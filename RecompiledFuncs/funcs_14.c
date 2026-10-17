#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chminelightswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086CB0: syscall     442
    recomp_syscall_handler(rdram, ctx, 0x80086CB0);
    return;
    // 0x80086CB4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void idwibble_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800750: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800754: jr          $ra
    // 0x80800758: sh          $a1, 0x34($a0)
    MEM_H(0X34, ctx->r4) = ctx->r5;
    return;
    // 0x80800758: sh          $a1, 0x34($a0)
    MEM_H(0X34, ctx->r4) = ctx->r5;
    // 0x8080075C: nop

;}
RECOMP_FUNC void _batimer_isLessThan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085318: syscall     157
    recomp_syscall_handler(rdram, ctx, 0x80085318);
    return;
    // 0x8008531C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void bstnt_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801244: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801248: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(404, 0X255C) << 16);
    // 0x8080124C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801250: jr          $ra
    // 0x80801254: lw          $v0, 0x255C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(404, 0X255C));
    return;
    // 0x80801254: lw          $v0, 0x255C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(404, 0X255C));
;}
RECOMP_FUNC void func_808008E8_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808008EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808008F4: jal         0x80100094
    // 0x808008F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808008F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808008FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800900: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80800904: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800908: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1748, 0X2030) << 16);
    // 0x8080090C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80800910: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800914: addiu       $a2, $a2, 0x2030
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1748, 0X2030));
    // 0x80800918: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    // 0x8080091C: bc1f        L_80800940
    if (!c1cs) {
        // 0x80800920: nop
    
            goto L_80800940;
    }
    // 0x80800920: nop

    // 0x80800924: jal         0x80089D18
    // 0x80800928: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800928: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080092C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80800930: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800934: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800938: b           L_80800958
    // 0x8080093C: swc1        $f8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f8.u32l;
        goto L_80800958;
    // 0x8080093C: swc1        $f8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f8.u32l;
L_80800940:
    // 0x80800940: jal         0x800D8FF8
    // 0x80800944: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80800944: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80800948: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080094C: lwc1        $f10, 0x24($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80800950: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80800954: swc1        $f16, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f16.u32l;
L_80800958:
    // 0x80800958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080095C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800960: jr          $ra
    // 0x80800964: nop

    return;
    // 0x80800964: nop

;}
RECOMP_FUNC void _chbubbleelevator_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087648: syscall     600
    recomp_syscall_handler(rdram, ctx, 0x80087648);
    return;
    // 0x8008764C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800620_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800620: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800624: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800628: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080062C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800630: jal         0x80100094
    // 0x80800634: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800634: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800638: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080063C: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80800640: andi        $t6, $a0, 0x1FF
    ctx->r14 = ctx->r4 & 0X1FF;
    // 0x80800644: jal         0x800CEAA8
    // 0x80800648: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800CEAA8(rdram, ctx);
        goto after_1;
    // 0x80800648: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x8080064C: beql        $v0, $zero, L_8080066C
    if (ctx->r2 == 0) {
        // 0x80800650: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_8080066C;
    }
    goto skip_0;
    // 0x80800650: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800654: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80800658: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080065C: andi        $t7, $a0, 0x1FF
    ctx->r15 = ctx->r4 & 0X1FF;
    // 0x80800660: jal         0x800CE88C
    // 0x80800664: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800CE88C(rdram, ctx);
        goto after_2;
    // 0x80800664: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_2:
    // 0x80800668: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
L_8080066C:
    // 0x8080066C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800670: addiu       $a1, $a1, 0x4C4
    ctx->r5 = ADD32(ctx->r5, 0X4C4);
    // 0x80800674: jal         0x8008A2B0
    // 0x80800678: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    _susubgame_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800678: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_3:
    // 0x8080067C: beq         $v0, $zero, L_8080068C
    if (ctx->r2 == 0) {
        // 0x80800680: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_8080068C;
    }
    // 0x80800680: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800684: jal         0x8008A2C0
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_8080068C:
    // 0x8080068C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800690: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800694: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800698: jr          $ra
    // 0x8080069C: nop

    return;
    // 0x8080069C: nop

;}
RECOMP_FUNC void func_8009DCCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DCCC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8009DCD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009DCD4: andi        $s0, $a1, 0xFF
    ctx->r16 = ctx->r5 & 0XFF;
    // 0x8009DCD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009DCDC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8009DCE0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8009DCE4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8009DCE8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8009DCEC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8009DCF0: jal         0x8009DAAC
    // 0x8009DCF4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_8009DAAC(rdram, ctx);
        goto after_0;
    // 0x8009DCF4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x8009DCF8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8009DCFC: jal         0x8009C128
    // 0x8009DD00: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x8009DD00: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x8009DD04: jal         0x800C2E40
    // 0x8009DD08: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_800C2E40(rdram, ctx);
        goto after_2;
    // 0x8009DD08: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_2:
    // 0x8009DD0C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x8009DD10: jal         0x800C431C
    // 0x8009DD14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C431C(rdram, ctx);
        goto after_3;
    // 0x8009DD14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8009DD18: jal         0x8009D3D8
    // 0x8009DD1C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8009D3D8(rdram, ctx);
        goto after_4;
    // 0x8009DD1C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x8009DD20: beq         $v0, $zero, L_8009DD3C
    if (ctx->r2 == 0) {
        // 0x8009DD24: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_8009DD3C;
    }
    // 0x8009DD24: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x8009DD28: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x8009DD2C: jal         0x800C3418
    // 0x8009DD30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C3418(rdram, ctx);
        goto after_5;
    // 0x8009DD30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8009DD34: b           L_8009DD48
    // 0x8009DD38: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
        goto L_8009DD48;
    // 0x8009DD38: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_8009DD3C:
    // 0x8009DD3C: jal         0x800C3418
    // 0x8009DD40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C3418(rdram, ctx);
        goto after_6;
    // 0x8009DD40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8009DD44: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_8009DD48:
    // 0x8009DD48: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8009DD4C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x8009DD50: lw          $t7, 0x104($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X104);
    // 0x8009DD54: lbu         $t8, 0x1C($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1C);
    // 0x8009DD58: beq         $t8, $zero, L_8009DD70
    if (ctx->r24 == 0) {
        // 0x8009DD5C: nop
    
            goto L_8009DD70;
    }
    // 0x8009DD5C: nop

    // 0x8009DD60: jal         0x800C35E8
    // 0x8009DD64: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_800C35E8(rdram, ctx);
        goto after_7;
    // 0x8009DD64: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_7:
    // 0x8009DD68: b           L_8009DD7C
    // 0x8009DD6C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
        goto L_8009DD7C;
    // 0x8009DD6C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_8009DD70:
    // 0x8009DD70: jal         0x800C368C
    // 0x8009DD74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C368C(rdram, ctx);
        goto after_8;
    // 0x8009DD74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8009DD78: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_8009DD7C:
    // 0x8009DD7C: jal         0x800C33DC
    // 0x8009DD80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C33DC(rdram, ctx);
        goto after_9;
    // 0x8009DD80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x8009DD84: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x8009DD88: jal         0x800C330C
    // 0x8009DD8C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C330C(rdram, ctx);
        goto after_10;
    // 0x8009DD8C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x8009DD90: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x8009DD94: jal         0x800C301C
    // 0x8009DD98: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800C301C(rdram, ctx);
        goto after_11;
    // 0x8009DD98: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_11:
    // 0x8009DD9C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x8009DDA0: jal         0x800C31DC
    // 0x8009DDA4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800C31DC(rdram, ctx);
        goto after_12;
    // 0x8009DDA4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_12:
    // 0x8009DDA8: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x8009DDAC: jal         0x800C3058
    // 0x8009DDB0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_800C3058(rdram, ctx);
        goto after_13;
    // 0x8009DDB0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_13:
    // 0x8009DDB4: jal         0x800C3BDC
    // 0x8009DDB8: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_800C3BDC(rdram, ctx);
        goto after_14;
    // 0x8009DDB8: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_14:
    // 0x8009DDBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009DDC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009DDC4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8009DDC8: jr          $ra
    // 0x8009DDCC: nop

    return;
    // 0x8009DDCC: nop

;}
RECOMP_FUNC void func_80800AD0_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800ADC: jal         0x800910BC
    // 0x80800AE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800910BC(rdram, ctx);
        goto after_0;
    // 0x80800AE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800AE4: jal         0x80800104
    // 0x80800AE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800104_bsbswim(rdram, ctx);
        goto after_1;
    // 0x80800AE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800AEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800AF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800AF4: jr          $ra
    // 0x80800AF8: nop

    return;
    // 0x80800AF8: nop

;}
RECOMP_FUNC void func_80800040_gzpublic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800044: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800048: jal         0x80014F00
    // 0x8080004C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    func_80014F00(rdram, ctx);
        goto after_0;
    // 0x8080004C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800050: jal         0x80014EC8
    // 0x80800054: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_80014EC8(rdram, ctx);
        goto after_1;
    // 0x80800054: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800058: lui         $a1, 0x1221
    ctx->r5 = S32(0X1221 << 16);
    // 0x8080005C: ori         $a1, $a1, 0x1221
    ctx->r5 = ctx->r5 | 0X1221;
    // 0x80800060: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800064: jal         0x80019E98
    // 0x80800068: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    aligned8_memset(rdram, ctx);
        goto after_2;
    // 0x80800068: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_2:
    // 0x8080006C: jal         0x8001D96C
    // 0x80800070: nop

    func_8001D96C(rdram, ctx);
        goto after_3;
    // 0x80800070: nop

    after_3:
    // 0x80800074: lui         $v0, 0x0
    ctx->r2 = S32(0X0 << 16);
    // 0x80800078: addiu       $v0, $v0, 0x50F0
    ctx->r2 = ADD32(ctx->r2, 0X50F0);
    // 0x8080007C: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    // 0x80800080: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800084: jal         0x8001E210
    // 0x80800088: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    rom_read_word(rdram, ctx);
        goto after_4;
    // 0x80800088: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_4:
    // 0x8080008C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800090: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800094: jal         0x8001E210
    // 0x80800098: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    rom_read_word(rdram, ctx);
        goto after_5;
    // 0x80800098: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_5:
    // 0x8080009C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808000A0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x808000A4: jal         0x8001E210
    // 0x808000A8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    rom_read_word(rdram, ctx);
        goto after_6;
    // 0x808000A8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_6:
    // 0x808000AC: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x808000B0: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x808000B4: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x808000B8: divu        $zero, $v1, $at
    lo = S32(U32(ctx->r3) / U32(ctx->r1)); hi = S32(U32(ctx->r3) % U32(ctx->r1));
    // 0x808000BC: mflo        $a3
    ctx->r7 = lo;
    // 0x808000C0: andi        $t6, $a3, 0xFFFF
    ctx->r14 = ctx->r7 & 0XFFFF;
    // 0x808000C4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x808000C8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x808000CC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x808000D0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x808000D4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808000D8: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x808000DC: subu        $t8, $v1, $t7
    ctx->r24 = SUB32(ctx->r3, ctx->r15);
    // 0x808000E0: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x808000E4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3402, 0X260) << 16);
    // 0x808000E8: addiu       $a2, $a2, 0x260
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3402, 0X260));
    // 0x808000EC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808000F0: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x808000F4: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x808000F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000FC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80800100: jal         0x8001D3D8
    // 0x80800104: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    func_8001D3D8(rdram, ctx);
        goto after_7;
    // 0x80800104: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_7:
    // 0x80800108: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8080010C: jal         0x8008A970
    // 0x80800110: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    _gzthread_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x80800110: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_8:
    // 0x80800114: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3402, 0X280) << 16);
    // 0x80800118: addiu       $a2, $a2, 0x280
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3402, 0X280));
    // 0x8080011C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800120: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800124: jal         0x8001D3D8
    // 0x80800128: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    func_8001D3D8(rdram, ctx);
        goto after_9;
    // 0x80800128: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    after_9:
    // 0x8080012C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800130: jal         0x8001D9CC
    // 0x80800134: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8001D9CC(rdram, ctx);
        goto after_10;
    // 0x80800134: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x80800138: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080013C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800140: jr          $ra
    // 0x80800144: nop

    return;
    // 0x80800144: nop

;}
RECOMP_FUNC void func_80804BB4_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804BB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804BB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80804BBC: slti        $at, $a2, 0x3
    ctx->r1 = SIGNED(ctx->r6) < 0X3 ? 1 : 0;
    // 0x80804BC0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80804BC4: beq         $at, $zero, L_80804BDC
    if (ctx->r1 == 0) {
        // 0x80804BC8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80804BDC;
    }
    // 0x80804BC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804BCC: jal         0x80804D30
    // 0x80804BD0: nop

    func_80804D30_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80804BD0: nop

    after_0:
    // 0x80804BD4: b           L_80804BE8
    // 0x80804BD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80804BE8;
    // 0x80804BD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80804BDC:
    // 0x80804BDC: jal         0x808038EC
    // 0x80804BE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808038EC_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80804BE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80804BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80804BE8:
    // 0x80804BE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804BEC: jr          $ra
    // 0x80804BF0: nop

    return;
    // 0x80804BF0: nop

;}
RECOMP_FUNC void _bstnt_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083F90: syscall     99
    recomp_syscall_handler(rdram, ctx, 0x80083F90);
    return;
    // 0x80083F94: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void mlMtxTranslate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019C84: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80019C88: addiu       $t0, $t0, -0x4350
    ctx->r8 = ADD32(ctx->r8, -0X4350);
    // 0x80019C8C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80019C90: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x80019C94: addiu       $v1, $v0, 0xC
    ctx->r3 = ADD32(ctx->r2, 0XC);
L_80019C98:
    // 0x80019C98: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80019C9C: lwc1        $f2, 0x10($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80019CA0: mul.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80019CA4: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80019CA8: mul.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80019CAC: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80019CB0: mul.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80019CB4: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80019CB8: add.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80019CBC: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80019CC0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80019CC4: bne         $v0, $v1, L_80019C98
    if (ctx->r2 != ctx->r3) {
        // 0x80019CC8: swc1        $f6, 0x2C($v0)
        MEM_W(0X2C, ctx->r2) = ctx->f6.u32l;
            goto L_80019C98;
    }
    // 0x80019CC8: swc1        $f6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f6.u32l;
    // 0x80019CCC: jr          $ra
    // 0x80019CD0: nop

    return;
    // 0x80019CD0: nop

;}
RECOMP_FUNC void func_800D721C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D721C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D7220: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D7224: jal         0x800D6254
    // 0x800D7228: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D6254(rdram, ctx);
        goto after_0;
    // 0x800D7228: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D722C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D7230: beq         $v0, $at, L_800D7248
    if (ctx->r2 == ctx->r1) {
        // 0x800D7234: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800D7248;
    }
    // 0x800D7234: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D7238: jal         0x800D7184
    // 0x800D723C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800D7184(rdram, ctx);
        goto after_1;
    // 0x800D723C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800D7240: b           L_800D724C
    // 0x800D7244: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D724C;
    // 0x800D7244: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D7248:
    // 0x800D7248: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D724C:
    // 0x800D724C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D7250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D7254: jr          $ra
    // 0x800D7258: nop

    return;
    // 0x800D7258: nop

;}
RECOMP_FUNC void baphysics_set_target_horizontal_velocity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_run_target_speed(rdram, ctx);
    // 0x8009B9B0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009B9B4: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x8009B9B8: jr          $ra
    // 0x8009B9BC: swc1        $f12, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x8009B9BC: swc1        $f12, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_8080000C_chtemplebossdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800010: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800018: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800020: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800024: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80800028: addiu       $v0, $t6, -0x32
    ctx->r2 = ADD32(ctx->r14, -0X32);
    // 0x8080002C: beq         $v0, $zero, L_80800048
    if (ctx->r2 == 0) {
        // 0x80800030: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_80800048;
    }
    // 0x80800030: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80800034: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800038: beq         $v0, $at, L_80800054
    if (ctx->r2 == ctx->r1) {
        // 0x8080003C: addiu       $t8, $zero, 0x14
        ctx->r24 = ADD32(0, 0X14);
            goto L_80800054;
    }
    // 0x8080003C: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x80800040: b           L_8080005C
    // 0x80800044: nop

        goto L_8080005C;
    // 0x80800044: nop

L_80800048:
    // 0x80800048: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8080004C: b           L_8080005C
    // 0x80800050: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
        goto L_8080005C;
    // 0x80800050: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_80800054:
    // 0x80800054: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80800058: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8080005C:
    // 0x8080005C: jal         0x800D035C
    // 0x80800060: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_800D035C(rdram, ctx);
        goto after_0;
    // 0x80800060: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_0:
    // 0x80800064: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080006C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800070: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80800074: beq         $at, $zero, L_808000CC
    if (ctx->r1 == 0) {
        // 0x80800078: lui         $a2, 0x42B4
        ctx->r6 = S32(0X42B4 << 16);
            goto L_808000CC;
    }
    // 0x80800078: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x8080007C: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x80800080: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80800084: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80800088: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8080008C: jal         0x80086898
    // 0x80800090: lui         $a3, 0x433E
    ctx->r7 = S32(0X433E << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800090: lui         $a3, 0x433E
    ctx->r7 = S32(0X433E << 16);
    after_1:
    // 0x80800094: beq         $v0, $zero, L_808000D4
    if (ctx->r2 == 0) {
        // 0x80800098: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000D4;
    }
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080009C: jal         0x800868A8
    // 0x808000A0: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x808000A0: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    after_2:
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A8: jal         0x800868C0
    // 0x808000AC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x808000AC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_3:
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000B8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808000BC: jal         0x800868C8
    // 0x808000C0: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    _chdoormake_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x808000C0: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_4:
    // 0x808000C4: b           L_808000D8
    // 0x808000C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808000D8;
    // 0x808000C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000CC:
    // 0x808000CC: jal         0x800FFA88
    // 0x808000D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_5;
    // 0x808000D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_5:
L_808000D4:
    // 0x808000D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000D8:
    // 0x808000D8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000E0: jr          $ra
    // 0x808000E4: nop

    return;
    // 0x808000E4: nop

;}
RECOMP_FUNC void _sueggmove_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A448: syscall     842
    recomp_syscall_handler(rdram, ctx, 0x8008A448);
    return;
    // 0x8008A44C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808039D4_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808039D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808039D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808039DC: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x808039E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808039E4: beq         $a1, $at, L_80803ACC
    if (ctx->r5 == ctx->r1) {
        // 0x808039E8: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80803ACC;
    }
    // 0x808039E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808039EC: addiu       $at, $zero, 0x8C
    ctx->r1 = ADD32(0, 0X8C);
    // 0x808039F0: bne         $a1, $at, L_80803B34
    if (ctx->r5 != ctx->r1) {
        // 0x808039F4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80803B34;
    }
    // 0x808039F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808039F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808039FC: beq         $a2, $at, L_80803ABC
    if (ctx->r6 == ctx->r1) {
        // 0x80803A00: lui         $a0, 0x7FFF
        ctx->r4 = S32(0X7FFF << 16);
            goto L_80803ABC;
    }
    // 0x80803A00: lui         $a0, 0x7FFF
    ctx->r4 = S32(0X7FFF << 16);
    // 0x80803A04: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80803A08: jal         0x800EE7F8
    // 0x80803A0C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80803A0C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x80803A10: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80803A14: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80803A18: jal         0x800EF1B8
    // 0x80803A1C: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x80803A1C: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_1:
    // 0x80803A20: jal         0x800C8A98
    // 0x80803A24: nop

    func_800C8A98(rdram, ctx);
        goto after_2;
    // 0x80803A24: nop

    after_2:
    // 0x80803A28: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x80803A2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803A30: jal         0x800C8F64
    // 0x80803A34: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_800C8F64(rdram, ctx);
        goto after_3;
    // 0x80803A34: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_3:
    // 0x80803A38: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2484, 0X74D0) << 16);
    // 0x80803A3C: addiu       $a1, $a1, 0x74D0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2484, 0X74D0));
    // 0x80803A40: jal         0x800C8E84
    // 0x80803A44: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_800C8E84(rdram, ctx);
        goto after_4;
    // 0x80803A44: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_4:
    // 0x80803A48: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2484, 0X74C8) << 16);
    // 0x80803A4C: addiu       $a1, $a1, 0x74C8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2484, 0X74C8));
    // 0x80803A50: jal         0x800C8D4C
    // 0x80803A54: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_800C8D4C(rdram, ctx);
        goto after_5;
    // 0x80803A54: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_5:
    // 0x80803A58: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80803A5C: jal         0x800C8CB8
    // 0x80803A60: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800C8CB8(rdram, ctx);
        goto after_6;
    // 0x80803A60: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_6:
    // 0x80803A64: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80803A68: jal         0x800C8FE0
    // 0x80803A6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C8FE0(rdram, ctx);
        goto after_7;
    // 0x80803A6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80803A70: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x80803A74: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80803A78: lui         $a0, 0x7FFF
    ctx->r4 = S32(0X7FFF << 16);
    // 0x80803A7C: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80803A80: bnel        $t7, $at, L_80803A94
    if (ctx->r15 != ctx->r1) {
        // 0x80803A84: lui         $at, 0x3FC0
        ctx->r1 = S32(0X3FC0 << 16);
            goto L_80803A94;
    }
    goto skip_0;
    // 0x80803A84: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    skip_0:
    // 0x80803A88: jal         0x800C3F48
    // 0x80803A8C: ori         $a0, $a0, 0xFD3B
    ctx->r4 = ctx->r4 | 0XFD3B;
    func_800C3F48(rdram, ctx);
        goto after_8;
    // 0x80803A8C: ori         $a0, $a0, 0xFD3B
    ctx->r4 = ctx->r4 | 0XFD3B;
    after_8:
    // 0x80803A90: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
L_80803A94:
    // 0x80803A94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803A9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80803AA0: jal         0x80103110
    // 0x80803AA4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_80103110(rdram, ctx);
        goto after_9;
    // 0x80803AA4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_9:
    // 0x80803AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803AAC: jal         0x80101FDC
    // 0x80803AB0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_10;
    // 0x80803AB0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x80803AB4: b           L_80803B34
    // 0x80803AB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803B34;
    // 0x80803AB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803ABC:
    // 0x80803ABC: jal         0x800C3F48
    // 0x80803AC0: ori         $a0, $a0, 0xFD3A
    ctx->r4 = ctx->r4 | 0XFD3A;
    func_800C3F48(rdram, ctx);
        goto after_11;
    // 0x80803AC0: ori         $a0, $a0, 0xFD3A
    ctx->r4 = ctx->r4 | 0XFD3A;
    after_11:
    // 0x80803AC4: b           L_80803B34
    // 0x80803AC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803B34;
    // 0x80803AC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803ACC:
    // 0x80803ACC: jal         0x801015D0
    // 0x80803AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_12;
    // 0x80803AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80803AD4: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80803AD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803ADC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80803AE0: srl         $t8, $v0, 10
    ctx->r24 = S32(U32(ctx->r2) >> 10);
    // 0x80803AE4: beq         $t8, $at, L_80803AFC
    if (ctx->r24 == ctx->r1) {
        // 0x80803AE8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80803AFC;
    }
    // 0x80803AE8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803AEC: beq         $t8, $at, L_80803B18
    if (ctx->r24 == ctx->r1) {
        // 0x80803AF0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80803B18;
    }
    // 0x80803AF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80803AF4: b           L_80803B34
    // 0x80803AF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803B34;
    // 0x80803AF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803AFC:
    // 0x80803AFC: jal         0x800DF744
    // 0x80803B00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_13;
    // 0x80803B00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80803B04: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80803B08: jal         0x800DF744
    // 0x80803B0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_14;
    // 0x80803B0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80803B10: b           L_80803B34
    // 0x80803B14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803B34;
    // 0x80803B14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803B18:
    // 0x80803B18: jal         0x800DF744
    // 0x80803B1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_15;
    // 0x80803B1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x80803B20: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80803B24: jal         0x800DF744
    // 0x80803B28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_16;
    // 0x80803B28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x80803B2C: b           L_80803B34
    // 0x80803B30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803B34;
    // 0x80803B30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803B34:
    // 0x80803B34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803B38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80803B3C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80803B40: jr          $ra
    // 0x80803B44: nop

    return;
    // 0x80803B44: nop

;}
RECOMP_FUNC void _bababykaz_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084480: syscall     112
    recomp_syscall_handler(rdram, ctx, 0x80084480);
    return;
    // 0x80084484: xori        $t0, $zero, 0x8
    ctx->r8 = 0 ^ 0X8;
;}
RECOMP_FUNC void func_808001A8_chmasterjiggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A8: jr          $ra
    // 0x808001AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808001AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80112648(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112648: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8011264C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80112650: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80112654: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80112658: jal         0x80110840
    // 0x8011265C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_80110840(rdram, ctx);
        goto after_0;
    // 0x8011265C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80112660: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80112664: jal         0x800F5CC0
    // 0x80112668: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5CC0(rdram, ctx);
        goto after_1;
    // 0x80112668: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8011266C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80112670: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80112674: jal         0x80013728
    // 0x80112678: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    func_80013728(rdram, ctx);
        goto after_2;
    // 0x80112678: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_2:
    // 0x8011267C: lw          $t6, 0x4C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4C);
    // 0x80112680: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80112684: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80112688: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x8011268C: lw          $v0, 0x4C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4C);
    // 0x80112690: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80112694: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80112698: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8011269C: nop

    // 0x801126A0: bc1fl       L_801126C4
    if (!c1cs) {
        // 0x801126A4: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_801126C4;
    }
    goto skip_0;
    // 0x801126A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_0:
    // 0x801126A8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801126AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801126B0: nop

    // 0x801126B4: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x801126B8: b           L_801126E8
    // 0x801126BC: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
        goto L_801126E8;
    // 0x801126BC: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x801126C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_801126C4:
    // 0x801126C4: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x801126C8: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x801126CC: nop

    // 0x801126D0: bc1f        L_801126E8
    if (!c1cs) {
        // 0x801126D4: nop
    
            goto L_801126E8;
    }
    // 0x801126D4: nop

    // 0x801126D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801126DC: nop

    // 0x801126E0: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x801126E4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
L_801126E8:
    // 0x801126E8: jal         0x800F5CEC
    // 0x801126EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F5CEC(rdram, ctx);
        goto after_3;
    // 0x801126EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801126F0: lw          $t7, 0x4C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4C);
    // 0x801126F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801126F8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x801126FC: jal         0x800F5D70
    // 0x80112700: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    func_800F5D70(rdram, ctx);
        goto after_4;
    // 0x80112700: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    after_4:
    // 0x80112704: jal         0x800EEFFC
    // 0x80112708: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800EEFFC(rdram, ctx);
        goto after_5;
    // 0x80112708: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_5:
    // 0x8011270C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80112710: lwc1        $f6, 0x6580($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6580);
    // 0x80112714: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80112718: nop

    // 0x8011271C: bc1tl       L_80112748
    if (c1cs) {
        // 0x80112720: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_80112748;
    }
    goto skip_1;
    // 0x80112720: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_1:
    // 0x80112724: jal         0x800F5B0C
    // 0x80112728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F5B0C(rdram, ctx);
        goto after_6;
    // 0x80112728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8011272C: bnel        $v0, $zero, L_80112748
    if (ctx->r2 != 0) {
        // 0x80112730: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_80112748;
    }
    goto skip_2;
    // 0x80112730: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_2:
    // 0x80112734: jal         0x801125F4
    // 0x80112738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801125F4(rdram, ctx);
        goto after_7;
    // 0x80112738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8011273C: bnel        $v0, $zero, L_80112754
    if (ctx->r2 != 0) {
        // 0x80112740: lw          $v0, 0x4C($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X4C);
            goto L_80112754;
    }
    goto skip_3;
    // 0x80112740: lw          $v0, 0x4C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4C);
    skip_3:
    // 0x80112744: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_80112748:
    // 0x80112748: lw          $t8, 0x4C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4C);
    // 0x8011274C: swc1        $f8, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f8.u32l;
    // 0x80112750: lw          $v0, 0x4C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4C);
L_80112754:
    // 0x80112754: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80112758: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8011275C: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80112760: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80112764: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80112768: nop

    // 0x8011276C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80112770: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x80112774: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80112778: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8011277C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80112780: jr          $ra
    // 0x80112784: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80112784: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void idscroll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: jr          $ra
    // 0x80800048: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800048: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80802674_gcnewoption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802674: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80802678: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080267C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80802680: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802684: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802688: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8080268C: jal         0x80800038
    // 0x80802690: lh          $a1, 0x6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X6);
    func_80800038_gcnewoption(rdram, ctx);
        goto after_0;
    // 0x80802690: lh          $a1, 0x6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X6);
    after_0:
    // 0x80802694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802698: jal         0x80800000
    // 0x8080269C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800000_gcnewoption(rdram, ctx);
        goto after_1;
    // 0x8080269C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x808026A0: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x808026A4: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x808026A8: lw          $a0, 0x3C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X3C);
    // 0x808026AC: jal         0x80087AF8
    // 0x808026B0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    _gczoombox_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808026B0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_2:
    // 0x808026B4: sltiu       $at, $v0, 0x7
    ctx->r1 = ctx->r2 < 0X7 ? 1 : 0;
    // 0x808026B8: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x808026BC: beq         $at, $zero, L_80802744
    if (ctx->r1 == 0) {
        // 0x808026C0: sw          $v0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r2;
            goto L_80802744;
    }
    // 0x808026C0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808026C4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x808026C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2590, 0X3044) << 16);
    // 0x808026CC: addu        $at, $at, $t9
    gpr jr_addend_808026D4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x808026D0: lw          $t9, 0x3044($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2590, 0X3044));
    // 0x808026D4: jr          $t9
    // 0x808026D8: nop

    switch (jr_addend_808026D4 >> 2) {
        case 0: goto L_808026DC; break;
        case 1: goto L_80802744; break;
        case 2: goto L_80802744; break;
        case 3: goto L_808026DC; break;
        case 4: goto L_8080270C; break;
        case 5: goto L_8080273C; break;
        case 6: goto L_8080273C; break;
        default: switch_error(__func__, 0x808026D4, 0x80803044);
    }
    // 0x808026D8: nop

L_808026DC:
    // 0x808026DC: addu        $a1, $s0, $v1
    ctx->r5 = ADD32(ctx->r16, ctx->r3);
    // 0x808026E0: lb          $t0, 0x94($a1)
    ctx->r8 = MEM_B(ctx->r5, 0X94);
    // 0x808026E4: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x808026E8: addu        $t2, $s0, $t1
    ctx->r10 = ADD32(ctx->r16, ctx->r9);
    // 0x808026EC: beq         $v0, $t0, L_80802704
    if (ctx->r2 == ctx->r8) {
        // 0x808026F0: nop
    
            goto L_80802704;
    }
    // 0x808026F0: nop

    // 0x808026F4: lw          $a0, 0x3C($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X3C);
    // 0x808026F8: jal         0x80087BF0
    // 0x808026FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    _gczoombox_entrypoint_34(rdram, ctx);
        goto after_3;
    // 0x808026FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_3:
    // 0x80802700: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
L_80802704:
    // 0x80802704: b           L_80802748
    // 0x80802708: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
        goto L_80802748;
    // 0x80802708: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_8080270C:
    // 0x8080270C: addu        $a1, $s0, $v1
    ctx->r5 = ADD32(ctx->r16, ctx->r3);
    // 0x80802710: lb          $t3, 0x94($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X94);
    // 0x80802714: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x80802718: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x8080271C: beq         $v0, $t3, L_80802734
    if (ctx->r2 == ctx->r11) {
        // 0x80802720: nop
    
            goto L_80802734;
    }
    // 0x80802720: nop

    // 0x80802724: lw          $a0, 0x3C($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X3C);
    // 0x80802728: jal         0x80087B30
    // 0x8080272C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    _gczoombox_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x8080272C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_4:
    // 0x80802730: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
L_80802734:
    // 0x80802734: b           L_80802748
    // 0x80802738: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
        goto L_80802748;
    // 0x80802738: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_8080273C:
    // 0x8080273C: b           L_80802748
    // 0x80802740: addu        $a1, $s0, $v1
    ctx->r5 = ADD32(ctx->r16, ctx->r3);
        goto L_80802748;
    // 0x80802740: addu        $a1, $s0, $v1
    ctx->r5 = ADD32(ctx->r16, ctx->r3);
L_80802744:
    // 0x80802744: addu        $a1, $s0, $v1
    ctx->r5 = ADD32(ctx->r16, ctx->r3);
L_80802748:
    // 0x80802748: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8080274C: sb          $t6, 0x94($a1)
    MEM_B(0X94, ctx->r5) = ctx->r14;
    // 0x80802750: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80802754: beql        $a0, $zero, L_808027CC
    if (ctx->r4 == 0) {
        // 0x80802758: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808027CC;
    }
    goto skip_0;
    // 0x80802758: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080275C: jal         0x80087AF8
    // 0x80802760: nop

    _gczoombox_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80802760: nop

    after_5:
    // 0x80802764: sltiu       $at, $v0, 0x7
    ctx->r1 = ctx->r2 < 0X7 ? 1 : 0;
    // 0x80802768: beq         $at, $zero, L_808027C0
    if (ctx->r1 == 0) {
        // 0x8080276C: sw          $v0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r2;
            goto L_808027C0;
    }
    // 0x8080276C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80802770: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80802774: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2590, 0X3060) << 16);
    // 0x80802778: addu        $at, $at, $t7
    gpr jr_addend_80802780 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8080277C: lw          $t7, 0x3060($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2590, 0X3060));
    // 0x80802780: jr          $t7
    // 0x80802784: nop

    switch (jr_addend_80802780 >> 2) {
        case 0: goto L_80802788; break;
        case 1: goto L_808027C0; break;
        case 2: goto L_80802788; break;
        case 3: goto L_80802788; break;
        case 4: goto L_808027A8; break;
        case 5: goto L_808027C0; break;
        case 6: goto L_80802788; break;
        default: switch_error(__func__, 0x80802780, 0x80803060);
    }
    // 0x80802784: nop

L_80802788:
    // 0x80802788: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8080278C: lbu         $t8, 0x24($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X24);
    // 0x80802790: beql        $v0, $t8, L_808027C4
    if (ctx->r2 == ctx->r24) {
        // 0x80802794: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_808027C4;
    }
    goto skip_1;
    // 0x80802794: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80802798: jal         0x80087BF0
    // 0x8080279C: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    _gczoombox_entrypoint_34(rdram, ctx);
        goto after_6;
    // 0x8080279C: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_6:
    // 0x808027A0: b           L_808027C4
    // 0x808027A4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
        goto L_808027C4;
    // 0x808027A4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_808027A8:
    // 0x808027A8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x808027AC: lbu         $t9, 0x24($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X24);
    // 0x808027B0: beql        $v0, $t9, L_808027C4
    if (ctx->r2 == ctx->r25) {
        // 0x808027B4: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_808027C4;
    }
    goto skip_2;
    // 0x808027B4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x808027B8: jal         0x80087B30
    // 0x808027BC: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    _gczoombox_entrypoint_10(rdram, ctx);
        goto after_7;
    // 0x808027BC: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_7:
L_808027C0:
    // 0x808027C0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_808027C4:
    // 0x808027C4: sb          $t0, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r8;
    // 0x808027C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808027CC:
    // 0x808027CC: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x808027D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808027D4: jr          $ra
    // 0x808027D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808027D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void bapackctrl_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800150: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800154: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800158: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080015C: lw          $t6, 0xD8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XD8);
    // 0x80800160: sltiu       $at, $a1, 0x6
    ctx->r1 = ctx->r5 < 0X6 ? 1 : 0;
    // 0x80800164: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800168: beq         $at, $zero, L_80800338
    if (ctx->r1 == 0) {
        // 0x8080016C: sb          $a1, 0x1C($t6)
        MEM_B(0X1C, ctx->r14) = ctx->r5;
            goto L_80800338;
    }
    // 0x8080016C: sb          $a1, 0x1C($t6)
    MEM_B(0X1C, ctx->r14) = ctx->r5;
    // 0x80800170: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80800174: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(477, 0X384) << 16);
    // 0x80800178: addu        $at, $at, $t7
    gpr jr_addend_80800180 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8080017C: lw          $t7, 0x384($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(477, 0X384));
    // 0x80800180: jr          $t7
    // 0x80800184: nop

    switch (jr_addend_80800180 >> 2) {
        case 0: goto L_80800188; break;
        case 1: goto L_808001A0; break;
        case 2: goto L_808001B8; break;
        case 3: goto L_8080020C; break;
        case 4: goto L_80800284; break;
        case 5: goto L_808002F4; break;
        default: switch_error(__func__, 0x80800180, 0x80800384);
    }
    // 0x80800184: nop

L_80800188:
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080018C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800190: jal         0x80098480
    // 0x80800194: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80098480(rdram, ctx);
        goto after_0;
    // 0x80800194: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800198: b           L_8080033C
    // 0x8080019C: lw          $v0, 0xD8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD8);
        goto L_8080033C;
    // 0x8080019C: lw          $v0, 0xD8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD8);
L_808001A0:
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001A8: jal         0x80098480
    // 0x808001AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80098480(rdram, ctx);
        goto after_1;
    // 0x808001AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x808001B0: b           L_8080033C
    // 0x808001B4: lw          $v0, 0xD8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD8);
        goto L_8080033C;
    // 0x808001B4: lw          $v0, 0xD8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD8);
L_808001B8:
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001C0: jal         0x80098480
    // 0x808001C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80098480(rdram, ctx);
        goto after_2;
    // 0x808001C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x808001C8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808001CC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808001D0: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808001D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001D8: lw          $t8, 0xD8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XD8);
    // 0x808001DC: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x808001E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001E4: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x808001E8: lw          $t9, 0xD8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XD8);
    // 0x808001EC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808001F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001F4: swc1        $f6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f6.u32l;
    // 0x808001F8: lw          $t0, 0xD8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XD8);
    // 0x808001FC: swc1        $f0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f0.u32l;
    // 0x80800200: lw          $t1, 0xD8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XD8);
    // 0x80800204: b           L_80800338
    // 0x80800208: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
        goto L_80800338;
    // 0x80800208: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
L_8080020C:
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800210: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800214: jal         0x80098480
    // 0x80800218: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80098480(rdram, ctx);
        goto after_3;
    // 0x80800218: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8080021C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800220: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800224: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800228: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080022C: lw          $t2, 0xD8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XD8);
    // 0x80800230: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x80800234: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800238: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
    // 0x8080023C: lw          $t3, 0xD8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XD8);
    // 0x80800240: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800244: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800248: swc1        $f16, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f16.u32l;
    // 0x8080024C: lw          $t4, 0xD8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XD8);
    // 0x80800250: lui         $a2, 0xBE4C
    ctx->r6 = S32(0XBE4C << 16);
    // 0x80800254: lui         $a3, 0xBECC
    ctx->r7 = S32(0XBECC << 16);
    // 0x80800258: swc1        $f0, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f0.u32l;
    // 0x8080025C: lw          $t5, 0xD8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XD8);
    // 0x80800260: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800264: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800268: swc1        $f18, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f18.u32l;
    // 0x8080026C: lw          $a0, 0xD8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XD8);
    // 0x80800270: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800274: jal         0x800EFA4C
    // 0x80800278: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x80800278: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_4:
    // 0x8080027C: b           L_8080033C
    // 0x80800280: lw          $v0, 0xD8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD8);
        goto L_8080033C;
    // 0x80800280: lw          $v0, 0xD8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD8);
L_80800284:
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800288: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080028C: jal         0x80098480
    // 0x80800290: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80098480(rdram, ctx);
        goto after_5;
    // 0x80800290: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80800294: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800298: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080029C: lw          $t6, 0xD8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XD8);
    // 0x808002A0: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x808002A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002A8: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x808002AC: lw          $t7, 0xD8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XD8);
    // 0x808002B0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808002B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002B8: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x808002BC: lw          $t8, 0xD8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XD8);
    // 0x808002C0: lui         $a2, 0xBE4C
    ctx->r6 = S32(0XBE4C << 16);
    // 0x808002C4: lui         $a3, 0xBECC
    ctx->r7 = S32(0XBECC << 16);
    // 0x808002C8: swc1        $f0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f0.u32l;
    // 0x808002CC: lw          $t9, 0xD8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XD8);
    // 0x808002D0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808002D4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808002D8: swc1        $f6, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f6.u32l;
    // 0x808002DC: lw          $a0, 0xD8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XD8);
    // 0x808002E0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808002E4: jal         0x800EFA4C
    // 0x808002E8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EFA4C(rdram, ctx);
        goto after_6;
    // 0x808002E8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_6:
    // 0x808002EC: b           L_8080033C
    // 0x808002F0: lw          $v0, 0xD8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD8);
        goto L_8080033C;
    // 0x808002F0: lw          $v0, 0xD8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD8);
L_808002F4:
    // 0x808002F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002FC: jal         0x80098480
    // 0x80800300: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80098480(rdram, ctx);
        goto after_7;
    // 0x80800300: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80800304: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800308: lw          $t0, 0xD8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XD8);
    // 0x8080030C: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
    // 0x80800310: lw          $v0, 0xD8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD8);
    // 0x80800314: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80800318: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x8080031C: lw          $t1, 0xD8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XD8);
    // 0x80800320: swc1        $f0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f0.u32l;
    // 0x80800324: lw          $t2, 0xD8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XD8);
    // 0x80800328: swc1        $f0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f0.u32l;
    // 0x8080032C: lw          $a0, 0xD8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XD8);
    // 0x80800330: jal         0x800EFD24
    // 0x80800334: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EFD24(rdram, ctx);
        goto after_8;
    // 0x80800334: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_8:
L_80800338:
    // 0x80800338: lw          $v0, 0xD8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD8);
L_8080033C:
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800340: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80800344: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800348: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x8080034C: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x80800350: jal         0x80098494
    // 0x80800354: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_80098494(rdram, ctx);
        goto after_9;
    // 0x80800354: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x80800358: lw          $a1, 0xD8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XD8);
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800360: jal         0x800984CC
    // 0x80800364: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_800984CC(rdram, ctx);
        goto after_10;
    // 0x80800364: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_10:
    // 0x80800368: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080036C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800370: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800374: jr          $ra
    // 0x80800378: nop

    return;
    // 0x80800378: nop

    // 0x8080037C: nop

;}
RECOMP_FUNC void func_80801484_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801484: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801488: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080148C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801490: jal         0x8009BD88
    // 0x80801494: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009BD88(rdram, ctx);
        goto after_0;
    // 0x80801494: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801498: jal         0x8008E95C
    // 0x8080149C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E95C(rdram, ctx);
        goto after_1;
    // 0x8080149C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808014A0: jal         0x800951B4
    // 0x808014A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800951B4(rdram, ctx);
        goto after_2;
    // 0x808014A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808014A8: jal         0x80092BE8
    // 0x808014AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092BE8(rdram, ctx);
        goto after_3;
    // 0x808014AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808014B0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808014B4: jal         0x8009C914
    // 0x808014B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_4;
    // 0x808014B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808014BC: jal         0x8009C974
    // 0x808014C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_5;
    // 0x808014C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808014C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014C8: jal         0x800931AC
    // 0x808014CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800931AC(rdram, ctx);
        goto after_6;
    // 0x808014CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808014D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014D4: jal         0x80084DA0
    // 0x808014D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _bakaztorpedo_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x808014D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x808014DC: jal         0x80800508
    // 0x808014E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800508_bskaztorpedo(rdram, ctx);
        goto after_8;
    // 0x808014E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808014E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808014E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808014EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808014F0: jr          $ra
    // 0x808014F4: nop

    return;
    // 0x808014F4: nop

;}
RECOMP_FUNC void func_8080011C_gcgamefix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080011C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800124: jal         0x800DA298
    // 0x80800128: addiu       $a0, $zero, 0x4FC
    ctx->r4 = ADD32(0, 0X4FC);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800128: addiu       $a0, $zero, 0x4FC
    ctx->r4 = ADD32(0, 0X4FC);
    after_0:
    // 0x8080012C: beq         $v0, $zero, L_8080013C
    if (ctx->r2 == 0) {
        // 0x80800130: nop
    
            goto L_8080013C;
    }
    // 0x80800130: nop

    // 0x80800134: jal         0x800DA544
    // 0x80800138: addiu       $a0, $zero, 0x4FD
    ctx->r4 = ADD32(0, 0X4FD);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800138: addiu       $a0, $zero, 0x4FD
    ctx->r4 = ADD32(0, 0X4FD);
    after_1:
L_8080013C:
    // 0x8080013C: jal         0x800DA298
    // 0x80800140: addiu       $a0, $zero, 0x4FF
    ctx->r4 = ADD32(0, 0X4FF);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800140: addiu       $a0, $zero, 0x4FF
    ctx->r4 = ADD32(0, 0X4FF);
    after_2:
    // 0x80800144: beql        $v0, $zero, L_80800158
    if (ctx->r2 == 0) {
        // 0x80800148: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800158;
    }
    goto skip_0;
    // 0x80800148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080014C: jal         0x800DA544
    // 0x80800150: addiu       $a0, $zero, 0x500
    ctx->r4 = ADD32(0, 0X500);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x80800150: addiu       $a0, $zero, 0x500
    ctx->r4 = ADD32(0, 0X500);
    after_3:
    // 0x80800154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800158:
    // 0x80800158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080015C: jr          $ra
    // 0x80800160: nop

    return;
    // 0x80800160: nop

;}
RECOMP_FUNC void func_800E3E8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3E8C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800E3E90: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800E3E94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3E98: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800E3E9C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3EA0: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    // 0x800E3EA4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800E3EA8: jal         0x800CACEC
    // 0x800E3EAC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800CACEC(rdram, ctx);
        goto after_0;
    // 0x800E3EAC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x800E3EB0: jal         0x800BCC58
    // 0x800E3EB4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800BCC58(rdram, ctx);
        goto after_1;
    // 0x800E3EB4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x800E3EB8: beq         $v0, $zero, L_800E3EE8
    if (ctx->r2 == 0) {
        // 0x800E3EBC: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_800E3EE8;
    }
    // 0x800E3EBC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800E3EC0: bne         $v1, $zero, L_800E3EE8
    if (ctx->r3 != 0) {
        // 0x800E3EC4: addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
            goto L_800E3EE8;
    }
    // 0x800E3EC4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800E3EC8: jal         0x800BCC28
    // 0x800E3ECC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800BCC28(rdram, ctx);
        goto after_2;
    // 0x800E3ECC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x800E3ED0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3ED4: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    // 0x800E3ED8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800E3EDC: jal         0x800CACEC
    // 0x800E3EE0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_800CACEC(rdram, ctx);
        goto after_3;
    // 0x800E3EE0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x800E3EE4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800E3EE8:
    tooie_sun_shadow_cull(rdram, ctx);
    // 0x800E3EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E3EEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800E3EF0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800E3EF4: jr          $ra
    // 0x800E3EF8: nop

    return;
    // 0x800E3EF8: nop

;}
RECOMP_FUNC void _gcfrontend_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088170: syscall     673
    recomp_syscall_handler(rdram, ctx, 0x80088170);
    return;
    // 0x80088174: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void cadbfunc_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080053C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800540: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800544: jal         0x808004E0
    // 0x80800548: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808004E0_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x80800548: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080054C: bne         $v0, $zero, L_8080055C
    if (ctx->r2 != 0) {
        // 0x80800550: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8080055C;
    }
    // 0x80800550: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800554: b           L_8080056C
    // 0x80800558: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080056C;
    // 0x80800558: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080055C:
    // 0x8080055C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800560: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800564: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800568: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
L_8080056C:
    // 0x8080056C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800570: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800574: jr          $ra
    // 0x80800578: nop

    return;
    // 0x80800578: nop

;}
RECOMP_FUNC void func_808001C8_sumissilehome(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808001CC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808001D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001D4: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x808001D8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808001DC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808001E0: jal         0x800EEF94
    // 0x808001E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EEF94(rdram, ctx);
        goto after_0;
    // 0x808001E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001E8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x808001EC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x808001F0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808001F4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808001F8: jal         0x800EFB24
    // 0x808001FC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x808001FC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_1:
    // 0x80800200: jal         0x800D8FF8
    // 0x80800204: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80800204: nop

    after_2:
    // 0x80800208: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080020C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800210: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800214: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800218: jal         0x800EF368
    // 0x8080021C: nop

    func_800EF368(rdram, ctx);
        goto after_3;
    // 0x8080021C: nop

    after_3:
    // 0x80800220: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800224: jal         0x800EF04C
    // 0x80800228: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800EF04C(rdram, ctx);
        goto after_4;
    // 0x80800228: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x8080022C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800230: jal         0x800EF368
    // 0x80800234: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800EF368(rdram, ctx);
        goto after_5;
    // 0x80800234: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80800238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080023C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800240: jr          $ra
    // 0x80800244: nop

    return;
    // 0x80800244: nop

;}
RECOMP_FUNC void func_800EC800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC800: lhu         $v0, 0x18($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X18);
    // 0x800EC804: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800EC808: sltu        $v0, $zero, $t6
    ctx->r2 = 0 < ctx->r14 ? 1 : 0;
    // 0x800EC80C: beq         $v0, $zero, L_800EC820
    if (ctx->r2 == 0) {
        // 0x800EC810: nop
    
            goto L_800EC820;
    }
    // 0x800EC810: nop

    // 0x800EC814: lhu         $v0, 0x14($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X14);
    // 0x800EC818: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x800EC81C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800EC820:
    // 0x800EC820: jr          $ra
    // 0x800EC824: nop

    return;
    // 0x800EC824: nop

;}
RECOMP_FUNC void func_80800CB4_chpawnbroker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CB4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800CB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800CBC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800CC0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800CC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800CC8: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80800CCC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800CD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800CD4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800CD8: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x80800CDC: jal         0x800D0B68
    // 0x80800CE0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_800D0B68(rdram, ctx);
        goto after_0;
    // 0x80800CE0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_0:
    // 0x80800CE4: bne         $v0, $zero, L_80800D08
    if (ctx->r2 != 0) {
        // 0x80800CE8: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_80800D08;
    }
    // 0x80800CE8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80800CEC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80800CF0: jal         0x800D0634
    // 0x80800CF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0634(rdram, ctx);
        goto after_1;
    // 0x80800CF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800CF8: jal         0x80106790
    // 0x80800CFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x80800CFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800D00: b           L_80800D2C
    // 0x80800D04: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
        goto L_80800D2C;
    // 0x80800D04: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80800D08:
    // 0x80800D08: jal         0x800D0B68
    // 0x80800D0C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0B68(rdram, ctx);
        goto after_3;
    // 0x80800D0C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x80800D10: bne         $v0, $zero, L_80800D2C
    if (ctx->r2 != 0) {
        // 0x80800D14: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800D2C;
    }
    // 0x80800D14: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800D18: addiu       $a1, $zero, 0x136
    ctx->r5 = ADD32(0, 0X136);
    // 0x80800D1C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80800D20: jal         0x80089C20
    // 0x80800D24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80800D24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80800D28: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80800D2C:
    // 0x80800D2C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800D30: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800D34: jal         0x8010A570
    // 0x80800D38: sw          $t6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r14;
    func_8010A570(rdram, ctx);
        goto after_5;
    // 0x80800D38: sw          $t6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r14;
    after_5:
    // 0x80800D3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D40: jal         0x80102424
    // 0x80800D44: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80800D44: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80800D48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800D50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800D54: jr          $ra
    // 0x80800D58: nop

    return;
    // 0x80800D58: nop

;}
RECOMP_FUNC void func_80800E00_chmineprospector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800E0C: jal         0x80100094
    // 0x80800E10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800E10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800E14: beq         $v0, $zero, L_80800E24
    if (ctx->r2 == 0) {
        // 0x80800E18: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800E24;
    }
    // 0x80800E18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800E1C: jal         0x800897C8
    // 0x80800E20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800E20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_80800E24:
    // 0x80800E24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E2C: jr          $ra
    // 0x80800E30: nop

    return;
    // 0x80800E30: nop

    // 0x80800E34: nop

    // 0x80800E38: nop

    // 0x80800E3C: nop

;}
RECOMP_FUNC void idtwinklea_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800004: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80800008: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8080000C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80800010: jr          $ra
    // 0x80800014: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    return;
    // 0x80800014: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80801AFC_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AFC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801B00: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801B04: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801B08: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80801B0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801B10: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80801B14: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80801B18: bgez        $t8, L_80801B38
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80801B1C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80801B38;
    }
    // 0x80801B1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801B20: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1008, 0X1DBC) << 16);
    // 0x80801B24: addiu       $t9, $t9, 0x1DBC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1008, 0X1DBC));
    // 0x80801B28: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80801B2C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80801B30: jal         0x800BBCB8
    // 0x80801B34: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80801B34: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    after_0:
L_80801B38:
    // 0x80801B38: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x80801B3C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1008, 0X1DF0) << 16);
    // 0x80801B40: addiu       $a3, $a3, 0x1DF0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1008, 0X1DF0));
    // 0x80801B44: andi        $t0, $a1, 0x1
    ctx->r8 = ctx->r5 & 0X1;
    // 0x80801B48: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x80801B4C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80801B50: jal         0x8010D930
    // 0x80801B54: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_8010D930(rdram, ctx);
        goto after_1;
    // 0x80801B54: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x80801B58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801B5C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801B60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801B64: jr          $ra
    // 0x80801B68: nop

    return;
    // 0x80801B68: nop

;}
RECOMP_FUNC void _sumole_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089A28: syscall     800
    recomp_syscall_handler(rdram, ctx, 0x80089A28);
    return;
    // 0x80089A2C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void _bsbflip_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082940: syscall     21
    recomp_syscall_handler(rdram, ctx, 0x80082940);
    return;
    // 0x80082944: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808011B0_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011B0: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x808011B4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808011B8: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x808011BC: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x808011C0: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x808011C4: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x808011C8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808011CC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808011D0: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x808011D4: jal         0x80100094
    // 0x808011D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808011D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808011DC: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x808011E0: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x808011E4: jal         0x80088368
    // 0x808011E8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808011E8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_1:
    // 0x808011EC: blez        $v0, L_80801240
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808011F0: sll         $s2, $s1, 2
        ctx->r18 = S32(ctx->r17 << 2);
            goto L_80801240;
    }
    // 0x808011F0: sll         $s2, $s1, 2
    ctx->r18 = S32(ctx->r17 << 2);
    // 0x808011F4: addiu       $t6, $sp, 0x5C
    ctx->r14 = ADD32(ctx->r29, 0X5C);
    // 0x808011F8: addu        $s0, $s2, $t6
    ctx->r16 = ADD32(ctx->r18, ctx->r14);
    // 0x808011FC: addu        $s3, $s5, $s2
    ctx->r19 = ADD32(ctx->r21, ctx->r18);
    // 0x80801200: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
L_80801204:
    // 0x80801204: slt         $at, $s4, $t7
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80801208: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8080120C: beq         $at, $zero, L_80801218
    if (ctx->r1 == 0) {
        // 0x80801210: or          $a1, $t7, $zero
        ctx->r5 = ctx->r15 | 0;
            goto L_80801218;
    }
    // 0x80801210: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80801214: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
L_80801218:
    // 0x80801218: jal         0x800AA20C
    // 0x8080121C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800AA20C(rdram, ctx);
        goto after_2;
    // 0x8080121C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80801220: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801224: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80801228: jal         0x80088368
    // 0x8080122C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x8080122C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    after_3:
    // 0x80801230: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801234: bnel        $at, $zero, L_80801204
    if (ctx->r1 != 0) {
        // 0x80801238: lw          $t7, 0x0($s3)
        ctx->r15 = MEM_W(ctx->r19, 0X0);
            goto L_80801204;
    }
    goto skip_0;
    // 0x80801238: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    skip_0:
    // 0x8080123C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80801240:
    // 0x80801240: jal         0x80088368
    // 0x80801244: nop

    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80801244: nop

    after_4:
    // 0x80801248: blez        $v0, L_80801288
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080124C: sll         $s2, $s1, 2
        ctx->r18 = S32(ctx->r17 << 2);
            goto L_80801288;
    }
    // 0x8080124C: sll         $s2, $s1, 2
    ctx->r18 = S32(ctx->r17 << 2);
    // 0x80801250: addiu       $t8, $sp, 0x5C
    ctx->r24 = ADD32(ctx->r29, 0X5C);
    // 0x80801254: addu        $s0, $s2, $t8
    ctx->r16 = ADD32(ctx->r18, ctx->r24);
    // 0x80801258: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8080125C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
L_80801260:
    // 0x80801260: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801264: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80801268: bne         $s4, $t9, L_80801274
    if (ctx->r20 != ctx->r25) {
        // 0x8080126C: addu        $t0, $s5, $s2
        ctx->r8 = ADD32(ctx->r21, ctx->r18);
            goto L_80801274;
    }
    // 0x8080126C: addu        $t0, $s5, $s2
    ctx->r8 = ADD32(ctx->r21, ctx->r18);
    // 0x80801270: sw          $s3, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r19;
L_80801274:
    // 0x80801274: jal         0x80088368
    // 0x80801278: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80801278: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    after_5:
    // 0x8080127C: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801280: bnel        $at, $zero, L_80801260
    if (ctx->r1 != 0) {
        // 0x80801284: lw          $t9, 0x0($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X0);
            goto L_80801260;
    }
    goto skip_1;
    // 0x80801284: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    skip_1:
L_80801288:
    // 0x80801288: jal         0x80088368
    // 0x8080128C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x8080128C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_6:
    // 0x80801290: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80801294: bne         $at, $zero, L_80801310
    if (ctx->r1 != 0) {
        // 0x80801298: addiu       $s1, $sp, 0x5C
        ctx->r17 = ADD32(ctx->r29, 0X5C);
            goto L_80801310;
    }
    // 0x80801298: addiu       $s1, $sp, 0x5C
    ctx->r17 = ADD32(ctx->r29, 0X5C);
    // 0x8080129C: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
L_808012A0:
    // 0x808012A0: blez        $s0, L_808012FC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x808012A4: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_808012FC;
    }
    // 0x808012A4: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x808012A8: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x808012AC: addu        $v0, $s1, $t1
    ctx->r2 = ADD32(ctx->r17, ctx->r9);
    // 0x808012B0: lw          $t2, -0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, -0X4);
    // 0x808012B4: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x808012B8: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x808012BC: addu        $v0, $s1, $t4
    ctx->r2 = ADD32(ctx->r17, ctx->r12);
    // 0x808012C0: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x808012C4: beq         $at, $zero, L_808012FC
    if (ctx->r1 == 0) {
        // 0x808012C8: nop
    
            goto L_808012FC;
    }
    // 0x808012C8: nop

    // 0x808012CC: lw          $a0, -0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X4);
    // 0x808012D0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808012D4: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
L_808012D8:
    // 0x808012D8: sltu        $at, $v0, $a2
    ctx->r1 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x808012DC: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x808012E0: bne         $at, $zero, L_808012FC
    if (ctx->r1 != 0) {
        // 0x808012E4: sw          $a1, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r5;
            goto L_808012FC;
    }
    // 0x808012E4: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x808012E8: lw          $a0, -0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X4);
    // 0x808012EC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808012F0: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x808012F4: bnel        $at, $zero, L_808012D8
    if (ctx->r1 != 0) {
        // 0x808012F8: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_808012D8;
    }
    goto skip_2;
    // 0x808012F8: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    skip_2:
L_808012FC:
    // 0x808012FC: jal         0x80088368
    // 0x80801300: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x80801300: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_7:
    // 0x80801304: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801308: bne         $at, $zero, L_808012A0
    if (ctx->r1 != 0) {
        // 0x8080130C: addiu       $a2, $sp, 0x60
        ctx->r6 = ADD32(ctx->r29, 0X60);
            goto L_808012A0;
    }
    // 0x8080130C: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
L_80801310:
    // 0x80801310: jal         0x800FC6B0
    // 0x80801314: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_8;
    // 0x80801314: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_8:
    // 0x80801318: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x8080131C: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80801320: addiu       $s0, $zero, 0x1349
    ctx->r16 = ADD32(0, 0X1349);
    // 0x80801324: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801328: beq         $t5, $t6, L_80801364
    if (ctx->r13 == ctx->r14) {
        // 0x8080132C: nop
    
            goto L_80801364;
    }
    // 0x8080132C: nop

    // 0x80801330: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x80801334: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80801338: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x8080133C: beq         $t7, $t5, L_8080135C
    if (ctx->r15 == ctx->r13) {
        // 0x80801340: addiu       $s0, $zero, 0x1348
        ctx->r16 = ADD32(0, 0X1348);
            goto L_8080135C;
    }
    // 0x80801340: addiu       $s0, $zero, 0x1348
    ctx->r16 = ADD32(0, 0X1348);
    // 0x80801344: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
L_80801348:
    // 0x80801348: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x8080134C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80801350: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801354: bnel        $t8, $t9, L_80801348
    if (ctx->r24 != ctx->r25) {
        // 0x80801358: lw          $t8, 0x4($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X4);
            goto L_80801348;
    }
    goto skip_3;
    // 0x80801358: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    skip_3:
L_8080135C:
    // 0x8080135C: b           L_80801364
    // 0x80801360: sw          $v1, 0xA0($s5)
    MEM_W(0XA0, ctx->r21) = ctx->r3;
        goto L_80801364;
    // 0x80801360: sw          $v1, 0xA0($s5)
    MEM_W(0XA0, ctx->r21) = ctx->r3;
L_80801364:
    // 0x80801364: jal         0x8008A090
    // 0x80801368: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiemulti_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x80801368: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x8080136C: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80801370: jal         0x80101FDC
    // 0x80801374: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_10;
    // 0x80801374: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_10:
    // 0x80801378: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x8080137C: addiu       $t1, $zero, 0xA3
    ctx->r9 = ADD32(0, 0XA3);
    // 0x80801380: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801384: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80801388: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8080138C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80801390: jal         0x8008A208
    // 0x80801394: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_11;
    // 0x80801394: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x80801398: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8080139C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808013A0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808013A4: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x808013A8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x808013AC: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x808013B0: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x808013B4: jr          $ra
    // 0x808013B8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x808013B8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_8080099C_chbottlesfamily(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080099C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009A0: addiu       $at, $zero, 0x1501
    ctx->r1 = ADD32(0, 0X1501);
    // 0x808009A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009A8: beq         $a1, $at, L_808009B8
    if (ctx->r5 == ctx->r1) {
        // 0x808009AC: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_808009B8;
    }
    // 0x808009AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808009B0: addiu       $at, $zero, 0x1539
    ctx->r1 = ADD32(0, 0X1539);
    // 0x808009B4: bne         $a1, $at, L_808009E0
    if (ctx->r5 != ctx->r1) {
        // 0x808009B8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808009E0;
    }
L_808009B8:
    // 0x808009B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808009BC: bnel        $a2, $at, L_808009E4
    if (ctx->r6 != ctx->r1) {
        // 0x808009C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808009E4;
    }
    goto skip_0;
    // 0x808009C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808009C4: jal         0x800C07F4
    // 0x808009C8: nop

    func_800C07F4(rdram, ctx);
        goto after_0;
    // 0x808009C8: nop

    after_0:
    // 0x808009CC: bne         $v0, $zero, L_808009E0
    if (ctx->r2 != 0) {
        // 0x808009D0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808009E0;
    }
    // 0x808009D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808009D4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808009D8: jal         0x80800CA4
    // 0x808009DC: addiu       $a2, $zero, 0x2020
    ctx->r6 = ADD32(0, 0X2020);
    func_80800CA4_chbottlesfamily(rdram, ctx);
        goto after_1;
    // 0x808009DC: addiu       $a2, $zero, 0x2020
    ctx->r6 = ADD32(0, 0X2020);
    after_1:
L_808009E0:
    // 0x808009E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808009E4:
    // 0x808009E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009E8: jr          $ra
    // 0x808009EC: nop

    return;
    // 0x808009EC: nop

;}
RECOMP_FUNC void chfantasyeyeball_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801820: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2400, 0X1F28) << 16);
    // 0x80801824: jr          $ra
    // 0x80801828: addiu       $v0, $v0, 0x1F28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2400, 0X1F28));
    return;
    // 0x80801828: addiu       $v0, $v0, 0x1F28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2400, 0X1F28));
;}
RECOMP_FUNC void func_800D9624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9624: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D9628: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800D962C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800D9630: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_800D9634:
    // 0x800D9634: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800D9638: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D963C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D9640: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800D9644: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800D9648: bne         $v0, $a3, L_800D9634
    if (ctx->r2 != ctx->r7) {
        // 0x800D964C: swc1        $f6, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f6.u32l;
            goto L_800D9634;
    }
    // 0x800D964C: swc1        $f6, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f6.u32l;
    // 0x800D9650: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800D9654: jr          $ra
    // 0x800D9658: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800D9658: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void guMtxL2F(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EE00: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x8002EE04: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002EE08: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8002EE0C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8002EE10: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x8002EE14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002EE18: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8002EE1C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8002EE20: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8002EE24: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_8002EE28:
    // 0x8002EE28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002EE2C: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_8002EE30:
    // 0x8002EE30: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8002EE34: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8002EE38: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002EE3C: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x8002EE40: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8002EE44: and         $t5, $t9, $t2
    ctx->r13 = ctx->r25 & ctx->r10;
    // 0x8002EE48: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x8002EE4C: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8002EE50: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8002EE54: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8002EE58: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8002EE5C: sll         $t5, $t8, 16
    ctx->r13 = S32(ctx->r24 << 16);
    // 0x8002EE60: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8002EE64: and         $t6, $t5, $t2
    ctx->r14 = ctx->r13 & ctx->r10;
    // 0x8002EE68: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x8002EE6C: or          $a3, $t9, $t6
    ctx->r7 = ctx->r25 | ctx->r14;
    // 0x8002EE70: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002EE74: mtc1        $a3, $f10
    ctx->f10.u32l = ctx->r7;
    // 0x8002EE78: sw          $a3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r7;
    // 0x8002EE7C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x8002EE80: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8002EE84: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002EE88: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8002EE8C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002EE90: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8002EE94: swc1        $f8, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->f8.u32l;
    // 0x8002EE98: bne         $a0, $t3, L_8002EE30
    if (ctx->r4 != ctx->r11) {
        // 0x8002EE9C: swc1        $f18, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->f18.u32l;
            goto L_8002EE30;
    }
    // 0x8002EE9C: swc1        $f18, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f18.u32l;
    // 0x8002EEA0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8002EEA4: bne         $a2, $t4, L_8002EE28
    if (ctx->r6 != ctx->r12) {
        // 0x8002EEA8: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_8002EE28;
    }
    // 0x8002EEA8: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x8002EEAC: jr          $ra
    // 0x8002EEB0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8002EEB0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80028010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028010: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80028014: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80028018: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8002801C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80028020: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80028024: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x80028028: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x8002802C: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x80028030: addiu       $t7, $zero, 0x2E0
    ctx->r15 = ADD32(0, 0X2E0);
    // 0x80028034: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x80028038: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8002803C: addiu       $t8, $zero, 0xB8
    ctx->r24 = ADD32(0, 0XB8);
    // 0x80028040: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80028044: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80028048: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x8002804C: beq         $t0, $zero, L_800282B4
    if (ctx->r8 == 0) {
        // 0x80028050: nop
    
            goto L_800282B4;
    }
    // 0x80028050: nop

    // 0x80028054: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80028058: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8002805C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80028060: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80028064: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x80028068: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8002806C: jal         0x800287FC
    // 0x80028070: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800287FC(rdram, ctx);
        goto after_0;
    // 0x80028070: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_0:
    // 0x80028074: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80028078: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8002807C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80028080: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80028084: nop

    // 0x80028088: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002808C: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80028090: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x80028094: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x80028098: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002809C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800280A0: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800280A4: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800280A8: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x800280AC: nop

    // 0x800280B0: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800280B4: nop

    // 0x800280B8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800280BC: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x800280C0: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800280C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800280C8: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800280CC: div.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800280D0: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x800280D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800280D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800280DC: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800280E0: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800280E4: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x800280E8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800280EC: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800280F0: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800280F4: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800280F8: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x800280FC: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80028100: lwc1        $f8, 0x24($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X24);
    // 0x80028104: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80028108: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8002810C: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x80028110: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80028114: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80028118: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x8002811C: nop

    // 0x80028120: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x80028124: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80028128: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8002812C: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x80028130: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80028134: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x80028138: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002813C: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80028140: swc1        $f10, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->f10.u32l;
    // 0x80028144: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80028148: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8002814C: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80028150: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80028154: lw          $t3, 0x18($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X18);
    // 0x80028158: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8002815C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80028160: lw          $t0, 0x28($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X28);
    // 0x80028164: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80028168: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x8002816C: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x80028170: addu        $t6, $t0, $t7
    ctx->r14 = ADD32(ctx->r8, ctx->r15);
    // 0x80028174: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x80028178: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8002817C: andi        $t9, $t8, 0x7
    ctx->r25 = ctx->r24 & 0X7;
    // 0x80028180: sra         $t1, $t9, 1
    ctx->r9 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80028184: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80028188: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8002818C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80028190: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80028194: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80028198: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8002819C: addu        $t0, $t5, $t3
    ctx->r8 = ADD32(ctx->r13, ctx->r11);
    // 0x800281A0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800281A4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800281A8: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x800281AC: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800281B0: subu        $a2, $t2, $t4
    ctx->r6 = SUB32(ctx->r10, ctx->r12);
    // 0x800281B4: jal         0x80028328
    // 0x800281B8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_80028328(rdram, ctx);
        goto after_1;
    // 0x800281B8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_1:
    // 0x800281BC: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x800281C0: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800281C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800281C8: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800281CC: mul.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800281D0: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800281D4: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800281D8: nop

    // 0x800281DC: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x800281E0: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800281E4: sra         $t1, $t9, 8
    ctx->r9 = S32(SIGNED(ctx->r25) >> 8);
    // 0x800281E8: sh          $t1, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r9;
    // 0x800281EC: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800281F0: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x800281F4: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x800281F8: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800281FC: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x80028200: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80028204: lw          $t3, 0x24($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X24);
    // 0x80028208: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8002820C: addu        $t6, $t3, $t7
    ctx->r14 = ADD32(ctx->r11, ctx->r15);
    // 0x80028210: jal         0x8002E330
    // 0x80028214: lw          $a0, 0x14($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X14);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x80028214: lw          $a0, 0x14($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X14);
    after_2:
    // 0x80028218: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8002821C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80028220: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80028224: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x80028228: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x8002822C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80028230: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80028234: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x80028238: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8002823C: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80028240: lw          $t4, 0x24($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X24);
    // 0x80028244: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80028248: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x8002824C: lw          $t5, 0x28($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X28);
    // 0x80028250: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x80028254: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x80028258: andi        $t0, $t5, 0x3
    ctx->r8 = ctx->r13 & 0X3;
    // 0x8002825C: sll         $t3, $t0, 30
    ctx->r11 = S32(ctx->r8 << 30);
    // 0x80028260: or          $t9, $t3, $t8
    ctx->r25 = ctx->r11 | ctx->r24;
    // 0x80028264: lh          $t3, 0x2A($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X2A);
    // 0x80028268: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x8002826C: andi        $t0, $t5, 0xFFF
    ctx->r8 = ctx->r13 & 0XFFF;
    // 0x80028270: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80028274: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80028278: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x8002827C: andi        $t8, $t3, 0x3
    ctx->r24 = ctx->r11 & 0X3;
    // 0x80028280: or          $t2, $t6, $t8
    ctx->r10 = ctx->r14 | ctx->r24;
    // 0x80028284: sw          $t2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r10;
    // 0x80028288: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x8002828C: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x80028290: sw          $zero, 0x28($t5)
    MEM_W(0X28, ctx->r13) = 0;
    // 0x80028294: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x80028298: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8002829C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800282A0: lw          $t6, 0x18($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X18);
    // 0x800282A4: subu        $t7, $t0, $t9
    ctx->r15 = SUB32(ctx->r8, ctx->r25);
    // 0x800282A8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800282AC: b           L_80028308
    // 0x800282B0: sw          $t8, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->r24;
        goto L_80028308;
    // 0x800282B0: sw          $t8, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->r24;
L_800282B4:
    // 0x800282B4: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x800282B8: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800282BC: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800282C0: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x800282C4: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x800282C8: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800282CC: lw          $t0, 0x28($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X28);
    // 0x800282D0: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x800282D4: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800282D8: addu        $t3, $t0, $t8
    ctx->r11 = ADD32(ctx->r8, ctx->r24);
    // 0x800282DC: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x800282E0: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800282E4: addiu       $t1, $zero, 0xB8
    ctx->r9 = ADD32(0, 0XB8);
    // 0x800282E8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800282EC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800282F0: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x800282F4: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800282F8: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x800282FC: jal         0x80028328
    // 0x80028300: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    func_80028328(rdram, ctx);
        goto after_3;
    // 0x80028300: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_3:
    // 0x80028304: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
L_80028308:
    // 0x80028308: b           L_80028318
    // 0x8002830C: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
        goto L_80028318;
    // 0x8002830C: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x80028310: b           L_80028318
    // 0x80028314: nop

        goto L_80028318;
    // 0x80028314: nop

L_80028318:
    // 0x80028318: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002831C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80028320: jr          $ra
    // 0x80028324: nop

    return;
    // 0x80028324: nop

;}
RECOMP_FUNC void func_8008BC4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BC4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008BC50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008BC54: jal         0x8008BBF0
    // 0x8008BC58: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008BBF0(rdram, ctx);
        goto after_0;
    // 0x8008BC58: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x8008BC5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008BC60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008BC64: jr          $ra
    // 0x8008BC68: nop

    return;
    // 0x8008BC68: nop

;}
RECOMP_FUNC void func_800A5104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5104: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5108: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A510C: jal         0x800A92A8
    // 0x800A5110: nop

    func_800A92A8(rdram, ctx);
        goto after_0;
    // 0x800A5110: nop

    after_0:
    // 0x800A5114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A511C: jr          $ra
    // 0x800A5120: nop

    return;
    // 0x800A5120: nop

;}
RECOMP_FUNC void func_808019A0_sucoasterfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808019A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808019A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808019AC: jal         0x80801E5C
    // 0x808019B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80801E5C_sucoasterfly(rdram, ctx);
        goto after_0;
    // 0x808019B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808019B4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x808019B8: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x808019BC: lui         $t0, 0x50
    ctx->r8 = S32(0X50 << 16);
    // 0x808019C0: ori         $t0, $t0, 0x4327
    ctx->r8 = ctx->r8 | 0X4327;
    // 0x808019C4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x808019C8: bgez        $t8, L_808019DC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808019CC: lui         $t9, 0x40
        ctx->r25 = S32(0X40 << 16);
            goto L_808019DC;
    }
    // 0x808019CC: lui         $t9, 0x40
    ctx->r25 = S32(0X40 << 16);
    // 0x808019D0: ori         $t9, $t9, 0x4027
    ctx->r25 = ctx->r25 | 0X4027;
    // 0x808019D4: b           L_808019E0
    // 0x808019D8: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
        goto L_808019E0;
    // 0x808019D8: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
L_808019DC:
    // 0x808019DC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
L_808019E0:
    // 0x808019E0: jal         0x808018BC
    // 0x808019E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808018BC_sucoasterfly(rdram, ctx);
        goto after_1;
    // 0x808019E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808019E8: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x808019EC: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x808019F0: jal         0x800EEB9C
    // 0x808019F4: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    func_800EEB9C(rdram, ctx);
        goto after_2;
    // 0x808019F4: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    after_2:
    // 0x808019F8: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808019FC: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801A00: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x80801A04: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801A08: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x80801A0C: jal         0x800F0D50
    // 0x80801A10: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_800F0D50(rdram, ctx);
        goto after_3;
    // 0x80801A10: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_3:
    // 0x80801A14: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80801A18: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80801A1C: jal         0x8010B990
    // 0x80801A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010B990(rdram, ctx);
        goto after_4;
    // 0x80801A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801A24: andi        $t1, $v0, 0x24
    ctx->r9 = ctx->r2 & 0X24;
    // 0x80801A28: beql        $t1, $zero, L_80801A70
    if (ctx->r9 == 0) {
        // 0x80801A2C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801A70;
    }
    goto skip_0;
    // 0x80801A2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801A30: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x80801A34: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80801A38: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80801A3C: bltzl       $t4, L_80801A70
    if (SIGNED(ctx->r12) < 0) {
        // 0x80801A40: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801A70;
    }
    goto skip_1;
    // 0x80801A40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80801A44: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80801A48: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A50: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80801A54: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80801A58: jal         0x80102924
    // 0x80801A5C: nop

    func_80102924(rdram, ctx);
        goto after_5;
    // 0x80801A5C: nop

    after_5:
    // 0x80801A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A64: jal         0x808014AC
    // 0x80801A68: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_6;
    // 0x80801A68: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80801A6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801A70:
    // 0x80801A70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801A74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801A78: jr          $ra
    // 0x80801A7C: nop

    return;
    // 0x80801A7C: nop

;}
RECOMP_FUNC void func_808005F0_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808005F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808005FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800600: jal         0x8009E6C4
    // 0x80800604: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E6C4(rdram, ctx);
        goto after_0;
    // 0x80800604: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800608: bne         $v0, $zero, L_80800758
    if (ctx->r2 != 0) {
        // 0x8080060C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800758;
    }
    // 0x8080060C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800610: jal         0x800A0DC4
    // 0x80800614: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0DC4(rdram, ctx);
        goto after_1;
    // 0x80800614: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800618: jal         0x80084D90
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bakaztorpedo_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800620: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800628: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // 0x8080062C: jal         0x8008C984
    // 0x80800630: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
    func_8008C984(rdram, ctx);
        goto after_3;
    // 0x80800630: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x80800634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800638: jal         0x8009BCB4
    // 0x8080063C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_gravity(rdram, ctx);
        goto after_4;
    // 0x8080063C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800640: lui         $a1, 0xC3C7
    ctx->r5 = S32(0XC3C7 << 16);
    // 0x80800644: ori         $a1, $a1, 0xFEB8
    ctx->r5 = ctx->r5 | 0XFEB8;
    // 0x80800648: jal         0x8009BCC4
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_5;
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800654: jal         0x800961AC
    // 0x80800658: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_800961AC(rdram, ctx);
        goto after_6;
    // 0x80800658: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_6:
    // 0x8080065C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800660: jal         0x8009BC5C
    // 0x80800664: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_8009BC5C(rdram, ctx);
        goto after_7;
    // 0x80800664: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_7:
    // 0x80800668: jal         0x8009EFA8
    // 0x8080066C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_pushZone(rdram, ctx);
        goto after_8;
    // 0x8080066C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800670: lui         $a2, 0x3DF5
    ctx->r6 = S32(0X3DF5 << 16);
    // 0x80800674: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80800678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080067C: jal         0x8009F1C8
    // 0x80800680: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_9;
    // 0x80800680: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800688: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080068C: jal         0x8009F1C8
    // 0x80800690: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_10;
    // 0x80800690: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_10:
    // 0x80800694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800698: lui         $a1, 0x428C
    ctx->r5 = S32(0X428C << 16);
    // 0x8080069C: jal         0x800959C8
    // 0x808006A0: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    func_800959C8(rdram, ctx);
        goto after_11;
    // 0x808006A0: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_11:
    // 0x808006A4: jal         0x8009E4AC
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E4AC(rdram, ctx);
        goto after_12;
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808006B4: jal         0x8009E55C
    // 0x808006B8: lui         $a2, 0x428C
    ctx->r6 = S32(0X428C << 16);
    func_8009E55C(rdram, ctx);
        goto after_13;
    // 0x808006B8: lui         $a2, 0x428C
    ctx->r6 = S32(0X428C << 16);
    after_13:
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808006C4: jal         0x8009E55C
    // 0x808006C8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009E55C(rdram, ctx);
        goto after_14;
    // 0x808006C8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_14:
    // 0x808006CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808006D4: jal         0x8009E55C
    // 0x808006D8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009E55C(rdram, ctx);
        goto after_15;
    // 0x808006D8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_15:
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E0: jal         0x80093360
    // 0x808006E4: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    func_80093360(rdram, ctx);
        goto after_16;
    // 0x808006E4: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    after_16:
    // 0x808006E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006EC: jal         0x800910BC
    // 0x808006F0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800910BC(rdram, ctx);
        goto after_17;
    // 0x808006F0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_17:
    // 0x808006F4: jal         0x808000CC
    // 0x808006F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000CC_bskaztorpedo(rdram, ctx);
        goto after_18;
    // 0x808006F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800700: jal         0x80084CE8
    // 0x80800704: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _bafpctrl_entrypoint_14(rdram, ctx);
        goto after_19;
    // 0x80800704: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_19:
    // 0x80800708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080070C: jal         0x80084CC0
    // 0x80800710: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bafpctrl_entrypoint_9(rdram, ctx);
        goto after_20;
    // 0x80800710: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x80800714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800718: jal         0x80084CC8
    // 0x8080071C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bafpctrl_entrypoint_10(rdram, ctx);
        goto after_21;
    // 0x8080071C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x80800720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800724: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800728: jal         0x80084CD0
    // 0x8080072C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _bafpctrl_entrypoint_11(rdram, ctx);
        goto after_22;
    // 0x8080072C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_22:
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800734: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800738: jal         0x800A38F0
    // 0x8080073C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800A38F0(rdram, ctx);
        goto after_23;
    // 0x8080073C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_23:
    // 0x80800740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800744: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800748: jal         0x800947EC
    // 0x8080074C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_24;
    // 0x8080074C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_24:
    // 0x80800750: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x80800754: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
L_80800758:
    // 0x80800758: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080075C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800760: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800764: jr          $ra
    // 0x80800768: nop

    return;
    // 0x80800768: nop

;}
RECOMP_FUNC void vector_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2928: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800B292C: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x800B2930: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800B2934: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800B2938: div         $zero, $t8, $t9
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r25)));
    // 0x800B293C: mflo        $v0
    ctx->r2 = lo;
    // 0x800B2940: bne         $t9, $zero, L_800B294C
    if (ctx->r25 != 0) {
        // 0x800B2944: nop
    
            goto L_800B294C;
    }
    // 0x800B2944: nop

    // 0x800B2948: break       7
    do_break(2148215112);
L_800B294C:
    // 0x800B294C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B2950: bne         $t9, $at, L_800B2964
    if (ctx->r25 != ctx->r1) {
        // 0x800B2954: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B2964;
    }
    // 0x800B2954: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2958: bne         $t8, $at, L_800B2964
    if (ctx->r24 != ctx->r1) {
        // 0x800B295C: nop
    
            goto L_800B2964;
    }
    // 0x800B295C: nop

    // 0x800B2960: break       6
    do_break(2148215136);
L_800B2964:
    // 0x800B2964: jr          $ra
    // 0x800B2968: nop

    return;
    // 0x800B2968: nop

;}
RECOMP_FUNC void _fxtwinkle_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088AB0: syscall     720
    recomp_syscall_handler(rdram, ctx, 0x80088AB0);
    return;
    // 0x80088AB4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080005C_chfactoryposter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080005C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800060: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800064: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800068: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x8080006C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800070: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800074: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800078: bnel        $t7, $at, L_808000F4
    if (ctx->r15 != ctx->r1) {
        // 0x8080007C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000F4;
    }
    goto skip_0;
    // 0x8080007C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800080: jal         0x800F54E4
    // 0x80800084: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800084: nop

    after_0:
    // 0x80800088: jal         0x800F6438
    // 0x8080008C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6438(rdram, ctx);
        goto after_1;
    // 0x8080008C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800090: beql        $v0, $zero, L_808000F4
    if (ctx->r2 == 0) {
        // 0x80800094: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000F4;
    }
    goto skip_1;
    // 0x80800094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800098: jal         0x800F54E4
    // 0x8080009C: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x8080009C: nop

    after_2:
    // 0x808000A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000A4: jal         0x800F5A00
    // 0x808000A8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800F5A00(rdram, ctx);
        goto after_3;
    // 0x808000A8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x808000AC: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808000B0: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808000BC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808000C0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1472, 0X158) << 16);
    // 0x808000C4: bc1fl       L_808000F4
    if (!c1cs) {
        // 0x808000C8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000F4;
    }
    goto skip_2;
    // 0x808000C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x808000CC: jal         0x80089D18
    // 0x808000D0: addiu       $a2, $a2, 0x158
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1472, 0X158));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x808000D0: addiu       $a2, $a2, 0x158
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1472, 0X158));
    after_4:
    // 0x808000D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808000D8: jal         0x800BF744
    // 0x808000DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800BF744(rdram, ctx);
        goto after_5;
    // 0x808000DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x808000E0: jal         0x800DA544
    // 0x808000E4: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    func_800DA544(rdram, ctx);
        goto after_6;
    // 0x808000E4: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    after_6:
    // 0x808000E8: jal         0x800FFAB0
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_7;
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808000F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000F4:
    // 0x808000F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000FC: jr          $ra
    // 0x80800100: nop

    return;
    // 0x80800100: nop

    // 0x80800104: nop

    // 0x80800108: nop

    // 0x8080010C: nop

;}
