#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void glrecord_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x808000A8: lw          $t6, -0x2A4C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2A4C);
    // 0x808000AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000B8: beq         $t6, $zero, L_808000C8
    if (ctx->r14 == 0) {
        // 0x808000BC: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_808000C8;
    }
    // 0x808000BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808000C0: jal         0x80800130
    // 0x808000C4: nop

    glrecord_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808000C4: nop

    after_0:
L_808000C8:
    // 0x808000C8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x808000CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x808000D0: jal         0x800D5B24
    // 0x808000D4: sb          $t7, -0x2A3C($at)
    MEM_B(-0X2A3C, ctx->r1) = ctx->r15;
    func_800D5B24(rdram, ctx);
        goto after_1;
    // 0x808000D4: sb          $t7, -0x2A3C($at)
    MEM_B(-0X2A3C, ctx->r1) = ctx->r15;
    after_1:
    // 0x808000D8: jal         0x80088268
    // 0x808000DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _gcsectionDll_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x808000DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808000E0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x808000E4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x808000E8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x808000EC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808000F0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x808000F4: addu        $a0, $v0, $t9
    ctx->r4 = ADD32(ctx->r2, ctx->r25);
    // 0x808000F8: jal         0x800D5B34
    // 0x808000FC: addiu       $a0, $a0, 0xC57
    ctx->r4 = ADD32(ctx->r4, 0XC57);
    func_800D5B34(rdram, ctx);
        goto after_3;
    // 0x808000FC: addiu       $a0, $a0, 0xC57
    ctx->r4 = ADD32(ctx->r4, 0XC57);
    after_3:
    // 0x80800100: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80800104: sw          $v0, -0x2A4C($at)
    MEM_W(-0X2A4C, ctx->r1) = ctx->r2;
    // 0x80800108: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8080010C: lw          $v1, -0x2A4C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2A4C);
    // 0x80800110: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800114: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80800118: jal         0x80800064
    // 0x8080011C: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    glrecord_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x8080011C: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    after_4:
    // 0x80800120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800124: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800128: jr          $ra
    // 0x8080012C: nop

    return;
    // 0x8080012C: nop

;}
RECOMP_FUNC void func_8009B4FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B4FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009B500: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009B504: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009B508: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x8009B50C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009B510: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009B514: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x8009B518: lw          $t7, 0xC8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC8);
    // 0x8009B51C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8009B520: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009B524: swc1        $f4, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->f4.u32l;
    // 0x8009B528: lw          $a0, 0xC8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC8);
    // 0x8009B52C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8009B530: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8009B534: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x8009B538: jal         0x800EFA4C
    // 0x8009B53C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x8009B53C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_0:
    // 0x8009B540: lw          $a0, 0xC8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B544: jal         0x800EFD24
    // 0x8009B548: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x8009B548: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x8009B54C: lw          $a0, 0xC8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B550: jal         0x800EFD24
    // 0x8009B554: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x8009B554: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_2:
    // 0x8009B558: lw          $a0, 0xC8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B55C: jal         0x800EFD24
    // 0x8009B560: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EFD24(rdram, ctx);
        goto after_3;
    // 0x8009B560: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_3:
    // 0x8009B564: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8009B568: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009B56C: lw          $t8, 0xC8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009B574: jal         0x8009BC34
    // 0x8009B578: swc1        $f6, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->f6.u32l;
    func_8009BC34(rdram, ctx);
        goto after_4;
    // 0x8009B578: swc1        $f6, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->f6.u32l;
    after_4:
    // 0x8009B57C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009B580: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009B584: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009B588: jr          $ra
    // 0x8009B58C: nop

    return;
    // 0x8009B58C: nop

;}
RECOMP_FUNC void func_808011A4_gcdialogexec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011A4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808011A8: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x808011AC: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x808011B0: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x808011B4: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x808011B8: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x808011BC: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x808011C0: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x808011C4: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x808011C8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x808011CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2594, 0X2E60) << 16);
    // 0x808011D0: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x808011D4: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x808011D8: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x808011DC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x808011E0: lwc1        $f20, 0x2E60($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2594, 0X2E60));
    // 0x808011E4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808011E8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808011EC: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x808011F0: lw          $s6, 0x64($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X64);
    // 0x808011F4: addiu       $s7, $zero, 0x8
    ctx->r23 = ADD32(0, 0X8);
L_808011F8:
    // 0x808011F8: lw          $a0, 0x120($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X120);
    // 0x808011FC: beql        $a0, $zero, L_80801230
    if (ctx->r4 == 0) {
        // 0x80801200: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80801230;
    }
    goto skip_0;
    // 0x80801200: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x80801204: mtc1        $s2, $f4
    ctx->f4.u32l = ctx->r18;
    // 0x80801208: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8080120C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80801210: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801214: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80801218: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x8080121C: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // 0x80801220: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80801224: jal         0x80087B80
    // 0x80801228: nop

    _gczoombox_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80801228: nop

    after_0:
    // 0x8080122C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80801230:
    // 0x80801230: bne         $s0, $s7, L_808011F8
    if (ctx->r16 != ctx->r23) {
        // 0x80801234: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_808011F8;
    }
    // 0x80801234: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80801238: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8080123C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80801240: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80801244: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80801248: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x8080124C: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80801250: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80801254: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80801258: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x8080125C: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x80801260: jr          $ra
    // 0x80801264: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80801264: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80800420_chsilo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800420: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800424: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800428: beq         $a1, $zero, L_80800478
    if (ctx->r5 == 0) {
        // 0x8080042C: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80800478;
    }
    // 0x8080042C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800430: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800434: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80800438: bltzl       $t8, L_808004B0
    if (SIGNED(ctx->r24) < 0) {
        // 0x8080043C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808004B0;
    }
    goto skip_0;
    // 0x8080043C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800440: jal         0x800F54E4
    // 0x80800444: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800444: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800448: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080044C: jal         0x800F7B9C
    // 0x80800450: addiu       $a1, $zero, 0x8B
    ctx->r5 = ADD32(0, 0X8B);
    func_800F7B9C(rdram, ctx);
        goto after_1;
    // 0x80800450: addiu       $a1, $zero, 0x8B
    ctx->r5 = ADD32(0, 0X8B);
    after_1:
    // 0x80800454: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800458: beq         $v0, $at, L_80800468
    if (ctx->r2 == ctx->r1) {
        // 0x8080045C: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80800468;
    }
    // 0x8080045C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800460: b           L_808004B0
    // 0x80800464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004B0;
    // 0x80800464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800468:
    // 0x80800468: lbu         $t0, 0x65($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X65);
    // 0x8080046C: ori         $t1, $t0, 0x8
    ctx->r9 = ctx->r8 | 0X8;
    // 0x80800470: b           L_808004AC
    // 0x80800474: sb          $t1, 0x65($a2)
    MEM_B(0X65, ctx->r6) = ctx->r9;
        goto L_808004AC;
    // 0x80800474: sb          $t1, 0x65($a2)
    MEM_B(0X65, ctx->r6) = ctx->r9;
L_80800478:
    // 0x80800478: lw          $t2, 0x64($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X64);
    // 0x8080047C: sll         $t4, $t2, 12
    ctx->r12 = S32(ctx->r10 << 12);
    // 0x80800480: bgezl       $t4, L_808004B0
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800484: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808004B0;
    }
    goto skip_1;
    // 0x80800484: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80800488: jal         0x800F54E4
    // 0x8080048C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x8080048C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x80800490: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800494: jal         0x800F7B9C
    // 0x80800498: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    func_800F7B9C(rdram, ctx);
        goto after_3;
    // 0x80800498: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    after_3:
    // 0x8080049C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808004A0: lbu         $t5, 0x65($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X65);
    // 0x808004A4: andi        $t6, $t5, 0xFFF7
    ctx->r14 = ctx->r13 & 0XFFF7;
    // 0x808004A8: sb          $t6, 0x65($a2)
    MEM_B(0X65, ctx->r6) = ctx->r14;
L_808004AC:
    // 0x808004AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004B0:
    // 0x808004B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004B8: jr          $ra
    // 0x808004BC: nop

    return;
    // 0x808004BC: nop

;}
RECOMP_FUNC void idglow_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sll         $t7, $a3, 4
    ctx->r15 = S32(ctx->r7 << 4);
    // 0x80800004: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80800008: addu        $v0, $t7, $a1
    ctx->r2 = ADD32(ctx->r15, ctx->r5);
    // 0x8080000C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800010: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x80800014: beq         $at, $zero, L_80800230
    if (ctx->r1 == 0) {
        // 0x80800018: lwc1        $f0, 0x0($t6)
        ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
            goto L_80800230;
    }
    // 0x80800018: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
L_8080001C:
    // 0x8080001C: lbu         $t8, 0xC($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XC);
    // 0x80800020: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800024: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80800028: bgez        $t8, L_8080003C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8080002C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8080003C;
    }
    // 0x8080002C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800030: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800034: nop

    // 0x80800038: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8080003C:
    // 0x8080003C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800040: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800044: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800048: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8080004C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80800050: nop

    // 0x80800054: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80800058: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8080005C: nop

    // 0x80800060: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80800064: beql        $t0, $zero, L_808000B4
    if (ctx->r8 == 0) {
        // 0x80800068: mfc1        $t0, $f16
        ctx->r8 = (int32_t)ctx->f16.u32l;
            goto L_808000B4;
    }
    goto skip_0;
    // 0x80800068: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x8080006C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800070: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800074: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80800078: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8080007C: nop

    // 0x80800080: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80800084: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80800088: nop

    // 0x8080008C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80800090: bne         $t0, $zero, L_808000A8
    if (ctx->r8 != 0) {
        // 0x80800094: nop
    
            goto L_808000A8;
    }
    // 0x80800094: nop

    // 0x80800098: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x8080009C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808000A0: b           L_808000C0
    // 0x808000A4: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_808000C0;
    // 0x808000A4: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_808000A8:
    // 0x808000A8: b           L_808000C0
    // 0x808000AC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_808000C0;
    // 0x808000AC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x808000B0: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
L_808000B4:
    // 0x808000B4: nop

    // 0x808000B8: bltz        $t0, L_808000A8
    if (SIGNED(ctx->r8) < 0) {
        // 0x808000BC: nop
    
            goto L_808000A8;
    }
    // 0x808000BC: nop

L_808000C0:
    // 0x808000C0: sb          $t0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r8;
    // 0x808000C4: lbu         $t1, 0xD($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0XD);
    // 0x808000C8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x808000CC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808000D0: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x808000D4: bgez        $t1, L_808000E8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808000D8: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_808000E8;
    }
    // 0x808000D8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808000DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000E0: nop

    // 0x808000E4: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_808000E8:
    // 0x808000E8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x808000EC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x808000F0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808000F4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x808000F8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x808000FC: nop

    // 0x80800100: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800104: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80800108: nop

    // 0x8080010C: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80800110: beql        $t3, $zero, L_80800160
    if (ctx->r11 == 0) {
        // 0x80800114: mfc1        $t3, $f10
        ctx->r11 = (int32_t)ctx->f10.u32l;
            goto L_80800160;
    }
    goto skip_1;
    // 0x80800114: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x80800118: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080011C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800120: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80800124: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80800128: nop

    // 0x8080012C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80800130: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80800134: nop

    // 0x80800138: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x8080013C: bne         $t3, $zero, L_80800154
    if (ctx->r11 != 0) {
        // 0x80800140: nop
    
            goto L_80800154;
    }
    // 0x80800140: nop

    // 0x80800144: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x80800148: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080014C: b           L_8080016C
    // 0x80800150: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_8080016C;
    // 0x80800150: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80800154:
    // 0x80800154: b           L_8080016C
    // 0x80800158: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_8080016C;
    // 0x80800158: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8080015C: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
L_80800160:
    // 0x80800160: nop

    // 0x80800164: bltz        $t3, L_80800154
    if (SIGNED(ctx->r11) < 0) {
        // 0x80800168: nop
    
            goto L_80800154;
    }
    // 0x80800168: nop

L_8080016C:
    // 0x8080016C: sb          $t3, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r11;
    // 0x80800170: lbu         $t4, 0xE($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0XE);
    // 0x80800174: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80800178: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8080017C: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80800180: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800184: bgez        $t4, L_80800198
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800188: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80800198;
    }
    // 0x80800188: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8080018C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800190: nop

    // 0x80800194: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
L_80800198:
    // 0x80800198: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8080019C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808001A0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808001A4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x808001A8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x808001AC: nop

    // 0x808001B0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x808001B4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x808001B8: nop

    // 0x808001BC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x808001C0: beql        $t6, $zero, L_80800210
    if (ctx->r14 == 0) {
        // 0x808001C4: mfc1        $t6, $f6
        ctx->r14 = (int32_t)ctx->f6.u32l;
            goto L_80800210;
    }
    goto skip_2;
    // 0x808001C4: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    skip_2:
    // 0x808001C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001CC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808001D0: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808001D4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x808001D8: nop

    // 0x808001DC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x808001E0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x808001E4: nop

    // 0x808001E8: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x808001EC: bne         $t6, $zero, L_80800204
    if (ctx->r14 != 0) {
        // 0x808001F0: nop
    
            goto L_80800204;
    }
    // 0x808001F0: nop

    // 0x808001F4: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x808001F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808001FC: b           L_8080021C
    // 0x80800200: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_8080021C;
    // 0x80800200: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80800204:
    // 0x80800204: b           L_8080021C
    // 0x80800208: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_8080021C;
    // 0x80800208: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8080020C: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
L_80800210:
    // 0x80800210: nop

    // 0x80800214: bltz        $t6, L_80800204
    if (SIGNED(ctx->r14) < 0) {
        // 0x80800218: nop
    
            goto L_80800204;
    }
    // 0x80800218: nop

L_8080021C:
    // 0x8080021C: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x80800220: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80800224: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80800228: bne         $at, $zero, L_8080001C
    if (ctx->r1 != 0) {
        // 0x8080022C: sb          $t6, -0x2($a2)
        MEM_B(-0X2, ctx->r6) = ctx->r14;
            goto L_8080001C;
    }
    // 0x8080022C: sb          $t6, -0x2($a2)
    MEM_B(-0X2, ctx->r6) = ctx->r14;
L_80800230:
    // 0x80800230: jr          $ra
    // 0x80800234: nop

    return;
    // 0x80800234: nop

;}
RECOMP_FUNC void func_8080006C_chcamerawibble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080006C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800070: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800074: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800078: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080007C: jal         0x80013970
    // 0x80800080: lwc1        $f12, 0x58($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X58);
    func_80013970(rdram, ctx);
        goto after_0;
    // 0x80800080: lwc1        $f12, 0x58($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X58);
    after_0:
    // 0x80800084: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800088: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080008C: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800090: neg.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
    // 0x80800094: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800098: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8080009C: jal         0x800C4B90
    // 0x808000A0: nop

    func_800C4B90(rdram, ctx);
        goto after_1;
    // 0x808000A0: nop

    after_1:
    // 0x808000A4: jal         0x800D8FF8
    // 0x808000A8: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x808000A8: nop

    after_2:
    // 0x808000AC: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808000B0: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808000B4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808000B8: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x808000BC: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    // 0x808000C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000CC: jr          $ra
    // 0x808000D0: nop

    return;
    // 0x808000D0: nop

    // 0x808000D4: nop

    // 0x808000D8: nop

    // 0x808000DC: nop

;}
RECOMP_FUNC void chweather_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(732, 0X440) << 16);
    // 0x808000DC: jr          $ra
    // 0x808000E0: addiu       $v0, $v0, 0x440
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(732, 0X440));
    return;
    // 0x808000E0: addiu       $v0, $v0, 0x440
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(732, 0X440));
;}
RECOMP_FUNC void func_8009CB44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CB44: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8009CB48: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8009CB4C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8009CB50: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8009CB54: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8009CB58: lw          $v0, 0x7F38($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7F38);
    // 0x8009CB5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009CB60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009CB64: beq         $v0, $zero, L_8009CB7C
    if (ctx->r2 == 0) {
        // 0x8009CB68: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8009CB7C;
    }
    // 0x8009CB68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009CB6C: jalr        $v0
    // 0x8009CB70: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8009CB70: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x8009CB74: b           L_8009CB84
    // 0x8009CB78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8009CB84;
    // 0x8009CB78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009CB7C:
    // 0x8009CB7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009CB80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009CB84:
    // 0x8009CB84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009CB88: jr          $ra
    // 0x8009CB8C: nop

    return;
    // 0x8009CB8C: nop

;}
RECOMP_FUNC void func_80801724_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801724: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80801728: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8080172C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80801730: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80801734: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80801738: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8080173C: jal         0x80106790
    // 0x80801740: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80801740: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80801744: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801748: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080174C: jal         0x80100094
    // 0x80801750: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80801750: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801754: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80801758: jal         0x80103AA0
    // 0x8080175C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80103AA0(rdram, ctx);
        goto after_2;
    // 0x8080175C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_2:
    // 0x80801760: beq         $v0, $zero, L_8080177C
    if (ctx->r2 == 0) {
        // 0x80801764: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_8080177C;
    }
    // 0x80801764: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80801768: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8080176C: jal         0x800AE0E8
    // 0x80801770: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    func_800AE0E8(rdram, ctx);
        goto after_3;
    // 0x80801770: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    after_3:
    // 0x80801774: bne         $v0, $zero, L_80801784
    if (ctx->r2 != 0) {
        // 0x80801778: nop
    
            goto L_80801784;
    }
    // 0x80801778: nop

L_8080177C:
    // 0x8080177C: b           L_808017F0
    // 0x80801780: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808017F0;
    // 0x80801780: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801784:
    // 0x80801784: jal         0x80801694
    // 0x80801788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801694_chstatueboss(rdram, ctx);
        goto after_4;
    // 0x80801788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080178C: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80801790: jal         0x800B2824
    // 0x80801794: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_800B2824(rdram, ctx);
        goto after_5;
    // 0x80801794: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_5:
    // 0x80801798: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8080179C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808017A0: jal         0x800AE080
    // 0x808017A4: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    func_800AE080(rdram, ctx);
        goto after_6;
    // 0x808017A4: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    after_6:
    // 0x808017A8: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x808017AC: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x808017B0: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x808017B4: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x808017B8: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x808017BC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x808017C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808017C4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808017C8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808017CC: addiu       $a2, $s0, 0x44
    ctx->r6 = ADD32(ctx->r16, 0X44);
    // 0x808017D0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x808017D4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x808017D8: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x808017DC: jal         0x800B1F8C
    // 0x808017E0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_800B1F8C(rdram, ctx);
        goto after_7;
    // 0x808017E0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_7:
    // 0x808017E4: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x808017E8: sh          $v0, 0x86($v1)
    MEM_H(0X86, ctx->r3) = ctx->r2;
    // 0x808017EC: lh          $v0, 0x86($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X86);
L_808017F0:
    // 0x808017F0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808017F4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x808017F8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808017FC: jr          $ra
    // 0x80801800: nop

    return;
    // 0x80801800: nop

;}
RECOMP_FUNC void func_8080078C_chlagoonufoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080078C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800790: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800794: addiu       $a0, $zero, 0x1C5
    ctx->r4 = ADD32(0, 0X1C5);
    // 0x80800798: jal         0x80089C30
    // 0x8080079C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080079C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808007A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007A4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x808007A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007AC: jr          $ra
    // 0x808007B0: nop

    return;
    // 0x808007B0: nop

;}
RECOMP_FUNC void _glgamedata_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088590: syscall     693
    recomp_syscall_handler(rdram, ctx, 0x80088590);
    return;
    // 0x80088594: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _batranslate_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085358: syscall     158
    recomp_syscall_handler(rdram, ctx, 0x80085358);
    return;
    // 0x8008535C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808000C4_chfriesstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808000C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000D4: jal         0x80100094
    // 0x808000D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808000DC: beq         $v0, $zero, L_80800140
    if (ctx->r2 == 0) {
        // 0x808000E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800140;
    }
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E4: jal         0x80100094
    // 0x808000E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808000E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808000EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000F0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x808000F4: jal         0x800897D8
    // 0x808000F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x808000F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x808000FC: jal         0x801022E4
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_3;
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800104: addiu       $at, $zero, 0xD0
    ctx->r1 = ADD32(0, 0XD0);
    // 0x80800108: bne         $v0, $at, L_80800128
    if (ctx->r2 != ctx->r1) {
        // 0x8080010C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800128;
    }
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800110: lui         $a1, 0x3EE6
    ctx->r5 = S32(0X3EE6 << 16);
    // 0x80800114: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x80800118: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8080011C: jal         0x80102320
    // 0x80800120: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    func_80102320(rdram, ctx);
        goto after_4;
    // 0x80800120: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    after_4:
    // 0x80800124: bne         $v0, $zero, L_80800140
    if (ctx->r2 != 0) {
        // 0x80800128: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800140;
    }
L_80800128:
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: jal         0x80100094
    // 0x80800130: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x80800130: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800134: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800138: jal         0x80089818
    // 0x8080013C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_18(rdram, ctx);
        goto after_6;
    // 0x8080013C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
L_80800140:
    // 0x80800140: jal         0x800F54E4
    // 0x80800144: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x80800144: nop

    after_7:
    // 0x80800148: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8080014C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800150: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800154: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800158: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x8080015C: lui         $a3, 0xC120
    ctx->r7 = S32(0XC120 << 16);
    // 0x80800160: jal         0x800F4EC8
    // 0x80800164: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F4EC8(rdram, ctx);
        goto after_8;
    // 0x80800164: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x80800168: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x8080016C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800170: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800174: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x80800178: beq         $at, $zero, L_80800384
    if (ctx->r1 == 0) {
        // 0x8080017C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800384;
    }
    // 0x8080017C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800180: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(940, 0XD80) << 16);
    // 0x80800184: addu        $at, $at, $t8
    gpr jr_addend_8080018C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800188: lw          $t8, 0xD80($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(940, 0XD80));
    // 0x8080018C: jr          $t8
    // 0x80800190: nop

    switch (jr_addend_8080018C >> 2) {
        case 0: goto L_80800194; break;
        case 1: goto L_80800200; break;
        case 2: goto L_80800248; break;
        case 3: goto L_80800258; break;
        case 4: goto L_80800334; break;
        case 5: goto L_8080035C; break;
        default: switch_error(__func__, 0x8080018C, 0x80800D80);
    }
    // 0x80800190: nop

L_80800194:
    // 0x80800194: jal         0x808005F0
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005F0_chfriesstand(rdram, ctx);
        goto after_9;
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080019C: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x808001A0: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x808001A4: jal         0x80101E14
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_10;
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808001AC: beq         $v0, $zero, L_808001F0
    if (ctx->r2 == 0) {
        // 0x808001B0: nop
    
            goto L_808001F0;
    }
    // 0x808001B0: nop

    // 0x808001B4: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: andi        $t9, $v0, 0x1FF
    ctx->r25 = ctx->r2 & 0X1FF;
    // 0x808001C0: sltiu       $at, $t9, 0x2
    ctx->r1 = ctx->r25 < 0X2 ? 1 : 0;
    // 0x808001C4: beq         $at, $zero, L_808001E8
    if (ctx->r1 == 0) {
        // 0x808001C8: nop
    
            goto L_808001E8;
    }
    // 0x808001C8: nop

    // 0x808001CC: lhu         $t2, 0x6E($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X6E);
    // 0x808001D0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x808001D4: andi        $t1, $t0, 0x1FF
    ctx->r9 = ctx->r8 & 0X1FF;
    // 0x808001D8: andi        $t3, $t2, 0xFE00
    ctx->r11 = ctx->r10 & 0XFE00;
    // 0x808001DC: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x808001E0: b           L_808001F0
    // 0x808001E4: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
        goto L_808001F0;
    // 0x808001E4: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
L_808001E8:
    // 0x808001E8: jal         0x80102424
    // 0x808001EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x808001EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
L_808001F0:
    // 0x808001F0: jal         0x808009A4
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808009A4_chfriesstand(rdram, ctx);
        goto after_12;
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808001F8: b           L_80800388
    // 0x808001FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800388;
    // 0x808001FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800200:
    // 0x80800200: jal         0x80800620
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800620_chfriesstand(rdram, ctx);
        goto after_13;
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800208: jal         0x808006D4
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006D4_chfriesstand(rdram, ctx);
        goto after_14;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800210: jal         0x80101DDC
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_15;
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800218: beq         $v0, $zero, L_80800238
    if (ctx->r2 == 0) {
        // 0x8080021C: nop
    
            goto L_80800238;
    }
    // 0x8080021C: nop

    // 0x80800220: lhu         $t5, 0x6E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800228: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080022C: andi        $t6, $t5, 0xFE00
    ctx->r14 = ctx->r13 & 0XFE00;
    // 0x80800230: jal         0x80102424
    // 0x80800234: sh          $t6, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r14;
    func_80102424(rdram, ctx);
        goto after_16;
    // 0x80800234: sh          $t6, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r14;
    after_16:
L_80800238:
    // 0x80800238: jal         0x808009A4
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808009A4_chfriesstand(rdram, ctx);
        goto after_17;
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800240: b           L_80800388
    // 0x80800244: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800388;
    // 0x80800244: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800248:
    // 0x80800248: jal         0x808005F0
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005F0_chfriesstand(rdram, ctx);
        goto after_18;
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800250: b           L_80800388
    // 0x80800254: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800388;
    // 0x80800254: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800258:
    // 0x80800258: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080025C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(940, 0XFE8) << 16);
    // 0x80800260: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x80800264: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80800268: addiu       $a2, $a2, 0xFE8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(940, 0XFE8));
    // 0x8080026C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800270: jal         0x80089D20
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_19;
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800278: lui         $a1, 0x3F56
    ctx->r5 = S32(0X3F56 << 16);
    // 0x8080027C: ori         $a1, $a1, 0x45A2
    ctx->r5 = ctx->r5 | 0X45A2;
    // 0x80800280: jal         0x80101E14
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_20;
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800288: beq         $v0, $zero, L_80800304
    if (ctx->r2 == 0) {
        // 0x8080028C: nop
    
            goto L_80800304;
    }
    // 0x8080028C: nop

    // 0x80800290: lw          $t7, 0x3C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X3C);
    // 0x80800294: beq         $t7, $zero, L_808002C8
    if (ctx->r15 == 0) {
        // 0x80800298: nop
    
            goto L_808002C8;
    }
    // 0x80800298: nop

    // 0x8080029C: jal         0x800FC660
    // 0x808002A0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_21;
    // 0x808002A0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_21:
    // 0x808002A4: jal         0x800D1A04
    // 0x808002A8: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    func_800D1A04(rdram, ctx);
        goto after_22;
    // 0x808002A8: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    after_22:
    // 0x808002AC: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x808002B0: subu        $a1, $t8, $v0
    ctx->r5 = SUB32(ctx->r24, ctx->r2);
    // 0x808002B4: jal         0x800D175C
    // 0x808002B8: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    func_800D175C(rdram, ctx);
        goto after_23;
    // 0x808002B8: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    after_23:
    // 0x808002BC: jal         0x800FFA88
    // 0x808002C0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_800FFA88(rdram, ctx);
        goto after_24;
    // 0x808002C0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_24:
    // 0x808002C4: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
L_808002C8:
    // 0x808002C8: jal         0x800F54E4
    // 0x808002CC: nop

    func_800F54E4(rdram, ctx);
        goto after_25;
    // 0x808002CC: nop

    after_25:
    // 0x808002D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002D4: jal         0x800F64A4
    // 0x808002D8: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    func_800F64A4(rdram, ctx);
        goto after_26;
    // 0x808002D8: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_26:
    // 0x808002DC: beq         $v0, $zero, L_808002EC
    if (ctx->r2 == 0) {
        // 0x808002E0: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_808002EC;
    }
    // 0x808002E0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x808002E4: b           L_808002F0
    // 0x808002E8: addiu       $a1, $zero, 0x110B
    ctx->r5 = ADD32(0, 0X110B);
        goto L_808002F0;
    // 0x808002E8: addiu       $a1, $zero, 0x110B
    ctx->r5 = ADD32(0, 0X110B);
L_808002EC:
    // 0x808002EC: addiu       $a1, $zero, 0x10FD
    ctx->r5 = ADD32(0, 0X10FD);
L_808002F0:
    // 0x808002F0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808002F4: addiu       $t9, $zero, 0x51
    ctx->r25 = ADD32(0, 0X51);
    // 0x808002F8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808002FC: jal         0x8008A208
    // 0x80800300: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_27;
    // 0x80800300: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_27:
L_80800304:
    // 0x80800304: jal         0x80101DDC
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_28;
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x8080030C: beql        $v0, $zero, L_80800388
    if (ctx->r2 == 0) {
        // 0x80800310: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800388;
    }
    goto skip_0;
    // 0x80800310: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800314: lhu         $t0, 0x6E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080031C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800320: andi        $t2, $t0, 0xFE00
    ctx->r10 = ctx->r8 & 0XFE00;
    // 0x80800324: jal         0x80102424
    // 0x80800328: sh          $t2, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r10;
    func_80102424(rdram, ctx);
        goto after_29;
    // 0x80800328: sh          $t2, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r10;
    after_29:
    // 0x8080032C: b           L_80800388
    // 0x80800330: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800388;
    // 0x80800330: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800334:
    // 0x80800334: jal         0x808005F0
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005F0_chfriesstand(rdram, ctx);
        goto after_30;
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x8080033C: jal         0x80101DDC
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_31;
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80800344: beq         $v0, $zero, L_80800384
    if (ctx->r2 == 0) {
        // 0x80800348: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800384;
    }
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080034C: jal         0x80102424
    // 0x80800350: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_32;
    // 0x80800350: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_32:
    // 0x80800354: b           L_80800388
    // 0x80800358: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800388;
    // 0x80800358: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080035C:
    // 0x8080035C: jal         0x80800620
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800620_chfriesstand(rdram, ctx);
        goto after_33;
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x80800364: jal         0x808006D4
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006D4_chfriesstand(rdram, ctx);
        goto after_34;
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x8080036C: jal         0x80101DDC
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_35;
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x80800374: beq         $v0, $zero, L_80800384
    if (ctx->r2 == 0) {
        // 0x80800378: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800384;
    }
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080037C: jal         0x80102424
    // 0x80800380: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_36;
    // 0x80800380: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_36:
L_80800384:
    // 0x80800384: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800388:
    // 0x80800388: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080038C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800390: jr          $ra
    // 0x80800394: nop

    return;
    // 0x80800394: nop

;}
RECOMP_FUNC void ncpod_entrypoint_33(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080100C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801014: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801018: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080101C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80801020: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801024: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80801028: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8080102C: jal         0x80800958
    // 0x80801030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ncpod_entrypoint_16(rdram, ctx);
        goto after_0;
    // 0x80801030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801034: bne         $v0, $zero, L_80801044
    if (ctx->r2 != 0) {
        // 0x80801038: nop
    
            goto L_80801044;
    }
    // 0x80801038: nop

    // 0x8080103C: b           L_808010D8
    // 0x80801040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808010D8;
    // 0x80801040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801044:
    // 0x80801044: jal         0x80110024
    // 0x80801048: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80110024(rdram, ctx);
        goto after_1;
    // 0x80801048: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080104C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80801050: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801054: jal         0x808005C0
    // 0x80801058: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    ncpod_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80801058: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x8080105C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80801060: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80801064: beq         $a1, $zero, L_8080107C
    if (ctx->r5 == 0) {
        // 0x80801068: nop
    
            goto L_8080107C;
    }
    // 0x80801068: nop

    // 0x8080106C: jal         0x80800548
    // 0x80801070: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    ncpod_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x80801070: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80801074: b           L_80801090
    // 0x80801078: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
        goto L_80801090;
    // 0x80801078: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_8080107C:
    // 0x8080107C: beq         $t6, $zero, L_8080108C
    if (ctx->r14 == 0) {
        // 0x80801080: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8080108C;
    }
    // 0x80801080: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80801084: jal         0x80800548
    // 0x80801088: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    ncpod_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x80801088: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_4:
L_8080108C:
    // 0x8080108C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_80801090:
    // 0x80801090: jal         0x800896A0
    // 0x80801094: lh          $a0, 0x4($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X4);
    _ncpodfixpos_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80801094: lh          $a0, 0x4($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X4);
    after_5:
    // 0x80801098: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8080109C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808010A0: jal         0x800896B8
    // 0x808010A4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    _ncpodfixpos_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x808010A4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_6:
    // 0x808010A8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808010AC: beql        $a1, $zero, L_808010C0
    if (ctx->r5 == 0) {
        // 0x808010B0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808010C0;
    }
    goto skip_0;
    // 0x808010B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x808010B4: jal         0x800896B0
    // 0x808010B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _ncpodfixpos_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x808010B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_7:
    // 0x808010BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_808010C0:
    // 0x808010C0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808010C4: jal         0x800896A8
    // 0x808010C8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    _ncpodfixpos_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x808010C8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_8:
    // 0x808010CC: jal         0x8010FD88
    // 0x808010D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8010FD88(rdram, ctx);
        goto after_9;
    // 0x808010D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x808010D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808010D8:
    // 0x808010D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808010DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808010E0: jr          $ra
    // 0x808010E4: nop

    return;
    // 0x808010E4: nop

    // 0x808010E8: nop

    // 0x808010EC: nop

;}
RECOMP_FUNC void func_801078AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801078AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801078B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801078B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801078B8: jal         0x800D90A4
    // 0x801078BC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800D90A4(rdram, ctx);
        goto after_0;
    // 0x801078BC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x801078C0: beq         $v0, $zero, L_801078D0
    if (ctx->r2 == 0) {
        // 0x801078C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801078D0;
    }
    // 0x801078C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801078C8: b           L_801078D4
    // 0x801078CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801078D4;
    // 0x801078CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801078D0:
    // 0x801078D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801078D4:
    // 0x801078D4: jr          $ra
    // 0x801078D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801078D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80092E50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092E50: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80092E54: jr          $ra
    // 0x80092E58: lbu         $v0, 0x15($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X15);
    return;
    // 0x80092E58: lbu         $v0, 0x15($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X15);
;}
RECOMP_FUNC void chpickups_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800060: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(700, 0X9D0) << 16);
    // 0x80800064: jr          $ra
    // 0x80800068: addiu       $v0, $v0, 0x9D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0X9D0));
    return;
    // 0x80800068: addiu       $v0, $v0, 0x9D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0X9D0));
;}
RECOMP_FUNC void func_800C6754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6754: jr          $ra
    // 0x800C6758: lbu         $v0, 0x95($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X95);
    return;
    // 0x800C6758: lbu         $v0, 0x95($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X95);
;}
RECOMP_FUNC void func_801143A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801143A4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801143A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801143AC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x801143B0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x801143B4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x801143B8: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x801143BC: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x801143C0: jal         0x800CA8F4
    // 0x801143C4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800CA8F4(rdram, ctx);
        goto after_0;
    // 0x801143C4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x801143C8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x801143CC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x801143D0: jal         0x800EFB24
    // 0x801143D4: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x801143D4: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x801143D8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x801143DC: jal         0x800EEAA4
    // 0x801143E0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EEAA4(rdram, ctx);
        goto after_2;
    // 0x801143E0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x801143E4: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801143E8: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x801143EC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x801143F0: sub.s       $f12, $f0, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x801143F4: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x801143F8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x801143FC: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80114400: nop

    // 0x80114404: bc1fl       L_80114434
    if (!c1cs) {
        // 0x80114408: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80114434;
    }
    goto skip_0;
    // 0x80114408: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8011440C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80114410: jal         0x800CACEC
    // 0x80114414: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    func_800CACEC(rdram, ctx);
        goto after_3;
    // 0x80114414: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x80114418: beq         $v0, $zero, L_80114430
    if (ctx->r2 == 0) {
        // 0x8011441C: lwc1        $f12, 0x18($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
            goto L_80114430;
    }
    // 0x8011441C: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80114420: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80114424: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80114428: b           L_80114434
    // 0x8011442C: swc1        $f12, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f12.u32l;
        goto L_80114434;
    // 0x8011442C: swc1        $f12, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f12.u32l;
L_80114430:
    // 0x80114430: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80114434:
    // 0x80114434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80114438: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8011443C: jr          $ra
    // 0x80114440: nop

    return;
    // 0x80114440: nop

;}
RECOMP_FUNC void func_808039B8_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808039B8: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x808039BC: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x808039C0: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x808039C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808039C8: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x808039CC: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x808039D0: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x808039D4: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x808039D8: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x808039DC: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x808039E0: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x808039E4: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x808039E8: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x808039EC: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x808039F0: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x808039F4: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808039F8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808039FC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80803A00: jal         0x80100094
    // 0x80803A04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803A04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803A08: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80803A0C: jal         0x80106790
    // 0x80803A10: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80803A10: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_1:
    // 0x80803A14: sw          $v0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r2;
    // 0x80803A18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803A1C: jal         0x80100094
    // 0x80803A20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80803A20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80803A24: sw          $v0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r2;
    // 0x80803A28: lbu         $t6, 0xC2($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XC2);
    // 0x80803A2C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80803A30: lui         $at, 0x4307
    ctx->r1 = S32(0X4307 << 16);
    // 0x80803A34: blezl       $t6, L_808041E8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80803A38: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_808041E8;
    }
    goto skip_0;
    // 0x80803A38: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    skip_0:
    // 0x80803A3C: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80803A40: lui         $at, 0xC307
    ctx->r1 = S32(0XC307 << 16);
    // 0x80803A44: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80803A48: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80803A4C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80803A50: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x80803A54: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80803A58: addiu       $fp, $sp, 0xA8
    ctx->r30 = ADD32(ctx->r29, 0XA8);
    // 0x80803A5C: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
L_80803A60:
    // 0x80803A60: lw          $a0, 0xF8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XF8);
    // 0x80803A64: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80803A68: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x80803A6C: beql        $s7, $t8, L_808041D0
    if (ctx->r23 == ctx->r24) {
        // 0x80803A70: lw          $t1, 0xF4($sp)
        ctx->r9 = MEM_W(ctx->r29, 0XF4);
            goto L_808041D0;
    }
    goto skip_1;
    // 0x80803A70: lw          $t1, 0xF4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF4);
    skip_1:
    // 0x80803A74: jal         0x8080000C
    // 0x80803A78: addiu       $s2, $s0, 0x4
    ctx->r18 = ADD32(ctx->r16, 0X4);
    func_8080000C_chdodgemcontrol(rdram, ctx);
        goto after_3;
    // 0x80803A78: addiu       $s2, $s0, 0x4
    ctx->r18 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80803A7C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80803A80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803A84: jal         0x80100094
    // 0x80803A88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80803A88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80803A8C: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80803A90: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80803A94: addiu       $a0, $sp, 0xD0
    ctx->r4 = ADD32(ctx->r29, 0XD0);
    // 0x80803A98: swc1        $f4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f4.u32l;
    // 0x80803A9C: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80803AA0: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    // 0x80803AA4: swc1        $f6, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f6.u32l;
    // 0x80803AA8: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80803AAC: swc1        $f8, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f8.u32l;
    // 0x80803AB0: jal         0x800EEB9C
    // 0x80803AB4: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    func_800EEB9C(rdram, ctx);
        goto after_5;
    // 0x80803AB4: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    after_5:
    // 0x80803AB8: addiu       $a0, $sp, 0xD0
    ctx->r4 = ADD32(ctx->r29, 0XD0);
    // 0x80803ABC: jal         0x800EF04C
    // 0x80803AC0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EF04C(rdram, ctx);
        goto after_6;
    // 0x80803AC0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_6:
    // 0x80803AC4: addiu       $a0, $sp, 0xC4
    ctx->r4 = ADD32(ctx->r29, 0XC4);
    // 0x80803AC8: lw          $a1, 0x48($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X48);
    // 0x80803ACC: jal         0x800EEB9C
    // 0x80803AD0: lui         $a2, 0x4243
    ctx->r6 = S32(0X4243 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_7;
    // 0x80803AD0: lui         $a2, 0x4243
    ctx->r6 = S32(0X4243 << 16);
    after_7:
    // 0x80803AD4: addiu       $s3, $s1, 0x4
    ctx->r19 = ADD32(ctx->r17, 0X4);
    // 0x80803AD8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80803ADC: jal         0x800EF04C
    // 0x80803AE0: addiu       $a0, $sp, 0xC4
    ctx->r4 = ADD32(ctx->r29, 0XC4);
    func_800EF04C(rdram, ctx);
        goto after_8;
    // 0x80803AE0: addiu       $a0, $sp, 0xC4
    ctx->r4 = ADD32(ctx->r29, 0XC4);
    after_8:
    // 0x80803AE4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803AE8: lui         $a1, 0x4336
    ctx->r5 = S32(0X4336 << 16);
    // 0x80803AEC: jal         0x800EFFB4
    // 0x80803AF0: addiu       $a2, $sp, 0xDC
    ctx->r6 = ADD32(ctx->r29, 0XDC);
    func_800EFFB4(rdram, ctx);
        goto after_9;
    // 0x80803AF0: addiu       $a2, $sp, 0xDC
    ctx->r6 = ADD32(ctx->r29, 0XDC);
    after_9:
    // 0x80803AF4: bne         $v0, $zero, L_80803B38
    if (ctx->r2 != 0) {
        // 0x80803AF8: addiu       $a0, $sp, 0xD0
        ctx->r4 = ADD32(ctx->r29, 0XD0);
            goto L_80803B38;
    }
    // 0x80803AF8: addiu       $a0, $sp, 0xD0
    ctx->r4 = ADD32(ctx->r29, 0XD0);
    // 0x80803AFC: lui         $a1, 0x431C
    ctx->r5 = S32(0X431C << 16);
    // 0x80803B00: jal         0x800EFFB4
    // 0x80803B04: addiu       $a2, $sp, 0xDC
    ctx->r6 = ADD32(ctx->r29, 0XDC);
    func_800EFFB4(rdram, ctx);
        goto after_10;
    // 0x80803B04: addiu       $a2, $sp, 0xDC
    ctx->r6 = ADD32(ctx->r29, 0XDC);
    after_10:
    // 0x80803B08: bne         $v0, $zero, L_80803B38
    if (ctx->r2 != 0) {
        // 0x80803B0C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803B38;
    }
    // 0x80803B0C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803B10: lui         $a1, 0x431C
    ctx->r5 = S32(0X431C << 16);
    // 0x80803B14: jal         0x800EFFB4
    // 0x80803B18: addiu       $a2, $sp, 0xC4
    ctx->r6 = ADD32(ctx->r29, 0XC4);
    func_800EFFB4(rdram, ctx);
        goto after_11;
    // 0x80803B18: addiu       $a2, $sp, 0xC4
    ctx->r6 = ADD32(ctx->r29, 0XC4);
    after_11:
    // 0x80803B1C: bne         $v0, $zero, L_80803B38
    if (ctx->r2 != 0) {
        // 0x80803B20: addiu       $a0, $sp, 0xD0
        ctx->r4 = ADD32(ctx->r29, 0XD0);
            goto L_80803B38;
    }
    // 0x80803B20: addiu       $a0, $sp, 0xD0
    ctx->r4 = ADD32(ctx->r29, 0XD0);
    // 0x80803B24: lui         $a1, 0x4302
    ctx->r5 = S32(0X4302 << 16);
    // 0x80803B28: jal         0x800EFFB4
    // 0x80803B2C: addiu       $a2, $sp, 0xC4
    ctx->r6 = ADD32(ctx->r29, 0XC4);
    func_800EFFB4(rdram, ctx);
        goto after_12;
    // 0x80803B2C: addiu       $a2, $sp, 0xC4
    ctx->r6 = ADD32(ctx->r29, 0XC4);
    after_12:
    // 0x80803B30: beql        $v0, $zero, L_808041D0
    if (ctx->r2 == 0) {
        // 0x80803B34: lw          $t1, 0xF4($sp)
        ctx->r9 = MEM_W(ctx->r29, 0XF4);
            goto L_808041D0;
    }
    goto skip_2;
    // 0x80803B34: lw          $t1, 0xF4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF4);
    skip_2:
L_80803B38:
    // 0x80803B38: jal         0x800EEF94
    // 0x80803B3C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800EEF94(rdram, ctx);
        goto after_13;
    // 0x80803B3C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_13:
    // 0x80803B40: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80803B44: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80803B48: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80803B4C: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x80803B50: nop

    // 0x80803B54: bne         $s7, $t0, L_80803B68
    if (ctx->r23 != ctx->r8) {
        // 0x80803B58: nop
    
            goto L_80803B68;
    }
    // 0x80803B58: nop

    // 0x80803B5C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80803B60: nop

    // 0x80803B64: swc1        $f18, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f18.u32l;
L_80803B68:
    // 0x80803B68: jal         0x800EEF94
    // 0x80803B6C: addiu       $a0, $s1, 0x28
    ctx->r4 = ADD32(ctx->r17, 0X28);
    func_800EEF94(rdram, ctx);
        goto after_14;
    // 0x80803B6C: addiu       $a0, $s1, 0x28
    ctx->r4 = ADD32(ctx->r17, 0X28);
    after_14:
    // 0x80803B70: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x80803B74: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80803B78: bc1fl       L_808041D0
    if (!c1cs) {
        // 0x80803B7C: lw          $t1, 0xF4($sp)
        ctx->r9 = MEM_W(ctx->r29, 0XF4);
            goto L_808041D0;
    }
    goto skip_3;
    // 0x80803B7C: lw          $t1, 0xF4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF4);
    skip_3:
    // 0x80803B80: jal         0x800F1DF4
    // 0x80803B84: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800F1DF4(rdram, ctx);
        goto after_15;
    // 0x80803B84: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_15:
    // 0x80803B88: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80803B8C: lwc1        $f12, 0x48($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X48);
    // 0x80803B90: mfc1        $s4, $f4
    ctx->r20 = (int32_t)ctx->f4.u32l;
    // 0x80803B94: nop

    // 0x80803B98: mtc1        $s4, $f6
    ctx->f6.u32l = ctx->r20;
    // 0x80803B9C: jal         0x800F1DCC
    // 0x80803BA0: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    func_800F1DCC(rdram, ctx);
        goto after_16;
    // 0x80803BA0: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_16:
    // 0x80803BA4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80803BA8: lwc1        $f10, 0x18($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X18);
    // 0x80803BAC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80803BB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80803BB4: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80803BB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80803BBC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80803BC0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1752, 0X4D5C) << 16);
    // 0x80803BC4: bc1fl       L_80803BE8
    if (!c1cs) {
        // 0x80803BC8: c.lt.s      $f24, $f20
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl < ctx->f20.fl;
            goto L_80803BE8;
    }
    goto skip_4;
    // 0x80803BC8: c.lt.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl < ctx->f20.fl;
    skip_4:
    // 0x80803BCC: jal         0x8010D930
    // 0x80803BD0: addiu       $a3, $a3, 0x4D5C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1752, 0X4D5C));
    func_8010D930(rdram, ctx);
        goto after_17;
    // 0x80803BD0: addiu       $a3, $a3, 0x4D5C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1752, 0X4D5C));
    after_17:
    // 0x80803BD4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803BD8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80803BDC: nop

    // 0x80803BE0: swc1        $f16, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->f16.u32l;
    // 0x80803BE4: c.lt.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl < ctx->f20.fl;
L_80803BE8:
    // 0x80803BE8: nop

    // 0x80803BEC: bc1fl       L_80803C10
    if (!c1cs) {
        // 0x80803BF0: c.lt.s      $f20, $f24
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
            goto L_80803C10;
    }
    goto skip_5;
    // 0x80803BF0: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
    skip_5:
    // 0x80803BF4: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    // 0x80803BF8: nop

    // 0x80803BFC: bc1fl       L_80803C10
    if (!c1cs) {
        // 0x80803C00: c.lt.s      $f20, $f24
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
            goto L_80803C10;
    }
    goto skip_6;
    // 0x80803C00: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
    skip_6:
    // 0x80803C04: jal         0x80802764
    // 0x80803C08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80802764_chdodgemcontrol(rdram, ctx);
        goto after_18;
    // 0x80803C08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
    // 0x80803C0C: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
L_80803C10:
    // 0x80803C10: nop

    // 0x80803C14: bc1fl       L_80803C38
    if (!c1cs) {
        // 0x80803C18: c.lt.s      $f26, $f20
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
            goto L_80803C38;
    }
    goto skip_7;
    // 0x80803C18: c.lt.s      $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
    skip_7:
    // 0x80803C1C: c.lt.s      $f28, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f28.fl < ctx->f20.fl;
    // 0x80803C20: nop

    // 0x80803C24: bc1fl       L_80803C38
    if (!c1cs) {
        // 0x80803C28: c.lt.s      $f26, $f20
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
            goto L_80803C38;
    }
    goto skip_8;
    // 0x80803C28: c.lt.s      $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
    skip_8:
    // 0x80803C2C: jal         0x80802824
    // 0x80803C30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80802824_chdodgemcontrol(rdram, ctx);
        goto after_19;
    // 0x80803C30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_19:
    // 0x80803C34: c.lt.s      $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
L_80803C38:
    // 0x80803C38: nop

    // 0x80803C3C: bc1fl       L_80803C60
    if (!c1cs) {
        // 0x80803C40: c.lt.s      $f20, $f28
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl < ctx->f28.fl;
            goto L_80803C60;
    }
    goto skip_9;
    // 0x80803C40: c.lt.s      $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl < ctx->f28.fl;
    skip_9:
    // 0x80803C44: c.lt.s      $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f20.fl < ctx->f30.fl;
    // 0x80803C48: nop

    // 0x80803C4C: bc1fl       L_80803C60
    if (!c1cs) {
        // 0x80803C50: c.lt.s      $f20, $f28
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl < ctx->f28.fl;
            goto L_80803C60;
    }
    goto skip_10;
    // 0x80803C50: c.lt.s      $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl < ctx->f28.fl;
    skip_10:
    // 0x80803C54: jal         0x80802884
    // 0x80803C58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80802884_chdodgemcontrol(rdram, ctx);
        goto after_20;
    // 0x80803C58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_20:
    // 0x80803C5C: c.lt.s      $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl < ctx->f28.fl;
L_80803C60:
    // 0x80803C60: nop

    // 0x80803C64: bc1t        L_80803C7C
    if (c1cs) {
        // 0x80803C68: nop
    
            goto L_80803C7C;
    }
    // 0x80803C68: nop

    // 0x80803C6C: c.lt.s      $f30, $f20
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f30.fl < ctx->f20.fl;
    // 0x80803C70: nop

    // 0x80803C74: bc1fl       L_80803C88
    if (!c1cs) {
        // 0x80803C78: lui         $at, 0x4316
        ctx->r1 = S32(0X4316 << 16);
            goto L_80803C88;
    }
    goto skip_11;
    // 0x80803C78: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    skip_11:
L_80803C7C:
    // 0x80803C7C: jal         0x808027C4
    // 0x80803C80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808027C4_chdodgemcontrol(rdram, ctx);
        goto after_21;
    // 0x80803C80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
    // 0x80803C84: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
L_80803C88:
    // 0x80803C88: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80803C8C: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803C90: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80803C94: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80803C98: nop

    // 0x80803C9C: bc1fl       L_80803CB8
    if (!c1cs) {
        // 0x80803CA0: lw          $t2, 0x6C($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X6C);
            goto L_80803CB8;
    }
    goto skip_12;
    // 0x80803CA0: lw          $t2, 0x6C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X6C);
    skip_12:
    // 0x80803CA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803CA8: nop

    // 0x80803CAC: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x80803CB0: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803CB4: lw          $t2, 0x6C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X6C);
L_80803CB8:
    // 0x80803CB8: lw          $t4, 0xF8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF8);
    // 0x80803CBC: andi        $t3, $t2, 0x1FF
    ctx->r11 = ctx->r10 & 0X1FF;
    // 0x80803CC0: bne         $t3, $zero, L_80803D1C
    if (ctx->r11 != 0) {
        // 0x80803CC4: nop
    
            goto L_80803D1C;
    }
    // 0x80803CC4: nop

    // 0x80803CC8: lbu         $t5, 0x79($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X79);
    // 0x80803CCC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80803CD0: srl         $t6, $t5, 4
    ctx->r14 = S32(U32(ctx->r13) >> 4);
    // 0x80803CD4: beq         $t6, $at, L_80803D1C
    if (ctx->r14 == ctx->r1) {
        // 0x80803CD8: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1752, 0X4CC4) << 16);
            goto L_80803D1C;
    }
    // 0x80803CD8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4CC4) << 16);
    // 0x80803CDC: lwc1        $f6, 0x4CC4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4CC4));
    // 0x80803CE0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80803CE4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80803CE8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80803CEC: mtc1        $s4, $f10
    ctx->f10.u32l = ctx->r20;
    // 0x80803CF0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80803CF4: cvt.s.w     $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    ctx->f22.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80803CF8: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x80803CFC: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803D00: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80803D04: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80803D08: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80803D0C: jal         0x800EEB9C
    // 0x80803D10: nop

    func_800EEB9C(rdram, ctx);
        goto after_22;
    // 0x80803D10: nop

    after_22:
    // 0x80803D14: b           L_80803D58
    // 0x80803D18: nop

        goto L_80803D58;
    // 0x80803D18: nop

L_80803D1C:
    // 0x80803D1C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4CC8) << 16);
    // 0x80803D20: lwc1        $f6, 0x4CC8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4CC8));
    // 0x80803D24: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803D28: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80803D2C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80803D30: mtc1        $s4, $f10
    ctx->f10.u32l = ctx->r20;
    // 0x80803D34: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80803D38: cvt.s.w     $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    ctx->f22.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80803D3C: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x80803D40: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803D44: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80803D48: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80803D4C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80803D50: jal         0x800EEB9C
    // 0x80803D54: nop

    func_800EEB9C(rdram, ctx);
        goto after_23;
    // 0x80803D54: nop

    after_23:
L_80803D58:
    // 0x80803D58: bne         $s7, $zero, L_80803DB4
    if (ctx->r23 != 0) {
        // 0x80803D5C: lw          $t7, 0xF8($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XF8);
            goto L_80803DB4;
    }
    // 0x80803D5C: lw          $t7, 0xF8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF8);
    // 0x80803D60: lbu         $t8, 0x79($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X79);
    // 0x80803D64: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80803D68: srl         $t9, $t8, 4
    ctx->r25 = S32(U32(ctx->r24) >> 4);
    // 0x80803D6C: beq         $t9, $at, L_80803DB4
    if (ctx->r25 == ctx->r1) {
        // 0x80803D70: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80803DB4;
    }
    // 0x80803D70: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80803D74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80803D78: lwc1        $f6, 0x24($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80803D7C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80803D80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803D84: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80803D88: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80803D8C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80803D90: swc1        $f10, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
    // 0x80803D94: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803D98: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80803D9C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80803DA0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80803DA4: jal         0x800EEB9C
    // 0x80803DA8: nop

    func_800EEB9C(rdram, ctx);
        goto after_24;
    // 0x80803DA8: nop

    after_24:
    // 0x80803DAC: b           L_80803DF4
    // 0x80803DB0: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
        goto L_80803DF4;
    // 0x80803DB0: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
L_80803DB4:
    // 0x80803DB4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4CCC) << 16);
    // 0x80803DB8: lwc1        $f10, 0x4CCC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4CCC));
    // 0x80803DBC: lwc1        $f8, 0x24($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80803DC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803DC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80803DC8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80803DCC: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80803DD0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80803DD4: swc1        $f16, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f16.u32l;
    // 0x80803DD8: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803DDC: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80803DE0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80803DE4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80803DE8: jal         0x800EEB9C
    // 0x80803DEC: nop

    func_800EEB9C(rdram, ctx);
        goto after_25;
    // 0x80803DEC: nop

    after_25:
    // 0x80803DF0: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
L_80803DF4:
    // 0x80803DF4: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80803DF8: jal         0x800EEB9C
    // 0x80803DFC: lui         $a2, 0x4243
    ctx->r6 = S32(0X4243 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_26;
    // 0x80803DFC: lui         $a2, 0x4243
    ctx->r6 = S32(0X4243 << 16);
    after_26:
    // 0x80803E00: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x80803E04: lw          $a1, 0x48($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X48);
    // 0x80803E08: jal         0x800EEB9C
    // 0x80803E0C: lui         $a2, 0x4243
    ctx->r6 = S32(0X4243 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_27;
    // 0x80803E0C: lui         $a2, 0x4243
    ctx->r6 = S32(0X4243 << 16);
    after_27:
    // 0x80803E10: lui         $a2, 0x432A
    ctx->r6 = S32(0X432A << 16);
    // 0x80803E14: ori         $a2, $a2, 0xA000
    ctx->r6 = ctx->r6 | 0XA000;
    // 0x80803E18: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803E1C: jal         0x80801084
    // 0x80803E20: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80801084_chdodgemcontrol(rdram, ctx);
        goto after_28;
    // 0x80803E20: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_28:
    // 0x80803E24: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80803E28: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x80803E2C: jal         0x800EE780
    // 0x80803E30: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800EE780(rdram, ctx);
        goto after_29;
    // 0x80803E30: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_29:
    // 0x80803E34: lui         $a2, 0x432A
    ctx->r6 = S32(0X432A << 16);
    // 0x80803E38: ori         $a2, $a2, 0xA000
    ctx->r6 = ctx->r6 | 0XA000;
    // 0x80803E3C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80803E40: jal         0x80801084
    // 0x80803E44: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80801084_chdodgemcontrol(rdram, ctx);
        goto after_30;
    // 0x80803E44: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_30:
    // 0x80803E48: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803E4C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80803E50: jal         0x800EFB24
    // 0x80803E54: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    func_800EFB24(rdram, ctx);
        goto after_31;
    // 0x80803E54: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    after_31:
    // 0x80803E58: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x80803E5C: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x80803E60: jal         0x800EE780
    // 0x80803E64: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800EE780(rdram, ctx);
        goto after_32;
    // 0x80803E64: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_32:
    // 0x80803E68: lui         $a2, 0x4308
    ctx->r6 = S32(0X4308 << 16);
    // 0x80803E6C: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80803E70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803E74: jal         0x80801084
    // 0x80803E78: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    func_80801084_chdodgemcontrol(rdram, ctx);
        goto after_33;
    // 0x80803E78: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    after_33:
    // 0x80803E7C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80803E80: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    // 0x80803E84: jal         0x800EFB24
    // 0x80803E88: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    func_800EFB24(rdram, ctx);
        goto after_34;
    // 0x80803E88: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    after_34:
    // 0x80803E8C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80803E90: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x80803E94: jal         0x800EE780
    // 0x80803E98: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800EE780(rdram, ctx);
        goto after_35;
    // 0x80803E98: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_35:
    // 0x80803E9C: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x80803EA0: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x80803EA4: jal         0x800EE780
    // 0x80803EA8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800EE780(rdram, ctx);
        goto after_36;
    // 0x80803EA8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_36:
    // 0x80803EAC: lui         $a2, 0x4308
    ctx->r6 = S32(0X4308 << 16);
    // 0x80803EB0: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80803EB4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80803EB8: jal         0x80801084
    // 0x80803EBC: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    func_80801084_chdodgemcontrol(rdram, ctx);
        goto after_37;
    // 0x80803EBC: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    after_37:
    // 0x80803EC0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80803EC4: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    // 0x80803EC8: jal         0x800EFB24
    // 0x80803ECC: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    func_800EFB24(rdram, ctx);
        goto after_38;
    // 0x80803ECC: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    after_38:
    // 0x80803ED0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803ED4: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80803ED8: jal         0x800EFB24
    // 0x80803EDC: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    func_800EFB24(rdram, ctx);
        goto after_39;
    // 0x80803EDC: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    after_39:
    // 0x80803EE0: addiu       $t0, $s4, 0xB4
    ctx->r8 = ADD32(ctx->r20, 0XB4);
    // 0x80803EE4: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80803EE8: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80803EEC: jal         0x800F1DCC
    // 0x80803EF0: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    func_800F1DCC(rdram, ctx);
        goto after_40;
    // 0x80803EF0: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    after_40:
    // 0x80803EF4: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x80803EF8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80803EFC: bc1fl       L_80803F20
    if (!c1cs) {
        // 0x80803F00: c.lt.s      $f20, $f24
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
            goto L_80803F20;
    }
    goto skip_13;
    // 0x80803F00: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
    skip_13:
    // 0x80803F04: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
    // 0x80803F08: nop

    // 0x80803F0C: bc1fl       L_80803F20
    if (!c1cs) {
        // 0x80803F10: c.lt.s      $f20, $f24
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
            goto L_80803F20;
    }
    goto skip_14;
    // 0x80803F10: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
    skip_14:
    // 0x80803F14: jal         0x80802104
    // 0x80803F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802104_chdodgemcontrol(rdram, ctx);
        goto after_41;
    // 0x80803F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x80803F1C: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
L_80803F20:
    // 0x80803F20: nop

    // 0x80803F24: bc1fl       L_80803F48
    if (!c1cs) {
        // 0x80803F28: c.lt.s      $f26, $f20
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
            goto L_80803F48;
    }
    goto skip_15;
    // 0x80803F28: c.lt.s      $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
    skip_15:
    // 0x80803F2C: c.lt.s      $f28, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f28.fl < ctx->f20.fl;
    // 0x80803F30: nop

    // 0x80803F34: bc1fl       L_80803F48
    if (!c1cs) {
        // 0x80803F38: c.lt.s      $f26, $f20
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
            goto L_80803F48;
    }
    goto skip_16;
    // 0x80803F38: c.lt.s      $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
    skip_16:
    // 0x80803F3C: jal         0x80802104
    // 0x80803F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802104_chdodgemcontrol(rdram, ctx);
        goto after_42;
    // 0x80803F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x80803F44: c.lt.s      $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
L_80803F48:
    // 0x80803F48: nop

    // 0x80803F4C: bc1fl       L_80803F70
    if (!c1cs) {
        // 0x80803F50: c.lt.s      $f20, $f28
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl < ctx->f28.fl;
            goto L_80803F70;
    }
    goto skip_17;
    // 0x80803F50: c.lt.s      $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl < ctx->f28.fl;
    skip_17:
    // 0x80803F54: c.lt.s      $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f20.fl < ctx->f30.fl;
    // 0x80803F58: nop

    // 0x80803F5C: bc1fl       L_80803F70
    if (!c1cs) {
        // 0x80803F60: c.lt.s      $f20, $f28
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl < ctx->f28.fl;
            goto L_80803F70;
    }
    goto skip_18;
    // 0x80803F60: c.lt.s      $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl < ctx->f28.fl;
    skip_18:
    // 0x80803F64: jal         0x80802104
    // 0x80803F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802104_chdodgemcontrol(rdram, ctx);
        goto after_43;
    // 0x80803F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x80803F6C: c.lt.s      $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl < ctx->f28.fl;
L_80803F70:
    // 0x80803F70: nop

    // 0x80803F74: bc1t        L_80803F8C
    if (c1cs) {
        // 0x80803F78: nop
    
            goto L_80803F8C;
    }
    // 0x80803F78: nop

    // 0x80803F7C: c.lt.s      $f30, $f20
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f30.fl < ctx->f20.fl;
    // 0x80803F80: nop

    // 0x80803F84: bc1fl       L_80803F98
    if (!c1cs) {
        // 0x80803F88: lwc1        $f12, 0x48($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
            goto L_80803F98;
    }
    goto skip_19;
    // 0x80803F88: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    skip_19:
L_80803F8C:
    // 0x80803F8C: jal         0x80802104
    // 0x80803F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802104_chdodgemcontrol(rdram, ctx);
        goto after_44;
    // 0x80803F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x80803F94: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
L_80803F98:
    // 0x80803F98: jal         0x800F1DCC
    // 0x80803F9C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800F1DCC(rdram, ctx);
        goto after_45;
    // 0x80803F9C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_45:
    // 0x80803FA0: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x80803FA4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80803FA8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80803FAC: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x80803FB0: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80803FB4: nop

    // 0x80803FB8: bc1fl       L_80803FEC
    if (!c1cs) {
        // 0x80803FBC: lui         $at, 0x42A0
        ctx->r1 = S32(0X42A0 << 16);
            goto L_80803FEC;
    }
    goto skip_20;
    // 0x80803FBC: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    skip_20:
    // 0x80803FC0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80803FC4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4CD0) << 16);
    // 0x80803FC8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80803FCC: nop

    // 0x80803FD0: bc1fl       L_80803FEC
    if (!c1cs) {
        // 0x80803FD4: lui         $at, 0x42A0
        ctx->r1 = S32(0X42A0 << 16);
            goto L_80803FEC;
    }
    goto skip_21;
    // 0x80803FD4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    skip_21:
    // 0x80803FD8: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803FDC: lwc1        $f6, 0x4CD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4CD0));
    // 0x80803FE0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80803FE4: swc1        $f8, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->f8.u32l;
    // 0x80803FE8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
L_80803FEC:
    // 0x80803FEC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80803FF0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80803FF4: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80803FF8: nop

    // 0x80803FFC: bc1fl       L_80804030
    if (!c1cs) {
        // 0x80804000: lui         $at, 0xC32A
        ctx->r1 = S32(0XC32A << 16);
            goto L_80804030;
    }
    goto skip_22;
    // 0x80804000: lui         $at, 0xC32A
    ctx->r1 = S32(0XC32A << 16);
    skip_22:
    // 0x80804004: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80804008: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4CD4) << 16);
    // 0x8080400C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80804010: nop

    // 0x80804014: bc1fl       L_80804030
    if (!c1cs) {
        // 0x80804018: lui         $at, 0xC32A
        ctx->r1 = S32(0XC32A << 16);
            goto L_80804030;
    }
    goto skip_23;
    // 0x80804018: lui         $at, 0xC32A
    ctx->r1 = S32(0XC32A << 16);
    skip_23:
    // 0x8080401C: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80804020: lwc1        $f4, 0x4CD4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4CD4));
    // 0x80804024: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80804028: swc1        $f6, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->f6.u32l;
    // 0x8080402C: lui         $at, 0xC32A
    ctx->r1 = S32(0XC32A << 16);
L_80804030:
    // 0x80804030: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80804034: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80804038: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8080403C: nop

    // 0x80804040: bc1fl       L_80804074
    if (!c1cs) {
        // 0x80804044: lui         $at, 0x432A
        ctx->r1 = S32(0X432A << 16);
            goto L_80804074;
    }
    goto skip_24;
    // 0x80804044: lui         $at, 0x432A
    ctx->r1 = S32(0X432A << 16);
    skip_24:
    // 0x80804048: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080404C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4CD8) << 16);
    // 0x80804050: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80804054: nop

    // 0x80804058: bc1fl       L_80804074
    if (!c1cs) {
        // 0x8080405C: lui         $at, 0x432A
        ctx->r1 = S32(0X432A << 16);
            goto L_80804074;
    }
    goto skip_25;
    // 0x8080405C: lui         $at, 0x432A
    ctx->r1 = S32(0X432A << 16);
    skip_25:
    // 0x80804060: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80804064: lwc1        $f18, 0x4CD8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4CD8));
    // 0x80804068: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8080406C: swc1        $f4, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->f4.u32l;
    // 0x80804070: lui         $at, 0x432A
    ctx->r1 = S32(0X432A << 16);
L_80804074:
    // 0x80804074: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80804078: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8080407C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80804080: nop

    // 0x80804084: bc1f        L_808040B4
    if (!c1cs) {
        // 0x80804088: nop
    
            goto L_808040B4;
    }
    // 0x80804088: nop

    // 0x8080408C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80804090: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4CDC) << 16);
    // 0x80804094: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80804098: nop

    // 0x8080409C: bc1f        L_808040B4
    if (!c1cs) {
        // 0x808040A0: nop
    
            goto L_808040B4;
    }
    // 0x808040A0: nop

    // 0x808040A4: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808040A8: lwc1        $f16, 0x4CDC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4CDC));
    // 0x808040AC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808040B0: swc1        $f18, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->f18.u32l;
L_808040B4:
    // 0x808040B4: jal         0x800F1DCC
    // 0x808040B8: lwc1        $f12, 0x48($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X48);
    func_800F1DCC(rdram, ctx);
        goto after_46;
    // 0x808040B8: lwc1        $f12, 0x48($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X48);
    after_46:
    // 0x808040BC: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x808040C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808040C4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808040C8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808040CC: nop

    // 0x808040D0: bc1fl       L_80804104
    if (!c1cs) {
        // 0x808040D4: lui         $at, 0x42A0
        ctx->r1 = S32(0X42A0 << 16);
            goto L_80804104;
    }
    goto skip_26;
    // 0x808040D4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    skip_26:
    // 0x808040D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808040DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4CE0) << 16);
    // 0x808040E0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808040E4: nop

    // 0x808040E8: bc1fl       L_80804104
    if (!c1cs) {
        // 0x808040EC: lui         $at, 0x42A0
        ctx->r1 = S32(0X42A0 << 16);
            goto L_80804104;
    }
    goto skip_27;
    // 0x808040EC: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    skip_27:
    // 0x808040F0: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808040F4: lwc1        $f10, 0x4CE0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4CE0));
    // 0x808040F8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808040FC: swc1        $f16, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->f16.u32l;
    // 0x80804100: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
L_80804104:
    // 0x80804104: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80804108: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8080410C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80804110: nop

    // 0x80804114: bc1fl       L_80804148
    if (!c1cs) {
        // 0x80804118: lui         $at, 0xC32A
        ctx->r1 = S32(0XC32A << 16);
            goto L_80804148;
    }
    goto skip_28;
    // 0x80804118: lui         $at, 0xC32A
    ctx->r1 = S32(0XC32A << 16);
    skip_28:
    // 0x8080411C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80804120: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4CE4) << 16);
    // 0x80804124: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80804128: nop

    // 0x8080412C: bc1fl       L_80804148
    if (!c1cs) {
        // 0x80804130: lui         $at, 0xC32A
        ctx->r1 = S32(0XC32A << 16);
            goto L_80804148;
    }
    goto skip_29;
    // 0x80804130: lui         $at, 0xC32A
    ctx->r1 = S32(0XC32A << 16);
    skip_29:
    // 0x80804134: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80804138: lwc1        $f8, 0x4CE4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4CE4));
    // 0x8080413C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80804140: swc1        $f10, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->f10.u32l;
    // 0x80804144: lui         $at, 0xC32A
    ctx->r1 = S32(0XC32A << 16);
L_80804148:
    // 0x80804148: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080414C: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80804150: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80804154: nop

    // 0x80804158: bc1fl       L_8080418C
    if (!c1cs) {
        // 0x8080415C: lui         $at, 0x432A
        ctx->r1 = S32(0X432A << 16);
            goto L_8080418C;
    }
    goto skip_30;
    // 0x8080415C: lui         $at, 0x432A
    ctx->r1 = S32(0X432A << 16);
    skip_30:
    // 0x80804160: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80804164: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4CE8) << 16);
    // 0x80804168: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8080416C: nop

    // 0x80804170: bc1fl       L_8080418C
    if (!c1cs) {
        // 0x80804174: lui         $at, 0x432A
        ctx->r1 = S32(0X432A << 16);
            goto L_8080418C;
    }
    goto skip_31;
    // 0x80804174: lui         $at, 0x432A
    ctx->r1 = S32(0X432A << 16);
    skip_31:
    // 0x80804178: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080417C: lwc1        $f6, 0x4CE8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4CE8));
    // 0x80804180: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80804184: swc1        $f8, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->f8.u32l;
    // 0x80804188: lui         $at, 0x432A
    ctx->r1 = S32(0X432A << 16);
L_8080418C:
    // 0x8080418C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80804190: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80804194: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80804198: nop

    // 0x8080419C: bc1fl       L_808041D0
    if (!c1cs) {
        // 0x808041A0: lw          $t1, 0xF4($sp)
        ctx->r9 = MEM_W(ctx->r29, 0XF4);
            goto L_808041D0;
    }
    goto skip_32;
    // 0x808041A0: lw          $t1, 0xF4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF4);
    skip_32:
    // 0x808041A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808041A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4CEC) << 16);
    // 0x808041AC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x808041B0: nop

    // 0x808041B4: bc1fl       L_808041D0
    if (!c1cs) {
        // 0x808041B8: lw          $t1, 0xF4($sp)
        ctx->r9 = MEM_W(ctx->r29, 0XF4);
            goto L_808041D0;
    }
    goto skip_33;
    // 0x808041B8: lw          $t1, 0xF4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF4);
    skip_33:
    // 0x808041BC: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808041C0: lwc1        $f4, 0x4CEC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4CEC));
    // 0x808041C4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808041C8: swc1        $f6, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->f6.u32l;
    // 0x808041CC: lw          $t1, 0xF4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF4);
L_808041D0:
    // 0x808041D0: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x808041D4: lbu         $t2, 0xC2($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XC2);
    // 0x808041D8: slt         $at, $s7, $t2
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x808041DC: bnel        $at, $zero, L_80803A60
    if (ctx->r1 != 0) {
        // 0x808041E0: lw          $t7, 0x6C($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X6C);
            goto L_80803A60;
    }
    goto skip_34;
    // 0x808041E0: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
    skip_34:
    // 0x808041E4: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
L_808041E8:
    // 0x808041E8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808041EC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808041F0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808041F4: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808041F8: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x808041FC: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80804200: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80804204: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80804208: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8080420C: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80804210: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80804214: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80804218: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x8080421C: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80804220: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80804224: jr          $ra
    // 0x80804228: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x80804228: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void func_80801428_chnicecavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801428: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080142C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801430: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x80801434: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80801438: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080143C: beql        $t6, $zero, L_80801458
    if (ctx->r14 == 0) {
        // 0x80801440: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801458;
    }
    goto skip_0;
    // 0x80801440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801444: jal         0x800856B8
    // 0x80801448: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _capod_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80801448: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080144C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80801450: sw          $zero, 0x18($a1)
    MEM_W(0X18, ctx->r5) = 0;
    // 0x80801454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801458:
    // 0x80801458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080145C: jr          $ra
    // 0x80801460: nop

    return;
    // 0x80801460: nop

;}
RECOMP_FUNC void func_80106520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106520: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80106524: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80106528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010652C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80106530: lw          $a0, 0x6ED4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6ED4);
    // 0x80106534: jal         0x800B296C
    // 0x80106538: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    vector_end(rdram, ctx);
        goto after_0;
    // 0x80106538: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8010653C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80106540: lw          $a0, 0x6ED4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6ED4);
    // 0x80106544: jal         0x800B28C4
    // 0x80106548: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    vector_begin(rdram, ctx);
        goto after_1;
    // 0x80106548: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x8010654C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80106550: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80106554: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80106558: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x8010655C: beq         $at, $zero, L_80106598
    if (ctx->r1 == 0) {
        // 0x80106560: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80106598;
    }
    // 0x80106560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80106564: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80106568: lh          $t6, 0x4($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X4);
L_8010656C:
    // 0x8010656C: bnel        $v0, $t6, L_8010658C
    if (ctx->r2 != ctx->r14) {
        // 0x80106570: addiu       $v1, $v1, 0xA8
        ctx->r3 = ADD32(ctx->r3, 0XA8);
            goto L_8010658C;
    }
    goto skip_0;
    // 0x80106570: addiu       $v1, $v1, 0xA8
    ctx->r3 = ADD32(ctx->r3, 0XA8);
    skip_0:
    // 0x80106574: lh          $t7, 0x6($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X6);
    // 0x80106578: bnel        $a2, $t7, L_8010658C
    if (ctx->r6 != ctx->r15) {
        // 0x8010657C: addiu       $v1, $v1, 0xA8
        ctx->r3 = ADD32(ctx->r3, 0XA8);
            goto L_8010658C;
    }
    goto skip_1;
    // 0x8010657C: addiu       $v1, $v1, 0xA8
    ctx->r3 = ADD32(ctx->r3, 0XA8);
    skip_1:
    // 0x80106580: b           L_8010659C
    // 0x80106584: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
        goto L_8010659C;
    // 0x80106584: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80106588: addiu       $v1, $v1, 0xA8
    ctx->r3 = ADD32(ctx->r3, 0XA8);
L_8010658C:
    // 0x8010658C: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x80106590: bnel        $at, $zero, L_8010656C
    if (ctx->r1 != 0) {
        // 0x80106594: lh          $t6, 0x4($v1)
        ctx->r14 = MEM_H(ctx->r3, 0X4);
            goto L_8010656C;
    }
    goto skip_2;
    // 0x80106594: lh          $t6, 0x4($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X4);
    skip_2:
L_80106598:
    // 0x80106598: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010659C:
    // 0x8010659C: jr          $ra
    // 0x801065A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801065A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_808005C0_chweldarbossfusebox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005C4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808005C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005CC: bne         $a1, $at, L_808005E4
    if (ctx->r5 != ctx->r1) {
        // 0x808005D0: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808005E4;
    }
    // 0x808005D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808005D4: jal         0x80103110
    // 0x808005D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_0;
    // 0x808005D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808005DC: b           L_808005E8
    // 0x808005E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005E8;
    // 0x808005E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005E4:
    // 0x808005E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005E8:
    // 0x808005E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005F0: jr          $ra
    // 0x808005F4: nop

    return;
    // 0x808005F4: nop

;}
RECOMP_FUNC void func_80800FEC_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800FF0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800FF4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800FF8: jal         0x808001FC
    // 0x80800FFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808001FC_bsstatue(rdram, ctx);
        goto after_0;
    // 0x80800FFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801004: addiu       $a1, $zero, 0x1F1
    ctx->r5 = ADD32(0, 0X1F1);
    // 0x80801008: jal         0x8008CCBC
    // 0x8080100C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x8080100C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_1:
    // 0x80801010: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80801014: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080101C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801020: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801024: jal         0x8009FFD8
    // 0x80801028: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80801028: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x8080102C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801030: jal         0x8009B9B0
    // 0x80801034: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x80801034: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80801038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080103C: jal         0x8009BA9C
    // 0x80801040: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_4;
    // 0x80801040: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80801044: jal         0x800FC660
    // 0x80801048: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC660(rdram, ctx);
        goto after_5;
    // 0x80801048: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_5:
    // 0x8080104C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801050: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801054: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801058: jr          $ra
    // 0x8080105C: nop

    return;
    // 0x8080105C: nop

;}
RECOMP_FUNC void func_80800F3C_cadbfunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F44: jal         0x800A587C
    // 0x80800F48: nop

    func_800A587C(rdram, ctx);
        goto after_0;
    // 0x80800F48: nop

    after_0:
    // 0x80800F4C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800F50: bnel        $v0, $at, L_80800F6C
    if (ctx->r2 != ctx->r1) {
        // 0x80800F54: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800F6C;
    }
    goto skip_0;
    // 0x80800F54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800F58: jal         0x800A586C
    // 0x80800F5C: nop

    func_800A586C(rdram, ctx);
        goto after_1;
    // 0x80800F5C: nop

    after_1:
    // 0x80800F60: b           L_80800F6C
    // 0x80800F64: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
        goto L_80800F6C;
    // 0x80800F64: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x80800F68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800F6C:
    // 0x80800F6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F74: jr          $ra
    // 0x80800F78: nop

    return;
    // 0x80800F78: nop

;}
RECOMP_FUNC void func_800C67E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C67E0: jr          $ra
    // 0x800C67E4: lw          $v0, 0x80($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X80);
    return;
    // 0x800C67E4: lw          $v0, 0x80($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X80);
;}
RECOMP_FUNC void func_80801DEC_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801DEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801DF0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80801DF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801DF8: beq         $a1, $at, L_80801E24
    if (ctx->r5 == ctx->r1) {
        // 0x80801DFC: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80801E24;
    }
    // 0x80801DFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801E00: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80801E04: beq         $a1, $at, L_80801F04
    if (ctx->r5 == ctx->r1) {
        // 0x80801E08: addiu       $at, $zero, 0x49
        ctx->r1 = ADD32(0, 0X49);
            goto L_80801F04;
    }
    // 0x80801E08: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x80801E0C: beq         $a1, $at, L_80801EBC
    if (ctx->r5 == ctx->r1) {
        // 0x80801E10: addiu       $at, $zero, 0x77
        ctx->r1 = ADD32(0, 0X77);
            goto L_80801EBC;
    }
    // 0x80801E10: addiu       $at, $zero, 0x77
    ctx->r1 = ADD32(0, 0X77);
    // 0x80801E14: beq         $a1, $at, L_80801F20
    if (ctx->r5 == ctx->r1) {
        // 0x80801E18: lw          $t1, 0x18($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X18);
            goto L_80801F20;
    }
    // 0x80801E18: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80801E1C: b           L_80801F74
    // 0x80801E20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801F74;
    // 0x80801E20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801E24:
    // 0x80801E24: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80801E28: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801E2C: lhu         $t7, 0x72($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X72);
    // 0x80801E30: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80801E34: bne         $t8, $at, L_80801EB4
    if (ctx->r24 != ctx->r1) {
        // 0x80801E38: nop
    
            goto L_80801EB4;
    }
    // 0x80801E38: nop

    // 0x80801E3C: jal         0x800F54E4
    // 0x80801E40: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80801E40: nop

    after_0:
    // 0x80801E44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801E48: jal         0x800F7F98
    // 0x80801E4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_1;
    // 0x80801E4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801E50: jal         0x800F54E4
    // 0x80801E54: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80801E54: nop

    after_2:
    // 0x80801E58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801E5C: jal         0x800F7B9C
    // 0x80801E60: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    func_800F7B9C(rdram, ctx);
        goto after_3;
    // 0x80801E60: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    after_3:
    // 0x80801E64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801E68: jal         0x80101FDC
    // 0x80801E6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80801E6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80801E70: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80801E74: jal         0x800D0A9C
    // 0x80801E78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_5;
    // 0x80801E78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80801E7C: bne         $v0, $zero, L_80801EB4
    if (ctx->r2 != 0) {
        // 0x80801E80: nop
    
            goto L_80801EB4;
    }
    // 0x80801E80: nop

    // 0x80801E84: jal         0x800EA090
    // 0x80801E88: nop

    func_800EA090(rdram, ctx);
        goto after_6;
    // 0x80801E88: nop

    after_6:
    // 0x80801E8C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801E90: bne         $v0, $at, L_80801EAC
    if (ctx->r2 != ctx->r1) {
        // 0x80801E94: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801EAC;
    }
    // 0x80801E94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801E98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801E9C: jal         0x80801974
    // 0x80801EA0: addiu       $a1, $zero, 0xFAB
    ctx->r5 = ADD32(0, 0XFAB);
    func_80801974_chtntmineshoot(rdram, ctx);
        goto after_7;
    // 0x80801EA0: addiu       $a1, $zero, 0xFAB
    ctx->r5 = ADD32(0, 0XFAB);
    after_7:
    // 0x80801EA4: b           L_80801F74
    // 0x80801EA8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80801F74;
    // 0x80801EA8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80801EAC:
    // 0x80801EAC: jal         0x80801974
    // 0x80801EB0: addiu       $a1, $zero, 0xFA4
    ctx->r5 = ADD32(0, 0XFA4);
    func_80801974_chtntmineshoot(rdram, ctx);
        goto after_8;
    // 0x80801EB0: addiu       $a1, $zero, 0xFA4
    ctx->r5 = ADD32(0, 0XFA4);
    after_8:
L_80801EB4:
    // 0x80801EB4: b           L_80801F74
    // 0x80801EB8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80801F74;
    // 0x80801EB8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80801EBC:
    // 0x80801EBC: jal         0x80088840
    // 0x80801EC0: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_9;
    // 0x80801EC0: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_9:
    // 0x80801EC4: beq         $v0, $zero, L_80801F70
    if (ctx->r2 == 0) {
        // 0x80801EC8: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_80801F70;
    }
    // 0x80801EC8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80801ECC: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80801ED0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801ED4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801ED8: jal         0x80085708
    // 0x80801EDC: addiu       $a3, $zero, 0x900
    ctx->r7 = ADD32(0, 0X900);
    _capod_entrypoint_13(rdram, ctx);
        goto after_10;
    // 0x80801EDC: addiu       $a3, $zero, 0x900
    ctx->r7 = ADD32(0, 0X900);
    after_10:
    // 0x80801EE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801EE4: jal         0x80101FDC
    // 0x80801EE8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_11;
    // 0x80801EE8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_11:
    // 0x80801EEC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2204, 0X2540) << 16);
    // 0x80801EF0: lwc1        $f4, 0x2540($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2204, 0X2540));
    // 0x80801EF4: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80801EF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801EFC: b           L_80801F74
    // 0x80801F00: swc1        $f4, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->f4.u32l;
        goto L_80801F74;
    // 0x80801F00: swc1        $f4, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->f4.u32l;
L_80801F04:
    // 0x80801F04: jal         0x800F54E4
    // 0x80801F08: nop

    func_800F54E4(rdram, ctx);
        goto after_12;
    // 0x80801F08: nop

    after_12:
    // 0x80801F0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801F10: jal         0x800F7F98
    // 0x80801F14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_13;
    // 0x80801F14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80801F18: b           L_80801F74
    // 0x80801F1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801F74;
    // 0x80801F1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801F20:
    // 0x80801F20: lhu         $t2, 0x72($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X72);
    // 0x80801F24: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801F28: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80801F2C: srl         $t3, $t2, 10
    ctx->r11 = S32(U32(ctx->r10) >> 10);
    // 0x80801F30: bnel        $t3, $at, L_80801F74
    if (ctx->r11 != ctx->r1) {
        // 0x80801F34: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80801F74;
    }
    goto skip_0;
    // 0x80801F34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80801F38: jal         0x800F7B9C
    // 0x80801F3C: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    func_800F7B9C(rdram, ctx);
        goto after_14;
    // 0x80801F3C: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    after_14:
    // 0x80801F40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801F44: jal         0x80101FDC
    // 0x80801F48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_15;
    // 0x80801F48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80801F4C: jal         0x80085710
    // 0x80801F50: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_16;
    // 0x80801F50: nop

    after_16:
    // 0x80801F54: jal         0x800F54E4
    // 0x80801F58: nop

    func_800F54E4(rdram, ctx);
        goto after_17;
    // 0x80801F58: nop

    after_17:
    // 0x80801F5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801F60: jal         0x800F7B9C
    // 0x80801F64: addiu       $a1, $zero, 0x99
    ctx->r5 = ADD32(0, 0X99);
    func_800F7B9C(rdram, ctx);
        goto after_18;
    // 0x80801F64: addiu       $a1, $zero, 0x99
    ctx->r5 = ADD32(0, 0X99);
    after_18:
    // 0x80801F68: b           L_80801F74
    // 0x80801F6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801F74;
    // 0x80801F6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801F70:
    // 0x80801F70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801F74:
    // 0x80801F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801F78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801F7C: jr          $ra
    // 0x80801F80: nop

    return;
    // 0x80801F80: nop

;}
RECOMP_FUNC void batranslate_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000D8: beq         $a1, $at, L_808000F4
    if (ctx->r5 == ctx->r1) {
        // 0x808000DC: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_808000F4;
    }
    // 0x808000DC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808000E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000E4: beql        $a1, $at, L_8080011C
    if (ctx->r5 == ctx->r1) {
        // 0x808000E8: lw          $a0, 0x140($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X140);
            goto L_8080011C;
    }
    goto skip_0;
    // 0x808000E8: lw          $a0, 0x140($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X140);
    skip_0:
    // 0x808000EC: b           L_80800144
    // 0x808000F0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
        goto L_80800144;
    // 0x808000F0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
L_808000F4:
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F8: jal         0x8008C9E4
    // 0x808000FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008C9E4(rdram, ctx);
        goto after_0;
    // 0x808000FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800104: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800108: jal         0x8009ADF0
    // 0x8080010C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8009ADF0(rdram, ctx);
        goto after_1;
    // 0x8080010C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800110: b           L_80800144
    // 0x80800114: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
        goto L_80800144;
    // 0x80800114: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80800118: lw          $a0, 0x140($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X140);
L_8080011C:
    // 0x8080011C: jal         0x800EFD24
    // 0x80800120: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x80800120: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_2:
    // 0x80800124: lw          $t8, 0x140($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X140);
    // 0x80800128: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800130: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800134: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800138: jal         0x8009ADF0
    // 0x8080013C: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    func_8009ADF0(rdram, ctx);
        goto after_3;
    // 0x8080013C: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    after_3:
    // 0x80800140: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
L_80800144:
    // 0x80800144: lw          $t0, 0x140($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X140);
    // 0x80800148: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8080014C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800150: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800154: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800158: jr          $ra
    // 0x8080015C: nop

    return;
    // 0x8080015C: nop

;}
RECOMP_FUNC void func_8010F070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010F070: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8010F074: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x8010F078: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8010F07C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8010F080: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8010F084: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010F088: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8010F08C: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8010F090: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8010F094: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8010F098: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8010F09C: jal         0x800DF8CC
    // 0x8010F0A0: lw          $a0, 0x7210($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7210);
    func_800DF8CC(rdram, ctx);
        goto after_0;
    // 0x8010F0A0: lw          $a0, 0x7210($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7210);
    after_0:
    // 0x8010F0A4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8010F0A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010F0AC: lw          $a0, 0x7210($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7210);
    // 0x8010F0B0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8010F0B4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8010F0B8: jal         0x800DF8B4
    // 0x8010F0BC: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    func_800DF8B4(rdram, ctx);
        goto after_1;
    // 0x8010F0BC: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    after_1:
    // 0x8010F0C0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8010F0C4: sll         $t0, $s4, 4
    ctx->r8 = S32(ctx->r20 << 4);
    // 0x8010F0C8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8010F0CC: sll         $t9, $v1, 4
    ctx->r25 = S32(ctx->r3 << 4);
    // 0x8010F0D0: addu        $s0, $t9, $v0
    ctx->r16 = ADD32(ctx->r25, ctx->r2);
    // 0x8010F0D4: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x8010F0D8: addu        $t1, $v1, $s4
    ctx->r9 = ADD32(ctx->r3, ctx->r20);
    // 0x8010F0DC: addu        $s3, $t0, $s0
    ctx->r19 = ADD32(ctx->r8, ctx->r16);
    // 0x8010F0E0: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8010F0E4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8010F0E8: jal         0x80100480
    // 0x8010F0EC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_80100480(rdram, ctx);
        goto after_2;
    // 0x8010F0EC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
    // 0x8010F0F0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8010F0F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8010F0F8: jal         0x80100480
    // 0x8010F0FC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_80100480(rdram, ctx);
        goto after_3;
    // 0x8010F0FC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_3:
    // 0x8010F100: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8010F104: lbu         $t2, 0x7238($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X7238);
    // 0x8010F108: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8010F10C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8010F110: beq         $t2, $zero, L_8010F158
    if (ctx->r10 == 0) {
        // 0x8010F114: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_8010F158;
    }
    // 0x8010F114: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010F118: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010F11C: addiu       $a2, $a2, 0x7220
    ctx->r6 = ADD32(ctx->r6, 0X7220);
    // 0x8010F120: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8010F124: jal         0x800F24D0
    // 0x8010F128: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_800F24D0(rdram, ctx);
        goto after_4;
    // 0x8010F128: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_4:
    // 0x8010F12C: jal         0x800EF2A0
    // 0x8010F130: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_800EF2A0(rdram, ctx);
        goto after_5;
    // 0x8010F130: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_5:
    // 0x8010F134: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010F138: addiu       $a2, $a2, 0x722C
    ctx->r6 = ADD32(ctx->r6, 0X722C);
    // 0x8010F13C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8010F140: jal         0x800F24D0
    // 0x8010F144: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800F24D0(rdram, ctx);
        goto after_6;
    // 0x8010F144: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_6:
    // 0x8010F148: jal         0x800EF2A0
    // 0x8010F14C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_800EF2A0(rdram, ctx);
        goto after_7;
    // 0x8010F14C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_7:
    // 0x8010F150: b           L_8010F174
    // 0x8010F154: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
        goto L_8010F174;
    // 0x8010F154: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
L_8010F158:
    // 0x8010F158: jal         0x800EE7F8
    // 0x8010F15C: addiu       $a1, $a1, 0x7220
    ctx->r5 = ADD32(ctx->r5, 0X7220);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x8010F15C: addiu       $a1, $a1, 0x7220
    ctx->r5 = ADD32(ctx->r5, 0X7220);
    after_8:
    // 0x8010F160: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010F164: addiu       $a1, $a1, 0x722C
    ctx->r5 = ADD32(ctx->r5, 0X722C);
    // 0x8010F168: jal         0x800EE7F8
    // 0x8010F16C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x8010F16C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_9:
    // 0x8010F170: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
L_8010F174:
    // 0x8010F174: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x8010F178: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8010F17C: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8010F180: jal         0x801164E0
    // 0x8010F184: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    func_801164E0(rdram, ctx);
        goto after_10;
    // 0x8010F184: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_10:
    // 0x8010F188: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8010F18C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8010F190: jal         0x8011649C
    // 0x8010F194: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_8011649C(rdram, ctx);
        goto after_11;
    // 0x8010F194: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_11:
    // 0x8010F198: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8010F19C: sltu        $at, $s0, $t3
    ctx->r1 = ctx->r16 < ctx->r11 ? 1 : 0;
    // 0x8010F1A0: beq         $at, $zero, L_8010F250
    if (ctx->r1 == 0) {
        // 0x8010F1A4: lui         $at, 0x4478
        ctx->r1 = S32(0X4478 << 16);
            goto L_8010F250;
    }
    // 0x8010F1A4: lui         $at, 0x4478
    ctx->r1 = S32(0X4478 << 16);
    // 0x8010F1A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8010F1AC: nop

    // 0x8010F1B0: lwc1        $f16, 0x0($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8010F1B4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8010F1B8: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x8010F1BC: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8010F1C0: beql        $at, $zero, L_8010F21C
    if (ctx->r1 == 0) {
        // 0x8010F1C4: add.s       $f16, $f18, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f0.fl;
            goto L_8010F21C;
    }
    goto skip_0;
    // 0x8010F1C4: add.s       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f0.fl;
    skip_0:
    // 0x8010F1C8: add.s       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f0.fl;
L_8010F1CC:
    // 0x8010F1CC: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8010F1D0: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x8010F1D4: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x8010F1D8: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8010F1DC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8010F1E0: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x8010F1E4: nop

    // 0x8010F1E8: sh          $t5, -0x18($s0)
    MEM_H(-0X18, ctx->r16) = ctx->r13;
    // 0x8010F1EC: lwc1        $f16, -0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, -0XC);
    // 0x8010F1F0: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8010F1F4: add.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x8010F1F8: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8010F1FC: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x8010F200: nop

    // 0x8010F204: sh          $t7, -0x16($s0)
    MEM_H(-0X16, ctx->r16) = ctx->r15;
    // 0x8010F208: lwc1        $f16, 0x0($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8010F20C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8010F210: bnel        $at, $zero, L_8010F1CC
    if (ctx->r1 != 0) {
        // 0x8010F214: add.s       $f16, $f18, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f0.fl;
            goto L_8010F1CC;
    }
    goto skip_1;
    // 0x8010F214: add.s       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f0.fl;
    skip_1:
    // 0x8010F218: add.s       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f0.fl;
L_8010F21C:
    // 0x8010F21C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x8010F220: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8010F224: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8010F228: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x8010F22C: nop

    // 0x8010F230: sh          $t5, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r13;
    // 0x8010F234: lwc1        $f16, -0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, -0XC);
    // 0x8010F238: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8010F23C: add.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x8010F240: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8010F244: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x8010F248: nop

    // 0x8010F24C: sh          $t7, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r15;
L_8010F250:
    // 0x8010F250: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8010F254: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8010F258: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8010F25C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8010F260: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8010F264: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8010F268: jr          $ra
    // 0x8010F26C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8010F26C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80020F70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020F70: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80020F74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80020F78: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80020F7C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80020F80: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80020F84: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80020F88: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80020F8C: lw          $t8, 0x11F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X11F4);
    // 0x80020F90: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x80020F94: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80020F98: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80020F9C: lw          $t1, 0x11F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X11F4);
    // 0x80020FA0: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80020FA4: sw          $t0, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->r8;
    // 0x80020FA8: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x80020FAC: lw          $t2, 0x11F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X11F4);
    // 0x80020FB0: sw          $zero, 0x20($t2)
    MEM_W(0X20, ctx->r10) = 0;
    // 0x80020FB4: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x80020FB8: lw          $t3, 0x11F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X11F4);
    // 0x80020FBC: sw          $zero, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = 0;
    // 0x80020FC0: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80020FC4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80020FC8: lw          $t6, 0x11F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11F4);
    // 0x80020FCC: lw          $t5, 0x18($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X18);
    // 0x80020FD0: sw          $t5, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->r13;
    // 0x80020FD4: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80020FD8: lw          $t8, 0x11F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X11F4);
    // 0x80020FDC: addiu       $t7, $zero, 0xB8
    ctx->r15 = ADD32(0, 0XB8);
    // 0x80020FE0: sw          $t7, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->r15;
    // 0x80020FE4: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80020FE8: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80020FEC: lw          $t1, 0x11F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X11F4);
    // 0x80020FF0: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x80020FF4: sw          $t0, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r8;
    // 0x80020FF8: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x80020FFC: lw          $t2, 0x11F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X11F4);
    // 0x80021000: sw          $zero, 0x48($t2)
    MEM_W(0X48, ctx->r10) = 0;
    // 0x80021004: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80021008: lw          $t4, 0x11F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X11F4);
    // 0x8002100C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80021010: sw          $t3, 0x4C($t4)
    MEM_W(0X4C, ctx->r12) = ctx->r11;
    // 0x80021014: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80021018: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8002101C: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80021020: bne         $at, $zero, L_8002103C
    if (ctx->r1 != 0) {
        // 0x80021024: nop
    
            goto L_8002103C;
    }
    // 0x80021024: nop

    // 0x80021028: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8002102C: lw          $t8, 0x11F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X11F4);
    // 0x80021030: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80021034: b           L_80021074
    // 0x80021038: sw          $t7, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->r15;
        goto L_80021074;
    // 0x80021038: sw          $t7, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->r15;
L_8002103C:
    // 0x8002103C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80021040: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80021044: bgtz        $t0, L_80021060
    if (SIGNED(ctx->r8) > 0) {
        // 0x80021048: nop
    
            goto L_80021060;
    }
    // 0x80021048: nop

    // 0x8002104C: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x80021050: lw          $t2, 0x11F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X11F4);
    // 0x80021054: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80021058: b           L_80021074
    // 0x8002105C: sw          $t1, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = ctx->r9;
        goto L_80021074;
    // 0x8002105C: sw          $t1, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = ctx->r9;
L_80021060:
    // 0x80021060: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80021064: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x80021068: lw          $t5, 0x11F4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X11F4);
    // 0x8002106C: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x80021070: sw          $t4, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->r12;
L_80021074:
    // 0x80021074: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80021078: lw          $t6, 0x11F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11F4);
    // 0x8002107C: addiu       $t7, $zero, 0x48
    ctx->r15 = ADD32(0, 0X48);
    // 0x80021080: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80021084: lw          $a3, 0x3C($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X3C);
    // 0x80021088: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8002108C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021090: jal         0x80020EE4
    // 0x80021094: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_80020EE4(rdram, ctx);
        goto after_0;
    // 0x80021094: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_0:
    // 0x80021098: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8002109C: lw          $t8, 0x11F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X11F4);
    // 0x800210A0: sw          $v0, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->r2;
    // 0x800210A4: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x800210A8: lw          $t9, 0x11F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11F4);
    // 0x800210AC: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x800210B0: lw          $t0, 0x3C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X3C);
    // 0x800210B4: blez        $t0, L_800212D8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800210B8: nop
    
            goto L_800212D8;
    }
    // 0x800210B8: nop

L_800210BC:
    // 0x800210BC: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x800210C0: lw          $t1, 0x11F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X11F4);
    // 0x800210C4: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800210C8: lw          $t2, 0x34($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X34);
    // 0x800210CC: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800210D0: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800210D4: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800210D8: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800210DC: sw          $zero, 0x14($t5)
    MEM_W(0X14, ctx->r13) = 0;
    // 0x800210E0: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x800210E4: lw          $t8, 0x11F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X11F4);
    // 0x800210E8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800210EC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800210F0: lw          $t9, 0x34($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X34);
    // 0x800210F4: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800210F8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800210FC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80021100: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80021104: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x80021108: sw          $t7, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->r15;
    // 0x8002110C: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80021110: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80021114: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80021118: lw          $a3, 0x4($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X4);
    // 0x8002111C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80021120: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021124: jal         0x80020EE4
    // 0x80021128: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_80020EE4(rdram, ctx);
        goto after_1;
    // 0x80021128: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x8002112C: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x80021130: lw          $t5, 0x11F4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X11F4);
    // 0x80021134: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80021138: lw          $t6, 0x34($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X34);
    // 0x8002113C: sll         $t0, $t8, 3
    ctx->r8 = S32(ctx->r24 << 3);
    // 0x80021140: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x80021144: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80021148: addu        $t9, $t6, $t0
    ctx->r25 = ADD32(ctx->r14, ctx->r8);
    // 0x8002114C: sw          $v0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->r2;
    // 0x80021150: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80021154: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80021158: addu        $t3, $t1, $t7
    ctx->r11 = ADD32(ctx->r9, ctx->r15);
    // 0x8002115C: lbu         $t2, 0x1C($t3)
    ctx->r10 = MEM_BU(ctx->r11, 0X1C);
    // 0x80021160: beq         $t2, $zero, L_800211A0
    if (ctx->r10 == 0) {
        // 0x80021164: nop
    
            goto L_800211A0;
    }
    // 0x80021164: nop

    // 0x80021168: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8002116C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80021170: jal         0x80027220
    // 0x80021174: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_80027220(rdram, ctx);
        goto after_2;
    // 0x80021174: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80021178: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x8002117C: lw          $t4, 0x11F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X11F4);
    // 0x80021180: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80021184: lw          $t5, 0x34($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X34);
    // 0x80021188: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x8002118C: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x80021190: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80021194: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
    // 0x80021198: b           L_800211C4
    // 0x8002119C: sw          $v0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r2;
        goto L_800211C4;
    // 0x8002119C: sw          $v0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r2;
L_800211A0:
    // 0x800211A0: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x800211A4: lw          $t9, 0x11F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11F4);
    // 0x800211A8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800211AC: lw          $t1, 0x34($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X34);
    // 0x800211B0: sll         $t3, $t7, 3
    ctx->r11 = S32(ctx->r15 << 3);
    // 0x800211B4: addu        $t3, $t3, $t7
    ctx->r11 = ADD32(ctx->r11, ctx->r15);
    // 0x800211B8: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800211BC: addu        $t2, $t1, $t3
    ctx->r10 = ADD32(ctx->r9, ctx->r11);
    // 0x800211C0: sw          $zero, 0x20($t2)
    MEM_W(0X20, ctx->r10) = 0;
L_800211C4:
    // 0x800211C4: addiu       $t4, $zero, 0x38
    ctx->r12 = ADD32(0, 0X38);
    // 0x800211C8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800211CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800211D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800211D4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800211D8: jal         0x80020EE4
    // 0x800211DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80020EE4(rdram, ctx);
        goto after_3;
    // 0x800211DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x800211E0: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x800211E4: lw          $t8, 0x11F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X11F4);
    // 0x800211E8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800211EC: lw          $t5, 0x34($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X34);
    // 0x800211F0: sll         $t0, $t6, 3
    ctx->r8 = S32(ctx->r14 << 3);
    // 0x800211F4: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x800211F8: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800211FC: addu        $t9, $t5, $t0
    ctx->r25 = ADD32(ctx->r13, ctx->r8);
    // 0x80021200: sw          $v0, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->r2;
    // 0x80021204: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80021208: lw          $t7, 0x11F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X11F4);
    // 0x8002120C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80021210: lw          $t1, 0x34($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X34);
    // 0x80021214: sll         $t2, $t3, 3
    ctx->r10 = S32(ctx->r11 << 3);
    // 0x80021218: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x8002121C: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80021220: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x80021224: lw          $t8, 0x44($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X44);
    // 0x80021228: sh          $zero, 0x2($t8)
    MEM_H(0X2, ctx->r24) = 0;
    // 0x8002122C: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80021230: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80021234: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80021238: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002123C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80021240: jal         0x80020EE4
    // 0x80021244: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80020EE4(rdram, ctx);
        goto after_4;
    // 0x80021244: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80021248: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x8002124C: lw          $t5, 0x11F4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X11F4);
    // 0x80021250: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80021254: lw          $t0, 0x34($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X34);
    // 0x80021258: sll         $t7, $t9, 3
    ctx->r15 = S32(ctx->r25 << 3);
    // 0x8002125C: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x80021260: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80021264: addu        $t3, $t0, $t7
    ctx->r11 = ADD32(ctx->r8, ctx->r15);
    // 0x80021268: lw          $t1, 0x44($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X44);
    // 0x8002126C: sw          $v0, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = ctx->r2;
    // 0x80021270: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x80021274: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80021278: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002127C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021280: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80021284: jal         0x80020EE4
    // 0x80021288: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80020EE4(rdram, ctx);
        goto after_5;
    // 0x80021288: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x8002128C: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80021290: lw          $t4, 0x11F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X11F4);
    // 0x80021294: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80021298: lw          $t8, 0x34($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X34);
    // 0x8002129C: sll         $t5, $t6, 3
    ctx->r13 = S32(ctx->r14 << 3);
    // 0x800212A0: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x800212A4: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800212A8: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x800212AC: lw          $t0, 0x44($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X44);
    // 0x800212B0: sw          $v0, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r2;
    // 0x800212B4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800212B8: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x800212BC: lw          $t1, 0x11F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X11F4);
    // 0x800212C0: addiu       $t3, $t7, 0x1
    ctx->r11 = ADD32(ctx->r15, 0X1);
    // 0x800212C4: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x800212C8: lw          $t2, 0x3C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X3C);
    // 0x800212CC: slt         $at, $t3, $t2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800212D0: bne         $at, $zero, L_800210BC
    if (ctx->r1 != 0) {
        // 0x800212D4: nop
    
            goto L_800210BC;
    }
    // 0x800212D4: nop

L_800212D8:
    // 0x800212D8: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x800212DC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800212E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800212E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800212E8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800212EC: jal         0x80020EE4
    // 0x800212F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80020EE4(rdram, ctx);
        goto after_6;
    // 0x800212F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x800212F4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800212F8: lw          $t6, 0x11F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11F4);
    // 0x800212FC: sw          $v0, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r2;
    // 0x80021300: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x80021304: lw          $t5, 0x11F4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X11F4);
    // 0x80021308: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x8002130C: addiu       $t8, $t8, 0x72B0
    ctx->r24 = ADD32(ctx->r24, 0X72B0);
    // 0x80021310: lw          $t9, 0x30($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X30);
    // 0x80021314: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x80021318: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x8002131C: lw          $t0, 0x11F4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X11F4);
    // 0x80021320: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80021324: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80021328: lw          $t7, 0x11F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X11F4);
    // 0x8002132C: sw          $zero, 0x8($t7)
    MEM_W(0X8, ctx->r15) = 0;
    // 0x80021330: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80021334: lw          $t1, 0x11F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X11F4);
    // 0x80021338: sw          $zero, 0x14($t1)
    MEM_W(0X14, ctx->r9) = 0;
    // 0x8002133C: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x80021340: lw          $t3, 0x11F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X11F4);
    // 0x80021344: sw          $zero, 0x18($t3)
    MEM_W(0X18, ctx->r11) = 0;
    // 0x80021348: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x8002134C: lw          $t2, 0x11F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X11F4);
    // 0x80021350: sw          $zero, 0xC($t2)
    MEM_W(0XC, ctx->r10) = 0;
    // 0x80021354: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80021358: lw          $t4, 0x11F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X11F4);
    // 0x8002135C: sw          $zero, 0x10($t4)
    MEM_W(0X10, ctx->r12) = 0;
    // 0x80021360: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80021364: addiu       $t5, $zero, 0xC0
    ctx->r13 = ADD32(0, 0XC0);
    // 0x80021368: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002136C: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x80021370: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80021374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021378: jal         0x80020EE4
    // 0x8002137C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_80020EE4(rdram, ctx);
        goto after_7;
    // 0x8002137C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x80021380: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80021384: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80021388: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8002138C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80021390: blez        $t9, L_800214A8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80021394: nop
    
            goto L_800214A8;
    }
    // 0x80021394: nop

L_80021398:
    // 0x80021398: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8002139C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800213A0: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x800213A4: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x800213A8: sll         $t7, $t7, 6
    ctx->r15 = S32(ctx->r15 << 6);
    // 0x800213AC: addu        $t3, $t7, $t1
    ctx->r11 = ADD32(ctx->r15, ctx->r9);
    // 0x800213B0: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x800213B4: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800213B8: lw          $a1, 0x11F4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X11F4);
    // 0x800213BC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800213C0: jal         0x80020E40
    // 0x800213C4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80020E40(rdram, ctx);
        goto after_8;
    // 0x800213C4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_8:
    // 0x800213C8: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800213CC: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x800213D0: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x800213D4: lw          $t4, 0x11F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X11F4);
    // 0x800213D8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800213DC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800213E0: jal         0x800293B4
    // 0x800213E4: lw          $a1, 0x24($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X24);
    func_800293B4(rdram, ctx);
        goto after_9;
    // 0x800213E4: lw          $a1, 0x24($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X24);
    after_9:
    // 0x800213E8: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800213EC: lw          $t6, 0x11F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11F4);
    // 0x800213F0: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800213F4: lw          $t5, 0x3C($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X3C);
    // 0x800213F8: blez        $t5, L_80021488
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800213FC: nop
    
            goto L_80021488;
    }
    // 0x800213FC: nop

L_80021400:
    // 0x80021400: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80021404: lw          $t9, 0x11F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11F4);
    // 0x80021408: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8002140C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80021410: lw          $t0, 0x34($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X34);
    // 0x80021414: sll         $t1, $t7, 3
    ctx->r9 = S32(ctx->r15 << 3);
    // 0x80021418: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x8002141C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80021420: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x80021424: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x80021428: lw          $t2, 0x1C($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X1C);
    // 0x8002142C: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80021430: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80021434: addu        $t5, $t2, $t6
    ctx->r13 = ADD32(ctx->r10, ctx->r14);
    // 0x80021438: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x8002143C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80021440: lw          $t9, 0x11F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11F4);
    // 0x80021444: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80021448: lw          $t7, 0x34($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X34);
    // 0x8002144C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80021450: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80021454: addu        $t3, $t7, $t1
    ctx->r11 = ADD32(ctx->r15, ctx->r9);
    // 0x80021458: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x8002145C: addiu       $t2, $t4, 0x1
    ctx->r10 = ADD32(ctx->r12, 0X1);
    // 0x80021460: sw          $t2, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r10;
    // 0x80021464: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80021468: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x8002146C: lw          $t5, 0x11F4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X11F4);
    // 0x80021470: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80021474: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x80021478: lw          $t9, 0x3C($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X3C);
    // 0x8002147C: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80021480: bne         $at, $zero, L_80021400
    if (ctx->r1 != 0) {
        // 0x80021484: nop
    
            goto L_80021400;
    }
    // 0x80021484: nop

L_80021488:
    // 0x80021488: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8002148C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80021490: addiu       $t7, $t0, 0x1
    ctx->r15 = ADD32(ctx->r8, 0X1);
    // 0x80021494: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80021498: lw          $t4, 0x4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X4);
    // 0x8002149C: slt         $at, $t7, $t4
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800214A0: bne         $at, $zero, L_80021398
    if (ctx->r1 != 0) {
        // 0x800214A4: nop
    
            goto L_80021398;
    }
    // 0x800214A4: nop

L_800214A8:
    // 0x800214A8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800214AC: addiu       $t3, $zero, 0x24
    ctx->r11 = ADD32(0, 0X24);
    // 0x800214B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800214B4: lw          $a3, 0x8($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X8);
    // 0x800214B8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800214BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800214C0: jal         0x80020EE4
    // 0x800214C4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_80020EE4(rdram, ctx);
        goto after_10;
    // 0x800214C4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_10:
    // 0x800214C8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800214CC: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800214D0: lw          $t6, 0x11F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11F4);
    // 0x800214D4: sw          $zero, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = 0;
    // 0x800214D8: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800214DC: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x800214E0: lw          $t8, 0x8($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X8);
    // 0x800214E4: blez        $t8, L_8002154C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800214E8: nop
    
            goto L_8002154C;
    }
    // 0x800214E8: nop

L_800214EC:
    // 0x800214EC: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800214F0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800214F4: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x800214F8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800214FC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80021500: addu        $t7, $t0, $t1
    ctx->r15 = ADD32(ctx->r8, ctx->r9);
    // 0x80021504: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80021508: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x8002150C: lw          $t4, 0x11F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X11F4);
    // 0x80021510: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80021514: lw          $t2, 0x2C($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X2C);
    // 0x80021518: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8002151C: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x80021520: lw          $t5, 0x11F4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X11F4);
    // 0x80021524: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80021528: sw          $t6, 0x2C($t5)
    MEM_W(0X2C, ctx->r13) = ctx->r14;
    // 0x8002152C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80021530: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80021534: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80021538: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x8002153C: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x80021540: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80021544: bne         $at, $zero, L_800214EC
    if (ctx->r1 != 0) {
        // 0x80021548: nop
    
            goto L_800214EC;
    }
    // 0x80021548: nop

L_8002154C:
    // 0x8002154C: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80021550: lw          $t4, 0x11F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X11F4);
    // 0x80021554: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80021558: sw          $t7, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->r15;
    // 0x8002155C: b           L_80021564
    // 0x80021560: nop

        goto L_80021564;
    // 0x80021560: nop

L_80021564:
    // 0x80021564: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80021568: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8002156C: jr          $ra
    // 0x80021570: nop

    return;
    // 0x80021570: nop

;}
RECOMP_FUNC void func_80806AA8_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806AA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80806AAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806AB0: jal         0x80088360
    // 0x80806AB4: nop

    _gcstatusDll_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x80806AB4: nop

    after_0:
    // 0x80806AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80806ABC: addiu       $t6, $v0, 0x1F
    ctx->r14 = ADD32(ctx->r2, 0X1F);
    // 0x80806AC0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80806AC4: sllv        $v0, $t7, $t6
    ctx->r2 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x80806AC8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80806ACC: jr          $ra
    // 0x80806AD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80806AD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800FBC_chjollyroger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800FC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800FC8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800FCC: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    // 0x80800FD0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800FD4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800FD8: beq         $v0, $zero, L_80801004
    if (ctx->r2 == 0) {
        // 0x80800FDC: addiu       $a1, $zero, 0x10
        ctx->r5 = ADD32(0, 0X10);
            goto L_80801004;
    }
    // 0x80800FDC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80800FE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800FE4: beq         $v0, $at, L_80801014
    if (ctx->r2 == ctx->r1) {
        // 0x80800FE8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801014;
    }
    // 0x80800FE8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800FEC: beq         $v0, $at, L_80801014
    if (ctx->r2 == ctx->r1) {
        // 0x80800FF0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801014;
    }
    // 0x80800FF0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800FF4: beql        $v0, $at, L_80801020
    if (ctx->r2 == ctx->r1) {
        // 0x80800FF8: lw          $a0, 0x0($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X0);
            goto L_80801020;
    }
    goto skip_0;
    // 0x80800FF8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x80800FFC: b           L_80801030
    // 0x80801000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801030;
    // 0x80801000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801004:
    // 0x80801004: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80801008: jal         0x800856B0
    // 0x8080100C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080100C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80801010: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_80801014:
    // 0x80801014: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801018: sw          $t6, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r14;
    // 0x8080101C: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_80801020:
    // 0x80801020: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80801024: jal         0x80085740
    // 0x80801028: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80801028: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080102C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801030:
    // 0x80801030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801034: jr          $ra
    // 0x80801038: nop

    return;
    // 0x80801038: nop

;}
RECOMP_FUNC void fxstep_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800754: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2830, 0X830) << 16);
    // 0x80800758: lh          $t6, 0x830($t6)
    ctx->r14 = MEM_H(ctx->r14, (int16_t)RELOC_LO16(2830, 0X830));
    // 0x8080075C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800764: beq         $t6, $zero, L_80800800
    if (ctx->r14 == 0) {
        // 0x80800768: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_80800800;
    }
    // 0x80800768: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8080076C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2830, 0X830) << 16);
    // 0x80800770: addiu       $v1, $t7, 0x830
    ctx->r3 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2830, 0X830));
    // 0x80800774: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
L_80800778:
    // 0x80800778: bnel        $a0, $v0, L_808007F4
    if (ctx->r4 != ctx->r2) {
        // 0x8080077C: lh          $v0, 0x18($v1)
        ctx->r2 = MEM_H(ctx->r3, 0X18);
            goto L_808007F4;
    }
    goto skip_0;
    // 0x8080077C: lh          $v0, 0x18($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X18);
    skip_0:
    // 0x80800780: beq         $a1, $zero, L_808007A0
    if (ctx->r5 == 0) {
        // 0x80800784: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2830, 0X828) << 16);
            goto L_808007A0;
    }
    // 0x80800784: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2830, 0X828) << 16);
    // 0x80800788: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080078C: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800790: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80800794: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x80800798: b           L_808007B4
    // 0x8080079C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
        goto L_808007B4;
    // 0x8080079C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_808007A0:
    // 0x808007A0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808007A4: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x808007A8: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x808007AC: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
    // 0x808007B0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_808007B4:
    // 0x808007B4: lwc1        $f12, 0x828($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2830, 0X828));
    // 0x808007B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2830, 0X82C) << 16);
    // 0x808007BC: lwc1        $f14, 0x82C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2830, 0X82C));
    // 0x808007C0: jal         0x800DC178
    // 0x808007C4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x808007C4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x808007C8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808007CC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808007D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808007D4: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x808007D8: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x808007DC: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x808007E0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x808007E4: lh          $t0, 0x14($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X14);
    // 0x808007E8: b           L_80800804
    // 0x808007EC: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
        goto L_80800804;
    // 0x808007EC: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x808007F0: lh          $v0, 0x18($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X18);
L_808007F4:
    // 0x808007F4: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x808007F8: bne         $v0, $zero, L_80800778
    if (ctx->r2 != 0) {
        // 0x808007FC: nop
    
            goto L_80800778;
    }
    // 0x808007FC: nop

L_80800800:
    // 0x80800800: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800804:
    // 0x80800804: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800808: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080080C: jr          $ra
    // 0x80800810: nop

    return;
    // 0x80800810: nop

    // 0x80800814: nop

    // 0x80800818: nop

    // 0x8080081C: nop

;}
RECOMP_FUNC void fxstep_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800598: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080059C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005A0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808005A4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808005A8: jal         0x808003B4
    // 0x808005AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_808003B4_fxstep(rdram, ctx);
        goto after_0;
    // 0x808005AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x808005B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005B8: jr          $ra
    // 0x808005BC: nop

    return;
    // 0x808005BC: nop

;}
RECOMP_FUNC void func_8080060C_bsride(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080060C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800610: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800614: jal         0x8008CABC
    // 0x80800618: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800618: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080061C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800620: addiu       $a3, $zero, 0x2F
    ctx->r7 = ADD32(0, 0X2F);
    // 0x80800624: lw          $a0, 0x15C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X15C);
    // 0x80800628: beq         $a0, $zero, L_80800650
    if (ctx->r4 == 0) {
        // 0x8080062C: nop
    
            goto L_80800650;
    }
    // 0x8080062C: nop

    // 0x80800630: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800634: jal         0x80086B00
    // 0x80800638: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    _chhandcart_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800638: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_1:
    // 0x8080063C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800640: jal         0x8008B10C
    // 0x80800644: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8008B10C(rdram, ctx);
        goto after_2;
    // 0x80800644: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800648: b           L_80800650
    // 0x8080064C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
        goto L_80800650;
    // 0x8080064C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_80800650:
    // 0x80800650: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800654: jal         0x8009E5C8
    // 0x80800658: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x80800658: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_3:
    // 0x8080065C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800660: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800664: jr          $ra
    // 0x80800668: nop

    return;
    // 0x80800668: nop

;}
RECOMP_FUNC void chclinker_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800450: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2208, 0X14D4) << 16);
    // 0x80800454: jr          $ra
    // 0x80800458: addiu       $v0, $v0, 0x14D4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2208, 0X14D4));
    return;
    // 0x80800458: addiu       $v0, $v0, 0x14D4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2208, 0X14D4));
;}
RECOMP_FUNC void _bsbtrot_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082C90: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082C90);
    return;
    // 0x80082C94: addi        $t0, $zero, 0x68
    ctx->r8 = ADD32(0, 0X68);
;}
RECOMP_FUNC void func_80801110_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801110: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801118: jal         0x808004CC
    // 0x8080111C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bstrexsmall_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080111C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801120: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801124: jal         0x800845D8
    // 0x80801128: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _babounce_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80801128: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x8080112C: lui         $a2, 0x3F30
    ctx->r6 = S32(0X3F30 << 16);
    // 0x80801130: ori         $a2, $a2, 0xA3D7
    ctx->r6 = ctx->r6 | 0XA3D7;
    // 0x80801134: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801138: jal         0x800845E0
    // 0x8080113C: addiu       $a1, $zero, 0x147
    ctx->r5 = ADD32(0, 0X147);
    _babounce_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x8080113C: addiu       $a1, $zero, 0x147
    ctx->r5 = ADD32(0, 0X147);
    after_2:
    // 0x80801140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801148: jr          $ra
    // 0x8080114C: nop

    return;
    // 0x8080114C: nop

;}
RECOMP_FUNC void func_800F130C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F130C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F1310: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800F1314: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800F1318: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F131C: addiu       $t6, $t6, 0x14AC
    ctx->r14 = ADD32(ctx->r14, 0X14AC);
    // 0x800F1320: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800F1324: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800F1328: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800F132C: jal         0x800F1274
    // 0x800F1330: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F1274(rdram, ctx);
        goto after_0;
    // 0x800F1330: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800F1334: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F1338: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F133C: jr          $ra
    // 0x800F1340: nop

    return;
    // 0x800F1340: nop

;}
RECOMP_FUNC void func_80095A64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095A64: jr          $ra
    // 0x80095A68: sw          $zero, 0x50($a0)
    MEM_W(0X50, ctx->r4) = 0;
    return;
    // 0x80095A68: sw          $zero, 0x50($a0)
    MEM_W(0X50, ctx->r4) = 0;
;}
RECOMP_FUNC void bsvanswim_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008D0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808008D4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(431, 0X9B0) << 16);
    // 0x808008D8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808008DC: jr          $ra
    // 0x808008E0: lw          $v0, 0x9B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(431, 0X9B0));
    return;
    // 0x808008E0: lw          $v0, 0x9B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(431, 0X9B0));
;}
RECOMP_FUNC void sumumbofx_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080137C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80801380: jr          $ra
    // 0x80801384: swc1        $f12, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x80801384: swc1        $f12, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void _bsdie_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082F90: syscall     37
    recomp_syscall_handler(rdram, ctx, 0x80082F90);
    return;
    // 0x80082F94: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8080081C_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080081C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800820: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800824: jal         0x808001FC
    // 0x80800828: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808001FC_bsstatue(rdram, ctx);
        goto after_0;
    // 0x80800828: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080082C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800830: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800834: jal         0x8080054C
    // 0x80800838: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
    func_8080054C_bsstatue(rdram, ctx);
        goto after_1;
    // 0x80800838: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
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
RECOMP_FUNC void bssplitup_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808003C8: jal         0x80084950
    // 0x808003CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _baduo_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x808003CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x808003D0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808003D4: jal         0x800F8EE4
    // 0x808003D8: lw          $a0, 0x184($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X184);
    func_800F8EE4(rdram, ctx);
        goto after_1;
    // 0x808003D8: lw          $a0, 0x184($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X184);
    after_1:
    // 0x808003DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003E4: jr          $ra
    // 0x808003E8: nop

    return;
    // 0x808003E8: nop

;}
RECOMP_FUNC void func_80800548_chmrsboggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800548: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080054C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800550: jal         0x800897C8
    // 0x80800554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80800554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080055C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800560: jr          $ra
    // 0x80800564: nop

    return;
    // 0x80800564: nop

;}
RECOMP_FUNC void func_80800C10_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C18: jal         0x8080021C
    // 0x80800C1C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8080021C_bsbanshack(rdram, ctx);
        goto after_0;
    // 0x80800C1C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800C20: lui         $a2, 0x40AC
    ctx->r6 = S32(0X40AC << 16);
    // 0x80800C24: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800C28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800C2C: jal         0x8008CB3C
    // 0x80800C30: addiu       $a1, $zero, 0x293
    ctx->r5 = ADD32(0, 0X293);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80800C30: addiu       $a1, $zero, 0x293
    ctx->r5 = ADD32(0, 0X293);
    after_1:
    // 0x80800C34: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800C38: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800C3C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800C40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800C44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800C48: jal         0x8009FFD8
    // 0x80800C4C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800C4C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80800C50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800C54: jal         0x8009B9B0
    // 0x80800C58: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800C58: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800C5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800C64: jr          $ra
    // 0x80800C68: nop

    return;
    // 0x80800C68: nop

;}
RECOMP_FUNC void _cosectionstor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087830: syscall     634
    recomp_syscall_handler(rdram, ctx, 0x80087830);
    return;
    // 0x80087834: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bssnowball_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C04: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800C08: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(356, 0X10A4) << 16);
    // 0x80800C0C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800C10: jr          $ra
    // 0x80800C14: lw          $v0, 0x10A4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(356, 0X10A4));
    return;
    // 0x80800C14: lw          $v0, 0x10A4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(356, 0X10A4));
;}
RECOMP_FUNC void func_800A01F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A01F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A01FC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A0200: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800A0204: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A0208: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A020C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A0210: jal         0x80095738
    // 0x800A0214: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_isTrue(rdram, ctx);
        goto after_0;
    // 0x800A0214: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_0:
    // 0x800A0218: beq         $v0, $zero, L_800A0228
    if (ctx->r2 == 0) {
        // 0x800A021C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A0228;
    }
    // 0x800A021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A0220: b           L_800A02C8
    // 0x800A0224: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_800A02C8;
    // 0x800A0224: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_800A0228:
    // 0x800A0228: jal         0x80091A58
    // 0x800A022C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_1;
    // 0x800A022C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x800A0230: beql        $v0, $zero, L_800A0248
    if (ctx->r2 == 0) {
        // 0x800A0234: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A0248;
    }
    goto skip_0;
    // 0x800A0234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x800A0238: jal         0x8009FE84
    // 0x800A023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getTypeOfJump(rdram, ctx);
        goto after_2;
    // 0x800A023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800A0240: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800A0244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800A0248:
    // 0x800A0248: jal         0x80091A58
    // 0x800A024C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_3;
    // 0x800A024C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_3:
    // 0x800A0250: beq         $v0, $zero, L_800A0264
    if (ctx->r2 == 0) {
        // 0x800A0254: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A0264;
    }
    // 0x800A0254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A0258: jal         0x800A055C
    // 0x800A025C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800A055C(rdram, ctx);
        goto after_4;
    // 0x800A025C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x800A0260: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800A0264:
    // 0x800A0264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A0268: jal         0x800919F4
    // 0x800A026C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_5;
    // 0x800A026C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x800A0270: beq         $v0, $zero, L_800A028C
    if (ctx->r2 == 0) {
        // 0x800A0274: nop
    
            goto L_800A028C;
    }
    // 0x800A0274: nop

    // 0x800A0278: jal         0x80097A50
    // 0x800A027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_beak_barge(rdram, ctx);
        goto after_6;
    // 0x800A027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800A0280: beq         $v0, $zero, L_800A028C
    if (ctx->r2 == 0) {
        // 0x800A0284: nop
    
            goto L_800A028C;
    }
    // 0x800A0284: nop

    // 0x800A0288: addiu       $s1, $zero, 0x13
    ctx->r17 = ADD32(0, 0X13);
L_800A028C:
    // 0x800A028C: jal         0x80097AD0
    // 0x800A0290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_7;
    // 0x800A0290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800A0294: beq         $v0, $zero, L_800A02A8
    if (ctx->r2 == 0) {
        // 0x800A0298: nop
    
            goto L_800A02A8;
    }
    // 0x800A0298: nop

    // 0x800A029C: jal         0x800848A8
    // 0x800A02A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_24(rdram, ctx);
        goto after_8;
    // 0x800A02A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800A02A4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800A02A8:
    // 0x800A02A8: jal         0x8008E148
    // 0x800A02AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_9;
    // 0x800A02AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800A02B0: beql        $v0, $zero, L_800A02C8
    if (ctx->r2 == 0) {
        // 0x800A02B4: or          $v0, $s1, $zero
        ctx->r2 = ctx->r17 | 0;
            goto L_800A02C8;
    }
    goto skip_1;
    // 0x800A02B4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    skip_1:
    // 0x800A02B8: jal         0x800848B0
    // 0x800A02BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_10;
    // 0x800A02BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x800A02C0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800A02C4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_800A02C8:
    // 0x800A02C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A02CC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A02D0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A02D4: jr          $ra
    // 0x800A02D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A02D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
