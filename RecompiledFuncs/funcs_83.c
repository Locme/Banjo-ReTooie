#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _bskazstilt_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800836C8: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x800836C8);
    return;
    // 0x800836CC: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_80800BC4_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BCC: jal         0x800845D0
    // 0x80800BD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _babounce_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800BD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800BD4: jal         0x8080016C
    // 0x80800BD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bsmum_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800BD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800BDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BE4: jr          $ra
    // 0x80800BE8: nop

    return;
    // 0x80800BE8: nop

;}
RECOMP_FUNC void _fxegg_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A78: syscall     719
    recomp_syscall_handler(rdram, ctx, 0x80088A78);
    return;
    // 0x80088A7C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800190_chbounce(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800190: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800194: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x80800198: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8080019C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(712, 0XFE0) << 16);
    // 0x808001A0: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x808001A4: addiu       $t8, $t8, 0xFE0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(712, 0XFE0));
    // 0x808001A8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808001AC: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x808001B0: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x808001B4: addu        $s3, $t7, $t8
    ctx->r19 = ADD32(ctx->r15, ctx->r24);
    // 0x808001B8: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x808001BC: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x808001C0: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x808001C4: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x808001C8: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x808001CC: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x808001D0: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x808001D4: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x808001D8: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x808001DC: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x808001E0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808001E4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808001E8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808001EC: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x808001F0: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x808001F4: beq         $a2, $zero, L_80800204
    if (ctx->r6 == 0) {
        // 0x808001F8: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_80800204;
    }
    // 0x808001F8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x808001FC: b           L_80800208
    // 0x80800200: lw          $s7, 0x0($a2)
    ctx->r23 = MEM_W(ctx->r6, 0X0);
        goto L_80800208;
    // 0x80800200: lw          $s7, 0x0($a2)
    ctx->r23 = MEM_W(ctx->r6, 0X0);
L_80800204:
    // 0x80800204: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_80800208:
    // 0x80800208: lh          $t9, 0x4($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X4);
    // 0x8080020C: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80800210: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800214: blez        $t9, L_808005DC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80800218: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_808005DC;
    }
    // 0x80800218: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8080021C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80800220: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800224: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800228: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x8080022C: addiu       $s0, $s0, 0x7188
    ctx->r16 = ADD32(ctx->r16, 0X7188);
    // 0x80800230: lh          $t0, 0x4($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X4);
L_80800234:
    // 0x80800234: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800238: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8080023C: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80800240: nop

    // 0x80800244: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800248: div.s       $f10, $f22, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f22.fl, ctx->f8.fl);
    // 0x8080024C: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80800250: swc1        $f16, 0x7188($at)
    MEM_W(0X7188, ctx->r1) = ctx->f16.u32l;
    // 0x80800254: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800258: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x8080025C: nop

    // 0x80800260: bc1f        L_80800284
    if (!c1cs) {
        // 0x80800264: nop
    
            goto L_80800284;
    }
    // 0x80800264: nop

    // 0x80800268: sub.s       $f18, $f0, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f22.fl;
L_8080026C:
    // 0x8080026C: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x80800270: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800274: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x80800278: nop

    // 0x8080027C: bc1tl       L_8080026C
    if (c1cs) {
        // 0x80800280: sub.s       $f18, $f0, $f22
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f22.fl;
            goto L_8080026C;
    }
    goto skip_0;
    // 0x80800280: sub.s       $f18, $f0, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f22.fl;
    skip_0:
L_80800284:
    // 0x80800284: bnel        $s6, $zero, L_808002A8
    if (ctx->r22 != 0) {
        // 0x80800288: lh          $a0, 0x2($s3)
        ctx->r4 = MEM_H(ctx->r19, 0X2);
            goto L_808002A8;
    }
    goto skip_1;
    // 0x80800288: lh          $a0, 0x2($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X2);
    skip_1:
    // 0x8080028C: beql        $s7, $zero, L_808002A8
    if (ctx->r23 == 0) {
        // 0x80800290: lh          $a0, 0x2($s3)
        ctx->r4 = MEM_H(ctx->r19, 0X2);
            goto L_808002A8;
    }
    goto skip_2;
    // 0x80800290: lh          $a0, 0x2($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X2);
    skip_2:
    // 0x80800294: jal         0x80106790
    // 0x80800298: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800298: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_0:
    // 0x8080029C: b           L_808002E4
    // 0x808002A0: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
        goto L_808002E4;
    // 0x808002A0: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x808002A4: lh          $a0, 0x2($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X2);
L_808002A8:
    // 0x808002A8: addiu       $at, $zero, 0x229
    ctx->r1 = ADD32(0, 0X229);
    // 0x808002AC: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x808002B0: beq         $a0, $at, L_808002C8
    if (ctx->r4 == ctx->r1) {
        // 0x808002B4: nop
    
            goto L_808002C8;
    }
    // 0x808002B4: nop

    // 0x808002B8: jal         0x80108474
    // 0x808002BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80108474(rdram, ctx);
        goto after_1;
    // 0x808002BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x808002C0: b           L_808002E4
    // 0x808002C4: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
        goto L_808002E4;
    // 0x808002C4: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
L_808002C8:
    // 0x808002C8: jal         0x80800078
    // 0x808002CC: nop

    func_80800078_chbounce(rdram, ctx);
        goto after_2;
    // 0x808002CC: nop

    after_2:
    // 0x808002D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002D4: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x808002D8: jal         0x80108474
    // 0x808002DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80108474(rdram, ctx);
        goto after_3;
    // 0x808002DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x808002E0: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
L_808002E4:
    // 0x808002E4: beq         $v0, $zero, L_808005C4
    if (ctx->r2 == 0) {
        // 0x808002E8: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_808005C4;
    }
    // 0x808002E8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808002EC: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x808002F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808002F4: addiu       $a2, $zero, 0x34
    ctx->r6 = ADD32(0, 0X34);
    // 0x808002F8: jal         0x80100074
    // 0x808002FC: andi        $s4, $t1, 0x7F
    ctx->r20 = ctx->r9 & 0X7F;
    func_80100074(rdram, ctx);
        goto after_4;
    // 0x808002FC: andi        $s4, $t1, 0x7F
    ctx->r20 = ctx->r9 & 0X7F;
    after_4:
    // 0x80800300: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800304: jal         0x80100094
    // 0x80800308: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x80800308: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x8080030C: lbu         $t4, 0x7B($s5)
    ctx->r12 = MEM_BU(ctx->r21, 0X7B);
    // 0x80800310: addiu       $s2, $s5, 0x4
    ctx->r18 = ADD32(ctx->r21, 0X4);
    // 0x80800314: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800318: ori         $t5, $t4, 0x8
    ctx->r13 = ctx->r12 | 0X8;
    // 0x8080031C: sb          $t5, 0x7B($s5)
    MEM_B(0X7B, ctx->r21) = ctx->r13;
    // 0x80800320: lbu         $t6, 0x24($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X24);
    // 0x80800324: lbu         $t9, 0x26($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X26);
    // 0x80800328: lbu         $t2, 0x25($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X25);
    // 0x8080032C: andi        $t7, $t6, 0xFF80
    ctx->r15 = ctx->r14 & 0XFF80;
    // 0x80800330: andi        $t0, $t9, 0xFF1F
    ctx->r8 = ctx->r25 & 0XFF1F;
    // 0x80800334: andi        $t3, $t2, 0xFF80
    ctx->r11 = ctx->r10 & 0XFF80;
    // 0x80800338: or          $t8, $s4, $t7
    ctx->r24 = ctx->r20 | ctx->r15;
    // 0x8080033C: ori         $t1, $t0, 0x20
    ctx->r9 = ctx->r8 | 0X20;
    // 0x80800340: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80800344: sb          $t8, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r24;
    // 0x80800348: sb          $t1, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r9;
    // 0x8080034C: sb          $t4, 0x25($v0)
    MEM_B(0X25, ctx->r2) = ctx->r12;
    // 0x80800350: lh          $t5, 0x6($s3)
    ctx->r13 = MEM_H(ctx->r19, 0X6);
    // 0x80800354: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800358: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080035C: sh          $t5, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r13;
    // 0x80800360: lwc1        $f6, 0x8($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80800364: swc1        $f6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f6.u32l;
    // 0x80800368: lh          $t6, 0xC($s3)
    ctx->r14 = MEM_H(ctx->r19, 0XC);
    // 0x8080036C: jal         0x800EE7F8
    // 0x80800370: sh          $t6, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r14;
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80800370: sh          $t6, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r14;
    after_6:
    // 0x80800374: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800378: jal         0x800EE7F8
    // 0x8080037C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x8080037C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x80800380: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800384: c.eq.s      $f28, $f8
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f28.fl == ctx->f8.fl;
    // 0x80800388: nop

    // 0x8080038C: bc1tl       L_80800404
    if (c1cs) {
        // 0x80800390: lh          $t1, 0x10($s3)
        ctx->r9 = MEM_H(ctx->r19, 0X10);
            goto L_80800404;
    }
    goto skip_3;
    // 0x80800390: lh          $t1, 0x10($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X10);
    skip_3:
    // 0x80800394: lh          $t7, 0x14($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X14);
    // 0x80800398: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x8080039C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x808003A0: jal         0x800DC178
    // 0x808003A4: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x808003A4: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    after_8:
    // 0x808003A8: lh          $t8, 0xE($s3)
    ctx->r24 = MEM_H(ctx->r19, 0XE);
    // 0x808003AC: lh          $t0, 0x16($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X16);
    // 0x808003B0: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808003B4: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x808003B8: lh          $t9, 0x12($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X12);
    // 0x808003BC: addiu       $s2, $s1, 0xC
    ctx->r18 = ADD32(ctx->r17, 0XC);
    // 0x808003C0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808003C4: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x808003C8: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x808003CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808003D0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808003D4: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x808003D8: add.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x808003DC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808003E0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808003E4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808003E8: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x808003EC: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x808003F0: jal         0x800EFA4C
    // 0x808003F4: nop

    func_800EFA4C(rdram, ctx);
        goto after_9;
    // 0x808003F4: nop

    after_9:
    // 0x808003F8: b           L_80800490
    // 0x808003FC: swc1        $f28, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f28.u32l;
        goto L_80800490;
    // 0x808003FC: swc1        $f28, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f28.u32l;
    // 0x80800400: lh          $t1, 0x10($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X10);
L_80800404:
    // 0x80800404: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x80800408: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8080040C: jal         0x800DC178
    // 0x80800410: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    func_800DC178(rdram, ctx);
        goto after_10;
    // 0x80800410: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_10:
    // 0x80800414: lh          $t2, 0x14($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X14);
    // 0x80800418: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8080041C: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x80800420: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80800424: jal         0x800DC178
    // 0x80800428: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    func_800DC178(rdram, ctx);
        goto after_11;
    // 0x80800428: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    after_11:
    // 0x8080042C: lh          $t3, 0x18($s3)
    ctx->r11 = MEM_H(ctx->r19, 0X18);
    // 0x80800430: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800434: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x80800438: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8080043C: jal         0x800DC178
    // 0x80800440: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    func_800DC178(rdram, ctx);
        goto after_12;
    // 0x80800440: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    after_12:
    // 0x80800444: lh          $t4, 0xE($s3)
    ctx->r12 = MEM_H(ctx->r19, 0XE);
    // 0x80800448: lh          $t5, 0x12($s3)
    ctx->r13 = MEM_H(ctx->r19, 0X12);
    // 0x8080044C: lh          $t6, 0x16($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X16);
    // 0x80800450: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80800454: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80800458: addiu       $s2, $s1, 0xC
    ctx->r18 = ADD32(ctx->r17, 0XC);
    // 0x8080045C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800460: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80800464: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800468: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080046C: add.s       $f18, $f24, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f24.fl + ctx->f16.fl;
    // 0x80800470: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800474: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800478: add.s       $f4, $f20, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f20.fl + ctx->f8.fl;
    // 0x8080047C: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80800480: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80800484: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80800488: jal         0x800EFA4C
    // 0x8080048C: nop

    func_800EFA4C(rdram, ctx);
        goto after_13;
    // 0x8080048C: nop

    after_13:
L_80800490:
    // 0x80800490: lhu         $t7, 0x0($s3)
    ctx->r15 = MEM_HU(ctx->r19, 0X0);
    // 0x80800494: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(712, 0X14A8) << 16);
    // 0x80800498: andi        $t8, $t7, 0x400
    ctx->r24 = ctx->r15 & 0X400;
    // 0x8080049C: beq         $t8, $zero, L_80800510
    if (ctx->r24 == 0) {
        // 0x808004A0: nop
    
            goto L_80800510;
    }
    // 0x808004A0: nop

    // 0x808004A4: lh          $t9, 0x10($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X10);
    // 0x808004A8: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x808004AC: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x808004B0: jal         0x800DC178
    // 0x808004B4: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    func_800DC178(rdram, ctx);
        goto after_14;
    // 0x808004B4: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_14:
    // 0x808004B8: lh          $t0, 0xE($s3)
    ctx->r8 = MEM_H(ctx->r19, 0XE);
    // 0x808004BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808004C0: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x808004C4: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x808004C8: nop

    // 0x808004CC: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808004D0: add.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x808004D4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x808004D8: jal         0x800EEB9C
    // 0x808004DC: nop

    func_800EEB9C(rdram, ctx);
        goto after_15;
    // 0x808004DC: nop

    after_15:
    // 0x808004E0: lh          $t1, 0x14($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X14);
    // 0x808004E4: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x808004E8: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x808004EC: jal         0x800DC178
    // 0x808004F0: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    func_800DC178(rdram, ctx);
        goto after_16;
    // 0x808004F0: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    after_16:
    // 0x808004F4: lh          $t2, 0x12($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X12);
    // 0x808004F8: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x808004FC: nop

    // 0x80800500: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800504: add.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80800508: b           L_80800578
    // 0x8080050C: swc1        $f6, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f6.u32l;
        goto L_80800578;
    // 0x8080050C: swc1        $f6, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f6.u32l;
L_80800510:
    // 0x80800510: lwc1        $f0, 0x14A8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(712, 0X14A8));
    // 0x80800514: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800518: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080051C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(712, 0X14A8) << 16);
    // 0x80800520: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800524: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x80800528: swc1        $f0, 0x14A8($at)
    MEM_W((int16_t)RELOC_LO16(712, 0X14A8), ctx->r1) = ctx->f0.u32l;
    // 0x8080052C: lhu         $t3, 0x0($s3)
    ctx->r11 = MEM_HU(ctx->r19, 0X0);
    // 0x80800530: andi        $t4, $t3, 0x20
    ctx->r12 = ctx->r11 & 0X20;
    // 0x80800534: beql        $t4, $zero, L_80800548
    if (ctx->r12 == 0) {
        // 0x80800538: mov.s       $f12, $f26
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
            goto L_80800548;
    }
    goto skip_4;
    // 0x80800538: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    skip_4:
    // 0x8080053C: b           L_80800554
    // 0x80800540: lwc1        $f20, 0x20($s3)
    ctx->f20.u32l = MEM_W(ctx->r19, 0X20);
        goto L_80800554;
    // 0x80800540: lwc1        $f20, 0x20($s3)
    ctx->f20.u32l = MEM_W(ctx->r19, 0X20);
    // 0x80800544: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
L_80800548:
    // 0x80800548: jal         0x800DC178
    // 0x8080054C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800DC178(rdram, ctx);
        goto after_17;
    // 0x8080054C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_17:
    // 0x80800550: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80800554:
    // 0x80800554: swc1        $f20, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f20.u32l;
    // 0x80800558: swc1        $f20, 0x48($s5)
    MEM_W(0X48, ctx->r21) = ctx->f20.u32l;
    // 0x8080055C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800560: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800564: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800568: add.s       $f10, $f20, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f20.fl + ctx->f4.fl;
    // 0x8080056C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800570: jal         0x800EF934
    // 0x80800574: nop

    func_800EF934(rdram, ctx);
        goto after_18;
    // 0x80800574: nop

    after_18:
L_80800578:
    // 0x80800578: lbu         $t5, 0x24($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X24);
    // 0x8080057C: lbu         $t8, 0x25($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X25);
    // 0x80800580: swc1        $f26, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f26.u32l;
    // 0x80800584: andi        $t6, $t5, 0xFF7F
    ctx->r14 = ctx->r13 & 0XFF7F;
    // 0x80800588: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x8080058C: sb          $t6, 0x24($s1)
    MEM_B(0X24, ctx->r17) = ctx->r14;
    // 0x80800590: sb          $t9, 0x25($s1)
    MEM_B(0X25, ctx->r17) = ctx->r25;
    // 0x80800594: lhu         $t0, 0x0($s3)
    ctx->r8 = MEM_HU(ctx->r19, 0X0);
    // 0x80800598: sh          $t0, 0x32($s1)
    MEM_H(0X32, ctx->r17) = ctx->r8;
    // 0x8080059C: lhu         $t1, 0x0($s3)
    ctx->r9 = MEM_HU(ctx->r19, 0X0);
    // 0x808005A0: andi        $t2, $t1, 0x200
    ctx->r10 = ctx->r9 & 0X200;
    // 0x808005A4: beql        $t2, $zero, L_808005C8
    if (ctx->r10 == 0) {
        // 0x808005A8: lw          $t3, 0x6C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X6C);
            goto L_808005C8;
    }
    goto skip_5;
    // 0x808005A8: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    skip_5:
    // 0x808005AC: jal         0x80105494
    // 0x808005B0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80105494(rdram, ctx);
        goto after_19;
    // 0x808005B0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_19:
    // 0x808005B4: beql        $v0, $zero, L_808005C8
    if (ctx->r2 == 0) {
        // 0x808005B8: lw          $t3, 0x6C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X6C);
            goto L_808005C8;
    }
    goto skip_6;
    // 0x808005B8: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    skip_6:
    // 0x808005BC: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x808005C0: swc1        $f16, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f16.u32l;
L_808005C4:
    // 0x808005C4: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
L_808005C8:
    // 0x808005C8: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x808005CC: lh          $t4, 0x4($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X4);
    // 0x808005D0: slt         $at, $s6, $t4
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x808005D4: bnel        $at, $zero, L_80800234
    if (ctx->r1 != 0) {
        // 0x808005D8: lh          $t0, 0x4($s3)
        ctx->r8 = MEM_H(ctx->r19, 0X4);
            goto L_80800234;
    }
    goto skip_7;
    // 0x808005D8: lh          $t0, 0x4($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X4);
    skip_7:
L_808005DC:
    // 0x808005DC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x808005E0: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x808005E4: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x808005E8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808005EC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808005F0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808005F4: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808005F8: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x808005FC: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80800600: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80800604: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80800608: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8080060C: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80800610: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80800614: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80800618: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x8080061C: jr          $ra
    // 0x80800620: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80800620: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void bafpctrl_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C10: lw          $t6, 0x90($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X90);
    // 0x80800C14: jr          $ra
    // 0x80800C18: lbu         $v0, 0x13($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X13);
    return;
    // 0x80800C18: lbu         $v0, 0x13($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X13);
;}
RECOMP_FUNC void func_808017D8_chsabreman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808017DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808017E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808017E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808017E8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808017EC: jal         0x80100094
    // 0x808017F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808017F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808017F4: lh          $v1, 0x820($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X820);
    // 0x808017F8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x808017FC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80801800: beq         $v1, $zero, L_80801824
    if (ctx->r3 == 0) {
        // 0x80801804: addiu       $a1, $zero, 0xE
        ctx->r5 = ADD32(0, 0XE);
            goto L_80801824;
    }
    // 0x80801804: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80801808: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080180C: beq         $v1, $at, L_80801840
    if (ctx->r3 == ctx->r1) {
        // 0x80801810: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801840;
    }
    // 0x80801810: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801814: beql        $v1, $at, L_8080183C
    if (ctx->r3 == ctx->r1) {
        // 0x80801818: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8080183C;
    }
    goto skip_0;
    // 0x80801818: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    skip_0:
    // 0x8080181C: b           L_80801858
    // 0x80801820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801858;
    // 0x80801820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801824:
    // 0x80801824: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80801828: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x8080182C: jal         0x800856B0
    // 0x80801830: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80801830: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80801834: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80801838: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_8080183C:
    // 0x8080183C: sh          $t7, 0x820($a3)
    MEM_H(0X820, ctx->r7) = ctx->r15;
L_80801840:
    // 0x80801840: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80801844: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80801848: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8080184C: jal         0x800856D0
    // 0x80801850: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    _capod_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80801850: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_2:
    // 0x80801854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801858:
    // 0x80801858: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080185C: jr          $ra
    // 0x80801860: nop

    return;
    // 0x80801860: nop

;}
RECOMP_FUNC void func_80804350_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804350: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80804354: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80804358: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080435C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80804360: beq         $a1, $at, L_80804380
    if (ctx->r5 == ctx->r1) {
        // 0x80804364: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80804380;
    }
    // 0x80804364: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80804368: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x8080436C: beq         $a1, $at, L_80804448
    if (ctx->r5 == ctx->r1) {
        // 0x80804370: lw          $t3, 0x30($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X30);
            goto L_80804448;
    }
    // 0x80804370: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80804374: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80804378: bne         $a1, $at, L_80804474
    if (ctx->r5 != ctx->r1) {
        // 0x8080437C: nop
    
            goto L_80804474;
    }
    // 0x8080437C: nop

L_80804380:
    // 0x80804380: jal         0x80101080
    // 0x80804384: nop

    func_80101080(rdram, ctx);
        goto after_0;
    // 0x80804384: nop

    after_0:
    // 0x80804388: jal         0x80106790
    // 0x8080438C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x8080438C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80804390: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80804394: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80804398: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080439C: jal         0x800866A0
    // 0x808043A0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x808043A0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x808043A4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808043A8: jal         0x800866C0
    // 0x808043AC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    _chexploder_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x808043AC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x808043B0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808043B4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808043B8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808043BC: lbu         $t7, 0x7A($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X7A);
    // 0x808043C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808043C4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x808043C8: beq         $t8, $zero, L_808043E0
    if (ctx->r24 == 0) {
        // 0x808043CC: nop
    
            goto L_808043E0;
    }
    // 0x808043CC: nop

    // 0x808043D0: jal         0x800866D0
    // 0x808043D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _chexploder_entrypoint_15(rdram, ctx);
        goto after_4;
    // 0x808043D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808043D8: b           L_808043EC
    // 0x808043DC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
        goto L_808043EC;
    // 0x808043DC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_808043E0:
    // 0x808043E0: jal         0x800866D0
    // 0x808043E4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    _chexploder_entrypoint_15(rdram, ctx);
        goto after_5;
    // 0x808043E4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_5:
    // 0x808043E8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_808043EC:
    // 0x808043EC: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1852, 0X5870) << 16);
    // 0x808043F0: addiu       $t2, $t2, 0x5870
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1852, 0X5870));
    // 0x808043F4: lbu         $t9, 0x7A($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X7A);
    // 0x808043F8: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x808043FC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80804400: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80804404: beq         $t0, $zero, L_80804434
    if (ctx->r8 == 0) {
        // 0x80804408: addiu       $a3, $zero, 0x6
        ctx->r7 = ADD32(0, 0X6);
            goto L_80804434;
    }
    // 0x80804408: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x8080440C: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1852, 0X5840) << 16);
    // 0x80804410: addiu       $t1, $t1, 0x5840
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1852, 0X5840));
    // 0x80804414: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x80804418: lw          $a2, 0x38($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X38);
    // 0x8080441C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80804420: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80804424: jal         0x800BBCB8
    // 0x80804428: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    func_800BBCB8(rdram, ctx);
        goto after_6;
    // 0x80804428: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_6:
    // 0x8080442C: b           L_80804480
    // 0x80804430: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80804480;
    // 0x80804430: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80804434:
    // 0x80804434: lw          $a2, 0x38($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X38);
    // 0x80804438: jal         0x800BBCB8
    // 0x8080443C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_800BBCB8(rdram, ctx);
        goto after_7;
    // 0x8080443C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_7:
    // 0x80804440: b           L_80804480
    // 0x80804444: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80804480;
    // 0x80804444: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80804448:
    // 0x80804448: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x8080444C: srl         $t5, $t4, 22
    ctx->r13 = S32(U32(ctx->r12) >> 22);
    // 0x80804450: bnel        $t5, $zero, L_80804480
    if (ctx->r13 != 0) {
        // 0x80804454: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80804480;
    }
    goto skip_0;
    // 0x80804454: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80804458: jal         0x800F54E4
    // 0x8080445C: nop

    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x8080445C: nop

    after_8:
    // 0x80804460: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80804464: jal         0x800F7B9C
    // 0x80804468: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    func_800F7B9C(rdram, ctx);
        goto after_9;
    // 0x80804468: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    after_9:
    // 0x8080446C: b           L_80804480
    // 0x80804470: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80804480;
    // 0x80804470: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80804474:
    // 0x80804474: b           L_80804480
    // 0x80804478: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80804480;
    // 0x80804478: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080447C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80804480:
    // 0x80804480: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80804484: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80804488: jr          $ra
    // 0x8080448C: nop

    return;
    // 0x8080448C: nop

;}
RECOMP_FUNC void func_800CF2B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF2B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CF2B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF2B8: jal         0x800CEA60
    // 0x800CF2BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CEA60(rdram, ctx);
        goto after_0;
    // 0x800CF2BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800CF2C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CF2C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CF2C8: swc1        $f0, -0x4E90($at)
    MEM_W(-0X4E90, ctx->r1) = ctx->f0.u32l;
    // 0x800CF2CC: jr          $ra
    // 0x800CF2D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800CF2D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _fxstep_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A20: syscall     718
    recomp_syscall_handler(rdram, ctx, 0x80088A20);
    return;
    // 0x80088A24: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80092738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092738: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x8009273C: jr          $ra
    // 0x80092740: lbu         $v0, 0x11($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X11);
    return;
    // 0x80092740: lbu         $v0, 0x11($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X11);
;}
RECOMP_FUNC void _chdinoroargrill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087168: syscall     524
    recomp_syscall_handler(rdram, ctx, 0x80087168);
    return;
    // 0x8008716C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800BD8_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BE0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800BE4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800BE8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80800BEC: sll         $t8, $a1, 6
    ctx->r24 = S32(ctx->r5 << 6);
    // 0x80800BF0: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80800BF4: andi        $t0, $t9, 0x3F
    ctx->r8 = ctx->r25 & 0X3F;
    // 0x80800BF8: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800BFC: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80800C00: jal         0x80800000
    // 0x80800C04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800000_chnests(rdram, ctx);
        goto after_0;
    // 0x80800C04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800C08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800C0C: lbu         $t3, 0x65($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X65);
    // 0x80800C10: ori         $t4, $t3, 0x10
    ctx->r12 = ctx->r11 | 0X10;
    // 0x80800C14: sb          $t4, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r12;
    // 0x80800C18: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800C1C: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
    // 0x80800C20: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800C24: jal         0x80800B4C
    // 0x80800C28: swc1        $f6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f6.u32l;
    func_80800B4C_chnests(rdram, ctx);
        goto after_1;
    // 0x80800C28: swc1        $f6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f6.u32l;
    after_1:
    // 0x80800C2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C34: jr          $ra
    // 0x80800C38: nop

    return;
    // 0x80800C38: nop

;}
RECOMP_FUNC void _subaddieDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A4A8: syscall     843
    recomp_syscall_handler(rdram, ctx, 0x8008A4A8);
    return;
    // 0x8008A4AC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800070_chfantasysafeswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800070: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800074: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800078: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x8080007C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800080: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800084: beq         $a1, $at, L_80800214
    if (ctx->r5 == ctx->r1) {
        // 0x80800088: sw          $a2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r6;
            goto L_80800214;
    }
    // 0x80800088: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8080008C: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x80800090: beq         $a1, $at, L_80800158
    if (ctx->r5 == ctx->r1) {
        // 0x80800094: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80800158;
    }
    // 0x80800094: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800098: beq         $a1, $at, L_808000B0
    if (ctx->r5 == ctx->r1) {
        // 0x8080009C: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_808000B0;
    }
    // 0x8080009C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808000A0: beq         $a1, $at, L_808001D8
    if (ctx->r5 == ctx->r1) {
        // 0x808000A4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808001D8;
    }
    // 0x808000A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000A8: b           L_80800238
    // 0x808000AC: nop

        goto L_80800238;
    // 0x808000AC: nop

L_808000B0:
    // 0x808000B0: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808000B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000B8: addiu       $a0, $zero, 0x2B2
    ctx->r4 = ADD32(0, 0X2B2);
    // 0x808000BC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808000C0: bne         $t7, $at, L_80800150
    if (ctx->r15 != ctx->r1) {
        // 0x808000C4: nop
    
            goto L_80800150;
    }
    // 0x808000C4: nop

    // 0x808000C8: jal         0x80089C30
    // 0x808000CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808000CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000D0: beq         $v0, $zero, L_8080012C
    if (ctx->r2 == 0) {
        // 0x808000D4: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_8080012C;
    }
    // 0x808000D4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808000D8: jal         0x800EE7F8
    // 0x808000DC: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808000DC: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_1:
    // 0x808000E0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808000E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000E8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808000EC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808000F0: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x808000F4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808000F8: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x808000FC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800100: jal         0x800EFA4C
    // 0x80800104: nop

    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x80800104: nop

    after_2:
    // 0x80800108: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8080010C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800110: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    // 0x80800114: jal         0x800C6A7C
    // 0x80800118: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C6A7C(rdram, ctx);
        goto after_3;
    // 0x80800118: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8080011C: beql        $v0, $zero, L_80800130
    if (ctx->r2 == 0) {
        // 0x80800120: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800130;
    }
    goto skip_0;
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800124: b           L_80800238
    // 0x80800128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800238;
    // 0x80800128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080012C:
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800130:
    // 0x80800130: jal         0x80102424
    // 0x80800134: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x80800134: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: jal         0x80103110
    // 0x80800140: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_5;
    // 0x80800140: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800144: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80800148: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x8080014C: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
L_80800150:
    // 0x80800150: b           L_80800238
    // 0x80800154: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800238;
    // 0x80800154: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800158:
    // 0x80800158: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
    // 0x8080015C: sll         $t3, $t1, 11
    ctx->r11 = S32(ctx->r9 << 11);
    // 0x80800160: bgez        $t3, L_808001D0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800164: nop
    
            goto L_808001D0;
    }
    // 0x80800164: nop

    // 0x80800168: jal         0x800EA05C
    // 0x8080016C: nop

    func_800EA05C(rdram, ctx);
        goto after_6;
    // 0x8080016C: nop

    after_6:
    // 0x80800170: addiu       $at, $zero, 0x13A
    ctx->r1 = ADD32(0, 0X13A);
    // 0x80800174: bnel        $v0, $at, L_808001A0
    if (ctx->r2 != ctx->r1) {
        // 0x80800178: lhu         $a1, 0x76($s0)
        ctx->r5 = MEM_HU(ctx->r16, 0X76);
            goto L_808001A0;
    }
    goto skip_1;
    // 0x80800178: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    skip_1:
    // 0x8080017C: lhu         $a2, 0x76($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X76);
    // 0x80800180: addiu       $a0, $zero, 0x417
    ctx->r4 = ADD32(0, 0X417);
    // 0x80800184: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    // 0x80800188: srl         $t4, $a2, 7
    ctx->r12 = S32(U32(ctx->r6) >> 7);
    // 0x8080018C: jal         0x80101180
    // 0x80800190: addiu       $a2, $t4, 0x1F
    ctx->r6 = ADD32(ctx->r12, 0X1F);
    func_80101180(rdram, ctx);
        goto after_7;
    // 0x80800190: addiu       $a2, $t4, 0x1F
    ctx->r6 = ADD32(ctx->r12, 0X1F);
    after_7:
    // 0x80800194: b           L_808001B4
    // 0x80800198: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
        goto L_808001B4;
    // 0x80800198: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x8080019C: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
L_808001A0:
    // 0x808001A0: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    // 0x808001A4: srl         $t5, $a1, 7
    ctx->r13 = S32(U32(ctx->r5) >> 7);
    // 0x808001A8: jal         0x800887D8
    // 0x808001AC: addiu       $a1, $t5, 0x1F
    ctx->r5 = ADD32(ctx->r13, 0X1F);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_8;
    // 0x808001AC: addiu       $a1, $t5, 0x1F
    ctx->r5 = ADD32(ctx->r13, 0X1F);
    after_8:
    // 0x808001B0: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
L_808001B4:
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808001BC: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x808001C0: jal         0x80102424
    // 0x808001C4: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x808001C4: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    after_9:
    // 0x808001C8: b           L_80800238
    // 0x808001CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800238;
    // 0x808001CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001D0:
    // 0x808001D0: b           L_80800238
    // 0x808001D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800238;
    // 0x808001D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001D8:
    // 0x808001D8: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x808001DC: srl         $t8, $a0, 7
    ctx->r24 = S32(U32(ctx->r4) >> 7);
    // 0x808001E0: jal         0x800DA298
    // 0x808001E4: addiu       $a0, $t8, 0x357
    ctx->r4 = ADD32(ctx->r24, 0X357);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x808001E4: addiu       $a0, $t8, 0x357
    ctx->r4 = ADD32(ctx->r24, 0X357);
    after_10:
    // 0x808001E8: beq         $v0, $zero, L_80800204
    if (ctx->r2 == 0) {
        // 0x808001EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800204;
    }
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F4: jal         0x80102424
    // 0x808001F8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x808001F8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_11:
    // 0x808001FC: b           L_80800238
    // 0x80800200: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800238;
    // 0x80800200: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800204:
    // 0x80800204: jal         0x80102424
    // 0x80800208: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_12;
    // 0x80800208: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x8080020C: b           L_80800238
    // 0x80800210: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800238;
    // 0x80800210: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800214:
    // 0x80800214: jal         0x801015D0
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_13;
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8080021C: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x80800220: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800224: srl         $t9, $a1, 7
    ctx->r25 = S32(U32(ctx->r5) >> 7);
    // 0x80800228: jal         0x800DF744
    // 0x8080022C: addiu       $a1, $t9, -0x31
    ctx->r5 = ADD32(ctx->r25, -0X31);
    func_800DF744(rdram, ctx);
        goto after_14;
    // 0x8080022C: addiu       $a1, $t9, -0x31
    ctx->r5 = ADD32(ctx->r25, -0X31);
    after_14:
    // 0x80800230: b           L_80800238
    // 0x80800234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800238;
    // 0x80800234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800238:
    // 0x80800238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080023C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800240: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800244: jr          $ra
    // 0x80800248: nop

    return;
    // 0x80800248: nop

;}
RECOMP_FUNC void func_8010E030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E030: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8010E034: lw          $a0, 0x7614($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7614);
    // 0x8010E038: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010E03C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010E040: beql        $a0, $zero, L_8010E05C
    if (ctx->r4 == 0) {
        // 0x8010E044: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010E05C;
    }
    goto skip_0;
    // 0x8010E044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8010E048: jal         0x8001BAFC
    // 0x8010E04C: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x8010E04C: nop

    after_0:
    // 0x8010E050: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8010E054: sw          $v0, 0x7614($at)
    MEM_W(0X7614, ctx->r1) = ctx->r2;
    // 0x8010E058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010E05C:
    // 0x8010E05C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010E060: jr          $ra
    // 0x8010E064: nop

    return;
    // 0x8010E064: nop

    // 0x8010E068: nop

    // 0x8010E06C: nop

;}
RECOMP_FUNC void bsbpeck_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080042C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800430: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800434: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800438: jal         0x80095774
    // 0x8080043C: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    baflag_clear(rdram, ctx);
        goto after_0;
    // 0x8080043C: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    after_0:
    // 0x80800440: jal         0x800C6DA0
    // 0x80800444: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    func_800C6DA0(rdram, ctx);
        goto after_1;
    // 0x80800444: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    after_1:
    // 0x80800448: jal         0x8009E474
    // 0x8080044C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8009E474(rdram, ctx);
        goto after_2;
    // 0x8080044C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800450: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800454: jal         0x800A0CF4
    // 0x80800458: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_3;
    // 0x80800458: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8080045C: jal         0x8009BC6C
    // 0x80800460: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baphysics_reset_gravity(rdram, ctx);
        goto after_4;
    // 0x80800460: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80800464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800468: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080046C: jr          $ra
    // 0x80800470: nop

    return;
    // 0x80800470: nop

;}
RECOMP_FUNC void ncbaspiral_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800258: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080025C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800260: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800264: lw          $t7, 0x48($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X48);
    // 0x80800268: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8080026C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80800270: beql        $a1, $t8, L_808002CC
    if (ctx->r5 == ctx->r24) {
        // 0x80800274: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002CC;
    }
    goto skip_0;
    // 0x80800274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800278: jal         0x800A5800
    // 0x8080027C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_800A5800(rdram, ctx);
        goto after_0;
    // 0x8080027C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800280: jal         0x80085640
    // 0x80800284: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    _cadbfunc_entrypoint_24(rdram, ctx);
        goto after_1;
    // 0x80800284: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x80800288: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080028C: jal         0x801107B0
    // 0x80800290: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_801107B0(rdram, ctx);
        goto after_2;
    // 0x80800290: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x80800294: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800298: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8080029C: jal         0x80088280
    // 0x808002A0: addiu       $a0, $a0, 0x1D1
    ctx->r4 = ADD32(ctx->r4, 0X1D1);
    _gccubesearch_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808002A0: addiu       $a0, $a0, 0x1D1
    ctx->r4 = ADD32(ctx->r4, 0X1D1);
    after_3:
    // 0x808002A4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x808002A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002AC: lw          $a1, 0x48($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X48);
    // 0x808002B0: jal         0x80088C00
    // 0x808002B4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x808002B4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_4:
    // 0x808002B8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x808002BC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x808002C0: lw          $t2, 0x48($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X48);
    // 0x808002C4: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x808002C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002CC:
    // 0x808002CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808002D0: jr          $ra
    // 0x808002D4: nop

    return;
    // 0x808002D4: nop

    // 0x808002D8: nop

    // 0x808002DC: nop

;}
RECOMP_FUNC void _fxsplash_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088AD8: syscall     722
    recomp_syscall_handler(rdram, ctx, 0x80088AD8);
    return;
    // 0x80088ADC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800DA238(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DA238: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800DA23C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DA240: addiu       $v0, $v0, -0x3874
    ctx->r2 = ADD32(ctx->r2, -0X3874);
    // 0x800DA244: addiu       $v1, $v1, -0x3880
    ctx->r3 = ADD32(ctx->r3, -0X3880);
L_800DA248:
    // 0x800DA248: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800DA24C: sb          $zero, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = 0;
    // 0x800DA250: sb          $zero, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = 0;
    // 0x800DA254: sb          $zero, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = 0;
    // 0x800DA258: bne         $v1, $v0, L_800DA248
    if (ctx->r3 != ctx->r2) {
        // 0x800DA25C: sb          $zero, -0x4($v1)
        MEM_B(-0X4, ctx->r3) = 0;
            goto L_800DA248;
    }
    // 0x800DA25C: sb          $zero, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = 0;
    // 0x800DA260: jr          $ra
    // 0x800DA264: nop

    return;
    // 0x800DA264: nop

;}
RECOMP_FUNC void func_800ADE2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADE2C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800ADE30: bne         $a1, $at, L_800ADE40
    if (ctx->r5 != ctx->r1) {
        // 0x800ADE34: sll         $t6, $a1, 6
        ctx->r14 = S32(ctx->r5 << 6);
            goto L_800ADE40;
    }
    // 0x800ADE34: sll         $t6, $a1, 6
    ctx->r14 = S32(ctx->r5 << 6);
    // 0x800ADE38: jr          $ra
    // 0x800ADE3C: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    return;
    // 0x800ADE3C: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
L_800ADE40:
    // 0x800ADE40: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x800ADE44: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x800ADE48: jr          $ra
    // 0x800ADE4C: nop

    return;
    // 0x800ADE4C: nop

;}
RECOMP_FUNC void func_80106DA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106DA4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80106DA8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80106DAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80106DB0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_80106DB4:
    // 0x80106DB4: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80106DB8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80106DBC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80106DC0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80106DC4: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80106DC8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80106DCC: mflo        $t8
    ctx->r24 = lo;
    // 0x80106DD0: sra         $t9, $t8, 8
    ctx->r25 = S32(SIGNED(ctx->r24) >> 8);
    // 0x80106DD4: bne         $v0, $a0, L_80106DB4
    if (ctx->r2 != ctx->r4) {
        // 0x80106DD8: sw          $t9, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r25;
            goto L_80106DB4;
    }
    // 0x80106DD8: sw          $t9, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r25;
    // 0x80106DDC: jr          $ra
    // 0x80106DE0: nop

    return;
    // 0x80106DE0: nop

    // 0x80106DE4: nop

    // 0x80106DE8: nop

    // 0x80106DEC: nop

;}
RECOMP_FUNC void gcstatusDll_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800188: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8080018C: jr          $ra
    // 0x80800190: lbu         $v0, -0x4BF1($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X4BF1);
    return;
    // 0x80800190: lbu         $v0, -0x4BF1($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X4BF1);
;}
RECOMP_FUNC void func_808006B4_chburgerstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808006C0: jal         0x80100094
    // 0x808006C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808006C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808006C8: bne         $v0, $zero, L_80800710
    if (ctx->r2 != 0) {
        // 0x808006CC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800710;
    }
    // 0x808006CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808006D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808006D4: jal         0x800897C0
    // 0x808006D8: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x808006D8: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_1:
    // 0x808006DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808006E0: jal         0x80100094
    // 0x808006E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808006E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808006E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006EC: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x808006F0: jal         0x800897E8
    // 0x808006F4: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x808006F4: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_3:
    // 0x808006F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808006FC: jal         0x80100094
    // 0x80800700: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80800700: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800704: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800708: jal         0x80089810
    // 0x8080070C: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    _suexpression_entrypoint_17(rdram, ctx);
        goto after_5;
    // 0x8080070C: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_5:
L_80800710:
    // 0x80800710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800714: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800718: jr          $ra
    // 0x8080071C: nop

    return;
    // 0x8080071C: nop

;}
RECOMP_FUNC void _ncfixposrot_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800891F0: syscall     767
    recomp_syscall_handler(rdram, ctx, 0x800891F0);
    return;
    // 0x800891F4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800150_basnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800150: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800158: lw          $v0, 0x110($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X110);
    // 0x8080015C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800160: lbu         $t6, 0x14($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X14);
    // 0x80800164: beql        $a1, $t6, L_808001AC
    if (ctx->r5 == ctx->r14) {
        // 0x80800168: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001AC;
    }
    goto skip_0;
    // 0x80800168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080016C: beq         $a1, $at, L_808001A4
    if (ctx->r5 == ctx->r1) {
        // 0x80800170: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808001A4;
    }
    // 0x80800170: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800174: bne         $a1, $at, L_808001A4
    if (ctx->r5 != ctx->r1) {
        // 0x80800178: lui         $at, 0x4396
        ctx->r1 = S32(0X4396 << 16);
            goto L_808001A4;
    }
    // 0x80800178: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8080017C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800180: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80800184: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800188: jal         0x800F0E00
    // 0x8080018C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F0E00(rdram, ctx);
        goto after_0;
    // 0x8080018C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800190: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800194: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800198: lw          $t7, 0x110($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X110);
    // 0x8080019C: swc1        $f0, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f0.u32l;
    // 0x808001A0: lw          $v0, 0x110($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X110);
L_808001A4:
    // 0x808001A4: sb          $a1, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r5;
    // 0x808001A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001AC:
    // 0x808001AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001B0: jr          $ra
    // 0x808001B4: nop

    return;
    // 0x808001B4: nop

;}
RECOMP_FUNC void func_8001E2A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E2A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E2A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E2A8: jal         0x80014F00
    // 0x8001E2AC: nop

    func_80014F00(rdram, ctx);
        goto after_0;
    // 0x8001E2AC: nop

    after_0:
    // 0x8001E2B0: jal         0x8001DA60
    // 0x8001E2B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8001DA60(rdram, ctx);
        goto after_1;
    // 0x8001E2B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8001E2B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E2BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E2C0: jr          $ra
    // 0x8001E2C4: nop

    return;
    // 0x8001E2C4: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800D78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800D80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D84: jal         0x808000CC
    // 0x80800D88: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_808000CC_bsstonehead(rdram, ctx);
        goto after_0;
    // 0x80800D88: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D90: jal         0x80091A30
    // 0x80800D94: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_1;
    // 0x80800D94: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x80800D98: beql        $v0, $zero, L_80800DCC
    if (ctx->r2 == 0) {
        // 0x80800D9C: lw          $v0, 0x15C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X15C);
            goto L_80800DCC;
    }
    goto skip_0;
    // 0x80800D9C: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    skip_0:
    // 0x80800DA0: jal         0x8009BB50
    // 0x80800DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_2;
    // 0x80800DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800DA8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800DAC: nop

    // 0x80800DB0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800DB4: nop

    // 0x80800DB8: bc1fl       L_80800DCC
    if (!c1cs) {
        // 0x80800DBC: lw          $v0, 0x15C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X15C);
            goto L_80800DCC;
    }
    goto skip_1;
    // 0x80800DBC: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    skip_1:
    // 0x80800DC0: jal         0x8009BC6C
    // 0x80800DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_3;
    // 0x80800DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800DC8: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
L_80800DCC:
    // 0x80800DCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800DD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DD4: beq         $v0, $at, L_80800E04
    if (ctx->r2 == ctx->r1) {
        // 0x80800DD8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800E04;
    }
    // 0x80800DD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800DDC: beq         $v0, $at, L_80800E44
    if (ctx->r2 == ctx->r1) {
        // 0x80800DE0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E44;
    }
    // 0x80800DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DE4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800DE8: beq         $v0, $at, L_80800E64
    if (ctx->r2 == ctx->r1) {
        // 0x80800DEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E64;
    }
    // 0x80800DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DF0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800DF4: beq         $v0, $at, L_80800E8C
    if (ctx->r2 == ctx->r1) {
        // 0x80800DF8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E8C;
    }
    // 0x80800DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DFC: b           L_80800EA8
    // 0x80800E00: nop

        goto L_80800EA8;
    // 0x80800E00: nop

L_80800E04:
    // 0x80800E04: jal         0x8008DF8C
    // 0x80800E08: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_4;
    // 0x80800E08: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_4:
    // 0x80800E0C: beq         $v0, $zero, L_80800E24
    if (ctx->r2 == 0) {
        // 0x80800E10: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E24;
    }
    // 0x80800E10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E14: jal         0x80800B38
    // 0x80800E18: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800B38_bsstonehead(rdram, ctx);
        goto after_5;
    // 0x80800E18: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80800E1C: b           L_80800EA8
    // 0x80800E20: nop

        goto L_80800EA8;
    // 0x80800E20: nop

L_80800E24:
    // 0x80800E24: jal         0x8008CAEC
    // 0x80800E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_6;
    // 0x80800E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800E2C: beq         $v0, $zero, L_80800EA8
    if (ctx->r2 == 0) {
        // 0x80800E30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800EA8;
    }
    // 0x80800E30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E34: jal         0x80800B38
    // 0x80800E38: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800B38_bsstonehead(rdram, ctx);
        goto after_7;
    // 0x80800E38: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x80800E3C: b           L_80800EA8
    // 0x80800E40: nop

        goto L_80800EA8;
    // 0x80800E40: nop

L_80800E44:
    // 0x80800E44: jal         0x8008DF8C
    // 0x80800E48: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_8;
    // 0x80800E48: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_8:
    // 0x80800E4C: beq         $v0, $zero, L_80800EA8
    if (ctx->r2 == 0) {
        // 0x80800E50: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800EA8;
    }
    // 0x80800E50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E54: jal         0x80800B38
    // 0x80800E58: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800B38_bsstonehead(rdram, ctx);
        goto after_9;
    // 0x80800E58: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x80800E5C: b           L_80800EA8
    // 0x80800E60: nop

        goto L_80800EA8;
    // 0x80800E60: nop

L_80800E64:
    // 0x80800E64: jal         0x8009D3A8
    // 0x80800E68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_10;
    // 0x80800E68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80800E6C: jal         0x8008E078
    // 0x80800E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_11;
    // 0x80800E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800E74: beq         $v0, $zero, L_80800EA8
    if (ctx->r2 == 0) {
        // 0x80800E78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800EA8;
    }
    // 0x80800E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E7C: jal         0x80800B38
    // 0x80800E80: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800B38_bsstonehead(rdram, ctx);
        goto after_12;
    // 0x80800E80: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_12:
    // 0x80800E84: b           L_80800EA8
    // 0x80800E88: nop

        goto L_80800EA8;
    // 0x80800E88: nop

L_80800E8C:
    // 0x80800E8C: jal         0x8009D3A8
    // 0x80800E90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_13;
    // 0x80800E90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80800E94: jal         0x8008CAEC
    // 0x80800E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_14;
    // 0x80800E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800E9C: beq         $v0, $zero, L_80800EA8
    if (ctx->r2 == 0) {
        // 0x80800EA0: addiu       $t6, $zero, 0xB3
        ctx->r14 = ADD32(0, 0XB3);
            goto L_80800EA8;
    }
    // 0x80800EA0: addiu       $t6, $zero, 0xB3
    ctx->r14 = ADD32(0, 0XB3);
    // 0x80800EA4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800EA8:
    // 0x80800EA8: jal         0x8008E078
    // 0x80800EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_15;
    // 0x80800EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800EB0: beq         $v0, $zero, L_80800EC4
    if (ctx->r2 == 0) {
        // 0x80800EB4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800EC4;
    }
    // 0x80800EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EB8: jal         0x808003F4
    // 0x80800EBC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_808003F4_bsstonehead(rdram, ctx);
        goto after_16;
    // 0x80800EBC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_16:
    // 0x80800EC0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80800EC4:
    // 0x80800EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EC8: jal         0x8009E5C8
    // 0x80800ECC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_17;
    // 0x80800ECC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_17:
    // 0x80800ED0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800ED4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800ED8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800EDC: jr          $ra
    // 0x80800EE0: nop

    return;
    // 0x80800EE0: nop

;}
RECOMP_FUNC void func_800EA0A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA0A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EA0AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EA0B0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800EA0B4: jal         0x80088B60
    // 0x800EA0B8: addiu       $a0, $a0, 0x2DC0
    ctx->r4 = ADD32(ctx->r4, 0X2DC0);
    _gsworldDll_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x800EA0B8: addiu       $a0, $a0, 0x2DC0
    ctx->r4 = ADD32(ctx->r4, 0X2DC0);
    after_0:
    // 0x800EA0BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EA0C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EA0C4: jr          $ra
    // 0x800EA0C8: nop

    return;
    // 0x800EA0C8: nop

;}
RECOMP_FUNC void func_808000DC_chplatuegrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000E4: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808000E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000EC: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808000F0: beq         $t6, $at, L_80800130
    if (ctx->r14 == ctx->r1) {
        // 0x808000F4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800130;
    }
    // 0x808000F4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000F8: bnel        $t6, $at, L_8080013C
    if (ctx->r14 != ctx->r1) {
        // 0x808000FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080013C;
    }
    goto skip_0;
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800100: jal         0x80101DDC
    // 0x80800104: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101DDC(rdram, ctx);
        goto after_0;
    // 0x80800104: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800108: beq         $v0, $zero, L_80800138
    if (ctx->r2 == 0) {
        // 0x8080010C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800138;
    }
    // 0x8080010C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800110: jal         0x80102424
    // 0x80800114: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800114: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800118: addiu       $a0, $zero, 0x518
    ctx->r4 = ADD32(0, 0X518);
    // 0x8080011C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800120: jal         0x80101180
    // 0x80800124: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_2;
    // 0x80800124: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800128: b           L_8080013C
    // 0x8080012C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080013C;
    // 0x8080012C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800130:
    // 0x80800130: jal         0x80103110
    // 0x80800134: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_3;
    // 0x80800134: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
L_80800138:
    // 0x80800138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080013C:
    // 0x8080013C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800140: jr          $ra
    // 0x80800144: nop

    return;
    // 0x80800144: nop

;}
RECOMP_FUNC void _bamovehover_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084E40: syscall     138
    recomp_syscall_handler(rdram, ctx, 0x80084E40);
    return;
    // 0x80084E44: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void baanim_playForDuration_once(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CDB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008CDBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008CDC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008CDC4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8008CDC8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8008CDCC: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8008CDD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008CDD4: jal         0x8008AF24
    // 0x8008CDD8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    anctrl_reset(rdram, ctx);
        goto after_0;
    // 0x8008CDD8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x8008CDDC: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8008CDE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008CDE4: jal         0x8008B1A0
    // 0x8008CDE8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_1;
    // 0x8008CDE8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_1:
    // 0x8008CDEC: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8008CDF0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8008CDF4: jal         0x8008AED4
    // 0x8008CDF8: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x8008CDF8: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_2:
    // 0x8008CDFC: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8008CE00: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8008CE04: jal         0x8008B1BC
    // 0x8008CE08: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    anctrl_setDuration(rdram, ctx);
        goto after_3;
    // 0x8008CE08: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_3:
    // 0x8008CE0C: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x8008CE10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008CE14: jal         0x8008B134
    // 0x8008CE18: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_4;
    // 0x8008CE18: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_4:
    // 0x8008CE1C: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8008CE20: jal         0x8008B064
    // 0x8008CE24: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    anctrl_start(rdram, ctx);
        goto after_5;
    // 0x8008CE24: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_5:
    // 0x8008CE28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008CE2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008CE30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008CE34: jr          $ra
    // 0x8008CE38: nop

    return;
    // 0x8008CE38: nop

;}
RECOMP_FUNC void bsfirstp_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803914: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80803918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080391C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80803920: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80803924: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80803928: sh          $a2, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r6;
    // 0x8080392C: jal         0x80095738
    // 0x80803930: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    baflag_isTrue(rdram, ctx);
        goto after_0;
    // 0x80803930: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    after_0:
    // 0x80803934: beq         $v0, $zero, L_80803964
    if (ctx->r2 == 0) {
        // 0x80803938: lh          $a2, 0x52($sp)
        ctx->r6 = MEM_H(ctx->r29, 0X52);
            goto L_80803964;
    }
    // 0x80803938: lh          $a2, 0x52($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X52);
    // 0x8080393C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803940: beq         $a2, $at, L_80803958
    if (ctx->r6 == ctx->r1) {
        // 0x80803944: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80803958;
    }
    // 0x80803944: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80803948: beql        $a2, $at, L_80803964
    if (ctx->r6 == ctx->r1) {
        // 0x8080394C: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80803964;
    }
    goto skip_0;
    // 0x8080394C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    skip_0:
    // 0x80803950: b           L_80803968
    // 0x80803954: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
        goto L_80803968;
    // 0x80803954: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_80803958:
    // 0x80803958: b           L_80803964
    // 0x8080395C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
        goto L_80803964;
    // 0x8080395C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80803960: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80803964:
    // 0x80803964: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_80803968:
    // 0x80803968: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8080396C: jal         0x8009E674
    // 0x80803970: sh          $a2, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r6;
    func_8009E674(rdram, ctx);
        goto after_1;
    // 0x80803970: sh          $a2, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r6;
    after_1:
    // 0x80803974: beq         $v0, $zero, L_80803980
    if (ctx->r2 == 0) {
        // 0x80803978: lh          $a2, 0x52($sp)
        ctx->r6 = MEM_H(ctx->r29, 0X52);
            goto L_80803980;
    }
    // 0x80803978: lh          $a2, 0x52($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X52);
    // 0x8080397C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_80803980:
    // 0x80803980: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803984: beq         $a2, $at, L_808039AC
    if (ctx->r6 == ctx->r1) {
        // 0x80803988: lw          $a0, 0x4C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X4C);
            goto L_808039AC;
    }
    // 0x80803988: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8080398C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803990: beq         $a2, $at, L_808039C0
    if (ctx->r6 == ctx->r1) {
        // 0x80803994: lw          $a0, 0x4C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X4C);
            goto L_808039C0;
    }
    // 0x80803994: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80803998: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080399C: beq         $a2, $at, L_808039D4
    if (ctx->r6 == ctx->r1) {
        // 0x808039A0: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_808039D4;
    }
    // 0x808039A0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808039A4: b           L_80803A30
    // 0x808039A8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
        goto L_80803A30;
    // 0x808039A8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_808039AC:
    // 0x808039AC: lui         $a1, 0x8081
    ctx->r5 = S32(RELOC_HI16(439, 0XB4AC) << 16);
    // 0x808039B0: jal         0x800EE7F8
    // 0x808039B4: addiu       $a1, $a1, -0x4B54
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(439, 0XB4AC));
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808039B4: addiu       $a1, $a1, -0x4B54
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(439, 0XB4AC));
    after_2:
    // 0x808039B8: b           L_80803A30
    // 0x808039BC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
        goto L_80803A30;
    // 0x808039BC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_808039C0:
    // 0x808039C0: lui         $a1, 0x8081
    ctx->r5 = S32(RELOC_HI16(439, 0XB4B8) << 16);
    // 0x808039C4: jal         0x800EE7F8
    // 0x808039C8: addiu       $a1, $a1, -0x4B48
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(439, 0XB4B8));
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x808039C8: addiu       $a1, $a1, -0x4B48
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(439, 0XB4B8));
    after_3:
    // 0x808039CC: b           L_80803A30
    // 0x808039D0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
        goto L_80803A30;
    // 0x808039D0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_808039D4:
    // 0x808039D4: lui         $a1, 0x8081
    ctx->r5 = S32(RELOC_HI16(439, 0XB4AC) << 16);
    // 0x808039D8: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(439, 0XB4B8) << 16);
    // 0x808039DC: addiu       $a2, $a2, -0x4B48
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(439, 0XB4B8));
    // 0x808039E0: jal         0x800EE780
    // 0x808039E4: addiu       $a1, $a1, -0x4B54
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(439, 0XB4AC));
    func_800EE780(rdram, ctx);
        goto after_4;
    // 0x808039E4: addiu       $a1, $a1, -0x4B54
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(439, 0XB4AC));
    after_4:
    // 0x808039E8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808039EC: jal         0x800EF334
    // 0x808039F0: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_800EF334(rdram, ctx);
        goto after_5;
    // 0x808039F0: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_5:
    // 0x808039F4: lui         $a1, 0x8081
    ctx->r5 = S32(RELOC_HI16(439, 0XB4C4) << 16);
    // 0x808039F8: addiu       $a1, $a1, -0x4B3C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(439, 0XB4C4));
    // 0x808039FC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80803A00: jal         0x800EFB24
    // 0x80803A04: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_800EFB24(rdram, ctx);
        goto after_6;
    // 0x80803A04: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_6:
    // 0x80803A08: jal         0x80803B68
    // 0x80803A0C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80803B68_bsfirstp(rdram, ctx);
        goto after_7;
    // 0x80803A0C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_7:
    // 0x80803A10: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80803A14: jal         0x800EF334
    // 0x80803A18: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800EF334(rdram, ctx);
        goto after_8;
    // 0x80803A18: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_8:
    // 0x80803A1C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80803A20: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80803A24: jal         0x800EE780
    // 0x80803A28: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_800EE780(rdram, ctx);
        goto after_9;
    // 0x80803A28: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_9:
    // 0x80803A2C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_80803A30:
    // 0x80803A30: jal         0x8009C128
    // 0x80803A34: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_8009C128(rdram, ctx);
        goto after_10;
    // 0x80803A34: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_10:
    // 0x80803A38: jal         0x8009BFCC
    // 0x80803A3C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_8009BFCC(rdram, ctx);
        goto after_11;
    // 0x80803A3C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_11:
    // 0x80803A40: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80803A44: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80803A48: jal         0x800EF8BC
    // 0x80803A4C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_800EF8BC(rdram, ctx);
        goto after_12;
    // 0x80803A4C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_12:
    // 0x80803A50: jal         0x8009C984
    // 0x80803A54: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    yaw_get(rdram, ctx);
        goto after_13;
    // 0x80803A54: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_13:
    // 0x80803A58: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80803A5C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80803A60: jal         0x800EF934
    // 0x80803A64: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_800EF934(rdram, ctx);
        goto after_14;
    // 0x80803A64: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_14:
    // 0x80803A68: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80803A6C: jal         0x800EF04C
    // 0x80803A70: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800EF04C(rdram, ctx);
        goto after_15;
    // 0x80803A70: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_15:
    // 0x80803A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803A78: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80803A7C: jr          $ra
    // 0x80803A80: nop

    return;
    // 0x80803A80: nop

;}
RECOMP_FUNC void func_800F64DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F64DC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F64E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F64E4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F64E8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F64EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F64F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F64F4: jal         0x8009E6F8
    // 0x800F64F8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    bs_getCurrentState(rdram, ctx);
        goto after_0;
    // 0x800F64F8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F64FC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F6500: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800F6504: jal         0x8009CA70
    // 0x800F6508: lui         $a2, 0x40
    ctx->r6 = S32(0X40 << 16);
    func_8009CA70(rdram, ctx);
        goto after_1;
    // 0x800F6508: lui         $a2, 0x40
    ctx->r6 = S32(0X40 << 16);
    after_1:
    // 0x800F650C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6510: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F6514: jr          $ra
    // 0x800F6518: nop

    return;
    // 0x800F6518: nop

;}
RECOMP_FUNC void _chbottlesparty_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086828: syscall     384
    recomp_syscall_handler(rdram, ctx, 0x80086828);
    return;
    // 0x8008682C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bsmum_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CDC: jal         0x800845D0
    // 0x80800CE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _babounce_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800CE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800CE4: jal         0x8080016C
    // 0x80800CE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bsmum_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800CE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800CEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800CF4: jr          $ra
    // 0x80800CF8: nop

    return;
    // 0x80800CF8: nop

;}
RECOMP_FUNC void bsbswim_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C50: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801C54: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(120, 0X1F88) << 16);
    // 0x80801C58: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801C5C: jr          $ra
    // 0x80801C60: lw          $v0, 0x1F88($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1F88));
    return;
    // 0x80801C60: lw          $v0, 0x1F88($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1F88));
;}
RECOMP_FUNC void func_80802778_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802778: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080277C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802780: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80802784: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802788: jal         0x80100094
    // 0x8080278C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080278C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802790: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80802794: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80802798: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x8080279C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808027A0: or          $t7, $a2, $at
    ctx->r15 = ctx->r6 | ctx->r1;
    // 0x808027A4: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x808027A8: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x808027AC: jal         0x800856B0
    // 0x808027B0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808027B0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x808027B4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x808027B8: lh          $t9, 0xA($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XA);
    // 0x808027BC: bnel        $t9, $zero, L_808027E8
    if (ctx->r25 != 0) {
        // 0x808027C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808027E8;
    }
    goto skip_0;
    // 0x808027C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808027C4: jal         0x80802248
    // 0x808027C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80802248_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x808027C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808027CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808027D0: jal         0x800F7F98
    // 0x808027D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7F98(rdram, ctx);
        goto after_3;
    // 0x808027D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808027D8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x808027DC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808027E0: sh          $t0, 0xA($t1)
    MEM_H(0XA, ctx->r9) = ctx->r8;
    // 0x808027E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808027E8:
    // 0x808027E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808027EC: jr          $ra
    // 0x808027F0: nop

    return;
    // 0x808027F0: nop

;}
RECOMP_FUNC void baphysics_get_vertical_velocity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BB50: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x8009BB54: jr          $ra
    // 0x8009BB58: lwc1        $f0, 0x14($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X14);
    return;
    // 0x8009BB58: lwc1        $f0, 0x14($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X14);
;}
RECOMP_FUNC void func_80806B5C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806B5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80806B60: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80806B64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806B68: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80806B6C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80806B70: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80806B74: jal         0x80087D38
    // 0x80806B78: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    _gcnewoption_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80806B78: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80806B7C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80806B80: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80806B84: addiu       $a2, $v0, 0x1
    ctx->r6 = ADD32(ctx->r2, 0X1);
    // 0x80806B88: bne         $t6, $at, L_80806BA0
    if (ctx->r14 != ctx->r1) {
        // 0x80806B8C: nop
    
            goto L_80806BA0;
    }
    // 0x80806B8C: nop

    // 0x80806B90: jal         0x80806AA8
    // 0x80806B94: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80806AA8_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80806B94: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x80806B98: b           L_80806BAC
    // 0x80806B9C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
        goto L_80806BAC;
    // 0x80806B9C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_80806BA0:
    // 0x80806BA0: jal         0x80806AD4
    // 0x80806BA4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80806AD4_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80806BA4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_2:
    // 0x80806BA8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_80806BAC:
    // 0x80806BAC: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80806BB0: bne         $at, $zero, L_80806BBC
    if (ctx->r1 != 0) {
        // 0x80806BB4: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80806BBC;
    }
    // 0x80806BB4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80806BB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80806BBC:
    // 0x80806BBC: jal         0x80806AF4
    // 0x80806BC0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80806AF4_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80806BC0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80806BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80806BC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80806BCC: jr          $ra
    // 0x80806BD0: nop

    return;
    // 0x80806BD0: nop

;}
RECOMP_FUNC void func_80800720_chbottlesfamily(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800720: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800724: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80800728: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080072C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800730: beq         $a1, $at, L_80800828
    if (ctx->r5 == ctx->r1) {
        // 0x80800734: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800828;
    }
    // 0x80800734: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800738: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x8080073C: beq         $a1, $at, L_80800778
    if (ctx->r5 == ctx->r1) {
        // 0x80800740: addiu       $v0, $sp, 0x28
        ctx->r2 = ADD32(ctx->r29, 0X28);
            goto L_80800778;
    }
    // 0x80800740: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x80800744: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x80800748: beq         $a1, $at, L_80800790
    if (ctx->r5 == ctx->r1) {
        // 0x8080074C: addiu       $v0, $sp, 0x28
        ctx->r2 = ADD32(ctx->r29, 0X28);
            goto L_80800790;
    }
    // 0x8080074C: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x80800750: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800754: beq         $a1, $at, L_808007A8
    if (ctx->r5 == ctx->r1) {
        // 0x80800758: addiu       $at, $zero, 0x57
        ctx->r1 = ADD32(0, 0X57);
            goto L_808007A8;
    }
    // 0x80800758: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x8080075C: beq         $a1, $at, L_808007B8
    if (ctx->r5 == ctx->r1) {
        // 0x80800760: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808007B8;
    }
    // 0x80800760: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800764: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800768: beq         $a1, $at, L_808007E0
    if (ctx->r5 == ctx->r1) {
        // 0x8080076C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808007E0;
    }
    // 0x8080076C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800770: b           L_8080085C
    // 0x80800774: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080085C;
    // 0x80800774: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800778:
    // 0x80800778: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080077C: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800780: jal         0x8080088C
    // 0x80800784: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_8080088C_chbottlesfamily(rdram, ctx);
        goto after_0;
    // 0x80800784: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_0:
    // 0x80800788: b           L_8080085C
    // 0x8080078C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080085C;
    // 0x8080078C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800790:
    // 0x80800790: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800794: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800798: jal         0x8080099C
    // 0x8080079C: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_8080099C_chbottlesfamily(rdram, ctx);
        goto after_1;
    // 0x8080079C: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_1:
    // 0x808007A0: b           L_8080085C
    // 0x808007A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080085C;
    // 0x808007A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007A8:
    // 0x808007A8: jal         0x80800A84
    // 0x808007AC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800A84_chbottlesfamily(rdram, ctx);
        goto after_2;
    // 0x808007AC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x808007B0: b           L_8080085C
    // 0x808007B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080085C;
    // 0x808007B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007B8:
    // 0x808007B8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808007BC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808007C0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x808007C4: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x808007C8: and         $t7, $a2, $at
    ctx->r15 = ctx->r6 & ctx->r1;
    // 0x808007CC: srl         $a2, $t7, 16
    ctx->r6 = S32(U32(ctx->r15) >> 16);
    // 0x808007D0: jal         0x80800B64
    // 0x808007D4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_80800B64_chbottlesfamily(rdram, ctx);
        goto after_3;
    // 0x808007D4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_3:
    // 0x808007D8: b           L_80800860
    // 0x808007DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800860;
    // 0x808007DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007E0:
    // 0x808007E0: jal         0x80800A44
    // 0x808007E4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80800A44_chbottlesfamily(rdram, ctx);
        goto after_4;
    // 0x808007E4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_4:
    // 0x808007E8: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x808007EC: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x808007F0: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x808007F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808007F8: jal         0x800897C0
    // 0x808007FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x808007FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800800: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800804: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800808: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x8080080C: jal         0x800897E8
    // 0x80800810: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_6;
    // 0x80800810: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_6:
    // 0x80800814: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800818: jal         0x80089810
    // 0x8080081C: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    _suexpression_entrypoint_17(rdram, ctx);
        goto after_7;
    // 0x8080081C: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_7:
    // 0x80800820: b           L_8080085C
    // 0x80800824: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080085C;
    // 0x80800824: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800828:
    // 0x80800828: lw          $a1, 0x64($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X64);
    // 0x8080082C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80800830: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800834: sll         $t0, $a1, 11
    ctx->r8 = S32(ctx->r5 << 11);
    // 0x80800838: jal         0x800DF744
    // 0x8080083C: srl         $a1, $t0, 31
    ctx->r5 = S32(U32(ctx->r8) >> 31);
    func_800DF744(rdram, ctx);
        goto after_8;
    // 0x8080083C: srl         $a1, $t0, 31
    ctx->r5 = S32(U32(ctx->r8) >> 31);
    after_8:
    // 0x80800840: jal         0x801015D0
    // 0x80800844: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_801015D0(rdram, ctx);
        goto after_9;
    // 0x80800844: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x80800848: b           L_8080085C
    // 0x8080084C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080085C;
    // 0x8080084C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800850: b           L_8080085C
    // 0x80800854: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080085C;
    // 0x80800854: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800858: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080085C:
    // 0x8080085C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800860:
    // 0x80800860: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800864: jr          $ra
    // 0x80800868: nop

    return;
    // 0x80800868: nop

;}
RECOMP_FUNC void func_80013D94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013D94: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80013D98: addiu       $v1, $v1, -0x7100
    ctx->r3 = ADD32(ctx->r3, -0X7100);
    // 0x80013D9C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80013DA0: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80013DA4: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80013DA8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80013DAC: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80013DB0: addiu       $t7, $t7, -0x70FC
    ctx->r15 = ADD32(ctx->r15, -0X70FC);
    // 0x80013DB4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80013DB8: mfhi        $v0
    ctx->r2 = hi;
    // 0x80013DBC: beq         $v0, $t8, L_80013DDC
    if (ctx->r2 == ctx->r24) {
        // 0x80013DC0: nop
    
            goto L_80013DDC;
    }
    // 0x80013DC0: nop

    // 0x80013DC4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80013DC8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80013DCC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80013DD0: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80013DD4: sw          $a0, -0x7150($at)
    MEM_W(-0X7150, ctx->r1) = ctx->r4;
    // 0x80013DD8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80013DDC:
    // 0x80013DDC: jr          $ra
    // 0x80013DE0: nop

    return;
    // 0x80013DE0: nop

;}
RECOMP_FUNC void mlspline_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080114C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801150: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801154: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80801158: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x8080115C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801160: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80801164: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80801168: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8080116C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801170: jal         0x800F0D50
    // 0x80801174: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_800F0D50(rdram, ctx);
        goto after_0;
    // 0x80801174: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x80801178: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8080117C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80801180: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80801184: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80801188: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8080118C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801190: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801194: mul.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80801198: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8080119C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x808011A0: nop

    // 0x808011A4: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x808011A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808011AC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x808011B0: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808011B4: bne         $v0, $zero, L_80801240
    if (ctx->r2 != 0) {
        // 0x808011B8: sub.s       $f20, $f2, $f4
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f4.fl;
            goto L_80801240;
    }
    // 0x808011B8: sub.s       $f20, $f2, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x808011BC: beq         $at, $zero, L_80801448
    if (ctx->r1 == 0) {
        // 0x808011C0: sll         $a1, $a0, 2
        ctx->r5 = S32(ctx->r4 << 2);
            goto L_80801448;
    }
    // 0x808011C0: sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4 << 2);
    // 0x808011C4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808011C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808011CC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808011D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808011D4: addu        $v1, $a2, $a1
    ctx->r3 = ADD32(ctx->r6, ctx->r5);
    // 0x808011D8: addu        $v0, $a3, $a1
    ctx->r2 = ADD32(ctx->r7, ctx->r5);
L_808011DC:
    // 0x808011DC: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x808011E0: lwc1        $f12, 0x18($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X18);
    // 0x808011E4: lwc1        $f2, 0xC($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XC);
    // 0x808011E8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x808011EC: sub.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x808011F0: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x808011F4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808011F8: sub.s       $f14, $f2, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x808011FC: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80801200: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801204: mul.s       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x80801208: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8080120C: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80801210: add.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x80801214: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80801218: lwc1        $f10, -0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8080121C: mul.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80801220: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80801224: mul.s       $f8, $f14, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80801228: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8080122C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80801230: bne         $at, $zero, L_808011DC
    if (ctx->r1 != 0) {
        // 0x80801234: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_808011DC;
    }
    // 0x80801234: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80801238: b           L_8080144C
    // 0x8080123C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080144C;
    // 0x8080123C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801240:
    // 0x80801240: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x80801244: multu       $a0, $a1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80801248: addiu       $t2, $a0, 0x2
    ctx->r10 = ADD32(ctx->r4, 0X2);
    // 0x8080124C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80801250: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801254: addiu       $t3, $a0, 0x3
    ctx->r11 = ADD32(ctx->r4, 0X3);
    // 0x80801258: mflo        $t0
    ctx->r8 = lo;
    // 0x8080125C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80801260: bne         $v1, $t2, L_808012CC
    if (ctx->r3 != ctx->r10) {
        // 0x80801264: addu        $a2, $a2, $t1
        ctx->r6 = ADD32(ctx->r6, ctx->r9);
            goto L_808012CC;
    }
    // 0x80801264: addu        $a2, $a2, $t1
    ctx->r6 = ADD32(ctx->r6, ctx->r9);
    // 0x80801268: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080126C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801270: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80801274: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80801278: lwc1        $f14, 0xC($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8080127C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80801280: sub.s       $f18, $f14, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x80801284: mul.s       $f20, $f18, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80801288: beql        $a0, $a1, L_808012BC
    if (ctx->r4 == ctx->r5) {
        // 0x8080128C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_808012BC;
    }
    goto skip_0;
    // 0x8080128C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_0:
    // 0x80801290: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
L_80801294:
    // 0x80801294: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80801298: lwc1        $f14, 0x10($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8080129C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x808012A0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808012A4: sub.s       $f18, $f14, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x808012A8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808012AC: mul.s       $f20, $f18, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x808012B0: bnel        $a0, $a1, L_80801294
    if (ctx->r4 != ctx->r5) {
        // 0x808012B4: swc1        $f20, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
            goto L_80801294;
    }
    goto skip_1;
    // 0x808012B4: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
    skip_1:
    // 0x808012B8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_808012BC:
    // 0x808012BC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808012C0: swc1        $f20, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f20.u32l;
    // 0x808012C4: b           L_8080144C
    // 0x808012C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080144C;
    // 0x808012C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808012CC:
    // 0x808012CC: bne         $v1, $t3, L_808013C0
    if (ctx->r3 != ctx->r11) {
        // 0x808012D0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808013C0;
    }
    // 0x808012D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808012D4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808012D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808012DC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808012E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808012E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808012E8: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x808012EC: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x808012F0: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x808012F4: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
    // 0x808012F8: lwc1        $f14, 0xC($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XC);
    // 0x808012FC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80801300: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80801304: sub.s       $f0, $f14, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x80801308: mul.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8080130C: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80801310: mul.s       $f10, $f0, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80801314: beql        $a0, $a1, L_80801384
    if (ctx->r4 == ctx->r5) {
        // 0x80801318: add.s       $f4, $f10, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
            goto L_80801384;
    }
    goto skip_2;
    // 0x80801318: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    skip_2:
    // 0x8080131C: add.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f14.fl;
L_80801320:
    // 0x80801320: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80801324: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80801328: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8080132C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801330: sub.s       $f6, $f12, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x80801334: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80801338: add.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080133C: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80801340: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80801344: mul.s       $f6, $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80801348: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8080134C: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80801350: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80801354: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80801358: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8080135C: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80801360: lwc1        $f14, 0xC($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80801364: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80801368: sub.s       $f0, $f14, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x8080136C: mul.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80801370: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80801374: mul.s       $f10, $f0, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80801378: bnel        $a0, $a1, L_80801320
    if (ctx->r4 != ctx->r5) {
        // 0x8080137C: add.s       $f6, $f14, $f14
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f14.fl;
            goto L_80801320;
    }
    goto skip_3;
    // 0x8080137C: add.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f14.fl;
    skip_3:
    // 0x80801380: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
L_80801384:
    // 0x80801384: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80801388: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080138C: add.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x80801390: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80801394: sub.s       $f6, $f12, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x80801398: add.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080139C: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x808013A0: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x808013A4: mul.s       $f6, $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x808013A8: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x808013AC: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x808013B0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808013B4: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x808013B8: b           L_8080144C
    // 0x808013BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080144C;
    // 0x808013BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808013C0:
    // 0x808013C0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808013C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808013C8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808013CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808013D0: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x808013D4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_808013D8:
    // 0x808013D8: lwc1        $f14, 0x0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X0);
    // 0x808013DC: lwc1        $f12, 0xC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
    // 0x808013E0: lwc1        $f10, 0x18($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X18);
    // 0x808013E4: lwc1        $f8, 0x24($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X24);
    // 0x808013E8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x808013EC: sub.s       $f6, $f12, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x808013F0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808013F4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808013F8: sub.s       $f8, $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x808013FC: mul.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80801400: add.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x80801404: mul.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80801408: add.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x8080140C: add.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80801410: sub.s       $f12, $f4, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x80801414: mul.s       $f6, $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80801418: add.s       $f12, $f6, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x8080141C: sub.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x80801420: swc1        $f12, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f12.u32l;
    // 0x80801424: lwc1        $f12, -0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80801428: mul.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x8080142C: nop

    // 0x80801430: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80801434: swc1        $f12, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f12.u32l;
    // 0x80801438: lwc1        $f12, -0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8080143C: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x80801440: bne         $a0, $a1, L_808013D8
    if (ctx->r4 != ctx->r5) {
        // 0x80801444: swc1        $f14, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f14.u32l;
            goto L_808013D8;
    }
    // 0x80801444: swc1        $f14, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f14.u32l;
L_80801448:
    // 0x80801448: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080144C:
    // 0x8080144C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80801450: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801454: jr          $ra
    // 0x80801458: nop

    return;
    // 0x80801458: nop

;}
RECOMP_FUNC void _chboilerboss_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085D88: syscall     238
    recomp_syscall_handler(rdram, ctx, 0x80085D88);
    return;
    // 0x80085D8C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800520_gcfrontend(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800520: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800524: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800528: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8080052C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800530: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800534: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800538: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8080053C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80800540: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800544: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800548: blez        $v0, L_8080066C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080054C: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_8080066C;
    }
    // 0x8080054C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800550: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2650, 0X8FC) << 16);
    // 0x80800554: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800558: addiu       $s3, $s3, 0x8FC
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2650, 0X8FC));
    // 0x8080055C: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
L_80800560:
    // 0x80800560: addu        $v1, $t6, $s2
    ctx->r3 = ADD32(ctx->r14, ctx->r18);
    // 0x80800564: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x80800568: lh          $s0, 0x2($v1)
    ctx->r16 = MEM_H(ctx->r3, 0X2);
    // 0x8080056C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80800570: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x80800574: beq         $at, $zero, L_8080065C
    if (ctx->r1 == 0) {
        // 0x80800578: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8080065C;
    }
    // 0x80800578: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080057C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2650, 0X820) << 16);
    // 0x80800580: addu        $at, $at, $t7
    gpr jr_addend_80800588 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800584: lw          $t7, 0x820($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2650, 0X820));
    // 0x80800588: jr          $t7
    // 0x8080058C: nop

    switch (jr_addend_80800588 >> 2) {
        case 0: goto L_80800590; break;
        case 1: goto L_808005A8; break;
        case 2: goto L_808005BC; break;
        case 3: goto L_808005D0; break;
        case 4: goto L_808005E4; break;
        case 5: goto L_808005F8; break;
        case 6: goto L_80800610; break;
        case 7: goto L_80800628; break;
        default: switch_error(__func__, 0x80800588, 0x80800820);
    }
    // 0x8080058C: nop

L_80800590:
    // 0x80800590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800594: jal         0x800D3A54
    // 0x80800598: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D3A54(rdram, ctx);
        goto after_0;
    // 0x80800598: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080059C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x808005A0: b           L_8080065C
    // 0x808005A4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
        goto L_8080065C;
    // 0x808005A4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
L_808005A8:
    // 0x808005A8: jal         0x800D3A88
    // 0x808005AC: nop

    func_800D3A88(rdram, ctx);
        goto after_1;
    // 0x808005AC: nop

    after_1:
    // 0x808005B0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x808005B4: b           L_8080065C
    // 0x808005B8: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
        goto L_8080065C;
    // 0x808005B8: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
L_808005BC:
    // 0x808005BC: jal         0x800D3AF0
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D3AF0(rdram, ctx);
        goto after_2;
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808005C4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x808005C8: b           L_8080065C
    // 0x808005CC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
        goto L_8080065C;
    // 0x808005CC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
L_808005D0:
    // 0x808005D0: jal         0x800D3A14
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D3A14(rdram, ctx);
        goto after_3;
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808005D8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x808005DC: b           L_8080065C
    // 0x808005E0: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
        goto L_8080065C;
    // 0x808005E0: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
L_808005E4:
    // 0x808005E4: jal         0x800D3A20
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D3A20(rdram, ctx);
        goto after_4;
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808005EC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x808005F0: b           L_8080065C
    // 0x808005F4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
        goto L_8080065C;
    // 0x808005F4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
L_808005F8:
    // 0x808005F8: sll         $t8, $s0, 3
    ctx->r24 = S32(ctx->r16 << 3);
    // 0x808005FC: jal         0x80800520
    // 0x80800600: addu        $a0, $s3, $t8
    ctx->r4 = ADD32(ctx->r19, ctx->r24);
    func_80800520_gcfrontend(rdram, ctx);
        goto after_5;
    // 0x80800600: addu        $a0, $s3, $t8
    ctx->r4 = ADD32(ctx->r19, ctx->r24);
    after_5:
    // 0x80800604: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80800608: b           L_8080065C
    // 0x8080060C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
        goto L_8080065C;
    // 0x8080060C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
L_80800610:
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800614: jal         0x800D3A54
    // 0x80800618: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D3A54(rdram, ctx);
        goto after_6;
    // 0x80800618: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8080061C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80800620: b           L_8080065C
    // 0x80800624: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
        goto L_8080065C;
    // 0x80800624: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
L_80800628:
    // 0x80800628: jal         0x800DC298
    // 0x8080062C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800DC298(rdram, ctx);
        goto after_7;
    // 0x8080062C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_7:
    // 0x80800630: beq         $v0, $zero, L_80800648
    if (ctx->r2 == 0) {
        // 0x80800634: nop
    
            goto L_80800648;
    }
    // 0x80800634: nop

    // 0x80800638: jal         0x800D3A20
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D3A20(rdram, ctx);
        goto after_8;
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800640: b           L_80800654
    // 0x80800644: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
        goto L_80800654;
    // 0x80800644: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_80800648:
    // 0x80800648: jal         0x800D3A20
    // 0x8080064C: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    func_800D3A20(rdram, ctx);
        goto after_9;
    // 0x8080064C: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    after_9:
    // 0x80800650: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_80800654:
    // 0x80800654: b           L_8080065C
    // 0x80800658: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
        goto L_8080065C;
    // 0x80800658: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
L_8080065C:
    // 0x8080065C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80800660: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800664: bnel        $at, $zero, L_80800560
    if (ctx->r1 != 0) {
        // 0x80800668: lw          $t6, 0x4($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X4);
            goto L_80800560;
    }
    goto skip_0;
    // 0x80800668: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    skip_0:
L_8080066C:
    // 0x8080066C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800670: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800674: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800678: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8080067C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800680: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800684: jr          $ra
    // 0x80800688: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800688: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8080048C_cheggproximity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080048C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800490: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800494: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800498: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080049C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808004A0: jal         0x800EEEA8
    // 0x808004A4: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800EEEA8(rdram, ctx);
        goto after_0;
    // 0x808004A4: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
    // 0x808004A8: beq         $v0, $zero, L_808004C0
    if (ctx->r2 == 0) {
        // 0x808004AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004C0;
    }
    // 0x808004AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B0: jal         0x80800718
    // 0x808004B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800718_cheggproximity(rdram, ctx);
        goto after_1;
    // 0x808004B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x808004B8: b           L_80800500
    // 0x808004BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800500;
    // 0x808004BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004C0:
    // 0x808004C0: jal         0x808001CC
    // 0x808004C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001CC_cheggproximity(rdram, ctx);
        goto after_2;
    // 0x808004C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808004C8: jal         0x8008A3F8
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_16(rdram, ctx);
        goto after_3;
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808004D0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808004D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2220, 0XCBC) << 16);
    // 0x808004D8: lwc1        $f4, 0xCBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2220, 0XCBC));
    // 0x808004DC: lwc1        $f6, 0x30($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X30);
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808004E8: nop

    // 0x808004EC: bc1fl       L_80800500
    if (!c1cs) {
        // 0x808004F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800500;
    }
    goto skip_0;
    // 0x808004F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808004F4: jal         0x80800718
    // 0x808004F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800718_cheggproximity(rdram, ctx);
        goto after_4;
    // 0x808004F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808004FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800500:
    // 0x80800500: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800504: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800508: jr          $ra
    // 0x8080050C: nop

    return;
    // 0x8080050C: nop

;}
RECOMP_FUNC void _basquash_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800850B0: syscall     150
    recomp_syscall_handler(rdram, ctx, 0x800850B0);
    return;
    // 0x800850B4: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void chanim_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808002D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002D4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808002D8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808002DC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808002E0: jal         0x80100094
    // 0x808002E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808002E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002E8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808002EC: jal         0x80104248
    // 0x808002F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80104248(rdram, ctx);
        goto after_1;
    // 0x808002F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808002F4: beql        $v0, $zero, L_80800374
    if (ctx->r2 == 0) {
        // 0x808002F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800374;
    }
    goto skip_0;
    // 0x808002F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808002FC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80800300: beql        $a0, $zero, L_80800374
    if (ctx->r4 == 0) {
        // 0x80800304: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800374;
    }
    goto skip_1;
    // 0x80800304: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800308: jal         0x80082660
    // 0x8080030C: nop

    _anseq_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x8080030C: nop

    after_2:
    // 0x80800310: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800314: jal         0x801022E4
    // 0x80800318: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_801022E4(rdram, ctx);
        goto after_3;
    // 0x80800318: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8080031C: lw          $t6, 0xF8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XF8);
    // 0x80800320: beq         $v0, $t6, L_8080035C
    if (ctx->r2 == ctx->r14) {
        // 0x80800324: nop
    
            goto L_8080035C;
    }
    // 0x80800324: nop

    // 0x80800328: sw          $v0, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->r2;
    // 0x8080032C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800330: jal         0x80082618
    // 0x80800334: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    _anseq_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80800334: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80800338: lw          $a0, 0xF4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XF4);
    // 0x8080033C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800340: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800344: beq         $a0, $zero, L_8080035C
    if (ctx->r4 == 0) {
        // 0x80800348: sll         $a3, $v1, 16
        ctx->r7 = S32(ctx->r3 << 16);
            goto L_8080035C;
    }
    // 0x80800348: sll         $a3, $v1, 16
    ctx->r7 = S32(ctx->r3 << 16);
    // 0x8080034C: sra         $t7, $a3, 16
    ctx->r15 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80800350: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x80800354: jal         0x80088F80
    // 0x80800358: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    _inantab_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80800358: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_5:
L_8080035C:
    // 0x8080035C: jal         0x80104248
    // 0x80800360: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80104248(rdram, ctx);
        goto after_6;
    // 0x80800360: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80800364: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800368: jal         0x80082658
    // 0x8080036C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _anseq_entrypoint_8(rdram, ctx);
        goto after_7;
    // 0x8080036C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x80800370: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800374:
    // 0x80800374: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800378: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080037C: jr          $ra
    // 0x80800380: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800380: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800384: nop

    // 0x80800388: nop

    // 0x8080038C: nop

;}
RECOMP_FUNC void func_8080281C_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080281C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802820: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802824: lw          $a1, 0x24($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X24);
    // 0x80802828: beql        $a1, $zero, L_8080283C
    if (ctx->r5 == 0) {
        // 0x8080282C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080283C;
    }
    goto skip_0;
    // 0x8080282C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80802830: jal         0x800C8B84
    // 0x80802834: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800C8B84(rdram, ctx);
        goto after_0;
    // 0x80802834: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80802838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080283C:
    // 0x8080283C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802840: jr          $ra
    // 0x80802844: nop

    return;
    // 0x80802844: nop

;}
RECOMP_FUNC void _subaddieaudioquick_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089D28: syscall     809
    recomp_syscall_handler(rdram, ctx, 0x80089D28);
    return;
    // 0x80089D2C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808007D4_cheggsplode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808007E0: jal         0x800F6478
    // 0x808007E4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800F6478(rdram, ctx);
        goto after_0;
    // 0x808007E4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808007E8: bne         $v0, $zero, L_808007F8
    if (ctx->r2 != 0) {
        // 0x808007EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808007F8;
    }
    // 0x808007EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007F0: b           L_808007FC
    // 0x808007F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808007FC;
    // 0x808007F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808007F8:
    // 0x808007F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007FC:
    // 0x808007FC: jr          $ra
    // 0x80800800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800804: nop

    // 0x80800808: nop

    // 0x8080080C: nop

;}
