#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _bsdronebubbled_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083070: syscall     40
    recomp_syscall_handler(rdram, ctx, 0x80083070);
    return;
    // 0x80083074: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800264_chstinger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_80800264_chstinger");
    // 0x80800264: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80800268: sw          $s7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r23;
    // 0x8080026C: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x80800270: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80800274: sw          $s6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r22;
    // 0x80800278: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8080027C: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x80800280: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x80800284: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x80800288: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x8080028C: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80800290: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80800294: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80800298: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8080029C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x808002A0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x808002A4: jal         0x80100094
    // 0x808002A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808002A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002AC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x808002B0: addiu       $s3, $v0, 0x18
    ctx->r19 = ADD32(ctx->r2, 0X18);
    // 0x808002B4: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x808002B8: lb          $s5, 0x0($v0)
    ctx->r21 = MEM_B(ctx->r2, 0X0);
    // 0x808002BC: jal         0x800F5898
    // 0x808002C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_800F5898(rdram, ctx);
        goto after_1;
    // 0x808002C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_1:
    // 0x808002C4: blez        $v0, L_80800370
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808002C8: lui         $at, 0x42F0
        ctx->r1 = S32(0X42F0 << 16);
            goto L_80800370;
    }
    // 0x808002C8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x808002CC: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808002D0: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x808002D4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808002D8: addiu       $s2, $sp, 0x84
    ctx->r18 = ADD32(ctx->r29, 0X84);
    // 0x808002DC: addiu       $s1, $sp, 0x68
    ctx->r17 = ADD32(ctx->r29, 0X68);
L_808002E0:
    // 0x808002E0: jal         0x800F6438
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_2;
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808002E8: beq         $v0, $zero, L_8080035C
    if (ctx->r2 == 0) {
        // 0x808002EC: nop
    
            goto L_8080035C;
    }
    // 0x808002EC: nop

    // 0x808002F0: beq         $s0, $s5, L_8080035C
    if (ctx->r16 == ctx->r21) {
        // 0x808002F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080035C;
    }
    // 0x808002F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F8: jal         0x800F5A00
    // 0x808002FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800F5A00(rdram, ctx);
        goto after_3;
    // 0x808002FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80800300: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800304: jal         0x800EEB40
    // 0x80800308: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EEB40(rdram, ctx);
        goto after_4;
    // 0x80800308: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_4:
    // 0x8080030C: bltz        $s4, L_80800324
    if (SIGNED(ctx->r20) < 0) {
        // 0x80800310: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_80800324;
    }
    // 0x80800310: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800314: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80800318: nop

    // 0x8080031C: bc1f        L_8080035C
    if (!c1cs) {
        // 0x80800320: nop
    
            goto L_8080035C;
    }
    // 0x80800320: nop

L_80800324:
    // 0x80800324: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80800328: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080032C: addiu       $a1, $s6, 0x4
    ctx->r5 = ADD32(ctx->r22, 0X4);
    // 0x80800330: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800334: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x80800338: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x8080033C: jal         0x800F0734
    // 0x80800340: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    func_800F0734(rdram, ctx);
        goto after_5;
    // 0x80800340: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    after_5:
    // 0x80800344: beq         $v0, $zero, L_8080035C
    if (ctx->r2 == 0) {
        // 0x80800348: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_8080035C;
    }
    // 0x80800348: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8080034C: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x80800350: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
    // 0x80800354: jal         0x800EE7F8
    // 0x80800358: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80800358: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_6:
L_8080035C:
    // 0x8080035C: jal         0x800F5898
    // 0x80800360: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_800F5898(rdram, ctx);
        goto after_7;
    // 0x80800360: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_7:
    // 0x80800364: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800368: bne         $at, $zero, L_808002E0
    if (ctx->r1 != 0) {
        // 0x8080036C: nop
    
            goto L_808002E0;
    }
    // 0x8080036C: nop

L_80800370:
    // 0x80800370: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80800374: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x80800378: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x8080037C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800380: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800384: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80800388: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8080038C: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80800390: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80800394: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x80800398: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x8080039C: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x808003A0: lw          $s6, 0x5C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X5C);
    // 0x808003A4: lw          $s7, 0x60($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X60);
    // 0x808003A8: jr          $ra
    // 0x808003AC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x808003AC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_80803BF0_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803BF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803BF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803BF8: jal         0x80102424
    // 0x80803BFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80803BFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80803C00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80803C04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803C08: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80803C0C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80803C10: bnel        $t7, $at, L_80803C30
    if (ctx->r15 != ctx->r1) {
        // 0x80803C14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80803C30;
    }
    goto skip_0;
    // 0x80803C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80803C18: jal         0x80089CA8
    // 0x80803C1C: nop

    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80803C1C: nop

    after_1:
    // 0x80803C20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80803C24: jal         0x8010A800
    // 0x80803C28: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A800(rdram, ctx);
        goto after_2;
    // 0x80803C28: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80803C2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803C30:
    // 0x80803C30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803C34: jr          $ra
    // 0x80803C38: nop

    return;
    // 0x80803C38: nop

;}
RECOMP_FUNC void func_80801324_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801324: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080132C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80801330: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80801334: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801338: jal         0x80100094
    // 0x8080133C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080133C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801340: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80801344: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801348: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080134C: beq         $a2, $zero, L_80801374
    if (ctx->r6 == 0) {
        // 0x80801350: sh          $a2, 0x18($v0)
        MEM_H(0X18, ctx->r2) = ctx->r6;
            goto L_80801374;
    }
    // 0x80801350: sh          $a2, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r6;
    // 0x80801354: beq         $a2, $at, L_8080138C
    if (ctx->r6 == ctx->r1) {
        // 0x80801358: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080138C;
    }
    // 0x80801358: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080135C: beq         $a2, $at, L_808013C0
    if (ctx->r6 == ctx->r1) {
        // 0x80801360: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808013C0;
    }
    // 0x80801360: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801364: beql        $a2, $at, L_808013E8
    if (ctx->r6 == ctx->r1) {
        // 0x80801368: lbu         $t7, 0x7A($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X7A);
            goto L_808013E8;
    }
    goto skip_0;
    // 0x80801368: lbu         $t7, 0x7A($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X7A);
    skip_0:
    // 0x8080136C: b           L_80801420
    // 0x80801370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801420;
    // 0x80801370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801374:
    // 0x80801374: lbu         $t6, 0x7A($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X7A);
    // 0x80801378: andi        $t8, $t6, 0xFFCF
    ctx->r24 = ctx->r14 & 0XFFCF;
    // 0x8080137C: sb          $t8, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r24;
    // 0x80801380: andi        $t9, $t8, 0xF1
    ctx->r25 = ctx->r24 & 0XF1;
    // 0x80801384: b           L_8080141C
    // 0x80801388: sb          $t9, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r25;
        goto L_8080141C;
    // 0x80801388: sb          $t9, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r25;
L_8080138C:
    // 0x8080138C: lbu         $t0, 0x7A($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X7A);
    // 0x80801390: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1364, 0X2578) << 16);
    // 0x80801394: lwc1        $f0, 0x2578($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1364, 0X2578));
    // 0x80801398: andi        $t2, $t0, 0xFFCF
    ctx->r10 = ctx->r8 & 0XFFCF;
    // 0x8080139C: sb          $t2, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r10;
    // 0x808013A0: andi        $t3, $t2, 0xF1
    ctx->r11 = ctx->r10 & 0XF1;
    // 0x808013A4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x808013A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808013AC: sb          $t3, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r11;
    // 0x808013B0: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x808013B4: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x808013B8: b           L_8080141C
    // 0x808013BC: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
        goto L_8080141C;
    // 0x808013BC: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
L_808013C0:
    // 0x808013C0: lbu         $t4, 0x7A($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X7A);
    // 0x808013C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1364, 0X257C) << 16);
    // 0x808013C8: lwc1        $f0, 0x257C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1364, 0X257C));
    // 0x808013CC: andi        $t5, $t4, 0xFFF1
    ctx->r13 = ctx->r12 & 0XFFF1;
    // 0x808013D0: ori         $t6, $t5, 0x6
    ctx->r14 = ctx->r13 | 0X6;
    // 0x808013D4: sb          $t6, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r14;
    // 0x808013D8: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x808013DC: b           L_8080141C
    // 0x808013E0: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
        goto L_8080141C;
    // 0x808013E0: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x808013E4: lbu         $t7, 0x7A($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X7A);
L_808013E8:
    // 0x808013E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1364, 0X2580) << 16);
    // 0x808013EC: lwc1        $f0, 0x2580($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1364, 0X2580));
    // 0x808013F0: andi        $t8, $t7, 0xFFCF
    ctx->r24 = ctx->r15 & 0XFFCF;
    // 0x808013F4: ori         $t0, $t8, 0x20
    ctx->r8 = ctx->r24 | 0X20;
    // 0x808013F8: andi        $t1, $t0, 0xF1
    ctx->r9 = ctx->r8 & 0XF1;
    // 0x808013FC: sb          $t0, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r8;
    // 0x80801400: ori         $t2, $t1, 0x6
    ctx->r10 = ctx->r9 | 0X6;
    // 0x80801404: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80801408: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080140C: sb          $t2, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r10;
    // 0x80801410: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x80801414: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x80801418: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
L_8080141C:
    // 0x8080141C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801420:
    // 0x80801420: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801424: jr          $ra
    // 0x80801428: nop

    return;
    // 0x80801428: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C0C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800C10: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(124, 0X2E50) << 16);
    // 0x80800C14: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800C18: jr          $ra
    // 0x80800C1C: lw          $v0, 0x2E50($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2E50));
    return;
    // 0x80800C1C: lw          $v0, 0x2E50($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2E50));
;}
RECOMP_FUNC void func_8009D940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D940: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8009D944: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009D948: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009D94C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009D950: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8009D954: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8009D958: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8009D95C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8009D960: jal         0x8009DAAC
    // 0x8009D964: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_8009DAAC(rdram, ctx);
        goto after_0;
    // 0x8009D964: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x8009D968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009D96C: jal         0x8009C128
    // 0x8009D970: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x8009D970: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x8009D974: lw          $t6, 0x104($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X104);
    // 0x8009D978: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8009D97C: jal         0x800C35E8
    // 0x8009D980: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    func_800C35E8(rdram, ctx);
        goto after_2;
    // 0x8009D980: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    after_2:
    // 0x8009D984: lw          $t7, 0x104($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X104);
    // 0x8009D988: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8009D98C: jal         0x800C301C
    // 0x8009D990: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    func_800C301C(rdram, ctx);
        goto after_3;
    // 0x8009D990: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    after_3:
    // 0x8009D994: lw          $t8, 0x104($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X104);
    // 0x8009D998: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8009D99C: jal         0x800C31DC
    // 0x8009D9A0: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    func_800C31DC(rdram, ctx);
        goto after_4;
    // 0x8009D9A0: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    after_4:
    // 0x8009D9A4: lw          $t9, 0x104($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X104);
    // 0x8009D9A8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8009D9AC: jal         0x800C3058
    // 0x8009D9B0: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    func_800C3058(rdram, ctx);
        goto after_5;
    // 0x8009D9B0: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    after_5:
    // 0x8009D9B4: lw          $t0, 0x104($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X104);
    // 0x8009D9B8: jal         0x800C3BDC
    // 0x8009D9BC: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    func_800C3BDC(rdram, ctx);
        goto after_6;
    // 0x8009D9BC: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    after_6:
    // 0x8009D9C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009D9C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009D9C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8009D9CC: jr          $ra
    // 0x8009D9D0: nop

    return;
    // 0x8009D9D0: nop

;}
RECOMP_FUNC void func_8080044C_chvandoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_8080044C_chvandoor");
    // 0x8080044C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800450: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x80800454: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80800458: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8080045C: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x80800460: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80800464: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80800468: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8080046C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800470: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800474: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800478: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8080047C: jal         0x8010D290
    // 0x80800480: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    func_8010D290(rdram, ctx);
        goto after_0;
    // 0x80800480: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    after_0:
    // 0x80800484: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800488: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080048C: bne         $v0, $at, L_8080049C
    if (ctx->r2 != ctx->r1) {
        // 0x80800490: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_8080049C;
    }
    // 0x80800490: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80800494: b           L_808005F8
    // 0x80800498: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005F8;
    // 0x80800498: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080049C:
    // 0x8080049C: addiu       $s1, $sp, 0x64
    ctx->r17 = ADD32(ctx->r29, 0X64);
    // 0x808004A0: jal         0x800F5A00
    // 0x808004A4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x808004A4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x808004A8: addiu       $s0, $sp, 0x5C
    ctx->r16 = ADD32(ctx->r29, 0X5C);
    // 0x808004AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808004B0: jal         0x80089C30
    // 0x808004B4: addiu       $a0, $zero, 0x3CC
    ctx->r4 = ADD32(0, 0X3CC);
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808004B4: addiu       $a0, $zero, 0x3CC
    ctx->r4 = ADD32(0, 0X3CC);
    after_2:
    // 0x808004B8: beq         $v0, $zero, L_808004FC
    if (ctx->r2 == 0) {
        // 0x808004BC: lui         $s6, 0x8080
        ctx->r22 = S32(RELOC_HI16(1168, 0X690) << 16);
            goto L_808004FC;
    }
    // 0x808004BC: lui         $s6, 0x8080
    ctx->r22 = S32(RELOC_HI16(1168, 0X690) << 16);
    // 0x808004C0: addiu       $s6, $s6, 0x690
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(1168, 0X690));
    // 0x808004C4: lhu         $t6, 0x76($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X76);
L_808004C8:
    // 0x808004C8: lhu         $t8, 0x76($s7)
    ctx->r24 = MEM_HU(ctx->r23, 0X76);
    // 0x808004CC: addiu       $a0, $zero, 0x3CC
    ctx->r4 = ADD32(0, 0X3CC);
    // 0x808004D0: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808004D4: srl         $t9, $t8, 7
    ctx->r25 = S32(U32(ctx->r24) >> 7);
    // 0x808004D8: bne         $t7, $t9, L_808004EC
    if (ctx->r15 != ctx->r25) {
        // 0x808004DC: sll         $t0, $s5, 2
        ctx->r8 = S32(ctx->r21 << 2);
            goto L_808004EC;
    }
    // 0x808004DC: sll         $t0, $s5, 2
    ctx->r8 = S32(ctx->r21 << 2);
    // 0x808004E0: addu        $t1, $s6, $t0
    ctx->r9 = ADD32(ctx->r22, ctx->r8);
    // 0x808004E4: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x808004E8: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_808004EC:
    // 0x808004EC: jal         0x80089C38
    // 0x808004F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddiefind_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x808004F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x808004F4: bnel        $v0, $zero, L_808004C8
    if (ctx->r2 != 0) {
        // 0x808004F8: lhu         $t6, 0x76($v0)
        ctx->r14 = MEM_HU(ctx->r2, 0X76);
            goto L_808004C8;
    }
    goto skip_0;
    // 0x808004F8: lhu         $t6, 0x76($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X76);
    skip_0:
L_808004FC:
    // 0x808004FC: lui         $s6, 0x8080
    ctx->r22 = S32(RELOC_HI16(1168, 0X690) << 16);
    // 0x80800500: slti        $at, $s5, 0x2
    ctx->r1 = SIGNED(ctx->r21) < 0X2 ? 1 : 0;
    // 0x80800504: addiu       $s6, $s6, 0x690
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(1168, 0X690));
    // 0x80800508: bne         $at, $zero, L_808005BC
    if (ctx->r1 != 0) {
        // 0x8080050C: addiu       $s3, $zero, 0x1
        ctx->r19 = ADD32(0, 0X1);
            goto L_808005BC;
    }
    // 0x8080050C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80800510: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(1168, 0X694) << 16);
    // 0x80800514: addiu       $s2, $s2, 0x694
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(1168, 0X694));
L_80800518:
    // 0x80800518: blez        $s3, L_808005B0
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8080051C: or          $s4, $s3, $zero
        ctx->r20 = ctx->r19 | 0;
            goto L_808005B0;
    }
    // 0x8080051C: or          $s4, $s3, $zero
    ctx->r20 = ctx->r19 | 0;
    // 0x80800520: sll         $t2, $s3, 2
    ctx->r10 = S32(ctx->r19 << 2);
    // 0x80800524: addu        $s0, $s6, $t2
    ctx->r16 = ADD32(ctx->r22, ctx->r10);
    // 0x80800528: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080052C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800530: jal         0x800EEB40
    // 0x80800534: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EEB40(rdram, ctx);
        goto after_4;
    // 0x80800534: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_4:
    // 0x80800538: lw          $a0, -0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X4);
    // 0x8080053C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800540: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800544: jal         0x800EEB40
    // 0x80800548: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EEB40(rdram, ctx);
        goto after_5;
    // 0x80800548: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_5:
    // 0x8080054C: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80800550: sll         $t3, $s4, 2
    ctx->r11 = S32(ctx->r20 << 2);
    // 0x80800554: addu        $s0, $s6, $t3
    ctx->r16 = ADD32(ctx->r22, ctx->r11);
    // 0x80800558: bc1fl       L_808005B4
    if (!c1cs) {
        // 0x8080055C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_808005B4;
    }
    goto skip_1;
    // 0x8080055C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_1:
    // 0x80800560: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80800564:
    // 0x80800564: lw          $t4, -0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, -0X4);
    // 0x80800568: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
    // 0x8080056C: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x80800570: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80800574: bne         $at, $zero, L_808005B0
    if (ctx->r1 != 0) {
        // 0x80800578: sw          $t4, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->r12;
            goto L_808005B0;
    }
    // 0x80800578: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x8080057C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800580: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800584: jal         0x800EEB40
    // 0x80800588: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EEB40(rdram, ctx);
        goto after_6;
    // 0x80800588: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_6:
    // 0x8080058C: lw          $a0, -0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X4);
    // 0x80800590: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800594: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800598: jal         0x800EEB40
    // 0x8080059C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EEB40(rdram, ctx);
        goto after_7;
    // 0x8080059C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_7:
    // 0x808005A0: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x808005A4: nop

    // 0x808005A8: bc1tl       L_80800564
    if (c1cs) {
        // 0x808005AC: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80800564;
    }
    goto skip_2;
    // 0x808005AC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_2:
L_808005B0:
    // 0x808005B0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_808005B4:
    // 0x808005B4: bne         $s3, $s5, L_80800518
    if (ctx->r19 != ctx->r21) {
        // 0x808005B8: nop
    
            goto L_80800518;
    }
    // 0x808005B8: nop

L_808005BC:
    // 0x808005BC: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x808005C0: beq         $s7, $v0, L_808005D0
    if (ctx->r23 == ctx->r2) {
        // 0x808005C4: addiu       $a0, $v0, 0x4
        ctx->r4 = ADD32(ctx->r2, 0X4);
            goto L_808005D0;
    }
    // 0x808005C4: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x808005C8: b           L_808005F8
    // 0x808005CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005F8;
    // 0x808005CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005D0:
    // 0x808005D0: jal         0x800EEB40
    // 0x808005D4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EEB40(rdram, ctx);
        goto after_8;
    // 0x808005D4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x808005D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1168, 0X634) << 16);
    // 0x808005DC: lwc1        $f4, 0x634($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1168, 0X634));
    // 0x808005E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808005E4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808005E8: nop

    // 0x808005EC: bc1fl       L_808005FC
    if (!c1cs) {
        // 0x808005F0: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_808005FC;
    }
    goto skip_3;
    // 0x808005F0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_3:
    // 0x808005F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005F8:
    // 0x808005F8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_808005FC:
    // 0x808005FC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800600: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800604: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800608: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8080060C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800610: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80800614: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80800618: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x8080061C: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x80800620: jr          $ra
    // 0x80800624: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80800624: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80800628: nop

    // 0x8080062C: nop

;}
RECOMP_FUNC void _bsstatue_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083BD0: syscall     91
    recomp_syscall_handler(rdram, ctx, 0x80083BD0);
    return;
    // 0x80083BD4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_8009097C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009097C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090980: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090984: lw          $t6, 0x20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20);
    // 0x80090988: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8009098C: sb          $a1, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r5;
    // 0x80090990: lw          $t7, 0x20($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X20);
    // 0x80090994: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80090998: sb          $zero, 0x8($t7)
    MEM_B(0X8, ctx->r15) = 0;
    // 0x8009099C: jal         0x800908A8
    // 0x800909A0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800908A8(rdram, ctx);
        goto after_0;
    // 0x800909A0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800909A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800909A8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800909AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800909B0: lw          $t8, 0x20($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X20);
    // 0x800909B4: jal         0x800908F0
    // 0x800909B8: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    func_800908F0(rdram, ctx);
        goto after_1;
    // 0x800909B8: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    after_1:
    // 0x800909BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800909C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800909C4: jr          $ra
    // 0x800909C8: nop

    return;
    // 0x800909C8: nop

;}
RECOMP_FUNC void func_80801FB8_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801FB8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801FBC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801FC0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801FC4: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80801FC8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801FCC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801FD0: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80801FD4: beq         $t6, $at, L_8080210C
    if (ctx->r14 == ctx->r1) {
        // 0x80801FD8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080210C;
    }
    // 0x80801FD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801FDC: beq         $t6, $at, L_80802004
    if (ctx->r14 == ctx->r1) {
        // 0x80801FE0: addiu       $a0, $s0, 0x58
        ctx->r4 = ADD32(ctx->r16, 0X58);
            goto L_80802004;
    }
    // 0x80801FE0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x80801FE4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801FE8: beq         $t6, $at, L_8080202C
    if (ctx->r14 == ctx->r1) {
        // 0x80801FEC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8080202C;
    }
    // 0x80801FEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801FF0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801FF4: beq         $t6, $at, L_80802040
    if (ctx->r14 == ctx->r1) {
        // 0x80801FF8: addiu       $a2, $zero, 0x0
        ctx->r6 = ADD32(0, 0X0);
            goto L_80802040;
    }
    // 0x80801FF8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80801FFC: b           L_80802110
    // 0x80802000: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
        goto L_80802110;
    // 0x80802000: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_80802004:
    // 0x80802004: jal         0x800D91EC
    // 0x80802008: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_800D91EC(rdram, ctx);
        goto after_0;
    // 0x80802008: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_0:
    // 0x8080200C: beq         $v0, $zero, L_8080210C
    if (ctx->r2 == 0) {
        // 0x80802010: addiu       $t7, $zero, 0xFF
        ctx->r15 = ADD32(0, 0XFF);
            goto L_8080210C;
    }
    // 0x80802010: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80802014: sb          $t7, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r15;
    // 0x80802018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080201C: jal         0x80101FDC
    // 0x80802020: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80802020: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80802024: b           L_80802110
    // 0x80802028: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
        goto L_80802110;
    // 0x80802028: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_8080202C:
    // 0x8080202C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80802030: jal         0x80018820
    // 0x80802034: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_80018820(rdram, ctx);
        goto after_2;
    // 0x80802034: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_2:
    // 0x80802038: b           L_80802110
    // 0x8080203C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
        goto L_80802110;
    // 0x8080203C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_80802040:
    // 0x80802040: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80802044: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80802048: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8080204C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802050: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80802054: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80802058: jal         0x800F10B4
    // 0x8080205C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x8080205C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80802060: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80802064: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80802068: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8080206C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80802070: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x80802074: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80802078: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8080207C: nop

    // 0x80802080: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80802084: beql        $t9, $zero, L_808020D4
    if (ctx->r25 == 0) {
        // 0x80802088: mfc1        $t9, $f6
        ctx->r25 = (int32_t)ctx->f6.u32l;
            goto L_808020D4;
    }
    goto skip_0;
    // 0x80802088: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x8080208C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802090: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80802094: sub.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80802098: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8080209C: nop

    // 0x808020A0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x808020A4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x808020A8: nop

    // 0x808020AC: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x808020B0: bne         $t9, $zero, L_808020C8
    if (ctx->r25 != 0) {
        // 0x808020B4: nop
    
            goto L_808020C8;
    }
    // 0x808020B4: nop

    // 0x808020B8: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x808020BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808020C0: b           L_808020E0
    // 0x808020C4: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_808020E0;
    // 0x808020C4: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_808020C8:
    // 0x808020C8: b           L_808020E0
    // 0x808020CC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_808020E0;
    // 0x808020CC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x808020D0: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
L_808020D4:
    // 0x808020D4: nop

    // 0x808020D8: bltz        $t9, L_808020C8
    if (SIGNED(ctx->r25) < 0) {
        // 0x808020DC: nop
    
            goto L_808020C8;
    }
    // 0x808020DC: nop

L_808020E0:
    // 0x808020E0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x808020E4: jal         0x800D90A4
    // 0x808020E8: sb          $t9, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r25;
    func_800D90A4(rdram, ctx);
        goto after_4;
    // 0x808020E8: sb          $t9, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r25;
    after_4:
    // 0x808020EC: beql        $v0, $zero, L_80802110
    if (ctx->r2 == 0) {
        // 0x808020F0: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_80802110;
    }
    goto skip_1;
    // 0x808020F0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_1:
    // 0x808020F4: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x808020F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808020FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802100: andi        $t1, $t0, 0xFFFE
    ctx->r9 = ctx->r8 & 0XFFFE;
    // 0x80802104: jal         0x80101FDC
    // 0x80802108: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80802108: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    after_5:
L_8080210C:
    // 0x8080210C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_80802110:
    // 0x80802110: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80802114: lbu         $a0, 0x28($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X28);
    // 0x80802118: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080211C: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80802120: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802124: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2284, 0X2A94) << 16);
    // 0x80802128: bc1tl       L_80802138
    if (c1cs) {
        // 0x8080212C: lw          $t2, 0x70($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X70);
            goto L_80802138;
    }
    goto skip_2;
    // 0x8080212C: lw          $t2, 0x70($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X70);
    skip_2:
    // 0x80802130: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80802134: lw          $t2, 0x70($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X70);
L_80802138:
    // 0x80802138: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080213C: addiu       $a3, $a3, 0x2A94
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2284, 0X2A94));
    // 0x80802140: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80802144: jal         0x80089D68
    // 0x80802148: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x80802148: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_6:
    // 0x8080214C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80802150: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80802154: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80802158: sb          $v0, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r2;
    // 0x8080215C: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x80802160: lbu         $a0, 0x2C($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X2C);
    // 0x80802164: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802168: bc1tl       L_80802178
    if (c1cs) {
        // 0x8080216C: lw          $t4, 0x70($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X70);
            goto L_80802178;
    }
    goto skip_3;
    // 0x8080216C: lw          $t4, 0x70($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X70);
    skip_3:
    // 0x80802170: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80802174: lw          $t4, 0x70($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X70);
L_80802178:
    // 0x80802178: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2284, 0X2AA4) << 16);
    // 0x8080217C: addiu       $a3, $a3, 0x2AA4
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2284, 0X2AA4));
    // 0x80802180: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80802184: jal         0x80089D68
    // 0x80802188: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_7;
    // 0x80802188: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_7:
    // 0x8080218C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80802190: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80802194: sb          $v0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r2;
    // 0x80802198: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080219C: c.eq.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl == ctx->f12.fl;
    // 0x808021A0: lui         $a3, 0x437F
    ctx->r7 = S32(0X437F << 16);
    // 0x808021A4: bc1fl       L_808021C0
    if (!c1cs) {
        // 0x808021A8: lbu         $t9, 0x65($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X65);
            goto L_808021C0;
    }
    goto skip_4;
    // 0x808021A8: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    skip_4:
    // 0x808021AC: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x808021B0: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x808021B4: b           L_808022C4
    // 0x808021B8: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
        goto L_808022C4;
    // 0x808021B8: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    // 0x808021BC: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
L_808021C0:
    // 0x808021C0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808021C4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808021C8: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x808021CC: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x808021D0: jal         0x800F10B4
    // 0x808021D4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x808021D4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x808021D8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x808021DC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x808021E0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x808021E4: lui         $a3, 0x3F8C
    ctx->r7 = S32(0X3F8C << 16);
    // 0x808021E8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808021EC: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x808021F0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808021F4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808021F8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x808021FC: nop

    // 0x80802200: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80802204: beql        $t2, $zero, L_80802254
    if (ctx->r10 == 0) {
        // 0x80802208: mfc1        $t2, $f4
        ctx->r10 = (int32_t)ctx->f4.u32l;
            goto L_80802254;
    }
    goto skip_5;
    // 0x80802208: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    skip_5:
    // 0x8080220C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802210: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80802214: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80802218: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8080221C: nop

    // 0x80802220: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80802224: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80802228: nop

    // 0x8080222C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80802230: bne         $t2, $zero, L_80802248
    if (ctx->r10 != 0) {
        // 0x80802234: nop
    
            goto L_80802248;
    }
    // 0x80802234: nop

    // 0x80802238: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x8080223C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80802240: b           L_80802260
    // 0x80802244: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80802260;
    // 0x80802244: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80802248:
    // 0x80802248: b           L_80802260
    // 0x8080224C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80802260;
    // 0x8080224C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80802250: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
L_80802254:
    // 0x80802254: nop

    // 0x80802258: bltz        $t2, L_80802248
    if (SIGNED(ctx->r10) < 0) {
        // 0x8080225C: nop
    
            goto L_80802248;
    }
    // 0x8080225C: nop

L_80802260:
    // 0x80802260: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80802264: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80802268: sb          $t2, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r10;
    // 0x8080226C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2284, 0X2908) << 16);
    // 0x80802270: lwc1        $f6, 0x2908($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2284, 0X2908));
    // 0x80802274: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80802278: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080227C: jal         0x800F10B4
    // 0x80802280: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_9;
    // 0x80802280: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x80802284: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80802288: jal         0x800C31DC
    // 0x8080228C: lbu         $a0, 0x28($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X28);
    func_800C31DC(rdram, ctx);
        goto after_10;
    // 0x8080228C: lbu         $a0, 0x28($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X28);
    after_10:
    // 0x80802290: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80802294: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80802298: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2284, 0X290C) << 16);
    // 0x8080229C: lwc1        $f8, 0x290C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2284, 0X290C));
    // 0x808022A0: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808022A4: lui         $a3, 0x3F8C
    ctx->r7 = S32(0X3F8C << 16);
    // 0x808022A8: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808022AC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808022B0: jal         0x800F10B4
    // 0x808022B4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_11;
    // 0x808022B4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_11:
    // 0x808022B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808022BC: jal         0x800C31DC
    // 0x808022C0: lbu         $a0, 0x2C($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X2C);
    func_800C31DC(rdram, ctx);
        goto after_12;
    // 0x808022C0: lbu         $a0, 0x2C($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X2C);
    after_12:
L_808022C4:
    // 0x808022C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808022C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808022CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808022D0: jr          $ra
    // 0x808022D4: nop

    return;
    // 0x808022D4: nop

;}
RECOMP_FUNC void func_800FCFB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FCFB0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800FCFB4: addiu       $t7, $t7, 0x5A20
    ctx->r15 = ADD32(ctx->r15, 0X5A20);
    // 0x800FCFB8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800FCFBC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FCFC0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800FCFC4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800FCFC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FCFCC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800FCFD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FCFD4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800FCFD8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800FCFDC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800FCFE0: bne         $a1, $v1, L_800FD0E4
    if (ctx->r5 != ctx->r3) {
        // 0x800FCFE4: or          $t0, $t6, $zero
        ctx->r8 = ctx->r14 | 0;
            goto L_800FD0E4;
    }
    // 0x800FCFE4: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x800FCFE8: beq         $a3, $zero, L_800FD060
    if (ctx->r7 == 0) {
        // 0x800FCFEC: or          $t8, $a3, $zero
        ctx->r24 = ctx->r7 | 0;
            goto L_800FD060;
    }
    // 0x800FCFEC: or          $t8, $a3, $zero
    ctx->r24 = ctx->r7 | 0;
    // 0x800FCFF0: lh          $v0, 0xA($a2)
    ctx->r2 = MEM_H(ctx->r6, 0XA);
    // 0x800FCFF4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FCFF8: or          $t9, $a2, $zero
    ctx->r25 = ctx->r6 | 0;
    // 0x800FCFFC: beq         $v0, $at, L_800FD044
    if (ctx->r2 == ctx->r1) {
        // 0x800FD000: lui         $t1, 0x393
        ctx->r9 = S32(0X393 << 16);
            goto L_800FD044;
    }
    // 0x800FD000: lui         $t1, 0x393
    ctx->r9 = S32(0X393 << 16);
    // 0x800FD004: ori         $t1, $t1, 0x8700
    ctx->r9 = ctx->r9 | 0X8700;
    // 0x800FD008: div         $zero, $t1, $v0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r2)));
    // 0x800FD00C: mflo        $a1
    ctx->r5 = lo;
    // 0x800FD010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FD014: bne         $v0, $zero, L_800FD020
    if (ctx->r2 != 0) {
        // 0x800FD018: nop
    
            goto L_800FD020;
    }
    // 0x800FD018: nop

    // 0x800FD01C: break       7
    do_break(2148519964);
L_800FD020:
    // 0x800FD020: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FD024: bne         $v0, $at, L_800FD038
    if (ctx->r2 != ctx->r1) {
        // 0x800FD028: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800FD038;
    }
    // 0x800FD028: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800FD02C: bne         $t1, $at, L_800FD038
    if (ctx->r9 != ctx->r1) {
        // 0x800FD030: nop
    
            goto L_800FD038;
    }
    // 0x800FD030: nop

    // 0x800FD034: break       6
    do_break(2148519988);
L_800FD038:
    // 0x800FD038: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800FD03C: jal         0x800FCED0
    // 0x800FD040: nop

    func_800FCED0(rdram, ctx);
        goto after_0;
    // 0x800FD040: nop

    after_0:
L_800FD044:
    // 0x800FD044: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800FD048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FD04C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800FD050: jal         0x800FCDE0
    // 0x800FD054: lw          $a1, 0x4($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4);
    func_800FCDE0(rdram, ctx);
        goto after_1;
    // 0x800FD054: lw          $a1, 0x4($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4);
    after_1:
    // 0x800FD058: b           L_800FD0D0
    // 0x800FD05C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
        goto L_800FD0D0;
    // 0x800FD05C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
L_800FD060:
    // 0x800FD060: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800FD064: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FD068: lui         $t4, 0x393
    ctx->r12 = S32(0X393 << 16);
    // 0x800FD06C: lh          $v0, 0x8($t3)
    ctx->r2 = MEM_H(ctx->r11, 0X8);
    // 0x800FD070: ori         $t4, $t4, 0x8700
    ctx->r12 = ctx->r12 | 0X8700;
    // 0x800FD074: beql        $v0, $at, L_800FD0BC
    if (ctx->r2 == ctx->r1) {
        // 0x800FD078: lw          $t5, 0x30($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X30);
            goto L_800FD0BC;
    }
    goto skip_0;
    // 0x800FD078: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x800FD07C: div         $zero, $t4, $v0
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r2)));
    // 0x800FD080: mflo        $a1
    ctx->r5 = lo;
    // 0x800FD084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FD088: bne         $v0, $zero, L_800FD094
    if (ctx->r2 != 0) {
        // 0x800FD08C: nop
    
            goto L_800FD094;
    }
    // 0x800FD08C: nop

    // 0x800FD090: break       7
    do_break(2148520080);
L_800FD094:
    // 0x800FD094: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FD098: bne         $v0, $at, L_800FD0AC
    if (ctx->r2 != ctx->r1) {
        // 0x800FD09C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800FD0AC;
    }
    // 0x800FD09C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800FD0A0: bne         $t4, $at, L_800FD0AC
    if (ctx->r12 != ctx->r1) {
        // 0x800FD0A4: nop
    
            goto L_800FD0AC;
    }
    // 0x800FD0A4: nop

    // 0x800FD0A8: break       6
    do_break(2148520104);
L_800FD0AC:
    // 0x800FD0AC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800FD0B0: jal         0x800FCED0
    // 0x800FD0B4: nop

    func_800FCED0(rdram, ctx);
        goto after_2;
    // 0x800FD0B4: nop

    after_2:
    // 0x800FD0B8: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
L_800FD0BC:
    // 0x800FD0BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FD0C0: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800FD0C4: jal         0x800FCDE0
    // 0x800FD0C8: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    func_800FCDE0(rdram, ctx);
        goto after_3;
    // 0x800FD0C8: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    after_3:
    // 0x800FD0CC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
L_800FD0D0:
    // 0x800FD0D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD0D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800FD0D8: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800FD0DC: b           L_800FD28C
    // 0x800FD0E0: sb          $t6, 0x5A3C($at)
    MEM_B(0X5A3C, ctx->r1) = ctx->r14;
        goto L_800FD28C;
    // 0x800FD0E0: sb          $t6, 0x5A3C($at)
    MEM_B(0X5A3C, ctx->r1) = ctx->r14;
L_800FD0E4:
    // 0x800FD0E4: bne         $v1, $zero, L_800FD28C
    if (ctx->r3 != 0) {
        // 0x800FD0E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800FD28C;
    }
    // 0x800FD0E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FD0EC: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x800FD0F0: jal         0x800FCCD4
    // 0x800FD0F4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    func_800FCCD4(rdram, ctx);
        goto after_4;
    // 0x800FD0F4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_4:
    // 0x800FD0F8: bnel        $v0, $zero, L_800FD124
    if (ctx->r2 != 0) {
        // 0x800FD0FC: addiu       $at, $zero, 0x4B
        ctx->r1 = ADD32(0, 0X4B);
            goto L_800FD124;
    }
    goto skip_1;
    // 0x800FD0FC: addiu       $at, $zero, 0x4B
    ctx->r1 = ADD32(0, 0X4B);
    skip_1:
    // 0x800FD100: jal         0x80017764
    // 0x800FD104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80017764(rdram, ctx);
        goto after_5;
    // 0x800FD104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800FD108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FD10C: jal         0x800FC688
    // 0x800FD110: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800FC688(rdram, ctx);
        goto after_6;
    // 0x800FD110: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x800FD114: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800FD118: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD11C: sb          $t8, 0x59D5($at)
    MEM_B(0X59D5, ctx->r1) = ctx->r24;
    // 0x800FD120: addiu       $at, $zero, 0x4B
    ctx->r1 = ADD32(0, 0X4B);
L_800FD124:
    // 0x800FD124: bne         $s0, $at, L_800FD144
    if (ctx->r16 != ctx->r1) {
        // 0x800FD128: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800FD144;
    }
    // 0x800FD128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FD12C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FD130: lui         $a1, 0x3E00
    ctx->r5 = S32(0X3E00 << 16);
    // 0x800FD134: jal         0x800FC97C
    // 0x800FD138: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800FC97C(rdram, ctx);
        goto after_7;
    // 0x800FD138: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_7:
    // 0x800FD13C: b           L_800FD154
    // 0x800FD140: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_800FD154;
    // 0x800FD140: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_800FD144:
    // 0x800FD144: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    // 0x800FD148: jal         0x800FC97C
    // 0x800FD14C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800FC97C(rdram, ctx);
        goto after_8;
    // 0x800FD14C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_8:
    // 0x800FD150: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_800FD154:
    // 0x800FD154: beql        $t9, $zero, L_800FD1D4
    if (ctx->r25 == 0) {
        // 0x800FD158: lw          $t4, 0x30($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X30);
            goto L_800FD1D4;
    }
    goto skip_2;
    // 0x800FD158: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    skip_2:
    // 0x800FD15C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800FD160: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FD164: lui         $t2, 0x393
    ctx->r10 = S32(0X393 << 16);
    // 0x800FD168: lh          $v0, 0xA($t1)
    ctx->r2 = MEM_H(ctx->r9, 0XA);
    // 0x800FD16C: ori         $t2, $t2, 0x8700
    ctx->r10 = ctx->r10 | 0X8700;
    // 0x800FD170: beql        $v0, $at, L_800FD1B8
    if (ctx->r2 == ctx->r1) {
        // 0x800FD174: lw          $t3, 0x30($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X30);
            goto L_800FD1B8;
    }
    goto skip_3;
    // 0x800FD174: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    skip_3:
    // 0x800FD178: div         $zero, $t2, $v0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r2)));
    // 0x800FD17C: mflo        $a1
    ctx->r5 = lo;
    // 0x800FD180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FD184: bne         $v0, $zero, L_800FD190
    if (ctx->r2 != 0) {
        // 0x800FD188: nop
    
            goto L_800FD190;
    }
    // 0x800FD188: nop

    // 0x800FD18C: break       7
    do_break(2148520332);
L_800FD190:
    // 0x800FD190: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FD194: bne         $v0, $at, L_800FD1A8
    if (ctx->r2 != ctx->r1) {
        // 0x800FD198: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800FD1A8;
    }
    // 0x800FD198: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800FD19C: bne         $t2, $at, L_800FD1A8
    if (ctx->r10 != ctx->r1) {
        // 0x800FD1A0: nop
    
            goto L_800FD1A8;
    }
    // 0x800FD1A0: nop

    // 0x800FD1A4: break       6
    do_break(2148520356);
L_800FD1A8:
    // 0x800FD1A8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800FD1AC: jal         0x800FCED0
    // 0x800FD1B0: nop

    func_800FCED0(rdram, ctx);
        goto after_9;
    // 0x800FD1B0: nop

    after_9:
    // 0x800FD1B4: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
L_800FD1B8:
    // 0x800FD1B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FD1BC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800FD1C0: jal         0x800FCDE0
    // 0x800FD1C4: lw          $a1, 0x4($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X4);
    func_800FCDE0(rdram, ctx);
        goto after_10;
    // 0x800FD1C4: lw          $a1, 0x4($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X4);
    after_10:
    // 0x800FD1C8: b           L_800FD240
    // 0x800FD1CC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
        goto L_800FD240;
    // 0x800FD1CC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800FD1D0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
L_800FD1D4:
    // 0x800FD1D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FD1D8: lui         $t5, 0x393
    ctx->r13 = S32(0X393 << 16);
    // 0x800FD1DC: lh          $v0, 0x8($t4)
    ctx->r2 = MEM_H(ctx->r12, 0X8);
    // 0x800FD1E0: ori         $t5, $t5, 0x8700
    ctx->r13 = ctx->r13 | 0X8700;
    // 0x800FD1E4: beql        $v0, $at, L_800FD22C
    if (ctx->r2 == ctx->r1) {
        // 0x800FD1E8: lw          $t6, 0x30($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X30);
            goto L_800FD22C;
    }
    goto skip_4;
    // 0x800FD1E8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    skip_4:
    // 0x800FD1EC: div         $zero, $t5, $v0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r2)));
    // 0x800FD1F0: mflo        $a1
    ctx->r5 = lo;
    // 0x800FD1F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FD1F8: bne         $v0, $zero, L_800FD204
    if (ctx->r2 != 0) {
        // 0x800FD1FC: nop
    
            goto L_800FD204;
    }
    // 0x800FD1FC: nop

    // 0x800FD200: break       7
    do_break(2148520448);
L_800FD204:
    // 0x800FD204: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FD208: bne         $v0, $at, L_800FD21C
    if (ctx->r2 != ctx->r1) {
        // 0x800FD20C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800FD21C;
    }
    // 0x800FD20C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800FD210: bne         $t5, $at, L_800FD21C
    if (ctx->r13 != ctx->r1) {
        // 0x800FD214: nop
    
            goto L_800FD21C;
    }
    // 0x800FD214: nop

    // 0x800FD218: break       6
    do_break(2148520472);
L_800FD21C:
    // 0x800FD21C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800FD220: jal         0x800FCED0
    // 0x800FD224: nop

    func_800FCED0(rdram, ctx);
        goto after_11;
    // 0x800FD224: nop

    after_11:
    // 0x800FD228: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_800FD22C:
    // 0x800FD22C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FD230: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800FD234: jal         0x800FCDE0
    // 0x800FD238: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    func_800FCDE0(rdram, ctx);
        goto after_12;
    // 0x800FD238: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_12:
    // 0x800FD23C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
L_800FD240:
    // 0x800FD240: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD244: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800FD248: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800FD24C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800FD250: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800FD254: sb          $t7, 0x5A3C($at)
    MEM_B(0X5A3C, ctx->r1) = ctx->r15;
    // 0x800FD258: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD25C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800FD260: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800FD264: addiu       $v1, $v1, 0x5A40
    ctx->r3 = ADD32(ctx->r3, 0X5A40);
    // 0x800FD268: swc1        $f4, 0x5A30($at)
    MEM_W(0X5A30, ctx->r1) = ctx->f4.u32l;
    // 0x800FD26C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800FD270: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FD274: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800FD278: bne         $v0, $at, L_800FD288
    if (ctx->r2 != ctx->r1) {
        // 0x800FD27C: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_800FD288;
    }
    // 0x800FD27C: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x800FD280: b           L_800FD28C
    // 0x800FD284: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
        goto L_800FD28C;
    // 0x800FD284: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_800FD288:
    // 0x800FD288: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
L_800FD28C:
    // 0x800FD28C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FD290: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FD294: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800FD298: jr          $ra
    // 0x800FD29C: nop

    return;
    // 0x800FD29C: nop

;}
RECOMP_FUNC void func_800FC660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC660: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FC664: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FC668: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800FC66C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800FC670: jal         0x800FC508
    // 0x800FC674: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    func_800FC508(rdram, ctx);
        goto after_0;
    // 0x800FC674: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_0:
    // 0x800FC678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FC67C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FC680: jr          $ra
    // 0x800FC684: nop

    return;
    // 0x800FC684: nop

;}
RECOMP_FUNC void func_800AA120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA120: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AA124: lh          $a0, 0x7780($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7780);
    // 0x800AA128: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AA12C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA130: jal         0x800A9FA0
    // 0x800AA134: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    func_800A9FA0(rdram, ctx);
        goto after_0;
    // 0x800AA134: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    after_0:
    // 0x800AA138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AA13C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AA140: jr          $ra
    // 0x800AA144: nop

    return;
    // 0x800AA144: nop

;}
RECOMP_FUNC void func_80800000_sulights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80800004: lw          $a2, 0x7EF0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7EF0);
    // 0x80800008: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800014: bne         $a2, $zero, L_80800038
    if (ctx->r6 != 0) {
        // 0x80800018: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80800038;
    }
    // 0x80800018: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080001C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x80800020: jal         0x800B2D70
    // 0x80800024: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    vector_new(rdram, ctx);
        goto after_0;
    // 0x80800024: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800028: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8080002C: sw          $v0, 0x7EF0($at)
    MEM_W(0X7EF0, ctx->r1) = ctx->r2;
    // 0x80800030: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80800034: lw          $a2, 0x7EF0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7EF0);
L_80800038:
    // 0x80800038: jal         0x800B296C
    // 0x8080003C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    vector_end(rdram, ctx);
        goto after_1;
    // 0x8080003C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x80800040: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80800044: lw          $a0, 0x7EF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF0);
    // 0x80800048: jal         0x800B28C4
    // 0x8080004C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    vector_begin(rdram, ctx);
        goto after_2;
    // 0x8080004C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800050: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800054: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800058: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8080005C: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x80800060: beq         $at, $zero, L_80800090
    if (ctx->r1 == 0) {
        // 0x80800064: nop
    
            goto L_80800090;
    }
    // 0x80800064: nop

    // 0x80800068: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8080006C: beq         $t6, $zero, L_80800090
    if (ctx->r14 == 0) {
        // 0x80800070: nop
    
            goto L_80800090;
    }
    // 0x80800070: nop

    // 0x80800074: addiu       $v1, $v1, 0x3C
    ctx->r3 = ADD32(ctx->r3, 0X3C);
L_80800078:
    // 0x80800078: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x8080007C: beq         $at, $zero, L_80800090
    if (ctx->r1 == 0) {
        // 0x80800080: nop
    
            goto L_80800090;
    }
    // 0x80800080: nop

    // 0x80800084: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x80800088: bnel        $t7, $zero, L_80800078
    if (ctx->r15 != 0) {
        // 0x8080008C: addiu       $v1, $v1, 0x3C
        ctx->r3 = ADD32(ctx->r3, 0X3C);
            goto L_80800078;
    }
    goto skip_0;
    // 0x8080008C: addiu       $v1, $v1, 0x3C
    ctx->r3 = ADD32(ctx->r3, 0X3C);
    skip_0:
L_80800090:
    // 0x80800090: bnel        $v1, $a1, L_808000A8
    if (ctx->r3 != ctx->r5) {
        // 0x80800094: lw          $t8, 0x20($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X20);
            goto L_808000A8;
    }
    goto skip_1;
    // 0x80800094: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x80800098: jal         0x800B2974
    // 0x8080009C: addiu       $a0, $a0, 0x7EF0
    ctx->r4 = ADD32(ctx->r4, 0X7EF0);
    vector_push_back(rdram, ctx);
        goto after_3;
    // 0x8080009C: addiu       $a0, $a0, 0x7EF0
    ctx->r4 = ADD32(ctx->r4, 0X7EF0);
    after_3:
    // 0x808000A0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808000A4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
L_808000A8:
    // 0x808000A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808000AC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808000B0: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x808000B4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x808000B8: swc1        $f4, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f4.u32l;
    // 0x808000BC: sb          $t9, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r25;
    // 0x808000C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000C8: jr          $ra
    // 0x808000CC: nop

    return;
    // 0x808000CC: nop

;}
RECOMP_FUNC void func_800F457C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F457C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F4580: bne         $a1, $zero, L_800F4598
    if (ctx->r5 != 0) {
        // 0x800F4584: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800F4598;
    }
    // 0x800F4584: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4588: jal         0x8009CCA4
    // 0x800F458C: nop

    func_8009CCA4(rdram, ctx);
        goto after_0;
    // 0x800F458C: nop

    after_0:
    // 0x800F4590: b           L_800F45A4
    // 0x800F4594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F45A4;
    // 0x800F4594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F4598:
    // 0x800F4598: jal         0x8009CCFC
    // 0x800F459C: nop

    func_8009CCFC(rdram, ctx);
        goto after_1;
    // 0x800F459C: nop

    after_1:
    // 0x800F45A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F45A4:
    // 0x800F45A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F45A8: jr          $ra
    // 0x800F45AC: nop

    return;
    // 0x800F45AC: nop

;}
RECOMP_FUNC void func_800D5270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5270: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D5274: jr          $ra
    // 0x800D5278: sb          $zero, -0x4BCF($at)
    MEM_B(-0X4BCF, ctx->r1) = 0;
    return;
    // 0x800D5278: sb          $zero, -0x4BCF($at)
    MEM_B(-0X4BCF, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80800C18_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C20: jal         0x800845D0
    // 0x80800C24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _babounce_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800C24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800C28: jal         0x80800198
    // 0x80800C2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bssnowball_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800C2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800C30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C38: jr          $ra
    // 0x80800C3C: nop

    return;
    // 0x80800C3C: nop

;}
RECOMP_FUNC void func_80094F88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094F88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80094F8C: beq         $a1, $zero, L_80094FBC
    if (ctx->r5 == 0) {
        // 0x80094F90: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80094FBC;
    }
    // 0x80094F90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80094F94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80094F98: beq         $a1, $at, L_80094FCC
    if (ctx->r5 == ctx->r1) {
        // 0x80094F9C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80094FCC;
    }
    // 0x80094F9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80094FA0: beq         $a1, $at, L_80094FDC
    if (ctx->r5 == ctx->r1) {
        // 0x80094FA4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80094FDC;
    }
    // 0x80094FA4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80094FA8: beql        $a1, $at, L_80094FEC
    if (ctx->r5 == ctx->r1) {
        // 0x80094FAC: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80094FEC;
    }
    goto skip_0;
    // 0x80094FAC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x80094FB0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80094FB4: b           L_80094FF4
    // 0x80094FB8: nop

        goto L_80094FF4;
    // 0x80094FB8: nop

L_80094FBC:
    // 0x80094FBC: jal         0x800A0C2C
    // 0x80094FC0: nop

    func_800A0C2C(rdram, ctx);
        goto after_0;
    // 0x80094FC0: nop

    after_0:
    // 0x80094FC4: b           L_80094FF8
    // 0x80094FC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80094FF8;
    // 0x80094FC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80094FCC:
    // 0x80094FCC: jal         0x800A0C38
    // 0x80094FD0: nop

    func_800A0C38(rdram, ctx);
        goto after_1;
    // 0x80094FD0: nop

    after_1:
    // 0x80094FD4: b           L_80094FF8
    // 0x80094FD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80094FF8;
    // 0x80094FD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80094FDC:
    // 0x80094FDC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80094FE0: b           L_80094FF8
    // 0x80094FE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80094FF8;
    // 0x80094FE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80094FE8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80094FEC:
    // 0x80094FEC: b           L_80094FF8
    // 0x80094FF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80094FF8;
    // 0x80094FF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80094FF4:
    // 0x80094FF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80094FF8:
    // 0x80094FF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80094FFC: jr          $ra
    // 0x80095000: nop

    return;
    // 0x80095000: nop

;}
RECOMP_FUNC void _cheggice_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087240: syscall     538
    recomp_syscall_handler(rdram, ctx, 0x80087240);
    return;
    // 0x80087244: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _ncbaglide_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800896E0: syscall     788
    recomp_syscall_handler(rdram, ctx, 0x800896E0);
    return;
    // 0x800896E4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_801121B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801121B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801121BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801121C0: jal         0x80112168
    // 0x801121C4: nop

    func_80112168(rdram, ctx);
        goto after_0;
    // 0x801121C4: nop

    after_0:
    // 0x801121C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801121CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801121D0: jr          $ra
    // 0x801121D4: nop

    return;
    // 0x801121D4: nop

;}
RECOMP_FUNC void func_808003C0_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808003CC: jal         0x8009BCB4
    // 0x808003D0: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_0;
    // 0x808003D0: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    after_0:
    // 0x808003D4: lui         $a1, 0x4305
    ctx->r5 = S32(0X4305 << 16);
    // 0x808003D8: ori         $a1, $a1, 0x547B
    ctx->r5 = ctx->r5 | 0X547B;
    // 0x808003DC: jal         0x8009BCC4
    // 0x808003E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_1;
    // 0x808003E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808003E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808003E8: jal         0x800961AC
    // 0x808003EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800961AC(rdram, ctx);
        goto after_2;
    // 0x808003EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x808003F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003F8: jr          $ra
    // 0x808003FC: nop

    return;
    // 0x808003FC: nop

;}
RECOMP_FUNC void func_800FB508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB508: lhu         $t6, 0x0($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X0);
    // 0x800FB50C: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x800FB510: lhu         $t7, 0x2($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X2);
    // 0x800FB514: sh          $t7, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r15;
    // 0x800FB518: lhu         $t8, 0x4($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X4);
    // 0x800FB51C: sh          $t8, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r24;
    // 0x800FB520: lw          $t9, 0x8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X8);
    // 0x800FB524: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x800FB528: lh          $t0, 0x6($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X6);
    // 0x800FB52C: jr          $ra
    // 0x800FB530: sh          $t0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r8;
    return;
    // 0x800FB530: sh          $t0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r8;
    // 0x800FB534: nop

    // 0x800FB538: nop

    // 0x800FB53C: nop

;}
RECOMP_FUNC void func_800D9888(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9888: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800D988C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D9890: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800D9894: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800D9898: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800D989C: lwc1        $f14, 0x0($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800D98A0: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800D98A4: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800D98A8: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800D98AC: mul.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800D98B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D98B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800D98B8: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800D98BC: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800D98C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D98C4: lwc1        $f18, 0x5D20($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5D20);
    // 0x800D98C8: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x800D98CC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800D98D0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800D98D4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800D98D8: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800D98DC: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800D98E0: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800D98E4: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800D98E8: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800D98EC: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800D98F0: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800D98F4: add.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x800D98F8: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800D98FC: nop

    // 0x800D9900: bc1fl       L_800D9A20
    if (!c1cs) {
        // 0x800D9904: neg.s       $f6, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
            goto L_800D9A20;
    }
    goto skip_0;
    // 0x800D9904: neg.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
    skip_0:
    // 0x800D9908: sub.s       $f10, $f16, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x800D990C: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x800D9910: nop

    // 0x800D9914: bc1fl       L_800D99AC
    if (!c1cs) {
        // 0x800D9918: sub.s       $f2, $f16, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f20.fl;
            goto L_800D99AC;
    }
    goto skip_1;
    // 0x800D9918: sub.s       $f2, $f16, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f20.fl;
    skip_1:
    // 0x800D991C: jal         0x80013A7C
    // 0x800D9920: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    func_80013A7C(rdram, ctx);
        goto after_0;
    // 0x800D9920: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_0:
    // 0x800D9924: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800D9928: jal         0x80013970
    // 0x800D992C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013970(rdram, ctx);
        goto after_1;
    // 0x800D992C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x800D9930: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800D9934: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D9938: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800D993C: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x800D9940: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800D9944: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800D9948: bc1tl       L_800D9998
    if (c1cs) {
        // 0x800D994C: sub.s       $f2, $f16, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f20.fl;
            goto L_800D9998;
    }
    goto skip_2;
    // 0x800D994C: sub.s       $f2, $f16, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f20.fl;
    skip_2:
    // 0x800D9950: sub.s       $f6, $f16, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f20.fl;
    // 0x800D9954: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800D9958: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800D995C: mul.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800D9960: jal         0x80013970
    // 0x800D9964: nop

    func_80013970(rdram, ctx);
        goto after_2;
    // 0x800D9964: nop

    after_2:
    // 0x800D9968: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800D996C: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800D9970: div.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800D9974: mul.s       $f12, $f20, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x800D9978: jal         0x80013970
    // 0x800D997C: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    func_80013970(rdram, ctx);
        goto after_3;
    // 0x800D997C: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x800D9980: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800D9984: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800D9988: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800D998C: b           L_800D999C
    // 0x800D9990: div.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
        goto L_800D999C;
    // 0x800D9990: div.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800D9994: sub.s       $f2, $f16, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f20.fl;
L_800D9998:
    // 0x800D9998: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
L_800D999C:
    // 0x800D999C: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800D99A0: b           L_800D99B0
    // 0x800D99A4: lwc1        $f14, 0x0($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X0);
        goto L_800D99B0;
    // 0x800D99A4: lwc1        $f14, 0x0($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800D99A8: sub.s       $f2, $f16, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f20.fl;
L_800D99AC:
    // 0x800D99AC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
L_800D99B0:
    // 0x800D99B0: mul.s       $f4, $f14, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800D99B4: nop

    // 0x800D99B8: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800D99BC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800D99C0: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
    // 0x800D99C4: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800D99C8: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800D99CC: mul.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800D99D0: nop

    // 0x800D99D4: mul.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800D99D8: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800D99DC: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
    // 0x800D99E0: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800D99E4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800D99E8: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800D99EC: nop

    // 0x800D99F0: mul.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x800D99F4: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800D99F8: swc1        $f10, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f10.u32l;
    // 0x800D99FC: lwc1        $f8, 0xC($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800D9A00: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800D9A04: mul.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800D9A08: nop

    // 0x800D9A0C: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800D9A10: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800D9A14: b           L_800D9ABC
    // 0x800D9A18: swc1        $f8, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f8.u32l;
        goto L_800D9ABC;
    // 0x800D9A18: swc1        $f8, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f8.u32l;
    // 0x800D9A1C: neg.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
L_800D9A20:
    // 0x800D9A20: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800D9A24: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    // 0x800D9A28: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800D9A2C: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    // 0x800D9A30: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800D9A34: sub.s       $f4, $f16, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f20.fl;
    // 0x800D9A38: neg.s       $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = -ctx->f10.fl;
    // 0x800D9A3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D9A40: swc1        $f8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f8.u32l;
    // 0x800D9A44: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800D9A48: mul.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800D9A4C: jal         0x80013970
    // 0x800D9A50: swc1        $f6, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f6.u32l;
    func_80013970(rdram, ctx);
        goto after_4;
    // 0x800D9A50: swc1        $f6, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f6.u32l;
    after_4:
    // 0x800D9A54: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800D9A58: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D9A5C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800D9A60: mul.s       $f12, $f20, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x800D9A64: jal         0x80013970
    // 0x800D9A68: nop

    func_80013970(rdram, ctx);
        goto after_5;
    // 0x800D9A68: nop

    after_5:
    // 0x800D9A6C: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800D9A70: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800D9A74: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800D9A78: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800D9A7C: nop

    // 0x800D9A80: mul.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800D9A84: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800D9A88: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800D9A8C: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800D9A90: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    // 0x800D9A94: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800D9A98: mul.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x800D9A9C: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800D9AA0: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800D9AA4: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800D9AA8: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x800D9AAC: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800D9AB0: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800D9AB4: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800D9AB8: swc1        $f8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f8.u32l;
L_800D9ABC:
    // 0x800D9ABC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D9AC0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800D9AC4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800D9AC8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800D9ACC: jr          $ra
    // 0x800D9AD0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800D9AD0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void chnests_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F38: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(752, 0X11E8) << 16);
    // 0x80800F3C: jr          $ra
    // 0x80800F40: addiu       $v0, $v0, 0x11E8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X11E8));
    return;
    // 0x80800F40: addiu       $v0, $v0, 0x11E8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X11E8));
;}
RECOMP_FUNC void func_80800330_chdiggerbossshell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800330: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800334: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800338: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8080033C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80800340: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80800344: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80800348: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8080034C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800350: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800354: jal         0x8010CD28
    // 0x80800358: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    func_8010CD28(rdram, ctx);
        goto after_0;
    // 0x80800358: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080035C: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80800360: addiu       $s4, $sp, 0x40
    ctx->r20 = ADD32(ctx->r29, 0X40);
    // 0x80800364: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800368: lwc1        $f4, 0x54($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X54);
    // 0x8080036C: addiu       $a1, $t6, 0x4
    ctx->r5 = ADD32(ctx->r14, 0X4);
    // 0x80800370: jal         0x800EE7F8
    // 0x80800374: add.s       $f20, $f0, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f0.fl + ctx->f4.fl;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800374: add.s       $f20, $f0, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f0.fl + ctx->f4.fl;
    after_1:
    // 0x80800378: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1492, 0X558) << 16);
    // 0x8080037C: lwc1        $f2, 0x558($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1492, 0X558));
    // 0x80800380: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800384: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800388: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080038C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800390: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800394: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800398: bc1fl       L_808003A8
    if (!c1cs) {
        // 0x8080039C: add.s       $f0, $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
            goto L_808003A8;
    }
    goto skip_0;
    // 0x8080039C: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    skip_0:
    // 0x808003A0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x808003A4: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_808003A8:
    // 0x808003A8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808003AC: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x808003B0: addiu       $s2, $sp, 0x58
    ctx->r18 = ADD32(ctx->r29, 0X58);
    // 0x808003B4: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
L_808003B8:
    // 0x808003B8: trunc.w.s   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x808003BC: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    // 0x808003C0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x808003C4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x808003C8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808003CC: jal         0x80108528
    // 0x808003D0: nop

    func_80108528(rdram, ctx);
        goto after_2;
    // 0x808003D0: nop

    after_2:
    // 0x808003D4: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x808003D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808003DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003E0: jal         0x80102FDC
    // 0x808003E4: lw          $a1, 0x38($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X38);
    func_80102FDC(rdram, ctx);
        goto after_3;
    // 0x808003E4: lw          $a1, 0x38($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X38);
    after_3:
    // 0x808003E8: addiu       $a1, $s1, 0x905
    ctx->r5 = ADD32(ctx->r17, 0X905);
    // 0x808003EC: andi        $t9, $a1, 0xFFFF
    ctx->r25 = ctx->r5 & 0XFFFF;
    // 0x808003F0: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F8: jal         0x80103140
    // 0x808003FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80103140(rdram, ctx);
        goto after_4;
    // 0x808003FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80800400: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80800404: add.s       $f12, $f20, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x80800408: lwc1        $f10, 0x24($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X24);
    // 0x8080040C: jal         0x800136E4
    // 0x80800410: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    func_800136E4(rdram, ctx);
        goto after_5;
    // 0x80800410: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    after_5:
    // 0x80800414: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800418: bne         $s1, $s3, L_808003B8
    if (ctx->r17 != ctx->r19) {
        // 0x8080041C: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_808003B8;
    }
    // 0x8080041C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800420: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800424: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x80800428: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8080042C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800430: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800434: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80800438: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8080043C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80800440: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80800444: jr          $ra
    // 0x80800448: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80800448: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void _sumole_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089A08: syscall     800
    recomp_syscall_handler(rdram, ctx, 0x80089A08);
    return;
    // 0x80089A0C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_8080537C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080537C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80805380: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80805384: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x80805388: lui         $t8, 0x8081
    ctx->r24 = S32(RELOC_HI16(804, 0X8424) << 16);
    // 0x8080538C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80805390: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80805394: addiu       $t8, $t8, -0x7BDC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(804, 0X8424));
    // 0x80805398: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080539C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808053A0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808053A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808053A8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808053AC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808053B0: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x808053B4: lbu         $a1, 0x0($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X0);
    // 0x808053B8: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    // 0x808053BC: jal         0x80802D40
    // 0x808053C0: lw          $a0, 0x30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30);
    func_80802D40_chgameselect(rdram, ctx);
        goto after_0;
    // 0x808053C0: lw          $a0, 0x30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30);
    after_0:
    // 0x808053C4: lbu         $t9, 0x0($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X0);
    // 0x808053C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808053CC: blezl       $t9, L_80805438
    if (SIGNED(ctx->r25) <= 0) {
        // 0x808053D0: lw          $a0, 0x30($s2)
        ctx->r4 = MEM_W(ctx->r18, 0X30);
            goto L_80805438;
    }
    goto skip_0;
    // 0x808053D0: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    skip_0:
    // 0x808053D4: lb          $v0, 0x3($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X3);
L_808053D8:
    // 0x808053D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808053DC: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x808053E0: bltz        $v0, L_808053F0
    if (SIGNED(ctx->r2) < 0) {
        // 0x808053E4: addiu       $t0, $zero, -0x1
        ctx->r8 = ADD32(0, -0X1);
            goto L_808053F0;
    }
    // 0x808053E4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x808053E8: b           L_808053F0
    // 0x808053EC: addu        $t0, $v0, $s0
    ctx->r8 = ADD32(ctx->r2, ctx->r16);
        goto L_808053F0;
    // 0x808053EC: addu        $t0, $v0, $s0
    ctx->r8 = ADD32(ctx->r2, ctx->r16);
L_808053F0:
    // 0x808053F0: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x808053F4: addiu       $v1, $zero, 0x9D
    ctx->r3 = ADD32(0, 0X9D);
    // 0x808053F8: beq         $v0, $zero, L_80805408
    if (ctx->r2 == 0) {
        // 0x808053FC: addu        $t1, $v0, $s0
        ctx->r9 = ADD32(ctx->r2, ctx->r16);
            goto L_80805408;
    }
    // 0x808053FC: addu        $t1, $v0, $s0
    ctx->r9 = ADD32(ctx->r2, ctx->r16);
    // 0x80805400: b           L_80805408
    // 0x80805404: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
        goto L_80805408;
    // 0x80805404: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
L_80805408:
    // 0x80805408: lbu         $t2, 0x1($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X1);
    // 0x8080540C: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x80805410: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x80805414: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80805418: jal         0x80802DB4
    // 0x8080541C: addu        $a2, $t2, $s0
    ctx->r6 = ADD32(ctx->r10, ctx->r16);
    func_80802DB4_chgameselect(rdram, ctx);
        goto after_1;
    // 0x8080541C: addu        $a2, $t2, $s0
    ctx->r6 = ADD32(ctx->r10, ctx->r16);
    after_1:
    // 0x80805420: lbu         $t3, 0x0($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X0);
    // 0x80805424: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80805428: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8080542C: bnel        $at, $zero, L_808053D8
    if (ctx->r1 != 0) {
        // 0x80805430: lb          $v0, 0x3($s1)
        ctx->r2 = MEM_B(ctx->r17, 0X3);
            goto L_808053D8;
    }
    goto skip_1;
    // 0x80805430: lb          $v0, 0x3($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X3);
    skip_1:
    // 0x80805434: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
L_80805438:
    // 0x80805438: lh          $a1, 0x4($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X4);
    // 0x8080543C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80805440: jal         0x80802E38
    // 0x80805444: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_80802E38_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80805444: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_2:
    // 0x80805448: lw          $a0, 0x2C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X2C);
    // 0x8080544C: jal         0x808026C8
    // 0x80805450: lbu         $a1, 0x2($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X2);
    func_808026C8_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80805450: lbu         $a1, 0x2($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X2);
    after_3:
    // 0x80805454: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80805458: sw          $t4, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r12;
    // 0x8080545C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80805460: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80805464: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80805468: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080546C: jr          $ra
    // 0x80805470: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80805470: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void badrone_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004F4: lw          $t7, 0x54($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X54);
    // 0x808004F8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x808004FC: jal         0x800846F8
    // 0x80800500: sb          $t6, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r14;
    _badata_entrypoint_23(rdram, ctx);
        goto after_0;
    // 0x80800500: sb          $t6, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r14;
    after_0:
    // 0x80800504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800508: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080050C: jr          $ra
    // 0x80800510: nop

    return;
    // 0x80800510: nop

;}
RECOMP_FUNC void _chfactorydrums_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087430: syscall     571
    recomp_syscall_handler(rdram, ctx, 0x80087430);
    return;
    // 0x80087434: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800C6B78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_voxel_sweep_enter(rdram, ctx);
    // 0x800C6B78: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800C6B7C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800C6B80: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800C6B84: addiu       $s2, $s2, -0x55C0
    ctx->r18 = ADD32(ctx->r18, -0X55C0);
    // 0x800C6B88: lw          $v1, 0x80($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X80);
    // 0x800C6B8C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C6B90: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800C6B94: addiu       $t6, $t6, -0x55BF
    ctx->r14 = ADD32(ctx->r14, -0X55BF);
    // 0x800C6B98: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800C6B9C: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800C6BA0: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800C6BA4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800C6BA8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800C6BAC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800C6BB0: sltu        $at, $v1, $t6
    ctx->r1 = ctx->r3 < ctx->r14 ? 1 : 0;
    // 0x800C6BB4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800C6BB8: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800C6BBC: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x800C6BC0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800C6BC4: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800C6BC8: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800C6BCC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800C6BD0: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x800C6BD4: sw          $zero, 0x84($s2)
    MEM_W(0X84, ctx->r18) = 0;
    // 0x800C6BD8: bne         $at, $zero, L_800C6C5C
    if (ctx->r1 != 0) {
        // 0x800C6BDC: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_800C6C5C;
    }
    // 0x800C6BDC: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x800C6BE0: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x800C6BE4: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800C6BE8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
L_800C6BEC:
    // 0x800C6BEC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C6BF0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800C6BF4: beq         $v0, $zero, L_800C6C4C
    if (ctx->r2 == 0) {
        // 0x800C6BF8: or          $a3, $s5, $zero
        ctx->r7 = ctx->r21 | 0;
            goto L_800C6C4C;
    }
    // 0x800C6BF8: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x800C6BFC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800C6C00: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // 0x800C6C04: jalr        $v0
    // 0x800C6C08: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800C6C08: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    after_0:
    tooie_voxel_sweep_provider(rdram, ctx);
    // 0x800C6C0C: beq         $v0, $zero, L_800C6C34
    if (ctx->r2 == 0) {
        // 0x800C6C10: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800C6C34;
    }
    // 0x800C6C10: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800C6C14: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x800C6C18: beql        $v0, $zero, L_800C6C34
    if (ctx->r2 == 0) {
        // 0x800C6C1C: sw          $zero, 0x84($s2)
        MEM_W(0X84, ctx->r18) = 0;
            goto L_800C6C34;
    }
    goto skip_0;
    // 0x800C6C1C: sw          $zero, 0x84($s2)
    MEM_W(0X84, ctx->r18) = 0;
    skip_0:
    // 0x800C6C20: jalr        $v0
    // 0x800C6C24: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x800C6C24: nop

    after_1:
    // 0x800C6C28: b           L_800C6C34
    // 0x800C6C2C: sw          $v0, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r2;
        goto L_800C6C34;
    // 0x800C6C2C: sw          $v0, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r2;
    // 0x800C6C30: sw          $zero, 0x84($s2)
    MEM_W(0X84, ctx->r18) = 0;
L_800C6C34:
    // 0x800C6C34: beql        $s1, $zero, L_800C6C4C
    if (ctx->r17 == 0) {
        // 0x800C6C38: lw          $v1, 0x80($s2)
        ctx->r3 = MEM_W(ctx->r18, 0X80);
            goto L_800C6C4C;
    }
    goto skip_1;
    // 0x800C6C38: lw          $v1, 0x80($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X80);
    skip_1:
    // 0x800C6C3C: or          $fp, $s1, $zero
    ctx->r30 = ctx->r17 | 0;
    // 0x800C6C40: b           L_800C6C4C
    // 0x800C6C44: lw          $v1, 0x80($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X80);
        goto L_800C6C4C;
    // 0x800C6C44: lw          $v1, 0x80($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X80);
    // 0x800C6C48: lw          $v1, 0x80($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X80);
L_800C6C4C:
    // 0x800C6C4C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800C6C50: sltu        $at, $s0, $v1
    ctx->r1 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x800C6C54: bnel        $at, $zero, L_800C6BEC
    if (ctx->r1 != 0) {
        // 0x800C6C58: lw          $v0, 0x4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X4);
            goto L_800C6BEC;
    }
    goto skip_2;
    // 0x800C6C58: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    skip_2:
L_800C6C5C:
    // 0x800C6C5C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    tooie_voxel_sweep_exit(rdram, ctx);
    // 0x800C6C60: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
    // 0x800C6C64: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800C6C68: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800C6C6C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800C6C70: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800C6C74: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800C6C78: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800C6C7C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800C6C80: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800C6C84: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800C6C88: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800C6C8C: jr          $ra
    // 0x800C6C90: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800C6C90: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _gsattract_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C80: syscall     731
    recomp_syscall_handler(rdram, ctx, 0x80088C80);
    return;
    // 0x80088C84: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void chboggyboy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1532, 0XCB8) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xCB8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1532, 0XCB8));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xCB8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1532, 0XCB8));
;}
RECOMP_FUNC void func_800C5778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5778: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C577C: addiu       $v1, $v1, -0x55E0
    ctx->r3 = ADD32(ctx->r3, -0X55E0);
    // 0x800C5780: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800C5784: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C5788: sb          $zero, 0x11($v1)
    MEM_B(0X11, ctx->r3) = 0;
    // 0x800C578C: sb          $v0, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r2;
    // 0x800C5790: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x800C5794: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800C5798: sb          $v0, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r2;
    // 0x800C579C: sb          $v0, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r2;
    // 0x800C57A0: sb          $v0, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r2;
    // 0x800C57A4: sb          $v0, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r2;
    // 0x800C57A8: sb          $v0, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r2;
    // 0x800C57AC: sb          $v0, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r2;
    // 0x800C57B0: sb          $v0, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r2;
    // 0x800C57B4: sb          $v0, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r2;
    // 0x800C57B8: jr          $ra
    // 0x800C57BC: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    return;
    // 0x800C57BC: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_80800038_bsrebound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800038: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080003C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800040: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800044: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800048: jal         0x8008CABC
    // 0x8080004C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080004C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800050: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800054: jal         0x800845C8
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babounce_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080005C: beq         $v0, $zero, L_8080006C
    if (ctx->r2 == 0) {
        // 0x80800060: nop
    
            goto L_8080006C;
    }
    // 0x80800060: nop

    // 0x80800064: jal         0x800841D8
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bswalk_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_8080006C:
    // 0x8080006C: jal         0x80084600
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babounce_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800074: beq         $v0, $zero, L_80800080
    if (ctx->r2 == 0) {
        // 0x80800078: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800080;
    }
    // 0x80800078: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080007C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800080:
    // 0x80800080: jal         0x800845C0
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babounce_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800088: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080008C: bnel        $v0, $at, L_808000D0
    if (ctx->r2 != ctx->r1) {
        // 0x80800090: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000D0;
    }
    goto skip_0;
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800094: jal         0x8008E260
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E260(rdram, ctx);
        goto after_5;
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080009C: beq         $v0, $zero, L_808000A8
    if (ctx->r2 == 0) {
        // 0x808000A0: addiu       $t7, $zero, 0x3D
        ctx->r15 = ADD32(0, 0X3D);
            goto L_808000A8;
    }
    // 0x808000A0: addiu       $t7, $zero, 0x3D
    ctx->r15 = ADD32(0, 0X3D);
    // 0x808000A4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_808000A8:
    // 0x808000A8: jal         0x8008B324
    // 0x808000AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_6;
    // 0x808000AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x808000B0: beql        $v0, $zero, L_808000D0
    if (ctx->r2 == 0) {
        // 0x808000B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000D0;
    }
    goto skip_1;
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808000B8: jal         0x8008DD04
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_7;
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808000C0: beq         $v0, $zero, L_808000CC
    if (ctx->r2 == 0) {
        // 0x808000C4: addiu       $t8, $zero, 0x2F
        ctx->r24 = ADD32(0, 0X2F);
            goto L_808000CC;
    }
    // 0x808000C4: addiu       $t8, $zero, 0x2F
    ctx->r24 = ADD32(0, 0X2F);
    // 0x808000C8: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_808000CC:
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000D0:
    // 0x808000D0: jal         0x8009E5C8
    // 0x808000D4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_8;
    // 0x808000D4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x808000D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000E4: jr          $ra
    // 0x808000E8: nop

    return;
    // 0x808000E8: nop

;}
RECOMP_FUNC void func_80801128_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801128: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080112C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801130: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801134: jal         0x800CEA60
    // 0x80801138: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEA60(rdram, ctx);
        goto after_0;
    // 0x80801138: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8080113C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80801140: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801144: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80801148: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8080114C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80801150: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2204, 0X24A0) << 16);
    // 0x80801154: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80801158: lui         $a3, 0x3FB3
    ctx->r7 = S32(0X3FB3 << 16);
    // 0x8080115C: bc1f        L_808011A8
    if (!c1cs) {
        // 0x80801160: nop
    
            goto L_808011A8;
    }
    // 0x80801160: nop

    // 0x80801164: lhu         $t7, 0x76($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X76);
    // 0x80801168: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8080116C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80801170: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x80801174: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80801178: bgez        $t8, L_8080118C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8080117C: cvt.s.w     $f14, $f4
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8080118C;
    }
    // 0x8080117C: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801180: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801184: nop

    // 0x80801188: add.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f6.fl;
L_8080118C:
    // 0x8080118C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2204, 0X249C) << 16);
    // 0x80801190: lwc1        $f8, 0x249C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2204, 0X249C));
    // 0x80801194: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80801198: jal         0x800F10B4
    // 0x8080119C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x8080119C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x808011A0: b           L_808011BC
    // 0x808011A4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_808011BC;
    // 0x808011A4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_808011A8:
    // 0x808011A8: lwc1        $f10, 0x24A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2204, 0X24A0));
    // 0x808011AC: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x808011B0: jal         0x800F10B4
    // 0x808011B4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x808011B4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x808011B8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_808011BC:
    // 0x808011BC: jal         0x800FE820
    // 0x808011C0: nop

    func_800FE820(rdram, ctx);
        goto after_3;
    // 0x808011C0: nop

    after_3:
    // 0x808011C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808011C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808011CC: jr          $ra
    // 0x808011D0: nop

    return;
    // 0x808011D0: nop

;}
RECOMP_FUNC void func_80800F70_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F70: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800F74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800F78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800F7C: jal         0x8008CABC
    // 0x80800F80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800F80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800F84: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800F88: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80800F8C: jal         0x808004A8
    // 0x80800F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004A8_bsledge(rdram, ctx);
        goto after_1;
    // 0x80800F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800F94: jal         0x808004D8
    // 0x80800F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004D8_bsledge(rdram, ctx);
        goto after_2;
    // 0x80800F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800F9C: lw          $v0, 0x160($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X160);
    // 0x80800FA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800FA4: beq         $v0, $at, L_80800FD0
    if (ctx->r2 == ctx->r1) {
        // 0x80800FA8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800FD0;
    }
    // 0x80800FA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800FAC: beq         $v0, $at, L_80800FFC
    if (ctx->r2 == ctx->r1) {
        // 0x80800FB0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800FFC;
    }
    // 0x80800FB0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800FB4: beq         $v0, $at, L_80801028
    if (ctx->r2 == ctx->r1) {
        // 0x80800FB8: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80801028;
    }
    // 0x80800FB8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800FBC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800FC0: beq         $v0, $at, L_80801190
    if (ctx->r2 == ctx->r1) {
        // 0x80800FC4: nop
    
            goto L_80801190;
    }
    // 0x80800FC4: nop

    // 0x80800FC8: b           L_808011B4
    // 0x80800FCC: nop

        goto L_808011B4;
    // 0x80800FCC: nop

L_80800FD0:
    // 0x80800FD0: jal         0x8008B324
    // 0x80800FD4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isStopped(rdram, ctx);
        goto after_3;
    // 0x80800FD4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80800FD8: beq         $v0, $zero, L_808011B4
    if (ctx->r2 == 0) {
        // 0x80800FDC: nop
    
            goto L_808011B4;
    }
    // 0x80800FDC: nop

    // 0x80800FE0: jal         0x80800D24
    // 0x80800FE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800D24_bsledge(rdram, ctx);
        goto after_4;
    // 0x80800FE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FEC: jal         0x80800D78
    // 0x80800FF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800D78_bsledge(rdram, ctx);
        goto after_5;
    // 0x80800FF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x80800FF4: b           L_808011B4
    // 0x80800FF8: nop

        goto L_808011B4;
    // 0x80800FF8: nop

L_80800FFC:
    // 0x80800FFC: jal         0x8008B324
    // 0x80801000: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isStopped(rdram, ctx);
        goto after_6;
    // 0x80801000: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x80801004: beq         $v0, $zero, L_808011B4
    if (ctx->r2 == 0) {
        // 0x80801008: nop
    
            goto L_808011B4;
    }
    // 0x80801008: nop

    // 0x8080100C: jal         0x80800D24
    // 0x80801010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800D24_bsledge(rdram, ctx);
        goto after_7;
    // 0x80801010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801018: jal         0x80800D78
    // 0x8080101C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800D78_bsledge(rdram, ctx);
        goto after_8;
    // 0x8080101C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x80801020: b           L_808011B4
    // 0x80801024: nop

        goto L_808011B4;
    // 0x80801024: nop

L_80801028:
    // 0x80801028: lui         $a1, 0x3BE5
    ctx->r5 = S32(0X3BE5 << 16);
    // 0x8080102C: jal         0x8008B348
    // 0x80801030: ori         $a1, $a1, 0x6042
    ctx->r5 = ctx->r5 | 0X6042;
    anctrl_isAt(rdram, ctx);
        goto after_9;
    // 0x80801030: ori         $a1, $a1, 0x6042
    ctx->r5 = ctx->r5 | 0X6042;
    after_9:
    // 0x80801034: beql        $v0, $zero, L_80801048
    if (ctx->r2 == 0) {
        // 0x80801038: lui         $a1, 0x3E4B
        ctx->r5 = S32(0X3E4B << 16);
            goto L_80801048;
    }
    goto skip_0;
    // 0x80801038: lui         $a1, 0x3E4B
    ctx->r5 = S32(0X3E4B << 16);
    skip_0:
    // 0x8080103C: jal         0x8009D874
    // 0x80801040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D874(rdram, ctx);
        goto after_10;
    // 0x80801040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80801044: lui         $a1, 0x3E4B
    ctx->r5 = S32(0X3E4B << 16);
L_80801048:
    // 0x80801048: ori         $a1, $a1, 0xF28
    ctx->r5 = ctx->r5 | 0XF28;
    // 0x8080104C: jal         0x8008B348
    // 0x80801050: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_11;
    // 0x80801050: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_11:
    // 0x80801054: bne         $v0, $zero, L_8080106C
    if (ctx->r2 != 0) {
        // 0x80801058: lui         $a1, 0x3E6B
        ctx->r5 = S32(0X3E6B << 16);
            goto L_8080106C;
    }
    // 0x80801058: lui         $a1, 0x3E6B
    ctx->r5 = S32(0X3E6B << 16);
    // 0x8080105C: ori         $a1, $a1, 0xB98C
    ctx->r5 = ctx->r5 | 0XB98C;
    // 0x80801060: jal         0x8008B348
    // 0x80801064: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_12;
    // 0x80801064: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_12:
    // 0x80801068: beq         $v0, $zero, L_8080109C
    if (ctx->r2 == 0) {
        // 0x8080106C: lui         $a2, 0x3FE6
        ctx->r6 = S32(0X3FE6 << 16);
            goto L_8080109C;
    }
L_8080106C:
    // 0x8080106C: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x80801070: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80801074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801078: addiu       $a1, $zero, 0x418
    ctx->r5 = ADD32(0, 0X418);
    // 0x8080107C: jal         0x8009DF94
    // 0x80801080: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    func_8009DF94(rdram, ctx);
        goto after_13;
    // 0x80801080: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    after_13:
    // 0x80801084: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x80801088: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8080108C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801090: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80801094: jal         0x80085490
    // 0x80801098: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    _bamotor_entrypoint_1(rdram, ctx);
        goto after_14;
    // 0x80801098: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_14:
L_8080109C:
    // 0x8080109C: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    // 0x808010A0: ori         $a1, $a1, 0x1A37
    ctx->r5 = ctx->r5 | 0X1A37;
    // 0x808010A4: jal         0x8008B348
    // 0x808010A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_15;
    // 0x808010A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_15:
    // 0x808010AC: beq         $v0, $zero, L_808010C4
    if (ctx->r2 == 0) {
        // 0x808010B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808010C4;
    }
    // 0x808010B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010B4: addiu       $a1, $zero, 0x445
    ctx->r5 = ADD32(0, 0X445);
    // 0x808010B8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808010BC: jal         0x8009DF94
    // 0x808010C0: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    func_8009DF94(rdram, ctx);
        goto after_16;
    // 0x808010C0: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    after_16:
L_808010C4:
    // 0x808010C4: lui         $a1, 0x3EC0
    ctx->r5 = S32(0X3EC0 << 16);
    // 0x808010C8: ori         $a1, $a1, 0x8312
    ctx->r5 = ctx->r5 | 0X8312;
    // 0x808010CC: jal         0x8008B348
    // 0x808010D0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_17;
    // 0x808010D0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_17:
    // 0x808010D4: beq         $v0, $zero, L_808010EC
    if (ctx->r2 == 0) {
        // 0x808010D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808010EC;
    }
    // 0x808010D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010DC: lui         $a2, 0x3FCC
    ctx->r6 = S32(0X3FCC << 16);
    // 0x808010E0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808010E4: jal         0x8009DF58
    // 0x808010E8: addiu       $a1, $zero, 0x43EF
    ctx->r5 = ADD32(0, 0X43EF);
    func_8009DF58(rdram, ctx);
        goto after_18;
    // 0x808010E8: addiu       $a1, $zero, 0x43EF
    ctx->r5 = ADD32(0, 0X43EF);
    after_18:
L_808010EC:
    // 0x808010EC: lui         $a1, 0x3ED1
    ctx->r5 = S32(0X3ED1 << 16);
    // 0x808010F0: ori         $a1, $a1, 0xA9FC
    ctx->r5 = ctx->r5 | 0XA9FC;
    // 0x808010F4: jal         0x8008B348
    // 0x808010F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_19;
    // 0x808010F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_19:
    // 0x808010FC: beq         $v0, $zero, L_80801114
    if (ctx->r2 == 0) {
        // 0x80801100: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801114;
    }
    // 0x80801100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801104: lui         $a2, 0x3FB9
    ctx->r6 = S32(0X3FB9 << 16);
    // 0x80801108: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8080110C: jal         0x8009DF58
    // 0x80801110: addiu       $a1, $zero, 0x43EF
    ctx->r5 = ADD32(0, 0X43EF);
    func_8009DF58(rdram, ctx);
        goto after_20;
    // 0x80801110: addiu       $a1, $zero, 0x43EF
    ctx->r5 = ADD32(0, 0X43EF);
    after_20:
L_80801114:
    // 0x80801114: lui         $a1, 0x3EE6
    ctx->r5 = S32(0X3EE6 << 16);
    // 0x80801118: ori         $a1, $a1, 0x24DD
    ctx->r5 = ctx->r5 | 0X24DD;
    // 0x8080111C: jal         0x8008B348
    // 0x80801120: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_21;
    // 0x80801120: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_21:
    // 0x80801124: beq         $v0, $zero, L_8080113C
    if (ctx->r2 == 0) {
        // 0x80801128: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080113C;
    }
    // 0x80801128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080112C: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x80801130: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80801134: jal         0x8009DF58
    // 0x80801138: addiu       $a1, $zero, 0x43EF
    ctx->r5 = ADD32(0, 0X43EF);
    func_8009DF58(rdram, ctx);
        goto after_22;
    // 0x80801138: addiu       $a1, $zero, 0x43EF
    ctx->r5 = ADD32(0, 0X43EF);
    after_22:
L_8080113C:
    // 0x8080113C: lui         $a1, 0x3F0A
    ctx->r5 = S32(0X3F0A << 16);
    // 0x80801140: ori         $a1, $a1, 0x1CAC
    ctx->r5 = ctx->r5 | 0X1CAC;
    // 0x80801144: jal         0x8008B348
    // 0x80801148: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_23;
    // 0x80801148: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_23:
    // 0x8080114C: beq         $v0, $zero, L_80801164
    if (ctx->r2 == 0) {
        // 0x80801150: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801164;
    }
    // 0x80801150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801154: addiu       $a1, $zero, 0x449
    ctx->r5 = ADD32(0, 0X449);
    // 0x80801158: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080115C: jal         0x8009DF94
    // 0x80801160: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    func_8009DF94(rdram, ctx);
        goto after_24;
    // 0x80801160: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    after_24:
L_80801164:
    // 0x80801164: jal         0x8008B324
    // 0x80801168: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isStopped(rdram, ctx);
        goto after_25;
    // 0x80801168: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_25:
    // 0x8080116C: beq         $v0, $zero, L_808011B4
    if (ctx->r2 == 0) {
        // 0x80801170: nop
    
            goto L_808011B4;
    }
    // 0x80801170: nop

    // 0x80801174: jal         0x80800D24
    // 0x80801178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800D24_bsledge(rdram, ctx);
        goto after_26;
    // 0x80801178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x8080117C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801180: jal         0x80800D78
    // 0x80801184: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800D78_bsledge(rdram, ctx);
        goto after_27;
    // 0x80801184: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_27:
    // 0x80801188: b           L_808011B4
    // 0x8080118C: nop

        goto L_808011B4;
    // 0x8080118C: nop

L_80801190:
    // 0x80801190: jal         0x8008B324
    // 0x80801194: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isStopped(rdram, ctx);
        goto after_28;
    // 0x80801194: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_28:
    // 0x80801198: beq         $v0, $zero, L_808011B4
    if (ctx->r2 == 0) {
        // 0x8080119C: nop
    
            goto L_808011B4;
    }
    // 0x8080119C: nop

    // 0x808011A0: jal         0x80800D24
    // 0x808011A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800D24_bsledge(rdram, ctx);
        goto after_29;
    // 0x808011A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x808011A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011AC: jal         0x80800D78
    // 0x808011B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800D78_bsledge(rdram, ctx);
        goto after_30;
    // 0x808011B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_30:
L_808011B4:
    // 0x808011B4: jal         0x80800450
    // 0x808011B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800450_bsledge(rdram, ctx);
        goto after_31;
    // 0x808011B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x808011BC: beq         $v0, $zero, L_808011C8
    if (ctx->r2 == 0) {
        // 0x808011C0: addiu       $t6, $zero, 0xA7
        ctx->r14 = ADD32(0, 0XA7);
            goto L_808011C8;
    }
    // 0x808011C0: addiu       $t6, $zero, 0xA7
    ctx->r14 = ADD32(0, 0XA7);
    // 0x808011C4: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
L_808011C8:
    // 0x808011C8: jal         0x808003D0
    // 0x808011CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003D0_bsledge(rdram, ctx);
        goto after_32;
    // 0x808011CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x808011D0: beq         $v0, $zero, L_808011DC
    if (ctx->r2 == 0) {
        // 0x808011D4: addiu       $t7, $zero, 0xAA
        ctx->r15 = ADD32(0, 0XAA);
            goto L_808011DC;
    }
    // 0x808011D4: addiu       $t7, $zero, 0xAA
    ctx->r15 = ADD32(0, 0XAA);
    // 0x808011D8: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_808011DC:
    // 0x808011DC: jal         0x80800000
    // 0x808011E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsledge(rdram, ctx);
        goto after_33;
    // 0x808011E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x808011E4: beq         $v0, $zero, L_808011F4
    if (ctx->r2 == 0) {
        // 0x808011E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808011F4;
    }
    // 0x808011E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011EC: addiu       $t8, $zero, 0xA9
    ctx->r24 = ADD32(0, 0XA9);
    // 0x808011F0: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_808011F4:
    // 0x808011F4: jal         0x80091A58
    // 0x808011F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_pressed(rdram, ctx);
        goto after_34;
    // 0x808011F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_34:
    // 0x808011FC: beq         $v0, $zero, L_80801208
    if (ctx->r2 == 0) {
        // 0x80801200: addiu       $t9, $zero, 0x2F
        ctx->r25 = ADD32(0, 0X2F);
            goto L_80801208;
    }
    // 0x80801200: addiu       $t9, $zero, 0x2F
    ctx->r25 = ADD32(0, 0X2F);
    // 0x80801204: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
L_80801208:
    // 0x80801208: jal         0x80800410
    // 0x8080120C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800410_bsledge(rdram, ctx);
        goto after_35;
    // 0x8080120C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x80801210: bne         $v0, $zero, L_80801220
    if (ctx->r2 != 0) {
        // 0x80801214: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801220;
    }
    // 0x80801214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801218: addiu       $t0, $zero, 0x2F
    ctx->r8 = ADD32(0, 0X2F);
    // 0x8080121C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
L_80801220:
    // 0x80801220: jal         0x8009E5C8
    // 0x80801224: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_36;
    // 0x80801224: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_36:
    // 0x80801228: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080122C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801230: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801234: jr          $ra
    // 0x80801238: nop

    return;
    // 0x80801238: nop

;}
RECOMP_FUNC void func_80800144_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800144: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800148: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080014C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800150: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800154: jal         0x80100094
    // 0x80800158: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800158: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080015C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800160: jal         0x80089B20
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sukickball_entrypoint_17(rdram, ctx);
        goto after_1;
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800168: jal         0x800DA298
    // 0x8080016C: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x8080016C: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    after_2:
    // 0x80800170: bnel        $v0, $zero, L_80800200
    if (ctx->r2 != 0) {
        // 0x80800174: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800200;
    }
    goto skip_0;
    // 0x80800174: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800178: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
    // 0x8080017C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800180: srl         $t6, $v0, 4
    ctx->r14 = S32(U32(ctx->r2) >> 4);
    // 0x80800184: beql        $t6, $at, L_80800200
    if (ctx->r14 == ctx->r1) {
        // 0x80800188: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800200;
    }
    goto skip_1;
    // 0x80800188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8080018C: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x80800190: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800194: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x80800198: bltzl       $t9, L_80800200
    if (SIGNED(ctx->r25) < 0) {
        // 0x8080019C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800200;
    }
    goto skip_2;
    // 0x8080019C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x808001A0: bnel        $t6, $at, L_808001B4
    if (ctx->r14 != ctx->r1) {
        // 0x808001A4: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_808001B4;
    }
    goto skip_3;
    // 0x808001A4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x808001A8: jal         0x80085710
    // 0x808001AC: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_3;
    // 0x808001AC: nop

    after_3:
    // 0x808001B0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
L_808001B4:
    // 0x808001B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001B8: lbu         $v0, 0x39($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X39);
    // 0x808001BC: beq         $v0, $zero, L_808001D4
    if (ctx->r2 == 0) {
        // 0x808001C0: nop
    
            goto L_808001D4;
    }
    // 0x808001C0: nop

    // 0x808001C4: beq         $v0, $at, L_808001D4
    if (ctx->r2 == ctx->r1) {
        // 0x808001C8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808001D4;
    }
    // 0x808001C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808001CC: bnel        $v0, $at, L_808001E0
    if (ctx->r2 != ctx->r1) {
        // 0x808001D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001E0;
    }
    goto skip_4;
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
L_808001D4:
    // 0x808001D4: jal         0x800A54F8
    // 0x808001D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A54F8(rdram, ctx);
        goto after_4;
    // 0x808001D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001E0:
    // 0x808001E0: addiu       $a1, $zero, 0xF1C
    ctx->r5 = ADD32(0, 0XF1C);
    // 0x808001E4: jal         0x80800000
    // 0x808001E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800000_chstoneballcontrol(rdram, ctx);
        goto after_5;
    // 0x808001E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x808001EC: lbu         $t1, 0x72($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X72);
    // 0x808001F0: andi        $t2, $t1, 0xFF03
    ctx->r10 = ctx->r9 & 0XFF03;
    // 0x808001F4: ori         $t3, $t2, 0xC
    ctx->r11 = ctx->r10 | 0XC;
    // 0x808001F8: sb          $t3, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r11;
    // 0x808001FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800200:
    // 0x80800200: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800204: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800208: jr          $ra
    // 0x8080020C: nop

    return;
    // 0x8080020C: nop

;}
RECOMP_FUNC void func_8080232C_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080232C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80802330: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80802334: addiu       $s0, $sp, 0x2C
    ctx->r16 = ADD32(ctx->r29, 0X2C);
    // 0x80802338: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080233C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80802340: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80802344: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802348: jal         0x8008A0D0
    // 0x8080234C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080234C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_0:
    // 0x80802350: beq         $v0, $zero, L_80802394
    if (ctx->r2 == 0) {
        // 0x80802354: addiu       $a0, $s1, 0x4
        ctx->r4 = ADD32(ctx->r17, 0X4);
            goto L_80802394;
    }
    // 0x80802354: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x80802358: jal         0x800F1DF4
    // 0x8080235C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800F1DF4(rdram, ctx);
        goto after_1;
    // 0x8080235C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80802360: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80802364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802368: jal         0x800EF1B8
    // 0x8080236C: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_2;
    // 0x8080236C: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    after_2:
    // 0x80802370: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80802374: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80802378: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080237C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802380: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x80802384: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    // 0x80802388: lui         $a3, 0x437A
    ctx->r7 = S32(0X437A << 16);
    // 0x8080238C: jal         0x80089F20
    // 0x80802390: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80802390: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_3:
L_80802394:
    // 0x80802394: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802398: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8080239C: jal         0x8008A0D0
    // 0x808023A0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x808023A0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x808023A4: beq         $v0, $zero, L_808023E8
    if (ctx->r2 == 0) {
        // 0x808023A8: addiu       $a0, $s1, 0x4
        ctx->r4 = ADD32(ctx->r17, 0X4);
            goto L_808023E8;
    }
    // 0x808023A8: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x808023AC: jal         0x800F1DF4
    // 0x808023B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800F1DF4(rdram, ctx);
        goto after_5;
    // 0x808023B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x808023B4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808023B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808023BC: jal         0x800EF1B8
    // 0x808023C0: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_6;
    // 0x808023C0: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    after_6:
    // 0x808023C4: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x808023C8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x808023CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808023D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808023D4: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x808023D8: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    // 0x808023DC: lui         $a3, 0x437A
    ctx->r7 = S32(0X437A << 16);
    // 0x808023E0: jal         0x80089F20
    // 0x808023E4: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x808023E4: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    after_7:
L_808023E8:
    // 0x808023E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808023EC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808023F0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808023F4: jr          $ra
    // 0x808023F8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808023F8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808023FC: nop

;}
RECOMP_FUNC void batimer_isZero(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A8: lw          $t6, 0x13C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X13C);
    // 0x808002AC: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x808002B0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808002B4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x808002B8: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x808002BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808002C0: c.eq.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl == ctx->f4.fl;
    // 0x808002C4: nop

    // 0x808002C8: bc1f        L_808002D4
    if (!c1cs) {
        // 0x808002CC: nop
    
            goto L_808002D4;
    }
    // 0x808002CC: nop

    // 0x808002D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002D4:
    // 0x808002D4: jr          $ra
    // 0x808002D8: nop

    return;
    // 0x808002D8: nop

;}
RECOMP_FUNC void _idwater_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088E48: syscall     744
    recomp_syscall_handler(rdram, ctx, 0x80088E48);
    return;
    // 0x80088E4C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void subaddieaudioquick_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080012C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800130: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800134: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800138: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8080013C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800140: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800144: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800148: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8080014C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800150: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80800154: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80800158: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080015C: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x80800160: nop

    // 0x80800164: bc1tl       L_808001B0
    if (c1cs) {
        // 0x80800168: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808001B0;
    }
    goto skip_0;
    // 0x80800168: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8080016C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_80800170:
    // 0x80800170: jal         0x80101E14
    // 0x80800174: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80101E14(rdram, ctx);
        goto after_0;
    // 0x80800174: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80800178: beq         $v0, $zero, L_80800194
    if (ctx->r2 == 0) {
        // 0x8080017C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800194;
    }
    // 0x8080017C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800180: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800184: jal         0x8080009C
    // 0x80800188: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800188: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8080018C: b           L_808001B0
    // 0x80800190: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001B0;
    // 0x80800190: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800194:
    // 0x80800194: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800198: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8080019C: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x808001A0: nop

    // 0x808001A4: bc1fl       L_80800170
    if (!c1cs) {
        // 0x808001A8: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_80800170;
    }
    goto skip_1;
    // 0x808001A8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_1:
    // 0x808001AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001B0:
    // 0x808001B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808001B4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808001B8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808001BC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808001C0: jr          $ra
    // 0x808001C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808001C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001C8: nop

    // 0x808001CC: nop

;}
RECOMP_FUNC void func_808000B8_chtorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808000BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000C0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808000C4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808000C8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x808000CC: jal         0x80100094
    // 0x808000D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000D4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x808000D8: lw          $t6, 0x28($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X28);
    // 0x808000DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808000E0: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x808000E4: bne         $t6, $zero, L_808001CC
    if (ctx->r14 != 0) {
        // 0x808000E8: lw          $s1, 0x48($sp)
        ctx->r17 = MEM_W(ctx->r29, 0X48);
            goto L_808001CC;
    }
    // 0x808000E8: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x808000EC: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x808000F0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x808000F4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x808000F8: jal         0x800E1610
    // 0x808000FC: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    func_800E1610(rdram, ctx);
        goto after_1;
    // 0x808000FC: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    after_1:
    // 0x80800100: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80800104: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x80800110: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800114: jal         0x800EFA98
    // 0x80800118: lui         $a2, 0xC28C
    ctx->r6 = S32(0XC28C << 16);
    func_800EFA98(rdram, ctx);
        goto after_2;
    // 0x80800118: lui         $a2, 0xC28C
    ctx->r6 = S32(0XC28C << 16);
    after_2:
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800120: jal         0x800EF04C
    // 0x80800124: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x80800124: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80800128: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2160, 0X8B4) << 16);
    // 0x8080012C: addiu       $t7, $t7, 0x8B4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2160, 0X8B4));
    // 0x80800130: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800134: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800138: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080013C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800140: jal         0x800BABB8
    // 0x80800144: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x80800144: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800150: jal         0x800EFA98
    // 0x80800154: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    func_800EFA98(rdram, ctx);
        goto after_5;
    // 0x80800154: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    after_5:
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: jal         0x800EF04C
    // 0x80800160: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EF04C(rdram, ctx);
        goto after_6;
    // 0x80800160: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x80800164: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80800168: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8080016C: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800170: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80800174: lwc1        $f6, 0x24($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X24);
    // 0x80800178: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8080017C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800180: nop

    // 0x80800184: bc1fl       L_808001D0
    if (!c1cs) {
        // 0x80800188: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808001D0;
    }
    goto skip_0;
    // 0x80800188: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080018C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800194: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800198: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8080019C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808001A0: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x808001A4: jal         0x800889D0
    // 0x808001A8: nop

    _fxairbub_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x808001A8: nop

    after_7:
    // 0x808001AC: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2160, 0X840) << 16);
    // 0x808001B0: addiu       $t0, $t0, 0x840
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2160, 0X840));
    // 0x808001B4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808001B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808001C0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808001C4: jal         0x800BABB8
    // 0x808001C8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_8;
    // 0x808001C8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_8:
L_808001CC:
    // 0x808001CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001D0:
    // 0x808001D0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808001D4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808001D8: jr          $ra
    // 0x808001DC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x808001DC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800F711C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F711C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F7120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F7124: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F7128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F712C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F7130: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F7134: jal         0x8009E674
    // 0x800F7138: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_8009E674(rdram, ctx);
        goto after_0;
    // 0x800F7138: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x800F713C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F7140: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800F7144: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800F7148: jr          $ra
    // 0x800F714C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F714C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void chjiggygamenew_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802C10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802C14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802C18: jal         0x80014F00
    // 0x80802C1C: nop

    func_80014F00(rdram, ctx);
        goto after_0;
    // 0x80802C1C: nop

    after_0:
    // 0x80802C20: jal         0x800886D8
    // 0x80802C24: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _glglobalsettings_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80802C24: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80802C28: beq         $v0, $zero, L_80802D60
    if (ctx->r2 == 0) {
        // 0x80802C2C: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_80802D60;
    }
    // 0x80802C2C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80802C30: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(772, 0X3DF9) << 16);
    // 0x80802C34: lbu         $t6, 0x3DF9($t6)
    ctx->r14 = MEM_BU(ctx->r14, (int16_t)RELOC_LO16(772, 0X3DF9));
    // 0x80802C38: addiu       $a1, $zero, 0x130
    ctx->r5 = ADD32(0, 0X130);
    // 0x80802C3C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(772, 0X3DF8) << 16);
    // 0x80802C40: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80802C44: lbu         $t8, 0x3DF8($t8)
    ctx->r24 = MEM_BU(ctx->r24, (int16_t)RELOC_LO16(772, 0X3DF8));
    // 0x80802C48: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(772, 0X3DFB) << 16);
    // 0x80802C4C: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(772, 0X3DFA) << 16);
    // 0x80802C50: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(772, 0X3DFD) << 16);
    // 0x80802C54: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80802C58: mflo        $t7
    ctx->r15 = lo;
    // 0x80802C5C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80802C60: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x80802C64: addu        $v1, $a2, $t9
    ctx->r3 = ADD32(ctx->r6, ctx->r25);
    // 0x80802C68: lhu         $t0, -0x2($v1)
    ctx->r8 = MEM_HU(ctx->r3, -0X2);
    // 0x80802C6C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(772, 0X3DFC) << 16);
    // 0x80802C70: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
    // 0x80802C74: lbu         $t1, 0x3DFB($t1)
    ctx->r9 = MEM_BU(ctx->r9, (int16_t)RELOC_LO16(772, 0X3DFB));
    // 0x80802C78: lbu         $t3, 0x3DFA($t3)
    ctx->r11 = MEM_BU(ctx->r11, (int16_t)RELOC_LO16(772, 0X3DFA));
    // 0x80802C7C: multu       $t1, $a1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80802C80: sll         $t1, $a3, 1
    ctx->r9 = S32(ctx->r7 << 1);
    // 0x80802C84: mflo        $t2
    ctx->r10 = lo;
    // 0x80802C88: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x80802C8C: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
    // 0x80802C90: addu        $v1, $a2, $t4
    ctx->r3 = ADD32(ctx->r6, ctx->r12);
    // 0x80802C94: lhu         $t5, -0x2($v1)
    ctx->r13 = MEM_HU(ctx->r3, -0X2);
    // 0x80802C98: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(772, 0X3DF8) << 16);
    // 0x80802C9C: addiu       $t2, $t2, 0x3DF8
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(772, 0X3DF8));
    // 0x80802CA0: sh          $t5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r13;
    // 0x80802CA4: lbu         $t6, 0x3DFD($t6)
    ctx->r14 = MEM_BU(ctx->r14, (int16_t)RELOC_LO16(772, 0X3DFD));
    // 0x80802CA8: lbu         $t8, 0x3DFC($t8)
    ctx->r24 = MEM_BU(ctx->r24, (int16_t)RELOC_LO16(772, 0X3DFC));
    // 0x80802CAC: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x80802CB0: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80802CB4: mflo        $t7
    ctx->r15 = lo;
    // 0x80802CB8: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80802CBC: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x80802CC0: addu        $v1, $a2, $t9
    ctx->r3 = ADD32(ctx->r6, ctx->r25);
    // 0x80802CC4: lhu         $t0, -0x2($v1)
    ctx->r8 = MEM_HU(ctx->r3, -0X2);
    // 0x80802CC8: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
    // 0x80802CCC: lbu         $t3, 0x1($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X1);
    // 0x80802CD0: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x80802CD4: multu       $t3, $a1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80802CD8: mflo        $t4
    ctx->r12 = lo;
    // 0x80802CDC: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x80802CE0: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80802CE4: addu        $v1, $a2, $t6
    ctx->r3 = ADD32(ctx->r6, ctx->r14);
    // 0x80802CE8: lhu         $t7, -0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, -0X2);
    // 0x80802CEC: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x80802CF0: lbu         $t8, 0x3($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X3);
    // 0x80802CF4: lbu         $t0, 0x2($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X2);
    // 0x80802CF8: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80802CFC: mflo        $t9
    ctx->r25 = lo;
    // 0x80802D00: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x80802D04: sll         $t1, $a0, 1
    ctx->r9 = S32(ctx->r4 << 1);
    // 0x80802D08: addu        $v1, $a2, $t1
    ctx->r3 = ADD32(ctx->r6, ctx->r9);
    // 0x80802D0C: lhu         $t2, -0x2($v1)
    ctx->r10 = MEM_HU(ctx->r3, -0X2);
    // 0x80802D10: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x80802D14: lbu         $t3, 0x5($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X5);
    // 0x80802D18: lbu         $t5, 0x4($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X4);
    // 0x80802D1C: multu       $t3, $a1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80802D20: mflo        $t4
    ctx->r12 = lo;
    // 0x80802D24: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x80802D28: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80802D2C: addu        $v1, $a2, $t6
    ctx->r3 = ADD32(ctx->r6, ctx->r14);
    // 0x80802D30: lhu         $t7, -0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, -0X2);
    // 0x80802D34: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x80802D38: lbu         $t8, 0x7($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X7);
    // 0x80802D3C: lbu         $t0, 0x6($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X6);
    // 0x80802D40: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80802D44: mflo        $t9
    ctx->r25 = lo;
    // 0x80802D48: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x80802D4C: sll         $t1, $a0, 1
    ctx->r9 = S32(ctx->r4 << 1);
    // 0x80802D50: addu        $v1, $a2, $t1
    ctx->r3 = ADD32(ctx->r6, ctx->r9);
    // 0x80802D54: lhu         $t2, -0x2($v1)
    ctx->r10 = MEM_HU(ctx->r3, -0X2);
    // 0x80802D58: b           L_80802E64
    // 0x80802D5C: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
        goto L_80802E64;
    // 0x80802D5C: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
L_80802D60:
    // 0x80802D60: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(772, 0X3DE5) << 16);
    // 0x80802D64: lbu         $t3, 0x3DE5($t3)
    ctx->r11 = MEM_BU(ctx->r11, (int16_t)RELOC_LO16(772, 0X3DE5));
    // 0x80802D68: addiu       $a1, $zero, 0x130
    ctx->r5 = ADD32(0, 0X130);
    // 0x80802D6C: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(772, 0X3DE4) << 16);
    // 0x80802D70: multu       $t3, $a1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80802D74: lbu         $t5, 0x3DE4($t5)
    ctx->r13 = MEM_BU(ctx->r13, (int16_t)RELOC_LO16(772, 0X3DE4));
    // 0x80802D78: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(772, 0X3DE7) << 16);
    // 0x80802D7C: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(772, 0X3DE6) << 16);
    // 0x80802D80: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(772, 0X3DE8) << 16);
    // 0x80802D84: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(772, 0X3DF8) << 16);
    // 0x80802D88: addiu       $a3, $a3, 0x3DF8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(772, 0X3DF8));
    // 0x80802D8C: addiu       $v1, $v1, 0x3DE8
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(772, 0X3DE8));
    // 0x80802D90: mflo        $t4
    ctx->r12 = lo;
    // 0x80802D94: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x80802D98: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80802D9C: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
    // 0x80802DA0: lhu         $t7, -0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, -0X2);
    // 0x80802DA4: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x80802DA8: lbu         $t8, 0x3DE7($t8)
    ctx->r24 = MEM_BU(ctx->r24, (int16_t)RELOC_LO16(772, 0X3DE7));
    // 0x80802DAC: lbu         $t0, 0x3DE6($t0)
    ctx->r8 = MEM_BU(ctx->r8, (int16_t)RELOC_LO16(772, 0X3DE6));
    // 0x80802DB0: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80802DB4: mflo        $t9
    ctx->r25 = lo;
    // 0x80802DB8: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x80802DBC: sll         $t1, $a0, 1
    ctx->r9 = S32(ctx->r4 << 1);
    // 0x80802DC0: addu        $v0, $a2, $t1
    ctx->r2 = ADD32(ctx->r6, ctx->r9);
    // 0x80802DC4: lhu         $t2, -0x2($v0)
    ctx->r10 = MEM_HU(ctx->r2, -0X2);
    // 0x80802DC8: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
L_80802DCC:
    // 0x80802DCC: lbu         $t3, 0x1($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X1);
    // 0x80802DD0: lbu         $t5, 0x0($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X0);
    // 0x80802DD4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80802DD8: multu       $t3, $a1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80802DDC: mflo        $t4
    ctx->r12 = lo;
    // 0x80802DE0: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x80802DE4: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80802DE8: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
    // 0x80802DEC: lhu         $t7, -0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, -0X2);
    // 0x80802DF0: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x80802DF4: lbu         $t8, -0x5($v1)
    ctx->r24 = MEM_BU(ctx->r3, -0X5);
    // 0x80802DF8: lbu         $t0, -0x6($v1)
    ctx->r8 = MEM_BU(ctx->r3, -0X6);
    // 0x80802DFC: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80802E00: mflo        $t9
    ctx->r25 = lo;
    // 0x80802E04: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x80802E08: sll         $t1, $a0, 1
    ctx->r9 = S32(ctx->r4 << 1);
    // 0x80802E0C: addu        $v0, $a2, $t1
    ctx->r2 = ADD32(ctx->r6, ctx->r9);
    // 0x80802E10: lhu         $t2, -0x2($v0)
    ctx->r10 = MEM_HU(ctx->r2, -0X2);
    // 0x80802E14: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
    // 0x80802E18: lbu         $t3, -0x3($v1)
    ctx->r11 = MEM_BU(ctx->r3, -0X3);
    // 0x80802E1C: lbu         $t5, -0x4($v1)
    ctx->r13 = MEM_BU(ctx->r3, -0X4);
    // 0x80802E20: multu       $t3, $a1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80802E24: mflo        $t4
    ctx->r12 = lo;
    // 0x80802E28: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x80802E2C: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80802E30: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
    // 0x80802E34: lhu         $t7, -0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, -0X2);
    // 0x80802E38: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x80802E3C: lbu         $t8, -0x1($v1)
    ctx->r24 = MEM_BU(ctx->r3, -0X1);
    // 0x80802E40: lbu         $t0, -0x2($v1)
    ctx->r8 = MEM_BU(ctx->r3, -0X2);
    // 0x80802E44: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80802E48: mflo        $t9
    ctx->r25 = lo;
    // 0x80802E4C: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x80802E50: sll         $t1, $a0, 1
    ctx->r9 = S32(ctx->r4 << 1);
    // 0x80802E54: addu        $v0, $a2, $t1
    ctx->r2 = ADD32(ctx->r6, ctx->r9);
    // 0x80802E58: lhu         $t2, -0x2($v0)
    ctx->r10 = MEM_HU(ctx->r2, -0X2);
    // 0x80802E5C: bne         $v1, $a3, L_80802DCC
    if (ctx->r3 != ctx->r7) {
        // 0x80802E60: sh          $t2, 0x0($v0)
        MEM_H(0X0, ctx->r2) = ctx->r10;
            goto L_80802DCC;
    }
    // 0x80802E60: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
L_80802E64:
    // 0x80802E64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802E68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802E6C: jr          $ra
    // 0x80802E70: nop

    return;
    // 0x80802E70: nop

;}
RECOMP_FUNC void subaddiedialog_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080040C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800410: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800414: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800418: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8080041C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800420: lbu         $t6, 0x16($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X16);
    // 0x80800424: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800428: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8080042C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80800430: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x80800434: beql        $t7, $at, L_808006C0
    if (ctx->r15 == ctx->r1) {
        // 0x80800438: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_808006C0;
    }
    goto skip_0;
    // 0x80800438: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    skip_0:
    // 0x8080043C: lhu         $t8, 0xC($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0XC);
    // 0x80800440: beql        $t8, $zero, L_808006C0
    if (ctx->r24 == 0) {
        // 0x80800444: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_808006C0;
    }
    goto skip_1;
    // 0x80800444: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    skip_1:
    // 0x80800448: jal         0x800F54E4
    // 0x8080044C: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8080044C: nop

    after_0:
    // 0x80800450: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800454: jal         0x800F64A4
    // 0x80800458: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    func_800F64A4(rdram, ctx);
        goto after_1;
    // 0x80800458: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    after_1:
    // 0x8080045C: bnel        $v0, $zero, L_808006C0
    if (ctx->r2 != 0) {
        // 0x80800460: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_808006C0;
    }
    goto skip_2;
    // 0x80800460: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    skip_2:
    // 0x80800464: lhu         $v0, 0xE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XE);
    // 0x80800468: beql        $v0, $zero, L_808005BC
    if (ctx->r2 == 0) {
        // 0x8080046C: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_808005BC;
    }
    goto skip_3;
    // 0x8080046C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    skip_3:
    // 0x80800470: jal         0x800DA298
    // 0x80800474: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800474: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800478: bne         $v0, $zero, L_808005B8
    if (ctx->r2 != 0) {
        // 0x8080047C: lw          $t9, 0x34($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X34);
            goto L_808005B8;
    }
    // 0x8080047C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80800480: andi        $t0, $t9, 0x20
    ctx->r8 = ctx->r25 & 0X20;
    // 0x80800484: beq         $t0, $zero, L_80800494
    if (ctx->r8 == 0) {
        // 0x80800488: lhu         $a2, 0x12($s0)
        ctx->r6 = MEM_HU(ctx->r16, 0X12);
            goto L_80800494;
    }
    // 0x80800488: lhu         $a2, 0x12($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X12);
    // 0x8080048C: ori         $t1, $a2, 0x1
    ctx->r9 = ctx->r6 | 0X1;
    // 0x80800490: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
L_80800494:
    // 0x80800494: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800498: jal         0x80800000
    // 0x8080049C: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    func_80800000_subaddiedialog(rdram, ctx);
        goto after_3;
    // 0x8080049C: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_3:
    // 0x808004A0: bne         $v0, $zero, L_808004B0
    if (ctx->r2 != 0) {
        // 0x808004A4: lw          $t2, 0x34($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X34);
            goto L_808004B0;
    }
    // 0x808004A4: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x808004A8: b           L_8080097C
    // 0x808004AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080097C;
    // 0x808004AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004B0:
    // 0x808004B0: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x808004B4: beq         $t3, $zero, L_808004D8
    if (ctx->r11 == 0) {
        // 0x808004B8: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_808004D8;
    }
    // 0x808004B8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808004BC: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x808004C0: jal         0x8080110C
    // 0x808004C4: lbu         $a2, 0x17($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X17);
    func_8080110C_subaddiedialog(rdram, ctx);
        goto after_4;
    // 0x808004C4: lbu         $a2, 0x17($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X17);
    after_4:
    // 0x808004C8: bnel        $v0, $zero, L_808004DC
    if (ctx->r2 != 0) {
        // 0x808004CC: lw          $t4, 0x34($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X34);
            goto L_808004DC;
    }
    goto skip_4;
    // 0x808004CC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    skip_4:
    // 0x808004D0: b           L_8080097C
    // 0x808004D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080097C;
    // 0x808004D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004D8:
    // 0x808004D8: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
L_808004DC:
    // 0x808004DC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x808004E0: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x808004E4: beql        $t5, $zero, L_80800520
    if (ctx->r13 == 0) {
        // 0x808004E8: lw          $t8, 0x34($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X34);
            goto L_80800520;
    }
    goto skip_5;
    // 0x808004E8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    skip_5:
    // 0x808004EC: lwc1        $f4, 0x48($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X48);
    // 0x808004F0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808004F4: lhu         $a2, 0x2($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X2);
    // 0x808004F8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808004FC: lbu         $a3, 0x17($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X17);
    // 0x80800500: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800504: jal         0x8080118C
    // 0x80800508: nop

    func_8080118C_subaddiedialog(rdram, ctx);
        goto after_5;
    // 0x80800508: nop

    after_5:
    // 0x8080050C: bnel        $v0, $zero, L_80800520
    if (ctx->r2 != 0) {
        // 0x80800510: lw          $t8, 0x34($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X34);
            goto L_80800520;
    }
    goto skip_6;
    // 0x80800510: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    skip_6:
    // 0x80800514: b           L_8080097C
    // 0x80800518: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080097C;
    // 0x80800518: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080051C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
L_80800520:
    // 0x80800520: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80800524: bnel        $t9, $zero, L_80800558
    if (ctx->r25 != 0) {
        // 0x80800528: lw          $t0, 0x34($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X34);
            goto L_80800558;
    }
    goto skip_7;
    // 0x80800528: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    skip_7:
    // 0x8080052C: jal         0x800F54E4
    // 0x80800530: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x80800530: nop

    after_6:
    // 0x80800534: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800538: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8080053C: jal         0x800F4B8C
    // 0x80800540: lhu         $a2, 0x12($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X12);
    func_800F4B8C(rdram, ctx);
        goto after_7;
    // 0x80800540: lhu         $a2, 0x12($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X12);
    after_7:
    // 0x80800544: bnel        $v0, $zero, L_80800558
    if (ctx->r2 != 0) {
        // 0x80800548: lw          $t0, 0x34($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X34);
            goto L_80800558;
    }
    goto skip_8;
    // 0x80800548: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    skip_8:
    // 0x8080054C: b           L_8080097C
    // 0x80800550: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080097C;
    // 0x80800550: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800554: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
L_80800558:
    // 0x80800558: lhu         $a2, 0x14($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X14);
    // 0x8080055C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80800560: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x80800564: bne         $t1, $zero, L_80800574
    if (ctx->r9 != 0) {
        // 0x80800568: lw          $a3, 0x3C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X3C);
            goto L_80800574;
    }
    // 0x80800568: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8080056C: ori         $t2, $a2, 0x2
    ctx->r10 = ctx->r6 | 0X2;
    // 0x80800570: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
L_80800574:
    // 0x80800574: lh          $t4, 0x10($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X10);
    // 0x80800578: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x8080057C: lhu         $a1, 0xC($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XC);
    // 0x80800580: jal         0x80801284
    // 0x80800584: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80800584: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_8:
    // 0x80800588: beq         $v0, $zero, L_808006AC
    if (ctx->r2 == 0) {
        // 0x8080058C: nop
    
            goto L_808006AC;
    }
    // 0x8080058C: nop

    // 0x80800590: jal         0x800DA544
    // 0x80800594: lhu         $a0, 0xE($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XE);
    func_800DA544(rdram, ctx);
        goto after_9;
    // 0x80800594: lhu         $a0, 0xE($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XE);
    after_9:
    // 0x80800598: lbu         $v0, 0x18($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X18);
    // 0x8080059C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808005A0: beq         $v0, $zero, L_808005B0
    if (ctx->r2 == 0) {
        // 0x808005A4: nop
    
            goto L_808005B0;
    }
    // 0x808005A4: nop

    // 0x808005A8: jal         0x80102424
    // 0x808005AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80102424(rdram, ctx);
        goto after_10;
    // 0x808005AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
L_808005B0:
    // 0x808005B0: b           L_8080097C
    // 0x808005B4: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
        goto L_8080097C;
    // 0x808005B4: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
L_808005B8:
    // 0x808005B8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
L_808005BC:
    // 0x808005BC: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x808005C0: lhu         $a2, 0x12($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X12);
    // 0x808005C4: jal         0x80801208
    // 0x808005C8: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    func_80801208_subaddiedialog(rdram, ctx);
        goto after_11;
    // 0x808005C8: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_11:
    // 0x808005CC: beq         $v0, $zero, L_808006AC
    if (ctx->r2 == 0) {
        // 0x808005D0: lw          $t5, 0x34($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X34);
            goto L_808006AC;
    }
    // 0x808005D0: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x808005D4: andi        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 & 0X2;
    // 0x808005D8: beq         $t6, $zero, L_80800604
    if (ctx->r14 == 0) {
        // 0x808005DC: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_80800604;
    }
    // 0x808005DC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808005E0: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x808005E4: jal         0x8080110C
    // 0x808005E8: lbu         $a2, 0x17($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X17);
    func_8080110C_subaddiedialog(rdram, ctx);
        goto after_12;
    // 0x808005E8: lbu         $a2, 0x17($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X17);
    after_12:
    // 0x808005EC: bnel        $v0, $zero, L_80800608
    if (ctx->r2 != 0) {
        // 0x808005F0: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_80800608;
    }
    goto skip_9;
    // 0x808005F0: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    skip_9:
    // 0x808005F4: jal         0x8080141C
    // 0x808005F8: nop

    func_8080141C_subaddiedialog(rdram, ctx);
        goto after_13;
    // 0x808005F8: nop

    after_13:
    // 0x808005FC: b           L_80800980
    // 0x80800600: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800980;
    // 0x80800600: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800604:
    // 0x80800604: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
L_80800608:
    // 0x80800608: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8080060C: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x80800610: beql        $t8, $zero, L_80800654
    if (ctx->r24 == 0) {
        // 0x80800614: lw          $t1, 0x34($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X34);
            goto L_80800654;
    }
    goto skip_10;
    // 0x80800614: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    skip_10:
    // 0x80800618: lwc1        $f8, 0x48($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X48);
    // 0x8080061C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800620: lhu         $a2, 0x2($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X2);
    // 0x80800624: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800628: lbu         $a3, 0x17($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X17);
    // 0x8080062C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800630: jal         0x8080118C
    // 0x80800634: nop

    func_8080118C_subaddiedialog(rdram, ctx);
        goto after_14;
    // 0x80800634: nop

    after_14:
    // 0x80800638: bnel        $v0, $zero, L_80800654
    if (ctx->r2 != 0) {
        // 0x8080063C: lw          $t1, 0x34($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X34);
            goto L_80800654;
    }
    goto skip_11;
    // 0x8080063C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    skip_11:
    // 0x80800640: jal         0x8080141C
    // 0x80800644: nop

    func_8080141C_subaddiedialog(rdram, ctx);
        goto after_15;
    // 0x80800644: nop

    after_15:
    // 0x80800648: b           L_80800980
    // 0x8080064C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800980;
    // 0x8080064C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800650: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
L_80800654:
    // 0x80800654: lhu         $a2, 0x14($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X14);
    // 0x80800658: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8080065C: andi        $t2, $t1, 0x8
    ctx->r10 = ctx->r9 & 0X8;
    // 0x80800660: bne         $t2, $zero, L_80800670
    if (ctx->r10 != 0) {
        // 0x80800664: lw          $a3, 0x3C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X3C);
            goto L_80800670;
    }
    // 0x80800664: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80800668: ori         $t3, $a2, 0x3
    ctx->r11 = ctx->r6 | 0X3;
    // 0x8080066C: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
L_80800670:
    // 0x80800670: lh          $t5, 0x10($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X10);
    // 0x80800674: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80800678: lhu         $a1, 0xC($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XC);
    // 0x8080067C: jal         0x80801284
    // 0x80800680: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_16;
    // 0x80800680: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_16:
    // 0x80800684: beq         $v0, $zero, L_808006AC
    if (ctx->r2 == 0) {
        // 0x80800688: nop
    
            goto L_808006AC;
    }
    // 0x80800688: nop

    // 0x8080068C: lbu         $v0, 0x18($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X18);
    // 0x80800690: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800694: beq         $v0, $zero, L_808006A4
    if (ctx->r2 == 0) {
        // 0x80800698: nop
    
            goto L_808006A4;
    }
    // 0x80800698: nop

    // 0x8080069C: jal         0x80102424
    // 0x808006A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80102424(rdram, ctx);
        goto after_17;
    // 0x808006A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_17:
L_808006A4:
    // 0x808006A4: b           L_8080097C
    // 0x808006A8: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
        goto L_8080097C;
    // 0x808006A8: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
L_808006AC:
    // 0x808006AC: jal         0x8080141C
    // 0x808006B0: nop

    func_8080141C_subaddiedialog(rdram, ctx);
        goto after_18;
    // 0x808006B0: nop

    after_18:
    // 0x808006B4: b           L_80800980
    // 0x808006B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800980;
    // 0x808006B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808006BC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_808006C0:
    // 0x808006C0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808006C4: jal         0x80801394
    // 0x808006C8: lhu         $a2, 0x0($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X0);
    func_80801394_subaddiedialog(rdram, ctx);
        goto after_19;
    // 0x808006C8: lhu         $a2, 0x0($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X0);
    after_19:
    // 0x808006CC: beq         $v0, $zero, L_8080084C
    if (ctx->r2 == 0) {
        // 0x808006D0: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_8080084C;
    }
    // 0x808006D0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808006D4: lhu         $a2, 0x12($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X12);
    // 0x808006D8: jal         0x800F54E4
    // 0x808006DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800F54E4(rdram, ctx);
        goto after_20;
    // 0x808006DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_20:
    // 0x808006E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006E4: jal         0x800F64A4
    // 0x808006E8: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    func_800F64A4(rdram, ctx);
        goto after_21;
    // 0x808006E8: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    after_21:
    // 0x808006EC: bne         $v0, $zero, L_808006FC
    if (ctx->r2 != 0) {
        // 0x808006F0: lw          $a2, 0x28($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X28);
            goto L_808006FC;
    }
    // 0x808006F0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808006F4: b           L_8080097C
    // 0x808006F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080097C;
    // 0x808006F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006FC:
    // 0x808006FC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800700: ori         $t8, $a2, 0x1
    ctx->r24 = ctx->r6 | 0X1;
    // 0x80800704: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800708: andi        $t7, $t6, 0x20
    ctx->r15 = ctx->r14 & 0X20;
    // 0x8080070C: beq         $t7, $zero, L_80800718
    if (ctx->r15 == 0) {
        // 0x80800710: nop
    
            goto L_80800718;
    }
    // 0x80800710: nop

    // 0x80800714: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
L_80800718:
    // 0x80800718: jal         0x80800000
    // 0x8080071C: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    func_80800000_subaddiedialog(rdram, ctx);
        goto after_22;
    // 0x8080071C: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_22:
    // 0x80800720: bne         $v0, $zero, L_80800730
    if (ctx->r2 != 0) {
        // 0x80800724: lw          $t9, 0x34($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X34);
            goto L_80800730;
    }
    // 0x80800724: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80800728: b           L_8080097C
    // 0x8080072C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080097C;
    // 0x8080072C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800730:
    // 0x80800730: andi        $t0, $t9, 0x2
    ctx->r8 = ctx->r25 & 0X2;
    // 0x80800734: beq         $t0, $zero, L_80800758
    if (ctx->r8 == 0) {
        // 0x80800738: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_80800758;
    }
    // 0x80800738: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8080073C: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80800740: jal         0x8080110C
    // 0x80800744: lbu         $a2, 0x17($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X17);
    func_8080110C_subaddiedialog(rdram, ctx);
        goto after_23;
    // 0x80800744: lbu         $a2, 0x17($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X17);
    after_23:
    // 0x80800748: bnel        $v0, $zero, L_8080075C
    if (ctx->r2 != 0) {
        // 0x8080074C: lw          $t1, 0x34($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X34);
            goto L_8080075C;
    }
    goto skip_12;
    // 0x8080074C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    skip_12:
    // 0x80800750: b           L_8080097C
    // 0x80800754: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080097C;
    // 0x80800754: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800758:
    // 0x80800758: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
L_8080075C:
    // 0x8080075C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80800760: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x80800764: beql        $t2, $zero, L_808007A0
    if (ctx->r10 == 0) {
        // 0x80800768: lw          $t5, 0x34($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X34);
            goto L_808007A0;
    }
    goto skip_13;
    // 0x80800768: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    skip_13:
    // 0x8080076C: lwc1        $f16, 0x48($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X48);
    // 0x80800770: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800774: lhu         $a2, 0x2($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X2);
    // 0x80800778: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8080077C: lbu         $a3, 0x17($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X17);
    // 0x80800780: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800784: jal         0x8080118C
    // 0x80800788: nop

    func_8080118C_subaddiedialog(rdram, ctx);
        goto after_24;
    // 0x80800788: nop

    after_24:
    // 0x8080078C: bnel        $v0, $zero, L_808007A0
    if (ctx->r2 != 0) {
        // 0x80800790: lw          $t5, 0x34($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X34);
            goto L_808007A0;
    }
    goto skip_14;
    // 0x80800790: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    skip_14:
    // 0x80800794: b           L_8080097C
    // 0x80800798: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080097C;
    // 0x80800798: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080079C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
L_808007A0:
    // 0x808007A0: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x808007A4: bnel        $t6, $zero, L_808007D8
    if (ctx->r14 != 0) {
        // 0x808007A8: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_808007D8;
    }
    goto skip_15;
    // 0x808007A8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    skip_15:
    // 0x808007AC: jal         0x800F54E4
    // 0x808007B0: nop

    func_800F54E4(rdram, ctx);
        goto after_25;
    // 0x808007B0: nop

    after_25:
    // 0x808007B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808007B8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808007BC: jal         0x800F4B8C
    // 0x808007C0: lhu         $a2, 0x12($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X12);
    func_800F4B8C(rdram, ctx);
        goto after_26;
    // 0x808007C0: lhu         $a2, 0x12($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X12);
    after_26:
    // 0x808007C4: bnel        $v0, $zero, L_808007D8
    if (ctx->r2 != 0) {
        // 0x808007C8: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_808007D8;
    }
    goto skip_16;
    // 0x808007C8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    skip_16:
    // 0x808007CC: b           L_8080097C
    // 0x808007D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080097C;
    // 0x808007D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808007D4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
L_808007D8:
    // 0x808007D8: lhu         $a2, 0x14($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X14);
    // 0x808007DC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x808007E0: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x808007E4: bne         $t8, $zero, L_808007F4
    if (ctx->r24 != 0) {
        // 0x808007E8: lw          $a3, 0x3C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X3C);
            goto L_808007F4;
    }
    // 0x808007E8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x808007EC: ori         $t9, $a2, 0x2
    ctx->r25 = ctx->r6 | 0X2;
    // 0x808007F0: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
L_808007F4:
    // 0x808007F4: lh          $t1, 0x10($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X10);
    // 0x808007F8: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x808007FC: lhu         $a1, 0x4($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X4);
    // 0x80800800: jal         0x80801284
    // 0x80800804: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_27;
    // 0x80800804: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_27:
    // 0x80800808: beq         $v0, $zero, L_8080083C
    if (ctx->r2 == 0) {
        // 0x8080080C: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_8080083C;
    }
    // 0x8080080C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800810: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800814: jal         0x808013E4
    // 0x80800818: lhu         $a2, 0x0($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X0);
    func_808013E4_subaddiedialog(rdram, ctx);
        goto after_28;
    // 0x80800818: lhu         $a2, 0x0($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X0);
    after_28:
    // 0x8080081C: lbu         $v0, 0x18($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X18);
    // 0x80800820: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800824: beq         $v0, $zero, L_80800834
    if (ctx->r2 == 0) {
        // 0x80800828: nop
    
            goto L_80800834;
    }
    // 0x80800828: nop

    // 0x8080082C: jal         0x80102424
    // 0x80800830: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80102424(rdram, ctx);
        goto after_29;
    // 0x80800830: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_29:
L_80800834:
    // 0x80800834: b           L_8080097C
    // 0x80800838: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
        goto L_8080097C;
    // 0x80800838: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
L_8080083C:
    // 0x8080083C: jal         0x8080141C
    // 0x80800840: nop

    func_8080141C_subaddiedialog(rdram, ctx);
        goto after_30;
    // 0x80800840: nop

    after_30:
    // 0x80800844: b           L_80800980
    // 0x80800848: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800980;
    // 0x80800848: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080084C:
    // 0x8080084C: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80800850: lhu         $a2, 0x12($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X12);
    // 0x80800854: jal         0x80801208
    // 0x80800858: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    func_80801208_subaddiedialog(rdram, ctx);
        goto after_31;
    // 0x80800858: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_31:
    // 0x8080085C: beql        $v0, $zero, L_8080097C
    if (ctx->r2 == 0) {
        // 0x80800860: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080097C;
    }
    goto skip_17;
    // 0x80800860: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_17:
    // 0x80800864: jal         0x800F54E4
    // 0x80800868: nop

    func_800F54E4(rdram, ctx);
        goto after_32;
    // 0x80800868: nop

    after_32:
    // 0x8080086C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800870: jal         0x800F64A4
    // 0x80800874: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    func_800F64A4(rdram, ctx);
        goto after_33;
    // 0x80800874: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    after_33:
    // 0x80800878: bne         $v0, $zero, L_80800890
    if (ctx->r2 != 0) {
        // 0x8080087C: lw          $t2, 0x34($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X34);
            goto L_80800890;
    }
    // 0x8080087C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80800880: jal         0x8080141C
    // 0x80800884: nop

    func_8080141C_subaddiedialog(rdram, ctx);
        goto after_34;
    // 0x80800884: nop

    after_34:
    // 0x80800888: b           L_80800980
    // 0x8080088C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800980;
    // 0x8080088C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800890:
    // 0x80800890: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x80800894: beq         $t3, $zero, L_808008C0
    if (ctx->r11 == 0) {
        // 0x80800898: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_808008C0;
    }
    // 0x80800898: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8080089C: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x808008A0: jal         0x8080110C
    // 0x808008A4: lbu         $a2, 0x17($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X17);
    func_8080110C_subaddiedialog(rdram, ctx);
        goto after_35;
    // 0x808008A4: lbu         $a2, 0x17($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X17);
    after_35:
    // 0x808008A8: bnel        $v0, $zero, L_808008C4
    if (ctx->r2 != 0) {
        // 0x808008AC: lw          $t4, 0x34($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X34);
            goto L_808008C4;
    }
    goto skip_18;
    // 0x808008AC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    skip_18:
    // 0x808008B0: jal         0x8080141C
    // 0x808008B4: nop

    func_8080141C_subaddiedialog(rdram, ctx);
        goto after_36;
    // 0x808008B4: nop

    after_36:
    // 0x808008B8: b           L_80800980
    // 0x808008BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800980;
    // 0x808008BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008C0:
    // 0x808008C0: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
L_808008C4:
    // 0x808008C4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x808008C8: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x808008CC: beql        $t5, $zero, L_80800910
    if (ctx->r13 == 0) {
        // 0x808008D0: lw          $t8, 0x34($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X34);
            goto L_80800910;
    }
    goto skip_19;
    // 0x808008D0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    skip_19:
    // 0x808008D4: lwc1        $f4, 0x48($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X48);
    // 0x808008D8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808008DC: lhu         $a2, 0x2($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X2);
    // 0x808008E0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808008E4: lbu         $a3, 0x17($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X17);
    // 0x808008E8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808008EC: jal         0x8080118C
    // 0x808008F0: nop

    func_8080118C_subaddiedialog(rdram, ctx);
        goto after_37;
    // 0x808008F0: nop

    after_37:
    // 0x808008F4: bnel        $v0, $zero, L_80800910
    if (ctx->r2 != 0) {
        // 0x808008F8: lw          $t8, 0x34($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X34);
            goto L_80800910;
    }
    goto skip_20;
    // 0x808008F8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    skip_20:
    // 0x808008FC: jal         0x8080141C
    // 0x80800900: nop

    func_8080141C_subaddiedialog(rdram, ctx);
        goto after_38;
    // 0x80800900: nop

    after_38:
    // 0x80800904: b           L_80800980
    // 0x80800908: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800980;
    // 0x80800908: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080090C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
L_80800910:
    // 0x80800910: lhu         $a2, 0x14($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X14);
    // 0x80800914: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80800918: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x8080091C: bne         $t9, $zero, L_8080092C
    if (ctx->r25 != 0) {
        // 0x80800920: lw          $a3, 0x3C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X3C);
            goto L_8080092C;
    }
    // 0x80800920: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80800924: ori         $t0, $a2, 0x3
    ctx->r8 = ctx->r6 | 0X3;
    // 0x80800928: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
L_8080092C:
    // 0x8080092C: lh          $t2, 0x10($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X10);
    // 0x80800930: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80800934: lhu         $a1, 0x6($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X6);
    // 0x80800938: jal         0x80801284
    // 0x8080093C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_39;
    // 0x8080093C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_39:
    // 0x80800940: beq         $v0, $zero, L_80800968
    if (ctx->r2 == 0) {
        // 0x80800944: nop
    
            goto L_80800968;
    }
    // 0x80800944: nop

    // 0x80800948: lbu         $v0, 0x18($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X18);
    // 0x8080094C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800950: beq         $v0, $zero, L_80800960
    if (ctx->r2 == 0) {
        // 0x80800954: nop
    
            goto L_80800960;
    }
    // 0x80800954: nop

    // 0x80800958: jal         0x80102424
    // 0x8080095C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80102424(rdram, ctx);
        goto after_40;
    // 0x8080095C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_40:
L_80800960:
    // 0x80800960: b           L_8080097C
    // 0x80800964: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
        goto L_8080097C;
    // 0x80800964: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
L_80800968:
    // 0x80800968: jal         0x8080141C
    // 0x8080096C: nop

    func_8080141C_subaddiedialog(rdram, ctx);
        goto after_41;
    // 0x8080096C: nop

    after_41:
    // 0x80800970: b           L_80800980
    // 0x80800974: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800980;
    // 0x80800974: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800978: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080097C:
    // 0x8080097C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800980:
    // 0x80800980: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800984: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800988: jr          $ra
    // 0x8080098C: nop

    return;
    // 0x8080098C: nop

;}
RECOMP_FUNC void func_80803668_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803668: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080366C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80803670: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80803674: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80803678: jal         0x80106790
    // 0x8080367C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080367C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80803680: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80803684: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803688: jal         0x80100094
    // 0x8080368C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080368C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80803690: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80803694: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80803698: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080369C: jal         0x800E4140
    // 0x808036A0: addiu       $a1, $v0, 0x20
    ctx->r5 = ADD32(ctx->r2, 0X20);
    func_800E4140(rdram, ctx);
        goto after_2;
    // 0x808036A0: addiu       $a1, $v0, 0x20
    ctx->r5 = ADD32(ctx->r2, 0X20);
    after_2:
    // 0x808036A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X3AD0) << 16);
    // 0x808036A8: lwc1        $f6, 0x3AD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X3AD0));
    // 0x808036AC: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808036B0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808036B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808036B8: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808036BC: lwc1        $f4, 0x24($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X24);
    // 0x808036C0: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x808036C4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808036C8: div.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808036CC: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x808036D0: sub.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x808036D4: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808036D8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808036DC: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x808036E0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x808036E4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808036E8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x808036EC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808036F0: jal         0x800E7DE4
    // 0x808036F4: nop

    func_800E7DE4(rdram, ctx);
        goto after_3;
    // 0x808036F4: nop

    after_3:
    // 0x808036F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808036FC: jal         0x80101870
    // 0x80803700: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80101870(rdram, ctx);
        goto after_4;
    // 0x80803700: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_4:
    // 0x80803704: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    // 0x80803708: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080370C: addiu       $s0, $s1, 0xC
    ctx->r16 = ADD32(ctx->r17, 0XC);
    // 0x80803710: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x80803714: bne         $t0, $at, L_80803738
    if (ctx->r8 != ctx->r1) {
        // 0x80803718: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803738;
    }
    // 0x80803718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080371C: addiu       $s0, $s1, 0xC
    ctx->r16 = ADD32(ctx->r17, 0XC);
    // 0x80803720: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(772, 0X3EA4) << 16);
    // 0x80803724: addiu       $a1, $a1, 0x3EA4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(772, 0X3EA4));
    // 0x80803728: jal         0x800EE7F8
    // 0x8080372C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x8080372C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80803730: b           L_80803748
    // 0x80803734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80803748;
    // 0x80803734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80803738:
    // 0x80803738: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(772, 0X3EB0) << 16);
    // 0x8080373C: jal         0x800EE7F8
    // 0x80803740: addiu       $a1, $a1, 0x3EB0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(772, 0X3EB0));
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80803740: addiu       $a1, $a1, 0x3EB0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(772, 0X3EB0));
    after_6:
    // 0x80803744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80803748:
    // 0x80803748: jal         0x800EF04C
    // 0x8080374C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x8080374C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x80803750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803754: jal         0x800E4140
    // 0x80803758: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    func_800E4140(rdram, ctx);
        goto after_8;
    // 0x80803758: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    after_8:
    // 0x8080375C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80803760: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80803764: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80803768: jr          $ra
    // 0x8080376C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8080376C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80800288_chlaundry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800288: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8080028C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800290: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80800294: jr          $ra
    // 0x80800298: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800298: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_8008E6BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E6BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E6C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E6C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008E6C8: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x8008E6CC: jal         0x800EBFF4
    // 0x8008E6D0: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_800EBFF4(rdram, ctx);
        goto after_0;
    // 0x8008E6D0: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_0:
    // 0x8008E6D4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8008E6D8: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8008E6DC: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x8008E6E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E6E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008E6E8: jr          $ra
    // 0x8008E6EC: nop

    return;
    // 0x8008E6EC: nop

;}
RECOMP_FUNC void func_80800A8C_chburgerstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800A98: jal         0x80085808
    // 0x80800A9C: addiu       $a1, $zero, 0x9F
    ctx->r5 = ADD32(0, 0X9F);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800A9C: addiu       $a1, $zero, 0x9F
    ctx->r5 = ADD32(0, 0X9F);
    after_0:
    // 0x80800AA0: jal         0x80085818
    // 0x80800AA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800AA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800AAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800AB0: jr          $ra
    // 0x80800AB4: nop

    return;
    // 0x80800AB4: nop

;}
