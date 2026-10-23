#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808005F8_chstarspinnerstar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808005FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800600: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800604: jal         0x801015D0
    // 0x80800608: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_801015D0(rdram, ctx);
        goto after_0;
    // 0x80800608: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080060C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800610: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80800614: jal         0x800D731C
    // 0x80800618: lhu         $a0, 0x14($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X14);
    func_800D731C(rdram, ctx);
        goto after_1;
    // 0x80800618: lhu         $a0, 0x14($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X14);
    after_1:
    // 0x8080061C: beq         $v0, $zero, L_80800650
    if (ctx->r2 == 0) {
        // 0x80800620: sb          $v0, 0x1F($sp)
        MEM_B(0X1F, ctx->r29) = ctx->r2;
            goto L_80800650;
    }
    // 0x80800620: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    // 0x80800624: jal         0x800DA298
    // 0x80800628: addiu       $a0, $zero, 0xEA
    ctx->r4 = ADD32(0, 0XEA);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800628: addiu       $a0, $zero, 0xEA
    ctx->r4 = ADD32(0, 0XEA);
    after_2:
    // 0x8080062C: bnel        $v0, $zero, L_80800654
    if (ctx->r2 != 0) {
        // 0x80800630: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800654;
    }
    goto skip_0;
    // 0x80800630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800634: jal         0x80088848
    // 0x80800638: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x80800638: nop

    after_3:
    // 0x8080063C: bne         $v0, $zero, L_80800650
    if (ctx->r2 != 0) {
        // 0x80800640: lbu         $a0, 0x1F($sp)
        ctx->r4 = MEM_BU(ctx->r29, 0X1F);
            goto L_80800650;
    }
    // 0x80800640: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    // 0x80800644: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800648: jal         0x800DBE60
    // 0x8080064C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800DBE60(rdram, ctx);
        goto after_4;
    // 0x8080064C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
L_80800650:
    // 0x80800650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800654:
    // 0x80800654: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800658: jr          $ra
    // 0x8080065C: nop

    return;
    // 0x8080065C: nop

;}
RECOMP_FUNC void _chnastycavemen_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085AF8: syscall     193
    recomp_syscall_handler(rdram, ctx, 0x80085AF8);
    return;
    // 0x80085AFC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bsdronebitten_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080008C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800090: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800094: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800098: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080009C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808000A0: jal         0x80084660
    // 0x808000A4: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    _badata_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808000A4: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000AC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808000B0: jal         0x8008CB3C
    // 0x808000B4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x808000B4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x808000B8: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x808000BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808000CC: jal         0x8009FFD8
    // 0x808000D0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x808000D0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D8: jal         0x8009BA58
    // 0x808000DC: lui         $a1, 0x4461
    ctx->r5 = S32(0X4461 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_3;
    // 0x808000DC: lui         $a1, 0x4461
    ctx->r5 = S32(0X4461 << 16);
    after_3:
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E4: jal         0x8009BCB4
    // 0x808000E8: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_4;
    // 0x808000E8: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    after_4:
    // 0x808000EC: jal         0x8009EFA8
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_pushZone(rdram, ctx);
        goto after_5;
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000F4: lui         $a2, 0x3DF5
    ctx->r6 = S32(0X3DF5 << 16);
    // 0x808000F8: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800100: jal         0x8009F1C8
    // 0x80800104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_6;
    // 0x80800104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800110: jal         0x8009F1C8
    // 0x80800114: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_7;
    // 0x80800114: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_7:
    // 0x80800118: jal         0x8008E944
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_8;
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800120: jal         0x8009D9D4
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D9D4(rdram, ctx);
        goto after_9;
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800128: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080012C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800130: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800134: jr          $ra
    // 0x80800138: nop

    return;
    // 0x80800138: nop

;}
RECOMP_FUNC void bavan_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800178: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8080017C: lw          $t6, 0x144($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X144);
    // 0x80800180: jr          $ra
    // 0x80800184: swc1        $f12, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x80800184: swc1        $f12, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80801A08_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801A0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801A10: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801A14: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80801A18: jal         0x800B53A4
    // 0x80801A1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x80801A1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80801A20: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(932, 0X2ACC) << 16);
    // 0x80801A24: addiu       $t6, $t6, 0x2ACC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(932, 0X2ACC));
    // 0x80801A28: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801A2C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801A30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801A34: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80801A38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801A3C: jal         0x800BABB8
    // 0x80801A40: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x80801A40: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80801A44: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(932, 0X2D68) << 16);
    // 0x80801A48: addiu       $t7, $t7, 0x2D68
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(932, 0X2D68));
    // 0x80801A4C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801A50: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80801A54: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80801A58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801A5C: jal         0x800BABB8
    // 0x80801A60: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80801A60: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x80801A64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801A6C: jr          $ra
    // 0x80801A70: nop

    return;
    // 0x80801A70: nop

;}
RECOMP_FUNC void ncpodfixpos_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000FC: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80800100: jal         0x8001B798
    // 0x80800104: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x80800104: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    after_0:
    // 0x80800108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080010C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800110: jr          $ra
    // 0x80800114: nop

    return;
    // 0x80800114: nop

;}
RECOMP_FUNC void func_808013C0_gcmapsects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013C0: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x808013C4: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x808013C8: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x808013CC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808013D0: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x808013D4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x808013D8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x808013DC: lw          $t9, 0x4C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4C);
    // 0x808013E0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808013E4: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x808013E8: sll         $t4, $t9, 1
    ctx->r12 = S32(ctx->r25 << 1);
    // 0x808013EC: bgez        $t4, L_80801444
    if (SIGNED(ctx->r12) >= 0) {
        // 0x808013F0: addiu       $t1, $zero, 0x58
        ctx->r9 = ADD32(0, 0X58);
            goto L_80801444;
    }
    // 0x808013F0: addiu       $t1, $zero, 0x58
    ctx->r9 = ADD32(0, 0X58);
    // 0x808013F4: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_808013F8:
    // 0x808013F8: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x808013FC: subu        $t5, $t5, $a1
    ctx->r13 = SUB32(ctx->r13, ctx->r5);
    // 0x80801400: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
    // 0x80801404: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80801408: subu        $t5, $t5, $a1
    ctx->r13 = SUB32(ctx->r13, ctx->r5);
    // 0x8080140C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80801410: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80801414: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80801418: lbu         $a2, 0x3C($t7)
    ctx->r6 = MEM_BU(ctx->r15, 0X3C);
    // 0x8080141C: beq         $t0, $a2, L_80801444
    if (ctx->r8 == ctx->r6) {
        // 0x80801420: nop
    
            goto L_80801444;
    }
    // 0x80801420: nop

    // 0x80801424: multu       $a2, $t1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80801428: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8080142C: mflo        $t8
    ctx->r24 = lo;
    // 0x80801430: addu        $a3, $v0, $t8
    ctx->r7 = ADD32(ctx->r2, ctx->r24);
    // 0x80801434: lbu         $t9, 0x4C($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X4C);
    // 0x80801438: andi        $t3, $t9, 0xFF7F
    ctx->r11 = ctx->r25 & 0XFF7F;
    // 0x8080143C: bne         $v1, $t2, L_808013F8
    if (ctx->r3 != ctx->r10) {
        // 0x80801440: sb          $t3, 0x4C($a3)
        MEM_B(0X4C, ctx->r7) = ctx->r11;
            goto L_808013F8;
    }
    // 0x80801440: sb          $t3, 0x4C($a3)
    MEM_B(0X4C, ctx->r7) = ctx->r11;
L_80801444:
    // 0x80801444: jr          $ra
    // 0x80801448: nop

    return;
    // 0x80801448: nop

;}
RECOMP_FUNC void func_808021E8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808021E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808021EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808021F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808021F4: jal         0x80100094
    // 0x808021F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808021F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808021FC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80802200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802204: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80802208: lbu         $t8, 0xFD($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XFD);
    // 0x8080220C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80802210: bne         $t8, $zero, L_80802220
    if (ctx->r24 != 0) {
        // 0x80802214: nop
    
            goto L_80802220;
    }
    // 0x80802214: nop

    // 0x80802218: b           L_80802220
    // 0x8080221C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802220;
    // 0x8080221C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802220:
    // 0x80802220: jr          $ra
    // 0x80802224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80802224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _gcdialogcamera_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800880B8: syscall     669
    recomp_syscall_handler(rdram, ctx, 0x800880B8);
    return;
    // 0x800880BC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80807DF4_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807DF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80807DF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80807DFC: jal         0x80100094
    // 0x80807E00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80807E00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80807E04: lbu         $v1, 0xA4($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XA4);
    // 0x80807E08: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80807E0C: sb          $zero, 0xA5($v0)
    MEM_B(0XA5, ctx->r2) = 0;
    // 0x80807E10: beq         $v1, $at, L_80807E2C
    if (ctx->r3 == ctx->r1) {
        // 0x80807E14: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80807E2C;
    }
    // 0x80807E14: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80807E18: beq         $v1, $at, L_80807E2C
    if (ctx->r3 == ctx->r1) {
        // 0x80807E1C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80807E2C;
    }
    // 0x80807E1C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80807E20: beq         $v1, $at, L_80807E2C
    if (ctx->r3 == ctx->r1) {
        // 0x80807E24: addiu       $t6, $zero, 0x4
        ctx->r14 = ADD32(0, 0X4);
            goto L_80807E2C;
    }
    // 0x80807E24: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80807E28: sb          $t6, 0xA4($v0)
    MEM_B(0XA4, ctx->r2) = ctx->r14;
L_80807E2C:
    // 0x80807E2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80807E30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80807E34: jr          $ra
    // 0x80807E38: nop

    return;
    // 0x80807E38: nop

;}
RECOMP_FUNC void func_800D3970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3970: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3978: jal         0x800D37D4
    // 0x800D397C: nop

    func_800D37D4(rdram, ctx);
        goto after_0;
    // 0x800D397C: nop

    after_0:
    // 0x800D3980: jal         0x800D3A14
    // 0x800D3984: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D3A14(rdram, ctx);
        goto after_1;
    // 0x800D3984: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800D3988: jal         0x800D3CF8
    // 0x800D398C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D3CF8(rdram, ctx);
        goto after_2;
    // 0x800D398C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x800D3990: jal         0x800D3D10
    // 0x800D3994: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D3D10(rdram, ctx);
        goto after_3;
    // 0x800D3994: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x800D3998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D399C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D39A0: jr          $ra
    // 0x800D39A4: nop

    return;
    // 0x800D39A4: nop

;}
RECOMP_FUNC void _gcnewpause_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088218: syscall     675
    recomp_syscall_handler(rdram, ctx, 0x80088218);
    return;
    // 0x8008821C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8009E9E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E9E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E9E8: jr          $ra
    // 0x8009E9EC: sb          $a0, 0x7078($at)
    MEM_B(0X7078, ctx->r1) = ctx->r4;
    return;
    // 0x8009E9EC: sb          $a0, 0x7078($at)
    MEM_B(0X7078, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_8010A698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A698: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8010A69C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8010A6A0: lw          $v0, 0x8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X8);
    // 0x8010A6A4: sll         $t8, $v0, 28
    ctx->r24 = S32(ctx->r2 << 28);
    // 0x8010A6A8: jr          $ra
    // 0x8010A6AC: srl         $v0, $t8, 31
    ctx->r2 = S32(U32(ctx->r24) >> 31);
    return;
    // 0x8010A6AC: srl         $v0, $t8, 31
    ctx->r2 = S32(U32(ctx->r24) >> 31);
;}
RECOMP_FUNC void bashoessuck_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800184: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800188: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080018C: jal         0x8009C128
    // 0x80800190: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800190: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800194: addiu       $a0, $zero, 0x16D
    ctx->r4 = ADD32(0, 0X16D);
    // 0x80800198: jal         0x80088280
    // 0x8080019C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _gccubesearch_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080019C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x808001A0: beq         $v0, $zero, L_808001B0
    if (ctx->r2 == 0) {
        // 0x808001A4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808001B0;
    }
    // 0x808001A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001A8: jal         0x80088C00
    // 0x808001AC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x808001AC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_808001B0:
    // 0x808001B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001B8: jr          $ra
    // 0x808001BC: nop

    return;
    // 0x808001BC: nop

;}
RECOMP_FUNC void func_8080047C_bscarry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080047C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800480: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800484: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800488: jal         0x8009EF10
    // 0x8080048C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    bastick_getZone(rdram, ctx);
        goto after_0;
    // 0x8080048C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800490: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800494: beq         $v0, $at, L_808004B0
    if (ctx->r2 == ctx->r1) {
        // 0x80800498: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_808004B0;
    }
    // 0x80800498: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080049C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808004A0: beql        $v0, $at, L_808004BC
    if (ctx->r2 == ctx->r1) {
        // 0x808004A4: addiu       $a1, $zero, 0x3B
        ctx->r5 = ADD32(0, 0X3B);
            goto L_808004BC;
    }
    goto skip_0;
    // 0x808004A4: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    skip_0:
    // 0x808004A8: b           L_808004C0
    // 0x808004AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
        goto L_808004C0;
    // 0x808004AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_808004B0:
    // 0x808004B0: b           L_808004BC
    // 0x808004B4: addiu       $a1, $zero, 0x9F
    ctx->r5 = ADD32(0, 0X9F);
        goto L_808004BC;
    // 0x808004B4: addiu       $a1, $zero, 0x9F
    ctx->r5 = ADD32(0, 0X9F);
    // 0x808004B8: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
L_808004BC:
    // 0x808004BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_808004C0:
    // 0x808004C0: jal         0x80084D40
    // 0x808004C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    _bahold_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x808004C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x808004C8: bne         $v0, $zero, L_808004D4
    if (ctx->r2 != 0) {
        // 0x808004CC: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_808004D4;
    }
    // 0x808004CC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808004D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_808004D4:
    // 0x808004D4: jal         0x8009E5C8
    // 0x808004D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x808004D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808004DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004E4: jr          $ra
    // 0x808004E8: nop

    return;
    // 0x808004E8: nop

;}
RECOMP_FUNC void func_800C54F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C54F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C54F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C54F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C54FC: jal         0x800A89A0
    // 0x800C5500: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    func_800A89A0(rdram, ctx);
        goto after_0;
    // 0x800C5500: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C5504: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800C5508: jal         0x800A8984
    // 0x800C550C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_800A8984(rdram, ctx);
        goto after_1;
    // 0x800C550C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x800C5510: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800C5514: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C5518: addiu       $a2, $a2, -0x5660
    ctx->r6 = ADD32(ctx->r6, -0X5660);
    // 0x800C551C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800C5520: addu        $v1, $a2, $t7
    ctx->r3 = ADD32(ctx->r6, ctx->r15);
    // 0x800C5524: lbu         $a0, 0xC($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XC);
    // 0x800C5528: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C552C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C5530: beq         $a0, $at, L_800C5548
    if (ctx->r4 == ctx->r1) {
        // 0x800C5534: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800C5548;
    }
    // 0x800C5534: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800C5538: beql        $a0, $at, L_800C5588
    if (ctx->r4 == ctx->r1) {
        // 0x800C553C: lw          $t3, 0x0($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X0);
            goto L_800C5588;
    }
    goto skip_0;
    // 0x800C553C: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x800C5540: b           L_800C55A4
    // 0x800C5544: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
        goto L_800C55A4;
    // 0x800C5544: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_800C5548:
    // 0x800C5548: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C554C: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x800C5550: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    // 0x800C5554: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800C5558: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800C555C: slt         $at, $t0, $a1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800C5560: bne         $at, $zero, L_800C55A0
    if (ctx->r1 != 0) {
        // 0x800C5564: sw          $t0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r8;
            goto L_800C55A0;
    }
    // 0x800C5564: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800C5568: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800C556C: sb          $t2, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r10;
    // 0x800C5570: jal         0x800C524C
    // 0x800C5574: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_800C524C(rdram, ctx);
        goto after_2;
    // 0x800C5574: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x800C5578: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C557C: b           L_800C55A0
    // 0x800C5580: addiu       $a2, $a2, -0x5660
    ctx->r6 = ADD32(ctx->r6, -0X5660);
        goto L_800C55A0;
    // 0x800C5580: addiu       $a2, $a2, -0x5660
    ctx->r6 = ADD32(ctx->r6, -0X5660);
    // 0x800C5584: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
L_800C5588:
    // 0x800C5588: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x800C558C: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x800C5590: bgez        $t5, L_800C55A0
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800C5594: sw          $t5, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r13;
            goto L_800C55A0;
    }
    // 0x800C5594: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800C5598: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800C559C: sb          $zero, 0xC($v1)
    MEM_B(0XC, ctx->r3) = 0;
L_800C55A0:
    // 0x800C55A0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_800C55A4:
    // 0x800C55A4: beql        $a0, $zero, L_800C564C
    if (ctx->r4 == 0) {
        // 0x800C55A8: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_800C564C;
    }
    goto skip_1;
    // 0x800C55A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_1:
    // 0x800C55AC: beql        $s0, $zero, L_800C564C
    if (ctx->r16 == 0) {
        // 0x800C55B0: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_800C564C;
    }
    goto skip_2;
    // 0x800C55B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_2:
    // 0x800C55B4: jal         0x80015CE8
    // 0x800C55B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80015CE8(rdram, ctx);
        goto after_3;
    // 0x800C55B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800C55BC: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800C55C0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C55C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C55C8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C55CC: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x800C55D0: jal         0x800CA6F0
    // 0x800C55D4: lw          $a1, -0x55FC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X55FC);
    func_800CA6F0(rdram, ctx);
        goto after_4;
    // 0x800C55D4: lw          $a1, -0x55FC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X55FC);
    after_4:
    // 0x800C55D8: jal         0x800A8AD4
    // 0x800C55DC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_800A8AD4(rdram, ctx);
        goto after_5;
    // 0x800C55DC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_5:
    // 0x800C55E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C55E4: jal         0x800CA6FC
    // 0x800C55E8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_800CA6FC(rdram, ctx);
        goto after_6;
    // 0x800C55E8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x800C55EC: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C55F0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C55F4: lwc1        $f4, -0x55E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X55E4);
    // 0x800C55F8: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C55FC: lwc1        $f8, -0x55E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X55E8);
    // 0x800C5600: add.s       $f12, $f2, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800C5604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C5608: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800C560C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800C5610: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x800C5614: jal         0x800CA558
    // 0x800C5618: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    func_800CA558(rdram, ctx);
        goto after_7;
    // 0x800C5618: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x800C561C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C5620: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C5624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C5628: div.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800C562C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800C5630: jal         0x800CA510
    // 0x800C5634: nop

    func_800CA510(rdram, ctx);
        goto after_8;
    // 0x800C5634: nop

    after_8:
    // 0x800C5638: jal         0x800CAF34
    // 0x800C563C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800CAF34(rdram, ctx);
        goto after_9;
    // 0x800C563C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800C5640: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C5644: addiu       $a2, $a2, -0x5660
    ctx->r6 = ADD32(ctx->r6, -0X5660);
    // 0x800C5648: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_800C564C:
    // 0x800C564C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C5650: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C5654: swc1        $f4, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->f4.u32l;
    // 0x800C5658: lwc1        $f6, 0x7C($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X7C);
    // 0x800C565C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800C5660: jr          $ra
    // 0x800C5664: swc1        $f6, 0x78($a2)
    MEM_W(0X78, ctx->r6) = ctx->f6.u32l;
    return;
    // 0x800C5664: swc1        $f6, 0x78($a2)
    MEM_W(0X78, ctx->r6) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_808035A8_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808035A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808035AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808035B0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808035B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808035B8: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x808035BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808035C0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x808035C4: jal         0x80101970
    // 0x808035C8: swc1        $f6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f6.u32l;
    func_80101970(rdram, ctx);
        goto after_0;
    // 0x808035C8: swc1        $f6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f6.u32l;
    after_0:
    // 0x808035CC: jal         0x800DF830
    // 0x808035D0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF830(rdram, ctx);
        goto after_1;
    // 0x808035D0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x808035D4: jal         0x800D674C
    // 0x808035D8: addiu       $a0, $zero, 0x69E
    ctx->r4 = ADD32(0, 0X69E);
    func_800D674C(rdram, ctx);
        goto after_2;
    // 0x808035D8: addiu       $a0, $zero, 0x69E
    ctx->r4 = ADD32(0, 0X69E);
    after_2:
    // 0x808035DC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x808035E0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x808035E4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808035E8: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x808035EC: jal         0x800DE448
    // 0x808035F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800DE448(rdram, ctx);
        goto after_3;
    // 0x808035F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x808035F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808035F8: jal         0x801018A4
    // 0x808035FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_801018A4(rdram, ctx);
        goto after_4;
    // 0x808035FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80803600: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80803604: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80803608: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x8080360C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80803610: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80803614: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80803618: jr          $ra
    // 0x8080361C: nop

    return;
    // 0x8080361C: nop

;}
RECOMP_FUNC void _bsdronexform_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800831C0: syscall     50
    recomp_syscall_handler(rdram, ctx, 0x800831C0);
    return;
    // 0x800831C4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _dbshift_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087970: syscall     642
    recomp_syscall_handler(rdram, ctx, 0x80087970);
    return;
    // 0x80087974: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bamum_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084F10: syscall     142
    recomp_syscall_handler(rdram, ctx, 0x80084F10);
    return;
    // 0x80084F14: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void changlerbossflare_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1336, 0X480) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x480
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1336, 0X480));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x480
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1336, 0X480));
;}
RECOMP_FUNC void func_808018BC_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808018C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808018C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808018C8: jal         0x80100094
    // 0x808018CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808018CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808018D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808018D4: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x808018D8: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x808018DC: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x808018E0: bgezl       $t8, L_80801900
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808018E4: lbu         $t2, 0x79($a0)
        ctx->r10 = MEM_BU(ctx->r4, 0X79);
            goto L_80801900;
    }
    goto skip_0;
    // 0x808018E4: lbu         $t2, 0x79($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X79);
    skip_0:
    // 0x808018E8: lbu         $t9, 0x79($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X79);
    // 0x808018EC: andi        $t0, $t9, 0xFF0F
    ctx->r8 = ctx->r25 & 0XFF0F;
    // 0x808018F0: ori         $t1, $t0, 0x40
    ctx->r9 = ctx->r8 | 0X40;
    // 0x808018F4: b           L_8080190C
    // 0x808018F8: sb          $t1, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r9;
        goto L_8080190C;
    // 0x808018F8: sb          $t1, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r9;
    // 0x808018FC: lbu         $t2, 0x79($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X79);
L_80801900:
    // 0x80801900: andi        $t3, $t2, 0xFF0F
    ctx->r11 = ctx->r10 & 0XFF0F;
    // 0x80801904: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x80801908: sb          $t4, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r12;
L_8080190C:
    // 0x8080190C: jal         0x808012B4
    // 0x80801910: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_1;
    // 0x80801910: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_1:
    // 0x80801914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801918: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080191C: jr          $ra
    // 0x80801920: nop

    return;
    // 0x80801920: nop

;}
RECOMP_FUNC void func_800EF410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF410: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EF414: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EF418: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EF41C: lwc1        $f12, 0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EF420: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EF424: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800EF428: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800EF42C: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800EF430: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EF434: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800EF438: add.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800EF43C: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    // 0x800EF440: nop

    // 0x800EF444: bc1t        L_800EF484
    if (c1cs) {
        // 0x800EF448: nop
    
            goto L_800EF484;
    }
    // 0x800EF448: nop

    // 0x800EF44C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x800EF450: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800EF454: jal         0x8002DCA0
    // 0x800EF458: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800EF458: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800EF45C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800EF460: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800EF464: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800EF468: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800EF46C: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800EF470: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800EF474: jal         0x800EFA20
    // 0x800EF478: nop

    func_800EFA20(rdram, ctx);
        goto after_1;
    // 0x800EF478: nop

    after_1:
    // 0x800EF47C: b           L_800EF490
    // 0x800EF480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800EF490;
    // 0x800EF480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EF484:
    // 0x800EF484: jal         0x800EE7F8
    // 0x800EF488: nop

    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x800EF488: nop

    after_2:
    // 0x800EF48C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EF490:
    // 0x800EF490: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EF494: jr          $ra
    // 0x800EF498: nop

    return;
    // 0x800EF498: nop

;}
RECOMP_FUNC void boot_osSetThreadPri(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80092B04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092B04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80092B08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80092B0C: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80092B10: addiu       $at, $zero, 0x607
    ctx->r1 = ADD32(0, 0X607);
    // 0x80092B14: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80092B18: lh          $a3, 0xC($t6)
    ctx->r7 = MEM_H(ctx->r14, 0XC);
    // 0x80092B1C: bnel        $a3, $at, L_80092B38
    if (ctx->r7 != ctx->r1) {
        // 0x80092B20: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80092B38;
    }
    goto skip_0;
    // 0x80092B20: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_0:
    // 0x80092B24: jal         0x80093F7C
    // 0x80092B28: nop

    func_80093F7C(rdram, ctx);
        goto after_0;
    // 0x80092B28: nop

    after_0:
    // 0x80092B2C: b           L_80092B74
    // 0x80092B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80092B74;
    // 0x80092B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80092B34: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80092B38:
    // 0x80092B38: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80092B3C: jal         0x800D674C
    // 0x80092B40: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x80092B40: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x80092B44: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80092B48: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80092B4C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80092B50: bnel        $a1, $zero, L_80092B70
    if (ctx->r5 != 0) {
        // 0x80092B54: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80092B70;
    }
    goto skip_1;
    // 0x80092B54: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_1:
    // 0x80092B58: lw          $t7, 0x50($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X50);
    // 0x80092B5C: lh          $a0, 0xC($t7)
    ctx->r4 = MEM_H(ctx->r15, 0XC);
    // 0x80092B60: jal         0x800D62E4
    // 0x80092B64: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800D62E4(rdram, ctx);
        goto after_2;
    // 0x80092B64: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80092B68: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80092B6C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80092B70:
    // 0x80092B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80092B74:
    // 0x80092B74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80092B78: jr          $ra
    // 0x80092B7C: nop

    return;
    // 0x80092B7C: nop

;}
RECOMP_FUNC void _chinflatablebossdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086720: syscall     361
    recomp_syscall_handler(rdram, ctx, 0x80086720);
    return;
    // 0x80086724: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80805644_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805644: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80805648: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8080564C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80805650: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80805654: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80805658: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8080565C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80805660: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x80805664: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80805668: lwc1        $f18, 0x60($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8080566C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA484) << 16);
    // 0x80805670: lwc1        $f6, -0x5B7C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA484));
    // 0x80805674: div.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80805678: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8080567C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80805680: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80805684: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80805688: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080568C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80805690: div.s       $f22, $f8, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80805694: jal         0x80013A5C
    // 0x80805698: sub.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f14.fl;
    func_80013A5C(rdram, ctx);
        goto after_0;
    // 0x80805698: sub.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f14.fl;
    after_0:
    // 0x8080569C: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x808056A0: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x808056A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808056A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808056AC: div.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808056B0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808056B4: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x808056B8: jal         0x80013A5C
    // 0x808056BC: sub.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f2.fl;
    func_80013A5C(rdram, ctx);
        goto after_1;
    // 0x808056BC: sub.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f2.fl;
    after_1:
    // 0x808056C0: sub.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x808056C4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x808056C8: c.lt.s      $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f22.fl < ctx->f18.fl;
    // 0x808056CC: nop

    // 0x808056D0: bc1fl       L_808056E0
    if (!c1cs) {
        // 0x808056D4: sub.s       $f4, $f14, $f20
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f20.fl;
            goto L_808056E0;
    }
    goto skip_0;
    // 0x808056D4: sub.s       $f4, $f14, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f20.fl;
    skip_0:
    // 0x808056D8: add.s       $f14, $f20, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x808056DC: sub.s       $f4, $f14, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f20.fl;
L_808056E0:
    // 0x808056E0: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA488) << 16);
    // 0x808056E4: lwc1        $f6, -0x5B78($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA488));
    // 0x808056E8: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x808056EC: sub.s       $f22, $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f4.fl;
    // 0x808056F0: c.lt.s      $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f22.fl < ctx->f6.fl;
    // 0x808056F4: nop

    // 0x808056F8: bc1f        L_80805708
    if (!c1cs) {
        // 0x808056FC: nop
    
            goto L_80805708;
    }
    // 0x808056FC: nop

    // 0x80805700: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80805704: nop

L_80805708:
    // 0x80805708: jal         0x800137D4
    // 0x8080570C: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    func_800137D4(rdram, ctx);
        goto after_2;
    // 0x8080570C: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x80805710: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80805714: jal         0x8001395C
    // 0x80805718: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_8001395C(rdram, ctx);
        goto after_3;
    // 0x80805718: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_3:
    // 0x8080571C: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80805720: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80805724: sub.s       $f18, $f20, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x80805728: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA48C) << 16);
    // 0x8080572C: lwc1        $f4, -0x5B74($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA48C));
    // 0x80805730: sub.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x80805734: sub.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80805738: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x8080573C: nop

    // 0x80805740: bc1f        L_80805750
    if (!c1cs) {
        // 0x80805744: nop
    
            goto L_80805750;
    }
    // 0x80805744: nop

    // 0x80805748: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8080574C: nop

L_80805750:
    // 0x80805750: jal         0x80013788
    // 0x80805754: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    func_80013788(rdram, ctx);
        goto after_4;
    // 0x80805754: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    after_4:
    // 0x80805758: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080575C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80805760: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA490) << 16);
    // 0x80805764: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80805768: lwc1        $f8, -0x5B70($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA490));
    // 0x8080576C: sub.s       $f14, $f6, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80805770: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80805774: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80805778: sub.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x8080577C: mul.s       $f18, $f2, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x80805780: c.lt.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl < ctx->f14.fl;
    // 0x80805784: nop

    // 0x80805788: bc1fl       L_80805798
    if (!c1cs) {
        // 0x8080578C: lwc1        $f16, 0x60($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
            goto L_80805798;
    }
    goto skip_1;
    // 0x8080578C: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    skip_1:
    // 0x80805790: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    // 0x80805794: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
L_80805798:
    // 0x80805798: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8080579C: mul.s       $f4, $f16, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x808057A0: swc1        $f18, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f18.u32l;
    // 0x808057A4: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x808057A8: mul.s       $f6, $f2, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x808057AC: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x808057B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808057B4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x808057B8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808057BC: mul.s       $f0, $f6, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x808057C0: jr          $ra
    // 0x808057C4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x808057C4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800E6A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E6A10: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800E6A14: beql        $t6, $zero, L_800E6A30
    if (ctx->r14 == 0) {
        // 0x800E6A18: lbu         $v0, 0x0($a1)
        ctx->r2 = MEM_BU(ctx->r5, 0X0);
            goto L_800E6A30;
    }
    goto skip_0;
    // 0x800E6A18: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    skip_0:
    // 0x800E6A1C: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
L_800E6A20:
    // 0x800E6A20: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800E6A24: bnel        $t7, $zero, L_800E6A20
    if (ctx->r15 != 0) {
        // 0x800E6A28: lbu         $t7, 0x1($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X1);
            goto L_800E6A20;
    }
    goto skip_1;
    // 0x800E6A28: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
    skip_1:
    // 0x800E6A2C: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
L_800E6A30:
    // 0x800E6A30: beq         $v0, $zero, L_800E6A50
    if (ctx->r2 == 0) {
        // 0x800E6A34: nop
    
            goto L_800E6A50;
    }
    // 0x800E6A34: nop

    // 0x800E6A38: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_800E6A3C:
    // 0x800E6A3C: lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1);
    // 0x800E6A40: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800E6A44: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800E6A48: bnel        $v0, $zero, L_800E6A3C
    if (ctx->r2 != 0) {
        // 0x800E6A4C: sb          $v0, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r2;
            goto L_800E6A3C;
    }
    goto skip_2;
    // 0x800E6A4C: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    skip_2:
L_800E6A50:
    // 0x800E6A50: jr          $ra
    // 0x800E6A54: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    return;
    // 0x800E6A54: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
;}
RECOMP_FUNC void _badata_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800846F0: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x800846F0);
    return;
    // 0x800846F4: addi        $t0, $zero, 0x58
    ctx->r8 = ADD32(0, 0X58);
;}
RECOMP_FUNC void func_8010FD88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010FD88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010FD8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010FD90: jal         0x8010FD08
    // 0x8010FD94: nop

    func_8010FD08(rdram, ctx);
        goto after_0;
    // 0x8010FD94: nop

    after_0:
    // 0x8010FD98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010FD9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010FDA0: jr          $ra
    // 0x8010FDA4: nop

    return;
    // 0x8010FDA4: nop

;}
RECOMP_FUNC void bsbeemain_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800B14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B18: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800B1C: jal         0x80082840
    // 0x80800B20: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsbee_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800B20: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800B24: jal         0x80084600
    // 0x80800B28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _babounce_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800B28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800B2C: beq         $v0, $zero, L_80800B38
    if (ctx->r2 == 0) {
        // 0x80800B30: addiu       $t6, $zero, 0x85
        ctx->r14 = ADD32(0, 0X85);
            goto L_80800B38;
    }
    // 0x80800B30: addiu       $t6, $zero, 0x85
    ctx->r14 = ADD32(0, 0X85);
    // 0x80800B34: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80800B38:
    // 0x80800B38: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800B3C: jal         0x8009E5C8
    // 0x80800B40: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80800B40: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800B44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B4C: jr          $ra
    // 0x80800B50: nop

    return;
    // 0x80800B50: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082BF8: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082BF8);
    return;
    // 0x80082BFC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80805058_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805058: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080505C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80805060: jal         0x80082FE0
    // 0x80805064: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80805064: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80805068: jal         0x80807BB8
    // 0x8080506C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80807BB8_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x8080506C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80805070: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x80805074: ori         $a3, $a3, 0xEBEE
    ctx->r7 = ctx->r7 | 0XEBEE;
    // 0x80805078: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080507C: addiu       $a1, $zero, 0x30D
    ctx->r5 = ADD32(0, 0X30D);
    // 0x80805080: jal         0x8008CC34
    // 0x80805084: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baanim_playForDuration_loopStartingAt(rdram, ctx);
        goto after_2;
    // 0x80805084: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_2:
    // 0x80805088: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x8080508C: ori         $a3, $a3, 0xEBEE
    ctx->r7 = ctx->r7 | 0XEBEE;
    // 0x80805090: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80805094: addiu       $a1, $zero, 0x311
    ctx->r5 = ADD32(0, 0X311);
    // 0x80805098: jal         0x808002CC
    // 0x8080509C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    func_808002CC_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x8080509C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_3:
    // 0x808050A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808050A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808050A8: jr          $ra
    // 0x808050AC: nop

    return;
    // 0x808050AC: nop

;}
RECOMP_FUNC void func_80092BDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092BDC: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80092BE0: jr          $ra
    // 0x80092BE4: lwc1        $f0, 0x1C($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X1C);
    return;
    // 0x80092BE4: lwc1        $f0, 0x1C($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X1C);
;}
RECOMP_FUNC void _chbouncycastle_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085E98: syscall     255
    recomp_syscall_handler(rdram, ctx, 0x80085E98);
    return;
    // 0x80085E9C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808001BC_chhellterskeltermouth(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001CC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808001D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808001D4: jal         0x800EE7F8
    // 0x808001D8: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808001D8: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x808001DC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808001E0: jal         0x800EE7F8
    // 0x808001E4: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808001E4: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_1:
    // 0x808001E8: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x808001EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001F0: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808001F4: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    // 0x808001F8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808001FC: jal         0x800DA298
    // 0x80800200: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800200: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    after_2:
    // 0x80800204: beq         $v0, $zero, L_8080023C
    if (ctx->r2 == 0) {
        // 0x80800208: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080023C;
    }
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080020C: jal         0x8010A590
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_3;
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: jal         0x80102FE8
    // 0x8080021C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80102FE8(rdram, ctx);
        goto after_4;
    // 0x8080021C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800224: jal         0x80101FDC
    // 0x80800228: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80800228: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x8080022C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80800230: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800234: b           L_80800244
    // 0x80800238: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
        goto L_80800244;
    // 0x80800238: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_8080023C:
    // 0x8080023C: jal         0x80103110
    // 0x80800240: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_6;
    // 0x80800240: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_80800244:
    // 0x80800244: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800248: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080024C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800250: jr          $ra
    // 0x80800254: nop

    return;
    // 0x80800254: nop

;}
RECOMP_FUNC void bswalk_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800460: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800464: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800468: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080046C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800470: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800474: jal         0x8080016C
    // 0x80800478: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_8080016C_bswalk(rdram, ctx);
        goto after_0;
    // 0x80800478: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x8080047C: jal         0x8009EF04
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_1;
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800484: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800488: nop

    // 0x8080048C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800490: nop

    // 0x80800494: bc1fl       L_808004B4
    if (!c1cs) {
        // 0x80800498: lui         $a1, 0x3EF0
        ctx->r5 = S32(0X3EF0 << 16);
            goto L_808004B4;
    }
    goto skip_0;
    // 0x80800498: lui         $a1, 0x3EF0
    ctx->r5 = S32(0X3EF0 << 16);
    skip_0:
    // 0x8080049C: jal         0x8009C984
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_2;
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808004A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808004A8: jal         0x8009C914
    // 0x808004AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_3;
    // 0x808004AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808004B0: lui         $a1, 0x3EF0
    ctx->r5 = S32(0X3EF0 << 16);
L_808004B4:
    // 0x808004B4: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    // 0x808004B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004BC: jal         0x800A2CE8
    // 0x808004C0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2CE8(rdram, ctx);
        goto after_4;
    // 0x808004C0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x808004C4: lui         $a1, 0x3F78
    ctx->r5 = S32(0X3F78 << 16);
    // 0x808004C8: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D0: jal         0x800A2CE8
    // 0x808004D4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_5;
    // 0x808004D4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_5:
    // 0x808004D8: jal         0x80800000
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bswalk(rdram, ctx);
        goto after_6;
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808004E0: jal         0x8009EF10
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_7;
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808004E8: beq         $v0, $zero, L_80800510
    if (ctx->r2 == 0) {
        // 0x808004EC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800510;
    }
    // 0x808004EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808004F0: beq         $v0, $at, L_8080052C
    if (ctx->r2 == ctx->r1) {
        // 0x808004F4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080052C;
    }
    // 0x808004F4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808004F8: beq         $v0, $at, L_80800534
    if (ctx->r2 == ctx->r1) {
        // 0x808004FC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800534;
    }
    // 0x808004FC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800500: beql        $v0, $at, L_80800540
    if (ctx->r2 == ctx->r1) {
        // 0x80800504: addiu       $s1, $zero, 0x4
        ctx->r17 = ADD32(0, 0X4);
            goto L_80800540;
    }
    goto skip_1;
    // 0x80800504: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    skip_1:
    // 0x80800508: b           L_80800540
    // 0x8080050C: nop

        goto L_80800540;
    // 0x8080050C: nop

L_80800510:
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800514: jal         0x8009BCD4
    // 0x80800518: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_8;
    // 0x80800518: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_8:
    // 0x8080051C: beq         $v0, $zero, L_80800540
    if (ctx->r2 == 0) {
        // 0x80800520: nop
    
            goto L_80800540;
    }
    // 0x80800520: nop

    // 0x80800524: b           L_80800540
    // 0x80800528: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_80800540;
    // 0x80800528: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8080052C:
    // 0x8080052C: b           L_80800540
    // 0x80800530: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_80800540;
    // 0x80800530: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80800534:
    // 0x80800534: b           L_80800540
    // 0x80800538: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
        goto L_80800540;
    // 0x80800538: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x8080053C: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_80800540:
    // 0x80800540: jal         0x8008DE24
    // 0x80800544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DE24(rdram, ctx);
        goto after_9;
    // 0x80800544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800548: beq         $v0, $zero, L_80800554
    if (ctx->r2 == 0) {
        // 0x8080054C: nop
    
            goto L_80800554;
    }
    // 0x8080054C: nop

    // 0x80800550: addiu       $s1, $zero, 0x7A
    ctx->r17 = ADD32(0, 0X7A);
L_80800554:
    // 0x80800554: jal         0x80097AD0
    // 0x80800558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_10;
    // 0x80800558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080055C: beq         $v0, $zero, L_80800570
    if (ctx->r2 == 0) {
        // 0x80800560: nop
    
            goto L_80800570;
    }
    // 0x80800560: nop

    // 0x80800564: jal         0x800848A8
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_24(rdram, ctx);
        goto after_11;
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080056C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80800570:
    // 0x80800570: jal         0x8008DD04
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_12;
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800578: beq         $v0, $zero, L_80800584
    if (ctx->r2 == 0) {
        // 0x8080057C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800584;
    }
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800580: addiu       $s1, $zero, 0x2F
    ctx->r17 = ADD32(0, 0X2F);
L_80800584:
    // 0x80800584: jal         0x800919F4
    // 0x80800588: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_13;
    // 0x80800588: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x8080058C: beq         $v0, $zero, L_80800598
    if (ctx->r2 == 0) {
        // 0x80800590: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800598;
    }
    // 0x80800590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800594: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
L_80800598:
    // 0x80800598: jal         0x80800248
    // 0x8080059C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800248_bswalk(rdram, ctx);
        goto after_14;
    // 0x8080059C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_14:
    // 0x808005A0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808005A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A8: jal         0x80091A58
    // 0x808005AC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_15;
    // 0x808005AC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_15:
    // 0x808005B0: beq         $v0, $zero, L_8080061C
    if (ctx->r2 == 0) {
        // 0x808005B4: nop
    
            goto L_8080061C;
    }
    // 0x808005B4: nop

    // 0x808005B8: jal         0x8009FE84
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getTypeOfJump(rdram, ctx);
        goto after_16;
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808005C0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808005C4: jal         0x8009BB00
    // 0x808005C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_17;
    // 0x808005C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808005CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808005D0: nop

    // 0x808005D4: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x808005D8: nop

    // 0x808005DC: bc1f        L_8080061C
    if (!c1cs) {
        // 0x808005E0: nop
    
            goto L_8080061C;
    }
    // 0x808005E0: nop

    // 0x808005E4: jal         0x8008D714
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D714(rdram, ctx);
        goto after_18;
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808005EC: beq         $v0, $zero, L_808005FC
    if (ctx->r2 == 0) {
        // 0x808005F0: nop
    
            goto L_808005FC;
    }
    // 0x808005F0: nop

    // 0x808005F4: b           L_8080061C
    // 0x808005F8: addiu       $s1, $zero, 0xB8
    ctx->r17 = ADD32(0, 0XB8);
        goto L_8080061C;
    // 0x808005F8: addiu       $s1, $zero, 0xB8
    ctx->r17 = ADD32(0, 0XB8);
L_808005FC:
    // 0x808005FC: jal         0x8008D790
    // 0x80800600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D790(rdram, ctx);
        goto after_19;
    // 0x80800600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800604: beq         $v0, $zero, L_8080061C
    if (ctx->r2 == 0) {
        // 0x80800608: nop
    
            goto L_8080061C;
    }
    // 0x80800608: nop

    // 0x8080060C: jal         0x80084978
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baduo_entrypoint_12(rdram, ctx);
        goto after_20;
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800614: b           L_80800664
    // 0x80800618: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800664;
    // 0x80800618: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080061C:
    // 0x8080061C: jal         0x8008E148
    // 0x80800620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_21;
    // 0x80800620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800624: beq         $v0, $zero, L_80800638
    if (ctx->r2 == 0) {
        // 0x80800628: nop
    
            goto L_80800638;
    }
    // 0x80800628: nop

    // 0x8080062C: jal         0x800848B0
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_22;
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800634: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80800638:
    // 0x80800638: jal         0x8008E35C
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_23;
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800640: beq         $v0, $zero, L_8080064C
    if (ctx->r2 == 0) {
        // 0x80800644: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080064C;
    }
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800648: addiu       $s1, $zero, 0x2D
    ctx->r17 = ADD32(0, 0X2D);
L_8080064C:
    // 0x8080064C: jal         0x800A02DC
    // 0x80800650: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800A02DC(rdram, ctx);
        goto after_24;
    // 0x80800650: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_24:
    // 0x80800654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800658: jal         0x8009E5C8
    // 0x8080065C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_25;
    // 0x8080065C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_25:
    // 0x80800660: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800664:
    // 0x80800664: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800668: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080066C: jr          $ra
    // 0x80800670: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800670: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800134C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800134C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800134C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800134CC: jal         0x80012530
    // 0x800134D0: nop

    func_80012530(rdram, ctx);
        goto after_0;
    // 0x800134D0: nop

    after_0:
    // 0x800134D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800134D8: bne         $v0, $at, L_800134F0
    if (ctx->r2 != ctx->r1) {
        // 0x800134DC: lui         $a0, 0x8007
        ctx->r4 = S32(0X8007 << 16);
            goto L_800134F0;
    }
    // 0x800134DC: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800134E0: addiu       $a0, $a0, 0x6A00
    ctx->r4 = ADD32(ctx->r4, 0X6A00);
    // 0x800134E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800134E8: jal         0x8002EAD0
    // 0x800134EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800134EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_800134F0:
    // 0x800134F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800134F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800134F8: jr          $ra
    // 0x800134FC: nop

    return;
    // 0x800134FC: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_39(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801470: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801474: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(376, 0X16C0) << 16);
    // 0x80801478: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080147C: jr          $ra
    // 0x80801480: lw          $v0, 0x16C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(376, 0X16C0));
    return;
    // 0x80801480: lw          $v0, 0x16C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(376, 0X16C0));
;}
RECOMP_FUNC void _bawobble_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085470: syscall     162
    recomp_syscall_handler(rdram, ctx, 0x80085470);
    return;
    // 0x80085474: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800A4AD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4AD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A4AD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A4AD8: jal         0x800A4CA8
    // 0x800A4ADC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A4CA8(rdram, ctx);
        goto after_0;
    // 0x800A4ADC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A4AE0: jal         0x800893C0
    // 0x800A4AE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _ncbaspline_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x800A4AE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800A4AE8: beq         $v0, $zero, L_800A4AF8
    if (ctx->r2 == 0) {
        // 0x800A4AEC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800A4AF8;
    }
    // 0x800A4AEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A4AF0: jal         0x800A3F14
    // 0x800A4AF4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800A3F14(rdram, ctx);
        goto after_2;
    // 0x800A4AF4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
L_800A4AF8:
    // 0x800A4AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A4AFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A4B00: jr          $ra
    // 0x800A4B04: nop

    return;
    // 0x800A4B04: nop

;}
RECOMP_FUNC void _baswim_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800852D8: syscall     156
    recomp_syscall_handler(rdram, ctx, 0x800852D8);
    return;
    // 0x800852DC: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void bainput_func_80097EC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097EC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80097ECC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097ED0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80097ED4: jal         0x80091A58
    // 0x80097ED8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x80097ED8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x80097EDC: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097EE0: beq         $t6, $zero, L_80097EF8
    if (ctx->r14 == 0) {
        // 0x80097EE4: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80097EF8;
    }
    // 0x80097EE4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80097EE8: jal         0x8008D568
    // 0x80097EEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008D568(rdram, ctx);
        goto after_1;
    // 0x80097EEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80097EF0: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097EF4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80097EF8:
    // 0x80097EF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097EFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80097F00: jr          $ra
    // 0x80097F04: nop

    return;
    // 0x80097F04: nop

;}
RECOMP_FUNC void func_8009DF94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_sound_log(rdram, ctx, 1);
    // 0x8009DF94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009DF98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009DF9C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8009DFA0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8009DFA4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8009DFA8: lw          $t6, 0x104($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X104);
    // 0x8009DFAC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8009DFB0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8009DFB4: lbu         $a1, 0x3($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X3);
    // 0x8009DFB8: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8009DFBC: jal         0x8009DCCC
    // 0x8009DFC0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_8009DCCC(rdram, ctx);
        goto after_0;
    // 0x8009DFC0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x8009DFC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009DFC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009DFCC: jr          $ra
    // 0x8009DFD0: nop

    return;
    // 0x8009DFD0: nop

;}
RECOMP_FUNC void func_808000A8_chlavaexplodbuild(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000AC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808000B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B4: bne         $a1, $at, L_80800120
    if (ctx->r5 != ctx->r1) {
        // 0x808000B8: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800120;
    }
    // 0x808000B8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808000BC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x808000C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808000C4: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x808000C8: jal         0x80086670
    // 0x808000CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808000CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000D0: jal         0x80800138
    // 0x808000D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800138_chlavaexplodbuild(rdram, ctx);
        goto after_1;
    // 0x808000D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808000D8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2068, 0X290) << 16);
    // 0x808000DC: addiu       $a1, $a1, 0x290
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2068, 0X290));
    // 0x808000E0: jal         0x800C4AF0
    // 0x808000E4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800C4AF0(rdram, ctx);
        goto after_2;
    // 0x808000E4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x808000E8: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x808000EC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808000F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808000F4: jal         0x800E15CC
    // 0x808000F8: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    func_800E15CC(rdram, ctx);
        goto after_3;
    // 0x808000F8: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    after_3:
    // 0x808000FC: lui         $a2, 0x3EE6
    ctx->r6 = S32(0X3EE6 << 16);
    // 0x80800100: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800104: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800108: jal         0x80018820
    // 0x8080010C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    func_80018820(rdram, ctx);
        goto after_4;
    // 0x8080010C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_4:
    // 0x80800110: jal         0x800DA544
    // 0x80800114: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x80800114: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    after_5:
    // 0x80800118: b           L_80800128
    // 0x8080011C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800128;
    // 0x8080011C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800120:
    // 0x80800120: b           L_80800128
    // 0x80800124: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800128;
    // 0x80800124: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800128:
    // 0x80800128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080012C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800130: jr          $ra
    // 0x80800134: nop

    return;
    // 0x80800134: nop

;}
RECOMP_FUNC void susubgame_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080041C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800420: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800424: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80800428: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8080042C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80800430: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800434: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800438: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x8080043C: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x80800440: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800444: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800448: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080044C: bne         $s4, $zero, L_80800458
    if (ctx->r20 != 0) {
        // 0x80800450: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_80800458;
    }
    // 0x80800450: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800454: lw          $s4, 0x0($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X0);
L_80800458:
    // 0x80800458: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8080045C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800460: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800464: beq         $v0, $zero, L_8080048C
    if (ctx->r2 == 0) {
        // 0x80800468: nop
    
            goto L_8080048C;
    }
    // 0x80800468: nop

    // 0x8080046C: beq         $v0, $at, L_8080049C
    if (ctx->r2 == ctx->r1) {
        // 0x80800470: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080049C;
    }
    // 0x80800470: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800474: beq         $v0, $at, L_80800494
    if (ctx->r2 == ctx->r1) {
        // 0x80800478: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800494;
    }
    // 0x80800478: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080047C: beql        $v0, $at, L_80800498
    if (ctx->r2 == ctx->r1) {
        // 0x80800480: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800498;
    }
    goto skip_0;
    // 0x80800480: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_0:
    // 0x80800484: b           L_808004E8
    // 0x80800488: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_808004E8;
    // 0x80800488: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8080048C:
    // 0x8080048C: jal         0x80800814
    // 0x80800490: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_80800814_susubgame(rdram, ctx);
        goto after_0;
    // 0x80800490: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_0:
L_80800494:
    // 0x80800494: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_80800498:
    // 0x80800498: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
L_8080049C:
    // 0x8080049C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808004A0: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
L_808004A4:
    // 0x808004A4: jal         0x808008DC
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008DC_susubgame(rdram, ctx);
        goto after_1;
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808004AC: beq         $v0, $zero, L_808004D8
    if (ctx->r2 == 0) {
        // 0x808004B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004D8;
    }
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B4: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x808004B8: addu        $s1, $s6, $t7
    ctx->r17 = ADD32(ctx->r22, ctx->r15);
    // 0x808004BC: jal         0x800A93E4
    // 0x808004C0: ori         $s2, $s5, 0x800
    ctx->r18 = ctx->r21 | 0X800;
    func_800A93E4(rdram, ctx);
        goto after_2;
    // 0x808004C0: ori         $s2, $s5, 0x800
    ctx->r18 = ctx->r21 | 0X800;
    after_2:
    // 0x808004C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004C8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x808004CC: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x808004D0: jal         0x80089560
    // 0x808004D4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    _ncpod_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x808004D4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_3:
L_808004D8:
    // 0x808004D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808004DC: bne         $s0, $s3, L_808004A4
    if (ctx->r16 != ctx->r19) {
        // 0x808004E0: nop
    
            goto L_808004A4;
    }
    // 0x808004E0: nop

    // 0x808004E4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_808004E8:
    // 0x808004E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004EC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808004F0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808004F4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808004F8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808004FC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80800500: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80800504: jr          $ra
    // 0x80800508: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800508: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _gczoombox_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B88: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087B88);
    return;
    // 0x80087B8C: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void func_80800CF4_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CFC: jal         0x80800128
    // 0x80800D00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800128_bskazfly(rdram, ctx);
        goto after_0;
    // 0x80800D00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800D08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800D0C: jal         0x808009C8
    // 0x80800D10: sw          $zero, 0x160($a0)
    MEM_W(0X160, ctx->r4) = 0;
    func_808009C8_bskazfly(rdram, ctx);
        goto after_1;
    // 0x80800D10: sw          $zero, 0x160($a0)
    MEM_W(0X160, ctx->r4) = 0;
    after_1:
    // 0x80800D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D1C: jr          $ra
    // 0x80800D20: nop

    return;
    // 0x80800D20: nop

;}
RECOMP_FUNC void func_80800180_chstatictorch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800180: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800184: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800188: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080018C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800190: bne         $a1, $at, L_808001F8
    if (ctx->r5 != ctx->r1) {
        // 0x80800194: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_808001F8;
    }
    // 0x80800194: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800198: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080019C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x808001A0: jal         0x80089928
    // 0x808001A4: addiu       $a3, $zero, 0x9EB
    ctx->r7 = ADD32(0, 0X9EB);
    _suflamefx_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808001A4: addiu       $a3, $zero, 0x9EB
    ctx->r7 = ADD32(0, 0X9EB);
    after_0:
    // 0x808001A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808001AC: jal         0x80100094
    // 0x808001B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808001B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808001B4: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x808001B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1712, 0X220) << 16);
    // 0x808001C0: lwc1        $f6, 0x220($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1712, 0X220));
    // 0x808001C4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808001C8: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x808001CC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x808001D0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x808001D4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808001D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001DC: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x808001E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x808001E4: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x808001E8: jal         0x80089960
    // 0x808001EC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _suflamefx_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x808001EC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_2:
    // 0x808001F0: b           L_80800200
    // 0x808001F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800200;
    // 0x808001F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001F8:
    // 0x808001F8: b           L_80800200
    // 0x808001FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800200;
    // 0x808001FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800200:
    // 0x80800200: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800204: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800208: jr          $ra
    // 0x8080020C: nop

    return;
    // 0x8080020C: nop

;}
