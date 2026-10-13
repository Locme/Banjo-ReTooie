#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _bahitspline_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D58: syscall     135
    recomp_syscall_handler(rdram, ctx, 0x80084D58);
    return;
    // 0x80084D5C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _plcamera_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800878F0: syscall     639
    recomp_syscall_handler(rdram, ctx, 0x800878F0);
    return;
    // 0x800878F4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void bsdronelook_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080005C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800060: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800064: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800068: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080006C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800070: jal         0x80084658
    // 0x80800074: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    _badata_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800074: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080007C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800080: jal         0x8008CB3C
    // 0x80800084: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80800084: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800088: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8080008C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800094: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800098: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080009C: jal         0x8009FFD8
    // 0x808000A0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x808000A0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A8: jal         0x8009B9B0
    // 0x808000AC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x808000AC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: jal         0x8009BA9C
    // 0x808000B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_4;
    // 0x808000B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808000BC: jal         0x80084C98
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000C4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000C8: beql        $v0, $at, L_80800124
    if (ctx->r2 == ctx->r1) {
        // 0x808000CC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800124;
    }
    goto skip_0;
    // 0x808000CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808000D0: jal         0x800A4E94
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4E94(rdram, ctx);
        goto after_6;
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808000D8: jal         0x800A3274
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3274(rdram, ctx);
        goto after_7;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808000E0: addiu       $t7, $v0, -0x2
    ctx->r15 = ADD32(ctx->r2, -0X2);
    // 0x808000E4: sltiu       $at, $t7, 0x12
    ctx->r1 = ctx->r15 < 0X12 ? 1 : 0;
    // 0x808000E8: beq         $at, $zero, L_80800114
    if (ctx->r1 == 0) {
        // 0x808000EC: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800114;
    }
    // 0x808000EC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808000F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(188, 0X230) << 16);
    // 0x808000F4: addu        $at, $at, $t7
    gpr jr_addend_808000FC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808000F8: lw          $t7, 0x230($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(188, 0X230));
    // 0x808000FC: jr          $t7
    // 0x80800100: nop

    switch (jr_addend_808000FC >> 2) {
        case 0: goto L_80800104; break;
        case 1: goto L_80800114; break;
        case 2: goto L_80800114; break;
        case 3: goto L_80800114; break;
        case 4: goto L_80800114; break;
        case 5: goto L_80800114; break;
        case 6: goto L_80800104; break;
        case 7: goto L_80800114; break;
        case 8: goto L_80800104; break;
        case 9: goto L_80800114; break;
        case 10: goto L_80800114; break;
        case 11: goto L_80800104; break;
        case 12: goto L_80800104; break;
        case 13: goto L_80800104; break;
        case 14: goto L_80800104; break;
        case 15: goto L_80800104; break;
        case 16: goto L_80800104; break;
        case 17: goto L_80800104; break;
        default: switch_error(__func__, 0x808000FC, 0x80800230);
    }
    // 0x80800100: nop

L_80800104:
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800108: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080010C: jal         0x80084CD0
    // 0x80800110: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _bafpctrl_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80800110: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
L_80800114:
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800118: jal         0x80084CF8
    // 0x8080011C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _bafpctrl_entrypoint_16(rdram, ctx);
        goto after_9;
    // 0x8080011C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x80800120: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800124:
    // 0x80800124: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800128: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080012C: jr          $ra
    // 0x80800130: nop

    return;
    // 0x80800130: nop

;}
RECOMP_FUNC void func_80800098_chmumbopad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080009C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000A0: lw          $v1, 0x6C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6C);
    // 0x808000A4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x808000A8: andi        $t6, $v1, 0x1FF
    ctx->r14 = ctx->r3 & 0X1FF;
    // 0x808000AC: beq         $t6, $at, L_808000C8
    if (ctx->r14 == ctx->r1) {
        // 0x808000B0: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_808000C8;
    }
    // 0x808000B0: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x808000B4: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x808000B8: beq         $t6, $at, L_808000F0
    if (ctx->r14 == ctx->r1) {
        // 0x808000BC: addiu       $a0, $zero, 0x1CA
        ctx->r4 = ADD32(0, 0X1CA);
            goto L_808000F0;
    }
    // 0x808000BC: addiu       $a0, $zero, 0x1CA
    ctx->r4 = ADD32(0, 0X1CA);
    // 0x808000C0: b           L_80800104
    // 0x808000C4: sll         $t0, $v1, 1
    ctx->r8 = S32(ctx->r3 << 1);
        goto L_80800104;
    // 0x808000C4: sll         $t0, $v1, 1
    ctx->r8 = S32(ctx->r3 << 1);
L_808000C8:
    // 0x808000C8: jal         0x800DA298
    // 0x808000CC: addiu       $a0, $zero, 0x358
    ctx->r4 = ADD32(0, 0X358);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808000CC: addiu       $a0, $zero, 0x358
    ctx->r4 = ADD32(0, 0X358);
    after_0:
    // 0x808000D0: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x808000D4: beq         $t7, $zero, L_80800130
    if (ctx->r15 == 0) {
        // 0x808000D8: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80800130;
    }
    // 0x808000D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x808000DC: jal         0x800DA298
    // 0x808000E0: addiu       $a0, $zero, 0x359
    ctx->r4 = ADD32(0, 0X359);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808000E0: addiu       $a0, $zero, 0x359
    ctx->r4 = ADD32(0, 0X359);
    after_1:
    // 0x808000E4: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x808000E8: b           L_80800130
    // 0x808000EC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_80800130;
    // 0x808000EC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_808000F0:
    // 0x808000F0: jal         0x800DA564
    // 0x808000F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DA564(rdram, ctx);
        goto after_2;
    // 0x808000F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x808000F8: sltu        $t9, $zero, $v0
    ctx->r25 = 0 < ctx->r2 ? 1 : 0;
    // 0x808000FC: b           L_80800130
    // 0x80800100: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_80800130;
    // 0x80800100: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80800104:
    // 0x80800104: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1720, 0X10EC) << 16);
    // 0x80800108: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x8080010C: lh          $a0, 0x10EC($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1720, 0X10EC));
    // 0x80800110: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800114: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800118: beq         $a0, $at, L_80800130
    if (ctx->r4 == ctx->r1) {
        // 0x8080011C: nop
    
            goto L_80800130;
    }
    // 0x8080011C: nop

    // 0x80800120: jal         0x800DA298
    // 0x80800124: nop

    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800124: nop

    after_3:
    // 0x80800128: b           L_80800134
    // 0x8080012C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800134;
    // 0x8080012C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800130:
    // 0x80800130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800134:
    // 0x80800134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800138: jr          $ra
    // 0x8080013C: nop

    return;
    // 0x8080013C: nop

;}
RECOMP_FUNC void func_800DB67C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DB67C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DB680: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DB684: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DB688: jal         0x800DACD0
    // 0x800DB68C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800DACD0(rdram, ctx);
        goto after_0;
    // 0x800DB68C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800DB690: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800DB694: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800DB698: srl         $a2, $v0, 1
    ctx->r6 = S32(U32(ctx->r2) >> 1);
    // 0x800DB69C: slti        $at, $a2, 0xF
    ctx->r1 = SIGNED(ctx->r6) < 0XF ? 1 : 0;
    // 0x800DB6A0: bne         $at, $zero, L_800DB6AC
    if (ctx->r1 != 0) {
        // 0x800DB6A4: nop
    
            goto L_800DB6AC;
    }
    // 0x800DB6A4: nop

    // 0x800DB6A8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
L_800DB6AC:
    // 0x800DB6AC: blez        $a2, L_800DB7B0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800DB6B0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800DB7B0;
    }
    // 0x800DB6B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800DB6B4: andi        $a3, $a2, 0x3
    ctx->r7 = ctx->r6 & 0X3;
    // 0x800DB6B8: beq         $a3, $zero, L_800DB708
    if (ctx->r7 == 0) {
        // 0x800DB6BC: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_800DB708;
    }
    // 0x800DB6BC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800DB6C0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800DB6C4: addiu       $t8, $t8, -0x3860
    ctx->r24 = ADD32(ctx->r24, -0X3860);
    // 0x800DB6C8: sll         $t7, $zero, 2
    ctx->r15 = S32(0 << 2);
    // 0x800DB6CC: sll         $t9, $zero, 1
    ctx->r25 = S32(0 << 1);
    // 0x800DB6D0: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x800DB6D4: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
L_800DB6D8:
    // 0x800DB6D8: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x800DB6DC: lbu         $t1, 0x1($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X1);
    // 0x800DB6E0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800DB6E4: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x800DB6E8: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x800DB6EC: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800DB6F0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800DB6F4: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800DB6F8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800DB6FC: bne         $a1, $a0, L_800DB6D8
    if (ctx->r5 != ctx->r4) {
        // 0x800DB700: swc1        $f6, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f6.u32l;
            goto L_800DB6D8;
    }
    // 0x800DB700: swc1        $f6, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f6.u32l;
    // 0x800DB704: beq         $a0, $a2, L_800DB7B0
    if (ctx->r4 == ctx->r6) {
        // 0x800DB708: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800DB7B0;
    }
L_800DB708:
    // 0x800DB708: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800DB70C: addiu       $t6, $t6, -0x3860
    ctx->r14 = ADD32(ctx->r14, -0X3860);
    // 0x800DB710: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x800DB714: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x800DB718: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800DB71C: addu        $a1, $t8, $t6
    ctx->r5 = ADD32(ctx->r24, ctx->r14);
    // 0x800DB720: addu        $v0, $t7, $t0
    ctx->r2 = ADD32(ctx->r15, ctx->r8);
    // 0x800DB724: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
L_800DB728:
    // 0x800DB728: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x800DB72C: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x800DB730: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800DB734: sll         $t1, $t2, 8
    ctx->r9 = S32(ctx->r10 << 8);
    // 0x800DB738: or          $t3, $t9, $t1
    ctx->r11 = ctx->r25 | ctx->r9;
    // 0x800DB73C: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800DB740: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800DB744: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800DB748: swc1        $f10, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f10.u32l;
    // 0x800DB74C: lbu         $t5, -0x6($v0)
    ctx->r13 = MEM_BU(ctx->r2, -0X6);
    // 0x800DB750: lbu         $t4, -0x5($v0)
    ctx->r12 = MEM_BU(ctx->r2, -0X5);
    // 0x800DB754: sll         $t7, $t5, 8
    ctx->r15 = S32(ctx->r13 << 8);
    // 0x800DB758: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800DB75C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800DB760: nop

    // 0x800DB764: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800DB768: swc1        $f18, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f18.u32l;
    // 0x800DB76C: lbu         $t2, -0x4($v0)
    ctx->r10 = MEM_BU(ctx->r2, -0X4);
    // 0x800DB770: lbu         $t6, -0x3($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0X3);
    // 0x800DB774: sll         $t9, $t2, 8
    ctx->r25 = S32(ctx->r10 << 8);
    // 0x800DB778: or          $t1, $t6, $t9
    ctx->r9 = ctx->r14 | ctx->r25;
    // 0x800DB77C: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800DB780: nop

    // 0x800DB784: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800DB788: swc1        $f6, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f6.u32l;
    // 0x800DB78C: lbu         $t5, -0x2($v0)
    ctx->r13 = MEM_BU(ctx->r2, -0X2);
    // 0x800DB790: lbu         $t3, -0x1($v0)
    ctx->r11 = MEM_BU(ctx->r2, -0X1);
    // 0x800DB794: sll         $t4, $t5, 8
    ctx->r12 = S32(ctx->r13 << 8);
    // 0x800DB798: or          $t7, $t3, $t4
    ctx->r15 = ctx->r11 | ctx->r12;
    // 0x800DB79C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800DB7A0: nop

    // 0x800DB7A4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800DB7A8: bne         $v1, $a1, L_800DB728
    if (ctx->r3 != ctx->r5) {
        // 0x800DB7AC: swc1        $f10, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
            goto L_800DB728;
    }
    // 0x800DB7AC: swc1        $f10, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
L_800DB7B0:
    // 0x800DB7B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DB7B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DB7B8: jr          $ra
    // 0x800DB7BC: nop

    return;
    // 0x800DB7BC: nop

;}
RECOMP_FUNC void func_800AC848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC848: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800AC84C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800AC850: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800AC854: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800AC858: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800AC85C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800AC860: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x800AC864: jal         0x80019CD4
    // 0x800AC868: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    func_80019CD4(rdram, ctx);
        goto after_0;
    // 0x800AC868: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    after_0:
    // 0x800AC86C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AC870: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800AC874: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x800AC878: jal         0x8001980C
    // 0x800AC87C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8001980C(rdram, ctx);
        goto after_1;
    // 0x800AC87C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x800AC880: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800AC884: jal         0x80019224
    // 0x800AC888: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    func_80019224(rdram, ctx);
        goto after_2;
    // 0x800AC888: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    after_2:
    // 0x800AC88C: addiu       $s1, $sp, 0x40
    ctx->r17 = ADD32(ctx->r29, 0X40);
    // 0x800AC890: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800AC894: jal         0x80019224
    // 0x800AC898: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    func_80019224(rdram, ctx);
        goto after_3;
    // 0x800AC898: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    after_3:
    // 0x800AC89C: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800AC8A0: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800AC8A4: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x800AC8A8: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x800AC8AC: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AC8B0: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x800AC8B4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800AC8B8: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x800AC8BC: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x800AC8C0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800AC8C4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800AC8C8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800AC8CC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800AC8D0: jal         0x800AC638
    // 0x800AC8D4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800AC638(rdram, ctx);
        goto after_4;
    // 0x800AC8D4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x800AC8D8: bne         $v0, $zero, L_800AC8E8
    if (ctx->r2 != 0) {
        // 0x800AC8DC: sw          $v0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r2;
            goto L_800AC8E8;
    }
    // 0x800AC8DC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800AC8E0: b           L_800AC964
    // 0x800AC8E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AC964;
    // 0x800AC8E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AC8E8:
    // 0x800AC8E8: jal         0x80019CD4
    // 0x800AC8EC: nop

    func_80019CD4(rdram, ctx);
        goto after_5;
    // 0x800AC8EC: nop

    after_5:
    // 0x800AC8F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AC8F4: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800AC8F8: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x800AC8FC: jal         0x80019750
    // 0x800AC900: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80019750(rdram, ctx);
        goto after_6;
    // 0x800AC900: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x800AC904: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x800AC908: jal         0x80019224
    // 0x800AC90C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80019224(rdram, ctx);
        goto after_7;
    // 0x800AC90C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x800AC910: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800AC914: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800AC918: addiu       $s1, $s1, 0x795C
    ctx->r17 = ADD32(ctx->r17, 0X795C);
    // 0x800AC91C: addiu       $s0, $s0, 0x7938
    ctx->r16 = ADD32(ctx->r16, 0X7938);
    // 0x800AC920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800AC924:
    // 0x800AC924: jal         0x80019224
    // 0x800AC928: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80019224(rdram, ctx);
        goto after_8;
    // 0x800AC928: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x800AC92C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800AC930: bnel        $s0, $s1, L_800AC924
    if (ctx->r16 != ctx->r17) {
        // 0x800AC934: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800AC924;
    }
    goto skip_0;
    // 0x800AC934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x800AC938: jal         0x80019CD4
    // 0x800AC93C: nop

    func_80019CD4(rdram, ctx);
        goto after_9;
    // 0x800AC93C: nop

    after_9:
    // 0x800AC940: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AC944: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800AC948: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800AC94C: jal         0x80019750
    // 0x800AC950: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80019750(rdram, ctx);
        goto after_10;
    // 0x800AC950: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x800AC954: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800AC958: jal         0x80019224
    // 0x800AC95C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80019224(rdram, ctx);
        goto after_11;
    // 0x800AC95C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_11:
    // 0x800AC960: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_800AC964:
    // 0x800AC964: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800AC968: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800AC96C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800AC970: jr          $ra
    // 0x800AC974: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800AC974: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80800404_chsunlightspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800404: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800408: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x8080040C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800410: sltiu       $at, $t7, 0x9
    ctx->r1 = ctx->r15 < 0X9 ? 1 : 0;
    // 0x80800414: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800418: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080041C: beq         $at, $zero, L_80800648
    if (ctx->r1 == 0) {
        // 0x80800420: sw          $a1, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r5;
            goto L_80800648;
    }
    // 0x80800420: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800424: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800428: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2244, 0X868) << 16);
    // 0x8080042C: addu        $at, $at, $t7
    gpr jr_addend_80800434 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800430: lw          $t7, 0x868($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2244, 0X868));
    // 0x80800434: jr          $t7
    // 0x80800438: nop

    switch (jr_addend_80800434 >> 2) {
        case 0: goto L_8080043C; break;
        case 1: goto L_8080044C; break;
        case 2: goto L_8080046C; break;
        case 3: goto L_80800530; break;
        case 4: goto L_80800550; break;
        case 5: goto L_80800570; break;
        case 6: goto L_808005A4; break;
        case 7: goto L_808005CC; break;
        case 8: goto L_808005EC; break;
        default: switch_error(__func__, 0x80800434, 0x80800868);
    }
    // 0x80800438: nop

L_8080043C:
    // 0x8080043C: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80800440: andi        $t9, $t8, 0xFFF7
    ctx->r25 = ctx->r24 & 0XFFF7;
    // 0x80800444: b           L_80800648
    // 0x80800448: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
        goto L_80800648;
    // 0x80800448: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
L_8080044C:
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800450: jal         0x80103110
    // 0x80800454: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_0;
    // 0x80800454: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800458: lbu         $t0, 0x7A($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X7A);
    // 0x8080045C: andi        $t1, $t0, 0xFF3F
    ctx->r9 = ctx->r8 & 0XFF3F;
    // 0x80800460: ori         $t2, $t1, 0x80
    ctx->r10 = ctx->r9 | 0X80;
    // 0x80800464: b           L_80800648
    // 0x80800468: sb          $t2, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r10;
        goto L_80800648;
    // 0x80800468: sb          $t2, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r10;
L_8080046C:
    // 0x8080046C: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2244, 0X8A4) << 16);
    // 0x80800470: addiu       $t4, $t4, 0x8A4
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2244, 0X8A4));
    // 0x80800474: lw          $at, 0x0($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X0);
    // 0x80800478: addiu       $t3, $sp, 0x34
    ctx->r11 = ADD32(ctx->r29, 0X34);
    // 0x8080047C: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
    // 0x80800480: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x80800484: lw          $at, 0x8($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X8);
    // 0x80800488: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8080048C: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x80800490: jal         0x80086C68
    // 0x80800494: sw          $at, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r1;
    _chmumbopad_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800494: sw          $at, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r1;
    after_1:
    // 0x80800498: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x8080049C: sra         $t7, $a3, 16
    ctx->r15 = S32(SIGNED(ctx->r7) >> 16);
    // 0x808004A0: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x808004A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808004AC: jal         0x80089840
    // 0x808004B0: addiu       $a2, $zero, 0x2E
    ctx->r6 = ADD32(0, 0X2E);
    _sumumbofx_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808004B0: addiu       $a2, $zero, 0x2E
    ctx->r6 = ADD32(0, 0X2E);
    after_2:
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B8: jal         0x80100094
    // 0x808004BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x808004BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808004C0: jal         0x80089850
    // 0x808004C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x808004C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004CC: jal         0x80100094
    // 0x808004D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x808004D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808004D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004D8: jal         0x800898B8
    // 0x808004DC: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_15(rdram, ctx);
        goto after_6;
    // 0x808004DC: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_6:
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E4: jal         0x80100094
    // 0x808004E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_7;
    // 0x808004E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808004EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004F0: jal         0x80089900
    // 0x808004F4: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    _sumumbofx_entrypoint_24(rdram, ctx);
        goto after_8;
    // 0x808004F4: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_8:
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004FC: jal         0x80100094
    // 0x80800500: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_9;
    // 0x80800500: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800504: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800508: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080050C: jal         0x80089908
    // 0x80800510: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    _sumumbofx_entrypoint_25(rdram, ctx);
        goto after_10;
    // 0x80800510: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_10:
    // 0x80800514: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800518: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080051C: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80800520: jal         0x80085708
    // 0x80800524: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _capod_entrypoint_13(rdram, ctx);
        goto after_11;
    // 0x80800524: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_11:
    // 0x80800528: b           L_8080064C
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080064C;
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800530:
    // 0x80800530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800534: jal         0x80100094
    // 0x80800538: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_12;
    // 0x80800538: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x8080053C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800540: jal         0x800898D0
    // 0x80800544: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    _sumumbofx_entrypoint_18(rdram, ctx);
        goto after_13;
    // 0x80800544: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    after_13:
    // 0x80800548: b           L_8080064C
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080064C;
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800550:
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800554: jal         0x80100094
    // 0x80800558: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_14;
    // 0x80800558: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x8080055C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800560: jal         0x800898C8
    // 0x80800564: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _sumumbofx_entrypoint_17(rdram, ctx);
        goto after_15;
    // 0x80800564: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_15:
    // 0x80800568: b           L_8080064C
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080064C;
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800570:
    // 0x80800570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800574: jal         0x80100094
    // 0x80800578: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_16;
    // 0x80800578: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x8080057C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800580: jal         0x800898C8
    // 0x80800584: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    _sumumbofx_entrypoint_17(rdram, ctx);
        goto after_17;
    // 0x80800584: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    after_17:
    // 0x80800588: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x8080058C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2244, 0X88C) << 16);
    // 0x80800590: ori         $t0, $t9, 0x8
    ctx->r8 = ctx->r25 | 0X8;
    // 0x80800594: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x80800598: lwc1        $f4, 0x88C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2244, 0X88C));
    // 0x8080059C: b           L_80800648
    // 0x808005A0: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
        goto L_80800648;
    // 0x808005A0: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
L_808005A4:
    // 0x808005A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A8: jal         0x80100094
    // 0x808005AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_18;
    // 0x808005AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x808005B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005B4: jal         0x800898C8
    // 0x808005B8: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    _sumumbofx_entrypoint_17(rdram, ctx);
        goto after_19;
    // 0x808005B8: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    after_19:
    // 0x808005BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808005C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005C4: b           L_80800648
    // 0x808005C8: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
        goto L_80800648;
    // 0x808005C8: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
L_808005CC:
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D0: jal         0x80100094
    // 0x808005D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_20;
    // 0x808005D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x808005D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005DC: jal         0x800898C0
    // 0x808005E0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_16(rdram, ctx);
        goto after_21;
    // 0x808005E0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_21:
    // 0x808005E4: b           L_8080064C
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080064C;
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808005EC:
    // 0x808005EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F0: jal         0x80089848
    // 0x808005F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _sumumbofx_entrypoint_1(rdram, ctx);
        goto after_22;
    // 0x808005F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x808005F8: jal         0x800DA524
    // 0x808005FC: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA524(rdram, ctx);
        goto after_23;
    // 0x808005FC: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_23:
    // 0x80800600: jal         0x800DA544
    // 0x80800604: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    func_800DA544(rdram, ctx);
        goto after_24;
    // 0x80800604: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    after_24:
    // 0x80800608: jal         0x800DA544
    // 0x8080060C: addiu       $a0, $zero, 0xE9
    ctx->r4 = ADD32(0, 0XE9);
    func_800DA544(rdram, ctx);
        goto after_25;
    // 0x8080060C: addiu       $a0, $zero, 0xE9
    ctx->r4 = ADD32(0, 0XE9);
    after_25:
    // 0x80800610: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800614: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x80800618: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8080061C: addiu       $a1, $zero, 0x1035
    ctx->r5 = ADD32(0, 0X1035);
    // 0x80800620: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80800624: jal         0x8008A208
    // 0x80800628: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_26;
    // 0x80800628: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_26:
    // 0x8080062C: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800634: andi        $t5, $t2, 0xFFFE
    ctx->r13 = ctx->r10 & 0XFFFE;
    // 0x80800638: jal         0x80089D40
    // 0x8080063C: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_27;
    // 0x8080063C: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    after_27:
    // 0x80800640: jal         0x800FFAB0
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_28;
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
L_80800648:
    // 0x80800648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080064C:
    // 0x8080064C: jal         0x80102424
    // 0x80800650: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80102424(rdram, ctx);
        goto after_29;
    // 0x80800650: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_29:
    // 0x80800654: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800658: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080065C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800660: jr          $ra
    // 0x80800664: nop

    return;
    // 0x80800664: nop

;}
RECOMP_FUNC void func_808009EC_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808009F0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808009F4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808009F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800A00: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80800A04: jal         0x80100094
    // 0x80800A08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800A08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800A0C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800A10: addiu       $at, $zero, 0x1345
    ctx->r1 = ADD32(0, 0X1345);
    // 0x80800A14: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800A18: beq         $a2, $at, L_80800A5C
    if (ctx->r6 == ctx->r1) {
        // 0x80800A1C: addiu       $at, $zero, 0x1347
        ctx->r1 = ADD32(0, 0X1347);
            goto L_80800A5C;
    }
    // 0x80800A1C: addiu       $at, $zero, 0x1347
    ctx->r1 = ADD32(0, 0X1347);
    // 0x80800A20: beq         $a2, $at, L_80800A40
    if (ctx->r6 == ctx->r1) {
        // 0x80800A24: addiu       $at, $zero, 0x1375
        ctx->r1 = ADD32(0, 0X1375);
            goto L_80800A40;
    }
    // 0x80800A24: addiu       $at, $zero, 0x1375
    ctx->r1 = ADD32(0, 0X1375);
    // 0x80800A28: beq         $a2, $at, L_80800A64
    if (ctx->r6 == ctx->r1) {
        // 0x80800A2C: addiu       $at, $zero, 0x1385
        ctx->r1 = ADD32(0, 0X1385);
            goto L_80800A64;
    }
    // 0x80800A2C: addiu       $at, $zero, 0x1385
    ctx->r1 = ADD32(0, 0X1385);
    // 0x80800A30: beq         $a2, $at, L_80800A64
    if (ctx->r6 == ctx->r1) {
        // 0x80800A34: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800A64;
    }
    // 0x80800A34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800A38: b           L_80800A74
    // 0x80800A3C: nop

        goto L_80800A74;
    // 0x80800A3C: nop

L_80800A40:
    // 0x80800A40: jal         0x800F54E4
    // 0x80800A44: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800A44: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80800A48: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A4C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80800A50: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80800A54: b           L_80800A74
    // 0x80800A58: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
        goto L_80800A74;
    // 0x80800A58: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
L_80800A5C:
    // 0x80800A5C: b           L_80800A74
    // 0x80800A60: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
        goto L_80800A74;
    // 0x80800A60: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
L_80800A64:
    // 0x80800A64: jal         0x800D211C
    // 0x80800A68: addiu       $a0, $zero, 0x83
    ctx->r4 = ADD32(0, 0X83);
    func_800D211C(rdram, ctx);
        goto after_2;
    // 0x80800A68: addiu       $a0, $zero, 0x83
    ctx->r4 = ADD32(0, 0X83);
    after_2:
    // 0x80800A6C: b           L_80800A78
    // 0x80800A70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800A78;
    // 0x80800A70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A74:
    // 0x80800A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A78:
    // 0x80800A78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A7C: jr          $ra
    // 0x80800A80: nop

    return;
    // 0x80800A80: nop

;}
RECOMP_FUNC void bafly_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007D8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808007DC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808007E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808007E8: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x808007EC: bne         $a1, $zero, L_80800810
    if (ctx->r5 != 0) {
        // 0x808007F0: sw          $a3, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r7;
            goto L_80800810;
    }
    // 0x808007F0: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x808007F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(528, 0XDA8) << 16);
    // 0x808007F8: lwc1        $f4, 0xDA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(528, 0XDA8));
    // 0x808007FC: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80800800: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800804: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x80800808: b           L_80800828
    // 0x8080080C: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
        goto L_80800828;
    // 0x8080080C: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
L_80800810:
    // 0x80800810: lui         $at, 0xC496
    ctx->r1 = S32(0XC496 << 16);
    // 0x80800814: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800818: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8080081C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800820: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x80800824: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
L_80800828:
    // 0x80800828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080082C: jal         0x8009C128
    // 0x80800830: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800830: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_0:
    // 0x80800834: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x80800838: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8080083C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800840: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800844: jal         0x800E1610
    // 0x80800848: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    func_800E1610(rdram, ctx);
        goto after_1;
    // 0x80800848: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    after_1:
    // 0x8080084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800850: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x80800854: jal         0x8008CDB8
    // 0x80800858: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    baanim_playForDuration_once(rdram, ctx);
        goto after_2;
    // 0x80800858: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    after_2:
    // 0x8080085C: jal         0x8009D9D4
    // 0x80800860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D9D4(rdram, ctx);
        goto after_3;
    // 0x80800860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800864: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800868: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080086C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800870: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80800874: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800878: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8080087C: jal         0x80085490
    // 0x80800880: nop

    _bamotor_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800880: nop

    after_4:
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800888: jal         0x800A32C4
    // 0x8080088C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800A32C4(rdram, ctx);
        goto after_5;
    // 0x8080088C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_5:
    // 0x80800890: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80800894: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80800898: jal         0x800F1E6C
    // 0x8080089C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_800F1E6C(rdram, ctx);
        goto after_6;
    // 0x8080089C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_6:
    // 0x808008A0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808008A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808008A8: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808008AC: jal         0x800136E4
    // 0x808008B0: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    func_800136E4(rdram, ctx);
        goto after_7;
    // 0x808008B0: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_7:
    // 0x808008B4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808008B8: jal         0x8009C914
    // 0x808008BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_8;
    // 0x808008BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808008C0: jal         0x8009C974
    // 0x808008C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_9;
    // 0x808008C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808008C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008CC: jal         0x8009B9B0
    // 0x808008D0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_10;
    // 0x808008D0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_10:
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D8: jal         0x8009B9C0
    // 0x808008DC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    baphysics_set_target_yaw(rdram, ctx);
        goto after_11;
    // 0x808008DC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_11:
    // 0x808008E0: jal         0x8009BB00
    // 0x808008E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_12;
    // 0x808008E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808008E8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008F0: jal         0x8009BA68
    // 0x808008F4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_13;
    // 0x808008F4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_13:
    // 0x808008F8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x808008FC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800904: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800908: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080090C: jal         0x8009FFD8
    // 0x80800910: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_14;
    // 0x80800910: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_14:
    // 0x80800914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800918: jal         0x8009BA58
    // 0x8080091C: lui         $a1, 0x4448
    ctx->r5 = S32(0X4448 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_15;
    // 0x8080091C: lui         $a1, 0x4448
    ctx->r5 = S32(0X4448 << 16);
    after_15:
    // 0x80800920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800924: jal         0x8009BCB4
    // 0x80800928: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    baphysics_set_gravity(rdram, ctx);
        goto after_16;
    // 0x80800928: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_16:
    // 0x8080092C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800930: jal         0x8009BCC4
    // 0x80800934: lui         $a1, 0xC57A
    ctx->r5 = S32(0XC57A << 16);
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_17;
    // 0x80800934: lui         $a1, 0xC57A
    ctx->r5 = S32(0XC57A << 16);
    after_17:
    // 0x80800938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080093C: jal         0x800A4DA4
    // 0x80800940: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800A4DA4(rdram, ctx);
        goto after_18;
    // 0x80800940: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_18:
    // 0x80800944: jal         0x800A4CA8
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_19;
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8080094C: lui         $a2, 0x461C
    ctx->r6 = S32(0X461C << 16);
    // 0x80800950: ori         $a2, $a2, 0x4000
    ctx->r6 = ctx->r6 | 0X4000;
    // 0x80800954: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800958: lui         $a1, 0x4140
    ctx->r5 = S32(0X4140 << 16);
    // 0x8080095C: jal         0x800892E0
    // 0x80800960: lui         $a3, 0x4448
    ctx->r7 = S32(0X4448 << 16);
    _ncbafly_entrypoint_4(rdram, ctx);
        goto after_20;
    // 0x80800960: lui         $a3, 0x4448
    ctx->r7 = S32(0X4448 << 16);
    after_20:
    // 0x80800964: jal         0x8008E944
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_21;
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x8080096C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800970: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800974: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800978: jr          $ra
    // 0x8080097C: nop

    return;
    // 0x8080097C: nop

;}
RECOMP_FUNC void func_80802080_sucoasterfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802080: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802084: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802088: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080208C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802090: jal         0x80100094
    // 0x80802094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802098: lbu         $a0, 0x11($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X11);
    // 0x8080209C: srl         $t6, $a0, 4
    ctx->r14 = S32(U32(ctx->r4) >> 4);
    // 0x808020A0: jal         0x8008A270
    // 0x808020A4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    _sucoasterflydata_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808020A4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x808020A8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808020AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808020B0: jal         0x80100094
    // 0x808020B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808020B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808020B8: bne         $v0, $zero, L_80802114
    if (ctx->r2 != 0) {
        // 0x808020BC: lw          $t7, 0x20($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X20);
            goto L_80802114;
    }
    // 0x808020BC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x808020C0: jal         0x80089790
    // 0x808020C4: lbu         $a0, 0x3($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X3);
    _suexpression_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808020C4: lbu         $a0, 0x3($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X3);
    after_3:
    // 0x808020C8: beq         $v0, $zero, L_80802114
    if (ctx->r2 == 0) {
        // 0x808020CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802114;
    }
    // 0x808020CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808020D0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x808020D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808020D8: jal         0x800897C0
    // 0x808020DC: lh          $a2, 0x2($t8)
    ctx->r6 = MEM_H(ctx->r24, 0X2);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x808020DC: lh          $a2, 0x2($t8)
    ctx->r6 = MEM_H(ctx->r24, 0X2);
    after_4:
    // 0x808020E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808020E4: jal         0x80100094
    // 0x808020E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x808020E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808020EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808020F0: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x808020F4: jal         0x800897E8
    // 0x808020F8: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_6;
    // 0x808020F8: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_6:
    // 0x808020FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802100: jal         0x80100094
    // 0x80802104: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_7;
    // 0x80802104: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80802108: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080210C: jal         0x80089810
    // 0x80802110: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    _suexpression_entrypoint_17(rdram, ctx);
        goto after_8;
    // 0x80802110: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    after_8:
L_80802114:
    // 0x80802114: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802118: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080211C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802120: jr          $ra
    // 0x80802124: nop

    return;
    // 0x80802124: nop

;}
RECOMP_FUNC void _bstnt_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083FB8: syscall     99
    recomp_syscall_handler(rdram, ctx, 0x80083FB8);
    return;
    // 0x80083FBC: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_80800210_chsilo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800210: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800214: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080021C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800220: jal         0x80087D98
    // 0x80800224: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    _gcnewoption_entrypoint_32(rdram, ctx);
        goto after_0;
    // 0x80800224: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    after_0:
    // 0x80800228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080022C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800230: jr          $ra
    // 0x80800234: nop

    return;
    // 0x80800234: nop

;}
RECOMP_FUNC void _bacough_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084610: syscall     117
    recomp_syscall_handler(rdram, ctx, 0x80084610);
    return;
    // 0x80084614: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_80801E24_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801E24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801E28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801E2C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801E30: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801E34: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80801E38: jal         0x80100094
    // 0x80801E3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801E3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801E40: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80801E44: lbu         $t6, 0x1CD($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1CD);
    // 0x80801E48: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80801E4C: beq         $t6, $zero, L_80801E5C
    if (ctx->r14 == 0) {
        // 0x80801E50: ori         $t8, $t7, 0x2000
        ctx->r24 = ctx->r15 | 0X2000;
            goto L_80801E5C;
    }
    // 0x80801E50: ori         $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 | 0X2000;
    // 0x80801E54: jal         0x80085710
    // 0x80801E58: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    _capod_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x80801E58: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    after_1:
L_80801E5C:
    // 0x80801E5C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80801E60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801E64: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80801E68: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80801E6C: jal         0x80085708
    // 0x80801E70: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x80801E70: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_2:
    // 0x80801E74: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80801E78: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80801E7C: sb          $t0, 0x1CD($t1)
    MEM_B(0X1CD, ctx->r9) = ctx->r8;
    // 0x80801E80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801E84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801E88: jr          $ra
    // 0x80801E8C: nop

    return;
    // 0x80801E8C: nop

;}
RECOMP_FUNC void func_800C9588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9588: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800C958C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800C9590: jr          $ra
    // 0x800C9594: nop

    return;
    // 0x800C9594: nop

;}
RECOMP_FUNC void func_8080216C_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080216C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802170: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80802174: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80802178: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080217C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802180: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802184: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80802188: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
L_8080218C:
    // 0x8080218C: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80802190: beql        $a0, $zero, L_808021A8
    if (ctx->r4 == 0) {
        // 0x80802194: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_808021A8;
    }
    goto skip_0;
    // 0x80802194: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_0:
    // 0x80802198: jal         0x800C8B84
    // 0x8080219C: nop

    func_800C8B84(rdram, ctx);
        goto after_0;
    // 0x8080219C: nop

    after_0:
    // 0x808021A0: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x808021A4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_808021A8:
    // 0x808021A8: bne         $s1, $s2, L_8080218C
    if (ctx->r17 != ctx->r18) {
        // 0x808021AC: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8080218C;
    }
    // 0x808021AC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808021B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808021B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808021B8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808021BC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808021C0: jr          $ra
    // 0x808021C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808021C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_808004EC_chcablecar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808004F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004F4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808004F8: jal         0x80100094
    // 0x808004FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808004FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800500: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(972, 0XE90) << 16);
    // 0x80800504: lwc1        $f14, 0xE90($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(972, 0XE90));
    // 0x80800508: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8080050C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800510: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(972, 0XE94) << 16);
    // 0x80800514: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80800518: nop

    // 0x8080051C: bc1f        L_8080052C
    if (!c1cs) {
        // 0x80800520: nop
    
            goto L_8080052C;
    }
    // 0x80800520: nop

    // 0x80800524: b           L_80800570
    // 0x80800528: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80800570;
    // 0x80800528: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8080052C:
    // 0x8080052C: lwc1        $f2, 0xE94($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(972, 0XE94));
    // 0x80800530: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800534: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800538: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8080053C: nop

    // 0x80800540: bc1fl       L_80800554
    if (!c1cs) {
        // 0x80800544: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_80800554;
    }
    goto skip_0;
    // 0x80800544: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_0:
    // 0x80800548: b           L_80800570
    // 0x8080054C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
        goto L_80800570;
    // 0x8080054C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80800550: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_80800554:
    // 0x80800554: lwc1        $f12, 0xC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80800558: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8080055C: jal         0x800F10B4
    // 0x80800560: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800560: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80800564: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800568: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8080056C: nop

L_80800570:
    // 0x80800570: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800574: jal         0x801015D0
    // 0x80800578: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_801015D0(rdram, ctx);
        goto after_2;
    // 0x80800578: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_2:
    // 0x8080057C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800580: jal         0x800DF6BC
    // 0x80800584: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    func_800DF6BC(rdram, ctx);
        goto after_3;
    // 0x80800584: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_3:
    // 0x80800588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080058C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800590: jr          $ra
    // 0x80800594: nop

    return;
    // 0x80800594: nop

;}
RECOMP_FUNC void func_80800030_bskazstill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800034: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800038: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080003C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800040: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x80800044: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080004C: bne         $t6, $zero, L_80800088
    if (ctx->r14 != 0) {
        // 0x80800050: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80800088;
    }
    // 0x80800050: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800054: sw          $zero, 0x160($a0)
    MEM_W(0X160, ctx->r4) = 0;
    // 0x80800058: sw          $zero, 0x164($a0)
    MEM_W(0X164, ctx->r4) = 0;
    // 0x8080005C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80800060: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800064: jal         0x8009FFD8
    // 0x80800068: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_0;
    // 0x80800068: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800070: jal         0x8009B9B0
    // 0x80800074: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_1;
    // 0x80800074: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x80800078: jal         0x800909CC
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800909CC(rdram, ctx);
        goto after_2;
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800080: jal         0x8009F258
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_func_8009F258(rdram, ctx);
        goto after_3;
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80800088:
    // 0x80800088: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8080008C: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
    // 0x80800090: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80800094: sltiu       $at, $t9, 0x6
    ctx->r1 = ctx->r25 < 0X6 ? 1 : 0;
    // 0x80800098: beq         $at, $zero, L_80800190
    if (ctx->r1 == 0) {
        // 0x8080009C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80800190;
    }
    // 0x8080009C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808000A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(288, 0X880) << 16);
    // 0x808000A4: addu        $at, $at, $t9
    gpr jr_addend_808000AC = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x808000A8: lw          $t9, 0x880($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(288, 0X880));
    // 0x808000AC: jr          $t9
    // 0x808000B0: nop

    switch (jr_addend_808000AC >> 2) {
        case 0: goto L_80800190; break;
        case 1: goto L_808000B4; break;
        case 2: goto L_808000CC; break;
        case 3: goto L_808000E4; break;
        case 4: goto L_80800100; break;
        case 5: goto L_8080011C; break;
        default: switch_error(__func__, 0x808000AC, 0x80800880);
    }
    // 0x808000B0: nop

L_808000B4:
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B8: addiu       $a1, $zero, 0xA4
    ctx->r5 = ADD32(0, 0XA4);
    // 0x808000BC: jal         0x8008CCBC
    // 0x808000C0: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_4;
    // 0x808000C0: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    after_4:
    // 0x808000C4: b           L_80800194
    // 0x808000C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800194;
    // 0x808000C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000CC:
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D0: addiu       $a1, $zero, 0xA5
    ctx->r5 = ADD32(0, 0XA5);
    // 0x808000D4: jal         0x8008CCBC
    // 0x808000D8: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_5;
    // 0x808000D8: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    after_5:
    // 0x808000DC: b           L_80800194
    // 0x808000E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800194;
    // 0x808000E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000E4:
    // 0x808000E4: lui         $a2, 0x40B6
    ctx->r6 = S32(0X40B6 << 16);
    // 0x808000E8: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F0: jal         0x8008CCBC
    // 0x808000F4: addiu       $a1, $zero, 0xAC
    ctx->r5 = ADD32(0, 0XAC);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_6;
    // 0x808000F4: addiu       $a1, $zero, 0xAC
    ctx->r5 = ADD32(0, 0XAC);
    after_6:
    // 0x808000F8: b           L_80800194
    // 0x808000FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800194;
    // 0x808000FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800100:
    // 0x80800100: lui         $a2, 0x40A9
    ctx->r6 = S32(0X40A9 << 16);
    // 0x80800104: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: jal         0x8008CCBC
    // 0x80800110: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_7;
    // 0x80800110: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    after_7:
    // 0x80800114: b           L_80800194
    // 0x80800118: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800194;
    // 0x80800118: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080011C:
    // 0x8080011C: jal         0x80084FE0
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800124: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800128: beq         $v0, $at, L_80800150
    if (ctx->r2 == ctx->r1) {
        // 0x8080012C: sw          $v0, 0x168($s0)
        MEM_W(0X168, ctx->r16) = ctx->r2;
            goto L_80800150;
    }
    // 0x8080012C: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x80800130: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800134: beq         $v0, $at, L_80800168
    if (ctx->r2 == ctx->r1) {
        // 0x80800138: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800168;
    }
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800140: beq         $v0, $at, L_80800180
    if (ctx->r2 == ctx->r1) {
        // 0x80800144: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800180;
    }
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800148: b           L_80800194
    // 0x8080014C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800194;
    // 0x8080014C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800150:
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800154: addiu       $a1, $zero, 0xA4
    ctx->r5 = ADD32(0, 0XA4);
    // 0x80800158: jal         0x8008CB3C
    // 0x8080015C: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_9;
    // 0x8080015C: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    after_9:
    // 0x80800160: b           L_80800194
    // 0x80800164: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800194;
    // 0x80800164: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800168:
    // 0x80800168: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x8080016C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800170: jal         0x8008CB3C
    // 0x80800174: addiu       $a1, $zero, 0x24E
    ctx->r5 = ADD32(0, 0X24E);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_10;
    // 0x80800174: addiu       $a1, $zero, 0x24E
    ctx->r5 = ADD32(0, 0X24E);
    after_10:
    // 0x80800178: b           L_80800194
    // 0x8080017C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800194;
    // 0x8080017C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800180:
    // 0x80800180: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x80800184: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800188: jal         0x8008CB3C
    // 0x8080018C: addiu       $a1, $zero, 0x24B
    ctx->r5 = ADD32(0, 0X24B);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_11;
    // 0x8080018C: addiu       $a1, $zero, 0x24B
    ctx->r5 = ADD32(0, 0X24B);
    after_11:
L_80800190:
    // 0x80800190: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800194:
    // 0x80800194: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800198: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080019C: jr          $ra
    // 0x808001A0: nop

    return;
    // 0x808001A0: nop

;}
RECOMP_FUNC void sumumbofx_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800250: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800254: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80800258: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8080025C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80800260: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80800264: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80800268: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8080026C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80800270: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800274: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800278: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8080027C: lh          $t6, 0x58($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X58);
    // 0x80800280: mtc1        $a1, $f26
    ctx->f26.u32l = ctx->r5;
    // 0x80800284: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800288: addiu       $s0, $a0, 0x64
    ctx->r16 = ADD32(ctx->r4, 0X64);
    // 0x8080028C: blez        $t6, L_80800338
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800290: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80800338;
    }
    // 0x80800290: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800294: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3146, 0X147C) << 16);
    // 0x80800298: lwc1        $f30, 0x147C($at)
    ctx->f30.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3146, 0X147C));
    // 0x8080029C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3146, 0X1480) << 16);
    // 0x808002A0: lwc1        $f28, 0x1480($at)
    ctx->f28.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3146, 0X1480));
    // 0x808002A4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x808002A8: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808002AC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808002B0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808002B4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808002B8: nop

    // 0x808002BC: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
L_808002C0:
    // 0x808002C0: jal         0x800DC178
    // 0x808002C4: mov.s       $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    ctx->f14.fl = ctx->f30.fl;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x808002C4: mov.s       $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    ctx->f14.fl = ctx->f30.fl;
    after_0:
    // 0x808002C8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808002CC: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x808002D0: jal         0x800DC178
    // 0x808002D4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x808002D4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_1:
    // 0x808002D8: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x808002DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3146, 0X1484) << 16);
    // 0x808002E0: lwc1        $f14, 0x1484($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3146, 0X1484));
    // 0x808002E4: jal         0x800DC178
    // 0x808002E8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x808002E8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x808002EC: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x808002F0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x808002F4: jal         0x800DC178
    // 0x808002F8: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x808002F8: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    after_3:
    // 0x808002FC: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x80800300: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80800304: jal         0x800DC178
    // 0x80800308: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80800308: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_4:
    // 0x8080030C: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x80800310: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80800314: jal         0x800DC178
    // 0x80800318: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80800318: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_5:
    // 0x8080031C: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80800320: lh          $t7, 0x58($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X58);
    // 0x80800324: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800328: addiu       $s0, $s0, 0x2C
    ctx->r16 = ADD32(ctx->r16, 0X2C);
    // 0x8080032C: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80800330: bnel        $at, $zero, L_808002C0
    if (ctx->r1 != 0) {
        // 0x80800334: mov.s       $f12, $f28
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
            goto L_808002C0;
    }
    goto skip_0;
    // 0x80800334: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    skip_0:
L_80800338:
    // 0x80800338: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8080033C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800340: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800344: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800348: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8080034C: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80800350: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80800354: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80800358: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8080035C: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80800360: jr          $ra
    // 0x80800364: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80800364: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80800AB8_chburgerstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800ABC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800AC0: bne         $a1, $at, L_80800AF0
    if (ctx->r5 != ctx->r1) {
        // 0x80800AC4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800AF0;
    }
    // 0x80800AC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AC8: addiu       $a0, $zero, 0x32F
    ctx->r4 = ADD32(0, 0X32F);
    // 0x80800ACC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800AD0: jal         0x80101180
    // 0x80800AD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_0;
    // 0x80800AD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800AD8: addiu       $a0, $zero, 0x32B
    ctx->r4 = ADD32(0, 0X32B);
    // 0x80800ADC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800AE0: jal         0x80101180
    // 0x80800AE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_1;
    // 0x80800AE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800AE8: b           L_80800B00
    // 0x80800AEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B00;
    // 0x80800AEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800AF0:
    // 0x80800AF0: jal         0x80085820
    // 0x80800AF4: nop

    _chswitch_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800AF4: nop

    after_2:
    // 0x80800AF8: b           L_80800B04
    // 0x80800AFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800B04;
    // 0x80800AFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B00:
    // 0x80800B00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B04:
    // 0x80800B04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B08: jr          $ra
    // 0x80800B0C: nop

    return;
    // 0x80800B0C: nop

;}
RECOMP_FUNC void func_8080056C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080056C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800570: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800574: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800578: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080057C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800580: jal         0x800D9004
    // 0x80800584: lw          $s0, 0x188($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X188);
    func_800D9004(rdram, ctx);
        goto after_0;
    // 0x80800584: lw          $s0, 0x188($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X188);
    after_0:
    // 0x80800588: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8080058C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800590: jal         0x8009B4D0
    // 0x80800594: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_8009B4D0(rdram, ctx);
        goto after_1;
    // 0x80800594: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x80800598: addiu       $a1, $s0, 0x2C
    ctx->r5 = ADD32(ctx->r16, 0X2C);
    // 0x8080059C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x808005A0: jal         0x800EF3DC
    // 0x808005A4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_800EF3DC(rdram, ctx);
        goto after_2;
    // 0x808005A4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_2:
    // 0x808005A8: jal         0x808004F8
    // 0x808005AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808004F8_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x808005AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x808005B0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808005B4: jal         0x800EF04C
    // 0x808005B8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_4;
    // 0x808005B8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x808005BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808005C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808005C4: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808005C8: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808005CC: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808005D0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808005D4: jal         0x800EF334
    // 0x808005D8: nop

    func_800EF334(rdram, ctx);
        goto after_5;
    // 0x808005D8: nop

    after_5:
    // 0x808005DC: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808005E0: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808005E4: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA3C0) << 16);
    // 0x808005E8: lwc1        $f12, -0x5C40($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA3C0));
    // 0x808005EC: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x808005F0: lwc1        $f2, 0x40($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X40);
    // 0x808005F4: addiu       $a0, $s0, 0x38
    ctx->r4 = ADD32(ctx->r16, 0X38);
    // 0x808005F8: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x808005FC: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80800600: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    // 0x80800604: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800608: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8080060C: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80800610: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80800614: swc1        $f16, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f16.u32l;
    // 0x80800618: jal         0x800EEFFC
    // 0x8080061C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_800EEFFC(rdram, ctx);
        goto after_6;
    // 0x8080061C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_6:
    // 0x80800620: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800624: jal         0x80806170
    // 0x80800628: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80806170_bsfirstp(rdram, ctx);
        goto after_7;
    // 0x80800628: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x8080062C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80800630: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800634: jal         0x800F1CF0
    // 0x80800638: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800F1CF0(rdram, ctx);
        goto after_8;
    // 0x80800638: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_8:
    // 0x8080063C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80800640: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800644: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800648: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8080064C: jal         0x8002DCA0
    // 0x80800650: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_9;
    // 0x80800650: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    after_9:
    // 0x80800654: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800658: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080065C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800660: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800664: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800668: jal         0x800F0DC0
    // 0x8080066C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_800F0DC0(rdram, ctx);
        goto after_10;
    // 0x8080066C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x80800670: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80800674: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800678: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080067C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800680: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800684: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800688: jal         0x800F0DC0
    // 0x8080068C: nop

    func_800F0DC0(rdram, ctx);
        goto after_11;
    // 0x8080068C: nop

    after_11:
    // 0x80800690: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80800694: jal         0x80809938
    // 0x80800698: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80809938_bsfirstp(rdram, ctx);
        goto after_12;
    // 0x80800698: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x8080069C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808006A0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808006A4: jal         0x800F0DC0
    // 0x808006A8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800F0DC0(rdram, ctx);
        goto after_13;
    // 0x808006A8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_13:
    // 0x808006AC: lwc1        $f2, 0x4C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x808006B0: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA3C4) << 16);
    // 0x808006B4: lwc1        $f4, -0x5C3C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA3C4));
    // 0x808006B8: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x808006BC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808006C0: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x808006C4: swc1        $f8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f8.u32l;
    // 0x808006C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006CC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808006D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808006D4: jr          $ra
    // 0x808006D8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x808006D8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800C9994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9994: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9998: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C999C: jal         0x800FCAE0
    // 0x800C99A0: nop

    func_800FCAE0(rdram, ctx);
        goto after_0;
    // 0x800C99A0: nop

    after_0:
    // 0x800C99A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C99A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C99AC: jr          $ra
    // 0x800C99B0: nop

    return;
    // 0x800C99B0: nop

;}
RECOMP_FUNC void gcfrontend_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003D0: jal         0x800D3D04
    // 0x808003D4: nop

    func_800D3D04(rdram, ctx);
        goto after_0;
    // 0x808003D4: nop

    after_0:
    // 0x808003D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003DC: jal         0x80800218
    // 0x808003E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    gcfrontend_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x808003E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808003E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003EC: jr          $ra
    // 0x808003F0: nop

    return;
    // 0x808003F0: nop

;}
RECOMP_FUNC void func_8080003C_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800040: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800044: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800048: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080004C: jal         0x80100094
    // 0x80800050: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800050: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800054: jal         0x800F54E4
    // 0x80800058: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800058: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080005C: jal         0x800F6438
    // 0x80800060: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6438(rdram, ctx);
        goto after_2;
    // 0x80800060: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800064: bnel        $v0, $zero, L_80800080
    if (ctx->r2 != 0) {
        // 0x80800068: lw          $v0, 0x24($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X24);
            goto L_80800080;
    }
    goto skip_0;
    // 0x80800068: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080006C: jal         0x800FFAB0
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800074: b           L_808000AC
    // 0x80800078: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000AC;
    // 0x80800078: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080007C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_80800080:
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800084: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800088: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8080008C: jal         0x8008A2A0
    // 0x80800090: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    _susubgame_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80800090: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    after_4:
    // 0x80800094: jal         0x8008A2F8
    // 0x80800098: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _susubgame_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80800098: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x8080009C: lhu         $t6, 0x6E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X6E);
    // 0x808000A0: andi        $t7, $t6, 0xFE00
    ctx->r15 = ctx->r14 & 0XFE00;
    // 0x808000A4: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
    // 0x808000A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000AC:
    // 0x808000AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000B4: jr          $ra
    // 0x808000B8: nop

    return;
    // 0x808000B8: nop

;}
RECOMP_FUNC void chfactoryroofbits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800618: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2280, 0XA08) << 16);
    // 0x8080061C: jr          $ra
    // 0x80800620: addiu       $v0, $v0, 0xA08
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2280, 0XA08));
    return;
    // 0x80800620: addiu       $v0, $v0, 0xA08
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2280, 0XA08));
;}
RECOMP_FUNC void suexpression_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x80800010: jal         0x80800CF4
    // 0x80800014: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80800CF4_suexpression(rdram, ctx);
        goto after_0;
    // 0x80800014: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800018: bne         $v0, $zero, L_8080002C
    if (ctx->r2 != 0) {
        // 0x8080001C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080002C;
    }
    // 0x8080001C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800020: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800024: b           L_8080003C
    // 0x80800028: nop

        goto L_8080003C;
    // 0x80800028: nop

L_8080002C:
    // 0x8080002C: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80800030: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800034: nop

    // 0x80800038: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
L_8080003C:
    // 0x8080003C: jr          $ra
    // 0x80800040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void bswasher_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008A8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808008AC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(443, 0X1E20) << 16);
    // 0x808008B0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808008B4: jr          $ra
    // 0x808008B8: lw          $v0, 0x1E20($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(443, 0X1E20));
    return;
    // 0x808008B8: lw          $v0, 0x1E20($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(443, 0X1E20));
;}
RECOMP_FUNC void _chhotwaterpoolbits_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086438: syscall     323
    recomp_syscall_handler(rdram, ctx, 0x80086438);
    return;
    // 0x8008643C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _sumumbofx_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800898C8: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x800898C8);
    return;
    // 0x800898CC: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void func_808001E0_chtorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808001E4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808001E8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x808001EC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x808001F0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808001F4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808001F8: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808001FC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800200: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800204: beql        $a1, $t7, L_80800338
    if (ctx->r5 == ctx->r15) {
        // 0x80800208: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800338;
    }
    goto skip_0;
    // 0x80800208: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8080020C: jal         0x80101FDC
    // 0x80800210: nop

    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x80800210: nop

    after_0:
    // 0x80800214: lhu         $t8, 0x72($s3)
    ctx->r24 = MEM_HU(ctx->r19, 0X72);
    // 0x80800218: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080021C: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80800220: bnel        $t9, $at, L_80800338
    if (ctx->r25 != ctx->r1) {
        // 0x80800224: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800338;
    }
    goto skip_1;
    // 0x80800224: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80800228: jal         0x800C8A98
    // 0x8080022C: nop

    func_800C8A98(rdram, ctx);
        goto after_1;
    // 0x8080022C: nop

    after_1:
    // 0x80800230: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2160, 0X950) << 16);
    // 0x80800234: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800238: addiu       $a1, $a1, 0x950
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2160, 0X950));
    // 0x8080023C: jal         0x800C8E84
    // 0x80800240: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C8E84(rdram, ctx);
        goto after_2;
    // 0x80800240: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800244: addiu       $s0, $s3, 0x4
    ctx->r16 = ADD32(ctx->r19, 0X4);
    // 0x80800248: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080024C: jal         0x800C8CB8
    // 0x80800250: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_800C8CB8(rdram, ctx);
        goto after_3;
    // 0x80800250: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_3:
    // 0x80800254: lui         $a2, 0x443B
    ctx->r6 = S32(0X443B << 16);
    // 0x80800258: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x8080025C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80800260: jal         0x800C8E54
    // 0x80800264: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    func_800C8E54(rdram, ctx);
        goto after_4;
    // 0x80800264: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    after_4:
    // 0x80800268: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8080026C: jal         0x800CB840
    // 0x80800270: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800CB840(rdram, ctx);
        goto after_5;
    // 0x80800270: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_5:
    // 0x80800274: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800278: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800280: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    // 0x80800284: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800288: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8080028C: jal         0x80109BEC
    // 0x80800290: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    func_80109BEC(rdram, ctx);
        goto after_6;
    // 0x80800290: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_6:
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800298: jal         0x8010CC10
    // 0x8080029C: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    func_8010CC10(rdram, ctx);
        goto after_7;
    // 0x8080029C: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    after_7:
    // 0x808002A0: beq         $v0, $zero, L_80800314
    if (ctx->r2 == 0) {
        // 0x808002A4: addiu       $s2, $sp, 0x3C
        ctx->r18 = ADD32(ctx->r29, 0X3C);
            goto L_80800314;
    }
    // 0x808002A4: addiu       $s2, $sp, 0x3C
    ctx->r18 = ADD32(ctx->r29, 0X3C);
    // 0x808002A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808002AC: addiu       $a1, $s3, 0x28
    ctx->r5 = ADD32(ctx->r19, 0X28);
    // 0x808002B0: jal         0x800EFA98
    // 0x808002B4: lui         $a2, 0xC348
    ctx->r6 = S32(0XC348 << 16);
    func_800EFA98(rdram, ctx);
        goto after_8;
    // 0x808002B4: lui         $a2, 0xC348
    ctx->r6 = S32(0XC348 << 16);
    after_8:
    // 0x808002B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808002BC: jal         0x800EF04C
    // 0x808002C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_9;
    // 0x808002C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x808002C4: jal         0x8010CCE0
    // 0x808002C8: nop

    func_8010CCE0(rdram, ctx);
        goto after_10;
    // 0x808002C8: nop

    after_10:
    // 0x808002CC: jal         0x8010CCEC
    // 0x808002D0: nop

    func_8010CCEC(rdram, ctx);
        goto after_11;
    // 0x808002D0: nop

    after_11:
    // 0x808002D4: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x808002D8: beq         $v0, $s1, L_80800314
    if (ctx->r2 == ctx->r17) {
        // 0x808002DC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80800314;
    }
    // 0x808002DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_808002E0:
    // 0x808002E0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808002E4: jal         0x80100094
    // 0x808002E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_12;
    // 0x808002E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x808002EC: lb          $a1, 0x0($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X0);
    // 0x808002F0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x808002F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808002FC: jal         0x800F7A7C
    // 0x80800300: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    func_800F7A7C(rdram, ctx);
        goto after_13;
    // 0x80800300: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_13:
    // 0x80800304: jal         0x8010CCEC
    // 0x80800308: nop

    func_8010CCEC(rdram, ctx);
        goto after_14;
    // 0x80800308: nop

    after_14:
    // 0x8080030C: bne         $v0, $s1, L_808002E0
    if (ctx->r2 != ctx->r17) {
        // 0x80800310: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808002E0;
    }
    // 0x80800310: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80800314:
    // 0x80800314: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80800318: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8080031C: jal         0x800863E8
    // 0x80800320: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_15;
    // 0x80800320: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_15:
    // 0x80800324: jal         0x800CB870
    // 0x80800328: nop

    func_800CB870(rdram, ctx);
        goto after_16;
    // 0x80800328: nop

    after_16:
    // 0x8080032C: jal         0x808000B8
    // 0x80800330: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_808000B8_chtorpedo(rdram, ctx);
        goto after_17;
    // 0x80800330: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_17:
    // 0x80800334: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800338:
    // 0x80800338: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080033C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800340: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800344: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800348: jr          $ra
    // 0x8080034C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8080034C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800CC63C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC63C: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800CC640: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800CC644: lw          $t7, -0x517C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X517C);
    // 0x800CC648: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CC64C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800CC650: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CC654: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800CC658: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CC65C: jal         0x800CB8F0
    // 0x800CC660: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    func_800CB8F0(rdram, ctx);
        goto after_0;
    // 0x800CC660: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x800CC664: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800CC668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CC66C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CC670: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800CC674: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800CC678: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800CC67C: jr          $ra
    // 0x800CC680: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    return;
    // 0x800CC680: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
;}
RECOMP_FUNC void func_80800884_chmolehill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800884: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800888: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080088C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800890: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800894: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800898: jal         0x800D731C
    // 0x8080089C: lhu         $a0, 0x14($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X14);
    func_800D731C(rdram, ctx);
        goto after_0;
    // 0x8080089C: lhu         $a0, 0x14($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X14);
    after_0:
    // 0x808008A0: sb          $v0, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r2;
    // 0x808008A4: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x808008A8: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x808008AC: bgez        $t9, L_80800904
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808008B0: nop
    
            goto L_80800904;
    }
    // 0x808008B0: nop

    // 0x808008B4: jal         0x800D8FF8
    // 0x808008B8: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x808008B8: nop

    after_1:
    // 0x808008BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1560, 0XAB8) << 16);
    // 0x808008C0: lwc1        $f2, 0xAB8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1560, 0XAB8));
    // 0x808008C4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x808008C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808008CC: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808008D0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808008D4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x808008D8: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
    // 0x808008DC: lwc1        $f16, 0x28($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808008E0: c.le.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl <= ctx->f16.fl;
    // 0x808008E4: nop

    // 0x808008E8: bc1fl       L_80800950
    if (!c1cs) {
        // 0x808008EC: lbu         $a0, 0x27($sp)
        ctx->r4 = MEM_BU(ctx->r29, 0X27);
            goto L_80800950;
    }
    goto skip_0;
    // 0x808008EC: lbu         $a0, 0x27($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X27);
    skip_0:
    // 0x808008F0: lbu         $t0, 0x74($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X74);
    // 0x808008F4: swc1        $f2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f2.u32l;
    // 0x808008F8: andi        $t1, $t0, 0xFFBF
    ctx->r9 = ctx->r8 & 0XFFBF;
    // 0x808008FC: b           L_8080094C
    // 0x80800900: sb          $t1, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r9;
        goto L_8080094C;
    // 0x80800900: sb          $t1, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r9;
L_80800904:
    // 0x80800904: jal         0x800D8FF8
    // 0x80800908: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80800908: nop

    after_2:
    // 0x8080090C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800910: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800914: lwc1        $f18, 0x28($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800918: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8080091C: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800920: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80800924: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    // 0x80800928: lwc1        $f10, 0x28($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8080092C: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x80800930: nop

    // 0x80800934: bc1fl       L_80800950
    if (!c1cs) {
        // 0x80800938: lbu         $a0, 0x27($sp)
        ctx->r4 = MEM_BU(ctx->r29, 0X27);
            goto L_80800950;
    }
    goto skip_1;
    // 0x80800938: lbu         $a0, 0x27($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X27);
    skip_1:
    // 0x8080093C: lbu         $t3, 0x74($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X74);
    // 0x80800940: swc1        $f2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f2.u32l;
    // 0x80800944: ori         $t4, $t3, 0x40
    ctx->r12 = ctx->r11 | 0X40;
    // 0x80800948: sb          $t4, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r12;
L_8080094C:
    // 0x8080094C: lbu         $a0, 0x27($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X27);
L_80800950:
    // 0x80800950: beql        $a0, $zero, L_80800990
    if (ctx->r4 == 0) {
        // 0x80800954: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800990;
    }
    goto skip_2;
    // 0x80800954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800958: lwc1        $f16, 0x28($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8080095C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800960: trunc.w.s   $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800964: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800968: jal         0x800DBE60
    // 0x8080096C: nop

    func_800DBE60(rdram, ctx);
        goto after_3;
    // 0x8080096C: nop

    after_3:
    // 0x80800970: lwc1        $f18, 0x28($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800974: lbu         $a0, 0x27($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X27);
    // 0x80800978: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080097C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800980: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80800984: jal         0x800DBE60
    // 0x80800988: nop

    func_800DBE60(rdram, ctx);
        goto after_4;
    // 0x80800988: nop

    after_4:
    // 0x8080098C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800990:
    // 0x80800990: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800994: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800998: jr          $ra
    // 0x8080099C: nop

    return;
    // 0x8080099C: nop

;}
RECOMP_FUNC void chcauldronentrydoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800378: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080037C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800380: jal         0x800E1720
    // 0x80800384: nop

    func_800E1720(rdram, ctx);
        goto after_0;
    // 0x80800384: nop

    after_0:
    // 0x80800388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080038C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800390: jr          $ra
    // 0x80800394: nop

    return;
    // 0x80800394: nop

;}
RECOMP_FUNC void func_80807328_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807328: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080732C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80807330: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80807334: jal         0x80807D48
    // 0x80807338: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80807D48_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80807338: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080733C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807340: jal         0x80804848
    // 0x80807344: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_80804848_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80807344: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x80807348: jal         0x80801928
    // 0x8080734C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801928_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x8080734C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80807350: jal         0x80801DC0
    // 0x80807354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801DC0_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80807354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80807358: jal         0x80808DB0
    // 0x8080735C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808DB0_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x8080735C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80807360: jal         0x80809D24
    // 0x80807364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80809D24_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x80807364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80807368: jal         0x8080682C
    // 0x8080736C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080682C_bsfirstp(rdram, ctx);
        goto after_6;
    // 0x8080736C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80807370: jal         0x808099B4
    // 0x80807374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808099B4_bsfirstp(rdram, ctx);
        goto after_7;
    // 0x80807374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80807378: jal         0x80800830
    // 0x8080737C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800830_bsfirstp(rdram, ctx);
        goto after_8;
    // 0x8080737C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80807380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80807384: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80807388: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080738C: jr          $ra
    // 0x80807390: nop

    return;
    // 0x80807390: nop

;}
RECOMP_FUNC void sumultiscore_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800708: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8080070C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80800710: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80800714: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80800718: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8080071C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80800720: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80800724: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80800728: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8080072C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80800730: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80800734: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800738: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8080073C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800740: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80800744: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80800748: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x8080074C: lw          $t6, 0x518($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X518);
    // 0x80800750: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800754: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800758: blez        $t6, L_80800898
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8080075C: or          $s1, $a0, $zero
        ctx->r17 = ctx->r4 | 0;
            goto L_80800898;
    }
    // 0x8080075C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800760: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3154, 0X1450) << 16);
    // 0x80800764: lwc1        $f24, 0x1450($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3154, 0X1450));
    // 0x80800768: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080076C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800770: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800774: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800778: sw          $a1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r5;
    // 0x8080077C: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
    // 0x80800780: addiu       $s7, $zero, 0xB89
    ctx->r23 = ADD32(0, 0XB89);
    // 0x80800784: addiu       $s6, $zero, 0xB8B
    ctx->r22 = ADD32(0, 0XB8B);
    // 0x80800788: addiu       $s5, $zero, -0x5
    ctx->r21 = ADD32(0, -0X5);
    // 0x8080078C: addiu       $s4, $zero, 0x5
    ctx->r20 = ADD32(0, 0X5);
    // 0x80800790: addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
    // 0x80800794: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
L_80800798:
    // 0x80800798: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x8080079C: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x808007A0: addu        $a0, $s1, $t9
    ctx->r4 = ADD32(ctx->r17, ctx->r25);
    // 0x808007A4: sb          $t0, 0x40($a0)
    MEM_B(0X40, ctx->r4) = ctx->r8;
    // 0x808007A8: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x808007AC: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x808007B0: sb          $t1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r9;
    // 0x808007B4: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x808007B8: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    // 0x808007BC: sb          $s3, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r19;
    // 0x808007C0: sh          $zero, 0x8($a0)
    MEM_H(0X8, ctx->r4) = 0;
    // 0x808007C4: sb          $s4, 0xA($a0)
    MEM_B(0XA, ctx->r4) = ctx->r20;
    // 0x808007C8: sb          $zero, 0xB($a0)
    MEM_B(0XB, ctx->r4) = 0;
    // 0x808007CC: sb          $s5, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r21;
    // 0x808007D0: sb          $zero, 0xD($a0)
    MEM_B(0XD, ctx->r4) = 0;
    // 0x808007D4: sb          $t2, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r10;
    // 0x808007D8: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x808007DC: sltiu       $at, $t3, 0x9
    ctx->r1 = ctx->r11 < 0X9 ? 1 : 0;
    // 0x808007E0: beq         $at, $zero, L_80800880
    if (ctx->r1 == 0) {
        // 0x808007E4: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80800880;
    }
    // 0x808007E4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x808007E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3154, 0X1454) << 16);
    // 0x808007EC: addu        $at, $at, $t3
    gpr jr_addend_808007F4 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x808007F0: lw          $t3, 0x1454($at)
    ctx->r11 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3154, 0X1454));
    // 0x808007F4: jr          $t3
    // 0x808007F8: nop

    switch (jr_addend_808007F4 >> 2) {
        case 0: goto L_808007FC; break;
        case 1: goto L_80800804; break;
        case 2: goto L_80800814; break;
        case 3: goto L_80800824; break;
        case 4: goto L_80800834; break;
        case 5: goto L_80800814; break;
        case 6: goto L_80800844; break;
        case 7: goto L_80800860; break;
        case 8: goto L_80800878; break;
        default: switch_error(__func__, 0x808007F4, 0x80801454);
    }
    // 0x808007F8: nop

L_808007FC:
    // 0x808007FC: b           L_80800880
    // 0x80800800: sb          $zero, 0x5($a0)
    MEM_B(0X5, ctx->r4) = 0;
        goto L_80800880;
    // 0x80800800: sb          $zero, 0x5($a0)
    MEM_B(0X5, ctx->r4) = 0;
L_80800804:
    // 0x80800804: addiu       $t4, $zero, 0xB4D
    ctx->r12 = ADD32(0, 0XB4D);
    // 0x80800808: sh          $t4, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r12;
    // 0x8080080C: b           L_80800880
    // 0x80800810: swc1        $f24, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f24.u32l;
        goto L_80800880;
    // 0x80800810: swc1        $f24, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f24.u32l;
L_80800814:
    // 0x80800814: jal         0x80801340
    // 0x80800818: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80801340_sumultiscore(rdram, ctx);
        goto after_0;
    // 0x80800818: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8080081C: b           L_80800884
    // 0x80800820: lw          $t1, 0x518($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X518);
        goto L_80800884;
    // 0x80800820: lw          $t1, 0x518($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X518);
L_80800824:
    // 0x80800824: addiu       $t5, $zero, 0xB81
    ctx->r13 = ADD32(0, 0XB81);
    // 0x80800828: sh          $t5, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r13;
    // 0x8080082C: b           L_80800880
    // 0x80800830: swc1        $f22, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f22.u32l;
        goto L_80800880;
    // 0x80800830: swc1        $f22, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f22.u32l;
L_80800834:
    // 0x80800834: addiu       $t6, $zero, 0xC14
    ctx->r14 = ADD32(0, 0XC14);
    // 0x80800838: sh          $t6, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r14;
    // 0x8080083C: b           L_80800880
    // 0x80800840: swc1        $f22, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f22.u32l;
        goto L_80800880;
    // 0x80800840: swc1        $f22, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f22.u32l;
L_80800844:
    // 0x80800844: lb          $t7, 0xC($a0)
    ctx->r15 = MEM_B(ctx->r4, 0XC);
    // 0x80800848: sh          $s7, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r23;
    // 0x8080084C: swc1        $f20, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f20.u32l;
    // 0x80800850: addiu       $t8, $t7, -0x5
    ctx->r24 = ADD32(ctx->r15, -0X5);
    // 0x80800854: sb          $fp, 0xA($a0)
    MEM_B(0XA, ctx->r4) = ctx->r30;
    // 0x80800858: b           L_80800880
    // 0x8080085C: sb          $t8, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r24;
        goto L_80800880;
    // 0x8080085C: sb          $t8, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r24;
L_80800860:
    // 0x80800860: lb          $t9, 0xC($a0)
    ctx->r25 = MEM_B(ctx->r4, 0XC);
    // 0x80800864: sh          $s6, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r22;
    // 0x80800868: swc1        $f20, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f20.u32l;
    // 0x8080086C: addiu       $t0, $t9, -0x5
    ctx->r8 = ADD32(ctx->r25, -0X5);
    // 0x80800870: b           L_80800880
    // 0x80800874: sb          $t0, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r8;
        goto L_80800880;
    // 0x80800874: sb          $t0, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r8;
L_80800878:
    // 0x80800878: jal         0x80801340
    // 0x8080087C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80801340_sumultiscore(rdram, ctx);
        goto after_1;
    // 0x8080087C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
L_80800880:
    // 0x80800880: lw          $t1, 0x518($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X518);
L_80800884:
    // 0x80800884: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800888: addiu       $s1, $s1, 0x13C
    ctx->r17 = ADD32(ctx->r17, 0X13C);
    // 0x8080088C: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80800890: bnel        $at, $zero, L_80800798
    if (ctx->r1 != 0) {
        // 0x80800894: lw          $t8, 0x0($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X0);
            goto L_80800798;
    }
    goto skip_0;
    // 0x80800894: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    skip_0:
L_80800898:
    // 0x80800898: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x8080089C: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x808008A0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x808008A4: addu        $t5, $s2, $t4
    ctx->r13 = ADD32(ctx->r18, ctx->r12);
    // 0x808008A8: sw          $t2, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r10;
    // 0x808008AC: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x808008B0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x808008B4: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x808008B8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x808008BC: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x808008C0: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x808008C4: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x808008C8: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x808008CC: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x808008D0: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x808008D4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x808008D8: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x808008DC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x808008E0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808008E4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808008E8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808008EC: jr          $ra
    // 0x808008F0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x808008F0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_800A1960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1960: jr          $ra
    // 0x800A1964: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    return;
    // 0x800A1964: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
;}
RECOMP_FUNC void bsblongleg_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080131C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801320: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801324: jal         0x8080013C
    // 0x80801328: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8080013C_bsblongleg(rdram, ctx);
        goto after_0;
    // 0x80801328: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080132C: jal         0x800839C8
    // 0x80801330: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x80801330: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080133C: jr          $ra
    // 0x80801340: nop

    return;
    // 0x80801340: nop

;}
RECOMP_FUNC void glcutDll_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080052C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80800530: jr          $ra
    // 0x80800534: sb          $a0, 0x75F8($at)
    MEM_B(0X75F8, ctx->r1) = ctx->r4;
    return;
    // 0x80800534: sb          $a0, 0x75F8($at)
    MEM_B(0X75F8, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_80800FC4_chjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FC4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800FC8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800FCC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800FD0: lw          $a0, 0x6C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C);
    // 0x80800FD4: andi        $t7, $a0, 0x1FF
    ctx->r15 = ctx->r4 & 0X1FF;
    // 0x80800FD8: jal         0x800D0CC8
    // 0x80800FDC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800D0CC8(rdram, ctx);
        goto after_0;
    // 0x80800FDC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x80800FE0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800FE4: jal         0x808000DC
    // 0x80800FE8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_808000DC_chjinjo(rdram, ctx);
        goto after_1;
    // 0x80800FE8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80800FEC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80800FF0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1672, 0X1390) << 16);
    // 0x80800FF4: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    // 0x80800FF8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80800FFC: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x80801000: lhu         $a0, 0x1390($a0)
    ctx->r4 = MEM_HU(ctx->r4, (int16_t)RELOC_LO16(1672, 0X1390));
    // 0x80801004: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801008: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8080100C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80801010: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80801014: jal         0x800C05B8
    // 0x80801018: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800C05B8(rdram, ctx);
        goto after_2;
    // 0x80801018: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x8080101C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801020: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801024: jr          $ra
    // 0x80801028: nop

    return;
    // 0x80801028: nop

;}
RECOMP_FUNC void _gcgoto_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087A90: syscall     652
    recomp_syscall_handler(rdram, ctx, 0x80087A90);
    return;
    // 0x80087A94: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_800E9300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9300: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E9304: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9308: jal         0x800E90D8
    // 0x800E930C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800E90D8(rdram, ctx);
        goto after_0;
    // 0x800E930C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800E9310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E9314: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E9318: jr          $ra
    // 0x800E931C: nop

    return;
    // 0x800E931C: nop

;}
RECOMP_FUNC void _bsbbilldrill_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800827A8: syscall     12
    recomp_syscall_handler(rdram, ctx, 0x800827A8);
    return;
    // 0x800827AC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808000A8_chterryegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000B0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000B4: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808000B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000BC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808000C0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808000C4: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x808000C8: beq         $at, $zero, L_80800210
    if (ctx->r1 == 0) {
        // 0x808000CC: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800210;
    }
    // 0x808000CC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808000D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1112, 0X1210) << 16);
    // 0x808000D4: addu        $at, $at, $t8
    gpr jr_addend_808000DC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808000D8: lw          $t8, 0x1210($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1112, 0X1210));
    // 0x808000DC: jr          $t8
    // 0x808000E0: nop

    switch (jr_addend_808000DC >> 2) {
        case 0: goto L_808000E4; break;
        case 1: goto L_80800210; break;
        case 2: goto L_8080010C; break;
        case 3: goto L_80800164; break;
        case 4: goto L_808001B0; break;
        case 5: goto L_808001D8; break;
        default: switch_error(__func__, 0x808000DC, 0x80801210);
    }
    // 0x808000E0: nop

L_808000E4:
    // 0x808000E4: jal         0x800878B0
    // 0x808000E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _plsu_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808000E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x808000EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808000F0: beq         $v0, $at, L_80800210
    if (ctx->r2 == ctx->r1) {
        // 0x808000F4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800210;
    }
    // 0x808000F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000F8: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x808000FC: jal         0x800F7BC8
    // 0x80800100: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_800F7BC8(rdram, ctx);
        goto after_1;
    // 0x80800100: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x80800104: b           L_80800214
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800214;
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080010C:
    // 0x8080010C: lw          $t9, 0x7C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X7C);
    // 0x80800110: sll         $t1, $t9, 19
    ctx->r9 = S32(ctx->r25 << 19);
    // 0x80800114: bgezl       $t1, L_80800214
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800118: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800214;
    }
    goto skip_0;
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080011C: jal         0x800D9078
    // 0x80800120: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_2;
    // 0x80800120: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_2:
    // 0x80800124: beq         $v0, $zero, L_80800210
    if (ctx->r2 == 0) {
        // 0x80800128: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800210;
    }
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: jal         0x80100094
    // 0x80800130: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80800130: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800138: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080013C: addiu       $a2, $zero, 0x7BE
    ctx->r6 = ADD32(0, 0X7BE);
    // 0x80800140: jal         0x8008A070
    // 0x80800144: lui         $a3, 0x4020
    ctx->r7 = S32(0X4020 << 16);
    _subaddiepalette_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800144: lui         $a3, 0x4020
    ctx->r7 = S32(0X4020 << 16);
    after_4:
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: jal         0x80102424
    // 0x80800150: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x80800150: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x80800154: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80800158: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080015C: b           L_80800210
    // 0x80800160: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_80800210;
    // 0x80800160: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80800164:
    // 0x80800164: jal         0x800D9078
    // 0x80800168: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_6;
    // 0x80800168: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_6:
    // 0x8080016C: beq         $v0, $zero, L_80800188
    if (ctx->r2 == 0) {
        // 0x80800170: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800188;
    }
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800174: jal         0x80102424
    // 0x80800178: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x80800178: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_7:
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800180: jal         0x8008A4B0
    // 0x80800184: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80800184: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
L_80800188:
    // 0x80800188: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8080018C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800190: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800194: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800198: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    // 0x8080019C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808001A0: jal         0x800F10B4
    // 0x808001A4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_9;
    // 0x808001A4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x808001A8: b           L_80800210
    // 0x808001AC: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
        goto L_80800210;
    // 0x808001AC: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
L_808001B0:
    // 0x808001B0: jal         0x800878B0
    // 0x808001B4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _plsu_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x808001B4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_10:
    // 0x808001B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808001BC: beq         $v0, $at, L_80800210
    if (ctx->r2 == ctx->r1) {
        // 0x808001C0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800210;
    }
    // 0x808001C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001C4: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x808001C8: jal         0x800F7BC8
    // 0x808001CC: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_800F7BC8(rdram, ctx);
        goto after_11;
    // 0x808001CC: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_11:
    // 0x808001D0: b           L_80800214
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800214;
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001D8:
    // 0x808001D8: jal         0x808010B0
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808010B0_chterryegg(rdram, ctx);
        goto after_12;
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808001E0: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x808001E4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808001E8: jal         0x80101E14
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_13;
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808001F0: beq         $v0, $zero, L_80800210
    if (ctx->r2 == 0) {
        // 0x808001F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800210;
    }
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808001FC: jal         0x80086670
    // 0x80800200: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_14;
    // 0x80800200: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_14:
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800208: jal         0x80102424
    // 0x8080020C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_15;
    // 0x8080020C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_15:
L_80800210:
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800214:
    // 0x80800214: jal         0x80100094
    // 0x80800218: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_16;
    // 0x80800218: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800220: jal         0x8008A068
    // 0x80800224: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _subaddiepalette_entrypoint_1(rdram, ctx);
        goto after_17;
    // 0x80800224: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_17:
    // 0x80800228: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080022C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800230: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800234: jr          $ra
    // 0x80800238: nop

    return;
    // 0x80800238: nop

;}
RECOMP_FUNC void func_800F6DA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6DA0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F6DA4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6DA8: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F6DAC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F6DB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F6DB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6DB8: jal         0x8009E6F8
    // 0x800F6DBC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    bs_getCurrentState(rdram, ctx);
        goto after_0;
    // 0x800F6DBC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F6DC0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F6DC4: jal         0x8009CBDC
    // 0x800F6DC8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8009CBDC(rdram, ctx);
        goto after_1;
    // 0x800F6DC8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x800F6DCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6DD0: xori        $t7, $v0, 0x12
    ctx->r15 = ctx->r2 ^ 0X12;
    // 0x800F6DD4: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800F6DD8: jr          $ra
    // 0x800F6DDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800F6DDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800B59E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B59E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B59E4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800B59E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B59EC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800B59F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B59F4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800B59F8: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800B59FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B5A00: addiu       $s2, $s2, 0x7F20
    ctx->r18 = ADD32(ctx->r18, 0X7F20);
    // 0x800B5A04: addiu       $s0, $s0, 0x7F34
    ctx->r16 = ADD32(ctx->r16, 0X7F34);
    // 0x800B5A08: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800B5A0C: addiu       $s3, $zero, 0x2D
    ctx->r19 = ADD32(0, 0X2D);
L_800B5A10:
    // 0x800B5A10: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x800B5A14: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x800B5A18: beql        $t7, $zero, L_800B5A48
    if (ctx->r15 == 0) {
        // 0x800B5A1C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800B5A48;
    }
    goto skip_0;
    // 0x800B5A1C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800B5A20: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800B5A24: beql        $a0, $zero, L_800B5A48
    if (ctx->r4 == 0) {
        // 0x800B5A28: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800B5A48;
    }
    goto skip_1;
    // 0x800B5A28: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x800B5A2C: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x800B5A30: beql        $s1, $t8, L_800B5A48
    if (ctx->r17 == ctx->r24) {
        // 0x800B5A34: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800B5A48;
    }
    goto skip_2;
    // 0x800B5A34: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x800B5A38: jal         0x800B5450
    // 0x800B5A3C: nop

    func_800B5450(rdram, ctx);
        goto after_0;
    // 0x800B5A3C: nop

    after_0:
    // 0x800B5A40: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800B5A44: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800B5A48:
    // 0x800B5A48: bne         $s1, $s3, L_800B5A10
    if (ctx->r17 != ctx->r19) {
        // 0x800B5A4C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800B5A10;
    }
    // 0x800B5A4C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800B5A50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B5A54: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B5A58: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B5A5C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800B5A60: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800B5A64: jr          $ra
    // 0x800B5A68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800B5A68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bsfirstp_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805994: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x80805998: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080599C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808059A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808059A4: jal         0x8009E6EC
    // 0x808059A8: sw          $zero, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = 0;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x808059A8: sw          $zero, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = 0;
    after_0:
    // 0x808059AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808059B0: slti        $at, $v0, 0x25
    ctx->r1 = SIGNED(ctx->r2) < 0X25 ? 1 : 0;
    // 0x808059B4: sw          $v0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r2;
    // 0x808059B8: bne         $at, $zero, L_80805A00
    if (ctx->r1 != 0) {
        // 0x808059BC: sw          $t6, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = ctx->r14;
            goto L_80805A00;
    }
    // 0x808059BC: sw          $t6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r14;
    // 0x808059C0: slti        $at, $v0, 0x74
    ctx->r1 = SIGNED(ctx->r2) < 0X74 ? 1 : 0;
    // 0x808059C4: bne         $at, $zero, L_808059E0
    if (ctx->r1 != 0) {
        // 0x808059C8: addiu       $t7, $v0, -0x45
        ctx->r15 = ADD32(ctx->r2, -0X45);
            goto L_808059E0;
    }
    // 0x808059C8: addiu       $t7, $v0, -0x45
    ctx->r15 = ADD32(ctx->r2, -0X45);
    // 0x808059CC: addiu       $at, $zero, 0x99
    ctx->r1 = ADD32(0, 0X99);
    // 0x808059D0: beq         $v0, $at, L_80805A30
    if (ctx->r2 == ctx->r1) {
        // 0x808059D4: nop
    
            goto L_80805A30;
    }
    // 0x808059D4: nop

    // 0x808059D8: b           L_80805A20
    // 0x808059DC: nop

        goto L_80805A20;
    // 0x808059DC: nop

L_808059E0:
    // 0x808059E0: sltiu       $at, $t7, 0x2F
    ctx->r1 = ctx->r15 < 0X2F ? 1 : 0;
    // 0x808059E4: beq         $at, $zero, L_80805A20
    if (ctx->r1 == 0) {
        // 0x808059E8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80805A20;
    }
    // 0x808059E8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808059EC: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA494) << 16);
    // 0x808059F0: addu        $at, $at, $t7
    gpr jr_addend_808059F8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808059F4: lw          $t7, -0x5B6C($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(439, 0XA494));
    // 0x808059F8: jr          $t7
    // 0x808059FC: nop

    switch (jr_addend_808059F8 >> 2) {
        case 0: goto L_80805E80; break;
        case 1: goto L_80805A20; break;
        case 2: goto L_80805B98; break;
        case 3: goto L_80805A20; break;
        case 4: goto L_80805A20; break;
        case 5: goto L_80805A20; break;
        case 6: goto L_80805A20; break;
        case 7: goto L_80805A40; break;
        case 8: goto L_80805A20; break;
        case 9: goto L_80805D34; break;
        case 10: goto L_80805A6C; break;
        case 11: goto L_80805A20; break;
        case 12: goto L_80805E18; break;
        case 13: goto L_80805A20; break;
        case 14: goto L_80805A20; break;
        case 15: goto L_80805A20; break;
        case 16: goto L_80805A20; break;
        case 17: goto L_80805A20; break;
        case 18: goto L_80805A20; break;
        case 19: goto L_80805A20; break;
        case 20: goto L_80805A20; break;
        case 21: goto L_80805A20; break;
        case 22: goto L_80805A20; break;
        case 23: goto L_80805A20; break;
        case 24: goto L_80805A20; break;
        case 25: goto L_80805A20; break;
        case 26: goto L_80805B78; break;
        case 27: goto L_80805A20; break;
        case 28: goto L_80805A78; break;
        case 29: goto L_80805AFC; break;
        case 30: goto L_80805B20; break;
        case 31: goto L_80805A20; break;
        case 32: goto L_80805A20; break;
        case 33: goto L_80805A20; break;
        case 34: goto L_80805A20; break;
        case 35: goto L_80805A20; break;
        case 36: goto L_80805A20; break;
        case 37: goto L_80805A20; break;
        case 38: goto L_80805A20; break;
        case 39: goto L_80805A20; break;
        case 40: goto L_80805CC0; break;
        case 41: goto L_80805A20; break;
        case 42: goto L_80805A20; break;
        case 43: goto L_80805A20; break;
        case 44: goto L_80805A20; break;
        case 45: goto L_80805B44; break;
        case 46: goto L_80805AE0; break;
        default: switch_error(__func__, 0x808059F8, 0x8080A494);
    }
    // 0x808059FC: nop

L_80805A00:
    // 0x80805A00: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80805A04: beq         $v0, $at, L_80805DB4
    if (ctx->r2 == ctx->r1) {
        // 0x80805A08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80805DB4;
    }
    // 0x80805A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805A0C: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x80805A10: beq         $v0, $at, L_80805EBC
    if (ctx->r2 == ctx->r1) {
        // 0x80805A14: addiu       $at, $zero, 0x24
        ctx->r1 = ADD32(0, 0X24);
            goto L_80805EBC;
    }
    // 0x80805A14: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    // 0x80805A18: beq         $v0, $at, L_80805EBC
    if (ctx->r2 == ctx->r1) {
        // 0x80805A1C: nop
    
            goto L_80805EBC;
    }
    // 0x80805A1C: nop

L_80805A20:
    // 0x80805A20: jal         0x80099B94
    // 0x80805A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099B94(rdram, ctx);
        goto after_1;
    // 0x80805A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80805A28: b           L_80805F38
    // 0x80805A2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80805F38;
    // 0x80805A2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80805A30:
    // 0x80805A30: jal         0x808019EC
    // 0x80805A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808019EC_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80805A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80805A38: b           L_80805F20
    // 0x80805A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80805F20;
    // 0x80805A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80805A40:
    // 0x80805A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805A44: jal         0x80099A7C
    // 0x80805A48: addiu       $a1, $sp, 0xE0
    ctx->r5 = ADD32(ctx->r29, 0XE0);
    func_80099A7C(rdram, ctx);
        goto after_3;
    // 0x80805A48: addiu       $a1, $sp, 0xE0
    ctx->r5 = ADD32(ctx->r29, 0XE0);
    after_3:
    // 0x80805A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805A50: jal         0x80084988
    // 0x80805A54: addiu       $a1, $sp, 0xE0
    ctx->r5 = ADD32(ctx->r29, 0XE0);
    _baduo_entrypoint_14(rdram, ctx);
        goto after_4;
    // 0x80805A54: addiu       $a1, $sp, 0xE0
    ctx->r5 = ADD32(ctx->r29, 0XE0);
    after_4:
    // 0x80805A58: addiu       $t8, $zero, 0xD7
    ctx->r24 = ADD32(0, 0XD7);
    // 0x80805A5C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80805A60: sw          $t8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r24;
    // 0x80805A64: b           L_80805F1C
    // 0x80805A68: sw          $t9, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r25;
        goto L_80805F1C;
    // 0x80805A68: sw          $t9, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r25;
L_80805A6C:
    // 0x80805A6C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80805A70: b           L_80805F1C
    // 0x80805A74: sw          $t1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r9;
        goto L_80805F1C;
    // 0x80805A74: sw          $t1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r9;
L_80805A78:
    // 0x80805A78: jal         0x80099A58
    // 0x80805A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A58(rdram, ctx);
        goto after_5;
    // 0x80805A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80805A80: beq         $v0, $zero, L_80805AA8
    if (ctx->r2 == 0) {
        // 0x80805A84: addiu       $t2, $zero, 0xCC
        ctx->r10 = ADD32(0, 0XCC);
            goto L_80805AA8;
    }
    // 0x80805A84: addiu       $t2, $zero, 0xCC
    ctx->r10 = ADD32(0, 0XCC);
    // 0x80805A88: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80805A8C: beq         $v0, $at, L_80805AB0
    if (ctx->r2 == ctx->r1) {
        // 0x80805A90: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80805AB0;
    }
    // 0x80805A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805A94: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80805A98: beq         $v0, $at, L_80805AC4
    if (ctx->r2 == ctx->r1) {
        // 0x80805A9C: addiu       $t4, $zero, 0xC9
        ctx->r12 = ADD32(0, 0XC9);
            goto L_80805AC4;
    }
    // 0x80805A9C: addiu       $t4, $zero, 0xC9
    ctx->r12 = ADD32(0, 0XC9);
    // 0x80805AA0: b           L_80805ACC
    // 0x80805AA4: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
        goto L_80805ACC;
    // 0x80805AA4: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
L_80805AA8:
    // 0x80805AA8: b           L_80805AC8
    // 0x80805AAC: sw          $t2, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r10;
        goto L_80805AC8;
    // 0x80805AAC: sw          $t2, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r10;
L_80805AB0:
    // 0x80805AB0: jal         0x800A3544
    // 0x80805AB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A3544(rdram, ctx);
        goto after_6;
    // 0x80805AB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80805AB8: addiu       $t3, $zero, 0xC8
    ctx->r11 = ADD32(0, 0XC8);
    // 0x80805ABC: b           L_80805AC8
    // 0x80805AC0: sw          $t3, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r11;
        goto L_80805AC8;
    // 0x80805AC0: sw          $t3, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r11;
L_80805AC4:
    // 0x80805AC4: sw          $t4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r12;
L_80805AC8:
    // 0x80805AC8: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
L_80805ACC:
    // 0x80805ACC: jal         0x800F7E64
    // 0x80805AD0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_800F7E64(rdram, ctx);
        goto after_7;
    // 0x80805AD0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_7:
    // 0x80805AD4: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80805AD8: b           L_80805F1C
    // 0x80805ADC: sw          $t5, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r13;
        goto L_80805F1C;
    // 0x80805ADC: sw          $t5, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r13;
L_80805AE0:
    // 0x80805AE0: jal         0x80807EEC
    // 0x80805AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807EEC_bsfirstp(rdram, ctx);
        goto after_8;
    // 0x80805AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80805AE8: jal         0x80801A5C
    // 0x80805AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801A5C_bsfirstp(rdram, ctx);
        goto after_9;
    // 0x80805AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80805AF0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80805AF4: b           L_80805F1C
    // 0x80805AF8: sw          $t6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r14;
        goto L_80805F1C;
    // 0x80805AF8: sw          $t6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r14;
L_80805AFC:
    // 0x80805AFC: jal         0x800A3404
    // 0x80805B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3404(rdram, ctx);
        goto after_10;
    // 0x80805B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80805B04: bnel        $v0, $zero, L_80805F20
    if (ctx->r2 != 0) {
        // 0x80805B08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80805F20;
    }
    goto skip_0;
    // 0x80805B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80805B0C: jal         0x80807EEC
    // 0x80805B10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807EEC_bsfirstp(rdram, ctx);
        goto after_11;
    // 0x80805B10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80805B14: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80805B18: b           L_80805F1C
    // 0x80805B1C: sw          $t7, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r15;
        goto L_80805F1C;
    // 0x80805B1C: sw          $t7, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r15;
L_80805B20:
    // 0x80805B20: jal         0x800A3404
    // 0x80805B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3404(rdram, ctx);
        goto after_12;
    // 0x80805B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80805B28: beql        $v0, $zero, L_80805F20
    if (ctx->r2 == 0) {
        // 0x80805B2C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80805F20;
    }
    goto skip_1;
    // 0x80805B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80805B30: jal         0x80807F24
    // 0x80805B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807F24_bsfirstp(rdram, ctx);
        goto after_13;
    // 0x80805B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80805B38: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80805B3C: b           L_80805F1C
    // 0x80805B40: sw          $t8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r24;
        goto L_80805F1C;
    // 0x80805B40: sw          $t8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r24;
L_80805B44:
    // 0x80805B44: jal         0x8009E6F8
    // 0x80805B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getCurrentState(rdram, ctx);
        goto after_14;
    // 0x80805B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80805B4C: addiu       $at, $zero, 0xD2
    ctx->r1 = ADD32(0, 0XD2);
    // 0x80805B50: bnel        $v0, $at, L_80805F20
    if (ctx->r2 != ctx->r1) {
        // 0x80805B54: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80805F20;
    }
    goto skip_2;
    // 0x80805B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80805B58: jal         0x80099A4C
    // 0x80805B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A4C(rdram, ctx);
        goto after_15;
    // 0x80805B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80805B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805B64: jal         0x80808678
    // 0x80805B68: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80808678_bsfirstp(rdram, ctx);
        goto after_16;
    // 0x80805B68: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_16:
    // 0x80805B6C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80805B70: b           L_80805F1C
    // 0x80805B74: sw          $t9, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r25;
        goto L_80805F1C;
    // 0x80805B74: sw          $t9, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r25;
L_80805B78:
    // 0x80805B78: jal         0x80099A34
    // 0x80805B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A34(rdram, ctx);
        goto after_17;
    // 0x80805B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80805B80: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80805B84: jal         0x80802BE8
    // 0x80805B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802BE8_bsfirstp(rdram, ctx);
        goto after_18;
    // 0x80805B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80805B8C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80805B90: b           L_80805F1C
    // 0x80805B94: sw          $t1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r9;
        goto L_80805F1C;
    // 0x80805B94: sw          $t1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r9;
L_80805B98:
    // 0x80805B98: jal         0x80099A4C
    // 0x80805B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A4C(rdram, ctx);
        goto after_19;
    // 0x80805B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80805BA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80805BA4: addiu       $a1, $sp, 0xD0
    ctx->r5 = ADD32(ctx->r29, 0XD0);
    // 0x80805BA8: jal         0x8008A3A8
    // 0x80805BAC: addiu       $a2, $sp, 0xC4
    ctx->r6 = ADD32(ctx->r29, 0XC4);
    _suegg_entrypoint_6(rdram, ctx);
        goto after_20;
    // 0x80805BAC: addiu       $a2, $sp, 0xC4
    ctx->r6 = ADD32(ctx->r29, 0XC4);
    after_20:
    // 0x80805BB0: lw          $a0, 0xC4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC4);
    // 0x80805BB4: jal         0x800883F0
    // 0x80805BB8: sw          $v0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r2;
    _gcegg_entrypoint_7(rdram, ctx);
        goto after_21;
    // 0x80805BB8: sw          $v0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r2;
    after_21:
    // 0x80805BBC: lw          $a0, 0xC4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC4);
    // 0x80805BC0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80805BC4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80805BC8: beq         $a0, $at, L_80805C00
    if (ctx->r4 == ctx->r1) {
        // 0x80805BCC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80805C00;
    }
    // 0x80805BCC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80805BD0: beq         $a0, $at, L_80805BF8
    if (ctx->r4 == ctx->r1) {
        // 0x80805BD4: addiu       $v1, $zero, 0xDA
        ctx->r3 = ADD32(0, 0XDA);
            goto L_80805BF8;
    }
    // 0x80805BD4: addiu       $v1, $zero, 0xDA
    ctx->r3 = ADD32(0, 0XDA);
    // 0x80805BD8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80805BDC: beq         $a0, $at, L_80805BF8
    if (ctx->r4 == ctx->r1) {
        // 0x80805BE0: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80805BF8;
    }
    // 0x80805BE0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80805BE4: beq         $a0, $at, L_80805BF4
    if (ctx->r4 == ctx->r1) {
        // 0x80805BE8: addiu       $t0, $zero, 0xDB
        ctx->r8 = ADD32(0, 0XDB);
            goto L_80805BF4;
    }
    // 0x80805BE8: addiu       $t0, $zero, 0xDB
    ctx->r8 = ADD32(0, 0XDB);
    // 0x80805BEC: b           L_80805C3C
    // 0x80805BF0: addiu       $v1, $zero, 0xDA
    ctx->r3 = ADD32(0, 0XDA);
        goto L_80805C3C;
    // 0x80805BF0: addiu       $v1, $zero, 0xDA
    ctx->r3 = ADD32(0, 0XDA);
L_80805BF4:
    // 0x80805BF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80805BF8:
    // 0x80805BF8: b           L_80805C3C
    // 0x80805BFC: addiu       $t0, $zero, 0xDC
    ctx->r8 = ADD32(0, 0XDC);
        goto L_80805C3C;
    // 0x80805BFC: addiu       $t0, $zero, 0xDC
    ctx->r8 = ADD32(0, 0XDC);
L_80805C00:
    // 0x80805C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805C04: jal         0x8009E6F8
    // 0x80805C08: sw          $a3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r7;
    bs_getCurrentState(rdram, ctx);
        goto after_22;
    // 0x80805C08: sw          $a3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r7;
    after_22:
    // 0x80805C0C: addiu       $at, $zero, 0xD9
    ctx->r1 = ADD32(0, 0XD9);
    // 0x80805C10: beq         $v0, $at, L_80805C24
    if (ctx->r2 == ctx->r1) {
        // 0x80805C14: lw          $a3, 0xC8($sp)
        ctx->r7 = MEM_W(ctx->r29, 0XC8);
            goto L_80805C24;
    }
    // 0x80805C14: lw          $a3, 0xC8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC8);
    // 0x80805C18: addiu       $v1, $zero, 0xD9
    ctx->r3 = ADD32(0, 0XD9);
    // 0x80805C1C: b           L_80805C3C
    // 0x80805C20: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_80805C3C;
    // 0x80805C20: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80805C24:
    // 0x80805C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805C28: jal         0x80803760
    // 0x80805C2C: sw          $a3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r7;
    func_80803760_bsfirstp(rdram, ctx);
        goto after_23;
    // 0x80805C2C: sw          $a3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r7;
    after_23:
    // 0x80805C30: lw          $a3, 0xC8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC8);
    // 0x80805C34: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80805C38: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80805C3C:
    // 0x80805C3C: addiu       $t2, $sp, 0xD0
    ctx->r10 = ADD32(ctx->r29, 0XD0);
    // 0x80805C40: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80805C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805C48: lw          $a1, 0xF0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF0);
    // 0x80805C4C: lw          $a2, 0xCC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XCC);
    // 0x80805C50: sw          $v1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r3;
    // 0x80805C54: jal         0x80803CD4
    // 0x80805C58: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    func_80803CD4_bsfirstp(rdram, ctx);
        goto after_24;
    // 0x80805C58: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    after_24:
    // 0x80805C5C: lw          $v1, 0xC0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XC0);
    // 0x80805C60: beq         $v0, $zero, L_80805F1C
    if (ctx->r2 == 0) {
        // 0x80805C64: lw          $t0, 0xBC($sp)
        ctx->r8 = MEM_W(ctx->r29, 0XBC);
            goto L_80805F1C;
    }
    // 0x80805C64: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x80805C68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80805C6C: beq         $v0, $at, L_80805C8C
    if (ctx->r2 == ctx->r1) {
        // 0x80805C70: lw          $a0, 0xC4($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XC4);
            goto L_80805C8C;
    }
    // 0x80805C70: lw          $a0, 0xC4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC4);
    // 0x80805C74: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80805C78: bne         $v0, $at, L_80805F1C
    if (ctx->r2 != ctx->r1) {
        // 0x80805C7C: addiu       $t3, $zero, 0x2
        ctx->r11 = ADD32(0, 0X2);
            goto L_80805F1C;
    }
    // 0x80805C7C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80805C80: sw          $t0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r8;
    // 0x80805C84: b           L_80805F1C
    // 0x80805C88: sw          $t3, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r11;
        goto L_80805F1C;
    // 0x80805C88: sw          $t3, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r11;
L_80805C8C:
    // 0x80805C8C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80805C90: bne         $a0, $at, L_80805CB4
    if (ctx->r4 != ctx->r1) {
        // 0x80805C94: sw          $v1, 0xF4($sp)
        MEM_W(0XF4, ctx->r29) = ctx->r3;
            goto L_80805CB4;
    }
    // 0x80805C94: sw          $v1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r3;
    // 0x80805C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805C9C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80805CA0: jal         0x80085520
    // 0x80805CA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _badeathmatch_entrypoint_5(rdram, ctx);
        goto after_25;
    // 0x80805CA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_25:
    // 0x80805CA8: addiu       $a0, $sp, 0xD0
    ctx->r4 = ADD32(ctx->r29, 0XD0);
    // 0x80805CAC: jal         0x8008A350
    // 0x80805CB0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    _sueggmisc_entrypoint_2(rdram, ctx);
        goto after_26;
    // 0x80805CB0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_26:
L_80805CB4:
    // 0x80805CB4: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80805CB8: b           L_80805F1C
    // 0x80805CBC: sw          $t4, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r12;
        goto L_80805F1C;
    // 0x80805CBC: sw          $t4, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r12;
L_80805CC0:
    // 0x80805CC0: jal         0x80099A58
    // 0x80805CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A58(rdram, ctx);
        goto after_27;
    // 0x80805CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80805CC8: sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
    // 0x80805CCC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80805CD0: jal         0x800F5A00
    // 0x80805CD4: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    func_800F5A00(rdram, ctx);
        goto after_28;
    // 0x80805CD4: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    after_28:
    // 0x80805CD8: addiu       $t5, $sp, 0xB0
    ctx->r13 = ADD32(ctx->r29, 0XB0);
    // 0x80805CDC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80805CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805CE4: lw          $a1, 0xF0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF0);
    // 0x80805CE8: lw          $a2, 0xAC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XAC);
    // 0x80805CEC: jal         0x80803CD4
    // 0x80805CF0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80803CD4_bsfirstp(rdram, ctx);
        goto after_29;
    // 0x80805CF0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_29:
    // 0x80805CF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80805CF8: beq         $v0, $at, L_80805D14
    if (ctx->r2 == ctx->r1) {
        // 0x80805CFC: addiu       $t6, $zero, 0xDA
        ctx->r14 = ADD32(0, 0XDA);
            goto L_80805D14;
    }
    // 0x80805CFC: addiu       $t6, $zero, 0xDA
    ctx->r14 = ADD32(0, 0XDA);
    // 0x80805D00: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80805D04: beq         $v0, $at, L_80805D24
    if (ctx->r2 == ctx->r1) {
        // 0x80805D08: addiu       $t8, $zero, 0xDB
        ctx->r24 = ADD32(0, 0XDB);
            goto L_80805D24;
    }
    // 0x80805D08: addiu       $t8, $zero, 0xDB
    ctx->r24 = ADD32(0, 0XDB);
    // 0x80805D0C: b           L_80805F20
    // 0x80805D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80805F20;
    // 0x80805D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80805D14:
    // 0x80805D14: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80805D18: sw          $t6, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r14;
    // 0x80805D1C: b           L_80805F1C
    // 0x80805D20: sw          $t7, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r15;
        goto L_80805F1C;
    // 0x80805D20: sw          $t7, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r15;
L_80805D24:
    // 0x80805D24: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80805D28: sw          $t8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r24;
    // 0x80805D2C: b           L_80805F1C
    // 0x80805D30: sw          $t9, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r25;
        goto L_80805F1C;
    // 0x80805D30: sw          $t9, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r25;
L_80805D34:
    // 0x80805D34: jal         0x80099A70
    // 0x80805D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A70(rdram, ctx);
        goto after_30;
    // 0x80805D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80805D3C: sw          $v0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r2;
    // 0x80805D40: jal         0x80099A58
    // 0x80805D44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A58(rdram, ctx);
        goto after_31;
    // 0x80805D44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80805D48: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x80805D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805D50: jal         0x80099A7C
    // 0x80805D54: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    func_80099A7C(rdram, ctx);
        goto after_32;
    // 0x80805D54: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    after_32:
    // 0x80805D58: addiu       $t1, $sp, 0x90
    ctx->r9 = ADD32(ctx->r29, 0X90);
    // 0x80805D5C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80805D60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805D64: lw          $a1, 0xF0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF0);
    // 0x80805D68: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x80805D6C: jal         0x80803CD4
    // 0x80805D70: lw          $a3, 0x9C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X9C);
    func_80803CD4_bsfirstp(rdram, ctx);
        goto after_33;
    // 0x80805D70: lw          $a3, 0x9C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X9C);
    after_33:
    // 0x80805D74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80805D78: beq         $v0, $at, L_80805D94
    if (ctx->r2 == ctx->r1) {
        // 0x80805D7C: addiu       $t2, $zero, 0xDA
        ctx->r10 = ADD32(0, 0XDA);
            goto L_80805D94;
    }
    // 0x80805D7C: addiu       $t2, $zero, 0xDA
    ctx->r10 = ADD32(0, 0XDA);
    // 0x80805D80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80805D84: beq         $v0, $at, L_80805DA4
    if (ctx->r2 == ctx->r1) {
        // 0x80805D88: addiu       $t4, $zero, 0xDC
        ctx->r12 = ADD32(0, 0XDC);
            goto L_80805DA4;
    }
    // 0x80805D88: addiu       $t4, $zero, 0xDC
    ctx->r12 = ADD32(0, 0XDC);
    // 0x80805D8C: b           L_80805F20
    // 0x80805D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80805F20;
    // 0x80805D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80805D94:
    // 0x80805D94: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80805D98: sw          $t2, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r10;
    // 0x80805D9C: b           L_80805F1C
    // 0x80805DA0: sw          $t3, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r11;
        goto L_80805F1C;
    // 0x80805DA0: sw          $t3, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r11;
L_80805DA4:
    // 0x80805DA4: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80805DA8: sw          $t4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r12;
    // 0x80805DAC: b           L_80805F1C
    // 0x80805DB0: sw          $t5, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r13;
        goto L_80805F1C;
    // 0x80805DB0: sw          $t5, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r13;
L_80805DB4:
    // 0x80805DB4: jal         0x80099A7C
    // 0x80805DB8: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    func_80099A7C(rdram, ctx);
        goto after_34;
    // 0x80805DB8: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    after_34:
    // 0x80805DBC: addiu       $t6, $sp, 0x80
    ctx->r14 = ADD32(ctx->r29, 0X80);
    // 0x80805DC0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80805DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805DC8: lw          $a1, 0xF0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF0);
    // 0x80805DCC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80805DD0: jal         0x80803CD4
    // 0x80805DD4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80803CD4_bsfirstp(rdram, ctx);
        goto after_35;
    // 0x80805DD4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_35:
    // 0x80805DD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80805DDC: beq         $v0, $at, L_80805DF8
    if (ctx->r2 == ctx->r1) {
        // 0x80805DE0: addiu       $t7, $zero, 0xDA
        ctx->r15 = ADD32(0, 0XDA);
            goto L_80805DF8;
    }
    // 0x80805DE0: addiu       $t7, $zero, 0xDA
    ctx->r15 = ADD32(0, 0XDA);
    // 0x80805DE4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80805DE8: beq         $v0, $at, L_80805E08
    if (ctx->r2 == ctx->r1) {
        // 0x80805DEC: addiu       $t9, $zero, 0xDB
        ctx->r25 = ADD32(0, 0XDB);
            goto L_80805E08;
    }
    // 0x80805DEC: addiu       $t9, $zero, 0xDB
    ctx->r25 = ADD32(0, 0XDB);
    // 0x80805DF0: b           L_80805F20
    // 0x80805DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80805F20;
    // 0x80805DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80805DF8:
    // 0x80805DF8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80805DFC: sw          $t7, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r15;
    // 0x80805E00: b           L_80805F1C
    // 0x80805E04: sw          $t8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r24;
        goto L_80805F1C;
    // 0x80805E04: sw          $t8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r24;
L_80805E08:
    // 0x80805E08: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80805E0C: sw          $t9, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r25;
    // 0x80805E10: b           L_80805F1C
    // 0x80805E14: sw          $t1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r9;
        goto L_80805F1C;
    // 0x80805E14: sw          $t1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r9;
L_80805E18:
    // 0x80805E18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805E1C: jal         0x8009C15C
    // 0x80805E20: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_8009C15C(rdram, ctx);
        goto after_36;
    // 0x80805E20: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_36:
    // 0x80805E24: addiu       $t2, $sp, 0x68
    ctx->r10 = ADD32(ctx->r29, 0X68);
    // 0x80805E28: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80805E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805E30: lw          $a1, 0xF0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF0);
    // 0x80805E34: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80805E38: jal         0x80803CD4
    // 0x80805E3C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80803CD4_bsfirstp(rdram, ctx);
        goto after_37;
    // 0x80805E3C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_37:
    // 0x80805E40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80805E44: beq         $v0, $at, L_80805E60
    if (ctx->r2 == ctx->r1) {
        // 0x80805E48: addiu       $t3, $zero, 0xDA
        ctx->r11 = ADD32(0, 0XDA);
            goto L_80805E60;
    }
    // 0x80805E48: addiu       $t3, $zero, 0xDA
    ctx->r11 = ADD32(0, 0XDA);
    // 0x80805E4C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80805E50: beq         $v0, $at, L_80805E70
    if (ctx->r2 == ctx->r1) {
        // 0x80805E54: addiu       $t5, $zero, 0xDC
        ctx->r13 = ADD32(0, 0XDC);
            goto L_80805E70;
    }
    // 0x80805E54: addiu       $t5, $zero, 0xDC
    ctx->r13 = ADD32(0, 0XDC);
    // 0x80805E58: b           L_80805F20
    // 0x80805E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80805F20;
    // 0x80805E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80805E60:
    // 0x80805E60: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80805E64: sw          $t3, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r11;
    // 0x80805E68: b           L_80805F1C
    // 0x80805E6C: sw          $t4, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r12;
        goto L_80805F1C;
    // 0x80805E6C: sw          $t4, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r12;
L_80805E70:
    // 0x80805E70: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80805E74: sw          $t5, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r13;
    // 0x80805E78: b           L_80805F1C
    // 0x80805E7C: sw          $t6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r14;
        goto L_80805F1C;
    // 0x80805E7C: sw          $t6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r14;
L_80805E80:
    // 0x80805E80: jal         0x800EFD24
    // 0x80805E84: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_800EFD24(rdram, ctx);
        goto after_38;
    // 0x80805E84: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_38:
    // 0x80805E88: addiu       $t7, $sp, 0x50
    ctx->r15 = ADD32(ctx->r29, 0X50);
    // 0x80805E8C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80805E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805E94: lw          $a1, 0xF0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF0);
    // 0x80805E98: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80805E9C: jal         0x80803CD4
    // 0x80805EA0: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_80803CD4_bsfirstp(rdram, ctx);
        goto after_39;
    // 0x80805EA0: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_39:
    // 0x80805EA4: beq         $v0, $zero, L_80805F1C
    if (ctx->r2 == 0) {
        // 0x80805EA8: addiu       $t8, $zero, 0xDB
        ctx->r24 = ADD32(0, 0XDB);
            goto L_80805F1C;
    }
    // 0x80805EA8: addiu       $t8, $zero, 0xDB
    ctx->r24 = ADD32(0, 0XDB);
    // 0x80805EAC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80805EB0: sw          $t8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r24;
    // 0x80805EB4: b           L_80805F1C
    // 0x80805EB8: sw          $t9, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r25;
        goto L_80805F1C;
    // 0x80805EB8: sw          $t9, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r25;
L_80805EBC:
    // 0x80805EBC: jal         0x800EFD24
    // 0x80805EC0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800EFD24(rdram, ctx);
        goto after_40;
    // 0x80805EC0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_40:
    // 0x80805EC4: addiu       $t1, $sp, 0x30
    ctx->r9 = ADD32(ctx->r29, 0X30);
    // 0x80805EC8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80805ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805ED0: lw          $a1, 0xF0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF0);
    // 0x80805ED4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80805ED8: jal         0x80803CD4
    // 0x80805EDC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80803CD4_bsfirstp(rdram, ctx);
        goto after_41;
    // 0x80805EDC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_41:
    // 0x80805EE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80805EE4: beq         $v0, $at, L_80805F00
    if (ctx->r2 == ctx->r1) {
        // 0x80805EE8: addiu       $t2, $zero, 0xDA
        ctx->r10 = ADD32(0, 0XDA);
            goto L_80805F00;
    }
    // 0x80805EE8: addiu       $t2, $zero, 0xDA
    ctx->r10 = ADD32(0, 0XDA);
    // 0x80805EEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80805EF0: beq         $v0, $at, L_80805F10
    if (ctx->r2 == ctx->r1) {
        // 0x80805EF4: addiu       $t4, $zero, 0xDB
        ctx->r12 = ADD32(0, 0XDB);
            goto L_80805F10;
    }
    // 0x80805EF4: addiu       $t4, $zero, 0xDB
    ctx->r12 = ADD32(0, 0XDB);
    // 0x80805EF8: b           L_80805F20
    // 0x80805EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80805F20;
    // 0x80805EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80805F00:
    // 0x80805F00: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80805F04: sw          $t2, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r10;
    // 0x80805F08: b           L_80805F1C
    // 0x80805F0C: sw          $t3, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r11;
        goto L_80805F1C;
    // 0x80805F0C: sw          $t3, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r11;
L_80805F10:
    // 0x80805F10: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80805F14: sw          $t4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r12;
    // 0x80805F18: sw          $t5, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r13;
L_80805F1C:
    // 0x80805F1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80805F20:
    // 0x80805F20: jal         0x8009E830
    // 0x80805F24: lw          $a1, 0xEC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XEC);
    func_8009E830(rdram, ctx);
        goto after_42;
    // 0x80805F24: lw          $a1, 0xEC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XEC);
    after_42:
    // 0x80805F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805F2C: jal         0x8009E5C8
    // 0x80805F30: lw          $a1, 0xF4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF4);
    bs_setState(rdram, ctx);
        goto after_43;
    // 0x80805F30: lw          $a1, 0xF4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF4);
    after_43:
    // 0x80805F34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80805F38:
    // 0x80805F38: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80805F3C: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    // 0x80805F40: jr          $ra
    // 0x80805F44: nop

    return;
    // 0x80805F44: nop

;}
RECOMP_FUNC void _baeggsetup_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084A40: syscall     126
    recomp_syscall_handler(rdram, ctx, 0x80084A40);
    return;
    // 0x80084A44: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80801608_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801608: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080160C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80801610: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80801614: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80801618: beq         $a1, $at, L_80801634
    if (ctx->r5 == ctx->r1) {
        // 0x8080161C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80801634;
    }
    // 0x8080161C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801620: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80801624: beq         $a1, $at, L_808016C0
    if (ctx->r5 == ctx->r1) {
        // 0x80801628: nop
    
            goto L_808016C0;
    }
    // 0x80801628: nop

    // 0x8080162C: b           L_8080170C
    // 0x80801630: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080170C;
    // 0x80801630: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801634:
    // 0x80801634: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80801638: jal         0x800F5A2C
    // 0x8080163C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_800F5A2C(rdram, ctx);
        goto after_0;
    // 0x8080163C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80801640: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801644: jal         0x800DC128
    // 0x80801648: addiu       $a1, $zero, 0x167
    ctx->r5 = ADD32(0, 0X167);
    func_800DC128(rdram, ctx);
        goto after_1;
    // 0x80801648: addiu       $a1, $zero, 0x167
    ctx->r5 = ADD32(0, 0X167);
    after_1:
    // 0x8080164C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80801650: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80801654: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80801658: lw          $a0, 0x2C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X2C);
    // 0x8080165C: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x80801660: jal         0x80108528
    // 0x80801664: addiu       $a0, $a0, 0x443
    ctx->r4 = ADD32(ctx->r4, 0X443);
    func_80108528(rdram, ctx);
        goto after_2;
    // 0x80801664: addiu       $a0, $a0, 0x443
    ctx->r4 = ADD32(ctx->r4, 0X443);
    after_2:
    // 0x80801668: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8080166C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801670: jal         0x80100094
    // 0x80801674: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80801674: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80801678: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8080167C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80801680: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    // 0x80801684: jal         0x800EE7F8
    // 0x80801688: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80801688: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_4:
    // 0x8080168C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801690: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80801694: jal         0x800EE7F8
    // 0x80801698: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80801698: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_5:
    // 0x8080169C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808016A0: jal         0x80101FDC
    // 0x808016A4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_6;
    // 0x808016A4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
    // 0x808016A8: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x808016AC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808016B0: jal         0x80102FDC
    // 0x808016B4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80102FDC(rdram, ctx);
        goto after_7;
    // 0x808016B4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x808016B8: b           L_8080170C
    // 0x808016BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080170C;
    // 0x808016BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808016C0:
    // 0x808016C0: jal         0x800EA05C
    // 0x808016C4: nop

    func_800EA05C(rdram, ctx);
        goto after_8;
    // 0x808016C4: nop

    after_8:
    // 0x808016C8: addiu       $at, $zero, 0x17D
    ctx->r1 = ADD32(0, 0X17D);
    // 0x808016CC: bne         $v0, $at, L_808016E8
    if (ctx->r2 != ctx->r1) {
        // 0x808016D0: addiu       $a0, $zero, 0x442
        ctx->r4 = ADD32(0, 0X442);
            goto L_808016E8;
    }
    // 0x808016D0: addiu       $a0, $zero, 0x442
    ctx->r4 = ADD32(0, 0X442);
    // 0x808016D4: addiu       $a0, $zero, 0x44D
    ctx->r4 = ADD32(0, 0X44D);
    // 0x808016D8: jal         0x80089C30
    // 0x808016DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x808016DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808016E0: b           L_808016F4
    // 0x808016E4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
        goto L_808016F4;
    // 0x808016E4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
L_808016E8:
    // 0x808016E8: jal         0x80089C30
    // 0x808016EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x808016EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x808016F0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
L_808016F4:
    // 0x808016F4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x808016F8: b           L_80801708
    // 0x808016FC: sw          $t7, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->r15;
        goto L_80801708;
    // 0x808016FC: sw          $t7, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->r15;
    // 0x80801700: b           L_8080170C
    // 0x80801704: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080170C;
    // 0x80801704: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801708:
    // 0x80801708: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080170C:
    // 0x8080170C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801710: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801714: jr          $ra
    // 0x80801718: nop

    return;
    // 0x80801718: nop

;}
RECOMP_FUNC void func_800DD214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD214: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DD218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DD21C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DD220: lw          $t6, 0x1C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X1C);
    // 0x800DD224: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800DD228: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800DD22C: beq         $t6, $zero, L_800DD2D8
    if (ctx->r14 == 0) {
        // 0x800DD230: addiu       $v1, $v1, -0x35C8
        ctx->r3 = ADD32(ctx->r3, -0X35C8);
            goto L_800DD2D8;
    }
    // 0x800DD230: addiu       $v1, $v1, -0x35C8
    ctx->r3 = ADD32(ctx->r3, -0X35C8);
    // 0x800DD234: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800DD238: beq         $v0, $zero, L_800DD26C
    if (ctx->r2 == 0) {
        // 0x800DD23C: nop
    
            goto L_800DD26C;
    }
    // 0x800DD23C: nop

    // 0x800DD240: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
    // 0x800DD244: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800DD248: sh          $t8, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r24;
    // 0x800DD24C: lh          $t9, 0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2);
    // 0x800DD250: bnel        $v0, $t9, L_800DD2DC
    if (ctx->r2 != ctx->r25) {
        // 0x800DD254: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DD2DC;
    }
    goto skip_0;
    // 0x800DD254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800DD258: lw          $t0, 0x1C($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X1C);
    // 0x800DD25C: jal         0x800DE2A4
    // 0x800DD260: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    func_800DE2A4(rdram, ctx);
        goto after_0;
    // 0x800DD260: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    after_0:
    // 0x800DD264: b           L_800DD2DC
    // 0x800DD268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DD2DC;
    // 0x800DD268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DD26C:
    // 0x800DD26C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DD270: addiu       $a0, $a0, -0x30A0
    ctx->r4 = ADD32(ctx->r4, -0X30A0);
    // 0x800DD274: addiu       $a1, $a2, 0x10
    ctx->r5 = ADD32(ctx->r6, 0X10);
    // 0x800DD278: jal         0x800193C4
    // 0x800DD27C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_800193C4(rdram, ctx);
        goto after_1;
    // 0x800DD27C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x800DD280: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DD284: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800DD288: addiu       $a1, $a1, -0x3168
    ctx->r5 = ADD32(ctx->r5, -0X3168);
    // 0x800DD28C: jal         0x800EEB40
    // 0x800DD290: addiu       $a0, $a0, -0x30A0
    ctx->r4 = ADD32(ctx->r4, -0X30A0);
    func_800EEB40(rdram, ctx);
        goto after_2;
    // 0x800DD290: addiu       $a0, $a0, -0x30A0
    ctx->r4 = ADD32(ctx->r4, -0X30A0);
    after_2:
    // 0x800DD294: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800DD298: lwc1        $f2, 0xC($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800DD29C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800DD2A0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800DD2A4: nop

    // 0x800DD2A8: bc1fl       L_800DD2DC
    if (!c1cs) {
        // 0x800DD2AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DD2DC;
    }
    goto skip_1;
    // 0x800DD2AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800DD2B0: lwc1        $f2, 0x8($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800DD2B4: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800DD2B8: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x800DD2BC: nop

    // 0x800DD2C0: bc1fl       L_800DD2DC
    if (!c1cs) {
        // 0x800DD2C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DD2DC;
    }
    goto skip_2;
    // 0x800DD2C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800DD2C8: lw          $t1, 0x1C($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X1C);
    // 0x800DD2CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800DD2D0: jal         0x800DE2A4
    // 0x800DD2D4: addu        $a1, $a2, $t1
    ctx->r5 = ADD32(ctx->r6, ctx->r9);
    func_800DE2A4(rdram, ctx);
        goto after_3;
    // 0x800DD2D4: addu        $a1, $a2, $t1
    ctx->r5 = ADD32(ctx->r6, ctx->r9);
    after_3:
L_800DD2D8:
    // 0x800DD2D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DD2DC:
    // 0x800DD2DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DD2E0: jr          $ra
    // 0x800DD2E4: nop

    return;
    // 0x800DD2E4: nop

;}
RECOMP_FUNC void _bskazfly_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083370: syscall     57
    recomp_syscall_handler(rdram, ctx, 0x80083370);
    return;
    // 0x80083374: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
