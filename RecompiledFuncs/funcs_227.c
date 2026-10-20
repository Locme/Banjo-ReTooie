#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chlagoonbits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085FC8: syscall     268
    recomp_syscall_handler(rdram, ctx, 0x80085FC8);
    return;
    // 0x80085FCC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _sucoasterflydata_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A268: syscall     832
    recomp_syscall_handler(rdram, ctx, 0x8008A268);
    return;
    // 0x8008A26C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800014_chlightfader(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800014: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800018: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080001C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800020: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800024: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800028: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080002C: jal         0x80100094
    // 0x80800030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800034: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800038: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8080003C: jal         0x800D9078
    // 0x80800040: addiu       $a0, $s2, 0x58
    ctx->r4 = ADD32(ctx->r18, 0X58);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x80800040: addiu       $a0, $s2, 0x58
    ctx->r4 = ADD32(ctx->r18, 0X58);
    after_1:
    // 0x80800044: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80800048: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1260, 0X390) << 16);
    // 0x8080004C: lwc1        $f4, 0x390($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1260, 0X390));
    // 0x80800050: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x80800054: lwc1        $f12, 0x58($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X58);
    // 0x80800058: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080005C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800060: jal         0x800F10B4
    // 0x80800064: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80800064: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80800068: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8080006C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800070: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800074: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80800078: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080007C: beq         $t6, $zero, L_808000D0
    if (ctx->r14 == 0) {
        // 0x80800080: sub.s       $f2, $f6, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f0.fl;
            goto L_808000D0;
    }
    // 0x80800080: sub.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80800084: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800088: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8080008C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800090: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80800094: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800098: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8080009C: beql        $v1, $a0, L_808000C0
    if (ctx->r3 == ctx->r4) {
        // 0x808000A0: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_808000C0;
    }
    goto skip_0;
    // 0x808000A0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_0:
L_808000A4:
    // 0x808000A4: lwc1        $f16, 0x18($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X18);
    // 0x808000A8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808000AC: swc1        $f18, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f18.u32l;
    // 0x808000B0: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x808000B4: bne         $v1, $a0, L_808000A4
    if (ctx->r3 != ctx->r4) {
        // 0x808000B8: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_808000A4;
    }
    // 0x808000B8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808000BC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_808000C0:
    // 0x808000C0: swc1        $f18, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f18.u32l;
    // 0x808000C4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808000C8: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x808000CC: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
L_808000D0:
    // 0x808000D0: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    // 0x808000D4: beq         $t8, $zero, L_808000F8
    if (ctx->r24 == 0) {
        // 0x808000D8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808000F8;
    }
    // 0x808000D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808000DC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808000E0: addiu       $a0, $s1, 0x30
    ctx->r4 = ADD32(ctx->r17, 0X30);
    // 0x808000E4: addiu       $a1, $s1, 0x1C
    ctx->r5 = ADD32(ctx->r17, 0X1C);
    // 0x808000E8: sub.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x808000EC: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x808000F0: jal         0x800F2F60
    // 0x808000F4: nop

    func_800F2F60(rdram, ctx);
        goto after_3;
    // 0x808000F4: nop

    after_3:
L_808000F8:
    // 0x808000F8: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x808000FC: jal         0x800F2E60
    // 0x80800100: addiu       $a1, $s1, 0x30
    ctx->r5 = ADD32(ctx->r17, 0X30);
    func_800F2E60(rdram, ctx);
        goto after_4;
    // 0x80800100: addiu       $a1, $s1, 0x30
    ctx->r5 = ADD32(ctx->r17, 0X30);
    after_4:
    // 0x80800104: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x80800108: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x8080010C: beq         $t0, $zero, L_80800148
    if (ctx->r8 == 0) {
        // 0x80800110: nop
    
            goto L_80800148;
    }
    // 0x80800110: nop

    // 0x80800114: jal         0x8001210C
    // 0x80800118: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_5;
    // 0x80800118: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x8080011C: beq         $v0, $zero, L_80800134
    if (ctx->r2 == 0) {
        // 0x80800120: addiu       $a0, $sp, 0x48
        ctx->r4 = ADD32(ctx->r29, 0X48);
            goto L_80800134;
    }
    // 0x80800120: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80800124: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800128: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080012C: b           L_80800140
    // 0x80800130: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
        goto L_80800140;
    // 0x80800130: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
L_80800134:
    // 0x80800134: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1260, 0X394) << 16);
    // 0x80800138: lwc1        $f0, 0x394($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1260, 0X394));
    // 0x8080013C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
L_80800140:
    // 0x80800140: jal         0x800F2F60
    // 0x80800144: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_800F2F60(rdram, ctx);
        goto after_6;
    // 0x80800144: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_6:
L_80800148:
    // 0x80800148: jal         0x800A946C
    // 0x8080014C: nop

    func_800A946C(rdram, ctx);
        goto after_7;
    // 0x8080014C: nop

    after_7:
    // 0x80800150: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80800154: bne         $at, $zero, L_808001C8
    if (ctx->r1 != 0) {
        // 0x80800158: addiu       $a0, $s2, 0x4
        ctx->r4 = ADD32(ctx->r18, 0X4);
            goto L_808001C8;
    }
    // 0x80800158: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    // 0x8080015C: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80800160: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80800164:
    // 0x80800164: jal         0x800F6438
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_8;
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080016C: beql        $v0, $zero, L_808001B4
    if (ctx->r2 == 0) {
        // 0x80800170: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808001B4;
    }
    goto skip_1;
    // 0x80800170: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80800174: jal         0x800A9420
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A9420(rdram, ctx);
        goto after_9;
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080017C: beql        $v0, $zero, L_808001B4
    if (ctx->r2 == 0) {
        // 0x80800180: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808001B4;
    }
    goto skip_2;
    // 0x80800180: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x80800184: jal         0x800A93F8
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A93F8(rdram, ctx);
        goto after_10;
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080018C: beq         $v0, $zero, L_808001B0
    if (ctx->r2 == 0) {
        // 0x80800190: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808001B0;
    }
    // 0x80800190: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800194: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // 0x80800198: jal         0x800CACEC
    // 0x8080019C: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    func_800CACEC(rdram, ctx);
        goto after_11;
    // 0x8080019C: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    after_11:
    // 0x808001A0: beq         $v0, $zero, L_808001B0
    if (ctx->r2 == 0) {
        // 0x808001A4: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_808001B0;
    }
    // 0x808001A4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x808001A8: b           L_808001D4
    // 0x808001AC: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
        goto L_808001D4;
    // 0x808001AC: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
L_808001B0:
    // 0x808001B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808001B4:
    // 0x808001B4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x808001B8: bne         $s0, $at, L_80800164
    if (ctx->r16 != ctx->r1) {
        // 0x808001BC: nop
    
            goto L_80800164;
    }
    // 0x808001BC: nop

    // 0x808001C0: b           L_808001D8
    // 0x808001C4: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
        goto L_808001D8;
    // 0x808001C4: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
L_808001C8:
    // 0x808001C8: jal         0x800E3E8C
    // 0x808001CC: lw          $a1, 0x10($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X10);
    func_800E3E8C(rdram, ctx);
        goto after_12;
    // 0x808001CC: lw          $a1, 0x10($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X10);
    after_12:
    // 0x808001D0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
L_808001D4:
    // 0x808001D4: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
L_808001D8:
    // 0x808001D8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x808001DC: beql        $t2, $zero, L_80800210
    if (ctx->r10 == 0) {
        // 0x808001E0: lw          $t4, 0x64($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X64);
            goto L_80800210;
    }
    goto skip_3;
    // 0x808001E0: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    skip_3:
    // 0x808001E4: lwc1        $f4, 0x2C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x808001E8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x808001EC: jal         0x800C8E84
    // 0x808001F0: swc1        $f4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f4.u32l;
    func_800C8E84(rdram, ctx);
        goto after_13;
    // 0x808001F0: swc1        $f4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f4.u32l;
    after_13:
    // 0x808001F4: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x808001F8: addiu       $a1, $s1, 0x28
    ctx->r5 = ADD32(ctx->r17, 0X28);
    // 0x808001FC: beql        $t3, $zero, L_80800210
    if (ctx->r11 == 0) {
        // 0x80800200: lw          $t4, 0x64($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X64);
            goto L_80800210;
    }
    goto skip_4;
    // 0x80800200: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    skip_4:
    // 0x80800204: jal         0x800C8D4C
    // 0x80800208: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_800C8D4C(rdram, ctx);
        goto after_14;
    // 0x80800208: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_14:
    // 0x8080020C: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
L_80800210:
    // 0x80800210: beql        $t4, $zero, L_8080022C
    if (ctx->r12 == 0) {
        // 0x80800214: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8080022C;
    }
    goto skip_5;
    // 0x80800214: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_5:
    // 0x80800218: jal         0x800C8B84
    // 0x8080021C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_800C8B84(rdram, ctx);
        goto after_15;
    // 0x8080021C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_15:
    // 0x80800220: jal         0x800FFA88
    // 0x80800224: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_16;
    // 0x80800224: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_16:
    // 0x80800228: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080022C:
    // 0x8080022C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800230: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800234: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800238: jr          $ra
    // 0x8080023C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8080023C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80112E50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112E50: lw          $v0, 0x60($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X60);
    // 0x80112E54: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80112E58: lh          $t6, 0xC($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XC);
    // 0x80112E5C: beq         $t6, $zero, L_80112E7C
    if (ctx->r14 == 0) {
        // 0x80112E60: nop
    
            goto L_80112E7C;
    }
    // 0x80112E60: nop

    // 0x80112E64: lh          $t7, 0xE($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XE);
    // 0x80112E68: bne         $a2, $t7, L_80112E7C
    if (ctx->r6 != ctx->r15) {
        // 0x80112E6C: nop
    
            goto L_80112E7C;
    }
    // 0x80112E6C: nop

    // 0x80112E70: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80112E74: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80112E78: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
L_80112E7C:
    // 0x80112E7C: jr          $ra
    // 0x80112E80: nop

    return;
    // 0x80112E80: nop

;}
RECOMP_FUNC void func_80800230_gccubeDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800230: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800234: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800238: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8080023C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800240: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800244: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800248: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8080024C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800250: jal         0x800825F0
    // 0x80800254: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    _gsmaker_entrypoint_21(rdram, ctx);
        goto after_0;
    // 0x80800254: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x80800258: beq         $v0, $zero, L_808002E4
    if (ctx->r2 == 0) {
        // 0x8080025C: lw          $t6, 0x3C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X3C);
            goto L_808002E4;
    }
    // 0x8080025C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80800260: addiu       $s0, $zero, 0x14
    ctx->r16 = ADD32(0, 0X14);
    // 0x80800264: multu       $t6, $s0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800268: mflo        $a0
    ctx->r4 = lo;
    // 0x8080026C: jal         0x8001ACCC
    // 0x80800270: nop

    heap_alloc(rdram, ctx);
        goto after_1;
    // 0x80800270: nop

    after_1:
    // 0x80800274: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80800278: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8080027C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800280: multu       $t7, $s0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800284: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800288: mflo        $a2
    ctx->r6 = lo;
    // 0x8080028C: jal         0x80082588
    // 0x80800290: nop

    _gsmaker_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80800290: nop

    after_2:
    // 0x80800294: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80800298: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8080029C: blez        $t8, L_808002DC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x808002A0: nop
    
            goto L_808002DC;
    }
    // 0x808002A0: nop

    // 0x808002A4: bne         $s2, $zero, L_808002DC
    if (ctx->r18 != 0) {
        // 0x808002A8: lw          $t0, 0x34($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X34);
            goto L_808002DC;
    }
    // 0x808002A8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x808002AC: sll         $t9, $zero, 4
    ctx->r25 = S32(0 << 4);
    // 0x808002B0: addu        $s0, $t9, $t0
    ctx->r16 = ADD32(ctx->r25, ctx->r8);
L_808002B4:
    // 0x808002B4: jal         0x80088B98
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gspropsDll_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808002BC: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x808002C0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808002C4: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x808002C8: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x808002CC: beq         $at, $zero, L_808002DC
    if (ctx->r1 == 0) {
        // 0x808002D0: nop
    
            goto L_808002DC;
    }
    // 0x808002D0: nop

    // 0x808002D4: beq         $s2, $zero, L_808002B4
    if (ctx->r18 == 0) {
        // 0x808002D8: nop
    
            goto L_808002B4;
    }
    // 0x808002D8: nop

L_808002DC:
    // 0x808002DC: jal         0x8001B084
    // 0x808002E0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    heap_free(rdram, ctx);
        goto after_4;
    // 0x808002E0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_4:
L_808002E4:
    // 0x808002E4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808002E8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808002EC: jal         0x800825F0
    // 0x808002F0: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    _gsmaker_entrypoint_21(rdram, ctx);
        goto after_5;
    // 0x808002F0: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_5:
    // 0x808002F4: beq         $v0, $zero, L_80800388
    if (ctx->r2 == 0) {
        // 0x808002F8: lw          $t2, 0x3C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X3C);
            goto L_80800388;
    }
    // 0x808002F8: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x808002FC: addiu       $s0, $zero, 0xC
    ctx->r16 = ADD32(0, 0XC);
    // 0x80800300: multu       $t2, $s0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800304: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800308: mflo        $a0
    ctx->r4 = lo;
    // 0x8080030C: jal         0x8001ACCC
    // 0x80800310: nop

    heap_alloc(rdram, ctx);
        goto after_6;
    // 0x80800310: nop

    after_6:
    // 0x80800314: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80800318: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8080031C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800320: multu       $t3, $s0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800324: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800328: mflo        $a2
    ctx->r6 = lo;
    // 0x8080032C: jal         0x80082588
    // 0x80800330: nop

    _gsmaker_entrypoint_8(rdram, ctx);
        goto after_7;
    // 0x80800330: nop

    after_7:
    // 0x80800334: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80800338: blez        $t4, L_80800380
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8080033C: nop
    
            goto L_80800380;
    }
    // 0x8080033C: nop

    // 0x80800340: bne         $s2, $zero, L_80800380
    if (ctx->r18 != 0) {
        // 0x80800344: sll         $t5, $s1, 2
        ctx->r13 = S32(ctx->r17 << 2);
            goto L_80800380;
    }
    // 0x80800344: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x80800348: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8080034C: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x80800350: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80800354: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
L_80800358:
    // 0x80800358: jal         0x80088BA0
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gspropsDll_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800360: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80800364: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800368: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8080036C: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80800370: beq         $at, $zero, L_80800380
    if (ctx->r1 == 0) {
        // 0x80800374: nop
    
            goto L_80800380;
    }
    // 0x80800374: nop

    // 0x80800378: beq         $s2, $zero, L_80800358
    if (ctx->r18 == 0) {
        // 0x8080037C: nop
    
            goto L_80800358;
    }
    // 0x8080037C: nop

L_80800380:
    // 0x80800380: jal         0x8001B084
    // 0x80800384: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    heap_free(rdram, ctx);
        goto after_9;
    // 0x80800384: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_9:
L_80800388:
    // 0x80800388: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080038C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800390: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800394: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800398: jr          $ra
    // 0x8080039C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8080039C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80807504_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807504: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80807508: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080750C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80807510: jal         0x800A3404
    // 0x80807514: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800A3404(rdram, ctx);
        goto after_0;
    // 0x80807514: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80807518: beq         $v0, $zero, L_80807540
    if (ctx->r2 == 0) {
        // 0x8080751C: nop
    
            goto L_80807540;
    }
    // 0x8080751C: nop

    // 0x80807520: jal         0x800DB9B0
    // 0x80807524: nop

    func_800DB9B0(rdram, ctx);
        goto after_1;
    // 0x80807524: nop

    after_1:
    // 0x80807528: beq         $v0, $zero, L_80807538
    if (ctx->r2 == 0) {
        // 0x8080752C: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_80807538;
    }
    // 0x8080752C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80807530: b           L_80807564
    // 0x80807534: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
        goto L_80807564;
    // 0x80807534: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_80807538:
    // 0x80807538: b           L_80807564
    // 0x8080753C: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
        goto L_80807564;
    // 0x8080753C: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
L_80807540:
    // 0x80807540: jal         0x8009E710
    // 0x80807544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_2;
    // 0x80807544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80807548: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x8080754C: bne         $v0, $at, L_80807560
    if (ctx->r2 != ctx->r1) {
        // 0x80807550: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80807560;
    }
    // 0x80807550: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80807554: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80807558: b           L_80807564
    // 0x8080755C: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
        goto L_80807564;
    // 0x8080755C: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_80807560:
    // 0x80807560: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
L_80807564:
    // 0x80807564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807568: jal         0x808061AC
    // 0x8080756C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808061AC_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x8080756C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80807570: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x80807574: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80807578: beq         $v0, $zero, L_808075E0
    if (ctx->r2 == 0) {
        // 0x8080757C: nop
    
            goto L_808075E0;
    }
    // 0x8080757C: nop

    // 0x80807580: beq         $v0, $at, L_80807608
    if (ctx->r2 == ctx->r1) {
        // 0x80807584: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80807608;
    }
    // 0x80807584: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80807588: beq         $v0, $at, L_808075A0
    if (ctx->r2 == ctx->r1) {
        // 0x8080758C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808075A0;
    }
    // 0x8080758C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80807590: beql        $v0, $at, L_8080761C
    if (ctx->r2 == ctx->r1) {
        // 0x80807594: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080761C;
    }
    goto skip_0;
    // 0x80807594: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80807598: b           L_8080761C
    // 0x8080759C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080761C;
    // 0x8080759C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808075A0:
    // 0x808075A0: jal         0x800839C8
    // 0x808075A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_4;
    // 0x808075A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808075A8: jal         0x80807BB8
    // 0x808075AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807BB8_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x808075AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808075B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808075B4: addiu       $a1, $zero, 0x272
    ctx->r5 = ADD32(0, 0X272);
    // 0x808075B8: jal         0x8008CBB0
    // 0x808075BC: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baanim_playForDuration_loop(rdram, ctx);
        goto after_6;
    // 0x808075BC: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_6:
    // 0x808075C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808075C4: jal         0x800936E8
    // 0x808075C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800936E8(rdram, ctx);
        goto after_7;
    // 0x808075C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808075CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808075D0: jal         0x8009337C
    // 0x808075D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009337C(rdram, ctx);
        goto after_8;
    // 0x808075D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808075D8: b           L_8080761C
    // 0x808075DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080761C;
    // 0x808075DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808075E0:
    // 0x808075E0: jal         0x800839C8
    // 0x808075E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_9;
    // 0x808075E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808075E8: jal         0x80807BB8
    // 0x808075EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807BB8_bsfirstp(rdram, ctx);
        goto after_10;
    // 0x808075EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808075F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808075F4: addiu       $a1, $zero, 0x272
    ctx->r5 = ADD32(0, 0X272);
    // 0x808075F8: jal         0x8008CBB0
    // 0x808075FC: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baanim_playForDuration_loop(rdram, ctx);
        goto after_11;
    // 0x808075FC: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_11:
    // 0x80807600: b           L_8080761C
    // 0x80807604: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080761C;
    // 0x80807604: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80807608:
    // 0x80807608: jal         0x800839C8
    // 0x8080760C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_12;
    // 0x8080760C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80807610: jal         0x80807BB8
    // 0x80807614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807BB8_bsfirstp(rdram, ctx);
        goto after_13;
    // 0x80807614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80807618: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080761C:
    // 0x8080761C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80807620: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80807624: jr          $ra
    // 0x80807628: nop

    return;
    // 0x80807628: nop

;}
RECOMP_FUNC void _glcrc_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088710: syscall     700
    recomp_syscall_handler(rdram, ctx, 0x80088710);
    return;
    // 0x80088714: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80093ECC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093ECC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80093ED0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80093ED4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80093ED8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80093EDC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80093EE0: jal         0x8009216C
    // 0x80093EE4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8009216C(rdram, ctx);
        goto after_0;
    // 0x80093EE4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80093EE8: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x80093EEC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80093EF0: jal         0x800EE7F8
    // 0x80093EF4: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80093EF4: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    after_1:
    // 0x80093EF8: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x80093EFC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80093F00: jal         0x800EF04C
    // 0x80093F04: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x80093F04: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    after_2:
    // 0x80093F08: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x80093F0C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80093F10: jal         0x800EF04C
    // 0x80093F14: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x80093F14: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    after_3:
    // 0x80093F18: lw          $t6, 0x50($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X50);
    // 0x80093F1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80093F20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80093F24: lwc1        $f0, 0x1C($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80093F28: jr          $ra
    // 0x80093F2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80093F2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _ncbasuck_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089710: syscall     790
    recomp_syscall_handler(rdram, ctx, 0x80089710);
    return;
    // 0x80089714: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chfoodwarn_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087198: syscall     529
    recomp_syscall_handler(rdram, ctx, 0x80087198);
    return;
    // 0x8008719C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800BCC_choildrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BCC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800BD0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800BD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800BD8: beq         $a1, $at, L_80800CCC
    if (ctx->r5 == ctx->r1) {
        // 0x80800BDC: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_80800CCC;
    }
    // 0x80800BDC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800BE0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800BE4: beq         $a1, $at, L_80800C14
    if (ctx->r5 == ctx->r1) {
        // 0x80800BE8: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_80800C14;
    }
    // 0x80800BE8: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80800BEC: beq         $a1, $at, L_80800C94
    if (ctx->r5 == ctx->r1) {
        // 0x80800BF0: addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
            goto L_80800C94;
    }
    // 0x80800BF0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80800BF4: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80800BF8: beq         $a1, $at, L_80800CB0
    if (ctx->r5 == ctx->r1) {
        // 0x80800BFC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800CB0;
    }
    // 0x80800BFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800C00: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x80800C04: beq         $a1, $at, L_80800C58
    if (ctx->r5 == ctx->r1) {
        // 0x80800C08: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800C58;
    }
    // 0x80800C08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800C0C: b           L_80800CE0
    // 0x80800C10: nop

        goto L_80800CE0;
    // 0x80800C10: nop

L_80800C14:
    // 0x80800C14: addiu       $at, $zero, 0x54
    ctx->r1 = ADD32(0, 0X54);
    // 0x80800C18: bne         $a2, $at, L_80800C50
    if (ctx->r6 != ctx->r1) {
        // 0x80800C1C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800C50;
    }
    // 0x80800C1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800C20: jal         0x808009F8
    // 0x80800C24: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808009F8_choildrill(rdram, ctx);
        goto after_0;
    // 0x80800C24: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x80800C28: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800C2C: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    // 0x80800C30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800C34: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80800C38: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800C3C: jal         0x800D1000
    // 0x80800C40: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_800D1000(rdram, ctx);
        goto after_1;
    // 0x80800C40: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_1:
    // 0x80800C44: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    // 0x80800C48: jal         0x800887D8
    // 0x80800C4C: addiu       $a1, $zero, 0x85
    ctx->r5 = ADD32(0, 0X85);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80800C4C: addiu       $a1, $zero, 0x85
    ctx->r5 = ADD32(0, 0X85);
    after_2:
L_80800C50:
    // 0x80800C50: b           L_80800CE0
    // 0x80800C54: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800CE0;
    // 0x80800C54: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800C58:
    // 0x80800C58: addiu       $at, $zero, 0x85
    ctx->r1 = ADD32(0, 0X85);
    // 0x80800C5C: bne         $a2, $at, L_80800C8C
    if (ctx->r6 != ctx->r1) {
        // 0x80800C60: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800C8C;
    }
    // 0x80800C60: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800C64: jal         0x808009F8
    // 0x80800C68: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808009F8_choildrill(rdram, ctx);
        goto after_3;
    // 0x80800C68: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x80800C6C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800C70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800C74: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80800C78: addiu       $a3, $zero, 0x900
    ctx->r7 = ADD32(0, 0X900);
    // 0x80800C7C: jal         0x80085708
    // 0x80800C80: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x80800C80: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_4:
    // 0x80800C84: b           L_80800CE0
    // 0x80800C88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CE0;
    // 0x80800C88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C8C:
    // 0x80800C8C: b           L_80800CE0
    // 0x80800C90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800CE0;
    // 0x80800C90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C94:
    // 0x80800C94: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    // 0x80800C98: jal         0x800867B8
    // 0x80800C9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chjigsawcollect_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800C9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80800CA0: jal         0x800FFAB0
    // 0x80800CA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x80800CA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x80800CA8: b           L_80800CE0
    // 0x80800CAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CE0;
    // 0x80800CAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CB0:
    // 0x80800CB0: jal         0x80108B04
    // 0x80800CB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_7;
    // 0x80800CB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800CB8: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    // 0x80800CBC: jal         0x800D0BD4
    // 0x80800CC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0BD4(rdram, ctx);
        goto after_8;
    // 0x80800CC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800CC4: b           L_80800CE0
    // 0x80800CC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CE0;
    // 0x80800CC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CCC:
    // 0x80800CCC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800CD0: jal         0x808009F8
    // 0x80800CD4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808009F8_choildrill(rdram, ctx);
        goto after_9;
    // 0x80800CD4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x80800CD8: b           L_80800CE0
    // 0x80800CDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CE0;
    // 0x80800CDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CE0:
    // 0x80800CE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800CE8: jr          $ra
    // 0x80800CEC: nop

    return;
    // 0x80800CEC: nop

;}
RECOMP_FUNC void cadbfunc_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008EC: jal         0x80800888
    // 0x808008F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800888_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x808008F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808008F4: bne         $v0, $zero, L_80800904
    if (ctx->r2 != 0) {
        // 0x808008F8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800904;
    }
    // 0x808008F8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808008FC: b           L_80800914
    // 0x80800900: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800914;
    // 0x80800900: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800904:
    // 0x80800904: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800908: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080090C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800910: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
L_80800914:
    // 0x80800914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800918: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080091C: jr          $ra
    // 0x80800920: nop

    return;
    // 0x80800920: nop

;}
RECOMP_FUNC void func_80801F54_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F54: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80801F58: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80801F5C: addiu       $s4, $sp, 0x80
    ctx->r20 = ADD32(ctx->r29, 0X80);
    // 0x80801F60: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80801F64: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80801F68: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80801F6C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80801F70: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80801F74: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80801F78: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80801F7C: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80801F80: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80801F84: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80801F88: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80801F8C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80801F90: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80801F94: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x80801F98: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80801F9C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80801FA0: jal         0x8008A0E0
    // 0x80801FA4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80801FA4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_0:
    // 0x80801FA8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80801FAC: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80801FB0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80801FB4: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80801FB8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80801FBC: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80801FC0: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80801FC4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80801FC8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80801FCC: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x80801FD0: addiu       $s5, $sp, 0x98
    ctx->r21 = ADD32(ctx->r29, 0X98);
    // 0x80801FD4: addiu       $s3, $sp, 0x8C
    ctx->r19 = ADD32(ctx->r29, 0X8C);
    // 0x80801FD8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80801FDC:
    // 0x80801FDC: jal         0x800EE7F8
    // 0x80801FE0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80801FE0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x80801FE4: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x80801FE8: jal         0x800DC178
    // 0x80801FEC: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80801FEC: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    after_2:
    // 0x80801FF0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80801FF4: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x80801FF8: jal         0x800DC178
    // 0x80801FFC: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80801FFC: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    after_3:
    // 0x80802000: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80802004: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    // 0x80802008: jal         0x800DC178
    // 0x8080200C: mov.s       $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    ctx->f14.fl = ctx->f30.fl;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x8080200C: mov.s       $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    ctx->f14.fl = ctx->f30.fl;
    after_4:
    // 0x80802010: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x80802014: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80802018: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080201C: lwc1        $f4, 0x44($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X44);
    // 0x80802020: lwc1        $f8, 0x48($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X48);
    // 0x80802024: add.s       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f20.fl + ctx->f4.fl;
    // 0x80802028: add.s       $f10, $f22, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f8.fl;
    // 0x8080202C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80802030: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80802034: jal         0x800EF214
    // 0x80802038: nop

    func_800EF214(rdram, ctx);
        goto after_5;
    // 0x80802038: nop

    after_5:
    // 0x8080203C: addiu       $a0, $zero, 0x460
    ctx->r4 = ADD32(0, 0X460);
    // 0x80802040: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80802044: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802048: jal         0x80108528
    // 0x8080204C: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    func_80108528(rdram, ctx);
        goto after_6;
    // 0x8080204C: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_6:
    // 0x80802050: beq         $v0, $zero, L_808020BC
    if (ctx->r2 == 0) {
        // 0x80802054: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808020BC;
    }
    // 0x80802054: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80802058: addiu       $s1, $v0, 0x28
    ctx->r17 = ADD32(ctx->r2, 0X28);
    // 0x8080205C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802060: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80802064: jal         0x800EFB24
    // 0x80802068: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800EFB24(rdram, ctx);
        goto after_7;
    // 0x80802068: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_7:
    // 0x8080206C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80802070: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80802074: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x80802078: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080207C: jal         0x800DC178
    // 0x80802080: nop

    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x80802080: nop

    after_8:
    // 0x80802084: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80802088: jal         0x800EF368
    // 0x8080208C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EF368(rdram, ctx);
        goto after_9;
    // 0x8080208C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x80802090: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x80802094: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1332, 0X2D64) << 16);
    // 0x80802098: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8080209C: sw          $t9, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r25;
    // 0x808020A0: lwc1        $f12, 0x2D64($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2D64));
    // 0x808020A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1332, 0X2D68) << 16);
    // 0x808020A8: jal         0x800DC178
    // 0x808020AC: lwc1        $f14, 0x2D68($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2D68));
    func_800DC178(rdram, ctx);
        goto after_10;
    // 0x808020AC: lwc1        $f14, 0x2D68($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2D68));
    after_10:
    // 0x808020B0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808020B4: jal         0x80102FDC
    // 0x808020B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102FDC(rdram, ctx);
        goto after_11;
    // 0x808020B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
L_808020BC:
    // 0x808020BC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808020C0: bnel        $s2, $s6, L_80801FDC
    if (ctx->r18 != ctx->r22) {
        // 0x808020C4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80801FDC;
    }
    goto skip_0;
    // 0x808020C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
    // 0x808020C8: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x808020CC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808020D0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808020D4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808020D8: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808020DC: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x808020E0: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x808020E4: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x808020E8: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x808020EC: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x808020F0: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x808020F4: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x808020F8: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x808020FC: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80802100: jr          $ra
    // 0x80802104: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80802104: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_80800090_chmole_lagoon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800098: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1780, 0XC0) << 16);
    // 0x8080009C: jal         0x800899F0
    // 0x808000A0: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1780, 0XC0));
    _sumole_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808000A0: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1780, 0XC0));
    after_0:
    // 0x808000A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void func_8080000C_chanemone(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800010: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80800014: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800018: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080001C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80800020: lhu         $t7, 0x72($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X72);
    // 0x80800024: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800028: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x8080002C: xori        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 ^ 0X3;
    // 0x80800030: sltu        $t9, $zero, $t9
    ctx->r25 = 0 < ctx->r25 ? 1 : 0;
    // 0x80800034: jal         0x808003A8
    // 0x80800038: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    func_808003A8_chanemone(rdram, ctx);
        goto after_0;
    // 0x80800038: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    after_0:
    // 0x8080003C: jal         0x8010D23C
    // 0x80800040: nop

    func_8010D23C(rdram, ctx);
        goto after_1;
    // 0x80800040: nop

    after_1:
    // 0x80800044: beql        $v0, $zero, L_80800090
    if (ctx->r2 == 0) {
        // 0x80800048: lw          $t5, 0x30($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X30);
            goto L_80800090;
    }
    goto skip_0;
    // 0x80800048: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x8080004C: lhu         $t0, 0x72($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X72);
    // 0x80800050: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800054: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x80800058: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x8080005C: beq         $t1, $at, L_80800068
    if (ctx->r9 == ctx->r1) {
        // 0x80800060: nop
    
            goto L_80800068;
    }
    // 0x80800060: nop

    // 0x80800064: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
L_80800068:
    // 0x80800068: jal         0x800F54E4
    // 0x8080006C: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x8080006C: nop

    after_2:
    // 0x80800070: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800074: jal         0x800F64A4
    // 0x80800078: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    func_800F64A4(rdram, ctx);
        goto after_3;
    // 0x80800078: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_3:
    // 0x8080007C: beq         $v0, $zero, L_8080008C
    if (ctx->r2 == 0) {
        // 0x80800080: lw          $t3, 0x34($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X34);
            goto L_8080008C;
    }
    // 0x80800080: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80800084: ori         $t4, $t3, 0x2
    ctx->r12 = ctx->r11 | 0X2;
    // 0x80800088: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_8080008C:
    // 0x8080008C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
L_80800090:
    // 0x80800090: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800094: beql        $t5, $zero, L_8080011C
    if (ctx->r13 == 0) {
        // 0x80800098: lwc1        $f0, 0x38($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
            goto L_8080011C;
    }
    goto skip_1;
    // 0x80800098: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    skip_1:
    // 0x8080009C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1032, 0X8A0) << 16);
    // 0x808000A0: lwc1        $f4, 0x8A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1032, 0X8A0));
    // 0x808000A4: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808000A8: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x808000AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000B0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808000B4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x808000B8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808000BC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808000C0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808000C4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808000C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000CC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808000D0: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x808000D4: jal         0x80089F20
    // 0x808000D8: nop

    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x808000D8: nop

    after_4:
    // 0x808000DC: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x808000E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808000E4: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808000E8: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x808000EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000F0: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808000F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808000F8: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x808000FC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800100: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800104: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800108: jal         0x80089F18
    // 0x8080010C: nop

    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x8080010C: nop

    after_5:
    // 0x80800110: b           L_80800150
    // 0x80800114: lhu         $a2, 0x72($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X72);
        goto L_80800150;
    // 0x80800114: lhu         $a2, 0x72($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X72);
    // 0x80800118: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
L_8080011C:
    // 0x8080011C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800120: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x80800124: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800128: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8080012C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800130: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800134: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800138: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8080013C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800140: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800144: jal         0x80089F18
    // 0x80800148: nop

    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x80800148: nop

    after_6:
    // 0x8080014C: lhu         $a2, 0x72($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X72);
L_80800150:
    // 0x80800150: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1032, 0X920) << 16);
    // 0x80800154: addiu       $t9, $t9, 0x920
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1032, 0X920));
    // 0x80800158: srl         $t7, $a2, 10
    ctx->r15 = S32(U32(ctx->r6) >> 10);
    // 0x8080015C: xori        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 ^ 0X1;
    // 0x80800160: sltiu       $a2, $t8, 0x1
    ctx->r6 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80800164: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080016C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800170: jal         0x80089D58
    // 0x80800174: addiu       $a3, $zero, 0x7D0
    ctx->r7 = ADD32(0, 0X7D0);
    _subaddieaudioloop_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x80800174: addiu       $a3, $zero, 0x7D0
    ctx->r7 = ADD32(0, 0X7D0);
    after_7:
    // 0x80800178: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x8080017C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: srl         $t0, $v0, 10
    ctx->r8 = S32(U32(ctx->r2) >> 10);
    // 0x80800188: beq         $t0, $at, L_808001AC
    if (ctx->r8 == ctx->r1) {
        // 0x8080018C: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_808001AC;
    }
    // 0x8080018C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800190: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800194: beq         $t0, $at, L_808001E8
    if (ctx->r8 == ctx->r1) {
        // 0x80800198: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808001E8;
    }
    // 0x80800198: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080019C: beq         $t0, $at, L_80800208
    if (ctx->r8 == ctx->r1) {
        // 0x808001A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800208;
    }
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: b           L_80800250
    // 0x808001A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800250;
    // 0x808001A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001AC:
    // 0x808001AC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1032, 0X934) << 16);
    // 0x808001B0: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x808001B4: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808001B8: jal         0x80089D20
    // 0x808001BC: addiu       $a2, $a2, 0x934
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1032, 0X934));
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x808001BC: addiu       $a2, $a2, 0x934
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1032, 0X934));
    after_8:
    // 0x808001C0: jal         0x80101DDC
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_9;
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808001C8: beq         $v0, $zero, L_8080024C
    if (ctx->r2 == 0) {
        // 0x808001CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080024C;
    }
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D0: jal         0x80102424
    // 0x808001D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_10;
    // 0x808001D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x808001D8: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x808001DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001E0: b           L_8080024C
    // 0x808001E4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_8080024C;
    // 0x808001E4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_808001E8:
    // 0x808001E8: jal         0x800D9078
    // 0x808001EC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_11;
    // 0x808001EC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_11:
    // 0x808001F0: beq         $v0, $zero, L_8080024C
    if (ctx->r2 == 0) {
        // 0x808001F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080024C;
    }
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F8: jal         0x80102424
    // 0x808001FC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_12;
    // 0x808001FC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_12:
    // 0x80800200: b           L_80800250
    // 0x80800204: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800250;
    // 0x80800204: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800208:
    // 0x80800208: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1032, 0X944) << 16);
    // 0x8080020C: lui         $a3, 0x3F19
    ctx->r7 = S32(0X3F19 << 16);
    // 0x80800210: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800214: addiu       $a2, $a2, 0x944
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1032, 0X944));
    // 0x80800218: jal         0x80089D20
    // 0x8080021C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_13;
    // 0x8080021C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_13:
    // 0x80800220: jal         0x80101DDC
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_14;
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800228: beq         $v0, $zero, L_8080024C
    if (ctx->r2 == 0) {
        // 0x8080022C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080024C;
    }
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800230: jal         0x80102424
    // 0x80800234: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_15;
    // 0x80800234: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: jal         0x8008A4B0
    // 0x80800240: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_16;
    // 0x80800240: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80800244: jal         0x8010A590
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_17;
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
L_8080024C:
    // 0x8080024C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800250:
    // 0x80800250: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800254: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800258: jr          $ra
    // 0x8080025C: nop

    return;
    // 0x8080025C: nop

;}
RECOMP_FUNC void func_80800090_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800098: addiu       $a0, $zero, 0x9DC
    ctx->r4 = ADD32(0, 0X9DC);
    // 0x8080009C: jal         0x800DA564
    // 0x808000A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x808000A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808000A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void func_80800BF4_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800BF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BFC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800C00: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80800C04: jal         0x80100094
    // 0x80800C08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800C0C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800C10: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800C14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800C18: beq         $a2, $zero, L_80800C38
    if (ctx->r6 == 0) {
        // 0x80800C1C: sb          $a2, 0x1($v0)
        MEM_B(0X1, ctx->r2) = ctx->r6;
            goto L_80800C38;
    }
    // 0x80800C1C: sb          $a2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r6;
    // 0x80800C20: beq         $a2, $at, L_80800C40
    if (ctx->r6 == ctx->r1) {
        // 0x80800C24: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800C40;
    }
    // 0x80800C24: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800C28: beq         $a2, $at, L_80800C7C
    if (ctx->r6 == ctx->r1) {
        // 0x80800C2C: addiu       $t9, $zero, 0x3
        ctx->r25 = ADD32(0, 0X3);
            goto L_80800C7C;
    }
    // 0x80800C2C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80800C30: b           L_80800C84
    // 0x80800C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C84;
    // 0x80800C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C38:
    // 0x80800C38: b           L_80800C80
    // 0x80800C3C: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
        goto L_80800C80;
    // 0x80800C3C: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
L_80800C40:
    // 0x80800C40: jal         0x800DC090
    // 0x80800C44: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800DC090(rdram, ctx);
        goto after_1;
    // 0x80800C44: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80800C48: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80800C4C: beq         $t6, $zero, L_80800C60
    if (ctx->r14 == 0) {
        // 0x80800C50: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800C60;
    }
    // 0x80800C50: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C54: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800C58: b           L_80800C68
    // 0x80800C5C: sb          $t7, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r15;
        goto L_80800C68;
    // 0x80800C5C: sb          $t7, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r15;
L_80800C60:
    // 0x80800C60: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80800C64: sb          $t8, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r24;
L_80800C68:
    // 0x80800C68: jal         0x800DC0C0
    // 0x80800C6C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800DC0C0(rdram, ctx);
        goto after_2;
    // 0x80800C6C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80800C70: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C74: b           L_80800C80
    // 0x80800C78: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
        goto L_80800C80;
    // 0x80800C78: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
L_80800C7C:
    // 0x80800C7C: sb          $t9, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r25;
L_80800C80:
    // 0x80800C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C84:
    // 0x80800C84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800C88: jr          $ra
    // 0x80800C8C: nop

    return;
    // 0x80800C8C: nop

;}
RECOMP_FUNC void subaddietaxi_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800800: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800804: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800808: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080080C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800810: jal         0x8010410C
    // 0x80800814: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    func_8010410C(rdram, ctx);
        goto after_0;
    // 0x80800814: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800818: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8080081C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80800820: jal         0x800CB698
    // 0x80800824: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800CB698(rdram, ctx);
        goto after_1;
    // 0x80800824: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
    // 0x80800828: jal         0x800D9078
    // 0x8080082C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800D9078(rdram, ctx);
        goto after_2;
    // 0x8080082C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_2:
    // 0x80800830: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800834: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800838: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8080083C: nop

    // 0x80800840: bc1t        L_808009A8
    if (c1cs) {
        // 0x80800844: nop
    
            goto L_808009A8;
    }
    // 0x80800844: nop

    // 0x80800848: jal         0x800CB518
    // 0x8080084C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    func_800CB518(rdram, ctx);
        goto after_3;
    // 0x8080084C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    after_3:
    // 0x80800850: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80800854: beq         $t6, $zero, L_80800868
    if (ctx->r14 == 0) {
        // 0x80800858: sw          $v0, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r2;
            goto L_80800868;
    }
    // 0x80800858: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8080085C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800860: jal         0x800888C8
    // 0x80800864: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    _fxsparkle_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800864: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_4:
L_80800868:
    // 0x80800868: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    // 0x8080086C: ori         $a1, $a1, 0x4024
    ctx->r5 = ctx->r5 | 0X4024;
    // 0x80800870: jal         0x8010B990
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010B990(rdram, ctx);
        goto after_5;
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800878: andi        $t7, $v0, 0x28
    ctx->r15 = ctx->r2 & 0X28;
    // 0x8080087C: beq         $t7, $zero, L_808009A8
    if (ctx->r15 == 0) {
        // 0x80800880: sw          $v0, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r2;
            goto L_808009A8;
    }
    // 0x80800880: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80800884: andi        $t8, $v0, 0x20
    ctx->r24 = ctx->r2 & 0X20;
    // 0x80800888: beq         $t8, $zero, L_80800914
    if (ctx->r24 == 0) {
        // 0x8080088C: andi        $v1, $v0, 0x8
        ctx->r3 = ctx->r2 & 0X8;
            goto L_80800914;
    }
    // 0x8080088C: andi        $v1, $v0, 0x8
    ctx->r3 = ctx->r2 & 0X8;
    // 0x80800890: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80800894: jal         0x8010AA54
    // 0x80800898: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    func_8010AA54(rdram, ctx);
        goto after_6;
    // 0x80800898: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_6:
    // 0x8080089C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808008A0: jal         0x800F1884
    // 0x808008A4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800F1884(rdram, ctx);
        goto after_7;
    // 0x808008A4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_7:
    // 0x808008A8: beq         $v0, $zero, L_808008F0
    if (ctx->r2 == 0) {
        // 0x808008AC: lw          $v1, 0x4C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X4C);
            goto L_808008F0;
    }
    // 0x808008AC: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x808008B0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808008B4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808008B8: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808008BC: jal         0x800F2094
    // 0x808008C0: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    func_800F2094(rdram, ctx);
        goto after_8;
    // 0x808008C0: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_8:
    // 0x808008C4: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x808008C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808008CC: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x808008D0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808008D4: nop

    // 0x808008D8: bc1f        L_80800914
    if (!c1cs) {
        // 0x808008DC: nop
    
            goto L_80800914;
    }
    // 0x808008DC: nop

    // 0x808008E0: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x808008E4: andi        $t9, $v1, 0x8
    ctx->r25 = ctx->r3 & 0X8;
    // 0x808008E8: b           L_80800914
    // 0x808008EC: addiu       $v1, $t9, 0x1
    ctx->r3 = ADD32(ctx->r25, 0X1);
        goto L_80800914;
    // 0x808008EC: addiu       $v1, $t9, 0x1
    ctx->r3 = ADD32(ctx->r25, 0X1);
L_808008F0:
    // 0x808008F0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808008F4: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808008F8: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x808008FC: nop

    // 0x80800900: bc1f        L_80800914
    if (!c1cs) {
        // 0x80800904: nop
    
            goto L_80800914;
    }
    // 0x80800904: nop

    // 0x80800908: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x8080090C: andi        $t0, $v1, 0x8
    ctx->r8 = ctx->r3 & 0X8;
    // 0x80800910: addiu       $v1, $t0, 0x1
    ctx->r3 = ADD32(ctx->r8, 0X1);
L_80800914:
    // 0x80800914: beq         $v1, $zero, L_808009A8
    if (ctx->r3 == 0) {
        // 0x80800918: addiu       $a0, $s0, 0x28
        ctx->r4 = ADD32(ctx->r16, 0X28);
            goto L_808009A8;
    }
    // 0x80800918: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x8080091C: addiu       $t1, $s0, 0x4
    ctx->r9 = ADD32(ctx->r16, 0X4);
    // 0x80800920: jal         0x800EFD24
    // 0x80800924: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    func_800EFD24(rdram, ctx);
        goto after_9;
    // 0x80800924: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    after_9:
    // 0x80800928: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8080092C: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80800930: addiu       $t2, $sp, 0x34
    ctx->r10 = ADD32(ctx->r29, 0X34);
    // 0x80800934: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
    // 0x80800938: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8080093C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800940: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x80800944: jal         0x800C696C
    // 0x80800948: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    func_800C696C(rdram, ctx);
        goto after_10;
    // 0x80800948: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    after_10:
    // 0x8080094C: beq         $v0, $zero, L_8080096C
    if (ctx->r2 == 0) {
        // 0x80800950: lwc1        $f6, 0x34($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
            goto L_8080096C;
    }
    // 0x80800950: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800954: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800958: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080095C: nop

    // 0x80800960: bc1fl       L_80800970
    if (!c1cs) {
        // 0x80800964: lw          $t3, 0x54($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X54);
            goto L_80800970;
    }
    goto skip_0;
    // 0x80800964: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x80800968: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
L_8080096C:
    // 0x8080096C: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
L_80800970:
    // 0x80800970: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800974: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x80800978: andi        $t4, $t3, 0x4
    ctx->r12 = ctx->r11 & 0X4;
    // 0x8080097C: beq         $t4, $zero, L_80800990
    if (ctx->r12 == 0) {
        // 0x80800980: lui         $a2, 0x3F66
        ctx->r6 = S32(0X3F66 << 16);
            goto L_80800990;
    }
    // 0x80800980: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80800984: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800988: jal         0x800E1610
    // 0x8080098C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_800E1610(rdram, ctx);
        goto after_11;
    // 0x8080098C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_11:
L_80800990:
    // 0x80800990: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x80800994: andi        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 & 0X2;
    // 0x80800998: beq         $t6, $zero, L_808009A8
    if (ctx->r14 == 0) {
        // 0x8080099C: nop
    
            goto L_808009A8;
    }
    // 0x8080099C: nop

    // 0x808009A0: jal         0x80800C00
    // 0x808009A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C00_subaddietaxi(rdram, ctx);
        goto after_12;
    // 0x808009A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_808009A8:
    // 0x808009A8: jal         0x80089C90
    // 0x808009AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_13;
    // 0x808009AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808009B0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x808009B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808009B8: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x808009BC: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    // 0x808009C0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808009C4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808009C8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808009CC: jal         0x800F10B4
    // 0x808009D0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_14;
    // 0x808009D0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_14:
    // 0x808009D4: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808009D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009DC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808009E0: jal         0x80089C98
    // 0x808009E4: nop

    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_15;
    // 0x808009E4: nop

    after_15:
    // 0x808009E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3334, 0XD40) << 16);
    // 0x808009EC: lwc1        $f14, 0xD40($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3334, 0XD40));
    // 0x808009F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3334, 0XD44) << 16);
    // 0x808009F4: lwc1        $f16, 0xD44($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3334, 0XD44));
    // 0x808009F8: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    // 0x808009FC: lw          $a3, 0x1C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X1C);
    // 0x80800A00: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    // 0x80800A04: jal         0x800F10B4
    // 0x80800A08: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_16;
    // 0x80800A08: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_16:
    // 0x80800A0C: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80800A10: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80800A14: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80800A18: bne         $t8, $at, L_80800A44
    if (ctx->r24 != ctx->r1) {
        // 0x80800A1C: nop
    
            goto L_80800A44;
    }
    // 0x80800A1C: nop

    // 0x80800A20: jal         0x80089C90
    // 0x80800A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_17;
    // 0x80800A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800A28: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80800A2C: beq         $v0, $at, L_80800A44
    if (ctx->r2 == ctx->r1) {
        // 0x80800A30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A44;
    }
    // 0x80800A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A34: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3334, 0XD68) << 16);
    // 0x80800A38: addiu       $a2, $a2, 0xD68
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3334, 0XD68));
    // 0x80800A3C: jal         0x80089D18
    // 0x80800A40: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_18;
    // 0x80800A40: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_18:
L_80800A44:
    // 0x80800A44: jal         0x80089C90
    // 0x80800A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_19;
    // 0x80800A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800A4C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80800A50: beq         $v0, $at, L_80800A64
    if (ctx->r2 == ctx->r1) {
        // 0x80800A54: lw          $a1, 0x5C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X5C);
            goto L_80800A64;
    }
    // 0x80800A54: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80800A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A5C: jal         0x801078DC
    // 0x80800A60: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    func_801078DC(rdram, ctx);
        goto after_20;
    // 0x80800A60: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    after_20:
L_80800A64:
    // 0x80800A64: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800A68: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800A6C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3334, 0XD48) << 16);
    // 0x80800A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A74: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x80800A78: nop

    // 0x80800A7C: bc1t        L_80800AA0
    if (c1cs) {
        // 0x80800A80: nop
    
            goto L_80800AA0;
    }
    // 0x80800A80: nop

    // 0x80800A84: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800A88: lwc1        $f8, 0xD48($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3334, 0XD48));
    // 0x80800A8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800A90: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80800A94: nop

    // 0x80800A98: bc1f        L_80800AB0
    if (!c1cs) {
        // 0x80800A9C: nop
    
            goto L_80800AB0;
    }
    // 0x80800A9C: nop

L_80800AA0:
    // 0x80800AA0: jal         0x8008A4B0
    // 0x80800AA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_21;
    // 0x80800AA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x80800AA8: b           L_80800AB0
    // 0x80800AAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800AB0;
    // 0x80800AAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800AB0:
    // 0x80800AB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800AB4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800AB8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800ABC: jr          $ra
    // 0x80800AC0: nop

    return;
    // 0x80800AC0: nop

;}
RECOMP_FUNC void func_80800218_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800218: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080021C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800220: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800224: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800228: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080022C: jal         0x80097AD0
    // 0x80800230: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_0;
    // 0x80800230: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    after_0:
    // 0x80800234: beql        $v0, $zero, L_8080024C
    if (ctx->r2 == 0) {
        // 0x80800238: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080024C;
    }
    goto skip_0;
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080023C: jal         0x800848A8
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_24(rdram, ctx);
        goto after_1;
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800244: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080024C:
    // 0x8080024C: jal         0x80091A58
    // 0x80800250: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_2;
    // 0x80800250: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x80800254: beq         $v0, $zero, L_80800260
    if (ctx->r2 == 0) {
        // 0x80800258: nop
    
            goto L_80800260;
    }
    // 0x80800258: nop

    // 0x8080025C: addiu       $s1, $zero, 0x107
    ctx->r17 = ADD32(0, 0X107);
L_80800260:
    // 0x80800260: jal         0x808014B0
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bstnt_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800268: beql        $v0, $zero, L_80800278
    if (ctx->r2 == 0) {
        // 0x8080026C: lbu         $t6, 0x168($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X168);
            goto L_80800278;
    }
    goto skip_1;
    // 0x8080026C: lbu         $t6, 0x168($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X168);
    skip_1:
    // 0x80800270: addiu       $s1, $zero, 0x10E
    ctx->r17 = ADD32(0, 0X10E);
    // 0x80800274: lbu         $t6, 0x168($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X168);
L_80800278:
    // 0x80800278: beql        $t6, $zero, L_80800298
    if (ctx->r14 == 0) {
        // 0x8080027C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800298;
    }
    goto skip_2;
    // 0x8080027C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800280: jal         0x8008E078
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_4;
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800288: beql        $v0, $zero, L_80800298
    if (ctx->r2 == 0) {
        // 0x8080028C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800298;
    }
    goto skip_3;
    // 0x8080028C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80800290: addiu       $s1, $zero, 0x10D
    ctx->r17 = ADD32(0, 0X10D);
    // 0x80800294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800298:
    // 0x80800298: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8080029C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808002A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808002A4: jr          $ra
    // 0x808002A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808002A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_808000C4_chdiggerground(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000D0: jal         0x8008A498
    // 0x808000D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _subaddieDll_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808000D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000DC: jal         0x8008A0F8
    // 0x808000E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sucoaster_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808000E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808000E4: beq         $v0, $zero, L_80800154
    if (ctx->r2 == 0) {
        // 0x808000E8: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(856, 0X360) << 16);
            goto L_80800154;
    }
    // 0x808000E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(856, 0X360) << 16);
    // 0x808000EC: jal         0x800DC298
    // 0x808000F0: lwc1        $f12, 0x360($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(856, 0X360));
    func_800DC298(rdram, ctx);
        goto after_2;
    // 0x808000F0: lwc1        $f12, 0x360($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(856, 0X360));
    after_2:
    // 0x808000F4: beq         $v0, $zero, L_80800104
    if (ctx->r2 == 0) {
        // 0x808000F8: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80800104;
    }
    // 0x808000F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808000FC: b           L_80800104
    // 0x80800100: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
        goto L_80800104;
    // 0x80800100: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_80800104:
    // 0x80800104: jal         0x8008A148
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080010C: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    // 0x80800110: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800114: srl         $t7, $t6, 21
    ctx->r15 = S32(U32(ctx->r14) >> 21);
    // 0x80800118: bnel        $t7, $zero, L_80800144
    if (ctx->r15 != 0) {
        // 0x8080011C: lbu         $t4, 0x64($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0X64);
            goto L_80800144;
    }
    goto skip_0;
    // 0x8080011C: lbu         $t4, 0x64($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X64);
    skip_0:
    // 0x80800120: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800124: jal         0x800D9058
    // 0x80800128: nop

    func_800D9058(rdram, ctx);
        goto after_4;
    // 0x80800128: nop

    after_4:
    // 0x8080012C: lhu         $t0, 0x6E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800130: andi        $t9, $v0, 0x1FF
    ctx->r25 = ctx->r2 & 0X1FF;
    // 0x80800134: andi        $t1, $t0, 0xFE00
    ctx->r9 = ctx->r8 & 0XFE00;
    // 0x80800138: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x8080013C: sh          $t2, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r10;
    // 0x80800140: lbu         $t4, 0x64($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X64);
L_80800144:
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800148: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x8080014C: jal         0x8010A590
    // 0x80800150: sb          $t5, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r13;
    func_8010A590(rdram, ctx);
        goto after_5;
    // 0x80800150: sb          $t5, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r13;
    after_5:
L_80800154:
    // 0x80800154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800158: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080015C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800160: jr          $ra
    // 0x80800164: nop

    return;
    // 0x80800164: nop

;}
RECOMP_FUNC void func_800A76F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A76F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800A76F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A76FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A7700: jal         0x800FB968
    // 0x800A7704: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_800FB968(rdram, ctx);
        goto after_0;
    // 0x800A7704: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A7708: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A770C: addiu       $s0, $s0, 0x7630
    ctx->r16 = ADD32(ctx->r16, 0X7630);
    // 0x800A7710: jal         0x800885D0
    // 0x800A7714: lh          $a0, 0x10($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X10);
    _glintrosyncDll_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x800A7714: lh          $a0, 0x10($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X10);
    after_1:
    // 0x800A7718: jal         0x8001A2B0
    // 0x800A771C: nop

    func_8001A2B0(rdram, ctx);
        goto after_2;
    // 0x800A771C: nop

    after_2:
    // 0x800A7720: lbu         $t6, 0x16($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X16);
    // 0x800A7724: lbu         $t7, 0x15($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X15);
    // 0x800A7728: lbu         $t8, 0x14($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X14);
    // 0x800A772C: lh          $t9, 0x10($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X10);
    // 0x800A7730: lbu         $t0, 0x13($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X13);
    // 0x800A7734: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x800A7738: sb          $zero, 0x16($s0)
    MEM_B(0X16, ctx->r16) = 0;
    // 0x800A773C: sb          $zero, 0x15($s0)
    MEM_B(0X15, ctx->r16) = 0;
    // 0x800A7740: sb          $zero, 0x14($s0)
    MEM_B(0X14, ctx->r16) = 0;
    // 0x800A7744: sh          $zero, 0x10($s0)
    MEM_H(0X10, ctx->r16) = 0;
    // 0x800A7748: sb          $zero, 0x13($s0)
    MEM_B(0X13, ctx->r16) = 0;
    // 0x800A774C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800A7750: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A7754: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x800A7758: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x800A775C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800A7760: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800A7764: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800A7768: jal         0x800A759C
    // 0x800A776C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    func_800A759C(rdram, ctx);
        goto after_3;
    // 0x800A776C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    after_3:
    // 0x800A7770: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800A7774: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A7778: jal         0x800A5CF0
    // 0x800A777C: sb          $t2, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r10;
    func_800A5CF0(rdram, ctx);
        goto after_4;
    // 0x800A777C: sb          $t2, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r10;
    after_4:
    // 0x800A7780: addiu       $a0, $zero, 0x647
    ctx->r4 = ADD32(0, 0X647);
    // 0x800A7784: jal         0x800DA9E4
    // 0x800A7788: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA9E4(rdram, ctx);
        goto after_5;
    // 0x800A7788: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x800A778C: beq         $v0, $zero, L_800A77AC
    if (ctx->r2 == 0) {
        // 0x800A7790: nop
    
            goto L_800A77AC;
    }
    // 0x800A7790: nop

    // 0x800A7794: jal         0x80088268
    // 0x800A7798: lh          $a0, 0x10($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X10);
    _gcsectionDll_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x800A7798: lh          $a0, 0x10($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X10);
    after_6:
    // 0x800A779C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A77A0: lbu         $t3, 0x762C($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X762C);
    // 0x800A77A4: bne         $v0, $t3, L_800A77CC
    if (ctx->r2 != ctx->r11) {
        // 0x800A77A8: nop
    
            goto L_800A77CC;
    }
    // 0x800A77A8: nop

L_800A77AC:
    // 0x800A77AC: jal         0x800DA298
    // 0x800A77B0: addiu       $a0, $zero, 0x650
    ctx->r4 = ADD32(0, 0X650);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x800A77B0: addiu       $a0, $zero, 0x650
    ctx->r4 = ADD32(0, 0X650);
    after_7:
    // 0x800A77B4: bne         $v0, $zero, L_800A77CC
    if (ctx->r2 != 0) {
        // 0x800A77B8: nop
    
            goto L_800A77CC;
    }
    // 0x800A77B8: nop

    // 0x800A77BC: jal         0x800EA05C
    // 0x800A77C0: nop

    func_800EA05C(rdram, ctx);
        goto after_8;
    // 0x800A77C0: nop

    after_8:
    // 0x800A77C4: jal         0x80087848
    // 0x800A77C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _cosectionstor_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x800A77C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
L_800A77CC:
    // 0x800A77CC: jal         0x800A7380
    // 0x800A77D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800A7380(rdram, ctx);
        goto after_10;
    // 0x800A77D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x800A77D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A77D8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A77DC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800A77E0: jal         0x800A72A4
    // 0x800A77E4: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    func_800A72A4(rdram, ctx);
        goto after_11;
    // 0x800A77E4: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_11:
    // 0x800A77E8: jal         0x800A5CF0
    // 0x800A77EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800A5CF0(rdram, ctx);
        goto after_12;
    // 0x800A77EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_12:
    // 0x800A77F0: jal         0x800A5C94
    // 0x800A77F4: nop

    func_800A5C94(rdram, ctx);
        goto after_13;
    // 0x800A77F4: nop

    after_13:
    // 0x800A77F8: jal         0x80081724
    // 0x800A77FC: nop

    func_80081724(rdram, ctx);
        goto after_14;
    // 0x800A77FC: nop

    after_14:
    // 0x800A7800: jal         0x800885D8
    // 0x800A7804: nop

    _glintrosyncDll_entrypoint_1(rdram, ctx);
        goto after_15;
    // 0x800A7804: nop

    after_15:
    // 0x800A7808: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800A780C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800A7810: sb          $t5, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r13;
    // 0x800A7814: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800A7818: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800A781C: jal         0x800A759C
    // 0x800A7820: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    func_800A759C(rdram, ctx);
        goto after_16;
    // 0x800A7820: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    after_16:
    // 0x800A7824: jal         0x80015768
    // 0x800A7828: nop

    func_80015768(rdram, ctx);
        goto after_17;
    // 0x800A7828: nop

    after_17:
    // 0x800A782C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7830: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A7834: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800A7838: jr          $ra
    // 0x800A783C: nop

    return;
    // 0x800A783C: nop

;}
RECOMP_FUNC void _bskaztorpedo_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083778: syscall     72
    recomp_syscall_handler(rdram, ctx, 0x80083778);
    return;
    // 0x8008377C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void bamovegoto_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D4: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x808001D8: jr          $ra
    // 0x808001DC: sb          $a1, 0x56($t6)
    MEM_B(0X56, ctx->r14) = ctx->r5;
    return;
    // 0x808001DC: sb          $a1, 0x56($t6)
    MEM_B(0X56, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void chalienkids_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1324, 0X20DC) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x20DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1324, 0X20DC));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x20DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1324, 0X20DC));
;}
RECOMP_FUNC void _baswim_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085270: syscall     156
    recomp_syscall_handler(rdram, ctx, 0x80085270);
    return;
    // 0x80085274: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80809684_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809684: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80809688: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080968C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80809690: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80809694: lw          $s0, 0x188($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X188);
    // 0x80809698: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080969C: jal         0x808024B0
    // 0x808096A0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_808024B0_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x808096A0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x808096A4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808096A8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808096AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808096B0: beq         $a1, $zero, L_8080972C
    if (ctx->r5 == 0) {
        // 0x808096B4: sb          $a1, 0x218($s0)
        MEM_B(0X218, ctx->r16) = ctx->r5;
            goto L_8080972C;
    }
    // 0x808096B4: sb          $a1, 0x218($s0)
    MEM_B(0X218, ctx->r16) = ctx->r5;
    // 0x808096B8: beq         $a1, $at, L_808096D0
    if (ctx->r5 == ctx->r1) {
        // 0x808096BC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808096D0;
    }
    // 0x808096BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808096C0: beq         $a1, $at, L_808096E0
    if (ctx->r5 == ctx->r1) {
        // 0x808096C4: nop
    
            goto L_808096E0;
    }
    // 0x808096C4: nop

    // 0x808096C8: b           L_808096F0
    // 0x808096CC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_808096F0;
    // 0x808096CC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_808096D0:
    // 0x808096D0: jal         0x80802560
    // 0x808096D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80802560_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x808096D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808096D8: b           L_808096EC
    // 0x808096DC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
        goto L_808096EC;
    // 0x808096DC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_808096E0:
    // 0x808096E0: jal         0x80802594
    // 0x808096E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80802594_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x808096E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x808096E8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_808096EC:
    // 0x808096EC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_808096F0:
    // 0x808096F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808096F4: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x808096F8: jal         0x80800290
    // 0x808096FC: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    func_80800290_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x808096FC: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    after_3:
    // 0x80809700: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80809704: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80809708: swc1        $f4, 0x21C($s0)
    MEM_W(0X21C, ctx->r16) = ctx->f4.u32l;
    // 0x8080970C: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80809710: swc1        $f6, 0x220($s0)
    MEM_W(0X220, ctx->r16) = ctx->f6.u32l;
    // 0x80809714: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80809718: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8080971C: swc1        $f8, 0x224($s0)
    MEM_W(0X224, ctx->r16) = ctx->f8.u32l;
    // 0x80809720: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80809724: lwc1        $f10, 0x4($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80809728: swc1        $f10, 0x228($s0)
    MEM_W(0X228, ctx->r16) = ctx->f10.u32l;
L_8080972C:
    // 0x8080972C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80809730: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80809734: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80809738: jr          $ra
    // 0x8080973C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8080973C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800E9B74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9B74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E9B78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9B7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800E9B80: jal         0x800E9D68
    // 0x800E9B84: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800E9D68(rdram, ctx);
        goto after_0;
    // 0x800E9B84: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800E9B88: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800E9B8C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800E9B90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E9B94: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x800E9B98: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x800E9B9C: mflo        $t8
    ctx->r24 = lo;
    // 0x800E9BA0: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800E9BA4: jal         0x800E9DD4
    // 0x800E9BA8: nop

    func_800E9DD4(rdram, ctx);
        goto after_1;
    // 0x800E9BA8: nop

    after_1:
    // 0x800E9BAC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800E9BB0: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E9BB4: beq         $at, $zero, L_800E9BD0
    if (ctx->r1 == 0) {
        // 0x800E9BB8: nop
    
            goto L_800E9BD0;
    }
    // 0x800E9BB8: nop

    // 0x800E9BBC: jal         0x800BE5C4
    // 0x800E9BC0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800BE5C4(rdram, ctx);
        goto after_2;
    // 0x800E9BC0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800E9BC4: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x800E9BC8: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x800E9BCC: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
L_800E9BD0:
    // 0x800E9BD0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E9BD4: addiu       $a0, $a0, 0x2DB0
    ctx->r4 = ADD32(ctx->r4, 0X2DB0);
    // 0x800E9BD8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800E9BDC: jal         0x800B3FD0
    // 0x800E9BE0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800B3FD0(rdram, ctx);
        goto after_3;
    // 0x800E9BE0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x800E9BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E9BE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E9BEC: jr          $ra
    // 0x800E9BF0: nop

    return;
    // 0x800E9BF0: nop

;}
RECOMP_FUNC void func_808035FC_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808035FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803604: jal         0x80106790
    // 0x80803608: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80803608: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080360C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803610: jal         0x80100094
    // 0x80803614: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80803614: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80803618: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080361C: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80803620: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x80803624: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80803628: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
    // 0x8080362C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803630: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803634: jr          $ra
    // 0x80803638: nop

    return;
    // 0x80803638: nop

;}
RECOMP_FUNC void func_800B1328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1328: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800B132C: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x800B1330: mtc1        $a3, $f26
    ctx->f26.u32l = ctx->r7;
    // 0x800B1334: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800B1338: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x800B133C: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x800B1340: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x800B1344: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800B1348: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800B134C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800B1350: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x800B1354: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x800B1358: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800B135C: jal         0x80019CD4
    // 0x800B1360: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    func_80019CD4(rdram, ctx);
        goto after_0;
    // 0x800B1360: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    after_0:
    // 0x800B1364: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x800B1368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B136C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B1370: jal         0x8001980C
    // 0x800B1374: lw          $a3, 0xA0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA0);
    func_8001980C(rdram, ctx);
        goto after_1;
    // 0x800B1374: lw          $a3, 0xA0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA0);
    after_1:
    // 0x800B1378: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x800B137C: jal         0x800193C4
    // 0x800B1380: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    func_800193C4(rdram, ctx);
        goto after_2;
    // 0x800B1380: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    after_2:
    // 0x800B1384: lh          $t6, 0x0($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X0);
    // 0x800B1388: lwc1        $f24, 0xA8($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800B138C: lw          $s2, 0xAC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XAC);
    // 0x800B1390: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B1394: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800B1398: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800B139C: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x800B13A0: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800B13A4: sw          $t9, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r25;
    // 0x800B13A8: lh          $t2, 0x4($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X4);
    // 0x800B13AC: lh          $t0, 0x2($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X2);
    // 0x800B13B0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800B13B4: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800B13B8: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x800B13BC: addu        $s0, $t1, $t9
    ctx->r16 = ADD32(ctx->r9, ctx->r25);
    // 0x800B13C0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800B13C4: addu        $s1, $t3, $s0
    ctx->r17 = ADD32(ctx->r11, ctx->r16);
    // 0x800B13C8: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800B13CC: beql        $at, $zero, L_800B14DC
    if (ctx->r1 == 0) {
        // 0x800B13D0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800B14DC;
    }
    goto skip_0;
    // 0x800B13D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800B13D4: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
L_800B13D8:
    // 0x800B13D8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800B13DC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800B13E0: sllv        $t5, $t4, $v0
    ctx->r13 = S32(ctx->r12 << (ctx->r2 & 31));
    // 0x800B13E4: and         $t6, $t5, $s2
    ctx->r14 = ctx->r13 & ctx->r18;
    // 0x800B13E8: bnel        $t6, $zero, L_800B14CC
    if (ctx->r14 != 0) {
        // 0x800B13EC: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800B14CC;
    }
    goto skip_1;
    // 0x800B13EC: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_1:
    // 0x800B13F0: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
    // 0x800B13F4: div.s       $f20, $f24, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = DIV_S(ctx->f24.fl, ctx->f26.fl);
    // 0x800B13F8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800B13FC: nop

    // 0x800B1400: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B1404: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x800B1408: lh          $t8, 0x4($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X4);
    // 0x800B140C: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800B1410: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800B1414: nop

    // 0x800B1418: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B141C: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800B1420: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x800B1424: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x800B1428: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800B142C: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800B1430: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800B1434: nop

    // 0x800B1438: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B143C: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800B1440: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
    // 0x800B1444: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x800B1448: lwc1        $f18, 0x80($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800B144C: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800B1450: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800B1454: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x800B1458: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B145C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B1460: mul.s       $f18, $f10, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800B1464: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800B1468: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800B146C: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x800B1470: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800B1474: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    // 0x800B1478: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800B147C: jal         0x8002DCA0
    // 0x800B1480: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x800B1480: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_3:
    // 0x800B1484: add.s       $f4, $f20, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x800B1488: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x800B148C: nop

    // 0x800B1490: bc1tl       L_800B14CC
    if (c1cs) {
        // 0x800B1494: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800B14CC;
    }
    goto skip_2;
    // 0x800B1494: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_2:
    // 0x800B1498: lh          $t9, 0x2($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X2);
    // 0x800B149C: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x800B14A0: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800B14A4: sll         $t2, $t9, 4
    ctx->r10 = S32(ctx->r25 << 4);
    // 0x800B14A8: subu        $t3, $s0, $t2
    ctx->r11 = SUB32(ctx->r16, ctx->r10);
    // 0x800B14AC: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x800B14B0: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x800B14B4: mflo        $t6
    ctx->r14 = lo;
    // 0x800B14B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B14BC: sh          $t6, 0x7EE0($at)
    MEM_H(0X7EE0, ctx->r1) = ctx->r14;
    // 0x800B14C0: b           L_800B14DC
    // 0x800B14C4: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
        goto L_800B14DC;
    // 0x800B14C4: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
    // 0x800B14C8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_800B14CC:
    // 0x800B14CC: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800B14D0: bnel        $at, $zero, L_800B13D8
    if (ctx->r1 != 0) {
        // 0x800B14D4: lbu         $v0, 0x8($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X8);
            goto L_800B13D8;
    }
    goto skip_3;
    // 0x800B14D4: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
    skip_3:
    // 0x800B14D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B14DC:
    // 0x800B14DC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800B14E0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800B14E4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800B14E8: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x800B14EC: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x800B14F0: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x800B14F4: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x800B14F8: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x800B14FC: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x800B1500: jr          $ra
    // 0x800B1504: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800B1504: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_8080068C_chmineprospector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080068C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800694: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    // 0x80800698: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(892, 0X1128) << 16);
    // 0x8080069C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(892, 0X1144) << 16);
    // 0x808006A0: addiu       $a3, $a3, 0x1144
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(892, 0X1144));
    // 0x808006A4: addiu       $a2, $a2, 0x1128
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(892, 0X1128));
    // 0x808006A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808006AC: jal         0x80089D28
    // 0x808006B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808006B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808006B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(892, 0XF0C) << 16);
    // 0x808006B8: jal         0x800DC298
    // 0x808006BC: lwc1        $f12, 0xF0C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(892, 0XF0C));
    func_800DC298(rdram, ctx);
        goto after_1;
    // 0x808006BC: lwc1        $f12, 0xF0C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(892, 0XF0C));
    after_1:
    // 0x808006C0: beq         $v0, $zero, L_808006DC
    if (ctx->r2 == 0) {
        // 0x808006C4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808006DC;
    }
    // 0x808006C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808006C8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(892, 0X1134) << 16);
    // 0x808006CC: addiu       $a2, $a2, 0x1134
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(892, 0X1134));
    // 0x808006D0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808006D4: jal         0x80089D20
    // 0x808006D8: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808006D8: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_2:
L_808006DC:
    // 0x808006DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808006E4: jr          $ra
    // 0x808006E8: nop

    return;
    // 0x808006E8: nop

;}
RECOMP_FUNC void boot___ull_divremi(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800029A8: lh          $t7, 0x12($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X12);
    // 0x800029AC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800029B0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800029B4: ld          $t6, 0x8($sp)
    ctx->r14 = LD(ctx->r29, 0X8);
    // 0x800029B8: or          $t8, $t7, $zero
    ctx->r24 = ctx->r15 | 0;
    // 0x800029BC: or          $t9, $t8, $zero
    ctx->r25 = ctx->r24 | 0;
    // 0x800029C0: ddivu       $zero, $t6, $t9
    DDIVU(U64(ctx->r14), U64(ctx->r25), &lo, &hi);
    // 0x800029C4: bne         $t9, $zero, L_800029D0
    if (ctx->r25 != 0) {
        // 0x800029C8: nop
    
            goto L_800029D0;
    }
    // 0x800029C8: nop

    // 0x800029CC: break       7
    do_break(2147494348);
L_800029D0:
    // 0x800029D0: mflo        $t0
    ctx->r8 = lo;
    // 0x800029D4: sd          $t0, 0x0($a0)
    SD(ctx->r8, 0X0, ctx->r4);
    // 0x800029D8: lh          $t2, 0x12($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X12);
    // 0x800029DC: ld          $t1, 0x8($sp)
    ctx->r9 = LD(ctx->r29, 0X8);
    // 0x800029E0: or          $t3, $t2, $zero
    ctx->r11 = ctx->r10 | 0;
    // 0x800029E4: or          $t4, $t3, $zero
    ctx->r12 = ctx->r11 | 0;
    // 0x800029E8: ddivu       $zero, $t1, $t4
    DDIVU(U64(ctx->r9), U64(ctx->r12), &lo, &hi);
    // 0x800029EC: bne         $t4, $zero, L_800029F8
    if (ctx->r12 != 0) {
        // 0x800029F0: nop
    
            goto L_800029F8;
    }
    // 0x800029F0: nop

    // 0x800029F4: break       7
    do_break(2147494388);
L_800029F8:
    // 0x800029F8: mfhi        $t5
    ctx->r13 = hi;
    // 0x800029FC: sd          $t5, 0x0($a1)
    SD(ctx->r13, 0X0, ctx->r5);
    // 0x80002A00: jr          $ra
    // 0x80002A04: nop

    return;
    // 0x80002A04: nop

;}
RECOMP_FUNC void _bainvisible_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800854A8: syscall     164
    recomp_syscall_handler(rdram, ctx, 0x800854A8);
    return;
    // 0x800854AC: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_8010108C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010108C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80101090: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80101094: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80101098: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8010109C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x801010A0: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x801010A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801010A8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x801010AC: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x801010B0: bgez        $t8, L_80101138
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801010B4: nop
    
            goto L_80101138;
    }
    // 0x801010B4: nop

    // 0x801010B8: jal         0x80081D34
    // 0x801010BC: lw          $a0, 0x10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X10);
    func_80081D34(rdram, ctx);
        goto after_0;
    // 0x801010BC: lw          $a0, 0x10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X10);
    after_0:
    // 0x801010C0: beq         $v0, $zero, L_801010D8
    if (ctx->r2 == 0) {
        // 0x801010C4: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_801010D8;
    }
    // 0x801010C4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x801010C8: jal         0x80081D80
    // 0x801010CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80081D80(rdram, ctx);
        goto after_1;
    // 0x801010CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x801010D0: b           L_801010DC
    // 0x801010D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_801010DC;
    // 0x801010D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_801010D8:
    // 0x801010D8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_801010DC:
    // 0x801010DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801010E0: jal         0x80100368
    // 0x801010E4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80100368(rdram, ctx);
        goto after_2;
    // 0x801010E4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x801010E8: lw          $t9, 0x40($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X40);
    // 0x801010EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801010F0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x801010F4: jalr        $t9
    // 0x801010F8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x801010F8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x801010FC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80101100: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80101104: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80101108: beq         $t0, $zero, L_80101130
    if (ctx->r8 == 0) {
        // 0x8010110C: nop
    
            goto L_80101130;
    }
    // 0x8010110C: nop

    // 0x80101110: bne         $v1, $zero, L_80101130
    if (ctx->r3 != 0) {
        // 0x80101114: nop
    
            goto L_80101130;
    }
    // 0x80101114: nop

    // 0x80101118: bgtz        $v0, L_80101130
    if (SIGNED(ctx->r2) > 0) {
        // 0x8010111C: nop
    
            goto L_80101130;
    }
    // 0x8010111C: nop

    // 0x80101120: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x80101124: jal         0x800819B4
    // 0x80101128: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_800819B4(rdram, ctx);
        goto after_4;
    // 0x80101128: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_4:
    // 0x8010112C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
L_80101130:
    // 0x80101130: b           L_80101138
    // 0x80101134: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_80101138;
    // 0x80101134: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80101138:
    // 0x80101138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010113C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80101140: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80101144: jr          $ra
    // 0x80101148: nop

    return;
    // 0x80101148: nop

;}
RECOMP_FUNC void func_808000C8_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D0: jal         0x80800040
    // 0x808000D4: nop

    func_80800040_chstoneballcontrol(rdram, ctx);
        goto after_0;
    // 0x808000D4: nop

    after_0:
    // 0x808000D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4E04) << 16);
    // 0x808000DC: lwc1        $f4, 0x4E04($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4E04));
    // 0x808000E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000E8: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808000EC: jr          $ra
    // 0x808000F0: nop

    return;
    // 0x808000F0: nop

;}
RECOMP_FUNC void func_80800F2C_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F34: jal         0x8080064C
    // 0x80800F38: nop

    bstrexlarge_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800F38: nop

    after_0:
    // 0x80800F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F44: jr          $ra
    // 0x80800F48: nop

    return;
    // 0x80800F48: nop

;}
RECOMP_FUNC void _bavan_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085390: syscall     159
    recomp_syscall_handler(rdram, ctx, 0x80085390);
    return;
    // 0x80085394: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _suflamefx_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089960: syscall     798
    recomp_syscall_handler(rdram, ctx, 0x80089960);
    return;
    // 0x80089964: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void dbanim_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800168: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080016C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800170: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80800174: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80800178: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8080017C: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x80800180: or          $fp, $a2, $zero
    ctx->r30 = ctx->r6 | 0;
    // 0x80800184: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80800188: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8080018C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80800190: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800194: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800198: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8080019C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001A0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808001A4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x808001A8: jal         0x800B2190
    // 0x808001AC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800B2190(rdram, ctx);
        goto after_0;
    // 0x808001AC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808001B0: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x808001B4: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x808001B8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x808001BC: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x808001C0: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x808001C4: addiu       $s3, $v1, 0x4
    ctx->r19 = ADD32(ctx->r3, 0X4);
    // 0x808001C8: blez        $t6, L_80800324
    if (SIGNED(ctx->r14) <= 0) {
        // 0x808001CC: nop
    
            goto L_80800324;
    }
    // 0x808001CC: nop

    // 0x808001D0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808001D4: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x808001D8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_808001DC:
    // 0x808001DC: jal         0x80100480
    // 0x808001E0: lh          $a1, 0x2($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X2);
    func_80100480(rdram, ctx);
        goto after_1;
    // 0x808001E0: lh          $a1, 0x2($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X2);
    after_1:
    // 0x808001E4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808001E8: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x808001EC: jal         0x800ADE2C
    // 0x808001F0: lh          $a1, 0x0($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X0);
    func_800ADE2C(rdram, ctx);
        goto after_2;
    // 0x808001F0: lh          $a1, 0x0($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X0);
    after_2:
    // 0x808001F4: addiu       $s0, $s3, 0x6
    ctx->r16 = ADD32(ctx->r19, 0X6);
    // 0x808001F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808001FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800200: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800204: jal         0x80116568
    // 0x80800208: lh          $a3, 0x2($s3)
    ctx->r7 = MEM_H(ctx->r19, 0X2);
    func_80116568(rdram, ctx);
        goto after_3;
    // 0x80800208: lh          $a3, 0x2($s3)
    ctx->r7 = MEM_H(ctx->r19, 0X2);
    after_3:
    // 0x8080020C: lh          $t7, 0x2($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X2);
    // 0x80800210: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800214: lh          $a1, 0x4($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X4);
    // 0x80800218: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8080021C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80800220: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80800224: jal         0x80100480
    // 0x80800228: addu        $s2, $s0, $t9
    ctx->r18 = ADD32(ctx->r16, ctx->r25);
    func_80100480(rdram, ctx);
        goto after_4;
    // 0x80800228: addu        $s2, $s0, $t9
    ctx->r18 = ADD32(ctx->r16, ctx->r25);
    after_4:
    // 0x8080022C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800230: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80800234: jal         0x800ADE2C
    // 0x80800238: lh          $a1, 0x0($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X0);
    func_800ADE2C(rdram, ctx);
        goto after_5;
    // 0x80800238: lh          $a1, 0x0($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X0);
    after_5:
    // 0x8080023C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800240: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800244: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800248: jal         0x801163B0
    // 0x8080024C: lh          $a3, 0x4($s3)
    ctx->r7 = MEM_H(ctx->r19, 0X4);
    func_801163B0(rdram, ctx);
        goto after_6;
    // 0x8080024C: lh          $a3, 0x4($s3)
    ctx->r7 = MEM_H(ctx->r19, 0X4);
    after_6:
    // 0x80800250: lh          $t1, 0x4($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X4);
    // 0x80800254: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80800258: addu        $s2, $s2, $t2
    ctx->r18 = ADD32(ctx->r18, ctx->r10);
    // 0x8080025C: lh          $a0, 0x0($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X0);
    // 0x80800260: slti        $at, $a0, -0x1
    ctx->r1 = SIGNED(ctx->r4) < -0X1 ? 1 : 0;
    // 0x80800264: bnel        $at, $zero, L_8080030C
    if (ctx->r1 != 0) {
        // 0x80800268: lw          $t5, 0x48($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X48);
            goto L_8080030C;
    }
    goto skip_0;
    // 0x80800268: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    skip_0:
L_8080026C:
    // 0x8080026C: bnel        $s4, $a0, L_80800280
    if (ctx->r20 != ctx->r4) {
        // 0x80800270: lh          $t4, 0x0($s1)
        ctx->r12 = MEM_H(ctx->r17, 0X0);
            goto L_80800280;
    }
    goto skip_1;
    // 0x80800270: lh          $t4, 0x0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X0);
    skip_1:
    // 0x80800274: b           L_808002F4
    // 0x80800278: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
        goto L_808002F4;
    // 0x80800278: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    // 0x8080027C: lh          $t4, 0x0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X0);
L_80800280:
    // 0x80800280: sll         $t3, $a0, 4
    ctx->r11 = S32(ctx->r4 << 4);
    // 0x80800284: addu        $v0, $t3, $s5
    ctx->r2 = ADD32(ctx->r11, ctx->r21);
    // 0x80800288: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // 0x8080028C: lh          $t5, 0x2($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X2);
    // 0x80800290: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80800294: sh          $t5, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r13;
    // 0x80800298: lh          $t6, 0x4($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X4);
    // 0x8080029C: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
    // 0x808002A0: lwc1        $f4, -0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, -0XC);
    // 0x808002A4: lh          $t7, 0x0($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X0);
    // 0x808002A8: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x808002AC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x808002B0: addu        $v1, $t8, $s6
    ctx->r3 = ADD32(ctx->r24, ctx->r22);
    // 0x808002B4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x808002B8: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x808002BC: nop

    // 0x808002C0: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
    // 0x808002C4: lwc1        $f10, -0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, -0X8);
    // 0x808002C8: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x808002CC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808002D0: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x808002D4: nop

    // 0x808002D8: sb          $t2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r10;
    // 0x808002DC: lwc1        $f4, -0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, -0X4);
    // 0x808002E0: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x808002E4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x808002E8: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x808002EC: nop

    // 0x808002F0: sb          $t4, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r12;
L_808002F4:
    // 0x808002F4: lh          $a0, 0x2($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X2);
    // 0x808002F8: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x808002FC: slti        $at, $a0, -0x1
    ctx->r1 = SIGNED(ctx->r4) < -0X1 ? 1 : 0;
    // 0x80800300: beq         $at, $zero, L_8080026C
    if (ctx->r1 == 0) {
        // 0x80800304: nop
    
            goto L_8080026C;
    }
    // 0x80800304: nop

    // 0x80800308: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
L_8080030C:
    // 0x8080030C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80800310: addiu       $s3, $s2, 0x2
    ctx->r19 = ADD32(ctx->r18, 0X2);
    // 0x80800314: lh          $t6, 0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X2);
    // 0x80800318: slt         $at, $s7, $t6
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8080031C: bnel        $at, $zero, L_808001DC
    if (ctx->r1 != 0) {
        // 0x80800320: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_808001DC;
    }
    goto skip_2;
    // 0x80800320: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    skip_2:
L_80800324:
    // 0x80800324: jal         0x800B2344
    // 0x80800328: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_800B2344(rdram, ctx);
        goto after_7;
    // 0x80800328: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_7:
    // 0x8080032C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800330: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800334: jal         0x8002E660
    // 0x80800338: sll         $a1, $v0, 4
    ctx->r5 = S32(ctx->r2 << 4);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_8;
    // 0x80800338: sll         $a1, $v0, 4
    ctx->r5 = S32(ctx->r2 << 4);
    after_8:
    // 0x8080033C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800340: jal         0x8002E660
    // 0x80800344: sll         $a1, $s0, 2
    ctx->r5 = S32(ctx->r16 << 2);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_9;
    // 0x80800344: sll         $a1, $s0, 2
    ctx->r5 = S32(ctx->r16 << 2);
    after_9:
    // 0x80800348: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8080034C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800350: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800354: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800358: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8080035C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800360: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80800364: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80800368: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8080036C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80800370: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80800374: jr          $ra
    // 0x80800378: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800378: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8080037C: nop

;}
RECOMP_FUNC void func_800F63B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F63B4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F63B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F63BC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F63C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F63C4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F63C8: jal         0x8008F7B4
    // 0x800F63CC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8008F7B4(rdram, ctx);
        goto after_0;
    // 0x800F63CC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F63D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F63D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F63D8: jr          $ra
    // 0x800F63DC: nop

    return;
    // 0x800F63DC: nop

;}
RECOMP_FUNC void func_80802CE0_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_80802CE0_chcollballcontrol");
    // 0x80802CE0: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80802CE4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80802CE8: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80802CEC: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80802CF0: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80802CF4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80802CF8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80802CFC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80802D00: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80802D04: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80802D08: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80802D0C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80802D10: jal         0x80100094
    // 0x80802D14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802D14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802D18: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1840, 0X4F3C) << 16);
    // 0x80802D1C: addiu       $t7, $t7, 0x4F3C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1840, 0X4F3C));
    // 0x80802D20: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80802D24: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80802D28: addiu       $t6, $sp, 0x84
    ctx->r14 = ADD32(ctx->r29, 0X84);
    // 0x80802D2C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80802D30: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80802D34: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x80802D38: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80802D3C: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80802D40: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x80802D44: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80802D48: jal         0x80106790
    // 0x80802D4C: lw          $a0, 0x3C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X3C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80802D4C: lw          $a0, 0x3C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X3C);
    after_1:
    // 0x80802D50: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80802D54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802D58: jal         0x80100094
    // 0x80802D5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80802D5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80802D60: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x80802D64: lhu         $v1, 0x72($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X72);
    // 0x80802D68: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80802D6C: srl         $t1, $v1, 10
    ctx->r9 = S32(U32(ctx->r3) >> 10);
    // 0x80802D70: beq         $t1, $at, L_80802D80
    if (ctx->r9 == ctx->r1) {
        // 0x80802D74: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80802D80;
    }
    // 0x80802D74: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80802D78: bnel        $t1, $at, L_808030A4
    if (ctx->r9 != ctx->r1) {
        // 0x80802D7C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_808030A4;
    }
    goto skip_0;
    // 0x80802D7C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
L_80802D80:
    // 0x80802D80: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80802D84: lwc1        $f6, 0x0($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80802D88: addiu       $t4, $zero, 0x7F
    ctx->r12 = ADD32(0, 0X7F);
    // 0x80802D8C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80802D90: nop

    // 0x80802D94: bc1tl       L_80802DB4
    if (c1cs) {
        // 0x80802D98: sw          $t4, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r12;
            goto L_80802DB4;
    }
    goto skip_1;
    // 0x80802D98: sw          $t4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r12;
    skip_1:
    // 0x80802D9C: lhu         $t2, 0x72($s5)
    ctx->r10 = MEM_HU(ctx->r21, 0X72);
    // 0x80802DA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802DA4: srl         $t3, $t2, 10
    ctx->r11 = S32(U32(ctx->r10) >> 10);
    // 0x80802DA8: bnel        $t3, $at, L_808030A4
    if (ctx->r11 != ctx->r1) {
        // 0x80802DAC: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_808030A4;
    }
    goto skip_2;
    // 0x80802DAC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x80802DB0: sw          $t4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r12;
L_80802DB4:
    // 0x80802DB4: lbu         $t5, 0x3A($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X3A);
    // 0x80802DB8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4BE8) << 16);
    // 0x80802DBC: lwc1        $f22, 0x4BE8($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4BE8));
    // 0x80802DC0: blez        $t5, L_80802F0C
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80802DC4: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80802F0C;
    }
    // 0x80802DC4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80802DC8: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x80802DCC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80802DD0: addiu       $s3, $sp, 0x64
    ctx->r19 = ADD32(ctx->r29, 0X64);
    // 0x80802DD4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80802DD8: lhu         $t9, 0x72($s5)
    ctx->r25 = MEM_HU(ctx->r21, 0X72);
L_80802DDC:
    // 0x80802DDC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80802DE0: srl         $t8, $t9, 10
    ctx->r24 = S32(U32(ctx->r25) >> 10);
    // 0x80802DE4: bne         $a2, $t8, L_80802DF8
    if (ctx->r6 != ctx->r24) {
        // 0x80802DE8: nop
    
            goto L_80802DF8;
    }
    // 0x80802DE8: nop

    // 0x80802DEC: lbu         $t6, 0x20($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X20);
    // 0x80802DF0: beql        $s1, $t6, L_80802EF0
    if (ctx->r17 == ctx->r14) {
        // 0x80802DF4: lw          $t9, 0x7C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X7C);
            goto L_80802EF0;
    }
    goto skip_3;
    // 0x80802DF4: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    skip_3:
L_80802DF8:
    // 0x80802DF8: jal         0x80089AF8
    // 0x80802DFC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x80802DFC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80802E00: bne         $v0, $zero, L_80802EEC
    if (ctx->r2 != 0) {
        // 0x80802E04: lui         $t7, 0x8080
        ctx->r15 = S32(RELOC_HI16(1840, 0X4F4C) << 16);
            goto L_80802EEC;
    }
    // 0x80802E04: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1840, 0X4F4C) << 16);
    // 0x80802E08: addiu       $t7, $t7, 0x4F4C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1840, 0X4F4C));
    // 0x80802E0C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80802E10: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80802E14: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80802E18: sw          $at, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r1;
    // 0x80802E1C: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x80802E20: sw          $t1, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r9;
    // 0x80802E24: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80802E28: jal         0x80089AC8
    // 0x80802E2C: sw          $at, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r1;
    _sukickball_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80802E2C: sw          $at, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r1;
    after_4:
    // 0x80802E30: beq         $v0, $zero, L_80802E9C
    if (ctx->r2 == 0) {
        // 0x80802E34: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80802E9C;
    }
    // 0x80802E34: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80802E38: jal         0x800F6C5C
    // 0x80802E3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F6C5C(rdram, ctx);
        goto after_5;
    // 0x80802E3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80802E40: beql        $v0, $zero, L_80802EF0
    if (ctx->r2 == 0) {
        // 0x80802E44: lw          $t9, 0x7C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X7C);
            goto L_80802EF0;
    }
    goto skip_4;
    // 0x80802E44: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    skip_4:
    // 0x80802E48: jal         0x800F5410
    // 0x80802E4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F5410(rdram, ctx);
        goto after_6;
    // 0x80802E4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80802E50: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80802E54: bne         $v0, $at, L_80802EEC
    if (ctx->r2 != ctx->r1) {
        // 0x80802E58: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80802EEC;
    }
    // 0x80802E58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802E5C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80802E60: jal         0x800F5A00
    // 0x80802E64: addiu       $s2, $s5, 0x4
    ctx->r18 = ADD32(ctx->r21, 0X4);
    func_800F5A00(rdram, ctx);
        goto after_7;
    // 0x80802E64: addiu       $s2, $s5, 0x4
    ctx->r18 = ADD32(ctx->r21, 0X4);
    after_7:
    // 0x80802E68: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802E6C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802E70: jal         0x800EFFB4
    // 0x80802E74: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800EFFB4(rdram, ctx);
        goto after_8;
    // 0x80802E74: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_8:
    // 0x80802E78: beq         $v0, $zero, L_80802EEC
    if (ctx->r2 == 0) {
        // 0x80802E7C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80802EEC;
    }
    // 0x80802E7C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802E80: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x80802E84: addiu       $t3, $sp, 0x84
    ctx->r11 = ADD32(ctx->r29, 0X84);
    // 0x80802E88: addu        $s0, $t2, $t3
    ctx->r16 = ADD32(ctx->r10, ctx->r11);
    // 0x80802E8C: jal         0x800EEB40
    // 0x80802E90: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EEB40(rdram, ctx);
        goto after_9;
    // 0x80802E90: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_9:
    // 0x80802E94: b           L_80802EEC
    // 0x80802E98: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
        goto L_80802EEC;
    // 0x80802E98: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
L_80802E9C:
    // 0x80802E9C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80802EA0: jal         0x80089AD8
    // 0x80802EA4: addiu       $s2, $s5, 0x4
    ctx->r18 = ADD32(ctx->r21, 0X4);
    _sukickball_entrypoint_8(rdram, ctx);
        goto after_10;
    // 0x80802EA4: addiu       $s2, $s5, 0x4
    ctx->r18 = ADD32(ctx->r21, 0X4);
    after_10:
    // 0x80802EA8: jal         0x80106790
    // 0x80802EAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_11;
    // 0x80802EAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x80802EB0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80802EB4: jal         0x800EE7F8
    // 0x80802EB8: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_12;
    // 0x80802EB8: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_12:
    // 0x80802EBC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802EC0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802EC4: jal         0x800EFFB4
    // 0x80802EC8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800EFFB4(rdram, ctx);
        goto after_13;
    // 0x80802EC8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_13:
    // 0x80802ECC: beq         $v0, $zero, L_80802EEC
    if (ctx->r2 == 0) {
        // 0x80802ED0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80802EEC;
    }
    // 0x80802ED0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802ED4: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x80802ED8: addiu       $t5, $sp, 0x84
    ctx->r13 = ADD32(ctx->r29, 0X84);
    // 0x80802EDC: addu        $s0, $t4, $t5
    ctx->r16 = ADD32(ctx->r12, ctx->r13);
    // 0x80802EE0: jal         0x800EEB40
    // 0x80802EE4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EEB40(rdram, ctx);
        goto after_14;
    // 0x80802EE4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_14:
    // 0x80802EE8: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
L_80802EEC:
    // 0x80802EEC: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
L_80802EF0:
    // 0x80802EF0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80802EF4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80802EF8: lbu         $t8, 0x3A($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X3A);
    // 0x80802EFC: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80802F00: bnel        $at, $zero, L_80802DDC
    if (ctx->r1 != 0) {
        // 0x80802F04: lhu         $t9, 0x72($s5)
        ctx->r25 = MEM_HU(ctx->r21, 0X72);
            goto L_80802DDC;
    }
    goto skip_5;
    // 0x80802F04: lhu         $t9, 0x72($s5)
    ctx->r25 = MEM_HU(ctx->r21, 0X72);
    skip_5:
    // 0x80802F08: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80802F0C:
    // 0x80802F0C: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x80802F10: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80802F14: lbu         $v0, 0x3A($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X3A);
    // 0x80802F18: blezl       $v0, L_80802F74
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80802F1C: lw          $t3, 0x74($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X74);
            goto L_80802F74;
    }
    goto skip_6;
    // 0x80802F1C: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    skip_6:
    // 0x80802F20: lhu         $v1, 0x72($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X72);
    // 0x80802F24: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x80802F28: srl         $t0, $v1, 10
    ctx->r8 = S32(U32(ctx->r3) >> 10);
    // 0x80802F2C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_80802F30:
    // 0x80802F30: bne         $a2, $v1, L_80802F40
    if (ctx->r6 != ctx->r3) {
        // 0x80802F34: sll         $t1, $s1, 2
        ctx->r9 = S32(ctx->r17 << 2);
            goto L_80802F40;
    }
    // 0x80802F34: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x80802F38: lbu         $t7, 0x20($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X20);
    // 0x80802F3C: beq         $s1, $t7, L_80802F60
    if (ctx->r17 == ctx->r15) {
        // 0x80802F40: addu        $t2, $a0, $t1
        ctx->r10 = ADD32(ctx->r4, ctx->r9);
            goto L_80802F60;
    }
L_80802F40:
    // 0x80802F40: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x80802F44: lwc1        $f0, 0x0($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80802F48: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80802F4C: nop

    // 0x80802F50: bc1fl       L_80802F64
    if (!c1cs) {
        // 0x80802F54: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80802F64;
    }
    goto skip_7;
    // 0x80802F54: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_7:
    // 0x80802F58: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80802F5C: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
L_80802F60:
    // 0x80802F60: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80802F64:
    // 0x80802F64: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80802F68: bne         $at, $zero, L_80802F30
    if (ctx->r1 != 0) {
        // 0x80802F6C: nop
    
            goto L_80802F30;
    }
    // 0x80802F6C: nop

    // 0x80802F70: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
L_80802F74:
    // 0x80802F74: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x80802F78: beql        $t3, $v0, L_808030A4
    if (ctx->r11 == ctx->r2) {
        // 0x80802F7C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_808030A4;
    }
    goto skip_8;
    // 0x80802F7C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_8:
    // 0x80802F80: lbu         $a1, 0x20($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X20);
    // 0x80802F84: beql        $v0, $a1, L_80802FC8
    if (ctx->r2 == ctx->r5) {
        // 0x80802F88: lw          $t4, 0x74($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X74);
            goto L_80802FC8;
    }
    goto skip_9;
    // 0x80802F88: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    skip_9:
    // 0x80802F8C: jal         0x80089AD0
    // 0x80802F90: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    _sukickball_entrypoint_7(rdram, ctx);
        goto after_15;
    // 0x80802F90: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_15:
    // 0x80802F94: beq         $v0, $zero, L_80802FAC
    if (ctx->r2 == 0) {
        // 0x80802F98: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80802FAC;
    }
    // 0x80802F98: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80802F9C: jal         0x80089AF0
    // 0x80802FA0: lbu         $a1, 0x20($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X20);
    _sukickball_entrypoint_11(rdram, ctx);
        goto after_16;
    // 0x80802FA0: lbu         $a1, 0x20($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X20);
    after_16:
    // 0x80802FA4: b           L_80802FC8
    // 0x80802FA8: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
        goto L_80802FC8;
    // 0x80802FA8: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
L_80802FAC:
    // 0x80802FAC: lbu         $a0, 0x20($s6)
    ctx->r4 = MEM_BU(ctx->r22, 0X20);
    // 0x80802FB0: jal         0x800F4F98
    // 0x80802FB4: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    func_800F4F98(rdram, ctx);
        goto after_17;
    // 0x80802FB4: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    after_17:
    // 0x80802FB8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80802FBC: jal         0x80089AF0
    // 0x80802FC0: lbu         $a1, 0x20($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X20);
    _sukickball_entrypoint_11(rdram, ctx);
        goto after_18;
    // 0x80802FC0: lbu         $a1, 0x20($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X20);
    after_18:
    // 0x80802FC4: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
L_80802FC8:
    // 0x80802FC8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80802FCC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802FD0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80802FD4: sb          $t4, 0x20($s6)
    MEM_B(0X20, ctx->r22) = ctx->r12;
    // 0x80802FD8: andi        $a1, $t4, 0xFF
    ctx->r5 = ctx->r12 & 0XFF;
    // 0x80802FDC: jal         0x80089AC8
    // 0x80802FE0: swc1        $f8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f8.u32l;
    _sukickball_entrypoint_6(rdram, ctx);
        goto after_19;
    // 0x80802FE0: swc1        $f8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f8.u32l;
    after_19:
    // 0x80802FE4: beq         $v0, $zero, L_80803008
    if (ctx->r2 == 0) {
        // 0x80802FE8: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80803008;
    }
    // 0x80802FE8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80802FEC: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80802FF0: addiu       $a2, $a2, 0x6EA0
    ctx->r6 = ADD32(ctx->r6, 0X6EA0);
    // 0x80802FF4: lbu         $a0, 0x20($s6)
    ctx->r4 = MEM_BU(ctx->r22, 0X20);
    // 0x80802FF8: jal         0x800F4950
    // 0x80802FFC: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    func_800F4950(rdram, ctx);
        goto after_20;
    // 0x80802FFC: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    after_20:
    // 0x80803000: b           L_80803028
    // 0x80803004: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
        goto L_80803028;
    // 0x80803004: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
L_80803008:
    // 0x80803008: jal         0x80089AD8
    // 0x8080300C: lbu         $a1, 0x20($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X20);
    _sukickball_entrypoint_8(rdram, ctx);
        goto after_21;
    // 0x8080300C: lbu         $a1, 0x20($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X20);
    after_21:
    // 0x80803010: jal         0x80106790
    // 0x80803014: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_22;
    // 0x80803014: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_22:
    // 0x80803018: lbu         $t5, 0x65($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X65);
    // 0x8080301C: andi        $t9, $t5, 0xFFEF
    ctx->r25 = ctx->r13 & 0XFFEF;
    // 0x80803020: sb          $t9, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r25;
    // 0x80803024: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
L_80803028:
    // 0x80803028: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8080302C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80803030: lw          $v0, 0x24($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X24);
    // 0x80803034: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80803038: srl         $t6, $v0, 22
    ctx->r14 = S32(U32(ctx->r2) >> 22);
    // 0x8080303C: beq         $t6, $at, L_8080306C
    if (ctx->r14 == ctx->r1) {
        // 0x80803040: addiu       $at, $zero, 0x43
        ctx->r1 = ADD32(0, 0X43);
            goto L_8080306C;
    }
    // 0x80803040: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x80803044: beq         $t6, $at, L_8080307C
    if (ctx->r14 == ctx->r1) {
        // 0x80803048: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8080307C;
    }
    // 0x80803048: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8080304C: addiu       $at, $zero, 0x44
    ctx->r1 = ADD32(0, 0X44);
    // 0x80803050: bne         $t6, $at, L_80803088
    if (ctx->r14 != ctx->r1) {
        // 0x80803054: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80803088;
    }
    // 0x80803054: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80803058: lbu         $a1, 0x20($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X20);
    // 0x8080305C: jal         0x80089AE8
    // 0x80803060: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _sukickball_entrypoint_10(rdram, ctx);
        goto after_23;
    // 0x80803060: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_23:
    // 0x80803064: b           L_8080308C
    // 0x80803068: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_8080308C;
    // 0x80803068: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8080306C:
    // 0x8080306C: jal         0x80089AE8
    // 0x80803070: lbu         $a1, 0x20($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X20);
    _sukickball_entrypoint_10(rdram, ctx);
        goto after_24;
    // 0x80803070: lbu         $a1, 0x20($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X20);
    after_24:
    // 0x80803074: b           L_8080308C
    // 0x80803078: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_8080308C;
    // 0x80803078: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8080307C:
    // 0x8080307C: lbu         $a1, 0x20($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X20);
    // 0x80803080: jal         0x80089AE8
    // 0x80803084: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _sukickball_entrypoint_10(rdram, ctx);
        goto after_25;
    // 0x80803084: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_25:
L_80803088:
    // 0x80803088: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8080308C:
    // 0x8080308C: jal         0x80801764
    // 0x80803090: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801764_chcollballcontrol(rdram, ctx);
        goto after_26;
    // 0x80803090: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_26:
    // 0x80803094: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80803098: nop

    // 0x8080309C: swc1        $f10, 0x24($s5)
    MEM_W(0X24, ctx->r21) = ctx->f10.u32l;
    // 0x808030A0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_808030A4:
    // 0x808030A4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808030A8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808030AC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808030B0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x808030B4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x808030B8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x808030BC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x808030C0: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x808030C4: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x808030C8: jr          $ra
    // 0x808030CC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x808030CC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void bsbtrot_entrypoint_41(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808024C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808024CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808024D0: jal         0x80800538
    // 0x808024D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800538_bsbtrot(rdram, ctx);
        goto after_0;
    // 0x808024D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808024D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808024DC: jal         0x80085000
    // 0x808024E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bashoes_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x808024E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808024E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808024E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808024EC: jal         0x80802380
    // 0x808024F0: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    func_80802380_bsbtrot(rdram, ctx);
        goto after_2;
    // 0x808024F0: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    after_2:
    // 0x808024F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808024F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808024FC: jr          $ra
    // 0x80802500: nop

    return;
    // 0x80802500: nop

;}
RECOMP_FUNC void func_80103140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103140: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80103144: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80103148: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010314C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80103150: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80103154: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80103158: lhu         $t0, 0x46($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X46);
    // 0x8010315C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80103160: lhu         $v1, 0x14($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X14);
    // 0x80103164: lhu         $t7, 0x4A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X4A);
    // 0x80103168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010316C: bne         $v1, $t0, L_80103188
    if (ctx->r3 != ctx->r8) {
        // 0x80103170: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_80103188;
    }
    // 0x80103170: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80103174: lhu         $t6, 0x16($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X16);
    // 0x80103178: bnel        $t6, $t7, L_8010318C
    if (ctx->r14 != ctx->r15) {
        // 0x8010317C: lw          $t8, 0x70($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X70);
            goto L_8010318C;
    }
    goto skip_0;
    // 0x8010317C: lw          $t8, 0x70($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X70);
    skip_0:
    // 0x80103180: b           L_8010329C
    // 0x80103184: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8010329C;
    // 0x80103184: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80103188:
    // 0x80103188: lw          $t8, 0x70($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X70);
L_8010318C:
    // 0x8010318C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80103190: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80103194: sll         $t9, $t8, 28
    ctx->r25 = S32(ctx->r24 << 28);
    // 0x80103198: srl         $t1, $t9, 31
    ctx->r9 = S32(U32(ctx->r25) >> 31);
    // 0x8010319C: jal         0x8010381C
    // 0x801031A0: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    func_8010381C(rdram, ctx);
        goto after_0;
    // 0x801031A0: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    after_0:
    // 0x801031A4: jal         0x80103938
    // 0x801031A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103938(rdram, ctx);
        goto after_1;
    // 0x801031A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801031AC: lbu         $t2, 0x74($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X74);
    // 0x801031B0: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801031B4: andi        $t3, $t2, 0xFF7F
    ctx->r11 = ctx->r10 & 0XFF7F;
    // 0x801031B8: sb          $t3, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r11;
    // 0x801031BC: sw          $zero, 0xC($t4)
    MEM_W(0XC, ctx->r12) = 0;
    // 0x801031C0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801031C4: sh          $zero, 0x68($s0)
    MEM_H(0X68, ctx->r16) = 0;
    // 0x801031C8: sh          $zero, 0x6A($s0)
    MEM_H(0X6A, ctx->r16) = 0;
    // 0x801031CC: sh          $zero, 0x62($s0)
    MEM_H(0X62, ctx->r16) = 0;
    // 0x801031D0: lhu         $t5, 0x18($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X18);
    // 0x801031D4: andi        $t6, $t5, 0x1F
    ctx->r14 = ctx->r13 & 0X1F;
    // 0x801031D8: sh          $t6, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r14;
    // 0x801031DC: lh          $t7, 0x8C($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X8C);
    // 0x801031E0: beq         $t7, $zero, L_801031F0
    if (ctx->r15 == 0) {
        // 0x801031E4: nop
    
            goto L_801031F0;
    }
    // 0x801031E4: nop

    // 0x801031E8: jal         0x80104328
    // 0x801031EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104328(rdram, ctx);
        goto after_2;
    // 0x801031EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_801031F0:
    // 0x801031F0: jal         0x800D58FC
    // 0x801031F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800D58FC(rdram, ctx);
        goto after_3;
    // 0x801031F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x801031F8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x801031FC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80103200: lhu         $t8, 0x46($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X46);
    // 0x80103204: sh          $t8, 0x14($t9)
    MEM_H(0X14, ctx->r25) = ctx->r24;
    // 0x80103208: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8010320C: lhu         $t1, 0x4A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X4A);
    // 0x80103210: bne         $v0, $zero, L_80103230
    if (ctx->r2 != 0) {
        // 0x80103214: sh          $t1, 0x16($t2)
        MEM_H(0X16, ctx->r10) = ctx->r9;
            goto L_80103230;
    }
    // 0x80103214: sh          $t1, 0x16($t2)
    MEM_H(0X16, ctx->r10) = ctx->r9;
    // 0x80103218: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8010321C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80103220: lbu         $t5, 0xB($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XB);
    // 0x80103224: ori         $t6, $t5, 0x2
    ctx->r14 = ctx->r13 | 0X2;
    // 0x80103228: b           L_80103244
    // 0x8010322C: sb          $t6, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r14;
        goto L_80103244;
    // 0x8010322C: sb          $t6, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r14;
L_80103230:
    // 0x80103230: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80103234: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x80103238: lbu         $t8, 0xB($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XB);
    // 0x8010323C: andi        $t9, $t8, 0xFFFD
    ctx->r25 = ctx->r24 & 0XFFFD;
    // 0x80103240: sb          $t9, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r25;
L_80103244:
    // 0x80103244: bne         $v0, $zero, L_80103254
    if (ctx->r2 != 0) {
        // 0x80103248: nop
    
            goto L_80103254;
    }
    // 0x80103248: nop

    // 0x8010324C: jal         0x80103328
    // 0x80103250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103328(rdram, ctx);
        goto after_4;
    // 0x80103250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80103254:
    // 0x80103254: jal         0x80103930
    // 0x80103258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103930(rdram, ctx);
        goto after_5;
    // 0x80103258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8010325C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80103260: beql        $t1, $zero, L_8010329C
    if (ctx->r9 == 0) {
        // 0x80103264: lw          $v0, 0x28($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X28);
            goto L_8010329C;
    }
    goto skip_1;
    // 0x80103264: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x80103268: lw          $t2, 0x70($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X70);
    // 0x8010326C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80103270: sll         $t4, $t2, 28
    ctx->r12 = S32(ctx->r10 << 28);
    // 0x80103274: bltzl       $t4, L_8010329C
    if (SIGNED(ctx->r12) < 0) {
        // 0x80103278: lw          $v0, 0x28($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X28);
            goto L_8010329C;
    }
    goto skip_2;
    // 0x80103278: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    skip_2:
    // 0x8010327C: bnel        $t5, $zero, L_8010329C
    if (ctx->r13 != 0) {
        // 0x80103280: lw          $v0, 0x28($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X28);
            goto L_8010329C;
    }
    goto skip_3;
    // 0x80103280: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    skip_3:
    // 0x80103284: jal         0x801039E4
    // 0x80103288: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_801039E4(rdram, ctx);
        goto after_6;
    // 0x80103288: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x8010328C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80103290: jal         0x800D62E4
    // 0x80103294: lhu         $a0, 0x14($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X14);
    func_800D62E4(rdram, ctx);
        goto after_7;
    // 0x80103294: lhu         $a0, 0x14($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X14);
    after_7:
    // 0x80103298: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_8010329C:
    // 0x8010329C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801032A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801032A4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801032A8: jr          $ra
    // 0x801032AC: nop

    return;
    // 0x801032AC: nop

;}
RECOMP_FUNC void gcgoto_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005BC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x808005C0: jr          $ra
    // 0x808005C4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x808005C4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_808009A0_chmayafarmer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009A0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808009A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808009A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808009AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009B0: jal         0x8010D254
    // 0x808009B4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x808009B4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x808009B8: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x808009BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808009C0: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808009C4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808009C8: nop

    // 0x808009CC: bc1fl       L_80800A0C
    if (!c1cs) {
        // 0x808009D0: lbu         $t0, 0x65($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X65);
            goto L_80800A0C;
    }
    goto skip_0;
    // 0x808009D0: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    skip_0:
    // 0x808009D4: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808009D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808009DC: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808009E0: beq         $t6, $at, L_808009F0
    if (ctx->r14 == ctx->r1) {
        // 0x808009E4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808009F0;
    }
    // 0x808009E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808009E8: bnel        $t6, $at, L_808009FC
    if (ctx->r14 != ctx->r1) {
        // 0x808009EC: lbu         $t7, 0x65($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X65);
            goto L_808009FC;
    }
    goto skip_1;
    // 0x808009EC: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    skip_1:
L_808009F0:
    // 0x808009F0: jal         0x808010DC
    // 0x808009F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808010DC_chmayafarmer(rdram, ctx);
        goto after_1;
    // 0x808009F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808009F8: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
L_808009FC:
    // 0x808009FC: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x80800A00: b           L_80800B88
    // 0x80800A04: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
        goto L_80800B88;
    // 0x80800A04: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x80800A08: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
L_80800A0C:
    // 0x80800A0C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800A10: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80800A14: jal         0x80106790
    // 0x80800A18: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x80800A18: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    after_2:
    // 0x80800A1C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800A20: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800A24: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80800A28: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80800A2C: jal         0x800EFFB4
    // 0x80800A30: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    func_800EFFB4(rdram, ctx);
        goto after_3;
    // 0x80800A30: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    after_3:
    // 0x80800A34: beq         $v0, $zero, L_80800A48
    if (ctx->r2 == 0) {
        // 0x80800A38: addiu       $a1, $zero, 0x11
        ctx->r5 = ADD32(0, 0X11);
            goto L_80800A48;
    }
    // 0x80800A38: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80800A3C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800A40: jal         0x8010114C
    // 0x80800A44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_4;
    // 0x80800A44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
L_80800A48:
    // 0x80800A48: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800A4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800A50: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80800A54: srl         $t2, $v0, 10
    ctx->r10 = S32(U32(ctx->r2) >> 10);
    // 0x80800A58: beq         $t2, $at, L_80800A80
    if (ctx->r10 == ctx->r1) {
        // 0x80800A5C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800A80;
    }
    // 0x80800A5C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A60: beq         $t2, $at, L_80800A80
    if (ctx->r10 == ctx->r1) {
        // 0x80800A64: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800A80;
    }
    // 0x80800A64: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800A68: beq         $t2, $at, L_80800AC8
    if (ctx->r10 == ctx->r1) {
        // 0x80800A6C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800AC8;
    }
    // 0x80800A6C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800A70: beq         $t2, $at, L_80800B34
    if (ctx->r10 == ctx->r1) {
        // 0x80800A74: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B34;
    }
    // 0x80800A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A78: b           L_80800B50
    // 0x80800A7C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
        goto L_80800B50;
    // 0x80800A7C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
L_80800A80:
    // 0x80800A80: jal         0x800DA9E4
    // 0x80800A84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA9E4(rdram, ctx);
        goto after_5;
    // 0x80800A84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800A88: beq         $v0, $zero, L_80800AA0
    if (ctx->r2 == 0) {
        // 0x80800A8C: lw          $a0, 0x44($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X44);
            goto L_80800AA0;
    }
    // 0x80800A8C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800A90: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80800A94: addiu       $a2, $zero, 0x418
    ctx->r6 = ADD32(0, 0X418);
    // 0x80800A98: jal         0x808000B0
    // 0x80800A9C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    func_808000B0_chmayafarmer(rdram, ctx);
        goto after_6;
    // 0x80800A9C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_6:
L_80800AA0:
    // 0x80800AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AA4: jal         0x80800D60
    // 0x80800AA8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80800D60_chmayafarmer(rdram, ctx);
        goto after_7;
    // 0x80800AA8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_7:
    // 0x80800AAC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800AB0: jal         0x800EF04C
    // 0x80800AB4: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_8;
    // 0x80800AB4: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_8:
    // 0x80800AB8: jal         0x808010DC
    // 0x80800ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808010DC_chmayafarmer(rdram, ctx);
        goto after_9;
    // 0x80800ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800AC0: b           L_80800B50
    // 0x80800AC4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
        goto L_80800B50;
    // 0x80800AC4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
L_80800AC8:
    // 0x80800AC8: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800ACC: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800AD0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80800AD4: nop

    // 0x80800AD8: bc1fl       L_80800AFC
    if (!c1cs) {
        // 0x80800ADC: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_80800AFC;
    }
    goto skip_2;
    // 0x80800ADC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_2:
    // 0x80800AE0: jal         0x80801040
    // 0x80800AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801040_chmayafarmer(rdram, ctx);
        goto after_10;
    // 0x80800AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800AE8: jal         0x808010DC
    // 0x80800AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808010DC_chmayafarmer(rdram, ctx);
        goto after_11;
    // 0x80800AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800AF0: b           L_80800B50
    // 0x80800AF4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
        goto L_80800B50;
    // 0x80800AF4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800AF8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_80800AFC:
    // 0x80800AFC: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x80800B00: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x80800B04: jal         0x800EF04C
    // 0x80800B08: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800EF04C(rdram, ctx);
        goto after_12;
    // 0x80800B08: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_12:
    // 0x80800B0C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1612, 0X123C) << 16);
    // 0x80800B10: addiu       $a2, $a2, 0x123C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1612, 0X123C));
    // 0x80800B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B18: jal         0x80089D18
    // 0x80800B1C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_13;
    // 0x80800B1C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_13:
    // 0x80800B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B24: jal         0x80102424
    // 0x80800B28: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_14;
    // 0x80800B28: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_14:
    // 0x80800B2C: b           L_80800B50
    // 0x80800B30: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
        goto L_80800B50;
    // 0x80800B30: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
L_80800B34:
    // 0x80800B34: jal         0x80101E14
    // 0x80800B38: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    func_80101E14(rdram, ctx);
        goto after_15;
    // 0x80800B38: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_15:
    // 0x80800B3C: beql        $v0, $zero, L_80800B50
    if (ctx->r2 == 0) {
        // 0x80800B40: addiu       $a0, $sp, 0x2C
        ctx->r4 = ADD32(ctx->r29, 0X2C);
            goto L_80800B50;
    }
    goto skip_3;
    // 0x80800B40: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    skip_3:
    // 0x80800B44: jal         0x80089CA8
    // 0x80800B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_16;
    // 0x80800B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800B4C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
L_80800B50:
    // 0x80800B50: jal         0x800EE7F8
    // 0x80800B54: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_17;
    // 0x80800B54: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_17:
    // 0x80800B58: lui         $at, 0x4523
    ctx->r1 = S32(0X4523 << 16);
    // 0x80800B5C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800B60: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1612, 0X11B8) << 16);
    // 0x80800B64: lwc1        $f6, 0x11B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1612, 0X11B8));
    // 0x80800B68: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x80800B6C: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B74: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800B78: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800B7C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800B80: jal         0x80085770
    // 0x80800B84: nop

    _chbadshad_entrypoint_1(rdram, ctx);
        goto after_18;
    // 0x80800B84: nop

    after_18:
L_80800B88:
    // 0x80800B88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B90: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800B94: jr          $ra
    // 0x80800B98: nop

    return;
    // 0x80800B98: nop

;}
RECOMP_FUNC void func_800BC580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC580: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BC584: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800BC588: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BC58C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800BC590: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800BC594: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800BC598: jal         0x800BC474
    // 0x800BC59C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800BC474(rdram, ctx);
        goto after_0;
    // 0x800BC59C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x800BC5A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BC5A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BC5A8: jr          $ra
    // 0x800BC5AC: nop

    return;
    // 0x800BC5AC: nop

;}
RECOMP_FUNC void _chdrawbridgeswitches_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087160: syscall     523
    recomp_syscall_handler(rdram, ctx, 0x80087160);
    return;
    // 0x80087164: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _dbid_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800879D8: syscall     646
    recomp_syscall_handler(rdram, ctx, 0x800879D8);
    return;
    // 0x800879DC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void ncbaglide_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800008: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080000C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800018: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x8080001C: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x80800020: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    // 0x80800024: jal         0x80111590
    // 0x80800028: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80111590(rdram, ctx);
        goto after_0;
    // 0x80800028: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800030: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x80800034: jal         0x80111B8C
    // 0x80800038: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    func_80111B8C(rdram, ctx);
        goto after_1;
    // 0x80800038: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    after_1:
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800040: jal         0x80115858
    // 0x80800044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80115858(rdram, ctx);
        goto after_2;
    // 0x80800044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080004C: jal         0x80115870
    // 0x80800050: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80115870(rdram, ctx);
        goto after_3;
    // 0x80800050: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800058: jal         0x801124D0
    // 0x8080005C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_801124D0(rdram, ctx);
        goto after_4;
    // 0x8080005C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800060: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800064: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800068: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080006C: jr          $ra
    // 0x80800070: nop

    return;
    // 0x80800070: nop

;}
RECOMP_FUNC void bsbshock_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808004F4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(116, 0X870) << 16);
    // 0x808004F8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808004FC: jr          $ra
    // 0x80800500: lw          $v0, 0x870($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(116, 0X870));
    return;
    // 0x80800500: lw          $v0, 0x870($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(116, 0X870));
;}
RECOMP_FUNC void _bsblongleg_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800829F8: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x800829F8);
    return;
    // 0x800829FC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
