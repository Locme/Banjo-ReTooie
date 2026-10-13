#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80021C8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021C8C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80021C90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80021C94: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80021C98: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80021C9C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80021CA0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80021CA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80021CA8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80021CAC: lbu         $t6, 0x47($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X47);
    // 0x80021CB0: bne         $t6, $zero, L_80021CC0
    if (ctx->r14 != 0) {
        // 0x80021CB4: nop
    
            goto L_80021CC0;
    }
    // 0x80021CB4: nop

    // 0x80021CB8: b           L_80021E08
    // 0x80021CBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80021E08;
    // 0x80021CBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80021CC0:
    // 0x80021CC0: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80021CC4: lw          $t7, -0x15C0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X15C0);
    // 0x80021CC8: beq         $t7, $zero, L_80021DF8
    if (ctx->r15 == 0) {
        // 0x80021CCC: nop
    
            goto L_80021DF8;
    }
    // 0x80021CCC: nop

    // 0x80021CD0: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80021CD4: lw          $t8, -0x15C0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X15C0);
    // 0x80021CD8: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80021CDC: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80021CE0: lw          $t9, -0x15C0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X15C0);
    // 0x80021CE4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80021CE8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80021CEC: sw          $t0, -0x15C0($at)
    MEM_W(-0X15C0, ctx->r1) = ctx->r8;
    // 0x80021CF0: lbu         $t1, 0x3B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X3B);
    // 0x80021CF4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80021CF8: sb          $t1, 0x4($t2)
    MEM_B(0X4, ctx->r10) = ctx->r9;
    // 0x80021CFC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80021D00: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80021D04: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80021D08: lbu         $t5, 0x47($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X47);
    // 0x80021D0C: sll         $t6, $t5, 14
    ctx->r14 = S32(ctx->r13 << 14);
    // 0x80021D10: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80021D14: lbu         $s0, 0x3B($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X3B);
    // 0x80021D18: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80021D1C: beq         $s0, $at, L_80021D38
    if (ctx->r16 == ctx->r1) {
        // 0x80021D20: nop
    
            goto L_80021D38;
    }
    // 0x80021D20: nop

    // 0x80021D24: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x80021D28: beq         $s0, $at, L_80021DAC
    if (ctx->r16 == ctx->r1) {
        // 0x80021D2C: nop
    
            goto L_80021DAC;
    }
    // 0x80021D2C: nop

    // 0x80021D30: b           L_80021DF0
    // 0x80021D34: nop

        goto L_80021DF0;
    // 0x80021D34: nop

L_80021D38:
    // 0x80021D38: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80021D3C: sh          $zero, 0x24($t7)
    MEM_H(0X24, ctx->r15) = 0;
    // 0x80021D40: lbu         $t8, 0x3F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3F);
    // 0x80021D44: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80021D48: addiu       $t9, $zero, 0x103
    ctx->r25 = ADD32(0, 0X103);
    // 0x80021D4C: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x80021D50: sh          $t0, 0x22($t1)
    MEM_H(0X22, ctx->r9) = ctx->r8;
    // 0x80021D54: lbu         $t2, 0x43($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X43);
    // 0x80021D58: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80021D5C: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80021D60: sb          $t3, 0x28($t4)
    MEM_B(0X28, ctx->r12) = ctx->r11;
    // 0x80021D64: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80021D68: addiu       $t7, $zero, 0x7F
    ctx->r15 = ADD32(0, 0X7F);
    // 0x80021D6C: lbu         $t6, 0x28($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X28);
    // 0x80021D70: subu        $t9, $t7, $t6
    ctx->r25 = SUB32(ctx->r15, ctx->r14);
    // 0x80021D74: sb          $t9, 0x29($t5)
    MEM_B(0X29, ctx->r13) = ctx->r25;
    // 0x80021D78: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80021D7C: lbu         $t0, 0x29($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X29);
    // 0x80021D80: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80021D84: bgez        $t0, L_80021D9C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80021D88: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80021D9C;
    }
    // 0x80021D88: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80021D8C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80021D90: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80021D94: nop

    // 0x80021D98: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80021D9C:
    // 0x80021D9C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80021DA0: swc1        $f6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
    // 0x80021DA4: b           L_80021DF8
    // 0x80021DA8: nop

        goto L_80021DF8;
    // 0x80021DA8: nop

L_80021DAC:
    // 0x80021DAC: jal         0x80021C10
    // 0x80021DB0: lbu         $a0, 0x43($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X43);
    func_80021C10(rdram, ctx);
        goto after_0;
    // 0x80021DB0: lbu         $a0, 0x43($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X43);
    after_0:
    // 0x80021DB4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80021DB8: swc1        $f0, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->f0.u32l;
    // 0x80021DBC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80021DC0: sh          $zero, 0x24($t3)
    MEM_H(0X24, ctx->r11) = 0;
    // 0x80021DC4: lbu         $t4, 0x3F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X3F);
    // 0x80021DC8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80021DCC: addiu       $t7, $zero, 0x103
    ctx->r15 = ADD32(0, 0X103);
    // 0x80021DD0: subu        $t6, $t7, $t4
    ctx->r14 = SUB32(ctx->r15, ctx->r12);
    // 0x80021DD4: sh          $t6, 0x22($t9)
    MEM_H(0X22, ctx->r25) = ctx->r14;
    // 0x80021DD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80021DDC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80021DE0: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80021DE4: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x80021DE8: b           L_80021DF8
    // 0x80021DEC: nop

        goto L_80021DF8;
    // 0x80021DEC: nop

L_80021DF0:
    // 0x80021DF0: b           L_80021DF8
    // 0x80021DF4: nop

        goto L_80021DF8;
    // 0x80021DF4: nop

L_80021DF8:
    // 0x80021DF8: b           L_80021E08
    // 0x80021DFC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
        goto L_80021E08;
    // 0x80021DFC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80021E00: b           L_80021E08
    // 0x80021E04: nop

        goto L_80021E08;
    // 0x80021E04: nop

L_80021E08:
    // 0x80021E08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80021E0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80021E10: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80021E14: jr          $ra
    // 0x80021E18: nop

    return;
    // 0x80021E18: nop

;}
RECOMP_FUNC void func_80801A30_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A30: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801A34: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80801A38: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80801A3C: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80801A40: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80801A44: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80801A48: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80801A4C: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80801A50: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80801A54: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80801A58: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80801A5C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80801A60: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80801A64: addiu       $s1, $a0, 0x4
    ctx->r17 = ADD32(ctx->r4, 0X4);
    // 0x80801A68: addiu       $s3, $zero, 0x9
    ctx->r19 = ADD32(0, 0X9);
L_80801A6C:
    // 0x80801A6C: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x80801A70: lwc1        $f6, 0x24($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X24);
    // 0x80801A74: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80801A78: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x80801A7C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80801A80: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80801A84: jal         0x800F10B4
    // 0x80801A88: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x80801A88: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x80801A8C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801A90: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80801A94: bne         $s0, $s3, L_80801A6C
    if (ctx->r16 != ctx->r19) {
        // 0x80801A98: swc1        $f0, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->f0.u32l;
            goto L_80801A6C;
    }
    // 0x80801A98: swc1        $f0, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->f0.u32l;
    // 0x80801A9C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80801AA0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80801AA4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80801AA8: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80801AAC: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80801AB0: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80801AB4: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80801AB8: jr          $ra
    // 0x80801ABC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80801ABC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void heap_bytes_allocated(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B3E8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001B3EC: jr          $ra
    // 0x8001B3F0: lw          $v0, -0x4100($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4100);
    return;
    // 0x8001B3F0: lw          $v0, -0x4100($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4100);
;}
RECOMP_FUNC void func_808010B8_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808010BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808010C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808010C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808010C8: jal         0x8009E6C4
    // 0x808010CC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8009E6C4(rdram, ctx);
        goto after_0;
    // 0x808010CC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x808010D0: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x808010D4: bnel        $a1, $zero, L_808010EC
    if (ctx->r5 != 0) {
        // 0x808010D8: sw          $a1, 0x15C($s0)
        MEM_W(0X15C, ctx->r16) = ctx->r5;
            goto L_808010EC;
    }
    goto skip_0;
    // 0x808010D8: sw          $a1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r5;
    skip_0:
    // 0x808010DC: jal         0x800F8B64
    // 0x808010E0: nop

    func_800F8B64(rdram, ctx);
        goto after_1;
    // 0x808010E0: nop

    after_1:
    // 0x808010E4: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x808010E8: sw          $a1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r5;
L_808010EC:
    // 0x808010EC: jal         0x80085208
    // 0x808010F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808010F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808010F4: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x808010F8: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808010FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801100: jal         0x8008CB3C
    // 0x80801104: addiu       $a1, $zero, 0xB9
    ctx->r5 = ADD32(0, 0XB9);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_3;
    // 0x80801104: addiu       $a1, $zero, 0xB9
    ctx->r5 = ADD32(0, 0XB9);
    after_3:
    // 0x80801108: jal         0x80800000
    // 0x8080110C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsbswim(rdram, ctx);
        goto after_4;
    // 0x8080110C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801110: jal         0x80800030
    // 0x80801114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800030_bsbswim(rdram, ctx);
        goto after_5;
    // 0x80801114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080111C: jal         0x8009BC5C
    // 0x80801120: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8009BC5C(rdram, ctx);
        goto after_6;
    // 0x80801120: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_6:
    // 0x80801124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801128: jal         0x8009B94C
    // 0x8080112C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009B94C(rdram, ctx);
        goto after_7;
    // 0x8080112C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80801130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801134: jal         0x8009BA9C
    // 0x80801138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_8;
    // 0x80801138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8080113C: lui         $a1, 0x4389
    ctx->r5 = S32(0X4389 << 16);
    // 0x80801140: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80801144: jal         0x8009BF5C
    // 0x80801148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BF5C(rdram, ctx);
        goto after_9;
    // 0x80801148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080114C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801150: jal         0x8009C4CC
    // 0x80801154: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_10;
    // 0x80801154: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_10:
    // 0x80801158: jal         0x8008E944
    // 0x8080115C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_11;
    // 0x8080115C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80801160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801168: jal         0x80085338
    // 0x8080116C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    _batimer_set(rdram, ctx);
        goto after_12;
    // 0x8080116C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_12:
    // 0x80801170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801174: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801178: jal         0x80085338
    // 0x8080117C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    _batimer_set(rdram, ctx);
        goto after_13;
    // 0x8080117C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_13:
    // 0x80801180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801184: jal         0x800910BC
    // 0x80801188: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800910BC(rdram, ctx);
        goto after_14;
    // 0x80801188: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_14:
    // 0x8080118C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801190: addiu       $a1, $zero, 0x467
    ctx->r5 = ADD32(0, 0X467);
    // 0x80801194: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801198: jal         0x8009DF18
    // 0x8080119C: addiu       $a3, $zero, 0x5DC0
    ctx->r7 = ADD32(0, 0X5DC0);
    func_8009DF18(rdram, ctx);
        goto after_15;
    // 0x8080119C: addiu       $a3, $zero, 0x5DC0
    ctx->r7 = ADD32(0, 0X5DC0);
    after_15:
    // 0x808011A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011A4: jal         0x80085298
    // 0x808011A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _baswim_entrypoint_6(rdram, ctx);
        goto after_16;
    // 0x808011A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x808011AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808011B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808011B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808011B8: jr          $ra
    // 0x808011BC: nop

    return;
    // 0x808011BC: nop

;}
RECOMP_FUNC void func_801138F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801138F4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801138F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801138FC: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80113900: jal         0x80112550
    // 0x80113904: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_80112550(rdram, ctx);
        goto after_0;
    // 0x80113904: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_0:
    // 0x80113908: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8011390C: jal         0x801107F0
    // 0x80113910: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_801107F0(rdram, ctx);
        goto after_1;
    // 0x80113910: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x80113914: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80113918: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x8011391C: jal         0x800EFB24
    // 0x80113920: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x80113920: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_2:
    // 0x80113924: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80113928: jal         0x800EF410
    // 0x8011392C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EF410(rdram, ctx);
        goto after_3;
    // 0x8011392C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x80113930: jal         0x800EEF94
    // 0x80113934: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EEF94(rdram, ctx);
        goto after_4;
    // 0x80113934: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x80113938: lui         $t6, 0x2
    ctx->r14 = S32(0X2 << 16);
    // 0x8011393C: ori         $t6, $t6, 0x20
    ctx->r14 = ctx->r14 | 0X20;
    // 0x80113940: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80113944: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80113948: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8011394C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80113950: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x80113954: jal         0x80112E98
    // 0x80113958: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80112E98(rdram, ctx);
        goto after_5;
    // 0x80113958: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x8011395C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80113960: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80113964: jr          $ra
    // 0x80113968: nop

    return;
    // 0x80113968: nop

;}
RECOMP_FUNC void func_8001DE64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DE64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001DE68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001DE6C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001DE70: lui         $t7, 0xAD09
    ctx->r15 = S32(0XAD09 << 16);
    // 0x8001DE74: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x8001DE78: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8001DE7C: lw          $t0, 0x300($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X300);
    // 0x8001DE80: lui         $t9, 0xAD17
    ctx->r25 = S32(0XAD17 << 16);
    // 0x8001DE84: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8001DE88: ori         $t9, $t9, 0x14
    ctx->r25 = ctx->r25 | 0X14;
    // 0x8001DE8C: bne         $t0, $zero, L_8001DEA8
    if (ctx->r8 != 0) {
        // 0x8001DE90: sw          $t9, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r25;
            goto L_8001DEA8;
    }
    // 0x8001DE90: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8001DE94: jal         0x80012598
    // 0x8001DE98: nop

    func_80012598(rdram, ctx);
        goto after_0;
    // 0x8001DE98: nop

    after_0:
    // 0x8001DE9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001DEA0: jal         0x8002EC20
    // 0x8001DEA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    osSetThreadPri_recomp(rdram, ctx);
        goto after_1;
    // 0x8001DEA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_8001DEA8:
    // 0x8001DEA8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8001DEAC: lui         $at, 0xAD09
    ctx->r1 = S32(0XAD09 << 16);
    // 0x8001DEB0: ori         $at, $at, 0x10
    ctx->r1 = ctx->r1 | 0X10;
    // 0x8001DEB4: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8001DEB8: xor         $t2, $t1, $at
    ctx->r10 = ctx->r9 ^ ctx->r1;
    // 0x8001DEBC: lui         $at, 0xAD17
    ctx->r1 = S32(0XAD17 << 16);
    // 0x8001DEC0: ori         $at, $at, 0x14
    ctx->r1 = ctx->r1 | 0X14;
    // 0x8001DEC4: xor         $t4, $t3, $at
    ctx->r12 = ctx->r11 ^ ctx->r1;
    // 0x8001DEC8: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x8001DECC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001DED0: jal         0x8001DEE8
    // 0x8001DED4: sb          $t5, -0x2487($at)
    MEM_B(-0X2487, ctx->r1) = ctx->r13;
    func_8001DEE8(rdram, ctx);
        goto after_2;
    // 0x8001DED4: sb          $t5, -0x2487($at)
    MEM_B(-0X2487, ctx->r1) = ctx->r13;
    after_2:
    // 0x8001DED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001DEDC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001DEE0: jr          $ra
    // 0x8001DEE4: nop

    return;
    // 0x8001DEE4: nop

;}
RECOMP_FUNC void bsbswim_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008F8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808008FC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(120, 0X1E80) << 16);
    // 0x80800900: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800904: jr          $ra
    // 0x80800908: lw          $v0, 0x1E80($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1E80));
    return;
    // 0x80800908: lw          $v0, 0x1E80($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1E80));
;}
RECOMP_FUNC void bsdronebubbled_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001BC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808001C0: lw          $t7, 0x54($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X54);
    // 0x808001C4: lwc1        $f4, 0x44($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X44);
    // 0x808001C8: jal         0x800D8FF8
    // 0x808001CC: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808001CC: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x808001D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(168, 0X2E4) << 16);
    // 0x808001D4: lwc1        $f6, 0x2E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(168, 0X2E4));
    // 0x808001D8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x808001DC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808001E0: lw          $a0, 0x54($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X54);
    // 0x808001E4: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x808001E8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808001EC: jal         0x800F1574
    // 0x808001F0: nop

    func_800F1574(rdram, ctx);
        goto after_1;
    // 0x808001F0: nop

    after_1:
    // 0x808001F4: jal         0x8008CABC
    // 0x808001F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_2;
    // 0x808001F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x808001FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(168, 0X2E8) << 16);
    // 0x80800200: lwc1        $f10, 0x2E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(168, 0X2E8));
    // 0x80800204: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800208: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8080020C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800210: mul.s       $f16, $f14, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x80800214: lw          $t0, 0x54($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X54);
    // 0x80800218: lwc1        $f12, 0x40($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X40);
    // 0x8080021C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800220: jal         0x800F1214
    // 0x80800224: nop

    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x80800224: nop

    after_3:
    // 0x80800228: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080022C: jal         0x8008B1BC
    // 0x80800230: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x80800230: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x80800234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800238: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080023C: jr          $ra
    // 0x80800240: nop

    return;
    // 0x80800240: nop

;}
RECOMP_FUNC void _bskazshoessuckspline_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800835D8: syscall     68
    recomp_syscall_handler(rdram, ctx, 0x800835D8);
    return;
    // 0x800835DC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _gldialog_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088750: syscall     702
    recomp_syscall_handler(rdram, ctx, 0x80088750);
    return;
    // 0x80088754: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80090150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090150: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090158: jal         0x800F54E4
    // 0x8009015C: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8009015C: nop

    after_0:
    // 0x80090160: jal         0x800F6478
    // 0x80090164: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6478(rdram, ctx);
        goto after_1;
    // 0x80090164: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80090168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009016C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090170: jr          $ra
    // 0x80090174: nop

    return;
    // 0x80090174: nop

;}
RECOMP_FUNC void func_80800624_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800624: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800628: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080062C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800630: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800634: jal         0x8008CABC
    // 0x80800638: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800638: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    after_0:
    // 0x8080063C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80800640: jal         0x80084C68
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800648: jal         0x80084C10
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800654: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x80800658: jal         0x80084C18
    // 0x8080065C: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    _bafly_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x8080065C: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    after_3:
    // 0x80800660: jal         0x80084C20
    // 0x80800664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80800664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080066C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800670: jal         0x80091A58
    // 0x80800674: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    bakey_pressed(rdram, ctx);
        goto after_5;
    // 0x80800674: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_5:
    // 0x80800678: beq         $v0, $zero, L_8080068C
    if (ctx->r2 == 0) {
        // 0x8080067C: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_8080068C;
    }
    // 0x8080067C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80800680: lw          $t7, 0x188($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X188);
    // 0x80800684: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800688: sb          $t6, 0x1C($t7)
    MEM_B(0X1C, ctx->r15) = ctx->r14;
L_8080068C:
    // 0x8080068C: lw          $t8, 0x188($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X188);
    // 0x80800690: lbu         $t9, 0x1C($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1C);
    // 0x80800694: beq         $t9, $zero, L_808006D0
    if (ctx->r25 == 0) {
        // 0x80800698: nop
    
            goto L_808006D0;
    }
    // 0x80800698: nop

    // 0x8080069C: jal         0x8001211C
    // 0x808006A0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_8001211C(rdram, ctx);
        goto after_6;
    // 0x808006A0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_6:
    // 0x808006A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808006A8: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x808006AC: mfhi        $t0
    ctx->r8 = hi;
    // 0x808006B0: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x808006B4: bne         $t0, $zero, L_808006D0
    if (ctx->r8 != 0) {
        // 0x808006B8: nop
    
            goto L_808006D0;
    }
    // 0x808006B8: nop

    // 0x808006BC: lw          $t1, 0x188($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X188);
    // 0x808006C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C4: jal         0x80084C28
    // 0x808006C8: sb          $zero, 0x1C($t1)
    MEM_B(0X1C, ctx->r9) = 0;
    _bafly_entrypoint_12(rdram, ctx);
        goto after_7;
    // 0x808006C8: sb          $zero, 0x1C($t1)
    MEM_B(0X1C, ctx->r9) = 0;
    after_7:
    // 0x808006CC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_808006D0:
    // 0x808006D0: bne         $v1, $zero, L_808006E4
    if (ctx->r3 != 0) {
        // 0x808006D4: nop
    
            goto L_808006E4;
    }
    // 0x808006D4: nop

    // 0x808006D8: lw          $t2, 0x15C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X15C);
    // 0x808006DC: beq         $t2, $zero, L_80800734
    if (ctx->r10 == 0) {
        // 0x808006E0: nop
    
            goto L_80800734;
    }
    // 0x808006E0: nop

L_808006E4:
    // 0x808006E4: beq         $v1, $zero, L_80800704
    if (ctx->r3 == 0) {
        // 0x808006E8: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80800704;
    }
    // 0x808006E8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808006EC: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x808006F0: jal         0x8008B1BC
    // 0x808006F4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    anctrl_setDuration(rdram, ctx);
        goto after_8;
    // 0x808006F4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_8:
    // 0x808006F8: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    // 0x808006FC: jal         0x80085948
    // 0x80800700: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _chusefeather_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x80800700: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
L_80800704:
    // 0x80800704: lw          $t3, 0x15C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X15C);
    // 0x80800708: lui         $a1, 0x3EB3
    ctx->r5 = S32(0X3EB3 << 16);
    // 0x8080070C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800710: beq         $t3, $zero, L_8080072C
    if (ctx->r11 == 0) {
        // 0x80800714: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080072C;
    }
    // 0x80800714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800718: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x8080071C: jal         0x80084598
    // 0x80800720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baboost_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x80800720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800724: b           L_80800734
    // 0x80800728: nop

        goto L_80800734;
    // 0x80800728: nop

L_8080072C:
    // 0x8080072C: jal         0x80084598
    // 0x80800730: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _baboost_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x80800730: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_11:
L_80800734:
    // 0x80800734: jal         0x80084590
    // 0x80800738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baboost_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x80800738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080073C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800744: jal         0x80084C00
    // 0x80800748: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bafly_entrypoint_7(rdram, ctx);
        goto after_13;
    // 0x80800748: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x8080074C: lw          $v0, 0x160($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X160);
    // 0x80800750: beq         $v0, $zero, L_80800768
    if (ctx->r2 == 0) {
        // 0x80800754: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800768;
    }
    // 0x80800754: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800758: beq         $v0, $at, L_80800780
    if (ctx->r2 == ctx->r1) {
        // 0x8080075C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800780;
    }
    // 0x8080075C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800760: b           L_8080084C
    // 0x80800764: lui         $a1, 0x3E0B
    ctx->r5 = S32(0X3E0B << 16);
        goto L_8080084C;
    // 0x80800764: lui         $a1, 0x3E0B
    ctx->r5 = S32(0X3E0B << 16);
L_80800768:
    // 0x80800768: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8080076C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800770: beql        $t4, $zero, L_8080084C
    if (ctx->r12 == 0) {
        // 0x80800774: lui         $a1, 0x3E0B
        ctx->r5 = S32(0X3E0B << 16);
            goto L_8080084C;
    }
    goto skip_0;
    // 0x80800774: lui         $a1, 0x3E0B
    ctx->r5 = S32(0X3E0B << 16);
    skip_0:
    // 0x80800778: b           L_80800848
    // 0x8080077C: sw          $t5, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r13;
        goto L_80800848;
    // 0x8080077C: sw          $t5, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r13;
L_80800780:
    // 0x80800780: jal         0x80084C00
    // 0x80800784: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bafly_entrypoint_7(rdram, ctx);
        goto after_14;
    // 0x80800784: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80800788: jal         0x8009BFD8
    // 0x8080078C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BFD8(rdram, ctx);
        goto after_15;
    // 0x8080078C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800790: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800794: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800798: jal         0x800136E4
    // 0x8080079C: sub.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_16;
    // 0x8080079C: sub.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f4.fl;
    after_16:
    // 0x808007A0: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808007A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007A8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808007AC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808007B0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x808007B4: nop

    // 0x808007B8: bc1fl       L_808007E4
    if (!c1cs) {
        // 0x808007BC: mfc1        $a1, $f2
        ctx->r5 = (int32_t)ctx->f2.u32l;
            goto L_808007E4;
    }
    goto skip_1;
    // 0x808007BC: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    skip_1:
    // 0x808007C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808007C4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808007C8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808007CC: nop

    // 0x808007D0: bc1fl       L_808007E4
    if (!c1cs) {
        // 0x808007D4: mfc1        $a1, $f2
        ctx->r5 = (int32_t)ctx->f2.u32l;
            goto L_808007E4;
    }
    goto skip_2;
    // 0x808007D4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    skip_2:
    // 0x808007D8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808007DC: nop

    // 0x808007E0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_808007E4:
    // 0x808007E4: jal         0x8009BF5C
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BF5C(rdram, ctx);
        goto after_17;
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808007EC: jal         0x80084C70
    // 0x808007F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_21(rdram, ctx);
        goto after_18;
    // 0x808007F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808007F4: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x808007F8: beq         $v0, $zero, L_80800828
    if (ctx->r2 == 0) {
        // 0x808007FC: nop
    
            goto L_80800828;
    }
    // 0x808007FC: nop

    // 0x80800800: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80800804: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80800808: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080080C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800814: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800818: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8080081C: jal         0x8009BA58
    // 0x80800820: nop

    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_19;
    // 0x80800820: nop

    after_19:
    // 0x80800824: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_80800828:
    // 0x80800828: bne         $v0, $zero, L_80800848
    if (ctx->r2 != 0) {
        // 0x8080082C: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80800848;
    }
    // 0x8080082C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800830: lui         $a1, 0x3F1E
    ctx->r5 = S32(0X3F1E << 16);
    // 0x80800834: jal         0x8008B1BC
    // 0x80800838: ori         $a1, $a1, 0xB852
    ctx->r5 = ctx->r5 | 0XB852;
    anctrl_setDuration(rdram, ctx);
        goto after_20;
    // 0x80800838: ori         $a1, $a1, 0xB852
    ctx->r5 = ctx->r5 | 0XB852;
    after_20:
    // 0x8080083C: jal         0x80084C68
    // 0x80800840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_20(rdram, ctx);
        goto after_21;
    // 0x80800840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800844: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
L_80800848:
    // 0x80800848: lui         $a1, 0x3E0B
    ctx->r5 = S32(0X3E0B << 16);
L_8080084C:
    // 0x8080084C: ori         $a1, $a1, 0xF28
    ctx->r5 = ctx->r5 | 0XF28;
    // 0x80800850: jal         0x8008B348
    // 0x80800854: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    anctrl_isAt(rdram, ctx);
        goto after_22;
    // 0x80800854: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_22:
    // 0x80800858: beq         $v0, $zero, L_80800888
    if (ctx->r2 == 0) {
        // 0x8080085C: lui         $a2, 0x3F19
        ctx->r6 = S32(0X3F19 << 16);
            goto L_80800888;
    }
    // 0x8080085C: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x80800860: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x80800864: addiu       $t6, $zero, 0x2710
    ctx->r14 = ADD32(0, 0X2710);
    // 0x80800868: addiu       $t7, $zero, 0x2EE0
    ctx->r15 = ADD32(0, 0X2EE0);
    // 0x8080086C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800870: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800874: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80800878: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8080087C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800880: jal         0x8009DFD4
    // 0x80800884: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    func_8009DFD4(rdram, ctx);
        goto after_23;
    // 0x80800884: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    after_23:
L_80800888:
    // 0x80800888: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x8080088C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800890: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(96, 0X1D00) << 16);
    // 0x80800894: lwc1        $f8, 0x1D00($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(96, 0X1D00));
    // 0x80800898: lui         $at, 0xC42F
    ctx->r1 = S32(0XC42F << 16);
    // 0x8080089C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808008A0: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x808008A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808008A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008AC: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x808008B0: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    // 0x808008B4: lui         $a3, 0x4416
    ctx->r7 = S32(0X4416 << 16);
    // 0x808008B8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x808008BC: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x808008C0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x808008C4: jal         0x80084C08
    // 0x808008C8: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    _bafly_entrypoint_8(rdram, ctx);
        goto after_24;
    // 0x808008C8: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_24:
    // 0x808008CC: jal         0x80084C98
    // 0x808008D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_4(rdram, ctx);
        goto after_25;
    // 0x808008D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x808008D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808008D8: beq         $v0, $at, L_808008F4
    if (ctx->r2 == ctx->r1) {
        // 0x808008DC: nop
    
            goto L_808008F4;
    }
    // 0x808008DC: nop

    // 0x808008E0: jal         0x80097A90
    // 0x808008E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_beak_bust(rdram, ctx);
        goto after_26;
    // 0x808008E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x808008E8: beq         $v0, $zero, L_808008F4
    if (ctx->r2 == 0) {
        // 0x808008EC: addiu       $t8, $zero, 0xF
        ctx->r24 = ADD32(0, 0XF);
            goto L_808008F4;
    }
    // 0x808008EC: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x808008F0: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_808008F4:
    // 0x808008F4: jal         0x800D8FF8
    // 0x808008F8: nop

    func_800D8FF8(rdram, ctx);
        goto after_27;
    // 0x808008F8: nop

    after_27:
    // 0x808008FC: lw          $t9, 0x188($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X188);
    // 0x80800900: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800904: lwc1        $f18, 0x0($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80800908: jal         0x800F0E00
    // 0x8080090C: sub.s       $f12, $f18, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f0.fl;
    func_800F0E00(rdram, ctx);
        goto after_28;
    // 0x8080090C: sub.s       $f12, $f18, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f0.fl;
    after_28:
    // 0x80800910: lw          $t0, 0x188($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X188);
    // 0x80800914: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080091C: swc1        $f0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f0.u32l;
    // 0x80800920: lw          $t1, 0x188($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X188);
    // 0x80800924: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80800928: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8080092C: nop

    // 0x80800930: bc1f        L_8080096C
    if (!c1cs) {
        // 0x80800934: nop
    
            goto L_8080096C;
    }
    // 0x80800934: nop

    // 0x80800938: jal         0x80091A58
    // 0x8080093C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_29;
    // 0x8080093C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_29:
    // 0x80800940: beq         $v0, $zero, L_8080096C
    if (ctx->r2 == 0) {
        // 0x80800944: nop
    
            goto L_8080096C;
    }
    // 0x80800944: nop

    // 0x80800948: jal         0x8008D0E0
    // 0x8080094C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D0E0(rdram, ctx);
        goto after_30;
    // 0x8080094C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80800950: beq         $v0, $zero, L_8080096C
    if (ctx->r2 == 0) {
        // 0x80800954: nop
    
            goto L_8080096C;
    }
    // 0x80800954: nop

    // 0x80800958: jal         0x80084C28
    // 0x8080095C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_12(rdram, ctx);
        goto after_31;
    // 0x8080095C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80800960: beq         $v0, $zero, L_8080096C
    if (ctx->r2 == 0) {
        // 0x80800964: addiu       $t2, $zero, 0x2A
        ctx->r10 = ADD32(0, 0X2A);
            goto L_8080096C;
    }
    // 0x80800964: addiu       $t2, $zero, 0x2A
    ctx->r10 = ADD32(0, 0X2A);
    // 0x80800968: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_8080096C:
    // 0x8080096C: jal         0x8008E35C
    // 0x80800970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_32;
    // 0x80800970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80800974: beq         $v0, $zero, L_80800980
    if (ctx->r2 == 0) {
        // 0x80800978: addiu       $t3, $zero, 0x2D
        ctx->r11 = ADD32(0, 0X2D);
            goto L_80800980;
    }
    // 0x80800978: addiu       $t3, $zero, 0x2D
    ctx->r11 = ADD32(0, 0X2D);
    // 0x8080097C: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
L_80800980:
    // 0x80800980: jal         0x80084BD8
    // 0x80800984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_2(rdram, ctx);
        goto after_33;
    // 0x80800984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x80800988: beq         $v0, $zero, L_80800994
    if (ctx->r2 == 0) {
        // 0x8080098C: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80800994;
    }
    // 0x8080098C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80800990: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_80800994:
    // 0x80800994: jal         0x800845B0
    // 0x80800998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baboost_entrypoint_5(rdram, ctx);
        goto after_34;
    // 0x80800998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x8080099C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009A0: jal         0x8009E5C8
    // 0x808009A4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    bs_setState(rdram, ctx);
        goto after_35;
    // 0x808009A4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_35:
    // 0x808009A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808009AC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808009B0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808009B4: jr          $ra
    // 0x808009B8: nop

    return;
    // 0x808009B8: nop

;}
RECOMP_FUNC void func_800D5DB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5DB8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800D5DBC: lw          $t6, -0x4700($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4700);
    // 0x800D5DC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D5DC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D5DC8: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800D5DCC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D5DD0: addiu       $a1, $a1, -0x4BC0
    ctx->r5 = ADD32(ctx->r5, -0X4BC0);
    // 0x800D5DD4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800D5DD8: jal         0x8001E210
    // 0x800D5DDC: addu        $a0, $t6, $v0
    ctx->r4 = ADD32(ctx->r14, ctx->r2);
    rom_read_word(rdram, ctx);
        goto after_0;
    // 0x800D5DDC: addu        $a0, $t6, $v0
    ctx->r4 = ADD32(ctx->r14, ctx->r2);
    after_0:
    // 0x800D5DE0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800D5DE4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800D5DE8: lw          $t7, -0x4700($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4700);
    // 0x800D5DEC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D5DF0: addiu       $a1, $a1, -0x4BBC
    ctx->r5 = ADD32(ctx->r5, -0X4BBC);
    // 0x800D5DF4: addu        $a0, $t7, $v0
    ctx->r4 = ADD32(ctx->r15, ctx->r2);
    // 0x800D5DF8: jal         0x8001E210
    // 0x800D5DFC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    rom_read_word(rdram, ctx);
        goto after_1;
    // 0x800D5DFC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x800D5E00: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800D5E04: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800D5E08: lw          $t0, -0x4BC0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4BC0);
    // 0x800D5E0C: lw          $t8, -0x4BBC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4BBC);
    // 0x800D5E10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D5E14: srl         $t1, $t0, 6
    ctx->r9 = S32(U32(ctx->r8) >> 6);
    // 0x800D5E18: srl         $t9, $t8, 6
    ctx->r25 = S32(U32(ctx->r24) >> 6);
    // 0x800D5E1C: subu        $v0, $t9, $t1
    ctx->r2 = SUB32(ctx->r25, ctx->r9);
    // 0x800D5E20: jr          $ra
    // 0x800D5E24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800D5E24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _chblink_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800857C8: syscall     175
    recomp_syscall_handler(rdram, ctx, 0x800857C8);
    return;
    // 0x800857CC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808000C8_chminisubgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808000CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000D0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x808000D4: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808000D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000DC: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x808000E0: beq         $t7, $at, L_80800300
    if (ctx->r15 == ctx->r1) {
        // 0x808000E4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800300;
    }
    // 0x808000E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000E8: beq         $t7, $at, L_80800104
    if (ctx->r15 == ctx->r1) {
        // 0x808000EC: addiu       $a0, $zero, 0xFC
        ctx->r4 = ADD32(0, 0XFC);
            goto L_80800104;
    }
    // 0x808000EC: addiu       $a0, $zero, 0xFC
    ctx->r4 = ADD32(0, 0XFC);
    // 0x808000F0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808000F4: beq         $t7, $at, L_808003A4
    if (ctx->r15 == ctx->r1) {
        // 0x808000F8: addiu       $a0, $zero, 0x1F
        ctx->r4 = ADD32(0, 0X1F);
            goto L_808003A4;
    }
    // 0x808000F8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x808000FC: b           L_80800424
    // 0x80800100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800424;
    // 0x80800100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800104:
    // 0x80800104: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80800108: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080010C: jal         0x800D24E8
    // 0x80800110: lw          $a1, 0x28($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X28);
    func_800D24E8(rdram, ctx);
        goto after_0;
    // 0x80800110: lw          $a1, 0x28($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X28);
    after_0:
    // 0x80800114: jal         0x800CEAD0
    // 0x80800118: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_1;
    // 0x80800118: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8080011C: beq         $v0, $zero, L_80800300
    if (ctx->r2 == 0) {
        // 0x80800120: addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
            goto L_80800300;
    }
    // 0x80800120: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80800124: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80800128: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x8080012C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800130: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    // 0x80800134: jal         0x800D2054
    // 0x80800138: lw          $a2, 0x28($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X28);
    func_800D2054(rdram, ctx);
        goto after_2;
    // 0x80800138: lw          $a2, 0x28($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X28);
    after_2:
    // 0x8080013C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800140: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800144: jal         0x80100094
    // 0x80800148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80800148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8080014C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800150: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800154: addiu       $a1, $zero, 0x5AA
    ctx->r5 = ADD32(0, 0X5AA);
    // 0x80800158: jal         0x800BF99C
    // 0x8080015C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800BF99C(rdram, ctx);
        goto after_4;
    // 0x8080015C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80800160: jal         0x80090708
    // 0x80800164: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80090708(rdram, ctx);
        goto after_5;
    // 0x80800164: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x80800168: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8080016C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800170: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800174: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800178: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080017C: jal         0x8008A2C8
    // 0x80800180: addiu       $a1, $a1, 0x30C
    ctx->r5 = ADD32(ctx->r5, 0X30C);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x80800180: addiu       $a1, $a1, 0x30C
    ctx->r5 = ADD32(ctx->r5, 0X30C);
    after_6:
    // 0x80800184: addiu       $a0, $zero, 0x4AE
    ctx->r4 = ADD32(0, 0X4AE);
    // 0x80800188: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    // 0x8080018C: jal         0x80101180
    // 0x80800190: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_7;
    // 0x80800190: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80800194: jal         0x800D395C
    // 0x80800198: nop

    func_800D395C(rdram, ctx);
        goto after_8;
    // 0x80800198: nop

    after_8:
    // 0x8080019C: beq         $v0, $zero, L_808001E4
    if (ctx->r2 == 0) {
        // 0x808001A0: addiu       $a0, $zero, 0x1F
        ctx->r4 = ADD32(0, 0X1F);
            goto L_808001E4;
    }
    // 0x808001A0: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x808001A4: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x808001A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001AC: addiu       $t1, $zero, 0x104A
    ctx->r9 = ADD32(0, 0X104A);
    // 0x808001B0: bne         $v0, $at, L_808001C0
    if (ctx->r2 != ctx->r1) {
        // 0x808001B4: addiu       $a1, $zero, 0x16
        ctx->r5 = ADD32(0, 0X16);
            goto L_808001C0;
    }
    // 0x808001B4: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x808001B8: b           L_808002B8
    // 0x808001BC: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
        goto L_808002B8;
    // 0x808001BC: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_808001C0:
    // 0x808001C0: bne         $v0, $zero, L_808001D8
    if (ctx->r2 != 0) {
        // 0x808001C4: addiu       $t3, $zero, 0x104C
        ctx->r11 = ADD32(0, 0X104C);
            goto L_808001D8;
    }
    // 0x808001C4: addiu       $t3, $zero, 0x104C
    ctx->r11 = ADD32(0, 0X104C);
    // 0x808001C8: addiu       $t2, $zero, 0x104B
    ctx->r10 = ADD32(0, 0X104B);
    // 0x808001CC: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x808001D0: b           L_808002B8
    // 0x808001D4: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
        goto L_808002B8;
    // 0x808001D4: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
L_808001D8:
    // 0x808001D8: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x808001DC: b           L_808002B8
    // 0x808001E0: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
        goto L_808002B8;
    // 0x808001E0: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
L_808001E4:
    // 0x808001E4: jal         0x800D0A9C
    // 0x808001E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_9;
    // 0x808001E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x808001EC: bne         $v0, $zero, L_80800218
    if (ctx->r2 != 0) {
        // 0x808001F0: lw          $t4, 0x48($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X48);
            goto L_80800218;
    }
    // 0x808001F0: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x808001F4: lw          $t5, 0x28($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X28);
    // 0x808001F8: addiu       $t6, $zero, 0x1030
    ctx->r14 = ADD32(0, 0X1030);
    // 0x808001FC: addiu       $t7, $zero, 0x44
    ctx->r15 = ADD32(0, 0X44);
    // 0x80800200: slti        $at, $t5, 0x3C
    ctx->r1 = SIGNED(ctx->r13) < 0X3C ? 1 : 0;
    // 0x80800204: bne         $at, $zero, L_80800218
    if (ctx->r1 != 0) {
        // 0x80800208: addiu       $a1, $zero, 0x16
        ctx->r5 = ADD32(0, 0X16);
            goto L_80800218;
    }
    // 0x80800208: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x8080020C: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x80800210: b           L_808002B8
    // 0x80800214: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
        goto L_808002B8;
    // 0x80800214: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
L_80800218:
    // 0x80800218: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x8080021C: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80800220: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80800224: jal         0x800D0A9C
    // 0x80800228: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_10;
    // 0x80800228: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x8080022C: bne         $v0, $zero, L_8080027C
    if (ctx->r2 != 0) {
        // 0x80800230: lw          $t3, 0x38($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X38);
            goto L_8080027C;
    }
    // 0x80800230: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80800234: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80800238: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080023C: addiu       $t1, $zero, 0x1034
    ctx->r9 = ADD32(0, 0X1034);
    // 0x80800240: lw          $v0, 0x28($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X28);
    // 0x80800244: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x80800248: beq         $v0, $zero, L_80800268
    if (ctx->r2 == 0) {
        // 0x8080024C: nop
    
            goto L_80800268;
    }
    // 0x8080024C: nop

    // 0x80800250: beq         $v0, $at, L_80800270
    if (ctx->r2 == ctx->r1) {
        // 0x80800254: addiu       $t2, $zero, 0x1046
        ctx->r10 = ADD32(0, 0X1046);
            goto L_80800270;
    }
    // 0x80800254: addiu       $t2, $zero, 0x1046
    ctx->r10 = ADD32(0, 0X1046);
    // 0x80800258: addiu       $t0, $zero, 0x1032
    ctx->r8 = ADD32(0, 0X1032);
    // 0x8080025C: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x80800260: b           L_808002B8
    // 0x80800264: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
        goto L_808002B8;
    // 0x80800264: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
L_80800268:
    // 0x80800268: b           L_808002B8
    // 0x8080026C: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
        goto L_808002B8;
    // 0x8080026C: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_80800270:
    // 0x80800270: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x80800274: b           L_808002B8
    // 0x80800278: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
        goto L_808002B8;
    // 0x80800278: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
L_8080027C:
    // 0x8080027C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800280: bne         $t3, $at, L_80800298
    if (ctx->r11 != ctx->r1) {
        // 0x80800284: lw          $t5, 0x48($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X48);
            goto L_80800298;
    }
    // 0x80800284: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80800288: addiu       $t4, $zero, 0x1031
    ctx->r12 = ADD32(0, 0X1031);
    // 0x8080028C: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x80800290: b           L_808002B8
    // 0x80800294: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
        goto L_808002B8;
    // 0x80800294: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
L_80800298:
    // 0x80800298: lw          $t6, 0x28($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X28);
    // 0x8080029C: addiu       $t8, $zero, 0x1034
    ctx->r24 = ADD32(0, 0X1034);
    // 0x808002A0: addiu       $t7, $zero, 0x1033
    ctx->r15 = ADD32(0, 0X1033);
    // 0x808002A4: beq         $t6, $zero, L_808002B4
    if (ctx->r14 == 0) {
        // 0x808002A8: addiu       $a1, $zero, 0x17
        ctx->r5 = ADD32(0, 0X17);
            goto L_808002B4;
    }
    // 0x808002A8: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x808002AC: b           L_808002B8
    // 0x808002B0: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
        goto L_808002B8;
    // 0x808002B0: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_808002B4:
    // 0x808002B4: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_808002B8:
    // 0x808002B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808002BC: jal         0x800FDC28
    // 0x808002C0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_800FDC28(rdram, ctx);
        goto after_11;
    // 0x808002C0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_11:
    // 0x808002C4: jal         0x800FC6B0
    // 0x808002C8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800FC6B0(rdram, ctx);
        goto after_12;
    // 0x808002C8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_12:
    // 0x808002CC: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x808002D0: addiu       $t0, $zero, 0x22
    ctx->r8 = ADD32(0, 0X22);
    // 0x808002D4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x808002D8: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x808002DC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808002E0: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x808002E4: jal         0x8008A208
    // 0x808002E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_13;
    // 0x808002E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_13:
    // 0x808002EC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808002F0: jal         0x80101FDC
    // 0x808002F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_14;
    // 0x808002F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_14:
    // 0x808002F8: b           L_80800424
    // 0x808002FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800424;
    // 0x808002FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800300:
    // 0x80800300: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80800304: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x80800308: slti        $at, $t2, 0xF
    ctx->r1 = SIGNED(ctx->r10) < 0XF ? 1 : 0;
    // 0x8080030C: beq         $at, $zero, L_80800420
    if (ctx->r1 == 0) {
        // 0x80800310: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(792, 0X1370) << 16);
            goto L_80800420;
    }
    // 0x80800310: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(792, 0X1370) << 16);
    // 0x80800314: jal         0x800DC298
    // 0x80800318: lwc1        $f12, 0x1370($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(792, 0X1370));
    func_800DC298(rdram, ctx);
        goto after_15;
    // 0x80800318: lwc1        $f12, 0x1370($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(792, 0X1370));
    after_15:
    // 0x8080031C: beql        $v0, $zero, L_80800424
    if (ctx->r2 == 0) {
        // 0x80800320: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800424;
    }
    goto skip_0;
    // 0x80800320: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800324: jal         0x80800AAC
    // 0x80800328: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80800AAC_chminisubgame(rdram, ctx);
        goto after_16;
    // 0x80800328: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_16:
    // 0x8080032C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80800330: jal         0x800DC0C0
    // 0x80800334: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_800DC0C0(rdram, ctx);
        goto after_17;
    // 0x80800334: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_17:
    // 0x80800338: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(792, 0X1374) << 16);
    // 0x8080033C: lwc1        $f4, 0x1374($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(792, 0X1374));
    // 0x80800340: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800344: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80800348: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8080034C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800350: bc1fl       L_80800364
    if (!c1cs) {
        // 0x80800354: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80800364;
    }
    goto skip_1;
    // 0x80800354: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_1:
    // 0x80800358: b           L_8080037C
    // 0x8080035C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_8080037C;
    // 0x8080035C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80800360: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80800364:
    // 0x80800364: nop

    // 0x80800368: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8080036C: nop

    // 0x80800370: bc1fl       L_80800380
    if (!c1cs) {
        // 0x80800374: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80800380;
    }
    goto skip_2;
    // 0x80800374: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_2:
    // 0x80800378: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8080037C:
    // 0x8080037C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_80800380:
    // 0x80800380: beql        $a2, $at, L_80800424
    if (ctx->r6 == ctx->r1) {
        // 0x80800384: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800424;
    }
    goto skip_3;
    // 0x80800384: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80800388: sh          $v1, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r3;
    // 0x8080038C: sh          $a2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r6;
    // 0x80800390: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800394: jal         0x80108B04
    // 0x80800398: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80108B04(rdram, ctx);
        goto after_18;
    // 0x80800398: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_18:
    // 0x8080039C: b           L_80800424
    // 0x808003A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800424;
    // 0x808003A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003A4:
    // 0x808003A4: jal         0x800D0B68
    // 0x808003A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_19;
    // 0x808003A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x808003AC: beq         $v0, $zero, L_80800420
    if (ctx->r2 == 0) {
        // 0x808003B0: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80800420;
    }
    // 0x808003B0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808003B4: jal         0x800D90A4
    // 0x808003B8: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800D90A4(rdram, ctx);
        goto after_20;
    // 0x808003B8: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_20:
    // 0x808003BC: beq         $v0, $zero, L_80800420
    if (ctx->r2 == 0) {
        // 0x808003C0: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80800420;
    }
    // 0x808003C0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808003C4: jal         0x80100094
    // 0x808003C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_21;
    // 0x808003C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x808003CC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808003D0: jal         0x80090708
    // 0x808003D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80090708(rdram, ctx);
        goto after_22;
    // 0x808003D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_22:
    // 0x808003D8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808003DC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808003E0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808003E4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808003E8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808003EC: jal         0x8008A2C8
    // 0x808003F0: addiu       $a1, $a1, 0x30C
    ctx->r5 = ADD32(ctx->r5, 0X30C);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_23;
    // 0x808003F0: addiu       $a1, $a1, 0x30C
    ctx->r5 = ADD32(ctx->r5, 0X30C);
    after_23:
    // 0x808003F4: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x808003F8: addiu       $t4, $zero, 0x22
    ctx->r12 = ADD32(0, 0X22);
    // 0x808003FC: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x80800400: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x80800404: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800408: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x8080040C: jal         0x8008A208
    // 0x80800410: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_24;
    // 0x80800410: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_24:
    // 0x80800414: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800418: jal         0x80101FDC
    // 0x8080041C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_25;
    // 0x8080041C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_25:
L_80800420:
    // 0x80800420: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800424:
    // 0x80800424: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800428: jr          $ra
    // 0x8080042C: nop

    return;
    // 0x8080042C: nop

;}
RECOMP_FUNC void func_808008D0_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008D8: jal         0x808006F0
    // 0x808008DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bstrexlarge_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808008DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808008E0: jal         0x80082FE0
    // 0x808008E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808008E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808008E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008F0: jr          $ra
    // 0x808008F4: nop

    return;
    // 0x808008F4: nop

;}
RECOMP_FUNC void ncbastring_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x808000A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000AC: jal         0x8080007C
    // 0x808000B0: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_8080007C_ncbastring(rdram, ctx);
        goto after_0;
    // 0x808000B0: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_0:
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B8: jal         0x801107F0
    // 0x808000BC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_801107F0(rdram, ctx);
        goto after_1;
    // 0x808000BC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_1:
    // 0x808000C0: lw          $t6, 0x5C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X5C);
    // 0x808000C4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x808000C8: beq         $t7, $zero, L_808000E4
    if (ctx->r15 == 0) {
        // 0x808000CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000E4;
    }
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D0: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x808000D4: jal         0x80089468
    // 0x808000D8: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    _ncbawaypoint_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808000D8: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_2:
    // 0x808000DC: b           L_808000F0
    // 0x808000E0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
        goto L_808000F0;
    // 0x808000E0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
L_808000E4:
    // 0x808000E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808000E8: nop

    // 0x808000EC: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
L_808000F0:
    // 0x808000F0: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x808000F4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x808000F8: jal         0x800EFB24
    // 0x808000FC: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    func_800EFB24(rdram, ctx);
        goto after_3;
    // 0x808000FC: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_3:
    // 0x80800100: jal         0x800EEF94
    // 0x80800104: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    func_800EEF94(rdram, ctx);
        goto after_4;
    // 0x80800104: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_4:
    // 0x80800108: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080010C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80800110: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800114: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80800118: jal         0x800F1A88
    // 0x8080011C: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    func_800F1A88(rdram, ctx);
        goto after_5;
    // 0x8080011C: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x80800120: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800124: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800128: nop

    // 0x8080012C: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x80800130: nop

    // 0x80800134: bc1f        L_80800148
    if (!c1cs) {
        // 0x80800138: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800148;
    }
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800140: jal         0x80113978
    // 0x80800144: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80113978(rdram, ctx);
        goto after_6;
    // 0x80800144: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
L_80800148:
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: jal         0x80115358
    // 0x80800150: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80115358(rdram, ctx);
        goto after_7;
    // 0x80800150: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800158: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080015C: jal         0x80115750
    // 0x80800160: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    func_80115750(rdram, ctx);
        goto after_8;
    // 0x80800160: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x80800164: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080016C: jal         0x80112C3C
    // 0x80800170: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80112C3C(rdram, ctx);
        goto after_9;
    // 0x80800170: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_9:
    // 0x80800174: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800178: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080017C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80800180: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80800184: sub.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x80800188: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8080018C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800190: jal         0x800EEBF0
    // 0x80800194: nop

    func_800EEBF0(rdram, ctx);
        goto after_10;
    // 0x80800194: nop

    after_10:
    // 0x80800198: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8080019C: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x808001A0: jal         0x800EE780
    // 0x808001A4: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    func_800EE780(rdram, ctx);
        goto after_11;
    // 0x808001A4: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    after_11:
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001AC: jal         0x80111CC8
    // 0x808001B0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_80111CC8(rdram, ctx);
        goto after_12;
    // 0x808001B0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_12:
    // 0x808001B4: beql        $v0, $zero, L_80800260
    if (ctx->r2 == 0) {
        // 0x808001B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800260;
    }
    goto skip_0;
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808001BC: jal         0x801138A0
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138A0(rdram, ctx);
        goto after_13;
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808001C4: bne         $v0, $zero, L_80800244
    if (ctx->r2 != 0) {
        // 0x808001C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800244;
    }
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001CC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808001D0: jal         0x80115444
    // 0x808001D4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_80115444(rdram, ctx);
        goto after_14;
    // 0x808001D4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_14:
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001DC: jal         0x801107F0
    // 0x808001E0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_801107F0(rdram, ctx);
        goto after_15;
    // 0x808001E0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_15:
    // 0x808001E4: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x808001E8: jal         0x800EEAD4
    // 0x808001EC: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_800EEAD4(rdram, ctx);
        goto after_16;
    // 0x808001EC: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_16:
    // 0x808001F0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808001F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001F8: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808001FC: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800200: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800204: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80800208: nop

    // 0x8080020C: bc1fl       L_80800260
    if (!c1cs) {
        // 0x80800210: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800260;
    }
    goto skip_1;
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800214: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80800218: nop

    // 0x8080021C: bc1fl       L_80800260
    if (!c1cs) {
        // 0x80800220: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800260;
    }
    goto skip_2;
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800224: jal         0x801138F4
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138F4(rdram, ctx);
        goto after_17;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8080022C: beql        $v0, $zero, L_80800260
    if (ctx->r2 == 0) {
        // 0x80800230: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800260;
    }
    goto skip_3;
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80800234: jal         0x80110F44
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80110F44(rdram, ctx);
        goto after_18;
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8080023C: b           L_80800260
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800260;
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800244:
    // 0x80800244: jal         0x801138F4
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138F4(rdram, ctx);
        goto after_19;
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8080024C: beql        $v0, $zero, L_80800260
    if (ctx->r2 == 0) {
        // 0x80800250: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800260;
    }
    goto skip_4;
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x80800254: jal         0x80110F44
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80110F44(rdram, ctx);
        goto after_20;
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800260:
    // 0x80800260: jal         0x80800008
    // 0x80800264: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_80800008_ncbastring(rdram, ctx);
        goto after_21;
    // 0x80800264: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_21:
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080026C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800270: jal         0x80110A68
    // 0x80800274: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    func_80110A68(rdram, ctx);
        goto after_22;
    // 0x80800274: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_22:
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080027C: jal         0x80110790
    // 0x80800280: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_80110790(rdram, ctx);
        goto after_23;
    // 0x80800280: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_23:
    // 0x80800284: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800288: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080028C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80800290: jr          $ra
    // 0x80800294: nop

    return;
    // 0x80800294: nop

;}
RECOMP_FUNC void func_80800000_chglowbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x80100094
    // 0x8080000C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080000C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800010: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1628, 0X1460) << 16);
    // 0x80800014: addiu       $t6, $t6, 0x1460
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1628, 0X1460));
    // 0x80800018: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8080001C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80800020: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800024: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x80800028: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8080002C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80800030: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80800034: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x80800038: lbu         $t0, 0x16($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X16);
    // 0x8080003C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800040: bne         $t0, $at, L_80800080
    if (ctx->r8 != ctx->r1) {
        // 0x80800044: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800080;
    }
    // 0x80800044: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800048: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080004C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1628, 0X1360) << 16);
    // 0x80800050: lwc1        $f6, 0x1360($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1628, 0X1360));
    // 0x80800054: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800058: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080005C: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80800060: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800064: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800068: nop

    // 0x8080006C: bc1fl       L_808000C0
    if (!c1cs) {
        // 0x80800070: lw          $t2, 0x18($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X18);
            goto L_808000C0;
    }
    goto skip_0;
    // 0x80800070: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80800074: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80800078: b           L_808000BC
    // 0x8080007C: sb          $zero, 0x16($v0)
    MEM_B(0X16, ctx->r2) = 0;
        goto L_808000BC;
    // 0x8080007C: sb          $zero, 0x16($v0)
    MEM_B(0X16, ctx->r2) = 0;
L_80800080:
    // 0x80800080: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1628, 0X1364) << 16);
    // 0x80800084: lwc1        $f0, 0x1364($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1628, 0X1364));
    // 0x80800088: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1628, 0X1368) << 16);
    // 0x8080008C: lwc1        $f18, 0x1368($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1628, 0X1368));
    // 0x80800090: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800094: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800098: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8080009C: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x808000A0: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x808000A4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x808000A8: nop

    // 0x808000AC: bc1fl       L_808000C0
    if (!c1cs) {
        // 0x808000B0: lw          $t2, 0x18($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X18);
            goto L_808000C0;
    }
    goto skip_1;
    // 0x808000B0: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x808000B4: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x808000B8: sb          $t1, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r9;
L_808000BC:
    // 0x808000BC: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
L_808000C0:
    // 0x808000C0: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x808000C4: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x808000C8: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x808000CC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808000D0: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x808000D4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808000D8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808000DC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808000E0: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x808000E4: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x808000E8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x808000EC: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x808000F0: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x808000F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808000F8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808000FC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800100: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x80800104: nop

    // 0x80800108: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8080010C: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800110: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800114: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800118: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x8080011C: nop

    // 0x80800120: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80800124: jal         0x800C8E84
    // 0x80800128: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    func_800C8E84(rdram, ctx);
        goto after_1;
    // 0x80800128: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    after_1:
    // 0x8080012C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800130: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800134: jr          $ra
    // 0x80800138: nop

    return;
    // 0x80800138: nop

;}
RECOMP_FUNC void func_80101A50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101A50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101A54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101A58: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80101A5C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80101A60: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80101A64: bltzl       $t8, L_80101B5C
    if (SIGNED(ctx->r24) < 0) {
        // 0x80101A68: lw          $a1, 0x78($a2)
        ctx->r5 = MEM_W(ctx->r6, 0X78);
            goto L_80101B5C;
    }
    goto skip_0;
    // 0x80101A68: lw          $a1, 0x78($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X78);
    skip_0:
    // 0x80101A6C: lw          $v1, 0x78($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X78);
    // 0x80101A70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80101A74: sll         $v0, $v1, 18
    ctx->r2 = S32(ctx->r3 << 18);
    // 0x80101A78: srl         $t9, $v0, 30
    ctx->r25 = S32(U32(ctx->r2) >> 30);
    // 0x80101A7C: beq         $t9, $zero, L_80101AA0
    if (ctx->r25 == 0) {
        // 0x80101A80: nop
    
            goto L_80101AA0;
    }
    // 0x80101A80: nop

    // 0x80101A84: beq         $t9, $at, L_80101AD8
    if (ctx->r25 == ctx->r1) {
        // 0x80101A88: sll         $v0, $v1, 20
        ctx->r2 = S32(ctx->r3 << 20);
            goto L_80101AD8;
    }
    // 0x80101A88: sll         $v0, $v1, 20
    ctx->r2 = S32(ctx->r3 << 20);
    // 0x80101A8C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80101A90: beq         $t9, $at, L_80101B1C
    if (ctx->r25 == ctx->r1) {
        // 0x80101A94: sll         $t3, $v1, 20
        ctx->r11 = S32(ctx->r3 << 20);
            goto L_80101B1C;
    }
    // 0x80101A94: sll         $t3, $v1, 20
    ctx->r11 = S32(ctx->r3 << 20);
    // 0x80101A98: b           L_80101B5C
    // 0x80101A9C: lw          $a1, 0x78($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X78);
        goto L_80101B5C;
    // 0x80101A9C: lw          $a1, 0x78($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X78);
L_80101AA0:
    // 0x80101AA0: jal         0x800DC0C0
    // 0x80101AA4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x80101AA4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80101AA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80101AAC: lwc1        $f4, 0x6434($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6434);
    // 0x80101AB0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80101AB4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80101AB8: nop

    // 0x80101ABC: bc1fl       L_80101B5C
    if (!c1cs) {
        // 0x80101AC0: lw          $a1, 0x78($a2)
        ctx->r5 = MEM_W(ctx->r6, 0X78);
            goto L_80101B5C;
    }
    goto skip_1;
    // 0x80101AC0: lw          $a1, 0x78($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X78);
    skip_1:
    // 0x80101AC4: lbu         $t0, 0x7A($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X7A);
    // 0x80101AC8: andi        $t1, $t0, 0xFFCF
    ctx->r9 = ctx->r8 & 0XFFCF;
    // 0x80101ACC: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x80101AD0: b           L_80101B58
    // 0x80101AD4: sb          $t2, 0x7A($a2)
    MEM_B(0X7A, ctx->r6) = ctx->r10;
        goto L_80101B58;
    // 0x80101AD4: sb          $t2, 0x7A($a2)
    MEM_B(0X7A, ctx->r6) = ctx->r10;
L_80101AD8:
    // 0x80101AD8: srl         $t3, $v0, 29
    ctx->r11 = S32(U32(ctx->r2) >> 29);
    // 0x80101ADC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80101AE0: bne         $t3, $at, L_80101AFC
    if (ctx->r11 != ctx->r1) {
        // 0x80101AE4: or          $v0, $t3, $zero
        ctx->r2 = ctx->r11 | 0;
            goto L_80101AFC;
    }
    // 0x80101AE4: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80101AE8: lbu         $t4, 0x7A($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X7A);
    // 0x80101AEC: andi        $t5, $t4, 0xFFCF
    ctx->r13 = ctx->r12 & 0XFFCF;
    // 0x80101AF0: ori         $t6, $t5, 0x20
    ctx->r14 = ctx->r13 | 0X20;
    // 0x80101AF4: b           L_80101B58
    // 0x80101AF8: sb          $t6, 0x7A($a2)
    MEM_B(0X7A, ctx->r6) = ctx->r14;
        goto L_80101B58;
    // 0x80101AF8: sb          $t6, 0x7A($a2)
    MEM_B(0X7A, ctx->r6) = ctx->r14;
L_80101AFC:
    // 0x80101AFC: lbu         $t0, 0x7A($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X7A);
    // 0x80101B00: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x80101B04: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80101B08: andi        $t9, $t8, 0xE
    ctx->r25 = ctx->r24 & 0XE;
    // 0x80101B0C: andi        $t1, $t0, 0xFFF1
    ctx->r9 = ctx->r8 & 0XFFF1;
    // 0x80101B10: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80101B14: b           L_80101B58
    // 0x80101B18: sb          $t2, 0x7A($a2)
    MEM_B(0X7A, ctx->r6) = ctx->r10;
        goto L_80101B58;
    // 0x80101B18: sb          $t2, 0x7A($a2)
    MEM_B(0X7A, ctx->r6) = ctx->r10;
L_80101B1C:
    // 0x80101B1C: lbu         $t8, 0x7A($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X7A);
    // 0x80101B20: srl         $t4, $t3, 29
    ctx->r12 = S32(U32(ctx->r11) >> 29);
    // 0x80101B24: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80101B28: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80101B2C: andi        $t7, $t6, 0xE
    ctx->r15 = ctx->r14 & 0XE;
    // 0x80101B30: andi        $t0, $t8, 0xFFF1
    ctx->r8 = ctx->r24 & 0XFFF1;
    // 0x80101B34: or          $t9, $t7, $t0
    ctx->r25 = ctx->r15 | ctx->r8;
    // 0x80101B38: sb          $t9, 0x7A($a2)
    MEM_B(0X7A, ctx->r6) = ctx->r25;
    // 0x80101B3C: lw          $t1, 0x78($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X78);
    // 0x80101B40: andi        $t5, $t9, 0xCF
    ctx->r13 = ctx->r25 & 0XCF;
    // 0x80101B44: sll         $t2, $t1, 20
    ctx->r10 = S32(ctx->r9 << 20);
    // 0x80101B48: srl         $t3, $t2, 29
    ctx->r11 = S32(U32(ctx->r10) >> 29);
    // 0x80101B4C: bnel        $t3, $zero, L_80101B5C
    if (ctx->r11 != 0) {
        // 0x80101B50: lw          $a1, 0x78($a2)
        ctx->r5 = MEM_W(ctx->r6, 0X78);
            goto L_80101B5C;
    }
    goto skip_2;
    // 0x80101B50: lw          $a1, 0x78($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X78);
    skip_2:
    // 0x80101B54: sb          $t5, 0x7A($a2)
    MEM_B(0X7A, ctx->r6) = ctx->r13;
L_80101B58:
    // 0x80101B58: lw          $a1, 0x78($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X78);
L_80101B5C:
    // 0x80101B5C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80101B60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80101B64: sll         $t6, $a1, 20
    ctx->r14 = S32(ctx->r5 << 20);
    // 0x80101B68: srl         $t8, $t6, 29
    ctx->r24 = S32(U32(ctx->r14) >> 29);
    // 0x80101B6C: jal         0x800DF744
    // 0x80101B70: addiu       $a1, $t8, 0x1
    ctx->r5 = ADD32(ctx->r24, 0X1);
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x80101B70: addiu       $a1, $t8, 0x1
    ctx->r5 = ADD32(ctx->r24, 0X1);
    after_1:
    // 0x80101B74: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80101B78: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80101B7C: lw          $a1, 0x78($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X78);
    // 0x80101B80: sll         $t7, $a1, 20
    ctx->r15 = S32(ctx->r5 << 20);
    // 0x80101B84: srl         $t0, $t7, 29
    ctx->r8 = S32(U32(ctx->r15) >> 29);
    // 0x80101B88: jal         0x800DF744
    // 0x80101B8C: addiu       $a1, $t0, 0x1
    ctx->r5 = ADD32(ctx->r8, 0X1);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x80101B8C: addiu       $a1, $t0, 0x1
    ctx->r5 = ADD32(ctx->r8, 0X1);
    after_2:
    // 0x80101B90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101B94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101B98: jr          $ra
    // 0x80101B9C: nop

    return;
    // 0x80101B9C: nop

;}
RECOMP_FUNC void _chweldarbossdoors_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086618: syscall     349
    recomp_syscall_handler(rdram, ctx, 0x80086618);
    return;
    // 0x8008661C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800508_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800508: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080050C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800510: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800514: jal         0x800EB854
    // 0x80800518: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800EB854(rdram, ctx);
        goto after_0;
    // 0x80800518: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080051C: beq         $v0, $zero, L_8080054C
    if (ctx->r2 == 0) {
        // 0x80800520: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080054C;
    }
    // 0x80800520: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800524: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800528: bnel        $v0, $at, L_8080055C
    if (ctx->r2 != ctx->r1) {
        // 0x8080052C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080055C;
    }
    goto skip_0;
    // 0x8080052C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800530: jal         0x80100094
    // 0x80800534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800538: addiu       $a0, $v0, 0x10C
    ctx->r4 = ADD32(ctx->r2, 0X10C);
    // 0x8080053C: jal         0x80087CA0
    // 0x80800540: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _gcnewoption_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800540: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800544: b           L_8080055C
    // 0x80800548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080055C;
    // 0x80800548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080054C:
    // 0x8080054C: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80800550: jal         0x80101808
    // 0x80800554: addiu       $a1, $a1, 0x17D0
    ctx->r5 = ADD32(ctx->r5, 0X17D0);
    func_80101808(rdram, ctx);
        goto after_3;
    // 0x80800554: addiu       $a1, $a1, 0x17D0
    ctx->r5 = ADD32(ctx->r5, 0X17D0);
    after_3:
    // 0x80800558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080055C:
    // 0x8080055C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800560: jr          $ra
    // 0x80800564: nop

    return;
    // 0x80800564: nop

;}
RECOMP_FUNC void func_808074D0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808074D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808074D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808074D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808074DC: jal         0x800936E8
    // 0x808074E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800936E8(rdram, ctx);
        goto after_0;
    // 0x808074E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808074E4: jal         0x800839B8
    // 0x808074E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x808074E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808074EC: jal         0x80807C8C
    // 0x808074F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80807C8C_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x808074F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808074F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808074F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808074FC: jr          $ra
    // 0x80807500: nop

    return;
    // 0x80807500: nop

;}
RECOMP_FUNC void func_80800AF4_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AF4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800AF8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800AFC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800B00: sltiu       $at, $a1, 0x5
    ctx->r1 = ctx->r5 < 0X5 ? 1 : 0;
    // 0x80800B04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B08: beq         $at, $zero, L_80800D38
    if (ctx->r1 == 0) {
        // 0x80800B0C: sb          $a1, 0x15C($a0)
        MEM_B(0X15C, ctx->r4) = ctx->r5;
            goto L_80800D38;
    }
    // 0x80800B0C: sb          $a1, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = ctx->r5;
    // 0x80800B10: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80800B14: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(41, 0X1DC0) << 16);
    // 0x80800B18: addu        $at, $at, $t6
    gpr jr_addend_80800B20 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800B1C: lw          $t6, 0x1DC0($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(41, 0X1DC0));
    // 0x80800B20: jr          $t6
    // 0x80800B24: nop

    switch (jr_addend_80800B20 >> 2) {
        case 0: goto L_80800D10; break;
        case 1: goto L_80800B28; break;
        case 2: goto L_80800C6C; break;
        case 3: goto L_80800C88; break;
        case 4: goto L_80800CC0; break;
        default: switch_error(__func__, 0x80800B20, 0x80801DC0);
    }
    // 0x80800B24: nop

L_80800B28:
    // 0x80800B28: jal         0x8008CABC
    // 0x80800B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800B30: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800B34: jal         0x80800A78
    // 0x80800B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A78_bsbansack(rdram, ctx);
        goto after_1;
    // 0x80800B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800B3C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(41, 0X1DD4) << 16);
    // 0x80800B40: lwc1        $f12, 0x1DD4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1DD4));
    // 0x80800B44: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(41, 0X1DD8) << 16);
    // 0x80800B48: jal         0x800DC178
    // 0x80800B4C: lwc1        $f14, 0x1DD8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1DD8));
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800B4C: lwc1        $f14, 0x1DD8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1DD8));
    after_2:
    // 0x80800B50: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B58: addiu       $a1, $zero, 0x3F0
    ctx->r5 = ADD32(0, 0X3F0);
    // 0x80800B5C: jal         0x8009DB04
    // 0x80800B60: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    func_8009DB04(rdram, ctx);
        goto after_3;
    // 0x80800B60: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    after_3:
    // 0x80800B64: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80800B68: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800B74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800B78: jal         0x8009FFD8
    // 0x80800B7C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_4;
    // 0x80800B7C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80800B80: lui         $a1, 0xC4A8
    ctx->r5 = S32(0XC4A8 << 16);
    // 0x80800B84: ori         $a1, $a1, 0xC000
    ctx->r5 = ctx->r5 | 0XC000;
    // 0x80800B88: jal         0x8009BCB4
    // 0x80800B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_gravity(rdram, ctx);
        goto after_5;
    // 0x80800B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800B90: jal         0x8009EF04
    // 0x80800B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_6;
    // 0x80800B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800B98: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800B9C: nop

    // 0x80800BA0: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800BA4: nop

    // 0x80800BA8: bc1t        L_80800BC4
    if (c1cs) {
        // 0x80800BAC: nop
    
            goto L_80800BC4;
    }
    // 0x80800BAC: nop

    // 0x80800BB0: jal         0x8009EEB8
    // 0x80800BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_7;
    // 0x80800BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800BB8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800BBC: jal         0x8009C914
    // 0x80800BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_8;
    // 0x80800BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_80800BC4:
    // 0x80800BC4: jal         0x8009BB5C
    // 0x80800BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB5C(rdram, ctx);
        goto after_9;
    // 0x80800BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800BCC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800BD0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80800BD4: jal         0x8009B9B0
    // 0x80800BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_10;
    // 0x80800BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800BDC: jal         0x8009C990
    // 0x80800BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_11;
    // 0x80800BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800BE4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800BE8: jal         0x8009B9C0
    // 0x80800BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_12;
    // 0x80800BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800BF0: jal         0x8009C990
    // 0x80800BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_13;
    // 0x80800BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800BF8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C00: jal         0x8009BA68
    // 0x80800C04: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_14;
    // 0x80800C04: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_14:
    // 0x80800C08: jal         0x8008AF24
    // 0x80800C0C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    anctrl_reset(rdram, ctx);
        goto after_15;
    // 0x80800C0C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_15:
    // 0x80800C10: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800C14: jal         0x8008AED4
    // 0x80800C18: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    anctrl_setIndex(rdram, ctx);
        goto after_16;
    // 0x80800C18: addiu       $a1, $zero, 0x144
    ctx->r5 = ADD32(0, 0X144);
    after_16:
    // 0x80800C1C: lui         $a2, 0x3EB3
    ctx->r6 = S32(0X3EB3 << 16);
    // 0x80800C20: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800C24: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800C28: jal         0x8008B1D4
    // 0x80800C2C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_17;
    // 0x80800C2C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_17:
    // 0x80800C30: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800C34: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800C38: jal         0x8008B1BC
    // 0x80800C3C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    anctrl_setDuration(rdram, ctx);
        goto after_18;
    // 0x80800C3C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_18:
    // 0x80800C40: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800C44: jal         0x8008B134
    // 0x80800C48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_19;
    // 0x80800C48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80800C4C: jal         0x8008B064
    // 0x80800C50: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    anctrl_start(rdram, ctx);
        goto after_20;
    // 0x80800C50: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_20:
    // 0x80800C54: lui         $a1, 0x4431
    ctx->r5 = S32(0X4431 << 16);
    // 0x80800C58: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80800C5C: jal         0x8009BA58
    // 0x80800C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_21;
    // 0x80800C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800C64: b           L_80800D3C
    // 0x80800C68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800D3C;
    // 0x80800C68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800C6C:
    // 0x80800C6C: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x80800C70: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C78: jal         0x8008CF1C
    // 0x80800C7C: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_22;
    // 0x80800C7C: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_22:
    // 0x80800C80: b           L_80800D3C
    // 0x80800C84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800D3C;
    // 0x80800C84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800C88:
    // 0x80800C88: jal         0x8008E35C
    // 0x80800C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_23;
    // 0x80800C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800C90: beql        $v0, $zero, L_80800CA4
    if (ctx->r2 == 0) {
        // 0x80800C94: lui         $a1, 0x3F7A
        ctx->r5 = S32(0X3F7A << 16);
            goto L_80800CA4;
    }
    goto skip_0;
    // 0x80800C94: lui         $a1, 0x3F7A
    ctx->r5 = S32(0X3F7A << 16);
    skip_0:
    // 0x80800C98: jal         0x80800A14
    // 0x80800C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A14_bsbansack(rdram, ctx);
        goto after_24;
    // 0x80800C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800CA0: lui         $a1, 0x3F7A
    ctx->r5 = S32(0X3F7A << 16);
L_80800CA4:
    // 0x80800CA4: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80800CA8: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800CAC: ori         $a1, $a1, 0xE148
    ctx->r5 = ctx->r5 | 0XE148;
    // 0x80800CB0: jal         0x8008CF1C
    // 0x80800CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_setEndAndDuration(rdram, ctx);
        goto after_25;
    // 0x80800CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800CB8: b           L_80800D3C
    // 0x80800CBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800D3C;
    // 0x80800CBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800CC0:
    // 0x80800CC0: jal         0x8008E35C
    // 0x80800CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_26;
    // 0x80800CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80800CC8: beql        $v0, $zero, L_80800CDC
    if (ctx->r2 == 0) {
        // 0x80800CCC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CDC;
    }
    goto skip_1;
    // 0x80800CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800CD0: jal         0x80800A14
    // 0x80800CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A14_bsbansack(rdram, ctx);
        goto after_27;
    // 0x80800CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80800CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800CDC:
    // 0x80800CDC: jal         0x8009D2D8
    // 0x80800CE0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8009D2D8(rdram, ctx);
        goto after_28;
    // 0x80800CE0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_28:
    // 0x80800CE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CE8: jal         0x800A2FCC
    // 0x80800CEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A2FCC(rdram, ctx);
        goto after_29;
    // 0x80800CEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x80800CF0: lui         $a1, 0x3F7A
    ctx->r5 = S32(0X3F7A << 16);
    // 0x80800CF4: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80800CF8: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800CFC: ori         $a1, $a1, 0xE148
    ctx->r5 = ctx->r5 | 0XE148;
    // 0x80800D00: jal         0x8008CF1C
    // 0x80800D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_setEndAndDuration(rdram, ctx);
        goto after_30;
    // 0x80800D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80800D08: b           L_80800D3C
    // 0x80800D0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800D3C;
    // 0x80800D0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D10:
    // 0x80800D10: jal         0x80800A78
    // 0x80800D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A78_bsbansack(rdram, ctx);
        goto after_31;
    // 0x80800D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80800D18: jal         0x8009BC6C
    // 0x80800D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_32;
    // 0x80800D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80800D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D24: jal         0x8009BF5C
    // 0x80800D28: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_33;
    // 0x80800D28: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_33:
    // 0x80800D2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D30: jal         0x8009C4CC
    // 0x80800D34: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_34;
    // 0x80800D34: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_34:
L_80800D38:
    // 0x80800D38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D3C:
    // 0x80800D3C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800D40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800D44: jr          $ra
    // 0x80800D48: nop

    return;
    // 0x80800D48: nop

;}
RECOMP_FUNC void func_8080082C_bskazstill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080082C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800830: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800834: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800838: jal         0x800839E8
    // 0x8080083C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x8080083C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800840: beq         $v0, $zero, L_80800854
    if (ctx->r2 == 0) {
        // 0x80800844: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80800854;
    }
    // 0x80800844: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800848: jal         0x800839B0
    // 0x8080084C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bsrest_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x8080084C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800850: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80800854:
    // 0x80800854: jal         0x8009E5C8
    // 0x80800858: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80800858: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8080085C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800860: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800864: jr          $ra
    // 0x80800868: nop

    return;
    // 0x80800868: nop

;}
RECOMP_FUNC void func_80800C0C_chhoneyb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C14: jal         0x80800B78
    // 0x80800C18: nop

    func_80800B78_chhoneyb(rdram, ctx);
        goto after_0;
    // 0x80800C18: nop

    after_0:
    // 0x80800C1C: jal         0x80800B98
    // 0x80800C20: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    func_80800B98_chhoneyb(rdram, ctx);
        goto after_1;
    // 0x80800C20: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    after_1:
    // 0x80800C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C2C: jr          $ra
    // 0x80800C30: nop

    return;
    // 0x80800C30: nop

;}
RECOMP_FUNC void func_80800374_chdippy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800374: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800378: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8080037C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800380: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800384: beq         $a1, $at, L_808003C4
    if (ctx->r5 == ctx->r1) {
        // 0x80800388: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_808003C4;
    }
    // 0x80800388: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8080038C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800390: beq         $a1, $at, L_808003AC
    if (ctx->r5 == ctx->r1) {
        // 0x80800394: addiu       $v0, $sp, 0x20
        ctx->r2 = ADD32(ctx->r29, 0X20);
            goto L_808003AC;
    }
    // 0x80800394: addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
    // 0x80800398: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080039C: beq         $a1, $at, L_8080041C
    if (ctx->r5 == ctx->r1) {
        // 0x808003A0: addiu       $a0, $zero, 0x36
        ctx->r4 = ADD32(0, 0X36);
            goto L_8080041C;
    }
    // 0x808003A0: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x808003A4: b           L_8080046C
    // 0x808003A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080046C;
    // 0x808003A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003AC:
    // 0x808003AC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808003B0: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808003B4: jal         0x8080047C
    // 0x808003B8: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_8080047C_chdippy(rdram, ctx);
        goto after_0;
    // 0x808003B8: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_0:
    // 0x808003BC: b           L_8080046C
    // 0x808003C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080046C;
    // 0x808003C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003C4:
    // 0x808003C4: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x808003C8: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
    // 0x808003CC: beq         $v0, $at, L_808003EC
    if (ctx->r2 == ctx->r1) {
        // 0x808003D0: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_808003EC;
    }
    // 0x808003D0: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x808003D4: bne         $v0, $at, L_80800414
    if (ctx->r2 != ctx->r1) {
        // 0x808003D8: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80800414;
    }
    // 0x808003D8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808003DC: jal         0x80800654
    // 0x808003E0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800654_chdippy(rdram, ctx);
        goto after_1;
    // 0x808003E0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_1:
    // 0x808003E4: b           L_8080046C
    // 0x808003E8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8080046C;
    // 0x808003E8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808003EC:
    // 0x808003EC: jal         0x80800D44
    // 0x808003F0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800D44_chdippy(rdram, ctx);
        goto after_2;
    // 0x808003F0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x808003F4: jal         0x80088840
    // 0x808003F8: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_3;
    // 0x808003F8: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    after_3:
    // 0x808003FC: beq         $v0, $zero, L_8080040C
    if (ctx->r2 == 0) {
        // 0x80800400: nop
    
            goto L_8080040C;
    }
    // 0x80800400: nop

    // 0x80800404: jal         0x80088830
    // 0x80800408: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_4;
    // 0x80800408: nop

    after_4:
L_8080040C:
    // 0x8080040C: b           L_8080046C
    // 0x80800410: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8080046C;
    // 0x80800410: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800414:
    // 0x80800414: b           L_8080046C
    // 0x80800418: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8080046C;
    // 0x80800418: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8080041C:
    // 0x8080041C: jal         0x80088840
    // 0x80800420: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_5;
    // 0x80800420: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_5:
    // 0x80800424: beq         $v0, $zero, L_80800468
    if (ctx->r2 == 0) {
        // 0x80800428: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_80800468;
    }
    // 0x80800428: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8080042C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800430: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800434: jal         0x8008A4B0
    // 0x80800438: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x80800438: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_6:
    // 0x8080043C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800440: jal         0x80800654
    // 0x80800444: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800654_chdippy(rdram, ctx);
        goto after_7;
    // 0x80800444: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x80800448: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080044C: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    // 0x80800450: jal         0x80800CBC
    // 0x80800454: addiu       $a2, $zero, 0x2030
    ctx->r6 = ADD32(0, 0X2030);
    func_80800CBC_chdippy(rdram, ctx);
        goto after_8;
    // 0x80800454: addiu       $a2, $zero, 0x2030
    ctx->r6 = ADD32(0, 0X2030);
    after_8:
    // 0x80800458: b           L_8080046C
    // 0x8080045C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080046C;
    // 0x8080045C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800460: b           L_8080046C
    // 0x80800464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080046C;
    // 0x80800464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800468:
    // 0x80800468: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080046C:
    // 0x8080046C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800470: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800474: jr          $ra
    // 0x80800478: nop

    return;
    // 0x80800478: nop

;}
RECOMP_FUNC void func_80096394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096394: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80096398: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8009639C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800963A0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800963A4: lw          $a1, 0x94($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X94);
    // 0x800963A8: jal         0x800EE7F8
    // 0x800963AC: addiu       $a1, $a1, 0x90
    ctx->r5 = ADD32(ctx->r5, 0X90);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800963AC: addiu       $a1, $a1, 0x90
    ctx->r5 = ADD32(ctx->r5, 0X90);
    after_0:
    // 0x800963B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800963B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800963B8: jr          $ra
    // 0x800963BC: nop

    return;
    // 0x800963BC: nop

;}
RECOMP_FUNC void func_80801500_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801500: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801504: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80801508: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8080150C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801510: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801514: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80801518: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8080151C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801520: jal         0x80100094
    // 0x80801524: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801524: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801528: lbu         $t6, 0x3A($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3A);
    // 0x8080152C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80801530: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801534: blez        $t6, L_8080155C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80801538: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080155C;
    }
    // 0x80801538: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8080153C:
    // 0x8080153C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801540: jal         0x808015D4
    // 0x80801544: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_808015D4_chcollballcontrol(rdram, ctx);
        goto after_1;
    // 0x80801544: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_1:
    // 0x80801548: lbu         $t7, 0x3A($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X3A);
    // 0x8080154C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801550: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80801554: bnel        $at, $zero, L_8080153C
    if (ctx->r1 != 0) {
        // 0x80801558: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080153C;
    }
    goto skip_0;
    // 0x80801558: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_8080155C:
    // 0x8080155C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801560: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801564: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801568: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8080156C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80801570: jr          $ra
    // 0x80801574: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80801574: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bainput_setDiveCooldown(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098188: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8009818C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80098190: lw          $t6, 0xA4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA4);
    // 0x80098194: jr          $ra
    // 0x80098198: swc1        $f12, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x80098198: swc1        $f12, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void _fxstep_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800889F0: syscall     718
    recomp_syscall_handler(rdram, ctx, 0x800889F0);
    return;
    // 0x800889F4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bareact_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(580, 0XB0) << 16);
    // 0x8080000C: addiu       $a3, $a3, 0xB0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(580, 0XB0));
    // 0x80800010: lbu         $t6, 0x0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X0);
    // 0x80800014: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800018: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080001C: beq         $t6, $zero, L_8080005C
    if (ctx->r14 == 0) {
        // 0x80800020: lui         $t7, 0x8080
        ctx->r15 = S32(RELOC_HI16(580, 0XB0) << 16);
            goto L_8080005C;
    }
    // 0x80800020: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(580, 0XB0) << 16);
    // 0x80800024: addiu       $v1, $t7, 0xB0
    ctx->r3 = ADD32(ctx->r15, (int16_t)RELOC_LO16(580, 0XB0));
    // 0x80800028: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
L_8080002C:
    // 0x8080002C: bnel        $a1, $a0, L_8080004C
    if (ctx->r5 != ctx->r4) {
        // 0x80800030: lbu         $a0, 0x10($v1)
        ctx->r4 = MEM_BU(ctx->r3, 0X10);
            goto L_8080004C;
    }
    goto skip_0;
    // 0x80800030: lbu         $a0, 0x10($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X10);
    skip_0:
    // 0x80800034: lw          $t0, 0xEC($a2)
    ctx->r8 = MEM_W(ctx->r6, 0XEC);
    // 0x80800038: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x8080003C: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x80800040: jr          $ra
    // 0x80800044: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    return;
    // 0x80800044: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80800048: lbu         $a0, 0x10($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X10);
L_8080004C:
    // 0x8080004C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800050: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80800054: bne         $a0, $zero, L_8080002C
    if (ctx->r4 != 0) {
        // 0x80800058: nop
    
            goto L_8080002C;
    }
    // 0x80800058: nop

L_8080005C:
    // 0x8080005C: jr          $ra
    // 0x80800060: nop

    return;
    // 0x80800060: nop

;}
RECOMP_FUNC void func_80800FE8_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FE8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80800FEC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800FF0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800FF4: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800FF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800FFC: lwc1        $f0, 0x58($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80801000: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801004: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2284, 0X2940) << 16);
    // 0x80801008: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8080100C: addiu       $a3, $a3, 0x2940
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2284, 0X2940));
    // 0x80801010: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801014: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801018: bc1f        L_80801024
    if (!c1cs) {
        // 0x8080101C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80801024;
    }
    // 0x8080101C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801020: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80801024:
    // 0x80801024: beql        $a2, $zero, L_8080104C
    if (ctx->r6 == 0) {
        // 0x80801028: lw          $t6, 0x70($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X70);
            goto L_8080104C;
    }
    goto skip_0;
    // 0x80801028: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
    skip_0:
    // 0x8080102C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801030: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801034: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80801038: nop

    // 0x8080103C: bc1fl       L_8080104C
    if (!c1cs) {
        // 0x80801040: lw          $t6, 0x70($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X70);
            goto L_8080104C;
    }
    goto skip_1;
    // 0x80801040: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
    skip_1:
    // 0x80801044: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801048: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
L_8080104C:
    // 0x8080104C: lbu         $a0, 0x24($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X24);
    // 0x80801050: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80801054: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80801058: jal         0x80089D68
    // 0x8080105C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x8080105C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x80801060: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80801064: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80801068: sb          $v0, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r2;
    // 0x8080106C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80801070: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80801074: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801078: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2284, 0X2940) << 16);
    // 0x8080107C: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80801080: bc1f        L_8080108C
    if (!c1cs) {
        // 0x80801084: nop
    
            goto L_8080108C;
    }
    // 0x80801084: nop

    // 0x80801088: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8080108C:
    // 0x8080108C: beql        $a2, $zero, L_808010B4
    if (ctx->r6 == 0) {
        // 0x80801090: lw          $t8, 0x70($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X70);
            goto L_808010B4;
    }
    goto skip_2;
    // 0x80801090: lw          $t8, 0x70($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X70);
    skip_2:
    // 0x80801094: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801098: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080109C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808010A0: nop

    // 0x808010A4: bc1fl       L_808010B4
    if (!c1cs) {
        // 0x808010A8: lw          $t8, 0x70($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X70);
            goto L_808010B4;
    }
    goto skip_3;
    // 0x808010A8: lw          $t8, 0x70($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X70);
    skip_3:
    // 0x808010AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808010B0: lw          $t8, 0x70($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X70);
L_808010B4:
    // 0x808010B4: lbu         $a0, 0x54($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X54);
    // 0x808010B8: addiu       $a3, $a3, 0x2940
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2284, 0X2940));
    // 0x808010BC: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x808010C0: jal         0x80089D68
    // 0x808010C4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x808010C4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
    // 0x808010C8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808010CC: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808010D0: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808010D4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808010D8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x808010DC: sb          $v0, 0x54($s0)
    MEM_B(0X54, ctx->r16) = ctx->r2;
    // 0x808010E0: bc1fl       L_80801100
    if (!c1cs) {
        // 0x808010E4: c.le.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
            goto L_80801100;
    }
    goto skip_4;
    // 0x808010E4: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    skip_4:
    // 0x808010E8: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808010EC: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x808010F0: nop

    // 0x808010F4: bc1t        L_80801120
    if (c1cs) {
        // 0x808010F8: nop
    
            goto L_80801120;
    }
    // 0x808010F8: nop

    // 0x808010FC: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
L_80801100:
    // 0x80801100: nop

    // 0x80801104: bc1fl       L_80801294
    if (!c1cs) {
        // 0x80801108: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80801294;
    }
    goto skip_5;
    // 0x80801108: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_5:
    // 0x8080110C: lwc1        $f16, 0x34($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80801110: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x80801114: nop

    // 0x80801118: bc1fl       L_80801294
    if (!c1cs) {
        // 0x8080111C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80801294;
    }
    goto skip_6;
    // 0x8080111C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_6:
L_80801120:
    // 0x80801120: jal         0x800B53A4
    // 0x80801124: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800B53A4(rdram, ctx);
        goto after_2;
    // 0x80801124: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_2:
    // 0x80801128: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x8080112C: jal         0x80106790
    // 0x80801130: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_3;
    // 0x80801130: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_3:
    // 0x80801134: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80801138: jal         0x80103EF4
    // 0x8080113C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80103EF4(rdram, ctx);
        goto after_4;
    // 0x8080113C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80801140: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x80801144: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80801148: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8080114C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80801150: jal         0x800EE7F8
    // 0x80801154: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80801154: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_5:
    // 0x80801158: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8080115C: jal         0x800EE7F8
    // 0x80801160: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80801160: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_6:
    // 0x80801164: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80801168: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8080116C: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80801170: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x80801174: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80801178: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x8080117C: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80801180: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x80801184: jal         0x800EE7F8
    // 0x80801188: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80801188: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    after_7:
    // 0x8080118C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80801190: jal         0x800EE7F8
    // 0x80801194: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x80801194: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_8:
    // 0x80801198: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x8080119C: jal         0x800138D0
    // 0x808011A0: lwc1        $f12, 0x44($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X44);
    func_800138D0(rdram, ctx);
        goto after_9;
    // 0x808011A0: lwc1        $f12, 0x44($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X44);
    after_9:
    // 0x808011A4: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808011A8: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x808011AC: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x808011B0: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x808011B4: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x808011B8: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    // 0x808011BC: jal         0x800138D0
    // 0x808011C0: lwc1        $f12, 0x44($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X44);
    func_800138D0(rdram, ctx);
        goto after_10;
    // 0x808011C0: lwc1        $f12, 0x44($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X44);
    after_10:
    // 0x808011C4: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808011C8: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x808011CC: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x808011D0: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x808011D4: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x808011D8: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x808011DC: jal         0x80013970
    // 0x808011E0: lwc1        $f12, 0x44($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X44);
    func_80013970(rdram, ctx);
        goto after_11;
    // 0x808011E0: lwc1        $f12, 0x44($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X44);
    after_11:
    // 0x808011E4: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808011E8: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x808011EC: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x808011F0: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x808011F4: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x808011F8: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x808011FC: jal         0x80013970
    // 0x80801200: lwc1        $f12, 0x44($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X44);
    func_80013970(rdram, ctx);
        goto after_12;
    // 0x80801200: lwc1        $f12, 0x44($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X44);
    after_12:
    // 0x80801204: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80801208: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8080120C: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80801210: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80801214: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2284, 0X2954) << 16);
    // 0x80801218: addiu       $t5, $t5, 0x2954
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(2284, 0X2954));
    // 0x8080121C: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80801220: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80801224: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801228: add.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8080122C: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    // 0x80801230: lw          $a3, 0x38($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X38);
    // 0x80801234: jal         0x800BABB8
    // 0x80801238: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800BABB8(rdram, ctx);
        goto after_13;
    // 0x80801238: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_13:
    // 0x8080123C: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80801240: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80801244: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x80801248: jal         0x800BA1D0
    // 0x8080124C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BA1D0(rdram, ctx);
        goto after_14;
    // 0x8080124C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_14:
    // 0x80801250: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80801254: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x80801258: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x8080125C: jal         0x800BA1D0
    // 0x80801260: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800BA1D0(rdram, ctx);
        goto after_15;
    // 0x80801260: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_15:
    // 0x80801264: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80801268: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x8080126C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80801270: jal         0x800BA1D0
    // 0x80801274: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BA1D0(rdram, ctx);
        goto after_16;
    // 0x80801274: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_16:
    // 0x80801278: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2284, 0X2934) << 16);
    // 0x8080127C: addiu       $a2, $a2, 0x2934
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2284, 0X2934));
    // 0x80801280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801284: jal         0x80089D18
    // 0x80801288: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_17;
    // 0x80801288: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_17:
    // 0x8080128C: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80801290: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80801294:
    // 0x80801294: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80801298: nop

    // 0x8080129C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x808012A0: nop

    // 0x808012A4: bc1fl       L_808012D4
    if (!c1cs) {
        // 0x808012A8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808012D4;
    }
    goto skip_7;
    // 0x808012A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x808012AC: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808012B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012B4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808012B8: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x808012BC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2284, 0X294C) << 16);
    // 0x808012C0: bc1fl       L_808012D4
    if (!c1cs) {
        // 0x808012C4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808012D4;
    }
    goto skip_8;
    // 0x808012C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_8:
    // 0x808012C8: jal         0x80089D18
    // 0x808012CC: addiu       $a2, $a2, 0x294C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2284, 0X294C));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_18;
    // 0x808012CC: addiu       $a2, $a2, 0x294C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2284, 0X294C));
    after_18:
    // 0x808012D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808012D4:
    // 0x808012D4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808012D8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x808012DC: jr          $ra
    // 0x808012E0: nop

    return;
    // 0x808012E0: nop

;}
RECOMP_FUNC void _bskazstilt_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800836F8: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x800836F8);
    return;
    // 0x800836FC: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void func_800A0D84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0D84: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A0D88: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x800A0D8C: jr          $ra
    // 0x800A0D90: swc1        $f12, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x800A0D90: swc1        $f12, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_8080019C_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080019C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001AC: jal         0x80100094
    // 0x808001B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808001B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808001B4: lbu         $v1, 0xF($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XF);
    // 0x808001B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C0: beq         $v1, $zero, L_808001E4
    if (ctx->r3 == 0) {
        // 0x808001C4: nop
    
            goto L_808001E4;
    }
    // 0x808001C4: nop

    // 0x808001C8: beq         $v1, $at, L_808001FC
    if (ctx->r3 == ctx->r1) {
        // 0x808001CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001FC;
    }
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808001D4: beq         $v1, $at, L_8080021C
    if (ctx->r3 == ctx->r1) {
        // 0x808001D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080021C;
    }
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001DC: b           L_80800230
    // 0x808001E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800230;
    // 0x808001E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001E4:
    // 0x808001E4: jal         0x80800158
    // 0x808001E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800158_chclockworkmouse(rdram, ctx);
        goto after_1;
    // 0x808001E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808001EC: jal         0x808000B4
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B4_chclockworkmouse(rdram, ctx);
        goto after_2;
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808001F4: b           L_80800230
    // 0x808001F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800230;
    // 0x808001F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001FC:
    // 0x808001FC: jal         0x80800158
    // 0x80800200: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800158_chclockworkmouse(rdram, ctx);
        goto after_3;
    // 0x80800200: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800204: jal         0x800880E0
    // 0x80800208: nop

    _gcintrotext_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80800208: nop

    after_4:
    // 0x8080020C: jal         0x808000B4
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B4_chclockworkmouse(rdram, ctx);
        goto after_5;
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800214: b           L_80800230
    // 0x80800218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800230;
    // 0x80800218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080021C:
    // 0x8080021C: jal         0x80800158
    // 0x80800220: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800158_chclockworkmouse(rdram, ctx);
        goto after_6;
    // 0x80800220: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800224: jal         0x80800024
    // 0x80800228: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80800024_chclockworkmouse(rdram, ctx);
        goto after_7;
    // 0x80800228: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x8080022C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800230:
    // 0x80800230: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800234: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800238: jr          $ra
    // 0x8080023C: nop

    return;
    // 0x8080023C: nop

;}
RECOMP_FUNC void bafpctrl_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _sumumbofx_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800898E0: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x800898E0);
    return;
    // 0x800898E4: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void chlavaslab_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1952, 0XA0) << 16);
    // 0x80800094: jr          $ra
    // 0x80800098: addiu       $v0, $v0, 0xA0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1952, 0XA0));
    return;
    // 0x80800098: addiu       $v0, $v0, 0xA0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1952, 0XA0));
    // 0x8080009C: nop

;}
RECOMP_FUNC void chlavaarchgrill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1956, 0X6A4) << 16);
    // 0x808005C8: jr          $ra
    // 0x808005CC: addiu       $v0, $v0, 0x6A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1956, 0X6A4));
    return;
    // 0x808005CC: addiu       $v0, $v0, 0x6A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1956, 0X6A4));
;}
RECOMP_FUNC void bsmum_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001F0: jal         0x8009E77C
    // 0x808001F4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8009E77C(rdram, ctx);
        goto after_0;
    // 0x808001F4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x808001F8: bnel        $v0, $zero, L_808002A8
    if (ctx->r2 != 0) {
        // 0x808001FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002A8;
    }
    goto skip_0;
    // 0x808001FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800200: jal         0x8009E4AC
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E4AC(rdram, ctx);
        goto after_1;
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080020C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800210: jal         0x8009E55C
    // 0x80800214: lui         $a2, 0x4218
    ctx->r6 = S32(0X4218 << 16);
    func_8009E55C(rdram, ctx);
        goto after_2;
    // 0x80800214: lui         $a2, 0x4218
    ctx->r6 = S32(0X4218 << 16);
    after_2:
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800220: jal         0x8009E53C
    // 0x80800224: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    func_8009E53C(rdram, ctx);
        goto after_3;
    // 0x80800224: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    after_3:
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080022C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800230: jal         0x8009E55C
    // 0x80800234: lui         $a2, 0x4200
    ctx->r6 = S32(0X4200 << 16);
    func_8009E55C(rdram, ctx);
        goto after_4;
    // 0x80800234: lui         $a2, 0x4200
    ctx->r6 = S32(0X4200 << 16);
    after_4:
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800240: jal         0x8009E53C
    // 0x80800244: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    func_8009E53C(rdram, ctx);
        goto after_5;
    // 0x80800244: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_5:
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080024C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800250: jal         0x8009E5A4
    // 0x80800254: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_8009E5A4(rdram, ctx);
        goto after_6;
    // 0x80800254: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_6:
    // 0x80800258: jal         0x8009F2A4
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_func_8009F2A4(rdram, ctx);
        goto after_7;
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800264: jal         0x800A0DAC
    // 0x80800268: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0DAC(rdram, ctx);
        goto after_8;
    // 0x80800268: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800270: jal         0x80093230
    // 0x80800274: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80093230(rdram, ctx);
        goto after_9;
    // 0x80800274: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_9:
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080027C: jal         0x80084F28
    // 0x80800280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bamum_entrypoint_4(rdram, ctx);
        goto after_10;
    // 0x80800280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800288: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080028C: jal         0x800947EC
    // 0x80800290: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_11;
    // 0x80800290: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x80800294: lui         $a1, 0x4019
    ctx->r5 = S32(0X4019 << 16);
    // 0x80800298: ori         $a1, $a1, 0x9980
    ctx->r5 = ctx->r5 | 0X9980;
    // 0x8080029C: jal         0x80092864
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092864(rdram, ctx);
        goto after_12;
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808002A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002A8:
    // 0x808002A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002B0: jr          $ra
    // 0x808002B4: nop

    return;
    // 0x808002B4: nop

;}
RECOMP_FUNC void _ncbajig_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800892F8: syscall     772
    recomp_syscall_handler(rdram, ctx, 0x800892F8);
    return;
    // 0x800892FC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808000E4_chflysaucercrate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000E8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808000EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F0: beq         $a1, $at, L_80800120
    if (ctx->r5 == ctx->r1) {
        // 0x808000F4: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80800120;
    }
    // 0x808000F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000F8: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808000FC: beq         $a1, $at, L_80800220
    if (ctx->r5 == ctx->r1) {
        // 0x80800100: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_80800220;
    }
    // 0x80800100: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80800104: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80800108: beq         $a1, $at, L_80800230
    if (ctx->r5 == ctx->r1) {
        // 0x8080010C: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_80800230;
    }
    // 0x8080010C: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800110: beq         $a1, $at, L_80800258
    if (ctx->r5 == ctx->r1) {
        // 0x80800114: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1696, 0XDC0) << 16);
            goto L_80800258;
    }
    // 0x80800114: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1696, 0XDC0) << 16);
    // 0x80800118: b           L_8080027C
    // 0x8080011C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080027C;
    // 0x8080011C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800120:
    // 0x80800120: sltiu       $at, $a2, 0xD
    ctx->r1 = ctx->r6 < 0XD ? 1 : 0;
    // 0x80800124: beq         $at, $zero, L_80800218
    if (ctx->r1 == 0) {
        // 0x80800128: sll         $t6, $a2, 2
        ctx->r14 = S32(ctx->r6 << 2);
            goto L_80800218;
    }
    // 0x80800128: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8080012C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XC38) << 16);
    // 0x80800130: addu        $at, $at, $t6
    gpr jr_addend_80800138 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800134: lw          $t6, 0xC38($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1696, 0XC38));
    // 0x80800138: jr          $t6
    // 0x8080013C: nop

    switch (jr_addend_80800138 >> 2) {
        case 0: goto L_80800218; break;
        case 1: goto L_80800218; break;
        case 2: goto L_8080020C; break;
        case 3: goto L_80800218; break;
        case 4: goto L_808001FC; break;
        case 5: goto L_80800218; break;
        case 6: goto L_80800140; break;
        case 7: goto L_80800218; break;
        case 8: goto L_80800218; break;
        case 9: goto L_80800218; break;
        case 10: goto L_80800218; break;
        case 11: goto L_80800218; break;
        case 12: goto L_808001D0; break;
        default: switch_error(__func__, 0x80800138, 0x80800C38);
    }
    // 0x8080013C: nop

L_80800140:
    // 0x80800140: jal         0x800DA298
    // 0x80800144: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800144: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_0:
    // 0x80800148: beq         $v0, $zero, L_808001C8
    if (ctx->r2 == 0) {
        // 0x8080014C: nop
    
            goto L_808001C8;
    }
    // 0x8080014C: nop

    // 0x80800150: jal         0x80085710
    // 0x80800154: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x80800154: nop

    after_1:
    // 0x80800158: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080015C: jal         0x8080000C
    // 0x80800160: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080000C_chflysaucercrate(rdram, ctx);
        goto after_2;
    // 0x80800160: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800164: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800168: jal         0x8008A4B0
    // 0x8080016C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x8080016C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800170: jal         0x800DA298
    // 0x80800174: addiu       $a0, $zero, 0xB3
    ctx->r4 = ADD32(0, 0XB3);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800174: addiu       $a0, $zero, 0xB3
    ctx->r4 = ADD32(0, 0XB3);
    after_4:
    // 0x80800178: beq         $v0, $zero, L_808001AC
    if (ctx->r2 == 0) {
        // 0x8080017C: lw          $t8, 0x18($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18);
            goto L_808001AC;
    }
    // 0x8080017C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800180: addiu       $a0, $zero, 0xCA
    ctx->r4 = ADD32(0, 0XCA);
    // 0x80800184: jal         0x800887D8
    // 0x80800188: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x80800188: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_5:
    // 0x8080018C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800190: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800194: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800198: addiu       $a3, $zero, 0x2810
    ctx->r7 = ADD32(0, 0X2810);
    // 0x8080019C: jal         0x80085708
    // 0x808001A0: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_6;
    // 0x808001A0: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_6:
    // 0x808001A4: b           L_8080027C
    // 0x808001A8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8080027C;
    // 0x808001A8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808001AC:
    // 0x808001AC: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x808001B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808001B8: jal         0x80085708
    // 0x808001BC: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    _capod_entrypoint_13(rdram, ctx);
        goto after_7;
    // 0x808001BC: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    after_7:
    // 0x808001C0: b           L_8080027C
    // 0x808001C4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8080027C;
    // 0x808001C4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808001C8:
    // 0x808001C8: b           L_8080027C
    // 0x808001CC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8080027C;
    // 0x808001CC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808001D0:
    // 0x808001D0: jal         0x80088840
    // 0x808001D4: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_8;
    // 0x808001D4: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_8:
    // 0x808001D8: beql        $v0, $zero, L_808001EC
    if (ctx->r2 == 0) {
        // 0x808001DC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808001EC;
    }
    goto skip_0;
    // 0x808001DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x808001E0: jal         0x80088830
    // 0x808001E4: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_9;
    // 0x808001E4: nop

    after_9:
    // 0x808001E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_808001EC:
    // 0x808001EC: jal         0x8080000C
    // 0x808001F0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_8080000C_chflysaucercrate(rdram, ctx);
        goto after_10;
    // 0x808001F0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_10:
    // 0x808001F4: b           L_8080027C
    // 0x808001F8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8080027C;
    // 0x808001F8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808001FC:
    // 0x808001FC: jal         0x80088830
    // 0x80800200: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_11;
    // 0x80800200: nop

    after_11:
    // 0x80800204: b           L_8080027C
    // 0x80800208: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8080027C;
    // 0x80800208: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8080020C:
    // 0x8080020C: addiu       $a0, $zero, 0xD6
    ctx->r4 = ADD32(0, 0XD6);
    // 0x80800210: jal         0x800887D8
    // 0x80800214: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_12;
    // 0x80800214: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    after_12:
L_80800218:
    // 0x80800218: b           L_8080027C
    // 0x8080021C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8080027C;
    // 0x8080021C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800220:
    // 0x80800220: lbu         $t0, 0x74($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X74);
    // 0x80800224: andi        $t1, $t0, 0xFFBF
    ctx->r9 = ctx->r8 & 0XFFBF;
    // 0x80800228: b           L_80800278
    // 0x8080022C: sb          $t1, 0x74($t9)
    MEM_B(0X74, ctx->r25) = ctx->r9;
        goto L_80800278;
    // 0x8080022C: sb          $t1, 0x74($t9)
    MEM_B(0X74, ctx->r25) = ctx->r9;
L_80800230:
    // 0x80800230: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800234: bnel        $a2, $at, L_80800248
    if (ctx->r6 != ctx->r1) {
        // 0x80800238: addiu       $a0, $zero, 0x2A2
        ctx->r4 = ADD32(0, 0X2A2);
            goto L_80800248;
    }
    goto skip_1;
    // 0x80800238: addiu       $a0, $zero, 0x2A2
    ctx->r4 = ADD32(0, 0X2A2);
    skip_1:
    // 0x8080023C: jal         0x800FFAB0
    // 0x80800240: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_13;
    // 0x80800240: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_13:
    // 0x80800244: addiu       $a0, $zero, 0x2A2
    ctx->r4 = ADD32(0, 0X2A2);
L_80800248:
    // 0x80800248: jal         0x801084B0
    // 0x8080024C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_801084B0(rdram, ctx);
        goto after_14;
    // 0x8080024C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_14:
    // 0x80800250: b           L_8080027C
    // 0x80800254: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080027C;
    // 0x80800254: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800258:
    // 0x80800258: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8080025C: addiu       $a0, $a0, 0xDC0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1696, 0XDC0));
    // 0x80800260: jal         0x80088090
    // 0x80800264: lw          $a1, 0x38($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_15;
    // 0x80800264: lw          $a1, 0x38($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X38);
    after_15:
    // 0x80800268: b           L_8080027C
    // 0x8080026C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080027C;
    // 0x8080026C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800270: b           L_8080027C
    // 0x80800274: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080027C;
    // 0x80800274: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800278:
    // 0x80800278: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080027C:
    // 0x8080027C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800280: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800284: jr          $ra
    // 0x80800288: nop

    return;
    // 0x80800288: nop

;}
RECOMP_FUNC void func_800F4200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4200: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F4204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4208: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800F420C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800F4210: jal         0x8009C128
    // 0x800F4214: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x800F4214: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800F4218: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800F421C: jal         0x8009C1CC
    // 0x800F4220: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_8009C1CC(rdram, ctx);
        goto after_1;
    // 0x800F4220: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x800F4224: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800F4228: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800F422C: jal         0x800EE780
    // 0x800F4230: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_800EE780(rdram, ctx);
        goto after_2;
    // 0x800F4230: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x800F4234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4238: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800F423C: jr          $ra
    // 0x800F4240: nop

    return;
    // 0x800F4240: nop

;}
RECOMP_FUNC void _subaddieDll_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A4D8: syscall     843
    recomp_syscall_handler(rdram, ctx, 0x8008A4D8);
    return;
    // 0x8008A4DC: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void chprisonbits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1932, 0XF78) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xF78
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1932, 0XF78));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xF78
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1932, 0XF78));
;}
RECOMP_FUNC void func_800C3FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3FF0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C3FF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C3FF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C3FFC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800C4000: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C4004: jal         0x800C2840
    // 0x800C4008: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C2840(rdram, ctx);
        goto after_0;
    // 0x800C4008: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800C400C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4010: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C4014: jr          $ra
    // 0x800C4018: nop

    return;
    // 0x800C4018: nop

;}
RECOMP_FUNC void func_800BE52C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE52C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BE530: addiu       $v0, $v0, -0x7BF0
    ctx->r2 = ADD32(ctx->r2, -0X7BF0);
    // 0x800BE534: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800BE538: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800BE53C: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x800BE540: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800BE544: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800BE548: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800BE54C: jr          $ra
    // 0x800BE550: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    return;
    // 0x800BE550: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
;}
RECOMP_FUNC void func_80800110_chalienbeam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800110: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800114: addiu       $at, $zero, 0x4F
    ctx->r1 = ADD32(0, 0X4F);
    // 0x80800118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080011C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800120: bne         $a1, $at, L_80800144
    if (ctx->r5 != ctx->r1) {
        // 0x80800124: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800144;
    }
    // 0x80800124: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800128: jal         0x80089CA8
    // 0x8080012C: nop

    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080012C: nop

    after_0:
    // 0x80800130: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800134: jal         0x80102424
    // 0x80800138: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800138: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x8080013C: b           L_8080014C
    // 0x80800140: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080014C;
    // 0x80800140: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800144:
    // 0x80800144: b           L_8080014C
    // 0x80800148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080014C;
    // 0x80800148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080014C:
    // 0x8080014C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800154: jr          $ra
    // 0x80800158: nop

    return;
    // 0x80800158: nop

;}
RECOMP_FUNC void gcstatusDll_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800118: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8080011C: lbu         $t6, 0x762C($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X762C);
    // 0x80800120: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80800124: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x80800128: beq         $t6, $at, L_80800138
    if (ctx->r14 == ctx->r1) {
        // 0x8080012C: lbu         $v1, -0x4BFC($v1)
        ctx->r3 = MEM_BU(ctx->r3, -0X4BFC);
            goto L_80800138;
    }
    // 0x8080012C: lbu         $v1, -0x4BFC($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X4BFC);
    // 0x80800130: jr          $ra
    // 0x80800134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800138:
    // 0x80800138: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8080013C: jr          $ra
    // 0x80800140: nop

    return;
    // 0x80800140: nop

;}
RECOMP_FUNC void func_800A5320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5320: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800A5324: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800A5328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A532C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800A5330: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800A5334: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x800A5338: jal         0x800EFA4C
    // 0x800A533C: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x800A533C: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    after_0:
    // 0x800A5340: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800A5344: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800A5348: jal         0x800EF8BC
    // 0x800A534C: lui         $a2, 0x4288
    ctx->r6 = S32(0X4288 << 16);
    func_800EF8BC(rdram, ctx);
        goto after_1;
    // 0x800A534C: lui         $a2, 0x4288
    ctx->r6 = S32(0X4288 << 16);
    after_1:
    // 0x800A5350: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A5354: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800A5358: lwc1        $f4, 0x55C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X55C0);
    // 0x800A535C: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800A5360: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800A5364: mul.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x800A5368: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x800A536C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800A5370: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A5374: jal         0x800EFA4C
    // 0x800A5378: nop

    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x800A5378: nop

    after_2:
    // 0x800A537C: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800A5380: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800A5384: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A5388: addiu       $v1, $v1, 0x70A0
    ctx->r3 = ADD32(ctx->r3, 0X70A0);
    // 0x800A538C: add.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x800A5390: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800A5394: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800A5398: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800A539C: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x800A53A0: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800A53A4: add.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x800A53A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A53AC: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800A53B0: sub.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x800A53B4: addiu       $a0, $a0, 0x70B0
    ctx->r4 = ADD32(ctx->r4, 0X70B0);
    // 0x800A53B8: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x800A53BC: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x800A53C0: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800A53C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A53C8: neg.s       $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = -ctx->f18.fl;
    // 0x800A53CC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x800A53D0: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x800A53D4: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800A53D8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A53DC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A53E0: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800A53E4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A53E8: addiu       $a2, $a2, 0x70D0
    ctx->r6 = ADD32(ctx->r6, 0X70D0);
    // 0x800A53EC: sub.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x800A53F0: addiu       $a1, $a1, 0x70C0
    ctx->r5 = ADD32(ctx->r5, 0X70C0);
    // 0x800A53F4: addiu       $v0, $v0, 0x70E0
    ctx->r2 = ADD32(ctx->r2, 0X70E0);
    // 0x800A53F8: add.s       $f10, $f14, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x800A53FC: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x800A5400: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x800A5404: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x800A5408: swc1        $f10, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f10.u32l;
    // 0x800A540C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800A5410: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x800A5414: swc1        $f14, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f14.u32l;
    // 0x800A5418: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    // 0x800A541C: swc1        $f16, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f16.u32l;
    // 0x800A5420: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    // 0x800A5424: swc1        $f16, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f16.u32l;
    // 0x800A5428: jr          $ra
    // 0x800A542C: swc1        $f16, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f16.u32l;
    return;
    // 0x800A542C: swc1        $f16, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f16.u32l;
;}
