#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _baswim_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800852C0: syscall     156
    recomp_syscall_handler(rdram, ctx, 0x800852C0);
    return;
    // 0x800852C4: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void _bsbtrot_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082C00: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082C00);
    return;
    // 0x80082C04: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800B44_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B44: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800B48: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800B4C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80800B50: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800B54: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800B58: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800B5C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800B60: jal         0x80802484
    // 0x80800B64: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    func_80802484_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80800B64: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800B68: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80800B6C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800B70: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800B74: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x80800B78: jal         0x80800978
    // 0x80800B7C: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    func_80800978_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80800B7C: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    after_1:
    // 0x80800B80: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800B84: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800B88: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80800B8C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80800B90: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800B94: lbu         $a1, 0x2B($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X2B);
    // 0x80800B98: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BA0: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x80800BA4: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x80800BA8: jal         0x800E0AFC
    // 0x80800BAC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_2;
    // 0x80800BAC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80800BB0: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80800BB4: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800BB8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800BBC: lbu         $a1, 0x2F($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X2F);
    // 0x80800BC0: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x80800BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BC8: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x80800BCC: jal         0x800E0AFC
    // 0x80800BD0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_3;
    // 0x80800BD0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x80800BD4: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x80800BD8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800BDC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800BE0: lw          $v0, 0x188($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X188);
    // 0x80800BE4: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x80800BE8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800BEC: lwc1        $f8, 0x44($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80800BF0: lwc1        $f16, 0x60($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X60);
    // 0x80800BF4: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80800BF8: mul.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C00: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    // 0x80800C04: mul.s       $f22, $f16, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800C08: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80800C0C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80800C10: jal         0x800E0AFC
    // 0x80800C14: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_4;
    // 0x80800C14: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    after_4:
    // 0x80800C18: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80800C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C20: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x80800C24: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80800C28: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80800C2C: jal         0x800E0AFC
    // 0x80800C30: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_5;
    // 0x80800C30: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    after_5:
    // 0x80800C34: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80800C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C3C: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x80800C40: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80800C44: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80800C48: jal         0x800E0AFC
    // 0x80800C4C: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_6;
    // 0x80800C4C: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    after_6:
    // 0x80800C50: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80800C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C58: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x80800C5C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80800C60: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80800C64: jal         0x800E0AFC
    // 0x80800C68: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_7;
    // 0x80800C68: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    after_7:
    // 0x80800C6C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800C70: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800C74: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800C78: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80800C7C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80800C80: jr          $ra
    // 0x80800C84: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80800C84: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void _chfantasycannon_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800876C0: syscall     606
    recomp_syscall_handler(rdram, ctx, 0x800876C0);
    return;
    // 0x800876C4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8001E34C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E34C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E350: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E354: jal         0x8001D96C
    // 0x8001E358: nop

    func_8001D96C(rdram, ctx);
        goto after_0;
    // 0x8001E358: nop

    after_0:
    // 0x8001E35C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001E360: jal         0x8001D37C
    // 0x8001E364: addiu       $a0, $a0, 0x187C
    ctx->r4 = ADD32(ctx->r4, 0X187C);
    func_8001D37C(rdram, ctx);
        goto after_1;
    // 0x8001E364: addiu       $a0, $a0, 0x187C
    ctx->r4 = ADD32(ctx->r4, 0X187C);
    after_1:
    // 0x8001E368: jal         0x8001E2A0
    // 0x8001E36C: nop

    func_8001E2A0(rdram, ctx);
        goto after_2;
    // 0x8001E36C: nop

    after_2:
    // 0x8001E370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E374: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E378: jr          $ra
    // 0x8001E37C: nop

    return;
    // 0x8001E37C: nop

;}
RECOMP_FUNC void suautobaddies_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002FC: jal         0x800D1A04
    // 0x80800300: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    func_800D1A04(rdram, ctx);
        goto after_0;
    // 0x80800300: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    after_0:
    // 0x80800304: beq         $v0, $zero, L_80800340
    if (ctx->r2 == 0) {
        // 0x80800308: addiu       $a0, $zero, 0x4B
        ctx->r4 = ADD32(0, 0X4B);
            goto L_80800340;
    }
    // 0x80800308: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    // 0x8080030C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800310: jal         0x800D1864
    // 0x80800314: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800D1864(rdram, ctx);
        goto after_1;
    // 0x80800314: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80800318: jal         0x800D1A04
    // 0x8080031C: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    func_800D1A04(rdram, ctx);
        goto after_2;
    // 0x8080031C: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    after_2:
    // 0x80800320: beq         $v0, $zero, L_8080035C
    if (ctx->r2 == 0) {
        // 0x80800324: lui         $at, 0x3FC0
        ctx->r1 = S32(0X3FC0 << 16);
            goto L_8080035C;
    }
    // 0x80800324: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800328: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080032C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80800330: jal         0x800C9DAC
    // 0x80800334: addiu       $a1, $a1, -0x6040
    ctx->r5 = ADD32(ctx->r5, -0X6040);
    func_800C9DAC(rdram, ctx);
        goto after_3;
    // 0x80800334: addiu       $a1, $a1, -0x6040
    ctx->r5 = ADD32(ctx->r5, -0X6040);
    after_3:
    // 0x80800338: b           L_80800360
    // 0x8080033C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800360;
    // 0x8080033C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800340:
    // 0x80800340: jal         0x800D1A04
    // 0x80800344: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    func_800D1A04(rdram, ctx);
        goto after_4;
    // 0x80800344: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    after_4:
    // 0x80800348: beq         $v0, $zero, L_8080035C
    if (ctx->r2 == 0) {
        // 0x8080034C: addiu       $a0, $zero, 0x4C
        ctx->r4 = ADD32(0, 0X4C);
            goto L_8080035C;
    }
    // 0x8080034C: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    // 0x80800350: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800354: jal         0x800D1864
    // 0x80800358: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800D1864(rdram, ctx);
        goto after_5;
    // 0x80800358: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
L_8080035C:
    // 0x8080035C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800360:
    // 0x80800360: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800364: jr          $ra
    // 0x80800368: nop

    return;
    // 0x80800368: nop

;}
RECOMP_FUNC void func_80096768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096768: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009676C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80096770: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80096774: jal         0x8009C128
    // 0x80096778: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80096778: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8009677C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80096780: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80096784: jal         0x800D4D5C
    // 0x80096788: lw          $a1, 0x94($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X94);
    func_800D4D5C(rdram, ctx);
        goto after_1;
    // 0x80096788: lw          $a1, 0x94($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X94);
    after_1:
    // 0x8009678C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80096790: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80096794: jr          $ra
    // 0x80096798: nop

    return;
    // 0x80096798: nop

;}
RECOMP_FUNC void func_80800F50_chmusicmenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F58: jal         0x80800714
    // 0x80800F5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800714_chmusicmenu(rdram, ctx);
        goto after_0;
    // 0x80800F5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800F60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800F64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800F68: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800F6C: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800F70: beq         $t6, $at, L_80800F80
    if (ctx->r14 == ctx->r1) {
        // 0x80800F74: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800F80;
    }
    // 0x80800F74: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800F78: bnel        $t6, $at, L_80800F8C
    if (ctx->r14 != ctx->r1) {
        // 0x80800F7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800F8C;
    }
    goto skip_0;
    // 0x80800F7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80800F80:
    // 0x80800F80: jal         0x80087CC8
    // 0x80800F84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800F84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F8C:
    // 0x80800F8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F90: jr          $ra
    // 0x80800F94: nop

    return;
    // 0x80800F94: nop

;}
RECOMP_FUNC void bswalk_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800330: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800334: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800338: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8080033C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800340: jal         0x8008CABC
    // 0x80800344: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800344: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800348: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080034C: jal         0x8009E710
    // 0x80800350: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_1;
    // 0x80800350: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800354: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800358: bnel        $v0, $at, L_8080037C
    if (ctx->r2 != ctx->r1) {
        // 0x8080035C: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_8080037C;
    }
    goto skip_0;
    // 0x8080035C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_0:
    // 0x80800360: jal         0x8008AEDC
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008AEDC(rdram, ctx);
        goto after_2;
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800368: jal         0x8008C0C8
    // 0x8080036C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008C0C8(rdram, ctx);
        goto after_3;
    // 0x8080036C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800370: b           L_80800384
    // 0x80800374: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
        goto L_80800384;
    // 0x80800374: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80800378: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8080037C:
    // 0x8080037C: nop

    // 0x80800380: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
L_80800384:
    // 0x80800384: jal         0x8008AF24
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_4;
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800390: jal         0x8008AED4
    // 0x80800394: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setIndex(rdram, ctx);
        goto after_5;
    // 0x80800394: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80800398: lui         $a1, 0x3EDC
    ctx->r5 = S32(0X3EDC << 16);
    // 0x8080039C: ori         $a1, $a1, 0x28F6
    ctx->r5 = ctx->r5 | 0X28F6;
    // 0x808003A0: jal         0x8008B1BC
    // 0x808003A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_6;
    // 0x808003A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003AC: jal         0x8008B24C
    // 0x808003B0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    anctrl_setStart(rdram, ctx);
        goto after_7;
    // 0x808003B0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B8: jal         0x8008B134
    // 0x808003BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_8;
    // 0x808003BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x808003C0: jal         0x8008B064
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_9;
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808003C8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808003CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808003D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808003D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808003DC: jal         0x8009FFD8
    // 0x808003E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_10;
    // 0x808003E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x808003E4: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x808003E8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808003EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003F0: jal         0x8008C9BC
    // 0x808003F4: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_11;
    // 0x808003F4: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_11:
    // 0x808003F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(435, 0X14F8) << 16);
    // 0x808003FC: lwc1        $f6, 0x14F8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(435, 0X14F8));
    // 0x80800400: lui         $a3, 0x3FE6
    ctx->r7 = S32(0X3FE6 << 16);
    // 0x80800404: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800408: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080040C: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x80800410: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    // 0x80800414: jal         0x8008C9F0
    // 0x80800418: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_12;
    // 0x80800418: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_12:
    // 0x8080041C: jal         0x8009F1E0
    // 0x80800420: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_resetZones(rdram, ctx);
        goto after_13;
    // 0x80800420: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80800424: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800428: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8080042C: jal         0x800A2EDC
    // 0x80800430: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A2EDC(rdram, ctx);
        goto after_14;
    // 0x80800430: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x80800434: jal         0x8008E0E8
    // 0x80800438: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8008E0E8(rdram, ctx);
        goto after_15;
    // 0x80800438: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x8080043C: beq         $v0, $zero, L_8080044C
    if (ctx->r2 == 0) {
        // 0x80800440: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080044C;
    }
    // 0x80800440: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800444: jal         0x80084788
    // 0x80800448: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _bapackctrl_entrypoint_5(rdram, ctx);
        goto after_16;
    // 0x80800448: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_16:
L_8080044C:
    // 0x8080044C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800450: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800454: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800458: jr          $ra
    // 0x8080045C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8080045C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void bsstonehead_entrypoint_38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013C0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808013C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808013C8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808013CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808013D0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x808013D4: jal         0x80085300
    // 0x808013D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_get(rdram, ctx);
        goto after_0;
    // 0x808013D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808013DC: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x808013E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808013E4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808013E8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808013EC: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    // 0x808013F0: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x808013F4: jal         0x800F10B4
    // 0x808013F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x808013F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x808013FC: jal         0x800D8FF8
    // 0x80801400: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80801400: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80801404: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80801408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080140C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80801410: jal         0x8009C990
    // 0x80801414: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    yaw_getIdeal(rdram, ctx);
        goto after_3;
    // 0x80801414: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80801418: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8080141C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801420: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80801424: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80801428: jal         0x8009C914
    // 0x8080142C: nop

    yaw_setIdeal(rdram, ctx);
        goto after_4;
    // 0x8080142C: nop

    after_4:
    // 0x80801430: jal         0x8009C974
    // 0x80801434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_5;
    // 0x80801434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080143C: jal         0x800852F0
    // 0x80801440: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_decrement(rdram, ctx);
        goto after_6;
    // 0x80801440: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80801444: beq         $v0, $zero, L_80801454
    if (ctx->r2 == 0) {
        // 0x80801448: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801454;
    }
    // 0x80801448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080144C: addiu       $t6, $zero, 0xB3
    ctx->r14 = ADD32(0, 0XB3);
    // 0x80801450: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_80801454:
    // 0x80801454: jal         0x8009E5C8
    // 0x80801458: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_7;
    // 0x80801458: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x8080145C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801460: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801464: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801468: jr          $ra
    // 0x8080146C: nop

    return;
    // 0x8080146C: nop

;}
RECOMP_FUNC void func_808006B4_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808006B8: bnel        $a1, $at, L_808006CC
    if (ctx->r5 != ctx->r1) {
        // 0x808006BC: lhu         $t6, 0x12($a0)
        ctx->r14 = MEM_HU(ctx->r4, 0X12);
            goto L_808006CC;
    }
    goto skip_0;
    // 0x808006BC: lhu         $t6, 0x12($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X12);
    skip_0:
    // 0x808006C0: jr          $ra
    // 0x808006C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x808006C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808006C8: lhu         $t6, 0x12($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X12);
L_808006CC:
    // 0x808006CC: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x808006D0: xor         $v1, $a1, $t7
    ctx->r3 = ctx->r5 ^ ctx->r15;
    // 0x808006D4: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x808006D8: jr          $ra
    // 0x808006DC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x808006DC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void _bskazshoesspringjump_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083598: syscall     67
    recomp_syscall_handler(rdram, ctx, 0x80083598);
    return;
    // 0x8008359C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800014_chmumbopad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800014: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080001C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800020: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800024: jal         0x80088280
    // 0x80800028: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    _gccubesearch_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800028: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8080002C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800030: jal         0x80088C00
    // 0x80800034: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800034: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080003C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800040: jr          $ra
    // 0x80800044: nop

    return;
    // 0x80800044: nop

;}
RECOMP_FUNC void _chscorepoints_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086460: syscall     325
    recomp_syscall_handler(rdram, ctx, 0x80086460);
    return;
    // 0x80086464: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808000D0_gcgamefix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D8: jal         0x800DA298
    // 0x808000DC: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808000DC: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    after_0:
    // 0x808000E0: beql        $v0, $zero, L_808000F4
    if (ctx->r2 == 0) {
        // 0x808000E4: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_808000F4;
    }
    goto skip_0;
    // 0x808000E4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    skip_0:
    // 0x808000E8: jal         0x800DA544
    // 0x808000EC: addiu       $a0, $zero, 0x507
    ctx->r4 = ADD32(0, 0X507);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x808000EC: addiu       $a0, $zero, 0x507
    ctx->r4 = ADD32(0, 0X507);
    after_1:
    // 0x808000F0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_808000F4:
    // 0x808000F4: jal         0x800D0A9C
    // 0x808000F8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0A9C(rdram, ctx);
        goto after_2;
    // 0x808000F8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x808000FC: beql        $v0, $zero, L_80800110
    if (ctx->r2 == 0) {
        // 0x80800100: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800110;
    }
    goto skip_1;
    // 0x80800100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800104: jal         0x800DA544
    // 0x80800108: addiu       $a0, $zero, 0x504
    ctx->r4 = ADD32(0, 0X504);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x80800108: addiu       $a0, $zero, 0x504
    ctx->r4 = ADD32(0, 0X504);
    after_3:
    // 0x8080010C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800110:
    // 0x80800110: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800114: jr          $ra
    // 0x80800118: nop

    return;
    // 0x80800118: nop

;}
RECOMP_FUNC void func_800CE7DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE7DC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800CE7E0: addiu       $v0, $v0, -0x4FD0
    ctx->r2 = ADD32(ctx->r2, -0X4FD0);
    // 0x800CE7E4: lbu         $a0, 0x120($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X120);
    // 0x800CE7E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CE7EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CE7F0: beql        $a0, $zero, L_800CE810
    if (ctx->r4 == 0) {
        // 0x800CE7F4: lbu         $t6, 0x121($v0)
        ctx->r14 = MEM_BU(ctx->r2, 0X121);
            goto L_800CE810;
    }
    goto skip_0;
    // 0x800CE7F4: lbu         $t6, 0x121($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X121);
    skip_0:
    // 0x800CE7F8: jal         0x800C2FDC
    // 0x800CE7FC: nop

    func_800C2FDC(rdram, ctx);
        goto after_0;
    // 0x800CE7FC: nop

    after_0:
    // 0x800CE800: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800CE804: addiu       $v0, $v0, -0x4FD0
    ctx->r2 = ADD32(ctx->r2, -0X4FD0);
    // 0x800CE808: sb          $zero, 0x120($v0)
    MEM_B(0X120, ctx->r2) = 0;
    // 0x800CE80C: lbu         $t6, 0x121($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X121);
L_800CE810:
    // 0x800CE810: beql        $t6, $zero, L_800CE830
    if (ctx->r14 == 0) {
        // 0x800CE814: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CE830;
    }
    goto skip_1;
    // 0x800CE814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800CE818: jal         0x800FC74C
    // 0x800CE81C: addiu       $a0, $zero, 0x92
    ctx->r4 = ADD32(0, 0X92);
    func_800FC74C(rdram, ctx);
        goto after_1;
    // 0x800CE81C: addiu       $a0, $zero, 0x92
    ctx->r4 = ADD32(0, 0X92);
    after_1:
    // 0x800CE820: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800CE824: addiu       $v0, $v0, -0x4FD0
    ctx->r2 = ADD32(ctx->r2, -0X4FD0);
    // 0x800CE828: sb          $zero, 0x121($v0)
    MEM_B(0X121, ctx->r2) = 0;
    // 0x800CE82C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CE830:
    // 0x800CE830: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CE834: jr          $ra
    // 0x800CE838: nop

    return;
    // 0x800CE838: nop

;}
RECOMP_FUNC void _bawasher_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085428: syscall     161
    recomp_syscall_handler(rdram, ctx, 0x80085428);
    return;
    // 0x8008542C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800A3DAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3DAC: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x800A3DB0: jr          $ra
    // 0x800A3DB4: lbu         $v0, 0x2($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X2);
    return;
    // 0x800A3DB4: lbu         $v0, 0x2($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X2);
;}
RECOMP_FUNC void func_80803B48_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803B48: jr          $ra
    // 0x80803B4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80803B4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800A586C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A586C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A5870: lw          $t6, -0x6AC0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6AC0);
    // 0x800A5874: jr          $ra
    // 0x800A5878: lw          $v0, 0x34($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X34);
    return;
    // 0x800A5878: lw          $v0, 0x34($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X34);
;}
RECOMP_FUNC void _subaddiefx_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A058: syscall     824
    recomp_syscall_handler(rdram, ctx, 0x8008A058);
    return;
    // 0x8008A05C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bsbbarge_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005E4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808005E8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(57, 0X630) << 16);
    // 0x808005EC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808005F0: jr          $ra
    // 0x808005F4: lw          $v0, 0x630($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(57, 0X630));
    return;
    // 0x808005F4: lw          $v0, 0x630($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(57, 0X630));
;}
RECOMP_FUNC void _cadbfunc_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085660: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x80085660);
    return;
    // 0x80085664: addi        $t0, $zero, 0x70
    ctx->r8 = ADD32(0, 0X70);
;}
RECOMP_FUNC void bsbfly_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019D8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808019DC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(96, 0X1DA8) << 16);
    // 0x808019E0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808019E4: jr          $ra
    // 0x808019E8: lw          $v0, 0x1DA8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(96, 0X1DA8));
    return;
    // 0x808019E8: lw          $v0, 0x1DA8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(96, 0X1DA8));
;}
RECOMP_FUNC void _bsfirstp_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084360: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x80084360);
    return;
    // 0x80084364: addi        $t0, $zero, 0x6C
    ctx->r8 = ADD32(0, 0X6C);
;}
RECOMP_FUNC void _suegg_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A3E8: syscall     841
    recomp_syscall_handler(rdram, ctx, 0x8008A3E8);
    return;
    // 0x8008A3EC: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void _chpowerhutwitchy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086068: syscall     275
    recomp_syscall_handler(rdram, ctx, 0x80086068);
    return;
    // 0x8008606C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _sucoasterfly_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089EF0: syscall     813
    recomp_syscall_handler(rdram, ctx, 0x80089EF0);
    return;
    // 0x80089EF4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void chbadbeehive_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1760, 0XB1C) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xB1C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1760, 0XB1C));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xB1C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1760, 0XB1C));
;}
RECOMP_FUNC void func_800DC324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC324: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DC328: jr          $ra
    // 0x800DC32C: sw          $a0, -0x3810($at)
    MEM_W(-0X3810, ctx->r1) = ctx->r4;
    return;
    // 0x800DC32C: sw          $a0, -0x3810($at)
    MEM_W(-0X3810, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void _glglobalsettings_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800886C8: syscall     699
    recomp_syscall_handler(rdram, ctx, 0x800886C8);
    return;
    // 0x800886CC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080010C_chfloorbubbles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080010C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800110: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80800114: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80800118: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8080011C: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80800120: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80800124: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80800128: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8080012C: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80800130: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80800134: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80800138: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8080013C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800140: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800144: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800148: jal         0x80100094
    // 0x8080014C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080014C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800150: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80800154: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80800158: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080015C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800160: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1716, 0X264) << 16);
    // 0x80800164: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80800168: lwc1        $f24, 0x264($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1716, 0X264));
    // 0x8080016C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800170: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800174: addiu       $s3, $s6, 0x4
    ctx->r19 = ADD32(ctx->r22, 0X4);
    // 0x80800178: addiu       $s2, $v0, 0x4
    ctx->r18 = ADD32(ctx->r2, 0X4);
    // 0x8080017C: addiu       $s5, $zero, 0x78
    ctx->r21 = ADD32(0, 0X78);
    // 0x80800180: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
L_80800184:
    // 0x80800184: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80800188: jal         0x800DC178
    // 0x8080018C: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x8080018C: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_1:
    // 0x80800190: lhu         $t6, 0x76($s6)
    ctx->r14 = MEM_HU(ctx->r22, 0X76);
    // 0x80800194: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800198: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x8080019C: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808001A0: multu       $t7, $s4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808001A4: mflo        $t8
    ctx->r24 = lo;
    // 0x808001A8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x808001AC: jal         0x800DC178
    // 0x808001B0: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x808001B0: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    after_2:
    // 0x808001B4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808001B8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808001BC: jal         0x800EEB9C
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EEB9C(rdram, ctx);
        goto after_3;
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: jal         0x800EF04C
    // 0x808001CC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EF04C(rdram, ctx);
        goto after_4;
    // 0x808001CC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_4:
    // 0x808001D0: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x808001D4: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001DC: jal         0x80089830
    // 0x808001E0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    _subaddie3d_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x808001E0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_5:
    // 0x808001E4: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x808001E8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x808001EC: bne         $s1, $s5, L_80800184
    if (ctx->r17 != ctx->r21) {
        // 0x808001F0: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_80800184;
    }
    // 0x808001F0: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x808001F4: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808001F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808001FC: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80800200: jal         0x80089838
    // 0x80800204: addiu       $a3, $s6, 0x1C
    ctx->r7 = ADD32(ctx->r22, 0X1C);
    _subaddie3d_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x80800204: addiu       $a3, $s6, 0x1C
    ctx->r7 = ADD32(ctx->r22, 0X1C);
    after_6:
    // 0x80800208: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8080020C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800210: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800214: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800218: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8080021C: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80800220: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80800224: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80800228: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8080022C: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80800230: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80800234: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80800238: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x8080023C: jr          $ra
    // 0x80800240: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80800240: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_808008D4_chbiggafoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008DC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1216, 0X1198) << 16);
    // 0x808008E0: addiu       $a2, $a2, 0x1198
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1216, 0X1198));
    // 0x808008E4: jal         0x8008A1E8
    // 0x808008E8: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x808008E8: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x808008EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008F4: jr          $ra
    // 0x808008F8: nop

    return;
    // 0x808008F8: nop

;}
RECOMP_FUNC void func_808016AC_chfactoryempspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016AC: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x808016B0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x808016B4: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x808016B8: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x808016BC: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x808016C0: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x808016C4: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x808016C8: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x808016CC: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x808016D0: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x808016D4: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x808016D8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x808016DC: jal         0x80100094
    // 0x808016E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808016E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808016E4: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x808016E8: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x808016EC: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x808016F0: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x808016F4: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x808016F8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808016FC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80801700: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80801704: lui         $at, 0x4561
    ctx->r1 = S32(0X4561 << 16);
    // 0x80801708: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8080170C: lui         $at, 0xC516
    ctx->r1 = S32(0XC516 << 16);
    // 0x80801710: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80801714: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801718: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080171C: addiu       $s3, $zero, 0x3C
    ctx->r19 = ADD32(0, 0X3C);
    // 0x80801720: addiu       $s2, $sp, 0x6C
    ctx->r18 = ADD32(ctx->r29, 0X6C);
L_80801724:
    // 0x80801724: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801728: jal         0x800DC128
    // 0x8080172C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_800DC128(rdram, ctx);
        goto after_1;
    // 0x8080172C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_1:
    // 0x80801730: lhu         $t8, 0x10($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X10);
    // 0x80801734: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80801738: andi        $t7, $t6, 0x1FC
    ctx->r15 = ctx->r14 & 0X1FC;
    // 0x8080173C: andi        $t9, $t8, 0xFE03
    ctx->r25 = ctx->r24 & 0XFE03;
    // 0x80801740: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80801744: sh          $t0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r8;
    // 0x80801748: lbu         $t3, 0x10($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X10);
    // 0x8080174C: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x80801750: lbu         $a0, 0x8($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X8);
    // 0x80801754: andi        $t4, $t3, 0xFF01
    ctx->r12 = ctx->r11 & 0XFF01;
    // 0x80801758: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x8080175C: jal         0x80089D48
    // 0x80801760: sb          $t5, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r13;
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80801760: sb          $t5, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r13;
    after_2:
    // 0x80801764: sb          $v0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r2;
    // 0x80801768: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8080176C: jal         0x800DC178
    // 0x80801770: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80801770: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_3:
    // 0x80801774: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x80801778: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8080177C: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x80801780: jal         0x800DC178
    // 0x80801784: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80801784: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    after_4:
    // 0x80801788: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x8080178C: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x80801790: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801794: jal         0x800DC128
    // 0x80801798: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DC128(rdram, ctx);
        goto after_5;
    // 0x80801798: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x8080179C: lbu         $t9, 0x11($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X11);
    // 0x808017A0: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x808017A4: andi        $t7, $t8, 0x2
    ctx->r15 = ctx->r24 & 0X2;
    // 0x808017A8: andi        $t0, $t9, 0xFFFD
    ctx->r8 = ctx->r25 & 0XFFFD;
    // 0x808017AC: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x808017B0: jal         0x800C8A98
    // 0x808017B4: sb          $t1, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r9;
    func_800C8A98(rdram, ctx);
        goto after_6;
    // 0x808017B4: sb          $t1, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r9;
    after_6:
    // 0x808017B8: mfc1        $a1, $f28
    ctx->r5 = (int32_t)ctx->f28.u32l;
    // 0x808017BC: mfc1        $a2, $f30
    ctx->r6 = (int32_t)ctx->f30.u32l;
    // 0x808017C0: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x808017C4: jal         0x800C8E54
    // 0x808017C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C8E54(rdram, ctx);
        goto after_7;
    // 0x808017C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x808017CC: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x808017D0: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x808017D4: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x808017D8: jal         0x800C8FB0
    // 0x808017DC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C8FB0(rdram, ctx);
        goto after_8;
    // 0x808017DC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_8:
    // 0x808017E0: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x808017E4: jal         0x800C8F64
    // 0x808017E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C8F64(rdram, ctx);
        goto after_9;
    // 0x808017E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x808017EC: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x808017F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808017F4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808017F8: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x808017FC: jal         0x800C8CB8
    // 0x80801800: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    func_800C8CB8(rdram, ctx);
        goto after_10;
    // 0x80801800: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_10:
    // 0x80801804: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x80801808: bne         $s1, $s3, L_80801724
    if (ctx->r17 != ctx->r19) {
        // 0x8080180C: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_80801724;
    }
    // 0x8080180C: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80801810: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80801814: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80801818: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8080181C: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80801820: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80801824: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80801828: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x8080182C: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80801830: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80801834: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x80801838: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x8080183C: jr          $ra
    // 0x80801840: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80801840: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void boot___osDevMgrMain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80807B18_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807B18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80807B1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80807B20: jal         0x80100094
    // 0x80807B24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80807B24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80807B28: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80807B2C: sb          $zero, 0xA4($v0)
    MEM_B(0XA4, ctx->r2) = 0;
    // 0x80807B30: sw          $zero, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = 0;
    // 0x80807B34: sb          $zero, 0xA6($v0)
    MEM_B(0XA6, ctx->r2) = 0;
    // 0x80807B38: sb          $t6, 0xA7($v0)
    MEM_B(0XA7, ctx->r2) = ctx->r14;
    // 0x80807B3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80807B40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80807B44: jr          $ra
    // 0x80807B48: nop

    return;
    // 0x80807B48: nop

;}
RECOMP_FUNC void func_800BF420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF420: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BF424: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BF428: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BF42C: jal         0x80088118
    // 0x800BF430: addiu       $a0, $a0, -0x7A50
    ctx->r4 = ADD32(ctx->r4, -0X7A50);
    _gcmapDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x800BF430: addiu       $a0, $a0, -0x7A50
    ctx->r4 = ADD32(ctx->r4, -0X7A50);
    after_0:
    // 0x800BF434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BF438: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BF43C: jr          $ra
    // 0x800BF440: nop

    return;
    // 0x800BF440: nop

;}
RECOMP_FUNC void func_80806CA4_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806CA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80806CA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806CAC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80806CB0: jal         0x80100094
    // 0x80806CB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80806CB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80806CB8: lbu         $v1, 0x5C($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X5C);
    // 0x80806CBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80806CC0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80806CC4: beq         $v1, $at, L_80806CDC
    if (ctx->r3 == ctx->r1) {
        // 0x80806CC8: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80806CDC;
    }
    // 0x80806CC8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80806CCC: beq         $v1, $at, L_80806CE4
    if (ctx->r3 == ctx->r1) {
        // 0x80806CD0: addiu       $t7, $zero, 0xA
        ctx->r15 = ADD32(0, 0XA);
            goto L_80806CE4;
    }
    // 0x80806CD0: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80806CD4: b           L_80806CEC
    // 0x80806CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80806CEC;
    // 0x80806CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80806CDC:
    // 0x80806CDC: b           L_80806CE8
    // 0x80806CE0: sb          $t6, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = ctx->r14;
        goto L_80806CE8;
    // 0x80806CE0: sb          $t6, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = ctx->r14;
L_80806CE4:
    // 0x80806CE4: sb          $t7, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = ctx->r15;
L_80806CE8:
    // 0x80806CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80806CEC:
    // 0x80806CEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80806CF0: jr          $ra
    // 0x80806CF4: nop

    return;
    // 0x80806CF4: nop

;}
RECOMP_FUNC void func_80012D84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012D84: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80012D88: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80012D8C: lui         $s4, 0x8007
    ctx->r20 = S32(0X8007 << 16);
    // 0x80012D90: addiu       $s4, $s4, -0x5EB4
    ctx->r20 = ADD32(ctx->r20, -0X5EB4);
    // 0x80012D94: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x80012D98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80012D9C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80012DA0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80012DA4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80012DA8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80012DAC: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80012DB0: beq         $t6, $zero, L_80012DE8
    if (ctx->r14 == 0) {
        // 0x80012DB4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80012DE8;
    }
    // 0x80012DB4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80012DB8: lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // 0x80012DBC: addiu       $s1, $s1, -0x6B78
    ctx->r17 = ADD32(ctx->r17, -0X6B78);
    // 0x80012DC0: addiu       $s2, $sp, 0x40
    ctx->r18 = ADD32(ctx->r29, 0X40);
    // 0x80012DC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80012DC8:
    // 0x80012DC8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80012DCC: jal         0x8002E1F0
    // 0x80012DD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80012DD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80012DD4: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80012DD8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80012DDC: sltu        $at, $s0, $t7
    ctx->r1 = ctx->r16 < ctx->r15 ? 1 : 0;
    // 0x80012DE0: bnel        $at, $zero, L_80012DC8
    if (ctx->r1 != 0) {
        // 0x80012DE4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80012DC8;
    }
    goto skip_0;
    // 0x80012DE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_80012DE8:
    // 0x80012DE8: lui         $s2, 0x8007
    ctx->r18 = S32(0X8007 << 16);
    // 0x80012DEC: addiu       $s2, $s2, -0x65D0
    ctx->r18 = ADD32(ctx->r18, -0X65D0);
    // 0x80012DF0: lw          $s0, 0x4($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X4);
    // 0x80012DF4: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x80012DF8: addiu       $s3, $s3, -0x5EB8
    ctx->r19 = ADD32(ctx->r19, -0X5EB8);
    // 0x80012DFC: beq         $s0, $zero, L_80012E68
    if (ctx->r16 == 0) {
        // 0x80012E00: nop
    
            goto L_80012E68;
    }
    // 0x80012E00: nop

L_80012E04:
    // 0x80012E04: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x80012E08: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80012E0C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80012E10: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80012E14: sltu        $at, $t0, $t8
    ctx->r1 = ctx->r8 < ctx->r24 ? 1 : 0;
    // 0x80012E18: beq         $at, $zero, L_80012E60
    if (ctx->r1 == 0) {
        // 0x80012E1C: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80012E60;
    }
    // 0x80012E1C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80012E20: lw          $t1, 0x4($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X4);
    // 0x80012E24: bne         $s0, $t1, L_80012E30
    if (ctx->r16 != ctx->r9) {
        // 0x80012E28: nop
    
            goto L_80012E30;
    }
    // 0x80012E28: nop

    // 0x80012E2C: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
L_80012E30:
    // 0x80012E30: jal         0x80020E74
    // 0x80012E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80020E74(rdram, ctx);
        goto after_1;
    // 0x80012E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80012E38: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x80012E3C: beql        $a1, $zero, L_80012E58
    if (ctx->r5 == 0) {
        // 0x80012E40: sw          $s0, 0x8($s2)
        MEM_W(0X8, ctx->r18) = ctx->r16;
            goto L_80012E58;
    }
    goto skip_1;
    // 0x80012E40: sw          $s0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r16;
    skip_1:
    // 0x80012E44: jal         0x80020E40
    // 0x80012E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80020E40(rdram, ctx);
        goto after_2;
    // 0x80012E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80012E4C: b           L_80012E60
    // 0x80012E50: nop

        goto L_80012E60;
    // 0x80012E50: nop

    // 0x80012E54: sw          $s0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r16;
L_80012E58:
    // 0x80012E58: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80012E5C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_80012E60:
    // 0x80012E60: bne         $s1, $zero, L_80012E04
    if (ctx->r17 != 0) {
        // 0x80012E64: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80012E04;
    }
    // 0x80012E64: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_80012E68:
    // 0x80012E68: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x80012E6C: addiu       $s3, $s3, -0x5EB8
    ctx->r19 = ADD32(ctx->r19, -0X5EB8);
    // 0x80012E70: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80012E74: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80012E78: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    // 0x80012E7C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80012E80: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x80012E84: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80012E88: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80012E8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80012E90: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80012E94: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80012E98: jr          $ra
    // 0x80012E9C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80012E9C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void _bafpctrl_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084CC0: syscall     133
    recomp_syscall_handler(rdram, ctx, 0x80084CC0);
    return;
    // 0x80084CC4: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void gspropprop_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x80800004: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80800008: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x8080000C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80800010: lh          $t8, 0x8($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X8);
    // 0x80800014: jr          $ra
    // 0x80800018: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    return;
    // 0x80800018: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
;}
RECOMP_FUNC void func_800E46E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E46E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E46E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E46E8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800E46EC: lui         $t7, 0xDB06
    ctx->r15 = S32(0XDB06 << 16);
    // 0x800E46F0: ori         $t7, $t7, 0x20
    ctx->r15 = ctx->r15 | 0X20;
    // 0x800E46F4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800E46F8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800E46FC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800E4700: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800E4704: jal         0x8002E330
    // 0x800E4708: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800E4708: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800E470C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800E4710: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x800E4714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E4718: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E471C: jr          $ra
    // 0x800E4720: nop

    return;
    // 0x800E4720: nop

;}
RECOMP_FUNC void ncbajig_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080004C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800050: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800054: lui         $a1, 0x3FE6
    ctx->r5 = S32(0X3FE6 << 16);
    // 0x80800058: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080005C: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800060: jal         0x80111B8C
    // 0x80800064: lui         $a2, 0x4160
    ctx->r6 = S32(0X4160 << 16);
    func_80111B8C(rdram, ctx);
        goto after_0;
    // 0x80800064: lui         $a2, 0x4160
    ctx->r6 = S32(0X4160 << 16);
    after_0:
    // 0x80800068: lui         $at, 0x4391
    ctx->r1 = S32(0X4391 << 16);
    // 0x8080006C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800070: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x80800074: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80800078: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080007C: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x80800080: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800088: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080008C: jal         0x80115858
    // 0x80800090: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    func_80115858(rdram, ctx);
        goto after_1;
    // 0x80800090: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    after_1:
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800098: jal         0x80115870
    // 0x8080009C: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    func_80115870(rdram, ctx);
        goto after_2;
    // 0x8080009C: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_2:
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A4: jal         0x801124D0
    // 0x808000A8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_801124D0(rdram, ctx);
        goto after_3;
    // 0x808000A8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_3:
    // 0x808000AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000B8: jr          $ra
    // 0x808000BC: nop

    return;
    // 0x808000BC: nop

;}
RECOMP_FUNC void fxairbub_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x800889A0
    // 0x80800010: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _fxripple_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80800014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800018: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080001C: jr          $ra
    // 0x80800020: nop

    return;
    // 0x80800020: nop

;}
RECOMP_FUNC void func_808001E4_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001F0: jal         0x800DA298
    // 0x808001F4: addiu       $a0, $zero, 0x9C7
    ctx->r4 = ADD32(0, 0X9C7);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808001F4: addiu       $a0, $zero, 0x9C7
    ctx->r4 = ADD32(0, 0X9C7);
    after_0:
    // 0x808001F8: beq         $v0, $zero, L_80800228
    if (ctx->r2 == 0) {
        // 0x808001FC: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_80800228;
    }
    // 0x808001FC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80800200: lhu         $t6, 0x76($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X76);
    // 0x80800204: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800208: beql        $t7, $zero, L_8080022C
    if (ctx->r15 == 0) {
        // 0x8080020C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080022C;
    }
    goto skip_0;
    // 0x8080020C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800210: jal         0x800856B8
    // 0x80800214: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _capod_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800214: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80800218: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8080021C: lhu         $t8, 0x76($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X76);
    // 0x80800220: andi        $t9, $t8, 0x7F
    ctx->r25 = ctx->r24 & 0X7F;
    // 0x80800224: sh          $t9, 0x76($v1)
    MEM_H(0X76, ctx->r3) = ctx->r25;
L_80800228:
    // 0x80800228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080022C:
    // 0x8080022C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800230: jr          $ra
    // 0x80800234: nop

    return;
    // 0x80800234: nop

;}
RECOMP_FUNC void func_8080028C_chbabydino(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080028C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800290: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800294: jal         0x800897C8
    // 0x80800298: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80800298: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080029C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002A4: jr          $ra
    // 0x808002A8: nop

    return;
    // 0x808002A8: nop

;}
RECOMP_FUNC void func_800F82C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F82C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F82C4: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800F82C8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800F82CC: jr          $ra
    // 0x800F82D0: sb          $t6, 0x54B0($at)
    MEM_B(0X54B0, ctx->r1) = ctx->r14;
    return;
    // 0x800F82D0: sb          $t6, 0x54B0($at)
    MEM_B(0X54B0, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_8008D058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D058: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D05C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D060: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008D064: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8008D068: jal         0x8008B304
    // 0x8008D06C: lw          $a0, 0x3C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X3C);
    func_8008B304(rdram, ctx);
        goto after_0;
    // 0x8008D06C: lw          $a0, 0x3C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X3C);
    after_0:
    // 0x8008D070: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8008D074: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8008D078: jal         0x8008B4D4
    // 0x8008D07C: lw          $a0, 0x3C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X3C);
    func_8008B4D4(rdram, ctx);
        goto after_1;
    // 0x8008D07C: lw          $a0, 0x3C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X3C);
    after_1:
    // 0x8008D080: jal         0x800DF41C
    // 0x8008D084: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF41C(rdram, ctx);
        goto after_2;
    // 0x8008D084: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8008D088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D08C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D090: jr          $ra
    // 0x8008D094: nop

    return;
    // 0x8008D094: nop

;}
RECOMP_FUNC void func_8080005C_bsclimb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080005C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800060: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800064: jal         0x8009EF34
    // 0x80800068: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    bastick_getY(rdram, ctx);
        goto after_0;
    // 0x80800068: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080006C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80800070: jal         0x800F2100
    // 0x80800074: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x80800074: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x80800078: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(144, 0X8B0) << 16);
    // 0x8080007C: lwc1        $f14, 0x8B0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(144, 0X8B0));
    // 0x80800080: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800084: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800088: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8080008C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800090: bc1fl       L_808000A8
    if (!c1cs) {
        // 0x80800094: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_808000A8;
    }
    goto skip_0;
    // 0x80800094: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_0:
    // 0x80800098: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080009C: b           L_808000C0
    // 0x808000A0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_808000C0;
    // 0x808000A0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808000A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_808000A8:
    // 0x808000A8: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x808000AC: jal         0x800F1344
    // 0x808000B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F1344(rdram, ctx);
        goto after_2;
    // 0x808000B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x808000B4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808000B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808000BC: nop

L_808000C0:
    // 0x808000C0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808000C4: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x808000C8: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x808000CC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808000D0: jal         0x8009B94C
    // 0x808000D4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009B94C(rdram, ctx);
        goto after_3;
    // 0x808000D4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x808000D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808000E0: jr          $ra
    // 0x808000E4: nop

    return;
    // 0x808000E4: nop

;}
RECOMP_FUNC void _glcutDll_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800887F8: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x800887F8);
    return;
    // 0x800887FC: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
