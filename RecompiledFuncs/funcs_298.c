#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80801370_gcboundDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801370: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80801374: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80801378: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080137C: addu        $v1, $t6, $a1
    ctx->r3 = ADD32(ctx->r14, ctx->r5);
    // 0x80801380: bne         $a2, $zero, L_8080138C
    if (ctx->r6 != 0) {
        // 0x80801384: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8080138C;
    }
    // 0x80801384: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80801388: addiu       $a2, $a1, -0x1C
    ctx->r6 = ADD32(ctx->r5, -0X1C);
L_8080138C:
    // 0x8080138C: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    // 0x80801390: sltu        $at, $a2, $v1
    ctx->r1 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x80801394: beq         $at, $zero, L_808013C8
    if (ctx->r1 == 0) {
        // 0x80801398: lw          $v1, 0x10($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X10);
            goto L_808013C8;
    }
    // 0x80801398: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x8080139C: lw          $t7, 0x14($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X14);
L_808013A0:
    // 0x808013A0: beq         $a3, $t7, L_808013B0
    if (ctx->r7 == ctx->r15) {
        // 0x808013A4: nop
    
            goto L_808013B0;
    }
    // 0x808013A4: nop

    // 0x808013A8: beql        $v1, $zero, L_808013BC
    if (ctx->r3 == 0) {
        // 0x808013AC: addiu       $a2, $a2, 0x1C
        ctx->r6 = ADD32(ctx->r6, 0X1C);
            goto L_808013BC;
    }
    goto skip_0;
    // 0x808013AC: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    skip_0:
L_808013B0:
    // 0x808013B0: jr          $ra
    // 0x808013B4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    return;
    // 0x808013B4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x808013B8: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
L_808013BC:
    // 0x808013BC: sltu        $at, $a2, $v0
    ctx->r1 = ctx->r6 < ctx->r2 ? 1 : 0;
    // 0x808013C0: bnel        $at, $zero, L_808013A0
    if (ctx->r1 != 0) {
        // 0x808013C4: lw          $t7, 0x14($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X14);
            goto L_808013A0;
    }
    goto skip_1;
    // 0x808013C4: lw          $t7, 0x14($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X14);
    skip_1:
L_808013C8:
    // 0x808013C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808013CC: jr          $ra
    // 0x808013D0: nop

    return;
    // 0x808013D0: nop

;}
RECOMP_FUNC void suflamefx_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001DC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808001E0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x808001E4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x808001E8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808001EC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x808001F0: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x808001F4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808001F8: addiu       $s0, $a0, 0x20
    ctx->r16 = ADD32(ctx->r4, 0X20);
    // 0x808001FC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80800200: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80800204: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800208: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    // 0x8080020C: jal         0x800E3E8C
    // 0x80800210: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    func_800E3E8C(rdram, ctx);
        goto after_0;
    // 0x80800210: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    after_0:
    // 0x80800214: beql        $v0, $zero, L_808002BC
    if (ctx->r2 == 0) {
        // 0x80800218: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_808002BC;
    }
    goto skip_0;
    // 0x80800218: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x8080021C: jal         0x800D674C
    // 0x80800220: lh          $a0, 0x18($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X18);
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x80800220: lh          $a0, 0x18($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X18);
    after_1:
    // 0x80800224: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800228: jal         0x800E2588
    // 0x8080022C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E2588(rdram, ctx);
        goto after_2;
    // 0x8080022C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80800230: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800234: jal         0x800E2594
    // 0x80800238: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800E2594(rdram, ctx);
        goto after_3;
    // 0x80800238: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x8080023C: lbu         $v1, 0x1B($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X1B);
    // 0x80800240: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800244: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3150, 0X524) << 16);
    // 0x80800248: blez        $v1, L_808002B0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8080024C: addiu       $s2, $sp, 0x54
        ctx->r18 = ADD32(ctx->r29, 0X54);
            goto L_808002B0;
    }
    // 0x8080024C: addiu       $s2, $sp, 0x54
    ctx->r18 = ADD32(ctx->r29, 0X54);
    // 0x80800250: lwc1        $f20, 0x524($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3150, 0X524));
L_80800254:
    // 0x80800254: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800258: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8080025C: nop

    // 0x80800260: bc1fl       L_808002A4
    if (!c1cs) {
        // 0x80800264: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_808002A4;
    }
    goto skip_1;
    // 0x80800264: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x80800268: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080026C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800270: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800274: jal         0x800EFA4C
    // 0x80800278: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x80800278: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x8080027C: lbu         $a1, 0x2C($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X2C);
    // 0x80800280: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80800284: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800288: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8080028C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800290: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800294: jal         0x800E2720
    // 0x80800298: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    func_800E2720(rdram, ctx);
        goto after_5;
    // 0x80800298: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    after_5:
    // 0x8080029C: lbu         $v1, 0x1B($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X1B);
    // 0x808002A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_808002A4:
    // 0x808002A4: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x808002A8: bne         $at, $zero, L_80800254
    if (ctx->r1 != 0) {
        // 0x808002AC: addiu       $s0, $s0, 0x30
        ctx->r16 = ADD32(ctx->r16, 0X30);
            goto L_80800254;
    }
    // 0x808002AC: addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
L_808002B0:
    // 0x808002B0: jal         0x800E2A14
    // 0x808002B4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800E2A14(rdram, ctx);
        goto after_6;
    // 0x808002B4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_6:
    // 0x808002B8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_808002BC:
    // 0x808002BC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808002C0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808002C4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x808002C8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x808002CC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x808002D0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x808002D4: jr          $ra
    // 0x808002D8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x808002D8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void suexpressjoint_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000B0: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x808000B4: jal         0x80800000
    // 0x808000B8: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    func_80800000_suexpressjoint(rdram, ctx);
        goto after_0;
    // 0x808000B8: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    after_0:
    // 0x808000BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808000C0: bne         $v0, $at, L_808000D0
    if (ctx->r2 != ctx->r1) {
        // 0x808000C4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808000D0;
    }
    // 0x808000C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000C8: b           L_808000E4
    // 0x808000CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000E4;
    // 0x808000CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000D0:
    // 0x808000D0: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x808000D4: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(3134, 0X1824) << 16);
    // 0x808000D8: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x808000DC: lbu         $v1, 0x1824($v1)
    ctx->r3 = MEM_BU(ctx->r3, (int16_t)RELOC_LO16(3134, 0X1824));
    // 0x808000E0: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
L_808000E4:
    // 0x808000E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000EC: jr          $ra
    // 0x808000F0: nop

    return;
    // 0x808000F0: nop

;}
RECOMP_FUNC void gccollectDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080011C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800120: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800124: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800128: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080012C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800130: addiu       $s1, $zero, 0x9
    ctx->r17 = ADD32(0, 0X9);
L_80800134:
    // 0x80800134: jal         0x8080008C
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gccollectDll_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8080013C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800140: bne         $s0, $s1, L_80800134
    if (ctx->r16 != ctx->r17) {
        // 0x80800144: nop
    
            goto L_80800134;
    }
    // 0x80800144: nop

    // 0x80800148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080014C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800150: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800154: jr          $ra
    // 0x80800158: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800158: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _badata_entrypoint_32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084740: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x80084740);
    return;
    // 0x80084744: addi        $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
;}
RECOMP_FUNC void gcintrotext_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x800DA544
    // 0x8080000C: addiu       $a0, $zero, 0x6CB
    ctx->r4 = ADD32(0, 0X6CB);
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x8080000C: addiu       $a0, $zero, 0x6CB
    ctx->r4 = ADD32(0, 0X6CB);
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
RECOMP_FUNC void func_800A9CAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9CAC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A9CB0: lbu         $t6, 0x7760($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7760);
    // 0x800A9CB4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A9CB8: beq         $t6, $zero, L_800A9CC8
    if (ctx->r14 == 0) {
        // 0x800A9CBC: nop
    
            goto L_800A9CC8;
    }
    // 0x800A9CBC: nop

    // 0x800A9CC0: jr          $ra
    // 0x800A9CC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800A9CC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A9CC8:
    // 0x800A9CC8: jr          $ra
    // 0x800A9CCC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800A9CCC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800DACD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DACD0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800DACD4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DACD8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800DACDC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DACE0: addiu       $v0, $v0, -0x3828
    ctx->r2 = ADD32(ctx->r2, -0X3828);
    // 0x800DACE4: addiu       $v1, $v1, -0x3858
    ctx->r3 = ADD32(ctx->r3, -0X3858);
    // 0x800DACE8: swc1        $f0, -0x3860($at)
    MEM_W(-0X3860, ctx->r1) = ctx->f0.u32l;
    // 0x800DACEC: swc1        $f0, -0x385C($at)
    MEM_W(-0X385C, ctx->r1) = ctx->f0.u32l;
L_800DACF0:
    // 0x800DACF0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800DACF4: swc1        $f0, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f0.u32l;
    // 0x800DACF8: swc1        $f0, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f0.u32l;
    // 0x800DACFC: swc1        $f0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f0.u32l;
    // 0x800DAD00: bne         $v1, $v0, L_800DACF0
    if (ctx->r3 != ctx->r2) {
        // 0x800DAD04: swc1        $f0, -0x10($v1)
        MEM_W(-0X10, ctx->r3) = ctx->f0.u32l;
            goto L_800DACF0;
    }
    // 0x800DAD04: swc1        $f0, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f0.u32l;
    // 0x800DAD08: jr          $ra
    // 0x800DAD0C: nop

    return;
    // 0x800DAD0C: nop

;}
RECOMP_FUNC void func_80800184_baflameline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800184: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800188: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8080018C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800190: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800194: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800198: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
    // 0x8080019C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(520, 0X6D8) << 16);
    // 0x808001A0: lwc1        $f6, 0x6D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(520, 0X6D8));
    // 0x808001A4: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x808001A8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808001AC: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
    // 0x808001B0: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808001B4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808001B8: jal         0x800EFA20
    // 0x808001BC: nop

    func_800EFA20(rdram, ctx);
        goto after_0;
    // 0x808001BC: nop

    after_0:
    // 0x808001C0: lw          $t6, 0x84($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X84);
    // 0x808001C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(520, 0X6DC) << 16);
    // 0x808001C8: lwc1        $f16, 0x6DC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(520, 0X6DC));
    // 0x808001CC: lwc1        $f10, 0x18($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X18);
    // 0x808001D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(520, 0X6E0) << 16);
    // 0x808001D4: lwc1        $f4, 0x6E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(520, 0X6E0));
    // 0x808001D8: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808001DC: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808001E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(520, 0X6E4) << 16);
    // 0x808001E4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808001E8: lwc1        $f14, 0x6E4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(520, 0X6E4));
    // 0x808001EC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808001F0: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x808001F4: jal         0x800DC178
    // 0x808001F8: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x808001F8: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x808001FC: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800200: lw          $t7, 0x84($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X84);
    // 0x80800204: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800208: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080020C: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80800210: lw          $a0, 0x1C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X1C);
    // 0x80800214: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x80800218: jal         0x800BA77C
    // 0x8080021C: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    func_800BA77C(rdram, ctx);
        goto after_2;
    // 0x8080021C: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    after_2:
    // 0x80800220: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800224: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800228: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8080022C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800230: lw          $t1, 0x84($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X84);
    // 0x80800234: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800238: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8080023C: lw          $a0, 0x1C($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X1C);
    // 0x80800240: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800244: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800248: sll         $t3, $a1, 16
    ctx->r11 = S32(ctx->r5 << 16);
    // 0x8080024C: sra         $a1, $t3, 16
    ctx->r5 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80800250: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80800254: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x80800258: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8080025C: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x80800260: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80800264: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80800268: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x8080026C: jal         0x800BA930
    // 0x80800270: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    func_800BA930(rdram, ctx);
        goto after_3;
    // 0x80800270: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    after_3:
    // 0x80800274: lw          $t1, 0x84($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X84);
    // 0x80800278: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(520, 0X738) << 16);
    // 0x8080027C: addiu       $t2, $t2, 0x738
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(520, 0X738));
    // 0x80800280: lw          $a0, 0x1C($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X1C);
    // 0x80800284: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800288: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8080028C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800290: jal         0x800BABB8
    // 0x80800294: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x80800294: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x80800298: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8080029C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808002A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808002A4: jr          $ra
    // 0x808002A8: nop

    return;
    // 0x808002A8: nop

;}
RECOMP_FUNC void boot_osCreatePiManager(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80800540_chmayafarmer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800540: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800544: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800548: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080054C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800550: jal         0x8010D254
    // 0x80800554: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x80800554: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x80800558: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x8080055C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800560: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80800564: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80800568: bltzl       $t8, L_8080059C
    if (SIGNED(ctx->r24) < 0) {
        // 0x8080056C: lbu         $t2, 0x65($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X65);
            goto L_8080059C;
    }
    goto skip_0;
    // 0x8080056C: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    skip_0:
    // 0x80800570: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800574: nop

    // 0x80800578: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080057C: nop

    // 0x80800580: bc1fl       L_8080059C
    if (!c1cs) {
        // 0x80800584: lbu         $t2, 0x65($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X65);
            goto L_8080059C;
    }
    goto skip_1;
    // 0x80800584: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    skip_1:
    // 0x80800588: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x8080058C: andi        $t0, $t9, 0xFFFE
    ctx->r8 = ctx->r25 & 0XFFFE;
    // 0x80800590: b           L_80800848
    // 0x80800594: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
        goto L_80800848;
    // 0x80800594: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x80800598: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
L_8080059C:
    // 0x8080059C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808005A4: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x808005A8: jal         0x80100094
    // 0x808005AC: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808005AC: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    after_1:
    // 0x808005B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005B4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x808005B8: jal         0x800897D8
    // 0x808005BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x808005BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x808005C0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808005C4: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    // 0x808005C8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x808005CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808005D0: lui         $a1, 0x430C
    ctx->r5 = S32(0X430C << 16);
    // 0x808005D4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808005D8: jal         0x80089F20
    // 0x808005DC: lui         $a3, 0x42DC
    ctx->r7 = S32(0X42DC << 16);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808005DC: lui         $a3, 0x42DC
    ctx->r7 = S32(0X42DC << 16);
    after_3:
    // 0x808005E0: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x808005E4: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x808005E8: bltzl       $t7, L_808006B4
    if (SIGNED(ctx->r15) < 0) {
        // 0x808005EC: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_808006B4;
    }
    goto skip_2;
    // 0x808005EC: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_2:
    // 0x808005F0: jal         0x80090178
    // 0x808005F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090178(rdram, ctx);
        goto after_4;
    // 0x808005F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x808005F8: beq         $v0, $zero, L_808006B0
    if (ctx->r2 == 0) {
        // 0x808005FC: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_808006B0;
    }
    // 0x808005FC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800600: jal         0x800D0A9C
    // 0x80800604: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_5;
    // 0x80800604: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800608: bnel        $v0, $zero, L_808006B4
    if (ctx->r2 != 0) {
        // 0x8080060C: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_808006B4;
    }
    goto skip_3;
    // 0x8080060C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_3:
    // 0x80800610: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800614: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80800618: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8080061C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800620: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800624: addiu       $a2, $zero, 0x15E
    ctx->r6 = ADD32(0, 0X15E);
    // 0x80800628: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    // 0x8080062C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800630: jal         0x8008A1C8
    // 0x80800634: nop

    _subaddiedialog_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800634: nop

    after_6:
    // 0x80800638: beq         $v0, $zero, L_80800674
    if (ctx->r2 == 0) {
        // 0x8080063C: addiu       $a0, $zero, 0x4D
        ctx->r4 = ADD32(0, 0X4D);
            goto L_80800674;
    }
    // 0x8080063C: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    // 0x80800640: jal         0x800DA9E4
    // 0x80800644: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_7;
    // 0x80800644: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800648: bne         $v0, $zero, L_80800674
    if (ctx->r2 != 0) {
        // 0x8080064C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800674;
    }
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800650: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800654: jal         0x80800000
    // 0x80800658: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800000_chmayafarmer(rdram, ctx);
        goto after_8;
    // 0x80800658: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x8080065C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800660: addiu       $a1, $zero, 0xF06
    ctx->r5 = ADD32(0, 0XF06);
    // 0x80800664: jal         0x80800180
    // 0x80800668: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_80800180_chmayafarmer(rdram, ctx);
        goto after_9;
    // 0x80800668: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_9:
    // 0x8080066C: b           L_808006B4
    // 0x80800670: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
        goto L_808006B4;
    // 0x80800670: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_80800674:
    // 0x80800674: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800678: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x8080067C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800680: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800684: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800688: addiu       $a2, $zero, 0x15E
    ctx->r6 = ADD32(0, 0X15E);
    // 0x8080068C: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    // 0x80800690: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800694: jal         0x8008A1E0
    // 0x80800698: nop

    _subaddiedialog_entrypoint_6(rdram, ctx);
        goto after_10;
    // 0x80800698: nop

    after_10:
    // 0x8080069C: beq         $v0, $zero, L_808006B0
    if (ctx->r2 == 0) {
        // 0x808006A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006B0;
    }
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A4: addiu       $a1, $zero, 0xF08
    ctx->r5 = ADD32(0, 0XF08);
    // 0x808006A8: jal         0x80800180
    // 0x808006AC: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_80800180_chmayafarmer(rdram, ctx);
        goto after_11;
    // 0x808006AC: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_11:
L_808006B0:
    // 0x808006B0: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_808006B4:
    // 0x808006B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808006B8: srl         $t2, $v0, 10
    ctx->r10 = S32(U32(ctx->r2) >> 10);
    // 0x808006BC: beq         $t2, $at, L_808006E4
    if (ctx->r10 == ctx->r1) {
        // 0x808006C0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808006E4;
    }
    // 0x808006C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808006C4: beq         $t2, $at, L_80800708
    if (ctx->r10 == ctx->r1) {
        // 0x808006C8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800708;
    }
    // 0x808006C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808006CC: beq         $t2, $at, L_808007C0
    if (ctx->r10 == ctx->r1) {
        // 0x808006D0: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_808007C0;
    }
    // 0x808006D0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808006D4: beq         $t2, $at, L_80800828
    if (ctx->r10 == ctx->r1) {
        // 0x808006D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800828;
    }
    // 0x808006D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006DC: b           L_8080084C
    // 0x808006E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080084C;
    // 0x808006E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006E4:
    // 0x808006E4: lhu         $t3, 0x76($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X76);
    // 0x808006E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006EC: srl         $t4, $t3, 7
    ctx->r12 = S32(U32(ctx->r11) >> 7);
    // 0x808006F0: bgtzl       $t4, L_8080084C
    if (SIGNED(ctx->r12) > 0) {
        // 0x808006F4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080084C;
    }
    goto skip_4;
    // 0x808006F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x808006F8: jal         0x808001CC
    // 0x808006FC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808001CC_chmayafarmer(rdram, ctx);
        goto after_12;
    // 0x808006FC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_12:
    // 0x80800700: b           L_8080084C
    // 0x80800704: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080084C;
    // 0x80800704: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800708:
    // 0x80800708: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1612, 0X11B4) << 16);
    // 0x8080070C: lwc1        $f6, 0x11B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1612, 0X11B4));
    // 0x80800710: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800714: lui         $a1, 0x3D75
    ctx->r5 = S32(0X3D75 << 16);
    // 0x80800718: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    // 0x8080071C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800724: jal         0x80101E14
    // 0x80800728: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    func_80101E14(rdram, ctx);
        goto after_13;
    // 0x80800728: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    after_13:
    // 0x8080072C: bne         $v0, $zero, L_80800744
    if (ctx->r2 != 0) {
        // 0x80800730: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800744;
    }
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800734: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80800738: jal         0x80101E14
    // 0x8080073C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80101E14(rdram, ctx);
        goto after_14;
    // 0x8080073C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_14:
    // 0x80800740: beq         $v0, $zero, L_80800758
    if (ctx->r2 == 0) {
        // 0x80800744: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1612, 0X1210) << 16);
            goto L_80800758;
    }
L_80800744:
    // 0x80800744: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1612, 0X1210) << 16);
    // 0x80800748: addiu       $a2, $a2, 0x1210
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1612, 0X1210));
    // 0x8080074C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800750: jal         0x80089D18
    // 0x80800754: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_15;
    // 0x80800754: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_15:
L_80800758:
    // 0x80800758: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x8080075C: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x80800760: jal         0x80101E14
    // 0x80800764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_16;
    // 0x80800764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800768: beq         $v0, $zero, L_80800848
    if (ctx->r2 == 0) {
        // 0x8080076C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800848;
    }
    // 0x8080076C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800770: jal         0x80100094
    // 0x80800774: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_17;
    // 0x80800774: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80800778: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080077C: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x80800780: jal         0x800897E8
    // 0x80800784: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_18;
    // 0x80800784: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_18:
    // 0x80800788: lhu         $t5, 0x76($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X76);
    // 0x8080078C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800794: srl         $t6, $t5, 7
    ctx->r14 = S32(U32(ctx->r13) >> 7);
    // 0x80800798: bgtz        $t6, L_808007B0
    if (SIGNED(ctx->r14) > 0) {
        // 0x8080079C: nop
    
            goto L_808007B0;
    }
    // 0x8080079C: nop

    // 0x808007A0: jal         0x808001CC
    // 0x808007A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001CC_chmayafarmer(rdram, ctx);
        goto after_19;
    // 0x808007A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808007A8: b           L_8080084C
    // 0x808007AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080084C;
    // 0x808007AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808007B0:
    // 0x808007B0: jal         0x808001CC
    // 0x808007B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808001CC_chmayafarmer(rdram, ctx);
        goto after_20;
    // 0x808007B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x808007B8: b           L_8080084C
    // 0x808007BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080084C;
    // 0x808007BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808007C0:
    // 0x808007C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808007C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808007C8: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808007CC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x808007D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808007D4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808007D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007DC: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    // 0x808007E0: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808007E4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808007E8: nop

    // 0x808007EC: bc1fl       L_80800800
    if (!c1cs) {
        // 0x808007F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800800;
    }
    goto skip_5;
    // 0x808007F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
    // 0x808007F4: jal         0x808001CC
    // 0x808007F8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808001CC_chmayafarmer(rdram, ctx);
        goto after_21;
    // 0x808007F8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_21:
    // 0x808007FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800800:
    // 0x80800800: jal         0x80101E14
    // 0x80800804: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    func_80101E14(rdram, ctx);
        goto after_22;
    // 0x80800804: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_22:
    // 0x80800808: beq         $v0, $zero, L_80800848
    if (ctx->r2 == 0) {
        // 0x8080080C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800848;
    }
    // 0x8080080C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800810: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1612, 0X1220) << 16);
    // 0x80800814: addiu       $a2, $a2, 0x1220
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1612, 0X1220));
    // 0x80800818: jal         0x80089D18
    // 0x8080081C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_23;
    // 0x8080081C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_23:
    // 0x80800820: b           L_8080084C
    // 0x80800824: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080084C;
    // 0x80800824: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800828:
    // 0x80800828: jal         0x80101E14
    // 0x8080082C: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    func_80101E14(rdram, ctx);
        goto after_24;
    // 0x8080082C: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_24:
    // 0x80800830: beq         $v0, $zero, L_80800848
    if (ctx->r2 == 0) {
        // 0x80800834: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800848;
    }
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800838: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1612, 0X1220) << 16);
    // 0x8080083C: addiu       $a2, $a2, 0x1220
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1612, 0X1220));
    // 0x80800840: jal         0x80089D18
    // 0x80800844: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_25;
    // 0x80800844: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_25:
L_80800848:
    // 0x80800848: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080084C:
    // 0x8080084C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800850: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800854: jr          $ra
    // 0x80800858: nop

    return;
    // 0x80800858: nop

;}
RECOMP_FUNC void bawasher_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x34
    ctx->r2 = ADD32(0, 0X34);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x34
    ctx->r2 = ADD32(0, 0X34);
;}
RECOMP_FUNC void _chfiregen_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800869F8: syscall     404
    recomp_syscall_handler(rdram, ctx, 0x800869F8);
    return;
    // 0x800869FC: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_800A34F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A34F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A34F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A34F8: lw          $a0, 0xA0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XA0);
    // 0x800A34FC: jal         0x800EE7F8
    // 0x800A3500: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800A3500: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x800A3504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A3508: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A350C: jr          $ra
    // 0x800A3510: nop

    return;
    // 0x800A3510: nop

;}
RECOMP_FUNC void func_80800354_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800354: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800358: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080035C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800360: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800364: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800368: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080036C: lh          $t9, 0x36($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X36);
    // 0x80800370: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80800374: bgez        $t8, L_80800384
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800378: addiu       $at, $zero, 0xCEB
        ctx->r1 = ADD32(0, 0XCEB);
            goto L_80800384;
    }
    // 0x80800378: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x8080037C: b           L_80800388
    // 0x80800380: addiu       $v0, $zero, 0x77
    ctx->r2 = ADD32(0, 0X77);
        goto L_80800388;
    // 0x80800380: addiu       $v0, $zero, 0x77
    ctx->r2 = ADD32(0, 0X77);
L_80800384:
    // 0x80800384: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_80800388:
    // 0x80800388: beq         $a2, $zero, L_80800394
    if (ctx->r6 == 0) {
        // 0x8080038C: lh          $a0, 0x36($sp)
        ctx->r4 = MEM_H(ctx->r29, 0X36);
            goto L_80800394;
    }
    // 0x8080038C: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    // 0x80800390: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80800394:
    // 0x80800394: bne         $t9, $at, L_808003A4
    if (ctx->r25 != ctx->r1) {
        // 0x80800398: addiu       $a2, $s0, 0x4
        ctx->r6 = ADD32(ctx->r16, 0X4);
            goto L_808003A4;
    }
    // 0x80800398: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x8080039C: b           L_808003A8
    // 0x808003A0: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
        goto L_808003A8;
    // 0x808003A0: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
L_808003A4:
    // 0x808003A4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
L_808003A8:
    // 0x808003A8: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x808003AC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x808003B0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808003B4: jal         0x800C05B8
    // 0x808003B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800C05B8(rdram, ctx);
        goto after_0;
    // 0x808003B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x808003BC: lbu         $t1, 0x74($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X74);
    // 0x808003C0: ori         $t2, $t1, 0x40
    ctx->r10 = ctx->r9 | 0X40;
    // 0x808003C4: sb          $t2, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r10;
    // 0x808003C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808003CC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808003D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808003D4: jr          $ra
    // 0x808003D8: nop

    return;
    // 0x808003D8: nop

;}
RECOMP_FUNC void chbaddiesetup_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800130: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800138: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080013C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800140: jal         0x800A5D60
    // 0x80800144: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800A5D60(rdram, ctx);
        goto after_0;
    // 0x80800144: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800148: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080014C: jal         0x80800000
    // 0x80800150: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80800000_chbaddiesetup(rdram, ctx);
        goto after_1;
    // 0x80800150: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800154: beq         $v0, $zero, L_808001C8
    if (ctx->r2 == 0) {
        // 0x80800158: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_808001C8;
    }
    // 0x80800158: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080015C: lbu         $t8, 0x4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4);
    // 0x80800160: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80800164: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800168: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x8080016C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80800170: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80800174: lbu         $t3, 0x4($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X4);
    // 0x80800178: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8080017C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80800180: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x80800184: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80800188: sw          $t1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r9;
    // 0x8080018C: lbu         $t9, 0x4($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X4);
    // 0x80800190: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80800194: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80800198: sll         $t6, $t9, 5
    ctx->r14 = S32(ctx->r25 << 5);
    // 0x8080019C: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x808001A0: sw          $t8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r24;
    // 0x808001A4: lbu         $t4, 0x4($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X4);
    // 0x808001A8: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x808001AC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x808001B0: sll         $t1, $t4, 5
    ctx->r9 = S32(ctx->r12 << 5);
    // 0x808001B4: addu        $t5, $t2, $t1
    ctx->r13 = ADD32(ctx->r10, ctx->r9);
    // 0x808001B8: sw          $t3, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->r11;
    // 0x808001BC: lbu         $t9, 0x4($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X4);
    // 0x808001C0: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x808001C4: sb          $t7, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r15;
L_808001C8:
    // 0x808001C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001D0: jr          $ra
    // 0x808001D4: nop

    return;
    // 0x808001D4: nop

;}
RECOMP_FUNC void func_808011E8_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808011EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808011F0: jal         0x80084800
    // 0x808011F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _badrone_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808011F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808011F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808011FC: bne         $v0, $at, L_80801210
    if (ctx->r2 != ctx->r1) {
        // 0x80801200: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801210;
    }
    // 0x80801200: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801204: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801208: jal         0x800947EC
    // 0x8080120C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_1;
    // 0x8080120C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_80801210:
    // 0x80801210: jal         0x80082FF0
    // 0x80801214: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80801214: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80801218: jal         0x80082830
    // 0x8080121C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsbee_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x8080121C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80801220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801228: jr          $ra
    // 0x8080122C: nop

    return;
    // 0x8080122C: nop

;}
RECOMP_FUNC void func_80099A7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099A7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80099A80: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80099A84: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80099A88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80099A8C: lw          $a1, 0xC0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC0);
    // 0x80099A90: jal         0x800EE7F8
    // 0x80099A94: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80099A94: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_0:
    // 0x80099A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80099A9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80099AA0: jr          $ra
    // 0x80099AA4: nop

    return;
    // 0x80099AA4: nop

;}
RECOMP_FUNC void func_8080000C_chcoderoombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080001C: jal         0x80100074
    // 0x80800020: addiu       $a2, $zero, 0x182
    ctx->r6 = ADD32(0, 0X182);
    func_80100074(rdram, ctx);
        goto after_0;
    // 0x80800020: addiu       $a2, $zero, 0x182
    ctx->r6 = ADD32(0, 0X182);
    after_0:
    // 0x80800024: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800028: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080002C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800030: jal         0x8008A2A0
    // 0x80800034: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _susubgame_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800034: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80800038: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1172, 0X1308) << 16);
    // 0x8080003C: addiu       $a1, $a1, 0x1308
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1172, 0X1308));
    // 0x80800040: jal         0x8008A300
    // 0x80800044: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _susubgame_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80800044: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080004C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800050: jr          $ra
    // 0x80800054: nop

    return;
    // 0x80800054: nop

;}
RECOMP_FUNC void func_80800174_chfaircoinbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800174: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800178: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080017C: jal         0x8010A63C
    // 0x80800180: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8010A63C(rdram, ctx);
        goto after_0;
    // 0x80800180: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800184: jal         0x80800050
    // 0x80800188: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800050_chfaircoinbox(rdram, ctx);
        goto after_1;
    // 0x80800188: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080018C: jal         0x800DA298
    // 0x80800190: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800190: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800194: beq         $v0, $zero, L_808001B0
    if (ctx->r2 == 0) {
        // 0x80800198: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808001B0;
    }
    // 0x80800198: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080019C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001A0: jal         0x808000A4
    // 0x808001A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808000A4_chfaircoinbox(rdram, ctx);
        goto after_3;
    // 0x808001A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x808001A8: b           L_808001BC
    // 0x808001AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808001BC;
    // 0x808001AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001B0:
    // 0x808001B0: jal         0x808000A4
    // 0x808001B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808000A4_chfaircoinbox(rdram, ctx);
        goto after_4;
    // 0x808001B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808001B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001BC:
    // 0x808001BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001C0: jr          $ra
    // 0x808001C4: nop

    return;
    // 0x808001C4: nop

;}
RECOMP_FUNC void func_80103CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103CDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103CE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103CE4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80103CE8: jal         0x80103B24
    // 0x80103CEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103B24(rdram, ctx);
        goto after_0;
    // 0x80103CEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80103CF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103CF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80103CF8: jr          $ra
    // 0x80103CFC: nop

    return;
    // 0x80103CFC: nop

;}
RECOMP_FUNC void func_80800834_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800834: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x80800838: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8080083C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80800840: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x80800844: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80800848: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8080084C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80800850: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800854: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800858: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080085C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800860: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800864: jal         0x80100094
    // 0x80800868: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800868: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080086C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800870: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80800874: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800878: addiu       $s3, $sp, 0xB0
    ctx->r19 = ADD32(ctx->r29, 0XB0);
    // 0x8080087C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800880: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
L_80800884:
    // 0x80800884: sb          $s6, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r22;
    // 0x80800888: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8080088C: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
    // 0x80800890: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800894: addiu       $a1, $zero, 0x934
    ctx->r5 = ADD32(0, 0X934);
    // 0x80800898: jal         0x808007E4
    // 0x8080089C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_808007E4_chjiggygamenew(rdram, ctx);
        goto after_1;
    // 0x8080089C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_1:
    // 0x808008A0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x808008A4: slti        $at, $s4, 0x14
    ctx->r1 = SIGNED(ctx->r20) < 0X14 ? 1 : 0;
    // 0x808008A8: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
    // 0x808008AC: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x808008B0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x808008B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808008B8: sb          $s6, 0x1F3($s1)
    MEM_B(0X1F3, ctx->r17) = ctx->r22;
    // 0x808008BC: bne         $at, $zero, L_80800884
    if (ctx->r1 != 0) {
        // 0x808008C0: sb          $s6, 0x207($s1)
        MEM_B(0X207, ctx->r17) = ctx->r22;
            goto L_80800884;
    }
    // 0x808008C0: sb          $s6, 0x207($s1)
    MEM_B(0X207, ctx->r17) = ctx->r22;
    // 0x808008C4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x808008C8: jal         0x8008A6C8
    // 0x808008CC: lw          $a0, 0x2C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X2C);
    _sujiggy_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x808008CC: lw          $a0, 0x2C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X2C);
    after_2:
    // 0x808008D0: addiu       $s7, $zero, 0x14
    ctx->r23 = ADD32(0, 0X14);
    // 0x808008D4: subu        $t6, $s7, $v0
    ctx->r14 = SUB32(ctx->r23, ctx->r2);
    // 0x808008D8: blez        $t6, L_80800940
    if (SIGNED(ctx->r14) <= 0) {
        // 0x808008DC: sll         $t7, $s4, 2
        ctx->r15 = S32(ctx->r20 << 2);
            goto L_80800940;
    }
    // 0x808008DC: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x808008E0: addiu       $t8, $sp, 0x60
    ctx->r24 = ADD32(ctx->r29, 0X60);
    // 0x808008E4: addu        $s3, $t7, $t8
    ctx->r19 = ADD32(ctx->r15, ctx->r24);
    // 0x808008E8: addiu       $s0, $sp, 0xB0
    ctx->r16 = ADD32(ctx->r29, 0XB0);
    // 0x808008EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_808008F0:
    // 0x808008F0: jal         0x800DC214
    // 0x808008F4: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_800DC214(rdram, ctx);
        goto after_3;
    // 0x808008F4: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_3:
    // 0x808008F8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x808008FC: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x80800900: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80800904: bnel        $t1, $zero, L_808008F0
    if (ctx->r9 != 0) {
        // 0x80800908: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808008F0;
    }
    goto skip_0;
    // 0x80800908: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_0:
    // 0x8080090C: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80800910: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x80800914: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x80800918: sw          $s6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r22;
    // 0x8080091C: lw          $a0, 0x2C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X2C);
    // 0x80800920: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80800924: jal         0x8008A6C8
    // 0x80800928: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    _sujiggy_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80800928: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    after_4:
    // 0x8080092C: subu        $t4, $s7, $v0
    ctx->r12 = SUB32(ctx->r23, ctx->r2);
    // 0x80800930: slt         $at, $s4, $t4
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80800934: bnel        $at, $zero, L_808008F0
    if (ctx->r1 != 0) {
        // 0x80800938: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808008F0;
    }
    goto skip_1;
    // 0x80800938: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_1:
    // 0x8080093C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_80800940:
    // 0x80800940: jal         0x8008A6C8
    // 0x80800944: lw          $a0, 0x2C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X2C);
    _sujiggy_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x80800944: lw          $a0, 0x2C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X2C);
    after_5:
    // 0x80800948: subu        $t5, $s7, $v0
    ctx->r13 = SUB32(ctx->r23, ctx->r2);
    // 0x8080094C: blez        $t5, L_808009E8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80800950: sll         $t6, $s4, 2
        ctx->r14 = S32(ctx->r20 << 2);
            goto L_808009E8;
    }
    // 0x80800950: sll         $t6, $s4, 2
    ctx->r14 = S32(ctx->r20 << 2);
    // 0x80800954: addiu       $t7, $sp, 0x60
    ctx->r15 = ADD32(ctx->r29, 0X60);
    // 0x80800958: addu        $s3, $t6, $t7
    ctx->r19 = ADD32(ctx->r14, ctx->r15);
    // 0x8080095C: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    // 0x80800960: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80800964:
    // 0x80800964: jal         0x800DC214
    // 0x80800968: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_800DC214(rdram, ctx);
        goto after_6;
    // 0x80800968: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_6:
    // 0x8080096C: multu       $v0, $s1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800970: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800974: mflo        $t8
    ctx->r24 = lo;
    // 0x80800978: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x8080097C: lb          $t0, 0x1($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X1);
    // 0x80800980: bnel        $s6, $t0, L_80800964
    if (ctx->r22 != ctx->r8) {
        // 0x80800984: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800964;
    }
    goto skip_2;
    // 0x80800984: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_2:
    // 0x80800988: multu       $v0, $s1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080098C: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80800990: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800994: addiu       $a1, $zero, 0xA4
    ctx->r5 = ADD32(0, 0XA4);
    // 0x80800998: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8080099C: mflo        $t1
    ctx->r9 = lo;
    // 0x808009A0: addu        $s5, $s2, $t1
    ctx->r21 = ADD32(ctx->r18, ctx->r9);
    // 0x808009A4: jal         0x808007E4
    // 0x808009A8: sb          $t2, 0x1($s5)
    MEM_B(0X1, ctx->r21) = ctx->r10;
    func_808007E4_chjiggygamenew(rdram, ctx);
        goto after_7;
    // 0x808009A8: sb          $t2, 0x1($s5)
    MEM_B(0X1, ctx->r21) = ctx->r10;
    after_7:
    // 0x808009AC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808009B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808009B4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x808009B8: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x808009BC: swc1        $f4, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->f4.u32l;
    // 0x808009C0: lw          $t3, -0x4($s3)
    ctx->r11 = MEM_W(ctx->r19, -0X4);
    // 0x808009C4: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x808009C8: sb          $s0, 0x1F4($t4)
    MEM_B(0X1F4, ctx->r12) = ctx->r16;
    // 0x808009CC: jal         0x8008A6C8
    // 0x808009D0: lw          $a0, 0x2C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X2C);
    _sujiggy_entrypoint_6(rdram, ctx);
        goto after_8;
    // 0x808009D0: lw          $a0, 0x2C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X2C);
    after_8:
    // 0x808009D4: subu        $t5, $s7, $v0
    ctx->r13 = SUB32(ctx->r23, ctx->r2);
    // 0x808009D8: slt         $at, $s4, $t5
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x808009DC: bnel        $at, $zero, L_80800964
    if (ctx->r1 != 0) {
        // 0x808009E0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800964;
    }
    goto skip_3;
    // 0x808009E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_3:
    // 0x808009E4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_808009E8:
    // 0x808009E8: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    // 0x808009EC: jal         0x8008A6D0
    // 0x808009F0: lw          $a0, 0x2C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X2C);
    _sujiggy_entrypoint_7(rdram, ctx);
        goto after_9;
    // 0x808009F0: lw          $a0, 0x2C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X2C);
    after_9:
    // 0x808009F4: blez        $v0, L_80800A88
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808009F8: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80800A88;
    }
    // 0x808009F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_808009FC:
    // 0x808009FC: jal         0x800DC214
    // 0x80800A00: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DC214(rdram, ctx);
        goto after_10;
    // 0x80800A00: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x80800A04: sll         $s0, $v0, 24
    ctx->r16 = S32(ctx->r2 << 24);
    // 0x80800A08: sra         $t6, $s0, 24
    ctx->r14 = S32(SIGNED(ctx->r16) >> 24);
    // 0x80800A0C: jal         0x800DC1AC
    // 0x80800A10: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    func_800DC1AC(rdram, ctx);
        goto after_11;
    // 0x80800A10: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    after_11:
    // 0x80800A14: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800A18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800A1C: nop

    // 0x80800A20: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800A24: nop

    // 0x80800A28: bc1tl       L_80800A40
    if (c1cs) {
        // 0x80800A2C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800A40;
    }
    goto skip_4;
    // 0x80800A2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_4:
    // 0x80800A30: negu        $s0, $s0
    ctx->r16 = SUB32(0, ctx->r16);
    // 0x80800A34: sll         $t7, $s0, 24
    ctx->r15 = S32(ctx->r16 << 24);
    // 0x80800A38: sra         $s0, $t7, 24
    ctx->r16 = S32(SIGNED(ctx->r15) >> 24);
    // 0x80800A3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80800A40:
    // 0x80800A40: jal         0x800DC214
    // 0x80800A44: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_800DC214(rdram, ctx);
        goto after_12;
    // 0x80800A44: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_12:
    // 0x80800A48: multu       $v0, $s1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800A4C: mflo        $t9
    ctx->r25 = lo;
    // 0x80800A50: addu        $t0, $s2, $t9
    ctx->r8 = ADD32(ctx->r18, ctx->r25);
    // 0x80800A54: lb          $t1, 0x0($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X0);
    // 0x80800A58: bnel        $t1, $zero, L_80800A40
    if (ctx->r9 != 0) {
        // 0x80800A5C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800A40;
    }
    goto skip_5;
    // 0x80800A5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_5:
    // 0x80800A60: multu       $v0, $s1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800A64: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80800A68: mflo        $t2
    ctx->r10 = lo;
    // 0x80800A6C: addu        $t3, $s2, $t2
    ctx->r11 = ADD32(ctx->r18, ctx->r10);
    // 0x80800A70: sb          $s0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r16;
    // 0x80800A74: jal         0x8008A6D0
    // 0x80800A78: lw          $a0, 0x2C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X2C);
    _sujiggy_entrypoint_7(rdram, ctx);
        goto after_13;
    // 0x80800A78: lw          $a0, 0x2C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X2C);
    after_13:
    // 0x80800A7C: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800A80: bnel        $at, $zero, L_808009FC
    if (ctx->r1 != 0) {
        // 0x80800A84: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_808009FC;
    }
    goto skip_6;
    // 0x80800A84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_6:
L_80800A88:
    // 0x80800A88: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80800A8C: addiu       $s0, $zero, 0x15
    ctx->r16 = ADD32(0, 0X15);
    // 0x80800A90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80800A94:
    // 0x80800A94: jal         0x800DC214
    // 0x80800A98: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_800DC214(rdram, ctx);
        goto after_14;
    // 0x80800A98: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_14:
    // 0x80800A9C: multu       $v0, $s1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800AA0: mflo        $t4
    ctx->r12 = lo;
    // 0x80800AA4: addu        $v1, $s2, $t4
    ctx->r3 = ADD32(ctx->r18, ctx->r12);
    // 0x80800AA8: lbu         $t5, 0x2($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X2);
    // 0x80800AAC: bnel        $t5, $zero, L_80800A94
    if (ctx->r13 != 0) {
        // 0x80800AB0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800A94;
    }
    goto skip_7;
    // 0x80800AB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_7:
    // 0x80800AB4: sb          $s4, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r20;
    // 0x80800AB8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80800ABC: bnel        $s4, $s0, L_80800A94
    if (ctx->r20 != ctx->r16) {
        // 0x80800AC0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800A94;
    }
    goto skip_8;
    // 0x80800AC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_8:
    // 0x80800AC4: sw          $s6, 0x24($fp)
    MEM_W(0X24, ctx->r30) = ctx->r22;
    // 0x80800AC8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800ACC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80800AD0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80800AD4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80800AD8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80800ADC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800AE0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800AE4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800AE8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800AF0: jr          $ra
    // 0x80800AF4: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x80800AF4: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void func_80800CB8_ncpoducam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800CBC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800CC0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800CC4: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80800CC8: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80800CCC: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80800CD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800CD4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800CD8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800CDC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800CE0: beq         $a0, $s1, L_80800D0C
    if (ctx->r4 == ctx->r17) {
        // 0x80800CE4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800D0C;
    }
    // 0x80800CE4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800CE8: addiu       $s2, $sp, 0x2A
    ctx->r18 = ADD32(ctx->r29, 0X2A);
L_80800CEC:
    // 0x80800CEC: jal         0x800A5800
    // 0x80800CF0: sh          $a0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r4;
    func_800A5800(rdram, ctx);
        goto after_0;
    // 0x80800CF0: sh          $a0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800CF4: jal         0x80085600
    // 0x80800CF8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _cadbfunc_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x80800CF8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80800CFC: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    // 0x80800D00: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800D04: bne         $a0, $s1, L_80800CEC
    if (ctx->r4 != ctx->r17) {
        // 0x80800D08: nop
    
            goto L_80800CEC;
    }
    // 0x80800D08: nop

L_80800D0C:
    // 0x80800D0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800D10: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800D14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800D18: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D1C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800D20: jr          $ra
    // 0x80800D24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800D24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bainput_func_8009803C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009803C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80098040: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80098044: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80098048: jal         0x80091A58
    // 0x8009804C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x8009804C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80098050: beql        $v0, $zero, L_8009808C
    if (ctx->r2 == 0) {
        // 0x80098054: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8009808C;
    }
    goto skip_0;
    // 0x80098054: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80098058: jal         0x8008D850
    // 0x8009805C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8008D850(rdram, ctx);
        goto after_1;
    // 0x8009805C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80098060: beq         $v0, $zero, L_80098088
    if (ctx->r2 == 0) {
        // 0x80098064: addiu       $a0, $sp, 0x24
        ctx->r4 = ADD32(ctx->r29, 0X24);
            goto L_80098088;
    }
    // 0x80098064: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80098068: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8009806C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80098070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80098074: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80098078: jal         0x8008A690
    // 0x8009807C: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    _suinv_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x8009807C: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    after_2:
    // 0x80098080: b           L_8009808C
    // 0x80098084: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
        goto L_8009808C;
    // 0x80098084: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_80098088:
    // 0x80098088: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009808C:
    // 0x8009808C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80098090: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80098094: jr          $ra
    // 0x80098098: nop

    return;
    // 0x80098098: nop

;}
RECOMP_FUNC void _bsfirstp_entrypoint_32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084388: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x80084388);
    return;
    // 0x8008438C: addi        $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
;}
RECOMP_FUNC void func_800FA2C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA2C0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800FA2C4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800FA2C8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800FA2CC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800FA2D0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800FA2D4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800FA2D8: jal         0x800D8FF8
    // 0x800FA2DC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x800FA2DC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    after_0:
    // 0x800FA2E0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800FA2E4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800FA2E8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800FA2EC: addiu       $s0, $s0, 0x3880
    ctx->r16 = ADD32(ctx->r16, 0X3880);
    // 0x800FA2F0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800FA2F4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_800FA2F8:
    // 0x800FA2F8: lbu         $t6, 0x10($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X10);
    // 0x800FA2FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800FA300: bnel        $s3, $t6, L_800FA360
    if (ctx->r19 != ctx->r14) {
        // 0x800FA304: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800FA360;
    }
    goto skip_0;
    // 0x800FA304: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800FA308: jal         0x800FA874
    // 0x800FA30C: lb          $a1, 0xE($s0)
    ctx->r5 = MEM_B(ctx->r16, 0XE);
    func_800FA874(rdram, ctx);
        goto after_1;
    // 0x800FA30C: lb          $a1, 0xE($s0)
    ctx->r5 = MEM_B(ctx->r16, 0XE);
    after_1:
    // 0x800FA310: beql        $v0, $zero, L_800FA360
    if (ctx->r2 == 0) {
        // 0x800FA314: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800FA360;
    }
    goto skip_1;
    // 0x800FA314: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x800FA318: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800FA31C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800FA320: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x800FA324: nop

    // 0x800FA328: bc1fl       L_800FA360
    if (!c1cs) {
        // 0x800FA32C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800FA360;
    }
    goto skip_2;
    // 0x800FA32C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x800FA330: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800FA334: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800FA338: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FA33C: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x800FA340: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800FA344: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x800FA348: nop

    // 0x800FA34C: bc1fl       L_800FA360
    if (!c1cs) {
        // 0x800FA350: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800FA360;
    }
    goto skip_3;
    // 0x800FA350: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_3:
    // 0x800FA354: jal         0x800FA240
    // 0x800FA358: swc1        $f20, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f20.u32l;
    func_800FA240(rdram, ctx);
        goto after_2;
    // 0x800FA358: swc1        $f20, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f20.u32l;
    after_2:
    // 0x800FA35C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800FA360:
    // 0x800FA360: slti        $at, $s1, 0x30
    ctx->r1 = SIGNED(ctx->r17) < 0X30 ? 1 : 0;
    // 0x800FA364: bne         $at, $zero, L_800FA2F8
    if (ctx->r1 != 0) {
        // 0x800FA368: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_800FA2F8;
    }
    // 0x800FA368: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x800FA36C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800FA370: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800FA374: addiu       $s2, $s2, 0x3DC0
    ctx->r18 = ADD32(ctx->r18, 0X3DC0);
    // 0x800FA378: addiu       $s0, $s0, 0x3880
    ctx->r16 = ADD32(ctx->r16, 0X3880);
    // 0x800FA37C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800FA380:
    // 0x800FA380: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x800FA384: beql        $a0, $zero, L_800FA398
    if (ctx->r4 == 0) {
        // 0x800FA388: lbu         $v0, 0xC($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0XC);
            goto L_800FA398;
    }
    goto skip_4;
    // 0x800FA388: lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XC);
    skip_4:
    // 0x800FA38C: jal         0x8008A590
    // 0x800FA390: nop

    _scinfobar_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x800FA390: nop

    after_3:
    // 0x800FA394: lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XC);
L_800FA398:
    // 0x800FA398: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800FA39C: beql        $v0, $s3, L_800FA3C0
    if (ctx->r2 == ctx->r19) {
        // 0x800FA3A0: lb          $v0, 0xD($s0)
        ctx->r2 = MEM_B(ctx->r16, 0XD);
            goto L_800FA3C0;
    }
    goto skip_5;
    // 0x800FA3A0: lb          $v0, 0xD($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XD);
    skip_5:
    // 0x800FA3A4: beq         $v0, $at, L_800FA434
    if (ctx->r2 == ctx->r1) {
        // 0x800FA3A8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800FA434;
    }
    // 0x800FA3A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800FA3AC: beq         $v0, $at, L_800FA464
    if (ctx->r2 == ctx->r1) {
        // 0x800FA3B0: nop
    
            goto L_800FA464;
    }
    // 0x800FA3B0: nop

    // 0x800FA3B4: b           L_800FA4DC
    // 0x800FA3B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800FA4DC;
    // 0x800FA3B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800FA3BC: lb          $v0, 0xD($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XD);
L_800FA3C0:
    // 0x800FA3C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800FA3C4: sltiu       $at, $v0, 0xA
    ctx->r1 = ctx->r2 < 0XA ? 1 : 0;
    // 0x800FA3C8: beq         $at, $zero, L_800FA414
    if (ctx->r1 == 0) {
        // 0x800FA3CC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800FA414;
    }
    // 0x800FA3CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FA3D0: addu        $t7, $s2, $v0
    ctx->r15 = ADD32(ctx->r18, ctx->r2);
    // 0x800FA3D4: lb          $v1, 0x0($t7)
    ctx->r3 = MEM_B(ctx->r15, 0X0);
    // 0x800FA3D8: lb          $t9, 0xA($s0)
    ctx->r25 = MEM_B(ctx->r16, 0XA);
    // 0x800FA3DC: lb          $t3, 0xB($s0)
    ctx->r11 = MEM_B(ctx->r16, 0XB);
    // 0x800FA3E0: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x800FA3E4: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800FA3E8: lh          $t2, 0x8($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X8);
    // 0x800FA3EC: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800FA3F0: sb          $t6, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r14;
    // 0x800FA3F4: lb          $a0, 0xD($s0)
    ctx->r4 = MEM_B(ctx->r16, 0XD);
    // 0x800FA3F8: mflo        $t0
    ctx->r8 = lo;
    // 0x800FA3FC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800FA400: sh          $t1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r9;
    // 0x800FA404: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800FA408: mflo        $t4
    ctx->r12 = lo;
    // 0x800FA40C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800FA410: sh          $t5, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r13;
L_800FA414:
    // 0x800FA414: sltiu       $at, $a0, 0xA
    ctx->r1 = ctx->r4 < 0XA ? 1 : 0;
    // 0x800FA418: bne         $at, $zero, L_800FA4D8
    if (ctx->r1 != 0) {
        // 0x800FA41C: addiu       $t7, $zero, 0xA
        ctx->r15 = ADD32(0, 0XA);
            goto L_800FA4D8;
    }
    // 0x800FA41C: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x800FA420: sb          $t7, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r15;
    // 0x800FA424: jal         0x800FA130
    // 0x800FA428: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800FA130(rdram, ctx);
        goto after_4;
    // 0x800FA428: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x800FA42C: b           L_800FA4DC
    // 0x800FA430: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800FA4DC;
    // 0x800FA430: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800FA434:
    // 0x800FA434: jal         0x8008A628
    // 0x800FA438: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    _scinfobar_entrypoint_21(rdram, ctx);
        goto after_5;
    // 0x800FA438: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    after_5:
    // 0x800FA43C: beql        $v0, $zero, L_800FA4DC
    if (ctx->r2 == 0) {
        // 0x800FA440: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800FA4DC;
    }
    goto skip_6;
    // 0x800FA440: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_6:
    // 0x800FA444: lbu         $t9, 0x11($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X11);
    // 0x800FA448: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800FA44C: bnel        $t9, $zero, L_800FA4DC
    if (ctx->r25 != 0) {
        // 0x800FA450: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800FA4DC;
    }
    goto skip_7;
    // 0x800FA450: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_7:
    // 0x800FA454: jal         0x8008A5B0
    // 0x800FA458: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    _scinfobar_entrypoint_6(rdram, ctx);
        goto after_6;
    // 0x800FA458: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    after_6:
    // 0x800FA45C: b           L_800FA4DC
    // 0x800FA460: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800FA4DC;
    // 0x800FA460: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800FA464:
    // 0x800FA464: jal         0x8008A628
    // 0x800FA468: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    _scinfobar_entrypoint_21(rdram, ctx);
        goto after_7;
    // 0x800FA468: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    after_7:
    // 0x800FA46C: beql        $v0, $zero, L_800FA4DC
    if (ctx->r2 == 0) {
        // 0x800FA470: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800FA4DC;
    }
    goto skip_8;
    // 0x800FA470: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_8:
    // 0x800FA474: lb          $v0, 0xD($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XD);
    // 0x800FA478: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800FA47C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FA480: blez        $v0, L_800FA4C8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800FA484: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_800FA4C8;
    }
    // 0x800FA484: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x800FA488: sb          $t8, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r24;
    // 0x800FA48C: lb          $v0, 0xD($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XD);
    // 0x800FA490: lb          $t3, 0xA($s0)
    ctx->r11 = MEM_B(ctx->r16, 0XA);
    // 0x800FA494: lb          $t6, 0xB($s0)
    ctx->r14 = MEM_B(ctx->r16, 0XB);
    // 0x800FA498: addu        $t0, $s2, $v0
    ctx->r8 = ADD32(ctx->r18, ctx->r2);
    // 0x800FA49C: lb          $v1, 0x0($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X0);
    // 0x800FA4A0: lh          $t1, 0x6($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X6);
    // 0x800FA4A4: lh          $t5, 0x8($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X8);
    // 0x800FA4A8: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800FA4AC: mflo        $t2
    ctx->r10 = lo;
    // 0x800FA4B0: subu        $t4, $t1, $t2
    ctx->r12 = SUB32(ctx->r9, ctx->r10);
    // 0x800FA4B4: sh          $t4, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r12;
    // 0x800FA4B8: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800FA4BC: mflo        $t7
    ctx->r15 = lo;
    // 0x800FA4C0: subu        $t9, $t5, $t7
    ctx->r25 = SUB32(ctx->r13, ctx->r15);
    // 0x800FA4C4: sh          $t9, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r25;
L_800FA4C8:
    // 0x800FA4C8: bgtzl       $v0, L_800FA4DC
    if (SIGNED(ctx->r2) > 0) {
        // 0x800FA4CC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800FA4DC;
    }
    goto skip_9;
    // 0x800FA4CC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_9:
    // 0x800FA4D0: jal         0x800FA130
    // 0x800FA4D4: sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
    func_800FA130(rdram, ctx);
        goto after_8;
    // 0x800FA4D4: sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
    after_8:
L_800FA4D8:
    // 0x800FA4D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800FA4DC:
    // 0x800FA4DC: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x800FA4E0: bne         $s1, $at, L_800FA380
    if (ctx->r17 != ctx->r1) {
        // 0x800FA4E4: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_800FA380;
    }
    // 0x800FA4E4: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x800FA4E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800FA4EC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800FA4F0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800FA4F4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800FA4F8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800FA4FC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800FA500: jr          $ra
    // 0x800FA504: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800FA504: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_808088CC_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808088CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808088D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808088D4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808088D8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x808088DC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808088E0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808088E4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808088E8: jal         0x80100094
    // 0x808088EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808088EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808088F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808088F4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808088F8: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_808088FC:
    // 0x808088FC: lw          $a0, 0xB0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XB0);
    // 0x80808900: beql        $a0, $zero, L_80808924
    if (ctx->r4 == 0) {
        // 0x80808904: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80808924;
    }
    goto skip_0;
    // 0x80808904: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80808908: jal         0x80106790
    // 0x8080890C: nop

    func_80106790(rdram, ctx);
        goto after_1;
    // 0x8080890C: nop

    after_1:
    // 0x80808910: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80808914: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80808918: jal         0x80808BE4
    // 0x8080891C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80808BE4_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x8080891C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x80808920: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80808924:
    // 0x80808924: bne         $s0, $s2, L_808088FC
    if (ctx->r16 != ctx->r18) {
        // 0x80808928: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_808088FC;
    }
    // 0x80808928: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8080892C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80808930: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80808934: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80808938: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8080893C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80808940: jr          $ra
    // 0x80808944: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80808944: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _suegg_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A420: syscall     841
    recomp_syscall_handler(rdram, ctx, 0x8008A420);
    return;
    // 0x8008A424: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void func_808001E4_chpumproomswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001EC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001F0: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808001F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808001F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001FC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800200: bnel        $t7, $at, L_80800290
    if (ctx->r15 != ctx->r1) {
        // 0x80800204: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800290;
    }
    goto skip_0;
    // 0x80800204: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800208: lbu         $t8, 0x5F($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X5F);
    // 0x8080020C: bne         $t8, $zero, L_80800248
    if (ctx->r24 != 0) {
        // 0x80800210: nop
    
            goto L_80800248;
    }
    // 0x80800210: nop

    // 0x80800214: jal         0x800EA05C
    // 0x80800218: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800218: nop

    after_0:
    // 0x8080021C: addiu       $at, $zero, 0xE3
    ctx->r1 = ADD32(0, 0XE3);
    // 0x80800220: bne         $v0, $at, L_80800234
    if (ctx->r2 != ctx->r1) {
        // 0x80800224: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800234;
    }
    // 0x80800224: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800228: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(996, 0X410) << 16);
    // 0x8080022C: b           L_8080023C
    // 0x80800230: addiu       $a2, $a2, 0x410
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(996, 0X410));
        goto L_8080023C;
    // 0x80800230: addiu       $a2, $a2, 0x410
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(996, 0X410));
L_80800234:
    // 0x80800234: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(996, 0X424) << 16);
    // 0x80800238: addiu       $a2, $a2, 0x424
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(996, 0X424));
L_8080023C:
    // 0x8080023C: jal         0x800C4350
    // 0x80800240: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4350(rdram, ctx);
        goto after_1;
    // 0x80800240: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x80800244: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
L_80800248:
    // 0x80800248: jal         0x800D9078
    // 0x8080024C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_2;
    // 0x8080024C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_2:
    // 0x80800250: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(996, 0X370) << 16);
    // 0x80800254: lwc1        $f4, 0x370($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(996, 0X370));
    // 0x80800258: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080025C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800260: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    // 0x80800264: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800268: jal         0x800F12D4
    // 0x8080026C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F12D4(rdram, ctx);
        goto after_3;
    // 0x8080026C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80800270: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800274: jal         0x800C31DC
    // 0x80800278: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    func_800C31DC(rdram, ctx);
        goto after_4;
    // 0x80800278: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    after_4:
    // 0x8080027C: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80800280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800284: jal         0x800C4350
    // 0x80800288: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800C4350(rdram, ctx);
        goto after_5;
    // 0x80800288: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8080028C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800290:
    // 0x80800290: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800294: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800298: jr          $ra
    // 0x8080029C: nop

    return;
    // 0x8080029C: nop

;}
RECOMP_FUNC void func_808024DC_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808024DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808024E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808024E4: jal         0x800A3280
    // 0x808024E8: nop

    func_800A3280(rdram, ctx);
        goto after_0;
    // 0x808024E8: nop

    after_0:
    // 0x808024EC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x808024F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808024F4: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(439, 0XAFB4) << 16);
    // 0x808024F8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808024FC: lw          $v0, -0x504C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XAFB4));
    // 0x80802500: jr          $ra
    // 0x80802504: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80802504: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _bahold_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D48: syscall     134
    recomp_syscall_handler(rdram, ctx, 0x80084D48);
    return;
    // 0x80084D4C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void basnowball_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080056C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800570: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800574: jal         0x800A1718
    // 0x80800578: nop

    func_800A1718(rdram, ctx);
        goto after_0;
    // 0x80800578: nop

    after_0:
    // 0x8080057C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800580: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800584: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80800588: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x8080058C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800590: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x80800594: jal         0x800F10B4
    // 0x80800598: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800598: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_1:
    // 0x8080059C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808005A4: jr          $ra
    // 0x808005A8: nop

    return;
    // 0x808005A8: nop

;}
RECOMP_FUNC void _gcdialogexec_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087E30: syscall     658
    recomp_syscall_handler(rdram, ctx, 0x80087E30);
    return;
    // 0x80087E34: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void freelist_new(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3268: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B326C: multu       $a0, $a1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B3270: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B3274: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B3278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B327C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800B3280: mflo        $a0
    ctx->r4 = lo;
    // 0x800B3284: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800B3288: jal         0x8001ACCC
    // 0x800B328C: nop

    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x800B328C: nop

    after_0:
    // 0x800B3290: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800B3294: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800B3298: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B329C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800B32A0: sh          $a1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r5;
    // 0x800B32A4: jal         0x800B2FE0
    // 0x800B32A8: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    freelist_clear(rdram, ctx);
        goto after_1;
    // 0x800B32A8: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    after_1:
    // 0x800B32AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B32B0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800B32B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B32B8: jr          $ra
    // 0x800B32BC: nop

    return;
    // 0x800B32BC: nop

;}
RECOMP_FUNC void _bscarry_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082E68: syscall     31
    recomp_syscall_handler(rdram, ctx, 0x80082E68);
    return;
    // 0x80082E6C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800DE8_chpawnbroker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800DEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DF0: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800DF4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800DF8: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800DFC: bnel        $t7, $at, L_80800E28
    if (ctx->r15 != ctx->r1) {
        // 0x80800E00: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800E28;
    }
    goto skip_0;
    // 0x80800E00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800E04: jal         0x80800E3C
    // 0x80800E08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800E3C_chpawnbroker(rdram, ctx);
        goto after_0;
    // 0x80800E08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800E0C: jal         0x80101DDC
    // 0x80800E10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80101DDC(rdram, ctx);
        goto after_1;
    // 0x80800E10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800E14: beq         $v0, $zero, L_80800E24
    if (ctx->r2 == 0) {
        // 0x80800E18: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800E24;
    }
    // 0x80800E18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800E1C: jal         0x80102424
    // 0x80800E20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800E20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_80800E24:
    // 0x80800E24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800E28:
    // 0x80800E28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E2C: jr          $ra
    // 0x80800E30: nop

    return;
    // 0x80800E30: nop

;}
RECOMP_FUNC void _sueggmove_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A488: syscall     842
    recomp_syscall_handler(rdram, ctx, 0x8008A488);
    return;
    // 0x8008A48C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_808006E8_cheggclockwork(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808006EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808006F4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808006F8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808006FC: jal         0x80100094
    // 0x80800700: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800700: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800704: jal         0x8001B798
    // 0x80800708: lh          $a0, 0x2C($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2C);
    func_8001B798(rdram, ctx);
        goto after_1;
    // 0x80800708: lh          $a0, 0x2C($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2C);
    after_1:
    // 0x8080070C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80800710: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800714: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800718: jal         0x800F6DE0
    // 0x8080071C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F6DE0(rdram, ctx);
        goto after_2;
    // 0x8080071C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80800720: bnel        $v0, $zero, L_808007A4
    if (ctx->r2 != 0) {
        // 0x80800724: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808007A4;
    }
    goto skip_0;
    // 0x80800724: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800728: jal         0x800F6DE0
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6DE0(rdram, ctx);
        goto after_3;
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800730: beq         $v0, $zero, L_8080074C
    if (ctx->r2 == 0) {
        // 0x80800734: addiu       $a1, $s0, 0xC
        ctx->r5 = ADD32(ctx->r16, 0XC);
            goto L_8080074C;
    }
    // 0x80800734: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x80800738: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080073C: jal         0x800EE7F8
    // 0x80800740: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80800740: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x80800744: b           L_808007A4
    // 0x80800748: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808007A4;
    // 0x80800748: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080074C:
    // 0x8080074C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800750: jal         0x800F6DE0
    // 0x80800754: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800F6DE0(rdram, ctx);
        goto after_5;
    // 0x80800754: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_5:
    // 0x80800758: beq         $v0, $zero, L_80800770
    if (ctx->r2 == 0) {
        // 0x8080075C: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_80800770;
    }
    // 0x8080075C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800760: jal         0x800EE7F8
    // 0x80800764: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80800764: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80800768: b           L_808007A4
    // 0x8080076C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808007A4;
    // 0x8080076C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800770:
    // 0x80800770: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800774: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800778: jal         0x800F6DE0
    // 0x8080077C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800F6DE0(rdram, ctx);
        goto after_7;
    // 0x8080077C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_7:
    // 0x80800780: beq         $v0, $zero, L_80800798
    if (ctx->r2 == 0) {
        // 0x80800784: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_80800798;
    }
    // 0x80800784: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800788: jal         0x800EE7F8
    // 0x8080078C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x8080078C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80800790: b           L_808007A4
    // 0x80800794: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808007A4;
    // 0x80800794: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800798:
    // 0x80800798: jal         0x800EE7F8
    // 0x8080079C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x8080079C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x808007A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007A4:
    // 0x808007A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808007A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808007AC: jr          $ra
    // 0x808007B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808007B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _dbzone_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087948: syscall     640
    recomp_syscall_handler(rdram, ctx, 0x80087948);
    return;
    // 0x8008794C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800934_bsvanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800934: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080093C: jal         0x80082FF0
    // 0x80800940: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800940: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800944: jal         0x80800174
    // 0x80800948: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800174_bsvanswim(rdram, ctx);
        goto after_1;
    // 0x80800948: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080094C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800950: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800954: jr          $ra
    // 0x80800958: nop

    return;
    // 0x80800958: nop

;}
RECOMP_FUNC void func_800AA00C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA00C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800AA010: addiu       $v0, $v0, 0x7780
    ctx->r2 = ADD32(ctx->r2, 0X7780);
    // 0x800AA014: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800AA018: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x800AA01C: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x800AA020: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x800AA024: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AA028: sh          $zero, 0x7786($at)
    MEM_H(0X7786, ctx->r1) = 0;
    // 0x800AA02C: sh          $zero, 0x7784($at)
    MEM_H(0X7784, ctx->r1) = 0;
    // 0x800AA030: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AA034: sh          $zero, 0x7788($at)
    MEM_H(0X7788, ctx->r1) = 0;
    // 0x800AA038: sh          $zero, 0x778A($at)
    MEM_H(0X778A, ctx->r1) = 0;
    // 0x800AA03C: sh          $zero, 0x778C($at)
    MEM_H(0X778C, ctx->r1) = 0;
    // 0x800AA040: sh          $zero, 0x778E($at)
    MEM_H(0X778E, ctx->r1) = 0;
    // 0x800AA044: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AA048: sh          $zero, 0x7790($at)
    MEM_H(0X7790, ctx->r1) = 0;
    // 0x800AA04C: jr          $ra
    // 0x800AA050: sh          $zero, 0x7792($at)
    MEM_H(0X7792, ctx->r1) = 0;
    return;
    // 0x800AA050: sh          $zero, 0x7792($at)
    MEM_H(0X7792, ctx->r1) = 0;
;}
RECOMP_FUNC void suegg_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080094C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800950: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800954: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800958: jal         0x80100094
    // 0x8080095C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080095C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800960: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3322, 0XE38) << 16);
    // 0x80800964: lwc1        $f4, 0xE38($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3322, 0XE38));
    // 0x80800968: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8080096C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800970: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800974: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800978: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080097C: bc1f        L_80800988
    if (!c1cs) {
        // 0x80800980: nop
    
            goto L_80800988;
    }
    // 0x80800980: nop

    // 0x80800984: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800988:
    // 0x80800988: beql        $v0, $zero, L_808009D0
    if (ctx->r2 == 0) {
        // 0x8080098C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808009D0;
    }
    goto skip_0;
    // 0x8080098C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800990: jal         0x8008A450
    // 0x80800994: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    _sueggmove_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800994: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80800998: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8080099C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x808009A0: bne         $t6, $zero, L_808009CC
    if (ctx->r14 != 0) {
        // 0x808009A4: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_808009CC;
    }
    // 0x808009A4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808009A8: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x808009AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808009B0: lwc1        $f10, 0x30($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X30);
    // 0x808009B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808009B8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x808009BC: nop

    // 0x808009C0: bc1fl       L_808009D0
    if (!c1cs) {
        // 0x808009C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808009D0;
    }
    goto skip_1;
    // 0x808009C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808009C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009CC:
    // 0x808009CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808009D0:
    // 0x808009D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808009D4: jr          $ra
    // 0x808009D8: nop

    return;
    // 0x808009D8: nop

;}
RECOMP_FUNC void func_80104378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104378: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010437C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80104380: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80104384: jal         0x800B3248
    // 0x80104388: lw          $a0, 0x6E80($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6E80);
    freelist_free(rdram, ctx);
        goto after_0;
    // 0x80104388: lw          $a0, 0x6E80($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6E80);
    after_0:
    // 0x8010438C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80104390: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80104394: sw          $zero, 0x6E80($at)
    MEM_W(0X6E80, ctx->r1) = 0;
    // 0x80104398: jr          $ra
    // 0x8010439C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010439C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8080374C_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080374C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80803750: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80803754: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80803758: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8080375C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803760: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80803764: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80803768: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8080376C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80803770: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80803774: jal         0x80100094
    // 0x80803778: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803778: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x8080377C: lh          $t6, 0xC6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XC6);
    // 0x80803780: beql        $t6, $zero, L_808037A0
    if (ctx->r14 == 0) {
        // 0x80803784: lhu         $t7, 0x76($s0)
        ctx->r15 = MEM_HU(ctx->r16, 0X76);
            goto L_808037A0;
    }
    goto skip_0;
    // 0x80803784: lhu         $t7, 0x76($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X76);
    skip_0:
    // 0x80803788: jal         0x8001B798
    // 0x8080378C: lh          $a0, 0xC6($v0)
    ctx->r4 = MEM_H(ctx->r2, 0XC6);
    func_8001B798(rdram, ctx);
        goto after_1;
    // 0x8080378C: lh          $a0, 0xC6($v0)
    ctx->r4 = MEM_H(ctx->r2, 0XC6);
    after_1:
    // 0x80803790: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803794: jal         0x80089820
    // 0x80803798: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _suexpression_entrypoint_19(rdram, ctx);
        goto after_2;
    // 0x80803798: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8080379C: lhu         $t7, 0x76($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X76);
L_808037A0:
    // 0x808037A0: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1732, 0X4160) << 16);
    // 0x808037A4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x808037A8: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x808037AC: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x808037B0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x808037B4: lw          $t0, 0x4160($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(1732, 0X4160));
    // 0x808037B8: sll         $t1, $t0, 15
    ctx->r9 = S32(ctx->r8 << 15);
    // 0x808037BC: bgezl       $t1, L_80803868
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808037C0: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80803868;
    }
    goto skip_1;
    // 0x808037C0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x808037C4: jal         0x8010262C
    // 0x808037C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8010262C(rdram, ctx);
        goto after_3;
    // 0x808037C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x808037CC: beq         $v0, $zero, L_80803864
    if (ctx->r2 == 0) {
        // 0x808037D0: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80803864;
    }
    // 0x808037D0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808037D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808037D8: jal         0x80100094
    // 0x808037DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x808037DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808037E0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808037E4: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(1732, 0X5308) << 16);
    // 0x808037E8: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(1732, 0X530E) << 16);
    // 0x808037EC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808037F0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808037F4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808037F8: addiu       $s3, $s3, 0x530E
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(1732, 0X530E));
    // 0x808037FC: addiu       $s0, $s0, 0x5308
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1732, 0X5308));
    // 0x80803800: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
L_80803804:
    // 0x80803804: lw          $a3, 0xD0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XD0);
    // 0x80803808: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8080380C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80803810: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80803814: jal         0x800E0AFC
    // 0x80803818: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    func_800E0AFC(rdram, ctx);
        goto after_5;
    // 0x80803818: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    after_5:
    // 0x8080381C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80803820: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x80803824: bnel        $at, $zero, L_80803804
    if (ctx->r1 != 0) {
        // 0x80803828: mfc1        $a2, $f22
        ctx->r6 = (int32_t)ctx->f22.u32l;
            goto L_80803804;
    }
    goto skip_2;
    // 0x80803828: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    skip_2:
    // 0x8080382C: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(1732, 0X5310) << 16);
    // 0x80803830: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(1732, 0X5316) << 16);
    // 0x80803834: addiu       $s3, $s3, 0x5316
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(1732, 0X5316));
    // 0x80803838: addiu       $s0, $s0, 0x5310
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1732, 0X5310));
    // 0x8080383C: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
L_80803840:
    // 0x80803840: lw          $a3, 0xD4($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XD4);
    // 0x80803844: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80803848: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8080384C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80803850: jal         0x800E0AFC
    // 0x80803854: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    func_800E0AFC(rdram, ctx);
        goto after_6;
    // 0x80803854: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    after_6:
    // 0x80803858: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8080385C: bnel        $s0, $s3, L_80803840
    if (ctx->r16 != ctx->r19) {
        // 0x80803860: mfc1        $a2, $f22
        ctx->r6 = (int32_t)ctx->f22.u32l;
            goto L_80803840;
    }
    goto skip_3;
    // 0x80803860: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    skip_3:
L_80803864:
    // 0x80803864: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80803868:
    // 0x80803868: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8080386C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80803870: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80803874: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80803878: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x8080387C: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80803880: jr          $ra
    // 0x80803884: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80803884: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800C01D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C01D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C01DC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C01E0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800C01E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C01E8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C01EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C01F0: jal         0x80087E50
    // 0x800C01F4: addiu       $a0, $a0, -0x7750
    ctx->r4 = ADD32(ctx->r4, -0X7750);
    _gcdialogexec_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x800C01F4: addiu       $a0, $a0, -0x7750
    ctx->r4 = ADD32(ctx->r4, -0X7750);
    after_0:
    // 0x800C01F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C01FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C0200: jr          $ra
    // 0x800C0204: nop

    return;
    // 0x800C0204: nop

;}
RECOMP_FUNC void bamovespline_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800328: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080032C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800330: jal         0x808000F4
    // 0x80800334: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808000F4_bamovespline(rdram, ctx);
        goto after_0;
    // 0x80800334: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080033C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800340: jr          $ra
    // 0x80800344: nop

    return;
    // 0x80800344: nop

;}
RECOMP_FUNC void _chjigsaw_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800858A0: syscall     178
    recomp_syscall_handler(rdram, ctx, 0x800858A0);
    return;
    // 0x800858A4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800730_bscarry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800730: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800734: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800738: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080073C: jal         0x800839E8
    // 0x80800740: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800740: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800744: beq         $v0, $zero, L_80800750
    if (ctx->r2 == 0) {
        // 0x80800748: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80800750;
    }
    // 0x80800748: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080074C: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
L_80800750:
    // 0x80800750: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800754: jal         0x80084D40
    // 0x80800758: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    _bahold_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800758: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8080075C: bne         $v0, $zero, L_80800768
    if (ctx->r2 != 0) {
        // 0x80800760: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80800768;
    }
    // 0x80800760: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800764: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
L_80800768:
    // 0x80800768: jal         0x8009E5C8
    // 0x8080076C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x8080076C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800774: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800778: jr          $ra
    // 0x8080077C: nop

    return;
    // 0x8080077C: nop

;}
RECOMP_FUNC void func_800F497C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F497C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F4980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F4984: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F4988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F498C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F4990: jal         0x80084810
    // 0x800F4994: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    _badrone_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x800F4994: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F4998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F499C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F49A0: jr          $ra
    // 0x800F49A4: nop

    return;
    // 0x800F49A4: nop

;}
RECOMP_FUNC void bafpctrl_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CAC: lw          $t6, 0x90($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X90);
    // 0x80800CB0: jr          $ra
    // 0x80800CB4: sb          $a1, 0x12($t6)
    MEM_B(0X12, ctx->r14) = ctx->r5;
    return;
    // 0x80800CB4: sb          $a1, 0x12($t6)
    MEM_B(0X12, ctx->r14) = ctx->r5;
;}
