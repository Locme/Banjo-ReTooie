#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800EE0F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE0F8: jr          $ra
    // 0x800EE0FC: sw          $a1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r5;
    return;
    // 0x800EE0FC: sw          $a1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void bsbtrot_entrypoint_44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808027C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808027C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808027C8: jal         0x8009BC6C
    // 0x808027CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baphysics_reset_gravity(rdram, ctx);
        goto after_0;
    // 0x808027CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808027D0: jal         0x8080061C
    // 0x808027D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080061C_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x808027D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808027D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808027DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808027E0: jr          $ra
    // 0x808027E4: nop

    return;
    // 0x808027E4: nop

;}
RECOMP_FUNC void func_800E2588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2588: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E258C: jr          $ra
    // 0x800E2590: sb          $a0, -0x2B72($at)
    MEM_B(-0X2B72, ctx->r1) = ctx->r4;
    return;
    // 0x800E2590: sb          $a0, -0x2B72($at)
    MEM_B(-0X2B72, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_800D298C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D298C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D2990: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D2994: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D2998: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800D299C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D29A0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D29A4: jal         0x800EA05C
    // 0x800D29A8: addiu       $s0, $s0, -0x4AD0
    ctx->r16 = ADD32(ctx->r16, -0X4AD0);
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x800D29A8: addiu       $s0, $s0, -0x4AD0
    ctx->r16 = ADD32(ctx->r16, -0X4AD0);
    after_0:
    // 0x800D29AC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800D29B0: addiu       $v1, $v1, -0x4CE0
    ctx->r3 = ADD32(ctx->r3, -0X4CE0);
    // 0x800D29B4: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x800D29B8: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x800D29BC: sb          $zero, 0x18($v1)
    MEM_B(0X18, ctx->r3) = 0;
    // 0x800D29C0: sb          $zero, 0x4($v1)
    MEM_B(0X4, ctx->r3) = 0;
    // 0x800D29C4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800D29C8: lh          $t8, -0x4AD0($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X4AD0);
    // 0x800D29CC: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x800D29D0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800D29D4: beql        $s2, $t8, L_800D2A30
    if (ctx->r18 == ctx->r24) {
        // 0x800D29D8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D2A30;
    }
    goto skip_0;
    // 0x800D29D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800D29DC: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
L_800D29E0:
    // 0x800D29E0: bnel        $s1, $v0, L_800D2A20
    if (ctx->r17 != ctx->r2) {
        // 0x800D29E4: lh          $v0, 0x10($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X10);
            goto L_800D2A20;
    }
    goto skip_1;
    // 0x800D29E4: lh          $v0, 0x10($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X10);
    skip_1:
    // 0x800D29E8: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x800D29EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D29F0: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800D29F4: beql        $t9, $zero, L_800D2A0C
    if (ctx->r25 == 0) {
        // 0x800D29F8: andi        $t0, $v0, 0x2
        ctx->r8 = ctx->r2 & 0X2;
            goto L_800D2A0C;
    }
    goto skip_2;
    // 0x800D29F8: andi        $t0, $v0, 0x2
    ctx->r8 = ctx->r2 & 0X2;
    skip_2:
    // 0x800D29FC: jal         0x800D2910
    // 0x800D2A00: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800D2910(rdram, ctx);
        goto after_1;
    // 0x800D2A00: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800D2A04: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x800D2A08: andi        $t0, $v0, 0x2
    ctx->r8 = ctx->r2 & 0X2;
L_800D2A0C:
    // 0x800D2A0C: beq         $t0, $zero, L_800D2A1C
    if (ctx->r8 == 0) {
        // 0x800D2A10: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800D2A1C;
    }
    // 0x800D2A10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800D2A14: jal         0x800D2910
    // 0x800D2A18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800D2910(rdram, ctx);
        goto after_2;
    // 0x800D2A18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
L_800D2A1C:
    // 0x800D2A1C: lh          $v0, 0x10($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X10);
L_800D2A20:
    // 0x800D2A20: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800D2A24: bne         $s2, $v0, L_800D29E0
    if (ctx->r18 != ctx->r2) {
        // 0x800D2A28: nop
    
            goto L_800D29E0;
    }
    // 0x800D2A28: nop

    // 0x800D2A2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D2A30:
    // 0x800D2A30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D2A34: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D2A38: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D2A3C: jr          $ra
    // 0x800D2A40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800D2A40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bscrouch_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800690: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800694: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(152, 0X990) << 16);
    // 0x80800698: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080069C: jr          $ra
    // 0x808006A0: lw          $v0, 0x990($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(152, 0X990));
    return;
    // 0x808006A0: lw          $v0, 0x990($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(152, 0X990));
;}
RECOMP_FUNC void func_8080000C_chamazongoldhordeofficial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800018: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080001C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800020: jal         0x80100094
    // 0x80800024: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800024: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800028: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x8080002C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800030: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800034: jal         0x8010A3E8
    // 0x80800038: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8010A3E8(rdram, ctx);
        goto after_1;
    // 0x80800038: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8080003C: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    // 0x80800040: jal         0x8008A4E0
    // 0x80800044: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddieDll_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800044: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80800048: addiu       $t6, $zero, -0x3E7
    ctx->r14 = ADD32(0, -0X3E7);
    // 0x8080004C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800050: sh          $t6, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r14;
    // 0x80800054: sh          $t7, 0x6A($s0)
    MEM_H(0X6A, ctx->r16) = ctx->r15;
    // 0x80800058: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    // 0x8080005C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800060: jal         0x800882C0
    // 0x80800064: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x80800064: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_3:
    // 0x80800068: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x8080006C: sb          $v0, 0x48($s0)
    MEM_B(0X48, ctx->r16) = ctx->r2;
    // 0x80800070: blez        $t8, L_808000E0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80800074: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808000E0;
    }
    // 0x80800074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800078: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8080007C: addiu       $v0, $sp, 0x3C
    ctx->r2 = ADD32(ctx->r29, 0X3C);
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800084: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
L_80800088:
    // 0x80800088: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8080008C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80800090: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80800094: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800098: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8080009C: sh          $t0, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r8;
    // 0x808000A0: lw          $t1, -0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, -0X4);
    // 0x808000A4: lh          $t2, 0x4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4);
    // 0x808000A8: sh          $t2, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r10;
    // 0x808000AC: lw          $t3, -0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, -0X4);
    // 0x808000B0: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x808000B4: srl         $t5, $t4, 7
    ctx->r13 = S32(U32(ctx->r12) >> 7);
    // 0x808000B8: sb          $t5, 0x48($a0)
    MEM_B(0X48, ctx->r4) = ctx->r13;
    // 0x808000BC: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x808000C0: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x808000C4: srl         $t8, $t7, 23
    ctx->r24 = S32(U32(ctx->r15) >> 23);
    // 0x808000C8: srl         $t9, $t8, 1
    ctx->r25 = S32(U32(ctx->r24) >> 1);
    // 0x808000CC: sb          $t9, 0x57($a0)
    MEM_B(0X57, ctx->r4) = ctx->r25;
    // 0x808000D0: lbu         $t0, 0x48($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X48);
    // 0x808000D4: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x808000D8: bnel        $at, $zero, L_80800088
    if (ctx->r1 != 0) {
        // 0x808000DC: lw          $t9, 0x0($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X0);
            goto L_80800088;
    }
    goto skip_0;
    // 0x808000DC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    skip_0:
L_808000E0:
    // 0x808000E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000E4: jal         0x80800DB4
    // 0x808000E8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_80800DB4_chamazongoldhordeofficial(rdram, ctx);
        goto after_4;
    // 0x808000E8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_4:
    // 0x808000EC: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    // 0x808000F0: jal         0x80088280
    // 0x808000F4: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    _gccubesearch_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x808000F4: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    after_5:
    // 0x808000F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000FC: jal         0x80088C00
    // 0x80800100: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80800100: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    after_6:
    // 0x80800104: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800108: jal         0x80100094
    // 0x8080010C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_7;
    // 0x8080010C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800110: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800114: addiu       $a1, $v0, 0x6C
    ctx->r5 = ADD32(ctx->r2, 0X6C);
    // 0x80800118: jal         0x8008A2A0
    // 0x8080011C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _susubgame_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x8080011C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x80800120: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800124: jal         0x80100094
    // 0x80800128: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_9;
    // 0x80800128: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x8080012C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1860, 0X11C0) << 16);
    // 0x80800130: addiu       $a1, $a1, 0x11C0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1860, 0X11C0));
    // 0x80800134: jal         0x8008A300
    // 0x80800138: addiu       $a0, $v0, 0x6C
    ctx->r4 = ADD32(ctx->r2, 0X6C);
    _susubgame_entrypoint_12(rdram, ctx);
        goto after_10;
    // 0x80800138: addiu       $a0, $v0, 0x6C
    ctx->r4 = ADD32(ctx->r2, 0X6C);
    after_10:
    // 0x8080013C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800140: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800144: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800148: jr          $ra
    // 0x8080014C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8080014C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_808040A0_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808040A0: jr          $ra
    // 0x808040A4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808040A4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_808025B4_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808025B4: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x808025B8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x808025BC: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x808025C0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x808025C4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808025C8: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x808025CC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808025D0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808025D4: beq         $a1, $at, L_808025F0
    if (ctx->r5 == ctx->r1) {
        // 0x808025D8: sw          $a2, 0xB8($sp)
        MEM_W(0XB8, ctx->r29) = ctx->r6;
            goto L_808025F0;
    }
    // 0x808025D8: sw          $a2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r6;
    // 0x808025DC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808025E0: beq         $a1, $at, L_808026C8
    if (ctx->r5 == ctx->r1) {
        // 0x808025E4: addiu       $a0, $zero, 0x511
        ctx->r4 = ADD32(0, 0X511);
            goto L_808026C8;
    }
    // 0x808025E4: addiu       $a0, $zero, 0x511
    ctx->r4 = ADD32(0, 0X511);
    // 0x808025E8: b           L_80802800
    // 0x808025EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802800;
    // 0x808025EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808025F0:
    // 0x808025F0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808025F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808025F8: lwc1        $f12, 0x58($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X58);
    // 0x808025FC: lwc1        $f14, 0x34($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X34);
    // 0x80802600: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80802604: lui         $a3, 0x437F
    ctx->r7 = S32(0X437F << 16);
    // 0x80802608: jal         0x800F10B4
    // 0x8080260C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x8080260C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80802610: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80802614: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80802618: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8080261C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80802620: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80802624: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80802628: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8080262C: nop

    // 0x80802630: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80802634: beql        $t7, $zero, L_80802684
    if (ctx->r15 == 0) {
        // 0x80802638: mfc1        $t7, $f6
        ctx->r15 = (int32_t)ctx->f6.u32l;
            goto L_80802684;
    }
    goto skip_0;
    // 0x80802638: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x8080263C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802640: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80802644: sub.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80802648: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8080264C: nop

    // 0x80802650: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80802654: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80802658: nop

    // 0x8080265C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80802660: bne         $t7, $zero, L_80802678
    if (ctx->r15 != 0) {
        // 0x80802664: nop
    
            goto L_80802678;
    }
    // 0x80802664: nop

    // 0x80802668: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8080266C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80802670: b           L_80802690
    // 0x80802674: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80802690;
    // 0x80802674: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80802678:
    // 0x80802678: b           L_80802690
    // 0x8080267C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80802690;
    // 0x8080267C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80802680: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
L_80802684:
    // 0x80802684: nop

    // 0x80802688: bltz        $t7, L_80802678
    if (SIGNED(ctx->r15) < 0) {
        // 0x8080268C: nop
    
            goto L_80802678;
    }
    // 0x8080268C: nop

L_80802690:
    // 0x80802690: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80802694: jal         0x801015D0
    // 0x80802698: sb          $t7, 0x9B($s3)
    MEM_B(0X9B, ctx->r19) = ctx->r15;
    func_801015D0(rdram, ctx);
        goto after_1;
    // 0x80802698: sb          $t7, 0x9B($s3)
    MEM_B(0X9B, ctx->r19) = ctx->r15;
    after_1:
    // 0x8080269C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808026A0: jal         0x800DF744
    // 0x808026A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x808026A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808026A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808026AC: jal         0x800DC128
    // 0x808026B0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800DC128(rdram, ctx);
        goto after_3;
    // 0x808026B0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_3:
    // 0x808026B4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808026B8: jal         0x800DF744
    // 0x808026BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800DF744(rdram, ctx);
        goto after_4;
    // 0x808026BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x808026C0: b           L_80802800
    // 0x808026C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802800;
    // 0x808026C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808026C8:
    // 0x808026C8: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x808026CC: jal         0x800882C0
    // 0x808026D0: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x808026D0: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_5:
    // 0x808026D4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808026D8: blez        $v0, L_808027F0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808026DC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_808027F0;
    }
    // 0x808026DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808026E0: addiu       $s1, $sp, 0x60
    ctx->r17 = ADD32(ctx->r29, 0X60);
L_808026E4:
    // 0x808026E4: jal         0x80088BE8
    // 0x808026E8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    _gspropctrl_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x808026E8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_6:
    // 0x808026EC: lhu         $t8, 0x76($s3)
    ctx->r24 = MEM_HU(ctx->r19, 0X76);
    // 0x808026F0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808026F4: slt         $at, $s0, $s2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x808026F8: srl         $t9, $t8, 7
    ctx->r25 = S32(U32(ctx->r24) >> 7);
    // 0x808026FC: bne         $v0, $t9, L_808027E8
    if (ctx->r2 != ctx->r25) {
        // 0x80802700: nop
    
            goto L_808027E8;
    }
    // 0x80802700: nop

    // 0x80802704: jal         0x80103EAC
    // 0x80802708: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80103EAC(rdram, ctx);
        goto after_7;
    // 0x80802708: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x8080270C: jal         0x800DC0C0
    // 0x80802710: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_8;
    // 0x80802710: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x80802714: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80802718: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080271C: nop

    // 0x80802720: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80802724: jal         0x800DC0C0
    // 0x80802728: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_9;
    // 0x80802728: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x8080272C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80802730: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80802734: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80802738: addiu       $s0, $s3, 0x18
    ctx->r16 = ADD32(ctx->r19, 0X18);
    // 0x8080273C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80802740: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80802744: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80802748: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x8080274C: jal         0x80088C00
    // 0x80802750: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_10;
    // 0x80802750: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_10:
    // 0x80802754: addiu       $s2, $s3, 0x28
    ctx->r18 = ADD32(ctx->r19, 0X28);
    // 0x80802758: addiu       $s1, $s3, 0x4
    ctx->r17 = ADD32(ctx->r19, 0X4);
    // 0x8080275C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80802760: jal         0x800EE7F8
    // 0x80802764: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x80802764: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_11:
    // 0x80802768: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080276C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80802770: jal         0x800F18FC
    // 0x80802774: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    func_800F18FC(rdram, ctx);
        goto after_12;
    // 0x80802774: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_12:
    // 0x80802778: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8080277C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802780: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80802784: swc1        $f8, 0x44($s3)
    MEM_W(0X44, ctx->r19) = ctx->f8.u32l;
    // 0x80802788: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8080278C: jal         0x800EEAD4
    // 0x80802790: swc1        $f10, 0x48($s3)
    MEM_W(0X48, ctx->r19) = ctx->f10.u32l;
    func_800EEAD4(rdram, ctx);
        goto after_13;
    // 0x80802790: swc1        $f10, 0x48($s3)
    MEM_W(0X48, ctx->r19) = ctx->f10.u32l;
    after_13:
    // 0x80802794: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80802798: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080279C: div.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x808027A0: neg.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = -ctx->f2.fl;
    // 0x808027A4: swc1        $f2, 0x38($s3)
    MEM_W(0X38, ctx->r19) = ctx->f2.u32l;
    // 0x808027A8: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x808027AC: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x808027B0: jal         0x800EF214
    // 0x808027B4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    func_800EF214(rdram, ctx);
        goto after_14;
    // 0x808027B4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_14:
    // 0x808027B8: lbu         $t0, 0x65($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X65);
    // 0x808027BC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808027C0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808027C4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x808027C8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808027CC: andi        $t1, $t0, 0xFFFE
    ctx->r9 = ctx->r8 & 0XFFFE;
    // 0x808027D0: jal         0x800DC178
    // 0x808027D4: sb          $t1, 0x65($s3)
    MEM_B(0X65, ctx->r19) = ctx->r9;
    func_800DC178(rdram, ctx);
        goto after_15;
    // 0x808027D4: sb          $t1, 0x65($s3)
    MEM_B(0X65, ctx->r19) = ctx->r9;
    after_15:
    // 0x808027D8: swc1        $f0, 0x34($s3)
    MEM_W(0X34, ctx->r19) = ctx->f0.u32l;
    // 0x808027DC: swc1        $f0, 0x58($s3)
    MEM_W(0X58, ctx->r19) = ctx->f0.u32l;
    // 0x808027E0: b           L_80802800
    // 0x808027E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802800;
    // 0x808027E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808027E8:
    // 0x808027E8: bne         $at, $zero, L_808026E4
    if (ctx->r1 != 0) {
        // 0x808027EC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_808026E4;
    }
    // 0x808027EC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_808027F0:
    // 0x808027F0: jal         0x800FFAB0
    // 0x808027F4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_16;
    // 0x808027F4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_16:
    // 0x808027F8: b           L_80802800
    // 0x808027FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802800;
    // 0x808027FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802800:
    // 0x80802800: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80802804: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80802808: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8080280C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80802810: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80802814: jr          $ra
    // 0x80802818: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80802818: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_800CA810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA810: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x800CA814: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800CA818: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800CA81C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800CA820: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800CA824: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800CA828: nop

    // 0x800CA82C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800CA830: nop

    // 0x800CA834: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800CA838: div.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800CA83C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800CA840: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800CA844: nop

    // 0x800CA848: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800CA84C: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800CA850: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800CA854: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CA858: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x800CA85C: nop

    // 0x800CA860: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800CA864: nop

    // 0x800CA868: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800CA86C: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800CA870: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800CA874: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800CA878: nop

    // 0x800CA87C: sw          $t3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r11;
    // 0x800CA880: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800CA884: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CA888: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800CA88C: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x800CA890: nop

    // 0x800CA894: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800CA898: nop

    // 0x800CA89C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800CA8A0: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800CA8A4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800CA8A8: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800CA8AC: jr          $ra
    // 0x800CA8B0: sw          $t7, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r15;
    return;
    // 0x800CA8B0: sw          $t7, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r15;
;}
RECOMP_FUNC void idtwinkle_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005A8: jal         0x8001B084
    // 0x808005AC: lw          $a0, 0x2C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C);
    heap_free(rdram, ctx);
        goto after_0;
    // 0x808005AC: lw          $a0, 0x2C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C);
    after_0:
    // 0x808005B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005B8: jr          $ra
    // 0x808005BC: nop

    return;
    // 0x808005BC: nop

;}
RECOMP_FUNC void func_80802A90_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802A90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802A94: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x80802A98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802A9C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80802AA0: bne         $a1, $at, L_80802AEC
    if (ctx->r5 != ctx->r1) {
        // 0x80802AA4: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80802AEC;
    }
    // 0x80802AA4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80802AA8: lw          $a0, 0x54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X54);
    // 0x80802AAC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80802AB0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80802AB4: beql        $a0, $zero, L_80802AD0
    if (ctx->r4 == 0) {
        // 0x80802AB8: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80802AD0;
    }
    goto skip_0;
    // 0x80802AB8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_0:
    // 0x80802ABC: jal         0x800863E8
    // 0x80802AC0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80802AC0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80802AC4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80802AC8: sw          $v0, 0x54($a3)
    MEM_W(0X54, ctx->r7) = ctx->r2;
    // 0x80802ACC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80802AD0:
    // 0x80802AD0: jal         0x80089CA8
    // 0x80802AD4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80802AD4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x80802AD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802ADC: jal         0x80101FDC
    // 0x80802AE0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80802AE0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x80802AE4: b           L_80802AF4
    // 0x80802AE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802AF4;
    // 0x80802AE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802AEC:
    // 0x80802AEC: b           L_80802AF4
    // 0x80802AF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802AF4;
    // 0x80802AF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802AF4:
    // 0x80802AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802AF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802AFC: jr          $ra
    // 0x80802B00: nop

    return;
    // 0x80802B00: nop

    // 0x80802B04: nop

    // 0x80802B08: nop

    // 0x80802B0C: nop

;}
RECOMP_FUNC void func_8008DD70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DD70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008DD74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DD78: jal         0x8009E71C
    // 0x8008DD7C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8009E71C(rdram, ctx);
        goto after_0;
    // 0x8008DD7C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x8008DD80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008DD84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008DD88: jr          $ra
    // 0x8008DD8C: nop

    return;
    // 0x8008DD8C: nop

;}
RECOMP_FUNC void func_808000FC_chboggykidshome(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800100: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800108: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080010C: beq         $a1, $at, L_80800130
    if (ctx->r5 == ctx->r1) {
        // 0x80800110: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800130;
    }
    // 0x80800110: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800114: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800118: beq         $a1, $at, L_8080018C
    if (ctx->r5 == ctx->r1) {
        // 0x8080011C: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_8080018C;
    }
    // 0x8080011C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800120: beq         $a1, $at, L_80800144
    if (ctx->r5 == ctx->r1) {
        // 0x80800124: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80800144;
    }
    // 0x80800124: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800128: b           L_80800204
    // 0x8080012C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800204;
    // 0x8080012C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800130:
    // 0x80800130: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800134: jal         0x80102424
    // 0x80800138: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80800138: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080013C: b           L_80800204
    // 0x80800140: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800204;
    // 0x80800140: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800144:
    // 0x80800144: jal         0x808002C0
    // 0x80800148: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_808002C0_chboggykidshome(rdram, ctx);
        goto after_1;
    // 0x80800148: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x8080014C: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x80800150: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80800154: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80800158: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080015C: jal         0x800897C0
    // 0x80800160: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80800160: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800164: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800168: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080016C: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80800170: jal         0x800897E8
    // 0x80800174: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x80800174: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_3:
    // 0x80800178: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080017C: jal         0x80089810
    // 0x80800180: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    _suexpression_entrypoint_17(rdram, ctx);
        goto after_4;
    // 0x80800180: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_4:
    // 0x80800184: b           L_80800204
    // 0x80800188: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800204;
    // 0x80800188: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080018C:
    // 0x8080018C: lw          $v0, 0x6C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X6C);
    // 0x80800190: addiu       $at, $zero, 0x34E
    ctx->r1 = ADD32(0, 0X34E);
    // 0x80800194: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1396, 0X560) << 16);
    // 0x80800198: sll         $t7, $v0, 11
    ctx->r15 = S32(ctx->r2 << 11);
    // 0x8080019C: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x808001A0: beq         $t8, $at, L_808001E8
    if (ctx->r24 == ctx->r1) {
        // 0x808001A4: addiu       $a0, $a0, 0x560
        ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1396, 0X560));
            goto L_808001E8;
    }
    // 0x808001A4: addiu       $a0, $a0, 0x560
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1396, 0X560));
    // 0x808001A8: addiu       $at, $zero, 0x3E4
    ctx->r1 = ADD32(0, 0X3E4);
    // 0x808001AC: beq         $t8, $at, L_808001D4
    if (ctx->r24 == ctx->r1) {
        // 0x808001B0: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1396, 0X550) << 16);
            goto L_808001D4;
    }
    // 0x808001B0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1396, 0X550) << 16);
    // 0x808001B4: addiu       $at, $zero, 0x41D
    ctx->r1 = ADD32(0, 0X41D);
    // 0x808001B8: bne         $t8, $at, L_80800200
    if (ctx->r24 != ctx->r1) {
        // 0x808001BC: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1396, 0X540) << 16);
            goto L_80800200;
    }
    // 0x808001BC: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1396, 0X540) << 16);
    // 0x808001C0: addiu       $a0, $a0, 0x540
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1396, 0X540));
    // 0x808001C4: jal         0x80088090
    // 0x808001C8: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x808001C8: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_5:
    // 0x808001CC: b           L_80800204
    // 0x808001D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800204;
    // 0x808001D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001D4:
    // 0x808001D4: addiu       $a0, $a0, 0x550
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1396, 0X550));
    // 0x808001D8: jal         0x80088090
    // 0x808001DC: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x808001DC: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_6:
    // 0x808001E0: b           L_80800204
    // 0x808001E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800204;
    // 0x808001E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001E8:
    // 0x808001E8: jal         0x80088090
    // 0x808001EC: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x808001EC: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_7:
    // 0x808001F0: b           L_80800204
    // 0x808001F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800204;
    // 0x808001F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808001F8: b           L_80800204
    // 0x808001FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800204;
    // 0x808001FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800200:
    // 0x80800200: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800204:
    // 0x80800204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800208: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080020C: jr          $ra
    // 0x80800210: nop

    return;
    // 0x80800210: nop

;}
RECOMP_FUNC void _chloggo_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800864B0: syscall     329
    recomp_syscall_handler(rdram, ctx, 0x800864B0);
    return;
    // 0x800864B4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void gcnewoption_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014B4: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x808014B8: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x808014BC: jr          $ra
    // 0x808014C0: sh          $a2, 0xB0($t7)
    MEM_H(0XB0, ctx->r15) = ctx->r6;
    return;
    // 0x808014C0: sh          $a2, 0xB0($t7)
    MEM_H(0XB0, ctx->r15) = ctx->r6;
;}
RECOMP_FUNC void func_80804FE4_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804FE4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80804FE8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80804FEC: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80804FF0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80804FF4: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80804FF8: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80804FFC: jal         0x80100094
    // 0x80805000: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80805000: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80805004: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x80805008: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x8080500C: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80805010: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80805014: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80805018: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8080501C: lbu         $s0, 0x48($t7)
    ctx->r16 = MEM_BU(ctx->r15, 0X48);
    // 0x80805020: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80805024: jal         0x800A89F8
    // 0x80805028: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    func_800A89F8(rdram, ctx);
        goto after_1;
    // 0x80805028: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    after_1:
    // 0x8080502C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x80805030: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80805034: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80805038: jal         0x800E8918
    // 0x8080503C: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    func_800E8918(rdram, ctx);
        goto after_2;
    // 0x8080503C: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    after_2:
    // 0x80805040: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80805044: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80805048: beq         $v0, $at, L_80805074
    if (ctx->r2 == ctx->r1) {
        // 0x8080504C: sw          $v0, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r2;
            goto L_80805074;
    }
    // 0x8080504C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80805050: beq         $v0, $zero, L_808052C4
    if (ctx->r2 == 0) {
        // 0x80805054: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808052C4;
    }
    // 0x80805054: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80805058: beq         $v0, $at, L_80805320
    if (ctx->r2 == ctx->r1) {
        // 0x8080505C: lw          $t9, 0x64($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X64);
            goto L_80805320;
    }
    // 0x8080505C: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80805060: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80805064: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80805068: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x8080506C: b           L_80805330
    // 0x80805070: lbu         $v0, 0x49($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X49);
        goto L_80805330;
    // 0x80805070: lbu         $v0, 0x49($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X49);
L_80805074:
    // 0x80805074: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80805078: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8080507C: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80805080: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80805084: addu        $s0, $t0, $t1
    ctx->r16 = ADD32(ctx->r8, ctx->r9);
    // 0x80805088: lbu         $t2, 0x4A($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X4A);
    // 0x8080508C: beql        $t2, $zero, L_808052C8
    if (ctx->r10 == 0) {
        // 0x80805090: lw          $t5, 0x64($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X64);
            goto L_808052C8;
    }
    goto skip_0;
    // 0x80805090: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    skip_0:
    // 0x80805094: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80805098: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080509C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808050A0: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x808050A4: lui         $at, 0x43A7
    ctx->r1 = S32(0X43A7 << 16);
    // 0x808050A8: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    // 0x808050AC: mov.s       $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = ctx->f18.fl;
    // 0x808050B0: bc1tl       L_808050D0
    if (c1cs) {
        // 0x808050B4: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_808050D0;
    }
    goto skip_1;
    // 0x808050B4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    skip_1:
    // 0x808050B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808050BC: nop

    // 0x808050C0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x808050C4: nop

    // 0x808050C8: bc1f        L_808050DC
    if (!c1cs) {
        // 0x808050CC: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_808050DC;
    }
    // 0x808050CC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_808050D0:
    // 0x808050D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808050D4: b           L_80805194
    // 0x808050D8: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
        goto L_80805194;
    // 0x808050D8: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
L_808050DC:
    // 0x808050DC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808050E0: lui         $at, 0x4398
    ctx->r1 = S32(0X4398 << 16);
    // 0x808050E4: c.le.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl <= ctx->f6.fl;
    // 0x808050E8: nop

    // 0x808050EC: bc1fl       L_80805140
    if (!c1cs) {
        // 0x808050F0: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_80805140;
    }
    goto skip_2;
    // 0x808050F0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_2:
    // 0x808050F4: c.le.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl <= ctx->f12.fl;
    // 0x808050F8: nop

    // 0x808050FC: bc1fl       L_80805140
    if (!c1cs) {
        // 0x80805100: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_80805140;
    }
    goto skip_3;
    // 0x80805100: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_3:
    // 0x80805104: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80805108: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080510C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80805110: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80805114: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x80805118: jal         0x800F10B4
    // 0x8080511C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x8080511C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80805120: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80805124: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80805128: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080512C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80805130: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80805134: b           L_80805194
    // 0x80805138: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
        goto L_80805194;
    // 0x80805138: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8080513C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
L_80805140:
    // 0x80805140: nop

    // 0x80805144: c.le.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl <= ctx->f12.fl;
    // 0x80805148: nop

    // 0x8080514C: bc1fl       L_80805198
    if (!c1cs) {
        // 0x80805150: lwc1        $f12, 0x60($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
            goto L_80805198;
    }
    goto skip_4;
    // 0x80805150: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    skip_4:
    // 0x80805154: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x80805158: nop

    // 0x8080515C: bc1fl       L_80805198
    if (!c1cs) {
        // 0x80805160: lwc1        $f12, 0x60($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
            goto L_80805198;
    }
    goto skip_5;
    // 0x80805160: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    skip_5:
    // 0x80805164: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80805168: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080516C: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80805170: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x80805174: jal         0x800F10B4
    // 0x80805178: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x80805178: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x8080517C: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80805180: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80805184: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80805188: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080518C: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80805190: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
L_80805194:
    // 0x80805194: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
L_80805198:
    // 0x80805198: lui         $at, 0x4381
    ctx->r1 = S32(0X4381 << 16);
    // 0x8080519C: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x808051A0: nop

    // 0x808051A4: bc1tl       L_808051C4
    if (c1cs) {
        // 0x808051A8: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_808051C4;
    }
    goto skip_6;
    // 0x808051A8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    skip_6:
    // 0x808051AC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808051B0: nop

    // 0x808051B4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x808051B8: nop

    // 0x808051BC: bc1f        L_808051D0
    if (!c1cs) {
        // 0x808051C0: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_808051D0;
    }
    // 0x808051C0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_808051C4:
    // 0x808051C4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808051C8: b           L_8080525C
    // 0x808051CC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
        goto L_8080525C;
    // 0x808051CC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_808051D0:
    // 0x808051D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808051D4: lui         $at, 0x4364
    ctx->r1 = S32(0X4364 << 16);
    // 0x808051D8: c.le.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl <= ctx->f4.fl;
    // 0x808051DC: nop

    // 0x808051E0: bc1fl       L_8080521C
    if (!c1cs) {
        // 0x808051E4: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_8080521C;
    }
    goto skip_7;
    // 0x808051E4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_7:
    // 0x808051E8: c.le.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl <= ctx->f12.fl;
    // 0x808051EC: nop

    // 0x808051F0: bc1fl       L_8080521C
    if (!c1cs) {
        // 0x808051F4: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_8080521C;
    }
    goto skip_8;
    // 0x808051F4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_8:
    // 0x808051F8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808051FC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80805200: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80805204: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80805208: jal         0x800F10B4
    // 0x8080520C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x8080520C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x80805210: b           L_80805258
    // 0x80805214: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80805258;
    // 0x80805214: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80805218: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
L_8080521C:
    // 0x8080521C: nop

    // 0x80805220: c.le.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl <= ctx->f12.fl;
    // 0x80805224: nop

    // 0x80805228: bc1fl       L_8080525C
    if (!c1cs) {
        // 0x8080522C: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8080525C;
    }
    goto skip_9;
    // 0x8080522C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    skip_9:
    // 0x80805230: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x80805234: nop

    // 0x80805238: bc1fl       L_8080525C
    if (!c1cs) {
        // 0x8080523C: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8080525C;
    }
    goto skip_10;
    // 0x8080523C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    skip_10:
    // 0x80805240: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80805244: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80805248: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8080524C: jal         0x800F10B4
    // 0x80805250: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80805250: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x80805254: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80805258:
    // 0x80805258: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_8080525C:
    // 0x8080525C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80805260: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80805264: c.eq.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl == ctx->f10.fl;
    // 0x80805268: nop

    // 0x8080526C: bc1tl       L_808052C8
    if (c1cs) {
        // 0x80805270: lw          $t5, 0x64($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X64);
            goto L_808052C8;
    }
    goto skip_11;
    // 0x80805270: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    skip_11:
    // 0x80805274: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80805278: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080527C: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80805280: c.eq.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl == ctx->f4.fl;
    // 0x80805284: nop

    // 0x80805288: bc1tl       L_808052C8
    if (c1cs) {
        // 0x8080528C: lw          $t5, 0x64($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X64);
            goto L_808052C8;
    }
    goto skip_12;
    // 0x8080528C: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    skip_12:
    // 0x80805290: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80805294: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80805298: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8080529C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808052A0: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808052A4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x808052A8: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x808052AC: lbu         $v0, 0x49($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X49);
    // 0x808052B0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808052B4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808052B8: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x808052BC: b           L_80805334
    // 0x808052C0: addu        $t1, $v0, $v1
    ctx->r9 = ADD32(ctx->r2, ctx->r3);
        goto L_80805334;
    // 0x808052C0: addu        $t1, $v0, $v1
    ctx->r9 = ADD32(ctx->r2, ctx->r3);
L_808052C4:
    // 0x808052C4: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
L_808052C8:
    // 0x808052C8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x808052CC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808052D0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808052D4: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
    // 0x808052D8: lbu         $v0, 0x49($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X49);
    // 0x808052DC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x808052E0: bgez        $v0, L_808052F4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x808052E4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808052F4;
    }
    // 0x808052E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808052E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808052EC: nop

    // 0x808052F0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_808052F4:
    // 0x808052F4: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808052F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808052FC: nop

    // 0x80805300: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80805304: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80805308: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x8080530C: nop

    // 0x80805310: beql        $v1, $zero, L_80805334
    if (ctx->r3 == 0) {
        // 0x80805314: addu        $t1, $v0, $v1
        ctx->r9 = ADD32(ctx->r2, ctx->r3);
            goto L_80805334;
    }
    goto skip_13;
    // 0x80805314: addu        $t1, $v0, $v1
    ctx->r9 = ADD32(ctx->r2, ctx->r3);
    skip_13:
    // 0x80805318: b           L_80805330
    // 0x8080531C: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
        goto L_80805330;
    // 0x8080531C: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
L_80805320:
    // 0x80805320: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80805324: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80805328: addu        $s0, $t9, $t0
    ctx->r16 = ADD32(ctx->r25, ctx->r8);
    // 0x8080532C: lbu         $v0, 0x49($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X49);
L_80805330:
    // 0x80805330: addu        $t1, $v0, $v1
    ctx->r9 = ADD32(ctx->r2, ctx->r3);
L_80805334:
    // 0x80805334: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x80805338: sb          $t2, 0x49($s0)
    MEM_B(0X49, ctx->r16) = ctx->r10;
    // 0x8080533C: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80805340: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80805344: bnel        $t3, $at, L_808053A8
    if (ctx->r11 != ctx->r1) {
        // 0x80805348: sb          $zero, 0x4A($s0)
        MEM_B(0X4A, ctx->r16) = 0;
            goto L_808053A8;
    }
    goto skip_14;
    // 0x80805348: sb          $zero, 0x4A($s0)
    MEM_B(0X4A, ctx->r16) = 0;
    skip_14:
    // 0x8080534C: jal         0x800E3A58
    // 0x80805350: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800E3A58(rdram, ctx);
        goto after_7;
    // 0x80805350: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_7:
    // 0x80805354: jal         0x800DF830
    // 0x80805358: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF830(rdram, ctx);
        goto after_8;
    // 0x80805358: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x8080535C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80805360: jal         0x800DF744
    // 0x80805364: lh          $a1, 0x36($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X36);
    func_800DF744(rdram, ctx);
        goto after_9;
    // 0x80805364: lh          $a1, 0x36($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X36);
    after_9:
    // 0x80805368: jal         0x800DF410
    // 0x8080536C: lbu         $a0, 0x49($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X49);
    func_800DF410(rdram, ctx);
        goto after_10;
    // 0x8080536C: lbu         $a0, 0x49($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X49);
    after_10:
    // 0x80805370: jal         0x800D674C
    // 0x80805374: addiu       $a0, $zero, 0x954
    ctx->r4 = ADD32(0, 0X954);
    func_800D674C(rdram, ctx);
        goto after_11;
    // 0x80805374: addiu       $a0, $zero, 0x954
    ctx->r4 = ADD32(0, 0X954);
    after_11:
    // 0x80805378: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x8080537C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80805380: addiu       $a1, $s0, 0x3C
    ctx->r5 = ADD32(ctx->r16, 0X3C);
    // 0x80805384: lw          $a3, 0x38($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X38);
    // 0x80805388: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8080538C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80805390: jal         0x800DE498
    // 0x80805394: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800DE498(rdram, ctx);
        goto after_12;
    // 0x80805394: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_12:
    // 0x80805398: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8080539C: b           L_808053A8
    // 0x808053A0: sb          $t5, 0x4A($s0)
    MEM_B(0X4A, ctx->r16) = ctx->r13;
        goto L_808053A8;
    // 0x808053A0: sb          $t5, 0x4A($s0)
    MEM_B(0X4A, ctx->r16) = ctx->r13;
    // 0x808053A4: sb          $zero, 0x4A($s0)
    MEM_B(0X4A, ctx->r16) = 0;
L_808053A8:
    // 0x808053A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808053AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808053B0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x808053B4: jr          $ra
    // 0x808053B8: nop

    return;
    // 0x808053B8: nop

;}
RECOMP_FUNC void func_80800000_chgruntylairexttowerwindow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800004: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void chphlegm_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1064, 0XBA0) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0xBA0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1064, 0XBA0));
    return;
    // 0x80800014: addiu       $v0, $v0, 0xBA0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1064, 0XBA0));
;}
RECOMP_FUNC void func_8080163C_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080163C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801640: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801644: jal         0x8009E6EC
    // 0x80801648: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80801648: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080164C: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80801650: beq         $v0, $at, L_80801678
    if (ctx->r2 == ctx->r1) {
        // 0x80801654: addiu       $at, $zero, 0x1B
        ctx->r1 = ADD32(0, 0X1B);
            goto L_80801678;
    }
    // 0x80801654: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x80801658: beq         $v0, $at, L_80801678
    if (ctx->r2 == ctx->r1) {
        // 0x8080165C: addiu       $at, $zero, 0x29
        ctx->r1 = ADD32(0, 0X29);
            goto L_80801678;
    }
    // 0x8080165C: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x80801660: beq         $v0, $at, L_80801678
    if (ctx->r2 == ctx->r1) {
        // 0x80801664: addiu       $at, $zero, 0x2B
        ctx->r1 = ADD32(0, 0X2B);
            goto L_80801678;
    }
    // 0x80801664: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x80801668: beql        $v0, $at, L_8080167C
    if (ctx->r2 == ctx->r1) {
        // 0x8080166C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080167C;
    }
    goto skip_0;
    // 0x8080166C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801670: jal         0x80099B94
    // 0x80801674: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80099B94(rdram, ctx);
        goto after_1;
    // 0x80801674: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80801678:
    // 0x80801678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080167C:
    // 0x8080167C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801680: jr          $ra
    // 0x80801684: nop

    return;
    // 0x80801684: nop

;}
RECOMP_FUNC void _bsrest_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800839D8: syscall     84
    recomp_syscall_handler(rdram, ctx, 0x800839D8);
    return;
    // 0x800839DC: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void bsjump_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D64: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800D68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800D70: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D74: jal         0x8008CABC
    // 0x80800D78: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800D78: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x80800D7C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800D80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D84: jal         0x8009BB24
    // 0x80800D88: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009BB24(rdram, ctx);
        goto after_1;
    // 0x80800D88: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80800D8C: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x80800D90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D98: beq         $v0, $zero, L_80800DB0
    if (ctx->r2 == 0) {
        // 0x80800D9C: nop
    
            goto L_80800DB0;
    }
    // 0x80800D9C: nop

    // 0x80800DA0: beq         $v0, $at, L_80800DEC
    if (ctx->r2 == ctx->r1) {
        // 0x80800DA4: nop
    
            goto L_80800DEC;
    }
    // 0x80800DA4: nop

    // 0x80800DA8: b           L_80800DEC
    // 0x80800DAC: nop

        goto L_80800DEC;
    // 0x80800DAC: nop

L_80800DB0:
    // 0x80800DB0: jal         0x8008DF8C
    // 0x80800DB4: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_8008DF8C(rdram, ctx);
        goto after_2;
    // 0x80800DB4: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_2:
    // 0x80800DB8: beq         $v0, $zero, L_80800DEC
    if (ctx->r2 == 0) {
        // 0x80800DBC: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80800DEC;
    }
    // 0x80800DBC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800DC0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800DC4: jal         0x8008B1D4
    // 0x80800DC8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    anctrl_setSubrange(rdram, ctx);
        goto after_3;
    // 0x80800DC8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_3:
    // 0x80800DCC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800DD0: jal         0x8008B1BC
    // 0x80800DD4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x80800DD4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_4:
    // 0x80800DD8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800DDC: jal         0x8008B134
    // 0x80800DE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x80800DE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800DE4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800DE8: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_80800DEC:
    // 0x80800DEC: jal         0x8008E078
    // 0x80800DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_6;
    // 0x80800DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800DF4: beq         $v0, $zero, L_80800E04
    if (ctx->r2 == 0) {
        // 0x80800DF8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E04;
    }
    // 0x80800DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DFC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800E00: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80800E04:
    // 0x80800E04: jal         0x8009E5C8
    // 0x80800E08: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_7;
    // 0x80800E08: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x80800E0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800E14: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800E18: jr          $ra
    // 0x80800E1C: nop

    return;
    // 0x80800E1C: nop

;}
RECOMP_FUNC void func_80801920_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801920: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801924: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801928: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080192C: jal         0x80100094
    // 0x80801930: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801930: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801934: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80801938: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080193C: addiu       $t6, $zero, 0x7F
    ctx->r14 = ADD32(0, 0X7F);
    // 0x80801940: sb          $t6, 0x20($v0)
    MEM_B(0X20, ctx->r2) = ctx->r14;
    // 0x80801944: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80801948: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8080194C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80801950: swc1        $f0, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f0.u32l;
    // 0x80801954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801958: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080195C: jr          $ra
    // 0x80801960: nop

    return;
    // 0x80801960: nop

;}
RECOMP_FUNC void func_800906DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800906DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800906E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800906E4: jal         0x800F54E4
    // 0x800906E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800906E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800906EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800906F0: jal         0x800F832C
    // 0x800906F4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F832C(rdram, ctx);
        goto after_1;
    // 0x800906F4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800906F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800906FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090700: jr          $ra
    // 0x80090704: nop

    return;
    // 0x80090704: nop

;}
RECOMP_FUNC void func_800EF368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF368: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EF36C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EF370: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800EF374: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EF378: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EF37C: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EF380: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800EF384: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800EF388: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800EF38C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EF390: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800EF394: add.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800EF398: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    // 0x800EF39C: nop

    // 0x800EF3A0: bc1tl       L_800EF3D0
    if (c1cs) {
        // 0x800EF3A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800EF3D0;
    }
    goto skip_0;
    // 0x800EF3A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800EF3A8: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x800EF3AC: jal         0x8002DCA0
    // 0x800EF3B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800EF3B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800EF3B4: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800EF3B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800EF3BC: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800EF3C0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800EF3C4: jal         0x800EF334
    // 0x800EF3C8: nop

    func_800EF334(rdram, ctx);
        goto after_1;
    // 0x800EF3C8: nop

    after_1:
    // 0x800EF3CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EF3D0:
    // 0x800EF3D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EF3D4: jr          $ra
    // 0x800EF3D8: nop

    return;
    // 0x800EF3D8: nop

;}
RECOMP_FUNC void func_800C0438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0438: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C043C: lw          $t6, -0x75F4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X75F4);
    // 0x800C0440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0448: sll         $t8, $t6, 18
    ctx->r24 = S32(ctx->r14 << 18);
    // 0x800C044C: bgez        $t8, L_800C045C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800C0450: nop
    
            goto L_800C045C;
    }
    // 0x800C0450: nop

    // 0x800C0454: jal         0x800C0308
    // 0x800C0458: nop

    func_800C0308(rdram, ctx);
        goto after_0;
    // 0x800C0458: nop

    after_0:
L_800C045C:
    // 0x800C045C: jal         0x800A819C
    // 0x800C0460: nop

    func_800A819C(rdram, ctx);
        goto after_1;
    // 0x800C0460: nop

    after_1:
    // 0x800C0464: beq         $v0, $zero, L_800C04B8
    if (ctx->r2 == 0) {
        // 0x800C0468: lui         $t9, 0x8013
        ctx->r25 = S32(0X8013 << 16);
            goto L_800C04B8;
    }
    // 0x800C0468: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C046C: lw          $t9, -0x75F4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X75F4);
    // 0x800C0470: sll         $t1, $t9, 18
    ctx->r9 = S32(ctx->r25 << 18);
    // 0x800C0474: bltzl       $t1, L_800C04BC
    if (SIGNED(ctx->r9) < 0) {
        // 0x800C0478: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C04BC;
    }
    goto skip_0;
    // 0x800C0478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C047C: jal         0x800C0638
    // 0x800C0480: nop

    func_800C0638(rdram, ctx);
        goto after_2;
    // 0x800C0480: nop

    after_2:
    // 0x800C0484: bne         $v0, $zero, L_800C04B0
    if (ctx->r2 != 0) {
        // 0x800C0488: lui         $t2, 0x8013
        ctx->r10 = S32(0X8013 << 16);
            goto L_800C04B0;
    }
    // 0x800C0488: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C048C: lbu         $t2, -0x75EF($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X75EF);
    // 0x800C0490: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C0494: srl         $t3, $t2, 4
    ctx->r11 = S32(U32(ctx->r10) >> 4);
    // 0x800C0498: blez        $t3, L_800C04B0
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800C049C: nop
    
            goto L_800C04B0;
    }
    // 0x800C049C: nop

    // 0x800C04A0: jal         0x80087E30
    // 0x800C04A4: addiu       $a0, $a0, -0x7750
    ctx->r4 = ADD32(ctx->r4, -0X7750);
    _gcdialogexec_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x800C04A4: addiu       $a0, $a0, -0x7750
    ctx->r4 = ADD32(ctx->r4, -0X7750);
    after_3:
    // 0x800C04A8: b           L_800C04BC
    // 0x800C04AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800C04BC;
    // 0x800C04AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C04B0:
    // 0x800C04B0: jal         0x800C0284
    // 0x800C04B4: nop

    func_800C0284(rdram, ctx);
        goto after_4;
    // 0x800C04B4: nop

    after_4:
L_800C04B8:
    // 0x800C04B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C04BC:
    // 0x800C04BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C04C0: jr          $ra
    // 0x800C04C4: nop

    return;
    // 0x800C04C4: nop

;}
RECOMP_FUNC void func_80800C28_chmole_training(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C28: lbu         $t6, 0x72($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X72);
    // 0x80800C2C: andi        $t7, $t6, 0xFF03
    ctx->r15 = ctx->r14 & 0XFF03;
    // 0x80800C30: ori         $t8, $t7, 0x34
    ctx->r24 = ctx->r15 | 0X34;
    // 0x80800C34: jr          $ra
    // 0x80800C38: sb          $t8, 0x72($a0)
    MEM_B(0X72, ctx->r4) = ctx->r24;
    return;
    // 0x80800C38: sb          $t8, 0x72($a0)
    MEM_B(0X72, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void _idtwinkle_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088DF0: syscall     742
    recomp_syscall_handler(rdram, ctx, 0x80088DF0);
    return;
    // 0x80088DF4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _subaddiesect_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089F48: syscall     817
    recomp_syscall_handler(rdram, ctx, 0x80089F48);
    return;
    // 0x80089F4C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _gspropctrl_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088BE8: syscall     728
    recomp_syscall_handler(rdram, ctx, 0x80088BE8);
    return;
    // 0x80088BEC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _sujiggy_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A6F0: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A6F0);
    return;
    // 0x8008A6F4: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void _gsmaker_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800825E0: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x800825E0);
    return;
    // 0x800825E4: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void idworldmake_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800984: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800988: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8080098C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800990: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800994: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80800998: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8080099C: lw          $a0, 0x7EF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF8);
    // 0x808009A0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x808009A4: jal         0x800B296C
    // 0x808009A8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    vector_end(rdram, ctx);
        goto after_0;
    // 0x808009A8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x808009AC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x808009B0: lw          $a0, 0x7EF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF8);
    // 0x808009B4: jal         0x800B28C4
    // 0x808009B8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    vector_begin(rdram, ctx);
        goto after_1;
    // 0x808009B8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x808009BC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808009C0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x808009C4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808009C8: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x808009CC: beq         $at, $zero, L_80800A0C
    if (ctx->r1 == 0) {
        // 0x808009D0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800A0C;
    }
    // 0x808009D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808009D4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_808009D8:
    // 0x808009D8: bnel        $a3, $t6, L_80800A00
    if (ctx->r7 != ctx->r14) {
        // 0x808009DC: addiu       $v1, $v1, 0xA8
        ctx->r3 = ADD32(ctx->r3, 0XA8);
            goto L_80800A00;
    }
    goto skip_0;
    // 0x808009DC: addiu       $v1, $v1, 0xA8
    ctx->r3 = ADD32(ctx->r3, 0XA8);
    skip_0:
    // 0x808009E0: lbu         $t7, 0x6($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X6);
    // 0x808009E4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808009E8: sllv        $t9, $t8, $t7
    ctx->r25 = S32(ctx->r24 << (ctx->r15 & 31));
    // 0x808009EC: and         $t0, $t9, $a2
    ctx->r8 = ctx->r25 & ctx->r6;
    // 0x808009F0: bnel        $t0, $zero, L_80800A00
    if (ctx->r8 != 0) {
        // 0x808009F4: addiu       $v1, $v1, 0xA8
        ctx->r3 = ADD32(ctx->r3, 0XA8);
            goto L_80800A00;
    }
    goto skip_1;
    // 0x808009F4: addiu       $v1, $v1, 0xA8
    ctx->r3 = ADD32(ctx->r3, 0XA8);
    skip_1:
    // 0x808009F8: sb          $s0, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r16;
    // 0x808009FC: addiu       $v1, $v1, 0xA8
    ctx->r3 = ADD32(ctx->r3, 0XA8);
L_80800A00:
    // 0x80800A00: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x80800A04: bnel        $at, $zero, L_808009D8
    if (ctx->r1 != 0) {
        // 0x80800A08: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_808009D8;
    }
    goto skip_2;
    // 0x80800A08: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_2:
L_80800A0C:
    // 0x80800A0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800A18: jr          $ra
    // 0x80800A1C: nop

    return;
    // 0x80800A1C: nop

;}
RECOMP_FUNC void _bsdronesuckunder_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083160: syscall     47
    recomp_syscall_handler(rdram, ctx, 0x80083160);
    return;
    // 0x80083164: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800E8DE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8DE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E8DE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8DEC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800E8DF0: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800E8DF4: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800E8DF8: div.s       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800E8DFC: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800E8E00: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x800E8E04: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800E8E08: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800E8E0C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800E8E10: nop

    // 0x800E8E14: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800E8E18: nop

    // 0x800E8E1C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800E8E20: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x800E8E24: jal         0x800E8E3C
    // 0x800E8E28: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    func_800E8E3C(rdram, ctx);
        goto after_0;
    // 0x800E8E28: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x800E8E2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E8E30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E8E34: jr          $ra
    // 0x800E8E38: nop

    return;
    // 0x800E8E38: nop

;}
RECOMP_FUNC void func_8080089C_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080089C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008A4: jal         0x8009BC6C
    // 0x808008A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baphysics_reset_gravity(rdram, ctx);
        goto after_0;
    // 0x808008A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808008AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808008B0: jal         0x8009BF5C
    // 0x808008B4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_1;
    // 0x808008B4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x808008B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808008BC: jal         0x8009C4CC
    // 0x808008C0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_2;
    // 0x808008C0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x808008C4: jal         0x80800198
    // 0x808008C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bssnowball_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808008C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808008CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008D4: jr          $ra
    // 0x808008D8: nop

    return;
    // 0x808008D8: nop

;}
RECOMP_FUNC void func_8009FF00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009FF00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009FF04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009FF08: jal         0x80084720
    // 0x8009FF0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _badata_entrypoint_28(rdram, ctx);
        goto after_0;
    // 0x8009FF0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009FF10: beq         $v0, $zero, L_8009FF34
    if (ctx->r2 == 0) {
        // 0x8009FF14: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8009FF34;
    }
    // 0x8009FF14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8009FF18: jal         0x8009BB5C
    // 0x8009FF1C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8009BB5C(rdram, ctx);
        goto after_1;
    // 0x8009FF1C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8009FF20: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8009FF24: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8009FF28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8009FF2C: jalr        $v1
    // 0x8009FF30: nop

    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_2;
    // 0x8009FF30: nop

    after_2:
L_8009FF34:
    // 0x8009FF34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009FF38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009FF3C: jr          $ra
    // 0x8009FF40: nop

    return;
    // 0x8009FF40: nop

;}
RECOMP_FUNC void func_80108DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108DC0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80108DC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80108DC8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80108DCC: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80108DD0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80108DD4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80108DD8: jal         0x80108C90
    // 0x80108DDC: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    func_80108C90(rdram, ctx);
        goto after_0;
    // 0x80108DDC: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    after_0:
    // 0x80108DE0: beq         $v0, $zero, L_80108EB0
    if (ctx->r2 == 0) {
        // 0x80108DE4: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80108EB0;
    }
    // 0x80108DE4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80108DE8: jal         0x80108CF4
    // 0x80108DEC: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    func_80108CF4(rdram, ctx);
        goto after_1;
    // 0x80108DEC: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_1:
    // 0x80108DF0: beq         $v0, $zero, L_80108E14
    if (ctx->r2 == 0) {
        // 0x80108DF4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80108E14;
    }
    // 0x80108DF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80108DF8: jal         0x80088BF0
    // 0x80108DFC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    _gspropctrl_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80108DFC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_2:
    // 0x80108E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80108E04: jal         0x800884A0
    // 0x80108E08: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    _glsplinefind_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80108E08: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_3:
    // 0x80108E0C: b           L_80108E20
    // 0x80108E10: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80108E20;
    // 0x80108E10: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80108E14:
    // 0x80108E14: jal         0x80088490
    // 0x80108E18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _glsplinefind_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80108E18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80108E1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80108E20:
    // 0x80108E20: bltz        $v0, L_80108EB0
    if (SIGNED(ctx->r2) < 0) {
        // 0x80108E24: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80108EB0;
    }
    // 0x80108E24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80108E28: jal         0x8010556C
    // 0x80108E2C: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    func_8010556C(rdram, ctx);
        goto after_5;
    // 0x80108E2C: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_5:
    // 0x80108E30: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80108E34: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80108E38: lh          $t0, 0x2($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X2);
    // 0x80108E3C: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x80108E40: andi        $t9, $t8, 0x7FE
    ctx->r25 = ctx->r24 & 0X7FE;
    // 0x80108E44: andi        $t1, $t0, 0xF801
    ctx->r9 = ctx->r8 & 0XF801;
    // 0x80108E48: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80108E4C: sh          $t2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r10;
    // 0x80108E50: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80108E54: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80108E58: nop

    // 0x80108E5C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80108E60: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80108E64: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80108E68: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80108E6C: nop

    // 0x80108E70: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80108E74: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x80108E78: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x80108E7C: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80108E80: nop

    // 0x80108E84: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80108E88: jal         0x800D7520
    // 0x80108E8C: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    func_800D7520(rdram, ctx);
        goto after_6;
    // 0x80108E8C: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    after_6:
    // 0x80108E90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80108E94: jal         0x800C82CC
    // 0x80108E98: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800C82CC(rdram, ctx);
        goto after_7;
    // 0x80108E98: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_7:
    // 0x80108E9C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80108EA0: swc1        $f0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f0.u32l;
    // 0x80108EA4: lbu         $t8, 0x77($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X77);
    // 0x80108EA8: ori         $t0, $t8, 0x10
    ctx->r8 = ctx->r24 | 0X10;
    // 0x80108EAC: sb          $t0, 0x77($s1)
    MEM_B(0X77, ctx->r17) = ctx->r8;
L_80108EB0:
    // 0x80108EB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80108EB4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80108EB8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80108EBC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80108EC0: jr          $ra
    // 0x80108EC4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80108EC4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80108EC8: nop

    // 0x80108ECC: nop

;}
RECOMP_FUNC void _chpowerhut_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086048: syscall     274
    recomp_syscall_handler(rdram, ctx, 0x80086048);
    return;
    // 0x8008604C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80802FEC_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802FEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802FF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802FF4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80802FF8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802FFC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80803000: jal         0x80100094
    // 0x80803004: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803004: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803008: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8080300C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80803010: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80803014: sb          $t6, 0x40($v0)
    MEM_B(0X40, ctx->r2) = ctx->r14;
    // 0x80803018: sb          $a1, 0x43($v0)
    MEM_B(0X43, ctx->r2) = ctx->r5;
    // 0x8080301C: jal         0x80803424
    // 0x80803020: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80803424_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80803020: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80803024: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80803028: jal         0x800F54E4
    // 0x8080302C: sh          $v0, 0x44($t7)
    MEM_H(0X44, ctx->r15) = ctx->r2;
    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x8080302C: sh          $v0, 0x44($t7)
    MEM_H(0X44, ctx->r15) = ctx->r2;
    after_2:
    // 0x80803030: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803034: jal         0x800F7F98
    // 0x80803038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_3;
    // 0x80803038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8080303C: jal         0x800F54E4
    // 0x80803040: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x80803040: nop

    after_4:
    // 0x80803044: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80803048: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080304C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80803050: jal         0x800F8300
    // 0x80803054: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_800F8300(rdram, ctx);
        goto after_5;
    // 0x80803054: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_5:
    // 0x80803058: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080305C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80803060: jal         0x80803BE8
    // 0x80803064: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_6;
    // 0x80803064: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
    // 0x80803068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080306C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803070: jr          $ra
    // 0x80803074: nop

    return;
    // 0x80803074: nop

;}
RECOMP_FUNC void chfairgroundworker_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(840, 0X350) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x350
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(840, 0X350));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x350
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(840, 0X350));
;}
RECOMP_FUNC void func_8080021C_chdingpot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080021C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800220: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800224: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800228: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080022C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800230: beq         $a1, $at, L_8080027C
    if (ctx->r5 == ctx->r1) {
        // 0x80800234: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8080027C;
    }
    // 0x80800234: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800238: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x8080023C: beq         $a1, $at, L_80800258
    if (ctx->r5 == ctx->r1) {
        // 0x80800240: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80800258;
    }
    // 0x80800240: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800244: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800248: beq         $a1, $at, L_80800268
    if (ctx->r5 == ctx->r1) {
        // 0x8080024C: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1176, 0X5A4) << 16);
            goto L_80800268;
    }
    // 0x8080024C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1176, 0X5A4) << 16);
    // 0x80800250: b           L_808002A4
    // 0x80800254: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002A4;
    // 0x80800254: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800258:
    // 0x80800258: jal         0x80102424
    // 0x8080025C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x8080025C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800260: b           L_808002A4
    // 0x80800264: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002A4;
    // 0x80800264: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800268:
    // 0x80800268: addiu       $a0, $a0, 0x5A4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1176, 0X5A4));
    // 0x8080026C: jal         0x80088090
    // 0x80800270: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800270: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_1:
    // 0x80800274: b           L_808002A4
    // 0x80800278: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002A4;
    // 0x80800278: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080027C:
    // 0x8080027C: jal         0x800F54E4
    // 0x80800280: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80800280: nop

    after_2:
    // 0x80800284: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800288: jal         0x800F7F98
    // 0x8080028C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_3;
    // 0x8080028C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800290: b           L_808002A4
    // 0x80800294: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808002A4;
    // 0x80800294: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80800298: b           L_808002A4
    // 0x8080029C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002A4;
    // 0x8080029C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808002A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002A4:
    // 0x808002A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002AC: jr          $ra
    // 0x808002B0: nop

    return;
    // 0x808002B0: nop

;}
RECOMP_FUNC void sujiggy_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800758: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080075C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800760: addiu       $a0, $zero, 0xD57
    ctx->r4 = ADD32(0, 0XD57);
    // 0x80800764: jal         0x800DA564
    // 0x80800768: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x80800768: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8080076C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800770: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800774: jr          $ra
    // 0x80800778: nop

    return;
    // 0x80800778: nop

;}
RECOMP_FUNC void func_808004F4_ch2dbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004FC: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800500: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800504: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800508: beq         $t6, $at, L_80800520
    if (ctx->r14 == ctx->r1) {
        // 0x8080050C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800520;
    }
    // 0x8080050C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800510: beq         $t6, $at, L_80800520
    if (ctx->r14 == ctx->r1) {
        // 0x80800514: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80800520;
    }
    // 0x80800514: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800518: bnel        $t6, $at, L_80800558
    if (ctx->r14 != ctx->r1) {
        // 0x8080051C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800558;
    }
    goto skip_0;
    // 0x8080051C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80800520:
    // 0x80800520: jal         0x8008A4A8
    // 0x80800524: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _subaddieDll_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800524: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800528: beq         $v0, $zero, L_80800538
    if (ctx->r2 == 0) {
        // 0x8080052C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800538;
    }
    // 0x8080052C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800530: b           L_8080053C
    // 0x80800534: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
        goto L_8080053C;
    // 0x80800534: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
L_80800538:
    // 0x80800538: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
L_8080053C:
    // 0x8080053C: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x80800540: jal         0x8008A128
    // 0x80800544: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    _sucoaster_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800544: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800548: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080054C: jal         0x8008A148
    // 0x80800550: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800550: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800558:
    // 0x80800558: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080055C: jr          $ra
    // 0x80800560: nop

    return;
    // 0x80800560: nop

;}
RECOMP_FUNC void _sulights_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A8D0: syscall     854
    recomp_syscall_handler(rdram, ctx, 0x8008A8D0);
    return;
    // 0x8008A8D4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_808005B0_bsbeefly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005B8: jal         0x8009E6EC
    // 0x808005BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x808005BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808005C0: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x808005C4: bne         $v0, $at, L_808005E8
    if (ctx->r2 != ctx->r1) {
        // 0x808005C8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808005E8;
    }
    // 0x808005C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808005CC: jal         0x80084598
    // 0x808005D0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _baboost_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808005D0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_1:
    // 0x808005D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808005D8: jal         0x8009E830
    // 0x808005DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_2;
    // 0x808005DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x808005E0: b           L_808005F4
    // 0x808005E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808005F4;
    // 0x808005E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005E8:
    // 0x808005E8: jal         0x80099B94
    // 0x808005EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80099B94(rdram, ctx);
        goto after_3;
    // 0x808005EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808005F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005F4:
    // 0x808005F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005F8: jr          $ra
    // 0x808005FC: nop

    return;
    // 0x808005FC: nop

;}
RECOMP_FUNC void func_80800818_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800818: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080081C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800820: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800824: or          $t7, $a0, $zero
    ctx->r15 = ctx->r4 | 0;
    // 0x80800828: ori         $t6, $a2, 0x4
    ctx->r14 = ctx->r6 | 0X4;
    // 0x8080082C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80800830: addiu       $t8, $zero, 0x6F
    ctx->r24 = ADD32(0, 0X6F);
    // 0x80800834: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80800838: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8080083C: jal         0x8008A208
    // 0x80800840: addiu       $a3, $t7, 0x4
    ctx->r7 = ADD32(ctx->r15, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80800840: addiu       $a3, $t7, 0x4
    ctx->r7 = ADD32(ctx->r15, 0X4);
    after_0:
    // 0x80800844: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80800848: lbu         $t0, 0x74($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X74);
    // 0x8080084C: ori         $t1, $t0, 0x40
    ctx->r9 = ctx->r8 | 0X40;
    // 0x80800850: sb          $t1, 0x74($v0)
    MEM_B(0X74, ctx->r2) = ctx->r9;
    // 0x80800854: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800858: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080085C: jr          $ra
    // 0x80800860: nop

    return;
    // 0x80800860: nop

;}
RECOMP_FUNC void bsdronejump_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080000C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800010: lwc1        $f4, 0x194($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X194);
    // 0x80800014: lw          $a3, 0x190($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X190);
    // 0x80800018: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080001C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800020: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800024: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800028: jal         0x800F10B4
    // 0x8080002C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x8080002C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80800030: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800034: jal         0x8008C990
    // 0x80800038: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8008C990(rdram, ctx);
        goto after_1;
    // 0x80800038: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8080003C: jal         0x80084DD0
    // 0x80800040: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _bamovegoto_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800040: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80800044: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800048: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080004C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800050: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80800054: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800058: jal         0x80013970
    // 0x8080005C: nop

    func_80013970(rdram, ctx);
        goto after_3;
    // 0x8080005C: nop

    after_3:
    // 0x80800060: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800064: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800068: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080006C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800070: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80800074: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800078: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8080007C: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80800080: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80800084: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800088: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080008C: jr          $ra
    // 0x80800090: nop

    return;
    // 0x80800090: nop

;}
RECOMP_FUNC void func_8009AD90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009AD90: lw          $t6, 0xC4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC4);
    // 0x8009AD94: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8009AD98: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
    // 0x8009AD9C: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x8009ADA0: lw          $t7, 0xC4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC4);
    // 0x8009ADA4: sb          $zero, 0x1($t7)
    MEM_B(0X1, ctx->r15) = 0;
    // 0x8009ADA8: lw          $t8, 0xC4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC4);
    // 0x8009ADAC: sb          $zero, 0x2($t8)
    MEM_B(0X2, ctx->r24) = 0;
L_8009ADB0:
    // 0x8009ADB0: lw          $t9, 0xC4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC4);
    // 0x8009ADB4: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x8009ADB8: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x8009ADBC: lw          $t1, 0xC4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC4);
    // 0x8009ADC0: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8009ADC4: sb          $zero, 0x1($t2)
    MEM_B(0X1, ctx->r10) = 0;
    // 0x8009ADC8: lw          $t3, 0xC4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC4);
    // 0x8009ADCC: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8009ADD0: sb          $zero, 0x2($t4)
    MEM_B(0X2, ctx->r12) = 0;
    // 0x8009ADD4: lw          $t5, 0xC4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0XC4);
    // 0x8009ADD8: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8009ADDC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8009ADE0: bne         $v0, $v1, L_8009ADB0
    if (ctx->r2 != ctx->r3) {
        // 0x8009ADE4: sb          $zero, 0x3($t6)
        MEM_B(0X3, ctx->r14) = 0;
            goto L_8009ADB0;
    }
    // 0x8009ADE4: sb          $zero, 0x3($t6)
    MEM_B(0X3, ctx->r14) = 0;
    // 0x8009ADE8: jr          $ra
    // 0x8009ADEC: nop

    return;
    // 0x8009ADEC: nop

;}
RECOMP_FUNC void func_80804E34_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804E34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80804E38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804E3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80804E40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804E44: lw          $a0, 0x28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X28);
    // 0x80804E48: jal         0x80801658
    // 0x80804E4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801658_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80804E4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80804E50: jal         0x800883A0
    // 0x80804E54: nop

    _gcstatusDll_entrypoint_18(rdram, ctx);
        goto after_1;
    // 0x80804E54: nop

    after_1:
    // 0x80804E58: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80804E5C: bne         $v0, $at, L_80804E6C
    if (ctx->r2 != ctx->r1) {
        // 0x80804E60: nop
    
            goto L_80804E6C;
    }
    // 0x80804E60: nop

    // 0x80804E64: b           L_80804EC4
    // 0x80804E68: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
        goto L_80804EC4;
    // 0x80804E68: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
L_80804E6C:
    // 0x80804E6C: jal         0x800883A0
    // 0x80804E70: nop

    _gcstatusDll_entrypoint_18(rdram, ctx);
        goto after_2;
    // 0x80804E70: nop

    after_2:
    // 0x80804E74: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80804E78: bne         $v0, $at, L_80804E88
    if (ctx->r2 != ctx->r1) {
        // 0x80804E7C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80804E88;
    }
    // 0x80804E7C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80804E80: b           L_80804EC4
    // 0x80804E84: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
        goto L_80804EC4;
    // 0x80804E84: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
L_80804E88:
    // 0x80804E88: jal         0x80088398
    // 0x80804E8C: nop

    _gcstatusDll_entrypoint_17(rdram, ctx);
        goto after_3;
    // 0x80804E8C: nop

    after_3:
    // 0x80804E90: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80804E94: bne         $v0, $at, L_80804EA4
    if (ctx->r2 != ctx->r1) {
        // 0x80804E98: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80804EA4;
    }
    // 0x80804E98: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80804E9C: b           L_80804EC4
    // 0x80804EA0: sw          $t7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r15;
        goto L_80804EC4;
    // 0x80804EA0: sw          $t7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r15;
L_80804EA4:
    // 0x80804EA4: jal         0x80088398
    // 0x80804EA8: nop

    _gcstatusDll_entrypoint_17(rdram, ctx);
        goto after_4;
    // 0x80804EA8: nop

    after_4:
    // 0x80804EAC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80804EB0: bne         $v0, $at, L_80804EC0
    if (ctx->r2 != ctx->r1) {
        // 0x80804EB4: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_80804EC0;
    }
    // 0x80804EB4: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80804EB8: b           L_80804EC4
    // 0x80804EBC: sw          $t8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r24;
        goto L_80804EC4;
    // 0x80804EBC: sw          $t8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r24;
L_80804EC0:
    // 0x80804EC0: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
L_80804EC4:
    // 0x80804EC4: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80804EC8: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x80804ECC: jal         0x800AA0B8
    // 0x80804ED0: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    func_800AA0B8(rdram, ctx);
        goto after_5;
    // 0x80804ED0: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    after_5:
    // 0x80804ED4: beq         $v0, $zero, L_80804EEC
    if (ctx->r2 == 0) {
        // 0x80804ED8: nop
    
            goto L_80804EEC;
    }
    // 0x80804ED8: nop

    // 0x80804EDC: jal         0x808065C0
    // 0x80804EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808065C0_chgameselect(rdram, ctx);
        goto after_6;
    // 0x80804EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80804EE4: b           L_80804F04
    // 0x80804EE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80804F04;
    // 0x80804EE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804EEC:
    // 0x80804EEC: jal         0x80805310
    // 0x80804EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80805310_chgameselect(rdram, ctx);
        goto after_7;
    // 0x80804EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80804EF4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80804EF8: jal         0x80803D00
    // 0x80804EFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80803D00_chgameselect(rdram, ctx);
        goto after_8;
    // 0x80804EFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80804F00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804F04:
    // 0x80804F04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804F08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80804F0C: jr          $ra
    // 0x80804F10: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x80804F10: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
;}
RECOMP_FUNC void bsride_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005A4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808005A8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(348, 0XA70) << 16);
    // 0x808005AC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808005B0: jr          $ra
    // 0x808005B4: lw          $v0, 0xA70($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(348, 0XA70));
    return;
    // 0x808005B4: lw          $v0, 0xA70($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(348, 0XA70));
;}
