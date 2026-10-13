#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800C96CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C96CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C96D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C96D4: jal         0x800C91C8
    // 0x800C96D8: nop

    func_800C91C8(rdram, ctx);
        goto after_0;
    // 0x800C96D8: nop

    after_0:
    // 0x800C96DC: beq         $v0, $zero, L_800C9708
    if (ctx->r2 == 0) {
        // 0x800C96E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C9708;
    }
    // 0x800C96E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C96E4: lbu         $t6, 0xA($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XA);
    // 0x800C96E8: lbu         $t7, 0x1C($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1C);
    // 0x800C96EC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C96F0: bne         $t6, $t7, L_800C9700
    if (ctx->r14 != ctx->r15) {
        // 0x800C96F4: nop
    
            goto L_800C9700;
    }
    // 0x800C96F4: nop

    // 0x800C96F8: b           L_800C970C
    // 0x800C96FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800C970C;
    // 0x800C96FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C9700:
    // 0x800C9700: b           L_800C970C
    // 0x800C9704: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800C970C;
    // 0x800C9704: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800C9708:
    // 0x800C9708: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C970C:
    // 0x800C970C: jr          $ra
    // 0x800C9710: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C9710: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800018_chfirefx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080001C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800020: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80800024: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x80800028: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080002C: sll         $t8, $t6, 25
    ctx->r24 = S32(ctx->r14 << 25);
    // 0x80800030: bgezl       $t8, L_80800040
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800034: lbu         $t9, 0x77($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X77);
            goto L_80800040;
    }
    goto skip_0;
    // 0x80800034: lbu         $t9, 0x77($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X77);
    skip_0:
    // 0x80800038: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
    // 0x8080003C: lbu         $t9, 0x77($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X77);
L_80800040:
    // 0x80800040: lw          $a1, 0x38($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X38);
    // 0x80800044: andi        $t0, $t9, 0xFFBF
    ctx->r8 = ctx->r25 & 0XFFBF;
    // 0x80800048: sb          $t0, 0x77($a0)
    MEM_B(0X77, ctx->r4) = ctx->r8;
    // 0x8080004C: lhu         $t1, 0x76($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X76);
    // 0x80800050: srl         $t2, $t1, 7
    ctx->r10 = S32(U32(ctx->r9) >> 7);
    // 0x80800054: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80800058: bgez        $t2, L_8080006C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8080005C: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8080006C;
    }
    // 0x8080005C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800060: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800064: nop

    // 0x80800068: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_8080006C:
    // 0x8080006C: lwc1        $f8, 0x48($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80800070: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80800074: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80800078: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8080007C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80800080: jal         0x80800098
    // 0x80800084: nop

    chfirefx_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800084: nop

    after_0:
    // 0x80800088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080008C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800090: jr          $ra
    // 0x80800094: nop

    return;
    // 0x80800094: nop

;}
RECOMP_FUNC void chonearmbandit_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(896, 0X12BC) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x12BC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(896, 0X12BC));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x12BC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(896, 0X12BC));
;}
RECOMP_FUNC void func_80800130_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800130: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800134: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800138: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080013C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800140: jal         0x8009E74C
    // 0x80800144: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8009E74C(rdram, ctx);
        goto after_0;
    // 0x80800144: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_0:
    // 0x80800148: bne         $v0, $zero, L_808001E8
    if (ctx->r2 != 0) {
        // 0x8080014C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001E8;
    }
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800150: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800154: jal         0x800947EC
    // 0x80800158: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_1;
    // 0x80800158: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8080015C: jal         0x8009E474
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E474(rdram, ctx);
        goto after_2;
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800164: jal         0x8009EF60
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_popZone(rdram, ctx);
        goto after_3;
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080016C: jal         0x80095A40
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095A40(rdram, ctx);
        goto after_4;
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: jal         0x8009590C
    // 0x8080017C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009590C(rdram, ctx);
        goto after_5;
    // 0x8080017C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x80800180: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800184: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080018C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800190: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800194: jal         0x800A4D6C
    // 0x80800198: nop

    func_800A4D6C(rdram, ctx);
        goto after_6;
    // 0x80800198: nop

    after_6:
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A0: jal         0x80092864
    // 0x808001A4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80092864(rdram, ctx);
        goto after_7;
    // 0x808001A4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_7:
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001AC: jal         0x80095964
    // 0x808001B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80095964(rdram, ctx);
        goto after_8;
    // 0x808001B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B8: jal         0x800A25DC
    // 0x808001BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A25DC(rdram, ctx);
        goto after_9;
    // 0x808001BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C4: jal         0x800A2018
    // 0x808001C8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800A2018(rdram, ctx);
        goto after_10;
    // 0x808001C8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_10:
    // 0x808001CC: jal         0x80800050
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800050_bsstatue(rdram, ctx);
        goto after_11;
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808001D4: jal         0x8009EB00
    // 0x808001D8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8009EB00(rdram, ctx);
        goto after_12;
    // 0x808001D8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_12:
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E0: jal         0x80800000
    // 0x808001E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800000_bsstatue(rdram, ctx);
        goto after_13;
    // 0x808001E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
L_808001E8:
    // 0x808001E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001F4: jr          $ra
    // 0x808001F8: nop

    return;
    // 0x808001F8: nop

;}
RECOMP_FUNC void func_800EB7A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB7A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EB7AC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800EB7B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800EB7B4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800EB7B8: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800EB7BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EB7C0: addiu       $s1, $s1, 0x2E9C
    ctx->r17 = ADD32(ctx->r17, 0X2E9C);
    // 0x800EB7C4: addiu       $s0, $s0, 0x2E80
    ctx->r16 = ADD32(ctx->r16, 0X2E80);
    // 0x800EB7C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_800EB7CC:
    // 0x800EB7CC: beql        $a0, $zero, L_800EB7E4
    if (ctx->r4 == 0) {
        // 0x800EB7D0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800EB7E4;
    }
    goto skip_0;
    // 0x800EB7D0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x800EB7D4: jal         0x800B2F58
    // 0x800EB7D8: nop

    vector_defrag(rdram, ctx);
        goto after_0;
    // 0x800EB7D8: nop

    after_0:
    // 0x800EB7DC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800EB7E0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800EB7E4:
    // 0x800EB7E4: bnel        $s0, $s1, L_800EB7CC
    if (ctx->r16 != ctx->r17) {
        // 0x800EB7E8: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_800EB7CC;
    }
    goto skip_1;
    // 0x800EB7E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x800EB7EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800EB7F0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800EB7F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800EB7F8: jr          $ra
    // 0x800EB7FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800EB7FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void baeggfire_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800664: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80800668: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    // 0x8080066C: slti        $t7, $v0, 0x2
    ctx->r15 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80800670: jr          $ra
    // 0x80800674: xori        $v0, $t7, 0x1
    ctx->r2 = ctx->r15 ^ 0X1;
    return;
    // 0x80800674: xori        $v0, $t7, 0x1
    ctx->r2 = ctx->r15 ^ 0X1;
    // 0x80800678: nop

    // 0x8080067C: nop

;}
RECOMP_FUNC void _gspropsDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088B90: syscall     727
    recomp_syscall_handler(rdram, ctx, 0x80088B90);
    return;
    // 0x80088B94: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80802864_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802864: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802868: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080286C: bne         $a1, $zero, L_808028D0
    if (ctx->r5 != 0) {
        // 0x80802870: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_808028D0;
    }
    // 0x80802870: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802874: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1060, 0X2CA8) << 16);
    // 0x80802878: addiu       $a1, $a1, 0x2CA8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1060, 0X2CA8));
    // 0x8080287C: addiu       $a0, $zero, 0x234
    ctx->r4 = ADD32(0, 0X234);
    // 0x80802880: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x80802884: jal         0x80108528
    // 0x80802888: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    func_80108528(rdram, ctx);
        goto after_0;
    // 0x80802888: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8080288C: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80802890: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80802894: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80802898: jal         0x80102FDC
    // 0x8080289C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80102FDC(rdram, ctx);
        goto after_1;
    // 0x8080289C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808028A0: jal         0x80088840
    // 0x808028A4: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_2;
    // 0x808028A4: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    after_2:
    // 0x808028A8: beq         $v0, $zero, L_808028C8
    if (ctx->r2 == 0) {
        // 0x808028AC: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_808028C8;
    }
    // 0x808028AC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808028B0: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x808028B4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x808028B8: jal         0x800862D8
    // 0x808028BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    _chappearfx_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808028BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x808028C0: b           L_808028D4
    // 0x808028C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808028D4;
    // 0x808028C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808028C8:
    // 0x808028C8: jal         0x800FFAB0
    // 0x808028CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x808028CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
L_808028D0:
    // 0x808028D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808028D4:
    // 0x808028D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808028D8: jr          $ra
    // 0x808028DC: nop

    return;
    // 0x808028DC: nop

;}
RECOMP_FUNC void func_800BEF00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEF00: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BEF04: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800BEF08: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800BEF0C: addiu       $s0, $s0, -0x7A50
    ctx->r16 = ADD32(ctx->r16, -0X7A50);
    // 0x800BEF10: lbu         $t6, 0x56($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X56);
    // 0x800BEF14: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BEF18: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800BEF1C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800BEF20: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800BEF24: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800BEF28: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800BEF2C: beq         $t6, $zero, L_800BF044
    if (ctx->r14 == 0) {
        // 0x800BEF30: sw          $zero, 0x1B0($s0)
        MEM_W(0X1B0, ctx->r16) = 0;
            goto L_800BF044;
    }
    // 0x800BEF30: sw          $zero, 0x1B0($s0)
    MEM_W(0X1B0, ctx->r16) = 0;
    // 0x800BEF34: andi        $t8, $a3, 0x1F00
    ctx->r24 = ctx->r7 & 0X1F00;
    // 0x800BEF38: addiu       $at, $zero, 0x1F00
    ctx->r1 = ADD32(0, 0X1F00);
    // 0x800BEF3C: beq         $t8, $at, L_800BEFAC
    if (ctx->r24 == ctx->r1) {
        // 0x800BEF40: or          $t7, $a3, $zero
        ctx->r15 = ctx->r7 | 0;
            goto L_800BEFAC;
    }
    // 0x800BEF40: or          $t7, $a3, $zero
    ctx->r15 = ctx->r7 | 0;
    // 0x800BEF44: lbu         $t9, 0x77($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X77);
    // 0x800BEF48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BEF4C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800BEF50: beq         $t9, $zero, L_800BEF68
    if (ctx->r25 == 0) {
        // 0x800BEF54: lw          $a2, 0x34($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X34);
            goto L_800BEF68;
    }
    // 0x800BEF54: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800BEF58: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800BEF5C: jal         0x80087FB0
    // 0x800BEF60: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    _gcmapsects_entrypoint_22(rdram, ctx);
        goto after_0;
    // 0x800BEF60: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x800BEF64: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
L_800BEF68:
    // 0x800BEF68: bnel        $t0, $zero, L_800BEFB0
    if (ctx->r8 != 0) {
        // 0x800BEF6C: lbu         $t8, 0x55($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X55);
            goto L_800BEFB0;
    }
    goto skip_0;
    // 0x800BEF6C: lbu         $t8, 0x55($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X55);
    skip_0:
    // 0x800BEF70: lbu         $t1, 0x2A($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X2A);
    // 0x800BEF74: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800BEF78: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800BEF7C: beq         $t1, $zero, L_800BEFAC
    if (ctx->r9 == 0) {
        // 0x800BEF80: lw          $t5, 0x38($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X38);
            goto L_800BEFAC;
    }
    // 0x800BEF80: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800BEF84: lbu         $t2, 0x29($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X29);
    // 0x800BEF88: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800BEF8C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800BEF90: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800BEF94: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x800BEF98: lw          $a1, 0x10($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X10);
    // 0x800BEF9C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800BEFA0: jal         0x800AB0BC
    // 0x800BEFA4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    func_800AB0BC(rdram, ctx);
        goto after_1;
    // 0x800BEFA4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_1:
    // 0x800BEFA8: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
L_800BEFAC:
    // 0x800BEFAC: lbu         $t8, 0x55($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X55);
L_800BEFB0:
    // 0x800BEFB0: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800BEFB4: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800BEFB8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800BEFBC: addu        $t7, $s0, $t9
    ctx->r15 = ADD32(ctx->r16, ctx->r25);
    // 0x800BEFC0: lw          $a1, 0x3C($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X3C);
    // 0x800BEFC4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800BEFC8: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x800BEFCC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800BEFD0: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800BEFD4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800BEFD8: jal         0x800AB0BC
    // 0x800BEFDC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    func_800AB0BC(rdram, ctx);
        goto after_2;
    // 0x800BEFDC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_2:
    // 0x800BEFE0: beq         $v0, $zero, L_800BEFF4
    if (ctx->r2 == 0) {
        // 0x800BEFE4: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_800BEFF4;
    }
    // 0x800BEFE4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800BEFE8: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x800BEFEC: b           L_800BF0CC
    // 0x800BEFF0: sw          $t3, 0x1B0($s0)
    MEM_W(0X1B0, ctx->r16) = ctx->r11;
        goto L_800BF0CC;
    // 0x800BEFF0: sw          $t3, 0x1B0($s0)
    MEM_W(0X1B0, ctx->r16) = ctx->r11;
L_800BEFF4:
    // 0x800BEFF4: lbu         $t4, 0x77($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X77);
    // 0x800BEFF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BEFFC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800BF000: beq         $t4, $zero, L_800BF02C
    if (ctx->r12 == 0) {
        // 0x800BF004: lw          $a2, 0x34($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X34);
            goto L_800BF02C;
    }
    // 0x800BF004: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800BF008: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800BF00C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800BF010: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800BF014: jal         0x80087FB0
    // 0x800BF018: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    _gcmapsects_entrypoint_22(rdram, ctx);
        goto after_3;
    // 0x800BF018: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_3:
    // 0x800BF01C: beq         $v0, $zero, L_800BF02C
    if (ctx->r2 == 0) {
        // 0x800BF020: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_800BF02C;
    }
    // 0x800BF020: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800BF024: b           L_800BF0D0
    // 0x800BF028: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800BF0D0;
    // 0x800BF028: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800BF02C:
    // 0x800BF02C: beq         $t0, $zero, L_800BF03C
    if (ctx->r8 == 0) {
        // 0x800BF030: nop
    
            goto L_800BF03C;
    }
    // 0x800BF030: nop

    // 0x800BF034: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800BF038: sw          $t6, 0x1B0($s0)
    MEM_W(0X1B0, ctx->r16) = ctx->r14;
L_800BF03C:
    // 0x800BF03C: b           L_800BF0CC
    // 0x800BF040: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_800BF0CC;
    // 0x800BF040: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_800BF044:
    // 0x800BF044: lbu         $t8, 0x77($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X77);
    // 0x800BF048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BF04C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800BF050: beq         $t8, $zero, L_800BF06C
    if (ctx->r24 == 0) {
        // 0x800BF054: lw          $a2, 0x34($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X34);
            goto L_800BF06C;
    }
    // 0x800BF054: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800BF058: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800BF05C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800BF060: jal         0x80087FB0
    // 0x800BF064: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    _gcmapsects_entrypoint_22(rdram, ctx);
        goto after_4;
    // 0x800BF064: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_4:
    // 0x800BF068: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
L_800BF06C:
    // 0x800BF06C: bne         $t0, $zero, L_800BF0B0
    if (ctx->r8 != 0) {
        // 0x800BF070: nop
    
            goto L_800BF0B0;
    }
    // 0x800BF070: nop

    // 0x800BF074: lbu         $t7, 0x2A($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X2A);
    // 0x800BF078: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800BF07C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800BF080: beq         $t7, $zero, L_800BF0B0
    if (ctx->r15 == 0) {
        // 0x800BF084: lw          $t4, 0x38($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X38);
            goto L_800BF0B0;
    }
    // 0x800BF084: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800BF088: lbu         $t1, 0x29($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X29);
    // 0x800BF08C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800BF090: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800BF094: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800BF098: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x800BF09C: lw          $a1, 0x10($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X10);
    // 0x800BF0A0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800BF0A4: jal         0x800AB0BC
    // 0x800BF0A8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    func_800AB0BC(rdram, ctx);
        goto after_5;
    // 0x800BF0A8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_5:
    // 0x800BF0AC: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
L_800BF0B0:
    // 0x800BF0B0: beql        $t0, $zero, L_800BF0CC
    if (ctx->r8 == 0) {
        // 0x800BF0B4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800BF0CC;
    }
    goto skip_1;
    // 0x800BF0B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800BF0B8: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800BF0BC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800BF0C0: b           L_800BF0CC
    // 0x800BF0C4: sw          $t6, 0x1B0($s0)
    MEM_W(0X1B0, ctx->r16) = ctx->r14;
        goto L_800BF0CC;
    // 0x800BF0C4: sw          $t6, 0x1B0($s0)
    MEM_W(0X1B0, ctx->r16) = ctx->r14;
    // 0x800BF0C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BF0CC:
    // 0x800BF0CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800BF0D0:
    // 0x800BF0D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800BF0D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800BF0D8: jr          $ra
    // 0x800BF0DC: nop

    return;
    // 0x800BF0DC: nop

;}
RECOMP_FUNC void func_80800F98_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FA0: jal         0x80800E48
    // 0x80800FA4: nop

    func_80800E48_chflysaucer(rdram, ctx);
        goto after_0;
    // 0x80800FA4: nop

    after_0:
    // 0x80800FA8: sltiu       $at, $v0, 0x6
    ctx->r1 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x80800FAC: beq         $at, $zero, L_80800FE0
    if (ctx->r1 == 0) {
        // 0x80800FB0: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_80800FE0;
    }
    // 0x80800FB0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80800FB4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X3E7C) << 16);
    // 0x80800FB8: addu        $at, $at, $t6
    gpr jr_addend_80800FC0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800FBC: lw          $t6, 0x3E7C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1692, 0X3E7C));
    // 0x80800FC0: jr          $t6
    // 0x80800FC4: nop

    switch (jr_addend_80800FC0 >> 2) {
        case 0: goto L_80800FC8; break;
        case 1: goto L_80800FD8; break;
        case 2: goto L_80800FD8; break;
        case 3: goto L_80800FD8; break;
        case 4: goto L_80800FD8; break;
        case 5: goto L_80800FC8; break;
        default: switch_error(__func__, 0x80800FC0, 0x80803E7C);
    }
    // 0x80800FC4: nop

L_80800FC8:
    // 0x80800FC8: jal         0x800FC6B0
    // 0x80800FCC: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_1;
    // 0x80800FCC: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_1:
    // 0x80800FD0: b           L_80800FE4
    // 0x80800FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800FE4;
    // 0x80800FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800FD8:
    // 0x80800FD8: jal         0x800FC6B0
    // 0x80800FDC: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_2;
    // 0x80800FDC: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_2:
L_80800FE0:
    // 0x80800FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800FE4:
    // 0x80800FE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800FE8: jr          $ra
    // 0x80800FEC: nop

    return;
    // 0x80800FEC: nop

;}
RECOMP_FUNC void func_808006AC_bscarry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006B4: jal         0x80082FE8
    // 0x808006B8: nop

    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808006B8: nop

    after_0:
    // 0x808006BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006C4: jr          $ra
    // 0x808006C8: nop

    return;
    // 0x808006C8: nop

;}
RECOMP_FUNC void boot___ll_lshift(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800028B4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800028B8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800028BC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800028C0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800028C4: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x800028C8: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x800028CC: dsllv       $v0, $t6, $t7
    ctx->r2 = ctx->r14 << (ctx->r15 & 63);
    // 0x800028D0: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x800028D4: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x800028D8: jr          $ra
    // 0x800028DC: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    return;
    // 0x800028DC: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
;}
RECOMP_FUNC void func_80801CB0_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CB0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80801CB4: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80801CB8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80801CBC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80801CC0: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x80801CC4: lhu         $v1, 0x4($t7)
    ctx->r3 = MEM_HU(ctx->r15, 0X4);
    // 0x80801CC8: xori        $v0, $v1, 0x6B54
    ctx->r2 = ctx->r3 ^ 0X6B54;
    // 0x80801CCC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80801CD0: bne         $v0, $zero, L_80801CE0
    if (ctx->r2 != 0) {
        // 0x80801CD4: nop
    
            goto L_80801CE0;
    }
    // 0x80801CD4: nop

    // 0x80801CD8: xori        $v0, $v1, 0xC
    ctx->r2 = ctx->r3 ^ 0XC;
    // 0x80801CDC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80801CE0:
    // 0x80801CE0: jr          $ra
    // 0x80801CE4: nop

    return;
    // 0x80801CE4: nop

;}
RECOMP_FUNC void _idbounce_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088CB0: syscall     733
    recomp_syscall_handler(rdram, ctx, 0x80088CB0);
    return;
    // 0x80088CB4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void idflame_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800048: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8080004C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800050: sll         $t6, $a3, 4
    ctx->r14 = S32(ctx->r7 << 4);
    // 0x80800054: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80800058: addu        $s5, $t6, $a1
    ctx->r21 = ADD32(ctx->r14, ctx->r5);
    // 0x8080005C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800060: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800064: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800068: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080006C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800070: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800074: sltu        $at, $a1, $s5
    ctx->r1 = ctx->r5 < ctx->r21 ? 1 : 0;
    // 0x80800078: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8080007C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80800080: beq         $at, $zero, L_8080010C
    if (ctx->r1 == 0) {
        // 0x80800084: lh          $s4, 0x8($s2)
        ctx->r20 = MEM_H(ctx->r18, 0X8);
            goto L_8080010C;
    }
    // 0x80800084: lh          $s4, 0x8($s2)
    ctx->r20 = MEM_H(ctx->r18, 0X8);
L_80800088:
    // 0x80800088: lh          $t7, 0xA($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XA);
    // 0x8080008C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800090: addu        $t8, $t7, $s4
    ctx->r24 = ADD32(ctx->r15, ctx->r20);
    // 0x80800094: sh          $t8, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r24;
    // 0x80800098: jal         0x80800000
    // 0x8080009C: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    func_80800000_idflame(rdram, ctx);
        goto after_0;
    // 0x8080009C: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    after_0:
    // 0x808000A0: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x808000A4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x808000A8: addu        $v1, $s2, $t9
    ctx->r3 = ADD32(ctx->r18, ctx->r25);
    // 0x808000AC: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x808000B0: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x808000B4: lwc1        $f16, 0x3C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x808000B8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808000BC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808000C0: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x808000C4: mul.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x808000C8: jal         0x8001395C
    // 0x808000CC: nop

    func_8001395C(rdram, ctx);
        goto after_1;
    // 0x808000CC: nop

    after_1:
    // 0x808000D0: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x808000D4: sll         $t1, $s3, 2
    ctx->r9 = S32(ctx->r19 << 2);
    // 0x808000D8: addu        $t2, $s2, $t1
    ctx->r10 = ADD32(ctx->r18, ctx->r9);
    // 0x808000DC: lwc1        $f18, 0x7C($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X7C);
    // 0x808000E0: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x808000E4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x808000E8: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808000EC: sltu        $at, $s0, $s5
    ctx->r1 = ctx->r16 < ctx->r21 ? 1 : 0;
    // 0x808000F0: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x808000F4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808000F8: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808000FC: trunc.w.s   $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800100: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80800104: bne         $at, $zero, L_80800088
    if (ctx->r1 != 0) {
        // 0x80800108: sh          $t5, -0x10($s1)
        MEM_H(-0X10, ctx->r17) = ctx->r13;
            goto L_80800088;
    }
    // 0x80800108: sh          $t5, -0x10($s1)
    MEM_H(-0X10, ctx->r17) = ctx->r13;
L_8080010C:
    // 0x8080010C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800110: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800114: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800118: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8080011C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800120: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80800124: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80800128: jr          $ra
    // 0x8080012C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8080012C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void suquiz_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800810: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800814: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800818: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080081C: jal         0x800DA298
    // 0x80800820: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800820: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    after_0:
    // 0x80800824: beq         $v0, $zero, L_8080083C
    if (ctx->r2 == 0) {
        // 0x80800828: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080083C;
    }
    // 0x80800828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080082C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80800830: lw          $t6, 0x7614($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7614);
    // 0x80800834: b           L_80800840
    // 0x80800838: lb          $v0, 0x27($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X27);
        goto L_80800840;
    // 0x80800838: lb          $v0, 0x27($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X27);
L_8080083C:
    // 0x8080083C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800840:
    // 0x80800840: jr          $ra
    // 0x80800844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void gcfrontend_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001C8: jal         0x80800450
    // 0x808001CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800450_gcfrontend(rdram, ctx);
        goto after_0;
    // 0x808001CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001D0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x808001D4: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x808001D8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2650, 0XD80) << 16);
    // 0x808001DC: addiu       $t7, $t7, 0xD80
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2650, 0XD80));
    // 0x808001E0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808001E4: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x808001E8: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x808001EC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x808001F0: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x808001F4: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x808001F8: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x808001FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800200: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x80800204: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80800208: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x8080020C: lbu         $v0, 0xC($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0XC);
    // 0x80800210: jr          $ra
    // 0x80800214: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800214: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void chdiggerbossdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1484, 0X430) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x430
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1484, 0X430));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x430
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1484, 0X430));
;}
RECOMP_FUNC void func_808003B8_chfriesstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808003BC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808003C0: slti        $at, $a1, 0x53
    ctx->r1 = SIGNED(ctx->r5) < 0X53 ? 1 : 0;
    // 0x808003C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003CC: bne         $at, $zero, L_808003F0
    if (ctx->r1 != 0) {
        // 0x808003D0: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_808003F0;
    }
    // 0x808003D0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808003D4: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808003D8: beq         $a1, $at, L_80800558
    if (ctx->r5 == ctx->r1) {
        // 0x808003DC: addiu       $at, $zero, 0xB8
        ctx->r1 = ADD32(0, 0XB8);
            goto L_80800558;
    }
    // 0x808003DC: addiu       $at, $zero, 0xB8
    ctx->r1 = ADD32(0, 0XB8);
    // 0x808003E0: beq         $a1, $at, L_80800578
    if (ctx->r5 == ctx->r1) {
        // 0x808003E4: lw          $v0, 0x30($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X30);
            goto L_80800578;
    }
    // 0x808003E4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x808003E8: b           L_808005DC
    // 0x808003EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005DC;
    // 0x808003EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003F0:
    // 0x808003F0: slti        $at, $a1, 0xB
    ctx->r1 = SIGNED(ctx->r5) < 0XB ? 1 : 0;
    // 0x808003F4: bne         $at, $zero, L_8080041C
    if (ctx->r1 != 0) {
        // 0x808003F8: addiu       $t6, $a1, -0x29
        ctx->r14 = ADD32(ctx->r5, -0X29);
            goto L_8080041C;
    }
    // 0x808003F8: addiu       $t6, $a1, -0x29
    ctx->r14 = ADD32(ctx->r5, -0X29);
    // 0x808003FC: sltiu       $at, $t6, 0x2A
    ctx->r1 = ctx->r14 < 0X2A ? 1 : 0;
    // 0x80800400: beq         $at, $zero, L_80800428
    if (ctx->r1 == 0) {
        // 0x80800404: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800428;
    }
    // 0x80800404: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800408: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(940, 0XD98) << 16);
    // 0x8080040C: addu        $at, $at, $t6
    gpr jr_addend_80800414 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800410: lw          $t6, 0xD98($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(940, 0XD98));
    // 0x80800414: jr          $t6
    // 0x80800418: nop

    switch (jr_addend_80800414 >> 2) {
        case 0: goto L_80800538; break;
        case 1: goto L_80800548; break;
        case 2: goto L_80800428; break;
        case 3: goto L_80800428; break;
        case 4: goto L_80800428; break;
        case 5: goto L_80800430; break;
        case 6: goto L_8080044C; break;
        case 7: goto L_80800428; break;
        case 8: goto L_80800428; break;
        case 9: goto L_80800468; break;
        case 10: goto L_80800428; break;
        case 11: goto L_80800428; break;
        case 12: goto L_80800428; break;
        case 13: goto L_80800428; break;
        case 14: goto L_80800428; break;
        case 15: goto L_80800428; break;
        case 16: goto L_80800428; break;
        case 17: goto L_80800428; break;
        case 18: goto L_80800428; break;
        case 19: goto L_80800428; break;
        case 20: goto L_8080047C; break;
        case 21: goto L_80800428; break;
        case 22: goto L_80800428; break;
        case 23: goto L_80800428; break;
        case 24: goto L_80800428; break;
        case 25: goto L_80800428; break;
        case 26: goto L_80800428; break;
        case 27: goto L_80800428; break;
        case 28: goto L_80800428; break;
        case 29: goto L_80800428; break;
        case 30: goto L_80800428; break;
        case 31: goto L_80800428; break;
        case 32: goto L_80800428; break;
        case 33: goto L_80800428; break;
        case 34: goto L_80800428; break;
        case 35: goto L_80800428; break;
        case 36: goto L_80800428; break;
        case 37: goto L_80800428; break;
        case 38: goto L_80800428; break;
        case 39: goto L_80800428; break;
        case 40: goto L_80800428; break;
        case 41: goto L_8080048C; break;
        default: switch_error(__func__, 0x80800414, 0x80800D98);
    }
    // 0x80800418: nop

L_8080041C:
    // 0x8080041C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800420: beql        $a1, $at, L_808004A8
    if (ctx->r5 == ctx->r1) {
        // 0x80800424: lbu         $t8, 0x65($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X65);
            goto L_808004A8;
    }
    goto skip_0;
    // 0x80800424: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    skip_0:
L_80800428:
    // 0x80800428: b           L_808005DC
    // 0x8080042C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005DC;
    // 0x8080042C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800430:
    // 0x80800430: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x80800434: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800438: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x8080043C: jal         0x808009F0
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808009F0_chfriesstand(rdram, ctx);
        goto after_0;
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800444: b           L_808005DC
    // 0x80800448: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x80800448: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080044C:
    // 0x8080044C: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x80800450: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800454: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800458: jal         0x80800AEC
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800AEC_chfriesstand(rdram, ctx);
        goto after_1;
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800460: b           L_808005DC
    // 0x80800464: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x80800464: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800468:
    // 0x80800468: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8080046C: jal         0x80090734
    // 0x80800470: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_80090734(rdram, ctx);
        goto after_2;
    // 0x80800470: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x80800474: b           L_808005DC
    // 0x80800478: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x80800478: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080047C:
    // 0x8080047C: jal         0x80800BB0
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800BB0_chfriesstand(rdram, ctx);
        goto after_3;
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800484: b           L_808005DC
    // 0x80800488: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x80800488: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080048C:
    // 0x8080048C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(940, 0XFF0) << 16);
    // 0x80800490: addiu       $a0, $a0, 0xFF0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(940, 0XFF0));
    // 0x80800494: jal         0x80088090
    // 0x80800498: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800498: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x8080049C: b           L_808005DC
    // 0x808004A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x808004A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808004A4: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
L_808004A8:
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808004B0: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x808004B4: jal         0x80102424
    // 0x808004B8: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x808004B8: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    after_5:
    // 0x808004BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C0: jal         0x80101EE4
    // 0x808004C4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80101EE4(rdram, ctx);
        goto after_6;
    // 0x808004C4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004CC: jal         0x80103110
    // 0x808004D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_7;
    // 0x808004D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808004D4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x808004D8: beql        $a0, $zero, L_80800504
    if (ctx->r4 == 0) {
        // 0x808004DC: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80800504;
    }
    goto skip_1;
    // 0x808004DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x808004E0: jal         0x80106790
    // 0x808004E4: nop

    func_80106790(rdram, ctx);
        goto after_8;
    // 0x808004E4: nop

    after_8:
    // 0x808004E8: lhu         $t1, 0x64($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X64);
    // 0x808004EC: lbu         $t3, 0x65($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X65);
    // 0x808004F0: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x808004F4: andi        $t4, $t3, 0xFFFE
    ctx->r12 = ctx->r11 & 0XFFFE;
    // 0x808004F8: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x808004FC: sb          $t5, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r13;
    // 0x80800500: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80800504:
    // 0x80800504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800508: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x8080050C: jal         0x80085708
    // 0x80800510: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    _capod_entrypoint_13(rdram, ctx);
        goto after_9;
    // 0x80800510: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_9:
    // 0x80800514: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800518: addiu       $t6, $zero, 0x51
    ctx->r14 = ADD32(0, 0X51);
    // 0x8080051C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800520: addiu       $a1, $zero, 0x10E0
    ctx->r5 = ADD32(0, 0X10E0);
    // 0x80800524: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800528: jal         0x8008A208
    // 0x8080052C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_10;
    // 0x8080052C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_10:
    // 0x80800530: b           L_808005DC
    // 0x80800534: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x80800534: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800538:
    // 0x80800538: jal         0x80800904
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800904_chfriesstand(rdram, ctx);
        goto after_11;
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800540: b           L_808005DC
    // 0x80800544: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x80800544: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800548:
    // 0x80800548: jal         0x80800970
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800970_chfriesstand(rdram, ctx);
        goto after_12;
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800550: b           L_808005DC
    // 0x80800554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x80800554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800558:
    // 0x80800558: jal         0x800D1A04
    // 0x8080055C: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    func_800D1A04(rdram, ctx);
        goto after_13;
    // 0x8080055C: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    after_13:
    // 0x80800560: bne         $v0, $zero, L_808005D8
    if (ctx->r2 != 0) {
        // 0x80800564: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005D8;
    }
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800568: jal         0x80108B04
    // 0x8080056C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_14;
    // 0x8080056C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80800570: b           L_808005DC
    // 0x80800574: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x80800574: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800578:
    // 0x80800578: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x8080057C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800580: beq         $t7, $at, L_80800598
    if (ctx->r15 == ctx->r1) {
        // 0x80800584: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800598;
    }
    // 0x80800584: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800588: beql        $t7, $at, L_808005BC
    if (ctx->r15 == ctx->r1) {
        // 0x8080058C: lw          $t9, 0x3C($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X3C);
            goto L_808005BC;
    }
    goto skip_2;
    // 0x8080058C: lw          $t9, 0x3C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X3C);
    skip_2:
    // 0x80800590: b           L_808005DC
    // 0x80800594: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005DC;
    // 0x80800594: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800598:
    // 0x80800598: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x8080059C: addiu       $v1, $zero, 0x10AF
    ctx->r3 = ADD32(0, 0X10AF);
    // 0x808005A0: beq         $t8, $zero, L_808005B0
    if (ctx->r24 == 0) {
        // 0x808005A4: nop
    
            goto L_808005B0;
    }
    // 0x808005A4: nop

    // 0x808005A8: b           L_808005DC
    // 0x808005AC: addiu       $v0, $zero, 0x10AE
    ctx->r2 = ADD32(0, 0X10AE);
        goto L_808005DC;
    // 0x808005AC: addiu       $v0, $zero, 0x10AE
    ctx->r2 = ADD32(0, 0X10AE);
L_808005B0:
    // 0x808005B0: b           L_808005DC
    // 0x808005B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_808005DC;
    // 0x808005B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808005B8: lw          $t9, 0x3C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X3C);
L_808005BC:
    // 0x808005BC: addiu       $v1, $zero, 0x110A
    ctx->r3 = ADD32(0, 0X110A);
    // 0x808005C0: beq         $t9, $zero, L_808005D0
    if (ctx->r25 == 0) {
        // 0x808005C4: nop
    
            goto L_808005D0;
    }
    // 0x808005C4: nop

    // 0x808005C8: b           L_808005DC
    // 0x808005CC: addiu       $v0, $zero, 0x1109
    ctx->r2 = ADD32(0, 0X1109);
        goto L_808005DC;
    // 0x808005CC: addiu       $v0, $zero, 0x1109
    ctx->r2 = ADD32(0, 0X1109);
L_808005D0:
    // 0x808005D0: b           L_808005DC
    // 0x808005D4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_808005DC;
    // 0x808005D4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_808005D8:
    // 0x808005D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005DC:
    // 0x808005DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808005E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005E8: jr          $ra
    // 0x808005EC: nop

    return;
    // 0x808005EC: nop

;}
RECOMP_FUNC void func_808078F4_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808078F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808078F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808078FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80807900: jal         0x80802484
    // 0x80807904: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80802484_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80807904: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80807908: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8080790C: jal         0x80802458
    // 0x80807910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802458_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80807910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80807914: jal         0x800D3948
    // 0x80807918: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_800D3948(rdram, ctx);
        goto after_2;
    // 0x80807918: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_2:
    // 0x8080791C: bne         $v0, $zero, L_80807968
    if (ctx->r2 != 0) {
        // 0x80807920: nop
    
            goto L_80807968;
    }
    // 0x80807920: nop

    // 0x80807924: jal         0x8009EA2C
    // 0x80807928: nop

    func_8009EA2C(rdram, ctx);
        goto after_3;
    // 0x80807928: nop

    after_3:
    // 0x8080792C: beq         $v0, $zero, L_80807950
    if (ctx->r2 == 0) {
        // 0x80807930: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80807950;
    }
    // 0x80807930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807934: addiu       $t6, $zero, 0x726
    ctx->r14 = ADD32(0, 0X726);
    // 0x80807938: addiu       $t7, $zero, 0x725
    ctx->r15 = ADD32(0, 0X725);
    // 0x8080793C: sh          $t6, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r14;
    // 0x80807940: sh          $t7, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r15;
    // 0x80807944: sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
    // 0x80807948: b           L_8080798C
    // 0x8080794C: sh          $zero, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = 0;
        goto L_8080798C;
    // 0x8080794C: sh          $zero, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = 0;
L_80807950:
    // 0x80807950: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80807954: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80807958: jal         0x80802AA8
    // 0x8080795C: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    func_80802AA8_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x8080795C: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_4:
    // 0x80807960: b           L_8080798C
    // 0x80807964: nop

        goto L_8080798C;
    // 0x80807964: nop

L_80807968:
    // 0x80807968: jal         0x800A940C
    // 0x8080796C: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800A940C(rdram, ctx);
        goto after_5;
    // 0x8080796C: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_5:
    // 0x80807970: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x80807974: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80807978: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8080797C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807980: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80807984: jal         0x80802AA8
    // 0x80807988: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    func_80802AA8_bsfirstp(rdram, ctx);
        goto after_6;
    // 0x80807988: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_6:
L_8080798C:
    // 0x8080798C: jal         0x800D3948
    // 0x80807990: nop

    func_800D3948(rdram, ctx);
        goto after_7;
    // 0x80807990: nop

    after_7:
    // 0x80807994: beq         $v0, $zero, L_808079A8
    if (ctx->r2 == 0) {
        // 0x80807998: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808079A8;
    }
    // 0x80807998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080799C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x808079A0: b           L_808079B4
    // 0x808079A4: lwc1        $f0, 0x44($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X44);
        goto L_808079B4;
    // 0x808079A4: lwc1        $f0, 0x44($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X44);
L_808079A8:
    // 0x808079A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808079AC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808079B0: nop

L_808079B4:
    // 0x808079B4: lh          $a1, 0x2C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2C);
    // 0x808079B8: jal         0x80092EC8
    // 0x808079BC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_80092EC8(rdram, ctx);
        goto after_8;
    // 0x808079BC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x808079C0: lh          $t0, 0x28($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X28);
    // 0x808079C4: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808079C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808079CC: beq         $t0, $zero, L_808079E0
    if (ctx->r8 == 0) {
        // 0x808079D0: or          $a1, $t0, $zero
        ctx->r5 = ctx->r8 | 0;
            goto L_808079E0;
    }
    // 0x808079D0: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x808079D4: jal         0x8009312C
    // 0x808079D8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_8009312C(rdram, ctx);
        goto after_9;
    // 0x808079D8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x808079DC: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
L_808079E0:
    // 0x808079E0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808079E4: jal         0x80093230
    // 0x808079E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80093230(rdram, ctx);
        goto after_10;
    // 0x808079E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808079EC: jal         0x8008CF7C
    // 0x808079F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008CF7C(rdram, ctx);
        goto after_11;
    // 0x808079F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808079F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808079F8: jal         0x800936CC
    // 0x808079FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800936CC(rdram, ctx);
        goto after_12;
    // 0x808079FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
    // 0x80807A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807A04: jal         0x8009359C
    // 0x80807A08: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    func_8009359C(rdram, ctx);
        goto after_13;
    // 0x80807A08: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    after_13:
    // 0x80807A0C: lh          $t1, 0x2A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2A);
    // 0x80807A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807A14: beql        $t1, $zero, L_80807A28
    if (ctx->r9 == 0) {
        // 0x80807A18: lw          $t2, 0x30($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X30);
            goto L_80807A28;
    }
    goto skip_0;
    // 0x80807A18: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x80807A1C: jal         0x8009316C
    // 0x80807A20: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    func_8009316C(rdram, ctx);
        goto after_14;
    // 0x80807A20: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_14:
    // 0x80807A24: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
L_80807A28:
    // 0x80807A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807A2C: jal         0x800936D8
    // 0x80807A30: lw          $a1, 0xC($t2)
    ctx->r5 = MEM_W(ctx->r10, 0XC);
    func_800936D8(rdram, ctx);
        goto after_15;
    // 0x80807A30: lw          $a1, 0xC($t2)
    ctx->r5 = MEM_W(ctx->r10, 0XC);
    after_15:
    // 0x80807A34: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80807A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807A3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80807A40: jal         0x8009E55C
    // 0x80807A44: lw          $a2, 0x0($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X0);
    func_8009E55C(rdram, ctx);
        goto after_16;
    // 0x80807A44: lw          $a2, 0x0($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X0);
    after_16:
    // 0x80807A48: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80807A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807A50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80807A54: jal         0x8009E55C
    // 0x80807A58: lw          $a2, 0x4($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X4);
    func_8009E55C(rdram, ctx);
        goto after_17;
    // 0x80807A58: lw          $a2, 0x4($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X4);
    after_17:
    // 0x80807A5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80807A60: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80807A64: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80807A68: jr          $ra
    // 0x80807A6C: nop

    return;
    // 0x80807A6C: nop

;}
RECOMP_FUNC void _sufade_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A8F8: syscall     855
    recomp_syscall_handler(rdram, ctx, 0x8008A8F8);
    return;
    // 0x8008A8FC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800AF4_chdinofamilysmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AF8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800AFC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800B00: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800B04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B08: beq         $a1, $at, L_80800B3C
    if (ctx->r5 == ctx->r1) {
        // 0x80800B0C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80800B3C;
    }
    // 0x80800B0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800B10: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80800B14: beq         $a1, $at, L_80800B90
    if (ctx->r5 == ctx->r1) {
        // 0x80800B18: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80800B90;
    }
    // 0x80800B18: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800B1C: addiu       $at, $zero, 0x4B
    ctx->r1 = ADD32(0, 0X4B);
    // 0x80800B20: beq         $a1, $at, L_80800B5C
    if (ctx->r5 == ctx->r1) {
        // 0x80800B24: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80800B5C;
    }
    // 0x80800B24: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800B28: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800B2C: beq         $a1, $at, L_80800B6C
    if (ctx->r5 == ctx->r1) {
        // 0x80800B30: addiu       $a0, $a2, 0x4
        ctx->r4 = ADD32(ctx->r6, 0X4);
            goto L_80800B6C;
    }
    // 0x80800B30: addiu       $a0, $a2, 0x4
    ctx->r4 = ADD32(ctx->r6, 0X4);
    // 0x80800B34: b           L_80800C00
    // 0x80800B38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800C00;
    // 0x80800B38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B3C:
    // 0x80800B3C: jal         0x80085710
    // 0x80800B40: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800B40: nop

    after_0:
    // 0x80800B44: addiu       $a0, $zero, 0x290
    ctx->r4 = ADD32(0, 0X290);
    // 0x80800B48: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    // 0x80800B4C: jal         0x80101180
    // 0x80800B50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80101180(rdram, ctx);
        goto after_1;
    // 0x80800B50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80800B54: b           L_80800C00
    // 0x80800B58: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800C00;
    // 0x80800B58: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800B5C:
    // 0x80800B5C: jal         0x80101FDC
    // 0x80800B60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800B60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800B64: b           L_80800C00
    // 0x80800B68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800C00;
    // 0x80800B68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B6C:
    // 0x80800B6C: jal         0x80088098
    // 0x80800B70: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800B70: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_3:
    // 0x80800B74: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800B78: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2404, 0XF10) << 16);
    // 0x80800B7C: addiu       $a0, $a0, 0xF10
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2404, 0XF10));
    // 0x80800B80: jal         0x80088090
    // 0x80800B84: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800B84: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_4:
    // 0x80800B88: b           L_80800C00
    // 0x80800B8C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800C00;
    // 0x80800B8C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800B90:
    // 0x80800B90: jal         0x801015D0
    // 0x80800B94: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_801015D0(rdram, ctx);
        goto after_5;
    // 0x80800B94: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_5:
    // 0x80800B98: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800B9C: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2404, 0XE94) << 16);
    // 0x80800BA0: addiu       $at, $zero, 0x14D
    ctx->r1 = ADD32(0, 0X14D);
    // 0x80800BA4: lhu         $t6, 0x72($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X72);
    // 0x80800BA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800BAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800BB0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800BB4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80800BB8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80800BBC: lhu         $t9, 0xE94($t9)
    ctx->r25 = MEM_HU(ctx->r25, (int16_t)RELOC_LO16(2404, 0XE94));
    // 0x80800BC0: bne         $t9, $at, L_80800BD8
    if (ctx->r25 != ctx->r1) {
        // 0x80800BC4: nop
    
            goto L_80800BD8;
    }
    // 0x80800BC4: nop

    // 0x80800BC8: jal         0x800DF744
    // 0x80800BCC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_6;
    // 0x80800BCC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_6:
    // 0x80800BD0: b           L_80800C00
    // 0x80800BD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800C00;
    // 0x80800BD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800BD8:
    // 0x80800BD8: jal         0x800DF744
    // 0x80800BDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_7;
    // 0x80800BDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800BE0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800BE4: jal         0x800DF744
    // 0x80800BE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_8;
    // 0x80800BE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800BEC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800BF0: jal         0x800DF744
    // 0x80800BF4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_9;
    // 0x80800BF4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x80800BF8: b           L_80800C00
    // 0x80800BFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800C00;
    // 0x80800BFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C00:
    // 0x80800C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C08: jr          $ra
    // 0x80800C0C: nop

    return;
    // 0x80800C0C: nop

;}
RECOMP_FUNC void func_800B27FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B27FC: lh          $t6, 0x8($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X8);
    // 0x800B2800: jr          $ra
    // 0x800B2804: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    return;
    // 0x800B2804: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
;}
RECOMP_FUNC void suegg_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808001F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800200: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800204: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800208: jal         0x80100094
    // 0x8080020C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080020C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800210: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80800214: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x80800218: bltzl       $t8, L_80800298
    if (SIGNED(ctx->r24) < 0) {
        // 0x8080021C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800298;
    }
    goto skip_0;
    // 0x8080021C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800220: lw          $t9, 0x38($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X38);
    // 0x80800224: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800228: sll         $t1, $t9, 9
    ctx->r9 = S32(ctx->r25 << 9);
    // 0x8080022C: bltz        $t1, L_8080028C
    if (SIGNED(ctx->r9) < 0) {
        // 0x80800230: nop
    
            goto L_8080028C;
    }
    // 0x80800230: nop

    // 0x80800234: lbu         $t2, 0x39($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X39);
    // 0x80800238: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x8080023C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(3322, 0XE54) << 16);
    // 0x80800240: andi        $t3, $t2, 0xFF7F
    ctx->r11 = ctx->r10 & 0XFF7F;
    // 0x80800244: sb          $t3, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r11;
    // 0x80800248: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x8080024C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80800250: addiu       $a3, $a3, 0xE54
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(3322, 0XE54));
    // 0x80800254: andi        $t4, $a1, 0x1
    ctx->r12 = ctx->r5 & 0X1;
    // 0x80800258: jal         0x8010D930
    // 0x8080025C: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    func_8010D930(rdram, ctx);
        goto after_1;
    // 0x8080025C: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    after_1:
    // 0x80800260: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80800264: beq         $t5, $zero, L_8080028C
    if (ctx->r13 == 0) {
        // 0x80800268: nop
    
            goto L_8080028C;
    }
    // 0x80800268: nop

    // 0x8080026C: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80800270: sll         $t6, $a0, 11
    ctx->r14 = S32(ctx->r4 << 11);
    // 0x80800274: jal         0x800883C0
    // 0x80800278: srl         $a0, $t6, 20
    ctx->r4 = S32(U32(ctx->r14) >> 20);
    _gcegg_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800278: srl         $a0, $t6, 20
    ctx->r4 = S32(U32(ctx->r14) >> 20);
    after_2:
    // 0x8080027C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800280: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800284: jal         0x80088A60
    // 0x80800288: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    _fxegg_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800288: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_3:
L_8080028C:
    // 0x8080028C: jal         0x800FFAB0
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800298:
    // 0x80800298: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080029C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808002A0: jr          $ra
    // 0x808002A4: nop

    return;
    // 0x808002A4: nop

;}
RECOMP_FUNC void func_801065A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801065A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801065A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801065AC: lh          $t6, 0x90($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X90);
    // 0x801065B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801065B4: beq         $t6, $zero, L_801065CC
    if (ctx->r14 == 0) {
        // 0x801065B8: nop
    
            goto L_801065CC;
    }
    // 0x801065B8: nop

    // 0x801065BC: jal         0x801063C0
    // 0x801065C0: nop

    func_801063C0(rdram, ctx);
        goto after_0;
    // 0x801065C0: nop

    after_0:
    // 0x801065C4: b           L_801065CC
    // 0x801065C8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
        goto L_801065CC;
    // 0x801065C8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_801065CC:
    // 0x801065CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801065D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801065D4: jr          $ra
    // 0x801065D8: nop

    return;
    // 0x801065D8: nop

    // 0x801065DC: nop

;}
RECOMP_FUNC void _suquiz_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A7E0: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A7E0);
    return;
    // 0x8008A7E4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_808019E0_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019E0: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x808019E4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808019E8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808019EC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808019F0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808019F4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x808019F8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x808019FC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80801A00: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80801A04: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80801A08: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80801A0C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80801A10: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    // 0x80801A14: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x80801A18: jal         0x808035FC
    // 0x80801A1C: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    func_808035FC_chjiggygamenew(rdram, ctx);
        goto after_0;
    // 0x80801A1C: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    after_0:
    // 0x80801A20: jal         0x800886D8
    // 0x80801A24: nop

    _glglobalsettings_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80801A24: nop

    after_1:
    // 0x80801A28: beq         $v0, $zero, L_80801A38
    if (ctx->r2 == 0) {
        // 0x80801A2C: lwc1        $f12, 0x68($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
            goto L_80801A38;
    }
    // 0x80801A2C: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80801A30: b           L_80801A3C
    // 0x80801A34: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80801A3C;
    // 0x80801A34: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80801A38:
    // 0x80801A38: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80801A3C:
    // 0x80801A3C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(772, 0X3D8C) << 16);
    // 0x80801A40: addiu       $t7, $t7, 0x3D8C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(772, 0X3D8C));
    // 0x80801A44: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x80801A48: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80801A4C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80801A50: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(772, 0X3BD0) << 16);
    // 0x80801A54: addiu       $s1, $s1, 0x3BD0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(772, 0X3BD0));
    // 0x80801A58: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x80801A5C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801A60: addiu       $s3, $zero, 0x14
    ctx->r19 = ADD32(0, 0X14);
    // 0x80801A64: addiu       $s2, $sp, 0x70
    ctx->r18 = ADD32(ctx->r29, 0X70);
    // 0x80801A68: bc1f        L_80801B50
    if (!c1cs) {
        // 0x80801A6C: nop
    
            goto L_80801B50;
    }
    // 0x80801A6C: nop

    // 0x80801A70: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80801A74: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80801A78: c.le.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl <= ctx->f6.fl;
    // 0x80801A7C: nop

    // 0x80801A80: bc1f        L_80801B50
    if (!c1cs) {
        // 0x80801A84: nop
    
            goto L_80801B50;
    }
    // 0x80801A84: nop

    // 0x80801A88: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80801A8C: c.le.s      $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f8.fl <= ctx->f14.fl;
    // 0x80801A90: nop

    // 0x80801A94: bc1f        L_80801B50
    if (!c1cs) {
        // 0x80801A98: nop
    
            goto L_80801B50;
    }
    // 0x80801A98: nop

    // 0x80801A9C: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80801AA0: c.le.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl <= ctx->f10.fl;
    // 0x80801AA4: nop

    // 0x80801AA8: bc1f        L_80801B50
    if (!c1cs) {
        // 0x80801AAC: nop
    
            goto L_80801B50;
    }
    // 0x80801AAC: nop

    // 0x80801AB0: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(772, 0X3AE0) << 16);
    // 0x80801AB4: addiu       $s1, $s1, 0x3AE0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(772, 0X3AE0));
    // 0x80801AB8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801ABC: addiu       $s3, $zero, 0x14
    ctx->r19 = ADD32(0, 0X14);
    // 0x80801AC0: addiu       $s2, $sp, 0x70
    ctx->r18 = ADD32(ctx->r29, 0X70);
L_80801AC4:
    // 0x80801AC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801AC8: jal         0x800E4140
    // 0x80801ACC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800E4140(rdram, ctx);
        goto after_2;
    // 0x80801ACC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x80801AD0: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    // 0x80801AD4: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80801AD8: lwc1        $f16, 0x74($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80801ADC: lwc1        $f18, 0x70($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80801AE0: bc1t        L_80801B14
    if (c1cs) {
        // 0x80801AE4: lwc1        $f10, 0x74($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
            goto L_80801B14;
    }
    // 0x80801AE4: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80801AE8: sub.s       $f0, $f14, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x80801AEC: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80801AF0: sub.s       $f2, $f12, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x80801AF4: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80801AF8: nop

    // 0x80801AFC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80801B00: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80801B04: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x80801B08: nop

    // 0x80801B0C: bc1f        L_80801B3C
    if (!c1cs) {
        // 0x80801B10: nop
    
            goto L_80801B3C;
    }
    // 0x80801B10: nop

L_80801B14:
    // 0x80801B14: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80801B18: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80801B1C: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80801B20: sub.s       $f0, $f14, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x80801B24: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x80801B28: sub.s       $f2, $f12, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x80801B2C: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80801B30: nop

    // 0x80801B34: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80801B38: add.s       $f20, $f18, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f18.fl + ctx->f4.fl;
L_80801B3C:
    // 0x80801B3C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801B40: bne         $s0, $s3, L_80801AC4
    if (ctx->r16 != ctx->r19) {
        // 0x80801B44: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80801AC4;
    }
    // 0x80801B44: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80801B48: b           L_80801BF8
    // 0x80801B4C: addiu       $v0, $s4, 0x15
    ctx->r2 = ADD32(ctx->r20, 0X15);
        goto L_80801BF8;
    // 0x80801B4C: addiu       $v0, $s4, 0x15
    ctx->r2 = ADD32(ctx->r20, 0X15);
L_80801B50:
    // 0x80801B50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801B54: jal         0x800E4140
    // 0x80801B58: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800E4140(rdram, ctx);
        goto after_3;
    // 0x80801B58: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x80801B5C: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    // 0x80801B60: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80801B64: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80801B68: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80801B6C: bc1t        L_80801BA0
    if (c1cs) {
        // 0x80801B70: lwc1        $f4, 0x74($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
            goto L_80801BA0;
    }
    // 0x80801B70: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80801B74: sub.s       $f0, $f14, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x80801B78: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80801B7C: sub.s       $f2, $f12, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x80801B80: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80801B84: nop

    // 0x80801B88: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80801B8C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80801B90: c.lt.s      $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f18.fl < ctx->f20.fl;
    // 0x80801B94: nop

    // 0x80801B98: bc1f        L_80801BC8
    if (!c1cs) {
        // 0x80801B9C: nop
    
            goto L_80801BC8;
    }
    // 0x80801B9C: nop

L_80801BA0:
    // 0x80801BA0: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80801BA4: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80801BA8: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80801BAC: sub.s       $f0, $f14, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x80801BB0: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x80801BB4: sub.s       $f2, $f12, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x80801BB8: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80801BBC: nop

    // 0x80801BC0: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80801BC4: add.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f10.fl;
L_80801BC8:
    // 0x80801BC8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801BCC: bne         $s0, $s3, L_80801B50
    if (ctx->r16 != ctx->r19) {
        // 0x80801BD0: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80801B50;
    }
    // 0x80801BD0: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80801BD4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X39D4) << 16);
    // 0x80801BD8: lwc1        $f16, 0x39D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X39D4));
    // 0x80801BDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801BE0: c.lt.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl < ctx->f16.fl;
    // 0x80801BE4: nop

    // 0x80801BE8: bc1f        L_80801BF8
    if (!c1cs) {
        // 0x80801BEC: nop
    
            goto L_80801BF8;
    }
    // 0x80801BEC: nop

    // 0x80801BF0: b           L_80801BF8
    // 0x80801BF4: addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
        goto L_80801BF8;
    // 0x80801BF4: addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
L_80801BF8:
    // 0x80801BF8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80801BFC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80801C00: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80801C04: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80801C08: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80801C0C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80801C10: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80801C14: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80801C18: jr          $ra
    // 0x80801C1C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80801C1C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80800918_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800918: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8080091C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800920: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800924: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800928: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080092C: jal         0x80100094
    // 0x80800930: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800930: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800934: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800938: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x8080093C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800940: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800944: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800948: bne         $t7, $at, L_808009A0
    if (ctx->r15 != ctx->r1) {
        // 0x8080094C: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_808009A0;
    }
    // 0x8080094C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800950: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800954: jal         0x800E39A8
    // 0x80800958: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_800E39A8(rdram, ctx);
        goto after_1;
    // 0x80800958: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x8080095C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800960: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800964: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80800968: jal         0x800EF214
    // 0x8080096C: lui         $a3, 0xC47A
    ctx->r7 = S32(0XC47A << 16);
    func_800EF214(rdram, ctx);
        goto after_2;
    // 0x8080096C: lui         $a3, 0xC47A
    ctx->r7 = S32(0XC47A << 16);
    after_2:
    // 0x80800970: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800974: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800978: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080097C: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x80800980: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800984: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800988: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080098C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800990: jal         0x800DF744
    // 0x80800994: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x80800994: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    after_3:
    // 0x80800998: b           L_808009AC
    // 0x8080099C: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
        goto L_808009AC;
    // 0x8080099C: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
L_808009A0:
    // 0x808009A0: jal         0x800DF744
    // 0x808009A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_4;
    // 0x808009A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808009A8: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
L_808009AC:
    // 0x808009AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808009B0: sll         $t8, $a1, 20
    ctx->r24 = S32(ctx->r5 << 20);
    // 0x808009B4: srl         $t9, $t8, 29
    ctx->r25 = S32(U32(ctx->r24) >> 29);
    // 0x808009B8: jal         0x800DF744
    // 0x808009BC: addiu       $a1, $t9, 0x1
    ctx->r5 = ADD32(ctx->r25, 0X1);
    func_800DF744(rdram, ctx);
        goto after_5;
    // 0x808009BC: addiu       $a1, $t9, 0x1
    ctx->r5 = ADD32(ctx->r25, 0X1);
    after_5:
    // 0x808009C0: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x808009C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808009C8: sll         $t0, $a1, 20
    ctx->r8 = S32(ctx->r5 << 20);
    // 0x808009CC: srl         $t1, $t0, 29
    ctx->r9 = S32(U32(ctx->r8) >> 29);
    // 0x808009D0: jal         0x800DF744
    // 0x808009D4: addiu       $a1, $t1, 0x1
    ctx->r5 = ADD32(ctx->r9, 0X1);
    func_800DF744(rdram, ctx);
        goto after_6;
    // 0x808009D4: addiu       $a1, $t1, 0x1
    ctx->r5 = ADD32(ctx->r9, 0X1);
    after_6:
    // 0x808009D8: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x808009DC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808009E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009E4: lw          $t3, 0x34($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X34);
    // 0x808009E8: beq         $t3, $zero, L_80800A38
    if (ctx->r11 == 0) {
        // 0x808009EC: nop
    
            goto L_80800A38;
    }
    // 0x808009EC: nop

    // 0x808009F0: jal         0x80089CD8
    // 0x808009F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_9(rdram, ctx);
        goto after_7;
    // 0x808009F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808009F8: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x808009FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A00: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80800A04: jal         0x80086598
    // 0x80800A08: lw          $a1, 0x34($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X34);
    _chlifeforcespell_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80800A08: lw          $a1, 0x34($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X34);
    after_8:
    // 0x80800A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A10: jal         0x80089CE8
    // 0x80800A14: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    _subaddiefade_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x80800A14: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_9:
    // 0x80800A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A1C: jal         0x80101870
    // 0x80800A20: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_80101870(rdram, ctx);
        goto after_10;
    // 0x80800A20: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_10:
    // 0x80800A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A28: jal         0x80089CE8
    // 0x80800A2C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    _subaddiefade_entrypoint_11(rdram, ctx);
        goto after_11;
    // 0x80800A2C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_11:
    // 0x80800A30: b           L_80800A44
    // 0x80800A34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800A44;
    // 0x80800A34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A38:
    // 0x80800A38: jal         0x80101870
    // 0x80800A3C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_80101870(rdram, ctx);
        goto after_12;
    // 0x80800A3C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_12:
    // 0x80800A40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A44:
    // 0x80800A44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A48: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800A4C: jr          $ra
    // 0x80800A50: nop

    return;
    // 0x80800A50: nop

;}
RECOMP_FUNC void func_8008F788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F788: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008F78C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F790: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008F794: jal         0x800D1B34
    // 0x8008F798: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800D1B34(rdram, ctx);
        goto after_0;
    // 0x8008F798: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8008F79C: jal         0x800D1844
    // 0x8008F7A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D1844(rdram, ctx);
        goto after_1;
    // 0x8008F7A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8008F7A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008F7A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008F7AC: jr          $ra
    // 0x8008F7B0: nop

    return;
    // 0x8008F7B0: nop

;}
RECOMP_FUNC void _bsstonehead_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C38: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083C38);
    return;
    // 0x80083C3C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_80800280_chpiranha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800280: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800284: lhu         $t9, 0x6E($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X6E);
    // 0x80800288: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x8080028C: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x80800290: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x80800294: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800298: jr          $ra
    // 0x8080029C: sh          $t1, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r9;
    return;
    // 0x8080029C: sh          $t1, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_800E23A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E23A4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800E23A8: addiu       $v1, $v1, -0x2B90
    ctx->r3 = ADD32(ctx->r3, -0X2B90);
    // 0x800E23AC: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800E23B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E23B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800E23B8: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x800E23BC: sh          $t2, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r10;
    // 0x800E23C0: lh          $v0, 0x1C($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X1C);
    // 0x800E23C4: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // 0x800E23C8: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x800E23CC: swc1        $f6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f6.u32l;
    // 0x800E23D0: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x800E23D4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800E23D8: lwc1        $f8, 0x30($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X30);
    // 0x800E23DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800E23E0: addiu       $t4, $zero, 0x4E20
    ctx->r12 = ADD32(0, 0X4E20);
    // 0x800E23E4: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x800E23E8: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x800E23EC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800E23F0: sb          $zero, 0x23($v1)
    MEM_B(0X23, ctx->r3) = 0;
    // 0x800E23F4: sb          $zero, 0x22($v1)
    MEM_B(0X22, ctx->r3) = 0;
    // 0x800E23F8: sb          $zero, 0x20($v1)
    MEM_B(0X20, ctx->r3) = 0;
    // 0x800E23FC: sb          $zero, 0x21($v1)
    MEM_B(0X21, ctx->r3) = 0;
    // 0x800E2400: sb          $zero, 0x1E($v1)
    MEM_B(0X1E, ctx->r3) = 0;
    // 0x800E2404: sb          $t1, 0x1F($v1)
    MEM_B(0X1F, ctx->r3) = ctx->r9;
    // 0x800E2408: sw          $zero, 0x7C($v1)
    MEM_W(0X7C, ctx->r3) = 0;
    // 0x800E240C: sw          $zero, 0x78($v1)
    MEM_W(0X78, ctx->r3) = 0;
    // 0x800E2410: sw          $t4, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r12;
    // 0x800E2414: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x800E2418: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x800E241C: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x800E2420: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x800E2424: swc1        $f4, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f4.u32l;
    // 0x800E2428: swc1        $f8, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f8.u32l;
    // 0x800E242C: jr          $ra
    // 0x800E2430: swc1        $f10, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f10.u32l;
    return;
    // 0x800E2430: swc1        $f10, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f10.u32l;
;}
RECOMP_FUNC void boot_osInvalICache(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800B2720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2720: bnel        $a0, $zero, L_800B2734
    if (ctx->r4 != 0) {
        // 0x800B2724: lw          $v1, 0x1C($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X1C);
            goto L_800B2734;
    }
    goto skip_0;
    // 0x800B2724: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    skip_0:
    // 0x800B2728: jr          $ra
    // 0x800B272C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B272C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B2730: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
L_800B2734:
    // 0x800B2734: bne         $v1, $zero, L_800B2744
    if (ctx->r3 != 0) {
        // 0x800B2738: addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
            goto L_800B2744;
    }
    // 0x800B2738: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x800B273C: jr          $ra
    // 0x800B2740: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B2740: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B2744:
    // 0x800B2744: jr          $ra
    // 0x800B2748: nop

    return;
    // 0x800B2748: nop

;}
RECOMP_FUNC void func_808014AC_sucoasterfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014AC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808014B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808014B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808014B8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x808014BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808014C0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808014C4: jal         0x80100094
    // 0x808014C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808014C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808014CC: lbu         $a0, 0x11($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X11);
    // 0x808014D0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808014D4: srl         $t6, $a0, 4
    ctx->r14 = S32(U32(ctx->r4) >> 4);
    // 0x808014D8: jal         0x8008A270
    // 0x808014DC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    _sucoasterflydata_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808014DC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x808014E0: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x808014E4: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x808014E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014EC: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808014F0: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x808014F4: jal         0x80102424
    // 0x808014F8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x808014F8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_2:
    // 0x808014FC: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80801500: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x80801504: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80801508: sltiu       $at, $t0, 0xC
    ctx->r1 = ctx->r8 < 0XC ? 1 : 0;
    // 0x8080150C: beq         $at, $zero, L_80801808
    if (ctx->r1 == 0) {
        // 0x80801510: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80801808;
    }
    // 0x80801510: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80801514: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3210, 0X2234) << 16);
    // 0x80801518: addu        $at, $at, $t0
    gpr jr_addend_80801520 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8080151C: lw          $t0, 0x2234($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3210, 0X2234));
    // 0x80801520: jr          $t0
    // 0x80801524: nop

    switch (jr_addend_80801520 >> 2) {
        case 0: goto L_80801528; break;
        case 1: goto L_80801548; break;
        case 2: goto L_8080155C; break;
        case 3: goto L_808015C0; break;
        case 4: goto L_80801604; break;
        case 5: goto L_80801618; break;
        case 6: goto L_8080168C; break;
        case 7: goto L_80801698; break;
        case 8: goto L_808016F8; break;
        case 9: goto L_80801808; break;
        case 10: goto L_80801738; break;
        case 11: goto L_808017F4; break;
        default: switch_error(__func__, 0x80801520, 0x80802234);
    }
    // 0x80801524: nop

L_80801528:
    // 0x80801528: lh          $t1, 0x24($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X24);
    // 0x8080152C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80801530: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80801534: nop

    // 0x80801538: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080153C: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x80801540: b           L_80801808
    // 0x80801544: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
        goto L_80801808;
    // 0x80801544: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
L_80801548:
    // 0x80801548: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080154C: nop

    // 0x80801550: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    // 0x80801554: b           L_80801808
    // 0x80801558: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
        goto L_80801808;
    // 0x80801558: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_8080155C:
    // 0x8080155C: lh          $t2, 0x26($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X26);
    // 0x80801560: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80801564: nop

    // 0x80801568: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080156C: jal         0x80107C00
    // 0x80801570: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    func_80107C00(rdram, ctx);
        goto after_3;
    // 0x80801570: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    after_3:
    // 0x80801574: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80801578: lbu         $a0, 0x11($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X11);
    // 0x8080157C: srl         $t3, $a0, 4
    ctx->r11 = S32(U32(ctx->r4) >> 4);
    // 0x80801580: jal         0x8008A280
    // 0x80801584: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    _sucoasterflydata_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80801584: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_4:
    // 0x80801588: lbu         $a0, 0x11($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X11);
    // 0x8080158C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801590: srl         $t4, $a0, 4
    ctx->r12 = S32(U32(ctx->r4) >> 4);
    // 0x80801594: jal         0x8008A288
    // 0x80801598: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    _sucoasterflydata_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80801598: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_5:
    // 0x8080159C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015A0: jal         0x800DC128
    // 0x808015A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800DC128(rdram, ctx);
        goto after_6;
    // 0x808015A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x808015A8: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x808015AC: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808015B0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808015B4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808015B8: b           L_80801808
    // 0x808015BC: swc1        $f6, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f6.u32l;
        goto L_80801808;
    // 0x808015BC: swc1        $f6, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f6.u32l;
L_808015C0:
    // 0x808015C0: jal         0x8010CD28
    // 0x808015C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_7;
    // 0x808015C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808015C8: jal         0x80107C00
    // 0x808015CC: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    func_80107C00(rdram, ctx);
        goto after_8;
    // 0x808015CC: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    after_8:
    // 0x808015D0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808015D4: lbu         $a0, 0x11($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X11);
    // 0x808015D8: srl         $t5, $a0, 4
    ctx->r13 = S32(U32(ctx->r4) >> 4);
    // 0x808015DC: jal         0x8008A280
    // 0x808015E0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    _sucoasterflydata_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x808015E0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_9:
    // 0x808015E4: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x808015E8: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808015EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808015F0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808015F4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808015F8: swc1        $f18, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f18.u32l;
    // 0x808015FC: b           L_80801808
    // 0x80801600: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
        goto L_80801808;
    // 0x80801600: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_80801604:
    // 0x80801604: addiu       $a0, $s1, 0x12
    ctx->r4 = ADD32(ctx->r17, 0X12);
    // 0x80801608: jal         0x800EE940
    // 0x8080160C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE940(rdram, ctx);
        goto after_10;
    // 0x8080160C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_10:
    // 0x80801610: b           L_8080180C
    // 0x80801614: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080180C;
    // 0x80801614: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801618:
    // 0x80801618: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8080161C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80801620: addiu       $a0, $s1, 0x12
    ctx->r4 = ADD32(ctx->r17, 0X12);
    // 0x80801624: beq         $t6, $at, L_80801634
    if (ctx->r14 == ctx->r1) {
        // 0x80801628: nop
    
            goto L_80801634;
    }
    // 0x80801628: nop

    // 0x8080162C: jal         0x800EE940
    // 0x80801630: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE940(rdram, ctx);
        goto after_11;
    // 0x80801630: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_11:
L_80801634:
    // 0x80801634: jal         0x80801A80
    // 0x80801638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801A80_sucoasterfly(rdram, ctx);
        goto after_12;
    // 0x80801638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080163C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801640: jal         0x80102D78
    // 0x80801644: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_80102D78(rdram, ctx);
        goto after_13;
    // 0x80801644: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_13:
    // 0x80801648: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x8080164C: lbu         $t8, 0x11($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X11);
    // 0x80801650: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x80801654: jal         0x80107C00
    // 0x80801658: sb          $t9, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r25;
    func_80107C00(rdram, ctx);
        goto after_14;
    // 0x80801658: sb          $t9, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r25;
    after_14:
    // 0x8080165C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80801660: lbu         $a0, 0x11($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X11);
    // 0x80801664: srl         $t0, $a0, 4
    ctx->r8 = S32(U32(ctx->r4) >> 4);
    // 0x80801668: jal         0x8008A290
    // 0x8080166C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    _sucoasterflydata_entrypoint_5(rdram, ctx);
        goto after_15;
    // 0x8080166C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_15:
    // 0x80801670: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80801674: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80801678: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080167C: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80801680: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    // 0x80801684: b           L_80801808
    // 0x80801688: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
        goto L_80801808;
    // 0x80801688: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_8080168C:
    // 0x8080168C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80801690: b           L_80801808
    // 0x80801694: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
        goto L_80801808;
    // 0x80801694: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
L_80801698:
    // 0x80801698: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8080169C: jal         0x800EE88C
    // 0x808016A0: addiu       $a1, $s1, 0x12
    ctx->r5 = ADD32(ctx->r17, 0X12);
    func_800EE88C(rdram, ctx);
        goto after_16;
    // 0x808016A0: addiu       $a1, $s1, 0x12
    ctx->r5 = ADD32(ctx->r17, 0X12);
    after_16:
    // 0x808016A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016A8: jal         0x80102D78
    // 0x808016AC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_80102D78(rdram, ctx);
        goto after_17;
    // 0x808016AC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_17:
    // 0x808016B0: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808016B4: lbu         $t1, 0x11($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X11);
    // 0x808016B8: andi        $t2, $t1, 0xFFF7
    ctx->r10 = ctx->r9 & 0XFFF7;
    // 0x808016BC: jal         0x80107C00
    // 0x808016C0: sb          $t2, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r10;
    func_80107C00(rdram, ctx);
        goto after_18;
    // 0x808016C0: sb          $t2, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r10;
    after_18:
    // 0x808016C4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808016C8: lbu         $a0, 0x11($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X11);
    // 0x808016CC: srl         $t3, $a0, 4
    ctx->r11 = S32(U32(ctx->r4) >> 4);
    // 0x808016D0: jal         0x8008A280
    // 0x808016D4: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    _sucoasterflydata_entrypoint_3(rdram, ctx);
        goto after_19;
    // 0x808016D4: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_19:
    // 0x808016D8: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x808016DC: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808016E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808016E4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808016E8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808016EC: swc1        $f4, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f4.u32l;
    // 0x808016F0: b           L_80801808
    // 0x808016F4: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
        goto L_80801808;
    // 0x808016F4: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_808016F8:
    // 0x808016F8: jal         0x80107C00
    // 0x808016FC: nop

    func_80107C00(rdram, ctx);
        goto after_20;
    // 0x808016FC: nop

    after_20:
    // 0x80801700: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80801704: lbu         $a0, 0x11($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X11);
    // 0x80801708: srl         $t4, $a0, 4
    ctx->r12 = S32(U32(ctx->r4) >> 4);
    // 0x8080170C: jal         0x8008A288
    // 0x80801710: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    _sucoasterflydata_entrypoint_4(rdram, ctx);
        goto after_21;
    // 0x80801710: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_21:
    // 0x80801714: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3210, 0X2264) << 16);
    // 0x80801718: lwc1        $f8, 0x2264($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3210, 0X2264));
    // 0x8080171C: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80801720: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80801724: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80801728: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8080172C: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80801730: b           L_80801808
    // 0x80801734: swc1        $f4, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f4.u32l;
        goto L_80801808;
    // 0x80801734: swc1        $f4, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f4.u32l;
L_80801738:
    // 0x80801738: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080173C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801740: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801744: jal         0x8008A4B0
    // 0x80801748: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_22;
    // 0x80801748: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    after_22:
    // 0x8080174C: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    // 0x80801750: lbu         $t5, 0x64($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X64);
    // 0x80801754: lbu         $t6, 0x70($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X70);
    // 0x80801758: andi        $t0, $t9, 0xFC0F
    ctx->r8 = ctx->r25 & 0XFC0F;
    // 0x8080175C: sh          $t0, 0x72($s0)
    MEM_H(0X72, ctx->r16) = ctx->r8;
    // 0x80801760: lw          $t1, 0x70($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X70);
    // 0x80801764: andi        $t7, $t5, 0xFFFD
    ctx->r15 = ctx->r13 & 0XFFFD;
    // 0x80801768: sb          $t7, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r15;
    // 0x8080176C: andi        $t8, $t7, 0xFE
    ctx->r24 = ctx->r15 & 0XFE;
    // 0x80801770: sb          $t8, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r24;
    // 0x80801774: sll         $t2, $t1, 22
    ctx->r10 = S32(ctx->r9 << 22);
    // 0x80801778: lbu         $t9, 0x64($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X64);
    // 0x8080177C: srl         $t3, $t2, 26
    ctx->r11 = S32(U32(ctx->r10) >> 26);
    // 0x80801780: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x80801784: andi        $t7, $t6, 0xFF01
    ctx->r15 = ctx->r14 & 0XFF01;
    // 0x80801788: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x8080178C: andi        $t5, $t9, 0xFFBF
    ctx->r13 = ctx->r25 & 0XFFBF;
    // 0x80801790: sb          $t5, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r13;
    // 0x80801794: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
    // 0x80801798: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x8080179C: lui         $at, 0xFFF7
    ctx->r1 = S32(0XFFF7 << 16);
    // 0x808017A0: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x808017A4: lbu         $t1, 0x77($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X77);
    // 0x808017A8: srl         $t3, $t2, 31
    ctx->r11 = S32(U32(ctx->r10) >> 31);
    // 0x808017AC: sll         $t6, $t3, 7
    ctx->r14 = S32(ctx->r11 << 7);
    // 0x808017B0: sb          $t8, 0x70($s0)
    MEM_B(0X70, ctx->r16) = ctx->r24;
    // 0x808017B4: andi        $t7, $t5, 0x7F
    ctx->r15 = ctx->r13 & 0X7F;
    // 0x808017B8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x808017BC: andi        $t2, $t1, 0xFFF0
    ctx->r10 = ctx->r9 & 0XFFF0;
    // 0x808017C0: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x808017C4: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x808017C8: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x808017CC: sb          $t8, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r24;
    // 0x808017D0: sw          $t0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r8;
    // 0x808017D4: sb          $t3, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r11;
    // 0x808017D8: jal         0x8010A570
    // 0x808017DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_23;
    // 0x808017DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808017E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017E4: jal         0x80801CD0
    // 0x808017E8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801CD0_sucoasterfly(rdram, ctx);
        goto after_24;
    // 0x808017E8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_24:
    // 0x808017EC: b           L_8080180C
    // 0x808017F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080180C;
    // 0x808017F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808017F4:
    // 0x808017F4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3210, 0X22AC) << 16);
    // 0x808017F8: addiu       $a2, $a2, 0x22AC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3210, 0X22AC));
    // 0x808017FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801800: jal         0x80089D18
    // 0x80801804: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_25;
    // 0x80801804: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_25:
L_80801808:
    // 0x80801808: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080180C:
    // 0x8080180C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801810: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801814: jr          $ra
    // 0x80801818: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80801818: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80800660_chstarspinnerstar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800660: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800664: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800668: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(956, 0X710) << 16);
    // 0x8080066C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800670: addiu       $a0, $a0, 0x710
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(956, 0X710));
    // 0x80800674: jal         0x800EE7F8
    // 0x80800678: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800678: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    after_0:
    // 0x8080067C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(956, 0X710) << 16);
    // 0x80800680: addiu       $v0, $a0, 0x710
    ctx->r2 = ADD32(ctx->r4, (int16_t)RELOC_LO16(956, 0X710));
    // 0x80800684: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800688: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8080068C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800690: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800694: jr          $ra
    // 0x80800698: nop

    return;
    // 0x80800698: nop

    // 0x8080069C: nop

;}
RECOMP_FUNC void func_801020DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801020DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801020E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801020E4: jal         0x80104248
    // 0x801020E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80104248(rdram, ctx);
        goto after_0;
    // 0x801020E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801020EC: beq         $v0, $zero, L_80102118
    if (ctx->r2 == 0) {
        // 0x801020F0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80102118;
    }
    // 0x801020F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801020F4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x801020F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801020FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80102100: bne         $t6, $at, L_80102110
    if (ctx->r14 != ctx->r1) {
        // 0x80102104: nop
    
            goto L_80102110;
    }
    // 0x80102104: nop

    // 0x80102108: b           L_80102110
    // 0x8010210C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80102110;
    // 0x8010210C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80102110:
    // 0x80102110: jal         0x8008B1A0
    // 0x80102114: nop

    anctrl_setSmoothTransition(rdram, ctx);
        goto after_1;
    // 0x80102114: nop

    after_1:
L_80102118:
    // 0x80102118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010211C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102120: jr          $ra
    // 0x80102124: nop

    return;
    // 0x80102124: nop

;}
RECOMP_FUNC void chdinofamilyfx_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: jal         0x801022E4
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_801022E4(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800014: addiu       $at, $zero, 0x14C
    ctx->r1 = ADD32(0, 0X14C);
    // 0x80800018: beq         $v0, $at, L_8080046C
    if (ctx->r2 == ctx->r1) {
        // 0x8080001C: addiu       $at, $zero, 0x14D
        ctx->r1 = ADD32(0, 0X14D);
            goto L_8080046C;
    }
    // 0x8080001C: addiu       $at, $zero, 0x14D
    ctx->r1 = ADD32(0, 0X14D);
    // 0x80800020: beq         $v0, $at, L_80800318
    if (ctx->r2 == ctx->r1) {
        // 0x80800024: addiu       $t3, $sp, 0x7C
        ctx->r11 = ADD32(ctx->r29, 0X7C);
            goto L_80800318;
    }
    // 0x80800024: addiu       $t3, $sp, 0x7C
    ctx->r11 = ADD32(ctx->r29, 0X7C);
    // 0x80800028: addiu       $at, $zero, 0x3F7
    ctx->r1 = ADD32(0, 0X3F7);
    // 0x8080002C: beq         $v0, $at, L_80800048
    if (ctx->r2 == ctx->r1) {
        // 0x80800030: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800048;
    }
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800034: addiu       $at, $zero, 0x3F8
    ctx->r1 = ADD32(0, 0X3F8);
    // 0x80800038: beq         $v0, $at, L_80800770
    if (ctx->r2 == ctx->r1) {
        // 0x8080003C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800770;
    }
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800040: b           L_80800A18
    // 0x80800044: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800A18;
    // 0x80800044: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800048:
    // 0x80800048: lui         $a1, 0x3D23
    ctx->r5 = S32(0X3D23 << 16);
    // 0x8080004C: jal         0x80101E14
    // 0x80800050: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    func_80101E14(rdram, ctx);
        goto after_1;
    // 0x80800050: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    after_1:
    // 0x80800054: beq         $v0, $zero, L_8080007C
    if (ctx->r2 == 0) {
        // 0x80800058: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080007C;
    }
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080005C: lui         $a0, 0x7FED
    ctx->r4 = S32(0X7FED << 16);
    // 0x80800060: lui         $a2, 0x7D0
    ctx->r6 = S32(0X7D0 << 16);
    // 0x80800064: ori         $a2, $a2, 0x12C
    ctx->r6 = ctx->r6 | 0X12C;
    // 0x80800068: ori         $a0, $a0, 0xAD02
    ctx->r4 = ctx->r4 | 0XAD02;
    // 0x8080006C: jal         0x800C4140
    // 0x80800070: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_2;
    // 0x80800070: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x80800074: b           L_808000A8
    // 0x80800078: lui         $a1, 0x3EBD
    ctx->r5 = S32(0X3EBD << 16);
        goto L_808000A8;
    // 0x80800078: lui         $a1, 0x3EBD
    ctx->r5 = S32(0X3EBD << 16);
L_8080007C:
    // 0x8080007C: lui         $a1, 0x3E2E
    ctx->r5 = S32(0X3E2E << 16);
    // 0x80800080: jal         0x80101E14
    // 0x80800084: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    func_80101E14(rdram, ctx);
        goto after_3;
    // 0x80800084: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    after_3:
    // 0x80800088: beq         $v0, $zero, L_808000A4
    if (ctx->r2 == 0) {
        // 0x8080008C: lui         $a0, 0x930D
        ctx->r4 = S32(0X930D << 16);
            goto L_808000A4;
    }
    // 0x8080008C: lui         $a0, 0x930D
    ctx->r4 = S32(0X930D << 16);
    // 0x80800090: lui         $a2, 0x7D0
    ctx->r6 = S32(0X7D0 << 16);
    // 0x80800094: ori         $a2, $a2, 0x12C
    ctx->r6 = ctx->r6 | 0X12C;
    // 0x80800098: ori         $a0, $a0, 0xAD02
    ctx->r4 = ctx->r4 | 0XAD02;
    // 0x8080009C: jal         0x800C4140
    // 0x808000A0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_4;
    // 0x808000A0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_4:
L_808000A4:
    // 0x808000A4: lui         $a1, 0x3EBD
    ctx->r5 = S32(0X3EBD << 16);
L_808000A8:
    // 0x808000A8: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    // 0x808000AC: jal         0x80101E14
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_5;
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000B4: beq         $v0, $zero, L_80800100
    if (ctx->r2 == 0) {
        // 0x808000B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800100;
    }
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000BC: addiu       $t6, $s0, 0x4
    ctx->r14 = ADD32(ctx->r16, 0X4);
    // 0x808000C0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x808000C4: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    // 0x808000C8: jal         0x8008A0D0
    // 0x808000CC: addiu       $a2, $sp, 0x9C
    ctx->r6 = ADD32(ctx->r29, 0X9C);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x808000CC: addiu       $a2, $sp, 0x9C
    ctx->r6 = ADD32(ctx->r29, 0X9C);
    after_6:
    // 0x808000D0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XBD0) << 16);
    // 0x808000D4: addiu       $a3, $a3, 0xBD0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XBD0));
    // 0x808000D8: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x808000DC: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x808000E0: jal         0x80800A28
    // 0x808000E4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_7;
    // 0x808000E4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_7:
    // 0x808000E8: lui         $a0, 0xA62F
    ctx->r4 = S32(0XA62F << 16);
    // 0x808000EC: lui         $a2, 0x7D0
    ctx->r6 = S32(0X7D0 << 16);
    // 0x808000F0: ori         $a2, $a2, 0x12C
    ctx->r6 = ctx->r6 | 0X12C;
    // 0x808000F4: ori         $a0, $a0, 0xA503
    ctx->r4 = ctx->r4 | 0XA503;
    // 0x808000F8: jal         0x800C4140
    // 0x808000FC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800C4140(rdram, ctx);
        goto after_8;
    // 0x808000FC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_8:
L_80800100:
    // 0x80800100: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80800104: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800108: jal         0x80101E14
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_9;
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800110: beq         $v0, $zero, L_80800A14
    if (ctx->r2 == 0) {
        // 0x80800114: addiu       $t7, $s0, 0x4
        ctx->r15 = ADD32(ctx->r16, 0X4);
            goto L_80800A14;
    }
    // 0x80800114: addiu       $t7, $s0, 0x4
    ctx->r15 = ADD32(ctx->r16, 0X4);
    // 0x80800118: jal         0x800EA05C
    // 0x8080011C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    func_800EA05C(rdram, ctx);
        goto after_10;
    // 0x8080011C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_10:
    // 0x80800120: xori        $t8, $v0, 0x118
    ctx->r24 = ctx->r2 ^ 0X118;
    // 0x80800124: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80800128: sw          $t8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r24;
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800130: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80800134: jal         0x8008A0D0
    // 0x80800138: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x80800138: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    after_11:
    // 0x8080013C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800140: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800144: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800148: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XBF8) << 16);
    // 0x8080014C: addiu       $a3, $a3, 0xBF8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XBF8));
    // 0x80800150: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800154: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x80800158: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080015C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800160: jal         0x80800A28
    // 0x80800164: nop

    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_12;
    // 0x80800164: nop

    after_12:
    // 0x80800168: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x8080016C: beq         $t9, $zero, L_8080019C
    if (ctx->r25 == 0) {
        // 0x80800170: lui         $at, 0x4234
        ctx->r1 = S32(0X4234 << 16);
            goto L_8080019C;
    }
    // 0x80800170: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800174: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800178: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080017C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XC20) << 16);
    // 0x80800180: addiu       $a3, $a3, 0xC20
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XC20));
    // 0x80800184: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800188: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x8080018C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800190: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800194: jal         0x80800A28
    // 0x80800198: nop

    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_13;
    // 0x80800198: nop

    after_13:
L_8080019C:
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x808001A4: jal         0x8008A0D0
    // 0x808001A8: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x808001A8: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    after_14:
    // 0x808001AC: lui         $at, 0x4307
    ctx->r1 = S32(0X4307 << 16);
    // 0x808001B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001B4: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808001B8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XBF8) << 16);
    // 0x808001BC: addiu       $a3, $a3, 0xBF8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XBF8));
    // 0x808001C0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808001C4: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x808001C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808001CC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808001D0: jal         0x80800A28
    // 0x808001D4: nop

    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_15;
    // 0x808001D4: nop

    after_15:
    // 0x808001D8: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x808001DC: lui         $at, 0x4307
    ctx->r1 = S32(0X4307 << 16);
    // 0x808001E0: beql        $t0, $zero, L_80800214
    if (ctx->r8 == 0) {
        // 0x808001E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800214;
    }
    goto skip_0;
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808001E8: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808001EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808001F0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XC20) << 16);
    // 0x808001F4: addiu       $a3, $a3, 0xC20
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XC20));
    // 0x808001F8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808001FC: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x80800200: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800204: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800208: jal         0x80800A28
    // 0x8080020C: nop

    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_16;
    // 0x8080020C: nop

    after_16:
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800214:
    // 0x80800214: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80800218: jal         0x8008A0D0
    // 0x8080021C: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_17;
    // 0x8080021C: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    after_17:
    // 0x80800220: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80800224: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800228: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080022C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XBF8) << 16);
    // 0x80800230: addiu       $a3, $a3, 0xBF8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XBF8));
    // 0x80800234: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800238: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x8080023C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800240: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800244: jal         0x80800A28
    // 0x80800248: nop

    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_18;
    // 0x80800248: nop

    after_18:
    // 0x8080024C: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x80800250: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80800254: beql        $t1, $zero, L_80800288
    if (ctx->r9 == 0) {
        // 0x80800258: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800288;
    }
    goto skip_1;
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x8080025C: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800260: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800264: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XC20) << 16);
    // 0x80800268: addiu       $a3, $a3, 0xC20
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XC20));
    // 0x8080026C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800270: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x80800274: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800278: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8080027C: jal         0x80800A28
    // 0x80800280: nop

    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_19;
    // 0x80800280: nop

    after_19:
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800288:
    // 0x80800288: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8080028C: jal         0x8008A0D0
    // 0x80800290: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_20;
    // 0x80800290: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    after_20:
    // 0x80800294: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2428, 0XBA0) << 16);
    // 0x80800298: lwc1        $f6, 0xBA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2428, 0XBA0));
    // 0x8080029C: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808002A0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XBF8) << 16);
    // 0x808002A4: addiu       $a3, $a3, 0xBF8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XBF8));
    // 0x808002A8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808002AC: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x808002B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808002B4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808002B8: jal         0x80800A28
    // 0x808002BC: nop

    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_21;
    // 0x808002BC: nop

    after_21:
    // 0x808002C0: lw          $t2, 0x8C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8C);
    // 0x808002C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2428, 0XBA4) << 16);
    // 0x808002C8: beql        $t2, $zero, L_808002FC
    if (ctx->r10 == 0) {
        // 0x808002CC: lui         $a0, 0x7FF3
        ctx->r4 = S32(0X7FF3 << 16);
            goto L_808002FC;
    }
    goto skip_2;
    // 0x808002CC: lui         $a0, 0x7FF3
    ctx->r4 = S32(0X7FF3 << 16);
    skip_2:
    // 0x808002D0: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808002D4: lwc1        $f16, 0xBA4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2428, 0XBA4));
    // 0x808002D8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XC20) << 16);
    // 0x808002DC: addiu       $a3, $a3, 0xC20
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XC20));
    // 0x808002E0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808002E4: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x808002E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808002EC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808002F0: jal         0x80800A28
    // 0x808002F4: nop

    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_22;
    // 0x808002F4: nop

    after_22:
    // 0x808002F8: lui         $a0, 0x7FF3
    ctx->r4 = S32(0X7FF3 << 16);
L_808002FC:
    // 0x808002FC: lui         $a2, 0x7D0
    ctx->r6 = S32(0X7D0 << 16);
    // 0x80800300: ori         $a2, $a2, 0x12C
    ctx->r6 = ctx->r6 | 0X12C;
    // 0x80800304: ori         $a0, $a0, 0x8C4A
    ctx->r4 = ctx->r4 | 0X8C4A;
    // 0x80800308: jal         0x800C4140
    // 0x8080030C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800C4140(rdram, ctx);
        goto after_23;
    // 0x8080030C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_23:
    // 0x80800310: b           L_80800A18
    // 0x80800314: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800A18;
    // 0x80800314: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800318:
    // 0x80800318: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2428, 0XBC0) << 16);
    // 0x8080031C: addiu       $t4, $t4, 0xBC0
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2428, 0XBC0));
    // 0x80800320: lw          $at, 0x0($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X0);
    // 0x80800324: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
    // 0x80800328: lui         $a1, 0x3EAE
    ctx->r5 = S32(0X3EAE << 16);
    // 0x8080032C: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x80800330: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x80800334: lw          $t6, 0xC($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XC);
    // 0x80800338: lw          $at, 0x8($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X8);
    // 0x8080033C: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800344: sw          $t6, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r14;
    // 0x80800348: jal         0x80101E14
    // 0x8080034C: sw          $at, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r1;
    func_80101E14(rdram, ctx);
        goto after_24;
    // 0x8080034C: sw          $at, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r1;
    after_24:
    // 0x80800350: bne         $v0, $zero, L_8080036C
    if (ctx->r2 != 0) {
        // 0x80800354: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080036C;
    }
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800358: lui         $a1, 0x3F23
    ctx->r5 = S32(0X3F23 << 16);
    // 0x8080035C: jal         0x80101E14
    // 0x80800360: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    func_80101E14(rdram, ctx);
        goto after_25;
    // 0x80800360: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    after_25:
    // 0x80800364: beq         $v0, $zero, L_8080038C
    if (ctx->r2 == 0) {
        // 0x80800368: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080038C;
    }
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080036C:
    // 0x8080036C: lui         $a0, 0x9973
    ctx->r4 = S32(0X9973 << 16);
    // 0x80800370: lui         $a2, 0x7D0
    ctx->r6 = S32(0X7D0 << 16);
    // 0x80800374: ori         $a2, $a2, 0x12C
    ctx->r6 = ctx->r6 | 0X12C;
    // 0x80800378: ori         $a0, $a0, 0x8D51
    ctx->r4 = ctx->r4 | 0X8D51;
    // 0x8080037C: jal         0x800C4140
    // 0x80800380: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_26;
    // 0x80800380: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_26:
    // 0x80800384: b           L_80800A18
    // 0x80800388: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800A18;
    // 0x80800388: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080038C:
    // 0x8080038C: lui         $a1, 0x3F42
    ctx->r5 = S32(0X3F42 << 16);
    // 0x80800390: jal         0x80101E14
    // 0x80800394: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    func_80101E14(rdram, ctx);
        goto after_27;
    // 0x80800394: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    after_27:
    // 0x80800398: beq         $v0, $zero, L_80800A14
    if (ctx->r2 == 0) {
        // 0x8080039C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800A14;
    }
    // 0x8080039C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003A0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808003A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2428, 0XBA8) << 16);
    // 0x808003A8: jal         0x800DC178
    // 0x808003AC: lwc1        $f14, 0xBA8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2428, 0XBA8));
    func_800DC178(rdram, ctx);
        goto after_28;
    // 0x808003AC: lwc1        $f14, 0xBA8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2428, 0XBA8));
    after_28:
    // 0x808003B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2428, 0XBAC) << 16);
    // 0x808003B4: lwc1        $f4, 0xBAC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2428, 0XBAC));
    // 0x808003B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808003BC: lui         $a2, 0x7D0
    ctx->r6 = S32(0X7D0 << 16);
    // 0x808003C0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808003C4: ori         $a2, $a2, 0x12C
    ctx->r6 = ctx->r6 | 0X12C;
    // 0x808003C8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808003CC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808003D0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x808003D4: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x808003D8: nop

    // 0x808003DC: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x808003E0: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x808003E4: nop

    // 0x808003E8: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x808003EC: beql        $a0, $zero, L_8080043C
    if (ctx->r4 == 0) {
        // 0x808003F0: mfc1        $a0, $f8
        ctx->r4 = (int32_t)ctx->f8.u32l;
            goto L_8080043C;
    }
    goto skip_3;
    // 0x808003F0: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    skip_3:
    // 0x808003F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808003F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808003FC: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800400: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800404: nop

    // 0x80800408: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8080040C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800410: nop

    // 0x80800414: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800418: bne         $a0, $zero, L_80800430
    if (ctx->r4 != 0) {
        // 0x8080041C: nop
    
            goto L_80800430;
    }
    // 0x8080041C: nop

    // 0x80800420: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80800424: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800428: b           L_80800448
    // 0x8080042C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80800448;
    // 0x8080042C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80800430:
    // 0x80800430: b           L_80800448
    // 0x80800434: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80800448;
    // 0x80800434: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80800438: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
L_8080043C:
    // 0x8080043C: nop

    // 0x80800440: bltz        $a0, L_80800430
    if (SIGNED(ctx->r4) < 0) {
        // 0x80800444: nop
    
            goto L_80800430;
    }
    // 0x80800444: nop

L_80800448:
    // 0x80800448: or          $t8, $a0, $zero
    ctx->r24 = ctx->r4 | 0;
    // 0x8080044C: lui         $at, 0xD
    ctx->r1 = S32(0XD << 16);
    // 0x80800450: ori         $at, $at, 0xAD33
    ctx->r1 = ctx->r1 | 0XAD33;
    // 0x80800454: sll         $t9, $t8, 21
    ctx->r25 = S32(ctx->r24 << 21);
    // 0x80800458: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8080045C: jal         0x800C4140
    // 0x80800460: addu        $a0, $t9, $at
    ctx->r4 = ADD32(ctx->r25, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_29;
    // 0x80800460: addu        $a0, $t9, $at
    ctx->r4 = ADD32(ctx->r25, ctx->r1);
    after_29:
    // 0x80800464: b           L_80800A18
    // 0x80800468: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800A18;
    // 0x80800468: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080046C:
    // 0x8080046C: jal         0x800EA05C
    // 0x80800470: nop

    func_800EA05C(rdram, ctx);
        goto after_30;
    // 0x80800470: nop

    after_30:
    // 0x80800474: xori        $t0, $v0, 0x118
    ctx->r8 = ctx->r2 ^ 0X118;
    // 0x80800478: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8080047C: jal         0x800EA05C
    // 0x80800480: sw          $t0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r8;
    func_800EA05C(rdram, ctx);
        goto after_31;
    // 0x80800480: sw          $t0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r8;
    after_31:
    // 0x80800484: xori        $v1, $v0, 0x114
    ctx->r3 = ctx->r2 ^ 0X114;
    // 0x80800488: sltiu       $a2, $v1, 0x1
    ctx->r6 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8080048C: bne         $a2, $zero, L_808004A0
    if (ctx->r6 != 0) {
        // 0x80800490: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004A0;
    }
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800494: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80800498: sltu        $t1, $zero, $a2
    ctx->r9 = 0 < ctx->r6 ? 1 : 0;
    // 0x8080049C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
L_808004A0:
    // 0x808004A0: lui         $a1, 0x3EFA
    ctx->r5 = S32(0X3EFA << 16);
    // 0x808004A4: ori         $a1, $a1, 0xE148
    ctx->r5 = ctx->r5 | 0XE148;
    // 0x808004A8: jal         0x80101E14
    // 0x808004AC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80101E14(rdram, ctx);
        goto after_32;
    // 0x808004AC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_32:
    // 0x808004B0: beq         $v0, $zero, L_80800564
    if (ctx->r2 == 0) {
        // 0x808004B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800564;
    }
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B8: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x808004BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x808004C4: sltu        $t5, $zero, $t2
    ctx->r13 = 0 < ctx->r10 ? 1 : 0;
    // 0x808004C8: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x808004CC: jal         0x8008A0D0
    // 0x808004D0: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_33;
    // 0x808004D0: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_33:
    // 0x808004D4: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x808004D8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808004DC: beql        $t3, $zero, L_80800510
    if (ctx->r11 == 0) {
        // 0x808004E0: lw          $t4, 0x20($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X20);
            goto L_80800510;
    }
    goto skip_4;
    // 0x808004E0: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    skip_4:
    // 0x808004E4: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808004E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808004EC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XBF8) << 16);
    // 0x808004F0: addiu       $a3, $a3, 0xBF8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XBF8));
    // 0x808004F4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808004F8: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x808004FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800500: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800504: jal         0x80800A28
    // 0x80800508: nop

    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_34;
    // 0x80800508: nop

    after_34:
    // 0x8080050C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
L_80800510:
    // 0x80800510: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800514: beql        $t4, $zero, L_80800548
    if (ctx->r12 == 0) {
        // 0x80800518: lui         $a0, 0x7FF3
        ctx->r4 = S32(0X7FF3 << 16);
            goto L_80800548;
    }
    goto skip_5;
    // 0x80800518: lui         $a0, 0x7FF3
    ctx->r4 = S32(0X7FF3 << 16);
    skip_5:
    // 0x8080051C: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800520: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800524: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XC20) << 16);
    // 0x80800528: addiu       $a3, $a3, 0xC20
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XC20));
    // 0x8080052C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800530: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80800534: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800538: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080053C: jal         0x80800A28
    // 0x80800540: nop

    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_35;
    // 0x80800540: nop

    after_35:
    // 0x80800544: lui         $a0, 0x7FF3
    ctx->r4 = S32(0X7FF3 << 16);
L_80800548:
    // 0x80800548: lui         $a2, 0x7D0
    ctx->r6 = S32(0X7D0 << 16);
    // 0x8080054C: ori         $a2, $a2, 0x12C
    ctx->r6 = ctx->r6 | 0X12C;
    // 0x80800550: ori         $a0, $a0, 0x8C4B
    ctx->r4 = ctx->r4 | 0X8C4B;
    // 0x80800554: jal         0x800C4140
    // 0x80800558: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_800C4140(rdram, ctx);
        goto after_36;
    // 0x80800558: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_36:
    // 0x8080055C: b           L_80800A18
    // 0x80800560: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800A18;
    // 0x80800560: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800564:
    // 0x80800564: lui         $a1, 0x3F38
    ctx->r5 = S32(0X3F38 << 16);
    // 0x80800568: jal         0x80101E14
    // 0x8080056C: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    func_80101E14(rdram, ctx);
        goto after_37;
    // 0x8080056C: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    after_37:
    // 0x80800570: beq         $v0, $zero, L_80800624
    if (ctx->r2 == 0) {
        // 0x80800574: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800624;
    }
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800578: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800580: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80800584: sltu        $t7, $zero, $t6
    ctx->r15 = 0 < ctx->r14 ? 1 : 0;
    // 0x80800588: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8080058C: jal         0x8008A0D0
    // 0x80800590: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_38;
    // 0x80800590: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    after_38:
    // 0x80800594: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80800598: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8080059C: beql        $t8, $zero, L_808005D0
    if (ctx->r24 == 0) {
        // 0x808005A0: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_808005D0;
    }
    goto skip_6;
    // 0x808005A0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    skip_6:
    // 0x808005A4: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808005A8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808005AC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XBF8) << 16);
    // 0x808005B0: addiu       $a3, $a3, 0xBF8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XBF8));
    // 0x808005B4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808005B8: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x808005BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808005C0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808005C4: jal         0x80800A28
    // 0x808005C8: nop

    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_39;
    // 0x808005C8: nop

    after_39:
    // 0x808005CC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
L_808005D0:
    // 0x808005D0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808005D4: beql        $t9, $zero, L_80800608
    if (ctx->r25 == 0) {
        // 0x808005D8: lui         $a0, 0x7FF3
        ctx->r4 = S32(0X7FF3 << 16);
            goto L_80800608;
    }
    goto skip_7;
    // 0x808005D8: lui         $a0, 0x7FF3
    ctx->r4 = S32(0X7FF3 << 16);
    skip_7:
    // 0x808005DC: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808005E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005E4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XC20) << 16);
    // 0x808005E8: addiu       $a3, $a3, 0xC20
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XC20));
    // 0x808005EC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808005F0: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x808005F4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808005F8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808005FC: jal         0x80800A28
    // 0x80800600: nop

    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_40;
    // 0x80800600: nop

    after_40:
    // 0x80800604: lui         $a0, 0x7FF3
    ctx->r4 = S32(0X7FF3 << 16);
L_80800608:
    // 0x80800608: lui         $a2, 0x7D0
    ctx->r6 = S32(0X7D0 << 16);
    // 0x8080060C: ori         $a2, $a2, 0x12C
    ctx->r6 = ctx->r6 | 0X12C;
    // 0x80800610: ori         $a0, $a0, 0x8C4B
    ctx->r4 = ctx->r4 | 0X8C4B;
    // 0x80800614: jal         0x800C4140
    // 0x80800618: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_800C4140(rdram, ctx);
        goto after_41;
    // 0x80800618: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_41:
    // 0x8080061C: b           L_80800A18
    // 0x80800620: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800A18;
    // 0x80800620: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800624:
    // 0x80800624: lui         $a1, 0x3F0C
    ctx->r5 = S32(0X3F0C << 16);
    // 0x80800628: jal         0x80101E14
    // 0x8080062C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80101E14(rdram, ctx);
        goto after_42;
    // 0x8080062C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_42:
    // 0x80800630: beq         $v0, $zero, L_808006CC
    if (ctx->r2 == 0) {
        // 0x80800634: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006CC;
    }
    // 0x80800634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800638: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800640: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80800644: sltu        $t1, $zero, $t0
    ctx->r9 = 0 < ctx->r8 ? 1 : 0;
    // 0x80800648: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8080064C: jal         0x8008A0D0
    // 0x80800650: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_43;
    // 0x80800650: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_43:
    // 0x80800654: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80800658: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8080065C: beql        $t2, $zero, L_80800690
    if (ctx->r10 == 0) {
        // 0x80800660: lw          $t5, 0x20($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X20);
            goto L_80800690;
    }
    goto skip_8;
    // 0x80800660: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    skip_8:
    // 0x80800664: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800668: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080066C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XBF8) << 16);
    // 0x80800670: addiu       $a3, $a3, 0xBF8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XBF8));
    // 0x80800674: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800678: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8080067C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800680: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800684: jal         0x80800A28
    // 0x80800688: nop

    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_44;
    // 0x80800688: nop

    after_44:
    // 0x8080068C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
L_80800690:
    // 0x80800690: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800694: beql        $t5, $zero, L_80800A18
    if (ctx->r13 == 0) {
        // 0x80800698: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800A18;
    }
    goto skip_9;
    // 0x80800698: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x8080069C: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808006A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808006A4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XC20) << 16);
    // 0x808006A8: addiu       $a3, $a3, 0xC20
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XC20));
    // 0x808006AC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808006B0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808006B4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808006B8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808006BC: jal         0x80800A28
    // 0x808006C0: nop

    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_45;
    // 0x808006C0: nop

    after_45:
    // 0x808006C4: b           L_80800A18
    // 0x808006C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800A18;
    // 0x808006C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808006CC:
    // 0x808006CC: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x808006D0: jal         0x80101E14
    // 0x808006D4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    func_80101E14(rdram, ctx);
        goto after_46;
    // 0x808006D4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_46:
    // 0x808006D8: beq         $v0, $zero, L_80800A14
    if (ctx->r2 == 0) {
        // 0x808006DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A14;
    }
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E0: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x808006E4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x808006E8: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x808006EC: sltu        $t4, $zero, $t3
    ctx->r12 = 0 < ctx->r11 ? 1 : 0;
    // 0x808006F0: jal         0x8008A0D0
    // 0x808006F4: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_47;
    // 0x808006F4: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    after_47:
    // 0x808006F8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808006FC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800700: beql        $t6, $zero, L_80800734
    if (ctx->r14 == 0) {
        // 0x80800704: lw          $t7, 0x20($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X20);
            goto L_80800734;
    }
    goto skip_10;
    // 0x80800704: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    skip_10:
    // 0x80800708: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080070C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800710: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XBF8) << 16);
    // 0x80800714: addiu       $a3, $a3, 0xBF8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XBF8));
    // 0x80800718: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8080071C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800720: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800724: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800728: jal         0x80800A28
    // 0x8080072C: nop

    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_48;
    // 0x8080072C: nop

    after_48:
    // 0x80800730: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
L_80800734:
    // 0x80800734: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800738: beql        $t7, $zero, L_80800A18
    if (ctx->r15 == 0) {
        // 0x8080073C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800A18;
    }
    goto skip_11;
    // 0x8080073C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_11:
    // 0x80800740: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800744: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800748: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XC20) << 16);
    // 0x8080074C: addiu       $a3, $a3, 0xC20
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XC20));
    // 0x80800750: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800754: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800758: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8080075C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800760: jal         0x80800A28
    // 0x80800764: nop

    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_49;
    // 0x80800764: nop

    after_49:
    // 0x80800768: b           L_80800A18
    // 0x8080076C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800A18;
    // 0x8080076C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800770:
    // 0x80800770: lui         $a1, 0x3E42
    ctx->r5 = S32(0X3E42 << 16);
    // 0x80800774: jal         0x80101E14
    // 0x80800778: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    func_80101E14(rdram, ctx);
        goto after_50;
    // 0x80800778: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    after_50:
    // 0x8080077C: bne         $v0, $zero, L_80800798
    if (ctx->r2 != 0) {
        // 0x80800780: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800798;
    }
    // 0x80800780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800784: lui         $a1, 0x3EEB
    ctx->r5 = S32(0X3EEB << 16);
    // 0x80800788: jal         0x80101E14
    // 0x8080078C: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    func_80101E14(rdram, ctx);
        goto after_51;
    // 0x8080078C: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    after_51:
    // 0x80800790: beq         $v0, $zero, L_808007AC
    if (ctx->r2 == 0) {
        // 0x80800794: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007AC;
    }
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800798:
    // 0x80800798: addiu       $t8, $zero, 0x44B
    ctx->r24 = ADD32(0, 0X44B);
    // 0x8080079C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808007A0: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x808007A4: b           L_808007D4
    // 0x808007A8: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
        goto L_808007D4;
    // 0x808007A8: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
L_808007AC:
    // 0x808007AC: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x808007B0: jal         0x80101E14
    // 0x808007B4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80101E14(rdram, ctx);
        goto after_52;
    // 0x808007B4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_52:
    // 0x808007B8: beq         $v0, $zero, L_808007D0
    if (ctx->r2 == 0) {
        // 0x808007BC: addiu       $t0, $zero, 0x44A
        ctx->r8 = ADD32(0, 0X44A);
            goto L_808007D0;
    }
    // 0x808007BC: addiu       $t0, $zero, 0x44A
    ctx->r8 = ADD32(0, 0X44A);
    // 0x808007C0: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x808007C4: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x808007C8: b           L_808007D4
    // 0x808007CC: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
        goto L_808007D4;
    // 0x808007CC: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
L_808007D0:
    // 0x808007D0: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_808007D4:
    // 0x808007D4: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x808007D8: beql        $t2, $zero, L_808009EC
    if (ctx->r10 == 0) {
        // 0x808007DC: lui         $a1, 0x3F26
        ctx->r5 = S32(0X3F26 << 16);
            goto L_808009EC;
    }
    goto skip_12;
    // 0x808007DC: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    skip_12:
    // 0x808007E0: jal         0x800EA05C
    // 0x808007E4: nop

    func_800EA05C(rdram, ctx);
        goto after_53;
    // 0x808007E4: nop

    after_53:
    // 0x808007E8: xori        $t5, $v0, 0x118
    ctx->r13 = ctx->r2 ^ 0X118;
    // 0x808007EC: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x808007F0: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x808007F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x808007FC: jal         0x8008A0D0
    // 0x80800800: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_54;
    // 0x80800800: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_54:
    // 0x80800804: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800808: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080080C: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800810: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XBF8) << 16);
    // 0x80800814: addiu       $a3, $a3, 0xBF8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XBF8));
    // 0x80800818: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8080081C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800820: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80800824: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800828: jal         0x80800A28
    // 0x8080082C: nop

    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_55;
    // 0x8080082C: nop

    after_55:
    // 0x80800830: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80800834: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800838: beql        $t3, $zero, L_8080086C
    if (ctx->r11 == 0) {
        // 0x8080083C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080086C;
    }
    goto skip_13;
    // 0x8080083C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_13:
    // 0x80800840: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800844: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800848: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XC20) << 16);
    // 0x8080084C: addiu       $a3, $a3, 0xC20
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XC20));
    // 0x80800850: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800854: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800858: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8080085C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800860: jal         0x80800A28
    // 0x80800864: nop

    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_56;
    // 0x80800864: nop

    after_56:
    // 0x80800868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080086C:
    // 0x8080086C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800870: jal         0x8008A0D0
    // 0x80800874: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_57;
    // 0x80800874: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_57:
    // 0x80800878: lui         $at, 0x4307
    ctx->r1 = S32(0X4307 << 16);
    // 0x8080087C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800880: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800884: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XBF8) << 16);
    // 0x80800888: addiu       $a3, $a3, 0xBF8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XBF8));
    // 0x8080088C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800890: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800894: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80800898: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8080089C: jal         0x80800A28
    // 0x808008A0: nop

    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_58;
    // 0x808008A0: nop

    after_58:
    // 0x808008A4: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x808008A8: lui         $at, 0x4307
    ctx->r1 = S32(0X4307 << 16);
    // 0x808008AC: beql        $t4, $zero, L_808008E0
    if (ctx->r12 == 0) {
        // 0x808008B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008E0;
    }
    goto skip_14;
    // 0x808008B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_14:
    // 0x808008B4: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808008B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808008BC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XC20) << 16);
    // 0x808008C0: addiu       $a3, $a3, 0xC20
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XC20));
    // 0x808008C4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808008C8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808008CC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808008D0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808008D4: jal         0x80800A28
    // 0x808008D8: nop

    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_59;
    // 0x808008D8: nop

    after_59:
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808008E0:
    // 0x808008E0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x808008E4: jal         0x8008A0D0
    // 0x808008E8: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_60;
    // 0x808008E8: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_60:
    // 0x808008EC: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x808008F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808008F4: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808008F8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XBF8) << 16);
    // 0x808008FC: addiu       $a3, $a3, 0xBF8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XBF8));
    // 0x80800900: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800904: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800908: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8080090C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800910: jal         0x80800A28
    // 0x80800914: nop

    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_61;
    // 0x80800914: nop

    after_61:
    // 0x80800918: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8080091C: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80800920: beql        $t6, $zero, L_80800954
    if (ctx->r14 == 0) {
        // 0x80800924: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800954;
    }
    goto skip_15;
    // 0x80800924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_15:
    // 0x80800928: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080092C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800930: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XC20) << 16);
    // 0x80800934: addiu       $a3, $a3, 0xC20
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XC20));
    // 0x80800938: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080093C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800940: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800944: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800948: jal         0x80800A28
    // 0x8080094C: nop

    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_62;
    // 0x8080094C: nop

    after_62:
    // 0x80800950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800954:
    // 0x80800954: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80800958: jal         0x8008A0D0
    // 0x8080095C: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_63;
    // 0x8080095C: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_63:
    // 0x80800960: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2428, 0XBB0) << 16);
    // 0x80800964: lwc1        $f16, 0xBB0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2428, 0XBB0));
    // 0x80800968: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080096C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XBF8) << 16);
    // 0x80800970: addiu       $a3, $a3, 0xBF8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XBF8));
    // 0x80800974: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800978: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8080097C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80800980: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800984: jal         0x80800A28
    // 0x80800988: nop

    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_64;
    // 0x80800988: nop

    after_64:
    // 0x8080098C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80800990: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2428, 0XBB4) << 16);
    // 0x80800994: beql        $t7, $zero, L_808009C8
    if (ctx->r15 == 0) {
        // 0x80800998: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_808009C8;
    }
    goto skip_16;
    // 0x80800998: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    skip_16:
    // 0x8080099C: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808009A0: lwc1        $f6, 0xBB4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2428, 0XBB4));
    // 0x808009A4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2428, 0XC20) << 16);
    // 0x808009A8: addiu       $a3, $a3, 0xC20
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2428, 0XC20));
    // 0x808009AC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808009B0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808009B4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808009B8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808009BC: jal         0x80800A28
    // 0x808009C0: nop

    func_80800A28_chdinofamilyfx(rdram, ctx);
        goto after_65;
    // 0x808009C0: nop

    after_65:
    // 0x808009C4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
L_808009C8:
    // 0x808009C8: lui         $at, 0x7FF3
    ctx->r1 = S32(0X7FF3 << 16);
    // 0x808009CC: ori         $at, $at, 0x8800
    ctx->r1 = ctx->r1 | 0X8800;
    // 0x808009D0: lui         $a2, 0x7D0
    ctx->r6 = S32(0X7D0 << 16);
    // 0x808009D4: andi        $t8, $a0, 0x7FF
    ctx->r24 = ctx->r4 & 0X7FF;
    // 0x808009D8: addu        $a0, $t8, $at
    ctx->r4 = ADD32(ctx->r24, ctx->r1);
    // 0x808009DC: ori         $a2, $a2, 0x12C
    ctx->r6 = ctx->r6 | 0X12C;
    // 0x808009E0: jal         0x800C4140
    // 0x808009E4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_66;
    // 0x808009E4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_66:
    // 0x808009E8: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
L_808009EC:
    // 0x808009EC: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808009F0: jal         0x80101E14
    // 0x808009F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_67;
    // 0x808009F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_67:
    // 0x808009F8: beq         $v0, $zero, L_80800A14
    if (ctx->r2 == 0) {
        // 0x808009FC: lui         $a0, 0x7FED
        ctx->r4 = S32(0X7FED << 16);
            goto L_80800A14;
    }
    // 0x808009FC: lui         $a0, 0x7FED
    ctx->r4 = S32(0X7FED << 16);
    // 0x80800A00: lui         $a2, 0x7D0
    ctx->r6 = S32(0X7D0 << 16);
    // 0x80800A04: ori         $a2, $a2, 0x12C
    ctx->r6 = ctx->r6 | 0X12C;
    // 0x80800A08: ori         $a0, $a0, 0xAE1F
    ctx->r4 = ctx->r4 | 0XAE1F;
    // 0x80800A0C: jal         0x800C4140
    // 0x80800A10: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_68;
    // 0x80800A10: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_68:
L_80800A14:
    // 0x80800A14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A18:
    // 0x80800A18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A1C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // 0x80800A20: jr          $ra
    // 0x80800A24: nop

    return;
    // 0x80800A24: nop

;}
RECOMP_FUNC void bsstatue_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801204: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801208: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(372, 0X1600) << 16);
    // 0x8080120C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801210: jr          $ra
    // 0x80801214: lw          $v0, 0x1600($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(372, 0X1600));
    return;
    // 0x80801214: lw          $v0, 0x1600($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(372, 0X1600));
;}
RECOMP_FUNC void func_80103DFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103DFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103E00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103E04: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80103E08: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80103E0C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80103E10: lhu         $t7, 0x14($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X14);
    // 0x80103E14: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80103E18: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80103E1C: bnel        $t7, $at, L_80103E3C
    if (ctx->r15 != ctx->r1) {
        // 0x80103E20: sw          $a2, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r6;
            goto L_80103E3C;
    }
    goto skip_0;
    // 0x80103E20: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    skip_0:
    // 0x80103E24: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80103E28: jal         0x800EE7F8
    // 0x80103E2C: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80103E2C: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    after_0:
    // 0x80103E30: b           L_80103EA0
    // 0x80103E34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80103EA0;
    // 0x80103E34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103E38: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
L_80103E3C:
    // 0x80103E3C: jal         0x80103328
    // 0x80103E40: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80103328(rdram, ctx);
        goto after_1;
    // 0x80103E40: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x80103E44: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80103E48: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80103E4C: jal         0x800EE7F8
    // 0x80103E50: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80103E50: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    after_2:
    // 0x80103E54: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80103E58: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80103E5C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80103E60: lh          $v0, 0x88($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X88);
    // 0x80103E64: lh          $t8, 0x8A($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X8A);
    // 0x80103E68: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80103E6C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80103E70: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
    // 0x80103E74: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80103E78: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80103E7C: lwc1        $f16, 0x4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80103E80: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80103E84: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80103E88: lwc1        $f6, 0x38($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X38);
    // 0x80103E8C: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80103E90: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80103E94: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80103E98: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
    // 0x80103E9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80103EA0:
    // 0x80103EA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80103EA4: jr          $ra
    // 0x80103EA8: nop

    return;
    // 0x80103EA8: nop

;}
RECOMP_FUNC void _gcfrontend_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800881A0: syscall     673
    recomp_syscall_handler(rdram, ctx, 0x800881A0);
    return;
    // 0x800881A4: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_80800000_fxegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2834, 0X550) << 16);
    // 0x80800004: lh          $v1, 0x550($v1)
    ctx->r3 = MEM_H(ctx->r3, (int16_t)RELOC_LO16(2834, 0X550));
L_80800008:
    // 0x80800008: beq         $v1, $zero, L_80800038
    if (ctx->r3 == 0) {
        // 0x8080000C: lui         $t6, 0x8080
        ctx->r14 = S32(RELOC_HI16(2834, 0X550) << 16);
            goto L_80800038;
    }
    // 0x8080000C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2834, 0X550) << 16);
    // 0x80800010: addiu       $a1, $t6, 0x550
    ctx->r5 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2834, 0X550));
    // 0x80800014: lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X0);
L_80800018:
    // 0x80800018: bnel        $a0, $v0, L_8080002C
    if (ctx->r4 != ctx->r2) {
        // 0x8080001C: lh          $v0, 0x6($a1)
        ctx->r2 = MEM_H(ctx->r5, 0X6);
            goto L_8080002C;
    }
    goto skip_0;
    // 0x8080001C: lh          $v0, 0x6($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X6);
    skip_0:
    // 0x80800020: jr          $ra
    // 0x80800024: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x80800024: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80800028: lh          $v0, 0x6($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X6);
L_8080002C:
    // 0x8080002C: addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
    // 0x80800030: bne         $v0, $zero, L_80800018
    if (ctx->r2 != 0) {
        // 0x80800034: nop
    
            goto L_80800018;
    }
    // 0x80800034: nop

L_80800038:
    // 0x80800038: b           L_80800008
    // 0x8080003C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80800008;
    // 0x8080003C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800040: jr          $ra
    // 0x80800044: nop

    return;
    // 0x80800044: nop

;}
RECOMP_FUNC void _chlavaentrydoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800870A0: syscall     508
    recomp_syscall_handler(rdram, ctx, 0x800870A0);
    return;
    // 0x800870A4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800170_chstarspinnerplanet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800170: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800178: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080017C: jal         0x800DA298
    // 0x80800180: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800180: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80800184: beql        $v0, $zero, L_808001DC
    if (ctx->r2 == 0) {
        // 0x80800188: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001DC;
    }
    goto skip_0;
    // 0x80800188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080018C: jal         0x800D8FF8
    // 0x80800190: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800190: nop

    after_1:
    // 0x80800194: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800198: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8080019C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x808001A0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001A4: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x808001A8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808001AC: jal         0x800F15F8
    // 0x808001B0: lwc1        $f12, 0x2C($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X2C);
    func_800F15F8(rdram, ctx);
        goto after_2;
    // 0x808001B0: lwc1        $f12, 0x2C($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X2C);
    after_2:
    // 0x808001B4: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x808001B8: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x808001BC: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808001C0: lwc1        $f4, 0x48($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X48);
    // 0x808001C4: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808001C8: jal         0x800136E4
    // 0x808001CC: sub.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_3;
    // 0x808001CC: sub.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f8.fl;
    after_3:
    // 0x808001D0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x808001D4: swc1        $f0, 0x48($t7)
    MEM_W(0X48, ctx->r15) = ctx->f0.u32l;
    // 0x808001D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001DC:
    // 0x808001DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001E0: jr          $ra
    // 0x808001E4: nop

    return;
    // 0x808001E4: nop

;}
RECOMP_FUNC void _badrone_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800848B0: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x800848B0);
    return;
    // 0x800848B4: addi        $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
;}
RECOMP_FUNC void func_808007BC_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808007C4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x808007C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007CC: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x808007D0: ori         $t6, $a2, 0x800
    ctx->r14 = ctx->r6 | 0X800;
    // 0x808007D4: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x808007D8: jal         0x800856B0
    // 0x808007DC: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808007DC: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_0:
    // 0x808007E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007E8: jr          $ra
    // 0x808007EC: nop

    return;
    // 0x808007EC: nop

;}
RECOMP_FUNC void func_8080401C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080401C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804024: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80804028: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080402C: jal         0x80087D30
    // 0x80804030: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    _gcnewoption_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x80804030: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80804034: bne         $v0, $zero, L_8080406C
    if (ctx->r2 != 0) {
        // 0x80804038: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080406C;
    }
    // 0x80804038: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080403C: jal         0x80087D50
    // 0x80804040: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _gcnewoption_entrypoint_23(rdram, ctx);
        goto after_1;
    // 0x80804040: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80804044: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(804, 0X83C8) << 16);
    // 0x80804048: addiu       $a2, $a2, -0x7C38
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(804, 0X83C8));
    // 0x8080404C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80804050: jal         0x80087D00
    // 0x80804054: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _gcnewoption_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x80804054: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80804058: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8080405C: beql        $t6, $zero, L_80804070
    if (ctx->r14 == 0) {
        // 0x80804060: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80804070;
    }
    goto skip_0;
    // 0x80804060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80804064: jal         0x80803CE0
    // 0x80804068: nop

    func_80803CE0_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80804068: nop

    after_3:
L_8080406C:
    // 0x8080406C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80804070:
    // 0x80804070: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804074: jr          $ra
    // 0x80804078: nop

    return;
    // 0x80804078: nop

;}
RECOMP_FUNC void func_80107C00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107C00: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80107C04: jr          $ra
    // 0x80107C08: lwc1        $f0, 0x6F10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6F10);
    return;
    // 0x80107C08: lwc1        $f0, 0x6F10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6F10);
    // 0x80107C0C: nop

;}
RECOMP_FUNC void func_800C67F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C67F8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C67FC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800C6800: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C6804: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_800C6808:
    // 0x800C6808: lbu         $t6, 0x40($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X40);
    // 0x800C680C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C6810: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C6814: sb          $t6, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r14;
    // 0x800C6818: lbu         $t7, 0x41($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X41);
    // 0x800C681C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800C6820: sb          $t7, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r15;
    // 0x800C6824: lbu         $t8, 0x3E($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X3E);
    // 0x800C6828: sb          $t8, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r24;
    // 0x800C682C: lbu         $t9, 0x3F($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X3F);
    // 0x800C6830: bne         $v0, $a0, L_800C6808
    if (ctx->r2 != ctx->r4) {
        // 0x800C6834: sb          $t9, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r25;
            goto L_800C6808;
    }
    // 0x800C6834: sb          $t9, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r25;
    // 0x800C6838: jr          $ra
    // 0x800C683C: nop

    return;
    // 0x800C683C: nop

;}
RECOMP_FUNC void func_80800BBC_chkingjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800BC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BC8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800BCC: jal         0x80088078
    // 0x80800BD0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    _gcdialogcamera_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800BD0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80800BD4: beq         $v0, $zero, L_80800C04
    if (ctx->r2 == 0) {
        // 0x80800BD8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800C04;
    }
    // 0x80800BD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800BDC: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80800BE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800BE4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800BE8: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800BEC: beq         $t7, $at, L_80800BFC
    if (ctx->r15 == ctx->r1) {
        // 0x80800BF0: nop
    
            goto L_80800BFC;
    }
    // 0x80800BF0: nop

    // 0x80800BF4: jal         0x80800C60
    // 0x80800BF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800C60_chkingjinjo(rdram, ctx);
        goto after_1;
    // 0x80800BF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_80800BFC:
    // 0x80800BFC: b           L_80800C08
    // 0x80800C00: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800C08;
    // 0x80800C00: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800C04:
    // 0x80800C04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C08:
    // 0x80800C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C10: jr          $ra
    // 0x80800C14: nop

    return;
    // 0x80800C14: nop

;}
