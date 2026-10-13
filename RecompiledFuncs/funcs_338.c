#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808003F4_bskazpaddle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808003F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003FC: jal         0x8009FBB0
    // 0x80800400: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    func_8009FBB0(rdram, ctx);
        goto after_0;
    // 0x80800400: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_0:
    // 0x80800404: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x80800408: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8080040C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800410: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800414: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800418: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8080041C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800420: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800424: jal         0x800BA930
    // 0x80800428: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_800BA930(rdram, ctx);
        goto after_1;
    // 0x80800428: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_1:
    // 0x8080042C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800430: jal         0x800BA22C
    // 0x80800434: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_2;
    // 0x80800434: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800438: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080043C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800440: jr          $ra
    // 0x80800444: nop

    return;
    // 0x80800444: nop

;}
RECOMP_FUNC void _sccustom_big_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A910: syscall     856
    recomp_syscall_handler(rdram, ctx, 0x8008A910);
    return;
    // 0x8008A914: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _chflysaucercrate_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086C10: syscall     431
    recomp_syscall_handler(rdram, ctx, 0x80086C10);
    return;
    // 0x80086C14: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800458_chtoxicroombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800458: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080045C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800460: jal         0x808004F0
    // 0x80800464: nop

    func_808004F0_chtoxicroombits(rdram, ctx);
        goto after_0;
    // 0x80800464: nop

    after_0:
    // 0x80800468: beq         $v0, $zero, L_80800480
    if (ctx->r2 == 0) {
        // 0x8080046C: addiu       $v1, $zero, 0x6
        ctx->r3 = ADD32(0, 0X6);
            goto L_80800480;
    }
    // 0x8080046C: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x80800470: jal         0x808004F0
    // 0x80800474: nop

    func_808004F0_chtoxicroombits(rdram, ctx);
        goto after_1;
    // 0x80800474: nop

    after_1:
    // 0x80800478: b           L_80800480
    // 0x8080047C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80800480;
    // 0x8080047C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800480:
    // 0x80800480: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x80800484: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x80800488: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2308, 0X1005) << 16);
    // 0x8080048C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80800490: lbu         $t8, 0x1005($t8)
    ctx->r24 = MEM_BU(ctx->r24, (int16_t)RELOC_LO16(2308, 0X1005));
    // 0x80800494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800498: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080049C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x808004A0: bgez        $t8, L_808004B4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808004A4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808004B4;
    }
    // 0x808004A4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808004A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808004AC: nop

    // 0x808004B0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_808004B4:
    // 0x808004B4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808004B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808004BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004C0: jr          $ra
    // 0x808004C4: div.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    return;
    // 0x808004C4: div.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
;}
RECOMP_FUNC void _glintrosyncDll_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088600: syscall     695
    recomp_syscall_handler(rdram, ctx, 0x80088600);
    return;
    // 0x80088604: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80094340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094340: jr          $ra
    // 0x80094344: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80094344: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
;}
RECOMP_FUNC void ncbaspline_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000E8: jal         0x801124D0
    // 0x808000EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_801124D0(rdram, ctx);
        goto after_0;
    // 0x808000EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808000F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000F4: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x808000F8: jal         0x80111B8C
    // 0x808000FC: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    func_80111B8C(rdram, ctx);
        goto after_1;
    // 0x808000FC: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    after_1:
    // 0x80800100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800104: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800108: jr          $ra
    // 0x8080010C: nop

    return;
    // 0x8080010C: nop

;}
RECOMP_FUNC void func_800F9444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9444: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F9448: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800F944C: beq         $a0, $at, L_800F9460
    if (ctx->r4 == ctx->r1) {
        // 0x800F9450: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800F9460;
    }
    // 0x800F9450: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F9454: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F9458: bne         $a0, $at, L_800F9470
    if (ctx->r4 != ctx->r1) {
        // 0x800F945C: nop
    
            goto L_800F9470;
    }
    // 0x800F945C: nop

L_800F9460:
    // 0x800F9460: jal         0x800C964C
    // 0x800F9464: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_800C964C(rdram, ctx);
        goto after_0;
    // 0x800F9464: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_0:
    // 0x800F9468: b           L_800F947C
    // 0x800F946C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F947C;
    // 0x800F946C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9470:
    // 0x800F9470: jal         0x800C964C
    // 0x800F9474: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_800C964C(rdram, ctx);
        goto after_1;
    // 0x800F9474: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_1:
    // 0x800F9478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F947C:
    // 0x800F947C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F9480: jr          $ra
    // 0x800F9484: nop

    return;
    // 0x800F9484: nop

;}
RECOMP_FUNC void func_8080017C_chchompaslunch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080017C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800180: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800184: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800188: jal         0x801015D0
    // 0x8080018C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_801015D0(rdram, ctx);
        goto after_0;
    // 0x8080018C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800190: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    // 0x80800194: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1548, 0X428) << 16);
    // 0x80800198: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8080019C: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x808001A0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x808001A4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x808001A8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808001AC: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x808001B0: jal         0x800DF744
    // 0x808001B4: lh          $a1, 0x428($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1548, 0X428));
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x808001B4: lh          $a1, 0x428($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1548, 0X428));
    after_1:
    // 0x808001B8: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
    // 0x808001BC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1548, 0X42A) << 16);
    // 0x808001C0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x808001C4: andi        $t0, $t9, 0x1FF
    ctx->r8 = ctx->r25 & 0X1FF;
    // 0x808001C8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x808001CC: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x808001D0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x808001D4: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x808001D8: jal         0x800DF744
    // 0x808001DC: lh          $a1, 0x42A($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1548, 0X42A));
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x808001DC: lh          $a1, 0x42A($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1548, 0X42A));
    after_2:
    // 0x808001E0: lw          $t2, 0x6C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X6C);
    // 0x808001E4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1548, 0X42C) << 16);
    // 0x808001E8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x808001EC: andi        $t3, $t2, 0x1FF
    ctx->r11 = ctx->r10 & 0X1FF;
    // 0x808001F0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x808001F4: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x808001F8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x808001FC: addu        $a1, $a1, $t4
    ctx->r5 = ADD32(ctx->r5, ctx->r12);
    // 0x80800200: jal         0x800DF744
    // 0x80800204: lh          $a1, 0x42C($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1548, 0X42C));
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x80800204: lh          $a1, 0x42C($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1548, 0X42C));
    after_3:
    // 0x80800208: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8080020C: jal         0x800DF744
    // 0x80800210: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_4;
    // 0x80800210: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800214: lw          $t5, 0x6C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X6C);
    // 0x80800218: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1548, 0X42E) << 16);
    // 0x8080021C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80800220: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x80800224: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800228: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8080022C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800230: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x80800234: jal         0x800DF744
    // 0x80800238: lh          $a1, 0x42E($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1548, 0X42E));
    func_800DF744(rdram, ctx);
        goto after_5;
    // 0x80800238: lh          $a1, 0x42E($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1548, 0X42E));
    after_5:
    // 0x8080023C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800240: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800244: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800248: jr          $ra
    // 0x8080024C: nop

    return;
    // 0x8080024C: nop

;}
RECOMP_FUNC void func_80801770_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801770: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801778: jal         0x808001A8
    // 0x8080177C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808001A8_bswasher(rdram, ctx);
        goto after_0;
    // 0x8080177C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801780: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801784: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801788: jal         0x808015EC
    // 0x8080178C: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    func_808015EC_bswasher(rdram, ctx);
        goto after_1;
    // 0x8080178C: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    after_1:
    // 0x80801790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801794: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801798: jr          $ra
    // 0x8080179C: nop

    return;
    // 0x8080179C: nop

;}
RECOMP_FUNC void func_800E7DAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7DAC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E7DB0: addiu       $v0, $v0, -0x2A30
    ctx->r2 = ADD32(ctx->r2, -0X2A30);
    // 0x800E7DB4: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x800E7DB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E7DBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E7DC0: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x800E7DC4: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x800E7DC8: lh          $a3, 0x4($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X4);
    // 0x800E7DCC: jal         0x800E7A90
    // 0x800E7DD0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800E7A90(rdram, ctx);
        goto after_0;
    // 0x800E7DD0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x800E7DD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E7DD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E7DDC: jr          $ra
    // 0x800E7DE0: nop

    return;
    // 0x800E7DE0: nop

;}
RECOMP_FUNC void _basnowball_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800850D8: syscall     151
    recomp_syscall_handler(rdram, ctx, 0x800850D8);
    return;
    // 0x800850DC: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void _bskazjump_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083440: syscall     62
    recomp_syscall_handler(rdram, ctx, 0x80083440);
    return;
    // 0x80083444: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _bsbwhirl_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082DC8: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082DC8);
    return;
    // 0x80082DCC: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void _chcollballcontrol_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086EA8: syscall     467
    recomp_syscall_handler(rdram, ctx, 0x80086EA8);
    return;
    // 0x80086EAC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _gctransitionDll_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800881D8: syscall     674
    recomp_syscall_handler(rdram, ctx, 0x800881D8);
    return;
    // 0x800881DC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void gctransitionDll_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A44: lbu         $t6, 0x1D($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1D);
    // 0x80800A48: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800A4C: beq         $t6, $zero, L_80800A68
    if (ctx->r14 == 0) {
        // 0x80800A50: nop
    
            goto L_80800A68;
    }
    // 0x80800A50: nop

    // 0x80800A54: jal         0x800885F8
    // 0x80800A58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _glintrosyncDll_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800A58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800A5C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800A60: b           L_80800A78
    // 0x80800A64: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80800A78;
    // 0x80800A64: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80800A68:
    // 0x80800A68: jal         0x800D8FF8
    // 0x80800A6C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800A6C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800A70: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800A74: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80800A78:
    // 0x80800A78: lbu         $t7, 0x8($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X8);
    // 0x80800A7C: beql        $t7, $zero, L_80800C74
    if (ctx->r15 == 0) {
        // 0x80800A80: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800C74;
    }
    goto skip_0;
    // 0x80800A80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800A84: lw          $a0, 0x2C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X2C);
    // 0x80800A88: beql        $a0, $zero, L_80800B70
    if (ctx->r4 == 0) {
        // 0x80800A8C: lwc1        $f16, 0x28($a3)
        ctx->f16.u32l = MEM_W(ctx->r7, 0X28);
            goto L_80800B70;
    }
    goto skip_1;
    // 0x80800A8C: lwc1        $f16, 0x28($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X28);
    skip_1:
    // 0x80800A90: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80800A94: jal         0x8008ADE4
    // 0x80800A98: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_8008ADE4(rdram, ctx);
        goto after_2;
    // 0x80800A98: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x80800A9C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800AA0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800AA4: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800AA8: lbu         $t8, 0x1C($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X1C);
    // 0x80800AAC: bnel        $t8, $at, L_80800B30
    if (ctx->r24 != ctx->r1) {
        // 0x80800AB0: lw          $v0, 0x30($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X30);
            goto L_80800B30;
    }
    goto skip_2;
    // 0x80800AB0: lw          $v0, 0x30($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X30);
    skip_2:
    // 0x80800AB4: lw          $t9, 0x30($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X30);
    // 0x80800AB8: sltiu       $at, $t9, 0x5
    ctx->r1 = ctx->r25 < 0X5 ? 1 : 0;
    // 0x80800ABC: beq         $at, $zero, L_80800B1C
    if (ctx->r1 == 0) {
        // 0x80800AC0: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80800B1C;
    }
    // 0x80800AC0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800AC4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2654, 0XC94) << 16);
    // 0x80800AC8: addu        $at, $at, $t9
    gpr jr_addend_80800AD0 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800ACC: lw          $t9, 0xC94($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2654, 0XC94));
    // 0x80800AD0: jr          $t9
    // 0x80800AD4: nop

    switch (jr_addend_80800AD0 >> 2) {
        case 0: goto L_80800B78; break;
        case 1: goto L_80800AD8; break;
        case 2: goto L_80800AF4; break;
        case 3: goto L_80800B78; break;
        case 4: goto L_80800B08; break;
        default: switch_error(__func__, 0x80800AD0, 0x80800C94);
    }
    // 0x80800AD4: nop

L_80800AD8:
    // 0x80800AD8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800ADC: jal         0x80090684
    // 0x80800AE0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80090684(rdram, ctx);
        goto after_3;
    // 0x80800AE0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_3:
    // 0x80800AE4: jal         0x800EA334
    // 0x80800AE8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800EA334(rdram, ctx);
        goto after_4;
    // 0x80800AE8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80800AEC: b           L_80800B78
    // 0x80800AF0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
        goto L_80800B78;
    // 0x80800AF0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_80800AF4:
    // 0x80800AF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800AF8: jal         0x800EA34C
    // 0x80800AFC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800EA34C(rdram, ctx);
        goto after_5;
    // 0x80800AFC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_5:
    // 0x80800B00: b           L_80800B78
    // 0x80800B04: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
        goto L_80800B78;
    // 0x80800B04: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_80800B08:
    // 0x80800B08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800B0C: jal         0x8002FBB0
    // 0x80800B10: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    osViBlack_recomp(rdram, ctx);
        goto after_6;
    // 0x80800B10: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_6:
    // 0x80800B14: b           L_80800B78
    // 0x80800B18: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
        goto L_80800B78;
    // 0x80800B18: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_80800B1C:
    // 0x80800B1C: lwc1        $f4, 0x28($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X28);
    // 0x80800B20: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80800B24: b           L_80800B78
    // 0x80800B28: swc1        $f6, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f6.u32l;
        goto L_80800B78;
    // 0x80800B28: swc1        $f6, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f6.u32l;
    // 0x80800B2C: lw          $v0, 0x30($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X30);
L_80800B30:
    // 0x80800B30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800B34: beql        $v0, $zero, L_80800B7C
    if (ctx->r2 == 0) {
        // 0x80800B38: lwc1        $f0, 0xC($a3)
        ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
            goto L_80800B7C;
    }
    goto skip_3;
    // 0x80800B38: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
    skip_3:
    // 0x80800B3C: beq         $v0, $at, L_80800B78
    if (ctx->r2 == ctx->r1) {
        // 0x80800B40: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800B78;
    }
    // 0x80800B40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800B44: beq         $v0, $at, L_80800B5C
    if (ctx->r2 == ctx->r1) {
        // 0x80800B48: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800B5C;
    }
    // 0x80800B48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800B4C: lwc1        $f8, 0x28($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X28);
    // 0x80800B50: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80800B54: b           L_80800B78
    // 0x80800B58: swc1        $f10, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f10.u32l;
        goto L_80800B78;
    // 0x80800B58: swc1        $f10, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f10.u32l;
L_80800B5C:
    // 0x80800B5C: jal         0x800EA34C
    // 0x80800B60: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800EA34C(rdram, ctx);
        goto after_7;
    // 0x80800B60: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_7:
    // 0x80800B64: b           L_80800B78
    // 0x80800B68: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
        goto L_80800B78;
    // 0x80800B68: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800B6C: lwc1        $f16, 0x28($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X28);
L_80800B70:
    // 0x80800B70: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80800B74: swc1        $f18, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f18.u32l;
L_80800B78:
    // 0x80800B78: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
L_80800B7C:
    // 0x80800B7C: lwc1        $f4, 0x28($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X28);
    // 0x80800B80: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800B84: nop

    // 0x80800B88: bc1tl       L_80800BB4
    if (c1cs) {
        // 0x80800B8C: lbu         $v0, 0x1C($a3)
        ctx->r2 = MEM_BU(ctx->r7, 0X1C);
            goto L_80800BB4;
    }
    goto skip_4;
    // 0x80800B8C: lbu         $v0, 0x1C($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X1C);
    skip_4:
    // 0x80800B90: lw          $a0, 0x2C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X2C);
    // 0x80800B94: beql        $a0, $zero, L_80800C68
    if (ctx->r4 == 0) {
        // 0x80800B98: lw          $t1, 0x30($a3)
        ctx->r9 = MEM_W(ctx->r7, 0X30);
            goto L_80800C68;
    }
    goto skip_5;
    // 0x80800B98: lw          $t1, 0x30($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X30);
    skip_5:
    // 0x80800B9C: jal         0x8008B324
    // 0x80800BA0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    anctrl_isStopped(rdram, ctx);
        goto after_8;
    // 0x80800BA0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_8:
    // 0x80800BA4: beq         $v0, $zero, L_80800C64
    if (ctx->r2 == 0) {
        // 0x80800BA8: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_80800C64;
    }
    // 0x80800BA8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800BAC: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80800BB0: lbu         $v0, 0x1C($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X1C);
L_80800BB4:
    // 0x80800BB4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800BB8: swc1        $f0, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f0.u32l;
    // 0x80800BBC: beq         $v0, $at, L_80800BCC
    if (ctx->r2 == ctx->r1) {
        // 0x80800BC0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80800BCC;
    }
    // 0x80800BC0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800BC4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800BC8: bne         $v0, $at, L_80800C38
    if (ctx->r2 != ctx->r1) {
        // 0x80800BCC: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_80800C38;
    }
L_80800BCC:
    // 0x80800BCC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800BD0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800BD4: lwc1        $f6, 0x24($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X24);
    // 0x80800BD8: lui         $at, 0xC3B4
    ctx->r1 = S32(0XC3B4 << 16);
    // 0x80800BDC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800BE0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800BE4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800BE8: swc1        $f10, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f10.u32l;
    // 0x80800BEC: lwc1        $f0, 0x24($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X24);
    // 0x80800BF0: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80800BF4: nop

    // 0x80800BF8: bc1fl       L_80800C18
    if (!c1cs) {
        // 0x80800BFC: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_80800C18;
    }
    goto skip_6;
    // 0x80800BFC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_6:
    // 0x80800C00: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800C04: nop

    // 0x80800C08: add.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80800C0C: swc1        $f18, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f18.u32l;
    // 0x80800C10: lwc1        $f0, 0x24($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X24);
    // 0x80800C14: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_80800C18:
    // 0x80800C18: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800C1C: nop

    // 0x80800C20: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80800C24: nop

    // 0x80800C28: bc1fl       L_80800C3C
    if (!c1cs) {
        // 0x80800C2C: lbu         $a1, 0xA($a3)
        ctx->r5 = MEM_BU(ctx->r7, 0XA);
            goto L_80800C3C;
    }
    goto skip_7;
    // 0x80800C2C: lbu         $a1, 0xA($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0XA);
    skip_7:
    // 0x80800C30: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80800C34: swc1        $f4, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f4.u32l;
L_80800C38:
    // 0x80800C38: lbu         $a1, 0xA($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0XA);
L_80800C3C:
    // 0x80800C3C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80800C40: jal         0x808000D8
    // 0x80800C44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_808000D8_gctransitionDll(rdram, ctx);
        goto after_9;
    // 0x80800C44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x80800C48: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800C4C: lw          $t0, 0x2C($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X2C);
    // 0x80800C50: beql        $t0, $zero, L_80800C68
    if (ctx->r8 == 0) {
        // 0x80800C54: lw          $t1, 0x30($a3)
        ctx->r9 = MEM_W(ctx->r7, 0X30);
            goto L_80800C68;
    }
    goto skip_8;
    // 0x80800C54: lw          $t1, 0x30($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X30);
    skip_8:
    // 0x80800C58: jal         0x800EA170
    // 0x80800C5C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800EA170(rdram, ctx);
        goto after_10;
    // 0x80800C5C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_10:
    // 0x80800C60: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_80800C64:
    // 0x80800C64: lw          $t1, 0x30($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X30);
L_80800C68:
    // 0x80800C68: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80800C6C: sw          $t2, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r10;
    // 0x80800C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C74:
    // 0x80800C74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800C78: jr          $ra
    // 0x80800C7C: nop

    return;
    // 0x80800C7C: nop

;}
RECOMP_FUNC void bsbkflamethrower_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800418: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080041C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(100, 0X450) << 16);
    // 0x80800420: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800424: jr          $ra
    // 0x80800428: lw          $v0, 0x450($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(100, 0X450));
    return;
    // 0x80800428: lw          $v0, 0x450($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(100, 0X450));
    // 0x8080042C: nop

;}
RECOMP_FUNC void chweldarbossfireball_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1376, 0X410) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x410
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1376, 0X410));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x410
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1376, 0X410));
;}
RECOMP_FUNC void func_800F8B88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8B88: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F8B8C: jr          $ra
    // 0x800F8B90: lbu         $v0, 0x54F8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X54F8);
    return;
    // 0x800F8B90: lbu         $v0, 0x54F8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X54F8);
;}
RECOMP_FUNC void func_808007B8_chbounce(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007B8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808007BC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x808007C0: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x808007C4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808007C8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x808007CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808007D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007D4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x808007D8: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x808007DC: jal         0x80100094
    // 0x808007E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808007E4: lhu         $t6, 0x32($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X32);
    // 0x808007E8: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x808007EC: beq         $t7, $zero, L_80800868
    if (ctx->r15 == 0) {
        // 0x808007F0: nop
    
            goto L_80800868;
    }
    // 0x808007F0: nop

    // 0x808007F4: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
    // 0x808007F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808007FC: srl         $v1, $v0, 25
    ctx->r3 = S32(U32(ctx->r2) >> 25);
    // 0x80800800: beq         $v1, $zero, L_80800868
    if (ctx->r3 == 0) {
        // 0x80800804: addiu       $a1, $v1, -0x1
        ctx->r5 = ADD32(ctx->r3, -0X1);
            goto L_80800868;
    }
    // 0x80800804: addiu       $a1, $v1, -0x1
    ctx->r5 = ADD32(ctx->r3, -0X1);
    // 0x80800808: sll         $a2, $v0, 22
    ctx->r6 = S32(ctx->r2 << 22);
    // 0x8080080C: srl         $t8, $a2, 26
    ctx->r24 = S32(U32(ctx->r6) >> 26);
    // 0x80800810: jal         0x800CC338
    // 0x80800814: addiu       $a2, $t8, -0x1
    ctx->r6 = ADD32(ctx->r24, -0X1);
    func_800CC338(rdram, ctx);
        goto after_1;
    // 0x80800814: addiu       $a2, $t8, -0x1
    ctx->r6 = ADD32(ctx->r24, -0X1);
    after_1:
    // 0x80800818: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080081C: bne         $v0, $at, L_80800850
    if (ctx->r2 != ctx->r1) {
        // 0x80800820: addiu       $t0, $v0, 0x1
        ctx->r8 = ADD32(ctx->r2, 0X1);
            goto L_80800850;
    }
    // 0x80800820: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x80800824: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800828: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080082C: jal         0x800EFB24
    // 0x80800830: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x80800830: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_2:
    // 0x80800834: jal         0x800EF2A0
    // 0x80800838: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    func_800EF2A0(rdram, ctx);
        goto after_3;
    // 0x80800838: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    after_3:
    // 0x8080083C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800840: jal         0x800EE7F8
    // 0x80800844: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80800844: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x80800848: b           L_808009A8
    // 0x8080084C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808009A8;
    // 0x8080084C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800850:
    // 0x80800850: lhu         $t3, 0x72($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X72);
    // 0x80800854: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80800858: andi        $t2, $t1, 0x3F0
    ctx->r10 = ctx->r9 & 0X3F0;
    // 0x8080085C: andi        $t4, $t3, 0xFC0F
    ctx->r12 = ctx->r11 & 0XFC0F;
    // 0x80800860: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80800864: sh          $t5, 0x72($s0)
    MEM_H(0X72, ctx->r16) = ctx->r13;
L_80800868:
    // 0x80800868: jal         0x800EC708
    // 0x8080086C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800EC708(rdram, ctx);
        goto after_5;
    // 0x8080086C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x80800870: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(712, 0XFC4) << 16);
    // 0x80800874: lwc1        $f4, 0xFC4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(712, 0XFC4));
    // 0x80800878: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080087C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800880: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800884: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80800888: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x8080088C: lwc1        $f6, 0x4($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80800890: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80800894: swc1        $f8, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f8.u32l;
    // 0x80800898: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8080089C: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x808008A0: swc1        $f16, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f16.u32l;
    // 0x808008A4: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x808008A8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x808008AC: beq         $t6, $zero, L_80800904
    if (ctx->r14 == 0) {
        // 0x808008B0: nop
    
            goto L_80800904;
    }
    // 0x808008B0: nop

    // 0x808008B4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808008B8: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x808008BC: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x808008C0: jal         0x800BF0E0
    // 0x808008C4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    func_800BF0E0(rdram, ctx);
        goto after_6;
    // 0x808008C4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_6:
    // 0x808008C8: bne         $v0, $zero, L_80800988
    if (ctx->r2 != 0) {
        // 0x808008CC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800988;
    }
    // 0x808008CC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808008D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808008D4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808008D8: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x808008DC: jal         0x800BEF00
    // 0x808008E0: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    func_800BEF00(rdram, ctx);
        goto after_7;
    // 0x808008E0: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    after_7:
    // 0x808008E4: beq         $v0, $zero, L_80800988
    if (ctx->r2 == 0) {
        // 0x808008E8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800988;
    }
    // 0x808008E8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808008EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808008F0: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x808008F4: jal         0x800EF04C
    // 0x808008F8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    func_800EF04C(rdram, ctx);
        goto after_8;
    // 0x808008F8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_8:
    // 0x808008FC: b           L_80800988
    // 0x80800900: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
        goto L_80800988;
    // 0x80800900: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
L_80800904:
    // 0x80800904: jal         0x8010A698
    // 0x80800908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A698(rdram, ctx);
        goto after_9;
    // 0x80800908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080090C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800914: jal         0x8010A654
    // 0x80800918: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A654(rdram, ctx);
        goto after_10;
    // 0x80800918: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8080091C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80800920: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800924: lw          $t0, 0x14($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X14);
    // 0x80800928: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080092C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800930: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80800934: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x80800938: jal         0x800C6B78
    // 0x8080093C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    func_800C6B78(rdram, ctx);
        goto after_11;
    // 0x8080093C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_11:
    // 0x80800940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800944: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800948: jal         0x8010A654
    // 0x8080094C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    func_8010A654(rdram, ctx);
        goto after_12;
    // 0x8080094C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_12:
    // 0x80800950: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80800954: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800958: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080095C: bne         $v1, $zero, L_80800988
    if (ctx->r3 != 0) {
        // 0x80800960: lw          $a2, 0x54($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X54);
            goto L_80800988;
    }
    // 0x80800960: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80800964: jal         0x800C6A7C
    // 0x80800968: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    func_800C6A7C(rdram, ctx);
        goto after_13;
    // 0x80800968: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    after_13:
    // 0x8080096C: beq         $v0, $zero, L_80800988
    if (ctx->r2 == 0) {
        // 0x80800970: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800988;
    }
    // 0x80800970: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800974: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800978: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8080097C: jal         0x800EF04C
    // 0x80800980: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    func_800EF04C(rdram, ctx);
        goto after_14;
    // 0x80800980: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_14:
    // 0x80800984: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
L_80800988:
    // 0x80800988: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8080098C: lwc1        $f18, 0x4($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80800990: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800994: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80800998: swc1        $f4, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f4.u32l;
    // 0x8080099C: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x808009A0: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x808009A4: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
L_808009A8:
    // 0x808009A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808009AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808009B0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x808009B4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808009B8: jr          $ra
    // 0x808009BC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x808009BC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void _bsclaw_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082EC0: syscall     33
    recomp_syscall_handler(rdram, ctx, 0x80082EC0);
    return;
    // 0x80082EC4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808004E0_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004E8: jal         0x80082FF0
    // 0x808004EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808004EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808004F0: jal         0x80800198
    // 0x808004F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bssnowball_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808004F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808004F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800500: jr          $ra
    // 0x80800504: nop

    return;
    // 0x80800504: nop

;}
RECOMP_FUNC void badrone_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C4: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x808005C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808005D0: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x808005D4: bne         $t7, $at, L_808005E4
    if (ctx->r15 != ctx->r1) {
        // 0x808005D8: nop
    
            goto L_808005E4;
    }
    // 0x808005D8: nop

    // 0x808005DC: jr          $ra
    // 0x808005E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808005E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005E4:
    // 0x808005E4: jr          $ra
    // 0x808005E8: nop

    return;
    // 0x808005E8: nop

;}
RECOMP_FUNC void func_800F82D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F82D4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F82D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F82DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F82E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F82E4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F82E8: jal         0x800F457C
    // 0x800F82EC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800F457C(rdram, ctx);
        goto after_0;
    // 0x800F82EC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F82F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F82F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F82F8: jr          $ra
    // 0x800F82FC: nop

    return;
    // 0x800F82FC: nop

;}
RECOMP_FUNC void _gcgoto_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087A50: syscall     652
    recomp_syscall_handler(rdram, ctx, 0x80087A50);
    return;
    // 0x80087A54: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800C90AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C90AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C90B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C90B4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C90B8: jal         0x80087E88
    // 0x800C90BC: addiu       $a0, $a0, -0x5500
    ctx->r4 = ADD32(ctx->r4, -0X5500);
    _gclightsDll_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x800C90BC: addiu       $a0, $a0, -0x5500
    ctx->r4 = ADD32(ctx->r4, -0X5500);
    after_0:
    // 0x800C90C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C90C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C90C8: jr          $ra
    // 0x800C90CC: nop

    return;
    // 0x800C90CC: nop

;}
RECOMP_FUNC void badata_entrypoint_30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800E48: beq         $a1, $at, L_80800E74
    if (ctx->r5 == ctx->r1) {
        // 0x80800E4C: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_80800E74;
    }
    // 0x80800E4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800E50: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800E54: beq         $a1, $at, L_80800E7C
    if (ctx->r5 == ctx->r1) {
        // 0x80800E58: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800E7C;
    }
    // 0x80800E58: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800E5C: beq         $a1, $at, L_80800E84
    if (ctx->r5 == ctx->r1) {
        // 0x80800E60: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800E84;
    }
    // 0x80800E60: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800E64: beq         $a1, $at, L_80800E8C
    if (ctx->r5 == ctx->r1) {
        // 0x80800E68: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800E8C;
    }
    // 0x80800E68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800E6C: b           L_80800E94
    // 0x80800E70: nop

        goto L_80800E94;
    // 0x80800E70: nop

L_80800E74:
    // 0x80800E74: jr          $ra
    // 0x80800E78: addiu       $v0, $zero, 0x73
    ctx->r2 = ADD32(0, 0X73);
    return;
    // 0x80800E78: addiu       $v0, $zero, 0x73
    ctx->r2 = ADD32(0, 0X73);
L_80800E7C:
    // 0x80800E7C: jr          $ra
    // 0x80800E80: addiu       $v0, $zero, 0x74
    ctx->r2 = ADD32(0, 0X74);
    return;
    // 0x80800E80: addiu       $v0, $zero, 0x74
    ctx->r2 = ADD32(0, 0X74);
L_80800E84:
    // 0x80800E84: jr          $ra
    // 0x80800E88: addiu       $v0, $zero, 0x75
    ctx->r2 = ADD32(0, 0X75);
    return;
    // 0x80800E88: addiu       $v0, $zero, 0x75
    ctx->r2 = ADD32(0, 0X75);
L_80800E8C:
    // 0x80800E8C: jr          $ra
    // 0x80800E90: addiu       $v0, $zero, 0x74
    ctx->r2 = ADD32(0, 0X74);
    return;
    // 0x80800E90: addiu       $v0, $zero, 0x74
    ctx->r2 = ADD32(0, 0X74);
L_80800E94:
    // 0x80800E94: jr          $ra
    // 0x80800E98: nop

    return;
    // 0x80800E98: nop

;}
RECOMP_FUNC void func_808001EC_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001F4: jal         0x8008DE24
    // 0x808001F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8008DE24(rdram, ctx);
        goto after_0;
    // 0x808001F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001FC: beq         $v0, $zero, L_80800210
    if (ctx->r2 == 0) {
        // 0x80800200: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800210;
    }
    // 0x80800200: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800204: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(124, 0X2DE0) << 16);
    // 0x80800208: b           L_80800238
    // 0x8080020C: lwc1        $f0, 0x2DE0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(124, 0X2DE0));
        goto L_80800238;
    // 0x8080020C: lwc1        $f0, 0x2DE0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(124, 0X2DE0));
L_80800210:
    // 0x80800210: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(124, 0X2DE4) << 16);
    // 0x80800214: lwc1        $f4, 0x2DE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(124, 0X2DE4));
    // 0x80800218: lui         $a1, 0x3EAE
    ctx->r5 = S32(0X3EAE << 16);
    // 0x8080021C: lui         $a2, 0x3E94
    ctx->r6 = S32(0X3E94 << 16);
    // 0x80800220: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x80800224: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80800228: ori         $a2, $a2, 0x7AE1
    ctx->r6 = ctx->r6 | 0X7AE1;
    // 0x8080022C: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    // 0x80800230: jal         0x80800070
    // 0x80800234: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80800070_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x80800234: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
L_80800238:
    // 0x80800238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080023C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800240: jr          $ra
    // 0x80800244: nop

    return;
    // 0x80800244: nop

;}
RECOMP_FUNC void chmasterjiggy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(768, 0X164C) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x164C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(768, 0X164C));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x164C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(768, 0X164C));
;}
RECOMP_FUNC void bskazpaddle_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800650: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800654: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(268, 0XA60) << 16);
    // 0x80800658: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080065C: jr          $ra
    // 0x80800660: lw          $v0, 0xA60($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(268, 0XA60));
    return;
    // 0x80800660: lw          $v0, 0xA60($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(268, 0XA60));
;}
RECOMP_FUNC void func_8002A890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A890: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002A894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002A898: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002A89C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002A8A0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8002A8A4: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8002A8A8: beq         $t7, $zero, L_8002A928
    if (ctx->r15 == 0) {
        // 0x8002A8AC: nop
    
            goto L_8002A928;
    }
    // 0x8002A8AC: nop

    // 0x8002A8B0: jal         0x80021794
    // 0x8002A8B4: nop

    func_80021794(rdram, ctx);
        goto after_0;
    // 0x8002A8B4: nop

    after_0:
    // 0x8002A8B8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8002A8BC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A8C0: bne         $t8, $zero, L_8002A8D0
    if (ctx->r24 != 0) {
        // 0x8002A8C4: nop
    
            goto L_8002A8D0;
    }
    // 0x8002A8C4: nop

    // 0x8002A8C8: b           L_8002A930
    // 0x8002A8CC: nop

        goto L_8002A930;
    // 0x8002A8CC: nop

L_8002A8D0:
    // 0x8002A8D0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8002A8D4: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8002A8D8: lw          $t9, 0x11F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11F4);
    // 0x8002A8DC: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x8002A8E0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A8E4: lw          $t0, 0x1C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1C);
    // 0x8002A8E8: lw          $t3, 0x88($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X88);
    // 0x8002A8EC: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x8002A8F0: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8002A8F4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A8F8: addiu       $t6, $zero, 0x12
    ctx->r14 = ADD32(0, 0X12);
    // 0x8002A8FC: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
    // 0x8002A900: lbu         $t8, 0x27($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X27);
    // 0x8002A904: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A908: sw          $t8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r24;
    // 0x8002A90C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A910: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8002A914: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8002A918: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8002A91C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A920: jal         0x8002B684
    // 0x8002A924: lw          $a0, 0x8($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X8);
    func_8002B684(rdram, ctx);
        goto after_1;
    // 0x8002A924: lw          $a0, 0x8($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X8);
    after_1:
L_8002A928:
    // 0x8002A928: b           L_8002A930
    // 0x8002A92C: nop

        goto L_8002A930;
    // 0x8002A92C: nop

L_8002A930:
    // 0x8002A930: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002A934: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002A938: jr          $ra
    // 0x8002A93C: nop

    return;
    // 0x8002A93C: nop

;}
RECOMP_FUNC void func_801058C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801058C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801058C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801058CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801058D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801058D4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801058D8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801058DC: jal         0x80105494
    // 0x801058E0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_80105494(rdram, ctx);
        goto after_0;
    // 0x801058E0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x801058E4: bne         $v0, $zero, L_801058F8
    if (ctx->r2 != 0) {
        // 0x801058E8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801058F8;
    }
    // 0x801058E8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801058EC: jal         0x8010556C
    // 0x801058F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010556C(rdram, ctx);
        goto after_1;
    // 0x801058F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801058F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_801058F8:
    // 0x801058F8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801058FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80105900: beql        $a0, $at, L_80105924
    if (ctx->r4 == ctx->r1) {
        // 0x80105904: lw          $t3, 0x34($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X34);
            goto L_80105924;
    }
    goto skip_0;
    // 0x80105904: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x80105908: lh          $t0, 0x2($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X2);
    // 0x8010590C: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x80105910: andi        $t9, $t8, 0x7FE
    ctx->r25 = ctx->r24 & 0X7FE;
    // 0x80105914: andi        $t1, $t0, 0xF801
    ctx->r9 = ctx->r8 & 0XF801;
    // 0x80105918: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x8010591C: sh          $t2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r10;
    // 0x80105920: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
L_80105924:
    // 0x80105924: beql        $t3, $zero, L_8010594C
    if (ctx->r11 == 0) {
        // 0x80105928: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8010594C;
    }
    goto skip_1;
    // 0x80105928: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_1:
    // 0x8010592C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80105930: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80105934: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80105938: sll         $t4, $a0, 21
    ctx->r12 = S32(ctx->r4 << 21);
    // 0x8010593C: jal         0x800D8648
    // 0x80105940: sra         $a0, $t4, 22
    ctx->r4 = S32(SIGNED(ctx->r12) >> 22);
    func_800D8648(rdram, ctx);
        goto after_2;
    // 0x80105940: sra         $a0, $t4, 22
    ctx->r4 = S32(SIGNED(ctx->r12) >> 22);
    after_2:
    // 0x80105944: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80105948: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8010594C:
    // 0x8010594C: nop

    // 0x80105950: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x80105954: swc1        $f0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f0.u32l;
    // 0x80105958: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8010595C: swc1        $f4, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f4.u32l;
    // 0x80105960: lbu         $t7, 0x77($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X77);
    // 0x80105964: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80105968: sb          $t8, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r24;
    // 0x8010596C: lbu         $t9, 0x3($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X3);
    // 0x80105970: lbu         $t2, 0x28($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X28);
    // 0x80105974: ori         $t1, $t9, 0x1
    ctx->r9 = ctx->r25 | 0X1;
    // 0x80105978: andi        $t3, $t2, 0xFF1F
    ctx->r11 = ctx->r10 & 0XFF1F;
    // 0x8010597C: sb          $t1, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r9;
    // 0x80105980: sb          $t3, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r11;
    // 0x80105984: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80105988: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010598C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80105990: jr          $ra
    // 0x80105994: nop

    return;
    // 0x80105994: nop

;}
RECOMP_FUNC void fxleaves_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800358: lbu         $v0, 0x22($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X22);
    // 0x8080035C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80800360: sltu        $v0, $zero, $t6
    ctx->r2 = 0 < ctx->r14 ? 1 : 0;
    // 0x80800364: beql        $v0, $zero, L_80800380
    if (ctx->r2 == 0) {
        // 0x80800368: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800380;
    }
    goto skip_0;
    // 0x80800368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080036C: jal         0x800B2928
    // 0x80800370: lw          $a0, 0x1C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1C);
    vector_size(rdram, ctx);
        goto after_0;
    // 0x80800370: lw          $a0, 0x1C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1C);
    after_0:
    // 0x80800374: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800378: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8080037C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800380:
    // 0x80800380: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800384: jr          $ra
    // 0x80800388: nop

    return;
    // 0x80800388: nop

;}
RECOMP_FUNC void func_80800050_chfantasycannon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800050: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800058: jal         0x8010C500
    // 0x8080005C: nop

    func_8010C500(rdram, ctx);
        goto after_0;
    // 0x8080005C: nop

    after_0:
    // 0x80800060: bne         $v0, $zero, L_80800070
    if (ctx->r2 != 0) {
        // 0x80800064: nop
    
            goto L_80800070;
    }
    // 0x80800064: nop

    // 0x80800068: b           L_80800094
    // 0x8080006C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800094;
    // 0x8080006C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800070:
    // 0x80800070: jal         0x800F54E4
    // 0x80800074: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800074: nop

    after_1:
    // 0x80800078: jal         0x800F64DC
    // 0x8080007C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F64DC(rdram, ctx);
        goto after_2;
    // 0x8080007C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800080: bnel        $v0, $zero, L_80800094
    if (ctx->r2 != 0) {
        // 0x80800084: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800094;
    }
    goto skip_0;
    // 0x80800084: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800088: b           L_80800094
    // 0x8080008C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800094;
    // 0x8080008C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800090: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800094:
    // 0x80800094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080009C: jr          $ra
    // 0x808000A0: nop

    return;
    // 0x808000A0: nop

;}
RECOMP_FUNC void bsow_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800110: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800118: jal         0x800845D0
    // 0x8080011C: nop

    _babounce_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080011C: nop

    after_0:
    // 0x80800120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800124: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800128: jr          $ra
    // 0x8080012C: nop

    return;
    // 0x8080012C: nop

;}
RECOMP_FUNC void func_800FE89C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE89C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800FE8A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE8A4: jr          $ra
    // 0x800FE8A8: sb          $t6, 0x59CF($at)
    MEM_B(0X59CF, ctx->r1) = ctx->r14;
    return;
    // 0x800FE8A8: sb          $t6, 0x59CF($at)
    MEM_B(0X59CF, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_80800300_chfantasylakebits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800300: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800304: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800308: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080030C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800310: jal         0x800BEA88
    // 0x80800314: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BEA88(rdram, ctx);
        goto after_0;
    // 0x80800314: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80800318: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080031C: jal         0x80088F10
    // 0x80800320: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _idworld_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800320: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800324: beq         $v0, $zero, L_80800334
    if (ctx->r2 == 0) {
        // 0x80800328: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800334;
    }
    // 0x80800328: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080032C: jal         0x80088E98
    // 0x80800330: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    _idwibble_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800330: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    after_2:
L_80800334:
    // 0x80800334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080033C: jr          $ra
    // 0x80800340: nop

    return;
    // 0x80800340: nop

;}
RECOMP_FUNC void chmole_witchy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1680, 0XF0) << 16);
    // 0x808000B8: jr          $ra
    // 0x808000BC: addiu       $v0, $v0, 0xF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1680, 0XF0));
    return;
    // 0x808000BC: addiu       $v0, $v0, 0xF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1680, 0XF0));
;}
RECOMP_FUNC void func_80800C3C_chfriesstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C3C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800C40: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800C44: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800C48: jal         0x800EA05C
    // 0x80800C4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800C4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800C50: addiu       $at, $zero, 0x124
    ctx->r1 = ADD32(0, 0X124);
    // 0x80800C54: bnel        $v0, $at, L_80800C68
    if (ctx->r2 != ctx->r1) {
        // 0x80800C58: lui         $at, 0x4361
        ctx->r1 = S32(0X4361 << 16);
            goto L_80800C68;
    }
    goto skip_0;
    // 0x80800C58: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    skip_0:
    // 0x80800C5C: jal         0x8010A624
    // 0x80800C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A624(rdram, ctx);
        goto after_1;
    // 0x80800C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800C64: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
L_80800C68:
    // 0x80800C68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800C6C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800C70: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800C74: jal         0x80088848
    // 0x80800C78: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x80800C78: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    after_2:
    // 0x80800C7C: beq         $v0, $zero, L_80800C9C
    if (ctx->r2 == 0) {
        // 0x80800C80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C9C;
    }
    // 0x80800C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C84: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80800C88: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800C8C: jal         0x80101FDC
    // 0x80800C90: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80800C90: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x80800C94: b           L_80800CA0
    // 0x80800C98: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
        goto L_80800CA0;
    // 0x80800C98: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_80800C9C:
    // 0x80800C9C: addiu       $v0, $zero, 0xA0
    ctx->r2 = ADD32(0, 0XA0);
L_80800CA0:
    // 0x80800CA0: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x80800CA4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CAC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800CB0: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x80800CB4: lui         $a3, 0x4361
    ctx->r7 = S32(0X4361 << 16);
    // 0x80800CB8: jal         0x80086898
    // 0x80800CBC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800CBC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_4:
    // 0x80800CC0: beq         $v0, $zero, L_80800CDC
    if (ctx->r2 == 0) {
        // 0x80800CC4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CDC;
    }
    // 0x80800CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CC8: jal         0x800868A8
    // 0x80800CCC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80800CCC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_5:
    // 0x80800CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CD4: jal         0x800868C0
    // 0x80800CD8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x80800CD8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
L_80800CDC:
    // 0x80800CDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800CE0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800CE4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800CE8: jr          $ra
    // 0x80800CEC: nop

    return;
    // 0x80800CEC: nop

;}
RECOMP_FUNC void func_800F796C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F796C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F7970: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F7974: jal         0x800F798C
    // 0x800F7978: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800F798C(rdram, ctx);
        goto after_0;
    // 0x800F7978: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800F797C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F7980: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F7984: jr          $ra
    // 0x800F7988: nop

    return;
    // 0x800F7988: nop

;}
RECOMP_FUNC void _bsblongleg_entrypoint_30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082AB8: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082AB8);
    return;
    // 0x80082ABC: addi        $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
;}
RECOMP_FUNC void func_80100610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100610: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80100614: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80100618: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8010061C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80100620: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80100624: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80100628: addiu       $s1, $s1, 0x43DC
    ctx->r17 = ADD32(ctx->r17, 0X43DC);
    // 0x8010062C: addiu       $s0, $s0, 0x43A0
    ctx->r16 = ADD32(ctx->r16, 0X43A0);
    // 0x80100630: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
L_80100634:
    // 0x80100634: beql        $a0, $zero, L_80100654
    if (ctx->r4 == 0) {
        // 0x80100638: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80100654;
    }
    goto skip_0;
    // 0x80100638: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_0:
    // 0x8010063C: jal         0x8001B084
    // 0x80100640: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x80100640: nop

    after_0:
    // 0x80100644: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x80100648: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x8010064C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80100650: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_80100654:
    // 0x80100654: bnel        $s0, $s1, L_80100634
    if (ctx->r16 != ctx->r17) {
        // 0x80100658: lw          $a0, 0x8($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X8);
            goto L_80100634;
    }
    goto skip_1;
    // 0x80100658: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    skip_1:
    // 0x8010065C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80100660: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80100664: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80100668: jr          $ra
    // 0x8010066C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8010066C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800FF62C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FF62C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800FF630: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800FF634: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800FF638: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800FF63C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FF640: jal         0x800BEC1C
    // 0x800FF644: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_800BEC1C(rdram, ctx);
        goto after_0;
    // 0x800FF644: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800FF648: beq         $v0, $zero, L_800FF658
    if (ctx->r2 == 0) {
        // 0x800FF64C: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800FF658;
    }
    // 0x800FF64C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800FF650: b           L_800FF658
    // 0x800FF654: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_800FF658;
    // 0x800FF654: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_800FF658:
    // 0x800FF658: jal         0x8010D1E8
    // 0x800FF65C: nop

    func_8010D1E8(rdram, ctx);
        goto after_1;
    // 0x800FF65C: nop

    after_1:
    // 0x800FF660: jal         0x800DB9B0
    // 0x800FF664: nop

    func_800DB9B0(rdram, ctx);
        goto after_2;
    // 0x800FF664: nop

    after_2:
    // 0x800FF668: beq         $v0, $zero, L_800FF684
    if (ctx->r2 == 0) {
        // 0x800FF66C: addiu       $s2, $sp, 0x40
        ctx->r18 = ADD32(ctx->r29, 0X40);
            goto L_800FF684;
    }
    // 0x800FF66C: addiu       $s2, $sp, 0x40
    ctx->r18 = ADD32(ctx->r29, 0X40);
    // 0x800FF670: addiu       $s2, $sp, 0x40
    ctx->r18 = ADD32(ctx->r29, 0X40);
    // 0x800FF674: jal         0x800E3980
    // 0x800FF678: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800E3980(rdram, ctx);
        goto after_3;
    // 0x800FF678: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x800FF67C: b           L_800FF68C
    // 0x800FF680: nop

        goto L_800FF68C;
    // 0x800FF680: nop

L_800FF684:
    // 0x800FF684: jal         0x8010D254
    // 0x800FF688: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8010D254(rdram, ctx);
        goto after_4;
    // 0x800FF688: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
L_800FF68C:
    // 0x800FF68C: jal         0x801067C4
    // 0x800FF690: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_801067C4(rdram, ctx);
        goto after_5;
    // 0x800FF690: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_5:
    // 0x800FF694: beq         $v0, $zero, L_800FFA18
    if (ctx->r2 == 0) {
        // 0x800FF698: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800FFA18;
    }
    // 0x800FF698: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800FF69C:
    // 0x800FF69C: lw          $t6, 0x64($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X64);
    // 0x800FF6A0: lw          $s1, 0x0($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X0);
    // 0x800FF6A4: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x800FF6A8: bltz        $t8, L_800FFA08
    if (SIGNED(ctx->r24) < 0) {
        // 0x800FF6AC: nop
    
            goto L_800FFA08;
    }
    // 0x800FF6AC: nop

    // 0x800FF6B0: lw          $t9, 0x74($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X74);
    // 0x800FF6B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FF6B8: sll         $t1, $t9, 27
    ctx->r9 = S32(ctx->r25 << 27);
    // 0x800FF6BC: bgez        $t1, L_800FF6F4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800FF6C0: nop
    
            goto L_800FF6F4;
    }
    // 0x800FF6C0: nop

    // 0x800FF6C4: jal         0x8010038C
    // 0x800FF6C8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_8010038C(rdram, ctx);
        goto after_6;
    // 0x800FF6C8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_6:
    // 0x800FF6CC: beql        $v0, $zero, L_800FF738
    if (ctx->r2 == 0) {
        // 0x800FF6D0: lh          $t3, 0x8C($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X8C);
            goto L_800FF738;
    }
    goto skip_0;
    // 0x800FF6D0: lh          $t3, 0x8C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X8C);
    skip_0:
    // 0x800FF6D4: jal         0x80100368
    // 0x800FF6D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80100368(rdram, ctx);
        goto after_7;
    // 0x800FF6D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800FF6DC: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x800FF6E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FF6E4: jalr        $t9
    // 0x800FF6E8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x800FF6E8: nop

    after_8:
    // 0x800FF6EC: b           L_800FF738
    // 0x800FF6F0: lh          $t3, 0x8C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X8C);
        goto L_800FF738;
    // 0x800FF6F0: lh          $t3, 0x8C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X8C);
L_800FF6F4:
    // 0x800FF6F4: jal         0x80100120
    // 0x800FF6F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80100120(rdram, ctx);
        goto after_9;
    // 0x800FF6F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800FF6FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FF700: jal         0x8010038C
    // 0x800FF704: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_8010038C(rdram, ctx);
        goto after_10;
    // 0x800FF704: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_10:
    // 0x800FF708: beql        $v0, $zero, L_800FF738
    if (ctx->r2 == 0) {
        // 0x800FF70C: lh          $t3, 0x8C($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X8C);
            goto L_800FF738;
    }
    goto skip_1;
    // 0x800FF70C: lh          $t3, 0x8C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X8C);
    skip_1:
    // 0x800FF710: jal         0x80100368
    // 0x800FF714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80100368(rdram, ctx);
        goto after_11;
    // 0x800FF714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x800FF718: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800FF71C: beql        $t2, $zero, L_800FF738
    if (ctx->r10 == 0) {
        // 0x800FF720: lh          $t3, 0x8C($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X8C);
            goto L_800FF738;
    }
    goto skip_2;
    // 0x800FF720: lh          $t3, 0x8C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X8C);
    skip_2:
    // 0x800FF724: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x800FF728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FF72C: jalr        $t9
    // 0x800FF730: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_12;
    // 0x800FF730: nop

    after_12:
    // 0x800FF734: lh          $t3, 0x8C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X8C);
L_800FF738:
    // 0x800FF738: beql        $t3, $zero, L_800FF764
    if (ctx->r11 == 0) {
        // 0x800FF73C: lh          $t7, 0x90($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X90);
            goto L_800FF764;
    }
    goto skip_3;
    // 0x800FF73C: lh          $t7, 0x90($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X90);
    skip_3:
    // 0x800FF740: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x800FF744: sll         $t6, $t4, 4
    ctx->r14 = S32(ctx->r12 << 4);
    // 0x800FF748: bgezl       $t6, L_800FF764
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800FF74C: lh          $t7, 0x90($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X90);
            goto L_800FF764;
    }
    goto skip_4;
    // 0x800FF74C: lh          $t7, 0x90($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X90);
    skip_4:
    // 0x800FF750: jal         0x80104248
    // 0x800FF754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_13;
    // 0x800FF754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x800FF758: jal         0x8008ADE4
    // 0x800FF75C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008ADE4(rdram, ctx);
        goto after_14;
    // 0x800FF75C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x800FF760: lh          $t7, 0x90($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X90);
L_800FF764:
    // 0x800FF764: beql        $t7, $zero, L_800FF778
    if (ctx->r15 == 0) {
        // 0x800FF768: lhu         $t8, 0x78($s0)
        ctx->r24 = MEM_HU(ctx->r16, 0X78);
            goto L_800FF778;
    }
    goto skip_5;
    // 0x800FF768: lhu         $t8, 0x78($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X78);
    skip_5:
    // 0x800FF76C: jal         0x801061D8
    // 0x800FF770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801061D8(rdram, ctx);
        goto after_15;
    // 0x800FF770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x800FF774: lhu         $t8, 0x78($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X78);
L_800FF778:
    // 0x800FF778: andi        $t0, $t8, 0x3
    ctx->r8 = ctx->r24 & 0X3;
    // 0x800FF77C: beql        $t0, $zero, L_800FF790
    if (ctx->r8 == 0) {
        // 0x800FF780: lw          $t1, 0x94($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X94);
            goto L_800FF790;
    }
    goto skip_6;
    // 0x800FF780: lw          $t1, 0x94($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X94);
    skip_6:
    // 0x800FF784: jal         0x80089CC8
    // 0x800FF788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_7(rdram, ctx);
        goto after_16;
    // 0x800FF788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x800FF78C: lw          $t1, 0x94($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X94);
L_800FF790:
    // 0x800FF790: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800FF794: srl         $t9, $t2, 22
    ctx->r25 = S32(U32(ctx->r10) >> 22);
    // 0x800FF798: beql        $t9, $zero, L_800FF7AC
    if (ctx->r25 == 0) {
        // 0x800FF79C: lh          $t3, 0x8E($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X8E);
            goto L_800FF7AC;
    }
    goto skip_7;
    // 0x800FF79C: lh          $t3, 0x8E($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X8E);
    skip_7:
    // 0x800FF7A0: jal         0x80106F70
    // 0x800FF7A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80106F70(rdram, ctx);
        goto after_17;
    // 0x800FF7A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x800FF7A8: lh          $t3, 0x8E($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X8E);
L_800FF7AC:
    // 0x800FF7AC: beql        $t3, $zero, L_800FF7C0
    if (ctx->r11 == 0) {
        // 0x800FF7B0: lw          $t4, 0x78($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X78);
            goto L_800FF7C0;
    }
    goto skip_8;
    // 0x800FF7B0: lw          $t4, 0x78($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X78);
    skip_8:
    // 0x800FF7B4: jal         0x80104780
    // 0x800FF7B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104780(rdram, ctx);
        goto after_18;
    // 0x800FF7B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x800FF7BC: lw          $t4, 0x78($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X78);
L_800FF7C0:
    // 0x800FF7C0: sll         $t6, $t4, 28
    ctx->r14 = S32(ctx->r12 << 28);
    // 0x800FF7C4: bgezl       $t6, L_800FF7F8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800FF7C8: lw          $t7, 0x74($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X74);
            goto L_800FF7F8;
    }
    goto skip_9;
    // 0x800FF7C8: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    skip_9:
    // 0x800FF7CC: jal         0x80085908
    // 0x800FF7D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chbounce_entrypoint_8(rdram, ctx);
        goto after_19;
    // 0x800FF7D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x800FF7D4: jal         0x80103014
    // 0x800FF7D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_20;
    // 0x800FF7D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x800FF7DC: beq         $s3, $zero, L_800FFA00
    if (ctx->r19 == 0) {
        // 0x800FF7E0: nop
    
            goto L_800FFA00;
    }
    // 0x800FF7E0: nop

    // 0x800FF7E4: jal         0x8008A7A8
    // 0x800FF7E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiezone_entrypoint_0(rdram, ctx);
        goto after_21;
    // 0x800FF7E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x800FF7EC: b           L_800FFA00
    // 0x800FF7F0: nop

        goto L_800FFA00;
    // 0x800FF7F0: nop

    // 0x800FF7F4: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
L_800FF7F8:
    // 0x800FF7F8: sll         $t0, $t7, 26
    ctx->r8 = S32(ctx->r15 << 26);
    // 0x800FF7FC: bltz        $t0, L_800FF824
    if (SIGNED(ctx->r8) < 0) {
        // 0x800FF800: nop
    
            goto L_800FF824;
    }
    // 0x800FF800: nop

    // 0x800FF804: jal         0x80103014
    // 0x800FF808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_22;
    // 0x800FF808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x800FF80C: beq         $s3, $zero, L_800FFA00
    if (ctx->r19 == 0) {
        // 0x800FF810: nop
    
            goto L_800FFA00;
    }
    // 0x800FF810: nop

    // 0x800FF814: jal         0x8008A7A8
    // 0x800FF818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiezone_entrypoint_0(rdram, ctx);
        goto after_23;
    // 0x800FF818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x800FF81C: b           L_800FFA00
    // 0x800FF820: nop

        goto L_800FFA00;
    // 0x800FF820: nop

L_800FF824:
    // 0x800FF824: jal         0x800136E4
    // 0x800FF828: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    func_800136E4(rdram, ctx);
        goto after_24;
    // 0x800FF828: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    after_24:
    // 0x800FF82C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800FF830: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800FF834: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800FF838: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800FF83C: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800FF840: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800FF844: nop

    // 0x800FF848: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x800FF84C: beql        $t2, $zero, L_800FF89C
    if (ctx->r10 == 0) {
        // 0x800FF850: mfc1        $t2, $f4
        ctx->r10 = (int32_t)ctx->f4.u32l;
            goto L_800FF89C;
    }
    goto skip_10;
    // 0x800FF850: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    skip_10:
    // 0x800FF854: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FF858: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800FF85C: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800FF860: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800FF864: nop

    // 0x800FF868: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800FF86C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800FF870: nop

    // 0x800FF874: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x800FF878: bne         $t2, $zero, L_800FF890
    if (ctx->r10 != 0) {
        // 0x800FF87C: nop
    
            goto L_800FF890;
    }
    // 0x800FF87C: nop

    // 0x800FF880: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x800FF884: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800FF888: b           L_800FF8A8
    // 0x800FF88C: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_800FF8A8;
    // 0x800FF88C: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_800FF890:
    // 0x800FF890: b           L_800FF8A8
    // 0x800FF894: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_800FF8A8;
    // 0x800FF894: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800FF898: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
L_800FF89C:
    // 0x800FF89C: nop

    // 0x800FF8A0: bltz        $t2, L_800FF890
    if (SIGNED(ctx->r10) < 0) {
        // 0x800FF8A4: nop
    
            goto L_800FF890;
    }
    // 0x800FF8A4: nop

L_800FF8A8:
    // 0x800FF8A8: lhu         $t5, 0x28($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X28);
    // 0x800FF8AC: sll         $t4, $t2, 7
    ctx->r12 = S32(ctx->r10 << 7);
    // 0x800FF8B0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800FF8B4: andi        $t6, $t5, 0x7F
    ctx->r14 = ctx->r13 & 0X7F;
    // 0x800FF8B8: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x800FF8BC: sh          $t7, 0x28($s1)
    MEM_H(0X28, ctx->r17) = ctx->r15;
    // 0x800FF8C0: jal         0x800136E4
    // 0x800FF8C4: lwc1        $f12, 0x44($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X44);
    func_800136E4(rdram, ctx);
        goto after_25;
    // 0x800FF8C4: lwc1        $f12, 0x44($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X44);
    after_25:
    // 0x800FF8C8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800FF8CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800FF8D0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800FF8D4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800FF8D8: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800FF8DC: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800FF8E0: nop

    // 0x800FF8E4: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800FF8E8: beql        $t0, $zero, L_800FF938
    if (ctx->r8 == 0) {
        // 0x800FF8EC: mfc1        $t0, $f6
        ctx->r8 = (int32_t)ctx->f6.u32l;
            goto L_800FF938;
    }
    goto skip_11;
    // 0x800FF8EC: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    skip_11:
    // 0x800FF8F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FF8F4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800FF8F8: sub.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800FF8FC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800FF900: nop

    // 0x800FF904: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800FF908: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800FF90C: nop

    // 0x800FF910: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800FF914: bne         $t0, $zero, L_800FF92C
    if (ctx->r8 != 0) {
        // 0x800FF918: nop
    
            goto L_800FF92C;
    }
    // 0x800FF918: nop

    // 0x800FF91C: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800FF920: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800FF924: b           L_800FF944
    // 0x800FF928: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_800FF944;
    // 0x800FF928: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_800FF92C:
    // 0x800FF92C: b           L_800FF944
    // 0x800FF930: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_800FF944;
    // 0x800FF930: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800FF934: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
L_800FF938:
    // 0x800FF938: nop

    // 0x800FF93C: bltz        $t0, L_800FF92C
    if (SIGNED(ctx->r8) < 0) {
        // 0x800FF940: nop
    
            goto L_800FF92C;
    }
    // 0x800FF940: nop

L_800FF944:
    // 0x800FF944: lhu         $t3, 0x26($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X26);
    // 0x800FF948: sll         $t9, $t0, 7
    ctx->r25 = S32(ctx->r8 << 7);
    // 0x800FF94C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800FF950: andi        $t5, $t3, 0x7F
    ctx->r13 = ctx->r11 & 0X7F;
    // 0x800FF954: or          $t4, $t9, $t5
    ctx->r12 = ctx->r25 | ctx->r13;
    // 0x800FF958: sh          $t4, 0x26($s1)
    MEM_H(0X26, ctx->r17) = ctx->r12;
    // 0x800FF95C: jal         0x800136E4
    // 0x800FF960: lwc1        $f12, 0x4C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4C);
    func_800136E4(rdram, ctx);
        goto after_26;
    // 0x800FF960: lwc1        $f12, 0x4C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4C);
    after_26:
    // 0x800FF964: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800FF968: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800FF96C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800FF970: lw          $v0, 0x28($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X28);
    // 0x800FF974: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800FF978: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800FF97C: srl         $t0, $v0, 14
    ctx->r8 = S32(U32(ctx->r2) >> 14);
    // 0x800FF980: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800FF984: nop

    // 0x800FF988: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800FF98C: beql        $t7, $zero, L_800FF9DC
    if (ctx->r15 == 0) {
        // 0x800FF990: mfc1        $t7, $f8
        ctx->r15 = (int32_t)ctx->f8.u32l;
            goto L_800FF9DC;
    }
    goto skip_12;
    // 0x800FF990: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    skip_12:
    // 0x800FF994: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800FF998: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800FF99C: sub.s       $f8, $f0, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800FF9A0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800FF9A4: nop

    // 0x800FF9A8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800FF9AC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800FF9B0: nop

    // 0x800FF9B4: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800FF9B8: bne         $t7, $zero, L_800FF9D0
    if (ctx->r15 != 0) {
        // 0x800FF9BC: nop
    
            goto L_800FF9D0;
    }
    // 0x800FF9BC: nop

    // 0x800FF9C0: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800FF9C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800FF9C8: b           L_800FF9E8
    // 0x800FF9CC: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800FF9E8;
    // 0x800FF9CC: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800FF9D0:
    // 0x800FF9D0: b           L_800FF9E8
    // 0x800FF9D4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800FF9E8;
    // 0x800FF9D4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800FF9D8: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
L_800FF9DC:
    // 0x800FF9DC: nop

    // 0x800FF9E0: bltz        $t7, L_800FF9D0
    if (SIGNED(ctx->r15) < 0) {
        // 0x800FF9E4: nop
    
            goto L_800FF9D0;
    }
    // 0x800FF9E4: nop

L_800FF9E8:
    // 0x800FF9E8: xor         $t1, $t7, $t0
    ctx->r9 = ctx->r15 ^ ctx->r8;
    // 0x800FF9EC: sll         $t2, $t1, 23
    ctx->r10 = S32(ctx->r9 << 23);
    // 0x800FF9F0: srl         $t3, $t2, 9
    ctx->r11 = S32(U32(ctx->r10) >> 9);
    // 0x800FF9F4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800FF9F8: xor         $t9, $t3, $v0
    ctx->r25 = ctx->r11 ^ ctx->r2;
    // 0x800FF9FC: sw          $t9, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r25;
L_800FFA00:
    // 0x800FFA00: jal         0x80103040
    // 0x800FFA04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103040(rdram, ctx);
        goto after_27;
    // 0x800FFA04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
L_800FFA08:
    // 0x800FFA08: jal         0x8010682C
    // 0x800FFA0C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_8010682C(rdram, ctx);
        goto after_28;
    // 0x800FFA0C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_28:
    // 0x800FFA10: bne         $v0, $zero, L_800FF69C
    if (ctx->r2 != 0) {
        // 0x800FFA14: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800FF69C;
    }
    // 0x800FFA14: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800FFA18:
    // 0x800FFA18: jal         0x8010DF3C
    // 0x800FFA1C: nop

    func_8010DF3C(rdram, ctx);
        goto after_29;
    // 0x800FFA1C: nop

    after_29:
    // 0x800FFA20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800FFA24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FFA28: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FFA2C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800FFA30: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800FFA34: jr          $ra
    // 0x800FFA38: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800FFA38: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void indrv_audio_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080010C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800110: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80800114: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800118: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8080011C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800120: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800124: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800128: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8080012C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800130: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2970, 0X14A4) << 16);
    // 0x80800134: lui         $s7, 0x8080
    ctx->r23 = S32(RELOC_HI16(2970, 0X1A4C) << 16);
    // 0x80800138: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080013C: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x80800140: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80800144: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800148: addiu       $s7, $s7, 0x1A4C
    ctx->r23 = ADD32(ctx->r23, (int16_t)RELOC_LO16(2970, 0X1A4C));
    // 0x8080014C: addiu       $s0, $s0, 0x14A4
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2970, 0X14A4));
    // 0x80800150: addiu       $s4, $zero, -0x4
    ctx->r20 = ADD32(0, -0X4);
    // 0x80800154: addiu       $s5, $zero, -0x3
    ctx->r21 = ADD32(0, -0X3);
    // 0x80800158: addiu       $s6, $zero, -0x2
    ctx->r22 = ADD32(0, -0X2);
    // 0x8080015C: lhu         $t6, 0x0($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X0);
L_80800160:
    // 0x80800160: bnel        $s3, $t6, L_808001FC
    if (ctx->r19 != ctx->r14) {
        // 0x80800164: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_808001FC;
    }
    goto skip_0;
    // 0x80800164: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    skip_0:
    // 0x80800168: beq         $s2, $s4, L_808001C8
    if (ctx->r18 == ctx->r20) {
        // 0x8080016C: nop
    
            goto L_808001C8;
    }
    // 0x8080016C: nop

    // 0x80800170: beq         $s2, $s5, L_80800188
    if (ctx->r18 == ctx->r21) {
        // 0x80800174: nop
    
            goto L_80800188;
    }
    // 0x80800174: nop

    // 0x80800178: beq         $s2, $s6, L_808001B8
    if (ctx->r18 == ctx->r22) {
        // 0x8080017C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808001B8;
    }
    // 0x8080017C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800180: b           L_808001EC
    // 0x80800184: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_808001EC;
    // 0x80800184: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800188:
    // 0x80800188: jal         0x80106790
    // 0x8080018C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080018C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80800190: lw          $t7, 0x7C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X7C);
    // 0x80800194: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800198: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8080019C: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x808001A0: bgezl       $t9, L_808001FC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808001A4: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_808001FC;
    }
    goto skip_1;
    // 0x808001A4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    skip_1:
    // 0x808001A8: jal         0x80800000
    // 0x808001AC: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    func_80800000_indrv_audio(rdram, ctx);
        goto after_1;
    // 0x808001AC: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    after_1:
    // 0x808001B0: b           L_808001FC
    // 0x808001B4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_808001FC;
    // 0x808001B4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_808001B8:
    // 0x808001B8: jal         0x808000BC
    // 0x808001BC: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    func_808000BC_indrv_audio(rdram, ctx);
        goto after_2;
    // 0x808001BC: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_2:
    // 0x808001C0: b           L_808001FC
    // 0x808001C4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_808001FC;
    // 0x808001C4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_808001C8:
    // 0x808001C8: jal         0x800DA298
    // 0x808001CC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x808001CC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_3:
    // 0x808001D0: beq         $v0, $zero, L_808001F8
    if (ctx->r2 == 0) {
        // 0x808001D4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808001F8;
    }
    // 0x808001D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808001D8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808001DC: jal         0x80800000
    // 0x808001E0: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    func_80800000_indrv_audio(rdram, ctx);
        goto after_4;
    // 0x808001E0: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    after_4:
    // 0x808001E4: b           L_808001FC
    // 0x808001E8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_808001FC;
    // 0x808001E8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_808001EC:
    // 0x808001EC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808001F0: jal         0x80800000
    // 0x808001F4: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    func_80800000_indrv_audio(rdram, ctx);
        goto after_5;
    // 0x808001F4: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    after_5:
L_808001F8:
    // 0x808001F8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_808001FC:
    // 0x808001FC: bnel        $s0, $s7, L_80800160
    if (ctx->r16 != ctx->r23) {
        // 0x80800200: lhu         $t6, 0x0($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X0);
            goto L_80800160;
    }
    goto skip_2;
    // 0x80800200: lhu         $t6, 0x0($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X0);
    skip_2:
    // 0x80800204: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800208: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080020C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800210: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800214: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800218: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8080021C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80800220: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80800224: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80800228: jr          $ra
    // 0x8080022C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8080022C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80800030_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800038: jal         0x80106790
    // 0x8080003C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080003C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800040: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800044: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800048: jal         0x80100094
    // 0x8080004C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080004C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800050: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800054: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800058: slti        $at, $a3, 0x14
    ctx->r1 = SIGNED(ctx->r7) < 0X14 ? 1 : 0;
    // 0x8080005C: beq         $at, $zero, L_808000E0
    if (ctx->r1 == 0) {
        // 0x80800060: addu        $t6, $v0, $a3
        ctx->r14 = ADD32(ctx->r2, ctx->r7);
            goto L_808000E0;
    }
    // 0x80800060: addu        $t6, $v0, $a3
    ctx->r14 = ADD32(ctx->r2, ctx->r7);
    // 0x80800064: lb          $t7, 0x1F4($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X1F4);
    // 0x80800068: addiu       $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
    // 0x8080006C: addiu       $at, $zero, 0x6B54
    ctx->r1 = ADD32(0, 0X6B54);
    // 0x80800070: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800074: mflo        $t8
    ctx->r24 = lo;
    // 0x80800078: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8080007C: lhu         $v1, 0x4($t9)
    ctx->r3 = MEM_HU(ctx->r25, 0X4);
    // 0x80800080: beq         $v1, $at, L_8080008C
    if (ctx->r3 == ctx->r1) {
        // 0x80800084: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8080008C;
    }
    // 0x80800084: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800088: bne         $v1, $at, L_808000D8
    if (ctx->r3 != ctx->r1) {
        // 0x8080008C: addu        $v1, $a0, $a3
        ctx->r3 = ADD32(ctx->r4, ctx->r7);
            goto L_808000D8;
    }
L_8080008C:
    // 0x8080008C: addu        $v1, $a0, $a3
    ctx->r3 = ADD32(ctx->r4, ctx->r7);
    // 0x80800090: lb          $t1, 0x1F4($v1)
    ctx->r9 = MEM_B(ctx->r3, 0X1F4);
    // 0x80800094: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800098: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x8080009C: multu       $t1, $t0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808000A0: mflo        $t2
    ctx->r10 = lo;
    // 0x808000A4: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x808000A8: swc1        $f4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f4.u32l;
    // 0x808000AC: lb          $a2, 0x1F4($v1)
    ctx->r6 = MEM_B(ctx->r3, 0X1F4);
    // 0x808000B0: jal         0x808007E4
    // 0x808000B4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_808007E4_chjiggygamenew(rdram, ctx);
        goto after_2;
    // 0x808000B4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x808000B8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808000BC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x808000C0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x808000C4: lb          $t4, 0x1F4($v1)
    ctx->r12 = MEM_B(ctx->r3, 0X1F4);
    // 0x808000C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808000CC: sw          $t4, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->r12;
    // 0x808000D0: b           L_80800148
    // 0x808000D4: sb          $t6, 0x1F4($v1)
    MEM_B(0X1F4, ctx->r3) = ctx->r14;
        goto L_80800148;
    // 0x808000D4: sb          $t6, 0x1F4($v1)
    MEM_B(0X1F4, ctx->r3) = ctx->r14;
L_808000D8:
    // 0x808000D8: b           L_80800148
    // 0x808000DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800148;
    // 0x808000DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000E0:
    // 0x808000E0: addiu       $a3, $a3, -0x14
    ctx->r7 = ADD32(ctx->r7, -0X14);
    // 0x808000E4: addu        $t7, $v0, $a3
    ctx->r15 = ADD32(ctx->r2, ctx->r7);
    // 0x808000E8: lb          $t8, 0x208($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X208);
    // 0x808000EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808000F0: addu        $v1, $a0, $a3
    ctx->r3 = ADD32(ctx->r4, ctx->r7);
    // 0x808000F4: beq         $t8, $at, L_80800148
    if (ctx->r24 == ctx->r1) {
        // 0x808000F8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800148;
    }
    // 0x808000F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000FC: lb          $t9, 0x208($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X208);
    // 0x80800100: addiu       $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
    // 0x80800104: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800108: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080010C: addiu       $a1, $zero, 0xF54
    ctx->r5 = ADD32(0, 0XF54);
    // 0x80800110: mflo        $t1
    ctx->r9 = lo;
    // 0x80800114: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x80800118: swc1        $f6, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f6.u32l;
    // 0x8080011C: lb          $a2, 0x208($v1)
    ctx->r6 = MEM_B(ctx->r3, 0X208);
    // 0x80800120: jal         0x808007E4
    // 0x80800124: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_808007E4_chjiggygamenew(rdram, ctx);
        goto after_3;
    // 0x80800124: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_3:
    // 0x80800128: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080012C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80800130: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80800134: lb          $t3, 0x208($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X208);
    // 0x80800138: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8080013C: sw          $t3, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r11;
    // 0x80800140: b           L_80800148
    // 0x80800144: sb          $t5, 0x208($v1)
    MEM_B(0X208, ctx->r3) = ctx->r13;
        goto L_80800148;
    // 0x80800144: sb          $t5, 0x208($v1)
    MEM_B(0X208, ctx->r3) = ctx->r13;
L_80800148:
    // 0x80800148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080014C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800150: jr          $ra
    // 0x80800154: nop

    return;
    // 0x80800154: nop

;}
RECOMP_FUNC void func_80800734_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800734: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080073C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800740: jal         0x80100094
    // 0x80800744: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800744: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800748: lbu         $t6, 0xFA($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XFA);
    // 0x8080074C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800750: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800754: bne         $t6, $at, L_80800764
    if (ctx->r14 != ctx->r1) {
        // 0x80800758: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80800764;
    }
    // 0x80800758: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080075C: jal         0x80100074
    // 0x80800760: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80100074(rdram, ctx);
        goto after_1;
    // 0x80800760: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_80800764:
    // 0x80800764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080076C: jr          $ra
    // 0x80800770: nop

    return;
    // 0x80800770: nop

;}
RECOMP_FUNC void glsplinefind_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080004C: jal         0x80088288
    // 0x80800050: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    _gccubesearch_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800050: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80800054: bne         $v0, $zero, L_80800064
    if (ctx->r2 != 0) {
        // 0x80800058: nop
    
            goto L_80800064;
    }
    // 0x80800058: nop

    // 0x8080005C: b           L_8080006C
    // 0x80800060: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8080006C;
    // 0x80800060: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800064:
    // 0x80800064: jal         0x8080007C
    // 0x80800068: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    glsplinefind_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800068: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_1:
L_8080006C:
    // 0x8080006C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800070: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800074: jr          $ra
    // 0x80800078: nop

    return;
    // 0x80800078: nop

;}
RECOMP_FUNC void glpackvtx_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800004: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8080000C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800010: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800018: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x8080001C: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80800020: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800024: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80800028: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8080002C: jal         0x800B2344
    // 0x80800030: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    func_800B2344(rdram, ctx);
        goto after_0;
    // 0x80800030: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_0:
    // 0x80800034: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
    // 0x80800038: multu       $v0, $s3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080003C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800040: mflo        $a0
    ctx->r4 = lo;
    // 0x80800044: jal         0x8001ACCC
    // 0x80800048: nop

    heap_alloc(rdram, ctx);
        goto after_1;
    // 0x80800048: nop

    after_1:
    // 0x8080004C: multu       $s1, $s3
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800050: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800058: mflo        $t6
    ctx->r14 = lo;
    // 0x8080005C: addu        $s6, $t6, $v0
    ctx->r22 = ADD32(ctx->r14, ctx->r2);
    // 0x80800060: jal         0x800B2190
    // 0x80800064: nop

    func_800B2190(rdram, ctx);
        goto after_2;
    // 0x80800064: nop

    after_2:
    // 0x80800068: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x8080006C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800070: addiu       $s5, $sp, 0x44
    ctx->r21 = ADD32(ctx->r29, 0X44);
    // 0x80800074: sltu        $at, $s0, $s6
    ctx->r1 = ctx->r16 < ctx->r22 ? 1 : 0;
    // 0x80800078: beq         $at, $zero, L_80800190
    if (ctx->r1 == 0) {
        // 0x8080007C: addiu       $s3, $zero, 0xFF
        ctx->r19 = ADD32(0, 0XFF);
            goto L_80800190;
    }
    // 0x8080007C: addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
L_80800080:
    // 0x80800080: beql        $s4, $zero, L_808000F0
    if (ctx->r20 == 0) {
        // 0x80800084: lbu         $t1, 0xC($s1)
        ctx->r9 = MEM_BU(ctx->r17, 0XC);
            goto L_808000F0;
    }
    goto skip_0;
    // 0x80800084: lbu         $t1, 0xC($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0XC);
    skip_0:
    // 0x80800088: lhu         $a1, 0x6($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X6);
    // 0x8080008C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800090: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80800094: andi        $t8, $a1, 0x1FF
    ctx->r24 = ctx->r5 & 0X1FF;
    // 0x80800098: jal         0x80087958
    // 0x8080009C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    _dbpalette_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x8080009C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_3:
    // 0x808000A0: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x808000A4: lbu         $t0, 0xC($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0XC);
    // 0x808000A8: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808000AC: mflo        $t1
    ctx->r9 = lo;
    // 0x808000B0: sra         $t2, $t1, 8
    ctx->r10 = S32(SIGNED(ctx->r9) >> 8);
    // 0x808000B4: sb          $t2, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r10;
    // 0x808000B8: lbu         $t4, 0xD($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0XD);
    // 0x808000BC: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x808000C0: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808000C4: mflo        $t5
    ctx->r13 = lo;
    // 0x808000C8: sra         $t6, $t5, 8
    ctx->r14 = S32(SIGNED(ctx->r13) >> 8);
    // 0x808000CC: sb          $t6, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r14;
    // 0x808000D0: lbu         $t8, 0xE($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0XE);
    // 0x808000D4: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x808000D8: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808000DC: mflo        $t9
    ctx->r25 = lo;
    // 0x808000E0: sra         $t0, $t9, 8
    ctx->r8 = S32(SIGNED(ctx->r25) >> 8);
    // 0x808000E4: b           L_80800104
    // 0x808000E8: sb          $t0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r8;
        goto L_80800104;
    // 0x808000E8: sb          $t0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r8;
    // 0x808000EC: lbu         $t1, 0xC($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0XC);
L_808000F0:
    // 0x808000F0: sb          $t1, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r9;
    // 0x808000F4: lbu         $t2, 0xD($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0XD);
    // 0x808000F8: sb          $t2, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r10;
    // 0x808000FC: lbu         $t3, 0xE($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0XE);
    // 0x80800100: sb          $t3, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r11;
L_80800104:
    // 0x80800104: beq         $s2, $zero, L_80800174
    if (ctx->r18 == 0) {
        // 0x80800108: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_80800174;
    }
    // 0x80800108: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8080010C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80800110: bnel        $s3, $v0, L_80800134
    if (ctx->r19 != ctx->r2) {
        // 0x80800114: lbu         $t6, 0x6($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X6);
            goto L_80800134;
    }
    goto skip_1;
    // 0x80800114: lbu         $t6, 0x6($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X6);
    skip_1:
    // 0x80800118: lw          $t4, 0x4($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X4);
    // 0x8080011C: bnel        $s3, $t4, L_80800134
    if (ctx->r19 != ctx->r12) {
        // 0x80800120: lbu         $t6, 0x6($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X6);
            goto L_80800134;
    }
    goto skip_2;
    // 0x80800120: lbu         $t6, 0x6($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X6);
    skip_2:
    // 0x80800124: lw          $t5, 0x8($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X8);
    // 0x80800128: beql        $s3, $t5, L_80800178
    if (ctx->r19 == ctx->r13) {
        // 0x8080012C: sh          $zero, 0x4($s0)
        MEM_H(0X4, ctx->r16) = 0;
            goto L_80800178;
    }
    goto skip_3;
    // 0x8080012C: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    skip_3:
    // 0x80800130: lbu         $t6, 0x6($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X6);
L_80800134:
    // 0x80800134: lbu         $t0, 0x7($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X7);
    // 0x80800138: lbu         $t4, 0x8($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X8);
    // 0x8080013C: multu       $v0, $t6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800140: mflo        $t7
    ctx->r15 = lo;
    // 0x80800144: sra         $t8, $t7, 8
    ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
    // 0x80800148: sb          $t8, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r24;
    // 0x8080014C: lw          $t9, 0x4($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X4);
    // 0x80800150: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800154: mflo        $t1
    ctx->r9 = lo;
    // 0x80800158: sra         $t2, $t1, 8
    ctx->r10 = S32(SIGNED(ctx->r9) >> 8);
    // 0x8080015C: sb          $t2, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r10;
    // 0x80800160: lw          $t3, 0x8($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X8);
    // 0x80800164: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800168: mflo        $t5
    ctx->r13 = lo;
    // 0x8080016C: sra         $t6, $t5, 8
    ctx->r14 = S32(SIGNED(ctx->r13) >> 8);
    // 0x80800170: sb          $t6, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r14;
L_80800174:
    // 0x80800174: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
L_80800178:
    // 0x80800178: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    // 0x8080017C: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x80800180: sltu        $at, $s0, $s6
    ctx->r1 = ctx->r16 < ctx->r22 ? 1 : 0;
    // 0x80800184: sh          $v0, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r2;
    // 0x80800188: bne         $at, $zero, L_80800080
    if (ctx->r1 != 0) {
        // 0x8080018C: sh          $v0, -0xA($s0)
        MEM_H(-0XA, ctx->r16) = ctx->r2;
            goto L_80800080;
    }
    // 0x8080018C: sh          $v0, -0xA($s0)
    MEM_H(-0XA, ctx->r16) = ctx->r2;
L_80800190:
    // 0x80800190: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800194: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x80800198: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080019C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808001A0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808001A4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808001A8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808001AC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x808001B0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x808001B4: jr          $ra
    // 0x808001B8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x808001B8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_808007F4_chjiggytemple(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808007F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808007FC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800800: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800804: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800808: beq         $a1, $at, L_80800868
    if (ctx->r5 == ctx->r1) {
        // 0x8080080C: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800868;
    }
    // 0x8080080C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800810: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800814: bne         $a1, $at, L_80800890
    if (ctx->r5 != ctx->r1) {
        // 0x80800818: nop
    
            goto L_80800890;
    }
    // 0x80800818: nop

    // 0x8080081C: jal         0x80088840
    // 0x80800820: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x80800820: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    after_0:
    // 0x80800824: bnel        $v0, $zero, L_80800850
    if (ctx->r2 != 0) {
        // 0x80800828: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80800850;
    }
    goto skip_0;
    // 0x80800828: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x8080082C: jal         0x80088840
    // 0x80800830: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x80800830: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    after_1:
    // 0x80800834: bnel        $v0, $zero, L_80800850
    if (ctx->r2 != 0) {
        // 0x80800838: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80800850;
    }
    goto skip_1;
    // 0x80800838: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x8080083C: jal         0x800FFAB0
    // 0x80800840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800844: b           L_8080089C
    // 0x80800848: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080089C;
    // 0x80800848: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080084C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80800850:
    // 0x80800850: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800854: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80800858: jal         0x80085708
    // 0x8080085C: addiu       $a3, $zero, 0x2820
    ctx->r7 = ADD32(0, 0X2820);
    _capod_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x8080085C: addiu       $a3, $zero, 0x2820
    ctx->r7 = ADD32(0, 0X2820);
    after_3:
    // 0x80800860: b           L_8080089C
    // 0x80800864: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080089C;
    // 0x80800864: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800868:
    // 0x80800868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080086C: jal         0x80101FDC
    // 0x80800870: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80800870: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800874: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800878: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080087C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800880: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80800884: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x80800888: b           L_8080089C
    // 0x8080088C: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
        goto L_8080089C;
    // 0x8080088C: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
L_80800890:
    // 0x80800890: b           L_8080089C
    // 0x80800894: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080089C;
    // 0x80800894: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800898: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080089C:
    // 0x8080089C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808008A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808008A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808008A8: jr          $ra
    // 0x808008AC: nop

    return;
    // 0x808008AC: nop

;}
