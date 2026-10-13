#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void bskazfly_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017EC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808017F0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(236, 0X1C78) << 16);
    // 0x808017F4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808017F8: jr          $ra
    // 0x808017FC: lw          $v0, 0x1C78($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(236, 0X1C78));
    return;
    // 0x808017FC: lw          $v0, 0x1C78($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(236, 0X1C78));
;}
RECOMP_FUNC void chhellterskelter_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(964, 0X7C8) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x7C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(964, 0X7C8));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x7C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(964, 0X7C8));
;}
RECOMP_FUNC void _bsbshock_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082B28: syscall     27
    recomp_syscall_handler(rdram, ctx, 0x80082B28);
    return;
    // 0x80082B2C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800000_sccustom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800004: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80800008: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80800014: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80800018: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8080001C: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x80800020: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80800024: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80800028: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8080002C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80800030: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80800034: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800038: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8080003C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800040: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80800044: jal         0x8008A5D8
    // 0x80800048: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    _scinfobar_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80800048: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8080004C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800050: jal         0x8008A610
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _scinfobar_entrypoint_18(rdram, ctx);
        goto after_1;
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800058: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8080005C: jal         0x8008A5F8
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _scinfobar_entrypoint_15(rdram, ctx);
        goto after_2;
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800064: jal         0x800B8C50
    // 0x80800068: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    func_800B8C50(rdram, ctx);
        goto after_3;
    // 0x80800068: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_3:
    // 0x8080006C: jal         0x8008A608
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _scinfobar_entrypoint_17(rdram, ctx);
        goto after_4;
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800074: beq         $v0, $zero, L_80800098
    if (ctx->r2 == 0) {
        // 0x80800078: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800098;
    }
    // 0x80800078: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080007C: beq         $v0, $at, L_808000A0
    if (ctx->r2 == ctx->r1) {
        // 0x80800080: addiu       $a0, $zero, 0x80
        ctx->r4 = ADD32(0, 0X80);
            goto L_808000A0;
    }
    // 0x80800080: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x80800084: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x80800088: beq         $v0, $s4, L_808000B4
    if (ctx->r2 == ctx->r20) {
        // 0x8080008C: nop
    
            goto L_808000B4;
    }
    // 0x8080008C: nop

    // 0x80800090: b           L_80800114
    // 0x80800094: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
        goto L_80800114;
    // 0x80800094: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
L_80800098:
    // 0x80800098: b           L_80800110
    // 0x8080009C: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
        goto L_80800110;
    // 0x8080009C: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
L_808000A0:
    // 0x808000A0: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x808000A4: jal         0x800B8CBC
    // 0x808000A8: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_800B8CBC(rdram, ctx);
        goto after_5;
    // 0x808000A8: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_5:
    // 0x808000AC: b           L_80800110
    // 0x808000B0: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
        goto L_80800110;
    // 0x808000B0: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
L_808000B4:
    // 0x808000B4: jal         0x8001211C
    // 0x808000B8: nop

    func_8001211C(rdram, ctx);
        goto after_6;
    // 0x808000B8: nop

    after_6:
    // 0x808000BC: sll         $a0, $v0, 5
    ctx->r4 = S32(ctx->r2 << 5);
    // 0x808000C0: andi        $t6, $a0, 0x1FF
    ctx->r14 = ctx->r4 & 0X1FF;
    // 0x808000C4: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x808000C8: bne         $at, $zero, L_808000D8
    if (ctx->r1 != 0) {
        // 0x808000CC: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_808000D8;
    }
    // 0x808000CC: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x808000D0: addiu       $t7, $zero, 0x200
    ctx->r15 = ADD32(0, 0X200);
    // 0x808000D4: subu        $v1, $t7, $t6
    ctx->r3 = SUB32(ctx->r15, ctx->r14);
L_808000D8:
    // 0x808000D8: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x808000DC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808000E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808000E8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808000EC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808000F0: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x808000F4: nop

    // 0x808000F8: addiu       $a0, $v1, 0x7F
    ctx->r4 = ADD32(ctx->r3, 0X7F);
    // 0x808000FC: andi        $t9, $a0, 0xFF
    ctx->r25 = ctx->r4 & 0XFF;
    // 0x80800100: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80800104: andi        $a1, $t9, 0xFF
    ctx->r5 = ctx->r25 & 0XFF;
    // 0x80800108: jal         0x800B8CBC
    // 0x8080010C: andi        $a2, $t9, 0xFF
    ctx->r6 = ctx->r25 & 0XFF;
    func_800B8CBC(rdram, ctx);
        goto after_7;
    // 0x8080010C: andi        $a2, $t9, 0xFF
    ctx->r6 = ctx->r25 & 0XFF;
    after_7:
L_80800110:
    // 0x80800110: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
L_80800114:
    // 0x80800114: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800118: mtc1        $s1, $f18
    ctx->f18.u32l = ctx->r17;
    // 0x8080011C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800120: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x80800124: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800128: lw          $s1, 0x68($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X68);
    // 0x8080012C: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    // 0x80800130: cvt.s.w     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800134: add.s       $f26, $f6, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f26.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800138: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    // 0x8080013C: nop

    // 0x80800140: bc1f        L_80800178
    if (!c1cs) {
        // 0x80800144: nop
    
            goto L_80800178;
    }
    // 0x80800144: nop

    // 0x80800148: sub.s       $f16, $f26, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f26.fl - ctx->f20.fl;
    // 0x8080014C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800150: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800154: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800158: div.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f26.fl);
    // 0x8080015C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800160: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80800164: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800168: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8080016C: mfc1        $s0, $f16
    ctx->r16 = (int32_t)ctx->f16.u32l;
    // 0x80800170: b           L_80800178
    // 0x80800174: nop

        goto L_80800178;
    // 0x80800174: nop

L_80800178:
    // 0x80800178: jal         0x800E7188
    // 0x8080017C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E7188(rdram, ctx);
        goto after_8;
    // 0x8080017C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80800180: addiu       $s2, $v0, -0x1
    ctx->r18 = ADD32(ctx->r2, -0X1);
    // 0x80800184: jal         0x800B8C8C
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B8C8C(rdram, ctx);
        goto after_9;
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080018C: jal         0x800B7F14
    // 0x80800190: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800B7F14(rdram, ctx);
        goto after_10;
    // 0x80800190: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_10:
    // 0x80800194: bltz        $s2, L_80800224
    if (SIGNED(ctx->r18) < 0) {
        // 0x80800198: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_80800224;
    }
    // 0x80800198: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x8080019C: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x808001A0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808001A4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808001A8: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x808001AC: nop

    // 0x808001B0: cvt.s.w     $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    ctx->f22.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808001B4: mtc1        $s0, $f18
    ctx->f18.u32l = ctx->r16;
L_808001B8:
    // 0x808001B8: subu        $t2, $s2, $s0
    ctx->r10 = SUB32(ctx->r18, ctx->r16);
    // 0x808001BC: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x808001C0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808001C4: addu        $t4, $s1, $s0
    ctx->r12 = ADD32(ctx->r17, ctx->r16);
    // 0x808001C8: mul.s       $f6, $f24, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f4.fl);
    // 0x808001CC: add.s       $f2, $f26, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f26.fl + ctx->f6.fl;
    // 0x808001D0: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x808001D4: nop

    // 0x808001D8: bc1f        L_808001E4
    if (!c1cs) {
        // 0x808001DC: nop
    
            goto L_808001E4;
    }
    // 0x808001DC: nop

    // 0x808001E0: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
L_808001E4:
    // 0x808001E4: bnel        $s3, $s4, L_808001FC
    if (ctx->r19 != ctx->r20) {
        // 0x808001E8: lbu         $a3, 0x0($t4)
        ctx->r7 = MEM_BU(ctx->r12, 0X0);
            goto L_808001FC;
    }
    goto skip_0;
    // 0x808001E8: lbu         $a3, 0x0($t4)
    ctx->r7 = MEM_BU(ctx->r12, 0X0);
    skip_0:
    // 0x808001EC: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x808001F0: b           L_808001FC
    // 0x808001F4: lbu         $a3, 0x0($t3)
    ctx->r7 = MEM_BU(ctx->r11, 0X0);
        goto L_808001FC;
    // 0x808001F4: lbu         $a3, 0x0($t3)
    ctx->r7 = MEM_BU(ctx->r11, 0X0);
    // 0x808001F8: lbu         $a3, 0x0($t4)
    ctx->r7 = MEM_BU(ctx->r12, 0X0);
L_808001FC:
    // 0x808001FC: add.s       $f8, $f22, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f22.fl + ctx->f2.fl;
    // 0x80800200: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800204: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800208: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8080020C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800210: jal         0x800B8DEC
    // 0x80800214: nop

    func_800B8DEC(rdram, ctx);
        goto after_11;
    // 0x80800214: nop

    after_11:
    // 0x80800218: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8080021C: bgezl       $s0, L_808001B8
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80800220: mtc1        $s0, $f18
        ctx->f18.u32l = ctx->r16;
            goto L_808001B8;
    }
    goto skip_1;
    // 0x80800220: mtc1        $s0, $f18
    ctx->f18.u32l = ctx->r16;
    skip_1:
L_80800224:
    // 0x80800224: jal         0x800B811C
    // 0x80800228: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800B811C(rdram, ctx);
        goto after_12;
    // 0x80800228: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_12:
    // 0x8080022C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80800230: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800234: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800238: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8080023C: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80800240: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80800244: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80800248: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8080024C: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80800250: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80800254: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80800258: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8080025C: jr          $ra
    // 0x80800260: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80800260: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8001B3A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B3A0: lbu         $t7, -0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, -0X1);
    // 0x8001B3A4: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x8001B3A8: jr          $ra
    // 0x8001B3AC: sb          $t8, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r24;
    return;
    // 0x8001B3AC: sb          $t8, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_80800498_bsmumswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800498: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080049C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004A0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808004A4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808004A8: jal         0x8008CABC
    // 0x808004AC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808004AC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x808004B0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808004B4: jal         0x80800114
    // 0x808004B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800114_bsmumswim(rdram, ctx);
        goto after_1;
    // 0x808004B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808004BC: jal         0x8008AF24
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808004C4: jal         0x8009E710
    // 0x808004C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_3;
    // 0x808004C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x808004CC: addiu       $at, $zero, 0xF1
    ctx->r1 = ADD32(0, 0XF1);
    // 0x808004D0: bne         $v0, $at, L_808004E4
    if (ctx->r2 != ctx->r1) {
        // 0x808004D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004E4;
    }
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D8: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x808004DC: jal         0x8008B1C8
    // 0x808004E0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_8008B1C8(rdram, ctx);
        goto after_4;
    // 0x808004E0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_4:
L_808004E4:
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E8: jal         0x8008AED4
    // 0x808004EC: addiu       $a1, $zero, 0x9D
    ctx->r5 = ADD32(0, 0X9D);
    anctrl_setIndex(rdram, ctx);
        goto after_5;
    // 0x808004EC: addiu       $a1, $zero, 0x9D
    ctx->r5 = ADD32(0, 0X9D);
    after_5:
    // 0x808004F0: lui         $a1, 0x4033
    ctx->r5 = S32(0X4033 << 16);
    // 0x808004F4: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808004F8: jal         0x8008B1BC
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_6;
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800504: jal         0x8008B134
    // 0x80800508: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_7;
    // 0x80800508: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x8080050C: jal         0x8008B064
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_8;
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800514: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800518: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080051C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800520: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800524: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800528: jal         0x8009FFD8
    // 0x8080052C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_9;
    // 0x8080052C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_9:
    // 0x80800530: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800534: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80800538: jal         0x8009C99C
    // 0x8080053C: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_10;
    // 0x8080053C: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_10:
    // 0x80800540: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800544: jal         0x8009B9B0
    // 0x80800548: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_11;
    // 0x80800548: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_11:
    // 0x8080054C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800550: jal         0x800A4DA4
    // 0x80800554: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800A4DA4(rdram, ctx);
        goto after_12;
    // 0x80800554: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_12:
    // 0x80800558: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080055C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800560: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800564: jr          $ra
    // 0x80800568: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800568: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80802AB8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802AB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802ABC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80802AC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802AC4: beq         $a1, $at, L_80802B48
    if (ctx->r5 == ctx->r1) {
        // 0x80802AC8: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80802B48;
    }
    // 0x80802AC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802ACC: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80802AD0: beq         $a1, $at, L_80802B84
    if (ctx->r5 == ctx->r1) {
        // 0x80802AD4: addiu       $at, $zero, 0x1C
        ctx->r1 = ADD32(0, 0X1C);
            goto L_80802B84;
    }
    // 0x80802AD4: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80802AD8: beq         $a1, $at, L_80802AFC
    if (ctx->r5 == ctx->r1) {
        // 0x80802ADC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80802AFC;
    }
    // 0x80802ADC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802AE0: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80802AE4: beq         $a1, $at, L_80802B10
    if (ctx->r5 == ctx->r1) {
        // 0x80802AE8: addiu       $at, $zero, 0x3B
        ctx->r1 = ADD32(0, 0X3B);
            goto L_80802B10;
    }
    // 0x80802AE8: addiu       $at, $zero, 0x3B
    ctx->r1 = ADD32(0, 0X3B);
    // 0x80802AEC: beq         $a1, $at, L_80802BBC
    if (ctx->r5 == ctx->r1) {
        // 0x80802AF0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80802BBC;
    }
    // 0x80802AF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802AF4: b           L_80802BD0
    // 0x80802AF8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80802BD0;
    // 0x80802AF8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80802AFC:
    // 0x80802AFC: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x80802B00: jal         0x8080290C
    // 0x80802B04: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_8080290C_chdiggerboss(rdram, ctx);
        goto after_0;
    // 0x80802B04: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_0:
    // 0x80802B08: b           L_80802BD0
    // 0x80802B0C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80802BD0;
    // 0x80802B0C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80802B10:
    // 0x80802B10: jal         0x800F54E4
    // 0x80802B14: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80802B14: nop

    after_1:
    // 0x80802B18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802B1C: jal         0x800F82D4
    // 0x80802B20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_2;
    // 0x80802B20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80802B24: addiu       $a0, $zero, 0x19A
    ctx->r4 = ADD32(0, 0X19A);
    // 0x80802B28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802B2C: jal         0x80087A60
    // 0x80802B30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _gcgoto_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80802B30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80802B34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80802B38: jal         0x800A7AD4
    // 0x80802B3C: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_800A7AD4(rdram, ctx);
        goto after_4;
    // 0x80802B3C: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_4:
    // 0x80802B40: b           L_80802BD0
    // 0x80802B44: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80802BD0;
    // 0x80802B44: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80802B48:
    // 0x80802B48: jal         0x800F54E4
    // 0x80802B4C: nop

    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x80802B4C: nop

    after_5:
    // 0x80802B50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802B54: jal         0x800F82D4
    // 0x80802B58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_6;
    // 0x80802B58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80802B5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802B60: addiu       $a1, $zero, 0x171D
    ctx->r5 = ADD32(0, 0X171D);
    // 0x80802B64: jal         0x80803660
    // 0x80802B68: addiu       $a2, $zero, 0x14C
    ctx->r6 = ADD32(0, 0X14C);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_7;
    // 0x80802B68: addiu       $a2, $zero, 0x14C
    ctx->r6 = ADD32(0, 0X14C);
    after_7:
    // 0x80802B6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802B70: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x80802B74: jal         0x8080290C
    // 0x80802B78: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_8080290C_chdiggerboss(rdram, ctx);
        goto after_8;
    // 0x80802B78: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_8:
    // 0x80802B7C: b           L_80802BD0
    // 0x80802B80: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80802BD0;
    // 0x80802B80: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80802B84:
    // 0x80802B84: jal         0x800DA544
    // 0x80802B88: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    func_800DA544(rdram, ctx);
        goto after_9;
    // 0x80802B88: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    after_9:
    // 0x80802B8C: jal         0x80088178
    // 0x80802B90: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_10;
    // 0x80802B90: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_10:
    // 0x80802B94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802B98: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80802B9C: jal         0x80802878
    // 0x80802BA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_11;
    // 0x80802BA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x80802BA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802BA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80802BAC: jal         0x80803BE8
    // 0x80802BB0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_12;
    // 0x80802BB0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_12:
    // 0x80802BB4: b           L_80802BD0
    // 0x80802BB8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80802BD0;
    // 0x80802BB8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80802BBC:
    // 0x80802BBC: jal         0x80805D64
    // 0x80802BC0: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    func_80805D64_chdiggerboss(rdram, ctx);
        goto after_13;
    // 0x80802BC0: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    after_13:
    // 0x80802BC4: b           L_80802BD0
    // 0x80802BC8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80802BD0;
    // 0x80802BC8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80802BCC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80802BD0:
    // 0x80802BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802BD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802BD8: jr          $ra
    // 0x80802BDC: nop

    return;
    // 0x80802BDC: nop

;}
RECOMP_FUNC void _baattach_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084450: syscall     111
    recomp_syscall_handler(rdram, ctx, 0x80084450);
    return;
    // 0x80084454: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void bskaztorpedo_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D34: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800D38: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(296, 0X1740) << 16);
    // 0x80800D3C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800D40: jr          $ra
    // 0x80800D44: lw          $v0, 0x1740($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(296, 0X1740));
    return;
    // 0x80800D44: lw          $v0, 0x1740($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(296, 0X1740));
;}
RECOMP_FUNC void func_808010B8_chfactorytoxiccloud(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808010BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808010C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808010C4: jal         0x80089BC0
    // 0x808010C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _subaddiejoy_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808010C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808010CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2300, 0X1418) << 16);
    // 0x808010D0: lwc1        $f4, 0x1418($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2300, 0X1418));
    // 0x808010D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010D8: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x808010DC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808010E0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808010E4: lui         $a3, 0x41C8
    ctx->r7 = S32(0X41C8 << 16);
    // 0x808010E8: jal         0x80102BAC
    // 0x808010EC: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    func_80102BAC(rdram, ctx);
        goto after_1;
    // 0x808010EC: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x808010F0: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808010F4: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808010F8: jal         0x80013728
    // 0x808010FC: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    func_80013728(rdram, ctx);
        goto after_2;
    // 0x808010FC: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    after_2:
    // 0x80801100: jal         0x800F2100
    // 0x80801104: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_3;
    // 0x80801104: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x80801108: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8080110C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801110: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    // 0x80801114: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80801118: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8080111C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80801120: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80801124: ori         $a1, $a1, 0x26
    ctx->r5 = ctx->r5 | 0X26;
    // 0x80801128: bc1f        L_80801138
    if (!c1cs) {
        // 0x8080112C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801138;
    }
    // 0x8080112C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801130: b           L_80801148
    // 0x80801134: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
        goto L_80801148;
    // 0x80801134: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
L_80801138:
    // 0x80801138: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080113C: nop

    // 0x80801140: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80801144: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
L_80801148:
    // 0x80801148: jal         0x8010BA80
    // 0x8080114C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_8010BA80(rdram, ctx);
        goto after_4;
    // 0x8080114C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_4:
    // 0x80801150: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801154: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801158: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080115C: jr          $ra
    // 0x80801160: nop

    return;
    // 0x80801160: nop

;}
RECOMP_FUNC void func_800FC74C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC74C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FC750: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FC754: jal         0x800FB5F8
    // 0x800FC758: nop

    func_800FB5F8(rdram, ctx);
        goto after_0;
    // 0x800FC758: nop

    after_0:
    // 0x800FC75C: beq         $v0, $zero, L_800FC778
    if (ctx->r2 == 0) {
        // 0x800FC760: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800FC778;
    }
    // 0x800FC760: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FC764: lh          $t6, 0x28($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X28);
    // 0x800FC768: bltzl       $t6, L_800FC77C
    if (SIGNED(ctx->r14) < 0) {
        // 0x800FC76C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FC77C;
    }
    goto skip_0;
    // 0x800FC76C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800FC770: jal         0x800FB774
    // 0x800FC774: nop

    func_800FB774(rdram, ctx);
        goto after_1;
    // 0x800FC774: nop

    after_1:
L_800FC778:
    // 0x800FC778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FC77C:
    // 0x800FC77C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FC780: jr          $ra
    // 0x800FC784: nop

    return;
    // 0x800FC784: nop

;}
RECOMP_FUNC void _glzone_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088780: syscall     703
    recomp_syscall_handler(rdram, ctx, 0x80088780);
    return;
    // 0x80088784: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _subaddiejoy_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089BD8: syscall     805
    recomp_syscall_handler(rdram, ctx, 0x80089BD8);
    return;
    // 0x80089BDC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_8009861C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009861C: lw          $t6, 0xE0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE0);
    // 0x80098620: jr          $ra
    // 0x80098624: lbu         $v0, 0x2E($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X2E);
    return;
    // 0x80098624: lbu         $v0, 0x2E($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X2E);
;}
RECOMP_FUNC void _babee_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084560: syscall     114
    recomp_syscall_handler(rdram, ctx, 0x80084560);
    return;
    // 0x80084564: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void idtwinklecolour_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800628: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080062C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800630: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800634: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800638: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8080063C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800640: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800644: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x80800648: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x8080064C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800650: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800654: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800658: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8080065C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800660: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800664: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80800668: jal         0x80088888
    // 0x8080066C: addiu       $a3, $s2, 0x6
    ctx->r7 = ADD32(ctx->r18, 0X6);
    _glidmake_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080066C: addiu       $a3, $s2, 0x6
    ctx->r7 = ADD32(ctx->r18, 0X6);
    after_0:
    // 0x80800670: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800674: jal         0x80088890
    // 0x80800678: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    _glidmake_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800678: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_1:
    // 0x8080067C: sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // 0x80800680: addiu       $v1, $sp, 0x40
    ctx->r3 = ADD32(ctx->r29, 0X40);
    // 0x80800684: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800688: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x8080068C: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
L_80800690:
    // 0x80800690: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x80800694: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80800698: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x8080069C: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x808006A0: sh          $t8, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r24;
    // 0x808006A4: lh          $v0, -0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, -0X2);
    // 0x808006A8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x808006AC: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808006B0: mflo        $t9
    ctx->r25 = lo;
    // 0x808006B4: addu        $s1, $s1, $t9
    ctx->r17 = ADD32(ctx->r17, ctx->r25);
    // 0x808006B8: bnel        $at, $zero, L_80800690
    if (ctx->r1 != 0) {
        // 0x808006BC: lh          $t6, 0x6($a0)
        ctx->r14 = MEM_H(ctx->r4, 0X6);
            goto L_80800690;
    }
    goto skip_0;
    // 0x808006BC: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    skip_0:
    // 0x808006C0: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x808006C4: jal         0x8002DCA0
    // 0x808006C8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x808006C8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_2:
    // 0x808006CC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808006D0: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808006D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808006D8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808006DC: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x808006E0: sh          $s3, 0x22($s2)
    MEM_H(0X22, ctx->r18) = ctx->r19;
    // 0x808006E4: lh          $v0, 0x22($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X22);
    // 0x808006E8: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x808006EC: addiu       $s0, $zero, 0x14
    ctx->r16 = ADD32(0, 0X14);
    // 0x808006F0: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x808006F4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808006F8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808006FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800700: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x80800704: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800708: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x8080070C: nop

    // 0x80800710: sh          $t3, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r11;
    // 0x80800714: lh          $t4, 0x1A($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X1A);
    // 0x80800718: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8080071C: nop

    // 0x80800720: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800724: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800728: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8080072C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80800730: blez        $v0, L_80800740
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800734: sh          $t6, 0x18($s2)
        MEM_H(0X18, ctx->r18) = ctx->r14;
            goto L_80800740;
    }
    // 0x80800734: sh          $t6, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r14;
    // 0x80800738: bne         $at, $zero, L_80800748
    if (ctx->r1 != 0) {
        // 0x8080073C: nop
    
            goto L_80800748;
    }
    // 0x8080073C: nop

L_80800740:
    // 0x80800740: sh          $t7, 0x22($s2)
    MEM_H(0X22, ctx->r18) = ctx->r15;
    // 0x80800744: lh          $v0, 0x22($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X22);
L_80800748:
    // 0x80800748: multu       $v0, $s0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080074C: mflo        $a0
    ctx->r4 = lo;
    // 0x80800750: jal         0x8001ACCC
    // 0x80800754: nop

    heap_alloc(rdram, ctx);
        goto after_3;
    // 0x80800754: nop

    after_3:
    // 0x80800758: lh          $t8, 0x22($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X22);
    // 0x8080075C: sw          $v0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r2;
    // 0x80800760: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800764: multu       $t8, $s0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800768: mflo        $a1
    ctx->r5 = lo;
    // 0x8080076C: jal         0x8002D6E0
    // 0x80800770: nop

    _bzero(rdram, ctx);
        goto after_4;
    // 0x80800770: nop

    after_4:
    // 0x80800774: lh          $t9, 0x22($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X22);
    // 0x80800778: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080077C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800780: blez        $t9, L_808007C0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80800784: addiu       $s3, $zero, 0x1
        ctx->r19 = ADD32(0, 0X1);
            goto L_808007C0;
    }
    // 0x80800784: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80800788: lw          $t0, 0x24($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X24);
L_8080078C:
    // 0x8080078C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800790: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800794: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x80800798: sb          $s3, 0xD($t1)
    MEM_B(0XD, ctx->r9) = ctx->r19;
    // 0x8080079C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x808007A0: jal         0x80800574
    // 0x808007A4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_80800574_idtwinklecolour(rdram, ctx);
        goto after_5;
    // 0x808007A4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_5:
    // 0x808007A8: lh          $t2, 0x22($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X22);
    // 0x808007AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808007B0: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x808007B4: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x808007B8: bnel        $at, $zero, L_8080078C
    if (ctx->r1 != 0) {
        // 0x808007BC: lw          $t0, 0x24($s2)
        ctx->r8 = MEM_W(ctx->r18, 0X24);
            goto L_8080078C;
    }
    goto skip_1;
    // 0x808007BC: lw          $t0, 0x24($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X24);
    skip_1:
L_808007C0:
    // 0x808007C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808007C4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808007C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808007CC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808007D0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808007D4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x808007D8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x808007DC: jr          $ra
    // 0x808007E0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x808007E0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800263C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800263C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800263C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800263C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800263CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800263D0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800263D4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800263D8: sw          $zero, 0x10($t6)
    MEM_W(0X10, ctx->r14) = 0;
    // 0x800263DC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800263E0: sw          $zero, 0x8($t7)
    MEM_W(0X8, ctx->r15) = 0;
    // 0x800263E4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800263E8: sw          $zero, 0xC($t8)
    MEM_W(0XC, ctx->r24) = 0;
    // 0x800263EC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800263F0: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x800263F4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800263F8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800263FC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80026400: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80026404: blez        $t1, L_80026444
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80026408: nop
    
            goto L_80026444;
    }
    // 0x80026408: nop

L_8002640C:
    // 0x8002640C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80026410: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80026414: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80026418: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8002641C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80026420: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80026424: jal         0x80020E40
    // 0x80026428: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    func_80020E40(rdram, ctx);
        goto after_0;
    // 0x80026428: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_0:
    // 0x8002642C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80026430: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80026434: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80026438: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002643C: bne         $at, $zero, L_8002640C
    if (ctx->r1 != 0) {
        // 0x80026440: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_8002640C;
    }
    // 0x80026440: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80026444:
    // 0x80026444: b           L_8002644C
    // 0x80026448: nop

        goto L_8002644C;
    // 0x80026448: nop

L_8002644C:
    // 0x8002644C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026450: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80026454: jr          $ra
    // 0x80026458: nop

    return;
    // 0x80026458: nop

;}
RECOMP_FUNC void func_808020F4_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808020F4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808020F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808020FC: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80802100: lbu         $t6, 0x9B($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X9B);
    // 0x80802104: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80802108: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8080210C: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80802110: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x80802114: bgez        $t6, L_80802128
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80802118: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80802128;
    }
    // 0x80802118: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8080211C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80802120: nop

    // 0x80802124: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80802128:
    // 0x80802128: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4BB4) << 16);
    // 0x8080212C: lwc1        $f4, 0x4BB4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4BB4));
    // 0x80802130: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80802134: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80802138: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8080213C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80802140: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80802144: nop

    // 0x80802148: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8080214C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80802150: nop

    // 0x80802154: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80802158: beql        $t8, $zero, L_808021A8
    if (ctx->r24 == 0) {
        // 0x8080215C: mfc1        $t8, $f8
        ctx->r24 = (int32_t)ctx->f8.u32l;
            goto L_808021A8;
    }
    goto skip_0;
    // 0x8080215C: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x80802160: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802164: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80802168: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8080216C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80802170: nop

    // 0x80802174: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80802178: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8080217C: nop

    // 0x80802180: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80802184: bne         $t8, $zero, L_8080219C
    if (ctx->r24 != 0) {
        // 0x80802188: nop
    
            goto L_8080219C;
    }
    // 0x80802188: nop

    // 0x8080218C: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80802190: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80802194: b           L_808021B4
    // 0x80802198: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_808021B4;
    // 0x80802198: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8080219C:
    // 0x8080219C: b           L_808021B4
    // 0x808021A0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_808021B4;
    // 0x808021A0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x808021A4: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
L_808021A8:
    // 0x808021A8: nop

    // 0x808021AC: bltz        $t8, L_8080219C
    if (SIGNED(ctx->r24) < 0) {
        // 0x808021B0: nop
    
            goto L_8080219C;
    }
    // 0x808021B0: nop

L_808021B4:
    // 0x808021B4: sb          $t8, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = ctx->r24;
    // 0x808021B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4BB8) << 16);
    // 0x808021BC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x808021C0: lwc1        $f18, 0x4BB8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4BB8));
    // 0x808021C4: lwc1        $f10, 0x38($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X38);
    // 0x808021C8: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x808021CC: jr          $ra
    // 0x808021D0: swc1        $f16, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x808021D0: swc1        $f16, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_801015B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801015B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801015B4: jr          $ra
    // 0x801015B8: addiu       $v0, $v0, 0x5A90
    ctx->r2 = ADD32(ctx->r2, 0X5A90);
    return;
    // 0x801015B8: addiu       $v0, $v0, 0x5A90
    ctx->r2 = ADD32(ctx->r2, 0X5A90);
;}
RECOMP_FUNC void func_800CF2D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF2D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CF2D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF2DC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800CF2E0: jal         0x800D3E40
    // 0x800CF2E4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_800D3E40(rdram, ctx);
        goto after_0;
    // 0x800CF2E4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_0:
    // 0x800CF2E8: bnel        $v0, $zero, L_800CF400
    if (ctx->r2 != 0) {
        // 0x800CF2EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CF400;
    }
    goto skip_0;
    // 0x800CF2EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800CF2F0: jal         0x800CEAA8
    // 0x800CF2F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CEAA8(rdram, ctx);
        goto after_1;
    // 0x800CF2F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800CF2F8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800CF2FC: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x800CF300: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CF304: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800CF308: jal         0x800CF67C
    // 0x800CF30C: sh          $t6, -0x4EA0($at)
    MEM_H(-0X4EA0, ctx->r1) = ctx->r14;
    func_800CF67C(rdram, ctx);
        goto after_2;
    // 0x800CF30C: sh          $t6, -0x4EA0($at)
    MEM_H(-0X4EA0, ctx->r1) = ctx->r14;
    after_2:
    // 0x800CF310: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800CF314: jal         0x800CEF00
    // 0x800CF318: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800CEF00(rdram, ctx);
        goto after_3;
    // 0x800CF318: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x800CF31C: jal         0x800CF6D0
    // 0x800CF320: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_800CF6D0(rdram, ctx);
        goto after_4;
    // 0x800CF320: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x800CF324: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CF328: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800CF32C: jal         0x800CE8D8
    // 0x800CF330: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800CE8D8(rdram, ctx);
        goto after_5;
    // 0x800CF330: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
    // 0x800CF334: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800CF338: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800CF33C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CF340: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CF344: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800CF348: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800CF34C: jal         0x800CE980
    // 0x800CF350: nop

    func_800CE980(rdram, ctx);
        goto after_6;
    // 0x800CF350: nop

    after_6:
    // 0x800CF354: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CF358: addiu       $a1, $a1, -0x8CC
    ctx->r5 = ADD32(ctx->r5, -0X8CC);
    // 0x800CF35C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CF360: jal         0x800CE928
    // 0x800CF364: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800CE928(rdram, ctx);
        goto after_7;
    // 0x800CF364: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x800CF368: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CF36C: jal         0x800CE88C
    // 0x800CF370: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_8;
    // 0x800CF370: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x800CF374: jal         0x800F54E4
    // 0x800CF378: nop

    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x800CF378: nop

    after_9:
    // 0x800CF37C: jal         0x800F6604
    // 0x800CF380: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6604(rdram, ctx);
        goto after_10;
    // 0x800CF380: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_10:
    // 0x800CF384: beq         $v0, $zero, L_800CF3C8
    if (ctx->r2 == 0) {
        // 0x800CF388: nop
    
            goto L_800CF3C8;
    }
    // 0x800CF388: nop

    // 0x800CF38C: jal         0x800CEF48
    // 0x800CF390: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800CEF48(rdram, ctx);
        goto after_11;
    // 0x800CF390: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_11:
    // 0x800CF394: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800CF398: nop

    // 0x800CF39C: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x800CF3A0: nop

    // 0x800CF3A4: bc1fl       L_800CF400
    if (!c1cs) {
        // 0x800CF3A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CF400;
    }
    goto skip_1;
    // 0x800CF3A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800CF3AC: jal         0x800F54E4
    // 0x800CF3B0: nop

    func_800F54E4(rdram, ctx);
        goto after_12;
    // 0x800CF3B0: nop

    after_12:
    // 0x800CF3B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CF3B8: jal         0x800F7B9C
    // 0x800CF3BC: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    func_800F7B9C(rdram, ctx);
        goto after_13;
    // 0x800CF3BC: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    after_13:
    // 0x800CF3C0: b           L_800CF400
    // 0x800CF3C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800CF400;
    // 0x800CF3C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CF3C8:
    // 0x800CF3C8: jal         0x800CEF48
    // 0x800CF3CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800CEF48(rdram, ctx);
        goto after_14;
    // 0x800CF3CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_14:
    // 0x800CF3D0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800CF3D4: nop

    // 0x800CF3D8: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x800CF3DC: nop

    // 0x800CF3E0: bc1tl       L_800CF400
    if (c1cs) {
        // 0x800CF3E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CF400;
    }
    goto skip_2;
    // 0x800CF3E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800CF3E8: jal         0x800F54E4
    // 0x800CF3EC: nop

    func_800F54E4(rdram, ctx);
        goto after_15;
    // 0x800CF3EC: nop

    after_15:
    // 0x800CF3F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CF3F4: jal         0x800F7B9C
    // 0x800CF3F8: addiu       $a1, $zero, 0x56
    ctx->r5 = ADD32(0, 0X56);
    func_800F7B9C(rdram, ctx);
        goto after_16;
    // 0x800CF3F8: addiu       $a1, $zero, 0x56
    ctx->r5 = ADD32(0, 0X56);
    after_16:
    // 0x800CF3FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CF400:
    // 0x800CF400: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CF404: jr          $ra
    // 0x800CF408: nop

    return;
    // 0x800CF408: nop

;}
RECOMP_FUNC void plcamera_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808004C4: jal         0x800F5EF8
    // 0x808004C8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800F5EF8(rdram, ctx);
        goto after_0;
    // 0x808004C8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808004CC: jal         0x80110014
    // 0x808004D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110014(rdram, ctx);
        goto after_1;
    // 0x808004D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808004D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004D8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808004DC: jal         0x80110848
    // 0x808004E0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_80110848(rdram, ctx);
        goto after_2;
    // 0x808004E0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808004E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004EC: jr          $ra
    // 0x808004F0: nop

    return;
    // 0x808004F0: nop

    // 0x808004F4: nop

    // 0x808004F8: nop

    // 0x808004FC: nop

;}
RECOMP_FUNC void func_80800824_chfiregen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800824: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80800828: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x8080082C: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x80800830: addiu       $t9, $t8, -0x1AA
    ctx->r25 = ADD32(ctx->r24, -0X1AA);
    // 0x80800834: sltiu       $at, $t9, 0xB
    ctx->r1 = ctx->r25 < 0XB ? 1 : 0;
    // 0x80800838: beq         $at, $zero, L_80800884
    if (ctx->r1 == 0) {
        // 0x8080083C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80800884;
    }
    // 0x8080083C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800840: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X14B0) << 16);
    // 0x80800844: addu        $at, $at, $t9
    gpr jr_addend_8080084C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800848: lw          $t9, 0x14B0($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1588, 0X14B0));
    // 0x8080084C: jr          $t9
    // 0x80800850: nop

    switch (jr_addend_8080084C >> 2) {
        case 0: goto L_80800854; break;
        case 1: goto L_80800884; break;
        case 2: goto L_8080085C; break;
        case 3: goto L_80800884; break;
        case 4: goto L_80800864; break;
        case 5: goto L_80800884; break;
        case 6: goto L_8080086C; break;
        case 7: goto L_80800884; break;
        case 8: goto L_80800874; break;
        case 9: goto L_80800884; break;
        case 10: goto L_8080087C; break;
        default: switch_error(__func__, 0x8080084C, 0x808014B0);
    }
    // 0x80800850: nop

L_80800854:
    // 0x80800854: jr          $ra
    // 0x80800858: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800858: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080085C:
    // 0x8080085C: jr          $ra
    // 0x80800860: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800860: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800864:
    // 0x80800864: jr          $ra
    // 0x80800868: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80800868: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8080086C:
    // 0x8080086C: jr          $ra
    // 0x80800870: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x80800870: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800874:
    // 0x80800874: jr          $ra
    // 0x80800878: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80800878: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8080087C:
    // 0x8080087C: jr          $ra
    // 0x80800880: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x80800880: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80800884:
    // 0x80800884: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800888: jr          $ra
    // 0x8080088C: nop

    return;
    // 0x8080088C: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_33(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808012B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012B8: jal         0x80800060
    // 0x808012BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800060_bsstonehead(rdram, ctx);
        goto after_0;
    // 0x808012BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808012C0: jal         0x800839C8
    // 0x808012C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x808012C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808012C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808012CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808012D0: jr          $ra
    // 0x808012D4: nop

    return;
    // 0x808012D4: nop

;}
RECOMP_FUNC void func_80800224_suspline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800224: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800228: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080022C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800230: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800234: lh          $v1, 0x78($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X78);
    // 0x80800238: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8080023C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800240: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80800244: bne         $at, $zero, L_808004DC
    if (ctx->r1 != 0) {
        // 0x80800248: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_808004DC;
    }
    // 0x80800248: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8080024C: lbu         $t6, 0x8A($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X8A);
    // 0x80800250: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x80800254: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x80800258: beql        $t7, $zero, L_80800284
    if (ctx->r15 == 0) {
        // 0x8080025C: mtc1        $t0, $f6
        ctx->f6.u32l = ctx->r8;
            goto L_80800284;
    }
    goto skip_0;
    // 0x8080025C: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    skip_0:
    // 0x80800260: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x80800264: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80800268: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080026C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80800270: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800274: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80800278: b           L_808002A0
    // 0x8080027C: sh          $t9, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r25;
        goto L_808002A0;
    // 0x8080027C: sh          $t9, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r25;
    // 0x80800280: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
L_80800284:
    // 0x80800284: lwc1        $f18, 0x0($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80800288: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080028C: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800290: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800294: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80800298: nop

    // 0x8080029C: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
L_808002A0:
    // 0x808002A0: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x808002A4: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x808002A8: sh          $t4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r12;
    // 0x808002AC: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x808002B0: sh          $t3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r11;
    // 0x808002B4: lh          $v1, 0x78($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X78);
    // 0x808002B8: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    // 0x808002BC: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x808002C0: bnel        $at, $zero, L_808002F8
    if (ctx->r1 != 0) {
        // 0x808002C4: addiu       $t9, $a0, 0x1
        ctx->r25 = ADD32(ctx->r4, 0X1);
            goto L_808002F8;
    }
    goto skip_1;
    // 0x808002C4: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    skip_1:
    // 0x808002C8: lbu         $t5, 0x8A($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X8A);
    // 0x808002CC: subu        $t7, $a0, $v1
    ctx->r15 = SUB32(ctx->r4, ctx->r3);
    // 0x808002D0: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x808002D4: andi        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 & 0X2;
    // 0x808002D8: beql        $t6, $zero, L_808002F0
    if (ctx->r14 == 0) {
        // 0x808002DC: sh          $t8, 0x4($s0)
        MEM_H(0X4, ctx->r16) = ctx->r24;
            goto L_808002F0;
    }
    goto skip_2;
    // 0x808002DC: sh          $t8, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r24;
    skip_2:
    // 0x808002E0: sh          $t7, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r15;
    // 0x808002E4: b           L_808002F4
    // 0x808002E8: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
        goto L_808002F4;
    // 0x808002E8: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    // 0x808002EC: sh          $t8, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r24;
L_808002F0:
    // 0x808002F0: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
L_808002F4:
    // 0x808002F4: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
L_808002F8:
    // 0x808002F8: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
    // 0x808002FC: lh          $v1, 0x78($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X78);
    // 0x80800300: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    // 0x80800304: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800308: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8080030C: bnel        $at, $zero, L_8080033C
    if (ctx->r1 != 0) {
        // 0x80800310: lh          $v0, 0x0($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X0);
            goto L_8080033C;
    }
    goto skip_3;
    // 0x80800310: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    skip_3:
    // 0x80800314: lbu         $t0, 0x8A($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X8A);
    // 0x80800318: subu        $t2, $v0, $v1
    ctx->r10 = SUB32(ctx->r2, ctx->r3);
    // 0x8080031C: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x80800320: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x80800324: beql        $t1, $zero, L_80800338
    if (ctx->r9 == 0) {
        // 0x80800328: sh          $t3, 0x6($s0)
        MEM_H(0X6, ctx->r16) = ctx->r11;
            goto L_80800338;
    }
    goto skip_4;
    // 0x80800328: sh          $t3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r11;
    skip_4:
    // 0x8080032C: b           L_80800338
    // 0x80800330: sh          $t2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r10;
        goto L_80800338;
    // 0x80800330: sh          $t2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r10;
    // 0x80800334: sh          $t3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r11;
L_80800338:
    // 0x80800338: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
L_8080033C:
    // 0x8080033C: bgezl       $v0, L_8080036C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80800340: lh          $a1, 0x2($s0)
        ctx->r5 = MEM_H(ctx->r16, 0X2);
            goto L_8080036C;
    }
    goto skip_5;
    // 0x80800340: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    skip_5:
    // 0x80800344: lbu         $t4, 0x8A($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X8A);
    // 0x80800348: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x8080034C: beql        $t5, $zero, L_80800368
    if (ctx->r13 == 0) {
        // 0x80800350: sh          $zero, 0x0($s0)
        MEM_H(0X0, ctx->r16) = 0;
            goto L_80800368;
    }
    goto skip_6;
    // 0x80800350: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    skip_6:
    // 0x80800354: lh          $t6, 0x78($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X78);
    // 0x80800358: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8080035C: b           L_80800368
    // 0x80800360: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
        goto L_80800368;
    // 0x80800360: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x80800364: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_80800368:
    // 0x80800368: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
L_8080036C:
    // 0x8080036C: jal         0x80800074
    // 0x80800370: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_80800074_suspline(rdram, ctx);
        goto after_0;
    // 0x80800370: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800374: beq         $v0, $zero, L_808003E8
    if (ctx->r2 == 0) {
        // 0x80800378: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_808003E8;
    }
    // 0x80800378: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8080037C: lbu         $t8, 0x8A($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X8A);
    // 0x80800380: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800384: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x80800388: beql        $t9, $zero, L_808003BC
    if (ctx->r25 == 0) {
        // 0x8080038C: lh          $t3, 0x2($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X2);
            goto L_808003BC;
    }
    goto skip_7;
    // 0x8080038C: lh          $t3, 0x2($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2);
    skip_7:
    // 0x80800390: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x80800394: lh          $t2, 0x78($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X78);
    // 0x80800398: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8080039C: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x808003A0: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x808003A4: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808003A8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808003AC: div.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x808003B0: b           L_808003E0
    // 0x808003B4: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
        goto L_808003E0;
    // 0x808003B4: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x808003B8: lh          $t3, 0x2($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2);
L_808003BC:
    // 0x808003BC: lh          $t5, 0x78($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X78);
    // 0x808003C0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x808003C4: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x808003C8: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x808003CC: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x808003D0: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808003D4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808003D8: div.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x808003DC: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
L_808003E0:
    // 0x808003E0: b           L_808003EC
    // 0x808003E4: sb          $t7, 0x8B($s1)
    MEM_B(0X8B, ctx->r17) = ctx->r15;
        goto L_808003EC;
    // 0x808003E4: sb          $t7, 0x8B($s1)
    MEM_B(0X8B, ctx->r17) = ctx->r15;
L_808003E8:
    // 0x808003E8: sb          $zero, 0x8B($s1)
    MEM_B(0X8B, ctx->r17) = 0;
L_808003EC:
    // 0x808003EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003F0: jal         0x80800074
    // 0x808003F4: lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4);
    func_80800074_suspline(rdram, ctx);
        goto after_1;
    // 0x808003F4: lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4);
    after_1:
    // 0x808003F8: beq         $v0, $zero, L_80800408
    if (ctx->r2 == 0) {
        // 0x808003FC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800408;
    }
    // 0x808003FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800400: lh          $t8, 0x4($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X4);
    // 0x80800404: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
L_80800408:
    // 0x80800408: jal         0x80800074
    // 0x8080040C: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    func_80800074_suspline(rdram, ctx);
        goto after_2;
    // 0x8080040C: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    after_2:
    // 0x80800410: beq         $v0, $zero, L_80800420
    if (ctx->r2 == 0) {
        // 0x80800414: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_80800420;
    }
    // 0x80800414: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800418: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x8080041C: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
L_80800420:
    // 0x80800420: lbu         $t0, 0x8A($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X8A);
    // 0x80800424: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x80800428: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x8080042C: beq         $t1, $zero, L_80800484
    if (ctx->r9 == 0) {
        // 0x80800430: addiu       $t3, $v0, 0x1
        ctx->r11 = ADD32(ctx->r2, 0X1);
            goto L_80800484;
    }
    // 0x80800430: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x80800434: lh          $t2, 0x78($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X78);
    // 0x80800438: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8080043C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80800440: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80800444: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800448: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3202, 0XEA4) << 16);
    // 0x8080044C: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800450: lui         $a3, 0x3EAA
    ctx->r7 = S32(0X3EAA << 16);
    // 0x80800454: ori         $a3, $a3, 0x7EFA
    ctx->r7 = ctx->r7 | 0X7EFA;
    // 0x80800458: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080045C: lwc1        $f8, 0xEA4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3202, 0XEA4));
    // 0x80800460: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80800464: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800468: div.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8080046C: div.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800470: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80800474: jal         0x800F10B4
    // 0x80800478: nop

    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80800478: nop

    after_3:
    // 0x8080047C: b           L_808004E8
    // 0x80800480: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004E8;
    // 0x80800480: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800484:
    // 0x80800484: lh          $t4, 0x78($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X78);
    // 0x80800488: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    // 0x8080048C: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x80800490: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80800494: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80800498: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8080049C: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808004A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3202, 0XEA8) << 16);
    // 0x808004A4: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    // 0x808004A8: lui         $a3, 0x3EAA
    ctx->r7 = S32(0X3EAA << 16);
    // 0x808004AC: ori         $a3, $a3, 0x7EFA
    ctx->r7 = ctx->r7 | 0X7EFA;
    // 0x808004B0: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808004B4: lwc1        $f10, 0xEA8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3202, 0XEA8));
    // 0x808004B8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x808004BC: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808004C0: div.s       $f14, $f16, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x808004C4: div.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x808004C8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808004CC: jal         0x800F10B4
    // 0x808004D0: nop

    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x808004D0: nop

    after_4:
    // 0x808004D4: b           L_808004E8
    // 0x808004D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004E8;
    // 0x808004D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004DC:
    // 0x808004DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808004E0: nop

    // 0x808004E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004E8:
    // 0x808004E8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808004EC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808004F0: jr          $ra
    // 0x808004F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808004F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800CB70C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB70C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800CB710: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800CB714: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800CB718: addiu       $t7, $t7, -0x5490
    ctx->r15 = ADD32(ctx->r15, -0X5490);
    // 0x800CB71C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800CB720: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CB724: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800CB728: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB72C: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    // 0x800CB730: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x800CB734: jal         0x800EE7F8
    // 0x800CB738: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800CB738: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800CB73C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB744: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800CB748: lh          $t8, 0x18($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X18);
    // 0x800CB74C: lh          $t9, 0x1A($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X1A);
    // 0x800CB750: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CB754: swc1        $f4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f4.u32l;
    // 0x800CB758: sh          $t8, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r24;
    // 0x800CB75C: jr          $ra
    // 0x800CB760: sh          $t9, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r25;
    return;
    // 0x800CB760: sh          $t9, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void func_8080000C_chappearfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: jr          $ra
    // 0x80800010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8010A610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A610: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8010A614: lw          $v0, 0x28($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X28);
    // 0x8010A618: sll         $t7, $v0, 22
    ctx->r15 = S32(ctx->r2 << 22);
    // 0x8010A61C: jr          $ra
    // 0x8010A620: srl         $v0, $t7, 31
    ctx->r2 = S32(U32(ctx->r15) >> 31);
    return;
    // 0x8010A620: srl         $v0, $t7, 31
    ctx->r2 = S32(U32(ctx->r15) >> 31);
;}
RECOMP_FUNC void chweldarhead_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1404, 0X4F0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x4F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1404, 0X4F0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x4F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1404, 0X4F0));
;}
RECOMP_FUNC void func_80801040_chvolcanobits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801048: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080104C: jal         0x800BEA88
    // 0x80801050: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_0;
    // 0x80801050: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80801054: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80801058: beq         $v0, $zero, L_8080107C
    if (ctx->r2 == 0) {
        // 0x8080105C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8080107C;
    }
    // 0x8080105C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801060: lhu         $a1, 0x76($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X76);
    // 0x80801064: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80801068: addiu       $a2, $a2, 0x6418
    ctx->r6 = ADD32(ctx->r6, 0X6418);
    // 0x8080106C: srl         $t6, $a1, 7
    ctx->r14 = S32(U32(ctx->r5) >> 7);
    // 0x80801070: addiu       $a1, $t6, -0x31
    ctx->r5 = ADD32(ctx->r14, -0X31);
    // 0x80801074: jal         0x80088660
    // 0x80801078: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80801078: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    after_1:
L_8080107C:
    // 0x8080107C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801084: jr          $ra
    // 0x80801088: nop

    return;
    // 0x80801088: nop

;}
RECOMP_FUNC void func_80803524_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803524: sra         $t6, $a1, 3
    ctx->r14 = S32(SIGNED(ctx->r5) >> 3);
    // 0x80803528: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8080352C: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80803530: andi        $t9, $a1, 0x7
    ctx->r25 = ctx->r5 & 0X7;
    // 0x80803534: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80803538: sllv        $t1, $t0, $t9
    ctx->r9 = S32(ctx->r8 << (ctx->r25 & 31));
    // 0x8080353C: and         $t2, $t8, $t1
    ctx->r10 = ctx->r24 & ctx->r9;
    // 0x80803540: beq         $t2, $zero, L_80803550
    if (ctx->r10 == 0) {
        // 0x80803544: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80803550;
    }
    // 0x80803544: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80803548: jr          $ra
    // 0x8080354C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8080354C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803550:
    // 0x80803550: jr          $ra
    // 0x80803554: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80803554: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800A16BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A16BC: beq         $a0, $zero, L_800A16DC
    if (ctx->r4 == 0) {
        // 0x800A16C0: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800A16DC;
    }
    // 0x800A16C0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A16C4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A16C8: addiu       $v0, $v0, 0x7090
    ctx->r2 = ADD32(ctx->r2, 0X7090);
    // 0x800A16CC: lbu         $t6, 0x5($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X5);
    // 0x800A16D0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800A16D4: jr          $ra
    // 0x800A16D8: sb          $t7, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r15;
    return;
    // 0x800A16D8: sb          $t7, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r15;
L_800A16DC:
    // 0x800A16DC: addiu       $v0, $v0, 0x7090
    ctx->r2 = ADD32(ctx->r2, 0X7090);
    // 0x800A16E0: lbu         $t8, 0x5($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X5);
    // 0x800A16E4: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800A16E8: sb          $t9, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r25;
    // 0x800A16EC: jr          $ra
    // 0x800A16F0: nop

    return;
    // 0x800A16F0: nop

;}
RECOMP_FUNC void _gcdialogcamera_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088088: syscall     669
    recomp_syscall_handler(rdram, ctx, 0x80088088);
    return;
    // 0x8008808C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _plcamera_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087918: syscall     639
    recomp_syscall_handler(rdram, ctx, 0x80087918);
    return;
    // 0x8008791C: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_808005AC_chburgerstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005AC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808005B0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808005B4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808005B8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(936, 0XDDC) << 16);
    // 0x808005BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808005C0: jal         0x80101E4C
    // 0x808005C4: addiu       $a1, $a1, 0xDDC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(936, 0XDDC));
    func_80101E4C(rdram, ctx);
        goto after_0;
    // 0x808005C4: addiu       $a1, $a1, 0xDDC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(936, 0XDDC));
    after_0:
    // 0x808005C8: beq         $v0, $zero, L_808006A0
    if (ctx->r2 == 0) {
        // 0x808005CC: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_808006A0;
    }
    // 0x808005CC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808005D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808005D4: jal         0x8008A0E8
    // 0x808005D8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    _subaddieskeleton_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808005D8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x808005DC: beq         $v0, $zero, L_808006A0
    if (ctx->r2 == 0) {
        // 0x808005E0: lwc1        $f4, 0x38($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
            goto L_808006A0;
    }
    // 0x808005E0: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808005E4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808005E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005EC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(936, 0XDEC) << 16);
    // 0x808005F0: addiu       $t6, $t6, 0xDEC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(936, 0XDEC));
    // 0x808005F4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808005F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808005FC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800600: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800604: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x80800608: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x8080060C: jal         0x800BABB8
    // 0x80800610: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80800610: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_2:
    // 0x80800614: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800618: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8080061C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800620: lwc1        $f2, 0x48($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800624: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800628: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080062C: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80800630: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800634: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800638: add.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x8080063C: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800640: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
    // 0x80800644: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800648: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080064C: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x80800650: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800654: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800658: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8080065C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800660: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800664: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80800668: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8080066C: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x80800670: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80800674: sll         $t1, $a3, 16
    ctx->r9 = S32(ctx->r7 << 16);
    // 0x80800678: sra         $a3, $t1, 16
    ctx->r7 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8080067C: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80800680: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80800684: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800688: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8080068C: jal         0x800BA994
    // 0x80800690: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_800BA994(rdram, ctx);
        goto after_3;
    // 0x80800690: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_3:
    // 0x80800694: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800698: jal         0x800BA22C
    // 0x8080069C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800BA22C(rdram, ctx);
        goto after_4;
    // 0x8080069C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
L_808006A0:
    // 0x808006A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808006A4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808006A8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808006AC: jr          $ra
    // 0x808006B0: nop

    return;
    // 0x808006B0: nop

;}
RECOMP_FUNC void func_800F2EFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2EFC: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800F2F00: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800F2F04: lbu         $t7, 0x1($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1);
    // 0x800F2F08: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800F2F0C: lbu         $t8, 0x2($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2);
    // 0x800F2F10: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x800F2F14: lbu         $t9, 0x3($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X3);
    // 0x800F2F18: jr          $ra
    // 0x800F2F1C: sw          $t9, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r25;
    return;
    // 0x800F2F1C: sw          $t9, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void func_800B9B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9B50: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x800B9B54: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x800B9B58: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x800B9B5C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800B9B60: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800B9B64: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800B9B68: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800B9B6C: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800B9B70: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800B9B74: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800B9B78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B9B7C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800B9B80: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
L_800B9B84:
    // 0x800B9B84: lh          $a0, 0x34($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X34);
    // 0x800B9B88: jal         0x800DC128
    // 0x800B9B8C: lh          $a1, 0x3A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X3A);
    func_800DC128(rdram, ctx);
        goto after_0;
    // 0x800B9B8C: lh          $a1, 0x3A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X3A);
    after_0:
    // 0x800B9B90: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800B9B94: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x800B9B98: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800B9B9C: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x800B9BA0: bne         $at, $zero, L_800B9B84
    if (ctx->r1 != 0) {
        // 0x800B9BA4: sh          $v0, -0x2($s2)
        MEM_H(-0X2, ctx->r18) = ctx->r2;
            goto L_800B9B84;
    }
    // 0x800B9BA4: sh          $v0, -0x2($s2)
    MEM_H(-0X2, ctx->r18) = ctx->r2;
    // 0x800B9BA8: lhu         $t6, 0xA8($s4)
    ctx->r14 = MEM_HU(ctx->r20, 0XA8);
    // 0x800B9BAC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B9BB0: sb          $t6, 0x38($s5)
    MEM_B(0X38, ctx->r21) = ctx->r14;
    // 0x800B9BB4: lwc1        $f6, 0x18($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X18);
    // 0x800B9BB8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800B9BBC: nop

    // 0x800B9BC0: bc1f        L_800B9BD4
    if (!c1cs) {
        // 0x800B9BC4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800B9BD4;
    }
    // 0x800B9BC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B9BC8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B9BCC: b           L_800B9BE0
    // 0x800B9BD0: swc1        $f8, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->f8.u32l;
        goto L_800B9BE0;
    // 0x800B9BD0: swc1        $f8, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->f8.u32l;
L_800B9BD4:
    // 0x800B9BD4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B9BD8: nop

    // 0x800B9BDC: swc1        $f10, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->f10.u32l;
L_800B9BE0:
    // 0x800B9BE0: lh          $t7, 0x84($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X84);
    // 0x800B9BE4: lh          $t8, 0x86($s4)
    ctx->r24 = MEM_H(ctx->r20, 0X86);
    // 0x800B9BE8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800B9BEC: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800B9BF0: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B9BF4: jal         0x800DC178
    // 0x800B9BF8: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x800B9BF8: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    after_1:
    // 0x800B9BFC: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800B9C00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B9C04: nop

    // 0x800B9C08: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800B9C0C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800B9C10: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800B9C14: nop

    // 0x800B9C18: sh          $t0, 0x2C($s5)
    MEM_H(0X2C, ctx->r21) = ctx->r8;
    // 0x800B9C1C: lwc1        $f14, 0x7C($s4)
    ctx->f14.u32l = MEM_W(ctx->r20, 0X7C);
    // 0x800B9C20: jal         0x800DC178
    // 0x800B9C24: lwc1        $f12, 0x78($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X78);
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x800B9C24: lwc1        $f12, 0x78($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X78);
    after_2:
    // 0x800B9C28: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800B9C2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B9C30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B9C34: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800B9C38: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800B9C3C: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x800B9C40: nop

    // 0x800B9C44: sh          $t2, 0x2E($s5)
    MEM_H(0X2E, ctx->r21) = ctx->r10;
    // 0x800B9C48: lbu         $v1, 0x5($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X5);
    // 0x800B9C4C: beql        $v1, $zero, L_800B9C74
    if (ctx->r3 == 0) {
        // 0x800B9C50: lhu         $t3, 0x0($s4)
        ctx->r11 = MEM_HU(ctx->r20, 0X0);
            goto L_800B9C74;
    }
    goto skip_0;
    // 0x800B9C50: lhu         $t3, 0x0($s4)
    ctx->r11 = MEM_HU(ctx->r20, 0X0);
    skip_0:
    // 0x800B9C54: beq         $v1, $at, L_800B9D10
    if (ctx->r3 == ctx->r1) {
        // 0x800B9C58: addiu       $s0, $sp, 0x8C
        ctx->r16 = ADD32(ctx->r29, 0X8C);
            goto L_800B9D10;
    }
    // 0x800B9C58: addiu       $s0, $sp, 0x8C
    ctx->r16 = ADD32(ctx->r29, 0X8C);
    // 0x800B9C5C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B9C60: beq         $v1, $at, L_800B9D84
    if (ctx->r3 == ctx->r1) {
        // 0x800B9C64: addiu       $s0, $sp, 0x80
        ctx->r16 = ADD32(ctx->r29, 0X80);
            goto L_800B9D84;
    }
    // 0x800B9C64: addiu       $s0, $sp, 0x80
    ctx->r16 = ADD32(ctx->r29, 0X80);
    // 0x800B9C68: b           L_800B9DF4
    // 0x800B9C6C: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
        goto L_800B9DF4;
    // 0x800B9C6C: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x800B9C70: lhu         $t3, 0x0($s4)
    ctx->r11 = MEM_HU(ctx->r20, 0X0);
L_800B9C74:
    // 0x800B9C74: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800B9C78: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x800B9C7C: andi        $t4, $t3, 0x40
    ctx->r12 = ctx->r11 & 0X40;
    // 0x800B9C80: beq         $t4, $zero, L_800B9CDC
    if (ctx->r12 == 0) {
        // 0x800B9C84: or          $s2, $s5, $zero
        ctx->r18 = ctx->r21 | 0;
            goto L_800B9CDC;
    }
    // 0x800B9C84: or          $s2, $s5, $zero
    ctx->r18 = ctx->r21 | 0;
    // 0x800B9C88: addiu       $s0, $sp, 0xB0
    ctx->r16 = ADD32(ctx->r29, 0XB0);
    // 0x800B9C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B9C90: jal         0x800EE88C
    // 0x800B9C94: addiu       $a1, $s4, 0x28
    ctx->r5 = ADD32(ctx->r20, 0X28);
    func_800EE88C(rdram, ctx);
        goto after_3;
    // 0x800B9C94: addiu       $a1, $s4, 0x28
    ctx->r5 = ADD32(ctx->r20, 0X28);
    after_3:
    // 0x800B9C98: addiu       $s1, $sp, 0xA4
    ctx->r17 = ADD32(ctx->r29, 0XA4);
    // 0x800B9C9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800B9CA0: jal         0x800EE88C
    // 0x800B9CA4: addiu       $a1, $s4, 0x2E
    ctx->r5 = ADD32(ctx->r20, 0X2E);
    func_800EE88C(rdram, ctx);
        goto after_4;
    // 0x800B9CA4: addiu       $a1, $s4, 0x2E
    ctx->r5 = ADD32(ctx->r20, 0X2E);
    after_4:
    // 0x800B9CA8: jal         0x800DC0C0
    // 0x800B9CAC: nop

    func_800DC0C0(rdram, ctx);
        goto after_5;
    // 0x800B9CAC: nop

    after_5:
    // 0x800B9CB0: addiu       $s2, $sp, 0x98
    ctx->r18 = ADD32(ctx->r29, 0X98);
    // 0x800B9CB4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800B9CB8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B9CBC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800B9CC0: jal         0x800EFE50
    // 0x800B9CC4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800EFE50(rdram, ctx);
        goto after_6;
    // 0x800B9CC4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_6:
    // 0x800B9CC8: addiu       $a0, $s5, 0x6
    ctx->r4 = ADD32(ctx->r21, 0X6);
    // 0x800B9CCC: jal         0x800EE940
    // 0x800B9CD0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EE940(rdram, ctx);
        goto after_7;
    // 0x800B9CD0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x800B9CD4: b           L_800B9DF4
    // 0x800B9CD8: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
        goto L_800B9DF4;
    // 0x800B9CD8: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
L_800B9CDC:
    // 0x800B9CDC: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
L_800B9CE0:
    // 0x800B9CE0: lh          $a0, 0x28($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X28);
    // 0x800B9CE4: jal         0x800DC128
    // 0x800B9CE8: lh          $a1, 0x2E($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2E);
    func_800DC128(rdram, ctx);
        goto after_8;
    // 0x800B9CE8: lh          $a1, 0x2E($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2E);
    after_8:
    // 0x800B9CEC: lh          $t5, 0x12($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X12);
    // 0x800B9CF0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800B9CF4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800B9CF8: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x800B9CFC: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x800B9D00: bne         $s1, $s3, L_800B9CE0
    if (ctx->r17 != ctx->r19) {
        // 0x800B9D04: sh          $t6, 0x4($s2)
        MEM_H(0X4, ctx->r18) = ctx->r14;
            goto L_800B9CE0;
    }
    // 0x800B9D04: sh          $t6, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r14;
    // 0x800B9D08: b           L_800B9DF8
    // 0x800B9D0C: lh          $a0, 0x9A($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X9A);
        goto L_800B9DF8;
    // 0x800B9D0C: lh          $a0, 0x9A($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X9A);
L_800B9D10:
    // 0x800B9D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B9D14: jal         0x800EE88C
    // 0x800B9D18: addiu       $a1, $s4, 0x12
    ctx->r5 = ADD32(ctx->r20, 0X12);
    func_800EE88C(rdram, ctx);
        goto after_9;
    // 0x800B9D18: addiu       $a1, $s4, 0x12
    ctx->r5 = ADD32(ctx->r20, 0X12);
    after_9:
    // 0x800B9D1C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800B9D20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B9D24: jal         0x800DC178
    // 0x800B9D28: lwc1        $f14, 0x56C0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X56C0);
    func_800DC178(rdram, ctx);
        goto after_10;
    // 0x800B9D28: lwc1        $f14, 0x56C0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X56C0);
    after_10:
    // 0x800B9D2C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800B9D30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B9D34: lwc1        $f14, 0x56C4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X56C4);
    // 0x800B9D38: jal         0x800DC178
    // 0x800B9D3C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_11;
    // 0x800B9D3C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    after_11:
    // 0x800B9D40: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x800B9D44: lh          $a1, 0x2A($s4)
    ctx->r5 = MEM_H(ctx->r20, 0X2A);
    // 0x800B9D48: jal         0x800DC128
    // 0x800B9D4C: lh          $a0, 0x28($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X28);
    func_800DC128(rdram, ctx);
        goto after_12;
    // 0x800B9D4C: lh          $a0, 0x28($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X28);
    after_12:
    // 0x800B9D50: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800B9D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B9D58: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x800B9D5C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B9D60: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x800B9D64: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800B9D68: jal         0x800EF214
    // 0x800B9D6C: nop

    func_800EF214(rdram, ctx);
        goto after_13;
    // 0x800B9D6C: nop

    after_13:
    // 0x800B9D70: addiu       $a0, $s5, 0x6
    ctx->r4 = ADD32(ctx->r21, 0X6);
    // 0x800B9D74: jal         0x800EE940
    // 0x800B9D78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE940(rdram, ctx);
        goto after_14;
    // 0x800B9D78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_14:
    // 0x800B9D7C: b           L_800B9DF4
    // 0x800B9D80: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
        goto L_800B9DF4;
    // 0x800B9D80: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
L_800B9D84:
    // 0x800B9D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B9D88: jal         0x800EE88C
    // 0x800B9D8C: addiu       $a1, $s4, 0x12
    ctx->r5 = ADD32(ctx->r20, 0X12);
    func_800EE88C(rdram, ctx);
        goto after_15;
    // 0x800B9D8C: addiu       $a1, $s4, 0x12
    ctx->r5 = ADD32(ctx->r20, 0X12);
    after_15:
    // 0x800B9D90: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800B9D94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B9D98: jal         0x800DC178
    // 0x800B9D9C: lwc1        $f14, 0x56C8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X56C8);
    func_800DC178(rdram, ctx);
        goto after_16;
    // 0x800B9D9C: lwc1        $f14, 0x56C8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X56C8);
    after_16:
    // 0x800B9DA0: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x800B9DA4: lh          $a1, 0x2A($s4)
    ctx->r5 = MEM_H(ctx->r20, 0X2A);
    // 0x800B9DA8: jal         0x800DC128
    // 0x800B9DAC: lh          $a0, 0x28($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X28);
    func_800DC128(rdram, ctx);
        goto after_17;
    // 0x800B9DAC: lh          $a0, 0x28($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X28);
    after_17:
    // 0x800B9DB0: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800B9DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B9DB8: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x800B9DBC: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B9DC0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800B9DC4: jal         0x800EF1B8
    // 0x800B9DC8: nop

    func_800EF1B8(rdram, ctx);
        goto after_18;
    // 0x800B9DC8: nop

    after_18:
    // 0x800B9DCC: addiu       $a0, $s5, 0x6
    ctx->r4 = ADD32(ctx->r21, 0X6);
    // 0x800B9DD0: jal         0x800EE940
    // 0x800B9DD4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE940(rdram, ctx);
        goto after_19;
    // 0x800B9DD4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_19:
    // 0x800B9DD8: lh          $a0, 0x2E($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X2E);
    // 0x800B9DDC: jal         0x800DC128
    // 0x800B9DE0: lh          $a1, 0x2C($s4)
    ctx->r5 = MEM_H(ctx->r20, 0X2C);
    func_800DC128(rdram, ctx);
        goto after_20;
    // 0x800B9DE0: lh          $a1, 0x2C($s4)
    ctx->r5 = MEM_H(ctx->r20, 0X2C);
    after_20:
    // 0x800B9DE4: lh          $t7, 0x8($s5)
    ctx->r15 = MEM_H(ctx->r21, 0X8);
    // 0x800B9DE8: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x800B9DEC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800B9DF0: sh          $t8, 0x8($s5)
    MEM_H(0X8, ctx->r21) = ctx->r24;
L_800B9DF4:
    // 0x800B9DF4: lh          $a0, 0x9A($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X9A);
L_800B9DF8:
    // 0x800B9DF8: jal         0x800DC128
    // 0x800B9DFC: lh          $a1, 0x9C($s4)
    ctx->r5 = MEM_H(ctx->r20, 0X9C);
    func_800DC128(rdram, ctx);
        goto after_21;
    // 0x800B9DFC: lh          $a1, 0x9C($s4)
    ctx->r5 = MEM_H(ctx->r20, 0X9C);
    after_21:
    // 0x800B9E00: sh          $v0, 0x30($s5)
    MEM_H(0X30, ctx->r21) = ctx->r2;
    // 0x800B9E04: lh          $t9, 0x30($s5)
    ctx->r25 = MEM_H(ctx->r21, 0X30);
    // 0x800B9E08: sh          $t9, 0x32($s5)
    MEM_H(0X32, ctx->r21) = ctx->r25;
    // 0x800B9E0C: lh          $a0, 0x9E($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X9E);
    // 0x800B9E10: bne         $a0, $zero, L_800B9E2C
    if (ctx->r4 != 0) {
        // 0x800B9E14: nop
    
            goto L_800B9E2C;
    }
    // 0x800B9E14: nop

    // 0x800B9E18: lh          $t0, 0xA0($s4)
    ctx->r8 = MEM_H(ctx->r20, 0XA0);
    // 0x800B9E1C: bne         $t0, $zero, L_800B9E2C
    if (ctx->r8 != 0) {
        // 0x800B9E20: nop
    
            goto L_800B9E2C;
    }
    // 0x800B9E20: nop

    // 0x800B9E24: b           L_800B9E40
    // 0x800B9E28: sh          $zero, 0x34($s5)
    MEM_H(0X34, ctx->r21) = 0;
        goto L_800B9E40;
    // 0x800B9E28: sh          $zero, 0x34($s5)
    MEM_H(0X34, ctx->r21) = 0;
L_800B9E2C:
    // 0x800B9E2C: jal         0x800DC128
    // 0x800B9E30: lh          $a1, 0xA0($s4)
    ctx->r5 = MEM_H(ctx->r20, 0XA0);
    func_800DC128(rdram, ctx);
        goto after_22;
    // 0x800B9E30: lh          $a1, 0xA0($s4)
    ctx->r5 = MEM_H(ctx->r20, 0XA0);
    after_22:
    // 0x800B9E34: lh          $t1, 0x32($s5)
    ctx->r9 = MEM_H(ctx->r21, 0X32);
    // 0x800B9E38: subu        $t2, $v0, $t1
    ctx->r10 = SUB32(ctx->r2, ctx->r9);
    // 0x800B9E3C: sh          $t2, 0x34($s5)
    MEM_H(0X34, ctx->r21) = ctx->r10;
L_800B9E40:
    // 0x800B9E40: lhu         $t3, 0x0($s4)
    ctx->r11 = MEM_HU(ctx->r20, 0X0);
    // 0x800B9E44: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800B9E48: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    // 0x800B9E4C: andi        $t4, $t3, 0x400
    ctx->r12 = ctx->r11 & 0X400;
    // 0x800B9E50: beq         $t4, $zero, L_800B9E80
    if (ctx->r12 == 0) {
        // 0x800B9E54: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_800B9E80;
    }
L_800B9E54:
    // 0x800B9E54: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800B9E58: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800B9E5C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800B9E60: jal         0x800DC178
    // 0x800B9E64: nop

    func_800DC178(rdram, ctx);
        goto after_23;
    // 0x800B9E64: nop

    after_23:
    // 0x800B9E68: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800B9E6C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800B9E70: bne         $s1, $s3, L_800B9E54
    if (ctx->r17 != ctx->r19) {
        // 0x800B9E74: swc1        $f0, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
            goto L_800B9E54;
    }
    // 0x800B9E74: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x800B9E78: b           L_800B9EC0
    // 0x800B9E7C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_800B9EC0;
    // 0x800B9E7C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800B9E80:
    // 0x800B9E80: lh          $t5, 0x4C($s4)
    ctx->r13 = MEM_H(ctx->r20, 0X4C);
    // 0x800B9E84: lh          $t6, 0x4E($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X4E);
    // 0x800B9E88: lh          $t7, 0x50($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X50);
    // 0x800B9E8C: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800B9E90: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800B9E94: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800B9E98: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B9E9C: addiu       $a0, $s5, 0x10
    ctx->r4 = ADD32(ctx->r21, 0X10);
    // 0x800B9EA0: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B9EA4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800B9EA8: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B9EAC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800B9EB0: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x800B9EB4: jal         0x800EFA4C
    // 0x800B9EB8: nop

    func_800EFA4C(rdram, ctx);
        goto after_24;
    // 0x800B9EB8: nop

    after_24:
    // 0x800B9EBC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800B9EC0:
    // 0x800B9EC0: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x800B9EC4: or          $s2, $s5, $zero
    ctx->r18 = ctx->r21 | 0;
L_800B9EC8:
    // 0x800B9EC8: lh          $a0, 0x40($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X40);
    // 0x800B9ECC: jal         0x800DC128
    // 0x800B9ED0: lh          $a1, 0x46($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X46);
    func_800DC128(rdram, ctx);
        goto after_25;
    // 0x800B9ED0: lh          $a1, 0x46($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X46);
    after_25:
    // 0x800B9ED4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800B9ED8: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x800B9EDC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800B9EE0: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x800B9EE4: bne         $at, $zero, L_800B9EC8
    if (ctx->r1 != 0) {
        // 0x800B9EE8: sh          $v0, 0x1E($s2)
        MEM_H(0X1E, ctx->r18) = ctx->r2;
            goto L_800B9EC8;
    }
    // 0x800B9EE8: sh          $v0, 0x1E($s2)
    MEM_H(0X1E, ctx->r18) = ctx->r2;
    // 0x800B9EEC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B9EF0: nop

    // 0x800B9EF4: swc1        $f18, 0x1C($s5)
    MEM_W(0X1C, ctx->r21) = ctx->f18.u32l;
    // 0x800B9EF8: lh          $a1, 0xA4($s4)
    ctx->r5 = MEM_H(ctx->r20, 0XA4);
    // 0x800B9EFC: jal         0x800DC128
    // 0x800B9F00: lh          $a0, 0xA2($s4)
    ctx->r4 = MEM_H(ctx->r20, 0XA2);
    func_800DC128(rdram, ctx);
        goto after_26;
    // 0x800B9F00: lh          $a0, 0xA2($s4)
    ctx->r4 = MEM_H(ctx->r20, 0XA2);
    after_26:
    // 0x800B9F04: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x800B9F08: sh          $t8, 0x36($s5)
    MEM_H(0X36, ctx->r21) = ctx->r24;
    // 0x800B9F0C: lbu         $v1, 0x4($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X4);
    // 0x800B9F10: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800B9F14: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x800B9F18: beq         $v1, $zero, L_800B9F3C
    if (ctx->r3 == 0) {
        // 0x800B9F1C: or          $s2, $s5, $zero
        ctx->r18 = ctx->r21 | 0;
            goto L_800B9F3C;
    }
    // 0x800B9F1C: or          $s2, $s5, $zero
    ctx->r18 = ctx->r21 | 0;
    // 0x800B9F20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B9F24: beq         $v1, $at, L_800B9F64
    if (ctx->r3 == ctx->r1) {
        // 0x800B9F28: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800B9F64;
    }
    // 0x800B9F28: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B9F2C: beq         $v1, $at, L_800BA018
    if (ctx->r3 == ctx->r1) {
        // 0x800B9F30: addiu       $a0, $s5, 0x6
        ctx->r4 = ADD32(ctx->r21, 0X6);
            goto L_800BA018;
    }
    // 0x800B9F30: addiu       $a0, $s5, 0x6
    ctx->r4 = ADD32(ctx->r21, 0X6);
    // 0x800B9F34: b           L_800BA144
    // 0x800B9F38: lbu         $t9, 0x39($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X39);
        goto L_800BA144;
    // 0x800B9F38: lbu         $t9, 0x39($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X39);
L_800B9F3C:
    // 0x800B9F3C: lh          $a0, 0xC4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XC4);
    // 0x800B9F40: jal         0x800DC128
    // 0x800B9F44: lh          $a1, 0xCA($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XCA);
    func_800DC128(rdram, ctx);
        goto after_27;
    // 0x800B9F44: lh          $a1, 0xCA($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XCA);
    after_27:
    // 0x800B9F48: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800B9F4C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800B9F50: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x800B9F54: bne         $s1, $s3, L_800B9F3C
    if (ctx->r17 != ctx->r19) {
        // 0x800B9F58: sh          $v0, 0x24($s2)
        MEM_H(0X24, ctx->r18) = ctx->r2;
            goto L_800B9F3C;
    }
    // 0x800B9F58: sh          $v0, 0x24($s2)
    MEM_H(0X24, ctx->r18) = ctx->r2;
    // 0x800B9F5C: b           L_800BA144
    // 0x800B9F60: lbu         $t9, 0x39($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X39);
        goto L_800BA144;
    // 0x800B9F60: lbu         $t9, 0x39($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X39);
L_800B9F64:
    // 0x800B9F64: lh          $t9, 0xCA($s4)
    ctx->r25 = MEM_H(ctx->r20, 0XCA);
    // 0x800B9F68: lh          $t0, 0xC8($s4)
    ctx->r8 = MEM_H(ctx->r20, 0XC8);
    // 0x800B9F6C: jal         0x800F0E44
    // 0x800B9F70: subu        $a0, $t9, $t0
    ctx->r4 = SUB32(ctx->r25, ctx->r8);
    func_800F0E44(rdram, ctx);
        goto after_28;
    // 0x800B9F70: subu        $a0, $t9, $t0
    ctx->r4 = SUB32(ctx->r25, ctx->r8);
    after_28:
    // 0x800B9F74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B9F78: jal         0x800DC128
    // 0x800B9F7C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800DC128(rdram, ctx);
        goto after_29;
    // 0x800B9F7C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_29:
    // 0x800B9F80: lh          $t1, 0xC8($s4)
    ctx->r9 = MEM_H(ctx->r20, 0XC8);
    // 0x800B9F84: jal         0x800F0E44
    // 0x800B9F88: addu        $a0, $v0, $t1
    ctx->r4 = ADD32(ctx->r2, ctx->r9);
    func_800F0E44(rdram, ctx);
        goto after_30;
    // 0x800B9F88: addu        $a0, $v0, $t1
    ctx->r4 = ADD32(ctx->r2, ctx->r9);
    after_30:
    // 0x800B9F8C: lh          $t2, 0xC6($s4)
    ctx->r10 = MEM_H(ctx->r20, 0XC6);
    // 0x800B9F90: lh          $t3, 0xC4($s4)
    ctx->r11 = MEM_H(ctx->r20, 0XC4);
    // 0x800B9F94: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B9F98: jal         0x800F0E44
    // 0x800B9F9C: subu        $a0, $t2, $t3
    ctx->r4 = SUB32(ctx->r10, ctx->r11);
    func_800F0E44(rdram, ctx);
        goto after_31;
    // 0x800B9F9C: subu        $a0, $t2, $t3
    ctx->r4 = SUB32(ctx->r10, ctx->r11);
    after_31:
    // 0x800B9FA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B9FA4: jal         0x800DC128
    // 0x800B9FA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800DC128(rdram, ctx);
        goto after_32;
    // 0x800B9FA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_32:
    // 0x800B9FAC: lh          $t4, 0xC4($s4)
    ctx->r12 = MEM_H(ctx->r20, 0XC4);
    // 0x800B9FB0: jal         0x800F0E44
    // 0x800B9FB4: addu        $a0, $v0, $t4
    ctx->r4 = ADD32(ctx->r2, ctx->r12);
    func_800F0E44(rdram, ctx);
        goto after_33;
    // 0x800B9FB4: addu        $a0, $v0, $t4
    ctx->r4 = ADD32(ctx->r2, ctx->r12);
    after_33:
    // 0x800B9FB8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800B9FBC: lh          $a0, 0xCC($s4)
    ctx->r4 = MEM_H(ctx->r20, 0XCC);
    // 0x800B9FC0: jal         0x800DC128
    // 0x800B9FC4: lh          $a1, 0xCE($s4)
    ctx->r5 = MEM_H(ctx->r20, 0XCE);
    func_800DC128(rdram, ctx);
        goto after_34;
    // 0x800B9FC4: lh          $a1, 0xCE($s4)
    ctx->r5 = MEM_H(ctx->r20, 0XCE);
    after_34:
    // 0x800B9FC8: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x800B9FCC: mtc1        $s1, $f6
    ctx->f6.u32l = ctx->r17;
    // 0x800B9FD0: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800B9FD4: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B9FD8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B9FDC: addiu       $s2, $sp, 0x74
    ctx->r18 = ADD32(ctx->r29, 0X74);
    // 0x800B9FE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B9FE4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800B9FE8: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B9FEC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800B9FF0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800B9FF4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B9FF8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800B9FFC: jal         0x800EF4E4
    // 0x800BA000: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800EF4E4(rdram, ctx);
        goto after_35;
    // 0x800BA000: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_35:
    // 0x800BA004: addiu       $a0, $s5, 0x26
    ctx->r4 = ADD32(ctx->r21, 0X26);
    // 0x800BA008: jal         0x800EE940
    // 0x800BA00C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EE940(rdram, ctx);
        goto after_36;
    // 0x800BA00C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_36:
    // 0x800BA010: b           L_800BA144
    // 0x800BA014: lbu         $t9, 0x39($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X39);
        goto L_800BA144;
    // 0x800BA014: lbu         $t9, 0x39($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X39);
L_800BA018:
    // 0x800BA018: jal         0x800EEDA0
    // 0x800BA01C: addiu       $a1, $s4, 0xC8
    ctx->r5 = ADD32(ctx->r20, 0XC8);
    func_800EEDA0(rdram, ctx);
        goto after_37;
    // 0x800BA01C: addiu       $a1, $s4, 0xC8
    ctx->r5 = ADD32(ctx->r20, 0XC8);
    after_37:
    // 0x800BA020: bnel        $v0, $zero, L_800BA128
    if (ctx->r2 != 0) {
        // 0x800BA024: sh          $zero, 0x2A($s5)
        MEM_H(0X2A, ctx->r21) = 0;
            goto L_800BA128;
    }
    goto skip_1;
    // 0x800BA024: sh          $zero, 0x2A($s5)
    MEM_H(0X2A, ctx->r21) = 0;
    skip_1:
    // 0x800BA028: lhu         $t5, 0x0($s4)
    ctx->r13 = MEM_HU(ctx->r20, 0X0);
    // 0x800BA02C: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x800BA030: beql        $t6, $zero, L_800BA094
    if (ctx->r14 == 0) {
        // 0x800BA034: lh          $t6, 0x6($s5)
        ctx->r14 = MEM_H(ctx->r21, 0X6);
            goto L_800BA094;
    }
    goto skip_2;
    // 0x800BA034: lh          $t6, 0x6($s5)
    ctx->r14 = MEM_H(ctx->r21, 0X6);
    skip_2:
    // 0x800BA038: lh          $t7, 0xC8($s4)
    ctx->r15 = MEM_H(ctx->r20, 0XC8);
    // 0x800BA03C: lh          $t8, 0x6($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X6);
    // 0x800BA040: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x800BA044: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800BA048: nop

    // 0x800BA04C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BA050: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    // 0x800BA054: lh          $t1, 0x8($s5)
    ctx->r9 = MEM_H(ctx->r21, 0X8);
    // 0x800BA058: lh          $t0, 0xCA($s4)
    ctx->r8 = MEM_H(ctx->r20, 0XCA);
    // 0x800BA05C: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x800BA060: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800BA064: nop

    // 0x800BA068: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BA06C: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x800BA070: lh          $t4, 0xA($s5)
    ctx->r12 = MEM_H(ctx->r21, 0XA);
    // 0x800BA074: lh          $t3, 0xCC($s4)
    ctx->r11 = MEM_H(ctx->r20, 0XCC);
    // 0x800BA078: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x800BA07C: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800BA080: nop

    // 0x800BA084: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BA088: b           L_800BA0E4
    // 0x800BA08C: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
        goto L_800BA0E4;
    // 0x800BA08C: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x800BA090: lh          $t6, 0x6($s5)
    ctx->r14 = MEM_H(ctx->r21, 0X6);
L_800BA094:
    // 0x800BA094: lh          $t7, 0xC8($s4)
    ctx->r15 = MEM_H(ctx->r20, 0XC8);
    // 0x800BA098: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800BA09C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800BA0A0: nop

    // 0x800BA0A4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BA0A8: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    // 0x800BA0AC: lh          $t0, 0xCA($s4)
    ctx->r8 = MEM_H(ctx->r20, 0XCA);
    // 0x800BA0B0: lh          $t9, 0x8($s5)
    ctx->r25 = MEM_H(ctx->r21, 0X8);
    // 0x800BA0B4: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x800BA0B8: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800BA0BC: nop

    // 0x800BA0C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BA0C4: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x800BA0C8: lh          $t3, 0xCC($s4)
    ctx->r11 = MEM_H(ctx->r20, 0XCC);
    // 0x800BA0CC: lh          $t2, 0xA($s5)
    ctx->r10 = MEM_H(ctx->r21, 0XA);
    // 0x800BA0D0: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x800BA0D4: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800BA0D8: nop

    // 0x800BA0DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BA0E0: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
L_800BA0E4:
    // 0x800BA0E4: lh          $t5, 0xC4($s4)
    ctx->r13 = MEM_H(ctx->r20, 0XC4);
    // 0x800BA0E8: lh          $t6, 0xC6($s4)
    ctx->r14 = MEM_H(ctx->r20, 0XC6);
    // 0x800BA0EC: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x800BA0F0: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800BA0F4: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BA0F8: jal         0x800DC178
    // 0x800BA0FC: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    func_800DC178(rdram, ctx);
        goto after_38;
    // 0x800BA0FC: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    after_38:
    // 0x800BA100: addiu       $s0, $sp, 0x68
    ctx->r16 = ADD32(ctx->r29, 0X68);
    // 0x800BA104: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800BA108: jal         0x800EF368
    // 0x800BA10C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EF368(rdram, ctx);
        goto after_39;
    // 0x800BA10C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x800BA110: addiu       $a0, $s5, 0x26
    ctx->r4 = ADD32(ctx->r21, 0X26);
    // 0x800BA114: jal         0x800EE940
    // 0x800BA118: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE940(rdram, ctx);
        goto after_40;
    // 0x800BA118: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_40:
    // 0x800BA11C: b           L_800BA144
    // 0x800BA120: lbu         $t9, 0x39($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X39);
        goto L_800BA144;
    // 0x800BA120: lbu         $t9, 0x39($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X39);
    // 0x800BA124: sh          $zero, 0x2A($s5)
    MEM_H(0X2A, ctx->r21) = 0;
L_800BA128:
    // 0x800BA128: lh          $t7, 0x2A($s5)
    ctx->r15 = MEM_H(ctx->r21, 0X2A);
    // 0x800BA12C: sh          $t7, 0x26($s5)
    MEM_H(0X26, ctx->r21) = ctx->r15;
    // 0x800BA130: lh          $a1, 0xC6($s4)
    ctx->r5 = MEM_H(ctx->r20, 0XC6);
    // 0x800BA134: jal         0x800DC128
    // 0x800BA138: lh          $a0, 0xC4($s4)
    ctx->r4 = MEM_H(ctx->r20, 0XC4);
    func_800DC128(rdram, ctx);
        goto after_41;
    // 0x800BA138: lh          $a0, 0xC4($s4)
    ctx->r4 = MEM_H(ctx->r20, 0XC4);
    after_41:
    // 0x800BA13C: sh          $v0, 0x28($s5)
    MEM_H(0X28, ctx->r21) = ctx->r2;
    // 0x800BA140: lbu         $t9, 0x39($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X39);
L_800BA144:
    // 0x800BA144: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x800BA148: sb          $t0, 0x39($s5)
    MEM_B(0X39, ctx->r21) = ctx->r8;
    // 0x800BA14C: lhu         $v0, 0x0($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X0);
    // 0x800BA150: andi        $t1, $v0, 0x8
    ctx->r9 = ctx->r2 & 0X8;
    // 0x800BA154: beql        $t1, $zero, L_800BA168
    if (ctx->r9 == 0) {
        // 0x800BA158: andi        $t2, $v0, 0x10
        ctx->r10 = ctx->r2 & 0X10;
            goto L_800BA168;
    }
    goto skip_3;
    // 0x800BA158: andi        $t2, $v0, 0x10
    ctx->r10 = ctx->r2 & 0X10;
    skip_3:
    // 0x800BA15C: sb          $zero, 0x52($s4)
    MEM_B(0X52, ctx->r20) = 0;
    // 0x800BA160: lhu         $v0, 0x0($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X0);
    // 0x800BA164: andi        $t2, $v0, 0x10
    ctx->r10 = ctx->r2 & 0X10;
L_800BA168:
    // 0x800BA168: beql        $t2, $zero, L_800BA178
    if (ctx->r10 == 0) {
        // 0x800BA16C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800BA178;
    }
    goto skip_4;
    // 0x800BA16C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_4:
    // 0x800BA170: sb          $zero, 0x53($s4)
    MEM_B(0X53, ctx->r20) = 0;
    // 0x800BA174: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800BA178:
    // 0x800BA178: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA17C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800BA180: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800BA184: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800BA188: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x800BA18C: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x800BA190: jr          $ra
    // 0x800BA194: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x800BA194: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void gczoombox_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803420: lbu         $t6, 0x177($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X177);
    // 0x80803424: andi        $t7, $t6, 0xEF
    ctx->r15 = ctx->r14 & 0XEF;
    // 0x80803428: jr          $ra
    // 0x8080342C: sb          $t7, 0x177($a0)
    MEM_B(0X177, ctx->r4) = ctx->r15;
    return;
    // 0x8080342C: sb          $t7, 0x177($a0)
    MEM_B(0X177, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_808000C8_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D0: lbu         $t6, 0x15E($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X15E);
    // 0x808000D4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808000D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000DC: bne         $t6, $zero, L_808000E8
    if (ctx->r14 != 0) {
        // 0x808000E0: nop
    
            goto L_808000E8;
    }
    // 0x808000E0: nop

    // 0x808000E4: sb          $zero, 0x160($a0)
    MEM_B(0X160, ctx->r4) = 0;
L_808000E8:
    // 0x808000E8: beq         $a1, $zero, L_80800108
    if (ctx->r5 == 0) {
        // 0x808000EC: sb          $a1, 0x15E($a3)
        MEM_B(0X15E, ctx->r7) = ctx->r5;
            goto L_80800108;
    }
    // 0x808000EC: sb          $a1, 0x15E($a3)
    MEM_B(0X15E, ctx->r7) = ctx->r5;
    // 0x808000F0: beq         $a1, $at, L_80800108
    if (ctx->r5 == ctx->r1) {
        // 0x808000F4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800108;
    }
    // 0x808000F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000F8: beq         $a1, $at, L_80800128
    if (ctx->r5 == ctx->r1) {
        // 0x808000FC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80800128;
    }
    // 0x808000FC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800100: b           L_80800148
    // 0x80800104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800148;
    // 0x80800104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800108:
    // 0x80800108: lbu         $a0, 0x160($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X160);
    // 0x8080010C: beql        $a0, $zero, L_80800148
    if (ctx->r4 == 0) {
        // 0x80800110: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800148;
    }
    goto skip_0;
    // 0x80800110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800114: jal         0x800C2FDC
    // 0x80800118: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800C2FDC(rdram, ctx);
        goto after_0;
    // 0x80800118: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080011C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800120: b           L_80800144
    // 0x80800124: sb          $zero, 0x160($a3)
    MEM_B(0X160, ctx->r7) = 0;
        goto L_80800144;
    // 0x80800124: sb          $zero, 0x160($a3)
    MEM_B(0X160, ctx->r7) = 0;
L_80800128:
    // 0x80800128: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(416, 0X1AF0) << 16);
    // 0x8080012C: addiu       $a2, $a2, 0x1AF0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(416, 0X1AF0));
    // 0x80800130: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800134: jal         0x8009D454
    // 0x80800138: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8009D454(rdram, ctx);
        goto after_1;
    // 0x80800138: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x8080013C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800140: sb          $v0, 0x160($a3)
    MEM_B(0X160, ctx->r7) = ctx->r2;
L_80800144:
    // 0x80800144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800148:
    // 0x80800148: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080014C: jr          $ra
    // 0x80800150: nop

    return;
    // 0x80800150: nop

;}
RECOMP_FUNC void func_80803610_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803610: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803614: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803618: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080361C: jal         0x800CEAA8
    // 0x80803620: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800CEAA8(rdram, ctx);
        goto after_0;
    // 0x80803620: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x80803624: beq         $v0, $zero, L_80803650
    if (ctx->r2 == 0) {
        // 0x80803628: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_80803650;
    }
    // 0x80803628: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8080362C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80803630: jal         0x800CE928
    // 0x80803634: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800CE928(rdram, ctx);
        goto after_1;
    // 0x80803634: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80803638: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8080363C: jal         0x800CE88C
    // 0x80803640: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CE88C(rdram, ctx);
        goto after_2;
    // 0x80803640: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80803644: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80803648: jal         0x800CEBD8
    // 0x8080364C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CEBD8(rdram, ctx);
        goto after_3;
    // 0x8080364C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
L_80803650:
    // 0x80803650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803654: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803658: jr          $ra
    // 0x8080365C: nop

    return;
    // 0x8080365C: nop

;}
RECOMP_FUNC void chfactorylobbydoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2212, 0X160) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x160
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2212, 0X160));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x160
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2212, 0X160));
;}
RECOMP_FUNC void func_801023E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801023E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801023E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801023EC: jal         0x80102394
    // 0x801023F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80102394(rdram, ctx);
        goto after_0;
    // 0x801023F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801023F4: bne         $v0, $zero, L_80102404
    if (ctx->r2 != 0) {
        // 0x801023F8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80102404;
    }
    // 0x801023F8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801023FC: b           L_80102414
    // 0x80102400: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80102414;
    // 0x80102400: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80102404:
    // 0x80102404: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80102408: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8010240C: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80102410: lhu         $v0, 0x6($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X6);
L_80102414:
    // 0x80102414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102418: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010241C: jr          $ra
    // 0x80102420: nop

    return;
    // 0x80102420: nop

;}
RECOMP_FUNC void func_80801B08_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801B0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801B10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801B14: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801B18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801B1C: jal         0x800DF744
    // 0x80801B20: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x80801B20: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80801B24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801B28: jal         0x80101870
    // 0x80801B2C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_1;
    // 0x80801B2C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80801B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801B34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801B38: jr          $ra
    // 0x80801B3C: nop

    return;
    // 0x80801B3C: nop

;}
RECOMP_FUNC void func_80092B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092B80: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80092B84: jr          $ra
    // 0x80092B88: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    return;
    // 0x80092B88: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
;}
RECOMP_FUNC void func_800A54C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A54C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A54C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A54C8: jal         0x8008FFE8
    // 0x800A54CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x800A54CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A54D0: jal         0x8011001C
    // 0x800A54D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8011001C(rdram, ctx);
        goto after_1;
    // 0x800A54D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800A54D8: beq         $v0, $zero, L_800A54E8
    if (ctx->r2 == 0) {
        // 0x800A54DC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800A54E8;
    }
    // 0x800A54DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A54E0: jal         0x800891E8
    // 0x800A54E4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    _ncfixposrot_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x800A54E4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_2:
L_800A54E8:
    // 0x800A54E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A54EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A54F0: jr          $ra
    // 0x800A54F4: nop

    return;
    // 0x800A54F4: nop

;}
RECOMP_FUNC void func_801174F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801174F4: addiu       $sp, $sp, -0x540
    ctx->r29 = ADD32(ctx->r29, -0X540);
    // 0x801174F8: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x801174FC: sltu        $at, $s5, $t0
    ctx->r1 = ctx->r21 < ctx->r8 ? 1 : 0;
    // 0x80117500: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80117504: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80117508: beq         $at, $zero, L_80117518
    if (ctx->r1 == 0) {
        // 0x8011750C: sw          $s0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r16;
            goto L_80117518;
    }
    // 0x8011750C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80117510: jal         0x80116F30
    // 0x80117514: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_80116F30(rdram, ctx);
        goto after_0;
    // 0x80117514: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_0:
L_80117518:
    // 0x80117518: sub         $s5, $s5, $t0
    ctx->r21 = SUB32(ctx->r21, ctx->r8);
    // 0x8011751C: andi        $s1, $s6, 0x1F
    ctx->r17 = ctx->r22 & 0X1F;
    // 0x80117520: sltu        $at, $s5, $t0
    ctx->r1 = ctx->r21 < ctx->r8 ? 1 : 0;
    // 0x80117524: addiu       $s1, $s1, 0x101
    ctx->r17 = ADD32(ctx->r17, 0X101);
    // 0x80117528: beq         $at, $zero, L_80117538
    if (ctx->r1 == 0) {
        // 0x8011752C: srlv        $s6, $s6, $t0
        ctx->r22 = S32(U32(ctx->r22) >> (ctx->r8 & 31));
            goto L_80117538;
    }
    // 0x8011752C: srlv        $s6, $s6, $t0
    ctx->r22 = S32(U32(ctx->r22) >> (ctx->r8 & 31));
    // 0x80117530: jal         0x80116F30
    // 0x80117534: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_80116F30(rdram, ctx);
        goto after_1;
    // 0x80117534: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_1:
L_80117538:
    // 0x80117538: andi        $s0, $s6, 0x1F
    ctx->r16 = ctx->r22 & 0X1F;
    // 0x8011753C: srlv        $s6, $s6, $t0
    ctx->r22 = S32(U32(ctx->r22) >> (ctx->r8 & 31));
    // 0x80117540: sub         $s5, $s5, $t0
    ctx->r21 = SUB32(ctx->r21, ctx->r8);
    // 0x80117544: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80117548: sltu        $at, $s5, $t0
    ctx->r1 = ctx->r21 < ctx->r8 ? 1 : 0;
    // 0x8011754C: beq         $at, $zero, L_8011755C
    if (ctx->r1 == 0) {
        // 0x80117550: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8011755C;
    }
    // 0x80117550: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80117554: jal         0x80116F30
    // 0x80117558: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_80116F30(rdram, ctx);
        goto after_2;
    // 0x80117558: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_2:
L_8011755C:
    // 0x8011755C: andi        $t2, $s6, 0xF
    ctx->r10 = ctx->r22 & 0XF;
    // 0x80117560: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x80117564: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80117568: srlv        $s6, $s6, $t0
    ctx->r22 = S32(U32(ctx->r22) >> (ctx->r8 & 31));
    // 0x8011756C: sub         $s5, $s5, $t0
    ctx->r21 = SUB32(ctx->r21, ctx->r8);
    // 0x80117570: or          $t1, $zero, $t2
    ctx->r9 = 0 | ctx->r10;
    // 0x80117574: addiu       $t9, $t9, 0x6640
    ctx->r25 = ADD32(ctx->r25, 0X6640);
    // 0x80117578: beq         $t2, $zero, L_801175CC
    if (ctx->r10 == 0) {
        // 0x8011757C: addi        $t7, $sp, 0x44
        ctx->r15 = ADD32(ctx->r29, 0X44);
            goto L_801175CC;
    }
    // 0x8011757C: addi        $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
L_80117580:
    // 0x80117580: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80117584: sltu        $at, $s5, $t0
    ctx->r1 = ctx->r21 < ctx->r8 ? 1 : 0;
    // 0x80117588: beql        $at, $zero, L_8011759C
    if (ctx->r1 == 0) {
        // 0x8011758C: lbu         $v1, 0x0($t9)
        ctx->r3 = MEM_BU(ctx->r25, 0X0);
            goto L_8011759C;
    }
    goto skip_0;
    // 0x8011758C: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    skip_0:
    // 0x80117590: jal         0x80116F30
    // 0x80117594: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_80116F30(rdram, ctx);
        goto after_3;
    // 0x80117594: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_3:
    // 0x80117598: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
L_8011759C:
    // 0x8011759C: andi        $v0, $s6, 0x7
    ctx->r2 = ctx->r22 & 0X7;
    // 0x801175A0: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x801175A4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x801175A8: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x801175AC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x801175B0: srlv        $s6, $s6, $t0
    ctx->r22 = S32(U32(ctx->r22) >> (ctx->r8 & 31));
    // 0x801175B4: sub         $s5, $s5, $t0
    ctx->r21 = SUB32(ctx->r21, ctx->r8);
    // 0x801175B8: bne         $t2, $zero, L_80117580
    if (ctx->r10 != 0) {
        // 0x801175BC: addiu       $t9, $t9, 0x1
        ctx->r25 = ADD32(ctx->r25, 0X1);
            goto L_80117580;
    }
    // 0x801175BC: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x801175C0: sltiu       $at, $t1, 0x13
    ctx->r1 = ctx->r9 < 0X13 ? 1 : 0;
    // 0x801175C4: beql        $at, $zero, L_801175F0
    if (ctx->r1 == 0) {
        // 0x801175C8: addiu       $t5, $zero, 0x7
        ctx->r13 = ADD32(0, 0X7);
            goto L_801175F0;
    }
    goto skip_1;
    // 0x801175C8: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    skip_1:
L_801175CC:
    // 0x801175CC: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x801175D0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x801175D4: slti        $at, $t1, 0x13
    ctx->r1 = SIGNED(ctx->r9) < 0X13 ? 1 : 0;
    // 0x801175D8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x801175DC: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x801175E0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801175E4: bne         $at, $zero, L_801175CC
    if (ctx->r1 != 0) {
        // 0x801175E8: addiu       $t9, $t9, 0x1
        ctx->r25 = ADD32(ctx->r25, 0X1);
            goto L_801175CC;
    }
    // 0x801175E8: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x801175EC: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
L_801175F0:
    // 0x801175F0: addi        $t0, $sp, 0x34
    ctx->r8 = ADD32(ctx->r29, 0X34);
    // 0x801175F4: addi        $t1, $sp, 0x38
    ctx->r9 = ADD32(ctx->r29, 0X38);
    // 0x801175F8: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x801175FC: addi        $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80117600: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x80117604: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x80117608: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8011760C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80117610: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80117614: jal         0x80116914
    // 0x80117618: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    func_80116914(rdram, ctx);
        goto after_4;
    // 0x80117618: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_4:
    // 0x8011761C: addi        $t1, $sp, 0x38
    ctx->r9 = ADD32(ctx->r29, 0X38);
    // 0x80117620: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x80117624: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80117628: addiu       $v0, $v0, 0x670C
    ctx->r2 = ADD32(ctx->r2, 0X670C);
    // 0x8011762C: sll         $v1, $t5, 1
    ctx->r3 = S32(ctx->r13 << 1);
    // 0x80117630: addi        $t0, $sp, 0x34
    ctx->r8 = ADD32(ctx->r29, 0X34);
    // 0x80117634: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80117638: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8011763C: add         $t9, $s1, $s0
    ctx->r25 = ADD32(ctx->r17, ctx->r16);
    // 0x80117640: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x80117644: addi        $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
    // 0x80117648: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
L_8011764C:
    // 0x8011764C: beq         $t9, $zero, L_8011777C
    if (ctx->r25 == 0) {
        // 0x80117650: sltu        $at, $s5, $t5
        ctx->r1 = ctx->r21 < ctx->r13 ? 1 : 0;
            goto L_8011777C;
    }
    // 0x80117650: sltu        $at, $s5, $t5
    ctx->r1 = ctx->r21 < ctx->r13 ? 1 : 0;
    // 0x80117654: beql        $at, $zero, L_80117668
    if (ctx->r1 == 0) {
        // 0x80117658: and         $v0, $s6, $t8
        ctx->r2 = ctx->r22 & ctx->r24;
            goto L_80117668;
    }
    goto skip_2;
    // 0x80117658: and         $v0, $s6, $t8
    ctx->r2 = ctx->r22 & ctx->r24;
    skip_2:
    // 0x8011765C: jal         0x80116F30
    // 0x80117660: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    func_80116F30(rdram, ctx);
        goto after_5;
    // 0x80117660: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_5:
    // 0x80117664: and         $v0, $s6, $t8
    ctx->r2 = ctx->r22 & ctx->r24;
L_80117668:
    // 0x80117668: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8011766C: addu        $t1, $t6, $v0
    ctx->r9 = ADD32(ctx->r14, ctx->r2);
    // 0x80117670: lhu         $t0, 0x4($t1)
    ctx->r8 = MEM_HU(ctx->r9, 0X4);
    // 0x80117674: lbu         $v0, 0x1($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X1);
    // 0x80117678: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x8011767C: srlv        $s6, $s6, $v0
    ctx->r22 = S32(U32(ctx->r22) >> (ctx->r2 & 31));
    // 0x80117680: bne         $at, $zero, L_801176E0
    if (ctx->r1 != 0) {
        // 0x80117684: sub         $s5, $s5, $v0
        ctx->r21 = SUB32(ctx->r21, ctx->r2);
            goto L_801176E0;
    }
    // 0x80117684: sub         $s5, $s5, $v0
    ctx->r21 = SUB32(ctx->r21, ctx->r2);
    // 0x80117688: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8011768C: beq         $t0, $at, L_801176F4
    if (ctx->r8 == ctx->r1) {
        // 0x80117690: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_801176F4;
    }
    // 0x80117690: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80117694: beql        $t0, $at, L_8011773C
    if (ctx->r8 == ctx->r1) {
        // 0x80117698: addiu       $t0, $zero, 0x3
        ctx->r8 = ADD32(0, 0X3);
            goto L_8011773C;
    }
    goto skip_3;
    // 0x80117698: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    skip_3:
    // 0x8011769C: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x801176A0: sltu        $at, $s5, $t0
    ctx->r1 = ctx->r21 < ctx->r8 ? 1 : 0;
    // 0x801176A4: beql        $at, $zero, L_801176B8
    if (ctx->r1 == 0) {
        // 0x801176A8: andi        $t1, $s6, 0x7F
        ctx->r9 = ctx->r22 & 0X7F;
            goto L_801176B8;
    }
    goto skip_4;
    // 0x801176A8: andi        $t1, $s6, 0x7F
    ctx->r9 = ctx->r22 & 0X7F;
    skip_4:
    // 0x801176AC: jal         0x80116F30
    // 0x801176B0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_80116F30(rdram, ctx);
        goto after_6;
    // 0x801176B0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_6:
    // 0x801176B4: andi        $t1, $s6, 0x7F
    ctx->r9 = ctx->r22 & 0X7F;
L_801176B8:
    // 0x801176B8: addiu       $t1, $t1, 0xB
    ctx->r9 = ADD32(ctx->r9, 0XB);
    // 0x801176BC: srlv        $s6, $s6, $t0
    ctx->r22 = S32(U32(ctx->r22) >> (ctx->r8 & 31));
    // 0x801176C0: sub         $s5, $s5, $t0
    ctx->r21 = SUB32(ctx->r21, ctx->r8);
    // 0x801176C4: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
L_801176C8:
    // 0x801176C8: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x801176CC: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x801176D0: bne         $t1, $zero, L_801176C8
    if (ctx->r9 != 0) {
        // 0x801176D4: addiu       $t7, $t7, 0x4
        ctx->r15 = ADD32(ctx->r15, 0X4);
            goto L_801176C8;
    }
    // 0x801176D4: addiu       $t7, $t7, 0x4
    ctx->r15 = ADD32(ctx->r15, 0X4);
    // 0x801176D8: j           L_8011764C
    // 0x801176DC: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
        goto L_8011764C;
    // 0x801176DC: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
L_801176E0:
    // 0x801176E0: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x801176E4: addiu       $t7, $t7, 0x4
    ctx->r15 = ADD32(ctx->r15, 0X4);
    // 0x801176E8: addiu       $t9, $t9, -0x1
    ctx->r25 = ADD32(ctx->r25, -0X1);
    // 0x801176EC: j           L_8011764C
    // 0x801176F0: or          $t2, $zero, $t0
    ctx->r10 = 0 | ctx->r8;
        goto L_8011764C;
    // 0x801176F0: or          $t2, $zero, $t0
    ctx->r10 = 0 | ctx->r8;
L_801176F4:
    // 0x801176F4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801176F8: sltu        $at, $s5, $t0
    ctx->r1 = ctx->r21 < ctx->r8 ? 1 : 0;
    // 0x801176FC: beql        $at, $zero, L_80117710
    if (ctx->r1 == 0) {
        // 0x80117700: andi        $t1, $s6, 0x3
        ctx->r9 = ctx->r22 & 0X3;
            goto L_80117710;
    }
    goto skip_5;
    // 0x80117700: andi        $t1, $s6, 0x3
    ctx->r9 = ctx->r22 & 0X3;
    skip_5:
    // 0x80117704: jal         0x80116F30
    // 0x80117708: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_80116F30(rdram, ctx);
        goto after_7;
    // 0x80117708: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_7:
    // 0x8011770C: andi        $t1, $s6, 0x3
    ctx->r9 = ctx->r22 & 0X3;
L_80117710:
    // 0x80117710: addi        $t1, $t1, 0x3
    ctx->r9 = ADD32(ctx->r9, 0X3);
    // 0x80117714: srlv        $s6, $s6, $t0
    ctx->r22 = S32(U32(ctx->r22) >> (ctx->r8 & 31));
    // 0x80117718: sub         $s5, $s5, $t0
    ctx->r21 = SUB32(ctx->r21, ctx->r8);
    // 0x8011771C: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
L_80117720:
    // 0x80117720: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x80117724: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x80117728: bne         $t1, $zero, L_80117720
    if (ctx->r9 != 0) {
        // 0x8011772C: addiu       $t7, $t7, 0x4
        ctx->r15 = ADD32(ctx->r15, 0X4);
            goto L_80117720;
    }
    // 0x8011772C: addiu       $t7, $t7, 0x4
    ctx->r15 = ADD32(ctx->r15, 0X4);
    // 0x80117730: j           L_8011764C
    // 0x80117734: nop

        goto L_8011764C;
    // 0x80117734: nop

    // 0x80117738: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
L_8011773C:
    // 0x8011773C: sltu        $at, $s5, $t0
    ctx->r1 = ctx->r21 < ctx->r8 ? 1 : 0;
    // 0x80117740: beql        $at, $zero, L_80117754
    if (ctx->r1 == 0) {
        // 0x80117744: andi        $t1, $s6, 0x7
        ctx->r9 = ctx->r22 & 0X7;
            goto L_80117754;
    }
    goto skip_6;
    // 0x80117744: andi        $t1, $s6, 0x7
    ctx->r9 = ctx->r22 & 0X7;
    skip_6:
    // 0x80117748: jal         0x80116F30
    // 0x8011774C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_80116F30(rdram, ctx);
        goto after_8;
    // 0x8011774C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_8:
    // 0x80117750: andi        $t1, $s6, 0x7
    ctx->r9 = ctx->r22 & 0X7;
L_80117754:
    // 0x80117754: addi        $t1, $t1, 0x3
    ctx->r9 = ADD32(ctx->r9, 0X3);
    // 0x80117758: srlv        $s6, $s6, $t0
    ctx->r22 = S32(U32(ctx->r22) >> (ctx->r8 & 31));
    // 0x8011775C: sub         $s5, $s5, $t0
    ctx->r21 = SUB32(ctx->r21, ctx->r8);
    // 0x80117760: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
L_80117764:
    // 0x80117764: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x80117768: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8011776C: bne         $t1, $zero, L_80117764
    if (ctx->r9 != 0) {
        // 0x80117770: addiu       $t7, $t7, 0x4
        ctx->r15 = ADD32(ctx->r15, 0X4);
            goto L_80117764;
    }
    // 0x80117770: addiu       $t7, $t7, 0x4
    ctx->r15 = ADD32(ctx->r15, 0X4);
    // 0x80117774: j           L_8011764C
    // 0x80117778: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
        goto L_8011764C;
    // 0x80117778: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
L_8011777C:
    // 0x8011777C: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x80117780: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x80117784: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80117788: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8011778C: addiu       $v0, $v0, 0x6692
    ctx->r2 = ADD32(ctx->r2, 0X6692);
    // 0x80117790: addi        $v1, $sp, 0x34
    ctx->r3 = ADD32(ctx->r29, 0X34);
    // 0x80117794: addi        $t0, $sp, 0x38
    ctx->r8 = ADD32(ctx->r29, 0X38);
    // 0x80117798: addi        $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8011779C: or          $a1, $zero, $s1
    ctx->r5 = 0 | ctx->r17;
    // 0x801177A0: addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // 0x801177A4: addiu       $a3, $a3, 0x6654
    ctx->r7 = ADD32(ctx->r7, 0X6654);
    // 0x801177A8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x801177AC: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x801177B0: jal         0x80116914
    // 0x801177B4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    func_80116914(rdram, ctx);
        goto after_9;
    // 0x801177B4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_9:
    // 0x801177B8: addi        $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x801177BC: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x801177C0: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x801177C4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x801177C8: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x801177CC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x801177D0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x801177D4: addiu       $v0, $v0, 0x66EE
    ctx->r2 = ADD32(ctx->r2, 0X66EE);
    // 0x801177D8: addi        $v1, $sp, 0x3C
    ctx->r3 = ADD32(ctx->r29, 0X3C);
    // 0x801177DC: addi        $t0, $sp, 0x40
    ctx->r8 = ADD32(ctx->r29, 0X40);
    // 0x801177E0: or          $a1, $zero, $s0
    ctx->r5 = 0 | ctx->r16;
    // 0x801177E4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801177E8: addiu       $a3, $a3, 0x66B2
    ctx->r7 = ADD32(ctx->r7, 0X66B2);
    // 0x801177EC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x801177F0: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x801177F4: jal         0x80116914
    // 0x801177F8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    func_80116914(rdram, ctx);
        goto after_10;
    // 0x801177F8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_10:
    // 0x801177FC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80117800: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80117804: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80117808: jal         0x80117A08
    // 0x8011780C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    func_80117A08(rdram, ctx);
        goto after_11;
    // 0x8011780C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_11:
    // 0x80117810: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80117814: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80117818: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8011781C: jr          $ra
    // 0x80117820: addiu       $sp, $sp, 0x540
    ctx->r29 = ADD32(ctx->r29, 0X540);
    return;
    // 0x80117820: addiu       $sp, $sp, 0x540
    ctx->r29 = ADD32(ctx->r29, 0X540);
;}
RECOMP_FUNC void bskazstill_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080086C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800870: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(288, 0X8D4) << 16);
    // 0x80800874: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800878: jr          $ra
    // 0x8080087C: lw          $v0, 0x8D4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(288, 0X8D4));
    return;
    // 0x8080087C: lw          $v0, 0x8D4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(288, 0X8D4));
;}
RECOMP_FUNC void _bastatemem_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085178: syscall     153
    recomp_syscall_handler(rdram, ctx, 0x80085178);
    return;
    // 0x8008517C: xori        $t0, $zero, 0xC
    ctx->r8 = 0 ^ 0XC;
;}
RECOMP_FUNC void func_80800000_chLagoonInnBlockedWall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800010: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800018: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x8080001C: beq         $t6, $at, L_80800074
    if (ctx->r14 == ctx->r1) {
        // 0x80800020: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800074;
    }
    // 0x80800020: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800024: bnel        $t6, $at, L_808000B0
    if (ctx->r14 != ctx->r1) {
        // 0x80800028: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000B0;
    }
    goto skip_0;
    // 0x80800028: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080002C: jal         0x800D9078
    // 0x80800030: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x80800030: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x80800034: beq         $v0, $zero, L_808000AC
    if (ctx->r2 == 0) {
        // 0x80800038: addiu       $a0, $sp, 0x24
        ctx->r4 = ADD32(ctx->r29, 0X24);
            goto L_808000AC;
    }
    // 0x80800038: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8080003C: jal         0x800EE7F8
    // 0x80800040: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800040: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x80800044: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800048: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x8080004C: jal         0x800EF1B8
    // 0x80800050: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_2;
    // 0x80800050: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    after_2:
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800058: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8080005C: jal         0x80086670
    // 0x80800060: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800060: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_3:
    // 0x80800064: jal         0x800DA544
    // 0x80800068: addiu       $a0, $zero, 0x3A9
    ctx->r4 = ADD32(0, 0X3A9);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x80800068: addiu       $a0, $zero, 0x3A9
    ctx->r4 = ADD32(0, 0X3A9);
    after_4:
    // 0x8080006C: b           L_808000B0
    // 0x80800070: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000B0;
    // 0x80800070: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800074:
    // 0x80800074: jal         0x800D9078
    // 0x80800078: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_5;
    // 0x80800078: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_5:
    // 0x8080007C: beql        $v0, $zero, L_808000B0
    if (ctx->r2 == 0) {
        // 0x80800080: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000B0;
    }
    goto skip_1;
    // 0x80800080: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800084: jal         0x800F54E4
    // 0x80800088: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x80800088: nop

    after_6:
    // 0x8080008C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800090: jal         0x800F82D4
    // 0x80800094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_7;
    // 0x80800094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800098: addiu       $a0, $zero, 0x1A7
    ctx->r4 = ADD32(0, 0X1A7);
    // 0x8080009C: jal         0x800887D8
    // 0x808000A0: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_8;
    // 0x808000A0: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_8:
    // 0x808000A4: jal         0x800FFAB0
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_9;
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_808000AC:
    // 0x808000AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000B0:
    // 0x808000B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000B8: jr          $ra
    // 0x808000BC: nop

    return;
    // 0x808000BC: nop

;}
RECOMP_FUNC void _chbaddiesetup_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086D50: syscall     449
    recomp_syscall_handler(rdram, ctx, 0x80086D50);
    return;
    // 0x80086D54: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_8010FD08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010FD08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010FD0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010FD10: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8010FD14: sb          $t6, 0x19($a0)
    MEM_B(0X19, ctx->r4) = ctx->r14;
    // 0x8010FD18: jal         0x8010FC38
    // 0x8010FD1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8010FC38(rdram, ctx);
        goto after_0;
    // 0x8010FD1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8010FD20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8010FD24: sb          $zero, 0x19($a0)
    MEM_B(0X19, ctx->r4) = 0;
    // 0x8010FD28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010FD2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010FD30: jr          $ra
    // 0x8010FD34: nop

    return;
    // 0x8010FD34: nop

;}
