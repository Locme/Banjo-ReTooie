#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800214_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800214: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800218: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080021C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800220: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800224: jal         0x80100094
    // 0x80800228: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800228: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080022C: lbu         $v1, 0xF($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XF);
    // 0x80800230: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800238: beq         $v1, $zero, L_8080025C
    if (ctx->r3 == 0) {
        // 0x8080023C: nop
    
            goto L_8080025C;
    }
    // 0x8080023C: nop

    // 0x80800240: beq         $v1, $at, L_80800274
    if (ctx->r3 == ctx->r1) {
        // 0x80800244: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800274;
    }
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800248: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080024C: beq         $v1, $at, L_80800294
    if (ctx->r3 == ctx->r1) {
        // 0x80800250: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800294;
    }
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800254: b           L_808002A8
    // 0x80800258: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002A8;
    // 0x80800258: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080025C:
    // 0x8080025C: jal         0x808001D0
    // 0x80800260: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808001D0_chhandcart(rdram, ctx);
        goto after_1;
    // 0x80800260: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800264: jal         0x808000B4
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B4_chhandcart(rdram, ctx);
        goto after_2;
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080026C: b           L_808002A8
    // 0x80800270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002A8;
    // 0x80800270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800274:
    // 0x80800274: jal         0x808001D0
    // 0x80800278: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808001D0_chhandcart(rdram, ctx);
        goto after_3;
    // 0x80800278: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x8080027C: jal         0x800880E0
    // 0x80800280: nop

    _gcintrotext_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80800280: nop

    after_4:
    // 0x80800284: jal         0x808000B4
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B4_chhandcart(rdram, ctx);
        goto after_5;
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080028C: b           L_808002A8
    // 0x80800290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002A8;
    // 0x80800290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800294:
    // 0x80800294: jal         0x808001D0
    // 0x80800298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808001D0_chhandcart(rdram, ctx);
        goto after_6;
    // 0x80800298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8080029C: jal         0x80800024
    // 0x808002A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80800024_chhandcart(rdram, ctx);
        goto after_7;
    // 0x808002A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x808002A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002A8:
    // 0x808002A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002B0: jr          $ra
    // 0x808002B4: nop

    return;
    // 0x808002B4: nop

;}
RECOMP_FUNC void _sujiggy_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A748: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A748);
    return;
    // 0x8008A74C: addi        $t0, $zero, 0x58
    ctx->r8 = ADD32(0, 0X58);
;}
RECOMP_FUNC void func_80800E98_chbiggafoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800EA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800EA4: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80800EA8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1216, 0X1244) << 16);
    // 0x80800EAC: addiu       $t7, $t7, 0x1244
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1216, 0X1244));
    // 0x80800EB0: lw          $a2, 0x38($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X38);
    // 0x80800EB4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800EB8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800EBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800EC0: jal         0x800BBCB8
    // 0x80800EC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80800EC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80800EC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800ECC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800ED0: jr          $ra
    // 0x80800ED4: nop

    return;
    // 0x80800ED4: nop

    // 0x80800ED8: nop

    // 0x80800EDC: nop

;}
RECOMP_FUNC void func_80800030_chlighthalo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800038: lbu         $a1, 0x34($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X34);
    // 0x8080003C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800040: beq         $a1, $zero, L_80800058
    if (ctx->r5 == 0) {
        // 0x80800044: andi        $a0, $a1, 0xFF
        ctx->r4 = ctx->r5 & 0XFF;
            goto L_80800058;
    }
    // 0x80800044: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80800048: jal         0x800E87E0
    // 0x8080004C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800E87E0(rdram, ctx);
        goto after_0;
    // 0x8080004C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800050: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800054: sb          $zero, 0x34($a2)
    MEM_B(0X34, ctx->r6) = 0;
L_80800058:
    // 0x80800058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080005C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
RECOMP_FUNC void func_800F1EA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1EA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F1EA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F1EAC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F1EB0: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800F1EB4: c.eq.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl == ctx->f12.fl;
    // 0x800F1EB8: nop

    // 0x800F1EBC: bc1fl       L_800F1EE0
    if (!c1cs) {
        // 0x800F1EC0: lwc1        $f14, 0x8($a0)
        ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
            goto L_800F1EE0;
    }
    goto skip_0;
    // 0x800F1EC0: lwc1        $f14, 0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
    skip_0:
    // 0x800F1EC4: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800F1EC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F1ECC: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800F1ED0: nop

    // 0x800F1ED4: bc1tl       L_800F1EFC
    if (c1cs) {
        // 0x800F1ED8: swc1        $f0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
            goto L_800F1EFC;
    }
    goto skip_1;
    // 0x800F1ED8: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    skip_1:
    // 0x800F1EDC: lwc1        $f14, 0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
L_800F1EE0:
    // 0x800F1EE0: jal         0x80013B7C
    // 0x800F1EE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80013B7C(rdram, ctx);
        goto after_0;
    // 0x800F1EE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800F1EE8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800F1EEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F1EF0: b           L_800F1EFC
    // 0x800F1EF4: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
        goto L_800F1EFC;
    // 0x800F1EF4: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x800F1EF8: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_800F1EFC:
    // 0x800F1EFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F1F00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F1F04: jr          $ra
    // 0x800F1F08: nop

    return;
    // 0x800F1F08: nop

;}
RECOMP_FUNC void func_8008C0B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C0B8: jr          $ra
    // 0x8008C0BC: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    return;
    // 0x8008C0BC: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _sujiggy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A698: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A698);
    return;
    // 0x8008A69C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void glid_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001FC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800200: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800204: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800208: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8080020C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80800210: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80800214: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800218: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8080021C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800220: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800224: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800228: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080022C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800230: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x80800234: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x80800238: jal         0x800B2190
    // 0x8080023C: lw          $a0, 0x14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14);
    func_800B2190(rdram, ctx);
        goto after_0;
    // 0x8080023C: lw          $a0, 0x14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14);
    after_0:
    // 0x80800240: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x80800244: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x80800248: addiu       $s3, $s1, 0x1C
    ctx->r19 = ADD32(ctx->r17, 0X1C);
    // 0x8080024C: blez        $a0, L_808002F4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80800250: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_808002F4;
    }
    // 0x80800250: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80800254:
    // 0x80800254: lh          $t6, 0x0($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X0);
    // 0x80800258: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8080025C: bnel        $s0, $t6, L_808002E8
    if (ctx->r16 != ctx->r14) {
        // 0x80800260: lw          $t3, 0x4($s3)
        ctx->r11 = MEM_W(ctx->r19, 0X4);
            goto L_808002E8;
    }
    goto skip_0;
    // 0x80800260: lw          $t3, 0x4($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X4);
    skip_0:
    // 0x80800264: lh          $t7, 0x2($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X2);
    // 0x80800268: addiu       $s6, $s3, 0x8
    ctx->r22 = ADD32(ctx->r19, 0X8);
    // 0x8080026C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800270: addu        $s7, $t8, $s3
    ctx->r23 = ADD32(ctx->r24, ctx->r19);
    // 0x80800274: addiu       $s7, $s7, 0x8
    ctx->r23 = ADD32(ctx->r23, 0X8);
    // 0x80800278: sltu        $at, $s6, $s7
    ctx->r1 = ctx->r22 < ctx->r23 ? 1 : 0;
    // 0x8080027C: beq         $at, $zero, L_808002F4
    if (ctx->r1 == 0) {
        // 0x80800280: or          $s1, $s7, $zero
        ctx->r17 = ctx->r23 | 0;
            goto L_808002F4;
    }
    // 0x80800280: or          $s1, $s7, $zero
    ctx->r17 = ctx->r23 | 0;
    // 0x80800284: lh          $t9, 0x0($s6)
    ctx->r25 = MEM_H(ctx->r22, 0X0);
L_80800288:
    // 0x80800288: lh          $t1, 0x2($s6)
    ctx->r9 = MEM_H(ctx->r22, 0X2);
    // 0x8080028C: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80800290: addu        $s0, $t0, $fp
    ctx->r16 = ADD32(ctx->r8, ctx->r30);
    // 0x80800294: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80800298: addu        $s2, $t2, $s0
    ctx->r18 = ADD32(ctx->r10, ctx->r16);
    // 0x8080029C: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x808002A0: beql        $at, $zero, L_808002D0
    if (ctx->r1 == 0) {
        // 0x808002A4: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_808002D0;
    }
    goto skip_1;
    // 0x808002A4: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    skip_1:
L_808002A8:
    // 0x808002A8: lh          $a0, 0x0($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X0);
    // 0x808002AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808002B0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808002B4: jalr        $s5
    // 0x808002B8: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r21)(rdram, ctx);
        goto after_1;
    // 0x808002B8: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_1:
    // 0x808002BC: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x808002C0: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x808002C4: bne         $at, $zero, L_808002A8
    if (ctx->r1 != 0) {
        // 0x808002C8: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_808002A8;
    }
    // 0x808002C8: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x808002CC: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
L_808002D0:
    // 0x808002D0: sltu        $at, $s6, $s7
    ctx->r1 = ctx->r22 < ctx->r23 ? 1 : 0;
    // 0x808002D4: bnel        $at, $zero, L_80800288
    if (ctx->r1 != 0) {
        // 0x808002D8: lh          $t9, 0x0($s6)
        ctx->r25 = MEM_H(ctx->r22, 0X0);
            goto L_80800288;
    }
    goto skip_2;
    // 0x808002D8: lh          $t9, 0x0($s6)
    ctx->r25 = MEM_H(ctx->r22, 0X0);
    skip_2:
    // 0x808002DC: b           L_808002F8
    // 0x808002E0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_808002F8;
    // 0x808002E0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x808002E4: lw          $t3, 0x4($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X4);
L_808002E8:
    // 0x808002E8: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x808002EC: bne         $at, $zero, L_80800254
    if (ctx->r1 != 0) {
        // 0x808002F0: addu        $s3, $s3, $t3
        ctx->r19 = ADD32(ctx->r19, ctx->r11);
            goto L_80800254;
    }
    // 0x808002F0: addu        $s3, $s3, $t3
    ctx->r19 = ADD32(ctx->r19, ctx->r11);
L_808002F4:
    // 0x808002F4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_808002F8:
    // 0x808002F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002FC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800300: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800304: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800308: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8080030C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80800310: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80800314: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80800318: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8080031C: jr          $ra
    // 0x80800320: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800320: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80800E94_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800EA0: jal         0x80800CA4
    // 0x80800EA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800CA4_bstrexsmall(rdram, ctx);
        goto after_0;
    // 0x80800EA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800EA8: jal         0x80800448
    // 0x80800EAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstrexsmall_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800EAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800EB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800EB8: jr          $ra
    // 0x80800EBC: nop

    return;
    // 0x80800EBC: nop

;}
RECOMP_FUNC void heap_merge_free_block(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AF14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001AF18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001AF1C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001AF20: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001AF24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001AF28: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8001AF2C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8001AF30: jal         0x8001B3E8
    // 0x8001AF34: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    heap_bytes_allocated(rdram, ctx);
        goto after_0;
    // 0x8001AF34: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    after_0:
    // 0x8001AF38: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x8001AF3C: addiu       $s3, $s3, -0x1670
    ctx->r19 = ADD32(ctx->r19, -0X1670);
    // 0x8001AF40: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8001AF44: lw          $s2, 0x14($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X14);
    // 0x8001AF48: addu        $t6, $v0, $a0
    ctx->r14 = ADD32(ctx->r2, ctx->r4);
    // 0x8001AF4C: addiu       $t7, $t6, -0x20
    ctx->r15 = ADD32(ctx->r14, -0X20);
    // 0x8001AF50: sltu        $at, $s2, $t7
    ctx->r1 = ctx->r18 < ctx->r15 ? 1 : 0;
    // 0x8001AF54: beql        $at, $zero, L_8001AFE4
    if (ctx->r1 == 0) {
        // 0x8001AF58: lw          $v1, 0x10($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X10);
            goto L_8001AFE4;
    }
    goto skip_0;
    // 0x8001AF58: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    skip_0:
    // 0x8001AF5C: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
    // 0x8001AF60: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x8001AF64: subu        $t9, $t8, $s2
    ctx->r25 = SUB32(ctx->r24, ctx->r18);
    // 0x8001AF68: subu        $t1, $t0, $s0
    ctx->r9 = SUB32(ctx->r8, ctx->r16);
    // 0x8001AF6C: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001AF70: beql        $at, $zero, L_8001AFE4
    if (ctx->r1 == 0) {
        // 0x8001AF74: lw          $v1, 0x10($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X10);
            goto L_8001AFE4;
    }
    goto skip_1;
    // 0x8001AF74: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    skip_1:
    // 0x8001AF78: lw          $t2, 0x14($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X14);
L_8001AF7C:
    // 0x8001AF7C: sw          $t2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r10;
    // 0x8001AF80: lw          $t3, 0x14($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X14);
    // 0x8001AF84: sw          $s0, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r16;
    // 0x8001AF88: sw          $s0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r16;
    // 0x8001AF8C: lw          $t4, 0x10($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X10);
    // 0x8001AF90: sw          $s2, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r18;
    // 0x8001AF94: lw          $t5, 0x10($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X10);
    // 0x8001AF98: sw          $t5, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r13;
    // 0x8001AF9C: jal         0x8001B3E8
    // 0x8001AFA0: sw          $s2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r18;
    heap_bytes_allocated(rdram, ctx);
        goto after_1;
    // 0x8001AFA0: sw          $s2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r18;
    after_1:
    // 0x8001AFA4: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8001AFA8: lw          $s2, 0x14($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X14);
    // 0x8001AFAC: addu        $t6, $v0, $a0
    ctx->r14 = ADD32(ctx->r2, ctx->r4);
    // 0x8001AFB0: addiu       $t7, $t6, -0x20
    ctx->r15 = ADD32(ctx->r14, -0X20);
    // 0x8001AFB4: sltu        $at, $s2, $t7
    ctx->r1 = ctx->r18 < ctx->r15 ? 1 : 0;
    // 0x8001AFB8: beql        $at, $zero, L_8001AFE4
    if (ctx->r1 == 0) {
        // 0x8001AFBC: lw          $v1, 0x10($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X10);
            goto L_8001AFE4;
    }
    goto skip_2;
    // 0x8001AFBC: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    skip_2:
    // 0x8001AFC0: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x8001AFC4: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x8001AFC8: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8001AFCC: subu        $t1, $t9, $s1
    ctx->r9 = SUB32(ctx->r25, ctx->r17);
    // 0x8001AFD0: subu        $t0, $t8, $v0
    ctx->r8 = SUB32(ctx->r24, ctx->r2);
    // 0x8001AFD4: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001AFD8: bnel        $at, $zero, L_8001AF7C
    if (ctx->r1 != 0) {
        // 0x8001AFDC: lw          $t2, 0x14($s2)
        ctx->r10 = MEM_W(ctx->r18, 0X14);
            goto L_8001AF7C;
    }
    goto skip_3;
    // 0x8001AFDC: lw          $t2, 0x14($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X14);
    skip_3:
    // 0x8001AFE0: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
L_8001AFE4:
    // 0x8001AFE4: sltu        $at, $a0, $v1
    ctx->r1 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x8001AFE8: beql        $at, $zero, L_8001B06C
    if (ctx->r1 == 0) {
        // 0x8001AFEC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8001B06C;
    }
    goto skip_4;
    // 0x8001AFEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x8001AFF0: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x8001AFF4: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x8001AFF8: subu        $t3, $t2, $s0
    ctx->r11 = SUB32(ctx->r10, ctx->r16);
    // 0x8001AFFC: subu        $t5, $t4, $v1
    ctx->r13 = SUB32(ctx->r12, ctx->r3);
    // 0x8001B000: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8001B004: beql        $at, $zero, L_8001B06C
    if (ctx->r1 == 0) {
        // 0x8001B008: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8001B06C;
    }
    goto skip_5;
    // 0x8001B008: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x8001B00C: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
L_8001B010:
    // 0x8001B010: sw          $v1, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r3;
    // 0x8001B014: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8001B018: sw          $t7, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r15;
    // 0x8001B01C: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
    // 0x8001B020: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x8001B024: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
    // 0x8001B028: lw          $t9, 0x10($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X10);
    // 0x8001B02C: sw          $s0, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r16;
    // 0x8001B030: sw          $s0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r16;
    // 0x8001B034: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x8001B038: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x8001B03C: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x8001B040: beql        $at, $zero, L_8001B06C
    if (ctx->r1 == 0) {
        // 0x8001B044: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8001B06C;
    }
    goto skip_6;
    // 0x8001B044: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x8001B048: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x8001B04C: lw          $t1, 0x4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X4);
    // 0x8001B050: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x8001B054: subu        $t2, $t1, $s1
    ctx->r10 = SUB32(ctx->r9, ctx->r17);
    // 0x8001B058: subu        $t3, $t4, $v0
    ctx->r11 = SUB32(ctx->r12, ctx->r2);
    // 0x8001B05C: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8001B060: bnel        $at, $zero, L_8001B010
    if (ctx->r1 != 0) {
        // 0x8001B064: lw          $t6, 0x14($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X14);
            goto L_8001B010;
    }
    goto skip_7;
    // 0x8001B064: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    skip_7:
    // 0x8001B068: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001B06C:
    // 0x8001B06C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001B070: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001B074: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B078: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8001B07C: jr          $ra
    // 0x8001B080: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001B080: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800A21C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A21C0: jr          $ra
    // 0x800A21C4: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    return;
    // 0x800A21C4: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80802AF8_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802AF8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802AFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802B00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802B04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802B08: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80802B0C: jal         0x80106790
    // 0x80802B10: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80802B10: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80802B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802B18: jal         0x80802A50
    // 0x80802B1C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80802A50_chcollballcontrol(rdram, ctx);
        goto after_1;
    // 0x80802B1C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80802B20: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80802B24: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80802B28: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80802B2C: lw          $v0, 0x24($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X24);
    // 0x80802B30: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x80802B34: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x80802B38: srl         $t7, $v0, 22
    ctx->r15 = S32(U32(ctx->r2) >> 22);
    // 0x80802B3C: beq         $t7, $at, L_80802BAC
    if (ctx->r15 == ctx->r1) {
        // 0x80802B40: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80802BAC;
    }
    // 0x80802B40: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80802B44: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x80802B48: beq         $t7, $at, L_80802BC8
    if (ctx->r15 == ctx->r1) {
        // 0x80802B4C: addiu       $at, $zero, 0x44
        ctx->r1 = ADD32(0, 0X44);
            goto L_80802BC8;
    }
    // 0x80802B4C: addiu       $at, $zero, 0x44
    ctx->r1 = ADD32(0, 0X44);
    // 0x80802B50: bnel        $t7, $at, L_80802C18
    if (ctx->r15 != ctx->r1) {
        // 0x80802B54: lbu         $t9, 0x72($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X72);
            goto L_80802C18;
    }
    goto skip_0;
    // 0x80802B54: lbu         $t9, 0x72($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X72);
    skip_0:
    // 0x80802B58: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80802B5C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80802B60: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x80802B64: sll         $t0, $t8, 12
    ctx->r8 = S32(ctx->r24 << 12);
    // 0x80802B68: bgez        $t0, L_80802B94
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80802B6C: lui         $a1, 0x8080
        ctx->r5 = S32(RELOC_HI16(1840, 0X4F2C) << 16);
            goto L_80802B94;
    }
    // 0x80802B6C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1840, 0X4F2C) << 16);
    // 0x80802B70: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x80802B74: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1840, 0X4F2C) << 16);
    // 0x80802B78: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x80802B7C: lw          $a1, 0x4F2C($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(1840, 0X4F2C));
    // 0x80802B80: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80802B84: jal         0x80089AE0
    // 0x80802B88: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    _sukickball_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80802B88: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_2:
    // 0x80802B8C: b           L_80802C18
    // 0x80802B90: lbu         $t9, 0x72($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X72);
        goto L_80802C18;
    // 0x80802B90: lbu         $t9, 0x72($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X72);
L_80802B94:
    // 0x80802B94: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x80802B98: lw          $a1, 0x4F2C($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(1840, 0X4F2C));
    // 0x80802B9C: jal         0x80089AE0
    // 0x80802BA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _sukickball_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x80802BA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80802BA4: b           L_80802C18
    // 0x80802BA8: lbu         $t9, 0x72($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X72);
        goto L_80802C18;
    // 0x80802BA8: lbu         $t9, 0x72($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X72);
L_80802BAC:
    // 0x80802BAC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1840, 0X4F2C) << 16);
    // 0x80802BB0: addu        $a1, $a1, $t3
    ctx->r5 = ADD32(ctx->r5, ctx->r11);
    // 0x80802BB4: lw          $a1, 0x4F2C($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(1840, 0X4F2C));
    // 0x80802BB8: jal         0x80089AE0
    // 0x80802BBC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _sukickball_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x80802BBC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_4:
    // 0x80802BC0: b           L_80802C18
    // 0x80802BC4: lbu         $t9, 0x72($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X72);
        goto L_80802C18;
    // 0x80802BC4: lbu         $t9, 0x72($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X72);
L_80802BC8:
    // 0x80802BC8: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    // 0x80802BCC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80802BD0: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x80802BD4: sll         $t6, $t4, 12
    ctx->r14 = S32(ctx->r12 << 12);
    // 0x80802BD8: bgez        $t6, L_80802C04
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80802BDC: lui         $a1, 0x8080
        ctx->r5 = S32(RELOC_HI16(1840, 0X4F2C) << 16);
            goto L_80802C04;
    }
    // 0x80802BDC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1840, 0X4F2C) << 16);
    // 0x80802BE0: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80802BE4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1840, 0X4F2C) << 16);
    // 0x80802BE8: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x80802BEC: lw          $a1, 0x4F2C($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(1840, 0X4F2C));
    // 0x80802BF0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80802BF4: jal         0x80089AE0
    // 0x80802BF8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    _sukickball_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x80802BF8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // 0x80802BFC: b           L_80802C18
    // 0x80802C00: lbu         $t9, 0x72($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X72);
        goto L_80802C18;
    // 0x80802C00: lbu         $t9, 0x72($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X72);
L_80802C04:
    // 0x80802C04: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x80802C08: lw          $a1, 0x4F2C($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(1840, 0X4F2C));
    // 0x80802C0C: jal         0x80089AE0
    // 0x80802C10: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _sukickball_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x80802C10: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_6:
    // 0x80802C14: lbu         $t9, 0x72($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X72);
L_80802C18:
    // 0x80802C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802C1C: andi        $t0, $t9, 0xFF03
    ctx->r8 = ctx->r25 & 0XFF03;
    // 0x80802C20: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x80802C24: jal         0x80089CA8
    // 0x80802C28: sb          $t1, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r9;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x80802C28: sb          $t1, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r9;
    after_7:
    // 0x80802C2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802C30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802C34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802C38: jr          $ra
    // 0x80802C3C: nop

    return;
    // 0x80802C3C: nop

;}
RECOMP_FUNC void func_80100690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100690: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80100694: addiu       $a2, $a2, 0x5A60
    ctx->r6 = ADD32(ctx->r6, 0X5A60);
    // 0x80100698: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8010069C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801006A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801006A4: bne         $t6, $zero, L_801006C4
    if (ctx->r14 != 0) {
        // 0x801006A8: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_801006C4;
    }
    // 0x801006A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801006AC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x801006B0: jal         0x800B3268
    // 0x801006B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    freelist_new(rdram, ctx);
        goto after_0;
    // 0x801006B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x801006B8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x801006BC: addiu       $a2, $a2, 0x5A60
    ctx->r6 = ADD32(ctx->r6, 0X5A60);
    // 0x801006C0: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_801006C4:
    // 0x801006C4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801006C8: jal         0x800B3044
    // 0x801006CC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    freelist_next(rdram, ctx);
        goto after_1;
    // 0x801006CC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801006D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801006D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801006D8: jr          $ra
    // 0x801006DC: nop

    return;
    // 0x801006DC: nop

;}
RECOMP_FUNC void baswim_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080016C: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x80800170: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800174: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80800178: jal         0x8009F1C8
    // 0x8080017C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_0;
    // 0x8080017C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800180: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800184: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800188: jal         0x8009F1C8
    // 0x8080018C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_1;
    // 0x8080018C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x80800190: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800194: jal         0x808002B0
    // 0x80800198: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baswim_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800198: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x8080019C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001A0: jal         0x808002A0
    // 0x808001A4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baswim_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x808001A4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x808001A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001B0: jr          $ra
    // 0x808001B4: nop

    return;
    // 0x808001B4: nop

;}
RECOMP_FUNC void chskeletonexplode_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800D24: jal         0x80100094
    // 0x80800D28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800D28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800D2C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D30: sb          $t6, 0xF5($v0)
    MEM_B(0XF5, ctx->r2) = ctx->r14;
    // 0x80800D34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D3C: jr          $ra
    // 0x80800D40: nop

    return;
    // 0x80800D40: nop

;}
RECOMP_FUNC void _babuzz_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800847B8: syscall     120
    recomp_syscall_handler(rdram, ctx, 0x800847B8);
    return;
    // 0x800847BC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_808027D4_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808027D4: jr          $ra
    // 0x808027D8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808027D8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_808000A4_bsbreegullbash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808000A8: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x808000AC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808000B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(112, 0X54C) << 16);
    // 0x808000B4: lwc1        $f24, 0x54C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(112, 0X54C));
    // 0x808000B8: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x808000BC: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x808000C0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808000C4: c.lt.s      $f30, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f30.fl < ctx->f24.fl;
    // 0x808000C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000CC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x808000D0: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x808000D4: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x808000D8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808000DC: bc1f        L_8080012C
    if (!c1cs) {
        // 0x808000E0: mov.s       $f20, $f30
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    ctx->f20.fl = ctx->f30.fl;
            goto L_8080012C;
    }
    // 0x808000E0: mov.s       $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    ctx->f20.fl = ctx->f30.fl;
    // 0x808000E4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808000E8: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x808000EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(112, 0X550) << 16);
    // 0x808000F0: lwc1        $f26, 0x550($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(112, 0X550));
    // 0x808000F4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x808000F8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808000FC: nop

    // 0x80800100: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
L_80800104:
    // 0x80800104: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x80800108: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x8080010C: jal         0x80800000
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsbreegullbash(rdram, ctx);
        goto after_0;
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800114: add.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x80800118: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
    // 0x8080011C: nop

    // 0x80800120: bc1tl       L_80800104
    if (c1cs) {
        // 0x80800124: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_80800104;
    }
    goto skip_0;
    // 0x80800124: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_0:
    // 0x80800128: mov.s       $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    ctx->f20.fl = ctx->f30.fl;
L_8080012C:
    // 0x8080012C: c.lt.s      $f30, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f30.fl < ctx->f24.fl;
    // 0x80800130: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800134: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800138: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8080013C: bc1fl       L_80800190
    if (!c1cs) {
        // 0x80800140: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80800190;
    }
    goto skip_1;
    // 0x80800140: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_1:
    // 0x80800144: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80800148: lui         $at, 0x43D7
    ctx->r1 = S32(0X43D7 << 16);
    // 0x8080014C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80800150: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800154: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800158: nop

L_8080015C:
    // 0x8080015C: jal         0x800136E4
    // 0x80800160: add.s       $f12, $f20, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f26.fl;
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x80800160: add.s       $f12, $f20, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f26.fl;
    after_1:
    // 0x80800164: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800168: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x8080016C: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x80800170: jal         0x80800000
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsbreegullbash(rdram, ctx);
        goto after_2;
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800178: add.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x8080017C: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
    // 0x80800180: nop

    // 0x80800184: bc1t        L_8080015C
    if (c1cs) {
        // 0x80800188: nop
    
            goto L_8080015C;
    }
    // 0x80800188: nop

    // 0x8080018C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80800190:
    // 0x80800190: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800194: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800198: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8080019C: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808001A0: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x808001A4: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x808001A8: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x808001AC: jr          $ra
    // 0x808001B0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x808001B0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80800204_bsblongleg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800204: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800208: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080020C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800210: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800214: jal         0x8009E74C
    // 0x80800218: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_8009E74C(rdram, ctx);
        goto after_0;
    // 0x80800218: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x8080021C: bnel        $v0, $zero, L_808002C8
    if (ctx->r2 != 0) {
        // 0x80800220: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002C8;
    }
    goto skip_0;
    // 0x80800220: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800224: jal         0x80084420
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baalarm_free(rdram, ctx);
        goto after_1;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800230: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800234: jal         0x8009E53C
    // 0x80800238: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009E53C(rdram, ctx);
        goto after_2;
    // 0x80800238: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_2:
    // 0x8080023C: jal         0x8009F1E0
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_resetZones(rdram, ctx);
        goto after_3;
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800248: jal         0x800A0CF4
    // 0x8080024C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_4;
    // 0x8080024C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800254: jal         0x800A0CE8
    // 0x80800258: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CE8(rdram, ctx);
        goto after_5;
    // 0x80800258: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800260: jal         0x800A0DD0
    // 0x80800264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0DD0(rdram, ctx);
        goto after_6;
    // 0x80800264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080026C: jal         0x800931AC
    // 0x80800270: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800931AC(rdram, ctx);
        goto after_7;
    // 0x80800270: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800278: jal         0x8009BF5C
    // 0x8080027C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_8;
    // 0x8080027C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_8:
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800284: jal         0x8009C4CC
    // 0x80800288: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_9;
    // 0x80800288: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_9:
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800290: jal         0x80091788
    // 0x80800294: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_clear(rdram, ctx);
        goto after_10;
    // 0x80800294: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x80800298: jal         0x800C77DC
    // 0x8080029C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C77DC(rdram, ctx);
        goto after_11;
    // 0x8080029C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A4: jal         0x80095774
    // 0x808002A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    baflag_clear(rdram, ctx);
        goto after_12;
    // 0x808002A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_12:
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808002B4: jal         0x800852E8
    // 0x808002B8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    _batimer_incrementBy(rdram, ctx);
        goto after_13;
    // 0x808002B8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_13:
    // 0x808002BC: jal         0x808000C8
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000C8_bsblongleg(rdram, ctx);
        goto after_14;
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808002C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002C8:
    // 0x808002C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002D0: jr          $ra
    // 0x808002D4: nop

    return;
    // 0x808002D4: nop

;}
RECOMP_FUNC void _chpickups_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085858: syscall     177
    recomp_syscall_handler(rdram, ctx, 0x80085858);
    return;
    // 0x8008585C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800C1AA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1AA4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800C1AA8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C1AAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C1AB0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C1AB4: jal         0x800E3980
    // 0x800C1AB8: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    func_800E3980(rdram, ctx);
        goto after_0;
    // 0x800C1AB8: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    after_0:
    // 0x800C1ABC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800C1AC0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C1AC4: jal         0x800EFB24
    // 0x800C1AC8: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x800C1AC8: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    after_1:
    // 0x800C1ACC: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800C1AD0: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800C1AD4: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800C1AD8: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C1ADC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800C1AE0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C1AE4: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800C1AE8: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x800C1AEC: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C1AF0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800C1AF4: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800C1AF8: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800C1AFC: nop

    // 0x800C1B00: bc1fl       L_800C1B18
    if (!c1cs) {
        // 0x800C1B04: lbu         $t6, 0x1D($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X1D);
            goto L_800C1B18;
    }
    goto skip_0;
    // 0x800C1B04: lbu         $t6, 0x1D($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1D);
    skip_0:
    // 0x800C1B08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C1B0C: b           L_800C1CA0
    // 0x800C1B10: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
        goto L_800C1CA0;
    // 0x800C1B10: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x800C1B14: lbu         $t6, 0x1D($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1D);
L_800C1B18:
    // 0x800C1B18: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800C1B1C: bne         $t7, $zero, L_800C1C14
    if (ctx->r15 != 0) {
        // 0x800C1B20: sb          $t6, 0x1C($s0)
        MEM_B(0X1C, ctx->r16) = ctx->r14;
            goto L_800C1C14;
    }
    // 0x800C1B20: sb          $t6, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r14;
    // 0x800C1B24: jal         0x800E3A58
    // 0x800C1B28: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800E3A58(rdram, ctx);
        goto after_2;
    // 0x800C1B28: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x800C1B2C: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800C1B30: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800C1B34: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C1B38: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C1B3C: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C1B40: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800C1B44: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x800C1B48: neg.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = -ctx->f8.fl;
    // 0x800C1B4C: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x800C1B50: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800C1B54: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x800C1B58: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x800C1B5C: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x800C1B60: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x800C1B64: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800C1B68: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800C1B6C: jal         0x800EF7B0
    // 0x800C1B70: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800EF7B0(rdram, ctx);
        goto after_3;
    // 0x800C1B70: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x800C1B74: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800C1B78: jal         0x800F1EA4
    // 0x800C1B7C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800F1EA4(rdram, ctx);
        goto after_4;
    // 0x800C1B7C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_4:
    // 0x800C1B80: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C1B84: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800C1B88: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C1B8C: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x800C1B90: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C1B94: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800C1B98: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800C1B9C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800C1BA0: nop

    // 0x800C1BA4: bc1fl       L_800C1BE0
    if (!c1cs) {
        // 0x800C1BA8: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_800C1BE0;
    }
    goto skip_1;
    // 0x800C1BA8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_1:
    // 0x800C1BAC: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800C1BB0: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x800C1BB4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C1BB8: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C1BBC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800C1BC0: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800C1BC4: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x800C1BC8: lbu         $t8, 0x1B($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1B);
    // 0x800C1BCC: beql        $t8, $zero, L_800C1C18
    if (ctx->r24 == 0) {
        // 0x800C1BD0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C1C18;
    }
    goto skip_2;
    // 0x800C1BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x800C1BD4: b           L_800C1C14
    // 0x800C1BD8: sb          $t9, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r25;
        goto L_800C1C14;
    // 0x800C1BD8: sb          $t9, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r25;
    // 0x800C1BDC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_800C1BE0:
    // 0x800C1BE0: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800C1BE4: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C1BE8: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x800C1BEC: nop

    // 0x800C1BF0: bc1fl       L_800C1C18
    if (!c1cs) {
        // 0x800C1BF4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C1C18;
    }
    goto skip_3;
    // 0x800C1BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x800C1BF8: sub.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x800C1BFC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C1C00: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x800C1C04: lbu         $t0, 0x1B($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X1B);
    // 0x800C1C08: beql        $t0, $zero, L_800C1C18
    if (ctx->r8 == 0) {
        // 0x800C1C0C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C1C18;
    }
    goto skip_4;
    // 0x800C1C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x800C1C10: sb          $t1, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r9;
L_800C1C14:
    // 0x800C1C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C1C18:
    // 0x800C1C18: jal         0x800C13C4
    // 0x800C1C1C: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    func_800C13C4(rdram, ctx);
        goto after_5;
    // 0x800C1C1C: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_5:
    // 0x800C1C20: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    // 0x800C1C24: lbu         $a1, 0x60($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X60);
    // 0x800C1C28: lbu         $a2, 0x1B($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1B);
    // 0x800C1C2C: lbu         $a3, 0x1C($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X1C);
    // 0x800C1C30: jal         0x800C18C8
    // 0x800C1C34: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800C18C8(rdram, ctx);
        goto after_6;
    // 0x800C1C34: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_6:
    // 0x800C1C38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C1C3C: lwc1        $f8, 0x57D4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X57D4);
    // 0x800C1C40: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C1C44: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x800C1C48: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C1C4C: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800C1C50: lbu         $t3, 0x1A($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1A);
    // 0x800C1C54: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800C1C58: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800C1C5C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800C1C60: beql        $t3, $zero, L_800C1C94
    if (ctx->r11 == 0) {
        // 0x800C1C64: mtc1        $v0, $f8
        ctx->f8.u32l = ctx->r2;
            goto L_800C1C94;
    }
    goto skip_5;
    // 0x800C1C64: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    skip_5:
    // 0x800C1C68: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800C1C6C: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800C1C70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C1C74: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C1C78: lwc1        $f10, 0x57D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X57D8);
    // 0x800C1C7C: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800C1C80: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800C1C84: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800C1C88: b           L_800C1CA0
    // 0x800C1C8C: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
        goto L_800C1CA0;
    // 0x800C1C8C: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x800C1C90: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
L_800C1C94:
    // 0x800C1C94: nop

    // 0x800C1C98: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C1C9C: swc1        $f16, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f16.u32l;
L_800C1CA0:
    // 0x800C1CA0: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800C1CA4: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    // 0x800C1CA8: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800C1CAC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800C1CB0: jal         0x800C191C
    // 0x800C1CB4: nop

    func_800C191C(rdram, ctx);
        goto after_7;
    // 0x800C1CB4: nop

    after_7:
    // 0x800C1CB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C1CBC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C1CC0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800C1CC4: jr          $ra
    // 0x800C1CC8: nop

    return;
    // 0x800C1CC8: nop

;}
RECOMP_FUNC void func_80802CDC_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802CDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802CE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802CE4: jal         0x80100094
    // 0x80802CE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802CE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802CEC: sb          $zero, 0x42($v0)
    MEM_B(0X42, ctx->r2) = 0;
    // 0x80802CF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802CF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802CF8: jr          $ra
    // 0x80802CFC: nop

    return;
    // 0x80802CFC: nop

;}
RECOMP_FUNC void func_8080047C_chpowerhut(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080047C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800480: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800484: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800488: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8080048C: jal         0x80100094
    // 0x80800490: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800490: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800494: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800498: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8080049C: jal         0x80100094
    // 0x808004A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808004A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808004A4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808004A8: jal         0x800EFD24
    // 0x808004AC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x808004AC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x808004B0: jal         0x800DA298
    // 0x808004B4: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x808004B4: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_3:
    // 0x808004B8: beq         $v0, $zero, L_808005E4
    if (ctx->r2 == 0) {
        // 0x808004BC: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_808005E4;
    }
    // 0x808004BC: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x808004C0: lhu         $t7, 0x6($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X6);
    // 0x808004C4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808004C8: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x808004CC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x808004D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808004D4: bgez        $t7, L_808004EC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808004D8: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808004EC;
    }
    // 0x808004D8: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808004DC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808004E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808004E4: nop

    // 0x808004E8: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_808004EC:
    // 0x808004EC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x808004F0: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1076, 0X994) << 16);
    // 0x808004F4: addiu       $t2, $t2, 0x994
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1076, 0X994));
    // 0x808004F8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808004FC: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x80800500: addiu       $t9, $sp, 0x34
    ctx->r25 = ADD32(ctx->r29, 0X34);
    // 0x80800504: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x80800508: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8080050C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80800510: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800514: jal         0x80089870
    // 0x80800518: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    _sumumbofx_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80800518: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    after_4:
    // 0x8080051C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80800520: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800524: lhu         $v0, 0x72($t3)
    ctx->r2 = MEM_HU(ctx->r11, 0X72);
    // 0x80800528: srl         $t4, $v0, 10
    ctx->r12 = S32(U32(ctx->r2) >> 10);
    // 0x8080052C: beq         $t4, $at, L_80800544
    if (ctx->r12 == ctx->r1) {
        // 0x80800530: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800544;
    }
    // 0x80800530: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800534: beq         $t4, $at, L_80800598
    if (ctx->r12 == ctx->r1) {
        // 0x80800538: lw          $v0, 0x2C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X2C);
            goto L_80800598;
    }
    // 0x80800538: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8080053C: b           L_808005DC
    // 0x80800540: nop

        goto L_808005DC;
    // 0x80800540: nop

L_80800544:
    // 0x80800544: jal         0x800898E8
    // 0x80800548: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_5;
    // 0x80800548: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x8080054C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800550: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800554: lui         $a1, 0x3FEC
    ctx->r5 = S32(0X3FEC << 16);
    // 0x80800558: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x8080055C: nop

    // 0x80800560: bc1f        L_808005DC
    if (!c1cs) {
        // 0x80800564: nop
    
            goto L_808005DC;
    }
    // 0x80800564: nop

    // 0x80800568: jal         0x80089868
    // 0x8080056C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    _sumumbofx_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x8080056C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_6:
    // 0x80800570: beq         $v0, $zero, L_808005DC
    if (ctx->r2 == 0) {
        // 0x80800574: lw          $t5, 0x44($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X44);
            goto L_808005DC;
    }
    // 0x80800574: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80800578: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080057C: jal         0x800898C8
    // 0x80800580: lw          $a1, 0x8($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X8);
    _sumumbofx_entrypoint_17(rdram, ctx);
        goto after_7;
    // 0x80800580: lw          $a1, 0x8($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X8);
    after_7:
    // 0x80800584: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800588: jal         0x80101FDC
    // 0x8080058C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x8080058C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x80800590: b           L_808005DC
    // 0x80800594: nop

        goto L_808005DC;
    // 0x80800594: nop

L_80800598:
    // 0x80800598: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8080059C: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x808005A0: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x808005A4: lwc1        $f10, 0x8($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X8);
    // 0x808005A8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x808005AC: jal         0x800D9078
    // 0x808005B0: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    func_800D9078(rdram, ctx);
        goto after_9;
    // 0x808005B0: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    after_9:
    // 0x808005B4: beq         $v0, $zero, L_808005DC
    if (ctx->r2 == 0) {
        // 0x808005B8: nop
    
            goto L_808005DC;
    }
    // 0x808005B8: nop

    // 0x808005BC: jal         0x80086AF0
    // 0x808005C0: nop

    _chglowbo_entrypoint_6(rdram, ctx);
        goto after_10;
    // 0x808005C0: nop

    after_10:
    // 0x808005C4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808005C8: jal         0x800898C0
    // 0x808005CC: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    _sumumbofx_entrypoint_16(rdram, ctx);
        goto after_11;
    // 0x808005CC: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    after_11:
    // 0x808005D0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808005D4: jal         0x80101FDC
    // 0x808005D8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_12;
    // 0x808005D8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_12:
L_808005DC:
    // 0x808005DC: jal         0x800898B0
    // 0x808005E0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_13;
    // 0x808005E0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_13:
L_808005E4:
    // 0x808005E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005E8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808005EC: jr          $ra
    // 0x808005F0: nop

    return;
    // 0x808005F0: nop

;}
RECOMP_FUNC void _baspin_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085148: syscall     152
    recomp_syscall_handler(rdram, ctx, 0x80085148);
    return;
    // 0x8008514C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _ncbaclimb_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089268: syscall     768
    recomp_syscall_handler(rdram, ctx, 0x80089268);
    return;
    // 0x8008926C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void bainput_should_flap_flip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097E34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80097E38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097E3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80097E40: jal         0x80091A58
    // 0x80097E44: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x80097E44: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80097E48: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097E4C: beq         $t6, $zero, L_80097E64
    if (ctx->r14 == 0) {
        // 0x80097E50: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80097E64;
    }
    // 0x80097E50: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80097E54: jal         0x8008D370
    // 0x80097E58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008D370(rdram, ctx);
        goto after_1;
    // 0x80097E58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80097E5C: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097E60: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80097E64:
    // 0x80097E64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097E68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80097E6C: jr          $ra
    // 0x80097E70: nop

    return;
    // 0x80097E70: nop

;}
RECOMP_FUNC void func_800BA568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA568: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800BA56C: jr          $ra
    // 0x800BA570: sh          $a1, 0xAE($a0)
    MEM_H(0XAE, ctx->r4) = ctx->r5;
    return;
    // 0x800BA570: sh          $a1, 0xAE($a0)
    MEM_H(0XAE, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_808000AC_chloggo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000B8: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808000BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000C4: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808000C8: beq         $t6, $at, L_808000F0
    if (ctx->r14 == ctx->r1) {
        // 0x808000CC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000F0;
    }
    // 0x808000CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000D0: beq         $t6, $at, L_80800160
    if (ctx->r14 == ctx->r1) {
        // 0x808000D4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800160;
    }
    // 0x808000D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000D8: beq         $t6, $at, L_80800170
    if (ctx->r14 == ctx->r1) {
        // 0x808000DC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800170;
    }
    // 0x808000DC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808000E0: beq         $t6, $at, L_80800160
    if (ctx->r14 == ctx->r1) {
        // 0x808000E4: nop
    
            goto L_80800160;
    }
    // 0x808000E4: nop

    // 0x808000E8: b           L_8080019C
    // 0x808000EC: lbu         $t9, 0x94($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X94);
        goto L_8080019C;
    // 0x808000EC: lbu         $t9, 0x94($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X94);
L_808000F0:
    // 0x808000F0: jal         0x80800460
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800460_chloggo(rdram, ctx);
        goto after_0;
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808000F8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x808000FC: jal         0x800D0A9C
    // 0x80800100: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0A9C(rdram, ctx);
        goto after_1;
    // 0x80800100: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x80800104: beq         $v0, $zero, L_80800138
    if (ctx->r2 == 0) {
        // 0x80800108: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800138;
    }
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1292, 0X6D8) << 16);
    // 0x80800110: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1292, 0X610) << 16);
    // 0x80800114: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80800118: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080011C: addiu       $a3, $a3, 0x610
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1292, 0X610));
    // 0x80800120: addiu       $a2, $a2, 0x6D8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1292, 0X6D8));
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800128: jal         0x8008A1F0
    // 0x8080012C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x8080012C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x80800130: b           L_8080019C
    // 0x80800134: lbu         $t9, 0x94($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X94);
        goto L_8080019C;
    // 0x80800134: lbu         $t9, 0x94($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X94);
L_80800138:
    // 0x80800138: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1292, 0X6D8) << 16);
    // 0x8080013C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1292, 0X5E0) << 16);
    // 0x80800140: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80800144: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800148: addiu       $a3, $a3, 0x5E0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1292, 0X5E0));
    // 0x8080014C: addiu       $a2, $a2, 0x6D8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1292, 0X6D8));
    // 0x80800150: jal         0x8008A1F0
    // 0x80800154: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x80800154: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80800158: b           L_8080019C
    // 0x8080015C: lbu         $t9, 0x94($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X94);
        goto L_8080019C;
    // 0x8080015C: lbu         $t9, 0x94($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X94);
L_80800160:
    // 0x80800160: jal         0x80800460
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800460_chloggo(rdram, ctx);
        goto after_4;
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800168: b           L_8080019C
    // 0x8080016C: lbu         $t9, 0x94($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X94);
        goto L_8080019C;
    // 0x8080016C: lbu         $t9, 0x94($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X94);
L_80800170:
    // 0x80800170: jal         0x800F54E4
    // 0x80800174: nop

    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x80800174: nop

    after_5:
    // 0x80800178: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080017C: jal         0x800F52B8
    // 0x80800180: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800F52B8(rdram, ctx);
        goto after_6;
    // 0x80800180: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x80800184: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800188: beql        $v0, $at, L_8080019C
    if (ctx->r2 == ctx->r1) {
        // 0x8080018C: lbu         $t9, 0x94($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X94);
            goto L_8080019C;
    }
    goto skip_0;
    // 0x8080018C: lbu         $t9, 0x94($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X94);
    skip_0:
    // 0x80800190: jal         0x80800398
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800398_chloggo(rdram, ctx);
        goto after_7;
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800198: lbu         $t9, 0x94($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X94);
L_8080019C:
    // 0x8080019C: andi        $t0, $t9, 0xFFBF
    ctx->r8 = ctx->r25 & 0XFFBF;
    // 0x808001A0: sb          $t0, 0x94($s0)
    MEM_B(0X94, ctx->r16) = ctx->r8;
    // 0x808001A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808001A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001B0: jr          $ra
    // 0x808001B4: nop

    return;
    // 0x808001B4: nop

;}
RECOMP_FUNC void sumultiscore_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FD0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800FD4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800FD8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800FDC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80800FE0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800FE4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800FE8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800FEC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800FF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800FF4: lw          $v1, 0x518($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X518);
    // 0x80800FF8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800FFC: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x80801000: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80801004: blez        $v1, L_80801084
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80801008: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_80801084;
    }
    // 0x80801008: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8080100C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80801010:
    // 0x80801010: blez        $v0, L_80801070
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801014: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80801070;
    }
    // 0x80801014: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801018: sll         $t6, $s5, 2
    ctx->r14 = S32(ctx->r21 << 2);
    // 0x8080101C: addu        $t6, $t6, $s5
    ctx->r14 = ADD32(ctx->r14, ctx->r21);
    // 0x80801020: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80801024: subu        $t6, $t6, $s5
    ctx->r14 = SUB32(ctx->r14, ctx->r21);
    // 0x80801028: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080102C: addu        $s2, $s3, $t6
    ctx->r18 = ADD32(ctx->r19, ctx->r14);
    // 0x80801030: addiu       $s2, $s2, 0x28
    ctx->r18 = ADD32(ctx->r18, 0X28);
    // 0x80801034: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_80801038:
    // 0x80801038: lbu         $t7, 0x1E($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X1E);
    // 0x8080103C: sll         $t8, $s0, 5
    ctx->r24 = S32(ctx->r16 << 5);
    // 0x80801040: addu        $a1, $s2, $t8
    ctx->r5 = ADD32(ctx->r18, ctx->r24);
    // 0x80801044: bne         $s4, $t7, L_8080105C
    if (ctx->r20 != ctx->r15) {
        // 0x80801048: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080105C;
    }
    // 0x80801048: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080104C: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x80801050: jal         0x80801160
    // 0x80801054: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80801160_sumultiscore(rdram, ctx);
        goto after_0;
    // 0x80801054: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_0:
    // 0x80801058: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_8080105C:
    // 0x8080105C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801060: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801064: bne         $at, $zero, L_80801038
    if (ctx->r1 != 0) {
        // 0x80801068: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_80801038;
    }
    // 0x80801068: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x8080106C: lw          $v1, 0x518($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X518);
L_80801070:
    // 0x80801070: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80801074: slt         $at, $s5, $v1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80801078: bne         $at, $zero, L_80801010
    if (ctx->r1 != 0) {
        // 0x8080107C: nop
    
            goto L_80801010;
    }
    // 0x8080107C: nop

    // 0x80801080: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_80801084:
    // 0x80801084: jal         0x800B8C50
    // 0x80801088: nop

    func_800B8C50(rdram, ctx);
        goto after_1;
    // 0x80801088: nop

    after_1:
    // 0x8080108C: jal         0x800B8C98
    // 0x80801090: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800B8C98(rdram, ctx);
        goto after_2;
    // 0x80801090: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x80801094: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80801098: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8080109C: jal         0x800B8CBC
    // 0x808010A0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800B8CBC(rdram, ctx);
        goto after_3;
    // 0x808010A0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_3:
    // 0x808010A4: jal         0x800B7F14
    // 0x808010A8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800B7F14(rdram, ctx);
        goto after_4;
    // 0x808010A8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_4:
    // 0x808010AC: lw          $v1, 0x518($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X518);
    // 0x808010B0: blez        $v1, L_80801130
    if (SIGNED(ctx->r3) <= 0) {
        // 0x808010B4: nop
    
            goto L_80801130;
    }
    // 0x808010B4: nop

    // 0x808010B8: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_808010BC:
    // 0x808010BC: blez        $v0, L_80801120
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808010C0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80801120;
    }
    // 0x808010C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808010C4: sll         $t9, $s5, 2
    ctx->r25 = S32(ctx->r21 << 2);
    // 0x808010C8: addu        $t9, $t9, $s5
    ctx->r25 = ADD32(ctx->r25, ctx->r21);
    // 0x808010CC: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x808010D0: subu        $t9, $t9, $s5
    ctx->r25 = SUB32(ctx->r25, ctx->r21);
    // 0x808010D4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808010D8: addu        $s2, $s3, $t9
    ctx->r18 = ADD32(ctx->r19, ctx->r25);
    // 0x808010DC: addiu       $s2, $s2, 0x28
    ctx->r18 = ADD32(ctx->r18, 0X28);
    // 0x808010E0: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_808010E4:
    // 0x808010E4: lbu         $t0, 0x1E($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X1E);
    // 0x808010E8: sll         $t1, $s0, 5
    ctx->r9 = S32(ctx->r16 << 5);
    // 0x808010EC: addu        $a1, $s2, $t1
    ctx->r5 = ADD32(ctx->r18, ctx->r9);
    // 0x808010F0: bne         $s4, $t0, L_8080110C
    if (ctx->r20 != ctx->r8) {
        // 0x808010F4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080110C;
    }
    // 0x808010F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808010F8: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x808010FC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80801100: jal         0x808011E0
    // 0x80801104: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    func_808011E0_sumultiscore(rdram, ctx);
        goto after_5;
    // 0x80801104: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_5:
    // 0x80801108: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_8080110C:
    // 0x8080110C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801110: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801114: bne         $at, $zero, L_808010E4
    if (ctx->r1 != 0) {
        // 0x80801118: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_808010E4;
    }
    // 0x80801118: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x8080111C: lw          $v1, 0x518($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X518);
L_80801120:
    // 0x80801120: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80801124: slt         $at, $s5, $v1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80801128: bne         $at, $zero, L_808010BC
    if (ctx->r1 != 0) {
        // 0x8080112C: nop
    
            goto L_808010BC;
    }
    // 0x8080112C: nop

L_80801130:
    // 0x80801130: jal         0x800B811C
    // 0x80801134: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800B811C(rdram, ctx);
        goto after_6;
    // 0x80801134: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_6:
    // 0x80801138: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8080113C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801140: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80801144: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801148: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8080114C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80801150: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80801154: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80801158: jr          $ra
    // 0x8080115C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8080115C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800D8744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8744: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D8748: addiu       $v0, $v0, -0x4190
    ctx->r2 = ADD32(ctx->r2, -0X4190);
    // 0x800D874C: lbu         $t6, 0x1A8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1A8);
    // 0x800D8750: lwc1        $f4, 0x190($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X190);
    // 0x800D8754: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D8758: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D875C: beq         $t6, $zero, L_800D8778
    if (ctx->r14 == 0) {
        // 0x800D8760: swc1        $f4, 0x194($v0)
        MEM_W(0X194, ctx->r2) = ctx->f4.u32l;
            goto L_800D8778;
    }
    // 0x800D8760: swc1        $f4, 0x194($v0)
    MEM_W(0X194, ctx->r2) = ctx->f4.u32l;
    // 0x800D8764: jal         0x800885F8
    // 0x800D8768: nop

    _glintrosyncDll_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x800D8768: nop

    after_0:
    // 0x800D876C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D8770: b           L_800D8788
    // 0x800D8774: addiu       $v0, $v0, -0x4190
    ctx->r2 = ADD32(ctx->r2, -0X4190);
        goto L_800D8788;
    // 0x800D8774: addiu       $v0, $v0, -0x4190
    ctx->r2 = ADD32(ctx->r2, -0X4190);
L_800D8778:
    // 0x800D8778: jal         0x800D8FF8
    // 0x800D877C: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x800D877C: nop

    after_1:
    // 0x800D8780: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D8784: addiu       $v0, $v0, -0x4190
    ctx->r2 = ADD32(ctx->r2, -0X4190);
L_800D8788:
    // 0x800D8788: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800D878C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D8790: lwc1        $f6, 0x190($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X190);
    // 0x800D8794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D8798: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800D879C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D87A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D87A4: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800D87A8: jr          $ra
    // 0x800D87AC: swc1        $f16, -0x4000($at)
    MEM_W(-0X4000, ctx->r1) = ctx->f16.u32l;
    return;
    // 0x800D87AC: swc1        $f16, -0x4000($at)
    MEM_W(-0X4000, ctx->r1) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_800EC828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC828: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EC82C: addiu       $v0, $v0, 0x2ED0
    ctx->r2 = ADD32(ctx->r2, 0X2ED0);
    // 0x800EC830: lw          $t6, 0x259C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X259C);
    // 0x800EC834: addiu       $t9, $zero, 0x7FFF
    ctx->r25 = ADD32(0, 0X7FFF);
    // 0x800EC838: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800EC83C: slti        $at, $t7, 0x6B7
    ctx->r1 = SIGNED(ctx->r15) < 0X6B7 ? 1 : 0;
    // 0x800EC840: beq         $at, $zero, L_800EC84C
    if (ctx->r1 == 0) {
        // 0x800EC844: sw          $t7, 0x259C($v0)
        MEM_W(0X259C, ctx->r2) = ctx->r15;
            goto L_800EC84C;
    }
    // 0x800EC844: sw          $t7, 0x259C($v0)
    MEM_W(0X259C, ctx->r2) = ctx->r15;
    // 0x800EC848: sw          $t9, 0x259C($v0)
    MEM_W(0X259C, ctx->r2) = ctx->r25;
L_800EC84C:
    // 0x800EC84C: jr          $ra
    // 0x800EC850: nop

    return;
    // 0x800EC850: nop

;}
RECOMP_FUNC void func_80800AFC_cheggproximity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AFC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800B00: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800B04: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80800B08: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80800B0C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800B10: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800B14: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800B18: jal         0x80100094
    // 0x80800B1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800B1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800B20: lw          $t6, 0xA4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XA4);
    // 0x80800B24: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800B28: bnel        $t6, $zero, L_80800BD8
    if (ctx->r14 != 0) {
        // 0x80800B2C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80800BD8;
    }
    goto skip_0;
    // 0x80800B2C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x80800B30: jal         0x800F5898
    // 0x80800B34: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_800F5898(rdram, ctx);
        goto after_1;
    // 0x80800B34: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_1:
    // 0x80800B38: blez        $v0, L_80800BD4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800B3C: sll         $t7, $s1, 2
        ctx->r15 = S32(ctx->r17 << 2);
            goto L_80800BD4;
    }
    // 0x80800B3C: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80800B40: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800B44: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800B48: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800B4C: addu        $s0, $s2, $t7
    ctx->r16 = ADD32(ctx->r18, ctx->r15);
    // 0x80800B50: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800B54: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80800B58: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
L_80800B5C:
    // 0x80800B5C: beql        $s2, $t8, L_80800BC0
    if (ctx->r18 == ctx->r24) {
        // 0x80800B60: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800BC0;
    }
    goto skip_1;
    // 0x80800B60: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x80800B64: lw          $t9, 0x60($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X60);
    // 0x80800B68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B6C: bne         $s2, $t9, L_80800B94
    if (ctx->r18 != ctx->r25) {
        // 0x80800B70: nop
    
            goto L_80800B94;
    }
    // 0x80800B70: nop

    // 0x80800B74: jal         0x800F53D0
    // 0x80800B78: swc1        $f20, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f20.u32l;
    func_800F53D0(rdram, ctx);
        goto after_2;
    // 0x80800B78: swc1        $f20, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f20.u32l;
    after_2:
    // 0x80800B7C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800B80: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80800B84: jal         0x80085488
    // 0x80800B88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _bamotor_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800B88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800B8C: b           L_80800BC0
    // 0x80800B90: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80800BC0;
    // 0x80800B90: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800B94:
    // 0x80800B94: jal         0x800D9078
    // 0x80800B98: addiu       $a0, $s0, 0x80
    ctx->r4 = ADD32(ctx->r16, 0X80);
    func_800D9078(rdram, ctx);
        goto after_4;
    // 0x80800B98: addiu       $a0, $s0, 0x80
    ctx->r4 = ADD32(ctx->r16, 0X80);
    after_4:
    // 0x80800B9C: beq         $v0, $zero, L_80800BBC
    if (ctx->r2 == 0) {
        // 0x80800BA0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800BBC;
    }
    // 0x80800BA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800BA4: jal         0x800F53D0
    // 0x80800BA8: swc1        $f20, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f20.u32l;
    func_800F53D0(rdram, ctx);
        goto after_5;
    // 0x80800BA8: swc1        $f20, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f20.u32l;
    after_5:
    // 0x80800BAC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800BB0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80800BB4: jal         0x80085488
    // 0x80800BB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _bamotor_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x80800BB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
L_80800BBC:
    // 0x80800BBC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800BC0:
    // 0x80800BC0: jal         0x800F5898
    // 0x80800BC4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    func_800F5898(rdram, ctx);
        goto after_7;
    // 0x80800BC4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x80800BC8: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800BCC: bnel        $at, $zero, L_80800B5C
    if (ctx->r1 != 0) {
        // 0x80800BD0: lw          $t8, 0x40($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X40);
            goto L_80800B5C;
    }
    goto skip_2;
    // 0x80800BD0: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
    skip_2:
L_80800BD4:
    // 0x80800BD4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80800BD8:
    // 0x80800BD8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800BDC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800BE0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800BE4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80800BE8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80800BEC: jr          $ra
    // 0x80800BF0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800BF0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8001C070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C070: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001C074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C078: jal         0x8001BF80
    // 0x8001C07C: nop

    func_8001BF80(rdram, ctx);
        goto after_0;
    // 0x8001C07C: nop

    after_0:
    // 0x8001C080: beq         $v0, $zero, L_8001C090
    if (ctx->r2 == 0) {
        // 0x8001C084: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001C090;
    }
    // 0x8001C084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001C088: b           L_8001C094
    // 0x8001C08C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8001C094;
    // 0x8001C08C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001C090:
    // 0x8001C090: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001C094:
    // 0x8001C094: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001C098: jr          $ra
    // 0x8001C09C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001C09C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _badrone_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084808: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x80084808);
    return;
    // 0x8008480C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _gczoombox_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B60: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087B60);
    return;
    // 0x80087B64: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void _fxdialog_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088B30: syscall     725
    recomp_syscall_handler(rdram, ctx, 0x80088B30);
    return;
    // 0x80088B34: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8008B90C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B90C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8008B910: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8008B914: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008B918: lw          $t9, 0x6CC0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6CC0);
    // 0x8008B91C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8008B920: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8008B924: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8008B928: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8008B92C: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8008B930: lh          $t0, -0x6($v0)
    ctx->r8 = MEM_H(ctx->r2, -0X6);
    // 0x8008B934: addiu       $v0, $v0, -0x6
    ctx->r2 = ADD32(ctx->r2, -0X6);
    // 0x8008B938: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008B93C: beq         $t0, $zero, L_8008B94C
    if (ctx->r8 == 0) {
        // 0x8008B940: nop
    
            goto L_8008B94C;
    }
    // 0x8008B940: nop

    // 0x8008B944: jr          $ra
    // 0x8008B948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8008B948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008B94C:
    // 0x8008B94C: jr          $ra
    // 0x8008B950: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8008B950: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80800054_chintrocam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800054: jr          $ra
    // 0x80800058: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800058: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void boot___osEnqueueAndYield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_801039A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801039A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801039A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801039AC: lhu         $a1, 0x14($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X14);
    // 0x801039B0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x801039B4: beq         $a1, $zero, L_801039C4
    if (ctx->r5 == 0) {
        // 0x801039B8: nop
    
            goto L_801039C4;
    }
    // 0x801039B8: nop

    // 0x801039BC: bne         $a1, $at, L_801039CC
    if (ctx->r5 != ctx->r1) {
        // 0x801039C0: nop
    
            goto L_801039CC;
    }
    // 0x801039C0: nop

L_801039C4:
    // 0x801039C4: b           L_801039D4
    // 0x801039C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801039D4;
    // 0x801039C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801039CC:
    // 0x801039CC: jal         0x800D6B0C
    // 0x801039D0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800D6B0C(rdram, ctx);
        goto after_0;
    // 0x801039D0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
L_801039D4:
    // 0x801039D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801039D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801039DC: jr          $ra
    // 0x801039E0: nop

    return;
    // 0x801039E0: nop

;}
RECOMP_FUNC void _bsclimb_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082EF0: syscall     34
    recomp_syscall_handler(rdram, ctx, 0x80082EF0);
    return;
    // 0x80082EF4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void sucoaster_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D8C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800D90: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800D94: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800D98: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80800D9C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800DA0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800DA4: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80800DA8: jal         0x80100094
    // 0x80800DAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800DAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800DB0: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80800DB4: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x80800DB8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800DBC: srl         $t6, $a0, 28
    ctx->r14 = S32(U32(ctx->r4) >> 28);
    // 0x80800DC0: jal         0x8008A240
    // 0x80800DC4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    _sucoasterdata_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800DC4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x80800DC8: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800DCC: lw          $t7, 0x18($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X18);
    // 0x80800DD0: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80800DD4: bltzl       $t9, L_80800E10
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800DD8: lb          $t4, 0x19($s1)
        ctx->r12 = MEM_B(ctx->r17, 0X19);
            goto L_80800E10;
    }
    goto skip_0;
    // 0x80800DD8: lb          $t4, 0x19($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X19);
    skip_0:
    // 0x80800DDC: jal         0x80802760
    // 0x80800DE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80802760_sucoaster(rdram, ctx);
        goto after_2;
    // 0x80800DE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80800DE4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800DE8: beq         $v0, $at, L_80800E0C
    if (ctx->r2 == ctx->r1) {
        // 0x80800DEC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800E0C;
    }
    // 0x80800DEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800DF0: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80800DF4: jal         0x800F64A4
    // 0x80800DF8: lw          $a1, 0x3C($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X3C);
    func_800F64A4(rdram, ctx);
        goto after_3;
    // 0x80800DF8: lw          $a1, 0x3C($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X3C);
    after_3:
    // 0x80800DFC: beq         $v0, $zero, L_80800E0C
    if (ctx->r2 == 0) {
        // 0x80800E00: lw          $t1, 0x5C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X5C);
            goto L_80800E0C;
    }
    // 0x80800E00: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80800E04: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80800E08: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
L_80800E0C:
    // 0x80800E0C: lb          $t4, 0x19($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X19);
L_80800E10:
    // 0x80800E10: bltzl       $t4, L_80800E28
    if (SIGNED(ctx->r12) < 0) {
        // 0x80800E14: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E28;
    }
    goto skip_1;
    // 0x80800E14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800E18: jal         0x80089F78
    // 0x80800E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800E20: beq         $v0, $zero, L_80800EBC
    if (ctx->r2 == 0) {
        // 0x80800E24: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800EBC;
    }
    // 0x80800E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800E28:
    // 0x80800E28: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800E2C: jal         0x808021A8
    // 0x80800E30: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    func_808021A8_sucoaster(rdram, ctx);
        goto after_5;
    // 0x80800E30: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    after_5:
    // 0x80800E34: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x80800E38: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800E3C: lw          $a3, 0x54($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X54);
    // 0x80800E40: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80800E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E48: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80800E4C: jal         0x80089F90
    // 0x80800E50: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x80800E50: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_6:
    // 0x80800E54: bnel        $v0, $zero, L_80800EA8
    if (ctx->r2 != 0) {
        // 0x80800E58: lw          $t9, 0x50($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X50);
            goto L_80800EA8;
    }
    goto skip_2;
    // 0x80800E58: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    skip_2:
    // 0x80800E5C: lw          $t6, 0x18($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X18);
    // 0x80800E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E64: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800E68: sll         $t8, $t6, 6
    ctx->r24 = S32(ctx->r14 << 6);
    // 0x80800E6C: bltzl       $t8, L_80800EA8
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800E70: lw          $t9, 0x50($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X50);
            goto L_80800EA8;
    }
    goto skip_3;
    // 0x80800E70: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    skip_3:
    // 0x80800E74: jal         0x80801004
    // 0x80800E78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_7;
    // 0x80800E78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80800E7C: beq         $v0, $zero, L_80800EA4
    if (ctx->r2 == 0) {
        // 0x80800E80: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80800EA4;
    }
    // 0x80800E80: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800E84: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800E88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E90: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800E94: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800E98: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800E9C: jal         0x80802384
    // 0x80800EA0: nop

    func_80802384_sucoaster(rdram, ctx);
        goto after_8;
    // 0x80800EA0: nop

    after_8:
L_80800EA4:
    // 0x80800EA4: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
L_80800EA8:
    // 0x80800EA8: lbu         $t1, 0x19($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X19);
    // 0x80800EAC: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x80800EB0: andi        $t2, $t1, 0xFF7F
    ctx->r10 = ctx->r9 & 0XFF7F;
    // 0x80800EB4: sb          $t2, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r10;
    // 0x80800EB8: sb          $t0, 0x16($s1)
    MEM_B(0X16, ctx->r17) = ctx->r8;
L_80800EBC:
    // 0x80800EBC: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80800EC0: lbu         $a2, 0x16($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X16);
    // 0x80800EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EC8: lh          $t4, 0x50($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X50);
    // 0x80800ECC: lw          $a3, 0x4C($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X4C);
    // 0x80800ED0: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80800ED4: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80800ED8: nop

    // 0x80800EDC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800EE0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80800EE4: lh          $t5, 0x52($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X52);
    // 0x80800EE8: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80800EEC: nop

    // 0x80800EF0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800EF4: jal         0x80089F80
    // 0x80800EF8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    _subaddierouteDll_entrypoint_5(rdram, ctx);
        goto after_9;
    // 0x80800EF8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_9:
    // 0x80800EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F00: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800F04: jal         0x80800C68
    // 0x80800F08: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    func_80800C68_sucoaster(rdram, ctx);
        goto after_10;
    // 0x80800F08: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    after_10:
    // 0x80800F0C: jal         0x80801B88
    // 0x80800F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoaster_entrypoint_18(rdram, ctx);
        goto after_11;
    // 0x80800F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800F14: lui         $a1, 0x30
    ctx->r5 = S32(0X30 << 16);
    // 0x80800F18: ori         $a1, $a1, 0x5425
    ctx->r5 = ctx->r5 | 0X5425;
    // 0x80800F1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F20: jal         0x8010BA80
    // 0x80800F24: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_8010BA80(rdram, ctx);
        goto after_12;
    // 0x80800F24: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_12:
    // 0x80800F28: andi        $t6, $v0, 0x20
    ctx->r14 = ctx->r2 & 0X20;
    // 0x80800F2C: beq         $t6, $zero, L_80800F78
    if (ctx->r14 == 0) {
        // 0x80800F30: sw          $v0, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r2;
            goto L_80800F78;
    }
    // 0x80800F30: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80800F34: jal         0x8010AA54
    // 0x80800F38: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_8010AA54(rdram, ctx);
        goto after_13;
    // 0x80800F38: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_13:
    // 0x80800F3C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800F40: jal         0x800F1EA4
    // 0x80800F44: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800F1EA4(rdram, ctx);
        goto after_14;
    // 0x80800F44: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_14:
    // 0x80800F48: beq         $v0, $zero, L_80800FBC
    if (ctx->r2 == 0) {
        // 0x80800F4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FBC;
    }
    // 0x80800F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F50: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800F54: jal         0x80801004
    // 0x80800F58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_15;
    // 0x80800F58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_15:
    // 0x80800F5C: beq         $v0, $zero, L_80800FBC
    if (ctx->r2 == 0) {
        // 0x80800F60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FBC;
    }
    // 0x80800F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800F68: jal         0x80802384
    // 0x80800F6C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_80802384_sucoaster(rdram, ctx);
        goto after_16;
    // 0x80800F6C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_16:
    // 0x80800F70: b           L_80800FC0
    // 0x80800F74: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
        goto L_80800FC0;
    // 0x80800F74: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
L_80800F78:
    // 0x80800F78: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x80800F7C: beq         $t7, $zero, L_80800FBC
    if (ctx->r15 == 0) {
        // 0x80800F80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FBC;
    }
    // 0x80800F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F84: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800F88: jal         0x80801004
    // 0x80800F8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_17;
    // 0x80800F8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_17:
    // 0x80800F90: beq         $v0, $zero, L_80800FBC
    if (ctx->r2 == 0) {
        // 0x80800F94: lui         $at, 0x430C
        ctx->r1 = S32(0X430C << 16);
            goto L_80800FBC;
    }
    // 0x80800F94: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x80800F98: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800F9C: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x80800FA0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800FA4: jal         0x800DC178
    // 0x80800FA8: nop

    func_800DC178(rdram, ctx);
        goto after_18;
    // 0x80800FA8: nop

    after_18:
    // 0x80800FAC: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800FB0: jal         0x800136E4
    // 0x80800FB4: add.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_19;
    // 0x80800FB4: add.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f6.fl;
    after_19:
    // 0x80800FB8: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_80800FBC:
    // 0x80800FBC: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
L_80800FC0:
    // 0x80800FC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800FC4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800FC8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800FCC: andi        $t8, $v0, 0x24
    ctx->r24 = ctx->r2 & 0X24;
    // 0x80800FD0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80800FD4: jr          $ra
    // 0x80800FD8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80800FD8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void bsthrow_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800194: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080019C: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    // 0x808001A0: jal         0x8009E704
    // 0x808001A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bs_getNextState(rdram, ctx);
        goto after_0;
    // 0x808001A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001AC: bne         $v0, $at, L_808001D8
    if (ctx->r2 != ctx->r1) {
        // 0x808001B0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808001D8;
    }
    // 0x808001B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001B4: lui         $a2, 0x3E0F
    ctx->r6 = S32(0X3E0F << 16);
    // 0x808001B8: ori         $a2, $a2, 0x5C29
    ctx->r6 = ctx->r6 | 0X5C29;
    // 0x808001BC: jal         0x800917A8
    // 0x808001C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastatetimer_set(rdram, ctx);
        goto after_1;
    // 0x808001C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808001C4: lui         $a2, 0x3E8F
    ctx->r6 = S32(0X3E8F << 16);
    // 0x808001C8: ori         $a2, $a2, 0x5C29
    ctx->r6 = ctx->r6 | 0X5C29;
    // 0x808001CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001D0: jal         0x800917A8
    // 0x808001D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bastatetimer_set(rdram, ctx);
        goto after_2;
    // 0x808001D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_808001D8:
    // 0x808001D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001E0: jr          $ra
    // 0x808001E4: nop

    return;
    // 0x808001E4: nop

;}
RECOMP_FUNC void func_80800030_chburgerstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800034: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800038: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080003C: jal         0x80088848
    // 0x80800040: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800040: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800044: beq         $v0, $zero, L_8080005C
    if (ctx->r2 == 0) {
        // 0x80800048: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080005C;
    }
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080004C: jal         0x80102424
    // 0x80800050: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800050: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x80800054: b           L_8080007C
    // 0x80800058: lhu         $a1, 0x64($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X64);
        goto L_8080007C;
    // 0x80800058: lhu         $a1, 0x64($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X64);
L_8080005C:
    // 0x8080005C: jal         0x800DA298
    // 0x80800060: addiu       $a0, $zero, 0x9F
    ctx->r4 = ADD32(0, 0X9F);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800060: addiu       $a0, $zero, 0x9F
    ctx->r4 = ADD32(0, 0X9F);
    after_2:
    // 0x80800064: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80800068: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x8080006C: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x80800070: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80800074: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x80800078: lhu         $a1, 0x64($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X64);
L_8080007C:
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800080: andi        $t1, $a1, 0x1
    ctx->r9 = ctx->r5 & 0X1;
    // 0x80800084: jal         0x80103110
    // 0x80800088: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    func_80103110(rdram, ctx);
        goto after_3;
    // 0x80800088: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_3:
    // 0x8080008C: addiu       $a0, $zero, 0x32F
    ctx->r4 = ADD32(0, 0X32F);
    // 0x80800090: jal         0x80089C30
    // 0x80800094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800098: beq         $v0, $zero, L_808000B0
    if (ctx->r2 == 0) {
        // 0x8080009C: addiu       $a0, $s0, 0x18
        ctx->r4 = ADD32(ctx->r16, 0X18);
            goto L_808000B0;
    }
    // 0x8080009C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x808000A0: jal         0x800EE7F8
    // 0x808000A4: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x808000A4: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_5:
    // 0x808000A8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808000AC: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
L_808000B0:
    // 0x808000B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000BC: jr          $ra
    // 0x808000C0: nop

    return;
    // 0x808000C0: nop

;}
RECOMP_FUNC void bastick_getAngle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EEAC: lw          $t6, 0x128($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X128);
    // 0x8009EEB0: jr          $ra
    // 0x8009EEB4: lwc1        $f0, 0x5C($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X5C);
    return;
    // 0x8009EEB4: lwc1        $f0, 0x5C($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X5C);
;}
RECOMP_FUNC void func_800A52E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A52E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A52E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A52E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A52EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A52F0: jal         0x800F54E4
    // 0x800A52F4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800A52F4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800A52F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A52FC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800A5300: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5304: jal         0x800878F0
    // 0x800A5308: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    _plcamera_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x800A5308: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800A530C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5310: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5314: jr          $ra
    // 0x800A5318: nop

    return;
    // 0x800A5318: nop

    // 0x800A531C: nop

;}
RECOMP_FUNC void func_800FEC1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FEC1C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FEC20: jr          $ra
    // 0x800FEC24: swc1        $f12, 0x59F0($at)
    MEM_W(0X59F0, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x800FEC24: swc1        $f12, 0x59F0($at)
    MEM_W(0X59F0, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80800338_bsmummove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800338: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080033C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800340: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800344: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800348: jal         0x8008CABC
    // 0x8080034C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080034C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800350: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800354: jal         0x80083808
    // 0x80800358: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _bsmum_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800358: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8080035C: jal         0x8009E710
    // 0x80800360: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_2;
    // 0x80800360: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80800364: addiu       $at, $zero, 0xE7
    ctx->r1 = ADD32(0, 0XE7);
    // 0x80800368: bnel        $v0, $at, L_80800384
    if (ctx->r2 != ctx->r1) {
        // 0x8080036C: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80800384;
    }
    goto skip_0;
    // 0x8080036C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_0:
    // 0x80800370: jal         0x8008CAC8
    // 0x80800374: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_3;
    // 0x80800374: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80800378: b           L_8080038C
    // 0x8080037C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
        goto L_8080038C;
    // 0x8080037C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80800380: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80800384:
    // 0x80800384: nop

    // 0x80800388: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
L_8080038C:
    // 0x8080038C: jal         0x8008AF24
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_4;
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800398: jal         0x8008AED4
    // 0x8080039C: addiu       $a1, $zero, 0xB3
    ctx->r5 = ADD32(0, 0XB3);
    anctrl_setIndex(rdram, ctx);
        goto after_5;
    // 0x8080039C: addiu       $a1, $zero, 0xB3
    ctx->r5 = ADD32(0, 0XB3);
    after_5:
    // 0x808003A0: lui         $a1, 0x3EDC
    ctx->r5 = S32(0X3EDC << 16);
    // 0x808003A4: ori         $a1, $a1, 0x28F6
    ctx->r5 = ctx->r5 | 0X28F6;
    // 0x808003A8: jal         0x8008B1BC
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_6;
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B4: jal         0x8008B24C
    // 0x808003B8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    anctrl_setStart(rdram, ctx);
        goto after_7;
    // 0x808003B8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C0: jal         0x8008B134
    // 0x808003C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_8;
    // 0x808003C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x808003C8: jal         0x8008B064
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_9;
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808003D0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808003D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808003D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808003E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808003E4: jal         0x8009FFD8
    // 0x808003E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_10;
    // 0x808003E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x808003EC: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808003F0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808003F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003F8: jal         0x8008C9BC
    // 0x808003FC: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_11;
    // 0x808003FC: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_11:
    // 0x80800400: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800404: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800408: lui         $a3, 0x3F66
    ctx->r7 = S32(0X3F66 << 16);
    // 0x8080040C: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800410: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800414: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x80800418: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    // 0x8080041C: jal         0x8008C9F0
    // 0x80800420: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_12;
    // 0x80800420: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_12:
    // 0x80800424: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800428: jal         0x8008CA30
    // 0x8080042C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8008CA30(rdram, ctx);
        goto after_13;
    // 0x8080042C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_13:
    // 0x80800430: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800434: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800438: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8080043C: jr          $ra
    // 0x80800440: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800440: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80092DE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092DE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80092DE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80092DEC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80092DF0: jal         0x800921E0
    // 0x80092DF4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800921E0(rdram, ctx);
        goto after_0;
    // 0x80092DF4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80092DF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80092DFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80092E00: jr          $ra
    // 0x80092E04: nop

    return;
    // 0x80092E04: nop

;}
RECOMP_FUNC void bswalk_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080127C: jr          $ra
    // 0x80801280: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80801280: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
