#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800BF544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF544: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BF548: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800BF54C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BF550: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800BF554: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BF558: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800BF55C: addu        $a3, $a3, $t6
    ctx->r7 = ADD32(ctx->r7, ctx->r14);
    // 0x800BF560: lw          $a3, -0x7A4C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7A4C);
    // 0x800BF564: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BF568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BF56C: beql        $a3, $zero, L_800BF580
    if (ctx->r7 == 0) {
        // 0x800BF570: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800BF580;
    }
    goto skip_0;
    // 0x800BF570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800BF574: jal         0x80088F50
    // 0x800BF578: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    _idworldmake_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x800BF578: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800BF57C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800BF580:
    // 0x800BF580: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BF584: jr          $ra
    // 0x800BF588: nop

    return;
    // 0x800BF588: nop

;}
RECOMP_FUNC void _chblink_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800857B8: syscall     175
    recomp_syscall_handler(rdram, ctx, 0x800857B8);
    return;
    // 0x800857BC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void ncbastring_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800028: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080002C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800030: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800034: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x80800038: jal         0x80111B8C
    // 0x8080003C: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    func_80111B8C(rdram, ctx);
        goto after_0;
    // 0x8080003C: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    after_0:
    // 0x80800040: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800044: jal         0x801124D0
    // 0x80800048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_801124D0(rdram, ctx);
        goto after_1;
    // 0x80800048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080004C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800050: jal         0x80115858
    // 0x80800054: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80115858(rdram, ctx);
        goto after_2;
    // 0x80800054: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800058: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080005C: jal         0x80115870
    // 0x80800060: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    func_80115870(rdram, ctx);
        goto after_3;
    // 0x80800060: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_3:
    // 0x80800064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080006C: jr          $ra
    // 0x80800070: nop

    return;
    // 0x80800070: nop

;}
RECOMP_FUNC void func_8080007C_ncbastring(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080007C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800084: jal         0x80112550
    // 0x80800088: nop

    func_80112550(rdram, ctx);
        goto after_0;
    // 0x80800088: nop

    after_0:
    // 0x8080008C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800090: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800094: jr          $ra
    // 0x80800098: nop

    return;
    // 0x80800098: nop

;}
RECOMP_FUNC void _bsbanshack_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082708: syscall     8
    recomp_syscall_handler(rdram, ctx, 0x80082708);
    return;
    // 0x8008270C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800E0040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0040: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x800E0044: jr          $ra
    // 0x800E0048: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    return;
    // 0x800E0048: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800E004C: nop

;}
RECOMP_FUNC void func_800DBB5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DBB5C: jr          $ra
    // 0x800DBB60: nop

    return;
    // 0x800DBB60: nop

;}
RECOMP_FUNC void func_800DF7C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF7C4: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800DF7C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF7CC: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800DF7D0: negu        $t6, $a1
    ctx->r14 = SUB32(0, ctx->r5);
    // 0x800DF7D4: jr          $ra
    // 0x800DF7D8: sw          $t6, -0x37B0($at)
    MEM_W(-0X37B0, ctx->r1) = ctx->r14;
    return;
    // 0x800DF7D8: sw          $t6, -0x37B0($at)
    MEM_W(-0X37B0, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_80800008_babounce(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x80800014: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800018: bne         $a1, $at, L_80800028
    if (ctx->r5 != ctx->r1) {
        // 0x8080001C: sb          $a1, 0xC($t6)
        MEM_B(0XC, ctx->r14) = ctx->r5;
            goto L_80800028;
    }
    // 0x8080001C: sb          $a1, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r5;
    // 0x80800020: jal         0x8008E95C
    // 0x80800024: nop

    func_8008E95C(rdram, ctx);
        goto after_0;
    // 0x80800024: nop

    after_0:
L_80800028:
    // 0x80800028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080002C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800030: jr          $ra
    // 0x80800034: nop

    return;
    // 0x80800034: nop

;}
RECOMP_FUNC void func_80800000_chdodgemdoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80800010: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1756, 0X350) << 16);
    // 0x80800014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800018: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x8080001C: addiu       $t8, $t6, -0x32
    ctx->r24 = ADD32(ctx->r14, -0X32);
    // 0x80800020: sll         $t0, $t8, 7
    ctx->r8 = S32(ctx->r24 << 7);
    // 0x80800024: andi        $t1, $v0, 0x7F
    ctx->r9 = ctx->r2 & 0X7F;
    // 0x80800028: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x8080002C: sh          $t2, 0x76($a0)
    MEM_H(0X76, ctx->r4) = ctx->r10;
    // 0x80800030: lwc1        $f4, 0x350($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1756, 0X350));
    // 0x80800034: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80800038: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x8080003C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80800040: srl         $t3, $a1, 7
    ctx->r11 = S32(U32(ctx->r5) >> 7);
    // 0x80800044: addiu       $a1, $t3, 0x767
    ctx->r5 = ADD32(ctx->r11, 0X767);
    // 0x80800048: andi        $t4, $a1, 0xFFFF
    ctx->r12 = ctx->r5 & 0XFFFF;
    // 0x8080004C: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x80800050: jal         0x80103140
    // 0x80800054: lhu         $a2, 0x16($t5)
    ctx->r6 = MEM_HU(ctx->r13, 0X16);
    func_80103140(rdram, ctx);
        goto after_0;
    // 0x80800054: lhu         $a2, 0x16($t5)
    ctx->r6 = MEM_HU(ctx->r13, 0X16);
    after_0:
    // 0x80800058: jal         0x8010A63C
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A63C(rdram, ctx);
        goto after_1;
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800060: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x80800064: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x80800068: jal         0x800DA298
    // 0x8080006C: addiu       $a0, $t6, 0xAB
    ctx->r4 = ADD32(ctx->r14, 0XAB);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x8080006C: addiu       $a0, $t6, 0xAB
    ctx->r4 = ADD32(ctx->r14, 0XAB);
    after_2:
    // 0x80800070: beq         $v0, $zero, L_8080008C
    if (ctx->r2 == 0) {
        // 0x80800074: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080008C;
    }
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800078: jal         0x80101FDC
    // 0x8080007C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x8080007C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80800080: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1756, 0X354) << 16);
    // 0x80800084: lwc1        $f6, 0x354($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1756, 0X354));
    // 0x80800088: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
L_8080008C:
    // 0x8080008C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800090: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800094: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800098: jr          $ra
    // 0x8080009C: nop

    return;
    // 0x8080009C: nop

;}
RECOMP_FUNC void func_8080000C_chscorepoints(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800010: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800018: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080001C: jal         0x800E73D4
    // 0x80800020: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800E73D4(rdram, ctx);
        goto after_0;
    // 0x80800020: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x80800024: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800028: jal         0x800E6DB4
    // 0x8080002C: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    func_800E6DB4(rdram, ctx);
        goto after_1;
    // 0x8080002C: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    after_1:
    // 0x80800030: jal         0x800E7188
    // 0x80800034: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800E7188(rdram, ctx);
        goto after_2;
    // 0x80800034: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80800038: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800040: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800044: jal         0x80100074
    // 0x80800048: addiu       $a2, $v0, 0x1
    ctx->r6 = ADD32(ctx->r2, 0X1);
    func_80100074(rdram, ctx);
        goto after_3;
    // 0x80800048: addiu       $a2, $v0, 0x1
    ctx->r6 = ADD32(ctx->r2, 0X1);
    after_3:
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800050: jal         0x80100094
    // 0x80800054: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80800054: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800058: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8080005C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800060: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800064: jal         0x8001BBA0
    // 0x80800068: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    rare_memcpy(rdram, ctx);
        goto after_5;
    // 0x80800068: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_5:
    // 0x8080006C: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x80800070: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1276, 0X3B0) << 16);
    // 0x80800074: lwc1        $f4, 0x3B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1276, 0X3B0));
    // 0x80800078: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8080007C: beq         $t7, $zero, L_808000A8
    if (ctx->r15 == 0) {
        // 0x80800080: swc1        $f4, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
            goto L_808000A8;
    }
    // 0x80800080: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x80800084: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
    // 0x80800088: bgez        $t8, L_808000A0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8080008C: nop
    
            goto L_808000A0;
    }
    // 0x8080008C: nop

    // 0x80800090: jal         0x800FC660
    // 0x80800094: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_800FC660(rdram, ctx);
        goto after_6;
    // 0x80800094: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_6:
    // 0x80800098: b           L_808000AC
    // 0x8080009C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000AC;
    // 0x8080009C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000A0:
    // 0x808000A0: jal         0x800FC660
    // 0x808000A4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_7;
    // 0x808000A4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_7:
L_808000A8:
    // 0x808000A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000AC:
    // 0x808000AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000B0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808000B4: jr          $ra
    // 0x808000B8: nop

    return;
    // 0x808000B8: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800890: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800898: jal         0x80800000
    // 0x8080089C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800000_bsstonehead(rdram, ctx);
        goto after_0;
    // 0x8080089C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808008A0: jal         0x80082FF0
    // 0x808008A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808008A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808008A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008B0: jr          $ra
    // 0x808008B4: nop

    return;
    // 0x808008B4: nop

;}
RECOMP_FUNC void func_80800080_chfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800080: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800084: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800088: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080008C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800090: jal         0x80100094
    // 0x80800094: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800094: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800098: jal         0x8008A040
    // 0x8080009C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x8080009C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808000A0: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x808000A4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808000A8: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x808000AC: bltzl       $t8, L_80800180
    if (SIGNED(ctx->r24) < 0) {
        // 0x808000B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800180;
    }
    goto skip_0;
    // 0x808000B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000B4: beq         $v0, $zero, L_808000CC
    if (ctx->r2 == 0) {
        // 0x808000B8: nop
    
            goto L_808000CC;
    }
    // 0x808000B8: nop

    // 0x808000BC: lw          $t9, 0x64($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X64);
    // 0x808000C0: sll         $t1, $t9, 14
    ctx->r9 = S32(ctx->r25 << 14);
    // 0x808000C4: bgezl       $t1, L_808000E0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808000C8: lwc1        $f12, 0x38($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X38);
            goto L_808000E0;
    }
    goto skip_1;
    // 0x808000C8: lwc1        $f12, 0x38($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X38);
    skip_1:
L_808000CC:
    // 0x808000CC: jal         0x808006C0
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006C0_chfreezy(rdram, ctx);
        goto after_2;
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000D4: b           L_80800180
    // 0x808000D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800180;
    // 0x808000D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000DC: lwc1        $f12, 0x38($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X38);
L_808000E0:
    // 0x808000E0: lwc1        $f14, 0x50($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X50);
    // 0x808000E4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1044, 0X6F4) << 16);
    // 0x808000E8: lwc1        $f6, 0x6F4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1044, 0X6F4));
    // 0x808000EC: sub.s       $f4, $f14, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x808000F0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x808000F4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808000F8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808000FC: jal         0x800F15F8
    // 0x80800100: nop

    func_800F15F8(rdram, ctx);
        goto after_3;
    // 0x80800100: nop

    after_3:
    // 0x80800104: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800108: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x8080010C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800110: lw          $t2, 0x78($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X78);
    // 0x80800114: sll         $t4, $t2, 29
    ctx->r12 = S32(ctx->r10 << 29);
    // 0x80800118: bltzl       $t4, L_80800134
    if (SIGNED(ctx->r12) < 0) {
        // 0x8080011C: lwc1        $f10, 0x38($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
            goto L_80800134;
    }
    goto skip_2;
    // 0x8080011C: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    skip_2:
    // 0x80800120: jal         0x808006C0
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006C0_chfreezy(rdram, ctx);
        goto after_4;
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800128: b           L_80800180
    // 0x8080012C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800180;
    // 0x8080012C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800130: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
L_80800134:
    // 0x80800134: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800138: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080013C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800140: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800144: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80800148: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8080014C: jal         0x80089F18
    // 0x80800150: nop

    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80800150: nop

    after_5:
    // 0x80800154: jal         0x80800538
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800538_chfreezy(rdram, ctx);
        goto after_6;
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080015C: jal         0x800D9078
    // 0x80800160: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_7;
    // 0x80800160: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_7:
    // 0x80800164: beq         $v0, $zero, L_8080017C
    if (ctx->r2 == 0) {
        // 0x80800168: addiu       $a1, $zero, 0x10
        ctx->r5 = ADD32(0, 0X10);
            goto L_8080017C;
    }
    // 0x80800168: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8080016C: jal         0x80089B88
    // 0x80800170: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _sufreezy_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80800170: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_8:
    // 0x80800174: jal         0x808006C0
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006C0_chfreezy(rdram, ctx);
        goto after_9;
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_8080017C:
    // 0x8080017C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800180:
    // 0x80800180: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800184: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800188: jr          $ra
    // 0x8080018C: nop

    return;
    // 0x8080018C: nop

;}
RECOMP_FUNC void _fxstep_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800889E0: syscall     718
    recomp_syscall_handler(rdram, ctx, 0x800889E0);
    return;
    // 0x800889E4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808004E8_chfantasydrillfield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004F0: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808004F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808004F8: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808004FC: beq         $t6, $at, L_80800514
    if (ctx->r14 == ctx->r1) {
        // 0x80800500: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800514;
    }
    // 0x80800500: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800504: beq         $t6, $at, L_80800524
    if (ctx->r14 == ctx->r1) {
        // 0x80800508: addiu       $a1, $zero, 0xB
        ctx->r5 = ADD32(0, 0XB);
            goto L_80800524;
    }
    // 0x80800508: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x8080050C: b           L_80800540
    // 0x80800510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800540;
    // 0x80800510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800514:
    // 0x80800514: jal         0x80103110
    // 0x80800518: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_0;
    // 0x80800518: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080051C: b           L_80800540
    // 0x80800520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800540;
    // 0x80800520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800524:
    // 0x80800524: jal         0x8008A4C0
    // 0x80800528: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddieDll_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800528: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8080052C: beq         $v0, $zero, L_8080053C
    if (ctx->r2 == 0) {
        // 0x80800530: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080053C;
    }
    // 0x80800530: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800534: jal         0x80108B04
    // 0x80800538: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_2;
    // 0x80800538: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_8080053C:
    // 0x8080053C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800540:
    // 0x80800540: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800544: jr          $ra
    // 0x80800548: nop

    return;
    // 0x80800548: nop

;}
RECOMP_FUNC void bamovethrust_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A0: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x808001A4: jr          $ra
    // 0x808001A8: lwc1        $f0, 0x8C($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X8C);
    return;
    // 0x808001A8: lwc1        $f0, 0x8C($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X8C);
    // 0x808001AC: nop

;}
RECOMP_FUNC void func_800EC340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC340: lhu         $t9, 0x1A($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X1A);
    // 0x800EC344: sll         $t8, $a1, 5
    ctx->r24 = S32(ctx->r5 << 5);
    // 0x800EC348: andi        $t0, $t9, 0x1F
    ctx->r8 = ctx->r25 & 0X1F;
    // 0x800EC34C: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x800EC350: jr          $ra
    // 0x800EC354: sh          $t1, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r9;
    return;
    // 0x800EC354: sh          $t1, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void _chbottlesfamily_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800864D8: syscall     331
    recomp_syscall_handler(rdram, ctx, 0x800864D8);
    return;
    // 0x800864DC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _susubgame_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A2D0: syscall     834
    recomp_syscall_handler(rdram, ctx, 0x8008A2D0);
    return;
    // 0x8008A2D4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800EF0_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EF0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800EF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800EF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800EFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800F00: jal         0x808005DC
    // 0x80800F04: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    bstrexsmall_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800F04: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x80800F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F0C: jal         0x8009BB24
    // 0x80800F10: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8009BB24(rdram, ctx);
        goto after_1;
    // 0x80800F10: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80800F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F18: jal         0x80091A30
    // 0x80800F1C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_2;
    // 0x80800F1C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x80800F20: beq         $v0, $zero, L_80800F48
    if (ctx->r2 == 0) {
        // 0x80800F24: lwc1        $f6, 0x2C($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_80800F48;
    }
    // 0x80800F24: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800F28: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800F2C: nop

    // 0x80800F30: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800F34: nop

    // 0x80800F38: bc1fl       L_80800F4C
    if (!c1cs) {
        // 0x80800F3C: lbu         $v0, 0x15C($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X15C);
            goto L_80800F4C;
    }
    goto skip_0;
    // 0x80800F3C: lbu         $v0, 0x15C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15C);
    skip_0:
    // 0x80800F40: jal         0x8009BC6C
    // 0x80800F44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_3;
    // 0x80800F44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80800F48:
    // 0x80800F48: lbu         $v0, 0x15C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15C);
L_80800F4C:
    // 0x80800F4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800F50: beq         $v0, $at, L_80800F68
    if (ctx->r2 == ctx->r1) {
        // 0x80800F54: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800F68;
    }
    // 0x80800F54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800F58: beq         $v0, $at, L_80800F94
    if (ctx->r2 == ctx->r1) {
        // 0x80800F5C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F94;
    }
    // 0x80800F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F60: b           L_80800FD4
    // 0x80800F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800FD4;
    // 0x80800F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800F68:
    // 0x80800F68: jal         0x808002B8
    // 0x80800F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002B8_bstrexsmall(rdram, ctx);
        goto after_4;
    // 0x80800F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800F70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F74: jal         0x8008DF8C
    // 0x80800F78: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_5;
    // 0x80800F78: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_5:
    // 0x80800F7C: beq         $v0, $zero, L_80800FD0
    if (ctx->r2 == 0) {
        // 0x80800F80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FD0;
    }
    // 0x80800F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F84: jal         0x80800CA4
    // 0x80800F88: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800CA4_bstrexsmall(rdram, ctx);
        goto after_6;
    // 0x80800F88: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80800F8C: b           L_80800FD4
    // 0x80800F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800FD4;
    // 0x80800F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800F94:
    // 0x80800F94: jal         0x8009D3A8
    // 0x80800F98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_7;
    // 0x80800F98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800F9C: jal         0x808002B8
    // 0x80800FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002B8_bstrexsmall(rdram, ctx);
        goto after_8;
    // 0x80800FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800FA4: jal         0x8008E078
    // 0x80800FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_9;
    // 0x80800FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800FAC: beql        $v0, $zero, L_80800FD4
    if (ctx->r2 == 0) {
        // 0x80800FB0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FD4;
    }
    goto skip_1;
    // 0x80800FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800FB4: jal         0x800A2E18
    // 0x80800FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A2E18(rdram, ctx);
        goto after_10;
    // 0x80800FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800FBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FC0: jal         0x8009B9B0
    // 0x80800FC4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_11;
    // 0x80800FC4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_11:
    // 0x80800FC8: addiu       $t6, $zero, 0x13B
    ctx->r14 = ADD32(0, 0X13B);
    // 0x80800FCC: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_80800FD0:
    // 0x80800FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800FD4:
    // 0x80800FD4: jal         0x8009E5C8
    // 0x80800FD8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_12;
    // 0x80800FD8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_12:
    // 0x80800FDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800FE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800FE4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800FE8: jr          $ra
    // 0x80800FEC: nop

    return;
    // 0x80800FEC: nop

;}
RECOMP_FUNC void func_8080000C_chzubba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800018: jal         0x80089EC8
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sucoasterfly_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800020: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x80800024: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800028: jal         0x8010A3E8
    // 0x8080002C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8010A3E8(rdram, ctx);
        goto after_1;
    // 0x8080002C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
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
RECOMP_FUNC void func_80802664_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802664: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80802668: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080266C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802670: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80802674: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802678: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080267C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80802680: sltiu       $at, $t8, 0xE
    ctx->r1 = ctx->r24 < 0XE ? 1 : 0;
    // 0x80802684: beq         $at, $zero, L_8080292C
    if (ctx->r1 == 0) {
        // 0x80802688: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8080292C;
    }
    // 0x80802688: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080268C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X6608) << 16);
    // 0x80802690: addu        $at, $at, $t8
    gpr jr_addend_80802698 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80802694: lw          $t8, 0x6608($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2484, 0X6608));
    // 0x80802698: jr          $t8
    // 0x8080269C: nop

    switch (jr_addend_80802698 >> 2) {
        case 0: goto L_8080292C; break;
        case 1: goto L_8080276C; break;
        case 2: goto L_808026A0; break;
        case 3: goto L_808026A0; break;
        case 4: goto L_808026CC; break;
        case 5: goto L_8080292C; break;
        case 6: goto L_8080292C; break;
        case 7: goto L_8080292C; break;
        case 8: goto L_8080281C; break;
        case 9: goto L_8080292C; break;
        case 10: goto L_808027C4; break;
        case 11: goto L_80802874; break;
        case 12: goto L_80802894; break;
        case 13: goto L_8080276C; break;
        default: switch_error(__func__, 0x80802698, 0x80806608);
    }
    // 0x8080269C: nop

L_808026A0:
    // 0x808026A0: jal         0x8008A7E8
    // 0x808026A4: nop

    _suquiz_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x808026A4: nop

    after_0:
    // 0x808026A8: lhu         $t9, 0x76($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X76);
    // 0x808026AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808026B0: srl         $t0, $t9, 7
    ctx->r8 = S32(U32(ctx->r25) >> 7);
    // 0x808026B4: bnel        $v0, $t0, L_80802930
    if (ctx->r2 != ctx->r8) {
        // 0x808026B8: lhu         $v0, 0x76($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X76);
            goto L_80802930;
    }
    goto skip_0;
    // 0x808026B8: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
    skip_0:
    // 0x808026BC: jal         0x80802434
    // 0x808026C0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80802434_chquiz(rdram, ctx);
        goto after_1;
    // 0x808026C0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
    // 0x808026C4: b           L_80802930
    // 0x808026C8: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
        goto L_80802930;
    // 0x808026C8: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
L_808026CC:
    // 0x808026CC: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x808026D0: srl         $t1, $a0, 7
    ctx->r9 = S32(U32(ctx->r4) >> 7);
    // 0x808026D4: jal         0x808000E0
    // 0x808026D8: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    func_808000E0_chquiz(rdram, ctx);
        goto after_2;
    // 0x808026D8: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_2:
    // 0x808026DC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808026E0: jal         0x80101E14
    // 0x808026E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_3;
    // 0x808026E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808026E8: beq         $v0, $zero, L_8080274C
    if (ctx->r2 == 0) {
        // 0x808026EC: nop
    
            goto L_8080274C;
    }
    // 0x808026EC: nop

    // 0x808026F0: lhu         $a2, 0x76($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X76);
    // 0x808026F4: addiu       $a0, $zero, 0x529
    ctx->r4 = ADD32(0, 0X529);
    // 0x808026F8: addiu       $a1, $zero, 0x83
    ctx->r5 = ADD32(0, 0X83);
    // 0x808026FC: srl         $t2, $a2, 7
    ctx->r10 = S32(U32(ctx->r6) >> 7);
    // 0x80802700: jal         0x80101180
    // 0x80802704: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    func_80101180(rdram, ctx);
        goto after_4;
    // 0x80802704: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    after_4:
    // 0x80802708: lhu         $a2, 0x76($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X76);
    // 0x8080270C: addiu       $a0, $zero, 0x528
    ctx->r4 = ADD32(0, 0X528);
    // 0x80802710: addiu       $a1, $zero, 0x83
    ctx->r5 = ADD32(0, 0X83);
    // 0x80802714: srl         $t3, $a2, 7
    ctx->r11 = S32(U32(ctx->r6) >> 7);
    // 0x80802718: jal         0x80101180
    // 0x8080271C: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    func_80101180(rdram, ctx);
        goto after_5;
    // 0x8080271C: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    after_5:
    // 0x80802720: beq         $v0, $zero, L_8080273C
    if (ctx->r2 == 0) {
        // 0x80802724: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080273C;
    }
    // 0x80802724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080272C: jal         0x80802434
    // 0x80802730: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80802434_chquiz(rdram, ctx);
        goto after_6;
    // 0x80802730: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_6:
    // 0x80802734: b           L_80802930
    // 0x80802738: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
        goto L_80802930;
    // 0x80802738: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
L_8080273C:
    // 0x8080273C: jal         0x80802434
    // 0x80802740: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80802434_chquiz(rdram, ctx);
        goto after_7;
    // 0x80802740: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_7:
    // 0x80802744: b           L_80802930
    // 0x80802748: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
        goto L_80802930;
    // 0x80802748: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
L_8080274C:
    // 0x8080274C: jal         0x80101DDC
    // 0x80802750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_8;
    // 0x80802750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80802754: beq         $v0, $zero, L_8080292C
    if (ctx->r2 == 0) {
        // 0x80802758: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080292C;
    }
    // 0x80802758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080275C: jal         0x80802434
    // 0x80802760: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80802434_chquiz(rdram, ctx);
        goto after_9;
    // 0x80802760: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_9:
    // 0x80802764: b           L_80802930
    // 0x80802768: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
        goto L_80802930;
    // 0x80802768: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
L_8080276C:
    // 0x8080276C: jal         0x80101DDC
    // 0x80802770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_10;
    // 0x80802770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80802774: beq         $v0, $zero, L_80802790
    if (ctx->r2 == 0) {
        // 0x80802778: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802790;
    }
    // 0x80802778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080277C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802780: jal         0x80802434
    // 0x80802784: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80802434_chquiz(rdram, ctx);
        goto after_11;
    // 0x80802784: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80802788: b           L_80802930
    // 0x8080278C: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
        goto L_80802930;
    // 0x8080278C: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
L_80802790:
    // 0x80802790: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80802794: jal         0x80101E14
    // 0x80802798: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    func_80101E14(rdram, ctx);
        goto after_12;
    // 0x80802798: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_12:
    // 0x8080279C: beql        $v0, $zero, L_80802930
    if (ctx->r2 == 0) {
        // 0x808027A0: lhu         $v0, 0x76($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X76);
            goto L_80802930;
    }
    goto skip_1;
    // 0x808027A0: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
    skip_1:
    // 0x808027A4: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x808027A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808027AC: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x808027B0: srl         $t4, $a1, 7
    ctx->r12 = S32(U32(ctx->r5) >> 7);
    // 0x808027B4: jal         0x8008A898
    // 0x808027B8: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    _suquiz_entrypoint_28(rdram, ctx);
        goto after_13;
    // 0x808027B8: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    after_13:
    // 0x808027BC: b           L_80802930
    // 0x808027C0: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
        goto L_80802930;
    // 0x808027C0: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
L_808027C4:
    // 0x808027C4: jal         0x80101DDC
    // 0x808027C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_14;
    // 0x808027C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808027CC: beq         $v0, $zero, L_808027E8
    if (ctx->r2 == 0) {
        // 0x808027D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808027E8;
    }
    // 0x808027D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808027D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808027D8: jal         0x80802434
    // 0x808027DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80802434_chquiz(rdram, ctx);
        goto after_15;
    // 0x808027DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x808027E0: b           L_80802930
    // 0x808027E4: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
        goto L_80802930;
    // 0x808027E4: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
L_808027E8:
    // 0x808027E8: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x808027EC: jal         0x80101E14
    // 0x808027F0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    func_80101E14(rdram, ctx);
        goto after_16;
    // 0x808027F0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_16:
    // 0x808027F4: beql        $v0, $zero, L_80802930
    if (ctx->r2 == 0) {
        // 0x808027F8: lhu         $v0, 0x76($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X76);
            goto L_80802930;
    }
    goto skip_2;
    // 0x808027F8: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
    skip_2:
    // 0x808027FC: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x80802800: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80802804: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80802808: srl         $t5, $a1, 7
    ctx->r13 = S32(U32(ctx->r5) >> 7);
    // 0x8080280C: jal         0x8008A898
    // 0x80802810: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    _suquiz_entrypoint_28(rdram, ctx);
        goto after_17;
    // 0x80802810: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    after_17:
    // 0x80802814: b           L_80802930
    // 0x80802818: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
        goto L_80802930;
    // 0x80802818: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
L_8080281C:
    // 0x8080281C: jal         0x80101DDC
    // 0x80802820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_18;
    // 0x80802820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80802824: beq         $v0, $zero, L_80802840
    if (ctx->r2 == 0) {
        // 0x80802828: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802840;
    }
    // 0x80802828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080282C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802830: jal         0x80802434
    // 0x80802834: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80802434_chquiz(rdram, ctx);
        goto after_19;
    // 0x80802834: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_19:
    // 0x80802838: b           L_80802930
    // 0x8080283C: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
        goto L_80802930;
    // 0x8080283C: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
L_80802840:
    // 0x80802840: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80802844: jal         0x80101E14
    // 0x80802848: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    func_80101E14(rdram, ctx);
        goto after_20;
    // 0x80802848: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_20:
    // 0x8080284C: beql        $v0, $zero, L_80802930
    if (ctx->r2 == 0) {
        // 0x80802850: lhu         $v0, 0x76($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X76);
            goto L_80802930;
    }
    goto skip_3;
    // 0x80802850: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
    skip_3:
    // 0x80802854: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x80802858: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8080285C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80802860: srl         $t6, $a1, 7
    ctx->r14 = S32(U32(ctx->r5) >> 7);
    // 0x80802864: jal         0x8008A898
    // 0x80802868: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    _suquiz_entrypoint_28(rdram, ctx);
        goto after_21;
    // 0x80802868: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_21:
    // 0x8080286C: b           L_80802930
    // 0x80802870: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
        goto L_80802930;
    // 0x80802870: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
L_80802874:
    // 0x80802874: jal         0x80101DDC
    // 0x80802878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_22;
    // 0x80802878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x8080287C: beq         $v0, $zero, L_8080292C
    if (ctx->r2 == 0) {
        // 0x80802880: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080292C;
    }
    // 0x80802880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802884: jal         0x80802434
    // 0x80802888: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_80802434_chquiz(rdram, ctx);
        goto after_23;
    // 0x80802888: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_23:
    // 0x8080288C: b           L_80802930
    // 0x80802890: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
        goto L_80802930;
    // 0x80802890: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
L_80802894:
    // 0x80802894: jal         0x80106790
    // 0x80802898: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_24;
    // 0x80802898: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_24:
    // 0x8080289C: lui         $a1, 0x3F59
    ctx->r5 = S32(0X3F59 << 16);
    // 0x808028A0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808028A4: jal         0x80101E14
    // 0x808028A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80101E14(rdram, ctx);
        goto after_25;
    // 0x808028A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_25:
    // 0x808028AC: beq         $v0, $zero, L_808028EC
    if (ctx->r2 == 0) {
        // 0x808028B0: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_808028EC;
    }
    // 0x808028B0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808028B4: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x808028B8: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x808028BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808028C0: srl         $t7, $a1, 7
    ctx->r15 = S32(U32(ctx->r5) >> 7);
    // 0x808028C4: jal         0x8008A898
    // 0x808028C8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    _suquiz_entrypoint_28(rdram, ctx);
        goto after_26;
    // 0x808028C8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_26:
    // 0x808028CC: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x808028D0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808028D4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808028D8: srl         $t8, $a1, 7
    ctx->r24 = S32(U32(ctx->r5) >> 7);
    // 0x808028DC: jal         0x8008A898
    // 0x808028E0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    _suquiz_entrypoint_28(rdram, ctx);
        goto after_27;
    // 0x808028E0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_27:
    // 0x808028E4: b           L_80802930
    // 0x808028E8: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
        goto L_80802930;
    // 0x808028E8: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
L_808028EC:
    // 0x808028EC: jal         0x80106790
    // 0x808028F0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_28;
    // 0x808028F0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_28:
    // 0x808028F4: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x808028F8: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808028FC: jal         0x80101E14
    // 0x80802900: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80101E14(rdram, ctx);
        goto after_29;
    // 0x80802900: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_29:
    // 0x80802904: beql        $v0, $zero, L_80802930
    if (ctx->r2 == 0) {
        // 0x80802908: lhu         $v0, 0x76($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X76);
            goto L_80802930;
    }
    goto skip_4;
    // 0x80802908: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
    skip_4:
    // 0x8080290C: lhu         $t9, 0x76($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X76);
    // 0x80802910: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802914: lui         $a0, 0x7FFF
    ctx->r4 = S32(0X7FFF << 16);
    // 0x80802918: srl         $t0, $t9, 7
    ctx->r8 = S32(U32(ctx->r25) >> 7);
    // 0x8080291C: bnel        $t0, $at, L_80802930
    if (ctx->r8 != ctx->r1) {
        // 0x80802920: lhu         $v0, 0x76($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X76);
            goto L_80802930;
    }
    goto skip_5;
    // 0x80802920: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
    skip_5:
    // 0x80802924: jal         0x800C3F48
    // 0x80802928: ori         $a0, $a0, 0xFE70
    ctx->r4 = ctx->r4 | 0XFE70;
    func_800C3F48(rdram, ctx);
        goto after_30;
    // 0x80802928: ori         $a0, $a0, 0xFE70
    ctx->r4 = ctx->r4 | 0XFE70;
    after_30:
L_8080292C:
    // 0x8080292C: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
L_80802930:
    // 0x80802930: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80802934: srl         $t1, $v0, 7
    ctx->r9 = S32(U32(ctx->r2) >> 7);
    // 0x80802938: beq         $t1, $at, L_80802958
    if (ctx->r9 == ctx->r1) {
        // 0x8080293C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80802958;
    }
    // 0x8080293C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80802940: beq         $t1, $at, L_80802958
    if (ctx->r9 == ctx->r1) {
        // 0x80802944: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80802958;
    }
    // 0x80802944: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80802948: beq         $t1, $at, L_80802958
    if (ctx->r9 == ctx->r1) {
        // 0x8080294C: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80802958;
    }
    // 0x8080294C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80802950: bnel        $t1, $at, L_80802964
    if (ctx->r9 != ctx->r1) {
        // 0x80802954: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802964;
    }
    goto skip_6;
    // 0x80802954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_6:
L_80802958:
    // 0x80802958: jal         0x801039E4
    // 0x8080295C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_801039E4(rdram, ctx);
        goto after_31;
    // 0x8080295C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_31:
    // 0x80802960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802964:
    // 0x80802964: jal         0x80100094
    // 0x80802968: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_32;
    // 0x80802968: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_32:
    // 0x8080296C: lw          $t2, 0x70($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X70);
    // 0x80802970: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802974: sll         $t4, $t2, 28
    ctx->r12 = S32(ctx->r10 << 28);
    // 0x80802978: bgezl       $t4, L_80802994
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8080297C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802994;
    }
    goto skip_7;
    // 0x8080297C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x80802980: beq         $v0, $zero, L_80802990
    if (ctx->r2 == 0) {
        // 0x80802984: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80802990;
    }
    // 0x80802984: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802988: jal         0x800897D8
    // 0x8080298C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_33;
    // 0x8080298C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_33:
L_80802990:
    // 0x80802990: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802994:
    // 0x80802994: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802998: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080299C: jr          $ra
    // 0x808029A0: nop

    return;
    // 0x808029A0: nop

;}
RECOMP_FUNC void func_80800F1C_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F24: lbu         $a1, 0x165($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X165);
    // 0x80800F28: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800F2C: beq         $a1, $zero, L_80800F44
    if (ctx->r5 == 0) {
        // 0x80800F30: andi        $a0, $a1, 0xFF
        ctx->r4 = ctx->r5 & 0XFF;
            goto L_80800F44;
    }
    // 0x80800F30: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80800F34: jal         0x800C2FDC
    // 0x80800F38: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800C2FDC(rdram, ctx);
        goto after_0;
    // 0x80800F38: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800F3C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800F40: sb          $zero, 0x165($a2)
    MEM_B(0X165, ctx->r6) = 0;
L_80800F44:
    // 0x80800F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F4C: jr          $ra
    // 0x80800F50: nop

    return;
    // 0x80800F50: nop

;}
RECOMP_FUNC void func_80807640_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807640: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80807644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80807648: jal         0x80100094
    // 0x8080764C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080764C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80807650: sb          $zero, 0xA0($v0)
    MEM_B(0XA0, ctx->r2) = 0;
    // 0x80807654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80807658: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080765C: jr          $ra
    // 0x80807660: nop

    return;
    // 0x80807660: nop

;}
RECOMP_FUNC void _ncbajig_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089308: syscall     772
    recomp_syscall_handler(rdram, ctx, 0x80089308);
    return;
    // 0x8008930C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _sumumbofx_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800898F0: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x800898F0);
    return;
    // 0x800898F4: addi        $t0, $zero, 0x58
    ctx->r8 = ADD32(0, 0X58);
;}
RECOMP_FUNC void func_80115FB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115FB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80115FB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80115FB8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80115FBC: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    // 0x80115FC0: jal         0x80115F98
    // 0x80115FC4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80115F98(rdram, ctx);
        goto after_0;
    // 0x80115FC4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80115FC8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80115FCC: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    // 0x80115FD0: jal         0x80115F98
    // 0x80115FD4: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    func_80115F98(rdram, ctx);
        goto after_1;
    // 0x80115FD4: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_1:
    // 0x80115FD8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80115FDC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80115FE0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80115FE4: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x80115FE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80115FEC: swc1        $f4, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->f4.u32l;
    // 0x80115FF0: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80115FF4: lwc1        $f0, 0x4C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x80115FF8: swc1        $f0, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f0.u32l;
    // 0x80115FFC: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80116000: swc1        $f0, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->f0.u32l;
    // 0x80116004: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x80116008: sh          $zero, 0x2E($t8)
    MEM_H(0X2E, ctx->r24) = 0;
    // 0x8011600C: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x80116010: swc1        $f6, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->f6.u32l;
    // 0x80116014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80116018: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8011601C: jr          $ra
    // 0x80116020: nop

    return;
    // 0x80116020: nop

;}
RECOMP_FUNC void func_808000C4_chhoneycarrier(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808000C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000CC: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x808000D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000D8: beq         $a1, $at, L_8080011C
    if (ctx->r5 == ctx->r1) {
        // 0x808000DC: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_8080011C;
    }
    // 0x808000DC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x808000E0: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x808000E4: beq         $a1, $at, L_8080013C
    if (ctx->r5 == ctx->r1) {
        // 0x808000E8: lw          $t3, 0x40($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X40);
            goto L_8080013C;
    }
    // 0x808000E8: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x808000EC: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x808000F0: beq         $a1, $at, L_8080010C
    if (ctx->r5 == ctx->r1) {
        // 0x808000F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080010C;
    }
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F8: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x808000FC: beq         $a1, $at, L_80800150
    if (ctx->r5 == ctx->r1) {
        // 0x80800100: nop
    
            goto L_80800150;
    }
    // 0x80800100: nop

    // 0x80800104: b           L_808001FC
    // 0x80800108: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001FC;
    // 0x80800108: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080010C:
    // 0x8080010C: jal         0x80800000
    // 0x80800110: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_80800000_chhoneycarrier(rdram, ctx);
        goto after_0;
    // 0x80800110: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x80800114: b           L_808001FC
    // 0x80800118: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001FC;
    // 0x80800118: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080011C:
    // 0x8080011C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80800120: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80800124: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80800128: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x8080012C: andi        $t1, $t0, 0xFFF7
    ctx->r9 = ctx->r8 & 0XFFF7;
    // 0x80800130: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80800134: b           L_808001F8
    // 0x80800138: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
        goto L_808001F8;
    // 0x80800138: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
L_8080013C:
    // 0x8080013C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80800140: nop

    // 0x80800144: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800148: b           L_808001F8
    // 0x8080014C: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
        goto L_808001F8;
    // 0x8080014C: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
L_80800150:
    // 0x80800150: jal         0x800C8A98
    // 0x80800154: nop

    func_800C8A98(rdram, ctx);
        goto after_1;
    // 0x80800154: nop

    after_1:
    // 0x80800158: lhu         $t6, 0x6E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X6E);
    // 0x8080015C: andi        $t5, $v0, 0x1FF
    ctx->r13 = ctx->r2 & 0X1FF;
    // 0x80800160: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800164: andi        $t7, $t6, 0xFE00
    ctx->r15 = ctx->r14 & 0XFE00;
    // 0x80800168: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x8080016C: sh          $t8, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r24;
    // 0x80800170: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80800174: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800178: andi        $t0, $a0, 0x1FF
    ctx->r8 = ctx->r4 & 0X1FF;
    // 0x8080017C: jal         0x800C8CB8
    // 0x80800180: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_800C8CB8(rdram, ctx);
        goto after_2;
    // 0x80800180: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_2:
    // 0x80800184: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80800188: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1724, 0X3EC) << 16);
    // 0x8080018C: addiu       $a1, $a1, 0x3EC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1724, 0X3EC));
    // 0x80800190: andi        $t9, $a0, 0x1FF
    ctx->r25 = ctx->r4 & 0X1FF;
    // 0x80800194: jal         0x800C8D4C
    // 0x80800198: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800C8D4C(rdram, ctx);
        goto after_3;
    // 0x80800198: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_3:
    // 0x8080019C: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x808001A0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1724, 0X3E0) << 16);
    // 0x808001A4: addiu       $a1, $a1, 0x3E0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1724, 0X3E0));
    // 0x808001A8: andi        $t1, $a0, 0x1FF
    ctx->r9 = ctx->r4 & 0X1FF;
    // 0x808001AC: jal         0x800C8E84
    // 0x808001B0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    func_800C8E84(rdram, ctx);
        goto after_4;
    // 0x808001B0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_4:
    // 0x808001B4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808001B8: jal         0x800EE7F8
    // 0x808001BC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x808001BC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x808001C0: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808001C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808001C8: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808001CC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808001D0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x808001D4: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x808001D8: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x808001DC: andi        $t2, $a0, 0x1FF
    ctx->r10 = ctx->r4 & 0X1FF;
    // 0x808001E0: jal         0x800C8CB8
    // 0x808001E4: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    func_800C8CB8(rdram, ctx);
        goto after_6;
    // 0x808001E4: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_6:
    // 0x808001E8: b           L_808001FC
    // 0x808001EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001FC;
    // 0x808001EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808001F0: b           L_808001FC
    // 0x808001F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001FC;
    // 0x808001F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001F8:
    // 0x808001F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001FC:
    // 0x808001FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800200: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800204: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800208: jr          $ra
    // 0x8080020C: nop

    return;
    // 0x8080020C: nop

;}
RECOMP_FUNC void bs_getCurrentState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E6F8: lw          $t6, 0x120($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X120);
    // 0x8009E6FC: jr          $ra
    // 0x8009E700: lw          $v0, 0x4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4);
    return;
    // 0x8009E700: lw          $v0, 0x4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4);
;}
RECOMP_FUNC void chprisonbits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1932, 0X1008) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x1008
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1932, 0X1008));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x1008
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1932, 0X1008));
;}
RECOMP_FUNC void func_80800A44_chlagoonfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A54: jal         0x80101FDC
    // 0x80800A58: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x80800A58: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800A5C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800A60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800A64: beq         $a1, $at, L_80800A7C
    if (ctx->r5 == ctx->r1) {
        // 0x80800A68: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800A7C;
    }
    // 0x80800A68: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A6C: beq         $a1, $at, L_80800AC4
    if (ctx->r5 == ctx->r1) {
        // 0x80800A70: nop
    
            goto L_80800AC4;
    }
    // 0x80800A70: nop

    // 0x80800A74: b           L_80800AD0
    // 0x80800A78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800AD0;
    // 0x80800A78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A7C:
    // 0x80800A7C: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80800A80: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800A84: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800A88: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800A8C: jal         0x800DC178
    // 0x80800A90: nop

    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800A90: nop

    after_1:
    // 0x80800A94: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800A98: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80800A9C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800AA0: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80800AA4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800AA8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800AAC: jal         0x800DC178
    // 0x80800AB0: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800AB0: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    after_2:
    // 0x80800AB4: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80800AB8: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80800ABC: b           L_80800ACC
    // 0x80800AC0: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
        goto L_80800ACC;
    // 0x80800AC0: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
L_80800AC4:
    // 0x80800AC4: jal         0x808009FC
    // 0x80800AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808009FC_chlagoonfish(rdram, ctx);
        goto after_3;
    // 0x80800AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80800ACC:
    // 0x80800ACC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800AD0:
    // 0x80800AD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800AD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800AD8: jr          $ra
    // 0x80800ADC: nop

    return;
    // 0x80800ADC: nop

;}
RECOMP_FUNC void func_80801CD4_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801CD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801CDC: jal         0x808002D4
    // 0x80801CE0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_808002D4_bsbansack(rdram, ctx);
        goto after_0;
    // 0x80801CE0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801CE4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801CE8: addiu       $a1, $zero, 0x289
    ctx->r5 = ADD32(0, 0X289);
    // 0x80801CEC: jal         0x8008CB3C
    // 0x80801CF0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80801CF0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x80801CF4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80801CF8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801CFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801D00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801D04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801D08: jal         0x8009FFD8
    // 0x80801D0C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80801D0C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80801D10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801D14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801D18: jr          $ra
    // 0x80801D1C: nop

    return;
    // 0x80801D1C: nop

;}
RECOMP_FUNC void _bssplitup_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083A90: syscall     89
    recomp_syscall_handler(rdram, ctx, 0x80083A90);
    return;
    // 0x80083A94: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808005E4_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808005E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808005F0: jal         0x80085228
    // 0x808005F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _basudie_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x808005F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005FC: jal         0x8009B9B0
    // 0x80800600: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_1;
    // 0x80800600: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_1:
    // 0x80800604: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x80800608: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080060C: beq         $v0, $zero, L_80800638
    if (ctx->r2 == 0) {
        // 0x80800610: nop
    
            goto L_80800638;
    }
    // 0x80800610: nop

    // 0x80800614: beq         $v0, $at, L_8080069C
    if (ctx->r2 == ctx->r1) {
        // 0x80800618: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080069C;
    }
    // 0x80800618: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080061C: beq         $v0, $at, L_808006F0
    if (ctx->r2 == ctx->r1) {
        // 0x80800620: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_808006F0;
    }
    // 0x80800620: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80800624: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800628: beql        $v0, $at, L_808006FC
    if (ctx->r2 == ctx->r1) {
        // 0x8080062C: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_808006FC;
    }
    goto skip_0;
    // 0x8080062C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_0:
    // 0x80800630: b           L_80800724
    // 0x80800634: nop

        goto L_80800724;
    // 0x80800634: nop

L_80800638:
    // 0x80800638: jal         0x8008E078
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_2;
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800640: beq         $v0, $zero, L_80800724
    if (ctx->r2 == 0) {
        // 0x80800644: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800724;
    }
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800648: lui         $a1, 0x3F3E
    ctx->r5 = S32(0X3F3E << 16);
    // 0x8080064C: jal         0x8008CED4
    // 0x80800650: ori         $a1, $a1, 0xCBFB
    ctx->r5 = ctx->r5 | 0XCBFB;
    baanim_setEnd(rdram, ctx);
        goto after_3;
    // 0x80800650: ori         $a1, $a1, 0xCBFB
    ctx->r5 = ctx->r5 | 0XCBFB;
    after_3:
    // 0x80800654: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800658: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080065C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800660: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x80800664: jal         0x8009DF18
    // 0x80800668: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF18(rdram, ctx);
        goto after_4;
    // 0x80800668: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_4:
    // 0x8080066C: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x80800670: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800678: addiu       $a1, $zero, 0x428
    ctx->r5 = ADD32(0, 0X428);
    // 0x8080067C: jal         0x8009DF18
    // 0x80800680: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF18(rdram, ctx);
        goto after_5;
    // 0x80800680: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_5:
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800688: jal         0x8009BA58
    // 0x8080068C: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_6;
    // 0x8080068C: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    after_6:
    // 0x80800690: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800694: b           L_80800724
    // 0x80800698: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
        goto L_80800724;
    // 0x80800698: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_8080069C:
    // 0x8080069C: jal         0x8008E078
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_7;
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808006A4: beq         $v0, $zero, L_80800724
    if (ctx->r2 == 0) {
        // 0x808006A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800724;
    }
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006AC: jal         0x8008CED4
    // 0x808006B0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEnd(rdram, ctx);
        goto after_8;
    // 0x808006B0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_8:
    // 0x808006B4: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x808006B8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C0: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x808006C4: jal         0x8009DF18
    // 0x808006C8: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF18(rdram, ctx);
        goto after_9;
    // 0x808006C8: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_9:
    // 0x808006CC: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x808006D0: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D8: addiu       $a1, $zero, 0x428
    ctx->r5 = ADD32(0, 0X428);
    // 0x808006DC: jal         0x8009DF18
    // 0x808006E0: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF18(rdram, ctx);
        goto after_10;
    // 0x808006E0: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_10:
    // 0x808006E4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x808006E8: b           L_80800724
    // 0x808006EC: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
        goto L_80800724;
    // 0x808006EC: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_808006F0:
    // 0x808006F0: b           L_80800724
    // 0x808006F4: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
        goto L_80800724;
    // 0x808006F4: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
    // 0x808006F8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_808006FC:
    // 0x808006FC: lwc1        $f0, 0x16C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800700: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800704: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80800708: nop

    // 0x8080070C: bc1f        L_80800724
    if (!c1cs) {
        // 0x80800710: nop
    
            goto L_80800724;
    }
    // 0x80800710: nop

    // 0x80800714: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800718: jal         0x800F0E00
    // 0x8080071C: sub.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f4.fl;
    func_800F0E00(rdram, ctx);
        goto after_11;
    // 0x8080071C: sub.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f4.fl;
    after_11:
    // 0x80800720: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
L_80800724:
    // 0x80800724: jal         0x808003BC
    // 0x80800728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bsvan_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x80800728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800730: jal         0x8009E5C8
    // 0x80800734: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bs_setState(rdram, ctx);
        goto after_13;
    // 0x80800734: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80800738: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080073C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800740: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800744: jr          $ra
    // 0x80800748: nop

    return;
    // 0x80800748: nop

;}
RECOMP_FUNC void gczoombox_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808036D8: jr          $ra
    // 0x808036DC: sb          $zero, 0x177($a0)
    MEM_B(0X177, ctx->r4) = 0;
    return;
    // 0x808036DC: sb          $zero, 0x177($a0)
    MEM_B(0X177, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80800BD4_chcredits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800BD8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800BDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800BE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800BE4: lbu         $t6, 0x7A($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X7A);
    // 0x80800BE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800BEC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800BF0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800BF4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800BF8: andi        $t7, $t6, 0xFF3F
    ctx->r15 = ctx->r14 & 0XFF3F;
    // 0x80800BFC: sb          $t7, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r15;
    // 0x80800C00: jal         0x800EFA4C
    // 0x80800C04: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x80800C04: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800C08: jal         0x800EA05C
    // 0x80800C0C: nop

    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x80800C0C: nop

    after_1:
    // 0x80800C10: addiu       $at, $zero, 0x19C
    ctx->r1 = ADD32(0, 0X19C);
    // 0x80800C14: beq         $v0, $at, L_80800C28
    if (ctx->r2 == ctx->r1) {
        // 0x80800C18: addiu       $a0, $zero, 0x650
        ctx->r4 = ADD32(0, 0X650);
            goto L_80800C28;
    }
    // 0x80800C18: addiu       $a0, $zero, 0x650
    ctx->r4 = ADD32(0, 0X650);
    // 0x80800C1C: addiu       $at, $zero, 0x19D
    ctx->r1 = ADD32(0, 0X19D);
    // 0x80800C20: bne         $v0, $at, L_80800C68
    if (ctx->r2 != ctx->r1) {
        // 0x80800C24: nop
    
            goto L_80800C68;
    }
    // 0x80800C24: nop

L_80800C28:
    // 0x80800C28: jal         0x800DA9E4
    // 0x80800C2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA9E4(rdram, ctx);
        goto after_2;
    // 0x80800C2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800C30: beq         $v0, $zero, L_80800C4C
    if (ctx->r2 == 0) {
        // 0x80800C34: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C4C;
    }
    // 0x80800C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C3C: jal         0x80800710
    // 0x80800C40: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800710_chcredits(rdram, ctx);
        goto after_3;
    // 0x80800C40: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x80800C44: b           L_80800C58
    // 0x80800C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800C58;
    // 0x80800C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800C4C:
    // 0x80800C4C: jal         0x80800710
    // 0x80800C50: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800710_chcredits(rdram, ctx);
        goto after_4;
    // 0x80800C50: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_4:
    // 0x80800C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800C58:
    // 0x80800C58: jal         0x808003E8
    // 0x80800C5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808003E8_chcredits(rdram, ctx);
        goto after_5;
    // 0x80800C5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800C60: b           L_80800C74
    // 0x80800C64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800C74;
    // 0x80800C64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800C68:
    // 0x80800C68: jal         0x808002A4
    // 0x80800C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002A4_chcredits(rdram, ctx);
        goto after_6;
    // 0x80800C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800C70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800C74:
    // 0x80800C74: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800C78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800C7C: jr          $ra
    // 0x80800C80: nop

    return;
    // 0x80800C80: nop

;}
RECOMP_FUNC void func_800F51CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F51CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F51D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F51D4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800F51D8: jal         0x800F47C0
    // 0x800F51DC: addiu       $a0, $a0, -0x7420
    ctx->r4 = ADD32(ctx->r4, -0X7420);
    func_800F47C0(rdram, ctx);
        goto after_0;
    // 0x800F51DC: addiu       $a0, $a0, -0x7420
    ctx->r4 = ADD32(ctx->r4, -0X7420);
    after_0:
    // 0x800F51E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F51E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F51E8: jr          $ra
    // 0x800F51EC: nop

    return;
    // 0x800F51EC: nop

;}
RECOMP_FUNC void func_80800000_chlagoonlockerdoorhits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x8080000C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800010: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800014: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800018: addiu       $t8, $t7, -0x33
    ctx->r24 = ADD32(ctx->r15, -0X33);
    // 0x8080001C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80800020: jal         0x800DA298
    // 0x80800024: addiu       $a0, $zero, 0x3A8
    ctx->r4 = ADD32(0, 0X3A8);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800024: addiu       $a0, $zero, 0x3A8
    ctx->r4 = ADD32(0, 0X3A8);
    after_0:
    // 0x80800028: beq         $v0, $zero, L_80800068
    if (ctx->r2 == 0) {
        // 0x8080002C: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80800068;
    }
    // 0x8080002C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800030: addiu       $a0, $zero, 0x3A4
    ctx->r4 = ADD32(0, 0X3A4);
    // 0x80800034: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800038: jal         0x800DA564
    // 0x8080003C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800DA564(rdram, ctx);
        goto after_1;
    // 0x8080003C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800040: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800044: addiu       $t9, $v0, 0x32
    ctx->r25 = ADD32(ctx->r2, 0X32);
    // 0x80800048: lhu         $t0, 0x76($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X76);
    // 0x8080004C: srl         $t1, $t0, 7
    ctx->r9 = S32(U32(ctx->r8) >> 7);
    // 0x80800050: bnel        $t9, $t1, L_8080006C
    if (ctx->r25 != ctx->r9) {
        // 0x80800054: lw          $t2, 0x1C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X1C);
            goto L_8080006C;
    }
    goto skip_0;
    // 0x80800054: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800058: jal         0x800FFAB0
    // 0x8080005C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x8080005C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80800060: b           L_80800100
    // 0x80800064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800100;
    // 0x80800064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800068:
    // 0x80800068: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
L_8080006C:
    // 0x8080006C: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2032, 0X3F8) << 16);
    // 0x80800070: addiu       $t5, $t5, 0x3F8
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(2032, 0X3F8));
    // 0x80800074: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80800078: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8080007C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80800080: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x80800084: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80800088: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080008C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800090: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800094: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2032, 0X390) << 16);
    // 0x80800098: lwc1        $f10, 0x390($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2032, 0X390));
    // 0x8080009C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808000A0: lui         $at, 0xC5FA
    ctx->r1 = S32(0XC5FA << 16);
    // 0x808000A4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808000A8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808000AC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x808000B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2032, 0X394) << 16);
    // 0x808000B8: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
    // 0x808000BC: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x808000C0: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x808000C4: nop

    // 0x808000C8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808000CC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x808000D0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808000D4: swc1        $f10, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f10.u32l;
    // 0x808000D8: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x808000DC: lwc1        $f6, 0x394($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2032, 0X394));
    // 0x808000E0: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x808000E4: nop

    // 0x808000E8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808000EC: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x808000F0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808000F4: jal         0x80103014
    // 0x808000F8: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    func_80103014(rdram, ctx);
        goto after_3;
    // 0x808000F8: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    after_3:
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800100:
    // 0x80800100: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800104: jr          $ra
    // 0x80800108: nop

    return;
    // 0x80800108: nop

;}
RECOMP_FUNC void fxgenlist_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2850, 0XA0) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0xA0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2850, 0XA0));
    return;
    // 0x80800020: addiu       $v0, $v0, 0xA0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2850, 0XA0));
;}
RECOMP_FUNC void func_808003D0_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808003DC: jal         0x80091A58
    // 0x808003E0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x808003E0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x808003E4: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x808003E8: beq         $t6, $zero, L_80800400
    if (ctx->r14 == 0) {
        // 0x808003EC: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800400;
    }
    // 0x808003EC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x808003F0: jal         0x80097530
    // 0x808003F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80097530(rdram, ctx);
        goto after_1;
    // 0x808003F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808003F8: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x808003FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80800400:
    // 0x80800400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800404: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800408: jr          $ra
    // 0x8080040C: nop

    return;
    // 0x8080040C: nop

;}
RECOMP_FUNC void func_800DD37C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD37C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DD380: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DD384: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DD388: lw          $t6, 0x1C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X1C);
    // 0x800DD38C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DD390: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800DD394: beq         $t6, $zero, L_800DD400
    if (ctx->r14 == 0) {
        // 0x800DD398: addiu       $a0, $a0, -0x3080
        ctx->r4 = ADD32(ctx->r4, -0X3080);
            goto L_800DD400;
    }
    // 0x800DD398: addiu       $a0, $a0, -0x3080
    ctx->r4 = ADD32(ctx->r4, -0X3080);
    // 0x800DD39C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800DD3A0: jal         0x800DC5BC
    // 0x800DD3A4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_800DC5BC(rdram, ctx);
        goto after_0;
    // 0x800DD3A4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x800DD3A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DD3AC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800DD3B0: addiu       $a1, $a1, -0x3168
    ctx->r5 = ADD32(ctx->r5, -0X3168);
    // 0x800DD3B4: jal         0x800EEB40
    // 0x800DD3B8: addiu       $a0, $a0, -0x3080
    ctx->r4 = ADD32(ctx->r4, -0X3080);
    func_800EEB40(rdram, ctx);
        goto after_1;
    // 0x800DD3B8: addiu       $a0, $a0, -0x3080
    ctx->r4 = ADD32(ctx->r4, -0X3080);
    after_1:
    tooie_lod_distance(rdram, ctx);
    // 0x800DD3BC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800DD3C0: lwc1        $f2, 0xC($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800DD3C4: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800DD3C8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800DD3CC: nop

    // 0x800DD3D0: bc1fl       L_800DD404
    if (!c1cs) {
        // 0x800DD3D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DD404;
    }
    goto skip_0;
    // 0x800DD3D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800DD3D8: lwc1        $f2, 0x8($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800DD3DC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800DD3E0: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x800DD3E4: nop

    // 0x800DD3E8: bc1fl       L_800DD404
    if (!c1cs) {
        // 0x800DD3EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DD404;
    }
    goto skip_1;
    // 0x800DD3EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800DD3F0: lw          $t7, 0x1C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X1C);
    // 0x800DD3F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800DD3F8: jal         0x800DE2A4
    // 0x800DD3FC: addu        $a1, $a2, $t7
    ctx->r5 = ADD32(ctx->r6, ctx->r15);
    func_800DE2A4(rdram, ctx);
        goto after_2;
    // 0x800DD3FC: addu        $a1, $a2, $t7
    ctx->r5 = ADD32(ctx->r6, ctx->r15);
    after_2:
L_800DD400:
    // 0x800DD400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DD404:
    // 0x800DD404: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DD408: jr          $ra
    // 0x800DD40C: nop

    return;
    // 0x800DD40C: nop

;}
RECOMP_FUNC void _chexploder_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086690: syscall     354
    recomp_syscall_handler(rdram, ctx, 0x80086690);
    return;
    // 0x80086694: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _bsow_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083920: syscall     82
    recomp_syscall_handler(rdram, ctx, 0x80083920);
    return;
    // 0x80083924: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800744_chkingjinjobits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800744: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800748: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080074C: addiu       $at, $zero, 0x14D7
    ctx->r1 = ADD32(0, 0X14D7);
    // 0x80800750: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800754: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800758: beq         $a1, $at, L_808007A0
    if (ctx->r5 == ctx->r1) {
        // 0x8080075C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_808007A0;
    }
    // 0x8080075C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800760: addiu       $at, $zero, 0x1536
    ctx->r1 = ADD32(0, 0X1536);
    // 0x80800764: beq         $a1, $at, L_80800780
    if (ctx->r5 == ctx->r1) {
        // 0x80800768: addiu       $a0, $zero, 0x142
        ctx->r4 = ADD32(0, 0X142);
            goto L_80800780;
    }
    // 0x80800768: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    // 0x8080076C: addiu       $at, $zero, 0x154C
    ctx->r1 = ADD32(0, 0X154C);
    // 0x80800770: beql        $a1, $at, L_80800794
    if (ctx->r5 == ctx->r1) {
        // 0x80800774: lbu         $t7, 0x65($a2)
        ctx->r15 = MEM_BU(ctx->r6, 0X65);
            goto L_80800794;
    }
    goto skip_0;
    // 0x80800774: lbu         $t7, 0x65($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X65);
    skip_0:
    // 0x80800778: b           L_808007B8
    // 0x8080077C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808007B8;
    // 0x8080077C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800780:
    // 0x80800780: jal         0x800887D8
    // 0x80800784: addiu       $a1, $zero, 0x66
    ctx->r5 = ADD32(0, 0X66);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800784: addiu       $a1, $zero, 0x66
    ctx->r5 = ADD32(0, 0X66);
    after_0:
    // 0x80800788: b           L_808007B8
    // 0x8080078C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808007B8;
    // 0x8080078C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800790: lbu         $t7, 0x65($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X65);
L_80800794:
    // 0x80800794: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x80800798: b           L_808007B4
    // 0x8080079C: sb          $t8, 0x65($a2)
    MEM_B(0X65, ctx->r6) = ctx->r24;
        goto L_808007B4;
    // 0x8080079C: sb          $t8, 0x65($a2)
    MEM_B(0X65, ctx->r6) = ctx->r24;
L_808007A0:
    // 0x808007A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808007A4: jal         0x800856B8
    // 0x808007A8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    _capod_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808007A8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x808007AC: jal         0x800FFAB0
    // 0x808007B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x808007B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_808007B4:
    // 0x808007B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007B8:
    // 0x808007B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007BC: jr          $ra
    // 0x808007C0: nop

    return;
    // 0x808007C0: nop

;}
RECOMP_FUNC void func_800B553C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B553C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B5540: jr          $ra
    // 0x800B5544: sb          $t6, 0x9($a0)
    MEM_B(0X9, ctx->r4) = ctx->r14;
    return;
    // 0x800B5544: sb          $t6, 0x9($a0)
    MEM_B(0X9, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_808000D0_bssilowait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D8: jal         0x8009E6EC
    // 0x808000DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x808000DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000E0: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x808000E4: bne         $v0, $at, L_80800108
    if (ctx->r2 != ctx->r1) {
        // 0x808000E8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800108;
    }
    // 0x808000E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000EC: jal         0x8009E5C8
    // 0x808000F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bs_setState(rdram, ctx);
        goto after_1;
    // 0x808000F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808000F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000F8: jal         0x8009E830
    // 0x808000FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_2;
    // 0x808000FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800100: b           L_80800114
    // 0x80800104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800114;
    // 0x80800104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800108:
    // 0x80800108: jal         0x80099AA8
    // 0x8080010C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80099AA8(rdram, ctx);
        goto after_3;
    // 0x8080010C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800114:
    // 0x80800114: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800118: jr          $ra
    // 0x8080011C: nop

    return;
    // 0x8080011C: nop

;}
RECOMP_FUNC void func_800A380C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A380C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A3810: lwc1        $f4, 0x5568($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5568);
    // 0x800A3814: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A3818: jr          $ra
    // 0x800A381C: swc1        $f4, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->f4.u32l;
    return;
    // 0x800A381C: swc1        $f4, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->f4.u32l;
;}
RECOMP_FUNC void _suautobaddies_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089FB0: syscall     820
    recomp_syscall_handler(rdram, ctx, 0x80089FB0);
    return;
    // 0x80089FB4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _gcmapsects_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087F68: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087F68);
    return;
    // 0x80087F6C: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_80020EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020EC0: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80020EC4: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x80020EC8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80020ECC: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80020ED0: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x80020ED4: jr          $ra
    // 0x80020ED8: nop

    return;
    // 0x80020ED8: nop

;}
