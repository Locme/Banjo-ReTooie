#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800410_fxegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800410: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800414: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800418: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080041C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800420: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800424: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80800428: or          $t6, $a2, $zero
    ctx->r14 = ctx->r6 | 0;
    // 0x8080042C: lwc1        $f16, 0x8($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80800430: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80800434: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80800438: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8080043C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800440: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80800444: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800448: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8080044C: sll         $t4, $a3, 16
    ctx->r12 = S32(ctx->r7 << 16);
    // 0x80800450: sra         $a3, $t4, 16
    ctx->r7 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80800454: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800458: sll         $t1, $a2, 16
    ctx->r9 = S32(ctx->r6 << 16);
    // 0x8080045C: sra         $a2, $t1, 16
    ctx->r6 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80800460: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80800464: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80800468: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x8080046C: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x80800470: jal         0x800BA930
    // 0x80800474: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800BA930(rdram, ctx);
        goto after_0;
    // 0x80800474: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800478: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080047C: jal         0x800BA3FC
    // 0x80800480: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800BA3FC(rdram, ctx);
        goto after_1;
    // 0x80800480: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x80800484: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2834, 0X658) << 16);
    // 0x80800488: addiu       $t7, $t7, 0x658
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2834, 0X658));
    // 0x8080048C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800490: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800494: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800498: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080049C: jal         0x800BABB8
    // 0x808004A0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x808004A0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x808004A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808004A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808004AC: jr          $ra
    // 0x808004B0: nop

    return;
    // 0x808004B0: nop

;}
RECOMP_FUNC void _basquash_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800850C8: syscall     150
    recomp_syscall_handler(rdram, ctx, 0x800850C8);
    return;
    // 0x800850CC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800EB854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB854: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EB858: jr          $ra
    // 0x800EB85C: lh          $v0, 0x2E9C($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2E9C);
    return;
    // 0x800EB85C: lh          $v0, 0x2E9C($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2E9C);
;}
RECOMP_FUNC void func_80801EB4_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801EB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801EB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801EBC: lhu         $a1, 0x72($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X72);
    // 0x80801EC0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801EC4: srl         $t6, $a1, 10
    ctx->r14 = S32(U32(ctx->r5) >> 10);
    // 0x80801EC8: jal         0x8010203C
    // 0x80801ECC: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_8010203C(rdram, ctx);
        goto after_0;
    // 0x80801ECC: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_0:
    // 0x80801ED0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80801ED4: jal         0x80105AC4
    // 0x80801ED8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80105AC4(rdram, ctx);
        goto after_1;
    // 0x80801ED8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80801EDC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(932, 0X2B58) << 16);
    // 0x80801EE0: lwc1        $f4, 0x2B58($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(932, 0X2B58));
    // 0x80801EE4: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80801EE8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801EEC: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80801EF0: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80801EF4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80801EF8: jal         0x80101CDC
    // 0x80801EFC: nop

    func_80101CDC(rdram, ctx);
        goto after_2;
    // 0x80801EFC: nop

    after_2:
    // 0x80801F00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801F04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801F08: jr          $ra
    // 0x80801F0C: nop

    return;
    // 0x80801F0C: nop

;}
RECOMP_FUNC void func_80026780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026780: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026784: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026788: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002678C: jal         0x8002FEC0
    // 0x80026790: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80026790: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80026794: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80026798: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8002679C: lw          $t6, 0x11F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11F4);
    // 0x800267A0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800267A4: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x800267A8: sw          $t7, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r15;
    // 0x800267AC: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x800267B0: lw          $t9, 0x11F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11F4);
    // 0x800267B4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800267B8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800267BC: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800267C0: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x800267C4: lw          $t3, 0x11F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X11F4);
    // 0x800267C8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800267CC: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800267D0: jal         0x8002FEC0
    // 0x800267D4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800267D4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800267D8: b           L_800267E0
    // 0x800267DC: nop

        goto L_800267E0;
    // 0x800267DC: nop

L_800267E0:
    // 0x800267E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800267E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800267E8: jr          $ra
    // 0x800267EC: nop

    return;
    // 0x800267EC: nop

;}
RECOMP_FUNC void func_80804DB0_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804DB0: jr          $ra
    // 0x80804DB4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80804DB4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80098C48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098C48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80098C4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80098C50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80098C54: lw          $t7, 0xB8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XB8);
    // 0x80098C58: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80098C5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80098C60: jal         0x8009AD90
    // 0x80098C64: sb          $t6, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r14;
    func_8009AD90(rdram, ctx);
        goto after_0;
    // 0x80098C64: sb          $t6, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r14;
    after_0:
    // 0x80098C68: jal         0x80084910
    // 0x80098C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badronemem_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80098C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80098C70: jal         0x80085178
    // 0x80098C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bastatemem_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80098C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80098C78: jal         0x800A3820
    // 0x80098C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3820(rdram, ctx);
        goto after_3;
    // 0x80098C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80098C80: lw          $t8, 0xB8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XB8);
    // 0x80098C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80098C88: jal         0x80091B10
    // 0x80098C8C: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    bakey_init(rdram, ctx);
        goto after_4;
    // 0x80098C8C: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    after_4:
    // 0x80098C90: jal         0x8009FE78
    // 0x80098C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FE78(rdram, ctx);
        goto after_5;
    // 0x80098C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80098C98: jal         0x8009C038
    // 0x80098C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009C038(rdram, ctx);
        goto after_6;
    // 0x80098C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80098CA0: jal         0x800848E8
    // 0x80098CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_32(rdram, ctx);
        goto after_7;
    // 0x80098CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80098CA8: jal         0x80084A20
    // 0x80098CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80098CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80098CB0: jal         0x800955CC
    // 0x80098CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800955CC(rdram, ctx);
        goto after_9;
    // 0x80098CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80098CB8: jal         0x800956E8
    // 0x80098CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baflag_clearAll(rdram, ctx);
        goto after_10;
    // 0x80098CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80098CC0: jal         0x800A0FF0
    // 0x80098CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A0FF0(rdram, ctx);
        goto after_11;
    // 0x80098CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80098CC8: jal         0x8009F114
    // 0x80098CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_reset(rdram, ctx);
        goto after_12;
    // 0x80098CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80098CD0: jal         0x8009811C
    // 0x80098CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_init(rdram, ctx);
        goto after_13;
    // 0x80098CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80098CD8: jal         0x800854C0
    // 0x80098CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bainvisible_entrypoint_3(rdram, ctx);
        goto after_14;
    // 0x80098CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80098CE0: jal         0x80098408
    // 0x80098CE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80098408(rdram, ctx);
        goto after_15;
    // 0x80098CE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80098CE8: jal         0x8009CBFC
    // 0x80098CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009CBFC(rdram, ctx);
        goto after_16;
    // 0x80098CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80098CF0: jal         0x8009E7AC
    // 0x80098CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E7AC(rdram, ctx);
        goto after_17;
    // 0x80098CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80098CF8: jal         0x800A16F4
    // 0x80098CFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A16F4(rdram, ctx);
        goto after_18;
    // 0x80098CFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80098D00: jal         0x80091E20
    // 0x80098D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80091E20(rdram, ctx);
        goto after_19;
    // 0x80098D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80098D08: jal         0x80094644
    // 0x80098D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094644(rdram, ctx);
        goto after_20;
    // 0x80098D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80098D10: jal         0x80084AD8
    // 0x80098D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baeggcursor_entrypoint_5(rdram, ctx);
        goto after_21;
    // 0x80098D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80098D18: jal         0x80084CB8
    // 0x80098D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_8(rdram, ctx);
        goto after_22;
    // 0x80098D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80098D20: jal         0x80084778
    // 0x80098D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bapackctrl_entrypoint_3(rdram, ctx);
        goto after_23;
    // 0x80098D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80098D28: jal         0x80084480
    // 0x80098D2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bababykaz_entrypoint_2(rdram, ctx);
        goto after_24;
    // 0x80098D2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80098D30: jal         0x800A4168
    // 0x80098D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4168(rdram, ctx);
        goto after_25;
    // 0x80098D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80098D38: jal         0x80084628
    // 0x80098D3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bacough_entrypoint_3(rdram, ctx);
        goto after_26;
    // 0x80098D3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80098D40: jal         0x80091EC8
    // 0x80098D44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80091EC8(rdram, ctx);
        goto after_27;
    // 0x80098D44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80098D48: jal         0x80085500
    // 0x80098D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badeathmatch_entrypoint_1(rdram, ctx);
        goto after_28;
    // 0x80098D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80098D50: jal         0x80084948
    // 0x80098D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baduo_entrypoint_6(rdram, ctx);
        goto after_29;
    // 0x80098D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80098D58: jal         0x80084458
    // 0x80098D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baattach_entrypoint_4(rdram, ctx);
        goto after_30;
    // 0x80098D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80098D60: jal         0x80098898
    // 0x80098D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80098898(rdram, ctx);
        goto after_31;
    // 0x80098D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80098D68: jal         0x8009AC6C
    // 0x80098D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009AC6C(rdram, ctx);
        goto after_32;
    // 0x80098D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80098D70: jal         0x8009B4FC
    // 0x80098D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009B4FC(rdram, ctx);
        goto after_33;
    // 0x80098D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x80098D78: jal         0x8009BD50
    // 0x80098D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BD50(rdram, ctx);
        goto after_34;
    // 0x80098D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80098D80: jal         0x8009BF04
    // 0x80098D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BF04(rdram, ctx);
        goto after_35;
    // 0x80098D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x80098D88: jal         0x80098538
    // 0x80098D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80098538(rdram, ctx);
        goto after_36;
    // 0x80098D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x80098D90: jal         0x8009CC90
    // 0x80098D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009CC90(rdram, ctx);
        goto after_37;
    // 0x80098D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80098D98: jal         0x8009C474
    // 0x80098D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baroll_reset(rdram, ctx);
        goto after_38;
    // 0x80098D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x80098DA0: jal         0x8009CF98
    // 0x80098DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009CF98(rdram, ctx);
        goto after_39;
    // 0x80098DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x80098DA8: jal         0x80094F38
    // 0x80098DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094F38(rdram, ctx);
        goto after_40;
    // 0x80098DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
    // 0x80098DB0: jal         0x800A0C44
    // 0x80098DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A0C44(rdram, ctx);
        goto after_41;
    // 0x80098DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x80098DB8: jal         0x80095068
    // 0x80098DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095068(rdram, ctx);
        goto after_42;
    // 0x80098DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x80098DC0: jal         0x80090938
    // 0x80098DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80090938(rdram, ctx);
        goto after_43;
    // 0x80098DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x80098DC8: jal         0x8009105C
    // 0x80098DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009105C(rdram, ctx);
        goto after_44;
    // 0x80098DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x80098DD0: jal         0x80091650
    // 0x80098DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastatetimerlist_init(rdram, ctx);
        goto after_45;
    // 0x80098DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x80098DD8: jal         0x80084D20
    // 0x80098DDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bahold_entrypoint_1(rdram, ctx);
        goto after_46;
    // 0x80098DDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_46:
    // 0x80098DE0: jal         0x80095AD0
    // 0x80098DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095AD0(rdram, ctx);
        goto after_47;
    // 0x80098DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x80098DE8: jal         0x80084F18
    // 0x80098DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamum_entrypoint_2(rdram, ctx);
        goto after_48;
    // 0x80098DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x80098DF0: jal         0x8008C764
    // 0x80098DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_init(rdram, ctx);
        goto after_49;
    // 0x80098DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x80098DF8: jal         0x800A21C8
    // 0x80098DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A21C8(rdram, ctx);
        goto after_50;
    // 0x80098DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x80098E00: jal         0x80092898
    // 0x80098E04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092898(rdram, ctx);
        goto after_51;
    // 0x80098E04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_51:
    // 0x80098E08: jal         0x8008E618
    // 0x80098E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E618(rdram, ctx);
        goto after_52;
    // 0x80098E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_52:
    // 0x80098E10: jal         0x80084FC0
    // 0x80098E14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basetup_entrypoint_4(rdram, ctx);
        goto after_53;
    // 0x80098E14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_53:
    // 0x80098E18: jal         0x8009D4D8
    // 0x80098E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D4D8(rdram, ctx);
        goto after_54;
    // 0x80098E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_54:
    // 0x80098E20: jal         0x800A1F78
    // 0x80098E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A1F78(rdram, ctx);
        goto after_55;
    // 0x80098E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_55:
    // 0x80098E28: jal         0x80084FF8
    // 0x80098E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_4(rdram, ctx);
        goto after_56;
    // 0x80098E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_56:
    // 0x80098E30: jal         0x8009E390
    // 0x80098E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E390(rdram, ctx);
        goto after_57;
    // 0x80098E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_57:
    // 0x80098E38: jal         0x800850C0
    // 0x80098E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basquash_entrypoint_2(rdram, ctx);
        goto after_58;
    // 0x80098E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_58:
    // 0x80098E40: jal         0x800A2D94
    // 0x80098E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A2D94(rdram, ctx);
        goto after_59;
    // 0x80098E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_59:
    // 0x80098E48: jal         0x80085350
    // 0x80098E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _batranslate_entrypoint_2(rdram, ctx);
        goto after_60;
    // 0x80098E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_60:
    // 0x80098E50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80098E54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80098E58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80098E5C: jr          $ra
    // 0x80098E60: nop

    return;
    // 0x80098E60: nop

;}
RECOMP_FUNC void func_80802020_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802020: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802024: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802028: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080202C: jal         0x800D9078
    // 0x80802030: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x80802030: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
    // 0x80802034: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80802038: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8080203C: lui         $at, 0xC37A
    ctx->r1 = S32(0XC37A << 16);
    // 0x80802040: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802044: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80802048: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x8080204C: lwc1        $f12, 0x28($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X28);
    // 0x80802050: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80802054: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80802058: jal         0x800F12D4
    // 0x8080205C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F12D4(rdram, ctx);
        goto after_1;
    // 0x8080205C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80802060: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80802064: swc1        $f0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f0.u32l;
    // 0x80802068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080206C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80802070: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802074: jr          $ra
    // 0x80802078: nop

    return;
    // 0x80802078: nop

;}
RECOMP_FUNC void func_808018B8_chfantasyathlete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808018BC: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x808018C0: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x808018C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808018C8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808018CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808018D0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808018D4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x808018D8: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x808018DC: beq         $t7, $zero, L_80801910
    if (ctx->r15 == 0) {
        // 0x808018E0: sw          $t6, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r14;
            goto L_80801910;
    }
    // 0x808018E0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x808018E4: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x808018E8: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x808018EC: lw          $a0, 0x78($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X78);
    // 0x808018F0: jal         0x800D7520
    // 0x808018F4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_800D7520(rdram, ctx);
        goto after_0;
    // 0x808018F4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x808018F8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808018FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801900: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80801904: jal         0x800C7A68
    // 0x80801908: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_800C7A68(rdram, ctx);
        goto after_1;
    // 0x80801908: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_1:
    // 0x8080190C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_80801910:
    // 0x80801910: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80801914: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80801918: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080191C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80801920: beq         $v1, $zero, L_80801930
    if (ctx->r3 == 0) {
        // 0x80801924: addu        $v0, $t2, $t4
        ctx->r2 = ADD32(ctx->r10, ctx->r12);
            goto L_80801930;
    }
    // 0x80801924: addu        $v0, $t2, $t4
    ctx->r2 = ADD32(ctx->r10, ctx->r12);
    // 0x80801928: b           L_80801934
    // 0x8080192C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_80801934;
    // 0x8080192C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80801930:
    // 0x80801930: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80801934:
    // 0x80801934: lw          $a1, 0x78($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X78);
    // 0x80801938: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8080193C: jal         0x801058C4
    // 0x80801940: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_801058C4(rdram, ctx);
        goto after_2;
    // 0x80801940: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_2:
    // 0x80801944: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80801948: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8080194C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80801950: andi        $t6, $t5, 0x8
    ctx->r14 = ctx->r13 & 0X8;
    // 0x80801954: beql        $t6, $zero, L_80801968
    if (ctx->r14 == 0) {
        // 0x80801958: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801968;
    }
    goto skip_0;
    // 0x80801958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080195C: lwc1        $f4, 0x94($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X94);
    // 0x80801960: swc1        $f4, 0x48($t7)
    MEM_W(0X48, ctx->r15) = ctx->f4.u32l;
    // 0x80801964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801968:
    // 0x80801968: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080196C: jr          $ra
    // 0x80801970: nop

    return;
    // 0x80801970: nop

;}
RECOMP_FUNC void _ncbaglide_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800896E8: syscall     788
    recomp_syscall_handler(rdram, ctx, 0x800896E8);
    return;
    // 0x800896EC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808049D4_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808049D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808049D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808049DC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808049E0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808049E4: lbu         $a3, 0x79($a0)
    ctx->r7 = MEM_BU(ctx->r4, 0X79);
    // 0x808049E8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808049EC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808049F0: srl         $t6, $a3, 4
    ctx->r14 = S32(U32(ctx->r7) >> 4);
    // 0x808049F4: bne         $t6, $at, L_80804A80
    if (ctx->r14 != ctx->r1) {
        // 0x808049F8: or          $a3, $t6, $zero
        ctx->r7 = ctx->r14 | 0;
            goto L_80804A80;
    }
    // 0x808049F8: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x808049FC: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1852, 0X5918) << 16);
    // 0x80804A00: addiu       $t7, $t7, 0x5918
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1852, 0X5918));
    // 0x80804A04: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x80804A08: lw          $a3, 0x38($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X38);
    // 0x80804A0C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80804A10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80804A14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80804A18: jal         0x800BABB8
    // 0x80804A1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_0;
    // 0x80804A1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80804A20: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1852, 0X5960) << 16);
    // 0x80804A24: addiu       $t8, $t8, 0x5960
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1852, 0X5960));
    // 0x80804A28: lw          $a3, 0x38($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X38);
    // 0x80804A2C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80804A30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80804A34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80804A38: jal         0x800BABB8
    // 0x80804A3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x80804A3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80804A40: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1852, 0X59A8) << 16);
    // 0x80804A44: addiu       $t9, $t9, 0x59A8
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1852, 0X59A8));
    // 0x80804A48: lw          $a3, 0x38($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X38);
    // 0x80804A4C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80804A50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80804A54: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80804A58: jal         0x800BABB8
    // 0x80804A5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80804A5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80804A60: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1852, 0X59D8) << 16);
    // 0x80804A64: addiu       $a3, $a3, 0x59D8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1852, 0X59D8));
    // 0x80804A68: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80804A6C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80804A70: jal         0x8010D930
    // 0x80804A74: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8010D930(rdram, ctx);
        goto after_3;
    // 0x80804A74: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x80804A78: b           L_80804A94
    // 0x80804A7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80804A94;
    // 0x80804A7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80804A80:
    // 0x80804A80: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80804A84: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80804A88: jal         0x80088A60
    // 0x80804A8C: lw          $a2, 0x38($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X38);
    _fxegg_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80804A8C: lw          $a2, 0x38($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X38);
    after_4:
    // 0x80804A90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80804A94:
    // 0x80804A94: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80804A98: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80804A9C: jr          $ra
    // 0x80804AA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80804AA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80092778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092778: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009277C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80092780: jal         0x800A3274
    // 0x80092784: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800A3274(rdram, ctx);
        goto after_0;
    // 0x80092784: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80092788: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8009278C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80092790: addiu       $a2, $sp, 0x1E
    ctx->r6 = ADD32(ctx->r29, 0X1E);
    // 0x80092794: jal         0x80084F38
    // 0x80092798: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    _bapreload_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80092798: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x8009279C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800927A0: jal         0x80092EC8
    // 0x800927A4: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    func_80092EC8(rdram, ctx);
        goto after_2;
    // 0x800927A4: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    after_2:
    // 0x800927A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800927AC: jal         0x8009312C
    // 0x800927B0: lh          $a1, 0x1C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1C);
    func_8009312C(rdram, ctx);
        goto after_3;
    // 0x800927B0: lh          $a1, 0x1C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1C);
    after_3:
    // 0x800927B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800927B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800927BC: jr          $ra
    // 0x800927C0: nop

    return;
    // 0x800927C0: nop

;}
RECOMP_FUNC void func_800A7B18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7B18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A7B1C: jr          $ra
    // 0x800A7B20: sb          $a0, 0x7642($at)
    MEM_B(0X7642, ctx->r1) = ctx->r4;
    return;
    // 0x800A7B20: sb          $a0, 0x7642($at)
    MEM_B(0X7642, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_800E4208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4208: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E420C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E4210: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E4214: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800E4218: lw          $a1, -0x2AFC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2AFC);
    // 0x800E421C: jal         0x800CA314
    // 0x800E4220: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA314(rdram, ctx);
        goto after_0;
    // 0x800E4220: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E4224: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E4228: jal         0x800CA364
    // 0x800E422C: lw          $a0, -0x2AFC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2AFC);
    func_800CA364(rdram, ctx);
        goto after_1;
    // 0x800E422C: lw          $a0, -0x2AFC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2AFC);
    after_1:
    // 0x800E4230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E4234: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E4238: sw          $zero, -0x2AFC($at)
    MEM_W(-0X2AFC, ctx->r1) = 0;
    // 0x800E423C: jr          $ra
    // 0x800E4240: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800E4240: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _chbigterrysbits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085FF0: syscall     269
    recomp_syscall_handler(rdram, ctx, 0x80085FF0);
    return;
    // 0x80085FF4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800214_chjigsawbitcont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800214: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080021C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800220: jal         0x80100094
    // 0x80800224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800228: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080022C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800230: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x80800234: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x80800238: bgezl       $t9, L_808002D8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8080023C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002D8;
    }
    goto skip_0;
    // 0x8080023C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800240: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800244: jal         0x800D8FF8
    // 0x80800248: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800248: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8080024C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800250: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800254: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800258: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8080025C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1644, 0X9AA) << 16);
    // 0x80800260: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80800264: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
    // 0x80800268: lwc1        $f8, 0x28($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8080026C: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x80800270: nop

    // 0x80800274: bc1fl       L_808002D8
    if (!c1cs) {
        // 0x80800278: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002D8;
    }
    goto skip_1;
    // 0x80800278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8080027C: lbu         $t0, 0x65($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X65);
    // 0x80800280: lhu         $t3, 0x76($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X76);
    // 0x80800284: swc1        $f2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f2.u32l;
    // 0x80800288: andi        $t1, $t0, 0xFFEF
    ctx->r9 = ctx->r8 & 0XFFEF;
    // 0x8080028C: srl         $t4, $t3, 7
    ctx->r12 = S32(U32(ctx->r11) >> 7);
    // 0x80800290: sb          $t1, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r9;
    // 0x80800294: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80800298: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8080029C: lh          $t6, 0x9AA($t6)
    ctx->r14 = MEM_H(ctx->r14, (int16_t)RELOC_LO16(1644, 0X9AA));
    // 0x808002A0: lh          $t2, 0x24($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X24);
    // 0x808002A4: slt         $at, $t2, $t6
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x808002A8: beql        $at, $zero, L_808002D8
    if (ctx->r1 == 0) {
        // 0x808002AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002D8;
    }
    goto skip_2;
    // 0x808002AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x808002B0: jal         0x800FCCD4
    // 0x808002B4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800FCCD4(rdram, ctx);
        goto after_2;
    // 0x808002B4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_2:
    // 0x808002B8: beq         $v0, $zero, L_808002D4
    if (ctx->r2 == 0) {
        // 0x808002BC: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_808002D4;
    }
    // 0x808002BC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x808002C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002C4: jal         0x800FCAE0
    // 0x808002C8: addiu       $a2, $zero, 0x1F40
    ctx->r6 = ADD32(0, 0X1F40);
    func_800FCAE0(rdram, ctx);
        goto after_3;
    // 0x808002C8: addiu       $a2, $zero, 0x1F40
    ctx->r6 = ADD32(0, 0X1F40);
    after_3:
    // 0x808002CC: jal         0x800FCA90
    // 0x808002D0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800FCA90(rdram, ctx);
        goto after_4;
    // 0x808002D0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_4:
L_808002D4:
    // 0x808002D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002D8:
    // 0x808002D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002DC: jr          $ra
    // 0x808002E0: nop

    return;
    // 0x808002E0: nop

;}
RECOMP_FUNC void bskazstilt_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808008E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808008F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808008F4: jal         0x8008CABC
    // 0x808008F8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808008F8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808008FC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800904: jal         0x8009D3A8
    // 0x80800908: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D3A8(rdram, ctx);
        goto after_1;
    // 0x80800908: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080090C: lui         $a1, 0x3F2E
    ctx->r5 = S32(0X3F2E << 16);
    // 0x80800910: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    // 0x80800914: jal         0x8008B348
    // 0x80800918: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_2;
    // 0x80800918: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8080091C: beq         $v0, $zero, L_8080092C
    if (ctx->r2 == 0) {
        // 0x80800920: nop
    
            goto L_8080092C;
    }
    // 0x80800920: nop

    // 0x80800924: jal         0x800C3BDC
    // 0x80800928: lbu         $a0, 0x160($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X160);
    func_800C3BDC(rdram, ctx);
        goto after_3;
    // 0x80800928: lbu         $a0, 0x160($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X160);
    after_3:
L_8080092C:
    // 0x8080092C: jal         0x8008B324
    // 0x80800930: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_4;
    // 0x80800930: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800934: beq         $v0, $zero, L_80800940
    if (ctx->r2 == 0) {
        // 0x80800938: addiu       $t6, $zero, 0xBB
        ctx->r14 = ADD32(0, 0XBB);
            goto L_80800940;
    }
    // 0x80800938: addiu       $t6, $zero, 0xBB
    ctx->r14 = ADD32(0, 0XBB);
    // 0x8080093C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800940:
    // 0x80800940: jal         0x80800000
    // 0x80800944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bskazstilt(rdram, ctx);
        goto after_5;
    // 0x80800944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800948: beq         $v0, $zero, L_80800958
    if (ctx->r2 == 0) {
        // 0x8080094C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800958;
    }
    // 0x8080094C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800950: addiu       $t7, $zero, 0x160
    ctx->r15 = ADD32(0, 0X160);
    // 0x80800954: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80800958:
    // 0x80800958: jal         0x8009E5C8
    // 0x8080095C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x8080095C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x80800960: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800964: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800968: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080096C: jr          $ra
    // 0x80800970: nop

    return;
    // 0x80800970: nop

;}
RECOMP_FUNC void _gspropmarker_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C40: syscall     730
    recomp_syscall_handler(rdram, ctx, 0x80088C40);
    return;
    // 0x80088C44: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void badrone_entrypoint_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800564: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080056C: jal         0x80800348
    // 0x80800570: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80800348_badrone(rdram, ctx);
        goto after_0;
    // 0x80800570: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_0:
    // 0x80800574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080057C: jr          $ra
    // 0x80800580: nop

    return;
    // 0x80800580: nop

;}
RECOMP_FUNC void func_80800BC4_chblackeye(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BC4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800BC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800BCC: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80800BD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800BD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800BD8: beq         $a1, $at, L_80800D64
    if (ctx->r5 == ctx->r1) {
        // 0x80800BDC: sw          $a2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r6;
            goto L_80800D64;
    }
    // 0x80800BDC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80800BE0: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x80800BE4: beq         $a1, $at, L_80800C14
    if (ctx->r5 == ctx->r1) {
        // 0x80800BE8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C14;
    }
    // 0x80800BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BEC: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x80800BF0: beq         $a1, $at, L_80800C44
    if (ctx->r5 == ctx->r1) {
        // 0x80800BF4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C44;
    }
    // 0x80800BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BF8: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800BFC: beq         $a1, $at, L_80800C54
    if (ctx->r5 == ctx->r1) {
        // 0x80800C00: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_80800C54;
    }
    // 0x80800C00: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800C04: beql        $a1, $at, L_80800CC8
    if (ctx->r5 == ctx->r1) {
        // 0x80800C08: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_80800CC8;
    }
    goto skip_0;
    // 0x80800C08: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x80800C0C: b           L_80800DA0
    // 0x80800C10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800DA0;
    // 0x80800C10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C14:
    // 0x80800C14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800C18: jal         0x800897C0
    // 0x80800C1C: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800C1C: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    after_0:
    // 0x80800C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C24: jal         0x80100094
    // 0x80800C28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800C28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800C2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C30: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80800C34: jal         0x800897E8
    // 0x80800C38: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80800C38: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    after_2:
    // 0x80800C3C: b           L_80800DA0
    // 0x80800C40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800DA0;
    // 0x80800C40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C44:
    // 0x80800C44: jal         0x800897C8
    // 0x80800C48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x80800C48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800C4C: b           L_80800DA0
    // 0x80800C50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800DA0;
    // 0x80800C50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C54:
    // 0x80800C54: lbu         $t6, 0x74($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X74);
    // 0x80800C58: addiu       $at, $zero, 0x1012
    ctx->r1 = ADD32(0, 0X1012);
    // 0x80800C5C: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    // 0x80800C60: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x80800C64: sb          $t7, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r15;
    // 0x80800C68: lh          $t8, 0x48($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X48);
    // 0x80800C6C: bnel        $t8, $at, L_80800CB8
    if (ctx->r24 != ctx->r1) {
        // 0x80800C70: lui         $at, 0x41C8
        ctx->r1 = S32(0X41C8 << 16);
            goto L_80800CB8;
    }
    goto skip_1;
    // 0x80800C70: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    skip_1:
    // 0x80800C74: jal         0x800D175C
    // 0x80800C78: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800D175C(rdram, ctx);
        goto after_4;
    // 0x80800C78: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800C7C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x80800C80: jal         0x800D0BD4
    // 0x80800C84: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_800D0BD4(rdram, ctx);
        goto after_5;
    // 0x80800C84: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_5:
    // 0x80800C88: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x80800C8C: jal         0x800D0BD4
    // 0x80800C90: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_800D0BD4(rdram, ctx);
        goto after_6;
    // 0x80800C90: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_6:
    // 0x80800C94: jal         0x800FC660
    // 0x80800C98: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_7;
    // 0x80800C98: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_7:
    // 0x80800C9C: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80800CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CA4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800CA8: ori         $t1, $t0, 0x8
    ctx->r9 = ctx->r8 | 0X8;
    // 0x80800CAC: jal         0x80800314
    // 0x80800CB0: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    func_80800314_chblackeye(rdram, ctx);
        goto after_8;
    // 0x80800CB0: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    after_8:
    // 0x80800CB4: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
L_80800CB8:
    // 0x80800CB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800CBC: b           L_80800D9C
    // 0x80800CC0: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_80800D9C;
    // 0x80800CC0: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x80800CC4: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_80800CC8:
    // 0x80800CC8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800CCC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800CD0: srl         $t2, $v0, 10
    ctx->r10 = S32(U32(ctx->r2) >> 10);
    // 0x80800CD4: beq         $t2, $at, L_80800CF4
    if (ctx->r10 == ctx->r1) {
        // 0x80800CD8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800CF4;
    }
    // 0x80800CD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800CDC: beq         $t2, $at, L_80800CF4
    if (ctx->r10 == ctx->r1) {
        // 0x80800CE0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800CF4;
    }
    // 0x80800CE0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800CE4: beq         $t2, $at, L_80800D2C
    if (ctx->r10 == ctx->r1) {
        // 0x80800CE8: addiu       $a0, $sp, 0x28
        ctx->r4 = ADD32(ctx->r29, 0X28);
            goto L_80800D2C;
    }
    // 0x80800CE8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800CEC: b           L_80800DA0
    // 0x80800CF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800DA0;
    // 0x80800CF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CF4:
    // 0x80800CF4: jal         0x800EE7F8
    // 0x80800CF8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x80800CF8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x80800CFC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800D00: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800D04: jal         0x800EF1B8
    // 0x80800D08: lui         $a2, 0xC316
    ctx->r6 = S32(0XC316 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_10;
    // 0x80800D08: lui         $a2, 0xC316
    ctx->r6 = S32(0XC316 << 16);
    after_10:
    // 0x80800D0C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1796, 0X102C) << 16);
    // 0x80800D10: addiu       $a0, $a0, 0x102C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1796, 0X102C));
    // 0x80800D14: jal         0x80088090
    // 0x80800D18: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x80800D18: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_11:
    // 0x80800D1C: jal         0x80088098
    // 0x80800D20: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_12;
    // 0x80800D20: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_12:
    // 0x80800D24: b           L_80800DA0
    // 0x80800D28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800DA0;
    // 0x80800D28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D2C:
    // 0x80800D2C: jal         0x800EE7F8
    // 0x80800D30: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_13;
    // 0x80800D30: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_13:
    // 0x80800D34: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800D38: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800D3C: jal         0x800EF1B8
    // 0x80800D40: lui         $a2, 0xC3E1
    ctx->r6 = S32(0XC3E1 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_14;
    // 0x80800D40: lui         $a2, 0xC3E1
    ctx->r6 = S32(0XC3E1 << 16);
    after_14:
    // 0x80800D44: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1796, 0X103C) << 16);
    // 0x80800D48: addiu       $a0, $a0, 0x103C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1796, 0X103C));
    // 0x80800D4C: jal         0x80088090
    // 0x80800D50: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_15;
    // 0x80800D50: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_15:
    // 0x80800D54: jal         0x80088098
    // 0x80800D58: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_16;
    // 0x80800D58: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_16:
    // 0x80800D5C: b           L_80800DA0
    // 0x80800D60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800DA0;
    // 0x80800D60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D64:
    // 0x80800D64: jal         0x801015D0
    // 0x80800D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_17;
    // 0x80800D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800D6C: lw          $a1, 0x64($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X64);
    // 0x80800D70: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800D74: sll         $t3, $a1, 11
    ctx->r11 = S32(ctx->r5 << 11);
    // 0x80800D78: jal         0x800DF744
    // 0x80800D7C: srl         $a1, $t3, 31
    ctx->r5 = S32(U32(ctx->r11) >> 31);
    func_800DF744(rdram, ctx);
        goto after_18;
    // 0x80800D7C: srl         $a1, $t3, 31
    ctx->r5 = S32(U32(ctx->r11) >> 31);
    after_18:
    // 0x80800D80: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800D84: jal         0x800DF744
    // 0x80800D88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_19;
    // 0x80800D88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80800D8C: b           L_80800DA0
    // 0x80800D90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800DA0;
    // 0x80800D90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800D94: b           L_80800DA0
    // 0x80800D98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800DA0;
    // 0x80800D98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800D9C:
    // 0x80800D9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800DA0:
    // 0x80800DA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800DA8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800DAC: jr          $ra
    // 0x80800DB0: nop

    return;
    // 0x80800DB0: nop

;}
RECOMP_FUNC void func_800C3A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3A40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C3A44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C3A48: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C3A4C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C3A50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3A54: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C3A58: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C3A5C: beq         $t6, $zero, L_800C3AD0
    if (ctx->r14 == 0) {
        // 0x800C3A60: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_800C3AD0;
    }
    // 0x800C3A60: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800C3A64: jal         0x800C1414
    // 0x800C3A68: nop

    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C3A68: nop

    after_0:
    // 0x800C3A6C: lbu         $t8, 0x7B($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X7B);
    // 0x800C3A70: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C3A74: ori         $t0, $t8, 0x10
    ctx->r8 = ctx->r24 | 0X10;
    // 0x800C3A78: andi        $t1, $t0, 0xFD
    ctx->r9 = ctx->r8 & 0XFD;
    // 0x800C3A7C: sb          $t0, 0x7B($v0)
    MEM_B(0X7B, ctx->r2) = ctx->r8;
    // 0x800C3A80: ori         $t2, $t1, 0x2
    ctx->r10 = ctx->r9 | 0X2;
    // 0x800C3A84: sb          $t2, 0x7B($v0)
    MEM_B(0X7B, ctx->r2) = ctx->r10;
    // 0x800C3A88: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C3A8C: lw          $t3, 0x78($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X78);
    // 0x800C3A90: ori         $t8, $t2, 0x8
    ctx->r24 = ctx->r10 | 0X8;
    // 0x800C3A94: swc1        $f4, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f4.u32l;
    // 0x800C3A98: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3A9C: sll         $t5, $t3, 28
    ctx->r13 = S32(ctx->r11 << 28);
    // 0x800C3AA0: swc1        $f6, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f6.u32l;
    // 0x800C3AA4: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C3AA8: swc1        $f10, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f10.u32l;
    // 0x800C3AAC: bltz        $t5, L_800C3AD0
    if (SIGNED(ctx->r13) < 0) {
        // 0x800C3AB0: swc1        $f8, 0x48($v0)
        MEM_W(0X48, ctx->r2) = ctx->f8.u32l;
            goto L_800C3AD0;
    }
    // 0x800C3AB0: swc1        $f8, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f8.u32l;
    // 0x800C3AB4: lh          $v1, 0x5A($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X5A);
    // 0x800C3AB8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C3ABC: sb          $t8, 0x7B($v0)
    MEM_B(0X7B, ctx->r2) = ctx->r24;
    // 0x800C3AC0: sh          $zero, 0x5A($v0)
    MEM_H(0X5A, ctx->r2) = 0;
    // 0x800C3AC4: sh          $v1, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r3;
    // 0x800C3AC8: sh          $v1, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r3;
    // 0x800C3ACC: swc1        $f16, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f16.u32l;
L_800C3AD0:
    // 0x800C3AD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3AD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C3AD8: jr          $ra
    // 0x800C3ADC: nop

    return;
    // 0x800C3ADC: nop

;}
RECOMP_FUNC void badata_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CDC: jal         0x80800000
    // 0x80800CE0: nop

    func_80800000_badata(rdram, ctx);
        goto after_0;
    // 0x80800CE0: nop

    after_0:
    // 0x80800CE4: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80800CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CEC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(473, 0X1718) << 16);
    // 0x80800CF0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800CF4: lh          $v0, 0x1718($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(473, 0X1718));
    // 0x80800CF8: jr          $ra
    // 0x80800CFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800CFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void chnests_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F8C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(752, 0X13E0) << 16);
    // 0x80800F90: jr          $ra
    // 0x80800F94: addiu       $v0, $v0, 0x13E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X13E0));
    return;
    // 0x80800F94: addiu       $v0, $v0, 0x13E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X13E0));
;}
RECOMP_FUNC void func_800BA7FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA7FC: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800BA800: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BA804: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800BA808: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800BA80C: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800BA810: nop

    // 0x800BA814: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800BA818: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800BA81C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800BA820: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800BA824: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800BA828: sh          $t7, 0x9E($a0)
    MEM_H(0X9E, ctx->r4) = ctx->r15;
    // 0x800BA82C: jr          $ra
    // 0x800BA830: sh          $t9, 0xA0($a0)
    MEM_H(0XA0, ctx->r4) = ctx->r25;
    return;
    // 0x800BA830: sh          $t9, 0xA0($a0)
    MEM_H(0XA0, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void func_80801060_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801068: jal         0x800839B8
    // 0x8080106C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x8080106C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801070: jal         0x8080064C
    // 0x80801074: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstrexlarge_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80801074: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080107C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801080: jr          $ra
    // 0x80801084: nop

    return;
    // 0x80801084: nop

;}
RECOMP_FUNC void bainput_func_80097B4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097B4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80097B50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097B54: jal         0x80091970
    // 0x80097B58: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    bakey_heldCount(rdram, ctx);
        goto after_0;
    // 0x80097B58: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80097B5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097B60: slti        $t6, $v0, 0x9
    ctx->r14 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x80097B64: xori        $v0, $t6, 0x1
    ctx->r2 = ctx->r14 ^ 0X1;
    // 0x80097B68: jr          $ra
    // 0x80097B6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80097B6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80807394_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807394: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80807398: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080739C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808073A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808073A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808073A8: jal         0x8009E6EC
    // 0x808073AC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x808073AC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x808073B0: addiu       $at, $zero, 0x62
    ctx->r1 = ADD32(0, 0X62);
    // 0x808073B4: beq         $v0, $at, L_808073D4
    if (ctx->r2 == ctx->r1) {
        // 0x808073B8: addiu       $at, $zero, 0x63
        ctx->r1 = ADD32(0, 0X63);
            goto L_808073D4;
    }
    // 0x808073B8: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x808073BC: beq         $v0, $at, L_80807470
    if (ctx->r2 == ctx->r1) {
        // 0x808073C0: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_80807470;
    }
    // 0x808073C0: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x808073C4: beq         $v0, $at, L_808073F8
    if (ctx->r2 == ctx->r1) {
        // 0x808073C8: nop
    
            goto L_808073F8;
    }
    // 0x808073C8: nop

    // 0x808073CC: b           L_80807494
    // 0x808073D0: nop

        goto L_80807494;
    // 0x808073D0: nop

L_808073D4:
    // 0x808073D4: jal         0x800A3404
    // 0x808073D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3404(rdram, ctx);
        goto after_1;
    // 0x808073D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808073DC: bnel        $v0, $zero, L_808074A8
    if (ctx->r2 != 0) {
        // 0x808073E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808074A8;
    }
    goto skip_0;
    // 0x808073E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808073E4: jal         0x80807EEC
    // 0x808073E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807EEC_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x808073E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808073EC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x808073F0: b           L_808074A4
    // 0x808073F4: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
        goto L_808074A4;
    // 0x808073F4: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_808073F8:
    // 0x808073F8: jal         0x800A3404
    // 0x808073FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3404(rdram, ctx);
        goto after_3;
    // 0x808073FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80807400: beq         $v0, $zero, L_80807448
    if (ctx->r2 == 0) {
        // 0x80807404: nop
    
            goto L_80807448;
    }
    // 0x80807404: nop

    // 0x80807408: jal         0x800D3948
    // 0x8080740C: nop

    func_800D3948(rdram, ctx);
        goto after_4;
    // 0x8080740C: nop

    after_4:
    // 0x80807410: bne         $v0, $zero, L_80807448
    if (ctx->r2 != 0) {
        // 0x80807414: nop
    
            goto L_80807448;
    }
    // 0x80807414: nop

    // 0x80807418: jal         0x80807F24
    // 0x8080741C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807F24_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x8080741C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80807420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807424: addiu       $a1, $zero, 0x30D
    ctx->r5 = ADD32(0, 0X30D);
    // 0x80807428: jal         0x8008CBB0
    // 0x8080742C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baanim_playForDuration_loop(rdram, ctx);
        goto after_6;
    // 0x8080742C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_6:
    // 0x80807430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807434: addiu       $a1, $zero, 0x311
    ctx->r5 = ADD32(0, 0X311);
    // 0x80807438: jal         0x80800488
    // 0x8080743C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    func_80800488_bsfirstp(rdram, ctx);
        goto after_7;
    // 0x8080743C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_7:
    // 0x80807440: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80807444: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_80807448:
    // 0x80807448: jal         0x80099A58
    // 0x8080744C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A58(rdram, ctx);
        goto after_8;
    // 0x8080744C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80807450: jal         0x80089620
    // 0x80807454: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _ncpoddialog_entrypoint_10(rdram, ctx);
        goto after_9;
    // 0x80807454: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x80807458: beq         $v0, $zero, L_808074A4
    if (ctx->r2 == 0) {
        // 0x8080745C: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_808074A4;
    }
    // 0x8080745C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80807460: sw          $t9, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r25;
    // 0x80807464: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80807468: b           L_808074A4
    // 0x8080746C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
        goto L_808074A4;
    // 0x8080746C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
L_80807470:
    // 0x80807470: jal         0x800A3404
    // 0x80807474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3404(rdram, ctx);
        goto after_10;
    // 0x80807474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80807478: beql        $v0, $zero, L_808074A8
    if (ctx->r2 == 0) {
        // 0x8080747C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808074A8;
    }
    goto skip_1;
    // 0x8080747C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80807480: jal         0x80807F24
    // 0x80807484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807F24_bsfirstp(rdram, ctx);
        goto after_11;
    // 0x80807484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80807488: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8080748C: b           L_808074A4
    // 0x80807490: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
        goto L_808074A4;
    // 0x80807490: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
L_80807494:
    // 0x80807494: jal         0x80805994
    // 0x80807498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bsfirstp_entrypoint_26(rdram, ctx);
        goto after_12;
    // 0x80807498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080749C: b           L_808074C0
    // 0x808074A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808074C0;
    // 0x808074A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808074A4:
    // 0x808074A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808074A8:
    // 0x808074A8: jal         0x8009E830
    // 0x808074AC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_8009E830(rdram, ctx);
        goto after_13;
    // 0x808074AC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_13:
    // 0x808074B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808074B4: jal         0x8009E5C8
    // 0x808074B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bs_setState(rdram, ctx);
        goto after_14;
    // 0x808074B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x808074BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808074C0:
    // 0x808074C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808074C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808074C8: jr          $ra
    // 0x808074CC: nop

    return;
    // 0x808074CC: nop

;}
RECOMP_FUNC void func_800FA9B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA9B4: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800FA9B8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800FA9BC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800FA9C0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FA9C4: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x800FA9C8: lw          $a2, 0x3898($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3898);
    // 0x800FA9CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FA9D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FA9D4: beql        $a2, $zero, L_800FA9E8
    if (ctx->r6 == 0) {
        // 0x800FA9D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FA9E8;
    }
    goto skip_0;
    // 0x800FA9D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800FA9DC: jal         0x8008A5C8
    // 0x800FA9E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    _scinfobar_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x800FA9E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x800FA9E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FA9E8:
    // 0x800FA9E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FA9EC: jr          $ra
    // 0x800FA9F0: nop

    return;
    // 0x800FA9F0: nop

;}
RECOMP_FUNC void _idwater_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088E60: syscall     744
    recomp_syscall_handler(rdram, ctx, 0x80088E60);
    return;
    // 0x80088E64: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80803B88_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803B88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803B8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803B90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80803B94: jal         0x800C8A98
    // 0x80803B98: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800C8A98(rdram, ctx);
        goto after_0;
    // 0x80803B98: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80803B9C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80803BA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803BA4: jal         0x800C8CB8
    // 0x80803BA8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800C8CB8(rdram, ctx);
        goto after_1;
    // 0x80803BA8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80803BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803BB0: jal         0x800C8F64
    // 0x80803BB4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_800C8F64(rdram, ctx);
        goto after_2;
    // 0x80803BB4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_2:
    // 0x80803BB8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2484, 0X755C) << 16);
    // 0x80803BBC: addiu       $a1, $a1, 0x755C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2484, 0X755C));
    // 0x80803BC0: jal         0x800C8D4C
    // 0x80803BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C8D4C(rdram, ctx);
        goto after_3;
    // 0x80803BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80803BC8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2484, 0X7564) << 16);
    // 0x80803BCC: addiu       $a1, $a1, 0x7564
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2484, 0X7564));
    // 0x80803BD0: jal         0x800C8E84
    // 0x80803BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C8E84(rdram, ctx);
        goto after_4;
    // 0x80803BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80803BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803BDC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80803BE0: jal         0x800863E8
    // 0x80803BE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80803BE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80803BE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803BEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80803BF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803BF4: jr          $ra
    // 0x80803BF8: nop

    return;
    // 0x80803BF8: nop

;}
RECOMP_FUNC void func_800B2198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2198: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800B219C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800B21A0: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x800B21A4: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800B21A8: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x800B21AC: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x800B21B0: lh          $t9, 0x6($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X6);
    // 0x800B21B4: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800B21B8: lh          $t0, 0x8($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X8);
    // 0x800B21BC: sw          $t0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r8;
    // 0x800B21C0: lh          $t1, 0xA($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XA);
    // 0x800B21C4: jr          $ra
    // 0x800B21C8: sw          $t1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r9;
    return;
    // 0x800B21C8: sw          $t1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r9;
;}
RECOMP_FUNC void func_80800190_chbonfirecavern(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800190: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800194: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800198: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080019C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001A0: jal         0x800D9078
    // 0x808001A4: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x808001A4: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_0:
    // 0x808001A8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808001AC: jal         0x80086148
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chfirefx_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001B4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808001B8: beql        $t6, $zero, L_808001EC
    if (ctx->r14 == 0) {
        // 0x808001BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808001EC;
    }
    goto skip_0;
    // 0x808001BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808001C0: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x808001C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001CC: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808001D0: bnel        $t8, $at, L_808001EC
    if (ctx->r24 != ctx->r1) {
        // 0x808001D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808001EC;
    }
    goto skip_1;
    // 0x808001D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808001D8: jal         0x80101FDC
    // 0x808001DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x808001DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x808001E0: jal         0x8010A590
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_3;
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808001E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001EC:
    // 0x808001EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001F4: jr          $ra
    // 0x808001F8: nop

    return;
    // 0x808001F8: nop

    // 0x808001FC: nop

;}
RECOMP_FUNC void _sumole_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800899E0: syscall     800
    recomp_syscall_handler(rdram, ctx, 0x800899E0);
    return;
    // 0x800899E4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chcrate_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086FA8: syscall     486
    recomp_syscall_handler(rdram, ctx, 0x80086FA8);
    return;
    // 0x80086FAC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chtemplebrokendoorpiece_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1924, 0X15C) << 16);
    // 0x808000F4: jr          $ra
    // 0x808000F8: addiu       $v0, $v0, 0x15C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1924, 0X15C));
    return;
    // 0x808000F8: addiu       $v0, $v0, 0x15C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1924, 0X15C));
    // 0x808000FC: nop

;}
RECOMP_FUNC void func_80800440_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800440: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800448: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080044C: jal         0x8008CABC
    // 0x80800450: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800450: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800454: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800458: jal         0x800852C0
    // 0x8080045C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _baswim_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x8080045C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800460: jal         0x800852C8
    // 0x80800464: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _baswim_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80800464: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800468: jal         0x800852D0
    // 0x8080046C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _baswim_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x8080046C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800470: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800474: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800478: jal         0x8008B348
    // 0x8080047C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    anctrl_isAt(rdram, ctx);
        goto after_4;
    // 0x8080047C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80800480: beq         $v0, $zero, L_808004AC
    if (ctx->r2 == 0) {
        // 0x80800484: lui         $a2, 0x3F99
        ctx->r6 = S32(0X3F99 << 16);
            goto L_808004AC;
    }
    // 0x80800484: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x80800488: lui         $a3, 0x3FB3
    ctx->r7 = S32(0X3FB3 << 16);
    // 0x8080048C: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80800490: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800494: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800498: jal         0x8009DE74
    // 0x8080049C: addiu       $a1, $zero, 0x3FD
    ctx->r5 = ADD32(0, 0X3FD);
    func_8009DE74(rdram, ctx);
        goto after_5;
    // 0x8080049C: addiu       $a1, $zero, 0x3FD
    ctx->r5 = ADD32(0, 0X3FD);
    after_5:
    // 0x808004A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808004A4: jal         0x800852B8
    // 0x808004A8: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    _baswim_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x808004A8: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    after_6:
L_808004AC:
    // 0x808004AC: lui         $a1, 0x3EEC
    ctx->r5 = S32(0X3EEC << 16);
    // 0x808004B0: ori         $a1, $a1, 0xD9E8
    ctx->r5 = ctx->r5 | 0XD9E8;
    // 0x808004B4: jal         0x8008B348
    // 0x808004B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x808004B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_7:
    // 0x808004BC: beql        $v0, $zero, L_808004D4
    if (ctx->r2 == 0) {
        // 0x808004C0: lui         $a1, 0x3E8D
        ctx->r5 = S32(0X3E8D << 16);
            goto L_808004D4;
    }
    goto skip_0;
    // 0x808004C0: lui         $a1, 0x3E8D
    ctx->r5 = S32(0X3E8D << 16);
    skip_0:
    // 0x808004C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808004C8: jal         0x8008B1BC
    // 0x808004CC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_8;
    // 0x808004CC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_8:
    // 0x808004D0: lui         $a1, 0x3E8D
    ctx->r5 = S32(0X3E8D << 16);
L_808004D4:
    // 0x808004D4: ori         $a1, $a1, 0x9E84
    ctx->r5 = ctx->r5 | 0X9E84;
    // 0x808004D8: jal         0x8008B348
    // 0x808004DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    anctrl_isAt(rdram, ctx);
        goto after_9;
    // 0x808004DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_9:
    // 0x808004E0: beq         $v0, $zero, L_808004F4
    if (ctx->r2 == 0) {
        // 0x808004E4: nop
    
            goto L_808004F4;
    }
    // 0x808004E4: nop

    // 0x808004E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808004EC: jal         0x8008B1BC
    // 0x808004F0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_10;
    // 0x808004F0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_10:
L_808004F4:
    // 0x808004F4: jal         0x80085280
    // 0x808004F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _baswim_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x808004F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_11:
    // 0x808004FC: beq         $v0, $zero, L_8080052C
    if (ctx->r2 == 0) {
        // 0x80800500: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080052C;
    }
    // 0x80800500: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800504: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800508: beq         $v0, $at, L_80800548
    if (ctx->r2 == ctx->r1) {
        // 0x8080050C: addiu       $t7, $zero, 0x39
        ctx->r15 = ADD32(0, 0X39);
            goto L_80800548;
    }
    // 0x8080050C: addiu       $t7, $zero, 0x39
    ctx->r15 = ADD32(0, 0X39);
    // 0x80800510: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800514: beq         $v0, $at, L_80800554
    if (ctx->r2 == ctx->r1) {
        // 0x80800518: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800554;
    }
    // 0x80800518: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080051C: beq         $v0, $at, L_80800550
    if (ctx->r2 == ctx->r1) {
        // 0x80800520: addiu       $t8, $zero, 0x19
        ctx->r24 = ADD32(0, 0X19);
            goto L_80800550;
    }
    // 0x80800520: addiu       $t8, $zero, 0x19
    ctx->r24 = ADD32(0, 0X19);
    // 0x80800524: b           L_80800558
    // 0x80800528: lui         $a1, 0x3EEC
    ctx->r5 = S32(0X3EEC << 16);
        goto L_80800558;
    // 0x80800528: lui         $a1, 0x3EEC
    ctx->r5 = S32(0X3EEC << 16);
L_8080052C:
    // 0x8080052C: lui         $a1, 0x3EEC
    ctx->r5 = S32(0X3EEC << 16);
    // 0x80800530: jal         0x8008B348
    // 0x80800534: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    anctrl_isAt(rdram, ctx);
        goto after_12;
    // 0x80800534: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_12:
    // 0x80800538: beq         $v0, $zero, L_80800554
    if (ctx->r2 == 0) {
        // 0x8080053C: addiu       $t6, $zero, 0x2B
        ctx->r14 = ADD32(0, 0X2B);
            goto L_80800554;
    }
    // 0x8080053C: addiu       $t6, $zero, 0x2B
    ctx->r14 = ADD32(0, 0X2B);
    // 0x80800540: b           L_80800554
    // 0x80800544: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
        goto L_80800554;
    // 0x80800544: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80800548:
    // 0x80800548: b           L_80800554
    // 0x8080054C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
        goto L_80800554;
    // 0x8080054C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_80800550:
    // 0x80800550: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_80800554:
    // 0x80800554: lui         $a1, 0x3EEC
    ctx->r5 = S32(0X3EEC << 16);
L_80800558:
    // 0x80800558: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8080055C: jal         0x8008B348
    // 0x80800560: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    anctrl_isAt(rdram, ctx);
        goto after_13;
    // 0x80800560: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_13:
    // 0x80800564: beq         $v0, $zero, L_8080059C
    if (ctx->r2 == 0) {
        // 0x80800568: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8080059C;
    }
    // 0x80800568: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080056C: jal         0x800919F4
    // 0x80800570: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_held(rdram, ctx);
        goto after_14;
    // 0x80800570: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_14:
    // 0x80800574: bne         $v0, $zero, L_8080059C
    if (ctx->r2 != 0) {
        // 0x80800578: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8080059C;
    }
    // 0x80800578: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080057C: jal         0x800919F4
    // 0x80800580: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_held(rdram, ctx);
        goto after_15;
    // 0x80800580: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_15:
    // 0x80800584: beq         $v0, $zero, L_80800598
    if (ctx->r2 == 0) {
        // 0x80800588: addiu       $t0, $zero, 0x2B
        ctx->r8 = ADD32(0, 0X2B);
            goto L_80800598;
    }
    // 0x80800588: addiu       $t0, $zero, 0x2B
    ctx->r8 = ADD32(0, 0X2B);
    // 0x8080058C: addiu       $t9, $zero, 0x39
    ctx->r25 = ADD32(0, 0X39);
    // 0x80800590: b           L_8080059C
    // 0x80800594: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
        goto L_8080059C;
    // 0x80800594: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_80800598:
    // 0x80800598: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
L_8080059C:
    // 0x8080059C: jal         0x8009803C
    // 0x808005A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bainput_func_8009803C(rdram, ctx);
        goto after_16;
    // 0x808005A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_16:
    // 0x808005A4: beq         $v0, $zero, L_808005B0
    if (ctx->r2 == 0) {
        // 0x808005A8: addiu       $t1, $zero, 0x157
        ctx->r9 = ADD32(0, 0X157);
            goto L_808005B0;
    }
    // 0x808005A8: addiu       $t1, $zero, 0x157
    ctx->r9 = ADD32(0, 0X157);
    // 0x808005AC: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
L_808005B0:
    // 0x808005B0: jal         0x80085278
    // 0x808005B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _baswim_entrypoint_2(rdram, ctx);
        goto after_17;
    // 0x808005B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_17:
    // 0x808005B8: beq         $v0, $zero, L_808005C4
    if (ctx->r2 == 0) {
        // 0x808005BC: addiu       $t2, $zero, 0x2D
        ctx->r10 = ADD32(0, 0X2D);
            goto L_808005C4;
    }
    // 0x808005BC: addiu       $t2, $zero, 0x2D
    ctx->r10 = ADD32(0, 0X2D);
    // 0x808005C0: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
L_808005C4:
    // 0x808005C4: jal         0x8008E35C
    // 0x808005C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    player_inWater(rdram, ctx);
        goto after_18;
    // 0x808005C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_18:
    // 0x808005CC: bne         $v0, $zero, L_808005D8
    if (ctx->r2 != 0) {
        // 0x808005D0: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_808005D8;
    }
    // 0x808005D0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x808005D4: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
L_808005D8:
    // 0x808005D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808005DC: jal         0x8009E5C8
    // 0x808005E0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_19;
    // 0x808005E0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_19:
    // 0x808005E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808005EC: jr          $ra
    // 0x808005F0: nop

    return;
    // 0x808005F0: nop

;}
RECOMP_FUNC void subaddiedialog_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800360: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800364: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080036C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800370: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80800374: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800378: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8080037C: jal         0x80800000
    // 0x80800380: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_80800000_subaddiedialog(rdram, ctx);
        goto after_0;
    // 0x80800380: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x80800384: bne         $v0, $zero, L_80800394
    if (ctx->r2 != 0) {
        // 0x80800388: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800394;
    }
    // 0x80800388: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080038C: b           L_808003FC
    // 0x80800390: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003FC;
    // 0x80800390: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800394:
    // 0x80800394: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800398: jal         0x8080110C
    // 0x8080039C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_8080110C_subaddiedialog(rdram, ctx);
        goto after_1;
    // 0x8080039C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x808003A0: beq         $v0, $zero, L_808003C0
    if (ctx->r2 == 0) {
        // 0x808003A4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808003C0;
    }
    // 0x808003A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808003A8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808003AC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808003B0: jal         0x8080118C
    // 0x808003B4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_8080118C_subaddiedialog(rdram, ctx);
        goto after_2;
    // 0x808003B4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x808003B8: bne         $v0, $zero, L_808003C8
    if (ctx->r2 != 0) {
        // 0x808003BC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808003C8;
    }
    // 0x808003BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_808003C0:
    // 0x808003C0: b           L_808003FC
    // 0x808003C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003FC;
    // 0x808003C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003C8:
    // 0x808003C8: jal         0x80016B30
    // 0x808003CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80016B30(rdram, ctx);
        goto after_3;
    // 0x808003CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808003D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808003D4: beq         $v0, $at, L_808003E4
    if (ctx->r2 == ctx->r1) {
        // 0x808003D8: nop
    
            goto L_808003E4;
    }
    // 0x808003D8: nop

    // 0x808003DC: b           L_808003FC
    // 0x808003E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003FC;
    // 0x808003E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003E4:
    // 0x808003E4: jal         0x800F54E4
    // 0x808003E8: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x808003E8: nop

    after_4:
    // 0x808003EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003F0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808003F4: jal         0x800F4BB8
    // 0x808003F8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_800F4BB8(rdram, ctx);
        goto after_5;
    // 0x808003F8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_5:
L_808003FC:
    // 0x808003FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800400: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800404: jr          $ra
    // 0x80800408: nop

    return;
    // 0x80800408: nop

;}
RECOMP_FUNC void func_8080062C_chhoneyb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080062C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800630: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800634: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800638: jal         0x80088408
    // 0x8080063C: lw          $a0, 0x28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X28);
    _gcextra_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080063C: lw          $a0, 0x28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X28);
    after_0:
    // 0x80800640: jal         0x8008FD48
    // 0x80800644: nop

    func_8008FD48(rdram, ctx);
        goto after_1;
    // 0x80800644: nop

    after_1:
    // 0x80800648: jal         0x800A1658
    // 0x8080064C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800A1658(rdram, ctx);
        goto after_2;
    // 0x8080064C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800650: jal         0x80800058
    // 0x80800654: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800058_chhoneyb(rdram, ctx);
        goto after_3;
    // 0x80800654: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800658: jal         0x80800B78
    // 0x8080065C: nop

    func_80800B78_chhoneyb(rdram, ctx);
        goto after_4;
    // 0x8080065C: nop

    after_4:
    // 0x80800660: addiu       $a0, $zero, 0x4B8
    ctx->r4 = ADD32(0, 0X4B8);
    // 0x80800664: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    // 0x80800668: jal         0x80101180
    // 0x8080066C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80101180(rdram, ctx);
        goto after_5;
    // 0x8080066C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
    // 0x80800670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800674: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800678: jr          $ra
    // 0x8080067C: nop

    return;
    // 0x8080067C: nop

;}
RECOMP_FUNC void func_800B8F88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8F88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B8F8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B8F90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B8F94: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800B8F98: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800B8F9C: jal         0x800B8CFC
    // 0x800B8FA0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800B8CFC(rdram, ctx);
        goto after_0;
    // 0x800B8FA0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x800B8FA4: addiu       $t6, $zero, 0x130
    ctx->r14 = ADD32(0, 0X130);
    // 0x800B8FA8: subu        $a1, $t6, $v0
    ctx->r5 = SUB32(ctx->r14, ctx->r2);
    // 0x800B8FAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B8FB0: bgez        $a1, L_800B8FC0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800B8FB4: sra         $t7, $a1, 1
        ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
            goto L_800B8FC0;
    }
    // 0x800B8FB4: sra         $t7, $a1, 1
    ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800B8FB8: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x800B8FBC: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_800B8FC0:
    // 0x800B8FC0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800B8FC4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8FC8: jal         0x800B8E28
    // 0x800B8FCC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_800B8E28(rdram, ctx);
        goto after_1;
    // 0x800B8FCC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800B8FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B8FD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B8FD8: jr          $ra
    // 0x800B8FDC: nop

    return;
    // 0x800B8FDC: nop

;}
RECOMP_FUNC void func_800F8294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8294: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F8298: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F829C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F82A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F82A4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F82A8: jal         0x800F452C
    // 0x800F82AC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800F452C(rdram, ctx);
        goto after_0;
    // 0x800F82AC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F82B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F82B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F82B8: jr          $ra
    // 0x800F82BC: nop

    return;
    // 0x800F82BC: nop

;}
RECOMP_FUNC void func_8008F990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F990: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008F994: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F998: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008F99C: jal         0x800F54E4
    // 0x8008F9A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008F9A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8008F9A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F9A8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8008F9AC: jal         0x800F4A58
    // 0x8008F9B0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800F4A58(rdram, ctx);
        goto after_1;
    // 0x8008F9B0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8008F9B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008F9B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008F9BC: jr          $ra
    // 0x8008F9C0: nop

    return;
    // 0x8008F9C0: nop

;}
RECOMP_FUNC void func_80800074_chfoodwarn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800074: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800078: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080007C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800080: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800084: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800088: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080008C: jal         0x800EFC7C
    // 0x80800090: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_800EFC7C(rdram, ctx);
        goto after_0;
    // 0x80800090: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_0:
    // 0x80800094: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800098: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8080009C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808000A0: jal         0x800EFC7C
    // 0x808000A4: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    func_800EFC7C(rdram, ctx);
        goto after_1;
    // 0x808000A4: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_1:
    // 0x808000A8: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808000AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000B4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808000B8: nop

    // 0x808000BC: bc1f        L_808000CC
    if (!c1cs) {
        // 0x808000C0: nop
    
            goto L_808000CC;
    }
    // 0x808000C0: nop

    // 0x808000C4: b           L_808000CC
    // 0x808000C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000CC;
    // 0x808000C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000CC:
    // 0x808000CC: jr          $ra
    // 0x808000D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808000D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _badust_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800849D8: syscall     125
    recomp_syscall_handler(rdram, ctx, 0x800849D8);
    return;
    // 0x800849DC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void ncpoddialog_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802770: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80802774: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802778: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x8080277C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802780: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80802784: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80802788: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080278C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80802790: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x80802794: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80802798: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x8080279C: jal         0x800EEDE8
    // 0x808027A0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800EEDE8(rdram, ctx);
        goto after_0;
    // 0x808027A0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x808027A4: bne         $v0, $zero, L_808027C0
    if (ctx->r2 != 0) {
        // 0x808027A8: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_808027C0;
    }
    // 0x808027A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808027AC: jal         0x800EE7F8
    // 0x808027B0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808027B0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x808027B4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x808027B8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808027BC: sb          $t8, 0x216($t9)
    MEM_B(0X216, ctx->r25) = ctx->r24;
L_808027C0:
    // 0x808027C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808027C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808027C8: jr          $ra
    // 0x808027CC: nop

    return;
    // 0x808027CC: nop

;}
RECOMP_FUNC void func_800FEDC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FEDC4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800FEDC8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800FEDCC: addiu       $v1, $v1, 0x59C0
    ctx->r3 = ADD32(ctx->r3, 0X59C0);
    // 0x800FEDD0: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x800FEDD4: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800FEDD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FEDDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FEDE0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800FEDE4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800FEDE8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800FEDEC: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800FEDF0: lh          $t0, 0x36($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X36);
    // 0x800FEDF4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800FEDF8: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800FEDFC: bne         $a1, $t0, L_800FEE74
    if (ctx->r5 != ctx->r8) {
        // 0x800FEE00: addu        $s0, $v1, $a2
        ctx->r16 = ADD32(ctx->r3, ctx->r6);
            goto L_800FEE74;
    }
    // 0x800FEE00: addu        $s0, $v1, $a2
    ctx->r16 = ADD32(ctx->r3, ctx->r6);
    // 0x800FEE04: beql        $a1, $zero, L_800FEE78
    if (ctx->r5 == 0) {
        // 0x800FEE08: lbu         $a0, 0x34($s0)
        ctx->r4 = MEM_BU(ctx->r16, 0X34);
            goto L_800FEE78;
    }
    goto skip_0;
    // 0x800FEE08: lbu         $a0, 0x34($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X34);
    skip_0:
    // 0x800FEE0C: jal         0x800EA05C
    // 0x800FEE10: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x800FEE10: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x800FEE14: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800FEE18: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800FEE1C: addiu       $v1, $v1, 0x59C0
    ctx->r3 = ADD32(ctx->r3, 0X59C0);
    // 0x800FEE20: addu        $s0, $v1, $a2
    ctx->r16 = ADD32(ctx->r3, ctx->r6);
    // 0x800FEE24: lbu         $a0, 0x34($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X34);
    // 0x800FEE28: jal         0x800C3648
    // 0x800FEE2C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800C3648(rdram, ctx);
        goto after_1;
    // 0x800FEE2C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x800FEE30: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800FEE34: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800FEE38: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800FEE3C: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x800FEE40: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800FEE44: lh          $t3, 0x3E5E($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X3E5E);
    // 0x800FEE48: lbu         $a0, 0x34($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X34);
    // 0x800FEE4C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800FEE50: nop

    // 0x800FEE54: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800FEE58: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800FEE5C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800FEE60: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800FEE64: jal         0x800C3058
    // 0x800FEE68: nop

    func_800C3058(rdram, ctx);
        goto after_2;
    // 0x800FEE68: nop

    after_2:
    // 0x800FEE6C: b           L_800FEF84
    // 0x800FEE70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800FEF84;
    // 0x800FEE70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800FEE74:
    // 0x800FEE74: lbu         $a0, 0x34($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X34);
L_800FEE78:
    // 0x800FEE78: beql        $a0, $zero, L_800FEEC4
    if (ctx->r4 == 0) {
        // 0x800FEE7C: lw          $t5, 0x34($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X34);
            goto L_800FEEC4;
    }
    goto skip_1;
    // 0x800FEE7C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x800FEE80: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800FEE84: nop

    // 0x800FEE88: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x800FEE8C: nop

    // 0x800FEE90: bc1t        L_800FEEB4
    if (c1cs) {
        // 0x800FEE94: nop
    
            goto L_800FEEB4;
    }
    // 0x800FEE94: nop

    // 0x800FEE98: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800FEE9C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800FEEA0: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x800FEEA4: jal         0x800C3A40
    // 0x800FEEA8: nop

    func_800C3A40(rdram, ctx);
        goto after_3;
    // 0x800FEEA8: nop

    after_3:
    // 0x800FEEAC: b           L_800FEEC0
    // 0x800FEEB0: sb          $zero, 0x34($s0)
    MEM_B(0X34, ctx->r16) = 0;
        goto L_800FEEC0;
    // 0x800FEEB0: sb          $zero, 0x34($s0)
    MEM_B(0X34, ctx->r16) = 0;
L_800FEEB4:
    // 0x800FEEB4: jal         0x800C2FDC
    // 0x800FEEB8: nop

    func_800C2FDC(rdram, ctx);
        goto after_4;
    // 0x800FEEB8: nop

    after_4:
    // 0x800FEEBC: sb          $zero, 0x34($s0)
    MEM_B(0X34, ctx->r16) = 0;
L_800FEEC0:
    // 0x800FEEC0: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
L_800FEEC4:
    // 0x800FEEC4: beql        $t5, $zero, L_800FEF78
    if (ctx->r13 == 0) {
        // 0x800FEEC8: lw          $t3, 0x34($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X34);
            goto L_800FEF78;
    }
    goto skip_2;
    // 0x800FEEC8: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x800FEECC: jal         0x800C2E04
    // 0x800FEED0: nop

    func_800C2E04(rdram, ctx);
        goto after_5;
    // 0x800FEED0: nop

    after_5:
    // 0x800FEED4: sb          $v0, 0x34($s0)
    MEM_B(0X34, ctx->r16) = ctx->r2;
    // 0x800FEED8: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x800FEEDC: jal         0x800C330C
    // 0x800FEEE0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C330C(rdram, ctx);
        goto after_6;
    // 0x800FEEE0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x800FEEE4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800FEEE8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800FEEEC: addiu       $t9, $t9, 0x3E64
    ctx->r25 = ADD32(ctx->r25, 0X3E64);
    // 0x800FEEF0: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800FEEF4: addu        $v0, $t7, $t9
    ctx->r2 = ADD32(ctx->r15, ctx->r25);
    // 0x800FEEF8: lh          $a1, -0x8($v0)
    ctx->r5 = MEM_H(ctx->r2, -0X8);
    // 0x800FEEFC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800FEF00: jal         0x800C301C
    // 0x800FEF04: lbu         $a0, 0x34($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X34);
    func_800C301C(rdram, ctx);
        goto after_7;
    // 0x800FEF04: lbu         $a0, 0x34($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X34);
    after_7:
    // 0x800FEF08: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800FEF0C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800FEF10: lbu         $a0, 0x34($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X34);
    // 0x800FEF14: lh          $t8, -0x6($t0)
    ctx->r24 = MEM_H(ctx->r8, -0X6);
    // 0x800FEF18: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800FEF1C: nop

    // 0x800FEF20: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800FEF24: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800FEF28: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800FEF2C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800FEF30: jal         0x800C3058
    // 0x800FEF34: nop

    func_800C3058(rdram, ctx);
        goto after_8;
    // 0x800FEF34: nop

    after_8:
    // 0x800FEF38: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800FEF3C: lbu         $a0, 0x34($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X34);
    // 0x800FEF40: jal         0x800C31DC
    // 0x800FEF44: lw          $a1, -0x4($t2)
    ctx->r5 = MEM_W(ctx->r10, -0X4);
    func_800C31DC(rdram, ctx);
        goto after_9;
    // 0x800FEF44: lw          $a1, -0x4($t2)
    ctx->r5 = MEM_W(ctx->r10, -0X4);
    after_9:
    // 0x800FEF48: lbu         $a0, 0x34($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X34);
    // 0x800FEF4C: jal         0x800C36F4
    // 0x800FEF50: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    func_800C36F4(rdram, ctx);
        goto after_10;
    // 0x800FEF50: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_10:
    // 0x800FEF54: lbu         $a0, 0x34($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X34);
    // 0x800FEF58: jal         0x800C368C
    // 0x800FEF5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C368C(rdram, ctx);
        goto after_11;
    // 0x800FEF5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x800FEF60: lbu         $a0, 0x34($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X34);
    // 0x800FEF64: jal         0x800C33DC
    // 0x800FEF68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C33DC(rdram, ctx);
        goto after_12;
    // 0x800FEF68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x800FEF6C: jal         0x800C3BDC
    // 0x800FEF70: lbu         $a0, 0x34($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X34);
    func_800C3BDC(rdram, ctx);
        goto after_13;
    // 0x800FEF70: lbu         $a0, 0x34($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X34);
    after_13:
    // 0x800FEF74: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
L_800FEF78:
    // 0x800FEF78: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800FEF7C: sh          $t3, 0x36($t4)
    MEM_H(0X36, ctx->r12) = ctx->r11;
    // 0x800FEF80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800FEF84:
    // 0x800FEF84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FEF88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800FEF8C: jr          $ra
    // 0x800FEF90: nop

    return;
    // 0x800FEF90: nop

;}
RECOMP_FUNC void func_80800204_chhotwaterpoolbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800204: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800208: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080020C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800210: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1268, 0XA50) << 16);
    // 0x80800214: addiu       $a1, $a1, 0xA50
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1268, 0XA50));
    // 0x80800218: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8080021C: jal         0x800F2E60
    // 0x80800220: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800F2E60(rdram, ctx);
        goto after_0;
    // 0x80800220: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
    // 0x80800224: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800228: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8080022C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800230: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800234: swc1        $f4, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->f4.u32l;
    // 0x80800238: swc1        $f6, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f6.u32l;
    // 0x8080023C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800240: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800244: jr          $ra
    // 0x80800248: nop

    return;
    // 0x80800248: nop

;}
RECOMP_FUNC void _chswitch_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800857F0: syscall     176
    recomp_syscall_handler(rdram, ctx, 0x800857F0);
    return;
    // 0x800857F4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void chdiggerfly_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(864, 0XF8) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xF8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(864, 0XF8));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xF8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(864, 0XF8));
;}
RECOMP_FUNC void sucoasterfly_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080219C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808021A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808021A4: jal         0x80100094
    // 0x808021A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808021A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808021AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808021B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808021B4: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x808021B8: jr          $ra
    // 0x808021BC: nop

    return;
    // 0x808021BC: nop

;}
RECOMP_FUNC void subaddiefade_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080005C: lbu         $t7, 0x79($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X79);
    // 0x80800060: ori         $t8, $t7, 0x3
    ctx->r24 = ctx->r15 | 0X3;
    // 0x80800064: jr          $ra
    // 0x80800068: sb          $t8, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r24;
    return;
    // 0x80800068: sb          $t8, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r24;
;}
