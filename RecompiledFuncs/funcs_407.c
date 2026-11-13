#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800A5044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A504C: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x800A5050: lw          $t7, 0x3C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X3C);
    // 0x800A5054: beql        $t7, $zero, L_800A5084
    if (ctx->r15 == 0) {
        // 0x800A5058: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A5084;
    }
    goto skip_0;
    // 0x800A5058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A505C: jal         0x800A4EC8
    // 0x800A5060: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A4EC8(rdram, ctx);
        goto after_0;
    // 0x800A5060: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A5064: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800A5068: lw          $t9, 0x38($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X38);
    // 0x800A506C: jal         0x800CA364
    // 0x800A5070: lw          $a0, 0x3C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X3C);
    func_800CA364(rdram, ctx);
        goto after_1;
    // 0x800A5070: lw          $a0, 0x3C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X3C);
    after_1:
    // 0x800A5074: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800A5078: lw          $t1, 0x38($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X38);
    // 0x800A507C: sw          $zero, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = 0;
    // 0x800A5080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A5084:
    // 0x800A5084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5088: jr          $ra
    // 0x800A508C: nop

    return;
    // 0x800A508C: nop

;}
RECOMP_FUNC void func_80800B80_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B80: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800B84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B88: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800B8C: jal         0x80100094
    // 0x80800B90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800B90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800B94: jal         0x800F54E4
    // 0x80800B98: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800B98: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800B9C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80800BA0: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80800BA4: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    // 0x80800BA8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80800BAC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80800BB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800BB4: jal         0x800D0A9C
    // 0x80800BB8: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    func_800D0A9C(rdram, ctx);
        goto after_2;
    // 0x80800BB8: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    after_2:
    // 0x80800BBC: jal         0x800D395C
    // 0x80800BC0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800D395C(rdram, ctx);
        goto after_3;
    // 0x80800BC0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_3:
    // 0x80800BC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800BC8: addiu       $a1, $zero, 0x83
    ctx->r5 = ADD32(0, 0X83);
    // 0x80800BCC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80800BD0: jal         0x800D2054
    // 0x80800BD4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800D2054(rdram, ctx);
        goto after_4;
    // 0x80800BD4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_4:
    // 0x80800BD8: xori        $v1, $v0, 0x1
    ctx->r3 = ctx->r2 ^ 0X1;
    // 0x80800BDC: sltiu       $a1, $v1, 0x1
    ctx->r5 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80800BE0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800BE4: beq         $a1, $zero, L_80800C00
    if (ctx->r5 == 0) {
        // 0x80800BE8: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80800C00;
    }
    // 0x80800BE8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800BEC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800BF0: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800BF4: bnel        $a1, $zero, L_80800C04
    if (ctx->r5 != 0) {
        // 0x80800BF8: lw          $v0, 0x38($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X38);
            goto L_80800C04;
    }
    goto skip_0;
    // 0x80800BF8: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    skip_0:
    // 0x80800BFC: sltu        $a1, $zero, $a3
    ctx->r5 = 0 < ctx->r7 ? 1 : 0;
L_80800C00:
    // 0x80800C00: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_80800C04:
    // 0x80800C04: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80800C08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800C0C: slti        $t1, $v0, 0x28
    ctx->r9 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x80800C10: xori        $t1, $t1, 0x1
    ctx->r9 = ctx->r9 ^ 0X1;
    // 0x80800C14: sltu        $a1, $zero, $t1
    ctx->r5 = 0 < ctx->r9 ? 1 : 0;
    // 0x80800C18: beq         $a1, $zero, L_80800C30
    if (ctx->r5 == 0) {
        // 0x80800C1C: lw          $v0, 0x24($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X24);
            goto L_80800C30;
    }
    // 0x80800C1C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800C20: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800C24: beql        $a1, $zero, L_80800C34
    if (ctx->r5 == 0) {
        // 0x80800C28: sw          $a1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r5;
            goto L_80800C34;
    }
    goto skip_1;
    // 0x80800C28: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    skip_1:
    // 0x80800C2C: sltiu       $a1, $a3, 0x1
    ctx->r5 = ctx->r7 < 0X1 ? 1 : 0;
L_80800C30:
    // 0x80800C30: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
L_80800C34:
    // 0x80800C34: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x80800C38: jal         0x800FDC28
    // 0x80800C3C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800FDC28(rdram, ctx);
        goto after_5;
    // 0x80800C3C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_5:
    // 0x80800C40: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800C44: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80800C48: bne         $a1, $zero, L_80800C58
    if (ctx->r5 != 0) {
        // 0x80800C4C: nop
    
            goto L_80800C58;
    }
    // 0x80800C4C: nop

    // 0x80800C50: beq         $v1, $zero, L_80800C60
    if (ctx->r3 == 0) {
        // 0x80800C54: addiu       $a1, $zero, 0x17
        ctx->r5 = ADD32(0, 0X17);
            goto L_80800C60;
    }
    // 0x80800C54: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
L_80800C58:
    // 0x80800C58: b           L_80800C60
    // 0x80800C5C: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
        goto L_80800C60;
    // 0x80800C5C: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
L_80800C60:
    // 0x80800C60: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800C64: jal         0x800FC6B0
    // 0x80800C68: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_800FC6B0(rdram, ctx);
        goto after_6;
    // 0x80800C68: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_6:
    // 0x80800C6C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80800C70: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80800C74: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x80800C78: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80800C7C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800C80: beq         $t6, $zero, L_80800C90
    if (ctx->r14 == 0) {
        // 0x80800C84: nop
    
            goto L_80800C90;
    }
    // 0x80800C84: nop

    // 0x80800C88: b           L_80800CEC
    // 0x80800C8C: addiu       $v1, $zero, 0x1346
    ctx->r3 = ADD32(0, 0X1346);
        goto L_80800CEC;
    // 0x80800C8C: addiu       $v1, $zero, 0x1346
    ctx->r3 = ADD32(0, 0X1346);
L_80800C90:
    // 0x80800C90: beq         $v1, $zero, L_80800CA0
    if (ctx->r3 == 0) {
        // 0x80800C94: nop
    
            goto L_80800CA0;
    }
    // 0x80800C94: nop

    // 0x80800C98: b           L_80800CEC
    // 0x80800C9C: addiu       $v1, $zero, 0x1347
    ctx->r3 = ADD32(0, 0X1347);
        goto L_80800CEC;
    // 0x80800C9C: addiu       $v1, $zero, 0x1347
    ctx->r3 = ADD32(0, 0X1347);
L_80800CA0:
    // 0x80800CA0: jal         0x800D395C
    // 0x80800CA4: nop

    func_800D395C(rdram, ctx);
        goto after_7;
    // 0x80800CA4: nop

    after_7:
    // 0x80800CA8: bne         $v0, $zero, L_80800CE0
    if (ctx->r2 != 0) {
        // 0x80800CAC: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80800CE0;
    }
    // 0x80800CAC: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80800CB0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80800CB4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CB8: beq         $t7, $zero, L_80800CD8
    if (ctx->r15 == 0) {
        // 0x80800CBC: nop
    
            goto L_80800CD8;
    }
    // 0x80800CBC: nop

    // 0x80800CC0: bne         $t8, $zero, L_80800CD0
    if (ctx->r24 != 0) {
        // 0x80800CC4: nop
    
            goto L_80800CD0;
    }
    // 0x80800CC4: nop

    // 0x80800CC8: b           L_80800CEC
    // 0x80800CCC: addiu       $v1, $zero, 0x1376
    ctx->r3 = ADD32(0, 0X1376);
        goto L_80800CEC;
    // 0x80800CCC: addiu       $v1, $zero, 0x1376
    ctx->r3 = ADD32(0, 0X1376);
L_80800CD0:
    // 0x80800CD0: b           L_80800CEC
    // 0x80800CD4: addiu       $v1, $zero, 0x1375
    ctx->r3 = ADD32(0, 0X1375);
        goto L_80800CEC;
    // 0x80800CD4: addiu       $v1, $zero, 0x1375
    ctx->r3 = ADD32(0, 0X1375);
L_80800CD8:
    // 0x80800CD8: b           L_80800CEC
    // 0x80800CDC: addiu       $v1, $zero, 0x1374
    ctx->r3 = ADD32(0, 0X1374);
        goto L_80800CEC;
    // 0x80800CDC: addiu       $v1, $zero, 0x1374
    ctx->r3 = ADD32(0, 0X1374);
L_80800CE0:
    // 0x80800CE0: addiu       $t9, $zero, 0x46
    ctx->r25 = ADD32(0, 0X46);
    // 0x80800CE4: addiu       $v1, $zero, 0xCEB
    ctx->r3 = ADD32(0, 0XCEB);
    // 0x80800CE8: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
L_80800CEC:
    // 0x80800CEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CF0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800CF4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800CF8: jr          $ra
    // 0x80800CFC: nop

    return;
    // 0x80800CFC: nop

;}
RECOMP_FUNC void func_80801AB0_sucoasterfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801AB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801AB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801ABC: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80801AC0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801AC4: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x80801AC8: bltz        $t7, L_80801AD8
    if (SIGNED(ctx->r15) < 0) {
        // 0x80801ACC: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_80801AD8;
    }
    // 0x80801ACC: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80801AD0: b           L_80801B7C
    // 0x80801AD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801B7C;
    // 0x80801AD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801AD8:
    // 0x80801AD8: bgez        $t9, L_80801AE8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80801ADC: nop
    
            goto L_80801AE8;
    }
    // 0x80801ADC: nop

    // 0x80801AE0: b           L_80801B7C
    // 0x80801AE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801B7C;
    // 0x80801AE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801AE8:
    // 0x80801AE8: jal         0x801072A8
    // 0x80801AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801072A8(rdram, ctx);
        goto after_0;
    // 0x80801AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80801AF0: bne         $v0, $zero, L_80801B08
    if (ctx->r2 != 0) {
        // 0x80801AF4: nop
    
            goto L_80801B08;
    }
    // 0x80801AF4: nop

    // 0x80801AF8: lw          $t0, 0x78($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X78);
    // 0x80801AFC: sll         $t2, $t0, 28
    ctx->r10 = S32(ctx->r8 << 28);
    // 0x80801B00: bgez        $t2, L_80801B10
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80801B04: nop
    
            goto L_80801B10;
    }
    // 0x80801B04: nop

L_80801B08:
    // 0x80801B08: b           L_80801B7C
    // 0x80801B0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801B7C;
    // 0x80801B0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801B10:
    // 0x80801B10: jal         0x80089F78
    // 0x80801B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80801B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801B18: bne         $v0, $zero, L_80801B28
    if (ctx->r2 != 0) {
        // 0x80801B1C: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80801B28;
    }
    // 0x80801B1C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801B20: b           L_80801B7C
    // 0x80801B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801B7C;
    // 0x80801B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801B28:
    // 0x80801B28: jal         0x8010C9B0
    // 0x80801B2C: addiu       $a1, $zero, 0x578
    ctx->r5 = ADD32(0, 0X578);
    func_8010C9B0(rdram, ctx);
        goto after_2;
    // 0x80801B2C: addiu       $a1, $zero, 0x578
    ctx->r5 = ADD32(0, 0X578);
    after_2:
    // 0x80801B30: bne         $v0, $zero, L_80801B40
    if (ctx->r2 != 0) {
        // 0x80801B34: nop
    
            goto L_80801B40;
    }
    // 0x80801B34: nop

    // 0x80801B38: b           L_80801B7C
    // 0x80801B3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801B7C;
    // 0x80801B3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801B40:
    // 0x80801B40: jal         0x8010C500
    // 0x80801B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_3;
    // 0x80801B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801B48: bne         $v0, $zero, L_80801B58
    if (ctx->r2 != 0) {
        // 0x80801B4C: nop
    
            goto L_80801B58;
    }
    // 0x80801B4C: nop

    // 0x80801B50: b           L_80801B7C
    // 0x80801B54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801B7C;
    // 0x80801B54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801B58:
    // 0x80801B58: jal         0x80089F00
    // 0x80801B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suchase_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80801B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801B60: bne         $v0, $zero, L_80801B70
    if (ctx->r2 != 0) {
        // 0x80801B64: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801B70;
    }
    // 0x80801B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B68: b           L_80801B7C
    // 0x80801B6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801B7C;
    // 0x80801B6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801B70:
    // 0x80801B70: jal         0x808014AC
    // 0x80801B74: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_5;
    // 0x80801B74: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x80801B78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801B7C:
    // 0x80801B7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801B80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801B84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801B88: jr          $ra
    // 0x80801B8C: nop

    return;
    // 0x80801B8C: nop

;}
RECOMP_FUNC void func_808003A0_chlaundry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808003A8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808003AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003B0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2140, 0X48C) << 16);
    // 0x808003B4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x808003B8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x808003BC: addiu       $a3, $a3, 0x48C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2140, 0X48C));
    // 0x808003C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808003C4: jal         0x8010D930
    // 0x808003C8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8010D930(rdram, ctx);
        goto after_0;
    // 0x808003C8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x808003CC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808003D0: jal         0x800888C8
    // 0x808003D4: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    _fxsparkle_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808003D4: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_1:
    // 0x808003D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003E0: jr          $ra
    // 0x808003E4: nop

    return;
    // 0x808003E4: nop

    // 0x808003E8: nop

    // 0x808003EC: nop

;}
RECOMP_FUNC void func_80800130_chgruntyfireball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800130: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800134: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800138: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8080013C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800140: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800144: beq         $a1, $at, L_80800168
    if (ctx->r5 == ctx->r1) {
        // 0x80800148: sw          $a2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r6;
            goto L_80800168;
    }
    // 0x80800148: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8080014C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800150: beq         $a1, $at, L_80800200
    if (ctx->r5 == ctx->r1) {
        // 0x80800154: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800200;
    }
    // 0x80800154: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800158: beq         $a1, $at, L_80800210
    if (ctx->r5 == ctx->r1) {
        // 0x8080015C: nop
    
            goto L_80800210;
    }
    // 0x8080015C: nop

    // 0x80800160: b           L_8080024C
    // 0x80800164: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080024C;
    // 0x80800164: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800168:
    // 0x80800168: jal         0x8010A590
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_0;
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800174: jal         0x80101FDC
    // 0x80800178: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800178: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x8080017C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800180: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800184: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800188: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8080018C: jal         0x8010D09C
    // 0x80800190: andi        $a0, $t6, 0xFFFF
    ctx->r4 = ctx->r14 & 0XFFFF;
    func_8010D09C(rdram, ctx);
        goto after_2;
    // 0x80800190: andi        $a0, $t6, 0xFFFF
    ctx->r4 = ctx->r14 & 0XFFFF;
    after_2:
    // 0x80800194: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800198: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080019C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808001A0: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x808001A4: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x808001A8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808001AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808001B0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x808001B4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808001B8: jal         0x800EFB24
    // 0x808001BC: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    func_800EFB24(rdram, ctx);
        goto after_3;
    // 0x808001BC: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x808001C0: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x808001C4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808001C8: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x808001CC: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x808001D0: nop

    // 0x808001D4: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808001D8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808001DC: jal         0x800EF368
    // 0x808001E0: nop

    func_800EF368(rdram, ctx);
        goto after_4;
    // 0x808001E0: nop

    after_4:
    // 0x808001E4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1488, 0X4F8) << 16);
    // 0x808001E8: addiu       $a2, $a2, 0x4F8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1488, 0X4F8));
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F0: jal         0x80089D18
    // 0x808001F4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x808001F4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x808001F8: b           L_8080024C
    // 0x808001FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080024C;
    // 0x808001FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800200:
    // 0x80800200: jal         0x80800260
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800260_chgruntyfireball(rdram, ctx);
        goto after_6;
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800208: b           L_8080024C
    // 0x8080020C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080024C;
    // 0x8080020C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800210:
    // 0x80800210: jal         0x800C8A98
    // 0x80800214: nop

    func_800C8A98(rdram, ctx);
        goto after_7;
    // 0x80800214: nop

    after_7:
    // 0x80800218: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x8080021C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800220: jal         0x800C8CB8
    // 0x80800224: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C8CB8(rdram, ctx);
        goto after_8;
    // 0x80800224: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_8:
    // 0x80800228: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1488, 0X50C) << 16);
    // 0x8080022C: addiu       $a1, $a1, 0x50C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1488, 0X50C));
    // 0x80800230: jal         0x800C8D4C
    // 0x80800234: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    func_800C8D4C(rdram, ctx);
        goto after_9;
    // 0x80800234: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    after_9:
    // 0x80800238: b           L_8080024C
    // 0x8080023C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080024C;
    // 0x8080023C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800240: b           L_8080024C
    // 0x80800244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080024C;
    // 0x80800244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800248: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080024C:
    // 0x8080024C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800250: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800254: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800258: jr          $ra
    // 0x8080025C: nop

    return;
    // 0x8080025C: nop

;}
RECOMP_FUNC void func_808007D8_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808007DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808007E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007E8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x808007EC: jal         0x80800064
    // 0x808007F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800064_bssnowball(rdram, ctx);
        goto after_0;
    // 0x808007F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808007F4: jal         0x80800000
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bssnowball(rdram, ctx);
        goto after_1;
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808007FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800800: jal         0x80091A30
    // 0x80800804: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_2;
    // 0x80800804: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x80800808: beql        $v0, $zero, L_8080083C
    if (ctx->r2 == 0) {
        // 0x8080080C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080083C;
    }
    goto skip_0;
    // 0x8080080C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800810: jal         0x8009BB50
    // 0x80800814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_3;
    // 0x80800814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800818: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080081C: nop

    // 0x80800820: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800824: nop

    // 0x80800828: bc1fl       L_8080083C
    if (!c1cs) {
        // 0x8080082C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080083C;
    }
    goto skip_1;
    // 0x8080082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800830: jal         0x8009BC6C
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_4;
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080083C:
    // 0x8080083C: jal         0x8008DF8C
    // 0x80800840: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    func_8008DF8C(rdram, ctx);
        goto after_5;
    // 0x80800840: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    after_5:
    // 0x80800844: beq         $v0, $zero, L_80800854
    if (ctx->r2 == 0) {
        // 0x80800848: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800854;
    }
    // 0x80800848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080084C: jal         0x8009D3A8
    // 0x80800850: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_6;
    // 0x80800850: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_80800854:
    // 0x80800854: jal         0x8008E078
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_7;
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080085C: beq         $v0, $zero, L_80800874
    if (ctx->r2 == 0) {
        // 0x80800860: nop
    
            goto L_80800874;
    }
    // 0x80800860: nop

    // 0x80800864: jal         0x800A2EAC
    // 0x80800868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A2EAC(rdram, ctx);
        goto after_8;
    // 0x80800868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080086C: addiu       $t6, $zero, 0x17E
    ctx->r14 = ADD32(0, 0X17E);
    // 0x80800870: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800874:
    // 0x80800874: jal         0x808002F8
    // 0x80800878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bssnowball_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80800878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080087C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800880: jal         0x8009E5C8
    // 0x80800884: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_10;
    // 0x80800884: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_10:
    // 0x80800888: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080088C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800890: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800894: jr          $ra
    // 0x80800898: nop

    return;
    // 0x80800898: nop

;}
RECOMP_FUNC void func_80024EE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024EE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80024EE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024EE8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80024EEC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80024EF0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80024EF4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80024EF8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80024EFC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80024F00: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x80024F04: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80024F08: sw          $zero, 0x10($t9)
    MEM_W(0X10, ctx->r25) = 0;
    // 0x80024F0C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80024F10: sw          $zero, 0xC($t0)
    MEM_W(0XC, ctx->r8) = 0;
    // 0x80024F14: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80024F18: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80024F1C: sw          $t1, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r9;
    // 0x80024F20: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80024F24: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80024F28: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80024F2C: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80024F30: beq         $t5, $zero, L_80025034
    if (ctx->r13 == 0) {
        // 0x80024F34: nop
    
            goto L_80025034;
    }
    // 0x80024F34: nop

L_80024F38:
    // 0x80024F38: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80024F3C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80024F40: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80024F44: sb          $zero, 0x138($t8)
    MEM_B(0X138, ctx->r24) = 0;
    // 0x80024F48: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80024F4C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80024F50: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80024F54: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80024F58: sw          $zero, 0x98($t2)
    MEM_W(0X98, ctx->r10) = 0;
    // 0x80024F5C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80024F60: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80024F64: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80024F68: sb          $zero, 0x118($t5)
    MEM_B(0X118, ctx->r13) = 0;
    // 0x80024F6C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80024F70: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80024F74: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80024F78: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80024F7C: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x80024F80: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x80024F84: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80024F88: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80024F8C: beq         $t2, $zero, L_80024FFC
    if (ctx->r10 == 0) {
        // 0x80024F90: nop
    
            goto L_80024FFC;
    }
    // 0x80024F90: nop

    // 0x80024F94: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80024F98: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80024F9C: sllv        $t5, $t4, $t3
    ctx->r13 = S32(ctx->r12 << (ctx->r11 & 31));
    // 0x80024FA0: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80024FA4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80024FA8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80024FAC: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x80024FB0: or          $t0, $t8, $t7
    ctx->r8 = ctx->r24 | ctx->r15;
    // 0x80024FB4: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80024FB8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80024FBC: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80024FC0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80024FC4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80024FC8: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80024FCC: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80024FD0: addu        $t8, $t4, $t5
    ctx->r24 = ADD32(ctx->r12, ctx->r13);
    // 0x80024FD4: sw          $t2, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r10;
    // 0x80024FD8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80024FDC: jal         0x80025DE4
    // 0x80024FE0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80025DE4(rdram, ctx);
        goto after_0;
    // 0x80024FE0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x80024FE4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80024FE8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80024FEC: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80024FF0: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x80024FF4: b           L_80025010
    // 0x80024FF8: sw          $v0, 0x158($t9)
    MEM_W(0X158, ctx->r25) = ctx->r2;
        goto L_80025010;
    // 0x80024FF8: sw          $v0, 0x158($t9)
    MEM_W(0X158, ctx->r25) = ctx->r2;
L_80024FFC:
    // 0x80024FFC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80025000: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80025004: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80025008: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x8002500C: sw          $zero, 0x18($t5)
    MEM_W(0X18, ctx->r13) = 0;
L_80025010:
    // 0x80025010: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80025014: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80025018: addiu       $t8, $t2, 0x1
    ctx->r24 = ADD32(ctx->r10, 0X1);
    // 0x8002501C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80025020: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80025024: lw          $t6, 0x4($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X4);
    // 0x80025028: sltu        $at, $t8, $t6
    ctx->r1 = ctx->r24 < ctx->r14 ? 1 : 0;
    // 0x8002502C: bne         $at, $zero, L_80024F38
    if (ctx->r1 != 0) {
        // 0x80025030: nop
    
            goto L_80024F38;
    }
    // 0x80025030: nop

L_80025034:
    // 0x80025034: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80025038: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002503C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80025040: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x80025044: lw          $t1, 0x0($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X0);
    // 0x80025048: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8002504C: bgez        $t1, L_80025064
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80025050: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80025064;
    }
    // 0x80025050: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80025054: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80025058: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002505C: nop

    // 0x80025060: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80025064:
    // 0x80025064: div.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80025068: swc1        $f16, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f16.u32l;
    // 0x8002506C: b           L_80025074
    // 0x80025070: nop

        goto L_80025074;
    // 0x80025070: nop

L_80025074:
    // 0x80025074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025078: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002507C: jr          $ra
    // 0x80025080: nop

    return;
    // 0x80025080: nop

;}
RECOMP_FUNC void func_80800BF0_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BF8: jal         0x80800164
    // 0x80800BFC: nop

    func_80800164_bsbanshack(rdram, ctx);
        goto after_0;
    // 0x80800BFC: nop

    after_0:
    // 0x80800C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C08: jr          $ra
    // 0x80800C0C: nop

    return;
    // 0x80800C0C: nop

;}
RECOMP_FUNC void func_8080002C_fxsplash25d(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080002C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800030: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800034: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800038: jal         0x800EE7F8
    // 0x8080003C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8080003C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80800040: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800044: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80800048: jal         0x800FB350
    // 0x8080004C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_800FB350(rdram, ctx);
        goto after_1;
    // 0x8080004C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80800050: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80800054: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800058: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8080005C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800060: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800064: jal         0x800E3980
    // 0x80800068: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    func_800E3980(rdram, ctx);
        goto after_2;
    // 0x80800068: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8080006C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800070: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80800074: jal         0x800EFB24
    // 0x80800078: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800EFB24(rdram, ctx);
        goto after_3;
    // 0x80800078: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x8080007C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800080: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800084: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x80800088: jal         0x800EF368
    // 0x8080008C: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    func_800EF368(rdram, ctx);
        goto after_4;
    // 0x8080008C: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x80800090: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800094: jal         0x800EF04C
    // 0x80800098: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x80800098: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_5:
    // 0x8080009C: jal         0x800B5BE4
    // 0x808000A0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800B5BE4(rdram, ctx);
        goto after_6;
    // 0x808000A0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_6:
    // 0x808000A4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808000A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000AC: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808000B0: beq         $a1, $zero, L_808000D8
    if (ctx->r5 == 0) {
        // 0x808000B4: nop
    
            goto L_808000D8;
    }
    // 0x808000B4: nop

    // 0x808000B8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808000BC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808000C0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x808000C4: nop

    // 0x808000C8: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x808000CC: jal         0x800BA660
    // 0x808000D0: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    func_800BA660(rdram, ctx);
        goto after_7;
    // 0x808000D0: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    after_7:
    // 0x808000D4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_808000D8:
    // 0x808000D8: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2826, 0X110) << 16);
    // 0x808000DC: addiu       $t9, $t9, 0x110
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2826, 0X110));
    // 0x808000E0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808000E4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808000E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808000EC: jal         0x800BABB8
    // 0x808000F0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_8;
    // 0x808000F0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_8:
    // 0x808000F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000F8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808000FC: jr          $ra
    // 0x80800100: nop

    return;
    // 0x80800100: nop

    // 0x80800104: nop

    // 0x80800108: nop

    // 0x8080010C: nop

;}
RECOMP_FUNC void func_800B7D14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7D14: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B7D18: addiu       $v0, $v0, -0x7D50
    ctx->r2 = ADD32(ctx->r2, -0X7D50);
    // 0x800B7D1C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800B7D20: jr          $ra
    // 0x800B7D24: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    return;
    // 0x800B7D24: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80803BE8_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803BE8: jr          $ra
    // 0x80803BEC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80803BEC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_808036B8_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808036B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808036BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808036C0: jal         0x800D37D4
    // 0x808036C4: nop

    func_800D37D4(rdram, ctx);
        goto after_0;
    // 0x808036C4: nop

    after_0:
    // 0x808036C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808036CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808036D0: jr          $ra
    // 0x808036D4: nop

    return;
    // 0x808036D4: nop

;}
RECOMP_FUNC void func_80800000_indrv_fx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080000C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800010: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80800014: jal         0x80106790
    // 0x80800018: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800018: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080001C: lw          $t6, 0x7C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X7C);
    // 0x80800020: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80800024: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800028: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x8080002C: bltz        $t8, L_80800038
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800030: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80800038;
    }
    // 0x80800030: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80800034: bne         $a1, $v0, L_80800080
    if (ctx->r5 != ctx->r2) {
        // 0x80800038: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80800080;
    }
L_80800038:
    // 0x80800038: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8080003C: beq         $a1, $v0, L_80800054
    if (ctx->r5 == ctx->r2) {
        // 0x80800040: addiu       $a2, $sp, 0x24
        ctx->r6 = ADD32(ctx->r29, 0X24);
            goto L_80800054;
    }
    // 0x80800040: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80800044: jal         0x800DBEFC
    // 0x80800048: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_1;
    // 0x80800048: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    after_1:
    // 0x8080004C: b           L_80800068
    // 0x80800050: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
        goto L_80800068;
    // 0x80800050: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
L_80800054:
    // 0x80800054: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80800058: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8080005C: jal         0x800EE88C
    // 0x80800060: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x80800060: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_2:
    // 0x80800064: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
L_80800068:
    // 0x80800068: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8080006C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800070: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80800074: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80800078: jal         0x800BBCB8
    // 0x8080007C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_800BBCB8(rdram, ctx);
        goto after_3;
    // 0x8080007C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_3:
L_80800080:
    // 0x80800080: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800084: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void func_8009DE38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DE38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009DE3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009DE40: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8009DE44: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8009DE48: lw          $t6, 0x104($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X104);
    // 0x8009DE4C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8009DE50: addiu       $t7, $zero, 0x55F0
    ctx->r15 = ADD32(0, 0X55F0);
    // 0x8009DE54: lbu         $a1, 0x2($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X2);
    // 0x8009DE58: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8009DE5C: jal         0x8009DCCC
    // 0x8009DE60: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_8009DCCC(rdram, ctx);
        goto after_0;
    // 0x8009DE60: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x8009DE64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009DE68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009DE6C: jr          $ra
    // 0x8009DE70: nop

    return;
    // 0x8009DE70: nop

;}
RECOMP_FUNC void func_800A055C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A055C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A0560: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A0564: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A0568: jal         0x8008E23C
    // 0x800A056C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008E23C(rdram, ctx);
        goto after_0;
    // 0x800A056C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A0570: beq         $v0, $zero, L_800A0598
    if (ctx->r2 == 0) {
        // 0x800A0574: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800A0598;
    }
    // 0x800A0574: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A0578: jal         0x8008D568
    // 0x800A057C: nop

    func_8008D568(rdram, ctx);
        goto after_1;
    // 0x800A057C: nop

    after_1:
    // 0x800A0580: beq         $v0, $zero, L_800A0590
    if (ctx->r2 == 0) {
        // 0x800A0584: nop
    
            goto L_800A0590;
    }
    // 0x800A0584: nop

    // 0x800A0588: b           L_800A05CC
    // 0x800A058C: addiu       $v0, $zero, 0xE4
    ctx->r2 = ADD32(0, 0XE4);
        goto L_800A05CC;
    // 0x800A058C: addiu       $v0, $zero, 0xE4
    ctx->r2 = ADD32(0, 0XE4);
L_800A0590:
    // 0x800A0590: b           L_800A05CC
    // 0x800A0594: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_800A05CC;
    // 0x800A0594: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800A0598:
    // 0x800A0598: jal         0x8008D1B0
    // 0x800A059C: nop

    func_8008D1B0(rdram, ctx);
        goto after_2;
    // 0x800A059C: nop

    after_2:
    // 0x800A05A0: beql        $v0, $zero, L_800A05CC
    if (ctx->r2 == 0) {
        // 0x800A05A4: lw          $v0, 0x1C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X1C);
            goto L_800A05CC;
    }
    goto skip_0;
    // 0x800A05A4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800A05A8: jal         0x8009EA2C
    // 0x800A05AC: nop

    func_8009EA2C(rdram, ctx);
        goto after_3;
    // 0x800A05AC: nop

    after_3:
    // 0x800A05B0: beq         $v0, $zero, L_800A05C0
    if (ctx->r2 == 0) {
        // 0x800A05B4: nop
    
            goto L_800A05C0;
    }
    // 0x800A05B4: nop

    // 0x800A05B8: b           L_800A05CC
    // 0x800A05BC: addiu       $v0, $zero, 0x18A
    ctx->r2 = ADD32(0, 0X18A);
        goto L_800A05CC;
    // 0x800A05BC: addiu       $v0, $zero, 0x18A
    ctx->r2 = ADD32(0, 0X18A);
L_800A05C0:
    // 0x800A05C0: b           L_800A05CC
    // 0x800A05C4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_800A05CC;
    // 0x800A05C4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800A05C8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800A05CC:
    // 0x800A05CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A05D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A05D4: jr          $ra
    // 0x800A05D8: nop

    return;
    // 0x800A05D8: nop

;}
RECOMP_FUNC void _chfairgroundworker_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085C78: syscall     215
    recomp_syscall_handler(rdram, ctx, 0x80085C78);
    return;
    // 0x80085C7C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _bsdie_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082FC8: syscall     37
    recomp_syscall_handler(rdram, ctx, 0x80082FC8);
    return;
    // 0x80082FCC: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void vector_erase_unordered(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2EA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B2EA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2EA8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800B2EAC: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x800B2EB0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800B2EB4: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800B2EB8: multu       $a1, $a2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2EBC: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800B2EC0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x800B2EC4: subu        $a1, $t9, $a2
    ctx->r5 = SUB32(ctx->r25, ctx->r6);
    // 0x800B2EC8: mflo        $t8
    ctx->r24 = lo;
    // 0x800B2ECC: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    // 0x800B2ED0: jal         0x8001BBC8
    // 0x800B2ED4: nop

    aligned4_memcpy(rdram, ctx);
        goto after_0;
    // 0x800B2ED4: nop

    after_0:
    // 0x800B2ED8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800B2EDC: lw          $t0, 0x8($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X8);
    // 0x800B2EE0: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x800B2EE4: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x800B2EE8: sw          $t2, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r10;
    // 0x800B2EEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2EF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B2EF4: jr          $ra
    // 0x800B2EF8: nop

    return;
    // 0x800B2EF8: nop

;}
RECOMP_FUNC void func_808084AC_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808084AC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808084B0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808084B4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x808084B8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x808084BC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808084C0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808084C4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808084C8: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x808084CC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x808084D0: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x808084D4: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA580) << 16);
    // 0x808084D8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808084DC: lwc1        $f18, -0x5A80($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA580));
    // 0x808084E0: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x808084E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808084E8: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x808084EC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808084F0: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x808084F4: mul.s       $f20, $f16, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808084F8: nop

L_808084FC:
    // 0x808084FC: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80808500: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80808504: jal         0x800F1214
    // 0x80808508: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_800F1214(rdram, ctx);
        goto after_0;
    // 0x80808508: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x8080850C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80808510: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80808514: bne         $s1, $s2, L_808084FC
    if (ctx->r17 != ctx->r18) {
        // 0x80808518: swc1        $f0, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->f0.u32l;
            goto L_808084FC;
    }
    // 0x80808518: swc1        $f0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->f0.u32l;
    // 0x8080851C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80808520: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80808524: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80808528: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8080852C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80808530: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80808534: jr          $ra
    // 0x80808538: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80808538: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800AA200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA200: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AA204: jr          $ra
    // 0x800AA208: sb          $a0, 0x7782($at)
    MEM_B(0X7782, ctx->r1) = ctx->r4;
    return;
    // 0x800AA208: sb          $a0, 0x7782($at)
    MEM_B(0X7782, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_808006A8_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006A8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808006AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808006B0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808006B4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808006B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808006BC: jal         0x80100094
    // 0x808006C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808006C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808006C4: addiu       $t6, $v0, 0x14
    ctx->r14 = ADD32(ctx->r2, 0X14);
    // 0x808006C8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x808006CC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x808006D0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808006D4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808006D8: blez        $t7, L_80800728
    if (SIGNED(ctx->r15) <= 0) {
        // 0x808006DC: nop
    
            goto L_80800728;
    }
    // 0x808006DC: nop

L_808006E0:
    // 0x808006E0: jal         0x800F53D0
    // 0x808006E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F53D0(rdram, ctx);
        goto after_1;
    // 0x808006E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808006E8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808006EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006F0: jal         0x800A18C8
    // 0x808006F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A18C8(rdram, ctx);
        goto after_2;
    // 0x808006F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808006F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006FC: jal         0x800A1870
    // 0x80800700: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A1870(rdram, ctx);
        goto after_3;
    // 0x80800700: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800708: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080070C: jal         0x80085550
    // 0x80800710: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _badeathmatch_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80800710: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80800714: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80800718: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8080071C: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80800720: bne         $at, $zero, L_808006E0
    if (ctx->r1 != 0) {
        // 0x80800724: nop
    
            goto L_808006E0;
    }
    // 0x80800724: nop

L_80800728:
    // 0x80800728: jal         0x80089980
    // 0x8080072C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _sumultiscore_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x8080072C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80800730: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800734: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800738: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080073C: jal         0x80089988
    // 0x80800740: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _sumultiscore_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x80800740: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x80800744: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800748: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080074C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800750: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800754: jr          $ra
    // 0x80800758: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800758: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80808100_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808100: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80808104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80808108: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080810C: jal         0x80808148
    // 0x80808110: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_80808148_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80808110: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80808114: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80808118: jal         0x8080853C
    // 0x8080811C: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    func_8080853C_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x8080811C: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    after_1:
    // 0x80808120: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80808124: jal         0x808084AC
    // 0x80808128: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_808084AC_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80808128: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_2:
    // 0x8080812C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80808130: jal         0x808085A8
    // 0x80808134: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_808085A8_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80808134: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x80808138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080813C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80808140: jr          $ra
    // 0x80808144: nop

    return;
    // 0x80808144: nop

;}
RECOMP_FUNC void bssplitup_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002F4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x808002F8: lw          $v0, 0x15C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X15C);
    // 0x808002FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800300: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800304: beq         $v0, $at, L_8080032C
    if (ctx->r2 == ctx->r1) {
        // 0x80800308: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080032C;
    }
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080030C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800310: beq         $v0, $at, L_80800350
    if (ctx->r2 == ctx->r1) {
        // 0x80800314: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800350;
    }
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800318: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080031C: beq         $v0, $at, L_8080036C
    if (ctx->r2 == ctx->r1) {
        // 0x80800320: nop
    
            goto L_8080036C;
    }
    // 0x80800320: nop

    // 0x80800324: b           L_8080036C
    // 0x80800328: nop

        goto L_8080036C;
    // 0x80800328: nop

L_8080032C:
    // 0x8080032C: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x80800330: jal         0x8008CB10
    // 0x80800334: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    baanim_isAt(rdram, ctx);
        goto after_0;
    // 0x80800334: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_0:
    // 0x80800338: beq         $v0, $zero, L_8080036C
    if (ctx->r2 == 0) {
        // 0x8080033C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080036C;
    }
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800340: jal         0x8080012C
    // 0x80800344: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080012C_bssplitup(rdram, ctx);
        goto after_1;
    // 0x80800344: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800348: b           L_8080036C
    // 0x8080034C: nop

        goto L_8080036C;
    // 0x8080034C: nop

L_80800350:
    // 0x80800350: lui         $a1, 0x3F02
    ctx->r5 = S32(0X3F02 << 16);
    // 0x80800354: jal         0x8008CB10
    // 0x80800358: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    baanim_isAt(rdram, ctx);
        goto after_2;
    // 0x80800358: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    after_2:
    // 0x8080035C: beq         $v0, $zero, L_8080036C
    if (ctx->r2 == 0) {
        // 0x80800360: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080036C;
    }
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800364: jal         0x8080012C
    // 0x80800368: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8080012C_bssplitup(rdram, ctx);
        goto after_3;
    // 0x80800368: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
L_8080036C:
    // 0x8080036C: jal         0x8008CAEC
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_4;
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800374: beq         $v0, $zero, L_8080039C
    if (ctx->r2 == 0) {
        // 0x80800378: addiu       $t6, $zero, 0xBB
        ctx->r14 = ADD32(0, 0XBB);
            goto L_8080039C;
    }
    // 0x80800378: addiu       $t6, $zero, 0xBB
    ctx->r14 = ADD32(0, 0XBB);
    // 0x8080037C: jal         0x800F54E4
    // 0x80800380: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x80800380: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_5:
    // 0x80800384: lw          $t7, 0x184($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X184);
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080038C: beql        $v0, $t7, L_808003A0
    if (ctx->r2 == ctx->r15) {
        // 0x80800390: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003A0;
    }
    goto skip_0;
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800394: jal         0x800F457C
    // 0x80800398: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F457C(rdram, ctx);
        goto after_6;
    // 0x80800398: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
L_8080039C:
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003A0:
    // 0x808003A0: jal         0x8009E5C8
    // 0x808003A4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_7;
    // 0x808003A4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x808003A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003B4: jr          $ra
    // 0x808003B8: nop

    return;
    // 0x808003B8: nop

;}
RECOMP_FUNC void func_800DF38C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF38C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DF390: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DF394: jal         0x800DE318
    // 0x800DF398: nop

    func_800DE318(rdram, ctx);
        goto after_0;
    // 0x800DF398: nop

    after_0:
    // 0x800DF39C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DF3A0: addiu       $v0, $v0, -0x35C0
    ctx->r2 = ADD32(ctx->r2, -0X35C0);
    // 0x800DF3A4: addiu       $t7, $v0, 0x400
    ctx->r15 = ADD32(ctx->r2, 0X400);
    // 0x800DF3A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DF3AC: sw          $v0, 0x400($v0)
    MEM_W(0X400, ctx->r2) = ctx->r2;
    // 0x800DF3B0: sw          $t7, 0x404($v0)
    MEM_W(0X404, ctx->r2) = ctx->r15;
    // 0x800DF3B4: jal         0x800EFD24
    // 0x800DF3B8: addiu       $a0, $a0, -0x31B8
    ctx->r4 = ADD32(ctx->r4, -0X31B8);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x800DF3B8: addiu       $a0, $a0, -0x31B8
    ctx->r4 = ADD32(ctx->r4, -0X31B8);
    after_1:
    // 0x800DF3BC: jal         0x800ADF98
    // 0x800DF3C0: nop

    func_800ADF98(rdram, ctx);
        goto after_2;
    // 0x800DF3C0: nop

    after_2:
    // 0x800DF3C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF3C8: jal         0x8010E334
    // 0x800DF3CC: sw          $v0, -0x37C0($at)
    MEM_W(-0X37C0, ctx->r1) = ctx->r2;
    func_8010E334(rdram, ctx);
        goto after_3;
    // 0x800DF3CC: sw          $v0, -0x37C0($at)
    MEM_W(-0X37C0, ctx->r1) = ctx->r2;
    after_3:
    // 0x800DF3D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DF3D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DF3D8: jr          $ra
    // 0x800DF3DC: nop

    return;
    // 0x800DF3DC: nop

;}
RECOMP_FUNC void func_80800D6C_chvolcanobits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D6C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800D70: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800D74: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800D78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D7C: jal         0x80100094
    // 0x80800D80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800D80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800D84: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1264, 0X12EC) << 16);
    // 0x80800D88: addiu       $a3, $a3, 0x12EC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1264, 0X12EC));
    // 0x80800D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D90: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800D94: jal         0x80089D50
    // 0x80800D98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800D98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80800D9C: beql        $v0, $zero, L_80800DFC
    if (ctx->r2 == 0) {
        // 0x80800DA0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800DFC;
    }
    goto skip_0;
    // 0x80800DA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800DA4: jal         0x8080108C
    // 0x80800DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080108C_chvolcanobits(rdram, ctx);
        goto after_2;
    // 0x80800DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800DAC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1264, 0X10EC) << 16);
    // 0x80800DB0: lwc1        $f6, 0x10EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1264, 0X10EC));
    // 0x80800DB4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800DB8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1264, 0X10F0) << 16);
    // 0x80800DBC: lwc1        $f10, 0x10F0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1264, 0X10F0));
    // 0x80800DC0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800DC4: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800DC8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800DCC: lui         $a3, 0x46FF
    ctx->r7 = S32(0X46FF << 16);
    // 0x80800DD0: ori         $a3, $a3, 0xFE00
    ctx->r7 = ctx->r7 | 0XFE00;
    // 0x80800DD4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80800DD8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800DDC: jal         0x800F12D4
    // 0x80800DE0: nop

    func_800F12D4(rdram, ctx);
        goto after_3;
    // 0x80800DE0: nop

    after_3:
    // 0x80800DE4: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DEC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800DF0: jal         0x80089D38
    // 0x80800DF4: nop

    _subaddieaudioloop_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800DF4: nop

    after_4:
    // 0x80800DF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800DFC:
    // 0x80800DFC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800E00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800E04: jr          $ra
    // 0x80800E08: nop

    return;
    // 0x80800E08: nop

;}
RECOMP_FUNC void func_800E71B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E71B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E71BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E71C0: jal         0x80088738
    // 0x800E71C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _gldialog_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x800E71C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800E71C8: beq         $v0, $zero, L_800E71D8
    if (ctx->r2 == 0) {
        // 0x800E71CC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800E71D8;
    }
    // 0x800E71CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800E71D0: b           L_800E71DC
    // 0x800E71D4: addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
        goto L_800E71DC;
    // 0x800E71D4: addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
L_800E71D8:
    // 0x800E71D8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800E71DC:
    // 0x800E71DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E71E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E71E4: jr          $ra
    // 0x800E71E8: nop

    return;
    // 0x800E71E8: nop

;}
RECOMP_FUNC void func_80800F2C_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    if (tooie_pause_settings_page_counts(rdram, ctx)) return;
    // 0x80800F2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F30: beq         $a1, $zero, L_80800F54
    if (ctx->r5 == 0) {
        // 0x80800F34: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800F54;
    }
    // 0x80800F34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F38: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800F3C: beq         $a1, $at, L_80800F64
    if (ctx->r5 == ctx->r1) {
        // 0x80800F40: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800F64;
    }
    // 0x80800F40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800F44: beq         $a1, $at, L_80800F74
    if (ctx->r5 == ctx->r1) {
        // 0x80800F48: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80800F74;
    }
    // 0x80800F48: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800F4C: b           L_80800F84
    // 0x80800F50: nop

        goto L_80800F84;
    // 0x80800F50: nop

L_80800F54:
    // 0x80800F54: jal         0x80800EA8
    // 0x80800F58: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80800EA8_gcnewpause(rdram, ctx);
        goto after_0;
    // 0x80800F58: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80800F5C: b           L_80800F9C
    // 0x80800F60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800F9C;
    // 0x80800F60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F64:
    // 0x80800F64: jal         0x80800FA8
    // 0x80800F68: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80800FA8_gcnewpause(rdram, ctx);
        goto after_1;
    // 0x80800F68: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x80800F6C: b           L_80800F9C
    // 0x80800F70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800F9C;
    // 0x80800F70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F74:
    // 0x80800F74: jal         0x80801AF8
    // 0x80800F78: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80801AF8_gcnewpause(rdram, ctx);
        goto after_2;
    // 0x80800F78: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80800F7C: b           L_80800F9C
    // 0x80800F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800F9C;
    // 0x80800F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F84:
    // 0x80800F84: jal         0x808016A4
    // 0x80800F88: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_808016A4_gcnewpause(rdram, ctx);
        goto after_3;
    // 0x80800F88: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x80800F8C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800F90: jal         0x808019A4
    // 0x80800F94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_808019A4_gcnewpause(rdram, ctx);
        goto after_4;
    // 0x80800F94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80800F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F9C:
    // 0x80800F9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800FA0: jr          $ra
    // 0x80800FA4: nop

    return;
    // 0x80800FA4: nop

;}
RECOMP_FUNC void func_800F99E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F99E8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F99EC: lbu         $v0, 0x5520($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5520);
    // 0x800F99F0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800F99F4: jr          $ra
    // 0x800F99F8: sltu        $v0, $zero, $t6
    ctx->r2 = 0 < ctx->r14 ? 1 : 0;
    return;
    // 0x800F99F8: sltu        $v0, $zero, $t6
    ctx->r2 = 0 < ctx->r14 ? 1 : 0;
;}
RECOMP_FUNC void boot_osDestroyThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800E2A14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2A14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E2A18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E2A1C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800E2A20: jal         0x800E22F0
    // 0x800E2A24: lw          $a1, -0x2B10($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2B10);
    func_800E22F0(rdram, ctx);
        goto after_0;
    // 0x800E2A24: lw          $a1, -0x2B10($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2B10);
    after_0:
    // 0x800E2A28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E2A2C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E2A30: sw          $zero, -0x2B10($at)
    MEM_W(-0X2B10, ctx->r1) = 0;
    // 0x800E2A34: jr          $ra
    // 0x800E2A38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800E2A38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80803320_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803320: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803324: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80803328: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8080332C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803330: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80803334: jal         0x80089C78
    // 0x80803338: addiu       $a0, $zero, 0x52B
    ctx->r4 = ADD32(0, 0X52B);
    _subaddiefind_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80803338: addiu       $a0, $zero, 0x52B
    ctx->r4 = ADD32(0, 0X52B);
    after_0:
    // 0x8080333C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80803340: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803344: jal         0x80102424
    // 0x80803348: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80803348: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x8080334C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80803350: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80803354: sw          $t6, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->r14;
    // 0x80803358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080335C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803360: jr          $ra
    // 0x80803364: nop

    return;
    // 0x80803364: nop

;}
RECOMP_FUNC void chicestationbits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1220, 0X280) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x280
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1220, 0X280));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x280
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1220, 0X280));
;}
RECOMP_FUNC void func_800C99B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C99B4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800C99B8: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x800C99BC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800C99C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C99C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C99C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C99CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C99D0: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C99D4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800C99D8: jal         0x800C3FF0
    // 0x800C99DC: nop

    func_800C3FF0(rdram, ctx);
        goto after_0;
    // 0x800C99DC: nop

    after_0:
    // 0x800C99E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C99E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C99E8: jr          $ra
    // 0x800C99EC: nop

    return;
    // 0x800C99EC: nop

;}
RECOMP_FUNC void _fxfontstring_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088978: syscall     713
    recomp_syscall_handler(rdram, ctx, 0x80088978);
    return;
    // 0x8008897C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800468_bskazpaddle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800468: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080046C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800470: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800474: jal         0x80800068
    // 0x80800478: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800068_bskazpaddle(rdram, ctx);
        goto after_0;
    // 0x80800478: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080047C: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80800480: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800488: jal         0x8008CB3C
    // 0x8080048C: addiu       $a1, $zero, 0x139
    ctx->r5 = ADD32(0, 0X139);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x8080048C: addiu       $a1, $zero, 0x139
    ctx->r5 = ADD32(0, 0X139);
    after_1:
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800494: jal         0x8008CA4C
    // 0x80800498: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008CA4C(rdram, ctx);
        goto after_2;
    // 0x80800498: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8080049C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x808004A0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808004A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A8: jal         0x8008C9BC
    // 0x808004AC: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_3;
    // 0x808004AC: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_3:
    // 0x808004B0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808004B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808004B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004BC: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x808004C0: lui         $a2, 0x43AF
    ctx->r6 = S32(0X43AF << 16);
    // 0x808004C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808004C8: jal         0x8008C9F0
    // 0x808004CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_4;
    // 0x808004CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D4: jal         0x8009C908
    // 0x808004D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    yaw_setUpdateType(rdram, ctx);
        goto after_5;
    // 0x808004D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E0: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x808004E4: jal         0x8009C99C
    // 0x808004E8: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_6;
    // 0x808004E8: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_6:
    // 0x808004EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F0: jal         0x8009D2D8
    // 0x808004F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D2D8(rdram, ctx);
        goto after_7;
    // 0x808004F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004FC: jal         0x8009B800
    // 0x80800500: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    baphysics_set_type(rdram, ctx);
        goto after_8;
    // 0x80800500: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x80800504: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800508: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080050C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800510: jr          $ra
    // 0x80800514: nop

    return;
    // 0x80800514: nop

;}
RECOMP_FUNC void func_800AEAA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEAA0: lh          $t9, 0x4($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X4);
    // 0x800AEAA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AEAA8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800AEAAC: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x800AEAB0: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x800AEAB4: addu        $t9, $t9, $a2
    ctx->r25 = ADD32(ctx->r25, ctx->r6);
L_800AEAB8:
    // 0x800AEAB8: lwc1        $f2, 0x0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800AEABC: lwc1        $f3, 0x4($s2)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r18, 0X4);
    // 0x800AEAC0: lwc1        $f4, 0x8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800AEAC4: add.s       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800AEAC8: lwc1        $f5, 0xC($s2)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r18, 0XC);
    // 0x800AEACC: lwc1        $f6, 0x10($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X10);
    // 0x800AEAD0: add.s       $f13, $f3, $f3
    CHECK_FR(ctx, 13);
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 3);
    NAN_CHECK(ctx->f3.fl); NAN_CHECK(ctx->f3.fl); 
    ctx->f13.fl = ctx->f3.fl + ctx->f3.fl;
    // 0x800AEAD4: mul.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800AEAD8: lwc1        $f7, 0x14($s2)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r18, 0X14);
    // 0x800AEADC: add.s       $f14, $f4, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f4.fl;
    // 0x800AEAE0: mul.s       $f19, $f2, $f13
    CHECK_FR(ctx, 19);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 13);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f13.fl); 
    ctx->f19.fl = MUL_S(ctx->f2.fl, ctx->f13.fl);
    // 0x800AEAE4: lwc1        $f8, 0x18($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X18);
    // 0x800AEAE8: addiu       $s2, $s2, 0x40
    ctx->r18 = ADD32(ctx->r18, 0X40);
    // 0x800AEAEC: mul.s       $f20, $f2, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f20.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x800AEAF0: sw          $zero, -0x34($s2)
    MEM_W(-0X34, ctx->r18) = 0;
    // 0x800AEAF4: sw          $zero, -0x24($s2)
    MEM_W(-0X24, ctx->r18) = 0;
    // 0x800AEAF8: mul.s       $f21, $f3, $f13
    CHECK_FR(ctx, 21);
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 13);
    NAN_CHECK(ctx->f3.fl); NAN_CHECK(ctx->f13.fl); 
    ctx->f21.fl = MUL_S(ctx->f3.fl, ctx->f13.fl);
    // 0x800AEAFC: sw          $zero, -0x14($s2)
    MEM_W(-0X14, ctx->r18) = 0;
    // 0x800AEB00: swc1        $f0, -0x4($s2)
    MEM_W(-0X4, ctx->r18) = ctx->f0.u32l;
    // 0x800AEB04: mul.s       $f22, $f3, $f14
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f3.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f22.fl = MUL_S(ctx->f3.fl, ctx->f14.fl);
    // 0x800AEB08: nop

    // 0x800AEB0C: mul.s       $f23, $f4, $f14
    CHECK_FR(ctx, 23);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f23.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800AEB10: sub.s       $f24, $f0, $f21
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 21);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f21.fl); 
    ctx->f24.fl = ctx->f0.fl - ctx->f21.fl;
    // 0x800AEB14: mul.s       $f15, $f5, $f12
    CHECK_FR(ctx, 15);
    CHECK_FR(ctx, 5);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f5.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f15.fl = MUL_S(ctx->f5.fl, ctx->f12.fl);
    // 0x800AEB18: nop

    // 0x800AEB1C: mul.s       $f16, $f5, $f13
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 5);
    CHECK_FR(ctx, 13);
    NAN_CHECK(ctx->f5.fl); NAN_CHECK(ctx->f13.fl); 
    ctx->f16.fl = MUL_S(ctx->f5.fl, ctx->f13.fl);
    // 0x800AEB20: sub.s       $f24, $f24, $f23
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 23);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f23.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f23.fl;
    // 0x800AEB24: mul.s       $f17, $f5, $f14
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 5);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f5.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f17.fl = MUL_S(ctx->f5.fl, ctx->f14.fl);
    // 0x800AEB28: nop

    // 0x800AEB2C: mul.s       $f24, $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f6.fl);
    // 0x800AEB30: add.s       $f25, $f19, $f17
    CHECK_FR(ctx, 25);
    CHECK_FR(ctx, 19);
    CHECK_FR(ctx, 17);
    NAN_CHECK(ctx->f19.fl); NAN_CHECK(ctx->f17.fl); 
    ctx->f25.fl = ctx->f19.fl + ctx->f17.fl;
    // 0x800AEB34: swc1        $f24, -0x40($s2)
    MEM_W(-0X40, ctx->r18) = ctx->f24.u32l;
    // 0x800AEB38: mul.s       $f25, $f25, $f6
    CHECK_FR(ctx, 25);
    CHECK_FR(ctx, 25);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f25.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f25.fl = MUL_S(ctx->f25.fl, ctx->f6.fl);
    // 0x800AEB3C: sub.s       $f26, $f20, $f16
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f26.fl = ctx->f20.fl - ctx->f16.fl;
    // 0x800AEB40: mul.s       $f26, $f26, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f6.fl);
    // 0x800AEB44: swc1        $f25, -0x3C($s2)
    MEM_W(-0X3C, ctx->r18) = ctx->f_odd[(25 - 1) * 2];
    // 0x800AEB48: sub.s       $f24, $f19, $f17
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 19);
    CHECK_FR(ctx, 17);
    NAN_CHECK(ctx->f19.fl); NAN_CHECK(ctx->f17.fl); 
    ctx->f24.fl = ctx->f19.fl - ctx->f17.fl;
    // 0x800AEB4C: swc1        $f26, -0x38($s2)
    MEM_W(-0X38, ctx->r18) = ctx->f26.u32l;
    // 0x800AEB50: mul.s       $f24, $f24, $f7
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 7);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f7.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f7.fl);
    // 0x800AEB54: sub.s       $f25, $f0, $f18
    CHECK_FR(ctx, 25);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f25.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x800AEB58: sub.s       $f25, $f25, $f23
    CHECK_FR(ctx, 25);
    CHECK_FR(ctx, 25);
    CHECK_FR(ctx, 23);
    NAN_CHECK(ctx->f25.fl); NAN_CHECK(ctx->f23.fl); 
    ctx->f25.fl = ctx->f25.fl - ctx->f23.fl;
    // 0x800AEB5C: swc1        $f24, -0x30($s2)
    MEM_W(-0X30, ctx->r18) = ctx->f24.u32l;
    // 0x800AEB60: mul.s       $f25, $f25, $f7
    CHECK_FR(ctx, 25);
    CHECK_FR(ctx, 25);
    CHECK_FR(ctx, 7);
    NAN_CHECK(ctx->f25.fl); NAN_CHECK(ctx->f7.fl); 
    ctx->f25.fl = MUL_S(ctx->f25.fl, ctx->f7.fl);
    // 0x800AEB64: add.s       $f26, $f22, $f15
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 15);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f15.fl); 
    ctx->f26.fl = ctx->f22.fl + ctx->f15.fl;
    // 0x800AEB68: mul.s       $f26, $f26, $f7
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 7);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f7.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f7.fl);
    // 0x800AEB6C: swc1        $f25, -0x2C($s2)
    MEM_W(-0X2C, ctx->r18) = ctx->f_odd[(25 - 1) * 2];
    // 0x800AEB70: add.s       $f24, $f20, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f24.fl = ctx->f20.fl + ctx->f16.fl;
    // 0x800AEB74: swc1        $f26, -0x28($s2)
    MEM_W(-0X28, ctx->r18) = ctx->f26.u32l;
    // 0x800AEB78: mul.s       $f24, $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x800AEB7C: sub.s       $f25, $f22, $f15
    CHECK_FR(ctx, 25);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 15);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f15.fl); 
    ctx->f25.fl = ctx->f22.fl - ctx->f15.fl;
    // 0x800AEB80: mul.s       $f25, $f25, $f8
    CHECK_FR(ctx, 25);
    CHECK_FR(ctx, 25);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f25.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f25.fl = MUL_S(ctx->f25.fl, ctx->f8.fl);
    // 0x800AEB84: sub.s       $f26, $f0, $f18
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f26.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x800AEB88: swc1        $f24, -0x20($s2)
    MEM_W(-0X20, ctx->r18) = ctx->f24.u32l;
    // 0x800AEB8C: sub.s       $f26, $f26, $f21
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 21);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f21.fl); 
    ctx->f26.fl = ctx->f26.fl - ctx->f21.fl;
    // 0x800AEB90: swc1        $f25, -0x1C($s2)
    MEM_W(-0X1C, ctx->r18) = ctx->f_odd[(25 - 1) * 2];
    // 0x800AEB94: mul.s       $f26, $f26, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f8.fl);
    // 0x800AEB98: bne         $s2, $t9, L_800AEAB8
    if (ctx->r18 != ctx->r25) {
        // 0x800AEB9C: swc1        $f26, -0x18($s2)
        MEM_W(-0X18, ctx->r18) = ctx->f26.u32l;
            goto L_800AEAB8;
    }
    // 0x800AEB9C: swc1        $f26, -0x18($s2)
    MEM_W(-0X18, ctx->r18) = ctx->f26.u32l;
    // 0x800AEBA0: jr          $ra
    // 0x800AEBA4: nop

    return;
    // 0x800AEBA4: nop

;}
RECOMP_FUNC void _gcintrotext_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800880E0: syscall     671
    recomp_syscall_handler(rdram, ctx, 0x800880E0);
    return;
    // 0x800880E4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80026DE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026DE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026DE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026DE8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80026DEC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80026DF0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80026DF4: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80026DF8: beq         $t7, $zero, L_80026E78
    if (ctx->r15 == 0) {
        // 0x80026DFC: nop
    
            goto L_80026E78;
    }
    // 0x80026DFC: nop

    // 0x80026E00: jal         0x80021794
    // 0x80026E04: nop

    func_80021794(rdram, ctx);
        goto after_0;
    // 0x80026E04: nop

    after_0:
    // 0x80026E08: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80026E0C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80026E10: bne         $t8, $zero, L_80026E20
    if (ctx->r24 != 0) {
        // 0x80026E14: nop
    
            goto L_80026E20;
    }
    // 0x80026E14: nop

    // 0x80026E18: b           L_80026E80
    // 0x80026E1C: nop

        goto L_80026E80;
    // 0x80026E1C: nop

L_80026E20:
    // 0x80026E20: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80026E24: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80026E28: lw          $t9, 0x11F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11F4);
    // 0x80026E2C: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80026E30: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80026E34: lw          $t0, 0x1C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1C);
    // 0x80026E38: lw          $t3, 0x88($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X88);
    // 0x80026E3C: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x80026E40: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x80026E44: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80026E48: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80026E4C: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
    // 0x80026E50: lbu         $t8, 0x27($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X27);
    // 0x80026E54: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80026E58: sw          $t8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r24;
    // 0x80026E5C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80026E60: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x80026E64: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80026E68: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80026E6C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80026E70: jal         0x8002B684
    // 0x80026E74: lw          $a0, 0x8($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X8);
    func_8002B684(rdram, ctx);
        goto after_1;
    // 0x80026E74: lw          $a0, 0x8($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X8);
    after_1:
L_80026E78:
    // 0x80026E78: b           L_80026E80
    // 0x80026E7C: nop

        goto L_80026E80;
    // 0x80026E7C: nop

L_80026E80:
    // 0x80026E80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026E84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80026E88: jr          $ra
    // 0x80026E8C: nop

    return;
    // 0x80026E8C: nop

;}
RECOMP_FUNC void func_80800F74_chexploder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F74: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800F78: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800F7C: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80800F80: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80800F84: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800F88: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x80800F8C: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x80800F90: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80800F94: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80800F98: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80800F9C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80800FA0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800FA4: jal         0x80100094
    // 0x80800FA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800FA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800FAC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800FB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800FB4: jal         0x80100094
    // 0x80800FB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800FB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800FBC: lh          $v1, 0xE($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE);
    // 0x80800FC0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800FC4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80800FC8: blezl       $v1, L_808010B8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80800FCC: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_808010B8;
    }
    goto skip_0;
    // 0x80800FCC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
L_80800FD0:
    // 0x80800FD0: lw          $t6, 0x34($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X34);
    // 0x80800FD4: sll         $t8, $t6, 17
    ctx->r24 = S32(ctx->r14 << 17);
    // 0x80800FD8: bgezl       $t8, L_808010A8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800FDC: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_808010A8;
    }
    goto skip_1;
    // 0x80800FDC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_1:
    // 0x80800FE0: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x80800FE4: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x80800FE8: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80800FEC: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80800FF0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800FF4: jal         0x800DC178
    // 0x80800FF8: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800FF8: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_2:
    // 0x80800FFC: lh          $t1, 0x8($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X8);
    // 0x80801000: lh          $t2, 0xA($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XA);
    // 0x80801004: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80801008: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8080100C: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80801010: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80801014: jal         0x800DC178
    // 0x80801018: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80801018: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    after_3:
    // 0x8080101C: lh          $t3, 0x4($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X4);
    // 0x80801020: lh          $t4, 0x6($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X6);
    // 0x80801024: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80801028: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8080102C: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80801030: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80801034: jal         0x800DC178
    // 0x80801038: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80801038: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    after_4:
    // 0x8080103C: lh          $t5, 0x4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X4);
    // 0x80801040: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x80801044: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x80801048: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8080104C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80801050: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801054: jal         0x800DC178
    // 0x80801058: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80801058: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_5:
    // 0x8080105C: addiu       $s2, $s1, 0x18
    ctx->r18 = ADD32(ctx->r17, 0X18);
    // 0x80801060: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801064: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x80801068: jal         0x800EF368
    // 0x8080106C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EF368(rdram, ctx);
        goto after_6;
    // 0x8080106C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x80801070: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801074: jal         0x800EF368
    // 0x80801078: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EF368(rdram, ctx);
        goto after_7;
    // 0x80801078: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x8080107C: trunc.w.s   $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    ctx->f8.u32l = TRUNC_W_S(ctx->f22.fl);
    // 0x80801080: trunc.w.s   $f10, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    ctx->f10.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x80801084: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80801088: trunc.w.s   $f16, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    ctx->f16.u32l = TRUNC_W_S(ctx->f26.fl);
    // 0x8080108C: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80801090: sh          $t8, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r24;
    // 0x80801094: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x80801098: sh          $t0, 0x30($s1)
    MEM_H(0X30, ctx->r17) = ctx->r8;
    // 0x8080109C: sh          $t2, 0x32($s1)
    MEM_H(0X32, ctx->r17) = ctx->r10;
    // 0x808010A0: lh          $v1, 0xE($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE);
    // 0x808010A4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_808010A8:
    // 0x808010A8: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x808010AC: bne         $at, $zero, L_80800FD0
    if (ctx->r1 != 0) {
        // 0x808010B0: addiu       $s1, $s1, 0x3C
        ctx->r17 = ADD32(ctx->r17, 0X3C);
            goto L_80800FD0;
    }
    // 0x808010B0: addiu       $s1, $s1, 0x3C
    ctx->r17 = ADD32(ctx->r17, 0X3C);
    // 0x808010B4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_808010B8:
    // 0x808010B8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808010BC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x808010C0: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x808010C4: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x808010C8: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x808010CC: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x808010D0: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x808010D4: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x808010D8: jr          $ra
    // 0x808010DC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x808010DC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void gcgamefix_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x808000D0
    // 0x8080000C: nop

    func_808000D0_gcgamefix(rdram, ctx);
        goto after_0;
    // 0x8080000C: nop

    after_0:
    // 0x80800010: jal         0x8080011C
    // 0x80800014: nop

    func_8080011C_gcgamefix(rdram, ctx);
        goto after_1;
    // 0x80800014: nop

    after_1:
    // 0x80800018: jal         0x80800164
    // 0x8080001C: nop

    func_80800164_gcgamefix(rdram, ctx);
        goto after_2;
    // 0x8080001C: nop

    after_2:
    // 0x80800020: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    // 0x80800024: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800028: jal         0x800D1864
    // 0x8080002C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D1864(rdram, ctx);
        goto after_3;
    // 0x8080002C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80800030: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800038: jal         0x800D1864
    // 0x8080003C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D1864(rdram, ctx);
        goto after_4;
    // 0x8080003C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80800040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800044: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800048: jr          $ra
    // 0x8080004C: nop

    return;
    // 0x8080004C: nop

;}
RECOMP_FUNC void func_80801ED0_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801ED0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801ED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801ED8: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x80801EDC: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80801EE0: beql        $v0, $zero, L_80801F00
    if (ctx->r2 == 0) {
        // 0x80801EE4: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_80801F00;
    }
    goto skip_0;
    // 0x80801EE4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_0:
    // 0x80801EE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801EEC: beql        $v0, $at, L_80801F1C
    if (ctx->r2 == ctx->r1) {
        // 0x80801EF0: lui         $at, 0x4416
        ctx->r1 = S32(0X4416 << 16);
            goto L_80801F1C;
    }
    goto skip_1;
    // 0x80801EF0: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    skip_1:
    // 0x80801EF4: b           L_80801F38
    // 0x80801EF8: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
        goto L_80801F38;
    // 0x80801EF8: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80801EFC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_80801F00:
    // 0x80801F00: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x80801F04: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801F08: jal         0x800DC178
    // 0x80801F0C: nop

    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x80801F0C: nop

    after_0:
    // 0x80801F10: b           L_80801F50
    // 0x80801F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801F50;
    // 0x80801F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801F18: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
L_80801F1C:
    // 0x80801F1C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801F20: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x80801F24: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801F28: jal         0x800DC178
    // 0x80801F2C: nop

    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80801F2C: nop

    after_1:
    // 0x80801F30: b           L_80801F50
    // 0x80801F34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801F50;
    // 0x80801F34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801F38:
    // 0x80801F38: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801F3C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80801F40: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801F44: jal         0x800DC178
    // 0x80801F48: nop

    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80801F48: nop

    after_2:
    // 0x80801F4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801F50:
    // 0x80801F50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801F54: jr          $ra
    // 0x80801F58: nop

    return;
    // 0x80801F58: nop

;}
RECOMP_FUNC void func_800E82EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E82EC: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800E82F0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800E82F4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800E82F8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800E82FC: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x800E8300: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800E8304: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E8308: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x800E830C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800E8310: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800E8314: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800E8318: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800E831C: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800E8320: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800E8324: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800E8328: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x800E832C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x800E8330: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800E8334: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x800E8338: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800E833C: addiu       $s7, $s7, -0x2A00
    ctx->r23 = ADD32(ctx->r23, -0X2A00);
    // 0x800E8340: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800E8344: addiu       $s1, $sp, 0x8C
    ctx->r17 = ADD32(ctx->r29, 0X8C);
    // 0x800E8348: addiu       $s2, $sp, 0x88
    ctx->r18 = ADD32(ctx->r29, 0X88);
    // 0x800E834C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800E8350: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_800E8354:
    // 0x800E8354: jal         0x800A8984
    // 0x800E8358: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800A8984(rdram, ctx);
        goto after_0;
    // 0x800E8358: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x800E835C: beq         $v0, $zero, L_800E83F8
    if (ctx->r2 == 0) {
        // 0x800E8360: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800E83F8;
    }
    // 0x800E8360: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800E8364: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800E8368: jal         0x800CA6D4
    // 0x800E836C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800CA6D4(rdram, ctx);
        goto after_1;
    // 0x800E836C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_1:
    // 0x800E8370: lwc1        $f2, 0x8C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800E8374: lwc1        $f12, 0x88($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800E8378: lw          $t6, 0x7C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X7C);
    // 0x800E837C: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x800E8380: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800E8384: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800E8388: add.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800E838C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800E8390: addu        $t8, $s7, $t7
    ctx->r24 = ADD32(ctx->r23, ctx->r15);
    // 0x800E8394: div.s       $f0, $f20, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f4.fl);
    // 0x800E8398: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800E839C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800E83A0: nop

    // 0x800E83A4: mul.s       $f16, $f22, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x800E83A8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800E83AC: swc1        $f10, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f10.u32l;
    // 0x800E83B0: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800E83B4: lw          $t0, 0x7C($s7)
    ctx->r8 = MEM_W(ctx->r23, 0X7C);
    // 0x800E83B8: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x800E83BC: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800E83C0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800E83C4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800E83C8: addu        $t2, $s7, $t1
    ctx->r10 = ADD32(ctx->r23, ctx->r9);
    // 0x800E83CC: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x800E83D0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800E83D4: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x800E83D8: lw          $t4, 0x7C($s7)
    ctx->r12 = MEM_W(ctx->r23, 0X7C);
    // 0x800E83DC: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x800E83E0: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800E83E4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800E83E8: addu        $t6, $s7, $t5
    ctx->r14 = ADD32(ctx->r23, ctx->r13);
    // 0x800E83EC: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x800E83F0: b           L_800E8414
    // 0x800E83F4: sw          $s6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r22;
        goto L_800E8414;
    // 0x800E83F4: sw          $s6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r22;
L_800E83F8:
    // 0x800E83F8: lw          $t8, 0x7C($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X7C);
    // 0x800E83FC: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800E8400: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800E8404: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800E8408: addu        $t0, $s7, $t9
    ctx->r8 = ADD32(ctx->r23, ctx->r25);
    // 0x800E840C: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x800E8410: sw          $zero, 0xC($t1)
    MEM_W(0XC, ctx->r9) = 0;
L_800E8414:
    // 0x800E8414: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800E8418: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800E841C: bne         $s3, $at, L_800E8354
    if (ctx->r19 != ctx->r1) {
        // 0x800E8420: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800E8354;
    }
    // 0x800E8420: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800E8424: lw          $t2, 0x7C($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X7C);
    // 0x800E8428: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800E842C: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x800E8430: bne         $at, $zero, L_800E843C
    if (ctx->r1 != 0) {
        // 0x800E8434: sw          $t3, 0x7C($s7)
        MEM_W(0X7C, ctx->r23) = ctx->r11;
            goto L_800E843C;
    }
    // 0x800E8434: sw          $t3, 0x7C($s7)
    MEM_W(0X7C, ctx->r23) = ctx->r11;
    // 0x800E8438: sw          $zero, 0x7C($s7)
    MEM_W(0X7C, ctx->r23) = 0;
L_800E843C:
    // 0x800E843C: jal         0x800DA298
    // 0x800E8440: addiu       $a0, $zero, 0xD4E
    ctx->r4 = ADD32(0, 0XD4E);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x800E8440: addiu       $a0, $zero, 0xD4E
    ctx->r4 = ADD32(0, 0XD4E);
    after_2:
    // 0x800E8444: bne         $v0, $zero, L_800E845C
    if (ctx->r2 != 0) {
        // 0x800E8448: nop
    
            goto L_800E845C;
    }
    // 0x800E8448: nop

    // 0x800E844C: jal         0x800DA298
    // 0x800E8450: addiu       $a0, $zero, 0xD4F
    ctx->r4 = ADD32(0, 0XD4F);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x800E8450: addiu       $a0, $zero, 0xD4F
    ctx->r4 = ADD32(0, 0XD4F);
    after_3:
    // 0x800E8454: beql        $v0, $zero, L_800E8468
    if (ctx->r2 == 0) {
        // 0x800E8458: lw          $a0, 0x0($s7)
        ctx->r4 = MEM_W(ctx->r23, 0X0);
            goto L_800E8468;
    }
    goto skip_0;
    // 0x800E8458: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    skip_0:
L_800E845C:
    // 0x800E845C: jal         0x80085B30
    // 0x800E8460: nop

    _chjiggygamenew_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x800E8460: nop

    after_4:
    // 0x800E8464: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
L_800E8468:
    // 0x800E8468: beql        $a0, $zero, L_800E86A0
    if (ctx->r4 == 0) {
        // 0x800E846C: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_800E86A0;
    }
    goto skip_1;
    // 0x800E846C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_1:
    // 0x800E8470: jal         0x800B3034
    // 0x800E8474: nop

    freelist_capacity(rdram, ctx);
        goto after_5;
    // 0x800E8474: nop

    after_5:
    // 0x800E8478: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800E847C: bne         $at, $zero, L_800E869C
    if (ctx->r1 != 0) {
        // 0x800E8480: sw          $v0, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r2;
            goto L_800E869C;
    }
    // 0x800E8480: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x800E8484: lui         $at, 0x4364
    ctx->r1 = S32(0X4364 << 16);
    // 0x800E8488: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800E848C: lui         $at, 0x4398
    ctx->r1 = S32(0X4398 << 16);
    // 0x800E8490: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800E8494: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800E8498: sw          $s6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r22;
    // 0x800E849C: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
L_800E84A0:
    // 0x800E84A0: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x800E84A4: jal         0x800B31B8
    // 0x800E84A8: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    freelist_is_element_alive(rdram, ctx);
        goto after_6;
    // 0x800E84A8: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    after_6:
    // 0x800E84AC: beq         $v0, $zero, L_800E8684
    if (ctx->r2 == 0) {
        // 0x800E84B0: lw          $a1, 0x98($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X98);
            goto L_800E8684;
    }
    // 0x800E84B0: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x800E84B4: jal         0x800B301C
    // 0x800E84B8: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    freelist_at(rdram, ctx);
        goto after_7;
    // 0x800E84B8: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    after_7:
    // 0x800E84BC: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x800E84C0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800E84C4: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_800E84C8:
    // 0x800E84C8: lw          $v0, 0x7C($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X7C);
    // 0x800E84CC: sll         $t0, $s3, 2
    ctx->r8 = S32(ctx->r19 << 2);
    // 0x800E84D0: subu        $t0, $t0, $s3
    ctx->r8 = SUB32(ctx->r8, ctx->r19);
    // 0x800E84D4: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x800E84D8: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x800E84DC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800E84E0: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x800E84E4: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800E84E8: addu        $t6, $s4, $t5
    ctx->r14 = ADD32(ctx->r20, ctx->r13);
    // 0x800E84EC: addu        $s0, $t6, $s5
    ctx->r16 = ADD32(ctx->r14, ctx->r21);
    // 0x800E84F0: lh          $t7, 0x46($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X46);
    // 0x800E84F4: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x800E84F8: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800E84FC: beq         $t7, $zero, L_800E866C
    if (ctx->r15 == 0) {
        // 0x800E8500: subu        $t8, $t8, $v0
        ctx->r24 = SUB32(ctx->r24, ctx->r2);
            goto L_800E866C;
    }
    // 0x800E8500: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x800E8504: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800E8508: addu        $t9, $s7, $t8
    ctx->r25 = ADD32(ctx->r23, ctx->r24);
    // 0x800E850C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800E8510: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x800E8514: lw          $t1, 0xC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XC);
    // 0x800E8518: beql        $t1, $zero, L_800E8670
    if (ctx->r9 == 0) {
        // 0x800E851C: sh          $fp, 0x34($s0)
        MEM_H(0X34, ctx->r16) = ctx->r30;
            goto L_800E8670;
    }
    goto skip_2;
    // 0x800E851C: sh          $fp, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r30;
    skip_2:
    // 0x800E8520: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800E8524: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x800E8528: nop

    // 0x800E852C: bc1t        L_800E8664
    if (c1cs) {
        // 0x800E8530: nop
    
            goto L_800E8664;
    }
    // 0x800E8530: nop

    // 0x800E8534: c.le.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl <= ctx->f0.fl;
    // 0x800E8538: nop

    // 0x800E853C: bc1t        L_800E8664
    if (c1cs) {
        // 0x800E8540: nop
    
            goto L_800E8664;
    }
    // 0x800E8540: nop

    // 0x800E8544: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800E8548: c.lt.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl < ctx->f22.fl;
    // 0x800E854C: nop

    // 0x800E8550: bc1t        L_800E8664
    if (c1cs) {
        // 0x800E8554: nop
    
            goto L_800E8664;
    }
    // 0x800E8554: nop

    // 0x800E8558: c.le.s      $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f26.fl <= ctx->f2.fl;
    // 0x800E855C: nop

    // 0x800E8560: bc1t        L_800E8664
    if (c1cs) {
        // 0x800E8564: nop
    
            goto L_800E8664;
    }
    // 0x800E8564: nop

    // 0x800E8568: lh          $v0, 0x240($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X240);
    // 0x800E856C: beql        $v0, $zero, L_800E8634
    if (ctx->r2 == 0) {
        // 0x800E8570: trunc.w.s   $f10, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_800E8634;
    }
    goto skip_3;
    // 0x800E8570: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    skip_3:
    // 0x800E8574: bnel        $v0, $s6, L_800E8674
    if (ctx->r2 != ctx->r22) {
        // 0x800E8578: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_800E8674;
    }
    goto skip_4;
    // 0x800E8578: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_4:
    // 0x800E857C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800E8580: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x800E8584: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    // 0x800E8588: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800E858C: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x800E8590: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800E8594: jal         0x800E81E0
    // 0x800E8598: nop

    func_800E81E0(rdram, ctx);
        goto after_8;
    // 0x800E8598: nop

    after_8:
    // 0x800E859C: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800E85A0: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x800E85A4: sub.s       $f20, $f16, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x800E85A8: swc1        $f2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
    // 0x800E85AC: jal         0x800F2100
    // 0x800E85B0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    mlAbsF(rdram, ctx);
        goto after_9;
    // 0x800E85B0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_9:
    // 0x800E85B4: lwc1        $f18, 0xC($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0XC);
    // 0x800E85B8: addiu       $s1, $s0, 0x28
    ctx->r17 = ADD32(ctx->r16, 0X28);
    // 0x800E85BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E85C0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800E85C4: addiu       $a1, $s0, 0x1C
    ctx->r5 = ADD32(ctx->r16, 0X1C);
    // 0x800E85C8: addiu       $s2, $s0, 0x10
    ctx->r18 = ADD32(ctx->r16, 0X10);
    // 0x800E85CC: bc1fl       L_800E85E0
    if (!c1cs) {
        // 0x800E85D0: c.lt.s      $f22, $f20
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
            goto L_800E85E0;
    }
    goto skip_5;
    // 0x800E85D0: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    skip_5:
    // 0x800E85D4: b           L_800E85F8
    // 0x800E85D8: sh          $s6, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r22;
        goto L_800E85F8;
    // 0x800E85D8: sh          $s6, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r22;
    // 0x800E85DC: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
L_800E85E0:
    // 0x800E85E0: nop

    // 0x800E85E4: bc1fl       L_800E85F8
    if (!c1cs) {
        // 0x800E85E8: sh          $s6, 0x34($s0)
        MEM_H(0X34, ctx->r16) = ctx->r22;
            goto L_800E85F8;
    }
    goto skip_6;
    // 0x800E85E8: sh          $s6, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r22;
    skip_6:
    // 0x800E85EC: b           L_800E85F8
    // 0x800E85F0: sh          $zero, 0x34($s0)
    MEM_H(0X34, ctx->r16) = 0;
        goto L_800E85F8;
    // 0x800E85F0: sh          $zero, 0x34($s0)
    MEM_H(0X34, ctx->r16) = 0;
    // 0x800E85F4: sh          $s6, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r22;
L_800E85F8:
    // 0x800E85F8: jal         0x800EFB24
    // 0x800E85FC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800EFB24(rdram, ctx);
        goto after_10;
    // 0x800E85FC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_10:
    // 0x800E8600: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800E8604: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800E8608: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E860C: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800E8610: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800E8614: jal         0x800EF334
    // 0x800E8618: nop

    func_800EF334(rdram, ctx);
        goto after_11;
    // 0x800E8618: nop

    after_11:
    // 0x800E861C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E8620: jal         0x800EF04C
    // 0x800E8624: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EF04C(rdram, ctx);
        goto after_12;
    // 0x800E8624: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_12:
    // 0x800E8628: b           L_800E8674
    // 0x800E862C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_800E8674;
    // 0x800E862C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800E8630: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
L_800E8634:
    // 0x800E8634: trunc.w.s   $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800E8638: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x800E863C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800E8640: jal         0x8001A0C0
    // 0x800E8644: nop

    func_8001A0C0(rdram, ctx);
        goto after_13;
    // 0x800E8644: nop

    after_13:
    // 0x800E8648: ori         $at, $zero, 0xFFFC
    ctx->r1 = 0 | 0XFFFC;
    // 0x800E864C: bne         $v0, $at, L_800E865C
    if (ctx->r2 != ctx->r1) {
        // 0x800E8650: nop
    
            goto L_800E865C;
    }
    // 0x800E8650: nop

    // 0x800E8654: b           L_800E8670
    // 0x800E8658: sh          $s6, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r22;
        goto L_800E8670;
    // 0x800E8658: sh          $s6, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r22;
L_800E865C:
    // 0x800E865C: b           L_800E8670
    // 0x800E8660: sh          $zero, 0x34($s0)
    MEM_H(0X34, ctx->r16) = 0;
        goto L_800E8670;
    // 0x800E8660: sh          $zero, 0x34($s0)
    MEM_H(0X34, ctx->r16) = 0;
L_800E8664:
    // 0x800E8664: b           L_800E8670
    // 0x800E8668: sh          $fp, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r30;
        goto L_800E8670;
    // 0x800E8668: sh          $fp, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r30;
L_800E866C:
    // 0x800E866C: sh          $fp, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r30;
L_800E8670:
    // 0x800E8670: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800E8674:
    // 0x800E8674: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800E8678: addiu       $s5, $s5, 0x38
    ctx->r21 = ADD32(ctx->r21, 0X38);
    // 0x800E867C: bne         $s3, $at, L_800E84C8
    if (ctx->r19 != ctx->r1) {
        // 0x800E8680: sh          $zero, 0x36($s0)
        MEM_H(0X36, ctx->r16) = 0;
            goto L_800E84C8;
    }
    // 0x800E8680: sh          $zero, 0x36($s0)
    MEM_H(0X36, ctx->r16) = 0;
L_800E8684:
    // 0x800E8684: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x800E8688: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x800E868C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800E8690: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800E8694: bne         $at, $zero, L_800E84A0
    if (ctx->r1 != 0) {
        // 0x800E8698: sw          $t7, 0x98($sp)
        MEM_W(0X98, ctx->r29) = ctx->r15;
            goto L_800E84A0;
    }
    // 0x800E8698: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
L_800E869C:
    // 0x800E869C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_800E86A0:
    // 0x800E86A0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800E86A4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800E86A8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800E86AC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x800E86B0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800E86B4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800E86B8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800E86BC: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800E86C0: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800E86C4: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800E86C8: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800E86CC: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x800E86D0: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x800E86D4: jr          $ra
    // 0x800E86D8: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x800E86D8: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_8008DAC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DAC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008DACC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DAD0: jal         0x800DB9B0
    // 0x8008DAD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800DB9B0(rdram, ctx);
        goto after_0;
    // 0x8008DAD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008DAD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008DADC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008DAE0: jr          $ra
    // 0x8008DAE4: nop

    return;
    // 0x8008DAE4: nop

;}
RECOMP_FUNC void func_8009E138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E138: lw          $t6, 0x114($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X114);
    // 0x8009E13C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8009E140: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x8009E144: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8009E148: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8009E14C: jr          $ra
    // 0x8009E150: lwc1        $f0, 0x0($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X0);
    return;
    // 0x8009E150: lwc1        $f0, 0x0($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X0);
;}
RECOMP_FUNC void _glzone_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088778: syscall     703
    recomp_syscall_handler(rdram, ctx, 0x80088778);
    return;
    // 0x8008877C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void mlwave_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800054: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800058: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080005C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800060: jal         0x800D8FF8
    // 0x80800064: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800064: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800068: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8080006C: jal         0x808001A8
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mlwave_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800074: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80800078: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080007C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80800080: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800084: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80800088: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080008C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800090: jal         0x800F15F8
    // 0x80800094: nop

    func_800F15F8(rdram, ctx);
        goto after_2;
    // 0x80800094: nop

    after_2:
    // 0x80800098: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x8080009C: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808000A0: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x808000A4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808000A8: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x808000AC: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x808000B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000BC: jr          $ra
    // 0x808000C0: nop

    return;
    // 0x808000C0: nop

;}
RECOMP_FUNC void func_800C6A7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_voxel_floor_enter(rdram, ctx);
    // 0x800C6A7C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C6A80: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C6A84: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800C6A88: addiu       $s2, $s2, -0x55C0
    ctx->r18 = ADD32(ctx->r18, -0X55C0);
    // 0x800C6A8C: lw          $v1, 0x80($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X80);
    // 0x800C6A90: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C6A94: addiu       $t6, $t6, -0x55BF
    ctx->r14 = ADD32(ctx->r14, -0X55BF);
    // 0x800C6A98: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x800C6A9C: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x800C6AA0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800C6AA4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800C6AA8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C6AAC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C6AB0: sltu        $at, $v1, $t6
    ctx->r1 = ctx->r3 < ctx->r14 ? 1 : 0;
    // 0x800C6AB4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800C6AB8: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800C6ABC: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800C6AC0: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x800C6AC4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800C6AC8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C6ACC: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800C6AD0: sw          $zero, 0x84($s2)
    MEM_W(0X84, ctx->r18) = 0;
    // 0x800C6AD4: bne         $at, $zero, L_800C6B48
    if (ctx->r1 != 0) {
        // 0x800C6AD8: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_800C6B48;
    }
    // 0x800C6AD8: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x800C6ADC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_800C6AE0:
    // 0x800C6AE0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C6AE4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800C6AE8: beq         $v0, $zero, L_800C6B38
    if (ctx->r2 == 0) {
        // 0x800C6AEC: or          $a2, $s5, $zero
        ctx->r6 = ctx->r21 | 0;
            goto L_800C6B38;
    }
    // 0x800C6AEC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800C6AF0: jalr        $v0
    // 0x800C6AF4: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800C6AF4: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_0:
    // 0x800C6AF8: beq         $v0, $zero, L_800C6B20
    if (ctx->r2 == 0) {
        // 0x800C6AFC: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800C6B20;
    }
    // 0x800C6AFC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800C6B00: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x800C6B04: beql        $v0, $zero, L_800C6B20
    if (ctx->r2 == 0) {
        // 0x800C6B08: sw          $zero, 0x84($s2)
        MEM_W(0X84, ctx->r18) = 0;
            goto L_800C6B20;
    }
    goto skip_0;
    // 0x800C6B08: sw          $zero, 0x84($s2)
    MEM_W(0X84, ctx->r18) = 0;
    skip_0:
    // 0x800C6B0C: jalr        $v0
    // 0x800C6B10: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x800C6B10: nop

    after_1:
    // 0x800C6B14: b           L_800C6B20
    // 0x800C6B18: sw          $v0, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r2;
        goto L_800C6B20;
    // 0x800C6B18: sw          $v0, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r2;
    // 0x800C6B1C: sw          $zero, 0x84($s2)
    MEM_W(0X84, ctx->r18) = 0;
L_800C6B20:
    // 0x800C6B20: beql        $s1, $zero, L_800C6B38
    if (ctx->r17 == 0) {
        // 0x800C6B24: lw          $v1, 0x80($s2)
        ctx->r3 = MEM_W(ctx->r18, 0X80);
            goto L_800C6B38;
    }
    goto skip_1;
    // 0x800C6B24: lw          $v1, 0x80($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X80);
    skip_1:
    // 0x800C6B28: or          $s7, $s1, $zero
    ctx->r23 = ctx->r17 | 0;
    // 0x800C6B2C: b           L_800C6B38
    // 0x800C6B30: lw          $v1, 0x80($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X80);
        goto L_800C6B38;
    // 0x800C6B30: lw          $v1, 0x80($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X80);
    // 0x800C6B34: lw          $v1, 0x80($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X80);
L_800C6B38:
    // 0x800C6B38: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800C6B3C: sltu        $at, $s0, $v1
    ctx->r1 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x800C6B40: bnel        $at, $zero, L_800C6AE0
    if (ctx->r1 != 0) {
        // 0x800C6B44: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_800C6AE0;
    }
    goto skip_2;
    // 0x800C6B44: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_2:
L_800C6B48:
    // 0x800C6B48: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    tooie_voxel_floor(rdram, ctx);
    // 0x800C6B4C: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
    // 0x800C6B50: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x800C6B54: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C6B58: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C6B5C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6B60: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C6B64: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800C6B68: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800C6B6C: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800C6B70: jr          $ra
    // 0x800C6B74: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C6B74: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _subaddiejoy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089BB0: syscall     805
    recomp_syscall_handler(rdram, ctx, 0x80089BB0);
    return;
    // 0x80089BB4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80100480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100480: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80100484: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80100488: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8010048C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80100490: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80100494: addiu       $t7, $t7, 0x43A0
    ctx->r15 = ADD32(ctx->r15, 0X43A0);
    // 0x80100498: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8010049C: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x801004A0: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x801004A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801004A8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x801004AC: bnel        $a2, $zero, L_801004DC
    if (ctx->r6 != 0) {
        // 0x801004B0: lh          $t0, 0x2($s0)
        ctx->r8 = MEM_H(ctx->r16, 0X2);
            goto L_801004DC;
    }
    goto skip_0;
    // 0x801004B0: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    skip_0:
    // 0x801004B4: sh          $a1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r5;
    // 0x801004B8: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x801004BC: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x801004C0: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801004C4: mflo        $a0
    ctx->r4 = lo;
    // 0x801004C8: jal         0x8001ACCC
    // 0x801004CC: nop

    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x801004CC: nop

    after_0:
    // 0x801004D0: b           L_8010050C
    // 0x801004D4: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
        goto L_8010050C;
    // 0x801004D4: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x801004D8: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
L_801004DC:
    // 0x801004DC: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x801004E0: beq         $at, $zero, L_8010050C
    if (ctx->r1 == 0) {
        // 0x801004E4: nop
    
            goto L_8010050C;
    }
    // 0x801004E4: nop

    // 0x801004E8: sh          $a3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r7;
    // 0x801004EC: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    // 0x801004F0: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x801004F4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801004F8: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801004FC: mflo        $a1
    ctx->r5 = lo;
    // 0x80100500: jal         0x8001B208
    // 0x80100504: nop

    heap_realloc(rdram, ctx);
        goto after_1;
    // 0x80100504: nop

    after_1:
    // 0x80100508: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
L_8010050C:
    // 0x8010050C: jal         0x8001211C
    // 0x80100510: nop

    func_8001211C(rdram, ctx);
        goto after_2;
    // 0x80100510: nop

    after_2:
    // 0x80100514: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80100518: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8010051C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80100520: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80100524: jr          $ra
    // 0x80100528: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80100528: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _babackpack_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084528: syscall     113
    recomp_syscall_handler(rdram, ctx, 0x80084528);
    return;
    // 0x8008452C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
