#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80801C7C_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801C80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801C84: jal         0x80801CB4
    // 0x80801C88: nop

    func_80801CB4_chinflatableboss(rdram, ctx);
        goto after_0;
    // 0x80801C88: nop

    after_0:
    // 0x80801C8C: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80801C90: subu        $v0, $t6, $v0
    ctx->r2 = SUB32(ctx->r14, ctx->r2);
    // 0x80801C94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801C98: bgez        $v0, L_80801CA8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80801C9C: sra         $t7, $v0, 1
        ctx->r15 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80801CA8;
    }
    // 0x80801C9C: sra         $t7, $v0, 1
    ctx->r15 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80801CA0: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x80801CA4: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_80801CA8:
    // 0x80801CA8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80801CAC: jr          $ra
    // 0x80801CB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80801CB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _glgamestore_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800884C0: syscall     688
    recomp_syscall_handler(rdram, ctx, 0x800884C0);
    return;
    // 0x800884C4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80092E5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092E5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80092E60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80092E64: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80092E68: jal         0x800921E0
    // 0x80092E6C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800921E0(rdram, ctx);
        goto after_0;
    // 0x80092E6C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x80092E70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80092E74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80092E78: jr          $ra
    // 0x80092E7C: nop

    return;
    // 0x80092E7C: nop

;}
RECOMP_FUNC void func_808027DC_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808027DC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808027E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808027E4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808027E8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808027EC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808027F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808027F4: jal         0x80100094
    // 0x808027F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808027F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808027FC: beq         $v0, $zero, L_8080297C
    if (ctx->r2 == 0) {
        // 0x80802800: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8080297C;
    }
    // 0x80802800: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80802804: lw          $t6, 0x64($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X64);
    // 0x80802808: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x8080280C: bgezl       $t8, L_80802838
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80802810: lhu         $v0, 0x72($s1)
        ctx->r2 = MEM_HU(ctx->r17, 0X72);
            goto L_80802838;
    }
    goto skip_0;
    // 0x80802810: lhu         $v0, 0x72($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X72);
    skip_0:
    // 0x80802814: jal         0x80087E18
    // 0x80802818: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gcnewoption_entrypoint_48(rdram, ctx);
        goto after_1;
    // 0x80802818: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080281C: beq         $v0, $zero, L_80802834
    if (ctx->r2 == 0) {
        // 0x80802820: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_80802834;
    }
    // 0x80802820: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80802824: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    // 0x80802828: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8080282C: jal         0x80800AEC
    // 0x80802830: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_80800AEC_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80802830: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
L_80802834:
    // 0x80802834: lhu         $v0, 0x72($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X72);
L_80802838:
    // 0x80802838: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080283C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802840: srl         $t9, $v0, 10
    ctx->r25 = S32(U32(ctx->r2) >> 10);
    // 0x80802844: beq         $t9, $at, L_8080285C
    if (ctx->r25 == ctx->r1) {
        // 0x80802848: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080285C;
    }
    // 0x80802848: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080284C: beq         $t9, $at, L_808028AC
    if (ctx->r25 == ctx->r1) {
        // 0x80802850: nop
    
            goto L_808028AC;
    }
    // 0x80802850: nop

    // 0x80802854: b           L_80802974
    // 0x80802858: nop

        goto L_80802974;
    // 0x80802858: nop

L_8080285C:
    // 0x8080285C: jal         0x80100094
    // 0x80802860: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80802860: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80802864: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80802868: jal         0x80087E00
    // 0x8080286C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _gcnewoption_entrypoint_45(rdram, ctx);
        goto after_4;
    // 0x8080286C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x80802870: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80802874: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80802878: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x8080287C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80802880: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80802884: lb          $s0, 0x3($t2)
    ctx->r16 = MEM_B(ctx->r10, 0X3);
    // 0x80802888: bltz        $s0, L_80802974
    if (SIGNED(ctx->r16) < 0) {
        // 0x8080288C: nop
    
            goto L_80802974;
    }
    // 0x8080288C: nop

    // 0x80802890: jal         0x80106790
    // 0x80802894: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    func_80106790(rdram, ctx);
        goto after_5;
    // 0x80802894: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    after_5:
    // 0x80802898: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    // 0x8080289C: jal         0x808026C8
    // 0x808028A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_808026C8_chgameselect(rdram, ctx);
        goto after_6;
    // 0x808028A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x808028A4: b           L_80802974
    // 0x808028A8: nop

        goto L_80802974;
    // 0x808028A8: nop

L_808028AC:
    // 0x808028AC: jal         0x80015FA0
    // 0x808028B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80015FA0(rdram, ctx);
        goto after_7;
    // 0x808028B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x808028B4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x808028B8: bne         $v0, $s0, L_80802928
    if (ctx->r2 != ctx->r16) {
        // 0x808028BC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80802928;
    }
    // 0x808028BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808028C0: lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2C);
    // 0x808028C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808028C8: blez        $v0, L_808028FC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808028CC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808028FC;
    }
    // 0x808028CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808028D0:
    // 0x808028D0: jal         0x80087D20
    // 0x808028D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gcnewoption_entrypoint_17(rdram, ctx);
        goto after_8;
    // 0x808028D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x808028D8: beql        $v0, $zero, L_808028EC
    if (ctx->r2 == 0) {
        // 0x808028DC: lw          $v0, 0x2C($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X2C);
            goto L_808028EC;
    }
    goto skip_1;
    // 0x808028DC: lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2C);
    skip_1:
    // 0x808028E0: b           L_808028FC
    // 0x808028E4: lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2C);
        goto L_808028FC;
    // 0x808028E4: lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2C);
    // 0x808028E8: lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2C);
L_808028EC:
    // 0x808028EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808028F0: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808028F4: bnel        $at, $zero, L_808028D0
    if (ctx->r1 != 0) {
        // 0x808028F8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808028D0;
    }
    goto skip_2;
    // 0x808028F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_2:
L_808028FC:
    // 0x808028FC: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80802900: beq         $at, $zero, L_80802918
    if (ctx->r1 == 0) {
        // 0x80802904: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80802918;
    }
    // 0x80802904: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802908: jal         0x80087DC0
    // 0x8080290C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_37(rdram, ctx);
        goto after_9;
    // 0x8080290C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80802910: b           L_80802974
    // 0x80802914: nop

        goto L_80802974;
    // 0x80802914: nop

L_80802918:
    // 0x80802918: jal         0x80803C60
    // 0x8080291C: nop

    func_80803C60_chgameselect(rdram, ctx);
        goto after_10;
    // 0x8080291C: nop

    after_10:
    // 0x80802920: b           L_80802974
    // 0x80802924: nop

        goto L_80802974;
    // 0x80802924: nop

L_80802928:
    // 0x80802928: jal         0x80016B54
    // 0x8080292C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80016B54(rdram, ctx);
        goto after_11;
    // 0x8080292C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80802930: bne         $v0, $s0, L_80802974
    if (ctx->r2 != ctx->r16) {
        // 0x80802934: nop
    
            goto L_80802974;
    }
    // 0x80802934: nop

    // 0x80802938: lw          $t3, 0x2C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X2C);
    // 0x8080293C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80802940: blez        $t3, L_8080296C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80802944: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080296C;
    }
    // 0x80802944: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80802948:
    // 0x80802948: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080294C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802950: jal         0x80803604
    // 0x80802954: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80803604_chgameselect(rdram, ctx);
        goto after_12;
    // 0x80802954: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
    // 0x80802958: lw          $t4, 0x2C($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X2C);
    // 0x8080295C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80802960: slt         $at, $s0, $t4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80802964: bnel        $at, $zero, L_80802948
    if (ctx->r1 != 0) {
        // 0x80802968: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80802948;
    }
    goto skip_3;
    // 0x80802968: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_3:
L_8080296C:
    // 0x8080296C: jal         0x80803CE0
    // 0x80802970: nop

    func_80803CE0_chgameselect(rdram, ctx);
        goto after_13;
    // 0x80802970: nop

    after_13:
L_80802974:
    // 0x80802974: jal         0x80087C98
    // 0x80802978: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _gcnewoption_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x80802978: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_14:
L_8080297C:
    // 0x8080297C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80802980: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802984: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80802988: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080298C: jr          $ra
    // 0x80802990: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80802990: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _glgamedata_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088578: syscall     693
    recomp_syscall_handler(rdram, ctx, 0x80088578);
    return;
    // 0x8008857C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800018_chboggyfatboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080001C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800020: jal         0x80085CE0
    // 0x80800024: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _chboggykids_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800024: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800028: bne         $v0, $zero, L_80800040
    if (ctx->r2 != 0) {
        // 0x8080002C: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_80800040;
    }
    // 0x8080002C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800030: jal         0x800FFAB0
    // 0x80800034: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800034: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x80800038: b           L_80800068
    // 0x8080003C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800068;
    // 0x8080003C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800040:
    // 0x80800040: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x80800044: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800048: addiu       $a0, $zero, 0x8E
    ctx->r4 = ADD32(0, 0X8E);
    // 0x8080004C: jal         0x800DA298
    // 0x80800050: swc1        $f4, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f4.u32l;
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800050: swc1        $f4, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f4.u32l;
    after_2:
    // 0x80800054: beql        $v0, $zero, L_80800068
    if (ctx->r2 == 0) {
        // 0x80800058: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800068;
    }
    goto skip_0;
    // 0x80800058: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8080005C: b           L_80800068
    // 0x80800060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800068;
    // 0x80800060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800064: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800068:
    // 0x80800068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080006C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800070: jr          $ra
    // 0x80800074: nop

    return;
    // 0x80800074: nop

;}
RECOMP_FUNC void chbadshad_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800464: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800468: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080046C: jal         0x80800664
    // 0x80800470: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80800664_chbadshad(rdram, ctx);
        goto after_0;
    // 0x80800470: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800474: beq         $v0, $zero, L_80800480
    if (ctx->r2 == 0) {
        // 0x80800478: lwc1        $f4, 0x20($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
            goto L_80800480;
    }
    // 0x80800478: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8080047C: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
L_80800480:
    // 0x80800480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800484: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800488: jr          $ra
    // 0x8080048C: nop

    return;
    // 0x8080048C: nop

;}
RECOMP_FUNC void _chlavacolumnswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F38: syscall     477
    recomp_syscall_handler(rdram, ctx, 0x80086F38);
    return;
    // 0x80086F3C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800A74_bsswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800A80: jal         0x800839E8
    // 0x80800A84: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800A84: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800A88: beq         $v0, $zero, L_80800A9C
    if (ctx->r2 == 0) {
        // 0x80800A8C: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80800A9C;
    }
    // 0x80800A8C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A90: jal         0x800839B0
    // 0x80800A94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bsrest_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80800A94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800A98: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80800A9C:
    // 0x80800A9C: jal         0x8009E5C8
    // 0x80800AA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80800AA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800AA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800AA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800AAC: jr          $ra
    // 0x80800AB0: nop

    return;
    // 0x80800AB0: nop

;}
RECOMP_FUNC void func_8008B4C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B4C4: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8008B4C8: sll         $t6, $v0, 29
    ctx->r14 = S32(ctx->r2 << 29);
    // 0x8008B4CC: jr          $ra
    // 0x8008B4D0: srl         $v0, $t6, 31
    ctx->r2 = S32(U32(ctx->r14) >> 31);
    return;
    // 0x8008B4D0: srl         $v0, $t6, 31
    ctx->r2 = S32(U32(ctx->r14) >> 31);
;}
RECOMP_FUNC void _dbtex_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087A30: syscall     650
    recomp_syscall_handler(rdram, ctx, 0x80087A30);
    return;
    // 0x80087A34: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chjigsawcollect_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1476, 0X670) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x670
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1476, 0X670));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x670
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1476, 0X670));
;}
RECOMP_FUNC void func_80800508_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800508: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080050C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800510: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800514: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800518: jal         0x8009E69C
    // 0x8080051C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E69C(rdram, ctx);
        goto after_0;
    // 0x8080051C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800520: bne         $v0, $zero, L_808005DC
    if (ctx->r2 != 0) {
        // 0x80800524: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005DC;
    }
    // 0x80800524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800528: jal         0x800A0DC4
    // 0x8080052C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0DC4(rdram, ctx);
        goto after_1;
    // 0x8080052C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800534: jal         0x8008C984
    // 0x80800538: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8008C984(rdram, ctx);
        goto after_2;
    // 0x80800538: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800540: jal         0x800961AC
    // 0x80800544: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_3;
    // 0x80800544: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800548: jal         0x8009BC34
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BC34(rdram, ctx);
        goto after_4;
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800554: jal         0x8009BF5C
    // 0x80800558: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_5;
    // 0x80800558: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800560: jal         0x8009C4CC
    // 0x80800564: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_6;
    // 0x80800564: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x80800568: jal         0x8009C000
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009C000(rdram, ctx);
        goto after_7;
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800570: jal         0x8009C570
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baroll_resetAngularVelocity(rdram, ctx);
        goto after_8;
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800578: jal         0x8009EF60
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_popZone(rdram, ctx);
        goto after_9;
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800580: jal         0x80095A40
    // 0x80800584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095A40(rdram, ctx);
        goto after_10;
    // 0x80800584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080058C: jal         0x80093360
    // 0x80800590: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80093360(rdram, ctx);
        goto after_11;
    // 0x80800590: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_11:
    // 0x80800594: jal         0x80084D80
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bakaztorpedo_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080059C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A0: jal         0x800910BC
    // 0x808005A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800910BC(rdram, ctx);
        goto after_13;
    // 0x808005A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x808005A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808005B0: jal         0x800947EC
    // 0x808005B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_14;
    // 0x808005B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x808005B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005BC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808005C0: jal         0x80084CD0
    // 0x808005C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _bafpctrl_entrypoint_11(rdram, ctx);
        goto after_15;
    // 0x808005C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
    // 0x808005C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005CC: jal         0x80084CE8
    // 0x808005D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bafpctrl_entrypoint_14(rdram, ctx);
        goto after_16;
    // 0x808005D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x808005D4: jal         0x8009E474
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E474(rdram, ctx);
        goto after_17;
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
L_808005DC:
    // 0x808005DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808005E8: jr          $ra
    // 0x808005EC: nop

    return;
    // 0x808005EC: nop

;}
RECOMP_FUNC void _bsswim_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083D88: syscall     94
    recomp_syscall_handler(rdram, ctx, 0x80083D88);
    return;
    // 0x80083D8C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808002CC_glgamedata(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002CC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x808002D0: lui         $at, 0x4B48
    ctx->r1 = S32(0X4B48 << 16);
    // 0x808002D4: ori         $at, $at, 0x4A43
    ctx->r1 = ctx->r1 | 0X4A43;
    // 0x808002D8: bne         $t6, $at, L_808002E8
    if (ctx->r14 != ctx->r1) {
        // 0x808002DC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_808002E8;
    }
    // 0x808002DC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808002E0: jr          $ra
    // 0x808002E4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x808002E4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808002E8:
    // 0x808002E8: jr          $ra
    // 0x808002EC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x808002EC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_808002C0_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002D0: jal         0x80082840
    // 0x808002D4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    _bsbee_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808002D4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002DC: jal         0x8009D3A8
    // 0x808002E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_1;
    // 0x808002E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808002E4: jal         0x80800058
    // 0x808002E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800058_bsbeemain(rdram, ctx);
        goto after_2;
    // 0x808002E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808002EC: lui         $a1, 0x3F70
    ctx->r5 = S32(0X3F70 << 16);
    // 0x808002F0: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    // 0x808002F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F8: jal         0x800A2CE8
    // 0x808002FC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2CE8(rdram, ctx);
        goto after_3;
    // 0x808002FC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x80800300: lui         $a1, 0x3EE1
    ctx->r5 = S32(0X3EE1 << 16);
    // 0x80800304: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080030C: jal         0x800A2CE8
    // 0x80800310: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_4;
    // 0x80800310: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_4:
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800318: jal         0x800919F4
    // 0x8080031C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_5;
    // 0x8080031C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800320: beq         $v0, $zero, L_80800330
    if (ctx->r2 == 0) {
        // 0x80800324: nop
    
            goto L_80800330;
    }
    // 0x80800324: nop

    // 0x80800328: jal         0x80084550
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babee_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80800330:
    // 0x80800330: jal         0x8009EF10
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_7;
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800338: bne         $v0, $zero, L_80800354
    if (ctx->r2 != 0) {
        // 0x8080033C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800354;
    }
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800340: jal         0x8009BCD4
    // 0x80800344: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_8;
    // 0x80800344: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_8:
    // 0x80800348: beq         $v0, $zero, L_80800354
    if (ctx->r2 == 0) {
        // 0x8080034C: addiu       $t6, $zero, 0x85
        ctx->r14 = ADD32(0, 0X85);
            goto L_80800354;
    }
    // 0x8080034C: addiu       $t6, $zero, 0x85
    ctx->r14 = ADD32(0, 0X85);
    // 0x80800350: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800354:
    // 0x80800354: jal         0x8008DD04
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_9;
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080035C: beq         $v0, $zero, L_8080036C
    if (ctx->r2 == 0) {
        // 0x80800360: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080036C;
    }
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800364: addiu       $t7, $zero, 0x88
    ctx->r15 = ADD32(0, 0X88);
    // 0x80800368: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_8080036C:
    // 0x8080036C: jal         0x80091A58
    // 0x80800370: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_10;
    // 0x80800370: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_10:
    // 0x80800374: beq         $v0, $zero, L_80800380
    if (ctx->r2 == 0) {
        // 0x80800378: addiu       $t8, $zero, 0x87
        ctx->r24 = ADD32(0, 0X87);
            goto L_80800380;
    }
    // 0x80800378: addiu       $t8, $zero, 0x87
    ctx->r24 = ADD32(0, 0X87);
    // 0x8080037C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80800380:
    // 0x80800380: jal         0x8008E35C
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_11;
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800388: beq         $v0, $zero, L_80800398
    if (ctx->r2 == 0) {
        // 0x8080038C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800398;
    }
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800390: addiu       $t9, $zero, 0x8C
    ctx->r25 = ADD32(0, 0X8C);
    // 0x80800394: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_80800398:
    // 0x80800398: jal         0x8009E5C8
    // 0x8080039C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_12;
    // 0x8080039C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_12:
    // 0x808003A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003AC: jr          $ra
    // 0x808003B0: nop

    return;
    // 0x808003B0: nop

;}
RECOMP_FUNC void func_80800768_chsunlightspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800768: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080076C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800770: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800774: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800778: jal         0x80100094
    // 0x8080077C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080077C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800780: beq         $v0, $zero, L_8080079C
    if (ctx->r2 == 0) {
        // 0x80800784: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080079C;
    }
    // 0x80800784: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800788: jal         0x80100094
    // 0x8080078C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080078C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800790: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800794: jal         0x80089880
    // 0x80800798: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _sumumbofx_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80800798: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_8080079C:
    // 0x8080079C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808007A0: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x808007A4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x808007A8: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x808007AC: bgezl       $t9, L_808007C0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808007B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808007C0;
    }
    goto skip_0;
    // 0x808007B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808007B4: jal         0x80101870
    // 0x808007B8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_3;
    // 0x808007B8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x808007BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007C0:
    // 0x808007C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007C4: jr          $ra
    // 0x808007C8: nop

    return;
    // 0x808007C8: nop

;}
RECOMP_FUNC void gclevel_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80800008: lbu         $t6, 0x762C($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X762C);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800014: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800018: jal         0x80800108
    // 0x8080001C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    gclevel_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080001C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80800020: jal         0x800A824C
    // 0x80800024: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800A824C(rdram, ctx);
        goto after_1;
    // 0x80800024: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800028: beq         $v0, $zero, L_80800040
    if (ctx->r2 == 0) {
        // 0x8080002C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800040;
    }
    // 0x8080002C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800030: jal         0x800A8240
    // 0x80800034: nop

    func_800A8240(rdram, ctx);
        goto after_2;
    // 0x80800034: nop

    after_2:
    // 0x80800038: b           L_808000AC
    // 0x8080003C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000AC;
    // 0x8080003C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800040:
    // 0x80800040: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800044: jal         0x80800270
    // 0x80800048: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    func_80800270_gclevel(rdram, ctx);
        goto after_3;
    // 0x80800048: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8080004C: beq         $v0, $zero, L_8080005C
    if (ctx->r2 == 0) {
        // 0x80800050: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_8080005C;
    }
    // 0x80800050: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800054: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80800058: sb          $t7, 0x762D($at)
    MEM_B(0X762D, ctx->r1) = ctx->r15;
L_8080005C:
    // 0x8080005C: jal         0x80087830
    // 0x80800060: nop

    _cosectionstor_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80800060: nop

    after_4:
    // 0x80800064: jal         0x800A13A0
    // 0x80800068: nop

    func_800A13A0(rdram, ctx);
        goto after_5;
    // 0x80800068: nop

    after_5:
    // 0x8080006C: jal         0x800CE524
    // 0x80800070: nop

    func_800CE524(rdram, ctx);
        goto after_6;
    // 0x80800070: nop

    after_6:
    // 0x80800074: jal         0x800CEF7C
    // 0x80800078: nop

    func_800CEF7C(rdram, ctx);
        goto after_7;
    // 0x80800078: nop

    after_7:
    // 0x8080007C: jal         0x800DA104
    // 0x80800080: nop

    func_800DA104(rdram, ctx);
        goto after_8;
    // 0x80800080: nop

    after_8:
    // 0x80800084: jal         0x8009E9A8
    // 0x80800088: nop

    func_8009E9A8(rdram, ctx);
        goto after_9;
    // 0x80800088: nop

    after_9:
    // 0x8080008C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800090: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800094: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800098: jal         0x8080016C
    // 0x8080009C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_8080016C_gclevel(rdram, ctx);
        goto after_10;
    // 0x8080009C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_10:
    // 0x808000A0: jal         0x800C75E8
    // 0x808000A4: nop

    func_800C75E8(rdram, ctx);
        goto after_11;
    // 0x808000A4: nop

    after_11:
    // 0x808000A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000AC:
    // 0x808000AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000B0: jr          $ra
    // 0x808000B4: nop

    return;
    // 0x808000B4: nop

;}
RECOMP_FUNC void glsavegame_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800114: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800118: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8080011C: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80800120: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800124: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x80800128: addiu       $s5, $s5, 0x7618
    ctx->r21 = ADD32(ctx->r21, 0X7618);
    // 0x8080012C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800130: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800134: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80800138: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8080013C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800140: addiu       $s2, $t6, 0x7618
    ctx->r18 = ADD32(ctx->r14, 0X7618);
    // 0x80800144: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80800148: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8080014C: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80800150: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80800154: sb          $s3, 0x12($s5)
    MEM_B(0X12, ctx->r21) = ctx->r19;
    // 0x80800158: sb          $s3, 0xF($s5)
    MEM_B(0XF, ctx->r21) = ctx->r19;
    // 0x8080015C: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x80800160: addiu       $s1, $s1, 0x7624
    ctx->r17 = ADD32(ctx->r17, 0X7624);
    // 0x80800164: or          $s4, $s2, $zero
    ctx->r20 = ctx->r18 | 0;
    // 0x80800168: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
L_8080016C:
    // 0x8080016C: sb          $s3, 0xC($s4)
    MEM_B(0XC, ctx->r20) = ctx->r19;
    // 0x80800170: jal         0x80800000
    // 0x80800174: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    func_80800000_glsavegame(rdram, ctx);
        goto after_0;
    // 0x80800174: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    after_0:
    // 0x80800178: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x8080017C: jal         0x800885A0
    // 0x80800180: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _glgamedata_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800180: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800184: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80800188: sltu        $at, $s2, $s1
    ctx->r1 = ctx->r18 < ctx->r17 ? 1 : 0;
    // 0x8080018C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80800190: bne         $at, $zero, L_8080016C
    if (ctx->r1 != 0) {
        // 0x80800194: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8080016C;
    }
    // 0x80800194: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800198: jal         0x80800000
    // 0x8080019C: nop

    func_80800000_glsavegame(rdram, ctx);
        goto after_2;
    // 0x8080019C: nop

    after_2:
    // 0x808001A0: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808001A4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808001A8: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x808001AC: addiu       $s6, $sp, 0x50
    ctx->r22 = ADD32(ctx->r29, 0X50);
    // 0x808001B0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x808001B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808001B8:
    // 0x808001B8: jal         0x80800020
    // 0x808001BC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_80800020_glsavegame(rdram, ctx);
        goto after_3;
    // 0x808001BC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_3:
    // 0x808001C0: bne         $v0, $zero, L_80800214
    if (ctx->r2 != 0) {
        // 0x808001C4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80800214;
    }
    // 0x808001C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808001C8: jal         0x808000CC
    // 0x808001CC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_808000CC_glsavegame(rdram, ctx);
        goto after_4;
    // 0x808001CC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_4:
    // 0x808001D0: addu        $t7, $s5, $v0
    ctx->r15 = ADD32(ctx->r21, ctx->r2);
    // 0x808001D4: lb          $t8, 0xC($t7)
    ctx->r24 = MEM_B(ctx->r15, 0XC);
    // 0x808001D8: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x808001DC: addu        $t9, $s5, $v0
    ctx->r25 = ADD32(ctx->r21, ctx->r2);
    // 0x808001E0: bne         $s3, $t8, L_80800210
    if (ctx->r19 != ctx->r24) {
        // 0x808001E4: addu        $t1, $s6, $t0
        ctx->r9 = ADD32(ctx->r22, ctx->r8);
            goto L_80800210;
    }
    // 0x808001E4: addu        $t1, $s6, $t0
    ctx->r9 = ADD32(ctx->r22, ctx->r8);
    // 0x808001E8: sb          $s1, 0xC($t9)
    MEM_B(0XC, ctx->r25) = ctx->r17;
    // 0x808001EC: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x808001F0: sw          $s2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r18;
    // 0x808001F4: addu        $t3, $s5, $t2
    ctx->r11 = ADD32(ctx->r21, ctx->r10);
    // 0x808001F8: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x808001FC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800200: jal         0x8001BBC8
    // 0x80800204: addiu       $a2, $zero, 0x1C0
    ctx->r6 = ADD32(0, 0X1C0);
    aligned4_memcpy(rdram, ctx);
        goto after_5;
    // 0x80800204: addiu       $a2, $zero, 0x1C0
    ctx->r6 = ADD32(0, 0X1C0);
    after_5:
    // 0x80800208: b           L_80800214
    // 0x8080020C: nop

        goto L_80800214;
    // 0x8080020C: nop

L_80800210:
    // 0x80800210: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_80800214:
    // 0x80800214: beql        $s0, $zero, L_80800224
    if (ctx->r16 == 0) {
        // 0x80800218: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800224;
    }
    goto skip_0;
    // 0x80800218: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8080021C: sb          $s1, 0xF($s5)
    MEM_B(0XF, ctx->r21) = ctx->r17;
    // 0x80800220: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800224:
    // 0x80800224: bnel        $s1, $s7, L_808001B8
    if (ctx->r17 != ctx->r23) {
        // 0x80800228: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808001B8;
    }
    goto skip_1;
    // 0x80800228: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
    // 0x8080022C: jal         0x8001B084
    // 0x80800230: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    heap_free(rdram, ctx);
        goto after_6;
    // 0x80800230: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_6:
    // 0x80800234: lb          $t4, 0xF($s5)
    ctx->r12 = MEM_B(ctx->r21, 0XF);
    // 0x80800238: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8080023C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80800240: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80800244: addu        $t6, $s6, $t5
    ctx->r14 = ADD32(ctx->r22, ctx->r13);
    // 0x80800248: sw          $s2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r18;
    // 0x8080024C: addiu       $v1, $v1, 0x761B
    ctx->r3 = ADD32(ctx->r3, 0X761B);
    // 0x80800250: addiu       $v0, $v0, 0x7618
    ctx->r2 = ADD32(ctx->r2, 0X7618);
    // 0x80800254: lb          $t7, 0xC($v0)
    ctx->r15 = MEM_B(ctx->r2, 0XC);
L_80800258:
    // 0x80800258: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8080025C: sll         $t8, $zero, 2
    ctx->r24 = S32(0 << 2);
    // 0x80800260: bne         $s3, $t7, L_8080029C
    if (ctx->r19 != ctx->r15) {
        // 0x80800264: addiu       $t9, $sp, 0x50
        ctx->r25 = ADD32(ctx->r29, 0X50);
            goto L_8080029C;
    }
    // 0x80800264: addiu       $t9, $sp, 0x50
    ctx->r25 = ADD32(ctx->r29, 0X50);
    // 0x80800268: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x8080026C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
L_80800270:
    // 0x80800270: bnel        $t0, $zero, L_80800284
    if (ctx->r8 != 0) {
        // 0x80800274: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800284;
    }
    goto skip_2;
    // 0x80800274: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x80800278: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
    // 0x8080027C: sb          $s1, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r17;
    // 0x80800280: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800284:
    // 0x80800284: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80800288: beq         $at, $zero, L_8080029C
    if (ctx->r1 == 0) {
        // 0x8080028C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8080029C;
    }
    // 0x8080028C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800290: lb          $t1, 0xC($v0)
    ctx->r9 = MEM_B(ctx->r2, 0XC);
    // 0x80800294: beql        $s3, $t1, L_80800270
    if (ctx->r19 == ctx->r9) {
        // 0x80800298: lw          $t0, 0x0($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X0);
            goto L_80800270;
    }
    goto skip_3;
    // 0x80800298: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    skip_3:
L_8080029C:
    // 0x8080029C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x808002A0: bnel        $v0, $v1, L_80800258
    if (ctx->r2 != ctx->r3) {
        // 0x808002A4: lb          $t7, 0xC($v0)
        ctx->r15 = MEM_B(ctx->r2, 0XC);
            goto L_80800258;
    }
    goto skip_4;
    // 0x808002A4: lb          $t7, 0xC($v0)
    ctx->r15 = MEM_B(ctx->r2, 0XC);
    skip_4:
    // 0x808002A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808002AC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808002B0: sb          $v0, 0x10($s5)
    MEM_B(0X10, ctx->r21) = ctx->r2;
    // 0x808002B4: sb          $v0, 0x11($s5)
    MEM_B(0X11, ctx->r21) = ctx->r2;
    // 0x808002B8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x808002BC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808002C0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808002C4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808002C8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808002CC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x808002D0: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x808002D4: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x808002D8: jr          $ra
    // 0x808002DC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x808002DC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void _gcgoto_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087AC0: syscall     652
    recomp_syscall_handler(rdram, ctx, 0x80087AC0);
    return;
    // 0x80087AC4: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void _chterryteeth_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800870C0: syscall     510
    recomp_syscall_handler(rdram, ctx, 0x800870C0);
    return;
    // 0x800870C4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _badrone_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800848E0: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x800848E0);
    return;
    // 0x800848E4: addi        $t0, $zero, 0x7C
    ctx->r8 = ADD32(0, 0X7C);
;}
RECOMP_FUNC void chgobicommon_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x801022E4
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_801022E4(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: addiu       $at, $zero, 0x221
    ctx->r1 = ADD32(0, 0X221);
    // 0x80800014: beq         $v0, $at, L_80800038
    if (ctx->r2 == ctx->r1) {
        // 0x80800018: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800038;
    }
    // 0x80800018: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080001C: addiu       $at, $zero, 0x222
    ctx->r1 = ADD32(0, 0X222);
    // 0x80800020: beq         $v0, $at, L_80800048
    if (ctx->r2 == ctx->r1) {
        // 0x80800024: addiu       $at, $zero, 0x223
        ctx->r1 = ADD32(0, 0X223);
            goto L_80800048;
    }
    // 0x80800024: addiu       $at, $zero, 0x223
    ctx->r1 = ADD32(0, 0X223);
    // 0x80800028: beq         $v0, $at, L_80800058
    if (ctx->r2 == ctx->r1) {
        // 0x8080002C: nop
    
            goto L_80800058;
    }
    // 0x8080002C: nop

    // 0x80800030: b           L_80800064
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800064;
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800038:
    // 0x80800038: jal         0x80800070
    // 0x8080003C: nop

    func_80800070_chgobicommon(rdram, ctx);
        goto after_1;
    // 0x8080003C: nop

    after_1:
    // 0x80800040: b           L_80800064
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800064;
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800048:
    // 0x80800048: jal         0x808000EC
    // 0x8080004C: nop

    func_808000EC_chgobicommon(rdram, ctx);
        goto after_2;
    // 0x8080004C: nop

    after_2:
    // 0x80800050: b           L_80800064
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800064;
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800058:
    // 0x80800058: jal         0x808001AC
    // 0x8080005C: nop

    func_808001AC_chgobicommon(rdram, ctx);
        goto after_3;
    // 0x8080005C: nop

    after_3:
    // 0x80800060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800064:
    // 0x80800064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800068: jr          $ra
    // 0x8080006C: nop

    return;
    // 0x8080006C: nop

;}
RECOMP_FUNC void babuzz_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800124: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800128: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080012C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800130: jal         0x800C2E04
    // 0x80800134: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800C2E04(rdram, ctx);
        goto after_0;
    // 0x80800134: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800138: lw          $t6, 0x34($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X34);
    // 0x8080013C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800140: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800144: sb          $v0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r2;
    // 0x80800148: lw          $t7, 0x34($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X34);
    // 0x8080014C: addiu       $t8, $zero, 0x1F40
    ctx->r24 = ADD32(0, 0X1F40);
    // 0x80800150: addiu       $a1, $zero, 0x49B
    ctx->r5 = ADD32(0, 0X49B);
    // 0x80800154: swc1        $f4, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f4.u32l;
    // 0x80800158: lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X34);
    // 0x8080015C: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80800160: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
    // 0x80800164: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
    // 0x80800168: sw          $t8, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r24;
    // 0x8080016C: lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X34);
    // 0x80800170: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
    // 0x80800174: sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
    // 0x80800178: lw          $t1, 0x34($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X34);
    // 0x8080017C: jal         0x800C301C
    // 0x80800180: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    func_800C301C(rdram, ctx);
        goto after_1;
    // 0x80800180: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    after_1:
    // 0x80800184: lw          $t2, 0x34($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X34);
    // 0x80800188: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080018C: jal         0x800C330C
    // 0x80800190: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    func_800C330C(rdram, ctx);
        goto after_2;
    // 0x80800190: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    after_2:
    // 0x80800194: lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X34);
    // 0x80800198: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x8080019C: jal         0x800C31DC
    // 0x808001A0: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    func_800C31DC(rdram, ctx);
        goto after_3;
    // 0x808001A0: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    after_3:
    // 0x808001A4: lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X34);
    // 0x808001A8: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x808001AC: jal         0x800C3058
    // 0x808001B0: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    func_800C3058(rdram, ctx);
        goto after_4;
    // 0x808001B0: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    after_4:
    // 0x808001B4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808001B8: lw          $t3, 0x34($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X34);
    // 0x808001BC: swc1        $f8, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->f8.u32l;
    // 0x808001C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001CC: jr          $ra
    // 0x808001D0: nop

    return;
    // 0x808001D0: nop

;}
RECOMP_FUNC void func_80800000_bsbbilldrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: sw          $zero, 0x168($a0)
    MEM_W(0X168, ctx->r4) = 0;
    return;
    // 0x80800004: sw          $zero, 0x168($a0)
    MEM_W(0X168, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80800178_chtempleinternaldoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800178: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080017C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800180: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80800184: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80800188: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2188, 0X208) << 16);
    // 0x8080018C: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80800190: addiu       $v0, $t6, -0x32
    ctx->r2 = ADD32(ctx->r14, -0X32);
    // 0x80800194: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80800198: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x8080019C: lhu         $a1, 0x208($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(2188, 0X208));
    // 0x808001A0: jal         0x80103140
    // 0x808001A4: lhu         $a2, 0x16($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X16);
    func_80103140(rdram, ctx);
        goto after_0;
    // 0x808001A4: lhu         $a2, 0x16($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X16);
    after_0:
    // 0x808001A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001B0: jr          $ra
    // 0x808001B4: nop

    return;
    // 0x808001B4: nop

    // 0x808001B8: nop

    // 0x808001BC: nop

;}
RECOMP_FUNC void func_80800C64_chcheato(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800C6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C70: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800C74: jal         0x80088078
    // 0x80800C78: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    _gcdialogcamera_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800C78: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80800C7C: beq         $v0, $zero, L_80800CAC
    if (ctx->r2 == 0) {
        // 0x80800C80: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800CAC;
    }
    // 0x80800C80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800C84: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80800C88: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800C8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800C90: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800C94: beq         $t7, $at, L_80800CA4
    if (ctx->r15 == ctx->r1) {
        // 0x80800C98: nop
    
            goto L_80800CA4;
    }
    // 0x80800C98: nop

    // 0x80800C9C: jal         0x80800D08
    // 0x80800CA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800D08_chcheato(rdram, ctx);
        goto after_1;
    // 0x80800CA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_80800CA4:
    // 0x80800CA4: b           L_80800CB0
    // 0x80800CA8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800CB0;
    // 0x80800CA8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800CAC:
    // 0x80800CAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CB0:
    // 0x80800CB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800CB8: jr          $ra
    // 0x80800CBC: nop

    return;
    // 0x80800CBC: nop

;}
RECOMP_FUNC void func_80091F74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091F74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091F78: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80091F7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091F80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80091F84: bne         $a1, $at, L_80091FC4
    if (ctx->r5 != ctx->r1) {
        // 0x80091F88: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80091FC4;
    }
    // 0x80091F88: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80091F8C: jal         0x800F8B70
    // 0x80091F90: nop

    func_800F8B70(rdram, ctx);
        goto after_0;
    // 0x80091F90: nop

    after_0:
    // 0x80091F94: bnel        $v0, $zero, L_80091FD8
    if (ctx->r2 != 0) {
        // 0x80091F98: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80091FD8;
    }
    goto skip_0;
    // 0x80091F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80091F9C: jal         0x800F9104
    // 0x80091FA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800F9104(rdram, ctx);
        goto after_1;
    // 0x80091FA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80091FA4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80091FA8: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x80091FAC: jal         0x80101238
    // 0x80091FB0: lw          $a1, 0x184($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X184);
    func_80101238(rdram, ctx);
        goto after_2;
    // 0x80091FB0: lw          $a1, 0x184($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X184);
    after_2:
    // 0x80091FB4: bnel        $v0, $zero, L_80091FC8
    if (ctx->r2 != 0) {
        // 0x80091FB8: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_80091FC8;
    }
    goto skip_1;
    // 0x80091FB8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x80091FBC: jal         0x800A05DC
    // 0x80091FC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A05DC(rdram, ctx);
        goto after_3;
    // 0x80091FC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
L_80091FC4:
    // 0x80091FC4: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
L_80091FC8:
    // 0x80091FC8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80091FCC: lw          $t0, 0x4C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4C);
    // 0x80091FD0: sb          $t8, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r24;
    // 0x80091FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80091FD8:
    // 0x80091FD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091FDC: jr          $ra
    // 0x80091FE0: nop

    return;
    // 0x80091FE0: nop

;}
RECOMP_FUNC void func_8080119C_chdinofamilymother(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080119C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808011A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808011A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808011A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808011AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808011B0: lw          $v0, 0x34($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X34);
    // 0x808011B4: ori         $a2, $a3, 0x10
    ctx->r6 = ctx->r7 | 0X10;
    // 0x808011B8: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    // 0x808011BC: beq         $v0, $zero, L_808011E0
    if (ctx->r2 == 0) {
        // 0x808011C0: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_808011E0;
    }
    // 0x808011C0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808011C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808011C8: beq         $v0, $at, L_8080120C
    if (ctx->r2 == ctx->r1) {
        // 0x808011CC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080120C;
    }
    // 0x808011CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808011D0: beq         $v0, $at, L_808011E8
    if (ctx->r2 == ctx->r1) {
        // 0x808011D4: nop
    
            goto L_808011E8;
    }
    // 0x808011D4: nop

    // 0x808011D8: b           L_8080121C
    // 0x808011DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080121C;
    // 0x808011DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808011E0:
    // 0x808011E0: jal         0x800856B0
    // 0x808011E4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808011E4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_0:
L_808011E8:
    // 0x808011E8: jal         0x800856E0
    // 0x808011EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x808011EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x808011F0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x808011F4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808011F8: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
    // 0x808011FC: jal         0x800880A8
    // 0x80801200: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    _gcdialogcamera_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80801200: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_2:
    // 0x80801204: jal         0x800880B8
    // 0x80801208: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x80801208: nop

    after_3:
L_8080120C:
    // 0x8080120C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80801210: jal         0x800856D8
    // 0x80801214: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x80801214: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80801218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080121C:
    // 0x8080121C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801220: jr          $ra
    // 0x80801224: nop

    return;
    // 0x80801224: nop

;}
RECOMP_FUNC void func_80803B50_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803B50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80803B54: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80803B58: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80803B5C: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80803B60: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803B64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803B68: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80803B6C: beq         $t6, $at, L_80803B9C
    if (ctx->r14 == ctx->r1) {
        // 0x80803B70: lui         $a2, 0x3E99
        ctx->r6 = S32(0X3E99 << 16);
            goto L_80803B9C;
    }
    // 0x80803B70: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80803B74: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80803B78: beq         $t6, $at, L_80803BD8
    if (ctx->r14 == ctx->r1) {
        // 0x80803B7C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80803BD8;
    }
    // 0x80803B7C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80803B80: beq         $t6, $at, L_80803C28
    if (ctx->r14 == ctx->r1) {
        // 0x80803B84: lui         $a2, 0x3E4C
        ctx->r6 = S32(0X3E4C << 16);
            goto L_80803C28;
    }
    // 0x80803B84: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80803B88: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80803B8C: beq         $t6, $at, L_80803C6C
    if (ctx->r14 == ctx->r1) {
        // 0x80803B90: nop
    
            goto L_80803C6C;
    }
    // 0x80803B90: nop

    // 0x80803B94: b           L_80803C78
    // 0x80803B98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803C78;
    // 0x80803B98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803B9C:
    // 0x80803B9C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80803BA0: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80803BA4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80803BA8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80803BAC: jal         0x800F10B4
    // 0x80803BB0: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x80803BB0: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80803BB4: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80803BB8: jal         0x800D9078
    // 0x80803BBC: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x80803BBC: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_1:
    // 0x80803BC0: beq         $v0, $zero, L_80803C74
    if (ctx->r2 == 0) {
        // 0x80803BC4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803C74;
    }
    // 0x80803BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803BC8: jal         0x80803A24
    // 0x80803BCC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80803A24_chevilmumbo(rdram, ctx);
        goto after_2;
    // 0x80803BCC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80803BD0: b           L_80803C78
    // 0x80803BD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803C78;
    // 0x80803BD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803BD8:
    // 0x80803BD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803BDC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80803BE0: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80803BE4: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80803BE8: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80803BEC: nop

    // 0x80803BF0: bc1fl       L_80803C08
    if (!c1cs) {
        // 0x80803BF4: swc1        $f0, 0x38($s0)
        MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
            goto L_80803C08;
    }
    goto skip_0;
    // 0x80803BF4: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    skip_0:
    // 0x80803BF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80803BFC: b           L_80803C08
    // 0x80803C00: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
        goto L_80803C08;
    // 0x80803C00: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
    // 0x80803C04: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
L_80803C08:
    // 0x80803C08: jal         0x800D9078
    // 0x80803C0C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800D9078(rdram, ctx);
        goto after_3;
    // 0x80803C0C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_3:
    // 0x80803C10: beq         $v0, $zero, L_80803C74
    if (ctx->r2 == 0) {
        // 0x80803C14: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803C74;
    }
    // 0x80803C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803C18: jal         0x80803A24
    // 0x80803C1C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80803A24_chevilmumbo(rdram, ctx);
        goto after_4;
    // 0x80803C1C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x80803C20: b           L_80803C78
    // 0x80803C24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803C78;
    // 0x80803C24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803C28:
    // 0x80803C28: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80803C2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803C30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80803C34: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80803C38: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80803C3C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80803C40: jal         0x800F10B4
    // 0x80803C44: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x80803C44: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x80803C48: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80803C4C: jal         0x800D9078
    // 0x80803C50: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800D9078(rdram, ctx);
        goto after_6;
    // 0x80803C50: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_6:
    // 0x80803C54: beq         $v0, $zero, L_80803C74
    if (ctx->r2 == 0) {
        // 0x80803C58: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803C74;
    }
    // 0x80803C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803C5C: jal         0x80803A24
    // 0x80803C60: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80803A24_chevilmumbo(rdram, ctx);
        goto after_7;
    // 0x80803C60: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_7:
    // 0x80803C64: b           L_80803C78
    // 0x80803C68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803C78;
    // 0x80803C68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803C6C:
    // 0x80803C6C: jal         0x800FFAB0
    // 0x80803C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_8;
    // 0x80803C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_80803C74:
    // 0x80803C74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803C78:
    // 0x80803C78: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80803C7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80803C80: jr          $ra
    // 0x80803C84: nop

    return;
    // 0x80803C84: nop

;}
RECOMP_FUNC void _sumole_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089A50: syscall     800
    recomp_syscall_handler(rdram, ctx, 0x80089A50);
    return;
    // 0x80089A54: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void func_800C6320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6320: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800C6324: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C6328: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C632C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C6330: addiu       $a1, $s0, 0x4C
    ctx->r5 = ADD32(ctx->r16, 0X4C);
    // 0x800C6334: jal         0x800EE7F8
    // 0x800C6338: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800C6338: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x800C633C: lw          $a3, 0x84($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X84);
    // 0x800C6340: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x800C6344: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x800C6348: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x800C634C: lui         $a2, 0xC4A2
    ctx->r6 = S32(0XC4A2 << 16);
    // 0x800C6350: addiu       $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
    // 0x800C6354: or          $t6, $a3, $at
    ctx->r14 = ctx->r7 | ctx->r1;
    // 0x800C6358: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x800C635C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800C6360: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x800C6364: jal         0x800C5CC0
    // 0x800C6368: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800C5CC0(rdram, ctx);
        goto after_1;
    // 0x800C6368: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x800C636C: beq         $v0, $zero, L_800C6398
    if (ctx->r2 == 0) {
        // 0x800C6370: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C6398;
    }
    // 0x800C6370: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C6374: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C6378: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C637C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C6380: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800C6384: nop

    // 0x800C6388: bc1fl       L_800C639C
    if (!c1cs) {
        // 0x800C638C: lwc1        $f8, 0x74($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
            goto L_800C639C;
    }
    goto skip_0;
    // 0x800C638C: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    skip_0:
    // 0x800C6390: jal         0x800C5F40
    // 0x800C6394: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800C5F40(rdram, ctx);
        goto after_2;
    // 0x800C6394: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_2:
L_800C6398:
    // 0x800C6398: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
L_800C639C:
    // 0x800C639C: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C63A0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800C63A4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800C63A8: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800C63AC: lw          $a3, 0x88($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X88);
    // 0x800C63B0: addiu       $t8, $sp, 0x44
    ctx->r24 = ADD32(ctx->r29, 0X44);
    // 0x800C63B4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800C63B8: add.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C63BC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800C63C0: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800C63C4: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800C63C8: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800C63CC: jal         0x800C5CC0
    // 0x800C63D0: nop

    func_800C5CC0(rdram, ctx);
        goto after_3;
    // 0x800C63D0: nop

    after_3:
    // 0x800C63D4: bne         $v0, $zero, L_800C63E4
    if (ctx->r2 != 0) {
        // 0x800C63D8: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C63E4;
    }
    // 0x800C63D8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C63DC: lbu         $t9, 0x9C($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X9C);
    // 0x800C63E0: beq         $t9, $zero, L_800C63F0
    if (ctx->r25 == 0) {
        // 0x800C63E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C63F0;
    }
L_800C63E4:
    // 0x800C63E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C63E8: jal         0x800C5FCC
    // 0x800C63EC: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    func_800C5FCC(rdram, ctx);
        goto after_4;
    // 0x800C63EC: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_4:
L_800C63F0:
    // 0x800C63F0: jal         0x800C5E14
    // 0x800C63F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C5E14(rdram, ctx);
        goto after_5;
    // 0x800C63F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800C63F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800C63FC: beq         $v0, $at, L_800C640C
    if (ctx->r2 == ctx->r1) {
        // 0x800C6400: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800C640C;
    }
    // 0x800C6400: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800C6404: jal         0x800C5A10
    // 0x800C6408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C5A10(rdram, ctx);
        goto after_6;
    // 0x800C6408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_800C640C:
    // 0x800C640C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C6410: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C6414: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800C6418: jr          $ra
    // 0x800C641C: nop

    return;
    // 0x800C641C: nop

;}
RECOMP_FUNC void func_80800000_chwaspstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x800DA298
    // 0x80800010: addiu       $a0, $zero, 0x35A
    ctx->r4 = ADD32(0, 0X35A);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a0, $zero, 0x35A
    ctx->r4 = ADD32(0, 0X35A);
    after_0:
    // 0x80800014: beq         $v0, $zero, L_80800024
    if (ctx->r2 == 0) {
        // 0x80800018: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80800024;
    }
    // 0x80800018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080001C: b           L_80800024
    // 0x80800020: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
        goto L_80800024;
    // 0x80800020: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
L_80800024:
    // 0x80800024: jal         0x80800134
    // 0x80800028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800134_chwaspstatue(rdram, ctx);
        goto after_1;
    // 0x80800028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
RECOMP_FUNC void bsvanswim_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800418: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080041C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(431, 0X980) << 16);
    // 0x80800420: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800424: jr          $ra
    // 0x80800428: lw          $v0, 0x980($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(431, 0X980));
    return;
    // 0x80800428: lw          $v0, 0x980($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(431, 0X980));
;}
RECOMP_FUNC void func_80800DB4_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800DB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800DC0: jal         0x80100094
    // 0x80800DC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800DC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800DC8: beq         $v0, $zero, L_80800DD8
    if (ctx->r2 == 0) {
        // 0x80800DCC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800DD8;
    }
    // 0x80800DCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800DD0: jal         0x800897C8
    // 0x80800DD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800DD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_80800DD8:
    // 0x80800DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DE0: jr          $ra
    // 0x80800DE4: nop

    return;
    // 0x80800DE4: nop

    // 0x80800DE8: nop

    // 0x80800DEC: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082C68: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082C68);
    return;
    // 0x80082C6C: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void bstrexlarge_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801928: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080192C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(412, 0X1A40) << 16);
    // 0x80801930: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801934: jr          $ra
    // 0x80801938: lw          $v0, 0x1A40($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(412, 0X1A40));
    return;
    // 0x80801938: lw          $v0, 0x1A40($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(412, 0X1A40));
    // 0x8080193C: nop

;}
RECOMP_FUNC void _chfairgroundworker_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085C68: syscall     215
    recomp_syscall_handler(rdram, ctx, 0x80085C68);
    return;
    // 0x80085C6C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80803320_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803320: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803324: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803328: jal         0x80807C8C
    // 0x8080332C: nop

    func_80807C8C_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x8080332C: nop

    after_0:
    // 0x80803330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803334: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803338: jr          $ra
    // 0x8080333C: nop

    return;
    // 0x8080333C: nop

;}
RECOMP_FUNC void sumumbofx_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801360: jr          $ra
    // 0x80801364: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    return;
    // 0x80801364: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
;}
RECOMP_FUNC void _bsdie_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082FB8: syscall     37
    recomp_syscall_handler(rdram, ctx, 0x80082FB8);
    return;
    // 0x80082FBC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800F5268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5268: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F526C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5270: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5278: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F527C: jal         0x80084C98
    // 0x800F5280: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    _bafpctrl_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x800F5280: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5284: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800F5288: beq         $v0, $at, L_800F5298
    if (ctx->r2 == ctx->r1) {
        // 0x800F528C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F5298;
    }
    // 0x800F528C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5290: b           L_800F52B0
    // 0x800F5294: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F52B0;
    // 0x800F5294: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F5298:
    // 0x800F5298: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x800F529C: addiu       $t7, $t7, 0x4CA0
    ctx->r15 = ADD32(ctx->r15, 0X4CA0);
    // 0x800F52A0: beq         $t7, $zero, L_800F52B0
    if (ctx->r15 == 0) {
        // 0x800F52A4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F52B0;
    }
    // 0x800F52A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F52A8: b           L_800F52B0
    // 0x800F52AC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800F52B0;
    // 0x800F52AC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800F52B0:
    // 0x800F52B0: jr          $ra
    // 0x800F52B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F52B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80801FA4_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801FA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801FA8: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80801FAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801FB0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801FB4: beq         $a1, $at, L_80802024
    if (ctx->r5 == ctx->r1) {
        // 0x80801FB8: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80802024;
    }
    // 0x80801FB8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80801FBC: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80801FC0: beq         $a1, $at, L_80802034
    if (ctx->r5 == ctx->r1) {
        // 0x80801FC4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80802034;
    }
    // 0x80801FC4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801FC8: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80801FCC: bne         $a1, $at, L_80802044
    if (ctx->r5 != ctx->r1) {
        // 0x80801FD0: addiu       $a0, $zero, 0x95
        ctx->r4 = ADD32(0, 0X95);
            goto L_80802044;
    }
    // 0x80801FD0: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    // 0x80801FD4: jal         0x800DA298
    // 0x80801FD8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80801FD8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80801FDC: beq         $v0, $zero, L_80801FEC
    if (ctx->r2 == 0) {
        // 0x80801FE0: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_80801FEC;
    }
    // 0x80801FE0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80801FE4: b           L_80801FF0
    // 0x80801FE8: addiu       $v0, $zero, 0x87A
    ctx->r2 = ADD32(0, 0X87A);
        goto L_80801FF0;
    // 0x80801FE8: addiu       $v0, $zero, 0x87A
    ctx->r2 = ADD32(0, 0X87A);
L_80801FEC:
    // 0x80801FEC: addiu       $v0, $zero, 0x879
    ctx->r2 = ADD32(0, 0X879);
L_80801FF0:
    // 0x80801FF0: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80801FF4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801FF8: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x80801FFC: lhu         $a2, 0x16($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X16);
    // 0x80802000: jal         0x80103140
    // 0x80802004: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80103140(rdram, ctx);
        goto after_1;
    // 0x80802004: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x80802008: jal         0x800DA298
    // 0x8080200C: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x8080200C: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    after_2:
    // 0x80802010: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802014: jal         0x8010A5B0
    // 0x80802018: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8010A5B0(rdram, ctx);
        goto after_3;
    // 0x80802018: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8080201C: b           L_80802050
    // 0x80802020: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802050;
    // 0x80802020: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802024:
    // 0x80802024: lbu         $t7, 0x74($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X74);
    // 0x80802028: andi        $t8, $t7, 0xFFBF
    ctx->r24 = ctx->r15 & 0XFFBF;
    // 0x8080202C: b           L_8080204C
    // 0x80802030: sb          $t8, 0x74($a3)
    MEM_B(0X74, ctx->r7) = ctx->r24;
        goto L_8080204C;
    // 0x80802030: sb          $t8, 0x74($a3)
    MEM_B(0X74, ctx->r7) = ctx->r24;
L_80802034:
    // 0x80802034: jal         0x80802060
    // 0x80802038: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80802060_chchuffy(rdram, ctx);
        goto after_4;
    // 0x80802038: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x8080203C: b           L_80802050
    // 0x80802040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802050;
    // 0x80802040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802044:
    // 0x80802044: b           L_80802050
    // 0x80802048: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802050;
    // 0x80802048: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080204C:
    // 0x8080204C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802050:
    // 0x80802050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802058: jr          $ra
    // 0x8080205C: nop

    return;
    // 0x8080205C: nop

;}
RECOMP_FUNC void func_808002A4_chjadestatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808002B0: jal         0x800D035C
    // 0x808002B4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800D035C(rdram, ctx);
        goto after_0;
    // 0x808002B4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x808002B8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808002BC: addiu       $a0, $zero, 0xEE
    ctx->r4 = ADD32(0, 0XEE);
    // 0x808002C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808002C4: jal         0x800D24E8
    // 0x808002C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D24E8(rdram, ctx);
        goto after_1;
    // 0x808002C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x808002CC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808002D0: addiu       $a0, $zero, 0x2B3
    ctx->r4 = ADD32(0, 0X2B3);
    // 0x808002D4: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x808002D8: slti        $at, $t6, 0x14
    ctx->r1 = SIGNED(ctx->r14) < 0X14 ? 1 : 0;
    // 0x808002DC: bnel        $at, $zero, L_808002F8
    if (ctx->r1 != 0) {
        // 0x808002E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002F8;
    }
    goto skip_0;
    // 0x808002E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808002E4: jal         0x80101180
    // 0x808002E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_2;
    // 0x808002E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x808002EC: jal         0x800FFAB0
    // 0x808002F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x808002F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808002F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002F8:
    // 0x808002F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002FC: jr          $ra
    // 0x80800300: nop

    return;
    // 0x80800300: nop

;}
RECOMP_FUNC void _chminisubgame_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085B88: syscall     202
    recomp_syscall_handler(rdram, ctx, 0x80085B88);
    return;
    // 0x80085B8C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80802620_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802620: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802628: jal         0x80087AE0
    // 0x8080262C: lw          $a0, 0x28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X28);
    _gczoombox_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080262C: lw          $a0, 0x28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X28);
    after_0:
    // 0x80802630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802634: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802638: jr          $ra
    // 0x8080263C: nop

    return;
    // 0x8080263C: nop

;}
RECOMP_FUNC void _idwave_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088D20: syscall     736
    recomp_syscall_handler(rdram, ctx, 0x80088D20);
    return;
    // 0x80088D24: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800BB0_chfriesstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BB0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800BB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800BB8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800BBC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800BC0: addiu       $a0, $zero, 0x32E
    ctx->r4 = ADD32(0, 0X32E);
    // 0x80800BC4: jal         0x801084B0
    // 0x80800BC8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_801084B0(rdram, ctx);
        goto after_0;
    // 0x80800BC8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x80800BCC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800BD0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800BD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800BD8: jal         0x80102FDC
    // 0x80800BDC: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    func_80102FDC(rdram, ctx);
        goto after_1;
    // 0x80800BDC: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    after_1:
    // 0x80800BE0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800BE4: jal         0x80089CD8
    // 0x80800BE8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    _subaddiefade_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800BE8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x80800BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BF0: jal         0x80089CE8
    // 0x80800BF4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    _subaddiefade_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x80800BF4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x80800BF8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80800BFC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80800C00: sw          $t7, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->r15;
    // 0x80800C04: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80800C08: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x80800C0C: lhu         $t1, 0x64($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X64);
    // 0x80800C10: andi        $t4, $t3, 0xFFFE
    ctx->r12 = ctx->r11 & 0XFFFE;
    // 0x80800C14: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80800C18: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80800C1C: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    // 0x80800C20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800C28: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800C2C: jr          $ra
    // 0x80800C30: nop

    return;
    // 0x80800C30: nop

;}
RECOMP_FUNC void bssplitup_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800118: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080011C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(364, 0X700) << 16);
    // 0x80800120: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800124: jr          $ra
    // 0x80800128: lw          $v0, 0x700($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(364, 0X700));
    return;
    // 0x80800128: lw          $v0, 0x700($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(364, 0X700));
;}
RECOMP_FUNC void func_808004D8_chstatuebossbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808004DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004E0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808004E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004EC: beq         $a1, $at, L_80800580
    if (ctx->r5 == ctx->r1) {
        // 0x808004F0: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_80800580;
    }
    // 0x808004F0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808004F4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808004F8: beq         $a1, $at, L_80800510
    if (ctx->r5 == ctx->r1) {
        // 0x808004FC: addiu       $at, $zero, 0x90
        ctx->r1 = ADD32(0, 0X90);
            goto L_80800510;
    }
    // 0x808004FC: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800500: beq         $a1, $at, L_808005A8
    if (ctx->r5 == ctx->r1) {
        // 0x80800504: nop
    
            goto L_808005A8;
    }
    // 0x80800504: nop

    // 0x80800508: b           L_808005F0
    // 0x8080050C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005F0;
    // 0x8080050C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800510:
    // 0x80800510: lw          $t6, 0x54($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X54);
    // 0x80800514: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80800518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080051C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80800520: sw          $t7, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r15;
    // 0x80800524: jal         0x80800604
    // 0x80800528: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80800604_chstatuebossbits(rdram, ctx);
        goto after_0;
    // 0x80800528: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080052C: lw          $t8, 0x54($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X54);
    // 0x80800530: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800534: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800538: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x8080053C: bne         $at, $zero, L_808005EC
    if (ctx->r1 != 0) {
        // 0x80800540: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_808005EC;
    }
    // 0x80800540: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800544: jal         0x800EC398
    // 0x80800548: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800EC398(rdram, ctx);
        goto after_1;
    // 0x80800548: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_1:
    // 0x8080054C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800550: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800558: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8080055C: jal         0x80086670
    // 0x80800560: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800560: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x80800564: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1424, 0X85C) << 16);
    // 0x80800568: addiu       $a2, $a2, 0x85C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1424, 0X85C));
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800570: jal         0x80089D18
    // 0x80800574: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800574: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80800578: b           L_808005F0
    // 0x8080057C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005F0;
    // 0x8080057C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800580:
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800584: jal         0x80101FDC
    // 0x80800588: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80800588: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800590: jal         0x80103110
    // 0x80800594: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_5;
    // 0x80800594: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800598: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8080059C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005A0: b           L_808005EC
    // 0x808005A4: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_808005EC;
    // 0x808005A4: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_808005A8:
    // 0x808005A8: jal         0x80101080
    // 0x808005AC: nop

    func_80101080(rdram, ctx);
        goto after_6;
    // 0x808005AC: nop

    after_6:
    // 0x808005B0: jal         0x80106790
    // 0x808005B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_7;
    // 0x808005B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x808005B8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808005BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808005C4: jal         0x800866A0
    // 0x808005C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_8;
    // 0x808005C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808005D4: jal         0x800866A0
    // 0x808005D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_9;
    // 0x808005D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x808005DC: b           L_808005F0
    // 0x808005E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005F0;
    // 0x808005E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808005E4: b           L_808005F0
    // 0x808005E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005F0;
    // 0x808005E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005EC:
    // 0x808005EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005F0:
    // 0x808005F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808005FC: jr          $ra
    // 0x80800600: nop

    return;
    // 0x80800600: nop

;}
