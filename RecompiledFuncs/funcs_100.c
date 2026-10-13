#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800D6550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6550: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D6554: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D6558: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D655C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800D6560: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D6564: sll         $t7, $t6, 27
    ctx->r15 = S32(ctx->r14 << 27);
    // 0x800D6568: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x800D656C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800D6570: sltiu       $at, $t9, 0x9
    ctx->r1 = ctx->r25 < 0X9 ? 1 : 0;
    // 0x800D6574: beq         $at, $zero, L_800D6694
    if (ctx->r1 == 0) {
        // 0x800D6578: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800D6694;
    }
    // 0x800D6578: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800D657C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D6580: addu        $at, $at, $t9
    gpr jr_addend_800D6588 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800D6584: lw          $t9, 0x5C78($at)
    ctx->r25 = ADD32(ctx->r1, 0X5C78);
    // 0x800D6588: jr          $t9
    // 0x800D658C: nop

    switch (jr_addend_800D6588 >> 2) {
        case 0: goto L_800D6590; break;
        case 1: goto L_800D65FC; break;
        case 2: goto L_800D6598; break;
        case 3: goto L_800D6598; break;
        case 4: goto L_800D6598; break;
        case 5: goto L_800D65BC; break;
        case 6: goto L_800D65BC; break;
        case 7: goto L_800D6598; break;
        case 8: goto L_800D6590; break;
        default: switch_error(__func__, 0x800D6588, 0x80125C78);
    }
    // 0x800D658C: nop

L_800D6590:
    // 0x800D6590: b           L_800D6698
    // 0x800D6594: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D6698;
    // 0x800D6594: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D6598:
    // 0x800D6598: jal         0x800D5E94
    // 0x800D659C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_800D5E94(rdram, ctx);
        goto after_0;
    // 0x800D659C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_0:
    // 0x800D65A0: bne         $v0, $zero, L_800D65B4
    if (ctx->r2 != 0) {
        // 0x800D65A4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_800D65B4;
    }
    // 0x800D65A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800D65A8: jal         0x800D5804
    // 0x800D65AC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_800D5804(rdram, ctx);
        goto after_1;
    // 0x800D65AC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_1:
    // 0x800D65B0: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_800D65B4:
    // 0x800D65B4: b           L_800D6698
    // 0x800D65B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D6698;
    // 0x800D65B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D65BC:
    // 0x800D65BC: jal         0x8001211C
    // 0x800D65C0: nop

    func_8001211C(rdram, ctx);
        goto after_2;
    // 0x800D65C0: nop

    after_2:
    // 0x800D65C4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800D65C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800D65CC: srl         $t1, $t0, 5
    ctx->r9 = S32(U32(ctx->r8) >> 5);
    // 0x800D65D0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800D65D4: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D65D8: beq         $at, $zero, L_800D65F4
    if (ctx->r1 == 0) {
        // 0x800D65DC: nop
    
            goto L_800D65F4;
    }
    // 0x800D65DC: nop

    // 0x800D65E0: jal         0x800D5804
    // 0x800D65E4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_800D5804(rdram, ctx);
        goto after_3;
    // 0x800D65E4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_3:
    // 0x800D65E8: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800D65EC: b           L_800D6698
    // 0x800D65F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D6698;
    // 0x800D65F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D65F4:
    // 0x800D65F4: b           L_800D6698
    // 0x800D65F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D6698;
    // 0x800D65F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D65FC:
    // 0x800D65FC: jal         0x8001211C
    // 0x800D6600: nop

    func_8001211C(rdram, ctx);
        goto after_4;
    // 0x800D6600: nop

    after_4:
    // 0x800D6604: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800D6608: srl         $t3, $v1, 5
    ctx->r11 = S32(U32(ctx->r3) >> 5);
    // 0x800D660C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800D6610: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D6614: beql        $at, $zero, L_800D6640
    if (ctx->r1 == 0) {
        // 0x800D6618: lw          $t5, 0x8($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X8);
            goto L_800D6640;
    }
    goto skip_0;
    // 0x800D6618: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    skip_0:
    // 0x800D661C: jal         0x800D5E94
    // 0x800D6620: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_800D5E94(rdram, ctx);
        goto after_5;
    // 0x800D6620: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_5:
    // 0x800D6624: bne         $v0, $zero, L_800D6694
    if (ctx->r2 != 0) {
        // 0x800D6628: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_800D6694;
    }
    // 0x800D6628: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800D662C: jal         0x800D5804
    // 0x800D6630: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_800D5804(rdram, ctx);
        goto after_6;
    // 0x800D6630: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_6:
    // 0x800D6634: b           L_800D6694
    // 0x800D6638: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
        goto L_800D6694;
    // 0x800D6638: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800D663C: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
L_800D6640:
    // 0x800D6640: sll         $t7, $t5, 14
    ctx->r15 = S32(ctx->r13 << 14);
    // 0x800D6644: bltz        $t7, L_800D668C
    if (SIGNED(ctx->r15) < 0) {
        // 0x800D6648: nop
    
            goto L_800D668C;
    }
    // 0x800D6648: nop

    // 0x800D664C: lhu         $t8, 0x8($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X8);
    // 0x800D6650: andi        $t0, $v1, 0x1
    ctx->r8 = ctx->r3 & 0X1;
    // 0x800D6654: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800D6658: bne         $t9, $zero, L_800D668C
    if (ctx->r25 != 0) {
        // 0x800D665C: nop
    
            goto L_800D668C;
    }
    // 0x800D665C: nop

    // 0x800D6660: bne         $t0, $zero, L_800D668C
    if (ctx->r8 != 0) {
        // 0x800D6664: nop
    
            goto L_800D668C;
    }
    // 0x800D6664: nop

    // 0x800D6668: jal         0x800D5E94
    // 0x800D666C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_800D5E94(rdram, ctx);
        goto after_7;
    // 0x800D666C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_7:
    // 0x800D6670: bne         $v0, $zero, L_800D6684
    if (ctx->r2 != 0) {
        // 0x800D6674: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_800D6684;
    }
    // 0x800D6674: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800D6678: jal         0x800D5804
    // 0x800D667C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_800D5804(rdram, ctx);
        goto after_8;
    // 0x800D667C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_8:
    // 0x800D6680: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_800D6684:
    // 0x800D6684: b           L_800D6698
    // 0x800D6688: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D6698;
    // 0x800D6688: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D668C:
    // 0x800D668C: b           L_800D6698
    // 0x800D6690: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D6698;
    // 0x800D6690: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D6694:
    // 0x800D6694: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D6698:
    // 0x800D6698: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D669C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D66A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D66A4: jr          $ra
    // 0x800D66A8: nop

    return;
    // 0x800D66A8: nop

;}
RECOMP_FUNC void func_80800570_chnewshovel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800570: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800574: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800578: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080057C: jal         0x801022E4
    // 0x80800580: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_801022E4(rdram, ctx);
        goto after_0;
    // 0x80800580: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800584: addiu       $at, $zero, 0x1BA
    ctx->r1 = ADD32(0, 0X1BA);
    // 0x80800588: beq         $v0, $at, L_808005E4
    if (ctx->r2 == ctx->r1) {
        // 0x8080058C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005E4;
    }
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800590: addiu       $at, $zero, 0x1BB
    ctx->r1 = ADD32(0, 0X1BB);
    // 0x80800594: bne         $v0, $at, L_808005FC
    if (ctx->r2 != ctx->r1) {
        // 0x80800598: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005FC;
    }
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080059C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1516, 0X1008) << 16);
    // 0x808005A0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1516, 0X1018) << 16);
    // 0x808005A4: addiu       $a3, $a3, 0x1018
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1516, 0X1018));
    // 0x808005A8: addiu       $a2, $a2, 0x1008
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1516, 0X1008));
    // 0x808005AC: jal         0x80089D28
    // 0x808005B0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x808005B0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x808005B4: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x808005B8: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808005BC: jal         0x80101E14
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_2;
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808005C4: beql        $v0, $zero, L_80800600
    if (ctx->r2 == 0) {
        // 0x808005C8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800600;
    }
    goto skip_0;
    // 0x808005C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808005CC: jal         0x80800CC4
    // 0x808005D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800CC4_chnewshovel(rdram, ctx);
        goto after_3;
    // 0x808005D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808005D4: jal         0x80800D18
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800D18_chnewshovel(rdram, ctx);
        goto after_4;
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808005DC: b           L_80800600
    // 0x808005E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800600;
    // 0x808005E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005E4:
    // 0x808005E4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1516, 0X1024) << 16);
    // 0x808005E8: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x808005EC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808005F0: addiu       $a2, $a2, 0x1024
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1516, 0X1024));
    // 0x808005F4: jal         0x80089D20
    // 0x808005F8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x808005F8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_5:
L_808005FC:
    // 0x808005FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800600:
    // 0x80800600: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800604: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800608: jr          $ra
    // 0x8080060C: nop

    return;
    // 0x8080060C: nop

;}
RECOMP_FUNC void func_80800BCC_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BD4: jal         0x80100094
    // 0x80800BD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800BD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800BDC: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x80800BE0: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // 0x80800BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BEC: jr          $ra
    // 0x80800BF0: nop

    return;
    // 0x80800BF0: nop

;}
RECOMP_FUNC void func_801002C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801002C0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801002C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801002C8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801002CC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801002D0: jal         0x801001D8
    // 0x801002D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_801001D8(rdram, ctx);
        goto after_0;
    // 0x801002D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x801002D8: jal         0x80089FB8
    // 0x801002DC: nop

    _suautobaddies_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x801002DC: nop

    after_1:
    // 0x801002E0: jal         0x800FFB74
    // 0x801002E4: nop

    func_800FFB74(rdram, ctx);
        goto after_2;
    // 0x801002E4: nop

    after_2:
    // 0x801002E8: jal         0x800F54E4
    // 0x801002EC: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x801002EC: nop

    after_3:
    // 0x801002F0: addiu       $s1, $sp, 0x2C
    ctx->r17 = ADD32(ctx->r29, 0X2C);
    // 0x801002F4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801002F8: jal         0x800F5A00
    // 0x801002FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5A00(rdram, ctx);
        goto after_4;
    // 0x801002FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80100300: addiu       $s2, $sp, 0x3C
    ctx->r18 = ADD32(ctx->r29, 0X3C);
    // 0x80100304: jal         0x801067C4
    // 0x80100308: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_801067C4(rdram, ctx);
        goto after_5;
    // 0x80100308: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x8010030C: beq         $v0, $zero, L_80100350
    if (ctx->r2 == 0) {
        // 0x80100310: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80100350;
    }
    // 0x80100310: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80100314:
    // 0x80100314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80100318: jal         0x80100230
    // 0x8010031C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80100230(rdram, ctx);
        goto after_6;
    // 0x8010031C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x80100320: beq         $v0, $zero, L_80100340
    if (ctx->r2 == 0) {
        // 0x80100324: nop
    
            goto L_80100340;
    }
    // 0x80100324: nop

    // 0x80100328: jal         0x80081D34
    // 0x8010032C: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    func_80081D34(rdram, ctx);
        goto after_7;
    // 0x8010032C: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    after_7:
    // 0x80100330: beq         $v0, $zero, L_80100340
    if (ctx->r2 == 0) {
        // 0x80100334: nop
    
            goto L_80100340;
    }
    // 0x80100334: nop

    // 0x80100338: jal         0x800819B4
    // 0x8010033C: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    func_800819B4(rdram, ctx);
        goto after_8;
    // 0x8010033C: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    after_8:
L_80100340:
    // 0x80100340: jal         0x8010682C
    // 0x80100344: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8010682C(rdram, ctx);
        goto after_9;
    // 0x80100344: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x80100348: bne         $v0, $zero, L_80100314
    if (ctx->r2 != 0) {
        // 0x8010034C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80100314;
    }
    // 0x8010034C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80100350:
    // 0x80100350: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80100354: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80100358: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8010035C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80100360: jr          $ra
    // 0x80100364: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80100364: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8008DE50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DE50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008DE54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DE58: jal         0x80096694
    // 0x8008DE5C: nop

    func_80096694(rdram, ctx);
        goto after_0;
    // 0x8008DE5C: nop

    after_0:
    // 0x8008DE60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008DE64: xori        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 ^ 0X3;
    // 0x8008DE68: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8008DE6C: jr          $ra
    // 0x8008DE70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8008DE70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void vector_end(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B296C: jr          $ra
    // 0x800B2970: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    return;
    // 0x800B2970: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
;}
RECOMP_FUNC void _gccollectDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088020: syscall     666
    recomp_syscall_handler(rdram, ctx, 0x80088020);
    return;
    // 0x80088024: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void strchr_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032A70: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80032A74: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80032A78: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x80032A7C: beql        $t6, $v1, L_80032AA8
    if (ctx->r14 == ctx->r3) {
        // 0x80032A80: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80032AA8;
    }
    goto skip_0;
    // 0x80032A80: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_0:
L_80032A84:
    // 0x80032A84: bnel        $v1, $zero, L_80032A98
    if (ctx->r3 != 0) {
        // 0x80032A88: lbu         $v1, 0x1($a0)
        ctx->r3 = MEM_BU(ctx->r4, 0X1);
            goto L_80032A98;
    }
    goto skip_1;
    // 0x80032A88: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
    skip_1:
    // 0x80032A8C: jr          $ra
    // 0x80032A90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80032A90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80032A94: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
L_80032A98:
    // 0x80032A98: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80032A9C: bne         $v0, $v1, L_80032A84
    if (ctx->r2 != ctx->r3) {
        // 0x80032AA0: nop
    
            goto L_80032A84;
    }
    // 0x80032AA0: nop

    // 0x80032AA4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80032AA8:
    // 0x80032AA8: jr          $ra
    // 0x80032AAC: nop

    return;
    // 0x80032AAC: nop

;}
RECOMP_FUNC void func_808004B8_chfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004C0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808004C4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x808004C8: addiu       $at, $zero, 0x2F6
    ctx->r1 = ADD32(0, 0X2F6);
    // 0x808004CC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808004D0: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x808004D4: srl         $t8, $t7, 22
    ctx->r24 = S32(U32(ctx->r15) >> 22);
    // 0x808004D8: bnel        $t8, $at, L_8080052C
    if (ctx->r24 != ctx->r1) {
        // 0x808004DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080052C;
    }
    goto skip_0;
    // 0x808004DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808004E0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x808004E4: jal         0x800EC708
    // 0x808004E8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800EC708(rdram, ctx);
        goto after_0;
    // 0x808004E8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x808004EC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x808004F0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x808004F4: jal         0x800EC708
    // 0x808004F8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    func_800EC708(rdram, ctx);
        goto after_1;
    // 0x808004F8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    after_1:
    // 0x808004FC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800500: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800504: lwc1        $f4, 0x38($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X38);
    // 0x80800508: div.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8080050C: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80800510: swc1        $f8, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f8.u32l;
    // 0x80800514: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80800518: beql        $t9, $zero, L_8080052C
    if (ctx->r25 == 0) {
        // 0x8080051C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080052C;
    }
    goto skip_1;
    // 0x8080051C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800520: lwc1        $f10, 0x50($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X50);
    // 0x80800524: swc1        $f10, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f10.u32l;
    // 0x80800528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080052C:
    // 0x8080052C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800530: jr          $ra
    // 0x80800534: nop

    return;
    // 0x80800534: nop

;}
RECOMP_FUNC void func_8080000C_chtransparencypot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800010: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800014: jr          $ra
    // 0x80800018: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80800018: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80000540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000540: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000544: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000548: jal         0x80001590
    // 0x8000054C: nop

    func_80001590(rdram, ctx);
        goto after_0;
    // 0x8000054C: nop

    after_0:
    // 0x80000550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000554: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000558: jr          $ra
    // 0x8000055C: nop

    return;
    // 0x8000055C: nop

;}
RECOMP_FUNC void func_80800398_chmineprospector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800398: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080039C: slti        $at, $a1, 0x58
    ctx->r1 = SIGNED(ctx->r5) < 0X58 ? 1 : 0;
    // 0x808003A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003A4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808003A8: bne         $at, $zero, L_808003C4
    if (ctx->r1 != 0) {
        // 0x808003AC: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_808003C4;
    }
    // 0x808003AC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808003B0: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808003B4: beq         $a1, $at, L_808004DC
    if (ctx->r5 == ctx->r1) {
        // 0x808003B8: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808004DC;
    }
    // 0x808003B8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808003BC: b           L_80800530
    // 0x808003C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800530;
    // 0x808003C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003C4:
    // 0x808003C4: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x808003C8: bne         $at, $zero, L_808003F0
    if (ctx->r1 != 0) {
        // 0x808003CC: addiu       $t6, $a1, -0x2E
        ctx->r14 = ADD32(ctx->r5, -0X2E);
            goto L_808003F0;
    }
    // 0x808003CC: addiu       $t6, $a1, -0x2E
    ctx->r14 = ADD32(ctx->r5, -0X2E);
    // 0x808003D0: sltiu       $at, $t6, 0x2A
    ctx->r1 = ctx->r14 < 0X2A ? 1 : 0;
    // 0x808003D4: beq         $at, $zero, L_80800524
    if (ctx->r1 == 0) {
        // 0x808003D8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800524;
    }
    // 0x808003D8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808003DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(892, 0XE60) << 16);
    // 0x808003E0: addu        $at, $at, $t6
    gpr jr_addend_808003E8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808003E4: lw          $t6, 0xE60($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(892, 0XE60));
    // 0x808003E8: jr          $t6
    // 0x808003EC: nop

    switch (jr_addend_808003E8 >> 2) {
        case 0: goto L_80800420; break;
        case 1: goto L_8080043C; break;
        case 2: goto L_80800524; break;
        case 3: goto L_80800458; break;
        case 4: goto L_80800524; break;
        case 5: goto L_80800524; break;
        case 6: goto L_80800524; break;
        case 7: goto L_80800524; break;
        case 8: goto L_80800524; break;
        case 9: goto L_80800524; break;
        case 10: goto L_80800524; break;
        case 11: goto L_80800524; break;
        case 12: goto L_80800524; break;
        case 13: goto L_80800524; break;
        case 14: goto L_80800524; break;
        case 15: goto L_80800478; break;
        case 16: goto L_80800524; break;
        case 17: goto L_80800524; break;
        case 18: goto L_80800524; break;
        case 19: goto L_80800524; break;
        case 20: goto L_80800524; break;
        case 21: goto L_80800524; break;
        case 22: goto L_80800524; break;
        case 23: goto L_80800524; break;
        case 24: goto L_80800524; break;
        case 25: goto L_80800524; break;
        case 26: goto L_80800524; break;
        case 27: goto L_80800524; break;
        case 28: goto L_80800524; break;
        case 29: goto L_80800524; break;
        case 30: goto L_80800524; break;
        case 31: goto L_80800524; break;
        case 32: goto L_80800524; break;
        case 33: goto L_80800524; break;
        case 34: goto L_80800524; break;
        case 35: goto L_80800524; break;
        case 36: goto L_80800488; break;
        case 37: goto L_80800524; break;
        case 38: goto L_80800524; break;
        case 39: goto L_80800524; break;
        case 40: goto L_80800524; break;
        case 41: goto L_808004B0; break;
        default: switch_error(__func__, 0x808003E8, 0x80800E60);
    }
    // 0x808003EC: nop

L_808003F0:
    // 0x808003F0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808003F4: bne         $a1, $at, L_80800524
    if (ctx->r5 != ctx->r1) {
        // 0x808003F8: lw          $t7, 0x28($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X28);
            goto L_80800524;
    }
    // 0x808003F8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x808003FC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800400: bne         $t7, $at, L_80800418
    if (ctx->r15 != ctx->r1) {
        // 0x80800404: nop
    
            goto L_80800418;
    }
    // 0x80800404: nop

    // 0x80800408: jal         0x80800970
    // 0x8080040C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800970_chmineprospector(rdram, ctx);
        goto after_0;
    // 0x8080040C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x80800410: b           L_80800530
    // 0x80800414: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800530;
    // 0x80800414: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800418:
    // 0x80800418: b           L_80800530
    // 0x8080041C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800530;
    // 0x8080041C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800420:
    // 0x80800420: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x80800424: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800428: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x8080042C: jal         0x808006EC
    // 0x80800430: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_808006EC_chmineprospector(rdram, ctx);
        goto after_1;
    // 0x80800430: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x80800434: b           L_80800530
    // 0x80800438: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800530;
    // 0x80800438: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080043C:
    // 0x8080043C: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x80800440: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800444: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800448: jal         0x8080084C
    // 0x8080044C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8080084C_chmineprospector(rdram, ctx);
        goto after_2;
    // 0x8080044C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x80800450: b           L_80800530
    // 0x80800454: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800530;
    // 0x80800454: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800458:
    // 0x80800458: addiu       $a0, $zero, 0x83
    ctx->r4 = ADD32(0, 0X83);
    // 0x8080045C: jal         0x800DA544
    // 0x80800460: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x80800460: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_3:
    // 0x80800464: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800468: jal         0x80102424
    // 0x8080046C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x8080046C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_4:
    // 0x80800470: b           L_80800530
    // 0x80800474: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800530;
    // 0x80800474: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800478:
    // 0x80800478: jal         0x808008A4
    // 0x8080047C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_808008A4_chmineprospector(rdram, ctx);
        goto after_5;
    // 0x8080047C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_5:
    // 0x80800480: b           L_80800530
    // 0x80800484: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800530;
    // 0x80800484: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800488:
    // 0x80800488: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(892, 0XFBC) << 16);
    // 0x8080048C: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x80800490: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80800494: jal         0x80088090
    // 0x80800498: addiu       $a0, $a0, 0xFBC
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(892, 0XFBC));
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800498: addiu       $a0, $a0, 0xFBC
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(892, 0XFBC));
    after_6:
    // 0x8080049C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x808004A0: jal         0x80088098
    // 0x808004A4: addiu       $a0, $a3, 0x28
    ctx->r4 = ADD32(ctx->r7, 0X28);
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x808004A4: addiu       $a0, $a3, 0x28
    ctx->r4 = ADD32(ctx->r7, 0X28);
    after_7:
    // 0x808004A8: b           L_80800530
    // 0x808004AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800530;
    // 0x808004AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004B0:
    // 0x808004B0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808004B4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808004B8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x808004BC: andi        $t8, $a1, 0xFFFF
    ctx->r24 = ctx->r5 & 0XFFFF;
    // 0x808004C0: and         $t9, $a2, $at
    ctx->r25 = ctx->r6 & ctx->r1;
    // 0x808004C4: srl         $a2, $t9, 16
    ctx->r6 = S32(U32(ctx->r25) >> 16);
    // 0x808004C8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x808004CC: jal         0x80800910
    // 0x808004D0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800910_chmineprospector(rdram, ctx);
        goto after_8;
    // 0x808004D0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_8:
    // 0x808004D4: b           L_80800534
    // 0x808004D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800534;
    // 0x808004D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004DC:
    // 0x808004DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808004E0: jal         0x80100094
    // 0x808004E4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80100094(rdram, ctx);
        goto after_9;
    // 0x808004E4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_9:
    // 0x808004E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808004EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808004F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808004F4: jal         0x800897C0
    // 0x808004F8: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_10;
    // 0x808004F8: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    after_10:
    // 0x808004FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800500: jal         0x80100094
    // 0x80800504: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_11;
    // 0x80800504: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800508: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080050C: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80800510: jal         0x800897E8
    // 0x80800514: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_12;
    // 0x80800514: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_12:
    // 0x80800518: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8080051C: b           L_8080052C
    // 0x80800520: sw          $zero, 0x10($t1)
    MEM_W(0X10, ctx->r9) = 0;
        goto L_8080052C;
    // 0x80800520: sw          $zero, 0x10($t1)
    MEM_W(0X10, ctx->r9) = 0;
L_80800524:
    // 0x80800524: b           L_80800530
    // 0x80800528: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800530;
    // 0x80800528: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080052C:
    // 0x8080052C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800530:
    // 0x80800530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800534:
    // 0x80800534: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800538: jr          $ra
    // 0x8080053C: nop

    return;
    // 0x8080053C: nop

;}
RECOMP_FUNC void _suexpression_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800897F8: syscall     795
    recomp_syscall_handler(rdram, ctx, 0x800897F8);
    return;
    // 0x800897FC: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_808001B8_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808001BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808001C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001C8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001CC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808001D0: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    // 0x808001D4: jal         0x80800070
    // 0x808001D8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80800070_bsbtrot(rdram, ctx);
        goto after_0;
    // 0x808001D8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x808001DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001E4: jr          $ra
    // 0x808001E8: nop

    return;
    // 0x808001E8: nop

;}
RECOMP_FUNC void _bstaxi_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083DE8: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083DE8);
    return;
    // 0x80083DEC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void suquiz_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F4: jal         0x800DA544
    // 0x808000F8: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x808000F8: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    after_0:
    // 0x808000FC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80800100: lw          $a0, 0x7614($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7614);
    // 0x80800104: bnel        $a0, $zero, L_80800128
    if (ctx->r4 != 0) {
        // 0x80800108: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800128;
    }
    goto skip_0;
    // 0x80800108: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    skip_0:
    // 0x8080010C: jal         0x8001ACCC
    // 0x80800110: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    heap_alloc(rdram, ctx);
        goto after_1;
    // 0x80800110: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    after_1:
    // 0x80800114: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80800118: sw          $v0, 0x7614($at)
    MEM_W(0X7614, ctx->r1) = ctx->r2;
    // 0x8080011C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80800120: lw          $a0, 0x7614($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7614);
    // 0x80800124: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80800128:
    // 0x80800128: jal         0x8001BCF8
    // 0x8080012C: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    rare_memset(rdram, ctx);
        goto after_2;
    // 0x8080012C: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    after_2:
    // 0x80800130: jal         0x800D3948
    // 0x80800134: nop

    func_800D3948(rdram, ctx);
        goto after_3;
    // 0x80800134: nop

    after_3:
    // 0x80800138: beq         $v0, $zero, L_808001A8
    if (ctx->r2 == 0) {
        // 0x8080013C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808001A8;
    }
    // 0x8080013C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800140: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800144: jal         0x80800C54
    // 0x80800148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    suquiz_entrypoint_21(rdram, ctx);
        goto after_4;
    // 0x80800148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8080014C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800150: jal         0x80800C54
    // 0x80800154: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    suquiz_entrypoint_21(rdram, ctx);
        goto after_5;
    // 0x80800154: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800158: jal         0x80088368
    // 0x8080015C: nop

    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x8080015C: nop

    after_6:
    // 0x80800160: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80800164: beq         $at, $zero, L_80800174
    if (ctx->r1 == 0) {
        // 0x80800168: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80800174;
    }
    // 0x80800168: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080016C: b           L_80800174
    // 0x80800170: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_80800174;
    // 0x80800170: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_80800174:
    // 0x80800174: jal         0x80800C54
    // 0x80800178: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    suquiz_entrypoint_21(rdram, ctx);
        goto after_7;
    // 0x80800178: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_7:
    // 0x8080017C: jal         0x80088368
    // 0x80800180: nop

    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80800180: nop

    after_8:
    // 0x80800184: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80800188: beq         $at, $zero, L_80800198
    if (ctx->r1 == 0) {
        // 0x8080018C: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80800198;
    }
    // 0x8080018C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800190: b           L_80800198
    // 0x80800194: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_80800198;
    // 0x80800194: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_80800198:
    // 0x80800198: jal         0x80800C54
    // 0x8080019C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    suquiz_entrypoint_21(rdram, ctx);
        goto after_9;
    // 0x8080019C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_9:
    // 0x808001A0: b           L_80800224
    // 0x808001A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800224;
    // 0x808001A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001A8:
    // 0x808001A8: jal         0x80800C54
    // 0x808001AC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    suquiz_entrypoint_21(rdram, ctx);
        goto after_10;
    // 0x808001AC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_10:
    // 0x808001B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808001B4: jal         0x80800C54
    // 0x808001B8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    suquiz_entrypoint_21(rdram, ctx);
        goto after_11;
    // 0x808001B8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_11:
    // 0x808001BC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808001C0: jal         0x80800C54
    // 0x808001C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    suquiz_entrypoint_21(rdram, ctx);
        goto after_12;
    // 0x808001C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x808001C8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808001CC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808001D0: jal         0x800DC298
    // 0x808001D4: nop

    func_800DC298(rdram, ctx);
        goto after_13;
    // 0x808001D4: nop

    after_13:
    // 0x808001D8: beq         $v0, $zero, L_808001F0
    if (ctx->r2 == 0) {
        // 0x808001DC: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_808001F0;
    }
    // 0x808001DC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x808001E0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x808001E4: lw          $t6, 0x7614($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7614);
    // 0x808001E8: b           L_80800200
    // 0x808001EC: sb          $zero, 0x31($t6)
    MEM_B(0X31, ctx->r14) = 0;
        goto L_80800200;
    // 0x808001EC: sb          $zero, 0x31($t6)
    MEM_B(0X31, ctx->r14) = 0;
L_808001F0:
    // 0x808001F0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x808001F4: lw          $t8, 0x7614($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7614);
    // 0x808001F8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808001FC: sb          $t7, 0x31($t8)
    MEM_B(0X31, ctx->r24) = ctx->r15;
L_80800200:
    // 0x80800200: lw          $a0, 0x7614($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7614);
    // 0x80800204: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800208: lbu         $t9, 0x31($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X31);
    // 0x8080020C: bnel        $t9, $zero, L_80800220
    if (ctx->r25 != 0) {
        // 0x80800210: sb          $zero, 0x32($a0)
        MEM_B(0X32, ctx->r4) = 0;
            goto L_80800220;
    }
    goto skip_1;
    // 0x80800210: sb          $zero, 0x32($a0)
    MEM_B(0X32, ctx->r4) = 0;
    skip_1:
    // 0x80800214: b           L_80800220
    // 0x80800218: sb          $t0, 0x32($a0)
    MEM_B(0X32, ctx->r4) = ctx->r8;
        goto L_80800220;
    // 0x80800218: sb          $t0, 0x32($a0)
    MEM_B(0X32, ctx->r4) = ctx->r8;
    // 0x8080021C: sb          $zero, 0x32($a0)
    MEM_B(0X32, ctx->r4) = 0;
L_80800220:
    // 0x80800220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800224:
    // 0x80800224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800228: jr          $ra
    // 0x8080022C: nop

    return;
    // 0x8080022C: nop

;}
RECOMP_FUNC void babee_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800274: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x80800278: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080027C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(459, 0X380) << 16);
    // 0x80800280: sb          $zero, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = 0;
    // 0x80800284: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    // 0x80800288: lwc1        $f6, 0x380($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(459, 0X380));
    // 0x8080028C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800290: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800294: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(459, 0X384) << 16);
    // 0x80800298: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x8080029C: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x808002A0: lwc1        $f10, 0x384($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(459, 0X384));
    // 0x808002A4: jr          $ra
    // 0x808002A8: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    return;
    // 0x808002A8: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_800C5A38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5A38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C5A3C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C5A40: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C5A44: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C5A48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C5A4C: jal         0x8001ACCC
    // 0x800C5A50: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x800C5A50: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    after_0:
    // 0x800C5A54: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800C5A58: jal         0x800EFD24
    // 0x800C5A5C: addiu       $a0, $v0, 0x4C
    ctx->r4 = ADD32(ctx->r2, 0X4C);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x800C5A5C: addiu       $a0, $v0, 0x4C
    ctx->r4 = ADD32(ctx->r2, 0X4C);
    after_1:
    // 0x800C5A60: jal         0x800EFD24
    // 0x800C5A64: addiu       $a0, $s2, 0x58
    ctx->r4 = ADD32(ctx->r18, 0X58);
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x800C5A64: addiu       $a0, $s2, 0x58
    ctx->r4 = ADD32(ctx->r18, 0X58);
    after_2:
    // 0x800C5A68: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800C5A6C: addiu       $s1, $s2, 0x1C
    ctx->r17 = ADD32(ctx->r18, 0X1C);
L_800C5A70:
    // 0x800C5A70: jal         0x800EFD24
    // 0x800C5A74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EFD24(rdram, ctx);
        goto after_3;
    // 0x800C5A74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x800C5A78: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800C5A7C: slti        $at, $s0, 0x24
    ctx->r1 = SIGNED(ctx->r16) < 0X24 ? 1 : 0;
    // 0x800C5A80: bne         $at, $zero, L_800C5A70
    if (ctx->r1 != 0) {
        // 0x800C5A84: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_800C5A70;
    }
    // 0x800C5A84: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x800C5A88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C5A8C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800C5A90: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_800C5A94:
    // 0x800C5A94: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800C5A98: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x800C5A9C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C5AA0: sb          $v1, 0x3D($v0)
    MEM_B(0X3D, ctx->r2) = ctx->r3;
    // 0x800C5AA4: sb          $v1, 0x3E($v0)
    MEM_B(0X3E, ctx->r2) = ctx->r3;
    // 0x800C5AA8: sb          $v1, 0x3F($v0)
    MEM_B(0X3F, ctx->r2) = ctx->r3;
    // 0x800C5AAC: bne         $at, $zero, L_800C5A94
    if (ctx->r1 != 0) {
        // 0x800C5AB0: sb          $v1, 0x3C($v0)
        MEM_B(0X3C, ctx->r2) = ctx->r3;
            goto L_800C5A94;
    }
    // 0x800C5AB0: sb          $v1, 0x3C($v0)
    MEM_B(0X3C, ctx->r2) = ctx->r3;
    // 0x800C5AB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C5AB8: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800C5ABC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_800C5AC0:
    // 0x800C5AC0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800C5AC4: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800C5AC8: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x800C5ACC: bne         $a0, $v1, L_800C5AC0
    if (ctx->r4 != ctx->r3) {
        // 0x800C5AD0: sh          $zero, 0xE($v0)
        MEM_H(0XE, ctx->r2) = 0;
            goto L_800C5AC0;
    }
    // 0x800C5AD0: sh          $zero, 0xE($v0)
    MEM_H(0XE, ctx->r2) = 0;
    // 0x800C5AD4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800C5AD8: sh          $zero, 0x16($s2)
    MEM_H(0X16, ctx->r18) = 0;
    // 0x800C5ADC: lh          $t6, 0x16($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X16);
    // 0x800C5AE0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800C5AE4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800C5AE8: sw          $zero, 0x18($s2)
    MEM_W(0X18, ctx->r18) = 0;
    // 0x800C5AEC: sw          $zero, 0xC($s2)
    MEM_W(0XC, ctx->r18) = 0;
    // 0x800C5AF0: addiu       $a0, $s2, 0x64
    ctx->r4 = ADD32(ctx->r18, 0X64);
    // 0x800C5AF4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800C5AF8: jal         0x800EFA4C
    // 0x800C5AFC: sh          $t6, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r14;
    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x800C5AFC: sh          $t6, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r14;
    after_4:
    // 0x800C5B00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C5B04: lwc1        $f4, 0x58A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X58A0);
    // 0x800C5B08: sw          $zero, 0x7C($s2)
    MEM_W(0X7C, ctx->r18) = 0;
    // 0x800C5B0C: sh          $zero, 0x8C($s2)
    MEM_H(0X8C, ctx->r18) = 0;
    // 0x800C5B10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C5B14: swc1        $f4, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->f4.u32l;
    // 0x800C5B18: lwc1        $f6, 0x58A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X58A4);
    // 0x800C5B1C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800C5B20: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C5B24: addiu       $t9, $zero, 0x1F00
    ctx->r25 = ADD32(0, 0X1F00);
    // 0x800C5B28: sw          $zero, 0x80($s2)
    MEM_W(0X80, ctx->r18) = 0;
    // 0x800C5B2C: sb          $zero, 0x8E($s2)
    MEM_B(0X8E, ctx->r18) = 0;
    // 0x800C5B30: sb          $zero, 0x90($s2)
    MEM_B(0X90, ctx->r18) = 0;
    // 0x800C5B34: sb          $zero, 0x8F($s2)
    MEM_B(0X8F, ctx->r18) = 0;
    // 0x800C5B38: sb          $zero, 0x91($s2)
    MEM_B(0X91, ctx->r18) = 0;
    // 0x800C5B3C: sw          $zero, 0x84($s2)
    MEM_W(0X84, ctx->r18) = 0;
    // 0x800C5B40: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x800C5B44: sw          $t9, 0x88($s2)
    MEM_W(0X88, ctx->r18) = ctx->r25;
    // 0x800C5B48: sb          $zero, 0x95($s2)
    MEM_B(0X95, ctx->r18) = 0;
    // 0x800C5B4C: sb          $zero, 0x9C($s2)
    MEM_B(0X9C, ctx->r18) = 0;
    // 0x800C5B50: sb          $zero, 0x94($s2)
    MEM_B(0X94, ctx->r18) = 0;
    // 0x800C5B54: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C5B58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C5B5C: swc1        $f6, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->f6.u32l;
    // 0x800C5B60: jal         0x800C5A10
    // 0x800C5B64: swc1        $f8, 0x78($s2)
    MEM_W(0X78, ctx->r18) = ctx->f8.u32l;
    func_800C5A10(rdram, ctx);
        goto after_5;
    // 0x800C5B64: swc1        $f8, 0x78($s2)
    MEM_W(0X78, ctx->r18) = ctx->f8.u32l;
    after_5:
    // 0x800C5B68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C5B6C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800C5B70: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C5B74: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C5B78: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C5B7C: jr          $ra
    // 0x800C5B80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C5B80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800000_bstwirl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x800A0CF4
    // 0x80800010: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800014: jal         0x800C6DA0
    // 0x80800018: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    func_800C6DA0(rdram, ctx);
        goto after_1;
    // 0x80800018: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    after_1:
    // 0x8080001C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800020: jal         0x80095774
    // 0x80800024: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    baflag_clear(rdram, ctx);
        goto after_2;
    // 0x80800024: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    after_2:
    // 0x80800028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080002C: jal         0x80084A28
    // 0x80800030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _badust_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x80800030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080003C: jr          $ra
    // 0x80800040: nop

    return;
    // 0x80800040: nop

;}
RECOMP_FUNC void func_80800000_chbeehive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080000C: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x80800010: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80800014: jal         0x800EE7F8
    // 0x80800018: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800018: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
    // 0x8080001C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800020: lwc1        $f4, 0x48($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80800024: jal         0x80089F48
    // 0x80800028: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    _subaddiesect_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800028: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    after_1:
    // 0x8080002C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800030: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800034: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800038: lhu         $v1, 0x76($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X76);
    // 0x8080003C: sw          $v0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r2;
    // 0x80800040: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800044: srl         $t6, $v1, 7
    ctx->r14 = S32(U32(ctx->r3) >> 7);
    // 0x80800048: addiu       $t8, $t6, -0x32
    ctx->r24 = ADD32(ctx->r14, -0X32);
    // 0x8080004C: sll         $t0, $t8, 7
    ctx->r8 = S32(ctx->r24 << 7);
    // 0x80800050: andi        $t1, $v1, 0x7F
    ctx->r9 = ctx->r3 & 0X7F;
    // 0x80800054: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x80800058: beq         $v0, $at, L_80800068
    if (ctx->r2 == ctx->r1) {
        // 0x8080005C: sh          $t2, 0x76($a3)
        MEM_H(0X76, ctx->r7) = ctx->r10;
            goto L_80800068;
    }
    // 0x8080005C: sh          $t2, 0x76($a3)
    MEM_H(0X76, ctx->r7) = ctx->r10;
    // 0x80800060: jal         0x80089F50
    // 0x80800064: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiesect_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800064: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_80800068:
    // 0x80800068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080006C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800070: jr          $ra
    // 0x80800074: nop

    return;
    // 0x80800074: nop

;}
RECOMP_FUNC void func_80800518_chpufferfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800518: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080051C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800520: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800524: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800528: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080052C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800530: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800534: beq         $t6, $at, L_8080055C
    if (ctx->r14 == ctx->r1) {
        // 0x80800538: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080055C;
    }
    // 0x80800538: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080053C: beq         $t6, $at, L_80800700
    if (ctx->r14 == ctx->r1) {
        // 0x80800540: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800700;
    }
    // 0x80800540: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800544: beq         $t6, $at, L_80800638
    if (ctx->r14 == ctx->r1) {
        // 0x80800548: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800638;
    }
    // 0x80800548: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080054C: beq         $t6, $at, L_808007B8
    if (ctx->r14 == ctx->r1) {
        // 0x80800550: nop
    
            goto L_808007B8;
    }
    // 0x80800550: nop

    // 0x80800554: b           L_8080085C
    // 0x80800558: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080085C;
    // 0x80800558: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080055C:
    // 0x8080055C: jal         0x80101F24
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_0;
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800564: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2240, 0X1124) << 16);
    // 0x80800568: lwc1        $f4, 0x1124($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2240, 0X1124));
    // 0x8080056C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800570: nop

    // 0x80800574: bc1fl       L_808005CC
    if (!c1cs) {
        // 0x80800578: lw          $t7, 0x64($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X64);
            goto L_808005CC;
    }
    goto skip_0;
    // 0x80800578: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x8080057C: jal         0x80101F24
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_1;
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800584: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2240, 0X1128) << 16);
    // 0x80800588: lwc1        $f6, 0x1128($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2240, 0X1128));
    // 0x8080058C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800590: nop

    // 0x80800594: bc1fl       L_808005CC
    if (!c1cs) {
        // 0x80800598: lw          $t7, 0x64($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X64);
            goto L_808005CC;
    }
    goto skip_1;
    // 0x80800598: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    skip_1:
    // 0x8080059C: jal         0x800DC0C0
    // 0x808005A0: nop

    func_800DC0C0(rdram, ctx);
        goto after_2;
    // 0x808005A0: nop

    after_2:
    // 0x808005A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808005A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808005AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005B0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808005B4: nop

    // 0x808005B8: bc1fl       L_808005CC
    if (!c1cs) {
        // 0x808005BC: lw          $t7, 0x64($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X64);
            goto L_808005CC;
    }
    goto skip_2;
    // 0x808005BC: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    skip_2:
    // 0x808005C0: jal         0x8080093C
    // 0x808005C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080093C_chpufferfish(rdram, ctx);
        goto after_3;
    // 0x808005C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808005C8: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
L_808005CC:
    // 0x808005CC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x808005D0: bgez        $t9, L_80800608
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808005D4: nop
    
            goto L_80800608;
    }
    // 0x808005D4: nop

    // 0x808005D8: jal         0x800D90A4
    // 0x808005DC: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    func_800D90A4(rdram, ctx);
        goto after_4;
    // 0x808005DC: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    after_4:
    // 0x808005E0: beq         $v0, $zero, L_80800858
    if (ctx->r2 == 0) {
        // 0x808005E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800858;
    }
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E8: jal         0x80089BD8
    // 0x808005EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x808005EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808005F0: beq         $v0, $zero, L_80800858
    if (ctx->r2 == 0) {
        // 0x808005F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800858;
    }
    // 0x808005F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F8: jal         0x8080086C
    // 0x808005FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080086C_chpufferfish(rdram, ctx);
        goto after_6;
    // 0x808005FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80800600: b           L_8080085C
    // 0x80800604: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080085C;
    // 0x80800604: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800608:
    // 0x80800608: jal         0x800D90A4
    // 0x8080060C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_7;
    // 0x8080060C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_7:
    // 0x80800610: beq         $v0, $zero, L_80800858
    if (ctx->r2 == 0) {
        // 0x80800614: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800858;
    }
    // 0x80800614: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800618: jal         0x8010C9B0
    // 0x8080061C: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    func_8010C9B0(rdram, ctx);
        goto after_8;
    // 0x8080061C: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    after_8:
    // 0x80800620: beq         $v0, $zero, L_80800858
    if (ctx->r2 == 0) {
        // 0x80800624: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800858;
    }
    // 0x80800624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800628: jal         0x8080086C
    // 0x8080062C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080086C_chpufferfish(rdram, ctx);
        goto after_9;
    // 0x8080062C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x80800630: b           L_8080085C
    // 0x80800634: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080085C;
    // 0x80800634: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800638:
    // 0x80800638: jal         0x80101F24
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_10;
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800640: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2240, 0X112C) << 16);
    // 0x80800644: lwc1        $f10, 0x112C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2240, 0X112C));
    // 0x80800648: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8080064C: nop

    // 0x80800650: bc1fl       L_808006A8
    if (!c1cs) {
        // 0x80800654: lw          $t0, 0x64($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X64);
            goto L_808006A8;
    }
    goto skip_3;
    // 0x80800654: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    skip_3:
    // 0x80800658: jal         0x80101F24
    // 0x8080065C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_11;
    // 0x8080065C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800660: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2240, 0X1130) << 16);
    // 0x80800664: lwc1        $f16, 0x1130($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2240, 0X1130));
    // 0x80800668: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8080066C: nop

    // 0x80800670: bc1fl       L_808006A8
    if (!c1cs) {
        // 0x80800674: lw          $t0, 0x64($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X64);
            goto L_808006A8;
    }
    goto skip_4;
    // 0x80800674: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    skip_4:
    // 0x80800678: jal         0x800DC0C0
    // 0x8080067C: nop

    func_800DC0C0(rdram, ctx);
        goto after_12;
    // 0x8080067C: nop

    after_12:
    // 0x80800680: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800684: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080068C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80800690: nop

    // 0x80800694: bc1fl       L_808006A8
    if (!c1cs) {
        // 0x80800698: lw          $t0, 0x64($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X64);
            goto L_808006A8;
    }
    goto skip_5;
    // 0x80800698: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    skip_5:
    // 0x8080069C: jal         0x8080093C
    // 0x808006A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080093C_chpufferfish(rdram, ctx);
        goto after_13;
    // 0x808006A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x808006A4: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
L_808006A8:
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006AC: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x808006B0: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x808006B4: bgez        $t2, L_808006E0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x808006B8: nop
    
            goto L_808006E0;
    }
    // 0x808006B8: nop

    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C0: jal         0x80089BD8
    // 0x808006C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_14;
    // 0x808006C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x808006C8: beq         $v0, $zero, L_80800858
    if (ctx->r2 == 0) {
        // 0x808006CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800858;
    }
    // 0x808006CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D0: jal         0x8080086C
    // 0x808006D4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080086C_chpufferfish(rdram, ctx);
        goto after_15;
    // 0x808006D4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_15:
    // 0x808006D8: b           L_8080085C
    // 0x808006DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080085C;
    // 0x808006DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808006E0:
    // 0x808006E0: jal         0x80101E14
    // 0x808006E4: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    func_80101E14(rdram, ctx);
        goto after_16;
    // 0x808006E4: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    after_16:
    // 0x808006E8: beq         $v0, $zero, L_80800858
    if (ctx->r2 == 0) {
        // 0x808006EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800858;
    }
    // 0x808006EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F0: jal         0x8080086C
    // 0x808006F4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080086C_chpufferfish(rdram, ctx);
        goto after_17;
    // 0x808006F4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_17:
    // 0x808006F8: b           L_8080085C
    // 0x808006FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080085C;
    // 0x808006FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800700:
    // 0x80800700: jal         0x80101F24
    // 0x80800704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_18;
    // 0x80800704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800708: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8080070C: lwc1        $f14, 0x34($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800710: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800714: add.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x80800718: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8080071C: jal         0x800F1214
    // 0x80800720: nop

    func_800F1214(rdram, ctx);
        goto after_19;
    // 0x80800720: nop

    after_19:
    // 0x80800724: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80800728: jal         0x80101DDC
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_20;
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800730: beq         $v0, $zero, L_80800778
    if (ctx->r2 == 0) {
        // 0x80800734: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800778;
    }
    // 0x80800734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800738: jal         0x80089D40
    // 0x8080073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_21;
    // 0x8080073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800740: lbu         $t3, 0x79($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X79);
    // 0x80800744: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800748: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080074C: srl         $t4, $t3, 4
    ctx->r12 = S32(U32(ctx->r11) >> 4);
    // 0x80800750: bne         $t4, $at, L_80800768
    if (ctx->r12 != ctx->r1) {
        // 0x80800754: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800768;
    }
    // 0x80800754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800758: jal         0x80800274
    // 0x8080075C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800274_chpufferfish(rdram, ctx);
        goto after_22;
    // 0x8080075C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800760: b           L_8080085C
    // 0x80800764: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080085C;
    // 0x80800764: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800768:
    // 0x80800768: jal         0x8080086C
    // 0x8080076C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8080086C_chpufferfish(rdram, ctx);
        goto after_23;
    // 0x8080076C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_23:
    // 0x80800770: b           L_8080085C
    // 0x80800774: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080085C;
    // 0x80800774: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800778:
    // 0x80800778: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2240, 0X1298) << 16);
    // 0x8080077C: addiu       $a3, $a3, 0x1298
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2240, 0X1298));
    // 0x80800780: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800784: jal         0x80089D50
    // 0x80800788: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_24;
    // 0x80800788: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_24:
    // 0x8080078C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2240, 0X1134) << 16);
    // 0x80800790: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x80800794: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800798: lwc1        $f14, 0x1134($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2240, 0X1134));
    // 0x8080079C: jal         0x800F1214
    // 0x808007A0: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    func_800F1214(rdram, ctx);
        goto after_25;
    // 0x808007A0: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_25:
    // 0x808007A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808007A8: jal         0x80089D30
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_0(rdram, ctx);
        goto after_26;
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x808007B0: b           L_8080085C
    // 0x808007B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080085C;
    // 0x808007B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007B8:
    // 0x808007B8: jal         0x80101F24
    // 0x808007BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_27;
    // 0x808007BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x808007C0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x808007C4: lwc1        $f14, 0x34($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808007C8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808007CC: add.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x808007D0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808007D4: jal         0x800F1214
    // 0x808007D8: nop

    func_800F1214(rdram, ctx);
        goto after_28;
    // 0x808007D8: nop

    after_28:
    // 0x808007DC: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808007E0: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x808007E4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808007E8: jal         0x80101E14
    // 0x808007EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_29;
    // 0x808007EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x808007F0: beq         $v0, $zero, L_80800814
    if (ctx->r2 == 0) {
        // 0x808007F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800814;
    }
    // 0x808007F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F8: jal         0x80089D40
    // 0x808007FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_30;
    // 0x808007FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80800800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800804: jal         0x8080086C
    // 0x80800808: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080086C_chpufferfish(rdram, ctx);
        goto after_31;
    // 0x80800808: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_31:
    // 0x8080080C: b           L_80800850
    // 0x80800810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800850;
    // 0x80800810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800814:
    // 0x80800814: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2240, 0X1298) << 16);
    // 0x80800818: addiu       $a3, $a3, 0x1298
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2240, 0X1298));
    // 0x8080081C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800820: jal         0x80089D50
    // 0x80800824: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_32;
    // 0x80800824: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_32:
    // 0x80800828: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2240, 0X1138) << 16);
    // 0x8080082C: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x80800830: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800834: lwc1        $f14, 0x1138($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2240, 0X1138));
    // 0x80800838: jal         0x800F1214
    // 0x8080083C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    func_800F1214(rdram, ctx);
        goto after_33;
    // 0x8080083C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_33:
    // 0x80800840: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800844: jal         0x80089D30
    // 0x80800848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_0(rdram, ctx);
        goto after_34;
    // 0x80800848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x8080084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800850:
    // 0x80800850: jal         0x8080093C
    // 0x80800854: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080093C_chpufferfish(rdram, ctx);
        goto after_35;
    // 0x80800854: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_35:
L_80800858:
    // 0x80800858: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080085C:
    // 0x8080085C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800860: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800864: jr          $ra
    // 0x80800868: nop

    return;
    // 0x80800868: nop

;}
RECOMP_FUNC void chmayaentrydoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1988, 0XE0) << 16);
    // 0x808000D8: jr          $ra
    // 0x808000DC: addiu       $v0, $v0, 0xE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1988, 0XE0));
    return;
    // 0x808000DC: addiu       $v0, $v0, 0xE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1988, 0XE0));
;}
RECOMP_FUNC void suexpressmorph_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808005F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808005F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808005FC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800600: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800604: jal         0x80103AA0
    // 0x80800608: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    func_80103AA0(rdram, ctx);
        goto after_0;
    // 0x80800608: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    after_0:
    // 0x8080060C: beq         $v0, $zero, L_808006C4
    if (ctx->r2 == 0) {
        // 0x80800610: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_808006C4;
    }
    // 0x80800610: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800614: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800618: jal         0x80103CDC
    // 0x8080061C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    func_80103CDC(rdram, ctx);
        goto after_1;
    // 0x8080061C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800620: beq         $v0, $zero, L_808006C4
    if (ctx->r2 == 0) {
        // 0x80800624: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808006C4;
    }
    // 0x80800624: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800628: jal         0x800B2840
    // 0x8080062C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800B2840(rdram, ctx);
        goto after_2;
    // 0x8080062C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x80800630: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800634: jal         0x800B2768
    // 0x80800638: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800B2768(rdram, ctx);
        goto after_3;
    // 0x80800638: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x8080063C: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80800640: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800644: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800648: lbu         $a3, 0x6($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X6);
    // 0x8080064C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80800650: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800654: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800658: jal         0x80087990
    // 0x8080065C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    _dbmorph_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x8080065C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x80800660: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80800664: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(3170, 0X1328) << 16);
    // 0x80800668: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x8080066C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80800670: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80800674: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80800678: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8080067C: lbu         $t1, 0x1328($t1)
    ctx->r9 = MEM_BU(ctx->r9, (int16_t)RELOC_LO16(3170, 0X1328));
    // 0x80800680: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80800684: beql        $t2, $zero, L_808006C8
    if (ctx->r10 == 0) {
        // 0x80800688: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808006C8;
    }
    goto skip_0;
    // 0x80800688: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080068C: lbu         $t4, 0x17($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X17);
    // 0x80800690: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80800694: sb          $t5, 0x17($s0)
    MEM_B(0X17, ctx->r16) = ctx->r13;
    // 0x80800698: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8080069C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x808006A0: jal         0x800AE080
    // 0x808006A4: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    func_800AE080(rdram, ctx);
        goto after_5;
    // 0x808006A4: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    after_5:
    // 0x808006A8: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x808006AC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808006B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808006B4: lbu         $a3, 0x6($t8)
    ctx->r7 = MEM_BU(ctx->r24, 0X6);
    // 0x808006B8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x808006BC: jal         0x80087998
    // 0x808006C0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    _dbmorph_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x808006C0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_6:
L_808006C4:
    // 0x808006C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006C8:
    // 0x808006C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808006CC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808006D0: jr          $ra
    // 0x808006D4: nop

    return;
    // 0x808006D4: nop

;}
RECOMP_FUNC void func_80801AF0_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AF0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80801AF4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801AF8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801AFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801B00: jal         0x80100094
    // 0x80801B04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801B04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801B08: jal         0x800D8FF8
    // 0x80801B0C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80801B0C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80801B10: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80801B14: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80801B18: lh          $a0, 0x128($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X128);
    // 0x80801B1C: jal         0x800F5A00
    // 0x80801B20: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x80801B20: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80801B24: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801B28: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80801B2C: jal         0x800F18FC
    // 0x80801B30: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    func_800F18FC(rdram, ctx);
        goto after_3;
    // 0x80801B30: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_3:
    // 0x80801B34: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80801B38: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80801B3C: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80801B40: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801B44: add.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80801B48: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x80801B4C: mul.s       $f18, $f2, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80801B50: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80801B54: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80801B58: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80801B5C: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    // 0x80801B60: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80801B64: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80801B68: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80801B6C: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x80801B70: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x80801B74: jal         0x800F1FF0
    // 0x80801B78: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_4;
    // 0x80801B78: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x80801B7C: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80801B80: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80801B84: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80801B88: lwc1        $f12, 0x44($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80801B8C: lwc1        $f14, 0x50($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80801B90: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80801B94: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80801B98: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80801B9C: jal         0x800F1FF0
    // 0x80801BA0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_5;
    // 0x80801BA0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x80801BA4: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80801BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BAC: jal         0x80102CF4
    // 0x80801BB0: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    func_80102CF4(rdram, ctx);
        goto after_6;
    // 0x80801BB0: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    after_6:
    // 0x80801BB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801BB8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801BBC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80801BC0: jr          $ra
    // 0x80801BC4: nop

    return;
    // 0x80801BC4: nop

;}
RECOMP_FUNC void func_800F8088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8088: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F808C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F8090: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F8094: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F8098: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F809C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F80A0: jal         0x80091D00
    // 0x800F80A4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    bakey_getBitfield(rdram, ctx);
        goto after_0;
    // 0x800F80A4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F80A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F80AC: jal         0x8009F1A4
    // 0x800F80B0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    bastick_func_8009F1A4(rdram, ctx);
        goto after_1;
    // 0x800F80B0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x800F80B4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800F80B8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800F80BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F80C0: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x800F80C4: beq         $t7, $zero, L_800F80D0
    if (ctx->r15 == 0) {
        // 0x800F80C8: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800F80D0;
    }
    // 0x800F80C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800F80CC: sltu        $v0, $zero, $v1
    ctx->r2 = 0 < ctx->r3 ? 1 : 0;
L_800F80D0:
    // 0x800F80D0: jr          $ra
    // 0x800F80D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800F80D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bainput_should_trot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009809C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800980A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800980A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800980A8: jal         0x80091A58
    // 0x800980AC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x800980AC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_0:
    // 0x800980B0: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x800980B4: beq         $t6, $zero, L_800980CC
    if (ctx->r14 == 0) {
        // 0x800980B8: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_800980CC;
    }
    // 0x800980B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800980BC: jal         0x8008D8E4
    // 0x800980C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008D8E4(rdram, ctx);
        goto after_1;
    // 0x800980C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800980C4: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x800980C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800980CC:
    // 0x800980CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800980D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800980D4: jr          $ra
    // 0x800980D8: nop

    return;
    // 0x800980D8: nop

;}
RECOMP_FUNC void func_80800394_chballoonbomb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800394: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800398: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080039C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808003A0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808003A4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808003A8: jal         0x800B53A4
    // 0x808003AC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x808003AC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x808003B0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808003B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003B8: jal         0x800BA670
    // 0x808003BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800BA670(rdram, ctx);
        goto after_1;
    // 0x808003BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x808003C0: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x808003C4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(836, 0X540) << 16);
    // 0x808003C8: addiu       $t6, $t6, 0x540
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(836, 0X540));
    // 0x808003CC: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x808003D0: lw          $a3, 0x38($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X38);
    // 0x808003D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808003D8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808003DC: jal         0x800BABB8
    // 0x808003E0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x808003E0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x808003E4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808003E8: jal         0x800BA22C
    // 0x808003EC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800BA22C(rdram, ctx);
        goto after_3;
    // 0x808003EC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x808003F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003F8: jr          $ra
    // 0x808003FC: nop

    return;
    // 0x808003FC: nop

;}
RECOMP_FUNC void func_800DF874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF874: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DF878: lw          $a0, -0x37C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X37C0);
    // 0x800DF87C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DF880: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DF884: beq         $a0, $zero, L_800DF89C
    if (ctx->r4 == 0) {
        // 0x800DF888: nop
    
            goto L_800DF89C;
    }
    // 0x800DF888: nop

    // 0x800DF88C: jal         0x800AE5F0
    // 0x800DF890: nop

    func_800AE5F0(rdram, ctx);
        goto after_0;
    // 0x800DF890: nop

    after_0:
    // 0x800DF894: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF898: sw          $v0, -0x37C0($at)
    MEM_W(-0X37C0, ctx->r1) = ctx->r2;
L_800DF89C:
    // 0x800DF89C: jal         0x8010E358
    // 0x800DF8A0: nop

    func_8010E358(rdram, ctx);
        goto after_1;
    // 0x800DF8A0: nop

    after_1:
    // 0x800DF8A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DF8A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DF8AC: jr          $ra
    // 0x800DF8B0: nop

    return;
    // 0x800DF8B0: nop

;}
RECOMP_FUNC void _bawandglow_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800853C8: syscall     160
    recomp_syscall_handler(rdram, ctx, 0x800853C8);
    return;
    // 0x800853CC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _idglowa_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088D90: syscall     739
    recomp_syscall_handler(rdram, ctx, 0x80088D90);
    return;
    // 0x80088D94: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _sumultiscore_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089998: syscall     799
    recomp_syscall_handler(rdram, ctx, 0x80089998);
    return;
    // 0x8008999C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_8080362C_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080362C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803630: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803634: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80803638: jal         0x80102424
    // 0x8080363C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x8080363C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80803640: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80803644: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803648: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x8080364C: beq         $t6, $at, L_808036C0
    if (ctx->r14 == ctx->r1) {
        // 0x80803650: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808036C0;
    }
    // 0x80803650: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803654: beq         $t6, $at, L_8080367C
    if (ctx->r14 == ctx->r1) {
        // 0x80803658: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080367C;
    }
    // 0x80803658: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080365C: beq         $t6, $at, L_80803694
    if (ctx->r14 == ctx->r1) {
        // 0x80803660: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80803694;
    }
    // 0x80803660: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80803664: bnel        $t6, $at, L_808036E4
    if (ctx->r14 != ctx->r1) {
        // 0x80803668: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_808036E4;
    }
    goto skip_0;
    // 0x80803668: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_0:
    // 0x8080366C: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80803670: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x80803674: b           L_808036E0
    // 0x80803678: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
        goto L_808036E0;
    // 0x80803678: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
L_8080367C:
    // 0x8080367C: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80803680: ori         $t4, $t1, 0x1
    ctx->r12 = ctx->r9 | 0X1;
    // 0x80803684: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
    // 0x80803688: ori         $t5, $t4, 0x8
    ctx->r13 = ctx->r12 | 0X8;
    // 0x8080368C: b           L_808036E0
    // 0x80803690: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
        goto L_808036E0;
    // 0x80803690: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
L_80803694:
    // 0x80803694: jal         0x800DA524
    // 0x80803698: addiu       $a0, $zero, 0xA33
    ctx->r4 = ADD32(0, 0XA33);
    func_800DA524(rdram, ctx);
        goto after_1;
    // 0x80803698: addiu       $a0, $zero, 0xA33
    ctx->r4 = ADD32(0, 0XA33);
    after_1:
    // 0x8080369C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808036A0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808036A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808036A8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808036AC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808036B0: jal         0x800EFA4C
    // 0x808036B4: nop

    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x808036B4: nop

    after_2:
    // 0x808036B8: b           L_808036E4
    // 0x808036BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
        goto L_808036E4;
    // 0x808036BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_808036C0:
    // 0x808036C0: jal         0x800DA524
    // 0x808036C4: addiu       $a0, $zero, 0xA32
    ctx->r4 = ADD32(0, 0XA32);
    func_800DA524(rdram, ctx);
        goto after_3;
    // 0x808036C4: addiu       $a0, $zero, 0xA32
    ctx->r4 = ADD32(0, 0XA32);
    after_3:
    // 0x808036C8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808036CC: jal         0x800EE7F8
    // 0x808036D0: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x808036D0: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_4:
    // 0x808036D4: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x808036D8: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x808036DC: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
L_808036E0:
    // 0x808036E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_808036E4:
    // 0x808036E4: nop

    // 0x808036E8: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x808036EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808036F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808036F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808036F8: jr          $ra
    // 0x808036FC: nop

    return;
    // 0x808036FC: nop

;}
RECOMP_FUNC void func_80800008_glgamedata(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8080000C: jr          $ra
    // 0x80800010: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    return;
    // 0x80800010: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void _chpufferfish_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087410: syscall     568
    recomp_syscall_handler(rdram, ctx, 0x80087410);
    return;
    // 0x80087414: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800858_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800858: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x8080085C: jr          $ra
    // 0x80800860: sw          $a1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r5;
    return;
    // 0x80800860: sw          $a1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void func_80800000_gcsectionskip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800004: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80800008: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8080000C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800014: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80800018: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080001C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80800020: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800024: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x80800028: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080002C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80800030: jal         0x800EE7F8
    // 0x80800034: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800034: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80800038: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x8080003C: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80800040: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800044: bnel        $t6, $zero, L_808000E8
    if (ctx->r14 != 0) {
        // 0x80800048: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_808000E8;
    }
    goto skip_0;
    // 0x80800048: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_0:
    // 0x8080004C: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80800050: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800054: add.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x80800058: sub.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8080005C: c.lt.s      $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f14.fl < ctx->f20.fl;
    // 0x80800060: nop

    // 0x80800064: bc1fl       L_80800078
    if (!c1cs) {
        // 0x80800068: lwc1        $f16, 0x8($s1)
        ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
            goto L_80800078;
    }
    goto skip_1;
    // 0x80800068: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    skip_1:
    // 0x8080006C: add.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x80800070: sub.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f10.fl;
    // 0x80800074: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
L_80800078:
    // 0x80800078: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080007C: add.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x80800080: sub.s       $f22, $f18, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80800084: c.lt.s      $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f14.fl < ctx->f22.fl;
    // 0x80800088: nop

    // 0x8080008C: bc1f        L_8080009C
    if (!c1cs) {
        // 0x80800090: nop
    
            goto L_8080009C;
    }
    // 0x80800090: nop

    // 0x80800094: add.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x80800098: sub.s       $f22, $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f6.fl;
L_8080009C:
    // 0x8080009C: jal         0x800F2100
    // 0x808000A0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x808000A0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x808000A4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x808000A8: jal         0x800F2100
    // 0x808000AC: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    mlAbsF(rdram, ctx);
        goto after_2;
    // 0x808000AC: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_2:
    // 0x808000B0: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808000B4: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x808000B8: nop

    // 0x808000BC: bc1fl       L_808000D8
    if (!c1cs) {
        // 0x808000C0: lwc1        $f18, 0x8($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
            goto L_808000D8;
    }
    goto skip_2;
    // 0x808000C0: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    skip_2:
    // 0x808000C4: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x808000C8: add.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x808000CC: b           L_80800164
    // 0x808000D0: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
        goto L_80800164;
    // 0x808000D0: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x808000D4: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
L_808000D8:
    // 0x808000D8: add.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f22.fl;
    // 0x808000DC: b           L_80800164
    // 0x808000E0: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
        goto L_80800164;
    // 0x808000E0: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x808000E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_808000E8:
    // 0x808000E8: jal         0x8002DCA0
    // 0x808000EC: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x808000EC: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x808000F0: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x808000F4: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x808000F8: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x808000FC: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800100: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80800104: add.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x80800108: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8080010C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80800110: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    // 0x80800114: div.s       $f20, $f6, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800118: jal         0x800F2100
    // 0x8080011C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    mlAbsF(rdram, ctx);
        goto after_4;
    // 0x8080011C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80800120: lwc1        $f22, 0x38($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800124: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80800128: jal         0x800F2100
    // 0x8080012C: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    mlAbsF(rdram, ctx);
        goto after_5;
    // 0x8080012C: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_5:
    // 0x80800130: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800134: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800138: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8080013C: mul.s       $f8, $f12, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80800140: add.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80800144: mul.s       $f10, $f22, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x80800148: div.s       $f12, $f8, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8080014C: div.s       $f22, $f10, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80800150: add.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x80800154: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x80800158: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8080015C: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x80800160: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
L_80800164:
    // 0x80800164: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80800168: jal         0x800EECE0
    // 0x8080016C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EECE0(rdram, ctx);
        goto after_6;
    // 0x8080016C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80800170: beq         $v0, $zero, L_80800180
    if (ctx->r2 == 0) {
        // 0x80800174: ldc1        $f20, 0x10($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
            goto L_80800180;
    }
    // 0x80800174: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800178: b           L_80800184
    // 0x8080017C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800184;
    // 0x8080017C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800180:
    // 0x80800180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800184:
    // 0x80800184: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800188: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8080018C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80800190: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800194: jr          $ra
    // 0x80800198: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80800198: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void _subaddieaudioloop_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089D50: syscall     810
    recomp_syscall_handler(rdram, ctx, 0x80089D50);
    return;
    // 0x80089D54: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void sucoasterflydata_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080018C: sltiu       $at, $a0, 0x5
    ctx->r1 = ctx->r4 < 0X5 ? 1 : 0;
    // 0x80800190: beq         $at, $zero, L_808001D8
    if (ctx->r1 == 0) {
        // 0x80800194: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808001D8;
    }
    // 0x80800194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800198: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080019C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3286, 0X268) << 16);
    // 0x808001A0: addu        $at, $at, $t6
    gpr jr_addend_808001A8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808001A4: lw          $t6, 0x268($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3286, 0X268));
    // 0x808001A8: jr          $t6
    // 0x808001AC: nop

    switch (jr_addend_808001A8 >> 2) {
        case 0: goto L_808001B0; break;
        case 1: goto L_808001B8; break;
        case 2: goto L_808001C0; break;
        case 3: goto L_808001C8; break;
        case 4: goto L_808001D0; break;
        default: switch_error(__func__, 0x808001A8, 0x80800268);
    }
    // 0x808001AC: nop

L_808001B0:
    // 0x808001B0: jr          $ra
    // 0x808001B4: addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
    return;
    // 0x808001B4: addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
L_808001B8:
    // 0x808001B8: jr          $ra
    // 0x808001BC: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
    return;
    // 0x808001BC: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
L_808001C0:
    // 0x808001C0: jr          $ra
    // 0x808001C4: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
    return;
    // 0x808001C4: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
L_808001C8:
    // 0x808001C8: jr          $ra
    // 0x808001CC: addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
    return;
    // 0x808001CC: addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
L_808001D0:
    // 0x808001D0: jr          $ra
    // 0x808001D4: addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
    return;
    // 0x808001D4: addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
L_808001D8:
    // 0x808001D8: jr          $ra
    // 0x808001DC: nop

    return;
    // 0x808001DC: nop

;}
RECOMP_FUNC void func_808007E0_chfactorysparkroom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808007E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808007E8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808007EC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808007F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808007F4: jal         0x80100094
    // 0x808007F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808007FC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800800: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800804: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_80800808:
    // 0x80800808: jal         0x800C8B84
    // 0x8080080C: lw          $a0, 0x200($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X200);
    func_800C8B84(rdram, ctx);
        goto after_1;
    // 0x8080080C: lw          $a0, 0x200($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X200);
    after_1:
    // 0x80800810: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800814: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800818: bne         $s1, $s2, L_80800808
    if (ctx->r17 != ctx->r18) {
        // 0x8080081C: sw          $zero, 0x1FC($s0)
        MEM_W(0X1FC, ctx->r16) = 0;
            goto L_80800808;
    }
    // 0x8080081C: sw          $zero, 0x1FC($s0)
    MEM_W(0X1FC, ctx->r16) = 0;
    // 0x80800820: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800824: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800828: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080082C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800830: jr          $ra
    // 0x80800834: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800834: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _suquiz_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A800: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A800);
    return;
    // 0x8008A804: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void subaddieaudioloop_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808000D0: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x808000D4: lw          $t7, 0x70($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X70);
    // 0x808000D8: lbu         $a0, 0x5F($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X5F);
    // 0x808000DC: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x808000E0: jal         0x80800248
    // 0x808000E4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x808000E4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_0:
    // 0x808000E8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x808000EC: sb          $v0, 0x5F($v1)
    MEM_B(0X5F, ctx->r3) = ctx->r2;
    // 0x808000F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000F4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x808000F8: sltu        $t9, $zero, $v0
    ctx->r25 = 0 < ctx->r2 ? 1 : 0;
    // 0x808000FC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80800100: jr          $ra
    // 0x80800104: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800104: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void guOrthoF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DCB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002DCB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002DCB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002DCBC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002DCC0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8002DCC4: jal         0x8002EEB4
    // 0x8002DCC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x8002DCC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002DCCC: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8002DCD0: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002DCD4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002DCD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002DCDC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8002DCE0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8002DCE4: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8002DCE8: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8002DCEC: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8002DCF0: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002DCF4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002DCF8: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8002DCFC: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8002DD00: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002DD04: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8002DD08: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8002DD0C: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002DD10: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002DD14: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002DD18: sub.s       $f2, $f14, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x8002DD1C: div.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8002DD20: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8002DD24: swc1        $f4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f4.u32l;
    // 0x8002DD28: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x8002DD2C: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002DD30: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8002DD34: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8002DD38: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8002DD3C: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8002DD40: swc1        $f6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f6.u32l;
    // 0x8002DD44: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002DD48: add.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x8002DD4C: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8002DD50: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8002DD54: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8002DD58: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8002DD5C: div.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8002DD60: swc1        $f6, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f6.u32l;
    // 0x8002DD64: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002DD68: nop

    // 0x8002DD6C: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    // 0x8002DD70: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    // 0x8002DD74: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8002DD78: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002DD7C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002DD80: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8002DD84: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8002DD88: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002DD8C: beq         $v1, $a0, L_8002DDD0
    if (ctx->r3 == ctx->r4) {
        // 0x8002DD90: lwc1        $f16, 0xC($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
            goto L_8002DDD0;
    }
    // 0x8002DD90: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
L_8002DD94:
    // 0x8002DD94: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8002DD98: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8002DD9C: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002DDA0: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8002DDA4: lwc1        $f14, 0x18($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8002DDA8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002DDAC: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8002DDB0: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8002DDB4: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x8002DDB8: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8002DDBC: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x8002DDC0: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x8002DDC4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002DDC8: bne         $v1, $a0, L_8002DD94
    if (ctx->r3 != ctx->r4) {
        // 0x8002DDCC: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_8002DD94;
    }
    // 0x8002DDCC: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
L_8002DDD0:
    // 0x8002DDD0: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8002DDD4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002DDD8: swc1        $f12, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f12.u32l;
    // 0x8002DDDC: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8002DDE0: nop

    // 0x8002DDE4: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8002DDE8: swc1        $f10, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8002DDEC: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
    // 0x8002DDF0: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8002DDF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002DDF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002DDFC: jr          $ra
    // 0x8002DE00: nop

    return;
    // 0x8002DE00: nop

;}
RECOMP_FUNC void func_80800000_chstoneballcoach(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800008: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x8080000C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: beq         $a1, $at, L_80800058
    if (ctx->r5 == ctx->r1) {
        // 0x80800018: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80800058;
    }
    // 0x80800018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080001C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800020: beq         $a1, $at, L_80800044
    if (ctx->r5 == ctx->r1) {
        // 0x80800024: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_80800044;
    }
    // 0x80800024: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800028: bne         $a1, $at, L_80800074
    if (ctx->r5 != ctx->r1) {
        // 0x8080002C: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1616, 0X3B8) << 16);
            goto L_80800074;
    }
    // 0x8080002C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1616, 0X3B8) << 16);
    // 0x80800030: addiu       $a0, $a0, 0x3B8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1616, 0X3B8));
    // 0x80800034: jal         0x80088090
    // 0x80800038: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800038: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_0:
    // 0x8080003C: b           L_80800080
    // 0x80800040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800080;
    // 0x80800040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800044:
    // 0x80800044: lbu         $t6, 0x72($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X72);
    // 0x80800048: andi        $t7, $t6, 0xFF03
    ctx->r15 = ctx->r14 & 0XFF03;
    // 0x8080004C: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x80800050: b           L_8080007C
    // 0x80800054: sb          $t8, 0x72($a2)
    MEM_B(0X72, ctx->r6) = ctx->r24;
        goto L_8080007C;
    // 0x80800054: sb          $t8, 0x72($a2)
    MEM_B(0X72, ctx->r6) = ctx->r24;
L_80800058:
    // 0x80800058: jal         0x801015D0
    // 0x8080005C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_801015D0(rdram, ctx);
        goto after_1;
    // 0x8080005C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x80800060: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800064: jal         0x800DF744
    // 0x80800068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x80800068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8080006C: b           L_80800080
    // 0x80800070: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800080;
    // 0x80800070: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800074:
    // 0x80800074: b           L_80800080
    // 0x80800078: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800080;
    // 0x80800078: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080007C:
    // 0x8080007C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800080:
    // 0x80800080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void func_80802B24_gcnewoption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802B24: beql        $a1, $zero, L_80802B40
    if (ctx->r5 == 0) {
        // 0x80802B28: lbu         $t9, 0x1C($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X1C);
            goto L_80802B40;
    }
    goto skip_0;
    // 0x80802B28: lbu         $t9, 0x1C($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1C);
    skip_0:
    // 0x80802B2C: lbu         $t7, 0x1C($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1C);
    // 0x80802B30: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x80802B34: jr          $ra
    // 0x80802B38: sb          $t8, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r24;
    return;
    // 0x80802B38: sb          $t8, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r24;
    // 0x80802B3C: lbu         $t9, 0x1C($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1C);
L_80802B40:
    // 0x80802B40: andi        $t0, $t9, 0xFFF7
    ctx->r8 = ctx->r25 & 0XFFF7;
    // 0x80802B44: sb          $t0, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r8;
    // 0x80802B48: jr          $ra
    // 0x80802B4C: nop

    return;
    // 0x80802B4C: nop

;}
RECOMP_FUNC void func_8010A730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A730: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8010A734: jr          $ra
    // 0x8010A738: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8010A738: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_8080028C_chbadshad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080028C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800290: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800294: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800298: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080029C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x808002A0: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x808002A4: lw          $t7, 0x78($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X78);
    // 0x808002A8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808002AC: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x808002B0: sll         $t9, $t7, 28
    ctx->r25 = S32(ctx->r15 << 28);
    // 0x808002B4: bltz        $t9, L_80800338
    if (SIGNED(ctx->r25) < 0) {
        // 0x808002B8: lw          $t2, 0x40($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X40);
            goto L_80800338;
    }
    // 0x808002B8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x808002BC: lw          $t0, 0x1C($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X1C);
    // 0x808002C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808002C4: ori         $at, $at, 0x8000
    ctx->r1 = ctx->r1 | 0X8000;
    // 0x808002C8: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x808002CC: bnel        $t1, $zero, L_8080033C
    if (ctx->r9 != 0) {
        // 0x808002D0: lw          $t3, 0x70($t2)
        ctx->r11 = MEM_W(ctx->r10, 0X70);
            goto L_8080033C;
    }
    goto skip_0;
    // 0x808002D0: lw          $t3, 0x70($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X70);
    skip_0:
    // 0x808002D4: lh          $t3, 0x7E($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X7E);
    // 0x808002D8: bgezl       $t3, L_8080033C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x808002DC: lw          $t3, 0x70($t2)
        ctx->r11 = MEM_W(ctx->r10, 0X70);
            goto L_8080033C;
    }
    goto skip_1;
    // 0x808002DC: lw          $t3, 0x70($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X70);
    skip_1:
    // 0x808002E0: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x808002E4: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x808002E8: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808002EC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x808002F0: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x808002F4: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x808002F8: nop

    // 0x808002FC: bnel        $t5, $t7, L_8080033C
    if (ctx->r13 != ctx->r15) {
        // 0x80800300: lw          $t3, 0x70($t2)
        ctx->r11 = MEM_W(ctx->r10, 0X70);
            goto L_8080033C;
    }
    goto skip_2;
    // 0x80800300: lw          $t3, 0x70($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X70);
    skip_2:
    // 0x80800304: lwc1        $f16, 0xC($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80800308: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8080030C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800310: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800314: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80800318: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x8080031C: nop

    // 0x80800320: bnel        $t9, $t1, L_8080033C
    if (ctx->r25 != ctx->r9) {
        // 0x80800324: lw          $t3, 0x70($t2)
        ctx->r11 = MEM_W(ctx->r10, 0X70);
            goto L_8080033C;
    }
    goto skip_3;
    // 0x80800324: lw          $t3, 0x70($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X70);
    skip_3:
    // 0x80800328: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x8080032C: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80800330: b           L_8080044C
    // 0x80800334: swc1        $f8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f8.u32l;
        goto L_8080044C;
    // 0x80800334: swc1        $f8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f8.u32l;
L_80800338:
    // 0x80800338: lw          $t3, 0x70($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X70);
L_8080033C:
    // 0x8080033C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800340: sll         $t6, $t3, 12
    ctx->r14 = S32(ctx->r11 << 12);
    // 0x80800344: bgezl       $t6, L_80800364
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800348: lw          $t5, 0x40($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X40);
            goto L_80800364;
    }
    goto skip_4;
    // 0x80800348: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    skip_4:
    // 0x8080034C: jal         0x800EE7F8
    // 0x80800350: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800350: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x80800354: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800358: b           L_80800454
    // 0x8080035C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800454;
    // 0x8080035C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800360: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
L_80800364:
    // 0x80800364: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    // 0x80800368: lh          $t7, 0x8E($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X8E);
    // 0x8080036C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x80800370: beql        $t7, $zero, L_808003F8
    if (ctx->r15 == 0) {
        // 0x80800374: lw          $a3, 0x48($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X48);
            goto L_808003F8;
    }
    goto skip_5;
    // 0x80800374: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    skip_5:
    // 0x80800378: jal         0x80105494
    // 0x8080037C: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    func_80105494(rdram, ctx);
        goto after_1;
    // 0x8080037C: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800380: bne         $v0, $zero, L_808003F4
    if (ctx->r2 != 0) {
        // 0x80800384: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_808003F4;
    }
    // 0x80800384: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800388: addiu       $t8, $sp, 0x30
    ctx->r24 = ADD32(ctx->r29, 0X30);
    // 0x8080038C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800390: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80800394: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80800398: jal         0x80104668
    // 0x8080039C: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    func_80104668(rdram, ctx);
        goto after_2;
    // 0x8080039C: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x808003A0: beql        $v0, $zero, L_808003F8
    if (ctx->r2 == 0) {
        // 0x808003A4: lw          $a3, 0x48($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X48);
            goto L_808003F8;
    }
    goto skip_6;
    // 0x808003A4: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    skip_6:
    // 0x808003A8: jal         0x8010518C
    // 0x808003AC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_8010518C(rdram, ctx);
        goto after_3;
    // 0x808003AC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_3:
    // 0x808003B0: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B8: jal         0x8010279C
    // 0x808003BC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_8010279C(rdram, ctx);
        goto after_4;
    // 0x808003BC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x808003C0: lw          $t0, 0x1C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1C);
    // 0x808003C4: sll         $t9, $t0, 0
    ctx->r25 = S32(ctx->r8 << 0);
    // 0x808003C8: bgezl       $t9, L_808003E4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808003CC: lbu         $t4, 0x65($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0X65);
            goto L_808003E4;
    }
    goto skip_7;
    // 0x808003CC: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    skip_7:
    // 0x808003D0: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x808003D4: andi        $t2, $t1, 0xFFFE
    ctx->r10 = ctx->r9 & 0XFFFE;
    // 0x808003D8: b           L_808003EC
    // 0x808003DC: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
        goto L_808003EC;
    // 0x808003DC: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    // 0x808003E0: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
L_808003E4:
    // 0x808003E4: ori         $t6, $t4, 0x1
    ctx->r14 = ctx->r12 | 0X1;
    // 0x808003E8: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
L_808003EC:
    // 0x808003EC: b           L_80800450
    // 0x808003F0: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
        goto L_80800450;
    // 0x808003F0: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
L_808003F4:
    // 0x808003F4: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
L_808003F8:
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003FC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800400: jal         0x8080086C
    // 0x80800404: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_8080086C_chbadshad(rdram, ctx);
        goto after_5;
    // 0x80800404: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_5:
    // 0x80800408: bnel        $v0, $zero, L_80800424
    if (ctx->r2 != 0) {
        // 0x8080040C: lw          $t8, 0x1C($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X1C);
            goto L_80800424;
    }
    goto skip_8;
    // 0x8080040C: lw          $t8, 0x1C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1C);
    skip_8:
    // 0x80800410: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80800414: andi        $t5, $t7, 0xFFFE
    ctx->r13 = ctx->r15 & 0XFFFE;
    // 0x80800418: b           L_8080044C
    // 0x8080041C: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
        goto L_8080044C;
    // 0x8080041C: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    // 0x80800420: lw          $t8, 0x1C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1C);
L_80800424:
    // 0x80800424: sll         $t0, $t8, 0
    ctx->r8 = S32(ctx->r24 << 0);
    // 0x80800428: bgezl       $t0, L_80800444
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8080042C: lbu         $t3, 0x65($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X65);
            goto L_80800444;
    }
    goto skip_9;
    // 0x8080042C: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    skip_9:
    // 0x80800430: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80800434: andi        $t1, $t9, 0xFFFE
    ctx->r9 = ctx->r25 & 0XFFFE;
    // 0x80800438: b           L_8080044C
    // 0x8080043C: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
        goto L_8080044C;
    // 0x8080043C: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80800440: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
L_80800444:
    // 0x80800444: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80800448: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
L_8080044C:
    // 0x8080044C: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
L_80800450:
    // 0x80800450: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800454:
    // 0x80800454: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800458: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080045C: jr          $ra
    // 0x80800460: nop

    return;
    // 0x80800460: nop

;}
RECOMP_FUNC void func_800BEB98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEB98: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BEB9C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800BEBA0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BEBA4: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800BEBA8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BEBAC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BEBB0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800BEBB4: lw          $t7, -0x7A3C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7A3C);
    // 0x800BEBB8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800BEBBC: beq         $t7, $zero, L_800BEBCC
    if (ctx->r15 == 0) {
        // 0x800BEBC0: nop
    
            goto L_800BEBCC;
    }
    // 0x800BEBC0: nop

    // 0x800BEBC4: jr          $ra
    // 0x800BEBC8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x800BEBC8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800BEBCC:
    // 0x800BEBCC: jr          $ra
    // 0x800BEBD0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800BEBD0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8080000C_chcastleshockpadswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800010: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800018: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800020: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800024: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x80800028: addiu       $a1, $zero, 0x4E8
    ctx->r5 = ADD32(0, 0X4E8);
    // 0x8080002C: jal         0x8008A0C8
    // 0x80800030: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800030: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_0:
    // 0x80800034: bne         $v0, $zero, L_8080004C
    if (ctx->r2 != 0) {
        // 0x80800038: addiu       $a0, $s0, 0x18
        ctx->r4 = ADD32(ctx->r16, 0X18);
            goto L_8080004C;
    }
    // 0x80800038: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8080003C: jal         0x800FFAB0
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800044: b           L_80800084
    // 0x80800048: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800084;
    // 0x80800048: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080004C:
    // 0x8080004C: jal         0x800EE7F8
    // 0x80800050: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800050: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80800054: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080005C: addiu       $a1, $zero, 0xA2
    ctx->r5 = ADD32(0, 0XA2);
    // 0x80800060: jal         0x80085808
    // 0x80800064: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x80800064: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x80800068: beq         $v0, $zero, L_80800078
    if (ctx->r2 == 0) {
        // 0x8080006C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800078;
    }
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800070: jal         0x80108B04
    // 0x80800074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_4;
    // 0x80800074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_80800078:
    // 0x80800078: jal         0x80085818
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800080: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800084:
    // 0x80800084: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800088: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080008C: jr          $ra
    // 0x80800090: nop

    return;
    // 0x80800090: nop

;}
RECOMP_FUNC void suquiz_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080074C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800750: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800754: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800758: jal         0x800DA298
    // 0x8080075C: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080075C: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    after_0:
    // 0x80800760: beql        $v0, $zero, L_80800780
    if (ctx->r2 == 0) {
        // 0x80800764: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800780;
    }
    goto skip_0;
    // 0x80800764: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800768: jal         0x8080070C
    // 0x8080076C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    suquiz_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x8080076C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800770: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80800774: b           L_80800780
    // 0x80800778: sltu        $v0, $zero, $t6
    ctx->r2 = 0 < ctx->r14 ? 1 : 0;
        goto L_80800780;
    // 0x80800778: sltu        $v0, $zero, $t6
    ctx->r2 = 0 < ctx->r14 ? 1 : 0;
    // 0x8080077C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800780:
    // 0x80800780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800784: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800788: jr          $ra
    // 0x8080078C: nop

    return;
    // 0x8080078C: nop

;}
RECOMP_FUNC void gcfrontend_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F0: jal         0x8080006C
    // 0x808000F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    gcfrontend_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808000F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x808000F8: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x808000FC: bne         $t6, $zero, L_80800128
    if (ctx->r14 != 0) {
        // 0x80800100: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800128;
    }
    // 0x80800100: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800104: jal         0x8080006C
    // 0x80800108: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcfrontend_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800108: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8080010C: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800110: bne         $t7, $zero, L_80800128
    if (ctx->r15 != 0) {
        // 0x80800114: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80800128;
    }
    // 0x80800114: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80800118: jal         0x8080006C
    // 0x8080011C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    gcfrontend_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x8080011C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x80800120: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800124: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80800128:
    // 0x80800128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080012C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800130: jr          $ra
    // 0x80800134: nop

    return;
    // 0x80800134: nop

;}
