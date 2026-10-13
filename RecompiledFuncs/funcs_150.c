#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80801DE0_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801DE0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801DE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801DE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801DEC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801DF0: jal         0x80100094
    // 0x80801DF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801DF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801DF8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80801DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E00: jal         0x80109FE8
    // 0x80801E04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_1;
    // 0x80801E04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801E08: jal         0x80807B18
    // 0x80801E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807B18_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80801E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801E10: jal         0x80806648
    // 0x80801E14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80806648_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80801E14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801E18: jal         0x808059A4
    // 0x80801E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808059A4_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x80801E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801E20: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80801E24: lh          $t7, 0xA0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XA0);
    // 0x80801E28: bne         $t7, $zero, L_80801F8C
    if (ctx->r15 != 0) {
        // 0x80801E2C: nop
    
            goto L_80801F8C;
    }
    // 0x80801E2C: nop

    // 0x80801E30: jal         0x800EA05C
    // 0x80801E34: nop

    func_800EA05C(rdram, ctx);
        goto after_5;
    // 0x80801E34: nop

    after_5:
    // 0x80801E38: addiu       $at, $zero, 0x15D
    ctx->r1 = ADD32(0, 0X15D);
    // 0x80801E3C: beq         $v0, $at, L_80801E54
    if (ctx->r2 == ctx->r1) {
        // 0x80801E40: addiu       $at, $zero, 0x19A
        ctx->r1 = ADD32(0, 0X19A);
            goto L_80801E54;
    }
    // 0x80801E40: addiu       $at, $zero, 0x19A
    ctx->r1 = ADD32(0, 0X19A);
    // 0x80801E44: beq         $v0, $at, L_80801EE0
    if (ctx->r2 == ctx->r1) {
        // 0x80801E48: nop
    
            goto L_80801EE0;
    }
    // 0x80801E48: nop

    // 0x80801E4C: b           L_80802148
    // 0x80801E50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802148;
    // 0x80801E50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801E54:
    // 0x80801E54: jal         0x800DA298
    // 0x80801E58: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80801E58: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    after_6:
    // 0x80801E5C: bne         $v0, $zero, L_80801EC0
    if (ctx->r2 != 0) {
        // 0x80801E60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801EC0;
    }
    // 0x80801E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E64: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80801E68: jal         0x8080290C
    // 0x80801E6C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_8080290C_chdiggerboss(rdram, ctx);
        goto after_7;
    // 0x80801E6C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_7:
    // 0x80801E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E74: addiu       $a1, $zero, 0x171C
    ctx->r5 = ADD32(0, 0X171C);
    // 0x80801E78: jal         0x80803660
    // 0x80801E7C: addiu       $a2, $zero, 0x144
    ctx->r6 = ADD32(0, 0X144);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_8;
    // 0x80801E7C: addiu       $a2, $zero, 0x144
    ctx->r6 = ADD32(0, 0X144);
    after_8:
    // 0x80801E80: jal         0x800F54E4
    // 0x80801E84: nop

    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x80801E84: nop

    after_9:
    // 0x80801E88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801E8C: jal         0x800F82D4
    // 0x80801E90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F82D4(rdram, ctx);
        goto after_10;
    // 0x80801E90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80801E94: jal         0x800F54E4
    // 0x80801E98: nop

    func_800F54E4(rdram, ctx);
        goto after_11;
    // 0x80801E98: nop

    after_11:
    // 0x80801E9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801EA0: jal         0x800F8444
    // 0x80801EA4: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    func_800F8444(rdram, ctx);
        goto after_12;
    // 0x80801EA4: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    after_12:
    // 0x80801EA8: addiu       $a0, $zero, 0x4F1
    ctx->r4 = ADD32(0, 0X4F1);
    // 0x80801EAC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80801EB0: jal         0x80101180
    // 0x80801EB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_13;
    // 0x80801EB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x80801EB8: b           L_80802148
    // 0x80801EBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802148;
    // 0x80801EBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801EC0:
    // 0x80801EC0: jal         0x800FFAB0
    // 0x80801EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_14;
    // 0x80801EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80801EC8: jal         0x80802228
    // 0x80801ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_15;
    // 0x80801ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80801ED0: jal         0x800FFAB0
    // 0x80801ED4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_16;
    // 0x80801ED4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_16:
    // 0x80801ED8: b           L_80802148
    // 0x80801EDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802148;
    // 0x80801EDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801EE0:
    // 0x80801EE0: jal         0x800DA298
    // 0x80801EE4: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    func_800DA298(rdram, ctx);
        goto after_17;
    // 0x80801EE4: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    after_17:
    // 0x80801EE8: bne         $v0, $zero, L_80801F54
    if (ctx->r2 != 0) {
        // 0x80801EEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801F54;
    }
    // 0x80801EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801EF0: jal         0x800F54E4
    // 0x80801EF4: nop

    func_800F54E4(rdram, ctx);
        goto after_18;
    // 0x80801EF4: nop

    after_18:
    // 0x80801EF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801EFC: jal         0x800F82D4
    // 0x80801F00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F82D4(rdram, ctx);
        goto after_19;
    // 0x80801F00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80801F04: jal         0x800F54E4
    // 0x80801F08: nop

    func_800F54E4(rdram, ctx);
        goto after_20;
    // 0x80801F08: nop

    after_20:
    // 0x80801F0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801F10: jal         0x800F8444
    // 0x80801F14: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    func_800F8444(rdram, ctx);
        goto after_21;
    // 0x80801F14: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    after_21:
    // 0x80801F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F1C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80801F20: jal         0x8080290C
    // 0x80801F24: addiu       $a2, $zero, 0x2020
    ctx->r6 = ADD32(0, 0X2020);
    func_8080290C_chdiggerboss(rdram, ctx);
        goto after_22;
    // 0x80801F24: addiu       $a2, $zero, 0x2020
    ctx->r6 = ADD32(0, 0X2020);
    after_22:
    // 0x80801F28: addiu       $a0, $zero, 0x18B9
    ctx->r4 = ADD32(0, 0X18B9);
    // 0x80801F2C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80801F30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801F34: jal         0x800861A0
    // 0x80801F38: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _chintrotext_entrypoint_1(rdram, ctx);
        goto after_23;
    // 0x80801F38: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_23:
    // 0x80801F3C: jal         0x800FDC28
    // 0x80801F40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FDC28(rdram, ctx);
        goto after_24;
    // 0x80801F40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_24:
    // 0x80801F44: jal         0x800C964C
    // 0x80801F48: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_800C964C(rdram, ctx);
        goto after_25;
    // 0x80801F48: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_25:
    // 0x80801F4C: b           L_80802148
    // 0x80801F50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802148;
    // 0x80801F50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801F54:
    // 0x80801F54: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801F58: jal         0x80802878
    // 0x80801F5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_26;
    // 0x80801F5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_26:
    // 0x80801F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F64: jal         0x80800180
    // 0x80801F68: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800180_chdiggerboss(rdram, ctx);
        goto after_27;
    // 0x80801F68: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_27:
    // 0x80801F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F70: addiu       $a1, $zero, 0x171F
    ctx->r5 = ADD32(0, 0X171F);
    // 0x80801F74: jal         0x80803660
    // 0x80801F78: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_28;
    // 0x80801F78: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    after_28:
    // 0x80801F7C: jal         0x800FDC28
    // 0x80801F80: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FDC28(rdram, ctx);
        goto after_29;
    // 0x80801F80: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_29:
    // 0x80801F84: b           L_80802148
    // 0x80801F88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802148;
    // 0x80801F88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801F8C:
    // 0x80801F8C: jal         0x80802228
    // 0x80801F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_30;
    // 0x80801F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80801F94: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80801F98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801F9C: jal         0x80100094
    // 0x80801FA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_31;
    // 0x80801FA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_31:
    // 0x80801FA4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80801FA8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80801FAC: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x80801FB0: lh          $v1, 0x0($t8)
    ctx->r3 = MEM_H(ctx->r24, 0X0);
    // 0x80801FB4: beq         $v1, $at, L_80801FCC
    if (ctx->r3 == ctx->r1) {
        // 0x80801FB8: addiu       $at, $zero, 0x37
        ctx->r1 = ADD32(0, 0X37);
            goto L_80801FCC;
    }
    // 0x80801FB8: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
    // 0x80801FBC: beq         $v1, $at, L_8080207C
    if (ctx->r3 == ctx->r1) {
        // 0x80801FC0: nop
    
            goto L_8080207C;
    }
    // 0x80801FC0: nop

    // 0x80801FC4: b           L_80802128
    // 0x80801FC8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
        goto L_80802128;
    // 0x80801FC8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
L_80801FCC:
    // 0x80801FCC: jal         0x80802314
    // 0x80801FD0: nop

    func_80802314_chdiggerboss(rdram, ctx);
        goto after_32;
    // 0x80801FD0: nop

    after_32:
    // 0x80801FD4: slti        $t9, $v0, 0x2
    ctx->r25 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80801FD8: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80801FDC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801FE0: jal         0x80804A50
    // 0x80801FE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80804A50_chdiggerboss(rdram, ctx);
        goto after_33;
    // 0x80801FE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_33:
    // 0x80801FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801FEC: jal         0x80807698
    // 0x80801FF0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80807698_chdiggerboss(rdram, ctx);
        goto after_34;
    // 0x80801FF0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_34:
    // 0x80801FF4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80801FF8: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x80801FFC: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80802000: beq         $t0, $zero, L_8080206C
    if (ctx->r8 == 0) {
        // 0x80802004: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8080206C;
    }
    // 0x80802004: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802008: sb          $t1, 0x2($t2)
    MEM_B(0X2, ctx->r10) = ctx->r9;
    // 0x8080200C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802010: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x80802014: jal         0x80803BE8
    // 0x80802018: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_35;
    // 0x80802018: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_35:
    // 0x8080201C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802020: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80802024: jal         0x80802878
    // 0x80802028: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_36;
    // 0x80802028: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_36:
    // 0x8080202C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802030: jal         0x808041E4
    // 0x80802034: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808041E4_chdiggerboss(rdram, ctx);
        goto after_37;
    // 0x80802034: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_37:
    // 0x80802038: jal         0x800F54E4
    // 0x8080203C: nop

    func_800F54E4(rdram, ctx);
        goto after_38;
    // 0x8080203C: nop

    after_38:
    // 0x80802040: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802044: jal         0x800F82D4
    // 0x80802048: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_39;
    // 0x80802048: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_39:
    // 0x8080204C: jal         0x800F54E4
    // 0x80802050: nop

    func_800F54E4(rdram, ctx);
        goto after_40;
    // 0x80802050: nop

    after_40:
    // 0x80802054: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802058: addiu       $a1, $zero, 0x8A
    ctx->r5 = ADD32(0, 0X8A);
    // 0x8080205C: jal         0x800F7C58
    // 0x80802060: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800F7C58(rdram, ctx);
        goto after_41;
    // 0x80802060: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_41:
    // 0x80802064: b           L_80802128
    // 0x80802068: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
        goto L_80802128;
    // 0x80802068: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
L_8080206C:
    // 0x8080206C: jal         0x808041E4
    // 0x80802070: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808041E4_chdiggerboss(rdram, ctx);
        goto after_42;
    // 0x80802070: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_42:
    // 0x80802074: b           L_80802128
    // 0x80802078: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
        goto L_80802128;
    // 0x80802078: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
L_8080207C:
    // 0x8080207C: jal         0x80802314
    // 0x80802080: nop

    func_80802314_chdiggerboss(rdram, ctx);
        goto after_43;
    // 0x80802080: nop

    after_43:
    // 0x80802084: sltiu       $t3, $v0, 0x1
    ctx->r11 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80802088: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8080208C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802090: jal         0x808041E4
    // 0x80802094: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808041E4_chdiggerboss(rdram, ctx);
        goto after_44;
    // 0x80802094: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_44:
    // 0x80802098: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080209C: jal         0x80804A50
    // 0x808020A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80804A50_chdiggerboss(rdram, ctx);
        goto after_45;
    // 0x808020A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_45:
    // 0x808020A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808020A8: jal         0x80807698
    // 0x808020AC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80807698_chdiggerboss(rdram, ctx);
        goto after_46;
    // 0x808020AC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_46:
    // 0x808020B0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x808020B4: addiu       $t5, $zero, 0x28
    ctx->r13 = ADD32(0, 0X28);
    // 0x808020B8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x808020BC: beq         $t4, $zero, L_8080211C
    if (ctx->r12 == 0) {
        // 0x808020C0: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8080211C;
    }
    // 0x808020C0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808020C4: sb          $t5, 0x2($t6)
    MEM_B(0X2, ctx->r14) = ctx->r13;
    // 0x808020C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808020CC: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x808020D0: jal         0x80803BE8
    // 0x808020D4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_47;
    // 0x808020D4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_47:
    // 0x808020D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808020DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808020E0: jal         0x80802878
    // 0x808020E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_48;
    // 0x808020E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_48:
    // 0x808020E8: jal         0x800F54E4
    // 0x808020EC: nop

    func_800F54E4(rdram, ctx);
        goto after_49;
    // 0x808020EC: nop

    after_49:
    // 0x808020F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808020F4: jal         0x800F82D4
    // 0x808020F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_50;
    // 0x808020F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_50:
    // 0x808020FC: jal         0x800F54E4
    // 0x80802100: nop

    func_800F54E4(rdram, ctx);
        goto after_51;
    // 0x80802100: nop

    after_51:
    // 0x80802104: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802108: addiu       $a1, $zero, 0x8A
    ctx->r5 = ADD32(0, 0X8A);
    // 0x8080210C: jal         0x800F7C58
    // 0x80802110: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800F7C58(rdram, ctx);
        goto after_52;
    // 0x80802110: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_52:
    // 0x80802114: b           L_80802128
    // 0x80802118: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
        goto L_80802128;
    // 0x80802118: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
L_8080211C:
    // 0x8080211C: jal         0x808041E4
    // 0x80802120: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808041E4_chdiggerboss(rdram, ctx);
        goto after_53;
    // 0x80802120: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_53:
    // 0x80802124: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
L_80802128:
    // 0x80802128: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8080212C: sh          $zero, 0xA0($t7)
    MEM_H(0XA0, ctx->r15) = 0;
    // 0x80802130: lbu         $t8, 0x75($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X75);
    // 0x80802134: andi        $t9, $t8, 0xFFFD
    ctx->r25 = ctx->r24 & 0XFFFD;
    // 0x80802138: sb          $t9, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r25;
    // 0x8080213C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80802140: sb          $t0, 0x6($t1)
    MEM_B(0X6, ctx->r9) = ctx->r8;
    // 0x80802144: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802148:
    // 0x80802148: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080214C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80802150: jr          $ra
    // 0x80802154: nop

    return;
    // 0x80802154: nop

;}
RECOMP_FUNC void _bsbansack_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800826C0: syscall     7
    recomp_syscall_handler(rdram, ctx, 0x800826C0);
    return;
    // 0x800826C4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800EF49C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF49C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EF4A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EF4A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800EF4A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800EF4AC: jal         0x800136E4
    // 0x800EF4B0: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    func_800136E4(rdram, ctx);
        goto after_0;
    // 0x800EF4B0: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x800EF4B4: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x800EF4B8: jal         0x800136E4
    // 0x800EF4BC: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x800EF4BC: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    after_1:
    // 0x800EF4C0: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x800EF4C4: jal         0x800136E4
    // 0x800EF4C8: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    func_800136E4(rdram, ctx);
        goto after_2;
    // 0x800EF4C8: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    after_2:
    // 0x800EF4CC: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x800EF4D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800EF4D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EF4D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800EF4DC: jr          $ra
    // 0x800EF4E0: nop

    return;
    // 0x800EF4E0: nop

;}
RECOMP_FUNC void func_8080219C_chpotogoldgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080219C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808021A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808021A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808021A8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x808021AC: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x808021B0: lw          $v0, 0x34($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X34);
    // 0x808021B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808021B8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x808021BC: beq         $v0, $zero, L_808021D8
    if (ctx->r2 == 0) {
        // 0x808021C0: addiu       $a1, $zero, 0x29
        ctx->r5 = ADD32(0, 0X29);
            goto L_808021D8;
    }
    // 0x808021C0: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    // 0x808021C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808021C8: beq         $v0, $at, L_8080220C
    if (ctx->r2 == ctx->r1) {
        // 0x808021CC: nop
    
            goto L_8080220C;
    }
    // 0x808021CC: nop

    // 0x808021D0: b           L_808021E0
    // 0x808021D4: nop

        goto L_808021E0;
    // 0x808021D4: nop

L_808021D8:
    // 0x808021D8: jal         0x800856B0
    // 0x808021DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808021DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
L_808021E0:
    // 0x808021E0: jal         0x800856E0
    // 0x808021E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x808021E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x808021E8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808021EC: sw          $t6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r14;
    // 0x808021F0: jal         0x800880A8
    // 0x808021F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _gcdialogcamera_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x808021F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x808021F8: jal         0x800880B8
    // 0x808021FC: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x808021FC: nop

    after_3:
    // 0x80802200: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80802204: jal         0x800856D8
    // 0x80802208: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _capod_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x80802208: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
L_8080220C:
    // 0x8080220C: jal         0x800F54E4
    // 0x80802210: nop

    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x80802210: nop

    after_5:
    // 0x80802214: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802218: jal         0x800F5A00
    // 0x8080221C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800F5A00(rdram, ctx);
        goto after_6;
    // 0x8080221C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_6:
    // 0x80802220: jal         0x800F54E4
    // 0x80802224: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x80802224: nop

    after_7:
    // 0x80802228: jal         0x800F5F24
    // 0x8080222C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5F24(rdram, ctx);
        goto after_8;
    // 0x8080222C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80802230: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80802234: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80802238: jal         0x800EEB9C
    // 0x8080223C: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_9;
    // 0x8080223C: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    after_9:
    // 0x80802240: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80802244: jal         0x800EF04C
    // 0x80802248: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800EF04C(rdram, ctx);
        goto after_10;
    // 0x80802248: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_10:
    // 0x8080224C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80802250: addiu       $t7, $zero, 0x22
    ctx->r15 = ADD32(0, 0X22);
    // 0x80802254: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80802258: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8080225C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80802260: jal         0x8008A208
    // 0x80802264: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_11;
    // 0x80802264: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    after_11:
    // 0x80802268: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080226C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80802270: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80802274: jr          $ra
    // 0x80802278: nop

    return;
    // 0x80802278: nop

;}
RECOMP_FUNC void func_80800158_chwumbawigwam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800158: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8080015C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800160: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800164: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800168: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080016C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800170: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800174: sltiu       $at, $t8, 0xA
    ctx->r1 = ctx->r24 < 0XA ? 1 : 0;
    // 0x80800178: beq         $at, $zero, L_80800B88
    if (ctx->r1 == 0) {
        // 0x8080017C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800B88;
    }
    // 0x8080017C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800180: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2272, 0X1088) << 16);
    // 0x80800184: addu        $at, $at, $t8
    gpr jr_addend_8080018C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800188: lw          $t8, 0x1088($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2272, 0X1088));
    // 0x8080018C: jr          $t8
    // 0x80800190: nop

    switch (jr_addend_8080018C >> 2) {
        case 0: goto L_80800194; break;
        case 1: goto L_808001A8; break;
        case 2: goto L_80800274; break;
        case 3: goto L_808003BC; break;
        case 4: goto L_808003DC; break;
        case 5: goto L_8080048C; break;
        case 6: goto L_80800578; break;
        case 7: goto L_808008B8; break;
        case 8: goto L_80800ACC; break;
        case 9: goto L_80800B7C; break;
        default: switch_error(__func__, 0x8080018C, 0x80801088);
    }
    // 0x80800190: nop

L_80800194:
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800198: jal         0x80103110
    // 0x8080019C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_0;
    // 0x8080019C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808001A0: b           L_80800B8C
    // 0x808001A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800B8C;
    // 0x808001A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808001A8:
    // 0x808001A8: jal         0x800F54E4
    // 0x808001AC: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808001AC: nop

    after_1:
    // 0x808001B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001B4: jal         0x800F5A00
    // 0x808001B8: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x808001B8: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_2:
    // 0x808001BC: jal         0x80103EAC
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_3;
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808001C4: jal         0x800F54E4
    // 0x808001C8: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x808001C8: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x808001CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001D0: jal         0x800F64A4
    // 0x808001D4: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    func_800F64A4(rdram, ctx);
        goto after_5;
    // 0x808001D4: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    after_5:
    // 0x808001D8: beq         $v0, $zero, L_808001F0
    if (ctx->r2 == 0) {
        // 0x808001DC: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2272, 0X10B0) << 16);
            goto L_808001F0;
    }
    // 0x808001DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2272, 0X10B0) << 16);
    // 0x808001E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808001E4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808001E8: b           L_808001F4
    // 0x808001EC: nop

        goto L_808001F4;
    // 0x808001EC: nop

L_808001F0:
    // 0x808001F0: lwc1        $f2, 0x10B0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2272, 0X10B0));
L_808001F4:
    // 0x808001F4: jal         0x800F54E4
    // 0x808001F8: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x808001F8: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    after_6:
    // 0x808001FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800200: jal         0x800F64A4
    // 0x80800204: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    func_800F64A4(rdram, ctx);
        goto after_7;
    // 0x80800204: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    after_7:
    // 0x80800208: beq         $v0, $zero, L_80800220
    if (ctx->r2 == 0) {
        // 0x8080020C: lwc1        $f2, 0x40($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
            goto L_80800220;
    }
    // 0x8080020C: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800210: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800214: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800218: b           L_80800238
    // 0x8080021C: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
        goto L_80800238;
    // 0x8080021C: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
L_80800220:
    // 0x80800220: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x80800224: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800228: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080022C: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800230: nop

    // 0x80800234: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
L_80800238:
    // 0x80800238: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080023C: addiu       $t9, $sp, 0x6C
    ctx->r25 = ADD32(ctx->r29, 0X6C);
    // 0x80800240: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80800244: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800248: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080024C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800250: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800254: jal         0x800F00A4
    // 0x80800258: nop

    func_800F00A4(rdram, ctx);
        goto after_8;
    // 0x80800258: nop

    after_8:
    // 0x8080025C: bne         $v0, $zero, L_80800B88
    if (ctx->r2 != 0) {
        // 0x80800260: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B88;
    }
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800264: jal         0x80800B9C
    // 0x80800268: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800B9C_chwumbawigwam(rdram, ctx);
        goto after_9;
    // 0x80800268: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x8080026C: b           L_80800B8C
    // 0x80800270: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800B8C;
    // 0x80800270: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800274:
    // 0x80800274: jal         0x800F54E4
    // 0x80800278: nop

    func_800F54E4(rdram, ctx);
        goto after_10;
    // 0x80800278: nop

    after_10:
    // 0x8080027C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800280: jal         0x800F5A00
    // 0x80800284: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_800F5A00(rdram, ctx);
        goto after_11;
    // 0x80800284: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_11:
    // 0x80800288: jal         0x80103EAC
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_12;
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800290: jal         0x800F54E4
    // 0x80800294: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_800F54E4(rdram, ctx);
        goto after_13;
    // 0x80800294: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x80800298: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080029C: jal         0x800F64A4
    // 0x808002A0: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    func_800F64A4(rdram, ctx);
        goto after_14;
    // 0x808002A0: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    after_14:
    // 0x808002A4: beq         $v0, $zero, L_808002BC
    if (ctx->r2 == 0) {
        // 0x808002A8: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2272, 0X10B4) << 16);
            goto L_808002BC;
    }
    // 0x808002A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2272, 0X10B4) << 16);
    // 0x808002AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002B0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808002B4: b           L_808002C0
    // 0x808002B8: nop

        goto L_808002C0;
    // 0x808002B8: nop

L_808002BC:
    // 0x808002BC: lwc1        $f2, 0x10B4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2272, 0X10B4));
L_808002C0:
    // 0x808002C0: jal         0x800F54E4
    // 0x808002C4: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    func_800F54E4(rdram, ctx);
        goto after_15;
    // 0x808002C4: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    after_15:
    // 0x808002C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002CC: jal         0x800F64A4
    // 0x808002D0: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    func_800F64A4(rdram, ctx);
        goto after_16;
    // 0x808002D0: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    after_16:
    // 0x808002D4: beq         $v0, $zero, L_808002EC
    if (ctx->r2 == 0) {
        // 0x808002D8: lwc1        $f2, 0x40($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
            goto L_808002EC;
    }
    // 0x808002D8: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808002DC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808002E0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808002E4: b           L_80800304
    // 0x808002E8: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
        goto L_80800304;
    // 0x808002E8: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
L_808002EC:
    // 0x808002EC: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x808002F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808002F4: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808002F8: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808002FC: nop

    // 0x80800300: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
L_80800304:
    // 0x80800304: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800308: addiu       $t0, $sp, 0x60
    ctx->r8 = ADD32(ctx->r29, 0X60);
    // 0x8080030C: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80800310: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800314: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800318: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8080031C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800320: jal         0x800F00A4
    // 0x80800324: nop

    func_800F00A4(rdram, ctx);
        goto after_17;
    // 0x80800324: nop

    after_17:
    // 0x80800328: beql        $v0, $zero, L_80800B8C
    if (ctx->r2 == 0) {
        // 0x8080032C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800B8C;
    }
    goto skip_0;
    // 0x8080032C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80800330: jal         0x8010A624
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A624(rdram, ctx);
        goto after_18;
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800338: jal         0x800DA298
    // 0x8080033C: addiu       $a0, $zero, 0x18A
    ctx->r4 = ADD32(0, 0X18A);
    func_800DA298(rdram, ctx);
        goto after_19;
    // 0x8080033C: addiu       $a0, $zero, 0x18A
    ctx->r4 = ADD32(0, 0X18A);
    after_19:
    // 0x80800340: beq         $v0, $zero, L_8080038C
    if (ctx->r2 == 0) {
        // 0x80800344: nop
    
            goto L_8080038C;
    }
    // 0x80800344: nop

    // 0x80800348: jal         0x800EA05C
    // 0x8080034C: nop

    func_800EA05C(rdram, ctx);
        goto after_20;
    // 0x8080034C: nop

    after_20:
    // 0x80800350: addiu       $at, $zero, 0x112
    ctx->r1 = ADD32(0, 0X112);
    // 0x80800354: bne         $v0, $at, L_8080038C
    if (ctx->r2 != ctx->r1) {
        // 0x80800358: nop
    
            goto L_8080038C;
    }
    // 0x80800358: nop

    // 0x8080035C: jal         0x8010CD28
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_21;
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800364: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800368: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080036C: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    // 0x80800370: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800374: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80800378: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8080037C: jal         0x80087A78
    // 0x80800380: nop

    _gcgoto_entrypoint_5(rdram, ctx);
        goto after_22;
    // 0x80800380: nop

    after_22:
    // 0x80800384: b           L_80800B8C
    // 0x80800388: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800B8C;
    // 0x80800388: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080038C:
    // 0x8080038C: jal         0x8010CD28
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_23;
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800394: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800398: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080039C: addiu       $a0, $zero, 0x11E
    ctx->r4 = ADD32(0, 0X11E);
    // 0x808003A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808003A4: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x808003A8: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x808003AC: jal         0x80087A78
    // 0x808003B0: nop

    _gcgoto_entrypoint_5(rdram, ctx);
        goto after_24;
    // 0x808003B0: nop

    after_24:
    // 0x808003B4: b           L_80800B8C
    // 0x808003B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800B8C;
    // 0x808003B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808003BC:
    // 0x808003BC: jal         0x800DA298
    // 0x808003C0: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA298(rdram, ctx);
        goto after_25;
    // 0x808003C0: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_25:
    // 0x808003C4: beq         $v0, $zero, L_80800B88
    if (ctx->r2 == 0) {
        // 0x808003C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B88;
    }
    // 0x808003C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003CC: jal         0x80800B9C
    // 0x808003D0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800B9C_chwumbawigwam(rdram, ctx);
        goto after_26;
    // 0x808003D0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_26:
    // 0x808003D4: b           L_80800B8C
    // 0x808003D8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800B8C;
    // 0x808003D8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808003DC:
    // 0x808003DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E0: jal         0x80100094
    // 0x808003E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_27;
    // 0x808003E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x808003E8: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x808003EC: jal         0x80103EF4
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_28;
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x808003F4: lhu         $t1, 0x62($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X62);
    // 0x808003F8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808003FC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800400: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80800404: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800408: bgez        $t1, L_8080041C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8080040C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8080041C;
    }
    // 0x8080040C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800410: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800414: nop

    // 0x80800418: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8080041C:
    // 0x8080041C: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800420: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x80800424: addiu       $t3, $s0, 0x4
    ctx->r11 = ADD32(ctx->r16, 0X4);
    // 0x80800428: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8080042C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80800430: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800434: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80800438: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8080043C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800440: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800444: jal         0x80089870
    // 0x80800448: nop

    _sumumbofx_entrypoint_6(rdram, ctx);
        goto after_29;
    // 0x80800448: nop

    after_29:
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800450: jal         0x80100094
    // 0x80800454: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_30;
    // 0x80800454: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x80800458: jal         0x800898B0
    // 0x8080045C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_31;
    // 0x8080045C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_31:
    // 0x80800460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800464: jal         0x80100094
    // 0x80800468: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_32;
    // 0x80800468: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_32:
    // 0x8080046C: jal         0x80089918
    // 0x80800470: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_33;
    // 0x80800470: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_33:
    // 0x80800474: beq         $v0, $zero, L_80800B88
    if (ctx->r2 == 0) {
        // 0x80800478: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B88;
    }
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080047C: jal         0x80800B9C
    // 0x80800480: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800B9C_chwumbawigwam(rdram, ctx);
        goto after_34;
    // 0x80800480: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_34:
    // 0x80800484: b           L_80800B8C
    // 0x80800488: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800B8C;
    // 0x80800488: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080048C:
    // 0x8080048C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800490: jal         0x80100094
    // 0x80800494: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_35;
    // 0x80800494: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_35:
    // 0x80800498: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8080049C: jal         0x80103EF4
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_36;
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x808004A4: lhu         $t4, 0x62($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X62);
    // 0x808004A8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808004AC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808004B0: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x808004B4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808004B8: bgez        $t4, L_808004CC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x808004BC: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_808004CC;
    }
    // 0x808004BC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808004C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808004C4: nop

    // 0x808004C8: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_808004CC:
    // 0x808004CC: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808004D0: addiu       $t5, $zero, 0x28
    ctx->r13 = ADD32(0, 0X28);
    // 0x808004D4: addiu       $t6, $s0, 0x4
    ctx->r14 = ADD32(ctx->r16, 0X4);
    // 0x808004D8: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808004DC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x808004E0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808004E4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x808004E8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x808004EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808004F0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808004F4: jal         0x80089870
    // 0x808004F8: nop

    _sumumbofx_entrypoint_6(rdram, ctx);
        goto after_37;
    // 0x808004F8: nop

    after_37:
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800500: jal         0x80100094
    // 0x80800504: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_38;
    // 0x80800504: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_38:
    // 0x80800508: jal         0x800898B0
    // 0x8080050C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_39;
    // 0x8080050C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_39:
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800514: jal         0x80100094
    // 0x80800518: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_40;
    // 0x80800518: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_40:
    // 0x8080051C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800520: jal         0x80089868
    // 0x80800524: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_5(rdram, ctx);
        goto after_41;
    // 0x80800524: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_41:
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080052C: jal         0x80100094
    // 0x80800530: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_42;
    // 0x80800530: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_42:
    // 0x80800534: jal         0x80089918
    // 0x80800538: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_43;
    // 0x80800538: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_43:
    // 0x8080053C: beql        $v0, $zero, L_80800B8C
    if (ctx->r2 == 0) {
        // 0x80800540: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800B8C;
    }
    goto skip_1;
    // 0x80800540: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80800544: jal         0x800DA298
    // 0x80800548: addiu       $a0, $zero, 0x18A
    ctx->r4 = ADD32(0, 0X18A);
    func_800DA298(rdram, ctx);
        goto after_44;
    // 0x80800548: addiu       $a0, $zero, 0x18A
    ctx->r4 = ADD32(0, 0X18A);
    after_44:
    // 0x8080054C: beq         $v0, $zero, L_80800568
    if (ctx->r2 == 0) {
        // 0x80800550: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800568;
    }
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800558: jal         0x80800B9C
    // 0x8080055C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800B9C_chwumbawigwam(rdram, ctx);
        goto after_45;
    // 0x8080055C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_45:
    // 0x80800560: b           L_80800B8C
    // 0x80800564: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800B8C;
    // 0x80800564: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800568:
    // 0x80800568: jal         0x80800B9C
    // 0x8080056C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800B9C_chwumbawigwam(rdram, ctx);
        goto after_46;
    // 0x8080056C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_46:
    // 0x80800570: b           L_80800B8C
    // 0x80800574: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800B8C;
    // 0x80800574: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800578:
    // 0x80800578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080057C: jal         0x80100094
    // 0x80800580: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_47;
    // 0x80800580: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_47:
    // 0x80800584: jal         0x800898E8
    // 0x80800588: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_48;
    // 0x80800588: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_48:
    // 0x8080058C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80800590: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800594: nop

    // 0x80800598: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8080059C: nop

    // 0x808005A0: bc1fl       L_80800628
    if (!c1cs) {
        // 0x808005A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800628;
    }
    goto skip_2;
    // 0x808005A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808005A8: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x808005AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005B0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808005B4: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x808005B8: bltz        $t9, L_808005D4
    if (SIGNED(ctx->r25) < 0) {
        // 0x808005BC: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(2272, 0X10EC) << 16);
            goto L_808005D4;
    }
    // 0x808005BC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2272, 0X10EC) << 16);
    // 0x808005C0: jal         0x80089D18
    // 0x808005C4: addiu       $a2, $a2, 0x10EC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2272, 0X10EC));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_49;
    // 0x808005C4: addiu       $a2, $a2, 0x10EC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2272, 0X10EC));
    after_49:
    // 0x808005C8: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x808005CC: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x808005D0: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
L_808005D4:
    // 0x808005D4: addiu       $t3, $s0, 0x4
    ctx->r11 = ADD32(ctx->r16, 0X4);
    // 0x808005D8: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E0: jal         0x80100094
    // 0x808005E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_50;
    // 0x808005E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_50:
    // 0x808005E8: jal         0x800898E8
    // 0x808005EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_51;
    // 0x808005EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_51:
    // 0x808005F0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808005F4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808005F8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808005FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800600: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800604: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    // 0x80800608: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8080060C: jal         0x800F12D4
    // 0x80800610: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F12D4(rdram, ctx);
        goto after_52;
    // 0x80800610: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_52:
    // 0x80800614: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80800618: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x8080061C: b           L_80800744
    // 0x80800620: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
        goto L_80800744;
    // 0x80800620: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x80800624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800628:
    // 0x80800628: jal         0x80100094
    // 0x8080062C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_53;
    // 0x8080062C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_53:
    // 0x80800630: jal         0x800898E8
    // 0x80800634: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_54;
    // 0x80800634: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_54:
    // 0x80800638: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8080063C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80800640: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800644: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800648: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080064C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800650: jal         0x800F10B4
    // 0x80800654: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_800F10B4(rdram, ctx);
        goto after_55;
    // 0x80800654: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_55:
    // 0x80800658: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x8080065C: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    // 0x80800660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800664: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800668: sll         $t6, $t4, 11
    ctx->r14 = S32(ctx->r12 << 11);
    // 0x8080066C: bltz        $t6, L_80800688
    if (SIGNED(ctx->r14) < 0) {
        // 0x80800670: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(2272, 0X1100) << 16);
            goto L_80800688;
    }
    // 0x80800670: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2272, 0X1100) << 16);
    // 0x80800674: jal         0x80089D18
    // 0x80800678: addiu       $a2, $a2, 0x1100
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2272, 0X1100));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_56;
    // 0x80800678: addiu       $a2, $a2, 0x1100
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2272, 0X1100));
    after_56:
    // 0x8080067C: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80800680: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x80800684: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
L_80800688:
    // 0x80800688: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8080068C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800690: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80800694: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800698: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080069C: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x808006A0: addiu       $t0, $s0, 0x4
    ctx->r8 = ADD32(ctx->r16, 0X4);
    // 0x808006A4: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x808006A8: mul.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x808006AC: jal         0x800138D0
    // 0x808006B0: nop

    func_800138D0(rdram, ctx);
        goto after_57;
    // 0x808006B0: nop

    after_57:
    // 0x808006B4: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x808006B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808006BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808006C0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808006C4: mul.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x808006C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808006CC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808006D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808006D4: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x808006D8: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x808006DC: mul.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x808006E0: jal         0x800138D0
    // 0x808006E4: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    func_800138D0(rdram, ctx);
        goto after_58;
    // 0x808006E4: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    after_58:
    // 0x808006E8: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x808006EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808006F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808006F4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808006F8: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800700: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800704: swc1        $f6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f6.u32l;
    // 0x80800708: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8080070C: jal         0x80100094
    // 0x80800710: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    func_80100094(rdram, ctx);
        goto after_59;
    // 0x80800710: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    after_59:
    // 0x80800714: jal         0x800898E8
    // 0x80800718: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_60;
    // 0x80800718: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_60:
    // 0x8080071C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80800720: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800724: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2272, 0X10B8) << 16);
    // 0x80800728: lwc1        $f10, 0x10B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2272, 0X10B8));
    // 0x8080072C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800730: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800734: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800738: jal         0x800F12D4
    // 0x8080073C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F12D4(rdram, ctx);
        goto after_61;
    // 0x8080073C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_61:
    // 0x80800740: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
L_80800744:
    // 0x80800744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800748: jal         0x80100094
    // 0x8080074C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_62;
    // 0x8080074C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_62:
    // 0x80800750: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80800754: jal         0x80103EF4
    // 0x80800758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_63;
    // 0x80800758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_63:
    // 0x8080075C: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800760: lwc1        $f14, 0x30($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80800764: jal         0x800F0E00
    // 0x80800768: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    func_800F0E00(rdram, ctx);
        goto after_64;
    // 0x80800768: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_64:
    // 0x8080076C: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800770: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800774: lhu         $t1, 0x62($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X62);
    // 0x80800778: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8080077C: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80800780: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80800784: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800788: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080078C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800790: bgezl       $t1, L_808007A8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800794: lwc1        $f10, 0x38($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
            goto L_808007A8;
    }
    goto skip_3;
    // 0x80800794: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    skip_3:
    // 0x80800798: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080079C: nop

    // 0x808007A0: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808007A4: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
L_808007A8:
    // 0x808007A8: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x808007AC: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x808007B0: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x808007B4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808007B8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x808007BC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x808007C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808007C4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x808007C8: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808007CC: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x808007D0: jal         0x80089870
    // 0x808007D4: nop

    _sumumbofx_entrypoint_6(rdram, ctx);
        goto after_65;
    // 0x808007D4: nop

    after_65:
    // 0x808007D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007DC: jal         0x80100094
    // 0x808007E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_66;
    // 0x808007E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_66:
    // 0x808007E4: jal         0x800898B0
    // 0x808007E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_67;
    // 0x808007E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_67:
    // 0x808007EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F0: jal         0x80100094
    // 0x808007F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_68;
    // 0x808007F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_68:
    // 0x808007F8: jal         0x80089918
    // 0x808007FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_69;
    // 0x808007FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_69:
    // 0x80800800: beq         $v0, $zero, L_80800810
    if (ctx->r2 == 0) {
        // 0x80800804: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800810;
    }
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800808: jal         0x80800B9C
    // 0x8080080C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80800B9C_chwumbawigwam(rdram, ctx);
        goto after_70;
    // 0x8080080C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_70:
L_80800810:
    // 0x80800810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800814: jal         0x80100094
    // 0x80800818: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_71;
    // 0x80800818: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_71:
    // 0x8080081C: jal         0x800898E8
    // 0x80800820: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_72;
    // 0x80800820: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_72:
    // 0x80800824: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800828: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080082C: nop

    // 0x80800830: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x80800834: nop

    // 0x80800838: bc1fl       L_80800B8C
    if (!c1cs) {
        // 0x8080083C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800B8C;
    }
    goto skip_4;
    // 0x8080083C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_4:
    // 0x80800840: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x80800844: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2272, 0X10E0) << 16);
    // 0x80800848: addiu       $t7, $t7, 0x10E0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2272, 0X10E0));
    // 0x8080084C: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80800850: bltzl       $t6, L_80800B8C
    if (SIGNED(ctx->r14) < 0) {
        // 0x80800854: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800B8C;
    }
    goto skip_5;
    // 0x80800854: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_5:
    // 0x80800858: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8080085C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80800860: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2272, 0X1114) << 16);
    // 0x80800864: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x80800868: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x8080086C: addiu       $t0, $t0, 0x1114
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2272, 0X1114));
    // 0x80800870: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800874: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80800878: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8080087C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800880: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x80800884: sw          $at, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r1;
    // 0x80800888: jal         0x800BBCB8
    // 0x8080088C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_800BBCB8(rdram, ctx);
        goto after_73;
    // 0x8080088C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_73:
    // 0x80800890: lui         $a0, 0x7FFB
    ctx->r4 = S32(0X7FFB << 16);
    // 0x80800894: lui         $a2, 0x1F40
    ctx->r6 = S32(0X1F40 << 16);
    // 0x80800898: ori         $a2, $a2, 0x3E8
    ctx->r6 = ctx->r6 | 0X3E8;
    // 0x8080089C: ori         $a0, $a0, 0x5BF2
    ctx->r4 = ctx->r4 | 0X5BF2;
    // 0x808008A0: jal         0x800C4140
    // 0x808008A4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_800C4140(rdram, ctx);
        goto after_74;
    // 0x808008A4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_74:
    // 0x808008A8: lbu         $t2, 0x74($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X74);
    // 0x808008AC: ori         $t3, $t2, 0x20
    ctx->r11 = ctx->r10 | 0X20;
    // 0x808008B0: b           L_80800B88
    // 0x808008B4: sb          $t3, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r11;
        goto L_80800B88;
    // 0x808008B4: sb          $t3, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r11;
L_808008B8:
    // 0x808008B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008BC: jal         0x80100094
    // 0x808008C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_75;
    // 0x808008C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_75:
    // 0x808008C4: jal         0x800898E8
    // 0x808008C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_76;
    // 0x808008C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_76:
    // 0x808008CC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808008D0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808008D4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808008D8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x808008DC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808008E0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808008E4: jal         0x800F10B4
    // 0x808008E8: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_800F10B4(rdram, ctx);
        goto after_77;
    // 0x808008E8: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_77:
    // 0x808008EC: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    // 0x808008F0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808008F4: sll         $t6, $t4, 11
    ctx->r14 = S32(ctx->r12 << 11);
    // 0x808008F8: bltz        $t6, L_80800924
    if (SIGNED(ctx->r14) < 0) {
        // 0x808008FC: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(2272, 0X1158) << 16);
            goto L_80800924;
    }
    // 0x808008FC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2272, 0X1158) << 16);
    // 0x80800900: addiu       $a2, $a2, 0x1158
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2272, 0X1158));
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800908: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080090C: jal         0x80089D18
    // 0x80800910: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_78;
    // 0x80800910: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    after_78:
    // 0x80800914: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80800918: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8080091C: ori         $t9, $t7, 0x10
    ctx->r25 = ctx->r15 | 0X10;
    // 0x80800920: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
L_80800924:
    // 0x80800924: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80800928: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080092C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800930: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800934: mul.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80800938: addiu       $t0, $s0, 0x4
    ctx->r8 = ADD32(ctx->r16, 0X4);
    // 0x8080093C: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80800940: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x80800944: mul.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80800948: jal         0x80013970
    // 0x8080094C: nop

    func_80013970(rdram, ctx);
        goto after_79;
    // 0x8080094C: nop

    after_79:
    // 0x80800950: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800954: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800958: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8080095C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800960: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800964: mul.s       $f14, $f2, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80800968: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8080096C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800970: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800974: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800978: mul.s       $f18, $f0, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8080097C: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80800980: mul.s       $f10, $f2, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80800984: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x80800988: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    // 0x8080098C: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800990: jal         0x80013970
    // 0x80800994: nop

    func_80013970(rdram, ctx);
        goto after_80;
    // 0x80800994: nop

    after_80:
    // 0x80800998: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8080099C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808009A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808009A4: mul.s       $f18, $f0, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x808009A8: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808009AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808009B4: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    // 0x808009B8: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x808009BC: jal         0x80100094
    // 0x808009C0: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    func_80100094(rdram, ctx);
        goto after_81;
    // 0x808009C0: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    after_81:
    // 0x808009C4: jal         0x800898E8
    // 0x808009C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_82;
    // 0x808009C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_82:
    // 0x808009CC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808009D0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808009D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808009D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808009DC: lui         $a3, 0x4033
    ctx->r7 = S32(0X4033 << 16);
    // 0x808009E0: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x808009E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808009E8: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    // 0x808009EC: jal         0x800F12D4
    // 0x808009F0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F12D4(rdram, ctx);
        goto after_83;
    // 0x808009F0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_83:
    // 0x808009F4: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x808009F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009FC: jal         0x80100094
    // 0x80800A00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_84;
    // 0x80800A00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_84:
    // 0x80800A04: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80800A08: jal         0x80103EF4
    // 0x80800A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_85;
    // 0x80800A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_85:
    // 0x80800A10: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800A14: lwc1        $f14, 0x30($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80800A18: jal         0x800F0E00
    // 0x80800A1C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    func_800F0E00(rdram, ctx);
        goto after_86;
    // 0x80800A1C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_86:
    // 0x80800A20: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800A24: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800A28: lhu         $t1, 0x62($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X62);
    // 0x80800A2C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800A30: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80800A34: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80800A38: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800A3C: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800A40: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800A44: bgezl       $t1, L_80800A5C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800A48: lwc1        $f10, 0x38($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
            goto L_80800A5C;
    }
    goto skip_6;
    // 0x80800A48: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    skip_6:
    // 0x80800A4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A50: nop

    // 0x80800A54: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80800A58: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
L_80800A5C:
    // 0x80800A5C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80800A60: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x80800A64: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80800A68: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800A6C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80800A70: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80800A74: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800A78: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80800A7C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800A80: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800A84: jal         0x80089870
    // 0x80800A88: nop

    _sumumbofx_entrypoint_6(rdram, ctx);
        goto after_87;
    // 0x80800A88: nop

    after_87:
    // 0x80800A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A90: jal         0x80100094
    // 0x80800A94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_88;
    // 0x80800A94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_88:
    // 0x80800A98: jal         0x800898B0
    // 0x80800A9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_89;
    // 0x80800A9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_89:
    // 0x80800AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AA4: jal         0x80100094
    // 0x80800AA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_90;
    // 0x80800AA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_90:
    // 0x80800AAC: jal         0x80089918
    // 0x80800AB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_91;
    // 0x80800AB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_91:
    // 0x80800AB4: beq         $v0, $zero, L_80800B88
    if (ctx->r2 == 0) {
        // 0x80800AB8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B88;
    }
    // 0x80800AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ABC: jal         0x80800B9C
    // 0x80800AC0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80800B9C_chwumbawigwam(rdram, ctx);
        goto after_92;
    // 0x80800AC0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_92:
    // 0x80800AC4: b           L_80800B8C
    // 0x80800AC8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800B8C;
    // 0x80800AC8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800ACC:
    // 0x80800ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AD0: jal         0x80100094
    // 0x80800AD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_93;
    // 0x80800AD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_93:
    // 0x80800AD8: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80800ADC: jal         0x80103EF4
    // 0x80800AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_94;
    // 0x80800AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_94:
    // 0x80800AE4: lhu         $t4, 0x62($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X62);
    // 0x80800AE8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800AEC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800AF0: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80800AF4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800AF8: bgez        $t4, L_80800B0C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800AFC: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80800B0C;
    }
    // 0x80800AFC: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800B00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800B04: nop

    // 0x80800B08: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80800B0C:
    // 0x80800B0C: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800B10: addiu       $t5, $zero, 0x28
    ctx->r13 = ADD32(0, 0X28);
    // 0x80800B14: addiu       $t6, $s0, 0x4
    ctx->r14 = ADD32(ctx->r16, 0X4);
    // 0x80800B18: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80800B1C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800B20: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800B24: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80800B28: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80800B2C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800B30: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800B34: jal         0x80089870
    // 0x80800B38: nop

    _sumumbofx_entrypoint_6(rdram, ctx);
        goto after_95;
    // 0x80800B38: nop

    after_95:
    // 0x80800B3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B40: jal         0x80100094
    // 0x80800B44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_96;
    // 0x80800B44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_96:
    // 0x80800B48: jal         0x800898B0
    // 0x80800B4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_97;
    // 0x80800B4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_97:
    // 0x80800B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B54: jal         0x80100094
    // 0x80800B58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_98;
    // 0x80800B58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_98:
    // 0x80800B5C: jal         0x80089918
    // 0x80800B60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_99;
    // 0x80800B60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_99:
    // 0x80800B64: beq         $v0, $zero, L_80800B88
    if (ctx->r2 == 0) {
        // 0x80800B68: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B88;
    }
    // 0x80800B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B6C: jal         0x80800B9C
    // 0x80800B70: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80800B9C_chwumbawigwam(rdram, ctx);
        goto after_100;
    // 0x80800B70: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_100:
    // 0x80800B74: b           L_80800B8C
    // 0x80800B78: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800B8C;
    // 0x80800B78: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800B7C:
    // 0x80800B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B80: jal         0x80800B9C
    // 0x80800B84: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800B9C_chwumbawigwam(rdram, ctx);
        goto after_101;
    // 0x80800B84: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_101:
L_80800B88:
    // 0x80800B88: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800B8C:
    // 0x80800B8C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800B90: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80800B94: jr          $ra
    // 0x80800B98: nop

    return;
    // 0x80800B98: nop

;}
RECOMP_FUNC void func_800EF0B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF0B4: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800EF0B8: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EF0BC: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x800EF0C0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800EF0C4: lh          $t2, 0x4($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X4);
    // 0x800EF0C8: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800EF0CC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800EF0D0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800EF0D4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800EF0D8: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800EF0DC: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x800EF0E0: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800EF0E4: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x800EF0E8: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EF0EC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800EF0F0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EF0F4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800EF0F8: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x800EF0FC: nop

    // 0x800EF100: sh          $t1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r9;
    // 0x800EF104: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EF108: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800EF10C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800EF110: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x800EF114: jr          $ra
    // 0x800EF118: sh          $t4, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r12;
    return;
    // 0x800EF118: sh          $t4, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r12;
;}
RECOMP_FUNC void func_80802044_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802044: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80802048: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080204C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802050: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802054: jal         0x80100094
    // 0x80802058: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802058: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080205C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80802060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802064: jal         0x80100094
    // 0x80802068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80802068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080206C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80802070: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X4274) << 16);
    // 0x80802074: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1692, 0X4624) << 16);
    // 0x80802078: lbu         $v1, 0x26($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X26);
    // 0x8080207C: addiu       $t9, $t9, 0x4624
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1692, 0X4624));
    // 0x80802080: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802084: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80802088: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8080208C: lwc1        $f0, 0x4274($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X4274));
    // 0x80802090: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80802094: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802098: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x8080209C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x808020A0: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x808020A4: nop

    // 0x808020A8: bc1tl       L_80802104
    if (c1cs) {
        // 0x808020AC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802104;
    }
    goto skip_0;
    // 0x808020AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808020B0: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x808020B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808020B8: beql        $t1, $at, L_80802104
    if (ctx->r9 == ctx->r1) {
        // 0x808020BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802104;
    }
    goto skip_1;
    // 0x808020BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808020C0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808020C4: jal         0x80089D88
    // 0x808020C8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    _suspline_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808020C8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_2:
    // 0x808020CC: beq         $v0, $zero, L_80802100
    if (ctx->r2 == 0) {
        // 0x808020D0: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_80802100;
    }
    // 0x808020D0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x808020D4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808020D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808020DC: lh          $a2, 0x0($t0)
    ctx->r6 = MEM_H(ctx->r8, 0X0);
    // 0x808020E0: jal         0x80085708
    // 0x808020E4: addiu       $a3, $zero, 0x4C21
    ctx->r7 = ADD32(0, 0X4C21);
    _capod_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x808020E4: addiu       $a3, $zero, 0x4C21
    ctx->r7 = ADD32(0, 0X4C21);
    after_3:
    // 0x808020E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808020EC: jal         0x808012A4
    // 0x808020F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808012A4_chflysaucer(rdram, ctx);
        goto after_4;
    // 0x808020F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808020F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808020F8: jal         0x808009DC
    // 0x808020FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808009DC_chflysaucer(rdram, ctx);
        goto after_5;
    // 0x808020FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
L_80802100:
    // 0x80802100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802104:
    // 0x80802104: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802108: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080210C: jr          $ra
    // 0x80802110: nop

    return;
    // 0x80802110: nop

;}
RECOMP_FUNC void func_80800978_chboggyboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800978: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080097C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800980: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800984: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800988: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080098C: jal         0x80100094
    // 0x80800990: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800990: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800994: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800998: addiu       $t6, $zero, 0x3B
    ctx->r14 = ADD32(0, 0X3B);
    // 0x8080099C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808009A0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808009A4: addiu       $a1, $zero, 0x108A
    ctx->r5 = ADD32(0, 0X108A);
    // 0x808009A8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808009AC: jal         0x8008A208
    // 0x808009B0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808009B0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x808009B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009B8: jal         0x80102424
    // 0x808009BC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x808009BC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_2:
    // 0x808009C0: jal         0x8010A570
    // 0x808009C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_3;
    // 0x808009C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808009C8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x808009CC: lbu         $t8, 0x16($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X16);
    // 0x808009D0: ori         $t0, $t8, 0x80
    ctx->r8 = ctx->r24 | 0X80;
    // 0x808009D4: andi        $t1, $t0, 0xBF
    ctx->r9 = ctx->r8 & 0XBF;
    // 0x808009D8: sb          $t0, 0x16($v1)
    MEM_B(0X16, ctx->r3) = ctx->r8;
    // 0x808009DC: sb          $t1, 0x16($v1)
    MEM_B(0X16, ctx->r3) = ctx->r9;
    // 0x808009E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808009E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808009E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808009EC: jr          $ra
    // 0x808009F0: nop

    return;
    // 0x808009F0: nop

;}
RECOMP_FUNC void func_80800030_bsswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800034: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800038: jal         0x80096544
    // 0x8080003C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_80096544(rdram, ctx);
        goto after_0;
    // 0x8080003C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800040: beql        $v0, $zero, L_808000D4
    if (ctx->r2 == 0) {
        // 0x80800044: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808000D4;
    }
    goto skip_0;
    // 0x80800044: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800048: jal         0x800DC0C0
    // 0x8080004C: nop

    func_800DC0C0(rdram, ctx);
        goto after_1;
    // 0x8080004C: nop

    after_1:
    // 0x80800050: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800054: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800058: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8080005C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800060: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800064: nop

    // 0x80800068: bc1f        L_80800080
    if (!c1cs) {
        // 0x8080006C: nop
    
            goto L_80800080;
    }
    // 0x8080006C: nop

    // 0x80800070: jal         0x80092C00
    // 0x80800074: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80092C00(rdram, ctx);
        goto after_2;
    // 0x80800074: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x80800078: b           L_8080008C
    // 0x8080007C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
        goto L_8080008C;
    // 0x8080007C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_80800080:
    // 0x80800080: jal         0x80092C24
    // 0x80800084: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80092C24(rdram, ctx);
        goto after_3;
    // 0x80800084: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x80800088: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_8080008C:
    // 0x8080008C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800090: jal         0x8009FBB0
    // 0x80800094: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009FBB0(rdram, ctx);
        goto after_4;
    // 0x80800094: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_4:
    // 0x80800098: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x8080009C: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x808000A0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808000A4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x808000A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000B0: addiu       $a1, $zero, -0x3C
    ctx->r5 = ADD32(0, -0X3C);
    // 0x808000B4: addiu       $a2, $zero, -0x64
    ctx->r6 = ADD32(0, -0X64);
    // 0x808000B8: addiu       $a3, $zero, -0x3C
    ctx->r7 = ADD32(0, -0X3C);
    // 0x808000BC: jal         0x800BA930
    // 0x808000C0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800BA930(rdram, ctx);
        goto after_5;
    // 0x808000C0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_5:
    // 0x808000C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808000C8: jal         0x800BA22C
    // 0x808000CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_6;
    // 0x808000CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808000D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000D4:
    // 0x808000D4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808000D8: jr          $ra
    // 0x808000DC: nop

    return;
    // 0x808000DC: nop

;}
RECOMP_FUNC void func_80105494(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105494: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105498: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010549C: lw          $v0, 0x7C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X7C);
    // 0x801054A0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801054A4: andi        $t6, $v0, 0xFFF
    ctx->r14 = ctx->r2 & 0XFFF;
    // 0x801054A8: bne         $t6, $zero, L_801054B8
    if (ctx->r14 != 0) {
        // 0x801054AC: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_801054B8;
    }
    // 0x801054AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x801054B0: b           L_801054C4
    // 0x801054B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801054C4;
    // 0x801054B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801054B8:
    // 0x801054B8: lw          $a0, 0x6EC0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EC0);
    // 0x801054BC: jal         0x800B301C
    // 0x801054C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    freelist_at(rdram, ctx);
        goto after_0;
    // 0x801054C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_0:
L_801054C4:
    // 0x801054C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801054C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801054CC: jr          $ra
    // 0x801054D0: nop

    return;
    // 0x801054D0: nop

;}
RECOMP_FUNC void func_800A0C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0C2C: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x800A0C30: jr          $ra
    // 0x800A0C34: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
    return;
    // 0x800A0C34: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
;}
RECOMP_FUNC void gcmapsects_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801AAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801AB0: jal         0x800BF704
    // 0x80801AB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800BF704(rdram, ctx);
        goto after_0;
    // 0x80801AB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801AB8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80801ABC: sb          $t6, 0x80($v0)
    MEM_B(0X80, ctx->r2) = ctx->r14;
    // 0x80801AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801AC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801AC8: jr          $ra
    // 0x80801ACC: nop

    return;
    // 0x80801ACC: nop

;}
RECOMP_FUNC void bsmummove_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800020: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800024: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800028: jr          $ra
    // 0x8080002C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080002C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80800630_sudeflect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800630: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800638: jal         0x800F6720
    // 0x8080063C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F6720(rdram, ctx);
        goto after_0;
    // 0x8080063C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800640: beq         $v0, $zero, L_80800650
    if (ctx->r2 == 0) {
        // 0x80800644: nop
    
            goto L_80800650;
    }
    // 0x80800644: nop

    // 0x80800648: b           L_80800694
    // 0x8080064C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800694;
    // 0x8080064C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800650:
    // 0x80800650: jal         0x800F5410
    // 0x80800654: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800F5410(rdram, ctx);
        goto after_1;
    // 0x80800654: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800658: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8080065C: bne         $v0, $at, L_8080066C
    if (ctx->r2 != ctx->r1) {
        // 0x80800660: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080066C;
    }
    // 0x80800660: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800664: b           L_80800694
    // 0x80800668: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800694;
    // 0x80800668: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080066C:
    // 0x8080066C: jal         0x800F52B8
    // 0x80800670: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F52B8(rdram, ctx);
        goto after_2;
    // 0x80800670: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800674: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800678: beq         $v0, $at, L_80800688
    if (ctx->r2 == ctx->r1) {
        // 0x8080067C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80800688;
    }
    // 0x8080067C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800680: bnel        $v0, $at, L_80800694
    if (ctx->r2 != ctx->r1) {
        // 0x80800684: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800694;
    }
    goto skip_0;
    // 0x80800684: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_80800688:
    // 0x80800688: b           L_80800694
    // 0x8080068C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800694;
    // 0x8080068C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800690: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800694:
    // 0x80800694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800698: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080069C: jr          $ra
    // 0x808006A0: nop

    return;
    // 0x808006A0: nop

;}
RECOMP_FUNC void func_808000DC_chnewmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808000E8: lbu         $t8, 0x74($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X74);
    // 0x808000EC: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x808000F0: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x808000F4: ori         $t9, $t8, 0x40
    ctx->r25 = ctx->r24 | 0X40;
    // 0x808000F8: sb          $t9, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r25;
    // 0x808000FC: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80800100: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800104: jal         0x8008A208
    // 0x80800108: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80800108: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    after_0:
    // 0x8080010C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800110: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800114: jr          $ra
    // 0x80800118: nop

    return;
    // 0x80800118: nop

;}
RECOMP_FUNC void chevilspirit_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(924, 0X2270) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x2270
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(924, 0X2270));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x2270
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(924, 0X2270));
;}
RECOMP_FUNC void _bskazmove_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083508: syscall     63
    recomp_syscall_handler(rdram, ctx, 0x80083508);
    return;
    // 0x8008350C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_80801C18_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C18: jr          $ra
    // 0x80801C1C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80801C1C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8008B2DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B2DC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8008B2E0: jr          $ra
    // 0x8008B2E4: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x8008B2E4: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_8002A024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A024: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002A028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002A02C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002A030: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002A034: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8002A038: jal         0x800E9054
    // 0x8002A03C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800E9054(rdram, ctx);
        goto after_0;
    // 0x8002A03C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8002A040: bne         $v0, $zero, L_8002A064
    if (ctx->r2 != 0) {
        // 0x8002A044: nop
    
            goto L_8002A064;
    }
    // 0x8002A044: nop

L_8002A048:
    // 0x8002A048: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8002A04C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8002A050: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8002A054: jal         0x800E9054
    // 0x8002A058: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800E9054(rdram, ctx);
        goto after_1;
    // 0x8002A058: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_1:
    // 0x8002A05C: beq         $v0, $zero, L_8002A048
    if (ctx->r2 == 0) {
        // 0x8002A060: nop
    
            goto L_8002A048;
    }
    // 0x8002A060: nop

L_8002A064:
    // 0x8002A064: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8002A068: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8002A06C: lbu         $t9, 0x36($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X36);
    // 0x8002A070: blez        $t9, L_8002A0B4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8002A074: nop
    
            goto L_8002A0B4;
    }
    // 0x8002A074: nop

L_8002A078:
    // 0x8002A078: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002A07C: jal         0x8002A150
    // 0x8002A080: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8002A150(rdram, ctx);
        goto after_2;
    // 0x8002A080: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x8002A084: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002A088: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8002A08C: jal         0x8002A318
    // 0x8002A090: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_8002A318(rdram, ctx);
        goto after_3;
    // 0x8002A090: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x8002A094: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A098: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8002A09C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8002A0A0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8002A0A4: lbu         $t3, 0x36($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X36);
    // 0x8002A0A8: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8002A0AC: bne         $at, $zero, L_8002A078
    if (ctx->r1 != 0) {
        // 0x8002A0B0: nop
    
            goto L_8002A078;
    }
    // 0x8002A0B0: nop

L_8002A0B4:
    // 0x8002A0B4: b           L_8002A0BC
    // 0x8002A0B8: nop

        goto L_8002A0BC;
    // 0x8002A0B8: nop

L_8002A0BC:
    // 0x8002A0BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002A0C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002A0C4: jr          $ra
    // 0x8002A0C8: nop

    return;
    // 0x8002A0C8: nop

;}
RECOMP_FUNC void func_800EF4E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF4E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800EF4E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EF4EC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800EF4F0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800EF4F4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800EF4F8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800EF4FC: jal         0x800137F4
    // 0x800EF500: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_800137F4(rdram, ctx);
        goto after_0;
    // 0x800EF500: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800EF504: jal         0x80013788
    // 0x800EF508: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_80013788(rdram, ctx);
        goto after_1;
    // 0x800EF508: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_1:
    // 0x800EF50C: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800EF510: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800EF514: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800EF518: mul.s       $f4, $f2, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800EF51C: nop

    // 0x800EF520: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800EF524: nop

    // 0x800EF528: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EF52C: nop

    // 0x800EF530: mul.s       $f16, $f14, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x800EF534: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EF538: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x800EF53C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800EF540: swc1        $f18, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f18.u32l;
    // 0x800EF544: jal         0x800137F4
    // 0x800EF548: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    func_800137F4(rdram, ctx);
        goto after_2;
    // 0x800EF548: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x800EF54C: jal         0x80013788
    // 0x800EF550: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_80013788(rdram, ctx);
        goto after_3;
    // 0x800EF550: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_3:
    // 0x800EF554: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800EF558: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800EF55C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800EF560: mul.s       $f4, $f2, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800EF564: nop

    // 0x800EF568: mul.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800EF56C: nop

    // 0x800EF570: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EF574: nop

    // 0x800EF578: mul.s       $f16, $f12, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x800EF57C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EF580: swc1        $f8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f8.u32l;
    // 0x800EF584: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800EF588: swc1        $f18, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f18.u32l;
    // 0x800EF58C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800EF590: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800EF594: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800EF598: jr          $ra
    // 0x800EF59C: nop

    return;
    // 0x800EF59C: nop

;}
RECOMP_FUNC void func_800C90D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C90D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C90D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C90D8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C90DC: jal         0x80087E90
    // 0x800C90E0: addiu       $a0, $a0, -0x5500
    ctx->r4 = ADD32(ctx->r4, -0X5500);
    _gclightsDll_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x800C90E0: addiu       $a0, $a0, -0x5500
    ctx->r4 = ADD32(ctx->r4, -0X5500);
    after_0:
    // 0x800C90E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C90E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C90EC: jr          $ra
    // 0x800C90F0: nop

    return;
    // 0x800C90F0: nop

;}
RECOMP_FUNC void subaddietaxi_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800B80: jal         0x8010410C
    // 0x80800B84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8010410C(rdram, ctx);
        goto after_0;
    // 0x80800B84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800B88: sh          $zero, 0x20($v0)
    MEM_H(0X20, ctx->r2) = 0;
    // 0x80800B8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800B90: jal         0x8008A4B0
    // 0x80800B94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800B94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BA0: jr          $ra
    // 0x80800BA4: nop

    return;
    // 0x80800BA4: nop

;}
RECOMP_FUNC void func_80800630_chlighthalo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800630: jr          $ra
    // 0x80800634: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800634: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _bsblongleg_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082A88: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082A88);
    return;
    // 0x80082A8C: addi        $t0, $zero, 0x60
    ctx->r8 = ADD32(0, 0X60);
;}
RECOMP_FUNC void func_80801228_chdinofamilymother(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801228: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080122C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801230: lw          $t6, 0x34($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X34);
    // 0x80801234: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80801238: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080123C: beql        $t6, $zero, L_80801258
    if (ctx->r14 == 0) {
        // 0x80801240: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801258;
    }
    goto skip_0;
    // 0x80801240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801244: jal         0x800856B8
    // 0x80801248: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _capod_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80801248: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080124C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80801250: sw          $zero, 0x34($a1)
    MEM_W(0X34, ctx->r5) = 0;
    // 0x80801254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801258:
    // 0x80801258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080125C: jr          $ra
    // 0x80801260: nop

    return;
    // 0x80801260: nop

;}
RECOMP_FUNC void func_800A718C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A718C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800A7190: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A7194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7198: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800A719C: jal         0x800E3BFC
    // 0x800A71A0: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_800E3BFC(rdram, ctx);
        goto after_0;
    // 0x800A71A0: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_0:
    // 0x800A71A4: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x800A71A8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A71AC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800A71B0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A71B4: jal         0x800E3C58
    // 0x800A71B8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800E3C58(rdram, ctx);
        goto after_1;
    // 0x800A71B8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_1:
    // 0x800A71BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A71C0: jal         0x800E3900
    // 0x800A71C4: lwc1        $f12, 0x55F0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X55F0);
    func_800E3900(rdram, ctx);
        goto after_2;
    // 0x800A71C4: lwc1        $f12, 0x55F0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X55F0);
    after_2:
    // 0x800A71C8: jal         0x800E3CE8
    // 0x800A71CC: nop

    func_800E3CE8(rdram, ctx);
        goto after_3;
    // 0x800A71CC: nop

    after_3:
    // 0x800A71D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A71D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A71D8: jr          $ra
    // 0x800A71DC: nop

    return;
    // 0x800A71DC: nop

;}
RECOMP_FUNC void func_8080030C_chtoxicroomprops(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080030C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800310: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800314: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800318: beq         $a1, $at, L_80800334
    if (ctx->r5 == ctx->r1) {
        // 0x8080031C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80800334;
    }
    // 0x8080031C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800320: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x80800324: beq         $a1, $at, L_8080035C
    if (ctx->r5 == ctx->r1) {
        // 0x80800328: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080035C;
    }
    // 0x80800328: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080032C: b           L_80800380
    // 0x80800330: nop

        goto L_80800380;
    // 0x80800330: nop

L_80800334:
    // 0x80800334: jal         0x800DA524
    // 0x80800338: addiu       $a0, $zero, 0xA04
    ctx->r4 = ADD32(0, 0XA04);
    func_800DA524(rdram, ctx);
        goto after_0;
    // 0x80800338: addiu       $a0, $zero, 0xA04
    ctx->r4 = ADD32(0, 0XA04);
    after_0:
    // 0x8080033C: jal         0x800DA524
    // 0x80800340: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    func_800DA524(rdram, ctx);
        goto after_1;
    // 0x80800340: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    after_1:
    // 0x80800344: jal         0x80089D40
    // 0x80800348: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800348: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080034C: jal         0x80088830
    // 0x80800350: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_3;
    // 0x80800350: nop

    after_3:
    // 0x80800354: b           L_80800380
    // 0x80800358: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800380;
    // 0x80800358: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8080035C:
    // 0x8080035C: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x80800360: bne         $a2, $at, L_80800378
    if (ctx->r6 != ctx->r1) {
        // 0x80800364: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800378;
    }
    // 0x80800364: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800368: jal         0x80101FDC
    // 0x8080036C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x8080036C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800370: b           L_80800380
    // 0x80800374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800380;
    // 0x80800374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800378:
    // 0x80800378: b           L_80800380
    // 0x8080037C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800380;
    // 0x8080037C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800380:
    // 0x80800380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800384: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800388: jr          $ra
    // 0x8080038C: nop

    return;
    // 0x8080038C: nop

;}
RECOMP_FUNC void func_800A92A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A92A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A92AC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800A92B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A92B4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800A92B8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A92BC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A92C0: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800A92C4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800A92C8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800A92CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A92D0: addiu       $s3, $s3, 0x76F0
    ctx->r19 = ADD32(ctx->r19, 0X76F0);
    // 0x800A92D4: addiu       $s0, $s0, 0x76D0
    ctx->r16 = ADD32(ctx->r16, 0X76D0);
    // 0x800A92D8: lw          $a0, 0x58($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X58);
L_800A92DC:
    // 0x800A92DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A92E0: beql        $a0, $zero, L_800A92F4
    if (ctx->r4 == 0) {
        // 0x800A92E4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800A92F4;
    }
    goto skip_0;
    // 0x800A92E4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x800A92E8: jal         0x8010FE00
    // 0x800A92EC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_8010FE00(rdram, ctx);
        goto after_0;
    // 0x800A92EC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_0:
    // 0x800A92F0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800A92F4:
    // 0x800A92F4: bnel        $s0, $s3, L_800A92DC
    if (ctx->r16 != ctx->r19) {
        // 0x800A92F8: lw          $a0, 0x58($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X58);
            goto L_800A92DC;
    }
    goto skip_1;
    // 0x800A92F8: lw          $a0, 0x58($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X58);
    skip_1:
    // 0x800A92FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A9300: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A9304: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A9308: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800A930C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800A9310: jr          $ra
    // 0x800A9314: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800A9314: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800100_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800100: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800108: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080010C: jal         0x8009E6EC
    // 0x80800110: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80800110: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800114: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800118: beq         $v0, $at, L_80800158
    if (ctx->r2 == ctx->r1) {
        // 0x8080011C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800158;
    }
    // 0x8080011C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800120: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x80800124: beq         $v0, $at, L_80800140
    if (ctx->r2 == ctx->r1) {
        // 0x80800128: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800140;
    }
    // 0x80800128: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080012C: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x80800130: beq         $v0, $at, L_80800148
    if (ctx->r2 == ctx->r1) {
        // 0x80800134: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_80800148;
    }
    // 0x80800134: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80800138: b           L_80800150
    // 0x8080013C: nop

        goto L_80800150;
    // 0x8080013C: nop

L_80800140:
    // 0x80800140: b           L_80800158
    // 0x80800144: sb          $t6, 0x15F($a0)
    MEM_B(0X15F, ctx->r4) = ctx->r14;
        goto L_80800158;
    // 0x80800144: sb          $t6, 0x15F($a0)
    MEM_B(0X15F, ctx->r4) = ctx->r14;
L_80800148:
    // 0x80800148: b           L_80800158
    // 0x8080014C: sb          $zero, 0x15F($a0)
    MEM_B(0X15F, ctx->r4) = 0;
        goto L_80800158;
    // 0x8080014C: sb          $zero, 0x15F($a0)
    MEM_B(0X15F, ctx->r4) = 0;
L_80800150:
    // 0x80800150: jalr        $t9
    // 0x80800154: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80800154: nop

    after_1:
L_80800158:
    // 0x80800158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080015C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800160: jr          $ra
    // 0x80800164: nop

    return;
    // 0x80800164: nop

;}
RECOMP_FUNC void _sufreezy_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089BA0: syscall     804
    recomp_syscall_handler(rdram, ctx, 0x80089BA0);
    return;
    // 0x80089BA4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800FAAB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FAAB4: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800FAAB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FAABC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800FAAC0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800FAAC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FAAC8: addiu       $t7, $t7, 0x3880
    ctx->r15 = ADD32(ctx->r15, 0X3880);
    // 0x800FAACC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800FAAD0: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x800FAAD4: lw          $t8, 0x18($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X18);
    // 0x800FAAD8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800FAADC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FAAE0: bne         $t8, $zero, L_800FAAF0
    if (ctx->r24 != 0) {
        // 0x800FAAE4: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_800FAAF0;
    }
    // 0x800FAAE4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800FAAE8: b           L_800FAB38
    // 0x800FAAEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FAB38;
    // 0x800FAAEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FAAF0:
    // 0x800FAAF0: sb          $t9, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r25;
    // 0x800FAAF4: jal         0x800FA240
    // 0x800FAAF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800FA240(rdram, ctx);
        goto after_0;
    // 0x800FAAF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800FAAFC: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x800FAB00: jal         0x8008A5B8
    // 0x800FAB04: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _scinfobar_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x800FAB04: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800FAB08: bne         $v0, $zero, L_800FAB18
    if (ctx->r2 != 0) {
        // 0x800FAB0C: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_800FAB18;
    }
    // 0x800FAB0C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800FAB10: b           L_800FAB38
    // 0x800FAB14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FAB38;
    // 0x800FAB14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FAB18:
    // 0x800FAB18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FAB1C: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x800FAB20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FAB24: jal         0x8008A5B0
    // 0x800FAB28: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    _scinfobar_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x800FAB28: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x800FAB2C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800FAB30: sb          $t0, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r8;
    // 0x800FAB34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800FAB38:
    // 0x800FAB38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FAB3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FAB40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800FAB44: jr          $ra
    // 0x800FAB48: nop

    return;
    // 0x800FAB48: nop

    // 0x800FAB4C: nop

;}
RECOMP_FUNC void func_800C9044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9048: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C904C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9050: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C9054: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    // 0x800C9058: jal         0x800B28CC
    // 0x800C905C: addiu       $a1, $a2, -0x1
    ctx->r5 = ADD32(ctx->r6, -0X1);
    vector_at(rdram, ctx);
        goto after_0;
    // 0x800C905C: addiu       $a1, $a2, -0x1
    ctx->r5 = ADD32(ctx->r6, -0X1);
    after_0:
    // 0x800C9060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9064: lbu         $v0, 0x17($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X17);
    // 0x800C9068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C906C: jr          $ra
    // 0x800C9070: nop

    return;
    // 0x800C9070: nop

;}
RECOMP_FUNC void func_80801604_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801604: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801608: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080160C: jal         0x80090A2C
    // 0x80801610: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80090A2C(rdram, ctx);
        goto after_0;
    // 0x80801610: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801614: jal         0x800951B4
    // 0x80801618: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800951B4(rdram, ctx);
        goto after_1;
    // 0x80801618: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080161C: jal         0x8080064C
    // 0x80801620: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstrexlarge_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80801620: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80801624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801628: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080162C: jr          $ra
    // 0x80801630: nop

    return;
    // 0x80801630: nop

;}
RECOMP_FUNC void func_808001E0_gcgoto(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808001E4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x808001E8: lbu         $t6, 0x75C0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X75C0);
    // 0x808001EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001F0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001F4: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x808001F8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x808001FC: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80800200: bne         $t6, $zero, L_808003BC
    if (ctx->r14 != 0) {
        // 0x80800204: sw          $a3, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r7;
            goto L_808003BC;
    }
    // 0x80800204: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80800208: beq         $a0, $zero, L_80800228
    if (ctx->r4 == 0) {
        // 0x8080020C: or          $t7, $a0, $zero
        ctx->r15 = ctx->r4 | 0;
            goto L_80800228;
    }
    // 0x8080020C: or          $t7, $a0, $zero
    ctx->r15 = ctx->r4 | 0;
    // 0x80800210: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2570, 0X740) << 16);
    // 0x80800214: addiu       $a0, $a0, 0x740
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2570, 0X740));
    // 0x80800218: jal         0x800882A0
    // 0x8080021C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    _gccubesearch_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x8080021C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_0:
    // 0x80800220: b           L_8080022C
    // 0x80800224: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_8080022C;
    // 0x80800224: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80800228:
    // 0x80800228: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8080022C:
    // 0x8080022C: jal         0x8008FE68
    // 0x80800230: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_8008FE68(rdram, ctx);
        goto after_1;
    // 0x80800230: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_1:
    // 0x80800234: beq         $s0, $zero, L_808003A8
    if (ctx->r16 == 0) {
        // 0x80800238: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003A8;
    }
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: jal         0x80088C00
    // 0x80800240: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80800240: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_2:
    // 0x80800244: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80800248: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8080024C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800250: beq         $t8, $zero, L_8080027C
    if (ctx->r24 == 0) {
        // 0x80800254: addiu       $a1, $sp, 0x38
        ctx->r5 = ADD32(ctx->r29, 0X38);
            goto L_8080027C;
    }
    // 0x80800254: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80800258: lhu         $t9, 0x8($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X8);
    // 0x8080025C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80800260: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800264: addiu       $at, $zero, 0x24F
    ctx->r1 = ADD32(0, 0X24F);
    // 0x80800268: bne         $t9, $at, L_80800284
    if (ctx->r25 != ctx->r1) {
        // 0x8080026C: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_80800284;
    }
    // 0x8080026C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800270: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800274: b           L_80800284
    // 0x80800278: nop

        goto L_80800284;
    // 0x80800278: nop

L_8080027C:
    // 0x8080027C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800280: nop

L_80800284:
    // 0x80800284: jal         0x800EEAD4
    // 0x80800288: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    func_800EEAD4(rdram, ctx);
        goto after_3;
    // 0x80800288: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x8080028C: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800290: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800294: nop

    // 0x80800298: bc1fl       L_808003AC
    if (!c1cs) {
        // 0x8080029C: lw          $a0, 0x54($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X54);
            goto L_808003AC;
    }
    goto skip_0;
    // 0x8080029C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x808002A0: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x808002A4: addiu       $at, $zero, 0x24D
    ctx->r1 = ADD32(0, 0X24D);
    // 0x808002A8: bnel        $v0, $at, L_80800300
    if (ctx->r2 != ctx->r1) {
        // 0x808002AC: addiu       $at, $zero, 0x24E
        ctx->r1 = ADD32(0, 0X24E);
            goto L_80800300;
    }
    goto skip_1;
    // 0x808002AC: addiu       $at, $zero, 0x24E
    ctx->r1 = ADD32(0, 0X24E);
    skip_1:
    // 0x808002B0: jal         0x800F54E4
    // 0x808002B4: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x808002B4: nop

    after_4:
    // 0x808002B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002BC: jal         0x80087910
    // 0x808002C0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    _plcamera_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x808002C0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_5:
    // 0x808002C4: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x808002C8: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x808002CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808002D0: jal         0x8080011C
    // 0x808002D4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8080011C_gcgoto(rdram, ctx);
        goto after_6;
    // 0x808002D4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x808002D8: jal         0x800A1618
    // 0x808002DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800A1618(rdram, ctx);
        goto after_7;
    // 0x808002DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x808002E0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808002E4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808002E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808002EC: jal         0x80090358
    // 0x808002F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80090358(rdram, ctx);
        goto after_8;
    // 0x808002F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x808002F4: b           L_808003C0
    // 0x808002F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003C0;
    // 0x808002F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808002FC: addiu       $at, $zero, 0x24E
    ctx->r1 = ADD32(0, 0X24E);
L_80800300:
    // 0x80800300: bnel        $v0, $at, L_8080035C
    if (ctx->r2 != ctx->r1) {
        // 0x80800304: lw          $v0, 0xC($s0)
        ctx->r2 = MEM_W(ctx->r16, 0XC);
            goto L_8080035C;
    }
    goto skip_2;
    // 0x80800304: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    skip_2:
    // 0x80800308: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8080030C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800310: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80800314: srl         $t0, $v0, 23
    ctx->r8 = S32(U32(ctx->r2) >> 23);
    // 0x80800318: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8080031C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80800320: bgez        $t0, L_80800338
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800324: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800338;
    }
    // 0x80800324: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800328: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080032C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800330: nop

    // 0x80800334: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80800338:
    // 0x80800338: lui         $at, 0x7F
    ctx->r1 = S32(0X7F << 16);
    // 0x8080033C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80800340: and         $t1, $v0, $at
    ctx->r9 = ctx->r2 & ctx->r1;
    // 0x80800344: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80800348: jal         0x80800468
    // 0x8080034C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    gcgoto_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x8080034C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_9:
    // 0x80800350: b           L_808003C0
    // 0x80800354: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003C0;
    // 0x80800354: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800358: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
L_8080035C:
    // 0x8080035C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800360: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80800364: srl         $t2, $v0, 23
    ctx->r10 = S32(U32(ctx->r2) >> 23);
    // 0x80800368: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8080036C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80800370: bgez        $t2, L_80800388
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800374: cvt.s.w     $f8, $f8
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80800388;
    }
    // 0x80800374: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800378: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080037C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800380: nop

    // 0x80800384: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80800388:
    // 0x80800388: lui         $at, 0x7F
    ctx->r1 = S32(0X7F << 16);
    // 0x8080038C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80800390: and         $t3, $v0, $at
    ctx->r11 = ctx->r2 & ctx->r1;
    // 0x80800394: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80800398: jal         0x80800468
    // 0x8080039C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    gcgoto_entrypoint_4(rdram, ctx);
        goto after_10;
    // 0x8080039C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_10:
    // 0x808003A0: b           L_808003C0
    // 0x808003A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003C0;
    // 0x808003A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003A8:
    // 0x808003A8: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
L_808003AC:
    // 0x808003AC: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x808003B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808003B4: jal         0x8080011C
    // 0x808003B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8080011C_gcgoto(rdram, ctx);
        goto after_11;
    // 0x808003B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_11:
L_808003BC:
    // 0x808003BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003C0:
    // 0x808003C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003C4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808003C8: jr          $ra
    // 0x808003CC: nop

    return;
    // 0x808003CC: nop

;}
RECOMP_FUNC void _bainvisible_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800854D0: syscall     164
    recomp_syscall_handler(rdram, ctx, 0x800854D0);
    return;
    // 0x800854D4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _baswim_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085298: syscall     156
    recomp_syscall_handler(rdram, ctx, 0x80085298);
    return;
    // 0x8008529C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _subaddiecustomhits_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A010: syscall     822
    recomp_syscall_handler(rdram, ctx, 0x8008A010);
    return;
    // 0x8008A014: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80028520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028520: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80028524: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80028528: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8002852C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80028530: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80028534: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80028538: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8002853C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80028540: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80028544: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80028548: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x8002854C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80028550: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80028554: lw          $t1, 0x20($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X20);
    // 0x80028558: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8002855C: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80028560: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x80028564: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80028568: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8002856C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80028570: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80028574: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x80028578: lw          $t7, 0x20($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X20);
    // 0x8002857C: sltu        $at, $t5, $t7
    ctx->r1 = ctx->r13 < ctx->r15 ? 1 : 0;
    // 0x80028580: beq         $at, $zero, L_800285A0
    if (ctx->r1 == 0) {
        // 0x80028584: nop
    
            goto L_800285A0;
    }
    // 0x80028584: nop

    // 0x80028588: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8002858C: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80028590: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80028594: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80028598: addu        $t8, $t2, $t4
    ctx->r24 = ADD32(ctx->r10, ctx->r12);
    // 0x8002859C: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
L_800285A0:
    // 0x800285A0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800285A4: addiu       $t9, $t6, 0x170
    ctx->r25 = ADD32(ctx->r14, 0X170);
    // 0x800285A8: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800285AC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800285B0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800285B4: sltu        $at, $t5, $t0
    ctx->r1 = ctx->r13 < ctx->r8 ? 1 : 0;
    // 0x800285B8: beq         $at, $zero, L_800286A4
    if (ctx->r1 == 0) {
        // 0x800285BC: nop
    
            goto L_800286A4;
    }
    // 0x800285BC: nop

    // 0x800285C0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800285C4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800285C8: subu        $t3, $t7, $t1
    ctx->r11 = SUB32(ctx->r15, ctx->r9);
    // 0x800285CC: sra         $t2, $t3, 1
    ctx->r10 = S32(SIGNED(ctx->r11) >> 1);
    // 0x800285D0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800285D4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800285D8: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800285DC: subu        $t6, $t4, $t8
    ctx->r14 = SUB32(ctx->r12, ctx->r24);
    // 0x800285E0: sra         $t9, $t6, 1
    ctx->r25 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800285E4: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800285E8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800285EC: addiu       $t5, $t0, 0x8
    ctx->r13 = ADD32(ctx->r8, 0X8);
    // 0x800285F0: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x800285F4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800285F8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800285FC: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80028600: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80028604: sll         $t1, $t7, 1
    ctx->r9 = S32(ctx->r15 << 1);
    // 0x80028608: andi        $t3, $t1, 0xFFF
    ctx->r11 = ctx->r9 & 0XFFF;
    // 0x8002860C: sll         $t2, $t3, 12
    ctx->r10 = S32(ctx->r11 << 12);
    // 0x80028610: lui         $at, 0x600
    ctx->r1 = S32(0X600 << 16);
    // 0x80028614: or          $t4, $t2, $at
    ctx->r12 = ctx->r10 | ctx->r1;
    // 0x80028618: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8002861C: or          $t9, $t4, $t6
    ctx->r25 = ctx->r12 | ctx->r14;
    // 0x80028620: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80028624: jal         0x8002E330
    // 0x80028628: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80028628: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x8002862C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80028630: sw          $v0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r2;
    // 0x80028634: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80028638: addiu       $t1, $t7, 0x8
    ctx->r9 = ADD32(ctx->r15, 0X8);
    // 0x8002863C: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80028640: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80028644: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80028648: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8002864C: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80028650: sll         $t8, $t2, 1
    ctx->r24 = S32(ctx->r10 << 1);
    // 0x80028654: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80028658: andi        $t5, $t0, 0xFFF
    ctx->r13 = ctx->r8 & 0XFFF;
    // 0x8002865C: addu        $t4, $t3, $t8
    ctx->r12 = ADD32(ctx->r11, ctx->r24);
    // 0x80028660: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80028664: sll         $t7, $t5, 12
    ctx->r15 = S32(ctx->r13 << 12);
    // 0x80028668: lui         $at, 0x600
    ctx->r1 = S32(0X600 << 16);
    // 0x8002866C: or          $t1, $t7, $at
    ctx->r9 = ctx->r15 | ctx->r1;
    // 0x80028670: andi        $t6, $t4, 0xFFF
    ctx->r14 = ctx->r12 & 0XFFF;
    // 0x80028674: or          $t2, $t1, $t6
    ctx->r10 = ctx->r9 | ctx->r14;
    // 0x80028678: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8002867C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80028680: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80028684: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x80028688: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8002868C: jal         0x8002E330
    // 0x80028690: lw          $a0, 0x20($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X20);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x80028690: lw          $a0, 0x20($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X20);
    after_1:
    // 0x80028694: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80028698: sw          $v0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r2;
    // 0x8002869C: b           L_800286DC
    // 0x800286A0: nop

        goto L_800286DC;
    // 0x800286A0: nop

L_800286A4:
    // 0x800286A4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800286A8: addiu       $t1, $t7, 0x8
    ctx->r9 = ADD32(ctx->r15, 0X8);
    // 0x800286AC: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x800286B0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800286B4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800286B8: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800286BC: lui         $at, 0x617
    ctx->r1 = S32(0X617 << 16);
    // 0x800286C0: andi        $t2, $t6, 0xFFF
    ctx->r10 = ctx->r14 & 0XFFF;
    // 0x800286C4: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x800286C8: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800286CC: jal         0x8002E330
    // 0x800286D0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800286D0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x800286D4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800286D8: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
L_800286DC:
    // 0x800286DC: b           L_800286EC
    // 0x800286E0: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
        goto L_800286EC;
    // 0x800286E0: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x800286E4: b           L_800286EC
    // 0x800286E8: nop

        goto L_800286EC;
    // 0x800286E8: nop

L_800286EC:
    // 0x800286EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800286F0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800286F4: jr          $ra
    // 0x800286F8: nop

    return;
    // 0x800286F8: nop

;}
RECOMP_FUNC void func_800D1A6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1A6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D1A70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1A74: jal         0x800D16C4
    // 0x800D1A78: nop

    func_800D16C4(rdram, ctx);
        goto after_0;
    // 0x800D1A78: nop

    after_0:
    // 0x800D1A7C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800D1A80: addiu       $a1, $a1, -0x50B0
    ctx->r5 = ADD32(ctx->r5, -0X50B0);
    // 0x800D1A84: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800D1A88: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x800D1A8C: lh          $v1, 0x2($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X2);
    // 0x800D1A90: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800D1A94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D1A98: beq         $v1, $at, L_800D1AB4
    if (ctx->r3 == ctx->r1) {
        // 0x800D1A9C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D1AB4;
    }
    // 0x800D1A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D1AA0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D1AA4: bne         $v1, $at, L_800D1ABC
    if (ctx->r3 != ctx->r1) {
        // 0x800D1AA8: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_800D1ABC;
    }
    // 0x800D1AA8: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x800D1AAC: b           L_800D1AC4
    // 0x800D1AB0: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
        goto L_800D1AC4;
    // 0x800D1AB0: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
L_800D1AB4:
    // 0x800D1AB4: b           L_800D1AC4
    // 0x800D1AB8: addiu       $v0, $zero, 0x3E7
    ctx->r2 = ADD32(0, 0X3E7);
        goto L_800D1AC4;
    // 0x800D1AB8: addiu       $v0, $zero, 0x3E7
    ctx->r2 = ADD32(0, 0X3E7);
L_800D1ABC:
    // 0x800D1ABC: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800D1AC0: lh          $v0, 0x2($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X2);
L_800D1AC4:
    // 0x800D1AC4: jr          $ra
    // 0x800D1AC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800D1AC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80112E98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112E98: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80112E9C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80112EA0: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80112EA4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80112EA8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80112EAC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80112EB0: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x80112EB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80112EB8: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80112EBC: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80112EC0: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80112EC4: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80112EC8: or          $fp, $a2, $zero
    ctx->r30 = ctx->r6 | 0;
    // 0x80112ECC: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80112ED0: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80112ED4: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80112ED8: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80112EDC: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80112EE0: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80112EE4: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80112EE8: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80112EEC: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80112EF0: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x80112EF4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80112EF8: jal         0x800F0E00
    // 0x80112EFC: sub.s       $f14, $f20, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f20.fl - ctx->f4.fl;
    func_800F0E00(rdram, ctx);
        goto after_0;
    // 0x80112EFC: sub.s       $f14, $f20, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f20.fl - ctx->f4.fl;
    after_0:
    // 0x80112F00: lw          $s7, 0xB8($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XB8);
    // 0x80112F04: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x80112F08: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80112F0C: beq         $s7, $zero, L_80112F4C
    if (ctx->r23 == 0) {
        // 0x80112F10: addiu       $s6, $sp, 0x88
        ctx->r22 = ADD32(ctx->r29, 0X88);
            goto L_80112F4C;
    }
    // 0x80112F10: addiu       $s6, $sp, 0x88
    ctx->r22 = ADD32(ctx->r29, 0X88);
    // 0x80112F14: beq         $s7, $at, L_80112F3C
    if (ctx->r23 == ctx->r1) {
        // 0x80112F18: lui         $s4, 0x8012
        ctx->r20 = S32(0X8012 << 16);
            goto L_80112F3C;
    }
    // 0x80112F18: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80112F1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80112F20: beq         $s7, $at, L_80112F44
    if (ctx->r23 == ctx->r1) {
        // 0x80112F24: lui         $s4, 0x8012
        ctx->r20 = S32(0X8012 << 16);
            goto L_80112F44;
    }
    // 0x80112F24: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80112F28: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80112F2C: beq         $s7, $v1, L_80112F44
    if (ctx->r23 == ctx->r3) {
        // 0x80112F30: nop
    
            goto L_80112F44;
    }
    // 0x80112F30: nop

    // 0x80112F34: b           L_80112F4C
    // 0x80112F38: nop

        goto L_80112F4C;
    // 0x80112F38: nop

L_80112F3C:
    // 0x80112F3C: b           L_80112F58
    // 0x80112F40: addiu       $s4, $s4, 0x4A40
    ctx->r20 = ADD32(ctx->r20, 0X4A40);
        goto L_80112F58;
    // 0x80112F40: addiu       $s4, $s4, 0x4A40
    ctx->r20 = ADD32(ctx->r20, 0X4A40);
L_80112F44:
    // 0x80112F44: b           L_80112F58
    // 0x80112F48: addiu       $s4, $s4, 0x4A48
    ctx->r20 = ADD32(ctx->r20, 0X4A48);
        goto L_80112F58;
    // 0x80112F48: addiu       $s4, $s4, 0x4A48
    ctx->r20 = ADD32(ctx->r20, 0X4A48);
L_80112F4C:
    // 0x80112F4C: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80112F50: addiu       $s4, $s4, 0x4A38
    ctx->r20 = ADD32(ctx->r20, 0X4A38);
    // 0x80112F54: mov.s       $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    ctx->f26.fl = ctx->f22.fl;
L_80112F58:
    // 0x80112F58: lw          $t6, 0x4($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X4);
    // 0x80112F5C: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80112F60: lw          $s5, 0xBC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XBC);
    // 0x80112F64: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80112F68: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x80112F6C: sltu        $at, $s0, $t8
    ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
    // 0x80112F70: beq         $at, $zero, L_80113058
    if (ctx->r1 == 0) {
        // 0x80112F74: addiu       $s2, $sp, 0x9C
        ctx->r18 = ADD32(ctx->r29, 0X9C);
            goto L_80113058;
    }
    // 0x80112F74: addiu       $s2, $sp, 0x9C
    ctx->r18 = ADD32(ctx->r29, 0X9C);
    // 0x80112F78: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80112F7C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80112F80: neg.s       $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = -ctx->f20.fl;
    // 0x80112F84: addiu       $s1, $sp, 0x78
    ctx->r17 = ADD32(ctx->r29, 0X78);
    // 0x80112F88: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80112F8C:
    // 0x80112F8C: bne         $s7, $v1, L_80112F98
    if (ctx->r23 != ctx->r3) {
        // 0x80112F90: lwc1        $f20, 0x0($s0)
        ctx->f20.u32l = MEM_W(ctx->r16, 0X0);
            goto L_80112F98;
    }
    // 0x80112F90: lwc1        $f20, 0x0($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80112F94: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_80112F98:
    // 0x80112F98: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80112F9C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80112FA0: jal         0x800EFA20
    // 0x80112FA4: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    func_800EFA20(rdram, ctx);
        goto after_1;
    // 0x80112FA4: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_1:
    // 0x80112FA8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80112FAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80112FB0: jal         0x800EF934
    // 0x80112FB4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EF934(rdram, ctx);
        goto after_2;
    // 0x80112FB4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x80112FB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80112FBC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80112FC0: jal         0x800EE780
    // 0x80112FC4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800EE780(rdram, ctx);
        goto after_3;
    // 0x80112FC4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_3:
    // 0x80112FC8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80112FCC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80112FD0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80112FD4: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x80112FD8: jal         0x800FAB50
    // 0x80112FDC: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    func_800FAB50(rdram, ctx);
        goto after_4;
    // 0x80112FDC: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_4:
    // 0x80112FE0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80112FE4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80112FE8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80112FEC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80112FF0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80112FF4: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x80112FF8: jal         0x800FB3C0
    // 0x80112FFC: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    func_800FB3C0(rdram, ctx);
        goto after_5;
    // 0x80112FFC: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    after_5:
    // 0x80113000: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80113004: jal         0x800EEAD4
    // 0x80113008: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EEAD4(rdram, ctx);
        goto after_6;
    // 0x80113008: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x8011300C: c.lt.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f26.fl < ctx->f0.fl;
    // 0x80113010: nop

    // 0x80113014: bc1fl       L_8011303C
    if (!c1cs) {
        // 0x80113018: lw          $t1, 0x4($s4)
        ctx->r9 = MEM_W(ctx->r20, 0X4);
            goto L_8011303C;
    }
    goto skip_0;
    // 0x80113018: lw          $t1, 0x4($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X4);
    skip_0:
    // 0x8011301C: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x80113020: jal         0x80110770
    // 0x80113024: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80110770(rdram, ctx);
        goto after_7;
    // 0x80113024: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x80113028: jal         0x801113B8
    // 0x8011302C: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    func_801113B8(rdram, ctx);
        goto after_8;
    // 0x8011302C: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    after_8:
    // 0x80113030: b           L_8011305C
    // 0x80113034: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8011305C;
    // 0x80113034: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80113038: lw          $t1, 0x4($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X4);
L_8011303C:
    // 0x8011303C: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x80113040: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80113044: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80113048: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8011304C: sltu        $at, $s0, $t3
    ctx->r1 = ctx->r16 < ctx->r11 ? 1 : 0;
    // 0x80113050: bnel        $at, $zero, L_80112F8C
    if (ctx->r1 != 0) {
        // 0x80113054: addiu       $v1, $zero, 0x3
        ctx->r3 = ADD32(0, 0X3);
            goto L_80112F8C;
    }
    goto skip_1;
    // 0x80113054: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    skip_1:
L_80113058:
    // 0x80113058: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8011305C:
    // 0x8011305C: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80113060: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80113064: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80113068: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8011306C: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80113070: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80113074: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80113078: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8011307C: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80113080: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80113084: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80113088: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x8011308C: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80113090: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x80113094: jr          $ra
    // 0x80113098: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80113098: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_800B7B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7B8C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B7B90: addiu       $v0, $v0, -0x7E80
    ctx->r2 = ADD32(ctx->r2, -0X7E80);
    // 0x800B7B94: sb          $a0, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r4;
    // 0x800B7B98: sb          $a1, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r5;
    // 0x800B7B9C: jr          $ra
    // 0x800B7BA0: sb          $a2, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r6;
    return;
    // 0x800B7BA0: sb          $a2, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r6;
;}
RECOMP_FUNC void _suflamefx_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089938: syscall     798
    recomp_syscall_handler(rdram, ctx, 0x80089938);
    return;
    // 0x8008993C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800EE0F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE0F0: jr          $ra
    // 0x800EE0F4: sw          $a1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r5;
    return;
    // 0x800EE0F4: sw          $a1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_80800F48_chlagoonufoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800F4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800F50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800F54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800F58: jal         0x80100094
    // 0x80800F5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800F5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800F60: jal         0x8080078C
    // 0x80800F64: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8080078C_chlagoonufoint(rdram, ctx);
        goto after_1;
    // 0x80800F64: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800F68: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800F6C: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x80800F70: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800F74: jal         0x800EFD24
    // 0x80800F78: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x80800F78: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x80800F7C: jal         0x800C8A98
    // 0x80800F80: nop

    func_800C8A98(rdram, ctx);
        goto after_3;
    // 0x80800F80: nop

    after_3:
    // 0x80800F84: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800F88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800F8C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800F90: jal         0x800C8CB8
    // 0x80800F94: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    func_800C8CB8(rdram, ctx);
        goto after_4;
    // 0x80800F94: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    after_4:
    // 0x80800F98: jal         0x800DA298
    // 0x80800F9C: addiu       $a0, $zero, 0x9F0
    ctx->r4 = ADD32(0, 0X9F0);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80800F9C: addiu       $a0, $zero, 0x9F0
    ctx->r4 = ADD32(0, 0X9F0);
    after_5:
    // 0x80800FA0: bnel        $v0, $zero, L_80800FB8
    if (ctx->r2 != 0) {
        // 0x80800FA4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FB8;
    }
    goto skip_0;
    // 0x80800FA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800FA8: jal         0x80088848
    // 0x80800FAC: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_6;
    // 0x80800FAC: nop

    after_6:
    // 0x80800FB0: beq         $v0, $zero, L_80800FC0
    if (ctx->r2 == 0) {
        // 0x80800FB4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FC0;
    }
    // 0x80800FB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800FB8:
    // 0x80800FB8: jal         0x80800E80
    // 0x80800FBC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800E80_chlagoonufoint(rdram, ctx);
        goto after_7;
    // 0x80800FBC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
L_80800FC0:
    // 0x80800FC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800FC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800FC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800FCC: jr          $ra
    // 0x80800FD0: nop

    return;
    // 0x80800FD0: nop

;}
RECOMP_FUNC void func_800F2290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2290: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800F2294: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800F2298: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800F229C: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800F22A0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800F22A4: nop

    // 0x800F22A8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800F22AC: jr          $ra
    // 0x800F22B0: sub.s       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f18.fl;
    return;
    // 0x800F22B0: sub.s       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f18.fl;
;}
RECOMP_FUNC void glidmake_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800294: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800298: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080029C: jal         0x8001B084
    // 0x808002A0: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x808002A0: nop

    after_0:
    // 0x808002A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002AC: jr          $ra
    // 0x808002B0: nop

    return;
    // 0x808002B0: nop

;}
RECOMP_FUNC void func_800EE84C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE84C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800EE850: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800EE854: nop

    // 0x800EE858: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800EE85C: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800EE860: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x800EE864: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800EE868: nop

    // 0x800EE86C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800EE870: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x800EE874: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x800EE878: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800EE87C: nop

    // 0x800EE880: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800EE884: jr          $ra
    // 0x800EE888: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x800EE888: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void _chfpsgame_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800873C8: syscall     562
    recomp_syscall_handler(rdram, ctx, 0x800873C8);
    return;
    // 0x800873CC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _ncbafly_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800892D8: syscall     771
    recomp_syscall_handler(rdram, ctx, 0x800892D8);
    return;
    // 0x800892DC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
