#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800BF4_cheggproximity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BF4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800BF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800BFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800C00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800C04: jal         0x80100094
    // 0x80800C08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800C0C: lw          $a3, 0xA0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XA0);
    // 0x80800C10: bltz        $a3, L_80800C88
    if (SIGNED(ctx->r7) < 0) {
        // 0x80800C14: sll         $t6, $a3, 2
        ctx->r14 = S32(ctx->r7 << 2);
            goto L_80800C88;
    }
    // 0x80800C14: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x80800C18: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80800C1C: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x80800C20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C28: bne         $t8, $at, L_80800C88
    if (ctx->r24 != ctx->r1) {
        // 0x80800C2C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80800C88;
    }
    // 0x80800C2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800C30: jal         0x80100094
    // 0x80800C34: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800C34: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800C38: lw          $t9, 0xA8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XA8);
    // 0x80800C3C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800C40: addiu       $a0, $zero, 0x2C4
    ctx->r4 = ADD32(0, 0X2C4);
    // 0x80800C44: beq         $t9, $zero, L_80800C5C
    if (ctx->r25 == 0) {
        // 0x80800C48: addiu       $a1, $zero, 0x74
        ctx->r5 = ADD32(0, 0X74);
            goto L_80800C5C;
    }
    // 0x80800C48: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
    // 0x80800C4C: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80800C50: jal         0x80101180
    // 0x80800C54: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80101180(rdram, ctx);
        goto after_2;
    // 0x80800C54: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_2:
    // 0x80800C58: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_80800C5C:
    // 0x80800C5C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800C60: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    // 0x80800C64: jal         0x800F7664
    // 0x80800C68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800F7664(rdram, ctx);
        goto after_3;
    // 0x80800C68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80800C6C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800C70: jal         0x8008A350
    // 0x80800C74: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    _sueggmisc_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800C74: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_4:
    // 0x80800C78: jal         0x800FFAB0
    // 0x80800C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x80800C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800C80: b           L_80800C8C
    // 0x80800C84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800C8C;
    // 0x80800C84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C88:
    // 0x80800C88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C8C:
    // 0x80800C8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800C94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800C98: jr          $ra
    // 0x80800C9C: nop

    return;
    // 0x80800C9C: nop

;}
RECOMP_FUNC void func_808011F4_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808011F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808011FC: jal         0x80082FE8
    // 0x80801200: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80801200: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801204: jal         0x80800F94
    // 0x80801208: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstnt_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80801208: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080120C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801210: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801214: jr          $ra
    // 0x80801218: nop

    return;
    // 0x80801218: nop

;}
RECOMP_FUNC void gccubesearch_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800194: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x80800198: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080019C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808001A0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808001A4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808001A8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808001AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001B0: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x808001B4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808001B8: lui         $s2, 0x7FFF
    ctx->r18 = S32(0X7FFF << 16);
    // 0x808001BC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808001C0: ori         $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 | 0XFFFF;
    // 0x808001C4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x808001C8: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x808001CC: nop

    // 0x808001D0: sh          $t7, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r15;
    // 0x808001D4: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x808001D8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808001DC: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x808001E0: nop

    // 0x808001E4: sh          $t9, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r25;
    // 0x808001E8: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x808001EC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x808001F0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808001F4: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x808001F8: bne         $a2, $zero, L_80800214
    if (ctx->r6 != 0) {
        // 0x808001FC: sh          $t1, 0x38($sp)
        MEM_H(0X38, ctx->r29) = ctx->r9;
            goto L_80800214;
    }
    // 0x808001FC: sh          $t1, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r9;
    // 0x80800200: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80800204: jal         0x808002E8
    // 0x80800208: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    gccubesearch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800208: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_0:
    // 0x8080020C: b           L_80800220
    // 0x80800210: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
        goto L_80800220;
    // 0x80800210: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_80800214:
    // 0x80800214: jal         0x80800380
    // 0x80800218: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    gccubesearch_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800218: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_1:
    // 0x8080021C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_80800220:
    // 0x80800220: bne         $v0, $zero, L_80800230
    if (ctx->r2 != 0) {
        // 0x80800224: nop
    
            goto L_80800230;
    }
    // 0x80800224: nop

    // 0x80800228: b           L_80800288
    // 0x8080022C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800288;
    // 0x8080022C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800230:
    // 0x80800230: blez        $v0, L_80800284
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800234: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80800284;
    }
    // 0x80800234: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800238: addiu       $s0, $sp, 0x4C
    ctx->r16 = ADD32(ctx->r29, 0X4C);
L_8080023C:
    // 0x8080023C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80800240: lh          $t2, 0x34($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X34);
    // 0x80800244: lh          $t4, 0x36($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X36);
    // 0x80800248: lh          $t6, 0x38($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X38);
    // 0x8080024C: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x80800250: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
    // 0x80800254: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x80800258: subu        $a0, $t2, $t3
    ctx->r4 = SUB32(ctx->r10, ctx->r11);
    // 0x8080025C: subu        $a1, $t4, $t5
    ctx->r5 = SUB32(ctx->r12, ctx->r13);
    // 0x80800260: jal         0x80800160
    // 0x80800264: subu        $a2, $t6, $t7
    ctx->r6 = SUB32(ctx->r14, ctx->r15);
    func_80800160_gccubesearch(rdram, ctx);
        goto after_2;
    // 0x80800264: subu        $a2, $t6, $t7
    ctx->r6 = SUB32(ctx->r14, ctx->r15);
    after_2:
    // 0x80800268: slt         $at, $v0, $s2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8080026C: beq         $at, $zero, L_8080027C
    if (ctx->r1 == 0) {
        // 0x80800270: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8080027C;
    }
    // 0x80800270: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800274: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800278: lw          $s4, 0x0($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X0);
L_8080027C:
    // 0x8080027C: bne         $s1, $s3, L_8080023C
    if (ctx->r17 != ctx->r19) {
        // 0x80800280: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8080023C;
    }
    // 0x80800280: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80800284:
    // 0x80800284: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_80800288:
    // 0x80800288: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8080028C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800290: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800294: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800298: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8080029C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808002A0: jr          $ra
    // 0x808002A4: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x808002A4: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void func_80800E2C_chbiggafoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E30: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800E34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E38: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800E3C: bne         $a1, $at, L_80800E80
    if (ctx->r5 != ctx->r1) {
        // 0x80800E40: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800E80;
    }
    // 0x80800E40: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800E44: jal         0x80101080
    // 0x80800E48: nop

    func_80101080(rdram, ctx);
        goto after_0;
    // 0x80800E48: nop

    after_0:
    // 0x80800E4C: jal         0x80106790
    // 0x80800E50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80800E50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800E54: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800E58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800E5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800E60: jal         0x800866A0
    // 0x80800E64: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800E64: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x80800E68: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E6C: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    // 0x80800E70: jal         0x80086688
    // 0x80800E74: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    _chexploder_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80800E74: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    after_3:
    // 0x80800E78: b           L_80800E88
    // 0x80800E7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800E88;
    // 0x80800E7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E80:
    // 0x80800E80: b           L_80800E88
    // 0x80800E84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800E88;
    // 0x80800E84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800E88:
    // 0x80800E88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800E90: jr          $ra
    // 0x80800E94: nop

    return;
    // 0x80800E94: nop

;}
RECOMP_FUNC void _chexploder_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800866C0: syscall     354
    recomp_syscall_handler(rdram, ctx, 0x800866C0);
    return;
    // 0x800866C4: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_80020E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020E40: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80020E44: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80020E48: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80020E4C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80020E50: beq         $t7, $zero, L_80020E60
    if (ctx->r15 == 0) {
        // 0x80020E54: nop
    
            goto L_80020E60;
    }
    // 0x80020E54: nop

    // 0x80020E58: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80020E5C: sw          $a0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r4;
L_80020E60:
    // 0x80020E60: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x80020E64: jr          $ra
    // 0x80020E68: nop

    return;
    // 0x80020E68: nop

;}
RECOMP_FUNC void func_800942D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800942D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800942D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800942D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800942DC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800942E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800942E4: jal         0x8001BDAC
    // 0x800942E8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8001BDAC(rdram, ctx);
        goto after_0;
    // 0x800942E8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800942EC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800942F0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800942F4: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x800942F8: lw          $t7, 0x50($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X50);
    // 0x800942FC: lui         $at, 0x3
    ctx->r1 = S32(0X3 << 16);
    // 0x80094300: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80094304: lw          $t8, 0x110($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X110);
    // 0x80094308: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8009430C: ori         $at, $at, 0x2001
    ctx->r1 = ctx->r1 | 0X2001;
    // 0x80094310: beql        $t8, $zero, L_8009432C
    if (ctx->r24 == 0) {
        // 0x80094314: lw          $v0, 0x1C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X1C);
            goto L_8009432C;
    }
    goto skip_0;
    // 0x80094314: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80094318: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8009431C: lw          $t2, 0x7DD4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DD4);
    // 0x80094320: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80094324: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80094328: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8009432C:
    // 0x8009432C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80094330: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80094334: slt         $t4, $v0, $at
    ctx->r12 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80094338: jr          $ra
    // 0x8009433C: xori        $v0, $t4, 0x1
    ctx->r2 = ctx->r12 ^ 0X1;
    return;
    // 0x8009433C: xori        $v0, $t4, 0x1
    ctx->r2 = ctx->r12 ^ 0X1;
;}
RECOMP_FUNC void _bawandglow_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800853E0: syscall     160
    recomp_syscall_handler(rdram, ctx, 0x800853E0);
    return;
    // 0x800853E4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void bsbabykaz_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800694: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800698: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080069C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808006A0: jal         0x8008DD70
    // 0x808006A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8008DD70(rdram, ctx);
        goto after_0;
    // 0x808006A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808006A8: bne         $v0, $zero, L_80800708
    if (ctx->r2 != 0) {
        // 0x808006AC: nop
    
            goto L_80800708;
    }
    // 0x808006AC: nop

    // 0x808006B0: jal         0x80084498
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bababykaz_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808006B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808006BC: beq         $v0, $at, L_808006DC
    if (ctx->r2 == ctx->r1) {
        // 0x808006C0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808006DC;
    }
    // 0x808006C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006C4: jal         0x800F7180
    // 0x808006C8: nop

    func_800F7180(rdram, ctx);
        goto after_2;
    // 0x808006C8: nop

    after_2:
    // 0x808006CC: bne         $v0, $zero, L_808006DC
    if (ctx->r2 != 0) {
        // 0x808006D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006DC;
    }
    // 0x808006D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D4: jal         0x800844A8
    // 0x808006D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bababykaz_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x808006D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_808006DC:
    // 0x808006DC: jal         0x8008E078
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_4;
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808006E4: beq         $v0, $zero, L_80800708
    if (ctx->r2 == 0) {
        // 0x808006E8: nop
    
            goto L_80800708;
    }
    // 0x808006E8: nop

    // 0x808006EC: jal         0x80096694
    // 0x808006F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096694(rdram, ctx);
        goto after_5;
    // 0x808006F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808006F4: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x808006F8: bne         $v0, $at, L_80800708
    if (ctx->r2 != ctx->r1) {
        // 0x808006FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800708;
    }
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800700: jal         0x800844A8
    // 0x80800704: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bababykaz_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x80800704: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
L_80800708:
    // 0x80800708: jal         0x8080005C
    // 0x8080070C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080005C_bsbabykaz(rdram, ctx);
        goto after_7;
    // 0x8080070C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800710: jal         0x800844C8
    // 0x80800714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bababykaz_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80800714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800718: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080071C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800720: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800724: jr          $ra
    // 0x80800728: nop

    return;
    // 0x80800728: nop

;}
RECOMP_FUNC void chchuffy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002F4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808002F8: jal         0x80106790
    // 0x808002FC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808002FC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800300: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800304: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800308: jal         0x80100094
    // 0x8080030C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080030C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800310: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800314: addiu       $a1, $v0, 0x4C
    ctx->r5 = ADD32(ctx->r2, 0X4C);
    // 0x80800318: jal         0x800EE7F8
    // 0x8080031C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x8080031C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800320: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80800324: addiu       $a0, $v1, 0x4C
    ctx->r4 = ADD32(ctx->r3, 0X4C);
    // 0x80800328: addiu       $a1, $v1, 0x58
    ctx->r5 = ADD32(ctx->r3, 0X58);
    // 0x8080032C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80800330: jal         0x800F1828
    // 0x80800334: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800F1828(rdram, ctx);
        goto after_3;
    // 0x80800334: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_3:
    // 0x80800338: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8080033C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800340: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800344: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800348: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8080034C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800350: jal         0x800F1DF4
    // 0x80800354: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    func_800F1DF4(rdram, ctx);
        goto after_4;
    // 0x80800354: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    after_4:
    // 0x80800358: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8080035C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800360: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800364: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x80800368: swc1        $f8, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f8.u32l;
    // 0x8080036C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80800370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800374: lhu         $t9, 0x72($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X72);
    // 0x80800378: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x8080037C: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x80800380: beq         $at, $zero, L_80800390
    if (ctx->r1 == 0) {
        // 0x80800384: nop
    
            goto L_80800390;
    }
    // 0x80800384: nop

    // 0x80800388: b           L_80800390
    // 0x8080038C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800390;
    // 0x8080038C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800390:
    // 0x80800390: jr          $ra
    // 0x80800394: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800394: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800260_chdrips(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800260: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800264: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800268: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8080026C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800270: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800274: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1816, 0X600) << 16);
    // 0x80800278: lwc1        $f6, 0x600($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1816, 0X600));
    // 0x8080027C: lwc1        $f4, 0x48($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80800280: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1816, 0X604) << 16);
    // 0x80800284: lwc1        $f10, 0x604($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1816, 0X604));
    // 0x80800288: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080028C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800290: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800294: jal         0x800DC298
    // 0x80800298: nop

    func_800DC298(rdram, ctx);
        goto after_0;
    // 0x80800298: nop

    after_0:
    // 0x8080029C: beq         $v0, $zero, L_8080037C
    if (ctx->r2 == 0) {
        // 0x808002A0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080037C;
    }
    // 0x808002A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808002A4: jal         0x80100094
    // 0x808002A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808002A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808002AC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808002B0: jal         0x800B53A4
    // 0x808002B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800B53A4(rdram, ctx);
        goto after_2;
    // 0x808002B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x808002B8: lw          $t6, 0x6C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X6C);
    // 0x808002BC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808002C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002C4: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x808002C8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x808002CC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x808002D0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808002D4: addu        $s0, $s0, $t8
    ctx->r16 = ADD32(ctx->r16, ctx->r24);
    // 0x808002D8: lbu         $t9, 0x10($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X10);
    // 0x808002DC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x808002E0: beq         $t9, $zero, L_80800300
    if (ctx->r25 == 0) {
        // 0x808002E4: nop
    
            goto L_80800300;
    }
    // 0x808002E4: nop

    // 0x808002E8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x808002EC: addiu       $a1, $a1, 0x6E50
    ctx->r5 = ADD32(ctx->r5, 0X6E50);
    // 0x808002F0: jal         0x800BA544
    // 0x808002F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800BA544(rdram, ctx);
        goto after_3;
    // 0x808002F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x808002F8: b           L_8080030C
    // 0x808002FC: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
        goto L_8080030C;
    // 0x808002FC: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
L_80800300:
    // 0x80800300: jal         0x800BA544
    // 0x80800304: addiu       $a1, $a1, 0x6E58
    ctx->r5 = ADD32(ctx->r5, 0X6E58);
    func_800BA544(rdram, ctx);
        goto after_4;
    // 0x80800304: addiu       $a1, $a1, 0x6E58
    ctx->r5 = ADD32(ctx->r5, 0X6E58);
    after_4:
    // 0x80800308: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
L_8080030C:
    // 0x8080030C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800310: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800314: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800318: nop

    // 0x8080031C: sll         $t1, $a1, 16
    ctx->r9 = S32(ctx->r5 << 16);
    // 0x80800320: jal         0x800BA4D0
    // 0x80800324: sra         $a1, $t1, 16
    ctx->r5 = S32(SIGNED(ctx->r9) >> 16);
    func_800BA4D0(rdram, ctx);
        goto after_5;
    // 0x80800324: sra         $a1, $t1, 16
    ctx->r5 = S32(SIGNED(ctx->r9) >> 16);
    after_5:
    // 0x80800328: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(1816, 0X698) << 16);
    // 0x8080032C: addiu       $t3, $t3, 0x698
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(1816, 0X698));
    // 0x80800330: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800334: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800338: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080033C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800340: jal         0x800BABB8
    // 0x80800344: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_6;
    // 0x80800344: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_6:
    // 0x80800348: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080034C: jal         0x800BA22C
    // 0x80800350: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_7;
    // 0x80800350: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800354: lhu         $a1, 0x76($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X76);
    // 0x80800358: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080035C: srl         $t4, $a1, 7
    ctx->r12 = S32(U32(ctx->r5) >> 7);
    // 0x80800360: jal         0x800DC128
    // 0x80800364: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    func_800DC128(rdram, ctx);
        goto after_8;
    // 0x80800364: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    after_8:
    // 0x80800368: lhu         $t7, 0x6E($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X6E);
    // 0x8080036C: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x80800370: andi        $t8, $t7, 0xFE00
    ctx->r24 = ctx->r15 & 0XFE00;
    // 0x80800374: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80800378: sh          $t9, 0x6E($s2)
    MEM_H(0X6E, ctx->r18) = ctx->r25;
L_8080037C:
    // 0x8080037C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800380: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800384: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800388: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8080038C: jr          $ra
    // 0x80800390: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800390: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void baduo_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: lw          $t6, 0x58($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X58);
    // 0x808000BC: jr          $ra
    // 0x808000C0: lbu         $v0, 0x2($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X2);
    return;
    // 0x808000C0: lbu         $v0, 0x2($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X2);
;}
RECOMP_FUNC void func_808014B0_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014B0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808014B4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808014B8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808014BC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808014C0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x808014C4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x808014C8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808014CC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808014D0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808014D4: jal         0x80106790
    // 0x808014D8: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808014D8: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x808014DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808014E0: jal         0x80100094
    // 0x808014E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808014E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808014E8: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808014EC: jal         0x800CEAA8
    // 0x808014F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAA8(rdram, ctx);
        goto after_2;
    // 0x808014F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x808014F4: beql        $v0, $zero, L_808015E8
    if (ctx->r2 == 0) {
        // 0x808014F8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808015E8;
    }
    goto skip_0;
    // 0x808014F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x808014FC: jal         0x800CEAD0
    // 0x80801500: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_3;
    // 0x80801500: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80801504: bnel        $v0, $zero, L_808015E8
    if (ctx->r2 != 0) {
        // 0x80801508: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808015E8;
    }
    goto skip_1;
    // 0x80801508: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x8080150C: jal         0x80088368
    // 0x80801510: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80801510: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_4:
    // 0x80801514: blez        $v0, L_808015E4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801518: addiu       $s5, $zero, 0x3
        ctx->r21 = ADD32(0, 0X3);
            goto L_808015E4;
    }
    // 0x80801518: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x8080151C: addiu       $s3, $sp, 0x44
    ctx->r19 = ADD32(ctx->r29, 0X44);
L_80801520:
    // 0x80801520: jal         0x800F6C5C
    // 0x80801524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6C5C(rdram, ctx);
        goto after_5;
    // 0x80801524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801528: beq         $v0, $zero, L_808015D0
    if (ctx->r2 == 0) {
        // 0x8080152C: nop
    
            goto L_808015D0;
    }
    // 0x8080152C: nop

    // 0x80801530: jal         0x800F55FC
    // 0x80801534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F55FC(rdram, ctx);
        goto after_6;
    // 0x80801534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801538: lw          $t6, 0x28($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X28);
    // 0x8080153C: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80801540: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x80801544: and         $t7, $t6, $v0
    ctx->r15 = ctx->r14 & ctx->r2;
    // 0x80801548: beq         $t7, $zero, L_808015D0
    if (ctx->r15 == 0) {
        // 0x8080154C: nop
    
            goto L_808015D0;
    }
    // 0x8080154C: nop

    // 0x80801550: lw          $t0, 0x2C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X2C);
    // 0x80801554: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80801558: addu        $a3, $s4, $t8
    ctx->r7 = ADD32(ctx->r20, ctx->r24);
    // 0x8080155C: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x80801560: addu        $t1, $a3, $t9
    ctx->r9 = ADD32(ctx->r7, ctx->r25);
    // 0x80801564: lw          $v1, 0x40($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X40);
    // 0x80801568: subu        $t2, $s5, $t0
    ctx->r10 = SUB32(ctx->r21, ctx->r8);
    // 0x8080156C: blez        $v1, L_808015D0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80801570: nop
    
            goto L_808015D0;
    }
    // 0x80801570: nop

    // 0x80801574: multu       $t2, $v1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80801578: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x8080157C: addu        $v0, $s4, $t3
    ctx->r2 = ADD32(ctx->r20, ctx->r11);
    // 0x80801580: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80801584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801588: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8080158C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80801590: mflo        $s1
    ctx->r17 = lo;
    // 0x80801594: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80801598: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8080159C: lw          $t6, 0x2C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X2C);
    // 0x808015A0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x808015A4: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x808015A8: jal         0x800F5A2C
    // 0x808015AC: sw          $zero, 0x40($t8)
    MEM_W(0X40, ctx->r24) = 0;
    func_800F5A2C(rdram, ctx);
        goto after_7;
    // 0x808015AC: sw          $zero, 0x40($t8)
    MEM_W(0X40, ctx->r24) = 0;
    after_7:
    // 0x808015B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808015B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808015B8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x808015BC: jal         0x80086468
    // 0x808015C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _chscorepoints_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x808015C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x808015C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808015C8: jal         0x80108B04
    // 0x808015CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80108B04(rdram, ctx);
        goto after_9;
    // 0x808015CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
L_808015D0:
    // 0x808015D0: jal         0x80088368
    // 0x808015D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_10;
    // 0x808015D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_10:
    // 0x808015D8: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808015DC: bne         $at, $zero, L_80801520
    if (ctx->r1 != 0) {
        // 0x808015E0: nop
    
            goto L_80801520;
    }
    // 0x808015E0: nop

L_808015E4:
    // 0x808015E4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808015E8:
    // 0x808015E8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808015EC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808015F0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808015F4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808015F8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x808015FC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80801600: jr          $ra
    // 0x80801604: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80801604: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800DC4B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC4B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DC4B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DC4B8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800DC4BC: jal         0x80020C08
    // 0x800DC4C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80020C08(rdram, ctx);
        goto after_0;
    // 0x800DC4C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x800DC4C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DC4C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DC4CC: jr          $ra
    // 0x800DC4D0: nop

    return;
    // 0x800DC4D0: nop

;}
RECOMP_FUNC void func_80800254_basub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800254: lw          $v1, 0x130($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X130);
    // 0x80800258: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8080025C: lw          $t6, 0x2C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2C);
    // 0x80800260: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800264: bnel        $t6, $zero, L_80800288
    if (ctx->r14 != 0) {
        // 0x80800268: lw          $t9, 0x30($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X30);
            goto L_80800288;
    }
    goto skip_0;
    // 0x80800268: lw          $t9, 0x30($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X30);
    skip_0:
    // 0x8080026C: sw          $a1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r5;
    // 0x80800270: lw          $v1, 0x130($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X130);
    // 0x80800274: lw          $t7, 0x28($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X28);
    // 0x80800278: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8080027C: jr          $ra
    // 0x80800280: sw          $t8, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r24;
    return;
    // 0x80800280: sw          $t8, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r24;
    // 0x80800284: lw          $t9, 0x30($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X30);
L_80800288:
    // 0x80800288: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8080028C: addiu       $a2, $v1, 0x8
    ctx->r6 = ADD32(ctx->r3, 0X8);
    // 0x80800290: bnel        $t9, $zero, L_808002B4
    if (ctx->r25 != 0) {
        // 0x80800294: addiu       $v0, $zero, 0x28
        ctx->r2 = ADD32(0, 0X28);
            goto L_808002B4;
    }
    goto skip_1;
    // 0x80800294: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    skip_1:
    // 0x80800298: sw          $a3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r7;
    // 0x8080029C: lw          $v1, 0x130($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X130);
    // 0x808002A0: lw          $t0, 0x28($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X28);
    // 0x808002A4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x808002A8: jr          $ra
    // 0x808002AC: sw          $t1, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r9;
    return;
    // 0x808002AC: sw          $t1, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r9;
    // 0x808002B0: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
L_808002B4:
    // 0x808002B4: lw          $t2, 0x2C($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X2C);
    // 0x808002B8: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x808002BC: bnel        $t2, $zero, L_808002E0
    if (ctx->r10 != 0) {
        // 0x808002C0: lw          $t5, 0x30($a2)
        ctx->r13 = MEM_W(ctx->r6, 0X30);
            goto L_808002E0;
    }
    goto skip_2;
    // 0x808002C0: lw          $t5, 0x30($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X30);
    skip_2:
    // 0x808002C4: sw          $a3, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r7;
    // 0x808002C8: lw          $v1, 0x130($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X130);
    // 0x808002CC: lw          $t3, 0x28($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X28);
    // 0x808002D0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x808002D4: jr          $ra
    // 0x808002D8: sw          $t4, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r12;
    return;
    // 0x808002D8: sw          $t4, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r12;
    // 0x808002DC: lw          $t5, 0x30($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X30);
L_808002E0:
    // 0x808002E0: bnel        $t5, $zero, L_80800304
    if (ctx->r13 != 0) {
        // 0x808002E4: lw          $t8, 0x34($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X34);
            goto L_80800304;
    }
    goto skip_3;
    // 0x808002E4: lw          $t8, 0x34($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X34);
    skip_3:
    // 0x808002E8: sw          $a3, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->r7;
    // 0x808002EC: lw          $v1, 0x130($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X130);
    // 0x808002F0: lw          $t6, 0x28($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X28);
    // 0x808002F4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x808002F8: jr          $ra
    // 0x808002FC: sw          $t7, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r15;
    return;
    // 0x808002FC: sw          $t7, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r15;
    // 0x80800300: lw          $t8, 0x34($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X34);
L_80800304:
    // 0x80800304: bnel        $t8, $zero, L_80800328
    if (ctx->r24 != 0) {
        // 0x80800308: lw          $t1, 0x38($a2)
        ctx->r9 = MEM_W(ctx->r6, 0X38);
            goto L_80800328;
    }
    goto skip_4;
    // 0x80800308: lw          $t1, 0x38($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X38);
    skip_4:
    // 0x8080030C: sw          $a3, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->r7;
    // 0x80800310: lw          $v1, 0x130($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X130);
    // 0x80800314: lw          $t9, 0x28($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X28);
    // 0x80800318: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8080031C: jr          $ra
    // 0x80800320: sw          $t0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r8;
    return;
    // 0x80800320: sw          $t0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r8;
    // 0x80800324: lw          $t1, 0x38($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X38);
L_80800328:
    // 0x80800328: bne         $t1, $zero, L_80800348
    if (ctx->r9 != 0) {
        // 0x8080032C: nop
    
            goto L_80800348;
    }
    // 0x8080032C: nop

    // 0x80800330: sw          $a3, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->r7;
    // 0x80800334: lw          $v1, 0x130($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X130);
    // 0x80800338: lw          $t2, 0x28($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X28);
    // 0x8080033C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80800340: jr          $ra
    // 0x80800344: sw          $t3, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r11;
    return;
    // 0x80800344: sw          $t3, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r11;
L_80800348:
    // 0x80800348: bne         $a1, $v0, L_808002B4
    if (ctx->r5 != ctx->r2) {
        // 0x8080034C: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_808002B4;
    }
    // 0x8080034C: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80800350: jr          $ra
    // 0x80800354: nop

    return;
    // 0x80800354: nop

;}
RECOMP_FUNC void _bsmumswim_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800838E0: syscall     81
    recomp_syscall_handler(rdram, ctx, 0x800838E0);
    return;
    // 0x800838E4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_801135D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801135D0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801135D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801135D8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x801135DC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x801135E0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x801135E4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x801135E8: jal         0x800EFB24
    // 0x801135EC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x801135EC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x801135F0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x801135F4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x801135F8: jal         0x800EFB24
    // 0x801135FC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x801135FC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x80113600: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80113604: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80113608: jal         0x800EFB24
    // 0x8011360C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x8011360C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80113610: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80113614: jal         0x800EEAA4
    // 0x80113618: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800EEAA4(rdram, ctx);
        goto after_3;
    // 0x80113618: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x8011361C: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x80113620: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80113624: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80113628: jal         0x800EF174
    // 0x8011362C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    func_800EF174(rdram, ctx);
        goto after_4;
    // 0x8011362C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_4:
    // 0x80113630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80113634: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80113638: jr          $ra
    // 0x8011363C: nop

    return;
    // 0x8011363C: nop

;}
RECOMP_FUNC void subaddie3d_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800094: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800098: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080009C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x808000A0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x808000A4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x808000A8: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x808000AC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x808000B0: jal         0x800EE7F8
    // 0x808000B4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808000B4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x808000B8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808000BC: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808000C0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x808000C4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x808000C8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808000CC: jal         0x800EE7F8
    // 0x808000D0: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808000D0: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x808000D4: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808000D8: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808000DC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808000E0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x808000E4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808000E8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x808000EC: addiu       $a3, $zero, 0x1F00
    ctx->r7 = ADD32(0, 0X1F00);
    // 0x808000F0: jal         0x800BEF00
    // 0x808000F4: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    func_800BEF00(rdram, ctx);
        goto after_2;
    // 0x808000F4: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x808000F8: beq         $v0, $zero, L_80800110
    if (ctx->r2 == 0) {
        // 0x808000FC: lwc1        $f4, 0x20($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
            goto L_80800110;
    }
    // 0x808000FC: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800100: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80800104: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800108: b           L_80800114
    // 0x8080010C: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
        goto L_80800114;
    // 0x8080010C: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
L_80800110:
    // 0x80800110: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800114:
    // 0x80800114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800118: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080011C: jr          $ra
    // 0x80800120: nop

    return;
    // 0x80800120: nop

    // 0x80800124: nop

    // 0x80800128: nop

    // 0x8080012C: nop

;}
RECOMP_FUNC void _bsfirstp_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084300: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x80084300);
    return;
    // 0x80084304: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void func_808004F8_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800500: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80800504: lwc1        $f4, 0x20C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20C);
    // 0x80800508: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080050C: jal         0x8009C984
    // 0x80800510: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    yaw_get(rdram, ctx);
        goto after_0;
    // 0x80800510: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80800514: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80800518: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080051C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800520: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    // 0x80800524: jal         0x800EEC70
    // 0x80800528: addiu       $a0, $v0, 0x2C
    ctx->r4 = ADD32(ctx->r2, 0X2C);
    func_800EEC70(rdram, ctx);
        goto after_1;
    // 0x80800528: addiu       $a0, $v0, 0x2C
    ctx->r4 = ADD32(ctx->r2, 0X2C);
    after_1:
    // 0x8080052C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800530: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800534: jr          $ra
    // 0x80800538: nop

    return;
    // 0x80800538: nop

;}
RECOMP_FUNC void func_800E70DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E70DC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800E70E0: beql        $v0, $zero, L_800E7128
    if (ctx->r2 == 0) {
        // 0x800E70E4: lbu         $a0, 0x0($a1)
        ctx->r4 = MEM_BU(ctx->r5, 0X0);
            goto L_800E7128;
    }
    goto skip_0;
    // 0x800E70E4: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    skip_0:
    // 0x800E70E8: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800E70EC: beql        $v1, $zero, L_800E7128
    if (ctx->r3 == 0) {
        // 0x800E70F0: lbu         $a0, 0x0($a1)
        ctx->r4 = MEM_BU(ctx->r5, 0X0);
            goto L_800E7128;
    }
    goto skip_1;
    // 0x800E70F0: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    skip_1:
    // 0x800E70F4: bnel        $v0, $v1, L_800E7128
    if (ctx->r2 != ctx->r3) {
        // 0x800E70F8: lbu         $a0, 0x0($a1)
        ctx->r4 = MEM_BU(ctx->r5, 0X0);
            goto L_800E7128;
    }
    goto skip_2;
    // 0x800E70F8: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    skip_2:
    // 0x800E70FC: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
L_800E7100:
    // 0x800E7100: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800E7104: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800E7108: beql        $v0, $zero, L_800E7128
    if (ctx->r2 == 0) {
        // 0x800E710C: lbu         $a0, 0x0($a1)
        ctx->r4 = MEM_BU(ctx->r5, 0X0);
            goto L_800E7128;
    }
    goto skip_3;
    // 0x800E710C: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    skip_3:
    // 0x800E7110: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800E7114: beql        $v1, $zero, L_800E7128
    if (ctx->r3 == 0) {
        // 0x800E7118: lbu         $a0, 0x0($a1)
        ctx->r4 = MEM_BU(ctx->r5, 0X0);
            goto L_800E7128;
    }
    goto skip_4;
    // 0x800E7118: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    skip_4:
    // 0x800E711C: beql        $v0, $v1, L_800E7100
    if (ctx->r2 == ctx->r3) {
        // 0x800E7120: lbu         $v0, 0x1($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X1);
            goto L_800E7100;
    }
    goto skip_5;
    // 0x800E7120: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    skip_5:
    // 0x800E7124: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
L_800E7128:
    // 0x800E7128: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800E712C: bne         $v0, $a0, L_800E713C
    if (ctx->r2 != ctx->r4) {
        // 0x800E7130: nop
    
            goto L_800E713C;
    }
    // 0x800E7130: nop

    // 0x800E7134: jr          $ra
    // 0x800E7138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800E7138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E713C:
    // 0x800E713C: beq         $v1, $zero, L_800E714C
    if (ctx->r3 == 0) {
        // 0x800E7140: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800E714C;
    }
    // 0x800E7140: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800E7144: beq         $at, $zero, L_800E7154
    if (ctx->r1 == 0) {
        // 0x800E7148: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800E7154;
    }
    // 0x800E7148: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E714C:
    // 0x800E714C: jr          $ra
    // 0x800E7150: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800E7150: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800E7154:
    // 0x800E7154: jr          $ra
    // 0x800E7158: nop

    return;
    // 0x800E7158: nop

;}
RECOMP_FUNC void func_80802754_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802754: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802758: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080275C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80802760: jal         0x800A3280
    // 0x80802764: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800A3280(rdram, ctx);
        goto after_0;
    // 0x80802764: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80802768: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8080276C: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x80802770: lui         $t7, 0x8081
    ctx->r15 = S32(RELOC_HI16(439, 0XB168) << 16);
    // 0x80802774: addiu       $t7, $t7, -0x4E98
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(439, 0XB168));
    // 0x80802778: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x8080277C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80802780: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80802784: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80802788: lui         $t0, 0x8081
    ctx->r8 = S32(RELOC_HI16(439, 0XB190) << 16);
    // 0x8080278C: addiu       $t0, $t0, -0x4E70
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(439, 0XB190));
    // 0x80802790: addu        $t1, $t6, $t0
    ctx->r9 = ADD32(ctx->r14, ctx->r8);
    // 0x80802794: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80802798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080279C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808027A0: jr          $ra
    // 0x808027A4: nop

    return;
    // 0x808027A4: nop

;}
RECOMP_FUNC void _chfactorytwinklies_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086520: syscall     333
    recomp_syscall_handler(rdram, ctx, 0x80086520);
    return;
    // 0x80086524: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80806370_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806370: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80806374: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80806378: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080637C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80806380: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80806384: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80806388: jal         0x80088360
    // 0x8080638C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    _gcstatusDll_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x8080638C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80806390: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80806394: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80806398: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080639C: lbu         $t6, 0x65($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X65);
    // 0x808063A0: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x808063A4: blez        $v0, L_808063D8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808063A8: sb          $t7, 0x65($v1)
        MEM_B(0X65, ctx->r3) = ctx->r15;
            goto L_808063D8;
    }
    // 0x808063A8: sb          $t7, 0x65($v1)
    MEM_B(0X65, ctx->r3) = ctx->r15;
    // 0x808063AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808063B0:
    // 0x808063B0: jal         0x80087D38
    // 0x808063B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gcnewoption_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x808063B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x808063B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808063BC: jal         0x808062CC
    // 0x808063C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_808062CC_chgameselect(rdram, ctx);
        goto after_2;
    // 0x808063C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x808063C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808063C8: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x808063CC: bnel        $at, $zero, L_808063B0
    if (ctx->r1 != 0) {
        // 0x808063D0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808063B0;
    }
    goto skip_0;
    // 0x808063D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x808063D4: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
L_808063D8:
    // 0x808063D8: jal         0x80802BE8
    // 0x808063DC: lw          $a0, 0x30($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X30);
    func_80802BE8_chgameselect(rdram, ctx);
        goto after_3;
    // 0x808063DC: lw          $a0, 0x30($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X30);
    after_3:
    // 0x808063E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808063E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808063E8: jal         0x80100074
    // 0x808063EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80100074(rdram, ctx);
        goto after_4;
    // 0x808063EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x808063F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808063F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808063F8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808063FC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80806400: jr          $ra
    // 0x80806404: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80806404: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_808022D8_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808022D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808022DC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808022E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808022E4: beq         $a1, $at, L_80802320
    if (ctx->r5 == ctx->r1) {
        // 0x808022E8: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80802320;
    }
    // 0x808022E8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808022EC: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x808022F0: beq         $a1, $at, L_80802308
    if (ctx->r5 == ctx->r1) {
        // 0x808022F4: addiu       $at, $zero, 0x4F
        ctx->r1 = ADD32(0, 0X4F);
            goto L_80802308;
    }
    // 0x808022F4: addiu       $at, $zero, 0x4F
    ctx->r1 = ADD32(0, 0X4F);
    // 0x808022F8: beq         $a1, $at, L_80802350
    if (ctx->r5 == ctx->r1) {
        // 0x808022FC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80802350;
    }
    // 0x808022FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80802300: b           L_80802374
    // 0x80802304: nop

        goto L_80802374;
    // 0x80802304: nop

L_80802308:
    // 0x80802308: jal         0x801015D0
    // 0x8080230C: nop

    func_801015D0(rdram, ctx);
        goto after_0;
    // 0x8080230C: nop

    after_0:
    // 0x80802310: jal         0x800DF830
    // 0x80802314: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF830(rdram, ctx);
        goto after_1;
    // 0x80802314: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x80802318: b           L_80802374
    // 0x8080231C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802374;
    // 0x8080231C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802320:
    // 0x80802320: lbu         $t7, 0x65($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X65);
    // 0x80802324: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80802328: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x8080232C: jal         0x80101FDC
    // 0x80802330: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80802330: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
    after_2:
    // 0x80802334: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802338: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8080233C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80802340: jal         0x800187B4
    // 0x80802344: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    func_800187B4(rdram, ctx);
        goto after_3;
    // 0x80802344: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_3:
    // 0x80802348: b           L_80802374
    // 0x8080234C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802374;
    // 0x8080234C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802350:
    // 0x80802350: jal         0x80101FDC
    // 0x80802354: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80802354: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x80802358: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080235C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80802360: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80802364: jal         0x800187B4
    // 0x80802368: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    func_800187B4(rdram, ctx);
        goto after_5;
    // 0x80802368: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_5:
    // 0x8080236C: b           L_80802374
    // 0x80802370: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802374;
    // 0x80802370: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802374:
    // 0x80802374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080237C: jr          $ra
    // 0x80802380: nop

    return;
    // 0x80802380: nop

;}
RECOMP_FUNC void func_800CE628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE628: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800CE62C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800CE630: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x800CE634: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x800CE638: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x800CE63C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x800CE640: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800CE644: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800CE648: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800CE64C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800CE650: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800CE654: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800CE658: jal         0x800EA09C
    // 0x800CE65C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    func_800EA09C(rdram, ctx);
        goto after_0;
    // 0x800CE65C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    after_0:
    // 0x800CE660: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CE664: bnel        $v0, $at, L_800CE7A8
    if (ctx->r2 != ctx->r1) {
        // 0x800CE668: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_800CE7A8;
    }
    goto skip_0;
    // 0x800CE668: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x800CE66C: jal         0x800F54E4
    // 0x800CE670: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x800CE670: nop

    after_1:
    // 0x800CE674: jal         0x800D9004
    // 0x800CE678: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800D9004(rdram, ctx);
        goto after_2;
    // 0x800CE678: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_2:
    // 0x800CE67C: jal         0x800DB9B0
    // 0x800CE680: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_800DB9B0(rdram, ctx);
        goto after_3;
    // 0x800CE680: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_3:
    // 0x800CE684: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800CE688: jal         0x800F6D24
    // 0x800CE68C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6D24(rdram, ctx);
        goto after_4;
    // 0x800CE68C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800CE690: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800CE694: jal         0x800F8004
    // 0x800CE698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F8004(rdram, ctx);
        goto after_5;
    // 0x800CE698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800CE69C: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x800CE6A0: jal         0x800F68B8
    // 0x800CE6A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F68B8(rdram, ctx);
        goto after_6;
    // 0x800CE6A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800CE6A8: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800CE6AC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800CE6B0: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x800CE6B4: addiu       $s2, $s2, -0x55D0
    ctx->r18 = ADD32(ctx->r18, -0X55D0);
    // 0x800CE6B8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800CE6BC: addiu       $s4, $zero, 0x9
    ctx->r20 = ADD32(0, 0X9);
L_800CE6C0:
    // 0x800CE6C0: jal         0x800CE3E0
    // 0x800CE6C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800CE3E0(rdram, ctx);
        goto after_7;
    // 0x800CE6C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x800CE6C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800CE6CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CE6D0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800CE6D4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800CE6D8: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x800CE6DC: jal         0x800CE59C
    // 0x800CE6E0: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    func_800CE59C(rdram, ctx);
        goto after_8;
    // 0x800CE6E0: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    after_8:
    // 0x800CE6E4: lb          $t6, 0x12($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X12);
    // 0x800CE6E8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800CE6EC: blezl       $t6, L_800CE77C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800CE6F0: lh          $t0, 0x2($s2)
        ctx->r8 = MEM_H(ctx->r18, 0X2);
            goto L_800CE77C;
    }
    goto skip_1;
    // 0x800CE6F0: lh          $t0, 0x2($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X2);
    skip_1:
    // 0x800CE6F4: lbu         $t7, 0x13($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X13);
    // 0x800CE6F8: bnel        $t7, $zero, L_800CE77C
    if (ctx->r15 != 0) {
        // 0x800CE6FC: lh          $t0, 0x2($s2)
        ctx->r8 = MEM_H(ctx->r18, 0X2);
            goto L_800CE77C;
    }
    goto skip_2;
    // 0x800CE6FC: lh          $t0, 0x2($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X2);
    skip_2:
    // 0x800CE700: lbu         $t8, 0x14($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X14);
    // 0x800CE704: bnel        $t8, $zero, L_800CE77C
    if (ctx->r24 != 0) {
        // 0x800CE708: lh          $t0, 0x2($s2)
        ctx->r8 = MEM_H(ctx->r18, 0X2);
            goto L_800CE77C;
    }
    goto skip_3;
    // 0x800CE708: lh          $t0, 0x2($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X2);
    skip_3:
    // 0x800CE70C: beql        $v0, $zero, L_800CE77C
    if (ctx->r2 == 0) {
        // 0x800CE710: lh          $t0, 0x2($s2)
        ctx->r8 = MEM_H(ctx->r18, 0X2);
            goto L_800CE77C;
    }
    goto skip_4;
    // 0x800CE710: lh          $t0, 0x2($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X2);
    skip_4:
    // 0x800CE714: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800CE718: lh          $t9, 0xA($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XA);
    // 0x800CE71C: sub.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x800CE720: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x800CE724: sh          $t9, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r25;
    // 0x800CE728: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x800CE72C: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800CE730: c.lt.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl < ctx->f20.fl;
    // 0x800CE734: nop

    // 0x800CE738: bc1fl       L_800CE76C
    if (!c1cs) {
        // 0x800CE73C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800CE76C;
    }
    goto skip_5;
    // 0x800CE73C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
    // 0x800CE740: lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X18);
    // 0x800CE744: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
    // 0x800CE748: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CE74C: beql        $v1, $zero, L_800CE768
    if (ctx->r3 == 0) {
        // 0x800CE750: sb          $zero, 0x12($s0)
        MEM_B(0X12, ctx->r16) = 0;
            goto L_800CE768;
    }
    goto skip_6;
    // 0x800CE750: sb          $zero, 0x12($s0)
    MEM_B(0X12, ctx->r16) = 0;
    skip_6:
    // 0x800CE754: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x800CE758: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x800CE75C: jalr        $v1
    // 0x800CE760: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_9;
    // 0x800CE760: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    after_9:
    // 0x800CE764: sb          $zero, 0x12($s0)
    MEM_B(0X12, ctx->r16) = 0;
L_800CE768:
    // 0x800CE768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800CE76C:
    // 0x800CE76C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CE770: jal         0x800CE49C
    // 0x800CE774: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800CE49C(rdram, ctx);
        goto after_10;
    // 0x800CE774: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x800CE778: lh          $t0, 0x2($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X2);
L_800CE77C:
    // 0x800CE77C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CE780: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CE784: beql        $t0, $zero, L_800CE798
    if (ctx->r8 == 0) {
        // 0x800CE788: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800CE798;
    }
    goto skip_7;
    // 0x800CE788: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_7:
    // 0x800CE78C: jal         0x800CEC94
    // 0x800CE790: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800CEC94(rdram, ctx);
        goto after_11;
    // 0x800CE790: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_11:
    // 0x800CE794: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800CE798:
    // 0x800CE798: addiu       $s2, $s2, 0x6
    ctx->r18 = ADD32(ctx->r18, 0X6);
    // 0x800CE79C: bne         $s1, $s4, L_800CE6C0
    if (ctx->r17 != ctx->r20) {
        // 0x800CE7A0: sb          $zero, 0x14($s0)
        MEM_B(0X14, ctx->r16) = 0;
            goto L_800CE6C0;
    }
    // 0x800CE7A0: sb          $zero, 0x14($s0)
    MEM_B(0X14, ctx->r16) = 0;
    // 0x800CE7A4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_800CE7A8:
    // 0x800CE7A8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800CE7AC: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800CE7B0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800CE7B4: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800CE7B8: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800CE7BC: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800CE7C0: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800CE7C4: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x800CE7C8: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x800CE7CC: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x800CE7D0: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x800CE7D4: jr          $ra
    // 0x800CE7D8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800CE7D8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_808000C8_chcredits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D0: jal         0x80088830
    // 0x808000D4: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_0;
    // 0x808000D4: nop

    after_0:
    // 0x808000D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000E0: jr          $ra
    // 0x808000E4: nop

    return;
    // 0x808000E4: nop

;}
RECOMP_FUNC void func_80094F14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094F14: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80094F18: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x80094F1C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80094F20: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x80094F24: sb          $a2, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r6;
    // 0x80094F28: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x80094F2C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80094F30: jr          $ra
    // 0x80094F34: swc1        $f12, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f12.u32l;
    return;
    // 0x80094F34: swc1        $f12, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_8080093C_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080093C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800940: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800944: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800948: jal         0x8010DD20
    // 0x8080094C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010DD20(rdram, ctx);
        goto after_0;
    // 0x8080094C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800954: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800958: jr          $ra
    // 0x8080095C: nop

    return;
    // 0x8080095C: nop

;}
RECOMP_FUNC void chpotogoldbits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800070: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2344, 0X920) << 16);
    // 0x80800074: jr          $ra
    // 0x80800078: addiu       $v0, $v0, 0x920
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2344, 0X920));
    return;
    // 0x80800078: addiu       $v0, $v0, 0x920
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2344, 0X920));
;}
RECOMP_FUNC void func_8080008C_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080008C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800090: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80800094: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80800098: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2484, 0X7008) << 16);
    // 0x8080009C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808000A0: jr          $ra
    // 0x808000A4: lw          $v0, 0x7008($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(2484, 0X7008));
    return;
    // 0x808000A4: lw          $v0, 0x7008($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(2484, 0X7008));
;}
RECOMP_FUNC void glzone_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808000C0: beq         $a2, $zero, L_808000E4
    if (ctx->r6 == 0) {
        // 0x808000C4: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_808000E4;
    }
    // 0x808000C4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x808000C8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x808000CC: jal         0x80087940
    // 0x808000D0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    _dbzone_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808000D0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x808000D4: beq         $v0, $zero, L_808000E4
    if (ctx->r2 == 0) {
        // 0x808000D8: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_808000E4;
    }
    // 0x808000D8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x808000DC: b           L_808000F4
    // 0x808000E0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
        goto L_808000F4;
    // 0x808000E0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_808000E4:
    // 0x808000E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000E8: jal         0x80087948
    // 0x808000EC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _dbzone_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808000EC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x808000F0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_808000F4:
    // 0x808000F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000FC: jr          $ra
    // 0x80800100: nop

    return;
    // 0x80800100: nop

;}
RECOMP_FUNC void bsdie_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800900: jal         0x80085230
    // 0x80800904: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _basudie_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800904: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800908: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080090C: jal         0x8009BF5C
    // 0x80800910: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_1;
    // 0x80800910: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x80800914: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800918: jal         0x8009C4CC
    // 0x8080091C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_2;
    // 0x8080091C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800928: jr          $ra
    // 0x8080092C: nop

    return;
    // 0x8080092C: nop

;}
RECOMP_FUNC void func_8080000C_chtnthut(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: jr          $ra
    // 0x80800010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800E42C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E42C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E42C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E42C8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E42CC: jal         0x800CA6E8
    // 0x800E42D0: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA6E8(rdram, ctx);
        goto after_0;
    // 0x800E42D0: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E42D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E42D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E42DC: jr          $ra
    // 0x800E42E0: nop

    return;
    // 0x800E42E0: nop

;}
RECOMP_FUNC void bakey_pressed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091A58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091A5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091A60: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80091A64: addu        $t6, $v0, $a1
    ctx->r14 = ADD32(ctx->r2, ctx->r5);
    // 0x80091A68: lbu         $t7, 0x18($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X18);
    // 0x80091A6C: beq         $t7, $zero, L_80091A7C
    if (ctx->r15 == 0) {
        // 0x80091A70: nop
    
            goto L_80091A7C;
    }
    // 0x80091A70: nop

    // 0x80091A74: b           L_80091A84
    // 0x80091A78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80091A84;
    // 0x80091A78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80091A7C:
    // 0x80091A7C: jal         0x800BD030
    // 0x80091A80: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    func_800BD030(rdram, ctx);
        goto after_0;
    // 0x80091A80: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_0:
L_80091A84:
    // 0x80091A84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80091A88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091A8C: jr          $ra
    // 0x80091A90: nop

    return;
    // 0x80091A90: nop

;}
RECOMP_FUNC void ncbaspline_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808007C8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808007CC: jal         0x800D5424
    // 0x808007D0: lhu         $a0, 0x8($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X8);
    func_800D5424(rdram, ctx);
        goto after_0;
    // 0x808007D0: lhu         $a0, 0x8($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X8);
    after_0:
    // 0x808007D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808007D8: jal         0x808007F0
    // 0x808007DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    ncbaspline_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x808007DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x808007E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007E8: jr          $ra
    // 0x808007EC: nop

    return;
    // 0x808007EC: nop

;}
RECOMP_FUNC void chfactorycrusher_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1136, 0XA50) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xA50
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1136, 0XA50));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xA50
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1136, 0XA50));
;}
RECOMP_FUNC void bsledge_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801278: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080127C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801280: jal         0x80800238
    // 0x80801284: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800238_bsledge(rdram, ctx);
        goto after_0;
    // 0x80801284: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801288: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080128C: jal         0x80800488
    // 0x80801290: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800488_bsledge(rdram, ctx);
        goto after_1;
    // 0x80801290: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801294: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801298: jal         0x800839C0
    // 0x8080129C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bsrest_entrypoint_15(rdram, ctx);
        goto after_2;
    // 0x8080129C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808012A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808012A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808012A8: jr          $ra
    // 0x808012AC: nop

    return;
    // 0x808012AC: nop

;}
RECOMP_FUNC void func_808058F0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808058F0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808058F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808058F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808058FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80805900: jal         0x8009E6EC
    // 0x80805904: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80805904: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // 0x80805908: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080590C: addiu       $at, $zero, 0x83
    ctx->r1 = ADD32(0, 0X83);
    // 0x80805910: bne         $v0, $at, L_80805968
    if (ctx->r2 != ctx->r1) {
        // 0x80805914: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_80805968;
    }
    // 0x80805914: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80805918: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8080591C: addiu       $t8, $zero, 0xCA
    ctx->r24 = ADD32(0, 0XCA);
    // 0x80805920: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80805924: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80805928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080592C: jal         0x8009BDAC
    // 0x80805930: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    func_8009BDAC(rdram, ctx);
        goto after_1;
    // 0x80805930: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    after_1:
    // 0x80805934: jal         0x80807D70
    // 0x80805938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807D70_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80805938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080593C: jal         0x80801A5C
    // 0x80805940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801A5C_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80805940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80805944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805948: jal         0x8009337C
    // 0x8080594C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009337C(rdram, ctx);
        goto after_4;
    // 0x8080594C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80805950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805954: jal         0x800936E8
    // 0x80805958: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800936E8(rdram, ctx);
        goto after_5;
    // 0x80805958: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8080595C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805960: jal         0x80093370
    // 0x80805964: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80093370(rdram, ctx);
        goto after_6;
    // 0x80805964: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
L_80805968:
    // 0x80805968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080596C: jal         0x8009E830
    // 0x80805970: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8009E830(rdram, ctx);
        goto after_7;
    // 0x80805970: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x80805974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805978: jal         0x8009E5C8
    // 0x8080597C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_8;
    // 0x8080597C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_8:
    // 0x80805980: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80805984: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80805988: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080598C: jr          $ra
    // 0x80805990: nop

    return;
    // 0x80805990: nop

;}
RECOMP_FUNC void _bsbwhirl_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082DA8: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082DA8);
    return;
    // 0x80082DAC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _bskazjump_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083460: syscall     62
    recomp_syscall_handler(rdram, ctx, 0x80083460);
    return;
    // 0x80083464: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void cothemedll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800114: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080011C: jal         0x80800000
    // 0x80800120: nop

    func_80800000_cothemedll(rdram, ctx);
        goto after_0;
    // 0x80800120: nop

    after_0:
    // 0x80800124: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80800128: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8080012C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800130: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80800134: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2508, 0X734) << 16);
    // 0x80800138: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080013C: lh          $v0, 0x734($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(2508, 0X734));
    // 0x80800140: jr          $ra
    // 0x80800144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void sumissilehome_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800084: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800088: jr          $ra
    // 0x8080008C: sb          $a2, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r6;
    return;
    // 0x8080008C: sb          $a2, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r6;
;}
RECOMP_FUNC void _gctransitionDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800881B8: syscall     674
    recomp_syscall_handler(rdram, ctx, 0x800881B8);
    return;
    // 0x800881BC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _glsplineDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800884E0: syscall     689
    recomp_syscall_handler(rdram, ctx, 0x800884E0);
    return;
    // 0x800884E4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800CB610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB610: jr          $ra
    // 0x800CB614: nop

    return;
    // 0x800CB614: nop

;}
RECOMP_FUNC void func_80800000_chfactorytrashbelt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: jal         0x800F54E4
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800014: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800018: jal         0x800F5A00
    // 0x8080001C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x8080001C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x80800020: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80800024: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800028: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080002C: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x80800030: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80800034: nop

    // 0x80800038: bc1f        L_80800168
    if (!c1cs) {
        // 0x8080003C: nop
    
            goto L_80800168;
    }
    // 0x8080003C: nop

    // 0x80800040: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800044: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800048: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8080004C: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x80800050: nop

    // 0x80800054: bc1f        L_80800168
    if (!c1cs) {
        // 0x80800058: nop
    
            goto L_80800168;
    }
    // 0x80800058: nop

    // 0x8080005C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800060: lui         $at, 0xC416
    ctx->r1 = S32(0XC416 << 16);
    // 0x80800064: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800068: nop

    // 0x8080006C: bc1f        L_80800168
    if (!c1cs) {
        // 0x80800070: nop
    
            goto L_80800168;
    }
    // 0x80800070: nop

    // 0x80800074: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800078: nop

    // 0x8080007C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80800080: nop

    // 0x80800084: bc1f        L_80800168
    if (!c1cs) {
        // 0x80800088: nop
    
            goto L_80800168;
    }
    // 0x80800088: nop

    // 0x8080008C: jal         0x800F54E4
    // 0x80800090: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80800090: nop

    after_2:
    // 0x80800094: jal         0x800F6C5C
    // 0x80800098: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6C5C(rdram, ctx);
        goto after_3;
    // 0x80800098: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x8080009C: beq         $v0, $zero, L_80800168
    if (ctx->r2 == 0) {
        // 0x808000A0: lwc1        $f12, 0x3C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_80800168;
    }
    // 0x808000A0: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808000A4: lui         $at, 0xC42F
    ctx->r1 = S32(0XC42F << 16);
    // 0x808000A8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000AC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808000B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808000B4: lui         $a2, 0x442F
    ctx->r6 = S32(0X442F << 16);
    // 0x808000B8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808000BC: jal         0x800F10B4
    // 0x808000C0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x808000C0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x808000C4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808000C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808000CC: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x808000D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000D4: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808000D8: nop

    // 0x808000DC: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808000E0: jal         0x800138D0
    // 0x808000E4: nop

    func_800138D0(rdram, ctx);
        goto after_5;
    // 0x808000E4: nop

    after_5:
    // 0x808000E8: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x808000EC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808000F0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808000F4: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808000F8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x808000FC: bgez        $t7, L_80800110
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800100: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80800110;
    }
    // 0x80800100: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800104: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800108: nop

    // 0x8080010C: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80800110:
    // 0x80800110: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80800114: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800118: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8080011C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800120: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80800124: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800128: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080012C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800130: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800134: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800138: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8080013C: div.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80800140: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80800144: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800148: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080014C: jal         0x800EFA4C
    // 0x80800150: nop

    func_800EFA4C(rdram, ctx);
        goto after_6;
    // 0x80800150: nop

    after_6:
    // 0x80800154: jal         0x800F54E4
    // 0x80800158: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x80800158: nop

    after_7:
    // 0x8080015C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800160: jal         0x800F48BC
    // 0x80800164: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800F48BC(rdram, ctx);
        goto after_8;
    // 0x80800164: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_8:
L_80800168:
    // 0x80800168: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2328, 0X5C0) << 16);
    // 0x8080016C: addiu       $a3, $a3, 0x5C0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2328, 0X5C0));
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800174: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800178: jal         0x80089D50
    // 0x8080017C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x8080017C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x80800180: jal         0x800D91B8
    // 0x80800184: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D91B8(rdram, ctx);
        goto after_10;
    // 0x80800184: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_10:
    // 0x80800188: lhu         $t8, 0x76($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X76);
    // 0x8080018C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800190: srl         $t9, $t8, 7
    ctx->r25 = S32(U32(ctx->r24) >> 7);
    // 0x80800194: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80800198: bgez        $t9, L_808001AC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8080019C: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808001AC;
    }
    // 0x8080019C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808001A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808001A4: nop

    // 0x808001A8: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
L_808001AC:
    // 0x808001AC: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x808001B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808001B4: nop

    // 0x808001B8: div.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808001BC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x808001C0: nop

    // 0x808001C4: bc1fl       L_808001DC
    if (!c1cs) {
        // 0x808001C8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808001DC;
    }
    goto skip_0;
    // 0x808001C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808001CC: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808001D0: sub.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x808001D4: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x808001D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001DC:
    // 0x808001DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001E0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808001E4: jr          $ra
    // 0x808001E8: nop

    return;
    // 0x808001E8: nop

;}
RECOMP_FUNC void func_80800F80_chonearmbandit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800F84: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800F88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F8C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800F90: jal         0x800DC298
    // 0x80800F94: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800DC298(rdram, ctx);
        goto after_0;
    // 0x80800F94: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800F98: beq         $v0, $zero, L_80800FB0
    if (ctx->r2 == 0) {
        // 0x80800F9C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800FB0;
    }
    // 0x80800F9C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800FA0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800FA4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800FA8: b           L_80800FBC
    // 0x80800FAC: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
        goto L_80800FBC;
    // 0x80800FAC: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
L_80800FB0:
    // 0x80800FB0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800FB4: nop

    // 0x80800FB8: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
L_80800FBC:
    // 0x80800FBC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800FC0: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80800FC4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800FC8: jal         0x800DC178
    // 0x80800FCC: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800FCC: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80800FD0: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800FD4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800FD8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80800FDC: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80800FE0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800FE4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800FE8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800FEC: swc1        $f6, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f6.u32l;
    // 0x80800FF0: swc1        $f8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f8.u32l;
    // 0x80800FF4: swc1        $f4, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f4.u32l;
    // 0x80800FF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801000: jr          $ra
    // 0x80801004: nop

    return;
    // 0x80801004: nop

;}
RECOMP_FUNC void func_800EA34C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA34C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EA350: jr          $ra
    // 0x800EA354: sh          $a0, 0x2DCC($at)
    MEM_H(0X2DCC, ctx->r1) = ctx->r4;
    return;
    // 0x800EA354: sh          $a0, 0x2DCC($at)
    MEM_H(0X2DCC, ctx->r1) = ctx->r4;
;}
