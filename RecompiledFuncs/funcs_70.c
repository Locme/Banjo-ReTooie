#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800254_chintroticker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080025C: lbu         $t6, 0x79($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X79);
    // 0x80800260: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x80800264: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x80800268: beq         $at, $zero, L_808002CC
    if (ctx->r1 == 0) {
        // 0x8080026C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_808002CC;
    }
    // 0x8080026C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800270: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1648, 0X804) << 16);
    // 0x80800274: addu        $at, $at, $t7
    gpr jr_addend_8080027C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800278: lw          $t7, 0x804($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1648, 0X804));
    // 0x8080027C: jr          $t7
    // 0x80800280: nop

    switch (jr_addend_8080027C >> 2) {
        case 0: goto L_808002CC; break;
        case 1: goto L_808002CC; break;
        case 2: goto L_80800284; break;
        case 3: goto L_80800294; break;
        case 4: goto L_808002AC; break;
        case 5: goto L_808002CC; break;
        default: switch_error(__func__, 0x8080027C, 0x80800804);
    }
    // 0x80800280: nop

L_80800284:
    // 0x80800284: jal         0x800DA524
    // 0x80800288: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    func_800DA524(rdram, ctx);
        goto after_0;
    // 0x80800288: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    after_0:
    // 0x8080028C: b           L_808002D0
    // 0x80800290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002D0;
    // 0x80800290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800294:
    // 0x80800294: jal         0x800DA544
    // 0x80800298: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800298: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    after_1:
    // 0x8080029C: jal         0x800DA524
    // 0x808002A0: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    func_800DA524(rdram, ctx);
        goto after_2;
    // 0x808002A0: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_2:
    // 0x808002A4: b           L_808002D0
    // 0x808002A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002D0;
    // 0x808002A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002AC:
    // 0x808002AC: jal         0x800DA524
    // 0x808002B0: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    func_800DA524(rdram, ctx);
        goto after_3;
    // 0x808002B0: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    after_3:
    // 0x808002B4: jal         0x800DA544
    // 0x808002B8: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x808002B8: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_4:
    // 0x808002BC: jal         0x800DA524
    // 0x808002C0: addiu       $a0, $zero, 0x1A5
    ctx->r4 = ADD32(0, 0X1A5);
    func_800DA524(rdram, ctx);
        goto after_5;
    // 0x808002C0: addiu       $a0, $zero, 0x1A5
    ctx->r4 = ADD32(0, 0X1A5);
    after_5:
    // 0x808002C4: jal         0x800DA544
    // 0x808002C8: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    func_800DA544(rdram, ctx);
        goto after_6;
    // 0x808002C8: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    after_6:
L_808002CC:
    // 0x808002CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002D0:
    // 0x808002D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002D4: jr          $ra
    // 0x808002D8: nop

    return;
    // 0x808002D8: nop

;}
RECOMP_FUNC void _chbaddiesetup_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086D60: syscall     449
    recomp_syscall_handler(rdram, ctx, 0x80086D60);
    return;
    // 0x80086D64: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80800C50_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800C54: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800C58: slti        $at, $a1, 0x41
    ctx->r1 = SIGNED(ctx->r5) < 0X41 ? 1 : 0;
    // 0x80800C5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800C60: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800C64: bne         $at, $zero, L_80800C88
    if (ctx->r1 != 0) {
        // 0x80800C68: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80800C88;
    }
    // 0x80800C68: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800C6C: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x80800C70: beq         $a1, $at, L_80800DC8
    if (ctx->r5 == ctx->r1) {
        // 0x80800C74: addiu       $at, $zero, 0x9F
        ctx->r1 = ADD32(0, 0X9F);
            goto L_80800DC8;
    }
    // 0x80800C74: addiu       $at, $zero, 0x9F
    ctx->r1 = ADD32(0, 0X9F);
    // 0x80800C78: beq         $a1, $at, L_80800E00
    if (ctx->r5 == ctx->r1) {
        // 0x80800C7C: nop
    
            goto L_80800E00;
    }
    // 0x80800C7C: nop

    // 0x80800C80: b           L_80800E18
    // 0x80800C84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800E18;
    // 0x80800C84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C88:
    // 0x80800C88: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x80800C8C: bne         $at, $zero, L_80800CB4
    if (ctx->r1 != 0) {
        // 0x80800C90: addiu       $t6, $a1, -0x2E
        ctx->r14 = ADD32(ctx->r5, -0X2E);
            goto L_80800CB4;
    }
    // 0x80800C90: addiu       $t6, $a1, -0x2E
    ctx->r14 = ADD32(ctx->r5, -0X2E);
    // 0x80800C94: sltiu       $at, $t6, 0x13
    ctx->r1 = ctx->r14 < 0X13 ? 1 : 0;
    // 0x80800C98: beq         $at, $zero, L_80800CC0
    if (ctx->r1 == 0) {
        // 0x80800C9C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800CC0;
    }
    // 0x80800C9C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800CA0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1060, 0X294C) << 16);
    // 0x80800CA4: addu        $at, $at, $t6
    gpr jr_addend_80800CAC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800CA8: lw          $t6, 0x294C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1060, 0X294C));
    // 0x80800CAC: jr          $t6
    // 0x80800CB0: nop

    switch (jr_addend_80800CAC >> 2) {
        case 0: goto L_80800D68; break;
        case 1: goto L_80800CC0; break;
        case 2: goto L_80800CC0; break;
        case 3: goto L_80800D84; break;
        case 4: goto L_80800CC0; break;
        case 5: goto L_80800CC0; break;
        case 6: goto L_80800CC0; break;
        case 7: goto L_80800CC0; break;
        case 8: goto L_80800CC0; break;
        case 9: goto L_80800CC0; break;
        case 10: goto L_80800CC0; break;
        case 11: goto L_80800CC0; break;
        case 12: goto L_80800CC0; break;
        case 13: goto L_80800CC0; break;
        case 14: goto L_80800CC0; break;
        case 15: goto L_80800DB8; break;
        case 16: goto L_80800CC0; break;
        case 17: goto L_80800CC8; break;
        case 18: goto L_80800CDC; break;
        default: switch_error(__func__, 0x80800CAC, 0x8080294C);
    }
    // 0x80800CB0: nop

L_80800CB4:
    // 0x80800CB4: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x80800CB8: beq         $a1, $v0, L_80800CF0
    if (ctx->r5 == ctx->r2) {
        // 0x80800CBC: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_80800CF0;
    }
    // 0x80800CBC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
L_80800CC0:
    // 0x80800CC0: b           L_80800E18
    // 0x80800CC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800E18;
    // 0x80800CC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800CC8:
    // 0x80800CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CCC: jal         0x80800E88
    // 0x80800CD0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80800E88_chdinoboss(rdram, ctx);
        goto after_0;
    // 0x80800CD0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_0:
    // 0x80800CD4: b           L_80800E18
    // 0x80800CD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800E18;
    // 0x80800CD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CDC:
    // 0x80800CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CE0: jal         0x80800F28
    // 0x80800CE4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80800F28_chdinoboss(rdram, ctx);
        goto after_1;
    // 0x80800CE4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80800CE8: b           L_80800E18
    // 0x80800CEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800E18;
    // 0x80800CEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CF0:
    // 0x80800CF0: beq         $t7, $v0, L_80800D08
    if (ctx->r15 == ctx->r2) {
        // 0x80800CF4: addiu       $at, $zero, 0x28
        ctx->r1 = ADD32(0, 0X28);
            goto L_80800D08;
    }
    // 0x80800CF4: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80800CF8: beq         $t7, $at, L_80800D24
    if (ctx->r15 == ctx->r1) {
        // 0x80800CFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D24;
    }
    // 0x80800CFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D00: b           L_80800E18
    // 0x80800D04: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800E18;
    // 0x80800D04: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800D08:
    // 0x80800D08: jal         0x80802500
    // 0x80800D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802500_chdinoboss(rdram, ctx);
        goto after_2;
    // 0x80800D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800D10: addiu       $a0, $zero, 0x112
    ctx->r4 = ADD32(0, 0X112);
    // 0x80800D14: jal         0x800887D8
    // 0x80800D18: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80800D18: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    after_3:
    // 0x80800D1C: b           L_80800E18
    // 0x80800D20: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800E18;
    // 0x80800D20: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800D24:
    // 0x80800D24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800D28: jal         0x8080248C
    // 0x80800D2C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_8080248C_chdinoboss(rdram, ctx);
        goto after_4;
    // 0x80800D2C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_4:
    // 0x80800D30: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800D34: addiu       $t8, $zero, 0x57
    ctx->r24 = ADD32(0, 0X57);
    // 0x80800D38: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800D3C: addiu       $a1, $zero, 0x17B3
    ctx->r5 = ADD32(0, 0X17B3);
    // 0x80800D40: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800D44: jal         0x8008A208
    // 0x80800D48: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80800D48: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x80800D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D50: jal         0x80800F70
    // 0x80800D54: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_6;
    // 0x80800D54: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x80800D58: b           L_80800E18
    // 0x80800D5C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800E18;
    // 0x80800D5C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80800D60: b           L_80800E18
    // 0x80800D64: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800E18;
    // 0x80800D64: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800D68:
    // 0x80800D68: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x80800D6C: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800D70: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800D74: jal         0x80801408
    // 0x80800D78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801408_chdinoboss(rdram, ctx);
        goto after_7;
    // 0x80800D78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800D7C: b           L_80800E18
    // 0x80800D80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800E18;
    // 0x80800D80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D84:
    // 0x80800D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D88: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x80800D8C: jal         0x8080248C
    // 0x80800D90: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_8080248C_chdinoboss(rdram, ctx);
        goto after_8;
    // 0x80800D90: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_8:
    // 0x80800D94: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800D98: addiu       $t9, $zero, 0x57
    ctx->r25 = ADD32(0, 0X57);
    // 0x80800D9C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800DA0: addiu       $a1, $zero, 0x17DF
    ctx->r5 = ADD32(0, 0X17DF);
    // 0x80800DA4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800DA8: jal         0x8008A208
    // 0x80800DAC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x80800DAC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x80800DB0: b           L_80800E18
    // 0x80800DB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800E18;
    // 0x80800DB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800DB8:
    // 0x80800DB8: jal         0x80801900
    // 0x80800DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801900_chdinoboss(rdram, ctx);
        goto after_10;
    // 0x80800DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800DC0: b           L_80800E18
    // 0x80800DC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800E18;
    // 0x80800DC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800DC8:
    // 0x80800DC8: jal         0x800D395C
    // 0x80800DCC: nop

    func_800D395C(rdram, ctx);
        goto after_11;
    // 0x80800DCC: nop

    after_11:
    // 0x80800DD0: bne         $v0, $zero, L_80800DE0
    if (ctx->r2 != 0) {
        // 0x80800DD4: addiu       $a1, $zero, 0xCEB
        ctx->r5 = ADD32(0, 0XCEB);
            goto L_80800DE0;
    }
    // 0x80800DD4: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x80800DD8: b           L_80800E18
    // 0x80800DDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800E18;
    // 0x80800DDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800DE0:
    // 0x80800DE0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800DE4: addiu       $t0, $zero, 0x57
    ctx->r8 = ADD32(0, 0X57);
    // 0x80800DE8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800DEC: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    // 0x80800DF0: jal         0x8008A208
    // 0x80800DF4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_12;
    // 0x80800DF4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_12:
    // 0x80800DF8: b           L_80800E18
    // 0x80800DFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800E18;
    // 0x80800DFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E00:
    // 0x80800E00: jal         0x800FDC28
    // 0x80800E04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_13;
    // 0x80800E04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x80800E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E0C: jal         0x80800F70
    // 0x80800E10: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_14;
    // 0x80800E10: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_14:
    // 0x80800E14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E18:
    // 0x80800E18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800E1C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800E20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800E24: jr          $ra
    // 0x80800E28: nop

    return;
    // 0x80800E28: nop

;}
RECOMP_FUNC void func_808000D4_bskazhatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000DC: jal         0x800832E0
    // 0x808000E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808000E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000EC: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
    // 0x808000F0: jal         0x80800000
    // 0x808000F4: sw          $zero, 0x160($a0)
    MEM_W(0X160, ctx->r4) = 0;
    func_80800000_bskazhatch(rdram, ctx);
        goto after_1;
    // 0x808000F4: sw          $zero, 0x160($a0)
    MEM_W(0X160, ctx->r4) = 0;
    after_1:
    // 0x808000F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800100: jr          $ra
    // 0x80800104: nop

    return;
    // 0x80800104: nop

;}
RECOMP_FUNC void _bastatemem_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085168: syscall     153
    recomp_syscall_handler(rdram, ctx, 0x80085168);
    return;
    // 0x8008516C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void chfantasyonion_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800718: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2396, 0X754) << 16);
    // 0x8080071C: jr          $ra
    // 0x80800720: addiu       $v0, $v0, 0x754
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2396, 0X754));
    return;
    // 0x80800720: addiu       $v0, $v0, 0x754
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2396, 0X754));
    // 0x80800724: nop

    // 0x80800728: nop

    // 0x8080072C: nop

;}
RECOMP_FUNC void _basnowball_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085130: syscall     151
    recomp_syscall_handler(rdram, ctx, 0x80085130);
    return;
    // 0x80085134: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void bsbeemain_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007B0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808007B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(80, 0X1280) << 16);
    // 0x808007B8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808007BC: jr          $ra
    // 0x808007C0: lw          $v0, 0x1280($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(80, 0X1280));
    return;
    // 0x808007C0: lw          $v0, 0x1280($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(80, 0X1280));
;}
RECOMP_FUNC void func_80800680_chhellterskelter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800680: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800684: addiu       $at, $zero, 0x210
    ctx->r1 = ADD32(0, 0X210);
    // 0x80800688: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080068C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800690: beq         $a1, $at, L_808006FC
    if (ctx->r5 == ctx->r1) {
        // 0x80800694: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_808006FC;
    }
    // 0x80800694: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800698: addiu       $at, $zero, 0x33A
    ctx->r1 = ADD32(0, 0X33A);
    // 0x8080069C: bne         $a1, $at, L_80800788
    if (ctx->r5 != ctx->r1) {
        // 0x808006A0: or          $t7, $a0, $zero
        ctx->r15 = ctx->r4 | 0;
            goto L_80800788;
    }
    // 0x808006A0: or          $t7, $a0, $zero
    ctx->r15 = ctx->r4 | 0;
    // 0x808006A4: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x808006A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808006AC: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x808006B0: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x808006B4: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x808006B8: lwc1        $f6, 0x48($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X48);
    // 0x808006BC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808006C0: addiu       $a1, $t7, 0x18
    ctx->r5 = ADD32(ctx->r15, 0X18);
    // 0x808006C4: jal         0x8010856C
    // 0x808006C8: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    func_8010856C(rdram, ctx);
        goto after_0;
    // 0x808006C8: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x808006CC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808006D0: jal         0x80106790
    // 0x808006D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808006D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808006D8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808006DC: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    // 0x808006E0: jal         0x80102FDC
    // 0x808006E4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80102FDC(rdram, ctx);
        goto after_2;
    // 0x808006E4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x808006E8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808006EC: jal         0x80105A9C
    // 0x808006F0: lui         $a1, 0x442F
    ctx->r5 = S32(0X442F << 16);
    func_80105A9C(rdram, ctx);
        goto after_3;
    // 0x808006F0: lui         $a1, 0x442F
    ctx->r5 = S32(0X442F << 16);
    after_3:
    // 0x808006F4: b           L_8080078C
    // 0x808006F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080078C;
    // 0x808006F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808006FC:
    // 0x808006FC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800700: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800704: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800708: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // 0x8080070C: jal         0x80108528
    // 0x80800710: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_80108528(rdram, ctx);
        goto after_4;
    // 0x80800710: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_4:
    // 0x80800714: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800718: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080071C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800720: jal         0x80102FDC
    // 0x80800724: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80102FDC(rdram, ctx);
        goto after_5;
    // 0x80800724: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80800728: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8080072C: lw          $t0, 0x64($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X64);
    // 0x80800730: sll         $t2, $t0, 11
    ctx->r10 = S32(ctx->r8 << 11);
    // 0x80800734: bgezl       $t2, L_8080075C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800738: lw          $t3, 0x30($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X30);
            goto L_8080075C;
    }
    goto skip_0;
    // 0x80800738: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x8080073C: jal         0x80089CA0
    // 0x80800740: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _subaddiefade_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800740: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_6:
    // 0x80800744: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800748: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x8080074C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800750: jal         0x800862D8
    // 0x80800754: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    _chappearfx_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80800754: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_7:
    // 0x80800758: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
L_8080075C:
    // 0x8080075C: lbu         $t4, 0x65($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X65);
    // 0x80800760: andi        $t5, $t4, 0xFFEF
    ctx->r13 = ctx->r12 & 0XFFEF;
    // 0x80800764: sb          $t5, 0x65($t3)
    MEM_B(0X65, ctx->r11) = ctx->r13;
    // 0x80800768: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8080076C: lbu         $t7, 0x65($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X65);
    // 0x80800770: ori         $t9, $t7, 0x8
    ctx->r25 = ctx->r15 | 0X8;
    // 0x80800774: sb          $t9, 0x65($t6)
    MEM_B(0X65, ctx->r14) = ctx->r25;
    // 0x80800778: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8080077C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80800780: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80800784: sw          $t1, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = ctx->r9;
L_80800788:
    // 0x80800788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080078C:
    // 0x8080078C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800790: jr          $ra
    // 0x80800794: nop

    return;
    // 0x80800794: nop

    // 0x80800798: nop

    // 0x8080079C: nop

;}
RECOMP_FUNC void func_808002C8_chmermaidstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002D0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808002D4: addiu       $t7, $zero, 0x18D
    ctx->r15 = ADD32(0, 0X18D);
    // 0x808002D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808002DC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808002E0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808002E4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808002E8: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x808002EC: jal         0x80086898
    // 0x808002F0: lui         $a3, 0x43C8
    ctx->r7 = S32(0X43C8 << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808002F0: lui         $a3, 0x43C8
    ctx->r7 = S32(0X43C8 << 16);
    after_0:
    // 0x808002F4: beq         $v0, $zero, L_8080031C
    if (ctx->r2 == 0) {
        // 0x808002F8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8080031C;
    }
    // 0x808002F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808002FC: jal         0x800868C0
    // 0x80800300: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800300: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_1:
    // 0x80800304: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800308: jal         0x800868A8
    // 0x8080030C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x8080030C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_2:
    // 0x80800310: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800314: jal         0x800868B0
    // 0x80800318: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80800318: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_3:
L_8080031C:
    // 0x8080031C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800320: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800324: jr          $ra
    // 0x80800328: nop

    return;
    // 0x80800328: nop

    // 0x8080032C: nop

;}
RECOMP_FUNC void gczoombox_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803440: lbu         $t6, 0x177($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X177);
    // 0x80803444: andi        $t7, $t6, 0xF7
    ctx->r15 = ctx->r14 & 0XF7;
    // 0x80803448: jr          $ra
    // 0x8080344C: sb          $t7, 0x177($a0)
    MEM_B(0X177, ctx->r4) = ctx->r15;
    return;
    // 0x8080344C: sb          $t7, 0x177($a0)
    MEM_B(0X177, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_800A8BA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8BA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A8BAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A8BB0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800A8BB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A8BB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A8BBC: jal         0x800E7E70
    // 0x800A8BC0: sw          $t6, 0x7674($at)
    MEM_W(0X7674, ctx->r1) = ctx->r14;
    func_800E7E70(rdram, ctx);
        goto after_0;
    // 0x800A8BC0: sw          $t6, 0x7674($at)
    MEM_W(0X7674, ctx->r1) = ctx->r14;
    after_0:
    // 0x800A8BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A8BC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A8BCC: jr          $ra
    // 0x800A8BD0: nop

    return;
    // 0x800A8BD0: nop

;}
RECOMP_FUNC void func_8080105C_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080105C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80801060: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80801064: addu        $fp, $a0, $a1
    ctx->r30 = ADD32(ctx->r4, ctx->r5);
    // 0x80801068: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8080106C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80801070: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80801074: slt         $at, $a0, $fp
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x80801078: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x8080107C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80801080: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80801084: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80801088: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8080108C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80801090: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801094: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80801098: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8080109C: beq         $at, $zero, L_80801188
    if (ctx->r1 == 0) {
        // 0x808010A0: or          $s5, $a0, $zero
        ctx->r21 = ctx->r4 | 0;
            goto L_80801188;
    }
    // 0x808010A0: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x808010A4: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2658, 0X20D8) << 16);
    // 0x808010A8: addiu       $t7, $t7, 0x20D8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2658, 0X20D8));
    // 0x808010AC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808010B0: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
L_808010B4:
    // 0x808010B4: lbu         $a0, 0x3($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X3);
    // 0x808010B8: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x808010BC: beq         $a0, $at, L_808010D4
    if (ctx->r4 == ctx->r1) {
        // 0x808010C0: nop
    
            goto L_808010D4;
    }
    // 0x808010C0: nop

    // 0x808010C4: jal         0x800C6E38
    // 0x808010C8: nop

    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x808010C8: nop

    after_0:
    // 0x808010CC: beql        $v0, $zero, L_80801180
    if (ctx->r2 == 0) {
        // 0x808010D0: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_80801180;
    }
    goto skip_0;
    // 0x808010D0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_0:
L_808010D4:
    // 0x808010D4: jal         0x800D1A04
    // 0x808010D8: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    func_800D1A04(rdram, ctx);
        goto after_1;
    // 0x808010D8: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    after_1:
    // 0x808010DC: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x808010E0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808010E4: beql        $t8, $zero, L_808010F8
    if (ctx->r24 == 0) {
        // 0x808010E8: lbu         $s3, 0x2($s1)
        ctx->r19 = MEM_BU(ctx->r17, 0X2);
            goto L_808010F8;
    }
    goto skip_1;
    // 0x808010E8: lbu         $s3, 0x2($s1)
    ctx->r19 = MEM_BU(ctx->r17, 0X2);
    skip_1:
    // 0x808010EC: beql        $v0, $zero, L_80801180
    if (ctx->r2 == 0) {
        // 0x808010F0: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_80801180;
    }
    goto skip_2;
    // 0x808010F0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_2:
    // 0x808010F4: lbu         $s3, 0x2($s1)
    ctx->r19 = MEM_BU(ctx->r17, 0X2);
L_808010F8:
    // 0x808010F8: jal         0x800D1C5C
    // 0x808010FC: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    func_800D1C5C(rdram, ctx);
        goto after_2;
    // 0x808010FC: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    after_2:
    // 0x80801100: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80801104: jal         0x800D27A4
    // 0x80801108: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D27A4(rdram, ctx);
        goto after_3;
    // 0x80801108: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x8080110C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801110: jal         0x800D28E8
    // 0x80801114: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800D28E8(rdram, ctx);
        goto after_4;
    // 0x80801114: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_4:
    // 0x80801118: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080111C: bne         $v0, $at, L_8080115C
    if (ctx->r2 != ctx->r1) {
        // 0x80801120: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_8080115C;
    }
    // 0x80801120: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80801124: jal         0x800D1A6C
    // 0x80801128: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    func_800D1A6C(rdram, ctx);
        goto after_5;
    // 0x80801128: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    after_5:
    // 0x8080112C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80801130: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80801134: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801138: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080113C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80801140: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80801144: jal         0x80801844
    // 0x80801148: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    func_80801844_gcnewpause(rdram, ctx);
        goto after_6;
    // 0x80801148: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    after_6:
    // 0x8080114C: beql        $v0, $zero, L_80801180
    if (ctx->r2 == 0) {
        // 0x80801150: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_80801180;
    }
    goto skip_3;
    // 0x80801150: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_3:
    // 0x80801154: b           L_8080117C
    // 0x80801158: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
        goto L_8080117C;
    // 0x80801158: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_8080115C:
    // 0x8080115C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801160: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80801164: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801168: jal         0x8080190C
    // 0x8080116C: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    func_8080190C_gcnewpause(rdram, ctx);
        goto after_7;
    // 0x8080116C: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    after_7:
    // 0x80801170: beql        $v0, $zero, L_80801180
    if (ctx->r2 == 0) {
        // 0x80801174: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_80801180;
    }
    goto skip_4;
    // 0x80801174: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_4:
    // 0x80801178: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_8080117C:
    // 0x8080117C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_80801180:
    // 0x80801180: bne         $s5, $fp, L_808010B4
    if (ctx->r21 != ctx->r30) {
        // 0x80801184: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_808010B4;
    }
    // 0x80801184: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80801188:
    // 0x80801188: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8080118C: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
    // 0x80801190: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80801194: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801198: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8080119C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808011A0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x808011A4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x808011A8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x808011AC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x808011B0: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x808011B4: jr          $ra
    // 0x808011B8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x808011B8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void _badata_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084710: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x80084710);
    return;
    // 0x80084714: addi        $t0, $zero, 0x68
    ctx->r8 = ADD32(0, 0X68);
;}
RECOMP_FUNC void _bsbtrot_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082BD8: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082BD8);
    return;
    // 0x80082BDC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800000_ncpoducam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800008: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: jal         0x800EFD24
    // 0x80800014: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800018: jal         0x800EFD24
    // 0x8080001C: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x8080001C: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    after_1:
    // 0x80800020: jal         0x800EFD24
    // 0x80800024: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x80800024: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    after_2:
    // 0x80800028: jal         0x800EFD24
    // 0x8080002C: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    func_800EFD24(rdram, ctx);
        goto after_3;
    // 0x8080002C: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    after_3:
    // 0x80800030: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800034: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800038: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080003C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800040: sb          $zero, 0x63($s0)
    MEM_B(0X63, ctx->r16) = 0;
    // 0x80800044: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x80800048: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    // 0x8080004C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800050: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800054: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800058: jr          $ra
    // 0x8080005C: nop

    return;
    // 0x8080005C: nop

;}
RECOMP_FUNC void _chjinjo_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086BA0: syscall     425
    recomp_syscall_handler(rdram, ctx, 0x80086BA0);
    return;
    // 0x80086BA4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800028_badeathmatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800028: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(657, 0X54F) << 16);
    // 0x8080002C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80800030: jr          $ra
    // 0x80800034: lbu         $v0, 0x54F($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(657, 0X54F));
    return;
    // 0x80800034: lbu         $v0, 0x54F($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(657, 0X54F));
;}
RECOMP_FUNC void _bawobble_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085450: syscall     162
    recomp_syscall_handler(rdram, ctx, 0x80085450);
    return;
    // 0x80085454: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80806834_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806834: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80806838: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080683C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80806840: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80806844: lw          $a0, 0x30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30);
    // 0x80806848: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8080684C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80806850: addiu       $a1, $zero, 0x18F0
    ctx->r5 = ADD32(0, 0X18F0);
    // 0x80806854: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80806858: jal         0x80802AD4
    // 0x8080685C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80802AD4_chgameselect(rdram, ctx);
        goto after_0;
    // 0x8080685C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80806860: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80806864: jal         0x80802D04
    // 0x80806868: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80802D04_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80806868: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080686C: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x80806870: jal         0x808026C8
    // 0x80806874: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808026C8_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80806874: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_2:
    // 0x80806878: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x8080687C: addiu       $a1, $zero, 0x18F0
    ctx->r5 = ADD32(0, 0X18F0);
    // 0x80806880: jal         0x80802640
    // 0x80806884: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80802640_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80806884: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80806888: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x8080688C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80806890: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x80806894: sw          $t8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r24;
    // 0x80806898: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080689C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808068A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808068A4: jr          $ra
    // 0x808068A8: nop

    return;
    // 0x808068A8: nop

;}
RECOMP_FUNC void func_808002E4_chfactoryworkerwear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002EC: jal         0x80100094
    // 0x808002F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808002F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002F4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808002F8: jal         0x80101038
    // 0x808002FC: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    func_80101038(rdram, ctx);
        goto after_1;
    // 0x808002FC: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    after_1:
    // 0x80800300: jal         0x80101068
    // 0x80800304: nop

    func_80101068(rdram, ctx);
        goto after_2;
    // 0x80800304: nop

    after_2:
    // 0x80800308: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8080030C: swc1        $f0, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f0.u32l;
    // 0x80800310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800314: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800318: jr          $ra
    // 0x8080031C: nop

    return;
    // 0x8080031C: nop

;}
RECOMP_FUNC void gcboundDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080004C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800050: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800054: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800058: jal         0x8001ACCC
    // 0x8080005C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x8080005C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80800060: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800064: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800068: jal         0x8001ACCC
    // 0x8080006C: sw          $v0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r2;
    heap_alloc(rdram, ctx);
        goto after_1;
    // 0x8080006C: sw          $v0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r2;
    after_1:
    // 0x80800070: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800074: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800078: jal         0x8001ACCC
    // 0x8080007C: sw          $v0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r2;
    heap_alloc(rdram, ctx);
        goto after_2;
    // 0x8080007C: sw          $v0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r2;
    after_2:
    // 0x80800080: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800084: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80800088: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8080008C: jal         0x800B42FC
    // 0x80800090: sw          $v0, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r2;
    func_800B42FC(rdram, ctx);
        goto after_3;
    // 0x80800090: sw          $v0, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r2;
    after_3:
    // 0x80800094: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80800098: sw          $v0, 0xE0($t9)
    MEM_W(0XE0, ctx->r25) = ctx->r2;
    // 0x8080009C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A4: jr          $ra
    // 0x808000A8: nop

    return;
    // 0x808000A8: nop

;}
RECOMP_FUNC void babackpack_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004BC: jal         0x8080053C
    // 0x808004C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    babackpack_set_state(rdram, ctx);
        goto after_0;
    // 0x808004C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808004C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004CC: jr          $ra
    // 0x808004D0: nop

    return;
    // 0x808004D0: nop

;}
RECOMP_FUNC void func_80800A50_gcdialogexec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A50: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800A54: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800A58: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800A5C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800A60: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800A64: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800A68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A6C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80800A70: lbu         $t6, 0x15C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X15C);
    // 0x80800A74: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80800A78: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800A7C: bne         $v0, $t6, L_80800A88
    if (ctx->r2 != ctx->r14) {
        // 0x80800A80: lw          $t8, 0x4C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X4C);
            goto L_80800A88;
    }
    // 0x80800A80: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80800A84: beq         $a1, $v0, L_80800D10
    if (ctx->r5 == ctx->r2) {
        // 0x80800A88: addiu       $t9, $t8, -0x1
        ctx->r25 = ADD32(ctx->r24, -0X1);
            goto L_80800D10;
    }
L_80800A88:
    // 0x80800A88: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80800A8C: sltiu       $at, $t9, 0xB
    ctx->r1 = ctx->r25 < 0XB ? 1 : 0;
    // 0x80800A90: beq         $at, $zero, L_80800D08
    if (ctx->r1 == 0) {
        // 0x80800A94: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80800D08;
    }
    // 0x80800A94: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800A98: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2594, 0X2E34) << 16);
    // 0x80800A9C: addu        $at, $at, $t9
    gpr jr_addend_80800AA4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800AA0: lw          $t9, 0x2E34($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2594, 0X2E34));
    // 0x80800AA4: jr          $t9
    // 0x80800AA8: nop

    switch (jr_addend_80800AA4 >> 2) {
        case 0: goto L_80800AAC; break;
        case 1: goto L_80800D08; break;
        case 2: goto L_80800D08; break;
        case 3: goto L_80800D08; break;
        case 4: goto L_80800B04; break;
        case 5: goto L_80800B70; break;
        case 6: goto L_80800C80; break;
        case 7: goto L_80800C90; break;
        case 8: goto L_80800D08; break;
        case 9: goto L_80800CDC; break;
        case 10: goto L_80800D00; break;
        default: switch_error(__func__, 0x80800AA4, 0x80802E34);
    }
    // 0x80800AA8: nop

L_80800AAC:
    // 0x80800AAC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800AB0: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    // 0x80800AB4: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_80800AB8:
    // 0x80800AB8: lw          $a0, 0x120($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X120);
    // 0x80800ABC: addu        $s0, $s4, $s2
    ctx->r16 = ADD32(ctx->r20, ctx->r18);
    // 0x80800AC0: beql        $a0, $zero, L_80800AF0
    if (ctx->r4 == 0) {
        // 0x80800AC4: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80800AF0;
    }
    goto skip_0;
    // 0x80800AC4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x80800AC8: lbu         $v0, 0x11C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X11C);
    // 0x80800ACC: srl         $t0, $v0, 6
    ctx->r8 = S32(U32(ctx->r2) >> 6);
    // 0x80800AD0: bnel        $t0, $zero, L_80800AE8
    if (ctx->r8 != 0) {
        // 0x80800AD4: andi        $t1, $v0, 0xFF3F
        ctx->r9 = ctx->r2 & 0XFF3F;
            goto L_80800AE8;
    }
    goto skip_1;
    // 0x80800AD4: andi        $t1, $v0, 0xFF3F
    ctx->r9 = ctx->r2 & 0XFF3F;
    skip_1:
    // 0x80800AD8: jal         0x80087B28
    // 0x80800ADC: nop

    _gczoombox_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800ADC: nop

    after_0:
    // 0x80800AE0: lbu         $v0, 0x11C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X11C);
    // 0x80800AE4: andi        $t1, $v0, 0xFF3F
    ctx->r9 = ctx->r2 & 0XFF3F;
L_80800AE8:
    // 0x80800AE8: sb          $t1, 0x11C($s0)
    MEM_B(0X11C, ctx->r16) = ctx->r9;
    // 0x80800AEC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80800AF0:
    // 0x80800AF0: bne         $s2, $s3, L_80800AB8
    if (ctx->r18 != ctx->r19) {
        // 0x80800AF4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80800AB8;
    }
    // 0x80800AF4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800AF8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80800AFC: b           L_80800D08
    // 0x80800B00: sb          $t2, 0x158($s4)
    MEM_B(0X158, ctx->r20) = ctx->r10;
        goto L_80800D08;
    // 0x80800B00: sb          $t2, 0x158($s4)
    MEM_B(0X158, ctx->r20) = ctx->r10;
L_80800B04:
    // 0x80800B04: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800B08: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    // 0x80800B0C: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_80800B10:
    // 0x80800B10: lw          $a0, 0x120($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X120);
    // 0x80800B14: addu        $t3, $s4, $s2
    ctx->r11 = ADD32(ctx->r20, ctx->r18);
    // 0x80800B18: beql        $a0, $zero, L_80800B44
    if (ctx->r4 == 0) {
        // 0x80800B1C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80800B44;
    }
    goto skip_2;
    // 0x80800B1C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_2:
    // 0x80800B20: lbu         $t4, 0x11C($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X11C);
    // 0x80800B24: srl         $t5, $t4, 6
    ctx->r13 = S32(U32(ctx->r12) >> 6);
    // 0x80800B28: bnel        $t5, $zero, L_80800B44
    if (ctx->r13 != 0) {
        // 0x80800B2C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80800B44;
    }
    goto skip_3;
    // 0x80800B2C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_3:
    // 0x80800B30: jal         0x80087B40
    // 0x80800B34: nop

    _gczoombox_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x80800B34: nop

    after_1:
    // 0x80800B38: jal         0x80087B30
    // 0x80800B3C: lw          $a0, 0x120($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X120);
    _gczoombox_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800B3C: lw          $a0, 0x120($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X120);
    after_2:
    // 0x80800B40: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80800B44:
    // 0x80800B44: bne         $s2, $s3, L_80800B10
    if (ctx->r18 != ctx->r19) {
        // 0x80800B48: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80800B10;
    }
    // 0x80800B48: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800B4C: lw          $a0, 0x12C($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X12C);
    // 0x80800B50: beql        $a0, $zero, L_80800D0C
    if (ctx->r4 == 0) {
        // 0x80800B54: lw          $t8, 0x4C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X4C);
            goto L_80800D0C;
    }
    goto skip_4;
    // 0x80800B54: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    skip_4:
    // 0x80800B58: jal         0x80087B40
    // 0x80800B5C: nop

    _gczoombox_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x80800B5C: nop

    after_3:
    // 0x80800B60: jal         0x80087B30
    // 0x80800B64: lw          $a0, 0x12C($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X12C);
    _gczoombox_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x80800B64: lw          $a0, 0x12C($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X12C);
    after_4:
    // 0x80800B68: b           L_80800D0C
    // 0x80800B6C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
        goto L_80800D0C;
    // 0x80800B6C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
L_80800B70:
    // 0x80800B70: lbu         $t7, 0x15E($s4)
    ctx->r15 = MEM_BU(ctx->r20, 0X15E);
    // 0x80800B74: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80800B78: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800B7C: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x80800B80: jal         0x8080064C
    // 0x80800B84: sb          $t8, 0x15E($s4)
    MEM_B(0X15E, ctx->r20) = ctx->r24;
    func_8080064C_gcdialogexec(rdram, ctx);
        goto after_5;
    // 0x80800B84: sb          $t8, 0x15E($s4)
    MEM_B(0X15E, ctx->r20) = ctx->r24;
    after_5:
    // 0x80800B88: beq         $v0, $zero, L_80800BAC
    if (ctx->r2 == 0) {
        // 0x80800B8C: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80800BAC;
    }
    // 0x80800B8C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_80800B90:
    // 0x80800B90: bne         $at, $zero, L_80800B9C
    if (ctx->r1 != 0) {
        // 0x80800B94: nop
    
            goto L_80800B9C;
    }
    // 0x80800B94: nop

    // 0x80800B98: addiu       $s0, $v0, -0x1
    ctx->r16 = ADD32(ctx->r2, -0X1);
L_80800B9C:
    // 0x80800B9C: jal         0x8080064C
    // 0x80800BA0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8080064C_gcdialogexec(rdram, ctx);
        goto after_6;
    // 0x80800BA0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_6:
    // 0x80800BA4: bnel        $v0, $zero, L_80800B90
    if (ctx->r2 != 0) {
        // 0x80800BA8: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80800B90;
    }
    goto skip_5;
    // 0x80800BA8: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    skip_5:
L_80800BAC:
    // 0x80800BAC: jal         0x8080064C
    // 0x80800BB0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8080064C_gcdialogexec(rdram, ctx);
        goto after_7;
    // 0x80800BB0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_7:
    // 0x80800BB4: beq         $v0, $zero, L_80800BD8
    if (ctx->r2 == 0) {
        // 0x80800BB8: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80800BD8;
    }
    // 0x80800BB8: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_80800BBC:
    // 0x80800BBC: bne         $at, $zero, L_80800BC8
    if (ctx->r1 != 0) {
        // 0x80800BC0: nop
    
            goto L_80800BC8;
    }
    // 0x80800BC0: nop

    // 0x80800BC4: addiu       $s0, $v0, -0x1
    ctx->r16 = ADD32(ctx->r2, -0X1);
L_80800BC8:
    // 0x80800BC8: jal         0x8080064C
    // 0x80800BCC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8080064C_gcdialogexec(rdram, ctx);
        goto after_8;
    // 0x80800BCC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_8:
    // 0x80800BD0: bnel        $v0, $zero, L_80800BBC
    if (ctx->r2 != 0) {
        // 0x80800BD4: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80800BBC;
    }
    goto skip_6;
    // 0x80800BD4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    skip_6:
L_80800BD8:
    // 0x80800BD8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800BDC: beql        $s0, $at, L_80800C08
    if (ctx->r16 == ctx->r1) {
        // 0x80800BE0: lbu         $t1, 0x15F($s4)
        ctx->r9 = MEM_BU(ctx->r20, 0X15F);
            goto L_80800C08;
    }
    goto skip_7;
    // 0x80800BE0: lbu         $t1, 0x15F($s4)
    ctx->r9 = MEM_BU(ctx->r20, 0X15F);
    skip_7:
    // 0x80800BE4: lhu         $t9, 0x15A($s4)
    ctx->r25 = MEM_HU(ctx->r20, 0X15A);
    // 0x80800BE8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800BEC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800BF0: andi        $t0, $t9, 0x200
    ctx->r8 = ctx->r25 & 0X200;
    // 0x80800BF4: bnel        $t0, $zero, L_80800C08
    if (ctx->r8 != 0) {
        // 0x80800BF8: lbu         $t1, 0x15F($s4)
        ctx->r9 = MEM_BU(ctx->r20, 0X15F);
            goto L_80800C08;
    }
    goto skip_8;
    // 0x80800BF8: lbu         $t1, 0x15F($s4)
    ctx->r9 = MEM_BU(ctx->r20, 0X15F);
    skip_8:
    // 0x80800BFC: jal         0x800880C8
    // 0x80800C00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _gcdialogcamera_entrypoint_10(rdram, ctx);
        goto after_9;
    // 0x80800C00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x80800C04: lbu         $t1, 0x15F($s4)
    ctx->r9 = MEM_BU(ctx->r20, 0X15F);
L_80800C08:
    // 0x80800C08: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800C0C: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    // 0x80800C10: andi        $t2, $t1, 0xFFFC
    ctx->r10 = ctx->r9 & 0XFFFC;
    // 0x80800C14: sb          $t2, 0x15F($s4)
    MEM_B(0X15F, ctx->r20) = ctx->r10;
    // 0x80800C18: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x80800C1C: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
L_80800C20:
    // 0x80800C20: lbu         $t3, 0x11C($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X11C);
    // 0x80800C24: andi        $t4, $t3, 0xFF3F
    ctx->r12 = ctx->r11 & 0XFF3F;
    // 0x80800C28: sb          $t4, 0x11C($s0)
    MEM_B(0X11C, ctx->r16) = ctx->r12;
    // 0x80800C2C: lw          $a0, 0x120($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X120);
    // 0x80800C30: beql        $a0, $zero, L_80800C64
    if (ctx->r4 == 0) {
        // 0x80800C34: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80800C64;
    }
    goto skip_9;
    // 0x80800C34: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_9:
    // 0x80800C38: jal         0x80087BE8
    // 0x80800C3C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    _gczoombox_entrypoint_33(rdram, ctx);
        goto after_10;
    // 0x80800C3C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_10:
    // 0x80800C40: lw          $t6, 0x15C($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X15C);
    // 0x80800C44: lbu         $t0, 0x15F($s4)
    ctx->r8 = MEM_BU(ctx->r20, 0X15F);
    // 0x80800C48: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80800C4C: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x80800C50: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x80800C54: andi        $t1, $t0, 0xFFFC
    ctx->r9 = ctx->r8 & 0XFFFC;
    // 0x80800C58: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80800C5C: sb          $t2, 0x15F($s4)
    MEM_B(0X15F, ctx->r20) = ctx->r10;
    // 0x80800C60: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80800C64:
    // 0x80800C64: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800C68: bne         $v1, $s2, L_80800C20
    if (ctx->r3 != ctx->r18) {
        // 0x80800C6C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800C20;
    }
    // 0x80800C6C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800C70: lbu         $t3, 0x15E($s4)
    ctx->r11 = MEM_BU(ctx->r20, 0X15E);
    // 0x80800C74: andi        $t4, $t3, 0xFFFB
    ctx->r12 = ctx->r11 & 0XFFFB;
    // 0x80800C78: b           L_80800D08
    // 0x80800C7C: sb          $t4, 0x15E($s4)
    MEM_B(0X15E, ctx->r20) = ctx->r12;
        goto L_80800D08;
    // 0x80800C7C: sb          $t4, 0x15E($s4)
    MEM_B(0X15E, ctx->r20) = ctx->r12;
L_80800C80:
    // 0x80800C80: jal         0x808001DC
    // 0x80800C84: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_808001DC_gcdialogexec(rdram, ctx);
        goto after_11;
    // 0x80800C84: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_11:
    // 0x80800C88: b           L_80800D08
    // 0x80800C8C: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
        goto L_80800D08;
    // 0x80800C8C: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
L_80800C90:
    // 0x80800C90: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800C94: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x80800C98: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_80800C9C:
    // 0x80800C9C: lbu         $t5, 0x11C($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X11C);
    // 0x80800CA0: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x80800CA4: addu        $s1, $s4, $t7
    ctx->r17 = ADD32(ctx->r20, ctx->r15);
    // 0x80800CA8: srl         $t6, $t5, 6
    ctx->r14 = S32(U32(ctx->r13) >> 6);
    // 0x80800CAC: bnel        $t6, $zero, L_80800CC4
    if (ctx->r14 != 0) {
        // 0x80800CB0: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80800CC4;
    }
    goto skip_10;
    // 0x80800CB0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_10:
    // 0x80800CB4: jal         0x80087AE0
    // 0x80800CB8: lw          $a0, 0x120($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X120);
    _gczoombox_entrypoint_0(rdram, ctx);
        goto after_12;
    // 0x80800CB8: lw          $a0, 0x120($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X120);
    after_12:
    // 0x80800CBC: sw          $zero, 0x120($s1)
    MEM_W(0X120, ctx->r17) = 0;
    // 0x80800CC0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80800CC4:
    // 0x80800CC4: bne         $s2, $s3, L_80800C9C
    if (ctx->r18 != ctx->r19) {
        // 0x80800CC8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800C9C;
    }
    // 0x80800CC8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800CCC: jal         0x808001DC
    // 0x80800CD0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_808001DC_gcdialogexec(rdram, ctx);
        goto after_13;
    // 0x80800CD0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_13:
    // 0x80800CD4: b           L_80800D0C
    // 0x80800CD8: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
        goto L_80800D0C;
    // 0x80800CD8: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
L_80800CDC:
    // 0x80800CDC: lw          $a0, 0x12C($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X12C);
    // 0x80800CE0: beql        $a0, $zero, L_80800D0C
    if (ctx->r4 == 0) {
        // 0x80800CE4: lw          $t8, 0x4C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X4C);
            goto L_80800D0C;
    }
    goto skip_11;
    // 0x80800CE4: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    skip_11:
    // 0x80800CE8: jal         0x80087B40
    // 0x80800CEC: nop

    _gczoombox_entrypoint_12(rdram, ctx);
        goto after_14;
    // 0x80800CEC: nop

    after_14:
    // 0x80800CF0: jal         0x80087B30
    // 0x80800CF4: lw          $a0, 0x12C($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X12C);
    _gczoombox_entrypoint_10(rdram, ctx);
        goto after_15;
    // 0x80800CF4: lw          $a0, 0x12C($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X12C);
    after_15:
    // 0x80800CF8: b           L_80800D0C
    // 0x80800CFC: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
        goto L_80800D0C;
    // 0x80800CFC: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
L_80800D00:
    // 0x80800D00: jal         0x8080052C
    // 0x80800D04: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8080052C_gcdialogexec(rdram, ctx);
        goto after_16;
    // 0x80800D04: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_16:
L_80800D08:
    // 0x80800D08: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
L_80800D0C:
    // 0x80800D0C: sb          $t8, 0x15C($s4)
    MEM_B(0X15C, ctx->r20) = ctx->r24;
L_80800D10:
    // 0x80800D10: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800D14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800D18: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D1C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800D20: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800D24: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800D28: jr          $ra
    // 0x80800D2C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800D2C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800F0F9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0F9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F0FA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0FA4: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x800F0FA8: jal         0x800F13C4
    // 0x800F0FAC: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    func_800F13C4(rdram, ctx);
        goto after_0;
    // 0x800F0FAC: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x800F0FB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0FB4: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F0FB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F0FBC: jr          $ra
    // 0x800F0FC0: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    return;
    // 0x800F0FC0: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
;}
RECOMP_FUNC void bswalk_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009C4: jal         0x8008E0E8
    // 0x808009C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008E0E8(rdram, ctx);
        goto after_0;
    // 0x808009C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808009CC: beq         $v0, $zero, L_808009DC
    if (ctx->r2 == 0) {
        // 0x808009D0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808009DC;
    }
    // 0x808009D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808009D4: jal         0x80084788
    // 0x808009D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _bapackctrl_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x808009D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
L_808009DC:
    // 0x808009DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009E4: jr          $ra
    // 0x808009E8: nop

    return;
    // 0x808009E8: nop

;}
RECOMP_FUNC void func_800EE5D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE5D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800EE5DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EE5E0: jal         0x8001BAFC
    // 0x800EE5E4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    defrag(rdram, ctx);
        goto after_0;
    // 0x800EE5E4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x800EE5E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800EE5EC: lw          $a0, 0x7EF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF8);
    // 0x800EE5F0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800EE5F4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800EE5F8: beql        $a0, $zero, L_800EE660
    if (ctx->r4 == 0) {
        // 0x800EE5FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800EE660;
    }
    goto skip_0;
    // 0x800EE5FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800EE600: beql        $v0, $a2, L_800EE660
    if (ctx->r2 == ctx->r6) {
        // 0x800EE604: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800EE660;
    }
    goto skip_1;
    // 0x800EE604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800EE608: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800EE60C: jal         0x800B296C
    // 0x800EE610: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    vector_end(rdram, ctx);
        goto after_1;
    // 0x800EE610: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x800EE614: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800EE618: lw          $a0, 0x7EF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF8);
    // 0x800EE61C: jal         0x800B28C4
    // 0x800EE620: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    vector_begin(rdram, ctx);
        goto after_2;
    // 0x800EE620: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x800EE624: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800EE628: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800EE62C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800EE630: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x800EE634: beq         $at, $zero, L_800EE65C
    if (ctx->r1 == 0) {
        // 0x800EE638: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800EE65C;
    }
    // 0x800EE638: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800EE63C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_800EE640:
    // 0x800EE640: bnel        $a2, $t6, L_800EE650
    if (ctx->r6 != ctx->r14) {
        // 0x800EE644: addiu       $v1, $v1, 0xA8
        ctx->r3 = ADD32(ctx->r3, 0XA8);
            goto L_800EE650;
    }
    goto skip_2;
    // 0x800EE644: addiu       $v1, $v1, 0xA8
    ctx->r3 = ADD32(ctx->r3, 0XA8);
    skip_2:
    // 0x800EE648: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800EE64C: addiu       $v1, $v1, 0xA8
    ctx->r3 = ADD32(ctx->r3, 0XA8);
L_800EE650:
    // 0x800EE650: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x800EE654: bnel        $at, $zero, L_800EE640
    if (ctx->r1 != 0) {
        // 0x800EE658: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_800EE640;
    }
    goto skip_3;
    // 0x800EE658: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_3:
L_800EE65C:
    // 0x800EE65C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EE660:
    // 0x800EE660: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800EE664: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x800EE668: jr          $ra
    // 0x800EE66C: nop

    return;
    // 0x800EE66C: nop

;}
RECOMP_FUNC void _suexpression_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800897C8: syscall     795
    recomp_syscall_handler(rdram, ctx, 0x800897C8);
    return;
    // 0x800897CC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80806E0C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806E0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80806E10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80806E14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80806E18: jal         0x80807BB8
    // 0x80806E1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80807BB8_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80806E1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80806E20: lw          $t6, 0x188($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X188);
    // 0x80806E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806E28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80806E2C: jal         0x800A34E4
    // 0x80806E30: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_800A34E4(rdram, ctx);
        goto after_1;
    // 0x80806E30: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_1:
    // 0x80806E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806E38: jal         0x800A34A0
    // 0x80806E3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A34A0(rdram, ctx);
        goto after_2;
    // 0x80806E3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80806E40: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80806E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806E48: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80806E4C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80806E50: jal         0x800936CC
    // 0x80806E54: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    func_800936CC(rdram, ctx);
        goto after_3;
    // 0x80806E54: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    after_3:
    // 0x80806E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806E5C: jal         0x808061AC
    // 0x80806E60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808061AC_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x80806E60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80806E64: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80806E68: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80806E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806E70: jal         0x80806BA0
    // 0x80806E74: sb          $t7, 0x218($t8)
    MEM_B(0X218, ctx->r24) = ctx->r15;
    func_80806BA0_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x80806E74: sb          $t7, 0x218($t8)
    MEM_B(0X218, ctx->r24) = ctx->r15;
    after_5:
    // 0x80806E78: jal         0x800827D8
    // 0x80806E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsbabykaz_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x80806E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80806E80: jal         0x80801A34
    // 0x80806E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801A34_bsfirstp(rdram, ctx);
        goto after_7;
    // 0x80806E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80806E88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80806E8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80806E90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80806E94: jr          $ra
    // 0x80806E98: nop

    return;
    // 0x80806E98: nop

;}
RECOMP_FUNC void func_80800624_chfantasyonion(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800624: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800628: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080062C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800630: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800634: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800638: jal         0x800E88E4
    // 0x8080063C: lbu         $a0, 0x1B($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X1B);
    func_800E88E4(rdram, ctx);
        goto after_0;
    // 0x8080063C: lbu         $a0, 0x1B($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X1B);
    after_0:
    // 0x80800640: beq         $v0, $zero, L_808006C0
    if (ctx->r2 == 0) {
        // 0x80800644: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_808006C0;
    }
    // 0x80800644: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800648: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8080064C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80800650: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x80800654: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800658: jal         0x800EFA4C
    // 0x8080065C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x8080065C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80800660: jal         0x800DF830
    // 0x80800664: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF830(rdram, ctx);
        goto after_2;
    // 0x80800664: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80800668: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x8080066C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800670: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800674: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800678: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080067C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800680: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800684: lui         $a3, 0x3E80
    ctx->r7 = S32(0X3E80 << 16);
    // 0x80800688: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8080068C: jal         0x800F10B4
    // 0x80800690: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80800690: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_3:
    // 0x80800694: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80800698: jal         0x800D674C
    // 0x8080069C: addiu       $a0, $zero, 0x637
    ctx->r4 = ADD32(0, 0X637);
    func_800D674C(rdram, ctx);
        goto after_4;
    // 0x8080069C: addiu       $a0, $zero, 0x637
    ctx->r4 = ADD32(0, 0X637);
    after_4:
    // 0x808006A0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2396, 0X748) << 16);
    // 0x808006A4: addiu       $a2, $a2, 0x748
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2396, 0X748));
    // 0x808006A8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808006AC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808006B0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808006B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808006B8: jal         0x800DE498
    // 0x808006BC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_800DE498(rdram, ctx);
        goto after_5;
    // 0x808006BC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_5:
L_808006C0:
    // 0x808006C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C4: jal         0x80101870
    // 0x808006C8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80101870(rdram, ctx);
        goto after_6;
    // 0x808006C8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_6:
    // 0x808006CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808006D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808006D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808006D8: jr          $ra
    // 0x808006DC: nop

    return;
    // 0x808006DC: nop

;}
RECOMP_FUNC void bastatetimer_isDone(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800915AC: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x800915B0: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800915B4: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x800915B8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800915BC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800915C0: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800915C4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800915C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800915CC: c.eq.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl == ctx->f4.fl;
    // 0x800915D0: nop

    // 0x800915D4: bc1f        L_800915E0
    if (!c1cs) {
        // 0x800915D8: nop
    
            goto L_800915E0;
    }
    // 0x800915D8: nop

    // 0x800915DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800915E0:
    // 0x800915E0: jr          $ra
    // 0x800915E4: nop

    return;
    // 0x800915E4: nop

;}
RECOMP_FUNC void func_80800AC8_chexploder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AC8: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80800ACC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800AD0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800AD4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800AD8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80800ADC: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80800AE0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80800AE4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80800AE8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80800AEC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80800AF0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800AF4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800AF8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800AFC: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    // 0x80800B00: sw          $a3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r7;
    // 0x80800B04: jal         0x80100094
    // 0x80800B08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800B08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800B0C: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80800B10: jal         0x801039E4
    // 0x80800B14: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    func_801039E4(rdram, ctx);
        goto after_1;
    // 0x80800B14: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    after_1:
    // 0x80800B18: jal         0x800B27E0
    // 0x80800B1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B27E0(rdram, ctx);
        goto after_2;
    // 0x80800B1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800B20: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80800B24: jal         0x80104248
    // 0x80800B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_3;
    // 0x80800B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800B2C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800B30: jal         0x8008AEDC
    // 0x80800B34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008AEDC(rdram, ctx);
        goto after_4;
    // 0x80800B34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80800B38: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x80800B3C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800B40: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800B44: jal         0x8008C238
    // 0x80800B48: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    func_8008C238(rdram, ctx);
        goto after_5;
    // 0x80800B48: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    after_5:
    // 0x80800B4C: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x80800B50: jal         0x800AE124
    // 0x80800B54: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    func_800AE124(rdram, ctx);
        goto after_6;
    // 0x80800B54: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    after_6:
    // 0x80800B58: sh          $v0, 0xE($s6)
    MEM_H(0XE, ctx->r22) = ctx->r2;
    // 0x80800B5C: lh          $a2, 0xE($s6)
    ctx->r6 = MEM_H(ctx->r22, 0XE);
    // 0x80800B60: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80800B64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800B68: sll         $t8, $a2, 4
    ctx->r24 = S32(ctx->r6 << 4);
    // 0x80800B6C: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x80800B70: jal         0x80100074
    // 0x80800B74: sll         $a2, $t8, 2
    ctx->r6 = S32(ctx->r24 << 2);
    func_80100074(rdram, ctx);
        goto after_7;
    // 0x80800B74: sll         $a2, $t8, 2
    ctx->r6 = S32(ctx->r24 << 2);
    after_7:
    // 0x80800B78: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x80800B7C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800B80: jal         0x800AE080
    // 0x80800B84: lh          $a0, 0x10($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X10);
    func_800AE080(rdram, ctx);
        goto after_8;
    // 0x80800B84: lh          $a0, 0x10($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X10);
    after_8:
    // 0x80800B88: lh          $t0, 0xE($s6)
    ctx->r8 = MEM_H(ctx->r22, 0XE);
    // 0x80800B8C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80800B90: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800B94: blez        $t0, L_80800BE0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80800B98: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80800BE0;
    }
    // 0x80800B98: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_80800B9C:
    // 0x80800B9C: jal         0x80087A28
    // 0x80800BA0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _dbskeleton_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x80800BA0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x80800BA4: sb          $v0, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r2;
    // 0x80800BA8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800BAC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800BB0: jal         0x800ADE50
    // 0x80800BB4: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    func_800ADE50(rdram, ctx);
        goto after_10;
    // 0x80800BB4: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_10:
    // 0x80800BB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800BBC: jal         0x800F2C1C
    // 0x80800BC0: addiu       $a1, $s0, 0x24
    ctx->r5 = ADD32(ctx->r16, 0X24);
    func_800F2C1C(rdram, ctx);
        goto after_11;
    // 0x80800BC0: addiu       $a1, $s0, 0x24
    ctx->r5 = ADD32(ctx->r16, 0X24);
    after_11:
    // 0x80800BC4: lh          $t1, 0xE($s6)
    ctx->r9 = MEM_H(ctx->r22, 0XE);
    // 0x80800BC8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800BCC: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    // 0x80800BD0: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80800BD4: bnel        $at, $zero, L_80800B9C
    if (ctx->r1 != 0) {
        // 0x80800BD8: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80800B9C;
    }
    goto skip_0;
    // 0x80800BD8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_0:
    // 0x80800BDC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80800BE0:
    // 0x80800BE0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80800BE4: jal         0x80100094
    // 0x80800BE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_12;
    // 0x80800BE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800BEC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800BF0: jal         0x8008AEDC
    // 0x80800BF4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8008AEDC(rdram, ctx);
        goto after_13;
    // 0x80800BF4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_13:
    // 0x80800BF8: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
    // 0x80800BFC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800C00: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800C04: jal         0x8008C200
    // 0x80800C08: lh          $a0, 0x10($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X10);
    func_8008C200(rdram, ctx);
        goto after_14;
    // 0x80800C08: lh          $a0, 0x10($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X10);
    after_14:
    // 0x80800C0C: lw          $t3, 0x0($s7)
    ctx->r11 = MEM_W(ctx->r23, 0X0);
    // 0x80800C10: jal         0x800AE080
    // 0x80800C14: lh          $a0, 0x10($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X10);
    func_800AE080(rdram, ctx);
        goto after_15;
    // 0x80800C14: lh          $a0, 0x10($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X10);
    after_15:
    // 0x80800C18: lh          $t4, 0xE($s6)
    ctx->r12 = MEM_H(ctx->r22, 0XE);
    // 0x80800C1C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80800C20: addiu       $t5, $s7, 0x44
    ctx->r13 = ADD32(ctx->r23, 0X44);
    // 0x80800C24: blez        $t4, L_80800D2C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80800C28: addiu       $t6, $s7, 0x4
        ctx->r14 = ADD32(ctx->r23, 0X4);
            goto L_80800D2C;
    }
    // 0x80800C28: addiu       $t6, $s7, 0x4
    ctx->r14 = ADD32(ctx->r23, 0X4);
    // 0x80800C2C: lw          $fp, 0x9C($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X9C);
    // 0x80800C30: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
    // 0x80800C34: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x80800C38: andi        $t7, $fp, 0x10
    ctx->r15 = ctx->r30 & 0X10;
    // 0x80800C3C: or          $fp, $t7, $zero
    ctx->r30 = ctx->r15 | 0;
    // 0x80800C40: addiu       $s3, $sp, 0x6C
    ctx->r19 = ADD32(ctx->r29, 0X6C);
    // 0x80800C44: addiu       $s2, $sp, 0x60
    ctx->r18 = ADD32(ctx->r29, 0X60);
    // 0x80800C48: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80800C4C:
    // 0x80800C4C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800C50: lbu         $a2, 0x39($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X39);
    // 0x80800C54: jal         0x800AE630
    // 0x80800C58: addiu       $a3, $s0, 0xC
    ctx->r7 = ADD32(ctx->r16, 0XC);
    func_800AE630(rdram, ctx);
        goto after_16;
    // 0x80800C58: addiu       $a3, $s0, 0xC
    ctx->r7 = ADD32(ctx->r16, 0XC);
    after_16:
    // 0x80800C5C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80800C60: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80800C64: lw          $a3, 0x10($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X10);
    // 0x80800C68: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800C6C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80800C70: jal         0x800EF5A0
    // 0x80800C74: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800EF5A0(rdram, ctx);
        goto after_17;
    // 0x80800C74: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_17:
    // 0x80800C78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800C7C: jal         0x800EF334
    // 0x80800C80: lw          $a1, 0x38($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X38);
    func_800EF334(rdram, ctx);
        goto after_18;
    // 0x80800C80: lw          $a1, 0x38($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X38);
    after_18:
    // 0x80800C84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800C88: jal         0x800EF04C
    // 0x80800C8C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_800EF04C(rdram, ctx);
        goto after_19;
    // 0x80800C8C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_19:
    // 0x80800C90: lw          $a0, 0x98($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X98);
    // 0x80800C94: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800C98: jal         0x800F18FC
    // 0x80800C9C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800F18FC(rdram, ctx);
        goto after_20;
    // 0x80800C9C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_20:
    // 0x80800CA0: jal         0x800EFD24
    // 0x80800CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EFD24(rdram, ctx);
        goto after_21;
    // 0x80800CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800CA8: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800CAC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800CB0: jal         0x800EEBF0
    // 0x80800CB4: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    func_800EEBF0(rdram, ctx);
        goto after_22;
    // 0x80800CB4: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    after_22:
    // 0x80800CB8: beql        $fp, $zero, L_80800CD0
    if (ctx->r30 == 0) {
        // 0x80800CBC: lbu         $t1, 0x39($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X39);
            goto L_80800CD0;
    }
    goto skip_1;
    // 0x80800CBC: lbu         $t1, 0x39($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X39);
    skip_1:
    // 0x80800CC0: lbu         $t9, 0x36($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X36);
    // 0x80800CC4: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x80800CC8: sb          $t0, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r8;
    // 0x80800CCC: lbu         $t1, 0x39($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X39);
L_80800CD0:
    // 0x80800CD0: lw          $v0, 0x9C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X9C);
    // 0x80800CD4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800CD8: bne         $t1, $at, L_80800D08
    if (ctx->r9 != ctx->r1) {
        // 0x80800CDC: andi        $t2, $v0, 0x20
        ctx->r10 = ctx->r2 & 0X20;
            goto L_80800D08;
    }
    // 0x80800CDC: andi        $t2, $v0, 0x20
    ctx->r10 = ctx->r2 & 0X20;
    // 0x80800CE0: beql        $t2, $zero, L_80800CFC
    if (ctx->r10 == 0) {
        // 0x80800CE4: lbu         $t6, 0x36($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X36);
            goto L_80800CFC;
    }
    goto skip_2;
    // 0x80800CE4: lbu         $t6, 0x36($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X36);
    skip_2:
    // 0x80800CE8: lbu         $t4, 0x36($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X36);
    // 0x80800CEC: ori         $t5, $t4, 0x40
    ctx->r13 = ctx->r12 | 0X40;
    // 0x80800CF0: b           L_80800D14
    // 0x80800CF4: sb          $t5, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r13;
        goto L_80800D14;
    // 0x80800CF4: sb          $t5, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r13;
    // 0x80800CF8: lbu         $t6, 0x36($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X36);
L_80800CFC:
    // 0x80800CFC: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x80800D00: b           L_80800D14
    // 0x80800D04: sb          $t7, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r15;
        goto L_80800D14;
    // 0x80800D04: sb          $t7, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r15;
L_80800D08:
    // 0x80800D08: lbu         $t9, 0x36($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X36);
    // 0x80800D0C: ori         $t0, $t9, 0x40
    ctx->r8 = ctx->r25 | 0X40;
    // 0x80800D10: sb          $t0, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r8;
L_80800D14:
    // 0x80800D14: lh          $t1, 0xE($s6)
    ctx->r9 = MEM_H(ctx->r22, 0XE);
    // 0x80800D18: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800D1C: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    // 0x80800D20: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80800D24: bnel        $at, $zero, L_80800C4C
    if (ctx->r1 != 0) {
        // 0x80800D28: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80800C4C;
    }
    goto skip_3;
    // 0x80800D28: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_3:
L_80800D2C:
    // 0x80800D2C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1392, 0X1AD0) << 16);
    // 0x80800D30: lwc1        $f6, 0x1AD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1392, 0X1AD0));
    // 0x80800D34: addiu       $a0, $s7, 0x44
    ctx->r4 = ADD32(ctx->r23, 0X44);
    // 0x80800D38: jal         0x800EFD24
    // 0x80800D3C: swc1        $f6, 0x5C($s6)
    MEM_W(0X5C, ctx->r22) = ctx->f6.u32l;
    func_800EFD24(rdram, ctx);
        goto after_23;
    // 0x80800D3C: swc1        $f6, 0x5C($s6)
    MEM_W(0X5C, ctx->r22) = ctx->f6.u32l;
    after_23:
    // 0x80800D40: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80800D44: jal         0x80100094
    // 0x80800D48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_24;
    // 0x80800D48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x80800D4C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80800D50: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800D54: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800D58: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800D5C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800D60: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80800D64: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80800D68: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80800D6C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80800D70: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80800D74: jr          $ra
    // 0x80800D78: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80800D78: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void _choildrill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087700: syscall     611
    recomp_syscall_handler(rdram, ctx, 0x80087700);
    return;
    // 0x80087704: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800124_chfactoryworkerwear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800124: jr          $ra
    // 0x80800128: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800128: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void chfriesstand_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(940, 0XF10) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0xF10
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(940, 0XF10));
    return;
    // 0x80800014: addiu       $v0, $v0, 0xF10
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(940, 0XF10));
;}
RECOMP_FUNC void func_80800A54_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800A58: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800A5C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800A60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A64: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800A68: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800A6C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800A70: addiu       $s2, $zero, 0x6
    ctx->r18 = ADD32(0, 0X6);
L_80800A74:
    // 0x80800A74: jal         0x800DA298
    // 0x80800A78: addiu       $a0, $s0, 0x42D
    ctx->r4 = ADD32(ctx->r16, 0X42D);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800A78: addiu       $a0, $s0, 0x42D
    ctx->r4 = ADD32(ctx->r16, 0X42D);
    after_0:
    // 0x80800A7C: bne         $v0, $zero, L_80800A8C
    if (ctx->r2 != 0) {
        // 0x80800A80: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800A8C;
    }
    // 0x80800A80: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800A84: b           L_80800A90
    // 0x80800A88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A90;
    // 0x80800A88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A8C:
    // 0x80800A8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A90:
    // 0x80800A90: bne         $s0, $s2, L_80800A74
    if (ctx->r16 != ctx->r18) {
        // 0x80800A94: addu        $s1, $s1, $v0
        ctx->r17 = ADD32(ctx->r17, ctx->r2);
            goto L_80800A74;
    }
    // 0x80800A94: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x80800A98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800A9C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80800AA0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800AA8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800AAC: jr          $ra
    // 0x80800AB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800AB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bsbfly_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801928: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080192C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(96, 0X1D98) << 16);
    // 0x80801930: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801934: jr          $ra
    // 0x80801938: lw          $v0, 0x1D98($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(96, 0X1D98));
    return;
    // 0x80801938: lw          $v0, 0x1D98($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(96, 0X1D98));
;}
RECOMP_FUNC void func_8080011C_chjigsaw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080011C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800124: jal         0x800D8FF8
    // 0x80800128: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800128: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080012C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800130: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800134: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80800138: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080013C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800140: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800144: lwc1        $f4, 0x54($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X54);
    // 0x80800148: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8080014C: swc1        $f10, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f10.u32l;
    // 0x80800150: lwc1        $f2, 0x54($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X54);
    // 0x80800154: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80800158: nop

    // 0x8080015C: bc1fl       L_80800170
    if (!c1cs) {
        // 0x80800160: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800170;
    }
    goto skip_0;
    // 0x80800160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800164: sub.s       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80800168: swc1        $f16, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f16.u32l;
    // 0x8080016C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800170:
    // 0x80800170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800174: jr          $ra
    // 0x80800178: nop

    return;
    // 0x80800178: nop

;}
RECOMP_FUNC void basub_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800648: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080064C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800650: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800654: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800658: jal         0x800F53D0
    // 0x8080065C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x8080065C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80800660: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80800664: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800668: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8080066C: beq         $v1, $at, L_80800688
    if (ctx->r3 == ctx->r1) {
        // 0x80800670: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80800688;
    }
    // 0x80800670: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800674: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x80800678: beql        $v1, $at, L_808006AC
    if (ctx->r3 == ctx->r1) {
        // 0x8080067C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808006AC;
    }
    goto skip_0;
    // 0x8080067C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80800680: b           L_808006AC
    // 0x80800684: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
        goto L_808006AC;
    // 0x80800684: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80800688:
    // 0x80800688: jal         0x8008F880
    // 0x8080068C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8008F880(rdram, ctx);
        goto after_1;
    // 0x8080068C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80800690: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(616, 0XC10) << 16);
    // 0x80800694: addiu       $a3, $a3, 0xC10
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(616, 0XC10));
    // 0x80800698: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8080069C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808006A0: jal         0x8010D930
    // 0x808006A4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_8010D930(rdram, ctx);
        goto after_2;
    // 0x808006A4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x808006A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_808006AC:
    // 0x808006AC: jal         0x80800358
    // 0x808006B0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80800358_basub(rdram, ctx);
        goto after_3;
    // 0x808006B0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x808006B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808006BC: jr          $ra
    // 0x808006C0: nop

    return;
    // 0x808006C0: nop

;}
RECOMP_FUNC void func_80018C50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018C50: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80018C54: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80018C58: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80018C5C: lw          $a2, -0x4350($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4350);
    // 0x80018C60: addiu       $v1, $sp, 0x18
    ctx->r3 = ADD32(ctx->r29, 0X18);
    // 0x80018C64: addiu       $t1, $sp, 0x58
    ctx->r9 = ADD32(ctx->r29, 0X58);
    // 0x80018C68: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80018C6C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
L_80018C70:
    // 0x80018C70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80018C74: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80018C78: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80018C7C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80018C80: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80018C84: beq         $v0, $t0, L_80018CE4
    if (ctx->r2 == ctx->r8) {
        // 0x80018C88: lwc1        $f16, 0x0($a3)
        ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
            goto L_80018CE4;
    }
    // 0x80018C88: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
L_80018C8C:
    // 0x80018C8C: mul.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80018C90: lwc1        $f12, 0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80018C94: lwc1        $f10, 0x10($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80018C98: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80018C9C: lwc1        $f6, 0x20($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X20);
    // 0x80018CA0: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80018CA4: lwc1        $f12, 0xC($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80018CA8: add.s       $f14, $f2, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x80018CAC: mul.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80018CB0: lwc1        $f8, 0x30($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X30);
    // 0x80018CB4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80018CB8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80018CBC: mul.s       $f8, $f12, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x80018CC0: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80018CC4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80018CC8: add.s       $f6, $f10, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80018CCC: add.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80018CD0: swc1        $f8, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80018CD4: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80018CD8: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80018CDC: bne         $v0, $t0, L_80018C8C
    if (ctx->r2 != ctx->r8) {
        // 0x80018CE0: nop
    
            goto L_80018C8C;
    }
    // 0x80018CE0: nop

L_80018CE4:
    // 0x80018CE4: mul.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80018CE8: lwc1        $f12, 0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80018CEC: lwc1        $f10, 0x10($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80018CF0: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80018CF4: lwc1        $f6, 0x20($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X20);
    // 0x80018CF8: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80018CFC: lwc1        $f12, 0xC($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80018D00: add.s       $f14, $f2, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x80018D04: mul.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80018D08: lwc1        $f8, 0x30($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X30);
    // 0x80018D0C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80018D10: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80018D14: mul.s       $f8, $f12, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x80018D18: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80018D1C: add.s       $f6, $f10, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80018D20: add.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80018D24: swc1        $f8, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80018D28: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80018D2C: sltu        $at, $v1, $t1
    ctx->r1 = ctx->r3 < ctx->r9 ? 1 : 0;
    // 0x80018D30: bne         $at, $zero, L_80018C70
    if (ctx->r1 != 0) {
        // 0x80018D34: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_80018C70;
    }
    // 0x80018D34: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80018D38: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80018D3C: addiu       $a1, $a1, -0x4350
    ctx->r5 = ADD32(ctx->r5, -0X4350);
    // 0x80018D40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80018D44: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
L_80018D48:
    // 0x80018D48: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80018D4C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80018D50: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80018D54: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80018D58: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x80018D5C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80018D60: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80018D64: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x80018D68: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x80018D6C: swc1        $f6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f6.u32l;
    // 0x80018D70: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80018D74: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80018D78: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x80018D7C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80018D80: swc1        $f8, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f8.u32l;
    // 0x80018D84: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80018D88: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x80018D8C: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80018D90: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80018D94: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80018D98: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80018D9C: bne         $v0, $t0, L_80018D48
    if (ctx->r2 != ctx->r8) {
        // 0x80018DA0: swc1        $f10, 0xC($t8)
        MEM_W(0XC, ctx->r24) = ctx->f10.u32l;
            goto L_80018D48;
    }
    // 0x80018DA0: swc1        $f10, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f10.u32l;
    // 0x80018DA4: jr          $ra
    // 0x80018DA8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80018DA8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void _chdoormake_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800868B8: syscall     393
    recomp_syscall_handler(rdram, ctx, 0x800868B8);
    return;
    // 0x800868BC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800987CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800987CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800987D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800987D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800987D8: jal         0x800D8FF8
    // 0x800987DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x800987DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800987E0: lw          $t6, 0xE0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE0);
    // 0x800987E4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800987E8: lwc1        $f4, 0x28($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X28);
    // 0x800987EC: jal         0x800F0E00
    // 0x800987F0: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    func_800F0E00(rdram, ctx);
        goto after_1;
    // 0x800987F0: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    after_1:
    // 0x800987F4: lw          $t7, 0xE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE0);
    // 0x800987F8: swc1        $f0, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->f0.u32l;
    // 0x800987FC: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    // 0x80098800: lbu         $t9, 0x2C($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X2C);
    // 0x80098804: beql        $t9, $zero, L_80098828
    if (ctx->r25 == 0) {
        // 0x80098808: lw          $t0, 0xE0($s0)
        ctx->r8 = MEM_W(ctx->r16, 0XE0);
            goto L_80098828;
    }
    goto skip_0;
    // 0x80098808: lw          $t0, 0xE0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XE0);
    skip_0:
    // 0x8009880C: jal         0x800C6E38
    // 0x80098810: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800C6E38(rdram, ctx);
        goto after_2;
    // 0x80098810: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_2:
    // 0x80098814: beq         $v0, $zero, L_80098824
    if (ctx->r2 == 0) {
        // 0x80098818: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80098824;
    }
    // 0x80098818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009881C: jal         0x8009E7C8
    // 0x80098820: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_8009E7C8(rdram, ctx);
        goto after_3;
    // 0x80098820: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_3:
L_80098824:
    // 0x80098824: lw          $t0, 0xE0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XE0);
L_80098828:
    // 0x80098828: sb          $zero, 0x2C($t0)
    MEM_B(0X2C, ctx->r8) = 0;
    // 0x8009882C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80098830: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80098834: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80098838: jr          $ra
    // 0x8009883C: nop

    return;
    // 0x8009883C: nop

;}
RECOMP_FUNC void bitfield_get_bit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9E60: bgez        $a1, L_800D9E70
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800D9E64: sra         $t6, $a1, 3
        ctx->r14 = S32(SIGNED(ctx->r5) >> 3);
            goto L_800D9E70;
    }
    // 0x800D9E64: sra         $t6, $a1, 3
    ctx->r14 = S32(SIGNED(ctx->r5) >> 3);
    // 0x800D9E68: addiu       $at, $a1, 0x7
    ctx->r1 = ADD32(ctx->r5, 0X7);
    // 0x800D9E6C: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_800D9E70:
    // 0x800D9E70: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800D9E74: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800D9E78: andi        $t9, $a1, 0x7
    ctx->r25 = ctx->r5 & 0X7;
    // 0x800D9E7C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800D9E80: sllv        $t1, $t0, $t9
    ctx->r9 = S32(ctx->r8 << (ctx->r25 & 31));
    // 0x800D9E84: and         $t2, $t8, $t1
    ctx->r10 = ctx->r24 & ctx->r9;
    // 0x800D9E88: beq         $t2, $zero, L_800D9E98
    if (ctx->r10 == 0) {
        // 0x800D9E8C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800D9E98;
    }
    // 0x800D9E8C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D9E90: jr          $ra
    // 0x800D9E94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800D9E94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D9E98:
    // 0x800D9E98: jr          $ra
    // 0x800D9E9C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800D9E9C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void _bafpctrl_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084CA8: syscall     133
    recomp_syscall_handler(rdram, ctx, 0x80084CA8);
    return;
    // 0x80084CAC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _subaddiefx_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A050: syscall     824
    recomp_syscall_handler(rdram, ctx, 0x8008A050);
    return;
    // 0x8008A054: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800ADC_chwarppad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800ADC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AE4: jal         0x8008FD48
    // 0x80800AE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008FD48(rdram, ctx);
        goto after_0;
    // 0x80800AE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800AEC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(780, 0X1080) << 16);
    // 0x80800AF0: lbu         $t6, 0x1080($t6)
    ctx->r14 = MEM_BU(ctx->r14, (int16_t)RELOC_LO16(780, 0X1080));
    // 0x80800AF4: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(780, 0X1080) << 16);
    // 0x80800AF8: addiu       $v1, $t7, 0x1080
    ctx->r3 = ADD32(ctx->r15, (int16_t)RELOC_LO16(780, 0X1080));
    // 0x80800AFC: beq         $t6, $zero, L_80800B28
    if (ctx->r14 == 0) {
        // 0x80800B00: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800B28;
    }
    // 0x80800B00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B04: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
L_80800B08:
    // 0x80800B08: bnel        $v0, $a0, L_80800B1C
    if (ctx->r2 != ctx->r4) {
        // 0x80800B0C: lbu         $a0, 0x2($v1)
        ctx->r4 = MEM_BU(ctx->r3, 0X2);
            goto L_80800B1C;
    }
    goto skip_0;
    // 0x80800B0C: lbu         $a0, 0x2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2);
    skip_0:
    // 0x80800B10: b           L_80800B2C
    // 0x80800B14: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
        goto L_80800B2C;
    // 0x80800B14: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x80800B18: lbu         $a0, 0x2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2);
L_80800B1C:
    // 0x80800B1C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80800B20: bne         $a0, $zero, L_80800B08
    if (ctx->r4 != 0) {
        // 0x80800B24: nop
    
            goto L_80800B08;
    }
    // 0x80800B24: nop

L_80800B28:
    // 0x80800B28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B2C:
    // 0x80800B2C: jr          $ra
    // 0x80800B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void ncbakaztorp_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800004: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _bsvan_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084130: syscall     105
    recomp_syscall_handler(rdram, ctx, 0x80084130);
    return;
    // 0x80084134: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _bsdronelook_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083118: syscall     45
    recomp_syscall_handler(rdram, ctx, 0x80083118);
    return;
    // 0x8008311C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801350_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801350: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801354: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80801358: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080135C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80801360: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80801364: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80801368: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8080136C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801370: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801374: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80801378: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8080137C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80801380: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80801384: addu        $v0, $a1, $t6
    ctx->r2 = ADD32(ctx->r5, ctx->r14);
    // 0x80801388: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8080138C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80801390: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x80801394: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80801398: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8080139C: jal         0x800BE444
    // 0x808013A0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800BE444(rdram, ctx);
        goto after_0;
    // 0x808013A0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x808013A4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x808013A8: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x808013AC: addiu       $s5, $zero, 0x44
    ctx->r21 = ADD32(0, 0X44);
    // 0x808013B0: beq         $t7, $zero, L_808014B0
    if (ctx->r15 == 0) {
        // 0x808013B4: addiu       $s4, $zero, 0x43
        ctx->r20 = ADD32(0, 0X43);
            goto L_808014B0;
    }
    // 0x808013B4: addiu       $s4, $zero, 0x43
    ctx->r20 = ADD32(0, 0X43);
    // 0x808013B8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x808013BC: addiu       $s3, $zero, 0x42
    ctx->r19 = ADD32(0, 0X42);
L_808013C0:
    // 0x808013C0: jal         0x800E9E88
    // 0x808013C4: nop

    func_800E9E88(rdram, ctx);
        goto after_1;
    // 0x808013C4: nop

    after_1:
    // 0x808013C8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808013CC: jal         0x800E9EB4
    // 0x808013D0: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    func_800E9EB4(rdram, ctx);
        goto after_2;
    // 0x808013D0: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    after_2:
    // 0x808013D4: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x808013D8: beq         $at, $zero, L_808014A0
    if (ctx->r1 == 0) {
        // 0x808013DC: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_808014A0;
    }
    // 0x808013DC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808013E0: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
L_808013E4:
    // 0x808013E4: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x808013E8: beql        $t9, $zero, L_80801494
    if (ctx->r25 == 0) {
        // 0x808013EC: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80801494;
    }
    goto skip_0;
    // 0x808013EC: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_0:
    // 0x808013F0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x808013F4: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x808013F8: srl         $t0, $v0, 22
    ctx->r8 = S32(U32(ctx->r2) >> 22);
    // 0x808013FC: beql        $t0, $s3, L_80801488
    if (ctx->r8 == ctx->r19) {
        // 0x80801400: lw          $t5, 0xC($s0)
        ctx->r13 = MEM_W(ctx->r16, 0XC);
            goto L_80801488;
    }
    goto skip_1;
    // 0x80801400: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
    skip_1:
    // 0x80801404: beq         $t0, $s4, L_8080144C
    if (ctx->r8 == ctx->r20) {
        // 0x80801408: nop
    
            goto L_8080144C;
    }
    // 0x80801408: nop

    // 0x8080140C: bnel        $t0, $s5, L_80801494
    if (ctx->r8 != ctx->r21) {
        // 0x80801410: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80801494;
    }
    goto skip_2;
    // 0x80801410: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_2:
    // 0x80801414: jal         0x80106790
    // 0x80801418: nop

    func_80106790(rdram, ctx);
        goto after_3;
    // 0x80801418: nop

    after_3:
    // 0x8080141C: lw          $t1, 0x64($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X64);
    // 0x80801420: sll         $t3, $t1, 12
    ctx->r11 = S32(ctx->r9 << 12);
    // 0x80801424: bgezl       $t3, L_80801440
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80801428: lw          $t6, 0x4($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X4);
            goto L_80801440;
    }
    goto skip_3;
    // 0x80801428: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    skip_3:
    // 0x8080142C: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
    // 0x80801430: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80801434: b           L_80801490
    // 0x80801438: sw          $t5, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r13;
        goto L_80801490;
    // 0x80801438: sw          $t5, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r13;
    // 0x8080143C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
L_80801440:
    // 0x80801440: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80801444: b           L_80801490
    // 0x80801448: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_80801490;
    // 0x80801448: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_8080144C:
    // 0x8080144C: jal         0x80106790
    // 0x80801450: nop

    func_80106790(rdram, ctx);
        goto after_4;
    // 0x80801450: nop

    after_4:
    // 0x80801454: lw          $t8, 0x64($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X64);
    // 0x80801458: sll         $t0, $t8, 12
    ctx->r8 = S32(ctx->r24 << 12);
    // 0x8080145C: bgezl       $t0, L_80801478
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80801460: lw          $t3, 0x8($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X8);
            goto L_80801478;
    }
    goto skip_4;
    // 0x80801460: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    skip_4:
    // 0x80801464: lw          $t1, 0x10($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X10);
    // 0x80801468: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8080146C: b           L_80801490
    // 0x80801470: sw          $t2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r10;
        goto L_80801490;
    // 0x80801470: sw          $t2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r10;
    // 0x80801474: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
L_80801478:
    // 0x80801478: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8080147C: b           L_80801490
    // 0x80801480: sw          $t4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r12;
        goto L_80801490;
    // 0x80801480: sw          $t4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r12;
    // 0x80801484: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
L_80801488:
    // 0x80801488: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8080148C: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
L_80801490:
    // 0x80801490: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_80801494:
    // 0x80801494: sltu        $at, $s1, $s2
    ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
    // 0x80801498: bnel        $at, $zero, L_808013E4
    if (ctx->r1 != 0) {
        // 0x8080149C: lw          $t8, 0x8($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X8);
            goto L_808013E4;
    }
    goto skip_5;
    // 0x8080149C: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    skip_5:
L_808014A0:
    // 0x808014A0: lw          $a0, 0x4($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X4);
    // 0x808014A4: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x808014A8: bne         $a0, $zero, L_808013C0
    if (ctx->r4 != 0) {
        // 0x808014AC: nop
    
            goto L_808013C0;
    }
    // 0x808014AC: nop

L_808014B0:
    // 0x808014B0: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x808014B4: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x808014B8: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x808014BC: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x808014C0: lw          $t4, 0x10($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X10);
    // 0x808014C4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x808014C8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x808014CC: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x808014D0: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x808014D4: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x808014D8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808014DC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x808014E0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x808014E4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808014E8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808014EC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808014F0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808014F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808014F8: jr          $ra
    // 0x808014FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808014FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
