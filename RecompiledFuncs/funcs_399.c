#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void chdinocoaster_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1072, 0X4E0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x4E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1072, 0X4E0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x4E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1072, 0X4E0));
;}
RECOMP_FUNC void func_800C71B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C71B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C71B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C71B8: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800C71BC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C71C0: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x800C71C4: lhu         $v0, 0x6($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X6);
    // 0x800C71C8: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x800C71CC: srl         $t7, $v0, 7
    ctx->r15 = S32(U32(ctx->r2) >> 7);
    // 0x800C71D0: bne         $t7, $at, L_800C71E0
    if (ctx->r15 != ctx->r1) {
        // 0x800C71D4: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800C71E0;
    }
    // 0x800C71D4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800C71D8: b           L_800C721C
    // 0x800C71DC: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_800C721C;
    // 0x800C71DC: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_800C71E0:
    // 0x800C71E0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800C71E4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C71E8: bgez        $v0, L_800C71FC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800C71EC: cvt.s.w     $f12, $f4
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800C71FC;
    }
    // 0x800C71EC: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C71F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C71F4: nop

    // 0x800C71F8: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
L_800C71FC:
    // 0x800C71FC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800C7200: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C7204: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C7208: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C720C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x800C7210: jal         0x800F10B4
    // 0x800C7214: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x800C7214: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x800C7218: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800C721C:
    // 0x800C721C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7220: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C7224: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800C7228: jr          $ra
    // 0x800C722C: nop

    return;
    // 0x800C722C: nop

;}
RECOMP_FUNC void _bsrest_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083958: syscall     84
    recomp_syscall_handler(rdram, ctx, 0x80083958);
    return;
    // 0x8008395C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808021D4_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808021D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808021D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808021DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808021E0: jal         0x801015D0
    // 0x808021E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_801015D0(rdram, ctx);
        goto after_0;
    // 0x808021E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808021E8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808021EC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x808021F0: jal         0x800D731C
    // 0x808021F4: lhu         $a0, 0x14($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X14);
    func_800D731C(rdram, ctx);
        goto after_1;
    // 0x808021F4: lhu         $a0, 0x14($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X14);
    after_1:
    // 0x808021F8: beq         $v0, $zero, L_80802230
    if (ctx->r2 == 0) {
        // 0x808021FC: sb          $v0, 0x1F($sp)
        MEM_B(0X1F, ctx->r29) = ctx->r2;
            goto L_80802230;
    }
    // 0x808021FC: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    // 0x80802200: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80802204: jal         0x800E8C58
    // 0x80802208: lbu         $a0, 0x28($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X28);
    func_800E8C58(rdram, ctx);
        goto after_2;
    // 0x80802208: lbu         $a0, 0x28($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X28);
    after_2:
    // 0x8080220C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80802210: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    // 0x80802214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802218: jal         0x800DBE60
    // 0x8080221C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800DBE60(rdram, ctx);
        goto after_3;
    // 0x8080221C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
    // 0x80802220: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    // 0x80802224: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802228: jal         0x800DBE60
    // 0x8080222C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    func_800DBE60(rdram, ctx);
        goto after_4;
    // 0x8080222C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_4:
L_80802230:
    // 0x80802230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802234: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802238: jr          $ra
    // 0x8080223C: nop

    return;
    // 0x8080223C: nop

;}
RECOMP_FUNC void func_800F214C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F214C: abs.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = fabsf(ctx->f12.fl);
    // 0x800F2150: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x800F2154: bc1t        L_800F2160
    if (c1cs) {
        // 0x800F2158: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800F2160;
    }
    // 0x800F2158: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F215C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800F2160:
    // 0x800F2160: jr          $ra
    // 0x800F2164: nop

    return;
    // 0x800F2164: nop

;}
RECOMP_FUNC void func_8010B190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B190: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010B194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010B198: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8010B19C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8010B1A0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8010B1A4: jal         0x8010C4AC
    // 0x8010B1A8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8010C4AC(rdram, ctx);
        goto after_0;
    // 0x8010B1A8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8010B1AC: jal         0x800D8FF8
    // 0x8010B1B0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x8010B1B0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8010B1B4: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8010B1B8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8010B1BC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8010B1C0: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8010B1C4: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x8010B1C8: lw          $a2, 0x48($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X48);
    // 0x8010B1CC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8010B1D0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8010B1D4: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8010B1D8: jal         0x800EF214
    // 0x8010B1DC: nop

    func_800EF214(rdram, ctx);
        goto after_2;
    // 0x8010B1DC: nop

    after_2:
    // 0x8010B1E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010B1E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8010B1E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010B1EC: jr          $ra
    // 0x8010B1F0: nop

    return;
    // 0x8010B1F0: nop

;}
RECOMP_FUNC void func_808045FC_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808045FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804604: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x80804608: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8080460C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80804610: beql        $v0, $v1, L_80804634
    if (ctx->r2 == ctx->r3) {
        // 0x80804614: lwc1        $f0, 0x0($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
            goto L_80804634;
    }
    goto skip_0;
    // 0x80804614: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x80804618: beq         $v0, $zero, L_808046B4
    if (ctx->r2 == 0) {
        // 0x8080461C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808046B4;
    }
    // 0x8080461C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80804620: beql        $v0, $at, L_80804704
    if (ctx->r2 == ctx->r1) {
        // 0x80804624: lwc1        $f0, 0x0($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
            goto L_80804704;
    }
    goto skip_1;
    // 0x80804624: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    skip_1:
    // 0x80804628: b           L_8080477C
    // 0x8080462C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
        goto L_8080477C;
    // 0x8080462C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80804630: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
L_80804634:
    // 0x80804634: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80804638: nop

    // 0x8080463C: bc1fl       L_80804650
    if (!c1cs) {
        // 0x80804640: c.eq.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
            goto L_80804650;
    }
    goto skip_2;
    // 0x80804640: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    skip_2:
    // 0x80804644: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
    // 0x80804648: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8080464C: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
L_80804650:
    // 0x80804650: nop

    // 0x80804654: bc1fl       L_80804680
    if (!c1cs) {
        // 0x80804658: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_80804680;
    }
    goto skip_3;
    // 0x80804658: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_3:
    // 0x8080465C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80804660: nop

    // 0x80804664: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x80804668: nop

    // 0x8080466C: bc1fl       L_80804680
    if (!c1cs) {
        // 0x80804670: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_80804680;
    }
    goto skip_4;
    // 0x80804670: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_4:
    // 0x80804674: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x80804678: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8080467C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_80804680:
    // 0x80804680: nop

    // 0x80804684: bc1fl       L_80804780
    if (!c1cs) {
        // 0x80804688: lwc1        $f8, 0x18($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
            goto L_80804780;
    }
    goto skip_5;
    // 0x80804688: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    skip_5:
    // 0x8080468C: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80804690: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80804694: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80804698: nop

    // 0x8080469C: bc1fl       L_80804780
    if (!c1cs) {
        // 0x808046A0: lwc1        $f8, 0x18($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
            goto L_80804780;
    }
    goto skip_6;
    // 0x808046A0: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    skip_6:
    // 0x808046A4: swc1        $f12, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f12.u32l;
    // 0x808046A8: sw          $t6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r14;
    // 0x808046AC: b           L_8080477C
    // 0x808046B0: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
        goto L_8080477C;
    // 0x808046B0: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
L_808046B4:
    // 0x808046B4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808046B8: nop

    // 0x808046BC: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x808046C0: nop

    // 0x808046C4: bc1fl       L_808046E0
    if (!c1cs) {
        // 0x808046C8: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_808046E0;
    }
    goto skip_7;
    // 0x808046C8: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_7:
    // 0x808046CC: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    // 0x808046D0: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
    // 0x808046D4: b           L_808046F8
    // 0x808046D8: swc1        $f2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f2.u32l;
        goto L_808046F8;
    // 0x808046D8: swc1        $f2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f2.u32l;
    // 0x808046DC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
L_808046E0:
    // 0x808046E0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808046E4: bc1f        L_808046F8
    if (!c1cs) {
        // 0x808046E8: nop
    
            goto L_808046F8;
    }
    // 0x808046E8: nop

    // 0x808046EC: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x808046F0: swc1        $f2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
    // 0x808046F4: swc1        $f12, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f12.u32l;
L_808046F8:
    // 0x808046F8: b           L_8080477C
    // 0x808046FC: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
        goto L_8080477C;
    // 0x808046FC: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80804700: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
L_80804704:
    // 0x80804704: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80804708: nop

    // 0x8080470C: bc1fl       L_80804720
    if (!c1cs) {
        // 0x80804710: c.eq.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
            goto L_80804720;
    }
    goto skip_8;
    // 0x80804710: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    skip_8:
    // 0x80804714: swc1        $f12, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f12.u32l;
    // 0x80804718: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8080471C: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
L_80804720:
    // 0x80804720: nop

    // 0x80804724: bc1fl       L_80804750
    if (!c1cs) {
        // 0x80804728: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_80804750;
    }
    goto skip_9;
    // 0x80804728: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_9:
    // 0x8080472C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80804730: nop

    // 0x80804734: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x80804738: nop

    // 0x8080473C: bc1fl       L_80804750
    if (!c1cs) {
        // 0x80804740: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_80804750;
    }
    goto skip_10;
    // 0x80804740: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_10:
    // 0x80804744: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x80804748: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8080474C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_80804750:
    // 0x80804750: nop

    // 0x80804754: bc1fl       L_80804780
    if (!c1cs) {
        // 0x80804758: lwc1        $f8, 0x18($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
            goto L_80804780;
    }
    goto skip_11;
    // 0x80804758: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    skip_11:
    // 0x8080475C: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80804760: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80804764: nop

    // 0x80804768: bc1fl       L_80804780
    if (!c1cs) {
        // 0x8080476C: lwc1        $f8, 0x18($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
            goto L_80804780;
    }
    goto skip_12;
    // 0x8080476C: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    skip_12:
    // 0x80804770: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
    // 0x80804774: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    // 0x80804778: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
L_8080477C:
    // 0x8080477C: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
L_80804780:
    // 0x80804780: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80804784: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x80804788: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x8080478C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80804790: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    // 0x80804794: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x80804798: jal         0x800F2108
    // 0x8080479C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F2108(rdram, ctx);
        goto after_0;
    // 0x8080479C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808047A0: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808047A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808047A8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808047AC: mul.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x808047B0: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x808047B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808047B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808047BC: div.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808047C0: add.s       $f2, $f18, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f14.fl;
    // 0x808047C4: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x808047C8: nop

    // 0x808047CC: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x808047D0: sub.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x808047D4: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x808047D8: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x808047DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808047E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808047E4: jr          $ra
    // 0x808047E8: nop

    return;
    // 0x808047E8: nop

;}
RECOMP_FUNC void func_8008E95C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E95C: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x8008E960: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8008E964: lbu         $t8, 0x2A($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X2A);
    // 0x8008E968: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x8008E96C: jr          $ra
    // 0x8008E970: sb          $t9, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r25;
    return;
    // 0x8008E970: sb          $t9, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void bsbbilldrill_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A4C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800A50: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(61, 0XB68) << 16);
    // 0x80800A54: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800A58: jr          $ra
    // 0x80800A5C: lw          $v0, 0xB68($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(61, 0XB68));
    return;
    // 0x80800A5C: lw          $v0, 0xB68($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(61, 0XB68));
;}
RECOMP_FUNC void func_8009AD78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009AD78: lw          $t6, 0xC4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC4);
    // 0x8009AD7C: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x8009AD80: jr          $ra
    // 0x8009AD84: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    return;
    // 0x8009AD84: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
;}
RECOMP_FUNC void func_80801374_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801374: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801378: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080137C: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80801380: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(880, 0X14F0) << 16);
    // 0x80801384: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801388: xor         $a2, $a1, $t7
    ctx->r6 = ctx->r5 ^ ctx->r15;
    // 0x8080138C: sltiu       $a2, $a2, 0x1
    ctx->r6 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x80801390: bne         $a2, $zero, L_808013AC
    if (ctx->r6 != 0) {
        // 0x80801394: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808013AC;
    }
    // 0x80801394: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801398: bnel        $a2, $zero, L_808013B8
    if (ctx->r6 != 0) {
        // 0x8080139C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808013B8;
    }
    goto skip_0;
    // 0x8080139C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808013A0: lbu         $t8, 0x5F($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X5F);
    // 0x808013A4: beql        $t8, $zero, L_808013B8
    if (ctx->r24 == 0) {
        // 0x808013A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808013B8;
    }
    goto skip_1;
    // 0x808013A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_808013AC:
    // 0x808013AC: jal         0x80089D50
    // 0x808013B0: addiu       $a3, $a3, 0x14F0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(880, 0X14F0));
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808013B0: addiu       $a3, $a3, 0x14F0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(880, 0X14F0));
    after_0:
    // 0x808013B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808013B8:
    // 0x808013B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808013BC: jr          $ra
    // 0x808013C0: nop

    return;
    // 0x808013C0: nop

    // 0x808013C4: nop

    // 0x808013C8: nop

    // 0x808013CC: nop

;}
RECOMP_FUNC void func_800CD544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD544: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800CD548: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800CD54C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CD550: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x800CD554: lwc1        $f4, -0x4FF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4FF0);
    // 0x800CD558: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800CD55C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800CD560: add.s       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f20.fl + ctx->f4.fl;
    // 0x800CD564: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800CD568: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800CD56C: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x800CD570: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x800CD574: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800CD578: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800CD57C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800CD580: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800CD584: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800CD588: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800CD58C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800CD590: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x800CD594: jal         0x800BD708
    // 0x800CD598: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800BD708(rdram, ctx);
        goto after_0;
    // 0x800CD598: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_0:
    // 0x800CD59C: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x800CD5A0: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x800CD5A4: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800CD5A8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800CD5AC: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x800CD5B0: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800CD5B4: bne         $at, $zero, L_800CD664
    if (ctx->r1 != 0) {
        // 0x800CD5B8: sw          $t8, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r24;
            goto L_800CD664;
    }
    // 0x800CD5B8: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    // 0x800CD5BC: addiu       $s0, $sp, 0x6C
    ctx->r16 = ADD32(ctx->r29, 0X6C);
    // 0x800CD5C0: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x800CD5C4: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
L_800CD5C8:
    // 0x800CD5C8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x800CD5CC: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800CD5D0: bne         $at, $zero, L_800CD64C
    if (ctx->r1 != 0) {
        // 0x800CD5D4: sw          $a0, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r4;
            goto L_800CD64C;
    }
    // 0x800CD5D4: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x800CD5D8: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
L_800CD5DC:
    // 0x800CD5DC: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800CD5E0: bne         $at, $zero, L_800CD638
    if (ctx->r1 != 0) {
        // 0x800CD5E4: sw          $v0, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r2;
            goto L_800CD638;
    }
    // 0x800CD5E4: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x800CD5E8: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
L_800CD5EC:
    // 0x800CD5EC: jal         0x800BDAD4
    // 0x800CD5F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BDAD4(rdram, ctx);
        goto after_1;
    // 0x800CD5F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800CD5F4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800CD5F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CD5FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CD600: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x800CD604: jal         0x800EADFC
    // 0x800CD608: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_800EADFC(rdram, ctx);
        goto after_2;
    // 0x800CD608: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_2:
    // 0x800CD60C: beql        $v0, $zero, L_800CD61C
    if (ctx->r2 == 0) {
        // 0x800CD610: lw          $v0, 0x74($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X74);
            goto L_800CD61C;
    }
    goto skip_0;
    // 0x800CD610: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    skip_0:
    // 0x800CD614: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x800CD618: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
L_800CD61C:
    // 0x800CD61C: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x800CD620: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800CD624: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800CD628: beq         $at, $zero, L_800CD5EC
    if (ctx->r1 == 0) {
        // 0x800CD62C: sw          $v0, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r2;
            goto L_800CD5EC;
    }
    // 0x800CD62C: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x800CD630: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x800CD634: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
L_800CD638:
    // 0x800CD638: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800CD63C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800CD640: beql        $at, $zero, L_800CD5DC
    if (ctx->r1 == 0) {
        // 0x800CD644: lw          $v0, 0x68($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X68);
            goto L_800CD5DC;
    }
    goto skip_1;
    // 0x800CD644: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    skip_1:
    // 0x800CD648: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
L_800CD64C:
    // 0x800CD64C: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x800CD650: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800CD654: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800CD658: slt         $at, $t2, $t1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800CD65C: beq         $at, $zero, L_800CD5C8
    if (ctx->r1 == 0) {
        // 0x800CD660: sw          $t1, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r9;
            goto L_800CD5C8;
    }
    // 0x800CD660: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
L_800CD664:
    // 0x800CD664: jal         0x800BDC44
    // 0x800CD668: nop

    func_800BDC44(rdram, ctx);
        goto after_3;
    // 0x800CD668: nop

    after_3:
    // 0x800CD66C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800CD670: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CD674: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CD678: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x800CD67C: jal         0x800EADFC
    // 0x800CD680: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_800EADFC(rdram, ctx);
        goto after_4;
    // 0x800CD680: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_4:
    // 0x800CD684: beq         $v0, $zero, L_800CD690
    if (ctx->r2 == 0) {
        // 0x800CD688: ldc1        $f20, 0x20($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
            goto L_800CD690;
    }
    // 0x800CD688: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800CD68C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
L_800CD690:
    // 0x800CD690: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800CD694: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x800CD698: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800CD69C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800CD6A0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800CD6A4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800CD6A8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800CD6AC: jr          $ra
    // 0x800CD6B0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800CD6B0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void _chjigsawdance_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800858C0: syscall     179
    recomp_syscall_handler(rdram, ctx, 0x800858C0);
    return;
    // 0x800858C4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80809AF8_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809AF8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80809AFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80809B00: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80809B04: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80809B08: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80809B0C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80809B10: lw          $t7, 0x188($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X188);
    // 0x80809B14: jal         0x800D9004
    // 0x80809B18: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    func_800D9004(rdram, ctx);
        goto after_0;
    // 0x80809B18: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    after_0:
    // 0x80809B1C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA5A0) << 16);
    // 0x80809B20: lwc1        $f12, -0x5A60($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA5A0));
    // 0x80809B24: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80809B28: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80809B2C: sub.s       $f2, $f0, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80809B30: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80809B34: addiu       $a0, $a0, 0x24C
    ctx->r4 = ADD32(ctx->r4, 0X24C);
    // 0x80809B38: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80809B3C: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x80809B40: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80809B44: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80809B48: jal         0x808057C8
    // 0x80809B4C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_808057C8_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80809B4C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80809B50: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80809B54: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80809B58: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80809B5C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80809B60: c.eq.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl == ctx->f12.fl;
    // 0x80809B64: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80809B68: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80809B6C: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80809B70: bc1tl       L_80809B90
    if (c1cs) {
        // 0x80809B74: swc1        $f12, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
            goto L_80809B90;
    }
    goto skip_0;
    // 0x80809B74: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    skip_0:
    // 0x80809B78: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80809B7C: jal         0x808057C8
    // 0x80809B80: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_808057C8_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80809B80: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80809B84: b           L_80809B90
    // 0x80809B88: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
        goto L_80809B90;
    // 0x80809B88: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80809B8C: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
L_80809B90:
    // 0x80809B90: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80809B94: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80809B98: jal         0x808052A4
    // 0x80809B9C: addiu       $a1, $a1, 0x250
    ctx->r5 = ADD32(ctx->r5, 0X250);
    func_808052A4_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80809B9C: addiu       $a1, $a1, 0x250
    ctx->r5 = ADD32(ctx->r5, 0X250);
    after_3:
    // 0x80809BA0: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80809BA4: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80809BA8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80809BAC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80809BB0: jal         0x8009C984
    // 0x80809BB4: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    yaw_get(rdram, ctx);
        goto after_4;
    // 0x80809BB4: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x80809BB8: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80809BBC: jal         0x800136E4
    // 0x80809BC0: add.s       $f12, $f0, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f18.fl;
    func_800136E4(rdram, ctx);
        goto after_5;
    // 0x80809BC0: add.s       $f12, $f0, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f18.fl;
    after_5:
    // 0x80809BC4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80809BC8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80809BCC: jal         0x8009C914
    // 0x80809BD0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    yaw_setIdeal(rdram, ctx);
        goto after_6;
    // 0x80809BD0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_6:
    // 0x80809BD4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80809BD8: jal         0x8009C944
    // 0x80809BDC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    yaw_set(rdram, ctx);
        goto after_7;
    // 0x80809BDC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x80809BE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80809BE4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80809BE8: jr          $ra
    // 0x80809BEC: nop

    return;
    // 0x80809BEC: nop

;}
RECOMP_FUNC void _sumissilehome_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A778: syscall     850
    recomp_syscall_handler(rdram, ctx, 0x8008A778);
    return;
    // 0x8008A77C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _subaddiefade_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089CD8: syscall     808
    recomp_syscall_handler(rdram, ctx, 0x80089CD8);
    return;
    // 0x80089CDC: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80800AE4_chkingjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AEC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800AF0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800AF4: jal         0x8008A1E8
    // 0x80800AF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800AF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800AFC: beq         $v0, $zero, L_80800B18
    if (ctx->r2 == 0) {
        // 0x80800B00: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800B18;
    }
    // 0x80800B00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800B04: addiu       $at, $zero, 0x1208
    ctx->r1 = ADD32(0, 0X1208);
    // 0x80800B08: beq         $v0, $at, L_80800B18
    if (ctx->r2 == ctx->r1) {
        // 0x80800B0C: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80800B18;
    }
    // 0x80800B0C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800B10: jal         0x80800C60
    // 0x80800B14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800C60_chkingjinjo(rdram, ctx);
        goto after_1;
    // 0x80800B14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_80800B18:
    // 0x80800B18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B20: jr          $ra
    // 0x80800B24: nop

    return;
    // 0x80800B24: nop

;}
RECOMP_FUNC void func_80800194_chkingjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800194: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800198: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080019C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808001A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001A4: jal         0x80100094
    // 0x808001A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808001A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808001AC: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808001B0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808001B4: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808001B8: addiu       $t8, $t7, -0x3
    ctx->r24 = ADD32(ctx->r15, -0X3);
    // 0x808001BC: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x808001C0: beq         $at, $zero, L_80800570
    if (ctx->r1 == 0) {
        // 0x808001C4: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800570;
    }
    // 0x808001C4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808001C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1296, 0XFD0) << 16);
    // 0x808001CC: addu        $at, $at, $t8
    gpr jr_addend_808001D4 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808001D0: lw          $t8, 0xFD0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1296, 0XFD0));
    // 0x808001D4: jr          $t8
    // 0x808001D8: nop

    switch (jr_addend_808001D4 >> 2) {
        case 0: goto L_808001DC; break;
        case 1: goto L_80800570; break;
        case 2: goto L_808001F4; break;
        case 3: goto L_80800258; break;
        case 4: goto L_8080043C; break;
        case 5: goto L_808004AC; break;
        case 6: goto L_80800560; break;
        default: switch_error(__func__, 0x808001D4, 0x80800FD0);
    }
    // 0x808001D8: nop

L_808001DC:
    // 0x808001DC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1296, 0X1238) << 16);
    // 0x808001E0: addiu       $a1, $a1, 0x1238
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1296, 0X1238));
    // 0x808001E4: jal         0x80800AE4
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800AE4_chkingjinjo(rdram, ctx);
        goto after_1;
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001EC: b           L_80800570
    // 0x808001F0: nop

        goto L_80800570;
    // 0x808001F0: nop

L_808001F4:
    // 0x808001F4: jal         0x800D9078
    // 0x808001F8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_2;
    // 0x808001F8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_2:
    // 0x808001FC: beq         $v0, $zero, L_80800570
    if (ctx->r2 == 0) {
        // 0x80800200: nop
    
            goto L_80800570;
    }
    // 0x80800200: nop

    // 0x80800204: jal         0x800F54E4
    // 0x80800208: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x80800208: nop

    after_3:
    // 0x8080020C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800210: jal         0x800F5A00
    // 0x80800214: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800F5A00(rdram, ctx);
        goto after_4;
    // 0x80800214: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_4:
    // 0x80800218: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8080021C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800220: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800224: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    // 0x80800228: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080022C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800230: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80800234: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800238: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080023C: jal         0x800D1000
    // 0x80800240: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    func_800D1000(rdram, ctx);
        goto after_5;
    // 0x80800240: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800248: jal         0x80102424
    // 0x8080024C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x8080024C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x80800250: b           L_80800570
    // 0x80800254: nop

        goto L_80800570;
    // 0x80800254: nop

L_80800258:
    // 0x80800258: addiu       $a0, $v1, 0xC
    ctx->r4 = ADD32(ctx->r3, 0XC);
    // 0x8080025C: jal         0x800D9078
    // 0x80800260: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    func_800D9078(rdram, ctx);
        goto after_7;
    // 0x80800260: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_7:
    // 0x80800264: beql        $v0, $zero, L_808002C0
    if (ctx->r2 == 0) {
        // 0x80800268: addiu       $t0, $s0, 0x4
        ctx->r8 = ADD32(ctx->r16, 0X4);
            goto L_808002C0;
    }
    goto skip_0;
    // 0x80800268: addiu       $t0, $s0, 0x4
    ctx->r8 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x8080026C: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80800270: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800274: bne         $a0, $zero, L_8080028C
    if (ctx->r4 != 0) {
        // 0x80800278: nop
    
            goto L_8080028C;
    }
    // 0x80800278: nop

    // 0x8080027C: jal         0x80089D10
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800284: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
    // 0x80800288: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
L_8080028C:
    // 0x8080028C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1296, 0X1254) << 16);
    // 0x80800290: addiu       $a2, $a2, 0x1254
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1296, 0X1254));
    // 0x80800294: jal         0x800C4350
    // 0x80800298: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4350(rdram, ctx);
        goto after_9;
    // 0x80800298: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x8080029C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808002A0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808002A4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x808002A8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808002AC: jal         0x800DC178
    // 0x808002B0: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
    func_800DC178(rdram, ctx);
        goto after_10;
    // 0x808002B0: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
    after_10:
    // 0x808002B4: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x808002B8: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
    // 0x808002BC: addiu       $t0, $s0, 0x4
    ctx->r8 = ADD32(ctx->r16, 0X4);
L_808002C0:
    // 0x808002C0: jal         0x800C0638
    // 0x808002C4: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    func_800C0638(rdram, ctx);
        goto after_11;
    // 0x808002C4: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    after_11:
    // 0x808002C8: bne         $v0, $zero, L_80800330
    if (ctx->r2 != 0) {
        // 0x808002CC: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_80800330;
    }
    // 0x808002CC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808002D0: jal         0x8010CAC0
    // 0x808002D4: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    func_8010CAC0(rdram, ctx);
        goto after_12;
    // 0x808002D4: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_12:
    // 0x808002D8: beq         $v0, $zero, L_80800330
    if (ctx->r2 == 0) {
        // 0x808002DC: nop
    
            goto L_80800330;
    }
    // 0x808002DC: nop

    // 0x808002E0: jal         0x800D90A4
    // 0x808002E4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_13;
    // 0x808002E4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_13:
    // 0x808002E8: beq         $v0, $zero, L_80800330
    if (ctx->r2 == 0) {
        // 0x808002EC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800330;
    }
    // 0x808002EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808002F0: jal         0x800DC128
    // 0x808002F4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800DC128(rdram, ctx);
        goto after_14;
    // 0x808002F4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_14:
    // 0x808002F8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808002FC: addiu       $t1, $zero, 0xA5
    ctx->r9 = ADD32(0, 0XA5);
    // 0x80800300: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800304: addiu       $a1, $v0, 0x152F
    ctx->r5 = ADD32(ctx->r2, 0X152F);
    // 0x80800308: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x8080030C: jal         0x8008A208
    // 0x80800310: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_15;
    // 0x80800310: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_15:
    // 0x80800314: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800318: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080031C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80800320: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800324: jal         0x800DC178
    // 0x80800328: nop

    func_800DC178(rdram, ctx);
        goto after_16;
    // 0x80800328: nop

    after_16:
    // 0x8080032C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80800330:
    // 0x80800330: jal         0x8010D248
    // 0x80800334: nop

    func_8010D248(rdram, ctx);
        goto after_17;
    // 0x80800334: nop

    after_17:
    // 0x80800338: beql        $v0, $zero, L_80800360
    if (ctx->r2 == 0) {
        // 0x8080033C: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_80800360;
    }
    goto skip_1;
    // 0x8080033C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    skip_1:
    // 0x80800340: jal         0x8010C500
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_18;
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800348: beql        $v0, $zero, L_80800360
    if (ctx->r2 == 0) {
        // 0x8080034C: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_80800360;
    }
    goto skip_2;
    // 0x8080034C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    skip_2:
    // 0x80800350: jal         0x8010CD28
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_19;
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800358: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x8080035C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
L_80800360:
    // 0x80800360: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800364: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800368: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8080036C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800370: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800374: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800378: lw          $a3, 0x54($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X54);
    // 0x8080037C: addiu       $t2, $zero, 0x4000
    ctx->r10 = ADD32(0, 0X4000);
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800384: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x80800388: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8080038C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80800390: jal         0x80089F90
    // 0x80800394: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_20;
    // 0x80800394: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_20:
    // 0x80800398: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8080039C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1296, 0XFEC) << 16);
    // 0x808003A0: lwc1        $f6, 0xFEC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1296, 0XFEC));
    // 0x808003A4: lhu         $a2, 0x6($a1)
    ctx->r6 = MEM_HU(ctx->r5, 0X6);
    // 0x808003A8: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x808003AC: addiu       $t4, $zero, 0x28
    ctx->r12 = ADD32(0, 0X28);
    // 0x808003B0: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x808003B4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003BC: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    // 0x808003C0: jal         0x80089F88
    // 0x808003C4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    _subaddierouteDll_entrypoint_6(rdram, ctx);
        goto after_21;
    // 0x808003C4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_21:
    // 0x808003C8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808003CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808003D0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x808003D4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808003D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808003DC: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x808003E0: lhu         $a2, 0x6($a1)
    ctx->r6 = MEM_HU(ctx->r5, 0X6);
    // 0x808003E4: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003EC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x808003F0: jal         0x80089F80
    // 0x808003F4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    _subaddierouteDll_entrypoint_5(rdram, ctx);
        goto after_22;
    // 0x808003F4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_22:
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003FC: jal         0x8010B990
    // 0x80800400: addiu       $a1, $zero, 0x1405
    ctx->r5 = ADD32(0, 0X1405);
    func_8010B990(rdram, ctx);
        goto after_23;
    // 0x80800400: addiu       $a1, $zero, 0x1405
    ctx->r5 = ADD32(0, 0X1405);
    after_23:
    // 0x80800404: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800408: jal         0x8010C9B0
    // 0x8080040C: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    func_8010C9B0(rdram, ctx);
        goto after_24;
    // 0x8080040C: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    after_24:
    // 0x80800410: beq         $v0, $zero, L_80800570
    if (ctx->r2 == 0) {
        // 0x80800414: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800570;
    }
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800418: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    // 0x8080041C: jal         0x8010CD88
    // 0x80800420: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    func_8010CD88(rdram, ctx);
        goto after_25;
    // 0x80800420: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    after_25:
    // 0x80800424: beq         $v0, $zero, L_80800570
    if (ctx->r2 == 0) {
        // 0x80800428: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800570;
    }
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080042C: jal         0x80102424
    // 0x80800430: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80102424(rdram, ctx);
        goto after_26;
    // 0x80800430: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_26:
    // 0x80800434: b           L_80800570
    // 0x80800438: nop

        goto L_80800570;
    // 0x80800438: nop

L_8080043C:
    // 0x8080043C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800440: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800444: jal         0x80101E14
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_27;
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x8080044C: beq         $v0, $zero, L_8080048C
    if (ctx->r2 == 0) {
        // 0x80800450: nop
    
            goto L_8080048C;
    }
    // 0x80800450: nop

    // 0x80800454: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80800458: beq         $a0, $zero, L_80800478
    if (ctx->r4 == 0) {
        // 0x8080045C: nop
    
            goto L_80800478;
    }
    // 0x8080045C: nop

    // 0x80800460: jal         0x800C3D78
    // 0x80800464: nop

    func_800C3D78(rdram, ctx);
        goto after_28;
    // 0x80800464: nop

    after_28:
    // 0x80800468: beq         $v0, $zero, L_80800478
    if (ctx->r2 == 0) {
        // 0x8080046C: nop
    
            goto L_80800478;
    }
    // 0x8080046C: nop

    // 0x80800470: jal         0x800C3CE8
    // 0x80800474: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    func_800C3CE8(rdram, ctx);
        goto after_29;
    // 0x80800474: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    after_29:
L_80800478:
    // 0x80800478: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1296, 0X1264) << 16);
    // 0x8080047C: addiu       $a2, $a2, 0x1264
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1296, 0X1264));
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800484: jal         0x80089D18
    // 0x80800488: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_30;
    // 0x80800488: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_30:
L_8080048C:
    // 0x8080048C: jal         0x80101DDC
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_31;
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80800494: beq         $v0, $zero, L_80800570
    if (ctx->r2 == 0) {
        // 0x80800498: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800570;
    }
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080049C: jal         0x80102424
    // 0x808004A0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_32;
    // 0x808004A0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_32:
    // 0x808004A4: b           L_80800570
    // 0x808004A8: nop

        goto L_80800570;
    // 0x808004A8: nop

L_808004AC:
    // 0x808004AC: jal         0x8010D248
    // 0x808004B0: nop

    func_8010D248(rdram, ctx);
        goto after_33;
    // 0x808004B0: nop

    after_33:
    // 0x808004B4: beql        $v0, $zero, L_808004DC
    if (ctx->r2 == 0) {
        // 0x808004B8: lui         $a1, 0x3DCC
        ctx->r5 = S32(0X3DCC << 16);
            goto L_808004DC;
    }
    goto skip_3;
    // 0x808004B8: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    skip_3:
    // 0x808004BC: jal         0x8010C500
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_34;
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x808004C4: beql        $v0, $zero, L_808004DC
    if (ctx->r2 == 0) {
        // 0x808004C8: lui         $a1, 0x3DCC
        ctx->r5 = S32(0X3DCC << 16);
            goto L_808004DC;
    }
    goto skip_4;
    // 0x808004C8: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    skip_4:
    // 0x808004CC: jal         0x8010CD28
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_35;
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x808004D4: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808004D8: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
L_808004DC:
    // 0x808004DC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E4: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x808004E8: jal         0x80102BF8
    // 0x808004EC: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    func_80102BF8(rdram, ctx);
        goto after_36;
    // 0x808004EC: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    after_36:
    // 0x808004F0: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x808004F4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808004F8: jal         0x80101E14
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_37;
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80800500: beq         $v0, $zero, L_80800540
    if (ctx->r2 == 0) {
        // 0x80800504: nop
    
            goto L_80800540;
    }
    // 0x80800504: nop

    // 0x80800508: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x8080050C: beq         $a0, $zero, L_8080052C
    if (ctx->r4 == 0) {
        // 0x80800510: nop
    
            goto L_8080052C;
    }
    // 0x80800510: nop

    // 0x80800514: jal         0x800C3D78
    // 0x80800518: nop

    func_800C3D78(rdram, ctx);
        goto after_38;
    // 0x80800518: nop

    after_38:
    // 0x8080051C: beq         $v0, $zero, L_8080052C
    if (ctx->r2 == 0) {
        // 0x80800520: nop
    
            goto L_8080052C;
    }
    // 0x80800520: nop

    // 0x80800524: jal         0x800C3CE8
    // 0x80800528: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    func_800C3CE8(rdram, ctx);
        goto after_39;
    // 0x80800528: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    after_39:
L_8080052C:
    // 0x8080052C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1296, 0X1274) << 16);
    // 0x80800530: addiu       $a2, $a2, 0x1274
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1296, 0X1274));
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800538: jal         0x80089D18
    // 0x8080053C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_40;
    // 0x8080053C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_40:
L_80800540:
    // 0x80800540: jal         0x80101DDC
    // 0x80800544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_41;
    // 0x80800544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x80800548: beq         $v0, $zero, L_80800570
    if (ctx->r2 == 0) {
        // 0x8080054C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800570;
    }
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800550: jal         0x80102424
    // 0x80800554: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_42;
    // 0x80800554: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_42:
    // 0x80800558: b           L_80800570
    // 0x8080055C: nop

        goto L_80800570;
    // 0x8080055C: nop

L_80800560:
    // 0x80800560: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1296, 0X1284) << 16);
    // 0x80800564: addiu       $a1, $a1, 0x1284
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1296, 0X1284));
    // 0x80800568: jal         0x80800AE4
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800AE4_chkingjinjo(rdram, ctx);
        goto after_43;
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
L_80800570:
    // 0x80800570: jal         0x800DA298
    // 0x80800574: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    func_800DA298(rdram, ctx);
        goto after_44;
    // 0x80800574: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    after_44:
    // 0x80800578: beq         $v0, $zero, L_808005C4
    if (ctx->r2 == 0) {
        // 0x8080057C: addiu       $t6, $s0, 0x4
        ctx->r14 = ADD32(ctx->r16, 0X4);
            goto L_808005C4;
    }
    // 0x8080057C: addiu       $t6, $s0, 0x4
    ctx->r14 = ADD32(ctx->r16, 0X4);
    // 0x80800580: jal         0x800F54E4
    // 0x80800584: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    func_800F54E4(rdram, ctx);
        goto after_45;
    // 0x80800584: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    after_45:
    // 0x80800588: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8080058C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800590: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800594: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800598: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080059C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808005A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005A4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808005A8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808005AC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808005B0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x808005B4: jal         0x800F4EC8
    // 0x808005B8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F4EC8(rdram, ctx);
        goto after_46;
    // 0x808005B8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_46:
    // 0x808005BC: b           L_80800608
    // 0x808005C0: nop

        goto L_80800608;
    // 0x808005C0: nop

L_808005C4:
    // 0x808005C4: jal         0x801022E4
    // 0x808005C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_47;
    // 0x808005C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x808005CC: addiu       $at, $zero, 0x3A9
    ctx->r1 = ADD32(0, 0X3A9);
    // 0x808005D0: bne         $v0, $at, L_80800608
    if (ctx->r2 != ctx->r1) {
        // 0x808005D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800608;
    }
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D8: lui         $a1, 0x3F0C
    ctx->r5 = S32(0X3F0C << 16);
    // 0x808005DC: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x808005E0: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808005E4: jal         0x80102320
    // 0x808005E8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80102320(rdram, ctx);
        goto after_48;
    // 0x808005E8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_48:
    // 0x808005EC: beq         $v0, $zero, L_80800608
    if (ctx->r2 == 0) {
        // 0x808005F0: nop
    
            goto L_80800608;
    }
    // 0x808005F0: nop

    // 0x808005F4: jal         0x80089828
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suexpression_entrypoint_20(rdram, ctx);
        goto after_49;
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x808005FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800600: jal         0x80089818
    // 0x80800604: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_18(rdram, ctx);
        goto after_50;
    // 0x80800604: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_50:
L_80800608:
    // 0x80800608: jal         0x80089828
    // 0x8080060C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suexpression_entrypoint_20(rdram, ctx);
        goto after_51;
    // 0x8080060C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_51:
    // 0x80800610: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800614: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800618: jal         0x800897D8
    // 0x8080061C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_52;
    // 0x8080061C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_52:
    // 0x80800620: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800624: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800628: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8080062C: jr          $ra
    // 0x80800630: nop

    return;
    // 0x80800630: nop

;}
RECOMP_FUNC void func_80801290_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801290: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80801294: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80801298: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8080129C: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x808012A0: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x808012A4: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x808012A8: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x808012AC: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x808012B0: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x808012B4: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x808012B8: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x808012BC: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x808012C0: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x808012C4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x808012C8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x808012CC: jal         0x80100094
    // 0x808012D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808012D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808012D4: jal         0x800D8FF8
    // 0x808012D8: sw          $v0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x808012D8: sw          $v0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r2;
    after_1:
    // 0x808012DC: lui         $at, 0xC250
    ctx->r1 = S32(0XC250 << 16);
    // 0x808012E0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808012E4: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x808012E8: lui         $at, 0xC244
    ctx->r1 = S32(0XC244 << 16);
    // 0x808012EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808012F0: addiu       $s0, $s5, 0x44
    ctx->r16 = ADD32(ctx->r21, 0X44);
    // 0x808012F4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x808012F8: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x808012FC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80801300: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801304: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x80801308: jal         0x800EF5A0
    // 0x8080130C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800EF5A0(rdram, ctx);
        goto after_2;
    // 0x8080130C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80801310: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80801314: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801318: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8080131C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80801320: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x80801324: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801328: jal         0x800EF5A0
    // 0x8080132C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800EF5A0(rdram, ctx);
        goto after_3;
    // 0x8080132C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x80801330: lui         $at, 0x4250
    ctx->r1 = S32(0X4250 << 16);
    // 0x80801334: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80801338: lui         $at, 0xC244
    ctx->r1 = S32(0XC244 << 16);
    // 0x8080133C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801340: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80801344: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80801348: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x8080134C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801350: jal         0x800EF5A0
    // 0x80801354: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800EF5A0(rdram, ctx);
        goto after_4;
    // 0x80801354: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x80801358: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8080135C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801360: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80801364: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80801368: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x8080136C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801370: jal         0x800EF5A0
    // 0x80801374: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800EF5A0(rdram, ctx);
        goto after_5;
    // 0x80801374: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x80801378: addiu       $s0, $sp, 0x7C
    ctx->r16 = ADD32(ctx->r29, 0X7C);
    // 0x8080137C: addiu       $s1, $s5, 0x4
    ctx->r17 = ADD32(ctx->r21, 0X4);
    // 0x80801380: addiu       $s2, $sp, 0xAC
    ctx->r18 = ADD32(ctx->r29, 0XAC);
    // 0x80801384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801388:
    // 0x80801388: jal         0x800EF04C
    // 0x8080138C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EF04C(rdram, ctx);
        goto after_6;
    // 0x8080138C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x80801390: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80801394: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x80801398: bnel        $at, $zero, L_80801388
    if (ctx->r1 != 0) {
        // 0x8080139C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801388;
    }
    goto skip_0;
    // 0x8080139C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808013A0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x808013A4: lw          $s1, 0xBC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XBC);
    // 0x808013A8: addiu       $fp, $zero, 0xC
    ctx->r30 = ADD32(0, 0XC);
    // 0x808013AC: addiu       $s7, $zero, 0x3C
    ctx->r23 = ADD32(0, 0X3C);
    // 0x808013B0: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
    // 0x808013B4: addiu       $s4, $sp, 0xAC
    ctx->r20 = ADD32(ctx->r29, 0XAC);
L_808013B8:
    // 0x808013B8: lbu         $t6, 0x87C($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X87C);
    // 0x808013BC: beql        $t6, $zero, L_80801494
    if (ctx->r14 == 0) {
        // 0x808013C0: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80801494;
    }
    goto skip_1;
    // 0x808013C0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_1:
    // 0x808013C4: multu       $s3, $s6
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808013C8: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x808013CC: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x808013D0: mflo        $t8
    ctx->r24 = lo;
    // 0x808013D4: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x808013D8: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x808013DC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808013E0: jal         0x800EE7B4
    // 0x808013E4: addiu       $a2, $s0, 0x5AC
    ctx->r6 = ADD32(ctx->r16, 0X5AC);
    func_800EE7B4(rdram, ctx);
        goto after_7;
    // 0x808013E4: addiu       $a2, $s0, 0x5AC
    ctx->r6 = ADD32(ctx->r16, 0X5AC);
    after_7:
    // 0x808013E8: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x808013EC: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x808013F0: c.lt.s      $f16, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f16.fl < ctx->f24.fl;
    // 0x808013F4: nop

    // 0x808013F8: bc1fl       L_8080140C
    if (!c1cs) {
        // 0x808013FC: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_8080140C;
    }
    goto skip_2;
    // 0x808013FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_2:
    // 0x80801400: b           L_80801490
    // 0x80801404: sb          $zero, 0x87C($s1)
    MEM_B(0X87C, ctx->r17) = 0;
        goto L_80801490;
    // 0x80801404: sb          $zero, 0x87C($s1)
    MEM_B(0X87C, ctx->r17) = 0;
    // 0x80801408: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_8080140C:
    // 0x8080140C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80801410: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80801414: mul.s       $f20, $f18, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x80801418: jal         0x800DC128
    // 0x8080141C: addiu       $s2, $s0, 0x2DC
    ctx->r18 = ADD32(ctx->r16, 0X2DC);
    func_800DC128(rdram, ctx);
        goto after_8;
    // 0x8080141C: addiu       $s2, $s0, 0x2DC
    ctx->r18 = ADD32(ctx->r16, 0X2DC);
    after_8:
    // 0x80801420: lbu         $v1, 0x87C($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X87C);
    // 0x80801424: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80801428: beq         $at, $zero, L_80801434
    if (ctx->r1 == 0) {
        // 0x8080142C: subu        $t9, $v1, $v0
        ctx->r25 = SUB32(ctx->r3, ctx->r2);
            goto L_80801434;
    }
    // 0x8080142C: subu        $t9, $v1, $v0
    ctx->r25 = SUB32(ctx->r3, ctx->r2);
    // 0x80801430: sb          $t9, 0x87C($s1)
    MEM_B(0X87C, ctx->r17) = ctx->r25;
L_80801434:
    // 0x80801434: lwc1        $f4, 0x5B0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X5B0);
    // 0x80801438: addiu       $t2, $sp, 0x7C
    ctx->r10 = ADD32(ctx->r29, 0X7C);
    // 0x8080143C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801440: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x80801444: swc1        $f6, 0x5B0($s0)
    MEM_W(0X5B0, ctx->r16) = ctx->f6.u32l;
    // 0x80801448: lbu         $t0, 0x8B8($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X8B8);
    // 0x8080144C: multu       $t0, $fp
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80801450: mflo        $t1
    ctx->r9 = lo;
    // 0x80801454: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    // 0x80801458: jal         0x800EE7F8
    // 0x8080145C: nop

    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x8080145C: nop

    after_9:
    // 0x80801460: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80801464: lw          $a1, 0x44($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X44);
    // 0x80801468: lw          $a2, 0x48($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X48);
    // 0x8080146C: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x80801470: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80801474: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80801478: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8080147C: jal         0x800EF4E4
    // 0x80801480: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800EF4E4(rdram, ctx);
        goto after_10;
    // 0x80801480: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x80801484: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801488: jal         0x800EF04C
    // 0x8080148C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EF04C(rdram, ctx);
        goto after_11;
    // 0x8080148C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_11:
L_80801490:
    // 0x80801490: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80801494:
    // 0x80801494: bne         $s3, $s7, L_808013B8
    if (ctx->r19 != ctx->r23) {
        // 0x80801498: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_808013B8;
    }
    // 0x80801498: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8080149C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x808014A0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808014A4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x808014A8: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x808014AC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x808014B0: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x808014B4: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x808014B8: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x808014BC: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x808014C0: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x808014C4: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x808014C8: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x808014CC: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x808014D0: jr          $ra
    // 0x808014D4: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x808014D4: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void gsmaker_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800188: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080018C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800190: jal         0x8001ACCC
    // 0x80800194: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x80800194: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_0:
    // 0x80800198: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8080019C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x808001A0: sw          $t6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r14;
    // 0x808001A4: sw          $a1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r5;
    // 0x808001A8: sw          $a1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r5;
    // 0x808001AC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808001B0: jal         0x8001ACCC
    // 0x808001B4: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    heap_alloc(rdram, ctx);
        goto after_1;
    // 0x808001B4: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_1:
    // 0x808001B8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808001BC: addiu       $t7, $v0, 0x20
    ctx->r15 = ADD32(ctx->r2, 0X20);
    // 0x808001C0: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x808001C4: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x808001C8: sw          $t7, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r15;
    // 0x808001CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001D4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808001D8: jr          $ra
    // 0x808001DC: nop

    return;
    // 0x808001DC: nop

;}
RECOMP_FUNC void func_808009F8_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009F8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808009FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A08: jal         0x8008CABC
    // 0x80800A0C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800A0C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x80800A10: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A18: jal         0x80095738
    // 0x80800A1C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_isTrue(rdram, ctx);
        goto after_1;
    // 0x80800A1C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_1:
    // 0x80800A20: beq         $v0, $zero, L_80800A38
    if (ctx->r2 == 0) {
        // 0x80800A24: nop
    
            goto L_80800A38;
    }
    // 0x80800A24: nop

    // 0x80800A28: jal         0x8009B7C0
    // 0x80800A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009B7C0(rdram, ctx);
        goto after_2;
    // 0x80800A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800A30: b           L_80800A44
    // 0x80800A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800A44;
    // 0x80800A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800A38:
    // 0x80800A38: jal         0x80800E64
    // 0x80800A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bsmum_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x80800A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800A44:
    // 0x80800A44: jal         0x8009BB24
    // 0x80800A48: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009BB24(rdram, ctx);
        goto after_4;
    // 0x80800A48: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x80800A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A50: jal         0x80091A30
    // 0x80800A54: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_5;
    // 0x80800A54: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_5:
    // 0x80800A58: beq         $v0, $zero, L_80800A78
    if (ctx->r2 == 0) {
        // 0x80800A5C: lwc1        $f6, 0x28($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80800A78;
    }
    // 0x80800A5C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800A60: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800A64: nop

    // 0x80800A68: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800A6C: nop

    // 0x80800A70: bc1t        L_80800A88
    if (c1cs) {
        // 0x80800A74: nop
    
            goto L_80800A88;
    }
    // 0x80800A74: nop

L_80800A78:
    // 0x80800A78: jal         0x8008D544
    // 0x80800A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D544(rdram, ctx);
        goto after_6;
    // 0x80800A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800A80: bnel        $v0, $zero, L_80800A94
    if (ctx->r2 != 0) {
        // 0x80800A84: lw          $v0, 0x15C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X15C);
            goto L_80800A94;
    }
    goto skip_0;
    // 0x80800A84: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    skip_0:
L_80800A88:
    // 0x80800A88: jal         0x8009BC6C
    // 0x80800A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_7;
    // 0x80800A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800A90: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
L_80800A94:
    // 0x80800A94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800A98: beq         $v0, $at, L_80800AC0
    if (ctx->r2 == ctx->r1) {
        // 0x80800A9C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800AC0;
    }
    // 0x80800A9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800AA0: beq         $v0, $at, L_80800AFC
    if (ctx->r2 == ctx->r1) {
        // 0x80800AA4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800AFC;
    }
    // 0x80800AA4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800AA8: beq         $v0, $at, L_80800B2C
    if (ctx->r2 == ctx->r1) {
        // 0x80800AAC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800B2C;
    }
    // 0x80800AAC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800AB0: beq         $v0, $at, L_80800B2C
    if (ctx->r2 == ctx->r1) {
        // 0x80800AB4: nop
    
            goto L_80800B2C;
    }
    // 0x80800AB4: nop

    // 0x80800AB8: b           L_80800B2C
    // 0x80800ABC: nop

        goto L_80800B2C;
    // 0x80800ABC: nop

L_80800AC0:
    // 0x80800AC0: jal         0x8008B324
    // 0x80800AC4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_8;
    // 0x80800AC4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_8:
    // 0x80800AC8: beq         $v0, $zero, L_80800AD8
    if (ctx->r2 == 0) {
        // 0x80800ACC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AD8;
    }
    // 0x80800ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AD0: jal         0x808007A0
    // 0x80800AD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808007A0_bsmum(rdram, ctx);
        goto after_9;
    // 0x80800AD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
L_80800AD8:
    // 0x80800AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ADC: jal         0x8008DF8C
    // 0x80800AE0: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_10;
    // 0x80800AE0: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_10:
    // 0x80800AE4: beq         $v0, $zero, L_80800B2C
    if (ctx->r2 == 0) {
        // 0x80800AE8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B2C;
    }
    // 0x80800AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AEC: jal         0x808007A0
    // 0x80800AF0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808007A0_bsmum(rdram, ctx);
        goto after_11;
    // 0x80800AF0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x80800AF4: b           L_80800B2C
    // 0x80800AF8: nop

        goto L_80800B2C;
    // 0x80800AF8: nop

L_80800AFC:
    // 0x80800AFC: jal         0x8008CAEC
    // 0x80800B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_12;
    // 0x80800B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800B04: beq         $v0, $zero, L_80800B14
    if (ctx->r2 == 0) {
        // 0x80800B08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B14;
    }
    // 0x80800B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B0C: addiu       $t6, $zero, 0xE9
    ctx->r14 = ADD32(0, 0XE9);
    // 0x80800B10: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_80800B14:
    // 0x80800B14: jal         0x8008DF8C
    // 0x80800B18: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_8008DF8C(rdram, ctx);
        goto after_13;
    // 0x80800B18: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_13:
    // 0x80800B1C: beq         $v0, $zero, L_80800B2C
    if (ctx->r2 == 0) {
        // 0x80800B20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B2C;
    }
    // 0x80800B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B24: jal         0x808007A0
    // 0x80800B28: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808007A0_bsmum(rdram, ctx);
        goto after_14;
    // 0x80800B28: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_14:
L_80800B2C:
    // 0x80800B2C: jal         0x8008E260
    // 0x80800B30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E260(rdram, ctx);
        goto after_15;
    // 0x80800B30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800B34: beq         $v0, $zero, L_80800B40
    if (ctx->r2 == 0) {
        // 0x80800B38: addiu       $t7, $zero, 0xEE
        ctx->r15 = ADD32(0, 0XEE);
            goto L_80800B40;
    }
    // 0x80800B38: addiu       $t7, $zero, 0xEE
    ctx->r15 = ADD32(0, 0XEE);
    // 0x80800B3C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80800B40:
    // 0x80800B40: jal         0x8008E078
    // 0x80800B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_16;
    // 0x80800B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800B48: beql        $v0, $zero, L_80800B64
    if (ctx->r2 == 0) {
        // 0x80800B4C: lwc1        $f8, 0x28($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80800B64;
    }
    goto skip_1;
    // 0x80800B4C: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x80800B50: jal         0x8009FE58
    // 0x80800B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FE58(rdram, ctx);
        goto after_17;
    // 0x80800B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800B58: addiu       $t8, $zero, 0xEF
    ctx->r24 = ADD32(0, 0XEF);
    // 0x80800B5C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80800B60: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
L_80800B64:
    // 0x80800B64: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800B68: nop

    // 0x80800B6C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80800B70: nop

    // 0x80800B74: bc1fl       L_80800B94
    if (!c1cs) {
        // 0x80800B78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B94;
    }
    goto skip_2;
    // 0x80800B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800B7C: jal         0x8008E35C
    // 0x80800B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_18;
    // 0x80800B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800B84: beq         $v0, $zero, L_80800B90
    if (ctx->r2 == 0) {
        // 0x80800B88: addiu       $t9, $zero, 0xF4
        ctx->r25 = ADD32(0, 0XF4);
            goto L_80800B90;
    }
    // 0x80800B88: addiu       $t9, $zero, 0xF4
    ctx->r25 = ADD32(0, 0XF4);
    // 0x80800B8C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_80800B90:
    // 0x80800B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800B94:
    // 0x80800B94: jal         0x8009E5C8
    // 0x80800B98: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_19;
    // 0x80800B98: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_19:
    // 0x80800B9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800BA4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800BA8: jr          $ra
    // 0x80800BAC: nop

    return;
    // 0x80800BAC: nop

;}
RECOMP_FUNC void func_80800200_chtiptup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800200: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800204: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800208: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080020C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800210: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80800214: jal         0x800D0A9C
    // 0x80800218: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_0;
    // 0x80800218: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080021C: beq         $v0, $zero, L_80800244
    if (ctx->r2 == 0) {
        // 0x80800220: nop
    
            goto L_80800244;
    }
    // 0x80800220: nop

    // 0x80800224: jal         0x80088848
    // 0x80800228: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80800228: nop

    after_1:
    // 0x8080022C: bne         $v0, $zero, L_80800244
    if (ctx->r2 != 0) {
        // 0x80800230: nop
    
            goto L_80800244;
    }
    // 0x80800230: nop

    // 0x80800234: jal         0x800FFAB0
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080023C: b           L_808002B8
    // 0x80800240: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002B8;
    // 0x80800240: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800244:
    // 0x80800244: jal         0x80089F48
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiesect_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080024C: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800250: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800258: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x8080025C: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80800260: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
    // 0x80800264: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80800268: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080026C: andi        $t1, $a1, 0x1FF
    ctx->r9 = ctx->r5 & 0X1FF;
    // 0x80800270: jal         0x80089F50
    // 0x80800274: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    _subaddiesect_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800274: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_4:
    // 0x80800278: addiu       $a0, $zero, 0x359
    ctx->r4 = ADD32(0, 0X359);
    // 0x8080027C: jal         0x80089C30
    // 0x80800280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800284: beq         $v0, $zero, L_80800294
    if (ctx->r2 == 0) {
        // 0x80800288: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800294;
    }
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080028C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80800290: sw          $t2, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r10;
L_80800294:
    // 0x80800294: jal         0x80105A9C
    // 0x80800298: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    func_80105A9C(rdram, ctx);
        goto after_6;
    // 0x80800298: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    after_6:
    // 0x8080029C: jal         0x80088848
    // 0x808002A0: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_7;
    // 0x808002A0: nop

    after_7:
    // 0x808002A4: beq         $v0, $zero, L_808002B4
    if (ctx->r2 == 0) {
        // 0x808002A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002B4;
    }
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002AC: jal         0x80102424
    // 0x808002B0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x808002B0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_8:
L_808002B4:
    // 0x808002B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002B8:
    // 0x808002B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002C0: jr          $ra
    // 0x808002C4: nop

    return;
    // 0x808002C4: nop

;}
RECOMP_FUNC void _chpickups_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085898: syscall     177
    recomp_syscall_handler(rdram, ctx, 0x80085898);
    return;
    // 0x8008589C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_800E1C00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1C00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800E1C04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E1C08: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800E1C0C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800E1C10: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800E1C14: jal         0x800E42C0
    // 0x800E1C18: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_800E42C0(rdram, ctx);
        goto after_0;
    // 0x800E1C18: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x800E1C1C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800E1C20: addiu       $v1, $v1, -0x2B90
    ctx->r3 = ADD32(ctx->r3, -0X2B90);
    // 0x800E1C24: lw          $t6, 0x24($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X24);
    // 0x800E1C28: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800E1C2C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800E1C30: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800E1C34: nop

    // 0x800E1C38: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E1C3C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800E1C40: jal         0x800E3928
    // 0x800E1C44: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    func_800E3928(rdram, ctx);
        goto after_1;
    // 0x800E1C44: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x800E1C48: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800E1C4C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800E1C50: jal         0x800EE7F8
    // 0x800E1C54: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x800E1C54: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800E1C58: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800E1C5C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800E1C60: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800E1C64: addiu       $v1, $v1, -0x2B90
    ctx->r3 = ADD32(ctx->r3, -0X2B90);
    // 0x800E1C68: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x800E1C6C: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800E1C70: bc1t        L_800E1C88
    if (c1cs) {
        // 0x800E1C74: nop
    
            goto L_800E1C88;
    }
    // 0x800E1C74: nop

    // 0x800E1C78: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x800E1C7C: nop

    // 0x800E1C80: bc1fl       L_800E1C94
    if (!c1cs) {
        // 0x800E1C84: lbu         $t7, 0x21($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X21);
            goto L_800E1C94;
    }
    goto skip_0;
    // 0x800E1C84: lbu         $t7, 0x21($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X21);
    skip_0:
L_800E1C88:
    // 0x800E1C88: b           L_800E1DE4
    // 0x800E1C8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800E1DE4;
    // 0x800E1C8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E1C90: lbu         $t7, 0x21($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X21);
L_800E1C94:
    // 0x800E1C94: bnel        $t7, $zero, L_800E1D34
    if (ctx->r15 != 0) {
        // 0x800E1C98: lw          $t1, 0x80($v1)
        ctx->r9 = MEM_W(ctx->r3, 0X80);
            goto L_800E1D34;
    }
    goto skip_1;
    // 0x800E1C98: lw          $t1, 0x80($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X80);
    skip_1:
    // 0x800E1C9C: lw          $t8, 0x24($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X24);
    // 0x800E1CA0: addiu       $at, $zero, 0x4E20
    ctx->r1 = ADD32(0, 0X4E20);
    // 0x800E1CA4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x800E1CA8: bnel        $t8, $at, L_800E1D34
    if (ctx->r24 != ctx->r1) {
        // 0x800E1CAC: lw          $t1, 0x80($v1)
        ctx->r9 = MEM_W(ctx->r3, 0X80);
            goto L_800E1D34;
    }
    goto skip_2;
    // 0x800E1CAC: lw          $t1, 0x80($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X80);
    skip_2:
    // 0x800E1CB0: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x800E1CB4: lh          $t0, 0x6($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X6);
    // 0x800E1CB8: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800E1CBC: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800E1CC0: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x800E1CC4: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800E1CC8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800E1CCC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800E1CD0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800E1CD4: mul.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800E1CD8: nop

    // 0x800E1CDC: mul.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800E1CE0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800E1CE4: nop

    // 0x800E1CE8: bc1f        L_800E1CF4
    if (!c1cs) {
        // 0x800E1CEC: nop
    
            goto L_800E1CF4;
    }
    // 0x800E1CEC: nop

    // 0x800E1CF0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800E1CF4:
    // 0x800E1CF4: lwc1        $f16, 0x5D90($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5D90);
    // 0x800E1CF8: mul.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800E1CFC: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x800E1D00: nop

    // 0x800E1D04: bc1fl       L_800E1D34
    if (!c1cs) {
        // 0x800E1D08: lw          $t1, 0x80($v1)
        ctx->r9 = MEM_W(ctx->r3, 0X80);
            goto L_800E1D34;
    }
    goto skip_3;
    // 0x800E1D08: lw          $t1, 0x80($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X80);
    skip_3:
    // 0x800E1D0C: div.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800E1D10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800E1D14: lwc1        $f6, 0x5D94($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5D94);
    // 0x800E1D18: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800E1D1C: nop

    // 0x800E1D20: bc1fl       L_800E1D34
    if (!c1cs) {
        // 0x800E1D24: lw          $t1, 0x80($v1)
        ctx->r9 = MEM_W(ctx->r3, 0X80);
            goto L_800E1D34;
    }
    goto skip_4;
    // 0x800E1D24: lw          $t1, 0x80($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X80);
    skip_4:
    // 0x800E1D28: b           L_800E1DE4
    // 0x800E1D2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800E1DE4;
    // 0x800E1D2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E1D30: lw          $t1, 0x80($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X80);
L_800E1D34:
    // 0x800E1D34: bnel        $t1, $zero, L_800E1D68
    if (ctx->r9 != 0) {
        // 0x800E1D38: lbu         $t2, 0x22($v1)
        ctx->r10 = MEM_BU(ctx->r3, 0X22);
            goto L_800E1D68;
    }
    goto skip_5;
    // 0x800E1D38: lbu         $t2, 0x22($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X22);
    skip_5:
    // 0x800E1D3C: lw          $v0, 0x78($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X78);
    // 0x800E1D40: beql        $v0, $zero, L_800E1D68
    if (ctx->r2 == 0) {
        // 0x800E1D44: lbu         $t2, 0x22($v1)
        ctx->r10 = MEM_BU(ctx->r3, 0X22);
            goto L_800E1D68;
    }
    goto skip_6;
    // 0x800E1D44: lbu         $t2, 0x22($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X22);
    skip_6:
    // 0x800E1D48: lw          $a0, 0x7C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X7C);
    // 0x800E1D4C: jalr        $v0
    // 0x800E1D50: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_3;
    // 0x800E1D50: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x800E1D54: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800E1D58: addiu       $v1, $v1, -0x2B90
    ctx->r3 = ADD32(ctx->r3, -0X2B90);
    // 0x800E1D5C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800E1D60: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800E1D64: lbu         $t2, 0x22($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X22);
L_800E1D68:
    // 0x800E1D68: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x800E1D6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800E1D70: beq         $t2, $zero, L_800E1DE4
    if (ctx->r10 == 0) {
        // 0x800E1D74: nop
    
            goto L_800E1DE4;
    }
    // 0x800E1D74: nop

    // 0x800E1D78: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800E1D7C: nop

    // 0x800E1D80: sub.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x800E1D84: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800E1D88: nop

    // 0x800E1D8C: bc1f        L_800E1DE4
    if (!c1cs) {
        // 0x800E1D90: nop
    
            goto L_800E1DE4;
    }
    // 0x800E1D90: nop

    // 0x800E1D94: sub.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800E1D98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E1D9C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800E1DA0: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800E1DA4: div.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800E1DA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800E1DAC: lh          $t5, 0x1C($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X1C);
    // 0x800E1DB0: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800E1DB4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800E1DB8: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800E1DBC: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800E1DC0: nop

    // 0x800E1DC4: multu       $t5, $t4
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E1DC8: mflo        $t6
    ctx->r14 = lo;
    // 0x800E1DCC: bgez        $t6, L_800E1DDC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800E1DD0: sra         $t7, $t6, 8
        ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
            goto L_800E1DDC;
    }
    // 0x800E1DD0: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800E1DD4: addiu       $at, $t6, 0xFF
    ctx->r1 = ADD32(ctx->r14, 0XFF);
    // 0x800E1DD8: sra         $t7, $at, 8
    ctx->r15 = S32(SIGNED(ctx->r1) >> 8);
L_800E1DDC:
    // 0x800E1DDC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E1DE0: sh          $t7, -0x2B74($at)
    MEM_H(-0X2B74, ctx->r1) = ctx->r15;
L_800E1DE4:
    // 0x800E1DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E1DE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800E1DEC: jr          $ra
    // 0x800E1DF0: nop

    return;
    // 0x800E1DF0: nop

;}
RECOMP_FUNC void func_808003A8_chfactorydrums(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808003B4: jal         0x80100094
    // 0x808003B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808003B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808003BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808003C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808003C4: jal         0x80089F70
    // 0x808003C8: addiu       $a2, $a0, 0x4
    ctx->r6 = ADD32(ctx->r4, 0X4);
    _subaddierouteDll_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808003C8: addiu       $a2, $a0, 0x4
    ctx->r6 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x808003CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003D4: jr          $ra
    // 0x808003D8: nop

    return;
    // 0x808003D8: nop

;}
RECOMP_FUNC void _chmusicmenu_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086E78: syscall     463
    recomp_syscall_handler(rdram, ctx, 0x80086E78);
    return;
    // 0x80086E7C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void sucoaster_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808014C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808014CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808014D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808014D4: jal         0x80100094
    // 0x808014D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808014D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808014DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808014E0: lhu         $a1, 0x72($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X72);
    // 0x808014E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808014E8: srl         $t6, $a1, 10
    ctx->r14 = S32(U32(ctx->r5) >> 10);
    // 0x808014EC: jal         0x8010203C
    // 0x808014F0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_8010203C(rdram, ctx);
        goto after_1;
    // 0x808014F0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_1:
    // 0x808014F4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808014F8: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x808014FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801500: lh          $t7, 0xC($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XC);
    // 0x80801504: lh          $t8, 0xE($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XE);
    // 0x80801508: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080150C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80801510: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80801514: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80801518: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080151C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801520: cvt.s.w     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80801524: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80801528: c.eq.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl == ctx->f2.fl;
    // 0x8080152C: mul.s       $f14, $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x80801530: bc1tl       L_80801570
    if (c1cs) {
        // 0x80801534: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801570;
    }
    goto skip_0;
    // 0x80801534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801538: div.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8080153C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3274, 0X286C) << 16);
    // 0x80801540: lwc1        $f16, 0x286C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X286C));
    // 0x80801544: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80801548: nop

    // 0x8080154C: bc1f        L_80801558
    if (!c1cs) {
        // 0x80801550: nop
    
            goto L_80801558;
    }
    // 0x80801550: nop

    // 0x80801554: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_80801558:
    // 0x80801558: mul.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8080155C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801560: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80801564: jal         0x80101CDC
    // 0x80801568: nop

    func_80101CDC(rdram, ctx);
        goto after_2;
    // 0x80801568: nop

    after_2:
    // 0x8080156C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801570:
    // 0x80801570: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801574: jr          $ra
    // 0x80801578: nop

    return;
    // 0x80801578: nop

;}
RECOMP_FUNC void func_80800C38_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C38: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800C3C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800C40: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800C44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C48: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800C4C: lw          $a1, 0x188($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X188);
    // 0x80800C50: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800C54: jal         0x800EE7F8
    // 0x80800C58: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800C58: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_0:
    // 0x80800C5C: jal         0x800A4C48
    // 0x80800C60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A4C48(rdram, ctx);
        goto after_1;
    // 0x80800C60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800C64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C68: jal         0x800CA9D8
    // 0x80800C6C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800CA9D8(rdram, ctx);
        goto after_2;
    // 0x80800C6C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x80800C70: jal         0x8009EF28
    // 0x80800C74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_getX(rdram, ctx);
        goto after_3;
    // 0x80800C74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80800C78: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800C7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800C80: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800C84: addiu       $s0, $sp, 0x44
    ctx->r16 = ADD32(ctx->r29, 0X44);
    // 0x80800C88: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800C8C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800C90: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C98: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800C9C: jal         0x800EFA4C
    // 0x80800CA0: nop

    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x80800CA0: nop

    after_4:
    // 0x80800CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CA8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800CAC: jal         0x800EF8BC
    // 0x80800CB0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_800EF8BC(rdram, ctx);
        goto after_5;
    // 0x80800CB0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80800CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800CBC: jal         0x800EF934
    // 0x80800CC0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_800EF934(rdram, ctx);
        goto after_6;
    // 0x80800CC0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_6:
    // 0x80800CC4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800CC8: jal         0x800EF04C
    // 0x80800CCC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x80800CCC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x80800CD0: jal         0x8009EF34
    // 0x80800CD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_getY(rdram, ctx);
        goto after_8;
    // 0x80800CD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80800CD8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800CDC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800CE0: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80800CE4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800CE8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CF0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800CF4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800CF8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800CFC: jal         0x800EFA4C
    // 0x80800D00: nop

    func_800EFA4C(rdram, ctx);
        goto after_9;
    // 0x80800D00: nop

    after_9:
    // 0x80800D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D08: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800D0C: jal         0x800EF8BC
    // 0x80800D10: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_800EF8BC(rdram, ctx);
        goto after_10;
    // 0x80800D10: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_10:
    // 0x80800D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800D1C: jal         0x800EF934
    // 0x80800D20: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_800EF934(rdram, ctx);
        goto after_11;
    // 0x80800D20: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_11:
    // 0x80800D24: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800D28: jal         0x800EF04C
    // 0x80800D2C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_12;
    // 0x80800D2C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_12:
    // 0x80800D30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800D34: jal         0x8009BA9C
    // 0x80800D38: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_8009BA9C(rdram, ctx);
        goto after_13;
    // 0x80800D38: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_13:
    // 0x80800D3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D40: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800D44: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800D48: jr          $ra
    // 0x80800D4C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80800D4C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _glsplinefind_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088488: syscall     687
    recomp_syscall_handler(rdram, ctx, 0x80088488);
    return;
    // 0x8008848C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800D10_bsbeefly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D18: jal         0x80082838
    // 0x80800D1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsbee_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800D1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D20: jal         0x8080039C
    // 0x80800D24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080039C_bsbeefly(rdram, ctx);
        goto after_1;
    // 0x80800D24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800D28: lui         $a3, 0x3F99
    ctx->r7 = S32(0X3F99 << 16);
    // 0x80800D2C: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800D30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800D34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800D38: jal         0x80084C30
    // 0x80800D3C: addiu       $a2, $zero, 0xD3
    ctx->r6 = ADD32(0, 0XD3);
    _bafly_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x80800D3C: addiu       $a2, $zero, 0xD3
    ctx->r6 = ADD32(0, 0XD3);
    after_2:
    // 0x80800D40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D48: jr          $ra
    // 0x80800D4C: nop

    return;
    // 0x80800D4C: nop

;}
RECOMP_FUNC void func_808000BC_chscorepoints(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000BC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000C8: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808000CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000D4: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808000D8: beq         $t6, $at, L_808000F0
    if (ctx->r14 == ctx->r1) {
        // 0x808000DC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000F0;
    }
    // 0x808000DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000E0: beql        $t6, $at, L_80800168
    if (ctx->r14 == ctx->r1) {
        // 0x808000E4: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_80800168;
    }
    goto skip_0;
    // 0x808000E4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_0:
    // 0x808000E8: b           L_8080018C
    // 0x808000EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080018C;
    // 0x808000EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000F0:
    // 0x808000F0: jal         0x800D9078
    // 0x808000F4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x808000F4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_0:
    // 0x808000F8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808000FC: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x80800100: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800104: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800108: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080010C: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800110: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800114: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800118: jal         0x800F12D4
    // 0x8080011C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F12D4(rdram, ctx);
        goto after_1;
    // 0x8080011C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80800120: jal         0x80013970
    // 0x80800124: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013970(rdram, ctx);
        goto after_2;
    // 0x80800124: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_2:
    // 0x80800128: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8080012C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800130: nop

    // 0x80800134: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800138: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
    // 0x8080013C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80800140: beql        $t7, $zero, L_8080018C
    if (ctx->r15 == 0) {
        // 0x80800144: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080018C;
    }
    goto skip_1;
    // 0x80800144: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800148: jal         0x80089CA8
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800154: jal         0x80101FDC
    // 0x80800158: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80800158: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x8080015C: b           L_8080018C
    // 0x80800160: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080018C;
    // 0x80800160: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800164: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_80800168:
    // 0x80800168: jal         0x800D8FF8
    // 0x8080016C: swc1        $f14, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f14.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_5;
    // 0x8080016C: swc1        $f14, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f14.u32l;
    after_5:
    // 0x80800170: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80800174: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800178: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080017C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800180: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80800184: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80800188: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080018C:
    // 0x8080018C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800190: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800194: jr          $ra
    // 0x80800198: nop

    return;
    // 0x80800198: nop

;}
RECOMP_FUNC void func_80800B34_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800B38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800B40: jal         0x808005F0
    // 0x80800B44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808005F0_bskaztorpedo(rdram, ctx);
        goto after_0;
    // 0x80800B44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800B48: lui         $a3, 0x3E6C
    ctx->r7 = S32(0X3E6C << 16);
    // 0x80800B4C: ori         $a3, $a3, 0x56D6
    ctx->r7 = ctx->r7 | 0X56D6;
    // 0x80800B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B54: addiu       $a1, $zero, 0x133
    ctx->r5 = ADD32(0, 0X133);
    // 0x80800B58: jal         0x8008CD30
    // 0x80800B5C: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_playForDuration_onceSmoothStartingAt(rdram, ctx);
        goto after_1;
    // 0x80800B5C: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_1:
    // 0x80800B60: jal         0x8080009C
    // 0x80800B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_bskaztorpedo(rdram, ctx);
        goto after_2;
    // 0x80800B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B6C: jal         0x8009B94C
    // 0x80800B70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009B94C(rdram, ctx);
        goto after_3;
    // 0x80800B70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B78: jal         0x8009BA9C
    // 0x80800B7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_4;
    // 0x80800B7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B84: jal         0x80085358
    // 0x80800B88: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _batranslate_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80800B88: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80800B8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B98: jr          $ra
    // 0x80800B9C: nop

    return;
    // 0x80800B9C: nop

;}
RECOMP_FUNC void func_80800630_chfactoryempspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800630: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800634: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80800638: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080063C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800640: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800644: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80800648: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080064C: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    // 0x80800650: jal         0x80100094
    // 0x80800654: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800654: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800658: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x8080065C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80800660: slti        $at, $a2, 0x96
    ctx->r1 = SIGNED(ctx->r6) < 0X96 ? 1 : 0;
    // 0x80800664: bne         $at, $zero, L_80800688
    if (ctx->r1 != 0) {
        // 0x80800668: addiu       $t6, $a2, -0xB
        ctx->r14 = ADD32(ctx->r6, -0XB);
            goto L_80800688;
    }
    // 0x80800668: addiu       $t6, $a2, -0xB
    ctx->r14 = ADD32(ctx->r6, -0XB);
    // 0x8080066C: addiu       $at, $zero, 0xB9
    ctx->r1 = ADD32(0, 0XB9);
    // 0x80800670: beq         $a2, $at, L_808009C4
    if (ctx->r6 == ctx->r1) {
        // 0x80800674: addiu       $at, $zero, 0xBA
        ctx->r1 = ADD32(0, 0XBA);
            goto L_808009C4;
    }
    // 0x80800674: addiu       $at, $zero, 0xBA
    ctx->r1 = ADD32(0, 0XBA);
    // 0x80800678: beql        $a2, $at, L_808009E4
    if (ctx->r6 == ctx->r1) {
        // 0x8080067C: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_808009E4;
    }
    goto skip_0;
    // 0x8080067C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_0:
    // 0x80800680: b           L_808009F4
    // 0x80800684: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808009F4;
    // 0x80800684: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800688:
    // 0x80800688: slti        $at, $a2, 0x4C
    ctx->r1 = SIGNED(ctx->r6) < 0X4C ? 1 : 0;
    // 0x8080068C: bne         $at, $zero, L_808006A4
    if (ctx->r1 != 0) {
        // 0x80800690: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_808006A4;
    }
    // 0x80800690: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800694: beq         $a2, $at, L_80800754
    if (ctx->r6 == ctx->r1) {
        // 0x80800698: addiu       $a0, $zero, 0xA06
        ctx->r4 = ADD32(0, 0XA06);
            goto L_80800754;
    }
    // 0x80800698: addiu       $a0, $zero, 0xA06
    ctx->r4 = ADD32(0, 0XA06);
    // 0x8080069C: b           L_808009F4
    // 0x808006A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808009F4;
    // 0x808006A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006A4:
    // 0x808006A4: slti        $at, $a2, 0x31
    ctx->r1 = SIGNED(ctx->r6) < 0X31 ? 1 : 0;
    // 0x808006A8: bne         $at, $zero, L_808006C0
    if (ctx->r1 != 0) {
        // 0x808006AC: addiu       $at, $zero, 0x4B
        ctx->r1 = ADD32(0, 0X4B);
            goto L_808006C0;
    }
    // 0x808006AC: addiu       $at, $zero, 0x4B
    ctx->r1 = ADD32(0, 0X4B);
    // 0x808006B0: beq         $a2, $at, L_80800738
    if (ctx->r6 == ctx->r1) {
        // 0x808006B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800738;
    }
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B8: b           L_808009F4
    // 0x808006BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808009F4;
    // 0x808006BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006C0:
    // 0x808006C0: sltiu       $at, $t6, 0x26
    ctx->r1 = ctx->r14 < 0X26 ? 1 : 0;
    // 0x808006C4: beq         $at, $zero, L_808009F0
    if (ctx->r1 == 0) {
        // 0x808006C8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808009F0;
    }
    // 0x808006C8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808006CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2304, 0X2088) << 16);
    // 0x808006D0: addu        $at, $at, $t6
    gpr jr_addend_808006D8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808006D4: lw          $t6, 0x2088($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2304, 0X2088));
    // 0x808006D8: jr          $t6
    // 0x808006DC: nop

    switch (jr_addend_808006D8 >> 2) {
        case 0: goto L_80800718; break;
        case 1: goto L_808009F0; break;
        case 2: goto L_808009F0; break;
        case 3: goto L_808009F0; break;
        case 4: goto L_808009F0; break;
        case 5: goto L_808009F0; break;
        case 6: goto L_808009F0; break;
        case 7: goto L_808009F0; break;
        case 8: goto L_808009F0; break;
        case 9: goto L_808009F0; break;
        case 10: goto L_808009F0; break;
        case 11: goto L_808009F0; break;
        case 12: goto L_808009F0; break;
        case 13: goto L_808009F0; break;
        case 14: goto L_808009F0; break;
        case 15: goto L_808009F0; break;
        case 16: goto L_808009F0; break;
        case 17: goto L_808009F0; break;
        case 18: goto L_808009F0; break;
        case 19: goto L_808009F0; break;
        case 20: goto L_80800974; break;
        case 21: goto L_808009F0; break;
        case 22: goto L_808009F0; break;
        case 23: goto L_808009F0; break;
        case 24: goto L_808009F0; break;
        case 25: goto L_808009F0; break;
        case 26: goto L_808009F0; break;
        case 27: goto L_808009F0; break;
        case 28: goto L_808009F0; break;
        case 29: goto L_808009F0; break;
        case 30: goto L_808008D0; break;
        case 31: goto L_80800930; break;
        case 32: goto L_808009F0; break;
        case 33: goto L_808009F0; break;
        case 34: goto L_808009F0; break;
        case 35: goto L_808006E0; break;
        case 36: goto L_808009F0; break;
        case 37: goto L_80800700; break;
        default: switch_error(__func__, 0x808006D8, 0x80802088);
    }
    // 0x808006DC: nop

L_808006E0:
    // 0x808006E0: lh          $t7, 0x70($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X70);
    // 0x808006E4: addiu       $at, $zero, 0x1339
    ctx->r1 = ADD32(0, 0X1339);
    // 0x808006E8: bne         $t7, $at, L_808006F8
    if (ctx->r15 != ctx->r1) {
        // 0x808006EC: nop
    
            goto L_808006F8;
    }
    // 0x808006EC: nop

    // 0x808006F0: jal         0x80801038
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801038_chfactoryempspell(rdram, ctx);
        goto after_1;
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_808006F8:
    // 0x808006F8: b           L_808009F4
    // 0x808006FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808009F4;
    // 0x808006FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800700:
    // 0x80800700: lh          $t8, 0x70($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X70);
    // 0x80800704: addiu       $at, $zero, 0x1339
    ctx->r1 = ADD32(0, 0X1339);
    // 0x80800708: bnel        $t8, $at, L_8080071C
    if (ctx->r24 != ctx->r1) {
        // 0x8080070C: lw          $t9, 0x70($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X70);
            goto L_8080071C;
    }
    goto skip_1;
    // 0x8080070C: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    skip_1:
    // 0x80800710: b           L_808009F4
    // 0x80800714: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
        goto L_808009F4;
    // 0x80800714: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
L_80800718:
    // 0x80800718: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
L_8080071C:
    // 0x8080071C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800720: bne         $t9, $at, L_80800730
    if (ctx->r25 != ctx->r1) {
        // 0x80800724: nop
    
            goto L_80800730;
    }
    // 0x80800724: nop

    // 0x80800728: jal         0x80801038
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801038_chfactoryempspell(rdram, ctx);
        goto after_2;
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_80800730:
    // 0x80800730: b           L_808009F4
    // 0x80800734: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808009F4;
    // 0x80800734: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800738:
    // 0x80800738: jal         0x8008A4B0
    // 0x8080073C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x8080073C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800744: jal         0x80101FDC
    // 0x80800748: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80800748: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x8080074C: b           L_808009F4
    // 0x80800750: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808009F4;
    // 0x80800750: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800754:
    // 0x80800754: jal         0x800DA298
    // 0x80800758: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80800758: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    after_5:
    // 0x8080075C: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800760: bne         $a1, $zero, L_8080077C
    if (ctx->r5 != 0) {
        // 0x80800764: lw          $a3, 0x64($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X64);
            goto L_8080077C;
    }
    // 0x80800764: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x80800768: addiu       $a0, $zero, 0xA05
    ctx->r4 = ADD32(0, 0XA05);
    // 0x8080076C: jal         0x800DA298
    // 0x80800770: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800770: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    after_6:
    // 0x80800774: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x80800778: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
L_8080077C:
    // 0x8080077C: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    // 0x80800780: jal         0x800DA3B8
    // 0x80800784: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    func_800DA3B8(rdram, ctx);
        goto after_7;
    // 0x80800784: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    after_7:
    // 0x80800788: jal         0x800DA298
    // 0x8080078C: addiu       $a0, $zero, 0xA05
    ctx->r4 = ADD32(0, 0XA05);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x8080078C: addiu       $a0, $zero, 0xA05
    ctx->r4 = ADD32(0, 0XA05);
    after_8:
    // 0x80800790: beq         $v0, $zero, L_80800870
    if (ctx->r2 == 0) {
        // 0x80800794: lw          $a3, 0x64($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X64);
            goto L_80800870;
    }
    // 0x80800794: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x80800798: addiu       $a0, $zero, 0x3BA
    ctx->r4 = ADD32(0, 0X3BA);
    // 0x8080079C: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x808007A0: jal         0x80089C30
    // 0x808007A4: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x808007A4: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    after_9:
    // 0x808007A8: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x808007AC: addiu       $a0, $zero, 0x3BA
    ctx->r4 = ADD32(0, 0X3BA);
    // 0x808007B0: jal         0x80089C38
    // 0x808007B4: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    _subaddiefind_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x808007B4: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_10:
    // 0x808007B8: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x808007BC: jal         0x80801F30
    // 0x808007C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801F30_chfactoryempspell(rdram, ctx);
        goto after_11;
    // 0x808007C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808007C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007C8: jal         0x80101FDC
    // 0x808007CC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80101FDC(rdram, ctx);
        goto after_12;
    // 0x808007CC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_12:
    // 0x808007D0: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x808007D4: jal         0x80101FDC
    // 0x808007D8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_13;
    // 0x808007D8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_13:
    // 0x808007DC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808007E0: jal         0x80101FDC
    // 0x808007E4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_14;
    // 0x808007E4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_14:
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007EC: jal         0x80100094
    // 0x808007F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_15;
    // 0x808007F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x808007F4: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x808007F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808007FC: jal         0x800898C8
    // 0x80800800: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    _sumumbofx_entrypoint_17(rdram, ctx);
        goto after_16;
    // 0x80800800: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_16:
    // 0x80800804: jal         0x80089860
    // 0x80800808: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    _sumumbofx_entrypoint_4(rdram, ctx);
        goto after_17;
    // 0x80800808: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    after_17:
    // 0x8080080C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800810: jal         0x80089858
    // 0x80800814: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    _sumumbofx_entrypoint_3(rdram, ctx);
        goto after_18;
    // 0x80800814: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_18:
    // 0x80800818: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080081C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80800820: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x80800824: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800828: swc1        $f0, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f0.u32l;
    // 0x8080082C: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80800830: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800834: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x80800838: swc1        $f0, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->f0.u32l;
    // 0x8080083C: sb          $zero, 0x28($s0)
    MEM_B(0X28, ctx->r16) = 0;
L_80800840:
    // 0x80800840: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800844: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    // 0x80800848: bne         $v0, $a0, L_80800840
    if (ctx->r2 != ctx->r4) {
        // 0x8080084C: sb          $zero, -0xC($v1)
        MEM_B(-0XC, ctx->r3) = 0;
            goto L_80800840;
    }
    // 0x8080084C: sb          $zero, -0xC($v1)
    MEM_B(-0XC, ctx->r3) = 0;
    // 0x80800850: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x80800854: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800858: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080085C: ori         $t5, $t4, 0x8
    ctx->r13 = ctx->r12 | 0X8;
    // 0x80800860: sb          $zero, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = 0;
    // 0x80800864: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    // 0x80800868: b           L_808008A0
    // 0x8080086C: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
        goto L_808008A0;
    // 0x8080086C: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
L_80800870:
    // 0x80800870: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80800874: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80800878: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080087C: andi        $t7, $t6, 0xFFF7
    ctx->r15 = ctx->r14 & 0XFFF7;
    // 0x80800880: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    // 0x80800884: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    // 0x80800888: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800890: jal         0x80101FDC
    // 0x80800894: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_19;
    // 0x80800894: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80800898: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080089C: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
L_808008A0:
    // 0x808008A0: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x808008A4: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
L_808008A8:
    // 0x808008A8: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x808008AC: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x808008B0: addu        $t1, $a3, $t9
    ctx->r9 = ADD32(ctx->r7, ctx->r25);
    // 0x808008B4: addiu       $t2, $t8, 0x1
    ctx->r10 = ADD32(ctx->r24, 0X1);
    // 0x808008B8: slti        $at, $t2, 0xF
    ctx->r1 = SIGNED(ctx->r10) < 0XF ? 1 : 0;
    // 0x808008BC: sh          $zero, 0x50($t1)
    MEM_H(0X50, ctx->r9) = 0;
    // 0x808008C0: bne         $at, $zero, L_808008A8
    if (ctx->r1 != 0) {
        // 0x808008C4: sw          $t2, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r10;
            goto L_808008A8;
    }
    // 0x808008C4: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x808008C8: b           L_808009F4
    // 0x808008CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808009F4;
    // 0x808008CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008D0:
    // 0x808008D0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x808008D4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808008D8: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x808008DC: sw          $a0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r4;
L_808008E0:
    // 0x808008E0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x808008E4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x808008E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808008EC: lhu         $t3, 0x16($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X16);
    // 0x808008F0: lhu         $a1, 0x14($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X14);
    // 0x808008F4: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x808008F8: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x808008FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800900: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800904: jal         0x80100D24
    // 0x80800908: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_80100D24(rdram, ctx);
        goto after_20;
    // 0x80800908: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_20:
    // 0x8080090C: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x80800910: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80800914: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80800918: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8080091C: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x80800920: bne         $v1, $at, L_808008E0
    if (ctx->r3 != ctx->r1) {
        // 0x80800924: sh          $v0, 0x4E($t0)
        MEM_H(0X4E, ctx->r8) = ctx->r2;
            goto L_808008E0;
    }
    // 0x80800924: sh          $v0, 0x4E($t0)
    MEM_H(0X4E, ctx->r8) = ctx->r2;
    // 0x80800928: b           L_808009F4
    // 0x8080092C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808009F4;
    // 0x8080092C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800930:
    // 0x80800930: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800934: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80800938:
    // 0x80800938: lh          $a0, 0x50($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X50);
    // 0x8080093C: beql        $a0, $zero, L_80800960
    if (ctx->r4 == 0) {
        // 0x80800940: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_80800960;
    }
    goto skip_2;
    // 0x80800940: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    skip_2:
    // 0x80800944: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800948: jal         0x80100E18
    // 0x8080094C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_80100E18(rdram, ctx);
        goto after_21;
    // 0x8080094C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_21:
    // 0x80800950: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80800954: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80800958: sh          $zero, 0x50($v0)
    MEM_H(0X50, ctx->r2) = 0;
    // 0x8080095C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_80800960:
    // 0x80800960: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x80800964: bne         $v1, $at, L_80800938
    if (ctx->r3 != ctx->r1) {
        // 0x80800968: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_80800938;
    }
    // 0x80800968: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8080096C: b           L_808009F4
    // 0x80800970: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808009F4;
    // 0x80800970: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800974:
    // 0x80800974: lw          $t4, 0x4C($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X4C);
    // 0x80800978: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080097C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80800980: addu        $t6, $a3, $t5
    ctx->r14 = ADD32(ctx->r7, ctx->r13);
    // 0x80800984: lh          $a0, 0x50($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X50);
    // 0x80800988: jal         0x80100A74
    // 0x8080098C: sh          $a0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r4;
    func_80100A74(rdram, ctx);
        goto after_22;
    // 0x8080098C: sh          $a0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r4;
    after_22:
    // 0x80800990: jal         0x800DF818
    // 0x80800994: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF818(rdram, ctx);
        goto after_23;
    // 0x80800994: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_23:
    // 0x80800998: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8080099C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808009A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808009A4: jal         0x800DF660
    // 0x808009A8: lbu         $a3, 0x9B($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X9B);
    func_800DF660(rdram, ctx);
        goto after_24;
    // 0x808009A8: lbu         $a3, 0x9B($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X9B);
    after_24:
    // 0x808009AC: jal         0x80100AC4
    // 0x808009B0: lh          $a0, 0x3E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X3E);
    func_80100AC4(rdram, ctx);
        goto after_25;
    // 0x808009B0: lh          $a0, 0x3E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X3E);
    after_25:
    // 0x808009B4: jal         0x800DF720
    // 0x808009B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF720(rdram, ctx);
        goto after_26;
    // 0x808009B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_26:
    // 0x808009BC: b           L_808009F4
    // 0x808009C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808009F4;
    // 0x808009C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009C4:
    // 0x808009C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808009C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808009CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808009D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808009D4: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x808009D8: b           L_808009F4
    // 0x808009DC: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
        goto L_808009F4;
    // 0x808009DC: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
    // 0x808009E0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_808009E4:
    // 0x808009E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808009E8: b           L_808009F4
    // 0x808009EC: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
        goto L_808009F4;
    // 0x808009EC: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
L_808009F0:
    // 0x808009F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808009F4:
    // 0x808009F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808009F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808009FC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80800A00: jr          $ra
    // 0x80800A04: nop

    return;
    // 0x80800A04: nop

;}
RECOMP_FUNC void func_800C7574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7574: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C7578: bne         $a1, $at, L_800C7590
    if (ctx->r5 != ctx->r1) {
        // 0x800C757C: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_800C7590;
    }
    // 0x800C757C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800C7580: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C7584: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C7588: jr          $ra
    // 0x800C758C: sb          $t6, -0x5510($at)
    MEM_B(-0X5510, ctx->r1) = ctx->r14;
    return;
    // 0x800C758C: sb          $t6, -0x5510($at)
    MEM_B(-0X5510, ctx->r1) = ctx->r14;
L_800C7590:
    // 0x800C7590: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C7594: sb          $zero, -0x5510($at)
    MEM_B(-0X5510, ctx->r1) = 0;
    // 0x800C7598: jr          $ra
    // 0x800C759C: nop

    return;
    // 0x800C759C: nop

;}
RECOMP_FUNC void cheggsplode_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2176, 0X994) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x994
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2176, 0X994));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x994
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2176, 0X994));
;}
RECOMP_FUNC void baeggaim_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800358: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080035C: jal         0x80084AE8
    // 0x80800360: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _baeggcursor_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800360: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80800364: jal         0x80084B38
    // 0x80800368: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _baeggfire_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800368: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080036C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800370: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800374: jr          $ra
    // 0x80800378: nop

    return;
    // 0x80800378: nop

;}
RECOMP_FUNC void func_801042B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801042B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801042BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801042C0: jal         0x80104268
    // 0x801042C4: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    func_80104268(rdram, ctx);
        goto after_0;
    // 0x801042C4: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    after_0:
    // 0x801042C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801042CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801042D0: jr          $ra
    // 0x801042D4: nop

    return;
    // 0x801042D4: nop

;}
RECOMP_FUNC void _chbounce_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800858F8: syscall     180
    recomp_syscall_handler(rdram, ctx, 0x800858F8);
    return;
    // 0x800858FC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800344_chprisonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800344: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800348: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080034C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800350: jal         0x80100094
    // 0x80800354: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800354: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800358: lbu         $t6, 0x6($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X6);
    // 0x8080035C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800360: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80800364: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80800368: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x8080036C: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80800370: beql        $t8, $zero, L_8080043C
    if (ctx->r24 == 0) {
        // 0x80800374: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080043C;
    }
    goto skip_0;
    // 0x80800374: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800378: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x8080037C: jal         0x80800280
    // 0x80800380: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_80800280_chprisonbits(rdram, ctx);
        goto after_1;
    // 0x80800380: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_1:
    // 0x80800384: bne         $v0, $zero, L_808003A4
    if (ctx->r2 != 0) {
        // 0x80800388: nop
    
            goto L_808003A4;
    }
    // 0x80800388: nop

    // 0x8080038C: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x80800390: jal         0x80800280
    // 0x80800394: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_80800280_chprisonbits(rdram, ctx);
        goto after_2;
    // 0x80800394: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_2:
    // 0x80800398: beq         $v0, $zero, L_808003A4
    if (ctx->r2 == 0) {
        // 0x8080039C: nop
    
            goto L_808003A4;
    }
    // 0x8080039C: nop

    // 0x808003A0: sb          $zero, 0x6($s0)
    MEM_B(0X6, ctx->r16) = 0;
L_808003A4:
    // 0x808003A4: beq         $v0, $zero, L_80800404
    if (ctx->r2 == 0) {
        // 0x808003A8: nop
    
            goto L_80800404;
    }
    // 0x808003A8: nop

    // 0x808003AC: jal         0x800DA298
    // 0x808003B0: addiu       $a0, $zero, 0xD5
    ctx->r4 = ADD32(0, 0XD5);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x808003B0: addiu       $a0, $zero, 0xD5
    ctx->r4 = ADD32(0, 0XD5);
    after_3:
    // 0x808003B4: beql        $v0, $zero, L_808003C8
    if (ctx->r2 == 0) {
        // 0x808003B8: lbu         $v0, 0x6($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X6);
            goto L_808003C8;
    }
    goto skip_1;
    // 0x808003B8: lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6);
    skip_1:
    // 0x808003BC: b           L_80800438
    // 0x808003C0: sb          $zero, 0x6($s0)
    MEM_B(0X6, ctx->r16) = 0;
        goto L_80800438;
    // 0x808003C0: sb          $zero, 0x6($s0)
    MEM_B(0X6, ctx->r16) = 0;
    // 0x808003C4: lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6);
L_808003C8:
    // 0x808003C8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x808003CC: andi        $t1, $v0, 0xFF
    ctx->r9 = ctx->r2 & 0XFF;
    // 0x808003D0: sb          $t1, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r9;
    // 0x808003D4: addu        $t2, $s0, $t1
    ctx->r10 = ADD32(ctx->r16, ctx->r9);
    // 0x808003D8: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x808003DC: bnel        $t3, $zero, L_8080043C
    if (ctx->r11 != 0) {
        // 0x808003E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080043C;
    }
    goto skip_2;
    // 0x808003E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x808003E4: jal         0x800DA544
    // 0x808003E8: addiu       $a0, $zero, 0xD5
    ctx->r4 = ADD32(0, 0XD5);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x808003E8: addiu       $a0, $zero, 0xD5
    ctx->r4 = ADD32(0, 0XD5);
    after_4:
    // 0x808003EC: addiu       $a0, $zero, 0x11E
    ctx->r4 = ADD32(0, 0X11E);
    // 0x808003F0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808003F4: jal         0x80101180
    // 0x808003F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_5;
    // 0x808003F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x808003FC: b           L_8080043C
    // 0x80800400: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080043C;
    // 0x80800400: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800404:
    // 0x80800404: jal         0x80800280
    // 0x80800408: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80800280_chprisonbits(rdram, ctx);
        goto after_6;
    // 0x80800408: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x8080040C: bnel        $v0, $zero, L_80800438
    if (ctx->r2 != 0) {
        // 0x80800410: sb          $zero, 0x6($s0)
        MEM_B(0X6, ctx->r16) = 0;
            goto L_80800438;
    }
    goto skip_3;
    // 0x80800410: sb          $zero, 0x6($s0)
    MEM_B(0X6, ctx->r16) = 0;
    skip_3:
    // 0x80800414: jal         0x80800280
    // 0x80800418: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80800280_chprisonbits(rdram, ctx);
        goto after_7;
    // 0x80800418: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x8080041C: bnel        $v0, $zero, L_80800438
    if (ctx->r2 != 0) {
        // 0x80800420: sb          $zero, 0x6($s0)
        MEM_B(0X6, ctx->r16) = 0;
            goto L_80800438;
    }
    goto skip_4;
    // 0x80800420: sb          $zero, 0x6($s0)
    MEM_B(0X6, ctx->r16) = 0;
    skip_4:
    // 0x80800424: jal         0x80800280
    // 0x80800428: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80800280_chprisonbits(rdram, ctx);
        goto after_8;
    // 0x80800428: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x8080042C: beql        $v0, $zero, L_8080043C
    if (ctx->r2 == 0) {
        // 0x80800430: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080043C;
    }
    goto skip_5;
    // 0x80800430: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80800434: sb          $zero, 0x6($s0)
    MEM_B(0X6, ctx->r16) = 0;
L_80800438:
    // 0x80800438: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080043C:
    // 0x8080043C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800440: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800444: jr          $ra
    // 0x80800448: nop

    return;
    // 0x80800448: nop

;}
RECOMP_FUNC void func_80800060_chelectricfence(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800060: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800064: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800068: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080006C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800070: jal         0x800D9078
    // 0x80800074: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x80800074: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x80800078: beql        $v0, $zero, L_8080008C
    if (ctx->r2 == 0) {
        // 0x8080007C: lhu         $a2, 0x72($s0)
        ctx->r6 = MEM_HU(ctx->r16, 0X72);
            goto L_8080008C;
    }
    goto skip_0;
    // 0x8080007C: lhu         $a2, 0x72($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x80800080: jal         0x8010A590
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_1;
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800088: lhu         $a2, 0x72($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X72);
L_8080008C:
    // 0x8080008C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1180, 0X508) << 16);
    // 0x80800090: addiu       $t8, $t8, 0x508
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1180, 0X508));
    // 0x80800094: srl         $t6, $a2, 10
    ctx->r14 = S32(U32(ctx->r6) >> 10);
    // 0x80800098: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x8080009C: sltiu       $a2, $t7, 0x1
    ctx->r6 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x808000A0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808000AC: jal         0x80089D58
    // 0x808000B0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    _subaddieaudioloop_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x808000B0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_2:
    // 0x808000B4: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    // 0x808000B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000BC: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x808000C0: bnel        $t0, $at, L_808000FC
    if (ctx->r8 != ctx->r1) {
        // 0x808000C4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808000FC;
    }
    goto skip_1;
    // 0x808000C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808000C8: lw          $t1, 0x7C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X7C);
    // 0x808000CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1180, 0X4B0) << 16);
    // 0x808000D0: sll         $t3, $t1, 19
    ctx->r11 = S32(ctx->r9 << 19);
    // 0x808000D4: bgezl       $t3, L_808000FC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x808000D8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808000FC;
    }
    goto skip_2;
    // 0x808000D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x808000DC: jal         0x800DC298
    // 0x808000E0: lwc1        $f12, 0x4B0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1180, 0X4B0));
    func_800DC298(rdram, ctx);
        goto after_3;
    // 0x808000E0: lwc1        $f12, 0x4B0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1180, 0X4B0));
    after_3:
    // 0x808000E4: beq         $v0, $zero, L_808000F8
    if (ctx->r2 == 0) {
        // 0x808000E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000F8;
    }
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000EC: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x808000F0: jal         0x808002AC
    // 0x808000F4: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    chelectricfence_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x808000F4: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    after_4:
L_808000F8:
    // 0x808000F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000FC:
    // 0x808000FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800100: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800104: jr          $ra
    // 0x80800108: nop

    return;
    // 0x80800108: nop

;}
RECOMP_FUNC void func_8010AF8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010AF8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010AF90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010AF94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010AF98: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010AF9C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8010AFA0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8010AFA4: lw          $v0, 0x70($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X70);
    // 0x8010AFA8: srl         $v1, $v0, 25
    ctx->r3 = S32(U32(ctx->r2) >> 25);
    // 0x8010AFAC: beq         $v1, $zero, L_8010AFD4
    if (ctx->r3 == 0) {
        // 0x8010AFB0: addiu       $a0, $v1, -0x1
        ctx->r4 = ADD32(ctx->r3, -0X1);
            goto L_8010AFD4;
    }
    // 0x8010AFB0: addiu       $a0, $v1, -0x1
    ctx->r4 = ADD32(ctx->r3, -0X1);
    // 0x8010AFB4: sll         $a1, $v0, 22
    ctx->r5 = S32(ctx->r2 << 22);
    // 0x8010AFB8: srl         $t7, $a1, 26
    ctx->r15 = S32(U32(ctx->r5) >> 26);
    // 0x8010AFBC: jal         0x800CC6CC
    // 0x8010AFC0: addiu       $a1, $t7, -0x1
    ctx->r5 = ADD32(ctx->r15, -0X1);
    func_800CC6CC(rdram, ctx);
        goto after_0;
    // 0x8010AFC0: addiu       $a1, $t7, -0x1
    ctx->r5 = ADD32(ctx->r15, -0X1);
    after_0:
    // 0x8010AFC4: bnel        $v0, $zero, L_8010AFD8
    if (ctx->r2 != 0) {
        // 0x8010AFC8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8010AFD8;
    }
    goto skip_0;
    // 0x8010AFC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x8010AFCC: b           L_8010AFE8
    // 0x8010AFD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010AFE8;
    // 0x8010AFD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010AFD4:
    // 0x8010AFD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8010AFD8:
    // 0x8010AFD8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8010AFDC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8010AFE0: jal         0x8010AE9C
    // 0x8010AFE4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_8010AE9C(rdram, ctx);
        goto after_1;
    // 0x8010AFE4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_1:
L_8010AFE8:
    // 0x8010AFE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010AFEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010AFF0: jr          $ra
    // 0x8010AFF4: nop

    return;
    // 0x8010AFF4: nop

;}
RECOMP_FUNC void func_80802340_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802340: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80802344: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80802348: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080234C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802350: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    // 0x80802354: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80802358: jal         0x8008A0E0
    // 0x8080235C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080235C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80802360: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80802364: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802368: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x8080236C: beq         $t6, $at, L_8080238C
    if (ctx->r14 == ctx->r1) {
        // 0x80802370: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080238C;
    }
    // 0x80802370: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802374: beq         $t6, $at, L_808023F4
    if (ctx->r14 == ctx->r1) {
        // 0x80802378: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808023F4;
    }
    // 0x80802378: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080237C: beql        $t6, $at, L_80802468
    if (ctx->r14 == ctx->r1) {
        // 0x80802380: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80802468;
    }
    goto skip_0;
    // 0x80802380: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80802384: b           L_80802468
    // 0x80802388: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80802468;
    // 0x80802388: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080238C:
    // 0x8080238C: jal         0x800D9078
    // 0x80802390: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x80802390: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x80802394: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1364, 0X25A8) << 16);
    // 0x80802398: lwc1        $f4, 0x25A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1364, 0X25A8));
    // 0x8080239C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808023A0: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808023A4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808023A8: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x808023AC: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x808023B0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808023B4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808023B8: jal         0x800F12D4
    // 0x808023BC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F12D4(rdram, ctx);
        goto after_2;
    // 0x808023BC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x808023C0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808023C4: jal         0x80102FDC
    // 0x808023C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102FDC(rdram, ctx);
        goto after_3;
    // 0x808023C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808023CC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x808023D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808023D4: beql        $t7, $zero, L_80802468
    if (ctx->r15 == 0) {
        // 0x808023D8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80802468;
    }
    goto skip_1;
    // 0x808023D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808023DC: jal         0x80102424
    // 0x808023E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x808023E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808023E4: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x808023E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808023EC: b           L_80802464
    // 0x808023F0: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_80802464;
    // 0x808023F0: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_808023F4:
    // 0x808023F4: jal         0x800D8FF8
    // 0x808023F8: nop

    func_800D8FF8(rdram, ctx);
        goto after_5;
    // 0x808023F8: nop

    after_5:
    // 0x808023FC: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80802400: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80802404: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80802408: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8080240C: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80802410: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x80802414: jal         0x800138D0
    // 0x80802418: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    func_800138D0(rdram, ctx);
        goto after_6;
    // 0x80802418: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    after_6:
    // 0x8080241C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1364, 0X25AC) << 16);
    // 0x80802420: lwc1        $f4, 0x25AC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1364, 0X25AC));
    // 0x80802424: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1364, 0X25B0) << 16);
    // 0x80802428: lwc1        $f10, 0x25B0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1364, 0X25B0));
    // 0x8080242C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80802430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802434: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80802438: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080243C: jal         0x80102FDC
    // 0x80802440: nop

    func_80102FDC(rdram, ctx);
        goto after_7;
    // 0x80802440: nop

    after_7:
    // 0x80802444: jal         0x800D9078
    // 0x80802448: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_8;
    // 0x80802448: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_8:
    // 0x8080244C: beq         $v0, $zero, L_80802464
    if (ctx->r2 == 0) {
        // 0x80802450: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802464;
    }
    // 0x80802450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802454: jal         0x80102424
    // 0x80802458: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x80802458: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x8080245C: jal         0x80089CA8
    // 0x80802460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x80802460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_80802464:
    // 0x80802464: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802468:
    // 0x80802468: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080246C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80802470: jr          $ra
    // 0x80802474: nop

    return;
    // 0x80802474: nop

    // 0x80802478: nop

    // 0x8080247C: nop

;}
RECOMP_FUNC void func_800DF4B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF4B0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800DF4B4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800DF4B8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800DF4BC: lw          $t7, 0x3198($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3198);
    // 0x800DF4C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF4C4: jr          $ra
    // 0x800DF4C8: sw          $t7, -0x3074($at)
    MEM_W(-0X3074, ctx->r1) = ctx->r15;
    return;
    // 0x800DF4C8: sw          $t7, -0x3074($at)
    MEM_W(-0X3074, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_808002E8_chcablespark(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808002EC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808002F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002F4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808002F8: beq         $a1, $at, L_8080031C
    if (ctx->r5 == ctx->r1) {
        // 0x808002FC: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8080031C;
    }
    // 0x808002FC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800300: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800304: beq         $a1, $at, L_80800380
    if (ctx->r5 == ctx->r1) {
        // 0x80800308: addiu       $at, $zero, 0x97
        ctx->r1 = ADD32(0, 0X97);
            goto L_80800380;
    }
    // 0x80800308: addiu       $at, $zero, 0x97
    ctx->r1 = ADD32(0, 0X97);
    // 0x8080030C: beql        $a1, $at, L_80800394
    if (ctx->r5 == ctx->r1) {
        // 0x80800310: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800394;
    }
    goto skip_0;
    // 0x80800310: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80800314: b           L_808003FC
    // 0x80800318: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003FC;
    // 0x80800318: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080031C:
    // 0x8080031C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800320: jal         0x80800828
    // 0x80800324: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_80800828_chcablespark(rdram, ctx);
        goto after_0;
    // 0x80800324: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800328: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8080032C: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x80800330: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
    // 0x80800334: lbu         $t8, 0x64($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X64);
    // 0x80800338: lhu         $t1, 0x76($a3)
    ctx->r9 = MEM_HU(ctx->r7, 0X76);
    // 0x8080033C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800340: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x80800344: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80800348: srl         $t2, $t1, 7
    ctx->r10 = S32(U32(ctx->r9) >> 7);
    // 0x8080034C: bne         $t2, $at, L_808003F8
    if (ctx->r10 != ctx->r1) {
        // 0x80800350: sb          $t0, 0x64($a3)
        MEM_B(0X64, ctx->r7) = ctx->r8;
            goto L_808003F8;
    }
    // 0x80800350: sb          $t0, 0x64($a3)
    MEM_B(0X64, ctx->r7) = ctx->r8;
    // 0x80800354: andi        $t4, $t0, 0xFE
    ctx->r12 = ctx->r8 & 0XFE;
    // 0x80800358: sb          $t4, 0x64($a3)
    MEM_B(0X64, ctx->r7) = ctx->r12;
    // 0x8080035C: jal         0x80800828
    // 0x80800360: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_80800828_chcablespark(rdram, ctx);
        goto after_1;
    // 0x80800360: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800364: beq         $v0, $zero, L_808003F8
    if (ctx->r2 == 0) {
        // 0x80800368: lw          $a3, 0x30($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X30);
            goto L_808003F8;
    }
    // 0x80800368: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8080036C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800370: jal         0x8008A4B0
    // 0x80800374: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800374: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800378: b           L_808003FC
    // 0x8080037C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003FC;
    // 0x8080037C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800380:
    // 0x80800380: jal         0x80800A48
    // 0x80800384: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800A48_chcablespark(rdram, ctx);
        goto after_3;
    // 0x80800384: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x80800388: b           L_808003FC
    // 0x8080038C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003FC;
    // 0x8080038C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800390: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80800394:
    // 0x80800394: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800398: lwc1        $f6, 0x38($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X38);
    // 0x8080039C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808003A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808003A4: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808003A8: lw          $a1, 0x48($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X48);
    // 0x808003AC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808003B0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x808003B4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x808003B8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808003BC: jal         0x800EEB9C
    // 0x808003C0: nop

    func_800EEB9C(rdram, ctx);
        goto after_4;
    // 0x808003C0: nop

    after_4:
    // 0x808003C4: lui         $at, 0x432F
    ctx->r1 = S32(0X432F << 16);
    // 0x808003C8: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808003CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808003D0: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808003D4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808003D8: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x808003DC: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x808003E0: jal         0x80101010
    // 0x808003E4: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    func_80101010(rdram, ctx);
        goto after_5;
    // 0x808003E4: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x808003E8: b           L_808003FC
    // 0x808003EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003FC;
    // 0x808003EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808003F0: b           L_808003FC
    // 0x808003F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003FC;
    // 0x808003F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003F8:
    // 0x808003F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003FC:
    // 0x808003FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800400: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800404: jr          $ra
    // 0x80800408: nop

    return;
    // 0x80800408: nop

;}
RECOMP_FUNC void func_8080002C_gcdialogexec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080002C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800030: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800034: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800038: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080003C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800040: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800044: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800048: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8080004C: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
L_80800050:
    // 0x80800050: jal         0x80087AE0
    // 0x80800054: lw          $a0, 0x120($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X120);
    _gczoombox_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800054: lw          $a0, 0x120($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X120);
    after_0:
    // 0x80800058: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8080005C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800060: bne         $s1, $s2, L_80800050
    if (ctx->r17 != ctx->r18) {
        // 0x80800064: sw          $zero, 0x11C($s0)
        MEM_W(0X11C, ctx->r16) = 0;
            goto L_80800050;
    }
    // 0x80800064: sw          $zero, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = 0;
    // 0x80800068: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8080006C: lw          $a0, 0x12C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X12C);
    // 0x80800070: beql        $a0, $zero, L_8080008C
    if (ctx->r4 == 0) {
        // 0x80800074: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080008C;
    }
    goto skip_0;
    // 0x80800074: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800078: jal         0x80087AE0
    // 0x8080007C: nop

    _gczoombox_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080007C: nop

    after_1:
    // 0x80800080: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80800084: sw          $zero, 0x12C($t7)
    MEM_W(0X12C, ctx->r15) = 0;
    // 0x80800088: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080008C:
    // 0x8080008C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800090: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800094: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800098: jr          $ra
    // 0x8080009C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8080009C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void chlavaarchgrill3switches_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2036, 0X280) << 16);
    // 0x808001E4: jr          $ra
    // 0x808001E8: addiu       $v0, $v0, 0x280
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2036, 0X280));
    return;
    // 0x808001E8: addiu       $v0, $v0, 0x280
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2036, 0X280));
    // 0x808001EC: nop

;}
RECOMP_FUNC void func_800BF68C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF68C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BF690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BF694: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BF698: jal         0x80088100
    // 0x800BF69C: addiu       $a0, $a0, -0x7A50
    ctx->r4 = ADD32(ctx->r4, -0X7A50);
    _gcmapDll_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x800BF69C: addiu       $a0, $a0, -0x7A50
    ctx->r4 = ADD32(ctx->r4, -0X7A50);
    after_0:
    // 0x800BF6A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BF6A4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800BF6A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BF6AC: sb          $t6, -0x79CC($at)
    MEM_B(-0X79CC, ctx->r1) = ctx->r14;
    // 0x800BF6B0: jr          $ra
    // 0x800BF6B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800BF6B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _bswalk_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084248: syscall     107
    recomp_syscall_handler(rdram, ctx, 0x80084248);
    return;
    // 0x8008424C: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void _chcoderoombits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086298: syscall     299
    recomp_syscall_handler(rdram, ctx, 0x80086298);
    return;
    // 0x8008629C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808004B0_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004B8: jal         0x80100094
    // 0x808004BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808004BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808004C0: lbu         $t6, 0x28($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X28);
    // 0x808004C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808004C8: beql        $t6, $zero, L_808004E4
    if (ctx->r14 == 0) {
        // 0x808004CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808004E4;
    }
    goto skip_0;
    // 0x808004CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808004D0: jal         0x800856B8
    // 0x808004D4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _capod_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808004D4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808004D8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808004DC: sb          $zero, 0x28($v1)
    MEM_B(0X28, ctx->r3) = 0;
    // 0x808004E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004E4:
    // 0x808004E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004E8: jr          $ra
    // 0x808004EC: nop

    return;
    // 0x808004EC: nop

;}
