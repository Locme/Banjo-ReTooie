#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8009E4E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E4E0: lw          $t6, 0x114($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X114);
    // 0x8009E4E4: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8009E4E8: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x8009E4EC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8009E4F0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8009E4F4: jr          $ra
    // 0x8009E4F8: sw          $a2, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r6;
    return;
    // 0x8009E4F8: sw          $a2, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r6;
;}
RECOMP_FUNC void func_800A8A44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8A44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A8A48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A8A4C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A8A50: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800A8A54: jal         0x800A8380
    // 0x800A8A58: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800A8380(rdram, ctx);
        goto after_0;
    // 0x800A8A58: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A8A5C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800A8A60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A8A64: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A8A68: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800A8A6C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800A8A70: jal         0x800A8424
    // 0x800A8A74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800A8424(rdram, ctx);
        goto after_1;
    // 0x800A8A74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x800A8A78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A8A7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A8A80: jr          $ra
    // 0x800A8A84: nop

    return;
    // 0x800A8A84: nop

;}
RECOMP_FUNC void func_80805F68_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805F68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80805F6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80805F70: jal         0x8009B4FC
    // 0x80805F74: nop

    func_8009B4FC(rdram, ctx);
        goto after_0;
    // 0x80805F74: nop

    after_0:
    // 0x80805F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80805F7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80805F80: jr          $ra
    // 0x80805F84: nop

    return;
    // 0x80805F84: nop

;}
RECOMP_FUNC void cothemedll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800578: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080057C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800584: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800588: bne         $a1, $at, L_808005B0
    if (ctx->r5 != ctx->r1) {
        // 0x8080058C: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_808005B0;
    }
    // 0x8080058C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80800590: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80800594: addiu       $a1, $zero, 0xFA0
    ctx->r5 = ADD32(0, 0XFA0);
    // 0x80800598: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8080059C: jal         0x800FC348
    // 0x808005A0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800FC348(rdram, ctx);
        goto after_0;
    // 0x808005A0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x808005A4: jal         0x800FECB8
    // 0x808005A8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800FECB8(rdram, ctx);
        goto after_1;
    // 0x808005A8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x808005AC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_808005B0:
    // 0x808005B0: beq         $a3, $zero, L_808005F0
    if (ctx->r7 == 0) {
        // 0x808005B4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808005F0;
    }
    // 0x808005B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005B8: beq         $a3, $at, L_808005D4
    if (ctx->r7 == ctx->r1) {
        // 0x808005BC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808005D4;
    }
    // 0x808005BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808005C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808005C4: beql        $a3, $at, L_808005F4
    if (ctx->r7 == ctx->r1) {
        // 0x808005C8: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_808005F4;
    }
    goto skip_0;
    // 0x808005C8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x808005CC: b           L_80800644
    // 0x808005D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800644;
    // 0x808005D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005D4:
    // 0x808005D4: addiu       $a1, $zero, 0xFA0
    ctx->r5 = ADD32(0, 0XFA0);
    // 0x808005D8: jal         0x800FC348
    // 0x808005DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800FC348(rdram, ctx);
        goto after_2;
    // 0x808005DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x808005E0: jal         0x800FEC60
    // 0x808005E4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800FEC60(rdram, ctx);
        goto after_3;
    // 0x808005E4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x808005E8: b           L_80800644
    // 0x808005EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800644;
    // 0x808005EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005F0:
    // 0x808005F0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
L_808005F4:
    // 0x808005F4: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x808005F8: lbu         $t7, 0xE($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XE);
    // 0x808005FC: bnel        $t7, $zero, L_80800640
    if (ctx->r15 != 0) {
        // 0x80800600: sb          $zero, 0xE($t0)
        MEM_B(0XE, ctx->r8) = 0;
            goto L_80800640;
    }
    goto skip_1;
    // 0x80800600: sb          $zero, 0xE($t0)
    MEM_B(0XE, ctx->r8) = 0;
    skip_1:
    // 0x80800604: lh          $t8, 0xC($t6)
    ctx->r24 = MEM_H(ctx->r14, 0XC);
    // 0x80800608: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080060C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800610: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80800614: beq         $t9, $zero, L_8080062C
    if (ctx->r25 == 0) {
        // 0x80800618: nop
    
            goto L_8080062C;
    }
    // 0x80800618: nop

    // 0x8080061C: jal         0x80800524
    // 0x80800620: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_80800524_cothemedll(rdram, ctx);
        goto after_4;
    // 0x80800620: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_4:
    // 0x80800624: b           L_80800644
    // 0x80800628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800644;
    // 0x80800628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080062C:
    // 0x8080062C: jal         0x80800524
    // 0x80800630: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800524_cothemedll(rdram, ctx);
        goto after_5;
    // 0x80800630: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800634: b           L_80800644
    // 0x80800638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800644;
    // 0x80800638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080063C: sb          $zero, 0xE($t0)
    MEM_B(0XE, ctx->r8) = 0;
L_80800640:
    // 0x80800640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800644:
    // 0x80800644: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800648: jr          $ra
    // 0x8080064C: nop

    return;
    // 0x8080064C: nop

;}
RECOMP_FUNC void gctransitionDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800880: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800888: jal         0x800EA05C
    // 0x8080088C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x8080088C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800890: jal         0x8080004C
    // 0x80800894: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8080004C_gctransitionDll(rdram, ctx);
        goto after_1;
    // 0x80800894: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800898: jal         0x80800000
    // 0x8080089C: lbu         $a0, 0x2($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X2);
    func_80800000_gctransitionDll(rdram, ctx);
        goto after_2;
    // 0x8080089C: lbu         $a0, 0x2($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X2);
    after_2:
    // 0x808008A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808008A4: lbu         $a1, 0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X1);
    // 0x808008A8: jal         0x808000D8
    // 0x808008AC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_808000D8_gctransitionDll(rdram, ctx);
        goto after_3;
    // 0x808008AC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
    // 0x808008B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008B8: jr          $ra
    // 0x808008BC: nop

    return;
    // 0x808008BC: nop

;}
RECOMP_FUNC void func_800E8104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8104: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E8108: lw          $a0, -0x2A0C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2A0C);
    // 0x800E810C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E8110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8114: beq         $a0, $zero, L_800E812C
    if (ctx->r4 == 0) {
        // 0x800E8118: nop
    
            goto L_800E812C;
    }
    // 0x800E8118: nop

    // 0x800E811C: jal         0x8001B084
    // 0x800E8120: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x800E8120: nop

    after_0:
    // 0x800E8124: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E8128: sw          $zero, -0x2A0C($at)
    MEM_W(-0X2A0C, ctx->r1) = 0;
L_800E812C:
    // 0x800E812C: jal         0x800A9800
    // 0x800E8130: nop

    func_800A9800(rdram, ctx);
        goto after_1;
    // 0x800E8130: nop

    after_1:
    // 0x800E8134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E8138: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E813C: jr          $ra
    // 0x800E8140: nop

    return;
    // 0x800E8140: nop

;}
RECOMP_FUNC void func_80800B0C_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B14: jal         0x80085148
    // 0x80800B18: nop

    _baspin_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800B18: nop

    after_0:
    // 0x80800B1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B24: jr          $ra
    // 0x80800B28: nop

    return;
    // 0x80800B28: nop

;}
RECOMP_FUNC void func_808006EC_chmineprospector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808006F0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808006F4: addiu       $at, $zero, 0xF90
    ctx->r1 = ADD32(0, 0XF90);
    // 0x808006F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800700: bne         $a1, $at, L_80800744
    if (ctx->r5 != ctx->r1) {
        // 0x80800704: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_80800744;
    }
    // 0x80800704: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800708: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8080070C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800710: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800714: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800718: jal         0x800D1000
    // 0x8080071C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_0;
    // 0x8080071C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80800720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800724: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800728: jal         0x80800A64
    // 0x8080072C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80800A64_chmineprospector(rdram, ctx);
        goto after_1;
    // 0x8080072C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_1:
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800734: jal         0x80102424
    // 0x80800738: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800738: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
    // 0x8080073C: b           L_8080083C
    // 0x80800740: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080083C;
    // 0x80800740: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800744:
    // 0x80800744: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(892, 0XF20) << 16);
    // 0x80800748: addiu       $a2, $a2, 0xF20
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(892, 0XF20));
    // 0x8080074C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800750: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80800754: jal         0x8008A1F8
    // 0x80800758: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x80800758: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_3:
    // 0x8080075C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(892, 0XF58) << 16);
    // 0x80800760: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800764: addiu       $a2, $a2, 0xF58
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(892, 0XF58));
    // 0x80800768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080076C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800770: jal         0x8008A1F8
    // 0x80800774: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x80800774: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_4:
    // 0x80800778: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(892, 0XF90) << 16);
    // 0x8080077C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800780: addiu       $a2, $a2, 0xF90
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(892, 0XF90));
    // 0x80800784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800788: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8080078C: jal         0x8008A1F8
    // 0x80800790: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x80800790: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_5:
    // 0x80800794: jal         0x8008A200
    // 0x80800798: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddiedialog_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x80800798: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x8080079C: beq         $v0, $zero, L_808007C0
    if (ctx->r2 == 0) {
        // 0x808007A0: lw          $t6, 0x34($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X34);
            goto L_808007C0;
    }
    // 0x808007A0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x808007A4: jal         0x80800970
    // 0x808007A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800970_chmineprospector(rdram, ctx);
        goto after_7;
    // 0x808007A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007B0: jal         0x80102424
    // 0x808007B4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x808007B4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_8:
    // 0x808007B8: b           L_8080083C
    // 0x808007BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080083C;
    // 0x808007BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808007C0:
    // 0x808007C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808007C4: bne         $t6, $at, L_808007F4
    if (ctx->r14 != ctx->r1) {
        // 0x808007C8: nop
    
            goto L_808007F4;
    }
    // 0x808007C8: nop

    // 0x808007CC: jal         0x80800970
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800970_chmineprospector(rdram, ctx);
        goto after_9;
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808007D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D8: jal         0x80102424
    // 0x808007DC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_10;
    // 0x808007DC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_10:
    // 0x808007E0: addiu       $a0, $zero, 0xB9
    ctx->r4 = ADD32(0, 0XB9);
    // 0x808007E4: jal         0x800887D8
    // 0x808007E8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_11;
    // 0x808007E8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_11:
    // 0x808007EC: b           L_8080083C
    // 0x808007F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080083C;
    // 0x808007F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808007F4:
    // 0x808007F4: jal         0x8008A200
    // 0x808007F8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _subaddiedialog_entrypoint_10(rdram, ctx);
        goto after_12;
    // 0x808007F8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_12:
    // 0x808007FC: bne         $v0, $zero, L_80800838
    if (ctx->r2 != 0) {
        // 0x80800800: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800838;
    }
    // 0x80800800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800804: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x80800808: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8080080C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800810: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800814: bne         $t8, $at, L_80800824
    if (ctx->r24 != ctx->r1) {
        // 0x80800818: nop
    
            goto L_80800824;
    }
    // 0x80800818: nop

    // 0x8080081C: b           L_80800824
    // 0x80800820: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
        goto L_80800824;
    // 0x80800820: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
L_80800824:
    // 0x80800824: jal         0x80800970
    // 0x80800828: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_80800970_chmineprospector(rdram, ctx);
        goto after_13;
    // 0x80800828: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_13:
    // 0x8080082C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800830: jal         0x80102424
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_14;
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
L_80800838:
    // 0x80800838: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080083C:
    // 0x8080083C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800840: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800844: jr          $ra
    // 0x80800848: nop

    return;
    // 0x80800848: nop

;}
RECOMP_FUNC void func_80802588_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802588: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080258C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80802590: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80802594: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80802598: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1608, 0X5134) << 16);
    // 0x8080259C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808025A0: addiu       $t6, $t6, 0x5134
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1608, 0X5134));
    // 0x808025A4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808025A8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808025AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808025B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808025B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808025B8: jal         0x800BABB8
    // 0x808025BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_0;
    // 0x808025BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x808025C0: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x808025C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808025C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808025CC: bne         $t7, $at, L_808025DC
    if (ctx->r15 != ctx->r1) {
        // 0x808025D0: addiu       $a1, $zero, 0x67A
        ctx->r5 = ADD32(0, 0X67A);
            goto L_808025DC;
    }
    // 0x808025D0: addiu       $a1, $zero, 0x67A
    ctx->r5 = ADD32(0, 0X67A);
    // 0x808025D4: b           L_808025DC
    // 0x808025D8: addiu       $a1, $zero, 0x679
    ctx->r5 = ADD32(0, 0X679);
        goto L_808025DC;
    // 0x808025D8: addiu       $a1, $zero, 0x679
    ctx->r5 = ADD32(0, 0X679);
L_808025DC:
    // 0x808025DC: jal         0x800BA670
    // 0x808025E0: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_800BA670(rdram, ctx);
        goto after_1;
    // 0x808025E0: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_1:
    // 0x808025E4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808025E8: jal         0x800BA22C
    // 0x808025EC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800BA22C(rdram, ctx);
        goto after_2;
    // 0x808025EC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_2:
    // 0x808025F0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1608, 0X4FE8) << 16);
    // 0x808025F4: addiu       $a2, $a2, 0x4FE8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1608, 0X4FE8));
    // 0x808025F8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808025FC: jal         0x80089D18
    // 0x80802600: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80802600: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80802604: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802608: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080260C: jr          $ra
    // 0x80802610: nop

    return;
    // 0x80802610: nop

;}
RECOMP_FUNC void baanim_playForDuration_onceSmooth(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CCBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008CCC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008CCC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008CCC8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8008CCCC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8008CCD0: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8008CCD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008CCD8: jal         0x8008AF24
    // 0x8008CCDC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    anctrl_reset(rdram, ctx);
        goto after_0;
    // 0x8008CCDC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x8008CCE0: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8008CCE4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8008CCE8: jal         0x8008AED4
    // 0x8008CCEC: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    anctrl_setIndex(rdram, ctx);
        goto after_1;
    // 0x8008CCEC: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_1:
    // 0x8008CCF0: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8008CCF4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8008CCF8: jal         0x8008B1BC
    // 0x8008CCFC: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    anctrl_setDuration(rdram, ctx);
        goto after_2;
    // 0x8008CCFC: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_2:
    // 0x8008CD00: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8008CD04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008CD08: jal         0x8008B134
    // 0x8008CD0C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_3;
    // 0x8008CD0C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_3:
    // 0x8008CD10: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x8008CD14: jal         0x8008B064
    // 0x8008CD18: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    anctrl_start(rdram, ctx);
        goto after_4;
    // 0x8008CD18: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_4:
    // 0x8008CD1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008CD20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008CD24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008CD28: jr          $ra
    // 0x8008CD2C: nop

    return;
    // 0x8008CD2C: nop

;}
RECOMP_FUNC void _chsparkle_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800871B8: syscall     533
    recomp_syscall_handler(rdram, ctx, 0x800871B8);
    return;
    // 0x800871BC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void gcnewoption_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009E0: jr          $ra
    // 0x808009E4: addiu       $v0, $zero, 0x260
    ctx->r2 = ADD32(0, 0X260);
    return;
    // 0x808009E4: addiu       $v0, $zero, 0x260
    ctx->r2 = ADD32(0, 0X260);
;}
RECOMP_FUNC void bsbflap_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006D4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808006D8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(90, 0X750) << 16);
    // 0x808006DC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808006E0: jr          $ra
    // 0x808006E4: lw          $v0, 0x750($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(90, 0X750));
    return;
    // 0x808006E4: lw          $v0, 0x750($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(90, 0X750));
;}
RECOMP_FUNC void bafly_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800464: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800468: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080046C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800470: jal         0x8009EF28
    // 0x80800474: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bastick_getX(rdram, ctx);
        goto after_0;
    // 0x80800474: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800478: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800480: jal         0x800919F4
    // 0x80800484: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    bakey_held(rdram, ctx);
        goto after_1;
    // 0x80800484: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80800488: beq         $v0, $zero, L_808004B8
    if (ctx->r2 == 0) {
        // 0x8080048C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004B8;
    }
    // 0x8080048C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800494: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80800498: jal         0x8009C99C
    // 0x8080049C: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_2;
    // 0x8080049C: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_2:
    // 0x808004A0: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x808004A4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808004A8: lui         $at, 0x42AA
    ctx->r1 = S32(0X42AA << 16);
    // 0x808004AC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808004B0: b           L_808004DC
    // 0x808004B4: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
        goto L_808004DC;
    // 0x808004B4: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
L_808004B8:
    // 0x808004B8: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x808004BC: jal         0x8009C99C
    // 0x808004C0: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_3;
    // 0x808004C0: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_3:
    // 0x808004C4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808004C8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808004CC: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x808004D0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808004D4: nop

    // 0x808004D8: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
L_808004DC:
    // 0x808004DC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808004E0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808004E4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x808004E8: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808004EC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808004F0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x808004F4: jal         0x800F10B4
    // 0x808004F8: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x808004F8: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x808004FC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800500: jal         0x8009C4CC
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baroll_setIdeal(rdram, ctx);
        goto after_5;
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800508: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8080050C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800510: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800514: neg.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
    // 0x80800518: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8080051C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80800520: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800524: jal         0x800F10B4
    // 0x80800528: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80800528: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_6:
    // 0x8080052C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80800530: jal         0x80084C90
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800538: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800540: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80800544: jal         0x8009C990
    // 0x80800548: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    yaw_getIdeal(rdram, ctx);
        goto after_8;
    // 0x80800548: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x8080054C: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800554: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80800558: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8080055C: jal         0x8009C914
    // 0x80800560: nop

    yaw_setIdeal(rdram, ctx);
        goto after_9;
    // 0x80800560: nop

    after_9:
    // 0x80800564: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800568: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080056C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800570: jr          $ra
    // 0x80800574: nop

    return;
    // 0x80800574: nop

;}
RECOMP_FUNC void func_80801CD8_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CD8: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80801CDC: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80801CE0: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80801CE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801CE8: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80801CEC: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80801CF0: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80801CF4: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80801CF8: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80801CFC: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80801D00: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80801D04: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80801D08: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80801D0C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80801D10: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80801D14: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80801D18: jal         0x80100094
    // 0x80801D1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801D1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80801D20: addiu       $s4, $sp, 0x9C
    ctx->r20 = ADD32(ctx->r29, 0X9C);
    // 0x80801D24: addiu       $s5, $sp, 0x90
    ctx->r21 = ADD32(ctx->r29, 0X90);
    // 0x80801D28: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801D2C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80801D30: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80801D34: jal         0x808019F4
    // 0x80801D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808019F4_chfactorymagnet(rdram, ctx);
        goto after_1;
    // 0x80801D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801D3C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801D40: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80801D44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801D48: lui         $s7, 0x8080
    ctx->r23 = S32(RELOC_HI16(2284, 0X29BC) << 16);
    // 0x80801D4C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80801D50: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80801D54: addiu       $s7, $s7, 0x29BC
    ctx->r23 = ADD32(ctx->r23, (int16_t)RELOC_LO16(2284, 0X29BC));
    // 0x80801D58: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80801D5C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80801D60: addiu       $fp, $zero, 0x230
    ctx->r30 = ADD32(0, 0X230);
    // 0x80801D64: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80801D68: addiu       $s3, $sp, 0x78
    ctx->r19 = ADD32(ctx->r29, 0X78);
L_80801D6C:
    // 0x80801D6C: lbu         $t6, 0x18($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X18);
    // 0x80801D70: beql        $t6, $zero, L_80801E3C
    if (ctx->r14 == 0) {
        // 0x80801D74: addiu       $s2, $s2, 0x1C
        ctx->r18 = ADD32(ctx->r18, 0X1C);
            goto L_80801E3C;
    }
    goto skip_0;
    // 0x80801D74: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
    skip_0:
    // 0x80801D78: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80801D7C: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80801D80: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80801D84: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80801D88: jal         0x800F12D4
    // 0x80801D8C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    func_800F12D4(rdram, ctx);
        goto after_2;
    // 0x80801D8C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_2:
    // 0x80801D90: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80801D94: jal         0x800B53A4
    // 0x80801D98: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800B53A4(rdram, ctx);
        goto after_3;
    // 0x80801D98: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_3:
    // 0x80801D9C: c.lt.s      $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
    // 0x80801DA0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801DA4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801DA8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80801DAC: bc1fl       L_80801DE8
    if (!c1cs) {
        // 0x80801DB0: lbu         $t8, 0x18($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X18);
            goto L_80801DE8;
    }
    goto skip_1;
    // 0x80801DB0: lbu         $t8, 0x18($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X18);
    skip_1:
    // 0x80801DB4: sub.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f26.fl;
    // 0x80801DB8: lbu         $t7, 0x18($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X18);
    // 0x80801DBC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80801DC0: bne         $s6, $t7, L_80801DD0
    if (ctx->r22 != ctx->r15) {
        // 0x80801DC4: add.s       $f20, $f20, $f20
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f20.fl;
            goto L_80801DD0;
    }
    // 0x80801DC4: add.s       $f20, $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f20.fl;
    // 0x80801DC8: b           L_80801DD0
    // 0x80801DCC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
        goto L_80801DD0;
    // 0x80801DCC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
L_80801DD0:
    // 0x80801DD0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80801DD4: jal         0x800EFE50
    // 0x80801DD8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800EFE50(rdram, ctx);
        goto after_4;
    // 0x80801DD8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x80801DDC: b           L_80801E08
    // 0x80801DE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_80801E08;
    // 0x80801DE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801DE4: lbu         $t8, 0x18($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X18);
L_80801DE8:
    // 0x80801DE8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80801DEC: bne         $s6, $t8, L_80801DFC
    if (ctx->r22 != ctx->r24) {
        // 0x80801DF0: nop
    
            goto L_80801DFC;
    }
    // 0x80801DF0: nop

    // 0x80801DF4: b           L_80801DFC
    // 0x80801DF8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
        goto L_80801DFC;
    // 0x80801DF8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
L_80801DFC:
    // 0x80801DFC: jal         0x800EE7F8
    // 0x80801E00: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80801E00: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_5:
    // 0x80801E04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80801E08:
    // 0x80801E08: jal         0x800BAA9C
    // 0x80801E0C: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    func_800BAA9C(rdram, ctx);
        goto after_6;
    // 0x80801E0C: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    after_6:
    // 0x80801E10: lbu         $a1, 0x19($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X19);
    // 0x80801E14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801E18: jal         0x800BA5B0
    // 0x80801E1C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_800BA5B0(rdram, ctx);
        goto after_7;
    // 0x80801E1C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_7:
    // 0x80801E20: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80801E24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801E28: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80801E2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801E30: jal         0x800BABB8
    // 0x80801E34: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    func_800BABB8(rdram, ctx);
        goto after_8;
    // 0x80801E34: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    after_8:
    // 0x80801E38: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
L_80801E3C:
    // 0x80801E3C: bne         $s2, $fp, L_80801D6C
    if (ctx->r18 != ctx->r30) {
        // 0x80801E40: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_80801D6C;
    }
    // 0x80801E40: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x80801E44: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80801E48: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80801E4C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80801E50: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80801E54: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80801E58: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80801E5C: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80801E60: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80801E64: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80801E68: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80801E6C: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80801E70: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80801E74: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80801E78: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x80801E7C: jr          $ra
    // 0x80801E80: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80801E80: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_8001D98C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D98C: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x8001D990: slti        $at, $t6, 0x38
    ctx->r1 = SIGNED(ctx->r14) < 0X38 ? 1 : 0;
    // 0x8001D994: beq         $at, $zero, L_8001D9A4
    if (ctx->r1 == 0) {
        // 0x8001D998: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_8001D9A4;
    }
    // 0x8001D998: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001D99C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001D9A0: sw          $t6, -0x2800($at)
    MEM_W(-0X2800, ctx->r1) = ctx->r14;
L_8001D9A4:
    // 0x8001D9A4: jr          $ra
    // 0x8001D9A8: nop

    return;
    // 0x8001D9A8: nop

;}
RECOMP_FUNC void _badeathmatch_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085530: syscall     165
    recomp_syscall_handler(rdram, ctx, 0x80085530);
    return;
    // 0x80085534: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800A1618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1618: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A161C: jr          $ra
    // 0x800A1620: sb          $a0, 0x7092($at)
    MEM_B(0X7092, ctx->r1) = ctx->r4;
    return;
    // 0x800A1620: sb          $a0, 0x7092($at)
    MEM_B(0X7092, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void sueggmisc_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800128: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080012C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800130: jal         0x800883D8
    // 0x80800134: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    _gcegg_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800134: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800138: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080013C: jal         0x800888C8
    // 0x80800140: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _fxsparkle_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800140: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80800144: jal         0x800883D0
    // 0x80800148: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _gcegg_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800148: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x8080014C: jal         0x800FC660
    // 0x80800150: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800FC660(rdram, ctx);
        goto after_3;
    // 0x80800150: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080015C: jr          $ra
    // 0x80800160: nop

    return;
    // 0x80800160: nop

;}
RECOMP_FUNC void func_8080060C_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080060C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800610: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800614: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800618: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080061C: jal         0x80100094
    // 0x80800620: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800620: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800624: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800628: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x8080062C: andi        $t6, $a0, 0x1FF
    ctx->r14 = ctx->r4 & 0X1FF;
    // 0x80800630: jal         0x800CEAA8
    // 0x80800634: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800CEAA8(rdram, ctx);
        goto after_1;
    // 0x80800634: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x80800638: beql        $v0, $zero, L_80800658
    if (ctx->r2 == 0) {
        // 0x8080063C: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_80800658;
    }
    goto skip_0;
    // 0x8080063C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800640: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80800644: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800648: andi        $t7, $a0, 0x1FF
    ctx->r15 = ctx->r4 & 0X1FF;
    // 0x8080064C: jal         0x800CE88C
    // 0x80800650: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800CE88C(rdram, ctx);
        goto after_2;
    // 0x80800650: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_2:
    // 0x80800654: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
L_80800658:
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080065C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80800660: jal         0x8008A2B0
    // 0x80800664: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    _susubgame_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800664: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_3:
    // 0x80800668: beq         $v0, $zero, L_80800678
    if (ctx->r2 == 0) {
        // 0x8080066C: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_80800678;
    }
    // 0x8080066C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800670: jal         0x8008A2C0
    // 0x80800674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80800678:
    // 0x80800678: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080067C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800680: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800684: jr          $ra
    // 0x80800688: nop

    return;
    // 0x80800688: nop

;}
RECOMP_FUNC void func_8080000C_chfactorylobbydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: jal         0x800EA090
    // 0x80800018: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800EA090(rdram, ctx);
        goto after_0;
    // 0x80800018: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080001C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800020: bne         $v0, $at, L_80800058
    if (ctx->r2 != ctx->r1) {
        // 0x80800024: addiu       $a0, $zero, 0x35
        ctx->r4 = ADD32(0, 0X35);
            goto L_80800058;
    }
    // 0x80800024: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    // 0x80800028: jal         0x800D0A9C
    // 0x8080002C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_1;
    // 0x8080002C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800030: beql        $v0, $zero, L_80800050
    if (ctx->r2 == 0) {
        // 0x80800034: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800050;
    }
    goto skip_0;
    // 0x80800034: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80800038: jal         0x8009E958
    // 0x8080003C: nop

    func_8009E958(rdram, ctx);
        goto after_2;
    // 0x8080003C: nop

    after_2:
    // 0x80800040: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800044: beql        $v0, $at, L_8080005C
    if (ctx->r2 == ctx->r1) {
        // 0x80800048: addiu       $t6, $zero, 0x8
        ctx->r14 = ADD32(0, 0X8);
            goto L_8080005C;
    }
    goto skip_1;
    // 0x80800048: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    skip_1:
    // 0x8080004C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80800050:
    // 0x80800050: jal         0x80101FDC
    // 0x80800054: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80800054: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_80800058:
    // 0x80800058: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
L_8080005C:
    // 0x8080005C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80800060: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800064: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800068: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080006C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800070: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x80800074: jal         0x80086898
    // 0x80800078: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800078: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    after_4:
    // 0x8080007C: beq         $v0, $zero, L_80800098
    if (ctx->r2 == 0) {
        // 0x80800080: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800098;
    }
    // 0x80800080: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800084: jal         0x800868A8
    // 0x80800088: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80800088: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    after_5:
    // 0x8080008C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800090: jal         0x800868C0
    // 0x80800094: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x80800094: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
L_80800098:
    // 0x80800098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080009C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000A0: jr          $ra
    // 0x808000A4: nop

    return;
    // 0x808000A4: nop

;}
RECOMP_FUNC void mlspline_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800074: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800078: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8080007C: lwc1        $f2, 0x4($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80800080: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80800084: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80800088: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8080008C: jr          $ra
    // 0x80800090: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    return;
    // 0x80800090: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
;}
RECOMP_FUNC void sucoasterdata_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808000A0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x808000A4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x808000A8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x808000AC: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(3282, 0X3C0) << 16);
    // 0x808000B0: addiu       $t7, $t7, 0x3C0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(3282, 0X3C0));
    // 0x808000B4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808000B8: jr          $ra
    // 0x808000BC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    return;
    // 0x808000BC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
;}
RECOMP_FUNC void _basnowball_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085118: syscall     151
    recomp_syscall_handler(rdram, ctx, 0x80085118);
    return;
    // 0x8008511C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_800A89BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A89BC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800A89C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A89C4: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800A89C8: sw          $a0, 0x7674($at)
    MEM_W(0X7674, ctx->r1) = ctx->r4;
    // 0x800A89CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A89D0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A89D4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A89D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A89DC: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800A89E0: jal         0x800E42B4
    // 0x800A89E4: lw          $a0, 0x768C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X768C);
    func_800E42B4(rdram, ctx);
        goto after_0;
    // 0x800A89E4: lw          $a0, 0x768C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X768C);
    after_0:
    // 0x800A89E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A89EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A89F0: jr          $ra
    // 0x800A89F4: nop

    return;
    // 0x800A89F4: nop

;}
RECOMP_FUNC void func_80102B2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102B2C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80102B30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102B34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102B38: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80102B3C: lw          $a2, 0x54($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X54);
    // 0x80102B40: lw          $a1, 0x48($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X48);
    // 0x80102B44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80102B48: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80102B4C: jal         0x80102A04
    // 0x80102B50: nop

    func_80102A04(rdram, ctx);
        goto after_0;
    // 0x80102B50: nop

    after_0:
    // 0x80102B54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80102B58: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    // 0x80102B5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102B60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102B64: jr          $ra
    // 0x80102B68: nop

    return;
    // 0x80102B68: nop

;}
RECOMP_FUNC void func_808012CC_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808012D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808012D8: jal         0x8001210C
    // 0x808012DC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8001210C(rdram, ctx);
        goto after_0;
    // 0x808012DC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x808012E0: bnel        $v0, $zero, L_80801338
    if (ctx->r2 != 0) {
        // 0x808012E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801338;
    }
    goto skip_0;
    // 0x808012E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808012E8: jal         0x800C954C
    // 0x808012EC: nop

    func_800C954C(rdram, ctx);
        goto after_1;
    // 0x808012EC: nop

    after_1:
    // 0x808012F0: bnel        $v0, $zero, L_80801338
    if (ctx->r2 != 0) {
        // 0x808012F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801338;
    }
    goto skip_1;
    // 0x808012F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808012F8: jal         0x80801EC4
    // 0x808012FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80801EC4_chevilspirit(rdram, ctx);
        goto after_2;
    // 0x808012FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80801300: beq         $v0, $zero, L_80801334
    if (ctx->r2 == 0) {
        // 0x80801304: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801334;
    }
    // 0x80801304: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801308: jal         0x8080104C
    // 0x8080130C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8080104C_chevilspirit(rdram, ctx);
        goto after_3;
    // 0x8080130C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80801310: beq         $v0, $zero, L_80801334
    if (ctx->r2 == 0) {
        // 0x80801314: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80801334;
    }
    // 0x80801314: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801318: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080131C: jal         0x80801988
    // 0x80801320: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80801988_chevilspirit(rdram, ctx);
        goto after_4;
    // 0x80801320: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80801324: beq         $v0, $zero, L_80801334
    if (ctx->r2 == 0) {
        // 0x80801328: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801334;
    }
    // 0x80801328: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080132C: jal         0x80102424
    // 0x80801330: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x80801330: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
L_80801334:
    // 0x80801334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801338:
    // 0x80801338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080133C: jr          $ra
    // 0x80801340: nop

    return;
    // 0x80801340: nop

;}
RECOMP_FUNC void _chappearfx_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800862E8: syscall     303
    recomp_syscall_handler(rdram, ctx, 0x800862E8);
    return;
    // 0x800862EC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800AB9D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB9D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AB9D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800AB9D8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800AB9DC: lw          $s0, 0x798C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X798C);
    // 0x800AB9E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AB9E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800AB9E8: beql        $s0, $zero, L_800ABA08
    if (ctx->r16 == 0) {
        // 0x800AB9EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800ABA08;
    }
    goto skip_0;
    // 0x800AB9EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_800AB9F0:
    // 0x800AB9F0: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
    // 0x800AB9F4: jal         0x8001B084
    // 0x800AB9F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    heap_free(rdram, ctx);
        goto after_0;
    // 0x800AB9F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800AB9FC: bne         $s1, $zero, L_800AB9F0
    if (ctx->r17 != 0) {
        // 0x800ABA00: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800AB9F0;
    }
    // 0x800ABA00: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800ABA04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800ABA08:
    // 0x800ABA08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800ABA0C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800ABA10: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800ABA14: sw          $zero, 0x798C($at)
    MEM_W(0X798C, ctx->r1) = 0;
    // 0x800ABA18: jr          $ra
    // 0x800ABA1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800ABA1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800E2594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2594: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800E2598: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E259C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E25A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E25A4: jal         0x800E1DF4
    // 0x800E25A8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800E1DF4(rdram, ctx);
        goto after_0;
    // 0x800E25A8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800E25AC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800E25B0: lui         $t7, 0xDB06
    ctx->r15 = S32(0XDB06 << 16);
    // 0x800E25B4: ori         $t7, $t7, 0x8
    ctx->r15 = ctx->r15 | 0X8;
    // 0x800E25B8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800E25BC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800E25C0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800E25C4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800E25C8: jal         0x800AF5D8
    // 0x800E25CC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800AF5D8(rdram, ctx);
        goto after_1;
    // 0x800E25CC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x800E25D0: jal         0x8002E330
    // 0x800E25D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800E25D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800E25D8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800E25DC: lui         $t0, 0xDB06
    ctx->r8 = S32(0XDB06 << 16);
    // 0x800E25E0: ori         $t0, $t0, 0x4
    ctx->r8 = ctx->r8 | 0X4;
    // 0x800E25E4: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x800E25E8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800E25EC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800E25F0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800E25F4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800E25F8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800E25FC: jal         0x800AF5E4
    // 0x800E2600: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_800AF5E4(rdram, ctx);
        goto after_3;
    // 0x800E2600: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_3:
    // 0x800E2604: jal         0x8002E330
    // 0x800E2608: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x800E2608: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x800E260C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800E2610: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E2614: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    // 0x800E2618: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E261C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800E2620: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E2624: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800E2628: jr          $ra
    // 0x800E262C: sw          $t2, -0x2B10($at)
    MEM_W(-0X2B10, ctx->r1) = ctx->r10;
    return;
    // 0x800E262C: sw          $t2, -0x2B10($at)
    MEM_W(-0X2B10, ctx->r1) = ctx->r10;
;}
RECOMP_FUNC void _bashoes_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084FD8: syscall     148
    recomp_syscall_handler(rdram, ctx, 0x80084FD8);
    return;
    // 0x80084FDC: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_80800428_suflamefx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800428: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080042C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800430: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800434: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800438: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080043C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800440: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800444: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800448: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080044C: jal         0x800DC178
    // 0x80800450: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x80800450: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800454: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x80800458: lh          $t7, 0xE($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XE);
    // 0x8080045C: lh          $t6, 0xC($s1)
    ctx->r14 = MEM_H(ctx->r17, 0XC);
    // 0x80800460: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80800464: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800468: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080046C: jal         0x800DC178
    // 0x80800470: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800470: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_1:
    // 0x80800474: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80800478: lwc1        $f14, 0x4($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8080047C: jal         0x800DC178
    // 0x80800480: lwc1        $f12, 0x8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X8);
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800480: lwc1        $f12, 0x8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X8);
    after_2:
    // 0x80800484: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80800488: lbu         $v0, 0x1A($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1A);
    // 0x8080048C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80800490: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800494: bnel        $v0, $at, L_808004B0
    if (ctx->r2 != ctx->r1) {
        // 0x80800498: sb          $v0, 0x2C($s0)
        MEM_B(0X2C, ctx->r16) = ctx->r2;
            goto L_808004B0;
    }
    goto skip_0;
    // 0x80800498: sb          $v0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r2;
    skip_0:
    // 0x8080049C: jal         0x800DC128
    // 0x808004A0: lbu         $a1, 0x1D($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1D);
    func_800DC128(rdram, ctx);
        goto after_3;
    // 0x808004A0: lbu         $a1, 0x1D($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1D);
    after_3:
    // 0x808004A4: b           L_808004B0
    // 0x808004A8: sb          $v0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r2;
        goto L_808004B0;
    // 0x808004A8: sb          $v0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r2;
    // 0x808004AC: sb          $v0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r2;
L_808004B0:
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B4: jal         0x800EE7F8
    // 0x808004B8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x808004B8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_4:
    // 0x808004BC: jal         0x800E3980
    // 0x808004C0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800E3980(rdram, ctx);
        goto after_5;
    // 0x808004C0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x808004C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C8: jal         0x800F1DF4
    // 0x808004CC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F1DF4(rdram, ctx);
        goto after_6;
    // 0x808004CC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_6:
    // 0x808004D0: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x808004D4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808004D8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808004DC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808004E0: jal         0x800DC178
    // 0x808004E4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x808004E4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x808004E8: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808004EC: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x808004F0: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x808004F4: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x808004F8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808004FC: jal         0x800EFCD8
    // 0x80800500: nop

    func_800EFCD8(rdram, ctx);
        goto after_8;
    // 0x80800500: nop

    after_8:
    // 0x80800504: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800508: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080050C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800510: jr          $ra
    // 0x80800514: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800514: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800518: nop

    // 0x8080051C: nop

;}
RECOMP_FUNC void func_80800170_chvolcanobits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800170: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800174: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800178: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8080017C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800180: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800184: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800188: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080018C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800190: jal         0x80100094
    // 0x80800194: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800194: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800198: lw          $t6, 0x60($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X60);
    // 0x8080019C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808001A0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808001A4: blez        $t6, L_808001E8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x808001A8: addiu       $s1, $v0, 0x4
        ctx->r17 = ADD32(ctx->r2, 0X4);
            goto L_808001E8;
    }
    // 0x808001A8: addiu       $s1, $v0, 0x4
    ctx->r17 = ADD32(ctx->r2, 0X4);
    // 0x808001AC: addiu       $s2, $sp, 0x3C
    ctx->r18 = ADD32(ctx->r29, 0X3C);
L_808001B0:
    // 0x808001B0: jal         0x800D9078
    // 0x808001B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x808001B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808001B8: beq         $v0, $zero, L_808001D0
    if (ctx->r2 == 0) {
        // 0x808001BC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_808001D0;
    }
    // 0x808001BC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808001C0: sh          $s0, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r16;
    // 0x808001C4: sh          $zero, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = 0;
    // 0x808001C8: jal         0x80108B04
    // 0x808001CC: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    func_80108B04(rdram, ctx);
        goto after_2;
    // 0x808001CC: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    after_2:
L_808001D0:
    // 0x808001D0: lw          $t7, 0x60($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X60);
    // 0x808001D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808001D8: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x808001DC: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x808001E0: bne         $at, $zero, L_808001B0
    if (ctx->r1 != 0) {
        // 0x808001E4: nop
    
            goto L_808001B0;
    }
    // 0x808001E4: nop

L_808001E8:
    // 0x808001E8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1264, 0X1274) << 16);
    // 0x808001EC: addiu       $a3, $a3, 0x1274
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1264, 0X1274));
    // 0x808001F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808001F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001F8: jal         0x80089D50
    // 0x808001FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x808001FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80800200: jal         0x800EA05C
    // 0x80800204: nop

    func_800EA05C(rdram, ctx);
        goto after_4;
    // 0x80800204: nop

    after_4:
    // 0x80800208: addiu       $at, $zero, 0x129
    ctx->r1 = ADD32(0, 0X129);
    // 0x8080020C: beq         $v0, $at, L_80800224
    if (ctx->r2 == ctx->r1) {
        // 0x80800210: addiu       $at, $zero, 0x133
        ctx->r1 = ADD32(0, 0X133);
            goto L_80800224;
    }
    // 0x80800210: addiu       $at, $zero, 0x133
    ctx->r1 = ADD32(0, 0X133);
    // 0x80800214: beql        $v0, $at, L_80800260
    if (ctx->r2 == ctx->r1) {
        // 0x80800218: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800260;
    }
    goto skip_0;
    // 0x80800218: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8080021C: b           L_80800260
    // 0x80800220: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800260;
    // 0x80800220: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800224:
    // 0x80800224: jal         0x80088840
    // 0x80800228: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_5;
    // 0x80800228: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    after_5:
    // 0x8080022C: beql        $v0, $zero, L_80800260
    if (ctx->r2 == 0) {
        // 0x80800230: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800260;
    }
    goto skip_1;
    // 0x80800230: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80800234: jal         0x800D9078
    // 0x80800238: addiu       $a0, $s4, 0x64
    ctx->r4 = ADD32(ctx->r20, 0X64);
    func_800D9078(rdram, ctx);
        goto after_6;
    // 0x80800238: addiu       $a0, $s4, 0x64
    ctx->r4 = ADD32(ctx->r20, 0X64);
    after_6:
    // 0x8080023C: beq         $v0, $zero, L_8080025C
    if (ctx->r2 == 0) {
        // 0x80800240: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_8080025C;
    }
    // 0x80800240: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80800244: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800248: sh          $t8, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r24;
    // 0x8080024C: sh          $t9, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r25;
    // 0x80800250: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80800254: jal         0x80108B04
    // 0x80800258: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80108B04(rdram, ctx);
        goto after_7;
    // 0x80800258: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
L_8080025C:
    // 0x8080025C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800260:
    // 0x80800260: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800264: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800268: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080026C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800270: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800274: jr          $ra
    // 0x80800278: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800278: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void bsvan_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A58: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801A5C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(427, 0X1D80) << 16);
    // 0x80801A60: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801A64: jr          $ra
    // 0x80801A68: lw          $v0, 0x1D80($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(427, 0X1D80));
    return;
    // 0x80801A68: lw          $v0, 0x1D80($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(427, 0X1D80));
    // 0x80801A6C: nop

;}
RECOMP_FUNC void func_808002AC_chattract(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002B4: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808002B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002C0: bne         $a1, $at, L_80800394
    if (ctx->r5 != ctx->r1) {
        // 0x808002C4: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80800394;
    }
    // 0x808002C4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808002C8: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x808002CC: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(812, 0X468) << 16);
    // 0x808002D0: addiu       $t9, $t9, 0x468
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(812, 0X468));
    // 0x808002D4: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808002D8: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x808002DC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x808002E0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808002E4: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x808002E8: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    // 0x808002EC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x808002F0: jal         0x80103140
    // 0x808002F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80103140(rdram, ctx);
        goto after_0;
    // 0x808002F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x808002F8: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800300: srl         $t0, $a1, 7
    ctx->r8 = S32(U32(ctx->r5) >> 7);
    // 0x80800304: jal         0x80102424
    // 0x80800308: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800308: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_1:
    // 0x8080030C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800310: lbu         $t5, 0x7A($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X7A);
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800318: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8080031C: andi        $t6, $t5, 0xFF3F
    ctx->r14 = ctx->r13 & 0XFF3F;
    // 0x80800320: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x80800324: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80800328: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
    // 0x8080032C: lbu         $t2, 0x18($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X18);
    // 0x80800330: sll         $t4, $t2, 6
    ctx->r12 = S32(ctx->r10 << 6);
    // 0x80800334: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80800338: sb          $t7, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r15;
    // 0x8080033C: lbu         $t8, 0x2($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2);
    // 0x80800340: beql        $t8, $zero, L_80800358
    if (ctx->r24 == 0) {
        // 0x80800344: lh          $t9, 0x10($v1)
        ctx->r25 = MEM_H(ctx->r3, 0X10);
            goto L_80800358;
    }
    goto skip_0;
    // 0x80800344: lh          $t9, 0x10($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X10);
    skip_0:
    // 0x80800348: jal         0x80089CA0
    // 0x8080034C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    _subaddiefade_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x8080034C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x80800350: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800354: lh          $t9, 0x10($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X10);
L_80800358:
    // 0x80800358: lbu         $t1, 0x79($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X79);
    // 0x8080035C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800360: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80800364: andi        $t2, $t1, 0xFF0F
    ctx->r10 = ctx->r9 & 0XFF0F;
    // 0x80800368: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080036C: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x80800370: lh          $t0, 0x12($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X12);
    // 0x80800374: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80800378: nop

    // 0x8080037C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800380: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x80800384: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80800388: sb          $t2, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r10;
    // 0x8080038C: b           L_80800398
    // 0x80800390: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
        goto L_80800398;
    // 0x80800390: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
L_80800394:
    // 0x80800394: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800398:
    // 0x80800398: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080039C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003A4: jr          $ra
    // 0x808003A8: nop

    return;
    // 0x808003A8: nop

;}
RECOMP_FUNC void func_808000A0_ch2dbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000AC: jal         0x8008A108
    // 0x808000B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _sucoaster_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808000B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000B4: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x808000B8: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x808000BC: bltzl       $t8, L_80800298
    if (SIGNED(ctx->r24) < 0) {
        // 0x808000C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800298;
    }
    goto skip_0;
    // 0x808000C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000C4: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    // 0x808000C8: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x808000CC: addiu       $t1, $t0, -0x2
    ctx->r9 = ADD32(ctx->r8, -0X2);
    // 0x808000D0: sltiu       $at, $t1, 0x15
    ctx->r1 = ctx->r9 < 0X15 ? 1 : 0;
    // 0x808000D4: beq         $at, $zero, L_80800294
    if (ctx->r1 == 0) {
        // 0x808000D8: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_80800294;
    }
    // 0x808000D8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x808000DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1356, 0X8A4) << 16);
    // 0x808000E0: addu        $at, $at, $t1
    gpr jr_addend_808000E8 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x808000E4: lw          $t1, 0x8A4($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1356, 0X8A4));
    // 0x808000E8: jr          $t1
    // 0x808000EC: nop

    switch (jr_addend_808000E8 >> 2) {
        case 0: goto L_808000F0; break;
        case 1: goto L_808000F0; break;
        case 2: goto L_80800294; break;
        case 3: goto L_80800294; break;
        case 4: goto L_80800294; break;
        case 5: goto L_80800294; break;
        case 6: goto L_808000F0; break;
        case 7: goto L_80800294; break;
        case 8: goto L_80800294; break;
        case 9: goto L_80800294; break;
        case 10: goto L_80800294; break;
        case 11: goto L_80800294; break;
        case 12: goto L_80800294; break;
        case 13: goto L_80800294; break;
        case 14: goto L_80800294; break;
        case 15: goto L_80800294; break;
        case 16: goto L_80800294; break;
        case 17: goto L_80800114; break;
        case 18: goto L_8080013C; break;
        case 19: goto L_80800214; break;
        case 20: goto L_808001C4; break;
        default: switch_error(__func__, 0x808000E8, 0x808008A4);
    }
    // 0x808000EC: nop

L_808000F0:
    // 0x808000F0: jal         0x80800468
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800468_ch2dbaddy(rdram, ctx);
        goto after_1;
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000F8: beq         $v0, $zero, L_80800294
    if (ctx->r2 == 0) {
        // 0x808000FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800294;
    }
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800100: jal         0x8008A148
    // 0x80800104: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800104: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_2:
    // 0x80800108: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080010C: b           L_80800294
    // 0x80800110: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
        goto L_80800294;
    // 0x80800110: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
L_80800114:
    // 0x80800114: jal         0x8008A190
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_19(rdram, ctx);
        goto after_3;
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080011C: jal         0x8080041C
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080041C_ch2dbaddy(rdram, ctx);
        goto after_4;
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800124: beq         $v0, $zero, L_80800294
    if (ctx->r2 == 0) {
        // 0x80800128: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800294;
    }
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: jal         0x80800700
    // 0x80800130: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80800700_ch2dbaddy(rdram, ctx);
        goto after_5;
    // 0x80800130: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_5:
    // 0x80800134: b           L_80800298
    // 0x80800138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800298;
    // 0x80800138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080013C:
    // 0x8080013C: jal         0x80800820
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800820_ch2dbaddy(rdram, ctx);
        goto after_6;
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800144: jal         0x8010CD28
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_7;
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080014C: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800150: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800154: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x80800160: jal         0x80102BF8
    // 0x80800164: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    func_80102BF8(rdram, ctx);
        goto after_8;
    // 0x80800164: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    after_8:
    // 0x80800168: lw          $a1, 0x64($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X64);
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800170: sll         $t2, $a1, 11
    ctx->r10 = S32(ctx->r5 << 11);
    // 0x80800174: jal         0x8010A5B0
    // 0x80800178: srl         $a1, $t2, 31
    ctx->r5 = S32(U32(ctx->r10) >> 31);
    func_8010A5B0(rdram, ctx);
        goto after_9;
    // 0x80800178: srl         $a1, $t2, 31
    ctx->r5 = S32(U32(ctx->r10) >> 31);
    after_9:
    // 0x8080017C: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: ori         $t6, $t5, 0x10
    ctx->r14 = ctx->r13 | 0X10;
    // 0x80800188: jal         0x80101DDC
    // 0x8080018C: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
    func_80101DDC(rdram, ctx);
        goto after_10;
    // 0x8080018C: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
    after_10:
    // 0x80800190: beql        $v0, $zero, L_80800298
    if (ctx->r2 == 0) {
        // 0x80800194: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800298;
    }
    goto skip_1;
    // 0x80800194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800198: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x8080019C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808001A0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x808001A4: bgez        $t9, L_808001B4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808001A8: nop
    
            goto L_808001B4;
    }
    // 0x808001A8: nop

    // 0x808001AC: b           L_808001B4
    // 0x808001B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_808001B4;
    // 0x808001B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_808001B4:
    // 0x808001B4: jal         0x8008A148
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_11;
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808001BC: b           L_80800298
    // 0x808001C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800298;
    // 0x808001C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001C4:
    // 0x808001C4: jal         0x8008A190
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_19(rdram, ctx);
        goto after_12;
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808001CC: jal         0x80101F24
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_13;
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808001D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1356, 0X8F8) << 16);
    // 0x808001D8: lwc1        $f6, 0x8F8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1356, 0X8F8));
    // 0x808001DC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x808001E0: nop

    // 0x808001E4: bc1f        L_808001F4
    if (!c1cs) {
        // 0x808001E8: nop
    
            goto L_808001F4;
    }
    // 0x808001E8: nop

    // 0x808001EC: jal         0x8010A570
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_14;
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
L_808001F4:
    // 0x808001F4: jal         0x80101DDC
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_15;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808001FC: beq         $v0, $zero, L_80800294
    if (ctx->r2 == 0) {
        // 0x80800200: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800294;
    }
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800204: jal         0x80800700
    // 0x80800208: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_80800700_ch2dbaddy(rdram, ctx);
        goto after_16;
    // 0x80800208: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_16:
    // 0x8080020C: b           L_80800298
    // 0x80800210: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800298;
    // 0x80800210: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800214:
    // 0x80800214: jal         0x8008A190
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_19(rdram, ctx);
        goto after_17;
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8080021C: jal         0x8008A160
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_13(rdram, ctx);
        goto after_18;
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800224: bnel        $v0, $zero, L_80800288
    if (ctx->r2 != 0) {
        // 0x80800228: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800288;
    }
    goto skip_2;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x8080022C: jal         0x808003C4
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003C4_ch2dbaddy(rdram, ctx);
        goto after_19;
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800234: beq         $v0, $zero, L_80800250
    if (ctx->r2 == 0) {
        // 0x80800238: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800250;
    }
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: jal         0x8008A148
    // 0x80800240: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_20;
    // 0x80800240: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_20:
    // 0x80800244: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800248: b           L_80800294
    // 0x8080024C: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
        goto L_80800294;
    // 0x8080024C: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
L_80800250:
    // 0x80800250: jal         0x80089F78
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_21;
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800258: beql        $v0, $zero, L_80800288
    if (ctx->r2 == 0) {
        // 0x8080025C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800288;
    }
    goto skip_3;
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80800260: jal         0x8008A110
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_3(rdram, ctx);
        goto after_22;
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800268: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8080026C: jal         0x800EE88C
    // 0x80800270: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800EE88C(rdram, ctx);
        goto after_23;
    // 0x80800270: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_23:
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800278: jal         0x80102D78
    // 0x8080027C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80102D78(rdram, ctx);
        goto after_24;
    // 0x8080027C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_24:
    // 0x80800280: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800288:
    // 0x80800288: addiu       $a1, $zero, 0x5802
    ctx->r5 = ADD32(0, 0X5802);
    // 0x8080028C: jal         0x8008A130
    // 0x80800290: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    _sucoaster_entrypoint_7(rdram, ctx);
        goto after_25;
    // 0x80800290: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_25:
L_80800294:
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
RECOMP_FUNC void func_80800108_chcactusofstrength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800108: jr          $ra
    // 0x8080010C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080010C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8010CBD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CBD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010CBD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010CBD8: jal         0x800F5A00
    // 0x8010CBDC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F5A00(rdram, ctx);
        goto after_0;
    // 0x8010CBDC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8010CBE0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8010CBE4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8010CBE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8010CBEC: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8010CBF0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8010CBF4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8010CBF8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010CBFC: swc1        $f8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f8.u32l;
    // 0x8010CC00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010CC04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010CC08: jr          $ra
    // 0x8010CC0C: nop

    return;
    // 0x8010CC0C: nop

;}
RECOMP_FUNC void _cothemedll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087878: syscall     635
    recomp_syscall_handler(rdram, ctx, 0x80087878);
    return;
    // 0x8008787C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800A9FA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9FA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A9FA4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800A9FA8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800A9FAC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A9FB0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A9FB4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800A9FB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A9FBC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A9FC0: addiu       $s1, $zero, 0x40
    ctx->r17 = ADD32(0, 0X40);
    // 0x800A9FC4: addiu       $s3, $zero, 0x4E
    ctx->r19 = ADD32(0, 0X4E);
L_800A9FC8:
    // 0x800A9FC8: jal         0x800A9F80
    // 0x800A9FCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A9F80(rdram, ctx);
        goto after_0;
    // 0x800A9FCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800A9FD0: beq         $v0, $zero, L_800A9FE0
    if (ctx->r2 == 0) {
        // 0x800A9FD4: xor         $v0, $s0, $s2
        ctx->r2 = ctx->r16 ^ ctx->r18;
            goto L_800A9FE0;
    }
    // 0x800A9FD4: xor         $v0, $s0, $s2
    ctx->r2 = ctx->r16 ^ ctx->r18;
    // 0x800A9FD8: beq         $v0, $zero, L_800A9FEC
    if (ctx->r2 == 0) {
        // 0x800A9FDC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800A9FEC;
    }
    // 0x800A9FDC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800A9FE0:
    // 0x800A9FE0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800A9FE4: bne         $s1, $s3, L_800A9FC8
    if (ctx->r17 != ctx->r19) {
        // 0x800A9FE8: nop
    
            goto L_800A9FC8;
    }
    // 0x800A9FE8: nop

L_800A9FEC:
    // 0x800A9FEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A9FF0: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800A9FF4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A9FF8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A9FFC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800AA000: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800AA004: jr          $ra
    // 0x800AA008: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800AA008: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800DB4_chamazongoldhordeofficial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800DB8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800DBC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80800DC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800DC4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800DC8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800DCC: jal         0x80100094
    // 0x80800DD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800DD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800DD4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80800DD8:
    // 0x80800DD8: lbu         $a1, 0x48($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X48);
    // 0x80800DDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800DE0: jal         0x800DC128
    // 0x80800DE4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    func_800DC128(rdram, ctx);
        goto after_1;
    // 0x80800DE4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_1:
    // 0x80800DE8: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x80800DEC: beq         $s1, $t6, L_80800DD8
    if (ctx->r17 == ctx->r14) {
        // 0x80800DF0: sb          $v0, 0x67($s0)
        MEM_B(0X67, ctx->r16) = ctx->r2;
            goto L_80800DD8;
    }
    // 0x80800DF0: sb          $v0, 0x67($s0)
    MEM_B(0X67, ctx->r16) = ctx->r2;
    // 0x80800DF4: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x80800DF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800DFC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800E00: swc1        $f4, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f4.u32l;
    // 0x80800E04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E08: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800E0C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800E10: jr          $ra
    // 0x80800E14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800E14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800C39A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C39A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C39A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C39A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C39AC: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C39B0: jal         0x800C1414
    // 0x800C39B4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C39B4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x800C39B8: lhu         $v0, 0x7A($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7A);
    // 0x800C39BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C39C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C39C4: srl         $t7, $v0, 13
    ctx->r15 = S32(U32(ctx->r2) >> 13);
    // 0x800C39C8: jr          $ra
    // 0x800C39CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800C39CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
;}
RECOMP_FUNC void _sccustom_banjo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A928: syscall     857
    recomp_syscall_handler(rdram, ctx, 0x8008A928);
    return;
    // 0x8008A92C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chpumproomswitch_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(996, 0X3C8) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x3C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(996, 0X3C8));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x3C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(996, 0X3C8));
;}
RECOMP_FUNC void func_800A9F14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9F14: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A9F18: bne         $a0, $at, L_800A9F28
    if (ctx->r4 != ctx->r1) {
        // 0x800A9F1C: addiu       $v0, $zero, 0x12
        ctx->r2 = ADD32(0, 0X12);
            goto L_800A9F28;
    }
    // 0x800A9F1C: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x800A9F20: jr          $ra
    // 0x800A9F24: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x800A9F24: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800A9F28:
    // 0x800A9F28: jr          $ra
    // 0x800A9F2C: nop

    return;
    // 0x800A9F2C: nop

;}
RECOMP_FUNC void func_8010CB0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CB0C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010CB10: addiu       $v0, $v0, 0x6F50
    ctx->r2 = ADD32(ctx->r2, 0X6F50);
    // 0x8010CB14: lh          $t6, 0xC($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XC);
    // 0x8010CB18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010CB1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010CB20: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8010CB24: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8010CB28: bne         $t6, $zero, L_8010CB38
    if (ctx->r14 != 0) {
        // 0x8010CB2C: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_8010CB38;
    }
    // 0x8010CB2C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8010CB30: b           L_8010CB74
    // 0x8010CB34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010CB74;
    // 0x8010CB34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010CB38:
    // 0x8010CB38: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8010CB3C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8010CB40: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8010CB44: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8010CB48: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8010CB4C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8010CB50: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010CB54: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8010CB58: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010CB5C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8010CB60: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010CB64: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8010CB68: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8010CB6C: jal         0x800F00A4
    // 0x8010CB70: nop

    func_800F00A4(rdram, ctx);
        goto after_0;
    // 0x8010CB70: nop

    after_0:
L_8010CB74:
    // 0x8010CB74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010CB78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8010CB7C: jr          $ra
    // 0x8010CB80: nop

    return;
    // 0x8010CB80: nop

;}
RECOMP_FUNC void bstaxi_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801024: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801028: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080102C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801030: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801034: jal         0x8008CABC
    // 0x80801038: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80801038: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    after_0:
    // 0x8080103C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80801040: jal         0x80800000
    // 0x80801044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bstaxi(rdram, ctx);
        goto after_1;
    // 0x80801044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080104C: jal         0x8009BB24
    // 0x80801050: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009BB24(rdram, ctx);
        goto after_2;
    // 0x80801050: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x80801054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801058: jal         0x80091A30
    // 0x8080105C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_3;
    // 0x8080105C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x80801060: beql        $v0, $zero, L_8080108C
    if (ctx->r2 == 0) {
        // 0x80801064: lbu         $v0, 0x15C($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X15C);
            goto L_8080108C;
    }
    goto skip_0;
    // 0x80801064: lbu         $v0, 0x15C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15C);
    skip_0:
    // 0x80801068: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080106C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80801070: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80801074: nop

    // 0x80801078: bc1fl       L_8080108C
    if (!c1cs) {
        // 0x8080107C: lbu         $v0, 0x15C($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X15C);
            goto L_8080108C;
    }
    goto skip_1;
    // 0x8080107C: lbu         $v0, 0x15C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15C);
    skip_1:
    // 0x80801080: jal         0x8009BC6C
    // 0x80801084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_4;
    // 0x80801084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801088: lbu         $v0, 0x15C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15C);
L_8080108C:
    // 0x8080108C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801090: beq         $v0, $zero, L_808010C0
    if (ctx->r2 == 0) {
        // 0x80801094: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808010C0;
    }
    // 0x80801094: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801098: beq         $v0, $at, L_80801118
    if (ctx->r2 == ctx->r1) {
        // 0x8080109C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801118;
    }
    // 0x8080109C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808010A4: beq         $v0, $at, L_80801140
    if (ctx->r2 == ctx->r1) {
        // 0x808010A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801140;
    }
    // 0x808010A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010AC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808010B0: beq         $v0, $at, L_8080117C
    if (ctx->r2 == ctx->r1) {
        // 0x808010B4: nop
    
            goto L_8080117C;
    }
    // 0x808010B4: nop

    // 0x808010B8: b           L_8080120C
    // 0x808010BC: nop

        goto L_8080120C;
    // 0x808010BC: nop

L_808010C0:
    // 0x808010C0: jal         0x8008DF8C
    // 0x808010C4: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_5;
    // 0x808010C4: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_5:
    // 0x808010C8: beq         $v0, $zero, L_808010EC
    if (ctx->r2 == 0) {
        // 0x808010CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808010EC;
    }
    // 0x808010CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010D0: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x808010D4: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808010D8: jal         0x8008CF1C
    // 0x808010DC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_6;
    // 0x808010DC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_6:
    // 0x808010E0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808010E4: b           L_8080120C
    // 0x808010E8: sb          $t6, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r14;
        goto L_8080120C;
    // 0x808010E8: sb          $t6, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r14;
L_808010EC:
    // 0x808010EC: jal         0x8008B324
    // 0x808010F0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    anctrl_isStopped(rdram, ctx);
        goto after_7;
    // 0x808010F0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_7:
    // 0x808010F4: beq         $v0, $zero, L_8080120C
    if (ctx->r2 == 0) {
        // 0x808010F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080120C;
    }
    // 0x808010F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010FC: lui         $a1, 0x3EF1
    ctx->r5 = S32(0X3EF1 << 16);
    // 0x80801100: ori         $a1, $a1, 0xA9FC
    ctx->r5 = ctx->r5 | 0XA9FC;
    // 0x80801104: jal         0x8008CF1C
    // 0x80801108: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_8;
    // 0x80801108: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_8:
    // 0x8080110C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80801110: b           L_8080120C
    // 0x80801114: sb          $t7, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r15;
        goto L_8080120C;
    // 0x80801114: sb          $t7, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r15;
L_80801118:
    // 0x80801118: jal         0x8008DF8C
    // 0x8080111C: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_9;
    // 0x8080111C: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_9:
    // 0x80801120: beq         $v0, $zero, L_8080120C
    if (ctx->r2 == 0) {
        // 0x80801124: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080120C;
    }
    // 0x80801124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801128: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8080112C: jal         0x8008CF1C
    // 0x80801130: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_10;
    // 0x80801130: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_10:
    // 0x80801134: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80801138: b           L_8080120C
    // 0x8080113C: sb          $t8, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r24;
        goto L_8080120C;
    // 0x8080113C: sb          $t8, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r24;
L_80801140:
    // 0x80801140: jal         0x8009D3A8
    // 0x80801144: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_11;
    // 0x80801144: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80801148: jal         0x8008E078
    // 0x8080114C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_12;
    // 0x8080114C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80801150: beq         $v0, $zero, L_8080120C
    if (ctx->r2 == 0) {
        // 0x80801154: nop
    
            goto L_8080120C;
    }
    // 0x80801154: nop

    // 0x80801158: jal         0x8009FE58
    // 0x8080115C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FE58(rdram, ctx);
        goto after_13;
    // 0x8080115C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80801160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801164: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80801168: jal         0x8008CF1C
    // 0x8080116C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_14;
    // 0x8080116C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_14:
    // 0x80801170: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80801174: b           L_8080120C
    // 0x80801178: sb          $t9, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r25;
        goto L_8080120C;
    // 0x80801178: sb          $t9, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r25;
L_8080117C:
    // 0x8080117C: jal         0x8009BB5C
    // 0x80801180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB5C(rdram, ctx);
        goto after_15;
    // 0x80801180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80801184: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80801188: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080118C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801190: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80801194: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80801198: jal         0x8009B9B0
    // 0x8080119C: nop

    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_16;
    // 0x8080119C: nop

    after_16:
    // 0x808011A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011A4: jal         0x8009D2D8
    // 0x808011A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8009D2D8(rdram, ctx);
        goto after_17;
    // 0x808011A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_17:
    // 0x808011AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011B0: jal         0x8009D3A8
    // 0x808011B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_18;
    // 0x808011B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x808011B8: jal         0x8009BB5C
    // 0x808011BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB5C(rdram, ctx);
        goto after_19;
    // 0x808011BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808011C0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808011C4: addiu       $t0, $zero, 0x123
    ctx->r8 = ADD32(0, 0X123);
    // 0x808011C8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x808011CC: nop

    // 0x808011D0: bc1f        L_808011E0
    if (!c1cs) {
        // 0x808011D4: nop
    
            goto L_808011E0;
    }
    // 0x808011D4: nop

    // 0x808011D8: b           L_808011F4
    // 0x808011DC: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
        goto L_808011F4;
    // 0x808011DC: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
L_808011E0:
    // 0x808011E0: jal         0x8008B324
    // 0x808011E4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    anctrl_isStopped(rdram, ctx);
        goto after_20;
    // 0x808011E4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_20:
    // 0x808011E8: beq         $v0, $zero, L_808011F4
    if (ctx->r2 == 0) {
        // 0x808011EC: addiu       $t1, $zero, 0x125
        ctx->r9 = ADD32(0, 0X125);
            goto L_808011F4;
    }
    // 0x808011EC: addiu       $t1, $zero, 0x125
    ctx->r9 = ADD32(0, 0X125);
    // 0x808011F0: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
L_808011F4:
    // 0x808011F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011F8: jal         0x80091A58
    // 0x808011FC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_21;
    // 0x808011FC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_21:
    // 0x80801200: beq         $v0, $zero, L_8080120C
    if (ctx->r2 == 0) {
        // 0x80801204: addiu       $t2, $zero, 0x124
        ctx->r10 = ADD32(0, 0X124);
            goto L_8080120C;
    }
    // 0x80801204: addiu       $t2, $zero, 0x124
    ctx->r10 = ADD32(0, 0X124);
    // 0x80801208: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
L_8080120C:
    // 0x8080120C: jal         0x8009BB50
    // 0x80801210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_22;
    // 0x80801210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80801214: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80801218: nop

    // 0x8080121C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80801220: nop

    // 0x80801224: bc1f        L_80801240
    if (!c1cs) {
        // 0x80801228: nop
    
            goto L_80801240;
    }
    // 0x80801228: nop

    // 0x8080122C: jal         0x8008E35C
    // 0x80801230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_23;
    // 0x80801230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80801234: beq         $v0, $zero, L_80801240
    if (ctx->r2 == 0) {
        // 0x80801238: addiu       $t3, $zero, 0x4C
        ctx->r11 = ADD32(0, 0X4C);
            goto L_80801240;
    }
    // 0x80801238: addiu       $t3, $zero, 0x4C
    ctx->r11 = ADD32(0, 0X4C);
    // 0x8080123C: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
L_80801240:
    // 0x80801240: jal         0x8008E078
    // 0x80801244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_24;
    // 0x80801244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80801248: beq         $v0, $zero, L_80801264
    if (ctx->r2 == 0) {
        // 0x8080124C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801264;
    }
    // 0x8080124C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801250: jal         0x80091A58
    // 0x80801254: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_25;
    // 0x80801254: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_25:
    // 0x80801258: beq         $v0, $zero, L_80801264
    if (ctx->r2 == 0) {
        // 0x8080125C: addiu       $t4, $zero, 0x126
        ctx->r12 = ADD32(0, 0X126);
            goto L_80801264;
    }
    // 0x8080125C: addiu       $t4, $zero, 0x126
    ctx->r12 = ADD32(0, 0X126);
    // 0x80801260: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
L_80801264:
    // 0x80801264: jal         0x8008E148
    // 0x80801268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_26;
    // 0x80801268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x8080126C: beq         $v0, $zero, L_80801278
    if (ctx->r2 == 0) {
        // 0x80801270: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80801278;
    }
    // 0x80801270: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80801274: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
L_80801278:
    // 0x80801278: jal         0x8008E260
    // 0x8080127C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E260(rdram, ctx);
        goto after_27;
    // 0x8080127C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80801280: beq         $v0, $zero, L_80801290
    if (ctx->r2 == 0) {
        // 0x80801284: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801290;
    }
    // 0x80801284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801288: addiu       $t6, $zero, 0x3D
    ctx->r14 = ADD32(0, 0X3D);
    // 0x8080128C: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
L_80801290:
    // 0x80801290: jal         0x8009E5C8
    // 0x80801294: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    bs_setState(rdram, ctx);
        goto after_28;
    // 0x80801294: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_28:
    // 0x80801298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080129C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808012A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808012A4: jr          $ra
    // 0x808012A8: nop

    return;
    // 0x808012A8: nop

;}
RECOMP_FUNC void gczoombox_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080010C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800114: beq         $a0, $zero, L_8080013C
    if (ctx->r4 == 0) {
        // 0x80800118: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8080013C;
    }
    // 0x80800118: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080011C: jal         0x800D52B0
    // 0x80800120: nop

    func_800D52B0(rdram, ctx);
        goto after_0;
    // 0x80800120: nop

    after_0:
    // 0x80800124: jal         0x80800000
    // 0x80800128: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800000_gczoombox(rdram, ctx);
        goto after_1;
    // 0x80800128: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080012C: jal         0x808000DC
    // 0x80800130: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808000DC_gczoombox(rdram, ctx);
        goto after_2;
    // 0x80800130: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800134: jal         0x8001B084
    // 0x80800138: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    heap_free(rdram, ctx);
        goto after_3;
    // 0x80800138: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
L_8080013C:
    // 0x8080013C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800140: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800144: jr          $ra
    // 0x80800148: nop

    return;
    // 0x80800148: nop

;}
RECOMP_FUNC void _sumumbofx_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089868: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x80089868);
    return;
    // 0x8008986C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80800A88_chflysaucercrate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A8C: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x80800A90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A9C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800AA0: jal         0x800EA05C
    // 0x80800AA4: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800AA4: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x80800AA8: addiu       $at, $zero, 0xCA
    ctx->r1 = ADD32(0, 0XCA);
    // 0x80800AAC: beq         $v0, $at, L_80800AC4
    if (ctx->r2 == ctx->r1) {
        // 0x80800AB0: addiu       $at, $zero, 0xD6
        ctx->r1 = ADD32(0, 0XD6);
            goto L_80800AC4;
    }
    // 0x80800AB0: addiu       $at, $zero, 0xD6
    ctx->r1 = ADD32(0, 0XD6);
    // 0x80800AB4: beq         $v0, $at, L_80800B3C
    if (ctx->r2 == ctx->r1) {
        // 0x80800AB8: nop
    
            goto L_80800B3C;
    }
    // 0x80800AB8: nop

    // 0x80800ABC: b           L_80800C0C
    // 0x80800AC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800C0C;
    // 0x80800AC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800AC4:
    // 0x80800AC4: jal         0x800DA298
    // 0x80800AC8: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800AC8: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    after_1:
    // 0x80800ACC: beq         $v0, $zero, L_80800AE4
    if (ctx->r2 == 0) {
        // 0x80800AD0: nop
    
            goto L_80800AE4;
    }
    // 0x80800AD0: nop

    // 0x80800AD4: jal         0x800FFAB0
    // 0x80800AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800ADC: b           L_80800C0C
    // 0x80800AE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800C0C;
    // 0x80800AE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800AE4:
    // 0x80800AE4: jal         0x800DA298
    // 0x80800AE8: addiu       $a0, $zero, 0x91
    ctx->r4 = ADD32(0, 0X91);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800AE8: addiu       $a0, $zero, 0x91
    ctx->r4 = ADD32(0, 0X91);
    after_3:
    // 0x80800AEC: beq         $v0, $zero, L_80800C08
    if (ctx->r2 == 0) {
        // 0x80800AF0: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1696, 0XCD8) << 16);
            goto L_80800C08;
    }
    // 0x80800AF0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XCD8) << 16);
    // 0x80800AF4: lwc1        $f6, 0xCD8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XCD8));
    // 0x80800AF8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XCDC) << 16);
    // 0x80800AFC: addiu       $a0, $zero, 0xB3
    ctx->r4 = ADD32(0, 0XB3);
    // 0x80800B00: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x80800B04: lwc1        $f8, 0xCDC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XCDC));
    // 0x80800B08: jal         0x800DA298
    // 0x80800B0C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800B0C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    after_4:
    // 0x80800B10: beq         $v0, $zero, L_80800B2C
    if (ctx->r2 == 0) {
        // 0x80800B14: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B2C;
    }
    // 0x80800B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B1C: jal         0x8080000C
    // 0x80800B20: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8080000C_chflysaucercrate(rdram, ctx);
        goto after_5;
    // 0x80800B20: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
    // 0x80800B24: b           L_80800C0C
    // 0x80800B28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800C0C;
    // 0x80800B28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B2C:
    // 0x80800B2C: jal         0x8080000C
    // 0x80800B30: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080000C_chflysaucercrate(rdram, ctx);
        goto after_6;
    // 0x80800B30: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x80800B34: b           L_80800C0C
    // 0x80800B38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800C0C;
    // 0x80800B38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B3C:
    // 0x80800B3C: jal         0x800DA298
    // 0x80800B40: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800B40: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    after_7:
    // 0x80800B44: beq         $v0, $zero, L_80800B64
    if (ctx->r2 == 0) {
        // 0x80800B48: nop
    
            goto L_80800B64;
    }
    // 0x80800B48: nop

    // 0x80800B4C: jal         0x800FFAB0
    // 0x80800B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_8;
    // 0x80800B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800B54: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80800B58: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x80800B5C: b           L_80800C08
    // 0x80800B60: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
        goto L_80800C08;
    // 0x80800B60: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
L_80800B64:
    // 0x80800B64: jal         0x80088840
    // 0x80800B68: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_9;
    // 0x80800B68: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_9:
    // 0x80800B6C: bne         $v0, $zero, L_80800B80
    if (ctx->r2 != 0) {
        // 0x80800B70: nop
    
            goto L_80800B80;
    }
    // 0x80800B70: nop

    // 0x80800B74: jal         0x800DA298
    // 0x80800B78: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x80800B78: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    after_10:
    // 0x80800B7C: beq         $v0, $zero, L_80800C00
    if (ctx->r2 == 0) {
        // 0x80800B80: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1696, 0XCE0) << 16);
            goto L_80800C00;
    }
L_80800B80:
    // 0x80800B80: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XCE0) << 16);
    // 0x80800B84: lwc1        $f10, 0xCE0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XCE0));
    // 0x80800B88: lui         $at, 0x44C8
    ctx->r1 = S32(0X44C8 << 16);
    // 0x80800B8C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800B90: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XCE4) << 16);
    // 0x80800B94: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x80800B98: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x80800B9C: lwc1        $f18, 0xCE4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XCE4));
    // 0x80800BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800BA8: jal         0x8008A4B0
    // 0x80800BAC: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_11;
    // 0x80800BAC: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    after_11:
    // 0x80800BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BB4: jal         0x8080000C
    // 0x80800BB8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8080000C_chflysaucercrate(rdram, ctx);
        goto after_12;
    // 0x80800BB8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_12:
    // 0x80800BBC: jal         0x80088840
    // 0x80800BC0: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_13;
    // 0x80800BC0: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_13:
    // 0x80800BC4: beq         $v0, $zero, L_80800BE8
    if (ctx->r2 == 0) {
        // 0x80800BC8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800BE8;
    }
    // 0x80800BC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800BCC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800BD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800BD4: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80800BD8: jal         0x80085708
    // 0x80800BDC: addiu       $a3, $zero, 0x2810
    ctx->r7 = ADD32(0, 0X2810);
    _capod_entrypoint_13(rdram, ctx);
        goto after_14;
    // 0x80800BDC: addiu       $a3, $zero, 0x2810
    ctx->r7 = ADD32(0, 0X2810);
    after_14:
    // 0x80800BE0: b           L_80800C0C
    // 0x80800BE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800C0C;
    // 0x80800BE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800BE8:
    // 0x80800BE8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800BEC: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80800BF0: jal         0x80085708
    // 0x80800BF4: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    _capod_entrypoint_13(rdram, ctx);
        goto after_15;
    // 0x80800BF4: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    after_15:
    // 0x80800BF8: b           L_80800C0C
    // 0x80800BFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800C0C;
    // 0x80800BFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800C00:
    // 0x80800C00: jal         0x800FFAB0
    // 0x80800C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_16;
    // 0x80800C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
L_80800C08:
    // 0x80800C08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800C0C:
    // 0x80800C0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800C10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800C14: jr          $ra
    // 0x80800C18: nop

    return;
    // 0x80800C18: nop

    // 0x80800C1C: nop

;}
