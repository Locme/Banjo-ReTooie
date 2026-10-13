#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800DE2A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE2A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800DE2A8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800DE2AC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800DE2B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800DE2B4: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800DE2B8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800DE2BC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800DE2C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800DE2C4: addiu       $s2, $s2, -0x3074
    ctx->r18 = ADD32(ctx->r18, -0X3074);
L_800DE2C8:
    // 0x800DE2C8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800DE2CC: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800DE2D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800DE2D4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800DE2D8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800DE2DC: lw          $t9, 0x0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X0);
    // 0x800DE2E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800DE2E4: jalr        $t9
    // 0x800DE2E8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800DE2E8: nop

    after_0:
    // 0x800DE2EC: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800DE2F0: beql        $v0, $zero, L_800DE304
    if (ctx->r2 == 0) {
        // 0x800DE2F4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800DE304;
    }
    goto skip_0;
    // 0x800DE2F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800DE2F8: b           L_800DE2C8
    // 0x800DE2FC: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
        goto L_800DE2C8;
    // 0x800DE2FC: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800DE300: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800DE304:
    // 0x800DE304: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800DE308: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800DE30C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800DE310: jr          $ra
    // 0x800DE314: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800DE314: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _bamovespline_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084EA0: syscall     140
    recomp_syscall_handler(rdram, ctx, 0x80084EA0);
    return;
    // 0x80084EA4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _chusefeather_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085940: syscall     182
    recomp_syscall_handler(rdram, ctx, 0x80085940);
    return;
    // 0x80085944: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bsbanpackwhack_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082698: syscall     6
    recomp_syscall_handler(rdram, ctx, 0x80082698);
    return;
    // 0x8008269C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _cheggproximity_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800873E0: syscall     563
    recomp_syscall_handler(rdram, ctx, 0x800873E0);
    return;
    // 0x800873E4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chswitch_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(696, 0XDD8) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0xDD8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(696, 0XDD8));
    return;
    // 0x80800020: addiu       $v0, $v0, 0xDD8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(696, 0XDD8));
;}
RECOMP_FUNC void func_8080012C_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080012C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800130: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800134: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800138: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8080013C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800140: bnel        $t7, $at, L_80800154
    if (ctx->r15 != ctx->r1) {
        // 0x80800144: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800154;
    }
    goto skip_0;
    // 0x80800144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800148: jal         0x808011F4
    // 0x8080014C: nop

    func_808011F4_chbanjoctrl(rdram, ctx);
        goto after_0;
    // 0x8080014C: nop

    after_0:
    // 0x80800150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800154:
    // 0x80800154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800158: jr          $ra
    // 0x8080015C: nop

    return;
    // 0x8080015C: nop

;}
RECOMP_FUNC void func_8001A010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A010: jr          $ra
    // 0x8001A014: nop

    return;
    // 0x8001A014: nop

;}
RECOMP_FUNC void _chboggyfatboy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086870: syscall     392
    recomp_syscall_handler(rdram, ctx, 0x80086870);
    return;
    // 0x80086874: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8001A440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A440: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001A444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A448: jal         0x8001A0F0
    // 0x8001A44C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8001A0F0(rdram, ctx);
        goto after_0;
    // 0x8001A44C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001A450: jal         0x80015430
    // 0x8001A454: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80015430(rdram, ctx);
        goto after_1;
    // 0x8001A454: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8001A458: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001A45C: addiu       $v1, $v1, -0x4128
    ctx->r3 = ADD32(ctx->r3, -0X4128);
    // 0x8001A460: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8001A464: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8001A468: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8001A46C: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8001A470: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x8001A474: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8001A478: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8001A47C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8001A480: addiu       $t7, $t7, -0x4308
    ctx->r15 = ADD32(ctx->r15, -0X4308);
    // 0x8001A484: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x8001A488: mfhi        $t9
    ctx->r25 = hi;
    // 0x8001A48C: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    // 0x8001A490: jal         0x8001A11C
    // 0x8001A494: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8001A11C(rdram, ctx);
        goto after_2;
    // 0x8001A494: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_2:
    // 0x8001A498: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A49C: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x8001A4A0: jal         0x80013D10
    // 0x8001A4A4: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    func_80013D10(rdram, ctx);
        goto after_3;
    // 0x8001A4A4: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    after_3:
    // 0x8001A4A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A4AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001A4B0: jr          $ra
    // 0x8001A4B4: nop

    return;
    // 0x8001A4B4: nop

;}
RECOMP_FUNC void ncbafly_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: jr          $ra
    // 0x808000A0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808000A0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8080143C_chcaptainblubber(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080143C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801440: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801444: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801448: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x8080144C: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2228, 0X1654) << 16);
    // 0x80801450: addiu       $at, $zero, 0x1C0
    ctx->r1 = ADD32(0, 0X1C0);
    // 0x80801454: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801458: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8080145C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80801460: lhu         $t9, 0x1654($t9)
    ctx->r25 = MEM_HU(ctx->r25, (int16_t)RELOC_LO16(2228, 0X1654));
    // 0x80801464: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801468: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080146C: bne         $t9, $at, L_80801488
    if (ctx->r25 != ctx->r1) {
        // 0x80801470: addiu       $a2, $zero, 0x0
        ctx->r6 = ADD32(0, 0X0);
            goto L_80801488;
    }
    // 0x80801470: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80801474: jal         0x8008A0D0
    // 0x80801478: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80801478: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x8080147C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801480: b           L_80801498
    // 0x80801484: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
        goto L_80801498;
    // 0x80801484: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
L_80801488:
    // 0x80801488: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8080148C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80801490: jal         0x800EFA4C
    // 0x80801494: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x80801494: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    after_1:
L_80801498:
    // 0x80801498: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080149C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014A0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x808014A4: add.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x808014A8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808014AC: jal         0x80085770
    // 0x808014B0: nop

    _chbadshad_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808014B0: nop

    after_2:
    // 0x808014B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808014B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808014BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808014C0: jr          $ra
    // 0x808014C4: nop

    return;
    // 0x808014C4: nop

;}
RECOMP_FUNC void func_801041C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801041C8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801041CC: lw          $a0, 0x6E70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6E70);
    // 0x801041D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801041D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801041D8: beql        $a0, $zero, L_801041F4
    if (ctx->r4 == 0) {
        // 0x801041DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801041F4;
    }
    goto skip_0;
    // 0x801041DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801041E0: jal         0x800B32E4
    // 0x801041E4: nop

    freelist_defrag(rdram, ctx);
        goto after_0;
    // 0x801041E4: nop

    after_0:
    // 0x801041E8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801041EC: sw          $v0, 0x6E70($at)
    MEM_W(0X6E70, ctx->r1) = ctx->r2;
    // 0x801041F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801041F4:
    // 0x801041F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801041F8: jr          $ra
    // 0x801041FC: nop

    return;
    // 0x801041FC: nop

;}
RECOMP_FUNC void func_8008D924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D924: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D92C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008D930: jal         0x800C6E38
    // 0x8008D934: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x8008D934: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_0:
    // 0x8008D938: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D93C: beq         $t6, $zero, L_8008D954
    if (ctx->r14 == 0) {
        // 0x8008D940: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008D954;
    }
    // 0x8008D940: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008D944: jal         0x800A3304
    // 0x8008D948: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A3304(rdram, ctx);
        goto after_1;
    // 0x8008D948: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008D94C: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D950: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8008D954:
    // 0x8008D954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D958: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D95C: jr          $ra
    // 0x8008D960: nop

    return;
    // 0x8008D960: nop

;}
RECOMP_FUNC void func_808008A8_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808008AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808008B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808008B8: jal         0x80095774
    // 0x808008BC: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    baflag_clear(rdram, ctx);
        goto after_0;
    // 0x808008BC: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    after_0:
    // 0x808008C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008C4: jal         0x80095774
    // 0x808008C8: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    baflag_clear(rdram, ctx);
        goto after_1;
    // 0x808008C8: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_1:
    // 0x808008CC: jal         0x8009E704
    // 0x808008D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getNextState(rdram, ctx);
        goto after_2;
    // 0x808008D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808008D4: addiu       $at, $zero, 0x173
    ctx->r1 = ADD32(0, 0X173);
    // 0x808008D8: beq         $v0, $at, L_808008F0
    if (ctx->r2 == ctx->r1) {
        // 0x808008DC: addiu       $at, $zero, 0x174
        ctx->r1 = ADD32(0, 0X174);
            goto L_808008F0;
    }
    // 0x808008DC: addiu       $at, $zero, 0x174
    ctx->r1 = ADD32(0, 0X174);
    // 0x808008E0: beq         $v0, $at, L_808008F0
    if (ctx->r2 == ctx->r1) {
        // 0x808008E4: addiu       $at, $zero, 0x179
        ctx->r1 = ADD32(0, 0X179);
            goto L_808008F0;
    }
    // 0x808008E4: addiu       $at, $zero, 0x179
    ctx->r1 = ADD32(0, 0X179);
    // 0x808008E8: bne         $v0, $at, L_80800924
    if (ctx->r2 != ctx->r1) {
        // 0x808008EC: nop
    
            goto L_80800924;
    }
    // 0x808008EC: nop

L_808008F0:
    // 0x808008F0: jal         0x80084C98
    // 0x808008F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x808008F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808008F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808008FC: bne         $v0, $at, L_80800924
    if (ctx->r2 != ctx->r1) {
        // 0x80800900: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800924;
    }
    // 0x80800900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800904: jal         0x80095760
    // 0x80800908: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    baflag_set(rdram, ctx);
        goto after_4;
    // 0x80800908: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    after_4:
    // 0x8080090C: jal         0x80084CA0
    // 0x80800910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80800910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800914: beq         $v0, $zero, L_80800924
    if (ctx->r2 == 0) {
        // 0x80800918: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800924;
    }
    // 0x80800918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080091C: jal         0x80095760
    // 0x80800920: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    baflag_set(rdram, ctx);
        goto after_6;
    // 0x80800920: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_6:
L_80800924:
    // 0x80800924: jal         0x80084D00
    // 0x80800928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_17(rdram, ctx);
        goto after_7;
    // 0x80800928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080092C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800930: jal         0x80084BF8
    // 0x80800934: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    _bafly_entrypoint_6(rdram, ctx);
        goto after_8;
    // 0x80800934: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_8:
    // 0x80800938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080093C: jal         0x80084C00
    // 0x80800940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bafly_entrypoint_7(rdram, ctx);
        goto after_9;
    // 0x80800940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80800944: jal         0x80800188
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800188_bskazfly(rdram, ctx);
        goto after_10;
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080094C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800950: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800954: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800958: jr          $ra
    // 0x8080095C: nop

    return;
    // 0x8080095C: nop

;}
RECOMP_FUNC void func_808003C4_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808003C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003CC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808003D0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808003D4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808003D8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808003DC: jal         0x80100094
    // 0x808003E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808003E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808003E4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x808003E8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808003EC: slti        $at, $a3, 0x10C1
    ctx->r1 = SIGNED(ctx->r7) < 0X10C1 ? 1 : 0;
    // 0x808003F0: bne         $at, $zero, L_8080042C
    if (ctx->r1 != 0) {
        // 0x808003F4: addiu       $at, $zero, 0x10D2
        ctx->r1 = ADD32(0, 0X10D2);
            goto L_8080042C;
    }
    // 0x808003F4: addiu       $at, $zero, 0x10D2
    ctx->r1 = ADD32(0, 0X10D2);
    // 0x808003F8: beq         $a3, $at, L_80800634
    if (ctx->r7 == ctx->r1) {
        // 0x808003FC: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800634;
    }
    // 0x808003FC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800400: addiu       $at, $zero, 0x10F8
    ctx->r1 = ADD32(0, 0X10F8);
    // 0x80800404: beq         $a3, $at, L_80800548
    if (ctx->r7 == ctx->r1) {
        // 0x80800408: addiu       $at, $zero, 0x10F9
        ctx->r1 = ADD32(0, 0X10F9);
            goto L_80800548;
    }
    // 0x80800408: addiu       $at, $zero, 0x10F9
    ctx->r1 = ADD32(0, 0X10F9);
    // 0x8080040C: beq         $a3, $at, L_80800548
    if (ctx->r7 == ctx->r1) {
        // 0x80800410: addiu       $at, $zero, 0x10FA
        ctx->r1 = ADD32(0, 0X10FA);
            goto L_80800548;
    }
    // 0x80800410: addiu       $at, $zero, 0x10FA
    ctx->r1 = ADD32(0, 0X10FA);
    // 0x80800414: beq         $a3, $at, L_80800548
    if (ctx->r7 == ctx->r1) {
        // 0x80800418: addiu       $at, $zero, 0x1118
        ctx->r1 = ADD32(0, 0X1118);
            goto L_80800548;
    }
    // 0x80800418: addiu       $at, $zero, 0x1118
    ctx->r1 = ADD32(0, 0X1118);
    // 0x8080041C: beql        $a3, $at, L_8080046C
    if (ctx->r7 == ctx->r1) {
        // 0x80800420: lw          $t6, 0x30($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X30);
            goto L_8080046C;
    }
    goto skip_0;
    // 0x80800420: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x80800424: b           L_80800660
    // 0x80800428: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800660;
    // 0x80800428: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080042C:
    // 0x8080042C: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x80800430: beq         $a3, $at, L_80800570
    if (ctx->r7 == ctx->r1) {
        // 0x80800434: addiu       $at, $zero, 0xCEC
        ctx->r1 = ADD32(0, 0XCEC);
            goto L_80800570;
    }
    // 0x80800434: addiu       $at, $zero, 0xCEC
    ctx->r1 = ADD32(0, 0XCEC);
    // 0x80800438: beq         $a3, $at, L_80800618
    if (ctx->r7 == ctx->r1) {
        // 0x8080043C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800618;
    }
    // 0x8080043C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800440: addiu       $at, $zero, 0x10BE
    ctx->r1 = ADD32(0, 0X10BE);
    // 0x80800444: beq         $a3, $at, L_80800468
    if (ctx->r7 == ctx->r1) {
        // 0x80800448: addiu       $at, $zero, 0x10BF
        ctx->r1 = ADD32(0, 0X10BF);
            goto L_80800468;
    }
    // 0x80800448: addiu       $at, $zero, 0x10BF
    ctx->r1 = ADD32(0, 0X10BF);
    // 0x8080044C: beq         $a3, $at, L_8080050C
    if (ctx->r7 == ctx->r1) {
        // 0x80800450: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8080050C;
    }
    // 0x80800450: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800454: addiu       $at, $zero, 0x10C0
    ctx->r1 = ADD32(0, 0X10C0);
    // 0x80800458: beql        $a3, $at, L_8080054C
    if (ctx->r7 == ctx->r1) {
        // 0x8080045C: lw          $t3, 0x28($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X28);
            goto L_8080054C;
    }
    goto skip_1;
    // 0x8080045C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x80800460: b           L_80800660
    // 0x80800464: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800660;
    // 0x80800464: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800468:
    // 0x80800468: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_8080046C:
    // 0x8080046C: blez        $t6, L_808004B0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800470: nop
    
            goto L_808004B0;
    }
    // 0x80800470: nop

    // 0x80800474: jal         0x800DA544
    // 0x80800478: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800478: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8080047C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80800480: addiu       $t8, $zero, 0x22
    ctx->r24 = ADD32(0, 0X22);
    // 0x80800484: addiu       $a1, $zero, 0x10BF
    ctx->r5 = ADD32(0, 0X10BF);
    // 0x80800488: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8080048C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800490: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80800494: jal         0x8008A208
    // 0x80800498: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80800498: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8080049C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808004A0: jal         0x80108B04
    // 0x808004A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_3;
    // 0x808004A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808004A8: b           L_808004FC
    // 0x808004AC: nop

        goto L_808004FC;
    // 0x808004AC: nop

L_808004B0:
    // 0x808004B0: jal         0x800F54E4
    // 0x808004B4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x808004B4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_4:
    // 0x808004B8: jal         0x800878F8
    // 0x808004BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _plcamera_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x808004BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x808004C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808004C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808004C8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808004CC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808004D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808004D4: jal         0x8008A2C8
    // 0x808004D8: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x808004D8: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_6:
    // 0x808004DC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x808004E0: addiu       $t0, $zero, 0x22
    ctx->r8 = ADD32(0, 0X22);
    // 0x808004E4: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    // 0x808004E8: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x808004EC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808004F0: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x808004F4: jal         0x8008A208
    // 0x808004F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x808004F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
L_808004FC:
    // 0x808004FC: jal         0x80088178
    // 0x80800500: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_8;
    // 0x80800500: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    after_8:
    // 0x80800504: b           L_80800660
    // 0x80800508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800660;
    // 0x80800508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080050C:
    // 0x8080050C: addiu       $a1, $v1, 0x18
    ctx->r5 = ADD32(ctx->r3, 0X18);
    // 0x80800510: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800514: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800518: jal         0x8008A2C8
    // 0x8080051C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_9;
    // 0x8080051C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_9:
    // 0x80800520: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80800524: addiu       $t2, $zero, 0x22
    ctx->r10 = ADD32(0, 0X22);
    // 0x80800528: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    // 0x8080052C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80800530: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800534: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80800538: jal         0x8008A208
    // 0x8080053C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_10;
    // 0x8080053C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x80800540: b           L_80800660
    // 0x80800544: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800660;
    // 0x80800544: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800548:
    // 0x80800548: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_8080054C:
    // 0x8080054C: addiu       $t4, $zero, 0x22
    ctx->r12 = ADD32(0, 0X22);
    // 0x80800550: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x80800554: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x80800558: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8080055C: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x80800560: jal         0x8008A208
    // 0x80800564: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_11;
    // 0x80800564: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x80800568: b           L_80800660
    // 0x8080056C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800660;
    // 0x8080056C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800570:
    // 0x80800570: jal         0x800F54E4
    // 0x80800574: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800F54E4(rdram, ctx);
        goto after_12;
    // 0x80800574: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_12:
    // 0x80800578: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8080057C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800580: jal         0x800F82D4
    // 0x80800584: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_13;
    // 0x80800584: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80800588: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080058C: jal         0x80101FDC
    // 0x80800590: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80101FDC(rdram, ctx);
        goto after_14;
    // 0x80800590: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_14:
    // 0x80800594: jal         0x800D395C
    // 0x80800598: nop

    func_800D395C(rdram, ctx);
        goto after_15;
    // 0x80800598: nop

    after_15:
    // 0x8080059C: beq         $v0, $zero, L_808005D0
    if (ctx->r2 == 0) {
        // 0x808005A0: lw          $t6, 0x30($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X30);
            goto L_808005D0;
    }
    // 0x808005A0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x808005A4: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x808005A8: blez        $t5, L_808005C0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x808005AC: nop
    
            goto L_808005C0;
    }
    // 0x808005AC: nop

    // 0x808005B0: jal         0x80088188
    // 0x808005B4: nop

    _gcfrontend_entrypoint_11(rdram, ctx);
        goto after_16;
    // 0x808005B4: nop

    after_16:
    // 0x808005B8: b           L_80800660
    // 0x808005BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800660;
    // 0x808005BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005C0:
    // 0x808005C0: jal         0x80088180
    // 0x808005C4: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_17;
    // 0x808005C4: nop

    after_17:
    // 0x808005C8: b           L_80800660
    // 0x808005CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800660;
    // 0x808005CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005D0:
    // 0x808005D0: blez        $t6, L_808005E8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x808005D4: addiu       $a0, $zero, 0xE4
        ctx->r4 = ADD32(0, 0XE4);
            goto L_808005E8;
    }
    // 0x808005D4: addiu       $a0, $zero, 0xE4
    ctx->r4 = ADD32(0, 0XE4);
    // 0x808005D8: jal         0x80087A58
    // 0x808005DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_18;
    // 0x808005DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x808005E0: b           L_80800604
    // 0x808005E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
        goto L_80800604;
    // 0x808005E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_808005E8:
    // 0x808005E8: jal         0x800F4CC0
    // 0x808005EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800F4CC0(rdram, ctx);
        goto after_19;
    // 0x808005EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_19:
    // 0x808005F0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808005F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005F8: jal         0x8008A2C0
    // 0x808005FC: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_20;
    // 0x808005FC: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_20:
    // 0x80800600: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80800604:
    // 0x80800604: addiu       $a1, $zero, 0x5D
    ctx->r5 = ADD32(0, 0X5D);
    // 0x80800608: jal         0x800F7C58
    // 0x8080060C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800F7C58(rdram, ctx);
        goto after_21;
    // 0x8080060C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_21:
    // 0x80800610: b           L_80800660
    // 0x80800614: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800660;
    // 0x80800614: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800618:
    // 0x80800618: jal         0x8008A2C0
    // 0x8080061C: addiu       $a1, $v1, 0x18
    ctx->r5 = ADD32(ctx->r3, 0X18);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_22;
    // 0x8080061C: addiu       $a1, $v1, 0x18
    ctx->r5 = ADD32(ctx->r3, 0X18);
    after_22:
    // 0x80800620: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800624: jal         0x80800970
    // 0x80800628: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800970_chballoonburst(rdram, ctx);
        goto after_23;
    // 0x80800628: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x8080062C: b           L_80800660
    // 0x80800630: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800660;
    // 0x80800630: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800634:
    // 0x80800634: jal         0x8008A2C0
    // 0x80800638: addiu       $a1, $v1, 0x18
    ctx->r5 = ADD32(ctx->r3, 0X18);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_24;
    // 0x80800638: addiu       $a1, $v1, 0x18
    ctx->r5 = ADD32(ctx->r3, 0X18);
    after_24:
    // 0x8080063C: jal         0x800F54E4
    // 0x80800640: nop

    func_800F54E4(rdram, ctx);
        goto after_25;
    // 0x80800640: nop

    after_25:
    // 0x80800644: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800648: jal         0x800F82D4
    // 0x8080064C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_26;
    // 0x8080064C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x80800650: addiu       $a0, $zero, 0xE1
    ctx->r4 = ADD32(0, 0XE1);
    // 0x80800654: jal         0x800887D8
    // 0x80800658: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_27;
    // 0x80800658: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_27:
    // 0x8080065C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800660:
    // 0x80800660: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800664: jr          $ra
    // 0x80800668: nop

    return;
    // 0x80800668: nop

;}
RECOMP_FUNC void func_80800508_chboggygirl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800508: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080050C: slti        $at, $a1, 0x53
    ctx->r1 = SIGNED(ctx->r5) < 0X53 ? 1 : 0;
    // 0x80800510: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800514: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800518: bne         $at, $zero, L_80800540
    if (ctx->r1 != 0) {
        // 0x8080051C: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800540;
    }
    // 0x8080051C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800520: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800524: beq         $a1, $at, L_8080059C
    if (ctx->r5 == ctx->r1) {
        // 0x80800528: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8080059C;
    }
    // 0x80800528: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080052C: addiu       $at, $zero, 0xB8
    ctx->r1 = ADD32(0, 0XB8);
    // 0x80800530: beq         $a1, $at, L_808005F0
    if (ctx->r5 == ctx->r1) {
        // 0x80800534: lw          $v0, 0x40($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X40);
            goto L_808005F0;
    }
    // 0x80800534: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80800538: b           L_808006F8
    // 0x8080053C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006F8;
    // 0x8080053C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800540:
    // 0x80800540: slti        $at, $a1, 0x31
    ctx->r1 = SIGNED(ctx->r5) < 0X31 ? 1 : 0;
    // 0x80800544: bne         $at, $zero, L_80800560
    if (ctx->r1 != 0) {
        // 0x80800548: addiu       $t6, $a1, -0x29
        ctx->r14 = ADD32(ctx->r5, -0X29);
            goto L_80800560;
    }
    // 0x80800548: addiu       $t6, $a1, -0x29
    ctx->r14 = ADD32(ctx->r5, -0X29);
    // 0x8080054C: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800550: beq         $a1, $at, L_808005DC
    if (ctx->r5 == ctx->r1) {
        // 0x80800554: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1536, 0XD48) << 16);
            goto L_808005DC;
    }
    // 0x80800554: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1536, 0XD48) << 16);
    // 0x80800558: b           L_808006F8
    // 0x8080055C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006F8;
    // 0x8080055C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800560:
    // 0x80800560: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x80800564: beq         $at, $zero, L_808006EC
    if (ctx->r1 == 0) {
        // 0x80800568: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808006EC;
    }
    // 0x80800568: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080056C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1536, 0XBF0) << 16);
    // 0x80800570: addu        $at, $at, $t6
    gpr jr_addend_80800578 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800574: lw          $t6, 0xBF0($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1536, 0XBF0));
    // 0x80800578: jr          $t6
    // 0x8080057C: nop

    switch (jr_addend_80800578 >> 2) {
        case 0: goto L_808005CC; break;
        case 1: goto L_808006DC; break;
        case 2: goto L_808006EC; break;
        case 3: goto L_808006EC; break;
        case 4: goto L_80800668; break;
        case 5: goto L_80800580; break;
        case 6: goto L_808006EC; break;
        case 7: goto L_808006C4; break;
        default: switch_error(__func__, 0x80800578, 0x80800BF0);
    }
    // 0x8080057C: nop

L_80800580:
    // 0x80800580: addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // 0x80800584: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800588: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x8080058C: jal         0x80800708
    // 0x80800590: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800708_chboggygirl(rdram, ctx);
        goto after_0;
    // 0x80800590: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x80800594: b           L_808006F8
    // 0x80800598: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006F8;
    // 0x80800598: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080059C:
    // 0x8080059C: jal         0x80089F60
    // 0x808005A0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808005A0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_1:
    // 0x808005A4: jal         0x800DA298
    // 0x808005A8: addiu       $a0, $zero, 0xB9
    ctx->r4 = ADD32(0, 0XB9);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x808005A8: addiu       $a0, $zero, 0xB9
    ctx->r4 = ADD32(0, 0XB9);
    after_2:
    // 0x808005AC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x808005B0: sll         $t8, $v0, 6
    ctx->r24 = S32(ctx->r2 << 6);
    // 0x808005B4: andi        $t9, $t8, 0x40
    ctx->r25 = ctx->r24 & 0X40;
    // 0x808005B8: lbu         $t0, 0x74($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X74);
    // 0x808005BC: andi        $t1, $t0, 0xFFBF
    ctx->r9 = ctx->r8 & 0XFFBF;
    // 0x808005C0: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x808005C4: b           L_808006F4
    // 0x808005C8: sb          $t2, 0x74($a3)
    MEM_B(0X74, ctx->r7) = ctx->r10;
        goto L_808006F4;
    // 0x808005C8: sb          $t2, 0x74($a3)
    MEM_B(0X74, ctx->r7) = ctx->r10;
L_808005CC:
    // 0x808005CC: jal         0x80800ABC
    // 0x808005D0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800ABC_chboggygirl(rdram, ctx);
        goto after_3;
    // 0x808005D0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x808005D4: b           L_808006F8
    // 0x808005D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006F8;
    // 0x808005D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005DC:
    // 0x808005DC: addiu       $a0, $a0, 0xD48
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1536, 0XD48));
    // 0x808005E0: jal         0x80088090
    // 0x808005E4: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x808005E4: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_4:
    // 0x808005E8: b           L_808006F8
    // 0x808005EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006F8;
    // 0x808005EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005F0:
    // 0x808005F0: andi        $t3, $v0, 0xFFFF
    ctx->r11 = ctx->r2 & 0XFFFF;
    // 0x808005F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005F8: beq         $t3, $at, L_80800610
    if (ctx->r11 == ctx->r1) {
        // 0x808005FC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800610;
    }
    // 0x808005FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800600: beq         $t3, $at, L_80800648
    if (ctx->r11 == ctx->r1) {
        // 0x80800604: nop
    
            goto L_80800648;
    }
    // 0x80800604: nop

    // 0x80800608: b           L_808006F8
    // 0x8080060C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006F8;
    // 0x8080060C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800610:
    // 0x80800610: jal         0x800DA298
    // 0x80800614: addiu       $a0, $zero, 0xB9
    ctx->r4 = ADD32(0, 0XB9);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80800614: addiu       $a0, $zero, 0xB9
    ctx->r4 = ADD32(0, 0XB9);
    after_5:
    // 0x80800618: beq         $v0, $zero, L_80800640
    if (ctx->r2 == 0) {
        // 0x8080061C: nop
    
            goto L_80800640;
    }
    // 0x8080061C: nop

    // 0x80800620: jal         0x80800B5C
    // 0x80800624: addiu       $a0, $zero, 0x3CB
    ctx->r4 = ADD32(0, 0X3CB);
    func_80800B5C_chboggygirl(rdram, ctx);
        goto after_6;
    // 0x80800624: addiu       $a0, $zero, 0x3CB
    ctx->r4 = ADD32(0, 0X3CB);
    after_6:
    // 0x80800628: beq         $v0, $zero, L_80800638
    if (ctx->r2 == 0) {
        // 0x8080062C: addiu       $v1, $zero, 0x108C
        ctx->r3 = ADD32(0, 0X108C);
            goto L_80800638;
    }
    // 0x8080062C: addiu       $v1, $zero, 0x108C
    ctx->r3 = ADD32(0, 0X108C);
    // 0x80800630: b           L_808006F8
    // 0x80800634: addiu       $v0, $zero, 0x108E
    ctx->r2 = ADD32(0, 0X108E);
        goto L_808006F8;
    // 0x80800634: addiu       $v0, $zero, 0x108E
    ctx->r2 = ADD32(0, 0X108E);
L_80800638:
    // 0x80800638: b           L_808006F8
    // 0x8080063C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_808006F8;
    // 0x8080063C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800640:
    // 0x80800640: b           L_808006F8
    // 0x80800644: addiu       $v0, $zero, 0x108C
    ctx->r2 = ADD32(0, 0X108C);
        goto L_808006F8;
    // 0x80800644: addiu       $v0, $zero, 0x108C
    ctx->r2 = ADD32(0, 0X108C);
L_80800648:
    // 0x80800648: jal         0x80800B5C
    // 0x8080064C: addiu       $a0, $zero, 0x3CB
    ctx->r4 = ADD32(0, 0X3CB);
    func_80800B5C_chboggygirl(rdram, ctx);
        goto after_7;
    // 0x8080064C: addiu       $a0, $zero, 0x3CB
    ctx->r4 = ADD32(0, 0X3CB);
    after_7:
    // 0x80800650: beq         $v0, $zero, L_80800660
    if (ctx->r2 == 0) {
        // 0x80800654: addiu       $v1, $zero, 0x108C
        ctx->r3 = ADD32(0, 0X108C);
            goto L_80800660;
    }
    // 0x80800654: addiu       $v1, $zero, 0x108C
    ctx->r3 = ADD32(0, 0X108C);
    // 0x80800658: b           L_808006F8
    // 0x8080065C: addiu       $v0, $zero, 0x108E
    ctx->r2 = ADD32(0, 0X108E);
        goto L_808006F8;
    // 0x8080065C: addiu       $v0, $zero, 0x108E
    ctx->r2 = ADD32(0, 0X108E);
L_80800660:
    // 0x80800660: b           L_808006F8
    // 0x80800664: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_808006F8;
    // 0x80800664: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800668:
    // 0x80800668: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x8080066C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1536, 0XD58) << 16);
    // 0x80800670: addiu       $a2, $a2, 0xD58
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1536, 0XD58));
    // 0x80800674: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80800678: jal         0x80089D18
    // 0x8080067C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x8080067C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_8:
    // 0x80800680: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800684: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800688: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8080068C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800690: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1536, 0XC10) << 16);
    // 0x80800694: lwc1        $f6, 0xC10($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1536, 0XC10));
    // 0x80800698: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8080069C: lui         $a2, 0x3F86
    ctx->r6 = S32(0X3F86 << 16);
    // 0x808006A0: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808006A4: addiu       $a1, $zero, 0x525
    ctx->r5 = ADD32(0, 0X525);
    // 0x808006A8: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    // 0x808006AC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x808006B0: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x808006B4: jal         0x800C9C70
    // 0x808006B8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_800C9C70(rdram, ctx);
        goto after_9;
    // 0x808006B8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_9:
    // 0x808006BC: b           L_808006F8
    // 0x808006C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006F8;
    // 0x808006C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006C4:
    // 0x808006C4: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    // 0x808006C8: jal         0x800DA980
    // 0x808006CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA980(rdram, ctx);
        goto after_10;
    // 0x808006CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x808006D0: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x808006D4: b           L_808006F8
    // 0x808006D8: subu        $v0, $t5, $v0
    ctx->r2 = SUB32(ctx->r13, ctx->r2);
        goto L_808006F8;
    // 0x808006D8: subu        $v0, $t5, $v0
    ctx->r2 = SUB32(ctx->r13, ctx->r2);
L_808006DC:
    // 0x808006DC: jal         0x80800B28
    // 0x808006E0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800B28_chboggygirl(rdram, ctx);
        goto after_11;
    // 0x808006E0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_11:
    // 0x808006E4: b           L_808006F8
    // 0x808006E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006F8;
    // 0x808006E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006EC:
    // 0x808006EC: b           L_808006F8
    // 0x808006F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006F8;
    // 0x808006F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006F4:
    // 0x808006F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006F8:
    // 0x808006F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808006FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800700: jr          $ra
    // 0x80800704: nop

    return;
    // 0x80800704: nop

;}
RECOMP_FUNC void suexpressjoint_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006BC: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x808006C0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x808006C4: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x808006C8: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x808006CC: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x808006D0: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x808006D4: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x808006D8: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x808006DC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808006E0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808006E4: lbu         $t6, 0x8($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X8);
    // 0x808006E8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808006EC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808006F0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x808006F4: bgez        $t6, L_80800708
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808006F8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800708;
    }
    // 0x808006F8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808006FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800700: nop

    // 0x80800704: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80800708:
    // 0x80800708: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3134, 0XA54) << 16);
    // 0x8080070C: lwc1        $f10, 0xA54($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3134, 0XA54));
    // 0x80800710: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800714: mul.s       $f22, $f6, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80800718: jal         0x801040A8
    // 0x8080071C: nop

    func_801040A8(rdram, ctx);
        goto after_0;
    // 0x8080071C: nop

    after_0:
    // 0x80800720: jal         0x800AE6BC
    // 0x80800724: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800AE6BC(rdram, ctx);
        goto after_1;
    // 0x80800724: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800728: lh          $t7, 0x6($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X6);
    // 0x8080072C: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(3134, 0X1818) << 16);
    // 0x80800730: addiu       $s2, $s2, 0x1818
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(3134, 0X1818));
    // 0x80800734: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80800738: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x8080073C: lbu         $t1, 0xB($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0XB);
    // 0x80800740: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80800744: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80800748: blez        $t1, L_80800A0C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8080074C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800A0C;
    }
    // 0x8080074C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800750: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800754: addiu       $s3, $sp, 0x7C
    ctx->r19 = ADD32(ctx->r29, 0X7C);
    // 0x80800758: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8080075C:
    // 0x8080075C: addiu       $a3, $sp, 0x7C
    ctx->r7 = ADD32(ctx->r29, 0X7C);
    // 0x80800760: addiu       $t0, $sp, 0x88
    ctx->r8 = ADD32(ctx->r29, 0X88);
    // 0x80800764: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
L_80800768:
    // 0x80800768: swc1        $f20, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f20.u32l;
    // 0x8080076C: swc1        $f20, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f20.u32l;
    // 0x80800770: swc1        $f20, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f20.u32l;
    // 0x80800774: lh          $t2, 0x6($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X6);
    // 0x80800778: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080077C: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x80800780: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80800784: addu        $a0, $s2, $t3
    ctx->r4 = ADD32(ctx->r18, ctx->r11);
    // 0x80800788: lbu         $t4, 0xC($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0XC);
    // 0x8080078C: blezl       $t4, L_8080087C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80800790: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8080087C;
    }
    goto skip_0;
    // 0x80800790: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    skip_0:
    // 0x80800794: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
L_80800798:
    // 0x80800798: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x8080079C: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x808007A0: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x808007A4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x808007A8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808007AC: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x808007B0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x808007B4: addu        $t1, $t9, $a1
    ctx->r9 = ADD32(ctx->r25, ctx->r5);
    // 0x808007B8: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x808007BC: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x808007C0: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x808007C4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808007C8: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x808007CC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808007D0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808007D4: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x808007D8: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x808007DC: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
    // 0x808007E0: lh          $t2, 0x6($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X6);
    // 0x808007E4: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x808007E8: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x808007EC: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x808007F0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x808007F4: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x808007F8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x808007FC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80800800: addu        $t1, $t9, $a1
    ctx->r9 = ADD32(ctx->r25, ctx->r5);
    // 0x80800804: lwc1        $f10, 0xC($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XC);
    // 0x80800808: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x8080080C: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x80800810: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800814: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800818: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8080081C: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80800820: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80800824: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x80800828: lh          $t2, 0x6($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X6);
    // 0x8080082C: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800830: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80800834: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x80800838: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8080083C: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x80800840: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80800844: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80800848: addu        $t1, $t9, $a1
    ctx->r9 = ADD32(ctx->r25, ctx->r5);
    // 0x8080084C: lwc1        $f6, 0x18($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X18);
    // 0x80800850: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80800854: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80800858: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
    // 0x8080085C: lh          $t2, 0x6($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X6);
    // 0x80800860: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80800864: addu        $a0, $s2, $t3
    ctx->r4 = ADD32(ctx->r18, ctx->r11);
    // 0x80800868: lbu         $t4, 0xC($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0XC);
    // 0x8080086C: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80800870: bnel        $at, $zero, L_80800798
    if (ctx->r1 != 0) {
        // 0x80800874: lw          $t5, 0x0($a0)
        ctx->r13 = MEM_W(ctx->r4, 0X0);
            goto L_80800798;
    }
    goto skip_1;
    // 0x80800874: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    skip_1:
    // 0x80800878: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_8080087C:
    // 0x8080087C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800880: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80800884: bne         $a2, $s3, L_80800768
    if (ctx->r6 != ctx->r19) {
        // 0x80800888: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_80800768;
    }
    // 0x80800888: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8080088C: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80800890: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80800894: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800898: addu        $v0, $t5, $s0
    ctx->r2 = ADD32(ctx->r13, ctx->r16);
    // 0x8080089C: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x808008A0: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x808008A4: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x808008A8: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x808008AC: beql        $t7, $zero, L_808008E0
    if (ctx->r15 == 0) {
        // 0x808008B0: neg.s       $f10, $f22
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = -ctx->f22.fl;
            goto L_808008E0;
    }
    goto skip_2;
    // 0x808008B0: neg.s       $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = -ctx->f22.fl;
    skip_2:
    // 0x808008B4: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x808008B8: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x808008BC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808008C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x808008C4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808008C8: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x808008CC: jal         0x800E0AFC
    // 0x808008D0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_2;
    // 0x808008D0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x808008D4: b           L_808008FC
    // 0x808008D8: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
        goto L_808008FC;
    // 0x808008D8: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x808008DC: neg.s       $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = -ctx->f22.fl;
L_808008E0:
    // 0x808008E0: lwc1        $f16, 0x90($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X90);
    // 0x808008E4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808008E8: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x808008EC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x808008F0: jal         0x800E0AFC
    // 0x808008F4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_3;
    // 0x808008F4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x808008F8: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
L_808008FC:
    // 0x808008FC: lwc1        $f18, 0x80($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80800900: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800904: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80800908: addu        $t1, $s2, $t9
    ctx->r9 = ADD32(ctx->r18, ctx->r25);
    // 0x8080090C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80800910: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x80800914: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80800918: addu        $v0, $t2, $s0
    ctx->r2 = ADD32(ctx->r10, ctx->r16);
    // 0x8080091C: lbu         $t3, 0x1($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X1);
    // 0x80800920: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x80800924: beql        $t4, $zero, L_80800958
    if (ctx->r12 == 0) {
        // 0x80800928: neg.s       $f6, $f22
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = -ctx->f22.fl;
            goto L_80800958;
    }
    goto skip_3;
    // 0x80800928: neg.s       $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = -ctx->f22.fl;
    skip_3:
    // 0x8080092C: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80800930: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x80800934: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80800938: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8080093C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800940: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x80800944: jal         0x800E0C20
    // 0x80800948: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800E0C20(rdram, ctx);
        goto after_4;
    // 0x80800948: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x8080094C: b           L_80800974
    // 0x80800950: lh          $t5, 0x6($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X6);
        goto L_80800974;
    // 0x80800950: lh          $t5, 0x6($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X6);
    // 0x80800954: neg.s       $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = -ctx->f22.fl;
L_80800958:
    // 0x80800958: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8080095C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800960: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x80800964: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80800968: jal         0x800E0C20
    // 0x8080096C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800E0C20(rdram, ctx);
        goto after_5;
    // 0x8080096C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x80800970: lh          $t5, 0x6($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X6);
L_80800974:
    // 0x80800974: lwc1        $f16, 0x74($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80800978: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8080097C: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x80800980: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x80800984: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80800988: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x8080098C: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80800990: addu        $v0, $t8, $s0
    ctx->r2 = ADD32(ctx->r24, ctx->r16);
    // 0x80800994: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x80800998: andi        $t1, $t9, 0x4
    ctx->r9 = ctx->r25 & 0X4;
    // 0x8080099C: beql        $t1, $zero, L_808009D0
    if (ctx->r9 == 0) {
        // 0x808009A0: neg.s       $f4, $f22
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = -ctx->f22.fl;
            goto L_808009D0;
    }
    goto skip_4;
    // 0x808009A0: neg.s       $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = -ctx->f22.fl;
    skip_4:
    // 0x808009A4: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x808009A8: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x808009AC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808009B0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x808009B4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808009B8: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x808009BC: jal         0x800E0B8C
    // 0x808009C0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_6;
    // 0x808009C0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_6:
    // 0x808009C4: b           L_808009EC
    // 0x808009C8: lh          $t2, 0x6($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X6);
        goto L_808009EC;
    // 0x808009C8: lh          $t2, 0x6($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X6);
    // 0x808009CC: neg.s       $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = -ctx->f22.fl;
L_808009D0:
    // 0x808009D0: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x808009D4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808009D8: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x808009DC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x808009E0: jal         0x800E0B8C
    // 0x808009E4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_7;
    // 0x808009E4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x808009E8: lh          $t2, 0x6($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X6);
L_808009EC:
    // 0x808009EC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x808009F0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x808009F4: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x808009F8: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x808009FC: lbu         $t5, 0xB($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0XB);
    // 0x80800A00: slt         $at, $s5, $t5
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80800A04: bnel        $at, $zero, L_8080075C
    if (ctx->r1 != 0) {
        // 0x80800A08: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8080075C;
    }
    goto skip_5;
    // 0x80800A08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    skip_5:
L_80800A0C:
    // 0x80800A0C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80800A10: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800A14: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800A18: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A1C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80800A20: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80800A24: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80800A28: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80800A2C: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80800A30: jr          $ra
    // 0x80800A34: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80800A34: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x80800A38: nop

    // 0x80800A3C: nop

;}
RECOMP_FUNC void bakey_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091D14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80091D18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80091D1C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80091D20: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80091D24: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80091D28: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80091D2C: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x80091D30: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80091D34: jal         0x800BD2D0
    // 0x80091D38: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800BD2D0(rdram, ctx);
        goto after_0;
    // 0x80091D38: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x80091D3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80091D40: jal         0x80091E80
    // 0x80091D44: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80091E80(rdram, ctx);
        goto after_1;
    // 0x80091D44: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_1:
    // 0x80091D48: beql        $v0, $zero, L_80091D70
    if (ctx->r2 == 0) {
        // 0x80091D4C: lw          $t9, 0x40($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X40);
            goto L_80091D70;
    }
    goto skip_0;
    // 0x80091D4C: lw          $t9, 0x40($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X40);
    skip_0:
    // 0x80091D50: lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X40);
    // 0x80091D54: lbu         $t7, 0x9($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X9);
    // 0x80091D58: bnel        $t7, $zero, L_80091D70
    if (ctx->r15 != 0) {
        // 0x80091D5C: lw          $t9, 0x40($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X40);
            goto L_80091D70;
    }
    goto skip_1;
    // 0x80091D5C: lw          $t9, 0x40($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X40);
    skip_1:
    // 0x80091D60: lbu         $t8, 0x8($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X8);
    // 0x80091D64: beql        $t8, $zero, L_80091D9C
    if (ctx->r24 == 0) {
        // 0x80091D68: addiu       $s2, $zero, 0xE
        ctx->r18 = ADD32(0, 0XE);
            goto L_80091D9C;
    }
    goto skip_2;
    // 0x80091D68: addiu       $s2, $zero, 0xE
    ctx->r18 = ADD32(0, 0XE);
    skip_2:
    // 0x80091D6C: lw          $t9, 0x40($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X40);
L_80091D70:
    // 0x80091D70: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80091D74: addiu       $s2, $zero, 0xE
    ctx->r18 = ADD32(0, 0XE);
    // 0x80091D78: sb          $zero, 0x8($t9)
    MEM_B(0X8, ctx->r25) = 0;
    // 0x80091D7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80091D80:
    // 0x80091D80: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80091D84: jal         0x80091C80
    // 0x80091D88: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    bakey_setState(rdram, ctx);
        goto after_2;
    // 0x80091D88: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x80091D8C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80091D90: bnel        $s0, $s2, L_80091D80
    if (ctx->r16 != ctx->r18) {
        // 0x80091D94: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80091D80;
    }
    goto skip_3;
    // 0x80091D94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_3:
    // 0x80091D98: addiu       $s2, $zero, 0xE
    ctx->r18 = ADD32(0, 0XE);
L_80091D9C:
    // 0x80091D9C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80091DA0: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x80091DA4: lw          $t0, 0x40($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X40);
L_80091DA8:
    // 0x80091DA8: addu        $v0, $t0, $s0
    ctx->r2 = ADD32(ctx->r8, ctx->r16);
    // 0x80091DAC: lbu         $t1, 0xA($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XA);
    // 0x80091DB0: sb          $t1, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r9;
    // 0x80091DB4: lw          $t2, 0x40($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X40);
    // 0x80091DB8: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80091DBC: lbu         $v1, 0xA($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0XA);
    // 0x80091DC0: beql        $v1, $zero, L_80091DE0
    if (ctx->r3 == 0) {
        // 0x80091DC4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80091DE0;
    }
    goto skip_4;
    // 0x80091DC4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_4:
    // 0x80091DC8: bne         $s3, $v1, L_80091DDC
    if (ctx->r19 != ctx->r3) {
        // 0x80091DCC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80091DDC;
    }
    // 0x80091DCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80091DD0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80091DD4: jal         0x80091C80
    // 0x80091DD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bakey_setState(rdram, ctx);
        goto after_3;
    // 0x80091DD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
L_80091DDC:
    // 0x80091DDC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80091DE0:
    // 0x80091DE0: bnel        $s0, $s2, L_80091DA8
    if (ctx->r16 != ctx->r18) {
        // 0x80091DE4: lw          $t0, 0x40($s1)
        ctx->r8 = MEM_W(ctx->r17, 0X40);
            goto L_80091DA8;
    }
    goto skip_5;
    // 0x80091DE4: lw          $t0, 0x40($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X40);
    skip_5:
    // 0x80091DE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80091DEC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80091DF0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80091DF4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80091DF8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80091DFC: jr          $ra
    // 0x80091E00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80091E00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800348_chhillbilly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800348: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080034C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800350: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800354: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800358: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8080035C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800360: bne         $t7, $at, L_80800380
    if (ctx->r15 != ctx->r1) {
        // 0x80800364: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80800380;
    }
    // 0x80800364: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800368: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8080036C: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x80800370: jal         0x800EE7F8
    // 0x80800374: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800374: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800378: b           L_80800398
    // 0x8080037C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
        goto L_80800398;
    // 0x8080037C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
L_80800380:
    // 0x80800380: jal         0x8008A110
    // 0x80800384: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    _sucoaster_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800384: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800388: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8080038C: jal         0x800EE88C
    // 0x80800390: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x80800390: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80800394: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
L_80800398:
    // 0x80800398: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(852, 0XCB4) << 16);
    // 0x8080039C: addiu       $t9, $t9, 0xCB4
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(852, 0XCB4));
    // 0x808003A0: lw          $a2, 0x38($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X38);
    // 0x808003A4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808003A8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808003AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808003B0: jal         0x800BBCB8
    // 0x808003B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_3;
    // 0x808003B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x808003B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808003C0: jr          $ra
    // 0x808003C4: nop

    return;
    // 0x808003C4: nop

;}
RECOMP_FUNC void func_80800C2C_bsbeefly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C34: jal         0x80084C58
    // 0x80800C38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bafly_entrypoint_18(rdram, ctx);
        goto after_0;
    // 0x80800C38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800C3C: jal         0x808002E4
    // 0x80800C40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808002E4_bsbeefly(rdram, ctx);
        goto after_1;
    // 0x80800C40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800C44: jal         0x80082830
    // 0x80800C48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsbee_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800C48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800C4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C54: jr          $ra
    // 0x80800C58: nop

    return;
    // 0x80800C58: nop

;}
RECOMP_FUNC void bskazstilt_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808004B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808004B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004BC: jal         0x808000C8
    // 0x808004C0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_808000C8_bskazstilt(rdram, ctx);
        goto after_0;
    // 0x808004C0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x808004C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808004CC: jal         0x8009D2F0
    // 0x808004D0: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_8009D2F0(rdram, ctx);
        goto after_1;
    // 0x808004D0: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_1:
    // 0x808004D4: jal         0x80097AD0
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_2;
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808004DC: beql        $v0, $zero, L_808004F4
    if (ctx->r2 == 0) {
        // 0x808004E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004F4;
    }
    goto skip_0;
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808004E4: jal         0x800848A8
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_24(rdram, ctx);
        goto after_3;
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808004EC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808004F4:
    // 0x808004F4: jal         0x80091A58
    // 0x808004F8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_4;
    // 0x808004F8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_4:
    // 0x808004FC: beq         $v0, $zero, L_8080050C
    if (ctx->r2 == 0) {
        // 0x80800500: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080050C;
    }
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800504: jal         0x80091788
    // 0x80800508: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_clear(rdram, ctx);
        goto after_5;
    // 0x80800508: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
L_8080050C:
    // 0x8080050C: jal         0x8009EF10
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_6;
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800514: blez        $v0, L_80800520
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800518: nop
    
            goto L_80800520;
    }
    // 0x80800518: nop

    // 0x8080051C: addiu       $s1, $zero, 0x49
    ctx->r17 = ADD32(0, 0X49);
L_80800520:
    // 0x80800520: jal         0x8008DF18
    // 0x80800524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DF18(rdram, ctx);
        goto after_7;
    // 0x80800524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800528: beq         $v0, $zero, L_80800534
    if (ctx->r2 == 0) {
        // 0x8080052C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800534;
    }
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800530: addiu       $s1, $zero, 0x4D
    ctx->r17 = ADD32(0, 0X4D);
L_80800534:
    // 0x80800534: jal         0x80091A58
    // 0x80800538: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_8;
    // 0x80800538: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_8:
    // 0x8080053C: beql        $v0, $zero, L_8080055C
    if (ctx->r2 == 0) {
        // 0x80800540: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080055C;
    }
    goto skip_1;
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800544: jal         0x8008E078
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_9;
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080054C: beql        $v0, $zero, L_8080055C
    if (ctx->r2 == 0) {
        // 0x80800550: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080055C;
    }
    goto skip_2;
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800554: addiu       $s1, $zero, 0x4A
    ctx->r17 = ADD32(0, 0X4A);
    // 0x80800558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080055C:
    // 0x8080055C: jal         0x800915AC
    // 0x80800560: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_isDone(rdram, ctx);
        goto after_10;
    // 0x80800560: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x80800564: beq         $v0, $zero, L_80800570
    if (ctx->r2 == 0) {
        // 0x80800568: nop
    
            goto L_80800570;
    }
    // 0x80800568: nop

    // 0x8080056C: addiu       $s1, $zero, 0x4B
    ctx->r17 = ADD32(0, 0X4B);
L_80800570:
    // 0x80800570: jal         0x80800000
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bskazstilt(rdram, ctx);
        goto after_11;
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800578: beq         $v0, $zero, L_80800584
    if (ctx->r2 == 0) {
        // 0x8080057C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800584;
    }
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800580: addiu       $s1, $zero, 0x160
    ctx->r17 = ADD32(0, 0X160);
L_80800584:
    // 0x80800584: jal         0x8009E5C8
    // 0x80800588: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    bs_setState(rdram, ctx);
        goto after_12;
    // 0x80800588: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_12:
    // 0x8080058C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800590: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800594: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800598: jr          $ra
    // 0x8080059C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8080059C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8080050C_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080050C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800510: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800514: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800518: lui         $a2, 0x3F1E
    ctx->r6 = S32(0X3F1E << 16);
    // 0x8080051C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800520: ori         $a2, $a2, 0xB852
    ctx->r6 = ctx->r6 | 0XB852;
    // 0x80800524: jal         0x8008CB3C
    // 0x80800528: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_0;
    // 0x80800528: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    after_0:
    // 0x8080052C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800530: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800538: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080053C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800540: jal         0x8009FFD8
    // 0x80800544: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800544: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080054C: jal         0x80095738
    // 0x80800550: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    baflag_isTrue(rdram, ctx);
        goto after_2;
    // 0x80800550: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_2:
    // 0x80800554: beq         $v0, $zero, L_8080056C
    if (ctx->r2 == 0) {
        // 0x80800558: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080056C;
    }
    // 0x80800558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080055C: jal         0x8009B9B0
    // 0x80800560: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800560: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800564: b           L_80800578
    // 0x80800568: nop

        goto L_80800578;
    // 0x80800568: nop

L_8080056C:
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800570: jal         0x8009B9B0
    // 0x80800574: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800574: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    after_4:
L_80800578:
    // 0x80800578: jal         0x8009C990
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_5;
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800580: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80800584: jal         0x8009BB00
    // 0x80800588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_6;
    // 0x80800588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080058C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800594: jal         0x8009BA68
    // 0x80800598: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_7;
    // 0x80800598: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x8080059C: jal         0x8009C990
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_8;
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808005A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005A8: jal         0x8009B9C0
    // 0x808005AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_9;
    // 0x808005AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808005B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005B4: jal         0x800A0CF4
    // 0x808005B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_10;
    // 0x808005B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C0: jal         0x8009BCB4
    // 0x808005C4: lui         $a1, 0xC396
    ctx->r5 = S32(0XC396 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_11;
    // 0x808005C4: lui         $a1, 0xC396
    ctx->r5 = S32(0XC396 << 16);
    after_11:
    // 0x808005C8: lui         $a1, 0xC2C7
    ctx->r5 = S32(0XC2C7 << 16);
    // 0x808005CC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808005D0: jal         0x8009BCC4
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_12;
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005DC: jal         0x800A4DA4
    // 0x808005E0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800A4DA4(rdram, ctx);
        goto after_13;
    // 0x808005E0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
    // 0x808005E4: jal         0x80800128
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800128_bsbfly(rdram, ctx);
        goto after_14;
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808005EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808005F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808005F4: lw          $t7, 0x188($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X188);
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005FC: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x80800600: lw          $t8, 0x188($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X188);
    // 0x80800604: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    // 0x80800608: jal         0x80084C60
    // 0x8080060C: sb          $zero, 0x1C($t8)
    MEM_B(0X1C, ctx->r24) = 0;
    _bafly_entrypoint_19(rdram, ctx);
        goto after_15;
    // 0x8080060C: sb          $zero, 0x1C($t8)
    MEM_B(0X1C, ctx->r24) = 0;
    after_15:
    // 0x80800610: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800614: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800618: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080061C: jr          $ra
    // 0x80800620: nop

    return;
    // 0x80800620: nop

;}
RECOMP_FUNC void func_80806928_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806928: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080692C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806930: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80806934: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80806938: lwc1        $f0, 0x184($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X184);
    // 0x8080693C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80806940: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80806944: nop

    // 0x80806948: bc1fl       L_80806964
    if (!c1cs) {
        // 0x8080694C: lwc1        $f8, 0x1EC($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X1EC);
            goto L_80806964;
    }
    goto skip_0;
    // 0x8080694C: lwc1        $f8, 0x1EC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1EC);
    skip_0:
    // 0x80806950: lwc1        $f6, 0x1E8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1E8);
    // 0x80806954: mul.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80806958: b           L_80806974
    // 0x8080695C: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
        goto L_80806974;
    // 0x8080695C: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x80806960: lwc1        $f8, 0x1EC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1EC);
L_80806964:
    // 0x80806964: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80806968: mul.s       $f2, $f10, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8080696C: nop

    // 0x80806970: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
L_80806974:
    // 0x80806974: beql        $t6, $zero, L_80806998
    if (ctx->r14 == 0) {
        // 0x80806978: lwc1        $f16, 0x20C($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X20C);
            goto L_80806998;
    }
    goto skip_1;
    // 0x80806978: lwc1        $f16, 0x20C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X20C);
    skip_1:
    // 0x8080697C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80806980: jal         0x80809D94
    // 0x80806984: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_80809D94_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80806984: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x80806988: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8080698C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80806990: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80806994: lwc1        $f16, 0x20C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X20C);
L_80806998:
    // 0x80806998: swc1        $f2, 0x208($v0)
    MEM_W(0X208, ctx->r2) = ctx->f2.u32l;
    // 0x8080699C: jal         0x80013728
    // 0x808069A0: sub.s       $f12, $f2, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f16.fl;
    func_80013728(rdram, ctx);
        goto after_1;
    // 0x808069A0: sub.s       $f12, $f2, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f16.fl;
    after_1:
    // 0x808069A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808069A8: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x808069AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808069B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808069B4: jr          $ra
    // 0x808069B8: div.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
    return;
    // 0x808069B8: div.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
;}
RECOMP_FUNC void bsdronefalldie_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800038: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080003C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800040: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800044: jal         0x800961AC
    // 0x80800048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_0;
    // 0x80800048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080004C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800050: jal         0x80092880
    // 0x80800054: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80092880(rdram, ctx);
        goto after_1;
    // 0x80800054: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080005C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
RECOMP_FUNC void bsbeggass_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080027C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800280: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(84, 0X2A0) << 16);
    // 0x80800284: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800288: jr          $ra
    // 0x8080028C: lw          $v0, 0x2A0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(84, 0X2A0));
    return;
    // 0x8080028C: lw          $v0, 0x2A0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(84, 0X2A0));
;}
RECOMP_FUNC void func_800EA068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA068: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EA06C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800EA070: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EA074: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800EA078: jal         0x80088260
    // 0x800EA07C: lw          $a0, 0x2DC4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2DC4);
    _gcsectionDll_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x800EA07C: lw          $a0, 0x2DC4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2DC4);
    after_0:
    // 0x800EA080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EA084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EA088: jr          $ra
    // 0x800EA08C: nop

    return;
    // 0x800EA08C: nop

;}
RECOMP_FUNC void func_808010C4_chmusicmenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010C4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x808010C8: addiu       $at, $zero, 0x6E
    ctx->r1 = ADD32(0, 0X6E);
    // 0x808010CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808010D0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808010D4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808010D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808010DC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808010E0: beq         $a1, $at, L_8080114C
    if (ctx->r5 == ctx->r1) {
        // 0x808010E4: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8080114C;
    }
    // 0x808010E4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808010E8: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808010EC: bne         $a1, $at, L_80801220
    if (ctx->r5 != ctx->r1) {
        // 0x808010F0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80801220;
    }
    // 0x808010F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808010F4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x808010F8: jal         0x800D3E40
    // 0x808010FC: sw          $a3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r7;
    func_800D3E40(rdram, ctx);
        goto after_0;
    // 0x808010FC: sw          $a3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r7;
    after_0:
    // 0x80801100: beq         $v0, $zero, L_80801128
    if (ctx->r2 == 0) {
        // 0x80801104: nop
    
            goto L_80801128;
    }
    // 0x80801104: nop

    // 0x80801108: jal         0x800DA298
    // 0x8080110C: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x8080110C: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    after_1:
    // 0x80801110: beq         $v0, $zero, L_80801128
    if (ctx->r2 == 0) {
        // 0x80801114: nop
    
            goto L_80801128;
    }
    // 0x80801114: nop

    // 0x80801118: jal         0x80088848
    // 0x8080111C: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x8080111C: nop

    after_2:
    // 0x80801120: beq         $v0, $zero, L_80801138
    if (ctx->r2 == 0) {
        // 0x80801124: lw          $t6, 0x78($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X78);
            goto L_80801138;
    }
    // 0x80801124: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
L_80801128:
    // 0x80801128: jal         0x800FFAB0
    // 0x8080112C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x8080112C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_3:
    // 0x80801130: b           L_80801220
    // 0x80801134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801220;
    // 0x80801134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801138:
    // 0x80801138: lbu         $t7, 0x65($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X65);
    // 0x8080113C: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x80801140: sb          $t8, 0x65($t6)
    MEM_B(0X65, ctx->r14) = ctx->r24;
    // 0x80801144: b           L_80801220
    // 0x80801148: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801220;
    // 0x80801148: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080114C:
    // 0x8080114C: lbu         $t0, 0x65($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X65);
    // 0x80801150: andi        $v0, $a2, 0x1
    ctx->r2 = ctx->r6 & 0X1;
    // 0x80801154: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x80801158: andi        $t1, $t0, 0xFFFE
    ctx->r9 = ctx->r8 & 0XFFFE;
    // 0x8080115C: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80801160: beq         $v0, $zero, L_80801218
    if (ctx->r2 == 0) {
        // 0x80801164: sb          $t2, 0x65($a3)
        MEM_B(0X65, ctx->r7) = ctx->r10;
            goto L_80801218;
    }
    // 0x80801164: sb          $t2, 0x65($a3)
    MEM_B(0X65, ctx->r7) = ctx->r10;
    // 0x80801168: lhu         $t3, 0x76($a3)
    ctx->r11 = MEM_HU(ctx->r7, 0X76);
    // 0x8080116C: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80801170: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80801174: srl         $t4, $t3, 7
    ctx->r12 = S32(U32(ctx->r11) >> 7);
    // 0x80801178: beq         $t4, $at, L_80801218
    if (ctx->r12 == ctx->r1) {
        // 0x8080117C: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80801218;
    }
    // 0x8080117C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801180: sw          $a3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r7;
    // 0x80801184: addiu       $s3, $sp, 0x40
    ctx->r19 = ADD32(ctx->r29, 0X40);
L_80801188:
    // 0x80801188: addiu       $s0, $s1, 0x1
    ctx->r16 = ADD32(ctx->r17, 0X1);
    // 0x8080118C: jal         0x800DA298
    // 0x80801190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80801190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801194: bne         $v0, $zero, L_808011AC
    if (ctx->r2 != 0) {
        // 0x80801198: slti        $at, $s0, 0xE
        ctx->r1 = SIGNED(ctx->r16) < 0XE ? 1 : 0;
            goto L_808011AC;
    }
    // 0x80801198: slti        $at, $s0, 0xE
    ctx->r1 = SIGNED(ctx->r16) < 0XE ? 1 : 0;
    // 0x8080119C: sll         $t5, $s2, 2
    ctx->r13 = S32(ctx->r18 << 2);
    // 0x808011A0: addu        $t7, $s3, $t5
    ctx->r15 = ADD32(ctx->r19, ctx->r13);
    // 0x808011A4: sw          $s1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r17;
    // 0x808011A8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_808011AC:
    // 0x808011AC: bne         $at, $zero, L_80801188
    if (ctx->r1 != 0) {
        // 0x808011B0: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_80801188;
    }
    // 0x808011B0: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x808011B4: bne         $s2, $zero, L_808011EC
    if (ctx->r18 != 0) {
        // 0x808011B8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808011EC;
    }
    // 0x808011B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808011BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_808011C0:
    // 0x808011C0: addiu       $s0, $s1, 0x1
    ctx->r16 = ADD32(ctx->r17, 0X1);
    // 0x808011C4: jal         0x800DA524
    // 0x808011C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800DA524(rdram, ctx);
        goto after_5;
    // 0x808011C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808011CC: slti        $at, $s0, 0xE
    ctx->r1 = SIGNED(ctx->r16) < 0XE ? 1 : 0;
    // 0x808011D0: bne         $at, $zero, L_808011C0
    if (ctx->r1 != 0) {
        // 0x808011D4: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_808011C0;
    }
    // 0x808011D4: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x808011D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808011DC: jal         0x800DC128
    // 0x808011E0: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_800DC128(rdram, ctx);
        goto after_6;
    // 0x808011E0: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_6:
    // 0x808011E4: b           L_80801200
    // 0x808011E8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_80801200;
    // 0x808011E8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_808011EC:
    // 0x808011EC: jal         0x800DC128
    // 0x808011F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800DC128(rdram, ctx);
        goto after_7;
    // 0x808011F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x808011F4: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x808011F8: addu        $t6, $s3, $t8
    ctx->r14 = ADD32(ctx->r19, ctx->r24);
    // 0x808011FC: lw          $s1, 0x0($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X0);
L_80801200:
    // 0x80801200: addiu       $s0, $s1, 0x1
    ctx->r16 = ADD32(ctx->r17, 0X1);
    // 0x80801204: jal         0x800DA544
    // 0x80801208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800DA544(rdram, ctx);
        goto after_8;
    // 0x80801208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080120C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80801210: jal         0x80102424
    // 0x80801214: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x80801214: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
L_80801218:
    // 0x80801218: b           L_80801220
    // 0x8080121C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801220;
    // 0x8080121C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801220:
    // 0x80801220: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801224: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801228: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080122C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80801230: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80801234: jr          $ra
    // 0x80801238: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80801238: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_800F83B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F83B8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F83BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F83C0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F83C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F83C8: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F83CC: jal         0x800A3514
    // 0x800F83D0: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800A3514(rdram, ctx);
        goto after_0;
    // 0x800F83D0: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F83D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F83D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F83DC: jr          $ra
    // 0x800F83E0: nop

    return;
    // 0x800F83E0: nop

;}
RECOMP_FUNC void func_80801A44_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A44: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801A48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A4C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80801A50: jal         0x800F54E4
    // 0x80801A54: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80801A54: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x80801A58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801A5C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80801A60: jal         0x8010D09C
    // 0x80801A64: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8010D09C(rdram, ctx);
        goto after_1;
    // 0x80801A64: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x80801A68: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80801A6C: jal         0x800EE7F8
    // 0x80801A70: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80801A70: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80801A74: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80801A78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801A7C: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80801A80: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80801A84: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801A88: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80801A8C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80801A90: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80801A94: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80801A98: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80801A9C: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x80801AA0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80801AA4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80801AA8: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x80801AAC: jal         0x800C6A7C
    // 0x80801AB0: lw          $a3, 0x14($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X14);
    func_800C6A7C(rdram, ctx);
        goto after_3;
    // 0x80801AB0: lw          $a3, 0x14($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X14);
    after_3:
    // 0x80801AB4: beq         $v0, $zero, L_80801ACC
    if (ctx->r2 == 0) {
        // 0x80801AB8: lw          $a0, 0x44($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X44);
            goto L_80801ACC;
    }
    // 0x80801AB8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80801ABC: jal         0x800EE7F8
    // 0x80801AC0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80801AC0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_4:
    // 0x80801AC4: b           L_80801AD8
    // 0x80801AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801AD8;
    // 0x80801AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801ACC:
    // 0x80801ACC: jal         0x8010D254
    // 0x80801AD0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_8010D254(rdram, ctx);
        goto after_5;
    // 0x80801AD0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_5:
    // 0x80801AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801AD8:
    // 0x80801AD8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801ADC: jr          $ra
    // 0x80801AE0: nop

    return;
    // 0x80801AE0: nop

;}
RECOMP_FUNC void func_80806D64_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806D64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80806D68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806D6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80806D70: jal         0x8080633C
    // 0x80806D74: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8080633C_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80806D74: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_0:
    // 0x80806D78: jal         0x80801928
    // 0x80806D7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80801928_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80806D7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80806D80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80806D84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80806D88: jr          $ra
    // 0x80806D8C: nop

    return;
    // 0x80806D8C: nop

;}
RECOMP_FUNC void func_800C9E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9E20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C9E24: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C9E28: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C9E2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C9E30: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C9E34: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800C9E38: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800C9E3C: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x800C9E40: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800C9E44: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800C9E48: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800C9E4C: jal         0x800C9750
    // 0x800C9E50: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    func_800C9750(rdram, ctx);
        goto after_0;
    // 0x800C9E50: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x800C9E54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C9E58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C9E5C: jr          $ra
    // 0x800C9E60: nop

    return;
    // 0x800C9E60: nop

;}
RECOMP_FUNC void _babackpack_get_state(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084508: syscall     113
    recomp_syscall_handler(rdram, ctx, 0x80084508);
    return;
    // 0x8008450C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8009E100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E100: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009E104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009E108: lw          $t6, 0x104($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X104);
    // 0x8009E10C: jal         0x800C3CE8
    // 0x8009E110: lbu         $a0, 0x3($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X3);
    func_800C3CE8(rdram, ctx);
        goto after_0;
    // 0x8009E110: lbu         $a0, 0x3($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X3);
    after_0:
    // 0x8009E114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009E118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009E11C: jr          $ra
    // 0x8009E120: nop

    return;
    // 0x8009E120: nop

    // 0x8009E124: nop

    // 0x8009E128: nop

    // 0x8009E12C: nop

;}
RECOMP_FUNC void func_8009EAD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EAD0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EAD4: jr          $ra
    // 0x8009EAD8: sb          $a0, 0x7074($at)
    MEM_B(0X7074, ctx->r1) = ctx->r4;
    return;
    // 0x8009EAD8: sb          $a0, 0x7074($at)
    MEM_B(0X7074, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_800CCFEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCFEC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800CCFF0: addiu       $v1, $v1, -0x5180
    ctx->r3 = ADD32(ctx->r3, -0X5180);
    // 0x800CCFF4: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x800CCFF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CCFFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CD000: beql        $a0, $zero, L_800CD020
    if (ctx->r4 == 0) {
        // 0x800CD004: lw          $a0, 0xC($v1)
        ctx->r4 = MEM_W(ctx->r3, 0XC);
            goto L_800CD020;
    }
    goto skip_0;
    // 0x800CD004: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    skip_0:
    // 0x800CD008: jal         0x8001BAFC
    // 0x800CD00C: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x800CD00C: nop

    after_0:
    // 0x800CD010: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800CD014: addiu       $v1, $v1, -0x5180
    ctx->r3 = ADD32(ctx->r3, -0X5180);
    // 0x800CD018: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x800CD01C: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
L_800CD020:
    // 0x800CD020: beql        $a0, $zero, L_800CD040
    if (ctx->r4 == 0) {
        // 0x800CD024: lw          $a0, 0x14($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X14);
            goto L_800CD040;
    }
    goto skip_1;
    // 0x800CD024: lw          $a0, 0x14($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X14);
    skip_1:
    // 0x800CD028: jal         0x8001BAFC
    // 0x800CD02C: nop

    defrag(rdram, ctx);
        goto after_1;
    // 0x800CD02C: nop

    after_1:
    // 0x800CD030: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800CD034: addiu       $v1, $v1, -0x5180
    ctx->r3 = ADD32(ctx->r3, -0X5180);
    // 0x800CD038: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x800CD03C: lw          $a0, 0x14($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X14);
L_800CD040:
    // 0x800CD040: beql        $a0, $zero, L_800CD060
    if (ctx->r4 == 0) {
        // 0x800CD044: lw          $a0, 0xE0($v1)
        ctx->r4 = MEM_W(ctx->r3, 0XE0);
            goto L_800CD060;
    }
    goto skip_2;
    // 0x800CD044: lw          $a0, 0xE0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XE0);
    skip_2:
    // 0x800CD048: jal         0x8001BAFC
    // 0x800CD04C: nop

    defrag(rdram, ctx);
        goto after_2;
    // 0x800CD04C: nop

    after_2:
    // 0x800CD050: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800CD054: addiu       $v1, $v1, -0x5180
    ctx->r3 = ADD32(ctx->r3, -0X5180);
    // 0x800CD058: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x800CD05C: lw          $a0, 0xE0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XE0);
L_800CD060:
    // 0x800CD060: beql        $a0, $zero, L_800CD080
    if (ctx->r4 == 0) {
        // 0x800CD064: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CD080;
    }
    goto skip_3;
    // 0x800CD064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x800CD068: jal         0x8001BAFC
    // 0x800CD06C: nop

    defrag(rdram, ctx);
        goto after_3;
    // 0x800CD06C: nop

    after_3:
    // 0x800CD070: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800CD074: addiu       $v1, $v1, -0x5180
    ctx->r3 = ADD32(ctx->r3, -0X5180);
    // 0x800CD078: sw          $v0, 0xE0($v1)
    MEM_W(0XE0, ctx->r3) = ctx->r2;
    // 0x800CD07C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CD080:
    // 0x800CD080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CD084: jr          $ra
    // 0x800CD088: nop

    return;
    // 0x800CD088: nop

;}
RECOMP_FUNC void _dbskeleton_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087A28: syscall     649
    recomp_syscall_handler(rdram, ctx, 0x80087A28);
    return;
    // 0x80087A2C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8080019C_chsignpost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080019C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001A0: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808001A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001A8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808001AC: beq         $a1, $at, L_808001D4
    if (ctx->r5 == ctx->r1) {
        // 0x808001B0: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_808001D4;
    }
    // 0x808001B0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808001B4: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x808001B8: beq         $a1, $at, L_808001EC
    if (ctx->r5 == ctx->r1) {
        // 0x808001BC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808001EC;
    }
    // 0x808001BC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808001C0: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x808001C4: beq         $a1, $at, L_80800200
    if (ctx->r5 == ctx->r1) {
        // 0x808001C8: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1656, 0X328) << 16);
            goto L_80800200;
    }
    // 0x808001C8: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1656, 0X328) << 16);
    // 0x808001CC: b           L_80800220
    // 0x808001D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800220;
    // 0x808001D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001D4:
    // 0x808001D4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808001D8: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    // 0x808001DC: jal         0x80800230
    // 0x808001E0: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    func_80800230_chsignpost(rdram, ctx);
        goto after_0;
    // 0x808001E0: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    after_0:
    // 0x808001E4: b           L_80800220
    // 0x808001E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800220;
    // 0x808001E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001EC:
    // 0x808001EC: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    // 0x808001F0: jal         0x80800264
    // 0x808001F4: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    func_80800264_chsignpost(rdram, ctx);
        goto after_1;
    // 0x808001F4: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    after_1:
    // 0x808001F8: b           L_80800220
    // 0x808001FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800220;
    // 0x808001FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800200:
    // 0x80800200: addiu       $a0, $a0, 0x328
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1656, 0X328));
    // 0x80800204: jal         0x80088090
    // 0x80800208: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800208: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_2:
    // 0x8080020C: b           L_80800220
    // 0x80800210: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800220;
    // 0x80800210: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800214: b           L_80800220
    // 0x80800218: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800220;
    // 0x80800218: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080021C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800220:
    // 0x80800220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800228: jr          $ra
    // 0x8080022C: nop

    return;
    // 0x8080022C: nop

;}
RECOMP_FUNC void func_800EBB30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EBB30: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800EBB34: addiu       $v1, $v1, 0x2EA0
    ctx->r3 = ADD32(ctx->r3, 0X2EA0);
    // 0x800EBB38: lw          $t6, 0x14($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X14);
    // 0x800EBB3C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800EBB40: lw          $t7, 0x18($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X18);
    // 0x800EBB44: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800EBB48: jr          $ra
    // 0x800EBB4C: lw          $v0, 0x1C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1C);
    return;
    // 0x800EBB4C: lw          $v0, 0x1C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1C);
;}
RECOMP_FUNC void func_80800084_glglobalsettings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800084: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800088: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080008C: jal         0x8001ACCC
    // 0x80800090: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x80800090: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_0:
    // 0x80800094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080009C: jr          $ra
    // 0x808000A0: nop

    return;
    // 0x808000A0: nop

;}
RECOMP_FUNC void sucoasterhit_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800C10: jal         0x80100094
    // 0x80800C14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800C18: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x80800C1C: srl         $t6, $a0, 28
    ctx->r14 = S32(U32(ctx->r4) >> 28);
    // 0x80800C20: jal         0x8008A240
    // 0x80800C24: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    _sucoasterdata_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800C24: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x80800C28: lw          $t7, 0x44($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X44);
    // 0x80800C2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800C30: lui         $a1, 0x4140
    ctx->r5 = S32(0X4140 << 16);
    // 0x80800C34: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x80800C38: beq         $t8, $zero, L_80800C88
    if (ctx->r24 == 0) {
        // 0x80800C3C: lui         $a2, 0x3F59
        ctx->r6 = S32(0X3F59 << 16);
            goto L_80800C88;
    }
    // 0x80800C3C: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x80800C40: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800C44: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800C48: jal         0x800E1610
    // 0x80800C4C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_800E1610(rdram, ctx);
        goto after_2;
    // 0x80800C4C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_2:
    // 0x80800C50: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80800C54: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800C58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800C5C: jal         0x80018820
    // 0x80800C60: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    func_80018820(rdram, ctx);
        goto after_3;
    // 0x80800C60: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    after_3:
    // 0x80800C64: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x80800C68: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800C6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800C70: jal         0x80089BF8
    // 0x80800C74: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    _subaddiejoy_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x80800C74: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    after_4:
    // 0x80800C78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800C7C: addiu       $a1, $zero, 0xB6
    ctx->r5 = ADD32(0, 0XB6);
    // 0x80800C80: jal         0x8010108C
    // 0x80800C84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_5;
    // 0x80800C84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
L_80800C88:
    // 0x80800C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C90: jr          $ra
    // 0x80800C94: nop

    return;
    // 0x80800C94: nop

    // 0x80800C98: nop

    // 0x80800C9C: nop

;}
RECOMP_FUNC void _bskazstilt_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083738: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x80083738);
    return;
    // 0x8008373C: addi        $t0, $zero, 0x6C
    ctx->r8 = ADD32(0, 0X6C);
;}
RECOMP_FUNC void bsbwhirl_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E8C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800E90: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(128, 0XFF8) << 16);
    // 0x80800E94: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800E98: jr          $ra
    // 0x80800E9C: lw          $v0, 0xFF8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(128, 0XFF8));
    return;
    // 0x80800E9C: lw          $v0, 0xFF8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(128, 0XFF8));
;}
RECOMP_FUNC void func_808008FC_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008FC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800900: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800904: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80800908: jal         0x80100094
    // 0x8080090C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080090C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800910: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800914: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800918: lbu         $t6, 0x72($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X72);
    // 0x8080091C: andi        $t7, $t6, 0xFF03
    ctx->r15 = ctx->r14 & 0XFF03;
    // 0x80800920: ori         $t8, $t7, 0x18
    ctx->r24 = ctx->r15 | 0X18;
    // 0x80800924: sb          $t8, 0x72($a0)
    MEM_B(0X72, ctx->r4) = ctx->r24;
    // 0x80800928: jal         0x80801500
    // 0x8080092C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    func_80801500_chcollballcontrol(rdram, ctx);
        goto after_1;
    // 0x8080092C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800930: jal         0x800FDC28
    // 0x80800934: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_2;
    // 0x80800934: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80800938: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8080093C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80800940: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x80800944: lbu         $t9, 0x3A($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X3A);
    // 0x80800948: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8080094C: addiu       $a0, $t0, 0x20
    ctx->r4 = ADD32(ctx->r8, 0X20);
    // 0x80800950: jal         0x80089978
    // 0x80800954: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    _sumultiscore_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800954: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_3:
    // 0x80800958: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8080095C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80800960: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80800964: lbu         $a3, 0x39($t0)
    ctx->r7 = MEM_BU(ctx->r8, 0X39);
    // 0x80800968: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8080096C: slti        $at, $a3, 0x4
    ctx->r1 = SIGNED(ctx->r7) < 0X4 ? 1 : 0;
    // 0x80800970: beql        $at, $zero, L_80800AC0
    if (ctx->r1 == 0) {
        // 0x80800974: sw          $t0, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r8;
            goto L_80800AC0;
    }
    goto skip_0;
    // 0x80800974: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    skip_0:
    // 0x80800978: lw          $t3, 0x64($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X64);
    // 0x8080097C: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x80800980: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800984: sll         $t5, $t3, 12
    ctx->r13 = S32(ctx->r11 << 12);
    // 0x80800988: bgez        $t5, L_80800A0C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8080098C: nop
    
            goto L_80800A0C;
    }
    // 0x8080098C: nop

    // 0x80800990: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x80800994: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800998: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080099C: beq         $v1, $a2, L_808009C4
    if (ctx->r3 == ctx->r6) {
        // 0x808009A0: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_808009C4;
    }
    // 0x808009A0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x808009A4: beq         $v1, $at, L_808009EC
    if (ctx->r3 == ctx->r1) {
        // 0x808009A8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808009EC;
    }
    // 0x808009A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808009AC: beq         $v1, $at, L_808009EC
    if (ctx->r3 == ctx->r1) {
        // 0x808009B0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808009EC;
    }
    // 0x808009B0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808009B4: beql        $v1, $at, L_808009F0
    if (ctx->r3 == ctx->r1) {
        // 0x808009B8: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_808009F0;
    }
    goto skip_1;
    // 0x808009B8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    skip_1:
    // 0x808009BC: b           L_80800B50
    // 0x808009C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800B50;
    // 0x808009C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009C4:
    // 0x808009C4: bnel        $t6, $zero, L_808009F0
    if (ctx->r14 != 0) {
        // 0x808009C8: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_808009F0;
    }
    goto skip_2;
    // 0x808009C8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    skip_2:
    // 0x808009CC: jal         0x800FC6B0
    // 0x808009D0: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_4;
    // 0x808009D0: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_4:
    // 0x808009D4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x808009D8: addiu       $a1, $zero, 0x12CC
    ctx->r5 = ADD32(0, 0X12CC);
    // 0x808009DC: jal         0x80800000
    // 0x808009E0: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    func_80800000_chcollballcontrol(rdram, ctx);
        goto after_5;
    // 0x808009E0: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_5:
    // 0x808009E4: b           L_80800B50
    // 0x808009E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800B50;
    // 0x808009E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009EC:
    // 0x808009EC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
L_808009F0:
    // 0x808009F0: addiu       $a1, $zero, 0x12CD
    ctx->r5 = ADD32(0, 0X12CD);
    // 0x808009F4: jal         0x80800000
    // 0x808009F8: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    func_80800000_chcollballcontrol(rdram, ctx);
        goto after_6;
    // 0x808009F8: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_6:
    // 0x808009FC: jal         0x800FC6B0
    // 0x80800A00: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_7;
    // 0x80800A00: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_7:
    // 0x80800A04: b           L_80800B50
    // 0x80800A08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800B50;
    // 0x80800A08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A0C:
    // 0x80800A0C: beq         $v1, $a2, L_80800A38
    if (ctx->r3 == ctx->r6) {
        // 0x80800A10: lw          $t7, 0x38($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X38);
            goto L_80800A38;
    }
    // 0x80800A10: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80800A14: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A18: beq         $v1, $at, L_80800A80
    if (ctx->r3 == ctx->r1) {
        // 0x80800A1C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800A80;
    }
    // 0x80800A1C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800A20: beq         $v1, $at, L_80800A80
    if (ctx->r3 == ctx->r1) {
        // 0x80800A24: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800A80;
    }
    // 0x80800A24: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800A28: beq         $v1, $at, L_80800AA0
    if (ctx->r3 == ctx->r1) {
        // 0x80800A2C: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_80800AA0;
    }
    // 0x80800A2C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800A30: b           L_80800B50
    // 0x80800A34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800B50;
    // 0x80800A34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A38:
    // 0x80800A38: bne         $t7, $zero, L_80800A80
    if (ctx->r15 != 0) {
        // 0x80800A3C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80800A80;
    }
    // 0x80800A3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800A40: lw          $a2, 0x20($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X20);
    // 0x80800A44: addiu       $a1, $a3, 0x91
    ctx->r5 = ADD32(ctx->r7, 0X91);
    // 0x80800A48: jal         0x800D2054
    // 0x80800A4C: addiu       $a2, $a2, 0x3E80
    ctx->r6 = ADD32(ctx->r6, 0X3E80);
    func_800D2054(rdram, ctx);
        goto after_8;
    // 0x80800A4C: addiu       $a2, $a2, 0x3E80
    ctx->r6 = ADD32(ctx->r6, 0X3E80);
    after_8:
    // 0x80800A50: jal         0x800DA544
    // 0x80800A54: addiu       $a0, $zero, 0xA17
    ctx->r4 = ADD32(0, 0XA17);
    func_800DA544(rdram, ctx);
        goto after_9;
    // 0x80800A54: addiu       $a0, $zero, 0xA17
    ctx->r4 = ADD32(0, 0XA17);
    after_9:
    // 0x80800A58: jal         0x800FC6B0
    // 0x80800A5C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_10;
    // 0x80800A5C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_10:
    // 0x80800A60: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800A64: jal         0x80101FDC
    // 0x80800A68: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80101FDC(rdram, ctx);
        goto after_11;
    // 0x80800A68: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_11:
    // 0x80800A6C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80800A70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A74: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x80800A78: b           L_80800B4C
    // 0x80800A7C: swc1        $f4, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f4.u32l;
        goto L_80800B4C;
    // 0x80800A7C: swc1        $f4, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f4.u32l;
L_80800A80:
    // 0x80800A80: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800A84: addiu       $a1, $zero, 0x127F
    ctx->r5 = ADD32(0, 0X127F);
    // 0x80800A88: jal         0x80800000
    // 0x80800A8C: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    func_80800000_chcollballcontrol(rdram, ctx);
        goto after_12;
    // 0x80800A8C: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_12:
    // 0x80800A90: jal         0x800FC6B0
    // 0x80800A94: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_13;
    // 0x80800A94: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_13:
    // 0x80800A98: b           L_80800B50
    // 0x80800A9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800B50;
    // 0x80800A9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800AA0:
    // 0x80800AA0: addiu       $a1, $zero, 0x1280
    ctx->r5 = ADD32(0, 0X1280);
    // 0x80800AA4: jal         0x80800000
    // 0x80800AA8: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    func_80800000_chcollballcontrol(rdram, ctx);
        goto after_14;
    // 0x80800AA8: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_14:
    // 0x80800AAC: jal         0x800FC6B0
    // 0x80800AB0: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_15;
    // 0x80800AB0: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_15:
    // 0x80800AB4: b           L_80800B50
    // 0x80800AB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800B50;
    // 0x80800AB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800ABC: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
L_80800AC0:
    // 0x80800AC0: jal         0x800AA200
    // 0x80800AC4: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    func_800AA200(rdram, ctx);
        goto after_16;
    // 0x80800AC4: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    after_16:
    // 0x80800AC8: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80800ACC: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80800AD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800AD4: lbu         $t9, 0x3A($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X3A);
    // 0x80800AD8: addiu       $v1, $sp, 0x4C
    ctx->r3 = ADD32(ctx->r29, 0X4C);
    // 0x80800ADC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800AE0: blez        $t9, L_80800B1C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80800AE4: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_80800B1C;
    }
    // 0x80800AE4: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80800AE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800AEC:
    // 0x80800AEC: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80800AF0: bnel        $a2, $t2, L_80800B04
    if (ctx->r6 != ctx->r10) {
        // 0x80800AF4: sb          $zero, 0x30($v0)
        MEM_B(0X30, ctx->r2) = 0;
            goto L_80800B04;
    }
    goto skip_3;
    // 0x80800AF4: sb          $zero, 0x30($v0)
    MEM_B(0X30, ctx->r2) = 0;
    skip_3:
    // 0x80800AF8: b           L_80800B04
    // 0x80800AFC: sb          $a1, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r5;
        goto L_80800B04;
    // 0x80800AFC: sb          $a1, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r5;
    // 0x80800B00: sb          $zero, 0x30($v0)
    MEM_B(0X30, ctx->r2) = 0;
L_80800B04:
    // 0x80800B04: lbu         $t3, 0x3A($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X3A);
    // 0x80800B08: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800B0C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800B10: slt         $at, $a0, $t3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80800B14: bne         $at, $zero, L_80800AEC
    if (ctx->r1 != 0) {
        // 0x80800B18: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80800AEC;
    }
    // 0x80800B18: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80800B1C:
    // 0x80800B1C: beq         $t1, $zero, L_80800B30
    if (ctx->r9 == 0) {
        // 0x80800B20: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_80800B30;
    }
    // 0x80800B20: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80800B24: addiu       $a1, $zero, 0x12D1
    ctx->r5 = ADD32(0, 0X12D1);
    // 0x80800B28: b           L_80800B34
    // 0x80800B2C: sb          $t1, 0x3B($t0)
    MEM_B(0X3B, ctx->r8) = ctx->r9;
        goto L_80800B34;
    // 0x80800B2C: sb          $t1, 0x3B($t0)
    MEM_B(0X3B, ctx->r8) = ctx->r9;
L_80800B30:
    // 0x80800B30: addiu       $a1, $zero, 0x12D2
    ctx->r5 = ADD32(0, 0X12D2);
L_80800B34:
    // 0x80800B34: jal         0x800FC6B0
    // 0x80800B38: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_800FC6B0(rdram, ctx);
        goto after_17;
    // 0x80800B38: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_17:
    // 0x80800B3C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800B40: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800B44: jal         0x80800000
    // 0x80800B48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800000_chcollballcontrol(rdram, ctx);
        goto after_18;
    // 0x80800B48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
L_80800B4C:
    // 0x80800B4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B50:
    // 0x80800B50: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800B54: jr          $ra
    // 0x80800B58: nop

    return;
    // 0x80800B58: nop

;}
RECOMP_FUNC void badust_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B50: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x80800B54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800B58: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80800B5C: lw          $t7, 0x5C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X5C);
    // 0x80800B60: sb          $zero, 0x8($t7)
    MEM_B(0X8, ctx->r15) = 0;
    // 0x80800B64: lw          $t8, 0x5C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X5C);
    // 0x80800B68: jal         0x80800B80
    // 0x80800B6C: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    badust_entrypoint_12(rdram, ctx);
        goto after_0;
    // 0x80800B6C: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    after_0:
    // 0x80800B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B78: jr          $ra
    // 0x80800B7C: nop

    return;
    // 0x80800B7C: nop

;}
RECOMP_FUNC void _chfishshootgame_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085A20: syscall     188
    recomp_syscall_handler(rdram, ctx, 0x80085A20);
    return;
    // 0x80085A24: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800C13D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C13D0: lhu         $t6, 0x7C($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X7C);
    // 0x800C13D4: and         $v0, $t6, $a1
    ctx->r2 = ctx->r14 & ctx->r5;
    // 0x800C13D8: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800C13DC: jr          $ra
    // 0x800C13E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800C13E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
;}
RECOMP_FUNC void _fxrain_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088920: syscall     710
    recomp_syscall_handler(rdram, ctx, 0x80088920);
    return;
    // 0x80088924: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_800A54F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A54F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A54FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5500: jal         0x8008FFE8
    // 0x800A5504: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x800A5504: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A5508: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A550C: jal         0x80089218
    // 0x800A5510: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    _ncfixposrot_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x800A5510: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800A5514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5518: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A551C: jr          $ra
    // 0x800A5520: nop

    return;
    // 0x800A5520: nop

;}
RECOMP_FUNC void func_80800424_chfootwear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800424: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800428: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080042C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800430: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800434: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800438: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8080043C: beq         $a1, $at, L_80800468
    if (ctx->r5 == ctx->r1) {
        // 0x80800440: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80800468;
    }
    // 0x80800440: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800444: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800448: beq         $a1, $at, L_80800490
    if (ctx->r5 == ctx->r1) {
        // 0x8080044C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800490;
    }
    // 0x8080044C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800450: beq         $a1, $at, L_808004F4
    if (ctx->r5 == ctx->r1) {
        // 0x80800454: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808004F4;
    }
    // 0x80800454: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800458: beql        $a1, $at, L_808004E8
    if (ctx->r5 == ctx->r1) {
        // 0x8080045C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808004E8;
    }
    goto skip_0;
    // 0x8080045C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80800460: b           L_808004F8
    // 0x80800464: sw          $s1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r17;
        goto L_808004F8;
    // 0x80800464: sw          $s1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r17;
L_80800468:
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080046C: jal         0x8008A4B0
    // 0x80800470: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800470: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800474: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080047C: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80800480: jal         0x8010A590
    // 0x80800484: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    func_8010A590(rdram, ctx);
        goto after_1;
    // 0x80800484: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    after_1:
    // 0x80800488: b           L_808004F8
    // 0x8080048C: sw          $s1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r17;
        goto L_808004F8;
    // 0x8080048C: sw          $s1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r17;
L_80800490:
    // 0x80800490: jal         0x8010A570
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_2;
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800498: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x8080049C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2448, 0X6E6) << 16);
    // 0x808004A0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808004A4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x808004A8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x808004AC: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x808004B0: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x808004B4: jal         0x800888C8
    // 0x808004B8: lh          $a1, 0x6E6($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(2448, 0X6E6));
    _fxsparkle_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808004B8: lh          $a1, 0x6E6($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(2448, 0X6E6));
    after_3:
    // 0x808004BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C0: jal         0x8008A4B0
    // 0x808004C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x808004C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808004C8: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x808004CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808004D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808004D4: andi        $t2, $t1, 0xFFFE
    ctx->r10 = ctx->r9 & 0XFFFE;
    // 0x808004D8: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    // 0x808004DC: b           L_808004F4
    // 0x808004E0: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
        goto L_808004F4;
    // 0x808004E0: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x808004E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_808004E8:
    // 0x808004E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808004EC: sb          $zero, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = 0;
    // 0x808004F0: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
L_808004F4:
    // 0x808004F4: sw          $s1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r17;
L_808004F8:
    // 0x808004F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004FC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800500: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800504: jr          $ra
    // 0x80800508: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800508: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
