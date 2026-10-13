#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void bskazglide_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009EC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808009F0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(244, 0XAE0) << 16);
    // 0x808009F4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808009F8: jr          $ra
    // 0x808009FC: lw          $v0, 0xAE0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(244, 0XAE0));
    return;
    // 0x808009FC: lw          $v0, 0xAE0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(244, 0XAE0));
;}
RECOMP_FUNC void func_80802AD8_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802AD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802ADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802AE0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80802AE4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80802AE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802AEC: jal         0x80100094
    // 0x80802AF0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802AF0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80802AF4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80802AF8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80802AFC: addu        $v1, $v0, $a3
    ctx->r3 = ADD32(ctx->r2, ctx->r7);
    // 0x80802B00: slti        $at, $a3, 0x9
    ctx->r1 = SIGNED(ctx->r7) < 0X9 ? 1 : 0;
    // 0x80802B04: bne         $at, $zero, L_80802B24
    if (ctx->r1 != 0) {
        // 0x80802B08: sb          $a2, 0x487($v1)
        MEM_B(0X487, ctx->r3) = ctx->r6;
            goto L_80802B24;
    }
    // 0x80802B08: sb          $a2, 0x487($v1)
    MEM_B(0X487, ctx->r3) = ctx->r6;
    // 0x80802B0C: addu        $a3, $a3, $a3
    ctx->r7 = ADD32(ctx->r7, ctx->r7);
    // 0x80802B10: addiu       $a3, $a3, -0x9
    ctx->r7 = ADD32(ctx->r7, -0X9);
    // 0x80802B14: addu        $v1, $v0, $a3
    ctx->r3 = ADD32(ctx->r2, ctx->r7);
    // 0x80802B18: sb          $a2, 0x478($v1)
    MEM_B(0X478, ctx->r3) = ctx->r6;
    // 0x80802B1C: b           L_80802B28
    // 0x80802B20: sb          $a2, 0x479($v1)
    MEM_B(0X479, ctx->r3) = ctx->r6;
        goto L_80802B28;
    // 0x80802B20: sb          $a2, 0x479($v1)
    MEM_B(0X479, ctx->r3) = ctx->r6;
L_80802B24:
    // 0x80802B24: sb          $a2, 0x478($v1)
    MEM_B(0X478, ctx->r3) = ctx->r6;
L_80802B28:
    // 0x80802B28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802B2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802B30: jr          $ra
    // 0x80802B34: nop

    return;
    // 0x80802B34: nop

    // 0x80802B38: nop

    // 0x80802B3C: nop

;}
RECOMP_FUNC void func_80102190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102190: beql        $a1, $zero, L_801021AC
    if (ctx->r5 == 0) {
        // 0x80102194: lbu         $t9, 0x74($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X74);
            goto L_801021AC;
    }
    goto skip_0;
    // 0x80102194: lbu         $t9, 0x74($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X74);
    skip_0:
    // 0x80102198: lbu         $t6, 0x74($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X74);
    // 0x8010219C: andi        $t7, $t6, 0xFFF7
    ctx->r15 = ctx->r14 & 0XFFF7;
    // 0x801021A0: jr          $ra
    // 0x801021A4: sb          $t7, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r15;
    return;
    // 0x801021A4: sb          $t7, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r15;
    // 0x801021A8: lbu         $t9, 0x74($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X74);
L_801021AC:
    // 0x801021AC: ori         $t0, $t9, 0x8
    ctx->r8 = ctx->r25 | 0X8;
    // 0x801021B0: sb          $t0, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r8;
    // 0x801021B4: jr          $ra
    // 0x801021B8: nop

    return;
    // 0x801021B8: nop

;}
RECOMP_FUNC void func_80115D88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115D88: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80115D8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80115D90: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80115D94: jal         0x801107F0
    // 0x80115D98: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_801107F0(rdram, ctx);
        goto after_0;
    // 0x80115D98: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x80115D9C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80115DA0: jal         0x801158CC
    // 0x80115DA4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_801158CC(rdram, ctx);
        goto after_1;
    // 0x80115DA4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80115DA8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80115DAC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80115DB0: jal         0x800EFB24
    // 0x80115DB4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x80115DB4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x80115DB8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80115DBC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80115DC0: lw          $a1, 0x3C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X3C);
    // 0x80115DC4: jal         0x800F1884
    // 0x80115DC8: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    func_800F1884(rdram, ctx);
        goto after_3;
    // 0x80115DC8: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    after_3:
    // 0x80115DCC: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80115DD0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80115DD4: lw          $t8, 0x3C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X3C);
    // 0x80115DD8: swc1        $f4, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->f4.u32l;
    // 0x80115DDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80115DE0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80115DE4: jr          $ra
    // 0x80115DE8: nop

    return;
    // 0x80115DE8: nop

;}
RECOMP_FUNC void func_800A8380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8380: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A8384: addiu       $v0, $v0, 0x7670
    ctx->r2 = ADD32(ctx->r2, 0X7670);
    // 0x800A8388: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x800A838C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800A8390: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // 0x800A8394: bne         $t6, $zero, L_800A83A4
    if (ctx->r14 != 0) {
        // 0x800A8398: nop
    
            goto L_800A83A4;
    }
    // 0x800A8398: nop

    // 0x800A839C: b           L_800A83A4
    // 0x800A83A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800A83A4;
    // 0x800A83A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800A83A4:
    // 0x800A83A4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800A83A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A83AC: beq         $a0, $at, L_800A83CC
    if (ctx->r4 == ctx->r1) {
        // 0x800A83B0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A83CC;
    }
    // 0x800A83B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A83B4: beq         $a0, $at, L_800A83D4
    if (ctx->r4 == ctx->r1) {
        // 0x800A83B8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800A83D4;
    }
    // 0x800A83B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A83BC: beq         $a0, $at, L_800A8414
    if (ctx->r4 == ctx->r1) {
        // 0x800A83C0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800A8414;
    }
    // 0x800A83C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A83C4: b           L_800A841C
    // 0x800A83C8: nop

        goto L_800A841C;
    // 0x800A83C8: nop

L_800A83CC:
    // 0x800A83CC: jr          $ra
    // 0x800A83D0: addu        $v0, $v1, $a1
    ctx->r2 = ADD32(ctx->r3, ctx->r5);
    return;
    // 0x800A83D0: addu        $v0, $v1, $a1
    ctx->r2 = ADD32(ctx->r3, ctx->r5);
L_800A83D4:
    // 0x800A83D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A83D8: bne         $v1, $at, L_800A83F8
    if (ctx->r3 != ctx->r1) {
        // 0x800A83DC: nop
    
            goto L_800A83F8;
    }
    // 0x800A83DC: nop

    // 0x800A83E0: beq         $a1, $zero, L_800A83F0
    if (ctx->r5 == 0) {
        // 0x800A83E4: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_800A83F0;
    }
    // 0x800A83E4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800A83E8: jr          $ra
    // 0x800A83EC: addiu       $v0, $a1, 0x4
    ctx->r2 = ADD32(ctx->r5, 0X4);
    return;
    // 0x800A83EC: addiu       $v0, $a1, 0x4
    ctx->r2 = ADD32(ctx->r5, 0X4);
L_800A83F0:
    // 0x800A83F0: jr          $ra
    // 0x800A83F4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800A83F4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800A83F8:
    // 0x800A83F8: beq         $a1, $zero, L_800A840C
    if (ctx->r5 == 0) {
        // 0x800A83FC: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_800A840C;
    }
    // 0x800A83FC: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800A8400: sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5 << 1);
    // 0x800A8404: jr          $ra
    // 0x800A8408: addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
    return;
    // 0x800A8408: addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
L_800A840C:
    // 0x800A840C: jr          $ra
    // 0x800A8410: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800A8410: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800A8414:
    // 0x800A8414: jr          $ra
    // 0x800A8418: addiu       $v0, $a1, 0x3
    ctx->r2 = ADD32(ctx->r5, 0X3);
    return;
    // 0x800A8418: addiu       $v0, $a1, 0x3
    ctx->r2 = ADD32(ctx->r5, 0X3);
L_800A841C:
    // 0x800A841C: jr          $ra
    // 0x800A8420: nop

    return;
    // 0x800A8420: nop

;}
RECOMP_FUNC void yaw_applyIdeal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C974: lw          $v0, 0xF8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF8);
    // 0x8009C978: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8009C97C: jr          $ra
    // 0x8009C980: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x8009C980: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_800A21C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A21C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A21CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A21D0: jal         0x800EA05C
    // 0x800A21D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x800A21D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A21D8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A21DC: addiu       $t0, $t0, -0x6D90
    ctx->r8 = ADD32(ctx->r8, -0X6D90);
    // 0x800A21E0: lh          $t6, 0x0($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X0);
    // 0x800A21E4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800A21E8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800A21EC: beq         $a2, $t6, L_800A221C
    if (ctx->r6 == ctx->r14) {
        // 0x800A21F0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800A221C;
    }
    // 0x800A21F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A21F4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A21F8: addiu       $v1, $t7, -0x6D90
    ctx->r3 = ADD32(ctx->r15, -0X6D90);
    // 0x800A21FC: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
L_800A2200:
    // 0x800A2200: beql        $v0, $a0, L_800A2220
    if (ctx->r2 == ctx->r4) {
        // 0x800A2204: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_800A2220;
    }
    goto skip_0;
    // 0x800A2204: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    skip_0:
    // 0x800A2208: lh          $a0, 0x4($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X4);
    // 0x800A220C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A2210: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A2214: bne         $a2, $a0, L_800A2200
    if (ctx->r6 != ctx->r4) {
        // 0x800A2218: nop
    
            goto L_800A2200;
    }
    // 0x800A2218: nop

L_800A221C:
    // 0x800A221C: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
L_800A2220:
    // 0x800A2220: addu        $v1, $t0, $t8
    ctx->r3 = ADD32(ctx->r8, ctx->r24);
    // 0x800A2224: lbu         $t9, 0x2($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X2);
    // 0x800A2228: lw          $t1, 0xB4($a3)
    ctx->r9 = MEM_W(ctx->r7, 0XB4);
    // 0x800A222C: sb          $t9, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r25;
    // 0x800A2230: lw          $t3, 0xB4($a3)
    ctx->r11 = MEM_W(ctx->r7, 0XB4);
    // 0x800A2234: lbu         $t2, 0x3($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X3);
    // 0x800A2238: sb          $t2, 0x1($t3)
    MEM_B(0X1, ctx->r11) = ctx->r10;
    // 0x800A223C: lh          $t4, 0x0($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X0);
    // 0x800A2240: bnel        $a2, $t4, L_800A2270
    if (ctx->r6 != ctx->r12) {
        // 0x800A2244: lw          $v0, 0xB4($a3)
        ctx->r2 = MEM_W(ctx->r7, 0XB4);
            goto L_800A2270;
    }
    goto skip_1;
    // 0x800A2244: lw          $v0, 0xB4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XB4);
    skip_1:
    // 0x800A2248: jal         0x800C8C18
    // 0x800A224C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800C8C18(rdram, ctx);
        goto after_1;
    // 0x800A224C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x800A2250: blez        $v0, L_800A226C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A2254: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_800A226C;
    }
    // 0x800A2254: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800A2258: lw          $t6, 0xB4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0XB4);
    // 0x800A225C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800A2260: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x800A2264: lw          $t7, 0xB4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0XB4);
    // 0x800A2268: sb          $zero, 0x1($t7)
    MEM_B(0X1, ctx->r15) = 0;
L_800A226C:
    // 0x800A226C: lw          $v0, 0xB4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XB4);
L_800A2270:
    // 0x800A2270: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800A2274: lb          $a1, 0x0($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X0);
    // 0x800A2278: slti        $at, $a1, 0x3
    ctx->r1 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x800A227C: bne         $at, $zero, L_800A2290
    if (ctx->r1 != 0) {
        // 0x800A2280: nop
    
            goto L_800A2290;
    }
    // 0x800A2280: nop

    // 0x800A2284: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800A2288: lw          $t9, 0xB4($a3)
    ctx->r25 = MEM_W(ctx->r7, 0XB4);
    // 0x800A228C: lb          $a1, 0x0($t9)
    ctx->r5 = MEM_B(ctx->r25, 0X0);
L_800A2290:
    // 0x800A2290: jal         0x800A25DC
    // 0x800A2294: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800A25DC(rdram, ctx);
        goto after_2;
    // 0x800A2294: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x800A2298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A229C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A22A0: jr          $ra
    // 0x800A22A4: nop

    return;
    // 0x800A22A4: nop

;}
RECOMP_FUNC void func_80800528_chloggo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800528: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080052C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800530: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800534: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800538: beq         $a1, $at, L_80800554
    if (ctx->r5 == ctx->r1) {
        // 0x8080053C: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_80800554;
    }
    // 0x8080053C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800540: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800544: beq         $a1, $at, L_80800598
    if (ctx->r5 == ctx->r1) {
        // 0x80800548: nop
    
            goto L_80800598;
    }
    // 0x80800548: nop

    // 0x8080054C: b           L_808005C8
    // 0x80800550: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005C8;
    // 0x80800550: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800554:
    // 0x80800554: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800558: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8080055C: jal         0x800EE7F8
    // 0x80800560: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800560: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x80800564: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800568: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8080056C: lui         $a2, 0xC348
    ctx->r6 = S32(0XC348 << 16);
    // 0x80800570: jal         0x800EF1B8
    // 0x80800574: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x80800574: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    after_1:
    // 0x80800578: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080057C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800580: jal         0x80086670
    // 0x80800584: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800584: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_2:
    // 0x80800588: jal         0x800DA544
    // 0x8080058C: addiu       $a0, $zero, 0x181
    ctx->r4 = ADD32(0, 0X181);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x8080058C: addiu       $a0, $zero, 0x181
    ctx->r4 = ADD32(0, 0X181);
    after_3:
    // 0x80800590: b           L_808005C8
    // 0x80800594: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005C8;
    // 0x80800594: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800598:
    // 0x80800598: jal         0x80101080
    // 0x8080059C: nop

    func_80101080(rdram, ctx);
        goto after_4;
    // 0x8080059C: nop

    after_4:
    // 0x808005A0: jal         0x80106790
    // 0x808005A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_5;
    // 0x808005A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x808005A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005AC: jal         0x800866C0
    // 0x808005B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _chexploder_entrypoint_13(rdram, ctx);
        goto after_6;
    // 0x808005B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808005B4: b           L_808005C8
    // 0x808005B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005C8;
    // 0x808005B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808005BC: b           L_808005C8
    // 0x808005C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005C8;
    // 0x808005C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808005C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005C8:
    // 0x808005C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808005D0: jr          $ra
    // 0x808005D4: nop

    return;
    // 0x808005D4: nop

    // 0x808005D8: nop

    // 0x808005DC: nop

;}
RECOMP_FUNC void func_80800000_chdinotraindoorswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800008: bne         $a1, $at, L_80800024
    if (ctx->r5 != ctx->r1) {
        // 0x8080000C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800024;
    }
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: addiu       $a0, $zero, 0x114
    ctx->r4 = ADD32(0, 0X114);
    // 0x80800014: jal         0x800887D8
    // 0x80800018: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800018: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_0:
    // 0x8080001C: b           L_8080002C
    // 0x80800020: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080002C;
    // 0x80800020: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800024:
    // 0x80800024: jal         0x80085820
    // 0x80800028: nop

    _chswitch_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80800028: nop

    after_1:
L_8080002C:
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
RECOMP_FUNC void bashake_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8080000C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800010: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800014: jal         0x8009C128
    // 0x80800018: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800018: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x8080001C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800020: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80800024: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(588, 0X100) << 16);
    // 0x80800028: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8080002C: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(588, 0X13C) << 16);
    // 0x80800030: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80800034: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800038: addiu       $t1, $t1, 0x13C
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(588, 0X13C));
    // 0x8080003C: addiu       $t8, $t8, 0x100
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(588, 0X100));
    // 0x80800040: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x80800044: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x80800048: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8080004C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800050: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800054: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x80800058: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8080005C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800060: jal         0x800E1610
    // 0x80800064: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    func_800E1610(rdram, ctx);
        goto after_1;
    // 0x80800064: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80800068: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8080006C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800070: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800074: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80800078: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x8080007C: jal         0x80085490
    // 0x80800080: lw          $a3, 0x4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X4);
    _bamotor_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800080: lw          $a3, 0x4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X4);
    after_2:
    // 0x80800084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800088: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080008C: jr          $ra
    // 0x80800090: nop

    return;
    // 0x80800090: nop

;}
RECOMP_FUNC void func_808009C0_chcrusherboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808009CC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808009D0: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    // 0x808009D4: lui         $a2, 0x4370
    ctx->r6 = S32(0X4370 << 16);
    // 0x808009D8: jal         0x80089F18
    // 0x808009DC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808009DC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_0:
    // 0x808009E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808009E4: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x808009E8: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x808009EC: bgez        $t8, L_80800A04
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808009F0: nop
    
            goto L_80800A04;
    }
    // 0x808009F0: nop

    // 0x808009F4: jal         0x80800338
    // 0x808009F8: nop

    func_80800338_chcrusherboulder(rdram, ctx);
        goto after_1;
    // 0x808009F8: nop

    after_1:
    // 0x808009FC: b           L_80800A10
    // 0x80800A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800A10;
    // 0x80800A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A04:
    // 0x80800A04: jal         0x8080087C
    // 0x80800A08: nop

    func_8080087C_chcrusherboulder(rdram, ctx);
        goto after_2;
    // 0x80800A08: nop

    after_2:
    // 0x80800A0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A10:
    // 0x80800A10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A14: jr          $ra
    // 0x80800A18: nop

    return;
    // 0x80800A18: nop

;}
RECOMP_FUNC void _badata_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084650: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x80084650);
    return;
    // 0x80084654: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800F78EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F78EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F78F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F78F4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800F78F8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800F78FC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F7900: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
    // 0x800F7904: lw          $s0, 0x5490($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X5490);
    // 0x800F7908: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800F790C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F7910: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800F7914: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800F7918: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800F791C: jal         0x8009ACF4
    // 0x800F7920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009ACF4(rdram, ctx);
        goto after_0;
    // 0x800F7920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800F7924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F7928: jal         0x8009AD04
    // 0x800F792C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8009AD04(rdram, ctx);
        goto after_1;
    // 0x800F792C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x800F7930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F7934: jal         0x8009AD20
    // 0x800F7938: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_8009AD20(rdram, ctx);
        goto after_2;
    // 0x800F7938: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_2:
    // 0x800F793C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F7940: jal         0x8009AD44
    // 0x800F7944: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8009AD44(rdram, ctx);
        goto after_3;
    // 0x800F7944: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x800F7948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F794C: jal         0x8009E7C8
    // 0x800F7950: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    func_8009E7C8(rdram, ctx);
        goto after_4;
    // 0x800F7950: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    after_4:
    // 0x800F7954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7958: xori        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 ^ 0X2;
    // 0x800F795C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F7960: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F7964: jr          $ra
    // 0x800F7968: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    return;
    // 0x800F7968: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void heap_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B084: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001B088: beq         $a0, $zero, L_8001B0B8
    if (ctx->r4 == 0) {
        // 0x8001B08C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8001B0B8;
    }
    // 0x8001B08C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B090: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8001B094: lw          $t7, -0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, -0XC);
    // 0x8001B098: addiu       $v0, $v0, -0x8B0
    ctx->r2 = ADD32(ctx->r2, -0X8B0);
    // 0x8001B09C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8001B0A0: subu        $t8, $t7, $a0
    ctx->r24 = SUB32(ctx->r15, ctx->r4);
    // 0x8001B0A4: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x8001B0A8: subu        $t9, $t6, $t8
    ctx->r25 = SUB32(ctx->r14, ctx->r24);
    // 0x8001B0AC: addiu       $t0, $t9, -0x10
    ctx->r8 = ADD32(ctx->r25, -0X10);
    // 0x8001B0B0: jal         0x8001A7B0
    // 0x8001B0B4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    heap_init_empty_block(rdram, ctx);
        goto after_0;
    // 0x8001B0B4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    after_0:
L_8001B0B8:
    // 0x8001B0B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001B0BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001B0C0: jr          $ra
    // 0x8001B0C4: nop

    return;
    // 0x8001B0C4: nop

;}
RECOMP_FUNC void func_808005D4_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005D4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808005D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808005DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808005E0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x808005E4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x808005E8: addiu       $s2, $sp, 0x44
    ctx->r18 = ADD32(ctx->r29, 0X44);
    // 0x808005EC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808005F0: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    // 0x808005F4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808005F8: jal         0x800EE7F8
    // 0x808005FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808005FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x80800600: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80800604: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800608: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x8080060C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80800610: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x80800614: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800618: jal         0x800EF214
    // 0x8080061C: nop

    func_800EF214(rdram, ctx);
        goto after_1;
    // 0x8080061C: nop

    after_1:
    // 0x80800620: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1140, 0X2A38) << 16);
    // 0x80800624: addiu       $t6, $t6, 0x2A38
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1140, 0X2A38));
    // 0x80800628: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080062C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800630: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800634: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800638: jal         0x800BBCB8
    // 0x8080063C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x8080063C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_2:
    // 0x80800640: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1140, 0X2A00) << 16);
    // 0x80800644: addiu       $t7, $t7, 0x2A00
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1140, 0X2A00));
    // 0x80800648: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080064C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800650: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800654: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800658: jal         0x800BBCB8
    // 0x8080065C: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_800BBCB8(rdram, ctx);
        goto after_3;
    // 0x8080065C: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_3:
    // 0x80800660: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x80800664: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1140, 0X2A6C) << 16);
    // 0x80800668: addiu       $a3, $a3, 0x2A6C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1140, 0X2A6C));
    // 0x8080066C: andi        $t8, $a1, 0x1
    ctx->r24 = ctx->r5 & 0X1;
    // 0x80800670: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80800674: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80800678: jal         0x8010D930
    // 0x8080067C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_8010D930(rdram, ctx);
        goto after_4;
    // 0x8080067C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_4:
    // 0x80800680: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1140, 0X2A7C) << 16);
    // 0x80800684: addiu       $a2, $a2, 0x2A7C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1140, 0X2A7C));
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080068C: jal         0x80089D18
    // 0x80800690: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800690: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x80800694: addiu       $s2, $sp, 0x38
    ctx->r18 = ADD32(ctx->r29, 0X38);
    // 0x80800698: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080069C: jal         0x800EE7F8
    // 0x808006A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x808006A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x808006A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808006A8: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x808006AC: jal         0x800EF1B8
    // 0x808006B0: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_7;
    // 0x808006B0: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    after_7:
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808006BC: jal         0x80086670
    // 0x808006C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x808006C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x808006C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808006C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808006CC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x808006D0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808006D4: jr          $ra
    // 0x808006D8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x808006D8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800B3EDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3EDC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B3EE0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B3EE4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800B3EE8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800B3EEC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B3EF0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B3EF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B3EF8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B3EFC: lw          $s2, 0x0($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X0);
    // 0x800B3F00: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800B3F04: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800B3F08: lh          $t7, 0x4($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X4);
    // 0x800B3F0C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800B3F10: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    // 0x800B3F14: beql        $t7, $zero, L_800B3F44
    if (ctx->r15 == 0) {
        // 0x800B3F18: lh          $v0, 0x2($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X2);
            goto L_800B3F44;
    }
    goto skip_0;
    // 0x800B3F18: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    skip_0:
    // 0x800B3F1C: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
L_800B3F20:
    // 0x800B3F20: or          $s3, $s0, $zero
    ctx->r19 = ctx->r16 | 0;
    // 0x800B3F24: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B3F28: jal         0x800B39D0
    // 0x800B3F2C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    func_800B39D0(rdram, ctx);
        goto after_0;
    // 0x800B3F2C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    after_0:
    // 0x800B3F30: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x800B3F34: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B3F38: bnel        $t8, $zero, L_800B3F20
    if (ctx->r24 != 0) {
        // 0x800B3F3C: lh          $a1, 0x0($s0)
        ctx->r5 = MEM_H(ctx->r16, 0X0);
            goto L_800B3F20;
    }
    goto skip_1;
    // 0x800B3F3C: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    skip_1:
    // 0x800B3F40: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
L_800B3F44:
    // 0x800B3F44: lh          $a0, 0x2($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X2);
    // 0x800B3F48: addu        $t9, $v0, $s1
    ctx->r25 = ADD32(ctx->r2, ctx->r17);
    // 0x800B3F4C: bne         $a0, $t9, L_800B3FB0
    if (ctx->r4 != ctx->r25) {
        // 0x800B3F50: slt         $at, $v0, $s4
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
            goto L_800B3FB0;
    }
    // 0x800B3F50: slt         $at, $v0, $s4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800B3F54: bnel        $at, $zero, L_800B3FB4
    if (ctx->r1 != 0) {
        // 0x800B3F58: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800B3FB4;
    }
    goto skip_2;
    // 0x800B3F58: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x800B3F5C: blez        $s4, L_800B3F6C
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800B3F60: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800B3F6C;
    }
    // 0x800B3F60: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800B3F64: b           L_800B3F6C
    // 0x800B3F68: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
        goto L_800B3F6C;
    // 0x800B3F68: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
L_800B3F6C:
    // 0x800B3F6C: beq         $s4, $zero, L_800B3F7C
    if (ctx->r20 == 0) {
        // 0x800B3F70: subu        $s1, $a0, $v1
        ctx->r17 = SUB32(ctx->r4, ctx->r3);
            goto L_800B3F7C;
    }
    // 0x800B3F70: subu        $s1, $a0, $v1
    ctx->r17 = SUB32(ctx->r4, ctx->r3);
    // 0x800B3F74: bne         $s4, $v0, L_800B3F84
    if (ctx->r20 != ctx->r2) {
        // 0x800B3F78: subu        $t0, $v0, $s4
        ctx->r8 = SUB32(ctx->r2, ctx->r20);
            goto L_800B3F84;
    }
    // 0x800B3F78: subu        $t0, $v0, $s4
    ctx->r8 = SUB32(ctx->r2, ctx->r20);
L_800B3F7C:
    // 0x800B3F7C: b           L_800B3F88
    // 0x800B3F80: sh          $zero, 0x0($s3)
    MEM_H(0X0, ctx->r19) = 0;
        goto L_800B3F88;
    // 0x800B3F80: sh          $zero, 0x0($s3)
    MEM_H(0X0, ctx->r19) = 0;
L_800B3F84:
    // 0x800B3F84: sh          $t0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r8;
L_800B3F88:
    // 0x800B3F88: lh          $t1, 0x0($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X0);
    // 0x800B3F8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B3F90: multu       $t1, $s1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B3F94: mflo        $a1
    ctx->r5 = lo;
    // 0x800B3F98: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800B3F9C: jal         0x8001B208
    // 0x800B3FA0: nop

    heap_realloc(rdram, ctx);
        goto after_1;
    // 0x800B3FA0: nop

    after_1:
    // 0x800B3FA4: sh          $s1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r17;
    // 0x800B3FA8: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800B3FAC: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
L_800B3FB0:
    // 0x800B3FB0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B3FB4:
    // 0x800B3FB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B3FB8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3FBC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B3FC0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800B3FC4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800B3FC8: jr          $ra
    // 0x800B3FCC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B3FCC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void subaddiecustomhits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800048: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8080004C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80800050: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80800054: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800058: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8080005C: jal         0x80106790
    // 0x80800060: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800060: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800064: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800068: jal         0x80103AA0
    // 0x8080006C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80103AA0(rdram, ctx);
        goto after_1;
    // 0x8080006C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_1:
    // 0x80800070: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80800074: jal         0x801040A8
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801040A8(rdram, ctx);
        goto after_2;
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080007C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80800080: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800084: beq         $t6, $zero, L_8080009C
    if (ctx->r14 == 0) {
        // 0x80800088: nop
    
            goto L_8080009C;
    }
    // 0x80800088: nop

    // 0x8080008C: jal         0x800AE0B8
    // 0x80800090: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_800AE0B8(rdram, ctx);
        goto after_3;
    // 0x80800090: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80800094: bne         $v0, $zero, L_808000A4
    if (ctx->r2 != 0) {
        // 0x80800098: nop
    
            goto L_808000A4;
    }
    // 0x80800098: nop

L_8080009C:
    // 0x8080009C: b           L_80800168
    // 0x808000A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800168;
    // 0x808000A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000A4:
    // 0x808000A4: jal         0x800B2824
    // 0x808000A8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_800B2824(rdram, ctx);
        goto after_4;
    // 0x808000A8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_4:
    // 0x808000AC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x808000B0: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808000B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808000B8: nop

    // 0x808000BC: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x808000C0: nop

    // 0x808000C4: bc1f        L_808000D4
    if (!c1cs) {
        // 0x808000C8: nop
    
            goto L_808000D4;
    }
    // 0x808000C8: nop

    // 0x808000CC: b           L_80800120
    // 0x808000D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80800120;
    // 0x808000D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_808000D4:
    // 0x808000D4: jal         0x801027F4
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801027F4(rdram, ctx);
        goto after_5;
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000DC: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x808000E0: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x808000E4: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x808000E8: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x808000EC: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x808000F0: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x808000F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808000F8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808000FC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800100: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800104: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800108: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8080010C: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80800110: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80800114: jal         0x800B1F8C
    // 0x80800118: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_800B1F8C(rdram, ctx);
        goto after_6;
    // 0x80800118: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_6:
    // 0x8080011C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800120:
    // 0x80800120: beql        $v1, $zero, L_80800168
    if (ctx->r3 == 0) {
        // 0x80800124: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80800168;
    }
    goto skip_0;
    // 0x80800124: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x80800128: jal         0x80104124
    // 0x8080012C: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    func_80104124(rdram, ctx);
        goto after_7;
    // 0x8080012C: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_7:
    // 0x80800130: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800134: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800138: jal         0x800EE7F8
    // 0x8080013C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x8080013C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_8:
    // 0x80800140: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80800144: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x80800148: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8080014C: lhu         $t2, 0x12($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X12);
    // 0x80800150: srl         $t3, $t2, 1
    ctx->r11 = S32(U32(ctx->r10) >> 1);
    // 0x80800154: jal         0x8001211C
    // 0x80800158: sw          $t3, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r11;
    func_8001211C(rdram, ctx);
        goto after_9;
    // 0x80800158: sw          $t3, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r11;
    after_9:
    // 0x8080015C: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80800160: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x80800164: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800168:
    // 0x80800168: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8080016C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80800170: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800174: jr          $ra
    // 0x80800178: nop

    return;
    // 0x80800178: nop

;}
RECOMP_FUNC void func_8080150C_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080150C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801510: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801514: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801518: jal         0x80800ECC
    // 0x8080151C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bstnt_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080151C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801520: jal         0x8008CABC
    // 0x80801524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_1;
    // 0x80801524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801528: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8080152C: jal         0x8008AF24
    // 0x80801530: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x80801530: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80801534: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801538: jal         0x8008B1A0
    // 0x8080153C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_3;
    // 0x8080153C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80801540: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801544: jal         0x8008AED4
    // 0x80801548: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
    anctrl_setIndex(rdram, ctx);
        goto after_4;
    // 0x80801548: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
    after_4:
    // 0x8080154C: lui         $a2, 0x3ECD
    ctx->r6 = S32(0X3ECD << 16);
    // 0x80801550: ori         $a2, $a2, 0x35A8
    ctx->r6 = ctx->r6 | 0X35A8;
    // 0x80801554: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801558: jal         0x8008B1D4
    // 0x8080155C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_5;
    // 0x8080155C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x80801560: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801564: jal         0x8008B1BC
    // 0x80801568: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_6;
    // 0x80801568: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_6:
    // 0x8080156C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801570: jal         0x8008B134
    // 0x80801574: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_7;
    // 0x80801574: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80801578: jal         0x8008B064
    // 0x8080157C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_start(rdram, ctx);
        goto after_8;
    // 0x8080157C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_8:
    // 0x80801580: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80801584: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080158C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801590: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80801594: jal         0x8009FFD8
    // 0x80801598: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_9;
    // 0x80801598: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_9:
    // 0x8080159C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015A0: lui         $a1, 0x4496
    ctx->r5 = S32(0X4496 << 16);
    // 0x808015A4: jal         0x8009C99C
    // 0x808015A8: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_10;
    // 0x808015A8: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_10:
    // 0x808015AC: jal         0x8009EF04
    // 0x808015B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_11;
    // 0x808015B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808015B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808015B8: nop

    // 0x808015BC: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x808015C0: nop

    // 0x808015C4: bc1t        L_808015E0
    if (c1cs) {
        // 0x808015C8: nop
    
            goto L_808015E0;
    }
    // 0x808015C8: nop

    // 0x808015CC: jal         0x8009EEB8
    // 0x808015D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_12;
    // 0x808015D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808015D4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808015D8: jal         0x8009C914
    // 0x808015DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_13;
    // 0x808015DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
L_808015E0:
    // 0x808015E0: jal         0x8009C990
    // 0x808015E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_14;
    // 0x808015E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808015E8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808015EC: jal         0x8009B9C0
    // 0x808015F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_15;
    // 0x808015F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808015F4: jal         0x80800164
    // 0x808015F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800164_bstnt(rdram, ctx);
        goto after_16;
    // 0x808015F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808015FC: jal         0x8009C990
    // 0x80801600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_17;
    // 0x80801600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80801604: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80801608: jal         0x8009BB00
    // 0x8080160C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_18;
    // 0x8080160C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80801610: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80801614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801618: jal         0x8009BA68
    // 0x8080161C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_19;
    // 0x8080161C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_19:
    // 0x80801620: lui         $a1, 0x442D
    ctx->r5 = S32(0X442D << 16);
    // 0x80801624: ori         $a1, $a1, 0x6000
    ctx->r5 = ctx->r5 | 0X6000;
    // 0x80801628: jal         0x8009BA58
    // 0x8080162C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_20;
    // 0x8080162C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80801630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801634: jal         0x8009BCB4
    // 0x80801638: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_21;
    // 0x80801638: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    after_21:
    // 0x8080163C: lui         $a1, 0x3FAC
    ctx->r5 = S32(0X3FAC << 16);
    // 0x80801640: lui         $a2, 0x3FB9
    ctx->r6 = S32(0X3FB9 << 16);
    // 0x80801644: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801648: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8080164C: jal         0x8009D7A4
    // 0x80801650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D7A4(rdram, ctx);
        goto after_22;
    // 0x80801650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80801654: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x80801658: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080165C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801660: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801664: jr          $ra
    // 0x80801668: nop

    return;
    // 0x80801668: nop

;}
RECOMP_FUNC void func_808000EC_chstatictorch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000F8: jal         0x80100094
    // 0x808000FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800100: beq         $v0, $zero, L_80800110
    if (ctx->r2 == 0) {
        // 0x80800104: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800110;
    }
    // 0x80800104: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800108: jal         0x80089930
    // 0x8080010C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suflamefx_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080010C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_80800110:
    // 0x80800110: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800114: lbu         $a0, 0x5F($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X5F);
    // 0x80800118: beql        $a0, $zero, L_80800134
    if (ctx->r4 == 0) {
        // 0x8080011C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800134;
    }
    goto skip_0;
    // 0x8080011C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800120: jal         0x800C2FDC
    // 0x80800124: nop

    func_800C2FDC(rdram, ctx);
        goto after_2;
    // 0x80800124: nop

    after_2:
    // 0x80800128: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8080012C: sb          $zero, 0x5F($t7)
    MEM_B(0X5F, ctx->r15) = 0;
    // 0x80800130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800134:
    // 0x80800134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800138: jr          $ra
    // 0x8080013C: nop

    return;
    // 0x8080013C: nop

;}
RECOMP_FUNC void func_80804318_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804318: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080431C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804320: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80804324: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80804328: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080432C: jal         0x800DF744
    // 0x80804330: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x80804330: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80804334: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80804338: jal         0x80101870
    // 0x8080433C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_1;
    // 0x8080433C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80804340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804344: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804348: jr          $ra
    // 0x8080434C: nop

    return;
    // 0x8080434C: nop

;}
RECOMP_FUNC void func_80106608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106608: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010660C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106610: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80106614: jal         0x800B2D28
    // 0x80106618: lw          $a0, 0x6EE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EE0);
    vector_free(rdram, ctx);
        goto after_0;
    // 0x80106618: lw          $a0, 0x6EE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EE0);
    after_0:
    // 0x8010661C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80106620: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80106624: sw          $zero, 0x6EE0($at)
    MEM_W(0X6EE0, ctx->r1) = 0;
    // 0x80106628: jr          $ra
    // 0x8010662C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010662C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8009AD04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009AD04: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009AD08: lw          $t6, 0xC0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC0);
    // 0x8009AD0C: jr          $ra
    // 0x8009AD10: swc1        $f12, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x8009AD10: swc1        $f12, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_800A32C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A32C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A32C8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800A32CC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800A32D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A32D4: jal         0x800EE7F8
    // 0x800A32D8: lw          $a1, 0xA0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XA0);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800A32D8: lw          $a1, 0xA0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XA0);
    after_0:
    // 0x800A32DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A32E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A32E4: jr          $ra
    // 0x800A32E8: nop

    return;
    // 0x800A32E8: nop

;}
RECOMP_FUNC void bstrexsmall_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004DC: jal         0x8009E77C
    // 0x808004E0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8009E77C(rdram, ctx);
        goto after_0;
    // 0x808004E0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x808004E4: bne         $v0, $zero, L_808005C8
    if (ctx->r2 != 0) {
        // 0x808004E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005C8;
    }
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004EC: sb          $zero, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = 0;
    // 0x808004F0: jal         0x808000C8
    // 0x808004F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808000C8_bstrexsmall(rdram, ctx);
        goto after_1;
    // 0x808004F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808004F8: jal         0x8009EFA8
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_pushZone(rdram, ctx);
        goto after_2;
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800500: lui         $a2, 0x3DF5
    ctx->r6 = S32(0X3DF5 << 16);
    // 0x80800504: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080050C: jal         0x8009F1C8
    // 0x80800510: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_3;
    // 0x80800510: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800514: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x80800518: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8080051C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800520: jal         0x8009F1C8
    // 0x80800524: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bastick_setZoneMax(rdram, ctx);
        goto after_4;
    // 0x80800524: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080052C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800530: jal         0x8009F1C8
    // 0x80800534: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_5;
    // 0x80800534: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_5:
    // 0x80800538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080053C: jal         0x80092864
    // 0x80800540: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    func_80092864(rdram, ctx);
        goto after_6;
    // 0x80800540: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    after_6:
    // 0x80800544: jal         0x8009E4AC
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E4AC(rdram, ctx);
        goto after_7;
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800550: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800554: jal         0x8009E55C
    // 0x80800558: lui         $a2, 0x428C
    ctx->r6 = S32(0X428C << 16);
    func_8009E55C(rdram, ctx);
        goto after_8;
    // 0x80800558: lui         $a2, 0x428C
    ctx->r6 = S32(0X428C << 16);
    after_8:
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800560: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800564: jal         0x8009E53C
    // 0x80800568: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009E53C(rdram, ctx);
        goto after_9;
    // 0x80800568: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_9:
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800570: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800574: jal         0x8009E55C
    // 0x80800578: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    func_8009E55C(rdram, ctx);
        goto after_10;
    // 0x80800578: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    after_10:
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800580: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800584: jal         0x8009E53C
    // 0x80800588: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009E53C(rdram, ctx);
        goto after_11;
    // 0x80800588: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_11:
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800590: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800594: jal         0x800959C8
    // 0x80800598: lui         $a2, 0x4260
    ctx->r6 = S32(0X4260 << 16);
    func_800959C8(rdram, ctx);
        goto after_12;
    // 0x80800598: lui         $a2, 0x4260
    ctx->r6 = S32(0X4260 << 16);
    after_12:
    // 0x8080059C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A0: jal         0x8009590C
    // 0x808005A4: lui         $a1, 0x42FA
    ctx->r5 = S32(0X42FA << 16);
    func_8009590C(rdram, ctx);
        goto after_13;
    // 0x808005A4: lui         $a1, 0x42FA
    ctx->r5 = S32(0X42FA << 16);
    after_13:
    // 0x808005A8: lui         $a1, 0xC53B
    ctx->r5 = S32(0XC53B << 16);
    // 0x808005AC: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x808005B0: jal         0x8009BCB4
    // 0x808005B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_gravity(rdram, ctx);
        goto after_14;
    // 0x808005B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808005B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808005C0: jal         0x800947EC
    // 0x808005C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_15;
    // 0x808005C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_15:
L_808005C8:
    // 0x808005C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808005D4: jr          $ra
    // 0x808005D8: nop

    return;
    // 0x808005D8: nop

;}
RECOMP_FUNC void _gcnewoption_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087CB0: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087CB0);
    return;
    // 0x80087CB4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800E24B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E24B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E24B8: jr          $ra
    // 0x800E24BC: sb          $a0, -0x2B71($at)
    MEM_B(-0X2B71, ctx->r1) = ctx->r4;
    return;
    // 0x800E24BC: sb          $a0, -0x2B71($at)
    MEM_B(-0X2B71, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_80800BC4_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BC4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800BC8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800BCC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800BD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800BD4: jal         0x8008CABC
    // 0x80800BD8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800BD8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800BDC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800BE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800BE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800BE8: beq         $a1, $zero, L_80800D88
    if (ctx->r5 == 0) {
        // 0x80800BEC: sb          $a1, 0x15C($s0)
        MEM_B(0X15C, ctx->r16) = ctx->r5;
            goto L_80800D88;
    }
    // 0x80800BEC: sb          $a1, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r5;
    // 0x80800BF0: beq         $a1, $at, L_80800C08
    if (ctx->r5 == ctx->r1) {
        // 0x80800BF4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800C08;
    }
    // 0x80800BF4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800BF8: beq         $a1, $at, L_80800D70
    if (ctx->r5 == ctx->r1) {
        // 0x80800BFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D70;
    }
    // 0x80800BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C00: b           L_80800D9C
    // 0x80800C04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800D9C;
    // 0x80800C04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800C08:
    // 0x80800C08: jal         0x8008AF24
    // 0x80800C0C: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80800C0C: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800C10: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800C14: jal         0x8008AED4
    // 0x80800C18: addiu       $a1, $zero, 0x1D1
    ctx->r5 = ADD32(0, 0X1D1);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x80800C18: addiu       $a1, $zero, 0x1D1
    ctx->r5 = ADD32(0, 0X1D1);
    after_2:
    // 0x80800C1C: lui         $a1, 0x400C
    ctx->r5 = S32(0X400C << 16);
    // 0x80800C20: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800C24: jal         0x8008B1BC
    // 0x80800C28: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_setDuration(rdram, ctx);
        goto after_3;
    // 0x80800C28: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x80800C2C: lui         $a2, 0x3F37
    ctx->r6 = S32(0X3F37 << 16);
    // 0x80800C30: ori         $a2, $a2, 0xA3D
    ctx->r6 = ctx->r6 | 0XA3D;
    // 0x80800C34: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800C38: jal         0x8008B1D4
    // 0x80800C3C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_4;
    // 0x80800C3C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800C40: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800C44: jal         0x8008B134
    // 0x80800C48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x80800C48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800C4C: lui         $a1, 0x3E46
    ctx->r5 = S32(0X3E46 << 16);
    // 0x80800C50: ori         $a1, $a1, 0xA7F0
    ctx->r5 = ctx->r5 | 0XA7F0;
    // 0x80800C54: jal         0x8008B24C
    // 0x80800C58: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_setStart(rdram, ctx);
        goto after_6;
    // 0x80800C58: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x80800C5C: jal         0x8008B064
    // 0x80800C60: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x80800C60: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x80800C64: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800C68: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800C74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800C78: jal         0x8009FFD8
    // 0x80800C7C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_8;
    // 0x80800C7C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_8:
    // 0x80800C80: jal         0x8009EF04
    // 0x80800C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_9;
    // 0x80800C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800C88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800C8C: nop

    // 0x80800C90: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800C94: nop

    // 0x80800C98: bc1t        L_80800CB4
    if (c1cs) {
        // 0x80800C9C: nop
    
            goto L_80800CB4;
    }
    // 0x80800C9C: nop

    // 0x80800CA0: jal         0x8009EEB8
    // 0x80800CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_10;
    // 0x80800CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800CA8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800CAC: jal         0x8009C914
    // 0x80800CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_11;
    // 0x80800CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
L_80800CB4:
    // 0x80800CB4: jal         0x8009C990
    // 0x80800CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_12;
    // 0x80800CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800CBC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800CC0: jal         0x8009B9C0
    // 0x80800CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_13;
    // 0x80800CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800CC8: jal         0x8009C990
    // 0x80800CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_14;
    // 0x80800CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800CD0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80800CD4: jal         0x8009BB00
    // 0x80800CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_15;
    // 0x80800CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800CDC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CE4: jal         0x8009BA68
    // 0x80800CE8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_16;
    // 0x80800CE8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_16:
    // 0x80800CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CF0: jal         0x8009BA58
    // 0x80800CF4: lui         $a1, 0x4461
    ctx->r5 = S32(0X4461 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_17;
    // 0x80800CF4: lui         $a1, 0x4461
    ctx->r5 = S32(0X4461 << 16);
    after_17:
    // 0x80800CF8: lui         $a1, 0xC4A8
    ctx->r5 = S32(0XC4A8 << 16);
    // 0x80800CFC: ori         $a1, $a1, 0xC000
    ctx->r5 = ctx->r5 | 0XC000;
    // 0x80800D00: jal         0x8009BCB4
    // 0x80800D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_gravity(rdram, ctx);
        goto after_18;
    // 0x80800D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800D08: jal         0x800DC0C0
    // 0x80800D0C: nop

    func_800DC0C0(rdram, ctx);
        goto after_19;
    // 0x80800D0C: nop

    after_19:
    // 0x80800D10: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800D14: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800D18: lui         $a3, 0x3F0C
    ctx->r7 = S32(0X3F0C << 16);
    // 0x80800D1C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800D20: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D28: addiu       $a1, $zero, 0x4D9
    ctx->r5 = ADD32(0, 0X4D9);
    // 0x80800D2C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80800D30: bc1f        L_80800D60
    if (!c1cs) {
        // 0x80800D34: addiu       $t8, $zero, 0x61A8
        ctx->r24 = ADD32(0, 0X61A8);
            goto L_80800D60;
    }
    // 0x80800D34: addiu       $t8, $zero, 0x61A8
    ctx->r24 = ADD32(0, 0X61A8);
    // 0x80800D38: lui         $a3, 0x3F0C
    ctx->r7 = S32(0X3F0C << 16);
    // 0x80800D3C: addiu       $t7, $zero, 0x61A8
    ctx->r15 = ADD32(0, 0X61A8);
    // 0x80800D40: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800D44: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D4C: addiu       $a1, $zero, 0x4D8
    ctx->r5 = ADD32(0, 0X4D8);
    // 0x80800D50: jal         0x8009DBB0
    // 0x80800D54: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_8009DBB0(rdram, ctx);
        goto after_20;
    // 0x80800D54: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_20:
    // 0x80800D58: b           L_80800D9C
    // 0x80800D5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800D9C;
    // 0x80800D5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D60:
    // 0x80800D60: jal         0x8009DBB0
    // 0x80800D64: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8009DBB0(rdram, ctx);
        goto after_21;
    // 0x80800D64: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_21:
    // 0x80800D68: b           L_80800D9C
    // 0x80800D6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800D9C;
    // 0x80800D6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D70:
    // 0x80800D70: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800D74: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800D78: jal         0x8008CF1C
    // 0x80800D7C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_22;
    // 0x80800D7C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_22:
    // 0x80800D80: b           L_80800D9C
    // 0x80800D84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800D9C;
    // 0x80800D84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D88:
    // 0x80800D88: lui         $a1, 0xC53B
    ctx->r5 = S32(0XC53B << 16);
    // 0x80800D8C: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80800D90: jal         0x8009BCB4
    // 0x80800D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_gravity(rdram, ctx);
        goto after_23;
    // 0x80800D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800D98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D9C:
    // 0x80800D9C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800DA0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800DA4: jr          $ra
    // 0x80800DA8: nop

    return;
    // 0x80800DA8: nop

;}
RECOMP_FUNC void cadbfunc_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E4C: jal         0x80800C9C
    // 0x80800E50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800C9C_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x80800E50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800E54: bne         $v0, $zero, L_80800E64
    if (ctx->r2 != 0) {
        // 0x80800E58: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800E64;
    }
    // 0x80800E58: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800E5C: b           L_80800E70
    // 0x80800E60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800E70;
    // 0x80800E60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800E64:
    // 0x80800E64: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800E68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800E6C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_80800E70:
    // 0x80800E70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E78: jr          $ra
    // 0x80800E7C: nop

    return;
    // 0x80800E7C: nop

;}
RECOMP_FUNC void _chplatuegrill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800877A0: syscall     623
    recomp_syscall_handler(rdram, ctx, 0x800877A0);
    return;
    // 0x800877A4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bsjig_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800831D0: syscall     51
    recomp_syscall_handler(rdram, ctx, 0x800831D0);
    return;
    // 0x800831D4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chfiregen_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800869B8: syscall     404
    recomp_syscall_handler(rdram, ctx, 0x800869B8);
    return;
    // 0x800869BC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800010_badust(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800010: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800014: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800018: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800020: jal         0x800852F0
    // 0x80800024: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    _batimer_decrement(rdram, ctx);
        goto after_0;
    // 0x80800024: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80800028: beq         $v0, $zero, L_8080004C
    if (ctx->r2 == 0) {
        // 0x8080002C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080004C;
    }
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800030: jal         0x800A2EEC
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A2EEC(rdram, ctx);
        goto after_1;
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800038: lui         $a2, 0x3DF5
    ctx->r6 = S32(0X3DF5 << 16);
    // 0x8080003C: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800044: jal         0x80085338
    // 0x80800048: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    _batimer_set(rdram, ctx);
        goto after_2;
    // 0x80800048: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
L_8080004C:
    // 0x8080004C: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x80800050: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800054: lbu         $t6, 0x9($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X9);
    // 0x80800058: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8080005C: bgez        $t7, L_80800070
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800060: andi        $t8, $t7, 0x1
        ctx->r24 = ctx->r15 & 0X1;
            goto L_80800070;
    }
    // 0x80800060: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80800064: beq         $t8, $zero, L_80800070
    if (ctx->r24 == 0) {
        // 0x80800068: nop
    
            goto L_80800070;
    }
    // 0x80800068: nop

    // 0x8080006C: addiu       $t8, $t8, -0x2
    ctx->r24 = ADD32(ctx->r24, -0X2);
L_80800070:
    // 0x80800070: sb          $t8, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r24;
    // 0x80800074: lw          $t9, 0x5C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X5C);
    // 0x80800078: lbu         $v1, 0x9($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X9);
    // 0x8080007C: beq         $v1, $zero, L_8080009C
    if (ctx->r3 == 0) {
        // 0x80800080: nop
    
            goto L_8080009C;
    }
    // 0x80800080: nop

    // 0x80800084: beq         $v1, $at, L_808000D8
    if (ctx->r3 == ctx->r1) {
        // 0x80800088: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000D8;
    }
    // 0x80800088: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080008C: beq         $v1, $at, L_80800114
    if (ctx->r3 == ctx->r1) {
        // 0x80800090: nop
    
            goto L_80800114;
    }
    // 0x80800090: nop

    // 0x80800094: b           L_8080014C
    // 0x80800098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080014C;
    // 0x80800098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080009C:
    // 0x8080009C: jal         0x8009BB18
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB18(rdram, ctx);
        goto after_3;
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000A4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808000A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000AC: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x808000B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000B4: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000BC: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x808000C0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x808000C4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808000C8: jal         0x80800424
    // 0x808000CC: nop

    badust_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x808000CC: nop

    after_4:
    // 0x808000D0: b           L_8080014C
    // 0x808000D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080014C;
    // 0x808000D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000D8:
    // 0x808000D8: jal         0x8009BB18
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB18(rdram, ctx);
        goto after_5;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000E0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808000E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808000E8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808000EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000F0: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F8: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x808000FC: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80800100: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800104: jal         0x80800424
    // 0x80800108: nop

    badust_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x80800108: nop

    after_6:
    // 0x8080010C: b           L_8080014C
    // 0x80800110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080014C;
    // 0x80800110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800114:
    // 0x80800114: jal         0x8009BB18
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB18(rdram, ctx);
        goto after_7;
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080011C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800120: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800124: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800128: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080012C: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800134: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x80800138: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8080013C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800140: jal         0x80800424
    // 0x80800144: nop

    badust_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80800144: nop

    after_8:
    // 0x80800148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080014C:
    // 0x8080014C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800150: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800154: jr          $ra
    // 0x80800158: nop

    return;
    // 0x80800158: nop

;}
RECOMP_FUNC void func_8010C9B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C9B0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010C9B4: addiu       $a2, $a2, 0x6F50
    ctx->r6 = ADD32(ctx->r6, 0X6F50);
    // 0x8010C9B8: lh          $t6, 0xE($a2)
    ctx->r14 = MEM_H(ctx->r6, 0XE);
    // 0x8010C9BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010C9C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010C9C4: bne         $t6, $zero, L_8010C9D4
    if (ctx->r14 != 0) {
        // 0x8010C9C8: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8010C9D4;
    }
    // 0x8010C9C8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8010C9CC: b           L_8010C9EC
    // 0x8010C9D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010C9EC;
    // 0x8010C9D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010C9D4:
    // 0x8010C9D4: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x8010C9D8: nop

    // 0x8010C9DC: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010C9E0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8010C9E4: jal         0x800EFFB4
    // 0x8010C9E8: nop

    func_800EFFB4(rdram, ctx);
        goto after_0;
    // 0x8010C9E8: nop

    after_0:
L_8010C9EC:
    // 0x8010C9EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010C9F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010C9F4: jr          $ra
    // 0x8010C9F8: nop

    return;
    // 0x8010C9F8: nop

;}
RECOMP_FUNC void func_800D2498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2498: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D249C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D24A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D24A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800D24A8: jal         0x800D21D0
    // 0x800D24AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800D21D0(rdram, ctx);
        goto after_0;
    // 0x800D24AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800D24B0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800D24B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D24B8: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800D24BC: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
    // 0x800D24C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D24C4: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x800D24C8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800D24CC: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
    // 0x800D24D0: jal         0x800D22E0
    // 0x800D24D4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800D22E0(rdram, ctx);
        goto after_1;
    // 0x800D24D4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800D24D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D24DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D24E0: jr          $ra
    // 0x800D24E4: nop

    return;
    // 0x800D24E4: nop

;}
RECOMP_FUNC void func_8080300C_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080300C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80803010: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80803014: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80803018: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x8080301C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803020: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x80803024: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x80803028: beq         $t6, $zero, L_80803050
    if (ctx->r14 == 0) {
        // 0x8080302C: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_80803050;
    }
    // 0x8080302C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80803030: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80803034: jal         0x800863E8
    // 0x80803038: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80803038: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x8080303C: lhu         $t9, 0x6E($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6E);
    // 0x80803040: andi        $t8, $v0, 0x1FF
    ctx->r24 = ctx->r2 & 0X1FF;
    // 0x80803044: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x80803048: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x8080304C: sh          $t1, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r9;
L_80803050:
    // 0x80803050: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1676, 0X44A8) << 16);
    // 0x80803054: addiu       $t2, $t2, 0x44A8
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1676, 0X44A8));
    // 0x80803058: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080305C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80803060: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80803064: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80803068: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080306C: jal         0x800BBCB8
    // 0x80803070: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x80803070: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_1:
    // 0x80803074: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1676, 0X4220) << 16);
    // 0x80803078: addiu       $a2, $a2, 0x4220
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1676, 0X4220));
    // 0x8080307C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803080: jal         0x80089D18
    // 0x80803084: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80803084: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80803088: jal         0x8010A570
    // 0x8080308C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_3;
    // 0x8080308C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80803090: jal         0x800FFAB0
    // 0x80803094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x80803094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80803098: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080309C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808030A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808030A4: jr          $ra
    // 0x808030A8: nop

    return;
    // 0x808030A8: nop

;}
RECOMP_FUNC void func_80094070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094070: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80094074: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80094078: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009407C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80094080: lw          $v1, 0x50($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X50);
    // 0x80094084: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80094088: lw          $t6, 0x10C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10C);
    // 0x8009408C: beql        $t6, $zero, L_800941B8
    if (ctx->r14 == 0) {
        // 0x80094090: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800941B8;
    }
    goto skip_0;
    // 0x80094090: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80094094: jal         0x800D90A4
    // 0x80094098: addiu       $a0, $v1, 0x114
    ctx->r4 = ADD32(ctx->r3, 0X114);
    func_800D90A4(rdram, ctx);
        goto after_0;
    // 0x80094098: addiu       $a0, $v1, 0x114
    ctx->r4 = ADD32(ctx->r3, 0X114);
    after_0:
    // 0x8009409C: beql        $v0, $zero, L_800941B8
    if (ctx->r2 == 0) {
        // 0x800940A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800941B8;
    }
    goto skip_1;
    // 0x800940A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800940A4: jal         0x800E3980
    // 0x800940A8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800E3980(rdram, ctx);
        goto after_1;
    // 0x800940A8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x800940AC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800940B0: jal         0x800EEAD4
    // 0x800940B4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800EEAD4(rdram, ctx);
        goto after_2;
    // 0x800940B4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x800940B8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800940BC: addiu       $v0, $v0, 0x7DD0
    ctx->r2 = ADD32(ctx->r2, 0X7DD0);
    // 0x800940C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800940C4:
    // 0x800940C4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800940C8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800940CC: nop

    // 0x800940D0: bc1tl       L_800940EC
    if (c1cs) {
        // 0x800940D4: addiu       $a0, $a1, -0x1
        ctx->r4 = ADD32(ctx->r5, -0X1);
            goto L_800940EC;
    }
    goto skip_2;
    // 0x800940D4: addiu       $a0, $a1, -0x1
    ctx->r4 = ADD32(ctx->r5, -0X1);
    skip_2:
    // 0x800940D8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800940DC: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x800940E0: bne         $at, $zero, L_800940C4
    if (ctx->r1 != 0) {
        // 0x800940E4: addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
            goto L_800940C4;
    }
    // 0x800940E4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800940E8: addiu       $a0, $a1, -0x1
    ctx->r4 = ADD32(ctx->r5, -0X1);
L_800940EC:
    // 0x800940EC: jal         0x80093F30
    // 0x800940F0: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_80093F30(rdram, ctx);
        goto after_3;
    // 0x800940F0: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_3:
    // 0x800940F4: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x800940F8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800940FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80094100: lw          $t7, 0x10C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X10C);
    // 0x80094104: beql        $v0, $t7, L_8009419C
    if (ctx->r2 == ctx->r15) {
        // 0x80094108: lw          $a0, 0x110($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X110);
            goto L_8009419C;
    }
    goto skip_3;
    // 0x80094108: lw          $a0, 0x110($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X110);
    skip_3:
    // 0x8009410C: jal         0x800942D0
    // 0x80094110: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_800942D0(rdram, ctx);
        goto after_4;
    // 0x80094110: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_4:
    // 0x80094114: beq         $v0, $zero, L_80094174
    if (ctx->r2 == 0) {
        // 0x80094118: lw          $a2, 0x28($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X28);
            goto L_80094174;
    }
    // 0x80094118: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8009411C: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x80094120: lw          $a0, 0x110($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X110);
    // 0x80094124: beql        $a0, $zero, L_80094148
    if (ctx->r4 == 0) {
        // 0x80094128: sw          $a2, 0x110($v1)
        MEM_W(0X110, ctx->r3) = ctx->r6;
            goto L_80094148;
    }
    goto skip_4;
    // 0x80094128: sw          $a2, 0x110($v1)
    MEM_W(0X110, ctx->r3) = ctx->r6;
    skip_4:
    // 0x8009412C: beql        $a2, $a0, L_80094148
    if (ctx->r6 == ctx->r4) {
        // 0x80094130: sw          $a2, 0x110($v1)
        MEM_W(0X110, ctx->r3) = ctx->r6;
            goto L_80094148;
    }
    goto skip_5;
    // 0x80094130: sw          $a2, 0x110($v1)
    MEM_W(0X110, ctx->r3) = ctx->r6;
    skip_5:
    // 0x80094134: jal         0x800E4BB8
    // 0x80094138: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800E4BB8(rdram, ctx);
        goto after_5;
    // 0x80094138: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_5:
    // 0x8009413C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80094140: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x80094144: sw          $a2, 0x110($v1)
    MEM_W(0X110, ctx->r3) = ctx->r6;
L_80094148:
    // 0x80094148: lw          $t8, 0x50($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X50);
    // 0x8009414C: jal         0x800E488C
    // 0x80094150: lw          $a0, 0x110($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X110);
    func_800E488C(rdram, ctx);
        goto after_6;
    // 0x80094150: lw          $a0, 0x110($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X110);
    after_6:
    // 0x80094154: beql        $v0, $zero, L_800941B8
    if (ctx->r2 == 0) {
        // 0x80094158: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800941B8;
    }
    goto skip_6;
    // 0x80094158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x8009415C: lw          $t9, 0x50($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X50);
    // 0x80094160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80094164: jal         0x800941C8
    // 0x80094168: lw          $a1, 0x110($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X110);
    func_800941C8(rdram, ctx);
        goto after_7;
    // 0x80094168: lw          $a1, 0x110($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X110);
    after_7:
    // 0x8009416C: b           L_800941B8
    // 0x80094170: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800941B8;
    // 0x80094170: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80094174:
    // 0x80094174: lw          $t0, 0x50($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X50);
    // 0x80094178: lw          $a0, 0x110($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X110);
    // 0x8009417C: beql        $a0, $zero, L_800941B8
    if (ctx->r4 == 0) {
        // 0x80094180: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800941B8;
    }
    goto skip_7;
    // 0x80094180: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x80094184: jal         0x800E4BB8
    // 0x80094188: nop

    func_800E4BB8(rdram, ctx);
        goto after_8;
    // 0x80094188: nop

    after_8:
    // 0x8009418C: lw          $t1, 0x50($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X50);
    // 0x80094190: b           L_800941B4
    // 0x80094194: sw          $zero, 0x110($t1)
    MEM_W(0X110, ctx->r9) = 0;
        goto L_800941B4;
    // 0x80094194: sw          $zero, 0x110($t1)
    MEM_W(0X110, ctx->r9) = 0;
    // 0x80094198: lw          $a0, 0x110($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X110);
L_8009419C:
    // 0x8009419C: beql        $a0, $zero, L_800941B8
    if (ctx->r4 == 0) {
        // 0x800941A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800941B8;
    }
    goto skip_8;
    // 0x800941A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x800941A4: jal         0x800E4BB8
    // 0x800941A8: nop

    func_800E4BB8(rdram, ctx);
        goto after_9;
    // 0x800941A8: nop

    after_9:
    // 0x800941AC: lw          $t2, 0x50($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X50);
    // 0x800941B0: sw          $zero, 0x110($t2)
    MEM_W(0X110, ctx->r10) = 0;
L_800941B4:
    // 0x800941B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800941B8:
    // 0x800941B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800941BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800941C0: jr          $ra
    // 0x800941C4: nop

    return;
    // 0x800941C4: nop

;}
RECOMP_FUNC void func_800C68E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C68E8: lbu         $t6, 0x9C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X9C);
    // 0x800C68EC: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800C68F0: beq         $t6, $zero, L_800C6904
    if (ctx->r14 == 0) {
        // 0x800C68F4: nop
    
            goto L_800C6904;
    }
    // 0x800C68F4: nop

    // 0x800C68F8: bne         $a1, $zero, L_800C6904
    if (ctx->r5 != 0) {
        // 0x800C68FC: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_800C6904;
    }
    // 0x800C68FC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C6900: sb          $t7, 0x93($a0)
    MEM_B(0X93, ctx->r4) = ctx->r15;
L_800C6904:
    // 0x800C6904: beq         $a1, $zero, L_800C6910
    if (ctx->r5 == 0) {
        // 0x800C6908: nop
    
            goto L_800C6910;
    }
    // 0x800C6908: nop

    // 0x800C690C: swc1        $f12, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->f12.u32l;
L_800C6910:
    // 0x800C6910: jr          $ra
    // 0x800C6914: sb          $a1, 0x9C($a0)
    MEM_B(0X9C, ctx->r4) = ctx->r5;
    return;
    // 0x800C6914: sb          $a1, 0x9C($a0)
    MEM_B(0X9C, ctx->r4) = ctx->r5;
    // 0x800C6918: nop

    // 0x800C691C: nop

;}
RECOMP_FUNC void func_8010C9FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C9FC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010CA00: addiu       $v0, $v0, 0x6F50
    ctx->r2 = ADD32(ctx->r2, 0X6F50);
    // 0x8010CA04: lh          $t6, 0xE($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE);
    // 0x8010CA08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010CA0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010CA10: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8010CA14: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8010CA18: bne         $t6, $zero, L_8010CA28
    if (ctx->r14 != 0) {
        // 0x8010CA1C: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_8010CA28;
    }
    // 0x8010CA1C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8010CA20: b           L_8010CA64
    // 0x8010CA24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010CA64;
    // 0x8010CA24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010CA28:
    // 0x8010CA28: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8010CA2C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8010CA30: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8010CA34: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8010CA38: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8010CA3C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8010CA40: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010CA44: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8010CA48: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010CA4C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8010CA50: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010CA54: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8010CA58: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8010CA5C: jal         0x800F00A4
    // 0x8010CA60: nop

    func_800F00A4(rdram, ctx);
        goto after_0;
    // 0x8010CA60: nop

    after_0:
L_8010CA64:
    // 0x8010CA64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010CA68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8010CA6C: jr          $ra
    // 0x8010CA70: nop

    return;
    // 0x8010CA70: nop

;}
RECOMP_FUNC void func_80800000_chgoldstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x80086C68
    // 0x80800010: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    _chmumbopad_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80800014: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x80800018: sra         $t6, $a3, 16
    ctx->r14 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8080001C: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x80800020: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800024: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800028: jal         0x80089840
    // 0x8080002C: addiu       $a2, $zero, 0x2D
    ctx->r6 = ADD32(0, 0X2D);
    _sumumbofx_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080002C: addiu       $a2, $zero, 0x2D
    ctx->r6 = ADD32(0, 0X2D);
    after_1:
    // 0x80800030: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800034: jal         0x80100094
    // 0x80800038: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800038: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8080003C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800040: jal         0x80089850
    // 0x80800044: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800044: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800048: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x8080004C: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800050: jal         0x80089900
    // 0x80800054: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _sumumbofx_entrypoint_24(rdram, ctx);
        goto after_4;
    // 0x80800054: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x80800058: jal         0x800DA298
    // 0x8080005C: addiu       $a0, $zero, 0x57C
    ctx->r4 = ADD32(0, 0X57C);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x8080005C: addiu       $a0, $zero, 0x57C
    ctx->r4 = ADD32(0, 0X57C);
    after_5:
    // 0x80800060: bne         $v0, $zero, L_8080007C
    if (ctx->r2 != 0) {
        // 0x80800064: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8080007C;
    }
    // 0x80800064: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800068: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080006C: jal         0x800898B8
    // 0x80800070: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_15(rdram, ctx);
        goto after_6;
    // 0x80800070: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_6:
    // 0x80800074: b           L_80800088
    // 0x80800078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800088;
    // 0x80800078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080007C:
    // 0x8080007C: jal         0x800898B8
    // 0x80800080: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    _sumumbofx_entrypoint_15(rdram, ctx);
        goto after_7;
    // 0x80800080: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_7:
    // 0x80800084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800088:
    // 0x80800088: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080008C: jr          $ra
    // 0x80800090: nop

    return;
    // 0x80800090: nop

;}
RECOMP_FUNC void func_80802574_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802574: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80802578: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080257C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80802580: jal         0x800D8FF8
    // 0x80802584: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80802584: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80802588: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    // 0x8080258C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802590: jal         0x80100094
    // 0x80802594: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80802594: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80802598: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x8080259C: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x808025A0: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x808025A4: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x808025A8: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x808025AC: bne         $at, $zero, L_80802730
    if (ctx->r1 != 0) {
        // 0x808025B0: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80802730;
    }
    // 0x808025B0: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x808025B4: lbu         $t7, 0x63($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X63);
    // 0x808025B8: bnel        $t7, $zero, L_80802734
    if (ctx->r15 != 0) {
        // 0x808025BC: addiu       $at, $zero, 0x17
        ctx->r1 = ADD32(0, 0X17);
            goto L_80802734;
    }
    goto skip_0;
    // 0x808025BC: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    skip_0:
    // 0x808025C0: jal         0x800F5A00
    // 0x808025C4: lw          $a0, 0x20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X20);
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x808025C4: lw          $a0, 0x20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X20);
    after_2:
    // 0x808025C8: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x808025CC: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x808025D0: jal         0x800F1EA4
    // 0x808025D4: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    func_800F1EA4(rdram, ctx);
        goto after_3;
    // 0x808025D4: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_3:
    // 0x808025D8: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x808025DC: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x808025E0: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x808025E4: lwc1        $f6, 0x18($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X18);
    // 0x808025E8: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x808025EC: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x808025F0: lbu         $t1, 0x61($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X61);
    // 0x808025F4: beql        $t1, $zero, L_80802650
    if (ctx->r9 == 0) {
        // 0x808025F8: lhu         $v1, 0x72($s0)
        ctx->r3 = MEM_HU(ctx->r16, 0X72);
            goto L_80802650;
    }
    goto skip_1;
    // 0x808025F8: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    skip_1:
    // 0x808025FC: jal         0x80090178
    // 0x80802600: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    func_80090178(rdram, ctx);
        goto after_4;
    // 0x80802600: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    after_4:
    // 0x80802604: beq         $v0, $zero, L_80802630
    if (ctx->r2 == 0) {
        // 0x80802608: lw          $t4, 0x78($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X78);
            goto L_80802630;
    }
    // 0x80802608: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x8080260C: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x80802610: lbu         $t3, 0x62($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X62);
    // 0x80802614: beql        $t3, $zero, L_80802650
    if (ctx->r11 == 0) {
        // 0x80802618: lhu         $v1, 0x72($s0)
        ctx->r3 = MEM_HU(ctx->r16, 0X72);
            goto L_80802650;
    }
    goto skip_2;
    // 0x80802618: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    skip_2:
    // 0x8080261C: sb          $zero, 0x62($t2)
    MEM_B(0X62, ctx->r10) = 0;
    // 0x80802620: jal         0x80800438
    // 0x80802624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800438_chdragonbrothers(rdram, ctx);
        goto after_5;
    // 0x80802624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80802628: b           L_80802650
    // 0x8080262C: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
        goto L_80802650;
    // 0x8080262C: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
L_80802630:
    // 0x80802630: lbu         $t5, 0x62($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X62);
    // 0x80802634: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80802638: bnel        $t5, $zero, L_80802650
    if (ctx->r13 != 0) {
        // 0x8080263C: lhu         $v1, 0x72($s0)
        ctx->r3 = MEM_HU(ctx->r16, 0X72);
            goto L_80802650;
    }
    goto skip_3;
    // 0x8080263C: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    skip_3:
    // 0x80802640: sb          $t6, 0x62($t4)
    MEM_B(0X62, ctx->r12) = ctx->r14;
    // 0x80802644: jal         0x808008C8
    // 0x80802648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008C8_chdragonbrothers(rdram, ctx);
        goto after_6;
    // 0x80802648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080264C: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
L_80802650:
    // 0x80802650: srl         $t7, $v1, 10
    ctx->r15 = S32(U32(ctx->r3) >> 10);
    // 0x80802654: addiu       $t8, $t7, -0x7
    ctx->r24 = ADD32(ctx->r15, -0X7);
    // 0x80802658: sltiu       $at, $t8, 0xC
    ctx->r1 = ctx->r24 < 0XC ? 1 : 0;
    // 0x8080265C: beq         $at, $zero, L_80802730
    if (ctx->r1 == 0) {
        // 0x80802660: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_80802730;
    }
    // 0x80802660: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80802664: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80802668: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X5248) << 16);
    // 0x8080266C: addu        $at, $at, $t8
    gpr jr_addend_80802674 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80802670: lw          $t8, 0x5248($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1852, 0X5248));
    // 0x80802674: jr          $t8
    // 0x80802678: nop

    switch (jr_addend_80802674 >> 2) {
        case 0: goto L_8080267C; break;
        case 1: goto L_8080267C; break;
        case 2: goto L_8080267C; break;
        case 3: goto L_8080267C; break;
        case 4: goto L_8080267C; break;
        case 5: goto L_8080267C; break;
        case 6: goto L_8080267C; break;
        case 7: goto L_8080267C; break;
        case 8: goto L_80802730; break;
        case 9: goto L_8080267C; break;
        case 10: goto L_8080267C; break;
        case 11: goto L_8080267C; break;
        default: switch_error(__func__, 0x80802674, 0x80805248);
    }
    // 0x80802678: nop

L_8080267C:
    // 0x8080267C: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x80802680: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80802684: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802688: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8080268C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80802690: nop

    // 0x80802694: bc1tl       L_808026D8
    if (c1cs) {
        // 0x80802698: lw          $t9, 0x78($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X78);
            goto L_808026D8;
    }
    goto skip_4;
    // 0x80802698: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    skip_4:
    // 0x8080269C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808026A0: nop

    // 0x808026A4: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x808026A8: nop

    // 0x808026AC: bc1fl       L_80802708
    if (!c1cs) {
        // 0x808026B0: lw          $t1, 0x78($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X78);
            goto L_80802708;
    }
    goto skip_5;
    // 0x808026B0: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    skip_5:
    // 0x808026B4: jal         0x800EF030
    // 0x808026B8: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    func_800EF030(rdram, ctx);
        goto after_7;
    // 0x808026B8: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    after_7:
    // 0x808026BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X5278) << 16);
    // 0x808026C0: lwc1        $f16, 0x5278($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X5278));
    // 0x808026C4: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x808026C8: nop

    // 0x808026CC: bc1fl       L_80802708
    if (!c1cs) {
        // 0x808026D0: lw          $t1, 0x78($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X78);
            goto L_80802708;
    }
    goto skip_6;
    // 0x808026D0: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    skip_6:
    // 0x808026D4: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
L_808026D8:
    // 0x808026D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808026DC: lbu         $t0, 0x61($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X61);
    // 0x808026E0: beql        $t0, $zero, L_80802728
    if (ctx->r8 == 0) {
        // 0x808026E4: lhu         $v1, 0x72($s0)
        ctx->r3 = MEM_HU(ctx->r16, 0X72);
            goto L_80802728;
    }
    goto skip_7;
    // 0x808026E4: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    skip_7:
    // 0x808026E8: jal         0x80800438
    // 0x808026EC: sb          $zero, 0x61($t9)
    MEM_B(0X61, ctx->r25) = 0;
    func_80800438_chdragonbrothers(rdram, ctx);
        goto after_8;
    // 0x808026EC: sb          $zero, 0x61($t9)
    MEM_B(0X61, ctx->r25) = 0;
    after_8:
    // 0x808026F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808026F4: jal         0x808004A4
    // 0x808026F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808004A4_chdragonbrothers(rdram, ctx);
        goto after_9;
    // 0x808026F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808026FC: b           L_80802728
    // 0x80802700: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
        goto L_80802728;
    // 0x80802700: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80802704: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
L_80802708:
    // 0x80802708: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8080270C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802710: lbu         $t3, 0x61($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X61);
    // 0x80802714: bnel        $t3, $zero, L_80802728
    if (ctx->r11 != 0) {
        // 0x80802718: lhu         $v1, 0x72($s0)
        ctx->r3 = MEM_HU(ctx->r16, 0X72);
            goto L_80802728;
    }
    goto skip_8;
    // 0x80802718: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    skip_8:
    // 0x8080271C: jal         0x808008C8
    // 0x80802720: sb          $t2, 0x61($t1)
    MEM_B(0X61, ctx->r9) = ctx->r10;
    func_808008C8_chdragonbrothers(rdram, ctx);
        goto after_10;
    // 0x80802720: sb          $t2, 0x61($t1)
    MEM_B(0X61, ctx->r9) = ctx->r10;
    after_10:
    // 0x80802724: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
L_80802728:
    // 0x80802728: srl         $t5, $v1, 10
    ctx->r13 = S32(U32(ctx->r3) >> 10);
    // 0x8080272C: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
L_80802730:
    // 0x80802730: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
L_80802734:
    // 0x80802734: bne         $v1, $at, L_8080278C
    if (ctx->r3 != ctx->r1) {
        // 0x80802738: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_8080278C;
    }
    // 0x80802738: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080273C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80802740: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80802744: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80802748: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x8080274C: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80802750: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80802754: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80802758: jal         0x800EFCD8
    // 0x8080275C: nop

    func_800EFCD8(rdram, ctx);
        goto after_11;
    // 0x8080275C: nop

    after_11:
    // 0x80802760: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80802764: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802768: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8080276C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80802770: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80802774: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80802778: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x8080277C: jal         0x800EF04C
    // 0x80802780: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
    func_800EF04C(rdram, ctx);
        goto after_12;
    // 0x80802780: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
    after_12:
    // 0x80802784: b           L_808027B0
    // 0x80802788: lbu         $t6, 0x7A($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X7A);
        goto L_808027B0;
    // 0x80802788: lbu         $t6, 0x7A($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X7A);
L_8080278C:
    // 0x8080278C: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80802790: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80802794: jal         0x800EEB9C
    // 0x80802798: lui         $a2, 0x437A
    ctx->r6 = S32(0X437A << 16);
    func_800EEB9C(rdram, ctx);
        goto after_13;
    // 0x80802798: lui         $a2, 0x437A
    ctx->r6 = S32(0X437A << 16);
    after_13:
    // 0x8080279C: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x808027A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808027A4: nop

    // 0x808027A8: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x808027AC: lbu         $t6, 0x7A($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X7A);
L_808027B0:
    // 0x808027B0: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x808027B4: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x808027B8: andi        $t4, $t6, 0x1
    ctx->r12 = ctx->r14 & 0X1;
    // 0x808027BC: beql        $t4, $zero, L_80802810
    if (ctx->r12 == 0) {
        // 0x808027C0: lbu         $t2, 0x5C($t3)
        ctx->r10 = MEM_BU(ctx->r11, 0X5C);
            goto L_80802810;
    }
    goto skip_9;
    // 0x808027C0: lbu         $t2, 0x5C($t3)
    ctx->r10 = MEM_BU(ctx->r11, 0X5C);
    skip_9:
    // 0x808027C4: lbu         $t8, 0x5C($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X5C);
    // 0x808027C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808027CC: bnel        $t8, $at, L_80802850
    if (ctx->r24 != ctx->r1) {
        // 0x808027D0: lhu         $t6, 0x72($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X72);
            goto L_80802850;
    }
    goto skip_10;
    // 0x808027D0: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    skip_10:
    // 0x808027D4: jal         0x800DA298
    // 0x808027D8: addiu       $a0, $zero, 0x406
    ctx->r4 = ADD32(0, 0X406);
    func_800DA298(rdram, ctx);
        goto after_14;
    // 0x808027D8: addiu       $a0, $zero, 0x406
    ctx->r4 = ADD32(0, 0X406);
    after_14:
    // 0x808027DC: bne         $v0, $zero, L_8080284C
    if (ctx->r2 != 0) {
        // 0x808027E0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8080284C;
    }
    // 0x808027E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808027E4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x808027E8: jal         0x80800B9C
    // 0x808027EC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_80800B9C_chdragonbrothers(rdram, ctx);
        goto after_15;
    // 0x808027EC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_15:
    // 0x808027F0: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x808027F4: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x808027F8: addiu       $a0, $zero, 0x129E
    ctx->r4 = ADD32(0, 0X129E);
    // 0x808027FC: jal         0x800C067C
    // 0x80802800: sb          $t0, 0x5C($t9)
    MEM_B(0X5C, ctx->r25) = ctx->r8;
    func_800C067C(rdram, ctx);
        goto after_16;
    // 0x80802800: sb          $t0, 0x5C($t9)
    MEM_B(0X5C, ctx->r25) = ctx->r8;
    after_16:
    // 0x80802804: b           L_80802850
    // 0x80802808: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
        goto L_80802850;
    // 0x80802808: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x8080280C: lbu         $t2, 0x5C($t3)
    ctx->r10 = MEM_BU(ctx->r11, 0X5C);
L_80802810:
    // 0x80802810: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80802814: bnel        $t2, $at, L_80802850
    if (ctx->r10 != ctx->r1) {
        // 0x80802818: lhu         $t6, 0x72($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X72);
            goto L_80802850;
    }
    goto skip_11;
    // 0x80802818: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    skip_11:
    // 0x8080281C: jal         0x800DA298
    // 0x80802820: addiu       $a0, $zero, 0x407
    ctx->r4 = ADD32(0, 0X407);
    func_800DA298(rdram, ctx);
        goto after_17;
    // 0x80802820: addiu       $a0, $zero, 0x407
    ctx->r4 = ADD32(0, 0X407);
    after_17:
    // 0x80802824: bne         $v0, $zero, L_8080284C
    if (ctx->r2 != 0) {
        // 0x80802828: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8080284C;
    }
    // 0x80802828: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080282C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80802830: jal         0x80800B9C
    // 0x80802834: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_80800B9C_chdragonbrothers(rdram, ctx);
        goto after_18;
    // 0x80802834: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_18:
    // 0x80802838: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x8080283C: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80802840: addiu       $a0, $zero, 0x129F
    ctx->r4 = ADD32(0, 0X129F);
    // 0x80802844: jal         0x800C067C
    // 0x80802848: sb          $t1, 0x5C($t5)
    MEM_B(0X5C, ctx->r13) = ctx->r9;
    func_800C067C(rdram, ctx);
        goto after_19;
    // 0x80802848: sb          $t1, 0x5C($t5)
    MEM_B(0X5C, ctx->r13) = ctx->r9;
    after_19:
L_8080284C:
    // 0x8080284C: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
L_80802850:
    // 0x80802850: srl         $t4, $t6, 10
    ctx->r12 = S32(U32(ctx->r14) >> 10);
    // 0x80802854: addiu       $t7, $t4, -0x3
    ctx->r15 = ADD32(ctx->r12, -0X3);
    // 0x80802858: sltiu       $at, $t7, 0x15
    ctx->r1 = ctx->r15 < 0X15 ? 1 : 0;
    // 0x8080285C: beq         $at, $zero, L_80803440
    if (ctx->r1 == 0) {
        // 0x80802860: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80803440;
    }
    // 0x80802860: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80802864: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X527C) << 16);
    // 0x80802868: addu        $at, $at, $t7
    gpr jr_addend_80802870 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8080286C: lw          $t7, 0x527C($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1852, 0X527C));
    // 0x80802870: jr          $t7
    // 0x80802874: nop

    switch (jr_addend_80802870 >> 2) {
        case 0: goto L_80802878; break;
        case 1: goto L_8080290C; break;
        case 2: goto L_80802974; break;
        case 3: goto L_808029AC; break;
        case 4: goto L_80802A10; break;
        case 5: goto L_80802A58; break;
        case 6: goto L_80802B3C; break;
        case 7: goto L_80802BA8; break;
        case 8: goto L_80802C10; break;
        case 9: goto L_80802C10; break;
        case 10: goto L_80802C90; break;
        case 11: goto L_80802DD4; break;
        case 12: goto L_80802E48; break;
        case 13: goto L_80802E58; break;
        case 14: goto L_80802E80; break;
        case 15: goto L_8080321C; break;
        case 16: goto L_8080325C; break;
        case 17: goto L_80803344; break;
        case 18: goto L_80803440; break;
        case 19: goto L_80803364; break;
        case 20: goto L_808033C0; break;
        default: switch_error(__func__, 0x80802870, 0x8080527C);
    }
    // 0x80802874: nop

L_80802878:
    // 0x80802878: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x8080287C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80802880: addiu       $a1, $zero, 0x8FC
    ctx->r5 = ADD32(0, 0X8FC);
    // 0x80802884: lw          $a0, 0x10($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X10);
    // 0x80802888: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8080288C: addiu       $a3, $zero, -0xA
    ctx->r7 = ADD32(0, -0XA);
    // 0x80802890: beq         $a0, $at, L_808028A8
    if (ctx->r4 == ctx->r1) {
        // 0x80802894: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_808028A8;
    }
    // 0x80802894: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80802898: beq         $a0, $at, L_808028DC
    if (ctx->r4 == ctx->r1) {
        // 0x8080289C: lw          $t0, 0x78($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X78);
            goto L_808028DC;
    }
    // 0x8080289C: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x808028A0: b           L_80803444
    // 0x808028A4: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x808028A4: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_808028A8:
    // 0x808028A8: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1852, 0X5650) << 16);
    // 0x808028AC: jal         0x8010CB0C
    // 0x808028B0: addiu       $a0, $a0, 0x5650
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1852, 0X5650));
    func_8010CB0C(rdram, ctx);
        goto after_20;
    // 0x808028B0: addiu       $a0, $a0, 0x5650
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1852, 0X5650));
    after_20:
    // 0x808028B4: beq         $v0, $zero, L_80803440
    if (ctx->r2 == 0) {
        // 0x808028B8: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80803440;
    }
    // 0x808028B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808028BC: jal         0x8008FA2C
    // 0x808028C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008FA2C(rdram, ctx);
        goto after_21;
    // 0x808028C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x808028C4: beq         $v0, $zero, L_80803440
    if (ctx->r2 == 0) {
        // 0x808028C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803440;
    }
    // 0x808028C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808028CC: jal         0x80800D98
    // 0x808028D0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800D98_chdragonbrothers(rdram, ctx);
        goto after_22;
    // 0x808028D0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_22:
    // 0x808028D4: b           L_80803444
    // 0x808028D8: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x808028D8: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_808028DC:
    // 0x808028DC: lbu         $t9, 0x58($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X58);
    // 0x808028E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808028E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808028E8: bnel        $t9, $at, L_80803444
    if (ctx->r25 != ctx->r1) {
        // 0x808028EC: lw          $t3, 0x78($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X78);
            goto L_80803444;
    }
    goto skip_12;
    // 0x808028EC: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    skip_12:
    // 0x808028F0: jal         0x80800D98
    // 0x808028F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800D98_chdragonbrothers(rdram, ctx);
        goto after_23;
    // 0x808028F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x808028F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808028FC: jal         0x808012B4
    // 0x80802900: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_24;
    // 0x80802900: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_24:
    // 0x80802904: b           L_80803444
    // 0x80802908: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x80802908: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_8080290C:
    // 0x8080290C: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80802910: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80802914: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1852, 0X565C) << 16);
    // 0x80802918: lw          $t2, 0x10($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X10);
    // 0x8080291C: addiu       $a0, $a0, 0x565C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1852, 0X565C));
    // 0x80802920: addiu       $a1, $zero, 0x8FC
    ctx->r5 = ADD32(0, 0X8FC);
    // 0x80802924: bne         $t2, $at, L_80803440
    if (ctx->r10 != ctx->r1) {
        // 0x80802928: addiu       $a2, $zero, 0xA
        ctx->r6 = ADD32(0, 0XA);
            goto L_80803440;
    }
    // 0x80802928: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8080292C: jal         0x8010CB0C
    // 0x80802930: addiu       $a3, $zero, -0xA
    ctx->r7 = ADD32(0, -0XA);
    func_8010CB0C(rdram, ctx);
        goto after_25;
    // 0x80802930: addiu       $a3, $zero, -0xA
    ctx->r7 = ADD32(0, -0XA);
    after_25:
    // 0x80802934: beq         $v0, $zero, L_80803440
    if (ctx->r2 == 0) {
        // 0x80802938: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80803440;
    }
    // 0x80802938: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8080293C: jal         0x8008FA2C
    // 0x80802940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008FA2C(rdram, ctx);
        goto after_26;
    // 0x80802940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x80802944: beq         $v0, $zero, L_80803440
    if (ctx->r2 == 0) {
        // 0x80802948: addiu       $t1, $zero, 0x3
        ctx->r9 = ADD32(0, 0X3);
            goto L_80803440;
    }
    // 0x80802948: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8080294C: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x80802950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802954: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802958: jal         0x80800D98
    // 0x8080295C: sb          $t1, 0x58($t5)
    MEM_B(0X58, ctx->r13) = ctx->r9;
    func_80800D98_chdragonbrothers(rdram, ctx);
        goto after_27;
    // 0x8080295C: sb          $t1, 0x58($t5)
    MEM_B(0X58, ctx->r13) = ctx->r9;
    after_27:
    // 0x80802960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802964: jal         0x808012B4
    // 0x80802968: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_28;
    // 0x80802968: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_28:
    // 0x8080296C: b           L_80803444
    // 0x80802970: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x80802970: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_80802974:
    // 0x80802974: jal         0x80101DDC
    // 0x80802978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_29;
    // 0x80802978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x8080297C: beq         $v0, $zero, L_80802998
    if (ctx->r2 == 0) {
        // 0x80802980: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802998;
    }
    // 0x80802980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802984: jal         0x80800D98
    // 0x80802988: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800D98_chdragonbrothers(rdram, ctx);
        goto after_30;
    // 0x80802988: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x8080298C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802990: jal         0x808012B4
    // 0x80802994: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_31;
    // 0x80802994: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_31:
L_80802998:
    // 0x80802998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080299C: jal         0x80801C44
    // 0x808029A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801C44_chdragonbrothers(rdram, ctx);
        goto after_32;
    // 0x808029A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_32:
    // 0x808029A4: b           L_80803444
    // 0x808029A8: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x808029A8: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_808029AC:
    // 0x808029AC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1852, 0X5668) << 16);
    // 0x808029B0: addiu       $a1, $a1, 0x5668
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1852, 0X5668));
    // 0x808029B4: jal         0x80101E4C
    // 0x808029B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E4C(rdram, ctx);
        goto after_33;
    // 0x808029B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x808029BC: beql        $v0, $zero, L_80803444
    if (ctx->r2 == 0) {
        // 0x808029C0: lw          $t3, 0x78($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X78);
            goto L_80803444;
    }
    goto skip_13;
    // 0x808029C0: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    skip_13:
    // 0x808029C4: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x808029C8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808029CC: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x808029D0: sll         $t7, $t6, 19
    ctx->r15 = S32(ctx->r14 << 19);
    // 0x808029D4: bgez        $t7, L_808029EC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808029D8: addiu       $a0, $sp, 0x54
        ctx->r4 = ADD32(ctx->r29, 0X54);
            goto L_808029EC;
    }
    // 0x808029D8: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x808029DC: jal         0x8008A0E0
    // 0x808029E0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_34;
    // 0x808029E0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_34:
    // 0x808029E4: b           L_808029F4
    // 0x808029E8: nop

        goto L_808029F4;
    // 0x808029E8: nop

L_808029EC:
    // 0x808029EC: jal         0x800EE7F8
    // 0x808029F0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_35;
    // 0x808029F0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_35:
L_808029F4:
    // 0x808029F4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1852, 0X53C8) << 16);
    // 0x808029F8: addiu       $a2, $a2, 0x53C8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1852, 0X53C8));
    // 0x808029FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802A00: jal         0x80089D18
    // 0x80802A04: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_36;
    // 0x80802A04: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_36:
    // 0x80802A08: b           L_80803444
    // 0x80802A0C: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x80802A0C: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_80802A10:
    // 0x80802A10: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80802A14: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80802A18: jal         0x800F2094
    // 0x80802A1C: lwc1        $f14, 0x18($t8)
    ctx->f14.u32l = MEM_W(ctx->r24, 0X18);
    func_800F2094(rdram, ctx);
        goto after_37;
    // 0x80802A1C: lwc1        $f14, 0x18($t8)
    ctx->f14.u32l = MEM_W(ctx->r24, 0X18);
    after_37:
    // 0x80802A20: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80802A24: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802A28: nop

    // 0x80802A2C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80802A30: nop

    // 0x80802A34: bc1fl       L_80802A48
    if (!c1cs) {
        // 0x80802A38: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802A48;
    }
    goto skip_14;
    // 0x80802A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_14:
    // 0x80802A3C: jal         0x8080183C
    // 0x80802A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080183C_chdragonbrothers(rdram, ctx);
        goto after_38;
    // 0x80802A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x80802A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802A48:
    // 0x80802A48: jal         0x80801C44
    // 0x80802A4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801C44_chdragonbrothers(rdram, ctx);
        goto after_39;
    // 0x80802A4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_39:
    // 0x80802A50: b           L_80803444
    // 0x80802A54: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x80802A54: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_80802A58:
    // 0x80802A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802A5C: jal         0x80801C44
    // 0x80802A60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801C44_chdragonbrothers(rdram, ctx);
        goto after_40;
    // 0x80802A60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_40:
    // 0x80802A64: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80802A68: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80802A6C: jal         0x80101E14
    // 0x80802A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_41;
    // 0x80802A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x80802A74: beq         $v0, $zero, L_80802A98
    if (ctx->r2 == 0) {
        // 0x80802A78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802A98;
    }
    // 0x80802A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802A7C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1852, 0X53E0) << 16);
    // 0x80802A80: addiu       $a2, $a2, 0x53E0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1852, 0X53E0));
    // 0x80802A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802A88: jal         0x80089D18
    // 0x80802A8C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_42;
    // 0x80802A8C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_42:
    // 0x80802A90: b           L_80803444
    // 0x80802A94: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x80802A94: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_80802A98:
    // 0x80802A98: jal         0x80101E14
    // 0x80802A9C: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    func_80101E14(rdram, ctx);
        goto after_43;
    // 0x80802A9C: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_43:
    // 0x80802AA0: beq         $v0, $zero, L_80802AB8
    if (ctx->r2 == 0) {
        // 0x80802AA4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802AB8;
    }
    // 0x80802AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802AA8: jal         0x80108B04
    // 0x80802AAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_44;
    // 0x80802AAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_44:
    // 0x80802AB0: b           L_80803444
    // 0x80802AB4: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x80802AB4: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_80802AB8:
    // 0x80802AB8: jal         0x80101DDC
    // 0x80802ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_45;
    // 0x80802ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x80802AC0: beql        $v0, $zero, L_80803444
    if (ctx->r2 == 0) {
        // 0x80802AC4: lw          $t3, 0x78($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X78);
            goto L_80803444;
    }
    goto skip_15;
    // 0x80802AC4: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    skip_15:
    // 0x80802AC8: lbu         $t0, 0x79($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X79);
    // 0x80802ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802AD0: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80802AD4: srl         $t9, $t0, 4
    ctx->r25 = S32(U32(ctx->r8) >> 4);
    // 0x80802AD8: blezl       $t9, L_80802AF4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80802ADC: lbu         $t2, 0x5D($t3)
        ctx->r10 = MEM_BU(ctx->r11, 0X5D);
            goto L_80802AF4;
    }
    goto skip_16;
    // 0x80802ADC: lbu         $t2, 0x5D($t3)
    ctx->r10 = MEM_BU(ctx->r11, 0X5D);
    skip_16:
    // 0x80802AE0: jal         0x808012B4
    // 0x80802AE4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_46;
    // 0x80802AE4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_46:
    // 0x80802AE8: b           L_80803444
    // 0x80802AEC: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x80802AEC: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80802AF0: lbu         $t2, 0x5D($t3)
    ctx->r10 = MEM_BU(ctx->r11, 0X5D);
L_80802AF4:
    // 0x80802AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802AF8: beq         $t2, $zero, L_80802B2C
    if (ctx->r10 == 0) {
        // 0x80802AFC: nop
    
            goto L_80802B2C;
    }
    // 0x80802AFC: nop

    // 0x80802B00: lb          $t1, 0x5E($t3)
    ctx->r9 = MEM_B(ctx->r11, 0X5E);
    // 0x80802B04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80802B08: bne         $t1, $at, L_80802B2C
    if (ctx->r9 != ctx->r1) {
        // 0x80802B0C: nop
    
            goto L_80802B2C;
    }
    // 0x80802B0C: nop

    // 0x80802B10: lbu         $t5, 0x61($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X61);
    // 0x80802B14: beq         $t5, $zero, L_80802B2C
    if (ctx->r13 == 0) {
        // 0x80802B18: nop
    
            goto L_80802B2C;
    }
    // 0x80802B18: nop

    // 0x80802B1C: jal         0x808018BC
    // 0x80802B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808018BC_chdragonbrothers(rdram, ctx);
        goto after_47;
    // 0x80802B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x80802B24: b           L_80803444
    // 0x80802B28: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x80802B28: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_80802B2C:
    // 0x80802B2C: jal         0x808012B4
    // 0x80802B30: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_48;
    // 0x80802B30: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_48:
    // 0x80802B34: b           L_80803444
    // 0x80802B38: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x80802B38: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_80802B3C:
    // 0x80802B3C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80802B40: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80802B44: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80802B48: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80802B4C: nop

    // 0x80802B50: bc1fl       L_80802B74
    if (!c1cs) {
        // 0x80802B54: lbu         $t4, 0x61($t6)
        ctx->r12 = MEM_BU(ctx->r14, 0X61);
            goto L_80802B74;
    }
    goto skip_17;
    // 0x80802B54: lbu         $t4, 0x61($t6)
    ctx->r12 = MEM_BU(ctx->r14, 0X61);
    skip_17:
    // 0x80802B58: jal         0x800D8FF8
    // 0x80802B5C: nop

    func_800D8FF8(rdram, ctx);
        goto after_49;
    // 0x80802B5C: nop

    after_49:
    // 0x80802B60: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80802B64: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80802B68: b           L_80802B94
    // 0x80802B6C: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
        goto L_80802B94;
    // 0x80802B6C: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x80802B70: lbu         $t4, 0x61($t6)
    ctx->r12 = MEM_BU(ctx->r14, 0X61);
L_80802B74:
    // 0x80802B74: beql        $t4, $zero, L_80802B98
    if (ctx->r12 == 0) {
        // 0x80802B78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802B98;
    }
    goto skip_18;
    // 0x80802B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_18:
    // 0x80802B7C: lbu         $t7, 0x63($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X63);
    // 0x80802B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802B84: bnel        $t7, $zero, L_80802B98
    if (ctx->r15 != 0) {
        // 0x80802B88: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802B98;
    }
    goto skip_19;
    // 0x80802B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_19:
    // 0x80802B8C: jal         0x808012B4
    // 0x80802B90: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_50;
    // 0x80802B90: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_50:
L_80802B94:
    // 0x80802B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802B98:
    // 0x80802B98: jal         0x80801C44
    // 0x80802B9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801C44_chdragonbrothers(rdram, ctx);
        goto after_51;
    // 0x80802B9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_51:
    // 0x80802BA0: b           L_80803444
    // 0x80802BA4: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x80802BA4: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_80802BA8:
    // 0x80802BA8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80802BAC: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80802BB0: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80802BB4: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80802BB8: nop

    // 0x80802BBC: bc1fl       L_80802BE0
    if (!c1cs) {
        // 0x80802BC0: lbu         $t0, 0x61($t8)
        ctx->r8 = MEM_BU(ctx->r24, 0X61);
            goto L_80802BE0;
    }
    goto skip_20;
    // 0x80802BC0: lbu         $t0, 0x61($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X61);
    skip_20:
    // 0x80802BC4: jal         0x800D8FF8
    // 0x80802BC8: nop

    func_800D8FF8(rdram, ctx);
        goto after_52;
    // 0x80802BC8: nop

    after_52:
    // 0x80802BCC: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80802BD0: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80802BD4: b           L_80802BFC
    // 0x80802BD8: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
        goto L_80802BFC;
    // 0x80802BD8: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x80802BDC: lbu         $t0, 0x61($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X61);
L_80802BE0:
    // 0x80802BE0: beql        $t0, $zero, L_80802C00
    if (ctx->r8 == 0) {
        // 0x80802BE4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802C00;
    }
    goto skip_21;
    // 0x80802BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_21:
    // 0x80802BE8: lbu         $t9, 0x63($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X63);
    // 0x80802BEC: bnel        $t9, $zero, L_80802C00
    if (ctx->r25 != 0) {
        // 0x80802BF0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802C00;
    }
    goto skip_22;
    // 0x80802BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_22:
    // 0x80802BF4: jal         0x8080183C
    // 0x80802BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080183C_chdragonbrothers(rdram, ctx);
        goto after_53;
    // 0x80802BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_53:
L_80802BFC:
    // 0x80802BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802C00:
    // 0x80802C00: jal         0x80801C44
    // 0x80802C04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801C44_chdragonbrothers(rdram, ctx);
        goto after_54;
    // 0x80802C04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_54:
    // 0x80802C08: b           L_80803444
    // 0x80802C0C: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x80802C0C: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_80802C10:
    // 0x80802C10: jal         0x80101DDC
    // 0x80802C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_55;
    // 0x80802C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_55:
    // 0x80802C18: beq         $v0, $zero, L_80802C48
    if (ctx->r2 == 0) {
        // 0x80802C1C: lw          $t2, 0x78($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X78);
            goto L_80802C48;
    }
    // 0x80802C1C: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x80802C20: lw          $t1, 0x10($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X10);
    // 0x80802C24: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80802C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802C2C: bnel        $t1, $at, L_80802C40
    if (ctx->r9 != ctx->r1) {
        // 0x80802C30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802C40;
    }
    goto skip_23;
    // 0x80802C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_23:
    // 0x80802C34: jal         0x80800D98
    // 0x80802C38: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_80800D98_chdragonbrothers(rdram, ctx);
        goto after_56;
    // 0x80802C38: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_56:
    // 0x80802C3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802C40:
    // 0x80802C40: jal         0x808012B4
    // 0x80802C44: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_57;
    // 0x80802C44: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_57:
L_80802C48:
    // 0x80802C48: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80802C4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802C50: lw          $t5, 0x10($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X10);
    // 0x80802C54: bne         $t5, $zero, L_80802C80
    if (ctx->r13 != 0) {
        // 0x80802C58: nop
    
            goto L_80802C80;
    }
    // 0x80802C58: nop

    // 0x80802C5C: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80802C60: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80802C64: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80802C68: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80802C6C: nop

    // 0x80802C70: bc1f        L_80802C80
    if (!c1cs) {
        // 0x80802C74: nop
    
            goto L_80802C80;
    }
    // 0x80802C74: nop

    // 0x80802C78: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80802C7C: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
L_80802C80:
    // 0x80802C80: jal         0x80801C44
    // 0x80802C84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801C44_chdragonbrothers(rdram, ctx);
        goto after_58;
    // 0x80802C84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_58:
    // 0x80802C88: b           L_80803444
    // 0x80802C8C: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x80802C8C: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_80802C90:
    // 0x80802C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802C94: jal         0x80801C44
    // 0x80802C98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801C44_chdragonbrothers(rdram, ctx);
        goto after_59;
    // 0x80802C98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_59:
    // 0x80802C9C: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x80802CA0: lw          $t6, 0x10($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X10);
    // 0x80802CA4: bnel        $t6, $zero, L_80803444
    if (ctx->r14 != 0) {
        // 0x80802CA8: lw          $t3, 0x78($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X78);
            goto L_80803444;
    }
    goto skip_24;
    // 0x80802CA8: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    skip_24:
    // 0x80802CAC: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x80802CB0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80802CB4: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x80802CB8: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80802CBC: bgez        $t8, L_80802CCC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80802CC0: nop
    
            goto L_80802CCC;
    }
    // 0x80802CC0: nop

    // 0x80802CC4: b           L_80802CCC
    // 0x80802CC8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80802CCC;
    // 0x80802CC8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80802CCC:
    // 0x80802CCC: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
    // 0x80802CD0: andi        $t2, $t9, 0x1FF
    ctx->r10 = ctx->r25 & 0X1FF;
    // 0x80802CD4: sltu        $at, $t2, $v0
    ctx->r1 = ctx->r10 < ctx->r2 ? 1 : 0;
    // 0x80802CD8: beq         $at, $zero, L_80802CF0
    if (ctx->r1 == 0) {
        // 0x80802CDC: nop
    
            goto L_80802CF0;
    }
    // 0x80802CDC: nop

    // 0x80802CE0: lw          $t3, 0x14($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X14);
    // 0x80802CE4: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80802CE8: bnel        $at, $zero, L_80802D40
    if (ctx->r1 != 0) {
        // 0x80802CEC: lwc1        $f0, 0x58($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
            goto L_80802D40;
    }
    goto skip_25;
    // 0x80802CEC: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    skip_25:
L_80802CF0:
    // 0x80802CF0: jal         0x80802534
    // 0x80802CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802534_chdragonbrothers(rdram, ctx);
        goto after_60;
    // 0x80802CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_60:
    // 0x80802CF8: bne         $v0, $zero, L_80802D2C
    if (ctx->r2 != 0) {
        // 0x80802CFC: nop
    
            goto L_80802D2C;
    }
    // 0x80802CFC: nop

    // 0x80802D00: lbu         $t5, 0x7A($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X7A);
    // 0x80802D04: addiu       $a0, $zero, 0x405
    ctx->r4 = ADD32(0, 0X405);
    // 0x80802D08: andi        $t4, $t5, 0x1
    ctx->r12 = ctx->r13 & 0X1;
    // 0x80802D0C: beq         $t4, $zero, L_80802D1C
    if (ctx->r12 == 0) {
        // 0x80802D10: nop
    
            goto L_80802D1C;
    }
    // 0x80802D10: nop

    // 0x80802D14: b           L_80802D1C
    // 0x80802D18: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
        goto L_80802D1C;
    // 0x80802D18: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
L_80802D1C:
    // 0x80802D1C: jal         0x800DA298
    // 0x80802D20: nop

    func_800DA298(rdram, ctx);
        goto after_61;
    // 0x80802D20: nop

    after_61:
    // 0x80802D24: beql        $v0, $zero, L_80802D40
    if (ctx->r2 == 0) {
        // 0x80802D28: lwc1        $f0, 0x58($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
            goto L_80802D40;
    }
    goto skip_26;
    // 0x80802D28: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    skip_26:
L_80802D2C:
    // 0x80802D2C: jal         0x808018BC
    // 0x80802D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808018BC_chdragonbrothers(rdram, ctx);
        goto after_62;
    // 0x80802D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_62:
    // 0x80802D34: b           L_80803444
    // 0x80802D38: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x80802D38: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80802D3C: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
L_80802D40:
    // 0x80802D40: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80802D44: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80802D48: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80802D4C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80802D50: nop

    // 0x80802D54: bc1fl       L_80802D6C
    if (!c1cs) {
        // 0x80802D58: lb          $t7, 0x60($t6)
        ctx->r15 = MEM_B(ctx->r14, 0X60);
            goto L_80802D6C;
    }
    goto skip_27;
    // 0x80802D58: lb          $t7, 0x60($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X60);
    skip_27:
    // 0x80802D5C: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80802D60: b           L_80803440
    // 0x80802D64: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
        goto L_80803440;
    // 0x80802D64: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x80802D68: lb          $t7, 0x60($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X60);
L_80802D6C:
    // 0x80802D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802D70: blez        $t7, L_80802D88
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80802D74: nop
    
            goto L_80802D88;
    }
    // 0x80802D74: nop

    // 0x80802D78: jal         0x80800000
    // 0x80802D7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800000_chdragonbrothers(rdram, ctx);
        goto after_63;
    // 0x80802D7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_63:
    // 0x80802D80: b           L_80803444
    // 0x80802D84: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x80802D84: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_80802D88:
    // 0x80802D88: jal         0x80802534
    // 0x80802D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802534_chdragonbrothers(rdram, ctx);
        goto after_64;
    // 0x80802D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_64:
    // 0x80802D90: bne         $v0, $zero, L_80802DC4
    if (ctx->r2 != 0) {
        // 0x80802D94: nop
    
            goto L_80802DC4;
    }
    // 0x80802D94: nop

    // 0x80802D98: lbu         $t0, 0x7A($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X7A);
    // 0x80802D9C: addiu       $a0, $zero, 0x405
    ctx->r4 = ADD32(0, 0X405);
    // 0x80802DA0: andi        $t8, $t0, 0x1
    ctx->r24 = ctx->r8 & 0X1;
    // 0x80802DA4: beq         $t8, $zero, L_80802DB4
    if (ctx->r24 == 0) {
        // 0x80802DA8: nop
    
            goto L_80802DB4;
    }
    // 0x80802DA8: nop

    // 0x80802DAC: b           L_80802DB4
    // 0x80802DB0: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
        goto L_80802DB4;
    // 0x80802DB0: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
L_80802DB4:
    // 0x80802DB4: jal         0x800DA298
    // 0x80802DB8: nop

    func_800DA298(rdram, ctx);
        goto after_65;
    // 0x80802DB8: nop

    after_65:
    // 0x80802DBC: beql        $v0, $zero, L_80803444
    if (ctx->r2 == 0) {
        // 0x80802DC0: lw          $t3, 0x78($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X78);
            goto L_80803444;
    }
    goto skip_28;
    // 0x80802DC0: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    skip_28:
L_80802DC4:
    // 0x80802DC4: jal         0x808018BC
    // 0x80802DC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808018BC_chdragonbrothers(rdram, ctx);
        goto after_66;
    // 0x80802DC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_66:
    // 0x80802DCC: b           L_80803444
    // 0x80802DD0: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x80802DD0: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_80802DD4:
    // 0x80802DD4: jal         0x80101DDC
    // 0x80802DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_67;
    // 0x80802DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_67:
    // 0x80802DDC: beq         $v0, $zero, L_80802E38
    if (ctx->r2 == 0) {
        // 0x80802DE0: nop
    
            goto L_80802E38;
    }
    // 0x80802DE0: nop

    // 0x80802DE4: lbu         $t9, 0x7A($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7A);
    // 0x80802DE8: addiu       $a0, $zero, 0x405
    ctx->r4 = ADD32(0, 0X405);
    // 0x80802DEC: andi        $t2, $t9, 0x1
    ctx->r10 = ctx->r25 & 0X1;
    // 0x80802DF0: beq         $t2, $zero, L_80802E00
    if (ctx->r10 == 0) {
        // 0x80802DF4: nop
    
            goto L_80802E00;
    }
    // 0x80802DF4: nop

    // 0x80802DF8: b           L_80802E00
    // 0x80802DFC: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
        goto L_80802E00;
    // 0x80802DFC: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
L_80802E00:
    // 0x80802E00: jal         0x800DA9E4
    // 0x80802E04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_68;
    // 0x80802E04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_68:
    // 0x80802E08: bne         $v0, $zero, L_80802E30
    if (ctx->r2 != 0) {
        // 0x80802E0C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802E30;
    }
    // 0x80802E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802E10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802E14: jal         0x808012B4
    // 0x80802E18: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_69;
    // 0x80802E18: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_69:
    // 0x80802E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802E20: jal         0x80800D98
    // 0x80802E24: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800D98_chdragonbrothers(rdram, ctx);
        goto after_70;
    // 0x80802E24: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_70:
    // 0x80802E28: b           L_80802E38
    // 0x80802E2C: nop

        goto L_80802E38;
    // 0x80802E2C: nop

L_80802E30:
    // 0x80802E30: jal         0x808012B4
    // 0x80802E34: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_71;
    // 0x80802E34: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_71:
L_80802E38:
    // 0x80802E38: jal         0x80801CEC
    // 0x80802E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801CEC_chdragonbrothers(rdram, ctx);
        goto after_72;
    // 0x80802E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_72:
    // 0x80802E40: b           L_80803444
    // 0x80802E44: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x80802E44: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_80802E48:
    // 0x80802E48: jal         0x80801CEC
    // 0x80802E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801CEC_chdragonbrothers(rdram, ctx);
        goto after_73;
    // 0x80802E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_73:
    // 0x80802E50: b           L_80803444
    // 0x80802E54: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x80802E54: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_80802E58:
    // 0x80802E58: jal         0x80101DDC
    // 0x80802E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_74;
    // 0x80802E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_74:
    // 0x80802E60: beq         $v0, $zero, L_80802E70
    if (ctx->r2 == 0) {
        // 0x80802E64: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802E70;
    }
    // 0x80802E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802E68: jal         0x808012B4
    // 0x80802E6C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_75;
    // 0x80802E6C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_75:
L_80802E70:
    // 0x80802E70: jal         0x80801CEC
    // 0x80802E74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801CEC_chdragonbrothers(rdram, ctx);
        goto after_76;
    // 0x80802E74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_76:
    // 0x80802E78: b           L_80803444
    // 0x80802E7C: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x80802E7C: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_80802E80:
    // 0x80802E80: lui         $a2, 0x450F
    ctx->r6 = S32(0X450F << 16);
    // 0x80802E84: ori         $a2, $a2, 0xC000
    ctx->r6 = ctx->r6 | 0XC000;
    // 0x80802E88: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80802E8C: jal         0x800EEB9C
    // 0x80802E90: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    func_800EEB9C(rdram, ctx);
        goto after_77;
    // 0x80802E90: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    after_77:
    // 0x80802E94: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1852, 0X5678) << 16);
    // 0x80802E98: addiu       $a3, $a3, 0x5678
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1852, 0X5678));
    // 0x80802E9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802EA0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80802EA4: jal         0x80089D50
    // 0x80802EA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_78;
    // 0x80802EA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_78:
    // 0x80802EAC: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80802EB0: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80802EB4: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80802EB8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80802EBC: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    // 0x80802EC0: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x80802EC4: lwc1        $f4, 0x18($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X18);
    // 0x80802EC8: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    // 0x80802ECC: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80802ED0: lw          $a0, 0x10($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X10);
    // 0x80802ED4: beq         $a0, $at, L_80802F04
    if (ctx->r4 == ctx->r1) {
        // 0x80802ED8: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_80802F04;
    }
    // 0x80802ED8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80802EDC: beq         $a0, $at, L_80802FC4
    if (ctx->r4 == ctx->r1) {
        // 0x80802EE0: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_80802FC4;
    }
    // 0x80802EE0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80802EE4: beq         $a0, $at, L_80803058
    if (ctx->r4 == ctx->r1) {
        // 0x80802EE8: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_80803058;
    }
    // 0x80802EE8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80802EEC: beql        $a0, $at, L_80803120
    if (ctx->r4 == ctx->r1) {
        // 0x80802EF0: lw          $t8, 0x64($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X64);
            goto L_80803120;
    }
    goto skip_29;
    // 0x80802EF0: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    skip_29:
    // 0x80802EF4: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x80802EF8: sll         $t5, $v0, 12
    ctx->r13 = S32(ctx->r2 << 12);
    // 0x80802EFC: b           L_808031B4
    // 0x80802F00: srl         $v0, $t5, 31
    ctx->r2 = S32(U32(ctx->r13) >> 31);
        goto L_808031B4;
    // 0x80802F00: srl         $v0, $t5, 31
    ctx->r2 = S32(U32(ctx->r13) >> 31);
L_80802F04:
    // 0x80802F04: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80802F08: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80802F0C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X52D4) << 16);
    // 0x80802F10: sll         $t0, $t6, 12
    ctx->r8 = S32(ctx->r14 << 12);
    // 0x80802F14: bgez        $t0, L_80802F28
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80802F18: nop
    
            goto L_80802F28;
    }
    // 0x80802F18: nop

    // 0x80802F1C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X52D0) << 16);
    // 0x80802F20: b           L_80802F2C
    // 0x80802F24: lwc1        $f0, 0x52D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X52D0));
        goto L_80802F2C;
    // 0x80802F24: lwc1        $f0, 0x52D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X52D0));
L_80802F28:
    // 0x80802F28: lwc1        $f0, 0x52D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X52D4));
L_80802F2C:
    // 0x80802F2C: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80802F30: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80802F34: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80802F38: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80802F3C: jal         0x800F10B4
    // 0x80802F40: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_79;
    // 0x80802F40: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_79:
    // 0x80802F44: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80802F48: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80802F4C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80802F50: sll         $t2, $t8, 12
    ctx->r10 = S32(ctx->r24 << 12);
    // 0x80802F54: bgezl       $t2, L_80802F70
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80802F58: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80802F70;
    }
    goto skip_30;
    // 0x80802F58: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_30:
    // 0x80802F5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802F60: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80802F64: b           L_80802F78
    // 0x80802F68: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
        goto L_80802F78;
    // 0x80802F68: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80802F6C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80802F70:
    // 0x80802F70: nop

    // 0x80802F74: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
L_80802F78:
    // 0x80802F78: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80802F7C: nop

    // 0x80802F80: bc1fl       L_80802FB8
    if (!c1cs) {
        // 0x80802F84: lw          $v0, 0x64($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X64);
            goto L_80802FB8;
    }
    goto skip_31;
    // 0x80802F84: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    skip_31:
    // 0x80802F88: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80802F8C: jal         0x800F1DCC
    // 0x80802F90: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    func_800F1DCC(rdram, ctx);
        goto after_80;
    // 0x80802F90: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    after_80:
    // 0x80802F94: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80802F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802F9C: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80802FA0: nop

    // 0x80802FA4: bc1fl       L_80802FB8
    if (!c1cs) {
        // 0x80802FA8: lw          $v0, 0x64($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X64);
            goto L_80802FB8;
    }
    goto skip_32;
    // 0x80802FA8: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    skip_32:
    // 0x80802FAC: jal         0x80800D98
    // 0x80802FB0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_80800D98_chdragonbrothers(rdram, ctx);
        goto after_81;
    // 0x80802FB0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_81:
    // 0x80802FB4: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
L_80802FB8:
    // 0x80802FB8: sll         $t1, $v0, 12
    ctx->r9 = S32(ctx->r2 << 12);
    // 0x80802FBC: b           L_808031B4
    // 0x80802FC0: srl         $v0, $t1, 31
    ctx->r2 = S32(U32(ctx->r9) >> 31);
        goto L_808031B4;
    // 0x80802FC0: srl         $v0, $t1, 31
    ctx->r2 = S32(U32(ctx->r9) >> 31);
L_80802FC4:
    // 0x80802FC4: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
    // 0x80802FC8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80802FCC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X52DC) << 16);
    // 0x80802FD0: sll         $t6, $t5, 12
    ctx->r14 = S32(ctx->r13 << 12);
    // 0x80802FD4: bgez        $t6, L_80802FE8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80802FD8: nop
    
            goto L_80802FE8;
    }
    // 0x80802FD8: nop

    // 0x80802FDC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X52D8) << 16);
    // 0x80802FE0: b           L_80802FEC
    // 0x80802FE4: lwc1        $f0, 0x52D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X52D8));
        goto L_80802FEC;
    // 0x80802FE4: lwc1        $f0, 0x52D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X52D8));
L_80802FE8:
    // 0x80802FE8: lwc1        $f0, 0x52DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X52DC));
L_80802FEC:
    // 0x80802FEC: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80802FF0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80802FF4: lw          $a3, 0x34($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X34);
    // 0x80802FF8: jal         0x800F10B4
    // 0x80802FFC: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_82;
    // 0x80802FFC: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_82:
    // 0x80803000: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x80803004: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80803008: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X52E4) << 16);
    // 0x8080300C: sll         $t7, $v0, 12
    ctx->r15 = S32(ctx->r2 << 12);
    // 0x80803010: srl         $v0, $t7, 31
    ctx->r2 = S32(U32(ctx->r15) >> 31);
    // 0x80803014: beq         $v0, $zero, L_80803028
    if (ctx->r2 == 0) {
        // 0x80803018: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803028;
    }
    // 0x80803018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080301C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X52E0) << 16);
    // 0x80803020: b           L_8080302C
    // 0x80803024: lwc1        $f0, 0x52E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X52E0));
        goto L_8080302C;
    // 0x80803024: lwc1        $f0, 0x52E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X52E0));
L_80803028:
    // 0x80803028: lwc1        $f0, 0x52E4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X52E4));
L_8080302C:
    // 0x8080302C: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80803030: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80803034: nop

    // 0x80803038: bc1fl       L_808031B8
    if (!c1cs) {
        // 0x8080303C: lwc1        $f4, 0x24($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
            goto L_808031B8;
    }
    goto skip_33;
    // 0x8080303C: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    skip_33:
    // 0x80803040: jal         0x80800D98
    // 0x80803044: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80800D98_chdragonbrothers(rdram, ctx);
        goto after_83;
    // 0x80803044: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_83:
    // 0x80803048: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x8080304C: sll         $t8, $v0, 12
    ctx->r24 = S32(ctx->r2 << 12);
    // 0x80803050: b           L_808031B4
    // 0x80803054: srl         $v0, $t8, 31
    ctx->r2 = S32(U32(ctx->r24) >> 31);
        goto L_808031B4;
    // 0x80803054: srl         $v0, $t8, 31
    ctx->r2 = S32(U32(ctx->r24) >> 31);
L_80803058:
    // 0x80803058: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x8080305C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80803060: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X52EC) << 16);
    // 0x80803064: sll         $t3, $t2, 12
    ctx->r11 = S32(ctx->r10 << 12);
    // 0x80803068: bgez        $t3, L_8080307C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8080306C: nop
    
            goto L_8080307C;
    }
    // 0x8080306C: nop

    // 0x80803070: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X52E8) << 16);
    // 0x80803074: b           L_80803080
    // 0x80803078: lwc1        $f0, 0x52E8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X52E8));
        goto L_80803080;
    // 0x80803078: lwc1        $f0, 0x52E8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X52E8));
L_8080307C:
    // 0x8080307C: lwc1        $f0, 0x52EC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X52EC));
L_80803080:
    // 0x80803080: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80803084: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80803088: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080308C: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80803090: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80803094: jal         0x800F10B4
    // 0x80803098: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_84;
    // 0x80803098: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_84:
    // 0x8080309C: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
    // 0x808030A0: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x808030A4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808030A8: sll         $t6, $t5, 12
    ctx->r14 = S32(ctx->r13 << 12);
    // 0x808030AC: bgezl       $t6, L_808030C8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808030B0: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_808030C8;
    }
    goto skip_34;
    // 0x808030B0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_34:
    // 0x808030B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808030B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808030BC: b           L_808030D0
    // 0x808030C0: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
        goto L_808030D0;
    // 0x808030C0: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808030C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_808030C8:
    // 0x808030C8: nop

    // 0x808030CC: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
L_808030D0:
    // 0x808030D0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808030D4: nop

    // 0x808030D8: bc1fl       L_80803110
    if (!c1cs) {
        // 0x808030DC: lw          $v0, 0x64($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X64);
            goto L_80803110;
    }
    goto skip_35;
    // 0x808030DC: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    skip_35:
    // 0x808030E0: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808030E4: jal         0x800F1DCC
    // 0x808030E8: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    func_800F1DCC(rdram, ctx);
        goto after_85;
    // 0x808030E8: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    after_85:
    // 0x808030EC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808030F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808030F4: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x808030F8: nop

    // 0x808030FC: bc1fl       L_80803110
    if (!c1cs) {
        // 0x80803100: lw          $v0, 0x64($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X64);
            goto L_80803110;
    }
    goto skip_36;
    // 0x80803100: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    skip_36:
    // 0x80803104: jal         0x80800D98
    // 0x80803108: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_80800D98_chdragonbrothers(rdram, ctx);
        goto after_86;
    // 0x80803108: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_86:
    // 0x8080310C: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
L_80803110:
    // 0x80803110: sll         $t7, $v0, 12
    ctx->r15 = S32(ctx->r2 << 12);
    // 0x80803114: b           L_808031B4
    // 0x80803118: srl         $v0, $t7, 31
    ctx->r2 = S32(U32(ctx->r15) >> 31);
        goto L_808031B4;
    // 0x80803118: srl         $v0, $t7, 31
    ctx->r2 = S32(U32(ctx->r15) >> 31);
    // 0x8080311C: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
L_80803120:
    // 0x80803120: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X52F4) << 16);
    // 0x80803124: sll         $t2, $t8, 12
    ctx->r10 = S32(ctx->r24 << 12);
    // 0x80803128: bgez        $t2, L_8080313C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8080312C: nop
    
            goto L_8080313C;
    }
    // 0x8080312C: nop

    // 0x80803130: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X52F0) << 16);
    // 0x80803134: b           L_80803140
    // 0x80803138: lwc1        $f0, 0x52F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X52F0));
        goto L_80803140;
    // 0x80803138: lwc1        $f0, 0x52F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X52F0));
L_8080313C:
    // 0x8080313C: lwc1        $f0, 0x52F4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X52F4));
L_80803140:
    // 0x80803140: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80803144: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80803148: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080314C: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80803150: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80803154: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80803158: jal         0x800F10B4
    // 0x8080315C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_87;
    // 0x8080315C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_87:
    // 0x80803160: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x80803164: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80803168: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X52FC) << 16);
    // 0x8080316C: sll         $t1, $v0, 12
    ctx->r9 = S32(ctx->r2 << 12);
    // 0x80803170: srl         $v0, $t1, 31
    ctx->r2 = S32(U32(ctx->r9) >> 31);
    // 0x80803174: beq         $v0, $zero, L_80803188
    if (ctx->r2 == 0) {
        // 0x80803178: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803188;
    }
    // 0x80803178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080317C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X52F8) << 16);
    // 0x80803180: b           L_8080318C
    // 0x80803184: lwc1        $f0, 0x52F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X52F8));
        goto L_8080318C;
    // 0x80803184: lwc1        $f0, 0x52F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X52F8));
L_80803188:
    // 0x80803188: lwc1        $f0, 0x52FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X52FC));
L_8080318C:
    // 0x8080318C: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80803190: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80803194: nop

    // 0x80803198: bc1fl       L_808031B8
    if (!c1cs) {
        // 0x8080319C: lwc1        $f4, 0x24($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
            goto L_808031B8;
    }
    goto skip_37;
    // 0x8080319C: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    skip_37:
    // 0x808031A0: jal         0x80800D98
    // 0x808031A4: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80800D98_chdragonbrothers(rdram, ctx);
        goto after_88;
    // 0x808031A4: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_88:
    // 0x808031A8: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x808031AC: sll         $t5, $v0, 12
    ctx->r13 = S32(ctx->r2 << 12);
    // 0x808031B0: srl         $v0, $t5, 31
    ctx->r2 = S32(U32(ctx->r13) >> 31);
L_808031B4:
    // 0x808031B4: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
L_808031B8:
    // 0x808031B8: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x808031BC: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808031C0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808031C4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808031C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808031CC: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x808031D0: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
    // 0x808031D4: beq         $v0, $zero, L_808031E4
    if (ctx->r2 == 0) {
        // 0x808031D8: lw          $t6, 0x78($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X78);
            goto L_808031E4;
    }
    // 0x808031D8: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x808031DC: b           L_808031E4
    // 0x808031E0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
        goto L_808031E4;
    // 0x808031E0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_808031E4:
    // 0x808031E4: lbu         $t7, 0x5B($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5B);
    // 0x808031E8: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x808031EC: bne         $at, $zero, L_80803200
    if (ctx->r1 != 0) {
        // 0x808031F0: nop
    
            goto L_80803200;
    }
    // 0x808031F0: nop

    // 0x808031F4: lbu         $t0, 0x63($t6)
    ctx->r8 = MEM_BU(ctx->r14, 0X63);
    // 0x808031F8: beql        $t0, $zero, L_80803444
    if (ctx->r8 == 0) {
        // 0x808031FC: lw          $t3, 0x78($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X78);
            goto L_80803444;
    }
    goto skip_38;
    // 0x808031FC: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    skip_38:
L_80803200:
    // 0x80803200: jal         0x80800D98
    // 0x80803204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800D98_chdragonbrothers(rdram, ctx);
        goto after_89;
    // 0x80803204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_89:
    // 0x80803208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080320C: jal         0x808012B4
    // 0x80803210: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_90;
    // 0x80803210: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_90:
    // 0x80803214: b           L_80803444
    // 0x80803218: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x80803218: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_8080321C:
    // 0x8080321C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803220: jal         0x80801C44
    // 0x80803224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801C44_chdragonbrothers(rdram, ctx);
        goto after_91;
    // 0x80803224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_91:
    // 0x80803228: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x8080322C: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x80803230: jal         0x80101E14
    // 0x80803234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_92;
    // 0x80803234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_92:
    // 0x80803238: beq         $v0, $zero, L_80803440
    if (ctx->r2 == 0) {
        // 0x8080323C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803440;
    }
    // 0x8080323C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803240: jal         0x808012B4
    // 0x80803244: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_93;
    // 0x80803244: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_93:
    // 0x80803248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080324C: jal         0x80800000
    // 0x80803250: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800000_chdragonbrothers(rdram, ctx);
        goto after_94;
    // 0x80803250: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_94:
    // 0x80803254: b           L_80803444
    // 0x80803258: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x80803258: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_8080325C:
    // 0x8080325C: jal         0x80800C08
    // 0x80803260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C08_chdragonbrothers(rdram, ctx);
        goto after_95;
    // 0x80803260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_95:
    // 0x80803264: jal         0x80801CEC
    // 0x80803268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801CEC_chdragonbrothers(rdram, ctx);
        goto after_96;
    // 0x80803268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_96:
    // 0x8080326C: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80803270: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80803274: lw          $a0, 0x10($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X10);
    // 0x80803278: beq         $a0, $at, L_80803300
    if (ctx->r4 == ctx->r1) {
        // 0x8080327C: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80803300;
    }
    // 0x8080327C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80803280: bne         $a0, $at, L_80803440
    if (ctx->r4 != ctx->r1) {
        // 0x80803284: lui         $a1, 0x3F6B
        ctx->r5 = S32(0X3F6B << 16);
            goto L_80803440;
    }
    // 0x80803284: lui         $a1, 0x3F6B
    ctx->r5 = S32(0X3F6B << 16);
    // 0x80803288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080328C: jal         0x80101E14
    // 0x80803290: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    func_80101E14(rdram, ctx);
        goto after_97;
    // 0x80803290: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    after_97:
    // 0x80803294: beq         $v0, $zero, L_808032E0
    if (ctx->r2 == 0) {
        // 0x80803298: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_808032E0;
    }
    // 0x80803298: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080329C: lui         $a2, 0x4541
    ctx->r6 = S32(0X4541 << 16);
    // 0x808032A0: ori         $a2, $a2, 0xC000
    ctx->r6 = ctx->r6 | 0XC000;
    // 0x808032A4: jal         0x800EEB9C
    // 0x808032A8: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    func_800EEB9C(rdram, ctx);
        goto after_98;
    // 0x808032A8: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    after_98:
    // 0x808032AC: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x808032B0: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808032B4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808032B8: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    // 0x808032BC: jal         0x800E1610
    // 0x808032C0: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    func_800E1610(rdram, ctx);
        goto after_99;
    // 0x808032C0: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    after_99:
    // 0x808032C4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1852, 0X5410) << 16);
    // 0x808032C8: addiu       $a2, $a2, 0x5410
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1852, 0X5410));
    // 0x808032CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808032D0: jal         0x80089D18
    // 0x808032D4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_100;
    // 0x808032D4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_100:
    // 0x808032D8: b           L_80803444
    // 0x808032DC: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x808032DC: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_808032E0:
    // 0x808032E0: jal         0x80101DDC
    // 0x808032E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_101;
    // 0x808032E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_101:
    // 0x808032E8: beq         $v0, $zero, L_80803440
    if (ctx->r2 == 0) {
        // 0x808032EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803440;
    }
    // 0x808032EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808032F0: jal         0x80800D98
    // 0x808032F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800D98_chdragonbrothers(rdram, ctx);
        goto after_102;
    // 0x808032F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_102:
    // 0x808032F8: b           L_80803444
    // 0x808032FC: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x808032FC: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_80803300:
    // 0x80803300: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80803304: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80803308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080330C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80803310: nop

    // 0x80803314: bc1f        L_80803334
    if (!c1cs) {
        // 0x80803318: nop
    
            goto L_80803334;
    }
    // 0x80803318: nop

    // 0x8080331C: jal         0x800D8FF8
    // 0x80803320: nop

    func_800D8FF8(rdram, ctx);
        goto after_103;
    // 0x80803320: nop

    after_103:
    // 0x80803324: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80803328: sub.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8080332C: b           L_80803440
    // 0x80803330: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
        goto L_80803440;
    // 0x80803330: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_80803334:
    // 0x80803334: jal         0x808012B4
    // 0x80803338: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_104;
    // 0x80803338: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_104:
    // 0x8080333C: b           L_80803444
    // 0x80803340: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x80803340: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_80803344:
    // 0x80803344: jal         0x80101DDC
    // 0x80803348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_105;
    // 0x80803348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_105:
    // 0x8080334C: beq         $v0, $zero, L_80803440
    if (ctx->r2 == 0) {
        // 0x80803350: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803440;
    }
    // 0x80803350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803354: jal         0x808012B4
    // 0x80803358: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_106;
    // 0x80803358: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_106:
    // 0x8080335C: b           L_80803444
    // 0x80803360: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x80803360: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_80803364:
    // 0x80803364: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1852, 0X5694) << 16);
    // 0x80803368: addiu       $a1, $a1, 0x5694
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1852, 0X5694));
    // 0x8080336C: jal         0x80101E4C
    // 0x80803370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E4C(rdram, ctx);
        goto after_107;
    // 0x80803370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_107:
    // 0x80803374: beq         $v0, $zero, L_8080338C
    if (ctx->r2 == 0) {
        // 0x80803378: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080338C;
    }
    // 0x80803378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080337C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1852, 0X5424) << 16);
    // 0x80803380: addiu       $a2, $a2, 0x5424
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1852, 0X5424));
    // 0x80803384: jal         0x80089D18
    // 0x80803388: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_108;
    // 0x80803388: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_108:
L_8080338C:
    // 0x8080338C: jal         0x80101DDC
    // 0x80803390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_109;
    // 0x80803390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_109:
    // 0x80803394: beq         $v0, $zero, L_80803440
    if (ctx->r2 == 0) {
        // 0x80803398: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803440;
    }
    // 0x80803398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080339C: jal         0x808012B4
    // 0x808033A0: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_110;
    // 0x808033A0: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_110:
    // 0x808033A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808033A8: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x808033AC: addiu       $a2, $zero, 0x420
    ctx->r6 = ADD32(0, 0X420);
    // 0x808033B0: jal         0x80800A80
    // 0x808033B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80800A80_chdragonbrothers(rdram, ctx);
        goto after_111;
    // 0x808033B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_111:
    // 0x808033B8: b           L_80803444
    // 0x808033BC: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x808033BC: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_808033C0:
    // 0x808033C0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1852, 0X5424) << 16);
    // 0x808033C4: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x808033C8: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808033CC: addiu       $a2, $a2, 0x5424
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1852, 0X5424));
    // 0x808033D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808033D4: jal         0x80089D20
    // 0x808033D8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_112;
    // 0x808033D8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_112:
    // 0x808033DC: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x808033E0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808033E4: lw          $a0, 0x10($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X10);
    // 0x808033E8: beq         $a0, $at, L_80803440
    if (ctx->r4 == ctx->r1) {
        // 0x808033EC: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80803440;
    }
    // 0x808033EC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x808033F0: beq         $a0, $at, L_8080340C
    if (ctx->r4 == ctx->r1) {
        // 0x808033F4: lw          $t2, 0x78($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X78);
            goto L_8080340C;
    }
    // 0x808033F4: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x808033F8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x808033FC: beq         $a0, $at, L_8080342C
    if (ctx->r4 == ctx->r1) {
        // 0x80803400: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_8080342C;
    }
    // 0x80803400: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80803404: b           L_80803444
    // 0x80803408: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x80803408: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_8080340C:
    // 0x8080340C: lbu         $t1, 0x58($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X58);
    // 0x80803410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803414: bnel        $t1, $zero, L_80803444
    if (ctx->r9 != 0) {
        // 0x80803418: lw          $t3, 0x78($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X78);
            goto L_80803444;
    }
    goto skip_39;
    // 0x80803418: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    skip_39:
    // 0x8080341C: jal         0x80800D98
    // 0x80803420: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80800D98_chdragonbrothers(rdram, ctx);
        goto after_113;
    // 0x80803420: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_113:
    // 0x80803424: b           L_80803444
    // 0x80803428: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
        goto L_80803444;
    // 0x80803428: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_8080342C:
    // 0x8080342C: jal         0x808012B4
    // 0x80803430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_114;
    // 0x80803430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_114:
    // 0x80803434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803438: jal         0x80800D98
    // 0x8080343C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800D98_chdragonbrothers(rdram, ctx);
        goto after_115;
    // 0x8080343C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_115:
L_80803440:
    // 0x80803440: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_80803444:
    // 0x80803444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803448: lbu         $t5, 0x5A($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X5A);
    // 0x8080344C: bnel        $t5, $zero, L_80803468
    if (ctx->r13 != 0) {
        // 0x80803450: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803468;
    }
    goto skip_40;
    // 0x80803450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_40:
    // 0x80803454: jal         0x80100094
    // 0x80803458: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_116;
    // 0x80803458: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_116:
    // 0x8080345C: jal         0x800897D0
    // 0x80803460: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _suexpression_entrypoint_9(rdram, ctx);
        goto after_117;
    // 0x80803460: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_117:
    // 0x80803464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80803468:
    // 0x80803468: jal         0x80100094
    // 0x8080346C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_118;
    // 0x8080346C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_118:
    // 0x80803470: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803474: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80803478: jal         0x800897D8
    // 0x8080347C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_119;
    // 0x8080347C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_119:
    // 0x80803480: jal         0x808006C8
    // 0x80803484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006C8_chdragonbrothers(rdram, ctx);
        goto after_120;
    // 0x80803484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_120:
    // 0x80803488: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x8080348C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803490: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80803494: lbu         $t7, 0x59($t4)
    ctx->r15 = MEM_BU(ctx->r12, 0X59);
    // 0x80803498: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080349C: bnel        $t7, $at, L_808034CC
    if (ctx->r15 != ctx->r1) {
        // 0x808034A0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808034CC;
    }
    goto skip_41;
    // 0x808034A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_41:
    // 0x808034A4: lbu         $t6, 0x7A($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X7A);
    // 0x808034A8: addiu       $a0, $zero, 0xFA
    ctx->r4 = ADD32(0, 0XFA);
    // 0x808034AC: andi        $t0, $t6, 0x1
    ctx->r8 = ctx->r14 & 0X1;
    // 0x808034B0: beq         $t0, $zero, L_808034C0
    if (ctx->r8 == 0) {
        // 0x808034B4: nop
    
            goto L_808034C0;
    }
    // 0x808034B4: nop

    // 0x808034B8: b           L_808034C0
    // 0x808034BC: addiu       $a0, $zero, 0xF9
    ctx->r4 = ADD32(0, 0XF9);
        goto L_808034C0;
    // 0x808034BC: addiu       $a0, $zero, 0xF9
    ctx->r4 = ADD32(0, 0XF9);
L_808034C0:
    // 0x808034C0: jal         0x800D2498
    // 0x808034C4: lw          $a1, 0xC($t8)
    ctx->r5 = MEM_W(ctx->r24, 0XC);
    func_800D2498(rdram, ctx);
        goto after_121;
    // 0x808034C4: lw          $a1, 0xC($t8)
    ctx->r5 = MEM_W(ctx->r24, 0XC);
    after_121:
    // 0x808034C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808034CC:
    // 0x808034CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808034D0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x808034D4: jr          $ra
    // 0x808034D8: nop

    return;
    // 0x808034D8: nop

;}
RECOMP_FUNC void func_80800000_sujiggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: andi        $a3, $a0, 0xFFFF
    ctx->r7 = ctx->r4 & 0XFFFF;
    // 0x80800004: lui         $at, 0xB000
    ctx->r1 = S32(0XB000 << 16);
    // 0x80800008: addu        $a3, $a3, $at
    ctx->r7 = ADD32(ctx->r7, ctx->r1);
    // 0x8080000C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800010: and         $a2, $a0, $at
    ctx->r6 = ctx->r4 & ctx->r1;
    // 0x80800014: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800018: srl         $t6, $a2, 16
    ctx->r14 = S32(U32(ctx->r6) >> 16);
    // 0x8080001C: andi        $t7, $a3, 0x2
    ctx->r15 = ctx->r7 & 0X2;
    // 0x80800020: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800024: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800028: beq         $t7, $zero, L_80800060
    if (ctx->r15 == 0) {
        // 0x8080002C: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_80800060;
    }
    // 0x8080002C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80800030: srl         $a0, $a3, 2
    ctx->r4 = S32(U32(ctx->r7) >> 2);
    // 0x80800034: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80800038: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8080003C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800040: jal         0x8001E210
    // 0x80800044: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    rom_read_word(rdram, ctx);
        goto after_0;
    // 0x80800044: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80800048: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8080004C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800050: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800054: and         $t9, $s0, $at
    ctx->r25 = ctx->r16 & ctx->r1;
    // 0x80800058: b           L_80800080
    // 0x8080005C: srl         $s0, $t9, 16
    ctx->r16 = S32(U32(ctx->r25) >> 16);
        goto L_80800080;
    // 0x8080005C: srl         $s0, $t9, 16
    ctx->r16 = S32(U32(ctx->r25) >> 16);
L_80800060:
    // 0x80800060: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800064: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800068: jal         0x8001E210
    // 0x8080006C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    rom_read_word(rdram, ctx);
        goto after_1;
    // 0x8080006C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800070: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80800074: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800078: andi        $t1, $s0, 0xFFFF
    ctx->r9 = ctx->r16 & 0XFFFF;
    // 0x8080007C: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
L_80800080:
    // 0x80800080: beq         $a2, $zero, L_808000D4
    if (ctx->r6 == 0) {
        // 0x80800084: lui         $at, 0xB000
        ctx->r1 = S32(0XB000 << 16);
            goto L_808000D4;
    }
    // 0x80800084: lui         $at, 0xB000
    ctx->r1 = S32(0XB000 << 16);
    // 0x80800088: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x8080008C: andi        $t2, $a2, 0x2
    ctx->r10 = ctx->r6 & 0X2;
    // 0x80800090: beq         $t2, $zero, L_808000C0
    if (ctx->r10 == 0) {
        // 0x80800094: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_808000C0;
    }
    // 0x80800094: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800098: srl         $t3, $a2, 2
    ctx->r11 = S32(U32(ctx->r6) >> 2);
    // 0x8080009C: sll         $a0, $t3, 2
    ctx->r4 = S32(ctx->r11 << 2);
    // 0x808000A0: jal         0x8001E210
    // 0x808000A4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    rom_read_word(rdram, ctx);
        goto after_2;
    // 0x808000A4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x808000A8: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x808000AC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x808000B0: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x808000B4: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x808000B8: b           L_808000D4
    // 0x808000BC: addu        $s0, $s0, $t7
    ctx->r16 = ADD32(ctx->r16, ctx->r15);
        goto L_808000D4;
    // 0x808000BC: addu        $s0, $s0, $t7
    ctx->r16 = ADD32(ctx->r16, ctx->r15);
L_808000C0:
    // 0x808000C0: jal         0x8001E210
    // 0x808000C4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    rom_read_word(rdram, ctx);
        goto after_3;
    // 0x808000C4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x808000C8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x808000CC: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x808000D0: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
L_808000D4:
    // 0x808000D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000D8: addiu       $v0, $s0, 0xA0
    ctx->r2 = ADD32(ctx->r16, 0XA0);
    // 0x808000DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000E0: jr          $ra
    // 0x808000E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808000E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_808001DC_gcdialogexec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001E8: lw          $v0, 0x170($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X170);
    // 0x808001EC: lh          $a1, 0x162($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X162);
    // 0x808001F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001F4: beq         $v0, $zero, L_8080023C
    if (ctx->r2 == 0) {
        // 0x808001F8: sh          $a1, 0x164($a0)
        MEM_H(0X164, ctx->r4) = ctx->r5;
            goto L_8080023C;
    }
    // 0x808001F8: sh          $a1, 0x164($a0)
    MEM_H(0X164, ctx->r4) = ctx->r5;
    // 0x808001FC: lw          $a0, 0x168($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X168);
    // 0x80800200: bne         $a0, $zero, L_80800218
    if (ctx->r4 != 0) {
        // 0x80800204: nop
    
            goto L_80800218;
    }
    // 0x80800204: nop

    // 0x80800208: jalr        $v0
    // 0x8080020C: lb          $a2, 0x160($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X160);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8080020C: lb          $a2, 0x160($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X160);
    after_0:
    // 0x80800210: b           L_80800240
    // 0x80800214: lw          $a0, 0x168($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X168);
        goto L_80800240;
    // 0x80800214: lw          $a0, 0x168($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X168);
L_80800218:
    // 0x80800218: jal         0x80800000
    // 0x8080021C: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    func_80800000_gcdialogexec(rdram, ctx);
        goto after_1;
    // 0x8080021C: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_1:
    // 0x80800220: beql        $v0, $zero, L_80800240
    if (ctx->r2 == 0) {
        // 0x80800224: lw          $a0, 0x168($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X168);
            goto L_80800240;
    }
    goto skip_0;
    // 0x80800224: lw          $a0, 0x168($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X168);
    skip_0:
    // 0x80800228: lw          $t9, 0x170($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X170);
    // 0x8080022C: lw          $a0, 0x168($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X168);
    // 0x80800230: lh          $a1, 0x162($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X162);
    // 0x80800234: jalr        $t9
    // 0x80800238: lb          $a2, 0x160($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X160);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80800238: lb          $a2, 0x160($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X160);
    after_2:
L_8080023C:
    // 0x8080023C: lw          $a0, 0x168($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X168);
L_80800240:
    // 0x80800240: beql        $a0, $zero, L_8080027C
    if (ctx->r4 == 0) {
        // 0x80800244: lhu         $t8, 0x15A($s0)
        ctx->r24 = MEM_HU(ctx->r16, 0X15A);
            goto L_8080027C;
    }
    goto skip_1;
    // 0x80800244: lhu         $t8, 0x15A($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X15A);
    skip_1:
    // 0x80800248: jal         0x80800000
    // 0x8080024C: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    func_80800000_gcdialogexec(rdram, ctx);
        goto after_3;
    // 0x8080024C: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_3:
    // 0x80800250: beql        $v0, $zero, L_8080027C
    if (ctx->r2 == 0) {
        // 0x80800254: lhu         $t8, 0x15A($s0)
        ctx->r24 = MEM_HU(ctx->r16, 0X15A);
            goto L_8080027C;
    }
    goto skip_2;
    // 0x80800254: lhu         $t8, 0x15A($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X15A);
    skip_2:
    // 0x80800258: lw          $a0, 0x168($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X168);
    // 0x8080025C: lhu         $t6, 0x18($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X18);
    // 0x80800260: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80800264: beql        $t7, $zero, L_8080027C
    if (ctx->r15 == 0) {
        // 0x80800268: lhu         $t8, 0x15A($s0)
        ctx->r24 = MEM_HU(ctx->r16, 0X15A);
            goto L_8080027C;
    }
    goto skip_3;
    // 0x80800268: lhu         $t8, 0x15A($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X15A);
    skip_3:
    // 0x8080026C: lh          $a1, 0x162($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X162);
    // 0x80800270: jal         0x8008A210
    // 0x80800274: lb          $a2, 0x160($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X160);
    _subaddiedialog_entrypoint_12(rdram, ctx);
        goto after_4;
    // 0x80800274: lb          $a2, 0x160($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X160);
    after_4:
    // 0x80800278: lhu         $t8, 0x15A($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X15A);
L_8080027C:
    // 0x8080027C: andi        $t0, $t8, 0x8
    ctx->r8 = ctx->r24 & 0X8;
    // 0x80800280: beq         $t0, $zero, L_808002C0
    if (ctx->r8 == 0) {
        // 0x80800284: nop
    
            goto L_808002C0;
    }
    // 0x80800284: nop

    // 0x80800288: jal         0x800A9C98
    // 0x8080028C: nop

    func_800A9C98(rdram, ctx);
        goto after_5;
    // 0x8080028C: nop

    after_5:
    // 0x80800290: beq         $v0, $zero, L_808002A8
    if (ctx->r2 == 0) {
        // 0x80800294: nop
    
            goto L_808002A8;
    }
    // 0x80800294: nop

    // 0x80800298: lw          $t1, 0x15C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X15C);
    // 0x8080029C: sll         $t3, $t1, 20
    ctx->r11 = S32(ctx->r9 << 20);
    // 0x808002A0: bltz        $t3, L_808002C0
    if (SIGNED(ctx->r11) < 0) {
        // 0x808002A4: nop
    
            goto L_808002C0;
    }
    // 0x808002A4: nop

L_808002A8:
    // 0x808002A8: jal         0x800F6438
    // 0x808002AC: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    func_800F6438(rdram, ctx);
        goto after_6;
    // 0x808002AC: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    after_6:
    // 0x808002B0: beq         $v0, $zero, L_808002C0
    if (ctx->r2 == 0) {
        // 0x808002B4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808002C0;
    }
    // 0x808002B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002B8: jal         0x800F82D4
    // 0x808002BC: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    func_800F82D4(rdram, ctx);
        goto after_7;
    // 0x808002BC: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    after_7:
L_808002C0:
    // 0x808002C0: jal         0x800FECB8
    // 0x808002C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FECB8(rdram, ctx);
        goto after_8;
    // 0x808002C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x808002C8: jal         0x80800164
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800164_gcdialogexec(rdram, ctx);
        goto after_9;
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808002D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002DC: jr          $ra
    // 0x808002E0: nop

    return;
    // 0x808002E0: nop

;}
RECOMP_FUNC void _bsbwhirl_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082DD8: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082DD8);
    return;
    // 0x80082DDC: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_80800220_subaddietaxi(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800220: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800224: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800228: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080022C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800230: jal         0x8010D254
    // 0x80800234: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x80800234: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80800238: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8080023C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800240: jal         0x800F1DF4
    // 0x80800244: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800F1DF4(rdram, ctx);
        goto after_1;
    // 0x80800244: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x80800248: jal         0x80090010
    // 0x8080024C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_80090010(rdram, ctx);
        goto after_2;
    // 0x8080024C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80800250: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800254: jal         0x800F1DCC
    // 0x80800258: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    func_800F1DCC(rdram, ctx);
        goto after_3;
    // 0x80800258: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x8080025C: jal         0x800F2100
    // 0x80800260: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_4;
    // 0x80800260: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_4:
    // 0x80800264: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800268: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080026C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800270: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800274: nop

    // 0x80800278: bc1f        L_80800284
    if (!c1cs) {
        // 0x8080027C: nop
    
            goto L_80800284;
    }
    // 0x8080027C: nop

    // 0x80800280: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800284:
    // 0x80800284: jr          $ra
    // 0x80800288: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800288: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void boot___osRestoreInt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void bskaz_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: beq         $a1, $a2, L_80800020
    if (ctx->r5 == ctx->r6) {
        // 0x80800008: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800020;
    }
    // 0x80800008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080000C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800010: bnel        $a1, $at, L_80800024
    if (ctx->r5 != ctx->r1) {
        // 0x80800014: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800024;
    }
    goto skip_0;
    // 0x80800014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800018: jal         0x800962B0
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800962B0(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
L_80800020:
    // 0x80800020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800024:
    // 0x80800024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800028: jr          $ra
    // 0x8080002C: nop

    return;
    // 0x8080002C: nop

;}
RECOMP_FUNC void func_800B7AE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7AE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B7AEC: beq         $a0, $zero, L_800B7B04
    if (ctx->r4 == 0) {
        // 0x800B7AF0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800B7B04;
    }
    // 0x800B7AF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7AF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B7AF8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B7AFC: b           L_800B7B0C
    // 0x800B7B00: sb          $t6, -0x7E70($at)
    MEM_B(-0X7E70, ctx->r1) = ctx->r14;
        goto L_800B7B0C;
    // 0x800B7B00: sb          $t6, -0x7E70($at)
    MEM_B(-0X7E70, ctx->r1) = ctx->r14;
L_800B7B04:
    // 0x800B7B04: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B7B08: sb          $zero, -0x7E70($at)
    MEM_B(-0X7E70, ctx->r1) = 0;
L_800B7B0C:
    // 0x800B7B0C: beql        $a0, $zero, L_800B7B20
    if (ctx->r4 == 0) {
        // 0x800B7B10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B7B20;
    }
    goto skip_0;
    // 0x800B7B10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800B7B14: jal         0x800B7B68
    // 0x800B7B18: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800B7B68(rdram, ctx);
        goto after_0;
    // 0x800B7B18: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800B7B1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B7B20:
    // 0x800B7B20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B7B24: jr          $ra
    // 0x800B7B28: nop

    return;
    // 0x800B7B28: nop

;}
RECOMP_FUNC void func_80800B90_chcactusofstrength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B94: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800B98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800BA0: beq         $a1, $at, L_80800BBC
    if (ctx->r5 == ctx->r1) {
        // 0x80800BA4: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800BBC;
    }
    // 0x80800BA4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800BA8: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800BAC: beq         $a1, $at, L_80800BD4
    if (ctx->r5 == ctx->r1) {
        // 0x80800BB0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800BD4;
    }
    // 0x80800BB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800BB4: b           L_80800C08
    // 0x80800BB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800C08;
    // 0x80800BB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800BBC:
    // 0x80800BBC: jal         0x80800C18
    // 0x80800BC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800C18_chcactusofstrength(rdram, ctx);
        goto after_0;
    // 0x80800BC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x80800BC4: jal         0x800FFAB0
    // 0x80800BC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800BC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800BCC: b           L_80800C08
    // 0x80800BD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800C08;
    // 0x80800BD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800BD4:
    // 0x80800BD4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800BD8: addiu       $a1, $zero, 0x13B
    ctx->r5 = ADD32(0, 0X13B);
    // 0x80800BDC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80800BE0: jal         0x80089C20
    // 0x80800BE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800BE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80800BE8: beq         $v0, $zero, L_80800C04
    if (ctx->r2 == 0) {
        // 0x80800BEC: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_80800C04;
    }
    // 0x80800BEC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800BF0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80800BF4: b           L_80800C04
    // 0x80800BF8: sw          $t6, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->r14;
        goto L_80800C04;
    // 0x80800BF8: sw          $t6, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->r14;
    // 0x80800BFC: b           L_80800C08
    // 0x80800C00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800C08;
    // 0x80800C00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C04:
    // 0x80800C04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C08:
    // 0x80800C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C10: jr          $ra
    // 0x80800C14: nop

    return;
    // 0x80800C14: nop

;}
RECOMP_FUNC void func_80800C9C_chclinker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CA0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800CA4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800CA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CAC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800CB0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80800CB4: jal         0x80100094
    // 0x80800CB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800CB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800CBC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CC0: addiu       $at, $zero, 0x137C
    ctx->r1 = ADD32(0, 0X137C);
    // 0x80800CC4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800CC8: beq         $a2, $at, L_80800CF0
    if (ctx->r6 == ctx->r1) {
        // 0x80800CCC: addiu       $at, $zero, 0x137D
        ctx->r1 = ADD32(0, 0X137D);
            goto L_80800CF0;
    }
    // 0x80800CCC: addiu       $at, $zero, 0x137D
    ctx->r1 = ADD32(0, 0X137D);
    // 0x80800CD0: beq         $a2, $at, L_80800D00
    if (ctx->r6 == ctx->r1) {
        // 0x80800CD4: addiu       $at, $zero, 0x137E
        ctx->r1 = ADD32(0, 0X137E);
            goto L_80800D00;
    }
    // 0x80800CD4: addiu       $at, $zero, 0x137E
    ctx->r1 = ADD32(0, 0X137E);
    // 0x80800CD8: beq         $a2, $at, L_80800D00
    if (ctx->r6 == ctx->r1) {
        // 0x80800CDC: addiu       $at, $zero, 0x137F
        ctx->r1 = ADD32(0, 0X137F);
            goto L_80800D00;
    }
    // 0x80800CDC: addiu       $at, $zero, 0x137F
    ctx->r1 = ADD32(0, 0X137F);
    // 0x80800CE0: beq         $a2, $at, L_80800D00
    if (ctx->r6 == ctx->r1) {
        // 0x80800CE4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800D00;
    }
    // 0x80800CE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800CE8: b           L_80800D14
    // 0x80800CEC: nop

        goto L_80800D14;
    // 0x80800CEC: nop

L_80800CF0:
    // 0x80800CF0: jal         0x800D211C
    // 0x80800CF4: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    func_800D211C(rdram, ctx);
        goto after_1;
    // 0x80800CF4: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    after_1:
    // 0x80800CF8: b           L_80800D18
    // 0x80800CFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800D18;
    // 0x80800CFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D00:
    // 0x80800D00: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80800D04: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800D08: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80800D0C: b           L_80800D18
    // 0x80800D10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800D18;
    // 0x80800D10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D14:
    // 0x80800D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D18:
    // 0x80800D18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D1C: jr          $ra
    // 0x80800D20: nop

    return;
    // 0x80800D20: nop

;}
RECOMP_FUNC void sucoaster_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808018B8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808018BC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808018C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808018C4: jal         0x80100094
    // 0x808018C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808018C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808018CC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808018D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018D4: jal         0x80802594
    // 0x808018D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80802594_sucoaster(rdram, ctx);
        goto after_1;
    // 0x808018D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x808018DC: beq         $v0, $zero, L_808018F8
    if (ctx->r2 == 0) {
        // 0x808018E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808018F8;
    }
    // 0x808018E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018E4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x808018E8: jal         0x80801004
    // 0x808018EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x808018EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x808018F0: b           L_8080194C
    // 0x808018F4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
        goto L_8080194C;
    // 0x808018F4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
L_808018F8:
    // 0x808018F8: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808018FC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80801900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801904: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801908: bne         $t7, $at, L_80801940
    if (ctx->r15 != ctx->r1) {
        // 0x8080190C: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80801940;
    }
    // 0x8080190C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801914: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80801918: jal         0x80801004
    // 0x8080191C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x8080191C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80801920: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80801924: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801928: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8080192C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801930: jal         0x800DC178
    // 0x80801934: nop

    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80801934: nop

    after_4:
    // 0x80801938: b           L_80801948
    // 0x8080193C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_80801948;
    // 0x8080193C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80801940:
    // 0x80801940: jal         0x80801004
    // 0x80801944: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x80801944: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
L_80801948:
    // 0x80801948: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
L_8080194C:
    // 0x8080194C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801950: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80801954: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801958: jal         0x800DC178
    // 0x8080195C: nop

    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x8080195C: nop

    after_6:
    // 0x80801960: jal         0x800D9058
    // 0x80801964: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800D9058(rdram, ctx);
        goto after_7;
    // 0x80801964: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_7:
    // 0x80801968: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8080196C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80801970: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801974: jal         0x800D9058
    // 0x80801978: sb          $v0, 0x12($t8)
    MEM_B(0X12, ctx->r24) = ctx->r2;
    func_800D9058(rdram, ctx);
        goto after_8;
    // 0x80801978: sb          $v0, 0x12($t8)
    MEM_B(0X12, ctx->r24) = ctx->r2;
    after_8:
    // 0x8080197C: lhu         $t1, 0x6E($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X6E);
    // 0x80801980: andi        $t0, $v0, 0x1FF
    ctx->r8 = ctx->r2 & 0X1FF;
    // 0x80801984: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801988: andi        $t2, $t1, 0xFE00
    ctx->r10 = ctx->r9 & 0XFE00;
    // 0x8080198C: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80801990: sh          $t3, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r11;
    // 0x80801994: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80801998: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080199C: addiu       $t5, $zero, 0x28
    ctx->r13 = ADD32(0, 0X28);
    // 0x808019A0: lbu         $a2, 0x16($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X16);
    // 0x808019A4: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x808019A8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x808019AC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x808019B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808019B8: jal         0x80089F88
    // 0x808019BC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _subaddierouteDll_entrypoint_6(rdram, ctx);
        goto after_9;
    // 0x808019BC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_9:
    // 0x808019C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808019C4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808019C8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808019CC: jr          $ra
    // 0x808019D0: nop

    return;
    // 0x808019D0: nop

;}
