#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chbadjinjo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086968: syscall     401
    recomp_syscall_handler(rdram, ctx, 0x80086968);
    return;
    // 0x8008696C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_801155E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801155E8: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x801155EC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801155F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801155F4: lwc1        $f4, 0x10($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X10);
    // 0x801155F8: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801155FC: jr          $ra
    // 0x80115600: nop

    return;
    // 0x80115600: nop

    // 0x80115604: nop

    // 0x80115608: nop

    // 0x8011560C: nop

;}
RECOMP_FUNC void _gcnewoption_entrypoint_40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087DD8: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087DD8);
    return;
    // 0x80087DDC: addi        $t0, $zero, 0xA0
    ctx->r8 = ADD32(0, 0XA0);
;}
RECOMP_FUNC void func_80800240_chbilldrillplate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800240: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800244: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x80800248: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080024C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800250: bne         $a1, $at, L_80800284
    if (ctx->r5 != ctx->r1) {
        // 0x80800254: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800284;
    }
    // 0x80800254: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800258: jal         0x8008A4B8
    // 0x8080025C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    _subaddieDll_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x8080025C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80800260: beq         $v0, $zero, L_8080028C
    if (ctx->r2 == 0) {
        // 0x80800264: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080028C;
    }
    // 0x80800264: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800268: jal         0x80103110
    // 0x8080026C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x8080026C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800270: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800274: jal         0x80101FDC
    // 0x80800278: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800278: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8080027C: b           L_80800290
    // 0x80800280: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800290;
    // 0x80800280: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800284:
    // 0x80800284: b           L_80800290
    // 0x80800288: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800290;
    // 0x80800288: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080028C:
    // 0x8080028C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800290:
    // 0x80800290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800294: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800298: jr          $ra
    // 0x8080029C: nop

    return;
    // 0x8080029C: nop

;}
RECOMP_FUNC void func_800A7840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7840: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A7844: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A7848: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A784C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A7850: jal         0x8001A4B8
    // 0x800A7854: addiu       $a0, $a0, 0x7658
    ctx->r4 = ADD32(ctx->r4, 0X7658);
    func_8001A4B8(rdram, ctx);
        goto after_0;
    // 0x800A7854: addiu       $a0, $a0, 0x7658
    ctx->r4 = ADD32(ctx->r4, 0X7658);
    after_0:
    // 0x800A7858: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A785C: lh          $t6, 0x7634($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7634);
    // 0x800A7860: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A7864: beq         $t6, $zero, L_800A7874
    if (ctx->r14 == 0) {
        // 0x800A7868: nop
    
            goto L_800A7874;
    }
    // 0x800A7868: nop

    // 0x800A786C: jal         0x8001A4B8
    // 0x800A7870: addiu       $a0, $a0, 0x7658
    ctx->r4 = ADD32(ctx->r4, 0X7658);
    func_8001A4B8(rdram, ctx);
        goto after_1;
    // 0x800A7870: addiu       $a0, $a0, 0x7658
    ctx->r4 = ADD32(ctx->r4, 0X7658);
    after_1:
L_800A7874:
    // 0x800A7874: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A7878: lw          $t7, 0x7658($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7658);
    // 0x800A787C: jal         0x80014F58
    // 0x800A7880: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_80014F58(rdram, ctx);
        goto after_2;
    // 0x800A7880: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_2:
    // 0x800A7884: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A7888: jal         0x800A73F4
    // 0x800A788C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800A73F4(rdram, ctx);
        goto after_3;
    // 0x800A788C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x800A7890: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A7894: lh          $t8, 0x7634($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7634);
    // 0x800A7898: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A789C: bne         $t8, $zero, L_800A78F0
    if (ctx->r24 != 0) {
        // 0x800A78A0: nop
    
            goto L_800A78F0;
    }
    // 0x800A78A0: nop

    // 0x800A78A4: lw          $t9, 0x7658($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7658);
    // 0x800A78A8: jal         0x80015410
    // 0x800A78AC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    func_80015410(rdram, ctx);
        goto after_4;
    // 0x800A78AC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_4:
    // 0x800A78B0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A78B4: lw          $t0, 0x7650($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7650);
    // 0x800A78B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A78BC: bne         $t0, $zero, L_800A78DC
    if (ctx->r8 != 0) {
        // 0x800A78C0: nop
    
            goto L_800A78DC;
    }
    // 0x800A78C0: nop

    // 0x800A78C4: jal         0x8001BD50
    // 0x800A78C8: lwc1        $f12, 0x55F4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X55F4);
    func_8001BD50(rdram, ctx);
        goto after_5;
    // 0x800A78C8: lwc1        $f12, 0x55F4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X55F4);
    after_5:
    // 0x800A78CC: beq         $v0, $zero, L_800A78DC
    if (ctx->r2 == 0) {
        // 0x800A78D0: nop
    
            goto L_800A78DC;
    }
    // 0x800A78D0: nop

    // 0x800A78D4: jal         0x800A7FD4
    // 0x800A78D8: nop

    func_800A7FD4(rdram, ctx);
        goto after_6;
    // 0x800A78D8: nop

    after_6:
L_800A78DC:
    // 0x800A78DC: jal         0x800E82EC
    // 0x800A78E0: nop

    func_800E82EC(rdram, ctx);
        goto after_7;
    // 0x800A78E0: nop

    after_7:
    // 0x800A78E4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A78E8: jal         0x8001A270
    // 0x800A78EC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_8001A270(rdram, ctx);
        goto after_8;
    // 0x800A78EC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_8:
L_800A78F0:
    // 0x800A78F0: jal         0x80015878
    // 0x800A78F4: nop

    func_80015878(rdram, ctx);
        goto after_9;
    // 0x800A78F4: nop

    after_9:
    // 0x800A78F8: jal         0x800E4628
    // 0x800A78FC: nop

    func_800E4628(rdram, ctx);
        goto after_10;
    // 0x800A78FC: nop

    after_10:
    // 0x800A7900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A7904: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A7908: sh          $zero, 0x7634($at)
    MEM_H(0X7634, ctx->r1) = 0;
    // 0x800A790C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A7910: sw          $zero, 0x7650($at)
    MEM_W(0X7650, ctx->r1) = 0;
    // 0x800A7914: jr          $ra
    // 0x800A7918: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A7918: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8002CE70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CE70: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002CE74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002CE78: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8002CE7C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8002CE80: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8002CE84: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8002CE88: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8002CE8C: blez        $t6, L_8002CF30
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8002CE90: nop
    
            goto L_8002CF30;
    }
    // 0x8002CE90: nop

    // 0x8002CE94: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8002CE98: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8002CE9C: lw          $t9, 0x28($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X28);
    // 0x8002CEA0: lw          $a0, 0x3C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X3C);
    // 0x8002CEA4: lw          $a2, 0x2C($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X2C);
    // 0x8002CEA8: jalr        $t9
    // 0x8002CEAC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8002CEAC: nop

    after_0:
    // 0x8002CEB0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8002CEB4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8002CEB8: andi        $t0, $t8, 0x7
    ctx->r8 = ctx->r24 & 0X7;
    // 0x8002CEBC: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8002CEC0: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8002CEC4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8002CEC8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8002CECC: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x8002CED0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8002CED4: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8002CED8: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x8002CEDC: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8002CEE0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8002CEE4: lh          $t3, 0x46($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X46);
    // 0x8002CEE8: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8002CEEC: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x8002CEF0: subu        $t9, $t6, $t7
    ctx->r25 = SUB32(ctx->r14, ctx->r15);
    // 0x8002CEF4: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x8002CEF8: andi        $t0, $t8, 0xFFF
    ctx->r8 = ctx->r24 & 0XFFF;
    // 0x8002CEFC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8002CF00: sll         $t1, $t0, 12
    ctx->r9 = S32(ctx->r8 << 12);
    // 0x8002CF04: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x8002CF08: andi        $t4, $t3, 0xFFF
    ctx->r12 = ctx->r11 & 0XFFF;
    // 0x8002CF0C: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x8002CF10: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8002CF14: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8002CF18: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8002CF1C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8002CF20: subu        $t8, $t7, $t9
    ctx->r24 = SUB32(ctx->r15, ctx->r25);
    // 0x8002CF24: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x8002CF28: b           L_8002CF34
    // 0x8002CF2C: nop

        goto L_8002CF34;
    // 0x8002CF2C: nop

L_8002CF30:
    // 0x8002CF30: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8002CF34:
    // 0x8002CF34: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8002CF38: andi        $t3, $t1, 0x2
    ctx->r11 = ctx->r9 & 0X2;
    // 0x8002CF3C: beq         $t3, $zero, L_8002CF7C
    if (ctx->r11 == 0) {
        // 0x8002CF40: nop
    
            goto L_8002CF7C;
    }
    // 0x8002CF40: nop

    // 0x8002CF44: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8002CF48: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x8002CF4C: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x8002CF50: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8002CF54: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8002CF58: lui         $t5, 0xF00
    ctx->r13 = S32(0XF00 << 16);
    // 0x8002CF5C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8002CF60: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8002CF64: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8002CF68: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x8002CF6C: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x8002CF70: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002CF74: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x8002CF78: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
L_8002CF7C:
    // 0x8002CF7C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8002CF80: addiu       $t3, $t1, 0x8
    ctx->r11 = ADD32(ctx->r9, 0X8);
    // 0x8002CF84: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8002CF88: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8002CF8C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8002CF90: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x8002CF94: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002CF98: lw          $t4, 0xC($t2)
    ctx->r12 = MEM_W(ctx->r10, 0XC);
    // 0x8002CF9C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8002CFA0: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8002CFA4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8002CFA8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002CFAC: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x8002CFB0: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8002CFB4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8002CFB8: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x8002CFBC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8002CFC0: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8002CFC4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8002CFC8: sll         $t2, $t3, 1
    ctx->r10 = S32(ctx->r11 << 1);
    // 0x8002CFCC: andi        $t4, $t2, 0xFFF
    ctx->r12 = ctx->r10 & 0XFFF;
    // 0x8002CFD0: andi        $t0, $t8, 0xF
    ctx->r8 = ctx->r24 & 0XF;
    // 0x8002CFD4: lh          $t3, 0x42($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X42);
    // 0x8002CFD8: sll         $t1, $t0, 28
    ctx->r9 = S32(ctx->r8 << 28);
    // 0x8002CFDC: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x8002CFE0: or          $t6, $t1, $t5
    ctx->r14 = ctx->r9 | ctx->r13;
    // 0x8002CFE4: andi        $t9, $t7, 0xF
    ctx->r25 = ctx->r15 & 0XF;
    // 0x8002CFE8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8002CFEC: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x8002CFF0: or          $t0, $t6, $t8
    ctx->r8 = ctx->r14 | ctx->r24;
    // 0x8002CFF4: andi        $t2, $t3, 0xFFF
    ctx->r10 = ctx->r11 & 0XFFF;
    // 0x8002CFF8: or          $t4, $t0, $t2
    ctx->r12 = ctx->r8 | ctx->r10;
    // 0x8002CFFC: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x8002D000: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8002D004: sw          $zero, 0x38($t5)
    MEM_W(0X38, ctx->r13) = 0;
    // 0x8002D008: b           L_8002D018
    // 0x8002D00C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
        goto L_8002D018;
    // 0x8002D00C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8002D010: b           L_8002D018
    // 0x8002D014: nop

        goto L_8002D018;
    // 0x8002D014: nop

L_8002D018:
    // 0x8002D018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002D01C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8002D020: jr          $ra
    // 0x8002D024: nop

    return;
    // 0x8002D024: nop

    // 0x8002D028: nop

    // 0x8002D02C: nop

;}
RECOMP_FUNC void _glpackvtx_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800887A0: syscall     704
    recomp_syscall_handler(rdram, ctx, 0x800887A0);
    return;
    // 0x800887A4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800C9F94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9F94: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C9F98: lw          $a0, -0x54A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X54A0);
    // 0x800C9F9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9FA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9FA4: sltiu       $v0, $a0, 0x1
    ctx->r2 = ctx->r4 < 0X1 ? 1 : 0;
    // 0x800C9FA8: bnel        $v0, $zero, L_800C9FC4
    if (ctx->r2 != 0) {
        // 0x800C9FAC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C9FC4;
    }
    goto skip_0;
    // 0x800C9FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C9FB0: jal         0x800B2928
    // 0x800C9FB4: nop

    vector_size(rdram, ctx);
        goto after_0;
    // 0x800C9FB4: nop

    after_0:
    // 0x800C9FB8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800C9FBC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800C9FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9FC4:
    // 0x800C9FC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9FC8: jr          $ra
    // 0x800C9FCC: nop

    return;
    // 0x800C9FCC: nop

;}
RECOMP_FUNC void func_80801578_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801578: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080157C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801580: jal         0x80090A2C
    // 0x80801584: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80090A2C(rdram, ctx);
        goto after_0;
    // 0x80801584: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801588: jal         0x808008D8
    // 0x8080158C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808008D8_bssub(rdram, ctx);
        goto after_1;
    // 0x8080158C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801594: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801598: jr          $ra
    // 0x8080159C: nop

    return;
    // 0x8080159C: nop

;}
RECOMP_FUNC void func_80800C70_chmole_training(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C78: lwc1        $f4, 0x48($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80800C7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800C80: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800C84: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80800C88: nop

    // 0x80800C8C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80800C90: nop

    // 0x80800C94: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800C98: jal         0x800899D0
    // 0x80800C9C: swc1        $f10, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f10.u32l;
    _sumole_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800C9C: swc1        $f10, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f10.u32l;
    after_0:
    // 0x80800CA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800CA8: jr          $ra
    // 0x80800CAC: nop

    return;
    // 0x80800CAC: nop

;}
RECOMP_FUNC void _chfootwear_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087770: syscall     620
    recomp_syscall_handler(rdram, ctx, 0x80087770);
    return;
    // 0x80087774: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800E4C_chcredits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E4C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800E50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E54: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800E58: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800E5C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800E60: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800E64: jal         0x800886D8
    // 0x80800E68: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    _glglobalsettings_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800E68: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800E6C: beq         $v0, $zero, L_80800E7C
    if (ctx->r2 == 0) {
        // 0x80800E70: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1636, 0X11FC) << 16);
            goto L_80800E7C;
    }
    // 0x80800E70: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1636, 0X11FC) << 16);
    // 0x80800E74: b           L_80800E88
    // 0x80800E78: lwc1        $f20, 0x11FC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1636, 0X11FC));
        goto L_80800E88;
    // 0x80800E78: lwc1        $f20, 0x11FC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1636, 0X11FC));
L_80800E7C:
    // 0x80800E7C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800E80: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800E84: nop

L_80800E88:
    // 0x80800E88: jal         0x800B8CFC
    // 0x80800E8C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800B8CFC(rdram, ctx);
        goto after_1;
    // 0x80800E8C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80800E90: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80800E94: lui         $at, 0x4398
    ctx->r1 = S32(0X4398 << 16);
    // 0x80800E98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800E9C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800EA0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800EA4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800EA8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800EAC: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80800EB0: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80800EB4: div.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800EB8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800EBC: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80800EC0: jal         0x800B8C8C
    // 0x80800EC4: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    func_800B8C8C(rdram, ctx);
        goto after_2;
    // 0x80800EC4: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    after_2:
    // 0x80800EC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800ECC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800ED0: jal         0x800B8CBC
    // 0x80800ED4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B8CBC(rdram, ctx);
        goto after_3;
    // 0x80800ED4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80800ED8: jal         0x800B8CF0
    // 0x80800EDC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800B8CF0(rdram, ctx);
        goto after_4;
    // 0x80800EDC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_4:
    // 0x80800EE0: jal         0x800B80D0
    // 0x80800EE4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800B80D0(rdram, ctx);
        goto after_5;
    // 0x80800EE4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_5:
    // 0x80800EE8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80800EEC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800EF0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800EF4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80800EF8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80800EFC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80800F00: jal         0x800B8E28
    // 0x80800F04: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    func_800B8E28(rdram, ctx);
        goto after_6;
    // 0x80800F04: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_6:
    // 0x80800F08: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80800F0C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80800F10: jal         0x800B8CBC
    // 0x80800F14: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800B8CBC(rdram, ctx);
        goto after_7;
    // 0x80800F14: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_7:
    // 0x80800F18: jal         0x800B8CF0
    // 0x80800F1C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800B8CF0(rdram, ctx);
        goto after_8;
    // 0x80800F1C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_8:
    // 0x80800F20: jal         0x800B80D0
    // 0x80800F24: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800B80D0(rdram, ctx);
        goto after_9;
    // 0x80800F24: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_9:
    // 0x80800F28: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800F2C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800F30: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800F34: jal         0x800B8E28
    // 0x80800F38: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    func_800B8E28(rdram, ctx);
        goto after_10;
    // 0x80800F38: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    after_10:
    // 0x80800F3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F40: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800F44: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800F48: jr          $ra
    // 0x80800F4C: nop

    return;
    // 0x80800F4C: nop

;}
RECOMP_FUNC void func_8008FF94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FF94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FF98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FF9C: jal         0x800F54E4
    // 0x8008FFA0: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FFA0: nop

    after_0:
    // 0x8008FFA4: jal         0x800F5D18
    // 0x8008FFA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5D18(rdram, ctx);
        goto after_1;
    // 0x8008FFA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8008FFAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FFB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FFB4: jr          $ra
    // 0x8008FFB8: nop

    return;
    // 0x8008FFB8: nop

;}
RECOMP_FUNC void func_8080367C_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080367C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803680: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803684: jal         0x80801944
    // 0x80803688: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801944_chstoneballcontrol(rdram, ctx);
        goto after_0;
    // 0x80803688: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080368C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803690: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803694: jr          $ra
    // 0x80803698: nop

    return;
    // 0x80803698: nop

;}
RECOMP_FUNC void _chcauldronentrydoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800870A8: syscall     509
    recomp_syscall_handler(rdram, ctx, 0x800870A8);
    return;
    // 0x800870AC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800B90_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B90: slti        $at, $a0, 0x1910
    ctx->r1 = SIGNED(ctx->r4) < 0X1910 ? 1 : 0;
    // 0x80800B94: bne         $at, $zero, L_80800BAC
    if (ctx->r1 != 0) {
        // 0x80800B98: slti        $at, $a0, 0x1A00
        ctx->r1 = SIGNED(ctx->r4) < 0X1A00 ? 1 : 0;
            goto L_80800BAC;
    }
    // 0x80800B98: slti        $at, $a0, 0x1A00
    ctx->r1 = SIGNED(ctx->r4) < 0X1A00 ? 1 : 0;
    // 0x80800B9C: beql        $at, $zero, L_80800BB0
    if (ctx->r1 == 0) {
        // 0x80800BA0: slti        $at, $a0, 0x1A00
        ctx->r1 = SIGNED(ctx->r4) < 0X1A00 ? 1 : 0;
            goto L_80800BB0;
    }
    goto skip_0;
    // 0x80800BA0: slti        $at, $a0, 0x1A00
    ctx->r1 = SIGNED(ctx->r4) < 0X1A00 ? 1 : 0;
    skip_0:
    // 0x80800BA4: jr          $ra
    // 0x80800BA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800BA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800BAC:
    // 0x80800BAC: slti        $at, $a0, 0x1A00
    ctx->r1 = SIGNED(ctx->r4) < 0X1A00 ? 1 : 0;
L_80800BB0:
    // 0x80800BB0: bne         $at, $zero, L_80800BCC
    if (ctx->r1 != 0) {
        // 0x80800BB4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80800BCC;
    }
    // 0x80800BB4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80800BB8: slti        $at, $a0, 0x1A89
    ctx->r1 = SIGNED(ctx->r4) < 0X1A89 ? 1 : 0;
    // 0x80800BBC: beq         $at, $zero, L_80800BCC
    if (ctx->r1 == 0) {
        // 0x80800BC0: nop
    
            goto L_80800BCC;
    }
    // 0x80800BC0: nop

    // 0x80800BC4: jr          $ra
    // 0x80800BC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800BC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800BCC:
    // 0x80800BCC: jr          $ra
    // 0x80800BD0: nop

    return;
    // 0x80800BD0: nop

;}
RECOMP_FUNC void func_8080014C_chlavacolumns(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080014C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800150: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800154: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800158: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x8080015C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800160: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800164: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800168: bne         $t7, $at, L_808001EC
    if (ctx->r15 != ctx->r1) {
        // 0x8080016C: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_808001EC;
    }
    // 0x8080016C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800170: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1944, 0X250) << 16);
    // 0x80800174: addiu       $a3, $a3, 0x250
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1944, 0X250));
    // 0x80800178: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080017C: jal         0x80089D50
    // 0x80800180: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800180: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800184: jal         0x800D8FF8
    // 0x80800188: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800188: nop

    after_1:
    // 0x8080018C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800190: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800194: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800198: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8080019C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808001A8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x808001AC: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x808001B0: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808001B4: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x808001B8: nop

    // 0x808001BC: bc1fl       L_808001F0
    if (!c1cs) {
        // 0x808001C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808001F0;
    }
    goto skip_0;
    // 0x808001C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808001C4: jal         0x80101FDC
    // 0x808001C8: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x808001C8: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    after_2:
    // 0x808001CC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1944, 0X258) << 16);
    // 0x808001D0: addiu       $a2, $a2, 0x258
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1944, 0X258));
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D8: jal         0x80089D18
    // 0x808001DC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808001DC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E4: jal         0x80103110
    // 0x808001E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_4;
    // 0x808001E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_808001EC:
    // 0x808001EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001F0:
    // 0x808001F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001F8: jr          $ra
    // 0x808001FC: nop

    return;
    // 0x808001FC: nop

;}
RECOMP_FUNC void func_80800704_chsunlightspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800704: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800708: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080070C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800710: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800714: jal         0x80100094
    // 0x80800718: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800718: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080071C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800720: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800724: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800728: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x8080072C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800730: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800734: addiu       $a3, $zero, 0x2E
    ctx->r7 = ADD32(0, 0X2E);
    // 0x80800738: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8080073C: jal         0x80089878
    // 0x80800740: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    _sumumbofx_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800740: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_1:
    // 0x80800744: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800748: jal         0x80100094
    // 0x8080074C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x8080074C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800750: jal         0x800898B0
    // 0x80800754: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_3;
    // 0x80800754: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800758: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080075C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800760: jr          $ra
    // 0x80800764: nop

    return;
    // 0x80800764: nop

;}
RECOMP_FUNC void func_800D71F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D71F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D71F8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800D71FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D7200: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800D7204: jal         0x800D7184
    // 0x800D7208: lh          $a0, -0x46F0($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X46F0);
    func_800D7184(rdram, ctx);
        goto after_0;
    // 0x800D7208: lh          $a0, -0x46F0($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X46F0);
    after_0:
    // 0x800D720C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D7210: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D7214: jr          $ra
    // 0x800D7218: nop

    return;
    // 0x800D7218: nop

;}
RECOMP_FUNC void func_80800024_chjiggybeam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080002C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800030: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800034: jal         0x800E3A58
    // 0x80800038: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800E3A58(rdram, ctx);
        goto after_0;
    // 0x80800038: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8080003C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800040: jal         0x80101870
    // 0x80800044: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80101870(rdram, ctx);
        goto after_1;
    // 0x80800044: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080004C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800050: jr          $ra
    // 0x80800054: nop

    return;
    // 0x80800054: nop

;}
RECOMP_FUNC void chfactorytwinklies_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1308, 0X2338) << 16);
    // 0x80800034: jr          $ra
    // 0x80800038: addiu       $v0, $v0, 0x2338
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1308, 0X2338));
    return;
    // 0x80800038: addiu       $v0, $v0, 0x2338
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1308, 0X2338));
;}
RECOMP_FUNC void _bsstonehead_entrypoint_32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083CE0: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083CE0);
    return;
    // 0x80083CE4: addi        $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
;}
RECOMP_FUNC void chgobiwitchy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(844, 0X410) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x410
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(844, 0X410));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x410
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(844, 0X410));
;}
RECOMP_FUNC void _subaddiedraw25d_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089C00: syscall     806
    recomp_syscall_handler(rdram, ctx, 0x80089C00);
    return;
    // 0x80089C04: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80092AA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092AA4: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80092AA8: jr          $ra
    // 0x80092AAC: sw          $zero, 0x84($t6)
    MEM_W(0X84, ctx->r14) = 0;
    return;
    // 0x80092AAC: sw          $zero, 0x84($t6)
    MEM_W(0X84, ctx->r14) = 0;
;}
RECOMP_FUNC void func_80800E90_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800E9C: jal         0x80801B88
    // 0x80800EA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80801B88_chboilerboss(rdram, ctx);
        goto after_0;
    // 0x80800EA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800EA4: jal         0x800CEAA8
    // 0x80800EA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAA8(rdram, ctx);
        goto after_1;
    // 0x80800EA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80800EAC: beq         $v0, $zero, L_80800EBC
    if (ctx->r2 == 0) {
        // 0x80800EB0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800EBC;
    }
    // 0x80800EB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800EB4: jal         0x800CE88C
    // 0x80800EB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CE88C(rdram, ctx);
        goto after_2;
    // 0x80800EB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_80800EBC:
    // 0x80800EBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EC0: jal         0x80100094
    // 0x80800EC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80800EC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800EC8: sb          $zero, 0x55($v0)
    MEM_B(0X55, ctx->r2) = 0;
    // 0x80800ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ED0: addiu       $a1, $zero, 0xF98
    ctx->r5 = ADD32(0, 0XF98);
    // 0x80800ED4: jal         0x8080238C
    // 0x80800ED8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8080238C_chboilerboss(rdram, ctx);
        goto after_4;
    // 0x80800ED8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x80800EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EE0: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x80800EE4: addiu       $a2, $zero, 0x430
    ctx->r6 = ADD32(0, 0X430);
    // 0x80800EE8: jal         0x808027E4
    // 0x80800EEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_808027E4_chboilerboss(rdram, ctx);
        goto after_5;
    // 0x80800EEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x80800EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EF4: jal         0x80800F34
    // 0x80800EF8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80800F34_chboilerboss(rdram, ctx);
        goto after_6;
    // 0x80800EF8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_6:
    // 0x80800EFC: jal         0x8010A570
    // 0x80800F00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_7;
    // 0x80800F00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800F04: sb          $zero, 0x5E($s0)
    MEM_B(0X5E, ctx->r16) = 0;
    // 0x80800F08: jal         0x80800E64
    // 0x80800F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800E64_chboilerboss(rdram, ctx);
        goto after_8;
    // 0x80800F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800F18: jal         0x8080221C
    // 0x80800F1C: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    func_8080221C_chboilerboss(rdram, ctx);
        goto after_9;
    // 0x80800F1C: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_9:
    // 0x80800F20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800F28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800F2C: jr          $ra
    // 0x80800F30: nop

    return;
    // 0x80800F30: nop

;}
RECOMP_FUNC void func_800C70B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C70B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C70B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C70B8: jal         0x800DA3B8
    // 0x800C70BC: addiu       $a0, $a0, 0xED
    ctx->r4 = ADD32(ctx->r4, 0XED);
    func_800DA3B8(rdram, ctx);
        goto after_0;
    // 0x800C70BC: addiu       $a0, $a0, 0xED
    ctx->r4 = ADD32(ctx->r4, 0XED);
    after_0:
    // 0x800C70C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C70C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C70C8: jr          $ra
    // 0x800C70CC: nop

    return;
    // 0x800C70CC: nop

;}
RECOMP_FUNC void func_800A9478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9478: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A947C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800A9480: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800A9484: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800A9488: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800A948C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A9490: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800A9494: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800A9498: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800A949C: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x800A94A0: addiu       $s3, $s3, 0x76D0
    ctx->r19 = ADD32(ctx->r19, 0X76D0);
    // 0x800A94A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A94A8: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
L_800A94AC:
    // 0x800A94AC: jal         0x800F6438
    // 0x800A94B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_0;
    // 0x800A94B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800A94B4: beq         $v0, $zero, L_800A94E4
    if (ctx->r2 == 0) {
        // 0x800A94B8: sll         $t6, $s0, 2
        ctx->r14 = S32(ctx->r16 << 2);
            goto L_800A94E4;
    }
    // 0x800A94B8: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x800A94BC: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x800A94C0: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x800A94C4: bnel        $s2, $t8, L_800A94E8
    if (ctx->r18 != ctx->r24) {
        // 0x800A94C8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800A94E8;
    }
    goto skip_0;
    // 0x800A94C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x800A94CC: jal         0x800A9420
    // 0x800A94D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A9420(rdram, ctx);
        goto after_1;
    // 0x800A94D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800A94D4: beq         $v0, $zero, L_800A94E4
    if (ctx->r2 == 0) {
        // 0x800A94D8: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_800A94E4;
    }
    // 0x800A94D8: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x800A94DC: b           L_800A94F4
    // 0x800A94E0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800A94F4;
    // 0x800A94E0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800A94E4:
    // 0x800A94E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800A94E8:
    // 0x800A94E8: bne         $s0, $s4, L_800A94AC
    if (ctx->r16 != ctx->r20) {
        // 0x800A94EC: nop
    
            goto L_800A94AC;
    }
    // 0x800A94EC: nop

    // 0x800A94F0: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_800A94F4:
    // 0x800A94F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A94F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A94FC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800A9500: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800A9504: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800A9508: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800A950C: jr          $ra
    // 0x800A9510: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800A9510: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80800F74_chsabreman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F74: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800F78: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800F7C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800F80: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800F84: jal         0x800EA05C
    // 0x80800F88: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800F88: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800F8C: addiu       $at, $zero, 0x127
    ctx->r1 = ADD32(0, 0X127);
    // 0x80800F90: bne         $v0, $at, L_80800FDC
    if (ctx->r2 != ctx->r1) {
        // 0x80800F94: addiu       $a0, $zero, 0x154
        ctx->r4 = ADD32(0, 0X154);
            goto L_80800FDC;
    }
    // 0x80800F94: addiu       $a0, $zero, 0x154
    ctx->r4 = ADD32(0, 0X154);
    // 0x80800F98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800F9C: jal         0x800882F0
    // 0x80800FA0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    _gccubesearch_entrypoint_15(rdram, ctx);
        goto after_1;
    // 0x80800FA0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x80800FA4: beq         $v0, $zero, L_80800FDC
    if (ctx->r2 == 0) {
        // 0x80800FA8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80800FDC;
    }
    // 0x80800FA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800FAC: jal         0x800EE88C
    // 0x80800FB0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x80800FB0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x80800FB4: jal         0x800CBC3C
    // 0x80800FB8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800CBC3C(rdram, ctx);
        goto after_3;
    // 0x80800FB8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x80800FBC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800FC0: jal         0x800CBC3C
    // 0x80800FC4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800CBC3C(rdram, ctx);
        goto after_4;
    // 0x80800FC4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x80800FC8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800FCC: bnel        $v0, $t6, L_80800FE0
    if (ctx->r2 != ctx->r14) {
        // 0x80800FD0: addiu       $a0, $zero, 0x1276
        ctx->r4 = ADD32(0, 0X1276);
            goto L_80800FE0;
    }
    goto skip_0;
    // 0x80800FD0: addiu       $a0, $zero, 0x1276
    ctx->r4 = ADD32(0, 0X1276);
    skip_0:
    // 0x80800FD4: b           L_80801000
    // 0x80800FD8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80801000;
    // 0x80800FD8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800FDC:
    // 0x80800FDC: addiu       $a0, $zero, 0x1276
    ctx->r4 = ADD32(0, 0X1276);
L_80800FE0:
    // 0x80800FE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800FE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800FE8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800FEC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800FF0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800FF4: jal         0x800C05B8
    // 0x80800FF8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_800C05B8(rdram, ctx);
        goto after_5;
    // 0x80800FF8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_5:
    // 0x80800FFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801000:
    // 0x80801000: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801004: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801008: jr          $ra
    // 0x8080100C: nop

    return;
    // 0x8080100C: nop

;}
RECOMP_FUNC void gclightsDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800370: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800374: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800378: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080037C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800380: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80800384: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800388: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8080038C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800390: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800394: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80800398: jal         0x800B28C4
    // 0x8080039C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    vector_begin(rdram, ctx);
        goto after_0;
    // 0x8080039C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x808003A0: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x808003A4: jal         0x800B296C
    // 0x808003A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    vector_end(rdram, ctx);
        goto after_1;
    // 0x808003A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x808003AC: lw          $s0, 0x5C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X5C);
    // 0x808003B0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808003B4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808003B8: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x808003BC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808003C0: beq         $at, $zero, L_80800438
    if (ctx->r1 == 0) {
        // 0x808003C4: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80800438;
    }
    // 0x808003C4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808003C8: addiu       $s1, $sp, 0x3C
    ctx->r17 = ADD32(ctx->r29, 0X3C);
    // 0x808003CC: lbu         $t7, 0x15($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X15);
L_808003D0:
    // 0x808003D0: beql        $t7, $zero, L_8080042C
    if (ctx->r15 == 0) {
        // 0x808003D4: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_8080042C;
    }
    goto skip_0;
    // 0x808003D4: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    skip_0:
    // 0x808003D8: lbu         $t8, 0x14($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X14);
    // 0x808003DC: beql        $t8, $zero, L_8080042C
    if (ctx->r24 == 0) {
        // 0x808003E0: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_8080042C;
    }
    goto skip_1;
    // 0x808003E0: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    skip_1:
    // 0x808003E4: lbu         $t9, 0x17($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X17);
    // 0x808003E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003EC: beql        $t9, $zero, L_8080042C
    if (ctx->r25 == 0) {
        // 0x808003F0: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_8080042C;
    }
    goto skip_2;
    // 0x808003F0: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    skip_2:
    // 0x808003F4: jal         0x800EE88C
    // 0x808003F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x808003F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x808003FC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800400: jal         0x800EEAD4
    // 0x80800404: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EEAD4(rdram, ctx);
        goto after_3;
    // 0x80800404: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80800408: beql        $s2, $zero, L_80800424
    if (ctx->r18 == 0) {
        // 0x8080040C: or          $s2, $s0, $zero
        ctx->r18 = ctx->r16 | 0;
            goto L_80800424;
    }
    goto skip_3;
    // 0x8080040C: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
    skip_3:
    // 0x80800410: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80800414: nop

    // 0x80800418: bc1fl       L_8080042C
    if (!c1cs) {
        // 0x8080041C: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_8080042C;
    }
    goto skip_4;
    // 0x8080041C: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    skip_4:
    // 0x80800420: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
L_80800424:
    // 0x80800424: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800428: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
L_8080042C:
    // 0x8080042C: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x80800430: bnel        $at, $zero, L_808003D0
    if (ctx->r1 != 0) {
        // 0x80800434: lbu         $t7, 0x15($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X15);
            goto L_808003D0;
    }
    goto skip_5;
    // 0x80800434: lbu         $t7, 0x15($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X15);
    skip_5:
L_80800438:
    // 0x80800438: beq         $s2, $zero, L_80800460
    if (ctx->r18 == 0) {
        // 0x8080043C: ldc1        $f20, 0x18($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
            goto L_80800460;
    }
    // 0x8080043C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800440: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80800444: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80800448: subu        $v1, $s2, $t0
    ctx->r3 = SUB32(ctx->r18, ctx->r8);
    // 0x8080044C: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x80800450: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x80800454: mflo        $v1
    ctx->r3 = lo;
    // 0x80800458: b           L_80800468
    // 0x8080045C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80800468;
    // 0x8080045C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80800460:
    // 0x80800460: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800464: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80800468:
    // 0x80800468: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080046C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800470: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800474: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800478: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8080047C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800480: jr          $ra
    // 0x80800484: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800484: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80801EC4_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801EC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801EC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801ECC: jal         0x800F54E4
    // 0x80801ED0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80801ED0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801ED4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80801ED8: jal         0x800F6D24
    // 0x80801EDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6D24(rdram, ctx);
        goto after_1;
    // 0x80801EDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80801EE0: beq         $v0, $zero, L_80801EF0
    if (ctx->r2 == 0) {
        // 0x80801EE4: nop
    
            goto L_80801EF0;
    }
    // 0x80801EE4: nop

    // 0x80801EE8: b           L_80801F0C
    // 0x80801EEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801F0C;
    // 0x80801EEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801EF0:
    // 0x80801EF0: jal         0x800F8004
    // 0x80801EF4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800F8004(rdram, ctx);
        goto after_2;
    // 0x80801EF4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80801EF8: beql        $v0, $zero, L_80801F0C
    if (ctx->r2 == 0) {
        // 0x80801EFC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80801F0C;
    }
    goto skip_0;
    // 0x80801EFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80801F00: b           L_80801F0C
    // 0x80801F04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801F0C;
    // 0x80801F04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801F08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801F0C:
    // 0x80801F0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801F10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801F14: jr          $ra
    // 0x80801F18: nop

    return;
    // 0x80801F18: nop

;}
RECOMP_FUNC void bsstand_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D0C: jal         0x80082FE8
    // 0x80800D10: nop

    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800D10: nop

    after_0:
    // 0x80800D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D1C: jr          $ra
    // 0x80800D20: nop

    return;
    // 0x80800D20: nop

;}
RECOMP_FUNC void func_80800000_chfantasyathlete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: beq         $a1, $zero, L_80800034
    if (ctx->r5 == 0) {
        // 0x8080000C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80800034;
    }
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800010: addiu       $a0, $zero, 0xA51
    ctx->r4 = ADD32(0, 0XA51);
    // 0x80800014: jal         0x800DA9E4
    // 0x80800018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_0;
    // 0x80800018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080001C: bnel        $v0, $zero, L_80800054
    if (ctx->r2 != 0) {
        // 0x80800020: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800054;
    }
    goto skip_0;
    // 0x80800020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800024: jal         0x800C78CC
    // 0x80800028: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C78CC(rdram, ctx);
        goto after_1;
    // 0x80800028: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8080002C: b           L_80800054
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800054;
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800034:
    // 0x80800034: addiu       $a0, $zero, 0xA51
    ctx->r4 = ADD32(0, 0XA51);
    // 0x80800038: jal         0x800DA9E4
    // 0x8080003C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA9E4(rdram, ctx);
        goto after_2;
    // 0x8080003C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800040: beql        $v0, $zero, L_80800054
    if (ctx->r2 == 0) {
        // 0x80800044: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800054;
    }
    goto skip_1;
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800048: jal         0x800C78CC
    // 0x8080004C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C78CC(rdram, ctx);
        goto after_3;
    // 0x8080004C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80800050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800054:
    // 0x80800054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800058: jr          $ra
    // 0x8080005C: nop

    return;
    // 0x8080005C: nop

;}
RECOMP_FUNC void func_80800000_chusefeather(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800004: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80800008: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80800014: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80800018: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8080001C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800020: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800024: lw          $a2, 0x24($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X24);
    // 0x80800028: lw          $a1, 0x48($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X48);
    // 0x8080002C: jal         0x800EF1B8
    // 0x80800030: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EF1B8(rdram, ctx);
        goto after_0;
    // 0x80800030: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800034: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80800038: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080003C: lwc1        $f0, 0x1C($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X1C);
    // 0x80800040: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x80800044: addiu       $s0, $sp, 0x54
    ctx->r16 = ADD32(ctx->r29, 0X54);
    // 0x80800048: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8080004C: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    // 0x80800050: addiu       $s3, $sp, 0x60
    ctx->r19 = ADD32(ctx->r29, 0X60);
    // 0x80800054: bc1fl       L_80800070
    if (!c1cs) {
        // 0x80800058: lui         $at, 0xC67A
        ctx->r1 = S32(0XC67A << 16);
            goto L_80800070;
    }
    goto skip_0;
    // 0x80800058: lui         $at, 0xC67A
    ctx->r1 = S32(0XC67A << 16);
    skip_0:
    // 0x8080005C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800060: nop

    // 0x80800064: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80800068: swc1        $f8, 0x1C($s4)
    MEM_W(0X1C, ctx->r20) = ctx->f8.u32l;
    // 0x8080006C: lui         $at, 0xC67A
    ctx->r1 = S32(0XC67A << 16);
L_80800070:
    // 0x80800070: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800074: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x80800078: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080007C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800080: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80800084: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80800088: bc1fl       L_808000A0
    if (!c1cs) {
        // 0x8080008C: lwc1        $f6, 0x58($s4)
        ctx->f6.u32l = MEM_W(ctx->r20, 0X58);
            goto L_808000A0;
    }
    goto skip_1;
    // 0x8080008C: lwc1        $f6, 0x58($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X58);
    skip_1:
    // 0x80800090: lwc1        $f16, 0x1C($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X1C);
    // 0x80800094: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80800098: swc1        $f18, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->f18.u32l;
    // 0x8080009C: lwc1        $f6, 0x58($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X58);
L_808000A0:
    // 0x808000A0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808000A4: nop

    // 0x808000A8: bc1f        L_80800164
    if (!c1cs) {
        // 0x808000AC: nop
    
            goto L_80800164;
    }
    // 0x808000AC: nop

    // 0x808000B0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808000B4: addiu       $s2, $sp, 0x58
    ctx->r18 = ADD32(ctx->r29, 0X58);
L_808000B8:
    // 0x808000B8: jal         0x800DC0C0
    // 0x808000BC: nop

    func_800DC0C0(rdram, ctx);
        goto after_1;
    // 0x808000BC: nop

    after_1:
    // 0x808000C0: bne         $s0, $s2, L_808000D0
    if (ctx->r16 != ctx->r18) {
        // 0x808000C4: add.s       $f10, $f0, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
            goto L_808000D0;
    }
    // 0x808000C4: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x808000C8: b           L_808000D4
    // 0x808000CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_808000D4;
    // 0x808000CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_808000D0:
    // 0x808000D0: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
L_808000D4:
    // 0x808000D4: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x808000D8: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x808000DC: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x808000E0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808000E4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x808000E8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808000EC: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x808000F0: sub.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x808000F4: bne         $s0, $s3, L_808000B8
    if (ctx->r16 != ctx->r19) {
        // 0x808000F8: swc1        $f10, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->f10.u32l;
            goto L_808000B8;
    }
    // 0x808000F8: swc1        $f10, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->f10.u32l;
    // 0x808000FC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(720, 0X340) << 16);
    // 0x80800100: addiu       $s1, $sp, 0x54
    ctx->r17 = ADD32(ctx->r29, 0X54);
    // 0x80800104: addiu       $t6, $t6, 0x340
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(720, 0X340));
    // 0x80800108: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080010C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800110: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800114: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800118: jal         0x800BABB8
    // 0x8080011C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x8080011C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x80800120: lw          $t7, 0x6C($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X6C);
    // 0x80800124: addiu       $at, $zero, 0x26A
    ctx->r1 = ADD32(0, 0X26A);
    // 0x80800128: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080012C: sll         $t8, $t7, 11
    ctx->r24 = S32(ctx->r15 << 11);
    // 0x80800130: srl         $t9, $t8, 20
    ctx->r25 = S32(U32(ctx->r24) >> 20);
    // 0x80800134: bne         $t9, $at, L_80800144
    if (ctx->r25 != ctx->r1) {
        // 0x80800138: addiu       $a1, $zero, 0x9E2
        ctx->r5 = ADD32(0, 0X9E2);
            goto L_80800144;
    }
    // 0x80800138: addiu       $a1, $zero, 0x9E2
    ctx->r5 = ADD32(0, 0X9E2);
    // 0x8080013C: b           L_80800144
    // 0x80800140: addiu       $a1, $zero, 0x9E4
    ctx->r5 = ADD32(0, 0X9E4);
        goto L_80800144;
    // 0x80800140: addiu       $a1, $zero, 0x9E4
    ctx->r5 = ADD32(0, 0X9E4);
L_80800144:
    // 0x80800144: jal         0x800BA3FC
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BA3FC(rdram, ctx);
        goto after_3;
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800150: jal         0x800BA75C
    // 0x80800154: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800BA75C(rdram, ctx);
        goto after_4;
    // 0x80800154: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: jal         0x800BABA0
    // 0x80800160: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    func_800BABA0(rdram, ctx);
        goto after_5;
    // 0x80800160: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_5:
L_80800164:
    // 0x80800164: jal         0x800D8FF8
    // 0x80800168: nop

    func_800D8FF8(rdram, ctx);
        goto after_6;
    // 0x80800168: nop

    after_6:
    // 0x8080016C: lwc1        $f8, 0x58($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X58);
    // 0x80800170: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800174: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80800178: sub.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8080017C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800180: swc1        $f16, 0x58($s4)
    MEM_W(0X58, ctx->r20) = ctx->f16.u32l;
    // 0x80800184: lwc1        $f12, 0x58($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X58);
    // 0x80800188: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x8080018C: nop

    // 0x80800190: bc1fl       L_808001AC
    if (!c1cs) {
        // 0x80800194: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_808001AC;
    }
    goto skip_2;
    // 0x80800194: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_2:
    // 0x80800198: jal         0x800FFAB0
    // 0x8080019C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_7;
    // 0x8080019C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_7:
    // 0x808001A0: b           L_808001E8
    // 0x808001A4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_808001E8;
    // 0x808001A4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x808001A8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_808001AC:
    // 0x808001AC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x808001B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808001B4: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x808001B8: jal         0x800F10B4
    // 0x808001BC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x808001BC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_8:
    // 0x808001C0: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808001C4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808001C8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808001CC: jal         0x80089C98
    // 0x808001D0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x808001D0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    after_9:
    // 0x808001D4: bnel        $s0, $zero, L_808001E8
    if (ctx->r16 != 0) {
        // 0x808001D8: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_808001E8;
    }
    goto skip_3;
    // 0x808001D8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_3:
    // 0x808001DC: jal         0x800FFAB0
    // 0x808001E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_10;
    // 0x808001E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_10:
    // 0x808001E4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_808001E8:
    // 0x808001E8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808001EC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808001F0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x808001F4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x808001F8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x808001FC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80800200: jr          $ra
    // 0x80800204: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80800204: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8080112C_chclinker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080112C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801130: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801134: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80801138: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080113C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80801140: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80801144: beq         $t6, $at, L_80801198
    if (ctx->r14 == ctx->r1) {
        // 0x80801148: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801198;
    }
    // 0x80801148: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080114C: beq         $t6, $at, L_80801168
    if (ctx->r14 == ctx->r1) {
        // 0x80801150: addiu       $a0, $a1, 0x58
        ctx->r4 = ADD32(ctx->r5, 0X58);
            goto L_80801168;
    }
    // 0x80801150: addiu       $a0, $a1, 0x58
    ctx->r4 = ADD32(ctx->r5, 0X58);
    // 0x80801154: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801158: beql        $t6, $at, L_8080119C
    if (ctx->r14 == ctx->r1) {
        // 0x8080115C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080119C;
    }
    goto skip_0;
    // 0x8080115C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801160: b           L_8080119C
    // 0x80801164: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080119C;
    // 0x80801164: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801168:
    // 0x80801168: jal         0x800D9078
    // 0x8080116C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x8080116C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x80801170: beq         $v0, $zero, L_80801198
    if (ctx->r2 == 0) {
        // 0x80801174: addiu       $a0, $zero, 0x35
        ctx->r4 = ADD32(0, 0X35);
            goto L_80801198;
    }
    // 0x80801174: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    // 0x80801178: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080117C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801180: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80801184: jal         0x800D1000
    // 0x80801188: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_1;
    // 0x80801188: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8080118C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801190: jal         0x80101FDC
    // 0x80801194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80801194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_80801198:
    // 0x80801198: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080119C:
    // 0x8080119C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808011A0: jr          $ra
    // 0x808011A4: nop

    return;
    // 0x808011A4: nop

;}
RECOMP_FUNC void func_80800BA8_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BA8: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80800BAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800BB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800BB4: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800BB8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2384, 0X2FF4) << 16);
    // 0x80800BBC: addiu       $at, $zero, 0x369
    ctx->r1 = ADD32(0, 0X369);
    // 0x80800BC0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800BC4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80800BC8: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80800BCC: lhu         $v0, 0x2FF4($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(2384, 0X2FF4));
    // 0x80800BD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800BD4: addiu       $t9, $sp, 0xD0
    ctx->r25 = ADD32(ctx->r29, 0XD0);
    // 0x80800BD8: beq         $v0, $at, L_80800C00
    if (ctx->r2 == ctx->r1) {
        // 0x80800BDC: lui         $t0, 0x8080
        ctx->r8 = S32(RELOC_HI16(2384, 0X30BC) << 16);
            goto L_80800C00;
    }
    // 0x80800BDC: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2384, 0X30BC) << 16);
    // 0x80800BE0: addiu       $at, $zero, 0x36A
    ctx->r1 = ADD32(0, 0X36A);
    // 0x80800BE4: beq         $v0, $at, L_80800E94
    if (ctx->r2 == ctx->r1) {
        // 0x80800BE8: addiu       $t1, $sp, 0x9C
        ctx->r9 = ADD32(ctx->r29, 0X9C);
            goto L_80800E94;
    }
    // 0x80800BE8: addiu       $t1, $sp, 0x9C
    ctx->r9 = ADD32(ctx->r29, 0X9C);
    // 0x80800BEC: addiu       $at, $zero, 0x36B
    ctx->r1 = ADD32(0, 0X36B);
    // 0x80800BF0: beq         $v0, $at, L_80801068
    if (ctx->r2 == ctx->r1) {
        // 0x80800BF4: lui         $t5, 0x8080
        ctx->r13 = S32(RELOC_HI16(2384, 0X311C) << 16);
            goto L_80801068;
    }
    // 0x80800BF4: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2384, 0X311C) << 16);
    // 0x80800BF8: b           L_8080133C
    // 0x80800BFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080133C;
    // 0x80800BFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800C00:
    // 0x80800C00: addiu       $t0, $t0, 0x30BC
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2384, 0X30BC));
    // 0x80800C04: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x80800C08: lw          $t2, 0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X4);
    // 0x80800C0C: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2384, 0X30CC) << 16);
    // 0x80800C10: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x80800C14: sw          $t2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r10;
    // 0x80800C18: lw          $t2, 0xC($t0)
    ctx->r10 = MEM_W(ctx->r8, 0XC);
    // 0x80800C1C: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x80800C20: addiu       $t4, $t4, 0x30CC
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2384, 0X30CC));
    // 0x80800C24: sw          $t2, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r10;
    // 0x80800C28: sw          $at, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r1;
    // 0x80800C2C: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
    // 0x80800C30: lw          $at, 0x0($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X0);
    // 0x80800C34: addiu       $t3, $sp, 0xC0
    ctx->r11 = ADD32(ctx->r29, 0XC0);
    // 0x80800C38: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x80800C3C: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x80800C40: lw          $at, 0x8($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X8);
    // 0x80800C44: lw          $t6, 0xC($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XC);
    // 0x80800C48: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2384, 0X30DC) << 16);
    // 0x80800C4C: addiu       $t8, $t8, 0x30DC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2384, 0X30DC));
    // 0x80800C50: sw          $at, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r1;
    // 0x80800C54: sw          $t6, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r14;
    // 0x80800C58: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80800C5C: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x80800C60: addiu       $t7, $sp, 0xB0
    ctx->r15 = ADD32(ctx->r29, 0XB0);
    // 0x80800C64: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x80800C68: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x80800C6C: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x80800C70: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80800C74: lui         $a1, 0x3E20
    ctx->r5 = S32(0X3E20 << 16);
    // 0x80800C78: sw          $at, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r1;
    // 0x80800C7C: sw          $t9, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r25;
    // 0x80800C80: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
    // 0x80800C84: ori         $a1, $a1, 0xC49C
    ctx->r5 = ctx->r5 | 0XC49C;
    // 0x80800C88: jal         0x80101E14
    // 0x80800C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_0;
    // 0x80800C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800C90: beq         $v0, $zero, L_80800CA4
    if (ctx->r2 == 0) {
        // 0x80800C94: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CA4;
    }
    // 0x80800C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C98: addiu       $t0, $zero, 0x55F0
    ctx->r8 = ADD32(0, 0X55F0);
    // 0x80800C9C: b           L_80800CD4
    // 0x80800CA0: sw          $t0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r8;
        goto L_80800CD4;
    // 0x80800CA0: sw          $t0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r8;
L_80800CA4:
    // 0x80800CA4: jal         0x80101E4C
    // 0x80800CA8: addiu       $a1, $sp, 0xD0
    ctx->r5 = ADD32(ctx->r29, 0XD0);
    func_80101E4C(rdram, ctx);
        goto after_1;
    // 0x80800CA8: addiu       $a1, $sp, 0xD0
    ctx->r5 = ADD32(ctx->r29, 0XD0);
    after_1:
    // 0x80800CAC: beq         $v0, $zero, L_80800CC0
    if (ctx->r2 == 0) {
        // 0x80800CB0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CC0;
    }
    // 0x80800CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CB4: addiu       $t2, $zero, 0x2710
    ctx->r10 = ADD32(0, 0X2710);
    // 0x80800CB8: b           L_80800CD4
    // 0x80800CBC: sw          $t2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r10;
        goto L_80800CD4;
    // 0x80800CBC: sw          $t2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r10;
L_80800CC0:
    // 0x80800CC0: jal         0x80101E4C
    // 0x80800CC4: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    func_80101E4C(rdram, ctx);
        goto after_2;
    // 0x80800CC4: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    after_2:
    // 0x80800CC8: beq         $v0, $zero, L_80800CD4
    if (ctx->r2 == 0) {
        // 0x80800CCC: addiu       $t5, $zero, 0x1388
        ctx->r13 = ADD32(0, 0X1388);
            goto L_80800CD4;
    }
    // 0x80800CCC: addiu       $t5, $zero, 0x1388
    ctx->r13 = ADD32(0, 0X1388);
    // 0x80800CD0: sw          $t5, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r13;
L_80800CD4:
    // 0x80800CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CD8: jal         0x80101E4C
    // 0x80800CDC: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    func_80101E4C(rdram, ctx);
        goto after_3;
    // 0x80800CDC: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    after_3:
    // 0x80800CE0: beq         $v0, $zero, L_80800DAC
    if (ctx->r2 == 0) {
        // 0x80800CE4: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2384, 0X2E60) << 16);
            goto L_80800DAC;
    }
    // 0x80800CE4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2E60) << 16);
    // 0x80800CE8: lwc1        $f12, 0x2E60($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2E60));
    // 0x80800CEC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2E64) << 16);
    // 0x80800CF0: jal         0x800DC178
    // 0x80800CF4: lwc1        $f14, 0x2E64($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2E64));
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80800CF4: lwc1        $f14, 0x2E64($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2E64));
    after_4:
    // 0x80800CF8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2E68) << 16);
    // 0x80800CFC: lwc1        $f4, 0x2E68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2E68));
    // 0x80800D00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800D04: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800D08: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800D0C: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800D10: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800D14: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800D18: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80800D1C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800D20: nop

    // 0x80800D24: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800D28: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800D2C: nop

    // 0x80800D30: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800D34: beql        $a0, $zero, L_80800D84
    if (ctx->r4 == 0) {
        // 0x80800D38: mfc1        $a0, $f8
        ctx->r4 = (int32_t)ctx->f8.u32l;
            goto L_80800D84;
    }
    goto skip_0;
    // 0x80800D38: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x80800D3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800D40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800D44: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800D48: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800D4C: nop

    // 0x80800D50: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80800D54: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800D58: nop

    // 0x80800D5C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800D60: bne         $a0, $zero, L_80800D78
    if (ctx->r4 != 0) {
        // 0x80800D64: nop
    
            goto L_80800D78;
    }
    // 0x80800D64: nop

    // 0x80800D68: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80800D6C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800D70: b           L_80800D90
    // 0x80800D74: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80800D90;
    // 0x80800D74: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80800D78:
    // 0x80800D78: b           L_80800D90
    // 0x80800D7C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80800D90;
    // 0x80800D7C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80800D80: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
L_80800D84:
    // 0x80800D84: nop

    // 0x80800D88: bltz        $a0, L_80800D78
    if (SIGNED(ctx->r4) < 0) {
        // 0x80800D8C: nop
    
            goto L_80800D78;
    }
    // 0x80800D8C: nop

L_80800D90:
    // 0x80800D90: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
    // 0x80800D94: lui         $at, 0x15
    ctx->r1 = S32(0X15 << 16);
    // 0x80800D98: ori         $at, $at, 0x7C04
    ctx->r1 = ctx->r1 | 0X7C04;
    // 0x80800D9C: sll         $t6, $t4, 21
    ctx->r14 = S32(ctx->r12 << 21);
    // 0x80800DA0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80800DA4: jal         0x800C4140
    // 0x80800DA8: addu        $a0, $t6, $at
    ctx->r4 = ADD32(ctx->r14, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_5;
    // 0x80800DA8: addu        $a0, $t6, $at
    ctx->r4 = ADD32(ctx->r14, ctx->r1);
    after_5:
L_80800DAC:
    // 0x80800DAC: lw          $t1, 0xAC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XAC);
    // 0x80800DB0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2E6C) << 16);
    // 0x80800DB4: addiu       $t7, $s0, 0x4
    ctx->r15 = ADD32(ctx->r16, 0X4);
    // 0x80800DB8: beql        $t1, $zero, L_8080133C
    if (ctx->r9 == 0) {
        // 0x80800DBC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080133C;
    }
    goto skip_1;
    // 0x80800DBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800DC0: lwc1        $f12, 0x2E6C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2E6C));
    // 0x80800DC4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2E70) << 16);
    // 0x80800DC8: lwc1        $f14, 0x2E70($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2E70));
    // 0x80800DCC: jal         0x800DC178
    // 0x80800DD0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x80800DD0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_6:
    // 0x80800DD4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2E74) << 16);
    // 0x80800DD8: lwc1        $f10, 0x2E74($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2E74));
    // 0x80800DDC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800DE0: lw          $t5, 0xAC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XAC);
    // 0x80800DE4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800DE8: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800DEC: sra         $t3, $t5, 5
    ctx->r11 = S32(SIGNED(ctx->r13) >> 5);
    // 0x80800DF0: andi        $t4, $t3, 0x3FF
    ctx->r12 = ctx->r11 & 0X3FF;
    // 0x80800DF4: sll         $t6, $t4, 11
    ctx->r14 = S32(ctx->r12 << 11);
    // 0x80800DF8: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800DFC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800E00: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80800E04: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80800E08: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800E0C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80800E10: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80800E14: nop

    // 0x80800E18: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80800E1C: beql        $t9, $zero, L_80800E6C
    if (ctx->r25 == 0) {
        // 0x80800E20: mfc1        $t9, $f18
        ctx->r25 = (int32_t)ctx->f18.u32l;
            goto L_80800E6C;
    }
    goto skip_2;
    // 0x80800E20: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    skip_2:
    // 0x80800E24: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800E28: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800E2C: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80800E30: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80800E34: nop

    // 0x80800E38: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80800E3C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80800E40: nop

    // 0x80800E44: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80800E48: bne         $t9, $zero, L_80800E60
    if (ctx->r25 != 0) {
        // 0x80800E4C: nop
    
            goto L_80800E60;
    }
    // 0x80800E4C: nop

    // 0x80800E50: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80800E54: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800E58: b           L_80800E78
    // 0x80800E5C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80800E78;
    // 0x80800E5C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80800E60:
    // 0x80800E60: b           L_80800E78
    // 0x80800E64: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80800E78;
    // 0x80800E64: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80800E68: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
L_80800E6C:
    // 0x80800E6C: nop

    // 0x80800E70: bltz        $t9, L_80800E60
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800E74: nop
    
            goto L_80800E60;
    }
    // 0x80800E74: nop

L_80800E78:
    // 0x80800E78: sll         $t2, $t9, 21
    ctx->r10 = S32(ctx->r25 << 21);
    // 0x80800E7C: addu        $a0, $t2, $t6
    ctx->r4 = ADD32(ctx->r10, ctx->r14);
    // 0x80800E80: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80800E84: jal         0x800C4140
    // 0x80800E88: addiu       $a0, $a0, 0x4C1
    ctx->r4 = ADD32(ctx->r4, 0X4C1);
    func_800C4140(rdram, ctx);
        goto after_7;
    // 0x80800E88: addiu       $a0, $a0, 0x4C1
    ctx->r4 = ADD32(ctx->r4, 0X4C1);
    after_7:
    // 0x80800E8C: b           L_8080133C
    // 0x80800E90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080133C;
    // 0x80800E90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800E94:
    // 0x80800E94: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2384, 0X30EC) << 16);
    // 0x80800E98: addiu       $t7, $t7, 0x30EC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2384, 0X30EC));
    // 0x80800E9C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800EA0: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80800EA4: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(2384, 0X30FC) << 16);
    // 0x80800EA8: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x80800EAC: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x80800EB0: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x80800EB4: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80800EB8: addiu       $t3, $t3, 0x30FC
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(2384, 0X30FC));
    // 0x80800EBC: sw          $t0, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r8;
    // 0x80800EC0: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x80800EC4: lw          $t6, 0x4($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X4);
    // 0x80800EC8: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80800ECC: addiu       $t5, $sp, 0x8C
    ctx->r13 = ADD32(ctx->r29, 0X8C);
    // 0x80800ED0: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
    // 0x80800ED4: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x80800ED8: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x80800EDC: lw          $t6, 0xC($t3)
    ctx->r14 = MEM_W(ctx->r11, 0XC);
    // 0x80800EE0: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2384, 0X310C) << 16);
    // 0x80800EE4: addiu       $t8, $t8, 0x310C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2384, 0X310C));
    // 0x80800EE8: sw          $at, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r1;
    // 0x80800EEC: sw          $t6, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r14;
    // 0x80800EF0: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x80800EF4: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x80800EF8: addiu       $t9, $sp, 0x7C
    ctx->r25 = ADD32(ctx->r29, 0X7C);
    // 0x80800EFC: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x80800F00: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x80800F04: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x80800F08: lw          $t0, 0xC($t8)
    ctx->r8 = MEM_W(ctx->r24, 0XC);
    // 0x80800F0C: lui         $a1, 0x3E01
    ctx->r5 = S32(0X3E01 << 16);
    // 0x80800F10: sw          $at, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r1;
    // 0x80800F14: sw          $t0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r8;
    // 0x80800F18: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x80800F1C: ori         $a1, $a1, 0x625
    ctx->r5 = ctx->r5 | 0X625;
    // 0x80800F20: jal         0x80101E14
    // 0x80800F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_8;
    // 0x80800F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800F28: beq         $v0, $zero, L_80800F3C
    if (ctx->r2 == 0) {
        // 0x80800F2C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F3C;
    }
    // 0x80800F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F30: addiu       $t2, $zero, 0x55F0
    ctx->r10 = ADD32(0, 0X55F0);
    // 0x80800F34: b           L_80800F88
    // 0x80800F38: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
        goto L_80800F88;
    // 0x80800F38: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
L_80800F3C:
    // 0x80800F3C: lui         $a1, 0x3E1F
    ctx->r5 = S32(0X3E1F << 16);
    // 0x80800F40: jal         0x80101E14
    // 0x80800F44: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    func_80101E14(rdram, ctx);
        goto after_9;
    // 0x80800F44: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    after_9:
    // 0x80800F48: bne         $v0, $zero, L_80800F64
    if (ctx->r2 != 0) {
        // 0x80800F4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F64;
    }
    // 0x80800F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F50: lui         $a1, 0x3F63
    ctx->r5 = S32(0X3F63 << 16);
    // 0x80800F54: jal         0x80101E14
    // 0x80800F58: ori         $a1, $a1, 0x53F8
    ctx->r5 = ctx->r5 | 0X53F8;
    func_80101E14(rdram, ctx);
        goto after_10;
    // 0x80800F58: ori         $a1, $a1, 0x53F8
    ctx->r5 = ctx->r5 | 0X53F8;
    after_10:
    // 0x80800F5C: beq         $v0, $zero, L_80800F70
    if (ctx->r2 == 0) {
        // 0x80800F60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F70;
    }
    // 0x80800F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800F64:
    // 0x80800F64: addiu       $t4, $zero, 0x2710
    ctx->r12 = ADD32(0, 0X2710);
    // 0x80800F68: b           L_80800F88
    // 0x80800F6C: sw          $t4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r12;
        goto L_80800F88;
    // 0x80800F6C: sw          $t4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r12;
L_80800F70:
    // 0x80800F70: lui         $a1, 0x3F6B
    ctx->r5 = S32(0X3F6B << 16);
    // 0x80800F74: jal         0x80101E14
    // 0x80800F78: ori         $a1, $a1, 0x20C
    ctx->r5 = ctx->r5 | 0X20C;
    func_80101E14(rdram, ctx);
        goto after_11;
    // 0x80800F78: ori         $a1, $a1, 0x20C
    ctx->r5 = ctx->r5 | 0X20C;
    after_11:
    // 0x80800F7C: beq         $v0, $zero, L_80800F88
    if (ctx->r2 == 0) {
        // 0x80800F80: addiu       $t5, $zero, 0x1388
        ctx->r13 = ADD32(0, 0X1388);
            goto L_80800F88;
    }
    // 0x80800F80: addiu       $t5, $zero, 0x1388
    ctx->r13 = ADD32(0, 0X1388);
    // 0x80800F84: sw          $t5, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r13;
L_80800F88:
    // 0x80800F88: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80800F8C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2E78) << 16);
    // 0x80800F90: beql        $t3, $zero, L_8080133C
    if (ctx->r11 == 0) {
        // 0x80800F94: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080133C;
    }
    goto skip_3;
    // 0x80800F94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80800F98: lwc1        $f12, 0x2E78($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2E78));
    // 0x80800F9C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2E7C) << 16);
    // 0x80800FA0: jal         0x800DC178
    // 0x80800FA4: lwc1        $f14, 0x2E7C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2E7C));
    func_800DC178(rdram, ctx);
        goto after_12;
    // 0x80800FA4: lwc1        $f14, 0x2E7C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2E7C));
    after_12:
    // 0x80800FA8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2E80) << 16);
    // 0x80800FAC: lwc1        $f4, 0x2E80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2E80));
    // 0x80800FB0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800FB4: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80800FB8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800FBC: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800FC0: sra         $t0, $t8, 5
    ctx->r8 = S32(SIGNED(ctx->r24) >> 5);
    // 0x80800FC4: andi        $t2, $t0, 0x3FF
    ctx->r10 = ctx->r8 & 0X3FF;
    // 0x80800FC8: sll         $t4, $t2, 11
    ctx->r12 = S32(ctx->r10 << 11);
    // 0x80800FCC: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800FD0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800FD4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80800FD8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80800FDC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800FE0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800FE4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80800FE8: nop

    // 0x80800FEC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80800FF0: beql        $t7, $zero, L_80801040
    if (ctx->r15 == 0) {
        // 0x80800FF4: mfc1        $t7, $f8
        ctx->r15 = (int32_t)ctx->f8.u32l;
            goto L_80801040;
    }
    goto skip_4;
    // 0x80800FF4: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    skip_4:
    // 0x80800FF8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800FFC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80801000: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80801004: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80801008: nop

    // 0x8080100C: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80801010: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80801014: nop

    // 0x80801018: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8080101C: bne         $t7, $zero, L_80801034
    if (ctx->r15 != 0) {
        // 0x80801020: nop
    
            goto L_80801034;
    }
    // 0x80801020: nop

    // 0x80801024: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80801028: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080102C: b           L_8080104C
    // 0x80801030: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8080104C;
    // 0x80801030: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80801034:
    // 0x80801034: b           L_8080104C
    // 0x80801038: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8080104C;
    // 0x80801038: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8080103C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
L_80801040:
    // 0x80801040: nop

    // 0x80801044: bltz        $t7, L_80801034
    if (SIGNED(ctx->r15) < 0) {
        // 0x80801048: nop
    
            goto L_80801034;
    }
    // 0x80801048: nop

L_8080104C:
    // 0x8080104C: sll         $t9, $t7, 21
    ctx->r25 = S32(ctx->r15 << 21);
    // 0x80801050: addu        $a0, $t9, $t4
    ctx->r4 = ADD32(ctx->r25, ctx->r12);
    // 0x80801054: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80801058: jal         0x800C4140
    // 0x8080105C: addiu       $a0, $a0, 0x4C1
    ctx->r4 = ADD32(ctx->r4, 0X4C1);
    func_800C4140(rdram, ctx);
        goto after_13;
    // 0x8080105C: addiu       $a0, $a0, 0x4C1
    ctx->r4 = ADD32(ctx->r4, 0X4C1);
    after_13:
    // 0x80801060: b           L_8080133C
    // 0x80801064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080133C;
    // 0x80801064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801068:
    // 0x80801068: addiu       $t5, $t5, 0x311C
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(2384, 0X311C));
    // 0x8080106C: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x80801070: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x80801074: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2384, 0X312C) << 16);
    // 0x80801078: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x8080107C: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80801080: addiu       $t1, $t1, 0x312C
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2384, 0X312C));
    // 0x80801084: addiu       $t7, $sp, 0x4C
    ctx->r15 = ADD32(ctx->r29, 0X4C);
    // 0x80801088: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8080108C: lw          $at, 0x8($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X8);
    // 0x80801090: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2384, 0X3148) << 16);
    // 0x80801094: addiu       $t9, $t9, 0x3148
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2384, 0X3148));
    // 0x80801098: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x8080109C: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x808010A0: addiu       $t2, $sp, 0x30
    ctx->r10 = ADD32(ctx->r29, 0X30);
    // 0x808010A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010A8: sw          $t6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r14;
    // 0x808010AC: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x808010B0: lw          $t0, 0x4($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X4);
    // 0x808010B4: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x808010B8: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x808010BC: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x808010C0: lw          $t0, 0xC($t1)
    ctx->r8 = MEM_W(ctx->r9, 0XC);
    // 0x808010C4: sw          $at, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r1;
    // 0x808010C8: lw          $at, 0x10($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X10);
    // 0x808010CC: sw          $t0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r8;
    // 0x808010D0: lw          $t0, 0x14($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X14);
    // 0x808010D4: sw          $at, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r1;
    // 0x808010D8: lw          $at, 0x18($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X18);
    // 0x808010DC: sw          $t0, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r8;
    // 0x808010E0: sw          $at, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r1;
    // 0x808010E4: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x808010E8: lw          $t3, 0x4($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X4);
    // 0x808010EC: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    // 0x808010F0: lw          $at, 0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X8);
    // 0x808010F4: sw          $t3, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r11;
    // 0x808010F8: lw          $t3, 0xC($t9)
    ctx->r11 = MEM_W(ctx->r25, 0XC);
    // 0x808010FC: sw          $at, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r1;
    // 0x80801100: lw          $at, 0x10($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X10);
    // 0x80801104: sw          $t3, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r11;
    // 0x80801108: lw          $t3, 0x14($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X14);
    // 0x8080110C: sw          $at, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r1;
    // 0x80801110: lw          $at, 0x18($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X18);
    // 0x80801114: sw          $t3, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r11;
    // 0x80801118: sw          $at, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->r1;
    // 0x8080111C: jal         0x80101E4C
    // 0x80801120: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    func_80101E4C(rdram, ctx);
        goto after_14;
    // 0x80801120: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_14:
    // 0x80801124: beq         $v0, $zero, L_80801138
    if (ctx->r2 == 0) {
        // 0x80801128: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801138;
    }
    // 0x80801128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080112C: addiu       $t5, $zero, 0x55F0
    ctx->r13 = ADD32(0, 0X55F0);
    // 0x80801130: b           L_80801180
    // 0x80801134: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
        goto L_80801180;
    // 0x80801134: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
L_80801138:
    // 0x80801138: jal         0x80101E4C
    // 0x8080113C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_80101E4C(rdram, ctx);
        goto after_15;
    // 0x8080113C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_15:
    // 0x80801140: beq         $v0, $zero, L_80801154
    if (ctx->r2 == 0) {
        // 0x80801144: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801154;
    }
    // 0x80801144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801148: addiu       $t6, $zero, 0x2710
    ctx->r14 = ADD32(0, 0X2710);
    // 0x8080114C: b           L_80801180
    // 0x80801150: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
        goto L_80801180;
    // 0x80801150: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
L_80801154:
    // 0x80801154: lui         $a1, 0x3EE1
    ctx->r5 = S32(0X3EE1 << 16);
    // 0x80801158: jal         0x80101E14
    // 0x8080115C: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    func_80101E14(rdram, ctx);
        goto after_16;
    // 0x8080115C: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    after_16:
    // 0x80801160: bne         $v0, $zero, L_80801178
    if (ctx->r2 != 0) {
        // 0x80801164: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801178;
    }
    // 0x80801164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801168: lui         $a1, 0x3F7E
    ctx->r5 = S32(0X3F7E << 16);
    // 0x8080116C: jal         0x80101E14
    // 0x80801170: ori         $a1, $a1, 0x76C9
    ctx->r5 = ctx->r5 | 0X76C9;
    func_80101E14(rdram, ctx);
        goto after_17;
    // 0x80801170: ori         $a1, $a1, 0x76C9
    ctx->r5 = ctx->r5 | 0X76C9;
    after_17:
    // 0x80801174: beq         $v0, $zero, L_80801180
    if (ctx->r2 == 0) {
        // 0x80801178: addiu       $t8, $zero, 0x1388
        ctx->r24 = ADD32(0, 0X1388);
            goto L_80801180;
    }
L_80801178:
    // 0x80801178: addiu       $t8, $zero, 0x1388
    ctx->r24 = ADD32(0, 0X1388);
    // 0x8080117C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_80801180:
    // 0x80801180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801184: jal         0x80101E4C
    // 0x80801188: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_80101E4C(rdram, ctx);
        goto after_18;
    // 0x80801188: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_18:
    // 0x8080118C: beq         $v0, $zero, L_80801258
    if (ctx->r2 == 0) {
        // 0x80801190: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2384, 0X2E84) << 16);
            goto L_80801258;
    }
    // 0x80801190: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2E84) << 16);
    // 0x80801194: lwc1        $f12, 0x2E84($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2E84));
    // 0x80801198: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2E88) << 16);
    // 0x8080119C: jal         0x800DC178
    // 0x808011A0: lwc1        $f14, 0x2E88($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2E88));
    func_800DC178(rdram, ctx);
        goto after_19;
    // 0x808011A0: lwc1        $f14, 0x2E88($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2E88));
    after_19:
    // 0x808011A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2E8C) << 16);
    // 0x808011A8: lwc1        $f10, 0x2E8C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2E8C));
    // 0x808011AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808011B0: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x808011B4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808011B8: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x808011BC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808011C0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808011C4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x808011C8: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x808011CC: nop

    // 0x808011D0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x808011D4: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x808011D8: nop

    // 0x808011DC: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x808011E0: beql        $a0, $zero, L_80801230
    if (ctx->r4 == 0) {
        // 0x808011E4: mfc1        $a0, $f18
        ctx->r4 = (int32_t)ctx->f18.u32l;
            goto L_80801230;
    }
    goto skip_5;
    // 0x808011E4: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    skip_5:
    // 0x808011E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808011EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808011F0: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x808011F4: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x808011F8: nop

    // 0x808011FC: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80801200: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80801204: nop

    // 0x80801208: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x8080120C: bne         $a0, $zero, L_80801224
    if (ctx->r4 != 0) {
        // 0x80801210: nop
    
            goto L_80801224;
    }
    // 0x80801210: nop

    // 0x80801214: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80801218: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080121C: b           L_8080123C
    // 0x80801220: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_8080123C;
    // 0x80801220: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80801224:
    // 0x80801224: b           L_8080123C
    // 0x80801228: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_8080123C;
    // 0x80801228: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8080122C: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
L_80801230:
    // 0x80801230: nop

    // 0x80801234: bltz        $a0, L_80801224
    if (SIGNED(ctx->r4) < 0) {
        // 0x80801238: nop
    
            goto L_80801224;
    }
    // 0x80801238: nop

L_8080123C:
    // 0x8080123C: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x80801240: lui         $at, 0x15
    ctx->r1 = S32(0X15 << 16);
    // 0x80801244: ori         $at, $at, 0x7C04
    ctx->r1 = ctx->r1 | 0X7C04;
    // 0x80801248: sll         $t0, $t1, 21
    ctx->r8 = S32(ctx->r9 << 21);
    // 0x8080124C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80801250: jal         0x800C4140
    // 0x80801254: addu        $a0, $t0, $at
    ctx->r4 = ADD32(ctx->r8, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_20;
    // 0x80801254: addu        $a0, $t0, $at
    ctx->r4 = ADD32(ctx->r8, ctx->r1);
    after_20:
L_80801258:
    // 0x80801258: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8080125C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2E90) << 16);
    // 0x80801260: addiu       $t2, $s0, 0x4
    ctx->r10 = ADD32(ctx->r16, 0X4);
    // 0x80801264: beql        $t4, $zero, L_8080133C
    if (ctx->r12 == 0) {
        // 0x80801268: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080133C;
    }
    goto skip_6;
    // 0x80801268: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x8080126C: lwc1        $f12, 0x2E90($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2E90));
    // 0x80801270: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2E94) << 16);
    // 0x80801274: lwc1        $f14, 0x2E94($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2E94));
    // 0x80801278: jal         0x800DC178
    // 0x8080127C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    func_800DC178(rdram, ctx);
        goto after_21;
    // 0x8080127C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    after_21:
    // 0x80801280: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2E98) << 16);
    // 0x80801284: lwc1        $f4, 0x2E98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2E98));
    // 0x80801288: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8080128C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80801290: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801294: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80801298: sra         $t7, $t8, 5
    ctx->r15 = S32(SIGNED(ctx->r24) >> 5);
    // 0x8080129C: andi        $t1, $t7, 0x3FF
    ctx->r9 = ctx->r15 & 0X3FF;
    // 0x808012A0: sll         $t0, $t1, 11
    ctx->r8 = S32(ctx->r9 << 11);
    // 0x808012A4: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x808012A8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808012AC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x808012B0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x808012B4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808012B8: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x808012BC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x808012C0: nop

    // 0x808012C4: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x808012C8: beql        $t3, $zero, L_80801318
    if (ctx->r11 == 0) {
        // 0x808012CC: mfc1        $t3, $f8
        ctx->r11 = (int32_t)ctx->f8.u32l;
            goto L_80801318;
    }
    goto skip_7;
    // 0x808012CC: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    skip_7:
    // 0x808012D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808012D4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x808012D8: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x808012DC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x808012E0: nop

    // 0x808012E4: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x808012E8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x808012EC: nop

    // 0x808012F0: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x808012F4: bne         $t3, $zero, L_8080130C
    if (ctx->r11 != 0) {
        // 0x808012F8: nop
    
            goto L_8080130C;
    }
    // 0x808012F8: nop

    // 0x808012FC: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x80801300: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801304: b           L_80801324
    // 0x80801308: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_80801324;
    // 0x80801308: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_8080130C:
    // 0x8080130C: b           L_80801324
    // 0x80801310: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_80801324;
    // 0x80801310: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80801314: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
L_80801318:
    // 0x80801318: nop

    // 0x8080131C: bltz        $t3, L_8080130C
    if (SIGNED(ctx->r11) < 0) {
        // 0x80801320: nop
    
            goto L_8080130C;
    }
    // 0x80801320: nop

L_80801324:
    // 0x80801324: sll         $t6, $t3, 21
    ctx->r14 = S32(ctx->r11 << 21);
    // 0x80801328: addu        $a0, $t6, $t0
    ctx->r4 = ADD32(ctx->r14, ctx->r8);
    // 0x8080132C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80801330: jal         0x800C4140
    // 0x80801334: addiu       $a0, $a0, 0x4C1
    ctx->r4 = ADD32(ctx->r4, 0X4C1);
    func_800C4140(rdram, ctx);
        goto after_22;
    // 0x80801334: addiu       $a0, $a0, 0x4C1
    ctx->r4 = ADD32(ctx->r4, 0X4C1);
    after_22:
    // 0x80801338: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080133C:
    // 0x8080133C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801340: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    // 0x80801344: jr          $ra
    // 0x80801348: nop

    return;
    // 0x80801348: nop

;}
RECOMP_FUNC void chintrochar_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804298: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080429C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808042A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808042A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808042A8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808042AC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808042B0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808042B4: jal         0x80106790
    // 0x808042B8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808042B8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x808042BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808042C0: jal         0x80100094
    // 0x808042C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808042C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x808042C8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x808042CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808042D0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808042D4: beq         $v1, $at, L_808042F0
    if (ctx->r3 == ctx->r1) {
        // 0x808042D8: lw          $t6, 0x2C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X2C);
            goto L_808042F0;
    }
    // 0x808042D8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x808042DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808042E0: beq         $v1, $at, L_80804328
    if (ctx->r3 == ctx->r1) {
        // 0x808042E4: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_80804328;
    }
    // 0x808042E4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x808042E8: b           L_8080435C
    // 0x808042EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080435C;
    // 0x808042EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808042F0:
    // 0x808042F0: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x808042F4: addu        $a0, $t7, $s0
    ctx->r4 = ADD32(ctx->r15, ctx->r16);
    // 0x808042F8: sltu        $at, $s0, $a0
    ctx->r1 = ctx->r16 < ctx->r4 ? 1 : 0;
    // 0x808042FC: beq         $at, $zero, L_80804358
    if (ctx->r1 == 0) {
        // 0x80804300: lh          $v1, 0xE0($v0)
        ctx->r3 = MEM_H(ctx->r2, 0XE0);
            goto L_80804358;
    }
    // 0x80804300: lh          $v1, 0xE0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XE0);
L_80804304:
    // 0x80804304: lh          $t8, 0xA($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XA);
    // 0x80804308: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8080430C: sltu        $at, $s0, $a0
    ctx->r1 = ctx->r16 < ctx->r4 ? 1 : 0;
    // 0x80804310: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80804314: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80804318: bne         $at, $zero, L_80804304
    if (ctx->r1 != 0) {
        // 0x8080431C: sh          $t9, -0x6($a2)
        MEM_H(-0X6, ctx->r6) = ctx->r25;
            goto L_80804304;
    }
    // 0x8080431C: sh          $t9, -0x6($a2)
    MEM_H(-0X6, ctx->r6) = ctx->r25;
    // 0x80804320: b           L_8080435C
    // 0x80804324: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080435C;
    // 0x80804324: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804328:
    // 0x80804328: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8080432C: addu        $a0, $t1, $s0
    ctx->r4 = ADD32(ctx->r9, ctx->r16);
    // 0x80804330: sltu        $at, $s0, $a0
    ctx->r1 = ctx->r16 < ctx->r4 ? 1 : 0;
    // 0x80804334: beq         $at, $zero, L_80804358
    if (ctx->r1 == 0) {
        // 0x80804338: lh          $v1, 0xE2($v0)
        ctx->r3 = MEM_H(ctx->r2, 0XE2);
            goto L_80804358;
    }
    // 0x80804338: lh          $v1, 0xE2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XE2);
L_8080433C:
    // 0x8080433C: lh          $t2, 0xA($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XA);
    // 0x80804340: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80804344: sltu        $at, $s0, $a0
    ctx->r1 = ctx->r16 < ctx->r4 ? 1 : 0;
    // 0x80804348: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x8080434C: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80804350: bne         $at, $zero, L_8080433C
    if (ctx->r1 != 0) {
        // 0x80804354: sh          $t3, -0x6($a2)
        MEM_H(-0X6, ctx->r6) = ctx->r11;
            goto L_8080433C;
    }
    // 0x80804354: sh          $t3, -0x6($a2)
    MEM_H(-0X6, ctx->r6) = ctx->r11;
L_80804358:
    // 0x80804358: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080435C:
    // 0x8080435C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804360: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80804364: jr          $ra
    // 0x80804368: nop

    return;
    // 0x80804368: nop

    // 0x8080436C: nop

;}
RECOMP_FUNC void _chanim_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085990: syscall     184
    recomp_syscall_handler(rdram, ctx, 0x80085990);
    return;
    // 0x80085994: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void chfantasylakebits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800010: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800014: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800018: jal         0x80106790
    // 0x8080001C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080001C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800020: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800024: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800028: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080002C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80800030: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    // 0x80800034: sltu        $at, $a2, $a0
    ctx->r1 = ctx->r6 < ctx->r4 ? 1 : 0;
    // 0x80800038: beq         $at, $zero, L_8080006C
    if (ctx->r1 == 0) {
        // 0x8080003C: addiu       $v1, $zero, 0xFF
        ctx->r3 = ADD32(0, 0XFF);
            goto L_8080006C;
    }
    // 0x8080003C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_80800040:
    // 0x80800040: sb          $v1, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r3;
    // 0x80800044: sb          $v1, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r3;
    // 0x80800048: sb          $zero, 0xE($a2)
    MEM_B(0XE, ctx->r6) = 0;
    // 0x8080004C: lh          $t9, 0x2($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X2);
    // 0x80800050: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x80800054: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80800058: sltu        $at, $a2, $a0
    ctx->r1 = ctx->r6 < ctx->r4 ? 1 : 0;
    // 0x8080005C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80800060: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80800064: bne         $at, $zero, L_80800040
    if (ctx->r1 != 0) {
        // 0x80800068: sh          $t0, -0xE($a2)
        MEM_H(-0XE, ctx->r6) = ctx->r8;
            goto L_80800040;
    }
    // 0x80800068: sh          $t0, -0xE($a2)
    MEM_H(-0XE, ctx->r6) = ctx->r8;
L_8080006C:
    // 0x8080006C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800070: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800074: jr          $ra
    // 0x80800078: nop

    return;
    // 0x80800078: nop

;}
RECOMP_FUNC void func_8080167C_chsabreman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080167C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801680: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801684: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801688: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8080168C: jal         0x80088078
    // 0x80801690: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    _gcdialogcamera_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80801690: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80801694: beq         $v0, $zero, L_808016D0
    if (ctx->r2 == 0) {
        // 0x80801698: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808016D0;
    }
    // 0x80801698: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080169C: jal         0x80100094
    // 0x808016A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808016A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808016A4: beq         $v0, $zero, L_808016C8
    if (ctx->r2 == 0) {
        // 0x808016A8: nop
    
            goto L_808016C8;
    }
    // 0x808016A8: nop

    // 0x808016AC: lh          $t6, 0x820($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X820);
    // 0x808016B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808016B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808016B8: beq         $t6, $at, L_808016C8
    if (ctx->r14 == ctx->r1) {
        // 0x808016BC: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_808016C8;
    }
    // 0x808016BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808016C0: jal         0x80801724
    // 0x808016C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80801724_chsabreman(rdram, ctx);
        goto after_2;
    // 0x808016C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_808016C8:
    // 0x808016C8: b           L_808016D4
    // 0x808016CC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808016D4;
    // 0x808016CC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_808016D0:
    // 0x808016D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808016D4:
    // 0x808016D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808016D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808016DC: jr          $ra
    // 0x808016E0: nop

    return;
    // 0x808016E0: nop

;}
RECOMP_FUNC void func_808003F0_chbilldrillboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003F8: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x808003FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800400: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800404: beq         $a1, $at, L_80800428
    if (ctx->r5 == ctx->r1) {
        // 0x80800408: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800428;
    }
    // 0x80800408: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080040C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800410: beq         $a1, $at, L_8080047C
    if (ctx->r5 == ctx->r1) {
        // 0x80800414: addiu       $at, $zero, 0x90
        ctx->r1 = ADD32(0, 0X90);
            goto L_8080047C;
    }
    // 0x80800414: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800418: beq         $a1, $at, L_8080049C
    if (ctx->r5 == ctx->r1) {
        // 0x8080041C: nop
    
            goto L_8080049C;
    }
    // 0x8080041C: nop

    // 0x80800420: b           L_808004C0
    // 0x80800424: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004C0;
    // 0x80800424: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800428:
    // 0x80800428: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x8080042C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800430: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800434: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800438: beql        $t7, $at, L_808004C0
    if (ctx->r15 == ctx->r1) {
        // 0x8080043C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808004C0;
    }
    goto skip_0;
    // 0x8080043C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800440: jal         0x8008A4B8
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800448: beql        $v0, $zero, L_808004C0
    if (ctx->r2 == 0) {
        // 0x8080044C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808004C0;
    }
    goto skip_1;
    // 0x8080044C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80800450: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800458: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080045C: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x80800460: jal         0x80103110
    // 0x80800464: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x80800464: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    after_1:
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080046C: jal         0x80101FDC
    // 0x80800470: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800470: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800474: b           L_808004C0
    // 0x80800478: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004C0;
    // 0x80800478: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080047C:
    // 0x8080047C: jal         0x8010A570
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_3;
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800488: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080048C: jal         0x80086670
    // 0x80800490: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800490: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x80800494: b           L_808004C0
    // 0x80800498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004C0;
    // 0x80800498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080049C:
    // 0x8080049C: jal         0x80800024
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800024_chbilldrillboulder(rdram, ctx);
        goto after_5;
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808004A4: jal         0x800FFAB0
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808004AC: b           L_808004C0
    // 0x808004B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004C0;
    // 0x808004B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808004B4: b           L_808004C0
    // 0x808004B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004C0;
    // 0x808004B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808004BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004C0:
    // 0x808004C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004CC: jr          $ra
    // 0x808004D0: nop

    return;
    // 0x808004D0: nop

;}
RECOMP_FUNC void _suexpressmorph_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B60: syscall     803
    recomp_syscall_handler(rdram, ctx, 0x80089B60);
    return;
    // 0x80089B64: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80800034_chmumboskulls(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800034: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800038: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080003C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800040: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800044: bne         $a1, $at, L_80800064
    if (ctx->r5 != ctx->r1) {
        // 0x80800048: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800064;
    }
    // 0x80800048: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080004C: jal         0x8080007C
    // 0x80800050: nop

    func_8080007C_chmumboskulls(rdram, ctx);
        goto after_0;
    // 0x80800050: nop

    after_0:
    // 0x80800054: jal         0x8010A63C
    // 0x80800058: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8010A63C(rdram, ctx);
        goto after_1;
    // 0x80800058: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080005C: b           L_8080006C
    // 0x80800060: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080006C;
    // 0x80800060: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800064:
    // 0x80800064: b           L_8080006C
    // 0x80800068: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080006C;
    // 0x80800068: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080006C:
    // 0x8080006C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800070: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800074: jr          $ra
    // 0x80800078: nop

    return;
    // 0x80800078: nop

;}
RECOMP_FUNC void chfiregen_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1588, 0X15B4) << 16);
    // 0x808000A8: jr          $ra
    // 0x808000AC: addiu       $v0, $v0, 0x15B4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X15B4));
    return;
    // 0x808000AC: addiu       $v0, $v0, 0x15B4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X15B4));
;}
RECOMP_FUNC void func_80107C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107C2C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80107C30: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80107C34: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80107C38: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80107C3C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80107C40: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80107C44: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80107C48: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80107C4C: jal         0x80106668
    // 0x80107C50: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_80106668(rdram, ctx);
        goto after_0;
    // 0x80107C50: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x80107C54: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80107C58: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80107C5C: lbu         $t1, 0x72($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X72);
    // 0x80107C60: sw          $t6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r14;
    // 0x80107C64: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x80107C68: andi        $t2, $t1, 0xFF03
    ctx->r10 = ctx->r9 & 0XFF03;
    // 0x80107C6C: lbu         $t9, 0x65($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X65);
    // 0x80107C70: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80107C74: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80107C78: sb          $t3, 0x72($v0)
    MEM_B(0X72, ctx->r2) = ctx->r11;
    // 0x80107C7C: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x80107C80: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80107C84: ori         $t1, $t9, 0x1
    ctx->r9 = ctx->r25 | 0X1;
    // 0x80107C88: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80107C8C: lw          $v1, 0x6C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X6C);
    // 0x80107C90: lbu         $t8, 0x77($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X77);
    // 0x80107C94: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80107C98: srl         $t3, $v1, 9
    ctx->r11 = S32(U32(ctx->r3) >> 9);
    // 0x80107C9C: andi        $t9, $t8, 0xFFF0
    ctx->r25 = ctx->r24 & 0XFFF0;
    // 0x80107CA0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80107CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80107CA8: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80107CAC: lw          $t5, 0x4($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X4);
    // 0x80107CB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80107CB4: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80107CB8: nop

    // 0x80107CBC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80107CC0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80107CC4: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x80107CC8: lw          $t6, 0x8($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X8);
    // 0x80107CCC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80107CD0: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80107CD4: nop

    // 0x80107CD8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80107CDC: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    // 0x80107CE0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80107CE4: sb          $t1, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r9;
    // 0x80107CE8: swc1        $f6, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f6.u32l;
    // 0x80107CEC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80107CF0: lbu         $t1, 0x7A($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X7A);
    // 0x80107CF4: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80107CF8: andi        $t0, $t1, 0xFF3F
    ctx->r8 = ctx->r9 & 0XFF3F;
    // 0x80107CFC: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x80107D00: swc1        $f0, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f0.u32l;
    // 0x80107D04: lh          $t2, 0x2($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X2);
    // 0x80107D08: sb          $t9, 0x77($v0)
    MEM_B(0X77, ctx->r2) = ctx->r25;
    // 0x80107D0C: swc1        $f8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f8.u32l;
    // 0x80107D10: xor         $t4, $t2, $t3
    ctx->r12 = ctx->r10 ^ ctx->r11;
    // 0x80107D14: sll         $t5, $t4, 20
    ctx->r13 = S32(ctx->r12 << 20);
    // 0x80107D18: lbu         $t4, 0x65($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X65);
    // 0x80107D1C: srl         $t6, $t5, 11
    ctx->r14 = S32(U32(ctx->r13) >> 11);
    // 0x80107D20: ori         $t2, $t0, 0x40
    ctx->r10 = ctx->r8 | 0X40;
    // 0x80107D24: xor         $t7, $t6, $v1
    ctx->r15 = ctx->r14 ^ ctx->r3;
    // 0x80107D28: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x80107D2C: sw          $t7, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r15;
    // 0x80107D30: sb          $t2, 0x7A($v0)
    MEM_B(0X7A, ctx->r2) = ctx->r10;
    // 0x80107D34: sb          $t5, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r13;
    // 0x80107D38: lhu         $t6, 0x18($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X18);
    // 0x80107D3C: sh          $t6, 0x7C($v0)
    MEM_H(0X7C, ctx->r2) = ctx->r14;
    // 0x80107D40: lwc1        $f16, 0x1C($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80107D44: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x80107D48: nop

    // 0x80107D4C: bc1tl       L_80107D68
    if (c1cs) {
        // 0x80107D50: lbu         $t1, 0x75($v0)
        ctx->r9 = MEM_BU(ctx->r2, 0X75);
            goto L_80107D68;
    }
    goto skip_0;
    // 0x80107D50: lbu         $t1, 0x75($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X75);
    skip_0:
    // 0x80107D54: lbu         $t8, 0x75($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X75);
    // 0x80107D58: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x80107D5C: b           L_80107D70
    // 0x80107D60: sb          $t9, 0x75($v0)
    MEM_B(0X75, ctx->r2) = ctx->r25;
        goto L_80107D70;
    // 0x80107D60: sb          $t9, 0x75($v0)
    MEM_B(0X75, ctx->r2) = ctx->r25;
    // 0x80107D64: lbu         $t1, 0x75($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X75);
L_80107D68:
    // 0x80107D68: andi        $t0, $t1, 0xFFEF
    ctx->r8 = ctx->r9 & 0XFFEF;
    // 0x80107D6C: sb          $t0, 0x75($v0)
    MEM_B(0X75, ctx->r2) = ctx->r8;
L_80107D70:
    // 0x80107D70: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x80107D74: lbu         $t6, 0x95($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X95);
    // 0x80107D78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80107D7C: sll         $t3, $t2, 11
    ctx->r11 = S32(ctx->r10 << 11);
    // 0x80107D80: srl         $t4, $t3, 31
    ctx->r12 = S32(U32(ctx->r11) >> 31);
    // 0x80107D84: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80107D88: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x80107D8C: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80107D90: sb          $t8, 0x95($s0)
    MEM_B(0X95, ctx->r16) = ctx->r24;
    // 0x80107D94: jal         0x80100074
    // 0x80107D98: lhu         $a2, 0x30($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X30);
    func_80100074(rdram, ctx);
        goto after_1;
    // 0x80107D98: lhu         $a2, 0x30($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X30);
    after_1:
    // 0x80107D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80107DA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80107DA4: jal         0x80100074
    // 0x80107DA8: lhu         $a2, 0x32($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X32);
    func_80100074(rdram, ctx);
        goto after_2;
    // 0x80107DA8: lhu         $a2, 0x32($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X32);
    after_2:
    // 0x80107DAC: lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4);
    // 0x80107DB0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80107DB4: bne         $a0, $at, L_80107DEC
    if (ctx->r4 != ctx->r1) {
        // 0x80107DB8: nop
    
            goto L_80107DEC;
    }
    // 0x80107DB8: nop

    // 0x80107DBC: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    // 0x80107DC0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80107DC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80107DC8: andi        $t1, $t9, 0x400
    ctx->r9 = ctx->r25 & 0X400;
    // 0x80107DCC: beq         $t1, $zero, L_80107DDC
    if (ctx->r9 == 0) {
        // 0x80107DD0: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80107DDC;
    }
    // 0x80107DD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80107DD4: b           L_80107DDC
    // 0x80107DD8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80107DDC;
    // 0x80107DD8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80107DDC:
    // 0x80107DDC: jal         0x800EBED4
    // 0x80107DE0: lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X0);
    func_800EBED4(rdram, ctx);
        goto after_3;
    // 0x80107DE0: lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X0);
    after_3:
    // 0x80107DE4: b           L_80107E34
    // 0x80107DE8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
        goto L_80107E34;
    // 0x80107DE8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_80107DEC:
    // 0x80107DEC: jal         0x800D738C
    // 0x80107DF0: nop

    func_800D738C(rdram, ctx);
        goto after_4;
    // 0x80107DF0: nop

    after_4:
    // 0x80107DF4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80107DF8: bne         $v0, $at, L_80107E08
    if (ctx->r2 != ctx->r1) {
        // 0x80107DFC: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80107E08;
    }
    // 0x80107DFC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80107E00: b           L_80107E0C
    // 0x80107E04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80107E0C;
    // 0x80107E04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80107E08:
    // 0x80107E08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80107E0C:
    // 0x80107E0C: lw          $t0, 0x24($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X24);
    // 0x80107E10: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80107E14: andi        $t2, $t0, 0x400
    ctx->r10 = ctx->r8 & 0X400;
    // 0x80107E18: beq         $t2, $zero, L_80107E28
    if (ctx->r10 == 0) {
        // 0x80107E1C: nop
    
            goto L_80107E28;
    }
    // 0x80107E1C: nop

    // 0x80107E20: b           L_80107E28
    // 0x80107E24: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80107E28;
    // 0x80107E24: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80107E28:
    // 0x80107E28: jal         0x800EBED4
    // 0x80107E2C: lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X0);
    func_800EBED4(rdram, ctx);
        goto after_5;
    // 0x80107E2C: lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X0);
    after_5:
    // 0x80107E30: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_80107E34:
    // 0x80107E34: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80107E38: lbu         $t4, 0x19($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X19);
    // 0x80107E3C: ori         $t6, $t4, 0x1
    ctx->r14 = ctx->r12 | 0X1;
    // 0x80107E40: sb          $t6, 0x19($v0)
    MEM_B(0X19, ctx->r2) = ctx->r14;
    // 0x80107E44: lw          $v1, 0x2C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X2C);
    // 0x80107E48: beql        $v1, $zero, L_80107E60
    if (ctx->r3 == 0) {
        // 0x80107E4C: lw          $t8, 0x0($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X0);
            goto L_80107E60;
    }
    goto skip_1;
    // 0x80107E4C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80107E50: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80107E54: b           L_80107E6C
    // 0x80107E58: sw          $v1, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r3;
        goto L_80107E6C;
    // 0x80107E58: sw          $v1, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r3;
    // 0x80107E5C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
L_80107E60:
    // 0x80107E60: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80107E64: addiu       $t7, $t7, 0x7C20
    ctx->r15 = ADD32(ctx->r15, 0X7C20);
    // 0x80107E68: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
L_80107E6C:
    // 0x80107E6C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80107E70: jal         0x800EC340
    // 0x80107E74: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800EC340(rdram, ctx);
        goto after_6;
    // 0x80107E74: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_6:
    // 0x80107E78: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80107E7C: jal         0x800EC360
    // 0x80107E80: lhu         $a1, 0x4($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X4);
    func_800EC360(rdram, ctx);
        goto after_7;
    // 0x80107E80: lhu         $a1, 0x4($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X4);
    after_7:
    // 0x80107E84: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80107E88: jal         0x800EC368
    // 0x80107E8C: lhu         $a1, 0x22($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X22);
    func_800EC368(rdram, ctx);
        goto after_8;
    // 0x80107E8C: lhu         $a1, 0x22($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X22);
    after_8:
    // 0x80107E90: lbu         $t1, 0x75($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X75);
    // 0x80107E94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80107E98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80107E9C: ori         $t5, $t1, 0x1
    ctx->r13 = ctx->r9 | 0X1;
    // 0x80107EA0: sb          $t5, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r13;
    // 0x80107EA4: lhu         $t3, 0x74($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X74);
    // 0x80107EA8: andi        $t7, $t5, 0xF7
    ctx->r15 = ctx->r13 & 0XF7;
    // 0x80107EAC: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80107EB0: andi        $t6, $t4, 0x8
    ctx->r14 = ctx->r12 & 0X8;
    // 0x80107EB4: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80107EB8: jal         0x80102FA0
    // 0x80107EBC: sb          $t8, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r24;
    func_80102FA0(rdram, ctx);
        goto after_9;
    // 0x80107EBC: sb          $t8, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r24;
    after_9:
    // 0x80107EC0: beql        $v0, $zero, L_80107ED4
    if (ctx->r2 == 0) {
        // 0x80107EC4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80107ED4;
    }
    goto skip_2;
    // 0x80107EC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_2:
    // 0x80107EC8: jal         0x8008A498
    // 0x80107ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x80107ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80107ED0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80107ED4:
    // 0x80107ED4: jal         0x80102FA0
    // 0x80107ED8: lui         $a1, 0x80
    ctx->r5 = S32(0X80 << 16);
    func_80102FA0(rdram, ctx);
        goto after_11;
    // 0x80107ED8: lui         $a1, 0x80
    ctx->r5 = S32(0X80 << 16);
    after_11:
    // 0x80107EDC: beq         $v0, $zero, L_80107EF0
    if (ctx->r2 == 0) {
        // 0x80107EE0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80107EF0;
    }
    // 0x80107EE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80107EE4: lbu         $t1, 0x71($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X71);
    // 0x80107EE8: ori         $t0, $t1, 0x20
    ctx->r8 = ctx->r9 | 0X20;
    // 0x80107EEC: sb          $t0, 0x71($s0)
    MEM_B(0X71, ctx->r16) = ctx->r8;
L_80107EF0:
    // 0x80107EF0: jal         0x80102FA0
    // 0x80107EF4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80102FA0(rdram, ctx);
        goto after_12;
    // 0x80107EF4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_12:
    // 0x80107EF8: beq         $v0, $zero, L_80107F0C
    if (ctx->r2 == 0) {
        // 0x80107EFC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80107F0C;
    }
    // 0x80107EFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80107F00: lbu         $t3, 0x70($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X70);
    // 0x80107F04: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80107F08: sb          $t4, 0x70($s0)
    MEM_B(0X70, ctx->r16) = ctx->r12;
L_80107F0C:
    // 0x80107F0C: jal         0x80102FA0
    // 0x80107F10: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    func_80102FA0(rdram, ctx);
        goto after_13;
    // 0x80107F10: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    after_13:
    // 0x80107F14: beq         $v0, $zero, L_80107F2C
    if (ctx->r2 == 0) {
        // 0x80107F18: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80107F2C;
    }
    // 0x80107F18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80107F1C: lbu         $t5, 0x77($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X77);
    // 0x80107F20: andi        $t6, $t5, 0xFFF0
    ctx->r14 = ctx->r13 & 0XFFF0;
    // 0x80107F24: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80107F28: sb          $t7, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r15;
L_80107F2C:
    // 0x80107F2C: jal         0x80102FA0
    // 0x80107F30: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    func_80102FA0(rdram, ctx);
        goto after_14;
    // 0x80107F30: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    after_14:
    // 0x80107F34: beq         $v0, $zero, L_80107F48
    if (ctx->r2 == 0) {
        // 0x80107F38: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80107F48;
    }
    // 0x80107F38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80107F3C: lbu         $t9, 0x64($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X64);
    // 0x80107F40: ori         $t1, $t9, 0x2
    ctx->r9 = ctx->r25 | 0X2;
    // 0x80107F44: sb          $t1, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r9;
L_80107F48:
    // 0x80107F48: jal         0x80102FA0
    // 0x80107F4C: lui         $a1, 0x400
    ctx->r5 = S32(0X400 << 16);
    func_80102FA0(rdram, ctx);
        goto after_15;
    // 0x80107F4C: lui         $a1, 0x400
    ctx->r5 = S32(0X400 << 16);
    after_15:
    // 0x80107F50: beq         $v0, $zero, L_80107F64
    if (ctx->r2 == 0) {
        // 0x80107F54: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80107F64;
    }
    // 0x80107F54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80107F58: lbu         $t2, 0x71($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X71);
    // 0x80107F5C: ori         $t3, $t2, 0x40
    ctx->r11 = ctx->r10 | 0X40;
    // 0x80107F60: sb          $t3, 0x71($s0)
    MEM_B(0X71, ctx->r16) = ctx->r11;
L_80107F64:
    // 0x80107F64: jal         0x80102FA0
    // 0x80107F68: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102FA0(rdram, ctx);
        goto after_16;
    // 0x80107F68: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_16:
    // 0x80107F6C: bne         $v0, $zero, L_80107F80
    if (ctx->r2 != 0) {
        // 0x80107F70: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80107F80;
    }
    // 0x80107F70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80107F74: lbu         $t5, 0x75($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X75);
    // 0x80107F78: ori         $t6, $t5, 0x2
    ctx->r14 = ctx->r13 | 0X2;
    // 0x80107F7C: sb          $t6, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r14;
L_80107F80:
    // 0x80107F80: jal         0x80102FA0
    // 0x80107F84: lui         $a1, 0x10
    ctx->r5 = S32(0X10 << 16);
    func_80102FA0(rdram, ctx);
        goto after_17;
    // 0x80107F84: lui         $a1, 0x10
    ctx->r5 = S32(0X10 << 16);
    after_17:
    // 0x80107F88: bne         $v0, $zero, L_80107F9C
    if (ctx->r2 != 0) {
        // 0x80107F8C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80107F9C;
    }
    // 0x80107F8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80107F90: lbu         $t8, 0x71($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X71);
    // 0x80107F94: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x80107F98: sb          $t9, 0x71($s0)
    MEM_B(0X71, ctx->r16) = ctx->r25;
L_80107F9C:
    // 0x80107F9C: jal         0x80102FA0
    // 0x80107FA0: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    func_80102FA0(rdram, ctx);
        goto after_18;
    // 0x80107FA0: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    after_18:
    // 0x80107FA4: beq         $v0, $zero, L_80107FB8
    if (ctx->r2 == 0) {
        // 0x80107FA8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80107FB8;
    }
    // 0x80107FA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80107FAC: lbu         $t0, 0x71($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X71);
    // 0x80107FB0: ori         $t2, $t0, 0x4
    ctx->r10 = ctx->r8 | 0X4;
    // 0x80107FB4: sb          $t2, 0x71($s0)
    MEM_B(0X71, ctx->r16) = ctx->r10;
L_80107FB8:
    // 0x80107FB8: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80107FBC: jal         0x80102FA0
    // 0x80107FC0: ori         $a1, $a1, 0x2
    ctx->r5 = ctx->r5 | 0X2;
    func_80102FA0(rdram, ctx);
        goto after_19;
    // 0x80107FC0: ori         $a1, $a1, 0x2
    ctx->r5 = ctx->r5 | 0X2;
    after_19:
    // 0x80107FC4: beq         $v0, $zero, L_80107FDC
    if (ctx->r2 == 0) {
        // 0x80107FC8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80107FDC;
    }
    // 0x80107FC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80107FCC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80107FD0: lbu         $t3, 0x2A($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X2A);
    // 0x80107FD4: andi        $t4, $t3, 0xFFFD
    ctx->r12 = ctx->r11 & 0XFFFD;
    // 0x80107FD8: sb          $t4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r12;
L_80107FDC:
    // 0x80107FDC: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80107FE0: jal         0x80102FA0
    // 0x80107FE4: ori         $a1, $a1, 0x4
    ctx->r5 = ctx->r5 | 0X4;
    func_80102FA0(rdram, ctx);
        goto after_20;
    // 0x80107FE4: ori         $a1, $a1, 0x4
    ctx->r5 = ctx->r5 | 0X4;
    after_20:
    // 0x80107FE8: beq         $v0, $zero, L_80107FFC
    if (ctx->r2 == 0) {
        // 0x80107FEC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80107FFC;
    }
    // 0x80107FEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80107FF0: lbu         $t6, 0x64($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X64);
    // 0x80107FF4: ori         $t7, $t6, 0x80
    ctx->r15 = ctx->r14 | 0X80;
    // 0x80107FF8: sb          $t7, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r15;
L_80107FFC:
    // 0x80107FFC: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80108000: jal         0x80102FA0
    // 0x80108004: ori         $a1, $a1, 0x8
    ctx->r5 = ctx->r5 | 0X8;
    func_80102FA0(rdram, ctx);
        goto after_21;
    // 0x80108004: ori         $a1, $a1, 0x8
    ctx->r5 = ctx->r5 | 0X8;
    after_21:
    // 0x80108008: beq         $v0, $zero, L_8010801C
    if (ctx->r2 == 0) {
        // 0x8010800C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8010801C;
    }
    // 0x8010800C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80108010: lbu         $t9, 0x64($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X64);
    // 0x80108014: ori         $t1, $t9, 0x40
    ctx->r9 = ctx->r25 | 0X40;
    // 0x80108018: sb          $t1, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r9;
L_8010801C:
    // 0x8010801C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80108020: jal         0x80102FA0
    // 0x80108024: ori         $a1, $a1, 0x400
    ctx->r5 = ctx->r5 | 0X400;
    func_80102FA0(rdram, ctx);
        goto after_22;
    // 0x80108024: ori         $a1, $a1, 0x400
    ctx->r5 = ctx->r5 | 0X400;
    after_22:
    // 0x80108028: beq         $v0, $zero, L_8010803C
    if (ctx->r2 == 0) {
        // 0x8010802C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8010803C;
    }
    // 0x8010802C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80108030: lbu         $t2, 0x71($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X71);
    // 0x80108034: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x80108038: sb          $t3, 0x71($s0)
    MEM_B(0X71, ctx->r16) = ctx->r11;
L_8010803C:
    // 0x8010803C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80108040: jal         0x80102FA0
    // 0x80108044: ori         $a1, $a1, 0x1000
    ctx->r5 = ctx->r5 | 0X1000;
    func_80102FA0(rdram, ctx);
        goto after_23;
    // 0x80108044: ori         $a1, $a1, 0x1000
    ctx->r5 = ctx->r5 | 0X1000;
    after_23:
    // 0x80108048: beq         $v0, $zero, L_8010805C
    if (ctx->r2 == 0) {
        // 0x8010804C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8010805C;
    }
    // 0x8010804C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80108050: lbu         $t5, 0x71($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X71);
    // 0x80108054: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80108058: sb          $t6, 0x71($s0)
    MEM_B(0X71, ctx->r16) = ctx->r14;
L_8010805C:
    // 0x8010805C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80108060: jal         0x80102FA0
    // 0x80108064: ori         $a1, $a1, 0x2000
    ctx->r5 = ctx->r5 | 0X2000;
    func_80102FA0(rdram, ctx);
        goto after_24;
    // 0x80108064: ori         $a1, $a1, 0x2000
    ctx->r5 = ctx->r5 | 0X2000;
    after_24:
    // 0x80108068: beq         $v0, $zero, L_8010807C
    if (ctx->r2 == 0) {
        // 0x8010806C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8010807C;
    }
    // 0x8010806C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80108070: lbu         $t8, 0x77($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X77);
    // 0x80108074: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x80108078: sb          $t9, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r25;
L_8010807C:
    // 0x8010807C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80108080: jal         0x80102FA0
    // 0x80108084: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    func_80102FA0(rdram, ctx);
        goto after_25;
    // 0x80108084: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    after_25:
    // 0x80108088: beq         $v0, $zero, L_8010809C
    if (ctx->r2 == 0) {
        // 0x8010808C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8010809C;
    }
    // 0x8010808C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80108090: lbu         $t0, 0x7E($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X7E);
    // 0x80108094: ori         $t2, $t0, 0x20
    ctx->r10 = ctx->r8 | 0X20;
    // 0x80108098: sb          $t2, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r10;
L_8010809C:
    // 0x8010809C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x801080A0: jal         0x80102FA0
    // 0x801080A4: ori         $a1, $a1, 0x100
    ctx->r5 = ctx->r5 | 0X100;
    func_80102FA0(rdram, ctx);
        goto after_26;
    // 0x801080A4: ori         $a1, $a1, 0x100
    ctx->r5 = ctx->r5 | 0X100;
    after_26:
    // 0x801080A8: beq         $v0, $zero, L_801080BC
    if (ctx->r2 == 0) {
        // 0x801080AC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801080BC;
    }
    // 0x801080AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801080B0: lbu         $t4, 0x74($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X74);
    // 0x801080B4: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x801080B8: sb          $t5, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r13;
L_801080BC:
    // 0x801080BC: jal         0x80102FA0
    // 0x801080C0: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    func_80102FA0(rdram, ctx);
        goto after_27;
    // 0x801080C0: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    after_27:
    // 0x801080C4: beq         $v0, $zero, L_801080D8
    if (ctx->r2 == 0) {
        // 0x801080C8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801080D8;
    }
    // 0x801080C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801080CC: lbu         $t7, 0x75($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X75);
    // 0x801080D0: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x801080D4: sb          $t8, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r24;
L_801080D8:
    // 0x801080D8: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x801080DC: jal         0x80102FA0
    // 0x801080E0: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    func_80102FA0(rdram, ctx);
        goto after_28;
    // 0x801080E0: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    after_28:
    // 0x801080E4: beq         $v0, $zero, L_801080F8
    if (ctx->r2 == 0) {
        // 0x801080E8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801080F8;
    }
    // 0x801080E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801080EC: lbu         $t1, 0x64($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X64);
    // 0x801080F0: ori         $t0, $t1, 0x1
    ctx->r8 = ctx->r9 | 0X1;
    // 0x801080F4: sb          $t0, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r8;
L_801080F8:
    // 0x801080F8: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x801080FC: jal         0x80102FA0
    // 0x80108100: ori         $a1, $a1, 0x10
    ctx->r5 = ctx->r5 | 0X10;
    func_80102FA0(rdram, ctx);
        goto after_29;
    // 0x80108100: ori         $a1, $a1, 0x10
    ctx->r5 = ctx->r5 | 0X10;
    after_29:
    // 0x80108104: beq         $v0, $zero, L_80108118
    if (ctx->r2 == 0) {
        // 0x80108108: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80108118;
    }
    // 0x80108108: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010810C: lbu         $t3, 0x7B($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X7B);
    // 0x80108110: ori         $t4, $t3, 0x2
    ctx->r12 = ctx->r11 | 0X2;
    // 0x80108114: sb          $t4, 0x7B($s0)
    MEM_B(0X7B, ctx->r16) = ctx->r12;
L_80108118:
    // 0x80108118: jal         0x80102FA0
    // 0x8010811C: lui         $a1, 0x8040
    ctx->r5 = S32(0X8040 << 16);
    func_80102FA0(rdram, ctx);
        goto after_30;
    // 0x8010811C: lui         $a1, 0x8040
    ctx->r5 = S32(0X8040 << 16);
    after_30:
    // 0x80108120: beq         $v0, $zero, L_80108134
    if (ctx->r2 == 0) {
        // 0x80108124: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80108134;
    }
    // 0x80108124: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80108128: lbu         $t6, 0x94($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X94);
    // 0x8010812C: ori         $t7, $t6, 0x80
    ctx->r15 = ctx->r14 | 0X80;
    // 0x80108130: sb          $t7, 0x94($s0)
    MEM_B(0X94, ctx->r16) = ctx->r15;
L_80108134:
    // 0x80108134: jal         0x80102FA0
    // 0x80108138: lui         $a1, 0x8080
    ctx->r5 = S32(0X8080 << 16);
    func_80102FA0(rdram, ctx);
        goto after_31;
    // 0x80108138: lui         $a1, 0x8080
    ctx->r5 = S32(0X8080 << 16);
    after_31:
    // 0x8010813C: beq         $v0, $zero, L_80108150
    if (ctx->r2 == 0) {
        // 0x80108140: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80108150;
    }
    // 0x80108140: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80108144: lbu         $t9, 0x94($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X94);
    // 0x80108148: ori         $t1, $t9, 0x40
    ctx->r9 = ctx->r25 | 0X40;
    // 0x8010814C: sb          $t1, 0x94($s0)
    MEM_B(0X94, ctx->r16) = ctx->r9;
L_80108150:
    // 0x80108150: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80108154: jal         0x80102FA0
    // 0x80108158: ori         $a1, $a1, 0x40
    ctx->r5 = ctx->r5 | 0X40;
    func_80102FA0(rdram, ctx);
        goto after_32;
    // 0x80108158: ori         $a1, $a1, 0x40
    ctx->r5 = ctx->r5 | 0X40;
    after_32:
    // 0x8010815C: beq         $v0, $zero, L_80108170
    if (ctx->r2 == 0) {
        // 0x80108160: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80108170;
    }
    // 0x80108160: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80108164: lbu         $t2, 0x73($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X73);
    // 0x80108168: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x8010816C: sb          $t3, 0x73($s0)
    MEM_B(0X73, ctx->r16) = ctx->r11;
L_80108170:
    // 0x80108170: jal         0x80102FA0
    // 0x80108174: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    func_80102FA0(rdram, ctx);
        goto after_33;
    // 0x80108174: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    after_33:
    // 0x80108178: beq         $v0, $zero, L_8010818C
    if (ctx->r2 == 0) {
        // 0x8010817C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8010818C;
    }
    // 0x8010817C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80108180: lbu         $t5, 0x79($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X79);
    // 0x80108184: ori         $t6, $t5, 0x8
    ctx->r14 = ctx->r13 | 0X8;
    // 0x80108188: sb          $t6, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r14;
L_8010818C:
    // 0x8010818C: jal         0x80102FA0
    // 0x80108190: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    func_80102FA0(rdram, ctx);
        goto after_34;
    // 0x80108190: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    after_34:
    // 0x80108194: beq         $v0, $zero, L_801081A8
    if (ctx->r2 == 0) {
        // 0x80108198: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801081A8;
    }
    // 0x80108198: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010819C: lbu         $t8, 0x95($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X95);
    // 0x801081A0: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x801081A4: sb          $t9, 0x95($s0)
    MEM_B(0X95, ctx->r16) = ctx->r25;
L_801081A8:
    // 0x801081A8: jal         0x80102FA0
    // 0x801081AC: lui         $a1, 0x8400
    ctx->r5 = S32(0X8400 << 16);
    func_80102FA0(rdram, ctx);
        goto after_35;
    // 0x801081AC: lui         $a1, 0x8400
    ctx->r5 = S32(0X8400 << 16);
    after_35:
    // 0x801081B0: beq         $v0, $zero, L_801081C4
    if (ctx->r2 == 0) {
        // 0x801081B4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801081C4;
    }
    // 0x801081B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801081B8: lbu         $t0, 0x96($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X96);
    // 0x801081BC: ori         $t2, $t0, 0x40
    ctx->r10 = ctx->r8 | 0X40;
    // 0x801081C0: sb          $t2, 0x96($s0)
    MEM_B(0X96, ctx->r16) = ctx->r10;
L_801081C4:
    // 0x801081C4: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x801081C8: jal         0x80102FA0
    // 0x801081CC: ori         $a1, $a1, 0x80
    ctx->r5 = ctx->r5 | 0X80;
    func_80102FA0(rdram, ctx);
        goto after_36;
    // 0x801081CC: ori         $a1, $a1, 0x80
    ctx->r5 = ctx->r5 | 0X80;
    after_36:
    // 0x801081D0: beq         $v0, $zero, L_801081E4
    if (ctx->r2 == 0) {
        // 0x801081D4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801081E4;
    }
    // 0x801081D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801081D8: lbu         $t4, 0x71($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X71);
    // 0x801081DC: ori         $t5, $t4, 0x8
    ctx->r13 = ctx->r12 | 0X8;
    // 0x801081E0: sb          $t5, 0x71($s0)
    MEM_B(0X71, ctx->r16) = ctx->r13;
L_801081E4:
    // 0x801081E4: jal         0x80102FA0
    // 0x801081E8: lui         $a1, 0x8200
    ctx->r5 = S32(0X8200 << 16);
    func_80102FA0(rdram, ctx);
        goto after_37;
    // 0x801081E8: lui         $a1, 0x8200
    ctx->r5 = S32(0X8200 << 16);
    after_37:
    // 0x801081EC: beq         $v0, $zero, L_80108200
    if (ctx->r2 == 0) {
        // 0x801081F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80108200;
    }
    // 0x801081F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801081F4: lbu         $t6, 0x95($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X95);
    // 0x801081F8: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x801081FC: sb          $t7, 0x95($s0)
    MEM_B(0X95, ctx->r16) = ctx->r15;
L_80108200:
    // 0x80108200: jal         0x8010A800
    // 0x80108204: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A800(rdram, ctx);
        goto after_38;
    // 0x80108204: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_38:
    // 0x80108208: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010820C: jal         0x80102FA0
    // 0x80108210: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    func_80102FA0(rdram, ctx);
        goto after_39;
    // 0x80108210: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    after_39:
    // 0x80108214: beq         $v0, $zero, L_8010822C
    if (ctx->r2 == 0) {
        // 0x80108218: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010822C;
    }
    // 0x80108218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010821C: jal         0x8010A800
    // 0x80108220: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010A800(rdram, ctx);
        goto after_40;
    // 0x80108220: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_40:
    // 0x80108224: jal         0x8010A63C
    // 0x80108228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A63C(rdram, ctx);
        goto after_41;
    // 0x80108228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
L_8010822C:
    // 0x8010822C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80108230: jal         0x80102FA0
    // 0x80108234: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    func_80102FA0(rdram, ctx);
        goto after_42;
    // 0x80108234: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    after_42:
    // 0x80108238: beq         $v0, $zero, L_80108250
    if (ctx->r2 == 0) {
        // 0x8010823C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80108250;
    }
    // 0x8010823C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80108240: jal         0x8010A800
    // 0x80108244: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A800(rdram, ctx);
        goto after_43;
    // 0x80108244: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_43:
    // 0x80108248: b           L_80108298
    // 0x8010824C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
        goto L_80108298;
    // 0x8010824C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
L_80108250:
    // 0x80108250: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80108254: jal         0x80102FA0
    // 0x80108258: lui         $a1, 0x40
    ctx->r5 = S32(0X40 << 16);
    func_80102FA0(rdram, ctx);
        goto after_44;
    // 0x80108258: lui         $a1, 0x40
    ctx->r5 = S32(0X40 << 16);
    after_44:
    // 0x8010825C: beq         $v0, $zero, L_80108278
    if (ctx->r2 == 0) {
        // 0x80108260: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80108278;
    }
    // 0x80108260: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80108264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80108268: jal         0x8010A800
    // 0x8010826C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8010A800(rdram, ctx);
        goto after_45;
    // 0x8010826C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_45:
    // 0x80108270: b           L_80108298
    // 0x80108274: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
        goto L_80108298;
    // 0x80108274: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
L_80108278:
    // 0x80108278: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8010827C: jal         0x80102FA0
    // 0x80108280: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    func_80102FA0(rdram, ctx);
        goto after_46;
    // 0x80108280: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    after_46:
    // 0x80108284: beq         $v0, $zero, L_80108294
    if (ctx->r2 == 0) {
        // 0x80108288: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80108294;
    }
    // 0x80108288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010828C: jal         0x8010A800
    // 0x80108290: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8010A800(rdram, ctx);
        goto after_47;
    // 0x80108290: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_47:
L_80108294:
    // 0x80108294: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
L_80108298:
    // 0x80108298: ori         $a1, $a1, 0x800
    ctx->r5 = ctx->r5 | 0X800;
    // 0x8010829C: jal         0x80102FA0
    // 0x801082A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80102FA0(rdram, ctx);
        goto after_48;
    // 0x801082A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_48:
    // 0x801082A4: beq         $v0, $zero, L_801082BC
    if (ctx->r2 == 0) {
        // 0x801082A8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801082BC;
    }
    // 0x801082A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801082AC: lbu         $t8, 0x7E($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X7E);
    // 0x801082B0: andi        $t9, $t8, 0xFFBF
    ctx->r25 = ctx->r24 & 0XFFBF;
    // 0x801082B4: b           L_801082C8
    // 0x801082B8: sb          $t9, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r25;
        goto L_801082C8;
    // 0x801082B8: sb          $t9, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r25;
L_801082BC:
    // 0x801082BC: lbu         $t0, 0x7E($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X7E);
    // 0x801082C0: ori         $t2, $t0, 0x40
    ctx->r10 = ctx->r8 | 0X40;
    // 0x801082C4: sb          $t2, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r10;
L_801082C8:
    // 0x801082C8: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x801082CC: jal         0x80102FA0
    // 0x801082D0: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    func_80102FA0(rdram, ctx);
        goto after_49;
    // 0x801082D0: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    after_49:
    // 0x801082D4: beq         $v0, $zero, L_801082EC
    if (ctx->r2 == 0) {
        // 0x801082D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801082EC;
    }
    // 0x801082D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801082DC: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x801082E0: andi        $t4, $t3, 0xFFFE
    ctx->r12 = ctx->r11 & 0XFFFE;
    // 0x801082E4: b           L_801082F8
    // 0x801082E8: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
        goto L_801082F8;
    // 0x801082E8: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
L_801082EC:
    // 0x801082EC: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x801082F0: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x801082F4: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
L_801082F8:
    // 0x801082F8: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x801082FC: beql        $a3, $zero, L_80108344
    if (ctx->r7 == 0) {
        // 0x80108300: lw          $a1, 0x24($s1)
        ctx->r5 = MEM_W(ctx->r17, 0X24);
            goto L_80108344;
    }
    goto skip_3;
    // 0x80108300: lw          $a1, 0x24($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X24);
    skip_3:
    // 0x80108304: lw          $t8, 0x10($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X10);
    // 0x80108308: lhu         $t2, 0x6C($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X6C);
    // 0x8010830C: lbu         $t1, 0x73($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X73);
    // 0x80108310: srl         $t9, $t8, 21
    ctx->r25 = S32(U32(ctx->r24) >> 21);
    // 0x80108314: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x80108318: andi        $t3, $t2, 0x1F
    ctx->r11 = ctx->r10 & 0X1F;
    // 0x8010831C: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x80108320: sh          $t4, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = ctx->r12;
    // 0x80108324: lw          $t5, 0x10($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X10);
    // 0x80108328: andi        $t2, $t1, 0xFFFE
    ctx->r10 = ctx->r9 & 0XFFFE;
    // 0x8010832C: sll         $t6, $t5, 30
    ctx->r14 = S32(ctx->r13 << 30);
    // 0x80108330: srl         $t8, $t6, 31
    ctx->r24 = S32(U32(ctx->r14) >> 31);
    // 0x80108334: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80108338: or          $t0, $t9, $t2
    ctx->r8 = ctx->r25 | ctx->r10;
    // 0x8010833C: sb          $t0, 0x73($s0)
    MEM_B(0X73, ctx->r16) = ctx->r8;
    // 0x80108340: lw          $a1, 0x24($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X24);
L_80108344:
    // 0x80108344: jal         0x80108658
    // 0x80108348: lw          $a2, 0x3C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X3C);
    func_80108658(rdram, ctx);
        goto after_50;
    // 0x80108348: lw          $a2, 0x3C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X3C);
    after_50:
    // 0x8010834C: lui         $t3, 0x4A
    ctx->r11 = S32(0X4A << 16);
    // 0x80108350: ori         $t3, $t3, 0x21
    ctx->r11 = ctx->r11 | 0X21;
    // 0x80108354: sw          $t3, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r11;
    // 0x80108358: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010835C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80108360: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80108364: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
L_80108368:
    // 0x80108368: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8010836C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80108370: bne         $v0, $a1, L_80108368
    if (ctx->r2 != ctx->r5) {
        // 0x80108374: sb          $a0, 0x5B($v1)
        MEM_B(0X5B, ctx->r3) = ctx->r4;
            goto L_80108368;
    }
    // 0x80108374: sb          $a0, 0x5B($v1)
    MEM_B(0X5B, ctx->r3) = ctx->r4;
    // 0x80108378: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8010837C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80108380: addiu       $a0, $s0, 0x98
    ctx->r4 = ADD32(ctx->r16, 0X98);
    // 0x80108384: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80108388: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8010838C: jal         0x800F31FC
    // 0x80108390: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800F31FC(rdram, ctx);
        goto after_51;
    // 0x80108390: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_51:
    // 0x80108394: lw          $t5, 0x40($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X40);
    // 0x80108398: beql        $t5, $zero, L_801083B4
    if (ctx->r13 == 0) {
        // 0x8010839C: lbu         $t1, 0x74($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X74);
            goto L_801083B4;
    }
    goto skip_4;
    // 0x8010839C: lbu         $t1, 0x74($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X74);
    skip_4:
    // 0x801083A0: lbu         $t7, 0x74($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X74);
    // 0x801083A4: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x801083A8: b           L_801083BC
    // 0x801083AC: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
        goto L_801083BC;
    // 0x801083AC: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
    // 0x801083B0: lbu         $t1, 0x74($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X74);
L_801083B4:
    // 0x801083B4: andi        $t9, $t1, 0xFFEF
    ctx->r25 = ctx->r9 & 0XFFEF;
    // 0x801083B8: sb          $t9, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r25;
L_801083BC:
    // 0x801083BC: lbu         $t0, 0x74($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X74);
    // 0x801083C0: lhu         $a1, 0x72($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X72);
    // 0x801083C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801083C8: ori         $t3, $t0, 0x8
    ctx->r11 = ctx->r8 | 0X8;
    // 0x801083CC: srl         $t4, $a1, 10
    ctx->r12 = S32(U32(ctx->r5) >> 10);
    // 0x801083D0: sb          $t3, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r11;
    // 0x801083D4: jal         0x80102424
    // 0x801083D8: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    func_80102424(rdram, ctx);
        goto after_52;
    // 0x801083D8: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    after_52:
    // 0x801083DC: jal         0x80103930
    // 0x801083E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103930(rdram, ctx);
        goto after_53;
    // 0x801083E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_53:
    // 0x801083E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801083E8: jal         0x8010A3E8
    // 0x801083EC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8010A3E8(rdram, ctx);
        goto after_54;
    // 0x801083EC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_54:
    // 0x801083F0: jal         0x80106E88
    // 0x801083F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80106E88(rdram, ctx);
        goto after_55;
    // 0x801083F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_55:
    // 0x801083F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801083FC: jal         0x80102FA0
    // 0x80108400: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80102FA0(rdram, ctx);
        goto after_56;
    // 0x80108400: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_56:
    // 0x80108404: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80108408: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010840C: jal         0x80102FA0
    // 0x80108410: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80102FA0(rdram, ctx);
        goto after_57;
    // 0x80108410: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_57:
    // 0x80108414: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80108418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010841C: jal         0x80104F2C
    // 0x80108420: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80104F2C(rdram, ctx);
        goto after_58;
    // 0x80108420: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_58:
    // 0x80108424: jal         0x800BEC1C
    // 0x80108428: nop

    func_800BEC1C(rdram, ctx);
        goto after_59;
    // 0x80108428: nop

    after_59:
    // 0x8010842C: beql        $v0, $zero, L_80108440
    if (ctx->r2 == 0) {
        // 0x80108430: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80108440;
    }
    goto skip_5;
    // 0x80108430: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x80108434: jal         0x8008A7A8
    // 0x80108438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiezone_entrypoint_0(rdram, ctx);
        goto after_60;
    // 0x80108438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_60:
    // 0x8010843C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80108440:
    // 0x80108440: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80108444: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80108448: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8010844C: jr          $ra
    // 0x80108450: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80108450: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _gcmapsects_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087F18: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087F18);
    return;
    // 0x80087F1C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8080064C_chstatuebossbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080064C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800650: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800654: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800658: jal         0x800DA298
    // 0x8080065C: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080065C: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    after_0:
    // 0x80800660: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800664: bne         $v1, $zero, L_80800678
    if (ctx->r3 != 0) {
        // 0x80800668: nop
    
            goto L_80800678;
    }
    // 0x80800668: nop

    // 0x8080066C: jal         0x80088848
    // 0x80800670: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80800670: nop

    after_1:
    // 0x80800674: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
L_80800678:
    // 0x80800678: beq         $v1, $zero, L_80800688
    if (ctx->r3 == 0) {
        // 0x8080067C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800688;
    }
    // 0x8080067C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800680: jal         0x80101FDC
    // 0x80800684: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800684: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_80800688:
    // 0x80800688: addiu       $t6, $zero, 0x102
    ctx->r14 = ADD32(0, 0X102);
    // 0x8080068C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80800690: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800694: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800698: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080069C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808006A0: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x808006A4: jal         0x80086898
    // 0x808006A8: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x808006A8: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    after_3:
    // 0x808006AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808006B0: jal         0x800868A8
    // 0x808006B4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x808006B4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_4:
    // 0x808006B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808006BC: jal         0x800868C0
    // 0x808006C0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x808006C0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_5:
    // 0x808006C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808006CC: jr          $ra
    // 0x808006D0: nop

    return;
    // 0x808006D0: nop

    // 0x808006D4: nop

    // 0x808006D8: nop

    // 0x808006DC: nop

;}
RECOMP_FUNC void func_808021A8_sucoaster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808021A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808021AC: andi        $t6, $a2, 0x1000
    ctx->r14 = ctx->r6 & 0X1000;
    // 0x808021B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808021B4: bne         $t6, $zero, L_808021CC
    if (ctx->r14 != 0) {
        // 0x808021B8: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_808021CC;
    }
    // 0x808021B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808021BC: lw          $v0, 0x18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18);
    // 0x808021C0: sll         $t8, $v0, 11
    ctx->r24 = S32(ctx->r2 << 11);
    // 0x808021C4: bgez        $t8, L_808021DC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808021C8: srl         $a0, $v0, 28
        ctx->r4 = S32(U32(ctx->r2) >> 28);
            goto L_808021DC;
    }
    // 0x808021C8: srl         $a0, $v0, 28
    ctx->r4 = S32(U32(ctx->r2) >> 28);
L_808021CC:
    // 0x808021CC: lh          $t9, 0x10($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X10);
    // 0x808021D0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x808021D4: b           L_80802250
    // 0x808021D8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
        goto L_80802250;
    // 0x808021D8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
L_808021DC:
    // 0x808021DC: jal         0x8008A258
    // 0x808021E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    _sucoasterdata_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808021E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808021E4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808021E8: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x808021EC: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x808021F0: lh          $t0, 0xE($a1)
    ctx->r8 = MEM_H(ctx->r5, 0XE);
    // 0x808021F4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808021F8: lh          $t1, 0xC($a1)
    ctx->r9 = MEM_H(ctx->r5, 0XC);
    // 0x808021FC: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80802200: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80802204: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80802208: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080220C: lh          $t2, 0x10($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X10);
    // 0x80802210: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802214: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80802218: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8080221C: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80802220: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80802224: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80802228: mul.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8080222C: nop

    // 0x80802230: mul.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80802234: jal         0x80103EAC
    // 0x80802238: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    func_80103EAC(rdram, ctx);
        goto after_1;
    // 0x80802238: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8080223C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80802240: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80802244: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80802248: jal         0x800F0E00
    // 0x8080224C: add.s       $f12, $f0, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f18.fl;
    func_800F0E00(rdram, ctx);
        goto after_2;
    // 0x8080224C: add.s       $f12, $f0, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f18.fl;
    after_2:
L_80802250:
    // 0x80802250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802254: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802258: jr          $ra
    // 0x8080225C: nop

    return;
    // 0x8080225C: nop

;}
RECOMP_FUNC void bsbwhirl_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808007BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808007C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007C8: jal         0x80800200
    // 0x808007CC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_80800200_bsbwhirl(rdram, ctx);
        goto after_0;
    // 0x808007CC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808007D0: lui         $a1, 0x3EF0
    ctx->r5 = S32(0X3EF0 << 16);
    // 0x808007D4: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    // 0x808007D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007DC: jal         0x800A2CE8
    // 0x808007E0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2CE8(rdram, ctx);
        goto after_1;
    // 0x808007E0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x808007E4: lui         $a1, 0x3F78
    ctx->r5 = S32(0X3F78 << 16);
    // 0x808007E8: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    // 0x808007EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F0: jal         0x800A2CE8
    // 0x808007F4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_2;
    // 0x808007F4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x808007F8: jal         0x80800114
    // 0x808007FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800114_bsbwhirl(rdram, ctx);
        goto after_3;
    // 0x808007FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800800: jal         0x8009EF10
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_4;
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800808: bne         $v0, $zero, L_80800824
    if (ctx->r2 != 0) {
        // 0x8080080C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800824;
    }
    // 0x8080080C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800810: jal         0x8009BCD4
    // 0x80800814: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_5;
    // 0x80800814: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_5:
    // 0x80800818: beq         $v0, $zero, L_80800824
    if (ctx->r2 == 0) {
        // 0x8080081C: addiu       $t6, $zero, 0x1B
        ctx->r14 = ADD32(0, 0X1B);
            goto L_80800824;
    }
    // 0x8080081C: addiu       $t6, $zero, 0x1B
    ctx->r14 = ADD32(0, 0X1B);
    // 0x80800820: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800824:
    // 0x80800824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800828: jal         0x80091A30
    // 0x8080082C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_released(rdram, ctx);
        goto after_6;
    // 0x8080082C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800830: beq         $v0, $zero, L_80800840
    if (ctx->r2 == 0) {
        // 0x80800834: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800840;
    }
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800838: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x8080083C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80800840:
    // 0x80800840: jal         0x80091A58
    // 0x80800844: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_7;
    // 0x80800844: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_7:
    // 0x80800848: beq         $v0, $zero, L_80800864
    if (ctx->r2 == 0) {
        // 0x8080084C: nop
    
            goto L_80800864;
    }
    // 0x8080084C: nop

    // 0x80800850: jal         0x8008E078
    // 0x80800854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_8;
    // 0x80800854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800858: beq         $v0, $zero, L_80800864
    if (ctx->r2 == 0) {
        // 0x8080085C: addiu       $t8, $zero, 0x1D
        ctx->r24 = ADD32(0, 0X1D);
            goto L_80800864;
    }
    // 0x8080085C: addiu       $t8, $zero, 0x1D
    ctx->r24 = ADD32(0, 0X1D);
    // 0x80800860: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80800864:
    // 0x80800864: jal         0x8008E35C
    // 0x80800868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_9;
    // 0x80800868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080086C: beq         $v0, $zero, L_8080087C
    if (ctx->r2 == 0) {
        // 0x80800870: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080087C;
    }
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800874: addiu       $t9, $zero, 0x4C
    ctx->r25 = ADD32(0, 0X4C);
    // 0x80800878: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_8080087C:
    // 0x8080087C: jal         0x80800430
    // 0x80800880: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80800430_bsbwhirl(rdram, ctx);
        goto after_10;
    // 0x80800880: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_10:
    // 0x80800884: jal         0x80800008
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800008_bsbwhirl(rdram, ctx);
        goto after_11;
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080088C: jal         0x8008E148
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_12;
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800894: beql        $v0, $zero, L_808008AC
    if (ctx->r2 == 0) {
        // 0x80800898: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008AC;
    }
    goto skip_0;
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080089C: jal         0x800848B0
    // 0x808008A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_13;
    // 0x808008A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808008A4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808008A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808008AC:
    // 0x808008AC: jal         0x8009E5C8
    // 0x808008B0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_14;
    // 0x808008B0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_14:
    // 0x808008B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808008B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808008BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808008C0: jr          $ra
    // 0x808008C4: nop

    return;
    // 0x808008C4: nop

;}
RECOMP_FUNC void bsclimb_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800500: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800504: jal         0x808001D0
    // 0x80800508: nop

    func_808001D0_bsclimb(rdram, ctx);
        goto after_0;
    // 0x80800508: nop

    after_0:
    // 0x8080050C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800510: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800514: jr          $ra
    // 0x80800518: nop

    return;
    // 0x80800518: nop

;}
