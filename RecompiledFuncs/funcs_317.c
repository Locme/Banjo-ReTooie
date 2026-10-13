#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800B7C_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800B80: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800B84: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800B88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B8C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800B90: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800B94: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80800B98: jal         0x80100094
    // 0x80800B9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800B9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800BA0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800BA4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80800BA8: slti        $at, $a2, 0x97
    ctx->r1 = SIGNED(ctx->r6) < 0X97 ? 1 : 0;
    // 0x80800BAC: bne         $at, $zero, L_80800BD0
    if (ctx->r1 != 0) {
        // 0x80800BB0: addiu       $t6, $a2, -0xA
        ctx->r14 = ADD32(ctx->r6, -0XA);
            goto L_80800BD0;
    }
    // 0x80800BB0: addiu       $t6, $a2, -0xA
    ctx->r14 = ADD32(ctx->r6, -0XA);
    // 0x80800BB4: addiu       $at, $zero, 0x9F
    ctx->r1 = ADD32(0, 0X9F);
    // 0x80800BB8: beq         $a2, $at, L_80800E10
    if (ctx->r6 == ctx->r1) {
        // 0x80800BBC: addiu       $at, $zero, 0xA2
        ctx->r1 = ADD32(0, 0XA2);
            goto L_80800E10;
    }
    // 0x80800BBC: addiu       $at, $zero, 0xA2
    ctx->r1 = ADD32(0, 0XA2);
    // 0x80800BC0: beq         $a2, $at, L_80800E2C
    if (ctx->r6 == ctx->r1) {
        // 0x80800BC4: lw          $t2, 0x28($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X28);
            goto L_80800E2C;
    }
    // 0x80800BC4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80800BC8: b           L_80800F04
    // 0x80800BCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F04;
    // 0x80800BCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800BD0:
    // 0x80800BD0: slti        $at, $a2, 0x96
    ctx->r1 = SIGNED(ctx->r6) < 0X96 ? 1 : 0;
    // 0x80800BD4: bne         $at, $zero, L_80800BEC
    if (ctx->r1 != 0) {
        // 0x80800BD8: addiu       $at, $zero, 0x96
        ctx->r1 = ADD32(0, 0X96);
            goto L_80800BEC;
    }
    // 0x80800BD8: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x80800BDC: beq         $a2, $at, L_80800DD4
    if (ctx->r6 == ctx->r1) {
        // 0x80800BE0: nop
    
            goto L_80800DD4;
    }
    // 0x80800BE0: nop

    // 0x80800BE4: b           L_80800F04
    // 0x80800BE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F04;
    // 0x80800BE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800BEC:
    // 0x80800BEC: slti        $at, $a2, 0x4A
    ctx->r1 = SIGNED(ctx->r6) < 0X4A ? 1 : 0;
    // 0x80800BF0: bne         $at, $zero, L_80800C08
    if (ctx->r1 != 0) {
        // 0x80800BF4: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800C08;
    }
    // 0x80800BF4: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800BF8: beq         $a2, $at, L_80800D8C
    if (ctx->r6 == ctx->r1) {
        // 0x80800BFC: addiu       $a0, $zero, 0x377
        ctx->r4 = ADD32(0, 0X377);
            goto L_80800D8C;
    }
    // 0x80800BFC: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    // 0x80800C00: b           L_80800F04
    // 0x80800C04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F04;
    // 0x80800C04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C08:
    // 0x80800C08: sltiu       $at, $t6, 0x40
    ctx->r1 = ctx->r14 < 0X40 ? 1 : 0;
    // 0x80800C0C: beq         $at, $zero, L_80800EF8
    if (ctx->r1 == 0) {
        // 0x80800C10: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800EF8;
    }
    // 0x80800C10: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800C14: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1332, 0X2B8C) << 16);
    // 0x80800C18: addu        $at, $at, $t6
    gpr jr_addend_80800C20 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800C1C: lw          $t6, 0x2B8C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2B8C));
    // 0x80800C20: jr          $t6
    // 0x80800C24: nop

    switch (jr_addend_80800C20 >> 2) {
        case 0: goto L_80800D14; break;
        case 1: goto L_80800CB4; break;
        case 2: goto L_80800EF8; break;
        case 3: goto L_80800EF8; break;
        case 4: goto L_80800EF8; break;
        case 5: goto L_80800EF8; break;
        case 6: goto L_80800EF8; break;
        case 7: goto L_80800EF8; break;
        case 8: goto L_80800EF8; break;
        case 9: goto L_80800EF8; break;
        case 10: goto L_80800EF8; break;
        case 11: goto L_80800EF8; break;
        case 12: goto L_80800EF8; break;
        case 13: goto L_80800EF8; break;
        case 14: goto L_80800EF8; break;
        case 15: goto L_80800EF8; break;
        case 16: goto L_80800EF8; break;
        case 17: goto L_80800EF8; break;
        case 18: goto L_80800EF8; break;
        case 19: goto L_80800EF8; break;
        case 20: goto L_80800EF8; break;
        case 21: goto L_80800EE0; break;
        case 22: goto L_80800EF8; break;
        case 23: goto L_80800EF8; break;
        case 24: goto L_80800EF8; break;
        case 25: goto L_80800EF8; break;
        case 26: goto L_80800EF8; break;
        case 27: goto L_80800EF8; break;
        case 28: goto L_80800EF8; break;
        case 29: goto L_80800EF8; break;
        case 30: goto L_80800EF8; break;
        case 31: goto L_80800EF8; break;
        case 32: goto L_80800EF8; break;
        case 33: goto L_80800EF8; break;
        case 34: goto L_80800EF8; break;
        case 35: goto L_80800EF8; break;
        case 36: goto L_80800C98; break;
        case 37: goto L_80800EF8; break;
        case 38: goto L_80800EF8; break;
        case 39: goto L_80800EF8; break;
        case 40: goto L_80800D6C; break;
        case 41: goto L_80800EF8; break;
        case 42: goto L_80800EF8; break;
        case 43: goto L_80800EF8; break;
        case 44: goto L_80800EF8; break;
        case 45: goto L_80800EF8; break;
        case 46: goto L_80800EF8; break;
        case 47: goto L_80800EF8; break;
        case 48: goto L_80800EF8; break;
        case 49: goto L_80800EF8; break;
        case 50: goto L_80800EF8; break;
        case 51: goto L_80800C28; break;
        case 52: goto L_80800EF8; break;
        case 53: goto L_80800EF8; break;
        case 54: goto L_80800CFC; break;
        case 55: goto L_80800EF8; break;
        case 56: goto L_80800EF8; break;
        case 57: goto L_80800EF8; break;
        case 58: goto L_80800EF8; break;
        case 59: goto L_80800EF8; break;
        case 60: goto L_80800EF8; break;
        case 61: goto L_80800EF8; break;
        case 62: goto L_80800EF8; break;
        case 63: goto L_80800D3C; break;
        default: switch_error(__func__, 0x80800C20, 0x80802B8C);
    }
    // 0x80800C24: nop

L_80800C28:
    // 0x80800C28: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800C2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800C30: beq         $a0, $zero, L_80800C58
    if (ctx->r4 == 0) {
        // 0x80800C34: nop
    
            goto L_80800C58;
    }
    // 0x80800C34: nop

    // 0x80800C38: beq         $a0, $at, L_80800C68
    if (ctx->r4 == ctx->r1) {
        // 0x80800C3C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800C68;
    }
    // 0x80800C3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800C40: beq         $a0, $at, L_80800C78
    if (ctx->r4 == ctx->r1) {
        // 0x80800C44: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800C78;
    }
    // 0x80800C44: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800C48: beq         $a0, $at, L_80800C88
    if (ctx->r4 == ctx->r1) {
        // 0x80800C4C: nop
    
            goto L_80800C88;
    }
    // 0x80800C4C: nop

    // 0x80800C50: b           L_80800F04
    // 0x80800C54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800C54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C58:
    // 0x80800C58: jal         0x80801D0C
    // 0x80800C5C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80801D0C_changlerboss(rdram, ctx);
        goto after_1;
    // 0x80800C5C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800C60: b           L_80800F04
    // 0x80800C64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800C64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C68:
    // 0x80800C68: jal         0x80801E3C
    // 0x80800C6C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80801E3C_changlerboss(rdram, ctx);
        goto after_2;
    // 0x80800C6C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80800C70: b           L_80800F04
    // 0x80800C74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800C74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C78:
    // 0x80800C78: jal         0x80801F54
    // 0x80800C7C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80801F54_changlerboss(rdram, ctx);
        goto after_3;
    // 0x80800C7C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80800C80: b           L_80800F04
    // 0x80800C84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800C84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C88:
    // 0x80800C88: jal         0x80802108
    // 0x80800C8C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80802108_changlerboss(rdram, ctx);
        goto after_4;
    // 0x80800C8C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80800C90: b           L_80800F04
    // 0x80800C94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800C94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C98:
    // 0x80800C98: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x80800C9C: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800CA0: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800CA4: jal         0x8080170C
    // 0x80800CA8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8080170C_changlerboss(rdram, ctx);
        goto after_5;
    // 0x80800CA8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80800CAC: b           L_80800F04
    // 0x80800CB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800CB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CB4:
    // 0x80800CB4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800CB8: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80800CBC: beq         $a0, $at, L_80800CF0
    if (ctx->r4 == ctx->r1) {
        // 0x80800CC0: addiu       $at, $zero, 0x19
        ctx->r1 = ADD32(0, 0X19);
            goto L_80800CF0;
    }
    // 0x80800CC0: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80800CC4: bne         $a0, $at, L_80800CF4
    if (ctx->r4 != ctx->r1) {
        // 0x80800CC8: addiu       $a1, $zero, 0x7
        ctx->r5 = ADD32(0, 0X7);
            goto L_80800CF4;
    }
    // 0x80800CC8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800CCC: addiu       $a0, $zero, 0x46C
    ctx->r4 = ADD32(0, 0X46C);
    // 0x80800CD0: jal         0x80101180
    // 0x80800CD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_6;
    // 0x80800CD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80800CD8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800CDC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80800CE0: jal         0x808021E4
    // 0x80800CE4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_808021E4_changlerboss(rdram, ctx);
        goto after_7;
    // 0x80800CE4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_7:
    // 0x80800CE8: b           L_80800F04
    // 0x80800CEC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800F04;
    // 0x80800CEC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800CF0:
    // 0x80800CF0: sb          $zero, 0x12B($v0)
    MEM_B(0X12B, ctx->r2) = 0;
L_80800CF4:
    // 0x80800CF4: b           L_80800F04
    // 0x80800CF8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800F04;
    // 0x80800CF8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800CFC:
    // 0x80800CFC: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x80800D00: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800D04: jal         0x80801070
    // 0x80800D08: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80801070_changlerboss(rdram, ctx);
        goto after_8;
    // 0x80800D08: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_8:
    // 0x80800D0C: b           L_80800F04
    // 0x80800D10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800D10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D14:
    // 0x80800D14: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800D18: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80800D1C: lhu         $t7, 0x72($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X72);
    // 0x80800D20: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800D24: bnel        $t8, $at, L_80800F04
    if (ctx->r24 != ctx->r1) {
        // 0x80800D28: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800F04;
    }
    goto skip_0;
    // 0x80800D28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800D2C: jal         0x808012E0
    // 0x80800D30: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_9;
    // 0x80800D30: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_9:
    // 0x80800D34: b           L_80800F04
    // 0x80800D38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800D38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D3C:
    // 0x80800D3C: jal         0x800DA298
    // 0x80800D40: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x80800D40: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    after_10:
    // 0x80800D44: beq         $v0, $zero, L_80800D5C
    if (ctx->r2 == 0) {
        // 0x80800D48: nop
    
            goto L_80800D5C;
    }
    // 0x80800D48: nop

    // 0x80800D4C: jal         0x80088848
    // 0x80800D50: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_11;
    // 0x80800D50: nop

    after_11:
    // 0x80800D54: beql        $v0, $zero, L_80800F04
    if (ctx->r2 == 0) {
        // 0x80800D58: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800F04;
    }
    goto skip_1;
    // 0x80800D58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
L_80800D5C:
    // 0x80800D5C: jal         0x80801DA0
    // 0x80800D60: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80801DA0_changlerboss(rdram, ctx);
        goto after_12;
    // 0x80800D60: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_12:
    // 0x80800D64: b           L_80800F04
    // 0x80800D68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800D68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D6C:
    // 0x80800D6C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800D70: jal         0x800F54E4
    // 0x80800D74: sb          $t9, 0x12C($a3)
    MEM_B(0X12C, ctx->r7) = ctx->r25;
    func_800F54E4(rdram, ctx);
        goto after_13;
    // 0x80800D74: sb          $t9, 0x12C($a3)
    MEM_B(0X12C, ctx->r7) = ctx->r25;
    after_13:
    // 0x80800D78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D7C: jal         0x800F82D4
    // 0x80800D80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_14;
    // 0x80800D80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
    // 0x80800D84: b           L_80800F04
    // 0x80800D88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800D88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D8C:
    // 0x80800D8C: jal         0x800DA298
    // 0x80800D90: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_800DA298(rdram, ctx);
        goto after_15;
    // 0x80800D90: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_15:
    // 0x80800D94: bne         $v0, $zero, L_80800DB0
    if (ctx->r2 != 0) {
        // 0x80800D98: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_80800DB0;
    }
    // 0x80800D98: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800D9C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800DA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800DA4: jal         0x80108B04
    // 0x80800DA8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80108B04(rdram, ctx);
        goto after_16;
    // 0x80800DA8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_16:
    // 0x80800DAC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_80800DB0:
    // 0x80800DB0: lbu         $t0, 0x12A($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X12A);
    // 0x80800DB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800DB8: beql        $t0, $zero, L_80800F04
    if (ctx->r8 == 0) {
        // 0x80800DBC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800F04;
    }
    goto skip_2;
    // 0x80800DBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x80800DC0: jal         0x800FDC28
    // 0x80800DC4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_800FDC28(rdram, ctx);
        goto after_17;
    // 0x80800DC4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_17:
    // 0x80800DC8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800DCC: b           L_80800F00
    // 0x80800DD0: sb          $zero, 0x12A($a3)
    MEM_B(0X12A, ctx->r7) = 0;
        goto L_80800F00;
    // 0x80800DD0: sb          $zero, 0x12A($a3)
    MEM_B(0X12A, ctx->r7) = 0;
L_80800DD4:
    // 0x80800DD4: jal         0x800D395C
    // 0x80800DD8: nop

    func_800D395C(rdram, ctx);
        goto after_18;
    // 0x80800DD8: nop

    after_18:
    // 0x80800DDC: bne         $v0, $zero, L_80800DEC
    if (ctx->r2 != 0) {
        // 0x80800DE0: addiu       $a1, $zero, 0xCEB
        ctx->r5 = ADD32(0, 0XCEB);
            goto L_80800DEC;
    }
    // 0x80800DE0: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x80800DE4: b           L_80800F04
    // 0x80800DE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F04;
    // 0x80800DE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800DEC:
    // 0x80800DEC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80800DF0: addiu       $t1, $zero, 0xB4
    ctx->r9 = ADD32(0, 0XB4);
    // 0x80800DF4: addiu       $a2, $zero, 0x146
    ctx->r6 = ADD32(0, 0X146);
    // 0x80800DF8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80800DFC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800E00: jal         0x8008A208
    // 0x80800E04: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_19;
    // 0x80800E04: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    after_19:
    // 0x80800E08: b           L_80800F04
    // 0x80800E0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800E0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E10:
    // 0x80800E10: jal         0x800FDC28
    // 0x80800E14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_20;
    // 0x80800E14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_20:
    // 0x80800E18: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800E1C: jal         0x808012E0
    // 0x80800E20: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_21;
    // 0x80800E20: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_21:
    // 0x80800E24: b           L_80800F04
    // 0x80800E28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800E28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E2C:
    // 0x80800E2C: lw          $t3, 0x7C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X7C);
    // 0x80800E30: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    // 0x80800E34: sll         $t5, $t3, 19
    ctx->r13 = S32(ctx->r11 << 19);
    // 0x80800E38: bgez        $t5, L_80800E50
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80800E3C: nop
    
            goto L_80800E50;
    }
    // 0x80800E3C: nop

    // 0x80800E40: jal         0x800DA298
    // 0x80800E44: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_800DA298(rdram, ctx);
        goto after_22;
    // 0x80800E44: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_22:
    // 0x80800E48: beq         $v0, $zero, L_80800E58
    if (ctx->r2 == 0) {
        // 0x80800E4C: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_80800E58;
    }
    // 0x80800E4C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_80800E50:
    // 0x80800E50: b           L_80800F04
    // 0x80800E54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F04;
    // 0x80800E54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800E58:
    // 0x80800E58: lh          $t6, 0x92($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X92);
    // 0x80800E5C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1332, 0X30B0) << 16);
    // 0x80800E60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800E64: bne         $t6, $zero, L_80800EC4
    if (ctx->r14 != 0) {
        // 0x80800E68: addiu       $a0, $a0, 0x30B0
        ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1332, 0X30B0));
            goto L_80800EC4;
    }
    // 0x80800E68: addiu       $a0, $a0, 0x30B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1332, 0X30B0));
    // 0x80800E6C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x80800E70: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
L_80800E74:
    // 0x80800E74: lbu         $t7, 0x1B($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1B);
    // 0x80800E78: bne         $t7, $zero, L_80800EB0
    if (ctx->r15 != 0) {
        // 0x80800E7C: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_80800EB0;
    }
    // 0x80800E7C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80800E80: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x80800E84: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800E88: addu        $a1, $a3, $t8
    ctx->r5 = ADD32(ctx->r7, ctx->r24);
    // 0x80800E8C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1332, 0X30B0) << 16);
    // 0x80800E90: addiu       $a0, $a0, 0x30B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1332, 0X30B0));
    // 0x80800E94: jal         0x800EE7F8
    // 0x80800E98: addiu       $a1, $a1, 0x3C
    ctx->r5 = ADD32(ctx->r5, 0X3C);
    func_800EE7F8(rdram, ctx);
        goto after_23;
    // 0x80800E98: addiu       $a1, $a1, 0x3C
    ctx->r5 = ADD32(ctx->r5, 0X3C);
    after_23:
    // 0x80800E9C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1332, 0X30B0) << 16);
    // 0x80800EA0: jal         0x80101074
    // 0x80800EA4: addiu       $a0, $a0, 0x30B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1332, 0X30B0));
    func_80101074(rdram, ctx);
        goto after_24;
    // 0x80800EA4: addiu       $a0, $a0, 0x30B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1332, 0X30B0));
    after_24:
    // 0x80800EA8: b           L_80800F04
    // 0x80800EAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800EAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800EB0:
    // 0x80800EB0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800EB4: bne         $v0, $a0, L_80800E74
    if (ctx->r2 != ctx->r4) {
        // 0x80800EB8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80800E74;
    }
    // 0x80800EB8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800EBC: b           L_80800F04
    // 0x80800EC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F04;
    // 0x80800EC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800EC4:
    // 0x80800EC4: jal         0x800EE7F8
    // 0x80800EC8: addiu       $a1, $a3, 0x84
    ctx->r5 = ADD32(ctx->r7, 0X84);
    func_800EE7F8(rdram, ctx);
        goto after_25;
    // 0x80800EC8: addiu       $a1, $a3, 0x84
    ctx->r5 = ADD32(ctx->r7, 0X84);
    after_25:
    // 0x80800ECC: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1332, 0X30B0) << 16);
    // 0x80800ED0: jal         0x80101074
    // 0x80800ED4: addiu       $a0, $a0, 0x30B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1332, 0X30B0));
    func_80101074(rdram, ctx);
        goto after_26;
    // 0x80800ED4: addiu       $a0, $a0, 0x30B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1332, 0X30B0));
    after_26:
    // 0x80800ED8: b           L_80800F04
    // 0x80800EDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800EDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800EE0:
    // 0x80800EE0: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x80800EE4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800EE8: jal         0x80800F14
    // 0x80800EEC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80800F14_changlerboss(rdram, ctx);
        goto after_27;
    // 0x80800EEC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_27:
    // 0x80800EF0: b           L_80800F04
    // 0x80800EF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800EF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800EF8:
    // 0x80800EF8: b           L_80800F04
    // 0x80800EFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F04;
    // 0x80800EFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800F00:
    // 0x80800F00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F04:
    // 0x80800F04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800F0C: jr          $ra
    // 0x80800F10: nop

    return;
    // 0x80800F10: nop

;}
RECOMP_FUNC void func_80800FD4_chlagoonufoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FD4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800FD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800FDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800FE0: jal         0x800D8FF8
    // 0x80800FE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800FE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800FE8: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80800FEC: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800FF0: lui         $at, 0x4420
    ctx->r1 = S32(0X4420 << 16);
    // 0x80800FF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800FF8: mul.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80800FFC: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80801000: lui         $at, 0x4548
    ctx->r1 = S32(0X4548 << 16);
    // 0x80801004: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801008: lui         $at, 0x4520
    ctx->r1 = S32(0X4520 << 16);
    // 0x8080100C: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80801010: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80801014: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80801018: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8080101C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80801020: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80801024: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801028: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8080102C: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80801030: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80801034: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    // 0x80801038: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080103C: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x80801040: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    // 0x80801044: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80801048: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080104C: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80801050: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
L_80801054:
    // 0x80801054: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80801058: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8080105C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80801060: nop

    // 0x80801064: bc1f        L_80801074
    if (!c1cs) {
        // 0x80801068: nop
    
            goto L_80801074;
    }
    // 0x80801068: nop

    // 0x8080106C: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80801070: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
L_80801074:
    // 0x80801074: bne         $v1, $a0, L_80801054
    if (ctx->r3 != ctx->r4) {
        // 0x80801078: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80801054;
    }
    // 0x80801078: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080107C: jal         0x80100094
    // 0x80801080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80801080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801084: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80801088: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8080108C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80801090: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801094: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80801098: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080109C: mul.s       $f16, $f6, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808010A0: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x808010A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808010A8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(748, 0X1BB0) << 16);
    // 0x808010AC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(748, 0X1BBC) << 16);
    // 0x808010B0: addiu       $a2, $a2, 0x1BBC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(748, 0X1BBC));
    // 0x808010B4: addiu       $a1, $a1, 0x1BB0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(748, 0X1BB0));
    // 0x808010B8: add.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x808010BC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808010C0: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x808010C4: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808010C8: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x808010CC: add.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x808010D0: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    // 0x808010D4: jal         0x800F3214
    // 0x808010D8: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    func_800F3214(rdram, ctx);
        goto after_2;
    // 0x808010D8: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    after_2:
    // 0x808010DC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x808010E0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x808010E4: jal         0x800C8D4C
    // 0x808010E8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800C8D4C(rdram, ctx);
        goto after_3;
    // 0x808010E8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_3:
    // 0x808010EC: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x808010F0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x808010F4: jal         0x800C8E84
    // 0x808010F8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_800C8E84(rdram, ctx);
        goto after_4;
    // 0x808010F8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_4:
    // 0x808010FC: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80801100: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801104: srl         $t8, $v0, 10
    ctx->r24 = S32(U32(ctx->r2) >> 10);
    // 0x80801108: beq         $t8, $at, L_80801134
    if (ctx->r24 == ctx->r1) {
        // 0x8080110C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801134;
    }
    // 0x8080110C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801110: beq         $t8, $at, L_8080116C
    if (ctx->r24 == ctx->r1) {
        // 0x80801114: lwc1        $f10, 0x5C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
            goto L_8080116C;
    }
    // 0x80801114: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80801118: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080111C: beq         $t8, $at, L_808011B0
    if (ctx->r24 == ctx->r1) {
        // 0x80801120: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_808011B0;
    }
    // 0x80801120: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80801124: beq         $t8, $at, L_808011D0
    if (ctx->r24 == ctx->r1) {
        // 0x80801128: lwc1        $f4, 0x5C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
            goto L_808011D0;
    }
    // 0x80801128: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8080112C: b           L_80801208
    // 0x80801130: nop

        goto L_80801208;
    // 0x80801130: nop

L_80801134:
    // 0x80801134: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
    // 0x80801138: lhu         $t2, 0x6E($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X6E);
    // 0x8080113C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801140: addiu       $v0, $t9, -0x1
    ctx->r2 = ADD32(ctx->r25, -0X1);
    // 0x80801144: andi        $t0, $v0, 0x1FF
    ctx->r8 = ctx->r2 & 0X1FF;
    // 0x80801148: andi        $t1, $t0, 0x1FF
    ctx->r9 = ctx->r8 & 0X1FF;
    // 0x8080114C: andi        $t3, $t2, 0xFE00
    ctx->r11 = ctx->r10 & 0XFE00;
    // 0x80801150: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80801154: bne         $t0, $zero, L_80801208
    if (ctx->r8 != 0) {
        // 0x80801158: sh          $t4, 0x6E($s0)
        MEM_H(0X6E, ctx->r16) = ctx->r12;
            goto L_80801208;
    }
    // 0x80801158: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
    // 0x8080115C: jal         0x80800E80
    // 0x80801160: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800E80_chlagoonufoint(rdram, ctx);
        goto after_5;
    // 0x80801160: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80801164: b           L_80801208
    // 0x80801168: nop

        goto L_80801208;
    // 0x80801168: nop

L_8080116C:
    // 0x8080116C: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80801170: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801174: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801178: mul.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8080117C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801184: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80801188: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x8080118C: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801190: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80801194: nop

    // 0x80801198: bc1f        L_80801208
    if (!c1cs) {
        // 0x8080119C: nop
    
            goto L_80801208;
    }
    // 0x8080119C: nop

    // 0x808011A0: jal         0x80800E80
    // 0x808011A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800E80_chlagoonufoint(rdram, ctx);
        goto after_6;
    // 0x808011A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x808011A8: b           L_80801208
    // 0x808011AC: nop

        goto L_80801208;
    // 0x808011AC: nop

L_808011B0:
    // 0x808011B0: jal         0x800DA298
    // 0x808011B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x808011B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x808011B8: beq         $v0, $zero, L_80801208
    if (ctx->r2 == 0) {
        // 0x808011BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801208;
    }
    // 0x808011BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011C0: jal         0x80800E80
    // 0x808011C4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800E80_chlagoonufoint(rdram, ctx);
        goto after_8;
    // 0x808011C4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_8:
    // 0x808011C8: b           L_80801208
    // 0x808011CC: nop

        goto L_80801208;
    // 0x808011CC: nop

L_808011D0:
    // 0x808011D0: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808011D4: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808011D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011DC: mul.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x808011E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808011E4: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x808011E8: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
    // 0x808011EC: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808011F0: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x808011F4: nop

    // 0x808011F8: bc1f        L_80801208
    if (!c1cs) {
        // 0x808011FC: nop
    
            goto L_80801208;
    }
    // 0x808011FC: nop

    // 0x80801200: jal         0x80800E80
    // 0x80801204: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800E80_chlagoonufoint(rdram, ctx);
        goto after_9;
    // 0x80801204: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
L_80801208:
    // 0x80801208: jal         0x800BEA88
    // 0x8080120C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_10;
    // 0x8080120C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x80801210: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80801214: lhu         $v1, 0x76($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X76);
    // 0x80801218: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x8080121C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80801220: srl         $t5, $v1, 7
    ctx->r13 = S32(U32(ctx->r3) >> 7);
    // 0x80801224: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80801228: addiu       $v1, $t6, -0x4
    ctx->r3 = ADD32(ctx->r14, -0X4);
    // 0x8080122C: addiu       $a1, $v1, 0x1
    ctx->r5 = ADD32(ctx->r3, 0X1);
    // 0x80801230: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x80801234: addiu       $a2, $a2, 0x5A60
    ctx->r6 = ADD32(ctx->r6, 0X5A60);
    // 0x80801238: jal         0x80088660
    // 0x8080123C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _glid_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x8080123C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x80801240: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80801244: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80801248: addiu       $a2, $a2, 0x5A68
    ctx->r6 = ADD32(ctx->r6, 0X5A68);
    // 0x8080124C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80801250: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80801254: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801258: jal         0x80088660
    // 0x8080125C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    _glid_entrypoint_0(rdram, ctx);
        goto after_12;
    // 0x8080125C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    after_12:
    // 0x80801260: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80801264: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801268: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8080126C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80801270: jal         0x80088660
    // 0x80801274: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    _glid_entrypoint_0(rdram, ctx);
        goto after_13;
    // 0x80801274: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    after_13:
    // 0x80801278: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8080127C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801280: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80801284: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80801288: jal         0x80088660
    // 0x8080128C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _glid_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x8080128C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_14:
    // 0x80801290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801294: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801298: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8080129C: jr          $ra
    // 0x808012A0: nop

    return;
    // 0x808012A0: nop

;}
RECOMP_FUNC void func_80803B04_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803B04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80803B08: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80803B0C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80803B10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80803B14: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80803B18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80803B1C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80803B20: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x80803B24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80803B28:
    // 0x80803B28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80803B2C: jal         0x8009E4E0
    // 0x80803B30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8009E4E0(rdram, ctx);
        goto after_0;
    // 0x80803B30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80803B34: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80803B38: bnel        $s0, $s2, L_80803B28
    if (ctx->r16 != ctx->r18) {
        // 0x80803B3C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80803B28;
    }
    goto skip_0;
    // 0x80803B3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x80803B40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80803B44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80803B48: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80803B4C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80803B50: jr          $ra
    // 0x80803B54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80803B54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800444_chblackeye(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800444: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080044C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800450: jal         0x80100094
    // 0x80800454: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800454: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800458: beq         $v0, $zero, L_80800468
    if (ctx->r2 == 0) {
        // 0x8080045C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800468;
    }
    // 0x8080045C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800460: jal         0x800897C8
    // 0x80800464: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800464: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_80800468:
    // 0x80800468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080046C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800470: jr          $ra
    // 0x80800474: nop

    return;
    // 0x80800474: nop

;}
RECOMP_FUNC void subaddielink_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000BC: lw          $a2, 0x4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X4);
    // 0x808000C0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808000C4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x808000C8: beq         $a2, $zero, L_808000E8
    if (ctx->r6 == 0) {
        // 0x808000CC: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_808000E8;
    }
    // 0x808000CC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808000D0: jal         0x80089C60
    // 0x808000D4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _subaddiefind_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x808000D4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x808000D8: beq         $v0, $zero, L_808000E8
    if (ctx->r2 == 0) {
        // 0x808000DC: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_808000E8;
    }
    // 0x808000DC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808000E0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x808000E4: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
L_808000E8:
    // 0x808000E8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x808000EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000F4: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x808000F8: jr          $ra
    // 0x808000FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x808000FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
;}
RECOMP_FUNC void func_800C3F14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3F14: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C3F18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C3F1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C3F20: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800C3F24: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800C3F28: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C3F2C: addiu       $a2, $zero, 0x55F0
    ctx->r6 = ADD32(0, 0X55F0);
    // 0x800C3F30: jal         0x800C2840
    // 0x800C3F34: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C2840(rdram, ctx);
        goto after_0;
    // 0x800C3F34: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800C3F38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3F3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C3F40: jr          $ra
    // 0x800C3F44: nop

    return;
    // 0x800C3F44: nop

;}
RECOMP_FUNC void func_80800968_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800968: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080096C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800970: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800974: lw          $a2, 0x48($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X48);
    // 0x80800978: jal         0x80800898
    // 0x8080097C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800898_chnests(rdram, ctx);
        goto after_0;
    // 0x8080097C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800980: beql        $v0, $zero, L_808009C8
    if (ctx->r2 == 0) {
        // 0x80800984: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808009C8;
    }
    goto skip_0;
    // 0x80800984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800988: jal         0x800DF3E0
    // 0x8080098C: nop

    func_800DF3E0(rdram, ctx);
        goto after_1;
    // 0x8080098C: nop

    after_1:
    // 0x80800990: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800994: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(752, 0X1124) << 16);
    // 0x80800998: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080099C: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x808009A0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x808009A4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x808009A8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x808009AC: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x808009B0: jal         0x800DF744
    // 0x808009B4: lbu         $a0, 0x1124($a0)
    ctx->r4 = MEM_BU(ctx->r4, (int16_t)RELOC_LO16(752, 0X1124));
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x808009B4: lbu         $a0, 0x1124($a0)
    ctx->r4 = MEM_BU(ctx->r4, (int16_t)RELOC_LO16(752, 0X1124));
    after_2:
    // 0x808009B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808009BC: jal         0x801018A4
    // 0x808009C0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_801018A4(rdram, ctx);
        goto after_3;
    // 0x808009C0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x808009C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808009C8:
    // 0x808009C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009CC: jr          $ra
    // 0x808009D0: nop

    return;
    // 0x808009D0: nop

;}
RECOMP_FUNC void func_800E8F8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8F8C: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x800E8F90: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800E8F94: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800E8F98: lhu         $t8, 0x2560($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X2560);
    // 0x800E8F9C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800E8FA0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800E8FA4: addu        $v0, $t8, $a2
    ctx->r2 = ADD32(ctx->r24, ctx->r6);
    // 0x800E8FA8: sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2 << 3);
    // 0x800E8FAC: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x800E8FB0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800E8FB4: lw          $t0, 0x3524($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3524);
    // 0x800E8FB8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800E8FBC: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x800E8FC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8FC4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800E8FC8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800E8FCC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800E8FD0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E8FD4: addiu       $a0, $a0, -0x26A0
    ctx->r4 = ADD32(ctx->r4, -0X26A0);
    // 0x800E8FD8: addiu       $a2, $zero, 0xD8
    ctx->r6 = ADD32(0, 0XD8);
    // 0x800E8FDC: jal         0x800E8E70
    // 0x800E8FE0: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    func_800E8E70(rdram, ctx);
        goto after_0;
    // 0x800E8FE0: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_0:
    // 0x800E8FE4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800E8FE8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800E8FEC: addiu       $t5, $t5, -0x2970
    ctx->r13 = ADD32(ctx->r13, -0X2970);
    // 0x800E8FF0: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800E8FF4: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800E8FF8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800E8FFC: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800E9000: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800E9004: addiu       $t4, $t3, 0x3A8
    ctx->r12 = ADD32(ctx->r11, 0X3A8);
    // 0x800E9008: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x800E900C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800E9010: addiu       $a1, $a1, -0x26A0
    ctx->r5 = ADD32(ctx->r5, -0X26A0);
    // 0x800E9014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E9018: jal         0x8001BBA0
    // 0x800E901C: addiu       $a2, $zero, 0xD8
    ctx->r6 = ADD32(0, 0XD8);
    rare_memcpy(rdram, ctx);
        goto after_1;
    // 0x800E901C: addiu       $a2, $zero, 0xD8
    ctx->r6 = ADD32(0, 0XD8);
    after_1:
    // 0x800E9020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800E9024: lui         $t7, 0x1A4
    ctx->r15 = S32(0X1A4 << 16);
    // 0x800E9028: addiu       $t7, $t7, 0x6560
    ctx->r15 = ADD32(ctx->r15, 0X6560);
    // 0x800E902C: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x800E9030: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800E9034: sw          $t8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r24;
    // 0x800E9038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E903C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800E9040: jr          $ra
    // 0x800E9044: nop

    return;
    // 0x800E9044: nop

;}
RECOMP_FUNC void func_800D2C54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2C54: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D2C58: addiu       $a1, $a1, -0x4CE0
    ctx->r5 = ADD32(ctx->r5, -0X4CE0);
    // 0x800D2C5C: lbu         $t6, 0x1($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X1);
    // 0x800D2C60: bne         $t6, $zero, L_800D2CBC
    if (ctx->r14 != 0) {
        // 0x800D2C64: nop
    
            goto L_800D2CBC;
    }
    // 0x800D2C64: nop

    // 0x800D2C68: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800D2C6C: lui         $t8, 0xF800
    ctx->r24 = S32(0XF800 << 16);
    // 0x800D2C70: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800D2C74: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800D2C78: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800D2C7C: lh          $t9, 0x32($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X32);
    // 0x800D2C80: lh          $t5, 0x2E($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X2E);
    // 0x800D2C84: lh          $t2, 0x2C($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X2C);
    // 0x800D2C88: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x800D2C8C: lh          $t9, 0x30($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X30);
    // 0x800D2C90: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x800D2C94: sll         $t3, $t2, 24
    ctx->r11 = S32(ctx->r10 << 24);
    // 0x800D2C98: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x800D2C9C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800D2CA0: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x800D2CA4: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x800D2CA8: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800D2CAC: or          $t0, $t8, $t2
    ctx->r8 = ctx->r24 | ctx->r10;
    // 0x800D2CB0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800D2CB4: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800D2CB8: sb          $t3, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r11;
L_800D2CBC:
    // 0x800D2CBC: jr          $ra
    // 0x800D2CC0: nop

    return;
    // 0x800D2CC0: nop

;}
RECOMP_FUNC void func_800E04AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E04AC: jr          $ra
    // 0x800E04B0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x800E04B0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800E04B4: nop

    // 0x800E04B8: nop

    // 0x800E04BC: nop

;}
RECOMP_FUNC void func_808011DC_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011DC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808011E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808011E4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808011E8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808011EC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808011F0: jal         0x80100094
    // 0x808011F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808011F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808011F8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808011FC: jal         0x80089998
    // 0x80801200: addiu       $a0, $v0, 0x4DC
    ctx->r4 = ADD32(ctx->r2, 0X4DC);
    _sumultiscore_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80801200: addiu       $a0, $v0, 0x4DC
    ctx->r4 = ADD32(ctx->r2, 0X4DC);
    after_1:
    // 0x80801204: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80801208: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080120C: lhu         $v0, 0x72($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X72);
    // 0x80801210: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x80801214: beq         $t7, $at, L_80801234
    if (ctx->r15 == ctx->r1) {
        // 0x80801218: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801234;
    }
    // 0x80801218: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080121C: beq         $t7, $at, L_80801284
    if (ctx->r15 == ctx->r1) {
        // 0x80801220: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80801284;
    }
    // 0x80801220: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801224: beq         $t7, $at, L_8080134C
    if (ctx->r15 == ctx->r1) {
        // 0x80801228: nop
    
            goto L_8080134C;
    }
    // 0x80801228: nop

    // 0x8080122C: b           L_808013B4
    // 0x80801230: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808013B4;
    // 0x80801230: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801234:
    // 0x80801234: jal         0x800C954C
    // 0x80801238: nop

    func_800C954C(rdram, ctx);
        goto after_2;
    // 0x80801238: nop

    after_2:
    // 0x8080123C: bnel        $v0, $zero, L_808013B4
    if (ctx->r2 != 0) {
        // 0x80801240: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808013B4;
    }
    goto skip_0;
    // 0x80801240: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80801244: jal         0x800DA298
    // 0x80801248: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80801248: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    after_3:
    // 0x8080124C: bne         $v0, $zero, L_808013B0
    if (ctx->r2 != 0) {
        // 0x80801250: lw          $t8, 0x38($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X38);
            goto L_808013B0;
    }
    // 0x80801250: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80801254: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80801258: addiu       $t9, $zero, 0x22
    ctx->r25 = ADD32(0, 0X22);
    // 0x8080125C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80801260: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    // 0x80801264: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80801268: jal         0x8008A208
    // 0x8080126C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x8080126C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80801270: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801274: jal         0x80101FDC
    // 0x80801278: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80801278: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x8080127C: b           L_808013B4
    // 0x80801280: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808013B4;
    // 0x80801280: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801284:
    // 0x80801284: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80801288: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8080128C: addiu       $s0, $s1, 0x1C
    ctx->r16 = ADD32(ctx->r17, 0X1C);
    // 0x80801290: blez        $t0, L_808012BC
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80801294: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808012BC;
    }
    // 0x80801294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801298:
    // 0x80801298: jal         0x800D90A4
    // 0x8080129C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_800D90A4(rdram, ctx);
        goto after_6;
    // 0x8080129C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_6:
    // 0x808012A0: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x808012A4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x808012A8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x808012AC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808012B0: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x808012B4: bnel        $at, $zero, L_80801298
    if (ctx->r1 != 0) {
        // 0x808012B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801298;
    }
    goto skip_1;
    // 0x808012B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_808012BC:
    // 0x808012BC: jal         0x80089C68
    // 0x808012C0: addiu       $a0, $zero, 0x356
    ctx->r4 = ADD32(0, 0X356);
    _subaddiefind_entrypoint_9(rdram, ctx);
        goto after_7;
    // 0x808012C0: addiu       $a0, $zero, 0x356
    ctx->r4 = ADD32(0, 0X356);
    after_7:
    // 0x808012C4: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x808012C8: beq         $at, $zero, L_80801320
    if (ctx->r1 == 0) {
        // 0x808012CC: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80801320;
    }
    // 0x808012CC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808012D0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808012D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808012D8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808012DC: jal         0x800DC178
    // 0x808012E0: nop

    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x808012E0: nop

    after_8:
    // 0x808012E4: jal         0x80088368
    // 0x808012E8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x808012E8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x808012EC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x808012F0: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808012F4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808012F8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808012FC: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    // 0x80801300: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80801304: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80801308: jal         0x800D9154
    // 0x8080130C: nop

    func_800D9154(rdram, ctx);
        goto after_10;
    // 0x8080130C: nop

    after_10:
    // 0x80801310: beq         $v0, $zero, L_80801320
    if (ctx->r2 == 0) {
        // 0x80801314: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80801320;
    }
    // 0x80801314: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801318: jal         0x80108B04
    // 0x8080131C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_80108B04(rdram, ctx);
        goto after_11;
    // 0x8080131C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_11:
L_80801320:
    // 0x80801320: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80801324: lw          $a0, 0x6C($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X6C);
    // 0x80801328: andi        $t3, $a0, 0x1FF
    ctx->r11 = ctx->r4 & 0X1FF;
    // 0x8080132C: jal         0x800CEAD0
    // 0x80801330: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_12;
    // 0x80801330: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_12:
    // 0x80801334: beql        $v0, $zero, L_808013B4
    if (ctx->r2 == 0) {
        // 0x80801338: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808013B4;
    }
    goto skip_2;
    // 0x80801338: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8080133C: jal         0x808015A4
    // 0x80801340: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_808015A4_chhoopswoop(rdram, ctx);
        goto after_13;
    // 0x80801340: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_13:
    // 0x80801344: b           L_808013B4
    // 0x80801348: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808013B4;
    // 0x80801348: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080134C:
    // 0x8080134C: jal         0x8008A2E8
    // 0x80801350: nop

    _susubgame_entrypoint_9(rdram, ctx);
        goto after_14;
    // 0x80801350: nop

    after_14:
    // 0x80801354: bnel        $v0, $zero, L_80801370
    if (ctx->r2 != 0) {
        // 0x80801358: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80801370;
    }
    goto skip_3;
    // 0x80801358: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    skip_3:
    // 0x8080135C: jal         0x800D9078
    // 0x80801360: addiu       $a0, $s1, 0x9F8
    ctx->r4 = ADD32(ctx->r17, 0X9F8);
    func_800D9078(rdram, ctx);
        goto after_15;
    // 0x80801360: addiu       $a0, $s1, 0x9F8
    ctx->r4 = ADD32(ctx->r17, 0X9F8);
    after_15:
    // 0x80801364: beql        $v0, $zero, L_808013B4
    if (ctx->r2 == 0) {
        // 0x80801368: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808013B4;
    }
    goto skip_4;
    // 0x80801368: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x8080136C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_80801370:
    // 0x80801370: addiu       $a1, $s1, 0x4C4
    ctx->r5 = ADD32(ctx->r17, 0X4C4);
    // 0x80801374: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80801378: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8080137C: jal         0x8008A2C8
    // 0x80801380: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_16;
    // 0x80801380: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_16:
    // 0x80801384: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80801388: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8080138C: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x80801390: addiu       $t5, $zero, 0x22
    ctx->r13 = ADD32(0, 0X22);
    // 0x80801394: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80801398: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8080139C: jal         0x8008A208
    // 0x808013A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_17;
    // 0x808013A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_17:
    // 0x808013A4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808013A8: jal         0x80101FDC
    // 0x808013AC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_18;
    // 0x808013AC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_18:
L_808013B0:
    // 0x808013B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808013B4:
    // 0x808013B4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808013B8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808013BC: jr          $ra
    // 0x808013C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808013C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80801584_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801584: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801588: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080158C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801590: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80801594: jal         0x801084B0
    // 0x80801598: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_801084B0(rdram, ctx);
        goto after_0;
    // 0x80801598: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8080159C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808015A0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808015A4: lhu         $a1, 0x72($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X72);
    // 0x808015A8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x808015AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808015B0: srl         $t8, $a1, 10
    ctx->r24 = S32(U32(ctx->r5) >> 10);
    // 0x808015B4: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x808015B8: jal         0x80102424
    // 0x808015BC: sw          $t7, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r15;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x808015BC: sw          $t7, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r15;
    after_1:
    // 0x808015C0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x808015C4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808015C8: jal         0x80102FDC
    // 0x808015CC: lw          $a1, 0x38($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X38);
    func_80102FDC(rdram, ctx);
        goto after_2;
    // 0x808015CC: lw          $a1, 0x38($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X38);
    after_2:
    // 0x808015D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808015D4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(932, 0X2B4C) << 16);
    // 0x808015D8: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x808015DC: lw          $v0, 0x28($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X28);
    // 0x808015E0: sll         $t2, $v0, 20
    ctx->r10 = S32(ctx->r2 << 20);
    // 0x808015E4: srl         $t3, $t2, 31
    ctx->r11 = S32(U32(ctx->r10) >> 31);
    // 0x808015E8: sll         $t5, $v0, 19
    ctx->r13 = S32(ctx->r2 << 19);
    // 0x808015EC: srl         $t6, $t5, 31
    ctx->r14 = S32(U32(ctx->r13) >> 31);
    // 0x808015F0: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x808015F4: sll         $t8, $v0, 18
    ctx->r24 = S32(ctx->r2 << 18);
    // 0x808015F8: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x808015FC: subu        $t7, $t4, $t6
    ctx->r15 = SUB32(ctx->r12, ctx->r14);
    // 0x80801600: subu        $v1, $t7, $t9
    ctx->r3 = SUB32(ctx->r15, ctx->r25);
    // 0x80801604: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // 0x80801608: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x8080160C: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x80801610: jal         0x80105A9C
    // 0x80801614: lw          $a1, 0x2B4C($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(932, 0X2B4C));
    func_80105A9C(rdram, ctx);
        goto after_3;
    // 0x80801614: lw          $a1, 0x2B4C($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(932, 0X2B4C));
    after_3:
    // 0x80801618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080161C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801620: jr          $ra
    // 0x80801624: nop

    return;
    // 0x80801624: nop

;}
RECOMP_FUNC void func_80800058_chtimetable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080005C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800060: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800064: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800068: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8080006C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800070: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800074: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800078: jal         0x80102FDC
    // 0x8080007C: nop

    func_80102FDC(rdram, ctx);
        goto after_0;
    // 0x8080007C: nop

    after_0:
    // 0x80800080: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800088: jal         0x80800000
    // 0x8080008C: addiu       $a2, $a0, 0x28
    ctx->r6 = ADD32(ctx->r4, 0X28);
    func_80800000_chtimetable(rdram, ctx);
        goto after_1;
    // 0x8080008C: addiu       $a2, $a0, 0x28
    ctx->r6 = ADD32(ctx->r4, 0X28);
    after_1:
    // 0x80800090: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800094: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800098: jal         0x80800000
    // 0x8080009C: addiu       $a2, $a0, 0x18
    ctx->r6 = ADD32(ctx->r4, 0X18);
    func_80800000_chtimetable(rdram, ctx);
        goto after_2;
    // 0x8080009C: addiu       $a2, $a0, 0x18
    ctx->r6 = ADD32(ctx->r4, 0X18);
    after_2:
    // 0x808000A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A8: jr          $ra
    // 0x808000AC: nop

    return;
    // 0x808000AC: nop

;}
RECOMP_FUNC void _ncpod_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089588: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x80089588);
    return;
    // 0x8008958C: addi        $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
;}
RECOMP_FUNC void _chwallsnakebaddy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F00: syscall     471
    recomp_syscall_handler(rdram, ctx, 0x80086F00);
    return;
    // 0x80086F04: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800C44_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C4C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800C50: jal         0x80100094
    // 0x80800C54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800C58: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800C5C: lh          $t6, 0x2C($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2C);
    // 0x80800C60: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80800C64: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x80800C68: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x80800C6C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80800C70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800C74: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800C78: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800C7C: jal         0x800136E4
    // 0x80800C80: nop

    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x80800C80: nop

    after_1:
    // 0x80800C84: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80800C88: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80800C8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800C90: jal         0x800D0B68
    // 0x80800C94: swc1        $f0, 0x48($t9)
    MEM_W(0X48, ctx->r25) = ctx->f0.u32l;
    func_800D0B68(rdram, ctx);
        goto after_2;
    // 0x80800C94: swc1        $f0, 0x48($t9)
    MEM_W(0X48, ctx->r25) = ctx->f0.u32l;
    after_2:
    // 0x80800C98: beq         $v0, $zero, L_80800CA8
    if (ctx->r2 == 0) {
        // 0x80800C9C: lw          $t1, 0x1C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X1C);
            goto L_80800CA8;
    }
    // 0x80800C9C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CA0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80800CA4: sh          $t0, 0x2C($t1)
    MEM_H(0X2C, ctx->r9) = ctx->r8;
L_80800CA8:
    // 0x80800CA8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80800CAC: addiu       $a0, $t2, 0x4
    ctx->r4 = ADD32(ctx->r10, 0X4);
    // 0x80800CB0: jal         0x800EE7F8
    // 0x80800CB4: addiu       $a1, $t2, 0x18
    ctx->r5 = ADD32(ctx->r10, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800CB4: addiu       $a1, $t2, 0x18
    ctx->r5 = ADD32(ctx->r10, 0X18);
    after_3:
    // 0x80800CB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800CC0: jr          $ra
    // 0x80800CC4: nop

    return;
    // 0x80800CC4: nop

;}
RECOMP_FUNC void bsbwhirl_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008D0: jal         0x8080017C
    // 0x808008D4: nop

    func_8080017C_bsbwhirl(rdram, ctx);
        goto after_0;
    // 0x808008D4: nop

    after_0:
    // 0x808008D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008E0: jr          $ra
    // 0x808008E4: nop

    return;
    // 0x808008E4: nop

;}
RECOMP_FUNC void _fxstep_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A18: syscall     718
    recomp_syscall_handler(rdram, ctx, 0x80088A18);
    return;
    // 0x80088A1C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_8080072C_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080072C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800730: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800734: jal         0x808004B8
    // 0x80800738: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bsbabykaz_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800738: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080073C: jal         0x80082FF0
    // 0x80800740: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800740: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800748: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080074C: jr          $ra
    // 0x80800750: nop

    return;
    // 0x80800750: nop

;}
RECOMP_FUNC void bafpctrl_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BFC: lw          $t6, 0x90($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X90);
    // 0x80800C00: lbu         $v0, 0x14($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X14);
    // 0x80800C04: xori        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 ^ 0X2;
    // 0x80800C08: jr          $ra
    // 0x80800C0C: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    return;
    // 0x80800C0C: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void _sumumbofx_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800898F8: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x800898F8);
    return;
    // 0x800898FC: addi        $t0, $zero, 0x5C
    ctx->r8 = ADD32(0, 0X5C);
;}
RECOMP_FUNC void _bskazstilt_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800836C0: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x800836C0);
    return;
    // 0x800836C4: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_808077AC_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808077AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808077B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808077B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808077B8: jal         0x80801B64
    // 0x808077BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801B64_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x808077BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x808077C0: jal         0x800839B8
    // 0x808077C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x808077C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808077C8: jal         0x80807C8C
    // 0x808077CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80807C8C_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x808077CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808077D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808077D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808077D8: jr          $ra
    // 0x808077DC: nop

    return;
    // 0x808077DC: nop

;}
RECOMP_FUNC void _subaddieDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A4A0: syscall     843
    recomp_syscall_handler(rdram, ctx, 0x8008A4A0);
    return;
    // 0x8008A4A4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _fxegg_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A70: syscall     719
    recomp_syscall_handler(rdram, ctx, 0x80088A70);
    return;
    // 0x80088A74: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808008A4_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008A4: addiu       $t6, $a1, -0x29
    ctx->r14 = ADD32(ctx->r5, -0X29);
    // 0x808008A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008AC: sltiu       $at, $t6, 0x2A
    ctx->r1 = ctx->r14 < 0X2A ? 1 : 0;
    // 0x808008B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808008B8: beq         $at, $zero, L_80800980
    if (ctx->r1 == 0) {
        // 0x808008BC: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800980;
    }
    // 0x808008BC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808008C0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808008C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2168, 0XE28) << 16);
    // 0x808008C8: addu        $at, $at, $t6
    gpr jr_addend_808008D0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808008CC: lw          $t6, 0xE28($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2168, 0XE28));
    // 0x808008D0: jr          $t6
    // 0x808008D4: nop

    switch (jr_addend_808008D0 >> 2) {
        case 0: goto L_80800960; break;
        case 1: goto L_80800970; break;
        case 2: goto L_80800980; break;
        case 3: goto L_80800980; break;
        case 4: goto L_80800980; break;
        case 5: goto L_80800930; break;
        case 6: goto L_80800980; break;
        case 7: goto L_80800948; break;
        case 8: goto L_80800980; break;
        case 9: goto L_80800980; break;
        case 10: goto L_80800980; break;
        case 11: goto L_80800980; break;
        case 12: goto L_80800980; break;
        case 13: goto L_80800980; break;
        case 14: goto L_80800980; break;
        case 15: goto L_80800980; break;
        case 16: goto L_80800980; break;
        case 17: goto L_80800980; break;
        case 18: goto L_80800980; break;
        case 19: goto L_80800980; break;
        case 20: goto L_808008D8; break;
        case 21: goto L_80800980; break;
        case 22: goto L_80800980; break;
        case 23: goto L_80800980; break;
        case 24: goto L_80800980; break;
        case 25: goto L_80800980; break;
        case 26: goto L_80800980; break;
        case 27: goto L_80800980; break;
        case 28: goto L_80800980; break;
        case 29: goto L_80800980; break;
        case 30: goto L_80800980; break;
        case 31: goto L_80800980; break;
        case 32: goto L_80800980; break;
        case 33: goto L_80800980; break;
        case 34: goto L_80800980; break;
        case 35: goto L_80800980; break;
        case 36: goto L_80800980; break;
        case 37: goto L_80800980; break;
        case 38: goto L_80800980; break;
        case 39: goto L_80800980; break;
        case 40: goto L_80800980; break;
        case 41: goto L_808008E8; break;
        default: switch_error(__func__, 0x808008D0, 0x80800E28);
    }
    // 0x808008D4: nop

L_808008D8:
    // 0x808008D8: jal         0x80800864
    // 0x808008DC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800864_chfactoryworkerdirty(rdram, ctx);
        goto after_0;
    // 0x808008DC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x808008E0: b           L_80800984
    // 0x808008E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800984;
    // 0x808008E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808008E8:
    // 0x808008E8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808008EC: jal         0x801022E4
    // 0x808008F0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_801022E4(rdram, ctx);
        goto after_1;
    // 0x808008F0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x808008F4: addiu       $at, $zero, 0x35E
    ctx->r1 = ADD32(0, 0X35E);
    // 0x808008F8: bne         $v0, $at, L_80800918
    if (ctx->r2 != ctx->r1) {
        // 0x808008FC: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_80800918;
    }
    // 0x808008FC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800900: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2168, 0X1024) << 16);
    // 0x80800904: addiu       $a0, $a0, 0x1024
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2168, 0X1024));
    // 0x80800908: jal         0x80088090
    // 0x8080090C: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x8080090C: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_2:
    // 0x80800910: b           L_80800984
    // 0x80800914: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800984;
    // 0x80800914: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800918:
    // 0x80800918: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2168, 0X1034) << 16);
    // 0x8080091C: addiu       $a0, $a0, 0x1034
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2168, 0X1034));
    // 0x80800920: jal         0x80088090
    // 0x80800924: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800924: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_3:
    // 0x80800928: b           L_80800984
    // 0x8080092C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800984;
    // 0x8080092C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800930:
    // 0x80800930: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800934: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    // 0x80800938: jal         0x80800788
    // 0x8080093C: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    func_80800788_chfactoryworkerdirty(rdram, ctx);
        goto after_4;
    // 0x8080093C: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    after_4:
    // 0x80800940: b           L_80800984
    // 0x80800944: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800984;
    // 0x80800944: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800948:
    // 0x80800948: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080094C: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    // 0x80800950: jal         0x80800828
    // 0x80800954: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    func_80800828_chfactoryworkerdirty(rdram, ctx);
        goto after_5;
    // 0x80800954: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    after_5:
    // 0x80800958: b           L_80800988
    // 0x8080095C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800988;
    // 0x8080095C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800960:
    // 0x80800960: jal         0x80800D48
    // 0x80800964: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800D48_chfactoryworkerdirty(rdram, ctx);
        goto after_6;
    // 0x80800964: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_6:
    // 0x80800968: b           L_80800984
    // 0x8080096C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800984;
    // 0x8080096C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800970:
    // 0x80800970: jal         0x80800DB4
    // 0x80800974: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800DB4_chfactoryworkerdirty(rdram, ctx);
        goto after_7;
    // 0x80800974: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_7:
    // 0x80800978: b           L_80800984
    // 0x8080097C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800984;
    // 0x8080097C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800980:
    // 0x80800980: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800984:
    // 0x80800984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800988:
    // 0x80800988: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080098C: jr          $ra
    // 0x80800990: nop

    return;
    // 0x80800990: nop

;}
RECOMP_FUNC void func_80800270_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800270: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800278: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8080027C: jal         0x80800180
    // 0x80800280: addiu       $a1, $a1, 0x2FF8
    ctx->r5 = ADD32(ctx->r5, 0X2FF8);
    func_80800180_bstrexlarge(rdram, ctx);
        goto after_0;
    // 0x80800280: addiu       $a1, $a1, 0x2FF8
    ctx->r5 = ADD32(ctx->r5, 0X2FF8);
    after_0:
    // 0x80800284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080028C: jr          $ra
    // 0x80800290: nop

    return;
    // 0x80800290: nop

;}
RECOMP_FUNC void func_800C9128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9128: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C912C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800C9130: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9134: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C9138: jal         0x80087EA0
    // 0x800C913C: addiu       $a0, $a0, -0x5500
    ctx->r4 = ADD32(ctx->r4, -0X5500);
    _gclightsDll_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x800C913C: addiu       $a0, $a0, -0x5500
    ctx->r4 = ADD32(ctx->r4, -0X5500);
    after_0:
    // 0x800C9140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9148: jr          $ra
    // 0x800C914C: nop

    return;
    // 0x800C914C: nop

;}
RECOMP_FUNC void func_80800020_chlavaarchgrill3switches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800020: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800024: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800028: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8080002C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800030: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800034: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800038: beq         $a1, $at, L_80800054
    if (ctx->r5 == ctx->r1) {
        // 0x8080003C: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800054;
    }
    // 0x8080003C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800040: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800044: beq         $a1, $at, L_8080007C
    if (ctx->r5 == ctx->r1) {
        // 0x80800048: addiu       $a0, $zero, 0x288
        ctx->r4 = ADD32(0, 0X288);
            goto L_8080007C;
    }
    // 0x80800048: addiu       $a0, $zero, 0x288
    ctx->r4 = ADD32(0, 0X288);
    // 0x8080004C: b           L_808000A0
    // 0x80800050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
        goto L_808000A0;
    // 0x80800050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80800054:
    // 0x80800054: addiu       $a0, $zero, 0x288
    ctx->r4 = ADD32(0, 0X288);
    // 0x80800058: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8080005C: jal         0x80101180
    // 0x80800060: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_0;
    // 0x80800060: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800064: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800068: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080006C: jal         0x80085820
    // 0x80800070: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80800070: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800074: b           L_808000B0
    // 0x80800078: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000B0;
    // 0x80800078: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080007C:
    // 0x8080007C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800080: jal         0x80101180
    // 0x80800084: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_2;
    // 0x80800084: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800088: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080008C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800090: jal         0x80085820
    // 0x80800094: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x80800094: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80800098: b           L_808000B0
    // 0x8080009C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000B0;
    // 0x8080009C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000A0:
    // 0x808000A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808000A4: jal         0x80085820
    // 0x808000A8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x808000A8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x808000AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000B0:
    // 0x808000B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000B8: jr          $ra
    // 0x808000BC: nop

    return;
    // 0x808000BC: nop

;}
RECOMP_FUNC void ncbaspiral_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800220: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800224: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800228: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080022C: lw          $a0, 0x48($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48);
    // 0x80800230: jal         0x800EE7F8
    // 0x80800234: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800234: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800238: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8080023C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80800240: lw          $t9, 0x48($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X48);
    // 0x80800244: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x80800248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080024C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800250: jr          $ra
    // 0x80800254: nop

    return;
    // 0x80800254: nop

;}
RECOMP_FUNC void func_80800FEC_chfantasyeyeball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FEC: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80800FF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800FF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800FF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800FFC: addiu       $a0, $zero, 0x482
    ctx->r4 = ADD32(0, 0X482);
    // 0x80801000: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80801004: jal         0x80089C40
    // 0x80801008: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    _subaddiefind_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80801008: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_0:
    // 0x8080100C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80801010: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80801014: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80801018: blez        $v0, L_80801070
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080101C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80801070;
    }
    // 0x8080101C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801020: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
L_80801024:
    // 0x80801024: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80801028: lhu         $t6, 0x72($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X72);
    // 0x8080102C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801030: slti        $at, $t7, 0x7
    ctx->r1 = SIGNED(ctx->r15) < 0X7 ? 1 : 0;
    // 0x80801034: beql        $at, $zero, L_80801064
    if (ctx->r1 == 0) {
        // 0x80801038: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80801064;
    }
    goto skip_0;
    // 0x80801038: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x8080103C: beql        $s0, $v0, L_80801064
    if (ctx->r16 == ctx->r2) {
        // 0x80801040: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80801064;
    }
    goto skip_1;
    // 0x80801040: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_1:
    // 0x80801044: lhu         $v1, 0x76($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X76);
    // 0x80801048: srl         $t8, $v1, 7
    ctx->r24 = S32(U32(ctx->r3) >> 7);
    // 0x8080104C: slt         $at, $t8, $a2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80801050: beql        $at, $zero, L_80801064
    if (ctx->r1 == 0) {
        // 0x80801054: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80801064;
    }
    goto skip_2;
    // 0x80801054: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_2:
    // 0x80801058: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8080105C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80801060: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80801064:
    // 0x80801064: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80801068: bne         $at, $zero, L_80801024
    if (ctx->r1 != 0) {
        // 0x8080106C: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80801024;
    }
    // 0x8080106C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80801070:
    // 0x80801070: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80801074: bne         $t0, $at, L_80801088
    if (ctx->r8 != ctx->r1) {
        // 0x80801078: sll         $t9, $t0, 2
        ctx->r25 = S32(ctx->r8 << 2);
            goto L_80801088;
    }
    // 0x80801078: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8080107C: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x80801080: b           L_8080109C
    // 0x80801084: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080109C;
    // 0x80801084: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801088:
    // 0x80801088: addu        $t1, $sp, $t9
    ctx->r9 = ADD32(ctx->r29, ctx->r25);
    // 0x8080108C: lw          $t1, 0x3C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3C);
    // 0x80801090: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801094: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80801098: sw          $t2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r10;
L_8080109C:
    // 0x8080109C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808010A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808010A4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x808010A8: jr          $ra
    // 0x808010AC: nop

    return;
    // 0x808010AC: nop

;}
RECOMP_FUNC void func_80800BEC_sudeflect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BEC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800BF0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80800BF4: lui         $s6, 0x8080
    ctx->r22 = S32(RELOC_HI16(3222, 0X1020) << 16);
    // 0x80800BF8: lw          $s6, 0x1020($s6)
    ctx->r22 = MEM_W(ctx->r22, (int16_t)RELOC_LO16(3222, 0X1020));
    // 0x80800BFC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800C00: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80800C04: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80800C08: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800C0C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800C10: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800C14: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800C18: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800C1C: lw          $a2, 0x0($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X0);
    // 0x80800C20: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800C24: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80800C28: beq         $a2, $zero, L_80800CE4
    if (ctx->r6 == 0) {
        // 0x80800C2C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80800CE4;
    }
    // 0x80800C2C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800C30: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x80800C34: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800C38: nop

L_80800C3C:
    // 0x80800C3C: jal         0x800E9E88
    // 0x80800C40: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800E9E88(rdram, ctx);
        goto after_0;
    // 0x80800C40: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80800C44: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800C48: jal         0x800E9EB4
    // 0x80800C4C: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    func_800E9EB4(rdram, ctx);
        goto after_1;
    // 0x80800C4C: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    after_1:
    // 0x80800C50: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x80800C54: beq         $at, $zero, L_80800CD4
    if (ctx->r1 == 0) {
        // 0x80800C58: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80800CD4;
    }
    // 0x80800C58: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800C5C: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
L_80800C60:
    // 0x80800C60: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80800C64: beql        $t7, $zero, L_80800CC8
    if (ctx->r15 == 0) {
        // 0x80800C68: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80800CC8;
    }
    goto skip_0;
    // 0x80800C68: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_0:
    // 0x80800C6C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80800C70: jal         0x8008A340
    // 0x80800C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sueggmisc_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800C78: beql        $v0, $zero, L_80800CC8
    if (ctx->r2 == 0) {
        // 0x80800C7C: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80800CC8;
    }
    goto skip_1;
    // 0x80800C7C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_1:
    // 0x80800C80: jal         0x80106790
    // 0x80800C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80106790(rdram, ctx);
        goto after_3;
    // 0x80800C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800C88: lw          $t8, 0x64($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X64);
    // 0x80800C8C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800C90: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800C94: sll         $t0, $t8, 14
    ctx->r8 = S32(ctx->r24 << 14);
    // 0x80800C98: bltz        $t0, L_80800CC4
    if (SIGNED(ctx->r8) < 0) {
        // 0x80800C9C: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_80800CC4;
    }
    // 0x80800C9C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80800CA0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800CA4: jal         0x80800ECC
    // 0x80800CA8: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    func_80800ECC_sudeflect(rdram, ctx);
        goto after_4;
    // 0x80800CA8: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    after_4:
    // 0x80800CAC: beq         $v0, $zero, L_80800CC4
    if (ctx->r2 == 0) {
        // 0x80800CB0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CC4;
    }
    // 0x80800CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CB4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800CB8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800CBC: jal         0x8010108C
    // 0x80800CC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_5;
    // 0x80800CC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
L_80800CC4:
    // 0x80800CC4: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_80800CC8:
    // 0x80800CC8: sltu        $at, $s1, $s3
    ctx->r1 = ctx->r17 < ctx->r19 ? 1 : 0;
    // 0x80800CCC: bnel        $at, $zero, L_80800C60
    if (ctx->r1 != 0) {
        // 0x80800CD0: lw          $t6, 0x8($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X8);
            goto L_80800C60;
    }
    goto skip_2;
    // 0x80800CD0: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    skip_2:
L_80800CD4:
    // 0x80800CD4: lw          $a2, 0x4($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X4);
    // 0x80800CD8: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x80800CDC: bne         $a2, $zero, L_80800C3C
    if (ctx->r6 != 0) {
        // 0x80800CE0: nop
    
            goto L_80800C3C;
    }
    // 0x80800CE0: nop

L_80800CE4:
    // 0x80800CE4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800CE8: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80800CEC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800CF0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800CF4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800CF8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800CFC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800D00: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80800D04: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80800D08: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80800D0C: jr          $ra
    // 0x80800D10: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800D10: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void gcstatusDll_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800194: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80800198: jr          $ra
    // 0x8080019C: lbu         $v0, -0x4BF0($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X4BF0);
    return;
    // 0x8080019C: lbu         $v0, -0x4BF0($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X4BF0);
;}
RECOMP_FUNC void _chexploder_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086698: syscall     354
    recomp_syscall_handler(rdram, ctx, 0x80086698);
    return;
    // 0x8008669C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80102780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102780: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80102784: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80102788: lwc1        $f6, 0x48($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X48);
    // 0x8010278C: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x80102790: lwc1        $f8, 0x4C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x80102794: jr          $ra
    // 0x80102798: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    return;
    // 0x80102798: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
;}
RECOMP_FUNC void bsstonehead_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EE4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800EE8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(376, 0X1670) << 16);
    // 0x80800EEC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800EF0: jr          $ra
    // 0x80800EF4: lw          $v0, 0x1670($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(376, 0X1670));
    return;
    // 0x80800EF4: lw          $v0, 0x1670($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(376, 0X1670));
;}
RECOMP_FUNC void func_80800BEC_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BF4: jal         0x808001E0
    // 0x80800BF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bsmum_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800BF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800BFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800C00: jal         0x800845D8
    // 0x80800C04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babounce_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800C04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800C08: lui         $a2, 0x3F0E
    ctx->r6 = S32(0X3F0E << 16);
    // 0x80800C0C: ori         $a2, $a2, 0x9100
    ctx->r6 = ctx->r6 | 0X9100;
    // 0x80800C10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800C14: jal         0x800845E0
    // 0x80800C18: addiu       $a1, $zero, 0xB7
    ctx->r5 = ADD32(0, 0XB7);
    _babounce_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800C18: addiu       $a1, $zero, 0xB7
    ctx->r5 = ADD32(0, 0XB7);
    after_2:
    // 0x80800C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C24: jr          $ra
    // 0x80800C28: nop

    return;
    // 0x80800C28: nop

;}
RECOMP_FUNC void func_80024D90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024D90: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80024D94: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x80024D98: beq         $t6, $zero, L_80024DC0
    if (ctx->r14 == 0) {
        // 0x80024D9C: nop
    
            goto L_80024DC0;
    }
    // 0x80024D9C: nop

    // 0x80024DA0: lw          $t7, 0x18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18);
    // 0x80024DA4: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80024DA8: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80024DAC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80024DB0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80024DB4: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80024DB8: b           L_80024DC8
    // 0x80024DBC: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
        goto L_80024DC8;
    // 0x80024DBC: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
L_80024DC0:
    // 0x80024DC0: addiu       $t0, $zero, 0x1E8
    ctx->r8 = ADD32(0, 0X1E8);
    // 0x80024DC4: sw          $t0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r8;
L_80024DC8:
    // 0x80024DC8: b           L_80024DD0
    // 0x80024DCC: nop

        goto L_80024DD0;
    // 0x80024DCC: nop

L_80024DD0:
    // 0x80024DD0: jr          $ra
    // 0x80024DD4: nop

    return;
    // 0x80024DD4: nop

;}
RECOMP_FUNC void _bamovehover_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084E38: syscall     138
    recomp_syscall_handler(rdram, ctx, 0x80084E38);
    return;
    // 0x80084E3C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080000C_chvandoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800018: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800020: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800024: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800028: addiu       $t8, $t7, 0xA08
    ctx->r24 = ADD32(ctx->r15, 0XA08);
    // 0x8080002C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80800030: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800034: jal         0x800EE7F8
    // 0x80800038: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800038: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x8080003C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800040: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800044: jal         0x800EE7F8
    // 0x80800048: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800048: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8080004C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800050: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800054: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800058: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8080005C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800060: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80800064: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x80800068: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8080006C: jal         0x800F54E4
    // 0x80800070: sw          $t9, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r25;
    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80800070: sw          $t9, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r25;
    after_2:
    // 0x80800074: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800078: jal         0x800F64A4
    // 0x8080007C: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    func_800F64A4(rdram, ctx);
        goto after_3;
    // 0x8080007C: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    after_3:
    // 0x80800080: bne         $v0, $zero, L_80800090
    if (ctx->r2 != 0) {
        // 0x80800084: nop
    
            goto L_80800090;
    }
    // 0x80800084: nop

    // 0x80800088: jal         0x800DA524
    // 0x8080008C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800DA524(rdram, ctx);
        goto after_4;
    // 0x8080008C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_4:
L_80800090:
    // 0x80800090: jal         0x800DA298
    // 0x80800094: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80800094: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80800098: beq         $v0, $zero, L_808000C0
    if (ctx->r2 == 0) {
        // 0x8080009C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000C0;
    }
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A4: jal         0x80800388
    // 0x808000A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800388_chvandoor(rdram, ctx);
        goto after_6;
    // 0x808000A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x808000AC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808000B0: jal         0x800EE7F8
    // 0x808000B4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x808000B4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x808000B8: b           L_808000CC
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808000CC;
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000C0:
    // 0x808000C0: jal         0x80800388
    // 0x808000C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800388_chvandoor(rdram, ctx);
        goto after_8;
    // 0x808000C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000CC:
    // 0x808000CC: jal         0x8010A800
    // 0x808000D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A800(rdram, ctx);
        goto after_9;
    // 0x808000D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808000D4: jal         0x800EA05C
    // 0x808000D8: nop

    func_800EA05C(rdram, ctx);
        goto after_10;
    // 0x808000D8: nop

    after_10:
    // 0x808000DC: addiu       $at, $zero, 0xE7
    ctx->r1 = ADD32(0, 0XE7);
    // 0x808000E0: bnel        $v0, $at, L_808000F4
    if (ctx->r2 != ctx->r1) {
        // 0x808000E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000F4;
    }
    goto skip_0;
    // 0x808000E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000E8: jal         0x8008A490
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
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

;}
RECOMP_FUNC void func_808001D4_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D4: blez        $a1, L_80800220
    if (SIGNED(ctx->r5) <= 0) {
        // 0x808001D8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800220;
    }
    // 0x808001D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808001DC: andi        $a3, $a1, 0x3
    ctx->r7 = ctx->r5 & 0X3;
    // 0x808001E0: beq         $a3, $zero, L_80800200
    if (ctx->r7 == 0) {
        // 0x808001E4: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_80800200;
    }
    // 0x808001E4: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x808001E8: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_808001EC:
    // 0x808001EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x808001F0: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x808001F4: bne         $a2, $v0, L_808001EC
    if (ctx->r6 != ctx->r2) {
        // 0x808001F8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_808001EC;
    }
    // 0x808001F8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808001FC: beq         $v0, $a1, L_80800220
    if (ctx->r2 == ctx->r5) {
        // 0x80800200: addu        $v1, $a0, $v0
        ctx->r3 = ADD32(ctx->r4, ctx->r2);
            goto L_80800220;
    }
L_80800200:
    // 0x80800200: addu        $v1, $a0, $v0
    ctx->r3 = ADD32(ctx->r4, ctx->r2);
L_80800204:
    // 0x80800204: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800208: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x8080020C: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x80800210: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x80800214: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800218: bne         $v0, $a1, L_80800204
    if (ctx->r2 != ctx->r5) {
        // 0x8080021C: sb          $zero, -0x4($v1)
        MEM_B(-0X4, ctx->r3) = 0;
            goto L_80800204;
    }
    // 0x8080021C: sb          $zero, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = 0;
L_80800220:
    // 0x80800220: jr          $ra
    // 0x80800224: nop

    return;
    // 0x80800224: nop

;}
RECOMP_FUNC void chexploder_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801824: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801828: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080182C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80801830: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801834: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801838: jal         0x80100094
    // 0x8080183C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080183C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801840: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801844: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801848: jal         0x80100094
    // 0x8080184C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080184C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80801850: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80801854: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80801858: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8080185C: lh          $t6, 0xE($t1)
    ctx->r14 = MEM_H(ctx->r9, 0XE);
    // 0x80801860: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80801864: blezl       $t6, L_808018DC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80801868: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808018DC;
    }
    goto skip_0;
    // 0x80801868: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080186C: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
L_80801870:
    // 0x80801870: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80801874: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80801878: beql        $a1, $t7, L_808018AC
    if (ctx->r5 == ctx->r15) {
        // 0x8080187C: lbu         $t3, 0x36($a2)
        ctx->r11 = MEM_BU(ctx->r6, 0X36);
            goto L_808018AC;
    }
    goto skip_1;
    // 0x8080187C: lbu         $t3, 0x36($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X36);
    skip_1:
    // 0x80801880: lbu         $a0, 0x39($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X39);
    // 0x80801884: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_80801888:
    // 0x80801888: bnel        $a0, $v1, L_8080189C
    if (ctx->r4 != ctx->r3) {
        // 0x8080188C: lh          $v1, 0x2($v0)
        ctx->r3 = MEM_H(ctx->r2, 0X2);
            goto L_8080189C;
    }
    goto skip_2;
    // 0x8080188C: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
    skip_2:
    // 0x80801890: b           L_808018A8
    // 0x80801894: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_808018A8;
    // 0x80801894: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80801898: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
L_8080189C:
    // 0x8080189C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x808018A0: bne         $a1, $v1, L_80801888
    if (ctx->r5 != ctx->r3) {
        // 0x808018A4: nop
    
            goto L_80801888;
    }
    // 0x808018A4: nop

L_808018A8:
    // 0x808018A8: lbu         $t3, 0x36($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X36);
L_808018AC:
    // 0x808018AC: sll         $t9, $t0, 6
    ctx->r25 = S32(ctx->r8 << 6);
    // 0x808018B0: andi        $t2, $t9, 0x40
    ctx->r10 = ctx->r25 & 0X40;
    // 0x808018B4: andi        $t4, $t3, 0xFFBF
    ctx->r12 = ctx->r11 & 0XFFBF;
    // 0x808018B8: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x808018BC: sb          $t5, 0x36($a2)
    MEM_B(0X36, ctx->r6) = ctx->r13;
    // 0x808018C0: lh          $t6, 0xE($t1)
    ctx->r14 = MEM_H(ctx->r9, 0XE);
    // 0x808018C4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x808018C8: addiu       $a2, $a2, 0x3C
    ctx->r6 = ADD32(ctx->r6, 0X3C);
    // 0x808018CC: slt         $at, $a3, $t6
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x808018D0: bnel        $at, $zero, L_80801870
    if (ctx->r1 != 0) {
        // 0x808018D4: lh          $t7, 0x0($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X0);
            goto L_80801870;
    }
    goto skip_3;
    // 0x808018D4: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    skip_3:
    // 0x808018D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808018DC:
    // 0x808018DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808018E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808018E4: jr          $ra
    // 0x808018E8: nop

    return;
    // 0x808018E8: nop

;}
RECOMP_FUNC void func_80802C64_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802C64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802C68: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802C6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802C70: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80802C74: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80802C78: jal         0x80100094
    // 0x80802C7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802C7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802C80: lui         $a1, 0x3F70
    ctx->r5 = S32(0X3F70 << 16);
    // 0x80802C84: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80802C88: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    // 0x80802C8C: jal         0x80105998
    // 0x80802C90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80105998(rdram, ctx);
        goto after_1;
    // 0x80802C90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80802C94: beq         $v0, $zero, L_80802CB8
    if (ctx->r2 == 0) {
        // 0x80802C98: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_80802CB8;
    }
    // 0x80802C98: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80802C9C: sb          $zero, 0xFE($t6)
    MEM_B(0XFE, ctx->r14) = 0;
    // 0x80802CA0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80802CA4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80802CA8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80802CAC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80802CB0: jal         0x808008DC
    // 0x80802CB4: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    func_808008DC_chclockworkmouse(rdram, ctx);
        goto after_2;
    // 0x80802CB4: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    after_2:
L_80802CB8:
    // 0x80802CB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802CBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802CC0: jr          $ra
    // 0x80802CC4: nop

    return;
    // 0x80802CC4: nop

;}
RECOMP_FUNC void func_80800000_idwibble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80800010: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80800014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800018: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8080001C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800020: nop

    // 0x80800024: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800028: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8080002C: lh          $t7, 0x2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2);
    // 0x80800030: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80800034: nop

    // 0x80800038: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080003C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80800040: lh          $t8, 0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4);
    // 0x80800044: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80800048: nop

    // 0x8080004C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800050: jal         0x800EEF94
    // 0x80800054: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    func_800EEF94(rdram, ctx);
        goto after_0;
    // 0x80800054: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x80800058: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8080005C: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800060: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800064: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80800068: mul.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8080006C: jal         0x800136D0
    // 0x80800070: nop

    func_800136D0(rdram, ctx);
        goto after_1;
    // 0x80800070: nop

    after_1:
    // 0x80800074: jal         0x800137D4
    // 0x80800078: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800137D4(rdram, ctx);
        goto after_2;
    // 0x80800078: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_2:
    // 0x8080007C: lh          $t9, 0x1A($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A);
    // 0x80800080: lbu         $t0, 0x33($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X33);
    // 0x80800084: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80800088: nop

    // 0x8080008C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800090: mul.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800094: beql        $t0, $zero, L_8080011C
    if (ctx->r8 == 0) {
        // 0x80800098: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080011C;
    }
    goto skip_0;
    // 0x80800098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080009C: jal         0x80013788
    // 0x808000A0: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    func_80013788(rdram, ctx);
        goto after_3;
    // 0x808000A0: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x808000A4: lh          $t1, 0x1A($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X1A);
    // 0x808000A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2938, 0X760) << 16);
    // 0x808000AC: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808000B0: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x808000B4: lwc1        $f10, 0x760($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2938, 0X760));
    // 0x808000B8: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808000BC: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808000C0: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808000C4: c.lt.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl < ctx->f14.fl;
    // 0x808000C8: mul.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808000CC: nop

    // 0x808000D0: mul.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x808000D4: bc1f        L_80800100
    if (!c1cs) {
        // 0x808000D8: lwc1        $f8, 0x28($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80800100;
    }
    // 0x808000D8: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808000DC: div.s       $f0, $f2, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f14.fl);
    // 0x808000E0: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808000E4: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x808000E8: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x808000EC: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x808000F0: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808000F4: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808000F8: b           L_80800118
    // 0x808000FC: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
        goto L_80800118;
    // 0x808000FC: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
L_80800100:
    // 0x80800100: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80800104: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x80800108: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8080010C: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800110: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80800114: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
L_80800118:
    // 0x80800118: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080011C:
    // 0x8080011C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800120: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800124: jr          $ra
    // 0x80800128: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x80800128: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
;}
RECOMP_FUNC void _ncfixposrot_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800891F8: syscall     767
    recomp_syscall_handler(rdram, ctx, 0x800891F8);
    return;
    // 0x800891FC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _sudeathmatch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A370: syscall     840
    recomp_syscall_handler(rdram, ctx, 0x8008A370);
    return;
    // 0x8008A374: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800000_chwaterfallgrillswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800010: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800014: bne         $a1, $at, L_80800034
    if (ctx->r5 != ctx->r1) {
        // 0x80800018: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80800034;
    }
    // 0x80800018: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8080001C: addiu       $a0, $zero, 0x11B
    ctx->r4 = ADD32(0, 0X11B);
    // 0x80800020: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800024: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800028: jal         0x80101180
    // 0x8080002C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80101180(rdram, ctx);
        goto after_0;
    // 0x8080002C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800030: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80800034:
    // 0x80800034: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800038: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8080003C: jal         0x80085820
    // 0x80800040: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80800040: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080004C: jr          $ra
    // 0x80800050: nop

    return;
    // 0x80800050: nop

;}
RECOMP_FUNC void baroll_setAngularVelocity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C554: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009C558: lw          $t6, 0xF4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XF4);
    // 0x8009C55C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8009C560: swc1        $f12, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f12.u32l;
    // 0x8009C564: lw          $t7, 0xF4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XF4);
    // 0x8009C568: jr          $ra
    // 0x8009C56C: swc1        $f14, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f14.u32l;
    return;
    // 0x8009C56C: swc1        $f14, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_800EE9EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE9EC: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x800EE9F0: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x800EE9F4: lw          $t9, 0x4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X4);
    // 0x800EE9F8: lw          $t0, 0x8($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X8);
    // 0x800EE9FC: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EEA00: mflo        $t8
    ctx->r24 = lo;
    // 0x800EEA04: nop

    // 0x800EEA08: nop

    // 0x800EEA0C: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EEA10: mflo        $t1
    ctx->r9 = lo;
    // 0x800EEA14: subu        $t2, $t8, $t1
    ctx->r10 = SUB32(ctx->r24, ctx->r9);
    // 0x800EEA18: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800EEA1C: nop

    // 0x800EEA20: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800EEA24: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800EEA28: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800EEA2C: lw          $t3, 0x8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X8);
    // 0x800EEA30: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800EEA34: lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X8);
    // 0x800EEA38: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EEA3C: mflo        $t5
    ctx->r13 = lo;
    // 0x800EEA40: nop

    // 0x800EEA44: nop

    // 0x800EEA48: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EEA4C: mflo        $t9
    ctx->r25 = lo;
    // 0x800EEA50: subu        $t0, $t5, $t9
    ctx->r8 = SUB32(ctx->r13, ctx->r25);
    // 0x800EEA54: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800EEA58: nop

    // 0x800EEA5C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800EEA60: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x800EEA64: lw          $t1, 0x4($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X4);
    // 0x800EEA68: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800EEA6C: lw          $t4, 0x4($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X4);
    // 0x800EEA70: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800EEA74: multu       $t8, $t1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EEA78: mflo        $t2
    ctx->r10 = lo;
    // 0x800EEA7C: nop

    // 0x800EEA80: nop

    // 0x800EEA84: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EEA88: mflo        $t6
    ctx->r14 = lo;
    // 0x800EEA8C: subu        $t7, $t2, $t6
    ctx->r15 = SUB32(ctx->r10, ctx->r14);
    // 0x800EEA90: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800EEA94: nop

    // 0x800EEA98: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800EEA9C: jr          $ra
    // 0x800EEAA0: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x800EEAA0: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_8011396C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011396C: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x80113970: jr          $ra
    // 0x80113974: sb          $a1, 0x14($t6)
    MEM_B(0X14, ctx->r14) = ctx->r5;
    return;
    // 0x80113974: sb          $a1, 0x14($t6)
    MEM_B(0X14, ctx->r14) = ctx->r5;
;}
