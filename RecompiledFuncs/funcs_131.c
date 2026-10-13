#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800A88_chflysaucercrate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A8C: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x80800A90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A9C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800AA0: jal         0x800EA05C
    // 0x80800AA4: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800AA4: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x80800AA8: addiu       $at, $zero, 0xCA
    ctx->r1 = ADD32(0, 0XCA);
    // 0x80800AAC: beq         $v0, $at, L_80800AC4
    if (ctx->r2 == ctx->r1) {
        // 0x80800AB0: addiu       $at, $zero, 0xD6
        ctx->r1 = ADD32(0, 0XD6);
            goto L_80800AC4;
    }
    // 0x80800AB0: addiu       $at, $zero, 0xD6
    ctx->r1 = ADD32(0, 0XD6);
    // 0x80800AB4: beq         $v0, $at, L_80800B3C
    if (ctx->r2 == ctx->r1) {
        // 0x80800AB8: nop
    
            goto L_80800B3C;
    }
    // 0x80800AB8: nop

    // 0x80800ABC: b           L_80800C0C
    // 0x80800AC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800C0C;
    // 0x80800AC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800AC4:
    // 0x80800AC4: jal         0x800DA298
    // 0x80800AC8: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800AC8: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    after_1:
    // 0x80800ACC: beq         $v0, $zero, L_80800AE4
    if (ctx->r2 == 0) {
        // 0x80800AD0: nop
    
            goto L_80800AE4;
    }
    // 0x80800AD0: nop

    // 0x80800AD4: jal         0x800FFAB0
    // 0x80800AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800ADC: b           L_80800C0C
    // 0x80800AE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800C0C;
    // 0x80800AE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800AE4:
    // 0x80800AE4: jal         0x800DA298
    // 0x80800AE8: addiu       $a0, $zero, 0x91
    ctx->r4 = ADD32(0, 0X91);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800AE8: addiu       $a0, $zero, 0x91
    ctx->r4 = ADD32(0, 0X91);
    after_3:
    // 0x80800AEC: beq         $v0, $zero, L_80800C08
    if (ctx->r2 == 0) {
        // 0x80800AF0: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1696, 0XCD8) << 16);
            goto L_80800C08;
    }
    // 0x80800AF0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XCD8) << 16);
    // 0x80800AF4: lwc1        $f6, 0xCD8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XCD8));
    // 0x80800AF8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XCDC) << 16);
    // 0x80800AFC: addiu       $a0, $zero, 0xB3
    ctx->r4 = ADD32(0, 0XB3);
    // 0x80800B00: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x80800B04: lwc1        $f8, 0xCDC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XCDC));
    // 0x80800B08: jal         0x800DA298
    // 0x80800B0C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800B0C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    after_4:
    // 0x80800B10: beq         $v0, $zero, L_80800B2C
    if (ctx->r2 == 0) {
        // 0x80800B14: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B2C;
    }
    // 0x80800B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B1C: jal         0x8080000C
    // 0x80800B20: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8080000C_chflysaucercrate(rdram, ctx);
        goto after_5;
    // 0x80800B20: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
    // 0x80800B24: b           L_80800C0C
    // 0x80800B28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800C0C;
    // 0x80800B28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B2C:
    // 0x80800B2C: jal         0x8080000C
    // 0x80800B30: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080000C_chflysaucercrate(rdram, ctx);
        goto after_6;
    // 0x80800B30: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x80800B34: b           L_80800C0C
    // 0x80800B38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800C0C;
    // 0x80800B38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B3C:
    // 0x80800B3C: jal         0x800DA298
    // 0x80800B40: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800B40: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    after_7:
    // 0x80800B44: beq         $v0, $zero, L_80800B64
    if (ctx->r2 == 0) {
        // 0x80800B48: nop
    
            goto L_80800B64;
    }
    // 0x80800B48: nop

    // 0x80800B4C: jal         0x800FFAB0
    // 0x80800B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_8;
    // 0x80800B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800B54: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80800B58: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x80800B5C: b           L_80800C08
    // 0x80800B60: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
        goto L_80800C08;
    // 0x80800B60: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
L_80800B64:
    // 0x80800B64: jal         0x80088840
    // 0x80800B68: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_9;
    // 0x80800B68: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_9:
    // 0x80800B6C: bne         $v0, $zero, L_80800B80
    if (ctx->r2 != 0) {
        // 0x80800B70: nop
    
            goto L_80800B80;
    }
    // 0x80800B70: nop

    // 0x80800B74: jal         0x800DA298
    // 0x80800B78: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x80800B78: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    after_10:
    // 0x80800B7C: beq         $v0, $zero, L_80800C00
    if (ctx->r2 == 0) {
        // 0x80800B80: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1696, 0XCE0) << 16);
            goto L_80800C00;
    }
L_80800B80:
    // 0x80800B80: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XCE0) << 16);
    // 0x80800B84: lwc1        $f10, 0xCE0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XCE0));
    // 0x80800B88: lui         $at, 0x44C8
    ctx->r1 = S32(0X44C8 << 16);
    // 0x80800B8C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800B90: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XCE4) << 16);
    // 0x80800B94: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x80800B98: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x80800B9C: lwc1        $f18, 0xCE4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XCE4));
    // 0x80800BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800BA8: jal         0x8008A4B0
    // 0x80800BAC: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_11;
    // 0x80800BAC: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    after_11:
    // 0x80800BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BB4: jal         0x8080000C
    // 0x80800BB8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8080000C_chflysaucercrate(rdram, ctx);
        goto after_12;
    // 0x80800BB8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_12:
    // 0x80800BBC: jal         0x80088840
    // 0x80800BC0: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_13;
    // 0x80800BC0: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_13:
    // 0x80800BC4: beq         $v0, $zero, L_80800BE8
    if (ctx->r2 == 0) {
        // 0x80800BC8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800BE8;
    }
    // 0x80800BC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800BCC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800BD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800BD4: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80800BD8: jal         0x80085708
    // 0x80800BDC: addiu       $a3, $zero, 0x2810
    ctx->r7 = ADD32(0, 0X2810);
    _capod_entrypoint_13(rdram, ctx);
        goto after_14;
    // 0x80800BDC: addiu       $a3, $zero, 0x2810
    ctx->r7 = ADD32(0, 0X2810);
    after_14:
    // 0x80800BE0: b           L_80800C0C
    // 0x80800BE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800C0C;
    // 0x80800BE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800BE8:
    // 0x80800BE8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800BEC: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80800BF0: jal         0x80085708
    // 0x80800BF4: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    _capod_entrypoint_13(rdram, ctx);
        goto after_15;
    // 0x80800BF4: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    after_15:
    // 0x80800BF8: b           L_80800C0C
    // 0x80800BFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800C0C;
    // 0x80800BFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800C00:
    // 0x80800C00: jal         0x800FFAB0
    // 0x80800C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_16;
    // 0x80800C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
L_80800C08:
    // 0x80800C08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800C0C:
    // 0x80800C0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800C10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800C14: jr          $ra
    // 0x80800C18: nop

    return;
    // 0x80800C18: nop

    // 0x80800C1C: nop

;}
RECOMP_FUNC void func_800F6CC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6CC8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F6CCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F6CD0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6CD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6CD8: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F6CDC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F6CE0: jal         0x8009E674
    // 0x800F6CE4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8009E674(rdram, ctx);
        goto after_0;
    // 0x800F6CE4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x800F6CE8: beq         $v0, $zero, L_800F6CF8
    if (ctx->r2 == 0) {
        // 0x800F6CEC: nop
    
            goto L_800F6CF8;
    }
    // 0x800F6CEC: nop

    // 0x800F6CF0: b           L_800F6D14
    // 0x800F6CF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F6D14;
    // 0x800F6CF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F6CF8:
    // 0x800F6CF8: jal         0x800F8B64
    // 0x800F6CFC: nop

    func_800F8B64(rdram, ctx);
        goto after_1;
    // 0x800F6CFC: nop

    after_1:
    // 0x800F6D00: beql        $v0, $zero, L_800F6D14
    if (ctx->r2 == 0) {
        // 0x800F6D04: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800F6D14;
    }
    goto skip_0;
    // 0x800F6D04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800F6D08: b           L_800F6D14
    // 0x800F6D0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F6D14;
    // 0x800F6D0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F6D10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F6D14:
    // 0x800F6D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6D18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F6D1C: jr          $ra
    // 0x800F6D20: nop

    return;
    // 0x800F6D20: nop

;}
RECOMP_FUNC void _idlight_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088D00: syscall     735
    recomp_syscall_handler(rdram, ctx, 0x80088D00);
    return;
    // 0x80088D04: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808004B0_chlagoonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808004B4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808004B8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808004BC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808004C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004C4: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x808004C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808004CC: jal         0x80086670
    // 0x808004D0: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808004D0: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_0:
    // 0x808004D4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1052, 0XA64) << 16);
    // 0x808004D8: addiu       $a2, $a2, 0xA64
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1052, 0XA64));
    // 0x808004DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808004E0: jal         0x80089D18
    // 0x808004E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808004E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x808004E8: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1052, 0XA30) << 16);
    // 0x808004EC: addiu       $t6, $t6, 0xA30
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1052, 0XA30));
    // 0x808004F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808004FC: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80800500: jal         0x800BBCB8
    // 0x80800504: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x80800504: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_2:
    // 0x80800508: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080050C: jal         0x80108B04
    // 0x80800510: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_3;
    // 0x80800510: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800514: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800518: jal         0x80101FDC
    // 0x8080051C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x8080051C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80800520: lbu         $t7, 0x65($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X65);
    // 0x80800524: addiu       $a0, $zero, 0xCF
    ctx->r4 = ADD32(0, 0XCF);
    // 0x80800528: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x8080052C: jal         0x800DA544
    // 0x80800530: sb          $t8, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r24;
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x80800530: sb          $t8, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r24;
    after_5:
    // 0x80800534: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800538: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080053C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800540: jr          $ra
    // 0x80800544: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800544: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800A9B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9B8C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A9B90: addiu       $v0, $v0, 0x7760
    ctx->r2 = ADD32(ctx->r2, 0X7760);
    // 0x800A9B94: sh          $a0, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r4;
    // 0x800A9B98: jr          $ra
    // 0x800A9B9C: sh          $a1, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r5;
    return;
    // 0x800A9B9C: sh          $a1, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void chnicecavemenguard_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1272, 0X920) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x920
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1272, 0X920));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x920
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1272, 0X920));
;}
RECOMP_FUNC void _chrainripples_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086308: syscall     305
    recomp_syscall_handler(rdram, ctx, 0x80086308);
    return;
    // 0x8008630C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bsledge_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800837B0: syscall     74
    recomp_syscall_handler(rdram, ctx, 0x800837B0);
    return;
    // 0x800837B4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808009DC_chphlegm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009E0: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808009E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009E8: beq         $a1, $at, L_80800A1C
    if (ctx->r5 == ctx->r1) {
        // 0x808009EC: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800A1C;
    }
    // 0x808009EC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808009F0: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x808009F4: beq         $a1, $at, L_80800A0C
    if (ctx->r5 == ctx->r1) {
        // 0x808009F8: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800A0C;
    }
    // 0x808009F8: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808009FC: beq         $a1, $at, L_80800A2C
    if (ctx->r5 == ctx->r1) {
        // 0x80800A00: nop
    
            goto L_80800A2C;
    }
    // 0x80800A00: nop

    // 0x80800A04: b           L_80800A48
    // 0x80800A08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A48;
    // 0x80800A08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A0C:
    // 0x80800A0C: jal         0x80800A58
    // 0x80800A10: nop

    func_80800A58_chphlegm(rdram, ctx);
        goto after_0;
    // 0x80800A10: nop

    after_0:
    // 0x80800A14: b           L_80800A48
    // 0x80800A18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A48;
    // 0x80800A18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A1C:
    // 0x80800A1C: jal         0x80101FDC
    // 0x80800A20: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800A20: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800A24: b           L_80800A48
    // 0x80800A28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A48;
    // 0x80800A28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A2C:
    // 0x80800A2C: jal         0x80101FDC
    // 0x80800A30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800A30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800A34: b           L_80800A48
    // 0x80800A38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A48;
    // 0x80800A38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800A3C: b           L_80800A48
    // 0x80800A40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A48;
    // 0x80800A40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800A44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A48:
    // 0x80800A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A50: jr          $ra
    // 0x80800A54: nop

    return;
    // 0x80800A54: nop

;}
RECOMP_FUNC void chmineprospector_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(892, 0X10BC) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x10BC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(892, 0X10BC));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x10BC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(892, 0X10BC));
;}
RECOMP_FUNC void func_800CE524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE524: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CE528: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800CE52C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800CE530: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800CE534: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800CE538: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CE53C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800CE540: addiu       $s1, $zero, 0x9
    ctx->r17 = ADD32(0, 0X9);
L_800CE544:
    // 0x800CE544: jal         0x800CE3E0
    // 0x800CE548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800CE3E0(rdram, ctx);
        goto after_0;
    // 0x800CE548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800CE54C: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x800CE550: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x800CE554: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800CE558: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
    // 0x800CE55C: swc1        $f20, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f20.u32l;
    // 0x800CE560: sb          $zero, 0x16($v0)
    MEM_B(0X16, ctx->r2) = 0;
    // 0x800CE564: sb          $zero, 0x15($v0)
    MEM_B(0X15, ctx->r2) = 0;
    // 0x800CE568: sb          $zero, 0x14($v0)
    MEM_B(0X14, ctx->r2) = 0;
    // 0x800CE56C: sb          $zero, 0x12($v0)
    MEM_B(0X12, ctx->r2) = 0;
    // 0x800CE570: sb          $zero, 0x13($v0)
    MEM_B(0X13, ctx->r2) = 0;
    // 0x800CE574: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x800CE578: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x800CE57C: bne         $s0, $s1, L_800CE544
    if (ctx->r16 != ctx->r17) {
        // 0x800CE580: sh          $t6, 0xA($v0)
        MEM_H(0XA, ctx->r2) = ctx->r14;
            goto L_800CE544;
    }
    // 0x800CE580: sh          $t6, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r14;
    // 0x800CE584: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CE588: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800CE58C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800CE590: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800CE594: jr          $ra
    // 0x800CE598: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800CE598: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800538_chfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800538: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8080053C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800540: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80800544: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80800548: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8080054C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800550: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800554: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800558: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x8080055C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800560: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800564: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x80800568: beql        $t6, $zero, L_8080058C
    if (ctx->r14 == 0) {
        // 0x8080056C: lw          $t2, 0x7C($s2)
        ctx->r10 = MEM_W(ctx->r18, 0X7C);
            goto L_8080058C;
    }
    goto skip_0;
    // 0x8080056C: lw          $t2, 0x7C($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X7C);
    skip_0:
    // 0x80800570: lhu         $t9, 0x6E($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X6E);
    // 0x80800574: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80800578: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x8080057C: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x80800580: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800584: sh          $t1, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r9;
    // 0x80800588: lw          $t2, 0x7C($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X7C);
L_8080058C:
    // 0x8080058C: sll         $t4, $t2, 19
    ctx->r12 = S32(ctx->r10 << 19);
    // 0x80800590: bgezl       $t4, L_808006A0
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800594: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_808006A0;
    }
    goto skip_1;
    // 0x80800594: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x80800598: lwc1        $f4, 0x58($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X58);
    // 0x8080059C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005A0: nop

    // 0x808005A4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808005A8: nop

    // 0x808005AC: bc1tl       L_808006A0
    if (c1cs) {
        // 0x808005B0: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_808006A0;
    }
    goto skip_2;
    // 0x808005B0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_2:
    // 0x808005B4: lw          $t5, 0x6C($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X6C);
    // 0x808005B8: addiu       $s0, $sp, 0x68
    ctx->r16 = ADD32(ctx->r29, 0X68);
    // 0x808005BC: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x808005C0: bnel        $t6, $zero, L_808006A0
    if (ctx->r14 != 0) {
        // 0x808005C4: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_808006A0;
    }
    goto skip_3;
    // 0x808005C4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_3:
    // 0x808005C8: jal         0x800E3980
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E3980(rdram, ctx);
        goto after_0;
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808005D0: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    // 0x808005D4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x808005D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808005DC: jal         0x800F18FC
    // 0x808005E0: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    func_800F18FC(rdram, ctx);
        goto after_1;
    // 0x808005E0: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_1:
    // 0x808005E4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808005E8: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808005EC: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x808005F0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808005F4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808005F8: addiu       $s0, $sp, 0x54
    ctx->r16 = ADD32(ctx->r29, 0X54);
    // 0x808005FC: addiu       $s1, $sp, 0x5C
    ctx->r17 = ADD32(ctx->r29, 0X5C);
L_80800600:
    // 0x80800600: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800604: jal         0x800DC178
    // 0x80800608: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800608: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_2:
    // 0x8080060C: sub.s       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x80800610: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800614: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800618: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8080061C: bne         $s0, $s1, L_80800600
    if (ctx->r16 != ctx->r17) {
        // 0x80800620: swc1        $f16, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->f16.u32l;
            goto L_80800600;
    }
    // 0x80800620: swc1        $f16, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->f16.u32l;
    // 0x80800624: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800628: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080062C: lwc1        $f18, 0x38($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X38);
    // 0x80800630: addiu       $s0, $sp, 0x5C
    ctx->r16 = ADD32(ctx->r29, 0X5C);
    // 0x80800634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800638: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8080063C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80800640: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800644: jal         0x800EEBF0
    // 0x80800648: nop

    func_800EEBF0(rdram, ctx);
        goto after_3;
    // 0x80800648: nop

    after_3:
    // 0x8080064C: addiu       $s1, $sp, 0x74
    ctx->r17 = ADD32(ctx->r29, 0X74);
    // 0x80800650: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800654: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80800658: jal         0x800EE780
    // 0x8080065C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800EE780(rdram, ctx);
        goto after_4;
    // 0x8080065C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x80800660: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800664: jal         0x80088AB0
    // 0x80800668: addiu       $a1, $zero, 0x9E5
    ctx->r5 = ADD32(0, 0X9E5);
    _fxtwinkle_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800668: addiu       $a1, $zero, 0x9E5
    ctx->r5 = ADD32(0, 0X9E5);
    after_5:
    // 0x8080066C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800670: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800674: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1044, 0X6F8) << 16);
    // 0x80800678: jal         0x800DC178
    // 0x8080067C: lwc1        $f14, 0x6F8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1044, 0X6F8));
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x8080067C: lwc1        $f14, 0x6F8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1044, 0X6F8));
    after_6:
    // 0x80800680: jal         0x800D9058
    // 0x80800684: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800D9058(rdram, ctx);
        goto after_7;
    // 0x80800684: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_7:
    // 0x80800688: lhu         $t8, 0x6E($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X6E);
    // 0x8080068C: andi        $t9, $v0, 0x1FF
    ctx->r25 = ctx->r2 & 0X1FF;
    // 0x80800690: andi        $t0, $t8, 0xFE00
    ctx->r8 = ctx->r24 & 0XFE00;
    // 0x80800694: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x80800698: sh          $t1, 0x6E($s2)
    MEM_H(0X6E, ctx->r18) = ctx->r9;
    // 0x8080069C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_808006A0:
    // 0x808006A0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808006A4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808006A8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808006AC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x808006B0: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x808006B4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x808006B8: jr          $ra
    // 0x808006BC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x808006BC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_80800F9C_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F9C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800FA0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800FA4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800FA8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800FAC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800FB0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800FB4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800FB8: jal         0x80100094
    // 0x80800FBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800FBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800FC0: jal         0x80089AB0
    // 0x80800FC4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    _sukickball_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800FC4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_1:
    // 0x80800FC8: sb          $v0, 0x39($s3)
    MEM_B(0X39, ctx->r19) = ctx->r2;
    // 0x80800FCC: sb          $zero, 0x3C($s3)
    MEM_B(0X3C, ctx->r19) = 0;
    // 0x80800FD0: jal         0x800DA298
    // 0x80800FD4: addiu       $a0, $zero, 0x667
    ctx->r4 = ADD32(0, 0X667);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800FD4: addiu       $a0, $zero, 0x667
    ctx->r4 = ADD32(0, 0X667);
    after_2:
    // 0x80800FD8: bne         $v0, $zero, L_80800FF0
    if (ctx->r2 != 0) {
        // 0x80800FDC: nop
    
            goto L_80800FF0;
    }
    // 0x80800FDC: nop

    // 0x80800FE0: jal         0x80090178
    // 0x80800FE4: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    func_80090178(rdram, ctx);
        goto after_3;
    // 0x80800FE4: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_3:
    // 0x80800FE8: bne         $v0, $zero, L_80801000
    if (ctx->r2 != 0) {
        // 0x80800FEC: nop
    
            goto L_80801000;
    }
    // 0x80800FEC: nop

L_80800FF0:
    // 0x80800FF0: jal         0x800FFAB0
    // 0x80800FF4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x80800FF4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80800FF8: b           L_808011F4
    // 0x80800FFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808011F4;
    // 0x80800FFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801000:
    // 0x80801000: jal         0x800EA05C
    // 0x80801004: nop

    func_800EA05C(rdram, ctx);
        goto after_5;
    // 0x80801004: nop

    after_5:
    // 0x80801008: addiu       $at, $zero, 0xBB
    ctx->r1 = ADD32(0, 0XBB);
    // 0x8080100C: beq         $v0, $at, L_8080101C
    if (ctx->r2 == ctx->r1) {
        // 0x80801010: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8080101C;
    }
    // 0x80801010: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801014: jal         0x800DA3B8
    // 0x80801018: addiu       $a0, $zero, 0x65A
    ctx->r4 = ADD32(0, 0X65A);
    func_800DA3B8(rdram, ctx);
        goto after_6;
    // 0x80801018: addiu       $a0, $zero, 0x65A
    ctx->r4 = ADD32(0, 0X65A);
    after_6:
L_8080101C:
    // 0x8080101C: lbu         $v0, 0x39($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X39);
    // 0x80801020: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1608, 0X509C) << 16);
    // 0x80801024: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80801028: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8080102C: lw          $t7, 0x509C($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(1608, 0X509C));
    // 0x80801030: sltiu       $at, $v0, 0x5
    ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x80801034: beq         $at, $zero, L_808010F4
    if (ctx->r1 == 0) {
        // 0x80801038: sb          $t7, 0x3A($s3)
        MEM_B(0X3A, ctx->r19) = ctx->r15;
            goto L_808010F4;
    }
    // 0x80801038: sb          $t7, 0x3A($s3)
    MEM_B(0X3A, ctx->r19) = ctx->r15;
    // 0x8080103C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80801040: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4EC0) << 16);
    // 0x80801044: addu        $at, $at, $t8
    gpr jr_addend_8080104C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80801048: lw          $t8, 0x4EC0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4EC0));
    // 0x8080104C: jr          $t8
    // 0x80801050: nop

    switch (jr_addend_8080104C >> 2) {
        case 0: goto L_80801054; break;
        case 1: goto L_80801078; break;
        case 2: goto L_80801098; break;
        case 3: goto L_808010F4; break;
        case 4: goto L_808010BC; break;
        default: switch_error(__func__, 0x8080104C, 0x80804EC0);
    }
    // 0x80801050: nop

L_80801054:
    // 0x80801054: sb          $zero, 0x39($s3)
    MEM_B(0X39, ctx->r19) = 0;
    // 0x80801058: jal         0x800DA298
    // 0x8080105C: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x8080105C: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    after_7:
    // 0x80801060: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801064: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801068: jal         0x80800F24
    // 0x8080106C: lbu         $a2, 0x39($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X39);
    func_80800F24_chstoneballcontrol(rdram, ctx);
        goto after_8;
    // 0x8080106C: lbu         $a2, 0x39($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X39);
    after_8:
    // 0x80801070: b           L_808010F4
    // 0x80801074: nop

        goto L_808010F4;
    // 0x80801074: nop

L_80801078:
    // 0x80801078: jal         0x800DA298
    // 0x8080107C: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x8080107C: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    after_9:
    // 0x80801080: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801084: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801088: jal         0x80800F24
    // 0x8080108C: lbu         $a2, 0x39($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X39);
    func_80800F24_chstoneballcontrol(rdram, ctx);
        goto after_10;
    // 0x8080108C: lbu         $a2, 0x39($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X39);
    after_10:
    // 0x80801090: b           L_808010F4
    // 0x80801094: nop

        goto L_808010F4;
    // 0x80801094: nop

L_80801098:
    // 0x80801098: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8080109C: jal         0x800D0A9C
    // 0x808010A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_11;
    // 0x808010A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x808010A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808010A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808010AC: jal         0x80800F24
    // 0x808010B0: lbu         $a2, 0x39($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X39);
    func_80800F24_chstoneballcontrol(rdram, ctx);
        goto after_12;
    // 0x808010B0: lbu         $a2, 0x39($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X39);
    after_12:
    // 0x808010B4: b           L_808010F4
    // 0x808010B8: nop

        goto L_808010F4;
    // 0x808010B8: nop

L_808010BC:
    // 0x808010BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808010C0: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
L_808010C4:
    // 0x808010C4: jal         0x800F6438
    // 0x808010C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_13;
    // 0x808010C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808010CC: beq         $v0, $zero, L_808010DC
    if (ctx->r2 == 0) {
        // 0x808010D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808010DC;
    }
    // 0x808010D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010D4: jal         0x800F4CEC
    // 0x808010D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F4CEC(rdram, ctx);
        goto after_14;
    // 0x808010D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
L_808010DC:
    // 0x808010DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808010E0: bne         $s0, $s1, L_808010C4
    if (ctx->r16 != ctx->r17) {
        // 0x808010E4: nop
    
            goto L_808010C4;
    }
    // 0x808010E4: nop

    // 0x808010E8: jal         0x80088368
    // 0x808010EC: nop

    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_15;
    // 0x808010EC: nop

    after_15:
    // 0x808010F0: sb          $v0, 0x3A($s3)
    MEM_B(0X3A, ctx->r19) = ctx->r2;
L_808010F4:
    // 0x808010F4: jal         0x8080128C
    // 0x808010F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8080128C_chstoneballcontrol(rdram, ctx);
        goto after_16;
    // 0x808010F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_16:
    // 0x808010FC: lbu         $t9, 0x39($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X39);
    // 0x80801100: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801104: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80801108: bne         $t9, $at, L_8080111C
    if (ctx->r25 != ctx->r1) {
        // 0x8080110C: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8080111C;
    }
    // 0x8080110C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80801110: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80801114: b           L_80801124
    // 0x80801118: sb          $t0, 0xA($s3)
    MEM_B(0XA, ctx->r19) = ctx->r8;
        goto L_80801124;
    // 0x80801118: sb          $t0, 0xA($s3)
    MEM_B(0XA, ctx->r19) = ctx->r8;
L_8080111C:
    // 0x8080111C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80801120: sb          $t1, 0xA($s3)
    MEM_B(0XA, ctx->r19) = ctx->r9;
L_80801124:
    // 0x80801124: lbu         $t5, 0x3A($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X3A);
    // 0x80801128: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8080112C: sb          $t2, 0xB($s3)
    MEM_B(0XB, ctx->r19) = ctx->r10;
    // 0x80801130: sb          $t3, 0xC($s3)
    MEM_B(0XC, ctx->r19) = ctx->r11;
    // 0x80801134: sb          $t4, 0xD($s3)
    MEM_B(0XD, ctx->r19) = ctx->r12;
    // 0x80801138: blez        $t5, L_808011B0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8080113C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_808011B0;
    }
    // 0x8080113C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801140: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x80801144: lbu         $v0, 0xA($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XA);
L_80801148:
    // 0x80801148: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080114C: addiu       $a0, $zero, 0x1B6
    ctx->r4 = ADD32(0, 0X1B6);
    // 0x80801150: beq         $v0, $at, L_8080116C
    if (ctx->r2 == ctx->r1) {
        // 0x80801154: addiu       $a1, $sp, 0x28
        ctx->r5 = ADD32(ctx->r29, 0X28);
            goto L_8080116C;
    }
    // 0x80801154: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80801158: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080115C: beql        $v0, $at, L_80801190
    if (ctx->r2 == ctx->r1) {
        // 0x80801160: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80801190;
    }
    goto skip_0;
    // 0x80801160: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x80801164: b           L_80801190
    // 0x80801168: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
        goto L_80801190;
    // 0x80801168: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_8080116C:
    // 0x8080116C: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80801170: jal         0x801084B0
    // 0x80801174: addu        $s2, $s3, $t6
    ctx->r18 = ADD32(ctx->r19, ctx->r14);
    func_801084B0(rdram, ctx);
        goto after_17;
    // 0x80801174: addu        $s2, $s3, $t6
    ctx->r18 = ADD32(ctx->r19, ctx->r14);
    after_17:
    // 0x80801178: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8080117C: sw          $t7, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r15;
    // 0x80801180: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80801184: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80801188: sw          $t9, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r25;
    // 0x8080118C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80801190:
    // 0x80801190: jal         0x80801330
    // 0x80801194: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80801330_chstoneballcontrol(rdram, ctx);
        goto after_18;
    // 0x80801194: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_18:
    // 0x80801198: lbu         $t0, 0x3A($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X3A);
    // 0x8080119C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808011A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808011A4: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x808011A8: bnel        $at, $zero, L_80801148
    if (ctx->r1 != 0) {
        // 0x808011AC: lbu         $v0, 0xA($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0XA);
            goto L_80801148;
    }
    goto skip_1;
    // 0x808011AC: lbu         $v0, 0xA($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XA);
    skip_1:
L_808011B0:
    // 0x808011B0: jal         0x800EA05C
    // 0x808011B4: nop

    func_800EA05C(rdram, ctx);
        goto after_19;
    // 0x808011B4: nop

    after_19:
    // 0x808011B8: addiu       $at, $zero, 0xBB
    ctx->r1 = ADD32(0, 0XBB);
    // 0x808011BC: bne         $v0, $at, L_808011E0
    if (ctx->r2 != ctx->r1) {
        // 0x808011C0: nop
    
            goto L_808011E0;
    }
    // 0x808011C0: nop

    // 0x808011C4: jal         0x8080145C
    // 0x808011C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8080145C_chstoneballcontrol(rdram, ctx);
        goto after_20;
    // 0x808011C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_20:
    // 0x808011CC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x808011D0: lbu         $t2, 0x72($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X72);
    // 0x808011D4: andi        $t3, $t2, 0xFF03
    ctx->r11 = ctx->r10 & 0XFF03;
    // 0x808011D8: ori         $t4, $t3, 0x1C
    ctx->r12 = ctx->r11 | 0X1C;
    // 0x808011DC: sb          $t4, 0x72($t1)
    MEM_B(0X72, ctx->r9) = ctx->r12;
L_808011E0:
    // 0x808011E0: jal         0x80089B28
    // 0x808011E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _sukickball_entrypoint_18(rdram, ctx);
        goto after_21;
    // 0x808011E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_21:
    // 0x808011E8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x808011EC: sb          $t5, 0x3C($s3)
    MEM_B(0X3C, ctx->r19) = ctx->r13;
    // 0x808011F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808011F4:
    // 0x808011F4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808011F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808011FC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80801200: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80801204: jr          $ra
    // 0x80801208: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80801208: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _bsbreegullbash_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082AF8: syscall     26
    recomp_syscall_handler(rdram, ctx, 0x80082AF8);
    return;
    // 0x80082AFC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chblink_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800857A8: syscall     175
    recomp_syscall_handler(rdram, ctx, 0x800857A8);
    return;
    // 0x800857AC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800000_gzreg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800008: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8080000C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800010: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80800014: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800018: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080001C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XB48) << 16);
    // 0x80800020: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800024: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800028: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8080002C: addiu       $a0, $a0, 0xB48
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XB48));
    // 0x80800030: jal         0x8001D37C
    // 0x80800034: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_8001D37C(rdram, ctx);
        goto after_0;
    // 0x80800034: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_0:
    // 0x80800038: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XB54) << 16);
    // 0x8080003C: jal         0x8001D37C
    // 0x80800040: addiu       $a0, $a0, 0xB54
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XB54));
    func_8001D37C(rdram, ctx);
        goto after_1;
    // 0x80800040: addiu       $a0, $a0, 0xB54
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XB54));
    after_1:
    // 0x80800044: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80800048: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(3394, 0XB58) << 16);
    // 0x8080004C: addiu       $s3, $s3, 0xB58
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(3394, 0XB58));
    // 0x80800050: beq         $v0, $zero, L_808000A0
    if (ctx->r2 == 0) {
        // 0x80800054: lui         $s2, 0x8080
        ctx->r18 = S32(RELOC_HI16(3394, 0XB5C) << 16);
            goto L_808000A0;
    }
    // 0x80800054: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(3394, 0XB5C) << 16);
    // 0x80800058: addiu       $s2, $s2, 0xB5C
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(3394, 0XB5C));
    // 0x8080005C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
L_80800060:
    // 0x80800060: and         $t7, $v0, $s4
    ctx->r15 = ctx->r2 & ctx->r20;
    // 0x80800064: bnel        $t6, $t7, L_80800094
    if (ctx->r14 != ctx->r15) {
        // 0x80800068: lw          $v0, 0xC($s0)
        ctx->r2 = MEM_W(ctx->r16, 0XC);
            goto L_80800094;
    }
    goto skip_0;
    // 0x80800068: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x8080006C: beq         $s1, $zero, L_8080007C
    if (ctx->r17 == 0) {
        // 0x80800070: nop
    
            goto L_8080007C;
    }
    // 0x80800070: nop

    // 0x80800074: b           L_80800084
    // 0x80800078: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_80800084;
    // 0x80800078: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8080007C:
    // 0x8080007C: jal         0x8001D37C
    // 0x80800080: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8001D37C(rdram, ctx);
        goto after_2;
    // 0x80800080: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_2:
L_80800084:
    // 0x80800084: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800088: jal         0x8001D37C
    // 0x8080008C: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    func_8001D37C(rdram, ctx);
        goto after_3;
    // 0x8080008C: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    after_3:
    // 0x80800090: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
L_80800094:
    // 0x80800094: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80800098: bnel        $v0, $zero, L_80800060
    if (ctx->r2 != 0) {
        // 0x8080009C: lw          $t6, 0x4($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X4);
            goto L_80800060;
    }
    goto skip_1;
    // 0x8080009C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    skip_1:
L_808000A0:
    // 0x808000A0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XB60) << 16);
    // 0x808000A4: jal         0x8001D37C
    // 0x808000A8: addiu       $a0, $a0, 0xB60
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XB60));
    func_8001D37C(rdram, ctx);
        goto after_4;
    // 0x808000A8: addiu       $a0, $a0, 0xB60
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XB60));
    after_4:
    // 0x808000AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808000B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000B4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808000B8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808000BC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808000C0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808000C4: jr          $ra
    // 0x808000C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808000C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void set_widescreen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800157E0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800157E4: jr          $ra
    // 0x800157E8: sh          $a0, -0x6648($at)
    MEM_H(-0X6648, ctx->r1) = ctx->r4;
    return;
    // 0x800157E8: sh          $a0, -0x6648($at)
    MEM_H(-0X6648, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void _chstatueboss_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086530: syscall     334
    recomp_syscall_handler(rdram, ctx, 0x80086530);
    return;
    // 0x80086534: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800FCAE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FCAE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FCAE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FCAE8: jal         0x800FCB54
    // 0x800FCAEC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800FCB54(rdram, ctx);
        goto after_0;
    // 0x800FCAEC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_0:
    // 0x800FCAF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FCAF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FCAF8: jr          $ra
    // 0x800FCAFC: nop

    return;
    // 0x800FCAFC: nop

;}
RECOMP_FUNC void func_80800018_chgobihailfire(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080001C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800024: jal         0x80088848
    // 0x80800028: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800028: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080002C: beq         $v0, $zero, L_80800070
    if (ctx->r2 == 0) {
        // 0x80800030: nop
    
            goto L_80800070;
    }
    // 0x80800030: nop

    // 0x80800034: jal         0x800EA05C
    // 0x80800038: nop

    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x80800038: nop

    after_1:
    // 0x8080003C: addiu       $at, $zero, 0x129
    ctx->r1 = ADD32(0, 0X129);
    // 0x80800040: beql        $v0, $at, L_80800054
    if (ctx->r2 == ctx->r1) {
        // 0x80800044: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800054;
    }
    goto skip_0;
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800048: jal         0x800FFAB0
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800054:
    // 0x80800054: jal         0x80102424
    // 0x80800058: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x80800058: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800060: jal         0x8010573C
    // 0x80800064: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8010573C(rdram, ctx);
        goto after_4;
    // 0x80800064: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_4:
    // 0x80800068: b           L_80800094
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800094;
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800070:
    // 0x80800070: jal         0x800DA298
    // 0x80800074: addiu       $a0, $zero, 0x97
    ctx->r4 = ADD32(0, 0X97);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80800074: addiu       $a0, $zero, 0x97
    ctx->r4 = ADD32(0, 0X97);
    after_5:
    // 0x80800078: bnel        $v0, $zero, L_80800094
    if (ctx->r2 != 0) {
        // 0x8080007C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800094;
    }
    goto skip_1;
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800080: jal         0x800FFAB0
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800088: b           L_808000B8
    // 0x8080008C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000B8;
    // 0x8080008C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800094:
    // 0x80800094: jal         0x80105A9C
    // 0x80800098: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    func_80105A9C(rdram, ctx);
        goto after_7;
    // 0x80800098: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    after_7:
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A0: jal         0x80102FDC
    // 0x808000A4: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    func_80102FDC(rdram, ctx);
        goto after_8;
    // 0x808000A4: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_8:
    // 0x808000A8: lbu         $t7, 0x95($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X95);
    // 0x808000AC: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x808000B0: sb          $t8, 0x95($s0)
    MEM_B(0X95, ctx->r16) = ctx->r24;
    // 0x808000B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000B8:
    // 0x808000B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000C0: jr          $ra
    // 0x808000C4: nop

    return;
    // 0x808000C4: nop

;}
RECOMP_FUNC void func_8009E7C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E7C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009E7CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009E7D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009E7D4: lw          $t6, 0x120($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X120);
    // 0x8009E7D8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8009E7DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009E7E0: sh          $a1, 0xC($t6)
    MEM_H(0XC, ctx->r14) = ctx->r5;
    // 0x8009E7E4: lw          $t8, 0x120($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X120);
    // 0x8009E7E8: sh          $t7, 0xE($t8)
    MEM_H(0XE, ctx->r24) = ctx->r15;
    // 0x8009E7EC: lw          $t9, 0x120($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X120);
    // 0x8009E7F0: jal         0x8009CB44
    // 0x8009E7F4: lw          $a1, 0x4($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X4);
    func_8009CB44(rdram, ctx);
        goto after_0;
    // 0x8009E7F4: lw          $a1, 0x4($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X4);
    after_0:
    // 0x8009E7F8: beql        $v0, $zero, L_8009E81C
    if (ctx->r2 == 0) {
        // 0x8009E7FC: lw          $t1, 0x120($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X120);
            goto L_8009E81C;
    }
    goto skip_0;
    // 0x8009E7FC: lw          $t1, 0x120($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X120);
    skip_0:
    // 0x8009E800: lw          $t0, 0x120($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X120);
    // 0x8009E804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009E808: jal         0x8009CB44
    // 0x8009E80C: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    func_8009CB44(rdram, ctx);
        goto after_1;
    // 0x8009E80C: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    after_1:
    // 0x8009E810: jalr        $v0
    // 0x8009E814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x8009E814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8009E818: lw          $t1, 0x120($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X120);
L_8009E81C:
    // 0x8009E81C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009E820: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009E824: lh          $v0, 0xE($t1)
    ctx->r2 = MEM_H(ctx->r9, 0XE);
    // 0x8009E828: jr          $ra
    // 0x8009E82C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8009E82C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8001E1B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E1B8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001E1BC: addiu       $a1, $a1, -0x2488
    ctx->r5 = ADD32(ctx->r5, -0X2488);
    // 0x8001E1C0: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x8001E1C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001E1C8: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8001E1CC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001E1D0: bne         $v1, $at, L_8001E1E0
    if (ctx->r3 != ctx->r1) {
        // 0x8001E1D4: sra         $a0, $t6, 16
        ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
            goto L_8001E1E0;
    }
    // 0x8001E1D4: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001E1D8: jr          $ra
    // 0x8001E1DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001E1DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001E1E0:
    // 0x8001E1E0: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x8001E1E4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001E1E8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8001E1EC: sh          $a0, -0x2490($at)
    MEM_H(-0X2490, ctx->r1) = ctx->r4;
    // 0x8001E1F0: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x8001E1F4: sb          $t9, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r25;
    // 0x8001E1F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001E1FC: jr          $ra
    // 0x8001E200: nop

    return;
    // 0x8001E200: nop

;}
RECOMP_FUNC void func_800A5608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5608: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A560C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800A5610: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5614: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5618: jal         0x80085560
    // 0x800A561C: addiu       $a0, $a0, -0x6AC0
    ctx->r4 = ADD32(ctx->r4, -0X6AC0);
    _cadbmgrDll_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x800A561C: addiu       $a0, $a0, -0x6AC0
    ctx->r4 = ADD32(ctx->r4, -0X6AC0);
    after_0:
    // 0x800A5620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5624: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5628: jr          $ra
    // 0x800A562C: nop

    return;
    // 0x800A562C: nop

;}
RECOMP_FUNC void _sujiggy_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A738: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A738);
    return;
    // 0x8008A73C: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void _chvolcanobits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086408: syscall     322
    recomp_syscall_handler(rdram, ctx, 0x80086408);
    return;
    // 0x8008640C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chghostdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085E68: syscall     251
    recomp_syscall_handler(rdram, ctx, 0x80085E68);
    return;
    // 0x80085E6C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80113640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80113640: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80113644: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80113648: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8011364C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80113650: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80113654: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80113658: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8011365C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80113660: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80113664: lui         $a3, 0x82
    ctx->r7 = S32(0X82 << 16);
    // 0x80113668: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x8011366C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80113670: jal         0x800FAB50
    // 0x80113674: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800FAB50(rdram, ctx);
        goto after_0;
    // 0x80113674: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80113678: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8011367C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80113680: jr          $ra
    // 0x80113684: nop

    return;
    // 0x80113684: nop

;}
RECOMP_FUNC void _bstaxi_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E20: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083E20);
    return;
    // 0x80083E24: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_80800C00_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C08: jal         0x80100094
    // 0x80800C0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800C10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C14: lw          $v0, 0xD0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XD0);
    // 0x80800C18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C1C: jr          $ra
    // 0x80800C20: nop

    return;
    // 0x80800C20: nop

;}
RECOMP_FUNC void _sukickball_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089A98: syscall     802
    recomp_syscall_handler(rdram, ctx, 0x80089A98);
    return;
    // 0x80089A9C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080048C_chmrsicecube(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080048C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800490: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800494: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1204, 0XA3C) << 16);
    // 0x80800498: addiu       $a0, $a0, 0xA3C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1204, 0XA3C));
    // 0x8080049C: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x808004A0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808004A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004A8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808004AC: jal         0x800882A8
    // 0x808004B0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _gccubesearch_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x808004B0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x808004B4: bne         $v0, $zero, L_808004C4
    if (ctx->r2 != 0) {
        // 0x808004B8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_808004C4;
    }
    // 0x808004B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808004BC: b           L_808004F8
    // 0x808004C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004F8;
    // 0x808004C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004C4:
    // 0x808004C4: lw          $a0, 0x10($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X10);
    // 0x808004C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808004CC: srl         $t6, $a0, 21
    ctx->r14 = S32(U32(ctx->r4) >> 21);
    // 0x808004D0: jal         0x80089C80
    // 0x808004D4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    _subaddiefind_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x808004D4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x808004D8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808004DC: beq         $v0, $zero, L_808004F4
    if (ctx->r2 == 0) {
        // 0x808004E0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808004F4;
    }
    // 0x808004E0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808004E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808004E8: jal         0x800EE88C
    // 0x808004EC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x808004EC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x808004F0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
L_808004F4:
    // 0x808004F4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_808004F8:
    // 0x808004F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800500: jr          $ra
    // 0x80800504: nop

    return;
    // 0x80800504: nop

;}
RECOMP_FUNC void func_808007A8_chnicecavemenguard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808007AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808007B4: jal         0x80100094
    // 0x808007B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808007BC: bne         $v0, $zero, L_808007FC
    if (ctx->r2 != 0) {
        // 0x808007C0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808007FC;
    }
    // 0x808007C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808007C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808007C8: jal         0x800897C0
    // 0x808007CC: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x808007CC: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_1:
    // 0x808007D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808007D4: jal         0x80100094
    // 0x808007D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808007D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808007DC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808007E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808007E4: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x808007E8: jal         0x800897E8
    // 0x808007EC: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x808007EC: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    after_3:
    // 0x808007F0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808007F4: jal         0x80089810
    // 0x808007F8: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    _suexpression_entrypoint_17(rdram, ctx);
        goto after_4;
    // 0x808007F8: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    after_4:
L_808007FC:
    // 0x808007FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800800: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800804: jr          $ra
    // 0x80800808: nop

    return;
    // 0x80800808: nop

;}
RECOMP_FUNC void func_80800AEC_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AF4: jal         0x800851F0
    // 0x80800AF8: nop

    _basub_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800AF8: nop

    after_0:
    // 0x80800AFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B04: jr          $ra
    // 0x80800B08: nop

    return;
    // 0x80800B08: nop

;}
RECOMP_FUNC void glid_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800004: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800008: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80800014: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80800018: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8080001C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800020: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800024: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800028: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8080002C: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x80800030: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x80800034: jal         0x800B2190
    // 0x80800038: lw          $a0, 0x14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14);
    func_800B2190(rdram, ctx);
        goto after_0;
    // 0x80800038: lw          $a0, 0x14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14);
    after_0:
    // 0x8080003C: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x80800040: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80800044: addiu       $s1, $s2, 0x1C
    ctx->r17 = ADD32(ctx->r18, 0X1C);
    // 0x80800048: blez        $a0, L_808000D0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8080004C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_808000D0;
    }
    // 0x8080004C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80800050:
    // 0x80800050: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    // 0x80800054: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800058: bnel        $s0, $t6, L_808000C4
    if (ctx->r16 != ctx->r14) {
        // 0x8080005C: lw          $t3, 0x4($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X4);
            goto L_808000C4;
    }
    goto skip_0;
    // 0x8080005C: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    skip_0:
    // 0x80800060: lh          $t7, 0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2);
    // 0x80800064: addiu       $s0, $s1, 0x8
    ctx->r16 = ADD32(ctx->r17, 0X8);
    // 0x80800068: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8080006C: addu        $s3, $t8, $s1
    ctx->r19 = ADD32(ctx->r24, ctx->r17);
    // 0x80800070: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x80800074: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x80800078: beq         $at, $zero, L_808000D0
    if (ctx->r1 == 0) {
        // 0x8080007C: or          $s2, $s3, $zero
        ctx->r18 = ctx->r19 | 0;
            goto L_808000D0;
    }
    // 0x8080007C: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_80800080:
    // 0x80800080: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x80800084: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x80800088: lh          $a3, 0x2($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X2);
    // 0x8080008C: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80800090: addu        $a2, $t0, $s4
    ctx->r6 = ADD32(ctx->r8, ctx->r20);
    // 0x80800094: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80800098: jalr        $s6
    // 0x8080009C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(ctx->r22)(rdram, ctx);
        goto after_1;
    // 0x8080009C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x808000A0: lh          $t1, 0x2($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2);
    // 0x808000A4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808000A8: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x808000AC: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x808000B0: bne         $at, $zero, L_80800080
    if (ctx->r1 != 0) {
        // 0x808000B4: addu        $s2, $s2, $t2
        ctx->r18 = ADD32(ctx->r18, ctx->r10);
            goto L_80800080;
    }
    // 0x808000B4: addu        $s2, $s2, $t2
    ctx->r18 = ADD32(ctx->r18, ctx->r10);
    // 0x808000B8: b           L_808000D4
    // 0x808000BC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_808000D4;
    // 0x808000BC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x808000C0: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
L_808000C4:
    // 0x808000C4: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x808000C8: bne         $at, $zero, L_80800050
    if (ctx->r1 != 0) {
        // 0x808000CC: addu        $s1, $s1, $t3
        ctx->r17 = ADD32(ctx->r17, ctx->r11);
            goto L_80800050;
    }
    // 0x808000CC: addu        $s1, $s1, $t3
    ctx->r17 = ADD32(ctx->r17, ctx->r11);
L_808000D0:
    // 0x808000D0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_808000D4:
    // 0x808000D4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000D8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x808000DC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808000E0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x808000E4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x808000E8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x808000EC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x808000F0: jr          $ra
    // 0x808000F4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x808000F4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _sucoaster_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A138: syscall     829
    recomp_syscall_handler(rdram, ctx, 0x8008A138);
    return;
    // 0x8008A13C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80801C44_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C44: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801C48: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80801C4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801C50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801C54: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80801C58: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801C5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801C60: jal         0x80100094
    // 0x80801C64: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801C64: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x80801C68: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801C6C: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80801C70: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80801C74: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x80801C78: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80801C7C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80801C80: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80801C84: bne         $a0, $zero, L_80801CB0
    if (ctx->r4 != 0) {
        // 0x80801C88: swc1        $f10, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
            goto L_80801CB0;
    }
    // 0x80801C88: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80801C8C: lwc1        $f14, 0x18($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80801C90: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80801C94: jal         0x800F1DCC
    // 0x80801C98: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    func_800F1DCC(rdram, ctx);
        goto after_1;
    // 0x80801C98: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80801C9C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80801CA0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801CA4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80801CA8: mul.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80801CAC: nop

L_80801CB0:
    // 0x80801CB0: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80801CB4: add.s       $f12, $f18, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x80801CB8: swc1        $f12, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f12.u32l;
    // 0x80801CBC: jal         0x800F1DCC
    // 0x80801CC0: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    func_800F1DCC(rdram, ctx);
        goto after_2;
    // 0x80801CC0: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    after_2:
    // 0x80801CC4: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80801CC8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CD0: jal         0x80801A4C
    // 0x80801CD4: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    func_80801A4C_chdragonbrothers(rdram, ctx);
        goto after_3;
    // 0x80801CD4: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    after_3:
    // 0x80801CD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801CDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801CE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801CE4: jr          $ra
    // 0x80801CE8: nop

    return;
    // 0x80801CE8: nop

;}
RECOMP_FUNC void func_808002A8_ch2dbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808002B8: beq         $a1, $at, L_808002F0
    if (ctx->r5 == ctx->r1) {
        // 0x808002BC: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_808002F0;
    }
    // 0x808002BC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808002C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808002C4: beq         $a1, $at, L_808002F0
    if (ctx->r5 == ctx->r1) {
        // 0x808002C8: addiu       $at, $zero, 0x38
        ctx->r1 = ADD32(0, 0X38);
            goto L_808002F0;
    }
    // 0x808002C8: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x808002CC: beq         $a1, $at, L_80800390
    if (ctx->r5 == ctx->r1) {
        // 0x808002D0: addiu       $at, $zero, 0x42
        ctx->r1 = ADD32(0, 0X42);
            goto L_80800390;
    }
    // 0x808002D0: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x808002D4: beq         $a1, $at, L_80800348
    if (ctx->r5 == ctx->r1) {
        // 0x808002D8: addiu       $v0, $sp, 0x20
        ctx->r2 = ADD32(ctx->r29, 0X20);
            goto L_80800348;
    }
    // 0x808002D8: addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
    // 0x808002DC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808002E0: beq         $a1, $at, L_8080035C
    if (ctx->r5 == ctx->r1) {
        // 0x808002E4: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_8080035C;
    }
    // 0x808002E4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808002E8: b           L_808003A4
    // 0x808002EC: nop

        goto L_808003A4;
    // 0x808002EC: nop

L_808002F0:
    // 0x808002F0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x808002F4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808002F8: jal         0x8008A1A0
    // 0x808002FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _sucoaster_entrypoint_21(rdram, ctx);
        goto after_0;
    // 0x808002FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800300: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800304: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800308: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x8080030C: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x80800310: bltzl       $t8, L_808003B4
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800314: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_808003B4;
    }
    goto skip_0;
    // 0x80800314: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x80800318: lw          $t9, 0x64($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X64);
    // 0x8080031C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80800320: bgez        $t1, L_80800338
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800324: nop
    
            goto L_80800338;
    }
    // 0x80800324: nop

    // 0x80800328: jal         0x808004A8
    // 0x8080032C: nop

    func_808004A8_ch2dbaddy(rdram, ctx);
        goto after_1;
    // 0x8080032C: nop

    after_1:
    // 0x80800330: b           L_808003B4
    // 0x80800334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003B4;
    // 0x80800334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800338:
    // 0x80800338: jal         0x808004F4
    // 0x8080033C: nop

    func_808004F4_ch2dbaddy(rdram, ctx);
        goto after_2;
    // 0x8080033C: nop

    after_2:
    // 0x80800340: b           L_808003B4
    // 0x80800344: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003B4;
    // 0x80800344: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800348:
    // 0x80800348: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x8080034C: jal         0x80800564
    // 0x80800350: lbu         $a2, 0x2($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X2);
    func_80800564_ch2dbaddy(rdram, ctx);
        goto after_3;
    // 0x80800350: lbu         $a2, 0x2($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X2);
    after_3:
    // 0x80800354: b           L_808003B0
    // 0x80800358: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_808003B0;
    // 0x80800358: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8080035C:
    // 0x8080035C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800360: jal         0x8008A110
    // 0x80800364: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    _sucoaster_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800364: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_4:
    // 0x80800368: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080036C: lhu         $a1, 0x6($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X6);
    // 0x80800370: jal         0x801032B0
    // 0x80800374: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_801032B0(rdram, ctx);
        goto after_5;
    // 0x80800374: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80800378: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080037C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800380: jal         0x8008A1A0
    // 0x80800384: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _sucoaster_entrypoint_21(rdram, ctx);
        goto after_6;
    // 0x80800384: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x80800388: b           L_808003B0
    // 0x8080038C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_808003B0;
    // 0x8080038C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800390:
    // 0x80800390: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1356, 0XA3C) << 16);
    // 0x80800394: jal         0x80101074
    // 0x80800398: addiu       $a0, $a0, 0xA3C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1356, 0XA3C));
    func_80101074(rdram, ctx);
        goto after_7;
    // 0x80800398: addiu       $a0, $a0, 0xA3C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1356, 0XA3C));
    after_7:
    // 0x8080039C: b           L_808003B4
    // 0x808003A0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_808003B4;
    // 0x808003A0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_808003A4:
    // 0x808003A4: jal         0x8008A1A0
    // 0x808003A8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    _sucoaster_entrypoint_21(rdram, ctx);
        goto after_8;
    // 0x808003A8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_8:
    // 0x808003AC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_808003B0:
    // 0x808003B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_808003B4:
    // 0x808003B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003BC: jr          $ra
    // 0x808003C0: nop

    return;
    // 0x808003C0: nop

;}
RECOMP_FUNC void func_8080222C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080222C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80802230: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80802234: mtc1        $a2, $f26
    ctx->f26.u32l = ctx->r6;
    // 0x80802238: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8080223C: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x80802240: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80802244: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80802248: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x8080224C: mov.s       $f28, $f14
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 14);
    ctx->f28.fl = ctx->f14.fl;
    // 0x80802250: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x80802254: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80802258: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8080225C: jal         0x800D8FEC
    // 0x80802260: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_800D8FEC(rdram, ctx);
        goto after_0;
    // 0x80802260: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x80802264: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // 0x80802268: multu       $v0, $s1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080226C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA450) << 16);
    // 0x80802270: mflo        $t6
    ctx->r14 = lo;
    // 0x80802274: blez        $t6, L_808022BC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80802278: nop
    
            goto L_808022BC;
    }
    // 0x80802278: nop

    // 0x8080227C: lwc1        $f22, -0x5BB0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA450));
    // 0x80802280: sub.s       $f4, $f28, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f28.fl - ctx->f20.fl;
L_80802284:
    // 0x80802284: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    // 0x80802288: mul.s       $f12, $f4, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8080228C: jal         0x800F0DC0
    // 0x80802290: nop

    func_800F0DC0(rdram, ctx);
        goto after_1;
    // 0x80802290: nop

    after_1:
    // 0x80802294: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80802298: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8080229C: jal         0x800D8FEC
    // 0x808022A0: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    func_800D8FEC(rdram, ctx);
        goto after_2;
    // 0x808022A0: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    after_2:
    // 0x808022A4: multu       $v0, $s1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808022A8: mflo        $t7
    ctx->r15 = lo;
    // 0x808022AC: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x808022B0: bnel        $at, $zero, L_80802284
    if (ctx->r1 != 0) {
        // 0x808022B4: sub.s       $f4, $f28, $f20
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f28.fl - ctx->f20.fl;
            goto L_80802284;
    }
    goto skip_0;
    // 0x808022B4: sub.s       $f4, $f28, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f28.fl - ctx->f20.fl;
    skip_0:
    // 0x808022B8: swc1        $f24, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f24.u32l;
L_808022BC:
    // 0x808022BC: jal         0x800F2100
    // 0x808022C0: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    mlAbsF(rdram, ctx);
        goto after_3;
    // 0x808022C0: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    after_3:
    // 0x808022C4: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA454) << 16);
    // 0x808022C8: lwc1        $f6, -0x5BAC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA454));
    // 0x808022CC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x808022D0: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x808022D4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808022D8: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x808022DC: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x808022E0: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x808022E4: bc1f        L_808022F0
    if (!c1cs) {
        // 0x808022E8: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_808022F0;
    }
    // 0x808022E8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x808022EC: mov.s       $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    ctx->f20.fl = ctx->f28.fl;
L_808022F0:
    // 0x808022F0: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x808022F4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808022F8: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x808022FC: jr          $ra
    // 0x80802300: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80802300: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void babounce_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080004C: jal         0x80084F80
    // 0x80800050: nop

    _bareact_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800050: nop

    after_0:
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800058: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x8080005C: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80800060: jr          $ra
    // 0x80800064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8080036C_suautobaddies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080036C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800370: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800374: jal         0x800EA05C
    // 0x80800378: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800378: nop

    after_0:
    // 0x8080037C: jal         0x800DB9B0
    // 0x80800380: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800DB9B0(rdram, ctx);
        goto after_1;
    // 0x80800380: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800384: bne         $v0, $zero, L_808003CC
    if (ctx->r2 != 0) {
        // 0x80800388: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_808003CC;
    }
    // 0x80800388: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080038C: addiu       $at, $zero, 0x154
    ctx->r1 = ADD32(0, 0X154);
    // 0x80800390: beq         $v1, $at, L_808003B0
    if (ctx->r3 == ctx->r1) {
        // 0x80800394: addiu       $at, $zero, 0xCA
        ctx->r1 = ADD32(0, 0XCA);
            goto L_808003B0;
    }
    // 0x80800394: addiu       $at, $zero, 0xCA
    ctx->r1 = ADD32(0, 0XCA);
    // 0x80800398: beq         $v1, $at, L_808003B0
    if (ctx->r3 == ctx->r1) {
        // 0x8080039C: nop
    
            goto L_808003B0;
    }
    // 0x8080039C: nop

    // 0x808003A0: jal         0x800DA298
    // 0x808003A4: addiu       $a0, $zero, 0x6E7
    ctx->r4 = ADD32(0, 0X6E7);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x808003A4: addiu       $a0, $zero, 0x6E7
    ctx->r4 = ADD32(0, 0X6E7);
    after_2:
    // 0x808003A8: beql        $v0, $zero, L_808003D0
    if (ctx->r2 == 0) {
        // 0x808003AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808003D0;
    }
    goto skip_0;
    // 0x808003AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_808003B0:
    // 0x808003B0: jal         0x800DA524
    // 0x808003B4: addiu       $a0, $zero, 0x6E7
    ctx->r4 = ADD32(0, 0X6E7);
    func_800DA524(rdram, ctx);
        goto after_3;
    // 0x808003B4: addiu       $a0, $zero, 0x6E7
    ctx->r4 = ADD32(0, 0X6E7);
    after_3:
    // 0x808003B8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808003BC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808003C0: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x808003C4: jal         0x800C9DAC
    // 0x808003C8: addiu       $a1, $a1, -0x6040
    ctx->r5 = ADD32(ctx->r5, -0X6040);
    func_800C9DAC(rdram, ctx);
        goto after_4;
    // 0x808003C8: addiu       $a1, $a1, -0x6040
    ctx->r5 = ADD32(ctx->r5, -0X6040);
    after_4:
L_808003CC:
    // 0x808003CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003D0:
    // 0x808003D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003D4: jr          $ra
    // 0x808003D8: nop

    return;
    // 0x808003D8: nop

;}
RECOMP_FUNC void func_808047EC_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808047EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808047F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808047F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808047F8: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x808047FC: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x80804800: addiu       $a0, $v0, 0x12C
    ctx->r4 = ADD32(ctx->r2, 0X12C);
    // 0x80804804: jal         0x8002D6E0
    // 0x80804808: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _bzero(rdram, ctx);
        goto after_0;
    // 0x80804808: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8080480C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80804810: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x80804814: jal         0x8002D6E0
    // 0x80804818: addiu       $a0, $a0, 0x164
    ctx->r4 = ADD32(ctx->r4, 0X164);
    _bzero(rdram, ctx);
        goto after_1;
    // 0x80804818: addiu       $a0, $a0, 0x164
    ctx->r4 = ADD32(ctx->r4, 0X164);
    after_1:
    // 0x8080481C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80804820: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80804824: jal         0x80804848
    // 0x80804828: lw          $a1, 0xC($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC);
    func_80804848_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80804828: lw          $a1, 0xC($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC);
    after_2:
    // 0x8080482C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804830: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80804834: jr          $ra
    // 0x80804838: nop

    return;
    // 0x80804838: nop

;}
RECOMP_FUNC void _badata_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084680: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x80084680);
    return;
    // 0x80084684: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void bsthrow_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800200: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800204: jal         0x8009E6EC
    // 0x80800208: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80800208: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080020C: addiu       $t6, $v0, -0x12
    ctx->r14 = ADD32(ctx->r2, -0X12);
    // 0x80800210: sltiu       $at, $t6, 0x14
    ctx->r1 = ctx->r14 < 0X14 ? 1 : 0;
    // 0x80800214: beq         $at, $zero, L_8080027C
    if (ctx->r1 == 0) {
        // 0x80800218: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080027C;
    }
    // 0x80800218: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080021C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800220: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(396, 0X2A0) << 16);
    // 0x80800224: addu        $at, $at, $t6
    gpr jr_addend_8080022C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800228: lw          $t6, 0x2A0($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(396, 0X2A0));
    // 0x8080022C: jr          $t6
    // 0x80800230: nop

    switch (jr_addend_8080022C >> 2) {
        case 0: goto L_80800234; break;
        case 1: goto L_8080027C; break;
        case 2: goto L_8080027C; break;
        case 3: goto L_8080026C; break;
        case 4: goto L_8080027C; break;
        case 5: goto L_8080027C; break;
        case 6: goto L_8080027C; break;
        case 7: goto L_8080027C; break;
        case 8: goto L_8080027C; break;
        case 9: goto L_8080027C; break;
        case 10: goto L_8080026C; break;
        case 11: goto L_8080026C; break;
        case 12: goto L_8080026C; break;
        case 13: goto L_8080027C; break;
        case 14: goto L_8080027C; break;
        case 15: goto L_8080027C; break;
        case 16: goto L_8080027C; break;
        case 17: goto L_8080027C; break;
        case 18: goto L_8080027C; break;
        case 19: goto L_8080026C; break;
        default: switch_error(__func__, 0x8080022C, 0x808002A0);
    }
    // 0x80800230: nop

L_80800234:
    // 0x80800234: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x80800238: bne         $t7, $zero, L_8080025C
    if (ctx->r15 != 0) {
        // 0x8080023C: nop
    
            goto L_8080025C;
    }
    // 0x8080023C: nop

    // 0x80800240: jal         0x8008E9AC
    // 0x80800244: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008E9AC(rdram, ctx);
        goto after_1;
    // 0x80800244: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800248: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080024C: jal         0x8008F6B8
    // 0x80800250: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8008F6B8(rdram, ctx);
        goto after_2;
    // 0x80800250: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80800254: b           L_80800288
    // 0x80800258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800288;
    // 0x80800258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080025C:
    // 0x8080025C: jal         0x8009E830
    // 0x80800260: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E830(rdram, ctx);
        goto after_3;
    // 0x80800260: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800264: b           L_80800288
    // 0x80800268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800288;
    // 0x80800268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080026C:
    // 0x8080026C: jal         0x8009E830
    // 0x80800270: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E830(rdram, ctx);
        goto after_4;
    // 0x80800270: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800274: b           L_80800288
    // 0x80800278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800288;
    // 0x80800278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080027C:
    // 0x8080027C: jal         0x80099B94
    // 0x80800280: nop

    func_80099B94(rdram, ctx);
        goto after_5;
    // 0x80800280: nop

    after_5:
    // 0x80800284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800288:
    // 0x80800288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080028C: jr          $ra
    // 0x80800290: nop

    return;
    // 0x80800290: nop

    // 0x80800294: nop

    // 0x80800298: nop

    // 0x8080029C: nop

;}
RECOMP_FUNC void func_80025084(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025084: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80025088: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002508C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80025090: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80025094: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80025098: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002509C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800250A0: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x800250A4: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800250A8: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x800250AC: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800250B0: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800250B4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800250B8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800250BC: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x800250C0: beq         $t1, $zero, L_8002517C
    if (ctx->r9 == 0) {
        // 0x800250C4: nop
    
            goto L_8002517C;
    }
    // 0x800250C4: nop

L_800250C8:
    // 0x800250C8: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800250CC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800250D0: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x800250D4: srlv        $t5, $t3, $t4
    ctx->r13 = S32(U32(ctx->r11) >> (ctx->r12 & 31));
    // 0x800250D8: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x800250DC: beq         $t6, $zero, L_80025158
    if (ctx->r14 == 0) {
        // 0x800250E0: nop
    
            goto L_80025158;
    }
    // 0x800250E0: nop

    // 0x800250E4: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800250E8: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x800250EC: beq         $t8, $zero, L_80025114
    if (ctx->r24 == 0) {
        // 0x800250F0: nop
    
            goto L_80025114;
    }
    // 0x800250F0: nop

    // 0x800250F4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800250F8: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800250FC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80025100: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80025104: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80025108: lw          $t3, 0x158($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X158);
    // 0x8002510C: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x80025110: sw          $t5, 0x158($t2)
    MEM_W(0X158, ctx->r10) = ctx->r13;
L_80025114:
    // 0x80025114: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80025118: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8002511C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80025120: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80025124: addu        $t0, $t6, $t8
    ctx->r8 = ADD32(ctx->r14, ctx->r24);
    // 0x80025128: lw          $t9, 0x158($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X158);
    // 0x8002512C: sltu        $at, $t9, $t1
    ctx->r1 = ctx->r25 < ctx->r9 ? 1 : 0;
    // 0x80025130: beq         $at, $zero, L_80025158
    if (ctx->r1 == 0) {
        // 0x80025134: nop
    
            goto L_80025158;
    }
    // 0x80025134: nop

    // 0x80025138: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8002513C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80025140: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80025144: addu        $t2, $t3, $t5
    ctx->r10 = ADD32(ctx->r11, ctx->r13);
    // 0x80025148: lw          $t7, 0x158($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X158);
    // 0x8002514C: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80025150: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80025154: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
L_80025158:
    // 0x80025158: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8002515C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80025160: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x80025164: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80025168: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8002516C: lw          $t4, 0x4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X4);
    // 0x80025170: sltu        $at, $t0, $t4
    ctx->r1 = ctx->r8 < ctx->r12 ? 1 : 0;
    // 0x80025174: bne         $at, $zero, L_800250C8
    if (ctx->r1 != 0) {
        // 0x80025178: nop
    
            goto L_800250C8;
    }
    // 0x80025178: nop

L_8002517C:
    // 0x8002517C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80025180: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80025184: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80025188: jal         0x80025224
    // 0x8002518C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    func_80025224(rdram, ctx);
        goto after_0;
    // 0x8002518C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x80025190: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80025194: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80025198: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
    // 0x8002519C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800251A0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800251A4: lw          $t7, 0xC($t2)
    ctx->r15 = MEM_W(ctx->r10, 0XC);
    // 0x800251A8: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800251AC: sw          $t8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r24;
    // 0x800251B0: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800251B4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800251B8: sw          $t9, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r25;
    // 0x800251BC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800251C0: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x800251C4: lh          $t4, 0x0($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X0);
    // 0x800251C8: beq         $t4, $at, L_800251FC
    if (ctx->r12 == ctx->r1) {
        // 0x800251CC: nop
    
            goto L_800251FC;
    }
    // 0x800251CC: nop

    // 0x800251D0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800251D4: jal         0x80025DE4
    // 0x800251D8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80025DE4(rdram, ctx);
        goto after_1;
    // 0x800251D8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x800251DC: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800251E0: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800251E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800251E8: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800251EC: addu        $t6, $t3, $t7
    ctx->r14 = ADD32(ctx->r11, ctx->r15);
    // 0x800251F0: lw          $t8, 0x158($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X158);
    // 0x800251F4: addu        $t2, $t8, $s0
    ctx->r10 = ADD32(ctx->r24, ctx->r16);
    // 0x800251F8: sw          $t2, 0x158($t6)
    MEM_W(0X158, ctx->r14) = ctx->r10;
L_800251FC:
    // 0x800251FC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80025200: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80025204: sw          $t9, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r25;
    // 0x80025208: b           L_80025210
    // 0x8002520C: nop

        goto L_80025210;
    // 0x8002520C: nop

L_80025210:
    // 0x80025210: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80025214: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80025218: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8002521C: jr          $ra
    // 0x80025220: nop

    return;
    // 0x80025220: nop

;}
RECOMP_FUNC void _chfaircoinbox_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087270: syscall     541
    recomp_syscall_handler(rdram, ctx, 0x80087270);
    return;
    // 0x80087274: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80025820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025820: addiu       $sp, $sp, -0x208
    ctx->r29 = ADD32(ctx->r29, -0X208);
    // 0x80025824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025828: sw          $a0, 0x208($sp)
    MEM_W(0X208, ctx->r29) = ctx->r4;
    // 0x8002582C: sw          $a1, 0x20C($sp)
    MEM_W(0X20C, ctx->r29) = ctx->r5;
    // 0x80025830: sw          $a2, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r6;
    // 0x80025834: lw          $t6, 0x208($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X208);
    // 0x80025838: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8002583C: jal         0x80024EE0
    // 0x80025840: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    func_80024EE0(rdram, ctx);
        goto after_0;
    // 0x80025840: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_0:
L_80025844:
    // 0x80025844: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80025848: lw          $t8, 0x20C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20C);
    // 0x8002584C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80025850: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80025854: lw          $t0, 0x20C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20C);
    // 0x80025858: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8002585C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80025860: lw          $t2, 0x20C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20C);
    // 0x80025864: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x80025868: lw          $t3, 0x208($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X208);
    // 0x8002586C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80025870: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80025874: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80025878: beq         $t5, $zero, L_80025928
    if (ctx->r13 == 0) {
        // 0x8002587C: nop
    
            goto L_80025928;
    }
    // 0x8002587C: nop

L_80025880:
    // 0x80025880: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80025884: lw          $t9, 0x20C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20C);
    // 0x80025888: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002588C: addu        $t8, $sp, $t7
    ctx->r24 = ADD32(ctx->r29, ctx->r15);
    // 0x80025890: lw          $t8, 0x38($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X38);
    // 0x80025894: addu        $t0, $t9, $t7
    ctx->r8 = ADD32(ctx->r25, ctx->r15);
    // 0x80025898: sw          $t8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r24;
    // 0x8002589C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800258A0: lw          $t4, 0x20C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20C);
    // 0x800258A4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800258A8: addu        $t3, $sp, $t2
    ctx->r11 = ADD32(ctx->r29, ctx->r10);
    // 0x800258AC: lw          $t3, 0xB8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XB8);
    // 0x800258B0: addu        $t5, $t4, $t2
    ctx->r13 = ADD32(ctx->r12, ctx->r10);
    // 0x800258B4: sw          $t3, 0x8C($t5)
    MEM_W(0X8C, ctx->r13) = ctx->r11;
    // 0x800258B8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800258BC: lw          $t7, 0x20C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20C);
    // 0x800258C0: addu        $t9, $sp, $t6
    ctx->r25 = ADD32(ctx->r29, ctx->r14);
    // 0x800258C4: lbu         $t9, 0x138($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X138);
    // 0x800258C8: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800258CC: sb          $t9, 0x10C($t8)
    MEM_B(0X10C, ctx->r24) = ctx->r25;
    // 0x800258D0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800258D4: lw          $t4, 0x20C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20C);
    // 0x800258D8: addu        $t1, $sp, $t0
    ctx->r9 = ADD32(ctx->r29, ctx->r8);
    // 0x800258DC: lbu         $t1, 0x158($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X158);
    // 0x800258E0: addu        $t2, $t4, $t0
    ctx->r10 = ADD32(ctx->r12, ctx->r8);
    // 0x800258E4: sb          $t1, 0x12C($t2)
    MEM_B(0X12C, ctx->r10) = ctx->r9;
    // 0x800258E8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800258EC: lw          $t6, 0x20C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20C);
    // 0x800258F0: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x800258F4: addu        $t7, $sp, $t5
    ctx->r15 = ADD32(ctx->r29, ctx->r13);
    // 0x800258F8: lw          $t7, 0x178($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X178);
    // 0x800258FC: addu        $t9, $t6, $t5
    ctx->r25 = ADD32(ctx->r14, ctx->r13);
    // 0x80025900: sw          $t7, 0x14C($t9)
    MEM_W(0X14C, ctx->r25) = ctx->r15;
    // 0x80025904: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80025908: lw          $t0, 0x208($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X208);
    // 0x8002590C: addiu       $t4, $t8, 0x1
    ctx->r12 = ADD32(ctx->r24, 0X1);
    // 0x80025910: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80025914: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80025918: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8002591C: sltu        $at, $t4, $t2
    ctx->r1 = ctx->r12 < ctx->r10 ? 1 : 0;
    // 0x80025920: bne         $at, $zero, L_80025880
    if (ctx->r1 != 0) {
        // 0x80025924: nop
    
            goto L_80025880;
    }
    // 0x80025924: nop

L_80025928:
    // 0x80025928: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8002592C: addiu       $a1, $sp, 0x1F8
    ctx->r5 = ADD32(ctx->r29, 0X1F8);
    // 0x80025930: jal         0x80025084
    // 0x80025934: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80025084(rdram, ctx);
        goto after_1;
    // 0x80025934: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80025938: lh          $t3, 0x1F8($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X1F8);
    // 0x8002593C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80025940: bne         $t3, $at, L_80025950
    if (ctx->r11 != ctx->r1) {
        // 0x80025944: nop
    
            goto L_80025950;
    }
    // 0x80025944: nop

    // 0x80025948: b           L_80025964
    // 0x8002594C: nop

        goto L_80025964;
    // 0x8002594C: nop

L_80025950:
    // 0x80025950: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80025954: lw          $t5, 0x210($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X210);
    // 0x80025958: sltu        $at, $t6, $t5
    ctx->r1 = ctx->r14 < ctx->r13 ? 1 : 0;
    // 0x8002595C: bne         $at, $zero, L_80025844
    if (ctx->r1 != 0) {
        // 0x80025960: nop
    
            goto L_80025844;
    }
    // 0x80025960: nop

L_80025964:
    // 0x80025964: b           L_8002596C
    // 0x80025968: nop

        goto L_8002596C;
    // 0x80025968: nop

L_8002596C:
    // 0x8002596C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025970: addiu       $sp, $sp, 0x208
    ctx->r29 = ADD32(ctx->r29, 0X208);
    // 0x80025974: jr          $ra
    // 0x80025978: nop

    return;
    // 0x80025978: nop

;}
RECOMP_FUNC void func_8080032C_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080032C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800330: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800334: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800338: jal         0x80092C90
    // 0x8080033C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80092C90(rdram, ctx);
        goto after_0;
    // 0x8080033C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80800340: jal         0x800B5BE4
    // 0x80800344: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800B5BE4(rdram, ctx);
        goto after_1;
    // 0x80800344: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_1:
    // 0x80800348: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(427, 0X1C40) << 16);
    // 0x8080034C: addiu       $t6, $t6, 0x1C40
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(427, 0X1C40));
    // 0x80800350: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800354: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800358: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080035C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800360: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800364: jal         0x800BABB8
    // 0x80800368: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80800368: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x8080036C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800370: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(427, 0X1A70) << 16);
    // 0x80800374: jal         0x800DC178
    // 0x80800378: lwc1        $f14, 0x1A70($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(427, 0X1A70));
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80800378: lwc1        $f14, 0x1A70($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(427, 0X1A70));
    after_3:
    // 0x8080037C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800380: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800384: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800388: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080038C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80800390: nop

    // 0x80800394: sll         $t8, $a3, 16
    ctx->r24 = S32(ctx->r7 << 16);
    // 0x80800398: jal         0x800BA77C
    // 0x8080039C: sra         $a3, $t8, 16
    ctx->r7 = S32(SIGNED(ctx->r24) >> 16);
    func_800BA77C(rdram, ctx);
        goto after_4;
    // 0x8080039C: sra         $a3, $t8, 16
    ctx->r7 = S32(SIGNED(ctx->r24) >> 16);
    after_4:
    // 0x808003A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808003A4: jal         0x800BA22C
    // 0x808003A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_5;
    // 0x808003A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808003AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003B0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808003B4: jr          $ra
    // 0x808003B8: nop

    return;
    // 0x808003B8: nop

;}
RECOMP_FUNC void _gczoombox_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B50: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087B50);
    return;
    // 0x80087B54: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_800FFBE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FFBE4: jr          $ra
    // 0x800FFBE8: nop

    return;
    // 0x800FFBE8: nop

;}
RECOMP_FUNC void func_800E88E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E88E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E88E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E88EC: jal         0x800A89F8
    // 0x800E88F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A89F8(rdram, ctx);
        goto after_0;
    // 0x800E88F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800E88F4: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    // 0x800E88F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800E88FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E8900: jal         0x800E8918
    // 0x800E8904: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800E8918(rdram, ctx);
        goto after_1;
    // 0x800E8904: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x800E8908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E890C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E8910: jr          $ra
    // 0x800E8914: nop

    return;
    // 0x800E8914: nop

;}
