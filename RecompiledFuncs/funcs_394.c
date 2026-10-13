#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808009F0_chfriesstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808009F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808009F8: addiu       $at, $zero, 0x10E0
    ctx->r1 = ADD32(0, 0X10E0);
    // 0x808009FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A04: beq         $a1, $at, L_80800A28
    if (ctx->r5 == ctx->r1) {
        // 0x80800A08: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800A28;
    }
    // 0x80800A08: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800A0C: addiu       $at, $zero, 0x10FD
    ctx->r1 = ADD32(0, 0X10FD);
    // 0x80800A10: beq         $a1, $at, L_80800A50
    if (ctx->r5 == ctx->r1) {
        // 0x80800A14: addiu       $at, $zero, 0x110B
        ctx->r1 = ADD32(0, 0X110B);
            goto L_80800A50;
    }
    // 0x80800A14: addiu       $at, $zero, 0x110B
    ctx->r1 = ADD32(0, 0X110B);
    // 0x80800A18: beq         $a1, $at, L_80800A50
    if (ctx->r5 == ctx->r1) {
        // 0x80800A1C: nop
    
            goto L_80800A50;
    }
    // 0x80800A1C: nop

    // 0x80800A20: b           L_80800A6C
    // 0x80800A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800A6C;
    // 0x80800A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800A28:
    // 0x80800A28: jal         0x80085710
    // 0x80800A2C: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800A2C: nop

    after_0:
    // 0x80800A30: lhu         $t6, 0x6E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A3C: andi        $t7, $t6, 0xFE00
    ctx->r15 = ctx->r14 & 0XFE00;
    // 0x80800A40: jal         0x80102424
    // 0x80800A44: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800A44: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
    after_1:
    // 0x80800A48: b           L_80800ADC
    // 0x80800A4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800ADC;
    // 0x80800A4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A50:
    // 0x80800A50: jal         0x8008FC9C
    // 0x80800A54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8008FC9C(rdram, ctx);
        goto after_2;
    // 0x80800A54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80800A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A5C: jal         0x80102424
    // 0x80800A60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x80800A60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800A64: b           L_80800ADC
    // 0x80800A68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800ADC;
    // 0x80800A68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A6C:
    // 0x80800A6C: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x80800A70: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(940, 0XE50) << 16);
    // 0x80800A74: addiu       $a2, $a2, 0xE50
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(940, 0XE50));
    // 0x80800A78: beql        $t8, $zero, L_80800ABC
    if (ctx->r24 == 0) {
        // 0x80800A7C: lhu         $t9, 0x6E($s0)
        ctx->r25 = MEM_HU(ctx->r16, 0X6E);
            goto L_80800ABC;
    }
    goto skip_0;
    // 0x80800A7C: lhu         $t9, 0x6E($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6E);
    skip_0:
    // 0x80800A80: jal         0x8008A1F8
    // 0x80800A84: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x80800A84: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_4:
    // 0x80800A88: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A8C: bne         $v0, $at, L_80800AB8
    if (ctx->r2 != ctx->r1) {
        // 0x80800A90: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AB8;
    }
    // 0x80800A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A94: jal         0x80102424
    // 0x80800A98: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x80800A98: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x80800A9C: jal         0x80106790
    // 0x80800AA0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_6;
    // 0x80800AA0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_6:
    // 0x80800AA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800AA8: jal         0x80102424
    // 0x80800AAC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x80800AAC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x80800AB0: b           L_80800ADC
    // 0x80800AB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800ADC;
    // 0x80800AB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800AB8:
    // 0x80800AB8: lhu         $t9, 0x6E($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6E);
L_80800ABC:
    // 0x80800ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800AC4: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x80800AC8: jal         0x80102424
    // 0x80800ACC: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x80800ACC: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
    after_8:
    // 0x80800AD0: jal         0x80090708
    // 0x80800AD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_9;
    // 0x80800AD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x80800AD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800ADC:
    // 0x80800ADC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800AE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800AE4: jr          $ra
    // 0x80800AE8: nop

    return;
    // 0x80800AE8: nop

;}
RECOMP_FUNC void func_800BA5BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA5BC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800BA5C0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800BA5C4: swc1        $f12, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f12.u32l;
    // 0x800BA5C8: jr          $ra
    // 0x800BA5CC: swc1        $f14, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->f14.u32l;
    return;
    // 0x800BA5CC: swc1        $f14, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_800F5A00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5A00: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5A04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5A08: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5A0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5A10: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5A14: jal         0x800F3BB0
    // 0x800F5A18: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800F3BB0(rdram, ctx);
        goto after_0;
    // 0x800F5A18: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5A1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5A20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5A24: jr          $ra
    // 0x800F5A28: nop

    return;
    // 0x800F5A28: nop

;}
RECOMP_FUNC void func_800E6F7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E6F7C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800E6F80: addiu       $t8, $zero, 0x30
    ctx->r24 = ADD32(0, 0X30);
    // 0x800E6F84: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x800E6F88: beq         $t6, $zero, L_800E6FA0
    if (ctx->r14 == 0) {
        // 0x800E6F8C: addiu       $v1, $zero, 0x1C
        ctx->r3 = ADD32(0, 0X1C);
            goto L_800E6FA0;
    }
    // 0x800E6F8C: addiu       $v1, $zero, 0x1C
    ctx->r3 = ADD32(0, 0X1C);
    // 0x800E6F90: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
L_800E6F94:
    // 0x800E6F94: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800E6F98: bnel        $t7, $zero, L_800E6F94
    if (ctx->r15 != 0) {
        // 0x800E6F9C: lbu         $t7, 0x1($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X1);
            goto L_800E6F94;
    }
    goto skip_0;
    // 0x800E6F9C: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
    skip_0:
L_800E6FA0:
    // 0x800E6FA0: sb          $t8, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r24;
    // 0x800E6FA4: sb          $t9, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r25;
    // 0x800E6FA8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
L_800E6FAC:
    // 0x800E6FAC: srlv        $v0, $a1, $v1
    ctx->r2 = S32(U32(ctx->r5) >> (ctx->r3 & 31));
    // 0x800E6FB0: andi        $t0, $v0, 0xF
    ctx->r8 = ctx->r2 & 0XF;
    // 0x800E6FB4: slti        $t1, $t0, 0xA
    ctx->r9 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x800E6FB8: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x800E6FBC: beq         $t2, $zero, L_800E6FD0
    if (ctx->r10 == 0) {
        // 0x800E6FC0: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_800E6FD0;
    }
    // 0x800E6FC0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800E6FC4: addiu       $t3, $t0, 0x30
    ctx->r11 = ADD32(ctx->r8, 0X30);
    // 0x800E6FC8: b           L_800E6FD8
    // 0x800E6FCC: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
        goto L_800E6FD8;
    // 0x800E6FCC: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
L_800E6FD0:
    // 0x800E6FD0: addiu       $t4, $v0, 0x57
    ctx->r12 = ADD32(ctx->r2, 0X57);
    // 0x800E6FD4: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
L_800E6FD8:
    // 0x800E6FD8: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800E6FDC: bgez        $v1, L_800E6FAC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800E6FE0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800E6FAC;
    }
    // 0x800E6FE0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800E6FE4: jr          $ra
    // 0x800E6FE8: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    return;
    // 0x800E6FE8: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
;}
RECOMP_FUNC void _bskazstill_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083658: syscall     70
    recomp_syscall_handler(rdram, ctx, 0x80083658);
    return;
    // 0x8008365C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void baduo_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808008DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808008E0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808008E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808008EC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808008F0: jal         0x800F6224
    // 0x808008F4: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    func_800F6224(rdram, ctx);
        goto after_0;
    // 0x808008F4: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    after_0:
    // 0x808008F8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808008FC: jal         0x800F53D0
    // 0x80800900: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F53D0(rdram, ctx);
        goto after_1;
    // 0x80800900: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800904: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800908: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080090C: jal         0x800F452C
    // 0x80800910: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800F452C(rdram, ctx);
        goto after_2;
    // 0x80800910: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80800914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800918: jal         0x800A3410
    // 0x8080091C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_800A3410(rdram, ctx);
        goto after_3;
    // 0x8080091C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_3:
    // 0x80800920: jal         0x80092778
    // 0x80800924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092778(rdram, ctx);
        goto after_4;
    // 0x80800924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080092C: jal         0x8009E5C8
    // 0x80800930: addiu       $a1, $zero, 0xE5
    ctx->r5 = ADD32(0, 0XE5);
    bs_setState(rdram, ctx);
        goto after_5;
    // 0x80800930: addiu       $a1, $zero, 0xE5
    ctx->r5 = ADD32(0, 0XE5);
    after_5:
    // 0x80800934: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800938: jal         0x80800008
    // 0x8080093C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800008_baduo(rdram, ctx);
        goto after_6;
    // 0x8080093C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80800940: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800944: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800948: jal         0x800A38F0
    // 0x8080094C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A38F0(rdram, ctx);
        goto after_7;
    // 0x8080094C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80800950: jal         0x800F8128
    // 0x80800954: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800F8128(rdram, ctx);
        goto after_8;
    // 0x80800954: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x80800958: jal         0x800F8EE4
    // 0x8080095C: lw          $a0, 0x184($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X184);
    func_800F8EE4(rdram, ctx);
        goto after_9;
    // 0x8080095C: lw          $a0, 0x184($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X184);
    after_9:
    // 0x80800960: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800964: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800968: jal         0x800F45B0
    // 0x8080096C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_800F45B0(rdram, ctx);
        goto after_10;
    // 0x8080096C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_10:
    // 0x80800970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800974: jal         0x8009C914
    // 0x80800978: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    yaw_setIdeal(rdram, ctx);
        goto after_11;
    // 0x80800978: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_11:
    // 0x8080097C: jal         0x8009C974
    // 0x80800980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_12;
    // 0x80800980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800988: jal         0x80800C78
    // 0x8080098C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_80800C78_baduo(rdram, ctx);
        goto after_13;
    // 0x8080098C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_13:
    // 0x80800990: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800994: jal         0x80800CA8
    // 0x80800998: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800CA8_baduo(rdram, ctx);
        goto after_14;
    // 0x80800998: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_14:
    // 0x8080099C: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x808009A0: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808009A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808009A8: addiu       $a1, $zero, 0x5A2
    ctx->r5 = ADD32(0, 0X5A2);
    // 0x808009AC: jal         0x8009DB04
    // 0x808009B0: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    func_8009DB04(rdram, ctx);
        goto after_15;
    // 0x808009B0: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    after_15:
    // 0x808009B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808009B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808009BC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808009C0: jr          $ra
    // 0x808009C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808009C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _susplinet_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E38: syscall     812
    recomp_syscall_handler(rdram, ctx, 0x80089E38);
    return;
    // 0x80089E3C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void glglobalsettings_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800304: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080030C: jal         0x800DA298
    // 0x80800310: addiu       $a0, $zero, 0xD54
    ctx->r4 = ADD32(0, 0XD54);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800310: addiu       $a0, $zero, 0xD54
    ctx->r4 = ADD32(0, 0XD54);
    after_0:
    // 0x80800314: bne         $v0, $zero, L_80800324
    if (ctx->r2 != 0) {
        // 0x80800318: nop
    
            goto L_80800324;
    }
    // 0x80800318: nop

    // 0x8080031C: b           L_80800398
    // 0x80800320: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800398;
    // 0x80800320: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800324:
    // 0x80800324: jal         0x80800084
    // 0x80800328: nop

    func_80800084_glglobalsettings(rdram, ctx);
        goto after_1;
    // 0x80800328: nop

    after_1:
    // 0x8080032C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800330: jal         0x80800168
    // 0x80800334: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80800168_glglobalsettings(rdram, ctx);
        goto after_2;
    // 0x80800334: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x80800338: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080033C: jal         0x800885C0
    // 0x80800340: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    _glglobaldata_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800340: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_3:
    // 0x80800344: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80800348: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080034C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800350:
    // 0x80800350: bnel        $a0, $v1, L_80800368
    if (ctx->r4 != ctx->r3) {
        // 0x80800354: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_80800368;
    }
    goto skip_0;
    // 0x80800354: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80800358: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8080035C: bne         $a0, $v0, L_80800350
    if (ctx->r4 != ctx->r2) {
        // 0x80800360: nop
    
            goto L_80800350;
    }
    // 0x80800360: nop

    // 0x80800364: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
L_80800368:
    // 0x80800368: jal         0x80800278
    // 0x8080036C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80800278_glglobalsettings(rdram, ctx);
        goto after_4;
    // 0x8080036C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_4:
    // 0x80800370: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800374: bne         $v0, $zero, L_8080038C
    if (ctx->r2 != 0) {
        // 0x80800378: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_8080038C;
    }
    // 0x80800378: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080037C: jal         0x80800114
    // 0x80800380: nop

    func_80800114_glglobalsettings(rdram, ctx);
        goto after_5;
    // 0x80800380: nop

    after_5:
    // 0x80800384: jal         0x800DA524
    // 0x80800388: addiu       $a0, $zero, 0xD54
    ctx->r4 = ADD32(0, 0XD54);
    func_800DA524(rdram, ctx);
        goto after_6;
    // 0x80800388: addiu       $a0, $zero, 0xD54
    ctx->r4 = ADD32(0, 0XD54);
    after_6:
L_8080038C:
    // 0x8080038C: jal         0x8001B084
    // 0x80800390: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    heap_free(rdram, ctx);
        goto after_7;
    // 0x80800390: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_7:
    // 0x80800394: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_80800398:
    // 0x80800398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080039C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003A0: jr          $ra
    // 0x808003A4: nop

    return;
    // 0x808003A4: nop

;}
RECOMP_FUNC void func_800C9F48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9F48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C9F4C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C9F50: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9F54: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C9F58: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800C9F5C: lhu         $t7, 0x12($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X12);
    // 0x800C9F60: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800C9F64: addiu       $a2, $a2, -0x64D0
    ctx->r6 = ADD32(ctx->r6, -0X64D0);
    // 0x800C9F68: srl         $t8, $t7, 1
    ctx->r24 = S32(U32(ctx->r15) >> 1);
    // 0x800C9F6C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800C9F70: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800C9F74: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800C9F78: sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    // 0x800C9F7C: jal         0x800C9750
    // 0x800C9F80: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C9750(rdram, ctx);
        goto after_0;
    // 0x800C9F80: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x800C9F84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C9F88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C9F8C: jr          $ra
    // 0x800C9F90: nop

    return;
    // 0x800C9F90: nop

;}
RECOMP_FUNC void chfactoryposter_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1472, 0X110) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x110
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1472, 0X110));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x110
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1472, 0X110));
;}
RECOMP_FUNC void _bsstonehead_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C98: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083C98);
    return;
    // 0x80083C9C: addi        $t0, $zero, 0x5C
    ctx->r8 = ADD32(0, 0X5C);
;}
RECOMP_FUNC void func_80800288_fxleaves(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800288: jr          $ra
    // 0x8080028C: sb          $a1, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r5;
    return;
    // 0x8080028C: sb          $a1, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_8008FCF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FCF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FCF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FCFC: jal         0x800F54E4
    // 0x8008FD00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FD00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008FD04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FD08: jal         0x800F52E4
    // 0x8008FD0C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F52E4(rdram, ctx);
        goto after_1;
    // 0x8008FD0C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008FD10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FD14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FD18: jr          $ra
    // 0x8008FD1C: nop

    return;
    // 0x8008FD1C: nop

;}
RECOMP_FUNC void func_8080012C_bssplitup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080012C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800130: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800134: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800138: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080013C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800140: beq         $a1, $at, L_80800168
    if (ctx->r5 == ctx->r1) {
        // 0x80800144: sw          $a1, 0x15C($a0)
        MEM_W(0X15C, ctx->r4) = ctx->r5;
            goto L_80800168;
    }
    // 0x80800144: sw          $a1, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r5;
    // 0x80800148: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080014C: beq         $a1, $at, L_808001CC
    if (ctx->r5 == ctx->r1) {
        // 0x80800150: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001CC;
    }
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800154: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800158: beq         $a1, $at, L_80800270
    if (ctx->r5 == ctx->r1) {
        // 0x8080015C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800270;
    }
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800160: b           L_8080027C
    // 0x80800164: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080027C;
    // 0x80800164: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800168:
    // 0x80800168: lui         $a2, 0x400C
    ctx->r6 = S32(0X400C << 16);
    // 0x8080016C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800174: jal         0x8008CCBC
    // 0x80800178: addiu       $a1, $zero, 0xA3
    ctx->r5 = ADD32(0, 0XA3);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_0;
    // 0x80800178: addiu       $a1, $zero, 0xA3
    ctx->r5 = ADD32(0, 0XA3);
    after_0:
    // 0x8080017C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800180: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080018C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800190: jal         0x8009FFD8
    // 0x80800194: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800194: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080019C: jal         0x8009B94C
    // 0x808001A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009B94C(rdram, ctx);
        goto after_2;
    // 0x808001A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A8: jal         0x8009BA9C
    // 0x808001AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_3;
    // 0x808001AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B4: addiu       $a1, $zero, 0x4592
    ctx->r5 = ADD32(0, 0X4592);
    // 0x808001B8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808001BC: jal         0x8009DF18
    // 0x808001C0: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    func_8009DF18(rdram, ctx);
        goto after_4;
    // 0x808001C0: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    after_4:
    // 0x808001C4: b           L_8080027C
    // 0x808001C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080027C;
    // 0x808001C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001CC:
    // 0x808001CC: jal         0x8009C128
    // 0x808001D0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_8009C128(rdram, ctx);
        goto after_5;
    // 0x808001D0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_5:
    // 0x808001D4: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x808001D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001DC: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x808001E0: addiu       $t7, $t7, -0x14C0
    ctx->r15 = ADD32(ctx->r15, -0X14C0);
    // 0x808001E4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808001E8: addiu       $a0, $zero, 0x156
    ctx->r4 = ADD32(0, 0X156);
    // 0x808001EC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808001F0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x808001F4: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x808001F8: jal         0x80089C48
    // 0x808001FC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _subaddiefind_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x808001FC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80800200: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800204: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800208: jal         0x800EE7F8
    // 0x8080020C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x8080020C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_7:
    // 0x80800210: jal         0x80084DB8
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovegoto_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: jal         0x80084E18
    // 0x80800220: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    _bamovegoto_entrypoint_12(rdram, ctx);
        goto after_9;
    // 0x80800220: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_9:
    // 0x80800224: jal         0x8008CAC8
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_10;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080022C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(364, 0X6F0) << 16);
    // 0x80800230: lwc1        $f6, 0x6F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(364, 0X6F0));
    // 0x80800234: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(364, 0X6F4) << 16);
    // 0x80800238: lwc1        $f10, 0x6F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(364, 0X6F4));
    // 0x8080023C: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800244: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800248: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8080024C: jal         0x80084DF0
    // 0x80800250: nop

    _bamovegoto_entrypoint_7(rdram, ctx);
        goto after_11;
    // 0x80800250: nop

    after_11:
    // 0x80800254: jal         0x80084E20
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovegoto_entrypoint_13(rdram, ctx);
        goto after_12;
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080025C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80800260: jal         0x800F9098
    // 0x80800264: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800F9098(rdram, ctx);
        goto after_13;
    // 0x80800264: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_13:
    // 0x80800268: b           L_8080027C
    // 0x8080026C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080027C;
    // 0x8080026C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800270:
    // 0x80800270: jal         0x8009B800
    // 0x80800274: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    baphysics_set_type(rdram, ctx);
        goto after_14;
    // 0x80800274: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
    // 0x80800278: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080027C:
    // 0x8080027C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800280: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800284: jr          $ra
    // 0x80800288: nop

    return;
    // 0x80800288: nop

;}
RECOMP_FUNC void func_808011B4_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808011B8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808011BC: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x808011C0: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x808011C4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808011C8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808011CC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808011D0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808011D4: beq         $a1, $at, L_808011F0
    if (ctx->r5 == ctx->r1) {
        // 0x808011D8: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_808011F0;
    }
    // 0x808011D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808011DC: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x808011E0: beql        $a1, $at, L_80801260
    if (ctx->r5 == ctx->r1) {
        // 0x808011E4: lw          $t1, 0x74($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X74);
            goto L_80801260;
    }
    goto skip_0;
    // 0x808011E4: lw          $t1, 0x74($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X74);
    skip_0:
    // 0x808011E8: b           L_808012C4
    // 0x808011EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808012C4;
    // 0x808011EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808011F0:
    // 0x808011F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808011F4: jal         0x80100094
    // 0x808011F8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808011F8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x808011FC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801200: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801204: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80801208: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
    // 0x8080120C: addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
L_80801210:
    // 0x80801210: lbu         $t6, 0xC0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0XC0);
    // 0x80801214: beql        $t6, $zero, L_8080123C
    if (ctx->r14 == 0) {
        // 0x80801218: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8080123C;
    }
    goto skip_1;
    // 0x80801218: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x8080121C: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80801220: addiu       $a0, $s1, 0xC8
    ctx->r4 = ADD32(ctx->r17, 0XC8);
    // 0x80801224: lw          $a1, 0xD4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XD4);
    // 0x80801228: mflo        $t7
    ctx->r15 = lo;
    // 0x8080122C: addu        $a3, $s1, $t7
    ctx->r7 = ADD32(ctx->r17, ctx->r15);
    // 0x80801230: jal         0x8080145C
    // 0x80801234: addiu       $a2, $a3, 0x60
    ctx->r6 = ADD32(ctx->r7, 0X60);
    func_8080145C_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80801234: addiu       $a2, $a3, 0x60
    ctx->r6 = ADD32(ctx->r7, 0X60);
    after_1:
    // 0x80801238: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8080123C:
    // 0x8080123C: bne         $s0, $s4, L_80801210
    if (ctx->r16 != ctx->r20) {
        // 0x80801240: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80801210;
    }
    // 0x80801240: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80801244: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80801248: lhu         $t8, 0x6E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X6E);
    // 0x8080124C: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x80801250: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80801254: b           L_808012C0
    // 0x80801258: sh          $t0, 0x6E($v0)
    MEM_H(0X6E, ctx->r2) = ctx->r8;
        goto L_808012C0;
    // 0x80801258: sh          $t0, 0x6E($v0)
    MEM_H(0X6E, ctx->r2) = ctx->r8;
    // 0x8080125C: lw          $t1, 0x74($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X74);
L_80801260:
    // 0x80801260: sll         $t3, $t1, 10
    ctx->r11 = S32(ctx->r9 << 10);
    // 0x80801264: bgez        $t3, L_808012B8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80801268: nop
    
            goto L_808012B8;
    }
    // 0x80801268: nop

    // 0x8080126C: jal         0x80100094
    // 0x80801270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80801270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80801274: addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
    // 0x80801278: multu       $s2, $s3
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080127C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801280: mflo        $s1
    ctx->r17 = lo;
    // 0x80801284: addu        $a0, $v0, $s1
    ctx->r4 = ADD32(ctx->r2, ctx->r17);
    // 0x80801288: jal         0x80101038
    // 0x8080128C: nop

    func_80101038(rdram, ctx);
        goto after_3;
    // 0x8080128C: nop

    after_3:
    // 0x80801290: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80801294: addu        $t5, $s0, $s2
    ctx->r13 = ADD32(ctx->r16, ctx->r18);
    // 0x80801298: sb          $t4, 0xC0($t5)
    MEM_B(0XC0, ctx->r13) = ctx->r12;
    // 0x8080129C: addu        $a3, $s0, $s1
    ctx->r7 = ADD32(ctx->r16, ctx->r17);
    // 0x808012A0: addiu       $a2, $a3, 0x60
    ctx->r6 = ADD32(ctx->r7, 0X60);
    // 0x808012A4: lw          $a1, 0xD4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XD4);
    // 0x808012A8: jal         0x8080145C
    // 0x808012AC: addiu       $a0, $s0, 0xC8
    ctx->r4 = ADD32(ctx->r16, 0XC8);
    func_8080145C_chgameselect(rdram, ctx);
        goto after_4;
    // 0x808012AC: addiu       $a0, $s0, 0xC8
    ctx->r4 = ADD32(ctx->r16, 0XC8);
    after_4:
    // 0x808012B0: b           L_808012C4
    // 0x808012B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808012C4;
    // 0x808012B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808012B8:
    // 0x808012B8: b           L_808012C4
    // 0x808012BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808012C4;
    // 0x808012BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808012C0:
    // 0x808012C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808012C4:
    // 0x808012C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808012C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808012CC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808012D0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808012D4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808012D8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808012DC: jr          $ra
    // 0x808012E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808012E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_808023C8_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808023C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808023CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808023D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808023D4: jal         0x80100094
    // 0x808023D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808023D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808023DC: lw          $t6, 0x60($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X60);
    // 0x808023E0: bnel        $t6, $zero, L_80802404
    if (ctx->r14 != 0) {
        // 0x808023E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802404;
    }
    goto skip_0;
    // 0x808023E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808023E8: lh          $t7, 0x64($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X64);
    // 0x808023EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808023F0: beql        $t7, $zero, L_80802404
    if (ctx->r15 == 0) {
        // 0x808023F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802404;
    }
    goto skip_1;
    // 0x808023F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808023F8: jal         0x80800F34
    // 0x808023FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800F34_chboilerboss(rdram, ctx);
        goto after_1;
    // 0x808023FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80802400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802404:
    // 0x80802404: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802408: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080240C: jr          $ra
    // 0x80802410: nop

    return;
    // 0x80802410: nop

;}
RECOMP_FUNC void bsstand_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800B70: jal         0x800A0CF4
    // 0x80800B74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_0;
    // 0x80800B74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800B78: jal         0x80090A2C
    // 0x80800B7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80090A2C(rdram, ctx);
        goto after_1;
    // 0x80800B7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800B80: jal         0x800951B4
    // 0x80800B84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800951B4(rdram, ctx);
        goto after_2;
    // 0x80800B84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800B88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B90: jr          $ra
    // 0x80800B94: nop

    return;
    // 0x80800B94: nop

;}
RECOMP_FUNC void _chklungophial_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800863B8: syscall     317
    recomp_syscall_handler(rdram, ctx, 0x800863B8);
    return;
    // 0x800863BC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void sulights_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808004B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808004B8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808004BC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808004C0: jal         0x800C8900
    // 0x808004C4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800C8900(rdram, ctx);
        goto after_0;
    // 0x808004C4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x808004C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808004CC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x808004D0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x808004D4: jal         0x808003F8
    // 0x808004D8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    sulights_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808004D8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x808004DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808004E4: jr          $ra
    // 0x808004E8: nop

    return;
    // 0x808004E8: nop

;}
RECOMP_FUNC void suexpression_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B44: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800B48: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800B4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800B54: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800B58: jal         0x80800044
    // 0x80800B5C: lbu         $a0, 0xD($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XD);
    suexpression_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800B5C: lbu         $a0, 0xD($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XD);
    after_0:
    // 0x80800B60: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800B64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800B68: jal         0x8010262C
    // 0x80800B6C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_8010262C(rdram, ctx);
        goto after_1;
    // 0x80800B6C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x80800B70: beq         $v0, $zero, L_80800CA4
    if (ctx->r2 == 0) {
        // 0x80800B74: sw          $v0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r2;
            goto L_80800CA4;
    }
    // 0x80800B74: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800B78: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x80800B7C: beq         $v0, $zero, L_80800B8C
    if (ctx->r2 == 0) {
        // 0x80800B80: addu        $a0, $s0, $v0
        ctx->r4 = ADD32(ctx->r16, ctx->r2);
            goto L_80800B8C;
    }
    // 0x80800B80: addu        $a0, $s0, $v0
    ctx->r4 = ADD32(ctx->r16, ctx->r2);
    // 0x80800B84: jal         0x80089780
    // 0x80800B88: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    _suexpressjoint_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800B88: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_2:
L_80800B8C:
    // 0x80800B8C: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    // 0x80800B90: bnel        $v0, $zero, L_80800BC0
    if (ctx->r2 != 0) {
        // 0x80800B94: lh          $t0, 0x8($s0)
        ctx->r8 = MEM_H(ctx->r16, 0X8);
            goto L_80800BC0;
    }
    goto skip_0;
    // 0x80800B94: lh          $t0, 0x8($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X8);
    skip_0:
    // 0x80800B98: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x80800B9C: bnel        $t7, $zero, L_80800BC0
    if (ctx->r15 != 0) {
        // 0x80800BA0: lh          $t0, 0x8($s0)
        ctx->r8 = MEM_H(ctx->r16, 0X8);
            goto L_80800BC0;
    }
    goto skip_1;
    // 0x80800BA0: lh          $t0, 0x8($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X8);
    skip_1:
    // 0x80800BA4: lh          $t8, 0x8($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X8);
    // 0x80800BA8: bnel        $t8, $zero, L_80800BC0
    if (ctx->r24 != 0) {
        // 0x80800BAC: lh          $t0, 0x8($s0)
        ctx->r8 = MEM_H(ctx->r16, 0X8);
            goto L_80800BC0;
    }
    goto skip_2;
    // 0x80800BAC: lh          $t0, 0x8($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X8);
    skip_2:
    // 0x80800BB0: lh          $t9, 0xA($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XA);
    // 0x80800BB4: beql        $t9, $zero, L_80800CA8
    if (ctx->r25 == 0) {
        // 0x80800BB8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800CA8;
    }
    goto skip_3;
    // 0x80800BB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80800BBC: lh          $t0, 0x8($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X8);
L_80800BC0:
    // 0x80800BC0: lbu         $t2, 0x11($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X11);
    // 0x80800BC4: lbu         $t4, 0x10($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X10);
    // 0x80800BC8: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x80800BCC: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800BD0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3138, 0XD4C) << 16);
    // 0x80800BD4: lwc1        $f0, 0xD4C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3138, 0XD4C));
    // 0x80800BD8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800BDC: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80800BE0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800BE4: mflo        $t3
    ctx->r11 = lo;
    // 0x80800BE8: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80800BEC: nop

    // 0x80800BF0: multu       $v0, $t4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800BF4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800BF8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800BFC: nop

    // 0x80800C00: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80800C04: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800C08: mflo        $t5
    ctx->r13 = lo;
    // 0x80800C0C: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80800C10: nop

    // 0x80800C14: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800C18: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80800C1C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80800C20: jal         0x800E0AFC
    // 0x80800C24: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_3;
    // 0x80800C24: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x80800C28: lh          $t6, 0x8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8);
    // 0x80800C2C: lbu         $t8, 0x11($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X11);
    // 0x80800C30: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x80800C34: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x80800C38: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x80800C3C: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800C40: lbu         $t2, 0x10($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X10);
    // 0x80800C44: lh          $t1, 0x4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X4);
    // 0x80800C48: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3138, 0XD50) << 16);
    // 0x80800C4C: subu        $t3, $v0, $t2
    ctx->r11 = SUB32(ctx->r2, ctx->r10);
    // 0x80800C50: lwc1        $f0, 0xD50($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3138, 0XD50));
    // 0x80800C54: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800C58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800C5C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800C60: mflo        $t0
    ctx->r8 = lo;
    // 0x80800C64: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80800C68: nop

    // 0x80800C6C: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800C70: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800C74: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800C78: nop

    // 0x80800C7C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80800C80: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80800C84: mflo        $t4
    ctx->r12 = lo;
    // 0x80800C88: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80800C8C: nop

    // 0x80800C90: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800C94: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80800C98: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800C9C: jal         0x800E0AFC
    // 0x80800CA0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_4;
    // 0x80800CA0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
L_80800CA4:
    // 0x80800CA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800CA8:
    // 0x80800CA8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800CAC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800CB0: jr          $ra
    // 0x80800CB4: nop

    return;
    // 0x80800CB4: nop

;}
RECOMP_FUNC void chklungophial_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1244, 0XC78) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0xC78
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1244, 0XC78));
    return;
    // 0x80800014: addiu       $v0, $v0, 0xC78
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1244, 0XC78));
;}
RECOMP_FUNC void func_800B525C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B525C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B5260: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800B5264: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800B5268: addiu       $s3, $s3, 0x7F18
    ctx->r19 = ADD32(ctx->r19, 0X7F18);
    // 0x800B526C: lh          $t6, 0x0($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X0);
    // 0x800B5270: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B5274: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B5278: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800B527C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B5280: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800B5284: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B5288: blez        $t6, L_800B52CC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800B528C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800B52CC;
    }
    // 0x800B528C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800B5290: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800B5294: addiu       $s4, $s4, 0x7F10
    ctx->r20 = ADD32(ctx->r20, 0X7F10);
    // 0x800B5298: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800B529C: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
L_800B52A0:
    // 0x800B52A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800B52A4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800B52A8: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x800B52AC: jal         0x800BC358
    // 0x800B52B0: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    func_800BC358(rdram, ctx);
        goto after_0;
    // 0x800B52B0: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_0:
    // 0x800B52B4: lh          $t9, 0x0($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X0);
    // 0x800B52B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B52BC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800B52C0: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B52C4: bnel        $at, $zero, L_800B52A0
    if (ctx->r1 != 0) {
        // 0x800B52C8: lw          $t7, 0x0($s4)
        ctx->r15 = MEM_W(ctx->r20, 0X0);
            goto L_800B52A0;
    }
    goto skip_0;
    // 0x800B52C8: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    skip_0:
L_800B52CC:
    // 0x800B52CC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B52D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B52D4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B52D8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B52DC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800B52E0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800B52E4: jr          $ra
    // 0x800B52E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B52E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800BCCFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCCFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BCD00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BCD04: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800BCD08: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    // 0x800BCD0C: addu        $t7, $a0, $a1
    ctx->r15 = ADD32(ctx->r4, ctx->r5);
    // 0x800BCD10: lbu         $t8, 0x8($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X8);
    // 0x800BCD14: subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    // 0x800BCD18: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x800BCD1C: addu        $a2, $a2, $t8
    ctx->r6 = ADD32(ctx->r6, ctx->r24);
    // 0x800BCD20: div         $zero, $a2, $v0
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r2)));
    // 0x800BCD24: mfhi        $a1
    ctx->r5 = hi;
    // 0x800BCD28: bne         $v0, $zero, L_800BCD34
    if (ctx->r2 != 0) {
        // 0x800BCD2C: nop
    
            goto L_800BCD34;
    }
    // 0x800BCD2C: nop

    // 0x800BCD30: break       7
    do_break(2148257072);
L_800BCD34:
    // 0x800BCD34: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BCD38: bne         $v0, $at, L_800BCD4C
    if (ctx->r2 != ctx->r1) {
        // 0x800BCD3C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BCD4C;
    }
    // 0x800BCD3C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BCD40: bne         $a2, $at, L_800BCD4C
    if (ctx->r6 != ctx->r1) {
        // 0x800BCD44: nop
    
            goto L_800BCD4C;
    }
    // 0x800BCD44: nop

    // 0x800BCD48: break       6
    do_break(2148257096);
L_800BCD4C:
    // 0x800BCD4C: jal         0x800BCCC0
    // 0x800BCD50: nop

    static_16_800BCCC0(rdram, ctx);
        goto after_0;
    // 0x800BCD50: nop

    after_0:
    // 0x800BCD54: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BCD58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BCD5C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800BCD60: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x800BCD64: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800BCD68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BCD6C: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x800BCD70: jr          $ra
    // 0x800BCD74: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    return;
    // 0x800BCD74: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
;}
RECOMP_FUNC void func_80803738_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803738: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080373C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803740: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80803744: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80803748: jal         0x808036F8
    // 0x8080374C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_808036F8_chgameselect(rdram, ctx);
        goto after_0;
    // 0x8080374C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80803750: beql        $v0, $zero, L_808037B0
    if (ctx->r2 == 0) {
        // 0x80803754: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808037B0;
    }
    goto skip_0;
    // 0x80803754: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80803758: jal         0x80088538
    // 0x8080375C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _glsavegame_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x8080375C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80803760: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80803764: jal         0x800DB7C0
    // 0x80803768: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DB7C0(rdram, ctx);
        goto after_2;
    // 0x80803768: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8080376C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80803770: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80803774: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x80803778: jal         0x800D04A0
    // 0x8080377C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800D04A0(rdram, ctx);
        goto after_3;
    // 0x8080377C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80803780: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80803784: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80803788: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x8080378C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80803790: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80803794: bgez        $t9, L_808037A4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80803798: nop
    
            goto L_808037A4;
    }
    // 0x80803798: nop

    // 0x8080379C: b           L_808037B0
    // 0x808037A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808037B0;
    // 0x808037A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808037A4:
    // 0x808037A4: b           L_808037B0
    // 0x808037A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_808037B0;
    // 0x808037A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808037AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808037B0:
    // 0x808037B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808037B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808037B8: jr          $ra
    // 0x808037BC: nop

    return;
    // 0x808037BC: nop

;}
RECOMP_FUNC void func_80800000_chlavaexplodbuild(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800008: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800014: lui         $a1, 0xC611
    ctx->r5 = S32(0XC611 << 16);
    // 0x80800018: ori         $a1, $a1, 0x5000
    ctx->r5 = ctx->r5 | 0X5000;
    // 0x8080001C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800020: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    // 0x80800024: lui         $a3, 0xC3FA
    ctx->r7 = S32(0XC3FA << 16);
    // 0x80800028: jal         0x800EFA4C
    // 0x8080002C: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x8080002C: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x80800030: jal         0x80103014
    // 0x80800034: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80103014(rdram, ctx);
        goto after_1;
    // 0x80800034: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080003C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800040: jr          $ra
    // 0x80800044: nop

    return;
    // 0x80800044: nop

;}
RECOMP_FUNC void _chbanjoctrl_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800863A0: syscall     315
    recomp_syscall_handler(rdram, ctx, 0x800863A0);
    return;
    // 0x800863A4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _vpmodule_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800890C8: syscall     761
    recomp_syscall_handler(rdram, ctx, 0x800890C8);
    return;
    // 0x800890CC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80013C48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013C48: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80013C4C: sw          $ra, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r31;
    // 0x80013C50: jal         0x80013B7C
    // 0x80013C54: nop

    func_80013B7C(rdram, ctx);
        goto after_0;
    // 0x80013C54: nop

    after_0:
    // 0x80013C58: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80013C5C: lwc1        $f2, 0x170C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X170C);
    // 0x80013C60: lw          $ra, 0x0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X0);
    // 0x80013C64: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x80013C68: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80013C6C: jr          $ra
    // 0x80013C70: nop

    return;
    // 0x80013C70: nop

;}
RECOMP_FUNC void func_800959FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800959FC: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x80095A00: jr          $ra
    // 0x80095A04: sw          $a1, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r5;
    return;
    // 0x80095A04: sw          $a1, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_808029AC_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808029AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808029B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808029B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808029B8: jal         0x800DA298
    // 0x808029BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808029BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x808029C0: beql        $v0, $zero, L_808029F4
    if (ctx->r2 == 0) {
        // 0x808029C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808029F4;
    }
    goto skip_0;
    // 0x808029C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808029C8: jal         0x800DA298
    // 0x808029CC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808029CC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x808029D0: bnel        $v0, $zero, L_808029F4
    if (ctx->r2 != 0) {
        // 0x808029D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808029F4;
    }
    goto skip_1;
    // 0x808029D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808029D8: jal         0x80801CB4
    // 0x808029DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80801CB4_chinflatableboss(rdram, ctx);
        goto after_2;
    // 0x808029DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808029E0: addiu       $a0, $zero, 0xEC
    ctx->r4 = ADD32(0, 0XEC);
    // 0x808029E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808029E8: jal         0x800D2498
    // 0x808029EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_3;
    // 0x808029EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x808029F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808029F4:
    // 0x808029F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808029F8: jr          $ra
    // 0x808029FC: nop

    return;
    // 0x808029FC: nop

;}
RECOMP_FUNC void bsjump_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080027C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800280: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800284: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800288: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8080028C: lw          $t6, 0x164($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X164);
    // 0x80800290: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800294: beql        $t6, $zero, L_808002A8
    if (ctx->r14 == 0) {
        // 0x80800298: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002A8;
    }
    goto skip_0;
    // 0x80800298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080029C: jal         0x8009FC80
    // 0x808002A0: nop

    func_8009FC80(rdram, ctx);
        goto after_0;
    // 0x808002A0: nop

    after_0:
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002A8:
    // 0x808002A8: jal         0x80095738
    // 0x808002AC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_isTrue(rdram, ctx);
        goto after_1;
    // 0x808002AC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_1:
    // 0x808002B0: beq         $v0, $zero, L_808002C8
    if (ctx->r2 == 0) {
        // 0x808002B4: nop
    
            goto L_808002C8;
    }
    // 0x808002B4: nop

    // 0x808002B8: jal         0x8009B7C0
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009B7C0(rdram, ctx);
        goto after_2;
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808002C0: b           L_808002D4
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808002D4;
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002C8:
    // 0x808002C8: jal         0x800841D8
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bswalk_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002D4:
    // 0x808002D4: jal         0x8009BB24
    // 0x808002D8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_8009BB24(rdram, ctx);
        goto after_4;
    // 0x808002D8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E0: jal         0x80091A30
    // 0x808002E4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_5;
    // 0x808002E4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_5:
    // 0x808002E8: beq         $v0, $zero, L_80800314
    if (ctx->r2 == 0) {
        // 0x808002EC: nop
    
            goto L_80800314;
    }
    // 0x808002EC: nop

    // 0x808002F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808002F4: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808002F8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808002FC: nop

    // 0x80800300: bc1f        L_80800314
    if (!c1cs) {
        // 0x80800304: nop
    
            goto L_80800314;
    }
    // 0x80800304: nop

    // 0x80800308: lw          $t7, 0x164($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X164);
    // 0x8080030C: beq         $t7, $zero, L_80800324
    if (ctx->r15 == 0) {
        // 0x80800310: nop
    
            goto L_80800324;
    }
    // 0x80800310: nop

L_80800314:
    // 0x80800314: jal         0x8008D544
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D544(rdram, ctx);
        goto after_6;
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080031C: bnel        $v0, $zero, L_80800330
    if (ctx->r2 != 0) {
        // 0x80800320: lw          $v0, 0x15C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X15C);
            goto L_80800330;
    }
    goto skip_1;
    // 0x80800320: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    skip_1:
L_80800324:
    // 0x80800324: jal         0x8009BC6C
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_7;
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080032C: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
L_80800330:
    // 0x80800330: beq         $v0, $zero, L_80800350
    if (ctx->r2 == 0) {
        // 0x80800334: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800350;
    }
    // 0x80800334: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800338: beq         $v0, $at, L_808003A8
    if (ctx->r2 == ctx->r1) {
        // 0x8080033C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808003A8;
    }
    // 0x8080033C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800340: beq         $v0, $at, L_808003FC
    if (ctx->r2 == ctx->r1) {
        // 0x80800344: nop
    
            goto L_808003FC;
    }
    // 0x80800344: nop

    // 0x80800348: b           L_808003FC
    // 0x8080034C: nop

        goto L_808003FC;
    // 0x8080034C: nop

L_80800350:
    // 0x80800350: jal         0x8008CAEC
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_8;
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800358: beq         $v0, $zero, L_80800378
    if (ctx->r2 == 0) {
        // 0x8080035C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800378;
    }
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800360: lui         $a1, 0x3F2A
    ctx->r5 = S32(0X3F2A << 16);
    // 0x80800364: ori         $a1, $a1, 0xACDA
    ctx->r5 = ctx->r5 | 0XACDA;
    // 0x80800368: jal         0x8008CF1C
    // 0x8080036C: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_9;
    // 0x8080036C: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    after_9:
    // 0x80800370: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800374: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
L_80800378:
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080037C: jal         0x8008DF8C
    // 0x80800380: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_10;
    // 0x80800380: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_10:
    // 0x80800384: beq         $v0, $zero, L_808003FC
    if (ctx->r2 == 0) {
        // 0x80800388: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003FC;
    }
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080038C: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x80800390: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800394: jal         0x8008CF1C
    // 0x80800398: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_11;
    // 0x80800398: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_11:
    // 0x8080039C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x808003A0: b           L_808003FC
    // 0x808003A4: sw          $t9, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r25;
        goto L_808003FC;
    // 0x808003A4: sw          $t9, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r25;
L_808003A8:
    // 0x808003A8: jal         0x8008CAEC
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_12;
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808003B0: beq         $v0, $zero, L_808003C0
    if (ctx->r2 == 0) {
        // 0x808003B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003C0;
    }
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B8: addiu       $t0, $zero, 0x2F
    ctx->r8 = ADD32(0, 0X2F);
    // 0x808003BC: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
L_808003C0:
    // 0x808003C0: lw          $t1, 0x164($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X164);
    // 0x808003C4: addiu       $t2, $zero, 0x21
    ctx->r10 = ADD32(0, 0X21);
    // 0x808003C8: beq         $t1, $zero, L_808003D8
    if (ctx->r9 == 0) {
        // 0x808003CC: nop
    
            goto L_808003D8;
    }
    // 0x808003CC: nop

    // 0x808003D0: sw          $zero, 0x164($s0)
    MEM_W(0X164, ctx->r16) = 0;
    // 0x808003D4: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
L_808003D8:
    // 0x808003D8: jal         0x8008DF8C
    // 0x808003DC: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_8008DF8C(rdram, ctx);
        goto after_13;
    // 0x808003DC: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_13:
    // 0x808003E0: beq         $v0, $zero, L_808003FC
    if (ctx->r2 == 0) {
        // 0x808003E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003FC;
    }
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808003EC: jal         0x8008CF1C
    // 0x808003F0: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_14;
    // 0x808003F0: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_14:
    // 0x808003F4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x808003F8: sw          $t3, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r11;
L_808003FC:
    // 0x808003FC: jal         0x8008E260
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E260(rdram, ctx);
        goto after_15;
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800404: beq         $v0, $zero, L_80800414
    if (ctx->r2 == 0) {
        // 0x80800408: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800414;
    }
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080040C: addiu       $t4, $zero, 0x3D
    ctx->r12 = ADD32(0, 0X3D);
    // 0x80800410: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
L_80800414:
    // 0x80800414: jal         0x80091A30
    // 0x80800418: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_16;
    // 0x80800418: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_16:
    // 0x8080041C: beq         $v0, $zero, L_80800428
    if (ctx->r2 == 0) {
        // 0x80800420: nop
    
            goto L_80800428;
    }
    // 0x80800420: nop

    // 0x80800424: sw          $zero, 0x164($s0)
    MEM_W(0X164, ctx->r16) = 0;
L_80800428:
    // 0x80800428: jal         0x800A3274
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3274(rdram, ctx);
        goto after_17;
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800430: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800434: beq         $v0, $at, L_8080044C
    if (ctx->r2 == ctx->r1) {
        // 0x80800438: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8080044C;
    }
    // 0x80800438: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8080043C: beq         $v0, $at, L_808004E4
    if (ctx->r2 == ctx->r1) {
        // 0x80800440: nop
    
            goto L_808004E4;
    }
    // 0x80800440: nop

    // 0x80800444: b           L_808004F8
    // 0x80800448: nop

        goto L_808004F8;
    // 0x80800448: nop

L_8080044C:
    // 0x8080044C: jal         0x80097DF4
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097DF4(rdram, ctx);
        goto after_18;
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800454: beq         $v0, $zero, L_80800460
    if (ctx->r2 == 0) {
        // 0x80800458: addiu       $t5, $zero, 0x10
        ctx->r13 = ADD32(0, 0X10);
            goto L_80800460;
    }
    // 0x80800458: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x8080045C: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
L_80800460:
    // 0x80800460: jal         0x80097F08
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097F08(rdram, ctx);
        goto after_19;
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800468: beq         $v0, $zero, L_808004CC
    if (ctx->r2 == 0) {
        // 0x8080046C: nop
    
            goto L_808004CC;
    }
    // 0x8080046C: nop

    // 0x80800470: jal         0x8009C150
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009C150(rdram, ctx);
        goto after_20;
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800478: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8080047C: jal         0x800964DC
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800964DC(rdram, ctx);
        goto after_21;
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800484: lw          $v0, 0x160($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X160);
    // 0x80800488: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080048C: beq         $v0, $zero, L_808004C0
    if (ctx->r2 == 0) {
        // 0x80800490: nop
    
            goto L_808004C0;
    }
    // 0x80800490: nop

    // 0x80800494: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80800498: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8080049C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808004A0: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x808004A4: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x808004A8: nop

    // 0x808004AC: bc1f        L_808004B8
    if (!c1cs) {
        // 0x808004B0: nop
    
            goto L_808004B8;
    }
    // 0x808004B0: nop

    // 0x808004B4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_808004B8:
    // 0x808004B8: bnel        $t6, $zero, L_808004C8
    if (ctx->r14 != 0) {
        // 0x808004BC: addiu       $t7, $zero, 0x11
        ctx->r15 = ADD32(0, 0X11);
            goto L_808004C8;
    }
    goto skip_2;
    // 0x808004BC: addiu       $t7, $zero, 0x11
    ctx->r15 = ADD32(0, 0X11);
    skip_2:
L_808004C0:
    // 0x808004C0: bne         $v0, $zero, L_808004CC
    if (ctx->r2 != 0) {
        // 0x808004C4: addiu       $t7, $zero, 0x11
        ctx->r15 = ADD32(0, 0X11);
            goto L_808004CC;
    }
    // 0x808004C4: addiu       $t7, $zero, 0x11
    ctx->r15 = ADD32(0, 0X11);
L_808004C8:
    // 0x808004C8: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
L_808004CC:
    // 0x808004CC: jal         0x80097A90
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_beak_bust(rdram, ctx);
        goto after_22;
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808004D4: beq         $v0, $zero, L_808004F8
    if (ctx->r2 == 0) {
        // 0x808004D8: addiu       $t8, $zero, 0xF
        ctx->r24 = ADD32(0, 0XF);
            goto L_808004F8;
    }
    // 0x808004D8: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x808004DC: b           L_808004F8
    // 0x808004E0: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
        goto L_808004F8;
    // 0x808004E0: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
L_808004E4:
    // 0x808004E4: jal         0x80097EC8
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097EC8(rdram, ctx);
        goto after_23;
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808004EC: beq         $v0, $zero, L_808004F8
    if (ctx->r2 == 0) {
        // 0x808004F0: addiu       $t9, $zero, 0xE4
        ctx->r25 = ADD32(0, 0XE4);
            goto L_808004F8;
    }
    // 0x808004F0: addiu       $t9, $zero, 0xE4
    ctx->r25 = ADD32(0, 0XE4);
    // 0x808004F4: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
L_808004F8:
    // 0x808004F8: jal         0x8008DA24
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DA24(rdram, ctx);
        goto after_24;
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800500: beq         $v0, $zero, L_8080050C
    if (ctx->r2 == 0) {
        // 0x80800504: addiu       $t0, $zero, 0xA8
        ctx->r8 = ADD32(0, 0XA8);
            goto L_8080050C;
    }
    // 0x80800504: addiu       $t0, $zero, 0xA8
    ctx->r8 = ADD32(0, 0XA8);
    // 0x80800508: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
L_8080050C:
    // 0x8080050C: jal         0x8008E078
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_25;
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800514: beql        $v0, $zero, L_80800558
    if (ctx->r2 == 0) {
        // 0x80800518: lwc1        $f4, 0x34($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
            goto L_80800558;
    }
    goto skip_3;
    // 0x80800518: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    skip_3:
    // 0x8080051C: jal         0x8009FE58
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FE58(rdram, ctx);
        goto after_26;
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80800524: jal         0x8009BB00
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_27;
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x8080052C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800530: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80800534: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x80800538: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x8080053C: nop

    // 0x80800540: bc1tl       L_80800554
    if (c1cs) {
        // 0x80800544: sw          $t2, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r10;
            goto L_80800554;
    }
    goto skip_4;
    // 0x80800544: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    skip_4:
    // 0x80800548: b           L_80800554
    // 0x8080054C: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
        goto L_80800554;
    // 0x8080054C: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80800550: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
L_80800554:
    // 0x80800554: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
L_80800558:
    // 0x80800558: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8080055C: nop

    // 0x80800560: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800564: nop

    // 0x80800568: bc1fl       L_80800588
    if (!c1cs) {
        // 0x8080056C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800588;
    }
    goto skip_5;
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
    // 0x80800570: jal         0x8008E35C
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_28;
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80800578: beq         $v0, $zero, L_80800584
    if (ctx->r2 == 0) {
        // 0x8080057C: addiu       $t3, $zero, 0x4C
        ctx->r11 = ADD32(0, 0X4C);
            goto L_80800584;
    }
    // 0x8080057C: addiu       $t3, $zero, 0x4C
    ctx->r11 = ADD32(0, 0X4C);
    // 0x80800580: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
L_80800584:
    // 0x80800584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800588:
    // 0x80800588: jal         0x8009E5C8
    // 0x8080058C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    bs_setState(rdram, ctx);
        goto after_29;
    // 0x8080058C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_29:
    // 0x80800590: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800594: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800598: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080059C: jr          $ra
    // 0x808005A0: nop

    return;
    // 0x808005A0: nop

;}
RECOMP_FUNC void func_800A9D00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9D00: jr          $ra
    // 0x800A9D04: nop

    return;
    // 0x800A9D04: nop

;}
RECOMP_FUNC void _vpscroll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089080: syscall     759
    recomp_syscall_handler(rdram, ctx, 0x80089080);
    return;
    // 0x80089084: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800C78CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C78CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C78D0: beq         $a0, $zero, L_800C78E8
    if (ctx->r4 == 0) {
        // 0x800C78D4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800C78E8;
    }
    // 0x800C78D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C78D8: jal         0x800C76E8
    // 0x800C78DC: nop

    func_800C76E8(rdram, ctx);
        goto after_0;
    // 0x800C78DC: nop

    after_0:
    // 0x800C78E0: b           L_800C78F4
    // 0x800C78E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800C78F4;
    // 0x800C78E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C78E8:
    // 0x800C78E8: jal         0x800C775C
    // 0x800C78EC: nop

    func_800C775C(rdram, ctx);
        goto after_1;
    // 0x800C78EC: nop

    after_1:
    // 0x800C78F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C78F4:
    // 0x800C78F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C78F8: jr          $ra
    // 0x800C78FC: nop

    return;
    // 0x800C78FC: nop

;}
RECOMP_FUNC void func_800908A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800908A0: jr          $ra
    // 0x800908A4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    return;
    // 0x800908A4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80116218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80116218: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8011621C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80116220: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80116224: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80116228: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8011622C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80116230: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80116234: lbu         $t6, 0x2C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2C);
    // 0x80116238: beq         $t6, $zero, L_80116248
    if (ctx->r14 == 0) {
        // 0x8011623C: nop
    
            goto L_80116248;
    }
    // 0x8011623C: nop

    // 0x80116240: b           L_8011625C
    // 0x80116244: lwc1        $f14, 0x28($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X28);
        goto L_8011625C;
    // 0x80116244: lwc1        $f14, 0x28($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X28);
L_80116248:
    // 0x80116248: jal         0x80110840
    // 0x8011624C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80110840(rdram, ctx);
        goto after_0;
    // 0x8011624C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80116250: jal         0x800F5F50
    // 0x80116254: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5F50(rdram, ctx);
        goto after_1;
    // 0x80116254: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80116258: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_8011625C:
    // 0x8011625C: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80116260: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80116264: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80116268: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x8011626C: jal         0x800136E4
    // 0x80116270: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_2;
    // 0x80116270: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_2:
    // 0x80116274: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80116278: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8011627C: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x80116280: lh          $t7, 0x2E($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2E);
    // 0x80116284: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80116288: addiu       $a1, $v0, 0x34
    ctx->r5 = ADD32(ctx->r2, 0X34);
    // 0x8011628C: beq         $t7, $zero, L_801162B0
    if (ctx->r15 == 0) {
        // 0x80116290: addiu       $a2, $v0, 0x3C
        ctx->r6 = ADD32(ctx->r2, 0X3C);
            goto L_801162B0;
    }
    // 0x80116290: addiu       $a2, $v0, 0x3C
    ctx->r6 = ADD32(ctx->r2, 0X3C);
    // 0x80116294: lbu         $t8, 0x48($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X48);
    // 0x80116298: beq         $t8, $zero, L_801162A8
    if (ctx->r24 == 0) {
        // 0x8011629C: nop
    
            goto L_801162A8;
    }
    // 0x8011629C: nop

    // 0x801162A0: b           L_801162B8
    // 0x801162A4: lwc1        $f12, 0x44($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X44);
        goto L_801162B8;
    // 0x801162A4: lwc1        $f12, 0x44($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X44);
L_801162A8:
    // 0x801162A8: b           L_801162B8
    // 0x801162AC: lwc1        $f12, 0x40($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X40);
        goto L_801162B8;
    // 0x801162AC: lwc1        $f12, 0x40($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X40);
L_801162B0:
    // 0x801162B0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801162B4: nop

L_801162B8:
    // 0x801162B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801162BC: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x801162C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801162C4: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x801162C8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801162CC: jal         0x80115EA8
    // 0x801162D0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_80115EA8(rdram, ctx);
        goto after_3;
    // 0x801162D0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x801162D4: jal         0x800137AC
    // 0x801162D8: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    func_800137AC(rdram, ctx);
        goto after_4;
    // 0x801162D8: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    after_4:
    // 0x801162DC: jal         0x800137C4
    // 0x801162E0: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    func_800137C4(rdram, ctx);
        goto after_5;
    // 0x801162E0: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x801162E4: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x801162E8: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x801162EC: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801162F0: lwc1        $f4, 0x34($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X34);
    // 0x801162F4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801162F8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x801162FC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80116300: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80116304: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80116308: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8011630C: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x80116310: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x80116314: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x80116318: lwc1        $f8, 0x34($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X34);
    // 0x8011631C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80116320: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x80116324: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80116328: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8011632C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80116330: addiu       $a1, $v0, 0x50
    ctx->r5 = ADD32(ctx->r2, 0X50);
    // 0x80116334: jal         0x80116120
    // 0x80116338: addiu       $a2, $v0, 0x4C
    ctx->r6 = ADD32(ctx->r2, 0X4C);
    func_80116120(rdram, ctx);
        goto after_6;
    // 0x80116338: addiu       $a2, $v0, 0x4C
    ctx->r6 = ADD32(ctx->r2, 0X4C);
    after_6:
    // 0x8011633C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80116340: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80116344: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80116348: lwc1        $f6, 0x54($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X54);
    // 0x8011634C: lwc1        $f16, 0x58($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80116350: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80116354: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80116358: nop

    // 0x8011635C: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80116360: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80116364: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80116368: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    // 0x8011636C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80116370: lwc1        $f8, 0x58($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80116374: lwc1        $f16, 0x50($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X50);
    // 0x80116378: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8011637C: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80116380: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x80116384: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x80116388: sb          $zero, 0x48($t1)
    MEM_B(0X48, ctx->r9) = 0;
    // 0x8011638C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80116390: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80116394: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80116398: jr          $ra
    // 0x8011639C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8011639C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80801130_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801130: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801134: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801138: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080113C: jal         0x808009B0
    // 0x80801140: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808009B0_bssub(rdram, ctx);
        goto after_0;
    // 0x80801140: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801144: jal         0x8080102C
    // 0x80801148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080102C_bssub(rdram, ctx);
        goto after_1;
    // 0x80801148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080114C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80801150: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80801154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801158: jal         0x8008C9BC
    // 0x8080115C: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_2;
    // 0x8080115C: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_2:
    // 0x80801160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801164: jal         0x8008CA30
    // 0x80801168: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8008CA30(rdram, ctx);
        goto after_3;
    // 0x80801168: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_3:
    // 0x8080116C: jal         0x800909CC
    // 0x80801170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800909CC(rdram, ctx);
        goto after_4;
    // 0x80801170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801174: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801178: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080117C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801180: jr          $ra
    // 0x80801184: nop

    return;
    // 0x80801184: nop

;}
RECOMP_FUNC void func_80800300_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800300: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800304: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800308: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080030C: jal         0x8009C990
    // 0x80800310: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_0;
    // 0x80800310: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800314: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800318: jal         0x8009C984
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_1;
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800320: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800324: jal         0x800F1DCC
    // 0x80800328: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F1DCC(rdram, ctx);
        goto after_2;
    // 0x80800328: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_2:
    // 0x8080032C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800330: jal         0x80085410
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bawasher_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800338: jal         0x8009BB5C
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB5C(rdram, ctx);
        goto after_4;
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800340: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800344: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800348: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080034C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800350: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800354: lui         $a2, 0x4461
    ctx->r6 = S32(0X4461 << 16);
    // 0x80800358: bc1fl       L_80800384
    if (!c1cs) {
        // 0x8080035C: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_80800384;
    }
    goto skip_0;
    // 0x8080035C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_0:
    // 0x80800360: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800364: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(443, 0X1CF0) << 16);
    // 0x80800368: lwc1        $f6, 0x1CF0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(443, 0X1CF0));
    // 0x8080036C: lui         $a3, 0x4234
    ctx->r7 = S32(0X4234 << 16);
    // 0x80800370: jal         0x800F10B4
    // 0x80800374: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x80800374: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x80800378: b           L_80800388
    // 0x8080037C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_80800388;
    // 0x8080037C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800380: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_80800384:
    // 0x80800384: nop

L_80800388:
    // 0x80800388: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8080038C: jal         0x80085418
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bawasher_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800394: jal         0x8009BB5C
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB5C(rdram, ctx);
        goto after_7;
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080039C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808003A0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808003A4: lui         $a2, 0x4461
    ctx->r6 = S32(0X4461 << 16);
    // 0x808003A8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x808003AC: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x808003B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(443, 0X1CF4) << 16);
    // 0x808003B4: bc1f        L_808003E0
    if (!c1cs) {
        // 0x808003B8: nop
    
            goto L_808003E0;
    }
    // 0x808003B8: nop

    // 0x808003BC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808003C0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808003C4: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x808003C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808003CC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808003D0: jal         0x800F10B4
    // 0x808003D4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x808003D4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x808003D8: b           L_808003E4
    // 0x808003DC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_808003E4;
    // 0x808003DC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_808003E0:
    // 0x808003E0: lwc1        $f2, 0x1CF4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(443, 0X1CF4));
L_808003E4:
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E8: jal         0x8008E078
    // 0x808003EC: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    player_isStable(rdram, ctx);
        goto after_9;
    // 0x808003EC: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    after_9:
    // 0x808003F0: bne         $v0, $zero, L_80800410
    if (ctx->r2 != 0) {
        // 0x808003F4: lwc1        $f2, 0x3C($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_80800410;
    }
    // 0x808003F4: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808003F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(443, 0X1CF8) << 16);
    // 0x808003FC: lwc1        $f12, 0x1CF8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(443, 0X1CF8));
    // 0x80800400: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(443, 0X1CFC) << 16);
    // 0x80800404: lwc1        $f16, 0x1CFC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(443, 0X1CFC));
    // 0x80800408: jal         0x800F13F0
    // 0x8080040C: add.s       $f14, $f2, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f16.fl;
    func_800F13F0(rdram, ctx);
        goto after_10;
    // 0x8080040C: add.s       $f14, $f2, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f16.fl;
    after_10:
L_80800410:
    // 0x80800410: jal         0x80085438
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bawasher_entrypoint_9(rdram, ctx);
        goto after_11;
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800418: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080041C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800420: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800424: jr          $ra
    // 0x80800428: nop

    return;
    // 0x80800428: nop

;}
RECOMP_FUNC void func_80800590_chcablespark(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800590: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800594: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800598: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080059C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808005A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005A4: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x808005A8: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x808005AC: jal         0x800E3980
    // 0x808005B0: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    func_800E3980(rdram, ctx);
        goto after_0;
    // 0x808005B0: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x808005B4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808005B8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808005BC: jal         0x800EFB24
    // 0x808005C0: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x808005C0: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_1:
    // 0x808005C4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808005C8: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    // 0x808005CC: lw          $a2, 0x28($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X28);
    // 0x808005D0: jal         0x800EEC30
    // 0x808005D4: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    func_800EEC30(rdram, ctx);
        goto after_2;
    // 0x808005D4: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    after_2:
    // 0x808005D8: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808005DC: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x808005E0: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    // 0x808005E4: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x808005E8: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x808005EC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808005F0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x808005F4: bc1f        L_80800610
    if (!c1cs) {
        // 0x808005F8: nop
    
            goto L_80800610;
    }
    // 0x808005F8: nop

    // 0x808005FC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800600: jal         0x800EE97C
    // 0x80800604: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_800EE97C(rdram, ctx);
        goto after_3;
    // 0x80800604: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_3:
    // 0x80800608: b           L_8080061C
    // 0x8080060C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
        goto L_8080061C;
    // 0x8080060C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
L_80800610:
    // 0x80800610: jal         0x800EE97C
    // 0x80800614: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_800EE97C(rdram, ctx);
        goto after_4;
    // 0x80800614: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_4:
    // 0x80800618: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
L_8080061C:
    // 0x8080061C: jal         0x800F1884
    // 0x80800620: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800F1884(rdram, ctx);
        goto after_5;
    // 0x80800620: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x80800624: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x80800628: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8080062C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800630: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800634: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80800638: lwc1        $f16, 0x28($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8080063C: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x80800640: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800644: jal         0x800136E4
    // 0x80800648: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_6;
    // 0x80800648: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    after_6:
    // 0x8080064C: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80800650: swc1        $f0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f0.u32l;
    // 0x80800654: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800658: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080065C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800660: jr          $ra
    // 0x80800664: nop

    return;
    // 0x80800664: nop

;}
RECOMP_FUNC void _bskazshoessuckspline_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800835E8: syscall     68
    recomp_syscall_handler(rdram, ctx, 0x800835E8);
    return;
    // 0x800835EC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void ncbatarget_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080010C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800110: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800114: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800118: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080011C: jal         0x8011607C
    // 0x80800120: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8011607C(rdram, ctx);
        goto after_0;
    // 0x80800120: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800128: jal         0x80800058
    // 0x8080012C: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_80800058_ncbatarget(rdram, ctx);
        goto after_1;
    // 0x8080012C: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_1:
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800134: jal         0x80800008
    // 0x80800138: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_80800008_ncbatarget(rdram, ctx);
        goto after_2;
    // 0x80800138: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_2:
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800140: jal         0x801107F0
    // 0x80800144: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_801107F0(rdram, ctx);
        goto after_3;
    // 0x80800144: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_3:
    // 0x80800148: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8080014C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800150: jal         0x800EFB24
    // 0x80800154: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    func_800EFB24(rdram, ctx);
        goto after_4;
    // 0x80800154: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    after_4:
    // 0x80800158: jal         0x800EEF94
    // 0x8080015C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_800EEF94(rdram, ctx);
        goto after_5;
    // 0x8080015C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_5:
    // 0x80800160: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80800164: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80800168: jal         0x800F1A88
    // 0x8080016C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800F1A88(rdram, ctx);
        goto after_6;
    // 0x8080016C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_6:
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800174: jal         0x80115358
    // 0x80800178: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80115358(rdram, ctx);
        goto after_7;
    // 0x80800178: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x8080017C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: jal         0x80115750
    // 0x80800188: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80115750(rdram, ctx);
        goto after_8;
    // 0x80800188: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_8:
    // 0x8080018C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80800190: lw          $a0, 0x58($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X58);
    // 0x80800194: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x80800198: jal         0x800F1E6C
    // 0x8080019C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_800F1E6C(rdram, ctx);
        goto after_9;
    // 0x8080019C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_9:
    // 0x808001A0: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808001AC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808001B0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808001B4: jal         0x80112D08
    // 0x808001B8: nop

    func_80112D08(rdram, ctx);
        goto after_10;
    // 0x808001B8: nop

    after_10:
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C0: jal         0x80112C3C
    // 0x808001C4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80112C3C(rdram, ctx);
        goto after_11;
    // 0x808001C4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_11:
    // 0x808001C8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808001CC: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x808001D0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808001D4: jal         0x800EEBF0
    // 0x808001D8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_800EEBF0(rdram, ctx);
        goto after_12;
    // 0x808001D8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_12:
    // 0x808001DC: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808001E0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x808001E4: jal         0x800EE780
    // 0x808001E8: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_800EE780(rdram, ctx);
        goto after_13;
    // 0x808001E8: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_13:
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F0: jal         0x80111FD4
    // 0x808001F4: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_80111FD4(rdram, ctx);
        goto after_14;
    // 0x808001F4: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_14:
    // 0x808001F8: beql        $v0, $zero, L_8080022C
    if (ctx->r2 == 0) {
        // 0x808001FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080022C;
    }
    goto skip_0;
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800200: jal         0x801138A0
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138A0(rdram, ctx);
        goto after_15;
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800208: beql        $v0, $zero, L_8080022C
    if (ctx->r2 == 0) {
        // 0x8080020C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080022C;
    }
    goto skip_1;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800210: jal         0x801138F4
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138F4(rdram, ctx);
        goto after_16;
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800218: beql        $v0, $zero, L_8080022C
    if (ctx->r2 == 0) {
        // 0x8080021C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080022C;
    }
    goto skip_2;
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800220: jal         0x80110F44
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80110F44(rdram, ctx);
        goto after_17;
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080022C:
    // 0x8080022C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800230: jal         0x80110A68
    // 0x80800234: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    func_80110A68(rdram, ctx);
        goto after_18;
    // 0x80800234: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_18:
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: jal         0x80110790
    // 0x80800240: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80110790(rdram, ctx);
        goto after_19;
    // 0x80800240: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_19:
    // 0x80800244: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800248: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080024C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80800250: jr          $ra
    // 0x80800254: nop

    return;
    // 0x80800254: nop

;}
RECOMP_FUNC void func_800F91EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F91EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F91F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F91F4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F91F8: jal         0x800B2F58
    // 0x800F91FC: lw          $a0, 0x54F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X54F0);
    vector_defrag(rdram, ctx);
        goto after_0;
    // 0x800F91FC: lw          $a0, 0x54F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X54F0);
    after_0:
    // 0x800F9200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F9204: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F9208: sw          $v0, 0x54F0($at)
    MEM_W(0X54F0, ctx->r1) = ctx->r2;
    // 0x800F920C: jr          $ra
    // 0x800F9210: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F9210: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800050_chfaircoinbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800050: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800058: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x8080005C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2132, 0X470) << 16);
    // 0x80800060: addiu       $t8, $t8, 0x470
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2132, 0X470));
    // 0x80800064: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80800068: addiu       $v0, $t6, -0x32
    ctx->r2 = ADD32(ctx->r14, -0X32);
    // 0x8080006C: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80800070: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80800074: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x80800078: jal         0x800DA298
    // 0x8080007C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080007C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x80800080: beq         $v0, $zero, L_80800090
    if (ctx->r2 == 0) {
        // 0x80800084: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_80800090;
    }
    // 0x80800084: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80800088: jal         0x800DA544
    // 0x8080008C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x8080008C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_1:
L_80800090:
    // 0x80800090: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80800094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800098: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8080009C: jr          $ra
    // 0x808000A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808000A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_808000E8_gldbDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808000EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808000F4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808000F8: jal         0x80800000
    // 0x808000FC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_80800000_gldbDll(rdram, ctx);
        goto after_0;
    // 0x808000FC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800100: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80800104: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x80800108: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8080010C: blez        $a2, L_8080029C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80800110: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8080029C;
    }
    // 0x80800110: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800114: andi        $a0, $a2, 0x3
    ctx->r4 = ctx->r6 & 0X3;
    // 0x80800118: beq         $a0, $zero, L_8080017C
    if (ctx->r4 == 0) {
        // 0x8080011C: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8080017C;
    }
    // 0x8080011C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800120: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800124: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80800128: addu        $v0, $t0, $v1
    ctx->r2 = ADD32(ctx->r8, ctx->r3);
L_8080012C:
    // 0x8080012C: div         $zero, $v1, $a0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r4)));
    // 0x80800130: mfhi        $t6
    ctx->r14 = hi;
    // 0x80800134: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x80800138: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8080013C: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80800140: bne         $a0, $zero, L_8080014C
    if (ctx->r4 != 0) {
        // 0x80800144: nop
    
            goto L_8080014C;
    }
    // 0x80800144: nop

    // 0x80800148: break       7
    do_break(2155872584);
L_8080014C:
    // 0x8080014C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800150: bne         $a0, $at, L_80800164
    if (ctx->r4 != ctx->r1) {
        // 0x80800154: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80800164;
    }
    // 0x80800154: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800158: bne         $v1, $at, L_80800164
    if (ctx->r3 != ctx->r1) {
        // 0x8080015C: nop
    
            goto L_80800164;
    }
    // 0x8080015C: nop

    // 0x80800160: break       6
    do_break(2155872608);
L_80800164:
    // 0x80800164: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800168: xor         $t1, $t8, $t9
    ctx->r9 = ctx->r24 ^ ctx->r25;
    // 0x8080016C: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x80800170: bne         $a1, $v1, L_8080012C
    if (ctx->r5 != ctx->r3) {
        // 0x80800174: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8080012C;
    }
    // 0x80800174: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800178: beq         $v1, $a2, L_8080029C
    if (ctx->r3 == ctx->r6) {
        // 0x8080017C: addiu       $a0, $zero, 0xE
        ctx->r4 = ADD32(0, 0XE);
            goto L_8080029C;
    }
L_8080017C:
    // 0x8080017C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80800180: addu        $v0, $t0, $v1
    ctx->r2 = ADD32(ctx->r8, ctx->r3);
L_80800184:
    // 0x80800184: div         $zero, $v1, $a0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r4)));
    // 0x80800188: mfhi        $t2
    ctx->r10 = hi;
    // 0x8080018C: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x80800190: addu        $t3, $a3, $t2
    ctx->r11 = ADD32(ctx->r7, ctx->r10);
    // 0x80800194: div         $zero, $t7, $a0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r4)));
    // 0x80800198: mfhi        $t8
    ctx->r24 = hi;
    // 0x8080019C: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x808001A0: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x808001A4: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x808001A8: lbu         $t2, 0x1($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1);
    // 0x808001AC: xor         $t6, $t4, $t5
    ctx->r14 = ctx->r12 ^ ctx->r13;
    // 0x808001B0: addiu       $t4, $v1, 0x2
    ctx->r12 = ADD32(ctx->r3, 0X2);
    // 0x808001B4: div         $zero, $t4, $a0
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r4)));
    // 0x808001B8: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x808001BC: lbu         $t1, 0x0($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X0);
    // 0x808001C0: mfhi        $t5
    ctx->r13 = hi;
    // 0x808001C4: addu        $t6, $a3, $t5
    ctx->r14 = ADD32(ctx->r7, ctx->r13);
    // 0x808001C8: xor         $t3, $t1, $t2
    ctx->r11 = ctx->r9 ^ ctx->r10;
    // 0x808001CC: addiu       $t1, $v1, 0x3
    ctx->r9 = ADD32(ctx->r3, 0X3);
    // 0x808001D0: div         $zero, $t1, $a0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r4)));
    // 0x808001D4: bne         $a0, $zero, L_808001E0
    if (ctx->r4 != 0) {
        // 0x808001D8: nop
    
            goto L_808001E0;
    }
    // 0x808001D8: nop

    // 0x808001DC: break       7
    do_break(2155872732);
L_808001E0:
    // 0x808001E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808001E4: bne         $a0, $at, L_808001F8
    if (ctx->r4 != ctx->r1) {
        // 0x808001E8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_808001F8;
    }
    // 0x808001E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808001EC: bne         $v1, $at, L_808001F8
    if (ctx->r3 != ctx->r1) {
        // 0x808001F0: nop
    
            goto L_808001F8;
    }
    // 0x808001F0: nop

    // 0x808001F4: break       6
    do_break(2155872756);
L_808001F8:
    // 0x808001F8: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
    // 0x808001FC: bne         $a0, $zero, L_80800208
    if (ctx->r4 != 0) {
        // 0x80800200: nop
    
            goto L_80800208;
    }
    // 0x80800200: nop

    // 0x80800204: break       7
    do_break(2155872772);
L_80800208:
    // 0x80800208: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080020C: bne         $a0, $at, L_80800220
    if (ctx->r4 != ctx->r1) {
        // 0x80800210: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80800220;
    }
    // 0x80800210: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800214: bne         $t7, $at, L_80800220
    if (ctx->r15 != ctx->r1) {
        // 0x80800218: nop
    
            goto L_80800220;
    }
    // 0x80800218: nop

    // 0x8080021C: break       6
    do_break(2155872796);
L_80800220:
    // 0x80800220: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80800224: bne         $a0, $zero, L_80800230
    if (ctx->r4 != 0) {
        // 0x80800228: nop
    
            goto L_80800230;
    }
    // 0x80800228: nop

    // 0x8080022C: break       7
    do_break(2155872812);
L_80800230:
    // 0x80800230: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800234: bne         $a0, $at, L_80800248
    if (ctx->r4 != ctx->r1) {
        // 0x80800238: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80800248;
    }
    // 0x80800238: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080023C: bne         $t4, $at, L_80800248
    if (ctx->r12 != ctx->r1) {
        // 0x80800240: nop
    
            goto L_80800248;
    }
    // 0x80800240: nop

    // 0x80800244: break       6
    do_break(2155872836);
L_80800248:
    // 0x80800248: lbu         $t8, 0x2($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X2);
    // 0x8080024C: mfhi        $t2
    ctx->r10 = hi;
    // 0x80800250: addu        $t3, $a3, $t2
    ctx->r11 = ADD32(ctx->r7, ctx->r10);
    // 0x80800254: xor         $t9, $t7, $t8
    ctx->r25 = ctx->r15 ^ ctx->r24;
    // 0x80800258: sb          $t9, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r25;
    // 0x8080025C: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x80800260: lbu         $t5, 0x3($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X3);
    // 0x80800264: bne         $a0, $zero, L_80800270
    if (ctx->r4 != 0) {
        // 0x80800268: nop
    
            goto L_80800270;
    }
    // 0x80800268: nop

    // 0x8080026C: break       7
    do_break(2155872876);
L_80800270:
    // 0x80800270: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800274: bne         $a0, $at, L_80800288
    if (ctx->r4 != ctx->r1) {
        // 0x80800278: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80800288;
    }
    // 0x80800278: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080027C: bne         $t1, $at, L_80800288
    if (ctx->r9 != ctx->r1) {
        // 0x80800280: nop
    
            goto L_80800288;
    }
    // 0x80800280: nop

    // 0x80800284: break       6
    do_break(2155872900);
L_80800288:
    // 0x80800288: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8080028C: xor         $t6, $t4, $t5
    ctx->r14 = ctx->r12 ^ ctx->r13;
    // 0x80800290: sb          $t6, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r14;
    // 0x80800294: bne         $v1, $a2, L_80800184
    if (ctx->r3 != ctx->r6) {
        // 0x80800298: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80800184;
    }
    // 0x80800298: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8080029C:
    // 0x8080029C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808002A4: jr          $ra
    // 0x808002A8: nop

    return;
    // 0x808002A8: nop

;}
RECOMP_FUNC void func_8080111C_chpotogoldgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080111C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801120: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80801124: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80801128: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080112C: addiu       $a0, $zero, 0x1F6
    ctx->r4 = ADD32(0, 0X1F6);
    // 0x80801130: jal         0x80088280
    // 0x80801134: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _gccubesearch_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80801134: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x80801138: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080113C: jal         0x80088C00
    // 0x80801140: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80801140: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80801144: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    // 0x80801148: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080114C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80801150: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80801154: jal         0x800D1000
    // 0x80801158: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_2;
    // 0x80801158: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x8080115C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801160: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801164: jal         0x80802124
    // 0x80801168: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_80802124_chpotogoldgame(rdram, ctx);
        goto after_3;
    // 0x80801168: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_3:
    // 0x8080116C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801170: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801174: jr          $ra
    // 0x80801178: nop

    return;
    // 0x80801178: nop

;}
RECOMP_FUNC void bsdronebubbled_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800070: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800074: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800078: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080007C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800080: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800084: jal         0x80084640
    // 0x80800088: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    _badata_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800088: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800090: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800094: jal         0x8008CB3C
    // 0x80800098: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80800098: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x8080009C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808000A0: lw          $t6, 0x54($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X54);
    // 0x808000A4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808000A8: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x808000AC: swc1        $f4, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->f4.u32l;
    // 0x808000B0: lw          $t7, 0x54($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X54);
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000BC: swc1        $f6, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f6.u32l;
    // 0x808000C0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808000C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808000C8: jal         0x8009FFD8
    // 0x808000CC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x808000CC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x808000D0: jal         0x8009D9D4
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D9D4(rdram, ctx);
        goto after_3;
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000E4: jr          $ra
    // 0x808000E8: nop

    return;
    // 0x808000E8: nop

;}
RECOMP_FUNC void ncfixposrot_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x8001ACCC
    // 0x8080000C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x8080000C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_0:
    // 0x80800010: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800014: jal         0x800EFD24
    // 0x80800018: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x80800018: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080001C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800020: jal         0x800EFD24
    // 0x80800024: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x80800024: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_2:
    // 0x80800028: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8080002C: sh          $zero, 0x18($v0)
    MEM_H(0X18, ctx->r2) = 0;
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800034: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800038: jr          $ra
    // 0x8080003C: nop

    return;
    // 0x8080003C: nop

;}
RECOMP_FUNC void _ncbaswim_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089320: syscall     773
    recomp_syscall_handler(rdram, ctx, 0x80089320);
    return;
    // 0x80089324: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800E1720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1720: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x800E1724: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800E1728: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800E172C: addiu       $t7, $t7, -0x3070
    ctx->r15 = ADD32(ctx->r15, -0X3070);
    // 0x800E1730: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800E1734: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800E1738: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800E173C: sb          $t8, 0x74($v0)
    MEM_B(0X74, ctx->r2) = ctx->r24;
    // 0x800E1740: jr          $ra
    // 0x800E1744: sb          $zero, 0x76($v0)
    MEM_B(0X76, ctx->r2) = 0;
    return;
    // 0x800E1744: sb          $zero, 0x76($v0)
    MEM_B(0X76, ctx->r2) = 0;
;}
RECOMP_FUNC void bskazstill_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800380: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800388: jal         0x800832E0
    // 0x8080038C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080038C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800390: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800394: jal         0x8008E39C
    // 0x80800398: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    func_8008E39C(rdram, ctx);
        goto after_1;
    // 0x80800398: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    after_1:
    // 0x8080039C: beq         $v0, $zero, L_808003B4
    if (ctx->r2 == 0) {
        // 0x808003A0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808003B4;
    }
    // 0x808003A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808003A4: jal         0x80800030
    // 0x808003A8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800030_bskazstill(rdram, ctx);
        goto after_2;
    // 0x808003A8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x808003AC: b           L_808003C0
    // 0x808003B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003C0;
    // 0x808003B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003B4:
    // 0x808003B4: jal         0x80800030
    // 0x808003B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800030_bskazstill(rdram, ctx);
        goto after_3;
    // 0x808003B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808003BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003C0:
    // 0x808003C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003C4: jr          $ra
    // 0x808003C8: nop

    return;
    // 0x808003C8: nop

;}
