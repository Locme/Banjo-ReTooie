#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _bssplitup_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083AD0: syscall     89
    recomp_syscall_handler(rdram, ctx, 0x80083AD0);
    return;
    // 0x80083AD4: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void idwater_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800004: lh          $t7, 0x10($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X10);
    // 0x80800008: lh          $t6, 0x2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2);
    // 0x8080000C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80800010: sh          $t8, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r24;
    // 0x80800014: lh          $t0, 0x8($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X8);
    // 0x80800018: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x8080001C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80800020: sh          $t1, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r9;
    // 0x80800024: lh          $t3, 0xA($a1)
    ctx->r11 = MEM_H(ctx->r5, 0XA);
    // 0x80800028: lh          $t2, 0x2($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X2);
    // 0x8080002C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80800030: jr          $ra
    // 0x80800034: sh          $t4, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r12;
    return;
    // 0x80800034: sh          $t4, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r12;
;}
RECOMP_FUNC void _chdoubloon_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087448: syscall     572
    recomp_syscall_handler(rdram, ctx, 0x80087448);
    return;
    // 0x8008744C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800000_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(308, 0X1120) << 16);
    // 0x80800004: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800008: lwc1        $f12, 0x1120($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(308, 0X1120));
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(308, 0X1124) << 16);
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800018: jal         0x800DC178
    // 0x8080001C: lwc1        $f14, 0x1124($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(308, 0X1124));
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x8080001C: lwc1        $f14, 0x1124($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(308, 0X1124));
    after_0:
    // 0x80800020: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800024: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800028: jal         0x8009DE38
    // 0x8080002C: addiu       $a1, $zero, 0x511
    ctx->r5 = ADD32(0, 0X511);
    func_8009DE38(rdram, ctx);
        goto after_1;
    // 0x8080002C: addiu       $a1, $zero, 0x511
    ctx->r5 = ADD32(0, 0X511);
    after_1:
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800038: jr          $ra
    // 0x8080003C: nop

    return;
    // 0x8080003C: nop

;}
RECOMP_FUNC void func_808018F4_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808018F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808018FC: jal         0x80084C40
    // 0x80801900: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bafly_entrypoint_15(rdram, ctx);
        goto after_0;
    // 0x80801900: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801904: jal         0x80800188
    // 0x80801908: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800188_bskazfly(rdram, ctx);
        goto after_1;
    // 0x80801908: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080190C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801910: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801914: jr          $ra
    // 0x80801918: nop

    return;
    // 0x80801918: nop

;}
RECOMP_FUNC void bsfirstp_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808027C0: bne         $a1, $zero, L_808027D0
    if (ctx->r5 != 0) {
        // 0x808027C4: addiu       $sp, $sp, -0x28
        ctx->r29 = ADD32(ctx->r29, -0X28);
            goto L_808027D0;
    }
    // 0x808027C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808027C8: b           L_80802974
    // 0x808027CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802974;
    // 0x808027CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808027D0:
    // 0x808027D0: addiu       $at, $zero, 0x164
    ctx->r1 = ADD32(0, 0X164);
    // 0x808027D4: beq         $a0, $at, L_80802848
    if (ctx->r4 == ctx->r1) {
        // 0x808027D8: andi        $v0, $a2, 0x3
        ctx->r2 = ctx->r6 & 0X3;
            goto L_80802848;
    }
    // 0x808027D8: andi        $v0, $a2, 0x3
    ctx->r2 = ctx->r6 & 0X3;
    // 0x808027DC: addiu       $at, $zero, 0x165
    ctx->r1 = ADD32(0, 0X165);
    // 0x808027E0: beq         $a0, $at, L_808027FC
    if (ctx->r4 == ctx->r1) {
        // 0x808027E4: sll         $t6, $a1, 3
        ctx->r14 = S32(ctx->r5 << 3);
            goto L_808027FC;
    }
    // 0x808027E4: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x808027E8: addiu       $at, $zero, 0x166
    ctx->r1 = ADD32(0, 0X166);
    // 0x808027EC: beq         $a0, $at, L_80802898
    if (ctx->r4 == ctx->r1) {
        // 0x808027F0: sll         $t8, $a1, 3
        ctx->r24 = S32(ctx->r5 << 3);
            goto L_80802898;
    }
    // 0x808027F0: sll         $t8, $a1, 3
    ctx->r24 = S32(ctx->r5 << 3);
    // 0x808027F4: b           L_808028E0
    // 0x808027F8: addiu       $v1, $sp, 0x18
    ctx->r3 = ADD32(ctx->r29, 0X18);
        goto L_808028E0;
    // 0x808027F8: addiu       $v1, $sp, 0x18
    ctx->r3 = ADD32(ctx->r29, 0X18);
L_808027FC:
    // 0x808027FC: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80802800: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80802804: lui         $t8, 0x8081
    ctx->r24 = S32(RELOC_HI16(439, 0XAD4C) << 16);
    // 0x80802808: addiu       $t8, $t8, -0x52B4
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(439, 0XAD4C));
    // 0x8080280C: addiu       $t7, $t6, -0xE
    ctx->r15 = ADD32(ctx->r14, -0XE);
    // 0x80802810: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80802814: lwl         $at, 0x0($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0X0);
    // 0x80802818: lwr         $at, 0x3($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0X3);
    // 0x8080281C: addiu       $v1, $sp, 0x18
    ctx->r3 = ADD32(ctx->r29, 0X18);
    // 0x80802820: sw          $at, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r1;
    // 0x80802824: lwl         $t1, 0x4($t9)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r25, 0X4);
    // 0x80802828: lwr         $t1, 0x7($t9)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r25, 0X7);
    // 0x8080282C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80802830: lwl         $at, 0x8($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0X8);
    // 0x80802834: lwr         $at, 0xB($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0XB);
    // 0x80802838: sw          $at, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r1;
    // 0x8080283C: lhu         $at, 0xC($t9)
    ctx->r1 = MEM_HU(ctx->r25, 0XC);
    // 0x80802840: b           L_808028E0
    // 0x80802844: sh          $at, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r1;
        goto L_808028E0;
    // 0x80802844: sh          $at, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r1;
L_80802848:
    // 0x80802848: sll         $t2, $a1, 3
    ctx->r10 = S32(ctx->r5 << 3);
    // 0x8080284C: subu        $t2, $t2, $a1
    ctx->r10 = SUB32(ctx->r10, ctx->r5);
    // 0x80802850: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80802854: lui         $t4, 0x8081
    ctx->r12 = S32(RELOC_HI16(439, 0XADA0) << 16);
    // 0x80802858: addiu       $t4, $t4, -0x5260
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(439, 0XADA0));
    // 0x8080285C: addiu       $t3, $t2, -0xE
    ctx->r11 = ADD32(ctx->r10, -0XE);
    // 0x80802860: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80802864: lwl         $at, 0x0($t5)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r13, 0X0);
    // 0x80802868: lwr         $at, 0x3($t5)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r13, 0X3);
    // 0x8080286C: addiu       $v1, $sp, 0x18
    ctx->r3 = ADD32(ctx->r29, 0X18);
    // 0x80802870: sw          $at, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r1;
    // 0x80802874: lwl         $t7, 0x4($t5)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r13, 0X4);
    // 0x80802878: lwr         $t7, 0x7($t5)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r13, 0X7);
    // 0x8080287C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80802880: lwl         $at, 0x8($t5)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r13, 0X8);
    // 0x80802884: lwr         $at, 0xB($t5)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r13, 0XB);
    // 0x80802888: sw          $at, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r1;
    // 0x8080288C: lhu         $at, 0xC($t5)
    ctx->r1 = MEM_HU(ctx->r13, 0XC);
    // 0x80802890: b           L_808028E0
    // 0x80802894: sh          $at, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r1;
        goto L_808028E0;
    // 0x80802894: sh          $at, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r1;
L_80802898:
    // 0x80802898: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8080289C: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x808028A0: lui         $t9, 0x8081
    ctx->r25 = S32(RELOC_HI16(439, 0XACF8) << 16);
    // 0x808028A4: addiu       $t9, $t9, -0x5308
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(439, 0XACF8));
    // 0x808028A8: addiu       $t0, $t8, -0xE
    ctx->r8 = ADD32(ctx->r24, -0XE);
    // 0x808028AC: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x808028B0: lwl         $at, 0x0($t1)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r9, 0X0);
    // 0x808028B4: lwr         $at, 0x3($t1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r9, 0X3);
    // 0x808028B8: addiu       $v1, $sp, 0x18
    ctx->r3 = ADD32(ctx->r29, 0X18);
    // 0x808028BC: sw          $at, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r1;
    // 0x808028C0: lwl         $t3, 0x4($t1)
    ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r9, 0X4);
    // 0x808028C4: lwr         $t3, 0x7($t1)
    ctx->r11 = do_lwr(rdram, ctx->r11, ctx->r9, 0X7);
    // 0x808028C8: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x808028CC: lwl         $at, 0x8($t1)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r9, 0X8);
    // 0x808028D0: lwr         $at, 0xB($t1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r9, 0XB);
    // 0x808028D4: sw          $at, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r1;
    // 0x808028D8: lhu         $at, 0xC($t1)
    ctx->r1 = MEM_HU(ctx->r9, 0XC);
    // 0x808028DC: sh          $at, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r1;
L_808028E0:
    // 0x808028E0: beq         $v0, $zero, L_80802914
    if (ctx->r2 == 0) {
        // 0x808028E4: sra         $t4, $a2, 2
        ctx->r12 = S32(SIGNED(ctx->r6) >> 2);
            goto L_80802914;
    }
    // 0x808028E4: sra         $t4, $a2, 2
    ctx->r12 = S32(SIGNED(ctx->r6) >> 2);
    // 0x808028E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808028EC: beq         $v0, $at, L_8080292C
    if (ctx->r2 == ctx->r1) {
        // 0x808028F0: sra         $t0, $a2, 2
        ctx->r8 = S32(SIGNED(ctx->r6) >> 2);
            goto L_8080292C;
    }
    // 0x808028F0: sra         $t0, $a2, 2
    ctx->r8 = S32(SIGNED(ctx->r6) >> 2);
    // 0x808028F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808028F8: beq         $v0, $at, L_80802944
    if (ctx->r2 == ctx->r1) {
        // 0x808028FC: sra         $t4, $a2, 2
        ctx->r12 = S32(SIGNED(ctx->r6) >> 2);
            goto L_80802944;
    }
    // 0x808028FC: sra         $t4, $a2, 2
    ctx->r12 = S32(SIGNED(ctx->r6) >> 2);
    // 0x80802900: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80802904: beq         $v0, $at, L_8080295C
    if (ctx->r2 == ctx->r1) {
        // 0x80802908: sra         $t0, $a2, 2
        ctx->r8 = S32(SIGNED(ctx->r6) >> 2);
            goto L_8080295C;
    }
    // 0x80802908: sra         $t0, $a2, 2
    ctx->r8 = S32(SIGNED(ctx->r6) >> 2);
    // 0x8080290C: b           L_80802974
    // 0x80802910: lw          $v0, 0xC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC);
        goto L_80802974;
    // 0x80802910: lw          $v0, 0xC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC);
L_80802914:
    // 0x80802914: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x80802918: addu        $t5, $v1, $t6
    ctx->r13 = ADD32(ctx->r3, ctx->r14);
    // 0x8080291C: lhu         $t7, 0x0($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X0);
    // 0x80802920: srl         $t8, $t7, 12
    ctx->r24 = S32(U32(ctx->r15) >> 12);
    // 0x80802924: b           L_80802970
    // 0x80802928: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
        goto L_80802970;
    // 0x80802928: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
L_8080292C:
    // 0x8080292C: sll         $t9, $t0, 1
    ctx->r25 = S32(ctx->r8 << 1);
    // 0x80802930: addu        $t2, $v1, $t9
    ctx->r10 = ADD32(ctx->r3, ctx->r25);
    // 0x80802934: lbu         $t1, 0x0($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X0);
    // 0x80802938: andi        $t3, $t1, 0xF
    ctx->r11 = ctx->r9 & 0XF;
    // 0x8080293C: b           L_80802970
    // 0x80802940: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
        goto L_80802970;
    // 0x80802940: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
L_80802944:
    // 0x80802944: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x80802948: addu        $t5, $v1, $t6
    ctx->r13 = ADD32(ctx->r3, ctx->r14);
    // 0x8080294C: lbu         $t7, 0x1($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X1);
    // 0x80802950: srl         $t8, $t7, 4
    ctx->r24 = S32(U32(ctx->r15) >> 4);
    // 0x80802954: b           L_80802970
    // 0x80802958: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
        goto L_80802970;
    // 0x80802958: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
L_8080295C:
    // 0x8080295C: sll         $t9, $t0, 1
    ctx->r25 = S32(ctx->r8 << 1);
    // 0x80802960: addu        $t2, $v1, $t9
    ctx->r10 = ADD32(ctx->r3, ctx->r25);
    // 0x80802964: lhu         $t1, 0x0($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X0);
    // 0x80802968: andi        $t3, $t1, 0xF
    ctx->r11 = ctx->r9 & 0XF;
    // 0x8080296C: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
L_80802970:
    // 0x80802970: lw          $v0, 0xC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC);
L_80802974:
    // 0x80802974: jr          $ra
    // 0x80802978: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80802978: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _cheggclockwork_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800871C0: syscall     534
    recomp_syscall_handler(rdram, ctx, 0x800871C0);
    return;
    // 0x800871C4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080145C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080145C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801460: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801464: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801468: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080146C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80801470: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80801474: jal         0x800E3980
    // 0x80801478: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800E3980(rdram, ctx);
        goto after_0;
    // 0x80801478: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8080147C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80801480: jal         0x800EF3DC
    // 0x80801484: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800EF3DC(rdram, ctx);
        goto after_1;
    // 0x80801484: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x80801488: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8080148C: jal         0x800EEAA4
    // 0x80801490: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EEAA4(rdram, ctx);
        goto after_2;
    // 0x80801490: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80801494: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801498: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8080149C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808014A0: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x808014A4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808014A8: bc1tl       L_808014E4
    if (c1cs) {
        // 0x808014AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808014E4;
    }
    goto skip_0;
    // 0x808014AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808014B0: jal         0x800EEAA4
    // 0x808014B4: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_800EEAA4(rdram, ctx);
        goto after_3;
    // 0x808014B4: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x808014B8: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808014BC: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x808014C0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808014C4: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x808014C8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808014CC: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x808014D0: div.s       $f2, $f8, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x808014D4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x808014D8: jal         0x800EE7B4
    // 0x808014DC: nop

    func_800EE7B4(rdram, ctx);
        goto after_4;
    // 0x808014DC: nop

    after_4:
    // 0x808014E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808014E4:
    // 0x808014E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808014E8: jr          $ra
    // 0x808014EC: nop

    return;
    // 0x808014EC: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B3C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800B40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B44: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800B48: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800B4C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800B50: jal         0x8008CABC
    // 0x80800B54: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800B54: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x80800B58: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800B5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800B64: jal         0x80098140
    // 0x80800B68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    bainput_enable(rdram, ctx);
        goto after_1;
    // 0x80800B68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80800B6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B70: jal         0x8009D3A8
    // 0x80800B74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D3A8(rdram, ctx);
        goto after_2;
    // 0x80800B74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800B78: jal         0x8008B324
    // 0x80800B7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_3;
    // 0x80800B7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800B80: beq         $v0, $zero, L_80800B8C
    if (ctx->r2 == 0) {
        // 0x80800B84: nop
    
            goto L_80800B8C;
    }
    // 0x80800B84: nop

    // 0x80800B88: addiu       $s0, $zero, 0x15
    ctx->r16 = ADD32(0, 0X15);
L_80800B8C:
    // 0x80800B8C: jal         0x8008B2B4
    // 0x80800B90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_getAnimTimer(rdram, ctx);
        goto after_4;
    // 0x80800B90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800B94: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800B98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800B9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800BA0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800BA4: nop

    // 0x80800BA8: bc1fl       L_80800BC0
    if (!c1cs) {
        // 0x80800BAC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800BC0;
    }
    goto skip_0;
    // 0x80800BAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x80800BB0: jal         0x808007E0
    // 0x80800BB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_808007E0_bsbtrot(rdram, ctx);
        goto after_5;
    // 0x80800BB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80800BB8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800BBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800BC0:
    // 0x80800BC0: jal         0x8009E5C8
    // 0x80800BC4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x80800BC4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80800BC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BCC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800BD0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800BD4: jr          $ra
    // 0x80800BD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800BD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80016800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016800: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80016804: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80016808: jr          $ra
    // 0x8001680C: lbu         $v0, -0x6294($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6294);
    return;
    // 0x8001680C: lbu         $v0, -0x6294($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6294);
;}
RECOMP_FUNC void func_800BF48C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF48C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BF490: addiu       $v0, $v0, -0x7A50
    ctx->r2 = ADD32(ctx->r2, -0X7A50);
    // 0x800BF494: sb          $a0, 0x85($v0)
    MEM_B(0X85, ctx->r2) = ctx->r4;
    // 0x800BF498: sb          $a1, 0x86($v0)
    MEM_B(0X86, ctx->r2) = ctx->r5;
    // 0x800BF49C: jr          $ra
    // 0x800BF4A0: sb          $a2, 0x87($v0)
    MEM_B(0X87, ctx->r2) = ctx->r6;
    return;
    // 0x800BF4A0: sb          $a2, 0x87($v0)
    MEM_B(0X87, ctx->r2) = ctx->r6;
;}
RECOMP_FUNC void func_808003BC_bsbanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003C4: jal         0x8009E704
    // 0x808003C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bs_getNextState(rdram, ctx);
        goto after_0;
    // 0x808003C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808003CC: jal         0x80800390
    // 0x808003D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80800390_bsbanswim(rdram, ctx);
        goto after_1;
    // 0x808003D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808003D4: bnel        $v0, $zero, L_80800400
    if (ctx->r2 != 0) {
        // 0x808003D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800400;
    }
    goto skip_0;
    // 0x808003D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808003DC: jal         0x8008E0E8
    // 0x808003E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008E0E8(rdram, ctx);
        goto after_2;
    // 0x808003E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808003E4: beq         $v0, $zero, L_808003F4
    if (ctx->r2 == 0) {
        // 0x808003E8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808003F4;
    }
    // 0x808003E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808003EC: jal         0x80084788
    // 0x808003F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _bapackctrl_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x808003F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
L_808003F4:
    // 0x808003F4: jal         0x80800104
    // 0x808003F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800104_bsbanswim(rdram, ctx);
        goto after_4;
    // 0x808003F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x808003FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800400:
    // 0x80800400: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800404: jr          $ra
    // 0x80800408: nop

    return;
    // 0x80800408: nop

;}
RECOMP_FUNC void func_800C5CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5CC0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C5CC4: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x800C5CC8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800C5CCC: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800C5CD0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C5CD4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800C5CD8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800C5CDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C5CE0: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x800C5CE4: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    // 0x800C5CE8: jal         0x800F2100
    // 0x800C5CEC: sub.s       $f12, $f20, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f20.fl - ctx->f14.fl;
    mlAbsF(rdram, ctx);
        goto after_0;
    // 0x800C5CEC: sub.s       $f12, $f20, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f20.fl - ctx->f14.fl;
    after_0:
    // 0x800C5CF0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x800C5CF4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800C5CF8: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C5CFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C5D00: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800C5D04: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800C5D08: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800C5D0C: bc1fl       L_800C5DE8
    if (!c1cs) {
        // 0x800C5D10: mfc1        $a1, $f14
        ctx->r5 = (int32_t)ctx->f14.u32l;
            goto L_800C5DE8;
    }
    goto skip_0;
    // 0x800C5D10: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    skip_0:
    // 0x800C5D14: c.lt.s      $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f14.fl < ctx->f20.fl;
    // 0x800C5D18: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800C5D1C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800C5D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C5D24: bc1f        L_800C5D88
    if (!c1cs) {
        // 0x800C5D28: lw          $t8, 0x48($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X48);
            goto L_800C5D88;
    }
    // 0x800C5D28: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800C5D2C: add.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x800C5D30: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x800C5D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C5D38: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C5D3C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800C5D40: jal         0x800C5BE4
    // 0x800C5D44: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_800C5BE4(rdram, ctx);
        goto after_1;
    // 0x800C5D44: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800C5D48: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C5D4C: bne         $v0, $zero, L_800C5DF8
    if (ctx->r2 != 0) {
        // 0x800C5D50: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800C5DF8;
    }
    // 0x800C5D50: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C5D54: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C5D58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C5D5C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800C5D60: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800C5D64: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800C5D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C5D6C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800C5D70: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800C5D74: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800C5D78: jal         0x800C5BE4
    // 0x800C5D7C: nop

    func_800C5BE4(rdram, ctx);
        goto after_2;
    // 0x800C5D7C: nop

    after_2:
    // 0x800C5D80: b           L_800C5DF8
    // 0x800C5D84: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800C5DF8;
    // 0x800C5D84: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800C5D88:
    // 0x800C5D88: sub.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x800C5D8C: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x800C5D90: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800C5D94: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800C5D98: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800C5D9C: jal         0x800C5BE4
    // 0x800C5DA0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_800C5BE4(rdram, ctx);
        goto after_3;
    // 0x800C5DA0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x800C5DA4: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C5DA8: bne         $v0, $zero, L_800C5DF8
    if (ctx->r2 != 0) {
        // 0x800C5DAC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800C5DF8;
    }
    // 0x800C5DAC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C5DB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C5DB4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C5DB8: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800C5DBC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800C5DC0: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x800C5DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C5DC8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800C5DCC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800C5DD0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800C5DD4: jal         0x800C5BE4
    // 0x800C5DD8: nop

    func_800C5BE4(rdram, ctx);
        goto after_4;
    // 0x800C5DD8: nop

    after_4:
    // 0x800C5DDC: b           L_800C5DF8
    // 0x800C5DE0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800C5DF8;
    // 0x800C5DE0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C5DE4: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
L_800C5DE8:
    // 0x800C5DE8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800C5DEC: jal         0x800C5BE4
    // 0x800C5DF0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_800C5BE4(rdram, ctx);
        goto after_5;
    // 0x800C5DF0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_5:
    // 0x800C5DF4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800C5DF8:
    // 0x800C5DF8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C5DFC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800C5E00: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800C5E04: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800C5E08: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800C5E0C: jr          $ra
    // 0x800C5E10: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800C5E10: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80104328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104328: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010432C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80104330: jal         0x801042D8
    // 0x80104334: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    func_801042D8(rdram, ctx);
        goto after_0;
    // 0x80104334: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    after_0:
    // 0x80104338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010433C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80104340: jr          $ra
    // 0x80104344: nop

    return;
    // 0x80104344: nop

    // 0x80104348: nop

    // 0x8010434C: nop

;}
RECOMP_FUNC void func_80108EF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108EF4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80108EF8: lhu         $v0, 0x8($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X8);
    // 0x80108EFC: xori        $t6, $v0, 0x23A
    ctx->r14 = ctx->r2 ^ 0X23A;
    // 0x80108F00: jr          $ra
    // 0x80108F04: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    return;
    // 0x80108F04: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_80800520_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800520: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800524: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800528: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080052C: jal         0x80800EE0
    // 0x80800530: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800EE0_chstonepillar(rdram, ctx);
        goto after_0;
    // 0x80800530: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800538: jal         0x80100094
    // 0x8080053C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080053C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800540: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800544: lw          $a1, 0x28($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X28);
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080054C: jal         0x808005B4
    // 0x80800550: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_808005B4_chstonepillar(rdram, ctx);
        goto after_2;
    // 0x80800550: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_2:
    // 0x80800554: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080055C: lw          $a1, 0x28($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X28);
    // 0x80800560: addiu       $a2, $v0, 0xC
    ctx->r6 = ADD32(ctx->r2, 0XC);
    // 0x80800564: jal         0x808005B4
    // 0x80800568: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    func_808005B4_chstonepillar(rdram, ctx);
        goto after_3;
    // 0x80800568: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_3:
    // 0x8080056C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800570: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800574: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800578: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x8080057C: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800580: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80800584: nop

    // 0x80800588: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080058C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800590: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80800594: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x80800598: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080059C: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    // 0x808005A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005AC: jr          $ra
    // 0x808005B0: nop

    return;
    // 0x808005B0: nop

;}
RECOMP_FUNC void func_800B3FD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3FD0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B3FD4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B3FD8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800B3FDC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800B3FE0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B3FE4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B3FE8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B3FEC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800B3FF0: lw          $s2, 0x0($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X0);
    // 0x800B3FF4: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800B3FF8: bne         $a2, $zero, L_800B4068
    if (ctx->r6 != 0) {
        // 0x800B3FFC: sw          $zero, 0x28($sp)
        MEM_W(0X28, ctx->r29) = 0;
            goto L_800B4068;
    }
    // 0x800B3FFC: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800B4000: lh          $t8, 0x4($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X4);
    // 0x800B4004: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    // 0x800B4008: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800B400C: beql        $t8, $zero, L_800B406C
    if (ctx->r24 == 0) {
        // 0x800B4010: lw          $t5, 0x28($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X28);
            goto L_800B406C;
    }
    goto skip_0;
    // 0x800B4010: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x800B4014: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
L_800B4018:
    // 0x800B4018: lh          $a1, 0x0($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X0);
    // 0x800B401C: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x800B4020: bne         $a1, $t0, L_800B4048
    if (ctx->r5 != ctx->r8) {
        // 0x800B4024: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800B4048;
    }
    // 0x800B4024: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B4028: jal         0x800B3B08
    // 0x800B402C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800B3B08(rdram, ctx);
        goto after_0;
    // 0x800B402C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800B4030: lh          $t1, 0x0($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X0);
    // 0x800B4034: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800B4038: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B403C: sh          $t2, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r10;
    // 0x800B4040: b           L_800B4068
    // 0x800B4044: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
        goto L_800B4068;
    // 0x800B4044: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
L_800B4048:
    // 0x800B4048: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x800B404C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B4050: jal         0x800B39D0
    // 0x800B4054: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    func_800B39D0(rdram, ctx);
        goto after_1;
    // 0x800B4054: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    after_1:
    // 0x800B4058: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x800B405C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B4060: bnel        $t4, $zero, L_800B4018
    if (ctx->r12 != 0) {
        // 0x800B4064: lh          $t9, 0x2($s0)
        ctx->r25 = MEM_H(ctx->r16, 0X2);
            goto L_800B4018;
    }
    goto skip_1;
    // 0x800B4064: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    skip_1:
L_800B4068:
    // 0x800B4068: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
L_800B406C:
    // 0x800B406C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800B4070: bnel        $t5, $zero, L_800B40F4
    if (ctx->r13 != 0) {
        // 0x800B4074: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_800B40F4;
    }
    goto skip_2;
    // 0x800B4074: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    skip_2:
    // 0x800B4078: lh          $v0, 0x2($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X2);
    // 0x800B407C: subu        $s0, $v0, $t6
    ctx->r16 = SUB32(ctx->r2, ctx->r14);
    // 0x800B4080: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800B4084: blezl       $s0, L_800B40DC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800B4088: lh          $t1, 0x0($s3)
        ctx->r9 = MEM_H(ctx->r19, 0X0);
            goto L_800B40DC;
    }
    goto skip_3;
    // 0x800B4088: lh          $t1, 0x0($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X0);
    skip_3:
    // 0x800B408C: lh          $t7, 0x0($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X0);
    // 0x800B4090: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B4094: jal         0x800B39D0
    // 0x800B4098: addu        $a1, $t7, $t6
    ctx->r5 = ADD32(ctx->r15, ctx->r14);
    func_800B39D0(rdram, ctx);
        goto after_2;
    // 0x800B4098: addu        $a1, $t7, $t6
    ctx->r5 = ADD32(ctx->r15, ctx->r14);
    after_2:
    // 0x800B409C: lh          $t8, 0x0($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X0);
    // 0x800B40A0: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800B40A4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800B40A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B40AC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x800B40B0: jal         0x800B39D0
    // 0x800B40B4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    func_800B39D0(rdram, ctx);
        goto after_3;
    // 0x800B40B4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_3:
    // 0x800B40B8: lh          $t0, 0x0($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X0);
    // 0x800B40BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800B40C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800B40C4: multu       $t0, $s0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B40C8: mflo        $a2
    ctx->r6 = lo;
    // 0x800B40CC: jal         0x8001BBC8
    // 0x800B40D0: nop

    aligned4_memcpy(rdram, ctx);
        goto after_4;
    // 0x800B40D0: nop

    after_4:
    // 0x800B40D4: lh          $v0, 0x2($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X2);
    // 0x800B40D8: lh          $t1, 0x0($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X0);
L_800B40DC:
    // 0x800B40DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B40E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B40E4: addu        $a1, $t1, $v0
    ctx->r5 = ADD32(ctx->r9, ctx->r2);
    // 0x800B40E8: jal         0x800B3B08
    // 0x800B40EC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    func_800B3B08(rdram, ctx);
        goto after_5;
    // 0x800B40EC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_5:
    // 0x800B40F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_800B40F4:
    // 0x800B40F4: jal         0x800B3EDC
    // 0x800B40F8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800B3EDC(rdram, ctx);
        goto after_6;
    // 0x800B40F8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_6:
    // 0x800B40FC: lh          $t2, 0x2($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X2);
    // 0x800B4100: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800B4104: sh          $t3, 0x2($s3)
    MEM_H(0X2, ctx->r19) = ctx->r11;
    // 0x800B4108: lh          $t4, 0x2($s3)
    ctx->r12 = MEM_H(ctx->r19, 0X2);
    // 0x800B410C: bnel        $t4, $zero, L_800B411C
    if (ctx->r12 != 0) {
        // 0x800B4110: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B411C;
    }
    goto skip_4;
    // 0x800B4110: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x800B4114: sh          $zero, 0x0($s3)
    MEM_H(0X0, ctx->r19) = 0;
    // 0x800B4118: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800B411C:
    // 0x800B411C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B4120: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B4124: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4128: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800B412C: jr          $ra
    // 0x800B4130: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B4130: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800BF444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF444: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BF448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BF44C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BF450: jal         0x80088110
    // 0x800BF454: addiu       $a0, $a0, -0x7A50
    ctx->r4 = ADD32(ctx->r4, -0X7A50);
    _gcmapDll_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x800BF454: addiu       $a0, $a0, -0x7A50
    ctx->r4 = ADD32(ctx->r4, -0X7A50);
    after_0:
    // 0x800BF458: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x800BF45C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800BF460: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x800BF464: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800BF468: addiu       $a3, $a3, -0x14B4
    ctx->r7 = ADD32(ctx->r7, -0X14B4);
    // 0x800BF46C: addiu       $a2, $a2, -0xDD8
    ctx->r6 = ADD32(ctx->r6, -0XDD8);
    // 0x800BF470: addiu       $a1, $a1, -0xF20
    ctx->r5 = ADD32(ctx->r5, -0XF20);
    // 0x800BF474: jal         0x800C6A28
    // 0x800BF478: addiu       $a0, $a0, -0x1100
    ctx->r4 = ADD32(ctx->r4, -0X1100);
    func_800C6A28(rdram, ctx);
        goto after_1;
    // 0x800BF478: addiu       $a0, $a0, -0x1100
    ctx->r4 = ADD32(ctx->r4, -0X1100);
    after_1:
    // 0x800BF47C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BF480: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BF484: jr          $ra
    // 0x800BF488: nop

    return;
    // 0x800BF488: nop

;}
RECOMP_FUNC void func_80800E94_chfactorysparkroom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E9C: jal         0x80089D00
    // 0x80800EA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddiefade_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800EA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800EA4: jal         0x8010A63C
    // 0x80800EA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8010A63C(rdram, ctx);
        goto after_1;
    // 0x80800EA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800EAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800EB0: jal         0x80085808
    // 0x80800EB4: addiu       $a1, $zero, 0xA2F
    ctx->r5 = ADD32(0, 0XA2F);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80800EB4: addiu       $a1, $zero, 0xA2F
    ctx->r5 = ADD32(0, 0XA2F);
    after_2:
    // 0x80800EB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800EC0: jr          $ra
    // 0x80800EC4: nop

    return;
    // 0x80800EC4: nop

;}
RECOMP_FUNC void func_80800024_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080002C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800030: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800034: addiu       $a0, $zero, 0x9DC
    ctx->r4 = ADD32(0, 0X9DC);
    // 0x80800038: jal         0x800DA7A8
    // 0x8080003C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800DA7A8(rdram, ctx);
        goto after_0;
    // 0x8080003C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x80800040: jal         0x800FDC28
    // 0x80800044: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_1;
    // 0x80800044: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80800048: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8080004C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800050: beq         $v0, $at, L_80800068
    if (ctx->r2 == ctx->r1) {
        // 0x80800054: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800068;
    }
    // 0x80800054: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800058: beq         $v0, $at, L_80800078
    if (ctx->r2 == ctx->r1) {
        // 0x8080005C: nop
    
            goto L_80800078;
    }
    // 0x8080005C: nop

    // 0x80800060: b           L_80800084
    // 0x80800064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800084;
    // 0x80800064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800068:
    // 0x80800068: jal         0x800FC660
    // 0x8080006C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC660(rdram, ctx);
        goto after_2;
    // 0x8080006C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_2:
    // 0x80800070: b           L_80800084
    // 0x80800074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800084;
    // 0x80800074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800078:
    // 0x80800078: jal         0x800FC660
    // 0x8080007C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC660(rdram, ctx);
        goto after_3;
    // 0x8080007C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_3:
    // 0x80800080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800084:
    // 0x80800084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void func_800BFD00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFD00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BFD04: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800BFD08: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800BFD0C: addiu       $s2, $s2, -0x7890
    ctx->r18 = ADD32(ctx->r18, -0X7890);
    // 0x800BFD10: lw          $t6, 0x30($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X30);
    // 0x800BFD14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BFD18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BFD1C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800BFD20: blez        $t6, L_800BFD54
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800BFD24: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_800BFD54;
    }
    // 0x800BFD24: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800BFD28: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800BFD2C: addiu       $s1, $s1, -0x788C
    ctx->r17 = ADD32(ctx->r17, -0X788C);
    // 0x800BFD30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800BFD34:
    // 0x800BFD34: jal         0x800DF744
    // 0x800BFD38: lw          $a1, 0x30($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X30);
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x800BFD38: lw          $a1, 0x30($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X30);
    after_0:
    // 0x800BFD3C: lw          $t7, 0x30($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X30);
    // 0x800BFD40: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800BFD44: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800BFD48: slt         $at, $t7, $s0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800BFD4C: beql        $at, $zero, L_800BFD34
    if (ctx->r1 == 0) {
        // 0x800BFD50: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800BFD34;
    }
    goto skip_0;
    // 0x800BFD50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_800BFD54:
    // 0x800BFD54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BFD58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BFD5C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800BFD60: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800BFD64: jr          $ra
    // 0x800BFD68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800BFD68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _chintroticker_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086B40: syscall     419
    recomp_syscall_handler(rdram, ctx, 0x80086B40);
    return;
    // 0x80086B44: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void gcskyDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080004C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800050: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800054: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800058: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080005C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800060: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800064: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800068: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8080006C: jal         0x800EA05C
    // 0x80800070: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800070: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    after_0:
    // 0x80800074: jal         0x80800000
    // 0x80800078: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80800000_gcskyDll(rdram, ctx);
        goto after_1;
    // 0x80800078: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080007C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80800080: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80800084: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x80800088: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
    // 0x8080008C: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
L_80800090:
    // 0x80800090: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80800094: beql        $a0, $zero, L_808000AC
    if (ctx->r4 == 0) {
        // 0x80800098: lw          $a0, 0x8($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X8);
            goto L_808000AC;
    }
    goto skip_0;
    // 0x80800098: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    skip_0:
    // 0x8080009C: jal         0x800DBFD8
    // 0x808000A0: nop

    func_800DBFD8(rdram, ctx);
        goto after_2;
    // 0x808000A0: nop

    after_2:
    // 0x808000A4: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x808000A8: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
L_808000AC:
    // 0x808000AC: beql        $a0, $zero, L_808000C4
    if (ctx->r4 == 0) {
        // 0x808000B0: lw          $a0, 0x18($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X18);
            goto L_808000C4;
    }
    goto skip_1;
    // 0x808000B0: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    skip_1:
    // 0x808000B4: jal         0x80088898
    // 0x808000B8: nop

    _glidmake_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x808000B8: nop

    after_3:
    // 0x808000BC: sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
    // 0x808000C0: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
L_808000C4:
    // 0x808000C4: beql        $a0, $zero, L_808000DC
    if (ctx->r4 == 0) {
        // 0x808000C8: lw          $a0, 0x24($s2)
        ctx->r4 = MEM_W(ctx->r18, 0X24);
            goto L_808000DC;
    }
    goto skip_2;
    // 0x808000C8: lw          $a0, 0x24($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X24);
    skip_2:
    // 0x808000CC: jal         0x80087A38
    // 0x808000D0: nop

    _dbtex_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x808000D0: nop

    after_4:
    // 0x808000D4: sw          $zero, 0x18($s1)
    MEM_W(0X18, ctx->r17) = 0;
    // 0x808000D8: lw          $a0, 0x24($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X24);
L_808000DC:
    // 0x808000DC: beql        $a0, $zero, L_808000F4
    if (ctx->r4 == 0) {
        // 0x808000E0: sw          $zero, 0x20($s2)
        MEM_W(0X20, ctx->r18) = 0;
            goto L_808000F4;
    }
    goto skip_3;
    // 0x808000E0: sw          $zero, 0x20($s2)
    MEM_W(0X20, ctx->r18) = 0;
    skip_3:
    // 0x808000E4: jal         0x800B23E0
    // 0x808000E8: nop

    func_800B23E0(rdram, ctx);
        goto after_5;
    // 0x808000E8: nop

    after_5:
    // 0x808000EC: sw          $zero, 0x24($s2)
    MEM_W(0X24, ctx->r18) = 0;
    // 0x808000F0: sw          $zero, 0x20($s2)
    MEM_W(0X20, ctx->r18) = 0;
L_808000F4:
    // 0x808000F4: lw          $t6, 0x10($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X10);
    // 0x808000F8: sll         $t7, $s3, 4
    ctx->r15 = S32(ctx->r19 << 4);
    // 0x808000FC: addu        $s0, $s4, $t7
    ctx->r16 = ADD32(ctx->r20, ctx->r15);
    // 0x80800100: beq         $t6, $zero, L_80800128
    if (ctx->r14 == 0) {
        // 0x80800104: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800128;
    }
    // 0x80800104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800108: jal         0x800D70F8
    // 0x8080010C: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    func_800D70F8(rdram, ctx);
        goto after_6;
    // 0x8080010C: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    after_6:
    // 0x80800110: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    // 0x80800114: jal         0x800D721C
    // 0x80800118: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D721C(rdram, ctx);
        goto after_7;
    // 0x80800118: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8080011C: jal         0x800D6CEC
    // 0x80800120: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    func_800D6CEC(rdram, ctx);
        goto after_8;
    // 0x80800120: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    after_8:
    // 0x80800124: sw          $zero, 0x10($s1)
    MEM_W(0X10, ctx->r17) = 0;
L_80800128:
    // 0x80800128: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8080012C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800130: bne         $s3, $s5, L_80800090
    if (ctx->r19 != ctx->r21) {
        // 0x80800134: addiu       $s2, $s2, 0x8
        ctx->r18 = ADD32(ctx->r18, 0X8);
            goto L_80800090;
    }
    // 0x80800134: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80800138: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8080013C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800140: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800144: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800148: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8080014C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80800150: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80800154: jr          $ra
    // 0x80800158: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800158: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800C2C4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2C4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C2C50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C2C54: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C2C58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C2C5C: jal         0x800C1414
    // 0x800C2C60: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C2C60: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    after_0:
    // 0x800C2C64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C2C68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C2C6C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800C2C70: addiu       $t7, $zero, 0x55F0
    ctx->r15 = ADD32(0, 0X55F0);
    // 0x800C2C74: addiu       $t8, $zero, 0x3F
    ctx->r24 = ADD32(0, 0X3F);
    // 0x800C2C78: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800C2C7C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C2C80: sw          $zero, 0x64($v0)
    MEM_W(0X64, ctx->r2) = 0;
    // 0x800C2C84: sh          $t6, 0x58($v0)
    MEM_H(0X58, ctx->r2) = ctx->r14;
    // 0x800C2C88: sh          $zero, 0x5C($v0)
    MEM_H(0X5C, ctx->r2) = 0;
    // 0x800C2C8C: sh          $t7, 0x5A($v0)
    MEM_H(0X5A, ctx->r2) = ctx->r15;
    // 0x800C2C90: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x800C2C94: sb          $t8, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r24;
    // 0x800C2C98: sb          $zero, 0x79($v0)
    MEM_B(0X79, ctx->r2) = 0;
    // 0x800C2C9C: sb          $t9, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r25;
    // 0x800C2CA0: jal         0x800EA05C
    // 0x800C2CA4: swc1        $f4, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f4.u32l;
    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x800C2CA4: swc1        $f4, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f4.u32l;
    after_1:
    // 0x800C2CA8: lhu         $t1, 0x7A($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X7A);
    // 0x800C2CAC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C2CB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C2CB4: andi        $t2, $t1, 0xFC3F
    ctx->r10 = ctx->r9 & 0XFC3F;
    // 0x800C2CB8: sh          $t2, 0x7A($s0)
    MEM_H(0X7A, ctx->r16) = ctx->r10;
    // 0x800C2CBC: lbu         $t3, 0x7B($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X7B);
    // 0x800C2CC0: sb          $t0, 0x63($s0)
    MEM_B(0X63, ctx->r16) = ctx->r8;
    // 0x800C2CC4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800C2CC8: andi        $t6, $t3, 0xFFEF
    ctx->r14 = ctx->r11 & 0XFFEF;
    // 0x800C2CCC: ori         $t8, $t6, 0x2
    ctx->r24 = ctx->r14 | 0X2;
    // 0x800C2CD0: sb          $t6, 0x7B($s0)
    MEM_B(0X7B, ctx->r16) = ctx->r14;
    // 0x800C2CD4: andi        $t0, $t8, 0xF7
    ctx->r8 = ctx->r24 & 0XF7;
    // 0x800C2CD8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800C2CDC: sb          $t8, 0x7B($s0)
    MEM_B(0X7B, ctx->r16) = ctx->r24;
    // 0x800C2CE0: andi        $t2, $t0, 0xDF
    ctx->r10 = ctx->r8 & 0XDF;
    // 0x800C2CE4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C2CE8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C2CEC: sb          $t0, 0x7B($s0)
    MEM_B(0X7B, ctx->r16) = ctx->r8;
    // 0x800C2CF0: sb          $t2, 0x7B($s0)
    MEM_B(0X7B, ctx->r16) = ctx->r10;
    // 0x800C2CF4: andi        $t3, $t2, 0xFB
    ctx->r11 = ctx->r10 & 0XFB;
    // 0x800C2CF8: sh          $v0, 0x5E($s0)
    MEM_H(0X5E, ctx->r16) = ctx->r2;
    // 0x800C2CFC: sb          $t3, 0x7B($s0)
    MEM_B(0X7B, ctx->r16) = ctx->r11;
    // 0x800C2D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2D04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C2D08: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x800C2D0C: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x800C2D10: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    // 0x800C2D14: jal         0x800C1210
    // 0x800C2D18: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    func_800C1210(rdram, ctx);
        goto after_2;
    // 0x800C2D18: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    after_2:
    // 0x800C2D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2D20: jal         0x800C11F8
    // 0x800C2D24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C11F8(rdram, ctx);
        goto after_3;
    // 0x800C2D24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x800C2D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2D2C: jal         0x800C13A0
    // 0x800C2D30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C13A0(rdram, ctx);
        goto after_4;
    // 0x800C2D30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x800C2D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2D38: jal         0x800C13A0
    // 0x800C2D3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800C13A0(rdram, ctx);
        goto after_5;
    // 0x800C2D3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x800C2D40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2D44: jal         0x800C13A0
    // 0x800C2D48: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800C13A0(rdram, ctx);
        goto after_6;
    // 0x800C2D48: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_6:
    // 0x800C2D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2D50: jal         0x800C13A0
    // 0x800C2D54: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_800C13A0(rdram, ctx);
        goto after_7;
    // 0x800C2D54: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_7:
    // 0x800C2D58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C2D5C: lwc1        $f10, 0x57F0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X57F0);
    // 0x800C2D60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C2D64: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x800C2D68: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x800C2D6C: lwc1        $f16, 0x57F4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X57F4);
    // 0x800C2D70: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x800C2D74: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C2D78: sh          $t4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r12;
    // 0x800C2D7C: sb          $zero, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = 0;
    // 0x800C2D80: sb          $zero, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = 0;
    // 0x800C2D84: sb          $zero, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = 0;
    // 0x800C2D88: sb          $zero, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = 0;
    // 0x800C2D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2D90: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    // 0x800C2D94: jal         0x800EFD24
    // 0x800C2D98: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    func_800EFD24(rdram, ctx);
        goto after_8;
    // 0x800C2D98: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    after_8:
    // 0x800C2D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2DA0: jal         0x800C13B0
    // 0x800C2DA4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C13B0(rdram, ctx);
        goto after_9;
    // 0x800C2DA4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x800C2DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2DAC: jal         0x800C13B0
    // 0x800C2DB0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_800C13B0(rdram, ctx);
        goto after_10;
    // 0x800C2DB0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_10:
    // 0x800C2DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2DB8: jal         0x800C13B0
    // 0x800C2DBC: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    func_800C13B0(rdram, ctx);
        goto after_11;
    // 0x800C2DBC: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_11:
    // 0x800C2DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2DC4: jal         0x800C13B0
    // 0x800C2DC8: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    func_800C13B0(rdram, ctx);
        goto after_12;
    // 0x800C2DC8: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_12:
    // 0x800C2DCC: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    // 0x800C2DD0: jal         0x800C3418
    // 0x800C2DD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C3418(rdram, ctx);
        goto after_13;
    // 0x800C2DD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_13:
    // 0x800C2DD8: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x800C2DDC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800C2DE0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800C2DE4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x800C2DE8: jal         0x800C3798
    // 0x800C2DEC: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    func_800C3798(rdram, ctx);
        goto after_14;
    // 0x800C2DEC: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    after_14:
    // 0x800C2DF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2DF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C2DF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C2DFC: jr          $ra
    // 0x800C2E00: nop

    return;
    // 0x800C2E00: nop

;}
RECOMP_FUNC void _bamoveledge_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084E68: syscall     139
    recomp_syscall_handler(rdram, ctx, 0x80084E68);
    return;
    // 0x80084E6C: xori        $t0, $zero, 0x8
    ctx->r8 = 0 ^ 0X8;
;}
RECOMP_FUNC void func_8008FD20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FD20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FD24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FD28: jal         0x800F54E4
    // 0x8008FD2C: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FD2C: nop

    after_0:
    // 0x8008FD30: jal         0x800F5378
    // 0x8008FD34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5378(rdram, ctx);
        goto after_1;
    // 0x8008FD34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8008FD38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FD3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FD40: jr          $ra
    // 0x8008FD44: nop

    return;
    // 0x8008FD44: nop

;}
RECOMP_FUNC void func_800DBEB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DBEB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DBEB4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800DBEB8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800DBEBC: addiu       $s0, $a0, 0x4
    ctx->r16 = ADD32(ctx->r4, 0X4);
    // 0x800DBEC0: addiu       $s1, $a0, 0x118
    ctx->r17 = ADD32(ctx->r4, 0X118);
    // 0x800DBEC4: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800DBEC8: beq         $at, $zero, L_800DBEE8
    if (ctx->r1 == 0) {
        // 0x800DBECC: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800DBEE8;
    }
    // 0x800DBECC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
L_800DBED0:
    // 0x800DBED0: jal         0x800EFD24
    // 0x800DBED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x800DBED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800DBED8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800DBEDC: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800DBEE0: bne         $at, $zero, L_800DBED0
    if (ctx->r1 != 0) {
        // 0x800DBEE4: nop
    
            goto L_800DBED0;
    }
    // 0x800DBEE4: nop

L_800DBEE8:
    // 0x800DBEE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800DBEEC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800DBEF0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800DBEF4: jr          $ra
    // 0x800DBEF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800DBEF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void bskazstilt_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007CC: jal         0x80800234
    // 0x808007D0: nop

    func_80800234_bskazstilt(rdram, ctx);
        goto after_0;
    // 0x808007D0: nop

    after_0:
    // 0x808007D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007DC: jr          $ra
    // 0x808007E0: nop

    return;
    // 0x808007E0: nop

;}
RECOMP_FUNC void func_80801AC4_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AC4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801AC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801ACC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801AD0: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80801AD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801AD8: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80801ADC: bltz        $t8, L_80801B34
    if (SIGNED(ctx->r24) < 0) {
        // 0x80801AE0: nop
    
            goto L_80801B34;
    }
    // 0x80801AE0: nop

    // 0x80801AE4: jal         0x80103C94
    // 0x80801AE8: nop

    func_80103C94(rdram, ctx);
        goto after_0;
    // 0x80801AE8: nop

    after_0:
    // 0x80801AEC: beq         $v0, $zero, L_80801B34
    if (ctx->r2 == 0) {
        // 0x80801AF0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80801B34;
    }
    // 0x80801AF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801AF4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80801AF8: jal         0x800B237C
    // 0x80801AFC: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_800B237C(rdram, ctx);
        goto after_1;
    // 0x80801AFC: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80801B00: jal         0x80101010
    // 0x80801B04: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_80101010(rdram, ctx);
        goto after_2;
    // 0x80801B04: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80801B08: lbu         $a2, 0x79($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X79);
    // 0x80801B0C: addiu       $a0, $zero, 0x4AB
    ctx->r4 = ADD32(0, 0X4AB);
    // 0x80801B10: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x80801B14: srl         $t9, $a2, 4
    ctx->r25 = S32(U32(ctx->r6) >> 4);
    // 0x80801B18: jal         0x80101180
    // 0x80801B1C: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    func_80101180(rdram, ctx);
        goto after_3;
    // 0x80801B1C: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_3:
    // 0x80801B20: beq         $v0, $zero, L_80801B34
    if (ctx->r2 == 0) {
        // 0x80801B24: nop
    
            goto L_80801B34;
    }
    // 0x80801B24: nop

    // 0x80801B28: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80801B2C: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x80801B30: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
L_80801B34:
    // 0x80801B34: jal         0x80089C90
    // 0x80801B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80801B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801B3C: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80801B40: beq         $at, $zero, L_80801B50
    if (ctx->r1 == 0) {
        // 0x80801B44: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801B50;
    }
    // 0x80801B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B48: jal         0x80089C98
    // 0x80801B4C: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80801B4C: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_5:
L_80801B50:
    // 0x80801B50: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80801B54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801B58: srl         $t3, $v0, 10
    ctx->r11 = S32(U32(ctx->r2) >> 10);
    // 0x80801B5C: beq         $t3, $at, L_80801B8C
    if (ctx->r11 == ctx->r1) {
        // 0x80801B60: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801B8C;
    }
    // 0x80801B60: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801B64: beq         $t3, $at, L_80801B8C
    if (ctx->r11 == ctx->r1) {
        // 0x80801B68: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80801B8C;
    }
    // 0x80801B68: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801B6C: bne         $t3, $at, L_80801B8C
    if (ctx->r11 != ctx->r1) {
        // 0x80801B70: nop
    
            goto L_80801B8C;
    }
    // 0x80801B70: nop

    // 0x80801B74: jal         0x80101DDC
    // 0x80801B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_6;
    // 0x80801B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801B7C: beq         $v0, $zero, L_80801B8C
    if (ctx->r2 == 0) {
        // 0x80801B80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801B8C;
    }
    // 0x80801B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B84: jal         0x80102424
    // 0x80801B88: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x80801B88: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
L_80801B8C:
    // 0x80801B8C: jal         0x8080179C
    // 0x80801B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080179C_chgameselect(rdram, ctx);
        goto after_8;
    // 0x80801B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801B94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801B98: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801B9C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801BA0: jr          $ra
    // 0x80801BA4: nop

    return;
    // 0x80801BA4: nop

;}
RECOMP_FUNC void func_8010B69C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B69C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010B6A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010B6A4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8010B6A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010B6AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010B6B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8010B6B4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8010B6B8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8010B6BC: jal         0x800BED50
    // 0x8010B6C0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800BED50(rdram, ctx);
        goto after_0;
    // 0x8010B6C0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x8010B6C4: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x8010B6C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8010B6CC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8010B6D0: sub.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8010B6D4: lwc1        $f12, 0x8($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8010B6D8: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8010B6DC: nop

    // 0x8010B6E0: bc1fl       L_8010B6F4
    if (!c1cs) {
        // 0x8010B6E4: swc1        $f2, 0x8($a1)
        MEM_W(0X8, ctx->r5) = ctx->f2.u32l;
            goto L_8010B6F4;
    }
    goto skip_0;
    // 0x8010B6E4: swc1        $f2, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f2.u32l;
    skip_0:
    // 0x8010B6E8: b           L_8010B6F4
    // 0x8010B6EC: swc1        $f12, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f12.u32l;
        goto L_8010B6F4;
    // 0x8010B6EC: swc1        $f12, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f12.u32l;
    // 0x8010B6F0: swc1        $f2, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f2.u32l;
L_8010B6F4:
    // 0x8010B6F4: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8010B6F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010B6FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010B700: c.eq.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl == ctx->f6.fl;
    // 0x8010B704: nop

    // 0x8010B708: bc1f        L_8010B714
    if (!c1cs) {
        // 0x8010B70C: nop
    
            goto L_8010B714;
    }
    // 0x8010B70C: nop

    // 0x8010B710: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010B714:
    // 0x8010B714: jr          $ra
    // 0x8010B718: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010B718: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void badata_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D60: jal         0x80800000
    // 0x80800D64: nop

    func_80800000_badata(rdram, ctx);
        goto after_0;
    // 0x80800D64: nop

    after_0:
    // 0x80800D68: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x80800D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D70: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(473, 0X1520) << 16);
    // 0x80800D74: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800D78: lh          $v0, 0x1520($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(473, 0X1520));
    // 0x80800D7C: jr          $ra
    // 0x80800D80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800D80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void sueggmove_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800300: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800304: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80800308: swc1        $f12, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f12.u32l;
    // 0x8080030C: jr          $ra
    // 0x80800310: swc1        $f14, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f14.u32l;
    return;
    // 0x80800310: swc1        $f14, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_80803760_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803760: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803768: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080376C: jal         0x80085338
    // 0x80803770: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    _batimer_set(rdram, ctx);
        goto after_0;
    // 0x80803770: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_0:
    // 0x80803774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803778: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080377C: jr          $ra
    // 0x80803780: nop

    return;
    // 0x80803780: nop

;}
RECOMP_FUNC void func_80101FDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101FDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80101FE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101FE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80101FE8: jal         0x80101F64
    // 0x80101FEC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80101F64(rdram, ctx);
        goto after_0;
    // 0x80101FEC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80101FF0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80101FF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80101FF8: jal         0x80101BE0
    // 0x80101FFC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80101BE0(rdram, ctx);
        goto after_1;
    // 0x80101FFC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80102000: beql        $v0, $zero, L_80102030
    if (ctx->r2 == 0) {
        // 0x80102004: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80102030;
    }
    goto skip_0;
    // 0x80102004: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80102008: jal         0x80104248
    // 0x8010200C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80104248(rdram, ctx);
        goto after_2;
    // 0x8010200C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80102010: beq         $v0, $zero, L_8010202C
    if (ctx->r2 == 0) {
        // 0x80102014: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8010202C;
    }
    // 0x80102014: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80102018: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8010201C: beql        $t6, $zero, L_80102030
    if (ctx->r14 == 0) {
        // 0x80102020: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80102030;
    }
    goto skip_1;
    // 0x80102020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80102024: jal         0x8008B064
    // 0x80102028: nop

    anctrl_start(rdram, ctx);
        goto after_3;
    // 0x80102028: nop

    after_3:
L_8010202C:
    // 0x8010202C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80102030:
    // 0x80102030: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80102034: jr          $ra
    // 0x80102038: nop

    return;
    // 0x80102038: nop

;}
RECOMP_FUNC void bsbeefly_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808002D4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(76, 0XE18) << 16);
    // 0x808002D8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808002DC: jr          $ra
    // 0x808002E0: lw          $v0, 0xE18($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(76, 0XE18));
    return;
    // 0x808002E0: lw          $v0, 0xE18($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(76, 0XE18));
;}
RECOMP_FUNC void _chlavacolumns_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087028: syscall     494
    recomp_syscall_handler(rdram, ctx, 0x80087028);
    return;
    // 0x8008702C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bstrexlarge_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080064C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800650: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800654: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800658: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080065C: jal         0x8009E74C
    // 0x80800660: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_8009E74C(rdram, ctx);
        goto after_0;
    // 0x80800660: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_0:
    // 0x80800664: bnel        $v0, $zero, L_808006E0
    if (ctx->r2 != 0) {
        // 0x80800668: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808006E0;
    }
    goto skip_0;
    // 0x80800668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080066C: jal         0x8009EF60
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_popZone(rdram, ctx);
        goto after_1;
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800674: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800678: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080067C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800680: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800684: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800688: jal         0x800A4D6C
    // 0x8080068C: nop

    func_800A4D6C(rdram, ctx);
        goto after_2;
    // 0x8080068C: nop

    after_2:
    // 0x80800690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800694: jal         0x80092864
    // 0x80800698: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80092864(rdram, ctx);
        goto after_3;
    // 0x80800698: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_3:
    // 0x8080069C: jal         0x8009E474
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E474(rdram, ctx);
        goto after_4;
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808006A4: jal         0x80095A40
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095A40(rdram, ctx);
        goto after_5;
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B0: jal         0x8009590C
    // 0x808006B4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009590C(rdram, ctx);
        goto after_6;
    // 0x808006B4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x808006B8: jal         0x8009BC6C
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_7;
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808006C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C4: jal         0x80095964
    // 0x808006C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80095964(rdram, ctx);
        goto after_8;
    // 0x808006C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x808006CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808006D4: jal         0x800947EC
    // 0x808006D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_9;
    // 0x808006D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x808006DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808006E0:
    // 0x808006E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808006E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808006E8: jr          $ra
    // 0x808006EC: nop

    return;
    // 0x808006EC: nop

;}
RECOMP_FUNC void fxrain_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808004B0: jal         0x808001E8
    // 0x808004B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808001E8_fxrain(rdram, ctx);
        goto after_0;
    // 0x808004B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808004B8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808004BC: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x808004C0: beql        $a0, $zero, L_808004EC
    if (ctx->r4 == 0) {
        // 0x808004C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808004EC;
    }
    goto skip_0;
    // 0x808004C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808004C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808004CC: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x808004D0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808004D4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808004D8: jal         0x800C3A40
    // 0x808004DC: nop

    func_800C3A40(rdram, ctx);
        goto after_1;
    // 0x808004DC: nop

    after_1:
    // 0x808004E0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808004E4: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    // 0x808004E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004EC:
    // 0x808004EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004F0: jr          $ra
    // 0x808004F4: nop

    return;
    // 0x808004F4: nop

;}
RECOMP_FUNC void func_800D8800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8800: jr          $ra
    // 0x800D8804: nop

    return;
    // 0x800D8804: nop

;}
RECOMP_FUNC void func_80800568_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800568: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080056C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800570: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800574: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800578: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080057C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800580: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800584: jal         0x80100094
    // 0x80800588: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800588: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080058C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800590: jal         0x801015D0
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_1;
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800598: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x8080059C: lui         $s2, 0x8081
    ctx->r18 = S32(RELOC_HI16(1480, 0X9EE2) << 16);
    // 0x808005A0: lui         $s0, 0x8081
    ctx->r16 = S32(RELOC_HI16(1480, 0X9EE0) << 16);
    // 0x808005A4: addiu       $s0, $s0, -0x6120
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1480, 0X9EE0));
    // 0x808005A8: addiu       $s2, $s2, -0x611E
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(1480, 0X9EE2));
L_808005AC:
    // 0x808005AC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x808005B0: jal         0x800DF744
    // 0x808005B4: lbu         $a1, 0xFC($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XFC);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x808005B4: lbu         $a1, 0xFC($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XFC);
    after_2:
    // 0x808005B8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x808005BC: bne         $s0, $s2, L_808005AC
    if (ctx->r16 != ctx->r18) {
        // 0x808005C0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_808005AC;
    }
    // 0x808005C0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808005C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005CC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808005D0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808005D4: jr          $ra
    // 0x808005D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808005D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void chjiggygamenew_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803770: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(772, 0X3EBC) << 16);
    // 0x80803774: jr          $ra
    // 0x80803778: addiu       $v0, $v0, 0x3EBC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(772, 0X3EBC));
    return;
    // 0x80803778: addiu       $v0, $v0, 0x3EBC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(772, 0X3EBC));
;}
RECOMP_FUNC void func_800C9DAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9DAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C9DB0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C9DB4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C9DB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C9DBC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C9DC0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800C9DC4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800C9DC8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800C9DCC: jal         0x800C9750
    // 0x800C9DD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C9750(rdram, ctx);
        goto after_0;
    // 0x800C9DD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800C9DD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C9DD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C9DDC: jr          $ra
    // 0x800C9DE0: nop

    return;
    // 0x800C9DE0: nop

;}
RECOMP_FUNC void chwitchyshockpadswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1452, 0X170) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x170
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1452, 0X170));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x170
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1452, 0X170));
;}
RECOMP_FUNC void _subaddieskeleton_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A0F0: syscall     828
    recomp_syscall_handler(rdram, ctx, 0x8008A0F0);
    return;
    // 0x8008A0F4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void subaddiedialog_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801004: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801008: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080100C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80801010: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80801014: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80801018: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x8080101C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80801020: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80801024: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80801028: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080102C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801030: jal         0x800F54E4
    // 0x80801034: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80801034: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80801038: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8080103C: blez        $s3, L_80801084
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80801040: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80801084;
    }
    // 0x80801040: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801044: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
L_80801048:
    // 0x80801048: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080104C: jal         0x800F64A4
    // 0x80801050: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800F64A4(rdram, ctx);
        goto after_1;
    // 0x80801050: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x80801054: beq         $v0, $zero, L_80801078
    if (ctx->r2 == 0) {
        // 0x80801058: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80801078;
    }
    // 0x80801058: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8080105C: lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4);
    // 0x80801060: jal         0x808010C8
    // 0x80801064: lbu         $a2, 0x6($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X6);
    func_808010C8_subaddiedialog(rdram, ctx);
        goto after_2;
    // 0x80801064: lbu         $a2, 0x6($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X6);
    after_2:
    // 0x80801068: bnel        $v0, $s5, L_8080107C
    if (ctx->r2 != ctx->r21) {
        // 0x8080106C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8080107C;
    }
    goto skip_0;
    // 0x8080106C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80801070: b           L_80801088
    // 0x80801074: lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6);
        goto L_80801088;
    // 0x80801074: lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6);
L_80801078:
    // 0x80801078: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8080107C:
    // 0x8080107C: bne         $s1, $s3, L_80801048
    if (ctx->r17 != ctx->r19) {
        // 0x80801080: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_80801048;
    }
    // 0x80801080: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80801084:
    // 0x80801084: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801088:
    // 0x80801088: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8080108C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801090: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801094: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80801098: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8080109C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x808010A0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x808010A4: jr          $ra
    // 0x808010A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808010A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void sumole_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B34: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801B38: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801B3C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80801B40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801B44: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80801B48: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80801B4C: jal         0x80802178
    // 0x80801B50: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_80802178_sumole(rdram, ctx);
        goto after_0;
    // 0x80801B50: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80801B54: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80801B58: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80801B5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801B60: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80801B64: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x80801B68: nop

    // 0x80801B6C: beq         $v1, $zero, L_80801B8C
    if (ctx->r3 == 0) {
        // 0x80801B70: nop
    
            goto L_80801B8C;
    }
    // 0x80801B70: nop

    // 0x80801B74: beq         $v1, $at, L_80801BFC
    if (ctx->r3 == ctx->r1) {
        // 0x80801B78: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801BFC;
    }
    // 0x80801B78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801B7C: beq         $v1, $at, L_80801C20
    if (ctx->r3 == ctx->r1) {
        // 0x80801B80: nop
    
            goto L_80801C20;
    }
    // 0x80801B80: nop

    // 0x80801B84: b           L_80801C64
    // 0x80801B88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801C64;
    // 0x80801B88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801B8C:
    // 0x80801B8C: beq         $v0, $zero, L_80801BB4
    if (ctx->r2 == 0) {
        // 0x80801B90: lh          $a0, 0x36($sp)
        ctx->r4 = MEM_H(ctx->r29, 0X36);
            goto L_80801BB4;
    }
    // 0x80801B90: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    // 0x80801B94: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80801B98: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80801B9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80801BA0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80801BA4: jal         0x800C05B8
    // 0x80801BA8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_800C05B8(rdram, ctx);
        goto after_1;
    // 0x80801BA8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_1:
    // 0x80801BAC: b           L_80801BF0
    // 0x80801BB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
        goto L_80801BF0;
    // 0x80801BB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80801BB4:
    // 0x80801BB4: jal         0x800DA298
    // 0x80801BB8: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80801BB8: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    after_2:
    // 0x80801BBC: beq         $v0, $zero, L_80801BCC
    if (ctx->r2 == 0) {
        // 0x80801BC0: lh          $a0, 0x36($sp)
        ctx->r4 = MEM_H(ctx->r29, 0X36);
            goto L_80801BCC;
    }
    // 0x80801BC0: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    // 0x80801BC4: b           L_80801BD0
    // 0x80801BC8: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
        goto L_80801BD0;
    // 0x80801BC8: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
L_80801BCC:
    // 0x80801BCC: addiu       $v1, $zero, 0x84
    ctx->r3 = ADD32(0, 0X84);
L_80801BD0:
    // 0x80801BD0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80801BD4: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80801BD8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80801BDC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80801BE0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80801BE4: jal         0x800C05B8
    // 0x80801BE8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_800C05B8(rdram, ctx);
        goto after_3;
    // 0x80801BE8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_3:
    // 0x80801BEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80801BF0:
    // 0x80801BF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801BF4: b           L_80801C60
    // 0x80801BF8: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
        goto L_80801C60;
    // 0x80801BF8: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_80801BFC:
    // 0x80801BFC: jal         0x800C064C
    // 0x80801C00: nop

    func_800C064C(rdram, ctx);
        goto after_4;
    // 0x80801C00: nop

    after_4:
    // 0x80801C04: lh          $t7, 0x36($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X36);
    // 0x80801C08: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80801C0C: bnel        $v0, $t7, L_80801C64
    if (ctx->r2 != ctx->r15) {
        // 0x80801C10: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80801C64;
    }
    goto skip_0;
    // 0x80801C10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80801C14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801C18: b           L_80801C60
    // 0x80801C1C: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
        goto L_80801C60;
    // 0x80801C1C: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_80801C20:
    // 0x80801C20: jal         0x800C064C
    // 0x80801C24: nop

    func_800C064C(rdram, ctx);
        goto after_5;
    // 0x80801C24: nop

    after_5:
    // 0x80801C28: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80801C2C: bnel        $v0, $v1, L_80801C64
    if (ctx->r2 != ctx->r3) {
        // 0x80801C30: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80801C64;
    }
    goto skip_1;
    // 0x80801C30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80801C34: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80801C38: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80801C3C: beq         $v0, $v1, L_80801C58
    if (ctx->r2 == ctx->r3) {
        // 0x80801C40: swc1        $f16, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
            goto L_80801C58;
    }
    // 0x80801C40: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x80801C44: lbu         $t1, 0x72($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X72);
    // 0x80801C48: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80801C4C: andi        $t2, $t1, 0xFF03
    ctx->r10 = ctx->r9 & 0XFF03;
    // 0x80801C50: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80801C54: sb          $t3, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r11;
L_80801C58:
    // 0x80801C58: b           L_80801C64
    // 0x80801C5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801C64;
    // 0x80801C5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801C60:
    // 0x80801C60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801C64:
    // 0x80801C64: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80801C68: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80801C6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801C70: jr          $ra
    // 0x80801C74: nop

    return;
    // 0x80801C74: nop

;}
RECOMP_FUNC void _chlagoonpirate_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086280: syscall     297
    recomp_syscall_handler(rdram, ctx, 0x80086280);
    return;
    // 0x80086284: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _badust_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084A00: syscall     125
    recomp_syscall_handler(rdram, ctx, 0x80084A00);
    return;
    // 0x80084A04: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_8010E358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E358: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010E35C: lw          $a0, 0x7074($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7074);
    // 0x8010E360: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010E364: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010E368: beql        $a0, $zero, L_8010E384
    if (ctx->r4 == 0) {
        // 0x8010E36C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010E384;
    }
    goto skip_0;
    // 0x8010E36C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8010E370: jal         0x800B38E8
    // 0x8010E374: nop

    func_800B38E8(rdram, ctx);
        goto after_0;
    // 0x8010E374: nop

    after_0:
    // 0x8010E378: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010E37C: sw          $v0, 0x7074($at)
    MEM_W(0X7074, ctx->r1) = ctx->r2;
    // 0x8010E380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010E384:
    // 0x8010E384: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010E388: jr          $ra
    // 0x8010E38C: nop

    return;
    // 0x8010E38C: nop

;}
RECOMP_FUNC void _bskazstill_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083640: syscall     70
    recomp_syscall_handler(rdram, ctx, 0x80083640);
    return;
    // 0x80083644: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
