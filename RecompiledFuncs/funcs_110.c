#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800000_bsdronevanish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800008: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: beq         $a1, $at, L_8080003C
    if (ctx->r5 == ctx->r1) {
        // 0x80800018: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8080003C;
    }
    // 0x80800018: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080001C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800020: beq         $a1, $at, L_80800058
    if (ctx->r5 == ctx->r1) {
        // 0x80800024: addiu       $a0, $zero, 0x1C
        ctx->r4 = ADD32(0, 0X1C);
            goto L_80800058;
    }
    // 0x80800024: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80800028: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080002C: beq         $a1, $at, L_80800084
    if (ctx->r5 == ctx->r1) {
        // 0x80800030: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800084;
    }
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800034: b           L_808000B0
    // 0x80800038: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
        goto L_808000B0;
    // 0x80800038: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_8080003C:
    // 0x8080003C: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80800040: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800048: jal         0x80085338
    // 0x8080004C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_0;
    // 0x8080004C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800050: b           L_808000B0
    // 0x80800054: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
        goto L_808000B0;
    // 0x80800054: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80800058:
    // 0x80800058: jal         0x800FC618
    // 0x8080005C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800FC618(rdram, ctx);
        goto after_1;
    // 0x8080005C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x80800060: jal         0x800FCA90
    // 0x80800064: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800FCA90(rdram, ctx);
        goto after_2;
    // 0x80800064: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_2:
    // 0x80800068: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x8080006C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800074: jal         0x80085338
    // 0x80800078: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_3;
    // 0x80800078: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8080007C: b           L_808000B0
    // 0x80800080: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
        goto L_808000B0;
    // 0x80800080: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80800084:
    // 0x80800084: jal         0x80093370
    // 0x80800088: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80093370(rdram, ctx);
        goto after_4;
    // 0x80800088: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8080008C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80800090: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800094: jal         0x800FCAE0
    // 0x80800098: addiu       $a2, $zero, 0x7D0
    ctx->r6 = ADD32(0, 0X7D0);
    func_800FCAE0(rdram, ctx);
        goto after_5;
    // 0x80800098: addiu       $a2, $zero, 0x7D0
    ctx->r6 = ADD32(0, 0X7D0);
    after_5:
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000A4: jal         0x80085338
    // 0x808000A8: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    _batimer_set(rdram, ctx);
        goto after_6;
    // 0x808000A8: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_6:
    // 0x808000AC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_808000B0:
    // 0x808000B0: lw          $t8, 0x188($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X188);
    // 0x808000B4: sb          $t7, 0x18($t8)
    MEM_B(0X18, ctx->r24) = ctx->r15;
    // 0x808000B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000C4: jr          $ra
    // 0x808000C8: nop

    return;
    // 0x808000C8: nop

;}
RECOMP_FUNC void func_800FC6B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC6B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FC6B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FC6B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FC6BC: jal         0x800FB5F8
    // 0x800FC6C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800FB5F8(rdram, ctx);
        goto after_0;
    // 0x800FC6C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800FC6C4: beq         $v0, $zero, L_800FC738
    if (ctx->r2 == 0) {
        // 0x800FC6C8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800FC738;
    }
    // 0x800FC6C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800FC6CC: lh          $t6, 0x28($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X28);
    // 0x800FC6D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FC6D4: bgez        $t6, L_800FC730
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800FC6D8: nop
    
            goto L_800FC730;
    }
    // 0x800FC6D8: nop

    // 0x800FC6DC: jal         0x800FB6E0
    // 0x800FC6E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800FB6E0(rdram, ctx);
        goto after_1;
    // 0x800FC6E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800FC6E4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800FC6E8: addiu       $t7, $t7, 0x57D0
    ctx->r15 = ADD32(ctx->r15, 0X57D0);
    // 0x800FC6EC: subu        $a0, $s0, $t7
    ctx->r4 = SUB32(ctx->r16, ctx->r15);
    // 0x800FC6F0: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x800FC6F4: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x800FC6F8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800FC6FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800FC700: mflo        $t8
    ctx->r24 = lo;
    // 0x800FC704: sh          $zero, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = 0;
    // 0x800FC708: andi        $a0, $t8, 0xFF
    ctx->r4 = ctx->r24 & 0XFF;
    // 0x800FC70C: sh          $a1, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r5;
    // 0x800FC710: jal         0x800172D4
    // 0x800FC714: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    func_800172D4(rdram, ctx);
        goto after_2;
    // 0x800FC714: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x800FC718: jal         0x80017764
    // 0x800FC71C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80017764(rdram, ctx);
        goto after_3;
    // 0x800FC71C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x800FC720: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800FC724: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x800FC728: jal         0x800FB6C0
    // 0x800FC72C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FB6C0(rdram, ctx);
        goto after_4;
    // 0x800FC72C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_800FC730:
    // 0x800FC730: jal         0x800FB540
    // 0x800FC734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FB540(rdram, ctx);
        goto after_5;
    // 0x800FC734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_800FC738:
    // 0x800FC738: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FC73C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FC740: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800FC744: jr          $ra
    // 0x800FC748: nop

    return;
    // 0x800FC748: nop

;}
RECOMP_FUNC void func_8010DD20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010DD20: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8010DD24: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8010DD28: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8010DD2C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8010DD30: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8010DD34: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8010DD38: jal         0x80104148
    // 0x8010DD3C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80104148(rdram, ctx);
        goto after_0;
    // 0x8010DD3C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8010DD40: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8010DD44: jal         0x801015D0
    // 0x8010DD48: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_801015D0(rdram, ctx);
        goto after_1;
    // 0x8010DD48: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x8010DD4C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8010DD50: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x8010DD54: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x8010DD58: bgezl       $t9, L_8010DEEC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8010DD5C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8010DEEC;
    }
    goto skip_0;
    // 0x8010DD5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8010DD60: jal         0x80104200
    // 0x8010DD64: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    func_80104200(rdram, ctx);
        goto after_2;
    // 0x8010DD64: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    after_2:
    // 0x8010DD68: beq         $v0, $zero, L_8010DEE0
    if (ctx->r2 == 0) {
        // 0x8010DD6C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8010DEE0;
    }
    // 0x8010DD6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010DD70: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x8010DD74: beql        $t0, $zero, L_8010DEE4
    if (ctx->r8 == 0) {
        // 0x8010DD78: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_8010DEE4;
    }
    goto skip_1;
    // 0x8010DD78: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    skip_1:
    // 0x8010DD7C: lbu         $t1, 0x5($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X5);
    // 0x8010DD80: bnel        $t1, $zero, L_8010DE0C
    if (ctx->r9 != 0) {
        // 0x8010DD84: lw          $t8, 0x44($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X44);
            goto L_8010DE0C;
    }
    goto skip_2;
    // 0x8010DD84: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x8010DD88: jal         0x8008B304
    // 0x8010DD8C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    func_8008B304(rdram, ctx);
        goto after_3;
    // 0x8010DD8C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_3:
    // 0x8010DD90: jal         0x800B27E0
    // 0x8010DD94: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_800B27E0(rdram, ctx);
        goto after_4;
    // 0x8010DD94: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_4:
    // 0x8010DD98: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8010DD9C: jal         0x8008AEDC
    // 0x8010DDA0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_8008AEDC(rdram, ctx);
        goto after_5;
    // 0x8010DDA0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_5:
    // 0x8010DDA4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8010DDA8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8010DDAC: jal         0x8008C200
    // 0x8010DDB0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_8008C200(rdram, ctx);
        goto after_6;
    // 0x8010DDB0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
    // 0x8010DDB4: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8010DDB8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8010DDBC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8010DDC0: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8010DDC4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8010DDC8: lhu         $t4, 0x4744($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X4744);
    // 0x8010DDCC: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x8010DDD0: bnel        $t5, $at, L_8010DE0C
    if (ctx->r13 != ctx->r1) {
        // 0x8010DDD4: lw          $t8, 0x44($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X44);
            goto L_8010DE0C;
    }
    goto skip_3;
    // 0x8010DDD4: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    skip_3:
    // 0x8010DDD8: jal         0x800A7180
    // 0x8010DDDC: nop

    func_800A7180(rdram, ctx);
        goto after_7;
    // 0x8010DDDC: nop

    after_7:
    // 0x8010DDE0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8010DDE4: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8010DDE8: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8010DDEC: addiu       $t7, $t6, 0x40
    ctx->r15 = ADD32(ctx->r14, 0X40);
    // 0x8010DDF0: jal         0x800AE080
    // 0x8010DDF4: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
    func_800AE080(rdram, ctx);
        goto after_8;
    // 0x8010DDF4: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
    after_8:
    // 0x8010DDF8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8010DDFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010DE00: jal         0x800AE598
    // 0x8010DE04: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800AE598(rdram, ctx);
        goto after_9;
    // 0x8010DE04: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_9:
    // 0x8010DE08: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
L_8010DE0C:
    // 0x8010DE0C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8010DE10: addiu       $t0, $t0, 0x4740
    ctx->r8 = ADD32(ctx->r8, 0X4740);
    // 0x8010DE14: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8010DE18: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8010DE1C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8010DE20: jal         0x800AE080
    // 0x8010DE24: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    func_800AE080(rdram, ctx);
        goto after_10;
    // 0x8010DE24: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    after_10:
    // 0x8010DE28: jal         0x800DF72C
    // 0x8010DE2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF72C(rdram, ctx);
        goto after_11;
    // 0x8010DE2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x8010DE30: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8010DE34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8010DE38: lhu         $v0, 0x4($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X4);
    // 0x8010DE3C: andi        $t3, $v0, 0x3
    ctx->r11 = ctx->r2 & 0X3;
    // 0x8010DE40: beq         $t3, $at, L_8010DE58
    if (ctx->r11 == ctx->r1) {
        // 0x8010DE44: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8010DE58;
    }
    // 0x8010DE44: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8010DE48: beq         $t3, $at, L_8010DED8
    if (ctx->r11 == ctx->r1) {
        // 0x8010DE4C: nop
    
            goto L_8010DED8;
    }
    // 0x8010DE4C: nop

    // 0x8010DE50: b           L_8010DEE4
    // 0x8010DE54: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8010DEE4;
    // 0x8010DE54: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8010DE58:
    // 0x8010DE58: lh          $a0, 0x8($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X8);
    // 0x8010DE5C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8010DE60: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8010DE64: bne         $a0, $zero, L_8010DEA0
    if (ctx->r4 != 0) {
        // 0x8010DE68: nop
    
            goto L_8010DEA0;
    }
    // 0x8010DE68: nop

    // 0x8010DE6C: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x8010DE70: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8010DE74: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8010DE78: lhu         $t5, 0x16($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X16);
    // 0x8010DE7C: lhu         $a1, 0x14($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X14);
    // 0x8010DE80: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8010DE84: jal         0x80100D24
    // 0x8010DE88: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_80100D24(rdram, ctx);
        goto after_12;
    // 0x8010DE88: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_12:
    // 0x8010DE8C: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x8010DE90: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8010DE94: lh          $a0, 0x8($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X8);
    // 0x8010DE98: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x8010DE9C: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
L_8010DEA0:
    // 0x8010DEA0: jal         0x80100A74
    // 0x8010DEA4: lbu         $a1, 0x6($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X6);
    func_80100A74(rdram, ctx);
        goto after_13;
    // 0x8010DEA4: lbu         $a1, 0x6($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X6);
    after_13:
    // 0x8010DEA8: jal         0x800DF818
    // 0x8010DEAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF818(rdram, ctx);
        goto after_14;
    // 0x8010DEAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x8010DEB0: lbu         $t8, 0x5($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X5);
    // 0x8010DEB4: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8010DEB8: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8010DEBC: beql        $t8, $zero, L_8010DED0
    if (ctx->r24 == 0) {
        // 0x8010DEC0: lw          $t0, 0xC($s0)
        ctx->r8 = MEM_W(ctx->r16, 0XC);
            goto L_8010DED0;
    }
    goto skip_4;
    // 0x8010DEC0: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    skip_4:
    // 0x8010DEC4: b           L_8010DEE0
    // 0x8010DEC8: sw          $zero, 0x28($t9)
    MEM_W(0X28, ctx->r25) = 0;
        goto L_8010DEE0;
    // 0x8010DEC8: sw          $zero, 0x28($t9)
    MEM_W(0X28, ctx->r25) = 0;
    // 0x8010DECC: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
L_8010DED0:
    // 0x8010DED0: b           L_8010DEE0
    // 0x8010DED4: sw          $t0, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r8;
        goto L_8010DEE0;
    // 0x8010DED4: sw          $t0, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r8;
L_8010DED8:
    // 0x8010DED8: jal         0x800DF714
    // 0x8010DEDC: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    func_800DF714(rdram, ctx);
        goto after_15;
    // 0x8010DEDC: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    after_15:
L_8010DEE0:
    // 0x8010DEE0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8010DEE4:
    // 0x8010DEE4: sb          $t2, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r10;
    // 0x8010DEE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8010DEEC:
    // 0x8010DEEC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8010DEF0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8010DEF4: jr          $ra
    // 0x8010DEF8: nop

    return;
    // 0x8010DEF8: nop

;}
RECOMP_FUNC void func_80800DBC_chquicksandbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DBC: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80800DC0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800DC4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800DC8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800DCC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80800DD0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800DD4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800DD8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800DDC: jal         0x8010C500
    // 0x80800DE0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_8010C500(rdram, ctx);
        goto after_0;
    // 0x80800DE0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x80800DE4: bne         $v0, $zero, L_80800DF4
    if (ctx->r2 != 0) {
        // 0x80800DE8: nop
    
            goto L_80800DF4;
    }
    // 0x80800DE8: nop

    // 0x80800DEC: b           L_80800EFC
    // 0x80800DF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800EFC;
    // 0x80800DF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800DF4:
    // 0x80800DF4: jal         0x800F54E4
    // 0x80800DF8: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800DF8: nop

    after_1:
    // 0x80800DFC: jal         0x800F55D0
    // 0x80800E00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F55D0(rdram, ctx);
        goto after_2;
    // 0x80800E00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800E04: beq         $v0, $zero, L_80800E14
    if (ctx->r2 == 0) {
        // 0x80800E08: nop
    
            goto L_80800E14;
    }
    // 0x80800E08: nop

    // 0x80800E0C: b           L_80800EFC
    // 0x80800E10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800EFC;
    // 0x80800E10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800E14:
    // 0x80800E14: jal         0x800F54E4
    // 0x80800E18: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x80800E18: nop

    after_3:
    // 0x80800E1C: jal         0x800F6E00
    // 0x80800E20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6E00(rdram, ctx);
        goto after_4;
    // 0x80800E20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80800E24: bne         $v0, $zero, L_80800E34
    if (ctx->r2 != 0) {
        // 0x80800E28: nop
    
            goto L_80800E34;
    }
    // 0x80800E28: nop

    // 0x80800E2C: b           L_80800EFC
    // 0x80800E30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800EFC;
    // 0x80800E30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800E34:
    // 0x80800E34: jal         0x800F54E4
    // 0x80800E38: nop

    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x80800E38: nop

    after_5:
    // 0x80800E3C: jal         0x800F6C5C
    // 0x80800E40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6C5C(rdram, ctx);
        goto after_6;
    // 0x80800E40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80800E44: bne         $v0, $zero, L_80800E54
    if (ctx->r2 != 0) {
        // 0x80800E48: addiu       $a0, $zero, 0x1EF
        ctx->r4 = ADD32(0, 0X1EF);
            goto L_80800E54;
    }
    // 0x80800E48: addiu       $a0, $zero, 0x1EF
    ctx->r4 = ADD32(0, 0X1EF);
    // 0x80800E4C: b           L_80800EFC
    // 0x80800E50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800EFC;
    // 0x80800E50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800E54:
    // 0x80800E54: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80800E58: jal         0x80089C40
    // 0x80800E5C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    _subaddiefind_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80800E5C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_7:
    // 0x80800E60: jal         0x800F54E4
    // 0x80800E64: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x80800E64: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    after_8:
    // 0x80800E68: addiu       $s2, $sp, 0xA4
    ctx->r18 = ADD32(ctx->r29, 0XA4);
    // 0x80800E6C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800E70: jal         0x800F5A00
    // 0x80800E74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5A00(rdram, ctx);
        goto after_9;
    // 0x80800E74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x80800E78: blez        $s4, L_80800EEC
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80800E7C: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80800EEC;
    }
    // 0x80800E7C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800E80: addiu       $s0, $sp, 0x54
    ctx->r16 = ADD32(ctx->r29, 0X54);
L_80800E84:
    // 0x80800E84: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80800E88: beql        $s3, $v0, L_80800EE4
    if (ctx->r19 == ctx->r2) {
        // 0x80800E8C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800EE4;
    }
    goto skip_0;
    // 0x80800E8C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80800E90: lw          $t6, 0x70($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X70);
    // 0x80800E94: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x80800E98: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800E9C: srl         $t7, $t6, 25
    ctx->r15 = S32(U32(ctx->r14) >> 25);
    // 0x80800EA0: srl         $t9, $t8, 25
    ctx->r25 = S32(U32(ctx->r24) >> 25);
    // 0x80800EA4: bnel        $t7, $t9, L_80800EE4
    if (ctx->r15 != ctx->r25) {
        // 0x80800EA8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800EE4;
    }
    goto skip_1;
    // 0x80800EA8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x80800EAC: jal         0x800EEB40
    // 0x80800EB0: addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);
    func_800EEB40(rdram, ctx);
        goto after_10;
    // 0x80800EB0: addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);
    after_10:
    // 0x80800EB4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800EB8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800EBC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800EC0: jal         0x800EEB40
    // 0x80800EC4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EEB40(rdram, ctx);
        goto after_11;
    // 0x80800EC4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_11:
    // 0x80800EC8: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80800ECC: nop

    // 0x80800ED0: bc1fl       L_80800EE4
    if (!c1cs) {
        // 0x80800ED4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800EE4;
    }
    goto skip_2;
    // 0x80800ED4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x80800ED8: b           L_80800EFC
    // 0x80800EDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800EFC;
    // 0x80800EDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800EE0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800EE4:
    // 0x80800EE4: bne         $s1, $s4, L_80800E84
    if (ctx->r17 != ctx->r20) {
        // 0x80800EE8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80800E84;
    }
    // 0x80800EE8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80800EEC:
    // 0x80800EEC: jal         0x800D90A4
    // 0x80800EF0: addiu       $a0, $s3, 0x58
    ctx->r4 = ADD32(ctx->r19, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_12;
    // 0x80800EF0: addiu       $a0, $s3, 0x58
    ctx->r4 = ADD32(ctx->r19, 0X58);
    after_12:
    // 0x80800EF4: sltiu       $t0, $v0, 0x1
    ctx->r8 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800EF8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80800EFC:
    // 0x80800EFC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800F00: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800F04: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800F08: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800F0C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800F10: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800F14: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80800F18: jr          $ra
    // 0x80800F1C: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80800F1C: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_80800504_chdiggerbossshell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800504: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800508: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080050C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1492, 0X60C) << 16);
    // 0x80800510: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800514: addiu       $t6, $t6, 0x60C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1492, 0X60C));
    // 0x80800518: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8080051C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800520: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800524: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800528: jal         0x800BBCB8
    // 0x8080052C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x8080052C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x80800530: jal         0x8010A570
    // 0x80800534: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8010A570(rdram, ctx);
        goto after_1;
    // 0x80800534: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800538: jal         0x800FFAB0
    // 0x8080053C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x8080053C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800540: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800544: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800548: jr          $ra
    // 0x8080054C: nop

    return;
    // 0x8080054C: nop

;}
RECOMP_FUNC void func_80808000_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80808004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80808008: jal         0x80100094
    // 0x8080800C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080800C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80808010: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80808014: jal         0x80089D48
    // 0x80808018: lbu         $a0, 0xA6($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XA6);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80808018: lbu         $a0, 0xA6($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XA6);
    after_1:
    // 0x8080801C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80808020: sb          $v0, 0xA6($t6)
    MEM_B(0XA6, ctx->r14) = ctx->r2;
    // 0x80808024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80808028: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080802C: jr          $ra
    // 0x80808030: nop

    return;
    // 0x80808030: nop

;}
RECOMP_FUNC void func_80800554_chstarspinnerctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800554: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800558: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080055C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(960, 0XA50) << 16);
    // 0x80800560: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800564: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800568: addiu       $t6, $t6, 0xA50
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(960, 0XA50));
    // 0x8080056C: addiu       $s0, $a0, 0x4
    ctx->r16 = ADD32(ctx->r4, 0X4);
    // 0x80800570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800574: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800578: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080057C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800580: jal         0x800BBCB8
    // 0x80800584: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80800584: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_0:
    // 0x80800588: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(960, 0XA00) << 16);
    // 0x8080058C: addiu       $t7, $t7, 0xA00
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(960, 0XA00));
    // 0x80800590: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800598: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080059C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808005A0: jal         0x800BBCB8
    // 0x808005A4: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x808005A4: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_1:
    // 0x808005A8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(960, 0XA98) << 16);
    // 0x808005AC: addiu       $a1, $a1, 0xA98
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(960, 0XA98));
    // 0x808005B0: jal         0x800C4AF0
    // 0x808005B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C4AF0(rdram, ctx);
        goto after_2;
    // 0x808005B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808005B8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(960, 0XAA8) << 16);
    // 0x808005BC: addiu       $a1, $a1, 0xAA8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(960, 0XAA8));
    // 0x808005C0: jal         0x800C4AF0
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C4AF0(rdram, ctx);
        goto after_3;
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808005C8: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x808005CC: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808005D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808005D4: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x808005D8: jal         0x800E1610
    // 0x808005DC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_800E1610(rdram, ctx);
        goto after_4;
    // 0x808005DC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x808005E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808005E4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x808005E8: jal         0x80018820
    // 0x808005EC: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    func_80018820(rdram, ctx);
        goto after_5;
    // 0x808005EC: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_5:
    // 0x808005F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808005F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005FC: jr          $ra
    // 0x80800600: nop

    return;
    // 0x80800600: nop

;}
RECOMP_FUNC void _capod_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800856B8: syscall     171
    recomp_syscall_handler(rdram, ctx, 0x800856B8);
    return;
    // 0x800856BC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _badronemem_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800848F8: syscall     123
    recomp_syscall_handler(rdram, ctx, 0x800848F8);
    return;
    // 0x800848FC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8010E7F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E7F4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010E7F8: addiu       $v0, $v0, 0x7060
    ctx->r2 = ADD32(ctx->r2, 0X7060);
    // 0x8010E7FC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8010E800: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x8010E804: jr          $ra
    // 0x8010E808: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    return;
    // 0x8010E808: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x8010E80C: nop

;}
RECOMP_FUNC void func_80801A20_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A20: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80801A24: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80801A28: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80801A2C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801A30: jal         0x80100094
    // 0x80801A34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801A34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801A38: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x80801A3C: jal         0x80106790
    // 0x80801A40: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80801A40: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_1:
    // 0x80801A44: sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    // 0x80801A48: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80801A4C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801A50: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80801A54: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x80801A58: beq         $at, $zero, L_80801F68
    if (ctx->r1 == 0) {
        // 0x80801A5C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80801F68;
    }
    // 0x80801A5C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80801A60: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4B90) << 16);
    // 0x80801A64: addu        $at, $at, $t8
    gpr jr_addend_80801A6C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80801A68: lw          $t8, 0x4B90($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4B90));
    // 0x80801A6C: jr          $t8
    // 0x80801A70: nop

    switch (jr_addend_80801A6C >> 2) {
        case 0: goto L_80801BA4; break;
        case 1: goto L_80801BC4; break;
        case 2: goto L_80801DE4; break;
        case 3: goto L_80801F34; break;
        case 4: goto L_80801A74; break;
        case 5: goto L_80801F4C; break;
        default: switch_error(__func__, 0x80801A6C, 0x80804B90);
    }
    // 0x80801A70: nop

L_80801A74:
    // 0x80801A74: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80801A78: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80801A7C: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801A80: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80801A84: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80801A88: nop

    // 0x80801A8C: bc1fl       L_80801AA8
    if (!c1cs) {
        // 0x80801A90: lbu         $t9, 0x9B($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X9B);
            goto L_80801AA8;
    }
    goto skip_0;
    // 0x80801A90: lbu         $t9, 0x9B($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X9B);
    skip_0:
    // 0x80801A94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801A98: nop

    // 0x80801A9C: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80801AA0: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80801AA4: lbu         $t9, 0x9B($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X9B);
L_80801AA8:
    // 0x80801AA8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80801AAC: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80801AB0: bgez        $t9, L_80801AC4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80801AB4: cvt.s.w     $f0, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80801AC4;
    }
    // 0x80801AB4: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80801AB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801ABC: nop

    // 0x80801AC0: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
L_80801AC4:
    // 0x80801AC4: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80801AC8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801ACC: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80801AD0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80801AD4: nop

    // 0x80801AD8: bc1fl       L_80801B78
    if (!c1cs) {
        // 0x80801ADC: lwc1        $f10, 0x8($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
            goto L_80801B78;
    }
    goto skip_1;
    // 0x80801ADC: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    skip_1:
    // 0x80801AE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801AE4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80801AE8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801AEC: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80801AF0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80801AF4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80801AF8: nop

    // 0x80801AFC: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80801B00: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80801B04: nop

    // 0x80801B08: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80801B0C: beql        $t1, $zero, L_80801B5C
    if (ctx->r9 == 0) {
        // 0x80801B10: mfc1        $t1, $f8
        ctx->r9 = (int32_t)ctx->f8.u32l;
            goto L_80801B5C;
    }
    goto skip_2;
    // 0x80801B10: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    skip_2:
    // 0x80801B14: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801B18: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80801B1C: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80801B20: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80801B24: nop

    // 0x80801B28: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80801B2C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80801B30: nop

    // 0x80801B34: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80801B38: bne         $t1, $zero, L_80801B50
    if (ctx->r9 != 0) {
        // 0x80801B3C: nop
    
            goto L_80801B50;
    }
    // 0x80801B3C: nop

    // 0x80801B40: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x80801B44: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801B48: b           L_80801B68
    // 0x80801B4C: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80801B68;
    // 0x80801B4C: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_80801B50:
    // 0x80801B50: b           L_80801B68
    // 0x80801B54: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80801B68;
    // 0x80801B54: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80801B58: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
L_80801B5C:
    // 0x80801B5C: nop

    // 0x80801B60: bltz        $t1, L_80801B50
    if (SIGNED(ctx->r9) < 0) {
        // 0x80801B64: nop
    
            goto L_80801B50;
    }
    // 0x80801B64: nop

L_80801B68:
    // 0x80801B68: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80801B6C: b           L_80801F68
    // 0x80801B70: sb          $t1, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r9;
        goto L_80801F68;
    // 0x80801B70: sb          $t1, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r9;
    // 0x80801B74: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
L_80801B78:
    // 0x80801B78: c.le.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl <= ctx->f10.fl;
    // 0x80801B7C: nop

    // 0x80801B80: bc1fl       L_80801F6C
    if (!c1cs) {
        // 0x80801B84: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80801F6C;
    }
    goto skip_3;
    // 0x80801B84: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    skip_3:
    // 0x80801B88: lbu         $t2, 0x72($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X72);
    // 0x80801B8C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80801B90: sb          $t5, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r13;
    // 0x80801B94: andi        $t3, $t2, 0xFF03
    ctx->r11 = ctx->r10 & 0XFF03;
    // 0x80801B98: ori         $t4, $t3, 0x4
    ctx->r12 = ctx->r11 | 0X4;
    // 0x80801B9C: b           L_80801F68
    // 0x80801BA0: sb          $t4, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r12;
        goto L_80801F68;
    // 0x80801BA0: sb          $t4, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r12;
L_80801BA4:
    // 0x80801BA4: jal         0x80802CE0
    // 0x80801BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802CE0_chcollballcontrol(rdram, ctx);
        goto after_2;
    // 0x80801BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801BAC: jal         0x80802764
    // 0x80801BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802764_chcollballcontrol(rdram, ctx);
        goto after_3;
    // 0x80801BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801BB4: jal         0x808020B0
    // 0x80801BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808020B0_chcollballcontrol(rdram, ctx);
        goto after_4;
    // 0x80801BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801BBC: b           L_80801F6C
    // 0x80801BC0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
        goto L_80801F6C;
    // 0x80801BC0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_80801BC4:
    // 0x80801BC4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801BC8: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    // 0x80801BCC: jal         0x800EE7F8
    // 0x80801BD0: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80801BD0: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_5:
    // 0x80801BD4: jal         0x80802764
    // 0x80801BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802764_chcollballcontrol(rdram, ctx);
        goto after_6;
    // 0x80801BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801BDC: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x80801BE0: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80801BE4: jal         0x80089AC8
    // 0x80801BE8: lbu         $a1, 0x20($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X20);
    _sukickball_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x80801BE8: lbu         $a1, 0x20($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X20);
    after_7:
    // 0x80801BEC: beq         $v0, $zero, L_80801C74
    if (ctx->r2 == 0) {
        // 0x80801BF0: lw          $t0, 0x84($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X84);
            goto L_80801C74;
    }
    // 0x80801BF0: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x80801BF4: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x80801BF8: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x80801BFC: jal         0x800F5A00
    // 0x80801C00: lbu         $a0, 0x20($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X20);
    func_800F5A00(rdram, ctx);
        goto after_8;
    // 0x80801C00: lbu         $a0, 0x20($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X20);
    after_8:
    // 0x80801C04: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x80801C08: jal         0x800F5F24
    // 0x80801C0C: lbu         $a0, 0x20($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X20);
    func_800F5F24(rdram, ctx);
        goto after_9;
    // 0x80801C0C: lbu         $a0, 0x20($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X20);
    after_9:
    // 0x80801C10: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80801C14: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80801C18: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801C1C: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x80801C20: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80801C24: jal         0x800EFCD8
    // 0x80801C28: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    func_800EFCD8(rdram, ctx);
        goto after_10;
    // 0x80801C28: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    after_10:
    // 0x80801C2C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80801C30: jal         0x800EF04C
    // 0x80801C34: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    func_800EF04C(rdram, ctx);
        goto after_11;
    // 0x80801C34: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    after_11:
    // 0x80801C38: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x80801C3C: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80801C40: jal         0x800F5D70
    // 0x80801C44: lbu         $a0, 0x20($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X20);
    func_800F5D70(rdram, ctx);
        goto after_12;
    // 0x80801C44: lbu         $a0, 0x20($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X20);
    after_12:
    // 0x80801C48: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80801C4C: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80801C50: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80801C54: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80801C58: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x80801C5C: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80801C60: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80801C64: jal         0x800EE7F8
    // 0x80801C68: swc1        $f18, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f18.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_13;
    // 0x80801C68: swc1        $f18, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f18.u32l;
    after_13:
    // 0x80801C6C: b           L_80801CE0
    // 0x80801C70: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
        goto L_80801CE0;
    // 0x80801C70: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
L_80801C74:
    // 0x80801C74: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80801C78: jal         0x80089AD8
    // 0x80801C7C: lbu         $a1, 0x20($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X20);
    _sukickball_entrypoint_8(rdram, ctx);
        goto after_14;
    // 0x80801C7C: lbu         $a1, 0x20($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X20);
    after_14:
    // 0x80801C80: jal         0x80106790
    // 0x80801C84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_15;
    // 0x80801C84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_15:
    // 0x80801C88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801C8C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80801C90: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x80801C94: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80801C98: lw          $a1, 0x48($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X48);
    // 0x80801C9C: jal         0x800EFCD8
    // 0x80801CA0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_800EFCD8(rdram, ctx);
        goto after_16;
    // 0x80801CA0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_16:
    // 0x80801CA4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80801CA8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80801CAC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80801CB0: jal         0x800EF04C
    // 0x80801CB4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_800EF04C(rdram, ctx);
        goto after_17;
    // 0x80801CB4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_17:
    // 0x80801CB8: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x80801CBC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80801CC0: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80801CC4: lwc1        $f8, 0x48($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80801CC8: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    // 0x80801CCC: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80801CD0: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80801CD4: jal         0x800EE7F8
    // 0x80801CD8: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_18;
    // 0x80801CD8: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    after_18:
    // 0x80801CDC: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
L_80801CE0:
    // 0x80801CE0: jal         0x800EFBFC
    // 0x80801CE4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_800EFBFC(rdram, ctx);
        goto after_19;
    // 0x80801CE4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_19:
    // 0x80801CE8: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80801CEC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80801CF0: nop

    // 0x80801CF4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80801CF8: nop

    // 0x80801CFC: bc1f        L_80801D5C
    if (!c1cs) {
        // 0x80801D00: nop
    
            goto L_80801D5C;
    }
    // 0x80801D00: nop

    // 0x80801D04: jal         0x800DC0C0
    // 0x80801D08: nop

    func_800DC0C0(rdram, ctx);
        goto after_20;
    // 0x80801D08: nop

    after_20:
    // 0x80801D0C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4BA8) << 16);
    // 0x80801D10: lwc1        $f10, 0x4BA8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4BA8));
    // 0x80801D14: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1840, 0X4DF4) << 16);
    // 0x80801D18: addiu       $a2, $a2, 0x4DF4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1840, 0X4DF4));
    // 0x80801D1C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80801D20: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80801D24: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80801D28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801D2C: bc1f        L_80801D5C
    if (!c1cs) {
        // 0x80801D30: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_80801D5C;
    }
    // 0x80801D30: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80801D34: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801D38: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801D3C: addiu       $t1, $zero, 0x4B
    ctx->r9 = ADD32(0, 0X4B);
    // 0x80801D40: addiu       $t2, $zero, 0x96
    ctx->r10 = ADD32(0, 0X96);
    // 0x80801D44: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80801D48: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80801D4C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80801D50: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80801D54: jal         0x800B4470
    // 0x80801D58: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800B4470(rdram, ctx);
        goto after_21;
    // 0x80801D58: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_21:
L_80801D5C:
    // 0x80801D5C: jal         0x800D9078
    // 0x80801D60: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    func_800D9078(rdram, ctx);
        goto after_22;
    // 0x80801D60: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    after_22:
    // 0x80801D64: jal         0x80802CE0
    // 0x80801D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802CE0_chcollballcontrol(rdram, ctx);
        goto after_23;
    // 0x80801D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80801D6C: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x80801D70: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80801D74: jal         0x80089AD0
    // 0x80801D78: lbu         $a1, 0x20($t3)
    ctx->r5 = MEM_BU(ctx->r11, 0X20);
    _sukickball_entrypoint_7(rdram, ctx);
        goto after_24;
    // 0x80801D78: lbu         $a1, 0x20($t3)
    ctx->r5 = MEM_BU(ctx->r11, 0X20);
    after_24:
    // 0x80801D7C: beq         $v0, $zero, L_80801DD4
    if (ctx->r2 == 0) {
        // 0x80801D80: lw          $t4, 0x84($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X84);
            goto L_80801DD4;
    }
    // 0x80801D80: lw          $t4, 0x84($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X84);
    // 0x80801D84: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80801D88: jal         0x80089AD8
    // 0x80801D8C: lbu         $a1, 0x20($t4)
    ctx->r5 = MEM_BU(ctx->r12, 0X20);
    _sukickball_entrypoint_8(rdram, ctx);
        goto after_25;
    // 0x80801D8C: lbu         $a1, 0x20($t4)
    ctx->r5 = MEM_BU(ctx->r12, 0X20);
    after_25:
    // 0x80801D90: jal         0x80106790
    // 0x80801D94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_26;
    // 0x80801D94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_26:
    // 0x80801D98: lw          $t5, 0x64($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X64);
    // 0x80801D9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801DA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801DA4: sll         $t6, $t5, 11
    ctx->r14 = S32(ctx->r13 << 11);
    // 0x80801DA8: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x80801DAC: bne         $t7, $at, L_80801DD4
    if (ctx->r15 != ctx->r1) {
        // 0x80801DB0: nop
    
            goto L_80801DD4;
    }
    // 0x80801DB0: nop

    // 0x80801DB4: jal         0x808030D0
    // 0x80801DB8: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    func_808030D0_chcollballcontrol(rdram, ctx);
        goto after_27;
    // 0x80801DB8: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    after_27:
    // 0x80801DBC: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x80801DC0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80801DC4: lbu         $t8, 0x65($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X65);
    // 0x80801DC8: swc1        $f8, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f8.u32l;
    // 0x80801DCC: andi        $t9, $t8, 0xFFEF
    ctx->r25 = ctx->r24 & 0XFFEF;
    // 0x80801DD0: sb          $t9, 0x65($v1)
    MEM_B(0X65, ctx->r3) = ctx->r25;
L_80801DD4:
    // 0x80801DD4: jal         0x808020B0
    // 0x80801DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808020B0_chcollballcontrol(rdram, ctx);
        goto after_28;
    // 0x80801DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80801DDC: b           L_80801F6C
    // 0x80801DE0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
        goto L_80801F6C;
    // 0x80801DE0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_80801DE4:
    // 0x80801DE4: jal         0x80802764
    // 0x80801DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802764_chcollballcontrol(rdram, ctx);
        goto after_29;
    // 0x80801DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80801DEC: jal         0x800D8FF8
    // 0x80801DF0: nop

    func_800D8FF8(rdram, ctx);
        goto after_30;
    // 0x80801DF0: nop

    after_30:
    // 0x80801DF4: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801DF8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801DFC: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80801E00: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80801E04: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80801E08: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80801E0C: jal         0x800EF1B8
    // 0x80801E10: nop

    func_800EF1B8(rdram, ctx);
        goto after_31;
    // 0x80801E10: nop

    after_31:
    // 0x80801E14: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80801E18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801E1C: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801E20: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80801E24: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x80801E28: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80801E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E30: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x80801E34: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x80801E38: srl         $t2, $t1, 22
    ctx->r10 = S32(U32(ctx->r9) >> 22);
    // 0x80801E3C: bne         $t2, $at, L_80801E80
    if (ctx->r10 != ctx->r1) {
        // 0x80801E40: lui         $at, 0x4416
        ctx->r1 = S32(0X4416 << 16);
            goto L_80801E80;
    }
    // 0x80801E40: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80801E44: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801E48: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801E4C: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    // 0x80801E50: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801E54: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80801E58: nop

    // 0x80801E5C: bc1fl       L_80801E84
    if (!c1cs) {
        // 0x80801E60: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80801E84;
    }
    goto skip_4;
    // 0x80801E60: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_4:
    // 0x80801E64: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80801E68: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80801E6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801E70: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80801E74: add.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80801E78: swc1        $f4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f4.u32l;
    // 0x80801E7C: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
L_80801E80:
    // 0x80801E80: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_80801E84:
    // 0x80801E84: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801E88: c.le.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl <= ctx->f10.fl;
    // 0x80801E8C: nop

    // 0x80801E90: bc1f        L_80801EA8
    if (!c1cs) {
        // 0x80801E94: nop
    
            goto L_80801EA8;
    }
    // 0x80801E94: nop

    // 0x80801E98: jal         0x80801764
    // 0x80801E9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801764_chcollballcontrol(rdram, ctx);
        goto after_32;
    // 0x80801E9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_32:
    // 0x80801EA0: jal         0x808021D4
    // 0x80801EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808021D4_chcollballcontrol(rdram, ctx);
        goto after_33;
    // 0x80801EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
L_80801EA8:
    // 0x80801EA8: jal         0x80802CE0
    // 0x80801EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802CE0_chcollballcontrol(rdram, ctx);
        goto after_34;
    // 0x80801EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80801EB0: jal         0x800DC0C0
    // 0x80801EB4: nop

    func_800DC0C0(rdram, ctx);
        goto after_35;
    // 0x80801EB4: nop

    after_35:
    // 0x80801EB8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4BAC) << 16);
    // 0x80801EBC: lwc1        $f4, 0x4BAC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4BAC));
    // 0x80801EC0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80801EC4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80801EC8: nop

    // 0x80801ECC: bc1f        L_80801F24
    if (!c1cs) {
        // 0x80801ED0: nop
    
            goto L_80801F24;
    }
    // 0x80801ED0: nop

    // 0x80801ED4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801ED8: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801EDC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1840, 0X4DF4) << 16);
    // 0x80801EE0: addiu       $a2, $a2, 0x4DF4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1840, 0X4DF4));
    // 0x80801EE4: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x80801EE8: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80801EEC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80801EF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801EF4: bc1f        L_80801F24
    if (!c1cs) {
        // 0x80801EF8: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_80801F24;
    }
    // 0x80801EF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80801EFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801F00: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80801F04: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x80801F08: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x80801F0C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80801F10: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80801F14: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80801F18: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80801F1C: jal         0x800B4470
    // 0x80801F20: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800B4470(rdram, ctx);
        goto after_36;
    // 0x80801F20: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_36:
L_80801F24:
    // 0x80801F24: jal         0x808020B0
    // 0x80801F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808020B0_chcollballcontrol(rdram, ctx);
        goto after_37;
    // 0x80801F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80801F2C: b           L_80801F6C
    // 0x80801F30: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
        goto L_80801F6C;
    // 0x80801F30: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_80801F34:
    // 0x80801F34: jal         0x80802764
    // 0x80801F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802764_chcollballcontrol(rdram, ctx);
        goto after_38;
    // 0x80801F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x80801F3C: jal         0x808020F4
    // 0x80801F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808020F4_chcollballcontrol(rdram, ctx);
        goto after_39;
    // 0x80801F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x80801F44: b           L_80801F6C
    // 0x80801F48: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
        goto L_80801F6C;
    // 0x80801F48: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_80801F4C:
    // 0x80801F4C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80801F50: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801F54: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F5C: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80801F60: jal         0x808020F4
    // 0x80801F64: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    func_808020F4_chcollballcontrol(rdram, ctx);
        goto after_40;
    // 0x80801F64: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    after_40:
L_80801F68:
    // 0x80801F68: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_80801F6C:
    // 0x80801F6C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801F70: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801F74: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x80801F78: nop

    // 0x80801F7C: bc1fl       L_80801FD8
    if (!c1cs) {
        // 0x80801F80: lw          $t5, 0x0($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X0);
            goto L_80801FD8;
    }
    goto skip_5;
    // 0x80801F80: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    skip_5:
    // 0x80801F84: jal         0x800137AC
    // 0x80801F88: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    func_800137AC(rdram, ctx);
        goto after_41;
    // 0x80801F88: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    after_41:
    // 0x80801F8C: jal         0x800137C4
    // 0x80801F90: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    func_800137C4(rdram, ctx);
        goto after_42;
    // 0x80801F90: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    after_42:
    // 0x80801F94: lwc1        $f2, 0x24($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801F98: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80801F9C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80801FA0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801FA4: mul.s       $f14, $f4, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80801FA8: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80801FAC: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80801FB0: mul.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80801FB4: add.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x80801FB8: div.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80801FBC: add.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x80801FC0: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80801FC4: div.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80801FC8: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    // 0x80801FCC: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80801FD0: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
    // 0x80801FD4: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
L_80801FD8:
    // 0x80801FD8: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x80801FDC: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x80801FE0: srl         $t7, $t6, 22
    ctx->r15 = S32(U32(ctx->r14) >> 22);
    // 0x80801FE4: bnel        $t7, $at, L_80802048
    if (ctx->r15 != ctx->r1) {
        // 0x80801FE8: lw          $t2, 0x64($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X64);
            goto L_80802048;
    }
    goto skip_6;
    // 0x80801FE8: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    skip_6:
    // 0x80801FEC: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80801FF0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801FF4: srl         $t8, $v0, 10
    ctx->r24 = S32(U32(ctx->r2) >> 10);
    // 0x80801FF8: beq         $t8, $at, L_80802044
    if (ctx->r24 == ctx->r1) {
        // 0x80801FFC: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80802044;
    }
    // 0x80801FFC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80802000: beql        $t8, $at, L_80802048
    if (ctx->r24 == ctx->r1) {
        // 0x80802004: lw          $t2, 0x64($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X64);
            goto L_80802048;
    }
    goto skip_7;
    // 0x80802004: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    skip_7:
    // 0x80802008: lw          $t9, 0x7C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X7C);
    // 0x8080200C: sll         $t1, $t9, 19
    ctx->r9 = S32(ctx->r25 << 19);
    // 0x80802010: bgezl       $t1, L_80802048
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80802014: lw          $t2, 0x64($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X64);
            goto L_80802048;
    }
    goto skip_8;
    // 0x80802014: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    skip_8:
    // 0x80802018: jal         0x800DC0C0
    // 0x8080201C: nop

    func_800DC0C0(rdram, ctx);
        goto after_43;
    // 0x8080201C: nop

    after_43:
    // 0x80802020: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4BB0) << 16);
    // 0x80802024: lwc1        $f18, 0x4BB0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4BB0));
    // 0x80802028: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x8080202C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80802030: nop

    // 0x80802034: bc1fl       L_80802048
    if (!c1cs) {
        // 0x80802038: lw          $t2, 0x64($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X64);
            goto L_80802048;
    }
    goto skip_9;
    // 0x80802038: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    skip_9:
    // 0x8080203C: jal         0x808022F0
    // 0x80802040: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_808022F0_chcollballcontrol(rdram, ctx);
        goto after_44;
    // 0x80802040: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_44:
L_80802044:
    // 0x80802044: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
L_80802048:
    // 0x80802048: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    // 0x8080204C: sll         $t4, $t2, 12
    ctx->r12 = S32(ctx->r10 << 12);
    // 0x80802050: bgezl       $t4, L_8080206C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80802054: lw          $v0, 0x84($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X84);
            goto L_8080206C;
    }
    goto skip_10;
    // 0x80802054: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    skip_10:
    // 0x80802058: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8080205C: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80802060: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80802064: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x80802068: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
L_8080206C:
    // 0x8080206C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80802070: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80802074: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x80802078: nop

    // 0x8080207C: bc1fl       L_808020A0
    if (!c1cs) {
        // 0x80802080: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_808020A0;
    }
    goto skip_11;
    // 0x80802080: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_11:
    // 0x80802084: jal         0x800D8FF8
    // 0x80802088: nop

    func_800D8FF8(rdram, ctx);
        goto after_45;
    // 0x80802088: nop

    after_45:
    // 0x8080208C: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    // 0x80802090: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80802094: sub.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80802098: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
    // 0x8080209C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_808020A0:
    // 0x808020A0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x808020A4: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x808020A8: jr          $ra
    // 0x808020AC: nop

    return;
    // 0x808020AC: nop

;}
RECOMP_FUNC void func_8080000C_chhillbilly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800018: jal         0x8008A0F8
    // 0x8080001C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    _sucoaster_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x80800020: beql        $v0, $zero, L_80800058
    if (ctx->r2 == 0) {
        // 0x80800024: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800058;
    }
    goto skip_0;
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800028: jal         0x8008A110
    // 0x8080002C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _sucoaster_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x8080002C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800030: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800034: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800038: addiu       $a0, $v0, 0x6
    ctx->r4 = ADD32(ctx->r2, 0X6);
    // 0x8080003C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800040: jal         0x800EE940
    // 0x80800044: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800EE940(rdram, ctx);
        goto after_2;
    // 0x80800044: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_2:
    // 0x80800048: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8080004C: jal         0x800EE940
    // 0x80800050: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800EE940(rdram, ctx);
        goto after_3;
    // 0x80800050: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800058:
    // 0x80800058: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080005C: jr          $ra
    // 0x80800060: nop

    return;
    // 0x80800060: nop

;}
RECOMP_FUNC void func_80800F0C_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800F10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800F14: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800F18: jal         0x80800238
    // 0x80800F1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800238_bsledge(rdram, ctx);
        goto after_0;
    // 0x80800F1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800F20: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x80800F24: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800F30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800F34: jal         0x8009FFD8
    // 0x80800F38: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800F38: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80800F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F40: jal         0x80800488
    // 0x80800F44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800488_bsledge(rdram, ctx);
        goto after_2;
    // 0x80800F44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800F48: sw          $zero, 0x164($s0)
    MEM_W(0X164, ctx->r16) = 0;
    // 0x80800F4C: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    // 0x80800F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F54: jal         0x80800D78
    // 0x80800F58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800D78_bsledge(rdram, ctx);
        goto after_3;
    // 0x80800F58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800F5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800F60: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800F64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800F68: jr          $ra
    // 0x80800F6C: nop

    return;
    // 0x80800F6C: nop

;}
RECOMP_FUNC void _gsattract_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C78: syscall     731
    recomp_syscall_handler(rdram, ctx, 0x80088C78);
    return;
    // 0x80088C7C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800F90F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F90F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F90FC: jr          $ra
    // 0x800F9100: sb          $a0, 0x54F9($at)
    MEM_B(0X54F9, ctx->r1) = ctx->r4;
    return;
    // 0x800F9100: sb          $a0, 0x54F9($at)
    MEM_B(0X54F9, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_80802A0C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802A0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802A10: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80802A14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802A18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802A1C: bne         $a1, $at, L_80802AB8
    if (ctx->r5 != ctx->r1) {
        // 0x80802A20: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80802AB8;
    }
    // 0x80802A20: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80802A24: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80802A28: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802A2C: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x80802A30: beq         $t7, $at, L_80802A48
    if (ctx->r15 == ctx->r1) {
        // 0x80802A34: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80802A48;
    }
    // 0x80802A34: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80802A38: beq         $t7, $at, L_80802A6C
    if (ctx->r15 == ctx->r1) {
        // 0x80802A3C: nop
    
            goto L_80802A6C;
    }
    // 0x80802A3C: nop

    // 0x80802A40: b           L_80802A90
    // 0x80802A44: nop

        goto L_80802A90;
    // 0x80802A44: nop

L_80802A48:
    // 0x80802A48: jal         0x80101080
    // 0x80802A4C: nop

    func_80101080(rdram, ctx);
        goto after_0;
    // 0x80802A4C: nop

    after_0:
    // 0x80802A50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802A54: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80802A58: lh          $a2, 0x20($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X20);
    // 0x80802A5C: jal         0x808030EC
    // 0x80802A60: lh          $a3, 0x22($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X22);
    func_808030EC_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80802A60: lh          $a3, 0x22($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X22);
    after_1:
    // 0x80802A64: b           L_80802AC4
    // 0x80802A68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802AC4;
    // 0x80802A68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802A6C:
    // 0x80802A6C: jal         0x80101080
    // 0x80802A70: nop

    func_80101080(rdram, ctx);
        goto after_2;
    // 0x80802A70: nop

    after_2:
    // 0x80802A74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802A78: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80802A7C: lh          $a2, 0x20($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X20);
    // 0x80802A80: jal         0x808034BC
    // 0x80802A84: lh          $a3, 0x22($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X22);
    func_808034BC_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80802A84: lh          $a3, 0x22($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X22);
    after_3:
    // 0x80802A88: b           L_80802AC4
    // 0x80802A8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802AC4;
    // 0x80802A8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802A90:
    // 0x80802A90: jal         0x80101080
    // 0x80802A94: nop

    func_80101080(rdram, ctx);
        goto after_4;
    // 0x80802A94: nop

    after_4:
    // 0x80802A98: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80802A9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80802AA0: lh          $a2, 0x20($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X20);
    // 0x80802AA4: lh          $a3, 0x22($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X22);
    // 0x80802AA8: jal         0x80800AEC
    // 0x80802AAC: lw          $a0, 0x3C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X3C);
    func_80800AEC_chgameselect(rdram, ctx);
        goto after_5;
    // 0x80802AAC: lw          $a0, 0x3C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X3C);
    after_5:
    // 0x80802AB0: b           L_80802AC4
    // 0x80802AB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802AC4;
    // 0x80802AB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802AB8:
    // 0x80802AB8: b           L_80802AC4
    // 0x80802ABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802AC4;
    // 0x80802ABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80802AC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802AC4:
    // 0x80802AC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802AC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802ACC: jr          $ra
    // 0x80802AD0: nop

    return;
    // 0x80802AD0: nop

;}
RECOMP_FUNC void bsswim_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B5C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800B60: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(384, 0XBD4) << 16);
    // 0x80800B64: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800B68: jr          $ra
    // 0x80800B6C: lw          $v0, 0xBD4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(384, 0XBD4));
    return;
    // 0x80800B6C: lw          $v0, 0xBD4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(384, 0XBD4));
;}
RECOMP_FUNC void badrone_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004D4: jal         0x80800348
    // 0x808004D8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80800348_badrone(rdram, ctx);
        goto after_0;
    // 0x808004D8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x808004DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004E4: jr          $ra
    // 0x808004E8: nop

    return;
    // 0x808004E8: nop

;}
RECOMP_FUNC void badata_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D8C: jal         0x80800000
    // 0x80800D90: nop

    func_80800000_badata(rdram, ctx);
        goto after_0;
    // 0x80800D90: nop

    after_0:
    // 0x80800D94: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80800D98: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80800D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DA0: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80800DA4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(473, 0X1568) << 16);
    // 0x80800DA8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800DAC: lh          $v0, 0x1568($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(473, 0X1568));
    // 0x80800DB0: jr          $ra
    // 0x80800DB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800DB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800B99CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B99CC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B99D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B99D4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800B99D8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800B99DC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800B99E0: jal         0x800E7FCC
    // 0x800B99E4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800E7FCC(rdram, ctx);
        goto after_0;
    // 0x800B99E4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x800B99E8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800B99EC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800B99F0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800B99F4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800B99F8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800B99FC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800B9A00: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800B9A04: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800B9A08: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800B9A0C: jal         0x800B9A24
    // 0x800B9A10: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_800B9A24(rdram, ctx);
        goto after_1;
    // 0x800B9A10: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_1:
    // 0x800B9A14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B9A18: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800B9A1C: jr          $ra
    // 0x800B9A20: nop

    return;
    // 0x800B9A20: nop

;}
RECOMP_FUNC void sueggmove_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800314: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800318: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080031C: jal         0x800EE7F8
    // 0x80800320: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800320: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
    // 0x80800324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800328: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080032C: jr          $ra
    // 0x80800330: nop

    return;
    // 0x80800330: nop

;}
RECOMP_FUNC void func_800EBE74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EBE74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EBE78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EBE7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800EBE80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800EBE84: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800EBE88: lw          $t7, 0x10($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X10);
    // 0x800EBE8C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800EBE90: beq         $t8, $zero, L_800EBEA8
    if (ctx->r24 == 0) {
        // 0x800EBE94: nop
    
            goto L_800EBEA8;
    }
    // 0x800EBE94: nop

    // 0x800EBE98: jal         0x800BDC44
    // 0x800EBE9C: nop

    func_800BDC44(rdram, ctx);
        goto after_0;
    // 0x800EBE9C: nop

    after_0:
    // 0x800EBEA0: b           L_800EBEB4
    // 0x800EBEA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_800EBEB4;
    // 0x800EBEA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800EBEA8:
    // 0x800EBEA8: jal         0x800BDBC4
    // 0x800EBEAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800BDBC4(rdram, ctx);
        goto after_1;
    // 0x800EBEAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800EBEB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800EBEB4:
    // 0x800EBEB4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800EBEB8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800EBEBC: jal         0x800EBC0C
    // 0x800EBEC0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_800EBC0C(rdram, ctx);
        goto after_2;
    // 0x800EBEC0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800EBEC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EBEC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EBECC: jr          $ra
    // 0x800EBED0: nop

    return;
    // 0x800EBED0: nop

;}
RECOMP_FUNC void bstrexlarge_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800638: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080063C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(412, 0X1990) << 16);
    // 0x80800640: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800644: jr          $ra
    // 0x80800648: lw          $v0, 0x1990($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(412, 0X1990));
    return;
    // 0x80800648: lw          $v0, 0x1990($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(412, 0X1990));
;}
RECOMP_FUNC void func_8011539C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011539C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801153A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801153A4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801153A8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801153AC: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x801153B0: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x801153B4: swc1        $f14, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f14.u32l;
    // 0x801153B8: lw          $t7, 0x14($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14);
    // 0x801153BC: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801153C0: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x801153C4: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801153C8: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x801153CC: swc1        $f6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f6.u32l;
    // 0x801153D0: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801153D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801153D8: mul.s       $f2, $f8, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x801153DC: nop

    // 0x801153E0: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801153E4: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x801153E8: jal         0x8002DCA0
    // 0x801153EC: add.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f2.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x801153EC: add.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f2.fl;
    after_0:
    // 0x801153F0: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801153F4: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801153F8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x801153FC: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80115400: jal         0x8002DCA0
    // 0x80115404: add.s       $f12, $f16, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f2.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80115404: add.s       $f12, $f16, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f2.fl;
    after_1:
    // 0x80115408: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8011540C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80115410: jal         0x80115428
    // 0x80115414: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80115428(rdram, ctx);
        goto after_2;
    // 0x80115414: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80115418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8011541C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80115420: jr          $ra
    // 0x80115424: nop

    return;
    // 0x80115424: nop

;}
RECOMP_FUNC void func_80029BA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029BA0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80029BA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80029BA8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80029BAC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80029BB0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80029BB4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80029BB8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80029BBC: lbu         $t8, 0x3F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3F);
    // 0x80029BC0: lw          $t7, 0x60($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X60);
    // 0x80029BC4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80029BC8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80029BCC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80029BD0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80029BD4: lbu         $t1, 0x33($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X33);
    // 0x80029BD8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80029BDC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80029BE0: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80029BE4: jal         0x800E9054
    // 0x80029BE8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800E9054(rdram, ctx);
        goto after_0;
    // 0x80029BE8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_0:
    // 0x80029BEC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80029BF0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80029BF4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80029BF8: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80029BFC: bne         $at, $zero, L_80029D34
    if (ctx->r1 != 0) {
        // 0x80029C00: nop
    
            goto L_80029D34;
    }
    // 0x80029C00: nop

L_80029C04:
    // 0x80029C04: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80029C08: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80029C0C: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x80029C10: bgez        $t8, L_80029C20
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80029C14: sra         $t7, $t8, 1
        ctx->r15 = S32(SIGNED(ctx->r24) >> 1);
            goto L_80029C20;
    }
    // 0x80029C14: sra         $t7, $t8, 1
    ctx->r15 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80029C18: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x80029C1C: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_80029C20:
    // 0x80029C20: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80029C24: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80029C28: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80029C2C: jal         0x800E9300
    // 0x80029C30: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    func_800E9300(rdram, ctx);
        goto after_1;
    // 0x80029C30: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_1:
    // 0x80029C34: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80029C38: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80029C3C: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x80029C40: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80029C44: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80029C48: lbu         $t1, 0x37($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X37);
    // 0x80029C4C: lbu         $t3, 0x2($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X2);
    // 0x80029C50: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80029C54: bne         $at, $zero, L_80029CC8
    if (ctx->r1 != 0) {
        // 0x80029C58: nop
    
            goto L_80029CC8;
    }
    // 0x80029C58: nop

    // 0x80029C5C: lbu         $t4, 0x3($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X3);
    // 0x80029C60: slt         $at, $t4, $t1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80029C64: bne         $at, $zero, L_80029CC8
    if (ctx->r1 != 0) {
        // 0x80029C68: nop
    
            goto L_80029CC8;
    }
    // 0x80029C68: nop

    // 0x80029C6C: lbu         $t5, 0x3B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X3B);
    // 0x80029C70: lbu         $t6, 0x0($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X0);
    // 0x80029C74: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80029C78: bne         $at, $zero, L_80029CC8
    if (ctx->r1 != 0) {
        // 0x80029C7C: nop
    
            goto L_80029CC8;
    }
    // 0x80029C7C: nop

    // 0x80029C80: lbu         $t8, 0x1($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X1);
    // 0x80029C84: slt         $at, $t8, $t5
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80029C88: bne         $at, $zero, L_80029CC8
    if (ctx->r1 != 0) {
        // 0x80029C8C: nop
    
            goto L_80029CC8;
    }
    // 0x80029C8C: nop

    // 0x80029C90: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80029C94: lbu         $t1, 0x3F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X3F);
    // 0x80029C98: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80029C9C: lw          $t3, 0x60($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X60);
    // 0x80029CA0: sll         $t4, $t1, 3
    ctx->r12 = S32(ctx->r9 << 3);
    // 0x80029CA4: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x80029CA8: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80029CAC: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80029CB0: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x80029CB4: sb          $t9, 0x34($t6)
    MEM_B(0X34, ctx->r14) = ctx->r25;
    // 0x80029CB8: b           L_80029D44
    // 0x80029CBC: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
        goto L_80029D44;
    // 0x80029CBC: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80029CC0: b           L_80029D20
    // 0x80029CC4: nop

        goto L_80029D20;
    // 0x80029CC4: nop

L_80029CC8:
    // 0x80029CC8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80029CCC: lbu         $t2, 0x37($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X37);
    // 0x80029CD0: lbu         $t8, 0x2($t5)
    ctx->r24 = MEM_BU(ctx->r13, 0X2);
    // 0x80029CD4: slt         $at, $t2, $t8
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80029CD8: bne         $at, $zero, L_80029D04
    if (ctx->r1 != 0) {
        // 0x80029CDC: nop
    
            goto L_80029D04;
    }
    // 0x80029CDC: nop

    // 0x80029CE0: lbu         $t7, 0x3B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X3B);
    // 0x80029CE4: lbu         $t0, 0x0($t5)
    ctx->r8 = MEM_BU(ctx->r13, 0X0);
    // 0x80029CE8: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80029CEC: beq         $at, $zero, L_80029D14
    if (ctx->r1 == 0) {
        // 0x80029CF0: nop
    
            goto L_80029D14;
    }
    // 0x80029CF0: nop

    // 0x80029CF4: lbu         $t1, 0x3($t5)
    ctx->r9 = MEM_BU(ctx->r13, 0X3);
    // 0x80029CF8: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80029CFC: bne         $at, $zero, L_80029D14
    if (ctx->r1 != 0) {
        // 0x80029D00: nop
    
            goto L_80029D14;
    }
    // 0x80029D00: nop

L_80029D04:
    // 0x80029D04: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80029D08: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80029D0C: b           L_80029D20
    // 0x80029D10: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
        goto L_80029D20;
    // 0x80029D10: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
L_80029D14:
    // 0x80029D14: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80029D18: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x80029D1C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_80029D20:
    // 0x80029D20: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80029D24: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80029D28: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80029D2C: beq         $at, $zero, L_80029C04
    if (ctx->r1 == 0) {
        // 0x80029D30: nop
    
            goto L_80029C04;
    }
    // 0x80029D30: nop

L_80029D34:
    // 0x80029D34: b           L_80029D44
    // 0x80029D38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80029D44;
    // 0x80029D38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80029D3C: b           L_80029D44
    // 0x80029D40: nop

        goto L_80029D44;
    // 0x80029D40: nop

L_80029D44:
    // 0x80029D44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80029D48: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80029D4C: jr          $ra
    // 0x80029D50: nop

    return;
    // 0x80029D50: nop

;}
RECOMP_FUNC void _chnests_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085A80: syscall     191
    recomp_syscall_handler(rdram, ctx, 0x80085A80);
    return;
    // 0x80085A84: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80105438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105438: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010543C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105440: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80105444: jal         0x800B3248
    // 0x80105448: lw          $a0, 0x6EC0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EC0);
    freelist_free(rdram, ctx);
        goto after_0;
    // 0x80105448: lw          $a0, 0x6EC0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EC0);
    after_0:
    // 0x8010544C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80105454: jr          $ra
    // 0x80105458: nop

    return;
    // 0x80105458: nop

;}
RECOMP_FUNC void _sukickball_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B00: syscall     802
    recomp_syscall_handler(rdram, ctx, 0x80089B00);
    return;
    // 0x80089B04: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void gztrace_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800838: jr          $ra
    // 0x8080083C: nop

    return;
    // 0x8080083C: nop

;}
RECOMP_FUNC void _subaddieskeleton_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A0E8: syscall     828
    recomp_syscall_handler(rdram, ctx, 0x8008A0E8);
    return;
    // 0x8008A0EC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80801B6C_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801B70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801B74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801B78: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80801B7C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80801B80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801B84: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801B88: beq         $t7, $at, L_80801BC0
    if (ctx->r15 == ctx->r1) {
        // 0x80801B8C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1008, 0X1C3C) << 16);
            goto L_80801BC0;
    }
    // 0x80801B8C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1008, 0X1C3C) << 16);
    // 0x80801B90: lwc1        $f4, 0x1C3C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1008, 0X1C3C));
    // 0x80801B94: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80801B98: jal         0x80102424
    // 0x80801B9C: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80801B9C: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x80801BA0: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x80801BA4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1008, 0X1DFC) << 16);
    // 0x80801BA8: addiu       $a3, $a3, 0x1DFC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1008, 0X1DFC));
    // 0x80801BAC: andi        $t8, $a1, 0x1
    ctx->r24 = ctx->r5 & 0X1;
    // 0x80801BB0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80801BB4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80801BB8: jal         0x8010D930
    // 0x80801BBC: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_8010D930(rdram, ctx);
        goto after_1;
    // 0x80801BBC: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_1:
L_80801BC0:
    // 0x80801BC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801BC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801BC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801BCC: jr          $ra
    // 0x80801BD0: nop

    return;
    // 0x80801BD0: nop

    // 0x80801BD4: nop

    // 0x80801BD8: nop

    // 0x80801BDC: nop

;}
RECOMP_FUNC void sumole_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808017C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808017CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808017D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808017D4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808017D8: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x808017DC: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x808017E0: jal         0x8010114C
    // 0x808017E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_0;
    // 0x808017E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x808017E8: jal         0x80101080
    // 0x808017EC: nop

    func_80101080(rdram, ctx);
        goto after_1;
    // 0x808017EC: nop

    after_1:
    // 0x808017F0: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808017F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808017F8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x808017FC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801800: addiu       $t8, $t7, -0x2
    ctx->r24 = ADD32(ctx->r15, -0X2);
    // 0x80801804: sltiu       $at, $t8, 0x12
    ctx->r1 = ctx->r24 < 0X12 ? 1 : 0;
    // 0x80801808: beq         $at, $zero, L_80801B20
    if (ctx->r1 == 0) {
        // 0x8080180C: swc1        $f4, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
            goto L_80801B20;
    }
    // 0x8080180C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x80801810: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80801814: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3158, 0X24AC) << 16);
    // 0x80801818: addu        $at, $at, $t8
    gpr jr_addend_80801820 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8080181C: lw          $t8, 0x24AC($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3158, 0X24AC));
    // 0x80801820: jr          $t8
    // 0x80801824: nop

    switch (jr_addend_80801820 >> 2) {
        case 0: goto L_808018F0; break;
        case 1: goto L_80801B20; break;
        case 2: goto L_80801940; break;
        case 3: goto L_80801B20; break;
        case 4: goto L_80801954; break;
        case 5: goto L_80801A34; break;
        case 6: goto L_80801B20; break;
        case 7: goto L_80801A20; break;
        case 8: goto L_808019B8; break;
        case 9: goto L_80801B20; break;
        case 10: goto L_80801B20; break;
        case 11: goto L_80801B20; break;
        case 12: goto L_80801B20; break;
        case 13: goto L_8080192C; break;
        case 14: goto L_80801828; break;
        case 15: goto L_808019EC; break;
        case 16: goto L_80801B20; break;
        case 17: goto L_80801968; break;
        default: switch_error(__func__, 0x80801820, 0x808024AC);
    }
    // 0x80801824: nop

L_80801828:
    // 0x80801828: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8080182C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80801830: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80801834: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80801838: nop

    // 0x8080183C: sll         $t0, $v1, 4
    ctx->r8 = S32(ctx->r3 << 4);
    // 0x80801840: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x80801844: lb          $t2, 0xA($t1)
    ctx->r10 = MEM_B(ctx->r9, 0XA);
    // 0x80801848: addu        $t3, $a2, $t0
    ctx->r11 = ADD32(ctx->r6, ctx->r8);
    // 0x8080184C: beql        $t2, $at, L_808018E0
    if (ctx->r10 == ctx->r1) {
        // 0x80801850: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808018E0;
    }
    goto skip_0;
    // 0x80801850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80801854: lb          $a0, 0xA($t3)
    ctx->r4 = MEM_B(ctx->r11, 0XA);
    // 0x80801858: jal         0x800C6E38
    // 0x8080185C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_800C6E38(rdram, ctx);
        goto after_2;
    // 0x8080185C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_2:
    // 0x80801860: bne         $v0, $zero, L_808018DC
    if (ctx->r2 != 0) {
        // 0x80801864: lw          $a2, 0x2C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X2C);
            goto L_808018DC;
    }
    // 0x80801864: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80801868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080186C: jal         0x80800000
    // 0x80801870: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80800000_sumole(rdram, ctx);
        goto after_3;
    // 0x80801870: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_3:
    // 0x80801874: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801878: jal         0x800D035C
    // 0x8080187C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800D035C(rdram, ctx);
        goto after_4;
    // 0x8080187C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_4:
    // 0x80801880: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80801884: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80801888: addiu       $a0, $zero, 0x424
    ctx->r4 = ADD32(0, 0X424);
    // 0x8080188C: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80801890: beq         $at, $zero, L_808018A8
    if (ctx->r1 == 0) {
        // 0x80801894: nop
    
            goto L_808018A8;
    }
    // 0x80801894: nop

    // 0x80801898: jal         0x80800454
    // 0x8080189C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sumole_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x8080189C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808018A0: b           L_80801B24
    // 0x808018A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801B24;
    // 0x808018A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808018A8:
    // 0x808018A8: jal         0x800DA9E4
    // 0x808018AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_6;
    // 0x808018AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808018B0: bne         $v0, $zero, L_808018CC
    if (ctx->r2 != 0) {
        // 0x808018B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808018CC;
    }
    // 0x808018B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018BC: jal         0x80800454
    // 0x808018C0: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    sumole_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x808018C0: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_7:
    // 0x808018C4: b           L_80801B24
    // 0x808018C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801B24;
    // 0x808018C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808018CC:
    // 0x808018CC: jal         0x80800454
    // 0x808018D0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    sumole_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x808018D0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_8:
    // 0x808018D4: b           L_80801B24
    // 0x808018D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801B24;
    // 0x808018D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808018DC:
    // 0x808018DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808018E0:
    // 0x808018E0: jal         0x80800454
    // 0x808018E4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    sumole_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x808018E4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_9:
    // 0x808018E8: b           L_80801B24
    // 0x808018EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801B24;
    // 0x808018EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808018F0:
    // 0x808018F0: jal         0x80090178
    // 0x808018F4: addiu       $a0, $zero, 0x601
    ctx->r4 = ADD32(0, 0X601);
    func_80090178(rdram, ctx);
        goto after_10;
    // 0x808018F4: addiu       $a0, $zero, 0x601
    ctx->r4 = ADD32(0, 0X601);
    after_10:
    // 0x808018F8: beq         $v0, $zero, L_80801910
    if (ctx->r2 == 0) {
        // 0x808018FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801910;
    }
    // 0x808018FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801900: jal         0x80800454
    // 0x80801904: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    sumole_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x80801904: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_11:
    // 0x80801908: b           L_80801B24
    // 0x8080190C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801B24;
    // 0x8080190C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801910:
    // 0x80801910: jal         0x80801568
    // 0x80801914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sumole_entrypoint_11(rdram, ctx);
        goto after_12;
    // 0x80801914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80801918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080191C: jal         0x80800454
    // 0x80801920: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    sumole_entrypoint_2(rdram, ctx);
        goto after_13;
    // 0x80801920: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_13:
    // 0x80801924: b           L_80801B24
    // 0x80801928: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801B24;
    // 0x80801928: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080192C:
    // 0x8080192C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801930: jal         0x80800454
    // 0x80801934: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    sumole_entrypoint_2(rdram, ctx);
        goto after_14;
    // 0x80801934: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_14:
    // 0x80801938: b           L_80801B24
    // 0x8080193C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801B24;
    // 0x8080193C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801940:
    // 0x80801940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801944: jal         0x80800454
    // 0x80801948: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    sumole_entrypoint_2(rdram, ctx);
        goto after_15;
    // 0x80801948: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_15:
    // 0x8080194C: b           L_80801B24
    // 0x80801950: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801B24;
    // 0x80801950: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801954:
    // 0x80801954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801958: jal         0x80800454
    // 0x8080195C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    sumole_entrypoint_2(rdram, ctx);
        goto after_16;
    // 0x8080195C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_16:
    // 0x80801960: b           L_80801B24
    // 0x80801964: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801B24;
    // 0x80801964: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801968:
    // 0x80801968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080196C: jal         0x80800000
    // 0x80801970: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80800000_sumole(rdram, ctx);
        goto after_17;
    // 0x80801970: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_17:
    // 0x80801974: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801978: jal         0x800D035C
    // 0x8080197C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800D035C(rdram, ctx);
        goto after_18;
    // 0x8080197C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_18:
    // 0x80801980: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80801984: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80801988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080198C: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80801990: beq         $at, $zero, L_808019A8
    if (ctx->r1 == 0) {
        // 0x80801994: nop
    
            goto L_808019A8;
    }
    // 0x80801994: nop

    // 0x80801998: jal         0x80800454
    // 0x8080199C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sumole_entrypoint_2(rdram, ctx);
        goto after_19;
    // 0x8080199C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808019A0: b           L_80801B24
    // 0x808019A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801B24;
    // 0x808019A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808019A8:
    // 0x808019A8: jal         0x80800454
    // 0x808019AC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    sumole_entrypoint_2(rdram, ctx);
        goto after_20;
    // 0x808019AC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_20:
    // 0x808019B0: b           L_80801B24
    // 0x808019B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801B24;
    // 0x808019B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808019B8:
    // 0x808019B8: jal         0x80106790
    // 0x808019BC: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_21;
    // 0x808019BC: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_21:
    // 0x808019C0: jal         0x80086928
    // 0x808019C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _chmolehill_entrypoint_3(rdram, ctx);
        goto after_22;
    // 0x808019C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_22:
    // 0x808019C8: bnel        $v0, $zero, L_808019DC
    if (ctx->r2 != 0) {
        // 0x808019CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808019DC;
    }
    goto skip_1;
    // 0x808019CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808019D0: jal         0x800C0850
    // 0x808019D4: nop

    func_800C0850(rdram, ctx);
        goto after_23;
    // 0x808019D4: nop

    after_23:
    // 0x808019D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808019DC:
    // 0x808019DC: jal         0x80800454
    // 0x808019E0: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    sumole_entrypoint_2(rdram, ctx);
        goto after_24;
    // 0x808019E0: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_24:
    // 0x808019E4: b           L_80801B24
    // 0x808019E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801B24;
    // 0x808019E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808019EC:
    // 0x808019EC: jal         0x80106790
    // 0x808019F0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_25;
    // 0x808019F0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_25:
    // 0x808019F4: jal         0x80086928
    // 0x808019F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _chmolehill_entrypoint_3(rdram, ctx);
        goto after_26;
    // 0x808019F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_26:
    // 0x808019FC: bnel        $v0, $zero, L_80801A10
    if (ctx->r2 != 0) {
        // 0x80801A00: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801A10;
    }
    goto skip_2;
    // 0x80801A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80801A04: jal         0x800C0850
    // 0x80801A08: nop

    func_800C0850(rdram, ctx);
        goto after_27;
    // 0x80801A08: nop

    after_27:
    // 0x80801A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801A10:
    // 0x80801A10: jal         0x80800454
    // 0x80801A14: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    sumole_entrypoint_2(rdram, ctx);
        goto after_28;
    // 0x80801A14: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_28:
    // 0x80801A18: b           L_80801B24
    // 0x80801A1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801B24;
    // 0x80801A1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801A20:
    // 0x80801A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A24: jal         0x80800454
    // 0x80801A28: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    sumole_entrypoint_2(rdram, ctx);
        goto after_29;
    // 0x80801A28: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_29:
    // 0x80801A2C: b           L_80801B24
    // 0x80801A30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801B24;
    // 0x80801A30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801A34:
    // 0x80801A34: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80801A38: jal         0x800FC6B0
    // 0x80801A3C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_800FC6B0(rdram, ctx);
        goto after_30;
    // 0x80801A3C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_30:
    // 0x80801A40: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80801A44: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80801A48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80801A4C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80801A50: addiu       $a0, $zero, 0x660
    ctx->r4 = ADD32(0, 0X660);
    // 0x80801A54: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80801A58: nop

    // 0x80801A5C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80801A60: addu        $a1, $a2, $t8
    ctx->r5 = ADD32(ctx->r6, ctx->r24);
    // 0x80801A64: lb          $t9, 0xA($a1)
    ctx->r25 = MEM_B(ctx->r5, 0XA);
    // 0x80801A68: beq         $t9, $at, L_80801ABC
    if (ctx->r25 == ctx->r1) {
        // 0x80801A6C: nop
    
            goto L_80801ABC;
    }
    // 0x80801A6C: nop

    // 0x80801A70: jal         0x800DA298
    // 0x80801A74: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_800DA298(rdram, ctx);
        goto after_31;
    // 0x80801A74: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_31:
    // 0x80801A78: lwc1        $f18, 0x54($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80801A7C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80801A80: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801A84: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80801A88: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x80801A8C: nop

    // 0x80801A90: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80801A94: addu        $t3, $a2, $t2
    ctx->r11 = ADD32(ctx->r6, ctx->r10);
    // 0x80801A98: jal         0x800C7074
    // 0x80801A9C: lb          $a0, 0xA($t3)
    ctx->r4 = MEM_B(ctx->r11, 0XA);
    func_800C7074(rdram, ctx);
        goto after_32;
    // 0x80801A9C: lb          $a0, 0xA($t3)
    ctx->r4 = MEM_B(ctx->r11, 0XA);
    after_32:
    // 0x80801AA0: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80801AA4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80801AA8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80801AAC: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x80801AB0: nop

    // 0x80801AB4: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x80801AB8: addu        $a1, $a2, $t6
    ctx->r5 = ADD32(ctx->r6, ctx->r14);
L_80801ABC:
    // 0x80801ABC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3158, 0X25B4) << 16);
    // 0x80801AC0: lh          $a0, 0x6($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X6);
    // 0x80801AC4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80801AC8: addiu       $v0, $v0, 0x25B4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3158, 0X25B4));
    // 0x80801ACC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80801AD0:
    // 0x80801AD0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80801AD4: bnel        $t7, $a0, L_80801B04
    if (ctx->r15 != ctx->r4) {
        // 0x80801AD8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80801B04;
    }
    goto skip_3;
    // 0x80801AD8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_3:
    // 0x80801ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AE0: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80801AE4: jal         0x80108B04
    // 0x80801AE8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_80108B04(rdram, ctx);
        goto after_33;
    // 0x80801AE8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_33:
    // 0x80801AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AF0: jal         0x80800454
    // 0x80801AF4: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    sumole_entrypoint_2(rdram, ctx);
        goto after_34;
    // 0x80801AF4: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_34:
    // 0x80801AF8: b           L_80801B0C
    // 0x80801AFC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
        goto L_80801B0C;
    // 0x80801AFC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80801B00: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80801B04:
    // 0x80801B04: bne         $v1, $a1, L_80801AD0
    if (ctx->r3 != ctx->r5) {
        // 0x80801B08: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80801AD0;
    }
    // 0x80801B08: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80801B0C:
    // 0x80801B0C: sltiu       $at, $v1, 0x8
    ctx->r1 = ctx->r3 < 0X8 ? 1 : 0;
    // 0x80801B10: bne         $at, $zero, L_80801B20
    if (ctx->r1 != 0) {
        // 0x80801B14: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801B20;
    }
    // 0x80801B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B18: jal         0x80800454
    // 0x80801B1C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    sumole_entrypoint_2(rdram, ctx);
        goto after_35;
    // 0x80801B1C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_35:
L_80801B20:
    // 0x80801B20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801B24:
    // 0x80801B24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801B28: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801B2C: jr          $ra
    // 0x80801B30: nop

    return;
    // 0x80801B30: nop

;}
RECOMP_FUNC void chglowbo_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808011EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808011F0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x808011F4: jal         0x8008FE94
    // 0x808011F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008FE94(rdram, ctx);
        goto after_0;
    // 0x808011F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x808011FC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80801200: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1628, 0X13A8) << 16);
    // 0x80801204: jal         0x800DC178
    // 0x80801208: lwc1        $f14, 0x13A8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1628, 0X13A8));
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80801208: lwc1        $f14, 0x13A8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1628, 0X13A8));
    after_1:
    // 0x8080120C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80801210: addiu       $a0, $zero, 0x2A0
    ctx->r4 = ADD32(0, 0X2A0);
    // 0x80801214: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80801218: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8080121C: jal         0x80108474
    // 0x80801220: nop

    func_80108474(rdram, ctx);
        goto after_2;
    // 0x80801220: nop

    after_2:
    // 0x80801224: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801228: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080122C: jr          $ra
    // 0x80801230: nop

    return;
    // 0x80801230: nop

;}
RECOMP_FUNC void fxrain_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800210: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800214: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800218: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080021C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800220: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80800224: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80800228: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8080022C: jal         0x800D674C
    // 0x80800230: addiu       $a0, $zero, 0x9EC
    ctx->r4 = ADD32(0, 0X9EC);
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x80800230: addiu       $a0, $zero, 0x9EC
    ctx->r4 = ADD32(0, 0X9EC);
    after_0:
    // 0x80800234: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800238: jal         0x800B28C4
    // 0x8080023C: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    vector_begin(rdram, ctx);
        goto after_1;
    // 0x8080023C: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_1:
    // 0x80800240: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80800244: jal         0x800B296C
    // 0x80800248: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    vector_end(rdram, ctx);
        goto after_2;
    // 0x80800248: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8080024C: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x80800250: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800254: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x80800258: beq         $at, $zero, L_808002A0
    if (ctx->r1 == 0) {
        // 0x8080025C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808002A0;
    }
    // 0x8080025C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800260: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800264: nop

L_80800268:
    // 0x80800268: jal         0x800DF830
    // 0x8080026C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF830(rdram, ctx);
        goto after_3;
    // 0x8080026C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x80800270: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800278: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080027C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800280: jal         0x800DE448
    // 0x80800284: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_800DE448(rdram, ctx);
        goto after_4;
    // 0x80800284: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_4:
    // 0x80800288: jal         0x800DF350
    // 0x8080028C: nop

    func_800DF350(rdram, ctx);
        goto after_5;
    // 0x8080028C: nop

    after_5:
    // 0x80800290: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x80800294: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x80800298: bne         $at, $zero, L_80800268
    if (ctx->r1 != 0) {
        // 0x8080029C: sb          $v0, -0x4($s0)
        MEM_B(-0X4, ctx->r16) = ctx->r2;
            goto L_80800268;
    }
    // 0x8080029C: sb          $v0, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = ctx->r2;
L_808002A0:
    // 0x808002A0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808002A4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808002A8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808002AC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x808002B0: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x808002B4: jr          $ra
    // 0x808002B8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x808002B8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _badust_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800849F8: syscall     125
    recomp_syscall_handler(rdram, ctx, 0x800849F8);
    return;
    // 0x800849FC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800B0D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0D80: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B0D84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B0D88: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B0D8C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B0D90: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800B0D94: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800B0D98: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800B0D9C: lh          $t0, 0x4($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X4);
    // 0x800B0DA0: lh          $t8, 0x2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2);
    // 0x800B0DA4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B0DA8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800B0DAC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800B0DB0: addu        $v1, $t7, $a0
    ctx->r3 = ADD32(ctx->r15, ctx->r4);
    // 0x800B0DB4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800B0DB8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B0DBC: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800B0DC0: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800B0DC4: addu        $s0, $t9, $v1
    ctx->r16 = ADD32(ctx->r25, ctx->r3);
    // 0x800B0DC8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800B0DCC: addu        $v0, $t1, $s0
    ctx->r2 = ADD32(ctx->r9, ctx->r16);
    // 0x800B0DD0: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800B0DD4: beq         $at, $zero, L_800B0DF8
    if (ctx->r1 == 0) {
        // 0x800B0DD8: lw          $s1, 0x5C($sp)
        ctx->r17 = MEM_W(ctx->r29, 0X5C);
            goto L_800B0DF8;
    }
    // 0x800B0DD8: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x800B0DDC: lbu         $t2, 0x8($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X8);
L_800B0DE0:
    // 0x800B0DE0: beq         $a1, $t2, L_800B0DF8
    if (ctx->r5 == ctx->r10) {
        // 0x800B0DE4: nop
    
            goto L_800B0DF8;
    }
    // 0x800B0DE4: nop

    // 0x800B0DE8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800B0DEC: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800B0DF0: bnel        $at, $zero, L_800B0DE0
    if (ctx->r1 != 0) {
        // 0x800B0DF4: lbu         $t2, 0x8($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X8);
            goto L_800B0DE0;
    }
    goto skip_0;
    // 0x800B0DF4: lbu         $t2, 0x8($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X8);
    skip_0:
L_800B0DF8:
    // 0x800B0DF8: bne         $s0, $v0, L_800B0E08
    if (ctx->r16 != ctx->r2) {
        // 0x800B0DFC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800B0E08;
    }
    // 0x800B0DFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800B0E00: b           L_800B0EB8
    // 0x800B0E04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B0EB8;
    // 0x800B0E04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B0E08:
    // 0x800B0E08: jal         0x800EE88C
    // 0x800B0E0C: addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    func_800EE88C(rdram, ctx);
        goto after_0;
    // 0x800B0E0C: addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    after_0:
    // 0x800B0E10: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x800B0E14: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800B0E18: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800B0E1C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800B0E20: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800B0E24: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x800B0E28: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B0E2C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800B0E30: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800B0E34: jal         0x800EFA4C
    // 0x800B0E38: nop

    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x800B0E38: nop

    after_1:
    // 0x800B0E3C: jal         0x80019CD4
    // 0x800B0E40: nop

    func_80019CD4(rdram, ctx);
        goto after_2;
    // 0x800B0E40: nop

    after_2:
    // 0x800B0E44: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800B0E48: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800B0E4C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x800B0E50: jal         0x80019750
    // 0x800B0E54: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    func_80019750(rdram, ctx);
        goto after_3;
    // 0x800B0E54: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    after_3:
    // 0x800B0E58: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800B0E5C: jal         0x80018AD0
    // 0x800B0E60: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    mlMtxGet(rdram, ctx);
        goto after_4;
    // 0x800B0E60: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    after_4:
    // 0x800B0E64: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800B0E68: jal         0x800ADE2C
    // 0x800B0E6C: lb          $a1, 0x9($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X9);
    func_800ADE2C(rdram, ctx);
        goto after_5;
    // 0x800B0E6C: lb          $a1, 0x9($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X9);
    after_5:
    // 0x800B0E70: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800B0E74: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x800B0E78: jal         0x80019AA0
    // 0x800B0E7C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80019AA0(rdram, ctx);
        goto after_6;
    // 0x800B0E7C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x800B0E80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800B0E84: jal         0x80019224
    // 0x800B0E88: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80019224(rdram, ctx);
        goto after_7;
    // 0x800B0E88: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x800B0E8C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800B0E90: jal         0x80019224
    // 0x800B0E94: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80019224(rdram, ctx);
        goto after_8;
    // 0x800B0E94: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_8:
    // 0x800B0E98: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x800B0E9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800B0EA0: beql        $s0, $zero, L_800B0EB8
    if (ctx->r16 == 0) {
        // 0x800B0EA4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800B0EB8;
    }
    goto skip_1;
    // 0x800B0EA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x800B0EA8: jal         0x800EEAD4
    // 0x800B0EAC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800EEAD4(rdram, ctx);
        goto after_9;
    // 0x800B0EAC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_9:
    // 0x800B0EB0: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x800B0EB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B0EB8:
    // 0x800B0EB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B0EBC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B0EC0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B0EC4: jr          $ra
    // 0x800B0EC8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800B0EC8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _bskazstill_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083648: syscall     70
    recomp_syscall_handler(rdram, ctx, 0x80083648);
    return;
    // 0x8008364C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void subaddieaudioquick_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000DC: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x808000E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808000E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000EC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x808000F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000F4: jal         0x80101E14
    // 0x808000F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80101E14(rdram, ctx);
        goto after_0;
    // 0x808000F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808000FC: beq         $v0, $zero, L_80800118
    if (ctx->r2 == 0) {
        // 0x80800100: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800118;
    }
    // 0x80800100: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800104: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800108: jal         0x8080009C
    // 0x8080010C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080010C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800110: b           L_8080011C
    // 0x80800114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080011C;
    // 0x80800114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800118:
    // 0x80800118: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080011C:
    // 0x8080011C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800120: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800124: jr          $ra
    // 0x80800128: nop

    return;
    // 0x80800128: nop

;}
RECOMP_FUNC void _chswitch_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085810: syscall     176
    recomp_syscall_handler(rdram, ctx, 0x80085810);
    return;
    // 0x80085814: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void subaddiedialog_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080012C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800130: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800134: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800138: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8080013C: jal         0x80800000
    // 0x80800140: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_80800000_subaddiedialog(rdram, ctx);
        goto after_0;
    // 0x80800140: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x80800144: bne         $v0, $zero, L_80800154
    if (ctx->r2 != 0) {
        // 0x80800148: nop
    
            goto L_80800154;
    }
    // 0x80800148: nop

    // 0x8080014C: b           L_808001A4
    // 0x80800150: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001A4;
    // 0x80800150: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800154:
    // 0x80800154: jal         0x800F54E4
    // 0x80800158: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800158: nop

    after_1:
    // 0x8080015C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800160: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800164: jal         0x800F4B8C
    // 0x80800168: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_800F4B8C(rdram, ctx);
        goto after_2;
    // 0x80800168: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8080016C: bne         $v0, $zero, L_8080017C
    if (ctx->r2 != 0) {
        // 0x80800170: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080017C;
    }
    // 0x80800170: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800174: b           L_808001A4
    // 0x80800178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001A4;
    // 0x80800178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080017C:
    // 0x8080017C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800180: jal         0x8080110C
    // 0x80800184: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_8080110C_subaddiedialog(rdram, ctx);
        goto after_3;
    // 0x80800184: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800188: bnel        $v0, $zero, L_808001A4
    if (ctx->r2 != 0) {
        // 0x8080018C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808001A4;
    }
    goto skip_0;
    // 0x8080018C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800190: jal         0x8080141C
    // 0x80800194: nop

    func_8080141C_subaddiedialog(rdram, ctx);
        goto after_4;
    // 0x80800194: nop

    after_4:
    // 0x80800198: b           L_808001A8
    // 0x8080019C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808001A8;
    // 0x8080019C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001A4:
    // 0x808001A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001A8:
    // 0x808001A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001AC: jr          $ra
    // 0x808001B0: nop

    return;
    // 0x808001B0: nop

;}
RECOMP_FUNC void func_80115358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115358: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x8011535C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80115360: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80115364: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80115368: nop

    // 0x8011536C: bc1fl       L_80115380
    if (!c1cs) {
        // 0x80115370: lwc1        $f0, 0x10($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
            goto L_80115380;
    }
    goto skip_0;
    // 0x80115370: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    skip_0:
    // 0x80115374: jr          $ra
    // 0x80115378: nop

    return;
    // 0x80115378: nop

    // 0x8011537C: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
L_80115380:
    // 0x80115380: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80115384: nop

    // 0x80115388: bc1f        L_80115394
    if (!c1cs) {
        // 0x8011538C: nop
    
            goto L_80115394;
    }
    // 0x8011538C: nop

    // 0x80115390: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80115394:
    // 0x80115394: jr          $ra
    // 0x80115398: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x80115398: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
;}
RECOMP_FUNC void _baalarm_get_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084418: syscall     110
    recomp_syscall_handler(rdram, ctx, 0x80084418);
    return;
    // 0x8008441C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void subaddiefade_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800320: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800324: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080032C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800330: jal         0x800F2EE0
    // 0x80800334: addiu       $a1, $a3, 0x98
    ctx->r5 = ADD32(ctx->r7, 0X98);
    func_800F2EE0(rdram, ctx);
        goto after_0;
    // 0x80800334: addiu       $a1, $a3, 0x98
    ctx->r5 = ADD32(ctx->r7, 0X98);
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
RECOMP_FUNC void func_800C72E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C72E4: jr          $ra
    // 0x800C72E8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x800C72E8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void chtrashcangame_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808021B0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2384, 0X31FC) << 16);
    // 0x808021B4: jr          $ra
    // 0x808021B8: addiu       $v0, $v0, 0x31FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2384, 0X31FC));
    return;
    // 0x808021B8: addiu       $v0, $v0, 0x31FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2384, 0X31FC));
;}
RECOMP_FUNC void func_808018AC_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018AC: jr          $ra
    // 0x808018B0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808018B0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void batimer_isGreaterThan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800240: lw          $t6, 0x13C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X13C);
    // 0x80800244: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80800248: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8080024C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80800250: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80800254: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800258: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x8080025C: nop

    // 0x80800260: bc1f        L_8080026C
    if (!c1cs) {
        // 0x80800264: nop
    
            goto L_8080026C;
    }
    // 0x80800264: nop

    // 0x80800268: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080026C:
    // 0x8080026C: jr          $ra
    // 0x80800270: nop

    return;
    // 0x80800270: nop

;}
RECOMP_FUNC void func_801063C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801063C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801063C4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801063C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801063CC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801063D0: lw          $a0, 0x6ED0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6ED0);
    // 0x801063D4: jal         0x800B301C
    // 0x801063D8: lh          $a1, 0x90($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X90);
    freelist_at(rdram, ctx);
        goto after_0;
    // 0x801063D8: lh          $a1, 0x90($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X90);
    after_0:
    // 0x801063DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801063E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801063E4: jr          $ra
    // 0x801063E8: nop

    return;
    // 0x801063E8: nop

;}
RECOMP_FUNC void _gcmapDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088108: syscall     672
    recomp_syscall_handler(rdram, ctx, 0x80088108);
    return;
    // 0x8008810C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void ncbapan_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800108: jr          $ra
    // 0x8080010C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080010C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
