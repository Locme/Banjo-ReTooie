#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80801C78_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C78: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801C7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801C80: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801C84: jal         0x800D9078
    // 0x80801C88: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x80801C88: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
    // 0x80801C8C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80801C90: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801C94: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801C98: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x80801C9C: lwc1        $f12, 0x28($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X28);
    // 0x80801CA0: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801CA4: lui         $a3, 0xC37A
    ctx->r7 = S32(0XC37A << 16);
    // 0x80801CA8: jal         0x800F12D4
    // 0x80801CAC: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F12D4(rdram, ctx);
        goto after_1;
    // 0x80801CAC: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x80801CB0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80801CB4: swc1        $f0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f0.u32l;
    // 0x80801CB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801CBC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80801CC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801CC4: jr          $ra
    // 0x80801CC8: nop

    return;
    // 0x80801CC8: nop

    // 0x80801CCC: nop

;}
RECOMP_FUNC void func_808046CC_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808046CC: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x808046D0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x808046D4: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x808046D8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808046DC: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x808046E0: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x808046E4: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x808046E8: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x808046EC: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x808046F0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808046F4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808046F8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808046FC: jal         0x80100094
    // 0x80804700: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80804700: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80804704: jal         0x800D8FF8
    // 0x80804708: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80804708: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    after_1:
    // 0x8080470C: lwc1        $f4, 0x10($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X10);
    // 0x80804710: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X5354) << 16);
    // 0x80804714: lwc1        $f12, 0x8($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X8);
    // 0x80804718: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8080471C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80804720: lui         $a3, 0x3D08
    ctx->r7 = S32(0X3D08 << 16);
    // 0x80804724: ori         $a3, $a3, 0x6595
    ctx->r7 = ctx->r7 | 0X6595;
    // 0x80804728: swc1        $f6, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->f6.u32l;
    // 0x8080472C: lwc1        $f8, 0x5354($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X5354));
    // 0x80804730: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80804734: jal         0x800F10B4
    // 0x80804738: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80804738: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8080473C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80804740: lwc1        $f2, 0x10($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X10);
    // 0x80804744: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80804748: addiu       $s2, $s1, 0x4
    ctx->r18 = ADD32(ctx->r17, 0X4);
    // 0x8080474C: c.le.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl <= ctx->f24.fl;
    // 0x80804750: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80804754: addiu       $s5, $sp, 0x5C
    ctx->r21 = ADD32(ctx->r29, 0X5C);
    // 0x80804758: bc1fl       L_8080484C
    if (!c1cs) {
        // 0x8080475C: lbu         $t9, 0x79($s1)
        ctx->r25 = MEM_BU(ctx->r17, 0X79);
            goto L_8080484C;
    }
    goto skip_0;
    // 0x8080475C: lbu         $t9, 0x79($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X79);
    skip_0:
    // 0x80804760: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80804764: addiu       $s3, $sp, 0x70
    ctx->r19 = ADD32(ctx->r29, 0X70);
    // 0x80804768: add.s       $f10, $f2, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f22.fl;
L_8080476C:
    // 0x8080476C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80804770: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80804774: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80804778: jal         0x800EE7F8
    // 0x8080477C: swc1        $f10, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->f10.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x8080477C: swc1        $f10, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->f10.u32l;
    after_3:
    // 0x80804780: lbu         $t6, 0x79($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X79);
    // 0x80804784: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x80804788: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8080478C: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x80804790: beq         $at, $zero, L_80804824
    if (ctx->r1 == 0) {
        // 0x80804794: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80804824;
    }
    // 0x80804794: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80804798: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X5358) << 16);
    // 0x8080479C: addu        $at, $at, $t8
    gpr jr_addend_808047A4 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808047A0: lw          $t8, 0x5358($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1852, 0X5358));
    // 0x808047A4: jr          $t8
    // 0x808047A8: nop

    switch (jr_addend_808047A4 >> 2) {
        case 0: goto L_808047AC; break;
        case 1: goto L_80804824; break;
        case 2: goto L_808047AC; break;
        case 3: goto L_80804810; break;
        case 4: goto L_808047AC; break;
        case 5: goto L_80804824; break;
        case 6: goto L_808047E8; break;
        default: switch_error(__func__, 0x808047A4, 0x80805358);
    }
    // 0x808047A8: nop

L_808047AC:
    // 0x808047AC: jal         0x800DC0C0
    // 0x808047B0: nop

    func_800DC0C0(rdram, ctx);
        goto after_4;
    // 0x808047B0: nop

    after_4:
    // 0x808047B4: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x808047B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808047BC: bc1f        L_808047D8
    if (!c1cs) {
        // 0x808047C0: nop
    
            goto L_808047D8;
    }
    // 0x808047C0: nop

    // 0x808047C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808047C8: jal         0x80088A70
    // 0x808047CC: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    _fxegg_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x808047CC: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_5:
    // 0x808047D0: b           L_80804824
    // 0x808047D4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_80804824;
    // 0x808047D4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_808047D8:
    // 0x808047D8: jal         0x80088A68
    // 0x808047DC: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    _fxegg_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x808047DC: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_6:
    // 0x808047E0: b           L_80804824
    // 0x808047E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_80804824;
    // 0x808047E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_808047E8:
    // 0x808047E8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x808047EC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808047F0: jal         0x800EFA20
    // 0x808047F4: addiu       $a1, $s1, 0x28
    ctx->r5 = ADD32(ctx->r17, 0X28);
    func_800EFA20(rdram, ctx);
        goto after_7;
    // 0x808047F4: addiu       $a1, $s1, 0x28
    ctx->r5 = ADD32(ctx->r17, 0X28);
    after_7:
    // 0x808047F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808047FC: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    // 0x80804800: jal         0x80088A90
    // 0x80804804: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    _fxegg_entrypoint_6(rdram, ctx);
        goto after_8;
    // 0x80804804: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_8:
    // 0x80804808: b           L_80804824
    // 0x8080480C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_80804824;
    // 0x8080480C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80804810:
    // 0x80804810: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804814: addiu       $a1, $s1, 0x28
    ctx->r5 = ADD32(ctx->r17, 0X28);
    // 0x80804818: jal         0x80088A88
    // 0x8080481C: lw          $a2, 0x38($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X38);
    _fxegg_entrypoint_5(rdram, ctx);
        goto after_9;
    // 0x8080481C: lw          $a2, 0x38($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X38);
    after_9:
    // 0x80804820: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80804824:
    // 0x80804824: beq         $s0, $zero, L_80804834
    if (ctx->r16 == 0) {
        // 0x80804828: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804834;
    }
    // 0x80804828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080482C: jal         0x800BA5A8
    // 0x80804830: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    func_800BA5A8(rdram, ctx);
        goto after_10;
    // 0x80804830: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_10:
L_80804834:
    // 0x80804834: lwc1        $f2, 0x10($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X10);
    // 0x80804838: c.le.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl <= ctx->f24.fl;
    // 0x8080483C: nop

    // 0x80804840: bc1tl       L_8080476C
    if (c1cs) {
        // 0x80804844: add.s       $f10, $f2, $f22
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f22.fl;
            goto L_8080476C;
    }
    goto skip_1;
    // 0x80804844: add.s       $f10, $f2, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f22.fl;
    skip_1:
    // 0x80804848: lbu         $t9, 0x79($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X79);
L_8080484C:
    // 0x8080484C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80804850: srl         $t0, $t9, 4
    ctx->r8 = S32(U32(ctx->r25) >> 4);
    // 0x80804854: bnel        $t0, $at, L_80804878
    if (ctx->r8 != ctx->r1) {
        // 0x80804858: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80804878;
    }
    goto skip_2;
    // 0x80804858: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_2:
    // 0x8080485C: jal         0x8001210C
    // 0x80804860: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_11;
    // 0x80804860: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    // 0x80804864: bne         $v0, $zero, L_80804874
    if (ctx->r2 != 0) {
        // 0x80804868: addiu       $a0, $s1, 0x4
        ctx->r4 = ADD32(ctx->r17, 0X4);
            goto L_80804874;
    }
    // 0x80804868: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x8080486C: jal         0x80088A78
    // 0x80804870: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    _fxegg_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x80804870: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_12:
L_80804874:
    // 0x80804874: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80804878:
    // 0x80804878: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8080487C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80804880: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80804884: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80804888: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8080488C: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x80804890: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x80804894: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x80804898: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x8080489C: jr          $ra
    // 0x808048A0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x808048A0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_80800684_chtrashcompactor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800684: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800688: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8080068C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800690: beq         $a1, $at, L_8080073C
    if (ctx->r5 == ctx->r1) {
        // 0x80800694: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_8080073C;
    }
    // 0x80800694: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800698: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x8080069C: beq         $a1, $at, L_808006C4
    if (ctx->r5 == ctx->r1) {
        // 0x808006A0: addiu       $a0, $zero, 0x3B5
        ctx->r4 = ADD32(0, 0X3B5);
            goto L_808006C4;
    }
    // 0x808006A0: addiu       $a0, $zero, 0x3B5
    ctx->r4 = ADD32(0, 0X3B5);
    // 0x808006A4: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808006A8: beq         $a1, $at, L_80800708
    if (ctx->r5 == ctx->r1) {
        // 0x808006AC: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_80800708;
    }
    // 0x808006AC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x808006B0: addiu       $at, $zero, 0x9F
    ctx->r1 = ADD32(0, 0X9F);
    // 0x808006B4: beq         $a1, $at, L_8080075C
    if (ctx->r5 == ctx->r1) {
        // 0x808006B8: lw          $t3, 0x20($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X20);
            goto L_8080075C;
    }
    // 0x808006B8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x808006BC: b           L_80800794
    // 0x808006C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800794;
    // 0x808006C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006C4:
    // 0x808006C4: jal         0x801084B0
    // 0x808006C8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_801084B0(rdram, ctx);
        goto after_0;
    // 0x808006C8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x808006CC: beq         $v0, $zero, L_80800790
    if (ctx->r2 == 0) {
        // 0x808006D0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800790;
    }
    // 0x808006D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006D4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808006D8: jal         0x80108944
    // 0x808006DC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80108944(rdram, ctx);
        goto after_1;
    // 0x808006DC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808006E0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808006E4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808006E8: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x808006EC: lwc1        $f6, 0x34($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X34);
    // 0x808006F0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x808006F4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808006F8: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x808006FC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80800700: b           L_80800790
    // 0x80800704: sw          $t7, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->r15;
        goto L_80800790;
    // 0x80800704: sw          $t7, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->r15;
L_80800708:
    // 0x80800708: sw          $zero, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = 0;
    // 0x8080070C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800710: jal         0x80108B04
    // 0x80800714: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_2;
    // 0x80800714: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800718: jal         0x800DA298
    // 0x8080071C: addiu       $a0, $zero, 0x1A0
    ctx->r4 = ADD32(0, 0X1A0);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x8080071C: addiu       $a0, $zero, 0x1A0
    ctx->r4 = ADD32(0, 0X1A0);
    after_3:
    // 0x80800720: bne         $v0, $zero, L_80800790
    if (ctx->r2 != 0) {
        // 0x80800724: addiu       $a0, $zero, 0x3A7
        ctx->r4 = ADD32(0, 0X3A7);
            goto L_80800790;
    }
    // 0x80800724: addiu       $a0, $zero, 0x3A7
    ctx->r4 = ADD32(0, 0X3A7);
    // 0x80800728: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8080072C: jal         0x80101180
    // 0x80800730: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_4;
    // 0x80800730: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80800734: b           L_80800794
    // 0x80800738: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800794;
    // 0x80800738: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080073C:
    // 0x8080073C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800740: bne         $a2, $at, L_80800754
    if (ctx->r6 != ctx->r1) {
        // 0x80800744: lw          $t0, 0x20($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X20);
            goto L_80800754;
    }
    // 0x80800744: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80800748: lbu         $t1, 0x65($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X65);
    // 0x8080074C: andi        $t2, $t1, 0xFFF7
    ctx->r10 = ctx->r9 & 0XFFF7;
    // 0x80800750: sb          $t2, 0x65($t0)
    MEM_B(0X65, ctx->r8) = ctx->r10;
L_80800754:
    // 0x80800754: b           L_80800794
    // 0x80800758: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800794;
    // 0x80800758: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8080075C:
    // 0x8080075C: lw          $t4, 0x64($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X64);
    // 0x80800760: sll         $t6, $t4, 12
    ctx->r14 = S32(ctx->r12 << 12);
    // 0x80800764: bgezl       $t6, L_80800794
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800768: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800794;
    }
    goto skip_0;
    // 0x80800768: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8080076C: jal         0x80085710
    // 0x80800770: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_5;
    // 0x80800770: nop

    after_5:
    // 0x80800774: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800778: lbu         $t8, 0x65($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X65);
    // 0x8080077C: andi        $t9, $t8, 0xFFF7
    ctx->r25 = ctx->r24 & 0XFFF7;
    // 0x80800780: b           L_80800790
    // 0x80800784: sb          $t9, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r25;
        goto L_80800790;
    // 0x80800784: sb          $t9, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r25;
    // 0x80800788: b           L_80800794
    // 0x8080078C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800794;
    // 0x8080078C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800790:
    // 0x80800790: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800794:
    // 0x80800794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800798: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080079C: jr          $ra
    // 0x808007A0: nop

    return;
    // 0x808007A0: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082BE8: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082BE8);
    return;
    // 0x80082BEC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80800338_chfactorytoxicpools(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800338: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080033C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800340: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800344: jal         0x80100094
    // 0x80800348: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800348: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080034C: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
    // 0x80800350: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800354: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800358: beq         $v1, $zero, L_80800370
    if (ctx->r3 == 0) {
        // 0x8080035C: nop
    
            goto L_80800370;
    }
    // 0x8080035C: nop

    // 0x80800360: beq         $v1, $at, L_80800380
    if (ctx->r3 == ctx->r1) {
        // 0x80800364: addiu       $a0, $a1, 0x4
        ctx->r4 = ADD32(ctx->r5, 0X4);
            goto L_80800380;
    }
    // 0x80800364: addiu       $a0, $a1, 0x4
    ctx->r4 = ADD32(ctx->r5, 0X4);
    // 0x80800368: b           L_808003D0
    // 0x8080036C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003D0;
    // 0x8080036C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800370:
    // 0x80800370: jal         0x80085838
    // 0x80800374: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _chswitch_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80800374: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800378: b           L_808003D0
    // 0x8080037C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003D0;
    // 0x8080037C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800380:
    // 0x80800380: jal         0x800D9078
    // 0x80800384: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D9078(rdram, ctx);
        goto after_2;
    // 0x80800384: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_2:
    // 0x80800388: beq         $v0, $zero, L_808003CC
    if (ctx->r2 == 0) {
        // 0x8080038C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808003CC;
    }
    // 0x8080038C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800390: jal         0x80103110
    // 0x80800394: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_3;
    // 0x80800394: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800398: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8080039C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808003A0: jal         0x800F54E4
    // 0x808003A4: sh          $t6, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r14;
    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x808003A4: sh          $t6, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r14;
    after_4:
    // 0x808003A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003AC: jal         0x800F82D4
    // 0x808003B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_5;
    // 0x808003B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x808003B4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x808003B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808003BC: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x808003C0: addiu       $a3, $zero, 0x2030
    ctx->r7 = ADD32(0, 0X2030);
    // 0x808003C4: jal         0x80085708
    // 0x808003C8: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_6;
    // 0x808003C8: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_6:
L_808003CC:
    // 0x808003CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003D0:
    // 0x808003D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003D4: jr          $ra
    // 0x808003D8: nop

    return;
    // 0x808003D8: nop

;}
RECOMP_FUNC void _badata_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084700: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x80084700);
    return;
    // 0x80084704: addi        $t0, $zero, 0x60
    ctx->r8 = ADD32(0, 0X60);
;}
RECOMP_FUNC void _fxstep_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A30: syscall     718
    recomp_syscall_handler(rdram, ctx, 0x80088A30);
    return;
    // 0x80088A34: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void _chjinjo_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086B90: syscall     425
    recomp_syscall_handler(rdram, ctx, 0x80086B90);
    return;
    // 0x80086B94: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void freelist_used_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3204: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x800B3208: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800B320C: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x800B3210: beql        $t6, $zero, L_800B3240
    if (ctx->r14 == 0) {
        // 0x800B3214: lh          $t8, 0x2($a0)
        ctx->r24 = MEM_H(ctx->r4, 0X2);
            goto L_800B3240;
    }
    goto skip_0;
    // 0x800B3214: lh          $t8, 0x2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2);
    skip_0:
    // 0x800B3218: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x800B321C: lh          $a3, 0x0($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X0);
L_800B3220:
    // 0x800B3220: multu       $a2, $a3
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B3224: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B3228: mflo        $t7
    ctx->r15 = lo;
    // 0x800B322C: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    // 0x800B3230: lh          $a2, 0x0($a1)
    ctx->r6 = MEM_H(ctx->r5, 0X0);
    // 0x800B3234: bne         $a2, $zero, L_800B3220
    if (ctx->r6 != 0) {
        // 0x800B3238: nop
    
            goto L_800B3220;
    }
    // 0x800B3238: nop

    // 0x800B323C: lh          $t8, 0x2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2);
L_800B3240:
    // 0x800B3240: jr          $ra
    // 0x800B3244: subu        $v0, $t8, $v1
    ctx->r2 = SUB32(ctx->r24, ctx->r3);
    return;
    // 0x800B3244: subu        $v0, $t8, $v1
    ctx->r2 = SUB32(ctx->r24, ctx->r3);
;}
RECOMP_FUNC void func_8080000C_chdingpot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800018: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080001C: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80800020: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800024: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800028: jal         0x80102FDC
    // 0x8080002C: nop

    func_80102FDC(rdram, ctx);
        goto after_0;
    // 0x8080002C: nop

    after_0:
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800038: jr          $ra
    // 0x8080003C: nop

    return;
    // 0x8080003C: nop

;}
RECOMP_FUNC void func_800B8CE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8CE0: addiu       $t6, $a0, -0xC24
    ctx->r14 = ADD32(ctx->r4, -0XC24);
    // 0x800B8CE4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8CE8: jr          $ra
    // 0x800B8CEC: sb          $t6, -0x7D37($at)
    MEM_B(-0X7D37, ctx->r1) = ctx->r14;
    return;
    // 0x800B8CEC: sb          $t6, -0x7D37($at)
    MEM_B(-0X7D37, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void bsbeemain_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800224: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800228: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(80, 0X1260) << 16);
    // 0x8080022C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800230: jr          $ra
    // 0x80800234: lw          $v0, 0x1260($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(80, 0X1260));
    return;
    // 0x80800234: lw          $v0, 0x1260($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(80, 0X1260));
;}
RECOMP_FUNC void func_808004FC_chmasterjiggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800500: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800504: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800508: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080050C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800510: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80800514: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x80800518: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8080051C: jal         0x8008FB10
    // 0x80800520: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    func_8008FB10(rdram, ctx);
        goto after_0;
    // 0x80800520: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    after_0:
    // 0x80800524: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800528: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080052C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800530: sltiu       $at, $t8, 0xA
    ctx->r1 = ctx->r24 < 0XA ? 1 : 0;
    // 0x80800534: beq         $at, $zero, L_808006F0
    if (ctx->r1 == 0) {
        // 0x80800538: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808006F0;
    }
    // 0x80800538: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080053C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(768, 0X1550) << 16);
    // 0x80800540: addu        $at, $at, $t8
    gpr jr_addend_80800548 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800544: lw          $t8, 0x1550($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(768, 0X1550));
    // 0x80800548: jr          $t8
    // 0x8080054C: nop

    switch (jr_addend_80800548 >> 2) {
        case 0: goto L_80800550; break;
        case 1: goto L_808005CC; break;
        case 2: goto L_808005CC; break;
        case 3: goto L_808005DC; break;
        case 4: goto L_80800614; break;
        case 5: goto L_80800634; break;
        case 6: goto L_808006F0; break;
        case 7: goto L_80800654; break;
        case 8: goto L_808006CC; break;
        case 9: goto L_808006CC; break;
        default: switch_error(__func__, 0x80800548, 0x80801550);
    }
    // 0x8080054C: nop

L_80800550:
    // 0x80800550: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800554: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80800558: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8080055C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800560: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800564: addiu       $a2, $zero, 0x190
    ctx->r6 = ADD32(0, 0X190);
    // 0x80800568: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    // 0x8080056C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800570: jal         0x8008A1E0
    // 0x80800574: nop

    _subaddiedialog_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800574: nop

    after_1:
    // 0x80800578: beq         $v0, $zero, L_808005B4
    if (ctx->r2 == 0) {
        // 0x8080057C: nop
    
            goto L_808005B4;
    }
    // 0x8080057C: nop

    // 0x80800580: jal         0x8008A740
    // 0x80800584: nop

    _sujiggy_entrypoint_21(rdram, ctx);
        goto after_2;
    // 0x80800584: nop

    after_2:
    // 0x80800588: beq         $v0, $zero, L_808005A4
    if (ctx->r2 == 0) {
        // 0x8080058C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005A4;
    }
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800594: jal         0x808001D0
    // 0x80800598: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808001D0_chmasterjiggy(rdram, ctx);
        goto after_3;
    // 0x80800598: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x8080059C: b           L_808005BC
    // 0x808005A0: nop

        goto L_808005BC;
    // 0x808005A0: nop

L_808005A4:
    // 0x808005A4: jal         0x808001D0
    // 0x808005A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808001D0_chmasterjiggy(rdram, ctx);
        goto after_4;
    // 0x808005A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808005AC: b           L_808005BC
    // 0x808005B0: nop

        goto L_808005BC;
    // 0x808005B0: nop

L_808005B4:
    // 0x808005B4: jal         0x80800414
    // 0x808005B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800414_chmasterjiggy(rdram, ctx);
        goto after_5;
    // 0x808005B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_808005BC:
    // 0x808005BC: jal         0x8080047C
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080047C_chmasterjiggy(rdram, ctx);
        goto after_6;
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808005C4: b           L_808006F4
    // 0x808005C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006F4;
    // 0x808005C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808005CC:
    // 0x808005CC: jal         0x8080047C
    // 0x808005D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080047C_chmasterjiggy(rdram, ctx);
        goto after_7;
    // 0x808005D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808005D4: b           L_808006F4
    // 0x808005D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006F4;
    // 0x808005D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808005DC:
    // 0x808005DC: jal         0x800C0638
    // 0x808005E0: nop

    func_800C0638(rdram, ctx);
        goto after_8;
    // 0x808005E0: nop

    after_8:
    // 0x808005E4: bne         $v0, $zero, L_80800604
    if (ctx->r2 != 0) {
        // 0x808005E8: nop
    
            goto L_80800604;
    }
    // 0x808005E8: nop

    // 0x808005EC: jal         0x800D9078
    // 0x808005F0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_9;
    // 0x808005F0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_9:
    // 0x808005F4: beq         $v0, $zero, L_80800604
    if (ctx->r2 == 0) {
        // 0x808005F8: nop
    
            goto L_80800604;
    }
    // 0x808005F8: nop

    // 0x808005FC: jal         0x808001B0
    // 0x80800600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001B0_chmasterjiggy(rdram, ctx);
        goto after_10;
    // 0x80800600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_80800604:
    // 0x80800604: jal         0x8080047C
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080047C_chmasterjiggy(rdram, ctx);
        goto after_11;
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080060C: b           L_808006F4
    // 0x80800610: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006F4;
    // 0x80800610: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800614:
    // 0x80800614: jal         0x800D90A4
    // 0x80800618: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    func_800D90A4(rdram, ctx);
        goto after_12;
    // 0x80800618: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    after_12:
    // 0x8080061C: beq         $v0, $zero, L_808006F0
    if (ctx->r2 == 0) {
        // 0x80800620: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006F0;
    }
    // 0x80800620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800624: jal         0x80800220
    // 0x80800628: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800220_chmasterjiggy(rdram, ctx);
        goto after_13;
    // 0x80800628: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_13:
    // 0x8080062C: b           L_808006F4
    // 0x80800630: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006F4;
    // 0x80800630: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800634:
    // 0x80800634: jal         0x80101DDC
    // 0x80800638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_14;
    // 0x80800638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8080063C: beq         $v0, $zero, L_808006F0
    if (ctx->r2 == 0) {
        // 0x80800640: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006F0;
    }
    // 0x80800640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800644: jal         0x80800220
    // 0x80800648: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800220_chmasterjiggy(rdram, ctx);
        goto after_15;
    // 0x80800648: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_15:
    // 0x8080064C: b           L_808006F4
    // 0x80800650: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006F4;
    // 0x80800650: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800654:
    // 0x80800654: jal         0x80800374
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800374_chmasterjiggy(rdram, ctx);
        goto after_16;
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8080065C: beql        $v0, $zero, L_80800688
    if (ctx->r2 == 0) {
        // 0x80800660: lwc1        $f8, 0x48($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
            goto L_80800688;
    }
    goto skip_0;
    // 0x80800660: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    skip_0:
    // 0x80800664: jal         0x808003D4
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003D4_chmasterjiggy(rdram, ctx);
        goto after_17;
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8080066C: beq         $v0, $zero, L_80800684
    if (ctx->r2 == 0) {
        // 0x80800670: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800684;
    }
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800674: jal         0x808001D0
    // 0x80800678: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808001D0_chmasterjiggy(rdram, ctx);
        goto after_18;
    // 0x80800678: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_18:
    // 0x8080067C: b           L_808006BC
    // 0x80800680: nop

        goto L_808006BC;
    // 0x80800680: nop

L_80800684:
    // 0x80800684: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
L_80800688:
    // 0x80800688: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8080068C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800690: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800694: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800698: addiu       $a2, $zero, 0x190
    ctx->r6 = ADD32(0, 0X190);
    // 0x8080069C: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    // 0x808006A0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808006A4: jal         0x8008A1E0
    // 0x808006A8: nop

    _subaddiedialog_entrypoint_6(rdram, ctx);
        goto after_19;
    // 0x808006A8: nop

    after_19:
    // 0x808006AC: beq         $v0, $zero, L_808006BC
    if (ctx->r2 == 0) {
        // 0x808006B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006BC;
    }
    // 0x808006B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B4: jal         0x808001D0
    // 0x808006B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808001D0_chmasterjiggy(rdram, ctx);
        goto after_20;
    // 0x808006B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_20:
L_808006BC:
    // 0x808006BC: jal         0x8080047C
    // 0x808006C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080047C_chmasterjiggy(rdram, ctx);
        goto after_21;
    // 0x808006C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808006C4: b           L_808006F4
    // 0x808006C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006F4;
    // 0x808006C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006CC:
    // 0x808006CC: jal         0x80101DDC
    // 0x808006D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_22;
    // 0x808006D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808006D4: beql        $v0, $zero, L_808006F4
    if (ctx->r2 == 0) {
        // 0x808006D8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808006F4;
    }
    goto skip_1;
    // 0x808006D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808006DC: lhu         $a1, 0x72($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X72);
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E4: srl         $t3, $a1, 10
    ctx->r11 = S32(U32(ctx->r5) >> 10);
    // 0x808006E8: jal         0x80800220
    // 0x808006EC: addiu       $a1, $t3, 0x1
    ctx->r5 = ADD32(ctx->r11, 0X1);
    func_80800220_chmasterjiggy(rdram, ctx);
        goto after_23;
    // 0x808006EC: addiu       $a1, $t3, 0x1
    ctx->r5 = ADD32(ctx->r11, 0X1);
    after_23:
L_808006F0:
    // 0x808006F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006F4:
    // 0x808006F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808006F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808006FC: jr          $ra
    // 0x80800700: nop

    return;
    // 0x80800700: nop

;}
RECOMP_FUNC void func_8080011C_bsride(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080011C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800124: jal         0x8009E6EC
    // 0x80800128: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80800128: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080012C: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80800130: bne         $v0, $at, L_80800154
    if (ctx->r2 != ctx->r1) {
        // 0x80800134: nop
    
            goto L_80800154;
    }
    // 0x80800134: nop

    // 0x80800138: jal         0x808000F0
    // 0x8080013C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808000F0_bsride(rdram, ctx);
        goto after_1;
    // 0x8080013C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800140: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800144: jal         0x8009E830
    // 0x80800148: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_2;
    // 0x80800148: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8080014C: b           L_80800160
    // 0x80800150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800160;
    // 0x80800150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800154:
    // 0x80800154: jal         0x80099B94
    // 0x80800158: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80099B94(rdram, ctx);
        goto after_3;
    // 0x80800158: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8080015C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800160:
    // 0x80800160: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800164: jr          $ra
    // 0x80800168: nop

    return;
    // 0x80800168: nop

;}
RECOMP_FUNC void func_800A34E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A34E4: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A34E8: jr          $ra
    // 0x800A34EC: sb          $a1, 0x3C($t6)
    MEM_B(0X3C, ctx->r14) = ctx->r5;
    return;
    // 0x800A34EC: sb          $a1, 0x3C($t6)
    MEM_B(0X3C, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void _fxkern_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088B28: syscall     724
    recomp_syscall_handler(rdram, ctx, 0x80088B28);
    return;
    // 0x80088B2C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void bsbfly_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801448: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080144C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(96, 0X1D78) << 16);
    // 0x80801450: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801454: jr          $ra
    // 0x80801458: lw          $v0, 0x1D78($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(96, 0X1D78));
    return;
    // 0x80801458: lw          $v0, 0x1D78($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(96, 0X1D78));
;}
RECOMP_FUNC void subaddiestore_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808000D4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x808000D8: addiu       $s5, $sp, 0x48
    ctx->r21 = ADD32(ctx->r29, 0X48);
    // 0x808000DC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808000E0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x808000E4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808000E8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x808000EC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x808000F0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808000F4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808000F8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808000FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800100: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80800104: jal         0x801067C4
    // 0x80800108: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_801067C4(rdram, ctx);
        goto after_0;
    // 0x80800108: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_0:
    // 0x8080010C: beq         $v0, $zero, L_808001C0
    if (ctx->r2 == 0) {
        // 0x80800110: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808001C0;
    }
    // 0x80800110: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800114: lui         $s4, 0x8
    ctx->r20 = S32(0X8 << 16);
    // 0x80800118: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8080011C: addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
L_80800120:
    // 0x80800120: lw          $t6, 0x6C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X6C);
    // 0x80800124: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800128: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080012C: srl         $t7, $t6, 21
    ctx->r15 = S32(U32(ctx->r14) >> 21);
    // 0x80800130: beq         $t7, $zero, L_808001B0
    if (ctx->r15 == 0) {
        // 0x80800134: nop
    
            goto L_808001B0;
    }
    // 0x80800134: nop

    // 0x80800138: jal         0x80801054
    // 0x8080013C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_80801054_subaddiestore(rdram, ctx);
        goto after_1;
    // 0x8080013C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_1:
    // 0x80800140: beql        $v0, $zero, L_80800188
    if (ctx->r2 == 0) {
        // 0x80800144: lw          $t2, 0x70($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X70);
            goto L_80800188;
    }
    goto skip_0;
    // 0x80800144: lw          $t2, 0x70($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X70);
    skip_0:
    // 0x80800148: bne         $v0, $s3, L_808001B0
    if (ctx->r2 != ctx->r19) {
        // 0x8080014C: lw          $t8, 0x50($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X50);
            goto L_808001B0;
    }
    // 0x8080014C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80800150: lw          $t9, 0x70($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X70);
    // 0x80800154: sll         $t1, $t9, 14
    ctx->r9 = S32(ctx->r25 << 14);
    // 0x80800158: bgezl       $t1, L_80800174
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8080015C: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_80800174;
    }
    goto skip_1;
    // 0x8080015C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    skip_1:
    // 0x80800160: jal         0x800887B0
    // 0x80800164: nop

    _glcutDll_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800164: nop

    after_2:
    // 0x80800168: beq         $v0, $zero, L_808001B0
    if (ctx->r2 == 0) {
        // 0x8080016C: nop
    
            goto L_808001B0;
    }
    // 0x8080016C: nop

    // 0x80800170: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
L_80800174:
    // 0x80800174: jal         0x80800B24
    // 0x80800178: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800B24_subaddiestore(rdram, ctx);
        goto after_3;
    // 0x80800178: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8080017C: b           L_808001B0
    // 0x80800180: nop

        goto L_808001B0;
    // 0x80800180: nop

    // 0x80800184: lw          $t2, 0x70($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X70);
L_80800188:
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080018C: sll         $t4, $t2, 14
    ctx->r12 = S32(ctx->r10 << 14);
    // 0x80800190: bltz        $t4, L_808001B0
    if (SIGNED(ctx->r12) < 0) {
        // 0x80800194: nop
    
            goto L_808001B0;
    }
    // 0x80800194: nop

    // 0x80800198: jal         0x80102F74
    // 0x8080019C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_80102F74(rdram, ctx);
        goto after_4;
    // 0x8080019C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_4:
    // 0x808001A0: bne         $v0, $zero, L_808001B0
    if (ctx->r2 != 0) {
        // 0x808001A4: nop
    
            goto L_808001B0;
    }
    // 0x808001A4: nop

    // 0x808001A8: jal         0x800FFAB0
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_808001B0:
    // 0x808001B0: jal         0x8010682C
    // 0x808001B4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8010682C(rdram, ctx);
        goto after_6;
    // 0x808001B4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_6:
    // 0x808001B8: bne         $v0, $zero, L_80800120
    if (ctx->r2 != 0) {
        // 0x808001BC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80800120;
    }
    // 0x808001BC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_808001C0:
    // 0x808001C0: addiu       $t5, $s1, 0x4
    ctx->r13 = ADD32(ctx->r17, 0X4);
    // 0x808001C4: sw          $t5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r13;
    // 0x808001C8: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    // 0x808001CC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808001D0: blezl       $t6, L_8080023C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x808001D4: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8080023C;
    }
    goto skip_2;
    // 0x808001D4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_2:
L_808001D8:
    // 0x808001D8: jal         0x80800330
    // 0x808001DC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800330_subaddiestore(rdram, ctx);
        goto after_7;
    // 0x808001DC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_7:
    // 0x808001E0: beq         $v0, $zero, L_80800218
    if (ctx->r2 == 0) {
        // 0x808001E4: lw          $t7, 0x50($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X50);
            goto L_80800218;
    }
    // 0x808001E4: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x808001E8: lwc1        $f4, 0x48($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X48);
    // 0x808001EC: lw          $a0, 0x6C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X6C);
    // 0x808001F0: addiu       $a1, $t7, 0x4
    ctx->r5 = ADD32(ctx->r15, 0X4);
    // 0x808001F4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808001F8: sll         $t8, $a0, 11
    ctx->r24 = S32(ctx->r4 << 11);
    // 0x808001FC: srl         $a0, $t8, 20
    ctx->r4 = S32(U32(ctx->r24) >> 20);
    // 0x80800200: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800204: jal         0x80108474
    // 0x80800208: nop

    func_80108474(rdram, ctx);
        goto after_8;
    // 0x80800208: nop

    after_8:
    // 0x8080020C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800210: jal         0x80800B24
    // 0x80800214: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800B24_subaddiestore(rdram, ctx);
        goto after_9;
    // 0x80800214: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
L_80800218:
    // 0x80800218: jal         0x80800FD0
    // 0x8080021C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800FD0_subaddiestore(rdram, ctx);
        goto after_10;
    // 0x8080021C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_10:
    // 0x80800220: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80800224: lh          $t1, 0x0($s6)
    ctx->r9 = MEM_H(ctx->r22, 0X0);
    // 0x80800228: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080022C: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80800230: bne         $at, $zero, L_808001D8
    if (ctx->r1 != 0) {
        // 0x80800234: nop
    
            goto L_808001D8;
    }
    // 0x80800234: nop

    // 0x80800238: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8080023C:
    // 0x8080023C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800240: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800244: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800248: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8080024C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800250: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80800254: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80800258: jr          $ra
    // 0x8080025C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8080025C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void bswalk_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800688: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080068C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800690: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800694: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800698: jal         0x8008CABC
    // 0x8080069C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080069C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x808006A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808006A4: jal         0x8009E710
    // 0x808006A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_1;
    // 0x808006A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808006AC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808006B0: bnel        $v0, $at, L_808006D4
    if (ctx->r2 != ctx->r1) {
        // 0x808006B4: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_808006D4;
    }
    goto skip_0;
    // 0x808006B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_0:
    // 0x808006B8: jal         0x8008AEDC
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008AEDC(rdram, ctx);
        goto after_2;
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808006C0: jal         0x8008C0C8
    // 0x808006C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008C0C8(rdram, ctx);
        goto after_3;
    // 0x808006C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x808006C8: b           L_808006DC
    // 0x808006CC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
        goto L_808006DC;
    // 0x808006CC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x808006D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_808006D4:
    // 0x808006D4: nop

    // 0x808006D8: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
L_808006DC:
    // 0x808006DC: jal         0x8008AF24
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_4;
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808006E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E8: jal         0x8008AED4
    // 0x808006EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setIndex(rdram, ctx);
        goto after_5;
    // 0x808006EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x808006F0: lui         $a1, 0x3EDC
    ctx->r5 = S32(0X3EDC << 16);
    // 0x808006F4: ori         $a1, $a1, 0x28F6
    ctx->r5 = ctx->r5 | 0X28F6;
    // 0x808006F8: jal         0x8008B1BC
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_6;
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800704: jal         0x8008B24C
    // 0x80800708: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    anctrl_setStart(rdram, ctx);
        goto after_7;
    // 0x80800708: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x8080070C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800710: jal         0x8008B134
    // 0x80800714: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_8;
    // 0x80800714: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x80800718: jal         0x8008B064
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_9;
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800720: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800724: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800728: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080072C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800730: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800734: jal         0x8009FFD8
    // 0x80800738: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_10;
    // 0x80800738: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x8080073C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800740: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800744: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800748: jal         0x8008C9BC
    // 0x8080074C: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_11;
    // 0x8080074C: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_11:
    // 0x80800750: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(435, 0X14FC) << 16);
    // 0x80800754: lwc1        $f6, 0x14FC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(435, 0X14FC));
    // 0x80800758: lui         $a3, 0x3FA6
    ctx->r7 = S32(0X3FA6 << 16);
    // 0x8080075C: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800760: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800764: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x80800768: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    // 0x8080076C: jal         0x8008C9F0
    // 0x80800770: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_12;
    // 0x80800770: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_12:
    // 0x80800774: jal         0x8009F1E0
    // 0x80800778: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_resetZones(rdram, ctx);
        goto after_13;
    // 0x80800778: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x8080077C: jal         0x8008E0E8
    // 0x80800780: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8008E0E8(rdram, ctx);
        goto after_14;
    // 0x80800780: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x80800784: beq         $v0, $zero, L_80800794
    if (ctx->r2 == 0) {
        // 0x80800788: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800794;
    }
    // 0x80800788: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080078C: jal         0x80084788
    // 0x80800790: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _bapackctrl_entrypoint_5(rdram, ctx);
        goto after_15;
    // 0x80800790: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_15:
L_80800794:
    // 0x80800794: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800798: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080079C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808007A0: jr          $ra
    // 0x808007A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808007A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void chmrsicecube_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1204, 0X9E4) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x9E4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1204, 0X9E4));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x9E4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1204, 0X9E4));
;}
RECOMP_FUNC void func_80800B70_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800B74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B78: jal         0x80800234
    // 0x80800B7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bssnowball_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800B7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800B80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800B84: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800B88: jal         0x80085128
    // 0x80800B8C: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    _basnowball_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80800B8C: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    after_1:
    // 0x80800B90: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x80800B94: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800B98: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800B9C: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    // 0x80800BA0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80800BA4: jal         0x80085150
    // 0x80800BA8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _baspin_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800BA8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80800BAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800BB4: jr          $ra
    // 0x80800BB8: nop

    return;
    // 0x80800BB8: nop

;}
RECOMP_FUNC void func_800D4534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4534: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D4538: bne         $a1, $zero, L_800D4548
    if (ctx->r5 != 0) {
        // 0x800D453C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800D4548;
    }
    // 0x800D453C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D4540: b           L_800D4554
    // 0x800D4544: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D4554;
    // 0x800D4544: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D4548:
    // 0x800D4548: jal         0x800AAD28
    // 0x800D454C: nop

    func_800AAD28(rdram, ctx);
        goto after_0;
    // 0x800D454C: nop

    after_0:
    // 0x800D4550: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D4554:
    // 0x800D4554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D4558: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D455C: jr          $ra
    // 0x800D4560: nop

    return;
    // 0x800D4560: nop

;}
RECOMP_FUNC void _suexpression_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800897B8: syscall     795
    recomp_syscall_handler(rdram, ctx, 0x800897B8);
    return;
    // 0x800897BC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800000_chbobpanel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x80103EF4
    // 0x8080000C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80103EF4(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80800014: jal         0x80103EAC
    // 0x80800018: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80103EAC(rdram, ctx);
        goto after_1;
    // 0x80800018: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8080001C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800020: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800024: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x80800028: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080002C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800030: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800034: jal         0x80089F20
    // 0x80800038: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800038: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_2:
    // 0x8080003C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800040: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800044: jr          $ra
    // 0x80800048: nop

    return;
    // 0x80800048: nop

;}
RECOMP_FUNC void _choildrill_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087710: syscall     611
    recomp_syscall_handler(rdram, ctx, 0x80087710);
    return;
    // 0x80087714: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void susubgame_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808005F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808005F4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808005F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800600: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
L_80800604:
    // 0x80800604: jal         0x808008DC
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008DC_susubgame(rdram, ctx);
        goto after_0;
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8080060C: beql        $v0, $zero, L_80800630
    if (ctx->r2 == 0) {
        // 0x80800610: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800630;
    }
    goto skip_0;
    // 0x80800610: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80800614: jal         0x800F6F00
    // 0x80800618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6F00(rdram, ctx);
        goto after_1;
    // 0x80800618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080061C: bnel        $v0, $zero, L_80800630
    if (ctx->r2 != 0) {
        // 0x80800620: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800630;
    }
    goto skip_1;
    // 0x80800620: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80800624: b           L_8080063C
    // 0x80800628: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080063C;
    // 0x80800628: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080062C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80800630:
    // 0x80800630: bne         $s0, $s1, L_80800604
    if (ctx->r16 != ctx->r17) {
        // 0x80800634: nop
    
            goto L_80800604;
    }
    // 0x80800634: nop

    // 0x80800638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080063C:
    // 0x8080063C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800640: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800644: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800648: jr          $ra
    // 0x8080064C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8080064C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800CBC3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBC3C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CBC40: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800CBC44: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800CBC48: addiu       $s4, $s4, -0x5180
    ctx->r20 = ADD32(ctx->r20, -0X5180);
    // 0x800CBC4C: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x800CBC50: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800CBC54: addiu       $s5, $zero, 0x1C
    ctx->r21 = ADD32(0, 0X1C);
    // 0x800CBC58: multu       $t6, $s5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CBC5C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800CBC60: lw          $s3, 0x4($s4)
    ctx->r19 = MEM_W(ctx->r20, 0X4);
    // 0x800CBC64: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CBC68: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800CBC6C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800CBC70: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800CBC74: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CBC78: mflo        $t7
    ctx->r15 = lo;
    // 0x800CBC7C: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x800CBC80: sltu        $at, $s3, $t8
    ctx->r1 = ctx->r19 < ctx->r24 ? 1 : 0;
    // 0x800CBC84: beql        $at, $zero, L_800CBD60
    if (ctx->r1 == 0) {
        // 0x800CBC88: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800CBD60;
    }
    goto skip_0;
    // 0x800CBC88: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_0:
L_800CBC8C:
    // 0x800CBC8C: jal         0x800CB910
    // 0x800CBC90: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800CB910(rdram, ctx);
        goto after_0;
    // 0x800CBC90: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x800CBC94: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800CBC98: jal         0x800CB8F0
    // 0x800CBC9C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800CB8F0(rdram, ctx);
        goto after_1;
    // 0x800CBC9C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x800CBCA0: sltu        $at, $v0, $s2
    ctx->r1 = ctx->r2 < ctx->r18 ? 1 : 0;
    // 0x800CBCA4: beq         $at, $zero, L_800CBD38
    if (ctx->r1 == 0) {
        // 0x800CBCA8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800CBD38;
    }
    // 0x800CBCA8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800CBCAC: lh          $t9, 0xE($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE);
L_800CBCB0:
    // 0x800CBCB0: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800CBCB4: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800CBCB8: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800CBCBC: nop

    // 0x800CBCC0: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CBCC4: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800CBCC8: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x800CBCCC: nop

    // 0x800CBCD0: bc1fl       L_800CBD2C
    if (!c1cs) {
        // 0x800CBCD4: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CBD2C;
    }
    goto skip_1;
    // 0x800CBCD4: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_1:
    // 0x800CBCD8: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800CBCDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CBCE0: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x800CBCE4: nop

    // 0x800CBCE8: bc1fl       L_800CBD2C
    if (!c1cs) {
        // 0x800CBCEC: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CBD2C;
    }
    goto skip_2;
    // 0x800CBCEC: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_2:
    // 0x800CBCF0: jal         0x800EFC7C
    // 0x800CBCF4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_2;
    // 0x800CBCF4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x800CBCF8: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800CBCFC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800CBD00: nop

    // 0x800CBD04: bc1fl       L_800CBD2C
    if (!c1cs) {
        // 0x800CBD08: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CBD2C;
    }
    goto skip_3;
    // 0x800CBD08: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_3:
    // 0x800CBD0C: lw          $t0, 0x4($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X4);
    // 0x800CBD10: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x800CBD14: subu        $v0, $s3, $t0
    ctx->r2 = SUB32(ctx->r19, ctx->r8);
    // 0x800CBD18: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800CBD1C: mflo        $v0
    ctx->r2 = lo;
    // 0x800CBD20: b           L_800CBD64
    // 0x800CBD24: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800CBD64;
    // 0x800CBD24: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800CBD28: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
L_800CBD2C:
    // 0x800CBD2C: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x800CBD30: bnel        $at, $zero, L_800CBCB0
    if (ctx->r1 != 0) {
        // 0x800CBD34: lh          $t9, 0xE($s0)
        ctx->r25 = MEM_H(ctx->r16, 0XE);
            goto L_800CBCB0;
    }
    goto skip_4;
    // 0x800CBD34: lh          $t9, 0xE($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE);
    skip_4:
L_800CBD38:
    // 0x800CBD38: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x800CBD3C: lw          $t4, 0x4($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X4);
    // 0x800CBD40: addiu       $s3, $s3, 0x1C
    ctx->r19 = ADD32(ctx->r19, 0X1C);
    // 0x800CBD44: multu       $t2, $s5
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CBD48: mflo        $t3
    ctx->r11 = lo;
    // 0x800CBD4C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800CBD50: sltu        $at, $s3, $t5
    ctx->r1 = ctx->r19 < ctx->r13 ? 1 : 0;
    // 0x800CBD54: bne         $at, $zero, L_800CBC8C
    if (ctx->r1 != 0) {
        // 0x800CBD58: nop
    
            goto L_800CBC8C;
    }
    // 0x800CBD58: nop

    // 0x800CBD5C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800CBD60:
    // 0x800CBD60: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800CBD64:
    // 0x800CBD64: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800CBD68: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800CBD6C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800CBD70: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800CBD74: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800CBD78: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800CBD7C: jr          $ra
    // 0x800CBD80: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800CBD80: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8080150C_chfactorybattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080150C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801510: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801514: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801518: jal         0x800EA05C
    // 0x8080151C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x8080151C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801520: addiu       $at, $zero, 0x101
    ctx->r1 = ADD32(0, 0X101);
    // 0x80801524: beq         $v0, $at, L_80801550
    if (ctx->r2 == ctx->r1) {
        // 0x80801528: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801550;
    }
    // 0x80801528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080152C: addiu       $at, $zero, 0x106
    ctx->r1 = ADD32(0, 0X106);
    // 0x80801530: beq         $v0, $at, L_80801594
    if (ctx->r2 == ctx->r1) {
        // 0x80801534: addiu       $at, $zero, 0x109
        ctx->r1 = ADD32(0, 0X109);
            goto L_80801594;
    }
    // 0x80801534: addiu       $at, $zero, 0x109
    ctx->r1 = ADD32(0, 0X109);
    // 0x80801538: beq         $v0, $at, L_808015F4
    if (ctx->r2 == ctx->r1) {
        // 0x8080153C: addiu       $at, $zero, 0x10B
        ctx->r1 = ADD32(0, 0X10B);
            goto L_808015F4;
    }
    // 0x8080153C: addiu       $at, $zero, 0x10B
    ctx->r1 = ADD32(0, 0X10B);
    // 0x80801540: beq         $v0, $at, L_80801654
    if (ctx->r2 == ctx->r1) {
        // 0x80801544: nop
    
            goto L_80801654;
    }
    // 0x80801544: nop

    // 0x80801548: b           L_808016B0
    // 0x8080154C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808016B0;
    // 0x8080154C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801550:
    // 0x80801550: addiu       $a1, $zero, 0x87F
    ctx->r5 = ADD32(0, 0X87F);
    // 0x80801554: jal         0x80103140
    // 0x80801558: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80103140(rdram, ctx);
        goto after_1;
    // 0x80801558: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8080155C: jal         0x80800480
    // 0x80801560: nop

    func_80800480_chfactorybattery(rdram, ctx);
        goto after_2;
    // 0x80801560: nop

    after_2:
    // 0x80801564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801568: lui         $a1, 0xC2B4
    ctx->r5 = S32(0XC2B4 << 16);
    // 0x8080156C: addiu       $a2, $zero, 0x4C
    ctx->r6 = ADD32(0, 0X4C);
    // 0x80801570: jal         0x80086888
    // 0x80801574: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    _chdoormake_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80801574: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80801578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080157C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801580: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80801584: jal         0x800868C8
    // 0x80801588: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _chdoormake_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x80801588: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_4:
    // 0x8080158C: b           L_808016B0
    // 0x80801590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808016B0;
    // 0x80801590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801594:
    // 0x80801594: jal         0x80103EF4
    // 0x80801598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_5;
    // 0x80801598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080159C: jal         0x80800480
    // 0x808015A0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_80800480_chfactorybattery(rdram, ctx);
        goto after_6;
    // 0x808015A0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x808015A4: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808015A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808015AC: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808015B0: addiu       $t6, $zero, 0x44
    ctx->r14 = ADD32(0, 0X44);
    // 0x808015B4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808015B8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808015BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015C0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808015C4: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x808015C8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x808015CC: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x808015D0: jal         0x80086898
    // 0x808015D4: nop

    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x808015D4: nop

    after_7:
    // 0x808015D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808015E0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808015E4: jal         0x800868C8
    // 0x808015E8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _chdoormake_entrypoint_9(rdram, ctx);
        goto after_8;
    // 0x808015E8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_8:
    // 0x808015EC: b           L_808016B0
    // 0x808015F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808016B0;
    // 0x808015F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808015F4:
    // 0x808015F4: jal         0x80103EF4
    // 0x808015F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_9;
    // 0x808015F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808015FC: jal         0x80800480
    // 0x80801600: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_80800480_chfactorybattery(rdram, ctx);
        goto after_10;
    // 0x80801600: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x80801604: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80801608: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080160C: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80801610: addiu       $t7, $zero, 0x44
    ctx->r15 = ADD32(0, 0X44);
    // 0x80801614: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801618: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8080161C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801620: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80801624: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x80801628: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8080162C: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80801630: jal         0x80086898
    // 0x80801634: nop

    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x80801634: nop

    after_11:
    // 0x80801638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080163C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801640: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801644: jal         0x800868C8
    // 0x80801648: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _chdoormake_entrypoint_9(rdram, ctx);
        goto after_12;
    // 0x80801648: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_12:
    // 0x8080164C: b           L_808016B0
    // 0x80801650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808016B0;
    // 0x80801650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801654:
    // 0x80801654: jal         0x80103EF4
    // 0x80801658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_13;
    // 0x80801658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8080165C: jal         0x80800480
    // 0x80801660: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_80800480_chfactorybattery(rdram, ctx);
        goto after_14;
    // 0x80801660: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_14:
    // 0x80801664: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80801668: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080166C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80801670: addiu       $t8, $zero, 0x44
    ctx->r24 = ADD32(0, 0X44);
    // 0x80801674: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801678: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080167C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801680: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80801684: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x80801688: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8080168C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80801690: jal         0x80086898
    // 0x80801694: nop

    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_15;
    // 0x80801694: nop

    after_15:
    // 0x80801698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080169C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808016A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808016A4: jal         0x800868C8
    // 0x808016A8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _chdoormake_entrypoint_9(rdram, ctx);
        goto after_16;
    // 0x808016A8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_16:
    // 0x808016AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808016B0:
    // 0x808016B0: jal         0x800868C0
    // 0x808016B4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_17;
    // 0x808016B4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_17:
    // 0x808016B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016BC: jal         0x800868A8
    // 0x808016C0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_18;
    // 0x808016C0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_18:
    // 0x808016C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016C8: jal         0x800868B0
    // 0x808016CC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_19;
    // 0x808016CC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_19:
    // 0x808016D0: jal         0x80800480
    // 0x808016D4: nop

    func_80800480_chfactorybattery(rdram, ctx);
        goto after_20;
    // 0x808016D4: nop

    after_20:
    // 0x808016D8: jal         0x800DA298
    // 0x808016DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA298(rdram, ctx);
        goto after_21;
    // 0x808016DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_21:
    // 0x808016E0: beql        $v0, $zero, L_80801718
    if (ctx->r2 == 0) {
        // 0x808016E4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801718;
    }
    goto skip_0;
    // 0x808016E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808016E8: lbu         $t0, 0x74($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X74);
    // 0x808016EC: ori         $t7, $t0, 0x40
    ctx->r15 = ctx->r8 | 0X40;
    // 0x808016F0: sb          $t7, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r15;
    // 0x808016F4: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x808016F8: andi        $t8, $t7, 0xDF
    ctx->r24 = ctx->r15 & 0XDF;
    // 0x808016FC: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80801700: srl         $t4, $t3, 31
    ctx->r12 = S32(U32(ctx->r11) >> 31);
    // 0x80801704: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x80801708: andi        $t6, $t5, 0x20
    ctx->r14 = ctx->r13 & 0X20;
    // 0x8080170C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80801710: sb          $t9, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r25;
    // 0x80801714: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801718:
    // 0x80801718: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080171C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801720: jr          $ra
    // 0x80801724: nop

    return;
    // 0x80801724: nop

;}
RECOMP_FUNC void _bawobble_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085440: syscall     162
    recomp_syscall_handler(rdram, ctx, 0x80085440);
    return;
    // 0x80085444: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void _chdoormake_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800868C8: syscall     393
    recomp_syscall_handler(rdram, ctx, 0x800868C8);
    return;
    // 0x800868CC: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_800D5298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5298: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D529C: jr          $ra
    // 0x800D52A0: lbu         $v0, -0x4BCF($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4BCF);
    return;
    // 0x800D52A0: lbu         $v0, -0x4BCF($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4BCF);
;}
RECOMP_FUNC void basub_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005C0: jal         0x800F53D0
    // 0x808005C4: nop

    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x808005C4: nop

    after_0:
    // 0x808005C8: jal         0x800872A0
    // 0x808005CC: lw          $a0, 0x184($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X184);
    _chping_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808005CC: lw          $a0, 0x184($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X184);
    after_1:
    // 0x808005D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005D8: jr          $ra
    // 0x808005DC: nop

    return;
    // 0x808005DC: nop

;}
RECOMP_FUNC void func_800138BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800138BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800138C0: lwc1        $f14, 0x16DC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X16DC);
    // 0x800138C4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800138C8: b           L_800138E4
    // 0x800138CC: lwc1        $f16, 0x16E0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X16E0);
        goto L_800138E4;
    // 0x800138CC: lwc1        $f16, 0x16E0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X16E0);
    // 0x800138D0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800138D4: lwc1        $f14, 0x16E4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X16E4);
    // 0x800138D8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800138DC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800138E0: nop

L_800138E4:
    // 0x800138E4: mul.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800138E8: lui         $at, 0x4B00
    ctx->r1 = S32(0X4B00 << 16);
    // 0x800138EC: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x800138F0: addiu       $t1, $t1, -0x2C60
    ctx->r9 = ADD32(ctx->r9, -0X2C60);
    // 0x800138F4: trunc.w.s   $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800138F8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800138FC: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80013900: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80013904: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80013908: mul.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8001390C: nop

    // 0x80013910: mul.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80013914: round.w.s   $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = lroundf(ctx->f4.fl);
    // 0x80013918: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x8001391C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80013920: lwc1        $f6, 0x16E8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X16E8);
    // 0x80013924: andi        $t2, $a0, 0xFFF
    ctx->r10 = ctx->r4 & 0XFFF;
    // 0x80013928: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8001392C: srl         $t0, $a0, 10
    ctx->r8 = S32(U32(ctx->r4) >> 10);
    // 0x80013930: addiu       $t0, $t0, 0x800
    ctx->r8 = ADD32(ctx->r8, 0X800);
    // 0x80013934: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80013938: andi        $t0, $t0, 0x1FFC
    ctx->r8 = ctx->r8 & 0X1FFC;
    // 0x8001393C: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x80013940: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80013944: lwc1        $f12, 0x4($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80013948: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001394C: sub.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80013950: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80013954: jr          $ra
    // 0x80013958: add.s       $f0, $f12, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f10.fl;
    return;
    // 0x80013958: add.s       $f0, $f12, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f10.fl;
;}
RECOMP_FUNC void ncbakaztorp_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800070: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80800074: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800078: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080007C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800080: jal         0x80112524
    // 0x80800084: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    func_80112524(rdram, ctx);
        goto after_0;
    // 0x80800084: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    after_0:
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080008C: jal         0x801107F0
    // 0x80800090: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_801107F0(rdram, ctx);
        goto after_1;
    // 0x80800090: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_1:
    // 0x80800094: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x80800098: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x8080009C: jal         0x800EFB24
    // 0x808000A0: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x808000A0: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    after_2:
    // 0x808000A4: jal         0x800EEF94
    // 0x808000A8: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    func_800EEF94(rdram, ctx);
        goto after_3;
    // 0x808000A8: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    after_3:
    // 0x808000AC: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x808000B0: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x808000B4: jal         0x800F1A88
    // 0x808000B8: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800F1A88(rdram, ctx);
        goto after_4;
    // 0x808000B8: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_4:
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000C4: jal         0x80113978
    // 0x808000C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80113978(rdram, ctx);
        goto after_5;
    // 0x808000C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D0: jal         0x80115358
    // 0x808000D4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_80115358(rdram, ctx);
        goto after_6;
    // 0x808000D4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_6:
    // 0x808000D8: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x808000DC: jal         0x80110840
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80110840(rdram, ctx);
        goto after_7;
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808000E4: jal         0x800F53D0
    // 0x808000E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F53D0(rdram, ctx);
        goto after_8;
    // 0x808000E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x808000EC: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F4: jal         0x80110818
    // 0x808000F8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_80110818(rdram, ctx);
        goto after_9;
    // 0x808000F8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_9:
    // 0x808000FC: jal         0x80084F00
    // 0x80800100: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    _bamovethrust_entrypoint_6(rdram, ctx);
        goto after_10;
    // 0x80800100: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_10:
    // 0x80800104: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80800108: jal         0x8009BFCC
    // 0x8080010C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_8009BFCC(rdram, ctx);
        goto after_11;
    // 0x8080010C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_11:
    // 0x80800110: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800114: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800118: jal         0x800F1DCC
    // 0x8080011C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F1DCC(rdram, ctx);
        goto after_12;
    // 0x8080011C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_12:
    // 0x80800120: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800124: jal         0x8009C984
    // 0x80800128: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    yaw_get(rdram, ctx);
        goto after_13;
    // 0x80800128: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x8080012C: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800130: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800134: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800138: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8080013C: jal         0x80013728
    // 0x80800140: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    func_80013728(rdram, ctx);
        goto after_14;
    // 0x80800140: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_14:
    // 0x80800144: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800148: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080014C: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800150: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800154: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80800158: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8080015C: sub.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80800160: bc1f        L_80800174
    if (!c1cs) {
        // 0x80800164: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80800174;
    }
    // 0x80800164: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800168: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080016C: b           L_8080019C
    // 0x80800170: sub.s       $f14, $f16, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f0.fl;
        goto L_8080019C;
    // 0x80800170: sub.s       $f14, $f16, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f0.fl;
L_80800174:
    // 0x80800174: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80800178: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080017C: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x80800180: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80800184: nop

    // 0x80800188: bc1f        L_8080019C
    if (!c1cs) {
        // 0x8080018C: nop
    
            goto L_8080019C;
    }
    // 0x8080018C: nop

    // 0x80800190: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800194: nop

    // 0x80800198: sub.s       $f14, $f4, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f0.fl;
L_8080019C:
    // 0x8080019C: jal         0x80013728
    // 0x808001A0: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    func_80013728(rdram, ctx);
        goto after_15;
    // 0x808001A0: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    after_15:
    // 0x808001A4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808001A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001AC: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808001B0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808001B4: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x808001B8: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x808001BC: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808001C0: bc1fl       L_808001DC
    if (!c1cs) {
        // 0x808001C4: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_808001DC;
    }
    goto skip_0;
    // 0x808001C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_0:
    // 0x808001C8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808001CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808001D0: b           L_808001FC
    // 0x808001D4: sub.s       $f2, $f10, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f0.fl;
        goto L_808001FC;
    // 0x808001D4: sub.s       $f2, $f10, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x808001D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_808001DC:
    // 0x808001DC: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x808001E0: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x808001E4: nop

    // 0x808001E8: bc1fl       L_80800200
    if (!c1cs) {
        // 0x808001EC: lui         $at, 0x4361
        ctx->r1 = S32(0X4361 << 16);
            goto L_80800200;
    }
    goto skip_1;
    // 0x808001EC: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    skip_1:
    // 0x808001F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808001F4: nop

    // 0x808001F8: sub.s       $f2, $f18, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f0.fl;
L_808001FC:
    // 0x808001FC: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
L_80800200:
    // 0x80800200: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800204: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3122, 0X2D0) << 16);
    // 0x80800208: lwc1        $f10, 0x2D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3122, 0X2D0));
    // 0x8080020C: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800210: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800214: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800220: nop

    // 0x80800224: mul.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80800228: nop

    // 0x8080022C: mul.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80800230: sub.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x80800234: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80800238: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8080023C: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    // 0x80800240: jal         0x80115750
    // 0x80800244: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    func_80115750(rdram, ctx);
        goto after_16;
    // 0x80800244: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    after_16:
    // 0x80800248: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800250: jal         0x80112C3C
    // 0x80800254: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    func_80112C3C(rdram, ctx);
        goto after_17;
    // 0x80800254: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_17:
    // 0x80800258: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8080025C: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x80800260: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80800264: jal         0x800EEBF0
    // 0x80800268: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    func_800EEBF0(rdram, ctx);
        goto after_18;
    // 0x80800268: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    after_18:
    // 0x8080026C: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x80800270: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x80800274: jal         0x800EE780
    // 0x80800278: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    func_800EE780(rdram, ctx);
        goto after_19;
    // 0x80800278: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    after_19:
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800280: jal         0x80111FD4
    // 0x80800284: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_80111FD4(rdram, ctx);
        goto after_20;
    // 0x80800284: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_20:
    // 0x80800288: beql        $v0, $zero, L_8080029C
    if (ctx->r2 == 0) {
        // 0x8080028C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080029C;
    }
    goto skip_2;
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800290: jal         0x801138F4
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138F4(rdram, ctx);
        goto after_21;
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080029C:
    // 0x8080029C: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x808002A0: jal         0x80110A68
    // 0x808002A4: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    func_80110A68(rdram, ctx);
        goto after_22;
    // 0x808002A4: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    after_22:
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002AC: jal         0x80110790
    // 0x808002B0: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_80110790(rdram, ctx);
        goto after_23;
    // 0x808002B0: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_23:
    // 0x808002B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002BC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x808002C0: jr          $ra
    // 0x808002C4: nop

    return;
    // 0x808002C4: nop

    // 0x808002C8: nop

    // 0x808002CC: nop

;}
RECOMP_FUNC void func_800EADFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EADFC: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x800EAE00: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800EAE04: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800EAE08: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800EAE0C: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x800EAE10: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x800EAE14: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800EAE18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800EAE1C: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x800EAE20: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x800EAE24: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x800EAE28: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800EAE2C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800EAE30: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800EAE34: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800EAE38: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // 0x800EAE3C: jal         0x800E9E88
    // 0x800EAE40: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    func_800E9E88(rdram, ctx);
        goto after_0;
    // 0x800EAE40: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    after_0:
    // 0x800EAE44: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x800EAE48: jal         0x800E9EB4
    // 0x800EAE4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E9EB4(rdram, ctx);
        goto after_1;
    // 0x800EAE4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800EAE50: sltu        $at, $s4, $v0
    ctx->r1 = ctx->r20 < ctx->r2 ? 1 : 0;
    // 0x800EAE54: beq         $at, $zero, L_800EB124
    if (ctx->r1 == 0) {
        // 0x800EAE58: sw          $v0, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->r2;
            goto L_800EB124;
    }
    // 0x800EAE58: sw          $v0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r2;
    // 0x800EAE5C: lw          $s7, 0xC0($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XC0);
    // 0x800EAE60: lw          $v0, 0x8($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X8);
L_800EAE64:
    // 0x800EAE64: sll         $t7, $v0, 27
    ctx->r15 = S32(ctx->r2 << 27);
    // 0x800EAE68: bgez        $t7, L_800EB110
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800EAE6C: andi        $t8, $v0, 0x1
        ctx->r24 = ctx->r2 & 0X1;
            goto L_800EB110;
    }
    // 0x800EAE6C: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x800EAE70: bne         $t8, $zero, L_800EAFAC
    if (ctx->r24 != 0) {
        // 0x800EAE74: sll         $t9, $v0, 28
        ctx->r25 = S32(ctx->r2 << 28);
            goto L_800EAFAC;
    }
    // 0x800EAE74: sll         $t9, $v0, 28
    ctx->r25 = S32(ctx->r2 << 28);
    // 0x800EAE78: sll         $t0, $v0, 30
    ctx->r8 = S32(ctx->r2 << 30);
    // 0x800EAE7C: bgezl       $t0, L_800EB114
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800EAE80: lw          $t8, 0xA0($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XA0);
            goto L_800EB114;
    }
    goto skip_0;
    // 0x800EAE80: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    skip_0:
    // 0x800EAE84: jal         0x80088C88
    // 0x800EAE88: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    _gsproplookup_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x800EAE88: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_2:
    // 0x800EAE8C: jal         0x800BFC54
    // 0x800EAE90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800BFC54(rdram, ctx);
        goto after_3;
    // 0x800EAE90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x800EAE94: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800EAE98: jal         0x800B2720
    // 0x800EAE9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B2720(rdram, ctx);
        goto after_4;
    // 0x800EAE9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x800EAEA0: beq         $v0, $zero, L_800EB110
    if (ctx->r2 == 0) {
        // 0x800EAEA4: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800EB110;
    }
    // 0x800EAEA4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800EAEA8: lh          $t1, 0x4($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X4);
    // 0x800EAEAC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800EAEB0: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800EAEB4: nop

    // 0x800EAEB8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800EAEBC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800EAEC0: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x800EAEC4: lh          $t2, 0x6($s4)
    ctx->r10 = MEM_H(ctx->r20, 0X6);
    // 0x800EAEC8: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800EAECC: nop

    // 0x800EAED0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800EAED4: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    // 0x800EAED8: lh          $t3, 0x8($s4)
    ctx->r11 = MEM_H(ctx->r20, 0X8);
    // 0x800EAEDC: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x800EAEE0: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800EAEE4: nop

    // 0x800EAEE8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800EAEEC: swc1        $f18, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f18.u32l;
    // 0x800EAEF0: lbu         $t4, 0x2($s4)
    ctx->r12 = MEM_BU(ctx->r20, 0X2);
    // 0x800EAEF4: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x800EAEF8: bgez        $t4, L_800EAF0C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800EAEFC: cvt.s.w     $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800EAF0C;
    }
    // 0x800EAEFC: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800EAF00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800EAF04: nop

    // 0x800EAF08: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
L_800EAF0C:
    // 0x800EAF0C: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800EAF10: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800EAF14: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    // 0x800EAF18: lbu         $t5, 0x3($s4)
    ctx->r13 = MEM_BU(ctx->r20, 0X3);
    // 0x800EAF1C: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x800EAF20: bgez        $t5, L_800EAF34
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800EAF24: cvt.s.w     $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800EAF34;
    }
    // 0x800EAF24: cvt.s.w     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800EAF28: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800EAF2C: nop

    // 0x800EAF30: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
L_800EAF34:
    // 0x800EAF34: add.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800EAF38: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800EAF3C: jal         0x800B2840
    // 0x800EAF40: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    func_800B2840(rdram, ctx);
        goto after_5;
    // 0x800EAF40: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x800EAF44: lbu         $t6, 0xA($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0XA);
    // 0x800EAF48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800EAF4C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800EAF50: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800EAF54: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    // 0x800EAF58: addiu       $a3, $sp, 0x7C
    ctx->r7 = ADD32(ctx->r29, 0X7C);
    // 0x800EAF5C: bgez        $t6, L_800EAF74
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800EAF60: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800EAF74;
    }
    // 0x800EAF60: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800EAF64: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800EAF68: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800EAF6C: nop

    // 0x800EAF70: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800EAF74:
    // 0x800EAF74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800EAF78: lwc1        $f16, 0x5E58($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5E58);
    // 0x800EAF7C: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x800EAF80: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x800EAF84: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800EAF88: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x800EAF8C: sw          $s7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r23;
    // 0x800EAF90: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800EAF94: jal         0x800AD1AC
    // 0x800EAF98: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800AD1AC(rdram, ctx);
        goto after_6;
    // 0x800EAF98: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_6:
    // 0x800EAF9C: beql        $v0, $zero, L_800EB114
    if (ctx->r2 == 0) {
        // 0x800EAFA0: lw          $t8, 0xA0($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XA0);
            goto L_800EB114;
    }
    goto skip_1;
    // 0x800EAFA0: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    skip_1:
    // 0x800EAFA4: b           L_800EB110
    // 0x800EAFA8: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
        goto L_800EB110;
    // 0x800EAFA8: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
L_800EAFAC:
    // 0x800EAFAC: bgez        $t9, L_800EB110
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800EAFB0: lw          $s3, 0x0($s4)
        ctx->r19 = MEM_W(ctx->r20, 0X0);
            goto L_800EB110;
    }
    // 0x800EAFB0: lw          $s3, 0x0($s4)
    ctx->r19 = MEM_W(ctx->r20, 0X0);
    // 0x800EAFB4: lhu         $t0, 0x18($s3)
    ctx->r8 = MEM_HU(ctx->r19, 0X18);
    // 0x800EAFB8: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x800EAFBC: beql        $t1, $zero, L_800EB114
    if (ctx->r9 == 0) {
        // 0x800EAFC0: lw          $t8, 0xA0($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XA0);
            goto L_800EB114;
    }
    goto skip_2;
    // 0x800EAFC0: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    skip_2:
    // 0x800EAFC4: jal         0x80106790
    // 0x800EAFC8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80106790(rdram, ctx);
        goto after_7;
    // 0x800EAFC8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x800EAFCC: lw          $t2, 0x64($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X64);
    // 0x800EAFD0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800EAFD4: sll         $t4, $t2, 14
    ctx->r12 = S32(ctx->r10 << 14);
    // 0x800EAFD8: bltzl       $t4, L_800EB114
    if (SIGNED(ctx->r12) < 0) {
        // 0x800EAFDC: lw          $t8, 0xA0($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XA0);
            goto L_800EB114;
    }
    goto skip_3;
    // 0x800EAFDC: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    skip_3:
    // 0x800EAFE0: lw          $v0, 0xC($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XC);
    // 0x800EAFE4: beq         $v0, $zero, L_800EB02C
    if (ctx->r2 == 0) {
        // 0x800EAFE8: nop
    
            goto L_800EB02C;
    }
    // 0x800EAFE8: nop

    // 0x800EAFEC: jalr        $v0
    // 0x800EAFF0: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_8;
    // 0x800EAFF0: nop

    after_8:
    // 0x800EAFF4: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x800EAFF8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800EAFFC: beq         $t5, $zero, L_800EB02C
    if (ctx->r13 == 0) {
        // 0x800EB000: nop
    
            goto L_800EB02C;
    }
    // 0x800EB000: nop

    // 0x800EB004: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // 0x800EB008: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x800EB00C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800EB010: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800EB014: jalr        $t9
    // 0x800EB018: lw          $a3, 0xBC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XBC);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x800EB018: lw          $a3, 0xBC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XBC);
    after_9:
    // 0x800EB01C: beql        $v0, $zero, L_800EB114
    if (ctx->r2 == 0) {
        // 0x800EB020: lw          $t8, 0xA0($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XA0);
            goto L_800EB114;
    }
    goto skip_4;
    // 0x800EB020: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    skip_4:
    // 0x800EB024: b           L_800EB110
    // 0x800EB028: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
        goto L_800EB110;
    // 0x800EB028: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
L_800EB02C:
    // 0x800EB02C: jal         0x80103328
    // 0x800EB030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103328(rdram, ctx);
        goto after_10;
    // 0x800EB030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x800EB034: addiu       $s5, $s0, 0x4
    ctx->r21 = ADD32(ctx->r16, 0X4);
    // 0x800EB038: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800EB03C: jal         0x800EEAD4
    // 0x800EB040: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800EEAD4(rdram, ctx);
        goto after_11;
    // 0x800EB040: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_11:
    // 0x800EB044: lhu         $t6, 0x6A($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X6A);
    // 0x800EB048: sub.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800EB04C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800EB050: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800EB054: bgez        $t6, L_800EB068
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800EB058: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800EB068;
    }
    // 0x800EB058: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800EB05C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800EB060: nop

    // 0x800EB064: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_800EB068:
    // 0x800EB068: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800EB06C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800EB070: c.le.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl <= ctx->f4.fl;
    // 0x800EB074: nop

    // 0x800EB078: bc1tl       L_800EB114
    if (c1cs) {
        // 0x800EB07C: lw          $t8, 0xA0($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XA0);
            goto L_800EB114;
    }
    goto skip_5;
    // 0x800EB07C: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    skip_5:
    // 0x800EB080: jal         0x800CB854
    // 0x800EB084: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CB854(rdram, ctx);
        goto after_12;
    // 0x800EB084: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x800EB088: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800EB08C: bne         $v0, $at, L_800EB09C
    if (ctx->r2 != ctx->r1) {
        // 0x800EB090: nop
    
            goto L_800EB09C;
    }
    // 0x800EB090: nop

    // 0x800EB094: jal         0x80103508
    // 0x800EB098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103508(rdram, ctx);
        goto after_13;
    // 0x800EB098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
L_800EB09C:
    // 0x800EB09C: jal         0x80103AA0
    // 0x800EB0A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80103AA0(rdram, ctx);
        goto after_14;
    // 0x800EB0A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_14:
    // 0x800EB0A4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800EB0A8: jal         0x800B2720
    // 0x800EB0AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B2720(rdram, ctx);
        goto after_15;
    // 0x800EB0AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_15:
    // 0x800EB0B0: beq         $v0, $zero, L_800EB100
    if (ctx->r2 == 0) {
        // 0x800EB0B4: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800EB100;
    }
    // 0x800EB0B4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800EB0B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EB0BC: jal         0x80103CDC
    // 0x800EB0C0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80103CDC(rdram, ctx);
        goto after_16;
    // 0x800EB0C0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_16:
    // 0x800EB0C4: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800EB0C8: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x800EB0CC: sw          $s7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r23;
    // 0x800EB0D0: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x800EB0D4: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x800EB0D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800EB0DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800EB0E0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800EB0E4: addiu       $a3, $s0, 0x44
    ctx->r7 = ADD32(ctx->r16, 0X44);
    // 0x800EB0E8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800EB0EC: jal         0x800AD1AC
    // 0x800EB0F0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_800AD1AC(rdram, ctx);
        goto after_17;
    // 0x800EB0F0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_17:
    // 0x800EB0F4: beq         $v0, $zero, L_800EB100
    if (ctx->r2 == 0) {
        // 0x800EB0F8: nop
    
            goto L_800EB100;
    }
    // 0x800EB0F8: nop

    // 0x800EB0FC: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
L_800EB100:
    // 0x800EB100: beql        $s2, $zero, L_800EB114
    if (ctx->r18 == 0) {
        // 0x800EB104: lw          $t8, 0xA0($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XA0);
            goto L_800EB114;
    }
    goto skip_6;
    // 0x800EB104: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    skip_6:
    // 0x800EB108: jal         0x800D62E4
    // 0x800EB10C: lhu         $a0, 0x14($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X14);
    func_800D62E4(rdram, ctx);
        goto after_18;
    // 0x800EB10C: lhu         $a0, 0x14($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X14);
    after_18:
L_800EB110:
    // 0x800EB110: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
L_800EB114:
    // 0x800EB114: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x800EB118: sltu        $at, $s4, $t8
    ctx->r1 = ctx->r20 < ctx->r24 ? 1 : 0;
    // 0x800EB11C: bnel        $at, $zero, L_800EAE64
    if (ctx->r1 != 0) {
        // 0x800EB120: lw          $v0, 0x8($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X8);
            goto L_800EAE64;
    }
    goto skip_7;
    // 0x800EB120: lw          $v0, 0x8($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X8);
    skip_7:
L_800EB124:
    // 0x800EB124: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800EB128: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
    // 0x800EB12C: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x800EB130: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800EB134: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800EB138: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800EB13C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800EB140: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800EB144: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800EB148: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800EB14C: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800EB150: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x800EB154: jr          $ra
    // 0x800EB158: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x800EB158: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void _chchuffyglow_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086D80: syscall     450
    recomp_syscall_handler(rdram, ctx, 0x80086D80);
    return;
    // 0x80086D84: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bafpctrl_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C98: syscall     133
    recomp_syscall_handler(rdram, ctx, 0x80084C98);
    return;
    // 0x80084C9C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _chpowerhutwitchy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086060: syscall     275
    recomp_syscall_handler(rdram, ctx, 0x80086060);
    return;
    // 0x80086064: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bsvan_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084120: syscall     105
    recomp_syscall_handler(rdram, ctx, 0x80084120);
    return;
    // 0x80084124: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _suegg_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A3D0: syscall     841
    recomp_syscall_handler(rdram, ctx, 0x8008A3D0);
    return;
    // 0x8008A3D4: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_8080000C_chballoonbomb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080001C: jal         0x80100094
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800024: jal         0x800F54E4
    // 0x80800028: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800028: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080002C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800030: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80800034: jal         0x8010D09C
    // 0x80800038: lw          $a2, 0x58($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X58);
    func_8010D09C(rdram, ctx);
        goto after_2;
    // 0x80800038: lw          $a2, 0x58($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X58);
    after_2:
    // 0x8080003C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800040: addiu       $v1, $sp, 0x38
    ctx->r3 = ADD32(ctx->r29, 0X38);
    // 0x80800044: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800048: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8080004C: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800050: beq         $v1, $a0, L_80800080
    if (ctx->r3 == ctx->r4) {
        // 0x80800054: lwc1        $f18, -0x4($v1)
        ctx->f18.u32l = MEM_W(ctx->r3, -0X4);
            goto L_80800080;
    }
    // 0x80800054: lwc1        $f18, -0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80800058: sub.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
L_8080005C:
    // 0x8080005C: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800060: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800064: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800068: div.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8080006C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800070: swc1        $f12, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f12.u32l;
    // 0x80800074: lwc1        $f18, -0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80800078: bnel        $v1, $a0, L_8080005C
    if (ctx->r3 != ctx->r4) {
        // 0x8080007C: sub.s       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
            goto L_8080005C;
    }
    goto skip_0;
    // 0x8080007C: sub.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
    skip_0:
L_80800080:
    // 0x80800080: sub.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80800084: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800088: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080008C: div.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80800090: swc1        $f12, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f12.u32l;
    // 0x80800094: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800098: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080009C: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808000A0: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808000A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808000A8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808000AC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808000B0: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x808000B4: jal         0x800DC298
    // 0x808000B8: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    func_800DC298(rdram, ctx);
        goto after_3;
    // 0x808000B8: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    after_3:
    // 0x808000BC: beq         $v0, $zero, L_808000D4
    if (ctx->r2 == 0) {
        // 0x808000C0: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_808000D4;
    }
    // 0x808000C0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808000C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808000C8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808000CC: b           L_808000E0
    // 0x808000D0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
        goto L_808000E0;
    // 0x808000D0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
L_808000D4:
    // 0x808000D4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808000D8: nop

    // 0x808000DC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
L_808000E0:
    // 0x808000E0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808000E4: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x808000E8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000EC: jal         0x800DC178
    // 0x808000F0: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x808000F0: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x808000F4: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808000F8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x808000FC: mul.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80800100: swc1        $f16, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f16.u32l;
    // 0x80800104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800108: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080010C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800110: jr          $ra
    // 0x80800114: nop

    return;
    // 0x80800114: nop

;}
RECOMP_FUNC void func_80800210_fxstep(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800210: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2830, 0X830) << 16);
    // 0x80800214: lh          $t6, 0x830($t6)
    ctx->r14 = MEM_H(ctx->r14, (int16_t)RELOC_LO16(2830, 0X830));
    // 0x80800218: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080021C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800220: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80800224: beq         $t6, $zero, L_808002A0
    if (ctx->r14 == 0) {
        // 0x80800228: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_808002A0;
    }
    // 0x80800228: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080022C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2830, 0X830) << 16);
    // 0x80800230: addiu       $v0, $t7, 0x830
    ctx->r2 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2830, 0X830));
    // 0x80800234: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
L_80800238:
    // 0x80800238: bnel        $a3, $v1, L_80800294
    if (ctx->r7 != ctx->r3) {
        // 0x8080023C: lh          $v1, 0x18($v0)
        ctx->r3 = MEM_H(ctx->r2, 0X18);
            goto L_80800294;
    }
    goto skip_0;
    // 0x8080023C: lh          $v1, 0x18($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X18);
    skip_0:
    // 0x80800240: lh          $t8, 0x14($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X14);
    // 0x80800244: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800248: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8080024C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80800250: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80800254: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80800258: lh          $a1, 0x2($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X2);
    // 0x8080025C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800260: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80800264: lh          $a2, 0x4($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X4);
    // 0x80800268: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8080026C: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80800270: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80800274: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80800278: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8080027C: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x80800280: jal         0x8080012C
    // 0x80800284: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    func_8080012C_fxstep(rdram, ctx);
        goto after_0;
    // 0x80800284: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_0:
    // 0x80800288: b           L_808002A4
    // 0x8080028C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002A4;
    // 0x8080028C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800290: lh          $v1, 0x18($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X18);
L_80800294:
    // 0x80800294: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x80800298: bne         $v1, $zero, L_80800238
    if (ctx->r3 != 0) {
        // 0x8080029C: nop
    
            goto L_80800238;
    }
    // 0x8080029C: nop

L_808002A0:
    // 0x808002A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002A4:
    // 0x808002A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808002A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808002AC: jr          $ra
    // 0x808002B0: nop

    return;
    // 0x808002B0: nop

;}
RECOMP_FUNC void func_80801988_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801988: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080198C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801990: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801994: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801998: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080199C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808019A0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808019A4: jal         0x80106790
    // 0x808019A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808019A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808019AC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808019B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019B4: jal         0x80100094
    // 0x808019B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808019B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808019BC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808019C0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x808019C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019C8: bne         $t6, $t7, L_808019D8
    if (ctx->r14 != ctx->r15) {
        // 0x808019CC: nop
    
            goto L_808019D8;
    }
    // 0x808019CC: nop

    // 0x808019D0: b           L_80801A58
    // 0x808019D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801A58;
    // 0x808019D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808019D8:
    // 0x808019D8: jal         0x80801A6C
    // 0x808019DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801A6C_chevilspirit(rdram, ctx);
        goto after_2;
    // 0x808019DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x808019E0: bne         $v0, $zero, L_808019F0
    if (ctx->r2 != 0) {
        // 0x808019E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808019F0;
    }
    // 0x808019E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019E8: b           L_80801A58
    // 0x808019EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801A58;
    // 0x808019EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808019F0:
    // 0x808019F0: jal         0x80100094
    // 0x808019F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x808019F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808019F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808019FC: jal         0x8008A028
    // 0x80801A00: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _subaddielink_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80801A00: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80801A04: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801A08: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x80801A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A10: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x80801A14: lbu         $t9, 0x64($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X64);
    // 0x80801A18: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(924, 0X21E0) << 16);
    // 0x80801A1C: ori         $t1, $t9, 0x20
    ctx->r9 = ctx->r25 | 0X20;
    // 0x80801A20: andi        $t2, $t1, 0xE7
    ctx->r10 = ctx->r9 & 0XE7;
    // 0x80801A24: sb          $t1, 0x64($s1)
    MEM_B(0X64, ctx->r17) = ctx->r9;
    // 0x80801A28: ori         $t3, $t2, 0x8
    ctx->r11 = ctx->r10 | 0X8;
    // 0x80801A2C: sb          $t3, 0x64($s1)
    MEM_B(0X64, ctx->r17) = ctx->r11;
    // 0x80801A30: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80801A34: bnel        $t4, $zero, L_80801A48
    if (ctx->r12 != 0) {
        // 0x80801A38: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80801A48;
    }
    goto skip_0;
    // 0x80801A38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x80801A3C: jal         0x80802090
    // 0x80801A40: addiu       $a1, $a1, 0x21E0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(924, 0X21E0));
    func_80802090_chevilspirit(rdram, ctx);
        goto after_5;
    // 0x80801A40: addiu       $a1, $a1, 0x21E0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(924, 0X21E0));
    after_5:
    // 0x80801A44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80801A48:
    // 0x80801A48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801A4C: jal         0x8010108C
    // 0x80801A50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_6;
    // 0x80801A50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80801A54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801A58:
    // 0x80801A58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A5C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801A60: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801A64: jr          $ra
    // 0x80801A68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80801A68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void bakaztorpedo_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800118: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8080011C: lw          $t6, 0xB0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XB0);
    // 0x80800120: jr          $ra
    // 0x80800124: swc1        $f12, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x80800124: swc1        $f12, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_800D3B24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3B24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D3B28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D3B2C: jal         0x800343B0
    // 0x800D3B30: nop

    osGetCount_recomp(rdram, ctx);
        goto after_0;
    // 0x800D3B30: nop

    after_0:
    // 0x800D3B34: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800D3B38: addiu       $a1, $a1, -0x3CDC
    ctx->r5 = ADD32(ctx->r5, -0X3CDC);
    // 0x800D3B3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800D3B40: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D3B44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800D3B48: jal         0x800D3B6C
    // 0x800D3B4C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D3B6C(rdram, ctx);
        goto after_1;
    // 0x800D3B4C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x800D3B50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3B54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D3B58: jr          $ra
    // 0x800D3B5C: nop

    return;
    // 0x800D3B5C: nop

;}
RECOMP_FUNC void guOrtho(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DE04: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8002DE08: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8002DE0C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8002DE10: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8002DE14: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8002DE18: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8002DE1C: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8002DE20: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002DE24: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8002DE28: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8002DE2C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8002DE30: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x8002DE34: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8002DE38: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8002DE3C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8002DE40: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8002DE44: jal         0x8002DCB0
    // 0x8002DE48: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    guOrthoF(rdram, ctx);
        goto after_0;
    // 0x8002DE48: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x8002DE4C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8002DE50: jal         0x8002ED00
    // 0x8002DE54: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x8002DE54: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x8002DE58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8002DE5C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8002DE60: jr          $ra
    // 0x8002DE64: nop

    return;
    // 0x8002DE64: nop

;}
RECOMP_FUNC void func_808009FC_bskazpaddle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A04: jal         0x80082FF0
    // 0x80800A08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800A08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800A0C: jal         0x80800000
    // 0x80800A10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800000_bskazpaddle(rdram, ctx);
        goto after_1;
    // 0x80800A10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A1C: jr          $ra
    // 0x80800A20: nop

    return;
    // 0x80800A20: nop

;}
RECOMP_FUNC void func_808002F8_chlagoonfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808002FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800300: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800304: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800308: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x8080030C: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x80800310: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800314: jal         0x800EEC30
    // 0x80800318: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    func_800EEC30(rdram, ctx);
        goto after_0;
    // 0x80800318: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    after_0:
    // 0x8080031C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800320: jal         0x800EF04C
    // 0x80800324: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_1;
    // 0x80800324: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x80800328: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
    // 0x8080032C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800330: sll         $a2, $v0, 22
    ctx->r6 = S32(ctx->r2 << 22);
    // 0x80800334: srl         $t6, $a2, 26
    ctx->r14 = S32(U32(ctx->r6) >> 26);
    // 0x80800338: srl         $a1, $v0, 25
    ctx->r5 = S32(U32(ctx->r2) >> 25);
    // 0x8080033C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80800340: jal         0x800CC338
    // 0x80800344: addiu       $a2, $t6, -0x1
    ctx->r6 = ADD32(ctx->r14, -0X1);
    func_800CC338(rdram, ctx);
        goto after_2;
    // 0x80800344: addiu       $a2, $t6, -0x1
    ctx->r6 = ADD32(ctx->r14, -0X1);
    after_2:
    // 0x80800348: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080034C: beq         $v0, $at, L_80800374
    if (ctx->r2 == ctx->r1) {
        // 0x80800350: addiu       $t8, $v0, 0x1
        ctx->r24 = ADD32(ctx->r2, 0X1);
            goto L_80800374;
    }
    // 0x80800350: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80800354: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
    // 0x80800358: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8080035C: andi        $t0, $t9, 0x3F0
    ctx->r8 = ctx->r25 & 0X3F0;
    // 0x80800360: andi        $t2, $t1, 0xFC0F
    ctx->r10 = ctx->r9 & 0XFC0F;
    // 0x80800364: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80800368: sh          $t3, 0x72($s0)
    MEM_H(0X72, ctx->r16) = ctx->r11;
    // 0x8080036C: b           L_80800378
    // 0x80800370: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800378;
    // 0x80800370: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800374:
    // 0x80800374: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800378:
    // 0x80800378: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080037C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800380: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800384: jr          $ra
    // 0x80800388: nop

    return;
    // 0x80800388: nop

;}
RECOMP_FUNC void func_8010D09C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_enemy_aim(rdram, ctx);
    // 0x8010D09C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8010D0A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010D0A4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8010D0A8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8010D0AC: jal         0x800D8FF8
    // 0x8010D0B0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8010D0B0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_0:
    // 0x8010D0B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010D0B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8010D0BC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8010D0C0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8010D0C4: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8010D0C8: jal         0x800F5A00
    // 0x8010D0CC: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x8010D0CC: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8010D0D0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8010D0D4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8010D0D8: jal         0x800F5A2C
    // 0x8010D0DC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800F5A2C(rdram, ctx);
        goto after_2;
    // 0x8010D0DC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x8010D0E0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8010D0E4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8010D0E8: jal         0x800EFB24
    // 0x8010D0EC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800EFB24(rdram, ctx);
        goto after_3;
    // 0x8010D0EC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x8010D0F0: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8010D0F4: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8010D0F8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8010D0FC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8010D100: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8010D104: jal         0x800EF334
    // 0x8010D108: nop

    func_800EF334(rdram, ctx);
        goto after_4;
    // 0x8010D108: nop

    after_4:
    // 0x8010D10C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8010D110: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8010D114: jal         0x800EE780
    // 0x8010D118: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_800EE780(rdram, ctx);
        goto after_5;
    // 0x8010D118: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_5:
    // 0x8010D11C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010D120: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    tooie_enemy_aim_end(rdram, ctx);
    // 0x8010D124: jr          $ra
    // 0x8010D128: nop

    return;
    // 0x8010D128: nop

;}
RECOMP_FUNC void chdiggerboss_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F0: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(1480, 0X9E44) << 16);
    // 0x808004F4: jr          $ra
    // 0x808004F8: addiu       $v0, $v0, -0x61BC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1480, 0X9E44));
    return;
    // 0x808004F8: addiu       $v0, $v0, -0x61BC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1480, 0X9E44));
;}
