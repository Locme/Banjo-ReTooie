#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808009E0_chboggyfatboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808009E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808009EC: jal         0x80800018
    // 0x808009F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800018_chboggyfatboy(rdram, ctx);
        goto after_0;
    // 0x808009F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808009F4: bne         $v0, $zero, L_80800A0C
    if (ctx->r2 != 0) {
        // 0x808009F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A0C;
    }
    // 0x808009F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009FC: jal         0x800FFAB0
    // 0x80800A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800A04: b           L_80800AE0
    // 0x80800A08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800AE0;
    // 0x80800A08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A0C:
    // 0x80800A0C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800A10: addiu       $a2, $a2, 0x6870
    ctx->r6 = ADD32(ctx->r6, 0X6870);
    // 0x80800A14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A18: jal         0x8008A560
    // 0x80800A1C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    _subaddietaxi_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x80800A1C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_2:
    // 0x80800A20: beql        $v0, $zero, L_80800A48
    if (ctx->r2 == 0) {
        // 0x80800A24: lw          $t6, 0x78($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X78);
            goto L_80800A48;
    }
    goto skip_0;
    // 0x80800A24: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    skip_0:
    // 0x80800A28: jal         0x80800078
    // 0x80800A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800078_chboggyfatboy(rdram, ctx);
        goto after_3;
    // 0x80800A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A34: jal         0x80102FDC
    // 0x80800A38: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80102FDC(rdram, ctx);
        goto after_4;
    // 0x80800A38: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_4:
    // 0x80800A3C: b           L_80800A7C
    // 0x80800A40: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
        goto L_80800A7C;
    // 0x80800A40: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    // 0x80800A44: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
L_80800A48:
    // 0x80800A48: sll         $t8, $t6, 26
    ctx->r24 = S32(ctx->r14 << 26);
    // 0x80800A4C: bgez        $t8, L_80800A64
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800A50: nop
    
            goto L_80800A64;
    }
    // 0x80800A50: nop

    // 0x80800A54: jal         0x800FFAB0
    // 0x80800A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x80800A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800A5C: b           L_80800AE0
    // 0x80800A60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800AE0;
    // 0x80800A60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A64:
    // 0x80800A64: jal         0x80800078
    // 0x80800A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800078_chboggyfatboy(rdram, ctx);
        goto after_6;
    // 0x80800A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A70: jal         0x80102FDC
    // 0x80800A74: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80102FDC(rdram, ctx);
        goto after_7;
    // 0x80800A74: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_7:
    // 0x80800A78: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
L_80800A7C:
    // 0x80800A7C: jal         0x80089C30
    // 0x80800A80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80800A80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800A84: beql        $v0, $zero, L_80800A9C
    if (ctx->r2 == 0) {
        // 0x80800A88: sw          $zero, 0x3C($s0)
        MEM_W(0X3C, ctx->r16) = 0;
            goto L_80800A9C;
    }
    goto skip_1;
    // 0x80800A88: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    skip_1:
    // 0x80800A8C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80800A90: b           L_80800A9C
    // 0x80800A94: sw          $t9, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r25;
        goto L_80800A9C;
    // 0x80800A94: sw          $t9, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r25;
    // 0x80800A98: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
L_80800A9C:
    // 0x80800A9C: jal         0x80800FE0
    // 0x80800AA0: addiu       $a0, $zero, 0x3CA
    ctx->r4 = ADD32(0, 0X3CA);
    func_80800FE0_chboggyfatboy(rdram, ctx);
        goto after_9;
    // 0x80800AA0: addiu       $a0, $zero, 0x3CA
    ctx->r4 = ADD32(0, 0X3CA);
    after_9:
    // 0x80800AA4: beql        $v0, $zero, L_80800AC8
    if (ctx->r2 == 0) {
        // 0x80800AA8: lui         $a1, 0x1000
        ctx->r5 = S32(0X1000 << 16);
            goto L_80800AC8;
    }
    goto skip_2;
    // 0x80800AA8: lui         $a1, 0x1000
    ctx->r5 = S32(0X1000 << 16);
    skip_2:
    // 0x80800AAC: jal         0x800DA298
    // 0x80800AB0: addiu       $a0, $zero, 0xBB
    ctx->r4 = ADD32(0, 0XBB);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x80800AB0: addiu       $a0, $zero, 0xBB
    ctx->r4 = ADD32(0, 0XBB);
    after_10:
    // 0x80800AB4: bnel        $v0, $zero, L_80800AC8
    if (ctx->r2 != 0) {
        // 0x80800AB8: lui         $a1, 0x1000
        ctx->r5 = S32(0X1000 << 16);
            goto L_80800AC8;
    }
    goto skip_3;
    // 0x80800AB8: lui         $a1, 0x1000
    ctx->r5 = S32(0X1000 << 16);
    skip_3:
    // 0x80800ABC: jal         0x800DA524
    // 0x80800AC0: addiu       $a0, $zero, 0xBA
    ctx->r4 = ADD32(0, 0XBA);
    func_800DA524(rdram, ctx);
        goto after_11;
    // 0x80800AC0: addiu       $a0, $zero, 0xBA
    ctx->r4 = ADD32(0, 0XBA);
    after_11:
    // 0x80800AC4: lui         $a1, 0x1000
    ctx->r5 = S32(0X1000 << 16);
L_80800AC8:
    // 0x80800AC8: ori         $a1, $a1, 0x2000
    ctx->r5 = ctx->r5 | 0X2000;
    // 0x80800ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800AD4: jal         0x801088A8
    // 0x80800AD8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_801088A8(rdram, ctx);
        goto after_12;
    // 0x80800AD8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
    // 0x80800ADC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800AE0:
    // 0x80800AE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800AE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800AE8: jr          $ra
    // 0x80800AEC: nop

    return;
    // 0x80800AEC: nop

;}
RECOMP_FUNC void func_80800F98_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FA0: jal         0x808009B0
    // 0x80800FA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808009B0_bssub(rdram, ctx);
        goto after_0;
    // 0x80800FA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800FA8: jal         0x80082FE0
    // 0x80800FAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800FAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800FB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800FB8: jr          $ra
    // 0x80800FBC: nop

    return;
    // 0x80800FBC: nop

;}
RECOMP_FUNC void func_800F5410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5410: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5414: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5418: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F541C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5420: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5424: jal         0x800A3274
    // 0x800F5428: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800A3274(rdram, ctx);
        goto after_0;
    // 0x800F5428: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F542C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5430: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5434: jr          $ra
    // 0x800F5438: nop

    return;
    // 0x800F5438: nop

;}
RECOMP_FUNC void _bapackctrl_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084778: syscall     119
    recomp_syscall_handler(rdram, ctx, 0x80084778);
    return;
    // 0x8008477C: xori        $t0, $zero, 0xC
    ctx->r8 = 0 ^ 0XC;
;}
RECOMP_FUNC void func_800B5C10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5C10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B5C14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B5C18: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800B5C1C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800B5C20: jal         0x800D3524
    // 0x800B5C24: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800D3524(rdram, ctx);
        goto after_0;
    // 0x800B5C24: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800B5C28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B5C2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800B5C30: jal         0x800B0D6C
    // 0x800B5C34: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800B0D6C(rdram, ctx);
        goto after_1;
    // 0x800B5C34: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800B5C38: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800B5C3C: jal         0x800B0D58
    // 0x800B5C40: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800B0D58(rdram, ctx);
        goto after_2;
    // 0x800B5C40: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x800B5C44: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800B5C48: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x800B5C4C: jal         0x800B0D60
    // 0x800B5C50: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800B0D60(rdram, ctx);
        goto after_3;
    // 0x800B5C50: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x800B5C54: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800B5C58: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800B5C5C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x800B5C60: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800B5C64: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800B5C68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B5C6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B5C70: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B5C74: jr          $ra
    // 0x800B5C78: nop

    return;
    // 0x800B5C78: nop

;}
RECOMP_FUNC void func_800C6DA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6DA0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C6DA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C6DA8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C6DAC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800C6DB0: jal         0x800C6E18
    // 0x800C6DB4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_800C6E18(rdram, ctx);
        goto after_0;
    // 0x800C6DB4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_0:
    // 0x800C6DB8: bne         $v0, $zero, L_800C6E08
    if (ctx->r2 != 0) {
        // 0x800C6DBC: lw          $v1, 0x28($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X28);
            goto L_800C6E08;
    }
    // 0x800C6DBC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x800C6DC0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800C6DC4: addiu       $t7, $t6, -0x3C
    ctx->r15 = ADD32(ctx->r14, -0X3C);
    // 0x800C6DC8: sltiu       $at, $t7, 0xA
    ctx->r1 = ctx->r15 < 0XA ? 1 : 0;
    // 0x800C6DCC: beq         $at, $zero, L_800C6DEC
    if (ctx->r1 == 0) {
        // 0x800C6DD0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800C6DEC;
    }
    // 0x800C6DD0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C6DD4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C6DD8: addu        $at, $at, $t7
    gpr jr_addend_800C6DE0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C6DDC: lw          $t7, 0x58B0($at)
    ctx->r15 = ADD32(ctx->r1, 0X58B0);
    // 0x800C6DE0: jr          $t7
    // 0x800C6DE4: nop

    switch (jr_addend_800C6DE0 >> 2) {
        case 0: goto L_800C6DEC; break;
        case 1: goto L_800C6DEC; break;
        case 2: goto L_800C6DEC; break;
        case 3: goto L_800C6DEC; break;
        case 4: goto L_800C6DEC; break;
        case 5: goto L_800C6DEC; break;
        case 6: goto L_800C6DE8; break;
        case 7: goto L_800C6DEC; break;
        case 8: goto L_800C6DEC; break;
        case 9: goto L_800C6DEC; break;
        default: switch_error(__func__, 0x800C6DE0, 0x801258B0);
    }
    // 0x800C6DE4: nop

L_800C6DE8:
    // 0x800C6DE8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800C6DEC:
    // 0x800C6DEC: beql        $v1, $zero, L_800C6E00
    if (ctx->r3 == 0) {
        // 0x800C6DF0: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_800C6E00;
    }
    goto skip_0;
    // 0x800C6DF0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x800C6DF4: jal         0x800FC6B0
    // 0x800C6DF8: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC6B0(rdram, ctx);
        goto after_1;
    // 0x800C6DF8: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_1:
    // 0x800C6DFC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_800C6E00:
    // 0x800C6E00: jal         0x800C70D0
    // 0x800C6E04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70D0(rdram, ctx);
        goto after_2;
    // 0x800C6E04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_800C6E08:
    // 0x800C6E08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C6E0C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C6E10: jr          $ra
    // 0x800C6E14: nop

    return;
    // 0x800C6E14: nop

;}
RECOMP_FUNC void func_8001E578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E578: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E57C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E580: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001E584: jal         0x8001E7B4
    // 0x8001E588: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001E7B4(rdram, ctx);
        goto after_0;
    // 0x8001E588: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8001E58C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001E590: jal         0x8001DDA4
    // 0x8001E594: lw          $a0, -0x16A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X16A8);
    func_8001DDA4(rdram, ctx);
        goto after_1;
    // 0x8001E594: lw          $a0, -0x16A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X16A8);
    after_1:
    // 0x8001E598: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001E59C: jal         0x8002EC20
    // 0x8001E5A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    osSetThreadPri_recomp(rdram, ctx);
        goto after_2;
    // 0x8001E5A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8001E5A4: jal         0x8001DDA4
    // 0x8001E5A8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_8001DDA4(rdram, ctx);
        goto after_3;
    // 0x8001E5A8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_3:
    // 0x8001E5AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001E5B0: jal         0x8002EC20
    // 0x8001E5B4: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
    osSetThreadPri_recomp(rdram, ctx);
        goto after_4;
    // 0x8001E5B4: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
    after_4:
    // 0x8001E5B8: jal         0x8001E4B0
    // 0x8001E5BC: nop

    func_8001E4B0(rdram, ctx);
        goto after_5;
    // 0x8001E5BC: nop

    after_5:
    // 0x8001E5C0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001E5C4: jal         0x8008A980
    // 0x8001E5C8: lw          $a0, -0x16B4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X16B4);
    _gzpublic_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x8001E5C8: lw          $a0, -0x16B4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X16B4);
    after_6:
    // 0x8001E5CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E5D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E5D4: jr          $ra
    // 0x8001E5D8: nop

    return;
    // 0x8001E5D8: nop

;}
RECOMP_FUNC void func_80103040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103040: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80103044: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80103048: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010304C: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80103050: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80103054: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80103058: bgezl       $t8, L_80103100
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8010305C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80103100;
    }
    goto skip_0;
    // 0x8010305C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80103060: lw          $t9, 0x7C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X7C);
    // 0x80103064: sll         $t1, $t9, 19
    ctx->r9 = S32(ctx->r25 << 19);
    // 0x80103068: bgezl       $t1, L_801030A4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8010306C: lw          $a0, 0x40($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X40);
            goto L_801030A4;
    }
    goto skip_1;
    // 0x8010306C: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    skip_1:
    // 0x80103070: jal         0x80100368
    // 0x80103074: nop

    func_80100368(rdram, ctx);
        goto after_0;
    // 0x80103074: nop

    after_0:
    // 0x80103078: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8010307C: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80103080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80103084: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80103088: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8010308C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80103090: jal         0x80085770
    // 0x80103094: nop

    _chbadshad_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80103094: nop

    after_1:
    // 0x80103098: b           L_80103100
    // 0x8010309C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80103100;
    // 0x8010309C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801030A0: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
L_801030A4:
    // 0x801030A4: beql        $a0, $zero, L_80103100
    if (ctx->r4 == 0) {
        // 0x801030A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80103100;
    }
    goto skip_2;
    // 0x801030A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x801030AC: jal         0x80106790
    // 0x801030B0: nop

    func_80106790(rdram, ctx);
        goto after_2;
    // 0x801030B0: nop

    after_2:
    // 0x801030B4: lw          $t2, 0x7C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X7C);
    // 0x801030B8: sll         $t4, $t2, 19
    ctx->r12 = S32(ctx->r10 << 19);
    // 0x801030BC: bltz        $t4, L_801030D4
    if (SIGNED(ctx->r12) < 0) {
        // 0x801030C0: nop
    
            goto L_801030D4;
    }
    // 0x801030C0: nop

    // 0x801030C4: lhu         $t5, 0x64($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X64);
    // 0x801030C8: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x801030CC: bnel        $t6, $zero, L_80103100
    if (ctx->r14 != 0) {
        // 0x801030D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80103100;
    }
    goto skip_3;
    // 0x801030D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
L_801030D4:
    // 0x801030D4: jal         0x80100368
    // 0x801030D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80100368(rdram, ctx);
        goto after_3;
    // 0x801030D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801030DC: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x801030E0: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x801030E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801030E8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x801030EC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801030F0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x801030F4: jal         0x80085770
    // 0x801030F8: nop

    _chbadshad_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x801030F8: nop

    after_4:
    // 0x801030FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80103100:
    // 0x80103100: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80103104: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80103108: jr          $ra
    // 0x8010310C: nop

    return;
    // 0x8010310C: nop

;}
RECOMP_FUNC void func_80800688_gcboundDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800688: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080068C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800690: jal         0x80800630
    // 0x80800694: nop

    func_80800630_gcboundDll(rdram, ctx);
        goto after_0;
    // 0x80800694: nop

    after_0:
    // 0x80800698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080069C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006A0: jr          $ra
    // 0x808006A4: nop

    return;
    // 0x808006A4: nop

;}
RECOMP_FUNC void _bssnowball_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083A50: syscall     87
    recomp_syscall_handler(rdram, ctx, 0x80083A50);
    return;
    // 0x80083A54: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800903D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800903D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800903D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800903D8: lui         $a2, 0xC4BB
    ctx->r6 = S32(0XC4BB << 16);
    // 0x800903DC: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x800903E0: jal         0x800903F8
    // 0x800903E4: lui         $a1, 0x4452
    ctx->r5 = S32(0X4452 << 16);
    func_800903F8(rdram, ctx);
        goto after_0;
    // 0x800903E4: lui         $a1, 0x4452
    ctx->r5 = S32(0X4452 << 16);
    after_0:
    // 0x800903E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800903EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800903F0: jr          $ra
    // 0x800903F4: nop

    return;
    // 0x800903F4: nop

;}
RECOMP_FUNC void func_800F929C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F929C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F92A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F92A4: jal         0x800F8B88
    // 0x800F92A8: nop

    func_800F8B88(rdram, ctx);
        goto after_0;
    // 0x800F92A8: nop

    after_0:
    // 0x800F92AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800F92B0: bne         $v0, $at, L_800F92C0
    if (ctx->r2 != ctx->r1) {
        // 0x800F92B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F92C0;
    }
    // 0x800F92B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F92B8: b           L_800F92C4
    // 0x800F92BC: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_800F92C4;
    // 0x800F92BC: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_800F92C0:
    // 0x800F92C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F92C4:
    // 0x800F92C4: jr          $ra
    // 0x800F92C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F92C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800D87B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D87B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D87B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D87B8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D87BC: jal         0x800884E8
    // 0x800D87C0: addiu       $a0, $a0, -0x4190
    ctx->r4 = ADD32(ctx->r4, -0X4190);
    _glsplineDll_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x800D87C0: addiu       $a0, $a0, -0x4190
    ctx->r4 = ADD32(ctx->r4, -0X4190);
    after_0:
    // 0x800D87C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D87C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D87CC: jr          $ra
    // 0x800D87D0: nop

    return;
    // 0x800D87D0: nop

;}
RECOMP_FUNC void func_8008DE44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DE44: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8008DE48: jr          $ra
    // 0x8008DE4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8008DE4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void bstrexsmall_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080195C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801960: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(416, 0X1BA8) << 16);
    // 0x80801964: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801968: jr          $ra
    // 0x8080196C: lw          $v0, 0x1BA8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1BA8));
    return;
    // 0x8080196C: lw          $v0, 0x1BA8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1BA8));
;}
RECOMP_FUNC void func_80800064_chboggyfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800068: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x8080006C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800070: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800074: beq         $a1, $at, L_808000AC
    if (ctx->r5 == ctx->r1) {
        // 0x80800078: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_808000AC;
    }
    // 0x80800078: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8080007C: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80800080: beq         $a1, $at, L_8080009C
    if (ctx->r5 == ctx->r1) {
        // 0x80800084: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8080009C;
    }
    // 0x80800084: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800088: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080008C: beq         $a1, $at, L_80800128
    if (ctx->r5 == ctx->r1) {
        // 0x80800090: addiu       $a0, $zero, 0x438
        ctx->r4 = ADD32(0, 0X438);
            goto L_80800128;
    }
    // 0x80800090: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    // 0x80800094: b           L_8080017C
    // 0x80800098: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080017C;
    // 0x80800098: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080009C:
    // 0x8080009C: jal         0x80800000
    // 0x808000A0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80800000_chboggyfish(rdram, ctx);
        goto after_0;
    // 0x808000A0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x808000A4: b           L_8080017C
    // 0x808000A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080017C;
    // 0x808000A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000AC:
    // 0x808000AC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808000B0: jal         0x801015D0
    // 0x808000B4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_801015D0(rdram, ctx);
        goto after_1;
    // 0x808000B4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x808000B8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x808000BC: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x808000C0: jal         0x800D731C
    // 0x808000C4: lhu         $a0, 0x14($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X14);
    func_800D731C(rdram, ctx);
        goto after_2;
    // 0x808000C4: lhu         $a0, 0x14($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X14);
    after_2:
    // 0x808000C8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x808000CC: beq         $v0, $zero, L_80800178
    if (ctx->r2 == 0) {
        // 0x808000D0: andi        $a0, $v0, 0xFF
        ctx->r4 = ctx->r2 & 0XFF;
            goto L_80800178;
    }
    // 0x808000D0: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x808000D4: lwc1        $f4, 0x28($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X28);
    // 0x808000D8: sb          $a0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r4;
    // 0x808000DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000E0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808000E4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808000E8: jal         0x800DBE60
    // 0x808000EC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800DBE60(rdram, ctx);
        goto after_3;
    // 0x808000EC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_3:
    // 0x808000F0: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    // 0x808000F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000F8: jal         0x800DBE60
    // 0x808000FC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    func_800DBE60(rdram, ctx);
        goto after_4;
    // 0x808000FC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80800100: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    // 0x80800104: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800108: jal         0x800DBE60
    // 0x8080010C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    func_800DBE60(rdram, ctx);
        goto after_5;
    // 0x8080010C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x80800110: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    // 0x80800114: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800118: jal         0x800DBE60
    // 0x8080011C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    func_800DBE60(rdram, ctx);
        goto after_6;
    // 0x8080011C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_6:
    // 0x80800120: b           L_8080017C
    // 0x80800124: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080017C;
    // 0x80800124: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800128:
    // 0x80800128: jal         0x800DA298
    // 0x8080012C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x8080012C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_7:
    // 0x80800130: beq         $v0, $zero, L_80800158
    if (ctx->r2 == 0) {
        // 0x80800134: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_80800158;
    }
    // 0x80800134: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800138: jal         0x80088848
    // 0x8080013C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_8;
    // 0x8080013C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_8:
    // 0x80800140: bne         $v0, $zero, L_80800158
    if (ctx->r2 != 0) {
        // 0x80800144: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_80800158;
    }
    // 0x80800144: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800148: jal         0x800FFAB0
    // 0x8080014C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_9;
    // 0x8080014C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_9:
    // 0x80800150: b           L_8080017C
    // 0x80800154: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080017C;
    // 0x80800154: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800158:
    // 0x80800158: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8080015C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800160: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800164: swc1        $f18, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f18.u32l;
    // 0x80800168: b           L_80800178
    // 0x8080016C: swc1        $f16, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f16.u32l;
        goto L_80800178;
    // 0x8080016C: swc1        $f16, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f16.u32l;
    // 0x80800170: b           L_8080017C
    // 0x80800174: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080017C;
    // 0x80800174: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800178:
    // 0x80800178: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080017C:
    // 0x8080017C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800180: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800184: jr          $ra
    // 0x80800188: nop

    return;
    // 0x80800188: nop

;}
RECOMP_FUNC void func_80103930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103930: jr          $ra
    // 0x80103934: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80103934: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _suegg_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A3C0: syscall     841
    recomp_syscall_handler(rdram, ctx, 0x8008A3C0);
    return;
    // 0x8008A3C4: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void subaddiejoy_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800358: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080035C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800360: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800364: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800368: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8080036C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800370: lw          $a0, 0x64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X64);
    // 0x80800374: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800378: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x8080037C: jal         0x80016068
    // 0x80800380: srl         $a0, $t7, 30
    ctx->r4 = S32(U32(ctx->r15) >> 30);
    func_80016068(rdram, ctx);
        goto after_0;
    // 0x80800380: srl         $a0, $t7, 30
    ctx->r4 = S32(U32(ctx->r15) >> 30);
    after_0:
    // 0x80800384: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800388: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8080038C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80800390: nop

    // 0x80800394: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80800398: jal         0x8002DCA0
    // 0x8080039C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8080039C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x808003A0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808003A4: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x808003A8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808003AC: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x808003B0: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808003B4: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x808003B8: bc1t        L_80800420
    if (c1cs) {
        // 0x808003BC: nop
    
            goto L_80800420;
    }
    // 0x808003BC: nop

    // 0x808003C0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808003C4: jal         0x80013B70
    // 0x808003C8: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    func_80013B70(rdram, ctx);
        goto after_2;
    // 0x808003C8: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x808003CC: jal         0x800E3A80
    // 0x808003D0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_800E3A80(rdram, ctx);
        goto after_3;
    // 0x808003D0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x808003D4: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808003D8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808003DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808003E0: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x808003E4: jal         0x800136E4
    // 0x808003E8: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    func_800136E4(rdram, ctx);
        goto after_4;
    // 0x808003E8: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_4:
    // 0x808003EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003F0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808003F4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x808003F8: jal         0x800F13F0
    // 0x808003FC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_800F13F0(rdram, ctx);
        goto after_5;
    // 0x808003FC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_5:
    // 0x80800400: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80800404: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800408: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8080040C: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80800410: beq         $t0, $zero, L_80800434
    if (ctx->r8 == 0) {
        // 0x80800414: lw          $t1, 0x3C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X3C);
            goto L_80800434;
    }
    // 0x80800414: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80800418: b           L_80800434
    // 0x8080041C: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
        goto L_80800434;
    // 0x8080041C: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
L_80800420:
    // 0x80800420: beq         $t3, $zero, L_80800434
    if (ctx->r11 == 0) {
        // 0x80800424: lw          $t4, 0x38($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X38);
            goto L_80800434;
    }
    // 0x80800424: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80800428: lwc1        $f6, 0x48($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X48);
    // 0x8080042C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80800430: swc1        $f6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f6.u32l;
L_80800434:
    // 0x80800434: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800438: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x8080043C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800440: jr          $ra
    // 0x80800444: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800444: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _subaddierouteDll_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089FA0: syscall     818
    recomp_syscall_handler(rdram, ctx, 0x80089FA0);
    return;
    // 0x80089FA4: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_808019A4_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808019A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808019AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808019B0: jal         0x800A0CF4
    // 0x808019B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_0;
    // 0x808019B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808019B8: jal         0x80084C40
    // 0x808019BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bafly_entrypoint_15(rdram, ctx);
        goto after_1;
    // 0x808019BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808019C0: jal         0x80800188
    // 0x808019C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800188_bsbfly(rdram, ctx);
        goto after_2;
    // 0x808019C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808019C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808019CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808019D0: jr          $ra
    // 0x808019D4: nop

    return;
    // 0x808019D4: nop

;}
RECOMP_FUNC void func_800DF47C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF47C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DF480: addiu       $v0, $v0, -0x3658
    ctx->r2 = ADD32(ctx->r2, -0X3658);
    // 0x800DF484: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800DF488: jr          $ra
    // 0x800DF48C: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    return;
    // 0x800DF48C: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void func_808000B4_bscrouch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(152, 0X970) << 16);
    // 0x808000B8: lwc1        $f4, 0x970($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(152, 0X970));
    // 0x808000BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000C4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808000C8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808000CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808000D0: lui         $a2, 0x4334
    ctx->r6 = S32(0X4334 << 16);
    // 0x808000D4: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x808000D8: jal         0x800F10B4
    // 0x808000DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x808000DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x808000E0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000E4: jal         0x8008B1BC
    // 0x808000E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_setDuration(rdram, ctx);
        goto after_1;
    // 0x808000E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808000EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000F4: jr          $ra
    // 0x808000F8: nop

    return;
    // 0x808000F8: nop

;}
RECOMP_FUNC void _bsbfly_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082998: syscall     22
    recomp_syscall_handler(rdram, ctx, 0x80082998);
    return;
    // 0x8008299C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void _chdinofamilyfx_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087738: syscall     615
    recomp_syscall_handler(rdram, ctx, 0x80087738);
    return;
    // 0x8008773C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bawobble_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B0: lw          $t7, 0x154($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X154);
    // 0x808001B4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808001B8: jr          $ra
    // 0x808001BC: sb          $t6, 0x1D($t7)
    MEM_B(0X1D, ctx->r15) = ctx->r14;
    return;
    // 0x808001BC: sb          $t6, 0x1D($t7)
    MEM_B(0X1D, ctx->r15) = ctx->r14;
;}
RECOMP_FUNC void _gldbstring_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088718: syscall     701
    recomp_syscall_handler(rdram, ctx, 0x80088718);
    return;
    // 0x8008871C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080008C_chmumboskullfakearchpanellava(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080008C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800090: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800094: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800098: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080009C: bne         $a1, $at, L_80800104
    if (ctx->r5 != ctx->r1) {
        // 0x808000A0: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80800104;
    }
    // 0x808000A0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808000A4: addiu       $s0, $a0, 0x4
    ctx->r16 = ADD32(ctx->r4, 0X4);
    // 0x808000A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808000AC: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x808000B0: jal         0x80086670
    // 0x808000B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808000B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000B8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808000BC: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1960, 0X160) << 16);
    // 0x808000C0: addiu       $t7, $t7, 0x160
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1960, 0X160));
    // 0x808000C4: lw          $a3, 0x38($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X38);
    // 0x808000C8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808000CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808000D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808000D4: jal         0x800BABB8
    // 0x808000D8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x808000D8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x808000DC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1960, 0X1CC) << 16);
    // 0x808000E0: addiu       $a1, $a1, 0x1CC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1960, 0X1CC));
    // 0x808000E4: jal         0x800C4AF0
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C4AF0(rdram, ctx);
        goto after_2;
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000EC: jal         0x80800000
    // 0x808000F0: nop

    func_80800000_chmumboskullfakearchpanellava(rdram, ctx);
        goto after_3;
    // 0x808000F0: nop

    after_3:
    // 0x808000F4: jal         0x800DA544
    // 0x808000F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x808000F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x808000FC: b           L_8080010C
    // 0x80800100: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080010C;
    // 0x80800100: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800104:
    // 0x80800104: b           L_8080010C
    // 0x80800108: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080010C;
    // 0x80800108: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080010C:
    // 0x8080010C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800110: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800114: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800118: jr          $ra
    // 0x8080011C: nop

    return;
    // 0x8080011C: nop

;}
RECOMP_FUNC void susubgame_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800650: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800654: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800658: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8080065C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800660: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800664: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80800668: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080066C: jal         0x800DA9E4
    // 0x80800670: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800DA9E4(rdram, ctx);
        goto after_0;
    // 0x80800670: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x80800674: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800678: jal         0x800F54E4
    // 0x8080067C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x8080067C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    after_1:
    // 0x80800680: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800684: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800688: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8080068C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x80800690: jal         0x8008A0C0
    // 0x80800694: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _subaddiemarker_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800694: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80800698: bne         $v0, $zero, L_808006A8
    if (ctx->r2 != 0) {
        // 0x8080069C: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_808006A8;
    }
    // 0x8080069C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x808006A0: b           L_80800748
    // 0x808006A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800748;
    // 0x808006A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006A8:
    // 0x808006A8: beq         $t7, $zero, L_808006FC
    if (ctx->r15 == 0) {
        // 0x808006AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006FC;
    }
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B0: jal         0x800F608C
    // 0x808006B4: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_800F608C(rdram, ctx);
        goto after_3;
    // 0x808006B4: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_3:
    // 0x808006B8: jal         0x800F497C
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F497C(rdram, ctx);
        goto after_4;
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808006C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C4: jal         0x800F49A8
    // 0x808006C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F49A8(rdram, ctx);
        goto after_5;
    // 0x808006C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808006CC: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x808006D0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x808006D4: addiu       $a1, $a1, -0x2A24
    ctx->r5 = ADD32(ctx->r5, -0X2A24);
    // 0x808006D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006DC: jal         0x800F49D4
    // 0x808006E0: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    func_800F49D4(rdram, ctx);
        goto after_6;
    // 0x808006E0: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    after_6:
    // 0x808006E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x808006EC: jal         0x800F4A58
    // 0x808006F0: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    func_800F4A58(rdram, ctx);
        goto after_7;
    // 0x808006F0: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    after_7:
    // 0x808006F4: b           L_80800748
    // 0x808006F8: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
        goto L_80800748;
    // 0x808006F8: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
L_808006FC:
    // 0x808006FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800700: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800704: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80800708: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080070C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800710: jal         0x800EFA4C
    // 0x80800714: nop

    func_800EFA4C(rdram, ctx);
        goto after_8;
    // 0x80800714: nop

    after_8:
    // 0x80800718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080071C: jal         0x800F608C
    // 0x80800720: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_800F608C(rdram, ctx);
        goto after_9;
    // 0x80800720: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_9:
    // 0x80800724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800728: jal         0x800F8294
    // 0x8080072C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800F8294(rdram, ctx);
        goto after_10;
    // 0x8080072C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_10:
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800734: jal         0x800F832C
    // 0x80800738: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800F832C(rdram, ctx);
        goto after_11;
    // 0x80800738: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_11:
    // 0x8080073C: jal         0x800F497C
    // 0x80800740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F497C(rdram, ctx);
        goto after_12;
    // 0x80800740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800744: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
L_80800748:
    // 0x80800748: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080074C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800750: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800754: jr          $ra
    // 0x80800758: nop

    return;
    // 0x80800758: nop

;}
RECOMP_FUNC void glgamestore_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F0: jal         0x80800030
    // 0x808000F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80800030_glgamestore(rdram, ctx);
        goto after_0;
    // 0x808000F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808000F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800100: jal         0x8080006C
    // 0x80800104: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8080006C_glgamestore(rdram, ctx);
        goto after_1;
    // 0x80800104: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_1:
    // 0x80800108: bne         $v0, $zero, L_80800128
    if (ctx->r2 != 0) {
        // 0x8080010C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800128;
    }
    // 0x8080010C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800110: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800114: jal         0x800885B0
    // 0x80800118: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _glglobaldata_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800118: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8080011C: bne         $v0, $zero, L_80800128
    if (ctx->r2 != 0) {
        // 0x80800120: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800128;
    }
    // 0x80800120: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800124: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80800128:
    // 0x80800128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080012C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800130: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800134: jr          $ra
    // 0x80800138: nop

    return;
    // 0x80800138: nop

;}
RECOMP_FUNC void func_80800FB4_chlavahand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FB4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800FB8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800FBC: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80800FC0: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80800FC4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80800FC8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80800FCC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800FD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800FD4: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80800FD8: jal         0x800D674C
    // 0x80800FDC: lhu         $a0, 0x14($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X14);
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x80800FDC: lhu         $a0, 0x14($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X14);
    after_0:
    // 0x80800FE0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800FE4: jal         0x80106790
    // 0x80800FE8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80800FE8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_1:
    // 0x80800FEC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800FF0: jal         0x801015D0
    // 0x80800FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_2;
    // 0x80800FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800FF8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80800FFC: addiu       $at, $zero, 0x927
    ctx->r1 = ADD32(0, 0X927);
    // 0x80801000: lhu         $t8, 0x14($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X14);
    // 0x80801004: bnel        $t8, $at, L_80801138
    if (ctx->r24 != ctx->r1) {
        // 0x80801008: lwc1        $f4, 0x38($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
            goto L_80801138;
    }
    goto skip_0;
    // 0x80801008: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    skip_0:
    // 0x8080100C: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80801010: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801014: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80801018: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8080101C: lbu         $t9, 0x9B($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X9B);
    // 0x80801020: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801024: addiu       $a3, $zero, 0x2A
    ctx->r7 = ADD32(0, 0X2A);
    // 0x80801028: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8080102C: lhu         $t0, 0x7A($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X7A);
    // 0x80801030: srl         $t1, $t0, 14
    ctx->r9 = S32(U32(ctx->r8) >> 14);
    // 0x80801034: jal         0x808011BC
    // 0x80801038: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    func_808011BC_chlavahand(rdram, ctx);
        goto after_3;
    // 0x80801038: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_3:
    // 0x8080103C: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80801040: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801044: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80801048: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8080104C: lbu         $t2, 0x9B($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X9B);
    // 0x80801050: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801054: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x80801058: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8080105C: lhu         $t3, 0x7A($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X7A);
    // 0x80801060: srl         $t4, $t3, 14
    ctx->r12 = S32(U32(ctx->r11) >> 14);
    // 0x80801064: jal         0x808011BC
    // 0x80801068: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    func_808011BC_chlavahand(rdram, ctx);
        goto after_4;
    // 0x80801068: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_4:
    // 0x8080106C: lwc1        $f8, 0x38($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80801070: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801074: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80801078: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8080107C: lbu         $t5, 0x9B($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X9B);
    // 0x80801080: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801084: addiu       $a3, $zero, 0x2D
    ctx->r7 = ADD32(0, 0X2D);
    // 0x80801088: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8080108C: lhu         $t6, 0x7A($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X7A);
    // 0x80801090: srl         $t7, $t6, 14
    ctx->r15 = S32(U32(ctx->r14) >> 14);
    // 0x80801094: jal         0x808011BC
    // 0x80801098: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_808011BC_chlavahand(rdram, ctx);
        goto after_5;
    // 0x80801098: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_5:
    // 0x8080109C: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808010A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808010A4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808010A8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x808010AC: lbu         $t8, 0x9B($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X9B);
    // 0x808010B0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808010B4: addiu       $a3, $zero, 0x2F
    ctx->r7 = ADD32(0, 0X2F);
    // 0x808010B8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x808010BC: lhu         $t9, 0x7A($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X7A);
    // 0x808010C0: srl         $t0, $t9, 14
    ctx->r8 = S32(U32(ctx->r25) >> 14);
    // 0x808010C4: jal         0x808011BC
    // 0x808010C8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    func_808011BC_chlavahand(rdram, ctx);
        goto after_6;
    // 0x808010C8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_6:
    // 0x808010CC: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808010D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808010D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808010D8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x808010DC: lbu         $t1, 0x9B($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X9B);
    // 0x808010E0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808010E4: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x808010E8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x808010EC: lhu         $t2, 0x7A($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X7A);
    // 0x808010F0: srl         $t3, $t2, 14
    ctx->r11 = S32(U32(ctx->r10) >> 14);
    // 0x808010F4: jal         0x808011BC
    // 0x808010F8: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    func_808011BC_chlavahand(rdram, ctx);
        goto after_7;
    // 0x808010F8: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    after_7:
    // 0x808010FC: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80801100: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801104: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80801108: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8080110C: lbu         $t4, 0x9B($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X9B);
    // 0x80801110: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801114: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    // 0x80801118: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8080111C: lhu         $t5, 0x7A($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X7A);
    // 0x80801120: srl         $t6, $t5, 14
    ctx->r14 = S32(U32(ctx->r13) >> 14);
    // 0x80801124: jal         0x808011BC
    // 0x80801128: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_808011BC_chlavahand(rdram, ctx);
        goto after_8;
    // 0x80801128: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_8:
    // 0x8080112C: b           L_80801198
    // 0x80801130: lbu         $t4, 0x7E($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X7E);
        goto L_80801198;
    // 0x80801130: lbu         $t4, 0x7E($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X7E);
    // 0x80801134: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
L_80801138:
    // 0x80801138: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080113C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80801140: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80801144: lbu         $t7, 0x9B($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X9B);
    // 0x80801148: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8080114C: addiu       $a3, $zero, 0x33
    ctx->r7 = ADD32(0, 0X33);
    // 0x80801150: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801154: lhu         $t8, 0x7A($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X7A);
    // 0x80801158: srl         $t9, $t8, 14
    ctx->r25 = S32(U32(ctx->r24) >> 14);
    // 0x8080115C: jal         0x808011BC
    // 0x80801160: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    func_808011BC_chlavahand(rdram, ctx);
        goto after_9;
    // 0x80801160: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_9:
    // 0x80801164: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80801168: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080116C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80801170: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80801174: lbu         $t0, 0x9B($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X9B);
    // 0x80801178: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8080117C: addiu       $a3, $zero, 0x35
    ctx->r7 = ADD32(0, 0X35);
    // 0x80801180: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80801184: lhu         $t1, 0x7A($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X7A);
    // 0x80801188: srl         $t2, $t1, 14
    ctx->r10 = S32(U32(ctx->r9) >> 14);
    // 0x8080118C: jal         0x808011BC
    // 0x80801190: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    func_808011BC_chlavahand(rdram, ctx);
        goto after_10;
    // 0x80801190: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    after_10:
    // 0x80801194: lbu         $t4, 0x7E($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X7E);
L_80801198:
    // 0x80801198: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x8080119C: sb          $t5, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r13;
    // 0x808011A0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808011A4: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x808011A8: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x808011AC: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x808011B0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x808011B4: jr          $ra
    // 0x808011B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808011B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_808003F8_bscarry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808003FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800400: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800404: jal         0x80800208
    // 0x80800408: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800208_bscarry(rdram, ctx);
        goto after_0;
    // 0x80800408: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080040C: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x80800410: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800418: jal         0x8008CB3C
    // 0x8080041C: addiu       $a1, $zero, 0x72
    ctx->r5 = ADD32(0, 0X72);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x8080041C: addiu       $a1, $zero, 0x72
    ctx->r5 = ADD32(0, 0X72);
    after_1:
    // 0x80800420: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800424: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080042C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800430: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800434: jal         0x8009FFD8
    // 0x80800438: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800438: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800440: jal         0x8009B9B0
    // 0x80800444: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800444: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080044C: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800450: jal         0x8009BFE4
    // 0x80800454: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_4;
    // 0x80800454: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_4:
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080045C: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800460: jal         0x8009C554
    // 0x80800464: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_5;
    // 0x80800464: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_5:
    // 0x80800468: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080046C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800470: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800474: jr          $ra
    // 0x80800478: nop

    return;
    // 0x80800478: nop

;}
RECOMP_FUNC void _basudie_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085200: syscall     155
    recomp_syscall_handler(rdram, ctx, 0x80085200);
    return;
    // 0x80085204: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801974_chfantasyathlete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801974: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801978: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080197C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801980: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80801984: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2388, 0X3034) << 16);
    // 0x80801988: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080198C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801990: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80801994: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80801998: lhu         $t9, 0x3034($t9)
    ctx->r25 = MEM_HU(ctx->r25, (int16_t)RELOC_LO16(2388, 0X3034));
    // 0x8080199C: addiu       $t0, $t9, -0x3F9
    ctx->r8 = ADD32(ctx->r25, -0X3F9);
    // 0x808019A0: sltiu       $at, $t0, 0x8
    ctx->r1 = ctx->r8 < 0X8 ? 1 : 0;
    // 0x808019A4: beq         $at, $zero, L_8080271C
    if (ctx->r1 == 0) {
        // 0x808019A8: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_8080271C;
    }
    // 0x808019A8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x808019AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2F78) << 16);
    // 0x808019B0: addu        $at, $at, $t0
    gpr jr_addend_808019B8 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x808019B4: lw          $t0, 0x2F78($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2F78));
    // 0x808019B8: jr          $t0
    // 0x808019BC: nop

    switch (jr_addend_808019B8 >> 2) {
        case 0: goto L_808019C0; break;
        case 1: goto L_80801CBC; break;
        case 2: goto L_8080271C; break;
        case 3: goto L_808023F0; break;
        case 4: goto L_80801F7C; break;
        case 5: goto L_80802228; break;
        case 6: goto L_808025E4; break;
        case 7: goto L_80802640; break;
        default: switch_error(__func__, 0x808019B8, 0x80802F78);
    }
    // 0x808019BC: nop

L_808019C0:
    // 0x808019C0: lui         $a1, 0x3D75
    ctx->r5 = S32(0X3D75 << 16);
    // 0x808019C4: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    // 0x808019C8: jal         0x80101E14
    // 0x808019CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_0;
    // 0x808019CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808019D0: bne         $v0, $zero, L_808019FC
    if (ctx->r2 != 0) {
        // 0x808019D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808019FC;
    }
    // 0x808019D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019D8: lui         $a1, 0x3E85
    ctx->r5 = S32(0X3E85 << 16);
    // 0x808019DC: jal         0x80101E14
    // 0x808019E0: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    func_80101E14(rdram, ctx);
        goto after_1;
    // 0x808019E0: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    after_1:
    // 0x808019E4: bne         $v0, $zero, L_808019FC
    if (ctx->r2 != 0) {
        // 0x808019E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808019FC;
    }
    // 0x808019E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019EC: lui         $a1, 0x3EEB
    ctx->r5 = S32(0X3EEB << 16);
    // 0x808019F0: jal         0x80101E14
    // 0x808019F4: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    func_80101E14(rdram, ctx);
        goto after_2;
    // 0x808019F4: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    after_2:
    // 0x808019F8: beq         $v0, $zero, L_80801AC4
    if (ctx->r2 == 0) {
        // 0x808019FC: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2388, 0X2F98) << 16);
            goto L_80801AC4;
    }
L_808019FC:
    // 0x808019FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2F98) << 16);
    // 0x80801A00: lwc1        $f12, 0x2F98($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2F98));
    // 0x80801A04: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2F9C) << 16);
    // 0x80801A08: jal         0x800DC178
    // 0x80801A0C: lwc1        $f14, 0x2F9C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2F9C));
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80801A0C: lwc1        $f14, 0x2F9C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2F9C));
    after_3:
    // 0x80801A10: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2FA0) << 16);
    // 0x80801A14: lwc1        $f4, 0x2FA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FA0));
    // 0x80801A18: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801A1C: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80801A20: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801A24: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80801A28: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801A2C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801A30: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80801A34: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80801A38: nop

    // 0x80801A3C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80801A40: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80801A44: nop

    // 0x80801A48: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80801A4C: beql        $a0, $zero, L_80801A9C
    if (ctx->r4 == 0) {
        // 0x80801A50: mfc1        $a0, $f8
        ctx->r4 = (int32_t)ctx->f8.u32l;
            goto L_80801A9C;
    }
    goto skip_0;
    // 0x80801A50: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x80801A54: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801A58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801A5C: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80801A60: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80801A64: nop

    // 0x80801A68: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80801A6C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80801A70: nop

    // 0x80801A74: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80801A78: bne         $a0, $zero, L_80801A90
    if (ctx->r4 != 0) {
        // 0x80801A7C: nop
    
            goto L_80801A90;
    }
    // 0x80801A7C: nop

    // 0x80801A80: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80801A84: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801A88: b           L_80801AA8
    // 0x80801A8C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80801AA8;
    // 0x80801A8C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80801A90:
    // 0x80801A90: b           L_80801AA8
    // 0x80801A94: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80801AA8;
    // 0x80801A94: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80801A98: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
L_80801A9C:
    // 0x80801A9C: nop

    // 0x80801AA0: bltz        $a0, L_80801A90
    if (SIGNED(ctx->r4) < 0) {
        // 0x80801AA4: nop
    
            goto L_80801A90;
    }
    // 0x80801AA4: nop

L_80801AA8:
    // 0x80801AA8: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x80801AAC: lui         $at, 0x1B
    ctx->r1 = S32(0X1B << 16);
    // 0x80801AB0: ori         $at, $at, 0x5E23
    ctx->r1 = ctx->r1 | 0X5E23;
    // 0x80801AB4: sll         $t3, $t2, 21
    ctx->r11 = S32(ctx->r10 << 21);
    // 0x80801AB8: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80801ABC: jal         0x800C4140
    // 0x80801AC0: addu        $a0, $t3, $at
    ctx->r4 = ADD32(ctx->r11, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_4;
    // 0x80801AC0: addu        $a0, $t3, $at
    ctx->r4 = ADD32(ctx->r11, ctx->r1);
    after_4:
L_80801AC4:
    // 0x80801AC4: lui         $a1, 0x3E2E
    ctx->r5 = S32(0X3E2E << 16);
    // 0x80801AC8: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    // 0x80801ACC: jal         0x80101E14
    // 0x80801AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_5;
    // 0x80801AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801AD4: bne         $v0, $zero, L_80801B00
    if (ctx->r2 != 0) {
        // 0x80801AD8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801B00;
    }
    // 0x80801AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801ADC: lui         $a1, 0x3EBD
    ctx->r5 = S32(0X3EBD << 16);
    // 0x80801AE0: jal         0x80101E14
    // 0x80801AE4: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    func_80101E14(rdram, ctx);
        goto after_6;
    // 0x80801AE4: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    after_6:
    // 0x80801AE8: bne         $v0, $zero, L_80801B00
    if (ctx->r2 != 0) {
        // 0x80801AEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801B00;
    }
    // 0x80801AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AF0: lui         $a1, 0x3F11
    ctx->r5 = S32(0X3F11 << 16);
    // 0x80801AF4: jal         0x80101E14
    // 0x80801AF8: ori         $a1, $a1, 0xEB85
    ctx->r5 = ctx->r5 | 0XEB85;
    func_80101E14(rdram, ctx);
        goto after_7;
    // 0x80801AF8: ori         $a1, $a1, 0xEB85
    ctx->r5 = ctx->r5 | 0XEB85;
    after_7:
    // 0x80801AFC: beq         $v0, $zero, L_80801BD0
    if (ctx->r2 == 0) {
        // 0x80801B00: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2388, 0X2FA4) << 16);
            goto L_80801BD0;
    }
L_80801B00:
    // 0x80801B00: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2FA4) << 16);
    // 0x80801B04: lwc1        $f12, 0x2FA4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FA4));
    // 0x80801B08: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2FA8) << 16);
    // 0x80801B0C: addiu       $t4, $s0, 0x4
    ctx->r12 = ADD32(ctx->r16, 0X4);
    // 0x80801B10: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x80801B14: jal         0x800DC178
    // 0x80801B18: lwc1        $f14, 0x2FA8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FA8));
    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x80801B18: lwc1        $f14, 0x2FA8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FA8));
    after_8:
    // 0x80801B1C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2FAC) << 16);
    // 0x80801B20: lwc1        $f10, 0x2FAC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FAC));
    // 0x80801B24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801B28: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80801B2C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80801B30: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80801B34: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801B38: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80801B3C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80801B40: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80801B44: nop

    // 0x80801B48: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80801B4C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80801B50: nop

    // 0x80801B54: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80801B58: beql        $a0, $zero, L_80801BA8
    if (ctx->r4 == 0) {
        // 0x80801B5C: mfc1        $a0, $f18
        ctx->r4 = (int32_t)ctx->f18.u32l;
            goto L_80801BA8;
    }
    goto skip_1;
    // 0x80801B5C: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    skip_1:
    // 0x80801B60: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801B64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801B68: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80801B6C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80801B70: nop

    // 0x80801B74: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80801B78: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80801B7C: nop

    // 0x80801B80: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80801B84: bne         $a0, $zero, L_80801B9C
    if (ctx->r4 != 0) {
        // 0x80801B88: nop
    
            goto L_80801B9C;
    }
    // 0x80801B88: nop

    // 0x80801B8C: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80801B90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801B94: b           L_80801BB4
    // 0x80801B98: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80801BB4;
    // 0x80801B98: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80801B9C:
    // 0x80801B9C: b           L_80801BB4
    // 0x80801BA0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80801BB4;
    // 0x80801BA0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80801BA4: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
L_80801BA8:
    // 0x80801BA8: nop

    // 0x80801BAC: bltz        $a0, L_80801B9C
    if (SIGNED(ctx->r4) < 0) {
        // 0x80801BB0: nop
    
            goto L_80801B9C;
    }
    // 0x80801BB0: nop

L_80801BB4:
    // 0x80801BB4: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80801BB8: lui         $at, 0x1B
    ctx->r1 = S32(0X1B << 16);
    // 0x80801BBC: ori         $at, $at, 0x5E24
    ctx->r1 = ctx->r1 | 0X5E24;
    // 0x80801BC0: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x80801BC4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80801BC8: jal         0x800C4140
    // 0x80801BCC: addu        $a0, $t7, $at
    ctx->r4 = ADD32(ctx->r15, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_9;
    // 0x80801BCC: addu        $a0, $t7, $at
    ctx->r4 = ADD32(ctx->r15, ctx->r1);
    after_9:
L_80801BD0:
    // 0x80801BD0: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80801BD4: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80801BD8: jal         0x80101E14
    // 0x80801BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_10;
    // 0x80801BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80801BE0: beq         $v0, $zero, L_8080271C
    if (ctx->r2 == 0) {
        // 0x80801BE4: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2388, 0X2FB0) << 16);
            goto L_8080271C;
    }
    // 0x80801BE4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2FB0) << 16);
    // 0x80801BE8: lwc1        $f12, 0x2FB0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FB0));
    // 0x80801BEC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2FB4) << 16);
    // 0x80801BF0: addiu       $t8, $s0, 0x4
    ctx->r24 = ADD32(ctx->r16, 0X4);
    // 0x80801BF4: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80801BF8: jal         0x800DC178
    // 0x80801BFC: lwc1        $f14, 0x2FB4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FB4));
    func_800DC178(rdram, ctx);
        goto after_11;
    // 0x80801BFC: lwc1        $f14, 0x2FB4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FB4));
    after_11:
    // 0x80801C00: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2FB8) << 16);
    // 0x80801C04: lwc1        $f4, 0x2FB8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FB8));
    // 0x80801C08: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801C0C: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80801C10: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801C14: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80801C18: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801C1C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80801C20: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80801C24: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80801C28: nop

    // 0x80801C2C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80801C30: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80801C34: nop

    // 0x80801C38: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80801C3C: beql        $a0, $zero, L_80801C8C
    if (ctx->r4 == 0) {
        // 0x80801C40: mfc1        $a0, $f8
        ctx->r4 = (int32_t)ctx->f8.u32l;
            goto L_80801C8C;
    }
    goto skip_2;
    // 0x80801C40: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    skip_2:
    // 0x80801C44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801C48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801C4C: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80801C50: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80801C54: nop

    // 0x80801C58: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80801C5C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80801C60: nop

    // 0x80801C64: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80801C68: bne         $a0, $zero, L_80801C80
    if (ctx->r4 != 0) {
        // 0x80801C6C: nop
    
            goto L_80801C80;
    }
    // 0x80801C6C: nop

    // 0x80801C70: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80801C74: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801C78: b           L_80801C98
    // 0x80801C7C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80801C98;
    // 0x80801C7C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80801C80:
    // 0x80801C80: b           L_80801C98
    // 0x80801C84: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80801C98;
    // 0x80801C84: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80801C88: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
L_80801C8C:
    // 0x80801C8C: nop

    // 0x80801C90: bltz        $a0, L_80801C80
    if (SIGNED(ctx->r4) < 0) {
        // 0x80801C94: nop
    
            goto L_80801C80;
    }
    // 0x80801C94: nop

L_80801C98:
    // 0x80801C98: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80801C9C: lui         $at, 0x1B
    ctx->r1 = S32(0X1B << 16);
    // 0x80801CA0: ori         $at, $at, 0x5E26
    ctx->r1 = ctx->r1 | 0X5E26;
    // 0x80801CA4: sll         $t1, $t0, 21
    ctx->r9 = S32(ctx->r8 << 21);
    // 0x80801CA8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80801CAC: jal         0x800C4140
    // 0x80801CB0: addu        $a0, $t1, $at
    ctx->r4 = ADD32(ctx->r9, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_12;
    // 0x80801CB0: addu        $a0, $t1, $at
    ctx->r4 = ADD32(ctx->r9, ctx->r1);
    after_12:
    // 0x80801CB4: b           L_80802720
    // 0x80801CB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802720;
    // 0x80801CB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801CBC:
    // 0x80801CBC: lui         $a1, 0x3EE6
    ctx->r5 = S32(0X3EE6 << 16);
    // 0x80801CC0: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80801CC4: jal         0x80101E14
    // 0x80801CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_13;
    // 0x80801CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80801CCC: bne         $v0, $zero, L_80801CE4
    if (ctx->r2 != 0) {
        // 0x80801CD0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801CE4;
    }
    // 0x80801CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CD4: lui         $a1, 0x3F73
    ctx->r5 = S32(0X3F73 << 16);
    // 0x80801CD8: jal         0x80101E14
    // 0x80801CDC: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    func_80101E14(rdram, ctx);
        goto after_14;
    // 0x80801CDC: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_14:
    // 0x80801CE0: beq         $v0, $zero, L_80801DAC
    if (ctx->r2 == 0) {
        // 0x80801CE4: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2388, 0X2FBC) << 16);
            goto L_80801DAC;
    }
L_80801CE4:
    // 0x80801CE4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2FBC) << 16);
    // 0x80801CE8: lwc1        $f12, 0x2FBC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FBC));
    // 0x80801CEC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2FC0) << 16);
    // 0x80801CF0: jal         0x800DC178
    // 0x80801CF4: lwc1        $f14, 0x2FC0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FC0));
    func_800DC178(rdram, ctx);
        goto after_15;
    // 0x80801CF4: lwc1        $f14, 0x2FC0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FC0));
    after_15:
    // 0x80801CF8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2FC4) << 16);
    // 0x80801CFC: lwc1        $f10, 0x2FC4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FC4));
    // 0x80801D00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801D04: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80801D08: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80801D0C: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80801D10: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801D14: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801D18: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80801D1C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80801D20: nop

    // 0x80801D24: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80801D28: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80801D2C: nop

    // 0x80801D30: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80801D34: beql        $a0, $zero, L_80801D84
    if (ctx->r4 == 0) {
        // 0x80801D38: mfc1        $a0, $f18
        ctx->r4 = (int32_t)ctx->f18.u32l;
            goto L_80801D84;
    }
    goto skip_3;
    // 0x80801D38: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    skip_3:
    // 0x80801D3C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801D40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801D44: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80801D48: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80801D4C: nop

    // 0x80801D50: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80801D54: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80801D58: nop

    // 0x80801D5C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80801D60: bne         $a0, $zero, L_80801D78
    if (ctx->r4 != 0) {
        // 0x80801D64: nop
    
            goto L_80801D78;
    }
    // 0x80801D64: nop

    // 0x80801D68: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80801D6C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801D70: b           L_80801D90
    // 0x80801D74: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80801D90;
    // 0x80801D74: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80801D78:
    // 0x80801D78: b           L_80801D90
    // 0x80801D7C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80801D90;
    // 0x80801D7C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80801D80: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
L_80801D84:
    // 0x80801D84: nop

    // 0x80801D88: bltz        $a0, L_80801D78
    if (SIGNED(ctx->r4) < 0) {
        // 0x80801D8C: nop
    
            goto L_80801D78;
    }
    // 0x80801D8C: nop

L_80801D90:
    // 0x80801D90: or          $t3, $a0, $zero
    ctx->r11 = ctx->r4 | 0;
    // 0x80801D94: lui         $at, 0x1F
    ctx->r1 = S32(0X1F << 16);
    // 0x80801D98: ori         $at, $at, 0x4404
    ctx->r1 = ctx->r1 | 0X4404;
    // 0x80801D9C: sll         $t4, $t3, 21
    ctx->r12 = S32(ctx->r11 << 21);
    // 0x80801DA0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80801DA4: jal         0x800C4140
    // 0x80801DA8: addu        $a0, $t4, $at
    ctx->r4 = ADD32(ctx->r12, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_16;
    // 0x80801DA8: addu        $a0, $t4, $at
    ctx->r4 = ADD32(ctx->r12, ctx->r1);
    after_16:
L_80801DAC:
    // 0x80801DAC: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80801DB0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80801DB4: jal         0x80101E14
    // 0x80801DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_17;
    // 0x80801DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80801DBC: beq         $v0, $zero, L_80801E90
    if (ctx->r2 == 0) {
        // 0x80801DC0: lui         $at, 0x3FA0
        ctx->r1 = S32(0X3FA0 << 16);
            goto L_80801E90;
    }
    // 0x80801DC0: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x80801DC4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801DC8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2FC8) << 16);
    // 0x80801DCC: addiu       $t5, $s0, 0x4
    ctx->r13 = ADD32(ctx->r16, 0X4);
    // 0x80801DD0: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80801DD4: jal         0x800DC178
    // 0x80801DD8: lwc1        $f14, 0x2FC8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FC8));
    func_800DC178(rdram, ctx);
        goto after_18;
    // 0x80801DD8: lwc1        $f14, 0x2FC8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FC8));
    after_18:
    // 0x80801DDC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2FCC) << 16);
    // 0x80801DE0: lwc1        $f4, 0x2FCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FCC));
    // 0x80801DE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801DE8: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80801DEC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801DF0: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80801DF4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801DF8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80801DFC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80801E00: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80801E04: nop

    // 0x80801E08: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80801E0C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80801E10: nop

    // 0x80801E14: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80801E18: beql        $a0, $zero, L_80801E68
    if (ctx->r4 == 0) {
        // 0x80801E1C: mfc1        $a0, $f8
        ctx->r4 = (int32_t)ctx->f8.u32l;
            goto L_80801E68;
    }
    goto skip_4;
    // 0x80801E1C: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    skip_4:
    // 0x80801E20: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801E24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801E28: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80801E2C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80801E30: nop

    // 0x80801E34: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80801E38: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80801E3C: nop

    // 0x80801E40: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80801E44: bne         $a0, $zero, L_80801E5C
    if (ctx->r4 != 0) {
        // 0x80801E48: nop
    
            goto L_80801E5C;
    }
    // 0x80801E48: nop

    // 0x80801E4C: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80801E50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801E54: b           L_80801E74
    // 0x80801E58: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80801E74;
    // 0x80801E58: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80801E5C:
    // 0x80801E5C: b           L_80801E74
    // 0x80801E60: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80801E74;
    // 0x80801E60: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80801E64: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
L_80801E68:
    // 0x80801E68: nop

    // 0x80801E6C: bltz        $a0, L_80801E5C
    if (SIGNED(ctx->r4) < 0) {
        // 0x80801E70: nop
    
            goto L_80801E5C;
    }
    // 0x80801E70: nop

L_80801E74:
    // 0x80801E74: or          $t7, $a0, $zero
    ctx->r15 = ctx->r4 | 0;
    // 0x80801E78: lui         $at, 0xB
    ctx->r1 = S32(0XB << 16);
    // 0x80801E7C: ori         $at, $at, 0xBD8A
    ctx->r1 = ctx->r1 | 0XBD8A;
    // 0x80801E80: sll         $t8, $t7, 21
    ctx->r24 = S32(ctx->r15 << 21);
    // 0x80801E84: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80801E88: jal         0x800C4140
    // 0x80801E8C: addu        $a0, $t8, $at
    ctx->r4 = ADD32(ctx->r24, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_19;
    // 0x80801E8C: addu        $a0, $t8, $at
    ctx->r4 = ADD32(ctx->r24, ctx->r1);
    after_19:
L_80801E90:
    // 0x80801E90: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x80801E94: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80801E98: jal         0x80101E14
    // 0x80801E9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_20;
    // 0x80801E9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80801EA0: beq         $v0, $zero, L_8080271C
    if (ctx->r2 == 0) {
        // 0x80801EA4: lui         $at, 0x3FA0
        ctx->r1 = S32(0X3FA0 << 16);
            goto L_8080271C;
    }
    // 0x80801EA4: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x80801EA8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801EAC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2FD0) << 16);
    // 0x80801EB0: addiu       $t9, $s0, 0x4
    ctx->r25 = ADD32(ctx->r16, 0X4);
    // 0x80801EB4: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80801EB8: jal         0x800DC178
    // 0x80801EBC: lwc1        $f14, 0x2FD0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FD0));
    func_800DC178(rdram, ctx);
        goto after_21;
    // 0x80801EBC: lwc1        $f14, 0x2FD0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FD0));
    after_21:
    // 0x80801EC0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2FD4) << 16);
    // 0x80801EC4: lwc1        $f10, 0x2FD4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FD4));
    // 0x80801EC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801ECC: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80801ED0: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80801ED4: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80801ED8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801EDC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80801EE0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80801EE4: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80801EE8: nop

    // 0x80801EEC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80801EF0: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80801EF4: nop

    // 0x80801EF8: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80801EFC: beql        $a0, $zero, L_80801F4C
    if (ctx->r4 == 0) {
        // 0x80801F00: mfc1        $a0, $f18
        ctx->r4 = (int32_t)ctx->f18.u32l;
            goto L_80801F4C;
    }
    goto skip_5;
    // 0x80801F00: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    skip_5:
    // 0x80801F04: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801F08: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801F0C: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80801F10: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80801F14: nop

    // 0x80801F18: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80801F1C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80801F20: nop

    // 0x80801F24: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80801F28: bne         $a0, $zero, L_80801F40
    if (ctx->r4 != 0) {
        // 0x80801F2C: nop
    
            goto L_80801F40;
    }
    // 0x80801F2C: nop

    // 0x80801F30: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80801F34: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801F38: b           L_80801F58
    // 0x80801F3C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80801F58;
    // 0x80801F3C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80801F40:
    // 0x80801F40: b           L_80801F58
    // 0x80801F44: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80801F58;
    // 0x80801F44: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80801F48: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
L_80801F4C:
    // 0x80801F4C: nop

    // 0x80801F50: bltz        $a0, L_80801F40
    if (SIGNED(ctx->r4) < 0) {
        // 0x80801F54: nop
    
            goto L_80801F40;
    }
    // 0x80801F54: nop

L_80801F58:
    // 0x80801F58: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x80801F5C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80801F60: ori         $at, $at, 0xF58B
    ctx->r1 = ctx->r1 | 0XF58B;
    // 0x80801F64: sll         $t2, $t1, 21
    ctx->r10 = S32(ctx->r9 << 21);
    // 0x80801F68: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80801F6C: jal         0x800C4140
    // 0x80801F70: addu        $a0, $t2, $at
    ctx->r4 = ADD32(ctx->r10, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_22;
    // 0x80801F70: addu        $a0, $t2, $at
    ctx->r4 = ADD32(ctx->r10, ctx->r1);
    after_22:
    // 0x80801F74: b           L_80802720
    // 0x80801F78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802720;
    // 0x80801F78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801F7C:
    // 0x80801F7C: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x80801F80: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80801F84: jal         0x80101E14
    // 0x80801F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_23;
    // 0x80801F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80801F8C: beq         $v0, $zero, L_80802058
    if (ctx->r2 == 0) {
        // 0x80801F90: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2388, 0X2FD8) << 16);
            goto L_80802058;
    }
    // 0x80801F90: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2FD8) << 16);
    // 0x80801F94: lwc1        $f12, 0x2FD8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FD8));
    // 0x80801F98: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2FDC) << 16);
    // 0x80801F9C: jal         0x800DC178
    // 0x80801FA0: lwc1        $f14, 0x2FDC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FDC));
    func_800DC178(rdram, ctx);
        goto after_24;
    // 0x80801FA0: lwc1        $f14, 0x2FDC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FDC));
    after_24:
    // 0x80801FA4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2FE0) << 16);
    // 0x80801FA8: lwc1        $f4, 0x2FE0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FE0));
    // 0x80801FAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801FB0: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80801FB4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801FB8: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80801FBC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801FC0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801FC4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80801FC8: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80801FCC: nop

    // 0x80801FD0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80801FD4: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80801FD8: nop

    // 0x80801FDC: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80801FE0: beql        $a0, $zero, L_80802030
    if (ctx->r4 == 0) {
        // 0x80801FE4: mfc1        $a0, $f8
        ctx->r4 = (int32_t)ctx->f8.u32l;
            goto L_80802030;
    }
    goto skip_6;
    // 0x80801FE4: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    skip_6:
    // 0x80801FE8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801FEC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801FF0: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80801FF4: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80801FF8: nop

    // 0x80801FFC: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80802000: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80802004: nop

    // 0x80802008: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x8080200C: bne         $a0, $zero, L_80802024
    if (ctx->r4 != 0) {
        // 0x80802010: nop
    
            goto L_80802024;
    }
    // 0x80802010: nop

    // 0x80802014: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80802018: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080201C: b           L_8080203C
    // 0x80802020: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_8080203C;
    // 0x80802020: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80802024:
    // 0x80802024: b           L_8080203C
    // 0x80802028: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_8080203C;
    // 0x80802028: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8080202C: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
L_80802030:
    // 0x80802030: nop

    // 0x80802034: bltz        $a0, L_80802024
    if (SIGNED(ctx->r4) < 0) {
        // 0x80802038: nop
    
            goto L_80802024;
    }
    // 0x80802038: nop

L_8080203C:
    // 0x8080203C: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
    // 0x80802040: lui         $at, 0x1B
    ctx->r1 = S32(0X1B << 16);
    // 0x80802044: ori         $at, $at, 0x5E26
    ctx->r1 = ctx->r1 | 0X5E26;
    // 0x80802048: sll         $t5, $t4, 21
    ctx->r13 = S32(ctx->r12 << 21);
    // 0x8080204C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80802050: jal         0x800C4140
    // 0x80802054: addu        $a0, $t5, $at
    ctx->r4 = ADD32(ctx->r13, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_25;
    // 0x80802054: addu        $a0, $t5, $at
    ctx->r4 = ADD32(ctx->r13, ctx->r1);
    after_25:
L_80802058:
    // 0x80802058: lui         $a1, 0x3ED7
    ctx->r5 = S32(0X3ED7 << 16);
    // 0x8080205C: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    // 0x80802060: jal         0x80101E14
    // 0x80802064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_26;
    // 0x80802064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80802068: beq         $v0, $zero, L_8080213C
    if (ctx->r2 == 0) {
        // 0x8080206C: lui         $at, 0x3F40
        ctx->r1 = S32(0X3F40 << 16);
            goto L_8080213C;
    }
    // 0x8080206C: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80802070: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80802074: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2FE4) << 16);
    // 0x80802078: addiu       $t6, $s0, 0x4
    ctx->r14 = ADD32(ctx->r16, 0X4);
    // 0x8080207C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80802080: jal         0x800DC178
    // 0x80802084: lwc1        $f14, 0x2FE4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FE4));
    func_800DC178(rdram, ctx);
        goto after_27;
    // 0x80802084: lwc1        $f14, 0x2FE4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FE4));
    after_27:
    // 0x80802088: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2FE8) << 16);
    // 0x8080208C: lwc1        $f10, 0x2FE8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FE8));
    // 0x80802090: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80802094: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80802098: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8080209C: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x808020A0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808020A4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808020A8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x808020AC: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x808020B0: nop

    // 0x808020B4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x808020B8: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x808020BC: nop

    // 0x808020C0: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x808020C4: beql        $a0, $zero, L_80802114
    if (ctx->r4 == 0) {
        // 0x808020C8: mfc1        $a0, $f18
        ctx->r4 = (int32_t)ctx->f18.u32l;
            goto L_80802114;
    }
    goto skip_7;
    // 0x808020C8: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    skip_7:
    // 0x808020CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808020D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808020D4: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x808020D8: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x808020DC: nop

    // 0x808020E0: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x808020E4: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x808020E8: nop

    // 0x808020EC: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x808020F0: bne         $a0, $zero, L_80802108
    if (ctx->r4 != 0) {
        // 0x808020F4: nop
    
            goto L_80802108;
    }
    // 0x808020F4: nop

    // 0x808020F8: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x808020FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80802100: b           L_80802120
    // 0x80802104: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80802120;
    // 0x80802104: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80802108:
    // 0x80802108: b           L_80802120
    // 0x8080210C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80802120;
    // 0x8080210C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80802110: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
L_80802114:
    // 0x80802114: nop

    // 0x80802118: bltz        $a0, L_80802108
    if (SIGNED(ctx->r4) < 0) {
        // 0x8080211C: nop
    
            goto L_80802108;
    }
    // 0x8080211C: nop

L_80802120:
    // 0x80802120: or          $t8, $a0, $zero
    ctx->r24 = ctx->r4 | 0;
    // 0x80802124: lui         $at, 0x1B
    ctx->r1 = S32(0X1B << 16);
    // 0x80802128: ori         $at, $at, 0x5E1F
    ctx->r1 = ctx->r1 | 0X5E1F;
    // 0x8080212C: sll         $t9, $t8, 21
    ctx->r25 = S32(ctx->r24 << 21);
    // 0x80802130: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80802134: jal         0x800C4140
    // 0x80802138: addu        $a0, $t9, $at
    ctx->r4 = ADD32(ctx->r25, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_28;
    // 0x80802138: addu        $a0, $t9, $at
    ctx->r4 = ADD32(ctx->r25, ctx->r1);
    after_28:
L_8080213C:
    // 0x8080213C: lui         $a1, 0x3F28
    ctx->r5 = S32(0X3F28 << 16);
    // 0x80802140: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    // 0x80802144: jal         0x80101E14
    // 0x80802148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_29;
    // 0x80802148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x8080214C: beq         $v0, $zero, L_8080271C
    if (ctx->r2 == 0) {
        // 0x80802150: lui         $at, 0x3F40
        ctx->r1 = S32(0X3F40 << 16);
            goto L_8080271C;
    }
    // 0x80802150: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80802154: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80802158: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2FEC) << 16);
    // 0x8080215C: addiu       $t0, $s0, 0x4
    ctx->r8 = ADD32(ctx->r16, 0X4);
    // 0x80802160: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80802164: jal         0x800DC178
    // 0x80802168: lwc1        $f14, 0x2FEC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FEC));
    func_800DC178(rdram, ctx);
        goto after_30;
    // 0x80802168: lwc1        $f14, 0x2FEC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FEC));
    after_30:
    // 0x8080216C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2FF0) << 16);
    // 0x80802170: lwc1        $f4, 0x2FF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FF0));
    // 0x80802174: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80802178: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x8080217C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80802180: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80802184: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80802188: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8080218C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80802190: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80802194: nop

    // 0x80802198: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8080219C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x808021A0: nop

    // 0x808021A4: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x808021A8: beql        $a0, $zero, L_808021F8
    if (ctx->r4 == 0) {
        // 0x808021AC: mfc1        $a0, $f8
        ctx->r4 = (int32_t)ctx->f8.u32l;
            goto L_808021F8;
    }
    goto skip_8;
    // 0x808021AC: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    skip_8:
    // 0x808021B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808021B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808021B8: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x808021BC: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x808021C0: nop

    // 0x808021C4: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x808021C8: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x808021CC: nop

    // 0x808021D0: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x808021D4: bne         $a0, $zero, L_808021EC
    if (ctx->r4 != 0) {
        // 0x808021D8: nop
    
            goto L_808021EC;
    }
    // 0x808021D8: nop

    // 0x808021DC: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x808021E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808021E4: b           L_80802204
    // 0x808021E8: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80802204;
    // 0x808021E8: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_808021EC:
    // 0x808021EC: b           L_80802204
    // 0x808021F0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80802204;
    // 0x808021F0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x808021F4: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
L_808021F8:
    // 0x808021F8: nop

    // 0x808021FC: bltz        $a0, L_808021EC
    if (SIGNED(ctx->r4) < 0) {
        // 0x80802200: nop
    
            goto L_808021EC;
    }
    // 0x80802200: nop

L_80802204:
    // 0x80802204: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x80802208: lui         $at, 0x1B
    ctx->r1 = S32(0X1B << 16);
    // 0x8080220C: ori         $at, $at, 0x5E1F
    ctx->r1 = ctx->r1 | 0X5E1F;
    // 0x80802210: sll         $t3, $t2, 21
    ctx->r11 = S32(ctx->r10 << 21);
    // 0x80802214: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80802218: jal         0x800C4140
    // 0x8080221C: addu        $a0, $t3, $at
    ctx->r4 = ADD32(ctx->r11, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_31;
    // 0x8080221C: addu        $a0, $t3, $at
    ctx->r4 = ADD32(ctx->r11, ctx->r1);
    after_31:
    // 0x80802220: b           L_80802720
    // 0x80802224: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802720;
    // 0x80802224: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802228:
    // 0x80802228: lui         $a1, 0x3EA3
    ctx->r5 = S32(0X3EA3 << 16);
    // 0x8080222C: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80802230: jal         0x80101E14
    // 0x80802234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_32;
    // 0x80802234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80802238: beq         $v0, $zero, L_80802310
    if (ctx->r2 == 0) {
        // 0x8080223C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802310;
    }
    // 0x8080223C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802240: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2FF4) << 16);
    // 0x80802244: lwc1        $f12, 0x2FF4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FF4));
    // 0x80802248: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2FF8) << 16);
    // 0x8080224C: jal         0x800DC178
    // 0x80802250: lwc1        $f14, 0x2FF8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FF8));
    func_800DC178(rdram, ctx);
        goto after_33;
    // 0x80802250: lwc1        $f14, 0x2FF8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FF8));
    after_33:
    // 0x80802254: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2FFC) << 16);
    // 0x80802258: lwc1        $f10, 0x2FFC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2FFC));
    // 0x8080225C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80802260: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80802264: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80802268: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x8080226C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80802270: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80802274: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80802278: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x8080227C: nop

    // 0x80802280: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80802284: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80802288: nop

    // 0x8080228C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80802290: beql        $a0, $zero, L_808022E0
    if (ctx->r4 == 0) {
        // 0x80802294: mfc1        $a0, $f18
        ctx->r4 = (int32_t)ctx->f18.u32l;
            goto L_808022E0;
    }
    goto skip_9;
    // 0x80802294: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    skip_9:
    // 0x80802298: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080229C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808022A0: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x808022A4: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x808022A8: nop

    // 0x808022AC: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x808022B0: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x808022B4: nop

    // 0x808022B8: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x808022BC: bne         $a0, $zero, L_808022D4
    if (ctx->r4 != 0) {
        // 0x808022C0: nop
    
            goto L_808022D4;
    }
    // 0x808022C0: nop

    // 0x808022C4: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x808022C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808022CC: b           L_808022EC
    // 0x808022D0: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_808022EC;
    // 0x808022D0: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_808022D4:
    // 0x808022D4: b           L_808022EC
    // 0x808022D8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_808022EC;
    // 0x808022D8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x808022DC: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
L_808022E0:
    // 0x808022E0: nop

    // 0x808022E4: bltz        $a0, L_808022D4
    if (SIGNED(ctx->r4) < 0) {
        // 0x808022E8: nop
    
            goto L_808022D4;
    }
    // 0x808022E8: nop

L_808022EC:
    // 0x808022EC: or          $t5, $a0, $zero
    ctx->r13 = ctx->r4 | 0;
    // 0x808022F0: lui         $at, 0x1B
    ctx->r1 = S32(0X1B << 16);
    // 0x808022F4: ori         $at, $at, 0x5E1E
    ctx->r1 = ctx->r1 | 0X5E1E;
    // 0x808022F8: sll         $t6, $t5, 21
    ctx->r14 = S32(ctx->r13 << 21);
    // 0x808022FC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80802300: jal         0x800C4140
    // 0x80802304: addu        $a0, $t6, $at
    ctx->r4 = ADD32(ctx->r14, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_34;
    // 0x80802304: addu        $a0, $t6, $at
    ctx->r4 = ADD32(ctx->r14, ctx->r1);
    after_34:
    // 0x80802308: b           L_80802720
    // 0x8080230C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802720;
    // 0x8080230C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802310:
    // 0x80802310: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80802314: jal         0x80101E14
    // 0x80802318: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80101E14(rdram, ctx);
        goto after_35;
    // 0x80802318: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_35:
    // 0x8080231C: beq         $v0, $zero, L_8080271C
    if (ctx->r2 == 0) {
        // 0x80802320: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2388, 0X3000) << 16);
            goto L_8080271C;
    }
    // 0x80802320: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X3000) << 16);
    // 0x80802324: lwc1        $f12, 0x3000($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X3000));
    // 0x80802328: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X3004) << 16);
    // 0x8080232C: jal         0x800DC178
    // 0x80802330: lwc1        $f14, 0x3004($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X3004));
    func_800DC178(rdram, ctx);
        goto after_36;
    // 0x80802330: lwc1        $f14, 0x3004($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X3004));
    after_36:
    // 0x80802334: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X3008) << 16);
    // 0x80802338: lwc1        $f4, 0x3008($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X3008));
    // 0x8080233C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80802340: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80802344: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80802348: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x8080234C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80802350: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80802354: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80802358: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x8080235C: nop

    // 0x80802360: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80802364: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80802368: nop

    // 0x8080236C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80802370: beql        $a0, $zero, L_808023C0
    if (ctx->r4 == 0) {
        // 0x80802374: mfc1        $a0, $f8
        ctx->r4 = (int32_t)ctx->f8.u32l;
            goto L_808023C0;
    }
    goto skip_10;
    // 0x80802374: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    skip_10:
    // 0x80802378: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080237C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80802380: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80802384: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80802388: nop

    // 0x8080238C: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80802390: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80802394: nop

    // 0x80802398: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x8080239C: bne         $a0, $zero, L_808023B4
    if (ctx->r4 != 0) {
        // 0x808023A0: nop
    
            goto L_808023B4;
    }
    // 0x808023A0: nop

    // 0x808023A4: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x808023A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808023AC: b           L_808023CC
    // 0x808023B0: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_808023CC;
    // 0x808023B0: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_808023B4:
    // 0x808023B4: b           L_808023CC
    // 0x808023B8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_808023CC;
    // 0x808023B8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x808023BC: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
L_808023C0:
    // 0x808023C0: nop

    // 0x808023C4: bltz        $a0, L_808023B4
    if (SIGNED(ctx->r4) < 0) {
        // 0x808023C8: nop
    
            goto L_808023B4;
    }
    // 0x808023C8: nop

L_808023CC:
    // 0x808023CC: or          $t8, $a0, $zero
    ctx->r24 = ctx->r4 | 0;
    // 0x808023D0: lui         $at, 0x1B
    ctx->r1 = S32(0X1B << 16);
    // 0x808023D4: ori         $at, $at, 0x5E25
    ctx->r1 = ctx->r1 | 0X5E25;
    // 0x808023D8: sll         $t9, $t8, 21
    ctx->r25 = S32(ctx->r24 << 21);
    // 0x808023DC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x808023E0: jal         0x800C4140
    // 0x808023E4: addu        $a0, $t9, $at
    ctx->r4 = ADD32(ctx->r25, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_37;
    // 0x808023E4: addu        $a0, $t9, $at
    ctx->r4 = ADD32(ctx->r25, ctx->r1);
    after_37:
    // 0x808023E8: b           L_80802720
    // 0x808023EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802720;
    // 0x808023EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808023F0:
    // 0x808023F0: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808023F4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808023F8: jal         0x80101E14
    // 0x808023FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_38;
    // 0x808023FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x80802400: beq         $v0, $zero, L_808024CC
    if (ctx->r2 == 0) {
        // 0x80802404: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2388, 0X300C) << 16);
            goto L_808024CC;
    }
    // 0x80802404: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X300C) << 16);
    // 0x80802408: lwc1        $f12, 0x300C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X300C));
    // 0x8080240C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X3010) << 16);
    // 0x80802410: jal         0x800DC178
    // 0x80802414: lwc1        $f14, 0x3010($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X3010));
    func_800DC178(rdram, ctx);
        goto after_39;
    // 0x80802414: lwc1        $f14, 0x3010($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X3010));
    after_39:
    // 0x80802418: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X3014) << 16);
    // 0x8080241C: lwc1        $f10, 0x3014($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X3014));
    // 0x80802420: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80802424: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80802428: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8080242C: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80802430: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80802434: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80802438: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8080243C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80802440: nop

    // 0x80802444: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80802448: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x8080244C: nop

    // 0x80802450: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80802454: beql        $a0, $zero, L_808024A4
    if (ctx->r4 == 0) {
        // 0x80802458: mfc1        $a0, $f18
        ctx->r4 = (int32_t)ctx->f18.u32l;
            goto L_808024A4;
    }
    goto skip_11;
    // 0x80802458: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    skip_11:
    // 0x8080245C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80802460: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80802464: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80802468: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x8080246C: nop

    // 0x80802470: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80802474: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80802478: nop

    // 0x8080247C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80802480: bne         $a0, $zero, L_80802498
    if (ctx->r4 != 0) {
        // 0x80802484: nop
    
            goto L_80802498;
    }
    // 0x80802484: nop

    // 0x80802488: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x8080248C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80802490: b           L_808024B0
    // 0x80802494: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_808024B0;
    // 0x80802494: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80802498:
    // 0x80802498: b           L_808024B0
    // 0x8080249C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_808024B0;
    // 0x8080249C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x808024A0: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
L_808024A4:
    // 0x808024A4: nop

    // 0x808024A8: bltz        $a0, L_80802498
    if (SIGNED(ctx->r4) < 0) {
        // 0x808024AC: nop
    
            goto L_80802498;
    }
    // 0x808024AC: nop

L_808024B0:
    // 0x808024B0: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x808024B4: lui         $at, 0x13
    ctx->r1 = S32(0X13 << 16);
    // 0x808024B8: ori         $at, $at, 0x8E23
    ctx->r1 = ctx->r1 | 0X8E23;
    // 0x808024BC: sll         $t2, $t1, 21
    ctx->r10 = S32(ctx->r9 << 21);
    // 0x808024C0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x808024C4: jal         0x800C4140
    // 0x808024C8: addu        $a0, $t2, $at
    ctx->r4 = ADD32(ctx->r10, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_40;
    // 0x808024C8: addu        $a0, $t2, $at
    ctx->r4 = ADD32(ctx->r10, ctx->r1);
    after_40:
L_808024CC:
    // 0x808024CC: lui         $a1, 0x3E2E
    ctx->r5 = S32(0X3E2E << 16);
    // 0x808024D0: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    // 0x808024D4: jal         0x80101E14
    // 0x808024D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_41;
    // 0x808024D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x808024DC: beq         $v0, $zero, L_808024F8
    if (ctx->r2 == 0) {
        // 0x808024E0: lui         $a0, 0x7FF3
        ctx->r4 = S32(0X7FF3 << 16);
            goto L_808024F8;
    }
    // 0x808024E0: lui         $a0, 0x7FF3
    ctx->r4 = S32(0X7FF3 << 16);
    // 0x808024E4: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x808024E8: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x808024EC: ori         $a0, $a0, 0x8CD5
    ctx->r4 = ctx->r4 | 0X8CD5;
    // 0x808024F0: jal         0x800C4140
    // 0x808024F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_42;
    // 0x808024F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_42:
L_808024F8:
    // 0x808024F8: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x808024FC: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80802500: jal         0x80101E14
    // 0x80802504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_43;
    // 0x80802504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x80802508: beq         $v0, $zero, L_8080271C
    if (ctx->r2 == 0) {
        // 0x8080250C: lui         $at, 0x3FA0
        ctx->r1 = S32(0X3FA0 << 16);
            goto L_8080271C;
    }
    // 0x8080250C: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x80802510: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80802514: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X3018) << 16);
    // 0x80802518: addiu       $t3, $s0, 0x4
    ctx->r11 = ADD32(ctx->r16, 0X4);
    // 0x8080251C: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80802520: jal         0x800DC178
    // 0x80802524: lwc1        $f14, 0x3018($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X3018));
    func_800DC178(rdram, ctx);
        goto after_44;
    // 0x80802524: lwc1        $f14, 0x3018($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X3018));
    after_44:
    // 0x80802528: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X301C) << 16);
    // 0x8080252C: lwc1        $f4, 0x301C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X301C));
    // 0x80802530: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80802534: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80802538: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8080253C: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80802540: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80802544: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80802548: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8080254C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80802550: nop

    // 0x80802554: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80802558: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x8080255C: nop

    // 0x80802560: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80802564: beql        $a0, $zero, L_808025B4
    if (ctx->r4 == 0) {
        // 0x80802568: mfc1        $a0, $f8
        ctx->r4 = (int32_t)ctx->f8.u32l;
            goto L_808025B4;
    }
    goto skip_12;
    // 0x80802568: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    skip_12:
    // 0x8080256C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802570: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80802574: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80802578: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x8080257C: nop

    // 0x80802580: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80802584: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80802588: nop

    // 0x8080258C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80802590: bne         $a0, $zero, L_808025A8
    if (ctx->r4 != 0) {
        // 0x80802594: nop
    
            goto L_808025A8;
    }
    // 0x80802594: nop

    // 0x80802598: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x8080259C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808025A0: b           L_808025C0
    // 0x808025A4: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_808025C0;
    // 0x808025A4: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_808025A8:
    // 0x808025A8: b           L_808025C0
    // 0x808025AC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_808025C0;
    // 0x808025AC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x808025B0: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
L_808025B4:
    // 0x808025B4: nop

    // 0x808025B8: bltz        $a0, L_808025A8
    if (SIGNED(ctx->r4) < 0) {
        // 0x808025BC: nop
    
            goto L_808025A8;
    }
    // 0x808025BC: nop

L_808025C0:
    // 0x808025C0: or          $t5, $a0, $zero
    ctx->r13 = ctx->r4 | 0;
    // 0x808025C4: lui         $at, 0x9
    ctx->r1 = S32(0X9 << 16);
    // 0x808025C8: ori         $at, $at, 0xC58B
    ctx->r1 = ctx->r1 | 0XC58B;
    // 0x808025CC: sll         $t6, $t5, 21
    ctx->r14 = S32(ctx->r13 << 21);
    // 0x808025D0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x808025D4: jal         0x800C4140
    // 0x808025D8: addu        $a0, $t6, $at
    ctx->r4 = ADD32(ctx->r14, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_45;
    // 0x808025D8: addu        $a0, $t6, $at
    ctx->r4 = ADD32(ctx->r14, ctx->r1);
    after_45:
    // 0x808025DC: b           L_80802720
    // 0x808025E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802720;
    // 0x808025E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808025E4:
    // 0x808025E4: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808025E8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808025EC: jal         0x80101E14
    // 0x808025F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_46;
    // 0x808025F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_46:
    // 0x808025F4: bne         $v0, $zero, L_80802620
    if (ctx->r2 != 0) {
        // 0x808025F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802620;
    }
    // 0x808025F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808025FC: lui         $a1, 0x3ED7
    ctx->r5 = S32(0X3ED7 << 16);
    // 0x80802600: jal         0x80101E14
    // 0x80802604: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    func_80101E14(rdram, ctx);
        goto after_47;
    // 0x80802604: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    after_47:
    // 0x80802608: bne         $v0, $zero, L_80802620
    if (ctx->r2 != 0) {
        // 0x8080260C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802620;
    }
    // 0x8080260C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802610: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x80802614: jal         0x80101E14
    // 0x80802618: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    func_80101E14(rdram, ctx);
        goto after_48;
    // 0x80802618: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_48:
    // 0x8080261C: beq         $v0, $zero, L_8080271C
    if (ctx->r2 == 0) {
        // 0x80802620: lui         $a0, 0x665B
        ctx->r4 = S32(0X665B << 16);
            goto L_8080271C;
    }
L_80802620:
    // 0x80802620: lui         $a0, 0x665B
    ctx->r4 = S32(0X665B << 16);
    // 0x80802624: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80802628: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x8080262C: ori         $a0, $a0, 0x5E1F
    ctx->r4 = ctx->r4 | 0X5E1F;
    // 0x80802630: jal         0x800C4140
    // 0x80802634: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_49;
    // 0x80802634: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_49:
    // 0x80802638: b           L_80802720
    // 0x8080263C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802720;
    // 0x8080263C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802640:
    // 0x80802640: lui         $a1, 0x3EAE
    ctx->r5 = S32(0X3EAE << 16);
    // 0x80802644: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    // 0x80802648: jal         0x80101E14
    // 0x8080264C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_50;
    // 0x8080264C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x80802650: beq         $v0, $zero, L_8080271C
    if (ctx->r2 == 0) {
        // 0x80802654: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2388, 0X3020) << 16);
            goto L_8080271C;
    }
    // 0x80802654: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X3020) << 16);
    // 0x80802658: lwc1        $f12, 0x3020($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X3020));
    // 0x8080265C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X3024) << 16);
    // 0x80802660: jal         0x800DC178
    // 0x80802664: lwc1        $f14, 0x3024($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X3024));
    func_800DC178(rdram, ctx);
        goto after_51;
    // 0x80802664: lwc1        $f14, 0x3024($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X3024));
    after_51:
    // 0x80802668: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X3028) << 16);
    // 0x8080266C: lwc1        $f10, 0x3028($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X3028));
    // 0x80802670: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80802674: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80802678: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8080267C: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80802680: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80802684: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80802688: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8080268C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80802690: nop

    // 0x80802694: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80802698: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x8080269C: nop

    // 0x808026A0: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x808026A4: beql        $a0, $zero, L_808026F4
    if (ctx->r4 == 0) {
        // 0x808026A8: mfc1        $a0, $f18
        ctx->r4 = (int32_t)ctx->f18.u32l;
            goto L_808026F4;
    }
    goto skip_13;
    // 0x808026A8: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    skip_13:
    // 0x808026AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808026B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808026B4: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x808026B8: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x808026BC: nop

    // 0x808026C0: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x808026C4: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x808026C8: nop

    // 0x808026CC: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x808026D0: bne         $a0, $zero, L_808026E8
    if (ctx->r4 != 0) {
        // 0x808026D4: nop
    
            goto L_808026E8;
    }
    // 0x808026D4: nop

    // 0x808026D8: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x808026DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808026E0: b           L_80802700
    // 0x808026E4: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80802700;
    // 0x808026E4: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_808026E8:
    // 0x808026E8: b           L_80802700
    // 0x808026EC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80802700;
    // 0x808026EC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x808026F0: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
L_808026F4:
    // 0x808026F4: nop

    // 0x808026F8: bltz        $a0, L_808026E8
    if (SIGNED(ctx->r4) < 0) {
        // 0x808026FC: nop
    
            goto L_808026E8;
    }
    // 0x808026FC: nop

L_80802700:
    // 0x80802700: or          $t8, $a0, $zero
    ctx->r24 = ctx->r4 | 0;
    // 0x80802704: lui         $at, 0x1B
    ctx->r1 = S32(0X1B << 16);
    // 0x80802708: ori         $at, $at, 0x5E1E
    ctx->r1 = ctx->r1 | 0X5E1E;
    // 0x8080270C: sll         $t9, $t8, 21
    ctx->r25 = S32(ctx->r24 << 21);
    // 0x80802710: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80802714: jal         0x800C4140
    // 0x80802718: addu        $a0, $t9, $at
    ctx->r4 = ADD32(ctx->r25, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_52;
    // 0x80802718: addu        $a0, $t9, $at
    ctx->r4 = ADD32(ctx->r25, ctx->r1);
    after_52:
L_8080271C:
    // 0x8080271C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802720:
    // 0x80802720: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802724: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802728: jr          $ra
    // 0x8080272C: nop

    return;
    // 0x8080272C: nop

;}
RECOMP_FUNC void func_800DCB58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DCB58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DCB5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800DCB60: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800DCB64: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800DCB68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DCB6C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DCB70: addiu       $a0, $a0, -0x30F0
    ctx->r4 = ADD32(ctx->r4, -0X30F0);
    // 0x800DCB74: jal         0x800DC580
    // 0x800DCB78: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_800DC580(rdram, ctx);
        goto after_0;
    // 0x800DCB78: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_0:
    // 0x800DCB7C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DCB80: addiu       $a0, $a0, -0x30E0
    ctx->r4 = ADD32(ctx->r4, -0X30E0);
    // 0x800DCB84: jal         0x800DC580
    // 0x800DCB88: addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    func_800DC580(rdram, ctx);
        goto after_1;
    // 0x800DCB88: addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    after_1:
    // 0x800DCB8C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DCB90: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800DCB94: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800DCB98: addiu       $a2, $a2, -0x30F0
    ctx->r6 = ADD32(ctx->r6, -0X30F0);
    // 0x800DCB9C: addiu       $a1, $a1, -0x30E0
    ctx->r5 = ADD32(ctx->r5, -0X30E0);
    // 0x800DCBA0: jal         0x800EFB24
    // 0x800DCBA4: addiu       $a0, $a0, -0x3100
    ctx->r4 = ADD32(ctx->r4, -0X3100);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x800DCBA4: addiu       $a0, $a0, -0x3100
    ctx->r4 = ADD32(ctx->r4, -0X3100);
    after_2:
    // 0x800DCBA8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DCBAC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800DCBB0: addiu       $a1, $a1, -0x3168
    ctx->r5 = ADD32(ctx->r5, -0X3168);
    // 0x800DCBB4: jal         0x800EF3DC
    // 0x800DCBB8: addiu       $a0, $a0, -0x30F0
    ctx->r4 = ADD32(ctx->r4, -0X30F0);
    func_800EF3DC(rdram, ctx);
        goto after_3;
    // 0x800DCBB8: addiu       $a0, $a0, -0x30F0
    ctx->r4 = ADD32(ctx->r4, -0X30F0);
    after_3:
    // 0x800DCBBC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DCBC0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800DCBC4: addiu       $v1, $v1, -0x30F0
    ctx->r3 = ADD32(ctx->r3, -0X30F0);
    // 0x800DCBC8: addiu       $v0, $v0, -0x3100
    ctx->r2 = ADD32(ctx->r2, -0X3100);
    // 0x800DCBCC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DCBD0: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800DCBD4: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800DCBD8: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800DCBDC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800DCBE0: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800DCBE4: lbu         $t6, 0x21($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X21);
    // 0x800DCBE8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800DCBEC: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800DCBF0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800DCBF4: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800DCBF8: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800DCBFC: add.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800DCC00: beq         $t7, $zero, L_800DCC78
    if (ctx->r15 == 0) {
        // 0x800DCC04: neg.s       $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
            goto L_800DCC78;
    }
    // 0x800DCC04: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800DCC08: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800DCC0C: nop

    // 0x800DCC10: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800DCC14: nop

    // 0x800DCC18: bc1fl       L_800DCC48
    if (!c1cs) {
        // 0x800DCC1C: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_800DCC48;
    }
    goto skip_0;
    // 0x800DCC1C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_0:
    // 0x800DCC20: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800DCC24: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DCC28: beq         $v0, $zero, L_800DCC44
    if (ctx->r2 == 0) {
        // 0x800DCC2C: addu        $a1, $s0, $v0
        ctx->r5 = ADD32(ctx->r16, ctx->r2);
            goto L_800DCC44;
    }
    // 0x800DCC2C: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    // 0x800DCC30: swc1        $f0, -0x3104($at)
    MEM_W(-0X3104, ctx->r1) = ctx->f0.u32l;
    // 0x800DCC34: jal         0x800DE2A4
    // 0x800DCC38: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800DE2A4(rdram, ctx);
        goto after_4;
    // 0x800DCC38: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x800DCC3C: b           L_800DCD00
    // 0x800DCC40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800DCD00;
    // 0x800DCC40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DCC44:
    // 0x800DCC44: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_800DCC48:
    // 0x800DCC48: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DCC4C: swc1        $f0, -0x3104($at)
    MEM_W(-0X3104, ctx->r1) = ctx->f0.u32l;
    // 0x800DCC50: bc1fl       L_800DCD00
    if (!c1cs) {
        // 0x800DCC54: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DCD00;
    }
    goto skip_1;
    // 0x800DCC54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800DCC58: lh          $v0, 0x22($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X22);
    // 0x800DCC5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800DCC60: beql        $v0, $zero, L_800DCD00
    if (ctx->r2 == 0) {
        // 0x800DCC64: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DCD00;
    }
    goto skip_2;
    // 0x800DCC64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800DCC68: jal         0x800DE2A4
    // 0x800DCC6C: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    func_800DE2A4(rdram, ctx);
        goto after_5;
    // 0x800DCC6C: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    after_5:
    // 0x800DCC70: b           L_800DCD00
    // 0x800DCC74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800DCD00;
    // 0x800DCC74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DCC78:
    // 0x800DCC78: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800DCC7C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DCC80: swc1        $f0, -0x3104($at)
    MEM_W(-0X3104, ctx->r1) = ctx->f0.u32l;
    // 0x800DCC84: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800DCC88: nop

    // 0x800DCC8C: bc1fl       L_800DCCD0
    if (!c1cs) {
        // 0x800DCC90: lw          $v0, 0x24($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X24);
            goto L_800DCCD0;
    }
    goto skip_3;
    // 0x800DCC90: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    skip_3:
    // 0x800DCC94: lh          $v0, 0x22($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X22);
    // 0x800DCC98: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800DCC9C: beql        $v0, $zero, L_800DCCB0
    if (ctx->r2 == 0) {
        // 0x800DCCA0: lw          $v0, 0x24($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X24);
            goto L_800DCCB0;
    }
    goto skip_4;
    // 0x800DCCA0: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    skip_4:
    // 0x800DCCA4: jal         0x800DE2A4
    // 0x800DCCA8: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    func_800DE2A4(rdram, ctx);
        goto after_6;
    // 0x800DCCA8: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    after_6:
    // 0x800DCCAC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
L_800DCCB0:
    // 0x800DCCB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800DCCB4: beql        $v0, $zero, L_800DCD00
    if (ctx->r2 == 0) {
        // 0x800DCCB8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DCD00;
    }
    goto skip_5;
    // 0x800DCCB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x800DCCBC: jal         0x800DE2A4
    // 0x800DCCC0: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    func_800DE2A4(rdram, ctx);
        goto after_7;
    // 0x800DCCC0: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    after_7:
    // 0x800DCCC4: b           L_800DCD00
    // 0x800DCCC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800DCD00;
    // 0x800DCCC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800DCCCC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
L_800DCCD0:
    // 0x800DCCD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800DCCD4: beql        $v0, $zero, L_800DCCE8
    if (ctx->r2 == 0) {
        // 0x800DCCD8: lh          $v0, 0x22($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X22);
            goto L_800DCCE8;
    }
    goto skip_6;
    // 0x800DCCD8: lh          $v0, 0x22($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X22);
    skip_6:
    // 0x800DCCDC: jal         0x800DE2A4
    // 0x800DCCE0: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    func_800DE2A4(rdram, ctx);
        goto after_8;
    // 0x800DCCE0: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    after_8:
    // 0x800DCCE4: lh          $v0, 0x22($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X22);
L_800DCCE8:
    // 0x800DCCE8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800DCCEC: beql        $v0, $zero, L_800DCD00
    if (ctx->r2 == 0) {
        // 0x800DCCF0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DCD00;
    }
    goto skip_7;
    // 0x800DCCF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x800DCCF4: jal         0x800DE2A4
    // 0x800DCCF8: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    func_800DE2A4(rdram, ctx);
        goto after_9;
    // 0x800DCCF8: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    after_9:
    // 0x800DCCFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DCD00:
    // 0x800DCD00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800DCD04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DCD08: jr          $ra
    // 0x800DCD0C: nop

    return;
    // 0x800DCD0C: nop

;}
RECOMP_FUNC void func_808008B4_bstntswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808008B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808008C0: jal         0x800839E8
    // 0x808008C4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x808008C4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x808008C8: beq         $v0, $zero, L_808008D4
    if (ctx->r2 == 0) {
        // 0x808008CC: addiu       $t6, $zero, 0x10F
        ctx->r14 = ADD32(0, 0X10F);
            goto L_808008D4;
    }
    // 0x808008CC: addiu       $t6, $zero, 0x10F
    ctx->r14 = ADD32(0, 0X10F);
    // 0x808008D0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_808008D4:
    // 0x808008D4: jal         0x80083F70
    // 0x808008D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bstnt_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x808008D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808008DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808008E0: jal         0x8009E5C8
    // 0x808008E4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x808008E4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x808008E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808008F0: jr          $ra
    // 0x808008F4: nop

    return;
    // 0x808008F4: nop

;}
RECOMP_FUNC void func_800B97A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B97A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B97A8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B97AC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800B97B0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B97B4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800B97B8: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800B97BC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800B97C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B97C4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800B97C8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800B97CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B97D0: addiu       $a0, $a0, 0x7160
    ctx->r4 = ADD32(ctx->r4, 0X7160);
    // 0x800B97D4: addiu       $a2, $a2, 0x7148
    ctx->r6 = ADD32(ctx->r6, 0X7148);
    // 0x800B97D8: jal         0x800EFB24
    // 0x800B97DC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x800B97DC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_0:
    // 0x800B97E0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800B97E4: addiu       $s0, $s0, 0x7128
    ctx->r16 = ADD32(ctx->r16, 0X7128);
    // 0x800B97E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B97EC: lwc1        $f2, 0x56AC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X56AC);
    // 0x800B97F0: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800B97F4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B97F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B97FC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B9800: nop

    // 0x800B9804: bc1fl       L_800B996C
    if (!c1cs) {
        // 0x800B9808: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800B996C;
    }
    goto skip_0;
    // 0x800B9808: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800B980C: lwc1        $f12, 0x56B0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X56B0);
    // 0x800B9810: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800B9814: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800B9818: nop

    // 0x800B981C: bc1fl       L_800B996C
    if (!c1cs) {
        // 0x800B9820: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800B996C;
    }
    goto skip_1;
    // 0x800B9820: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800B9824: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B9828: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800B982C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800B9830: nop

    // 0x800B9834: bc1fl       L_800B996C
    if (!c1cs) {
        // 0x800B9838: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800B996C;
    }
    goto skip_2;
    // 0x800B9838: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x800B983C: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x800B9840: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B9844: nop

    // 0x800B9848: bc1fl       L_800B996C
    if (!c1cs) {
        // 0x800B984C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800B996C;
    }
    goto skip_3;
    // 0x800B984C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x800B9850: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800B9854: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800B9858: bc1fl       L_800B996C
    if (!c1cs) {
        // 0x800B985C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800B996C;
    }
    goto skip_4;
    // 0x800B985C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x800B9860: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x800B9864: jal         0x800E3E8C
    // 0x800B9868: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_800E3E8C(rdram, ctx);
        goto after_1;
    // 0x800B9868: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_1:
    // 0x800B986C: beq         $v0, $zero, L_800B9968
    if (ctx->r2 == 0) {
        // 0x800B9870: lw          $a3, 0x38($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X38);
            goto L_800B9968;
    }
    // 0x800B9870: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B9874: lwc1        $f12, 0x0($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800B9878: lwc1        $f14, 0x4($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800B987C: jal         0x80018E8C
    // 0x800B9880: lw          $a2, 0x8($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X8);
    mlMtx_set_translation(rdram, ctx);
        goto after_2;
    // 0x800B9880: lw          $a2, 0x8($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X8);
    after_2:
    // 0x800B9884: jal         0x80018C28
    // 0x800B9888: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    mlMtxApply(rdram, ctx);
        goto after_3;
    // 0x800B9888: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_3:
    // 0x800B988C: lw          $a1, 0x58($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X58);
    // 0x800B9890: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800B9894: addiu       $a0, $a0, 0x716C
    ctx->r4 = ADD32(ctx->r4, 0X716C);
    // 0x800B9898: jal         0x800193C4
    // 0x800B989C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800193C4(rdram, ctx);
        goto after_4;
    // 0x800B989C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_4:
    // 0x800B98A0: lwc1        $f12, 0x44($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800B98A4: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800B98A8: jal         0x80018E8C
    // 0x800B98AC: lw          $a2, 0x4C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4C);
    mlMtx_set_translation(rdram, ctx);
        goto after_5;
    // 0x800B98AC: lw          $a2, 0x4C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4C);
    after_5:
    // 0x800B98B0: jal         0x80018FE8
    // 0x800B98B4: lwc1        $f12, 0x30($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X30);
    mlMtxRotYaw(rdram, ctx);
        goto after_6;
    // 0x800B98B4: lwc1        $f12, 0x30($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X30);
    after_6:
    // 0x800B98B8: jal         0x80018F50
    // 0x800B98BC: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    mlMtxRotPitch(rdram, ctx);
        goto after_7;
    // 0x800B98BC: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    after_7:
    // 0x800B98C0: lw          $v0, 0x58($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X58);
    // 0x800B98C4: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800B98C8: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800B98CC: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800B98D0: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800B98D4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x800B98D8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800B98DC: jal         0x80019C84
    // 0x800B98E0: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    mlMtxTranslate(rdram, ctx);
        goto after_8;
    // 0x800B98E0: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    after_8:
    // 0x800B98E4: jal         0x80018C28
    // 0x800B98E8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    mlMtxApply(rdram, ctx);
        goto after_9;
    // 0x800B98E8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_9:
    // 0x800B98EC: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800B98F0: lui         $t7, 0xDA38
    ctx->r15 = S32(0XDA38 << 16);
    // 0x800B98F4: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x800B98F8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800B98FC: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x800B9900: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B9904: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800B9908: lui         $t2, 0xDE00
    ctx->r10 = S32(0XDE00 << 16);
    // 0x800B990C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800B9910: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800B9914: addiu       $t0, $t9, 0x40
    ctx->r8 = ADD32(ctx->r25, 0X40);
    // 0x800B9918: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    // 0x800B991C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800B9920: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x800B9924: sw          $t1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r9;
    // 0x800B9928: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800B992C: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    // 0x800B9930: jal         0x8002E330
    // 0x800B9934: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_10;
    // 0x800B9934: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_10:
    // 0x800B9938: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800B993C: lui         $t4, 0xD838
    ctx->r12 = S32(0XD838 << 16);
    // 0x800B9940: ori         $t4, $t4, 0x2
    ctx->r12 = ctx->r12 | 0X2;
    // 0x800B9944: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800B9948: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800B994C: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x800B9950: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B9954: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800B9958: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
    // 0x800B995C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800B9960: b           L_800B996C
    // 0x800B9964: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
        goto L_800B996C;
    // 0x800B9964: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_800B9968:
    // 0x800B9968: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B996C:
    // 0x800B996C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B9970: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B9974: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9978: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B997C: jr          $ra
    // 0x800B9980: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B9980: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800B9984: nop

    // 0x800B9988: nop

    // 0x800B998C: nop

;}
RECOMP_FUNC void func_80800ED4_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800ED4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800ED8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800EDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800EE0: jal         0x808001FC
    // 0x80800EE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808001FC_bsstatue(rdram, ctx);
        goto after_0;
    // 0x80800EE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800EE8: jal         0x8008E944
    // 0x80800EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_1;
    // 0x80800EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EF4: addiu       $a1, $zero, 0x11E8
    ctx->r5 = ADD32(0, 0X11E8);
    // 0x80800EF8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800EFC: jal         0x800847E0
    // 0x80800F00: addiu       $a3, $zero, 0x51
    ctx->r7 = ADD32(0, 0X51);
    _badialog_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800F00: addiu       $a3, $zero, 0x51
    ctx->r7 = ADD32(0, 0X51);
    after_2:
    // 0x80800F04: beq         $v0, $zero, L_80800F20
    if (ctx->r2 == 0) {
        // 0x80800F08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F20;
    }
    // 0x80800F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F10: jal         0x80800DB8
    // 0x80800F14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800DB8_bsstatue(rdram, ctx);
        goto after_3;
    // 0x80800F14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800F18: b           L_80800F2C
    // 0x80800F1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800F2C;
    // 0x80800F1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F20:
    // 0x80800F20: jal         0x80800DB8
    // 0x80800F24: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800DB8_bsstatue(rdram, ctx);
        goto after_4;
    // 0x80800F24: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800F28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F2C:
    // 0x80800F2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800F30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800F34: jr          $ra
    // 0x80800F38: nop

    return;
    // 0x80800F38: nop

;}
RECOMP_FUNC void func_80109538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109538: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8010953C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80109540: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80109544: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80109548: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8010954C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80109550: jal         0x8008A010
    // 0x80109554: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _subaddiecustomhits_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80109554: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80109558: bne         $v0, $zero, L_80109568
    if (ctx->r2 != 0) {
        // 0x8010955C: addiu       $a0, $sp, 0x2C
        ctx->r4 = ADD32(ctx->r29, 0X2C);
            goto L_80109568;
    }
    // 0x8010955C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80109560: jal         0x800EE7F8
    // 0x80109564: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80109564: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_1:
L_80109568:
    // 0x80109568: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x8010956C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80109570: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80109574: beq         $v0, $zero, L_8010959C
    if (ctx->r2 == 0) {
        // 0x80109578: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_8010959C;
    }
    // 0x80109578: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8010957C: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x80109580: srl         $t7, $t6, 22
    ctx->r15 = S32(U32(ctx->r14) >> 22);
    // 0x80109584: bne         $t7, $zero, L_80109594
    if (ctx->r15 != 0) {
        // 0x80109588: nop
    
            goto L_80109594;
    }
    // 0x80109588: nop

    // 0x8010958C: b           L_8010959C
    // 0x80109590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_8010959C;
    // 0x80109590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80109594:
    // 0x80109594: b           L_8010959C
    // 0x80109598: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8010959C;
    // 0x80109598: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8010959C:
    // 0x8010959C: beql        $t8, $zero, L_801095E8
    if (ctx->r24 == 0) {
        // 0x801095A0: addiu       $a0, $sp, 0x2C
        ctx->r4 = ADD32(ctx->r29, 0X2C);
            goto L_801095E8;
    }
    goto skip_0;
    // 0x801095A0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    skip_0:
    // 0x801095A4: jal         0x800B53A4
    // 0x801095A8: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_800B53A4(rdram, ctx);
        goto after_2;
    // 0x801095A8: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_2:
    // 0x801095AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801095B0: jal         0x80109524
    // 0x801095B4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80109524(rdram, ctx);
        goto after_3;
    // 0x801095B4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_3:
    // 0x801095B8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801095BC: jal         0x800BA3FC
    // 0x801095C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800BA3FC(rdram, ctx);
        goto after_4;
    // 0x801095C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x801095C4: jal         0x80109518
    // 0x801095C8: nop

    func_80109518(rdram, ctx);
        goto after_5;
    // 0x801095C8: nop

    after_5:
    // 0x801095CC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x801095D0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801095D4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801095D8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801095DC: jal         0x800BABB8
    // 0x801095E0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800BABB8(rdram, ctx);
        goto after_6;
    // 0x801095E0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_6:
    // 0x801095E4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
L_801095E8:
    // 0x801095E8: jal         0x801094E0
    // 0x801095EC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_801094E0(rdram, ctx);
        goto after_7;
    // 0x801095EC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_7:
    // 0x801095F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801095F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801095F8: jr          $ra
    // 0x801095FC: nop

    return;
    // 0x801095FC: nop

;}
RECOMP_FUNC void _chnewmumbo_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086980: syscall     403
    recomp_syscall_handler(rdram, ctx, 0x80086980);
    return;
    // 0x80086984: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808002E8_chsilo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808002EC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808002F0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808002F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808002F8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808002FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800300: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800304: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80800308: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080030C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800310: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80800314: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
    // 0x80800318: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_8080031C:
    // 0x8080031C: jal         0x8080015C
    // 0x80800320: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8080015C_chsilo(rdram, ctx);
        goto after_0;
    // 0x80800320: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80800324: beql        $v0, $zero, L_80800350
    if (ctx->r2 == 0) {
        // 0x80800328: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800350;
    }
    goto skip_0;
    // 0x80800328: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8080032C: bnel        $s1, $s4, L_8080034C
    if (ctx->r17 != ctx->r20) {
        // 0x80800330: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8080034C;
    }
    goto skip_1;
    // 0x80800330: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x80800334: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x80800338: nop

    // 0x8080033C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800340: b           L_80800358
    // 0x80800344: swc1        $f6, 0x58($s3)
    MEM_W(0X58, ctx->r19) = ctx->f6.u32l;
        goto L_80800358;
    // 0x80800344: swc1        $f6, 0x58($s3)
    MEM_W(0X58, ctx->r19) = ctx->f6.u32l;
    // 0x80800348: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8080034C:
    // 0x8080034C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80800350:
    // 0x80800350: bnel        $s0, $s2, L_8080031C
    if (ctx->r16 != ctx->r18) {
        // 0x80800354: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8080031C;
    }
    goto skip_2;
    // 0x80800354: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_2:
L_80800358:
    // 0x80800358: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8080035C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800360: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800364: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800368: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8080036C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800370: jr          $ra
    // 0x80800374: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800374: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void subaddietaxi_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800094: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800098: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8080009C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808000A0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808000A4: jal         0x8010410C
    // 0x808000A8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    func_8010410C(rdram, ctx);
        goto after_0;
    // 0x808000A8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808000AC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808000B0: jal         0x800CB518
    // 0x808000B4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_800CB518(rdram, ctx);
        goto after_1;
    // 0x808000B4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_1:
    // 0x808000B8: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x808000BC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x808000C0: jal         0x800CB698
    // 0x808000C4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800CB698(rdram, ctx);
        goto after_2;
    // 0x808000C4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
    // 0x808000C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808000CC: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808000D0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x808000D4: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x808000D8: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x808000DC: bc1f        L_808000EC
    if (!c1cs) {
        // 0x808000E0: nop
    
            goto L_808000EC;
    }
    // 0x808000E0: nop

    // 0x808000E4: b           L_8080020C
    // 0x808000E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080020C;
    // 0x808000E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000EC:
    // 0x808000EC: beq         $t7, $zero, L_808000FC
    if (ctx->r15 == 0) {
        // 0x808000F0: addiu       $a0, $s1, 0x4
        ctx->r4 = ADD32(ctx->r17, 0X4);
            goto L_808000FC;
    }
    // 0x808000F0: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x808000F4: jal         0x800888C8
    // 0x808000F8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    _fxsparkle_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808000F8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_3:
L_808000FC:
    // 0x808000FC: addiu       $t8, $s1, 0x4
    ctx->r24 = ADD32(ctx->r17, 0X4);
    // 0x80800100: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80800104: jal         0x800D9078
    // 0x80800108: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    func_800D9078(rdram, ctx);
        goto after_4;
    // 0x80800108: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    after_4:
    // 0x8080010C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800110: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800114: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800118: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080011C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80800120: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800124: jal         0x800F10B4
    // 0x80800128: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x80800128: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x8080012C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80800130: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80800134: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800138: lwc1        $f14, 0x18($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8080013C: jal         0x800F1214
    // 0x80800140: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800F1214(rdram, ctx);
        goto after_6;
    // 0x80800140: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_6:
    // 0x80800144: swc1        $f0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
    // 0x80800148: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x8080014C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800150: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80800154: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800158: jal         0x800EFE50
    // 0x8080015C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800EFE50(rdram, ctx);
        goto after_7;
    // 0x8080015C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x80800160: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3334, 0XD14) << 16);
    // 0x80800164: lwc1        $f16, 0xD14($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3334, 0XD14));
    // 0x80800168: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8080016C: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800170: jal         0x8001395C
    // 0x80800174: nop

    func_8001395C(rdram, ctx);
        goto after_8;
    // 0x80800174: nop

    after_8:
    // 0x80800178: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8080017C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800180: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80800184: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800188: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8080018C: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80800190: jal         0x80104580
    // 0x80800194: swc1        $f8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f8.u32l;
    func_80104580(rdram, ctx);
        goto after_9;
    // 0x80800194: swc1        $f8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f8.u32l;
    after_9:
    // 0x80800198: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8080019C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808001A8: c.eq.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl == ctx->f0.fl;
    // 0x808001AC: nop

    // 0x808001B0: bc1f        L_8080020C
    if (!c1cs) {
        // 0x808001B4: nop
    
            goto L_8080020C;
    }
    // 0x808001B4: nop

    // 0x808001B8: jal         0x800EFD24
    // 0x808001BC: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    func_800EFD24(rdram, ctx);
        goto after_10;
    // 0x808001BC: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    after_10:
    // 0x808001C0: jal         0x800EFD24
    // 0x808001C4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800EFD24(rdram, ctx);
        goto after_11;
    // 0x808001C4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_11:
    // 0x808001C8: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x808001CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808001D0: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x808001D4: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x808001D8: beq         $t0, $zero, L_808001EC
    if (ctx->r8 == 0) {
        // 0x808001DC: lui         $a2, 0x3F66
        ctx->r6 = S32(0X3F66 << 16);
            goto L_808001EC;
    }
    // 0x808001DC: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x808001E0: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808001E4: jal         0x800E1610
    // 0x808001E8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    func_800E1610(rdram, ctx);
        goto after_12;
    // 0x808001E8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    after_12:
L_808001EC:
    // 0x808001EC: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x808001F0: andi        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 & 0X2;
    // 0x808001F4: beq         $t2, $zero, L_80800204
    if (ctx->r10 == 0) {
        // 0x808001F8: nop
    
            goto L_80800204;
    }
    // 0x808001F8: nop

    // 0x808001FC: jal         0x80800C00
    // 0x80800200: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800C00_subaddietaxi(rdram, ctx);
        goto after_13;
    // 0x80800200: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
L_80800204:
    // 0x80800204: b           L_8080020C
    // 0x80800208: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080020C;
    // 0x80800208: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080020C:
    // 0x8080020C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800210: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800214: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800218: jr          $ra
    // 0x8080021C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8080021C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void bsdronegoto_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080044C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800450: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800454: lw          $t6, 0x194($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X194);
    // 0x80800458: beq         $t6, $zero, L_80800470
    if (ctx->r14 == 0) {
        // 0x8080045C: nop
    
            goto L_80800470;
    }
    // 0x8080045C: nop

    // 0x80800460: jal         0x80099B94
    // 0x80800464: nop

    func_80099B94(rdram, ctx);
        goto after_0;
    // 0x80800464: nop

    after_0:
    // 0x80800468: b           L_80800518
    // 0x8080046C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800518;
    // 0x8080046C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800470:
    // 0x80800470: jal         0x8009E6EC
    // 0x80800474: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_1;
    // 0x80800474: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800478: slti        $at, $v0, 0x90
    ctx->r1 = SIGNED(ctx->r2) < 0X90 ? 1 : 0;
    // 0x8080047C: bne         $at, $zero, L_808004A0
    if (ctx->r1 != 0) {
        // 0x80800480: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808004A0;
    }
    // 0x80800480: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800484: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800488: beq         $v0, $at, L_808004E0
    if (ctx->r2 == ctx->r1) {
        // 0x8080048C: addiu       $at, $zero, 0x96
        ctx->r1 = ADD32(0, 0X96);
            goto L_808004E0;
    }
    // 0x8080048C: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x80800490: beq         $v0, $at, L_808004E0
    if (ctx->r2 == ctx->r1) {
        // 0x80800494: nop
    
            goto L_808004E0;
    }
    // 0x80800494: nop

    // 0x80800498: b           L_8080050C
    // 0x8080049C: nop

        goto L_8080050C;
    // 0x8080049C: nop

L_808004A0:
    // 0x808004A0: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x808004A4: bne         $at, $zero, L_808004C0
    if (ctx->r1 != 0) {
        // 0x808004A8: addiu       $t7, $v0, -0x56
        ctx->r15 = ADD32(ctx->r2, -0X56);
            goto L_808004C0;
    }
    // 0x808004A8: addiu       $t7, $v0, -0x56
    ctx->r15 = ADD32(ctx->r2, -0X56);
    // 0x808004AC: addiu       $at, $zero, 0x8F
    ctx->r1 = ADD32(0, 0X8F);
    // 0x808004B0: beq         $v0, $at, L_808004F0
    if (ctx->r2 == ctx->r1) {
        // 0x808004B4: nop
    
            goto L_808004F0;
    }
    // 0x808004B4: nop

    // 0x808004B8: b           L_8080050C
    // 0x808004BC: nop

        goto L_8080050C;
    // 0x808004BC: nop

L_808004C0:
    // 0x808004C0: sltiu       $at, $t7, 0xE
    ctx->r1 = ctx->r15 < 0XE ? 1 : 0;
    // 0x808004C4: beq         $at, $zero, L_8080050C
    if (ctx->r1 == 0) {
        // 0x808004C8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8080050C;
    }
    // 0x808004C8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808004CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(180, 0X530) << 16);
    // 0x808004D0: addu        $at, $at, $t7
    gpr jr_addend_808004D8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808004D4: lw          $t7, 0x530($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(180, 0X530));
    // 0x808004D8: jr          $t7
    // 0x808004DC: nop

    switch (jr_addend_808004D8 >> 2) {
        case 0: goto L_808004E0; break;
        case 1: goto L_8080050C; break;
        case 2: goto L_8080050C; break;
        case 3: goto L_8080050C; break;
        case 4: goto L_8080050C; break;
        case 5: goto L_8080050C; break;
        case 6: goto L_8080050C; break;
        case 7: goto L_808004E0; break;
        case 8: goto L_8080050C; break;
        case 9: goto L_8080050C; break;
        case 10: goto L_8080050C; break;
        case 11: goto L_808004E0; break;
        case 12: goto L_808004E0; break;
        case 13: goto L_808004E0; break;
        default: switch_error(__func__, 0x808004D8, 0x80800530);
    }
    // 0x808004DC: nop

L_808004E0:
    // 0x808004E0: jal         0x80099B94
    // 0x808004E4: nop

    func_80099B94(rdram, ctx);
        goto after_2;
    // 0x808004E4: nop

    after_2:
    // 0x808004E8: b           L_80800518
    // 0x808004EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800518;
    // 0x808004EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004F0:
    // 0x808004F0: jal         0x80084DC0
    // 0x808004F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bamovegoto_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808004F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_3:
    // 0x808004F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808004FC: jal         0x8009E830
    // 0x80800500: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_4;
    // 0x80800500: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800504: b           L_80800518
    // 0x80800508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800518;
    // 0x80800508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080050C:
    // 0x8080050C: jal         0x80099AA8
    // 0x80800510: nop

    func_80099AA8(rdram, ctx);
        goto after_5;
    // 0x80800510: nop

    after_5:
    // 0x80800514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800518:
    // 0x80800518: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080051C: jr          $ra
    // 0x80800520: nop

    return;
    // 0x80800520: nop

    // 0x80800524: nop

    // 0x80800528: nop

    // 0x8080052C: nop

;}
RECOMP_FUNC void _suquiz_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A878: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A878);
    return;
    // 0x8008A87C: addi        $t0, $zero, 0x60
    ctx->r8 = ADD32(0, 0X60);
;}
RECOMP_FUNC void _chboggykidshome_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800866F0: syscall     355
    recomp_syscall_handler(rdram, ctx, 0x800866F0);
    return;
    // 0x800866F4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808040A8_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808040A8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808040AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808040B0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808040B4: jal         0x800D8FF8
    // 0x808040B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808040B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808040BC: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808040C0: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808040C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808040C8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x808040CC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808040D0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808040D4: bne         $t7, $at, L_80804304
    if (ctx->r15 != ctx->r1) {
        // 0x808040D8: swc1        $f6, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
            goto L_80804304;
    }
    // 0x808040D8: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x808040DC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808040E0: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x808040E4: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x808040E8: jal         0x800EFA20
    // 0x808040EC: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    func_800EFA20(rdram, ctx);
        goto after_1;
    // 0x808040EC: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x808040F0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808040F4: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x808040F8: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808040FC: jal         0x800EE780
    // 0x80804100: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_800EE780(rdram, ctx);
        goto after_2;
    // 0x80804100: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_2:
    // 0x80804104: lui         $a3, 0x2
    ctx->r7 = S32(0X2 << 16);
    // 0x80804108: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x8080410C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80804110: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80804114: jal         0x800C6A7C
    // 0x80804118: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800C6A7C(rdram, ctx);
        goto after_3;
    // 0x80804118: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x8080411C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80804120: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80804124: jal         0x800EE7F8
    // 0x80804128: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80804128: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_4:
    // 0x8080412C: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80804130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804134: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80804138: beq         $t8, $zero, L_808041A4
    if (ctx->r24 == 0) {
        // 0x8080413C: lui         $at, 0xC3C8
        ctx->r1 = S32(0XC3C8 << 16);
            goto L_808041A4;
    }
    // 0x8080413C: lui         $at, 0xC3C8
    ctx->r1 = S32(0XC3C8 << 16);
    // 0x80804140: jal         0x80086670
    // 0x80804144: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80804144: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_5:
    // 0x80804148: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x8080414C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80804150: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80804154: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80804158: jal         0x800E1610
    // 0x8080415C: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    func_800E1610(rdram, ctx);
        goto after_6;
    // 0x8080415C: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    after_6:
    // 0x80804160: lbu         $t9, 0x7A($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7A);
    // 0x80804164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804168: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8080416C: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80804170: beq         $t0, $zero, L_80804194
    if (ctx->r8 == 0) {
        // 0x80804174: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1852, 0X5448) << 16);
            goto L_80804194;
    }
    // 0x80804174: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1852, 0X5448) << 16);
    // 0x80804178: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1852, 0X5794) << 16);
    // 0x8080417C: addiu       $a2, $a2, 0x5794
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1852, 0X5794));
    // 0x80804180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804184: jal         0x80089D18
    // 0x80804188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80804188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8080418C: b           L_808041CC
    // 0x80804190: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
        goto L_808041CC;
    // 0x80804190: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
L_80804194:
    // 0x80804194: jal         0x80089D18
    // 0x80804198: addiu       $a2, $a2, 0x5448
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1852, 0X5448));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80804198: addiu       $a2, $a2, 0x5448
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1852, 0X5448));
    after_8:
    // 0x8080419C: b           L_808041CC
    // 0x808041A0: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
        goto L_808041CC;
    // 0x808041A0: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
L_808041A4:
    // 0x808041A4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808041A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808041AC: nop

    // 0x808041B0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x808041B4: nop

    // 0x808041B8: bc1fl       L_808041CC
    if (!c1cs) {
        // 0x808041BC: addiu       $a1, $s0, 0x18
        ctx->r5 = ADD32(ctx->r16, 0X18);
            goto L_808041CC;
    }
    goto skip_0;
    // 0x808041BC: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    skip_0:
    // 0x808041C0: jal         0x80089CA8
    // 0x808041C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x808041C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808041C8: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
L_808041CC:
    // 0x808041CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808041D0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808041D4: jal         0x800EFA20
    // 0x808041D8: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    func_800EFA20(rdram, ctx);
        goto after_10;
    // 0x808041D8: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    after_10:
    // 0x808041DC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808041E0: jal         0x800EF04C
    // 0x808041E4: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    func_800EF04C(rdram, ctx);
        goto after_11;
    // 0x808041E4: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_11:
    // 0x808041E8: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808041EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808041F0: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808041F4: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x808041F8: nop

    // 0x808041FC: bc1fl       L_80804308
    if (!c1cs) {
        // 0x80804200: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80804308;
    }
    goto skip_1;
    // 0x80804200: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80804204: lbu         $t1, 0x7A($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X7A);
    // 0x80804208: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080420C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80804210: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80804214: bne         $t2, $zero, L_80804288
    if (ctx->r10 != 0) {
        // 0x80804218: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_80804288;
    }
    // 0x80804218: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8080421C: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(1852, 0X57A8) << 16);
    // 0x80804220: addiu       $t3, $t3, 0x57A8
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(1852, 0X57A8));
    // 0x80804224: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80804228: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8080422C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80804230: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80804234: jal         0x800BBCB8
    // 0x80804238: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_12;
    // 0x80804238: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_12:
    // 0x8080423C: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    // 0x80804240: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X534C) << 16);
    // 0x80804244: sll         $t6, $t4, 11
    ctx->r14 = S32(ctx->r12 << 11);
    // 0x80804248: bltzl       $t6, L_80804308
    if (SIGNED(ctx->r14) < 0) {
        // 0x8080424C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80804308;
    }
    goto skip_2;
    // 0x8080424C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80804250: lwc1        $f4, 0x534C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X534C));
    // 0x80804254: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80804258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080425C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80804260: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80804264: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1852, 0X5460) << 16);
    // 0x80804268: bc1fl       L_80804308
    if (!c1cs) {
        // 0x8080426C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80804308;
    }
    goto skip_3;
    // 0x8080426C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80804270: jal         0x80089D18
    // 0x80804274: addiu       $a2, $a2, 0x5460
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1852, 0X5460));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_13;
    // 0x80804274: addiu       $a2, $a2, 0x5460
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1852, 0X5460));
    after_13:
    // 0x80804278: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x8080427C: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x80804280: b           L_80804304
    // 0x80804284: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
        goto L_80804304;
    // 0x80804284: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
L_80804288:
    // 0x80804288: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1852, 0X57E0) << 16);
    // 0x8080428C: addiu       $t0, $t0, 0x57E0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1852, 0X57E0));
    // 0x80804290: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80804294: jal         0x800BBCB8
    // 0x80804298: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_800BBCB8(rdram, ctx);
        goto after_14;
    // 0x80804298: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_14:
    // 0x8080429C: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1852, 0X5810) << 16);
    // 0x808042A0: addiu       $t1, $t1, 0x5810
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1852, 0X5810));
    // 0x808042A4: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x808042A8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808042AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808042B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808042B4: jal         0x800BBCB8
    // 0x808042B8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800BBCB8(rdram, ctx);
        goto after_15;
    // 0x808042B8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_15:
    // 0x808042BC: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x808042C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X5350) << 16);
    // 0x808042C4: sll         $t4, $t2, 11
    ctx->r12 = S32(ctx->r10 << 11);
    // 0x808042C8: bltzl       $t4, L_80804308
    if (SIGNED(ctx->r12) < 0) {
        // 0x808042CC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80804308;
    }
    goto skip_4;
    // 0x808042CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x808042D0: lwc1        $f8, 0x5350($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X5350));
    // 0x808042D4: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808042D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808042DC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808042E0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x808042E4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1852, 0X5474) << 16);
    // 0x808042E8: bc1fl       L_80804308
    if (!c1cs) {
        // 0x808042EC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80804308;
    }
    goto skip_5;
    // 0x808042EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x808042F0: jal         0x80089D18
    // 0x808042F4: addiu       $a2, $a2, 0x5474
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1852, 0X5474));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_16;
    // 0x808042F4: addiu       $a2, $a2, 0x5474
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1852, 0X5474));
    after_16:
    // 0x808042F8: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x808042FC: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x80804300: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
L_80804304:
    // 0x80804304: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80804308:
    // 0x80804308: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080430C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80804310: jr          $ra
    // 0x80804314: nop

    return;
    // 0x80804314: nop

;}
RECOMP_FUNC void bastatetimer_get(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091538: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x8009153C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80091540: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x80091544: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80091548: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8009154C: jr          $ra
    // 0x80091550: lwc1        $f0, 0x0($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X0);
    return;
    // 0x80091550: lwc1        $f0, 0x0($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X0);
;}
RECOMP_FUNC void suspline_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800198: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8080019C: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x808001A0: jr          $ra
    // 0x808001A4: lwc1        $f0, 0x30($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X30);
    return;
    // 0x808001A4: lwc1        $f0, 0x30($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X30);
;}
RECOMP_FUNC void func_80800258_suautobaddies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800258: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080025C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800260: jal         0x800DA298
    // 0x80800264: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800264: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    after_0:
    // 0x80800268: beql        $v0, $zero, L_8080028C
    if (ctx->r2 == 0) {
        // 0x8080026C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080028C;
    }
    goto skip_0;
    // 0x8080026C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800270: jal         0x800DB9B0
    // 0x80800274: nop

    func_800DB9B0(rdram, ctx);
        goto after_1;
    // 0x80800274: nop

    after_1:
    // 0x80800278: beql        $v0, $zero, L_8080028C
    if (ctx->r2 == 0) {
        // 0x8080027C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080028C;
    }
    goto skip_1;
    // 0x8080027C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800280: jal         0x8008A890
    // 0x80800284: nop

    _suquiz_entrypoint_27(rdram, ctx);
        goto after_2;
    // 0x80800284: nop

    after_2:
    // 0x80800288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080028C:
    // 0x8080028C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800290: jr          $ra
    // 0x80800294: nop

    return;
    // 0x80800294: nop

;}
RECOMP_FUNC void func_80802058_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802058: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080205C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802060: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80802064: jal         0x80802218
    // 0x80802068: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80802218_chaliendad(rdram, ctx);
        goto after_0;
    // 0x80802068: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080206C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80802070: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80802074: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80802078: beq         $t6, $at, L_80802098
    if (ctx->r14 == ctx->r1) {
        // 0x8080207C: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80802098;
    }
    // 0x8080207C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80802080: beq         $t6, $at, L_8080216C
    if (ctx->r14 == ctx->r1) {
        // 0x80802084: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8080216C;
    }
    // 0x80802084: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80802088: beq         $t6, $at, L_80802108
    if (ctx->r14 == ctx->r1) {
        // 0x8080208C: nop
    
            goto L_80802108;
    }
    // 0x8080208C: nop

    // 0x80802090: b           L_8080216C
    // 0x80802094: nop

        goto L_8080216C;
    // 0x80802094: nop

L_80802098:
    // 0x80802098: jal         0x800D9078
    // 0x8080209C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x8080209C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x808020A0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808020A4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808020A8: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808020AC: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    // 0x808020B0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808020B4: jal         0x800F12D4
    // 0x808020B8: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F12D4(rdram, ctx);
        goto after_2;
    // 0x808020B8: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x808020BC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808020C0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808020C4: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x808020C8: jal         0x800EFE50
    // 0x808020CC: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    func_800EFE50(rdram, ctx);
        goto after_3;
    // 0x808020CC: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    after_3:
    // 0x808020D0: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x808020D4: beq         $t7, $zero, L_8080216C
    if (ctx->r15 == 0) {
        // 0x808020D8: nop
    
            goto L_8080216C;
    }
    // 0x808020D8: nop

    // 0x808020DC: lw          $a2, 0x6C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X6C);
    // 0x808020E0: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    // 0x808020E4: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x808020E8: sll         $t8, $a2, 11
    ctx->r24 = S32(ctx->r6 << 11);
    // 0x808020EC: jal         0x80101180
    // 0x808020F0: srl         $a2, $t8, 20
    ctx->r6 = S32(U32(ctx->r24) >> 20);
    func_80101180(rdram, ctx);
        goto after_4;
    // 0x808020F0: srl         $a2, $t8, 20
    ctx->r6 = S32(U32(ctx->r24) >> 20);
    after_4:
    // 0x808020F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808020F8: jal         0x80102424
    // 0x808020FC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x808020FC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_5:
    // 0x80802100: b           L_8080216C
    // 0x80802104: nop

        goto L_8080216C;
    // 0x80802104: nop

L_80802108:
    // 0x80802108: jal         0x800D9078
    // 0x8080210C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_6;
    // 0x8080210C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_6:
    // 0x80802110: jal         0x800D8FF8
    // 0x80802114: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_7;
    // 0x80802114: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_7:
    // 0x80802118: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8080211C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802120: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80802124: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80802128: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8080212C: jal         0x800D8FF8
    // 0x80802130: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_8;
    // 0x80802130: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    after_8:
    // 0x80802134: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80802138: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080213C: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    // 0x80802140: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80802144: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x80802148: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8080214C: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80802150: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80802154: beq         $t0, $zero, L_8080216C
    if (ctx->r8 == 0) {
        // 0x80802158: nop
    
            goto L_8080216C;
    }
    // 0x80802158: nop

    // 0x8080215C: jal         0x80101180
    // 0x80802160: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_9;
    // 0x80802160: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x80802164: jal         0x800FFAB0
    // 0x80802168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_10;
    // 0x80802168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_8080216C:
    // 0x8080216C: jal         0x80802284
    // 0x80802170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802284_chaliendad(rdram, ctx);
        goto after_11;
    // 0x80802170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80802174: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80802178: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080217C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80802180: jr          $ra
    // 0x80802184: nop

    return;
    // 0x80802184: nop

;}
