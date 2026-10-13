#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80801870_chpotogoldgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801874: andi        $t6, $a3, 0x1
    ctx->r14 = ctx->r7 & 0X1;
    // 0x80801878: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8080187C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801880: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801884: or          $a1, $t7, $a1
    ctx->r5 = ctx->r15 | ctx->r5;
    // 0x80801888: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080188C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801890: jal         0x800BEA88
    // 0x80801894: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_0;
    // 0x80801894: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80801898: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8080189C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x808018A0: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x808018A4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x808018A8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x808018AC: subu        $a1, $t9, $t0
    ctx->r5 = SUB32(ctx->r25, ctx->r8);
    // 0x808018B0: addiu       $a1, $a1, 0x5
    ctx->r5 = ADD32(ctx->r5, 0X5);
    // 0x808018B4: addiu       $a2, $a2, 0x75B0
    ctx->r6 = ADD32(ctx->r6, 0X75B0);
    // 0x808018B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808018BC: jal         0x80088660
    // 0x808018C0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    _glid_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808018C0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x808018C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808018C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808018CC: jr          $ra
    // 0x808018D0: nop

    return;
    // 0x808018D0: nop

;}
RECOMP_FUNC void _chpoolkids_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800860E8: syscall     278
    recomp_syscall_handler(rdram, ctx, 0x800860E8);
    return;
    // 0x800860EC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bskazeggass_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800258: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080025C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800260: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800264: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800268: jal         0x80098140
    // 0x8080026C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    bainput_enable(rdram, ctx);
        goto after_0;
    // 0x8080026C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80800270: jal         0x8009BC6C
    // 0x80800274: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baphysics_reset_gravity(rdram, ctx);
        goto after_1;
    // 0x80800274: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800278: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080027C: jal         0x800A0CDC
    // 0x80800280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CDC(rdram, ctx);
        goto after_2;
    // 0x80800280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800284: jal         0x800832E8
    // 0x80800288: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800288: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8080028C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800294: jr          $ra
    // 0x80800298: nop

    return;
    // 0x80800298: nop

;}
RECOMP_FUNC void func_8009AC6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009AC6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009AC70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009AC74: lw          $t6, 0xC0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC0);
    // 0x8009AC78: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8009AC7C: sw          $zero, 0x18($t6)
    MEM_W(0X18, ctx->r14) = 0;
    // 0x8009AC80: lw          $t7, 0xC0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC0);
    // 0x8009AC84: sw          $zero, 0x14($t7)
    MEM_W(0X14, ctx->r15) = 0;
    // 0x8009AC88: lw          $a0, 0xC0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC0);
    // 0x8009AC8C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8009AC90: jal         0x800EFD24
    // 0x8009AC94: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x8009AC94: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x8009AC98: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8009AC9C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8009ACA0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8009ACA4: lw          $t8, 0xC0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XC0);
    // 0x8009ACA8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8009ACAC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8009ACB0: sw          $zero, 0x4C($t8)
    MEM_W(0X4C, ctx->r24) = 0;
    // 0x8009ACB4: lw          $t9, 0xC0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC0);
    // 0x8009ACB8: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x8009ACBC: sw          $zero, 0x4C($t0)
    MEM_W(0X4C, ctx->r8) = 0;
    // 0x8009ACC0: lw          $t1, 0xC0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0XC0);
    // 0x8009ACC4: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8009ACC8: sw          $zero, 0x74($t2)
    MEM_W(0X74, ctx->r10) = 0;
    // 0x8009ACCC: lw          $t3, 0xC0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XC0);
    // 0x8009ACD0: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8009ACD4: sw          $zero, 0x9C($t4)
    MEM_W(0X9C, ctx->r12) = 0;
    // 0x8009ACD8: lw          $t5, 0xC0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0XC0);
    // 0x8009ACDC: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8009ACE0: sw          $zero, 0xC4($t6)
    MEM_W(0XC4, ctx->r14) = 0;
    // 0x8009ACE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009ACE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009ACEC: jr          $ra
    // 0x8009ACF0: nop

    return;
    // 0x8009ACF0: nop

;}
RECOMP_FUNC void func_800AADE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AADE4: jr          $ra
    // 0x800AADE8: lhu         $v0, 0x14($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X14);
    return;
    // 0x800AADE8: lhu         $v0, 0x14($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X14);
;}
RECOMP_FUNC void gsmaker_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800318: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080031C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800320: jal         0x8080038C
    // 0x80800324: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    gsmaker_entrypoint_13(rdram, ctx);
        goto after_0;
    // 0x80800324: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80800328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080032C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800330: jr          $ra
    // 0x80800334: nop

    return;
    // 0x80800334: nop

;}
RECOMP_FUNC void func_808043D8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808043D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808043DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808043E0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808043E4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808043E8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808043EC: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x808043F0: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x808043F4: jal         0x8008A0E0
    // 0x808043F8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808043F8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_0:
    // 0x808043FC: beql        $v0, $zero, L_80804444
    if (ctx->r2 == 0) {
        // 0x80804400: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80804444;
    }
    goto skip_0;
    // 0x80804400: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80804404: jal         0x800B53A4
    // 0x80804408: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800B53A4(rdram, ctx);
        goto after_1;
    // 0x80804408: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8080440C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80804410: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80804414: jal         0x800BAB80
    // 0x80804418: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800BAB80(rdram, ctx);
        goto after_2;
    // 0x80804418: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x8080441C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80804420: lui         $t7, 0x8081
    ctx->r15 = S32(RELOC_HI16(1480, 0X9FE0) << 16);
    // 0x80804424: addiu       $t7, $t7, -0x6020
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1480, 0X9FE0));
    // 0x80804428: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080442C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80804430: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80804434: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80804438: jal         0x800BABB8
    // 0x8080443C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x8080443C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_3:
    // 0x80804440: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804444:
    // 0x80804444: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80804448: jr          $ra
    // 0x8080444C: nop

    return;
    // 0x8080444C: nop

;}
RECOMP_FUNC void chexploder_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801604: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801608: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8080160C: jal         0x800EE88C
    // 0x80801610: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EE88C(rdram, ctx);
        goto after_0;
    // 0x80801610: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80801614: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801618: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8080161C: jal         0x80801578
    // 0x80801620: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    chexploder_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80801620: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80801624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801628: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080162C: jr          $ra
    // 0x80801630: nop

    return;
    // 0x80801630: nop

;}
RECOMP_FUNC void bskazjump_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800834: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800838: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(256, 0XC50) << 16);
    // 0x8080083C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800840: jr          $ra
    // 0x80800844: lw          $v0, 0xC50($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(256, 0XC50));
    return;
    // 0x80800844: lw          $v0, 0xC50($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(256, 0XC50));
;}
RECOMP_FUNC void func_80013538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013538: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x8001353C: jr          $ra
    // 0x80013540: lw          $v0, 0x73E0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X73E0);
    return;
    // 0x80013540: lw          $v0, 0x73E0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X73E0);
;}
RECOMP_FUNC void _bsbansnooze_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082748: syscall     9
    recomp_syscall_handler(rdram, ctx, 0x80082748);
    return;
    // 0x8008274C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bsbtrot_entrypoint_37(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080231C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802320: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802324: jal         0x80082FE8
    // 0x80802328: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80802328: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080232C: jal         0x808004B4
    // 0x80802330: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808004B4_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x80802330: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80802334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080233C: jr          $ra
    // 0x80802340: nop

    return;
    // 0x80802340: nop

;}
RECOMP_FUNC void func_808004C4_chgruntyfireballbig(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004C4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808004C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808004D0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808004D4: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x808004D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1500, 0X670) << 16);
    // 0x808004DC: lwc1        $f6, 0x670($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1500, 0X670));
    // 0x808004E0: lwc1        $f4, 0x38($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X38);
    // 0x808004E4: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1500, 0X788) << 16);
    // 0x808004E8: addiu       $t7, $t7, 0x788
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1500, 0X788));
    // 0x808004EC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808004F0: addiu       $s0, $a0, 0x4
    ctx->r16 = ADD32(ctx->r4, 0X4);
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808004FC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800500: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800504: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800508: jal         0x800BBCB8
    // 0x8080050C: nop

    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x8080050C: nop

    after_0:
    // 0x80800510: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80800514: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800518: jal         0x800EE7F8
    // 0x8080051C: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8080051C: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_1:
    // 0x80800520: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800524: jal         0x800EF368
    // 0x80800528: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    func_800EF368(rdram, ctx);
        goto after_2;
    // 0x80800528: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    after_2:
    // 0x8080052C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800530: jal         0x800EF334
    // 0x80800534: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    func_800EF334(rdram, ctx);
        goto after_3;
    // 0x80800534: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    after_3:
    // 0x80800538: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8080053C: jal         0x800EF04C
    // 0x80800540: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_4;
    // 0x80800540: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x80800544: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80800548: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1500, 0X674) << 16);
    // 0x8080054C: lwc1        $f16, 0x674($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1500, 0X674));
    // 0x80800550: lwc1        $f10, 0x38($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X38);
    // 0x80800554: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1500, 0X754) << 16);
    // 0x80800558: addiu       $t9, $t9, 0x754
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1500, 0X754));
    // 0x8080055C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800560: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800564: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800568: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080056C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800570: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800574: jal         0x800BBCB8
    // 0x80800578: nop

    func_800BBCB8(rdram, ctx);
        goto after_5;
    // 0x80800578: nop

    after_5:
    // 0x8080057C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800580: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800584: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800588: jr          $ra
    // 0x8080058C: nop

    return;
    // 0x8080058C: nop

;}
RECOMP_FUNC void func_800A9F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9F30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A9F34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9F38: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800A9F3C: jal         0x8001BDAC
    // 0x800A9F40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8001BDAC(rdram, ctx);
        goto after_0;
    // 0x800A9F40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800A9F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A9F48: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A9F4C: lw          $t6, 0x7770($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7770);
    // 0x800A9F50: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800A9F54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A9F58: jr          $ra
    // 0x800A9F5C: slt         $v0, $t6, $t7
    ctx->r2 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    return;
    // 0x800A9F5C: slt         $v0, $t6, $t7
    ctx->r2 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
;}
RECOMP_FUNC void _bssilowait_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083A10: syscall     86
    recomp_syscall_handler(rdram, ctx, 0x80083A10);
    return;
    // 0x80083A14: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void gspropctrl_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D4: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x808000D8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x808000DC: nop

    // 0x808000E0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808000E4: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x808000E8: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x808000EC: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x808000F0: nop

    // 0x808000F4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808000F8: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
    // 0x808000FC: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x80800100: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80800104: nop

    // 0x80800108: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8080010C: jr          $ra
    // 0x80800110: swc1        $f18, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f18.u32l;
    return;
    // 0x80800110: swc1        $f18, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_800A5C94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5C94: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A5C98: lbu         $t6, 0x7115($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7115);
    // 0x800A5C9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5CA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5CA4: beql        $t6, $zero, L_800A5CB8
    if (ctx->r14 == 0) {
        // 0x800A5CA8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A5CB8;
    }
    goto skip_0;
    // 0x800A5CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A5CAC: jal         0x801002C0
    // 0x800A5CB0: nop

    func_801002C0(rdram, ctx);
        goto after_0;
    // 0x800A5CB0: nop

    after_0:
    // 0x800A5CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A5CB8:
    // 0x800A5CB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5CBC: jr          $ra
    // 0x800A5CC0: nop

    return;
    // 0x800A5CC0: nop

;}
RECOMP_FUNC void func_808002A8_cheggsplode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808002B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808002B8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808002BC: jal         0x80100094
    // 0x808002C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808002C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002C4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808002C8: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808002CC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808002D0: beq         $v1, $at, L_80800300
    if (ctx->r3 == ctx->r1) {
        // 0x808002D4: addiu       $at, $zero, 0x9F
        ctx->r1 = ADD32(0, 0X9F);
            goto L_80800300;
    }
    // 0x808002D4: addiu       $at, $zero, 0x9F
    ctx->r1 = ADD32(0, 0X9F);
    // 0x808002D8: bne         $v1, $at, L_8080034C
    if (ctx->r3 != ctx->r1) {
        // 0x808002DC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080034C;
    }
    // 0x808002DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808002E0: jal         0x800D3948
    // 0x808002E4: nop

    func_800D3948(rdram, ctx);
        goto after_1;
    // 0x808002E4: nop

    after_1:
    // 0x808002E8: bne         $v0, $zero, L_808002F8
    if (ctx->r2 != 0) {
        // 0x808002EC: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_808002F8;
    }
    // 0x808002EC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x808002F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808002F4: sh          $t6, 0x6($t7)
    MEM_H(0X6, ctx->r15) = ctx->r14;
L_808002F8:
    // 0x808002F8: b           L_8080034C
    // 0x808002FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080034C;
    // 0x808002FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800300:
    // 0x80800300: jal         0x800BF8E4
    // 0x80800304: nop

    func_800BF8E4(rdram, ctx);
        goto after_2;
    // 0x80800304: nop

    after_2:
    // 0x80800308: blez        $v0, L_80800344
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080030C: nop
    
            goto L_80800344;
    }
    // 0x8080030C: nop

    // 0x80800310: jal         0x800C8A98
    // 0x80800314: nop

    func_800C8A98(rdram, ctx);
        goto after_3;
    // 0x80800314: nop

    after_3:
    // 0x80800318: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8080031C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2176, 0X9DC) << 16);
    // 0x80800320: addiu       $a1, $a1, 0x9DC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2176, 0X9DC));
    // 0x80800324: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800328: jal         0x800C8E84
    // 0x8080032C: sw          $v0, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r2;
    func_800C8E84(rdram, ctx);
        goto after_4;
    // 0x8080032C: sw          $v0, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r2;
    after_4:
    // 0x80800330: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80800334: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800338: lw          $a0, 0x10($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X10);
    // 0x8080033C: jal         0x800C8CB8
    // 0x80800340: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800C8CB8(rdram, ctx);
        goto after_5;
    // 0x80800340: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_5:
L_80800344:
    // 0x80800344: b           L_8080034C
    // 0x80800348: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080034C;
    // 0x80800348: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080034C:
    // 0x8080034C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800350: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800354: jr          $ra
    // 0x80800358: nop

    return;
    // 0x80800358: nop

;}
RECOMP_FUNC void func_80800D28_ncpoducam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D28: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800D2C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800D30: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800D34: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800D38: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80800D3C: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80800D40: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800D44: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800D48: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800D4C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800D50: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800D54: lbu         $a1, 0x60($s4)
    ctx->r5 = MEM_BU(ctx->r20, 0X60);
    // 0x80800D58: jal         0x80800CB8
    // 0x80800D5C: lh          $a0, 0x58($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X58);
    func_80800CB8_ncpoducam(rdram, ctx);
        goto after_0;
    // 0x80800D5C: lh          $a0, 0x58($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X58);
    after_0:
    // 0x80800D60: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800D64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D68: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800D6C: jal         0x80089EB0
    // 0x80800D70: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _susplinet_entrypoint_18(rdram, ctx);
        goto after_1;
    // 0x80800D70: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x80800D74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800D78: jal         0x8001B668
    // 0x80800D7C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8001B668(rdram, ctx);
        goto after_2;
    // 0x80800D7C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80800D80: sh          $v0, 0x2($s4)
    MEM_H(0X2, ctx->r20) = ctx->r2;
    // 0x80800D84: jal         0x8001B798
    // 0x80800D88: lh          $a0, 0x2($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X2);
    func_8001B798(rdram, ctx);
        goto after_3;
    // 0x80800D88: lh          $a0, 0x2($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X2);
    after_3:
    // 0x80800D8C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800D90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D94: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800D98: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800D9C: jal         0x80089EB8
    // 0x80800DA0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    _susplinet_entrypoint_19(rdram, ctx);
        goto after_4;
    // 0x80800DA0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_4:
    // 0x80800DA4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800DA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800DAC: jal         0x80089E28
    // 0x80800DB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _susplinet_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800DB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80800DB4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800DB8: addiu       $s1, $sp, 0x68
    ctx->r17 = ADD32(ctx->r29, 0X68);
L_80800DBC:
    // 0x80800DBC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800DC0: jal         0x80089E90
    // 0x80800DC4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _susplinet_entrypoint_14(rdram, ctx);
        goto after_6;
    // 0x80800DC4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80800DC8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800DCC: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x80800DD0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800DD4: bne         $at, $zero, L_80800DBC
    if (ctx->r1 != 0) {
        // 0x80800DD8: sw          $v0, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->r2;
            goto L_80800DBC;
    }
    // 0x80800DD8: sw          $v0, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->r2;
    // 0x80800DDC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800DE0: addiu       $s1, $sp, 0x60
    ctx->r17 = ADD32(ctx->r29, 0X60);
    // 0x80800DE4: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_80800DE8:
    // 0x80800DE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800DEC: jal         0x80089E98
    // 0x80800DF0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _susplinet_entrypoint_15(rdram, ctx);
        goto after_7;
    // 0x80800DF0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x80800DF4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800DF8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800DFC: bne         $s0, $s3, L_80800DE8
    if (ctx->r16 != ctx->r19) {
        // 0x80800E00: sw          $v0, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->r2;
            goto L_80800DE8;
    }
    // 0x80800E00: sw          $v0, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->r2;
    // 0x80800E04: jal         0x80089E80
    // 0x80800E08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _susplinet_entrypoint_12(rdram, ctx);
        goto after_8;
    // 0x80800E08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x80800E0C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800E10: jal         0x80089E88
    // 0x80800E14: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _susplinet_entrypoint_13(rdram, ctx);
        goto after_9;
    // 0x80800E14: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x80800E18: lh          $t6, 0x58($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X58);
    // 0x80800E1C: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x80800E20: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800E24: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80800E28: lh          $t7, 0x52($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X52);
    // 0x80800E2C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800E30: addiu       $s7, $sp, 0x52
    ctx->r23 = ADD32(ctx->r29, 0X52);
    // 0x80800E34: beq         $t7, $s5, L_80800F38
    if (ctx->r15 == ctx->r21) {
        // 0x80800E38: addiu       $s6, $sp, 0x48
        ctx->r22 = ADD32(ctx->r29, 0X48);
            goto L_80800F38;
    }
    // 0x80800E38: addiu       $s6, $sp, 0x48
    ctx->r22 = ADD32(ctx->r29, 0X48);
    // 0x80800E3C: addiu       $s4, $sp, 0x3C
    ctx->r20 = ADD32(ctx->r29, 0X3C);
    // 0x80800E40: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
L_80800E44:
    // 0x80800E44: jal         0x800A5800
    // 0x80800E48: nop

    func_800A5800(rdram, ctx);
        goto after_10;
    // 0x80800E48: nop

    after_10:
    // 0x80800E4C: jal         0x80085580
    // 0x80800E50: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    _cadbfunc_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x80800E50: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_11:
    // 0x80800E54: jal         0x80085590
    // 0x80800E58: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    _cadbfunc_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x80800E58: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    after_12:
    // 0x80800E5C: sh          $s5, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r21;
    // 0x80800E60: jal         0x800855E0
    // 0x80800E64: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    _cadbfunc_entrypoint_12(rdram, ctx);
        goto after_13;
    // 0x80800E64: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_13:
    // 0x80800E68: jal         0x80085640
    // 0x80800E6C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    _cadbfunc_entrypoint_24(rdram, ctx);
        goto after_14;
    // 0x80800E6C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_14:
    // 0x80800E70: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80800E74: sh          $t8, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r24;
    // 0x80800E78: jal         0x800855F0
    // 0x80800E7C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    _cadbfunc_entrypoint_14(rdram, ctx);
        goto after_15;
    // 0x80800E7C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    after_15:
    // 0x80800E80: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x80800E84: jal         0x80085668
    // 0x80800E88: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    _cadbfunc_entrypoint_29(rdram, ctx);
        goto after_16;
    // 0x80800E88: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_16:
    // 0x80800E8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800E90: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800E94: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800E98: jal         0x80089E20
    // 0x80800E9C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    _susplinet_entrypoint_0(rdram, ctx);
        goto after_17;
    // 0x80800E9C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    after_17:
    // 0x80800EA0: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    // 0x80800EA4: jal         0x80085668
    // 0x80800EA8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    _cadbfunc_entrypoint_29(rdram, ctx);
        goto after_18;
    // 0x80800EA8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_18:
    // 0x80800EAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800EB0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800EB4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800EB8: jal         0x80089E20
    // 0x80800EBC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    _susplinet_entrypoint_0(rdram, ctx);
        goto after_19;
    // 0x80800EBC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    after_19:
    // 0x80800EC0: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x80800EC4: jal         0x80085668
    // 0x80800EC8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    _cadbfunc_entrypoint_29(rdram, ctx);
        goto after_20;
    // 0x80800EC8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_20:
    // 0x80800ECC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800ED0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800ED4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800ED8: jal         0x80089E20
    // 0x80800EDC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    _susplinet_entrypoint_0(rdram, ctx);
        goto after_21;
    // 0x80800EDC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    after_21:
    // 0x80800EE0: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80800EE4: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x80800EE8: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x80800EEC: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x80800EF0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800EF4: sll         $t7, $s0, 16
    ctx->r15 = S32(ctx->r16 << 16);
    // 0x80800EF8: addiu       $t0, $t9, 0xC
    ctx->r8 = ADD32(ctx->r25, 0XC);
    // 0x80800EFC: addiu       $t2, $t1, 0xC
    ctx->r10 = ADD32(ctx->r9, 0XC);
    // 0x80800F00: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x80800F04: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x80800F08: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80800F0C: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x80800F10: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x80800F14: sw          $t2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r10;
    // 0x80800F18: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
    // 0x80800F1C: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x80800F20: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80800F24: jal         0x80085600
    // 0x80800F28: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    _cadbfunc_entrypoint_16(rdram, ctx);
        goto after_22;
    // 0x80800F28: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_22:
    // 0x80800F2C: lh          $a0, 0x52($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X52);
    // 0x80800F30: bne         $a0, $s5, L_80800E44
    if (ctx->r4 != ctx->r21) {
        // 0x80800F34: nop
    
            goto L_80800E44;
    }
    // 0x80800F34: nop

L_80800F38:
    // 0x80800F38: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800F3C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800F40: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800F44: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F48: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800F4C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80800F50: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80800F54: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80800F58: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80800F5C: jr          $ra
    // 0x80800F60: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80800F60: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80800000_bstaxi(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x8009EF1C
    // 0x8080000C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80800014: jal         0x8009EF10
    // 0x80800018: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x80800018: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080001C: bne         $v0, $zero, L_80800038
    if (ctx->r2 != 0) {
        // 0x80800020: lwc1        $f12, 0x1C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_80800038;
    }
    // 0x80800020: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800024: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800028: jal         0x8009B9B0
    // 0x8080002C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x8080002C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800030: b           L_80800058
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800058;
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800038:
    // 0x80800038: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8080003C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800040: jal         0x800F1214
    // 0x80800044: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x80800044: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    after_3:
    // 0x80800048: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080004C: jal         0x8009B9B0
    // 0x80800050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800058:
    // 0x80800058: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080005C: jr          $ra
    // 0x80800060: nop

    return;
    // 0x80800060: nop

;}
RECOMP_FUNC void func_80801A50_chfantasyeyeball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A50: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801A54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801A58: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80801A5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801A60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801A64: beq         $a1, $at, L_80801B04
    if (ctx->r5 == ctx->r1) {
        // 0x80801A68: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_80801B04;
    }
    // 0x80801A68: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80801A6C: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80801A70: beq         $a1, $at, L_80801B44
    if (ctx->r5 == ctx->r1) {
        // 0x80801A74: addiu       $at, $zero, 0x3E
        ctx->r1 = ADD32(0, 0X3E);
            goto L_80801B44;
    }
    // 0x80801A74: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80801A78: beq         $a1, $at, L_80801A9C
    if (ctx->r5 == ctx->r1) {
        // 0x80801A7C: addiu       $at, $zero, 0x3F
        ctx->r1 = ADD32(0, 0X3F);
            goto L_80801A9C;
    }
    // 0x80801A7C: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x80801A80: beq         $a1, $at, L_80801AC4
    if (ctx->r5 == ctx->r1) {
        // 0x80801A84: lw          $t6, 0x40($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X40);
            goto L_80801AC4;
    }
    // 0x80801A84: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80801A88: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80801A8C: beq         $a1, $at, L_80801B60
    if (ctx->r5 == ctx->r1) {
        // 0x80801A90: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80801B60;
    }
    // 0x80801A90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801A94: b           L_80801BB0
    // 0x80801A98: nop

        goto L_80801BB0;
    // 0x80801A98: nop

L_80801A9C:
    // 0x80801A9C: jal         0x800F54E4
    // 0x80801AA0: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80801AA0: nop

    after_0:
    // 0x80801AA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801AA8: jal         0x800F5A00
    // 0x80801AAC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x80801AAC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x80801AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AB4: jal         0x80801BC4
    // 0x80801AB8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80801BC4_chfantasyeyeball(rdram, ctx);
        goto after_2;
    // 0x80801AB8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x80801ABC: b           L_80801BB0
    // 0x80801AC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801BB0;
    // 0x80801AC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801AC4:
    // 0x80801AC4: lhu         $t7, 0x18($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X18);
    // 0x80801AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801ACC: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80801AD0: beq         $t8, $zero, L_80801AF4
    if (ctx->r24 == 0) {
        // 0x80801AD4: nop
    
            goto L_80801AF4;
    }
    // 0x80801AD4: nop

    // 0x80801AD8: jal         0x80106790
    // 0x80801ADC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_80106790(rdram, ctx);
        goto after_3;
    // 0x80801ADC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_3:
    // 0x80801AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AE4: jal         0x80801BC4
    // 0x80801AE8: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_80801BC4_chfantasyeyeball(rdram, ctx);
        goto after_4;
    // 0x80801AE8: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_4:
    // 0x80801AEC: b           L_80801BB0
    // 0x80801AF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801BB0;
    // 0x80801AF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801AF4:
    // 0x80801AF4: jal         0x80801BC4
    // 0x80801AF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801BC4_chfantasyeyeball(rdram, ctx);
        goto after_5;
    // 0x80801AF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80801AFC: b           L_80801BB0
    // 0x80801B00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801BB0;
    // 0x80801B00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801B04:
    // 0x80801B04: jal         0x80101080
    // 0x80801B08: nop

    func_80101080(rdram, ctx);
        goto after_6;
    // 0x80801B08: nop

    after_6:
    // 0x80801B0C: jal         0x80106790
    // 0x80801B10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_7;
    // 0x80801B10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80801B14: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80801B18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801B1C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801B20: jal         0x80086E00
    // 0x80801B24: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chskeletonexplode_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x80801B24: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_8:
    // 0x80801B28: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801B2C: jal         0x80086E08
    // 0x80801B30: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    _chskeletonexplode_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x80801B30: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_9:
    // 0x80801B34: jal         0x800FFA88
    // 0x80801B38: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_10;
    // 0x80801B38: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_10:
    // 0x80801B3C: b           L_80801BB0
    // 0x80801B40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801BB0;
    // 0x80801B40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801B44:
    // 0x80801B44: jal         0x801015D0
    // 0x80801B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_11;
    // 0x80801B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80801B4C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80801B50: jal         0x800DF744
    // 0x80801B54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_12;
    // 0x80801B54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80801B58: b           L_80801BB0
    // 0x80801B5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801BB0;
    // 0x80801B5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801B60:
    // 0x80801B60: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80801B64: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801B68: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80801B6C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801B70: jal         0x800DC178
    // 0x80801B74: nop

    func_800DC178(rdram, ctx);
        goto after_13;
    // 0x80801B74: nop

    after_13:
    // 0x80801B78: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80801B7C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801B80: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80801B84: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801B88: jal         0x800DC178
    // 0x80801B8C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_14;
    // 0x80801B8C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    after_14:
    // 0x80801B90: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80801B94: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80801B98: jal         0x800EE7F8
    // 0x80801B9C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_15;
    // 0x80801B9C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_15:
    // 0x80801BA0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801BA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801BA8: b           L_80801BB0
    // 0x80801BAC: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
        goto L_80801BB0;
    // 0x80801BAC: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
L_80801BB0:
    // 0x80801BB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801BB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801BB8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801BBC: jr          $ra
    // 0x80801BC0: nop

    return;
    // 0x80801BC0: nop

;}
RECOMP_FUNC void chchuffyglow_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808004D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004D4: jal         0x80106790
    // 0x808004D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808004D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x808004DC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808004E0: addiu       $a0, $zero, 0x30E
    ctx->r4 = ADD32(0, 0X30E);
    // 0x808004E4: jal         0x801084B0
    // 0x808004E8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_801084B0(rdram, ctx);
        goto after_1;
    // 0x808004E8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x808004EC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808004F0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x808004F4: sw          $t7, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r15;
    // 0x808004F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800500: jr          $ra
    // 0x80800504: nop

    return;
    // 0x80800504: nop

;}
RECOMP_FUNC void func_800C7B28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7B28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C7B2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C7B30: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C7B34: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C7B38: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800C7B3C: jal         0x800C7980
    // 0x800C7B40: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800C7980(rdram, ctx);
        goto after_0;
    // 0x800C7B40: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800C7B44: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800C7B48: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7B4C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800C7B50: lbu         $a0, 0x2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2);
    // 0x800C7B54: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800C7B58: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800C7B5C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800C7B60: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800C7B64: jal         0x80089138
    // 0x800C7B68: addiu       $a1, $v1, 0x14
    ctx->r5 = ADD32(ctx->r3, 0X14);
    _mlspline_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x800C7B68: addiu       $a1, $v1, 0x14
    ctx->r5 = ADD32(ctx->r3, 0X14);
    after_1:
    // 0x800C7B6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7B70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C7B74: jr          $ra
    // 0x800C7B78: nop

    return;
    // 0x800C7B78: nop

;}
RECOMP_FUNC void func_800E3CB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3CB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E3CBC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800E3CC0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800E3CC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E3CC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3CCC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3CD0: jal         0x800CA6D4
    // 0x800E3CD4: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA6D4(rdram, ctx);
        goto after_0;
    // 0x800E3CD4: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E3CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E3CDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E3CE0: jr          $ra
    // 0x800E3CE4: nop

    return;
    // 0x800E3CE4: nop

;}
RECOMP_FUNC void func_80800050_bsdronexform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800050: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800054: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800058: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8080005C: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80800060: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800064: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80800068: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080006C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800070: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80800074: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800078: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080007C: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80800080: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80800084: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80800088: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080008C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800090: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800094: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80800098: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8080009C: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x808000A0: sll         $t0, $a3, 16
    ctx->r8 = S32(ctx->r7 << 16);
    // 0x808000A4: sra         $a3, $t0, 16
    ctx->r7 = S32(SIGNED(ctx->r8) >> 16);
    // 0x808000A8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x808000AC: jal         0x800BA930
    // 0x808000B0: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    func_800BA930(rdram, ctx);
        goto after_0;
    // 0x808000B0: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    after_0:
    // 0x808000B4: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x808000B8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808000BC: lw          $t4, 0x18C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X18C);
    // 0x808000C0: lwc1        $f0, 0x14($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X14);
    // 0x808000C4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000C8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000CC: jal         0x800BA7C4
    // 0x808000D0: nop

    func_800BA7C4(rdram, ctx);
        goto after_1;
    // 0x808000D0: nop

    after_1:
    // 0x808000D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000DC: jr          $ra
    // 0x808000E0: nop

    return;
    // 0x808000E0: nop

;}
RECOMP_FUNC void _bsdronefalldie_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800830A8: syscall     41
    recomp_syscall_handler(rdram, ctx, 0x800830A8);
    return;
    // 0x800830AC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void ncfixposrot_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002E8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808002EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002F0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808002F4: jal         0x800EE7F8
    // 0x808002F8: addiu       $a1, $a3, 0xC
    ctx->r5 = ADD32(ctx->r7, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808002F8: addiu       $a1, $a3, 0xC
    ctx->r5 = ADD32(ctx->r7, 0XC);
    after_0:
    // 0x808002FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800300: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800304: jr          $ra
    // 0x80800308: nop

    return;
    // 0x80800308: nop

;}
RECOMP_FUNC void _gsmaker_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082608: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x80082608);
    return;
    // 0x8008260C: addi        $t0, $zero, 0x60
    ctx->r8 = ADD32(0, 0X60);
;}
RECOMP_FUNC void bsblongleg_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800574: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800578: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080057C: jal         0x80800204
    // 0x80800580: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800204_bsblongleg(rdram, ctx);
        goto after_0;
    // 0x80800580: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800584: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800588: jal         0x800C2FDC
    // 0x8080058C: lbu         $a0, 0x160($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X160);
    func_800C2FDC(rdram, ctx);
        goto after_1;
    // 0x8080058C: lbu         $a0, 0x160($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X160);
    after_1:
    // 0x80800590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800594: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800598: jr          $ra
    // 0x8080059C: nop

    return;
    // 0x8080059C: nop

;}
RECOMP_FUNC void bssplat_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080029C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808002A0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(360, 0X2B0) << 16);
    // 0x808002A4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808002A8: jr          $ra
    // 0x808002AC: lw          $v0, 0x2B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(360, 0X2B0));
    return;
    // 0x808002AC: lw          $v0, 0x2B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(360, 0X2B0));
;}
RECOMP_FUNC void func_80800D10_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D10: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80800D14: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x80800D18: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x80800D1C: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x80800D20: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x80800D24: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800D28: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80800D2C: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x80800D30: addiu       $s7, $sp, 0x60
    ctx->r23 = ADD32(ctx->r29, 0X60);
    // 0x80800D34: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80800D38: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80800D3C: addiu       $t6, $sp, 0x6C
    ctx->r14 = ADD32(ctx->r29, 0X6C);
    // 0x80800D40: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80800D44: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80800D48: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80800D4C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800D50: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800D54: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800D58: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80800D5C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x80800D60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800D64: jal         0x800A8A04
    // 0x80800D68: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    func_800A8A04(rdram, ctx);
        goto after_0;
    // 0x80800D68: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    after_0:
    // 0x80800D6C: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80800D70: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80800D74: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800D78: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80800D7C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800D80: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80800D84: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800D88: addiu       $s2, $sp, 0x70
    ctx->r18 = ADD32(ctx->r29, 0X70);
    // 0x80800D8C: addiu       $s3, $sp, 0x78
    ctx->r19 = ADD32(ctx->r29, 0X78);
    // 0x80800D90: addiu       $t7, $zero, 0x1C
    ctx->r15 = ADD32(0, 0X1C);
    // 0x80800D94: addiu       $t8, $zero, 0xC8
    ctx->r24 = ADD32(0, 0XC8);
    // 0x80800D98: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800D9C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800DA0: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x80800DA4: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    // 0x80800DA8: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    // 0x80800DAC: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x80800DB0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800DB4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80800DB8: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80800DBC: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800DC0: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x80800DC4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800DC8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800DCC: mfc1        $s1, $f6
    ctx->r17 = (int32_t)ctx->f6.u32l;
    // 0x80800DD0: jal         0x80800B28
    // 0x80800DD4: nop

    func_80800B28_ncpoddialog(rdram, ctx);
        goto after_1;
    // 0x80800DD4: nop

    after_1:
    // 0x80800DD8: lb          $v1, 0x211($s4)
    ctx->r3 = MEM_B(ctx->r20, 0X211);
    // 0x80800DDC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800DE0: beq         $v1, $at, L_80800F5C
    if (ctx->r3 == ctx->r1) {
        // 0x80800DE4: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80800F5C;
    }
    // 0x80800DE4: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80800DE8: beql        $v1, $at, L_80800F60
    if (ctx->r3 == ctx->r1) {
        // 0x80800DEC: lbu         $t7, 0x217($s4)
        ctx->r15 = MEM_BU(ctx->r20, 0X217);
            goto L_80800F60;
    }
    goto skip_0;
    // 0x80800DEC: lbu         $t7, 0x217($s4)
    ctx->r15 = MEM_BU(ctx->r20, 0X217);
    skip_0:
    // 0x80800DF0: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x80800DF4: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80800DF8: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
    // 0x80800DFC: cvt.s.w     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800E00: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80800E04: nop

    // 0x80800E08: bc1f        L_80800E50
    if (!c1cs) {
        // 0x80800E0C: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80800E50;
    }
    // 0x80800E0C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80800E10:
    // 0x80800E10: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800E14: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800E18: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800E1C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80800E20: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800E24: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x80800E28: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x80800E2C: jal         0x80800B28
    // 0x80800E30: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    func_80800B28_ncpoddialog(rdram, ctx);
        goto after_2;
    // 0x80800E30: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    after_2:
    // 0x80800E34: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80800E38: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80800E3C: nop

    // 0x80800E40: bc1fl       L_80800E54
    if (!c1cs) {
        // 0x80800E44: c.lt.s      $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
            goto L_80800E54;
    }
    goto skip_1;
    // 0x80800E44: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    skip_1:
    // 0x80800E48: bnel        $s0, $s1, L_80800E10
    if (ctx->r16 != ctx->r17) {
        // 0x80800E4C: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80800E10;
    }
    goto skip_2;
    // 0x80800E4C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    skip_2:
L_80800E50:
    // 0x80800E50: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
L_80800E54:
    // 0x80800E54: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
    // 0x80800E58: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800E5C: bc1f        L_80800EA4
    if (!c1cs) {
        // 0x80800E60: addiu       $t3, $zero, 0x2
        ctx->r11 = ADD32(0, 0X2);
            goto L_80800EA4;
    }
    // 0x80800E60: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
L_80800E64:
    // 0x80800E64: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800E68: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800E6C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800E70: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80800E74: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800E78: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x80800E7C: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x80800E80: jal         0x80800B28
    // 0x80800E84: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    func_80800B28_ncpoddialog(rdram, ctx);
        goto after_3;
    // 0x80800E84: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    after_3:
    // 0x80800E88: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80800E8C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80800E90: nop

    // 0x80800E94: bc1fl       L_80800EA8
    if (!c1cs) {
        // 0x80800E98: addiu       $t4, $zero, 0x72
        ctx->r12 = ADD32(0, 0X72);
            goto L_80800EA8;
    }
    goto skip_3;
    // 0x80800E98: addiu       $t4, $zero, 0x72
    ctx->r12 = ADD32(0, 0X72);
    skip_3:
    // 0x80800E9C: bnel        $s0, $s1, L_80800E64
    if (ctx->r16 != ctx->r17) {
        // 0x80800EA0: addiu       $t3, $zero, 0x2
        ctx->r11 = ADD32(0, 0X2);
            goto L_80800E64;
    }
    goto skip_4;
    // 0x80800EA0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    skip_4:
L_80800EA4:
    // 0x80800EA4: addiu       $t4, $zero, 0x72
    ctx->r12 = ADD32(0, 0X72);
L_80800EA8:
    // 0x80800EA8: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80800EAC: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80800EB0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800EB4: cvt.s.w     $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800EB8: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80800EBC: nop

    // 0x80800EC0: bc1f        L_80800F08
    if (!c1cs) {
        // 0x80800EC4: addiu       $t5, $zero, 0x3
        ctx->r13 = ADD32(0, 0X3);
            goto L_80800F08;
    }
    // 0x80800EC4: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
L_80800EC8:
    // 0x80800EC8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800ECC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800ED0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800ED4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80800ED8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800EDC: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x80800EE0: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x80800EE4: jal         0x80800B28
    // 0x80800EE8: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    func_80800B28_ncpoddialog(rdram, ctx);
        goto after_4;
    // 0x80800EE8: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    after_4:
    // 0x80800EEC: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80800EF0: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80800EF4: nop

    // 0x80800EF8: bc1fl       L_80800F0C
    if (!c1cs) {
        // 0x80800EFC: c.lt.s      $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
            goto L_80800F0C;
    }
    goto skip_5;
    // 0x80800EFC: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    skip_5:
    // 0x80800F00: bnel        $s0, $s1, L_80800EC8
    if (ctx->r16 != ctx->r17) {
        // 0x80800F04: addiu       $t5, $zero, 0x3
        ctx->r13 = ADD32(0, 0X3);
            goto L_80800EC8;
    }
    goto skip_6;
    // 0x80800F04: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    skip_6:
L_80800F08:
    // 0x80800F08: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
L_80800F0C:
    // 0x80800F0C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800F10: bc1f        L_80800F58
    if (!c1cs) {
        // 0x80800F14: addiu       $t6, $zero, 0x4
        ctx->r14 = ADD32(0, 0X4);
            goto L_80800F58;
    }
    // 0x80800F14: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
L_80800F18:
    // 0x80800F18: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800F1C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800F20: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800F24: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80800F28: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800F2C: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x80800F30: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x80800F34: jal         0x80800B28
    // 0x80800F38: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    func_80800B28_ncpoddialog(rdram, ctx);
        goto after_5;
    // 0x80800F38: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    after_5:
    // 0x80800F3C: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80800F40: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80800F44: nop

    // 0x80800F48: bc1fl       L_80800F5C
    if (!c1cs) {
        // 0x80800F4C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800F5C;
    }
    goto skip_7;
    // 0x80800F4C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_7:
    // 0x80800F50: bnel        $s0, $s1, L_80800F18
    if (ctx->r16 != ctx->r17) {
        // 0x80800F54: addiu       $t6, $zero, 0x4
        ctx->r14 = ADD32(0, 0X4);
            goto L_80800F18;
    }
    goto skip_8;
    // 0x80800F54: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    skip_8:
L_80800F58:
    // 0x80800F58: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80800F5C:
    // 0x80800F5C: lbu         $t7, 0x217($s4)
    ctx->r15 = MEM_BU(ctx->r20, 0X217);
L_80800F60:
    // 0x80800F60: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800F64: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80800F68: bne         $t7, $zero, L_80800FC8
    if (ctx->r15 != 0) {
        // 0x80800F6C: or          $a2, $s6, $zero
        ctx->r6 = ctx->r22 | 0;
            goto L_80800FC8;
    }
    // 0x80800F6C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800F70: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80800F74: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800F78: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x80800F7C: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x80800F80: jal         0x80800B28
    // 0x80800F84: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    func_80800B28_ncpoddialog(rdram, ctx);
        goto after_6;
    // 0x80800F84: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    after_6:
    // 0x80800F88: beq         $v0, $zero, L_80800FC4
    if (ctx->r2 == 0) {
        // 0x80800F8C: addiu       $t9, $zero, 0x5
        ctx->r25 = ADD32(0, 0X5);
            goto L_80800FC4;
    }
    // 0x80800F8C: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
L_80800F90:
    // 0x80800F90: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800F94: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800F98: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800F9C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80800FA0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800FA4: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x80800FA8: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x80800FAC: jal         0x80800B28
    // 0x80800FB0: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    func_80800B28_ncpoddialog(rdram, ctx);
        goto after_7;
    // 0x80800FB0: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    after_7:
    // 0x80800FB4: beq         $v0, $zero, L_80800FC4
    if (ctx->r2 == 0) {
        // 0x80800FB8: slti        $at, $s0, 0xA
        ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
            goto L_80800FC4;
    }
    // 0x80800FB8: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x80800FBC: bnel        $at, $zero, L_80800F90
    if (ctx->r1 != 0) {
        // 0x80800FC0: addiu       $t9, $zero, 0x5
        ctx->r25 = ADD32(0, 0X5);
            goto L_80800F90;
    }
    goto skip_9;
    // 0x80800FC0: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    skip_9:
L_80800FC4:
    // 0x80800FC4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80800FC8:
    // 0x80800FC8: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80800FCC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800FD0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800FD4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80800FD8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800FDC: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x80800FE0: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x80800FE4: jal         0x80800B28
    // 0x80800FE8: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    func_80800B28_ncpoddialog(rdram, ctx);
        goto after_8;
    // 0x80800FE8: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    after_8:
    // 0x80800FEC: bne         $v0, $zero, L_80801028
    if (ctx->r2 != 0) {
        // 0x80800FF0: addiu       $t1, $zero, 0x6
        ctx->r9 = ADD32(0, 0X6);
            goto L_80801028;
    }
    // 0x80800FF0: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
L_80800FF4:
    // 0x80800FF4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800FF8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800FFC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80801000: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80801004: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80801008: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x8080100C: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x80801010: jal         0x80800B28
    // 0x80801014: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    func_80800B28_ncpoddialog(rdram, ctx);
        goto after_9;
    // 0x80801014: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    after_9:
    // 0x80801018: bne         $v0, $zero, L_80801028
    if (ctx->r2 != 0) {
        // 0x8080101C: slti        $at, $s0, 0xA
        ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
            goto L_80801028;
    }
    // 0x8080101C: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x80801020: bnel        $at, $zero, L_80800FF4
    if (ctx->r1 != 0) {
        // 0x80801024: addiu       $t1, $zero, 0x6
        ctx->r9 = ADD32(0, 0X6);
            goto L_80800FF4;
    }
    goto skip_10;
    // 0x80801024: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    skip_10:
L_80801028:
    // 0x80801028: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8080102C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80801030: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80801034: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80801038: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x8080103C: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80801040: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80801044: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80801048: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x8080104C: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x80801050: jr          $ra
    // 0x80801054: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80801054: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_80801518_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801518: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080151C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801520: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801524: jal         0x80800AEC
    // 0x80801528: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    func_80800AEC_bssub(rdram, ctx);
        goto after_0;
    // 0x80801528: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x8080152C: jal         0x800839E8
    // 0x80801530: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80801530: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80801534: beql        $v0, $zero, L_8080154C
    if (ctx->r2 == 0) {
        // 0x80801538: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8080154C;
    }
    goto skip_0;
    // 0x80801538: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x8080153C: jal         0x80084750
    // 0x80801540: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _badata_entrypoint_34(rdram, ctx);
        goto after_2;
    // 0x80801540: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80801544: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80801548: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_8080154C:
    // 0x8080154C: jal         0x8009E5C8
    // 0x80801550: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x80801550: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80801554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801558: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080155C: jr          $ra
    // 0x80801560: nop

    return;
    // 0x80801560: nop

;}
RECOMP_FUNC void func_808004A8_bskazwingwhack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004B0: jal         0x8009E474
    // 0x808004B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E474(rdram, ctx);
        goto after_0;
    // 0x808004B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808004B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808004BC: jal         0x80095774
    // 0x808004C0: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    baflag_clear(rdram, ctx);
        goto after_1;
    // 0x808004C0: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    after_1:
    // 0x808004C4: jal         0x800832E8
    // 0x808004C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808004C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808004CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004D4: jr          $ra
    // 0x808004D8: nop

    return;
    // 0x808004D8: nop

;}
RECOMP_FUNC void func_8080000C_chtalontorpedoboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: jal         0x808001CC
    // 0x80800018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808001CC_chtalontorpedoboulder(rdram, ctx);
        goto after_0;
    // 0x80800018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080001C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800020: beq         $v0, $zero, L_80800048
    if (ctx->r2 == 0) {
        // 0x80800024: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800048;
    }
    // 0x80800024: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800028: jal         0x800DA298
    // 0x8080002C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x8080002C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800030: beq         $v0, $zero, L_80800048
    if (ctx->r2 == 0) {
        // 0x80800034: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80800048;
    }
    // 0x80800034: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800038: jal         0x800FFAB0
    // 0x8080003C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x8080003C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80800040: b           L_80800064
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800064;
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800048:
    // 0x80800048: lwc1        $f0, 0x38($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X38);
    // 0x8080004C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800050: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80800054: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800058: jal         0x80102FDC
    // 0x8080005C: nop

    func_80102FDC(rdram, ctx);
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
RECOMP_FUNC void func_808001B0_chbottlesfamily(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808001B4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808001B8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808001BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001C0: jal         0x80100094
    // 0x808001C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808001C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808001C8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808001CC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808001D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001D4: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808001D8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808001DC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808001E0: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808001E4: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x808001E8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001EC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808001F0: jal         0x80089F18
    // 0x808001F4: nop

    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808001F4: nop

    after_1:
    // 0x808001F8: jal         0x80089828
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suexpression_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800200: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800204: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800208: jal         0x800897D8
    // 0x8080020C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x8080020C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80800210: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800214: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800218: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8080021C: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x80800220: beq         $at, $zero, L_80800458
    if (ctx->r1 == 0) {
        // 0x80800224: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800458;
    }
    // 0x80800224: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800228: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1300, 0XD30) << 16);
    // 0x8080022C: addu        $at, $at, $t8
    gpr jr_addend_80800234 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800230: lw          $t8, 0xD30($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1300, 0XD30));
    // 0x80800234: jr          $t8
    // 0x80800238: nop

    switch (jr_addend_80800234 >> 2) {
        case 0: goto L_8080023C; break;
        case 1: goto L_80800274; break;
        case 2: goto L_808002A0; break;
        case 3: goto L_808003FC; break;
        case 4: goto L_80800450; break;
        default: switch_error(__func__, 0x80800234, 0x80800D30);
    }
    // 0x80800238: nop

L_8080023C:
    // 0x8080023C: jal         0x808005D0
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005D0_chbottlesfamily(rdram, ctx);
        goto after_4;
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800244: jal         0x808004B4
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004B4_chbottlesfamily(rdram, ctx);
        goto after_5;
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080024C: bnel        $v0, $zero, L_8080045C
    if (ctx->r2 != 0) {
        // 0x80800250: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8080045C;
    }
    goto skip_0;
    // 0x80800250: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80800254: jal         0x800D90A4
    // 0x80800258: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_6;
    // 0x80800258: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_6:
    // 0x8080025C: beql        $v0, $zero, L_8080045C
    if (ctx->r2 == 0) {
        // 0x80800260: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8080045C;
    }
    goto skip_1;
    // 0x80800260: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80800264: jal         0x80800520
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800520_chbottlesfamily(rdram, ctx);
        goto after_7;
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080026C: b           L_8080045C
    // 0x80800270: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8080045C;
    // 0x80800270: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800274:
    // 0x80800274: jal         0x8010CD28
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_8;
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080027C: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800280: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800284: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080028C: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x80800290: jal         0x80102BF8
    // 0x80800294: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    func_80102BF8(rdram, ctx);
        goto after_9;
    // 0x80800294: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    after_9:
    // 0x80800298: b           L_8080045C
    // 0x8080029C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8080045C;
    // 0x8080029C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808002A0:
    // 0x808002A0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808002A4: jal         0x800D9078
    // 0x808002A8: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800D9078(rdram, ctx);
        goto after_10;
    // 0x808002A8: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_10:
    // 0x808002AC: beq         $v0, $zero, L_808002E4
    if (ctx->r2 == 0) {
        // 0x808002B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002E4;
    }
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1300, 0XEF8) << 16);
    // 0x808002B8: addiu       $a2, $a2, 0xEF8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1300, 0XEF8));
    // 0x808002BC: jal         0x80089D18
    // 0x808002C0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x808002C0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_11:
    // 0x808002C4: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x808002C8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808002CC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808002D0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808002D4: jal         0x800DC178
    // 0x808002D8: nop

    func_800DC178(rdram, ctx);
        goto after_12;
    // 0x808002D8: nop

    after_12:
    // 0x808002DC: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x808002E0: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
L_808002E4:
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E8: jal         0x80105230
    // 0x808002EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80105230(rdram, ctx);
        goto after_13;
    // 0x808002EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x808002F0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808002F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002F8: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x808002FC: lw          $a3, 0x54($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X54);
    // 0x80800300: addiu       $t0, $zero, 0x401
    ctx->r8 = ADD32(0, 0X401);
    // 0x80800304: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080030C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800310: jal         0x80089F90
    // 0x80800314: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_14;
    // 0x80800314: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_14:
    // 0x80800318: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8080031C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1300, 0XD44) << 16);
    // 0x80800320: lwc1        $f10, 0xD44($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1300, 0XD44));
    // 0x80800324: lhu         $a2, 0x6($a1)
    ctx->r6 = MEM_HU(ctx->r5, 0X6);
    // 0x80800328: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8080032C: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80800330: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80800334: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080033C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80800340: jal         0x80089F88
    // 0x80800344: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    _subaddierouteDll_entrypoint_6(rdram, ctx);
        goto after_15;
    // 0x80800344: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_15:
    // 0x80800348: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8080034C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800350: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800354: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80800358: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080035C: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x80800360: lhu         $a2, 0x6($a1)
    ctx->r6 = MEM_HU(ctx->r5, 0X6);
    // 0x80800364: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080036C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80800370: jal         0x80089F80
    // 0x80800374: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    _subaddierouteDll_entrypoint_5(rdram, ctx);
        goto after_16;
    // 0x80800374: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_16:
    // 0x80800378: jal         0x800D8FF8
    // 0x8080037C: nop

    func_800D8FF8(rdram, ctx);
        goto after_17;
    // 0x8080037C: nop

    after_17:
    // 0x80800380: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800384: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800388: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8080038C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800390: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800394: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800398: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8080039C: jal         0x800F15F8
    // 0x808003A0: nop

    func_800F15F8(rdram, ctx);
        goto after_18;
    // 0x808003A0: nop

    after_18:
    // 0x808003A4: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003AC: jal         0x8010B990
    // 0x808003B0: addiu       $a1, $zero, 0x1305
    ctx->r5 = ADD32(0, 0X1305);
    func_8010B990(rdram, ctx);
        goto after_19;
    // 0x808003B0: addiu       $a1, $zero, 0x1305
    ctx->r5 = ADD32(0, 0X1305);
    after_19:
    // 0x808003B4: jal         0x808004B4
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004B4_chbottlesfamily(rdram, ctx);
        goto after_20;
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x808003BC: bnel        $v0, $zero, L_8080045C
    if (ctx->r2 != 0) {
        // 0x808003C0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8080045C;
    }
    goto skip_2;
    // 0x808003C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x808003C4: jal         0x800D90A4
    // 0x808003C8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_21;
    // 0x808003C8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_21:
    // 0x808003CC: beq         $v0, $zero, L_80800458
    if (ctx->r2 == 0) {
        // 0x808003D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800458;
    }
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D4: jal         0x80102424
    // 0x808003D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_22;
    // 0x808003D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x808003DC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808003E0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808003E4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808003E8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808003EC: jal         0x800DC178
    // 0x808003F0: nop

    func_800DC178(rdram, ctx);
        goto after_23;
    // 0x808003F0: nop

    after_23:
    // 0x808003F4: b           L_80800458
    // 0x808003F8: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_80800458;
    // 0x808003F8: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_808003FC:
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800400: jal         0x80105230
    // 0x80800404: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80105230(rdram, ctx);
        goto after_24;
    // 0x80800404: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
    // 0x80800408: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x8080040C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800414: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x80800418: jal         0x80102BF8
    // 0x8080041C: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    func_80102BF8(rdram, ctx);
        goto after_25;
    // 0x8080041C: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    after_25:
    // 0x80800420: jal         0x808004B4
    // 0x80800424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004B4_chbottlesfamily(rdram, ctx);
        goto after_26;
    // 0x80800424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80800428: bne         $v0, $zero, L_80800458
    if (ctx->r2 != 0) {
        // 0x8080042C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800458;
    }
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800430: jal         0x80102CF4
    // 0x80800434: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    func_80102CF4(rdram, ctx);
        goto after_27;
    // 0x80800434: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_27:
    // 0x80800438: beq         $v0, $zero, L_80800458
    if (ctx->r2 == 0) {
        // 0x8080043C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800458;
    }
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800440: jal         0x80102424
    // 0x80800444: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_28;
    // 0x80800444: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_28:
    // 0x80800448: b           L_8080045C
    // 0x8080044C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8080045C;
    // 0x8080044C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800450:
    // 0x80800450: jal         0x808005D0
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005D0_chbottlesfamily(rdram, ctx);
        goto after_29;
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
L_80800458:
    // 0x80800458: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080045C:
    // 0x8080045C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800460: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800464: jr          $ra
    // 0x80800468: nop

    return;
    // 0x80800468: nop

;}
RECOMP_FUNC void chdragonbrothers_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804490: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1852, 0X58A8) << 16);
    // 0x80804494: jr          $ra
    // 0x80804498: addiu       $v0, $v0, 0x58A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1852, 0X58A8));
    return;
    // 0x80804498: addiu       $v0, $v0, 0x58A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1852, 0X58A8));
;}
RECOMP_FUNC void bsstonehead_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800814: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800818: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080081C: jal         0x80085230
    // 0x80800820: nop

    _basudie_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800820: nop

    after_0:
    // 0x80800824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800828: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080082C: jr          $ra
    // 0x80800830: nop

    return;
    // 0x80800830: nop

;}
RECOMP_FUNC void func_80800138_chtempleinternaldoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800138: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080013C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800140: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800144: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800148: bne         $a1, $at, L_8080015C
    if (ctx->r5 != ctx->r1) {
        // 0x8080014C: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_8080015C;
    }
    // 0x8080014C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800150: jal         0x80800178
    // 0x80800154: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80800178_chtempleinternaldoor(rdram, ctx);
        goto after_0;
    // 0x80800154: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800158: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_8080015C:
    // 0x8080015C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800160: jal         0x80086248
    // 0x80800164: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chdoor_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800164: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080016C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800170: jr          $ra
    // 0x80800174: nop

    return;
    // 0x80800174: nop

;}
RECOMP_FUNC void _bstaxi_entrypoint_33(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083ED0: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083ED0);
    return;
    // 0x80083ED4: addi        $t0, $zero, 0x84
    ctx->r8 = ADD32(0, 0X84);
;}
RECOMP_FUNC void bsbswim_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D1C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800D20: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(120, 0X1EA0) << 16);
    // 0x80800D24: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800D28: jr          $ra
    // 0x80800D2C: lw          $v0, 0x1EA0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1EA0));
    return;
    // 0x80800D2C: lw          $v0, 0x1EA0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1EA0));
;}
RECOMP_FUNC void ncpoducam_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080011C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800120: sh          $a2, 0x58($a0)
    MEM_H(0X58, ctx->r4) = ctx->r6;
    // 0x80800124: jal         0x8080145C
    // 0x80800128: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080145C_ncpoducam(rdram, ctx);
        goto after_0;
    // 0x80800128: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8080012C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800130: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800134: jr          $ra
    // 0x80800138: nop

    return;
    // 0x80800138: nop

;}
RECOMP_FUNC void func_8009D454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D454: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009D458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009D45C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8009D460: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8009D464: jal         0x8009C128
    // 0x8009D468: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8009D468: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8009D46C: lbu         $a0, 0x2F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2F);
    // 0x8009D470: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8009D474: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009D478: bnel        $a0, $zero, L_8009D490
    if (ctx->r4 != 0) {
        // 0x8009D47C: addiu       $a1, $sp, 0x1C
        ctx->r5 = ADD32(ctx->r29, 0X1C);
            goto L_8009D490;
    }
    goto skip_0;
    // 0x8009D47C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    skip_0:
    // 0x8009D480: jal         0x800C4350
    // 0x8009D484: addiu       $a2, $a2, -0x6DF0
    ctx->r6 = ADD32(ctx->r6, -0X6DF0);
    func_800C4350(rdram, ctx);
        goto after_1;
    // 0x8009D484: addiu       $a2, $a2, -0x6DF0
    ctx->r6 = ADD32(ctx->r6, -0X6DF0);
    after_1:
    // 0x8009D488: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8009D48C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
L_8009D490:
    // 0x8009D490: jal         0x800C4350
    // 0x8009D494: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_800C4350(rdram, ctx);
        goto after_2;
    // 0x8009D494: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x8009D498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009D49C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009D4A0: jr          $ra
    // 0x8009D4A4: nop

    return;
    // 0x8009D4A4: nop

;}
RECOMP_FUNC void _bsbflap_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082910: syscall     20
    recomp_syscall_handler(rdram, ctx, 0x80082910);
    return;
    // 0x80082914: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080043C_chfactorymaindoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080043C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800440: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800448: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080044C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800450: bne         $a1, $at, L_8080046C
    if (ctx->r5 != ctx->r1) {
        // 0x80800454: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8080046C;
    }
    // 0x80800454: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800458: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x8080045C: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
    // 0x80800460: jal         0x800887D8
    // 0x80800464: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800464: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800468: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_8080046C:
    // 0x8080046C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800470: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800474: jal         0x800857F8
    // 0x80800478: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chswitch_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800478: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080047C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800480: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800484: jr          $ra
    // 0x80800488: nop

    return;
    // 0x80800488: nop

;}
RECOMP_FUNC void func_80101CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101CDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101CE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101CE4: jal         0x80104248
    // 0x80101CE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80104248(rdram, ctx);
        goto after_0;
    // 0x80101CE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80101CEC: beq         $v0, $zero, L_80101CFC
    if (ctx->r2 == 0) {
        // 0x80101CF0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80101CFC;
    }
    // 0x80101CF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80101CF4: jal         0x8008B1BC
    // 0x80101CF8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    anctrl_setDuration(rdram, ctx);
        goto after_1;
    // 0x80101CF8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
L_80101CFC:
    // 0x80101CFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101D00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101D04: jr          $ra
    // 0x80101D08: nop

    return;
    // 0x80101D08: nop

;}
RECOMP_FUNC void func_80800000_chlavaarchgrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8080000C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800010: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800014: swc1        $f4, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f4.u32l;
    // 0x80800018: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8080001C: addiu       $a0, $zero, 0xA1A
    ctx->r4 = ADD32(0, 0XA1A);
    // 0x80800020: jal         0x800DA7A8
    // 0x80800024: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800DA7A8(rdram, ctx);
        goto after_0;
    // 0x80800024: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x80800028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080002C: jal         0x8010A800
    // 0x80800030: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A800(rdram, ctx);
        goto after_1;
    // 0x80800030: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080003C: jr          $ra
    // 0x80800040: nop

    return;
    // 0x80800040: nop

;}
RECOMP_FUNC void func_80800088_chmrsboggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800088: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080008C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800090: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800094: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800098: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8080009C: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x808000A0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808000A8: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x808000AC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808000B0: jal         0x80089F20
    // 0x808000B4: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808000B4: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    after_0:
    // 0x808000B8: jal         0x80089828
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suexpression_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000C0: beql        $v0, $zero, L_808000E4
    if (ctx->r2 == 0) {
        // 0x808000C4: lhu         $t7, 0x72($s0)
        ctx->r15 = MEM_HU(ctx->r16, 0X72);
            goto L_808000E4;
    }
    goto skip_0;
    // 0x808000C4: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x808000C8: jal         0x80089828
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suexpression_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000D4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x808000D8: jal         0x800897D8
    // 0x808000DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x808000DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x808000E0: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
L_808000E4:
    // 0x808000E4: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808000E8: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x808000EC: sltiu       $at, $t9, 0x8
    ctx->r1 = ctx->r25 < 0X8 ? 1 : 0;
    // 0x808000F0: beq         $at, $zero, L_8080027C
    if (ctx->r1 == 0) {
        // 0x808000F4: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8080027C;
    }
    // 0x808000F4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808000F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(888, 0X9C0) << 16);
    // 0x808000FC: addu        $at, $at, $t9
    gpr jr_addend_80800104 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800100: lw          $t9, 0x9C0($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(888, 0X9C0));
    // 0x80800104: jr          $t9
    // 0x80800108: nop

    switch (jr_addend_80800104 >> 2) {
        case 0: goto L_8080010C; break;
        case 1: goto L_8080027C; break;
        case 2: goto L_8080017C; break;
        case 3: goto L_8080027C; break;
        case 4: goto L_8080019C; break;
        case 5: goto L_8080011C; break;
        case 6: goto L_8080027C; break;
        case 7: goto L_80800248; break;
        default: switch_error(__func__, 0x80800104, 0x808009C0);
    }
    // 0x80800108: nop

L_8080010C:
    // 0x8080010C: jal         0x80800568
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800568_chmrsboggy(rdram, ctx);
        goto after_4;
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800114: b           L_80800280
    // 0x80800118: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800280;
    // 0x80800118: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080011C:
    // 0x8080011C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(888, 0XB20) << 16);
    // 0x80800120: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(888, 0XA58) << 16);
    // 0x80800124: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80800128: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8080012C: addiu       $a3, $a3, 0xA58
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(888, 0XA58));
    // 0x80800130: addiu       $a2, $a2, 0xB20
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(888, 0XB20));
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800138: jal         0x8008A1F0
    // 0x8080013C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x8080013C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80800140: beq         $v0, $zero, L_8080027C
    if (ctx->r2 == 0) {
        // 0x80800144: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8080027C;
    }
    // 0x80800144: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800148: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(888, 0XA58) << 16);
    // 0x8080014C: addiu       $a2, $a2, 0xA58
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(888, 0XA58));
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800154: jal         0x8008A1F8
    // 0x80800158: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x80800158: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_6:
    // 0x8080015C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800160: beq         $v0, $at, L_8080027C
    if (ctx->r2 == ctx->r1) {
        // 0x80800164: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080027C;
    }
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800168: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080016C: jal         0x808007CC
    // 0x80800170: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_808007CC_chmrsboggy(rdram, ctx);
        goto after_7;
    // 0x80800170: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80800174: b           L_80800280
    // 0x80800178: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800280;
    // 0x80800178: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080017C:
    // 0x8080017C: jal         0x80101DDC
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_8;
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800184: beq         $v0, $zero, L_8080027C
    if (ctx->r2 == 0) {
        // 0x80800188: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080027C;
    }
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080018C: jal         0x80102424
    // 0x80800190: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x80800190: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x80800194: b           L_80800280
    // 0x80800198: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800280;
    // 0x80800198: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080019C:
    // 0x8080019C: jal         0x80101DDC
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_10;
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808001A4: beql        $v0, $zero, L_80800280
    if (ctx->r2 == 0) {
        // 0x808001A8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800280;
    }
    goto skip_1;
    // 0x808001A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808001AC: jal         0x800F54E4
    // 0x808001B0: nop

    func_800F54E4(rdram, ctx);
        goto after_11;
    // 0x808001B0: nop

    after_11:
    // 0x808001B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001B8: jal         0x800F82D4
    // 0x808001BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_12;
    // 0x808001BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x808001C0: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    // 0x808001C4: jal         0x800DA980
    // 0x808001C8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA980(rdram, ctx);
        goto after_13;
    // 0x808001C8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
    // 0x808001CC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808001D0: bne         $v0, $at, L_80800218
    if (ctx->r2 != ctx->r1) {
        // 0x808001D4: addiu       $a0, $zero, 0x142
        ctx->r4 = ADD32(0, 0X142);
            goto L_80800218;
    }
    // 0x808001D4: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001DC: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x808001E0: jal         0x80800910
    // 0x808001E4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_80800910_chmrsboggy(rdram, ctx);
        goto after_14;
    // 0x808001E4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_14:
    // 0x808001E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808001EC: addiu       $t1, $zero, 0x3E
    ctx->r9 = ADD32(0, 0X3E);
    // 0x808001F0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808001F4: addiu       $a1, $zero, 0x109E
    ctx->r5 = ADD32(0, 0X109E);
    // 0x808001F8: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    // 0x808001FC: jal         0x8008A208
    // 0x80800200: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_15;
    // 0x80800200: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_15:
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800208: jal         0x80102424
    // 0x8080020C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_16;
    // 0x8080020C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_16:
    // 0x80800210: b           L_80800280
    // 0x80800214: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800280;
    // 0x80800214: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800218:
    // 0x80800218: jal         0x80089C30
    // 0x8080021C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_17;
    // 0x8080021C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800224: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80800228: addiu       $a2, $zero, 0x31
    ctx->r6 = ADD32(0, 0X31);
    // 0x8080022C: jal         0x80800878
    // 0x80800230: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    func_80800878_chmrsboggy(rdram, ctx);
        goto after_18;
    // 0x80800230: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    after_18:
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800238: jal         0x80102424
    // 0x8080023C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_19;
    // 0x8080023C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80800240: b           L_80800280
    // 0x80800244: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800280;
    // 0x80800244: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800248:
    // 0x80800248: jal         0x80105834
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_20;
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800254: jal         0x80105230
    // 0x80800258: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80105230(rdram, ctx);
        goto after_21;
    // 0x80800258: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x8080025C: jal         0x80105A5C
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_22;
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800264: beql        $v0, $zero, L_80800280
    if (ctx->r2 == 0) {
        // 0x80800268: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800280;
    }
    goto skip_2;
    // 0x80800268: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8080026C: jal         0x80800790
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800790_chmrsboggy(rdram, ctx);
        goto after_23;
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800274: jal         0x800FFAB0
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_24;
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
L_8080027C:
    // 0x8080027C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800280:
    // 0x80800280: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800284: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800288: jr          $ra
    // 0x8080028C: nop

    return;
    // 0x8080028C: nop

;}
RECOMP_FUNC void sujiggy_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080077C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800780: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800784: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800788: jal         0x80088840
    // 0x8080078C: addiu       $a0, $a0, 0x7A
    ctx->r4 = ADD32(ctx->r4, 0X7A);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x8080078C: addiu       $a0, $a0, 0x7A
    ctx->r4 = ADD32(ctx->r4, 0X7A);
    after_0:
    // 0x80800790: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800794: beq         $t6, $zero, L_808007C4
    if (ctx->r14 == 0) {
        // 0x80800798: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_808007C4;
    }
    // 0x80800798: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8080079C: jal         0x808000E8
    // 0x808007A0: nop

    sujiggy_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808007A0: nop

    after_1:
    // 0x808007A4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x808007A8: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808007AC: beql        $v0, $zero, L_808007C8
    if (ctx->r2 == 0) {
        // 0x808007B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808007C8;
    }
    goto skip_0;
    // 0x808007B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808007B4: jal         0x800DA298
    // 0x808007B8: addiu       $a0, $v1, 0x392
    ctx->r4 = ADD32(ctx->r3, 0X392);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x808007B8: addiu       $a0, $v1, 0x392
    ctx->r4 = ADD32(ctx->r3, 0X392);
    after_2:
    // 0x808007BC: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808007C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_808007C4:
    // 0x808007C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007C8:
    // 0x808007C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007CC: jr          $ra
    // 0x808007D0: nop

    return;
    // 0x808007D0: nop

;}
RECOMP_FUNC void func_8010A800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A800: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8010A804: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8010A808: sllv        $t8, $t6, $a1
    ctx->r24 = S32(ctx->r14 << (ctx->r5 & 31));
    // 0x8010A80C: lhu         $t1, 0x2A($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X2A);
    // 0x8010A810: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8010A814: andi        $t0, $t9, 0x1FE
    ctx->r8 = ctx->r25 & 0X1FE;
    // 0x8010A818: andi        $t2, $t1, 0xFE01
    ctx->r10 = ctx->r9 & 0XFE01;
    // 0x8010A81C: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x8010A820: jr          $ra
    // 0x8010A824: sh          $t3, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r11;
    return;
    // 0x8010A824: sh          $t3, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r11;
;}
RECOMP_FUNC void func_80800240_chlagoonfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800240: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800244: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800248: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080024C: jal         0x80100074
    // 0x80800250: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80100074(rdram, ctx);
        goto after_0;
    // 0x80800250: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080025C: jr          $ra
    // 0x80800260: nop

    return;
    // 0x80800260: nop

;}
