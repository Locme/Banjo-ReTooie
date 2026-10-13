#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _bababykaz_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800844B8: syscall     112
    recomp_syscall_handler(rdram, ctx, 0x800844B8);
    return;
    // 0x800844BC: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80800B34_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800B38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B3C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800B40: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800B44: jal         0x80100094
    // 0x80800B48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800B48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800B4C: lbu         $t6, 0x5F($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X5F);
    // 0x80800B50: beql        $t6, $zero, L_80800B90
    if (ctx->r14 == 0) {
        // 0x80800B54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800B90;
    }
    goto skip_0;
    // 0x80800B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800B58: lw          $a0, 0x20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X20);
    // 0x80800B5C: jal         0x800F5EF8
    // 0x80800B60: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800F5EF8(rdram, ctx);
        goto after_1;
    // 0x80800B60: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800B64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B68: jal         0x80089548
    // 0x80800B6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _ncpod_entrypoint_17(rdram, ctx);
        goto after_2;
    // 0x80800B6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800B70: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B74: sb          $zero, 0x5F($t7)
    MEM_B(0X5F, ctx->r15) = 0;
    // 0x80800B78: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80800B7C: beql        $t8, $zero, L_80800B90
    if (ctx->r24 == 0) {
        // 0x80800B80: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800B90;
    }
    goto skip_1;
    // 0x80800B80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800B84: jal         0x808008C8
    // 0x80800B88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808008C8_chdragonbrothers(rdram, ctx);
        goto after_3;
    // 0x80800B88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800B8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B90:
    // 0x80800B90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B94: jr          $ra
    // 0x80800B98: nop

    return;
    // 0x80800B98: nop

;}
RECOMP_FUNC void func_8080090C_bstntswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080090C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800910: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800914: jal         0x80800114
    // 0x80800918: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800114_bstntswim(rdram, ctx);
        goto after_0;
    // 0x80800918: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080091C: jal         0x80082FE0
    // 0x80800920: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800920: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800928: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080092C: jr          $ra
    // 0x80800930: nop

    return;
    // 0x80800930: nop

;}
RECOMP_FUNC void bawasher_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001C8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808001CC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808001D0: lw          $a0, 0x14C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14C);
    // 0x808001D4: jal         0x800EE7F8
    // 0x808001D8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808001D8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_0:
    // 0x808001DC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808001E0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808001E4: lw          $a0, 0x14C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X14C);
    // 0x808001E8: jal         0x800EE7F8
    // 0x808001EC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808001EC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x808001F0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x808001F4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808001F8: lw          $a0, 0x14C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X14C);
    // 0x808001FC: jal         0x800EE7F8
    // 0x80800200: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800200: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_2:
    // 0x80800204: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80800208: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8080020C: addiu       $a0, $a0, 0x5420
    ctx->r4 = ADD32(ctx->r4, 0X5420);
    // 0x80800210: jal         0x80086D30
    // 0x80800214: lw          $a1, 0x184($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X184);
    _chbaddiesetup_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800214: lw          $a1, 0x184($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X184);
    after_3:
    // 0x80800218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080021C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800220: jr          $ra
    // 0x80800224: nop

    return;
    // 0x80800224: nop

;}
RECOMP_FUNC void func_808000F4_chclinker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808000F8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808000FC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800100: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800104: jal         0x80100094
    // 0x80800108: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800108: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080010C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800110: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80800114: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2208, 0X1408) << 16);
    // 0x80800118: addiu       $a1, $a1, 0x1408
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2208, 0X1408));
    // 0x8080011C: beq         $v1, $zero, L_80800138
    if (ctx->r3 == 0) {
        // 0x80800120: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800138;
    }
    // 0x80800120: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800124: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800128: beq         $v1, $at, L_8080027C
    if (ctx->r3 == ctx->r1) {
        // 0x8080012C: nop
    
            goto L_8080027C;
    }
    // 0x8080012C: nop

    // 0x80800130: b           L_808002A0
    // 0x80800134: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808002A0;
    // 0x80800134: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800138:
    // 0x80800138: jal         0x800C4AF0
    // 0x8080013C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_800C4AF0(rdram, ctx);
        goto after_1;
    // 0x8080013C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800140: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2208, 0X1418) << 16);
    // 0x80800144: addiu       $t6, $t6, 0x1418
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2208, 0X1418));
    // 0x80800148: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080014C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800154: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800158: jal         0x800BBCB8
    // 0x8080015C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x8080015C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80800160: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2208, 0X1444) << 16);
    // 0x80800164: addiu       $t7, $t7, 0x1444
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2208, 0X1444));
    // 0x80800168: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080016C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800170: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800174: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800178: jal         0x800BABB8
    // 0x8080017C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x8080017C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x80800180: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800184: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800188: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080018C: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800190: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x80800194: addiu       $t4, $zero, 0x258
    ctx->r12 = ADD32(0, 0X258);
    // 0x80800198: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8080019C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x808001A0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808001A4: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x808001A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001AC: addiu       $a1, $zero, -0x1E
    ctx->r5 = ADD32(0, -0X1E);
    // 0x808001B0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808001B4: addiu       $a3, $zero, 0x1C2
    ctx->r7 = ADD32(0, 0X1C2);
    // 0x808001B8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808001BC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808001C0: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x808001C4: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x808001C8: sra         $a2, $t9, 16
    ctx->r6 = S32(SIGNED(ctx->r25) >> 16);
    // 0x808001CC: jal         0x800BA994
    // 0x808001D0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    func_800BA994(rdram, ctx);
        goto after_4;
    // 0x808001D0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_4:
    // 0x808001D4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808001D8: jal         0x800BA22C
    // 0x808001DC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800BA22C(rdram, ctx);
        goto after_5;
    // 0x808001DC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_5:
    // 0x808001E0: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2208, 0X148C) << 16);
    // 0x808001E4: addiu       $t5, $t5, 0x148C
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(2208, 0X148C));
    // 0x808001E8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808001EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808001F0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808001F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808001F8: jal         0x800BABB8
    // 0x808001FC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_6;
    // 0x808001FC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_6:
    // 0x80800200: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800204: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800208: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080020C: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800210: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x80800214: addiu       $t2, $zero, 0xC8
    ctx->r10 = ADD32(0, 0XC8);
    // 0x80800218: sub.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8080021C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80800220: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800224: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80800228: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080022C: addiu       $a1, $zero, -0x1E
    ctx->r5 = ADD32(0, -0X1E);
    // 0x80800230: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800234: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    // 0x80800238: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080023C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800240: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80800244: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x80800248: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8080024C: jal         0x800BA994
    // 0x80800250: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    func_800BA994(rdram, ctx);
        goto after_7;
    // 0x80800250: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_7:
    // 0x80800254: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800258: jal         0x800BA22C
    // 0x8080025C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800BA22C(rdram, ctx);
        goto after_8;
    // 0x8080025C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x80800260: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2208, 0X12F0) << 16);
    // 0x80800264: lwc1        $f8, 0x12F0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2208, 0X12F0));
    // 0x80800268: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8080026C: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x80800270: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80800274: b           L_8080029C
    // 0x80800278: sw          $t3, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r11;
        goto L_8080029C;
    // 0x80800278: sw          $t3, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r11;
L_8080027C:
    // 0x8080027C: jal         0x800D9078
    // 0x80800280: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_9;
    // 0x80800280: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_9:
    // 0x80800284: beq         $v0, $zero, L_8080029C
    if (ctx->r2 == 0) {
        // 0x80800288: lw          $t5, 0x3C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X3C);
            goto L_8080029C;
    }
    // 0x80800288: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8080028C: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800294: jal         0x80103110
    // 0x80800298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_10;
    // 0x80800298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
L_8080029C:
    // 0x8080029C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808002A0:
    // 0x808002A0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808002A4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808002A8: jr          $ra
    // 0x808002AC: nop

    return;
    // 0x808002AC: nop

;}
RECOMP_FUNC void func_80803DD8_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803DD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803DDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803DE0: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80803DE4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80803DE8: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80803DEC: addiu       $t8, $t7, -0xB
    ctx->r24 = ADD32(ctx->r15, -0XB);
    // 0x80803DF0: sltiu       $at, $t8, 0x1D
    ctx->r1 = ctx->r24 < 0X1D ? 1 : 0;
    // 0x80803DF4: beq         $at, $zero, L_80803E3C
    if (ctx->r1 == 0) {
        // 0x80803DF8: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80803E3C;
    }
    // 0x80803DF8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80803DFC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X4560) << 16);
    // 0x80803E00: addu        $at, $at, $t8
    gpr jr_addend_80803E08 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80803E04: lw          $t8, 0x4560($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1360, 0X4560));
    // 0x80803E08: jr          $t8
    // 0x80803E0C: nop

    switch (jr_addend_80803E08 >> 2) {
        case 0: goto L_80803E10; break;
        case 1: goto L_80803E10; break;
        case 2: goto L_80803E3C; break;
        case 3: goto L_80803E3C; break;
        case 4: goto L_80803E3C; break;
        case 5: goto L_80803E3C; break;
        case 6: goto L_80803E3C; break;
        case 7: goto L_80803E3C; break;
        case 8: goto L_80803E3C; break;
        case 9: goto L_80803E3C; break;
        case 10: goto L_80803E3C; break;
        case 11: goto L_80803E20; break;
        case 12: goto L_80803E20; break;
        case 13: goto L_80803E3C; break;
        case 14: goto L_80803E3C; break;
        case 15: goto L_80803E3C; break;
        case 16: goto L_80803E3C; break;
        case 17: goto L_80803E3C; break;
        case 18: goto L_80803E3C; break;
        case 19: goto L_80803E3C; break;
        case 20: goto L_80803E3C; break;
        case 21: goto L_80803E3C; break;
        case 22: goto L_80803E3C; break;
        case 23: goto L_80803E3C; break;
        case 24: goto L_80803E3C; break;
        case 25: goto L_80803E3C; break;
        case 26: goto L_80803E3C; break;
        case 27: goto L_80803E30; break;
        case 28: goto L_80803E30; break;
        default: switch_error(__func__, 0x80803E08, 0x80804560);
    }
    // 0x80803E0C: nop

L_80803E10:
    // 0x80803E10: jal         0x80801AA0
    // 0x80803E14: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_0;
    // 0x80803E14: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_0:
    // 0x80803E18: b           L_80803E3C
    // 0x80803E1C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80803E3C;
    // 0x80803E1C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80803E20:
    // 0x80803E20: jal         0x80801AA0
    // 0x80803E24: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_1;
    // 0x80803E24: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_1:
    // 0x80803E28: b           L_80803E3C
    // 0x80803E2C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80803E3C;
    // 0x80803E2C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80803E30:
    // 0x80803E30: jal         0x80801AA0
    // 0x80803E34: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_2;
    // 0x80803E34: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    after_2:
    // 0x80803E38: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80803E3C:
    // 0x80803E3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803E40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803E44: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80803E48: jr          $ra
    // 0x80803E4C: nop

    return;
    // 0x80803E4C: nop

;}
RECOMP_FUNC void bafpctrl_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800F94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800F98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800F9C: beq         $a1, $zero, L_80800FEC
    if (ctx->r5 == 0) {
        // 0x80800FA0: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80800FEC;
    }
    // 0x80800FA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800FA4: jal         0x80800D38
    // 0x80800FA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bafpctrl_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800FA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FB0: jal         0x80800CA0
    // 0x80800FB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bafpctrl_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800FB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FBC: jal         0x80800CAC
    // 0x80800FC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bafpctrl_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800FC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800FCC: jal         0x800947EC
    // 0x80800FD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_3;
    // 0x80800FD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80800FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FD8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800FDC: jal         0x800947EC
    // 0x80800FE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_4;
    // 0x80800FE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80800FE4: b           L_8080101C
    // 0x80800FE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080101C;
    // 0x80800FE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800FEC:
    // 0x80800FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FF0: jal         0x80800D38
    // 0x80800FF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bafpctrl_entrypoint_14(rdram, ctx);
        goto after_5;
    // 0x80800FF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800FF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801000: jal         0x800947EC
    // 0x80801004: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_6;
    // 0x80801004: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80801008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080100C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801010: jal         0x800947EC
    // 0x80801014: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_7;
    // 0x80801014: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80801018: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080101C:
    // 0x8080101C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801020: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801024: jr          $ra
    // 0x80801028: nop

    return;
    // 0x80801028: nop

;}
RECOMP_FUNC void bamovespline_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800180: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800188: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080018C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800190: lw          $v0, 0xC8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC8);
    // 0x80800194: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800198: lbu         $t7, 0x90($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X90);
    // 0x8080019C: bnel        $t7, $at, L_808001D4
    if (ctx->r15 != ctx->r1) {
        // 0x808001A0: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_808001D4;
    }
    goto skip_0;
    // 0x808001A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x808001A4: jal         0x800D7520
    // 0x808001A8: lh          $a0, 0x94($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X94);
    func_800D7520(rdram, ctx);
        goto after_0;
    // 0x808001A8: lh          $a0, 0x94($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X94);
    after_0:
    // 0x808001AC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x808001B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001B4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x808001B8: lw          $t9, 0xC8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC8);
    // 0x808001BC: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x808001C0: jal         0x800C810C
    // 0x808001C4: lw          $a1, 0x98($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X98);
    func_800C810C(rdram, ctx);
        goto after_1;
    // 0x808001C4: lw          $a1, 0x98($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X98);
    after_1:
    // 0x808001C8: b           L_808001F0
    // 0x808001CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808001F0;
    // 0x808001CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_808001D4:
    // 0x808001D4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808001D8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808001DC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001E0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808001E4: jal         0x800EFA4C
    // 0x808001E8: nop

    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x808001E8: nop

    after_2:
    // 0x808001EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001F0:
    // 0x808001F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808001F4: jr          $ra
    // 0x808001F8: nop

    return;
    // 0x808001F8: nop

;}
RECOMP_FUNC void func_808000A4_chgate1doors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000B4: jal         0x800DA298
    // 0x808000B8: addiu       $a0, $zero, 0xB1
    ctx->r4 = ADD32(0, 0XB1);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808000B8: addiu       $a0, $zero, 0xB1
    ctx->r4 = ADD32(0, 0XB1);
    after_0:
    // 0x808000BC: beq         $v0, $zero, L_808000EC
    if (ctx->r2 == 0) {
        // 0x808000C0: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_808000EC;
    }
    // 0x808000C0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808000C4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808000C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D0: jal         0x8010A570
    // 0x808000D4: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    func_8010A570(rdram, ctx);
        goto after_1;
    // 0x808000D4: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000DC: jal         0x80101FDC
    // 0x808000E0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x808000E0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x808000E4: b           L_80800118
    // 0x808000E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800118;
    // 0x808000E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000EC:
    // 0x808000EC: addiu       $a1, $zero, 0x129
    ctx->r5 = ADD32(0, 0X129);
    // 0x808000F0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x808000F4: jal         0x80089C20
    // 0x808000F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808000F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x808000FC: beql        $v0, $zero, L_80800118
    if (ctx->r2 == 0) {
        // 0x80800100: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800118;
    }
    goto skip_0;
    // 0x80800100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800104: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80800108: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8080010C: sw          $t6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r14;
    // 0x80800110: sw          $t7, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r15;
    // 0x80800114: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800118:
    // 0x80800118: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080011C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800120: jr          $ra
    // 0x80800124: nop

    return;
    // 0x80800124: nop

;}
RECOMP_FUNC void sujiggy_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800130: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800138: jal         0x80088458
    // 0x8080013C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _glreflight_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080013C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800140: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800144: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(3354, 0X8E9) << 16);
    // 0x80800148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080014C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800150: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80800154: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80800158: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8080015C: lbu         $t8, 0x8E9($t8)
    ctx->r24 = MEM_BU(ctx->r24, (int16_t)RELOC_LO16(3354, 0X8E9));
    // 0x80800160: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800164: and         $t9, $t8, $v0
    ctx->r25 = ctx->r24 & ctx->r2;
    // 0x80800168: andi        $t0, $t9, 0x7F
    ctx->r8 = ctx->r25 & 0X7F;
    // 0x8080016C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80800170: jr          $ra
    // 0x80800174: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    return;
    // 0x80800174: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
;}
RECOMP_FUNC void func_808013E4_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808013E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808013EC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808013F0: jal         0x808001A8
    // 0x808013F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bsvan_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808013F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808013F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013FC: addiu       $a1, $zero, 0xEE
    ctx->r5 = ADD32(0, 0XEE);
    // 0x80801400: jal         0x8008CB3C
    // 0x80801404: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80801404: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x80801408: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8080140C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801414: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801418: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8080141C: jal         0x8009FFD8
    // 0x80801420: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80801420: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80801424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801428: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x8080142C: jal         0x8009C99C
    // 0x80801430: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_3;
    // 0x80801430: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    after_3:
    // 0x80801434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801438: jal         0x8009B9B0
    // 0x8080143C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x8080143C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80801440: jal         0x800909CC
    // 0x80801444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800909CC(rdram, ctx);
        goto after_5;
    // 0x80801444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801448: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080144C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801450: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801454: jr          $ra
    // 0x80801458: nop

    return;
    // 0x80801458: nop

;}
RECOMP_FUNC void _gcstatusDll_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088360: syscall     679
    recomp_syscall_handler(rdram, ctx, 0x80088360);
    return;
    // 0x80088364: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void chgoldsnakehead_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(724, 0X598) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x598
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(724, 0X598));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x598
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(724, 0X598));
;}
RECOMP_FUNC void func_801026CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801026CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801026D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801026D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801026D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801026DC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801026E0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801026E4: jal         0x800D3E40
    // 0x801026E8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800D3E40(rdram, ctx);
        goto after_0;
    // 0x801026E8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x801026EC: beq         $v0, $zero, L_80102708
    if (ctx->r2 == 0) {
        // 0x801026F0: lwc1        $f2, 0x28($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80102708;
    }
    // 0x801026F0: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801026F4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801026F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801026FC: nop

    // 0x80102700: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80102704: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
L_80102708:
    // 0x80102708: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8010270C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80102710: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80102714: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80102718: nop

    // 0x8010271C: bc1fl       L_80102730
    if (!c1cs) {
        // 0x80102720: sub.s       $f6, $f2, $f12
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f12.fl;
            goto L_80102730;
    }
    goto skip_0;
    // 0x80102720: sub.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f12.fl;
    skip_0:
    // 0x80102724: b           L_80102740
    // 0x80102728: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
        goto L_80102740;
    // 0x80102728: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8010272C: sub.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f12.fl;
L_80102730:
    // 0x80102730: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80102734: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80102738: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8010273C: add.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f16.fl;
L_80102740:
    // 0x80102740: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80102744: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80102748: nop

    // 0x8010274C: bc1fl       L_8010275C
    if (!c1cs) {
        // 0x80102750: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_8010275C;
    }
    goto skip_1;
    // 0x80102750: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_1:
    // 0x80102754: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80102758: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_8010275C:
    // 0x8010275C: jal         0x80101CDC
    // 0x80102760: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80101CDC(rdram, ctx);
        goto after_1;
    // 0x80102760: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80102764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010276C: jr          $ra
    // 0x80102770: nop

    return;
    // 0x80102770: nop

    // 0x80102774: nop

    // 0x80102778: nop

    // 0x8010277C: nop

;}
RECOMP_FUNC void func_80800130_chintrotext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800130: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800138: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080013C: jal         0x800DA524
    // 0x80800140: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    func_800DA524(rdram, ctx);
        goto after_0;
    // 0x80800140: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    after_0:
    // 0x80800144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800148: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080014C: jr          $ra
    // 0x80800150: nop

    return;
    // 0x80800150: nop

;}
RECOMP_FUNC void func_808000E0_chmermaidstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000E4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808000E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000EC: beq         $a1, $at, L_80800108
    if (ctx->r5 == ctx->r1) {
        // 0x808000F0: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800108;
    }
    // 0x808000F0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808000F4: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808000F8: beq         $a1, $at, L_80800118
    if (ctx->r5 == ctx->r1) {
        // 0x808000FC: nop
    
            goto L_80800118;
    }
    // 0x808000FC: nop

    // 0x80800100: b           L_80800140
    // 0x80800104: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800140;
    // 0x80800104: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800108:
    // 0x80800108: jal         0x808001B0
    // 0x8080010C: nop

    func_808001B0_chmermaidstatue(rdram, ctx);
        goto after_0;
    // 0x8080010C: nop

    after_0:
    // 0x80800110: b           L_80800140
    // 0x80800114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800140;
    // 0x80800114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800118:
    // 0x80800118: jal         0x80800150
    // 0x8080011C: nop

    func_80800150_chmermaidstatue(rdram, ctx);
        goto after_1;
    // 0x8080011C: nop

    after_1:
    // 0x80800120: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800124: jal         0x800BF744
    // 0x80800128: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    func_800BF744(rdram, ctx);
        goto after_2;
    // 0x80800128: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    after_2:
    // 0x8080012C: b           L_80800140
    // 0x80800130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800140;
    // 0x80800130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800134: b           L_80800140
    // 0x80800138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800140;
    // 0x80800138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080013C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800140:
    // 0x80800140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800148: jr          $ra
    // 0x8080014C: nop

    return;
    // 0x8080014C: nop

;}
RECOMP_FUNC void func_800EA45C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA45C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800EA460: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x800EA464: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x800EA468: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x800EA46C: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800EA470: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800EA474: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800EA478: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x800EA47C: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800EA480: addiu       $s2, $s2, 0x2DD0
    ctx->r18 = ADD32(ctx->r18, 0X2DD0);
    // 0x800EA484: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800EA488: addiu       $s4, $sp, 0x60
    ctx->r20 = ADD32(ctx->r29, 0X60);
    // 0x800EA48C: addiu       $s5, $zero, 0x8
    ctx->r21 = ADD32(0, 0X8);
L_800EA490:
    // 0x800EA490: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800EA494: beql        $a0, $zero, L_800EA4F0
    if (ctx->r4 == 0) {
        // 0x800EA498: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800EA4F0;
    }
    goto skip_0;
    // 0x800EA498: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800EA49C: jal         0x80106790
    // 0x800EA4A0: addiu       $s3, $s2, 0x8
    ctx->r19 = ADD32(ctx->r18, 0X8);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x800EA4A0: addiu       $s3, $s2, 0x8
    ctx->r19 = ADD32(ctx->r18, 0X8);
    after_0:
    // 0x800EA4A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800EA4A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800EA4AC: jal         0x800F5A00
    // 0x800EA4B0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x800EA4B0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x800EA4B4: jal         0x80103C94
    // 0x800EA4B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103C94(rdram, ctx);
        goto after_2;
    // 0x800EA4B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800EA4BC: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800EA4C0: lh          $a0, 0x80($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X80);
    // 0x800EA4C4: lw          $t6, 0x18($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X18);
    // 0x800EA4C8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800EA4CC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800EA4D0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800EA4D4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800EA4D8: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x800EA4DC: addiu       $a3, $s0, 0x44
    ctx->r7 = ADD32(ctx->r16, 0X44);
    // 0x800EA4E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800EA4E4: jal         0x800D8B80
    // 0x800EA4E8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_800D8B80(rdram, ctx);
        goto after_3;
    // 0x800EA4E8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_3:
    // 0x800EA4EC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800EA4F0:
    // 0x800EA4F0: bne         $s1, $s5, L_800EA490
    if (ctx->r17 != ctx->r21) {
        // 0x800EA4F4: addiu       $s2, $s2, 0x14
        ctx->r18 = ADD32(ctx->r18, 0X14);
            goto L_800EA490;
    }
    // 0x800EA4F4: addiu       $s2, $s2, 0x14
    ctx->r18 = ADD32(ctx->r18, 0X14);
    // 0x800EA4F8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800EA4FC: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800EA500: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800EA504: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x800EA508: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x800EA50C: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x800EA510: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x800EA514: jr          $ra
    // 0x800EA518: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800EA518: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80800518_bskazpaddle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800518: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080051C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800520: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800524: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800528: jal         0x8008CABC
    // 0x8080052C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080052C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x80800530: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800538: jal         0x80092C24
    // 0x8080053C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80092C24(rdram, ctx);
        goto after_1;
    // 0x8080053C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800544: jal         0x808003F4
    // 0x80800548: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_808003F4_bskazpaddle(rdram, ctx);
        goto after_2;
    // 0x80800548: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800550: jal         0x80092C00
    // 0x80800554: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80092C00(rdram, ctx);
        goto after_3;
    // 0x80800554: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x80800558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080055C: jal         0x808003F4
    // 0x80800560: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_808003F4_bskazpaddle(rdram, ctx);
        goto after_4;
    // 0x80800560: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x80800564: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800568: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8080056C: jal         0x8008B348
    // 0x80800570: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isAt(rdram, ctx);
        goto after_5;
    // 0x80800570: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x80800574: beq         $v0, $zero, L_80800594
    if (ctx->r2 == 0) {
        // 0x80800578: lui         $a2, 0x3F66
        ctx->r6 = S32(0X3F66 << 16);
            goto L_80800594;
    }
    // 0x80800578: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x8080057C: lui         $a3, 0x3F8C
    ctx->r7 = S32(0X3F8C << 16);
    // 0x80800580: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800584: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080058C: jal         0x8009DE74
    // 0x80800590: addiu       $a1, $zero, 0x40C
    ctx->r5 = ADD32(0, 0X40C);
    func_8009DE74(rdram, ctx);
        goto after_6;
    // 0x80800590: addiu       $a1, $zero, 0x40C
    ctx->r5 = ADD32(0, 0X40C);
    after_6:
L_80800594:
    // 0x80800594: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800598: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x8080059C: jal         0x8008B348
    // 0x808005A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x808005A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x808005A4: beq         $v0, $zero, L_808005C4
    if (ctx->r2 == 0) {
        // 0x808005A8: lui         $a2, 0x3F66
        ctx->r6 = S32(0X3F66 << 16);
            goto L_808005C4;
    }
    // 0x808005A8: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x808005AC: lui         $a3, 0x3F8C
    ctx->r7 = S32(0X3F8C << 16);
    // 0x808005B0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808005B4: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808005B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005BC: jal         0x8009DE74
    // 0x808005C0: addiu       $a1, $zero, 0x40C
    ctx->r5 = ADD32(0, 0X40C);
    func_8009DE74(rdram, ctx);
        goto after_8;
    // 0x808005C0: addiu       $a1, $zero, 0x40C
    ctx->r5 = ADD32(0, 0X40C);
    after_8:
L_808005C4:
    // 0x808005C4: jal         0x80800100
    // 0x808005C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800100_bskazpaddle(rdram, ctx);
        goto after_9;
    // 0x808005C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808005CC: jal         0x8009EF10
    // 0x808005D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_10;
    // 0x808005D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808005D4: bne         $v0, $zero, L_808005E0
    if (ctx->r2 != 0) {
        // 0x808005D8: addiu       $t6, $zero, 0x15D
        ctx->r14 = ADD32(0, 0X15D);
            goto L_808005E0;
    }
    // 0x808005D8: addiu       $t6, $zero, 0x15D
    ctx->r14 = ADD32(0, 0X15D);
    // 0x808005DC: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_808005E0:
    // 0x808005E0: jal         0x8008E35C
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_11;
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808005E8: bne         $v0, $zero, L_808005F8
    if (ctx->r2 != 0) {
        // 0x808005EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005F8;
    }
    // 0x808005EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F0: addiu       $t7, $zero, 0xBB
    ctx->r15 = ADD32(0, 0XBB);
    // 0x808005F4: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_808005F8:
    // 0x808005F8: jal         0x80091A58
    // 0x808005FC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_12;
    // 0x808005FC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_12:
    // 0x80800600: beq         $v0, $zero, L_8080060C
    if (ctx->r2 == 0) {
        // 0x80800604: addiu       $t8, $zero, 0x15F
        ctx->r24 = ADD32(0, 0X15F);
            goto L_8080060C;
    }
    // 0x80800604: addiu       $t8, $zero, 0x15F
    ctx->r24 = ADD32(0, 0X15F);
    // 0x80800608: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_8080060C:
    // 0x8080060C: jal         0x80096500
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096500(rdram, ctx);
        goto after_13;
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800614: beq         $v0, $zero, L_80800630
    if (ctx->r2 == 0) {
        // 0x80800618: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800630;
    }
    // 0x80800618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080061C: jal         0x80091A58
    // 0x80800620: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_14;
    // 0x80800620: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_14:
    // 0x80800624: beq         $v0, $zero, L_80800630
    if (ctx->r2 == 0) {
        // 0x80800628: addiu       $t9, $zero, 0xBD
        ctx->r25 = ADD32(0, 0XBD);
            goto L_80800630;
    }
    // 0x80800628: addiu       $t9, $zero, 0xBD
    ctx->r25 = ADD32(0, 0XBD);
    // 0x8080062C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_80800630:
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800634: jal         0x8009E5C8
    // 0x80800638: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_15;
    // 0x80800638: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_15:
    // 0x8080063C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800640: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800644: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800648: jr          $ra
    // 0x8080064C: nop

    return;
    // 0x8080064C: nop

;}
RECOMP_FUNC void func_80800000_chlavaslabswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080000C: bne         $a1, $at, L_80800044
    if (ctx->r5 != ctx->r1) {
        // 0x80800010: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80800044;
    }
    // 0x80800010: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800014: addiu       $a0, $zero, 0x250
    ctx->r4 = ADD32(0, 0X250);
    // 0x80800018: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8080001C: jal         0x80101180
    // 0x80800020: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_0;
    // 0x80800020: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800024: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800028: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080002C: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80800030: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80800034: jal         0x80085708
    // 0x80800038: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80800038: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x8080003C: b           L_8080004C
    // 0x80800040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080004C;
    // 0x80800040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800044:
    // 0x80800044: jal         0x80085820
    // 0x80800048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_8080004C:
    // 0x8080004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800054: jr          $ra
    // 0x80800058: nop

    return;
    // 0x80800058: nop

;}
RECOMP_FUNC void func_8080020C_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080020C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800210: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800214: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800218: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8080021C: jal         0x8009EF10
    // 0x80800220: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bastick_getZone(rdram, ctx);
        goto after_0;
    // 0x80800220: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800224: beq         $v0, $zero, L_80800250
    if (ctx->r2 == 0) {
        // 0x80800228: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800250;
    }
    // 0x80800228: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080022C: beq         $v0, $at, L_80800244
    if (ctx->r2 == ctx->r1) {
        // 0x80800230: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800244;
    }
    // 0x80800230: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800234: beql        $v0, $at, L_80800250
    if (ctx->r2 == ctx->r1) {
        // 0x80800238: addiu       $s0, $zero, 0x144
        ctx->r16 = ADD32(0, 0X144);
            goto L_80800250;
    }
    goto skip_0;
    // 0x80800238: addiu       $s0, $zero, 0x144
    ctx->r16 = ADD32(0, 0X144);
    skip_0:
    // 0x8080023C: b           L_80800250
    // 0x80800240: nop

        goto L_80800250;
    // 0x80800240: nop

L_80800244:
    // 0x80800244: b           L_80800250
    // 0x80800248: addiu       $s0, $zero, 0x146
    ctx->r16 = ADD32(0, 0X146);
        goto L_80800250;
    // 0x80800248: addiu       $s0, $zero, 0x146
    ctx->r16 = ADD32(0, 0X146);
    // 0x8080024C: addiu       $s0, $zero, 0x144
    ctx->r16 = ADD32(0, 0X144);
L_80800250:
    // 0x80800250: jal         0x80097AD0
    // 0x80800254: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bainput_should_enter_first_person(rdram, ctx);
        goto after_1;
    // 0x80800254: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800258: beq         $v0, $zero, L_8080026C
    if (ctx->r2 == 0) {
        // 0x8080025C: nop
    
            goto L_8080026C;
    }
    // 0x8080025C: nop

    // 0x80800260: jal         0x800848A8
    // 0x80800264: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _badrone_entrypoint_24(rdram, ctx);
        goto after_2;
    // 0x80800264: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800268: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8080026C:
    // 0x8080026C: jal         0x80800000
    // 0x80800270: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800000_bstrexsmall(rdram, ctx);
        goto after_3;
    // 0x80800270: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800274: beq         $v0, $zero, L_80800280
    if (ctx->r2 == 0) {
        // 0x80800278: nop
    
            goto L_80800280;
    }
    // 0x80800278: nop

    // 0x8080027C: addiu       $s0, $zero, 0x143
    ctx->r16 = ADD32(0, 0X143);
L_80800280:
    // 0x80800280: jal         0x8008DD04
    // 0x80800284: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8008DD04(rdram, ctx);
        goto after_4;
    // 0x80800284: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800288: beq         $v0, $zero, L_80800294
    if (ctx->r2 == 0) {
        // 0x8080028C: nop
    
            goto L_80800294;
    }
    // 0x8080028C: nop

    // 0x80800290: addiu       $s0, $zero, 0x13E
    ctx->r16 = ADD32(0, 0X13E);
L_80800294:
    // 0x80800294: jal         0x8080003C
    // 0x80800298: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8080003C_bstrexsmall(rdram, ctx);
        goto after_5;
    // 0x80800298: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x8080029C: beq         $v0, $zero, L_808002A8
    if (ctx->r2 == 0) {
        // 0x808002A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002A8;
    }
    // 0x808002A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002A4: addiu       $s0, $zero, 0x13F
    ctx->r16 = ADD32(0, 0X13F);
L_808002A8:
    // 0x808002A8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x808002AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002B0: jr          $ra
    // 0x808002B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808002B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void bsdie_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800358: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080035C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800360: jal         0x80085230
    // 0x80800364: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _basudie_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800364: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800368: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080036C: jal         0x800A0CF4
    // 0x80800370: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_1;
    // 0x80800370: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800374: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800378: jal         0x8009BF5C
    // 0x8080037C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_2;
    // 0x8080037C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800380: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800384: jal         0x8009C4CC
    // 0x80800388: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_3;
    // 0x80800388: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x8080038C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800390: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800394: jr          $ra
    // 0x80800398: nop

    return;
    // 0x80800398: nop

;}
RECOMP_FUNC void chbigterrysbits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1056, 0X380) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x380
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1056, 0X380));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x380
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1056, 0X380));
;}
RECOMP_FUNC void func_8001B858(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B858: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001B85C: jr          $ra
    // 0x8001B860: lw          $v0, -0x3908($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3908);
    return;
    // 0x8001B860: lw          $v0, -0x3908($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3908);
;}
RECOMP_FUNC void _idworld_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088F08: syscall     748
    recomp_syscall_handler(rdram, ctx, 0x80088F08);
    return;
    // 0x80088F0C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void gczoomboxdata_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800274: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800278: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8080027C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2686, 0XAA8) << 16);
    // 0x80800280: addiu       $t7, $t7, 0xAA8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2686, 0XAA8));
    // 0x80800284: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800288: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8080028C: lb          $t8, 0x2($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X2);
    // 0x80800290: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    // 0x80800294: lb          $t9, 0x3($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X3);
    // 0x80800298: jr          $ra
    // 0x8080029C: sb          $t9, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r25;
    return;
    // 0x8080029C: sb          $t9, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r25;
;}
RECOMP_FUNC void func_808009EC_chbiggafoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808009F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808009F8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808009FC: jal         0x8010C9B0
    // 0x80800A00: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    func_8010C9B0(rdram, ctx);
        goto after_0;
    // 0x80800A00: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    after_0:
    // 0x80800A04: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800A08: addiu       $a0, $zero, 0x6CD
    ctx->r4 = ADD32(0, 0X6CD);
    // 0x80800A0C: jal         0x800DA3B8
    // 0x80800A10: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800DA3B8(rdram, ctx);
        goto after_1;
    // 0x80800A10: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80800A14: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A18: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800A1C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800A20: bne         $t6, $zero, L_80800A38
    if (ctx->r14 != 0) {
        // 0x80800A24: nop
    
            goto L_80800A38;
    }
    // 0x80800A24: nop

    // 0x80800A28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800A30: b           L_80800A8C
    // 0x80800A34: swc1        $f4, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->f4.u32l;
        goto L_80800A8C;
    // 0x80800A34: swc1        $f4, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->f4.u32l;
L_80800A38:
    // 0x80800A38: jal         0x800F54E4
    // 0x80800A3C: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80800A3C: nop

    after_2:
    // 0x80800A40: jal         0x800F6478
    // 0x80800A44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6478(rdram, ctx);
        goto after_3;
    // 0x80800A44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800A48: bne         $v0, $zero, L_80800A58
    if (ctx->r2 != 0) {
        // 0x80800A4C: nop
    
            goto L_80800A58;
    }
    // 0x80800A4C: nop

    // 0x80800A50: b           L_80800A8C
    // 0x80800A54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A8C;
    // 0x80800A54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A58:
    // 0x80800A58: jal         0x800DA298
    // 0x80800A5C: addiu       $a0, $zero, 0x9FB
    ctx->r4 = ADD32(0, 0X9FB);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800A5C: addiu       $a0, $zero, 0x9FB
    ctx->r4 = ADD32(0, 0X9FB);
    after_4:
    // 0x80800A60: beql        $v0, $zero, L_80800A8C
    if (ctx->r2 == 0) {
        // 0x80800A64: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800A8C;
    }
    goto skip_0;
    // 0x80800A64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800A68: jal         0x800DA298
    // 0x80800A6C: addiu       $a0, $zero, 0x1C7
    ctx->r4 = ADD32(0, 0X1C7);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80800A6C: addiu       $a0, $zero, 0x1C7
    ctx->r4 = ADD32(0, 0X1C7);
    after_5:
    // 0x80800A70: beq         $v0, $zero, L_80800A88
    if (ctx->r2 == 0) {
        // 0x80800A74: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800A88;
    }
    // 0x80800A74: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800A78: jal         0x800D9078
    // 0x80800A7C: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    func_800D9078(rdram, ctx);
        goto after_6;
    // 0x80800A7C: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    after_6:
    // 0x80800A80: b           L_80800A90
    // 0x80800A84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800A90;
    // 0x80800A84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A88:
    // 0x80800A88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A8C:
    // 0x80800A8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A90:
    // 0x80800A90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A94: jr          $ra
    // 0x80800A98: nop

    return;
    // 0x80800A98: nop

;}
RECOMP_FUNC void _ncpod_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089518: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x80089518);
    return;
    // 0x8008951C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void _gccubesearch_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800882E0: syscall     678
    recomp_syscall_handler(rdram, ctx, 0x800882E0);
    return;
    // 0x800882E4: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_80801448_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801448: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080144C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801450: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801454: jal         0x8009E710
    // 0x80801458: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_0;
    // 0x80801458: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080145C: lui         $a2, 0x3FA6
    ctx->r6 = S32(0X3FA6 << 16);
    // 0x80801460: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80801464: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80801468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080146C: jal         0x8008CCBC
    // 0x80801470: addiu       $a1, $zero, 0x11D
    ctx->r5 = ADD32(0, 0X11D);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x80801470: addiu       $a1, $zero, 0x11D
    ctx->r5 = ADD32(0, 0X11D);
    after_1:
    // 0x80801474: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80801478: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080147C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801480: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801484: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801488: jal         0x8009FFD8
    // 0x8080148C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x8080148C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x80801490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801494: jal         0x800A0CF4
    // 0x80801498: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_3;
    // 0x80801498: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080149C: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x808014A0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808014A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014A8: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x808014AC: jal         0x8009DF18
    // 0x808014B0: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DF18(rdram, ctx);
        goto after_4;
    // 0x808014B0: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_4:
    // 0x808014B4: lui         $a1, 0x3FE6
    ctx->r5 = S32(0X3FE6 << 16);
    // 0x808014B8: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808014BC: jal         0x8009D820
    // 0x808014C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D820(rdram, ctx);
        goto after_5;
    // 0x808014C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808014C4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808014C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808014CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014D0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808014D4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808014D8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808014DC: jal         0x80085490
    // 0x808014E0: nop

    _bamotor_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x808014E0: nop

    after_6:
    // 0x808014E4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x808014E8: addiu       $at, $zero, 0xE0
    ctx->r1 = ADD32(0, 0XE0);
    // 0x808014EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014F0: bne         $t7, $at, L_80801508
    if (ctx->r15 != ctx->r1) {
        // 0x808014F4: nop
    
            goto L_80801508;
    }
    // 0x808014F4: nop

    // 0x808014F8: jal         0x80083A78
    // 0x808014FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bssplat_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x808014FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801500: b           L_80801510
    // 0x80801504: nop

        goto L_80801510;
    // 0x80801504: nop

L_80801508:
    // 0x80801508: jal         0x800A17A8
    // 0x8080150C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800A17A8(rdram, ctx);
        goto after_8;
    // 0x8080150C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_8:
L_80801510:
    // 0x80801510: jal         0x800A1718
    // 0x80801514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A1718(rdram, ctx);
        goto after_9;
    // 0x80801514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80801518: bne         $v0, $zero, L_80801528
    if (ctx->r2 != 0) {
        // 0x8080151C: nop
    
            goto L_80801528;
    }
    // 0x8080151C: nop

    // 0x80801520: jal         0x80085208
    // 0x80801524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x80801524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_80801528:
    // 0x80801528: jal         0x808013BC
    // 0x8080152C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808013BC_bskazfly(rdram, ctx);
        goto after_11;
    // 0x8080152C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80801530: jal         0x8008E944
    // 0x80801534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_12;
    // 0x80801534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80801538: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    // 0x8080153C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801540: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801544: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801548: jr          $ra
    // 0x8080154C: nop

    return;
    // 0x8080154C: nop

;}
RECOMP_FUNC void bsrest_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800584: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800588: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080058C: jal         0x808003FC
    // 0x80800590: nop

    static_344_808003FC(rdram, ctx);
        goto after_0;
    // 0x80800590: nop

    after_0:
    // 0x80800594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800598: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080059C: jr          $ra
    // 0x808005A0: nop

    return;
    // 0x808005A0: nop

;}
RECOMP_FUNC void func_808006D0_subaddierouteDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006D0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x808006D4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x808006D8: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x808006DC: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x808006E0: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x808006E4: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x808006E8: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x808006EC: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x808006F0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808006F4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808006F8: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x808006FC: lw          $s4, 0x70($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X70);
    // 0x80800700: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80800704: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x80800708: srl         $t6, $s4, 25
    ctx->r14 = S32(U32(ctx->r20) >> 25);
    // 0x8080070C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800710: addiu       $s4, $t6, -0x1
    ctx->r20 = ADD32(ctx->r14, -0X1);
    // 0x80800714: jal         0x800CC61C
    // 0x80800718: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800CC61C(rdram, ctx);
        goto after_0;
    // 0x80800718: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_0:
    // 0x8080071C: bne         $v0, $zero, L_8080072C
    if (ctx->r2 != 0) {
        // 0x80800720: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8080072C;
    }
    // 0x80800720: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800724: b           L_808007FC
    // 0x80800728: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808007FC;
    // 0x80800728: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080072C:
    // 0x8080072C: addiu       $s5, $sp, 0x64
    ctx->r21 = ADD32(ctx->r29, 0X64);
    // 0x80800730: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800734: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80800738: jal         0x800EEB9C
    // 0x8080073C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800EEB9C(rdram, ctx);
        goto after_1;
    // 0x8080073C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x80800740: addiu       $s0, $s1, -0x1
    ctx->r16 = ADD32(ctx->r17, -0X1);
    // 0x80800744: bltz        $s0, L_808007F8
    if (SIGNED(ctx->r16) < 0) {
        // 0x80800748: addiu       $s1, $s2, 0x4
        ctx->r17 = ADD32(ctx->r18, 0X4);
            goto L_808007F8;
    }
    // 0x80800748: addiu       $s1, $s2, 0x4
    ctx->r17 = ADD32(ctx->r18, 0X4);
    // 0x8080074C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800750: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800754: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800758: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x8080075C: addiu       $s2, $sp, 0x5C
    ctx->r18 = ADD32(ctx->r29, 0X5C);
    // 0x80800760: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_80800764:
    // 0x80800764: jal         0x800CC684
    // 0x80800768: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800CC684(rdram, ctx);
        goto after_2;
    // 0x80800768: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8080076C: lh          $t7, 0xC($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XC);
    // 0x80800770: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80800774: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800778: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8080077C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80800780: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800784: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800788: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8080078C: jal         0x800F05F8
    // 0x80800790: nop

    func_800F05F8(rdram, ctx);
        goto after_3;
    // 0x80800790: nop

    after_3:
    // 0x80800794: bne         $v0, $s3, L_808007EC
    if (ctx->r2 != ctx->r19) {
        // 0x80800798: lwc1        $f12, 0x5C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
            goto L_808007EC;
    }
    // 0x80800798: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8080079C: c.le.s      $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl <= ctx->f12.fl;
    // 0x808007A0: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    // 0x808007A4: bc1fl       L_808007F0
    if (!c1cs) {
        // 0x808007A8: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_808007F0;
    }
    goto skip_0;
    // 0x808007A8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    skip_0:
    // 0x808007AC: c.le.s      $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl <= ctx->f14.fl;
    // 0x808007B0: nop

    // 0x808007B4: bc1fl       L_808007F0
    if (!c1cs) {
        // 0x808007B8: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_808007F0;
    }
    goto skip_1;
    // 0x808007B8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    skip_1:
    // 0x808007BC: jal         0x800F13F0
    // 0x808007C0: nop

    func_800F13F0(rdram, ctx);
        goto after_4;
    // 0x808007C0: nop

    after_4:
    // 0x808007C4: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x808007C8: nop

    // 0x808007CC: bc1fl       L_808007F0
    if (!c1cs) {
        // 0x808007D0: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_808007F0;
    }
    goto skip_2;
    // 0x808007D0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    skip_2:
    // 0x808007D4: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x808007D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808007DC: lhu         $t8, 0x6($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X6);
    // 0x808007E0: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x808007E4: b           L_808007FC
    // 0x808007E8: sh          $t9, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r25;
        goto L_808007FC;
    // 0x808007E8: sh          $t9, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r25;
L_808007EC:
    // 0x808007EC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_808007F0:
    // 0x808007F0: bgezl       $s0, L_80800764
    if (SIGNED(ctx->r16) >= 0) {
        // 0x808007F4: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80800764;
    }
    goto skip_3;
    // 0x808007F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_3:
L_808007F8:
    // 0x808007F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007FC:
    // 0x808007FC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80800800: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800804: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800808: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8080080C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80800810: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80800814: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80800818: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x8080081C: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80800820: jr          $ra
    // 0x80800824: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80800824: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8001D30C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D30C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001D310: addiu       $v0, $v0, -0x2EA8
    ctx->r2 = ADD32(ctx->r2, -0X2EA8);
    // 0x8001D314: jr          $ra
    // 0x8001D318: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    return;
    // 0x8001D318: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
;}
RECOMP_FUNC void anctrl_getAnimTimer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B2B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008B2B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B2BC: jal         0x8008C0C8
    // 0x8008B2C0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    func_8008C0C8(rdram, ctx);
        goto after_0;
    // 0x8008B2C0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8008B2C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B2C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008B2CC: jr          $ra
    // 0x8008B2D0: nop

    return;
    // 0x8008B2D0: nop

;}
RECOMP_FUNC void bskazstilt_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808010A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010AC: jal         0x8080013C
    // 0x808010B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8080013C_bskazstilt(rdram, ctx);
        goto after_0;
    // 0x808010B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808010B4: jal         0x800839C8
    // 0x808010B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x808010B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808010BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808010C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808010C4: jr          $ra
    // 0x808010C8: nop

    return;
    // 0x808010C8: nop

;}
RECOMP_FUNC void _glcutDll_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088850: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x80088850);
    return;
    // 0x80088854: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void _chlavaslab_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087038: syscall     496
    recomp_syscall_handler(rdram, ctx, 0x80087038);
    return;
    // 0x8008703C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bsmum_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083858: syscall     75
    recomp_syscall_handler(rdram, ctx, 0x80083858);
    return;
    // 0x8008385C: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_80800E0C_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E0C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800E10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E14: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800E18: jal         0x80100094
    // 0x80800E1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800E1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800E20: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800E24: jal         0x80089998
    // 0x80800E28: addiu       $a0, $v0, 0x28
    ctx->r4 = ADD32(ctx->r2, 0X28);
    _sumultiscore_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800E28: addiu       $a0, $v0, 0x28
    ctx->r4 = ADD32(ctx->r2, 0X28);
    after_1:
    // 0x80800E2C: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80800E30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800E34: lhu         $v1, 0x72($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X72);
    // 0x80800E38: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800E3C: beq         $t6, $at, L_80800E5C
    if (ctx->r14 == ctx->r1) {
        // 0x80800E40: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800E5C;
    }
    // 0x80800E40: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800E44: beq         $t6, $at, L_80800EAC
    if (ctx->r14 == ctx->r1) {
        // 0x80800E48: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800EAC;
    }
    // 0x80800E48: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800E4C: beq         $t6, $at, L_80800FB4
    if (ctx->r14 == ctx->r1) {
        // 0x80800E50: nop
    
            goto L_80800FB4;
    }
    // 0x80800E50: nop

    // 0x80800E54: b           L_80801010
    // 0x80800E58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801010;
    // 0x80800E58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800E5C:
    // 0x80800E5C: jal         0x800C954C
    // 0x80800E60: nop

    func_800C954C(rdram, ctx);
        goto after_2;
    // 0x80800E60: nop

    after_2:
    // 0x80800E64: bnel        $v0, $zero, L_80801010
    if (ctx->r2 != 0) {
        // 0x80800E68: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801010;
    }
    goto skip_0;
    // 0x80800E68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800E6C: jal         0x800DA298
    // 0x80800E70: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800E70: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    after_3:
    // 0x80800E74: bne         $v0, $zero, L_8080100C
    if (ctx->r2 != 0) {
        // 0x80800E78: lw          $t7, 0x40($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X40);
            goto L_8080100C;
    }
    // 0x80800E78: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80800E7C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80800E80: addiu       $t8, $zero, 0xB3
    ctx->r24 = ADD32(0, 0XB3);
    // 0x80800E84: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800E88: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    // 0x80800E8C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80800E90: jal         0x8008A208
    // 0x80800E94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80800E94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80800E98: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800E9C: jal         0x80101FDC
    // 0x80800EA0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80800EA0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80800EA4: b           L_80801010
    // 0x80800EA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801010;
    // 0x80800EA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800EAC:
    // 0x80800EAC: lw          $a0, 0x6C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X6C);
    // 0x80800EB0: andi        $t9, $a0, 0x1FF
    ctx->r25 = ctx->r4 & 0X1FF;
    // 0x80800EB4: jal         0x800CEAD0
    // 0x80800EB8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_6;
    // 0x80800EB8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_6:
    // 0x80800EBC: beq         $v0, $zero, L_80800ED4
    if (ctx->r2 == 0) {
        // 0x80800EC0: nop
    
            goto L_80800ED4;
    }
    // 0x80800EC0: nop

    // 0x80800EC4: jal         0x808011BC
    // 0x80800EC8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_808011BC_chmonsterinterior(rdram, ctx);
        goto after_7;
    // 0x80800EC8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_7:
    // 0x80800ECC: b           L_80801010
    // 0x80800ED0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801010;
    // 0x80800ED0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800ED4:
    // 0x80800ED4: jal         0x80089C68
    // 0x80800ED8: addiu       $a0, $zero, 0x453
    ctx->r4 = ADD32(0, 0X453);
    _subaddiefind_entrypoint_9(rdram, ctx);
        goto after_8;
    // 0x80800ED8: addiu       $a0, $zero, 0x453
    ctx->r4 = ADD32(0, 0X453);
    after_8:
    // 0x80800EDC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800EE0: jal         0x80089C68
    // 0x80800EE4: addiu       $a0, $zero, 0x452
    ctx->r4 = ADD32(0, 0X452);
    _subaddiefind_entrypoint_9(rdram, ctx);
        goto after_9;
    // 0x80800EE4: addiu       $a0, $zero, 0x452
    ctx->r4 = ADD32(0, 0X452);
    after_9:
    // 0x80800EE8: addiu       $a0, $zero, 0x454
    ctx->r4 = ADD32(0, 0X454);
    // 0x80800EEC: jal         0x80089C68
    // 0x80800EF0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    _subaddiefind_entrypoint_9(rdram, ctx);
        goto after_10;
    // 0x80800EF0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_10:
    // 0x80800EF4: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80800EF8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80800EFC: addu        $t0, $v0, $v1
    ctx->r8 = ADD32(ctx->r2, ctx->r3);
    // 0x80800F00: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80800F04: slti        $at, $t2, 0x5
    ctx->r1 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
    // 0x80800F08: beq         $at, $zero, L_8080100C
    if (ctx->r1 == 0) {
        // 0x80800F0C: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_8080100C;
    }
    // 0x80800F0C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800F10: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800F14: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800F18: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800F1C: jal         0x800DC178
    // 0x80800F20: nop

    func_800DC178(rdram, ctx);
        goto after_11;
    // 0x80800F20: nop

    after_11:
    // 0x80800F24: jal         0x80088368
    // 0x80800F28: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_12;
    // 0x80800F28: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_12:
    // 0x80800F2C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80800F30: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800F34: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800F38: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800F3C: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    // 0x80800F40: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80800F44: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800F48: jal         0x800D9154
    // 0x80800F4C: nop

    func_800D9154(rdram, ctx);
        goto after_13;
    // 0x80800F4C: nop

    after_13:
    // 0x80800F50: beql        $v0, $zero, L_80801010
    if (ctx->r2 == 0) {
        // 0x80800F54: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801010;
    }
    goto skip_1;
    // 0x80800F54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800F58: jal         0x800DC0C0
    // 0x80800F5C: nop

    func_800DC0C0(rdram, ctx);
        goto after_14;
    // 0x80800F5C: nop

    after_14:
    // 0x80800F60: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800F64: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800F68: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1320, 0X1E2C) << 16);
    // 0x80800F6C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80800F70: nop

    // 0x80800F74: bc1f        L_80800F84
    if (!c1cs) {
        // 0x80800F78: nop
    
            goto L_80800F84;
    }
    // 0x80800F78: nop

    // 0x80800F7C: b           L_80800FA4
    // 0x80800F80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80800FA4;
    // 0x80800F80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80800F84:
    // 0x80800F84: lwc1        $f18, 0x1E2C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1320, 0X1E2C));
    // 0x80800F88: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800F8C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80800F90: nop

    // 0x80800F94: bc1f        L_80800FA4
    if (!c1cs) {
        // 0x80800F98: nop
    
            goto L_80800FA4;
    }
    // 0x80800F98: nop

    // 0x80800F9C: b           L_80800FA4
    // 0x80800FA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80800FA4;
    // 0x80800FA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800FA4:
    // 0x80800FA4: jal         0x80108B04
    // 0x80800FA8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80108B04(rdram, ctx);
        goto after_15;
    // 0x80800FA8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_15:
    // 0x80800FAC: b           L_80801010
    // 0x80800FB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801010;
    // 0x80800FB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800FB4:
    // 0x80800FB4: jal         0x8008A2E8
    // 0x80800FB8: nop

    _susubgame_entrypoint_9(rdram, ctx);
        goto after_16;
    // 0x80800FB8: nop

    after_16:
    // 0x80800FBC: beq         $v0, $zero, L_8080100C
    if (ctx->r2 == 0) {
        // 0x80800FC0: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_8080100C;
    }
    // 0x80800FC0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800FC4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800FC8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800FCC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800FD0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800FD4: jal         0x8008A2C8
    // 0x80800FD8: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_17;
    // 0x80800FD8: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_17:
    // 0x80800FDC: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80800FE0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80800FE4: addiu       $t5, $zero, 0xB3
    ctx->r13 = ADD32(0, 0XB3);
    // 0x80800FE8: lw          $a1, 0x8($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X8);
    // 0x80800FEC: lw          $a2, 0xC($t4)
    ctx->r6 = MEM_W(ctx->r12, 0XC);
    // 0x80800FF0: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x80800FF4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800FF8: jal         0x8008A208
    // 0x80800FFC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_18;
    // 0x80800FFC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_18:
    // 0x80801000: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80801004: jal         0x80101FDC
    // 0x80801008: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_19;
    // 0x80801008: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_19:
L_8080100C:
    // 0x8080100C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801010:
    // 0x80801010: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801014: jr          $ra
    // 0x80801018: nop

    return;
    // 0x80801018: nop

;}
RECOMP_FUNC void chfirefx_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800634: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80800638: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8080063C: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80800640: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80800644: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80800648: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080064C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80800650: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80800654: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80800658: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8080065C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80800660: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800664: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800668: jal         0x80100094
    // 0x8080066C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080066C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800670: lh          $t6, 0x12($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X12);
    // 0x80800674: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x80800678: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080067C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800680: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80800684: jal         0x800F0E00
    // 0x80800688: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    func_800F0E00(rdram, ctx);
        goto after_1;
    // 0x80800688: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    after_1:
    // 0x8080068C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80800690: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800694: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1104, 0X11D8) << 16);
    // 0x80800698: lwc1        $f10, 0x11D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1104, 0X11D8));
    // 0x8080069C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808006A0: addiu       $s5, $s0, 0x4
    ctx->r21 = ADD32(ctx->r16, 0X4);
    // 0x808006A4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808006A8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808006AC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x808006B0: jal         0x800E3E8C
    // 0x808006B4: nop

    func_800E3E8C(rdram, ctx);
        goto after_2;
    // 0x808006B4: nop

    after_2:
    // 0x808006B8: beql        $v0, $zero, L_808007B0
    if (ctx->r2 == 0) {
        // 0x808006BC: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_808007B0;
    }
    goto skip_0;
    // 0x808006BC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x808006C0: lbu         $t8, 0x7E($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X7E);
    // 0x808006C4: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x808006C8: sb          $t9, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r25;
    // 0x808006CC: lh          $t0, 0x8($s4)
    ctx->r8 = MEM_H(ctx->r20, 0X8);
    // 0x808006D0: addiu       $s0, $s4, 0x20
    ctx->r16 = ADD32(ctx->r20, 0X20);
    // 0x808006D4: beql        $t0, $zero, L_808007B0
    if (ctx->r8 == 0) {
        // 0x808006D8: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_808007B0;
    }
    goto skip_1;
    // 0x808006D8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_1:
    // 0x808006DC: jal         0x800D674C
    // 0x808006E0: addiu       $a0, $zero, 0x9CE
    ctx->r4 = ADD32(0, 0X9CE);
    func_800D674C(rdram, ctx);
        goto after_3;
    // 0x808006E0: addiu       $a0, $zero, 0x9CE
    ctx->r4 = ADD32(0, 0X9CE);
    after_3:
    // 0x808006E4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808006E8: jal         0x800E2588
    // 0x808006EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E2588(rdram, ctx);
        goto after_4;
    // 0x808006EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x808006F0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x808006F4: jal         0x800E2594
    // 0x808006F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800E2594(rdram, ctx);
        goto after_5;
    // 0x808006F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x808006FC: jal         0x800E24D8
    // 0x80800700: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E24D8(rdram, ctx);
        goto after_6;
    // 0x80800700: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80800704: lh          $t1, 0x8($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X8);
    // 0x80800708: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8080070C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800710: blez        $t1, L_808007A4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80800714: addiu       $s3, $sp, 0x60
        ctx->r19 = ADD32(ctx->r29, 0X60);
            goto L_808007A4;
    }
    // 0x80800714: addiu       $s3, $sp, 0x60
    ctx->r19 = ADD32(ctx->r29, 0X60);
    // 0x80800718: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8080071C: addiu       $s1, $sp, 0x6C
    ctx->r17 = ADD32(ctx->r29, 0X6C);
    // 0x80800720: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
L_80800724:
    // 0x80800724: lwc1        $f4, 0x4($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X4);
    // 0x80800728: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080072C: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    // 0x80800730: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800734: nop

    // 0x80800738: mul.s       $f20, $f6, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8080073C: jal         0x800EE88C
    // 0x80800740: nop

    func_800EE88C(rdram, ctx);
        goto after_7;
    // 0x80800740: nop

    after_7:
    // 0x80800744: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800748: jal         0x800EF04C
    // 0x8080074C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EF04C(rdram, ctx);
        goto after_8;
    // 0x8080074C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_8:
    // 0x80800750: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800754: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800758: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8080075C: jal         0x800EFA4C
    // 0x80800760: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800EFA4C(rdram, ctx);
        goto after_9;
    // 0x80800760: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_9:
    // 0x80800764: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800768: lh          $a2, 0x6($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X6);
    // 0x8080076C: addiu       $t3, $zero, 0xC0
    ctx->r11 = ADD32(0, 0XC0);
    // 0x80800770: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800774: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80800778: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8080077C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800780: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800784: jal         0x800E2720
    // 0x80800788: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_800E2720(rdram, ctx);
        goto after_10;
    // 0x80800788: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_10:
    // 0x8080078C: lh          $t4, 0x8($s4)
    ctx->r12 = MEM_H(ctx->r20, 0X8);
    // 0x80800790: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800794: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80800798: slt         $at, $s2, $t4
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8080079C: bnel        $at, $zero, L_80800724
    if (ctx->r1 != 0) {
        // 0x808007A0: lwc1        $f18, 0x10($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
            goto L_80800724;
    }
    goto skip_2;
    // 0x808007A0: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    skip_2:
L_808007A4:
    // 0x808007A4: jal         0x800E2A14
    // 0x808007A8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800E2A14(rdram, ctx);
        goto after_11;
    // 0x808007A8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_11:
    // 0x808007AC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_808007B0:
    // 0x808007B0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808007B4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x808007B8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x808007BC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x808007C0: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x808007C4: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x808007C8: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x808007CC: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x808007D0: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x808007D4: jr          $ra
    // 0x808007D8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x808007D8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80800E58_chkingjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E58: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800E5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E60: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800E64: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800E68: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800E6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800E70: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800E74: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800E78: bnel        $t7, $at, L_80800EE4
    if (ctx->r15 != ctx->r1) {
        // 0x80800E7C: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_80800EE4;
    }
    goto skip_0;
    // 0x80800E7C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    skip_0:
    // 0x80800E80: lw          $t8, 0x64($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X64);
    // 0x80800E84: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x80800E88: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800E8C: sll         $t0, $t8, 12
    ctx->r8 = S32(ctx->r24 << 12);
    // 0x80800E90: bgez        $t0, L_80800EE0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800E94: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1296, 0X12C0) << 16);
            goto L_80800EE0;
    }
    // 0x80800E94: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1296, 0X12C0) << 16);
    // 0x80800E98: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1296, 0X12E8) << 16);
    // 0x80800E9C: addiu       $a3, $a3, 0x12E8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1296, 0X12E8));
    // 0x80800EA0: jal         0x80089D28
    // 0x80800EA4: addiu       $a2, $a2, 0x12C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1296, 0X12C0));
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800EA4: addiu       $a2, $a2, 0x12C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1296, 0X12C0));
    after_0:
    // 0x80800EA8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1296, 0X12D0) << 16);
    // 0x80800EAC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1296, 0X12F8) << 16);
    // 0x80800EB0: addiu       $a3, $a3, 0x12F8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1296, 0X12F8));
    // 0x80800EB4: addiu       $a2, $a2, 0x12D0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1296, 0X12D0));
    // 0x80800EB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800EBC: jal         0x80089D28
    // 0x80800EC0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800EC0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80800EC4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1296, 0X12DC) << 16);
    // 0x80800EC8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1296, 0X1304) << 16);
    // 0x80800ECC: addiu       $a3, $a3, 0x1304
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1296, 0X1304));
    // 0x80800ED0: addiu       $a2, $a2, 0x12DC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1296, 0X12DC));
    // 0x80800ED4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800ED8: jal         0x80089D28
    // 0x80800EDC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800EDC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
L_80800EE0:
    // 0x80800EE0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
L_80800EE4:
    // 0x80800EE4: lui         $a1, 0xC38C
    ctx->r5 = S32(0XC38C << 16);
    // 0x80800EE8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800EEC: lui         $a3, 0xC37A
    ctx->r7 = S32(0XC37A << 16);
    // 0x80800EF0: jal         0x800EFA4C
    // 0x80800EF4: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x80800EF4: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    after_3:
    // 0x80800EF8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800EFC: lui         $a1, 0x432A
    ctx->r5 = S32(0X432A << 16);
    // 0x80800F00: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    // 0x80800F04: jal         0x800EFA4C
    // 0x80800F08: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x80800F08: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    after_4:
    // 0x80800F0C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800F10: jal         0x800EF334
    // 0x80800F14: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    func_800EF334(rdram, ctx);
        goto after_5;
    // 0x80800F14: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_5:
    // 0x80800F18: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800F1C: jal         0x800EF334
    // 0x80800F20: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    func_800EF334(rdram, ctx);
        goto after_6;
    // 0x80800F20: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_6:
    // 0x80800F24: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800F28: jal         0x800EF04C
    // 0x80800F2C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x80800F2C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x80800F30: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800F34: jal         0x800EF04C
    // 0x80800F38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_8;
    // 0x80800F38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x80800F3C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800F40: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800F44: jal         0x80089F28
    // 0x80800F48: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    _sudeflect_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80800F48: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_9:
    // 0x80800F4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F50: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800F54: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800F58: jr          $ra
    // 0x80800F5C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800F5C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800BED70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BED70: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800BED74: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800BED78: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800BED7C: addiu       $s0, $s0, -0x7A50
    ctx->r16 = ADD32(ctx->r16, -0X7A50);
    // 0x800BED80: lbu         $t6, 0x2A($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2A);
    // 0x800BED84: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800BED88: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800BED8C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800BED90: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800BED94: beq         $t6, $zero, L_800BEDF4
    if (ctx->r14 == 0) {
        // 0x800BED98: sw          $a3, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r7;
            goto L_800BEDF4;
    }
    // 0x800BED98: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800BED9C: jal         0x800EFD24
    // 0x800BEDA0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x800BEDA0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x800BEDA4: lbu         $t7, 0x29($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X29);
    // 0x800BEDA8: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800BEDAC: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800BEDB0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BEDB4: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x800BEDB8: lw          $a1, 0x10($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X10);
    // 0x800BEDBC: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800BEDC0: addiu       $t0, $sp, 0x34
    ctx->r8 = ADD32(ctx->r29, 0X34);
    // 0x800BEDC4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800BEDC8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800BEDCC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800BEDD0: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800BEDD4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800BEDD8: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800BEDDC: jal         0x800AD2C8
    // 0x800BEDE0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    func_800AD2C8(rdram, ctx);
        goto after_1;
    // 0x800BEDE0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800BEDE4: beql        $v0, $zero, L_800BEDF8
    if (ctx->r2 == 0) {
        // 0x800BEDE8: lbu         $t3, 0x77($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X77);
            goto L_800BEDF8;
    }
    goto skip_0;
    // 0x800BEDE8: lbu         $t3, 0x77($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X77);
    skip_0:
    // 0x800BEDEC: b           L_800BEE30
    // 0x800BEDF0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800BEE30;
    // 0x800BEDF0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800BEDF4:
    // 0x800BEDF4: lbu         $t3, 0x77($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X77);
L_800BEDF8:
    // 0x800BEDF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BEDFC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800BEE00: beq         $t3, $zero, L_800BEE2C
    if (ctx->r11 == 0) {
        // 0x800BEE04: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800BEE2C;
    }
    // 0x800BEE04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BEE08: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800BEE0C: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800BEE10: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800BEE14: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800BEE18: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800BEE1C: jal         0x80087FA0
    // 0x800BEE20: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    _gcmapsects_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x800BEE20: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x800BEE24: b           L_800BEE30
    // 0x800BEE28: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800BEE30;
    // 0x800BEE28: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800BEE2C:
    // 0x800BEE2C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800BEE30:
    // 0x800BEE30: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800BEE34: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800BEE38: jr          $ra
    // 0x800BEE3C: nop

    return;
    // 0x800BEE3C: nop

;}
RECOMP_FUNC void __baanim_update_scaleToHorizontalVelocity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C2A8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8008C2AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008C2B0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8008C2B4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8008C2B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008C2BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008C2C0: lbu         $t6, 0x38($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X38);
    // 0x8008C2C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008C2C8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8008C2CC: beql        $t6, $zero, L_8008C2E0
    if (ctx->r14 == 0) {
        // 0x8008C2D0: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_8008C2E0;
    }
    goto skip_0;
    // 0x8008C2D0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x8008C2D4: b           L_8008C2E4
    // 0x8008C2D8: lwc1        $f2, 0x34($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X34);
        goto L_8008C2E4;
    // 0x8008C2D8: lwc1        $f2, 0x34($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8008C2DC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_8008C2E0:
    // 0x8008C2E0: nop

L_8008C2E4:
    // 0x8008C2E4: jal         0x8009BB24
    // 0x8008C2E8: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    func_8009BB24(rdram, ctx);
        goto after_0;
    // 0x8008C2E8: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x8008C2EC: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8008C2F0: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8008C2F4: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8008C2F8: nop

    // 0x8008C2FC: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8008C300: jal         0x8002DCA0
    // 0x8008C304: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8008C304: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x8008C308: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8008C30C: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8008C310: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8008C314: lwc1        $f8, 0x2C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8008C318: lwc1        $f16, 0x30($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8008C31C: lwc1        $f14, 0x24($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8008C320: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8008C324: lw          $a2, 0x28($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X28);
    // 0x8008C328: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8008C32C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8008C330: jal         0x800F1198
    // 0x8008C334: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F1198(rdram, ctx);
        goto after_2;
    // 0x8008C334: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8008C338: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8008C33C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8008C340: lwc1        $f14, 0x1C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8008C344: jal         0x800F0D50
    // 0x8008C348: lw          $a2, 0x20($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X20);
    func_800F0D50(rdram, ctx);
        goto after_3;
    // 0x8008C348: lw          $a2, 0x20($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X20);
    after_3:
    // 0x8008C34C: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8008C350: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8008C354: jal         0x8008B1BC
    // 0x8008C358: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x8008C358: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_4:
    // 0x8008C35C: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8008C360: jal         0x8008ADE4
    // 0x8008C364: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    func_8008ADE4(rdram, ctx);
        goto after_5;
    // 0x8008C364: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_5:
    // 0x8008C368: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008C36C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8008C370: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8008C374: jr          $ra
    // 0x8008C378: nop

    return;
    // 0x8008C378: nop

;}
RECOMP_FUNC void badrone_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A4: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x808001A8: jr          $ra
    // 0x808001AC: sb          $a1, 0x5($t6)
    MEM_B(0X5, ctx->r14) = ctx->r5;
    return;
    // 0x808001AC: sb          $a1, 0x5($t6)
    MEM_B(0X5, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_808023A0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808023A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808023A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808023A8: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x808023AC: jal         0x800A4C68
    // 0x808023B0: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    func_800A4C68(rdram, ctx);
        goto after_0;
    // 0x808023B0: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    after_0:
    // 0x808023B4: jal         0x800A8AF0
    // 0x808023B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800A8AF0(rdram, ctx);
        goto after_1;
    // 0x808023B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808023BC: lui         $at, 0x4318
    ctx->r1 = S32(0X4318 << 16);
    // 0x808023C0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808023C4: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808023C8: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x808023CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808023D0: lwc1        $f4, 0xB8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XB8);
    // 0x808023D4: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808023D8: addiu       $v0, $v0, 0xB8
    ctx->r2 = ADD32(ctx->r2, 0XB8);
    // 0x808023DC: sub.s       $f12, $f14, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x808023E0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x808023E4: mul.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x808023E8: jal         0x80013B7C
    // 0x808023EC: nop

    func_80013B7C(rdram, ctx);
        goto after_2;
    // 0x808023EC: nop

    after_2:
    // 0x808023F0: jal         0x80013728
    // 0x808023F4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013728(rdram, ctx);
        goto after_3;
    // 0x808023F4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x808023F8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x808023FC: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x80802400: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80802404: swc1        $f0, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f0.u32l;
    // 0x80802408: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8080240C: lwc1        $f10, 0x4($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80802410: jal         0x80013B7C
    // 0x80802414: sub.s       $f12, $f14, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f10.fl;
    func_80013B7C(rdram, ctx);
        goto after_4;
    // 0x80802414: sub.s       $f12, $f14, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f10.fl;
    after_4:
    // 0x80802418: jal         0x80013728
    // 0x8080241C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013728(rdram, ctx);
        goto after_5;
    // 0x8080241C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_5:
    // 0x80802420: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80802424: swc1        $f0, 0xC8($t9)
    MEM_W(0XC8, ctx->r25) = ctx->f0.u32l;
    // 0x80802428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080242C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80802430: jr          $ra
    // 0x80802434: nop

    return;
    // 0x80802434: nop

;}
RECOMP_FUNC void func_80801554_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801554: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80801558: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080155C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801560: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80801564: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801568: jal         0x80100094
    // 0x8080156C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080156C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801570: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80801574: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80801578: addiu       $a1, $a1, 0x17D0
    ctx->r5 = ADD32(ctx->r5, 0X17D0);
    // 0x8080157C: jal         0x80101808
    // 0x80801580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101808(rdram, ctx);
        goto after_1;
    // 0x80801580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801584: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80801588: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x8080158C: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80801590: bgezl       $t8, L_808015E4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80801594: lw          $t9, 0x5C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X5C);
            goto L_808015E4;
    }
    goto skip_0;
    // 0x80801594: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    skip_0:
    // 0x80801598: jal         0x80104130
    // 0x8080159C: nop

    func_80104130(rdram, ctx);
        goto after_2;
    // 0x8080159C: nop

    after_2:
    // 0x808015A0: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x808015A4: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x808015A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808015AC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808015B0: jal         0x800DBEFC
    // 0x808015B4: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    func_800DBEFC(rdram, ctx);
        goto after_3;
    // 0x808015B4: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    after_3:
    // 0x808015B8: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x808015BC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808015C0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808015C4: jal         0x800DBEFC
    // 0x808015C8: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    func_800DBEFC(rdram, ctx);
        goto after_4;
    // 0x808015C8: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    after_4:
    // 0x808015CC: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x808015D0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808015D4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x808015D8: jal         0x800DBEFC
    // 0x808015DC: addiu       $a2, $a2, 0x34
    ctx->r6 = ADD32(ctx->r6, 0X34);
    func_800DBEFC(rdram, ctx);
        goto after_5;
    // 0x808015DC: addiu       $a2, $a2, 0x34
    ctx->r6 = ADD32(ctx->r6, 0X34);
    after_5:
    // 0x808015E0: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
L_808015E4:
    // 0x808015E4: beql        $t9, $zero, L_808017D0
    if (ctx->r25 == 0) {
        // 0x808015E8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808017D0;
    }
    goto skip_1;
    // 0x808015E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x808015EC: lhu         $t0, 0x72($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X72);
    // 0x808015F0: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x808015F4: slti        $at, $t1, 0x10
    ctx->r1 = SIGNED(ctx->r9) < 0X10 ? 1 : 0;
    // 0x808015F8: beql        $at, $zero, L_808017D0
    if (ctx->r1 == 0) {
        // 0x808015FC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808017D0;
    }
    goto skip_2;
    // 0x808015FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80801600: jal         0x800B27E0
    // 0x80801604: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800B27E0(rdram, ctx);
        goto after_6;
    // 0x80801604: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_6:
    // 0x80801608: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8080160C: jal         0x800D674C
    // 0x80801610: addiu       $a0, $zero, 0x637
    ctx->r4 = ADD32(0, 0X637);
    func_800D674C(rdram, ctx);
        goto after_7;
    // 0x80801610: addiu       $a0, $zero, 0x637
    ctx->r4 = ADD32(0, 0X637);
    after_7:
    // 0x80801614: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80801618: jal         0x800EFD24
    // 0x8080161C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_800EFD24(rdram, ctx);
        goto after_8;
    // 0x8080161C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_8:
    // 0x80801620: jal         0x801040A8
    // 0x80801624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801040A8(rdram, ctx);
        goto after_9;
    // 0x80801624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80801628: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080162C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80801630: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80801634: jal         0x800AE630
    // 0x80801638: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    func_800AE630(rdram, ctx);
        goto after_10;
    // 0x80801638: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    after_10:
    // 0x8080163C: beq         $v0, $zero, L_808016C4
    if (ctx->r2 == 0) {
        // 0x80801640: addiu       $a0, $sp, 0x40
        ctx->r4 = ADD32(ctx->r29, 0X40);
            goto L_808016C4;
    }
    // 0x80801640: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80801644: jal         0x800EF334
    // 0x80801648: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    func_800EF334(rdram, ctx);
        goto after_11;
    // 0x80801648: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    after_11:
    // 0x8080164C: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80801650: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80801654: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x80801658: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8080165C: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80801660: jal         0x800EF5A0
    // 0x80801664: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800EF5A0(rdram, ctx);
        goto after_12;
    // 0x80801664: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_12:
    // 0x80801668: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8080166C: jal         0x800EF04C
    // 0x80801670: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_13;
    // 0x80801670: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_13:
    // 0x80801674: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080167C: jal         0x80089C90
    // 0x80801680: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x80801680: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    after_14:
    // 0x80801684: jal         0x800DF410
    // 0x80801688: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF410(rdram, ctx);
        goto after_15;
    // 0x80801688: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_15:
    // 0x8080168C: jal         0x800DF830
    // 0x80801690: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF830(rdram, ctx);
        goto after_16;
    // 0x80801690: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_16:
    // 0x80801694: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80801698: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080169C: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808016A0: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x808016A4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808016A8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808016AC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x808016B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808016B4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808016B8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x808016BC: jal         0x800DE448
    // 0x808016C0: nop

    func_800DE448(rdram, ctx);
        goto after_17;
    // 0x808016C0: nop

    after_17:
L_808016C4:
    // 0x808016C4: addiu       $t3, $s0, 0x4
    ctx->r11 = ADD32(ctx->r16, 0X4);
    // 0x808016C8: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x808016CC: jal         0x801040A8
    // 0x808016D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801040A8(rdram, ctx);
        goto after_18;
    // 0x808016D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808016D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808016D8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x808016DC: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x808016E0: jal         0x800AE630
    // 0x808016E4: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    func_800AE630(rdram, ctx);
        goto after_19;
    // 0x808016E4: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    after_19:
    // 0x808016E8: beq         $v0, $zero, L_80801778
    if (ctx->r2 == 0) {
        // 0x808016EC: addiu       $a0, $sp, 0x40
        ctx->r4 = ADD32(ctx->r29, 0X40);
            goto L_80801778;
    }
    // 0x808016EC: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808016F0: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x808016F4: addiu       $t4, $s0, 0x44
    ctx->r12 = ADD32(ctx->r16, 0X44);
    // 0x808016F8: jal         0x800EF334
    // 0x808016FC: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    func_800EF334(rdram, ctx);
        goto after_20;
    // 0x808016FC: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    after_20:
    // 0x80801700: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80801704: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80801708: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8080170C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80801710: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80801714: jal         0x800EF5A0
    // 0x80801718: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800EF5A0(rdram, ctx);
        goto after_21;
    // 0x80801718: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_21:
    // 0x8080171C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80801720: jal         0x800EF04C
    // 0x80801724: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EF04C(rdram, ctx);
        goto after_22;
    // 0x80801724: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_22:
    // 0x80801728: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080172C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801730: jal         0x80089C90
    // 0x80801734: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_23;
    // 0x80801734: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    after_23:
    // 0x80801738: jal         0x800DF410
    // 0x8080173C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF410(rdram, ctx);
        goto after_24;
    // 0x8080173C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_24:
    // 0x80801740: jal         0x800DF830
    // 0x80801744: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF830(rdram, ctx);
        goto after_25;
    // 0x80801744: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_25:
    // 0x80801748: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x8080174C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801750: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80801754: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80801758: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8080175C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80801760: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80801764: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80801768: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8080176C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80801770: jal         0x800DE448
    // 0x80801774: nop

    func_800DE448(rdram, ctx);
        goto after_26;
    // 0x80801774: nop

    after_26:
L_80801778:
    // 0x80801778: jal         0x80089C90
    // 0x8080177C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_27;
    // 0x8080177C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80801780: jal         0x800DF410
    // 0x80801784: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF410(rdram, ctx);
        goto after_28;
    // 0x80801784: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_28:
    // 0x80801788: jal         0x800DF830
    // 0x8080178C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF830(rdram, ctx);
        goto after_29;
    // 0x8080178C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_29:
    // 0x80801790: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(832, 0X2D4C) << 16);
    // 0x80801794: lwc1        $f18, 0x2D4C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(832, 0X2D4C));
    // 0x80801798: lwc1        $f16, 0x28($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8080179C: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x808017A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808017A4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808017A8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x808017AC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808017B0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x808017B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808017B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808017BC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808017C0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808017C4: jal         0x800DE448
    // 0x808017C8: nop

    func_800DE448(rdram, ctx);
        goto after_30;
    // 0x808017C8: nop

    after_30:
    // 0x808017CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808017D0:
    // 0x808017D0: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
L_808017D4:
    // 0x808017D4: lw          $a0, 0x43C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X43C);
    // 0x808017D8: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x808017DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808017E0: beql        $a0, $zero, L_80801800
    if (ctx->r4 == 0) {
        // 0x808017E4: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80801800;
    }
    goto skip_3;
    // 0x808017E4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_3:
    // 0x808017E8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808017EC: jal         0x800BC358
    // 0x808017F0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_800BC358(rdram, ctx);
        goto after_31;
    // 0x808017F0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_31:
    // 0x808017F4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x808017F8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x808017FC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80801800:
    // 0x80801800: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80801804: bne         $v0, $at, L_808017D4
    if (ctx->r2 != ctx->r1) {
        // 0x80801808: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_808017D4;
    }
    // 0x80801808: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8080180C: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80801810: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x80801814: lw          $a0, 0x434($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X434);
    // 0x80801818: beql        $a0, $zero, L_8080182C
    if (ctx->r4 == 0) {
        // 0x8080181C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080182C;
    }
    goto skip_4;
    // 0x8080181C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80801820: jal         0x800BC358
    // 0x80801824: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BC358(rdram, ctx);
        goto after_32;
    // 0x80801824: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_32:
    // 0x80801828: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080182C:
    // 0x8080182C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801830: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80801834: jr          $ra
    // 0x80801838: nop

    return;
    // 0x80801838: nop

;}
RECOMP_FUNC void chhotwatersteam_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1428, 0X240) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x240
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1428, 0X240));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x240
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1428, 0X240));
;}
RECOMP_FUNC void func_80800000_chfantasyonion(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800004: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800008: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800014: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800018: jal         0x800EE7F8
    // 0x8080001C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8080001C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800020: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: jal         0x800EE7F8
    // 0x80800028: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800028: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x8080002C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800030: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800034: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x80800038: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080003C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800040: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800044: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800048: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080004C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800050: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80800054: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x80800058: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8080005C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800060: jal         0x800BEF00
    // 0x80800064: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    func_800BEF00(rdram, ctx);
        goto after_2;
    // 0x80800064: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x80800068: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8080006C: lw          $v1, 0x18($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X18);
    // 0x80800070: bnel        $v1, $zero, L_808000A0
    if (ctx->r3 != 0) {
        // 0x80800074: andi        $a0, $v1, 0xFF
        ctx->r4 = ctx->r3 & 0XFF;
            goto L_808000A0;
    }
    goto skip_0;
    // 0x80800074: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    skip_0:
    // 0x80800078: jal         0x800E8714
    // 0x8080007C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E8714(rdram, ctx);
        goto after_3;
    // 0x8080007C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80800080: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80800084: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80800088: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x8080008C: jal         0x800E8870
    // 0x80800090: sw          $v0, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r2;
    func_800E8870(rdram, ctx);
        goto after_4;
    // 0x80800090: sw          $v0, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r2;
    after_4:
    // 0x80800094: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80800098: lw          $v1, 0x18($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X18);
    // 0x8080009C: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
L_808000A0:
    // 0x808000A0: jal         0x800E8830
    // 0x808000A4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800E8830(rdram, ctx);
        goto after_5;
    // 0x808000A4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_5:
    // 0x808000A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000AC: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808000B0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808000B4: jr          $ra
    // 0x808000B8: nop

    return;
    // 0x808000B8: nop

;}
RECOMP_FUNC void func_808008BC_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808008C8: jal         0x8009BF5C
    // 0x808008CC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_0;
    // 0x808008CC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x808008D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808008D4: jal         0x8009C4CC
    // 0x808008D8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_1;
    // 0x808008D8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x808008DC: jal         0x808000F0
    // 0x808008E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808000F0_bswasher(rdram, ctx);
        goto after_2;
    // 0x808008E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808008E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008EC: jr          $ra
    // 0x808008F0: nop

    return;
    // 0x808008F0: nop

;}
RECOMP_FUNC void func_808002AC_chbabydino(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002B0: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x808002B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002B8: beq         $a1, $at, L_80800354
    if (ctx->r5 == ctx->r1) {
        // 0x808002BC: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800354;
    }
    // 0x808002BC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808002C0: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808002C4: beq         $a1, $at, L_808002F4
    if (ctx->r5 == ctx->r1) {
        // 0x808002C8: addiu       $v0, $sp, 0x28
        ctx->r2 = ADD32(ctx->r29, 0X28);
            goto L_808002F4;
    }
    // 0x808002C8: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x808002CC: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x808002D0: beq         $a1, $at, L_80800308
    if (ctx->r5 == ctx->r1) {
        // 0x808002D4: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800308;
    }
    // 0x808002D4: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808002D8: beq         $a1, $at, L_80800318
    if (ctx->r5 == ctx->r1) {
        // 0x808002DC: addiu       $a2, $zero, 0x39
        ctx->r6 = ADD32(0, 0X39);
            goto L_80800318;
    }
    // 0x808002DC: addiu       $a2, $zero, 0x39
    ctx->r6 = ADD32(0, 0X39);
    // 0x808002E0: addiu       $at, $zero, 0xB8
    ctx->r1 = ADD32(0, 0XB8);
    // 0x808002E4: beq         $a1, $at, L_80800370
    if (ctx->r5 == ctx->r1) {
        // 0x808002E8: lw          $v0, 0x28($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X28);
            goto L_80800370;
    }
    // 0x808002E8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x808002EC: b           L_808003AC
    // 0x808002F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003AC;
    // 0x808002F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002F4:
    // 0x808002F4: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808002F8: jal         0x808003BC
    // 0x808002FC: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_808003BC_chbabydino(rdram, ctx);
        goto after_0;
    // 0x808002FC: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_0:
    // 0x80800300: b           L_808003AC
    // 0x80800304: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003AC;
    // 0x80800304: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800308:
    // 0x80800308: jal         0x808005F0
    // 0x8080030C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_808005F0_chbabydino(rdram, ctx);
        goto after_1;
    // 0x8080030C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800310: b           L_808003B0
    // 0x80800314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003B0;
    // 0x80800314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800318:
    // 0x80800318: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080031C: jal         0x800897C0
    // 0x80800320: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80800320: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x80800324: jal         0x80089828
    // 0x80800328: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _suexpression_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x80800328: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8080032C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800330: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800334: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x80800338: jal         0x800897E8
    // 0x8080033C: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_4;
    // 0x8080033C: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_4:
    // 0x80800340: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800344: jal         0x80089810
    // 0x80800348: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    _suexpression_entrypoint_17(rdram, ctx);
        goto after_5;
    // 0x80800348: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_5:
    // 0x8080034C: b           L_808003AC
    // 0x80800350: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003AC;
    // 0x80800350: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800354:
    // 0x80800354: jal         0x801015D0
    // 0x80800358: nop

    func_801015D0(rdram, ctx);
        goto after_6;
    // 0x80800358: nop

    after_6:
    // 0x8080035C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800360: jal         0x800DF744
    // 0x80800364: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_7;
    // 0x80800364: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800368: b           L_808003AC
    // 0x8080036C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003AC;
    // 0x8080036C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800370:
    // 0x80800370: andi        $t6, $v0, 0xFFFF
    ctx->r14 = ctx->r2 & 0XFFFF;
    // 0x80800374: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800378: bnel        $t6, $at, L_808003AC
    if (ctx->r14 != ctx->r1) {
        // 0x8080037C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808003AC;
    }
    goto skip_0;
    // 0x8080037C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800380: jal         0x800DA298
    // 0x80800384: addiu       $a0, $zero, 0x98
    ctx->r4 = ADD32(0, 0X98);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x80800384: addiu       $a0, $zero, 0x98
    ctx->r4 = ADD32(0, 0X98);
    after_8:
    // 0x80800388: beq         $v0, $zero, L_80800398
    if (ctx->r2 == 0) {
        // 0x8080038C: addiu       $v1, $zero, 0x107D
        ctx->r3 = ADD32(0, 0X107D);
            goto L_80800398;
    }
    // 0x8080038C: addiu       $v1, $zero, 0x107D
    ctx->r3 = ADD32(0, 0X107D);
    // 0x80800390: b           L_808003AC
    // 0x80800394: addiu       $v0, $zero, 0x107F
    ctx->r2 = ADD32(0, 0X107F);
        goto L_808003AC;
    // 0x80800394: addiu       $v0, $zero, 0x107F
    ctx->r2 = ADD32(0, 0X107F);
L_80800398:
    // 0x80800398: b           L_808003AC
    // 0x8080039C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_808003AC;
    // 0x8080039C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808003A0: b           L_808003AC
    // 0x808003A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003AC;
    // 0x808003A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808003A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003AC:
    // 0x808003AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003B0:
    // 0x808003B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003B4: jr          $ra
    // 0x808003B8: nop

    return;
    // 0x808003B8: nop

;}
RECOMP_FUNC void func_80800000_subaddiedialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: andi        $t6, $a2, 0x7
    ctx->r14 = ctx->r6 & 0X7;
    // 0x80800008: beq         $t6, $zero, L_80800020
    if (ctx->r14 == 0) {
        // 0x8080000C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800020;
    }
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: jal         0x8010CAC0
    // 0x80800014: nop

    func_8010CAC0(rdram, ctx);
        goto after_0;
    // 0x80800014: nop

    after_0:
    // 0x80800018: b           L_80800030
    // 0x8080001C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800030;
    // 0x8080001C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800020:
    // 0x80800020: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x80800024: jal         0x8010CB0C
    // 0x80800028: addiu       $a3, $zero, -0x96
    ctx->r7 = ADD32(0, -0X96);
    func_8010CB0C(rdram, ctx);
        goto after_1;
    // 0x80800028: addiu       $a3, $zero, -0x96
    ctx->r7 = ADD32(0, -0X96);
    after_1:
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800030:
    // 0x80800030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
