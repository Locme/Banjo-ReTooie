#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void suexpressmorph_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800718: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080071C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800720: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800724: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80800728: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8080072C: jal         0x808006D8
    // 0x80800730: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    suexpressmorph_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800730: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800734: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800738: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x8080073C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3170, 0X1320) << 16);
    // 0x80800740: lh          $t9, 0x2($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X2);
    // 0x80800744: addiu       $a1, $a1, 0x1320
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3170, 0X1320));
    // 0x80800748: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8080074C: multu       $t9, $a3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800750: sb          $zero, 0x5($a2)
    MEM_B(0X5, ctx->r6) = 0;
    // 0x80800754: sb          $t8, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r24;
    // 0x80800758: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080075C: addiu       $v0, $a2, 0x8
    ctx->r2 = ADD32(ctx->r6, 0X8);
    // 0x80800760: mflo        $t1
    ctx->r9 = lo;
    // 0x80800764: addu        $t2, $a1, $t1
    ctx->r10 = ADD32(ctx->r5, ctx->r9);
    // 0x80800768: lbu         $t0, 0x7($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0X7);
    // 0x8080076C: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x80800770: addu        $v1, $t3, $a2
    ctx->r3 = ADD32(ctx->r11, ctx->r6);
    // 0x80800774: blez        $t0, L_808007B8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80800778: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_808007B8;
    }
    // 0x80800778: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8080077C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800780: nop

    // 0x80800784: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_80800788:
    // 0x80800788: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x8080078C: lh          $t4, 0x2($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X2);
    // 0x80800790: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800794: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800798: multu       $t4, $a3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080079C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808007A0: mflo        $t5
    ctx->r13 = lo;
    // 0x808007A4: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x808007A8: lbu         $t7, 0x7($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X7);
    // 0x808007AC: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x808007B0: bnel        $at, $zero, L_80800788
    if (ctx->r1 != 0) {
        // 0x808007B4: swc1        $f0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
            goto L_80800788;
    }
    goto skip_0;
    // 0x808007B4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    skip_0:
L_808007B8:
    // 0x808007B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007C0: jr          $ra
    // 0x808007C4: nop

    return;
    // 0x808007C4: nop

    // 0x808007C8: nop

    // 0x808007CC: nop

;}
RECOMP_FUNC void _gcsectionskip_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087AD0: syscall     653
    recomp_syscall_handler(rdram, ctx, 0x80087AD0);
    return;
    // 0x80087AD4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801B00_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801B04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801B08: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80801B0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801B10: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801B14: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(932, 0X2DBC) << 16);
    // 0x80801B18: addiu       $t7, $t7, 0x2DBC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(932, 0X2DBC));
    // 0x80801B1C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80801B20: lw          $a2, 0x38($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X38);
    // 0x80801B24: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801B28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801B2C: jal         0x800BBCB8
    // 0x80801B30: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80801B30: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x80801B34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801B38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801B3C: jr          $ra
    // 0x80801B40: nop

    return;
    // 0x80801B40: nop

;}
RECOMP_FUNC void bskazmove_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BC8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800BCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BD0: bne         $a1, $at, L_80800C20
    if (ctx->r5 != ctx->r1) {
        // 0x80800BD4: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80800C20;
    }
    // 0x80800BD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800BD8: jal         0x8009EF10
    // 0x80800BDC: nop

    bastick_getZone(rdram, ctx);
        goto after_0;
    // 0x80800BDC: nop

    after_0:
    // 0x80800BE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800BE4: bnel        $v0, $at, L_80800C24
    if (ctx->r2 != ctx->r1) {
        // 0x80800BE8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800C24;
    }
    goto skip_0;
    // 0x80800BE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80800BEC: jal         0x8009EF1C
    // 0x80800BF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bastick_getZonePosition(rdram, ctx);
        goto after_1;
    // 0x80800BF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800BF4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(260, 0XC64) << 16);
    // 0x80800BF8: lwc1        $f4, 0xC64($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(260, 0XC64));
    // 0x80800BFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800C00: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800C04: nop

    // 0x80800C08: bc1fl       L_80800C24
    if (!c1cs) {
        // 0x80800C0C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800C24;
    }
    goto skip_1;
    // 0x80800C0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x80800C10: jal         0x800962B0
    // 0x80800C14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800962B0(rdram, ctx);
        goto after_2;
    // 0x80800C14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800C18: b           L_80800C30
    // 0x80800C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C30;
    // 0x80800C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C20:
    // 0x80800C20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800C24:
    // 0x80800C24: jal         0x800962B0
    // 0x80800C28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800962B0(rdram, ctx);
        goto after_3;
    // 0x80800C28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800C2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C30:
    // 0x80800C30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C34: jr          $ra
    // 0x80800C38: nop

    return;
    // 0x80800C38: nop

;}
RECOMP_FUNC void func_8080569C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080569C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x808056A0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x808056A4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x808056A8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x808056AC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x808056B0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x808056B4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x808056B8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x808056BC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x808056C0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x808056C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808056C8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808056CC: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x808056D0: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x808056D4: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x808056D8: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x808056DC: beq         $v0, $zero, L_80805700
    if (ctx->r2 == 0) {
        // 0x808056E0: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80805700;
    }
    // 0x808056E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808056E4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808056E8: beq         $v0, $at, L_80805724
    if (ctx->r2 == ctx->r1) {
        // 0x808056EC: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80805724;
    }
    // 0x808056EC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808056F0: beq         $v0, $at, L_808058D8
    if (ctx->r2 == ctx->r1) {
        // 0x808056F4: nop
    
            goto L_808058D8;
    }
    // 0x808056F4: nop

    // 0x808056F8: b           L_808058F8
    // 0x808056FC: nop

        goto L_808058F8;
    // 0x808056FC: nop

L_80805700:
    // 0x80805700: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80805704:
    // 0x80805704: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80805708: jal         0x80805BA0
    // 0x8080570C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80805BA0_chgameselect(rdram, ctx);
        goto after_0;
    // 0x8080570C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80805710: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80805714: bnel        $s1, $s0, L_80805704
    if (ctx->r17 != ctx->r16) {
        // 0x80805718: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80805704;
    }
    goto skip_0;
    // 0x80805718: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
    // 0x8080571C: b           L_8080592C
    // 0x80805720: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8080592C;
    // 0x80805720: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80805724:
    // 0x80805724: jal         0x80088360
    // 0x80805728: nop

    _gcstatusDll_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80805728: nop

    after_1:
    // 0x8080572C: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80805730: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80805734: jal         0x80100094
    // 0x80805738: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80805738: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8080573C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80805740: blez        $s7, L_8080588C
    if (SIGNED(ctx->r23) <= 0) {
        // 0x80805744: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8080588C;
    }
    // 0x80805744: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80805748: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080574C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80805750: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80805754: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x80805758: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x8080575C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_80805760:
    // 0x80805760: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805764: jal         0x80016068
    // 0x80805768: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_80016068(rdram, ctx);
        goto after_3;
    // 0x80805768: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_3:
    // 0x8080576C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805770: jal         0x80015E80
    // 0x80805774: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_80015E80(rdram, ctx);
        goto after_4;
    // 0x80805774: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_4:
    // 0x80805778: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x8080577C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x80805780: beq         $v0, $zero, L_808057BC
    if (ctx->r2 == 0) {
        // 0x80805784: nop
    
            goto L_808057BC;
    }
    // 0x80805784: nop

    // 0x80805788: beq         $v0, $s4, L_808057A0
    if (ctx->r2 == ctx->r20) {
        // 0x8080578C: sll         $t7, $s1, 2
        ctx->r15 = S32(ctx->r17 << 2);
            goto L_808057A0;
    }
    // 0x8080578C: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80805790: beq         $v0, $fp, L_8080585C
    if (ctx->r2 == ctx->r30) {
        // 0x80805794: lw          $t2, 0x64($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X64);
            goto L_8080585C;
    }
    // 0x80805794: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x80805798: b           L_80805880
    // 0x8080579C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80805880;
    // 0x8080579C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_808057A0:
    // 0x808057A0: addu        $a0, $s5, $t7
    ctx->r4 = ADD32(ctx->r21, ctx->r15);
    // 0x808057A4: jal         0x800D9078
    // 0x808057A8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800D9078(rdram, ctx);
        goto after_5;
    // 0x808057A8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_5:
    // 0x808057AC: beql        $v0, $zero, L_80805880
    if (ctx->r2 == 0) {
        // 0x808057B0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80805880;
    }
    goto skip_1;
    // 0x808057B0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x808057B4: b           L_8080587C
    // 0x808057B8: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
        goto L_8080587C;
    // 0x808057B8: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
L_808057BC:
    // 0x808057BC: bne         $s4, $t8, L_808057EC
    if (ctx->r20 != ctx->r24) {
        // 0x808057C0: lwc1        $f0, 0x58($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
            goto L_808057EC;
    }
    // 0x808057C0: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x808057C4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x808057C8: sb          $t9, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r25;
    // 0x808057CC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808057D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808057D4: jal         0x80087DF0
    // 0x808057D8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    _gcnewoption_entrypoint_43(rdram, ctx);
        goto after_6;
    // 0x808057D8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_6:
    // 0x808057DC: jal         0x80803CC0
    // 0x808057E0: nop

    func_80803CC0_chgameselect(rdram, ctx);
        goto after_7;
    // 0x808057E0: nop

    after_7:
    // 0x808057E4: b           L_80805880
    // 0x808057E8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80805880;
    // 0x808057E8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_808057EC:
    // 0x808057EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7D68) << 16);
    // 0x808057F0: lwc1        $f4, 0x7D68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7D68));
    // 0x808057F4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808057F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808057FC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80805800: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80805804: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x80805808: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7D6C) << 16);
    // 0x8080580C: bc1f        L_80805828
    if (!c1cs) {
        // 0x80805810: nop
    
            goto L_80805828;
    }
    // 0x80805810: nop

    // 0x80805814: jal         0x808062EC
    // 0x80805818: addu        $s0, $s5, $t0
    ctx->r16 = ADD32(ctx->r21, ctx->r8);
    func_808062EC_chgameselect(rdram, ctx);
        goto after_8;
    // 0x80805818: addu        $s0, $s5, $t0
    ctx->r16 = ADD32(ctx->r21, ctx->r8);
    after_8:
    // 0x8080581C: sb          $s6, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r22;
    // 0x80805820: b           L_8080587C
    // 0x80805824: swc1        $f20, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f20.u32l;
        goto L_8080587C;
    // 0x80805824: swc1        $f20, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f20.u32l;
L_80805828:
    // 0x80805828: lwc1        $f6, 0x7D6C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7D6C));
    // 0x8080582C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80805830: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80805834: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80805838: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8080583C: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x80805840: bc1fl       L_80805880
    if (!c1cs) {
        // 0x80805844: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80805880;
    }
    goto skip_2;
    // 0x80805844: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x80805848: jal         0x808062EC
    // 0x8080584C: addu        $s0, $s5, $t1
    ctx->r16 = ADD32(ctx->r21, ctx->r9);
    func_808062EC_chgameselect(rdram, ctx);
        goto after_9;
    // 0x8080584C: addu        $s0, $s5, $t1
    ctx->r16 = ADD32(ctx->r21, ctx->r9);
    after_9:
    // 0x80805850: sb          $s6, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r22;
    // 0x80805854: b           L_8080587C
    // 0x80805858: swc1        $f20, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f20.u32l;
        goto L_8080587C;
    // 0x80805858: swc1        $f20, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f20.u32l;
L_8080585C:
    // 0x8080585C: bne         $s4, $t2, L_8080587C
    if (ctx->r20 != ctx->r10) {
        // 0x80805860: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8080587C;
    }
    // 0x80805860: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80805864: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x80805868: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080586C: jal         0x80087DF0
    // 0x80805870: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _gcnewoption_entrypoint_43(rdram, ctx);
        goto after_10;
    // 0x80805870: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x80805874: jal         0x80803CE0
    // 0x80805878: nop

    func_80803CE0_chgameselect(rdram, ctx);
        goto after_11;
    // 0x80805878: nop

    after_11:
L_8080587C:
    // 0x8080587C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80805880:
    // 0x80805880: bne         $s1, $s7, L_80805760
    if (ctx->r17 != ctx->r23) {
        // 0x80805884: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80805760;
    }
    // 0x80805884: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80805888: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8080588C:
    // 0x8080588C: blez        $s7, L_808058B0
    if (SIGNED(ctx->r23) <= 0) {
        // 0x80805890: addiu       $fp, $zero, 0x2
        ctx->r30 = ADD32(0, 0X2);
            goto L_808058B0;
    }
    // 0x80805890: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x80805894: or          $s2, $s5, $zero
    ctx->r18 = ctx->r21 | 0;
L_80805898:
    // 0x80805898: lbu         $t3, 0x0($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X0);
    // 0x8080589C: bne         $fp, $t3, L_808058B0
    if (ctx->r30 != ctx->r11) {
        // 0x808058A0: nop
    
            goto L_808058B0;
    }
    // 0x808058A0: nop

    // 0x808058A4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808058A8: bne         $s1, $s7, L_80805898
    if (ctx->r17 != ctx->r23) {
        // 0x808058AC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80805898;
    }
    // 0x808058AC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_808058B0:
    // 0x808058B0: bne         $s1, $s7, L_80805928
    if (ctx->r17 != ctx->r23) {
        // 0x808058B4: lw          $t4, 0x80($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X80);
            goto L_80805928;
    }
    // 0x808058B4: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x808058B8: jal         0x80802F8C
    // 0x808058BC: lw          $a0, 0x30($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X30);
    func_80802F8C_chgameselect(rdram, ctx);
        goto after_12;
    // 0x808058BC: lw          $a0, 0x30($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X30);
    after_12:
    // 0x808058C0: beq         $v0, $zero, L_80805928
    if (ctx->r2 == 0) {
        // 0x808058C4: lw          $t5, 0x80($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X80);
            goto L_80805928;
    }
    // 0x808058C4: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x808058C8: lbu         $t7, 0x65($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X65);
    // 0x808058CC: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x808058D0: b           L_80805928
    // 0x808058D4: sb          $t8, 0x65($t5)
    MEM_B(0X65, ctx->r13) = ctx->r24;
        goto L_80805928;
    // 0x808058D4: sb          $t8, 0x65($t5)
    MEM_B(0X65, ctx->r13) = ctx->r24;
L_808058D8:
    // 0x808058D8: jal         0x80087E00
    // 0x808058DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    _gcnewoption_entrypoint_45(rdram, ctx);
        goto after_13;
    // 0x808058DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_13:
    // 0x808058E0: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x808058E4: addiu       $a1, $v0, 0x1E
    ctx->r5 = ADD32(ctx->r2, 0X1E);
    // 0x808058E8: jal         0x808026C8
    // 0x808058EC: lw          $a0, 0x24($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X24);
    func_808026C8_chgameselect(rdram, ctx);
        goto after_14;
    // 0x808058EC: lw          $a0, 0x24($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X24);
    after_14:
    // 0x808058F0: b           L_8080592C
    // 0x808058F4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8080592C;
    // 0x808058F4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_808058F8:
    // 0x808058F8: jal         0x80015FA0
    // 0x808058FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80015FA0(rdram, ctx);
        goto after_15;
    // 0x808058FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
    // 0x80805900: beq         $v0, $zero, L_80805928
    if (ctx->r2 == 0) {
        // 0x80805904: lw          $t0, 0x80($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X80);
            goto L_80805928;
    }
    // 0x80805904: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80805908: jal         0x80802F8C
    // 0x8080590C: lw          $a0, 0x30($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X30);
    func_80802F8C_chgameselect(rdram, ctx);
        goto after_16;
    // 0x8080590C: lw          $a0, 0x30($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X30);
    after_16:
    // 0x80805910: beql        $v0, $zero, L_8080592C
    if (ctx->r2 == 0) {
        // 0x80805914: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8080592C;
    }
    goto skip_3;
    // 0x80805914: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_3:
    // 0x80805918: lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X80);
    // 0x8080591C: lbu         $t2, 0x65($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X65);
    // 0x80805920: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x80805924: sb          $t3, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r11;
L_80805928:
    // 0x80805928: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8080592C:
    // 0x8080592C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80805930: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80805934: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80805938: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8080593C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80805940: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80805944: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80805948: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8080594C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80805950: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80805954: jr          $ra
    // 0x80805958: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80805958: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_8080202C_sucoaster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080202C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802030: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802034: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80802038: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080203C: jal         0x80802760
    // 0x80802040: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80802760_sucoaster(rdram, ctx);
        goto after_0;
    // 0x80802040: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80802044: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80802048: bne         $v0, $at, L_80802058
    if (ctx->r2 != ctx->r1) {
        // 0x8080204C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80802058;
    }
    // 0x8080204C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802050: b           L_808020A8
    // 0x80802054: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808020A8;
    // 0x80802054: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802058:
    // 0x80802058: jal         0x800F6478
    // 0x8080205C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_800F6478(rdram, ctx);
        goto after_1;
    // 0x8080205C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x80802060: bne         $v0, $zero, L_80802070
    if (ctx->r2 != 0) {
        // 0x80802064: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80802070;
    }
    // 0x80802064: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80802068: b           L_808020A8
    // 0x8080206C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808020A8;
    // 0x8080206C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802070:
    // 0x80802070: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80802074: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x80802078: sll         $t9, $t7, 9
    ctx->r25 = S32(ctx->r15 << 9);
    // 0x8080207C: bltz        $t9, L_8080208C
    if (SIGNED(ctx->r25) < 0) {
        // 0x80802080: nop
    
            goto L_8080208C;
    }
    // 0x80802080: nop

    // 0x80802084: b           L_808020A8
    // 0x80802088: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808020A8;
    // 0x80802088: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080208C:
    // 0x8080208C: jal         0x800F5A00
    // 0x80802090: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x80802090: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x80802094: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80802098: lui         $a1, 0x44E1
    ctx->r5 = S32(0X44E1 << 16);
    // 0x8080209C: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x808020A0: jal         0x800EFFB4
    // 0x808020A4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EFFB4(rdram, ctx);
        goto after_3;
    // 0x808020A4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_3:
L_808020A8:
    // 0x808020A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808020AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808020B0: jr          $ra
    // 0x808020B4: nop

    return;
    // 0x808020B4: nop

;}
RECOMP_FUNC void func_80800150_chfactorycrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800150: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800154: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800158: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080015C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800160: jal         0x80100094
    // 0x80800164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800168: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x8080016C: jal         0x80800898
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800898_chfactorycrusher(rdram, ctx);
        goto after_1;
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800174: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x80800178: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x8080017C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800180: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800184: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x80800188: beq         $at, $zero, L_80800514
    if (ctx->r1 == 0) {
        // 0x8080018C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800514;
    }
    // 0x8080018C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800190: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1136, 0XA20) << 16);
    // 0x80800194: addu        $at, $at, $t8
    gpr jr_addend_8080019C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800198: lw          $t8, 0xA20($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1136, 0XA20));
    // 0x8080019C: jr          $t8
    // 0x808001A0: nop

    switch (jr_addend_8080019C >> 2) {
        case 0: goto L_808001A4; break;
        case 1: goto L_808002E0; break;
        case 2: goto L_80800428; break;
        case 3: goto L_80800460; break;
        case 4: goto L_808004FC; break;
        default: switch_error(__func__, 0x8080019C, 0x80800A20);
    }
    // 0x808001A0: nop

L_808001A4:
    // 0x808001A4: jal         0x800DA298
    // 0x808001A8: addiu       $a0, $zero, 0x329
    ctx->r4 = ADD32(0, 0X329);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x808001A8: addiu       $a0, $zero, 0x329
    ctx->r4 = ADD32(0, 0X329);
    after_2:
    // 0x808001AC: bnel        $v0, $zero, L_808002D8
    if (ctx->r2 != 0) {
        // 0x808001B0: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_808002D8;
    }
    goto skip_0;
    // 0x808001B0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_0:
    // 0x808001B4: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x808001B8: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x808001BC: sll         $t1, $t9, 12
    ctx->r9 = S32(ctx->r25 << 12);
    // 0x808001C0: bltzl       $t1, L_808002D8
    if (SIGNED(ctx->r9) < 0) {
        // 0x808001C4: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_808002D8;
    }
    goto skip_1;
    // 0x808001C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_1:
    // 0x808001C8: lw          $t3, 0x18($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X18);
    // 0x808001CC: bnel        $t3, $zero, L_808002D8
    if (ctx->r11 != 0) {
        // 0x808001D0: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_808002D8;
    }
    goto skip_2;
    // 0x808001D0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_2:
    // 0x808001D4: jal         0x800D90A4
    // 0x808001D8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_3;
    // 0x808001D8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_3:
    // 0x808001DC: beql        $v0, $zero, L_808002D8
    if (ctx->r2 == 0) {
        // 0x808001E0: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_808002D8;
    }
    goto skip_3;
    // 0x808001E0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_3:
    // 0x808001E4: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001EC: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x808001F0: andi        $t5, $t4, 0xFFEF
    ctx->r13 = ctx->r12 & 0XFFEF;
    // 0x808001F4: jal         0x80800738
    // 0x808001F8: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    func_80800738_chfactorycrusher(rdram, ctx);
        goto after_4;
    // 0x808001F8: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    after_4:
    // 0x808001FC: beql        $v0, $zero, L_808002BC
    if (ctx->r2 == 0) {
        // 0x80800200: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002BC;
    }
    goto skip_4;
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x80800204: jal         0x800F54E4
    // 0x80800208: nop

    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x80800208: nop

    after_5:
    // 0x8080020C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800210: jal         0x800F64A4
    // 0x80800214: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    func_800F64A4(rdram, ctx);
        goto after_6;
    // 0x80800214: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_6:
    // 0x80800218: bnel        $v0, $zero, L_80800240
    if (ctx->r2 != 0) {
        // 0x8080021C: lwc1        $f4, 0x18($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
            goto L_80800240;
    }
    goto skip_5;
    // 0x8080021C: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    skip_5:
    // 0x80800220: jal         0x800F54E4
    // 0x80800224: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x80800224: nop

    after_7:
    // 0x80800228: jal         0x800F5578
    // 0x8080022C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5578(rdram, ctx);
        goto after_8;
    // 0x8080022C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80800230: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80800234: bne         $at, $zero, L_80800278
    if (ctx->r1 != 0) {
        // 0x80800238: nop
    
            goto L_80800278;
    }
    // 0x80800238: nop

    // 0x8080023C: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
L_80800240:
    // 0x80800240: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80800244: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x80800248: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080024C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800250: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800254: bc1f        L_80800264
    if (!c1cs) {
        // 0x80800258: nop
    
            goto L_80800264;
    }
    // 0x80800258: nop

    // 0x8080025C: b           L_80800264
    // 0x80800260: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
        goto L_80800264;
    // 0x80800260: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
L_80800264:
    // 0x80800264: jal         0x80085708
    // 0x80800268: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_9;
    // 0x80800268: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_9:
    // 0x8080026C: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80800270: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x80800274: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
L_80800278:
    // 0x80800278: jal         0x800F54E4
    // 0x8080027C: nop

    func_800F54E4(rdram, ctx);
        goto after_10;
    // 0x8080027C: nop

    after_10:
    // 0x80800280: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800284: jal         0x800F7F98
    // 0x80800288: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7F98(rdram, ctx);
        goto after_11;
    // 0x80800288: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x8080028C: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80800290: addiu       $a0, $zero, 0x3EE
    ctx->r4 = ADD32(0, 0X3EE);
    // 0x80800294: addiu       $a1, $zero, 0xB9
    ctx->r5 = ADD32(0, 0XB9);
    // 0x80800298: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x8080029C: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x808002A0: jal         0x80101180
    // 0x808002A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_12;
    // 0x808002A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x808002A8: jal         0x8010A624
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A624(rdram, ctx);
        goto after_13;
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808002B0: jal         0x8010A624
    // 0x808002B4: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    func_8010A624(rdram, ctx);
        goto after_14;
    // 0x808002B4: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_14:
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002BC:
    // 0x808002BC: jal         0x80101FDC
    // 0x808002C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_15;
    // 0x808002C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_15:
    // 0x808002C4: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808002C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002CC: nop

    // 0x808002D0: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x808002D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_808002D8:
    // 0x808002D8: b           L_80800514
    // 0x808002DC: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
        goto L_80800514;
    // 0x808002DC: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
L_808002E0:
    // 0x808002E0: jal         0x800D9078
    // 0x808002E4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_16;
    // 0x808002E4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_16:
    // 0x808002E8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808002EC: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x808002F0: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808002F4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808002F8: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    // 0x808002FC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800300: jal         0x800F12D4
    // 0x80800304: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F12D4(rdram, ctx);
        goto after_17;
    // 0x80800304: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_17:
    // 0x80800308: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080030C: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80800310: jal         0x808008B8
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008B8_chfactorycrusher(rdram, ctx);
        goto after_18;
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800318: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8080031C: jal         0x808008B8
    // 0x80800320: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    func_808008B8_chfactorycrusher(rdram, ctx);
        goto after_19;
    // 0x80800320: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    after_19:
    // 0x80800324: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x80800328: sll         $t4, $t2, 11
    ctx->r12 = S32(ctx->r10 << 11);
    // 0x8080032C: bgezl       $t4, L_80800340
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800330: lw          $t5, 0x54($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X54);
            goto L_80800340;
    }
    goto skip_6;
    // 0x80800330: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    skip_6:
    // 0x80800334: jal         0x808008F0
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008F0_chfactorycrusher(rdram, ctx);
        goto after_20;
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8080033C: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
L_80800340:
    // 0x80800340: beql        $t5, $zero, L_80800518
    if (ctx->r13 == 0) {
        // 0x80800344: lw          $t4, 0x64($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X64);
            goto L_80800518;
    }
    goto skip_7;
    // 0x80800344: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    skip_7:
    // 0x80800348: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x8080034C: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800350: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800354: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800358: bne         $t7, $at, L_80800404
    if (ctx->r15 != ctx->r1) {
        // 0x8080035C: lui         $a1, 0x42A0
        ctx->r5 = S32(0X42A0 << 16);
            goto L_80800404;
    }
    // 0x8080035C: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x80800360: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x80800364: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800368: jal         0x800E1610
    // 0x8080036C: addiu       $a3, $s0, 0x28
    ctx->r7 = ADD32(ctx->r16, 0X28);
    func_800E1610(rdram, ctx);
        goto after_21;
    // 0x8080036C: addiu       $a3, $s0, 0x28
    ctx->r7 = ADD32(ctx->r16, 0X28);
    after_21:
    // 0x80800370: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800374: lui         $a1, 0x44FA
    ctx->r5 = S32(0X44FA << 16);
    // 0x80800378: jal         0x800E148C
    // 0x8080037C: lui         $a2, 0x45FA
    ctx->r6 = S32(0X45FA << 16);
    func_800E148C(rdram, ctx);
        goto after_22;
    // 0x8080037C: lui         $a2, 0x45FA
    ctx->r6 = S32(0X45FA << 16);
    after_22:
    // 0x80800380: jal         0x8010D640
    // 0x80800384: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    func_8010D640(rdram, ctx);
        goto after_23;
    // 0x80800384: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_23:
    // 0x80800388: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x8080038C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800390: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800394: jal         0x800F2100
    // 0x80800398: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    mlAbsF(rdram, ctx);
        goto after_24;
    // 0x80800398: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    after_24:
    // 0x8080039C: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x808003A0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808003A4: jal         0x800F0E00
    // 0x808003A8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F0E00(rdram, ctx);
        goto after_25;
    // 0x808003A8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_25:
    // 0x808003AC: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x808003B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003B4: lui         $at, 0x4030
    ctx->r1 = S32(0X4030 << 16);
    // 0x808003B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808003BC: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808003C0: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808003C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808003C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808003CC: lui         $a2, 0x3EB3
    ctx->r6 = S32(0X3EB3 << 16);
    // 0x808003D0: mul.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808003D4: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x808003D8: nop

    // 0x808003DC: bc1f        L_808003F0
    if (!c1cs) {
        // 0x808003E0: nop
    
            goto L_808003F0;
    }
    // 0x808003E0: nop

    // 0x808003E4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x808003E8: jal         0x80018820
    // 0x808003EC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    func_80018820(rdram, ctx);
        goto after_26;
    // 0x808003EC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    after_26:
L_808003F0:
    // 0x808003F0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1136, 0XAE0) << 16);
    // 0x808003F4: addiu       $a2, $a2, 0xAE0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1136, 0XAE0));
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003FC: jal         0x80089D18
    // 0x80800400: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_27;
    // 0x80800400: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_27:
L_80800404:
    // 0x80800404: jal         0x80800800
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800800_chfactorycrusher(rdram, ctx);
        goto after_28;
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800410: jal         0x80101FDC
    // 0x80800414: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_29;
    // 0x80800414: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_29:
    // 0x80800418: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1136, 0XA34) << 16);
    // 0x8080041C: lwc1        $f18, 0xA34($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1136, 0XA34));
    // 0x80800420: b           L_80800514
    // 0x80800424: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
        goto L_80800514;
    // 0x80800424: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
L_80800428:
    // 0x80800428: jal         0x800D90A4
    // 0x8080042C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_30;
    // 0x8080042C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_30:
    // 0x80800430: beq         $v0, $zero, L_80800450
    if (ctx->r2 == 0) {
        // 0x80800434: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800450;
    }
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800438: jal         0x80101FDC
    // 0x8080043C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_31;
    // 0x8080043C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_31:
    // 0x80800440: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800444: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800448: nop

    // 0x8080044C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80800450:
    // 0x80800450: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800454: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800458: b           L_80800514
    // 0x8080045C: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
        goto L_80800514;
    // 0x8080045C: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
L_80800460:
    // 0x80800460: jal         0x800D9078
    // 0x80800464: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_32;
    // 0x80800464: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_32:
    // 0x80800468: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080046C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800470: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800474: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800478: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080047C: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800480: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    // 0x80800484: jal         0x800F12D4
    // 0x80800488: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F12D4(rdram, ctx);
        goto after_33;
    // 0x80800488: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_33:
    // 0x8080048C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800490: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80800494: jal         0x808008B8
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008B8_chfactorycrusher(rdram, ctx);
        goto after_34;
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x8080049C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x808004A0: jal         0x808008B8
    // 0x808004A4: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    func_808008B8_chfactorycrusher(rdram, ctx);
        goto after_35;
    // 0x808004A4: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    after_35:
    // 0x808004A8: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x808004AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B0: beql        $t8, $zero, L_80800518
    if (ctx->r24 == 0) {
        // 0x808004B4: lw          $t4, 0x64($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X64);
            goto L_80800518;
    }
    goto skip_8;
    // 0x808004B4: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    skip_8:
    // 0x808004B8: jal         0x80101FDC
    // 0x808004BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_36;
    // 0x808004BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_36:
    // 0x808004C0: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x808004C4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808004C8: sll         $t1, $t9, 11
    ctx->r9 = S32(ctx->r25 << 11);
    // 0x808004CC: bgezl       $t1, L_808004E4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808004D0: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_808004E4;
    }
    goto skip_9;
    // 0x808004D0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_9:
    // 0x808004D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808004D8: b           L_808004EC
    // 0x808004DC: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
        goto L_808004EC;
    // 0x808004DC: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x808004E0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_808004E4:
    // 0x808004E4: nop

    // 0x808004E8: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
L_808004EC:
    // 0x808004EC: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x808004F0: andi        $t3, $t2, 0xFFEF
    ctx->r11 = ctx->r10 & 0XFFEF;
    // 0x808004F4: b           L_80800514
    // 0x808004F8: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
        goto L_80800514;
    // 0x808004F8: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
L_808004FC:
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800500: jal         0x808008B8
    // 0x80800504: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    func_808008B8_chfactorycrusher(rdram, ctx);
        goto after_37;
    // 0x80800504: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    after_37:
    // 0x80800508: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8080050C: jal         0x808008B8
    // 0x80800510: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    func_808008B8_chfactorycrusher(rdram, ctx);
        goto after_38;
    // 0x80800510: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    after_38:
L_80800514:
    // 0x80800514: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
L_80800518:
    // 0x80800518: sll         $t6, $t4, 12
    ctx->r14 = S32(ctx->r12 << 12);
    // 0x8080051C: bltzl       $t6, L_80800570
    if (SIGNED(ctx->r14) < 0) {
        // 0x80800520: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800570;
    }
    goto skip_10;
    // 0x80800520: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_10:
    // 0x80800524: jal         0x808006CC
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006CC_chfactorycrusher(rdram, ctx);
        goto after_39;
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x8080052C: jal         0x808006CC
    // 0x80800530: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    func_808006CC_chfactorycrusher(rdram, ctx);
        goto after_40;
    // 0x80800530: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_40:
    // 0x80800534: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x80800538: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x8080053C: bltzl       $t9, L_80800570
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800540: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800570;
    }
    goto skip_11;
    // 0x80800540: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_11:
    // 0x80800544: lw          $a1, 0x7C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X7C);
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080054C: sll         $t0, $a1, 19
    ctx->r8 = S32(ctx->r5 << 19);
    // 0x80800550: jal         0x8010A654
    // 0x80800554: srl         $a1, $t0, 31
    ctx->r5 = S32(U32(ctx->r8) >> 31);
    func_8010A654(rdram, ctx);
        goto after_41;
    // 0x80800554: srl         $a1, $t0, 31
    ctx->r5 = S32(U32(ctx->r8) >> 31);
    after_41:
    // 0x80800558: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8080055C: lw          $a1, 0x7C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X7C);
    // 0x80800560: sll         $t3, $a1, 19
    ctx->r11 = S32(ctx->r5 << 19);
    // 0x80800564: jal         0x8010A654
    // 0x80800568: srl         $a1, $t3, 31
    ctx->r5 = S32(U32(ctx->r11) >> 31);
    func_8010A654(rdram, ctx);
        goto after_42;
    // 0x80800568: srl         $a1, $t3, 31
    ctx->r5 = S32(U32(ctx->r11) >> 31);
    after_42:
    // 0x8080056C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800570:
    // 0x80800570: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800574: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80800578: jr          $ra
    // 0x8080057C: nop

    return;
    // 0x8080057C: nop

;}
RECOMP_FUNC void func_8080218C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080218C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802194: beq         $a1, $zero, L_808021A8
    if (ctx->r5 == 0) {
        // 0x80802198: sh          $a0, 0x1C($sp)
        MEM_H(0X1C, ctx->r29) = ctx->r4;
            goto L_808021A8;
    }
    // 0x80802198: sh          $a0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r4;
    // 0x8080219C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808021A0: b           L_808021AC
    // 0x808021A4: sh          $t6, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r14;
        goto L_808021AC;
    // 0x808021A4: sh          $t6, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r14;
L_808021A8:
    // 0x808021A8: sh          $zero, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = 0;
L_808021AC:
    // 0x808021AC: addiu       $a0, $zero, 0x4A8
    ctx->r4 = ADD32(0, 0X4A8);
    // 0x808021B0: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x808021B4: jal         0x80101180
    // 0x808021B8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_80101180(rdram, ctx);
        goto after_0;
    // 0x808021B8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x808021BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808021C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808021C4: jr          $ra
    // 0x808021C8: nop

    return;
    // 0x808021C8: nop

;}
RECOMP_FUNC void capod_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808000B8: jal         0x8008FFE8
    // 0x808000BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x808000BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808000C0: beq         $v0, $zero, L_808000E0
    if (ctx->r2 == 0) {
        // 0x808000C4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808000E0;
    }
    // 0x808000C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000C8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808000CC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x808000D0: jal         0x80089540
    // 0x808000D4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    _ncpod_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x808000D4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808000D8: b           L_808000E8
    // 0x808000DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000E8;
    // 0x808000DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000E0:
    // 0x808000E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000E8:
    // 0x808000E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000EC: jr          $ra
    // 0x808000F0: nop

    return;
    // 0x808000F0: nop

;}
RECOMP_FUNC void subaddiefind_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800440: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800444: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800448: lwc1        $f20, 0x60($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8080044C: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x80800450: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80800454: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800458: addiu       $s7, $sp, 0x48
    ctx->r23 = ADD32(ctx->r29, 0X48);
    // 0x8080045C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800460: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x80800464: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80800468: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8080046C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800470: mul.s       $f20, $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80800474: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80800478: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x8080047C: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x80800480: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800484: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800488: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8080048C: jal         0x801067C4
    // 0x80800490: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_801067C4(rdram, ctx);
        goto after_0;
    // 0x80800490: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_0:
    // 0x80800494: beq         $v0, $zero, L_80800508
    if (ctx->r2 == 0) {
        // 0x80800498: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80800508;
    }
    // 0x80800498: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080049C: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
L_808004A0:
    // 0x808004A0: lw          $t6, 0x6C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X6C);
    // 0x808004A4: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x808004A8: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x808004AC: bne         $s4, $t8, L_808004F8
    if (ctx->r20 != ctx->r24) {
        // 0x808004B0: nop
    
            goto L_808004F8;
    }
    // 0x808004B0: nop

    // 0x808004B4: lw          $t9, 0x64($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X64);
    // 0x808004B8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808004BC: sll         $t1, $t9, 14
    ctx->r9 = S32(ctx->r25 << 14);
    // 0x808004C0: bltz        $t1, L_808004F8
    if (SIGNED(ctx->r9) < 0) {
        // 0x808004C4: nop
    
            goto L_808004F8;
    }
    // 0x808004C4: nop

    // 0x808004C8: jalr        $s3
    // 0x808004CC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    LOOKUP_FUNC(ctx->r19)(rdram, ctx);
        goto after_1;
    // 0x808004CC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x808004D0: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x808004D4: nop

    // 0x808004D8: bc1f        L_808004F8
    if (!c1cs) {
        // 0x808004DC: nop
    
            goto L_808004F8;
    }
    // 0x808004DC: nop

    // 0x808004E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808004E4: sw          $s0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r16;
    // 0x808004E8: bne         $s1, $s6, L_808004F8
    if (ctx->r17 != ctx->r22) {
        // 0x808004EC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_808004F8;
    }
    // 0x808004EC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x808004F0: b           L_8080050C
    // 0x808004F4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_8080050C;
    // 0x808004F4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_808004F8:
    // 0x808004F8: jal         0x8010682C
    // 0x808004FC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_8010682C(rdram, ctx);
        goto after_2;
    // 0x808004FC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_2:
    // 0x80800500: bne         $v0, $zero, L_808004A0
    if (ctx->r2 != 0) {
        // 0x80800504: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808004A0;
    }
    // 0x80800504: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80800508:
    // 0x80800508: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_8080050C:
    // 0x8080050C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800510: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800514: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800518: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8080051C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800520: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800524: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80800528: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8080052C: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x80800530: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x80800534: jr          $ra
    // 0x80800538: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80800538: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void bskazshoessuckspline_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800318: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080031C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(280, 0X470) << 16);
    // 0x80800320: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800324: jr          $ra
    // 0x80800328: lw          $v0, 0x470($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(280, 0X470));
    return;
    // 0x80800328: lw          $v0, 0x470($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(280, 0X470));
;}
RECOMP_FUNC void func_800E7620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7620: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800E7624: addiu       $v1, $v1, -0x2A80
    ctx->r3 = ADD32(ctx->r3, -0X2A80);
    // 0x800E7628: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800E762C: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x800E7630: sw          $t6, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r14;
    // 0x800E7634: sw          $t6, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r14;
    // 0x800E7638: sw          $t6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r14;
    // 0x800E763C: sw          $t6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r14;
    // 0x800E7640: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
    // 0x800E7644: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800E7648: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800E764C: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x800E7650: sw          $t9, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r25;
    // 0x800E7654: jr          $ra
    // 0x800E7658: sb          $zero, 0x24($v1)
    MEM_B(0X24, ctx->r3) = 0;
    return;
    // 0x800E7658: sb          $zero, 0x24($v1)
    MEM_B(0X24, ctx->r3) = 0;
;}
RECOMP_FUNC void func_800D8B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8B80: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800D8B84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D8B88: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x800D8B8C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800D8B90: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D8B94: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    // 0x800D8B98: jal         0x800D8988
    // 0x800D8B9C: sw          $a3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r7;
    func_800D8988(rdram, ctx);
        goto after_0;
    // 0x800D8B9C: sw          $a3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r7;
    after_0:
    // 0x800D8BA0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800D8BA4: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x800D8BA8: jal         0x800EE7F8
    // 0x800D8BAC: lw          $a1, 0xD8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XD8);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x800D8BAC: lw          $a1, 0xD8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XD8);
    after_1:
    // 0x800D8BB0: jal         0x80019CD4
    // 0x800D8BB4: nop

    func_80019CD4(rdram, ctx);
        goto after_2;
    // 0x800D8BB4: nop

    after_2:
    // 0x800D8BB8: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x800D8BBC: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    // 0x800D8BC0: lw          $a2, 0xC8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC8);
    // 0x800D8BC4: jal         0x8001980C
    // 0x800D8BC8: lw          $a3, 0xCC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XCC);
    func_8001980C(rdram, ctx);
        goto after_3;
    // 0x800D8BC8: lw          $a3, 0xCC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XCC);
    after_3:
    // 0x800D8BCC: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x800D8BD0: jal         0x80019224
    // 0x800D8BD4: lw          $a1, 0xD8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XD8);
    func_80019224(rdram, ctx);
        goto after_4;
    // 0x800D8BD4: lw          $a1, 0xD8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XD8);
    after_4:
    // 0x800D8BD8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800D8BDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D8BE0: lw          $v1, 0xD0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XD0);
    // 0x800D8BE4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
L_800D8BE8:
    // 0x800D8BE8: lhu         $t8, 0x0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X0);
    // 0x800D8BEC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D8BF0: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800D8BF4: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800D8BF8: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800D8BFC: bne         $at, $zero, L_800D8BE8
    if (ctx->r1 != 0) {
        // 0x800D8C00: sh          $t8, 0x12($a1)
        MEM_H(0X12, ctx->r5) = ctx->r24;
            goto L_800D8BE8;
    }
    // 0x800D8C00: sh          $t8, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r24;
    // 0x800D8C04: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800D8C08: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x800D8C0C: addiu       $t2, $sp, 0x58
    ctx->r10 = ADD32(ctx->r29, 0X58);
    // 0x800D8C10: lw          $t1, 0xD4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD4);
    // 0x800D8C14: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
L_800D8C18:
    // 0x800D8C18: lh          $t9, 0x14($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X14);
    // 0x800D8C1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D8C20: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800D8C24: sll         $t4, $t9, 4
    ctx->r12 = S32(ctx->r25 << 4);
    // 0x800D8C28: addu        $a3, $t4, $t1
    ctx->r7 = ADD32(ctx->r12, ctx->r9);
    // 0x800D8C2C: addiu       $a0, $a3, 0x18
    ctx->r4 = ADD32(ctx->r7, 0X18);
    // 0x800D8C30: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D8C34: beq         $v0, $t0, L_800D8C5C
    if (ctx->r2 == ctx->r8) {
        // 0x800D8C38: lh          $t5, 0x0($a0)
        ctx->r13 = MEM_H(ctx->r4, 0X0);
            goto L_800D8C5C;
    }
    // 0x800D8C38: lh          $t5, 0x0($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X0);
L_800D8C3C:
    // 0x800D8C3C: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800D8C40: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D8C44: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D8C48: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800D8C4C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800D8C50: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x800D8C54: bne         $v0, $t0, L_800D8C3C
    if (ctx->r2 != ctx->r8) {
        // 0x800D8C58: lh          $t5, 0x0($a0)
        ctx->r13 = MEM_H(ctx->r4, 0X0);
            goto L_800D8C3C;
    }
    // 0x800D8C58: lh          $t5, 0x0($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X0);
L_800D8C5C:
    // 0x800D8C5C: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800D8C60: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D8C64: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800D8C68: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800D8C6C: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x800D8C70: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x800D8C74: bne         $a2, $t2, L_800D8C18
    if (ctx->r6 != ctx->r10) {
        // 0x800D8C78: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_800D8C18;
    }
    // 0x800D8C78: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800D8C7C: addiu       $a0, $sp, 0xAC
    ctx->r4 = ADD32(ctx->r29, 0XAC);
    // 0x800D8C80: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800D8C84: jal         0x800EFB24
    // 0x800D8C88: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800EFB24(rdram, ctx);
        goto after_5;
    // 0x800D8C88: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_5:
    // 0x800D8C8C: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x800D8C90: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x800D8C94: jal         0x800EFB24
    // 0x800D8C98: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800EFB24(rdram, ctx);
        goto after_6;
    // 0x800D8C98: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_6:
    // 0x800D8C9C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800D8CA0: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x800D8CA4: jal         0x800EE97C
    // 0x800D8CA8: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    func_800EE97C(rdram, ctx);
        goto after_7;
    // 0x800D8CA8: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    after_7:
    // 0x800D8CAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D8CB0: lwc1        $f0, 0x5CF4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5CF4);
    // 0x800D8CB4: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800D8CB8: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800D8CBC: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800D8CC0: nop

    // 0x800D8CC4: bc1t        L_800D8D1C
    if (c1cs) {
        // 0x800D8CC8: nop
    
            goto L_800D8D1C;
    }
    // 0x800D8CC8: nop

    // 0x800D8CCC: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x800D8CD0: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800D8CD4: bc1t        L_800D8D1C
    if (c1cs) {
        // 0x800D8CD8: nop
    
            goto L_800D8D1C;
    }
    // 0x800D8CD8: nop

    // 0x800D8CDC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800D8CE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D8CE4: bc1t        L_800D8D1C
    if (c1cs) {
        // 0x800D8CE8: nop
    
            goto L_800D8D1C;
    }
    // 0x800D8CE8: nop

    // 0x800D8CEC: lwc1        $f0, 0x5CF8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5CF8);
    // 0x800D8CF0: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800D8CF4: nop

    // 0x800D8CF8: bc1t        L_800D8D1C
    if (c1cs) {
        // 0x800D8CFC: nop
    
            goto L_800D8D1C;
    }
    // 0x800D8CFC: nop

    // 0x800D8D00: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x800D8D04: nop

    // 0x800D8D08: bc1t        L_800D8D1C
    if (c1cs) {
        // 0x800D8D0C: nop
    
            goto L_800D8D1C;
    }
    // 0x800D8D0C: nop

    // 0x800D8D10: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800D8D14: nop

    // 0x800D8D18: bc1f        L_800D8D4C
    if (!c1cs) {
        // 0x800D8D1C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_800D8D4C;
    }
L_800D8D1C:
    // 0x800D8D1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D8D20: lwc1        $f0, 0x5CFC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5CFC);
    // 0x800D8D24: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800D8D28: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800D8D2C: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800D8D30: nop

    // 0x800D8D34: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800D8D38: nop

    // 0x800D8D3C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800D8D40: swc1        $f12, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f12.u32l;
    // 0x800D8D44: swc1        $f14, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f14.u32l;
    // 0x800D8D48: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
L_800D8D4C:
    // 0x800D8D4C: jal         0x800EEF94
    // 0x800D8D50: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    func_800EEF94(rdram, ctx);
        goto after_8;
    // 0x800D8D50: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_8:
    // 0x800D8D54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D8D58: lwc1        $f18, 0x5D00($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5D00);
    // 0x800D8D5C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800D8D60: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800D8D64: nop

    // 0x800D8D68: bc1f        L_800D8D78
    if (!c1cs) {
        // 0x800D8D6C: nop
    
            goto L_800D8D78;
    }
    // 0x800D8D6C: nop

    // 0x800D8D70: b           L_800D8F30
    // 0x800D8D74: sb          $zero, 0x1A($t6)
    MEM_B(0X1A, ctx->r14) = 0;
        goto L_800D8F30;
    // 0x800D8D74: sb          $zero, 0x1A($t6)
    MEM_B(0X1A, ctx->r14) = 0;
L_800D8D78:
    // 0x800D8D78: jal         0x800F2100
    // 0x800D8D7C: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    mlAbsF(rdram, ctx);
        goto after_9;
    // 0x800D8D7C: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    after_9:
    // 0x800D8D80: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800D8D84: jal         0x800F2100
    // 0x800D8D88: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    mlAbsF(rdram, ctx);
        goto after_10;
    // 0x800D8D88: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x800D8D8C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800D8D90: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800D8D94: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800D8D98: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800D8D9C: nop

    // 0x800D8DA0: bc1f        L_800D8DB0
    if (!c1cs) {
        // 0x800D8DA4: nop
    
            goto L_800D8DB0;
    }
    // 0x800D8DA4: nop

    // 0x800D8DA8: b           L_800D8DB0
    // 0x800D8DAC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_800D8DB0;
    // 0x800D8DAC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800D8DB0:
    // 0x800D8DB0: jal         0x800F2100
    // 0x800D8DB4: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    mlAbsF(rdram, ctx);
        goto after_11;
    // 0x800D8DB4: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    after_11:
    // 0x800D8DB8: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x800D8DBC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800D8DC0: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800D8DC4: addu        $t8, $sp, $t7
    ctx->r24 = ADD32(ctx->r29, ctx->r15);
    // 0x800D8DC8: jal         0x800F2100
    // 0x800D8DCC: lwc1        $f12, 0x58($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X58);
    mlAbsF(rdram, ctx);
        goto after_12;
    // 0x800D8DCC: lwc1        $f12, 0x58($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X58);
    after_12:
    // 0x800D8DD0: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800D8DD4: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x800D8DD8: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800D8DDC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800D8DE0: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x800D8DE4: bc1fl       L_800D8DF4
    if (!c1cs) {
        // 0x800D8DE8: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_800D8DF4;
    }
    goto skip_0;
    // 0x800D8DE8: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x800D8DEC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800D8DF0: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_800D8DF4:
    // 0x800D8DF4: div         $zero, $t9, $t0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r8)));
    // 0x800D8DF8: mfhi        $v0
    ctx->r2 = hi;
    // 0x800D8DFC: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x800D8E00: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x800D8E04: addu        $t6, $sp, $t4
    ctx->r14 = ADD32(ctx->r29, ctx->r12);
    // 0x800D8E08: lwc1        $f10, 0x34($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X34);
    // 0x800D8E0C: lwc1        $f8, 0x94($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X94);
    // 0x800D8E10: addu        $t7, $sp, $t4
    ctx->r15 = ADD32(ctx->r29, ctx->r12);
    // 0x800D8E14: addu        $t8, $sp, $t4
    ctx->r24 = ADD32(ctx->r29, ctx->r12);
    // 0x800D8E18: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800D8E1C: lw          $a3, 0xA0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0XA0);
    // 0x800D8E20: lw          $a2, 0xAC($t7)
    ctx->r6 = MEM_W(ctx->r15, 0XAC);
    // 0x800D8E24: bne         $t0, $zero, L_800D8E30
    if (ctx->r8 != 0) {
        // 0x800D8E28: nop
    
            goto L_800D8E30;
    }
    // 0x800D8E28: nop

    // 0x800D8E2C: break       7
    do_break(2148372012);
L_800D8E30:
    // 0x800D8E30: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D8E34: bne         $t0, $at, L_800D8E48
    if (ctx->r8 != ctx->r1) {
        // 0x800D8E38: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D8E48;
    }
    // 0x800D8E38: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D8E3C: bne         $t9, $at, L_800D8E48
    if (ctx->r25 != ctx->r1) {
        // 0x800D8E40: nop
    
            goto L_800D8E48;
    }
    // 0x800D8E40: nop

    // 0x800D8E44: break       6
    do_break(2148372036);
L_800D8E48:
    // 0x800D8E48: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800D8E4C: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    // 0x800D8E50: jal         0x800EFA4C
    // 0x800D8E54: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    func_800EFA4C(rdram, ctx);
        goto after_13;
    // 0x800D8E54: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    after_13:
    // 0x800D8E58: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x800D8E5C: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800D8E60: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x800D8E64: addiu       $t9, $v1, 0x2
    ctx->r25 = ADD32(ctx->r3, 0X2);
    // 0x800D8E68: div         $zero, $t9, $t0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r8)));
    // 0x800D8E6C: mfhi        $v0
    ctx->r2 = hi;
    // 0x800D8E70: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x800D8E74: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x800D8E78: addu        $t6, $sp, $t4
    ctx->r14 = ADD32(ctx->r29, ctx->r12);
    // 0x800D8E7C: lwc1        $f4, 0x34($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X34);
    // 0x800D8E80: lwc1        $f18, 0x94($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X94);
    // 0x800D8E84: addu        $t7, $sp, $t4
    ctx->r15 = ADD32(ctx->r29, ctx->r12);
    // 0x800D8E88: addu        $t8, $sp, $t4
    ctx->r24 = ADD32(ctx->r29, ctx->r12);
    // 0x800D8E8C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800D8E90: bne         $t0, $zero, L_800D8E9C
    if (ctx->r8 != 0) {
        // 0x800D8E94: nop
    
            goto L_800D8E9C;
    }
    // 0x800D8E94: nop

    // 0x800D8E98: break       7
    do_break(2148372120);
L_800D8E9C:
    // 0x800D8E9C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D8EA0: bne         $t0, $at, L_800D8EB4
    if (ctx->r8 != ctx->r1) {
        // 0x800D8EA4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D8EB4;
    }
    // 0x800D8EA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D8EA8: bne         $t9, $at, L_800D8EB4
    if (ctx->r25 != ctx->r1) {
        // 0x800D8EAC: nop
    
            goto L_800D8EB4;
    }
    // 0x800D8EAC: nop

    // 0x800D8EB0: break       6
    do_break(2148372144);
L_800D8EB4:
    // 0x800D8EB4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800D8EB8: lw          $a3, 0xA0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0XA0);
    // 0x800D8EBC: lw          $a2, 0xAC($t7)
    ctx->r6 = MEM_W(ctx->r15, 0XAC);
    // 0x800D8EC0: jal         0x800EFA4C
    // 0x800D8EC4: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    func_800EFA4C(rdram, ctx);
        goto after_14;
    // 0x800D8EC4: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    after_14:
    // 0x800D8EC8: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800D8ECC: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800D8ED0: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800D8ED4: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800D8ED8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800D8EDC: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800D8EE0: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x800D8EE4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800D8EE8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800D8EEC: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800D8EF0: sub.s       $f0, $f16, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800D8EF4: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800D8EF8: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800D8EFC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800D8F00: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800D8F04: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x800D8F08: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800D8F0C: lwc1        $f18, 0x8C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800D8F10: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800D8F14: lwc1        $f6, 0x88($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800D8F18: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800D8F1C: sb          $t9, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = ctx->r25;
    // 0x800D8F20: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800D8F24: sub.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800D8F28: div.s       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800D8F2C: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
L_800D8F30:
    // 0x800D8F30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D8F34: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    // 0x800D8F38: jr          $ra
    // 0x800D8F3C: nop

    return;
    // 0x800D8F3C: nop

;}
RECOMP_FUNC void func_80800CC8_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800CD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800CD8: jal         0x80100094
    // 0x80800CDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800CDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800CE0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800CE4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800CE8: lhu         $t7, 0x72($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X72);
    // 0x80800CEC: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800CF0: beql        $t8, $at, L_80800D98
    if (ctx->r24 == ctx->r1) {
        // 0x80800CF4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800D98;
    }
    goto skip_0;
    // 0x80800CF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800CF8: lh          $t9, 0x2C($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2C);
    // 0x80800CFC: bne         $t9, $zero, L_80800D44
    if (ctx->r25 != 0) {
        // 0x80800D00: nop
    
            goto L_80800D44;
    }
    // 0x80800D00: nop

    // 0x80800D04: jal         0x800DA298
    // 0x80800D08: addiu       $a0, $zero, 0x9D6
    ctx->r4 = ADD32(0, 0X9D6);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800D08: addiu       $a0, $zero, 0x9D6
    ctx->r4 = ADD32(0, 0X9D6);
    after_1:
    // 0x80800D0C: bne         $v0, $zero, L_80800D44
    if (ctx->r2 != 0) {
        // 0x80800D10: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_80800D44;
    }
    // 0x80800D10: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80800D14: jal         0x800D0B68
    // 0x80800D18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_2;
    // 0x80800D18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800D1C: bne         $v0, $zero, L_80800D44
    if (ctx->r2 != 0) {
        // 0x80800D20: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800D44;
    }
    // 0x80800D20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800D24: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    // 0x80800D28: jal         0x800CE8D8
    // 0x80800D2C: addiu       $a2, $zero, 0x2D
    ctx->r6 = ADD32(0, 0X2D);
    func_800CE8D8(rdram, ctx);
        goto after_3;
    // 0x80800D2C: addiu       $a2, $zero, 0x2D
    ctx->r6 = ADD32(0, 0X2D);
    after_3:
    // 0x80800D30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800D34: jal         0x800CE88C
    // 0x80800D38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_4;
    // 0x80800D38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800D3C: jal         0x800DA544
    // 0x80800D40: addiu       $a0, $zero, 0x9D6
    ctx->r4 = ADD32(0, 0X9D6);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x80800D40: addiu       $a0, $zero, 0x9D6
    ctx->r4 = ADD32(0, 0X9D6);
    after_5:
L_80800D44:
    // 0x80800D44: jal         0x80800DD8
    // 0x80800D48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800DD8_chstonepillar(rdram, ctx);
        goto after_6;
    // 0x80800D48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_6:
    // 0x80800D4C: beql        $v0, $zero, L_80800D6C
    if (ctx->r2 == 0) {
        // 0x80800D50: lui         $a0, 0x7FF5
        ctx->r4 = S32(0X7FF5 << 16);
            goto L_80800D6C;
    }
    goto skip_1;
    // 0x80800D50: lui         $a0, 0x7FF5
    ctx->r4 = S32(0X7FF5 << 16);
    skip_1:
    // 0x80800D54: jal         0x800F54E4
    // 0x80800D58: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x80800D58: nop

    after_7:
    // 0x80800D5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D60: jal         0x800F7F98
    // 0x80800D64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7F98(rdram, ctx);
        goto after_8;
    // 0x80800D64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800D68: lui         $a0, 0x7FF5
    ctx->r4 = S32(0X7FF5 << 16);
L_80800D6C:
    // 0x80800D6C: jal         0x800C3F48
    // 0x80800D70: ori         $a0, $a0, 0x7C16
    ctx->r4 = ctx->r4 | 0X7C16;
    func_800C3F48(rdram, ctx);
        goto after_9;
    // 0x80800D70: ori         $a0, $a0, 0x7C16
    ctx->r4 = ctx->r4 | 0X7C16;
    after_9:
    // 0x80800D74: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800D78: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800D7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800D80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800D84: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800D88: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800D8C: jal         0x808011CC
    // 0x80800D90: nop

    func_808011CC_chstonepillar(rdram, ctx);
        goto after_10;
    // 0x80800D90: nop

    after_10:
    // 0x80800D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D98:
    // 0x80800D98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D9C: jr          $ra
    // 0x80800DA0: nop

    return;
    // 0x80800DA0: nop

;}
RECOMP_FUNC void func_800BA5A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA5A8: jr          $ra
    // 0x800BA5AC: sh          $a1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r5;
    return;
    // 0x800BA5AC: sh          $a1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_800BE600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE600: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800BE604: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800BE608: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x800BE60C: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x800BE610: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x800BE614: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x800BE618: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x800BE61C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800BE620: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800BE624: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800BE628: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800BE62C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800BE630: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800BE634: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800BE638: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800BE63C: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x800BE640: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800BE644: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x800BE648: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800BE64C: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x800BE650: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800BE654: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800BE658: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800BE65C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800BE660: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    // 0x800BE664: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800BE668: addiu       $s5, $sp, 0x64
    ctx->r21 = ADD32(ctx->r29, 0X64);
    // 0x800BE66C: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    // 0x800BE670: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800BE674: addiu       $s6, $sp, 0x58
    ctx->r22 = ADD32(ctx->r29, 0X58);
    // 0x800BE678: addiu       $s7, $sp, 0x70
    ctx->r23 = ADD32(ctx->r29, 0X70);
    // 0x800BE67C: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x800BE680: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800BE684: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x800BE688: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800BE68C: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x800BE690: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800BE694: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800BE698: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800BE69C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800BE6A0: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x800BE6A4: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x800BE6A8: jal         0x800BEF00
    // 0x800BE6AC: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    func_800BEF00(rdram, ctx);
        goto after_0;
    // 0x800BE6AC: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x800BE6B0: beq         $v0, $zero, L_800BE6C0
    if (ctx->r2 == 0) {
        // 0x800BE6B4: addiu       $s2, $zero, 0x96
        ctx->r18 = ADD32(0, 0X96);
            goto L_800BE6C0;
    }
    // 0x800BE6B4: addiu       $s2, $zero, 0x96
    ctx->r18 = ADD32(0, 0X96);
    // 0x800BE6B8: b           L_800BE7C4
    // 0x800BE6BC: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
        goto L_800BE7C4;
    // 0x800BE6BC: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
L_800BE6C0:
    // 0x800BE6C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BE6C4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800BE6C8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800BE6CC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800BE6D0: addiu       $s1, $zero, 0x3E8
    ctx->r17 = ADD32(0, 0X3E8);
    // 0x800BE6D4: ori         $s3, $zero, 0xC738
    ctx->r19 = 0 | 0XC738;
L_800BE6D8:
    // 0x800BE6D8: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800BE6DC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800BE6E0: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x800BE6E4: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x800BE6E8: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800BE6EC: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x800BE6F0: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800BE6F4: jal         0x800DC178
    // 0x800BE6F8: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x800BE6F8: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x800BE6FC: mtc1        $s2, $f4
    ctx->f4.u32l = ctx->r18;
    // 0x800BE700: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800BE704: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800BE708: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BE70C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800BE710: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x800BE714: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800BE718: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800BE71C: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
    // 0x800BE720: jal         0x800DC178
    // 0x800BE724: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x800BE724: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x800BE728: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800BE72C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800BE730: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x800BE734: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800BE738: swc1        $f16, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f16.u32l;
    // 0x800BE73C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800BE740: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x800BE744: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800BE748: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    // 0x800BE74C: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800BE750: jal         0x800DC178
    // 0x800BE754: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x800BE754: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x800BE758: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x800BE75C: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800BE760: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800BE764: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BE768: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800BE76C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x800BE770: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800BE774: sub.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800BE778: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x800BE77C: jal         0x800DC178
    // 0x800BE780: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x800BE780: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x800BE784: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800BE788: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800BE78C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800BE790: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800BE794: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x800BE798: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x800BE79C: jal         0x800BEF00
    // 0x800BE7A0: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    func_800BEF00(rdram, ctx);
        goto after_5;
    // 0x800BE7A0: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x800BE7A4: beq         $v0, $zero, L_800BE7B4
    if (ctx->r2 == 0) {
        // 0x800BE7A8: addiu       $s1, $s1, 0x7D0
        ctx->r17 = ADD32(ctx->r17, 0X7D0);
            goto L_800BE7B4;
    }
    // 0x800BE7A8: addiu       $s1, $s1, 0x7D0
    ctx->r17 = ADD32(ctx->r17, 0X7D0);
    // 0x800BE7AC: b           L_800BE7C4
    // 0x800BE7B0: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
        goto L_800BE7C4;
    // 0x800BE7B0: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
L_800BE7B4:
    // 0x800BE7B4: bne         $s1, $s3, L_800BE6D8
    if (ctx->r17 != ctx->r19) {
        // 0x800BE7B8: addiu       $s2, $s2, 0x12C
        ctx->r18 = ADD32(ctx->r18, 0X12C);
            goto L_800BE6D8;
    }
    // 0x800BE7B8: addiu       $s2, $s2, 0x12C
    ctx->r18 = ADD32(ctx->r18, 0X12C);
    // 0x800BE7BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800BE7C0: nop

L_800BE7C4:
    // 0x800BE7C4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800BE7C8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800BE7CC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800BE7D0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800BE7D4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800BE7D8: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800BE7DC: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800BE7E0: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x800BE7E4: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x800BE7E8: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x800BE7EC: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x800BE7F0: jr          $ra
    // 0x800BE7F4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800BE7F4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void _gcnewoption_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087D48: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087D48);
    return;
    // 0x80087D4C: addi        $t0, $zero, 0x58
    ctx->r8 = ADD32(0, 0X58);
;}
RECOMP_FUNC void func_80025750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025750: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80025754: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80025758: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8002575C: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x80025760: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80025764: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x80025768: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x8002576C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x80025770: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80025774: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80025778: beq         $t0, $zero, L_80025810
    if (ctx->r8 == 0) {
        // 0x8002577C: nop
    
            goto L_80025810;
    }
    // 0x8002577C: nop

L_80025780:
    // 0x80025780: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80025784: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80025788: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x8002578C: lw          $t4, 0x18($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X18);
    // 0x80025790: addu        $t5, $a1, $t2
    ctx->r13 = ADD32(ctx->r5, ctx->r10);
    // 0x80025794: sw          $t4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r12;
    // 0x80025798: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8002579C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800257A0: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800257A4: lw          $t9, 0x98($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X98);
    // 0x800257A8: addu        $t0, $a1, $t7
    ctx->r8 = ADD32(ctx->r5, ctx->r15);
    // 0x800257AC: sw          $t9, 0x8C($t0)
    MEM_W(0X8C, ctx->r8) = ctx->r25;
    // 0x800257B0: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800257B4: addu        $t3, $a0, $t1
    ctx->r11 = ADD32(ctx->r4, ctx->r9);
    // 0x800257B8: lbu         $t2, 0x118($t3)
    ctx->r10 = MEM_BU(ctx->r11, 0X118);
    // 0x800257BC: addu        $t4, $a1, $t1
    ctx->r12 = ADD32(ctx->r5, ctx->r9);
    // 0x800257C0: sb          $t2, 0x10C($t4)
    MEM_B(0X10C, ctx->r12) = ctx->r10;
    // 0x800257C4: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800257C8: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x800257CC: lbu         $t8, 0x138($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X138);
    // 0x800257D0: addu        $t7, $a1, $t5
    ctx->r15 = ADD32(ctx->r5, ctx->r13);
    // 0x800257D4: sb          $t8, 0x12C($t7)
    MEM_B(0X12C, ctx->r15) = ctx->r24;
    // 0x800257D8: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800257DC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800257E0: addu        $t3, $a0, $t0
    ctx->r11 = ADD32(ctx->r4, ctx->r8);
    // 0x800257E4: lw          $t1, 0x158($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X158);
    // 0x800257E8: addu        $t2, $a1, $t0
    ctx->r10 = ADD32(ctx->r5, ctx->r8);
    // 0x800257EC: sw          $t1, 0x14C($t2)
    MEM_W(0X14C, ctx->r10) = ctx->r9;
    // 0x800257F0: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800257F4: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x800257F8: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800257FC: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80025800: lw          $t8, 0x4($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X4);
    // 0x80025804: sltu        $at, $t6, $t8
    ctx->r1 = ctx->r14 < ctx->r24 ? 1 : 0;
    // 0x80025808: bne         $at, $zero, L_80025780
    if (ctx->r1 != 0) {
        // 0x8002580C: nop
    
            goto L_80025780;
    }
    // 0x8002580C: nop

L_80025810:
    // 0x80025810: b           L_80025818
    // 0x80025814: nop

        goto L_80025818;
    // 0x80025814: nop

L_80025818:
    // 0x80025818: jr          $ra
    // 0x8002581C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8002581C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void _glcutDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800887C0: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x800887C0);
    return;
    // 0x800887C4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void sccustom_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080081C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800820: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800824: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800828: jal         0x8080050C
    // 0x8080082C: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    func_8080050C_sccustom(rdram, ctx);
        goto after_0;
    // 0x8080082C: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    after_0:
    // 0x80800830: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800834: jal         0x808006C4
    // 0x80800838: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_808006C4_sccustom(rdram, ctx);
        goto after_1;
    // 0x80800838: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8080083C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800840: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800844: jr          $ra
    // 0x80800848: nop

    return;
    // 0x80800848: nop

;}
RECOMP_FUNC void _chfactorymagnet_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800874E0: syscall     579
    recomp_syscall_handler(rdram, ctx, 0x800874E0);
    return;
    // 0x800874E4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _bsmum_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800837F8: syscall     75
    recomp_syscall_handler(rdram, ctx, 0x800837F8);
    return;
    // 0x800837FC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808080B4_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808080B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808080B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808080BC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808080C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808080C4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808080C8: jal         0x80092744
    // 0x808080CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80092744(rdram, ctx);
        goto after_0;
    // 0x808080CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808080D0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x808080D4: lbu         $t6, 0x2B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2B);
    // 0x808080D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808080DC: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808080E0: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x808080E4: lh          $a3, 0x4($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X4);
    // 0x808080E8: jal         0x80092750
    // 0x808080EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80092750(rdram, ctx);
        goto after_1;
    // 0x808080EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x808080F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808080F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808080F8: jr          $ra
    // 0x808080FC: nop

    return;
    // 0x808080FC: nop

;}
RECOMP_FUNC void _subaddieaudioloop_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089D58: syscall     810
    recomp_syscall_handler(rdram, ctx, 0x80089D58);
    return;
    // 0x80089D5C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _chwandglow_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800872F0: syscall     549
    recomp_syscall_handler(rdram, ctx, 0x800872F0);
    return;
    // 0x800872F4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800770_chjadesnake(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800770: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800778: jal         0x80101870
    // 0x8080077C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101870(rdram, ctx);
        goto after_0;
    // 0x8080077C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800780: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800784: lw          $t7, 0x7C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X7C);
    // 0x80800788: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x8080078C: bgezl       $t9, L_808007D0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800790: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808007D0;
    }
    goto skip_0;
    // 0x80800790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800794: jal         0x80104130
    // 0x80800798: nop

    func_80104130(rdram, ctx);
        goto after_1;
    // 0x80800798: nop

    after_1:
    // 0x8080079C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808007A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808007A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808007A8: jal         0x800DBEFC
    // 0x808007AC: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    func_800DBEFC(rdram, ctx);
        goto after_2;
    // 0x808007AC: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    after_2:
    // 0x808007B0: jal         0x80104130
    // 0x808007B4: nop

    func_80104130(rdram, ctx);
        goto after_3;
    // 0x808007B4: nop

    after_3:
    // 0x808007B8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808007BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808007C0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808007C4: jal         0x800DBEFC
    // 0x808007C8: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    func_800DBEFC(rdram, ctx);
        goto after_4;
    // 0x808007C8: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    after_4:
    // 0x808007CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007D0:
    // 0x808007D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007D4: jr          $ra
    // 0x808007D8: nop

    return;
    // 0x808007D8: nop

;}
RECOMP_FUNC void func_8080050C_chdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080050C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800510: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800514: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800518: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080051C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800520: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800524: jal         0x80100094
    // 0x80800528: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800528: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080052C: lhu         $v1, 0x72($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X72);
    // 0x80800530: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800534: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800538: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x8080053C: beq         $t6, $at, L_8080054C
    if (ctx->r14 == ctx->r1) {
        // 0x80800540: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8080054C;
    }
    // 0x80800540: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800544: bnel        $t6, $at, L_80800554
    if (ctx->r14 != ctx->r1) {
        // 0x80800548: lh          $t7, 0x2E($v0)
        ctx->r15 = MEM_H(ctx->r2, 0X2E);
            goto L_80800554;
    }
    goto skip_0;
    // 0x80800548: lh          $t7, 0x2E($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2E);
    skip_0:
L_8080054C:
    // 0x8080054C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80800550: lh          $t7, 0x2E($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2E);
L_80800554:
    // 0x80800554: beql        $t7, $zero, L_808005D4
    if (ctx->r15 == 0) {
        // 0x80800558: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808005D4;
    }
    goto skip_1;
    // 0x80800558: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8080055C: bnel        $s0, $zero, L_8080057C
    if (ctx->r16 != 0) {
        // 0x80800560: lh          $a0, 0x2E($a1)
        ctx->r4 = MEM_H(ctx->r5, 0X2E);
            goto L_8080057C;
    }
    goto skip_2;
    // 0x80800560: lh          $a0, 0x2E($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2E);
    skip_2:
    // 0x80800564: bnel        $s0, $zero, L_808005D4
    if (ctx->r16 != 0) {
        // 0x80800568: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808005D4;
    }
    goto skip_3;
    // 0x80800568: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8080056C: lbu         $t8, 0x5F($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X5F);
    // 0x80800570: beql        $t8, $zero, L_808005D4
    if (ctx->r24 == 0) {
        // 0x80800574: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808005D4;
    }
    goto skip_4;
    // 0x80800574: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80800578: lh          $a0, 0x2E($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2E);
L_8080057C:
    // 0x8080057C: jal         0x800C4B7C
    // 0x80800580: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800C4B7C(rdram, ctx);
        goto after_1;
    // 0x80800580: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_1:
    // 0x80800584: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80800588: jal         0x800C4B70
    // 0x8080058C: lh          $a0, 0x30($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X30);
    func_800C4B70(rdram, ctx);
        goto after_2;
    // 0x8080058C: lh          $a0, 0x30($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X30);
    after_2:
    // 0x80800590: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80800594: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80800598: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080059C: lh          $t1, 0x32($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X32);
    // 0x808005A0: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x808005A4: nop

    // 0x808005A8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808005AC: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808005B0: jal         0x800C4B64
    // 0x808005B4: nop

    func_800C4B64(rdram, ctx);
        goto after_3;
    // 0x808005B4: nop

    after_3:
    // 0x808005B8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1148, 0X15B0) << 16);
    // 0x808005BC: addiu       $a3, $a3, 0x15B0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1148, 0X15B0));
    // 0x808005C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808005C4: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x808005C8: jal         0x80089D50
    // 0x808005CC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x808005CC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x808005D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005D4:
    // 0x808005D4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808005D8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808005DC: jr          $ra
    // 0x808005E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808005E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _sumultiscore_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089970: syscall     799
    recomp_syscall_handler(rdram, ctx, 0x80089970);
    return;
    // 0x80089974: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800F38A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F38A8: andi        $v0, $a1, 0x4
    ctx->r2 = ctx->r5 & 0X4;
    // 0x800F38AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F38B0: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x800F38B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F38B8: beq         $t6, $zero, L_800F38D8
    if (ctx->r14 == 0) {
        // 0x800F38BC: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_800F38D8;
    }
    // 0x800F38BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800F38C0: jal         0x800F40EC
    // 0x800F38C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F40EC(rdram, ctx);
        goto after_0;
    // 0x800F38C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800F38C8: xori        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 ^ 0X2;
    // 0x800F38CC: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800F38D0: bne         $v0, $zero, L_800F3920
    if (ctx->r2 != 0) {
        // 0x800F38D4: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_800F3920;
    }
    // 0x800F38D4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_800F38D8:
    // 0x800F38D8: andi        $v0, $a1, 0x2
    ctx->r2 = ctx->r5 & 0X2;
    // 0x800F38DC: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x800F38E0: beq         $t8, $zero, L_800F3900
    if (ctx->r24 == 0) {
        // 0x800F38E4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800F3900;
    }
    // 0x800F38E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800F38E8: jal         0x800F40EC
    // 0x800F38EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F40EC(rdram, ctx);
        goto after_1;
    // 0x800F38EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x800F38F0: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800F38F4: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800F38F8: bne         $v0, $zero, L_800F3920
    if (ctx->r2 != 0) {
        // 0x800F38FC: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_800F3920;
    }
    // 0x800F38FC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_800F3900:
    // 0x800F3900: andi        $v0, $a1, 0x1
    ctx->r2 = ctx->r5 & 0X1;
    // 0x800F3904: sltu        $t0, $zero, $v0
    ctx->r8 = 0 < ctx->r2 ? 1 : 0;
    // 0x800F3908: beq         $t0, $zero, L_800F3920
    if (ctx->r8 == 0) {
        // 0x800F390C: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_800F3920;
    }
    // 0x800F390C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800F3910: jal         0x800F3ED0
    // 0x800F3914: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800F3ED0(rdram, ctx);
        goto after_2;
    // 0x800F3914: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800F3918: xori        $t1, $v0, 0xA
    ctx->r9 = ctx->r2 ^ 0XA;
    // 0x800F391C: sltiu       $v0, $t1, 0x1
    ctx->r2 = ctx->r9 < 0X1 ? 1 : 0;
L_800F3920:
    // 0x800F3920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F3924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F3928: jr          $ra
    // 0x800F392C: nop

    return;
    // 0x800F392C: nop

;}
RECOMP_FUNC void func_800A8CCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8CCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A8CD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A8CD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A8CD8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A8CDC: jal         0x800A89BC
    // 0x800A8CE0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800A89BC(rdram, ctx);
        goto after_0;
    // 0x800A8CE0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x800A8CE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A8CE8: jal         0x800A8B24
    // 0x800A8CEC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800A8B24(rdram, ctx);
        goto after_1;
    // 0x800A8CEC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800A8CF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A8CF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A8CF8: jr          $ra
    // 0x800A8CFC: nop

    return;
    // 0x800A8CFC: nop

;}
RECOMP_FUNC void _chjiggytemple_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085B60: syscall     200
    recomp_syscall_handler(rdram, ctx, 0x80085B60);
    return;
    // 0x80085B64: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _gspropsDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088B88: syscall     727
    recomp_syscall_handler(rdram, ctx, 0x80088B88);
    return;
    // 0x80088B8C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bskazcrouch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083300: syscall     54
    recomp_syscall_handler(rdram, ctx, 0x80083300);
    return;
    // 0x80083304: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chicekeydoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800877B8: syscall     625
    recomp_syscall_handler(rdram, ctx, 0x800877B8);
    return;
    // 0x800877BC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800018_chstarspinnerctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080001C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800020: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(960, 0X918) << 16);
    // 0x80800024: jal         0x80086038
    // 0x80800028: addiu       $a1, $a1, 0x918
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(960, 0X918));
    _chpowerhut_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800028: addiu       $a1, $a1, 0x918
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(960, 0X918));
    after_0:
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
RECOMP_FUNC void func_80106E18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106E18: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80106E1C: lw          $a0, 0x6F00($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6F00);
    // 0x80106E20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106E24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106E28: beql        $a0, $zero, L_80106E44
    if (ctx->r4 == 0) {
        // 0x80106E2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80106E44;
    }
    goto skip_0;
    // 0x80106E2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80106E30: jal         0x800B3248
    // 0x80106E34: nop

    freelist_free(rdram, ctx);
        goto after_0;
    // 0x80106E34: nop

    after_0:
    // 0x80106E38: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80106E3C: sw          $zero, 0x6F00($at)
    MEM_W(0X6F00, ctx->r1) = 0;
    // 0x80106E40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106E44:
    // 0x80106E44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80106E48: jr          $ra
    // 0x80106E4C: nop

    return;
    // 0x80106E4C: nop

;}
RECOMP_FUNC void func_808004E0_gspropsDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004E0: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x808004E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808004E8: sll         $t7, $t6, 25
    ctx->r15 = S32(ctx->r14 << 25);
    // 0x808004EC: srl         $t8, $t7, 26
    ctx->r24 = S32(U32(ctx->r15) >> 26);
    // 0x808004F0: addiu       $t9, $t8, -0x6
    ctx->r25 = ADD32(ctx->r24, -0X6);
    // 0x808004F4: sltiu       $at, $t9, 0x7
    ctx->r1 = ctx->r25 < 0X7 ? 1 : 0;
    // 0x808004F8: beq         $at, $zero, L_8080051C
    if (ctx->r1 == 0) {
        // 0x808004FC: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8080051C;
    }
    // 0x808004FC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800500: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2866, 0X790) << 16);
    // 0x80800504: addu        $at, $at, $t9
    gpr jr_addend_8080050C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800508: lw          $t9, 0x790($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2866, 0X790));
    // 0x8080050C: jr          $t9
    // 0x80800510: nop

    switch (jr_addend_8080050C >> 2) {
        case 0: goto L_80800514; break;
        case 1: goto L_80800514; break;
        case 2: goto L_80800514; break;
        case 3: goto L_80800514; break;
        case 4: goto L_80800514; break;
        case 5: goto L_80800514; break;
        case 6: goto L_80800514; break;
        default: switch_error(__func__, 0x8080050C, 0x80800790);
    }
    // 0x80800510: nop

L_80800514:
    // 0x80800514: jr          $ra
    // 0x80800518: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800518: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080051C:
    // 0x8080051C: jr          $ra
    // 0x80800520: nop

    return;
    // 0x80800520: nop

;}
RECOMP_FUNC void _idbounce_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088CB8: syscall     733
    recomp_syscall_handler(rdram, ctx, 0x80088CB8);
    return;
    // 0x80088CBC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808003C0_chjinjovillagecamera1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003CC: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808003D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808003D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003D8: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808003DC: beq         $t6, $at, L_808003F4
    if (ctx->r14 == ctx->r1) {
        // 0x808003E0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808003F4;
    }
    // 0x808003E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808003E4: beq         $t6, $at, L_80800434
    if (ctx->r14 == ctx->r1) {
        // 0x808003E8: nop
    
            goto L_80800434;
    }
    // 0x808003E8: nop

    // 0x808003EC: b           L_80800450
    // 0x808003F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800450;
    // 0x808003F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003F4:
    // 0x808003F4: jal         0x800D9078
    // 0x808003F8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x808003F8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_0:
    // 0x808003FC: beql        $v0, $zero, L_80800450
    if (ctx->r2 == 0) {
        // 0x80800400: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800450;
    }
    goto skip_0;
    // 0x80800400: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800404: jal         0x80086B90
    // 0x80800408: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    _chjinjo_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800408: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_1:
    // 0x8080040C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800410: jal         0x80086B88
    // 0x80800414: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _chjinjo_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800414: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080041C: jal         0x80101FDC
    // 0x80800420: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80800420: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80800424: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80800428: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080042C: b           L_8080044C
    // 0x80800430: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_8080044C;
    // 0x80800430: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80800434:
    // 0x80800434: jal         0x800D9078
    // 0x80800438: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_4;
    // 0x80800438: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_4:
    // 0x8080043C: beql        $v0, $zero, L_80800450
    if (ctx->r2 == 0) {
        // 0x80800440: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800450;
    }
    goto skip_1;
    // 0x80800440: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800444: jal         0x80088830
    // 0x80800448: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_5;
    // 0x80800448: nop

    after_5:
L_8080044C:
    // 0x8080044C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800450:
    // 0x80800450: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800454: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800458: jr          $ra
    // 0x8080045C: nop

    return;
    // 0x8080045C: nop

;}
RECOMP_FUNC void _subaddiefind_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089C88: syscall     807
    recomp_syscall_handler(rdram, ctx, 0x80089C88);
    return;
    // 0x80089C8C: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void suquiz_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800848: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080084C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800850: jal         0x800DA298
    // 0x80800854: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800854: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    after_0:
    // 0x80800858: beq         $v0, $zero, L_80800890
    if (ctx->r2 == 0) {
        // 0x8080085C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800890;
    }
    // 0x8080085C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800860: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80800864: lw          $t6, 0x7614($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7614);
    // 0x80800868: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080086C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800870: lwc1        $f6, 0x20($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X20);
    // 0x80800874: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80800878: nop

    // 0x8080087C: bc1f        L_80800894
    if (!c1cs) {
        // 0x80800880: nop
    
            goto L_80800894;
    }
    // 0x80800880: nop

    // 0x80800884: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800888: b           L_80800894
    // 0x8080088C: nop

        goto L_80800894;
    // 0x8080088C: nop

L_80800890:
    // 0x80800890: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800894:
    // 0x80800894: jr          $ra
    // 0x80800898: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800898: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _sufade_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A8F0: syscall     855
    recomp_syscall_handler(rdram, ctx, 0x8008A8F0);
    return;
    // 0x8008A8F4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void idflame_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800130: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80800134: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2930, 0X560) << 16);
    // 0x80800138: addiu       $a3, $a3, 0x560
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2930, 0X560));
    // 0x8080013C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800140: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    // 0x80800144: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80800148: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8080014C: lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X0);
    // 0x80800150: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x80800154: beq         $at, $zero, L_8080017C
    if (ctx->r1 == 0) {
        // 0x80800158: addiu       $a1, $a0, -0x2
        ctx->r5 = ADD32(ctx->r4, -0X2);
            goto L_8080017C;
    }
    // 0x80800158: addiu       $a1, $a0, -0x2
    ctx->r5 = ADD32(ctx->r4, -0X2);
    // 0x8080015C: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
L_80800160:
    // 0x80800160: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80800164: bne         $at, $zero, L_8080017C
    if (ctx->r1 != 0) {
        // 0x80800168: nop
    
            goto L_8080017C;
    }
    // 0x80800168: nop

    // 0x8080016C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80800170: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x80800174: bnel        $at, $zero, L_80800160
    if (ctx->r1 != 0) {
        // 0x80800178: lh          $t6, 0x0($v1)
        ctx->r14 = MEM_H(ctx->r3, 0X0);
            goto L_80800160;
    }
    goto skip_0;
    // 0x80800178: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    skip_0:
L_8080017C:
    // 0x8080017C: bne         $v1, $a0, L_80800198
    if (ctx->r3 != ctx->r4) {
        // 0x80800180: sltu        $at, $v1, $a0
        ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
            goto L_80800198;
    }
    // 0x80800180: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x80800184: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80800188: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x8080018C: addiu       $t8, $t7, 0x2
    ctx->r24 = ADD32(ctx->r15, 0X2);
    // 0x80800190: jr          $ra
    // 0x80800194: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    return;
    // 0x80800194: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
L_80800198:
    // 0x80800198: beq         $at, $zero, L_808001B8
    if (ctx->r1 == 0) {
        // 0x8080019C: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_808001B8;
    }
    // 0x8080019C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
L_808001A0:
    // 0x808001A0: lh          $t9, 0x0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X0);
    // 0x808001A4: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x808001A8: sltu        $at, $v1, $a2
    ctx->r1 = ctx->r3 < ctx->r6 ? 1 : 0;
    // 0x808001AC: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x808001B0: bne         $at, $zero, L_808001A0
    if (ctx->r1 != 0) {
        // 0x808001B4: sh          $t9, 0x2($a2)
        MEM_H(0X2, ctx->r6) = ctx->r25;
            goto L_808001A0;
    }
    // 0x808001B4: sh          $t9, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r25;
L_808001B8:
    // 0x808001B8: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x808001BC: lw          $t0, 0x4($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X4);
    // 0x808001C0: addiu       $t1, $t0, 0x2
    ctx->r9 = ADD32(ctx->r8, 0X2);
    // 0x808001C4: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x808001C8: jr          $ra
    // 0x808001CC: nop

    return;
    // 0x808001CC: nop

;}
RECOMP_FUNC void func_80800018_chonearmbandit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8080001C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800024: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800028: jal         0x80800040
    // 0x8080002C: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    func_80800040_chonearmbandit(rdram, ctx);
        goto after_0;
    // 0x8080002C: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800038: jr          $ra
    // 0x8080003C: nop

    return;
    // 0x8080003C: nop

;}
RECOMP_FUNC void func_8010B0E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B0E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010B0E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010B0E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8010B0EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8010B0F0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8010B0F4: jal         0x8010C4AC
    // 0x8010B0F8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8010C4AC(rdram, ctx);
        goto after_0;
    // 0x8010B0F8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8010B0FC: jal         0x800D8FF8
    // 0x8010B100: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x8010B100: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8010B104: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8010B108: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8010B10C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8010B110: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x8010B114: lw          $a1, 0x44($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X44);
    // 0x8010B118: lw          $a2, 0x48($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X48);
    // 0x8010B11C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8010B120: jal         0x800EF214
    // 0x8010B124: nop

    func_800EF214(rdram, ctx);
        goto after_2;
    // 0x8010B124: nop

    after_2:
    // 0x8010B128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010B12C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8010B130: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010B134: jr          $ra
    // 0x8010B138: nop

    return;
    // 0x8010B138: nop

;}
RECOMP_FUNC void func_808000AC_chnewfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B4: jal         0x80089B78
    // 0x808000B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _sufreezy_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808000B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000BC: jal         0x8010A570
    // 0x808000C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8010A570(rdram, ctx);
        goto after_1;
    // 0x808000C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808000C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000CC: jr          $ra
    // 0x808000D0: nop

    return;
    // 0x808000D0: nop

;}
RECOMP_FUNC void func_80800270_bsswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800270: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800274: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800278: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080027C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800280: jal         0x8009E69C
    // 0x80800284: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E69C(rdram, ctx);
        goto after_0;
    // 0x80800284: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800288: bnel        $v0, $zero, L_808002D0
    if (ctx->r2 != 0) {
        // 0x8080028C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002D0;
    }
    goto skip_0;
    // 0x8080028C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800290: jal         0x8009BC90
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_1;
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800298: jal         0x8009BC6C
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_2;
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808002A0: jal         0x8009F1E0
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_resetZones(rdram, ctx);
        goto after_3;
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002AC: jal         0x800961AC
    // 0x808002B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_4;
    // 0x808002B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808002B4: jal         0x8008E0E8
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E0E8(rdram, ctx);
        goto after_5;
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808002BC: beq         $v0, $zero, L_808002CC
    if (ctx->r2 == 0) {
        // 0x808002C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002CC;
    }
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C4: jal         0x80084788
    // 0x808002C8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _bapackctrl_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x808002C8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
L_808002CC:
    // 0x808002CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002D0:
    // 0x808002D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002D8: jr          $ra
    // 0x808002DC: nop

    return;
    // 0x808002DC: nop

;}
RECOMP_FUNC void func_808009A4_chfriesstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808009A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009AC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x808009B0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(940, 0X1088) << 16);
    // 0x808009B4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(940, 0XE50) << 16);
    // 0x808009B8: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x808009BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808009C0: addiu       $a3, $a3, 0xE50
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(940, 0XE50));
    // 0x808009C4: addiu       $a2, $a2, 0x1088
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(940, 0X1088));
    // 0x808009C8: jal         0x8008A1F0
    // 0x808009CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x808009CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808009D0: beq         $v0, $zero, L_808009E0
    if (ctx->r2 == 0) {
        // 0x808009D4: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_808009E0;
    }
    // 0x808009D4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808009D8: jal         0x80090734
    // 0x808009DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090734(rdram, ctx);
        goto after_1;
    // 0x808009DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
L_808009E0:
    // 0x808009E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808009E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808009E8: jr          $ra
    // 0x808009EC: nop

    return;
    // 0x808009EC: nop

;}
RECOMP_FUNC void suegg_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002B4: jal         0x80100094
    // 0x808002B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808002B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002C0: jal         0x80800DC0
    // 0x808002C4: lh          $a1, 0x3A($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X3A);
    func_80800DC0_suegg(rdram, ctx);
        goto after_1;
    // 0x808002C4: lh          $a1, 0x3A($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X3A);
    after_1:
    // 0x808002C8: bne         $v0, $zero, L_808002E0
    if (ctx->r2 != 0) {
        // 0x808002CC: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_808002E0;
    }
    // 0x808002CC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808002D0: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x808002D4: lbu         $t8, 0x2A($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X2A);
    // 0x808002D8: ori         $t9, $t8, 0x4
    ctx->r25 = ctx->r24 | 0X4;
    // 0x808002DC: sb          $t9, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r25;
L_808002E0:
    // 0x808002E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002E8: jr          $ra
    // 0x808002EC: nop

    return;
    // 0x808002EC: nop

;}
RECOMP_FUNC void _suquiz_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A7E8: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A7E8);
    return;
    // 0x8008A7EC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
