#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _idwibble_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088E80: syscall     745
    recomp_syscall_handler(rdram, ctx, 0x80088E80);
    return;
    // 0x80088E84: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chanim_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800088: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080008C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800090: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800094: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800098: jal         0x80106790
    // 0x8080009C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080009C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x808000A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000A4: jal         0x80100094
    // 0x808000A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808000A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808000AC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808000B0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x808000B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808000B8: jal         0x800DC128
    // 0x808000BC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x808000BC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_2:
    // 0x808000C0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x808000C4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808000C8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x808000CC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x808000D0: sw          $v0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r2;
    // 0x808000D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000DC: jr          $ra
    // 0x808000E0: nop

    return;
    // 0x808000E0: nop

;}
RECOMP_FUNC void func_8009D5E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D5E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009D5E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009D5E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009D5EC: lw          $v0, 0x104($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X104);
    // 0x8009D5F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009D5F4: lbu         $a1, 0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X1);
    // 0x8009D5F8: beq         $a1, $zero, L_8009D60C
    if (ctx->r5 == 0) {
        // 0x8009D5FC: nop
    
            goto L_8009D60C;
    }
    // 0x8009D5FC: nop

    // 0x8009D600: jal         0x800C2FDC
    // 0x8009D604: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    func_800C2FDC(rdram, ctx);
        goto after_0;
    // 0x8009D604: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    after_0:
    // 0x8009D608: lw          $v0, 0x104($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X104);
L_8009D60C:
    // 0x8009D60C: jal         0x800C2FDC
    // 0x8009D610: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    func_800C2FDC(rdram, ctx);
        goto after_1;
    // 0x8009D610: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    after_1:
    // 0x8009D614: lw          $t6, 0x104($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X104);
    // 0x8009D618: jal         0x800C2FDC
    // 0x8009D61C: lbu         $a0, 0x3($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X3);
    func_800C2FDC(rdram, ctx);
        goto after_2;
    // 0x8009D61C: lbu         $a0, 0x3($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X3);
    after_2:
    // 0x8009D620: lw          $t7, 0x104($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X104);
    // 0x8009D624: jal         0x800C2FDC
    // 0x8009D628: lbu         $a0, 0x2($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X2);
    func_800C2FDC(rdram, ctx);
        goto after_3;
    // 0x8009D628: lbu         $a0, 0x2($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X2);
    after_3:
    // 0x8009D62C: lw          $t8, 0x104($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X104);
    // 0x8009D630: lbu         $a0, 0x4($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X4);
    // 0x8009D634: beql        $a0, $zero, L_8009D648
    if (ctx->r4 == 0) {
        // 0x8009D638: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8009D648;
    }
    goto skip_0;
    // 0x8009D638: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8009D63C: jal         0x800C2FDC
    // 0x8009D640: nop

    func_800C2FDC(rdram, ctx);
        goto after_4;
    // 0x8009D640: nop

    after_4:
    // 0x8009D644: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009D648:
    // 0x8009D648: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009D64C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009D650: jr          $ra
    // 0x8009D654: nop

    return;
    // 0x8009D654: nop

;}
RECOMP_FUNC void func_80800BFC_sumultiscore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BFC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800C00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C04: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800C08: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800C0C: lbu         $t6, 0x6($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X6);
    // 0x80800C10: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80800C14: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80800C18: beq         $t6, $zero, L_80800D10
    if (ctx->r14 == 0) {
        // 0x80800C1C: addu        $t8, $t8, $a1
        ctx->r24 = ADD32(ctx->r24, ctx->r5);
            goto L_80800D10;
    }
    // 0x80800C1C: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x80800C20: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80800C24: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x80800C28: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800C2C: addu        $v1, $a0, $t8
    ctx->r3 = ADD32(ctx->r4, ctx->r24);
    // 0x80800C30: lw          $t9, 0x160($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X160);
    // 0x80800C34: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800C38: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800C3C: bne         $t9, $at, L_80800C68
    if (ctx->r25 != ctx->r1) {
        // 0x80800C40: nop
    
            goto L_80800C68;
    }
    // 0x80800C40: nop

    // 0x80800C44: lw          $t0, 0x1C($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X1C);
    // 0x80800C48: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80800C4C: jal         0x800F53D0
    // 0x80800C50: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x80800C50: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_0:
    // 0x80800C54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C58: jal         0x80085540
    // 0x80800C5C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _badeathmatch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800C5C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x80800C60: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80800C64: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
L_80800C68:
    // 0x80800C68: jal         0x800D8FF8
    // 0x80800C6C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80800C6C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_2:
    // 0x80800C70: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800C74: jal         0x800F1574
    // 0x80800C78: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    func_800F1574(rdram, ctx);
        goto after_3;
    // 0x80800C78: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    after_3:
    // 0x80800C7C: beq         $v0, $zero, L_80800CB8
    if (ctx->r2 == 0) {
        // 0x80800C80: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_80800CB8;
    }
    // 0x80800C80: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80800C84: lw          $t2, 0x160($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X160);
    // 0x80800C88: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80800C8C: lbu         $t7, 0x6($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X6);
    // 0x80800C90: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80800C94: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80800C98: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80800C9C: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x80800CA0: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x80800CA4: sb          $t7, 0x46($v0)
    MEM_B(0X46, ctx->r2) = ctx->r15;
    // 0x80800CA8: sw          $zero, 0x160($v1)
    MEM_W(0X160, ctx->r3) = 0;
    // 0x80800CAC: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x80800CB0: b           L_80800D10
    // 0x80800CB4: sb          $zero, 0x6($s0)
    MEM_B(0X6, ctx->r16) = 0;
        goto L_80800D10;
    // 0x80800CB4: sb          $zero, 0x6($s0)
    MEM_B(0X6, ctx->r16) = 0;
L_80800CB8:
    // 0x80800CB8: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80800CBC: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x80800CC0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800CC4: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800CC8: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80800CCC: nop

    // 0x80800CD0: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80800CD4: nop

    // 0x80800CD8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800CDC: sub.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80800CE0: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800CE4: jal         0x80013970
    // 0x80800CE8: nop

    func_80013970(rdram, ctx);
        goto after_4;
    // 0x80800CE8: nop

    after_4:
    // 0x80800CEC: jal         0x800F2100
    // 0x80800CF0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_5;
    // 0x80800CF0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_5:
    // 0x80800CF4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3154, 0X1494) << 16);
    // 0x80800CF8: lwc1        $f16, 0x1494($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3154, 0X1494));
    // 0x80800CFC: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800D00: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800D04: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x80800D08: nop

    // 0x80800D0C: sb          $t2, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r10;
L_80800D10:
    // 0x80800D10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800D18: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800D1C: jr          $ra
    // 0x80800D20: nop

    return;
    // 0x80800D20: nop

;}
RECOMP_FUNC void func_808069BC_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808069BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808069C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808069C4: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x808069C8: jal         0x80809D94
    // 0x808069CC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80809D94_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x808069CC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x808069D0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x808069D4: lwc1        $f4, 0x20C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20C);
    // 0x808069D8: swc1        $f0, 0x208($v0)
    MEM_W(0X208, ctx->r2) = ctx->f0.u32l;
    // 0x808069DC: jal         0x80013728
    // 0x808069E0: sub.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f4.fl;
    func_80013728(rdram, ctx);
        goto after_1;
    // 0x808069E0: sub.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f4.fl;
    after_1:
    // 0x808069E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808069E8: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x808069EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808069F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808069F4: jr          $ra
    // 0x808069F8: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    return;
    // 0x808069F8: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
;}
RECOMP_FUNC void func_80800C8C_suspline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C8C: lbu         $t6, 0x88($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X88);
    // 0x80800C90: addiu       $v0, $zero, 0x8C
    ctx->r2 = ADD32(0, 0X8C);
    // 0x80800C94: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800C98: blez        $t6, L_80800CD4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800C9C: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80800CD4;
    }
    // 0x80800C9C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800CA0: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80800CA4: sh          $v0, 0x68($a1)
    MEM_H(0X68, ctx->r5) = ctx->r2;
L_80800CA8:
    // 0x80800CA8: lh          $t7, 0x78($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X78);
    // 0x80800CAC: lbu         $t9, 0x88($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X88);
    // 0x80800CB0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800CB4: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800CB8: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80800CBC: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80800CC0: mflo        $t8
    ctx->r24 = lo;
    // 0x80800CC4: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80800CC8: bnel        $at, $zero, L_80800CA8
    if (ctx->r1 != 0) {
        // 0x80800CCC: sh          $v0, 0x68($a1)
        MEM_H(0X68, ctx->r5) = ctx->r2;
            goto L_80800CA8;
    }
    goto skip_0;
    // 0x80800CCC: sh          $v0, 0x68($a1)
    MEM_H(0X68, ctx->r5) = ctx->r2;
    skip_0:
    // 0x80800CD0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80800CD4:
    // 0x80800CD4: lbu         $t0, 0x89($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X89);
    // 0x80800CD8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800CDC: blez        $t0, L_80800D08
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80800CE0: nop
    
            goto L_80800D08;
    }
    // 0x80800CE0: nop

L_80800CE4:
    // 0x80800CE4: sh          $v0, 0x70($a1)
    MEM_H(0X70, ctx->r5) = ctx->r2;
    // 0x80800CE8: lbu         $t3, 0x89($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X89);
    // 0x80800CEC: lh          $t1, 0x78($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X78);
    // 0x80800CF0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800CF4: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80800CF8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80800CFC: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80800D00: bne         $at, $zero, L_80800CE4
    if (ctx->r1 != 0) {
        // 0x80800D04: addu        $v0, $v0, $t2
        ctx->r2 = ADD32(ctx->r2, ctx->r10);
            goto L_80800CE4;
    }
    // 0x80800D04: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
L_80800D08:
    // 0x80800D08: jr          $ra
    // 0x80800D0C: nop

    return;
    // 0x80800D0C: nop

;}
RECOMP_FUNC void _bssplitup_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083AC8: syscall     89
    recomp_syscall_handler(rdram, ctx, 0x80083AC8);
    return;
    // 0x80083ACC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _bsdronebubbled_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083088: syscall     40
    recomp_syscall_handler(rdram, ctx, 0x80083088);
    return;
    // 0x8008308C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void bsfirstp_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080297C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802980: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x80802984: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80802988: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8080298C: lui         $t8, 0x8081
    ctx->r24 = S32(RELOC_HI16(439, 0XAC94) << 16);
    // 0x80802990: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80802994: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80802998: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080299C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808029A0: addiu       $t8, $t8, -0x536C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(439, 0XAC94));
    // 0x808029A4: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x808029A8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808029AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808029B0: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x808029B4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x808029B8: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
L_808029BC:
    // 0x808029BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808029C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808029C4: lbu         $a2, -0x2($s1)
    ctx->r6 = MEM_BU(ctx->r17, -0X2);
    // 0x808029C8: jal         0x80085548
    // 0x808029CC: lbu         $a3, -0x1($s1)
    ctx->r7 = MEM_BU(ctx->r17, -0X1);
    _badeathmatch_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x808029CC: lbu         $a3, -0x1($s1)
    ctx->r7 = MEM_BU(ctx->r17, -0X1);
    after_0:
    // 0x808029D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808029D4: bne         $s0, $s3, L_808029BC
    if (ctx->r16 != ctx->r19) {
        // 0x808029D8: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_808029BC;
    }
    // 0x808029D8: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x808029DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808029E0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808029E4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808029E8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808029EC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808029F0: jr          $ra
    // 0x808029F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808029F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void idworld_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800218: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080021C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800220: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80800224: addiu       $s0, $s0, 0x7EF0
    ctx->r16 = ADD32(ctx->r16, 0X7EF0);
    // 0x80800228: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080022C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800230: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800234: jal         0x800B296C
    // 0x80800238: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    vector_end(rdram, ctx);
        goto after_0;
    // 0x80800238: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    after_0:
    // 0x8080023C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800240: jal         0x800B28C4
    // 0x80800244: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    vector_begin(rdram, ctx);
        goto after_1;
    // 0x80800244: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    after_1:
    // 0x80800248: sltu        $at, $v0, $s2
    ctx->r1 = ctx->r2 < ctx->r18 ? 1 : 0;
    // 0x8080024C: beq         $at, $zero, L_8080029C
    if (ctx->r1 == 0) {
        // 0x80800250: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8080029C;
    }
    // 0x80800250: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800254: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2950, 0X2C0) << 16);
    // 0x80800258: addiu       $s1, $s1, 0x2C0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2950, 0X2C0));
    // 0x8080025C: lbu         $t6, 0x7($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X7);
L_80800260:
    // 0x80800260: beql        $t6, $zero, L_80800290
    if (ctx->r14 == 0) {
        // 0x80800264: addiu       $s0, $s0, 0xA8
        ctx->r16 = ADD32(ctx->r16, 0XA8);
            goto L_80800290;
    }
    goto skip_0;
    // 0x80800264: addiu       $s0, $s0, 0xA8
    ctx->r16 = ADD32(ctx->r16, 0XA8);
    skip_0:
    // 0x80800268: lbu         $t7, 0x6($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X6);
    // 0x8080026C: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80800270: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800274: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800278: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x8080027C: lw          $t9, 0x0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X0);
    // 0x80800280: lh          $a2, 0x4($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X4);
    // 0x80800284: jalr        $t9
    // 0x80800288: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80800288: nop

    after_2:
    // 0x8080028C: addiu       $s0, $s0, 0xA8
    ctx->r16 = ADD32(ctx->r16, 0XA8);
L_80800290:
    // 0x80800290: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x80800294: bnel        $at, $zero, L_80800260
    if (ctx->r1 != 0) {
        // 0x80800298: lbu         $t6, 0x7($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X7);
            goto L_80800260;
    }
    goto skip_1;
    // 0x80800298: lbu         $t6, 0x7($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X7);
    skip_1:
L_8080029C:
    // 0x8080029C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808002A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002A4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808002A8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808002AC: jr          $ra
    // 0x808002B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808002B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808002B4: nop

    // 0x808002B8: nop

    // 0x808002BC: nop

;}
RECOMP_FUNC void bstrexlarge_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F18: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800F1C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(412, 0X19D0) << 16);
    // 0x80800F20: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800F24: jr          $ra
    // 0x80800F28: lw          $v0, 0x19D0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(412, 0X19D0));
    return;
    // 0x80800F28: lw          $v0, 0x19D0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(412, 0X19D0));
;}
RECOMP_FUNC void func_800D175C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D175C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D1760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1764: jal         0x800D16C4
    // 0x800D1768: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800D16C4(rdram, ctx);
        goto after_0;
    // 0x800D1768: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D176C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800D1770: lw          $t6, -0x4DB0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4DB0);
    // 0x800D1774: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x800D1778: addiu       $a3, $a3, 0x1A04
    ctx->r7 = ADD32(ctx->r7, 0X1A04);
    // 0x800D177C: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x800D1780: sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2 << 3);
    // 0x800D1784: addu        $t2, $a3, $t1
    ctx->r10 = ADD32(ctx->r7, ctx->r9);
    // 0x800D1788: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800D178C: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x800D1790: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x800D1794: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800D1798: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x800D179C: xor         $t4, $t3, $t9
    ctx->r12 = ctx->r11 ^ ctx->r25;
    // 0x800D17A0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800D17A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D17A8: jal         0x800D16CC
    // 0x800D17AC: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    func_800D16CC(rdram, ctx);
        goto after_1;
    // 0x800D17AC: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_1:
    // 0x800D17B0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800D17B4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800D17B8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800D17BC: lw          $t6, -0x4DB0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4DB0);
    // 0x800D17C0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800D17C4: sll         $t1, $v0, 1
    ctx->r9 = S32(ctx->r2 << 1);
    // 0x800D17C8: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x800D17CC: addu        $t2, $a3, $t1
    ctx->r10 = ADD32(ctx->r7, ctx->r9);
    // 0x800D17D0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800D17D4: lh          $t0, 0x0($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X0);
    // 0x800D17D8: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x800D17DC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800D17E0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800D17E4: lh          $a0, -0x50B0($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X50B0);
    // 0x800D17E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D17EC: jal         0x800D24E8
    // 0x800D17F0: xor         $a1, $t3, $t0
    ctx->r5 = ctx->r11 ^ ctx->r8;
    func_800D24E8(rdram, ctx);
        goto after_2;
    // 0x800D17F0: xor         $a1, $t3, $t0
    ctx->r5 = ctx->r11 ^ ctx->r8;
    after_2:
    // 0x800D17F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D17F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D17FC: jr          $ra
    // 0x800D1800: nop

    return;
    // 0x800D1800: nop

;}
RECOMP_FUNC void _bsstatue_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083BC8: syscall     91
    recomp_syscall_handler(rdram, ctx, 0x80083BC8);
    return;
    // 0x80083BCC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_808002E0_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808002EC: beq         $a2, $zero, L_80800304
    if (ctx->r6 == 0) {
        // 0x808002F0: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80800304;
    }
    // 0x808002F0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808002F4: jal         0x80800024
    // 0x808002F8: nop

    func_80800024_bstrexlarge(rdram, ctx);
        goto after_0;
    // 0x808002F8: nop

    after_0:
    // 0x808002FC: b           L_8080030C
    // 0x80800300: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
        goto L_8080030C;
    // 0x80800300: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
L_80800304:
    // 0x80800304: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800308: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
L_8080030C:
    // 0x8080030C: jal         0x8009EF10
    // 0x80800310: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x80800310: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800314: beq         $v0, $zero, L_8080033C
    if (ctx->r2 == 0) {
        // 0x80800318: addiu       $v1, $zero, 0x151
        ctx->r3 = ADD32(0, 0X151);
            goto L_8080033C;
    }
    // 0x80800318: addiu       $v1, $zero, 0x151
    ctx->r3 = ADD32(0, 0X151);
    // 0x8080031C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800320: beq         $v0, $at, L_80800344
    if (ctx->r2 == ctx->r1) {
        // 0x80800324: addiu       $v1, $zero, 0x152
        ctx->r3 = ADD32(0, 0X152);
            goto L_80800344;
    }
    // 0x80800324: addiu       $v1, $zero, 0x152
    ctx->r3 = ADD32(0, 0X152);
    // 0x80800328: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080032C: beq         $v0, $at, L_8080034C
    if (ctx->r2 == ctx->r1) {
        // 0x80800330: addiu       $t7, $zero, 0x150
        ctx->r15 = ADD32(0, 0X150);
            goto L_8080034C;
    }
    // 0x80800330: addiu       $t7, $zero, 0x150
    ctx->r15 = ADD32(0, 0X150);
    // 0x80800334: b           L_80800350
    // 0x80800338: nop

        goto L_80800350;
    // 0x80800338: nop

L_8080033C:
    // 0x8080033C: b           L_80800350
    // 0x80800340: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
        goto L_80800350;
    // 0x80800340: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
L_80800344:
    // 0x80800344: b           L_80800350
    // 0x80800348: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
        goto L_80800350;
    // 0x80800348: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
L_8080034C:
    // 0x8080034C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_80800350:
    // 0x80800350: jal         0x8009E6F8
    // 0x80800354: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bs_getCurrentState(rdram, ctx);
        goto after_2;
    // 0x80800354: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800358: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080035C: beq         $v0, $v1, L_80800368
    if (ctx->r2 == ctx->r3) {
        // 0x80800360: nop
    
            goto L_80800368;
    }
    // 0x80800360: nop

    // 0x80800364: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
L_80800368:
    // 0x80800368: jal         0x80800140
    // 0x8080036C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800140_bstrexlarge(rdram, ctx);
        goto after_3;
    // 0x8080036C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800370: beq         $v0, $zero, L_8080037C
    if (ctx->r2 == 0) {
        // 0x80800374: addiu       $t8, $zero, 0x14F
        ctx->r24 = ADD32(0, 0X14F);
            goto L_8080037C;
    }
    // 0x80800374: addiu       $t8, $zero, 0x14F
    ctx->r24 = ADD32(0, 0X14F);
    // 0x80800378: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_8080037C:
    // 0x8080037C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80800380: beq         $t9, $zero, L_8080039C
    if (ctx->r25 == 0) {
        // 0x80800384: nop
    
            goto L_8080039C;
    }
    // 0x80800384: nop

    // 0x80800388: jal         0x8008DD04
    // 0x8080038C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8008DD04(rdram, ctx);
        goto after_4;
    // 0x8080038C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800390: beq         $v0, $zero, L_8080039C
    if (ctx->r2 == 0) {
        // 0x80800394: addiu       $t0, $zero, 0x14A
        ctx->r8 = ADD32(0, 0X14A);
            goto L_8080039C;
    }
    // 0x80800394: addiu       $t0, $zero, 0x14A
    ctx->r8 = ADD32(0, 0X14A);
    // 0x80800398: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_8080039C:
    // 0x8080039C: jal         0x80800160
    // 0x808003A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800160_bstrexlarge(rdram, ctx);
        goto after_5;
    // 0x808003A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x808003A4: beq         $v0, $zero, L_808003B0
    if (ctx->r2 == 0) {
        // 0x808003A8: addiu       $t1, $zero, 0x14B
        ctx->r9 = ADD32(0, 0X14B);
            goto L_808003B0;
    }
    // 0x808003A8: addiu       $t1, $zero, 0x14B
    ctx->r9 = ADD32(0, 0X14B);
    // 0x808003AC: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_808003B0:
    // 0x808003B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003B4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x808003B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003BC: jr          $ra
    // 0x808003C0: nop

    return;
    // 0x808003C0: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800BE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800BEC: jal         0x80098140
    // 0x80800BF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    bainput_enable(rdram, ctx);
        goto after_0;
    // 0x80800BF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80800BF4: jal         0x8080061C
    // 0x80800BF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080061C_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x80800BF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800BFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C04: jr          $ra
    // 0x80800C08: nop

    return;
    // 0x80800C08: nop

;}
RECOMP_FUNC void suegg_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C58: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800C5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C60: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800C64: jal         0x800EE7F8
    // 0x80800C68: addiu       $a1, $a3, 0x28
    ctx->r5 = ADD32(ctx->r7, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800C68: addiu       $a1, $a3, 0x28
    ctx->r5 = ADD32(ctx->r7, 0X28);
    after_0:
    // 0x80800C6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C74: jr          $ra
    // 0x80800C78: nop

    return;
    // 0x80800C78: nop

;}
RECOMP_FUNC void func_80800330_chbottlesparty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800330: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800334: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800338: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080033C: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x80800340: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800344: beql        $t6, $zero, L_808003D4
    if (ctx->r14 == 0) {
        // 0x80800348: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808003D4;
    }
    goto skip_0;
    // 0x80800348: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080034C: lwc1        $f12, 0x58($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80800350: jal         0x800F0F9C
    // 0x80800354: lwc1        $f14, 0x2C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X2C);
    func_800F0F9C(rdram, ctx);
        goto after_0;
    // 0x80800354: lwc1        $f14, 0x2C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X2C);
    after_0:
    // 0x80800358: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1508, 0X508) << 16);
    // 0x8080035C: addiu       $a1, $a1, 0x508
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1508, 0X508));
    // 0x80800360: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800364: jal         0x800F3780
    // 0x80800368: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800F3780(rdram, ctx);
        goto after_1;
    // 0x80800368: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x8080036C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800374: jal         0x80103DFC
    // 0x80800378: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_80103DFC(rdram, ctx);
        goto after_2;
    // 0x80800378: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x8080037C: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
    // 0x80800380: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1508, 0X4CC) << 16);
    // 0x80800384: addiu       $t0, $t0, 0x4CC
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1508, 0X4CC));
    // 0x80800388: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x8080038C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80800390: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80800394: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800398: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1508, 0X4FC) << 16);
    // 0x8080039C: addiu       $a1, $a1, 0x4FC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1508, 0X4FC));
    // 0x808003A0: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    // 0x808003A4: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808003A8: jal         0x800F3214
    // 0x808003AC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_800F3214(rdram, ctx);
        goto after_3;
    // 0x808003AC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x808003B0: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x808003B4: jal         0x800C8E84
    // 0x808003B8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800C8E84(rdram, ctx);
        goto after_4;
    // 0x808003B8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_4:
    // 0x808003BC: jal         0x800D8FF8
    // 0x808003C0: nop

    func_800D8FF8(rdram, ctx);
        goto after_5;
    // 0x808003C0: nop

    after_5:
    // 0x808003C4: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808003C8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x808003CC: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x808003D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003D4:
    // 0x808003D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003D8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808003DC: jr          $ra
    // 0x808003E0: nop

    return;
    // 0x808003E0: nop

;}
RECOMP_FUNC void sucoasterfly_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800018: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800020: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800024: addiu       $a2, $a3, 0x1C
    ctx->r6 = ADD32(ctx->r7, 0X1C);
    // 0x80800028: jal         0x80100074
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100074(rdram, ctx);
        goto after_0;
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800030: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800034: jal         0x8008A268
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoasterflydata_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080003C: lbu         $t9, 0x11($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X11);
    // 0x80800040: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800048: andi        $t0, $t9, 0xFF0F
    ctx->r8 = ctx->r25 & 0XFF0F;
    // 0x8080004C: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800050: sb          $t1, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r9;
    // 0x80800054: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800058: jal         0x80089F70
    // 0x8080005C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    _subaddierouteDll_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x8080005C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x80800060: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800064: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80800068: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080006C: swc1        $f4, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f4.u32l;
    // 0x80800070: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800074: lui         $a3, 0xC4BB
    ctx->r7 = S32(0XC4BB << 16);
    // 0x80800078: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x8080007C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800084: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80800088: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    // 0x8080008C: jal         0x80801FE4
    // 0x80800090: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    func_80801FE4_sucoasterfly(rdram, ctx);
        goto after_3;
    // 0x80800090: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x80800094: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800098: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8080009C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808000A0: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x808000A4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808000A8: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x808000AC: nop

    // 0x808000B0: sh          $t3, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r11;
    // 0x808000B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000B8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808000BC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808000C0: jr          $ra
    // 0x808000C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808000C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80803B58_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803B58: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80803B5C: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80803B60: jr          $ra
    // 0x80803B64: swc1        $f12, 0x110($v0)
    MEM_W(0X110, ctx->r2) = ctx->f12.u32l;
    return;
    // 0x80803B64: swc1        $f12, 0x110($v0)
    MEM_W(0X110, ctx->r2) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_800F1214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1214: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800F1218: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F121C: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x800F1220: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800F1224: jr          $ra
    // 0x800F1228: add.s       $f0, $f8, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f14.fl;
    return;
    // 0x800F1228: add.s       $f0, $f8, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f14.fl;
;}
RECOMP_FUNC void func_80800AC0_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AC8: jal         0x808001A8
    // 0x80800ACC: nop

    func_808001A8_bsledge(rdram, ctx);
        goto after_0;
    // 0x80800ACC: nop

    after_0:
    // 0x80800AD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800AD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800AD8: jr          $ra
    // 0x80800ADC: nop

    return;
    // 0x80800ADC: nop

;}
RECOMP_FUNC void func_80800064_chwarppad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080006C: lhu         $t7, 0x76($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X76);
    // 0x80800070: addiu       $t6, $a1, 0x32
    ctx->r14 = ADD32(ctx->r5, 0X32);
    // 0x80800074: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800078: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x8080007C: bnel        $t6, $t8, L_80800090
    if (ctx->r14 != ctx->r24) {
        // 0x80800080: lw          $t9, 0x2C($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X2C);
            goto L_80800090;
    }
    goto skip_0;
    // 0x80800080: lw          $t9, 0x2C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X2C);
    skip_0:
    // 0x80800084: b           L_808000A4
    // 0x80800088: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000A4;
    // 0x80800088: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080008C: lw          $t9, 0x2C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X2C);
L_80800090:
    // 0x80800090: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80800094: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80800098: addu        $a0, $t0, $a1
    ctx->r4 = ADD32(ctx->r8, ctx->r5);
    // 0x8080009C: jal         0x800DA298
    // 0x808000A0: addiu       $a0, $a0, 0x3AB
    ctx->r4 = ADD32(ctx->r4, 0X3AB);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808000A0: addiu       $a0, $a0, 0x3AB
    ctx->r4 = ADD32(ctx->r4, 0X3AB);
    after_0:
L_808000A4:
    // 0x808000A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void _bamoveledge_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084E70: syscall     139
    recomp_syscall_handler(rdram, ctx, 0x80084E70);
    return;
    // 0x80084E74: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80802F00_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802F00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802F04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802F08: jal         0x80802ED4
    // 0x80802F0C: nop

    func_80802ED4_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80802F0C: nop

    after_0:
    // 0x80802F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802F14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802F18: jr          $ra
    // 0x80802F1C: nop

    return;
    // 0x80802F1C: nop

;}
RECOMP_FUNC void gcskyDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080015C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80800160: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800164: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800168: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8080016C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800170: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800174: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800178: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080017C: jal         0x800EA05C
    // 0x80800180: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800180: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800184: jal         0x80800000
    // 0x80800188: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80800000_gcskyDll(rdram, ctx);
        goto after_1;
    // 0x80800188: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080018C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800190: jal         0x800EFD24
    // 0x80800194: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x80800194: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    after_2:
    // 0x80800198: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
    // 0x8080019C: addiu       $s1, $sp, 0x64
    ctx->r17 = ADD32(ctx->r29, 0X64);
    // 0x808001A0: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    // 0x808001A4: or          $s2, $s5, $zero
    ctx->r18 = ctx->r21 | 0;
    // 0x808001A8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_808001AC:
    // 0x808001AC: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x808001B0: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x808001B4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x808001B8: sw          $zero, 0x20($s2)
    MEM_W(0X20, ctx->r18) = 0;
    // 0x808001BC: sw          $zero, 0x24($s2)
    MEM_W(0X24, ctx->r18) = 0;
    // 0x808001C0: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x808001C4: lh          $a0, 0x4($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X4);
    // 0x808001C8: beql        $a0, $zero, L_808003AC
    if (ctx->r4 == 0) {
        // 0x808001CC: addiu       $s4, $s4, 0x10
        ctx->r20 = ADD32(ctx->r20, 0X10);
            goto L_808003AC;
    }
    goto skip_0;
    // 0x808001CC: addiu       $s4, $s4, 0x10
    ctx->r20 = ADD32(ctx->r20, 0X10);
    skip_0:
    // 0x808001D0: jal         0x800D674C
    // 0x808001D4: nop

    func_800D674C(rdram, ctx);
        goto after_3;
    // 0x808001D4: nop

    after_3:
    // 0x808001D8: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x808001DC: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x808001E0: bne         $t6, $zero, L_808001FC
    if (ctx->r14 != 0) {
        // 0x808001E4: nop
    
            goto L_808001FC;
    }
    // 0x808001E4: nop

    // 0x808001E8: jal         0x800B27FC
    // 0x808001EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B27FC(rdram, ctx);
        goto after_4;
    // 0x808001EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x808001F0: jal         0x80087A30
    // 0x808001F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _dbtex_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x808001F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x808001F8: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
L_808001FC:
    // 0x808001FC: jal         0x800D70D0
    // 0x80800200: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D70D0(rdram, ctx);
        goto after_6;
    // 0x80800200: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80800204: jal         0x800D71F4
    // 0x80800208: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D71F4(rdram, ctx);
        goto after_7;
    // 0x80800208: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x8080020C: jal         0x800B274C
    // 0x80800210: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    func_800B274C(rdram, ctx);
        goto after_8;
    // 0x80800210: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    after_8:
    // 0x80800214: beq         $v0, $zero, L_80800234
    if (ctx->r2 == 0) {
        // 0x80800218: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800234;
    }
    // 0x80800218: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080021C: jal         0x800888A0
    // 0x80800220: lh          $a0, 0x4($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X4);
    _glidmake_entrypoint_5(rdram, ctx);
        goto after_9;
    // 0x80800220: lh          $a0, 0x4($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X4);
    after_9:
    // 0x80800224: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80800228: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080022C: jal         0x80088F20
    // 0x80800230: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _idworldmake_entrypoint_0(rdram, ctx);
        goto after_10;
    // 0x80800230: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
L_80800234:
    // 0x80800234: jal         0x800DBFF8
    // 0x80800238: nop

    func_800DBFF8(rdram, ctx);
        goto after_11;
    // 0x80800238: nop

    after_11:
    // 0x8080023C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80800240: jal         0x800B2840
    // 0x80800244: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    func_800B2840(rdram, ctx);
        goto after_12;
    // 0x80800244: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    after_12:
    // 0x80800248: sw          $v0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r2;
    // 0x8080024C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800250: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x80800254: jal         0x800B2198
    // 0x80800258: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    func_800B2198(rdram, ctx);
        goto after_13;
    // 0x80800258: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    after_13:
    // 0x8080025C: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80800260: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80800264: jal         0x800F2100
    // 0x80800268: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    mlAbsF(rdram, ctx);
        goto after_14;
    // 0x80800268: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_14:
    // 0x8080026C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800270: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x80800274: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80800278: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8080027C: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x80800280: jal         0x800F2100
    // 0x80800284: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    mlAbsF(rdram, ctx);
        goto after_15;
    // 0x80800284: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_15:
    // 0x80800288: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8080028C: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x80800290: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80800294: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80800298: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x8080029C: jal         0x800F2100
    // 0x808002A0: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    mlAbsF(rdram, ctx);
        goto after_16;
    // 0x808002A0: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    after_16:
    // 0x808002A4: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808002A8: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x808002AC: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x808002B0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x808002B4: sw          $t5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r13;
    // 0x808002B8: jal         0x800F2100
    // 0x808002BC: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    mlAbsF(rdram, ctx);
        goto after_17;
    // 0x808002BC: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_17:
    // 0x808002C0: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808002C4: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x808002C8: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x808002CC: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x808002D0: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x808002D4: jal         0x800F2100
    // 0x808002D8: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    mlAbsF(rdram, ctx);
        goto after_18;
    // 0x808002D8: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_18:
    // 0x808002DC: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808002E0: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x808002E4: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x808002E8: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x808002EC: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x808002F0: jal         0x800F2100
    // 0x808002F4: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    mlAbsF(rdram, ctx);
        goto after_19;
    // 0x808002F4: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    after_19:
    // 0x808002F8: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808002FC: addiu       $v0, $sp, 0x78
    ctx->r2 = ADD32(ctx->r29, 0X78);
    // 0x80800300: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x80800304: addiu       $v1, $sp, 0x58
    ctx->r3 = ADD32(ctx->r29, 0X58);
    // 0x80800308: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8080030C: nop

    // 0x80800310: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
L_80800314:
    // 0x80800314: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80800318: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8080031C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800320: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80800324: nop

    // 0x80800328: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080032C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800330: nop

    // 0x80800334: bc1fl       L_80800348
    if (!c1cs) {
        // 0x80800338: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_80800348;
    }
    goto skip_1;
    // 0x80800338: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x8080033C: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x80800340: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800344: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_80800348:
    // 0x80800348: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8080034C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80800350: nop

    // 0x80800354: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800358: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8080035C: nop

    // 0x80800360: bc1f        L_8080036C
    if (!c1cs) {
        // 0x80800364: nop
    
            goto L_8080036C;
    }
    // 0x80800364: nop

    // 0x80800368: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
L_8080036C:
    // 0x8080036C: bne         $v1, $s1, L_80800314
    if (ctx->r3 != ctx->r17) {
        // 0x80800370: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80800314;
    }
    // 0x80800370: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800374: lwc1        $f8, 0x8($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80800378: swc1        $f8, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f8.u32l;
    // 0x8080037C: lwc1        $f10, 0xC($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80800380: swc1        $f10, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f10.u32l;
    // 0x80800384: lw          $t7, 0x10($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X10);
    // 0x80800388: beql        $t7, $zero, L_808003AC
    if (ctx->r15 == 0) {
        // 0x8080038C: addiu       $s4, $s4, 0x10
        ctx->r20 = ADD32(ctx->r20, 0X10);
            goto L_808003AC;
    }
    goto skip_2;
    // 0x8080038C: addiu       $s4, $s4, 0x10
    ctx->r20 = ADD32(ctx->r20, 0X10);
    skip_2:
    // 0x80800390: jal         0x800D5B24
    // 0x80800394: nop

    func_800D5B24(rdram, ctx);
        goto after_20;
    // 0x80800394: nop

    after_20:
    // 0x80800398: lw          $a0, 0x20($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X20);
    // 0x8080039C: jal         0x800B2400
    // 0x808003A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800B2400(rdram, ctx);
        goto after_21;
    // 0x808003A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x808003A4: sw          $v0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r2;
    // 0x808003A8: addiu       $s4, $s4, 0x10
    ctx->r20 = ADD32(ctx->r20, 0X10);
L_808003AC:
    // 0x808003AC: slti        $at, $s4, 0x20
    ctx->r1 = SIGNED(ctx->r20) < 0X20 ? 1 : 0;
    // 0x808003B0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808003B4: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x808003B8: bne         $at, $zero, L_808001AC
    if (ctx->r1 != 0) {
        // 0x808003BC: addiu       $s3, $s3, 0x10
        ctx->r19 = ADD32(ctx->r19, 0X10);
            goto L_808001AC;
    }
    // 0x808003BC: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x808003C0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808003C4: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    // 0x808003C8: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x808003CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003D0:
    // 0x808003D0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808003D4: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x808003D8: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x808003DC: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x808003E0: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x808003E4: bne         $v1, $a0, L_808003D0
    if (ctx->r3 != ctx->r4) {
        // 0x808003E8: sw          $v0, 0x20($s0)
        MEM_W(0X20, ctx->r16) = ctx->r2;
            goto L_808003D0;
    }
    // 0x808003E8: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x808003EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808003F0: jal         0x800BFCD0
    // 0x808003F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BFCD0(rdram, ctx);
        goto after_22;
    // 0x808003F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x808003F8: jal         0x800EEF94
    // 0x808003FC: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    func_800EEF94(rdram, ctx);
        goto after_23;
    // 0x808003FC: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    after_23:
    // 0x80800400: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800404: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800408: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8080040C: swc1        $f6, 0x134($s5)
    MEM_W(0X134, ctx->r21) = ctx->f6.u32l;
    // 0x80800410: addiu       $t0, $t9, 0x64
    ctx->r8 = ADD32(ctx->r25, 0X64);
    // 0x80800414: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80800418: nop

    // 0x8080041C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800420: swc1        $f4, 0x130($s5)
    MEM_W(0X130, ctx->r21) = ctx->f4.u32l;
    // 0x80800424: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800428: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8080042C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80800430: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800434: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800438: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080043C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800440: jr          $ra
    // 0x80800444: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80800444: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void _bskazow_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083518: syscall     64
    recomp_syscall_handler(rdram, ctx, 0x80083518);
    return;
    // 0x8008351C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8008CA74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CA74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008CA78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CA7C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8008CA80: jal         0x8008B4D4
    // 0x8008CA84: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_8008B4D4(rdram, ctx);
        goto after_0;
    // 0x8008CA84: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x8008CA88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008CA8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008CA90: jr          $ra
    // 0x8008CA94: nop

    return;
    // 0x8008CA94: nop

;}
RECOMP_FUNC void bskazstilt_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B14: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800B18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800B1C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800B20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B24: jal         0x8008CABC
    // 0x80800B28: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800B28: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    after_0:
    // 0x80800B2C: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80800B30: jal         0x808000C8
    // 0x80800B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000C8_bskazstilt(rdram, ctx);
        goto after_1;
    // 0x80800B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800B38: jal         0x80800064
    // 0x80800B3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800064_bskazstilt(rdram, ctx);
        goto after_2;
    // 0x80800B3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800B40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B44: jal         0x8009BB24
    // 0x80800B48: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_8009BB24(rdram, ctx);
        goto after_3;
    // 0x80800B48: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_3:
    // 0x80800B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B50: jal         0x80091A30
    // 0x80800B54: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_4;
    // 0x80800B54: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_4:
    // 0x80800B58: beq         $v0, $zero, L_80800B80
    if (ctx->r2 == 0) {
        // 0x80800B5C: lwc1        $f6, 0x40($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
            goto L_80800B80;
    }
    // 0x80800B5C: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800B60: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800B64: nop

    // 0x80800B68: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800B6C: nop

    // 0x80800B70: bc1f        L_80800B80
    if (!c1cs) {
        // 0x80800B74: nop
    
            goto L_80800B80;
    }
    // 0x80800B74: nop

    // 0x80800B78: jal         0x8009BC6C
    // 0x80800B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_5;
    // 0x80800B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_80800B80:
    // 0x80800B80: jal         0x8009C150
    // 0x80800B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009C150(rdram, ctx);
        goto after_6;
    // 0x80800B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800B88: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80800B8C: jal         0x80096364
    // 0x80800B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096364(rdram, ctx);
        goto after_7;
    // 0x80800B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800B94: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800B98: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x80800B9C: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800BA0: sub.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80800BA4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800BA8: beq         $v0, $zero, L_80800BDC
    if (ctx->r2 == 0) {
        // 0x80800BAC: mov.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
            goto L_80800BDC;
    }
    // 0x80800BAC: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x80800BB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800BB4: beq         $v0, $at, L_80800C5C
    if (ctx->r2 == ctx->r1) {
        // 0x80800BB8: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80800C5C;
    }
    // 0x80800BB8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800BBC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800BC0: beq         $v0, $at, L_80800CC8
    if (ctx->r2 == ctx->r1) {
        // 0x80800BC4: lui         $a2, 0x3F80
        ctx->r6 = S32(0X3F80 << 16);
            goto L_80800CC8;
    }
    // 0x80800BC4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800BC8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800BCC: beq         $v0, $at, L_80800D4C
    if (ctx->r2 == ctx->r1) {
        // 0x80800BD0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D4C;
    }
    // 0x80800BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BD4: b           L_80800D9C
    // 0x80800BD8: nop

        goto L_80800D9C;
    // 0x80800BD8: nop

L_80800BDC:
    // 0x80800BDC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800BE0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800BE4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800BE8: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80800BEC: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80800BF0: bc1t        L_80800C10
    if (c1cs) {
        // 0x80800BF4: nop
    
            goto L_80800C10;
    }
    // 0x80800BF4: nop

    // 0x80800BF8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800BFC: nop

    // 0x80800C00: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80800C04: nop

    // 0x80800C08: bc1f        L_80800C18
    if (!c1cs) {
        // 0x80800C0C: nop
    
            goto L_80800C18;
    }
    // 0x80800C0C: nop

L_80800C10:
    // 0x80800C10: jal         0x8008B1BC
    // 0x80800C14: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    anctrl_setDuration(rdram, ctx);
        goto after_8;
    // 0x80800C14: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_8:
L_80800C18:
    // 0x80800C18: jal         0x8008B324
    // 0x80800C1C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    anctrl_isStopped(rdram, ctx);
        goto after_9;
    // 0x80800C1C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_9:
    // 0x80800C20: beq         $v0, $zero, L_80800D9C
    if (ctx->r2 == 0) {
        // 0x80800C24: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80800D9C;
    }
    // 0x80800C24: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800C28: lui         $a2, 0x3F07
    ctx->r6 = S32(0X3F07 << 16);
    // 0x80800C2C: ori         $a2, $a2, 0x381D
    ctx->r6 = ctx->r6 | 0X381D;
    // 0x80800C30: jal         0x8008B1D4
    // 0x80800C34: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_10;
    // 0x80800C34: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_10:
    // 0x80800C38: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800C3C: jal         0x8008B1BC
    // 0x80800C40: lui         $a1, 0x4090
    ctx->r5 = S32(0X4090 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_11;
    // 0x80800C40: lui         $a1, 0x4090
    ctx->r5 = S32(0X4090 << 16);
    after_11:
    // 0x80800C44: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800C48: jal         0x8008B134
    // 0x80800C4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_12;
    // 0x80800C4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800C50: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800C54: b           L_80800D9C
    // 0x80800C58: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
        goto L_80800D9C;
    // 0x80800C58: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_80800C5C:
    // 0x80800C5C: jal         0x8008B2B4
    // 0x80800C60: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    anctrl_getAnimTimer(rdram, ctx);
        goto after_13;
    // 0x80800C60: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    after_13:
    // 0x80800C64: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(292, 0X11F8) << 16);
    // 0x80800C68: lwc1        $f4, 0x11F8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(292, 0X11F8));
    // 0x80800C6C: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80800C70: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800C74: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800C78: nop

    // 0x80800C7C: bc1f        L_80800D9C
    if (!c1cs) {
        // 0x80800C80: nop
    
            goto L_80800D9C;
    }
    // 0x80800C80: nop

    // 0x80800C84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800C88: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800C8C: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80800C90: nop

    // 0x80800C94: bc1f        L_80800D9C
    if (!c1cs) {
        // 0x80800C98: nop
    
            goto L_80800D9C;
    }
    // 0x80800C98: nop

    // 0x80800C9C: jal         0x8008B2B4
    // 0x80800CA0: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    anctrl_getAnimTimer(rdram, ctx);
        goto after_14;
    // 0x80800CA0: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    after_14:
    // 0x80800CA4: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800CA8: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x80800CAC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800CB0: swc1        $f12, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f12.u32l;
    // 0x80800CB4: jal         0x8008B134
    // 0x80800CB8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_15;
    // 0x80800CB8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_15:
    // 0x80800CBC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80800CC0: b           L_80800D9C
    // 0x80800CC4: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
        goto L_80800D9C;
    // 0x80800CC4: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_80800CC8:
    // 0x80800CC8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(292, 0X11FC) << 16);
    // 0x80800CCC: lwc1        $f8, 0x11FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(292, 0X11FC));
    // 0x80800CD0: lwc1        $f14, 0x170($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X170);
    // 0x80800CD4: lw          $a3, 0x16C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X16C);
    // 0x80800CD8: jal         0x800F10B4
    // 0x80800CDC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_16;
    // 0x80800CDC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_16:
    // 0x80800CE0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800CE4: jal         0x8008B10C
    // 0x80800CE8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_8008B10C(rdram, ctx);
        goto after_17;
    // 0x80800CE8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_17:
    // 0x80800CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800CF4: jal         0x8009D2F0
    // 0x80800CF8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_8009D2F0(rdram, ctx);
        goto after_18;
    // 0x80800CF8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_18:
    // 0x80800CFC: jal         0x8008E078
    // 0x80800D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_19;
    // 0x80800D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800D04: beq         $v0, $zero, L_80800D9C
    if (ctx->r2 == 0) {
        // 0x80800D08: nop
    
            goto L_80800D9C;
    }
    // 0x80800D08: nop

    // 0x80800D0C: jal         0x8009FE58
    // 0x80800D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FE58(rdram, ctx);
        goto after_20;
    // 0x80800D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800D14: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800D18: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800D1C: jal         0x8008B1D4
    // 0x80800D20: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    anctrl_setSubrange(rdram, ctx);
        goto after_21;
    // 0x80800D20: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_21:
    // 0x80800D24: lui         $a1, 0x3FA6
    ctx->r5 = S32(0X3FA6 << 16);
    // 0x80800D28: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800D2C: jal         0x8008B1BC
    // 0x80800D30: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    anctrl_setDuration(rdram, ctx);
        goto after_22;
    // 0x80800D30: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_22:
    // 0x80800D34: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800D38: jal         0x8008B134
    // 0x80800D3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_23;
    // 0x80800D3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x80800D40: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80800D44: b           L_80800D9C
    // 0x80800D48: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
        goto L_80800D9C;
    // 0x80800D48: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
L_80800D4C:
    // 0x80800D4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800D50: jal         0x8009D2F0
    // 0x80800D54: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_8009D2F0(rdram, ctx);
        goto after_24;
    // 0x80800D54: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_24:
    // 0x80800D58: jal         0x8008B324
    // 0x80800D5C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    anctrl_isStopped(rdram, ctx);
        goto after_25;
    // 0x80800D5C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_25:
    // 0x80800D60: beq         $v0, $zero, L_80800D70
    if (ctx->r2 == 0) {
        // 0x80800D64: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D70;
    }
    // 0x80800D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D68: addiu       $t9, $zero, 0x48
    ctx->r25 = ADD32(0, 0X48);
    // 0x80800D6C: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
L_80800D70:
    // 0x80800D70: jal         0x80091A58
    // 0x80800D74: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_26;
    // 0x80800D74: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_26:
    // 0x80800D78: beq         $v0, $zero, L_80800D88
    if (ctx->r2 == 0) {
        // 0x80800D7C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D88;
    }
    // 0x80800D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D80: addiu       $t0, $zero, 0x4A
    ctx->r8 = ADD32(0, 0X4A);
    // 0x80800D84: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
L_80800D88:
    // 0x80800D88: jal         0x800915AC
    // 0x80800D8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_isDone(rdram, ctx);
        goto after_27;
    // 0x80800D8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_27:
    // 0x80800D90: beq         $v0, $zero, L_80800D9C
    if (ctx->r2 == 0) {
        // 0x80800D94: addiu       $t1, $zero, 0x4B
        ctx->r9 = ADD32(0, 0X4B);
            goto L_80800D9C;
    }
    // 0x80800D94: addiu       $t1, $zero, 0x4B
    ctx->r9 = ADD32(0, 0X4B);
    // 0x80800D98: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
L_80800D9C:
    // 0x80800D9C: jal         0x80800000
    // 0x80800DA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bskazstilt(rdram, ctx);
        goto after_28;
    // 0x80800DA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80800DA4: beq         $v0, $zero, L_80800DB4
    if (ctx->r2 == 0) {
        // 0x80800DA8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800DB4;
    }
    // 0x80800DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DAC: addiu       $t2, $zero, 0x160
    ctx->r10 = ADD32(0, 0X160);
    // 0x80800DB0: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
L_80800DB4:
    // 0x80800DB4: jal         0x8009E5C8
    // 0x80800DB8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    bs_setState(rdram, ctx);
        goto after_29;
    // 0x80800DB8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_29:
    // 0x80800DBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800DC0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800DC4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800DC8: jr          $ra
    // 0x80800DCC: nop

    return;
    // 0x80800DCC: nop

;}
RECOMP_FUNC void func_8080072C_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080072C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800730: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800734: jal         0x808001A8
    // 0x80800738: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808001A8_bsledge(rdram, ctx);
        goto after_0;
    // 0x80800738: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080073C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800740: jal         0x800961AC
    // 0x80800744: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_1;
    // 0x80800744: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800748: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080074C: jal         0x80085358
    // 0x80800750: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batranslate_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800750: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800758: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080075C: jr          $ra
    // 0x80800760: nop

    return;
    // 0x80800760: nop

;}
RECOMP_FUNC void func_800F0DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0DC0: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x800F0DC4: nop

    // 0x800F0DC8: bc1fl       L_800F0DDC
    if (!c1cs) {
        // 0x800F0DCC: neg.s       $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
            goto L_800F0DDC;
    }
    goto skip_0;
    // 0x800F0DCC: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
    skip_0:
    // 0x800F0DD0: jr          $ra
    // 0x800F0DD4: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    return;
    // 0x800F0DD4: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x800F0DD8: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
L_800F0DDC:
    // 0x800F0DDC: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800F0DE0: nop

    // 0x800F0DE4: bc1fl       L_800F0DF8
    if (!c1cs) {
        // 0x800F0DE8: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_800F0DF8;
    }
    goto skip_1;
    // 0x800F0DE8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_1:
    // 0x800F0DEC: jr          $ra
    // 0x800F0DF0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800F0DF0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800F0DF4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800F0DF8:
    // 0x800F0DF8: jr          $ra
    // 0x800F0DFC: nop

    return;
    // 0x800F0DFC: nop

;}
RECOMP_FUNC void func_80800450_gcfrontend(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800450: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2650, 0XD80) << 16);
    // 0x80800454: lbu         $v0, 0xD80($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(2650, 0XD80));
    // 0x80800458: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2650, 0XD8C) << 16);
    // 0x8080045C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2650, 0XD81) << 16);
    // 0x80800460: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800464: bne         $at, $zero, L_80800488
    if (ctx->r1 != 0) {
        // 0x80800468: nop
    
            goto L_80800488;
    }
    // 0x80800468: nop

    // 0x8080046C: lbu         $t6, 0xD81($t6)
    ctx->r14 = MEM_BU(ctx->r14, (int16_t)RELOC_LO16(2650, 0XD81));
    // 0x80800470: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80800474: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80800478: beq         $at, $zero, L_80800488
    if (ctx->r1 == 0) {
        // 0x8080047C: nop
    
            goto L_80800488;
    }
    // 0x8080047C: nop

    // 0x80800480: jr          $ra
    // 0x80800484: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800484: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800488:
    // 0x80800488: lbu         $v1, 0xD8C($v1)
    ctx->r3 = MEM_BU(ctx->r3, (int16_t)RELOC_LO16(2650, 0XD8C));
    // 0x8080048C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2650, 0XD8D) << 16);
    // 0x80800490: lbu         $t8, 0xD8D($t8)
    ctx->r24 = MEM_BU(ctx->r24, (int16_t)RELOC_LO16(2650, 0XD8D));
    // 0x80800494: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800498: bne         $at, $zero, L_808004B4
    if (ctx->r1 != 0) {
        // 0x8080049C: addu        $v0, $t8, $v1
        ctx->r2 = ADD32(ctx->r24, ctx->r3);
            goto L_808004B4;
    }
    // 0x8080049C: addu        $v0, $t8, $v1
    ctx->r2 = ADD32(ctx->r24, ctx->r3);
    // 0x808004A0: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808004A4: beq         $at, $zero, L_808004B4
    if (ctx->r1 == 0) {
        // 0x808004A8: nop
    
            goto L_808004B4;
    }
    // 0x808004A8: nop

    // 0x808004AC: jr          $ra
    // 0x808004B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808004B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004B4:
    // 0x808004B4: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2650, 0XD98) << 16);
    // 0x808004B8: lbu         $v1, 0xD98($v1)
    ctx->r3 = MEM_BU(ctx->r3, (int16_t)RELOC_LO16(2650, 0XD98));
    // 0x808004BC: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2650, 0XD99) << 16);
    // 0x808004C0: lbu         $t9, 0xD99($t9)
    ctx->r25 = MEM_BU(ctx->r25, (int16_t)RELOC_LO16(2650, 0XD99));
    // 0x808004C4: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x808004C8: bne         $at, $zero, L_808004E4
    if (ctx->r1 != 0) {
        // 0x808004CC: addu        $v0, $t9, $v1
        ctx->r2 = ADD32(ctx->r25, ctx->r3);
            goto L_808004E4;
    }
    // 0x808004CC: addu        $v0, $t9, $v1
    ctx->r2 = ADD32(ctx->r25, ctx->r3);
    // 0x808004D0: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808004D4: beq         $at, $zero, L_808004E4
    if (ctx->r1 == 0) {
        // 0x808004D8: nop
    
            goto L_808004E4;
    }
    // 0x808004D8: nop

    // 0x808004DC: jr          $ra
    // 0x808004E0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x808004E0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_808004E4:
    // 0x808004E4: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2650, 0XDA4) << 16);
    // 0x808004E8: lbu         $v1, 0xDA4($v1)
    ctx->r3 = MEM_BU(ctx->r3, (int16_t)RELOC_LO16(2650, 0XDA4));
    // 0x808004EC: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2650, 0XDA5) << 16);
    // 0x808004F0: lbu         $t0, 0xDA5($t0)
    ctx->r8 = MEM_BU(ctx->r8, (int16_t)RELOC_LO16(2650, 0XDA5));
    // 0x808004F4: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x808004F8: bne         $at, $zero, L_80800514
    if (ctx->r1 != 0) {
        // 0x808004FC: addu        $v0, $t0, $v1
        ctx->r2 = ADD32(ctx->r8, ctx->r3);
            goto L_80800514;
    }
    // 0x808004FC: addu        $v0, $t0, $v1
    ctx->r2 = ADD32(ctx->r8, ctx->r3);
    // 0x80800500: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800504: beql        $at, $zero, L_80800518
    if (ctx->r1 == 0) {
        // 0x80800508: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80800518;
    }
    goto skip_0;
    // 0x80800508: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    skip_0:
    // 0x8080050C: jr          $ra
    // 0x80800510: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x80800510: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800514:
    // 0x80800514: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800518:
    // 0x80800518: jr          $ra
    // 0x8080051C: nop

    return;
    // 0x8080051C: nop

;}
RECOMP_FUNC void func_80800204_chklungophial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800204: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800208: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080020C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800210: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800214: jal         0x80100094
    // 0x80800218: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800218: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080021C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800220: jal         0x800D9078
    // 0x80800224: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x80800224: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    after_1:
    // 0x80800228: beq         $v0, $zero, L_80800240
    if (ctx->r2 == 0) {
        // 0x8080022C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800240;
    }
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800230: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1244, 0XCCC) << 16);
    // 0x80800234: addiu       $a2, $a2, 0xCCC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1244, 0XCCC));
    // 0x80800238: jal         0x80089D18
    // 0x8080023C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x8080023C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_2:
L_80800240:
    // 0x80800240: addiu       $t6, $s0, 0x4
    ctx->r14 = ADD32(ctx->r16, 0X4);
    // 0x80800244: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80800248: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x8080024C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800250: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800254: bne         $t8, $at, L_80800328
    if (ctx->r24 != ctx->r1) {
        // 0x80800258: nop
    
            goto L_80800328;
    }
    // 0x80800258: nop

    // 0x8080025C: jal         0x800D8FF8
    // 0x80800260: nop

    func_800D8FF8(rdram, ctx);
        goto after_3;
    // 0x80800260: nop

    after_3:
    // 0x80800264: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80800268: addiu       $a0, $zero, 0x423
    ctx->r4 = ADD32(0, 0X423);
    // 0x8080026C: jal         0x80089C30
    // 0x80800270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800274: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800278: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8080027C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800280: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800284: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800288: jal         0x800136E4
    // 0x8080028C: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_5;
    // 0x8080028C: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_5:
    // 0x80800290: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80800294: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800298: lwc1        $f18, 0x54($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8080029C: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x808002A0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808002A4: jal         0x800136E4
    // 0x808002A8: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_6;
    // 0x808002A8: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_6:
    // 0x808002AC: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x808002B0: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x808002B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808002B8: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808002BC: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808002C0: lui         $a1, 0x40
    ctx->r5 = S32(0X40 << 16);
    // 0x808002C4: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x808002C8: ori         $a1, $a1, 0x7
    ctx->r5 = ctx->r5 | 0X7;
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D0: sub.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x808002D4: jal         0x8010B990
    // 0x808002D8: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    func_8010B990(rdram, ctx);
        goto after_7;
    // 0x808002D8: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    after_7:
    // 0x808002DC: andi        $t9, $v0, 0x20
    ctx->r25 = ctx->r2 & 0X20;
    // 0x808002E0: beq         $t9, $zero, L_808002F0
    if (ctx->r25 == 0) {
        // 0x808002E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002F0;
    }
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E8: jal         0x808003C8
    // 0x808002EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808003C8_chklungophial(rdram, ctx);
        goto after_8;
    // 0x808002EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
L_808002F0:
    // 0x808002F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1244, 0XBF4) << 16);
    // 0x808002F4: jal         0x800DC298
    // 0x808002F8: lwc1        $f12, 0xBF4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1244, 0XBF4));
    func_800DC298(rdram, ctx);
        goto after_9;
    // 0x808002F8: lwc1        $f12, 0xBF4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1244, 0XBF4));
    after_9:
    // 0x808002FC: beq         $v0, $zero, L_80800328
    if (ctx->r2 == 0) {
        // 0x80800300: lw          $t0, 0x34($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X34);
            goto L_80800328;
    }
    // 0x80800300: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80800304: beq         $t0, $zero, L_80800328
    if (ctx->r8 == 0) {
        // 0x80800308: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_80800328;
    }
    // 0x80800308: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080030C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800310: jal         0x8008A0E8
    // 0x80800314: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    _subaddieskeleton_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x80800314: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_10:
    // 0x80800318: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8080031C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800320: jal         0x80800AEC
    // 0x80800324: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_80800AEC_chklungophial(rdram, ctx);
        goto after_11;
    // 0x80800324: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_11:
L_80800328:
    // 0x80800328: jal         0x800BFA1C
    // 0x8080032C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800BFA1C(rdram, ctx);
        goto after_12;
    // 0x8080032C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_12:
    // 0x80800330: bnel        $v0, $zero, L_80800364
    if (ctx->r2 != 0) {
        // 0x80800334: lw          $t3, 0x3C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X3C);
            goto L_80800364;
    }
    goto skip_0;
    // 0x80800334: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x80800338: jal         0x800FFAB0
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_13;
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800340: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80800344: lw          $a0, 0xC($t1)
    ctx->r4 = MEM_W(ctx->r9, 0XC);
    // 0x80800348: beql        $a0, $zero, L_80800364
    if (ctx->r4 == 0) {
        // 0x8080034C: lw          $t3, 0x3C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X3C);
            goto L_80800364;
    }
    goto skip_1;
    // 0x8080034C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x80800350: jal         0x800C8B84
    // 0x80800354: nop

    func_800C8B84(rdram, ctx);
        goto after_14;
    // 0x80800354: nop

    after_14:
    // 0x80800358: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8080035C: sw          $zero, 0xC($t2)
    MEM_W(0XC, ctx->r10) = 0;
    // 0x80800360: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
L_80800364:
    // 0x80800364: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x80800368: beql        $a0, $zero, L_8080037C
    if (ctx->r4 == 0) {
        // 0x8080036C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080037C;
    }
    goto skip_2;
    // 0x8080036C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800370: jal         0x800C8CB8
    // 0x80800374: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800C8CB8(rdram, ctx);
        goto after_15;
    // 0x80800374: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_15:
    // 0x80800378: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080037C:
    // 0x8080037C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800380: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800384: jr          $ra
    // 0x80800388: nop

    return;
    // 0x80800388: nop

;}
RECOMP_FUNC void func_80800318_bsmummove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800318: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080031C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800320: jal         0x80083800
    // 0x80800324: nop

    _bsmum_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800324: nop

    after_0:
    // 0x80800328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080032C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800330: jr          $ra
    // 0x80800334: nop

    return;
    // 0x80800334: nop

;}
RECOMP_FUNC void _sumole_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089A00: syscall     800
    recomp_syscall_handler(rdram, ctx, 0x80089A00);
    return;
    // 0x80089A04: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800DBE60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DBE60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DBE64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DBE68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DBE6C: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800DBE70: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800DBE74: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800DBE78: jal         0x800DB9D0
    // 0x800DBE7C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800DB9D0(rdram, ctx);
        goto after_0;
    // 0x800DBE7C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800DBE80: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800DBE84: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800DBE88: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800DBE8C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800DBE90: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x800DBE94: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800DBE98: swc1        $f6, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->f6.u32l;
    // 0x800DBE9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DBEA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DBEA4: jr          $ra
    // 0x800DBEA8: nop

    return;
    // 0x800DBEA8: nop

;}
RECOMP_FUNC void chnests_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F5C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(752, 0X12C0) << 16);
    // 0x80800F60: jr          $ra
    // 0x80800F64: addiu       $v0, $v0, 0x12C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X12C0));
    return;
    // 0x80800F64: addiu       $v0, $v0, 0x12C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X12C0));
;}
RECOMP_FUNC void func_8009E4FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E4FC: lw          $t6, 0x114($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X114);
    // 0x8009E500: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8009E504: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8009E508: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8009E50C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8009E510: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8009E514: swc1        $f12, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f12.u32l;
    // 0x8009E518: lw          $t8, 0x114($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X114);
    // 0x8009E51C: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8009E520: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8009E524: swc1        $f14, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f14.u32l;
    // 0x8009E528: lw          $t0, 0x114($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X114);
    // 0x8009E52C: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8009E530: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8009E534: jr          $ra
    // 0x8009E538: swc1        $f4, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f4.u32l;
    return;
    // 0x8009E538: swc1        $f4, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f4.u32l;
;}
RECOMP_FUNC void chbiggafoot_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1216, 0X1094) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1094
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1216, 0X1094));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1094
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1216, 0X1094));
;}
RECOMP_FUNC void func_808003B8_chwarppad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003C0: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x808003C4: lhu         $t8, 0x76($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X76);
    // 0x808003C8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808003CC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x808003D0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x808003D4: srl         $t9, $t8, 7
    ctx->r25 = S32(U32(ctx->r24) >> 7);
    // 0x808003D8: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x808003DC: addiu       $a0, $a0, 0x379
    ctx->r4 = ADD32(ctx->r4, 0X379);
    // 0x808003E0: jal         0x800DA544
    // 0x808003E4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x808003E4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x808003E8: jal         0x80089CB0
    // 0x808003EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _subaddiefade_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x808003EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808003F0: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x808003F4: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808003F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808003FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800400: jal         0x800862D8
    // 0x80800404: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _chappearfx_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800404: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x80800408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080040C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800410: jr          $ra
    // 0x80800414: nop

    return;
    // 0x80800414: nop

;}
RECOMP_FUNC void func_800A7168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7168: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A716C: jr          $ra
    // 0x800A7170: addiu       $v0, $v0, -0x5C60
    ctx->r2 = ADD32(ctx->r2, -0X5C60);
    return;
    // 0x800A7170: addiu       $v0, $v0, -0x5C60
    ctx->r2 = ADD32(ctx->r2, -0X5C60);
    // 0x800A7174: nop

    // 0x800A7178: nop

    // 0x800A717C: nop

;}
RECOMP_FUNC void func_80800058_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080005C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800060: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800064: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800068: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080006C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80800070: jal         0x800EE7F8
    // 0x80800074: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800074: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x80800078: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8080007C: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800080: jal         0x800EF1B8
    // 0x80800084: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x80800084: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_1:
    // 0x80800088: jal         0x800F54E4
    // 0x8080008C: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x8080008C: nop

    after_2:
    // 0x80800090: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800094: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800098: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    // 0x8080009C: jal         0x800F4F34
    // 0x808000A0: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    func_800F4F34(rdram, ctx);
        goto after_3;
    // 0x808000A0: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    after_3:
    // 0x808000A4: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808000A8: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808000AC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808000B0: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x808000B4: beq         $at, $zero, L_80800250
    if (ctx->r1 == 0) {
        // 0x808000B8: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800250;
    }
    // 0x808000B8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808000BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1140, 0X2760) << 16);
    // 0x808000C0: addu        $at, $at, $t8
    gpr jr_addend_808000C8 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808000C4: lw          $t8, 0x2760($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1140, 0X2760));
    // 0x808000C8: jr          $t8
    // 0x808000CC: nop

    switch (jr_addend_808000C8 >> 2) {
        case 0: goto L_808000D0; break;
        case 1: goto L_80800130; break;
        case 2: goto L_80800158; break;
        case 3: goto L_808001B8; break;
        case 4: goto L_808001E0; break;
        default: switch_error(__func__, 0x808000C8, 0x80802760);
    }
    // 0x808000CC: nop

L_808000D0:
    // 0x808000D0: jal         0x80800264
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800264_chfactoryrobot(rdram, ctx);
        goto after_4;
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000D8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808000DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000E0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x808000E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000EC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808000F0: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    // 0x808000F4: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    // 0x808000F8: jal         0x808006DC
    // 0x808000FC: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    func_808006DC_chfactoryrobot(rdram, ctx);
        goto after_5;
    // 0x808000FC: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    after_5:
    // 0x80800100: beq         $v0, $zero, L_80800250
    if (ctx->r2 == 0) {
        // 0x80800104: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800250;
    }
    // 0x80800104: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800108: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080010C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1140, 0X2774) << 16);
    // 0x80800110: jal         0x800DC178
    // 0x80800114: lwc1        $f14, 0x2774($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1140, 0X2774));
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x80800114: lwc1        $f14, 0x2774($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1140, 0X2774));
    after_6:
    // 0x80800118: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800120: jal         0x80101FDC
    // 0x80800124: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x80800124: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x80800128: b           L_80800254
    // 0x8080012C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800254;
    // 0x8080012C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800130:
    // 0x80800130: jal         0x80800264
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800264_chfactoryrobot(rdram, ctx);
        goto after_8;
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800138: jal         0x800D9078
    // 0x8080013C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800D9078(rdram, ctx);
        goto after_9;
    // 0x8080013C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_9:
    // 0x80800140: beq         $v0, $zero, L_80800250
    if (ctx->r2 == 0) {
        // 0x80800144: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800250;
    }
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800148: jal         0x80101FDC
    // 0x8080014C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_10;
    // 0x8080014C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x80800150: b           L_80800254
    // 0x80800154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800254;
    // 0x80800154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800158:
    // 0x80800158: jal         0x80800264
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800264_chfactoryrobot(rdram, ctx);
        goto after_11;
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800160: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x80800164: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800168: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8080016C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800174: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80800178: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    // 0x8080017C: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    // 0x80800180: jal         0x808006DC
    // 0x80800184: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    func_808006DC_chfactoryrobot(rdram, ctx);
        goto after_12;
    // 0x80800184: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    after_12:
    // 0x80800188: beq         $v0, $zero, L_80800250
    if (ctx->r2 == 0) {
        // 0x8080018C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800250;
    }
    // 0x8080018C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800190: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800194: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1140, 0X2778) << 16);
    // 0x80800198: jal         0x800DC178
    // 0x8080019C: lwc1        $f14, 0x2778($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1140, 0X2778));
    func_800DC178(rdram, ctx);
        goto after_13;
    // 0x8080019C: lwc1        $f14, 0x2778($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1140, 0X2778));
    after_13:
    // 0x808001A0: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A8: jal         0x80101FDC
    // 0x808001AC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_14;
    // 0x808001AC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_14:
    // 0x808001B0: b           L_80800254
    // 0x808001B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800254;
    // 0x808001B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001B8:
    // 0x808001B8: jal         0x80800264
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800264_chfactoryrobot(rdram, ctx);
        goto after_15;
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808001C0: jal         0x800D9078
    // 0x808001C4: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800D9078(rdram, ctx);
        goto after_16;
    // 0x808001C4: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_16:
    // 0x808001C8: beq         $v0, $zero, L_80800250
    if (ctx->r2 == 0) {
        // 0x808001CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800250;
    }
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D0: jal         0x80101FDC
    // 0x808001D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_17;
    // 0x808001D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x808001D8: b           L_80800254
    // 0x808001DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800254;
    // 0x808001DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001E0:
    // 0x808001E0: jal         0x80800264
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800264_chfactoryrobot(rdram, ctx);
        goto after_18;
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808001E8: jal         0x8010D254
    // 0x808001EC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_8010D254(rdram, ctx);
        goto after_19;
    // 0x808001EC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_19:
    // 0x808001F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808001F4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x808001F8: jal         0x800F18FC
    // 0x808001FC: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_800F18FC(rdram, ctx);
        goto after_20;
    // 0x808001FC: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_20:
    // 0x80800200: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800204: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080020C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x80800210: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80800214: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    // 0x80800218: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    // 0x8080021C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800220: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80800224: jal         0x808006DC
    // 0x80800228: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    func_808006DC_chfactoryrobot(rdram, ctx);
        goto after_21;
    // 0x80800228: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    after_21:
    // 0x8080022C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800230: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800238: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x8080023C: nop

    // 0x80800240: bc1fl       L_80800254
    if (!c1cs) {
        // 0x80800244: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800254;
    }
    goto skip_0;
    // 0x80800244: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800248: jal         0x80101FDC
    // 0x8080024C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_22;
    // 0x8080024C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_22:
L_80800250:
    // 0x80800250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800254:
    // 0x80800254: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800258: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8080025C: jr          $ra
    // 0x80800260: nop

    return;
    // 0x80800260: nop

;}
RECOMP_FUNC void fxrain_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808004FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800500: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800504: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800508: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8080050C: jal         0x800D8FF8
    // 0x80800510: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800510: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    after_0:
    // 0x80800514: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800518: jal         0x800E3980
    // 0x8080051C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_800E3980(rdram, ctx);
        goto after_1;
    // 0x8080051C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_1:
    // 0x80800520: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x80800524: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800528: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
    // 0x8080052C: jal         0x800EFB24
    // 0x80800530: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x80800530: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_2:
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800538: jal         0x800EE7F8
    // 0x8080053C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x8080053C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_3:
    // 0x80800540: jal         0x800A5490
    // 0x80800544: nop

    func_800A5490(rdram, ctx);
        goto after_4;
    // 0x80800544: nop

    after_4:
    // 0x80800548: beq         $v0, $zero, L_80800558
    if (ctx->r2 == 0) {
        // 0x8080054C: nop
    
            goto L_80800558;
    }
    // 0x8080054C: nop

    // 0x80800550: jal         0x800B28B8
    // 0x80800554: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    vector_clear(rdram, ctx);
        goto after_5;
    // 0x80800554: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    after_5:
L_80800558:
    // 0x80800558: jal         0x800B2928
    // 0x8080055C: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    vector_size(rdram, ctx);
        goto after_6;
    // 0x8080055C: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    after_6:
    // 0x80800560: blezl       $v0, L_80800604
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800564: lbu         $a0, 0x0($s1)
        ctx->r4 = MEM_BU(ctx->r17, 0X0);
            goto L_80800604;
    }
    goto skip_0;
    // 0x80800564: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    skip_0:
    // 0x80800568: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x8080056C: bnel        $t6, $zero, L_8080061C
    if (ctx->r14 != 0) {
        // 0x80800570: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8080061C;
    }
    goto skip_1;
    // 0x80800570: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_1:
    // 0x80800574: jal         0x800C2E04
    // 0x80800578: nop

    func_800C2E04(rdram, ctx);
        goto after_7;
    // 0x80800578: nop

    after_7:
    // 0x8080057C: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x80800580: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80800584: jal         0x800C330C
    // 0x80800588: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C330C(rdram, ctx);
        goto after_8;
    // 0x80800588: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x8080058C: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x80800590: jal         0x800C301C
    // 0x80800594: addiu       $a1, $zero, 0x465
    ctx->r5 = ADD32(0, 0X465);
    func_800C301C(rdram, ctx);
        goto after_9;
    // 0x80800594: addiu       $a1, $zero, 0x465
    ctx->r5 = ADD32(0, 0X465);
    after_9:
    // 0x80800598: lui         $a1, 0x3F73
    ctx->r5 = S32(0X3F73 << 16);
    // 0x8080059C: lui         $a2, 0x3F86
    ctx->r6 = S32(0X3F86 << 16);
    // 0x808005A0: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x808005A4: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x808005A8: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808005AC: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808005B0: jal         0x800C37E0
    // 0x808005B4: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    func_800C37E0(rdram, ctx);
        goto after_10;
    // 0x808005B4: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    after_10:
    // 0x808005B8: lui         $a2, 0x4B45
    ctx->r6 = S32(0X4B45 << 16);
    // 0x808005BC: ori         $a2, $a2, 0xC100
    ctx->r6 = ctx->r6 | 0XC100;
    // 0x808005C0: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x808005C4: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x808005C8: jal         0x800C3A40
    // 0x808005CC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C3A40(rdram, ctx);
        goto after_11;
    // 0x808005CC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_11:
    // 0x808005D0: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x808005D4: jal         0x800C3418
    // 0x808005D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C3418(rdram, ctx);
        goto after_12;
    // 0x808005D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
    // 0x808005DC: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x808005E0: addiu       $a1, $zero, 0x1388
    ctx->r5 = ADD32(0, 0X1388);
    // 0x808005E4: addiu       $a2, $zero, 0x1770
    ctx->r6 = ADD32(0, 0X1770);
    // 0x808005E8: jal         0x800C316C
    // 0x808005EC: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    func_800C316C(rdram, ctx);
        goto after_13;
    // 0x808005EC: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    after_13:
    // 0x808005F0: jal         0x800C3BDC
    // 0x808005F4: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    func_800C3BDC(rdram, ctx);
        goto after_14;
    // 0x808005F4: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    after_14:
    // 0x808005F8: b           L_8080061C
    // 0x808005FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_8080061C;
    // 0x808005FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800600: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
L_80800604:
    // 0x80800604: beql        $a0, $zero, L_8080061C
    if (ctx->r4 == 0) {
        // 0x80800608: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8080061C;
    }
    goto skip_2;
    // 0x80800608: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_2:
    // 0x8080060C: jal         0x800C2FDC
    // 0x80800610: nop

    func_800C2FDC(rdram, ctx);
        goto after_15;
    // 0x80800610: nop

    after_15:
    // 0x80800614: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x80800618: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8080061C:
    // 0x8080061C: jal         0x800B2928
    // 0x80800620: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    vector_size(rdram, ctx);
        goto after_16;
    // 0x80800620: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    after_16:
    // 0x80800624: blezl       $v0, L_808006D0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800628: lbu         $t8, 0x1C($s1)
        ctx->r24 = MEM_BU(ctx->r17, 0X1C);
            goto L_808006D0;
    }
    goto skip_3;
    // 0x80800628: lbu         $t8, 0x1C($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X1C);
    skip_3:
    // 0x8080062C: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
L_80800630:
    // 0x80800630: jal         0x800B28CC
    // 0x80800634: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    vector_at(rdram, ctx);
        goto after_17;
    // 0x80800634: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_17:
    // 0x80800638: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8080063C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800640: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80800644: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80800648: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8080064C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80800650: mul.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80800654: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800658: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8080065C: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80800660: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80800664: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80800668: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8080066C: mul.s       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80800670: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800674: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800678: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8080067C: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    // 0x80800680: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800684: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80800688: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8080068C: nop

    // 0x80800690: bc1fl       L_808006B8
    if (!c1cs) {
        // 0x80800694: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808006B8;
    }
    goto skip_4;
    // 0x80800694: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_4:
    // 0x80800698: lbu         $t7, 0x18($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X18);
    // 0x8080069C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808006A0: bnel        $t7, $zero, L_808006B8
    if (ctx->r15 != 0) {
        // 0x808006A4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808006B8;
    }
    goto skip_5;
    // 0x808006A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_5:
    // 0x808006A8: jal         0x800B2E30
    // 0x808006AC: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    vector_erase(rdram, ctx);
        goto after_18;
    // 0x808006AC: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    after_18:
    // 0x808006B0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x808006B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808006B8:
    // 0x808006B8: jal         0x800B2928
    // 0x808006BC: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    vector_size(rdram, ctx);
        goto after_19;
    // 0x808006BC: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    after_19:
    // 0x808006C0: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808006C4: bnel        $at, $zero, L_80800630
    if (ctx->r1 != 0) {
        // 0x808006C8: lw          $a0, 0x20($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X20);
            goto L_80800630;
    }
    goto skip_6;
    // 0x808006C8: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    skip_6:
    // 0x808006CC: lbu         $t8, 0x1C($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X1C);
L_808006D0:
    // 0x808006D0: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x808006D4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x808006D8: jal         0x800B2928
    // 0x808006DC: sb          $t9, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r25;
    vector_size(rdram, ctx);
        goto after_20;
    // 0x808006DC: sb          $t9, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r25;
    after_20:
    // 0x808006E0: lbu         $a1, 0x1C($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1C);
    // 0x808006E4: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808006E8: beql        $at, $zero, L_80800738
    if (ctx->r1 == 0) {
        // 0x808006EC: sb          $zero, 0x1C($s1)
        MEM_B(0X1C, ctx->r17) = 0;
            goto L_80800738;
    }
    goto skip_7;
    // 0x808006EC: sb          $zero, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = 0;
    skip_7:
    // 0x808006F0: jal         0x800B28CC
    // 0x808006F4: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    vector_at(rdram, ctx);
        goto after_21;
    // 0x808006F4: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    after_21:
    // 0x808006F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006FC: jal         0x800EEB40
    // 0x80800700: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800EEB40(rdram, ctx);
        goto after_22;
    // 0x80800700: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_22:
    // 0x80800704: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2798, 0X8E0) << 16);
    // 0x80800708: lwc1        $f2, 0x8E0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2798, 0X8E0));
    // 0x8080070C: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80800710: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80800714: nop

    // 0x80800718: bc1fl       L_8080073C
    if (!c1cs) {
        // 0x8080071C: lbu         $v1, 0x30($s1)
        ctx->r3 = MEM_BU(ctx->r17, 0X30);
            goto L_8080073C;
    }
    goto skip_8;
    // 0x8080071C: lbu         $v1, 0x30($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X30);
    skip_8:
    // 0x80800720: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x80800724: jal         0x800B2E30
    // 0x80800728: lbu         $a1, 0x1C($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1C);
    vector_erase(rdram, ctx);
        goto after_23;
    // 0x80800728: lbu         $a1, 0x1C($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1C);
    after_23:
    // 0x8080072C: b           L_8080073C
    // 0x80800730: lbu         $v1, 0x30($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X30);
        goto L_8080073C;
    // 0x80800730: lbu         $v1, 0x30($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X30);
    // 0x80800734: sb          $zero, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = 0;
L_80800738:
    // 0x80800738: lbu         $v1, 0x30($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X30);
L_8080073C:
    // 0x8080073C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800740: beq         $v1, $zero, L_8080084C
    if (ctx->r3 == 0) {
        // 0x80800744: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8080084C;
    }
    // 0x80800744: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800748: lwc1        $f16, 0x34($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X34);
    // 0x8080074C: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x80800750: addu        $t1, $s1, $t0
    ctx->r9 = ADD32(ctx->r17, ctx->r8);
    // 0x80800754: add.s       $f4, $f16, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x80800758: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x8080075C: swc1        $f4, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f4.u32l;
    // 0x80800760: lwc1        $f6, 0x38($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X38);
    // 0x80800764: lwc1        $f10, 0x34($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X34);
    // 0x80800768: c.le.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl <= ctx->f10.fl;
    // 0x8080076C: nop

    // 0x80800770: bc1fl       L_808007A0
    if (!c1cs) {
        // 0x80800774: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808007A0;
    }
    goto skip_9;
    // 0x80800774: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_9:
    // 0x80800778: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080077C: andi        $v0, $t2, 0xFF
    ctx->r2 = ctx->r10 & 0XFF;
    // 0x80800780: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80800784: sb          $t2, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r10;
    // 0x80800788: bne         $at, $zero, L_8080079C
    if (ctx->r1 != 0) {
        // 0x8080078C: swc1        $f8, 0x34($s1)
        MEM_W(0X34, ctx->r17) = ctx->f8.u32l;
            goto L_8080079C;
    }
    // 0x8080078C: swc1        $f8, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f8.u32l;
    // 0x80800790: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800794: sb          $t3, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r11;
    // 0x80800798: andi        $v0, $t3, 0xFF
    ctx->r2 = ctx->r11 & 0XFF;
L_8080079C:
    // 0x8080079C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_808007A0:
    // 0x808007A0: bnel        $v0, $at, L_808007D8
    if (ctx->r2 != ctx->r1) {
        // 0x808007A4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808007D8;
    }
    goto skip_10;
    // 0x808007A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_10:
    // 0x808007A8: lwc1        $f18, 0x34($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X34);
    // 0x808007AC: lwc1        $f16, 0x3C($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x808007B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808007B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808007B8: div.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f16.fl);
    // 0x808007BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2798, 0X8E4) << 16);
    // 0x808007C0: lwc1        $f8, 0x8E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2798, 0X8E4));
    // 0x808007C4: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x808007C8: mul.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808007CC: b           L_80800824
    // 0x808007D0: swc1        $f18, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f18.u32l;
        goto L_80800824;
    // 0x808007D0: swc1        $f18, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f18.u32l;
    // 0x808007D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_808007D8:
    // 0x808007D8: bne         $v0, $at, L_808007EC
    if (ctx->r2 != ctx->r1) {
        // 0x808007DC: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2798, 0X8E8) << 16);
            goto L_808007EC;
    }
    // 0x808007DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2798, 0X8E8) << 16);
    // 0x808007E0: lwc1        $f16, 0x8E8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2798, 0X8E8));
    // 0x808007E4: b           L_80800824
    // 0x808007E8: swc1        $f16, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f16.u32l;
        goto L_80800824;
    // 0x808007E8: swc1        $f16, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f16.u32l;
L_808007EC:
    // 0x808007EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808007F0: bne         $v0, $at, L_80800818
    if (ctx->r2 != ctx->r1) {
        // 0x808007F4: nop
    
            goto L_80800818;
    }
    // 0x808007F4: nop

    // 0x808007F8: lwc1        $f10, 0x34($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X34);
    // 0x808007FC: lwc1        $f4, 0x44($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X44);
    // 0x80800800: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2798, 0X8EC) << 16);
    // 0x80800804: lwc1        $f8, 0x8EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2798, 0X8EC));
    // 0x80800808: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8080080C: mul.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800810: b           L_80800824
    // 0x80800814: swc1        $f18, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f18.u32l;
        goto L_80800824;
    // 0x80800814: swc1        $f18, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f18.u32l;
L_80800818:
    // 0x80800818: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2798, 0X8F0) << 16);
    // 0x8080081C: lwc1        $f16, 0x8F0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2798, 0X8F0));
    // 0x80800820: swc1        $f16, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f16.u32l;
L_80800824:
    // 0x80800824: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2798, 0X8F4) << 16);
    // 0x80800828: lwc1        $f10, 0x8F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2798, 0X8F4));
    // 0x8080082C: lwc1        $f4, 0x38($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80800830: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2798, 0X8F8) << 16);
    // 0x80800834: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x80800838: nop

    // 0x8080083C: bc1f        L_8080084C
    if (!c1cs) {
        // 0x80800840: nop
    
            goto L_8080084C;
    }
    // 0x80800840: nop

    // 0x80800844: lwc1        $f6, 0x8F8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2798, 0X8F8));
    // 0x80800848: swc1        $f6, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f6.u32l;
L_8080084C:
    // 0x8080084C: jal         0x800F1574
    // 0x80800850: addiu       $a0, $s1, 0x2C
    ctx->r4 = ADD32(ctx->r17, 0X2C);
    func_800F1574(rdram, ctx);
        goto after_24;
    // 0x80800850: addiu       $a0, $s1, 0x2C
    ctx->r4 = ADD32(ctx->r17, 0X2C);
    after_24:
    // 0x80800854: beql        $v0, $zero, L_808008BC
    if (ctx->r2 == 0) {
        // 0x80800858: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808008BC;
    }
    goto skip_11;
    // 0x80800858: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_11:
    // 0x8080085C: lw          $t4, 0x28($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X28);
    // 0x80800860: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800864: bnel        $t4, $at, L_80800898
    if (ctx->r12 != ctx->r1) {
        // 0x80800868: lbu         $t6, 0x30($s1)
        ctx->r14 = MEM_BU(ctx->r17, 0X30);
            goto L_80800898;
    }
    goto skip_12;
    // 0x80800868: lbu         $t6, 0x30($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X30);
    skip_12:
    // 0x8080086C: jal         0x800A5490
    // 0x80800870: nop

    func_800A5490(rdram, ctx);
        goto after_25;
    // 0x80800870: nop

    after_25:
    // 0x80800874: bnel        $v0, $zero, L_80800898
    if (ctx->r2 != 0) {
        // 0x80800878: lbu         $t6, 0x30($s1)
        ctx->r14 = MEM_BU(ctx->r17, 0X30);
            goto L_80800898;
    }
    goto skip_13;
    // 0x80800878: lbu         $t6, 0x30($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X30);
    skip_13:
    // 0x8080087C: lbu         $t5, 0x30($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X30);
    // 0x80800880: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800884: beql        $t5, $at, L_80800898
    if (ctx->r13 == ctx->r1) {
        // 0x80800888: lbu         $t6, 0x30($s1)
        ctx->r14 = MEM_BU(ctx->r17, 0X30);
            goto L_80800898;
    }
    goto skip_14;
    // 0x80800888: lbu         $t6, 0x30($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X30);
    skip_14:
    // 0x8080088C: jal         0x80800000
    // 0x80800890: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800000_fxrain(rdram, ctx);
        goto after_26;
    // 0x80800890: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_26:
    // 0x80800894: lbu         $t6, 0x30($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X30);
L_80800898:
    // 0x80800898: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2798, 0X8FC) << 16);
    // 0x8080089C: beq         $t6, $zero, L_808008B0
    if (ctx->r14 == 0) {
        // 0x808008A0: nop
    
            goto L_808008B0;
    }
    // 0x808008A0: nop

    // 0x808008A4: lwc1        $f8, 0x38($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X38);
    // 0x808008A8: b           L_808008B8
    // 0x808008AC: swc1        $f8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f8.u32l;
        goto L_808008B8;
    // 0x808008AC: swc1        $f8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f8.u32l;
L_808008B0:
    // 0x808008B0: lwc1        $f18, 0x8FC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2798, 0X8FC));
    // 0x808008B4: swc1        $f18, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f18.u32l;
L_808008B8:
    // 0x808008B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008BC:
    // 0x808008BC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808008C0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808008C4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808008C8: jr          $ra
    // 0x808008CC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x808008CC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8010A590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A590: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010A594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010A598: jal         0x8010A5B0
    // 0x8010A59C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010A5B0(rdram, ctx);
        goto after_0;
    // 0x8010A59C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8010A5A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010A5A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010A5A8: jr          $ra
    // 0x8010A5AC: nop

    return;
    // 0x8010A5AC: nop

;}
RECOMP_FUNC void func_80802888_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802888: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8080288C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802890: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80802894: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80802898: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080289C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808028A0: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808028A4: beq         $t6, $at, L_808028C4
    if (ctx->r14 == ctx->r1) {
        // 0x808028A8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808028C4;
    }
    // 0x808028A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808028AC: beq         $t6, $at, L_8080293C
    if (ctx->r14 == ctx->r1) {
        // 0x808028B0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080293C;
    }
    // 0x808028B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808028B4: beql        $t6, $at, L_80802A20
    if (ctx->r14 == ctx->r1) {
        // 0x808028B8: lui         $at, 0x43C8
        ctx->r1 = S32(0X43C8 << 16);
            goto L_80802A20;
    }
    goto skip_0;
    // 0x808028B8: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    skip_0:
    // 0x808028BC: b           L_80802A6C
    // 0x808028C0: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
        goto L_80802A6C;
    // 0x808028C0: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
L_808028C4:
    // 0x808028C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1332, 0X2D8C) << 16);
    // 0x808028C8: lwc1        $f2, 0x2D8C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2D8C));
    // 0x808028CC: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808028D0: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x808028D4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1332, 0X3098) << 16);
    // 0x808028D8: mul.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x808028DC: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x808028E0: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x808028E4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x808028E8: addiu       $a1, $a1, 0x3098
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1332, 0X3098));
    // 0x808028EC: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x808028F0: jal         0x800F2F60
    // 0x808028F4: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    func_800F2F60(rdram, ctx);
        goto after_0;
    // 0x808028F4: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x808028F8: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x808028FC: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80802900: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802904: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80802908: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080290C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80802910: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    // 0x80802914: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80802918: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080291C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80802920: jal         0x800C8E54
    // 0x80802924: nop

    func_800C8E54(rdram, ctx);
        goto after_1;
    // 0x80802924: nop

    after_1:
    // 0x80802928: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    // 0x8080292C: jal         0x800C8E84
    // 0x80802930: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800C8E84(rdram, ctx);
        goto after_2;
    // 0x80802930: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_2:
    // 0x80802934: b           L_80802A6C
    // 0x80802938: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
        goto L_80802A6C;
    // 0x80802938: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
L_8080293C:
    // 0x8080293C: jal         0x800D9078
    // 0x80802940: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_3;
    // 0x80802940: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_3:
    // 0x80802944: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1332, 0X2D90) << 16);
    // 0x80802948: lwc1        $f2, 0x2D90($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2D90));
    // 0x8080294C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80802950: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80802954: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80802958: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x8080295C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80802960: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80802964: jal         0x800F12D4
    // 0x80802968: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_800F12D4(rdram, ctx);
        goto after_4;
    // 0x80802968: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x8080296C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80802970: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80802974: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80802978: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1332, 0X3098) << 16);
    // 0x8080297C: mul.s       $f2, $f18, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80802980: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80802984: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80802988: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080298C: addiu       $a1, $a1, 0x3098
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1332, 0X3098));
    // 0x80802990: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80802994: jal         0x800F2F60
    // 0x80802998: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    func_800F2F60(rdram, ctx);
        goto after_5;
    // 0x80802998: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x8080299C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x808029A0: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808029A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808029A8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x808029AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808029B0: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x808029B4: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    // 0x808029B8: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x808029BC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808029C0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808029C4: jal         0x800C8E54
    // 0x808029C8: nop

    func_800C8E54(rdram, ctx);
        goto after_6;
    // 0x808029C8: nop

    after_6:
    // 0x808029CC: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    // 0x808029D0: jal         0x800C8E84
    // 0x808029D4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800C8E84(rdram, ctx);
        goto after_7;
    // 0x808029D4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_7:
    // 0x808029D8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x808029DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808029E0: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808029E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808029E8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808029EC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808029F0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808029F4: jal         0x80089C98
    // 0x808029F8: nop

    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x808029F8: nop

    after_8:
    // 0x808029FC: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80802A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802A04: beql        $t3, $zero, L_80802A6C
    if (ctx->r11 == 0) {
        // 0x80802A08: lw          $a0, 0x54($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X54);
            goto L_80802A6C;
    }
    goto skip_1;
    // 0x80802A08: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    skip_1:
    // 0x80802A0C: jal         0x80101FDC
    // 0x80802A10: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_9;
    // 0x80802A10: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x80802A14: b           L_80802A6C
    // 0x80802A18: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
        goto L_80802A6C;
    // 0x80802A18: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    // 0x80802A1C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
L_80802A20:
    // 0x80802A20: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80802A24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802A28: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80802A2C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80802A30: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80802A34: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
    // 0x80802A38: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    // 0x80802A3C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80802A40: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80802A44: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
    // 0x80802A48: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80802A4C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80802A50: jal         0x800C8E54
    // 0x80802A54: nop

    func_800C8E54(rdram, ctx);
        goto after_10;
    // 0x80802A54: nop

    after_10:
    // 0x80802A58: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1332, 0X3098) << 16);
    // 0x80802A5C: addiu       $a1, $a1, 0x3098
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1332, 0X3098));
    // 0x80802A60: jal         0x800C8E84
    // 0x80802A64: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    func_800C8E84(rdram, ctx);
        goto after_11;
    // 0x80802A64: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    after_11:
    // 0x80802A68: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
L_80802A6C:
    // 0x80802A6C: beql        $a0, $zero, L_80802A80
    if (ctx->r4 == 0) {
        // 0x80802A70: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80802A80;
    }
    goto skip_2;
    // 0x80802A70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80802A74: jal         0x800C8CB8
    // 0x80802A78: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C8CB8(rdram, ctx);
        goto after_12;
    // 0x80802A78: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_12:
    // 0x80802A7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802A80:
    // 0x80802A80: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80802A84: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80802A88: jr          $ra
    // 0x80802A8C: nop

    return;
    // 0x80802A8C: nop

;}
RECOMP_FUNC void chjiggygamenew_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802E74: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(772, 0X3E50) << 16);
    // 0x80802E78: jr          $ra
    // 0x80802E7C: addiu       $v0, $v0, 0x3E50
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(772, 0X3E50));
    return;
    // 0x80802E7C: addiu       $v0, $v0, 0x3E50
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(772, 0X3E50));
;}
RECOMP_FUNC void func_80020DEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020DEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80020DF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020DF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80020DF8: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80020DFC: lw          $t6, 0x11F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11F0);
    // 0x80020E00: beq         $t6, $zero, L_80020E20
    if (ctx->r14 == 0) {
        // 0x80020E04: nop
    
            goto L_80020E20;
    }
    // 0x80020E04: nop

    // 0x80020E08: jal         0x80027200
    // 0x80020E0C: nop

    func_80027200(rdram, ctx);
        goto after_0;
    // 0x80020E0C: nop

    after_0:
    // 0x80020E10: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80020E14: sw          $zero, 0x11F0($at)
    MEM_W(0X11F0, ctx->r1) = 0;
    // 0x80020E18: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80020E1C: sw          $zero, 0x11F4($at)
    MEM_W(0X11F4, ctx->r1) = 0;
L_80020E20:
    // 0x80020E20: b           L_80020E28
    // 0x80020E24: nop

        goto L_80020E28;
    // 0x80020E24: nop

L_80020E28:
    // 0x80020E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020E2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80020E30: jr          $ra
    // 0x80020E34: nop

    return;
    // 0x80020E34: nop

    // 0x80020E38: nop

    // 0x80020E3C: nop

;}
RECOMP_FUNC void func_800FA818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA818: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800FA81C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800FA820: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800FA824: addiu       $t7, $t7, 0x3880
    ctx->r15 = ADD32(ctx->r15, 0X3880);
    // 0x800FA828: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800FA82C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800FA830: lw          $t8, 0x18($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X18);
    // 0x800FA834: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FA838: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FA83C: beq         $t8, $zero, L_800FA850
    if (ctx->r24 == 0) {
        // 0x800FA840: nop
    
            goto L_800FA850;
    }
    // 0x800FA840: nop

    // 0x800FA844: lb          $t9, 0xE($v0)
    ctx->r25 = MEM_B(ctx->r2, 0XE);
    // 0x800FA848: beq         $a1, $t9, L_800FA858
    if (ctx->r5 == ctx->r25) {
        // 0x800FA84C: nop
    
            goto L_800FA858;
    }
    // 0x800FA84C: nop

L_800FA850:
    // 0x800FA850: b           L_800FA864
    // 0x800FA854: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FA864;
    // 0x800FA854: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FA858:
    // 0x800FA858: jal         0x800FA240
    // 0x800FA85C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800FA240(rdram, ctx);
        goto after_0;
    // 0x800FA85C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800FA860: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800FA864:
    // 0x800FA864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FA868: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FA86C: jr          $ra
    // 0x800FA870: nop

    return;
    // 0x800FA870: nop

;}
RECOMP_FUNC void ncpoddialog_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802840: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802844: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802848: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080284C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80802850: lb          $v1, 0x211($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X211);
    // 0x80802854: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80802858: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080285C: bne         $v1, $at, L_8080287C
    if (ctx->r3 != ctx->r1) {
        // 0x80802860: nop
    
            goto L_8080287C;
    }
    // 0x80802860: nop

    // 0x80802864: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80802868: jal         0x80801310
    // 0x8080286C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_80801310_ncpoddialog(rdram, ctx);
        goto after_0;
    // 0x8080286C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x80802870: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80802874: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80802878: lb          $v1, 0x211($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X211);
L_8080287C:
    // 0x8080287C: bne         $a2, $v1, L_8080288C
    if (ctx->r6 != ctx->r3) {
        // 0x80802880: addiu       $a0, $zero, 0x64
        ctx->r4 = ADD32(0, 0X64);
            goto L_8080288C;
    }
    // 0x80802880: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x80802884: lbu         $t6, 0x216($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X216);
    // 0x80802888: beq         $t6, $zero, L_8080290C
    if (ctx->r14 == 0) {
        // 0x8080288C: sll         $t7, $a3, 16
        ctx->r15 = S32(ctx->r7 << 16);
            goto L_8080290C;
    }
L_8080288C:
    // 0x8080288C: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x80802890: sb          $zero, 0x216($s0)
    MEM_B(0X216, ctx->r16) = 0;
    // 0x80802894: sb          $a2, 0x211($s0)
    MEM_B(0X211, ctx->r16) = ctx->r6;
    // 0x80802898: sb          $a3, 0x213($s0)
    MEM_B(0X213, ctx->r16) = ctx->r7;
    // 0x8080289C: jal         0x8009055C
    // 0x808028A0: or          $a1, $t7, $a2
    ctx->r5 = ctx->r15 | ctx->r6;
    func_8009055C(rdram, ctx);
        goto after_1;
    // 0x808028A0: or          $a1, $t7, $a2
    ctx->r5 = ctx->r15 | ctx->r6;
    after_1:
    // 0x808028A4: lb          $v1, 0x211($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X211);
    // 0x808028A8: bnel        $v1, $zero, L_808028C0
    if (ctx->r3 != 0) {
        // 0x808028AC: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_808028C0;
    }
    goto skip_0;
    // 0x808028AC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    skip_0:
    // 0x808028B0: lbu         $t8, 0x213($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X213);
    // 0x808028B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808028B8: beq         $t8, $at, L_808028C8
    if (ctx->r24 == ctx->r1) {
        // 0x808028BC: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_808028C8;
    }
    // 0x808028BC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
L_808028C0:
    // 0x808028C0: bne         $v1, $at, L_80802908
    if (ctx->r3 != ctx->r1) {
        // 0x808028C4: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80802908;
    }
    // 0x808028C4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_808028C8:
    // 0x808028C8: jal         0x80110024
    // 0x808028CC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80110024(rdram, ctx);
        goto after_2;
    // 0x808028CC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x808028D0: lb          $a3, 0x211($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X211);
    // 0x808028D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808028D8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808028DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808028E0: jal         0x800894E8
    // 0x808028E4: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    _ncpod_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x808028E4: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    after_3:
    // 0x808028E8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808028EC: beq         $v0, $at, L_8080290C
    if (ctx->r2 == ctx->r1) {
        // 0x808028F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080290C;
    }
    // 0x808028F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808028F4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808028F8: jal         0x80800338
    // 0x808028FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800338_ncpoddialog(rdram, ctx);
        goto after_4;
    // 0x808028FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80802900: b           L_80802910
    // 0x80802904: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80802910;
    // 0x80802904: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802908:
    // 0x80802908: sb          $t9, 0x212($s0)
    MEM_B(0X212, ctx->r16) = ctx->r25;
L_8080290C:
    // 0x8080290C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802910:
    // 0x80802910: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80802914: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802918: jr          $ra
    // 0x8080291C: nop

    return;
    // 0x8080291C: nop

;}
RECOMP_FUNC void _chswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800857D0: syscall     176
    recomp_syscall_handler(rdram, ctx, 0x800857D0);
    return;
    // 0x800857D4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080016C_bsride(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080016C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800170: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800174: jal         0x8080008C
    // 0x80800178: nop

    func_8080008C_bsride(rdram, ctx);
        goto after_0;
    // 0x80800178: nop

    after_0:
    // 0x8080017C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800180: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800184: jr          $ra
    // 0x80800188: nop

    return;
    // 0x80800188: nop

;}
