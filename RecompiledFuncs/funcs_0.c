#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80106C4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106C4C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80106C50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80106C54: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80106C58: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80106C5C: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x80106C60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80106C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80106C68: sll         $t8, $t6, 30
    ctx->r24 = S32(ctx->r14 << 30);
    // 0x80106C6C: bltz        $t8, L_80106C7C
    if (SIGNED(ctx->r24) < 0) {
        // 0x80106C70: nop
    
            goto L_80106C7C;
    }
    // 0x80106C70: nop

    // 0x80106C74: b           L_80106D4C
    // 0x80106C78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80106D4C;
    // 0x80106C78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80106C7C:
    // 0x80106C7C: jal         0x80089CD8
    // 0x80106C80: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    _subaddiefade_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80106C80: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_0:
    // 0x80106C84: jal         0x80106C08
    // 0x80106C88: nop

    func_80106C08(rdram, ctx);
        goto after_1;
    // 0x80106C88: nop

    after_1:
    // 0x80106C8C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80106C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80106C94: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80106C98: jal         0x80106D60
    // 0x80106C9C: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    func_80106D60(rdram, ctx);
        goto after_2;
    // 0x80106C9C: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_2:
    // 0x80106CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80106CA4: jal         0x80103F38
    // 0x80106CA8: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_80103F38(rdram, ctx);
        goto after_3;
    // 0x80106CA8: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_3:
    // 0x80106CAC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80106CB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80106CB4: jal         0x800B3494
    // 0x80106CB8: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_800B3494(rdram, ctx);
        goto after_4;
    // 0x80106CB8: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_4:
    // 0x80106CBC: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80106CC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80106CC4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80106CC8: jal         0x800B37A4
    // 0x80106CCC: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    func_800B37A4(rdram, ctx);
        goto after_5;
    // 0x80106CCC: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_5:
    // 0x80106CD0: lbu         $t0, 0x7B($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X7B);
    // 0x80106CD4: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80106CD8: srl         $t1, $t0, 6
    ctx->r9 = S32(U32(ctx->r8) >> 6);
    // 0x80106CDC: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80106CE0: beql        $at, $zero, L_80106D4C
    if (ctx->r1 == 0) {
        // 0x80106CE4: or          $v0, $s1, $zero
        ctx->r2 = ctx->r17 | 0;
            goto L_80106D4C;
    }
    goto skip_0;
    // 0x80106CE4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    skip_0:
    // 0x80106CE8: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x80106CEC: addiu       $s0, $sp, 0x2C
    ctx->r16 = ADD32(ctx->r29, 0X2C);
    // 0x80106CF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80106CF4: sll         $t4, $t2, 25
    ctx->r12 = S32(ctx->r10 << 25);
    // 0x80106CF8: bgezl       $t4, L_80106D4C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80106CFC: or          $v0, $s1, $zero
        ctx->r2 = ctx->r17 | 0;
            goto L_80106D4C;
    }
    goto skip_1;
    // 0x80106CFC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    skip_1:
    // 0x80106D00: jal         0x800C8960
    // 0x80106D04: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800C8960(rdram, ctx);
        goto after_6;
    // 0x80106D04: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_6:
    // 0x80106D08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80106D0C: jal         0x80106DA4
    // 0x80106D10: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_80106DA4(rdram, ctx);
        goto after_7;
    // 0x80106D10: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_7:
    // 0x80106D14: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x80106D18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80106D1C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80106D20: beq         $t5, $zero, L_80106D34
    if (ctx->r13 == 0) {
        // 0x80106D24: lui         $at, 0x43FA
        ctx->r1 = S32(0X43FA << 16);
            goto L_80106D34;
    }
    // 0x80106D24: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80106D28: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80106D2C: b           L_80106D3C
    // 0x80106D30: lwc1        $f0, 0x18($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X18);
        goto L_80106D3C;
    // 0x80106D30: lwc1        $f0, 0x18($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X18);
L_80106D34:
    // 0x80106D34: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80106D38: nop

L_80106D3C:
    // 0x80106D3C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80106D40: jal         0x800B36C0
    // 0x80106D44: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800B36C0(rdram, ctx);
        goto after_8;
    // 0x80106D44: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_8:
    // 0x80106D48: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_80106D4C:
    // 0x80106D4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80106D50: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80106D54: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80106D58: jr          $ra
    // 0x80106D5C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80106D5C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8008B2AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B2AC: jr          $ra
    // 0x8008B2B0: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    return;
    // 0x8008B2B0: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
;}
RECOMP_FUNC void func_80800514_chpawnbroker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800514: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800518: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080051C: jal         0x800897C8
    // 0x80800520: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80800520: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800528: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080052C: jr          $ra
    // 0x80800530: nop

    return;
    // 0x80800530: nop

;}
RECOMP_FUNC void func_80800C18_chamazongoldhordeofficial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C20: jal         0x800F54E4
    // 0x80800C24: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800C24: nop

    after_0:
    // 0x80800C28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C2C: jal         0x800F640C
    // 0x80800C30: addiu       $a1, $zero, 0x1D9
    ctx->r5 = ADD32(0, 0X1D9);
    func_800F640C(rdram, ctx);
        goto after_1;
    // 0x80800C30: addiu       $a1, $zero, 0x1D9
    ctx->r5 = ADD32(0, 0X1D9);
    after_1:
    // 0x80800C34: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800C38: bne         $t6, $zero, L_80800C50
    if (ctx->r14 != 0) {
        // 0x80800C3C: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800C50;
    }
    // 0x80800C3C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800C40: jal         0x8008FE14
    // 0x80800C44: nop

    func_8008FE14(rdram, ctx);
        goto after_2;
    // 0x80800C44: nop

    after_2:
    // 0x80800C48: xori        $t7, $v0, 0x1D9
    ctx->r15 = ctx->r2 ^ 0X1D9;
    // 0x80800C4C: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
L_80800C50:
    // 0x80800C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C58: jr          $ra
    // 0x80800C5C: nop

    return;
    // 0x80800C5C: nop

;}
RECOMP_FUNC void glpackvtx_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001C4: jal         0x8001B084
    // 0x808001C8: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x808001C8: nop

    after_0:
    // 0x808001CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001D4: jr          $ra
    // 0x808001D8: nop

    return;
    // 0x808001D8: nop

    // 0x808001DC: nop

;}
RECOMP_FUNC void func_808001A8_bsbanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001B0: jal         0x80800104
    // 0x808001B4: nop

    func_80800104_bsbanswim(rdram, ctx);
        goto after_0;
    // 0x808001B4: nop

    after_0:
    // 0x808001B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001C0: jr          $ra
    // 0x808001C4: nop

    return;
    // 0x808001C4: nop

;}
RECOMP_FUNC void func_8011113C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011113C: jr          $ra
    // 0x80111140: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80111140: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void _chbottlesplantgrill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086788: syscall     371
    recomp_syscall_handler(rdram, ctx, 0x80086788);
    return;
    // 0x8008678C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _badeathmatch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800854F8: syscall     165
    recomp_syscall_handler(rdram, ctx, 0x800854F8);
    return;
    // 0x800854FC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80115C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115C40: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
    // 0x80115C44: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80115C48: lbu         $t6, 0x11($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X11);
    // 0x80115C4C: beql        $t6, $zero, L_80115C6C
    if (ctx->r14 == 0) {
        // 0x80115C50: lbu         $t7, 0x12($v0)
        ctx->r15 = MEM_BU(ctx->r2, 0X12);
            goto L_80115C6C;
    }
    goto skip_0;
    // 0x80115C50: lbu         $t7, 0x12($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X12);
    skip_0:
    // 0x80115C54: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80115C58: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80115C5C: nop

    // 0x80115C60: bc1t        L_80115C9C
    if (c1cs) {
        // 0x80115C64: nop
    
            goto L_80115C9C;
    }
    // 0x80115C64: nop

    // 0x80115C68: lbu         $t7, 0x12($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X12);
L_80115C6C:
    // 0x80115C6C: beql        $t7, $zero, L_80115C90
    if (ctx->r15 == 0) {
        // 0x80115C70: swc1        $f12, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
            goto L_80115C90;
    }
    goto skip_1;
    // 0x80115C70: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    skip_1:
    // 0x80115C74: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80115C78: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80115C7C: nop

    // 0x80115C80: bc1fl       L_80115C90
    if (!c1cs) {
        // 0x80115C84: swc1        $f12, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
            goto L_80115C90;
    }
    goto skip_2;
    // 0x80115C84: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    skip_2:
    // 0x80115C88: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80115C8C: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
L_80115C90:
    // 0x80115C90: lw          $t9, 0x3C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X3C);
    // 0x80115C94: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80115C98: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
L_80115C9C:
    // 0x80115C9C: jr          $ra
    // 0x80115CA0: nop

    return;
    // 0x80115CA0: nop

;}
RECOMP_FUNC void func_8008EF3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008EF3C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008EF40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008EF44: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8008EF48: jal         0x8009E6F8
    // 0x8008EF4C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    bs_getCurrentState(rdram, ctx);
        goto after_0;
    // 0x8008EF4C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008EF50: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008EF54: jal         0x800A3274
    // 0x8008EF58: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800A3274(rdram, ctx);
        goto after_1;
    // 0x8008EF58: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x8008EF5C: addiu       $t6, $v0, -0x2
    ctx->r14 = ADD32(ctx->r2, -0X2);
    // 0x8008EF60: sltiu       $at, $t6, 0x12
    ctx->r1 = ctx->r14 < 0X12 ? 1 : 0;
    // 0x8008EF64: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8008EF68: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8008EF6C: beq         $at, $zero, L_8008F1CC
    if (ctx->r1 == 0) {
        // 0x8008EF70: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_8008F1CC;
    }
    // 0x8008EF70: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8008EF74: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8008EF78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EF7C: addu        $at, $at, $t6
    gpr jr_addend_8008EF84 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8008EF80: lw          $t6, 0x4B80($at)
    ctx->r14 = ADD32(ctx->r1, 0X4B80);
    // 0x8008EF84: jr          $t6
    // 0x8008EF88: nop

    switch (jr_addend_8008EF84 >> 2) {
        case 0: goto L_8008EF8C; break;
        case 1: goto L_8008F1CC; break;
        case 2: goto L_8008F1CC; break;
        case 3: goto L_8008F1CC; break;
        case 4: goto L_8008F1CC; break;
        case 5: goto L_8008F1CC; break;
        case 6: goto L_8008F1CC; break;
        case 7: goto L_8008F120; break;
        case 8: goto L_8008F1CC; break;
        case 9: goto L_8008F06C; break;
        case 10: goto L_8008F1CC; break;
        case 11: goto L_8008EFAC; break;
        case 12: goto L_8008EFDC; break;
        case 13: goto L_8008F034; break;
        case 14: goto L_8008F064; break;
        case 15: goto L_8008F1CC; break;
        case 16: goto L_8008F164; break;
        case 17: goto L_8008F198; break;
        default: switch_error(__func__, 0x8008EF84, 0x80124B80);
    }
    // 0x8008EF88: nop

L_8008EF8C:
    // 0x8008EF8C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8008EF90: jal         0x80095738
    // 0x8008EF94: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    baflag_isTrue(rdram, ctx);
        goto after_2;
    // 0x8008EF94: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_2:
    // 0x8008EF98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008EF9C: jal         0x8008EE04
    // 0x8008EFA0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_8008EE04(rdram, ctx);
        goto after_3;
    // 0x8008EFA0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_3:
    // 0x8008EFA4: b           L_8008F4E4
    // 0x8008EFA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008F4E4;
    // 0x8008EFA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008EFAC:
    // 0x8008EFAC: addiu       $at, $zero, 0xF7
    ctx->r1 = ADD32(0, 0XF7);
    // 0x8008EFB0: bne         $v1, $at, L_8008EFD4
    if (ctx->r3 != ctx->r1) {
        // 0x8008EFB4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8008EFD4;
    }
    // 0x8008EFB4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8008EFB8: jal         0x80095738
    // 0x8008EFBC: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    baflag_isTrue(rdram, ctx);
        goto after_4;
    // 0x8008EFBC: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_4:
    // 0x8008EFC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008EFC4: jal         0x8008EE04
    // 0x8008EFC8: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_8008EE04(rdram, ctx);
        goto after_5;
    // 0x8008EFC8: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_5:
    // 0x8008EFCC: b           L_8008F4E4
    // 0x8008EFD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008F4E4;
    // 0x8008EFD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008EFD4:
    // 0x8008EFD4: b           L_8008F4E0
    // 0x8008EFD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008F4E0;
    // 0x8008EFD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008EFDC:
    // 0x8008EFDC: addiu       $at, $zero, 0xFC
    ctx->r1 = ADD32(0, 0XFC);
    // 0x8008EFE0: bne         $v1, $at, L_8008F004
    if (ctx->r3 != ctx->r1) {
        // 0x8008EFE4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8008F004;
    }
    // 0x8008EFE4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8008EFE8: jal         0x80095738
    // 0x8008EFEC: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    baflag_isTrue(rdram, ctx);
        goto after_6;
    // 0x8008EFEC: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    after_6:
    // 0x8008EFF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008EFF4: jal         0x8008EE04
    // 0x8008EFF8: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_8008EE04(rdram, ctx);
        goto after_7;
    // 0x8008EFF8: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_7:
    // 0x8008EFFC: b           L_8008F4E4
    // 0x8008F000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008F4E4;
    // 0x8008F000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008F004:
    // 0x8008F004: addiu       $at, $zero, 0xFB
    ctx->r1 = ADD32(0, 0XFB);
    // 0x8008F008: bne         $v1, $at, L_8008F02C
    if (ctx->r3 != ctx->r1) {
        // 0x8008F00C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8008F02C;
    }
    // 0x8008F00C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8008F010: jal         0x80095738
    // 0x8008F014: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    baflag_isTrue(rdram, ctx);
        goto after_8;
    // 0x8008F014: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    after_8:
    // 0x8008F018: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F01C: jal         0x8008EE04
    // 0x8008F020: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8008EE04(rdram, ctx);
        goto after_9;
    // 0x8008F020: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_9:
    // 0x8008F024: b           L_8008F4E4
    // 0x8008F028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008F4E4;
    // 0x8008F028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008F02C:
    // 0x8008F02C: b           L_8008F4E0
    // 0x8008F030: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008F4E0;
    // 0x8008F030: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F034:
    // 0x8008F034: addiu       $at, $zero, 0x10E
    ctx->r1 = ADD32(0, 0X10E);
    // 0x8008F038: bne         $v1, $at, L_8008F05C
    if (ctx->r3 != ctx->r1) {
        // 0x8008F03C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8008F05C;
    }
    // 0x8008F03C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8008F040: jal         0x80095738
    // 0x8008F044: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    baflag_isTrue(rdram, ctx);
        goto after_10;
    // 0x8008F044: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_10:
    // 0x8008F048: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F04C: jal         0x8008EE04
    // 0x8008F050: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_8008EE04(rdram, ctx);
        goto after_11;
    // 0x8008F050: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_11:
    // 0x8008F054: b           L_8008F4E4
    // 0x8008F058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008F4E4;
    // 0x8008F058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008F05C:
    // 0x8008F05C: b           L_8008F4E0
    // 0x8008F060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008F4E0;
    // 0x8008F060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F064:
    // 0x8008F064: b           L_8008F4E0
    // 0x8008F068: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
        goto L_8008F4E0;
    // 0x8008F068: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_8008F06C:
    // 0x8008F06C: addiu       $at, $zero, 0xC2
    ctx->r1 = ADD32(0, 0XC2);
    // 0x8008F070: beq         $v1, $at, L_8008F09C
    if (ctx->r3 == ctx->r1) {
        // 0x8008F074: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8008F09C;
    }
    // 0x8008F074: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8008F078: addiu       $at, $zero, 0xC4
    ctx->r1 = ADD32(0, 0XC4);
    // 0x8008F07C: beq         $v1, $at, L_8008F09C
    if (ctx->r3 == ctx->r1) {
        // 0x8008F080: addiu       $at, $zero, 0x18A
        ctx->r1 = ADD32(0, 0X18A);
            goto L_8008F09C;
    }
    // 0x8008F080: addiu       $at, $zero, 0x18A
    ctx->r1 = ADD32(0, 0X18A);
    // 0x8008F084: beq         $v1, $at, L_8008F0B8
    if (ctx->r3 == ctx->r1) {
        // 0x8008F088: addiu       $at, $zero, 0x18B
        ctx->r1 = ADD32(0, 0X18B);
            goto L_8008F0B8;
    }
    // 0x8008F088: addiu       $at, $zero, 0x18B
    ctx->r1 = ADD32(0, 0X18B);
    // 0x8008F08C: beq         $v1, $at, L_8008F0B8
    if (ctx->r3 == ctx->r1) {
        // 0x8008F090: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8008F0B8;
    }
    // 0x8008F090: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8008F094: b           L_8008F0C0
    // 0x8008F098: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
        goto L_8008F0C0;
    // 0x8008F098: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
L_8008F09C:
    // 0x8008F09C: jal         0x80095738
    // 0x8008F0A0: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    baflag_isTrue(rdram, ctx);
        goto after_12;
    // 0x8008F0A0: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    after_12:
    // 0x8008F0A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F0A8: jal         0x8008EE04
    // 0x8008F0AC: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_8008EE04(rdram, ctx);
        goto after_13;
    // 0x8008F0AC: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_13:
    // 0x8008F0B0: b           L_8008F4E4
    // 0x8008F0B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008F4E4;
    // 0x8008F0B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008F0B8:
    // 0x8008F0B8: b           L_8008F4E0
    // 0x8008F0BC: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
        goto L_8008F4E0;
    // 0x8008F0BC: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
L_8008F0C0:
    // 0x8008F0C0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x8008F0C4: jal         0x80095738
    // 0x8008F0C8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    baflag_isTrue(rdram, ctx);
        goto after_14;
    // 0x8008F0C8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_14:
    // 0x8008F0CC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8008F0D0: beq         $v0, $zero, L_8008F118
    if (ctx->r2 == 0) {
        // 0x8008F0D4: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_8008F118;
    }
    // 0x8008F0D4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8008F0D8: beq         $a2, $zero, L_8008F110
    if (ctx->r6 == 0) {
        // 0x8008F0DC: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8008F110;
    }
    // 0x8008F0DC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8008F0E0: jal         0x80106790
    // 0x8008F0E4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_80106790(rdram, ctx);
        goto after_15;
    // 0x8008F0E4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_15:
    // 0x8008F0E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008F0EC: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x8008F0F0: jal         0x8008DC90
    // 0x8008F0F4: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    func_8008DC90(rdram, ctx);
        goto after_16;
    // 0x8008F0F4: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    after_16:
    // 0x8008F0F8: beq         $v0, $zero, L_8008F108
    if (ctx->r2 == 0) {
        // 0x8008F0FC: nop
    
            goto L_8008F108;
    }
    // 0x8008F0FC: nop

    // 0x8008F100: b           L_8008F4E0
    // 0x8008F104: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
        goto L_8008F4E0;
    // 0x8008F104: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_8008F108:
    // 0x8008F108: b           L_8008F4E0
    // 0x8008F10C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008F4E0;
    // 0x8008F10C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F110:
    // 0x8008F110: b           L_8008F4E0
    // 0x8008F114: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
        goto L_8008F4E0;
    // 0x8008F114: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_8008F118:
    // 0x8008F118: b           L_8008F4E0
    // 0x8008F11C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008F4E0;
    // 0x8008F11C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F120:
    // 0x8008F120: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8008F124: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    // 0x8008F128: jal         0x80095738
    // 0x8008F12C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    baflag_isTrue(rdram, ctx);
        goto after_17;
    // 0x8008F12C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_17:
    // 0x8008F130: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008F134: jal         0x8008E92C
    // 0x8008F138: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8008E92C(rdram, ctx);
        goto after_18;
    // 0x8008F138: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_18:
    // 0x8008F13C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8008F140: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8008F144: beq         $t7, $zero, L_8008F15C
    if (ctx->r15 == 0) {
        // 0x8008F148: nop
    
            goto L_8008F15C;
    }
    // 0x8008F148: nop

    // 0x8008F14C: beq         $t8, $zero, L_8008F15C
    if (ctx->r24 == 0) {
        // 0x8008F150: nop
    
            goto L_8008F15C;
    }
    // 0x8008F150: nop

    // 0x8008F154: b           L_8008F4E0
    // 0x8008F158: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
        goto L_8008F4E0;
    // 0x8008F158: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
L_8008F15C:
    // 0x8008F15C: b           L_8008F4E0
    // 0x8008F160: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008F4E0;
    // 0x8008F160: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F164:
    // 0x8008F164: beq         $a2, $zero, L_8008F190
    if (ctx->r6 == 0) {
        // 0x8008F168: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8008F190;
    }
    // 0x8008F168: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8008F16C: jal         0x80106790
    // 0x8008F170: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_80106790(rdram, ctx);
        goto after_19;
    // 0x8008F170: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_19:
    // 0x8008F174: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008F178: jal         0x800840B0
    // 0x8008F17C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    _bstrexsmall_entrypoint_7(rdram, ctx);
        goto after_20;
    // 0x8008F17C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_20:
    // 0x8008F180: beq         $v0, $zero, L_8008F190
    if (ctx->r2 == 0) {
        // 0x8008F184: nop
    
            goto L_8008F190;
    }
    // 0x8008F184: nop

    // 0x8008F188: b           L_8008F4E0
    // 0x8008F18C: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
        goto L_8008F4E0;
    // 0x8008F18C: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_8008F190:
    // 0x8008F190: b           L_8008F4E0
    // 0x8008F194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008F4E0;
    // 0x8008F194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F198:
    // 0x8008F198: beq         $a2, $zero, L_8008F1C4
    if (ctx->r6 == 0) {
        // 0x8008F19C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8008F1C4;
    }
    // 0x8008F19C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8008F1A0: jal         0x80106790
    // 0x8008F1A4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_80106790(rdram, ctx);
        goto after_21;
    // 0x8008F1A4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_21:
    // 0x8008F1A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008F1AC: jal         0x80084030
    // 0x8008F1B0: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    _bstrexlarge_entrypoint_7(rdram, ctx);
        goto after_22;
    // 0x8008F1B0: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_22:
    // 0x8008F1B4: beq         $v0, $zero, L_8008F1C4
    if (ctx->r2 == 0) {
        // 0x8008F1B8: nop
    
            goto L_8008F1C4;
    }
    // 0x8008F1B8: nop

    // 0x8008F1BC: b           L_8008F4E0
    // 0x8008F1C0: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_8008F4E0;
    // 0x8008F1C0: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_8008F1C4:
    // 0x8008F1C4: b           L_8008F4E0
    // 0x8008F1C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008F4E0;
    // 0x8008F1C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F1CC:
    // 0x8008F1CC: lw          $t9, 0x18($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X18);
    // 0x8008F1D0: slti        $at, $v1, 0xE5
    ctx->r1 = SIGNED(ctx->r3) < 0XE5 ? 1 : 0;
    // 0x8008F1D4: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x8008F1D8: beq         $t0, $zero, L_8008F1E8
    if (ctx->r8 == 0) {
        // 0x8008F1DC: nop
    
            goto L_8008F1E8;
    }
    // 0x8008F1DC: nop

    // 0x8008F1E0: b           L_8008F4E0
    // 0x8008F1E4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8008F4E0;
    // 0x8008F1E4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8008F1E8:
    // 0x8008F1E8: bne         $at, $zero, L_8008F218
    if (ctx->r1 != 0) {
        // 0x8008F1EC: addiu       $t2, $v1, -0x5
        ctx->r10 = ADD32(ctx->r3, -0X5);
            goto L_8008F218;
    }
    // 0x8008F1EC: addiu       $t2, $v1, -0x5
    ctx->r10 = ADD32(ctx->r3, -0X5);
    // 0x8008F1F0: addiu       $at, $zero, 0x124
    ctx->r1 = ADD32(0, 0X124);
    // 0x8008F1F4: beq         $v1, $at, L_8008F4B4
    if (ctx->r3 == ctx->r1) {
        // 0x8008F1F8: addiu       $at, $zero, 0x189
        ctx->r1 = ADD32(0, 0X189);
            goto L_8008F4B4;
    }
    // 0x8008F1F8: addiu       $at, $zero, 0x189
    ctx->r1 = ADD32(0, 0X189);
    // 0x8008F1FC: beq         $v1, $at, L_8008F280
    if (ctx->r3 == ctx->r1) {
        // 0x8008F200: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8008F280;
    }
    // 0x8008F200: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8008F204: addiu       $at, $zero, 0x18A
    ctx->r1 = ADD32(0, 0X18A);
    // 0x8008F208: beq         $v1, $at, L_8008F4D4
    if (ctx->r3 == ctx->r1) {
        // 0x8008F20C: nop
    
            goto L_8008F4D4;
    }
    // 0x8008F20C: nop

    // 0x8008F210: b           L_8008F4E0
    // 0x8008F214: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008F4E0;
    // 0x8008F214: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F218:
    // 0x8008F218: slti        $at, $v1, 0xB7
    ctx->r1 = SIGNED(ctx->r3) < 0XB7 ? 1 : 0;
    // 0x8008F21C: bne         $at, $zero, L_8008F238
    if (ctx->r1 != 0) {
        // 0x8008F220: addiu       $t1, $v1, -0xA4
        ctx->r9 = ADD32(ctx->r3, -0XA4);
            goto L_8008F238;
    }
    // 0x8008F220: addiu       $t1, $v1, -0xA4
    ctx->r9 = ADD32(ctx->r3, -0XA4);
    // 0x8008F224: addiu       $at, $zero, 0xE4
    ctx->r1 = ADD32(0, 0XE4);
    // 0x8008F228: beq         $v1, $at, L_8008F29C
    if (ctx->r3 == ctx->r1) {
        // 0x8008F22C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8008F29C;
    }
    // 0x8008F22C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8008F230: b           L_8008F4E0
    // 0x8008F234: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008F4E0;
    // 0x8008F234: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F238:
    // 0x8008F238: slti        $at, $v1, 0x3E
    ctx->r1 = SIGNED(ctx->r3) < 0X3E ? 1 : 0;
    // 0x8008F23C: bne         $at, $zero, L_8008F260
    if (ctx->r1 != 0) {
        // 0x8008F240: sltiu       $at, $t1, 0x13
        ctx->r1 = ctx->r9 < 0X13 ? 1 : 0;
            goto L_8008F260;
    }
    // 0x8008F240: sltiu       $at, $t1, 0x13
    ctx->r1 = ctx->r9 < 0X13 ? 1 : 0;
    // 0x8008F244: beq         $at, $zero, L_8008F4DC
    if (ctx->r1 == 0) {
        // 0x8008F248: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_8008F4DC;
    }
    // 0x8008F248: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8008F24C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F250: addu        $at, $at, $t1
    gpr jr_addend_8008F258 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8008F254: lw          $t1, 0x4BC8($at)
    ctx->r9 = ADD32(ctx->r1, 0X4BC8);
    // 0x8008F258: jr          $t1
    // 0x8008F25C: nop

    switch (jr_addend_8008F258 >> 2) {
        case 0: goto L_8008F410; break;
        case 1: goto L_8008F410; break;
        case 2: goto L_8008F4DC; break;
        case 3: goto L_8008F4DC; break;
        case 4: goto L_8008F4DC; break;
        case 5: goto L_8008F2B8; break;
        case 6: goto L_8008F4DC; break;
        case 7: goto L_8008F4DC; break;
        case 8: goto L_8008F4DC; break;
        case 9: goto L_8008F4DC; break;
        case 10: goto L_8008F4DC; break;
        case 11: goto L_8008F4DC; break;
        case 12: goto L_8008F4DC; break;
        case 13: goto L_8008F4DC; break;
        case 14: goto L_8008F4DC; break;
        case 15: goto L_8008F4DC; break;
        case 16: goto L_8008F320; break;
        case 17: goto L_8008F4DC; break;
        case 18: goto L_8008F2C0; break;
        default: switch_error(__func__, 0x8008F258, 0x80124BC8);
    }
    // 0x8008F25C: nop

L_8008F260:
    // 0x8008F260: sltiu       $at, $t2, 0x39
    ctx->r1 = ctx->r10 < 0X39 ? 1 : 0;
    // 0x8008F264: beq         $at, $zero, L_8008F4DC
    if (ctx->r1 == 0) {
        // 0x8008F268: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_8008F4DC;
    }
    // 0x8008F268: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008F26C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F270: addu        $at, $at, $t2
    gpr jr_addend_8008F278 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8008F274: lw          $t2, 0x4C14($at)
    ctx->r10 = ADD32(ctx->r1, 0X4C14);
    // 0x8008F278: jr          $t2
    // 0x8008F27C: nop

    switch (jr_addend_8008F278 >> 2) {
        case 0: goto L_8008F438; break;
        case 1: goto L_8008F360; break;
        case 2: goto L_8008F4DC; break;
        case 3: goto L_8008F4DC; break;
        case 4: goto L_8008F4DC; break;
        case 5: goto L_8008F4DC; break;
        case 6: goto L_8008F4DC; break;
        case 7: goto L_8008F4DC; break;
        case 8: goto L_8008F4DC; break;
        case 9: goto L_8008F4DC; break;
        case 10: goto L_8008F2E0; break;
        case 11: goto L_8008F4DC; break;
        case 12: goto L_8008F3C0; break;
        case 13: goto L_8008F4DC; break;
        case 14: goto L_8008F300; break;
        case 15: goto L_8008F4DC; break;
        case 16: goto L_8008F4DC; break;
        case 17: goto L_8008F4DC; break;
        case 18: goto L_8008F4DC; break;
        case 19: goto L_8008F4DC; break;
        case 20: goto L_8008F4DC; break;
        case 21: goto L_8008F410; break;
        case 22: goto L_8008F410; break;
        case 23: goto L_8008F410; break;
        case 24: goto L_8008F410; break;
        case 25: goto L_8008F410; break;
        case 26: goto L_8008F4DC; break;
        case 27: goto L_8008F4DC; break;
        case 28: goto L_8008F4DC; break;
        case 29: goto L_8008F4DC; break;
        case 30: goto L_8008F4DC; break;
        case 31: goto L_8008F4DC; break;
        case 32: goto L_8008F4DC; break;
        case 33: goto L_8008F4DC; break;
        case 34: goto L_8008F4DC; break;
        case 35: goto L_8008F4DC; break;
        case 36: goto L_8008F4DC; break;
        case 37: goto L_8008F340; break;
        case 38: goto L_8008F4DC; break;
        case 39: goto L_8008F4DC; break;
        case 40: goto L_8008F4DC; break;
        case 41: goto L_8008F4DC; break;
        case 42: goto L_8008F474; break;
        case 43: goto L_8008F4DC; break;
        case 44: goto L_8008F418; break;
        case 45: goto L_8008F4DC; break;
        case 46: goto L_8008F4DC; break;
        case 47: goto L_8008F4DC; break;
        case 48: goto L_8008F4DC; break;
        case 49: goto L_8008F4DC; break;
        case 50: goto L_8008F4DC; break;
        case 51: goto L_8008F4DC; break;
        case 52: goto L_8008F4DC; break;
        case 53: goto L_8008F4DC; break;
        case 54: goto L_8008F4DC; break;
        case 55: goto L_8008F4DC; break;
        case 56: goto L_8008F438; break;
        default: switch_error(__func__, 0x8008F278, 0x80124C14);
    }
    // 0x8008F27C: nop

L_8008F280:
    // 0x8008F280: jal         0x80095738
    // 0x8008F284: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    baflag_isTrue(rdram, ctx);
        goto after_23;
    // 0x8008F284: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_23:
    // 0x8008F288: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F28C: jal         0x8008EE04
    // 0x8008F290: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_8008EE04(rdram, ctx);
        goto after_24;
    // 0x8008F290: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_24:
    // 0x8008F294: b           L_8008F4E4
    // 0x8008F298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008F4E4;
    // 0x8008F298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008F29C:
    // 0x8008F29C: jal         0x80095738
    // 0x8008F2A0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    baflag_isTrue(rdram, ctx);
        goto after_25;
    // 0x8008F2A0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_25:
    // 0x8008F2A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F2A8: jal         0x8008EE04
    // 0x8008F2AC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_8008EE04(rdram, ctx);
        goto after_26;
    // 0x8008F2AC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_26:
    // 0x8008F2B0: b           L_8008F4E4
    // 0x8008F2B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008F4E4;
    // 0x8008F2B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008F2B8:
    // 0x8008F2B8: b           L_8008F4E0
    // 0x8008F2BC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_8008F4E0;
    // 0x8008F2BC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8008F2C0:
    // 0x8008F2C0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8008F2C4: jal         0x80095738
    // 0x8008F2C8: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    baflag_isTrue(rdram, ctx);
        goto after_27;
    // 0x8008F2C8: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_27:
    // 0x8008F2CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F2D0: jal         0x8008EE04
    // 0x8008F2D4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_8008EE04(rdram, ctx);
        goto after_28;
    // 0x8008F2D4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_28:
    // 0x8008F2D8: b           L_8008F4E4
    // 0x8008F2DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008F4E4;
    // 0x8008F2DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008F2E0:
    // 0x8008F2E0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8008F2E4: jal         0x80095738
    // 0x8008F2E8: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    baflag_isTrue(rdram, ctx);
        goto after_29;
    // 0x8008F2E8: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_29:
    // 0x8008F2EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F2F0: jal         0x8008EE04
    // 0x8008F2F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008EE04(rdram, ctx);
        goto after_30;
    // 0x8008F2F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x8008F2F8: b           L_8008F4E4
    // 0x8008F2FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008F4E4;
    // 0x8008F2FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008F300:
    // 0x8008F300: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8008F304: jal         0x80095738
    // 0x8008F308: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    baflag_isTrue(rdram, ctx);
        goto after_31;
    // 0x8008F308: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_31:
    // 0x8008F30C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F310: jal         0x8008EE04
    // 0x8008F314: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008EE04(rdram, ctx);
        goto after_32;
    // 0x8008F314: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_32:
    // 0x8008F318: b           L_8008F4E4
    // 0x8008F31C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008F4E4;
    // 0x8008F31C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008F320:
    // 0x8008F320: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8008F324: jal         0x80095738
    // 0x8008F328: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    baflag_isTrue(rdram, ctx);
        goto after_33;
    // 0x8008F328: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_33:
    // 0x8008F32C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F330: jal         0x8008EE04
    // 0x8008F334: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008EE04(rdram, ctx);
        goto after_34;
    // 0x8008F334: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_34:
    // 0x8008F338: b           L_8008F4E4
    // 0x8008F33C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008F4E4;
    // 0x8008F33C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008F340:
    // 0x8008F340: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8008F344: jal         0x80095738
    // 0x8008F348: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    baflag_isTrue(rdram, ctx);
        goto after_35;
    // 0x8008F348: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_35:
    // 0x8008F34C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F350: jal         0x8008EE04
    // 0x8008F354: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8008EE04(rdram, ctx);
        goto after_36;
    // 0x8008F354: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_36:
    // 0x8008F358: b           L_8008F4E4
    // 0x8008F35C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008F4E4;
    // 0x8008F35C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008F360:
    // 0x8008F360: beq         $a2, $zero, L_8008F390
    if (ctx->r6 == 0) {
        // 0x8008F364: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8008F390;
    }
    // 0x8008F364: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8008F368: jal         0x80106790
    // 0x8008F36C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_80106790(rdram, ctx);
        goto after_37;
    // 0x8008F36C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_37:
    // 0x8008F370: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008F374: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x8008F378: jal         0x8008DAE8
    // 0x8008F37C: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    func_8008DAE8(rdram, ctx);
        goto after_38;
    // 0x8008F37C: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    after_38:
    // 0x8008F380: bne         $v0, $zero, L_8008F390
    if (ctx->r2 != 0) {
        // 0x8008F384: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_8008F390;
    }
    // 0x8008F384: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8008F388: b           L_8008F4E0
    // 0x8008F38C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008F4E0;
    // 0x8008F38C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F390:
    // 0x8008F390: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8008F394: jal         0x80095738
    // 0x8008F398: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    baflag_isTrue(rdram, ctx);
        goto after_39;
    // 0x8008F398: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    after_39:
    // 0x8008F39C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F3A0: jal         0x8008EE04
    // 0x8008F3A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8008EE04(rdram, ctx);
        goto after_40;
    // 0x8008F3A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_40:
    // 0x8008F3A8: beq         $v0, $zero, L_8008F3B8
    if (ctx->r2 == 0) {
        // 0x8008F3AC: nop
    
            goto L_8008F3B8;
    }
    // 0x8008F3AC: nop

    // 0x8008F3B0: b           L_8008F4E4
    // 0x8008F3B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008F4E4;
    // 0x8008F3B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008F3B8:
    // 0x8008F3B8: b           L_8008F4E0
    // 0x8008F3BC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_8008F4E0;
    // 0x8008F3BC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_8008F3C0:
    // 0x8008F3C0: beq         $a2, $zero, L_8008F3F0
    if (ctx->r6 == 0) {
        // 0x8008F3C4: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8008F3F0;
    }
    // 0x8008F3C4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8008F3C8: jal         0x80106790
    // 0x8008F3CC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_80106790(rdram, ctx);
        goto after_41;
    // 0x8008F3CC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_41:
    // 0x8008F3D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008F3D4: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x8008F3D8: jal         0x8008DAE8
    // 0x8008F3DC: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    func_8008DAE8(rdram, ctx);
        goto after_42;
    // 0x8008F3DC: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    after_42:
    // 0x8008F3E0: bne         $v0, $zero, L_8008F3F0
    if (ctx->r2 != 0) {
        // 0x8008F3E4: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_8008F3F0;
    }
    // 0x8008F3E4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8008F3E8: b           L_8008F4E0
    // 0x8008F3EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008F4E0;
    // 0x8008F3EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F3F0:
    // 0x8008F3F0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8008F3F4: jal         0x80095738
    // 0x8008F3F8: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    baflag_isTrue(rdram, ctx);
        goto after_43;
    // 0x8008F3F8: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    after_43:
    // 0x8008F3FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F400: jal         0x8008EE04
    // 0x8008F404: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8008EE04(rdram, ctx);
        goto after_44;
    // 0x8008F404: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_44:
    // 0x8008F408: b           L_8008F4E4
    // 0x8008F40C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008F4E4;
    // 0x8008F40C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008F410:
    // 0x8008F410: b           L_8008F4E0
    // 0x8008F414: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_8008F4E0;
    // 0x8008F414: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8008F418:
    // 0x8008F418: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8008F41C: jal         0x80095738
    // 0x8008F420: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    baflag_isTrue(rdram, ctx);
        goto after_45;
    // 0x8008F420: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    after_45:
    // 0x8008F424: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F428: jal         0x8008EE04
    // 0x8008F42C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8008EE04(rdram, ctx);
        goto after_46;
    // 0x8008F42C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_46:
    // 0x8008F430: b           L_8008F4E4
    // 0x8008F434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008F4E4;
    // 0x8008F434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008F438:
    // 0x8008F438: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8008F43C: jal         0x8009BB50
    // 0x8008F440: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_47;
    // 0x8008F440: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_47:
    // 0x8008F444: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008F448: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8008F44C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8008F450: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8008F454: bc1fl       L_8008F478
    if (!c1cs) {
        // 0x8008F458: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8008F478;
    }
    goto skip_0;
    // 0x8008F458: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_0:
    // 0x8008F45C: jal         0x8008E078
    // 0x8008F460: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    player_isStable(rdram, ctx);
        goto after_48;
    // 0x8008F460: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_48:
    // 0x8008F464: bne         $v0, $zero, L_8008F474
    if (ctx->r2 != 0) {
        // 0x8008F468: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_8008F474;
    }
    // 0x8008F468: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8008F46C: b           L_8008F4E0
    // 0x8008F470: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_8008F4E0;
    // 0x8008F470: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_8008F474:
    // 0x8008F474: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_8008F478:
    // 0x8008F478: jal         0x8009BB50
    // 0x8008F47C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_49;
    // 0x8008F47C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_49:
    // 0x8008F480: lui         $at, 0xC4AF
    ctx->r1 = S32(0XC4AF << 16);
    // 0x8008F484: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008F488: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8008F48C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8008F490: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8008F494: bc1fl       L_8008F4B8
    if (!c1cs) {
        // 0x8008F498: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8008F4B8;
    }
    goto skip_1;
    // 0x8008F498: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_1:
    // 0x8008F49C: jal         0x8008E078
    // 0x8008F4A0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    player_isStable(rdram, ctx);
        goto after_50;
    // 0x8008F4A0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_50:
    // 0x8008F4A4: bne         $v0, $zero, L_8008F4B4
    if (ctx->r2 != 0) {
        // 0x8008F4A8: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_8008F4B4;
    }
    // 0x8008F4A8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8008F4AC: b           L_8008F4E0
    // 0x8008F4B0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_8008F4E0;
    // 0x8008F4B0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_8008F4B4:
    // 0x8008F4B4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_8008F4B8:
    // 0x8008F4B8: jal         0x80095738
    // 0x8008F4BC: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    baflag_isTrue(rdram, ctx);
        goto after_51;
    // 0x8008F4BC: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    after_51:
    // 0x8008F4C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F4C4: jal         0x8008EE04
    // 0x8008F4C8: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_8008EE04(rdram, ctx);
        goto after_52;
    // 0x8008F4C8: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_52:
    // 0x8008F4CC: b           L_8008F4E4
    // 0x8008F4D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008F4E4;
    // 0x8008F4D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008F4D4:
    // 0x8008F4D4: b           L_8008F4E0
    // 0x8008F4D8: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
        goto L_8008F4E0;
    // 0x8008F4D8: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
L_8008F4DC:
    // 0x8008F4DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F4E0:
    // 0x8008F4E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008F4E4:
    // 0x8008F4E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008F4E8: jr          $ra
    // 0x8008F4EC: nop

    return;
    // 0x8008F4EC: nop

;}
RECOMP_FUNC void _basub_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085180: syscall     154
    recomp_syscall_handler(rdram, ctx, 0x80085180);
    return;
    // 0x80085184: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void _ncbatarget_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800894B8: syscall     782
    recomp_syscall_handler(rdram, ctx, 0x800894B8);
    return;
    // 0x800894BC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_8080048C_chchuffyglow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080048C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800490: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800494: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800498: jal         0x80089C98
    // 0x8080049C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080049C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808004A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808004A4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808004A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808004AC: lbu         $t7, 0x65($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X65);
    // 0x808004B0: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    // 0x808004B4: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x808004B8: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
    // 0x808004BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004C4: jr          $ra
    // 0x808004C8: nop

    return;
    // 0x808004C8: nop

;}
RECOMP_FUNC void _bashoes_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084FE0: syscall     148
    recomp_syscall_handler(rdram, ctx, 0x80084FE0);
    return;
    // 0x80084FE4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bastick_setZoneMax(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F1C8: lw          $t6, 0x128($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X128);
    // 0x8009F1CC: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8009F1D0: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8009F1D4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8009F1D8: jr          $ra
    // 0x8009F1DC: swc1        $f12, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f12.u32l;
    return;
    // 0x8009F1DC: swc1        $f12, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_800E2554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2554: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E2558: addiu       $v0, $v0, -0x2B90
    ctx->r2 = ADD32(ctx->r2, -0X2B90);
    // 0x800E255C: swc1        $f12, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f12.u32l;
    // 0x800E2560: jr          $ra
    // 0x800E2564: swc1        $f14, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f14.u32l;
    return;
    // 0x800E2564: swc1        $f14, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_80800D3C_chcrusherboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800D40: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X131C) << 16);
    // 0x80800D44: lwc1        $f4, 0x131C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1640, 0X131C));
    // 0x80800D48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800D50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D54: jal         0x800EA05C
    // 0x80800D58: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800D58: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x80800D5C: addiu       $at, $zero, 0xCB
    ctx->r1 = ADD32(0, 0XCB);
    // 0x80800D60: bnel        $v0, $at, L_80800D7C
    if (ctx->r2 != ctx->r1) {
        // 0x80800D64: lbu         $t9, 0x74($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X74);
            goto L_80800D7C;
    }
    goto skip_0;
    // 0x80800D64: lbu         $t9, 0x74($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X74);
    skip_0:
    // 0x80800D68: lbu         $t7, 0x74($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X74);
    // 0x80800D6C: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x80800D70: b           L_80800D84
    // 0x80800D74: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
        goto L_80800D84;
    // 0x80800D74: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
    // 0x80800D78: lbu         $t9, 0x74($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X74);
L_80800D7C:
    // 0x80800D7C: andi        $t0, $t9, 0xFFDF
    ctx->r8 = ctx->r25 & 0XFFDF;
    // 0x80800D80: sb          $t0, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r8;
L_80800D84:
    // 0x80800D84: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80800D88: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80800D8C: bgez        $t3, L_80800E44
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800D90: nop
    
            goto L_80800E44;
    }
    // 0x80800D90: nop

    // 0x80800D94: jal         0x800DA298
    // 0x80800D98: addiu       $a0, $zero, 0x4FF
    ctx->r4 = ADD32(0, 0X4FF);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800D98: addiu       $a0, $zero, 0x4FF
    ctx->r4 = ADD32(0, 0X4FF);
    after_1:
    // 0x80800D9C: bne         $v0, $zero, L_80800DB4
    if (ctx->r2 != 0) {
        // 0x80800DA0: nop
    
            goto L_80800DB4;
    }
    // 0x80800DA0: nop

    // 0x80800DA4: jal         0x800DA298
    // 0x80800DA8: addiu       $a0, $zero, 0x4FC
    ctx->r4 = ADD32(0, 0X4FC);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800DA8: addiu       $a0, $zero, 0x4FC
    ctx->r4 = ADD32(0, 0X4FC);
    after_2:
    // 0x80800DAC: bne         $v0, $zero, L_80800DC4
    if (ctx->r2 != 0) {
        // 0x80800DB0: nop
    
            goto L_80800DC4;
    }
    // 0x80800DB0: nop

L_80800DB4:
    // 0x80800DB4: jal         0x800FFAB0
    // 0x80800DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x80800DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800DBC: b           L_80800EC0
    // 0x80800DC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800EC0;
    // 0x80800DC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800DC4:
    // 0x80800DC4: jal         0x800DA298
    // 0x80800DC8: addiu       $a0, $zero, 0x4FC
    ctx->r4 = ADD32(0, 0X4FC);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800DC8: addiu       $a0, $zero, 0x4FC
    ctx->r4 = ADD32(0, 0X4FC);
    after_4:
    // 0x80800DCC: beql        $v0, $zero, L_80800EC0
    if (ctx->r2 == 0) {
        // 0x80800DD0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800EC0;
    }
    goto skip_1;
    // 0x80800DD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800DD4: jal         0x800DA298
    // 0x80800DD8: addiu       $a0, $zero, 0x4FD
    ctx->r4 = ADD32(0, 0X4FD);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80800DD8: addiu       $a0, $zero, 0x4FD
    ctx->r4 = ADD32(0, 0X4FD);
    after_5:
    // 0x80800DDC: beq         $v0, $zero, L_80800DF4
    if (ctx->r2 == 0) {
        // 0x80800DE0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800DF4;
    }
    // 0x80800DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DE4: jal         0x80800A1C
    // 0x80800DE8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800A1C_chcrusherboulder(rdram, ctx);
        goto after_6;
    // 0x80800DE8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_6:
    // 0x80800DEC: b           L_80800EC0
    // 0x80800DF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800EC0;
    // 0x80800DF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800DF4:
    // 0x80800DF4: jal         0x800DA298
    // 0x80800DF8: addiu       $a0, $zero, 0x4FB
    ctx->r4 = ADD32(0, 0X4FB);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800DF8: addiu       $a0, $zero, 0x4FB
    ctx->r4 = ADD32(0, 0X4FB);
    after_7:
    // 0x80800DFC: beq         $v0, $zero, L_80800E20
    if (ctx->r2 == 0) {
        // 0x80800E00: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800E20;
    }
    // 0x80800E00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800E04: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800E08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800E0C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800E10: jal         0x80085708
    // 0x80800E14: addiu       $a3, $zero, 0x2820
    ctx->r7 = ADD32(0, 0X2820);
    _capod_entrypoint_13(rdram, ctx);
        goto after_8;
    // 0x80800E14: addiu       $a3, $zero, 0x2820
    ctx->r7 = ADD32(0, 0X2820);
    after_8:
    // 0x80800E18: b           L_80800E34
    // 0x80800E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800E34;
    // 0x80800E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800E20:
    // 0x80800E20: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800E24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800E28: jal         0x80085708
    // 0x80800E2C: addiu       $a3, $zero, 0x2820
    ctx->r7 = ADD32(0, 0X2820);
    _capod_entrypoint_13(rdram, ctx);
        goto after_9;
    // 0x80800E2C: addiu       $a3, $zero, 0x2820
    ctx->r7 = ADD32(0, 0X2820);
    after_9:
    // 0x80800E30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800E34:
    // 0x80800E34: jal         0x80800A1C
    // 0x80800E38: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800A1C_chcrusherboulder(rdram, ctx);
        goto after_10;
    // 0x80800E38: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x80800E3C: b           L_80800EC0
    // 0x80800E40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800EC0;
    // 0x80800E40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800E44:
    // 0x80800E44: jal         0x800DA298
    // 0x80800E48: addiu       $a0, $zero, 0x4FF
    ctx->r4 = ADD32(0, 0X4FF);
    func_800DA298(rdram, ctx);
        goto after_11;
    // 0x80800E48: addiu       $a0, $zero, 0x4FF
    ctx->r4 = ADD32(0, 0X4FF);
    after_11:
    // 0x80800E4C: beq         $v0, $zero, L_80800E84
    if (ctx->r2 == 0) {
        // 0x80800E50: addiu       $a0, $zero, 0x500
        ctx->r4 = ADD32(0, 0X500);
            goto L_80800E84;
    }
    // 0x80800E50: addiu       $a0, $zero, 0x500
    ctx->r4 = ADD32(0, 0X500);
    // 0x80800E54: jal         0x800DA9E4
    // 0x80800E58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_12;
    // 0x80800E58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800E5C: bne         $v0, $zero, L_80800E74
    if (ctx->r2 != 0) {
        // 0x80800E60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E74;
    }
    // 0x80800E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E64: jal         0x80800A1C
    // 0x80800E68: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80800A1C_chcrusherboulder(rdram, ctx);
        goto after_13;
    // 0x80800E68: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_13:
    // 0x80800E6C: b           L_80800EC0
    // 0x80800E70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800EC0;
    // 0x80800E70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800E74:
    // 0x80800E74: jal         0x800FFAB0
    // 0x80800E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_14;
    // 0x80800E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800E7C: b           L_80800EC0
    // 0x80800E80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800EC0;
    // 0x80800E80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800E84:
    // 0x80800E84: jal         0x800DA298
    // 0x80800E88: addiu       $a0, $zero, 0x4FC
    ctx->r4 = ADD32(0, 0X4FC);
    func_800DA298(rdram, ctx);
        goto after_15;
    // 0x80800E88: addiu       $a0, $zero, 0x4FC
    ctx->r4 = ADD32(0, 0X4FC);
    after_15:
    // 0x80800E8C: beq         $v0, $zero, L_80800EA4
    if (ctx->r2 == 0) {
        // 0x80800E90: nop
    
            goto L_80800EA4;
    }
    // 0x80800E90: nop

    // 0x80800E94: jal         0x800FFAB0
    // 0x80800E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_16;
    // 0x80800E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800E9C: b           L_80800EC0
    // 0x80800EA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800EC0;
    // 0x80800EA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800EA4:
    // 0x80800EA4: jal         0x800DA298
    // 0x80800EA8: addiu       $a0, $zero, 0x4FD
    ctx->r4 = ADD32(0, 0X4FD);
    func_800DA298(rdram, ctx);
        goto after_17;
    // 0x80800EA8: addiu       $a0, $zero, 0x4FD
    ctx->r4 = ADD32(0, 0X4FD);
    after_17:
    // 0x80800EAC: beql        $v0, $zero, L_80800EC0
    if (ctx->r2 == 0) {
        // 0x80800EB0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800EC0;
    }
    goto skip_2;
    // 0x80800EB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800EB4: jal         0x800FFAB0
    // 0x80800EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_18;
    // 0x80800EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800EBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800EC0:
    // 0x80800EC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800EC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800EC8: jr          $ra
    // 0x80800ECC: nop

    return;
    // 0x80800ECC: nop

;}
RECOMP_FUNC void func_800C69FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C69FC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C6A00: jr          $ra
    // 0x800C6A04: lw          $v0, -0x553C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X553C);
    return;
    // 0x800C6A04: lw          $v0, -0x553C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X553C);
;}
RECOMP_FUNC void func_808086A8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808086A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808086AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808086B0: jal         0x80100094
    // 0x808086B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808086B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808086B8: lw          $t6, 0xD4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XD4);
    // 0x808086BC: beql        $t6, $zero, L_808086D8
    if (ctx->r14 == 0) {
        // 0x808086C0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808086D8;
    }
    goto skip_0;
    // 0x808086C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x808086C4: jal         0x80106790
    // 0x808086C8: lw          $a0, 0xD4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XD4);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808086C8: lw          $a0, 0xD4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XD4);
    after_1:
    // 0x808086CC: b           L_808086DC
    // 0x808086D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808086DC;
    // 0x808086D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808086D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808086D8:
    // 0x808086D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808086DC:
    // 0x808086DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808086E0: jr          $ra
    // 0x808086E4: nop

    return;
    // 0x808086E4: nop

;}
RECOMP_FUNC void func_8001953C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001953C: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80019540: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80019544: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80019548: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8001954C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80019550: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80019554: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80019558: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001955C: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x80019560: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80019564:
    // 0x80019564: andi        $t6, $t0, 0x1
    ctx->r14 = ctx->r8 & 0X1;
    // 0x80019568: beq         $t6, $zero, L_80019588
    if (ctx->r14 == 0) {
        // 0x8001956C: andi        $t9, $t0, 0x2
        ctx->r25 = ctx->r8 & 0X2;
            goto L_80019588;
    }
    // 0x8001956C: andi        $t9, $t0, 0x2
    ctx->r25 = ctx->r8 & 0X2;
    // 0x80019570: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80019574: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80019578: nop

    // 0x8001957C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80019580: b           L_8001959C
    // 0x80019584: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
        goto L_8001959C;
    // 0x80019584: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
L_80019588:
    // 0x80019588: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8001958C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80019590: nop

    // 0x80019594: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80019598: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
L_8001959C:
    // 0x8001959C: beq         $t9, $zero, L_800195BC
    if (ctx->r25 == 0) {
        // 0x800195A0: andi        $t3, $t0, 0x4
        ctx->r11 = ctx->r8 & 0X4;
            goto L_800195BC;
    }
    // 0x800195A0: andi        $t3, $t0, 0x4
    ctx->r11 = ctx->r8 & 0X4;
    // 0x800195A4: lw          $t1, 0x4($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X4);
    // 0x800195A8: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800195AC: nop

    // 0x800195B0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800195B4: b           L_800195D0
    // 0x800195B8: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
        goto L_800195D0;
    // 0x800195B8: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
L_800195BC:
    // 0x800195BC: lw          $t2, 0x4($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X4);
    // 0x800195C0: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800195C4: nop

    // 0x800195C8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800195CC: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
L_800195D0:
    // 0x800195D0: beq         $t3, $zero, L_800195F0
    if (ctx->r11 == 0) {
        // 0x800195D4: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800195F0;
    }
    // 0x800195D4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800195D8: lw          $t4, 0x8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X8);
    // 0x800195DC: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800195E0: nop

    // 0x800195E4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800195E8: b           L_80019604
    // 0x800195EC: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
        goto L_80019604;
    // 0x800195EC: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
L_800195F0:
    // 0x800195F0: lw          $t5, 0x8($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X8);
    // 0x800195F4: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x800195F8: nop

    // 0x800195FC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80019600: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
L_80019604:
    // 0x80019604: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x80019608: bne         $at, $zero, L_80019564
    if (ctx->r1 != 0) {
        // 0x8001960C: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_80019564;
    }
    // 0x8001960C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80019610: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x80019614: addiu       $s2, $sp, 0xA8
    ctx->r18 = ADD32(ctx->r29, 0XA8);
    // 0x80019618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8001961C:
    // 0x8001961C: jal         0x80019224
    // 0x80019620: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80019224(rdram, ctx);
        goto after_0;
    // 0x80019620: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80019624: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80019628: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x8001962C: bnel        $at, $zero, L_8001961C
    if (ctx->r1 != 0) {
        // 0x80019630: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001961C;
    }
    goto skip_0;
    // 0x80019630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80019634: addiu       $v1, $sp, 0x48
    ctx->r3 = ADD32(ctx->r29, 0X48);
    // 0x80019638: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001963C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80019640: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x80019644: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80019648: sltu        $at, $v1, $a2
    ctx->r1 = ctx->r3 < ctx->r6 ? 1 : 0;
    // 0x8001964C: beq         $at, $zero, L_80019680
    if (ctx->r1 == 0) {
        // 0x80019650: lwc1        $f18, -0x4($v1)
        ctx->f18.u32l = MEM_W(ctx->r3, -0X4);
            goto L_80019680;
    }
    // 0x80019650: lwc1        $f18, -0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80019654: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
L_80019658:
    // 0x80019658: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001965C: sltu        $at, $v1, $a2
    ctx->r1 = ctx->r3 < ctx->r6 ? 1 : 0;
    // 0x80019660: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80019664: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80019668: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8001966C: sw          $v0, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r2;
    // 0x80019670: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
    // 0x80019674: lwc1        $f18, -0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80019678: bnel        $at, $zero, L_80019658
    if (ctx->r1 != 0) {
        // 0x8001967C: trunc.w.s   $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
            goto L_80019658;
    }
    goto skip_1;
    // 0x8001967C: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
    skip_1:
L_80019680:
    // 0x80019680: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80019684: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80019688: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8001968C: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80019690: nop

    // 0x80019694: sw          $v0, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r2;
    // 0x80019698: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
    // 0x8001969C: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    // 0x800196A0: addiu       $t0, $sp, 0xA8
    ctx->r8 = ADD32(ctx->r29, 0XA8);
    // 0x800196A4: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x800196A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800196AC:
    // 0x800196AC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800196B0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_800196B4:
    // 0x800196B4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800196B8: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800196BC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800196C0: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800196C4: addu        $v0, $s1, $v1
    ctx->r2 = ADD32(ctx->r17, ctx->r3);
    // 0x800196C8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800196CC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800196D0: nop

    // 0x800196D4: bc1fl       L_800196F0
    if (!c1cs) {
        // 0x800196D8: lw          $t1, 0x0($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X0);
            goto L_800196F0;
    }
    goto skip_2;
    // 0x800196D8: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    skip_2:
    // 0x800196DC: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800196E0: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x800196E4: b           L_8001971C
    // 0x800196E8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
        goto L_8001971C;
    // 0x800196E8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800196EC: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
L_800196F0:
    // 0x800196F0: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800196F4: nop

    // 0x800196F8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800196FC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80019700: nop

    // 0x80019704: bc1fl       L_80019720
    if (!c1cs) {
        // 0x80019708: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80019720;
    }
    goto skip_3;
    // 0x80019708: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_3:
    // 0x8001970C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80019710: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80019714: nop

    // 0x80019718: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_8001971C:
    // 0x8001971C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80019720:
    // 0x80019720: bne         $v1, $a2, L_800196B4
    if (ctx->r3 != ctx->r6) {
        // 0x80019724: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800196B4;
    }
    // 0x80019724: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80019728: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    // 0x8001972C: bnel        $a3, $t0, L_800196AC
    if (ctx->r7 != ctx->r8) {
        // 0x80019730: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800196AC;
    }
    goto skip_4;
    // 0x80019730: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_4:
    // 0x80019734: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80019738: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001973C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80019740: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80019744: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80019748: jr          $ra
    // 0x8001974C: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8001974C: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_80090658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090658: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009065C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090660: jal         0x800F54E4
    // 0x80090664: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80090664: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80090668: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009066C: jal         0x800F7F98
    // 0x80090670: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F7F98(rdram, ctx);
        goto after_1;
    // 0x80090670: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80090674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009067C: jr          $ra
    // 0x80090680: nop

    return;
    // 0x80090680: nop

;}
RECOMP_FUNC void _chtoxicroombits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087530: syscall     585
    recomp_syscall_handler(rdram, ctx, 0x80087530);
    return;
    // 0x80087534: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080377C_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080377C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80803780: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80803784: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80803788: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8080378C: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80803790: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80803794: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80803798: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8080379C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x808037A0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x808037A4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x808037A8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808037AC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808037B0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808037B4: jal         0x80100094
    // 0x808037B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808037B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808037BC: lw          $t6, 0x7C($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X7C);
    // 0x808037C0: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x808037C4: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x808037C8: bgezl       $t8, L_808038F4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808037CC: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_808038F4;
    }
    goto skip_0;
    // 0x808037CC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x808037D0: lh          $t9, 0x90($s4)
    ctx->r25 = MEM_H(ctx->r20, 0X90);
    // 0x808037D4: beql        $t9, $zero, L_808038F4
    if (ctx->r25 == 0) {
        // 0x808037D8: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_808038F4;
    }
    goto skip_1;
    // 0x808037D8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_1:
    // 0x808037DC: lw          $t0, 0x64($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X64);
    // 0x808037E0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808037E4: addiu       $s5, $zero, 0x14
    ctx->r21 = ADD32(0, 0X14);
    // 0x808037E8: sll         $t2, $t0, 11
    ctx->r10 = S32(ctx->r8 << 11);
    // 0x808037EC: bltz        $t2, L_8080383C
    if (SIGNED(ctx->r10) < 0) {
        // 0x808037F0: lui         $s3, 0x8080
        ctx->r19 = S32(RELOC_HI16(772, 0X3F04) << 16);
            goto L_8080383C;
    }
    // 0x808037F0: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(772, 0X3F04) << 16);
    // 0x808037F4: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(772, 0X3F14) << 16);
    // 0x808037F8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808037FC: addiu       $s2, $s2, 0x3F14
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(772, 0X3F14));
    // 0x80803800: addiu       $s3, $s3, 0x3F04
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(772, 0X3F04));
    // 0x80803804: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_80803808:
    // 0x80803808: jal         0x8010649C
    // 0x8080380C: addiu       $a1, $s0, 0x190
    ctx->r5 = ADD32(ctx->r16, 0X190);
    func_8010649C(rdram, ctx);
        goto after_1;
    // 0x8080380C: addiu       $a1, $s0, 0x190
    ctx->r5 = ADD32(ctx->r16, 0X190);
    after_1:
    // 0x80803810: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80803814: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803818: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8080381C: jal         0x800EDE54
    // 0x80803820: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800EDE54(rdram, ctx);
        goto after_2;
    // 0x80803820: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_2:
    // 0x80803824: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80803828: bnel        $s0, $s5, L_80803808
    if (ctx->r16 != ctx->r21) {
        // 0x8080382C: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80803808;
    }
    goto skip_2;
    // 0x8080382C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_2:
    // 0x80803830: lbu         $t4, 0x65($s4)
    ctx->r12 = MEM_BU(ctx->r20, 0X65);
    // 0x80803834: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x80803838: sb          $t5, 0x65($s4)
    MEM_B(0X65, ctx->r20) = ctx->r13;
L_8080383C:
    // 0x8080383C: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(772, 0X3F14) << 16);
    // 0x80803840: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(772, 0X3F04) << 16);
    // 0x80803844: addiu       $s3, $s3, 0x3F04
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(772, 0X3F04));
    // 0x80803848: addiu       $s2, $s2, 0x3F14
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(772, 0X3F14));
    // 0x8080384C: addiu       $s5, $zero, 0x14
    ctx->r21 = ADD32(0, 0X14);
    // 0x80803850: jal         0x8080000C
    // 0x80803854: lw          $a0, 0x3C($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X3C);
    func_8080000C_chjiggygamenew(rdram, ctx);
        goto after_3;
    // 0x80803854: lw          $a0, 0x3C($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X3C);
    after_3:
    // 0x80803858: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X3AD4) << 16);
    // 0x8080385C: lwc1        $f22, 0x3AD4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X3AD4));
    // 0x80803860: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X3AD8) << 16);
    // 0x80803864: or          $s1, $s6, $zero
    ctx->r17 = ctx->r22 | 0;
    // 0x80803868: addiu       $fp, $v0, -0x15
    ctx->r30 = ADD32(ctx->r2, -0X15);
    // 0x8080386C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80803870: lwc1        $f20, 0x3AD8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X3AD8));
    // 0x80803874: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80803878: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_8080387C:
    // 0x8080387C: bne         $s0, $fp, L_8080388C
    if (ctx->r16 != ctx->r30) {
        // 0x80803880: lbu         $v0, 0x0($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X0);
            goto L_8080388C;
    }
    // 0x80803880: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80803884: b           L_80803890
    // 0x80803888: sb          $s6, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r22;
        goto L_80803890;
    // 0x80803888: sb          $s6, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r22;
L_8080388C:
    // 0x8080388C: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
L_80803890:
    // 0x80803890: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x80803894: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80803898: beql        $v0, $t6, L_808038E8
    if (ctx->r2 == ctx->r14) {
        // 0x8080389C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808038E8;
    }
    goto skip_3;
    // 0x8080389C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_3:
    // 0x808038A0: jal         0x8010649C
    // 0x808038A4: addiu       $a1, $s0, 0x190
    ctx->r5 = ADD32(ctx->r16, 0X190);
    func_8010649C(rdram, ctx);
        goto after_4;
    // 0x808038A4: addiu       $a1, $s0, 0x190
    ctx->r5 = ADD32(ctx->r16, 0X190);
    after_4:
    // 0x808038A8: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x808038AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808038B0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808038B4: beql        $v1, $zero, L_808038DC
    if (ctx->r3 == 0) {
        // 0x808038B8: mfc1        $a3, $f22
        ctx->r7 = (int32_t)ctx->f22.u32l;
            goto L_808038DC;
    }
    goto skip_4;
    // 0x808038B8: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    skip_4:
    // 0x808038BC: bne         $v1, $s7, L_808038E4
    if (ctx->r3 != ctx->r23) {
        // 0x808038C0: or          $a1, $s3, $zero
        ctx->r5 = ctx->r19 | 0;
            goto L_808038E4;
    }
    // 0x808038C0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808038C4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808038C8: jal         0x800EDE54
    // 0x808038CC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800EDE54(rdram, ctx);
        goto after_5;
    // 0x808038CC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_5:
    // 0x808038D0: b           L_808038E8
    // 0x808038D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_808038E8;
    // 0x808038D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808038D8: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
L_808038DC:
    // 0x808038DC: jal         0x800EDE54
    // 0x808038E0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800EDE54(rdram, ctx);
        goto after_6;
    // 0x808038E0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_6:
L_808038E4:
    // 0x808038E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808038E8:
    // 0x808038E8: bne         $s0, $s5, L_8080387C
    if (ctx->r16 != ctx->r21) {
        // 0x808038EC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8080387C;
    }
    // 0x808038EC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808038F0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_808038F4:
    // 0x808038F4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808038F8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808038FC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80803900: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80803904: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80803908: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8080390C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80803910: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80803914: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80803918: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8080391C: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80803920: jr          $ra
    // 0x80803924: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80803924: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80800F4C_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F4C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800F50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800F54: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800F58: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800F5C: jal         0x80100094
    // 0x80800F60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800F60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800F64: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800F68: jal         0x80089998
    // 0x80800F6C: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
    _sumultiscore_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800F6C: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
    after_1:
    // 0x80800F70: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800F74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800F78: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800F7C: beq         $t6, $at, L_80800F9C
    if (ctx->r14 == ctx->r1) {
        // 0x80800F80: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800F9C;
    }
    // 0x80800F80: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800F84: beq         $t6, $at, L_80800FE8
    if (ctx->r14 == ctx->r1) {
        // 0x80800F88: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800FE8;
    }
    // 0x80800F88: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800F8C: beq         $t6, $at, L_80801070
    if (ctx->r14 == ctx->r1) {
        // 0x80800F90: nop
    
            goto L_80801070;
    }
    // 0x80800F90: nop

    // 0x80800F94: b           L_808010C8
    // 0x80800F98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808010C8;
    // 0x80800F98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800F9C:
    // 0x80800F9C: jal         0x800C954C
    // 0x80800FA0: nop

    func_800C954C(rdram, ctx);
        goto after_2;
    // 0x80800FA0: nop

    after_2:
    // 0x80800FA4: bnel        $v0, $zero, L_808010C8
    if (ctx->r2 != 0) {
        // 0x80800FA8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808010C8;
    }
    goto skip_0;
    // 0x80800FA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800FAC: jal         0x800DA298
    // 0x80800FB0: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800FB0: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    after_3:
    // 0x80800FB4: bne         $v0, $zero, L_808010C4
    if (ctx->r2 != 0) {
        // 0x80800FB8: addiu       $a1, $zero, 0xCEC
        ctx->r5 = ADD32(0, 0XCEC);
            goto L_808010C4;
    }
    // 0x80800FB8: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    // 0x80800FBC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800FC0: addiu       $t7, $zero, 0x22
    ctx->r15 = ADD32(0, 0X22);
    // 0x80800FC4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800FC8: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80800FCC: jal         0x8008A208
    // 0x80800FD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80800FD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80800FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FD8: jal         0x80101FDC
    // 0x80800FDC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80800FDC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80800FE0: b           L_808010C8
    // 0x80800FE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808010C8;
    // 0x80800FE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800FE8:
    // 0x80800FE8: jal         0x80089C68
    // 0x80800FEC: addiu       $a0, $zero, 0x350
    ctx->r4 = ADD32(0, 0X350);
    _subaddiefind_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x80800FEC: addiu       $a0, $zero, 0x350
    ctx->r4 = ADD32(0, 0X350);
    after_6:
    // 0x80800FF0: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x80800FF4: beq         $at, $zero, L_80801048
    if (ctx->r1 == 0) {
        // 0x80800FF8: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80801048;
    }
    // 0x80800FF8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800FFC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801000: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801004: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801008: jal         0x800DC178
    // 0x8080100C: nop

    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x8080100C: nop

    after_7:
    // 0x80801010: jal         0x80088368
    // 0x80801014: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80801014: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x80801018: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8080101C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80801020: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x80801024: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80801028: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8080102C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80801030: jal         0x800D9154
    // 0x80801034: nop

    func_800D9154(rdram, ctx);
        goto after_9;
    // 0x80801034: nop

    after_9:
    // 0x80801038: beq         $v0, $zero, L_80801048
    if (ctx->r2 == 0) {
        // 0x8080103C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801048;
    }
    // 0x8080103C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801040: jal         0x80108B04
    // 0x80801044: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_80108B04(rdram, ctx);
        goto after_10;
    // 0x80801044: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_10:
L_80801048:
    // 0x80801048: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x8080104C: andi        $t8, $a0, 0x1FF
    ctx->r24 = ctx->r4 & 0X1FF;
    // 0x80801050: jal         0x800CEAD0
    // 0x80801054: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_11;
    // 0x80801054: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_11:
    // 0x80801058: beql        $v0, $zero, L_808010C8
    if (ctx->r2 == 0) {
        // 0x8080105C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808010C8;
    }
    goto skip_1;
    // 0x8080105C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80801060: jal         0x80801338
    // 0x80801064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801338_chballoonburst(rdram, ctx);
        goto after_12;
    // 0x80801064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80801068: b           L_808010C8
    // 0x8080106C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808010C8;
    // 0x8080106C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801070:
    // 0x80801070: jal         0x8008A2E8
    // 0x80801074: nop

    _susubgame_entrypoint_9(rdram, ctx);
        goto after_13;
    // 0x80801074: nop

    after_13:
    // 0x80801078: beq         $v0, $zero, L_808010C4
    if (ctx->r2 == 0) {
        // 0x8080107C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808010C4;
    }
    // 0x8080107C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801080: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80801084: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80801088: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8080108C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80801090: jal         0x8008A2C8
    // 0x80801094: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_14;
    // 0x80801094: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_14:
    // 0x80801098: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8080109C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808010A0: addiu       $t0, $zero, 0x22
    ctx->r8 = ADD32(0, 0X22);
    // 0x808010A4: lw          $a1, 0x10($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X10);
    // 0x808010A8: lw          $a2, 0x14($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X14);
    // 0x808010AC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808010B0: jal         0x8008A208
    // 0x808010B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_15;
    // 0x808010B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_15:
    // 0x808010B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010BC: jal         0x80101FDC
    // 0x808010C0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_16;
    // 0x808010C0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_16:
L_808010C4:
    // 0x808010C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808010C8:
    // 0x808010C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808010CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808010D0: jr          $ra
    // 0x808010D4: nop

    return;
    // 0x808010D4: nop

;}
RECOMP_FUNC void _chfactoryprop_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800861C0: syscall     287
    recomp_syscall_handler(rdram, ctx, 0x800861C0);
    return;
    // 0x800861C4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8010C2D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C2D8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8010C2DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010C2E0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8010C2E4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8010C2E8: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8010C2EC: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8010C2F0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8010C2F4: jal         0x80103F38
    // 0x8010C2F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80103F38(rdram, ctx);
        goto after_0;
    // 0x8010C2F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x8010C2FC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8010C300: jal         0x8010A40C
    // 0x8010C304: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_8010A40C(rdram, ctx);
        goto after_1;
    // 0x8010C304: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_1:
    // 0x8010C308: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8010C30C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8010C310: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8010C314: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8010C318: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x8010C31C: jal         0x800EFB24
    // 0x8010C320: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x8010C320: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8010C324: jal         0x800EEFD4
    // 0x8010C328: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800EEFD4(rdram, ctx);
        goto after_3;
    // 0x8010C328: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x8010C32C: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8010C330: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8010C334: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8010C338: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010C33C: add.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8010C340: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8010C344: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8010C348: nop

    // 0x8010C34C: bc1f        L_8010C398
    if (!c1cs) {
        // 0x8010C350: nop
    
            goto L_8010C398;
    }
    // 0x8010C350: nop

    // 0x8010C354: jal         0x8002DCA0
    // 0x8010C358: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x8010C358: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x8010C35C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8010C360: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8010C364: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8010C368: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8010C36C: add.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x8010C370: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8010C374: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8010C378: jal         0x800EF368
    // 0x8010C37C: nop

    func_800EF368(rdram, ctx);
        goto after_5;
    // 0x8010C37C: nop

    after_5:
    // 0x8010C380: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8010C384: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8010C388: jal         0x800EF04C
    // 0x8010C38C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_6;
    // 0x8010C38C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_6:
    // 0x8010C390: b           L_8010C398
    // 0x8010C394: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010C398;
    // 0x8010C394: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010C398:
    // 0x8010C398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010C39C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8010C3A0: jr          $ra
    // 0x8010C3A4: nop

    return;
    // 0x8010C3A4: nop

;}
RECOMP_FUNC void chpumproomswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(996, 0X380) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x380
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(996, 0X380));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x380
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(996, 0X380));
;}
RECOMP_FUNC void _sumumbofx_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089860: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x80089860);
    return;
    // 0x80089864: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800998_chboggyfatboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800998: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080099C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808009A4: jal         0x80100094
    // 0x808009A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808009A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808009AC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808009B0: lw          $a0, 0x3C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3C);
    // 0x808009B4: jal         0x80106790
    // 0x808009B8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808009B8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808009BC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808009C0: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
    // 0x808009C4: addiu       $a1, $v0, 0x18
    ctx->r5 = ADD32(ctx->r2, 0X18);
    // 0x808009C8: jal         0x800EE940
    // 0x808009CC: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    func_800EE940(rdram, ctx);
        goto after_2;
    // 0x808009CC: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    after_2:
    // 0x808009D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808009D8: jr          $ra
    // 0x808009DC: nop

    return;
    // 0x808009DC: nop

;}
RECOMP_FUNC void _bstrexlarge_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084060: syscall     101
    recomp_syscall_handler(rdram, ctx, 0x80084060);
    return;
    // 0x80084064: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_8080006C_ncpod(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080006C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800070: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800074: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x80800078: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8080007C: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x80800080: bnel        $t7, $zero, L_808000A0
    if (ctx->r15 != 0) {
        // 0x80800084: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000A0;
    }
    goto skip_0;
    // 0x80800084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800088: jal         0x800EA05C
    // 0x8080008C: sb          $t8, 0x43($a0)
    MEM_B(0X43, ctx->r4) = ctx->r24;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x8080008C: sb          $t8, 0x43($a0)
    MEM_B(0X43, ctx->r4) = ctx->r24;
    after_0:
    // 0x80800090: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800094: jal         0x800887D8
    // 0x80800098: addiu       $a1, $zero, 0x79
    ctx->r5 = ADD32(0, 0X79);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800098: addiu       $a1, $zero, 0x79
    ctx->r5 = ADD32(0, 0X79);
    after_1:
    // 0x8080009C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000A0:
    // 0x808000A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A4: jr          $ra
    // 0x808000A8: nop

    return;
    // 0x808000A8: nop

;}
RECOMP_FUNC void _idlight_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088D08: syscall     735
    recomp_syscall_handler(rdram, ctx, 0x80088D08);
    return;
    // 0x80088D0C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800D4EF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4EF4: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x800D4EF8: sltiu       $at, $t6, 0x13
    ctx->r1 = ctx->r14 < 0X13 ? 1 : 0;
    // 0x800D4EFC: beq         $at, $zero, L_800D4F90
    if (ctx->r1 == 0) {
        // 0x800D4F00: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800D4F90;
    }
    // 0x800D4F00: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800D4F04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D4F08: addu        $at, $at, $t6
    gpr jr_addend_800D4F10 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800D4F0C: lw          $t6, 0x5B40($at)
    ctx->r14 = ADD32(ctx->r1, 0X5B40);
    // 0x800D4F10: jr          $t6
    // 0x800D4F14: nop

    switch (jr_addend_800D4F10 >> 2) {
        case 0: goto L_800D4F18; break;
        case 1: goto L_800D4F20; break;
        case 2: goto L_800D4F90; break;
        case 3: goto L_800D4F90; break;
        case 4: goto L_800D4F90; break;
        case 5: goto L_800D4F28; break;
        case 6: goto L_800D4F30; break;
        case 7: goto L_800D4F38; break;
        case 8: goto L_800D4F90; break;
        case 9: goto L_800D4F40; break;
        case 10: goto L_800D4F48; break;
        case 11: goto L_800D4F50; break;
        case 12: goto L_800D4F58; break;
        case 13: goto L_800D4F60; break;
        case 14: goto L_800D4F68; break;
        case 15: goto L_800D4F70; break;
        case 16: goto L_800D4F78; break;
        case 17: goto L_800D4F80; break;
        case 18: goto L_800D4F88; break;
        default: switch_error(__func__, 0x800D4F10, 0x80125B40);
    }
    // 0x800D4F14: nop

L_800D4F18:
    // 0x800D4F18: jr          $ra
    // 0x800D4F1C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x800D4F1C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_800D4F20:
    // 0x800D4F20: jr          $ra
    // 0x800D4F24: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x800D4F24: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_800D4F28:
    // 0x800D4F28: jr          $ra
    // 0x800D4F2C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x800D4F2C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800D4F30:
    // 0x800D4F30: jr          $ra
    // 0x800D4F34: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x800D4F34: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_800D4F38:
    // 0x800D4F38: jr          $ra
    // 0x800D4F3C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x800D4F3C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_800D4F40:
    // 0x800D4F40: jr          $ra
    // 0x800D4F44: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x800D4F44: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800D4F48:
    // 0x800D4F48: jr          $ra
    // 0x800D4F4C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x800D4F4C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800D4F50:
    // 0x800D4F50: jr          $ra
    // 0x800D4F54: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x800D4F54: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_800D4F58:
    // 0x800D4F58: jr          $ra
    // 0x800D4F5C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x800D4F5C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_800D4F60:
    // 0x800D4F60: jr          $ra
    // 0x800D4F64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800D4F64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D4F68:
    // 0x800D4F68: jr          $ra
    // 0x800D4F6C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x800D4F6C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_800D4F70:
    // 0x800D4F70: jr          $ra
    // 0x800D4F74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800D4F74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D4F78:
    // 0x800D4F78: jr          $ra
    // 0x800D4F7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800D4F7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D4F80:
    // 0x800D4F80: jr          $ra
    // 0x800D4F84: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x800D4F84: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_800D4F88:
    // 0x800D4F88: jr          $ra
    // 0x800D4F8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800D4F8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D4F90:
    // 0x800D4F90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D4F94: jr          $ra
    // 0x800D4F98: nop

    return;
    // 0x800D4F98: nop

;}
RECOMP_FUNC void func_80800868_bsbanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800868: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080086C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800870: jal         0x8008CABC
    // 0x80800874: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800874: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800878: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080087C: jal         0x8080040C
    // 0x80800880: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8080040C_bsbanswim(rdram, ctx);
        goto after_1;
    // 0x80800880: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800884: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800888: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x8080088C: jal         0x8008B1BC
    // 0x80800890: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    anctrl_setDuration(rdram, ctx);
        goto after_2;
    // 0x80800890: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800898: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080089C: jr          $ra
    // 0x808008A0: nop

    return;
    // 0x808008A0: nop

;}
RECOMP_FUNC void dbmorph_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080007C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800080: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800084: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80800088: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8080008C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800090: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80800094: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800098: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8080009C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808000A0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808000A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000A8: lhu         $fp, 0x16($a1)
    ctx->r30 = MEM_HU(ctx->r5, 0X16);
    // 0x808000AC: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x808000B0: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x808000B4: andi        $t6, $fp, 0x1
    ctx->r14 = ctx->r30 & 0X1;
    // 0x808000B8: or          $fp, $t6, $zero
    ctx->r30 = ctx->r14 | 0;
    // 0x808000BC: jal         0x80800000
    // 0x808000C0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80800000_dbmorph(rdram, ctx);
        goto after_0;
    // 0x808000C0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x808000C4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x808000C8: jal         0x800B2190
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B2190(rdram, ctx);
        goto after_1;
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000D0: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808000D4: jal         0x800B2190
    // 0x808000D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800B2190(rdram, ctx);
        goto after_2;
    // 0x808000D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x808000DC: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x808000E0: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x808000E4: lh          $v1, 0x4($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X4);
    // 0x808000E8: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
    // 0x808000EC: addu        $s1, $t8, $s4
    ctx->r17 = ADD32(ctx->r24, ctx->r20);
    // 0x808000F0: beq         $fp, $zero, L_80800138
    if (ctx->r30 == 0) {
        // 0x808000F4: addu        $s0, $t8, $v0
        ctx->r16 = ADD32(ctx->r24, ctx->r2);
            goto L_80800138;
    }
    // 0x808000F4: addu        $s0, $t8, $v0
    ctx->r16 = ADD32(ctx->r24, ctx->r2);
    // 0x808000F8: lh          $s6, 0x6($t7)
    ctx->r22 = MEM_H(ctx->r15, 0X6);
    // 0x808000FC: beql        $s6, $zero, L_80800138
    if (ctx->r22 == 0) {
        // 0x80800100: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_80800138;
    }
    goto skip_0;
    // 0x80800100: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    skip_0:
L_80800104:
    // 0x80800104: lhu         $t9, 0x6($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X6);
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800110: andi        $t6, $t9, 0x4000
    ctx->r14 = ctx->r25 & 0X4000;
    // 0x80800114: beql        $t6, $zero, L_8080012C
    if (ctx->r14 == 0) {
        // 0x80800118: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_8080012C;
    }
    goto skip_1;
    // 0x80800118: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    skip_1:
    // 0x8080011C: jal         0x8001BBC8
    // 0x80800120: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    aligned4_memcpy(rdram, ctx);
        goto after_3;
    // 0x80800120: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_3:
    // 0x80800124: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x80800128: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_8080012C:
    // 0x8080012C: bne         $s6, $zero, L_80800104
    if (ctx->r22 != 0) {
        // 0x80800130: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_80800104;
    }
    // 0x80800130: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80800134: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
L_80800138:
    // 0x80800138: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8080013C: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80800140: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x80800144: lbu         $s0, 0x3($t8)
    ctx->r16 = MEM_BU(ctx->r24, 0X3);
    // 0x80800148: addiu       $v1, $t8, 0xC
    ctx->r3 = ADD32(ctx->r24, 0XC);
    // 0x8080014C: blezl       $s0, L_808006F4
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80800150: lbu         $t7, 0x17($s2)
        ctx->r15 = MEM_BU(ctx->r18, 0X17);
            goto L_808006F4;
    }
    goto skip_2;
    // 0x80800150: lbu         $t7, 0x17($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X17);
    skip_2:
    // 0x80800154: sw          $s2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r18;
    // 0x80800158: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8080015C: addiu       $s2, $zero, -0x2
    ctx->r18 = ADD32(0, -0X2);
    // 0x80800160: lw          $s7, 0x78($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X78);
L_80800164:
    // 0x80800164: lwc1        $f0, 0x0($s7)
    ctx->f0.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80800168: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x8080016C: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x80800170: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x80800174: nop

    // 0x80800178: bc1tl       L_808006A8
    if (c1cs) {
        // 0x8080017C: lh          $t9, 0x0($v1)
        ctx->r25 = MEM_H(ctx->r3, 0X0);
            goto L_808006A8;
    }
    goto skip_3;
    // 0x8080017C: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    skip_3:
    // 0x80800180: lh          $t6, 0x4($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X4);
    // 0x80800184: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x80800188: addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
    // 0x8080018C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800190: lh          $t6, 0x6($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X6);
    // 0x80800194: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x80800198: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080019C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x808001A0: lh          $t6, 0x8($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X8);
    // 0x808001A4: addu        $a1, $t9, $v1
    ctx->r5 = ADD32(ctx->r25, ctx->r3);
    // 0x808001A8: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x808001AC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808001B0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808001B4: slti        $at, $a0, -0x1
    ctx->r1 = SIGNED(ctx->r4) < -0X1 ? 1 : 0;
    // 0x808001B8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808001BC: lbu         $t1, 0x10($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X10);
    // 0x808001C0: lbu         $t2, 0x11($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X11);
    // 0x808001C4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x808001C8: lbu         $t3, 0x12($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X12);
    // 0x808001CC: lbu         $t4, 0x13($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X13);
    // 0x808001D0: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x808001D4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808001D8: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x808001DC: lh          $t6, 0xC($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XC);
    // 0x808001E0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808001E4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808001E8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x808001EC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808001F0: lh          $t6, 0xE($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XE);
    // 0x808001F4: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x808001F8: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x808001FC: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80800200: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800204: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80800208: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x8080020C: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80800210: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800214: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800218: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8080021C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800220: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80800224: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800228: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x8080022C: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x80800230: sra         $t0, $t7, 16
    ctx->r8 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80800234: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x80800238: sra         $t5, $t7, 16
    ctx->r13 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8080023C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800240: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800244: mfc1        $ra, $f6
    ctx->r31 = (int32_t)ctx->f6.u32l;
    // 0x80800248: nop

    // 0x8080024C: sll         $t7, $ra, 16
    ctx->r15 = S32(ctx->r31 << 16);
    // 0x80800250: bne         $at, $zero, L_8080069C
    if (ctx->r1 != 0) {
        // 0x80800254: sra         $ra, $t7, 16
        ctx->r31 = S32(SIGNED(ctx->r15) >> 16);
            goto L_8080069C;
    }
    // 0x80800254: sra         $ra, $t7, 16
    ctx->r31 = S32(SIGNED(ctx->r15) >> 16);
L_80800258:
    // 0x80800258: bne         $s3, $a0, L_80800328
    if (ctx->r19 != ctx->r4) {
        // 0x8080025C: sll         $v1, $a0, 4
        ctx->r3 = S32(ctx->r4 << 4);
            goto L_80800328;
    }
    // 0x8080025C: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80800260: lh          $t6, 0x10($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X10);
    // 0x80800264: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80800268: lbu         $t1, 0xC($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XC);
    // 0x8080026C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80800270: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x80800274: lbu         $t2, 0xD($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XD);
    // 0x80800278: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080027C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800280: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x80800284: lbu         $t3, 0xE($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0XE);
    // 0x80800288: lbu         $t4, 0xF($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0XF);
    // 0x8080028C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800290: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80800294: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800298: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8080029C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808002A0: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x808002A4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x808002A8: nop

    // 0x808002AC: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x808002B0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808002B4: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    // 0x808002B8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808002BC: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x808002C0: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x808002C4: lh          $t6, 0xA($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XA);
    // 0x808002C8: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x808002CC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808002D0: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x808002D4: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    // 0x808002D8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808002DC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x808002E0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x808002E4: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x808002E8: nop

    // 0x808002EC: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x808002F0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808002F4: sra         $t0, $t7, 16
    ctx->r8 = S32(SIGNED(ctx->r15) >> 16);
    // 0x808002F8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808002FC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800300: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x80800304: nop

    // 0x80800308: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x8080030C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800310: sra         $t5, $t7, 16
    ctx->r13 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80800314: mfc1        $ra, $f10
    ctx->r31 = (int32_t)ctx->f10.u32l;
    // 0x80800318: nop

    // 0x8080031C: sll         $t7, $ra, 16
    ctx->r15 = S32(ctx->r31 << 16);
    // 0x80800320: b           L_80800680
    // 0x80800324: sra         $ra, $t7, 16
    ctx->r31 = S32(SIGNED(ctx->r15) >> 16);
        goto L_80800680;
    // 0x80800324: sra         $ra, $t7, 16
    ctx->r31 = S32(SIGNED(ctx->r15) >> 16);
L_80800328:
    // 0x80800328: addu        $s0, $v1, $s5
    ctx->r16 = ADD32(ctx->r3, ctx->r21);
    // 0x8080032C: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
    // 0x80800330: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x80800334: addu        $s1, $v1, $s4
    ctx->r17 = ADD32(ctx->r3, ctx->r20);
    // 0x80800338: addu        $t9, $t7, $a3
    ctx->r25 = ADD32(ctx->r15, ctx->r7);
    // 0x8080033C: lh          $t7, 0x8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X8);
    // 0x80800340: addu        $t8, $t6, $a2
    ctx->r24 = ADD32(ctx->r14, ctx->r6);
    // 0x80800344: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    // 0x80800348: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
    // 0x8080034C: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
    // 0x80800350: addu        $t9, $t7, $t5
    ctx->r25 = ADD32(ctx->r15, ctx->r13);
    // 0x80800354: lbu         $t7, 0xC($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XC);
    // 0x80800358: addu        $t8, $t6, $t0
    ctx->r24 = ADD32(ctx->r14, ctx->r8);
    // 0x8080035C: lh          $t6, 0xA($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XA);
    // 0x80800360: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80800364: sh          $t8, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r24;
    // 0x80800368: addu        $t8, $t6, $ra
    ctx->r24 = ADD32(ctx->r14, ctx->r31);
    // 0x8080036C: sh          $t9, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r25;
    // 0x80800370: sh          $t8, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r24;
    // 0x80800374: bgez        $t7, L_8080038C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800378: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8080038C;
    }
    // 0x80800378: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8080037C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800380: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800384: nop

    // 0x80800388: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8080038C:
    // 0x8080038C: lbu         $t9, 0xC($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0XC);
    // 0x80800390: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800394: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800398: subu        $t6, $t1, $t9
    ctx->r14 = SUB32(ctx->r9, ctx->r25);
    // 0x8080039C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x808003A0: nop

    // 0x808003A4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808003A8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x808003AC: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x808003B0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x808003B4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x808003B8: nop

    // 0x808003BC: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x808003C0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x808003C4: nop

    // 0x808003C8: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x808003CC: beql        $t7, $zero, L_8080041C
    if (ctx->r15 == 0) {
        // 0x808003D0: mfc1        $t7, $f4
        ctx->r15 = (int32_t)ctx->f4.u32l;
            goto L_8080041C;
    }
    goto skip_4;
    // 0x808003D0: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    skip_4:
    // 0x808003D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003D8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808003DC: sub.s       $f4, $f16, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x808003E0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x808003E4: nop

    // 0x808003E8: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x808003EC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x808003F0: nop

    // 0x808003F4: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x808003F8: bne         $t7, $zero, L_80800410
    if (ctx->r15 != 0) {
        // 0x808003FC: nop
    
            goto L_80800410;
    }
    // 0x808003FC: nop

    // 0x80800400: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80800404: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800408: b           L_80800428
    // 0x8080040C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80800428;
    // 0x8080040C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80800410:
    // 0x80800410: b           L_80800428
    // 0x80800414: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80800428;
    // 0x80800414: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80800418: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
L_8080041C:
    // 0x8080041C: nop

    // 0x80800420: bltz        $t7, L_80800410
    if (SIGNED(ctx->r15) < 0) {
        // 0x80800424: nop
    
            goto L_80800410;
    }
    // 0x80800424: nop

L_80800428:
    // 0x80800428: lbu         $t9, 0xD($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XD);
    // 0x8080042C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80800430: sb          $t7, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r15;
    // 0x80800434: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80800438: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080043C: bgez        $t9, L_80800450
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800440: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80800450;
    }
    // 0x80800440: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800444: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800448: nop

    // 0x8080044C: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_80800450:
    // 0x80800450: lbu         $t6, 0xD($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XD);
    // 0x80800454: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800458: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8080045C: subu        $t8, $t2, $t6
    ctx->r24 = SUB32(ctx->r10, ctx->r14);
    // 0x80800460: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80800464: nop

    // 0x80800468: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8080046C: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80800470: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80800474: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80800478: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8080047C: nop

    // 0x80800480: cvt.w.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800484: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80800488: nop

    // 0x8080048C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80800490: beql        $t9, $zero, L_808004E0
    if (ctx->r25 == 0) {
        // 0x80800494: mfc1        $t9, $f18
        ctx->r25 = (int32_t)ctx->f18.u32l;
            goto L_808004E0;
    }
    goto skip_5;
    // 0x80800494: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    skip_5:
    // 0x80800498: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080049C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808004A0: sub.s       $f18, $f6, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x808004A4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x808004A8: nop

    // 0x808004AC: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x808004B0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x808004B4: nop

    // 0x808004B8: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x808004BC: bne         $t9, $zero, L_808004D4
    if (ctx->r25 != 0) {
        // 0x808004C0: nop
    
            goto L_808004D4;
    }
    // 0x808004C0: nop

    // 0x808004C4: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x808004C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808004CC: b           L_808004EC
    // 0x808004D0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_808004EC;
    // 0x808004D0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_808004D4:
    // 0x808004D4: b           L_808004EC
    // 0x808004D8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_808004EC;
    // 0x808004D8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x808004DC: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
L_808004E0:
    // 0x808004E0: nop

    // 0x808004E4: bltz        $t9, L_808004D4
    if (SIGNED(ctx->r25) < 0) {
        // 0x808004E8: nop
    
            goto L_808004D4;
    }
    // 0x808004E8: nop

L_808004EC:
    // 0x808004EC: lbu         $t6, 0xE($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XE);
    // 0x808004F0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x808004F4: sb          $t9, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r25;
    // 0x808004F8: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x808004FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800500: bgez        $t6, L_80800514
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800504: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80800514;
    }
    // 0x80800504: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800508: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080050C: nop

    // 0x80800510: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
L_80800514:
    // 0x80800514: lbu         $t8, 0xE($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0XE);
    // 0x80800518: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080051C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800520: subu        $t7, $t3, $t8
    ctx->r15 = SUB32(ctx->r11, ctx->r24);
    // 0x80800524: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80800528: nop

    // 0x8080052C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800530: mul.s       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800534: add.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800538: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8080053C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80800540: nop

    // 0x80800544: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80800548: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8080054C: nop

    // 0x80800550: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80800554: beql        $t6, $zero, L_808005A4
    if (ctx->r14 == 0) {
        // 0x80800558: mfc1        $t6, $f8
        ctx->r14 = (int32_t)ctx->f8.u32l;
            goto L_808005A4;
    }
    goto skip_6;
    // 0x80800558: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    skip_6:
    // 0x8080055C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800560: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800564: sub.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80800568: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8080056C: nop

    // 0x80800570: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80800574: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80800578: nop

    // 0x8080057C: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80800580: bne         $t6, $zero, L_80800598
    if (ctx->r14 != 0) {
        // 0x80800584: nop
    
            goto L_80800598;
    }
    // 0x80800584: nop

    // 0x80800588: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8080058C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800590: b           L_808005B0
    // 0x80800594: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_808005B0;
    // 0x80800594: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80800598:
    // 0x80800598: b           L_808005B0
    // 0x8080059C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_808005B0;
    // 0x8080059C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x808005A0: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
L_808005A4:
    // 0x808005A4: nop

    // 0x808005A8: bltz        $t6, L_80800598
    if (SIGNED(ctx->r14) < 0) {
        // 0x808005AC: nop
    
            goto L_80800598;
    }
    // 0x808005AC: nop

L_808005B0:
    // 0x808005B0: lbu         $t8, 0xF($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XF);
    // 0x808005B4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x808005B8: sb          $t6, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r14;
    // 0x808005BC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x808005C0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808005C4: bgez        $t8, L_808005D8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808005C8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808005D8;
    }
    // 0x808005C8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808005CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808005D0: nop

    // 0x808005D4: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
L_808005D8:
    // 0x808005D8: lbu         $t7, 0xF($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0XF);
    // 0x808005DC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808005E0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808005E4: subu        $t9, $t4, $t7
    ctx->r25 = SUB32(ctx->r12, ctx->r15);
    // 0x808005E8: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x808005EC: nop

    // 0x808005F0: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808005F4: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x808005F8: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808005FC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80800600: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80800604: nop

    // 0x80800608: cvt.w.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8080060C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80800610: nop

    // 0x80800614: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80800618: beql        $t8, $zero, L_80800668
    if (ctx->r24 == 0) {
        // 0x8080061C: mfc1        $t8, $f16
        ctx->r24 = (int32_t)ctx->f16.u32l;
            goto L_80800668;
    }
    goto skip_7;
    // 0x8080061C: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    skip_7:
    // 0x80800620: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800624: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800628: sub.s       $f16, $f4, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8080062C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80800630: nop

    // 0x80800634: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80800638: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8080063C: nop

    // 0x80800640: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80800644: bne         $t8, $zero, L_8080065C
    if (ctx->r24 != 0) {
        // 0x80800648: nop
    
            goto L_8080065C;
    }
    // 0x80800648: nop

    // 0x8080064C: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80800650: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800654: b           L_80800674
    // 0x80800658: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80800674;
    // 0x80800658: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8080065C:
    // 0x8080065C: b           L_80800674
    // 0x80800660: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80800674;
    // 0x80800660: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80800664: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
L_80800668:
    // 0x80800668: nop

    // 0x8080066C: bltz        $t8, L_8080065C
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800670: nop
    
            goto L_8080065C;
    }
    // 0x80800670: nop

L_80800674:
    // 0x80800674: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80800678: sb          $t8, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r24;
    // 0x8080067C: nop

L_80800680:
    // 0x80800680: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    // 0x80800684: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80800688: slti        $at, $a0, -0x1
    ctx->r1 = SIGNED(ctx->r4) < -0X1 ? 1 : 0;
    // 0x8080068C: beq         $at, $zero, L_80800258
    if (ctx->r1 == 0) {
        // 0x80800690: nop
    
            goto L_80800258;
    }
    // 0x80800690: nop

    // 0x80800694: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80800698: lbu         $s0, 0x3($t7)
    ctx->r16 = MEM_BU(ctx->r15, 0X3);
L_8080069C:
    // 0x8080069C: b           L_808006D0
    // 0x808006A0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
        goto L_808006D0;
    // 0x808006A0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x808006A4: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
L_808006A8:
    // 0x808006A8: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x808006AC: addu        $a1, $v1, $t6
    ctx->r5 = ADD32(ctx->r3, ctx->r14);
    // 0x808006B0: lh          $t8, 0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4);
    // 0x808006B4: addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
    // 0x808006B8: beql        $s2, $t8, L_808006D4
    if (ctx->r18 == ctx->r24) {
        // 0x808006BC: andi        $t9, $a1, 0x3
        ctx->r25 = ctx->r5 & 0X3;
            goto L_808006D4;
    }
    goto skip_8;
    // 0x808006BC: andi        $t9, $a1, 0x3
    ctx->r25 = ctx->r5 & 0X3;
    skip_8:
    // 0x808006C0: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
L_808006C4:
    // 0x808006C4: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x808006C8: bnel        $s2, $t7, L_808006C4
    if (ctx->r18 != ctx->r15) {
        // 0x808006CC: lh          $t7, 0x0($a1)
        ctx->r15 = MEM_H(ctx->r5, 0X0);
            goto L_808006C4;
    }
    goto skip_9;
    // 0x808006CC: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    skip_9:
L_808006D0:
    // 0x808006D0: andi        $t9, $a1, 0x3
    ctx->r25 = ctx->r5 & 0X3;
L_808006D4:
    // 0x808006D4: beq         $t9, $zero, L_808006E0
    if (ctx->r25 == 0) {
        // 0x808006D8: slt         $at, $s6, $s0
        ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r16) ? 1 : 0;
            goto L_808006E0;
    }
    // 0x808006D8: slt         $at, $s6, $s0
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x808006DC: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
L_808006E0:
    // 0x808006E0: bne         $at, $zero, L_80800164
    if (ctx->r1 != 0) {
        // 0x808006E4: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80800164;
    }
    // 0x808006E4: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x808006E8: sw          $s7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r23;
    // 0x808006EC: lw          $s2, 0x6C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X6C);
    // 0x808006F0: lbu         $t7, 0x17($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X17);
L_808006F4:
    // 0x808006F4: andi        $t8, $fp, 0x1
    ctx->r24 = ctx->r30 & 0X1;
    // 0x808006F8: andi        $t9, $t7, 0xFFFE
    ctx->r25 = ctx->r15 & 0XFFFE;
    // 0x808006FC: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80800700: sb          $t6, 0x17($s2)
    MEM_B(0X17, ctx->r18) = ctx->r14;
    // 0x80800704: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800708: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8080070C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80800710: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80800714: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80800718: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8080071C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800720: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800724: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800728: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080072C: jr          $ra
    // 0x80800730: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80800730: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80808034_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808034: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80808038: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080803C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80808040: jal         0x80100094
    // 0x80808044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80808044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80808048: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080804C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80808050: lh          $t6, 0xA4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XA4);
    // 0x80808054: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80808058: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080805C: bne         $t6, $at, L_8080807C
    if (ctx->r14 != ctx->r1) {
        // 0x80808060: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8080807C;
    }
    // 0x80808060: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80808064: jal         0x8001210C
    // 0x80808068: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    func_8001210C(rdram, ctx);
        goto after_1;
    // 0x80808068: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_1:
    // 0x8080806C: beql        $v0, $zero, L_80808080
    if (ctx->r2 == 0) {
        // 0x80808070: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_80808080;
    }
    goto skip_0;
    // 0x80808070: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x80808074: jal         0x808081AC
    // 0x80808078: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_808081AC_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80808078: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
L_8080807C:
    // 0x8080807C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
L_80808080:
    // 0x80808080: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80808084: lui         $a3, 0x8081
    ctx->r7 = S32(RELOC_HI16(1480, 0XA160) << 16);
    // 0x80808088: lw          $t0, 0x70($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X70);
    // 0x8080808C: lbu         $a0, 0xA6($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0XA6);
    // 0x80808090: addiu       $a3, $a3, -0x5EA0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1480, 0XA160));
    // 0x80808094: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80808098: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8080809C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808080A0: jal         0x80089D68
    // 0x808080A4: addiu       $a1, $t9, 0x4
    ctx->r5 = ADD32(ctx->r25, 0X4);
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x808080A4: addiu       $a1, $t9, 0x4
    ctx->r5 = ADD32(ctx->r25, 0X4);
    after_3:
    // 0x808080A8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x808080AC: sb          $v0, 0xA6($t2)
    MEM_B(0XA6, ctx->r10) = ctx->r2;
    // 0x808080B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808080B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808080B8: jr          $ra
    // 0x808080BC: nop

    return;
    // 0x808080BC: nop

;}
RECOMP_FUNC void func_80800030_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800038: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x8080003C: addiu       $a2, $zero, 0x372
    ctx->r6 = ADD32(0, 0X372);
    // 0x80800040: jal         0x80800FA4
    // 0x80800044: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_80800FA4_chalienkids(rdram, ctx);
        goto after_0;
    // 0x80800044: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080004C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800050: jr          $ra
    // 0x80800054: nop

    return;
    // 0x80800054: nop

;}
RECOMP_FUNC void func_808001B0_chmasterjiggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001B8: jal         0x8008A6D8
    // 0x808001BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _sujiggy_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x808001BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001C8: jr          $ra
    // 0x808001CC: nop

    return;
    // 0x808001CC: nop

;}
RECOMP_FUNC void func_800F3B3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3B3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F3B40: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800F3B44: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800F3B48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F3B4C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800F3B50: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800F3B54: jal         0x8009E154
    // 0x800F3B58: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8009E154(rdram, ctx);
        goto after_0;
    // 0x800F3B58: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x800F3B5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800F3B60: jal         0x8008E9B8
    // 0x800F3B64: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8008E9B8(rdram, ctx);
        goto after_1;
    // 0x800F3B64: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x800F3B68: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800F3B6C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800F3B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F3B74: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800F3B78: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800F3B7C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800F3B80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F3B84: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800F3B88: jr          $ra
    // 0x800F3B8C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    return;
    // 0x800F3B8C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
;}
RECOMP_FUNC void dbvtxnormal_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80800004: jr          $ra
    // 0x80800008: addu        $v0, $t6, $a0
    ctx->r2 = ADD32(ctx->r14, ctx->r4);
    return;
    // 0x80800008: addu        $v0, $t6, $a0
    ctx->r2 = ADD32(ctx->r14, ctx->r4);
;}
RECOMP_FUNC void _chlagoonufoint_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085A38: syscall     190
    recomp_syscall_handler(rdram, ctx, 0x80085A38);
    return;
    // 0x80085A3C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800CEB54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEB54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CEB58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CEB5C: jal         0x800CE3E0
    // 0x800CEB60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800CE3E0(rdram, ctx);
        goto after_0;
    // 0x800CEB60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800CEB64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CEB68: jal         0x800CEB08
    // 0x800CEB6C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800CEB08(rdram, ctx);
        goto after_1;
    // 0x800CEB6C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800CEB70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CEB74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CEB78: jr          $ra
    // 0x800CEB7C: nop

    return;
    // 0x800CEB7C: nop

;}
RECOMP_FUNC void func_80800310_chdinofoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800310: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800314: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800318: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080031C: jal         0x80089C90
    // 0x80800320: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800320: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800324: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800328: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080032C: jal         0x80089C98
    // 0x80800330: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800330: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_1:
    // 0x80800334: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800338: jal         0x80101870
    // 0x8080033C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80101870(rdram, ctx);
        goto after_2;
    // 0x8080033C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800340: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800344: jal         0x80089C98
    // 0x80800348: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800348: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x8080034C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800350: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800354: jr          $ra
    // 0x80800358: nop

    return;
    // 0x80800358: nop

;}
RECOMP_FUNC void func_808001C8_chfaircoinbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001D8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808001DC: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    // 0x808001E0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808001E4: jal         0x8008FB10
    // 0x808001E8: lui         $a3, 0x42B8
    ctx->r7 = S32(0X42B8 << 16);
    func_8008FB10(rdram, ctx);
        goto after_0;
    // 0x808001E8: lui         $a3, 0x42B8
    ctx->r7 = S32(0X42B8 << 16);
    after_0:
    // 0x808001EC: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x808001F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001F4: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x808001F8: beq         $t6, $at, L_80800220
    if (ctx->r14 == ctx->r1) {
        // 0x808001FC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800220;
    }
    // 0x808001FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800200: beq         $t6, $at, L_80800250
    if (ctx->r14 == ctx->r1) {
        // 0x80800204: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800250;
    }
    // 0x80800204: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800208: beq         $t6, $at, L_80800250
    if (ctx->r14 == ctx->r1) {
        // 0x8080020C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800250;
    }
    // 0x8080020C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800210: beql        $t6, $at, L_80800254
    if (ctx->r14 == ctx->r1) {
        // 0x80800214: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800254;
    }
    goto skip_0;
    // 0x80800214: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800218: b           L_80800254
    // 0x8080021C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800254;
    // 0x8080021C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800220:
    // 0x80800220: jal         0x80800050
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800050_chfaircoinbox(rdram, ctx);
        goto after_1;
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800228: jal         0x800DA298
    // 0x8080022C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x8080022C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800230: beq         $v0, $zero, L_80800248
    if (ctx->r2 == 0) {
        // 0x80800234: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800248;
    }
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800238: jal         0x808000A4
    // 0x8080023C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808000A4_chfaircoinbox(rdram, ctx);
        goto after_3;
    // 0x8080023C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80800240: b           L_80800254
    // 0x80800244: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800254;
    // 0x80800244: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800248:
    // 0x80800248: jal         0x808002CC
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002CC_chfaircoinbox(rdram, ctx);
        goto after_4;
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80800250:
    // 0x80800250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800254:
    // 0x80800254: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800258: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080025C: jr          $ra
    // 0x80800260: nop

    return;
    // 0x80800260: nop

;}
RECOMP_FUNC void func_800B4380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4380: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B4384: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B4388: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B438C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800B4390: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800B4394: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B4398: addiu       $s1, $s1, 0x7EFC
    ctx->r17 = ADD32(ctx->r17, 0X7EFC);
    // 0x800B439C: addiu       $s0, $s0, 0x7EF0
    ctx->r16 = ADD32(ctx->r16, 0X7EF0);
    // 0x800B43A0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_800B43A4:
    // 0x800B43A4: beql        $a0, $zero, L_800B43BC
    if (ctx->r4 == 0) {
        // 0x800B43A8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800B43BC;
    }
    goto skip_0;
    // 0x800B43A8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x800B43AC: jal         0x800B2F58
    // 0x800B43B0: nop

    vector_defrag(rdram, ctx);
        goto after_0;
    // 0x800B43B0: nop

    after_0:
    // 0x800B43B4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800B43B8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800B43BC:
    // 0x800B43BC: bnel        $s0, $s1, L_800B43A4
    if (ctx->r16 != ctx->r17) {
        // 0x800B43C0: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_800B43A4;
    }
    goto skip_1;
    // 0x800B43C0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x800B43C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B43C8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B43CC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B43D0: jr          $ra
    // 0x800B43D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800B43D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800CEF6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEF6C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CEF70: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CEF74: jr          $ra
    // 0x800CEF78: swc1        $f4, -0x4E90($at)
    MEM_W(-0X4E90, ctx->r1) = ctx->f4.u32l;
    return;
    // 0x800CEF78: swc1        $f4, -0x4E90($at)
    MEM_W(-0X4E90, ctx->r1) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80802BCC_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802BCC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802BD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802BD4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802BD8: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x80802BDC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80802BE0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80802BE4: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    // 0x80802BE8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80802BEC: jal         0x80089F20
    // 0x80802BF0: lui         $a3, 0x4282
    ctx->r7 = S32(0X4282 << 16);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80802BF0: lui         $a3, 0x4282
    ctx->r7 = S32(0X4282 << 16);
    after_0:
    // 0x80802BF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802BF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802BFC: jr          $ra
    // 0x80802C00: nop

    return;
    // 0x80802C00: nop

;}
RECOMP_FUNC void func_800C82CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C82CC: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800C82D0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800C82D4: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x800C82D8: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x800C82DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C82E0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800C82E4: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x800C82E8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800C82EC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800C82F0: jal         0x800C7BCC
    // 0x800C82F4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_800C7BCC(rdram, ctx);
        goto after_0;
    // 0x800C82F4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x800C82F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C82FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C8300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8304: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x800C8308: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800C830C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C8310: bc1f        L_800C8320
    if (!c1cs) {
        // 0x800C8314: nop
    
            goto L_800C8320;
    }
    // 0x800C8314: nop

    // 0x800C8318: b           L_800C8484
    // 0x800C831C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800C8484;
    // 0x800C831C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800C8320:
    // 0x800C8320: lwc1        $f22, 0x5924($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X5924);
    // 0x800C8324: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800C8328: jal         0x800C8198
    // 0x800C832C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    func_800C8198(rdram, ctx);
        goto after_1;
    // 0x800C832C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_1:
    // 0x800C8330: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800C8334: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C8338: sub.s       $f24, $f0, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f24.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x800C833C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8340: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800C8344: div.s       $f2, $f22, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f22.fl, ctx->f6.fl);
    // 0x800C8348: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800C834C: add.s       $f26, $f0, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f26.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x800C8350: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x800C8354: add.s       $f20, $f2, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800C8358: jal         0x800C8198
    // 0x800C835C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_800C8198(rdram, ctx);
        goto after_2;
    // 0x800C835C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_2:
    // 0x800C8360: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800C8364: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C8368: sub.s       $f24, $f0, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800C836C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8370: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800C8374: div.s       $f22, $f20, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = DIV_S(ctx->f20.fl, ctx->f8.fl);
    // 0x800C8378: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800C837C: add.s       $f26, $f0, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f26.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x800C8380: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x800C8384: add.s       $f20, $f22, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f22.fl + ctx->f22.fl;
    // 0x800C8388: jal         0x800C8198
    // 0x800C838C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_800C8198(rdram, ctx);
        goto after_3;
    // 0x800C838C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_3:
    // 0x800C8390: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800C8394: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C8398: sub.s       $f24, $f0, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800C839C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C83A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800C83A4: div.s       $f22, $f20, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = DIV_S(ctx->f20.fl, ctx->f10.fl);
    // 0x800C83A8: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800C83AC: add.s       $f26, $f0, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f26.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x800C83B0: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x800C83B4: add.s       $f20, $f22, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f22.fl + ctx->f22.fl;
    // 0x800C83B8: jal         0x800C8198
    // 0x800C83BC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_800C8198(rdram, ctx);
        goto after_4;
    // 0x800C83BC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_4:
    // 0x800C83C0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800C83C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C83C8: sub.s       $f24, $f0, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800C83CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C83D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800C83D4: div.s       $f22, $f20, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = DIV_S(ctx->f20.fl, ctx->f16.fl);
    // 0x800C83D8: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800C83DC: add.s       $f26, $f0, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f26.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x800C83E0: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x800C83E4: add.s       $f20, $f22, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f22.fl + ctx->f22.fl;
    // 0x800C83E8: jal         0x800C8198
    // 0x800C83EC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_800C8198(rdram, ctx);
        goto after_5;
    // 0x800C83EC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_5:
    // 0x800C83F0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800C83F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C83F8: sub.s       $f24, $f0, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800C83FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8400: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800C8404: div.s       $f22, $f20, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = DIV_S(ctx->f20.fl, ctx->f18.fl);
    // 0x800C8408: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800C840C: add.s       $f26, $f0, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f26.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x800C8410: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x800C8414: add.s       $f20, $f22, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f22.fl + ctx->f22.fl;
    // 0x800C8418: jal         0x800C8198
    // 0x800C841C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_800C8198(rdram, ctx);
        goto after_6;
    // 0x800C841C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_6:
    // 0x800C8420: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800C8424: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800C8428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C842C: jal         0x800C7A68
    // 0x800C8430: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    func_800C7A68(rdram, ctx);
        goto after_7;
    // 0x800C8430: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    after_7:
    // 0x800C8434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8438: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x800C843C: jal         0x800C7A68
    // 0x800C8440: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    func_800C7A68(rdram, ctx);
        goto after_8;
    // 0x800C8440: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_8:
    // 0x800C8444: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C8448: jal         0x800EEB40
    // 0x800C844C: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_800EEB40(rdram, ctx);
        goto after_9;
    // 0x800C844C: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_9:
    // 0x800C8450: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x800C8454: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C8458: jal         0x800EEB40
    // 0x800C845C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_800EEB40(rdram, ctx);
        goto after_10;
    // 0x800C845C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_10:
    // 0x800C8460: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x800C8464: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C8468: bc1fl       L_800C847C
    if (!c1cs) {
        // 0x800C846C: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_800C847C;
    }
    goto skip_0;
    // 0x800C846C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x800C8470: b           L_800C8480
    // 0x800C8474: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
        goto L_800C8480;
    // 0x800C8474: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x800C8478: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_800C847C:
    // 0x800C847C: nop

L_800C8480:
    // 0x800C8480: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800C8484:
    // 0x800C8484: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800C8488: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800C848C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800C8490: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x800C8494: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x800C8498: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x800C849C: jr          $ra
    // 0x800C84A0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800C84A0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80800214_chweldarbossfireball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800214: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080021C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800220: jal         0x801040D0
    // 0x80800224: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_801040D0(rdram, ctx);
        goto after_0;
    // 0x80800224: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800228: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8080022C: jal         0x801015D0
    // 0x80800230: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_801015D0(rdram, ctx);
        goto after_1;
    // 0x80800230: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x80800234: jal         0x800DF41C
    // 0x80800238: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800DF41C(rdram, ctx);
        goto after_2;
    // 0x80800238: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x8080023C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800240: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800244: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800248: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080024C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800250: jal         0x800EFA4C
    // 0x80800254: lw          $a1, 0x50($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X50);
    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x80800254: lw          $a1, 0x50($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X50);
    after_3:
    // 0x80800258: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8080025C: jal         0x800D93A0
    // 0x80800260: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800D93A0(rdram, ctx);
        goto after_4;
    // 0x80800260: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_4:
    // 0x80800264: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800268: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x8080026C: jal         0x800DFF2C
    // 0x80800270: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_800DFF2C(rdram, ctx);
        goto after_5;
    // 0x80800270: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_5:
    // 0x80800274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800278: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080027C: jr          $ra
    // 0x80800280: nop

    return;
    // 0x80800280: nop

;}
