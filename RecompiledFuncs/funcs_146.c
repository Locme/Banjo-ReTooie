#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80801348_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801348: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080134C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801350: jal         0x808002D4
    // 0x80801354: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808002D4_bsbansack(rdram, ctx);
        goto after_0;
    // 0x80801354: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801358: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x8080135C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801360: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801364: jal         0x8008CCBC
    // 0x80801368: addiu       $a1, $zero, 0x28C
    ctx->r5 = ADD32(0, 0X28C);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x80801368: addiu       $a1, $zero, 0x28C
    ctx->r5 = ADD32(0, 0X28C);
    after_1:
    // 0x8080136C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801370: jal         0x800845D8
    // 0x80801374: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babounce_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80801374: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80801378: jal         0x80801178
    // 0x8080137C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80801178_bsbansack(rdram, ctx);
        goto after_3;
    // 0x8080137C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80801380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801384: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801388: jr          $ra
    // 0x8080138C: nop

    return;
    // 0x8080138C: nop

;}
RECOMP_FUNC void func_80800000_chdinofamilymother(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: jal         0x80088848
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800014: beq         $v0, $zero, L_8080002C
    if (ctx->r2 == 0) {
        // 0x80800018: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080002C;
    }
    // 0x80800018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080001C: jal         0x808005EC
    // 0x80800020: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_808005EC_chdinofamilymother(rdram, ctx);
        goto after_1;
    // 0x80800020: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_1:
    // 0x80800024: b           L_80800078
    // 0x80800028: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
        goto L_80800078;
    // 0x80800028: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
L_8080002C:
    // 0x8080002C: jal         0x800DA298
    // 0x80800030: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800030: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    after_2:
    // 0x80800034: beql        $v0, $zero, L_80800078
    if (ctx->r2 == 0) {
        // 0x80800038: addiu       $a0, $s0, 0x18
        ctx->r4 = ADD32(ctx->r16, 0X18);
            goto L_80800078;
    }
    goto skip_0;
    // 0x80800038: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    skip_0:
    // 0x8080003C: jal         0x800DA298
    // 0x80800040: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800040: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    after_3:
    // 0x80800044: bnel        $v0, $zero, L_80800078
    if (ctx->r2 != 0) {
        // 0x80800048: addiu       $a0, $s0, 0x18
        ctx->r4 = ADD32(ctx->r16, 0X18);
            goto L_80800078;
    }
    goto skip_1;
    // 0x80800048: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    skip_1:
    // 0x8080004C: jal         0x800DA298
    // 0x80800050: addiu       $a0, $zero, 0x15F
    ctx->r4 = ADD32(0, 0X15F);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800050: addiu       $a0, $zero, 0x15F
    ctx->r4 = ADD32(0, 0X15F);
    after_4:
    // 0x80800054: beql        $v0, $zero, L_80800078
    if (ctx->r2 == 0) {
        // 0x80800058: addiu       $a0, $s0, 0x18
        ctx->r4 = ADD32(ctx->r16, 0X18);
            goto L_80800078;
    }
    goto skip_2;
    // 0x80800058: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    skip_2:
    // 0x8080005C: jal         0x800DA298
    // 0x80800060: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80800060: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    after_5:
    // 0x80800064: beq         $v0, $zero, L_80800074
    if (ctx->r2 == 0) {
        // 0x80800068: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800074;
    }
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080006C: jal         0x808005EC
    // 0x80800070: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808005EC_chdinofamilymother(rdram, ctx);
        goto after_6;
    // 0x80800070: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_6:
L_80800074:
    // 0x80800074: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
L_80800078:
    // 0x80800078: jal         0x800EE7F8
    // 0x8080007C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x8080007C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x80800080: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800084: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x80800088: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
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
RECOMP_FUNC void func_80103AA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103AA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103AA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103AA8: jal         0x801039A4
    // 0x80103AAC: nop

    func_801039A4(rdram, ctx);
        goto after_0;
    // 0x80103AAC: nop

    after_0:
    // 0x80103AB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103AB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80103AB8: jr          $ra
    // 0x80103ABC: nop

    return;
    // 0x80103ABC: nop

;}
RECOMP_FUNC void func_800C30B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C30B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C30BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C30C0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800C30C4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800C30C8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800C30CC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800C30D0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800C30D4: jal         0x800C1070
    // 0x800C30D8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800C1070(rdram, ctx);
        goto after_0;
    // 0x800C30D8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800C30DC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800C30E0: jal         0x800EEAD4
    // 0x800C30E4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800EEAD4(rdram, ctx);
        goto after_1;
    // 0x800C30E4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x800C30E8: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C30EC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800C30F0: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C30F4: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    // 0x800C30F8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800C30FC: bc1f        L_800C3110
    if (!c1cs) {
        // 0x800C3100: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800C3110;
    }
    // 0x800C3100: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800C3104: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800C3108: b           L_800C3144
    // 0x800C310C: nop

        goto L_800C3144;
    // 0x800C310C: nop

L_800C3110:
    // 0x800C3110: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x800C3114: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C3118: bc1fl       L_800C3140
    if (!c1cs) {
        // 0x800C311C: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_800C3140;
    }
    goto skip_0;
    // 0x800C311C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x800C3120: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x800C3124: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C3128: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C312C: sub.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x800C3130: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C3134: b           L_800C3144
    // 0x800C3138: sub.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f8.fl;
        goto L_800C3144;
    // 0x800C3138: sub.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800C313C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_800C3140:
    // 0x800C3140: nop

L_800C3144:
    // 0x800C3144: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800C3148: lbu         $a0, 0x33($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X33);
    // 0x800C314C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800C3150: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800C3154: jal         0x800C3058
    // 0x800C3158: nop

    func_800C3058(rdram, ctx);
        goto after_2;
    // 0x800C3158: nop

    after_2:
    // 0x800C315C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3160: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C3164: jr          $ra
    // 0x800C3168: nop

    return;
    // 0x800C3168: nop

;}
RECOMP_FUNC void func_808008C8_chsabreman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808008CC: slti        $at, $a1, 0x58
    ctx->r1 = SIGNED(ctx->r5) < 0X58 ? 1 : 0;
    // 0x808008D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808008D8: bne         $at, $zero, L_808008F4
    if (ctx->r1 != 0) {
        // 0x808008DC: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_808008F4;
    }
    // 0x808008DC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808008E0: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808008E4: beq         $a1, $at, L_80800C44
    if (ctx->r5 == ctx->r1) {
        // 0x808008E8: lw          $t0, 0x28($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X28);
            goto L_80800C44;
    }
    // 0x808008E8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x808008EC: b           L_80800CCC
    // 0x808008F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800CCC;
    // 0x808008F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808008F4:
    // 0x808008F4: addiu       $t6, $a1, -0xB
    ctx->r14 = ADD32(ctx->r5, -0XB);
    // 0x808008F8: sltiu       $at, $t6, 0x4D
    ctx->r1 = ctx->r14 < 0X4D ? 1 : 0;
    // 0x808008FC: beq         $at, $zero, L_80800CC0
    if (ctx->r1 == 0) {
        // 0x80800900: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800CC0;
    }
    // 0x80800900: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800904: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1232, 0X1A74) << 16);
    // 0x80800908: addu        $at, $at, $t6
    gpr jr_addend_80800910 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080090C: lw          $t6, 0x1A74($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1232, 0X1A74));
    // 0x80800910: jr          $t6
    // 0x80800914: nop

    switch (jr_addend_80800910 >> 2) {
        case 0: goto L_80800B5C; break;
        case 1: goto L_80800CC0; break;
        case 2: goto L_80800CC0; break;
        case 3: goto L_80800CC0; break;
        case 4: goto L_80800CC0; break;
        case 5: goto L_80800CC0; break;
        case 6: goto L_80800CC0; break;
        case 7: goto L_80800CC0; break;
        case 8: goto L_80800CC0; break;
        case 9: goto L_80800CC0; break;
        case 10: goto L_80800CC0; break;
        case 11: goto L_80800CC0; break;
        case 12: goto L_80800CC0; break;
        case 13: goto L_80800CC0; break;
        case 14: goto L_80800CC0; break;
        case 15: goto L_80800CC0; break;
        case 16: goto L_80800CC0; break;
        case 17: goto L_80800CC0; break;
        case 18: goto L_80800CC0; break;
        case 19: goto L_80800CC0; break;
        case 20: goto L_80800C04; break;
        case 21: goto L_80800CC0; break;
        case 22: goto L_80800CC0; break;
        case 23: goto L_80800CC0; break;
        case 24: goto L_80800CC0; break;
        case 25: goto L_80800CC0; break;
        case 26: goto L_80800CC0; break;
        case 27: goto L_80800CC0; break;
        case 28: goto L_80800CC0; break;
        case 29: goto L_80800CC0; break;
        case 30: goto L_80800CA0; break;
        case 31: goto L_80800CC0; break;
        case 32: goto L_80800CC0; break;
        case 33: goto L_80800CC0; break;
        case 34: goto L_80800CC0; break;
        case 35: goto L_80800A94; break;
        case 36: goto L_80800CC0; break;
        case 37: goto L_80800CC0; break;
        case 38: goto L_80800CC0; break;
        case 39: goto L_80800CC0; break;
        case 40: goto L_80800CC0; break;
        case 41: goto L_80800CC0; break;
        case 42: goto L_80800CC0; break;
        case 43: goto L_80800CC0; break;
        case 44: goto L_80800CC0; break;
        case 45: goto L_80800CC0; break;
        case 46: goto L_80800CC0; break;
        case 47: goto L_80800CC0; break;
        case 48: goto L_80800CC0; break;
        case 49: goto L_80800CC0; break;
        case 50: goto L_808009E4; break;
        case 51: goto L_80800918; break;
        case 52: goto L_80800CC0; break;
        case 53: goto L_80800950; break;
        case 54: goto L_80800CC0; break;
        case 55: goto L_80800CC0; break;
        case 56: goto L_80800CC0; break;
        case 57: goto L_80800B90; break;
        case 58: goto L_80800CC0; break;
        case 59: goto L_80800CC0; break;
        case 60: goto L_80800CC0; break;
        case 61: goto L_80800CC0; break;
        case 62: goto L_80800CC0; break;
        case 63: goto L_80800CC0; break;
        case 64: goto L_80800BA4; break;
        case 65: goto L_80800BDC; break;
        case 66: goto L_80800CC0; break;
        case 67: goto L_80800CC0; break;
        case 68: goto L_80800CC0; break;
        case 69: goto L_80800CC0; break;
        case 70: goto L_80800CC0; break;
        case 71: goto L_80800BE8; break;
        case 72: goto L_80800CC0; break;
        case 73: goto L_80800CC0; break;
        case 74: goto L_80800CC0; break;
        case 75: goto L_80800CC0; break;
        case 76: goto L_80800C18; break;
        default: switch_error(__func__, 0x80800910, 0x80801A74);
    }
    // 0x80800914: nop

L_80800918:
    // 0x80800918: addiu       $a0, $zero, 0x1CA
    ctx->r4 = ADD32(0, 0X1CA);
    // 0x8080091C: jal         0x800DA564
    // 0x80800920: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x80800920: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800924: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800928: bne         $v0, $at, L_80800CC8
    if (ctx->r2 != ctx->r1) {
        // 0x8080092C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800CC8;
    }
    // 0x8080092C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800930: jal         0x8008A508
    // 0x80800934: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    _subaddietaxi_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800934: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_1:
    // 0x80800938: beq         $v0, $zero, L_80800CC8
    if (ctx->r2 == 0) {
        // 0x8080093C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800CC8;
    }
    // 0x8080093C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800940: jal         0x808011F8
    // 0x80800944: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_2;
    // 0x80800944: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_2:
    // 0x80800948: b           L_80800CCC
    // 0x8080094C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CCC;
    // 0x8080094C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800950:
    // 0x80800950: addiu       $a0, $zero, 0x1CA
    ctx->r4 = ADD32(0, 0X1CA);
    // 0x80800954: jal         0x800DA564
    // 0x80800958: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DA564(rdram, ctx);
        goto after_3;
    // 0x80800958: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x8080095C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800960: bne         $v0, $at, L_80800CC8
    if (ctx->r2 != ctx->r1) {
        // 0x80800964: lw          $t7, 0x28($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X28);
            goto L_80800CC8;
    }
    // 0x80800964: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80800968: lhu         $t8, 0x72($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X72);
    // 0x8080096C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800970: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80800974: bnel        $t9, $at, L_80800CCC
    if (ctx->r25 != ctx->r1) {
        // 0x80800978: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800CCC;
    }
    goto skip_0;
    // 0x80800978: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8080097C: jal         0x800FC660
    // 0x80800980: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_4;
    // 0x80800980: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_4:
    // 0x80800984: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800988: jal         0x808011F8
    // 0x8080098C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_5;
    // 0x8080098C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_5:
    // 0x80800990: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800994: jal         0x8008A4B0
    // 0x80800998: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x80800998: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8080099C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x808009A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808009A4: lw          $t1, 0x50($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X50);
    // 0x808009A8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x808009AC: sw          $t2, 0x50($t0)
    MEM_W(0X50, ctx->r8) = ctx->r10;
    // 0x808009B0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x808009B4: lw          $t4, 0x50($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X50);
    // 0x808009B8: bnel        $t4, $at, L_80800CCC
    if (ctx->r12 != ctx->r1) {
        // 0x808009BC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800CCC;
    }
    goto skip_1;
    // 0x808009BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x808009C0: jal         0x800F54E4
    // 0x808009C4: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x808009C4: nop

    after_7:
    // 0x808009C8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808009CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808009D4: jal         0x800F8300
    // 0x808009D8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_800F8300(rdram, ctx);
        goto after_8;
    // 0x808009D8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_8:
    // 0x808009DC: b           L_80800CCC
    // 0x808009E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CCC;
    // 0x808009E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009E4:
    // 0x808009E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808009E8: jal         0x80100094
    // 0x808009EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_9;
    // 0x808009EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808009F0: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x808009F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808009F8: addiu       $a0, $zero, 0x1FE
    ctx->r4 = ADD32(0, 0X1FE);
    // 0x808009FC: beq         $t5, $zero, L_80800A18
    if (ctx->r13 == 0) {
        // 0x80800A00: addiu       $a1, $sp, 0x28
        ctx->r5 = ADD32(ctx->r29, 0X28);
            goto L_80800A18;
    }
    // 0x80800A00: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800A04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800A08: beq         $t5, $at, L_80800A58
    if (ctx->r13 == ctx->r1) {
        // 0x80800A0C: addiu       $a0, $sp, 0x28
        ctx->r4 = ADD32(ctx->r29, 0X28);
            goto L_80800A58;
    }
    // 0x80800A0C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800A10: b           L_80800CCC
    // 0x80800A14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CCC;
    // 0x80800A14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A18:
    // 0x80800A18: jal         0x801084B0
    // 0x80800A1C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_801084B0(rdram, ctx);
        goto after_10;
    // 0x80800A1C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_10:
    // 0x80800A20: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800A24: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800A28: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800A2C: jal         0x8008A028
    // 0x80800A30: addiu       $a0, $v1, 0x810
    ctx->r4 = ADD32(ctx->r3, 0X810);
    _subaddielink_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x80800A30: addiu       $a0, $v1, 0x810
    ctx->r4 = ADD32(ctx->r3, 0X810);
    after_11:
    // 0x80800A34: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800A38: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800A3C: jal         0x80102FDC
    // 0x80800A40: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    func_80102FDC(rdram, ctx);
        goto after_12;
    // 0x80800A40: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    after_12:
    // 0x80800A44: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80800A48: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80800A4C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80800A50: b           L_80800CC8
    // 0x80800A54: sw          $t8, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->r24;
        goto L_80800CC8;
    // 0x80800A54: sw          $t8, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->r24;
L_80800A58:
    // 0x80800A58: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800A5C: addiu       $t1, $zero, 0x12
    ctx->r9 = ADD32(0, 0X12);
    // 0x80800A60: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800A64: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80800A68: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x80800A6C: jal         0x80086590
    // 0x80800A70: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _chlifeforcespell_entrypoint_1(rdram, ctx);
        goto after_13;
    // 0x80800A70: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_13:
    // 0x80800A74: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80800A78: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x80800A7C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80800A80: sw          $v0, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = ctx->r2;
    // 0x80800A84: jal         0x808017D8
    // 0x80800A88: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_808017D8_chsabreman(rdram, ctx);
        goto after_14;
    // 0x80800A88: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_14:
    // 0x80800A8C: b           L_80800CCC
    // 0x80800A90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CCC;
    // 0x80800A90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A94:
    // 0x80800A94: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80800A98: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800A9C: lhu         $v0, 0x72($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X72);
    // 0x80800AA0: srl         $t3, $v0, 10
    ctx->r11 = S32(U32(ctx->r2) >> 10);
    // 0x80800AA4: beq         $t3, $at, L_80800AC4
    if (ctx->r11 == ctx->r1) {
        // 0x80800AA8: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80800AC4;
    }
    // 0x80800AA8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800AAC: beq         $t3, $at, L_80800AEC
    if (ctx->r11 == ctx->r1) {
        // 0x80800AB0: addiu       $at, $zero, 0x18
        ctx->r1 = ADD32(0, 0X18);
            goto L_80800AEC;
    }
    // 0x80800AB0: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80800AB4: beq         $t3, $at, L_80800B08
    if (ctx->r11 == ctx->r1) {
        // 0x80800AB8: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800B08;
    }
    // 0x80800AB8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800ABC: b           L_80800B14
    // 0x80800AC0: lh          $t4, 0x30($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X30);
        goto L_80800B14;
    // 0x80800AC0: lh          $t4, 0x30($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X30);
L_80800AC4:
    // 0x80800AC4: jal         0x808016E4
    // 0x80800AC8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_808016E4_chsabreman(rdram, ctx);
        goto after_15;
    // 0x80800AC8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_15:
    // 0x80800ACC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800AD0: jal         0x808011F8
    // 0x80800AD4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_16;
    // 0x80800AD4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_16:
    // 0x80800AD8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800ADC: jal         0x8008A4B0
    // 0x80800AE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_17;
    // 0x80800AE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x80800AE4: b           L_80800B14
    // 0x80800AE8: lh          $t4, 0x30($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X30);
        goto L_80800B14;
    // 0x80800AE8: lh          $t4, 0x30($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X30);
L_80800AEC:
    // 0x80800AEC: jal         0x808016E4
    // 0x80800AF0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_808016E4_chsabreman(rdram, ctx);
        goto after_18;
    // 0x80800AF0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_18:
    // 0x80800AF4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800AF8: jal         0x808011F8
    // 0x80800AFC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_19;
    // 0x80800AFC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_19:
    // 0x80800B00: b           L_80800B14
    // 0x80800B04: lh          $t4, 0x30($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X30);
        goto L_80800B14;
    // 0x80800B04: lh          $t4, 0x30($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X30);
L_80800B08:
    // 0x80800B08: jal         0x808011F8
    // 0x80800B0C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_20;
    // 0x80800B0C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_20:
    // 0x80800B10: lh          $t4, 0x30($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X30);
L_80800B14:
    // 0x80800B14: addiu       $at, $zero, 0x1275
    ctx->r1 = ADD32(0, 0X1275);
    // 0x80800B18: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x80800B1C: bnel        $t4, $at, L_80800CCC
    if (ctx->r12 != ctx->r1) {
        // 0x80800B20: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800CCC;
    }
    goto skip_2;
    // 0x80800B20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x80800B24: jal         0x800C01A8
    // 0x80800B28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C01A8(rdram, ctx);
        goto after_21;
    // 0x80800B28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x80800B2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800B30: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800B34: jal         0x808017D8
    // 0x80800B38: addiu       $a2, $zero, 0x2030
    ctx->r6 = ADD32(0, 0X2030);
    func_808017D8_chsabreman(rdram, ctx);
        goto after_22;
    // 0x80800B38: addiu       $a2, $zero, 0x2030
    ctx->r6 = ADD32(0, 0X2030);
    after_22:
    // 0x80800B3C: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    // 0x80800B40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800B44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800B48: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800B4C: jal         0x800D1000
    // 0x80800B50: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_23;
    // 0x80800B50: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_23:
    // 0x80800B54: b           L_80800CCC
    // 0x80800B58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CCC;
    // 0x80800B58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B5C:
    // 0x80800B5C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80800B60: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800B64: bne         $t5, $at, L_80800B88
    if (ctx->r13 != ctx->r1) {
        // 0x80800B68: nop
    
            goto L_80800B88;
    }
    // 0x80800B68: nop

    // 0x80800B6C: jal         0x808016E4
    // 0x80800B70: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_808016E4_chsabreman(rdram, ctx);
        goto after_24;
    // 0x80800B70: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_24:
    // 0x80800B74: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800B78: jal         0x808011F8
    // 0x80800B7C: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_25;
    // 0x80800B7C: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_25:
    // 0x80800B80: b           L_80800CCC
    // 0x80800B84: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800CCC;
    // 0x80800B84: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800B88:
    // 0x80800B88: b           L_80800CCC
    // 0x80800B8C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800CCC;
    // 0x80800B8C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800B90:
    // 0x80800B90: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800B94: jal         0x80801010
    // 0x80800B98: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80801010_chsabreman(rdram, ctx);
        goto after_26;
    // 0x80800B98: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_26:
    // 0x80800B9C: b           L_80800CCC
    // 0x80800BA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CCC;
    // 0x80800BA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800BA4:
    // 0x80800BA4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800BA8: jal         0x80108B04
    // 0x80800BAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_27;
    // 0x80800BAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x80800BB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800BB4: jal         0x8008A4B0
    // 0x80800BB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_28;
    // 0x80800BB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
    // 0x80800BBC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800BC0: jal         0x808011F8
    // 0x80800BC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_29;
    // 0x80800BC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_29:
    // 0x80800BC8: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80800BCC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800BD0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800BD4: b           L_80800CC8
    // 0x80800BD8: swc1        $f4, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f4.u32l;
        goto L_80800CC8;
    // 0x80800BD8: swc1        $f4, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f4.u32l;
L_80800BDC:
    // 0x80800BDC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80800BE0: b           L_80800CC8
    // 0x80800BE4: sw          $zero, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = 0;
        goto L_80800CC8;
    // 0x80800BE4: sw          $zero, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = 0;
L_80800BE8:
    // 0x80800BE8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80800BEC: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1232, 0X1BE8) << 16);
    // 0x80800BF0: addiu       $a0, $a0, 0x1BE8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1232, 0X1BE8));
    // 0x80800BF4: jal         0x80088090
    // 0x80800BF8: lw          $a1, 0x38($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_30;
    // 0x80800BF8: lw          $a1, 0x38($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X38);
    after_30:
    // 0x80800BFC: b           L_80800CCC
    // 0x80800C00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CCC;
    // 0x80800C00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C04:
    // 0x80800C04: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800C08: jal         0x80800D30
    // 0x80800C0C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80800D30_chsabreman(rdram, ctx);
        goto after_31;
    // 0x80800C0C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_31:
    // 0x80800C10: b           L_80800CCC
    // 0x80800C14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CCC;
    // 0x80800C14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C18:
    // 0x80800C18: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800C1C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80800C20: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800C24: andi        $t9, $a1, 0xFFFF
    ctx->r25 = ctx->r5 & 0XFFFF;
    // 0x80800C28: and         $t1, $a2, $at
    ctx->r9 = ctx->r6 & ctx->r1;
    // 0x80800C2C: srl         $a2, $t1, 16
    ctx->r6 = S32(U32(ctx->r9) >> 16);
    // 0x80800C30: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80800C34: jal         0x8080167C
    // 0x80800C38: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8080167C_chsabreman(rdram, ctx);
        goto after_32;
    // 0x80800C38: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_32:
    // 0x80800C3C: b           L_80800CD0
    // 0x80800C40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800CD0;
    // 0x80800C40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800C44:
    // 0x80800C44: jal         0x80088848
    // 0x80800C48: sw          $zero, 0x50($t0)
    MEM_W(0X50, ctx->r8) = 0;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_33;
    // 0x80800C48: sw          $zero, 0x50($t0)
    MEM_W(0X50, ctx->r8) = 0;
    after_33:
    // 0x80800C4C: bne         $v0, $zero, L_80800C70
    if (ctx->r2 != 0) {
        // 0x80800C50: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800C70;
    }
    // 0x80800C50: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800C54: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800C58: addiu       $a2, $a2, 0x6370
    ctx->r6 = ADD32(ctx->r6, 0X6370);
    // 0x80800C5C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80800C60: jal         0x8008A560
    // 0x80800C64: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _subaddietaxi_entrypoint_13(rdram, ctx);
        goto after_34;
    // 0x80800C64: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_34:
    // 0x80800C68: beq         $v0, $zero, L_80800C80
    if (ctx->r2 == 0) {
        // 0x80800C6C: lw          $t3, 0x28($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X28);
            goto L_80800C80;
    }
    // 0x80800C6C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_80800C70:
    // 0x80800C70: jal         0x80800030
    // 0x80800C74: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80800030_chsabreman(rdram, ctx);
        goto after_35;
    // 0x80800C74: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_35:
    // 0x80800C78: b           L_80800CCC
    // 0x80800C7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CCC;
    // 0x80800C7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C80:
    // 0x80800C80: lw          $t4, 0x78($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X78);
    // 0x80800C84: sll         $t6, $t4, 26
    ctx->r14 = S32(ctx->r12 << 26);
    // 0x80800C88: bgezl       $t6, L_80800CCC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800C8C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800CCC;
    }
    goto skip_3;
    // 0x80800C8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x80800C90: jal         0x800FFAB0
    // 0x80800C94: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_36;
    // 0x80800C94: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_36:
    // 0x80800C98: b           L_80800CCC
    // 0x80800C9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CCC;
    // 0x80800C9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CA0:
    // 0x80800CA0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800CA4: jal         0x80100094
    // 0x80800CA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_37;
    // 0x80800CA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_37:
    // 0x80800CAC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800CB0: jal         0x8008A080
    // 0x80800CB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _subaddiepalette_entrypoint_4(rdram, ctx);
        goto after_38;
    // 0x80800CB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_38:
    // 0x80800CB8: b           L_80800CCC
    // 0x80800CBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CCC;
    // 0x80800CBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CC0:
    // 0x80800CC0: b           L_80800CCC
    // 0x80800CC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800CCC;
    // 0x80800CC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800CC8:
    // 0x80800CC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CCC:
    // 0x80800CCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800CD0:
    // 0x80800CD0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800CD4: jr          $ra
    // 0x80800CD8: nop

    return;
    // 0x80800CD8: nop

;}
RECOMP_FUNC void func_8009BE20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BE20: jr          $ra
    // 0x8009BE24: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    return;
    // 0x8009BE24: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800030_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800034: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800038: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080003C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800040: jal         0x8009E77C
    // 0x80800044: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_8009E77C(rdram, ctx);
        goto after_0;
    // 0x80800044: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_0:
    // 0x80800048: bnel        $v0, $zero, L_808000F4
    if (ctx->r2 != 0) {
        // 0x8080004C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000F4;
    }
    goto skip_0;
    // 0x8080004C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800050: jal         0x80085290
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800058: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x8080005C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800064: jal         0x8009C554
    // 0x80800068: lui         $a1, 0x4302
    ctx->r5 = S32(0X4302 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_2;
    // 0x80800068: lui         $a1, 0x4302
    ctx->r5 = S32(0X4302 << 16);
    after_2:
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800070: jal         0x8009BCB4
    // 0x80800074: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_gravity(rdram, ctx);
        goto after_3;
    // 0x80800074: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800078: lui         $a1, 0xC3C7
    ctx->r5 = S32(0XC3C7 << 16);
    // 0x8080007C: ori         $a1, $a1, 0xFEB8
    ctx->r5 = ctx->r5 | 0XFEB8;
    // 0x80800080: jal         0x8009BCC4
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800088: jal         0x800F8B88
    // 0x8080008C: nop

    func_800F8B88(rdram, ctx);
        goto after_5;
    // 0x8080008C: nop

    after_5:
    // 0x80800090: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800094: beq         $v0, $at, L_808000A4
    if (ctx->r2 == ctx->r1) {
        // 0x80800098: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000A4;
    }
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080009C: jal         0x800A0CF4
    // 0x808000A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_6;
    // 0x808000A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
L_808000A4:
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A8: jal         0x800961AC
    // 0x808000AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800961AC(rdram, ctx);
        goto after_7;
    // 0x808000AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: jal         0x80093360
    // 0x808000B8: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    func_80093360(rdram, ctx);
        goto after_8;
    // 0x808000B8: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    after_8:
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C0: jal         0x8009BC5C
    // 0x808000C4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_8009BC5C(rdram, ctx);
        goto after_9;
    // 0x808000C4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_9:
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000CC: jal         0x80085298
    // 0x808000D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _baswim_entrypoint_6(rdram, ctx);
        goto after_10;
    // 0x808000D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808000D4: jal         0x8009E6F8
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getCurrentState(rdram, ctx);
        goto after_11;
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808000DC: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x808000E0: beq         $v0, $at, L_808000F0
    if (ctx->r2 == ctx->r1) {
        // 0x808000E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000F0;
    }
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: jal         0x80085558
    // 0x808000EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _baairbar_entrypoint_0(rdram, ctx);
        goto after_12;
    // 0x808000EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
L_808000F0:
    // 0x808000F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000F4:
    // 0x808000F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000FC: jr          $ra
    // 0x80800100: nop

    return;
    // 0x80800100: nop

;}
RECOMP_FUNC void func_808000C8_chlifeforcespell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808000CC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808000D0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808000D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000D8: jal         0x80100094
    // 0x808000DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808000E0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x808000E4: jal         0x80106790
    // 0x808000E8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808000E8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_1:
    // 0x808000EC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808000F0: jal         0x800EFD24
    // 0x808000F4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x808000F4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_2:
    // 0x808000F8: jal         0x800DA298
    // 0x808000FC: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x808000FC: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_3:
    // 0x80800100: beq         $v0, $zero, L_80800278
    if (ctx->r2 == 0) {
        // 0x80800104: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_80800278;
    }
    // 0x80800104: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800108: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x8080010C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80800110: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x80800114: andi        $t6, $a1, 0x1FF
    ctx->r14 = ctx->r5 & 0X1FF;
    // 0x80800118: jal         0x8008A0D0
    // 0x8080011C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x8080011C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_4:
    // 0x80800120: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80800124: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x80800128: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1328, 0X4B4) << 16);
    // 0x8080012C: addiu       $t9, $t9, 0x4B4
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1328, 0X4B4));
    // 0x80800130: addiu       $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
    // 0x80800134: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800138: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8080013C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800140: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800144: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x80800148: jal         0x80089878
    // 0x8080014C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    _sumumbofx_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x8080014C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_5:
    // 0x80800150: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800154: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800158: srl         $t0, $v0, 10
    ctx->r8 = S32(U32(ctx->r2) >> 10);
    // 0x8080015C: beq         $t0, $at, L_8080017C
    if (ctx->r8 == ctx->r1) {
        // 0x80800160: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080017C;
    }
    // 0x80800160: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800164: beq         $t0, $at, L_808001DC
    if (ctx->r8 == ctx->r1) {
        // 0x80800168: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808001DC;
    }
    // 0x80800168: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080016C: beq         $t0, $at, L_80800214
    if (ctx->r8 == ctx->r1) {
        // 0x80800170: nop
    
            goto L_80800214;
    }
    // 0x80800170: nop

    // 0x80800174: b           L_80800270
    // 0x80800178: nop

        goto L_80800270;
    // 0x80800178: nop

L_8080017C:
    // 0x8080017C: jal         0x800898E8
    // 0x80800180: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_6;
    // 0x80800180: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_6:
    // 0x80800184: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800188: nop

    // 0x8080018C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800190: nop

    // 0x80800194: bc1f        L_80800270
    if (!c1cs) {
        // 0x80800198: nop
    
            goto L_80800270;
    }
    // 0x80800198: nop

    // 0x8080019C: jal         0x800D9078
    // 0x808001A0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_7;
    // 0x808001A0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_7:
    // 0x808001A4: lui         $a1, 0x3FEC
    ctx->r5 = S32(0X3FEC << 16);
    // 0x808001A8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808001AC: jal         0x80089868
    // 0x808001B0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    _sumumbofx_entrypoint_5(rdram, ctx);
        goto after_8;
    // 0x808001B0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_8:
    // 0x808001B4: beq         $v0, $zero, L_80800270
    if (ctx->r2 == 0) {
        // 0x808001B8: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80800270;
    }
    // 0x808001B8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808001BC: jal         0x800898C8
    // 0x808001C0: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    _sumumbofx_entrypoint_17(rdram, ctx);
        goto after_9;
    // 0x808001C0: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    after_9:
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: jal         0x80101FDC
    // 0x808001CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_10;
    // 0x808001CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x808001D0: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808001D4: b           L_80800270
    // 0x808001D8: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_80800270;
    // 0x808001D8: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_808001DC:
    // 0x808001DC: jal         0x800D9078
    // 0x808001E0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_11;
    // 0x808001E0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_11:
    // 0x808001E4: beq         $v0, $zero, L_80800270
    if (ctx->r2 == 0) {
        // 0x808001E8: nop
    
            goto L_80800270;
    }
    // 0x808001E8: nop

    // 0x808001EC: jal         0x80086AF0
    // 0x808001F0: nop

    _chglowbo_entrypoint_6(rdram, ctx);
        goto after_12;
    // 0x808001F0: nop

    after_12:
    // 0x808001F4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808001F8: jal         0x800898C0
    // 0x808001FC: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    _sumumbofx_entrypoint_16(rdram, ctx);
        goto after_13;
    // 0x808001FC: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    after_13:
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800204: jal         0x80101FDC
    // 0x80800208: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_14;
    // 0x80800208: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_14:
    // 0x8080020C: b           L_80800270
    // 0x80800210: nop

        goto L_80800270;
    // 0x80800210: nop

L_80800214:
    // 0x80800214: jal         0x800898F0
    // 0x80800218: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    _sumumbofx_entrypoint_22(rdram, ctx);
        goto after_15;
    // 0x80800218: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_15:
    // 0x8080021C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1328, 0X450) << 16);
    // 0x80800220: lwc1        $f8, 0x450($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1328, 0X450));
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800228: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8080022C: nop

    // 0x80800230: bc1f        L_80800270
    if (!c1cs) {
        // 0x80800234: nop
    
            goto L_80800270;
    }
    // 0x80800234: nop

    // 0x80800238: jal         0x80089848
    // 0x8080023C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _sumumbofx_entrypoint_1(rdram, ctx);
        goto after_16;
    // 0x8080023C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x80800240: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800244: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x80800248: jal         0x8010114C
    // 0x8080024C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_17;
    // 0x8080024C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x80800250: jal         0x800FFA88
    // 0x80800254: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_18;
    // 0x80800254: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_18:
    // 0x80800258: jal         0x800DA544
    // 0x8080025C: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    func_800DA544(rdram, ctx);
        goto after_19;
    // 0x8080025C: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    after_19:
    // 0x80800260: jal         0x800DA524
    // 0x80800264: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA524(rdram, ctx);
        goto after_20;
    // 0x80800264: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_20:
    // 0x80800268: b           L_8080027C
    // 0x8080026C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8080027C;
    // 0x8080026C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800270:
    // 0x80800270: jal         0x800898B0
    // 0x80800274: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_21;
    // 0x80800274: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_21:
L_80800278:
    // 0x80800278: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080027C:
    // 0x8080027C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800280: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800284: jr          $ra
    // 0x80800288: nop

    return;
    // 0x80800288: nop

;}
RECOMP_FUNC void func_80107070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107070: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80107074: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80107078: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010707C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80107080: jal         0x80106F30
    // 0x80107084: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80106F30(rdram, ctx);
        goto after_0;
    // 0x80107084: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80107088: bne         $v0, $zero, L_80107098
    if (ctx->r2 != 0) {
        // 0x8010708C: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80107098;
    }
    // 0x8010708C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80107090: b           L_801071EC
    // 0x80107094: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801071EC;
    // 0x80107094: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80107098:
    // 0x80107098: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8010709C: lh          $t6, 0xA($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XA);
    // 0x801070A0: sltiu       $at, $a3, 0x5
    ctx->r1 = ctx->r7 < 0X5 ? 1 : 0;
    // 0x801070A4: bne         $a3, $t6, L_801070B4
    if (ctx->r7 != ctx->r14) {
        // 0x801070A8: nop
    
            goto L_801070B4;
    }
    // 0x801070A8: nop

    // 0x801070AC: b           L_801071EC
    // 0x801070B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801071EC;
    // 0x801070B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801070B4:
    // 0x801070B4: beq         $at, $zero, L_801071D0
    if (ctx->r1 == 0) {
        // 0x801070B8: sll         $t7, $a3, 2
        ctx->r15 = S32(ctx->r7 << 2);
            goto L_801071D0;
    }
    // 0x801070B8: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x801070BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801070C0: addu        $at, $at, $t7
    gpr jr_addend_801070C8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801070C4: lw          $t7, 0x6460($at)
    ctx->r15 = ADD32(ctx->r1, 0X6460);
    // 0x801070C8: jr          $t7
    // 0x801070CC: nop

    switch (jr_addend_801070C8 >> 2) {
        case 0: goto L_801070D0; break;
        case 1: goto L_801070E4; break;
        case 2: goto L_8010712C; break;
        case 3: goto L_80107160; break;
        case 4: goto L_80107194; break;
        default: switch_error(__func__, 0x801070C8, 0x80126460);
    }
    // 0x801070CC: nop

L_801070D0:
    // 0x801070D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801070D4: jal         0x80103110
    // 0x801070D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x801070D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x801070DC: b           L_801071D0
    // 0x801070E0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
        goto L_801071D0;
    // 0x801070E0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
L_801070E4:
    // 0x801070E4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x801070E8: addiu       $a2, $a2, 0x44F0
    ctx->r6 = ADD32(ctx->r6, 0X44F0);
    // 0x801070EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801070F0: jal         0x80089D18
    // 0x801070F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x801070F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x801070F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801070FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80107100: jal         0x801073F8
    // 0x80107104: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_801073F8(rdram, ctx);
        goto after_3;
    // 0x80107104: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80107108: bne         $v0, $zero, L_80107118
    if (ctx->r2 != 0) {
        // 0x8010710C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80107118;
    }
    // 0x8010710C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80107110: jal         0x80103110
    // 0x80107114: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_4;
    // 0x80107114: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_80107118:
    // 0x80107118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010711C: jal         0x80107750
    // 0x80107120: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80107750(rdram, ctx);
        goto after_5;
    // 0x80107120: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x80107124: b           L_801071D0
    // 0x80107128: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
        goto L_801071D0;
    // 0x80107128: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
L_8010712C:
    // 0x8010712C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80107130: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80107134: jal         0x801073F8
    // 0x80107138: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_801073F8(rdram, ctx);
        goto after_6;
    // 0x80107138: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x8010713C: bne         $v0, $zero, L_8010714C
    if (ctx->r2 != 0) {
        // 0x80107140: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010714C;
    }
    // 0x80107140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80107144: jal         0x80103110
    // 0x80107148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_7;
    // 0x80107148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
L_8010714C:
    // 0x8010714C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80107150: jal         0x80107750
    // 0x80107154: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80107750(rdram, ctx);
        goto after_8;
    // 0x80107154: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x80107158: b           L_801071D0
    // 0x8010715C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
        goto L_801071D0;
    // 0x8010715C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
L_80107160:
    // 0x80107160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80107164: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80107168: jal         0x801073F8
    // 0x8010716C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_801073F8(rdram, ctx);
        goto after_9;
    // 0x8010716C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x80107170: bne         $v0, $zero, L_80107180
    if (ctx->r2 != 0) {
        // 0x80107174: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80107180;
    }
    // 0x80107174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80107178: jal         0x80103110
    // 0x8010717C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_10;
    // 0x8010717C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
L_80107180:
    // 0x80107180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80107184: jal         0x80107448
    // 0x80107188: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80107448(rdram, ctx);
        goto after_11;
    // 0x80107188: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_11:
    // 0x8010718C: b           L_801071D0
    // 0x80107190: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
        goto L_801071D0;
    // 0x80107190: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
L_80107194:
    // 0x80107194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80107198: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8010719C: jal         0x801073F8
    // 0x801071A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_801073F8(rdram, ctx);
        goto after_12;
    // 0x801071A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x801071A4: bne         $v0, $zero, L_801071B4
    if (ctx->r2 != 0) {
        // 0x801071A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801071B4;
    }
    // 0x801071A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801071AC: jal         0x80103110
    // 0x801071B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_13;
    // 0x801071B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
L_801071B4:
    // 0x801071B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801071B8: jal         0x8010754C
    // 0x801071BC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8010754C(rdram, ctx);
        goto after_14;
    // 0x801071BC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_14:
    // 0x801071C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801071C4: jal         0x801075E4
    // 0x801071C8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_801075E4(rdram, ctx);
        goto after_15;
    // 0x801071C8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_15:
    // 0x801071CC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
L_801071D0:
    // 0x801071D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801071D4: jal         0x801073AC
    // 0x801071D8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_801073AC(rdram, ctx);
        goto after_16;
    // 0x801071D8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_16:
    // 0x801071DC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x801071E0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x801071E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801071E8: sh          $t8, 0xA($t9)
    MEM_H(0XA, ctx->r25) = ctx->r24;
L_801071EC:
    // 0x801071EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801071F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801071F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801071F8: jr          $ra
    // 0x801071FC: nop

    return;
    // 0x801071FC: nop

;}
RECOMP_FUNC void func_8008E92C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E92C: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x8008E930: jr          $ra
    // 0x8008E934: lw          $v0, 0x18($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X18);
    return;
    // 0x8008E934: lw          $v0, 0x18($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X18);
;}
RECOMP_FUNC void bawobble_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800104: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800108: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080010C: jal         0x8080004C
    // 0x80800110: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8080004C_bawobble(rdram, ctx);
        goto after_0;
    // 0x80800110: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080011C: jr          $ra
    // 0x80800120: nop

    return;
    // 0x80800120: nop

;}
RECOMP_FUNC void bsdronegoto_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080034C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800350: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800354: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800358: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080035C: sw          $zero, 0x190($a0)
    MEM_W(0X190, ctx->r4) = 0;
    // 0x80800360: sw          $zero, 0x194($a0)
    MEM_W(0X194, ctx->r4) = 0;
    // 0x80800364: jal         0x80087AC0
    // 0x80800368: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _gcgoto_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800368: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800370: jal         0x80091E48
    // 0x80800374: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    func_80091E48(rdram, ctx);
        goto after_1;
    // 0x80800374: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_1:
    // 0x80800378: jal         0x8008E078
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_2;
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800380: bnel        $v0, $zero, L_808003AC
    if (ctx->r2 != 0) {
        // 0x80800384: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003AC;
    }
    goto skip_0;
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800388: jal         0x800846B0
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badata_entrypoint_14(rdram, ctx);
        goto after_3;
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800390: beq         $v0, $zero, L_808003A8
    if (ctx->r2 == 0) {
        // 0x80800394: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003A8;
    }
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800398: jal         0x80800000
    // 0x8080039C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800000_bsdronegoto(rdram, ctx);
        goto after_4;
    // 0x8080039C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808003A0: b           L_808003B8
    // 0x808003A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003B8;
    // 0x808003A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003A8:
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003AC:
    // 0x808003AC: jal         0x80800000
    // 0x808003B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800000_bsdronegoto(rdram, ctx);
        goto after_5;
    // 0x808003B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x808003B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003B8:
    // 0x808003B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003C0: jr          $ra
    // 0x808003C4: nop

    return;
    // 0x808003C4: nop

;}
RECOMP_FUNC void _gccubeDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087C70: syscall     655
    recomp_syscall_handler(rdram, ctx, 0x80087C70);
    return;
    // 0x80087C74: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800000_chpufferfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x8008A498
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddieDll_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: bne         $v0, $zero, L_80800028
    if (ctx->r2 != 0) {
        // 0x80800014: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800028;
    }
    // 0x80800014: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800018: jal         0x800FFAB0
    // 0x8080001C: nop

    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x8080001C: nop

    after_1:
    // 0x80800020: b           L_80800034
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800034;
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800028:
    // 0x80800028: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8080002C: swc1        $f4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f4.u32l;
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800034:
    // 0x80800034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800038: jr          $ra
    // 0x8080003C: nop

    return;
    // 0x8080003C: nop

;}
RECOMP_FUNC void func_80800AF0_chmineprospector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AF0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800AF4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800AF8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800AFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B00: jal         0x80100094
    // 0x80800B04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800B04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800B08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B0C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800B10: jal         0x800897D8
    // 0x80800B14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80800B14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800B18: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800B1C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800B20: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80800B24: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800B28: jal         0x8008FB10
    // 0x80800B2C: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    func_8008FB10(rdram, ctx);
        goto after_2;
    // 0x80800B2C: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    after_2:
    // 0x80800B30: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80800B34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800B38: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800B3C: beq         $t6, $at, L_80800B54
    if (ctx->r14 == ctx->r1) {
        // 0x80800B40: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800B54;
    }
    // 0x80800B40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800B44: beq         $t6, $at, L_80800BD8
    if (ctx->r14 == ctx->r1) {
        // 0x80800B48: nop
    
            goto L_80800BD8;
    }
    // 0x80800B48: nop

    // 0x80800B4C: b           L_80800BE4
    // 0x80800B50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800BE4;
    // 0x80800B50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800B54:
    // 0x80800B54: jal         0x80105834
    // 0x80800B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_3;
    // 0x80800B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800B5C: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800B60: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800B64: jal         0x80105998
    // 0x80800B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105998(rdram, ctx);
        goto after_4;
    // 0x80800B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800B6C: beq         $v0, $zero, L_80800B8C
    if (ctx->r2 == 0) {
        // 0x80800B70: addiu       $a1, $zero, 0xF91
        ctx->r5 = ADD32(0, 0XF91);
            goto L_80800B8C;
    }
    // 0x80800B70: addiu       $a1, $zero, 0xF91
    ctx->r5 = ADD32(0, 0XF91);
    // 0x80800B74: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800B78: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80800B7C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800B80: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800B84: jal         0x8008A208
    // 0x80800B88: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80800B88: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_5:
L_80800B8C:
    // 0x80800B8C: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x80800B90: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800B94: jal         0x80105998
    // 0x80800B98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105998(rdram, ctx);
        goto after_6;
    // 0x80800B98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800B9C: beq         $v0, $zero, L_80800BB0
    if (ctx->r2 == 0) {
        // 0x80800BA0: addiu       $a0, $zero, 0x143
        ctx->r4 = ADD32(0, 0X143);
            goto L_80800BB0;
    }
    // 0x80800BA0: addiu       $a0, $zero, 0x143
    ctx->r4 = ADD32(0, 0X143);
    // 0x80800BA4: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x80800BA8: jal         0x80101180
    // 0x80800BAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_7;
    // 0x80800BAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
L_80800BB0:
    // 0x80800BB0: jal         0x80105A5C
    // 0x80800BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_8;
    // 0x80800BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800BB8: beq         $v0, $zero, L_80800BC8
    if (ctx->r2 == 0) {
        // 0x80800BBC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BC8;
    }
    // 0x80800BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BC0: jal         0x80102424
    // 0x80800BC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x80800BC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
L_80800BC8:
    // 0x80800BC8: jal         0x80800D34
    // 0x80800BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800D34_chmineprospector(rdram, ctx);
        goto after_10;
    // 0x80800BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800BD0: b           L_80800BE4
    // 0x80800BD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800BE4;
    // 0x80800BD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800BD8:
    // 0x80800BD8: jal         0x80800D8C
    // 0x80800BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800D8C_chmineprospector(rdram, ctx);
        goto after_11;
    // 0x80800BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800BE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800BE4:
    // 0x80800BE4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800BE8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800BEC: jr          $ra
    // 0x80800BF0: nop

    return;
    // 0x80800BF0: nop

;}
RECOMP_FUNC void func_800DF4CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF4CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DF4D0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800DF4D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DF4D8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800DF4DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF4E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DF4E4: sw          $t6, -0x3648($at)
    MEM_W(-0X3648, ctx->r1) = ctx->r14;
    // 0x800DF4E8: jal         0x800EE7F8
    // 0x800DF4EC: addiu       $a0, $a0, -0x3644
    ctx->r4 = ADD32(ctx->r4, -0X3644);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800DF4EC: addiu       $a0, $a0, -0x3644
    ctx->r4 = ADD32(ctx->r4, -0X3644);
    after_0:
    // 0x800DF4F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DF4F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DF4F8: jr          $ra
    // 0x800DF4FC: nop

    return;
    // 0x800DF4FC: nop

;}
RECOMP_FUNC void bsblongleg_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080104C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801050: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801054: jal         0x8009BC6C
    // 0x80801058: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baphysics_reset_gravity(rdram, ctx);
        goto after_0;
    // 0x80801058: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080105C: jal         0x80800204
    // 0x80801060: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800204_bsblongleg(rdram, ctx);
        goto after_1;
    // 0x80801060: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080106C: jr          $ra
    // 0x80801070: nop

    return;
    // 0x80801070: nop

;}
RECOMP_FUNC void func_808017D0_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808017D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808017D8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1060, 0X2A48) << 16);
    // 0x808017DC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1060, 0X2C4C) << 16);
    // 0x808017E0: addiu       $a3, $a3, 0x2C4C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1060, 0X2C4C));
    // 0x808017E4: addiu       $a2, $a2, 0x2A48
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1060, 0X2A48));
    // 0x808017E8: jal         0x80089D28
    // 0x808017EC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808017EC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x808017F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808017F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808017F8: jr          $ra
    // 0x808017FC: nop

    return;
    // 0x808017FC: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082CA8: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082CA8);
    return;
    // 0x80082CAC: addi        $t0, $zero, 0x74
    ctx->r8 = ADD32(0, 0X74);
;}
RECOMP_FUNC void func_808017F0_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808017F4: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x808017F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808017FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801800: beq         $a1, $at, L_80801878
    if (ctx->r5 == ctx->r1) {
        // 0x80801804: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80801878;
    }
    // 0x80801804: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80801808: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x8080180C: beq         $a1, $at, L_808018BC
    if (ctx->r5 == ctx->r1) {
        // 0x80801810: addiu       $at, $zero, 0x2A
        ctx->r1 = ADD32(0, 0X2A);
            goto L_808018BC;
    }
    // 0x80801810: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x80801814: beq         $a1, $at, L_808018E8
    if (ctx->r5 == ctx->r1) {
        // 0x80801818: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_808018E8;
    }
    // 0x80801818: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8080181C: beq         $a1, $at, L_80801838
    if (ctx->r5 == ctx->r1) {
        // 0x80801820: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80801838;
    }
    // 0x80801820: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801824: addiu       $at, $zero, 0x99
    ctx->r1 = ADD32(0, 0X99);
    // 0x80801828: beql        $a1, $at, L_8080184C
    if (ctx->r5 == ctx->r1) {
        // 0x8080182C: lw          $t6, 0x64($a3)
        ctx->r14 = MEM_W(ctx->r7, 0X64);
            goto L_8080184C;
    }
    goto skip_0;
    // 0x8080182C: lw          $t6, 0x64($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X64);
    skip_0:
    // 0x80801830: b           L_80801920
    // 0x80801834: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801920;
    // 0x80801834: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801838:
    // 0x80801838: jal         0x80801930
    // 0x8080183C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80801930_chmonsterinterior(rdram, ctx);
        goto after_0;
    // 0x8080183C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x80801840: b           L_80801920
    // 0x80801844: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801920;
    // 0x80801844: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801848: lw          $t6, 0x64($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X64);
L_8080184C:
    // 0x8080184C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1320, 0X1E58) << 16);
    // 0x80801850: addiu       $a0, $a0, 0x1E58
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1320, 0X1E58));
    // 0x80801854: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80801858: bgez        $t8, L_80801868
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8080185C: nop
    
            goto L_80801868;
    }
    // 0x8080185C: nop

    // 0x80801860: b           L_80801868
    // 0x80801864: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80801868;
    // 0x80801864: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80801868:
    // 0x80801868: jal         0x80101074
    // 0x8080186C: nop

    func_80101074(rdram, ctx);
        goto after_1;
    // 0x8080186C: nop

    after_1:
    // 0x80801870: b           L_80801920
    // 0x80801874: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801920;
    // 0x80801874: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801878:
    // 0x80801878: lw          $t9, 0x64($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X64);
    // 0x8080187C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80801880: sll         $t1, $t9, 11
    ctx->r9 = S32(ctx->r25 << 11);
    // 0x80801884: bgez        $t1, L_808018AC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80801888: nop
    
            goto L_808018AC;
    }
    // 0x80801888: nop

    // 0x8080188C: lw          $a1, 0x6C($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X6C);
    // 0x80801890: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801894: sll         $t2, $a1, 11
    ctx->r10 = S32(ctx->r5 << 11);
    // 0x80801898: srl         $t3, $t2, 20
    ctx->r11 = S32(U32(ctx->r10) >> 20);
    // 0x8080189C: jal         0x8010DD20
    // 0x808018A0: addiu       $a1, $t3, -0x44B
    ctx->r5 = ADD32(ctx->r11, -0X44B);
    func_8010DD20(rdram, ctx);
        goto after_2;
    // 0x808018A0: addiu       $a1, $t3, -0x44B
    ctx->r5 = ADD32(ctx->r11, -0X44B);
    after_2:
    // 0x808018A4: b           L_80801920
    // 0x808018A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801920;
    // 0x808018A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808018AC:
    // 0x808018AC: jal         0x801015D0
    // 0x808018B0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_801015D0(rdram, ctx);
        goto after_3;
    // 0x808018B0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x808018B4: b           L_80801920
    // 0x808018B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801920;
    // 0x808018B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808018BC:
    // 0x808018BC: lw          $t4, 0x64($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X64);
    // 0x808018C0: sll         $t6, $t4, 11
    ctx->r14 = S32(ctx->r12 << 11);
    // 0x808018C4: bgezl       $t6, L_80801920
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808018C8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80801920;
    }
    goto skip_1;
    // 0x808018C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x808018CC: lw          $a0, 0x6C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X6C);
    // 0x808018D0: sll         $t7, $a0, 11
    ctx->r15 = S32(ctx->r4 << 11);
    // 0x808018D4: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x808018D8: jal         0x8010DC50
    // 0x808018DC: addiu       $a0, $t8, -0x44B
    ctx->r4 = ADD32(ctx->r24, -0X44B);
    func_8010DC50(rdram, ctx);
        goto after_4;
    // 0x808018DC: addiu       $a0, $t8, -0x44B
    ctx->r4 = ADD32(ctx->r24, -0X44B);
    after_4:
    // 0x808018E0: b           L_80801920
    // 0x808018E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801920;
    // 0x808018E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808018E8:
    // 0x808018E8: lw          $t9, 0x64($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X64);
    // 0x808018EC: sll         $t1, $t9, 11
    ctx->r9 = S32(ctx->r25 << 11);
    // 0x808018F0: bgezl       $t1, L_80801920
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808018F4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80801920;
    }
    goto skip_2;
    // 0x808018F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x808018F8: lw          $a0, 0x6C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X6C);
    // 0x808018FC: sll         $t2, $a0, 11
    ctx->r10 = S32(ctx->r4 << 11);
    // 0x80801900: srl         $t3, $t2, 20
    ctx->r11 = S32(U32(ctx->r10) >> 20);
    // 0x80801904: jal         0x8010DCB4
    // 0x80801908: addiu       $a0, $t3, -0x44B
    ctx->r4 = ADD32(ctx->r11, -0X44B);
    func_8010DCB4(rdram, ctx);
        goto after_5;
    // 0x80801908: addiu       $a0, $t3, -0x44B
    ctx->r4 = ADD32(ctx->r11, -0X44B);
    after_5:
    // 0x8080190C: b           L_80801920
    // 0x80801910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801920;
    // 0x80801910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801914: b           L_80801920
    // 0x80801918: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801920;
    // 0x80801918: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080191C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801920:
    // 0x80801920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801928: jr          $ra
    // 0x8080192C: nop

    return;
    // 0x8080192C: nop

;}
RECOMP_FUNC void func_800EF2A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF2A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EF2A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EF2A8: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EF2AC: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EF2B0: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EF2B4: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800EF2B8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800EF2BC: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800EF2C0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EF2C4: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800EF2C8: add.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800EF2CC: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    // 0x800EF2D0: nop

    // 0x800EF2D4: bc1tl       L_800EF328
    if (c1cs) {
        // 0x800EF2D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800EF328;
    }
    goto skip_0;
    // 0x800EF2D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800EF2DC: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x800EF2E0: jal         0x8002DCA0
    // 0x800EF2E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800EF2E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800EF2E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800EF2EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800EF2F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800EF2F4: div.s       $f2, $f18, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800EF2F8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EF2FC: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EF300: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EF304: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800EF308: nop

    // 0x800EF30C: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800EF310: nop

    // 0x800EF314: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800EF318: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800EF31C: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x800EF320: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x800EF324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EF328:
    // 0x800EF328: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EF32C: jr          $ra
    // 0x800EF330: nop

    return;
    // 0x800EF330: nop

;}
RECOMP_FUNC void func_8080121C_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080121C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801220: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801224: jal         0x80800E54
    // 0x80801228: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bstnt_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80801228: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080122C: jal         0x80082FF0
    // 0x80801230: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80801230: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801238: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080123C: jr          $ra
    // 0x80801240: nop

    return;
    // 0x80801240: nop

;}
RECOMP_FUNC void rtlight_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800130: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800138: jal         0x8001B084
    // 0x8080013C: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x8080013C: nop

    after_0:
    // 0x80800140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800148: jr          $ra
    // 0x8080014C: nop

    return;
    // 0x8080014C: nop

;}
RECOMP_FUNC void func_80112C3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112C3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80112C40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80112C44: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80112C48: lw          $v0, 0x60($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X60);
    // 0x80112C4C: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80112C50: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80112C54: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80112C58: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80112C5C: beq         $at, $zero, L_80112CF4
    if (ctx->r1 == 0) {
        // 0x80112C60: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80112CF4;
    }
    // 0x80112C60: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80112C64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80112C68: addu        $at, $at, $t7
    gpr jr_addend_80112C70 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80112C6C: lw          $t7, 0x6594($at)
    ctx->r15 = ADD32(ctx->r1, 0X6594);
    // 0x80112C70: jr          $t7
    // 0x80112C74: nop

    switch (jr_addend_80112C70 >> 2) {
        case 0: goto L_80112C78; break;
        case 1: goto L_80112C78; break;
        case 2: goto L_80112C90; break;
        case 3: goto L_80112CC4; break;
        case 4: goto L_80112C78; break;
        default: switch_error(__func__, 0x80112C70, 0x80126594);
    }
    // 0x80112C74: nop

L_80112C78:
    // 0x80112C78: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80112C7C: lwc1        $f14, 0x0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80112C80: jal         0x800F1738
    // 0x80112C84: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    func_800F1738(rdram, ctx);
        goto after_0;
    // 0x80112C84: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    after_0:
    // 0x80112C88: b           L_80112CF4
    // 0x80112C8C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
        goto L_80112CF4;
    // 0x80112C8C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80112C90:
    // 0x80112C90: lwc1        $f14, 0x0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80112C94: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80112C98: jal         0x800F1DCC
    // 0x80112C9C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800F1DCC(rdram, ctx);
        goto after_1;
    // 0x80112C9C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x80112CA0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80112CA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80112CA8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80112CAC: nop

    // 0x80112CB0: bc1fl       L_80112CF8
    if (!c1cs) {
        // 0x80112CB4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80112CF8;
    }
    goto skip_0;
    // 0x80112CB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80112CB8: lw          $t8, 0x60($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X60);
    // 0x80112CBC: b           L_80112CF4
    // 0x80112CC0: lwc1        $f20, 0x0($t8)
    ctx->f20.u32l = MEM_W(ctx->r24, 0X0);
        goto L_80112CF4;
    // 0x80112CC0: lwc1        $f20, 0x0($t8)
    ctx->f20.u32l = MEM_W(ctx->r24, 0X0);
L_80112CC4:
    // 0x80112CC4: lwc1        $f14, 0x0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80112CC8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80112CCC: jal         0x800F1DCC
    // 0x80112CD0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800F1DCC(rdram, ctx);
        goto after_2;
    // 0x80112CD0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x80112CD4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80112CD8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80112CDC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80112CE0: nop

    // 0x80112CE4: bc1fl       L_80112CF8
    if (!c1cs) {
        // 0x80112CE8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80112CF8;
    }
    goto skip_1;
    // 0x80112CE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80112CEC: lw          $t9, 0x60($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X60);
    // 0x80112CF0: lwc1        $f20, 0x0($t9)
    ctx->f20.u32l = MEM_W(ctx->r25, 0X0);
L_80112CF4:
    // 0x80112CF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80112CF8:
    // 0x80112CF8: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x80112CFC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80112D00: jr          $ra
    // 0x80112D04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80112D04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800934_chspotlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800934: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800938: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x8080093C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800940: bne         $a1, $at, L_80800958
    if (ctx->r5 != ctx->r1) {
        // 0x80800944: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800958;
    }
    // 0x80800944: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800948: jal         0x8080047C
    // 0x8080094C: nop

    func_8080047C_chspotlight(rdram, ctx);
        goto after_0;
    // 0x8080094C: nop

    after_0:
    // 0x80800950: b           L_8080095C
    // 0x80800954: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080095C;
    // 0x80800954: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800958:
    // 0x80800958: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080095C:
    // 0x8080095C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800960: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800964: jr          $ra
    // 0x80800968: nop

    return;
    // 0x80800968: nop

    // 0x8080096C: nop

;}
RECOMP_FUNC void _basudie_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085218: syscall     155
    recomp_syscall_handler(rdram, ctx, 0x80085218);
    return;
    // 0x8008521C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80804AF0_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804AF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804AF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804AF8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80804AFC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80804B00: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x80804B04: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80804B08: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80804B0C: blez        $t6, L_80804B3C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80804B10: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_80804B3C;
    }
    // 0x80804B10: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80804B14: jal         0x80087D38
    // 0x80804B18: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _gcnewoption_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80804B18: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80804B1C: addiu       $a2, $v0, -0x1
    ctx->r6 = ADD32(ctx->r2, -0X1);
    // 0x80804B20: bgez        $a2, L_80804B30
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80804B24: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_80804B30;
    }
    // 0x80804B24: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80804B28: lw          $a2, 0x18($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X18);
    // 0x80804B2C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_80804B30:
    // 0x80804B30: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80804B34: jal         0x808049E8
    // 0x80804B38: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_808049E8_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80804B38: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
L_80804B3C:
    // 0x80804B3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804B40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804B44: jr          $ra
    // 0x80804B48: nop

    return;
    // 0x80804B48: nop

;}
RECOMP_FUNC void func_80092AD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092AD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80092ADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80092AE0: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80092AE4: jal         0x800AE080
    // 0x80092AE8: lh          $a0, 0x0($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X0);
    func_800AE080(rdram, ctx);
        goto after_0;
    // 0x80092AE8: lh          $a0, 0x0($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X0);
    after_0:
    // 0x80092AEC: jal         0x800AE6BC
    // 0x80092AF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800AE6BC(rdram, ctx);
        goto after_1;
    // 0x80092AF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80092AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80092AF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80092AFC: jr          $ra
    // 0x80092B00: nop

    return;
    // 0x80092B00: nop

;}
RECOMP_FUNC void func_800140D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800140D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800140DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800140E0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800140E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800140E8: beq         $v0, $at, L_80014100
    if (ctx->r2 == ctx->r1) {
        // 0x800140EC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80014100;
    }
    // 0x800140EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800140F0: beq         $v0, $at, L_80014110
    if (ctx->r2 == ctx->r1) {
        // 0x800140F4: nop
    
            goto L_80014110;
    }
    // 0x800140F4: nop

    // 0x800140F8: b           L_8001411C
    // 0x800140FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001411C;
    // 0x800140FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80014100:
    // 0x80014100: jal         0x80013EF0
    // 0x80014104: nop

    func_80013EF0(rdram, ctx);
        goto after_0;
    // 0x80014104: nop

    after_0:
    // 0x80014108: b           L_8001411C
    // 0x8001410C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001411C;
    // 0x8001410C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80014110:
    // 0x80014110: jal         0x80013FE4
    // 0x80014114: nop

    func_80013FE4(rdram, ctx);
        goto after_1;
    // 0x80014114: nop

    after_1:
    // 0x80014118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001411C:
    // 0x8001411C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80014120: jr          $ra
    // 0x80014124: nop

    return;
    // 0x80014124: nop

;}
RECOMP_FUNC void _suexpression_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089828: syscall     795
    recomp_syscall_handler(rdram, ctx, 0x80089828);
    return;
    // 0x8008982C: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void func_808000C4_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808000C8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x808000CC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x808000D0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2484, 0X7010) << 16);
    // 0x808000D4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808000D8: jr          $ra
    // 0x808000DC: lw          $v0, 0x7010($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(2484, 0X7010));
    return;
    // 0x808000DC: lw          $v0, 0x7010($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(2484, 0X7010));
;}
RECOMP_FUNC void subaddietaxi_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800534: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800538: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080053C: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800540: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800544: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800548: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080054C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800550: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800554: jal         0x800EFA4C
    // 0x80800558: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x80800558: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8080055C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800560: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80800564: jal         0x800DFF64
    // 0x80800568: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_800DFF64(rdram, ctx);
        goto after_1;
    // 0x80800568: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x8080056C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800570: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800574: jr          $ra
    // 0x80800578: nop

    return;
    // 0x80800578: nop

;}
RECOMP_FUNC void _suquiz_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A890: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A890);
    return;
    // 0x8008A894: addi        $t0, $zero, 0x6C
    ctx->r8 = ADD32(0, 0X6C);
;}
RECOMP_FUNC void func_80802048_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802048: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8080204C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80802050: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80802054: lwc1        $f26, 0xC8($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80802058: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080205C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80802060: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802064: mul.s       $f26, $f26, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f6.fl);
    // 0x80802068: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8080206C: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x80802070: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x80802074: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x80802078: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x8080207C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80802080: c.lt.s      $f26, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f26.fl < ctx->f8.fl;
    // 0x80802084: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80802088: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8080208C: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x80802090: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80802094: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80802098: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x8080209C: bc1t        L_808022E0
    if (c1cs) {
        // 0x808020A0: swc1        $f4, 0xB4($sp)
        MEM_W(0XB4, ctx->r29) = ctx->f4.u32l;
            goto L_808022E0;
    }
    // 0x808020A0: swc1        $f4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f4.u32l;
    // 0x808020A4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808020A8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x808020AC: jal         0x800EFB8C
    // 0x808020B0: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    func_800EFB8C(rdram, ctx);
        goto after_0;
    // 0x808020B0: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    after_0:
    // 0x808020B4: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x808020B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808020BC: jal         0x800EFB8C
    // 0x808020C0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EFB8C(rdram, ctx);
        goto after_1;
    // 0x808020C0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_1:
    // 0x808020C4: sub.s       $f10, $f0, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x808020C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808020CC: c.lt.s      $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f24.fl < ctx->f10.fl;
    // 0x808020D0: nop

    // 0x808020D4: bc1tl       L_808022E4
    if (c1cs) {
        // 0x808020D8: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_808022E4;
    }
    goto skip_0;
    // 0x808020D8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x808020DC: jal         0x800EFB8C
    // 0x808020E0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EFB8C(rdram, ctx);
        goto after_2;
    // 0x808020E0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x808020E4: swc1        $f0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f0.u32l;
    // 0x808020E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808020EC: jal         0x800F1DF4
    // 0x808020F0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800F1DF4(rdram, ctx);
        goto after_3;
    // 0x808020F0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_3:
    // 0x808020F4: swc1        $f0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f0.u32l;
    // 0x808020F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808020FC: jal         0x800F1DF4
    // 0x80802100: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
    func_800F1DF4(rdram, ctx);
        goto after_4;
    // 0x80802100: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
    after_4:
    // 0x80802104: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80802108: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080210C: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80802110: addiu       $s0, $sp, 0x84
    ctx->r16 = ADD32(ctx->r29, 0X84);
    // 0x80802114: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x80802118: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8080211C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80802120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802124: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80802128: jal         0x800EEB9C
    // 0x8080212C: nop

    func_800EEB9C(rdram, ctx);
        goto after_5;
    // 0x8080212C: nop

    after_5:
    // 0x80802130: addiu       $s1, $sp, 0x90
    ctx->r17 = ADD32(ctx->r29, 0X90);
    // 0x80802134: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802138: jal         0x800EE7F8
    // 0x8080213C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x8080213C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80802140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802144: jal         0x800EF04C
    // 0x80802148: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x80802148: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_7:
    // 0x8080214C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802150: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80802154: jal         0x800EFB24
    // 0x80802158: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800EFB24(rdram, ctx);
        goto after_8;
    // 0x80802158: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_8:
    // 0x8080215C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802160: jal         0x800F1DF4
    // 0x80802164: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800F1DF4(rdram, ctx);
        goto after_9;
    // 0x80802164: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x80802168: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080216C: jal         0x800F2094
    // 0x80802170: lwc1        $f14, 0xA8($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XA8);
    func_800F2094(rdram, ctx);
        goto after_10;
    // 0x80802170: lwc1        $f14, 0xA8($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XA8);
    after_10:
    // 0x80802174: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80802178: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8080217C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80802180: jal         0x800F20BC
    // 0x80802184: lwc1        $f14, 0xA8($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XA8);
    func_800F20BC(rdram, ctx);
        goto after_11;
    // 0x80802184: lwc1        $f14, 0xA8($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XA8);
    after_11:
    // 0x80802188: beq         $v0, $zero, L_808022D4
    if (ctx->r2 == 0) {
        // 0x8080218C: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_808022D4;
    }
    // 0x8080218C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80802190: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80802194: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80802198: mul.s       $f6, $f26, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f2.fl);
    // 0x8080219C: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808021A0: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x808021A4: nop

    // 0x808021A8: bc1f        L_808021B4
    if (!c1cs) {
        // 0x808021AC: nop
    
            goto L_808021B4;
    }
    // 0x808021AC: nop

    // 0x808021B0: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
L_808021B4:
    // 0x808021B4: mul.s       $f0, $f22, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x808021B8: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x808021BC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x808021C0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808021C4: jal         0x800F20BC
    // 0x808021C8: add.s       $f14, $f0, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f10.fl;
    func_800F20BC(rdram, ctx);
        goto after_12;
    // 0x808021C8: add.s       $f14, $f0, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f10.fl;
    after_12:
    // 0x808021CC: beq         $v0, $zero, L_808021E0
    if (ctx->r2 == 0) {
        // 0x808021D0: lwc1        $f18, 0xA8($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0XA8);
            goto L_808021E0;
    }
    // 0x808021D0: lwc1        $f18, 0xA8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x808021D4: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x808021D8: b           L_808021E4
    // 0x808021DC: add.s       $f20, $f16, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f16.fl + ctx->f22.fl;
        goto L_808021E4;
    // 0x808021DC: add.s       $f20, $f16, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f16.fl + ctx->f22.fl;
L_808021E0:
    // 0x808021E0: sub.s       $f20, $f18, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f18.fl - ctx->f22.fl;
L_808021E4:
    // 0x808021E4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808021E8: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x808021EC: jal         0x800EEB9C
    // 0x808021F0: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    func_800EEB9C(rdram, ctx);
        goto after_13;
    // 0x808021F0: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    after_13:
    // 0x808021F4: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x808021F8: jal         0x800EF04C
    // 0x808021FC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EF04C(rdram, ctx);
        goto after_14;
    // 0x808021FC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_14:
    // 0x80802200: addiu       $s1, $sp, 0x5C
    ctx->r17 = ADD32(ctx->r29, 0X5C);
    // 0x80802204: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802208: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
    // 0x8080220C: jal         0x800EFB24
    // 0x80802210: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800EFB24(rdram, ctx);
        goto after_15;
    // 0x80802210: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_15:
    // 0x80802214: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80802218: beq         $v0, $zero, L_808022B8
    if (ctx->r2 == 0) {
        // 0x8080221C: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_808022B8;
    }
    // 0x8080221C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80802220:
    // 0x80802220: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80802224: addiu       $t6, $sp, 0x6C
    ctx->r14 = ADD32(ctx->r29, 0X6C);
    // 0x80802228: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080222C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802230: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80802234: jal         0x800F05F8
    // 0x80802238: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800F05F8(rdram, ctx);
        goto after_16;
    // 0x80802238: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_16:
    // 0x8080223C: beq         $v0, $zero, L_808022A8
    if (ctx->r2 == 0) {
        // 0x80802240: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808022A8;
    }
    // 0x80802240: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80802244: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802248: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080224C: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80802250: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80802254: nop

    // 0x80802258: bc1f        L_808022A8
    if (!c1cs) {
        // 0x8080225C: nop
    
            goto L_808022A8;
    }
    // 0x8080225C: nop

    // 0x80802260: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80802264: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80802268: c.lt.s      $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f22.fl < ctx->f8.fl;
    // 0x8080226C: nop

    // 0x80802270: bc1f        L_80802280
    if (!c1cs) {
        // 0x80802274: nop
    
            goto L_80802280;
    }
    // 0x80802274: nop

    // 0x80802278: b           L_80802280
    // 0x8080227C: addiu       $v0, $zero, -0x5
    ctx->r2 = ADD32(0, -0X5);
        goto L_80802280;
    // 0x8080227C: addiu       $v0, $zero, -0x5
    ctx->r2 = ADD32(0, -0X5);
L_80802280:
    // 0x80802280: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80802284: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80802288: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080228C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80802290: sw          $v1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r3;
    // 0x80802294: add.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
    // 0x80802298: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080229C: jal         0x800EEB9C
    // 0x808022A0: nop

    func_800EEB9C(rdram, ctx);
        goto after_17;
    // 0x808022A0: nop

    after_17:
    // 0x808022A4: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
L_808022A8:
    // 0x808022A8: beq         $v1, $zero, L_808022B8
    if (ctx->r3 == 0) {
        // 0x808022AC: slti        $v0, $s0, 0x5
        ctx->r2 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
            goto L_808022B8;
    }
    // 0x808022AC: slti        $v0, $s0, 0x5
    ctx->r2 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x808022B0: bne         $v0, $zero, L_80802220
    if (ctx->r2 != 0) {
        // 0x808022B4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80802220;
    }
    // 0x808022B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808022B8:
    // 0x808022B8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808022BC: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x808022C0: jal         0x800EEB9C
    // 0x808022C4: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    func_800EEB9C(rdram, ctx);
        goto after_18;
    // 0x808022C4: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    after_18:
    // 0x808022C8: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x808022CC: jal         0x800EF04C
    // 0x808022D0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EF04C(rdram, ctx);
        goto after_19;
    // 0x808022D0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_19:
L_808022D4:
    // 0x808022D4: lwc1        $f18, 0xB4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x808022D8: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x808022DC: swc1        $f18, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f18.u32l;
L_808022E0:
    // 0x808022E0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_808022E4:
    // 0x808022E4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808022E8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808022EC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808022F0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808022F4: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x808022F8: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x808022FC: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x80802300: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x80802304: jr          $ra
    // 0x80802308: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80802308: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_800A1718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1718: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A171C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A1720: lw          $t6, 0x158($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X158);
    // 0x800A1724: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800A1728: beq         $t6, $zero, L_800A1740
    if (ctx->r14 == 0) {
        // 0x800A172C: nop
    
            goto L_800A1740;
    }
    // 0x800A172C: nop

    // 0x800A1730: jal         0x800F9F04
    // 0x800A1734: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    func_800F9F04(rdram, ctx);
        goto after_0;
    // 0x800A1734: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    after_0:
    // 0x800A1738: b           L_800A1754
    // 0x800A173C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A1754;
    // 0x800A173C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A1740:
    // 0x800A1740: jal         0x800A3274
    // 0x800A1744: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800A3274(rdram, ctx);
        goto after_1;
    // 0x800A1744: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x800A1748: jal         0x800D4E7C
    // 0x800A174C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D4E7C(rdram, ctx);
        goto after_2;
    // 0x800A174C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800A1750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A1754:
    // 0x800A1754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A1758: jr          $ra
    // 0x800A175C: nop

    return;
    // 0x800A175C: nop

;}
RECOMP_FUNC void func_80800360_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800360: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800364: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800368: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080036C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800370: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80800374: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800378: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8080037C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800380: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800384: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    // 0x80800388: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8080038C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800390: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80800394:
    // 0x80800394: add.s       $f22, $f24, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = ctx->f24.fl + ctx->f20.fl;
    // 0x80800398: jal         0x808002A4
    // 0x8080039C: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_808002A4_chbanjoctrl(rdram, ctx);
        goto after_0;
    // 0x8080039C: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_0:
    // 0x808003A0: beql        $v0, $zero, L_808003B4
    if (ctx->r2 == 0) {
        // 0x808003A4: sub.s       $f22, $f24, $f20
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = ctx->f24.fl - ctx->f20.fl;
            goto L_808003B4;
    }
    goto skip_0;
    // 0x808003A4: sub.s       $f22, $f24, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = ctx->f24.fl - ctx->f20.fl;
    skip_0:
    // 0x808003A8: b           L_808003D8
    // 0x808003AC: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
        goto L_808003D8;
    // 0x808003AC: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    // 0x808003B0: sub.s       $f22, $f24, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = ctx->f24.fl - ctx->f20.fl;
L_808003B4:
    // 0x808003B4: jal         0x808002A4
    // 0x808003B8: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_808002A4_chbanjoctrl(rdram, ctx);
        goto after_1;
    // 0x808003B8: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_1:
    // 0x808003BC: beq         $v0, $zero, L_808003CC
    if (ctx->r2 == 0) {
        // 0x808003C0: nop
    
            goto L_808003CC;
    }
    // 0x808003C0: nop

    // 0x808003C4: b           L_808003D8
    // 0x808003C8: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
        goto L_808003D8;
    // 0x808003C8: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
L_808003CC:
    // 0x808003CC: beq         $s0, $zero, L_80800394
    if (ctx->r16 == 0) {
        // 0x808003D0: add.s       $f20, $f20, $f26
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
            goto L_80800394;
    }
    // 0x808003D0: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    // 0x808003D4: mov.s       $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    ctx->f0.fl = ctx->f24.fl;
L_808003D8:
    // 0x808003D8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x808003DC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808003E0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808003E4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808003E8: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808003EC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x808003F0: jr          $ra
    // 0x808003F4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x808003F4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void chmole_training_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CB0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1604, 0XF30) << 16);
    // 0x80800CB4: jr          $ra
    // 0x80800CB8: addiu       $v0, $v0, 0xF30
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1604, 0XF30));
    return;
    // 0x80800CB8: addiu       $v0, $v0, 0xF30
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1604, 0XF30));
    // 0x80800CBC: nop

;}
RECOMP_FUNC void gcstatusDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x808000C4: jr          $ra
    // 0x808000C8: sb          $a0, -0x4BF7($at)
    MEM_B(-0X4BF7, ctx->r1) = ctx->r4;
    return;
    // 0x808000C8: sb          $a0, -0x4BF7($at)
    MEM_B(-0X4BF7, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_800C2A68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2A68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2A6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2A70: jal         0x80017244
    // 0x800C2A74: nop

    func_80017244(rdram, ctx);
        goto after_0;
    // 0x800C2A74: nop

    after_0:
    // 0x800C2A78: jal         0x80016E7C
    // 0x800C2A7C: nop

    func_80016E7C(rdram, ctx);
        goto after_1;
    // 0x800C2A7C: nop

    after_1:
    // 0x800C2A80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C2A84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C2A88: jr          $ra
    // 0x800C2A8C: nop

    return;
    // 0x800C2A8C: nop

;}
RECOMP_FUNC void bababykaz_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808003F8: jal         0x80095760
    // 0x808003FC: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    baflag_set(rdram, ctx);
        goto after_0;
    // 0x808003FC: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    after_0:
    // 0x80800400: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800404: jal         0x8009F198
    // 0x80800408: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bastick_func_8009F198(rdram, ctx);
        goto after_1;
    // 0x80800408: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080040C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800410: jal         0x80091C74
    // 0x80800414: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_func_80091C74(rdram, ctx);
        goto after_2;
    // 0x80800414: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080041C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800420: jr          $ra
    // 0x80800424: nop

    return;
    // 0x80800424: nop

;}
RECOMP_FUNC void suspline_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808001E8: jr          $ra
    // 0x808001EC: swc1        $f12, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x808001EC: swc1        $f12, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void _gcnewoption_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087D90: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087D90);
    return;
    // 0x80087D94: addi        $t0, $zero, 0x7C
    ctx->r8 = ADD32(0, 0X7C);
;}
RECOMP_FUNC void chboggykidshome_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1396, 0X4F8) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x4F8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1396, 0X4F8));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x4F8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1396, 0X4F8));
;}
RECOMP_FUNC void gcnewoption_entrypoint_39(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802C68: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802C6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802C70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802C74: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x80802C78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802C7C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80802C80: beq         $v0, $at, L_80802C94
    if (ctx->r2 == ctx->r1) {
        // 0x80802C84: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802C94;
    }
    // 0x80802C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802C88: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80802C8C: bnel        $v0, $at, L_80802CE0
    if (ctx->r2 != ctx->r1) {
        // 0x80802C90: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80802CE0;
    }
    goto skip_0;
    // 0x80802C90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_80802C94:
    // 0x80802C94: jal         0x80800038
    // 0x80802C98: lh          $a1, 0x6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X6);
    func_80800038_gcnewoption(rdram, ctx);
        goto after_0;
    // 0x80802C98: lh          $a1, 0x6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X6);
    after_0:
    // 0x80802C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802CA0: jal         0x80800000
    // 0x80802CA4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800000_gcnewoption(rdram, ctx);
        goto after_1;
    // 0x80802CA4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80802CA8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80802CAC: jal         0x80802A9C
    // 0x80802CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802A9C_gcnewoption(rdram, ctx);
        goto after_2;
    // 0x80802CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80802CB4: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80802CB8: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
    // 0x80802CBC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80802CC0: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    // 0x80802CC4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80802CC8: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x80802CCC: jal         0x80087C28
    // 0x80802CD0: lw          $a0, 0x3C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X3C);
    _gczoombox_entrypoint_41(rdram, ctx);
        goto after_3;
    // 0x80802CD0: lw          $a0, 0x3C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X3C);
    after_3:
    // 0x80802CD4: b           L_80802CE0
    // 0x80802CD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802CE0;
    // 0x80802CD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80802CDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802CE0:
    // 0x80802CE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802CE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802CE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802CEC: jr          $ra
    // 0x80802CF0: nop

    return;
    // 0x80802CF0: nop

;}
RECOMP_FUNC void boot___ll_mul(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002978: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8000297C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80002980: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80002984: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80002988: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x8000298C: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x80002990: dmultu      $t6, $t7
    DMULTU(U64(ctx->r14), U64(ctx->r15), &lo, &hi);
    // 0x80002994: mflo        $v0
    ctx->r2 = lo;
    // 0x80002998: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x8000299C: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x800029A0: jr          $ra
    // 0x800029A4: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    return;
    // 0x800029A4: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
;}
RECOMP_FUNC void func_8080223C_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080223C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80802240: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80802244: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80802248: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x8080224C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802250: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802254: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80802258: beq         $t6, $at, L_8080228C
    if (ctx->r14 == ctx->r1) {
        // 0x8080225C: lui         $a1, 0x3C23
        ctx->r5 = S32(0X3C23 << 16);
            goto L_8080228C;
    }
    // 0x8080225C: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x80802260: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802264: beq         $t6, $at, L_808026A8
    if (ctx->r14 == ctx->r1) {
        // 0x80802268: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808026A8;
    }
    // 0x80802268: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080226C: beq         $t6, $at, L_808024A8
    if (ctx->r14 == ctx->r1) {
        // 0x80802270: lui         $a1, 0x3DCC
        ctx->r5 = S32(0X3DCC << 16);
            goto L_808024A8;
    }
    // 0x80802270: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80802274: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80802278: beq         $t6, $at, L_808026CC
    if (ctx->r14 == ctx->r1) {
        // 0x8080227C: lui         $a1, 0x3D4C
        ctx->r5 = S32(0X3D4C << 16);
            goto L_808026CC;
    }
    // 0x8080227C: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x80802280: addiu       $t7, $a0, 0x4
    ctx->r15 = ADD32(ctx->r4, 0X4);
    // 0x80802284: b           L_808028A0
    // 0x80802288: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
        goto L_808028A0;
    // 0x80802288: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_8080228C:
    // 0x8080228C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802290: jal         0x80101E14
    // 0x80802294: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    func_80101E14(rdram, ctx);
        goto after_0;
    // 0x80802294: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    after_0:
    // 0x80802298: beql        $v0, $zero, L_808023C4
    if (ctx->r2 == 0) {
        // 0x8080229C: addiu       $t3, $s0, 0x4
        ctx->r11 = ADD32(ctx->r16, 0X4);
            goto L_808023C4;
    }
    goto skip_0;
    // 0x8080229C: addiu       $t3, $s0, 0x4
    ctx->r11 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x808022A0: jal         0x8010C754
    // 0x808022A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C754(rdram, ctx);
        goto after_1;
    // 0x808022A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808022A8: slti        $at, $v0, 0x5DC
    ctx->r1 = SIGNED(ctx->r2) < 0X5DC ? 1 : 0;
    // 0x808022AC: bne         $at, $zero, L_808022C4
    if (ctx->r1 != 0) {
        // 0x808022B0: nop
    
            goto L_808022C4;
    }
    // 0x808022B0: nop

    // 0x808022B4: jal         0x800DB9B0
    // 0x808022B8: nop

    func_800DB9B0(rdram, ctx);
        goto after_2;
    // 0x808022B8: nop

    after_2:
    // 0x808022BC: beql        $v0, $zero, L_808023C4
    if (ctx->r2 == 0) {
        // 0x808022C0: addiu       $t3, $s0, 0x4
        ctx->r11 = ADD32(ctx->r16, 0X4);
            goto L_808023C4;
    }
    goto skip_1;
    // 0x808022C0: addiu       $t3, $s0, 0x4
    ctx->r11 = ADD32(ctx->r16, 0X4);
    skip_1:
L_808022C4:
    // 0x808022C4: jal         0x800D3948
    // 0x808022C8: nop

    func_800D3948(rdram, ctx);
        goto after_3;
    // 0x808022C8: nop

    after_3:
    // 0x808022CC: bne         $v0, $zero, L_808022F0
    if (ctx->r2 != 0) {
        // 0x808022D0: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_808022F0;
    }
    // 0x808022D0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808022D4: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2384, 0X326C) << 16);
    // 0x808022D8: addiu       $t8, $t8, 0x326C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2384, 0X326C));
    // 0x808022DC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808022E0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808022E4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808022E8: jal         0x800BBCB8
    // 0x808022EC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_800BBCB8(rdram, ctx);
        goto after_4;
    // 0x808022EC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_4:
L_808022F0:
    // 0x808022F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2FA0) << 16);
    // 0x808022F4: lwc1        $f12, 0x2FA0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2FA0));
    // 0x808022F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2FA4) << 16);
    // 0x808022FC: addiu       $t9, $s0, 0x4
    ctx->r25 = ADD32(ctx->r16, 0X4);
    // 0x80802300: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80802304: jal         0x800DC178
    // 0x80802308: lwc1        $f14, 0x2FA4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2FA4));
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80802308: lwc1        $f14, 0x2FA4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2FA4));
    after_5:
    // 0x8080230C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2FA8) << 16);
    // 0x80802310: lwc1        $f4, 0x2FA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2FA8));
    // 0x80802314: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80802318: lui         $a2, 0x5DC
    ctx->r6 = S32(0X5DC << 16);
    // 0x8080231C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80802320: ori         $a2, $a2, 0x190
    ctx->r6 = ctx->r6 | 0X190;
    // 0x80802324: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80802328: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8080232C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80802330: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80802334: nop

    // 0x80802338: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8080233C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80802340: nop

    // 0x80802344: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80802348: beql        $a0, $zero, L_80802398
    if (ctx->r4 == 0) {
        // 0x8080234C: mfc1        $a0, $f8
        ctx->r4 = (int32_t)ctx->f8.u32l;
            goto L_80802398;
    }
    goto skip_2;
    // 0x8080234C: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    skip_2:
    // 0x80802350: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802354: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80802358: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8080235C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80802360: nop

    // 0x80802364: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80802368: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x8080236C: nop

    // 0x80802370: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80802374: bne         $a0, $zero, L_8080238C
    if (ctx->r4 != 0) {
        // 0x80802378: nop
    
            goto L_8080238C;
    }
    // 0x80802378: nop

    // 0x8080237C: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80802380: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80802384: b           L_808023A4
    // 0x80802388: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_808023A4;
    // 0x80802388: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_8080238C:
    // 0x8080238C: b           L_808023A4
    // 0x80802390: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_808023A4;
    // 0x80802390: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80802394: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
L_80802398:
    // 0x80802398: nop

    // 0x8080239C: bltz        $a0, L_8080238C
    if (SIGNED(ctx->r4) < 0) {
        // 0x808023A0: nop
    
            goto L_8080238C;
    }
    // 0x808023A0: nop

L_808023A4:
    // 0x808023A4: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x808023A8: lui         $at, 0x1F
    ctx->r1 = S32(0X1F << 16);
    // 0x808023AC: ori         $at, $at, 0xFCB7
    ctx->r1 = ctx->r1 | 0XFCB7;
    // 0x808023B0: sll         $t2, $t1, 21
    ctx->r10 = S32(ctx->r9 << 21);
    // 0x808023B4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x808023B8: jal         0x800C4140
    // 0x808023BC: addu        $a0, $t2, $at
    ctx->r4 = ADD32(ctx->r10, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_6;
    // 0x808023BC: addu        $a0, $t2, $at
    ctx->r4 = ADD32(ctx->r10, ctx->r1);
    after_6:
    // 0x808023C0: addiu       $t3, $s0, 0x4
    ctx->r11 = ADD32(ctx->r16, 0X4);
L_808023C4:
    // 0x808023C4: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x808023C8: jal         0x80101F24
    // 0x808023CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_7;
    // 0x808023CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808023D0: lui         $at, 0x4307
    ctx->r1 = S32(0X4307 << 16);
    // 0x808023D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808023D8: nop

    // 0x808023DC: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808023E0: jal         0x80013970
    // 0x808023E4: nop

    func_80013970(rdram, ctx);
        goto after_8;
    // 0x808023E4: nop

    after_8:
    // 0x808023E8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x808023EC: jal         0x80103EF4
    // 0x808023F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_9;
    // 0x808023F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808023F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2FAC) << 16);
    // 0x808023F8: lwc1        $f18, 0x2FAC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2FAC));
    // 0x808023FC: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x80802400: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802404: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80802408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080240C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80802410: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80802414: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80802418: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8080241C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80802420: jal         0x80101F24
    // 0x80802424: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    func_80101F24(rdram, ctx);
        goto after_10;
    // 0x80802424: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    after_10:
    // 0x80802428: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2FB0) << 16);
    // 0x8080242C: lwc1        $f6, 0x2FB0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2FB0));
    // 0x80802430: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2FB4) << 16);
    // 0x80802434: lwc1        $f4, 0x2FB4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2FB4));
    // 0x80802438: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8080243C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802440: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80802444: jal         0x80101DDC
    // 0x80802448: swc1        $f10, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f10.u32l;
    func_80101DDC(rdram, ctx);
        goto after_11;
    // 0x80802448: swc1        $f10, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f10.u32l;
    after_11:
    // 0x8080244C: beql        $v0, $zero, L_808028A4
    if (ctx->r2 == 0) {
        // 0x80802450: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_808028A4;
    }
    goto skip_3;
    // 0x80802450: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_3:
    // 0x80802454: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    // 0x80802458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080245C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80802460: sll         $t6, $t4, 11
    ctx->r14 = S32(ctx->r12 << 11);
    // 0x80802464: bgezl       $t6, L_80802480
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80802468: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_80802480;
    }
    goto skip_4;
    // 0x80802468: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_4:
    // 0x8080246C: jal         0x80102424
    // 0x80802470: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_12;
    // 0x80802470: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_12:
    // 0x80802474: b           L_808028A4
    // 0x80802478: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
        goto L_808028A4;
    // 0x80802478: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080247C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_80802480:
    // 0x80802480: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80802484: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80802488: jal         0x800DC178
    // 0x8080248C: nop

    func_800DC178(rdram, ctx);
        goto after_13;
    // 0x8080248C: nop

    after_13:
    // 0x80802490: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80802494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802498: jal         0x80102424
    // 0x8080249C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_14;
    // 0x8080249C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
    // 0x808024A0: b           L_808028A4
    // 0x808024A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
        goto L_808028A4;
    // 0x808024A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_808024A8:
    // 0x808024A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808024AC: jal         0x80101E14
    // 0x808024B0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80101E14(rdram, ctx);
        goto after_15;
    // 0x808024B0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_15:
    // 0x808024B4: beql        $v0, $zero, L_80802598
    if (ctx->r2 == 0) {
        // 0x808024B8: addiu       $t0, $s0, 0x4
        ctx->r8 = ADD32(ctx->r16, 0X4);
            goto L_80802598;
    }
    goto skip_5;
    // 0x808024B8: addiu       $t0, $s0, 0x4
    ctx->r8 = ADD32(ctx->r16, 0X4);
    skip_5:
    // 0x808024BC: jal         0x8010C754
    // 0x808024C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C754(rdram, ctx);
        goto after_16;
    // 0x808024C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808024C4: slti        $at, $v0, 0x5DC
    ctx->r1 = SIGNED(ctx->r2) < 0X5DC ? 1 : 0;
    // 0x808024C8: beq         $at, $zero, L_80802594
    if (ctx->r1 == 0) {
        // 0x808024CC: lui         $at, 0x3F40
        ctx->r1 = S32(0X3F40 << 16);
            goto L_80802594;
    }
    // 0x808024CC: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808024D0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808024D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2FB8) << 16);
    // 0x808024D8: jal         0x800DC178
    // 0x808024DC: lwc1        $f14, 0x2FB8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2FB8));
    func_800DC178(rdram, ctx);
        goto after_17;
    // 0x808024DC: lwc1        $f14, 0x2FB8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2FB8));
    after_17:
    // 0x808024E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2FBC) << 16);
    // 0x808024E4: lwc1        $f16, 0x2FBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2FBC));
    // 0x808024E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808024EC: lui         $a2, 0x5DC
    ctx->r6 = S32(0X5DC << 16);
    // 0x808024F0: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808024F4: ori         $a2, $a2, 0x190
    ctx->r6 = ctx->r6 | 0X190;
    // 0x808024F8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808024FC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80802500: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80802504: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80802508: nop

    // 0x8080250C: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80802510: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80802514: nop

    // 0x80802518: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x8080251C: beql        $a0, $zero, L_8080256C
    if (ctx->r4 == 0) {
        // 0x80802520: mfc1        $a0, $f6
        ctx->r4 = (int32_t)ctx->f6.u32l;
            goto L_8080256C;
    }
    goto skip_6;
    // 0x80802520: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    skip_6:
    // 0x80802524: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802528: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8080252C: sub.s       $f6, $f18, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80802530: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80802534: nop

    // 0x80802538: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8080253C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80802540: nop

    // 0x80802544: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80802548: bne         $a0, $zero, L_80802560
    if (ctx->r4 != 0) {
        // 0x8080254C: nop
    
            goto L_80802560;
    }
    // 0x8080254C: nop

    // 0x80802550: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80802554: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80802558: b           L_80802578
    // 0x8080255C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80802578;
    // 0x8080255C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80802560:
    // 0x80802560: b           L_80802578
    // 0x80802564: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80802578;
    // 0x80802564: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80802568: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
L_8080256C:
    // 0x8080256C: nop

    // 0x80802570: bltz        $a0, L_80802560
    if (SIGNED(ctx->r4) < 0) {
        // 0x80802574: nop
    
            goto L_80802560;
    }
    // 0x80802574: nop

L_80802578:
    // 0x80802578: or          $t8, $a0, $zero
    ctx->r24 = ctx->r4 | 0;
    // 0x8080257C: lui         $at, 0x15
    ctx->r1 = S32(0X15 << 16);
    // 0x80802580: ori         $at, $at, 0x7C9D
    ctx->r1 = ctx->r1 | 0X7C9D;
    // 0x80802584: sll         $t9, $t8, 21
    ctx->r25 = S32(ctx->r24 << 21);
    // 0x80802588: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8080258C: jal         0x800C4140
    // 0x80802590: addu        $a0, $t9, $at
    ctx->r4 = ADD32(ctx->r25, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_18;
    // 0x80802590: addu        $a0, $t9, $at
    ctx->r4 = ADD32(ctx->r25, ctx->r1);
    after_18:
L_80802594:
    // 0x80802594: addiu       $t0, $s0, 0x4
    ctx->r8 = ADD32(ctx->r16, 0X4);
L_80802598:
    // 0x80802598: jal         0x800D3948
    // 0x8080259C: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    func_800D3948(rdram, ctx);
        goto after_19;
    // 0x8080259C: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    after_19:
    // 0x808025A0: bne         $v0, $zero, L_80802688
    if (ctx->r2 != 0) {
        // 0x808025A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802688;
    }
    // 0x808025A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808025A8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2384, 0X3300) << 16);
    // 0x808025AC: jal         0x80101E4C
    // 0x808025B0: addiu       $a1, $a1, 0x3300
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2384, 0X3300));
    func_80101E4C(rdram, ctx);
        goto after_20;
    // 0x808025B0: addiu       $a1, $a1, 0x3300
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2384, 0X3300));
    after_20:
    // 0x808025B4: beq         $v0, $zero, L_80802688
    if (ctx->r2 == 0) {
        // 0x808025B8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80802688;
    }
    // 0x808025B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808025BC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x808025C0: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(2384, 0X32C0) << 16);
    // 0x808025C4: addiu       $t2, $t2, 0x32C0
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(2384, 0X32C0));
    // 0x808025C8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808025CC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808025D0: jal         0x800BABB8
    // 0x808025D4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800BABB8(rdram, ctx);
        goto after_21;
    // 0x808025D4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_21:
    // 0x808025D8: jal         0x800DC0C0
    // 0x808025DC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    func_800DC0C0(rdram, ctx);
        goto after_22;
    // 0x808025DC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_22:
    // 0x808025E0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808025E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808025E8: nop

    // 0x808025EC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808025F0: nop

    // 0x808025F4: bc1fl       L_80802644
    if (!c1cs) {
        // 0x808025F8: lwc1        $f16, 0x48($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
            goto L_80802644;
    }
    goto skip_7;
    // 0x808025F8: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    skip_7:
    // 0x808025FC: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80802600: addiu       $t8, $zero, -0x2D
    ctx->r24 = ADD32(0, -0X2D);
    // 0x80802604: addiu       $t9, $zero, 0x1F4
    ctx->r25 = ADD32(0, 0X1F4);
    // 0x80802608: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080260C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80802610: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80802614: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80802618: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x8080261C: addiu       $a1, $zero, -0x14
    ctx->r5 = ADD32(0, -0X14);
    // 0x80802620: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
    // 0x80802624: addiu       $a2, $t5, -0x4B
    ctx->r6 = ADD32(ctx->r13, -0X4B);
    // 0x80802628: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x8080262C: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80802630: jal         0x800BA994
    // 0x80802634: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    func_800BA994(rdram, ctx);
        goto after_23;
    // 0x80802634: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    after_23:
    // 0x80802638: b           L_80802680
    // 0x8080263C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
        goto L_80802680;
    // 0x8080263C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80802640: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
L_80802644:
    // 0x80802644: addiu       $t5, $zero, -0x2D
    ctx->r13 = ADD32(0, -0X2D);
    // 0x80802648: addiu       $t6, $zero, 0x1F4
    ctx->r14 = ADD32(0, 0X1F4);
    // 0x8080264C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80802650: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80802654: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80802658: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8080265C: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80802660: addiu       $a1, $zero, -0x14
    ctx->r5 = ADD32(0, -0X14);
    // 0x80802664: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
    // 0x80802668: addiu       $a2, $t2, 0x4B
    ctx->r6 = ADD32(ctx->r10, 0X4B);
    // 0x8080266C: sll         $t3, $a2, 16
    ctx->r11 = S32(ctx->r6 << 16);
    // 0x80802670: sra         $a2, $t3, 16
    ctx->r6 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80802674: jal         0x800BA994
    // 0x80802678: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    func_800BA994(rdram, ctx);
        goto after_24;
    // 0x80802678: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    after_24:
    // 0x8080267C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
L_80802680:
    // 0x80802680: jal         0x800BA22C
    // 0x80802684: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_25;
    // 0x80802684: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
L_80802688:
    // 0x80802688: jal         0x80101DDC
    // 0x8080268C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_26;
    // 0x8080268C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80802690: beq         $v0, $zero, L_808028A0
    if (ctx->r2 == 0) {
        // 0x80802694: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808028A0;
    }
    // 0x80802694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802698: jal         0x80102424
    // 0x8080269C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_27;
    // 0x8080269C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_27:
    // 0x808026A0: b           L_808028A4
    // 0x808026A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
        goto L_808028A4;
    // 0x808026A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_808026A8:
    // 0x808026A8: jal         0x800D90A4
    // 0x808026AC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_28;
    // 0x808026AC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_28:
    // 0x808026B0: beq         $v0, $zero, L_808026C0
    if (ctx->r2 == 0) {
        // 0x808026B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808026C0;
    }
    // 0x808026B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808026B8: jal         0x80102424
    // 0x808026BC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_29;
    // 0x808026BC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_29:
L_808026C0:
    // 0x808026C0: addiu       $t7, $s0, 0x4
    ctx->r15 = ADD32(ctx->r16, 0X4);
    // 0x808026C4: b           L_808028A0
    // 0x808026C8: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
        goto L_808028A0;
    // 0x808026C8: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_808026CC:
    // 0x808026CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808026D0: jal         0x80101E14
    // 0x808026D4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80101E14(rdram, ctx);
        goto after_30;
    // 0x808026D4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_30:
    // 0x808026D8: beql        $v0, $zero, L_808027F4
    if (ctx->r2 == 0) {
        // 0x808026DC: addiu       $t3, $s0, 0x4
        ctx->r11 = ADD32(ctx->r16, 0X4);
            goto L_808027F4;
    }
    goto skip_8;
    // 0x808026DC: addiu       $t3, $s0, 0x4
    ctx->r11 = ADD32(ctx->r16, 0X4);
    skip_8:
    // 0x808026E0: jal         0x8010C754
    // 0x808026E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C754(rdram, ctx);
        goto after_31;
    // 0x808026E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x808026E8: slti        $at, $v0, 0x5DC
    ctx->r1 = SIGNED(ctx->r2) < 0X5DC ? 1 : 0;
    // 0x808026EC: beql        $at, $zero, L_808027F4
    if (ctx->r1 == 0) {
        // 0x808026F0: addiu       $t3, $s0, 0x4
        ctx->r11 = ADD32(ctx->r16, 0X4);
            goto L_808027F4;
    }
    goto skip_9;
    // 0x808026F0: addiu       $t3, $s0, 0x4
    ctx->r11 = ADD32(ctx->r16, 0X4);
    skip_9:
    // 0x808026F4: jal         0x800D3948
    // 0x808026F8: nop

    func_800D3948(rdram, ctx);
        goto after_32;
    // 0x808026F8: nop

    after_32:
    // 0x808026FC: bne         $v0, $zero, L_80802720
    if (ctx->r2 != 0) {
        // 0x80802700: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80802720;
    }
    // 0x80802700: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80802704: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2384, 0X326C) << 16);
    // 0x80802708: addiu       $t8, $t8, 0x326C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2384, 0X326C));
    // 0x8080270C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80802710: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80802714: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80802718: jal         0x800BBCB8
    // 0x8080271C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_800BBCB8(rdram, ctx);
        goto after_33;
    // 0x8080271C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_33:
L_80802720:
    // 0x80802720: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2FC0) << 16);
    // 0x80802724: lwc1        $f12, 0x2FC0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2FC0));
    // 0x80802728: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2FC4) << 16);
    // 0x8080272C: addiu       $t9, $s0, 0x4
    ctx->r25 = ADD32(ctx->r16, 0X4);
    // 0x80802730: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80802734: jal         0x800DC178
    // 0x80802738: lwc1        $f14, 0x2FC4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2FC4));
    func_800DC178(rdram, ctx);
        goto after_34;
    // 0x80802738: lwc1        $f14, 0x2FC4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2FC4));
    after_34:
    // 0x8080273C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2FC8) << 16);
    // 0x80802740: lwc1        $f6, 0x2FC8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2FC8));
    // 0x80802744: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80802748: lui         $a2, 0x5DC
    ctx->r6 = S32(0X5DC << 16);
    // 0x8080274C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80802750: ori         $a2, $a2, 0x190
    ctx->r6 = ctx->r6 | 0X190;
    // 0x80802754: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80802758: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8080275C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80802760: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80802764: nop

    // 0x80802768: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8080276C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80802770: nop

    // 0x80802774: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80802778: beql        $a0, $zero, L_808027C8
    if (ctx->r4 == 0) {
        // 0x8080277C: mfc1        $a0, $f4
        ctx->r4 = (int32_t)ctx->f4.u32l;
            goto L_808027C8;
    }
    goto skip_10;
    // 0x8080277C: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    skip_10:
    // 0x80802780: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802784: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80802788: sub.s       $f4, $f8, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8080278C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80802790: nop

    // 0x80802794: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80802798: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x8080279C: nop

    // 0x808027A0: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x808027A4: bne         $a0, $zero, L_808027BC
    if (ctx->r4 != 0) {
        // 0x808027A8: nop
    
            goto L_808027BC;
    }
    // 0x808027A8: nop

    // 0x808027AC: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x808027B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808027B4: b           L_808027D4
    // 0x808027B8: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_808027D4;
    // 0x808027B8: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_808027BC:
    // 0x808027BC: b           L_808027D4
    // 0x808027C0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_808027D4;
    // 0x808027C0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x808027C4: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
L_808027C8:
    // 0x808027C8: nop

    // 0x808027CC: bltz        $a0, L_808027BC
    if (SIGNED(ctx->r4) < 0) {
        // 0x808027D0: nop
    
            goto L_808027BC;
    }
    // 0x808027D0: nop

L_808027D4:
    // 0x808027D4: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x808027D8: lui         $at, 0x1F
    ctx->r1 = S32(0X1F << 16);
    // 0x808027DC: ori         $at, $at, 0xFC01
    ctx->r1 = ctx->r1 | 0XFC01;
    // 0x808027E0: sll         $t2, $t1, 21
    ctx->r10 = S32(ctx->r9 << 21);
    // 0x808027E4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x808027E8: jal         0x800C4140
    // 0x808027EC: addu        $a0, $t2, $at
    ctx->r4 = ADD32(ctx->r10, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_35;
    // 0x808027EC: addu        $a0, $t2, $at
    ctx->r4 = ADD32(ctx->r10, ctx->r1);
    after_35:
    // 0x808027F0: addiu       $t3, $s0, 0x4
    ctx->r11 = ADD32(ctx->r16, 0X4);
L_808027F4:
    // 0x808027F4: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x808027F8: jal         0x80101DDC
    // 0x808027FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_36;
    // 0x808027FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x80802800: beq         $v0, $zero, L_80802824
    if (ctx->r2 == 0) {
        // 0x80802804: nop
    
            goto L_80802824;
    }
    // 0x80802804: nop

    // 0x80802808: jal         0x80106790
    // 0x8080280C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_37;
    // 0x8080280C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_37:
    // 0x80802810: lw          $t4, 0x50($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X50);
    // 0x80802814: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80802818: sw          $t5, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r13;
    // 0x8080281C: jal         0x800FFA88
    // 0x80802820: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_38;
    // 0x80802820: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_38:
L_80802824:
    // 0x80802824: jal         0x80101F24
    // 0x80802828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_39;
    // 0x80802828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x8080282C: lui         $at, 0x4307
    ctx->r1 = S32(0X4307 << 16);
    // 0x80802830: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80802834: nop

    // 0x80802838: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8080283C: jal         0x80013970
    // 0x80802840: nop

    func_80013970(rdram, ctx);
        goto after_40;
    // 0x80802840: nop

    after_40:
    // 0x80802844: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80802848: jal         0x80103EF4
    // 0x8080284C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_41;
    // 0x8080284C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x80802850: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2FCC) << 16);
    // 0x80802854: lwc1        $f18, 0x2FCC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2FCC));
    // 0x80802858: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x8080285C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802860: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80802864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802868: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8080286C: sub.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80802870: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80802874: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80802878: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8080287C: jal         0x80101F24
    // 0x80802880: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    func_80101F24(rdram, ctx);
        goto after_42;
    // 0x80802880: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    after_42:
    // 0x80802884: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2FD0) << 16);
    // 0x80802888: lwc1        $f8, 0x2FD0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2FD0));
    // 0x8080288C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2FD4) << 16);
    // 0x80802890: lwc1        $f6, 0x2FD4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2FD4));
    // 0x80802894: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80802898: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080289C: swc1        $f10, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f10.u32l;
L_808028A0:
    // 0x808028A0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_808028A4:
    // 0x808028A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808028A8: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808028AC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808028B0: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x808028B4: nop

    // 0x808028B8: bc1f        L_808028CC
    if (!c1cs) {
        // 0x808028BC: nop
    
            goto L_808028CC;
    }
    // 0x808028BC: nop

    // 0x808028C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808028C4: nop

    // 0x808028C8: swc1        $f8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f8.u32l;
L_808028CC:
    // 0x808028CC: jal         0x800F54E4
    // 0x808028D0: nop

    func_800F54E4(rdram, ctx);
        goto after_43;
    // 0x808028D0: nop

    after_43:
    // 0x808028D4: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x808028D8: jal         0x80103EAC
    // 0x808028DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_44;
    // 0x808028DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x808028E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808028E4: jal         0x80103EAC
    // 0x808028E8: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_80103EAC(rdram, ctx);
        goto after_45;
    // 0x808028E8: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_45:
    // 0x808028EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2FD8) << 16);
    // 0x808028F0: lwc1        $f6, 0x2FD8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2FD8));
    // 0x808028F4: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808028F8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808028FC: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80802900: add.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80802904: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80802908: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8080290C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80802910: jal         0x800F4F34
    // 0x80802914: nop

    func_800F4F34(rdram, ctx);
        goto after_46;
    // 0x80802914: nop

    after_46:
    // 0x80802918: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8080291C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80802920: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80802924: jr          $ra
    // 0x80802928: nop

    return;
    // 0x80802928: nop

;}
RECOMP_FUNC void func_808004B0_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B0: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x808004B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808004BC: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x808004C0: jal         0x80100094
    // 0x808004C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808004C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808004C8: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x808004CC: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x808004D0: jal         0x80100094
    // 0x808004D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808004D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808004D8: jal         0x800D8FF8
    // 0x808004DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x808004DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_2:
    // 0x808004E0: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x808004E4: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x808004E8: lbu         $t6, 0xFA($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XFA);
    // 0x808004EC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x808004F0: bnel        $v1, $t6, L_808006F0
    if (ctx->r3 != ctx->r14) {
        // 0x808004F4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808006F0;
    }
    goto skip_0;
    // 0x808004F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808004F8: lbu         $v0, 0xFB($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XFB);
    // 0x808004FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800500: beq         $v0, $at, L_80800528
    if (ctx->r2 == ctx->r1) {
        // 0x80800504: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800528;
    }
    // 0x80800504: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800508: beq         $v0, $at, L_80800534
    if (ctx->r2 == ctx->r1) {
        // 0x8080050C: lw          $t8, 0x78($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X78);
            goto L_80800534;
    }
    // 0x8080050C: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80800510: beq         $v0, $v1, L_80800528
    if (ctx->r2 == ctx->r3) {
        // 0x80800514: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800528;
    }
    // 0x80800514: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800518: beq         $v0, $at, L_80800534
    if (ctx->r2 == ctx->r1) {
        // 0x8080051C: nop
    
            goto L_80800534;
    }
    // 0x8080051C: nop

    // 0x80800520: b           L_80800540
    // 0x80800524: nop

        goto L_80800540;
    // 0x80800524: nop

L_80800528:
    // 0x80800528: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x8080052C: b           L_80800540
    // 0x80800530: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
        goto L_80800540;
    // 0x80800530: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
L_80800534:
    // 0x80800534: jal         0x80106790
    // 0x80800538: lw          $a0, 0x3C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X3C);
    func_80106790(rdram, ctx);
        goto after_3;
    // 0x80800538: lw          $a0, 0x3C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X3C);
    after_3:
    // 0x8080053C: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
L_80800540:
    // 0x80800540: jal         0x80089E68
    // 0x80800544: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    _susplinet_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x80800544: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    after_4:
    // 0x80800548: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080054C: jal         0x80089E78
    // 0x80800550: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    _susplinet_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80800550: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    after_5:
    // 0x80800554: jal         0x80105AE8
    // 0x80800558: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    func_80105AE8(rdram, ctx);
        goto after_6;
    // 0x80800558: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_6:
    // 0x8080055C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800560: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800564: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80800568: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8080056C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800570: jal         0x80089E70
    // 0x80800574: nop

    _susplinet_entrypoint_10(rdram, ctx);
        goto after_7;
    // 0x80800574: nop

    after_7:
    // 0x80800578: jal         0x80089EA8
    // 0x8080057C: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    _susplinet_entrypoint_17(rdram, ctx);
        goto after_8;
    // 0x8080057C: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    after_8:
    // 0x80800580: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80800584: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800588: jal         0x80089E58
    // 0x8080058C: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    _susplinet_entrypoint_7(rdram, ctx);
        goto after_9;
    // 0x8080058C: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    after_9:
    // 0x80800590: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80800594: jal         0x80089E60
    // 0x80800598: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _susplinet_entrypoint_8(rdram, ctx);
        goto after_10;
    // 0x80800598: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8080059C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808005A0: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x808005A4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808005A8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x808005AC: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x808005B0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x808005B4: jal         0x800EF5A0
    // 0x808005B8: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_800EF5A0(rdram, ctx);
        goto after_11;
    // 0x808005B8: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_11:
    // 0x808005BC: jal         0x80089E50
    // 0x808005C0: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    _susplinet_entrypoint_6(rdram, ctx);
        goto after_12;
    // 0x808005C0: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    after_12:
    // 0x808005C4: beql        $v0, $zero, L_808005D4
    if (ctx->r2 == 0) {
        // 0x808005C8: lbu         $t9, 0xFC($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0XFC);
            goto L_808005D4;
    }
    goto skip_1;
    // 0x808005C8: lbu         $t9, 0xFC($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XFC);
    skip_1:
    // 0x808005CC: sb          $zero, 0xFC($s0)
    MEM_B(0XFC, ctx->r16) = 0;
    // 0x808005D0: lbu         $t9, 0xFC($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XFC);
L_808005D4:
    // 0x808005D4: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x808005D8: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x808005DC: beql        $t9, $zero, L_80800644
    if (ctx->r25 == 0) {
        // 0x808005E0: lwc1        $f18, 0x44($t2)
        ctx->f18.u32l = MEM_W(ctx->r10, 0X44);
            goto L_80800644;
    }
    goto skip_2;
    // 0x808005E0: lwc1        $f18, 0x44($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X44);
    skip_2:
    // 0x808005E4: lwc1        $f12, 0x44($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X44);
    // 0x808005E8: jal         0x800F1DCC
    // 0x808005EC: lwc1        $f14, 0x10C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10C);
    func_800F1DCC(rdram, ctx);
        goto after_13;
    // 0x808005EC: lwc1        $f14, 0x10C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10C);
    after_13:
    // 0x808005F0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808005F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808005F8: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x808005FC: lwc1        $f18, 0x10C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x80800600: lwc1        $f14, 0x110($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X110);
    // 0x80800604: mul.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800608: nop

    // 0x8080060C: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80800610: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80800614: swc1        $f6, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f6.u32l;
    // 0x80800618: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x8080061C: lwc1        $f12, 0x48($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X48);
    // 0x80800620: jal         0x800F1DCC
    // 0x80800624: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    func_800F1DCC(rdram, ctx);
        goto after_14;
    // 0x80800624: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    after_14:
    // 0x80800628: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8080062C: lwc1        $f8, 0x110($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X110);
    // 0x80800630: mul.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80800634: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800638: b           L_8080065C
    // 0x8080063C: swc1        $f16, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f16.u32l;
        goto L_8080065C;
    // 0x8080063C: swc1        $f16, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f16.u32l;
    // 0x80800640: lwc1        $f18, 0x44($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X44);
L_80800644:
    // 0x80800644: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80800648: swc1        $f18, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f18.u32l;
    // 0x8080064C: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x80800650: lwc1        $f4, 0x48($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X48);
    // 0x80800654: sb          $t4, 0xFC($s0)
    MEM_B(0XFC, ctx->r16) = ctx->r12;
    // 0x80800658: swc1        $f4, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f4.u32l;
L_8080065C:
    // 0x8080065C: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800660: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80800664: lw          $a1, 0x10C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10C);
    // 0x80800668: lw          $a2, 0x110($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X110);
    // 0x8080066C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80800670: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80800674: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80800678: jal         0x800EF4E4
    // 0x8080067C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800EF4E4(rdram, ctx);
        goto after_15;
    // 0x8080067C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_15:
    // 0x80800680: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x80800684: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800688: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8080068C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800690: lw          $a1, 0x10C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10C);
    // 0x80800694: lw          $a2, 0x110($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X110);
    // 0x80800698: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8080069C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808006A0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x808006A4: jal         0x800EF4E4
    // 0x808006A8: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800EF4E4(rdram, ctx);
        goto after_16;
    // 0x808006A8: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_16:
    // 0x808006AC: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x808006B0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808006B4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808006B8: jal         0x800EF04C
    // 0x808006BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_17;
    // 0x808006BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_17:
    // 0x808006C0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808006C4: jal         0x800EF04C
    // 0x808006C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_18;
    // 0x808006C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_18:
    // 0x808006CC: addiu       $s0, $sp, 0x44
    ctx->r16 = ADD32(ctx->r29, 0X44);
    // 0x808006D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x808006D8: jal         0x800A516C
    // 0x808006DC: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    func_800A516C(rdram, ctx);
        goto after_19;
    // 0x808006DC: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_19:
    // 0x808006E0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808006E4: jal         0x800856A8
    // 0x808006E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _capod_entrypoint_1(rdram, ctx);
        goto after_20;
    // 0x808006E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_20:
    // 0x808006EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006F0:
    // 0x808006F0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808006F4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x808006F8: jr          $ra
    // 0x808006FC: nop

    return;
    // 0x808006FC: nop

;}
RECOMP_FUNC void idglow_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080027C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800280: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800284: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800288: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080028C: jal         0x800D8FF8
    // 0x80800290: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800290: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800294: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800298: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080029C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808002A0: lwc1        $f2, 0x4($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X4);
    // 0x808002A4: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x808002A8: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x808002AC: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x808002B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2894, 0X324) << 16);
    // 0x808002B4: addiu       $a2, $a2, -0x7328
    ctx->r6 = ADD32(ctx->r6, -0X7328);
    // 0x808002B8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808002BC: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x808002C0: lwc1        $f12, 0x0($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X0);
    // 0x808002C4: c.le.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl <= ctx->f12.fl;
    // 0x808002C8: nop

    // 0x808002CC: bc1f        L_808002E4
    if (!c1cs) {
        // 0x808002D0: nop
    
            goto L_808002E4;
    }
    // 0x808002D0: nop

    // 0x808002D4: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    // 0x808002D8: swc1        $f14, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f14.u32l;
    // 0x808002DC: b           L_80800304
    // 0x808002E0: swc1        $f10, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f10.u32l;
        goto L_80800304;
    // 0x808002E0: swc1        $f10, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f10.u32l;
L_808002E4:
    // 0x808002E4: lwc1        $f0, 0x324($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2894, 0X324));
    // 0x808002E8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x808002EC: nop

    // 0x808002F0: bc1fl       L_80800308
    if (!c1cs) {
        // 0x808002F4: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80800308;
    }
    goto skip_0;
    // 0x808002F4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808002F8: neg.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = -ctx->f2.fl;
    // 0x808002FC: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
    // 0x80800300: swc1        $f16, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f16.u32l;
L_80800304:
    // 0x80800304: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_80800308:
    // 0x80800308: jal         0x80088660
    // 0x8080030C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _glid_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080030C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800314: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800318: jr          $ra
    // 0x8080031C: nop

    return;
    // 0x8080031C: nop

;}
RECOMP_FUNC void func_800C6420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6420: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800C6424: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C6428: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C642C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C6430: addiu       $a1, $s0, 0x4C
    ctx->r5 = ADD32(ctx->r16, 0X4C);
    // 0x800C6434: jal         0x800EE7F8
    // 0x800C6438: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800C6438: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x800C643C: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800C6440: lwc1        $f8, 0x70($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X70);
    // 0x800C6444: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800C6448: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C644C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800C6450: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C6454: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C6458: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800C645C: nop

    // 0x800C6460: bc1f        L_800C6470
    if (!c1cs) {
        // 0x800C6464: nop
    
            goto L_800C6470;
    }
    // 0x800C6464: nop

    // 0x800C6468: b           L_800C6470
    // 0x800C646C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800C6470;
    // 0x800C646C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800C6470:
    // 0x800C6470: jal         0x8001210C
    // 0x800C6474: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    func_8001210C(rdram, ctx);
        goto after_1;
    // 0x800C6474: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    after_1:
    // 0x800C6478: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x800C647C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x800C6480: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800C6484: beq         $v1, $zero, L_800C6494
    if (ctx->r3 == 0) {
        // 0x800C6488: lui         $a2, 0xC3C3
        ctx->r6 = S32(0XC3C3 << 16);
            goto L_800C6494;
    }
    // 0x800C6488: lui         $a2, 0xC3C3
    ctx->r6 = S32(0XC3C3 << 16);
    // 0x800C648C: beq         $v0, $zero, L_800C6514
    if (ctx->r2 == 0) {
        // 0x800C6490: nop
    
            goto L_800C6514;
    }
    // 0x800C6490: nop

L_800C6494:
    // 0x800C6494: beq         $v1, $zero, L_800C64A4
    if (ctx->r3 == 0) {
        // 0x800C6498: lui         $at, 0x2
        ctx->r1 = S32(0X2 << 16);
            goto L_800C64A4;
    }
    // 0x800C6498: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x800C649C: lbu         $t6, 0x91($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X91);
    // 0x800C64A0: sb          $t6, 0x8F($s0)
    MEM_B(0X8F, ctx->r16) = ctx->r14;
L_800C64A4:
    // 0x800C64A4: lw          $a3, 0x84($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X84);
    // 0x800C64A8: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x800C64AC: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x800C64B0: addiu       $t8, $sp, 0x4C
    ctx->r24 = ADD32(ctx->r29, 0X4C);
    // 0x800C64B4: or          $t7, $a3, $at
    ctx->r15 = ctx->r7 | ctx->r1;
    // 0x800C64B8: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800C64BC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800C64C0: jal         0x800C5CC0
    // 0x800C64C4: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    func_800C5CC0(rdram, ctx);
        goto after_2;
    // 0x800C64C4: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    after_2:
    // 0x800C64C8: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x800C64CC: beq         $v0, $zero, L_800C6504
    if (ctx->r2 == 0) {
        // 0x800C64D0: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C6504;
    }
    // 0x800C64D0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C64D4: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800C64D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C64DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C64E0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x800C64E4: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x800C64E8: nop

    // 0x800C64EC: bc1f        L_800C6514
    if (!c1cs) {
        // 0x800C64F0: nop
    
            goto L_800C6514;
    }
    // 0x800C64F0: nop

    // 0x800C64F4: jal         0x800C5F40
    // 0x800C64F8: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    func_800C5F40(rdram, ctx);
        goto after_3;
    // 0x800C64F8: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    after_3:
    // 0x800C64FC: b           L_800C6514
    // 0x800C6500: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
        goto L_800C6514;
    // 0x800C6500: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
L_800C6504:
    // 0x800C6504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C6508: jal         0x800C5F8C
    // 0x800C650C: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    func_800C5F8C(rdram, ctx);
        goto after_4;
    // 0x800C650C: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    after_4:
    // 0x800C6510: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
L_800C6514:
    // 0x800C6514: beq         $v1, $zero, L_800C6524
    if (ctx->r3 == 0) {
        // 0x800C6518: lw          $t9, 0x40($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X40);
            goto L_800C6524;
    }
    // 0x800C6518: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800C651C: bne         $t9, $zero, L_800C65B0
    if (ctx->r25 != 0) {
        // 0x800C6520: nop
    
            goto L_800C65B0;
    }
    // 0x800C6520: nop

L_800C6524:
    // 0x800C6524: beql        $v1, $zero, L_800C6538
    if (ctx->r3 == 0) {
        // 0x800C6528: lwc1        $f6, 0x74($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
            goto L_800C6538;
    }
    goto skip_0;
    // 0x800C6528: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    skip_0:
    // 0x800C652C: lbu         $t0, 0x90($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X90);
    // 0x800C6530: sb          $t0, 0x8E($s0)
    MEM_B(0X8E, ctx->r16) = ctx->r8;
    // 0x800C6534: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
L_800C6538:
    // 0x800C6538: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C653C: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x800C6540: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800C6544: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800C6548: lw          $a3, 0x88($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X88);
    // 0x800C654C: addiu       $t1, $sp, 0x4C
    ctx->r9 = ADD32(ctx->r29, 0X4C);
    // 0x800C6550: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800C6554: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C6558: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800C655C: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800C6560: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800C6564: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800C6568: jal         0x800C5CC0
    // 0x800C656C: nop

    func_800C5CC0(rdram, ctx);
        goto after_5;
    // 0x800C656C: nop

    after_5:
    // 0x800C6570: bne         $v0, $zero, L_800C6580
    if (ctx->r2 != 0) {
        // 0x800C6574: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C6580;
    }
    // 0x800C6574: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C6578: lbu         $t2, 0x9C($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X9C);
    // 0x800C657C: beq         $t2, $zero, L_800C6598
    if (ctx->r10 == 0) {
        // 0x800C6580: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C6598;
    }
L_800C6580:
    // 0x800C6580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C6584: jal         0x800C5FCC
    // 0x800C6588: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    func_800C5FCC(rdram, ctx);
        goto after_6;
    // 0x800C6588: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_6:
    // 0x800C658C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800C6590: b           L_800C65B0
    // 0x800C6594: sb          $t3, 0x92($s0)
    MEM_B(0X92, ctx->r16) = ctx->r11;
        goto L_800C65B0;
    // 0x800C6594: sb          $t3, 0x92($s0)
    MEM_B(0X92, ctx->r16) = ctx->r11;
L_800C6598:
    // 0x800C6598: lbu         $t4, 0x92($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X92);
    // 0x800C659C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800C65A0: beq         $t4, $zero, L_800C65B0
    if (ctx->r12 == 0) {
        // 0x800C65A4: nop
    
            goto L_800C65B0;
    }
    // 0x800C65A4: nop

    // 0x800C65A8: sb          $zero, 0x92($s0)
    MEM_B(0X92, ctx->r16) = 0;
    // 0x800C65AC: sb          $t5, 0x8F($s0)
    MEM_B(0X8F, ctx->r16) = ctx->r13;
L_800C65B0:
    // 0x800C65B0: jal         0x800C5E14
    // 0x800C65B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C5E14(rdram, ctx);
        goto after_7;
    // 0x800C65B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800C65B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800C65BC: beq         $v0, $at, L_800C65CC
    if (ctx->r2 == ctx->r1) {
        // 0x800C65C0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800C65CC;
    }
    // 0x800C65C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800C65C4: jal         0x800C5A10
    // 0x800C65C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C5A10(rdram, ctx);
        goto after_8;
    // 0x800C65C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_800C65CC:
    // 0x800C65CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C65D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C65D4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800C65D8: jr          $ra
    // 0x800C65DC: nop

    return;
    // 0x800C65DC: nop

;}
RECOMP_FUNC void suquiz_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C18: beq         $a0, $zero, L_80800C3C
    if (ctx->r4 == 0) {
        // 0x80800C1C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800C3C;
    }
    // 0x80800C1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800C24: bnel        $a0, $at, L_80800C48
    if (ctx->r4 != ctx->r1) {
        // 0x80800C28: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800C48;
    }
    goto skip_0;
    // 0x80800C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800C2C: jal         0x800DA544
    // 0x80800C30: addiu       $a0, $zero, 0x582
    ctx->r4 = ADD32(0, 0X582);
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x80800C30: addiu       $a0, $zero, 0x582
    ctx->r4 = ADD32(0, 0X582);
    after_0:
    // 0x80800C34: b           L_80800C48
    // 0x80800C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C48;
    // 0x80800C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C3C:
    // 0x80800C3C: jal         0x800DA544
    // 0x80800C40: addiu       $a0, $zero, 0x583
    ctx->r4 = ADD32(0, 0X583);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800C40: addiu       $a0, $zero, 0x583
    ctx->r4 = ADD32(0, 0X583);
    after_1:
    // 0x80800C44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C48:
    // 0x80800C48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C4C: jr          $ra
    // 0x80800C50: nop

    return;
    // 0x80800C50: nop

;}
