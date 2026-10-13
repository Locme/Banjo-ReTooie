#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800F1C98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1C98: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F1C9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F1CA0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800F1CA4: jal         0x800EEF94
    // 0x800F1CA8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_800EEF94(rdram, ctx);
        goto after_0;
    // 0x800F1CA8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x800F1CAC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800F1CB0: jal         0x800EEF94
    // 0x800F1CB4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800EEF94(rdram, ctx);
        goto after_1;
    // 0x800F1CB4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x800F1CB8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800F1CBC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800F1CC0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800F1CC4: jal         0x800EE97C
    // 0x800F1CC8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    func_800EE97C(rdram, ctx);
        goto after_2;
    // 0x800F1CC8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x800F1CCC: jal         0x800EEF94
    // 0x800F1CD0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EEF94(rdram, ctx);
        goto after_3;
    // 0x800F1CD0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x800F1CD4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800F1CD8: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F1CDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F1CE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800F1CE4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800F1CE8: jr          $ra
    // 0x800F1CEC: div.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    return;
    // 0x800F1CEC: div.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
;}
RECOMP_FUNC void bswalk_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002DC: jal         0x80800000
    // 0x808002E0: nop

    func_80800000_bswalk(rdram, ctx);
        goto after_0;
    // 0x808002E0: nop

    after_0:
    // 0x808002E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002EC: jr          $ra
    // 0x808002F0: nop

    return;
    // 0x808002F0: nop

;}
RECOMP_FUNC void func_800BDD00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BDD00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BDD04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BDD08: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BDD0C: jal         0x80087C80
    // 0x800BDD10: addiu       $a0, $a0, -0x7BF0
    ctx->r4 = ADD32(ctx->r4, -0X7BF0);
    _gccubeDll_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x800BDD10: addiu       $a0, $a0, -0x7BF0
    ctx->r4 = ADD32(ctx->r4, -0X7BF0);
    after_0:
    // 0x800BDD14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BDD18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BDD1C: jr          $ra
    // 0x800BDD20: nop

    return;
    // 0x800BDD20: nop

;}
RECOMP_FUNC void func_80800848_bsbanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800848: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080084C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800850: jal         0x808003BC
    // 0x80800854: nop

    func_808003BC_bsbanswim(rdram, ctx);
        goto after_0;
    // 0x80800854: nop

    after_0:
    // 0x80800858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080085C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800860: jr          $ra
    // 0x80800864: nop

    return;
    // 0x80800864: nop

;}
RECOMP_FUNC void func_8008AD80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AD80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008AD84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008AD88: jal         0x8008C0B8
    // 0x8008AD8C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8008C0B8(rdram, ctx);
        goto after_0;
    // 0x8008AD8C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008AD90: jal         0x8001ACCC
    // 0x8008AD94: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    heap_alloc(rdram, ctx);
        goto after_1;
    // 0x8008AD94: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    after_1:
    // 0x8008AD98: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8008AD9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008ADA0: jal         0x8008B518
    // 0x8008ADA4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_8008B518(rdram, ctx);
        goto after_2;
    // 0x8008ADA4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8008ADA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008ADAC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8008ADB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008ADB4: jr          $ra
    // 0x8008ADB8: nop

    return;
    // 0x8008ADB8: nop

;}
RECOMP_FUNC void func_800C9EAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9EAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C9EB0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800C9EB4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800C9EB8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C9EBC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C9EC0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C9EC4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C9EC8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800C9ECC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800C9ED0: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x800C9ED4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800C9ED8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800C9EDC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800C9EE0: jal         0x800C9750
    // 0x800C9EE4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_800C9750(rdram, ctx);
        goto after_0;
    // 0x800C9EE4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x800C9EE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C9EEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C9EF0: jr          $ra
    // 0x800C9EF4: nop

    return;
    // 0x800C9EF4: nop

;}
RECOMP_FUNC void func_80111CC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111CC8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80111CCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80111CD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80111CD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80111CD8: jal         0x80110898
    // 0x80111CDC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    func_80110898(rdram, ctx);
        goto after_0;
    // 0x80111CDC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x80111CE0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80111CE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80111CE8: jal         0x801107F0
    // 0x80111CEC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_801107F0(rdram, ctx);
        goto after_1;
    // 0x80111CEC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x80111CF0: jal         0x8010FFD0
    // 0x80111CF4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8010FFD0(rdram, ctx);
        goto after_2;
    // 0x80111CF4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80111CF8: beq         $v0, $zero, L_80111D30
    if (ctx->r2 == 0) {
        // 0x80111CFC: nop
    
            goto L_80111D30;
    }
    // 0x80111CFC: nop

    // 0x80111D00: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80111D04: jal         0x800EFD24
    // 0x80111D08: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    func_800EFD24(rdram, ctx);
        goto after_3;
    // 0x80111D08: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_3:
    // 0x80111D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80111D10: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80111D14: jal         0x80113640
    // 0x80111D18: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    func_80113640(rdram, ctx);
        goto after_4;
    // 0x80111D18: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_4:
    // 0x80111D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80111D20: jal         0x80110770
    // 0x80111D24: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80110770(rdram, ctx);
        goto after_5;
    // 0x80111D24: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_5:
    // 0x80111D28: b           L_80111D9C
    // 0x80111D2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80111D9C;
    // 0x80111D2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80111D30:
    // 0x80111D30: jal         0x80111A98
    // 0x80111D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80111A98(rdram, ctx);
        goto after_6;
    // 0x80111D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80111D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80111D3C: jal         0x80111ABC
    // 0x80111D40: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80111ABC(rdram, ctx);
        goto after_7;
    // 0x80111D40: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_7:
    // 0x80111D44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80111D48: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80111D4C: jal         0x80111A38
    // 0x80111D50: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_80111A38(rdram, ctx);
        goto after_8;
    // 0x80111D50: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_8:
    // 0x80111D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80111D58: jal         0x8011106C
    // 0x80111D5C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8011106C(rdram, ctx);
        goto after_9;
    // 0x80111D5C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_9:
    // 0x80111D60: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80111D64: jal         0x800EF04C
    // 0x80111D68: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_10;
    // 0x80111D68: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_10:
    // 0x80111D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80111D70: jal         0x80110770
    // 0x80111D74: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80110770(rdram, ctx);
        goto after_11;
    // 0x80111D74: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_11:
    // 0x80111D78: jal         0x8011329C
    // 0x80111D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8011329C(rdram, ctx);
        goto after_12;
    // 0x80111D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80111D80: beql        $v0, $zero, L_80111D9C
    if (ctx->r2 == 0) {
        // 0x80111D84: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80111D9C;
    }
    goto skip_0;
    // 0x80111D84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80111D88: jal         0x80111C04
    // 0x80111D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80111C04(rdram, ctx);
        goto after_13;
    // 0x80111D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80111D90: b           L_80111D9C
    // 0x80111D94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80111D9C;
    // 0x80111D94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80111D98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80111D9C:
    // 0x80111D9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80111DA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80111DA4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80111DA8: jr          $ra
    // 0x80111DAC: nop

    return;
    // 0x80111DAC: nop

;}
RECOMP_FUNC void func_8001209C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001209C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800120A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800120A4: jal         0x8001A2B0
    // 0x800120A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8001A2B0(rdram, ctx);
        goto after_0;
    // 0x800120A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800120AC: jal         0x800155BC
    // 0x800120B0: nop

    func_800155BC(rdram, ctx);
        goto after_1;
    // 0x800120B0: nop

    after_1:
    // 0x800120B4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800120B8: lw          $t6, 0x3380($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3380);
    // 0x800120BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800120C0: bne         $t6, $at, L_800120D0
    if (ctx->r14 != ctx->r1) {
        // 0x800120C4: nop
    
            goto L_800120D0;
    }
    // 0x800120C4: nop

    // 0x800120C8: jal         0x800A7B24
    // 0x800120CC: nop

    func_800A7B24(rdram, ctx);
        goto after_2;
    // 0x800120CC: nop

    after_2:
L_800120D0:
    // 0x800120D0: jal         0x8001207C
    // 0x800120D4: nop

    func_8001207C(rdram, ctx);
        goto after_3;
    // 0x800120D4: nop

    after_3:
    // 0x800120D8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800120DC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800120E0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800120E4: sw          $t7, 0x3380($at)
    MEM_W(0X3380, ctx->r1) = ctx->r15;
    // 0x800120E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800120EC: bnel        $t7, $at, L_80012100
    if (ctx->r15 != ctx->r1) {
        // 0x800120F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80012100;
    }
    goto skip_0;
    // 0x800120F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800120F4: jal         0x800A7BB8
    // 0x800120F8: lw          $a0, 0x59CC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X59CC);
    func_800A7BB8(rdram, ctx);
        goto after_4;
    // 0x800120F8: lw          $a0, 0x59CC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X59CC);
    after_4:
    // 0x800120FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80012100:
    // 0x80012100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80012104: jr          $ra
    // 0x80012108: nop

    return;
    // 0x80012108: nop

;}
RECOMP_FUNC void func_808001F4_bsdroneslide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808001F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800200: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800204: jal         0x8009EF04
    // 0x80800208: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    bastick_distance(rdram, ctx);
        goto after_0;
    // 0x80800208: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080020C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800210: nop

    // 0x80800214: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800218: nop

    // 0x8080021C: bc1t        L_80800254
    if (c1cs) {
        // 0x80800220: nop
    
            goto L_80800254;
    }
    // 0x80800220: nop

    // 0x80800224: jal         0x8009EEB8
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_1;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080022C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800230: jal         0x800F1DCC
    // 0x80800234: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    func_800F1DCC(rdram, ctx);
        goto after_2;
    // 0x80800234: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x80800238: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8080023C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800240: jal         0x800F0DC0
    // 0x80800244: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800F0DC0(rdram, ctx);
        goto after_3;
    // 0x80800244: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x80800248: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080024C: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80800250: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
L_80800254:
    // 0x80800254: jal         0x8009BB18
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB18(rdram, ctx);
        goto after_4;
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080025C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800260: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80800264: jal         0x800F1DCC
    // 0x80800268: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_800F1DCC(rdram, ctx);
        goto after_5;
    // 0x80800268: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x8080026C: jal         0x800D8FF8
    // 0x80800270: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_6;
    // 0x80800270: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x80800274: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800278: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800280: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80800284: add.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x80800288: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8080028C: jal         0x8009B9C0
    // 0x80800290: nop

    baphysics_set_target_yaw(rdram, ctx);
        goto after_7;
    // 0x80800290: nop

    after_7:
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800298: jal         0x800A4DA4
    // 0x8080029C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800A4DA4(rdram, ctx);
        goto after_8;
    // 0x8080029C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_8:
    // 0x808002A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808002AC: jr          $ra
    // 0x808002B0: nop

    return;
    // 0x808002B0: nop

;}
RECOMP_FUNC void _bskazstilt_entrypoint_30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083750: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x80083750);
    return;
    // 0x80083754: addi        $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
;}
RECOMP_FUNC void _bamum_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084F28: syscall     142
    recomp_syscall_handler(rdram, ctx, 0x80084F28);
    return;
    // 0x80084F2C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808008C4_chheggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008C4: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x808008C8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808008CC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x808008D0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x808008D4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808008D8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808008DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808008E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808008E4: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x808008E8: jal         0x80100094
    // 0x808008EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808008EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808008F0: addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
    // 0x808008F4: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x808008F8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x808008FC: addiu       $a0, $zero, 0x299
    ctx->r4 = ADD32(0, 0X299);
    // 0x80800900: jal         0x800882C0
    // 0x80800904: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800904: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_1:
    // 0x80800908: blez        $v0, L_8080094C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080090C: addiu       $s0, $sp, 0x58
        ctx->r16 = ADD32(ctx->r29, 0X58);
            goto L_8080094C;
    }
    // 0x8080090C: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x80800910: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80800914: addu        $s1, $t7, $s0
    ctx->r17 = ADD32(ctx->r15, ctx->r16);
    // 0x80800918: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
L_8080091C:
    // 0x8080091C: jal         0x80088BE8
    // 0x80800920: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _gspropctrl_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80800920: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x80800924: multu       $v0, $s2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800928: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080092C: mflo        $t8
    ctx->r24 = lo;
    // 0x80800930: addu        $a1, $s5, $t8
    ctx->r5 = ADD32(ctx->r21, ctx->r24);
    // 0x80800934: jal         0x80088C00
    // 0x80800938: addiu       $a1, $a1, -0x258
    ctx->r5 = ADD32(ctx->r5, -0X258);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x80800938: addiu       $a1, $a1, -0x258
    ctx->r5 = ADD32(ctx->r5, -0X258);
    after_3:
    // 0x8080093C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800940: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80800944: bne         $at, $zero, L_8080091C
    if (ctx->r1 != 0) {
        // 0x80800948: nop
    
            goto L_8080091C;
    }
    // 0x80800948: nop

L_8080094C:
    // 0x8080094C: addiu       $a0, $zero, 0x511
    ctx->r4 = ADD32(0, 0X511);
    // 0x80800950: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800954: jal         0x800882C0
    // 0x80800958: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x80800958: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_4:
    // 0x8080095C: blez        $v0, L_808009A8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800960: addiu       $s0, $sp, 0x58
        ctx->r16 = ADD32(ctx->r29, 0X58);
            goto L_808009A8;
    }
    // 0x80800960: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x80800964: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80800968: addu        $s4, $t0, $s0
    ctx->r20 = ADD32(ctx->r8, ctx->r16);
    // 0x8080096C: addiu       $s2, $sp, 0x3C
    ctx->r18 = ADD32(ctx->r29, 0X3C);
L_80800970:
    // 0x80800970: jal         0x80088BE8
    // 0x80800974: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _gspropctrl_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80800974: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x80800978: addiu       $s1, $v0, -0x32
    ctx->r17 = ADD32(ctx->r2, -0X32);
    // 0x8080097C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800980: jal         0x80088C00
    // 0x80800984: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80800984: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_6:
    // 0x80800988: jal         0x80088498
    // 0x8080098C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _glsplinefind_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x8080098C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x80800990: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800994: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x80800998: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
    // 0x8080099C: addu        $t2, $s5, $t1
    ctx->r10 = ADD32(ctx->r21, ctx->r9);
    // 0x808009A0: bne         $at, $zero, L_80800970
    if (ctx->r1 != 0) {
        // 0x808009A4: sw          $v0, 0x48($t2)
        MEM_W(0X48, ctx->r10) = ctx->r2;
            goto L_80800970;
    }
    // 0x808009A4: sw          $v0, 0x48($t2)
    MEM_W(0X48, ctx->r10) = ctx->r2;
L_808009A8:
    // 0x808009A8: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x808009AC: addiu       $a0, $s5, 0x3C
    ctx->r4 = ADD32(ctx->r21, 0X3C);
    // 0x808009B0: jal         0x800EE7F8
    // 0x808009B4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x808009B4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_8:
    // 0x808009B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808009BC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808009C0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808009C4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808009C8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808009CC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x808009D0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x808009D4: jr          $ra
    // 0x808009D8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x808009D8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void boot___osPiGetAccess(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80800484_chchuffyglow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800484: jr          $ra
    // 0x80800488: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800488: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80801544_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801544: jr          $ra
    // 0x80801548: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80801548: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_80800150_chsmalltrexdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800150: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800154: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800158: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080015C: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800160: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800164: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800168: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080016C: bne         $t7, $at, L_80800228
    if (ctx->r15 != ctx->r1) {
        // 0x80800170: nop
    
            goto L_80800228;
    }
    // 0x80800170: nop

    // 0x80800174: jal         0x800D90A4
    // 0x80800178: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    func_800D90A4(rdram, ctx);
        goto after_0;
    // 0x80800178: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    after_0:
    // 0x8080017C: beq         $v0, $zero, L_80800228
    if (ctx->r2 == 0) {
        // 0x80800180: nop
    
            goto L_80800228;
    }
    // 0x80800180: nop

    // 0x80800184: jal         0x800F54E4
    // 0x80800188: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800188: nop

    after_1:
    // 0x8080018C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800190: jal         0x800F5A00
    // 0x80800194: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x80800194: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x80800198: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x8080019C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808001A0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808001A4: jal         0x800F1DF4
    // 0x808001A8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F1DF4(rdram, ctx);
        goto after_3;
    // 0x808001A8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x808001AC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808001B0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x808001B4: jal         0x800EEAD4
    // 0x808001B8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800EEAD4(rdram, ctx);
        goto after_4;
    // 0x808001B8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x808001BC: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x808001C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001C4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001CC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808001D0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808001D4: bc1f        L_80800220
    if (!c1cs) {
        // 0x808001D8: nop
    
            goto L_80800220;
    }
    // 0x808001D8: nop

    // 0x808001DC: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808001E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001E4: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808001E8: jal         0x800F2094
    // 0x808001EC: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    func_800F2094(rdram, ctx);
        goto after_5;
    // 0x808001EC: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_5:
    // 0x808001F0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808001F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001FC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800200: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80800204: nop

    // 0x80800208: bc1f        L_80800228
    if (!c1cs) {
        // 0x8080020C: nop
    
            goto L_80800228;
    }
    // 0x8080020C: nop

    // 0x80800210: jal         0x8010108C
    // 0x80800214: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_6;
    // 0x80800214: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80800218: b           L_80800228
    // 0x8080021C: nop

        goto L_80800228;
    // 0x8080021C: nop

L_80800220:
    // 0x80800220: jal         0x8010108C
    // 0x80800224: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_7;
    // 0x80800224: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
L_80800228:
    // 0x80800228: jal         0x80086240
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chdoor_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800234: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800238: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080023C: jr          $ra
    // 0x80800240: nop

    return;
    // 0x80800240: nop

;}
RECOMP_FUNC void _fxstep_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A58: syscall     718
    recomp_syscall_handler(rdram, ctx, 0x80088A58);
    return;
    // 0x80088A5C: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void func_808000F4_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000FC: jal         0x808000C8
    // 0x80800100: nop

    func_808000C8_chcollballcontrol(rdram, ctx);
        goto after_0;
    // 0x80800100: nop

    after_0:
    // 0x80800104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080010C: jr          $ra
    // 0x80800110: nop

    return;
    // 0x80800110: nop

;}
RECOMP_FUNC void func_800141D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800141D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800141D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800141D8: jal         0x80013DE4
    // 0x800141DC: nop

    func_80013DE4(rdram, ctx);
        goto after_0;
    // 0x800141DC: nop

    after_0:
    // 0x800141E0: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x800141E4: lw          $t6, -0x7B74($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7B74);
    // 0x800141E8: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800141EC: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x800141F0: bnel        $t6, $at, L_8001424C
    if (ctx->r14 != ctx->r1) {
        // 0x800141F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001424C;
    }
    goto skip_0;
    // 0x800141F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800141F8: lw          $t7, -0x7B80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7B80);
    // 0x800141FC: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80014200: addiu       $t8, $t8, -0x7154
    ctx->r24 = ADD32(ctx->r24, -0X7154);
    // 0x80014204: bnel        $t7, $zero, L_8001424C
    if (ctx->r15 != 0) {
        // 0x80014208: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001424C;
    }
    goto skip_1;
    // 0x80014208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8001420C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80014210: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80014214: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80014218: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x8001421C: jal         0x80013FE4
    // 0x80014220: lw          $a0, -0x71A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X71A8);
    func_80013FE4(rdram, ctx);
        goto after_1;
    // 0x80014220: lw          $a0, -0x71A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X71A8);
    after_1:
    // 0x80014224: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80014228: addiu       $v0, $v0, -0x7154
    ctx->r2 = ADD32(ctx->r2, -0X7154);
    // 0x8001422C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80014230: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80014234: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80014238: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x8001423C: mfhi        $t3
    ctx->r11 = hi;
    // 0x80014240: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80014244: nop

    // 0x80014248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001424C:
    // 0x8001424C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80014250: jr          $ra
    // 0x80014254: nop

    return;
    // 0x80014254: nop

;}
RECOMP_FUNC void _bastatemem_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085170: syscall     153
    recomp_syscall_handler(rdram, ctx, 0x80085170);
    return;
    // 0x80085174: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80092BD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092BD0: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80092BD4: jr          $ra
    // 0x80092BD8: lwc1        $f0, 0xC8($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0XC8);
    return;
    // 0x80092BD8: lwc1        $f0, 0xC8($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0XC8);
;}
RECOMP_FUNC void func_80800834_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800834: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800838: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080083C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800840: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800844: jal         0x80091A58
    // 0x80800848: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x80800848: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x8080084C: beql        $v0, $zero, L_80800860
    if (ctx->r2 == 0) {
        // 0x80800850: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800860;
    }
    goto skip_0;
    // 0x80800850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800854: jal         0x80085188
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basub_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080085C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800860:
    // 0x80800860: jal         0x80091A58
    // 0x80800864: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_pressed(rdram, ctx);
        goto after_2;
    // 0x80800864: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800868: beql        $v0, $zero, L_80800888
    if (ctx->r2 == 0) {
        // 0x8080086C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800888;
    }
    goto skip_1;
    // 0x8080086C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800870: jal         0x8009BB94
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB94(rdram, ctx);
        goto after_3;
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800878: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080087C: jal         0x800851C0
    // 0x80800880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basub_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80800880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800888:
    // 0x80800888: jal         0x80091A58
    // 0x8080088C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_5;
    // 0x8080088C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_5:
    // 0x80800890: beql        $v0, $zero, L_808008C8
    if (ctx->r2 == 0) {
        // 0x80800894: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808008C8;
    }
    goto skip_2;
    // 0x80800894: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800898: jal         0x800EA068
    // 0x8080089C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    func_800EA068(rdram, ctx);
        goto after_6;
    // 0x8080089C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_6:
    // 0x808008A0: beq         $v0, $zero, L_808008BC
    if (ctx->r2 == 0) {
        // 0x808008A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008BC;
    }
    // 0x808008A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008A8: lui         $a1, 0x4320
    ctx->r5 = S32(0X4320 << 16);
    // 0x808008AC: jal         0x80085198
    // 0x808008B0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    _basub_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x808008B0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_7:
    // 0x808008B4: b           L_808008C8
    // 0x808008B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808008C8;
    // 0x808008B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008BC:
    // 0x808008BC: jal         0x800851A8
    // 0x808008C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basub_entrypoint_5(rdram, ctx);
        goto after_8;
    // 0x808008C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808008C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008C8:
    // 0x808008C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808008CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808008D0: jr          $ra
    // 0x808008D4: nop

    return;
    // 0x808008D4: nop

;}
RECOMP_FUNC void vector_defrag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2F58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B2F5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2F60: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800B2F64: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x800B2F68: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x800B2F6C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800B2F70: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x800B2F74: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
    // 0x800B2F78: jal         0x8001BAFC
    // 0x800B2F7C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    defrag(rdram, ctx);
        goto after_0;
    // 0x800B2F7C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_0:
    // 0x800B2F80: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x800B2F84: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x800B2F88: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2F8C: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x800B2F90: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
    // 0x800B2F94: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800B2F98: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x800B2F9C: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800B2FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2FA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B2FA8: jr          $ra
    // 0x800B2FAC: nop

    return;
    // 0x800B2FAC: nop

;}
RECOMP_FUNC void func_800EB51C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB51C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800EB520: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800EB524: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800EB528: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800EB52C: addu        $s0, $s0, $t7
    ctx->r16 = ADD32(ctx->r16, ctx->r15);
    // 0x800EB530: lw          $s0, 0x2E80($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X2E80);
    // 0x800EB534: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800EB538: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800EB53C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800EB540: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800EB544: beq         $s0, $zero, L_800EB5C8
    if (ctx->r16 == 0) {
        // 0x800EB548: sw          $a0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r4;
            goto L_800EB5C8;
    }
    // 0x800EB548: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800EB54C: jal         0x800B28C4
    // 0x800EB550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    vector_begin(rdram, ctx);
        goto after_0;
    // 0x800EB550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800EB554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EB558: jal         0x800B296C
    // 0x800EB55C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    vector_end(rdram, ctx);
        goto after_1;
    // 0x800EB55C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800EB560: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800EB564: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800EB568: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800EB56C: beq         $v0, $v1, L_800EB5C8
    if (ctx->r2 == ctx->r3) {
        // 0x800EB570: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800EB5C8;
    }
    // 0x800EB570: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EB574: sh          $t8, 0x2E9C($at)
    MEM_H(0X2E9C, ctx->r1) = ctx->r24;
    // 0x800EB578: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800EB57C: beq         $at, $zero, L_800EB5C8
    if (ctx->r1 == 0) {
        // 0x800EB580: or          $s0, $v1, $zero
        ctx->r16 = ctx->r3 | 0;
            goto L_800EB5C8;
    }
    // 0x800EB580: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x800EB584: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
L_800EB588:
    // 0x800EB588: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800EB58C: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x800EB590: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800EB594: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800EB598: beq         $t0, $zero, L_800EB5B0
    if (ctx->r8 == 0) {
        // 0x800EB59C: nop
    
            goto L_800EB5B0;
    }
    // 0x800EB59C: nop

    // 0x800EB5A0: jal         0x800EC7D4
    // 0x800EB5A4: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    func_800EC7D4(rdram, ctx);
        goto after_2;
    // 0x800EB5A4: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    after_2:
    // 0x800EB5A8: b           L_800EB5BC
    // 0x800EB5AC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_800EB5BC;
    // 0x800EB5AC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800EB5B0:
    // 0x800EB5B0: jal         0x80088C30
    // 0x800EB5B4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _gspropprop_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x800EB5B4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x800EB5B8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800EB5BC:
    // 0x800EB5BC: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x800EB5C0: bnel        $at, $zero, L_800EB588
    if (ctx->r1 != 0) {
        // 0x800EB5C4: lw          $a2, 0x0($s0)
        ctx->r6 = MEM_W(ctx->r16, 0X0);
            goto L_800EB588;
    }
    goto skip_0;
    // 0x800EB5C4: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    skip_0:
L_800EB5C8:
    // 0x800EB5C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800EB5CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EB5D0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800EB5D4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800EB5D8: jr          $ra
    // 0x800EB5DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800EB5DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8009EA70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EA70: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009EA74: jr          $ra
    // 0x8009EA78: lbu         $v0, 0x7076($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7076);
    return;
    // 0x8009EA78: lbu         $v0, 0x7076($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7076);
;}
RECOMP_FUNC void _bawobble_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085458: syscall     162
    recomp_syscall_handler(rdram, ctx, 0x80085458);
    return;
    // 0x8008545C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8001E7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E7C0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001E7C4: jr          $ra
    // 0x8001E7C8: lh          $v0, -0x2480($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2480);
    return;
    // 0x8001E7C8: lh          $v0, -0x2480($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2480);
;}
RECOMP_FUNC void func_80800AAC_chlavahand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AAC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800AB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800AB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AB8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800ABC: beq         $a1, $at, L_80800C20
    if (ctx->r5 == ctx->r1) {
        // 0x80800AC0: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_80800C20;
    }
    // 0x80800AC0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800AC4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80800AC8: beq         $a1, $v1, L_80800C34
    if (ctx->r5 == ctx->r3) {
        // 0x80800ACC: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80800C34;
    }
    // 0x80800ACC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800AD0: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80800AD4: beq         $a1, $at, L_80800B08
    if (ctx->r5 == ctx->r1) {
        // 0x80800AD8: addiu       $a0, $zero, 0x400
        ctx->r4 = ADD32(0, 0X400);
            goto L_80800B08;
    }
    // 0x80800AD8: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x80800ADC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800AE0: beq         $a1, $at, L_80800BC4
    if (ctx->r5 == ctx->r1) {
        // 0x80800AE4: lw          $t2, 0x38($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X38);
            goto L_80800BC4;
    }
    // 0x80800AE4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80800AE8: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800AEC: beq         $a1, $at, L_80800C54
    if (ctx->r5 == ctx->r1) {
        // 0x80800AF0: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80800C54;
    }
    // 0x80800AF0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800AF4: addiu       $at, $zero, 0x97
    ctx->r1 = ADD32(0, 0X97);
    // 0x80800AF8: beq         $a1, $at, L_80800D2C
    if (ctx->r5 == ctx->r1) {
        // 0x80800AFC: lw          $t5, 0x38($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X38);
            goto L_80800D2C;
    }
    // 0x80800AFC: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80800B00: b           L_80800D7C
    // 0x80800B04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D7C;
    // 0x80800B04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B08:
    // 0x80800B08: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80800B0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800B10: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x80800B14: jal         0x80108528
    // 0x80800B18: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80108528(rdram, ctx);
        goto after_0;
    // 0x80800B18: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x80800B1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B20: addiu       $a1, $zero, 0x927
    ctx->r5 = ADD32(0, 0X927);
    // 0x80800B24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800B28: jal         0x80103140
    // 0x80800B2C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_80103140(rdram, ctx);
        goto after_1;
    // 0x80800B2C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800B30: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800B34: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80800B38: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x80800B3C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80800B40: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80800B44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800B48: sw          $t7, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r15;
    // 0x80800B4C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80800B50: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x80800B54: sw          $t8, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->r24;
    // 0x80800B58: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80800B5C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80800B60: lhu         $t2, 0x12($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X12);
    // 0x80800B64: srl         $t3, $t2, 1
    ctx->r11 = S32(U32(ctx->r10) >> 1);
    // 0x80800B68: sw          $t3, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r11;
    // 0x80800B6C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80800B70: jal         0x80108528
    // 0x80800B74: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80108528(rdram, ctx);
        goto after_2;
    // 0x80800B74: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_2:
    // 0x80800B78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B7C: addiu       $a1, $zero, 0x926
    ctx->r5 = ADD32(0, 0X926);
    // 0x80800B80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800B84: jal         0x80103140
    // 0x80800B88: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_80103140(rdram, ctx);
        goto after_3;
    // 0x80800B88: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_3:
    // 0x80800B8C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80800B90: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80800B94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800B98: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80800B9C: sw          $t5, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r13;
    // 0x80800BA0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800BA4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80800BA8: lhu         $t8, 0x12($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X12);
    // 0x80800BAC: srl         $t9, $t8, 1
    ctx->r25 = S32(U32(ctx->r24) >> 1);
    // 0x80800BB0: sw          $t9, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r25;
    // 0x80800BB4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80800BB8: lhu         $t1, 0x7C($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X7C);
    // 0x80800BBC: b           L_80800D7C
    // 0x80800BC0: sh          $t1, 0x7C($v1)
    MEM_H(0X7C, ctx->r3) = ctx->r9;
        goto L_80800D7C;
    // 0x80800BC0: sh          $t1, 0x7C($v1)
    MEM_H(0X7C, ctx->r3) = ctx->r9;
L_80800BC4:
    // 0x80800BC4: lhu         $v0, 0x72($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X72);
    // 0x80800BC8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80800BCC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800BD0: srl         $t3, $v0, 10
    ctx->r11 = S32(U32(ctx->r2) >> 10);
    // 0x80800BD4: bne         $v1, $t3, L_80800BEC
    if (ctx->r3 != ctx->r11) {
        // 0x80800BD8: or          $v0, $t3, $zero
        ctx->r2 = ctx->r11 | 0;
            goto L_80800BEC;
    }
    // 0x80800BD8: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80800BDC: jal         0x80102424
    // 0x80800BE0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x80800BE0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x80800BE4: b           L_80800C00
    // 0x80800BE8: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
        goto L_80800C00;
    // 0x80800BE8: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
L_80800BEC:
    // 0x80800BEC: bne         $v0, $at, L_80800BFC
    if (ctx->r2 != ctx->r1) {
        // 0x80800BF0: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80800BFC;
    }
    // 0x80800BF0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800BF4: jal         0x80102424
    // 0x80800BF8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x80800BF8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
L_80800BFC:
    // 0x80800BFC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
L_80800C00:
    // 0x80800C00: lbu         $t5, 0x7A($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X7A);
    // 0x80800C04: andi        $t6, $t5, 0xFF3F
    ctx->r14 = ctx->r13 & 0XFF3F;
    // 0x80800C08: ori         $t7, $t6, 0x80
    ctx->r15 = ctx->r14 | 0X80;
    // 0x80800C0C: sb          $t7, 0x7A($t4)
    MEM_B(0X7A, ctx->r12) = ctx->r15;
    // 0x80800C10: jal         0x8010A570
    // 0x80800C14: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_8010A570(rdram, ctx);
        goto after_6;
    // 0x80800C14: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_6:
    // 0x80800C18: b           L_80800D7C
    // 0x80800C1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D7C;
    // 0x80800C1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C20:
    // 0x80800C20: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800C24: jal         0x80102424
    // 0x80800C28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x80800C28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800C2C: b           L_80800D7C
    // 0x80800C30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D7C;
    // 0x80800C30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C34:
    // 0x80800C34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800C38: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80800C3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800C40: swc1        $f4, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f4.u32l;
    // 0x80800C44: jal         0x80102424
    // 0x80800C48: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x80800C48: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_8:
    // 0x80800C4C: b           L_80800D7C
    // 0x80800C50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D7C;
    // 0x80800C50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C54:
    // 0x80800C54: jal         0x80108B04
    // 0x80800C58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_9;
    // 0x80800C58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80800C5C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80800C60: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800C64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800C68: lhu         $t0, 0x76($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X76);
    // 0x80800C6C: srl         $t1, $t0, 7
    ctx->r9 = S32(U32(ctx->r8) >> 7);
    // 0x80800C70: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80800C74: bgez        $t1, L_80800C88
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800C78: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80800C88;
    }
    // 0x80800C78: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800C7C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800C80: nop

    // 0x80800C84: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80800C88:
    // 0x80800C88: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800C8C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800C90: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2332, 0X1290) << 16);
    // 0x80800C94: lwc1        $f4, 0x1290($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2332, 0X1290));
    // 0x80800C98: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80800C9C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800CA0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800CA4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800CA8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80800CAC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80800CB0: nop

    // 0x80800CB4: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800CB8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80800CBC: nop

    // 0x80800CC0: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80800CC4: beql        $t2, $zero, L_80800D14
    if (ctx->r10 == 0) {
        // 0x80800CC8: mfc1        $t2, $f10
        ctx->r10 = (int32_t)ctx->f10.u32l;
            goto L_80800D14;
    }
    goto skip_0;
    // 0x80800CC8: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x80800CCC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800CD0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800CD4: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80800CD8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80800CDC: nop

    // 0x80800CE0: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80800CE4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80800CE8: nop

    // 0x80800CEC: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80800CF0: bne         $t2, $zero, L_80800D08
    if (ctx->r10 != 0) {
        // 0x80800CF4: nop
    
            goto L_80800D08;
    }
    // 0x80800CF4: nop

    // 0x80800CF8: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80800CFC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800D00: b           L_80800D20
    // 0x80800D04: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80800D20;
    // 0x80800D04: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80800D08:
    // 0x80800D08: b           L_80800D20
    // 0x80800D0C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80800D20;
    // 0x80800D0C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80800D10: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
L_80800D14:
    // 0x80800D14: nop

    // 0x80800D18: bltz        $t2, L_80800D08
    if (SIGNED(ctx->r10) < 0) {
        // 0x80800D1C: nop
    
            goto L_80800D08;
    }
    // 0x80800D1C: nop

L_80800D20:
    // 0x80800D20: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80800D24: b           L_80800D7C
    // 0x80800D28: sh          $t2, 0x7C($t9)
    MEM_H(0X7C, ctx->r25) = ctx->r10;
        goto L_80800D7C;
    // 0x80800D28: sh          $t2, 0x7C($t9)
    MEM_H(0X7C, ctx->r25) = ctx->r10;
L_80800D2C:
    // 0x80800D2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800D30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800D34: lwc1        $f16, 0x38($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X38);
    // 0x80800D38: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800D3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800D40: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80800D44: lw          $a1, 0x48($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X48);
    // 0x80800D48: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800D4C: mul.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800D50: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800D54: jal         0x800EEB9C
    // 0x80800D58: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_800EEB9C(rdram, ctx);
        goto after_10;
    // 0x80800D58: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x80800D5C: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800D60: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800D64: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800D68: add.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80800D6C: jal         0x80101010
    // 0x80800D70: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    func_80101010(rdram, ctx);
        goto after_11;
    // 0x80800D70: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    after_11:
    // 0x80800D74: b           L_80800D7C
    // 0x80800D78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D7C;
    // 0x80800D78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D7C:
    // 0x80800D7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D80: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800D84: jr          $ra
    // 0x80800D88: nop

    return;
    // 0x80800D88: nop

;}
RECOMP_FUNC void bsbeemain_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003DC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808003E0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(80, 0X1270) << 16);
    // 0x808003E4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808003E8: jr          $ra
    // 0x808003EC: lw          $v0, 0x1270($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(80, 0X1270));
    return;
    // 0x808003EC: lw          $v0, 0x1270($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(80, 0X1270));
;}
RECOMP_FUNC void func_800E1804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1804: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800E1808: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x800E180C: sw          $s7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r23;
    // 0x800E1810: sw          $s6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r22;
    // 0x800E1814: sw          $s5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r21;
    // 0x800E1818: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    // 0x800E181C: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x800E1820: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x800E1824: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x800E1828: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x800E182C: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x800E1830: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x800E1834: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x800E1838: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800E183C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800E1840: jal         0x800D8FF8
    // 0x800E1844: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x800E1844: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x800E1848: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800E184C: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x800E1850: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E1854: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x800E1858: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800E185C: lwc1        $f26, 0x5D80($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X5D80);
    // 0x800E1860: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E1864: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800E1868: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800E186C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800E1870: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x800E1874: addiu       $s0, $s0, -0x3070
    ctx->r16 = ADD32(ctx->r16, -0X3070);
    // 0x800E1878: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800E187C: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x800E1880: addiu       $s6, $zero, 0xA
    ctx->r22 = ADD32(0, 0XA);
    // 0x800E1884: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x800E1888: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800E188C: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_800E1890:
    // 0x800E1890: lbu         $v0, 0x74($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X74);
    // 0x800E1894: beql        $v0, $s3, L_800E18B8
    if (ctx->r2 == ctx->r19) {
        // 0x800E1898: lwc1        $f4, 0x28($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
            goto L_800E18B8;
    }
    goto skip_0;
    // 0x800E1898: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    skip_0:
    // 0x800E189C: beql        $v0, $s4, L_800E18E4
    if (ctx->r2 == ctx->r20) {
        // 0x800E18A0: lwc1        $f0, 0x30($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
            goto L_800E18E4;
    }
    goto skip_1;
    // 0x800E18A0: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    skip_1:
    // 0x800E18A4: beql        $v0, $s5, L_800E19AC
    if (ctx->r2 == ctx->r21) {
        // 0x800E18A8: lwc1        $f0, 0x30($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
            goto L_800E19AC;
    }
    goto skip_2;
    // 0x800E18A8: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    skip_2:
    // 0x800E18AC: b           L_800E1A0C
    // 0x800E18B0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_800E1A0C;
    // 0x800E18B0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800E18B4: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
L_800E18B8:
    // 0x800E18B8: c.le.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl <= ctx->f4.fl;
    // 0x800E18BC: nop

    // 0x800E18C0: bc1fl       L_800E18D4
    if (!c1cs) {
        // 0x800E18C4: swc1        $f30, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->f30.u32l;
            goto L_800E18D4;
    }
    goto skip_3;
    // 0x800E18C4: swc1        $f30, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f30.u32l;
    skip_3:
    // 0x800E18C8: b           L_800E18D4
    // 0x800E18CC: swc1        $f28, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f28.u32l;
        goto L_800E18D4;
    // 0x800E18CC: swc1        $f28, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f28.u32l;
    // 0x800E18D0: swc1        $f30, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f30.u32l;
L_800E18D4:
    // 0x800E18D4: sb          $s7, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r23;
    // 0x800E18D8: b           L_800E1A08
    // 0x800E18DC: sb          $zero, 0x77($s0)
    MEM_B(0X77, ctx->r16) = 0;
        goto L_800E1A08;
    // 0x800E18DC: sb          $zero, 0x77($s0)
    MEM_B(0X77, ctx->r16) = 0;
    // 0x800E18E0: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
L_800E18E4:
    // 0x800E18E4: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x800E18E8: nop

    // 0x800E18EC: bc1tl       L_800E193C
    if (c1cs) {
        // 0x800E18F0: lbu         $v0, 0x77($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X77);
            goto L_800E193C;
    }
    goto skip_4;
    // 0x800E18F0: lbu         $v0, 0x77($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X77);
    skip_4:
    // 0x800E18F4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800E18F8: jal         0x800F0E00
    // 0x800E18FC: sub.s       $f14, $f0, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f22.fl;
    func_800F0E00(rdram, ctx);
        goto after_1;
    // 0x800E18FC: sub.s       $f14, $f0, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f22.fl;
    after_1:
    // 0x800E1900: lbu         $v0, 0x77($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X77);
    // 0x800E1904: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x800E1908: beql        $v0, $zero, L_800E1964
    if (ctx->r2 == 0) {
        // 0x800E190C: lwc1        $f6, 0x1C($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
            goto L_800E1964;
    }
    goto skip_5;
    // 0x800E190C: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    skip_5:
    // 0x800E1910: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800E1914: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800E1918: lwc1        $f12, 0x30($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800E191C: lwc1        $f14, 0x18($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800E1920: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    // 0x800E1924: jal         0x800F10B4
    // 0x800E1928: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x800E1928: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x800E192C: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x800E1930: b           L_800E1960
    // 0x800E1934: lbu         $v0, 0x77($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X77);
        goto L_800E1960;
    // 0x800E1934: lbu         $v0, 0x77($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X77);
    // 0x800E1938: lbu         $v0, 0x77($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X77);
L_800E193C:
    // 0x800E193C: beql        $v0, $zero, L_800E1964
    if (ctx->r2 == 0) {
        // 0x800E1940: lwc1        $f6, 0x1C($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
            goto L_800E1964;
    }
    goto skip_6;
    // 0x800E1940: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    skip_6:
    // 0x800E1944: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800E1948: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800E194C: lbu         $v0, 0x77($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X77);
    // 0x800E1950: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800E1954: nop

    // 0x800E1958: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800E195C: swc1        $f16, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f16.u32l;
L_800E1960:
    // 0x800E1960: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
L_800E1964:
    // 0x800E1964: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800E1968: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800E196C: c.eq.s      $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f24.fl == ctx->f6.fl;
    // 0x800E1970: sb          $t6, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r14;
    // 0x800E1974: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x800E1978: bc1t        L_800E1A08
    if (c1cs) {
        // 0x800E197C: swc1        $f4, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
            goto L_800E1A08;
    }
    // 0x800E197C: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x800E1980: jal         0x800F2100
    // 0x800E1984: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    mlAbsF(rdram, ctx);
        goto after_3;
    // 0x800E1984: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    after_3:
    // 0x800E1988: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
    // 0x800E198C: nop

    // 0x800E1990: bc1fl       L_800E1A0C
    if (!c1cs) {
        // 0x800E1994: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800E1A0C;
    }
    goto skip_7;
    // 0x800E1994: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_7:
    // 0x800E1998: jal         0x800E1720
    // 0x800E199C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800E1720(rdram, ctx);
        goto after_4;
    // 0x800E199C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x800E19A0: b           L_800E1A0C
    // 0x800E19A4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_800E1A0C;
    // 0x800E19A4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800E19A8: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
L_800E19AC:
    // 0x800E19AC: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800E19B0: addiu       $s1, $s0, 0x34
    ctx->r17 = ADD32(ctx->r16, 0X34);
    // 0x800E19B4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800E19B8: nop

    // 0x800E19BC: bc1f        L_800E1A00
    if (!c1cs) {
        // 0x800E19C0: nop
    
            goto L_800E1A00;
    }
    // 0x800E19C0: nop

    // 0x800E19C4: jal         0x800F13F0
    // 0x800E19C8: add.s       $f14, $f0, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f22.fl;
    func_800F13F0(rdram, ctx);
        goto after_5;
    // 0x800E19C8: add.s       $f14, $f0, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f22.fl;
    after_5:
    // 0x800E19CC: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800E19D0: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x800E19D4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800E19D8: lbu         $a2, 0x78($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X78);
    // 0x800E19DC: jal         0x800F3780
    // 0x800E19E0: div.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    func_800F3780(rdram, ctx);
        goto after_6;
    // 0x800E19E0: div.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    after_6:
    // 0x800E19E4: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800E19E8: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800E19EC: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800E19F0: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x800E19F4: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x800E19F8: b           L_800E1A08
    // 0x800E19FC: swc1        $f16, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f16.u32l;
        goto L_800E1A08;
    // 0x800E19FC: swc1        $f16, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f16.u32l;
L_800E1A00:
    // 0x800E1A00: jal         0x800E1720
    // 0x800E1A04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800E1720(rdram, ctx);
        goto after_7;
    // 0x800E1A04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
L_800E1A08:
    // 0x800E1A08: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800E1A0C:
    // 0x800E1A0C: bne         $s2, $s6, L_800E1890
    if (ctx->r18 != ctx->r22) {
        // 0x800E1A10: addiu       $s0, $s0, 0x7C
        ctx->r16 = ADD32(ctx->r16, 0X7C);
            goto L_800E1890;
    }
    // 0x800E1A10: addiu       $s0, $s0, 0x7C
    ctx->r16 = ADD32(ctx->r16, 0X7C);
    // 0x800E1A14: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800E1A18: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800E1A1C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800E1A20: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800E1A24: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x800E1A28: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x800E1A2C: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x800E1A30: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x800E1A34: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x800E1A38: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x800E1A3C: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x800E1A40: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
    // 0x800E1A44: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x800E1A48: lw          $s6, 0x64($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X64);
    // 0x800E1A4C: lw          $s7, 0x68($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X68);
    // 0x800E1A50: jr          $ra
    // 0x800E1A54: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800E1A54: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8080051C_bsdronexform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080051C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800520: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800524: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800528: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080052C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800530: jal         0x800D8FF8
    // 0x80800534: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800534: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x80800538: lw          $v0, 0x18C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18C);
    // 0x8080053C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80800540: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(208, 0X1180) << 16);
    // 0x80800544: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80800548: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8080054C: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x80800550: lw          $t6, 0x18C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18C);
    // 0x80800554: lwc1        $f8, 0x10($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X10);
    // 0x80800558: c.lt.s      $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f8.fl < ctx->f22.fl;
    // 0x8080055C: nop

    // 0x80800560: bc1fl       L_808005B8
    if (!c1cs) {
        // 0x80800564: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808005B8;
    }
    goto skip_0;
    // 0x80800564: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80800568: lwc1        $f20, 0x1180($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(208, 0X1180));
L_8080056C:
    // 0x8080056C: jal         0x808000E4
    // 0x80800570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000E4_bsdronexform(rdram, ctx);
        goto after_1;
    // 0x80800570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800574: lw          $v0, 0x18C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18C);
    // 0x80800578: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8080057C: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800580: mul.s       $f18, $f20, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x80800584: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80800588: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8080058C: lw          $v0, 0x18C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18C);
    // 0x80800590: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80800594: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x80800598: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
    // 0x8080059C: lw          $t7, 0x18C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X18C);
    // 0x808005A0: lwc1        $f16, 0x10($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X10);
    // 0x808005A4: c.lt.s      $f16, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f16.fl < ctx->f22.fl;
    // 0x808005A8: nop

    // 0x808005AC: bc1t        L_8080056C
    if (c1cs) {
        // 0x808005B0: nop
    
            goto L_8080056C;
    }
    // 0x808005B0: nop

    // 0x808005B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808005B8:
    // 0x808005B8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808005BC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808005C0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808005C4: jr          $ra
    // 0x808005C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808005C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_808000BC_indrv_audio(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808000C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808000CC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2970, 0X1478) << 16);
    // 0x808000D0: addiu       $a2, $a2, 0x1478
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2970, 0X1478));
    // 0x808000D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000D8: jal         0x800C4350
    // 0x808000DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C4350(rdram, ctx);
        goto after_0;
    // 0x808000DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x808000E0: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    // 0x808000E4: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x808000E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000EC: jal         0x800C4350
    // 0x808000F0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_800C4350(rdram, ctx);
        goto after_1;
    // 0x808000F0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x808000F4: jal         0x800C3BDC
    // 0x808000F8: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    func_800C3BDC(rdram, ctx);
        goto after_2;
    // 0x808000F8: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    after_2:
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800100: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800104: jr          $ra
    // 0x80800108: nop

    return;
    // 0x80800108: nop

;}
RECOMP_FUNC void func_800A046C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A046C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A0470: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A0474: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A0478: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A047C: jal         0x80095748
    // 0x800A0480: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    baflag_isFalse(rdram, ctx);
        goto after_0;
    // 0x800A0480: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_0:
    // 0x800A0484: bne         $v0, $zero, L_800A04E0
    if (ctx->r2 != 0) {
        // 0x800A0488: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A04E0;
    }
    // 0x800A0488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A048C: jal         0x80095738
    // 0x800A0490: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_isTrue(rdram, ctx);
        goto after_1;
    // 0x800A0490: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_1:
    // 0x800A0494: beq         $v0, $zero, L_800A04C4
    if (ctx->r2 == 0) {
        // 0x800A0498: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A04C4;
    }
    // 0x800A0498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A049C: jal         0x80095748
    // 0x800A04A0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    baflag_isFalse(rdram, ctx);
        goto after_2;
    // 0x800A04A0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
    // 0x800A04A4: beq         $v0, $zero, L_800A04C4
    if (ctx->r2 == 0) {
        // 0x800A04A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A04C4;
    }
    // 0x800A04A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A04AC: jal         0x80095748
    // 0x800A04B0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    baflag_isFalse(rdram, ctx);
        goto after_3;
    // 0x800A04B0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_3:
    // 0x800A04B4: beq         $v0, $zero, L_800A04C4
    if (ctx->r2 == 0) {
        // 0x800A04B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A04C4;
    }
    // 0x800A04B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A04BC: jal         0x80095774
    // 0x800A04C0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_clear(rdram, ctx);
        goto after_4;
    // 0x800A04C0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_4:
L_800A04C4:
    // 0x800A04C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A04C8: jal         0x80095774
    // 0x800A04CC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    baflag_clear(rdram, ctx);
        goto after_5;
    // 0x800A04CC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_5:
    // 0x800A04D0: jal         0x800831F0
    // 0x800A04D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsjig_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x800A04D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800A04D8: jal         0x800FC660
    // 0x800A04DC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800FC660(rdram, ctx);
        goto after_7;
    // 0x800A04DC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_7:
L_800A04E0:
    // 0x800A04E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A04E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A04E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A04EC: jr          $ra
    // 0x800A04F0: nop

    return;
    // 0x800A04F0: nop

;}
RECOMP_FUNC void _suexpression_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800897D0: syscall     795
    recomp_syscall_handler(rdram, ctx, 0x800897D0);
    return;
    // 0x800897D4: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_808006CC_chfactorycrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006CC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808006D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006D4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x808006D8: jal         0x80100094
    // 0x808006DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808006DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808006E0: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x808006E4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808006E8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808006EC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x808006F0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x808006F4: jal         0x800EE780
    // 0x808006F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800EE780(rdram, ctx);
        goto after_1;
    // 0x808006F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x808006FC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800700: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800704: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800708: jal         0x800EE780
    // 0x8080070C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800EE780(rdram, ctx);
        goto after_2;
    // 0x8080070C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_2:
    // 0x80800710: jal         0x800F54E4
    // 0x80800714: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x80800714: nop

    after_3:
    // 0x80800718: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080071C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800720: jal         0x800F4D18
    // 0x80800724: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_800F4D18(rdram, ctx);
        goto after_4;
    // 0x80800724: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x80800728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080072C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800730: jr          $ra
    // 0x80800734: nop

    return;
    // 0x80800734: nop

;}
RECOMP_FUNC void func_80800454_chstarspinnerstar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800454: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080045C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800460: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800464: lwc1        $f4, 0x2C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80800468: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8080046C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800470: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(956, 0X6A4) << 16);
    // 0x80800474: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800478: nop

    // 0x8080047C: bc1fl       L_80800490
    if (!c1cs) {
        // 0x80800480: lwc1        $f8, 0x1C($a1)
        ctx->f8.u32l = MEM_W(ctx->r5, 0X1C);
            goto L_80800490;
    }
    goto skip_0;
    // 0x80800480: lwc1        $f8, 0x1C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X1C);
    skip_0:
    // 0x80800484: b           L_80800498
    // 0x80800488: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
        goto L_80800498;
    // 0x80800488: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8080048C: lwc1        $f8, 0x1C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X1C);
L_80800490:
    // 0x80800490: lwc1        $f10, 0x6A4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(956, 0X6A4));
    // 0x80800494: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
L_80800498:
    // 0x80800498: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8080049C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(956, 0X6A8) << 16);
    // 0x808004A0: lwc1        $f4, 0x6A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(956, 0X6A8));
    // 0x808004A4: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x808004A8: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x808004AC: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808004B0: jal         0x800F2100
    // 0x808004B4: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    mlAbsF(rdram, ctx);
        goto after_0;
    // 0x808004B4: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x808004B8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x808004BC: jal         0x800DA298
    // 0x808004C0: addiu       $a0, $zero, 0x679
    ctx->r4 = ADD32(0, 0X679);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808004C0: addiu       $a0, $zero, 0x679
    ctx->r4 = ADD32(0, 0X679);
    after_1:
    // 0x808004C4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808004C8: beq         $v0, $zero, L_808004D8
    if (ctx->r2 == 0) {
        // 0x808004CC: lwc1        $f14, 0x20($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
            goto L_808004D8;
    }
    // 0x808004CC: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808004D0: b           L_808004DC
    // 0x808004D4: addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
        goto L_808004DC;
    // 0x808004D4: addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
L_808004D8:
    // 0x808004D8: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
L_808004DC:
    // 0x808004DC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x808004E0: lwc1        $f10, 0x2C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x808004E4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808004E8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808004EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808004F0: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808004F4: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808004F8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808004FC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800500: nop

    // 0x80800504: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800508: bc1f        L_8080053C
    if (!c1cs) {
        // 0x8080050C: nop
    
            goto L_8080053C;
    }
    // 0x8080050C: nop

    // 0x80800510: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800514: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80800518: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    // 0x8080051C: nop

    // 0x80800520: bc1f        L_80800534
    if (!c1cs) {
        // 0x80800524: nop
    
            goto L_80800534;
    }
    // 0x80800524: nop

    // 0x80800528: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080052C: b           L_80800570
    // 0x80800530: lwc1        $f0, 0x2C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X2C);
        goto L_80800570;
    // 0x80800530: lwc1        $f0, 0x2C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X2C);
L_80800534:
    // 0x80800534: b           L_8080056C
    // 0x80800538: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_8080056C;
    // 0x80800538: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_8080053C:
    // 0x8080053C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80800540: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x80800544: jal         0x800F2100
    // 0x80800548: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    mlAbsF(rdram, ctx);
        goto after_2;
    // 0x80800548: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x8080054C: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800550: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800554: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80800558: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8080055C: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800560: bc1fl       L_80800570
    if (!c1cs) {
        // 0x80800564: lwc1        $f0, 0x2C($a1)
        ctx->f0.u32l = MEM_W(ctx->r5, 0X2C);
            goto L_80800570;
    }
    goto skip_1;
    // 0x80800564: lwc1        $f0, 0x2C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X2C);
    skip_1:
    // 0x80800568: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
L_8080056C:
    // 0x8080056C: lwc1        $f0, 0x2C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X2C);
L_80800570:
    // 0x80800570: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800574: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80800578: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(956, 0X6AC) << 16);
    // 0x8080057C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80800580: add.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x80800584: bc1f        L_808005B4
    if (!c1cs) {
        // 0x80800588: swc1        $f16, 0x8($a1)
        MEM_W(0X8, ctx->r5) = ctx->f16.u32l;
            goto L_808005B4;
    }
    // 0x80800588: swc1        $f16, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f16.u32l;
    // 0x8080058C: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80800590: lwc1        $f6, 0x1C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80800594: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800598: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080059C: nop

    // 0x808005A0: bc1fl       L_808005E8
    if (!c1cs) {
        // 0x808005A4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808005E8;
    }
    goto skip_2;
    // 0x808005A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x808005A8: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x808005AC: b           L_808005E8
    // 0x808005B0: swc1        $f8, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f8.u32l;
        goto L_808005E8;
    // 0x808005B0: swc1        $f8, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f8.u32l;
L_808005B4:
    // 0x808005B4: lwc1        $f10, 0x1C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x808005B8: lwc1        $f16, 0x6AC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(956, 0X6AC));
    // 0x808005BC: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x808005C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808005C4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808005C8: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x808005CC: nop

    // 0x808005D0: bc1fl       L_808005E8
    if (!c1cs) {
        // 0x808005D4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808005E8;
    }
    goto skip_3;
    // 0x808005D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x808005D8: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x808005DC: b           L_808005E8
    // 0x808005E0: swc1        $f6, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f6.u32l;
        goto L_808005E8;
    // 0x808005E0: swc1        $f6, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f6.u32l;
    // 0x808005E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005E8:
    // 0x808005E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005F0: jr          $ra
    // 0x808005F4: nop

    return;
    // 0x808005F4: nop

;}
RECOMP_FUNC void vpwibble_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080036C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800370: jal         0x800D8FF8
    // 0x80800374: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800374: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800378: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8080037C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800380: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800384: lwc1        $f6, 0x2C($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X2C);
    // 0x80800388: lwc1        $f4, 0x24($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X24);
    // 0x8080038C: lw          $t7, 0x34($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X34);
    // 0x80800390: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800394: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800398: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8080039C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x808003A0: swc1        $f10, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f10.u32l;
    // 0x808003A4: lw          $t6, 0x1C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X1C);
    // 0x808003A8: blez        $t7, L_808003E0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x808003AC: addu        $a3, $v1, $t6
        ctx->r7 = ADD32(ctx->r3, ctx->r14);
            goto L_808003E0;
    }
    // 0x808003AC: addu        $a3, $v1, $t6
    ctx->r7 = ADD32(ctx->r3, ctx->r14);
    // 0x808003B0: addiu       $v1, $a2, 0x38
    ctx->r3 = ADD32(ctx->r6, 0X38);
    // 0x808003B4: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
L_808003B8:
    // 0x808003B8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x808003BC: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x808003C0: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808003C4: mflo        $t9
    ctx->r25 = lo;
    // 0x808003C8: addu        $t0, $a3, $t9
    ctx->r8 = ADD32(ctx->r7, ctx->r25);
    // 0x808003CC: sb          $a1, 0x3($t0)
    MEM_B(0X3, ctx->r8) = ctx->r5;
    // 0x808003D0: lw          $t1, 0x34($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X34);
    // 0x808003D4: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x808003D8: bnel        $at, $zero, L_808003B8
    if (ctx->r1 != 0) {
        // 0x808003DC: lh          $t8, 0x0($v1)
        ctx->r24 = MEM_H(ctx->r3, 0X0);
            goto L_808003B8;
    }
    goto skip_0;
    // 0x808003DC: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    skip_0:
L_808003E0:
    // 0x808003E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003E8: jr          $ra
    // 0x808003EC: nop

    return;
    // 0x808003EC: nop

;}
RECOMP_FUNC void func_80800328_chsecreteggs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800328: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080032C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800330: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80800334: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800338: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080033C: beq         $a1, $at, L_80800360
    if (ctx->r5 == ctx->r1) {
        // 0x80800340: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80800360;
    }
    // 0x80800340: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800344: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80800348: beq         $a1, $at, L_80800388
    if (ctx->r5 == ctx->r1) {
        // 0x8080034C: addiu       $at, $zero, 0x3E
        ctx->r1 = ADD32(0, 0X3E);
            goto L_80800388;
    }
    // 0x8080034C: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80800350: beq         $a1, $at, L_808003E8
    if (ctx->r5 == ctx->r1) {
        // 0x80800354: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808003E8;
    }
    // 0x80800354: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800358: b           L_80800468
    // 0x8080035C: nop

        goto L_80800468;
    // 0x8080035C: nop

L_80800360:
    // 0x80800360: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800364: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080036C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800370: beq         $t7, $at, L_80800380
    if (ctx->r15 == ctx->r1) {
        // 0x80800374: nop
    
            goto L_80800380;
    }
    // 0x80800374: nop

    // 0x80800378: jal         0x80102424
    // 0x8080037C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x8080037C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
L_80800380:
    // 0x80800380: b           L_80800468
    // 0x80800384: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800468;
    // 0x80800384: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800388:
    // 0x80800388: jal         0x801015D0
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_1;
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800390: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
    // 0x80800394: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2472, 0X494) << 16);
    // 0x80800398: addiu       $at, $zero, 0x1D4
    ctx->r1 = ADD32(0, 0X1D4);
    // 0x8080039C: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x808003A0: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x808003A4: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x808003A8: lhu         $v0, 0x494($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(2472, 0X494));
    // 0x808003AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808003B0: beq         $v0, $at, L_808003C8
    if (ctx->r2 == ctx->r1) {
        // 0x808003B4: addiu       $at, $zero, 0x1D5
        ctx->r1 = ADD32(0, 0X1D5);
            goto L_808003C8;
    }
    // 0x808003B4: addiu       $at, $zero, 0x1D5
    ctx->r1 = ADD32(0, 0X1D5);
    // 0x808003B8: beq         $v0, $at, L_808003D8
    if (ctx->r2 == ctx->r1) {
        // 0x808003BC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_808003D8;
    }
    // 0x808003BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808003C0: b           L_80800468
    // 0x808003C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800468;
    // 0x808003C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003C8:
    // 0x808003C8: jal         0x800DF744
    // 0x808003CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x808003CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808003D0: b           L_80800468
    // 0x808003D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800468;
    // 0x808003D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003D8:
    // 0x808003D8: jal         0x800DF744
    // 0x808003DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x808003DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808003E0: b           L_80800468
    // 0x808003E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800468;
    // 0x808003E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003E8:
    // 0x808003E8: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x808003EC: addiu       $at, $zero, 0x974
    ctx->r1 = ADD32(0, 0X974);
    // 0x808003F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808003F4: lhu         $v0, 0x14($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X14);
    // 0x808003F8: beq         $v0, $at, L_80800418
    if (ctx->r2 == ctx->r1) {
        // 0x808003FC: addiu       $at, $zero, 0x975
        ctx->r1 = ADD32(0, 0X975);
            goto L_80800418;
    }
    // 0x808003FC: addiu       $at, $zero, 0x975
    ctx->r1 = ADD32(0, 0X975);
    // 0x80800400: bne         $v0, $at, L_80800424
    if (ctx->r2 != ctx->r1) {
        // 0x80800404: nop
    
            goto L_80800424;
    }
    // 0x80800404: nop

    // 0x80800408: jal         0x800DA544
    // 0x8080040C: addiu       $a0, $zero, 0x3E3
    ctx->r4 = ADD32(0, 0X3E3);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x8080040C: addiu       $a0, $zero, 0x3E3
    ctx->r4 = ADD32(0, 0X3E3);
    after_4:
    // 0x80800410: b           L_80800424
    // 0x80800414: addiu       $a1, $zero, 0x1551
    ctx->r5 = ADD32(0, 0X1551);
        goto L_80800424;
    // 0x80800414: addiu       $a1, $zero, 0x1551
    ctx->r5 = ADD32(0, 0X1551);
L_80800418:
    // 0x80800418: jal         0x800DA544
    // 0x8080041C: addiu       $a0, $zero, 0x3E5
    ctx->r4 = ADD32(0, 0X3E5);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x8080041C: addiu       $a0, $zero, 0x3E5
    ctx->r4 = ADD32(0, 0X3E5);
    after_5:
    // 0x80800420: addiu       $a1, $zero, 0x1552
    ctx->r5 = ADD32(0, 0X1552);
L_80800424:
    // 0x80800424: beq         $a1, $zero, L_80800440
    if (ctx->r5 == 0) {
        // 0x80800428: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_80800440;
    }
    // 0x80800428: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8080042C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800430: addiu       $t2, $zero, 0x6F
    ctx->r10 = ADD32(0, 0X6F);
    // 0x80800434: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800438: jal         0x8008A208
    // 0x8080043C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x8080043C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_6:
L_80800440:
    // 0x80800440: jal         0x800D1844
    // 0x80800444: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    func_800D1844(rdram, ctx);
        goto after_7;
    // 0x80800444: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    after_7:
    // 0x80800448: jal         0x80800000
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chsecreteggs(rdram, ctx);
        goto after_8;
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800450: jal         0x800FC660
    // 0x80800454: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_9;
    // 0x80800454: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_9:
    // 0x80800458: jal         0x800FFA88
    // 0x8080045C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_10;
    // 0x8080045C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_10:
    // 0x80800460: b           L_80800468
    // 0x80800464: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800468;
    // 0x80800464: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800468:
    // 0x80800468: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080046C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800470: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800474: jr          $ra
    // 0x80800478: nop

    return;
    // 0x80800478: nop

;}
RECOMP_FUNC void _bsfirstp_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084350: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x80084350);
    return;
    // 0x80084354: addi        $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
;}
RECOMP_FUNC void func_800CEC94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEC94: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800CEC98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CEC9C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800CECA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800CECA4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800CECA8: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800CECAC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CECB0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800CECB4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800CECB8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800CECBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CECC0: bc1f        L_800CECCC
    if (!c1cs) {
        // 0x800CECC4: nop
    
            goto L_800CECCC;
    }
    // 0x800CECC4: nop

    // 0x800CECC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800CECCC:
    // 0x800CECCC: beql        $v0, $zero, L_800CECF4
    if (ctx->r2 == 0) {
        // 0x800CECD0: c.lt.s      $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
            goto L_800CECF4;
    }
    goto skip_0;
    // 0x800CECD0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    skip_0:
    // 0x800CECD4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CECD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CECDC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800CECE0: nop

    // 0x800CECE4: bc1fl       L_800CECF4
    if (!c1cs) {
        // 0x800CECE8: c.lt.s      $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
            goto L_800CECF4;
    }
    goto skip_1;
    // 0x800CECE8: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    skip_1:
    // 0x800CECEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CECF0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
L_800CECF4:
    // 0x800CECF4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800CECF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CECFC: bc1f        L_800CED08
    if (!c1cs) {
        // 0x800CED00: nop
    
            goto L_800CED08;
    }
    // 0x800CED00: nop

    // 0x800CED04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800CED08:
    // 0x800CED08: beql        $v0, $zero, L_800CED28
    if (ctx->r2 == 0) {
        // 0x800CED0C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800CED28;
    }
    goto skip_2;
    // 0x800CED0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    skip_2:
    // 0x800CED10: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800CED14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CED18: bc1fl       L_800CED28
    if (!c1cs) {
        // 0x800CED1C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800CED28;
    }
    goto skip_3;
    // 0x800CED1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    skip_3:
    // 0x800CED20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CED24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800CED28:
    // 0x800CED28: lb          $v0, 0x12($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X12);
    // 0x800CED2C: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800CED30: beq         $t6, $zero, L_800CED70
    if (ctx->r14 == 0) {
        // 0x800CED34: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_800CED70;
    }
    // 0x800CED34: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800CED38: lbu         $v0, 0x13($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X13);
    // 0x800CED3C: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800CED40: beq         $t7, $zero, L_800CED70
    if (ctx->r15 == 0) {
        // 0x800CED44: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800CED70;
    }
    // 0x800CED44: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800CED48: lbu         $v0, 0x14($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X14);
    // 0x800CED4C: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800CED50: beq         $t8, $zero, L_800CED70
    if (ctx->r24 == 0) {
        // 0x800CED54: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_800CED70;
    }
    // 0x800CED54: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800CED58: sltiu       $v0, $a2, 0x1
    ctx->r2 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x800CED5C: bne         $v0, $zero, L_800CED70
    if (ctx->r2 != 0) {
        // 0x800CED60: nop
    
            goto L_800CED70;
    }
    // 0x800CED60: nop

    // 0x800CED64: lbu         $v0, 0x15($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X15);
    // 0x800CED68: sltu        $t9, $zero, $v0
    ctx->r25 = 0 < ctx->r2 ? 1 : 0;
    // 0x800CED6C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800CED70:
    // 0x800CED70: bnel        $v0, $zero, L_800CED84
    if (ctx->r2 != 0) {
        // 0x800CED74: sltu        $t0, $zero, $a1
        ctx->r8 = 0 < ctx->r5 ? 1 : 0;
            goto L_800CED84;
    }
    goto skip_4;
    // 0x800CED74: sltu        $t0, $zero, $a1
    ctx->r8 = 0 < ctx->r5 ? 1 : 0;
    skip_4:
    // 0x800CED78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CED7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CED80: sltu        $t0, $zero, $a1
    ctx->r8 = 0 < ctx->r5 ? 1 : 0;
L_800CED84:
    // 0x800CED84: bne         $t0, $zero, L_800CEDA0
    if (ctx->r8 != 0) {
        // 0x800CED88: sw          $t0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r8;
            goto L_800CEDA0;
    }
    // 0x800CED88: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800CED8C: bnel        $a0, $zero, L_800CEDA4
    if (ctx->r4 != 0) {
        // 0x800CED90: lw          $t4, 0x20($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X20);
            goto L_800CEDA4;
    }
    goto skip_5;
    // 0x800CED90: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    skip_5:
    // 0x800CED94: lbu         $t2, 0x16($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X16);
    // 0x800CED98: beql        $t2, $zero, L_800CEEF4
    if (ctx->r10 == 0) {
        // 0x800CED9C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CEEF4;
    }
    goto skip_6;
    // 0x800CED9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
L_800CEDA0:
    // 0x800CEDA0: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
L_800CEDA4:
    // 0x800CEDA4: sltu        $t3, $zero, $a0
    ctx->r11 = 0 < ctx->r4 ? 1 : 0;
    // 0x800CEDA8: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800CEDAC: beq         $t4, $zero, L_800CEE3C
    if (ctx->r12 == 0) {
        // 0x800CEDB0: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800CEE3C;
    }
    // 0x800CEDB0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800CEDB4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800CEDB8: addiu       $v1, $v1, -0x4FD0
    ctx->r3 = ADD32(ctx->r3, -0X4FD0);
    // 0x800CEDBC: lbu         $t5, 0x121($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X121);
    // 0x800CEDC0: addiu       $a0, $zero, 0x92
    ctx->r4 = ADD32(0, 0X92);
    // 0x800CEDC4: bnel        $t5, $zero, L_800CEDF8
    if (ctx->r13 != 0) {
        // 0x800CEDC8: sub.s       $f8, $f0, $f12
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_800CEDF8;
    }
    goto skip_7;
    // 0x800CEDC8: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    skip_7:
    // 0x800CEDCC: jal         0x800FC6B0
    // 0x800CEDD0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_800FC6B0(rdram, ctx);
        goto after_0;
    // 0x800CEDD0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_0:
    // 0x800CEDD4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800CEDD8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800CEDDC: addiu       $v1, $v1, -0x4FD0
    ctx->r3 = ADD32(ctx->r3, -0X4FD0);
    // 0x800CEDE0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800CEDE4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CEDE8: sb          $t6, 0x121($v1)
    MEM_B(0X121, ctx->r3) = ctx->r14;
    // 0x800CEDEC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800CEDF0: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800CEDF4: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
L_800CEDF8:
    // 0x800CEDF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CEDFC: lwc1        $f2, 0x59C4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X59C4);
    // 0x800CEE00: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800CEE04: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800CEE08: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800CEE0C: addiu       $a0, $zero, 0x92
    ctx->r4 = ADD32(0, 0X92);
    // 0x800CEE10: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800CEE14: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800CEE18: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x800CEE1C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800CEE20: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800CEE24: jal         0x800FCD14
    // 0x800CEE28: nop

    func_800FCD14(rdram, ctx);
        goto after_1;
    // 0x800CEE28: nop

    after_1:
    // 0x800CEE2C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800CEE30: addiu       $v1, $v1, -0x4FD0
    ctx->r3 = ADD32(ctx->r3, -0X4FD0);
    // 0x800CEE34: b           L_800CEE68
    // 0x800CEE38: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
        goto L_800CEE68;
    // 0x800CEE38: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
L_800CEE3C:
    // 0x800CEE3C: addiu       $v1, $v1, -0x4FD0
    ctx->r3 = ADD32(ctx->r3, -0X4FD0);
    // 0x800CEE40: lbu         $t8, 0x121($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X121);
    // 0x800CEE44: addiu       $a0, $zero, 0x92
    ctx->r4 = ADD32(0, 0X92);
    // 0x800CEE48: beql        $t8, $zero, L_800CEE6C
    if (ctx->r24 == 0) {
        // 0x800CEE4C: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_800CEE6C;
    }
    goto skip_8;
    // 0x800CEE4C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x800CEE50: jal         0x800FC74C
    // 0x800CEE54: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_800FC74C(rdram, ctx);
        goto after_2;
    // 0x800CEE54: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_2:
    // 0x800CEE58: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800CEE5C: addiu       $v1, $v1, -0x4FD0
    ctx->r3 = ADD32(ctx->r3, -0X4FD0);
    // 0x800CEE60: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800CEE64: sb          $zero, 0x121($v1)
    MEM_B(0X121, ctx->r3) = 0;
L_800CEE68:
    // 0x800CEE68: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
L_800CEE6C:
    // 0x800CEE6C: beql        $t9, $zero, L_800CEEBC
    if (ctx->r25 == 0) {
        // 0x800CEE70: lbu         $a0, 0x120($v1)
        ctx->r4 = MEM_BU(ctx->r3, 0X120);
            goto L_800CEEBC;
    }
    goto skip_9;
    // 0x800CEE70: lbu         $a0, 0x120($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X120);
    skip_9:
    // 0x800CEE74: lbu         $a0, 0x120($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X120);
    // 0x800CEE78: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800CEE7C: addiu       $a2, $a2, -0x5598
    ctx->r6 = ADD32(ctx->r6, -0X5598);
    // 0x800CEE80: bne         $a0, $zero, L_800CEEA8
    if (ctx->r4 != 0) {
        // 0x800CEE84: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800CEEA8;
    }
    // 0x800CEE84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CEE88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CEE8C: jal         0x800C4350
    // 0x800CEE90: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_800C4350(rdram, ctx);
        goto after_3;
    // 0x800CEE90: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_3:
    // 0x800CEE94: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800CEE98: addiu       $v1, $v1, -0x4FD0
    ctx->r3 = ADD32(ctx->r3, -0X4FD0);
    // 0x800CEE9C: sb          $v0, 0x120($v1)
    MEM_B(0X120, ctx->r3) = ctx->r2;
    // 0x800CEEA0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800CEEA4: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
L_800CEEA8:
    // 0x800CEEA8: jal         0x800C3BDC
    // 0x800CEEAC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_800C3BDC(rdram, ctx);
        goto after_4;
    // 0x800CEEAC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_4:
    // 0x800CEEB0: b           L_800CEEDC
    // 0x800CEEB4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
        goto L_800CEEDC;
    // 0x800CEEB4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800CEEB8: lbu         $a0, 0x120($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X120);
L_800CEEBC:
    // 0x800CEEBC: beql        $a0, $zero, L_800CEEE0
    if (ctx->r4 == 0) {
        // 0x800CEEC0: lw          $v0, 0x20($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X20);
            goto L_800CEEE0;
    }
    goto skip_10;
    // 0x800CEEC0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    skip_10:
    // 0x800CEEC4: jal         0x800C2FDC
    // 0x800CEEC8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_800C2FDC(rdram, ctx);
        goto after_5;
    // 0x800CEEC8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_5:
    // 0x800CEECC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800CEED0: addiu       $v1, $v1, -0x4FD0
    ctx->r3 = ADD32(ctx->r3, -0X4FD0);
    // 0x800CEED4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800CEED8: sb          $zero, 0x120($v1)
    MEM_B(0X120, ctx->r3) = 0;
L_800CEEDC:
    // 0x800CEEDC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_800CEEE0:
    // 0x800CEEE0: bnel        $v0, $zero, L_800CEEF0
    if (ctx->r2 != 0) {
        // 0x800CEEE4: sb          $v0, 0x16($a3)
        MEM_B(0X16, ctx->r7) = ctx->r2;
            goto L_800CEEF0;
    }
    goto skip_11;
    // 0x800CEEE4: sb          $v0, 0x16($a3)
    MEM_B(0X16, ctx->r7) = ctx->r2;
    skip_11:
    // 0x800CEEE8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800CEEEC: sb          $v0, 0x16($a3)
    MEM_B(0X16, ctx->r7) = ctx->r2;
L_800CEEF0:
    // 0x800CEEF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CEEF4:
    // 0x800CEEF4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800CEEF8: jr          $ra
    // 0x800CEEFC: nop

    return;
    // 0x800CEEFC: nop

;}
RECOMP_FUNC void basub_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005E8: lw          $v0, 0x130($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X130);
    // 0x808005EC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808005F0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808005F4: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x808005F8: addiu       $a1, $zero, 0x52A
    ctx->r5 = ADD32(0, 0X52A);
    // 0x808005FC: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800600: nop

    // 0x80800604: bc1fl       L_8080063C
    if (!c1cs) {
        // 0x80800608: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080063C;
    }
    goto skip_0;
    // 0x80800608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080060C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800610: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800614: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    // 0x80800618: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x8080061C: jal         0x8009DB04
    // 0x80800620: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009DB04(rdram, ctx);
        goto after_0;
    // 0x80800620: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800624: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800628: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8080062C: addiu       $a0, $a0, 0x51A0
    ctx->r4 = ADD32(ctx->r4, 0X51A0);
    // 0x80800630: jal         0x80086D30
    // 0x80800634: lw          $a1, 0x184($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X184);
    _chbaddiesetup_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800634: lw          $a1, 0x184($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X184);
    after_1:
    // 0x80800638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080063C:
    // 0x8080063C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800640: jr          $ra
    // 0x80800644: nop

    return;
    // 0x80800644: nop

;}
RECOMP_FUNC void gcdialogcamera_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808006B8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808006BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006C0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808006C4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808006C8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x808006CC: jal         0x80800000
    // 0x808006D0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_80800000_gcdialogcamera(rdram, ctx);
        goto after_0;
    // 0x808006D0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x808006D4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x808006D8: lbu         $t6, 0x167($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X167);
    // 0x808006DC: beql        $t6, $zero, L_808007B0
    if (ctx->r14 == 0) {
        // 0x808006E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808007B0;
    }
    goto skip_0;
    // 0x808006E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808006E4: lw          $a0, 0x168($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X168);
    // 0x808006E8: jal         0x8080003C
    // 0x808006EC: lw          $a1, 0x16C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X16C);
    func_8080003C_gcdialogcamera(rdram, ctx);
        goto after_1;
    // 0x808006EC: lw          $a1, 0x16C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X16C);
    after_1:
    // 0x808006F0: beq         $v0, $zero, L_80800788
    if (ctx->r2 == 0) {
        // 0x808006F4: nop
    
            goto L_80800788;
    }
    // 0x808006F4: nop

    // 0x808006F8: jal         0x800856C0
    // 0x808006FC: nop

    _capod_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x808006FC: nop

    after_2:
    // 0x80800700: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800704: beq         $v0, $at, L_8080071C
    if (ctx->r2 == ctx->r1) {
        // 0x80800708: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8080071C;
    }
    // 0x80800708: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8080070C: beq         $v0, $at, L_80800724
    if (ctx->r2 == ctx->r1) {
        // 0x80800710: addiu       $a0, $zero, 0x57
        ctx->r4 = ADD32(0, 0X57);
            goto L_80800724;
    }
    // 0x80800710: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    // 0x80800714: b           L_80800740
    // 0x80800718: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
        goto L_80800740;
    // 0x80800718: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
L_8080071C:
    // 0x8080071C: jal         0x80800620
    // 0x80800720: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80800620_gcdialogcamera(rdram, ctx);
        goto after_3;
    // 0x80800720: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
L_80800724:
    // 0x80800724: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80800728: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080072C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800730: jal         0x80800664
    // 0x80800734: lw          $a0, 0x168($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X168);
    gcdialogcamera_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x80800734: lw          $a0, 0x168($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X168);
    after_4:
    // 0x80800738: b           L_808007B0
    // 0x8080073C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808007B0;
    // 0x8080073C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800740:
    // 0x80800740: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80800744: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80800748: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8080074C: or          $a1, $t9, $t0
    ctx->r5 = ctx->r25 | ctx->r8;
    // 0x80800750: jal         0x800856A0
    // 0x80800754: lw          $a2, 0x168($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X168);
    _capod_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80800754: lw          $a2, 0x168($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X168);
    after_5:
    // 0x80800758: beq         $v0, $zero, L_808007AC
    if (ctx->r2 == 0) {
        // 0x8080075C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808007AC;
    }
    // 0x8080075C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800760: beq         $v0, $at, L_808007AC
    if (ctx->r2 == ctx->r1) {
        // 0x80800764: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808007AC;
    }
    // 0x80800764: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800768: bne         $v0, $at, L_808007AC
    if (ctx->r2 != ctx->r1) {
        // 0x8080076C: lw          $t2, 0x28($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X28);
            goto L_808007AC;
    }
    // 0x8080076C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80800770: lw          $a0, 0x168($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X168);
    // 0x80800774: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800778: jal         0x80800664
    // 0x8080077C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    gcdialogcamera_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x8080077C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x80800780: b           L_808007B0
    // 0x80800784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808007B0;
    // 0x80800784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800788:
    // 0x80800788: jal         0x800856C0
    // 0x8080078C: nop

    _capod_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x8080078C: nop

    after_7:
    // 0x80800790: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800794: bne         $v0, $at, L_808007AC
    if (ctx->r2 != ctx->r1) {
        // 0x80800798: lw          $t3, 0x28($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X28);
            goto L_808007AC;
    }
    // 0x80800798: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8080079C: lw          $a0, 0x168($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X168);
    // 0x808007A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808007A4: jal         0x80800664
    // 0x808007A8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    gcdialogcamera_entrypoint_9(rdram, ctx);
        goto after_8;
    // 0x808007A8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_8:
L_808007AC:
    // 0x808007AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007B0:
    // 0x808007B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808007B4: jr          $ra
    // 0x808007B8: nop

    return;
    // 0x808007B8: nop

    // 0x808007BC: nop

;}
RECOMP_FUNC void func_80802288_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802288: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080228C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802290: jal         0x80100094
    // 0x80802294: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802294: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802298: lbu         $t6, 0x12B($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X12B);
    // 0x8080229C: beql        $t6, $zero, L_808022B8
    if (ctx->r14 == 0) {
        // 0x808022A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808022B8;
    }
    goto skip_0;
    // 0x808022A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808022A4: jal         0x80085710
    // 0x808022A8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _capod_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x808022A8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808022AC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808022B0: sb          $zero, 0x12B($v1)
    MEM_B(0X12B, ctx->r3) = 0;
    // 0x808022B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808022B8:
    // 0x808022B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808022BC: jr          $ra
    // 0x808022C0: nop

    return;
    // 0x808022C0: nop

;}
RECOMP_FUNC void _chegggolden_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800871F8: syscall     536
    recomp_syscall_handler(rdram, ctx, 0x800871F8);
    return;
    // 0x800871FC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chdoormake_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800868C0: syscall     393
    recomp_syscall_handler(rdram, ctx, 0x800868C0);
    return;
    // 0x800868C4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_808000E8_chtemplebossdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000EC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000F0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808000F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000FC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800100: beq         $a1, $at, L_80800128
    if (ctx->r5 == ctx->r1) {
        // 0x80800104: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80800128;
    }
    // 0x80800104: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800108: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x8080010C: beq         $a1, $at, L_80800174
    if (ctx->r5 == ctx->r1) {
        // 0x80800110: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800174;
    }
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800114: addiu       $at, $zero, 0x59
    ctx->r1 = ADD32(0, 0X59);
    // 0x80800118: beq         $a1, $at, L_80800184
    if (ctx->r5 == ctx->r1) {
        // 0x8080011C: nop
    
            goto L_80800184;
    }
    // 0x8080011C: nop

    // 0x80800120: b           L_808001A0
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808001A0;
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800128:
    // 0x80800128: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
    // 0x8080012C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80800130: addiu       $a2, $zero, 0x106
    ctx->r6 = ADD32(0, 0X106);
    // 0x80800134: srl         $t7, $v0, 7
    ctx->r15 = S32(U32(ctx->r2) >> 7);
    // 0x80800138: addiu       $v0, $t7, -0x32
    ctx->r2 = ADD32(ctx->r15, -0X32);
    // 0x8080013C: beq         $t8, $v0, L_8080014C
    if (ctx->r24 == ctx->r2) {
        // 0x80800140: addiu       $a3, $s0, 0x4
        ctx->r7 = ADD32(ctx->r16, 0X4);
            goto L_8080014C;
    }
    // 0x80800140: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x80800144: b           L_808001AC
    // 0x80800148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001AC;
    // 0x80800148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080014C:
    // 0x8080014C: beq         $v0, $zero, L_8080015C
    if (ctx->r2 == 0) {
        // 0x80800150: addiu       $t9, $zero, 0xB2
        ctx->r25 = ADD32(0, 0XB2);
            goto L_8080015C;
    }
    // 0x80800150: addiu       $t9, $zero, 0xB2
    ctx->r25 = ADD32(0, 0XB2);
    // 0x80800154: b           L_80800160
    // 0x80800158: addiu       $a1, $zero, 0xF3B
    ctx->r5 = ADD32(0, 0XF3B);
        goto L_80800160;
    // 0x80800158: addiu       $a1, $zero, 0xF3B
    ctx->r5 = ADD32(0, 0XF3B);
L_8080015C:
    // 0x8080015C: addiu       $a1, $zero, 0xF3A
    ctx->r5 = ADD32(0, 0XF3A);
L_80800160:
    // 0x80800160: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800164: jal         0x8008A208
    // 0x80800168: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80800168: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x8080016C: b           L_808001A0
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808001A0;
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800174:
    // 0x80800174: jal         0x80108BD4
    // 0x80800178: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108BD4(rdram, ctx);
        goto after_1;
    // 0x80800178: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080017C: b           L_808001AC
    // 0x80800180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001AC;
    // 0x80800180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800184:
    // 0x80800184: jal         0x80085710
    // 0x80800188: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_2;
    // 0x80800188: nop

    after_2:
    // 0x8080018C: jal         0x800FFA88
    // 0x80800190: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_3;
    // 0x80800190: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x80800194: b           L_808001AC
    // 0x80800198: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001AC;
    // 0x80800198: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001A0:
    // 0x808001A0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808001A4: jal         0x80086248
    // 0x808001A8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    _chdoor_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x808001A8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_4:
L_808001AC:
    // 0x808001AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808001B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001B8: jr          $ra
    // 0x808001BC: nop

    return;
    // 0x808001BC: nop

;}
RECOMP_FUNC void bstimeout_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800310: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800314: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(400, 0X340) << 16);
    // 0x80800318: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080031C: jr          $ra
    // 0x80800320: lw          $v0, 0x340($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(400, 0X340));
    return;
    // 0x80800320: lw          $v0, 0x340($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(400, 0X340));
    // 0x80800324: nop

    // 0x80800328: nop

    // 0x8080032C: nop

;}
RECOMP_FUNC void _chpowerhutwitchy_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086078: syscall     275
    recomp_syscall_handler(rdram, ctx, 0x80086078);
    return;
    // 0x8008607C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8080025C_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080025C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800260: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800264: jal         0x808007D8
    // 0x80800268: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808007D8_chbanjoctrl(rdram, ctx);
        goto after_0;
    // 0x80800268: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080026C: beq         $v0, $zero, L_80800294
    if (ctx->r2 == 0) {
        // 0x80800270: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800294;
    }
    // 0x80800270: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800274: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80800278: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8080027C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800280: nop

    // 0x80800284: bc1fl       L_80800298
    if (!c1cs) {
        // 0x80800288: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800298;
    }
    goto skip_0;
    // 0x80800288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080028C: jal         0x800904C8
    // 0x80800290: addiu       $a0, $zero, 0x91
    ctx->r4 = ADD32(0, 0X91);
    func_800904C8(rdram, ctx);
        goto after_1;
    // 0x80800290: addiu       $a0, $zero, 0x91
    ctx->r4 = ADD32(0, 0X91);
    after_1:
L_80800294:
    // 0x80800294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800298:
    // 0x80800298: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080029C: jr          $ra
    // 0x808002A0: nop

    return;
    // 0x808002A0: nop

;}
RECOMP_FUNC void _bafpctrl_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084CB0: syscall     133
    recomp_syscall_handler(rdram, ctx, 0x80084CB0);
    return;
    // 0x80084CB4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
