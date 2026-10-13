#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8008B9C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B9C4: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8008B9C8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8008B9CC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008B9D0: lw          $t9, 0x6CC0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6CC0);
    // 0x8008B9D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008B9D8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8008B9DC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8008B9E0: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8008B9E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B9E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008B9EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8008B9F0: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8008B9F4: lh          $a2, -0x6($v1)
    ctx->r6 = MEM_H(ctx->r3, -0X6);
    // 0x8008B9F8: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x8008B9FC: addiu       $v1, $v1, -0x6
    ctx->r3 = ADD32(ctx->r3, -0X6);
    // 0x8008BA00: beq         $a2, $zero, L_8008BA28
    if (ctx->r6 == 0) {
        // 0x8008BA04: sh          $t0, 0x2($v1)
        MEM_H(0X2, ctx->r3) = ctx->r8;
            goto L_8008BA28;
    }
    // 0x8008BA04: sh          $t0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r8;
    // 0x8008BA08: sll         $a0, $a2, 16
    ctx->r4 = S32(ctx->r6 << 16);
    // 0x8008BA0C: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8008BA10: jal         0x800DFCE8
    // 0x8008BA14: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    func_800DFCE8(rdram, ctx);
        goto after_0;
    // 0x8008BA14: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_0:
    // 0x8008BA18: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8008BA1C: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x8008BA20: b           L_8008BA4C
    // 0x8008BA24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008BA4C;
    // 0x8008BA24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008BA28:
    // 0x8008BA28: jal         0x800DFD10
    // 0x8008BA2C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800DFD10(rdram, ctx);
        goto after_1;
    // 0x8008BA2C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8008BA30: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8008BA34: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8008BA38: jal         0x800DFCE8
    // 0x8008BA3C: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    func_800DFCE8(rdram, ctx);
        goto after_2;
    // 0x8008BA3C: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    after_2:
    // 0x8008BA40: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8008BA44: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x8008BA48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008BA4C:
    // 0x8008BA4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008BA50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008BA54: jr          $ra
    // 0x8008BA58: nop

    return;
    // 0x8008BA58: nop

;}
RECOMP_FUNC void func_80096670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096670: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80096674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80096678: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x8009667C: jal         0x800C67C8
    // 0x80096680: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800C67C8(rdram, ctx);
        goto after_0;
    // 0x80096680: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x80096684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80096688: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009668C: jr          $ra
    // 0x80096690: nop

    return;
    // 0x80096690: nop

;}
RECOMP_FUNC void _chlifeforcespell_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086588: syscall     338
    recomp_syscall_handler(rdram, ctx, 0x80086588);
    return;
    // 0x8008658C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chcrate_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1912, 0X410) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x410
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1912, 0X410));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x410
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1912, 0X410));
;}
RECOMP_FUNC void func_80801200_chnicecavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801200: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801208: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080120C: jal         0x80100094
    // 0x80801210: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801210: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801214: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80801218: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080121C: jal         0x800DA298
    // 0x80801220: lw          $a0, 0x28($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X28);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80801220: lw          $a0, 0x28($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X28);
    after_1:
    // 0x80801224: bne         $v0, $zero, L_8080123C
    if (ctx->r2 != 0) {
        // 0x80801228: nop
    
            goto L_8080123C;
    }
    // 0x80801228: nop

    // 0x8080122C: jal         0x80088848
    // 0x80801230: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x80801230: nop

    after_2:
    // 0x80801234: beql        $v0, $zero, L_80801248
    if (ctx->r2 == 0) {
        // 0x80801238: addiu       $v0, $zero, 0x7E6
        ctx->r2 = ADD32(0, 0X7E6);
            goto L_80801248;
    }
    goto skip_0;
    // 0x80801238: addiu       $v0, $zero, 0x7E6
    ctx->r2 = ADD32(0, 0X7E6);
    skip_0:
L_8080123C:
    // 0x8080123C: b           L_80801248
    // 0x80801240: addiu       $v0, $zero, 0x7E7
    ctx->r2 = ADD32(0, 0X7E7);
        goto L_80801248;
    // 0x80801240: addiu       $v0, $zero, 0x7E7
    ctx->r2 = ADD32(0, 0X7E7);
    // 0x80801244: addiu       $v0, $zero, 0x7E6
    ctx->r2 = ADD32(0, 0X7E6);
L_80801248:
    // 0x80801248: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080124C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801250: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    // 0x80801254: jal         0x8008A060
    // 0x80801258: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    _subaddiepalette_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80801258: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    after_3:
    // 0x8080125C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801260: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801264: jr          $ra
    // 0x80801268: nop

    return;
    // 0x80801268: nop

;}
RECOMP_FUNC void chtntmineshoot_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B94: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2204, 0X26D8) << 16);
    // 0x80801B98: jr          $ra
    // 0x80801B9C: addiu       $v0, $v0, 0x26D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2204, 0X26D8));
    return;
    // 0x80801B9C: addiu       $v0, $v0, 0x26D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2204, 0X26D8));
;}
RECOMP_FUNC void chfiregen_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801020: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1588, 0X19B4) << 16);
    // 0x80801024: jr          $ra
    // 0x80801028: addiu       $v0, $v0, 0x19B4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X19B4));
    return;
    // 0x80801028: addiu       $v0, $v0, 0x19B4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X19B4));
;}
RECOMP_FUNC void func_8080019C_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080019C: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x808001A0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808001A4: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x808001A8: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x808001AC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x808001B0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x808001B4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808001B8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808001BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808001C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808001C4: sw          $a0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r4;
    // 0x808001C8: lw          $s4, 0x0($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X0);
    // 0x808001CC: addiu       $a0, $zero, 0x2BA
    ctx->r4 = ADD32(0, 0X2BA);
    // 0x808001D0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x808001D4: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x808001D8: jal         0x800882C0
    // 0x808001DC: lw          $s6, 0x0($s4)
    ctx->r22 = MEM_W(ctx->r20, 0X0);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x808001DC: lw          $s6, 0x0($s4)
    ctx->r22 = MEM_W(ctx->r20, 0X0);
    after_0:
    // 0x808001E0: jal         0x800EA05C
    // 0x808001E4: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x808001E4: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    after_1:
    // 0x808001E8: jal         0x800883A8
    // 0x808001EC: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    _gcstatusDll_entrypoint_19(rdram, ctx);
        goto after_2;
    // 0x808001EC: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    after_2:
    // 0x808001F0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808001F4: blez        $s5, L_808002C8
    if (SIGNED(ctx->r21) <= 0) {
        // 0x808001F8: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_808002C8;
    }
    // 0x808001F8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808001FC: addiu       $s1, $sp, 0x58
    ctx->r17 = ADD32(ctx->r29, 0X58);
    // 0x80800200: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
L_80800204:
    // 0x80800204: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80800208: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8080020C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800210: lhu         $a2, 0x6($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X6);
    // 0x80800214: srl         $t8, $a2, 7
    ctx->r24 = S32(U32(ctx->r6) >> 7);
    // 0x80800218: jal         0x800842A0
    // 0x8080021C: addiu       $a2, $t8, -0x32
    ctx->r6 = ADD32(ctx->r24, -0X32);
    _bsfirstp_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x8080021C: addiu       $a2, $t8, -0x32
    ctx->r6 = ADD32(ctx->r24, -0X32);
    after_3:
    // 0x80800220: sltiu       $at, $v0, 0x8
    ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x80800224: beq         $at, $zero, L_8080027C
    if (ctx->r1 == 0) {
        // 0x80800228: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_8080027C;
    }
    // 0x80800228: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8080022C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2216, 0X20E8) << 16);
    // 0x80800230: addu        $at, $at, $t9
    gpr jr_addend_80800238 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800234: lw          $t9, 0x20E8($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2216, 0X20E8));
    // 0x80800238: jr          $t9
    // 0x8080023C: nop

    switch (jr_addend_80800238 >> 2) {
        case 0: goto L_80800240; break;
        case 1: goto L_80800248; break;
        case 2: goto L_80800250; break;
        case 3: goto L_80800258; break;
        case 4: goto L_80800260; break;
        case 5: goto L_80800268; break;
        case 6: goto L_80800270; break;
        case 7: goto L_80800278; break;
        default: switch_error(__func__, 0x80800238, 0x808020E8);
    }
    // 0x8080023C: nop

L_80800240:
    // 0x80800240: b           L_8080027C
    // 0x80800244: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_8080027C;
    // 0x80800244: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80800248:
    // 0x80800248: b           L_8080027C
    // 0x8080024C: addiu       $s0, $zero, 0x1C8
    ctx->r16 = ADD32(0, 0X1C8);
        goto L_8080027C;
    // 0x8080024C: addiu       $s0, $zero, 0x1C8
    ctx->r16 = ADD32(0, 0X1C8);
L_80800250:
    // 0x80800250: b           L_8080027C
    // 0x80800254: addiu       $s0, $zero, 0x1C9
    ctx->r16 = ADD32(0, 0X1C9);
        goto L_8080027C;
    // 0x80800254: addiu       $s0, $zero, 0x1C9
    ctx->r16 = ADD32(0, 0X1C9);
L_80800258:
    // 0x80800258: b           L_8080027C
    // 0x8080025C: addiu       $s0, $zero, 0x1CA
    ctx->r16 = ADD32(0, 0X1CA);
        goto L_8080027C;
    // 0x8080025C: addiu       $s0, $zero, 0x1CA
    ctx->r16 = ADD32(0, 0X1CA);
L_80800260:
    // 0x80800260: b           L_8080027C
    // 0x80800264: addiu       $s0, $zero, 0x1CB
    ctx->r16 = ADD32(0, 0X1CB);
        goto L_8080027C;
    // 0x80800264: addiu       $s0, $zero, 0x1CB
    ctx->r16 = ADD32(0, 0X1CB);
L_80800268:
    // 0x80800268: b           L_8080027C
    // 0x8080026C: addiu       $s0, $zero, 0x1CC
    ctx->r16 = ADD32(0, 0X1CC);
        goto L_8080027C;
    // 0x8080026C: addiu       $s0, $zero, 0x1CC
    ctx->r16 = ADD32(0, 0X1CC);
L_80800270:
    // 0x80800270: b           L_8080027C
    // 0x80800274: addiu       $s0, $zero, 0x2B8
    ctx->r16 = ADD32(0, 0X2B8);
        goto L_8080027C;
    // 0x80800274: addiu       $s0, $zero, 0x2B8
    ctx->r16 = ADD32(0, 0X2B8);
L_80800278:
    // 0x80800278: addiu       $s0, $zero, 0x1CD
    ctx->r16 = ADD32(0, 0X1CD);
L_8080027C:
    // 0x8080027C: beql        $s0, $zero, L_808002BC
    if (ctx->r16 == 0) {
        // 0x80800280: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_808002BC;
    }
    goto skip_0;
    // 0x80800280: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x80800284: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080028C: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x80800290: srl         $t0, $a2, 23
    ctx->r8 = S32(U32(ctx->r6) >> 23);
    // 0x80800294: jal         0x801085CC
    // 0x80800298: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    func_801085CC(rdram, ctx);
        goto after_4;
    // 0x80800298: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    after_4:
    // 0x8080029C: lhu         $t1, 0x76($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X76);
    // 0x808002A0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x808002A4: andi        $t2, $t1, 0x7F
    ctx->r10 = ctx->r9 & 0X7F;
    // 0x808002A8: ori         $t3, $t2, 0x1980
    ctx->r11 = ctx->r10 | 0X1980;
    // 0x808002AC: jal         0x80106790
    // 0x808002B0: sh          $t3, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r11;
    func_80106790(rdram, ctx);
        goto after_5;
    // 0x808002B0: sh          $t3, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r11;
    after_5:
    // 0x808002B4: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808002B8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_808002BC:
    // 0x808002BC: bne         $s2, $s5, L_80800204
    if (ctx->r18 != ctx->r21) {
        // 0x808002C0: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80800204;
    }
    // 0x808002C0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x808002C4: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
L_808002C8:
    // 0x808002C8: lw          $t4, 0xD0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD0);
    // 0x808002CC: sw          $s4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r20;
    // 0x808002D0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808002D4: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x808002D8: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x808002DC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x808002E0: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x808002E4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808002E8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808002EC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808002F0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808002F4: jr          $ra
    // 0x808002F8: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x808002F8: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_80805BA0_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805BA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80805BA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80805BA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80805BAC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80805BB0: jal         0x80803E40
    // 0x80805BB4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80803E40_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80805BB4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80805BB8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80805BBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80805BC0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80805BC4: addiu       $t6, $a1, 0x2
    ctx->r14 = ADD32(ctx->r5, 0X2);
    // 0x80805BC8: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80805BCC: bne         $at, $zero, L_80805BE4
    if (ctx->r1 != 0) {
        // 0x80805BD0: nop
    
            goto L_80805BE4;
    }
    // 0x80805BD0: nop

    // 0x80805BD4: jal         0x8080407C
    // 0x80805BD8: nop

    func_8080407C_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80805BD8: nop

    after_1:
    // 0x80805BDC: b           L_80805BF0
    // 0x80805BE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80805BF0;
    // 0x80805BE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80805BE4:
    // 0x80805BE4: jal         0x8080401C
    // 0x80805BE8: nop

    func_8080401C_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80805BE8: nop

    after_2:
    // 0x80805BEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80805BF0:
    // 0x80805BF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80805BF4: jr          $ra
    // 0x80805BF8: nop

    return;
    // 0x80805BF8: nop

;}
RECOMP_FUNC void _bsrest_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083978: syscall     84
    recomp_syscall_handler(rdram, ctx, 0x80083978);
    return;
    // 0x8008397C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800270_gclevel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800270: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800278: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080027C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800280: jal         0x80800314
    // 0x80800284: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80800314_gclevel(rdram, ctx);
        goto after_0;
    // 0x80800284: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80800288: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080028C: bne         $v0, $zero, L_8080029C
    if (ctx->r2 != 0) {
        // 0x80800290: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8080029C;
    }
    // 0x80800290: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800294: b           L_80800304
    // 0x80800298: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800304;
    // 0x80800298: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080029C:
    // 0x8080029C: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x808002A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808002A4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808002A8: bne         $v1, $at, L_808002C0
    if (ctx->r3 != ctx->r1) {
        // 0x808002AC: nop
    
            goto L_808002C0;
    }
    // 0x808002AC: nop

    // 0x808002B0: jal         0x800DA544
    // 0x808002B4: lhu         $a0, 0x2($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X2);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x808002B4: lhu         $a0, 0x2($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X2);
    after_1:
    // 0x808002B8: b           L_80800304
    // 0x808002BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800304;
    // 0x808002BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002C0:
    // 0x808002C0: bne         $t6, $v1, L_808002F0
    if (ctx->r14 != ctx->r3) {
        // 0x808002C4: nop
    
            goto L_808002F0;
    }
    // 0x808002C4: nop

    // 0x808002C8: lb          $t7, 0x6($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X6);
    // 0x808002CC: beq         $a0, $t7, L_808002E0
    if (ctx->r4 == ctx->r15) {
        // 0x808002D0: nop
    
            goto L_808002E0;
    }
    // 0x808002D0: nop

    // 0x808002D4: lb          $t8, 0x7($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X7);
    // 0x808002D8: bne         $a0, $t8, L_808002F0
    if (ctx->r4 != ctx->r24) {
        // 0x808002DC: nop
    
            goto L_808002F0;
    }
    // 0x808002DC: nop

L_808002E0:
    // 0x808002E0: jal         0x800DA544
    // 0x808002E4: lhu         $a0, 0x2($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X2);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x808002E4: lhu         $a0, 0x2($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X2);
    after_2:
    // 0x808002E8: b           L_80800304
    // 0x808002EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800304;
    // 0x808002EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002F0:
    // 0x808002F0: jal         0x800DA298
    // 0x808002F4: lhu         $a0, 0x2($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X2);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x808002F4: lhu         $a0, 0x2($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X2);
    after_3:
    // 0x808002F8: b           L_80800308
    // 0x808002FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800308;
    // 0x808002FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800300: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800304:
    // 0x80800304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800308:
    // 0x80800308: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080030C: jr          $ra
    // 0x80800310: nop

    return;
    // 0x80800310: nop

;}
RECOMP_FUNC void func_80801E5C_sucoasterfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801E5C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801E60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801E64: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801E68: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801E6C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801E70: jal         0x80100094
    // 0x80801E74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801E74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801E78: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80801E7C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801E80: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80801E84: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80801E88: bgez        $t8, L_80801EAC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80801E8C: nop
    
            goto L_80801EAC;
    }
    // 0x80801E8C: nop

    // 0x80801E90: jal         0x8008FE94
    // 0x80801E94: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_8008FE94(rdram, ctx);
        goto after_1;
    // 0x80801E94: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x80801E98: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801E9C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801EA0: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80801EA4: b           L_80801FD0
    // 0x80801EA8: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
        goto L_80801FD0;
    // 0x80801EA8: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
L_80801EAC:
    // 0x80801EAC: jal         0x80104544
    // 0x80801EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104544(rdram, ctx);
        goto after_2;
    // 0x80801EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801EB4: beq         $v0, $zero, L_80801F24
    if (ctx->r2 == 0) {
        // 0x80801EB8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801F24;
    }
    // 0x80801EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801EBC: jal         0x8010473C
    // 0x80801EC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010473C(rdram, ctx);
        goto after_3;
    // 0x80801EC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80801EC4: lh          $t9, 0x18($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X18);
    // 0x80801EC8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80801ECC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801ED0: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80801ED4: nop

    // 0x80801ED8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80801EDC: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80801EE0: jal         0x800EE7F8
    // 0x80801EE4: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80801EE4: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x80801EE8: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80801EEC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80801EF0: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x80801EF4: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
    // 0x80801EF8: sll         $a2, $v0, 22
    ctx->r6 = S32(ctx->r2 << 22);
    // 0x80801EFC: srl         $t0, $a2, 26
    ctx->r8 = S32(U32(ctx->r6) >> 26);
    // 0x80801F00: srl         $a1, $v0, 25
    ctx->r5 = S32(U32(ctx->r2) >> 25);
    // 0x80801F04: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80801F08: jal         0x800CC338
    // 0x80801F0C: addiu       $a2, $t0, -0x1
    ctx->r6 = ADD32(ctx->r8, -0X1);
    func_800CC338(rdram, ctx);
        goto after_5;
    // 0x80801F0C: addiu       $a2, $t0, -0x1
    ctx->r6 = ADD32(ctx->r8, -0X1);
    after_5:
    // 0x80801F10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80801F14: beql        $v0, $at, L_80801FD0
    if (ctx->r2 == ctx->r1) {
        // 0x80801F18: lwc1        $f0, 0x8($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
            goto L_80801FD0;
    }
    goto skip_0;
    // 0x80801F18: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    skip_0:
    // 0x80801F1C: b           L_80801FD0
    // 0x80801F20: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
        goto L_80801FD0;
    // 0x80801F20: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
L_80801F24:
    // 0x80801F24: lh          $t1, 0x18($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X18);
    // 0x80801F28: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80801F2C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801F30: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80801F34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F38: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80801F3C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801F40: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    // 0x80801F44: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80801F48: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80801F4C: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80801F50: jal         0x80801FE4
    // 0x80801F54: nop

    func_80801FE4_sucoasterfly(rdram, ctx);
        goto after_6;
    // 0x80801F54: nop

    after_6:
    // 0x80801F58: beq         $v0, $zero, L_80801FCC
    if (ctx->r2 == 0) {
        // 0x80801F5C: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_80801FCC;
    }
    // 0x80801F5C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80801F60: jal         0x800EE7F8
    // 0x80801F64: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80801F64: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x80801F68: lh          $t2, 0x18($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X18);
    // 0x80801F6C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80801F70: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80801F74: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80801F78: nop

    // 0x80801F7C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80801F80: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80801F84: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x80801F88: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
    // 0x80801F8C: sll         $a2, $v0, 22
    ctx->r6 = S32(ctx->r2 << 22);
    // 0x80801F90: srl         $t3, $a2, 26
    ctx->r11 = S32(U32(ctx->r6) >> 26);
    // 0x80801F94: srl         $a1, $v0, 25
    ctx->r5 = S32(U32(ctx->r2) >> 25);
    // 0x80801F98: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80801F9C: jal         0x800CC338
    // 0x80801FA0: addiu       $a2, $t3, -0x1
    ctx->r6 = ADD32(ctx->r11, -0X1);
    func_800CC338(rdram, ctx);
        goto after_8;
    // 0x80801FA0: addiu       $a2, $t3, -0x1
    ctx->r6 = ADD32(ctx->r11, -0X1);
    after_8:
    // 0x80801FA4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80801FA8: beql        $v0, $at, L_80801FD0
    if (ctx->r2 == ctx->r1) {
        // 0x80801FAC: lwc1        $f0, 0x8($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
            goto L_80801FD0;
    }
    goto skip_1;
    // 0x80801FAC: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    skip_1:
    // 0x80801FB0: lh          $t4, 0x18($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X18);
    // 0x80801FB4: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80801FB8: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80801FBC: nop

    // 0x80801FC0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80801FC4: b           L_80801FD0
    // 0x80801FC8: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
        goto L_80801FD0;
    // 0x80801FC8: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
L_80801FCC:
    // 0x80801FCC: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
L_80801FD0:
    // 0x80801FD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801FD4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801FD8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801FDC: jr          $ra
    // 0x80801FE0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80801FE0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80801EE8_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801EE8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801EEC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80801EF0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80801EF4: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80801EF8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80801EFC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80801F00: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80801F04: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801F08: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801F0C: jal         0x8008A6F8
    // 0x80801F10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    _sujiggy_entrypoint_12(rdram, ctx);
        goto after_0;
    // 0x80801F10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80801F14: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801F18: sw          $v0, 0x2C($s5)
    MEM_W(0X2C, ctx->r21) = ctx->r2;
    // 0x80801F1C: sw          $t6, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r14;
    // 0x80801F20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801F24: jal         0x80088718
    // 0x80801F28: addiu       $a1, $zero, 0x186D
    ctx->r5 = ADD32(0, 0X186D);
    _gldbstring_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80801F28: addiu       $a1, $zero, 0x186D
    ctx->r5 = ADD32(0, 0X186D);
    after_1:
    // 0x80801F2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801F30: jal         0x80088720
    // 0x80801F34: lh          $a1, 0x2E($s5)
    ctx->r5 = MEM_H(ctx->r21, 0X2E);
    _gldbstring_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80801F34: lh          $a1, 0x2E($s5)
    ctx->r5 = MEM_H(ctx->r21, 0X2E);
    after_2:
    // 0x80801F38: lbu         $t7, -0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, -0X1);
    // 0x80801F3C: sll         $s3, $zero, 4
    ctx->r19 = S32(0 << 4);
    // 0x80801F40: subu        $s3, $s3, $zero
    ctx->r19 = SUB32(ctx->r19, 0);
    // 0x80801F44: beq         $t7, $zero, L_80801FCC
    if (ctx->r15 == 0) {
        // 0x80801F48: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80801FCC;
    }
    // 0x80801F48: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80801F4C: sll         $s3, $s3, 1
    ctx->r19 = S32(ctx->r19 << 1);
    // 0x80801F50: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80801F54: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x80801F58: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x80801F5C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80801F60:
    // 0x80801F60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801F64: jal         0x80100094
    // 0x80801F68: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80801F68: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_3:
    // 0x80801F6C: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x80801F70: addu        $a1, $v0, $s3
    ctx->r5 = ADD32(ctx->r2, ctx->r19);
    // 0x80801F74: addiu       $a1, $a1, 0x21C
    ctx->r5 = ADD32(ctx->r5, 0X21C);
    // 0x80801F78: beq         $a0, $zero, L_80801FA8
    if (ctx->r4 == 0) {
        // 0x80801F7C: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80801FA8;
    }
    // 0x80801F7C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80801F80: beq         $s2, $a0, L_80801FA8
    if (ctx->r18 == ctx->r4) {
        // 0x80801F84: addu        $v0, $a1, $s1
        ctx->r2 = ADD32(ctx->r5, ctx->r17);
            goto L_80801FA8;
    }
    // 0x80801F84: addu        $v0, $a1, $s1
    ctx->r2 = ADD32(ctx->r5, ctx->r17);
    // 0x80801F88: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
L_80801F8C:
    // 0x80801F8C: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x80801F90: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801F94: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801F98: beq         $a0, $zero, L_80801FA8
    if (ctx->r4 == 0) {
        // 0x80801F9C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80801FA8;
    }
    // 0x80801F9C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80801FA0: bnel        $s2, $a0, L_80801F8C
    if (ctx->r18 != ctx->r4) {
        // 0x80801FA4: sb          $a0, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r4;
            goto L_80801F8C;
    }
    goto skip_0;
    // 0x80801FA4: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    skip_0:
L_80801FA8:
    // 0x80801FA8: addu        $t8, $a2, $s1
    ctx->r24 = ADD32(ctx->r6, ctx->r17);
    // 0x80801FAC: sb          $zero, 0x1($t8)
    MEM_B(0X1, ctx->r24) = 0;
    // 0x80801FB0: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
    // 0x80801FB4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80801FB8: addiu       $s3, $s3, 0x1E
    ctx->r19 = ADD32(ctx->r19, 0X1E);
    // 0x80801FBC: beq         $t9, $zero, L_80801FCC
    if (ctx->r25 == 0) {
        // 0x80801FC0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80801FCC;
    }
    // 0x80801FC0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801FC4: bnel        $s4, $s6, L_80801F60
    if (ctx->r20 != ctx->r22) {
        // 0x80801FC8: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80801F60;
    }
    goto skip_1;
    // 0x80801FC8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_1:
L_80801FCC:
    // 0x80801FCC: slti        $at, $s4, 0x3
    ctx->r1 = SIGNED(ctx->r20) < 0X3 ? 1 : 0;
    // 0x80801FD0: beq         $at, $zero, L_80802000
    if (ctx->r1 == 0) {
        // 0x80801FD4: sll         $s3, $s4, 4
        ctx->r19 = S32(ctx->r20 << 4);
            goto L_80802000;
    }
    // 0x80801FD4: sll         $s3, $s4, 4
    ctx->r19 = S32(ctx->r20 << 4);
    // 0x80801FD8: subu        $s3, $s3, $s4
    ctx->r19 = SUB32(ctx->r19, ctx->r20);
    // 0x80801FDC: sll         $s3, $s3, 1
    ctx->r19 = S32(ctx->r19 << 1);
L_80801FE0:
    // 0x80801FE0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80801FE4: jal         0x80100094
    // 0x80801FE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80801FE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80801FEC: addu        $t0, $v0, $s3
    ctx->r8 = ADD32(ctx->r2, ctx->r19);
    // 0x80801FF0: addiu       $s3, $s3, 0x1E
    ctx->r19 = ADD32(ctx->r19, 0X1E);
    // 0x80801FF4: slti        $at, $s3, 0x5A
    ctx->r1 = SIGNED(ctx->r19) < 0X5A ? 1 : 0;
    // 0x80801FF8: bne         $at, $zero, L_80801FE0
    if (ctx->r1 != 0) {
        // 0x80801FFC: sb          $zero, 0x21C($t0)
        MEM_B(0X21C, ctx->r8) = 0;
            goto L_80801FE0;
    }
    // 0x80801FFC: sb          $zero, 0x21C($t0)
    MEM_B(0X21C, ctx->r8) = 0;
L_80802000:
    // 0x80802000: jal         0x80088728
    // 0x80802004: addiu       $a0, $zero, 0x186D
    ctx->r4 = ADD32(0, 0X186D);
    _gldbstring_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80802004: addiu       $a0, $zero, 0x186D
    ctx->r4 = ADD32(0, 0X186D);
    after_5:
    // 0x80802008: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8080200C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802010: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80802014: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80802018: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8080201C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80802020: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80802024: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80802028: jr          $ra
    // 0x8080202C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8080202C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _sumissilehome_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A798: syscall     850
    recomp_syscall_handler(rdram, ctx, 0x8008A798);
    return;
    // 0x8008A79C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _gcskyDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088068: syscall     667
    recomp_syscall_handler(rdram, ctx, 0x80088068);
    return;
    // 0x8008806C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808002A0_chbilldrillplate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808002A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002A8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x808002AC: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    // 0x808002B0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x808002B4: jal         0x80089C40
    // 0x808002B8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    _subaddiefind_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808002B8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x808002BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808002C0: blez        $v0, L_80800300
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808002C4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800300;
    }
    // 0x808002C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002C8: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x808002CC: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x808002D0: addu        $a1, $t7, $v0
    ctx->r5 = ADD32(ctx->r15, ctx->r2);
    // 0x808002D4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
L_808002D8:
    // 0x808002D8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808002DC: lhu         $t9, 0x72($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X72);
    // 0x808002E0: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x808002E4: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x808002E8: bnel        $at, $zero, L_808002F8
    if (ctx->r1 != 0) {
        // 0x808002EC: sltu        $at, $v0, $a1
        ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
            goto L_808002F8;
    }
    goto skip_0;
    // 0x808002EC: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    skip_0:
    // 0x808002F0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x808002F4: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
L_808002F8:
    // 0x808002F8: bnel        $at, $zero, L_808002D8
    if (ctx->r1 != 0) {
        // 0x808002FC: lw          $t8, 0x0($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X0);
            goto L_808002D8;
    }
    goto skip_1;
    // 0x808002FC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    skip_1:
L_80800300:
    // 0x80800300: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800304: beq         $a0, $at, L_80800314
    if (ctx->r4 == ctx->r1) {
        // 0x80800308: nop
    
            goto L_80800314;
    }
    // 0x80800308: nop

    // 0x8080030C: bnel        $a0, $zero, L_8080034C
    if (ctx->r4 != 0) {
        // 0x80800310: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080034C;
    }
    goto skip_2;
    // 0x80800310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
L_80800314:
    // 0x80800314: jal         0x80800FCC
    // 0x80800318: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80800FCC_chbilldrillplate(rdram, ctx);
        goto after_1;
    // 0x80800318: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x8080031C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800320: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800324: bnel        $a0, $zero, L_80800340
    if (ctx->r4 != 0) {
        // 0x80800328: lhu         $a0, 0x2($v1)
        ctx->r4 = MEM_HU(ctx->r3, 0X2);
            goto L_80800340;
    }
    goto skip_3;
    // 0x80800328: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    skip_3:
    // 0x8080032C: lhu         $a0, 0xC($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0XC);
    // 0x80800330: jal         0x800DA544
    // 0x80800334: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x80800334: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800338: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8080033C: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
L_80800340:
    // 0x80800340: jal         0x800887D8
    // 0x80800344: lhu         $a1, 0xE($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0XE);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80800344: lhu         $a1, 0xE($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0XE);
    after_3:
    // 0x80800348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080034C:
    // 0x8080034C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800350: jr          $ra
    // 0x80800354: nop

    return;
    // 0x80800354: nop

;}
RECOMP_FUNC void func_80020C74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020C74: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80020C78: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80020C7C: lw          $t6, -0x15DC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X15DC);
    // 0x80020C80: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x80020C84: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80020C88: jr          $ra
    // 0x80020C8C: lhu         $v0, 0x0($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X0);
    return;
    // 0x80020C8C: lhu         $v0, 0x0($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X0);
;}
RECOMP_FUNC void func_80801E98_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801E98: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801E9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801EA0: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80801EA4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80801EA8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80801EAC: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80801EB0: bltz        $t8, L_80802004
    if (SIGNED(ctx->r24) < 0) {
        // 0x80801EB4: addiu       $a1, $zero, 0xFA
        ctx->r5 = ADD32(0, 0XFA);
            goto L_80802004;
    }
    // 0x80801EB4: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x80801EB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801EBC: jal         0x8010CAC0
    // 0x80801EC0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_8010CAC0(rdram, ctx);
        goto after_0;
    // 0x80801EC0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80801EC4: beql        $v0, $zero, L_80802008
    if (ctx->r2 == 0) {
        // 0x80801EC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802008;
    }
    goto skip_0;
    // 0x80801EC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801ECC: jal         0x800DB9B0
    // 0x80801ED0: nop

    func_800DB9B0(rdram, ctx);
        goto after_1;
    // 0x80801ED0: nop

    after_1:
    // 0x80801ED4: bne         $v0, $zero, L_80802004
    if (ctx->r2 != 0) {
        // 0x80801ED8: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_80802004;
    }
    // 0x80801ED8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80801EDC: lw          $t0, 0x64($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X64);
    // 0x80801EE0: addiu       $a0, $zero, 0x413
    ctx->r4 = ADD32(0, 0X413);
    // 0x80801EE4: sll         $t2, $t0, 11
    ctx->r10 = S32(ctx->r8 << 11);
    // 0x80801EE8: bgez        $t2, L_80801FBC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80801EEC: nop
    
            goto L_80801FBC;
    }
    // 0x80801EEC: nop

    // 0x80801EF0: jal         0x800DA298
    // 0x80801EF4: addiu       $a0, $zero, 0x414
    ctx->r4 = ADD32(0, 0X414);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80801EF4: addiu       $a0, $zero, 0x414
    ctx->r4 = ADD32(0, 0X414);
    after_2:
    // 0x80801EF8: bne         $v0, $zero, L_80801F30
    if (ctx->r2 != 0) {
        // 0x80801EFC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80801F30;
    }
    // 0x80801EFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801F00: jal         0x8008FA2C
    // 0x80801F04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008FA2C(rdram, ctx);
        goto after_3;
    // 0x80801F04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80801F08: beql        $v0, $zero, L_80802008
    if (ctx->r2 == 0) {
        // 0x80801F0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802008;
    }
    goto skip_1;
    // 0x80801F0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80801F10: jal         0x800DA544
    // 0x80801F14: addiu       $a0, $zero, 0x414
    ctx->r4 = ADD32(0, 0X414);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x80801F14: addiu       $a0, $zero, 0x414
    ctx->r4 = ADD32(0, 0X414);
    after_4:
    // 0x80801F18: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801F1C: addiu       $a1, $zero, 0x10DB
    ctx->r5 = ADD32(0, 0X10DB);
    // 0x80801F20: jal         0x8080105C
    // 0x80801F24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080105C_chflysaucer(rdram, ctx);
        goto after_5;
    // 0x80801F24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80801F28: b           L_80802008
    // 0x80801F2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802008;
    // 0x80801F2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801F30:
    // 0x80801F30: jal         0x80090178
    // 0x80801F34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090178(rdram, ctx);
        goto after_6;
    // 0x80801F34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80801F38: beq         $v0, $zero, L_80802004
    if (ctx->r2 == 0) {
        // 0x80801F3C: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_80802004;
    }
    // 0x80801F3C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80801F40: jal         0x800EE7F8
    // 0x80801F44: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80801F44: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_7:
    // 0x80801F48: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80801F4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801F50: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80801F54: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80801F58: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x80801F5C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80801F60: jal         0x8010CAC0
    // 0x80801F64: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    func_8010CAC0(rdram, ctx);
        goto after_8;
    // 0x80801F64: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x80801F68: beq         $v0, $zero, L_80801F84
    if (ctx->r2 == 0) {
        // 0x80801F6C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80801F84;
    }
    // 0x80801F6C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801F70: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801F74: jal         0x808012A4
    // 0x80801F78: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808012A4_chflysaucer(rdram, ctx);
        goto after_9;
    // 0x80801F78: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_9:
    // 0x80801F7C: b           L_80802008
    // 0x80801F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802008;
    // 0x80801F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801F84:
    // 0x80801F84: jal         0x8008FA60
    // 0x80801F88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008FA60(rdram, ctx);
        goto after_10;
    // 0x80801F88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80801F8C: beq         $v0, $zero, L_80802004
    if (ctx->r2 == 0) {
        // 0x80801F90: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80802004;
    }
    // 0x80801F90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801F94: jal         0x80016B30
    // 0x80801F98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80016B30(rdram, ctx);
        goto after_11;
    // 0x80801F98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80801F9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801FA0: bne         $v0, $at, L_80802004
    if (ctx->r2 != ctx->r1) {
        // 0x80801FA4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80802004;
    }
    // 0x80801FA4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801FA8: addiu       $a1, $zero, 0x10DC
    ctx->r5 = ADD32(0, 0X10DC);
    // 0x80801FAC: jal         0x8080105C
    // 0x80801FB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080105C_chflysaucer(rdram, ctx);
        goto after_12;
    // 0x80801FB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x80801FB4: b           L_80802008
    // 0x80801FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802008;
    // 0x80801FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801FBC:
    // 0x80801FBC: jal         0x800DA9E4
    // 0x80801FC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_13;
    // 0x80801FC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80801FC4: bne         $v0, $zero, L_80801FE4
    if (ctx->r2 != 0) {
        // 0x80801FC8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80801FE4;
    }
    // 0x80801FC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801FCC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801FD0: addiu       $a1, $zero, 0x10DD
    ctx->r5 = ADD32(0, 0X10DD);
    // 0x80801FD4: jal         0x8080105C
    // 0x80801FD8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080105C_chflysaucer(rdram, ctx);
        goto after_14;
    // 0x80801FD8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
    // 0x80801FDC: b           L_80802008
    // 0x80801FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802008;
    // 0x80801FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801FE4:
    // 0x80801FE4: jal         0x80016B30
    // 0x80801FE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80016B30(rdram, ctx);
        goto after_15;
    // 0x80801FE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80801FEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801FF0: bne         $v0, $at, L_80802004
    if (ctx->r2 != ctx->r1) {
        // 0x80801FF4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80802004;
    }
    // 0x80801FF4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801FF8: addiu       $a1, $zero, 0x10DE
    ctx->r5 = ADD32(0, 0X10DE);
    // 0x80801FFC: jal         0x8080105C
    // 0x80802000: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080105C_chflysaucer(rdram, ctx);
        goto after_16;
    // 0x80802000: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_16:
L_80802004:
    // 0x80802004: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802008:
    // 0x80802008: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080200C: jr          $ra
    // 0x80802010: nop

    return;
    // 0x80802010: nop

;}
RECOMP_FUNC void func_800D92F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D92F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D92F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D92FC: jal         0x800F8AA4
    // 0x800D9300: nop

    func_800F8AA4(rdram, ctx);
        goto after_0;
    // 0x800D9300: nop

    after_0:
    // 0x800D9304: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800D9308: jal         0x800F8DA8
    // 0x800D930C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F8DA8(rdram, ctx);
        goto after_1;
    // 0x800D930C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800D9310: beql        $v0, $zero, L_800D9324
    if (ctx->r2 == 0) {
        // 0x800D9314: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D9324;
    }
    goto skip_0;
    // 0x800D9314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D9318: jal         0x800F8E78
    // 0x800D931C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800F8E78(rdram, ctx);
        goto after_2;
    // 0x800D931C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x800D9320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D9324:
    // 0x800D9324: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D9328: jr          $ra
    // 0x800D932C: nop

    return;
    // 0x800D932C: nop

;}
RECOMP_FUNC void func_80805F30_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805F30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80805F34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80805F38: beq         $a1, $zero, L_80805F64
    if (ctx->r5 == 0) {
        // 0x80805F3C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80805F64;
    }
    // 0x80805F3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80805F40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80805F44: beq         $a1, $at, L_80805F7C
    if (ctx->r5 == ctx->r1) {
        // 0x80805F48: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80805F7C;
    }
    // 0x80805F48: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80805F4C: beq         $a1, $at, L_80805F94
    if (ctx->r5 == ctx->r1) {
        // 0x80805F50: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80805F94;
    }
    // 0x80805F50: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80805F54: beq         $a1, $at, L_80805FAC
    if (ctx->r5 == ctx->r1) {
        // 0x80805F58: nop
    
            goto L_80805FAC;
    }
    // 0x80805F58: nop

    // 0x80805F5C: b           L_80805FC0
    // 0x80805F60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80805FC0;
    // 0x80805F60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80805F64:
    // 0x80805F64: jal         0x80088350
    // 0x80805F68: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    _gcstatusDll_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80805F68: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80805F6C: jal         0x80088348
    // 0x80805F70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcstatusDll_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80805F70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80805F74: b           L_80805FC0
    // 0x80805F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80805FC0;
    // 0x80805F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80805F7C:
    // 0x80805F7C: jal         0x80088350
    // 0x80805F80: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    _gcstatusDll_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80805F80: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_2:
    // 0x80805F84: jal         0x80088348
    // 0x80805F88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcstatusDll_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x80805F88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80805F8C: b           L_80805FC0
    // 0x80805F90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80805FC0;
    // 0x80805F90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80805F94:
    // 0x80805F94: jal         0x80088350
    // 0x80805F98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcstatusDll_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80805F98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80805F9C: jal         0x80088348
    // 0x80805FA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    _gcstatusDll_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x80805FA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x80805FA4: b           L_80805FC0
    // 0x80805FA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80805FC0;
    // 0x80805FA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80805FAC:
    // 0x80805FAC: jal         0x80088350
    // 0x80805FB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcstatusDll_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x80805FB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80805FB4: jal         0x80088348
    // 0x80805FB8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    _gcstatusDll_entrypoint_7(rdram, ctx);
        goto after_7;
    // 0x80805FB8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_7:
    // 0x80805FBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80805FC0:
    // 0x80805FC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80805FC4: jr          $ra
    // 0x80805FC8: nop

    return;
    // 0x80805FC8: nop

;}
RECOMP_FUNC void func_80017D74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017D74: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80017D78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80017D7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80017D80: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80017D84: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80017D88: jal         0x80017810
    // 0x80017D8C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_80017810(rdram, ctx);
        goto after_0;
    // 0x80017D8C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x80017D90: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x80017D94: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80017D98: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80017D9C: beq         $t6, $zero, L_80017E8C
    if (ctx->r14 == 0) {
        // 0x80017DA0: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80017E8C;
    }
    // 0x80017DA0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80017DA4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80017DA8: bne         $s0, $v0, L_80017DD4
    if (ctx->r16 != ctx->r2) {
        // 0x80017DAC: sll         $v1, $a0, 2
        ctx->r3 = S32(ctx->r4 << 2);
            goto L_80017DD4;
    }
    // 0x80017DAC: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x80017DB0: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x80017DB4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017DB8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80017DBC: sw          $v0, -0x5160($at)
    MEM_W(-0X5160, ctx->r1) = ctx->r2;
    // 0x80017DC0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017DC4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80017DC8: sw          $zero, -0x5148($at)
    MEM_W(-0X5148, ctx->r1) = 0;
    // 0x80017DCC: b           L_80017EAC
    // 0x80017DD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80017EAC;
    // 0x80017DD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80017DD4:
    // 0x80017DD4: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80017DD8: addiu       $t7, $t7, -0x5160
    ctx->r15 = ADD32(ctx->r15, -0X5160);
    // 0x80017DDC: addu        $a2, $v1, $t7
    ctx->r6 = ADD32(ctx->r3, ctx->r15);
    // 0x80017DE0: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80017DE4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80017DE8: beq         $s0, $t8, L_80017E84
    if (ctx->r16 == ctx->r24) {
        // 0x80017DEC: nop
    
            goto L_80017E84;
    }
    // 0x80017DEC: nop

    // 0x80017DF0: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80017DF4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80017DF8: jal         0x800260B0
    // 0x80017DFC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_800260B0(rdram, ctx);
        goto after_1;
    // 0x80017DFC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_1:
    // 0x80017E00: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80017E04: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80017E08: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80017E0C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80017E10: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80017E14: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80017E18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80017E1C: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80017E20: bc1f        L_80017E40
    if (!c1cs) {
        // 0x80017E24: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80017E40;
    }
    // 0x80017E24: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80017E28: jal         0x80026330
    // 0x80017E2C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80026330(rdram, ctx);
        goto after_2;
    // 0x80017E2C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_2:
    // 0x80017E30: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80017E34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80017E38: b           L_80017EAC
    // 0x80017E3C: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
        goto L_80017EAC;
    // 0x80017E3C: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
L_80017E40:
    // 0x80017E40: beq         $at, $zero, L_80017E50
    if (ctx->r1 == 0) {
        // 0x80017E44: subu        $a0, $v0, $s0
        ctx->r4 = SUB32(ctx->r2, ctx->r16);
            goto L_80017E50;
    }
    // 0x80017E44: subu        $a0, $v0, $s0
    ctx->r4 = SUB32(ctx->r2, ctx->r16);
    // 0x80017E48: b           L_80017E50
    // 0x80017E4C: subu        $a0, $s0, $v0
    ctx->r4 = SUB32(ctx->r16, ctx->r2);
        goto L_80017E50;
    // 0x80017E4C: subu        $a0, $s0, $v0
    ctx->r4 = SUB32(ctx->r16, ctx->r2);
L_80017E50:
    // 0x80017E50: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80017E54: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80017E58: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x80017E5C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017E60: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80017E64: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
    // 0x80017E68: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80017E6C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80017E70: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80017E74: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80017E78: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x80017E7C: nop

    // 0x80017E80: sw          $t0, -0x5148($at)
    MEM_W(-0X5148, ctx->r1) = ctx->r8;
L_80017E84:
    // 0x80017E84: b           L_80017EAC
    // 0x80017E88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80017EAC;
    // 0x80017E88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80017E8C:
    // 0x80017E8C: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x80017E90: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017E94: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80017E98: sw          $v0, -0x5160($at)
    MEM_W(-0X5160, ctx->r1) = ctx->r2;
    // 0x80017E9C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017EA0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80017EA4: sw          $zero, -0x5148($at)
    MEM_W(-0X5148, ctx->r1) = 0;
    // 0x80017EA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80017EAC:
    // 0x80017EAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80017EB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80017EB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80017EB8: jr          $ra
    // 0x80017EBC: nop

    return;
    // 0x80017EBC: nop

;}
RECOMP_FUNC void func_80091E80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091E80: lw          $v1, 0x48($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X48);
    // 0x80091E84: lbu         $t6, 0x3($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X3);
    // 0x80091E88: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80091E8C: lbu         $t8, -0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, -0X1);
    // 0x80091E90: and         $t9, $t8, $a1
    ctx->r25 = ctx->r24 & ctx->r5;
    // 0x80091E94: xor         $v0, $a1, $t9
    ctx->r2 = ctx->r5 ^ ctx->r25;
    // 0x80091E98: jr          $ra
    // 0x80091E9C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x80091E9C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_80114FA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114FA4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80114FA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80114FAC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80114FB0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80114FB4: lbu         $t6, 0xC($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XC);
    // 0x80114FB8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80114FBC: beql        $t6, $zero, L_801150E0
    if (ctx->r14 == 0) {
        // 0x80114FC0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801150E0;
    }
    goto skip_0;
    // 0x80114FC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80114FC4: lbu         $t7, 0xE($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XE);
    // 0x80114FC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80114FCC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80114FD0: beq         $t7, $zero, L_801150DC
    if (ctx->r15 == 0) {
        // 0x80114FD4: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_801150DC;
    }
    // 0x80114FD4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80114FD8: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80114FDC: lwc1        $f4, 0x6600($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6600);
    // 0x80114FE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80114FE4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80114FE8: nop

    // 0x80114FEC: bc1f        L_80115004
    if (!c1cs) {
        // 0x80114FF0: nop
    
            goto L_80115004;
    }
    // 0x80114FF0: nop

    // 0x80114FF4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80114FF8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80114FFC: b           L_80115010
    // 0x80115000: nop

        goto L_80115010;
    // 0x80115000: nop

L_80115004:
    // 0x80115004: lwc1        $f6, 0x6604($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6604);
    // 0x80115008: mul.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8011500C: nop

L_80115010:
    // 0x80115010: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80115014: lwc1        $f8, 0x6608($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6608);
    // 0x80115018: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8011501C: addiu       $a3, $a3, 0x4A50
    ctx->r7 = ADD32(ctx->r7, 0X4A50);
    // 0x80115020: mul.s       $f0, $f2, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80115024: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_80115028:
    // 0x80115028: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8011502C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80115030: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80115034: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80115038: addu        $t0, $a3, $t9
    ctx->r8 = ADD32(ctx->r7, ctx->r25);
    // 0x8011503C: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x80115040: lbu         $v0, 0x1($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X1);
    // 0x80115044: negu        $t2, $v0
    ctx->r10 = SUB32(0, ctx->r2);
    // 0x80115048: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8011504C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80115050: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80115054: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80115058: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8011505C: bgezl       $v0, L_80115074
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80115060: add.s       $f10, $f18, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
            goto L_80115074;
    }
    goto skip_1;
    // 0x80115060: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    skip_1:
    // 0x80115064: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80115068: nop

    // 0x8011506C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80115070: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
L_80115074:
    // 0x80115074: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80115078: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8011507C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80115080: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x80115084: bne         $v1, $a1, L_80115028
    if (ctx->r3 != ctx->r5) {
        // 0x80115088: sw          $t4, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->r12;
            goto L_80115028;
    }
    // 0x80115088: sw          $t4, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r12;
    // 0x8011508C: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x80115090: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80115094: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80115098: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8011509C: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x801150A0: lbu         $t8, 0x4($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X4);
    // 0x801150A4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x801150A8: bgez        $t8, L_801150BC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801150AC: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801150BC;
    }
    // 0x801150AC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801150B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801150B4: nop

    // 0x801150B8: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
L_801150BC:
    // 0x801150BC: mul.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x801150C0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x801150C4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x801150C8: add.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x801150CC: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801150D0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801150D4: jal         0x800B99CC
    // 0x801150D8: nop

    func_800B99CC(rdram, ctx);
        goto after_0;
    // 0x801150D8: nop

    after_0:
L_801150DC:
    // 0x801150DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801150E0:
    // 0x801150E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801150E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801150E8: jr          $ra
    // 0x801150EC: nop

    return;
    // 0x801150EC: nop

;}
RECOMP_FUNC void gsmaker_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080005C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800060: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800064: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800068: jal         0x8001ACCC
    // 0x8080006C: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x8080006C: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_0:
    // 0x80800070: bne         $v0, $zero, L_80800080
    if (ctx->r2 != 0) {
        // 0x80800074: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80800080;
    }
    // 0x80800074: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800078: b           L_808000DC
    // 0x8080007C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000DC;
    // 0x8080007C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800080:
    // 0x80800080: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80800084: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800088: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x8080008C: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x80800090: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x80800094: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800098: sh          $t7, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r15;
    // 0x8080009C: jal         0x800D674C
    // 0x808000A0: lh          $a0, 0x20($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X20);
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x808000A0: lh          $a0, 0x20($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X20);
    after_1:
    // 0x808000A4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x808000A8: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x808000AC: jal         0x800D70D0
    // 0x808000B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D70D0(rdram, ctx);
        goto after_2;
    // 0x808000B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x808000B4: jal         0x800D71F4
    // 0x808000B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D71F4(rdram, ctx);
        goto after_3;
    // 0x808000B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x808000BC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x808000C0: beq         $t8, $zero, L_808000D0
    if (ctx->r24 == 0) {
        // 0x808000C4: nop
    
            goto L_808000D0;
    }
    // 0x808000C4: nop

    // 0x808000C8: b           L_808000DC
    // 0x808000CC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_808000DC;
    // 0x808000CC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_808000D0:
    // 0x808000D0: jal         0x8001B084
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    heap_free(rdram, ctx);
        goto after_4;
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000DC:
    // 0x808000DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000E8: jr          $ra
    // 0x808000EC: nop

    return;
    // 0x808000EC: nop

;}
RECOMP_FUNC void func_80095870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095870: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x80095874: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80095878: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x8009587C: lw          $t7, 0x94($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X94);
    // 0x80095880: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80095884: jr          $ra
    // 0x80095888: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    return;
    // 0x80095888: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_80020760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020760: beq         $a0, $zero, L_80020778
    if (ctx->r4 == 0) {
        // 0x80020764: nop
    
            goto L_80020778;
    }
    // 0x80020764: nop

    // 0x80020768: jr          $ra
    // 0x8002076C: lbu         $v0, 0x45($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X45);
    return;
    // 0x8002076C: lbu         $v0, 0x45($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X45);
    // 0x80020770: b           L_80020780
    // 0x80020774: nop

        goto L_80020780;
    // 0x80020774: nop

L_80020778:
    // 0x80020778: jr          $ra
    // 0x8002077C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002077C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80020780:
    // 0x80020780: jr          $ra
    // 0x80020784: nop

    return;
    // 0x80020784: nop

;}
RECOMP_FUNC void bsrest_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808007EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007F0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808007F4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808007F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808007FC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800800: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800804: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800808: jal         0x8009FFD8
    // 0x8080080C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_0;
    // 0x8080080C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x80800810: jal         0x80800000
    // 0x80800814: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800000_bsrest(rdram, ctx);
        goto after_1;
    // 0x80800814: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800818: jal         0x80800080
    // 0x8080081C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    static_344_80800080(rdram, ctx);
        goto after_2;
    // 0x8080081C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800820: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80800824: beql        $t7, $zero, L_80800838
    if (ctx->r15 == 0) {
        // 0x80800828: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800838;
    }
    goto skip_0;
    // 0x80800828: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080082C: jal         0x80800188
    // 0x80800830: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bsrest_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800830: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800834: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800838:
    // 0x80800838: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080083C: jr          $ra
    // 0x80800840: nop

    return;
    // 0x80800840: nop

;}
RECOMP_FUNC void bastick_func_8009EEF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EEF8: lw          $t6, 0x128($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X128);
    // 0x8009EEFC: jr          $ra
    // 0x8009EF00: lbu         $v0, 0x65($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X65);
    return;
    // 0x8009EF00: lbu         $v0, 0x65($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X65);
;}
RECOMP_FUNC void _subaddiefade_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089CB8: syscall     808
    recomp_syscall_handler(rdram, ctx, 0x80089CB8);
    return;
    // 0x80089CBC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _bssplat_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083A80: syscall     88
    recomp_syscall_handler(rdram, ctx, 0x80083A80);
    return;
    // 0x80083A84: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8008E9A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E9A0: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x8008E9A4: jr          $ra
    // 0x8008E9A8: sw          $a1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r5;
    return;
    // 0x8008E9A8: sw          $a1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_80800000_chfactoryempspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: jal         0x80800A08
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800A08_chfactoryempspell(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800014: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800018: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080001C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800020: sltiu       $at, $t8, 0xB
    ctx->r1 = ctx->r24 < 0XB ? 1 : 0;
    // 0x80800024: beq         $at, $zero, L_8080061C
    if (ctx->r1 == 0) {
        // 0x80800028: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8080061C;
    }
    // 0x80800028: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080002C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2304, 0X2040) << 16);
    // 0x80800030: addu        $at, $at, $t8
    gpr jr_addend_80800038 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800034: lw          $t8, 0x2040($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2304, 0X2040));
    // 0x80800038: jr          $t8
    // 0x8080003C: nop

    switch (jr_addend_80800038 >> 2) {
        case 0: goto L_8080061C; break;
        case 1: goto L_80800040; break;
        case 2: goto L_808000C4; break;
        case 3: goto L_8080011C; break;
        case 4: goto L_80800188; break;
        case 5: goto L_80800248; break;
        case 6: goto L_808002CC; break;
        case 7: goto L_808003B8; break;
        case 8: goto L_80800434; break;
        case 9: goto L_808004F8; break;
        case 10: goto L_808005A0; break;
        default: switch_error(__func__, 0x80800038, 0x80802040);
    }
    // 0x8080003C: nop

L_80800040:
    // 0x80800040: jal         0x800DA298
    // 0x80800044: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800044: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_1:
    // 0x80800048: beql        $v0, $zero, L_80800620
    if (ctx->r2 == 0) {
        // 0x8080004C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800620;
    }
    goto skip_0;
    // 0x8080004C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800050: jal         0x80801F30
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801F30_chfactoryempspell(rdram, ctx);
        goto after_2;
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080005C: jal         0x80100094
    // 0x80800060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80800060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800064: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800068: jal         0x800898B8
    // 0x8080006C: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_15(rdram, ctx);
        goto after_4;
    // 0x8080006C: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_4:
    // 0x80800070: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800078: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8080007C: jal         0x80085708
    // 0x80800080: addiu       $a3, $zero, 0x810
    ctx->r7 = ADD32(0, 0X810);
    _capod_entrypoint_13(rdram, ctx);
        goto after_5;
    // 0x80800080: addiu       $a3, $zero, 0x810
    ctx->r7 = ADD32(0, 0X810);
    after_5:
    // 0x80800084: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80800088: addiu       $a0, $zero, 0xA05
    ctx->r4 = ADD32(0, 0XA05);
    // 0x8080008C: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x80800090: jal         0x800DA544
    // 0x80800094: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    func_800DA544(rdram, ctx);
        goto after_6;
    // 0x80800094: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    after_6:
    // 0x80800098: addiu       $a0, $zero, 0x2B0
    ctx->r4 = ADD32(0, 0X2B0);
    // 0x8080009C: addiu       $a1, $zero, 0xBB
    ctx->r5 = ADD32(0, 0XBB);
    // 0x808000A0: jal         0x80101180
    // 0x808000A4: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_80101180(rdram, ctx);
        goto after_7;
    // 0x808000A4: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_7:
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000AC: jal         0x80101FDC
    // 0x808000B0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x808000B0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x808000B4: jal         0x800DA544
    // 0x808000B8: addiu       $a0, $zero, 0x57F
    ctx->r4 = ADD32(0, 0X57F);
    func_800DA544(rdram, ctx);
        goto after_9;
    // 0x808000B8: addiu       $a0, $zero, 0x57F
    ctx->r4 = ADD32(0, 0X57F);
    after_9:
    // 0x808000BC: b           L_80800620
    // 0x808000C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800620;
    // 0x808000C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000C4:
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C8: jal         0x80100094
    // 0x808000CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_10;
    // 0x808000CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x808000D0: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808000DC: jal         0x80801130
    // 0x808000E0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_80801130_chfactoryempspell(rdram, ctx);
        goto after_11;
    // 0x808000E0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_11:
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: jal         0x80801C00
    // 0x808000EC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80801C00_chfactoryempspell(rdram, ctx);
        goto after_12;
    // 0x808000EC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_12:
    // 0x808000F0: jal         0x80089918
    // 0x808000F4: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_13;
    // 0x808000F4: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    after_13:
    // 0x808000F8: beq         $v0, $zero, L_8080061C
    if (ctx->r2 == 0) {
        // 0x808000FC: lw          $a0, 0x90($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X90);
            goto L_8080061C;
    }
    // 0x808000FC: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x80800100: jal         0x800898D0
    // 0x80800104: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_18(rdram, ctx);
        goto after_14;
    // 0x80800104: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_14:
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: jal         0x80101FDC
    // 0x80800110: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_15;
    // 0x80800110: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_15:
    // 0x80800114: b           L_80800620
    // 0x80800118: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800620;
    // 0x80800118: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080011C:
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800120: jal         0x80100094
    // 0x80800124: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_16;
    // 0x80800124: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80800128: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800130: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800134: jal         0x80801130
    // 0x80800138: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    func_80801130_chfactoryempspell(rdram, ctx);
        goto after_17;
    // 0x80800138: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    after_17:
    // 0x8080013C: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x80800140: jal         0x80089868
    // 0x80800144: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    _sumumbofx_entrypoint_5(rdram, ctx);
        goto after_18;
    // 0x80800144: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    after_18:
    // 0x80800148: jal         0x80089910
    // 0x8080014C: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    _sumumbofx_entrypoint_26(rdram, ctx);
        goto after_19;
    // 0x8080014C: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    after_19:
    // 0x80800150: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800154: jal         0x80801C00
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C00_chfactoryempspell(rdram, ctx);
        goto after_20;
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8080015C: jal         0x80089918
    // 0x80800160: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_21;
    // 0x80800160: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    after_21:
    // 0x80800164: beq         $v0, $zero, L_8080061C
    if (ctx->r2 == 0) {
        // 0x80800168: lw          $a0, 0x8C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X8C);
            goto L_8080061C;
    }
    // 0x80800168: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x8080016C: jal         0x800898C8
    // 0x80800170: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    _sumumbofx_entrypoint_17(rdram, ctx);
        goto after_22;
    // 0x80800170: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_22:
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: jal         0x80101FDC
    // 0x8080017C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_23;
    // 0x8080017C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_23:
    // 0x80800180: b           L_80800620
    // 0x80800184: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800620;
    // 0x80800184: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800188:
    // 0x80800188: addiu       $a0, $zero, 0x3BA
    ctx->r4 = ADD32(0, 0X3BA);
    // 0x8080018C: jal         0x80089C30
    // 0x80800190: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_24;
    // 0x80800190: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    after_24:
    // 0x80800194: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x80800198: addiu       $a0, $zero, 0x3BA
    ctx->r4 = ADD32(0, 0X3BA);
    // 0x8080019C: jal         0x80089C38
    // 0x808001A0: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    _subaddiefind_entrypoint_3(rdram, ctx);
        goto after_25;
    // 0x808001A0: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    after_25:
    // 0x808001A4: sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001AC: jal         0x80100094
    // 0x808001B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_26;
    // 0x808001B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x808001B4: lw          $t1, 0x84($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X84);
    // 0x808001B8: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808001C4: jal         0x80801130
    // 0x808001C8: lw          $a2, 0x34($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X34);
    func_80801130_chfactoryempspell(rdram, ctx);
        goto after_27;
    // 0x808001C8: lw          $a2, 0x34($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X34);
    after_27:
    // 0x808001CC: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D4: jal         0x80801C00
    // 0x808001D8: lw          $a1, 0x34($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X34);
    func_80801C00_chfactoryempspell(rdram, ctx);
        goto after_28;
    // 0x808001D8: lw          $a1, 0x34($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X34);
    after_28:
    // 0x808001DC: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x808001E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808001E4: lhu         $t3, 0x72($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X72);
    // 0x808001E8: srl         $t4, $t3, 10
    ctx->r12 = S32(U32(ctx->r11) >> 10);
    // 0x808001EC: bnel        $t4, $at, L_80800620
    if (ctx->r12 != ctx->r1) {
        // 0x808001F0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800620;
    }
    goto skip_1;
    // 0x808001F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808001F4: jal         0x80101FDC
    // 0x808001F8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_29;
    // 0x808001F8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_29:
    // 0x808001FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800200: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800204: lw          $t5, 0x84($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X84);
    // 0x80800208: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8080020C: swc1        $f4, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->f4.u32l;
    // 0x80800210: jal         0x80101FDC
    // 0x80800214: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    func_80101FDC(rdram, ctx);
        goto after_30;
    // 0x80800214: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    after_30:
    // 0x80800218: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080021C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800220: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800228: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8080022C: jal         0x80101FDC
    // 0x80800230: swc1        $f6, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f6.u32l;
    func_80101FDC(rdram, ctx);
        goto after_31;
    // 0x80800230: swc1        $f6, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f6.u32l;
    after_31:
    // 0x80800234: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x80800238: jal         0x800898E0
    // 0x8080023C: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    _sumumbofx_entrypoint_20(rdram, ctx);
        goto after_32;
    // 0x8080023C: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_32:
    // 0x80800240: b           L_80800620
    // 0x80800244: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800620;
    // 0x80800244: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800248:
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080024C: jal         0x80100094
    // 0x80800250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_33;
    // 0x80800250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_33:
    // 0x80800254: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080025C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800260: jal         0x80801130
    // 0x80800264: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_80801130_chfactoryempspell(rdram, ctx);
        goto after_34;
    // 0x80800264: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_34:
    // 0x80800268: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2304, 0X206C) << 16);
    // 0x8080026C: lwc1        $f12, 0x206C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2304, 0X206C));
    // 0x80800270: jal         0x808012C0
    // 0x80800274: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_808012C0_chfactoryempspell(rdram, ctx);
        goto after_35;
    // 0x80800274: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_35:
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080027C: jal         0x80801E9C
    // 0x80800280: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80801E9C_chfactoryempspell(rdram, ctx);
        goto after_36;
    // 0x80800280: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_36:
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800288: jal         0x80801C00
    // 0x8080028C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80801C00_chfactoryempspell(rdram, ctx);
        goto after_37;
    // 0x8080028C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_37:
    // 0x80800290: jal         0x80089918
    // 0x80800294: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_38;
    // 0x80800294: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_38:
    // 0x80800298: beql        $v0, $zero, L_80800620
    if (ctx->r2 == 0) {
        // 0x8080029C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800620;
    }
    goto skip_2;
    // 0x8080029C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x808002A0: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808002AC: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x808002B0: jal         0x80101FDC
    // 0x808002B4: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    func_80101FDC(rdram, ctx);
        goto after_39;
    // 0x808002B4: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    after_39:
    // 0x808002B8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x808002BC: jal         0x800898E0
    // 0x808002C0: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    _sumumbofx_entrypoint_20(rdram, ctx);
        goto after_40;
    // 0x808002C0: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_40:
    // 0x808002C4: b           L_80800620
    // 0x808002C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800620;
    // 0x808002C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002CC:
    // 0x808002CC: addiu       $a0, $zero, 0x3BA
    ctx->r4 = ADD32(0, 0X3BA);
    // 0x808002D0: jal         0x80089C30
    // 0x808002D4: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_41;
    // 0x808002D4: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    after_41:
    // 0x808002D8: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x808002DC: addiu       $a0, $zero, 0x3BA
    ctx->r4 = ADD32(0, 0X3BA);
    // 0x808002E0: jal         0x80089C38
    // 0x808002E4: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    _subaddiefind_entrypoint_3(rdram, ctx);
        goto after_42;
    // 0x808002E4: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    after_42:
    // 0x808002E8: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F0: jal         0x80100094
    // 0x808002F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_43;
    // 0x808002F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_43:
    // 0x808002F8: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x808002FC: jal         0x80089910
    // 0x80800300: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_26(rdram, ctx);
        goto after_44;
    // 0x80800300: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_44:
    // 0x80800304: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800308: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080030C: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800314: sub.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80800318: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    // 0x8080031C: swc1        $f2, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->f2.u32l;
    // 0x80800320: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x80800324: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800328: swc1        $f2, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f2.u32l;
    // 0x8080032C: jal         0x80801130
    // 0x80800330: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    func_80801130_chfactoryempspell(rdram, ctx);
        goto after_45;
    // 0x80800330: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_45:
    // 0x80800334: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2304, 0X2070) << 16);
    // 0x80800338: lwc1        $f12, 0x2070($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2304, 0X2070));
    // 0x8080033C: jal         0x808012C0
    // 0x80800340: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_808012C0_chfactoryempspell(rdram, ctx);
        goto after_46;
    // 0x80800340: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_46:
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800348: jal         0x80801E9C
    // 0x8080034C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    func_80801E9C_chfactoryempspell(rdram, ctx);
        goto after_47;
    // 0x8080034C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_47:
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800354: jal         0x80801C00
    // 0x80800358: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80801C00_chfactoryempspell(rdram, ctx);
        goto after_48;
    // 0x80800358: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_48:
    // 0x8080035C: jal         0x80089918
    // 0x80800360: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_49;
    // 0x80800360: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_49:
    // 0x80800364: beql        $v0, $zero, L_80800620
    if (ctx->r2 == 0) {
        // 0x80800368: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800620;
    }
    goto skip_3;
    // 0x80800368: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x8080036C: jal         0x80086B58
    // 0x80800370: nop

    _chmrtannoy_entrypoint_0(rdram, ctx);
        goto after_50;
    // 0x80800370: nop

    after_50:
    // 0x80800374: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800378: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080037C: addiu       $a1, $zero, 0x1339
    ctx->r5 = ADD32(0, 0X1339);
    // 0x80800380: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800384: jal         0x8008A208
    // 0x80800388: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_51;
    // 0x80800388: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_51:
    // 0x8080038C: jal         0x800DA544
    // 0x80800390: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    func_800DA544(rdram, ctx);
        goto after_52;
    // 0x80800390: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    after_52:
    // 0x80800394: jal         0x80086AF0
    // 0x80800398: nop

    _chglowbo_entrypoint_6(rdram, ctx);
        goto after_53;
    // 0x80800398: nop

    after_53:
    // 0x8080039C: jal         0x808016AC
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808016AC_chfactoryempspell(rdram, ctx);
        goto after_54;
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_54:
    // 0x808003A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A8: jal         0x80101FDC
    // 0x808003AC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80101FDC(rdram, ctx);
        goto after_55;
    // 0x808003AC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_55:
    // 0x808003B0: b           L_80800620
    // 0x808003B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800620;
    // 0x808003B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003B8:
    // 0x808003B8: addiu       $a0, $zero, 0x3BA
    ctx->r4 = ADD32(0, 0X3BA);
    // 0x808003BC: jal         0x80089C30
    // 0x808003C0: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_56;
    // 0x808003C0: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_56:
    // 0x808003C4: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x808003C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003CC: jal         0x80100094
    // 0x808003D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_57;
    // 0x808003D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_57:
    // 0x808003D4: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808003E0: jal         0x80801130
    // 0x808003E4: lw          $a2, 0x34($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X34);
    func_80801130_chfactoryempspell(rdram, ctx);
        goto after_58;
    // 0x808003E4: lw          $a2, 0x34($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X34);
    after_58:
    // 0x808003E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2304, 0X2074) << 16);
    // 0x808003EC: lwc1        $f12, 0x2074($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2304, 0X2074));
    // 0x808003F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2304, 0X2078) << 16);
    // 0x808003F4: jal         0x808012C0
    // 0x808003F8: lwc1        $f14, 0x2078($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2304, 0X2078));
    func_808012C0_chfactoryempspell(rdram, ctx);
        goto after_59;
    // 0x808003F8: lwc1        $f14, 0x2078($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2304, 0X2078));
    after_59:
    // 0x808003FC: jal         0x80801844
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801844_chfactoryempspell(rdram, ctx);
        goto after_60;
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_60:
    // 0x80800404: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080040C: jal         0x80801E9C
    // 0x80800410: lw          $a1, 0x34($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X34);
    func_80801E9C_chfactoryempspell(rdram, ctx);
        goto after_61;
    // 0x80800410: lw          $a1, 0x34($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X34);
    after_61:
    // 0x80800414: jal         0x800CEAA8
    // 0x80800418: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAA8(rdram, ctx);
        goto after_62;
    // 0x80800418: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_62:
    // 0x8080041C: beq         $v0, $zero, L_8080061C
    if (ctx->r2 == 0) {
        // 0x80800420: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080061C;
    }
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800424: jal         0x80101FDC
    // 0x80800428: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80101FDC(rdram, ctx);
        goto after_63;
    // 0x80800428: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_63:
    // 0x8080042C: b           L_80800620
    // 0x80800430: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800620;
    // 0x80800430: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800434:
    // 0x80800434: addiu       $a0, $zero, 0x3BA
    ctx->r4 = ADD32(0, 0X3BA);
    // 0x80800438: jal         0x80089C30
    // 0x8080043C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_64;
    // 0x8080043C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_64:
    // 0x80800440: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800448: jal         0x80100094
    // 0x8080044C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_65;
    // 0x8080044C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_65:
    // 0x80800450: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80800454: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080045C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800460: jal         0x80801130
    // 0x80800464: lw          $a2, 0x34($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X34);
    func_80801130_chfactoryempspell(rdram, ctx);
        goto after_66;
    // 0x80800464: lw          $a2, 0x34($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X34);
    after_66:
    // 0x80800468: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2304, 0X207C) << 16);
    // 0x8080046C: lwc1        $f12, 0x207C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2304, 0X207C));
    // 0x80800470: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2304, 0X2080) << 16);
    // 0x80800474: jal         0x808012C0
    // 0x80800478: lwc1        $f14, 0x2080($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2304, 0X2080));
    func_808012C0_chfactoryempspell(rdram, ctx);
        goto after_67;
    // 0x80800478: lwc1        $f14, 0x2080($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2304, 0X2080));
    after_67:
    // 0x8080047C: jal         0x80801844
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801844_chfactoryempspell(rdram, ctx);
        goto after_68;
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_68:
    // 0x80800484: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080048C: jal         0x80801E9C
    // 0x80800490: lw          $a1, 0x34($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X34);
    func_80801E9C_chfactoryempspell(rdram, ctx);
        goto after_69;
    // 0x80800490: lw          $a1, 0x34($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X34);
    after_69:
    // 0x80800494: jal         0x800DA298
    // 0x80800498: addiu       $a0, $zero, 0xA05
    ctx->r4 = ADD32(0, 0XA05);
    func_800DA298(rdram, ctx);
        goto after_70;
    // 0x80800498: addiu       $a0, $zero, 0xA05
    ctx->r4 = ADD32(0, 0XA05);
    after_70:
    // 0x8080049C: beq         $v0, $zero, L_808004CC
    if (ctx->r2 == 0) {
        // 0x808004A0: nop
    
            goto L_808004CC;
    }
    // 0x808004A0: nop

    // 0x808004A4: jal         0x800CEA84
    // 0x808004A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEA84(rdram, ctx);
        goto after_71;
    // 0x808004A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_71:
    // 0x808004AC: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x808004B0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808004B4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808004B8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808004BC: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x808004C0: nop

    // 0x808004C4: bc1fl       L_80800620
    if (!c1cs) {
        // 0x808004C8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800620;
    }
    goto skip_4;
    // 0x808004C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
L_808004CC:
    // 0x808004CC: jal         0x80089D48
    // 0x808004D0: lbu         $a0, 0x28($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X28);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_72;
    // 0x808004D0: lbu         $a0, 0x28($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X28);
    after_72:
    // 0x808004D4: sb          $v0, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r2;
    // 0x808004D8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x808004DC: jal         0x800898C0
    // 0x808004E0: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _sumumbofx_entrypoint_16(rdram, ctx);
        goto after_73;
    // 0x808004E0: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_73:
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E8: jal         0x80101FDC
    // 0x808004EC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80101FDC(rdram, ctx);
        goto after_74;
    // 0x808004EC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_74:
    // 0x808004F0: b           L_80800620
    // 0x808004F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800620;
    // 0x808004F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004F8:
    // 0x808004F8: addiu       $a0, $zero, 0x3BA
    ctx->r4 = ADD32(0, 0X3BA);
    // 0x808004FC: jal         0x80089C30
    // 0x80800500: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_75;
    // 0x80800500: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_75:
    // 0x80800504: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080050C: jal         0x80100094
    // 0x80800510: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_76;
    // 0x80800510: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_76:
    // 0x80800514: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80800518: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8080051C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800520: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800524: jal         0x80801130
    // 0x80800528: lw          $a2, 0x34($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X34);
    func_80801130_chfactoryempspell(rdram, ctx);
        goto after_77;
    // 0x80800528: lw          $a2, 0x34($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X34);
    after_77:
    // 0x8080052C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80800530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800534: jal         0x80801C00
    // 0x80800538: lw          $a1, 0x34($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X34);
    func_80801C00_chfactoryempspell(rdram, ctx);
        goto after_78;
    // 0x80800538: lw          $a1, 0x34($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X34);
    after_78:
    // 0x8080053C: jal         0x80801844
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801844_chfactoryempspell(rdram, ctx);
        goto after_79;
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_79:
    // 0x80800544: jal         0x80089918
    // 0x80800548: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_80;
    // 0x80800548: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_80:
    // 0x8080054C: beql        $v0, $zero, L_80800620
    if (ctx->r2 == 0) {
        // 0x80800550: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800620;
    }
    goto skip_5;
    // 0x80800550: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x80800554: jal         0x800DA298
    // 0x80800558: addiu       $a0, $zero, 0x329
    ctx->r4 = ADD32(0, 0X329);
    func_800DA298(rdram, ctx);
        goto after_81;
    // 0x80800558: addiu       $a0, $zero, 0x329
    ctx->r4 = ADD32(0, 0X329);
    after_81:
    // 0x8080055C: bne         $v0, $zero, L_80800570
    if (ctx->r2 != 0) {
        // 0x80800560: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800570;
    }
    // 0x80800560: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800564: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800568: jal         0x808012C0
    // 0x8080056C: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_808012C0_chfactoryempspell(rdram, ctx);
        goto after_82;
    // 0x8080056C: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_82:
L_80800570:
    // 0x80800570: jal         0x80801AB4
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801AB4_chfactoryempspell(rdram, ctx);
        goto after_83;
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_83:
    // 0x80800578: jal         0x80801E48
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801E48_chfactoryempspell(rdram, ctx);
        goto after_84;
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_84:
    // 0x80800580: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80800584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800588: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x8080058C: andi        $t9, $t8, 0xFFF7
    ctx->r25 = ctx->r24 & 0XFFF7;
    // 0x80800590: jal         0x80101FDC
    // 0x80800594: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    func_80101FDC(rdram, ctx);
        goto after_85;
    // 0x80800594: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    after_85:
    // 0x80800598: b           L_80800620
    // 0x8080059C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800620;
    // 0x8080059C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808005A0:
    // 0x808005A0: addiu       $a0, $zero, 0x3BA
    ctx->r4 = ADD32(0, 0X3BA);
    // 0x808005A4: jal         0x80089C30
    // 0x808005A8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_86;
    // 0x808005A8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_86:
    // 0x808005AC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x808005B0: addiu       $a0, $zero, 0x3BA
    ctx->r4 = ADD32(0, 0X3BA);
    // 0x808005B4: jal         0x80089C38
    // 0x808005B8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    _subaddiefind_entrypoint_3(rdram, ctx);
        goto after_87;
    // 0x808005B8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_87:
    // 0x808005BC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C4: jal         0x80089848
    // 0x808005C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sumumbofx_entrypoint_1(rdram, ctx);
        goto after_88;
    // 0x808005C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_88:
    // 0x808005CC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808005D0: jal         0x80101FDC
    // 0x808005D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_89;
    // 0x808005D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_89:
    // 0x808005D8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808005DC: jal         0x80101FDC
    // 0x808005E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_90;
    // 0x808005E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_90:
    // 0x808005E4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2304, 0X2084) << 16);
    // 0x808005E8: lwc1        $f0, 0x2084($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2304, 0X2084));
    // 0x808005EC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x808005F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808005F8: swc1        $f0, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->f0.u32l;
    // 0x808005FC: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80800600: jal         0x8008A4B0
    // 0x80800604: swc1        $f0, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->f0.u32l;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_91;
    // 0x80800604: swc1        $f0, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->f0.u32l;
    after_91:
    // 0x80800608: jal         0x800DA524
    // 0x8080060C: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA524(rdram, ctx);
        goto after_92;
    // 0x8080060C: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_92:
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800614: jal         0x80101FDC
    // 0x80800618: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_93;
    // 0x80800618: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_93:
L_8080061C:
    // 0x8080061C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800620:
    // 0x80800620: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800624: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // 0x80800628: jr          $ra
    // 0x8080062C: nop

    return;
    // 0x8080062C: nop

;}
RECOMP_FUNC void func_808004DC_chbkcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808004E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004E4: slti        $at, $a1, 0x53
    ctx->r1 = SIGNED(ctx->r5) < 0X53 ? 1 : 0;
    // 0x808004E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004F0: bne         $at, $zero, L_8080050C
    if (ctx->r1 != 0) {
        // 0x808004F4: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_8080050C;
    }
    // 0x808004F4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808004F8: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808004FC: beq         $a1, $at, L_808005F0
    if (ctx->r5 == ctx->r1) {
        // 0x80800500: nop
    
            goto L_808005F0;
    }
    // 0x80800500: nop

    // 0x80800504: b           L_8080073C
    // 0x80800508: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080073C;
    // 0x80800508: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080050C:
    // 0x8080050C: addiu       $t6, $a1, -0x2E
    ctx->r14 = ADD32(ctx->r5, -0X2E);
    // 0x80800510: sltiu       $at, $t6, 0x25
    ctx->r1 = ctx->r14 < 0X25 ? 1 : 0;
    // 0x80800514: beq         $at, $zero, L_80800738
    if (ctx->r1 == 0) {
        // 0x80800518: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800738;
    }
    // 0x80800518: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080051C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2464, 0X768) << 16);
    // 0x80800520: addu        $at, $at, $t6
    gpr jr_addend_80800528 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800524: lw          $t6, 0x768($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2464, 0X768));
    // 0x80800528: jr          $t6
    // 0x8080052C: nop

    switch (jr_addend_80800528 >> 2) {
        case 0: goto L_808006FC; break;
        case 1: goto L_80800738; break;
        case 2: goto L_80800738; break;
        case 3: goto L_80800738; break;
        case 4: goto L_80800738; break;
        case 5: goto L_80800738; break;
        case 6: goto L_80800738; break;
        case 7: goto L_80800738; break;
        case 8: goto L_80800738; break;
        case 9: goto L_80800738; break;
        case 10: goto L_80800738; break;
        case 11: goto L_80800738; break;
        case 12: goto L_80800738; break;
        case 13: goto L_80800738; break;
        case 14: goto L_80800738; break;
        case 15: goto L_80800600; break;
        case 16: goto L_80800738; break;
        case 17: goto L_808005B4; break;
        case 18: goto L_80800530; break;
        case 19: goto L_80800738; break;
        case 20: goto L_80800738; break;
        case 21: goto L_80800738; break;
        case 22: goto L_80800738; break;
        case 23: goto L_80800738; break;
        case 24: goto L_80800738; break;
        case 25: goto L_80800738; break;
        case 26: goto L_80800738; break;
        case 27: goto L_80800738; break;
        case 28: goto L_80800738; break;
        case 29: goto L_80800738; break;
        case 30: goto L_80800738; break;
        case 31: goto L_80800738; break;
        case 32: goto L_80800738; break;
        case 33: goto L_80800738; break;
        case 34: goto L_80800738; break;
        case 35: goto L_80800738; break;
        case 36: goto L_80800718; break;
        default: switch_error(__func__, 0x80800528, 0x80800768);
    }
    // 0x8080052C: nop

L_80800530:
    // 0x80800530: lw          $t7, 0x78($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X78);
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800538: sll         $t9, $t7, 29
    ctx->r25 = S32(ctx->r15 << 29);
    // 0x8080053C: bltz        $t9, L_808005AC
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800540: nop
    
            goto L_808005AC;
    }
    // 0x80800540: nop

    // 0x80800544: jal         0x80102424
    // 0x80800548: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80800548: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8080054C: jal         0x800F54E4
    // 0x80800550: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800550: nop

    after_1:
    // 0x80800554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800558: jal         0x8010CD50
    // 0x8080055C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8010CD50(rdram, ctx);
        goto after_2;
    // 0x8080055C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80800560: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x80800564: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800568: jal         0x800858E0
    // 0x8080056C: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    _chbounce_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x8080056C: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_3:
    // 0x80800570: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x80800574: jal         0x800858F0
    // 0x80800578: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _chbounce_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x80800578: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8080057C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800580: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800584: jal         0x80108B04
    // 0x80800588: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_5;
    // 0x80800588: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8080058C: jal         0x8010A570
    // 0x80800590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_6;
    // 0x80800590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800594: lui         $a0, 0x7FFB
    ctx->r4 = S32(0X7FFB << 16);
    // 0x80800598: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x8080059C: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x808005A0: ori         $a0, $a0, 0x5C16
    ctx->r4 = ctx->r4 | 0X5C16;
    // 0x808005A4: jal         0x800C4140
    // 0x808005A8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_7;
    // 0x808005A8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_7:
L_808005AC:
    // 0x808005AC: b           L_8080073C
    // 0x808005B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080073C;
    // 0x808005B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005B4:
    // 0x808005B4: lw          $t0, 0x78($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X78);
    // 0x808005B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005BC: sll         $t2, $t0, 29
    ctx->r10 = S32(ctx->r8 << 29);
    // 0x808005C0: bltz        $t2, L_808005E8
    if (SIGNED(ctx->r10) < 0) {
        // 0x808005C4: nop
    
            goto L_808005E8;
    }
    // 0x808005C4: nop

    // 0x808005C8: jal         0x80102424
    // 0x808005CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x808005CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x808005D0: lui         $a0, 0x7FFB
    ctx->r4 = S32(0X7FFB << 16);
    // 0x808005D4: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x808005D8: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x808005DC: ori         $a0, $a0, 0x5C16
    ctx->r4 = ctx->r4 | 0X5C16;
    // 0x808005E0: jal         0x800C4140
    // 0x808005E4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_9;
    // 0x808005E4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_9:
L_808005E8:
    // 0x808005E8: b           L_8080073C
    // 0x808005EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080073C;
    // 0x808005EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005F0:
    // 0x808005F0: jal         0x80089F60
    // 0x808005F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x808005F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808005F8: b           L_8080073C
    // 0x808005FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080073C;
    // 0x808005FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800600:
    // 0x80800600: jal         0x800F54E4
    // 0x80800604: nop

    func_800F54E4(rdram, ctx);
        goto after_11;
    // 0x80800604: nop

    after_11:
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080060C: jal         0x8010CD50
    // 0x80800610: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8010CD50(rdram, ctx);
        goto after_12;
    // 0x80800610: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_12:
    // 0x80800614: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800618: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080061C: jal         0x800858E0
    // 0x80800620: add.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f6.fl;
    _chbounce_entrypoint_3(rdram, ctx);
        goto after_13;
    // 0x80800620: add.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f6.fl;
    after_13:
    // 0x80800624: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
    // 0x80800628: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080062C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80800630: srl         $t3, $v0, 7
    ctx->r11 = S32(U32(ctx->r2) >> 7);
    // 0x80800634: addiu       $v0, $t3, -0x32
    ctx->r2 = ADD32(ctx->r11, -0X32);
    // 0x80800638: beq         $v0, $zero, L_8080065C
    if (ctx->r2 == 0) {
        // 0x8080063C: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_8080065C;
    }
    // 0x8080063C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800640: beq         $v0, $at, L_80800684
    if (ctx->r2 == ctx->r1) {
        // 0x80800644: addiu       $a0, $zero, 0x12
        ctx->r4 = ADD32(0, 0X12);
            goto L_80800684;
    }
    // 0x80800644: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x80800648: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080064C: beq         $v0, $at, L_808006BC
    if (ctx->r2 == ctx->r1) {
        // 0x80800650: addiu       $a0, $zero, 0x12
        ctx->r4 = ADD32(0, 0X12);
            goto L_808006BC;
    }
    // 0x80800650: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x80800654: b           L_808006EC
    // 0x80800658: nop

        goto L_808006EC;
    // 0x80800658: nop

L_8080065C:
    // 0x8080065C: jal         0x80085900
    // 0x80800660: addiu       $a2, $zero, 0x513
    ctx->r6 = ADD32(0, 0X513);
    _chbounce_entrypoint_7(rdram, ctx);
        goto after_14;
    // 0x80800660: addiu       $a2, $zero, 0x513
    ctx->r6 = ADD32(0, 0X513);
    after_14:
    // 0x80800664: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800668: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080066C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800670: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800674: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800678: swc1        $f8, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f8.u32l;
    // 0x8080067C: b           L_808006EC
    // 0x80800680: swc1        $f10, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f10.u32l;
        goto L_808006EC;
    // 0x80800680: swc1        $f10, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f10.u32l;
L_80800684:
    // 0x80800684: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800688: jal         0x80085900
    // 0x8080068C: addiu       $a2, $zero, 0x517
    ctx->r6 = ADD32(0, 0X517);
    _chbounce_entrypoint_7(rdram, ctx);
        goto after_15;
    // 0x8080068C: addiu       $a2, $zero, 0x517
    ctx->r6 = ADD32(0, 0X517);
    after_15:
    // 0x80800690: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800694: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80800698: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080069C: addiu       $a1, $zero, 0x975
    ctx->r5 = ADD32(0, 0X975);
    // 0x808006A0: jal         0x80103140
    // 0x808006A4: lhu         $a2, 0x16($t4)
    ctx->r6 = MEM_HU(ctx->r12, 0X16);
    func_80103140(rdram, ctx);
        goto after_16;
    // 0x808006A4: lhu         $a2, 0x16($t4)
    ctx->r6 = MEM_HU(ctx->r12, 0X16);
    after_16:
    // 0x808006A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808006AC: jal         0x80102424
    // 0x808006B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_17;
    // 0x808006B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x808006B4: b           L_808006EC
    // 0x808006B8: nop

        goto L_808006EC;
    // 0x808006B8: nop

L_808006BC:
    // 0x808006BC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808006C0: jal         0x80085900
    // 0x808006C4: addiu       $a2, $zero, 0x517
    ctx->r6 = ADD32(0, 0X517);
    _chbounce_entrypoint_7(rdram, ctx);
        goto after_18;
    // 0x808006C4: addiu       $a2, $zero, 0x517
    ctx->r6 = ADD32(0, 0X517);
    after_18:
    // 0x808006C8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808006CC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x808006D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006D4: addiu       $a1, $zero, 0x974
    ctx->r5 = ADD32(0, 0X974);
    // 0x808006D8: jal         0x80103140
    // 0x808006DC: lhu         $a2, 0x16($t5)
    ctx->r6 = MEM_HU(ctx->r13, 0X16);
    func_80103140(rdram, ctx);
        goto after_19;
    // 0x808006DC: lhu         $a2, 0x16($t5)
    ctx->r6 = MEM_HU(ctx->r13, 0X16);
    after_19:
    // 0x808006E0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808006E4: jal         0x80102424
    // 0x808006E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_20;
    // 0x808006E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
L_808006EC:
    // 0x808006EC: jal         0x8010A590
    // 0x808006F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8010A590(rdram, ctx);
        goto after_21;
    // 0x808006F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_21:
    // 0x808006F4: b           L_8080073C
    // 0x808006F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080073C;
    // 0x808006F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006FC:
    // 0x808006FC: jal         0x800DA544
    // 0x80800700: addiu       $a0, $zero, 0x342
    ctx->r4 = ADD32(0, 0X342);
    func_800DA544(rdram, ctx);
        goto after_22;
    // 0x80800700: addiu       $a0, $zero, 0x342
    ctx->r4 = ADD32(0, 0X342);
    after_22:
    // 0x80800704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800708: jal         0x80102424
    // 0x8080070C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_23;
    // 0x8080070C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_23:
    // 0x80800710: b           L_8080073C
    // 0x80800714: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080073C;
    // 0x80800714: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800718:
    // 0x80800718: jal         0x80088098
    // 0x8080071C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_24;
    // 0x8080071C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_24:
    // 0x80800720: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2464, 0X870) << 16);
    // 0x80800724: addiu       $a0, $a0, 0x870
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2464, 0X870));
    // 0x80800728: jal         0x80088090
    // 0x8080072C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_25;
    // 0x8080072C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_25:
    // 0x80800730: b           L_8080073C
    // 0x80800734: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8080073C;
    // 0x80800734: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800738:
    // 0x80800738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080073C:
    // 0x8080073C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800740: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800744: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800748: jr          $ra
    // 0x8080074C: nop

    return;
    // 0x8080074C: nop

;}
RECOMP_FUNC void func_8010CA74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CA74: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010CA78: addiu       $a2, $a2, 0x6F50
    ctx->r6 = ADD32(ctx->r6, 0X6F50);
    // 0x8010CA7C: lh          $t6, 0xE($a2)
    ctx->r14 = MEM_H(ctx->r6, 0XE);
    // 0x8010CA80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010CA84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010CA88: bne         $t6, $zero, L_8010CA98
    if (ctx->r14 != 0) {
        // 0x8010CA8C: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8010CA98;
    }
    // 0x8010CA8C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8010CA90: b           L_8010CAB0
    // 0x8010CA94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010CAB0;
    // 0x8010CA94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010CA98:
    // 0x8010CA98: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x8010CA9C: nop

    // 0x8010CAA0: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010CAA4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8010CAA8: jal         0x800F0064
    // 0x8010CAAC: nop

    func_800F0064(rdram, ctx);
        goto after_0;
    // 0x8010CAAC: nop

    after_0:
L_8010CAB0:
    // 0x8010CAB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010CAB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010CAB8: jr          $ra
    // 0x8010CABC: nop

    return;
    // 0x8010CABC: nop

;}
RECOMP_FUNC void func_80110A24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110A24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80110A28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80110A2C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80110A30: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80110A34: jal         0x80112524
    // 0x80110A38: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_80112524(rdram, ctx);
        goto after_0;
    // 0x80110A38: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80110A3C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80110A40: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80110A44: jal         0x800A516C
    // 0x80110A48: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_800A516C(rdram, ctx);
        goto after_1;
    // 0x80110A48: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80110A4C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80110A50: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80110A54: swc1        $f4, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f4.u32l;
    // 0x80110A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80110A5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80110A60: jr          $ra
    // 0x80110A64: nop

    return;
    // 0x80110A64: nop

;}
RECOMP_FUNC void func_801137E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801137E4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801137E8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801137EC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801137F0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801137F4: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x801137F8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x801137FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80113800: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80113804: lui         $a3, 0x86
    ctx->r7 = S32(0X86 << 16);
    // 0x80113808: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x8011380C: jal         0x800C6A7C
    // 0x80113810: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800C6A7C(rdram, ctx);
        goto after_0;
    // 0x80113810: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80113814: beq         $v0, $zero, L_8011388C
    if (ctx->r2 == 0) {
        // 0x80113818: addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
            goto L_8011388C;
    }
    // 0x80113818: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8011381C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80113820: jal         0x800EFB24
    // 0x80113824: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x80113824: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x80113828: jal         0x800EF2A0
    // 0x8011382C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_800EF2A0(rdram, ctx);
        goto after_2;
    // 0x8011382C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x80113830: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80113834: jal         0x800EEAA4
    // 0x80113838: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800EEAA4(rdram, ctx);
        goto after_3;
    // 0x80113838: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x8011383C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80113840: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80113844: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80113848: nop

    // 0x8011384C: bc1f        L_8011385C
    if (!c1cs) {
        // 0x80113850: nop
    
            goto L_8011385C;
    }
    // 0x80113850: nop

    // 0x80113854: b           L_80113890
    // 0x80113858: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80113890;
    // 0x80113858: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8011385C:
    // 0x8011385C: jal         0x80013A7C
    // 0x80113860: nop

    func_80013A7C(rdram, ctx);
        goto after_4;
    // 0x80113860: nop

    after_4:
    // 0x80113864: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80113868: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8011386C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80113870: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80113874: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80113878: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8011387C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80113880: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80113884: b           L_80113890
    // 0x80113888: swc1        $f16, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f16.u32l;
        goto L_80113890;
    // 0x80113888: swc1        $f16, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f16.u32l;
L_8011388C:
    // 0x8011388C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80113890:
    // 0x80113890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80113894: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80113898: jr          $ra
    // 0x8011389C: nop

    return;
    // 0x8011389C: nop

;}
RECOMP_FUNC void chhagstraindoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800140: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1972, 0X150) << 16);
    // 0x80800144: jr          $ra
    // 0x80800148: addiu       $v0, $v0, 0x150
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1972, 0X150));
    return;
    // 0x80800148: addiu       $v0, $v0, 0x150
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1972, 0X150));
    // 0x8080014C: nop

;}
RECOMP_FUNC void func_800A4C68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4C68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A4C6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A4C70: jal         0x800A940C
    // 0x800A4C74: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    func_800A940C(rdram, ctx);
        goto after_0;
    // 0x800A4C74: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    after_0:
    // 0x800A4C78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A4C7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A4C80: jr          $ra
    // 0x800A4C84: nop

    return;
    // 0x800A4C84: nop

;}
RECOMP_FUNC void func_80800018_chshockjump(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080001C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800020: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800024: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800028: beq         $a1, $at, L_80800044
    if (ctx->r5 == ctx->r1) {
        // 0x8080002C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800044;
    }
    // 0x8080002C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800030: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x80800034: beq         $a1, $at, L_80800080
    if (ctx->r5 == ctx->r1) {
        // 0x80800038: nop
    
            goto L_80800080;
    }
    // 0x80800038: nop

    // 0x8080003C: b           L_8080009C
    // 0x80800040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080009C;
    // 0x80800040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800044:
    // 0x80800044: jal         0x80101080
    // 0x80800048: nop

    func_80101080(rdram, ctx);
        goto after_0;
    // 0x80800048: nop

    after_0:
    // 0x8080004C: jal         0x80106790
    // 0x80800050: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80800050: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800054: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800058: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080005C: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    // 0x80800060: jal         0x80086688
    // 0x80800064: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    _chexploder_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80800064: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    after_2:
    // 0x80800068: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080006C: lui         $a1, 0xC416
    ctx->r5 = S32(0XC416 << 16);
    // 0x80800070: jal         0x80086690
    // 0x80800074: lui         $a2, 0xC3C8
    ctx->r6 = S32(0XC3C8 << 16);
    _chexploder_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x80800074: lui         $a2, 0xC3C8
    ctx->r6 = S32(0XC3C8 << 16);
    after_3:
    // 0x80800078: b           L_8080009C
    // 0x8080007C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080009C;
    // 0x8080007C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800080:
    // 0x80800080: jal         0x800F7B9C
    // 0x80800084: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    func_800F7B9C(rdram, ctx);
        goto after_4;
    // 0x80800084: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    after_4:
    // 0x80800088: b           L_8080009C
    // 0x8080008C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080009C;
    // 0x8080008C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800090: b           L_8080009C
    // 0x80800094: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080009C;
    // 0x80800094: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800098: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080009C:
    // 0x8080009C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000A4: jr          $ra
    // 0x808000A8: nop

    return;
    // 0x808000A8: nop

;}
RECOMP_FUNC void subaddieDll_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800318: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080031C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800320: jal         0x80800260
    // 0x80800324: nop

    func_80800260_subaddieDll(rdram, ctx);
        goto after_0;
    // 0x80800324: nop

    after_0:
    // 0x80800328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080032C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800330: jr          $ra
    // 0x80800334: nop

    return;
    // 0x80800334: nop

;}
RECOMP_FUNC void func_80800000_bsrebound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x800845D8
    // 0x80800010: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _babounce_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800014: lui         $a2, 0x3F15
    ctx->r6 = S32(0X3F15 << 16);
    // 0x80800018: ori         $a2, $a2, 0x119D
    ctx->r6 = ctx->r6 | 0X119D;
    // 0x8080001C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800020: jal         0x800845E0
    // 0x80800024: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    _babounce_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800024: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_1:
    // 0x80800028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080002C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800030: jr          $ra
    // 0x80800034: nop

    return;
    // 0x80800034: nop

;}
RECOMP_FUNC void _suexpressjoint_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089778: syscall     794
    recomp_syscall_handler(rdram, ctx, 0x80089778);
    return;
    // 0x8008977C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8080041C_chfactorytrashbelt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080041C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800420: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800424: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800428: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8080042C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80800430: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800434: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800438: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8080043C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800440: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800444: jal         0x80100094
    // 0x80800448: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800448: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080044C: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80800450: beq         $s0, $at, L_80800520
    if (ctx->r16 == ctx->r1) {
        // 0x80800454: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800520;
    }
    // 0x80800454: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800458: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x8080045C: beq         $s0, $at, L_808004A4
    if (ctx->r16 == ctx->r1) {
        // 0x80800460: lw          $s2, 0x40($sp)
        ctx->r18 = MEM_W(ctx->r29, 0X40);
            goto L_808004A4;
    }
    // 0x80800460: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80800464: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x80800468: beq         $s0, $at, L_808004EC
    if (ctx->r16 == ctx->r1) {
        // 0x8080046C: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_808004EC;
    }
    // 0x8080046C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800470: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800474: bne         $s0, $at, L_80800580
    if (ctx->r16 != ctx->r1) {
        // 0x80800478: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_80800580;
    }
    // 0x80800478: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8080047C: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80800480: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x80800484: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x80800488: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x8080048C: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x80800490: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x80800494: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x80800498: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x8080049C: b           L_80800588
    // 0x808004A0: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
        goto L_80800588;
    // 0x808004A0: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
L_808004A4:
    // 0x808004A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808004A8: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x808004AC: addiu       $s3, $zero, 0x7
    ctx->r19 = ADD32(0, 0X7);
L_808004B0:
    // 0x808004B0: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x808004B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808004B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808004BC: lhu         $t7, 0x16($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X16);
    // 0x808004C0: lhu         $a1, 0x14($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X14);
    // 0x808004C4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808004C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808004CC: jal         0x80100D24
    // 0x808004D0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_80100D24(rdram, ctx);
        goto after_1;
    // 0x808004D0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_1:
    // 0x808004D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808004D8: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x808004DC: bne         $s0, $s3, L_808004B0
    if (ctx->r16 != ctx->r19) {
        // 0x808004E0: sh          $v0, 0x2($s1)
        MEM_H(0X2, ctx->r17) = ctx->r2;
            goto L_808004B0;
    }
    // 0x808004E0: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // 0x808004E4: b           L_8080058C
    // 0x808004E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080058C;
    // 0x808004E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004EC:
    // 0x808004EC: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x808004F0: addiu       $s2, $zero, 0xE
    ctx->r18 = ADD32(0, 0XE);
L_808004F4:
    // 0x808004F4: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    // 0x808004F8: beql        $a0, $zero, L_80800510
    if (ctx->r4 == 0) {
        // 0x808004FC: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_80800510;
    }
    goto skip_0;
    // 0x808004FC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    skip_0:
    // 0x80800500: jal         0x80100E18
    // 0x80800504: nop

    func_80100E18(rdram, ctx);
        goto after_2;
    // 0x80800504: nop

    after_2:
    // 0x80800508: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x8080050C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
L_80800510:
    // 0x80800510: bne         $s1, $s2, L_808004F4
    if (ctx->r17 != ctx->r18) {
        // 0x80800514: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_808004F4;
    }
    // 0x80800514: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80800518: b           L_8080058C
    // 0x8080051C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080058C;
    // 0x8080051C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800520:
    // 0x80800520: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80800524: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800528: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8080052C: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x80800530: lh          $s0, 0x4($t0)
    ctx->r16 = MEM_H(ctx->r8, 0X4);
    // 0x80800534: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80800538: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8080053C: jal         0x80100A74
    // 0x80800540: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    func_80100A74(rdram, ctx);
        goto after_3;
    // 0x80800540: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_3:
    // 0x80800544: jal         0x800DF818
    // 0x80800548: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF818(rdram, ctx);
        goto after_4;
    // 0x80800548: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x8080054C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800550: addiu       $a1, $zero, -0x2
    ctx->r5 = ADD32(0, -0X2);
    // 0x80800554: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800558: jal         0x800DF660
    // 0x8080055C: lbu         $a3, 0x9B($s4)
    ctx->r7 = MEM_BU(ctx->r20, 0X9B);
    func_800DF660(rdram, ctx);
        goto after_5;
    // 0x8080055C: lbu         $a3, 0x9B($s4)
    ctx->r7 = MEM_BU(ctx->r20, 0X9B);
    after_5:
    // 0x80800560: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80800564: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80800568: jal         0x80100AC4
    // 0x8080056C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    func_80100AC4(rdram, ctx);
        goto after_6;
    // 0x8080056C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_6:
    // 0x80800570: jal         0x800DF720
    // 0x80800574: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF720(rdram, ctx);
        goto after_7;
    // 0x80800574: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80800578: b           L_8080058C
    // 0x8080057C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080058C;
    // 0x8080057C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800580:
    // 0x80800580: b           L_8080058C
    // 0x80800584: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080058C;
    // 0x80800584: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800588:
    // 0x80800588: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080058C:
    // 0x8080058C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800590: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800594: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800598: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8080059C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x808005A0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x808005A4: jr          $ra
    // 0x808005A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808005A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_808006A4_cheggproximity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808006A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006AC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808006B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808006B4: jal         0x80100094
    // 0x808006B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808006B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808006BC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808006C0: lw          $t6, 0xA0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XA0);
    // 0x808006C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808006C8: jal         0x80800874
    // 0x808006CC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_80800874_cheggproximity(rdram, ctx);
        goto after_1;
    // 0x808006CC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_1:
    // 0x808006D0: jal         0x80800AFC
    // 0x808006D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800AFC_cheggproximity(rdram, ctx);
        goto after_2;
    // 0x808006D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808006D8: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x808006DC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x808006E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808006E4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x808006E8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x808006EC: lw          $t1, 0x40($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X40);
    // 0x808006F0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x808006F4: bnel        $t1, $at, L_8080070C
    if (ctx->r9 != ctx->r1) {
        // 0x808006F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080070C;
    }
    goto skip_0;
    // 0x808006F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808006FC: lbu         $t3, 0x39($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X39);
    // 0x80800700: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x80800704: sb          $t4, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r12;
    // 0x80800708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080070C:
    // 0x8080070C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800710: jr          $ra
    // 0x80800714: nop

    return;
    // 0x80800714: nop

;}
RECOMP_FUNC void func_8080000C_chexplodingchainlinks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: jr          $ra
    // 0x80800010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800DC508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC508: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DC50C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DC510: jal         0x80020760
    // 0x800DC514: nop

    func_80020760(rdram, ctx);
        goto after_0;
    // 0x800DC514: nop

    after_0:
    // 0x800DC518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DC51C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DC520: jr          $ra
    // 0x800DC524: nop

    return;
    // 0x800DC524: nop

;}
RECOMP_FUNC void func_80800128_cheel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800128: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080012C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800130: jal         0x80100094
    // 0x80800134: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800134: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800138: lw          $t6, 0xDC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XDC);
    // 0x8080013C: beql        $t6, $zero, L_8080015C
    if (ctx->r14 == 0) {
        // 0x80800140: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080015C;
    }
    goto skip_0;
    // 0x80800140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800144: lw          $a0, 0xDC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XDC);
    // 0x80800148: jal         0x800C8B84
    // 0x8080014C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800C8B84(rdram, ctx);
        goto after_1;
    // 0x8080014C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800150: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800154: sw          $zero, 0xDC($v1)
    MEM_W(0XDC, ctx->r3) = 0;
    // 0x80800158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080015C:
    // 0x8080015C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800160: jr          $ra
    // 0x80800164: nop

    return;
    // 0x80800164: nop

;}
RECOMP_FUNC void _chfactorymaindoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087560: syscall     588
    recomp_syscall_handler(rdram, ctx, 0x80087560);
    return;
    // 0x80087564: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80802314_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802314: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802318: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080231C: addiu       $a0, $zero, 0xA4F
    ctx->r4 = ADD32(0, 0XA4F);
    // 0x80802320: jal         0x800DA980
    // 0x80802324: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DA980(rdram, ctx);
        goto after_0;
    // 0x80802324: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80802328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080232C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80802330: subu        $v0, $t6, $v0
    ctx->r2 = SUB32(ctx->r14, ctx->r2);
    // 0x80802334: jr          $ra
    // 0x80802338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80802338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800CB8BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB8BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CB8C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB8C4: jal         0x800CB890
    // 0x800CB8C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800CB890(rdram, ctx);
        goto after_0;
    // 0x800CB8C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800CB8CC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800CB8D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB8D4: lh          $t7, 0x1A($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X1A);
    // 0x800CB8D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CB8DC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800CB8E0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800CB8E4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800CB8E8: jr          $ra
    // 0x800CB8EC: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    return;
    // 0x800CB8EC: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
;}
