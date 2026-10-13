#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _baboost_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084590: syscall     115
    recomp_syscall_handler(rdram, ctx, 0x80084590);
    return;
    // 0x80084594: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void gcnewoption_entrypoint_36(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802B14: lbu         $t7, 0x1C($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1C);
    // 0x80802B18: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80802B1C: jr          $ra
    // 0x80802B20: sb          $t8, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r24;
    return;
    // 0x80802B20: sb          $t8, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void _chcrusher_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A98: syscall     413
    recomp_syscall_handler(rdram, ctx, 0x80086A98);
    return;
    // 0x80086A9C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800914FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800914FC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80091500: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091504: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091508: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8009150C: jal         0x80091290
    // 0x80091510: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_80091290(rdram, ctx);
        goto after_0;
    // 0x80091510: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x80091514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80091518: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009151C: jr          $ra
    // 0x80091520: nop

    return;
    // 0x80091520: nop

    // 0x80091524: nop

    // 0x80091528: nop

    // 0x8009152C: nop

;}
RECOMP_FUNC void func_808001F4_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800200: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800204: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800208: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8080020C: jal         0x80100094
    // 0x80800210: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800210: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800214: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800218: lbu         $v1, 0x95($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X95);
    // 0x8080021C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800220: beql        $v1, $zero, L_80800254
    if (ctx->r3 == 0) {
        // 0x80800224: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_80800254;
    }
    goto skip_0;
    // 0x80800224: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80800228: beq         $v1, $at, L_80800270
    if (ctx->r3 == ctx->r1) {
        // 0x8080022C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800270;
    }
    // 0x8080022C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800230: beq         $v1, $at, L_80800264
    if (ctx->r3 == ctx->r1) {
        // 0x80800234: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800264;
    }
    // 0x80800234: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800238: bnel        $v1, $at, L_80800284
    if (ctx->r3 != ctx->r1) {
        // 0x8080023C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800284;
    }
    goto skip_1;
    // 0x8080023C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800240: jal         0x800F54E4
    // 0x80800244: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800244: nop

    after_1:
    // 0x80800248: jal         0x800F4B20
    // 0x8080024C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F4B20(rdram, ctx);
        goto after_2;
    // 0x8080024C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800250: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
L_80800254:
    // 0x80800254: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800258: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8080025C: jal         0x800856B0
    // 0x80800260: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800260: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_3:
L_80800264:
    // 0x80800264: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80800268: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080026C: sb          $t7, 0x95($t8)
    MEM_B(0X95, ctx->r24) = ctx->r15;
L_80800270:
    // 0x80800270: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800274: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800278: jal         0x800856D0
    // 0x8080027C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x8080027C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80800280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800284:
    // 0x80800284: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800288: jr          $ra
    // 0x8080028C: nop

    return;
    // 0x8080028C: nop

;}
RECOMP_FUNC void _bashoes_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085050: syscall     148
    recomp_syscall_handler(rdram, ctx, 0x80085050);
    return;
    // 0x80085054: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void ncpoducam_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808016B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808016BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808016C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808016C4: lbu         $v0, 0x60($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X60);
    // 0x808016C8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808016CC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808016D0: beq         $v0, $at, L_80801704
    if (ctx->r2 == ctx->r1) {
        // 0x808016D4: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80801704;
    }
    // 0x808016D4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808016D8: beq         $v0, $at, L_80801704
    if (ctx->r2 == ctx->r1) {
        // 0x808016DC: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80801704;
    }
    // 0x808016DC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x808016E0: bnel        $v0, $at, L_80801724
    if (ctx->r2 != ctx->r1) {
        // 0x808016E4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80801724;
    }
    goto skip_0;
    // 0x808016E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x808016E8: jal         0x8001B798
    // 0x808016EC: lh          $a0, 0x2($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X2);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x808016EC: lh          $a0, 0x2($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X2);
    after_0:
    // 0x808016F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808016F4: jal         0x80089E48
    // 0x808016F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _susplinet_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x808016F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x808016FC: b           L_80801728
    // 0x80801700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801728;
    // 0x80801700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801704:
    // 0x80801704: jal         0x8001B798
    // 0x80801708: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    func_8001B798(rdram, ctx);
        goto after_2;
    // 0x80801708: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    after_2:
    // 0x8080170C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801710: jal         0x80089D88
    // 0x80801714: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _suspline_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80801714: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80801718: b           L_80801728
    // 0x8080171C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801728;
    // 0x8080171C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801720: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801724:
    // 0x80801724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801728:
    // 0x80801728: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080172C: jr          $ra
    // 0x80801730: nop

    return;
    // 0x80801730: nop

;}
RECOMP_FUNC void _bssub_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083D58: syscall     93
    recomp_syscall_handler(rdram, ctx, 0x80083D58);
    return;
    // 0x80083D5C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _chintrotext_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800861A0: syscall     285
    recomp_syscall_handler(rdram, ctx, 0x800861A0);
    return;
    // 0x800861A4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bsstonehead_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800834: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800838: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(376, 0X1640) << 16);
    // 0x8080083C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800840: jr          $ra
    // 0x80800844: lw          $v0, 0x1640($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(376, 0X1640));
    return;
    // 0x80800844: lw          $v0, 0x1640($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(376, 0X1640));
;}
RECOMP_FUNC void func_800FC1CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC1CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FC1D0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800FC1D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FC1D8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800FC1DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FC1E0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FC1E4: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800FC1E8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800FC1EC: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800FC1F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800FC1F4: addiu       $s3, $s3, 0x5960
    ctx->r19 = ADD32(ctx->r19, 0X5960);
    // 0x800FC1F8: addiu       $s0, $s0, 0x57D0
    ctx->r16 = ADD32(ctx->r16, 0X57D0);
    // 0x800FC1FC: lh          $a0, 0x28($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X28);
L_800FC200:
    // 0x800FC200: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800FC204: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800FC208: bltzl       $a0, L_800FC21C
    if (SIGNED(ctx->r4) < 0) {
        // 0x800FC20C: addiu       $s0, $s0, 0x50
        ctx->r16 = ADD32(ctx->r16, 0X50);
            goto L_800FC21C;
    }
    goto skip_0;
    // 0x800FC20C: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
    skip_0:
    // 0x800FC210: jal         0x800FCB00
    // 0x800FC214: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800FCB00(rdram, ctx);
        goto after_0;
    // 0x800FC214: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x800FC218: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
L_800FC21C:
    // 0x800FC21C: bnel        $s0, $s3, L_800FC200
    if (ctx->r16 != ctx->r19) {
        // 0x800FC220: lh          $a0, 0x28($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X28);
            goto L_800FC200;
    }
    goto skip_1;
    // 0x800FC220: lh          $a0, 0x28($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X28);
    skip_1:
    // 0x800FC224: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800FC228: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FC22C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FC230: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800FC234: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800FC238: jr          $ra
    // 0x800FC23C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800FC23C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800710_chseaweedbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800710: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800714: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800718: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080071C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800720: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800724: jal         0x80100094
    // 0x80800728: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800728: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080072C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800730: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800734: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80800738: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x8080073C: beq         $at, $zero, L_808007C4
    if (ctx->r1 == 0) {
        // 0x80800740: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_808007C4;
    }
    // 0x80800740: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800744: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1024, 0XE08) << 16);
    // 0x80800748: addu        $at, $at, $t7
    gpr jr_addend_80800750 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8080074C: lw          $t7, 0xE08($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1024, 0XE08));
    // 0x80800750: jr          $t7
    // 0x80800754: nop

    switch (jr_addend_80800750 >> 2) {
        case 0: goto L_80800758; break;
        case 1: goto L_8080076C; break;
        case 2: goto L_80800780; break;
        case 3: goto L_808007C4; break;
        case 4: goto L_808007C4; break;
        case 5: goto L_808007A0; break;
        case 6: goto L_808007B8; break;
        default: switch_error(__func__, 0x80800750, 0x80800E08);
    }
    // 0x80800754: nop

L_80800758:
    // 0x80800758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080075C: jal         0x8008A4B0
    // 0x80800760: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800760: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800764: b           L_808007C8
    // 0x80800768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808007C8;
    // 0x80800768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080076C:
    // 0x8080076C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800770: jal         0x8008A4B0
    // 0x80800774: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800774: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800778: b           L_808007C8
    // 0x8080077C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808007C8;
    // 0x8080077C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800780:
    // 0x80800780: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800784: jal         0x8010D254
    // 0x80800788: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8010D254(rdram, ctx);
        goto after_3;
    // 0x80800788: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_3:
    // 0x8080078C: jal         0x8010CD28
    // 0x80800790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_4;
    // 0x80800790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800794: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800798: b           L_808007C4
    // 0x8080079C: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
        goto L_808007C4;
    // 0x8080079C: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
L_808007A0:
    // 0x808007A0: jal         0x800EE7F8
    // 0x808007A4: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x808007A4: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_5:
    // 0x808007A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1024, 0XE24) << 16);
    // 0x808007AC: lwc1        $f4, 0xE24($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1024, 0XE24));
    // 0x808007B0: b           L_808007C4
    // 0x808007B4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_808007C4;
    // 0x808007B4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_808007B8:
    // 0x808007B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1024, 0XE28) << 16);
    // 0x808007BC: lwc1        $f6, 0xE28($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1024, 0XE28));
    // 0x808007C0: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_808007C4:
    // 0x808007C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808007C8:
    // 0x808007C8: jal         0x80102424
    // 0x808007CC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x808007CC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x808007D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808007D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808007D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808007DC: jr          $ra
    // 0x808007E0: nop

    return;
    // 0x808007E0: nop

;}
RECOMP_FUNC void func_800F8AA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8AA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F8AA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8AAC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F8AB0: jal         0x800B28C4
    // 0x800F8AB4: lw          $a0, 0x54F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X54F0);
    vector_begin(rdram, ctx);
        goto after_0;
    // 0x800F8AB4: lw          $a0, 0x54F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X54F0);
    after_0:
    // 0x800F8AB8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F8ABC: lw          $a0, 0x54F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X54F0);
    // 0x800F8AC0: jal         0x800B296C
    // 0x800F8AC4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    vector_end(rdram, ctx);
        goto after_1;
    // 0x800F8AC4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800F8AC8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800F8ACC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800F8AD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8AD4: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800F8AD8: beq         $at, $zero, L_800F8B04
    if (ctx->r1 == 0) {
        // 0x800F8ADC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800F8B04;
    }
    // 0x800F8ADC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F8AE0: lbu         $t6, 0x1($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1);
L_800F8AE4:
    // 0x800F8AE4: beql        $t6, $zero, L_800F8AF8
    if (ctx->r14 == 0) {
        // 0x800F8AE8: addiu       $v1, $v1, 0x3C
        ctx->r3 = ADD32(ctx->r3, 0X3C);
            goto L_800F8AF8;
    }
    goto skip_0;
    // 0x800F8AE8: addiu       $v1, $v1, 0x3C
    ctx->r3 = ADD32(ctx->r3, 0X3C);
    skip_0:
    // 0x800F8AEC: b           L_800F8B04
    // 0x800F8AF0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
        goto L_800F8B04;
    // 0x800F8AF0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800F8AF4: addiu       $v1, $v1, 0x3C
    ctx->r3 = ADD32(ctx->r3, 0X3C);
L_800F8AF8:
    // 0x800F8AF8: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x800F8AFC: bnel        $at, $zero, L_800F8AE4
    if (ctx->r1 != 0) {
        // 0x800F8B00: lbu         $t6, 0x1($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X1);
            goto L_800F8AE4;
    }
    goto skip_1;
    // 0x800F8B00: lbu         $t6, 0x1($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1);
    skip_1:
L_800F8B04:
    // 0x800F8B04: jr          $ra
    // 0x800F8B08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800F8B08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void bsbflip_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808003FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800400: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800404: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800408: jal         0x8008CABC
    // 0x8080040C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080040C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800410: lui         $a1, 0x3E75
    ctx->r5 = S32(0X3E75 << 16);
    // 0x80800414: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800418: ori         $a1, $a1, 0x2546
    ctx->r5 = ctx->r5 | 0X2546;
    // 0x8080041C: jal         0x8008B348
    // 0x80800420: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isAt(rdram, ctx);
        goto after_1;
    // 0x80800420: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800424: beql        $v0, $zero, L_8080046C
    if (ctx->r2 == 0) {
        // 0x80800428: lw          $v0, 0x15C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X15C);
            goto L_8080046C;
    }
    goto skip_0;
    // 0x80800428: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    skip_0:
    // 0x8080042C: jal         0x8008B284
    // 0x80800430: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_getPlaybackType(rdram, ctx);
        goto after_2;
    // 0x80800430: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800434: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800438: beql        $v0, $at, L_8080046C
    if (ctx->r2 == ctx->r1) {
        // 0x8080043C: lw          $v0, 0x15C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X15C);
            goto L_8080046C;
    }
    goto skip_1;
    // 0x8080043C: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    skip_1:
    // 0x80800440: jal         0x8008B264
    // 0x80800444: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_getIndex(rdram, ctx);
        goto after_3;
    // 0x80800444: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800448: addiu       $at, $zero, 0x4B
    ctx->r1 = ADD32(0, 0X4B);
    // 0x8080044C: bne         $v0, $at, L_80800468
    if (ctx->r2 != ctx->r1) {
        // 0x80800450: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800468;
    }
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800454: lui         $a2, 0x3F0E
    ctx->r6 = S32(0X3F0E << 16);
    // 0x80800458: ori         $a2, $a2, 0xD917
    ctx->r6 = ctx->r6 | 0XD917;
    // 0x8080045C: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    // 0x80800460: jal         0x8009DF94
    // 0x80800464: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    func_8009DF94(rdram, ctx);
        goto after_4;
    // 0x80800464: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    after_4:
L_80800468:
    // 0x80800468: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
L_8080046C:
    // 0x8080046C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800470: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800474: beq         $v0, $at, L_808004A0
    if (ctx->r2 == ctx->r1) {
        // 0x80800478: lui         $a1, 0x3E3C
        ctx->r5 = S32(0X3E3C << 16);
            goto L_808004A0;
    }
    // 0x80800478: lui         $a1, 0x3E3C
    ctx->r5 = S32(0X3E3C << 16);
    // 0x8080047C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800480: beq         $v0, $at, L_808004C0
    if (ctx->r2 == ctx->r1) {
        // 0x80800484: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808004C0;
    }
    // 0x80800484: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800488: beq         $v0, $at, L_8080050C
    if (ctx->r2 == ctx->r1) {
        // 0x8080048C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080050C;
    }
    // 0x8080048C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800490: beq         $v0, $at, L_80800594
    if (ctx->r2 == ctx->r1) {
        // 0x80800494: nop
    
            goto L_80800594;
    }
    // 0x80800494: nop

    // 0x80800498: b           L_808005B8
    // 0x8080049C: nop

        goto L_808005B8;
    // 0x8080049C: nop

L_808004A0:
    // 0x808004A0: jal         0x8008B348
    // 0x808004A4: ori         $a1, $a1, 0x1BDA
    ctx->r5 = ctx->r5 | 0X1BDA;
    anctrl_isAt(rdram, ctx);
        goto after_5;
    // 0x808004A4: ori         $a1, $a1, 0x1BDA
    ctx->r5 = ctx->r5 | 0X1BDA;
    after_5:
    // 0x808004A8: beq         $v0, $zero, L_808005B8
    if (ctx->r2 == 0) {
        // 0x808004AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005B8;
    }
    // 0x808004AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B0: jal         0x80800064
    // 0x808004B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800064_bsbflip(rdram, ctx);
        goto after_6;
    // 0x808004B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x808004B8: b           L_808005B8
    // 0x808004BC: nop

        goto L_808005B8;
    // 0x808004BC: nop

L_808004C0:
    // 0x808004C0: jal         0x80800000
    // 0x808004C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsbflip(rdram, ctx);
        goto after_7;
    // 0x808004C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808004C8: jal         0x8008B324
    // 0x808004CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_8;
    // 0x808004CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_8:
    // 0x808004D0: beq         $v0, $zero, L_808004E0
    if (ctx->r2 == 0) {
        // 0x808004D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004E0;
    }
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D8: jal         0x80800064
    // 0x808004DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800064_bsbflip(rdram, ctx);
        goto after_9;
    // 0x808004DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
L_808004E0:
    // 0x808004E0: jal         0x80097A90
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_beak_bust(rdram, ctx);
        goto after_10;
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808004E8: beq         $v0, $zero, L_808004F4
    if (ctx->r2 == 0) {
        // 0x808004EC: addiu       $t6, $zero, 0xF
        ctx->r14 = ADD32(0, 0XF);
            goto L_808004F4;
    }
    // 0x808004EC: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x808004F0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_808004F4:
    // 0x808004F4: jal         0x8008DA24
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DA24(rdram, ctx);
        goto after_11;
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808004FC: beq         $v0, $zero, L_808005B8
    if (ctx->r2 == 0) {
        // 0x80800500: addiu       $t7, $zero, 0xA8
        ctx->r15 = ADD32(0, 0XA8);
            goto L_808005B8;
    }
    // 0x80800500: addiu       $t7, $zero, 0xA8
    ctx->r15 = ADD32(0, 0XA8);
    // 0x80800504: b           L_808005B8
    // 0x80800508: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
        goto L_808005B8;
    // 0x80800508: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_8080050C:
    // 0x8080050C: jal         0x8008E260
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E260(rdram, ctx);
        goto after_12;
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800514: beq         $v0, $zero, L_80800524
    if (ctx->r2 == 0) {
        // 0x80800518: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800524;
    }
    // 0x80800518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080051C: addiu       $t8, $zero, 0x3D
    ctx->r24 = ADD32(0, 0X3D);
    // 0x80800520: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80800524:
    // 0x80800524: jal         0x80091A30
    // 0x80800528: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_13;
    // 0x80800528: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_13:
    // 0x8080052C: beq         $v0, $zero, L_80800538
    if (ctx->r2 == 0) {
        // 0x80800530: addiu       $t9, $zero, 0x2F
        ctx->r25 = ADD32(0, 0X2F);
            goto L_80800538;
    }
    // 0x80800530: addiu       $t9, $zero, 0x2F
    ctx->r25 = ADD32(0, 0X2F);
    // 0x80800534: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_80800538:
    // 0x80800538: jal         0x8008E078
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_14;
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800540: beq         $v0, $zero, L_80800568
    if (ctx->r2 == 0) {
        // 0x80800544: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800568;
    }
    // 0x80800544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800548: jal         0x800A01F8
    // 0x8080054C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800A01F8(rdram, ctx);
        goto after_15;
    // 0x8080054C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_15:
    // 0x80800550: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800558: jal         0x80800064
    // 0x8080055C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800064_bsbflip(rdram, ctx);
        goto after_16;
    // 0x8080055C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_16:
    // 0x80800560: b           L_808005B8
    // 0x80800564: nop

        goto L_808005B8;
    // 0x80800564: nop

L_80800568:
    // 0x80800568: jal         0x80097A90
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_beak_bust(rdram, ctx);
        goto after_17;
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800570: beq         $v0, $zero, L_8080057C
    if (ctx->r2 == 0) {
        // 0x80800574: addiu       $t0, $zero, 0xF
        ctx->r8 = ADD32(0, 0XF);
            goto L_8080057C;
    }
    // 0x80800574: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x80800578: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_8080057C:
    // 0x8080057C: jal         0x8008DA24
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DA24(rdram, ctx);
        goto after_18;
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800584: beq         $v0, $zero, L_808005B8
    if (ctx->r2 == 0) {
        // 0x80800588: addiu       $t1, $zero, 0xA8
        ctx->r9 = ADD32(0, 0XA8);
            goto L_808005B8;
    }
    // 0x80800588: addiu       $t1, $zero, 0xA8
    ctx->r9 = ADD32(0, 0XA8);
    // 0x8080058C: b           L_808005B8
    // 0x80800590: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
        goto L_808005B8;
    // 0x80800590: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_80800594:
    // 0x80800594: jal         0x8008B324
    // 0x80800598: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_19;
    // 0x80800598: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_19:
    // 0x8080059C: beq         $v0, $zero, L_808005AC
    if (ctx->r2 == 0) {
        // 0x808005A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005AC;
    }
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A4: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x808005A8: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
L_808005AC:
    // 0x808005AC: jal         0x800A01F8
    // 0x808005B0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800A01F8(rdram, ctx);
        goto after_20;
    // 0x808005B0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_20:
    // 0x808005B4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_808005B8:
    // 0x808005B8: jal         0x8008E35C
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_21;
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808005C0: beq         $v0, $zero, L_808005D0
    if (ctx->r2 == 0) {
        // 0x808005C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005D0;
    }
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C8: addiu       $t3, $zero, 0x4C
    ctx->r11 = ADD32(0, 0X4C);
    // 0x808005CC: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
L_808005D0:
    // 0x808005D0: jal         0x8009E5C8
    // 0x808005D4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_22;
    // 0x808005D4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_22:
    // 0x808005D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005E4: jr          $ra
    // 0x808005E8: nop

    return;
    // 0x808005E8: nop

;}
RECOMP_FUNC void func_800A4074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4074: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A4078: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A407C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A4080: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A4084: jal         0x800A5A4C
    // 0x800A4088: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800A5A4C(rdram, ctx);
        goto after_0;
    // 0x800A4088: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800A408C: jal         0x80090B98
    // 0x800A4090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80090B98(rdram, ctx);
        goto after_1;
    // 0x800A4090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800A4094: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x800A4098: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A409C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A40A0: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x800A40A4: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x800A40A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A40AC: sb          $zero, 0x6($t7)
    MEM_B(0X6, ctx->r15) = 0;
    // 0x800A40B0: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x800A40B4: sb          $zero, 0x3($t8)
    MEM_B(0X3, ctx->r24) = 0;
    // 0x800A40B8: lw          $t9, 0x38($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X38);
    // 0x800A40BC: sb          $zero, 0x4($t9)
    MEM_B(0X4, ctx->r25) = 0;
    // 0x800A40C0: lw          $t0, 0x38($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X38);
    // 0x800A40C4: sb          $zero, 0x5($t0)
    MEM_B(0X5, ctx->r8) = 0;
    // 0x800A40C8: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x800A40CC: swc1        $f4, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->f4.u32l;
    // 0x800A40D0: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x800A40D4: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800A40D8: swc1        $f6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f6.u32l;
    // 0x800A40DC: jal         0x800A3F14
    // 0x800A40E0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800A3F14(rdram, ctx);
        goto after_2;
    // 0x800A40E0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x800A40E4: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x800A40E8: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800A40EC: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A40F0: sb          $t2, 0x2($t3)
    MEM_B(0X2, ctx->r11) = ctx->r10;
    // 0x800A40F4: lw          $t5, 0x38($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X38);
    // 0x800A40F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A40FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A4100: sb          $t4, 0x1($t5)
    MEM_B(0X1, ctx->r13) = ctx->r12;
    // 0x800A4104: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A4108: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A410C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A4110: jal         0x800A3DB8
    // 0x800A4114: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800A3DB8(rdram, ctx);
        goto after_3;
    // 0x800A4114: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x800A4118: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x800A411C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A4120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A4124: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A4128: jal         0x800A3EC8
    // 0x800A412C: sb          $t7, 0x7($t8)
    MEM_B(0X7, ctx->r24) = ctx->r15;
    func_800A3EC8(rdram, ctx);
        goto after_4;
    // 0x800A412C: sb          $t7, 0x7($t8)
    MEM_B(0X7, ctx->r24) = ctx->r15;
    after_4:
    // 0x800A4130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A4134: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800A4138: jal         0x80085338
    // 0x800A413C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    _batimer_set(rdram, ctx);
        goto after_5;
    // 0x800A413C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_5:
    // 0x800A4140: lw          $t0, 0x38($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X38);
    // 0x800A4144: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800A4148: sh          $t9, 0x36($t0)
    MEM_H(0X36, ctx->r8) = ctx->r25;
    // 0x800A414C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A4150: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A4154: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A4158: jr          $ra
    // 0x800A415C: nop

    return;
    // 0x800A415C: nop

;}
RECOMP_FUNC void func_80800000_bsbanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x8080000C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800010: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800014: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800018: jal         0x8009FFD8
    // 0x8080001C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x80800020: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800024: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800028: jr          $ra
    // 0x8080002C: nop

    return;
    // 0x8080002C: nop

;}
RECOMP_FUNC void func_8080013C_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080013C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800140: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800144: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800148: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080014C: jal         0x80100094
    // 0x80800150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800154: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800158: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8080015C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800160: jal         0x80800080
    // 0x80800164: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_80800080_chflysaucer(rdram, ctx);
        goto after_1;
    // 0x80800164: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x80800168: beq         $v0, $zero, L_808001A4
    if (ctx->r2 == 0) {
        // 0x8080016C: lw          $t6, 0x24($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X24);
            goto L_808001A4;
    }
    // 0x8080016C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800170: lh          $v1, 0x2A($t6)
    ctx->r3 = MEM_H(ctx->r14, 0X2A);
    // 0x80800174: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800178: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8080017C: beq         $at, $zero, L_808001A4
    if (ctx->r1 == 0) {
        // 0x80800180: sll         $t8, $v1, 3
        ctx->r24 = S32(ctx->r3 << 3);
            goto L_808001A4;
    }
    // 0x80800180: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x80800184: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80800188: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080018C: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80800190: slt         $at, $t0, $a1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80800194: beql        $at, $zero, L_808001A8
    if (ctx->r1 == 0) {
        // 0x80800198: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001A8;
    }
    goto skip_0;
    // 0x80800198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080019C: jal         0x80108B04
    // 0x808001A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80108B04(rdram, ctx);
        goto after_2;
    // 0x808001A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
L_808001A4:
    // 0x808001A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001A8:
    // 0x808001A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001AC: jr          $ra
    // 0x808001B0: nop

    return;
    // 0x808001B0: nop

;}
RECOMP_FUNC void _bstnt_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083F50: syscall     99
    recomp_syscall_handler(rdram, ctx, 0x80083F50);
    return;
    // 0x80083F54: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800058_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080005C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800060: jal         0x8009EF1C
    // 0x80800064: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x80800064: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800068: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8080006C: jal         0x8009EF10
    // 0x80800070: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x80800070: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800074: bne         $v0, $zero, L_80800090
    if (ctx->r2 != 0) {
        // 0x80800078: lwc1        $f12, 0x1C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_80800090;
    }
    // 0x80800078: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8080007C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800080: jal         0x8009B9B0
    // 0x80800084: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800084: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800088: b           L_808000B4
    // 0x8080008C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000B4;
    // 0x8080008C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800090:
    // 0x80800090: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800094: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800098: lui         $a2, 0x43BB
    ctx->r6 = S32(0X43BB << 16);
    // 0x8080009C: jal         0x800F1214
    // 0x808000A0: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x808000A0: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    after_3:
    // 0x808000A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000A8: jal         0x8009B9B0
    // 0x808000AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x808000AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x808000B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000B4:
    // 0x808000B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000B8: jr          $ra
    // 0x808000BC: nop

    return;
    // 0x808000BC: nop

;}
RECOMP_FUNC void baalarm_get_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
;}
RECOMP_FUNC void func_800EBD78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EBD78: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800EBD7C: lbu         $t6, 0x5450($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X5450);
    // 0x800EBD80: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800EBD84: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800EBD88: bne         $v0, $t6, L_800EBDB0
    if (ctx->r2 != ctx->r14) {
        // 0x800EBD8C: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_800EBDB0;
    }
    // 0x800EBD8C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800EBD90: addiu       $t0, $t0, 0x2ED0
    ctx->r8 = ADD32(ctx->r8, 0X2ED0);
    // 0x800EBD94: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800EBD98:
    // 0x800EBD98: slti        $at, $v1, 0x19
    ctx->r1 = SIGNED(ctx->r3) < 0X19 ? 1 : 0;
    // 0x800EBD9C: beq         $at, $zero, L_800EBDB0
    if (ctx->r1 == 0) {
        // 0x800EBDA0: addu        $t7, $t0, $v1
        ctx->r15 = ADD32(ctx->r8, ctx->r3);
            goto L_800EBDB0;
    }
    // 0x800EBDA0: addu        $t7, $t0, $v1
    ctx->r15 = ADD32(ctx->r8, ctx->r3);
    // 0x800EBDA4: lbu         $t8, 0x2580($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X2580);
    // 0x800EBDA8: beql        $v0, $t8, L_800EBD98
    if (ctx->r2 == ctx->r24) {
        // 0x800EBDAC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800EBD98;
    }
    goto skip_0;
    // 0x800EBDAC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
L_800EBDB0:
    // 0x800EBDB0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800EBDB4: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x800EBDB8: bne         $v1, $at, L_800EBDC8
    if (ctx->r3 != ctx->r1) {
        // 0x800EBDBC: addiu       $t0, $t0, 0x2ED0
        ctx->r8 = ADD32(ctx->r8, 0X2ED0);
            goto L_800EBDC8;
    }
    // 0x800EBDBC: addiu       $t0, $t0, 0x2ED0
    ctx->r8 = ADD32(ctx->r8, 0X2ED0);
    // 0x800EBDC0: jr          $ra
    // 0x800EBDC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800EBDC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800EBDC8:
    // 0x800EBDC8: addu        $a0, $t0, $v1
    ctx->r4 = ADD32(ctx->r8, ctx->r3);
    // 0x800EBDCC: lbu         $a1, 0x2580($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X2580);
    // 0x800EBDD0: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x800EBDD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800EBDD8: andi        $t9, $a1, 0x80
    ctx->r25 = ctx->r5 & 0X80;
    // 0x800EBDDC: beq         $t9, $zero, L_800EBDF8
    if (ctx->r25 == 0) {
        // 0x800EBDE0: sll         $t4, $v1, 2
        ctx->r12 = S32(ctx->r3 << 2);
            goto L_800EBDF8;
    }
    // 0x800EBDE0: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
L_800EBDE4:
    // 0x800EBDE4: sra         $t1, $a2, 1
    ctx->r9 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800EBDE8: and         $t2, $a1, $t1
    ctx->r10 = ctx->r5 & ctx->r9;
    // 0x800EBDEC: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800EBDF0: bne         $t2, $zero, L_800EBDE4
    if (ctx->r10 != 0) {
        // 0x800EBDF4: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800EBDE4;
    }
    // 0x800EBDF4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_800EBDF8:
    // 0x800EBDF8: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x800EBDFC: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x800EBE00: subu        $t6, $t6, $a3
    ctx->r14 = SUB32(ctx->r14, ctx->r7);
    // 0x800EBE04: sll         $t4, $t4, 7
    ctx->r12 = S32(ctx->r12 << 7);
    // 0x800EBE08: or          $t3, $a1, $a2
    ctx->r11 = ctx->r5 | ctx->r6;
    // 0x800EBE0C: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x800EBE10: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800EBE14: sb          $t3, 0x2580($a0)
    MEM_B(0X2580, ctx->r4) = ctx->r11;
    // 0x800EBE18: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x800EBE1C: jr          $ra
    // 0x800EBE20: nop

    return;
    // 0x800EBE20: nop

;}
RECOMP_FUNC void func_8001EE34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EE34: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8001EE38: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001EE3C: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x8001EE40: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8001EE44: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8001EE48: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001EE4C: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x8001EE50: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x8001EE54: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x8001EE58: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
L_8001EE5C:
    // 0x8001EE5C: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8001EE60: beq         $t7, $zero, L_8001EE90
    if (ctx->r15 == 0) {
        // 0x8001EE64: nop
    
            goto L_8001EE90;
    }
    // 0x8001EE64: nop

    // 0x8001EE68: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8001EE6C: sw          $t8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r24;
    // 0x8001EE70: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    // 0x8001EE74: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8001EE78: sh          $t0, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r8;
    // 0x8001EE7C: lw          $t1, 0xB8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB8);
    // 0x8001EE80: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x8001EE84: sw          $t2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r10;
    // 0x8001EE88: addiu       $t3, $sp, 0x84
    ctx->r11 = ADD32(ctx->r29, 0X84);
    // 0x8001EE8C: sw          $t3, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r11;
L_8001EE90:
    // 0x8001EE90: lw          $t4, 0xB8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB8);
    // 0x8001EE94: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8001EE98: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    // 0x8001EE9C: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8001EEA0: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8001EEA4: sw          $t7, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r15;
    // 0x8001EEA8: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x8001EEAC: bne         $t8, $zero, L_8001EEC8
    if (ctx->r24 != 0) {
        // 0x8001EEB0: nop
    
            goto L_8001EEC8;
    }
    // 0x8001EEB0: nop

    // 0x8001EEB4: addiu       $a0, $sp, 0x5A
    ctx->r4 = ADD32(ctx->r29, 0X5A);
    // 0x8001EEB8: jal         0x80020298
    // 0x8001EEBC: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_80020298(rdram, ctx);
        goto after_0;
    // 0x8001EEBC: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_0:
    // 0x8001EEC0: b           L_800200A4
    // 0x8001EEC4: nop

        goto L_800200A4;
    // 0x8001EEC4: nop

L_8001EEC8:
    // 0x8001EEC8: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x8001EECC: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x8001EED0: sw          $t0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r8;
    // 0x8001EED4: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8001EED8: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8001EEDC: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    // 0x8001EEE0: lw          $t3, 0xB8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB8);
    // 0x8001EEE4: lhu         $s0, 0x0($t3)
    ctx->r16 = MEM_HU(ctx->r11, 0X0);
    // 0x8001EEE8: slti        $at, $s0, 0x201
    ctx->r1 = SIGNED(ctx->r16) < 0X201 ? 1 : 0;
    // 0x8001EEEC: bne         $at, $zero, L_8001EF2C
    if (ctx->r1 != 0) {
        // 0x8001EEF0: nop
    
            goto L_8001EF2C;
    }
    // 0x8001EEF0: nop

    // 0x8001EEF4: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x8001EEF8: beq         $s0, $at, L_8001F740
    if (ctx->r16 == ctx->r1) {
        // 0x8001EEFC: nop
    
            goto L_8001F740;
    }
    // 0x8001EEFC: nop

    // 0x8001EF00: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x8001EF04: beq         $s0, $at, L_8001FC64
    if (ctx->r16 == ctx->r1) {
        // 0x8001EF08: nop
    
            goto L_8001FC64;
    }
    // 0x8001EF08: nop

    // 0x8001EF0C: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x8001EF10: beq         $s0, $at, L_8001F740
    if (ctx->r16 == ctx->r1) {
        // 0x8001EF14: nop
    
            goto L_8001F740;
    }
    // 0x8001EF14: nop

    // 0x8001EF18: addiu       $at, $zero, 0x2000
    ctx->r1 = ADD32(0, 0X2000);
    // 0x8001EF1C: beq         $s0, $at, L_8001FA68
    if (ctx->r16 == ctx->r1) {
        // 0x8001EF20: nop
    
            goto L_8001FA68;
    }
    // 0x8001EF20: nop

    // 0x8001EF24: b           L_80020038
    // 0x8001EF28: nop

        goto L_80020038;
    // 0x8001EF28: nop

L_8001EF2C:
    // 0x8001EF2C: slti        $at, $s0, 0x81
    ctx->r1 = SIGNED(ctx->r16) < 0X81 ? 1 : 0;
    // 0x8001EF30: bne         $at, $zero, L_8001EF58
    if (ctx->r1 != 0) {
        // 0x8001EF34: nop
    
            goto L_8001EF58;
    }
    // 0x8001EF34: nop

    // 0x8001EF38: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x8001EF3C: beq         $s0, $at, L_8001F9A4
    if (ctx->r16 == ctx->r1) {
        // 0x8001EF40: nop
    
            goto L_8001F9A4;
    }
    // 0x8001EF40: nop

    // 0x8001EF44: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x8001EF48: beq         $s0, $at, L_8001FFE8
    if (ctx->r16 == ctx->r1) {
        // 0x8001EF4C: nop
    
            goto L_8001FFE8;
    }
    // 0x8001EF4C: nop

    // 0x8001EF50: b           L_80020038
    // 0x8001EF54: nop

        goto L_80020038;
    // 0x8001EF54: nop

L_8001EF58:
    // 0x8001EF58: slti        $at, $s0, 0x41
    ctx->r1 = SIGNED(ctx->r16) < 0X41 ? 1 : 0;
    // 0x8001EF5C: bne         $at, $zero, L_8001EF78
    if (ctx->r1 != 0) {
        // 0x8001EF60: nop
    
            goto L_8001EF78;
    }
    // 0x8001EF60: nop

    // 0x8001EF64: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8001EF68: beq         $s0, $at, L_8001FFD8
    if (ctx->r16 == ctx->r1) {
        // 0x8001EF6C: nop
    
            goto L_8001FFD8;
    }
    // 0x8001EF6C: nop

    // 0x8001EF70: b           L_80020038
    // 0x8001EF74: nop

        goto L_80020038;
    // 0x8001EF74: nop

L_8001EF78:
    // 0x8001EF78: slti        $at, $s0, 0x11
    ctx->r1 = SIGNED(ctx->r16) < 0X11 ? 1 : 0;
    // 0x8001EF7C: bne         $at, $zero, L_8001EF98
    if (ctx->r1 != 0) {
        // 0x8001EF80: nop
    
            goto L_8001EF98;
    }
    // 0x8001EF80: nop

    // 0x8001EF84: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8001EF88: beq         $s0, $at, L_8001FDE4
    if (ctx->r16 == ctx->r1) {
        // 0x8001EF8C: nop
    
            goto L_8001FDE4;
    }
    // 0x8001EF8C: nop

    // 0x8001EF90: b           L_80020038
    // 0x8001EF94: nop

        goto L_80020038;
    // 0x8001EF94: nop

L_8001EF98:
    // 0x8001EF98: addiu       $t4, $s0, -0x1
    ctx->r12 = ADD32(ctx->r16, -0X1);
    // 0x8001EF9C: sltiu       $at, $t4, 0x10
    ctx->r1 = ctx->r12 < 0X10 ? 1 : 0;
    // 0x8001EFA0: beq         $at, $zero, L_80020038
    if (ctx->r1 == 0) {
        // 0x8001EFA4: nop
    
            goto L_80020038;
    }
    // 0x8001EFA4: nop

    // 0x8001EFA8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8001EFAC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001EFB0: addu        $at, $at, $t4
    gpr jr_addend_8001EFB8 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8001EFB4: lw          $t4, 0x1940($at)
    ctx->r12 = ADD32(ctx->r1, 0X1940);
    // 0x8001EFB8: jr          $t4
    // 0x8001EFBC: nop

    switch (jr_addend_8001EFB8 >> 2) {
        case 0: goto L_8001EFC0; break;
        case 1: goto L_8001F740; break;
        case 2: goto L_80020038; break;
        case 3: goto L_8001F898; break;
        case 4: goto L_80020038; break;
        case 5: goto L_80020038; break;
        case 6: goto L_80020038; break;
        case 7: goto L_8001FAC8; break;
        case 8: goto L_80020038; break;
        case 9: goto L_80020038; break;
        case 10: goto L_80020038; break;
        case 11: goto L_80020038; break;
        case 12: goto L_80020038; break;
        case 13: goto L_80020038; break;
        case 14: goto L_80020038; break;
        case 15: goto L_8001F93C; break;
        default: switch_error(__func__, 0x8001EFB8, 0x80041940);
    }
    // 0x8001EFBC: nop

L_8001EFC0:
    // 0x8001EFC0: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8001EFC4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8001EFC8: lbu         $t6, 0x45($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X45);
    // 0x8001EFCC: beq         $t6, $at, L_8001EFE8
    if (ctx->r14 == ctx->r1) {
        // 0x8001EFD0: nop
    
            goto L_8001EFE8;
    }
    // 0x8001EFD0: nop

    // 0x8001EFD4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001EFD8: beq         $t6, $at, L_8001EFE8
    if (ctx->r14 == ctx->r1) {
        // 0x8001EFDC: nop
    
            goto L_8001EFE8;
    }
    // 0x8001EFDC: nop

    // 0x8001EFE0: b           L_800200A4
    // 0x8001EFE4: nop

        goto L_800200A4;
    // 0x8001EFE4: nop

L_8001EFE8:
    // 0x8001EFE8: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8001EFEC: lbu         $t8, 0x43($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X43);
    // 0x8001EFF0: sh          $t8, 0xB2($sp)
    MEM_H(0XB2, ctx->r29) = ctx->r24;
    // 0x8001EFF4: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8001EFF8: lbu         $t0, 0x40($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X40);
    // 0x8001EFFC: sh          $t0, 0xB0($sp)
    MEM_H(0XB0, ctx->r29) = ctx->r8;
    // 0x8001F000: sb          $zero, 0xB4($sp)
    MEM_B(0XB4, ctx->r29) = 0;
    // 0x8001F004: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x8001F008: lw          $t2, 0x11DC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X11DC);
    // 0x8001F00C: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x8001F010: lh          $t1, 0x11E0($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X11E0);
    // 0x8001F014: lw          $t3, 0x44($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X44);
    // 0x8001F018: slt         $t4, $t1, $t3
    ctx->r12 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8001F01C: xori        $t4, $t4, 0x1
    ctx->r12 = ctx->r12 ^ 0X1;
    // 0x8001F020: sw          $t4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r12;
    // 0x8001F024: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x8001F028: beq         $t5, $zero, L_8001F044
    if (ctx->r13 == 0) {
        // 0x8001F02C: nop
    
            goto L_8001F044;
    }
    // 0x8001F02C: nop

    // 0x8001F030: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8001F034: lbu         $t7, 0x44($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X44);
    // 0x8001F038: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8001F03C: beq         $t8, $zero, L_8001F058
    if (ctx->r24 == 0) {
        // 0x8001F040: nop
    
            goto L_8001F058;
    }
    // 0x8001F040: nop

L_8001F044:
    // 0x8001F044: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8001F048: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    // 0x8001F04C: jal         0x800268D0
    // 0x8001F050: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800268D0(rdram, ctx);
        goto after_1;
    // 0x8001F050: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_1:
    // 0x8001F054: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
L_8001F058:
    // 0x8001F058: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x8001F05C: bne         $t9, $zero, L_8001F1DC
    if (ctx->r25 != 0) {
        // 0x8001F060: nop
    
            goto L_8001F1DC;
    }
    // 0x8001F060: nop

    // 0x8001F064: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8001F068: lbu         $t2, 0x44($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X44);
    // 0x8001F06C: andi        $t1, $t2, 0x12
    ctx->r9 = ctx->r10 & 0X12;
    // 0x8001F070: bne         $t1, $zero, L_8001F084
    if (ctx->r9 != 0) {
        // 0x8001F074: nop
    
            goto L_8001F084;
    }
    // 0x8001F074: nop

    // 0x8001F078: lw          $t3, 0x34($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X34);
    // 0x8001F07C: blez        $t3, L_8001F0C4
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8001F080: nop
    
            goto L_8001F0C4;
    }
    // 0x8001F080: nop

L_8001F084:
    // 0x8001F084: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8001F088: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8001F08C: sb          $t4, 0x45($t5)
    MEM_B(0X45, ctx->r13) = ctx->r12;
    // 0x8001F090: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8001F094: lw          $t7, 0x34($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X34);
    // 0x8001F098: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8001F09C: sw          $t8, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->r24;
    // 0x8001F0A0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001F0A4: lw          $a0, 0x11DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11DC);
    // 0x8001F0A8: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
    // 0x8001F0AC: ori         $a2, $zero, 0x8235
    ctx->r6 = 0 | 0X8235;
    // 0x8001F0B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001F0B4: jal         0x80026500
    // 0x8001F0B8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    func_80026500(rdram, ctx);
        goto after_2;
    // 0x8001F0B8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_2:
    // 0x8001F0BC: b           L_8001F1D4
    // 0x8001F0C0: nop

        goto L_8001F1D4;
    // 0x8001F0C0: nop

L_8001F0C4:
    // 0x8001F0C4: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8001F0C8: beq         $t9, $zero, L_8001F1CC
    if (ctx->r25 == 0) {
        // 0x8001F0CC: nop
    
            goto L_8001F1CC;
    }
    // 0x8001F0CC: nop

    // 0x8001F0D0: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x8001F0D4: lw          $t2, 0x11D4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X11D4);
    // 0x8001F0D8: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
L_8001F0DC:
    // 0x8001F0DC: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8001F0E0: lbu         $t0, 0x44($t1)
    ctx->r8 = MEM_BU(ctx->r9, 0X44);
    // 0x8001F0E4: andi        $t3, $t0, 0x12
    ctx->r11 = ctx->r8 & 0X12;
    // 0x8001F0E8: bne         $t3, $zero, L_8001F15C
    if (ctx->r11 != 0) {
        // 0x8001F0EC: nop
    
            goto L_8001F15C;
    }
    // 0x8001F0EC: nop

    // 0x8001F0F0: andi        $t4, $t0, 0x4
    ctx->r12 = ctx->r8 & 0X4;
    // 0x8001F0F4: beq         $t4, $zero, L_8001F15C
    if (ctx->r12 == 0) {
        // 0x8001F0F8: nop
    
            goto L_8001F15C;
    }
    // 0x8001F0F8: nop

    // 0x8001F0FC: lbu         $t5, 0x45($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X45);
    // 0x8001F100: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001F104: beq         $t5, $at, L_8001F15C
    if (ctx->r13 == ctx->r1) {
        // 0x8001F108: nop
    
            goto L_8001F15C;
    }
    // 0x8001F108: nop

    // 0x8001F10C: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x8001F110: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x8001F114: sh          $t7, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r15;
    // 0x8001F118: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x8001F11C: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x8001F120: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8001F124: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8001F128: sb          $t6, 0x45($t9)
    MEM_B(0X45, ctx->r25) = ctx->r14;
    // 0x8001F12C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001F130: lw          $a0, 0x11DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11DC);
    // 0x8001F134: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8001F138: addiu       $a2, $zero, 0x3E8
    ctx->r6 = ADD32(0, 0X3E8);
    // 0x8001F13C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001F140: jal         0x80026500
    // 0x8001F144: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    func_80026500(rdram, ctx);
        goto after_3;
    // 0x8001F144: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_3:
    // 0x8001F148: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8001F14C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001F150: addiu       $a2, $zero, 0x3E8
    ctx->r6 = ADD32(0, 0X3E8);
    // 0x8001F154: jal         0x80026BE0
    // 0x8001F158: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_80026BE0(rdram, ctx);
        goto after_4;
    // 0x8001F158: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_4:
L_8001F15C:
    // 0x8001F15C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8001F160: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8001F164: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    // 0x8001F168: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x8001F16C: beq         $t0, $zero, L_8001F180
    if (ctx->r8 == 0) {
        // 0x8001F170: nop
    
            goto L_8001F180;
    }
    // 0x8001F170: nop

    // 0x8001F174: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8001F178: bne         $t4, $zero, L_8001F0DC
    if (ctx->r12 != 0) {
        // 0x8001F17C: nop
    
            goto L_8001F0DC;
    }
    // 0x8001F17C: nop

L_8001F180:
    // 0x8001F180: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8001F184: bne         $t1, $zero, L_8001F1BC
    if (ctx->r9 != 0) {
        // 0x8001F188: nop
    
            goto L_8001F1BC;
    }
    // 0x8001F188: nop

    // 0x8001F18C: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8001F190: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8001F194: sw          $t5, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r13;
    // 0x8001F198: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001F19C: lw          $a0, 0x11DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11DC);
    // 0x8001F1A0: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
    // 0x8001F1A4: addiu       $a2, $zero, 0x3E9
    ctx->r6 = ADD32(0, 0X3E9);
    // 0x8001F1A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001F1AC: jal         0x80026500
    // 0x8001F1B0: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    func_80026500(rdram, ctx);
        goto after_5;
    // 0x8001F1B0: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_5:
    // 0x8001F1B4: b           L_8001F1C4
    // 0x8001F1B8: nop

        goto L_8001F1C4;
    // 0x8001F1B8: nop

L_8001F1BC:
    // 0x8001F1BC: jal         0x800200B8
    // 0x8001F1C0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_800200B8(rdram, ctx);
        goto after_6;
    // 0x8001F1C0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_6:
L_8001F1C4:
    // 0x8001F1C4: b           L_8001F1D4
    // 0x8001F1C8: nop

        goto L_8001F1D4;
    // 0x8001F1C8: nop

L_8001F1CC:
    // 0x8001F1CC: jal         0x800200B8
    // 0x8001F1D0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_800200B8(rdram, ctx);
        goto after_7;
    // 0x8001F1D0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_7:
L_8001F1D4:
    // 0x8001F1D4: b           L_800200A4
    // 0x8001F1D8: nop

        goto L_800200A4;
    // 0x8001F1D8: nop

L_8001F1DC:
    // 0x8001F1DC: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8001F1E0: lbu         $t6, 0x44($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X44);
    // 0x8001F1E4: ori         $t9, $t6, 0x4
    ctx->r25 = ctx->r14 | 0X4;
    // 0x8001F1E8: sb          $t9, 0x44($t8)
    MEM_B(0X44, ctx->r24) = ctx->r25;
    // 0x8001F1EC: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x8001F1F0: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8001F1F4: lbu         $t3, 0xC($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0XC);
    // 0x8001F1F8: sh          $t3, 0x3A($t0)
    MEM_H(0X3A, ctx->r8) = ctx->r11;
    // 0x8001F1FC: lh          $t4, 0xB2($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XB2);
    // 0x8001F200: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8001F204: sb          $t4, 0x43($t1)
    MEM_B(0X43, ctx->r9) = ctx->r12;
    // 0x8001F208: lw          $t5, 0xAC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XAC);
    // 0x8001F20C: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8001F210: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8001F214: lwc1        $f8, 0x2C($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X2C);
    // 0x8001F218: lwc1        $f16, 0x28($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X28);
    // 0x8001F21C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8001F220: nop

    // 0x8001F224: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001F228: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001F22C: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001F230: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8001F234: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8001F238: nop

    // 0x8001F23C: sw          $t8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r24;
    // 0x8001F240: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x8001F244: lw          $t2, 0x11DC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X11DC);
    // 0x8001F248: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x8001F24C: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8001F250: lw          $t3, 0x50($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X50);
    // 0x8001F254: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x8001F258: sw          $t4, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->r12;
    // 0x8001F25C: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8001F260: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x8001F264: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x8001F268: lh          $t4, 0x3A($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X3A);
    // 0x8001F26C: lh          $t1, 0x38($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X38);
    // 0x8001F270: lbu         $t6, 0x2($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X2);
    // 0x8001F274: lw          $t5, -0x15DC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X15DC);
    // 0x8001F278: multu       $t4, $t1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001F27C: andi        $t9, $t6, 0x1F
    ctx->r25 = ctx->r14 & 0X1F;
    // 0x8001F280: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x8001F284: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x8001F288: addu        $t2, $t5, $t8
    ctx->r10 = ADD32(ctx->r13, ctx->r24);
    // 0x8001F28C: lbu         $t9, 0xD5($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0XD5);
    // 0x8001F290: addiu       $at, $zero, 0x3F01
    ctx->r1 = ADD32(0, 0X3F01);
    // 0x8001F294: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x8001F298: mflo        $t7
    ctx->r15 = lo;
    // 0x8001F29C: nop

    // 0x8001F2A0: nop

    // 0x8001F2A4: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001F2A8: mflo        $t5
    ctx->r13 = lo;
    // 0x8001F2AC: nop

    // 0x8001F2B0: nop

    // 0x8001F2B4: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x8001F2B8: mflo        $t8
    ctx->r24 = lo;
    // 0x8001F2BC: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x8001F2C0: nop

    // 0x8001F2C4: multu       $t3, $t8
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001F2C8: mflo        $t2
    ctx->r10 = lo;
    // 0x8001F2CC: nop

    // 0x8001F2D0: nop

    // 0x8001F2D4: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x8001F2D8: mflo        $t0
    ctx->r8 = lo;
    // 0x8001F2DC: bgtz        $t0, L_8001F2EC
    if (SIGNED(ctx->r8) > 0) {
        // 0x8001F2E0: nop
    
            goto L_8001F2EC;
    }
    // 0x8001F2E0: nop

    // 0x8001F2E4: b           L_8001F374
    // 0x8001F2E8: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
        goto L_8001F374;
    // 0x8001F2E8: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
L_8001F2EC:
    // 0x8001F2EC: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8001F2F0: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x8001F2F4: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x8001F2F8: lh          $t2, 0x3A($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X3A);
    // 0x8001F2FC: lh          $t0, 0x38($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X38);
    // 0x8001F300: lbu         $t6, 0x2($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X2);
    // 0x8001F304: lw          $t4, -0x15DC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X15DC);
    // 0x8001F308: multu       $t2, $t0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001F30C: andi        $t7, $t6, 0x1F
    ctx->r15 = ctx->r14 & 0X1F;
    // 0x8001F310: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x8001F314: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x8001F318: addu        $t5, $t4, $t9
    ctx->r13 = ADD32(ctx->r12, ctx->r25);
    // 0x8001F31C: lbu         $t7, 0xD5($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XD5);
    // 0x8001F320: addiu       $at, $zero, 0x3F01
    ctx->r1 = ADD32(0, 0X3F01);
    // 0x8001F324: lh          $t3, 0x0($t5)
    ctx->r11 = MEM_H(ctx->r13, 0X0);
    // 0x8001F328: mflo        $t1
    ctx->r9 = lo;
    // 0x8001F32C: nop

    // 0x8001F330: nop

    // 0x8001F334: multu       $t1, $t7
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001F338: mflo        $t4
    ctx->r12 = lo;
    // 0x8001F33C: nop

    // 0x8001F340: nop

    // 0x8001F344: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x8001F348: mflo        $t9
    ctx->r25 = lo;
    // 0x8001F34C: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x8001F350: nop

    // 0x8001F354: multu       $t3, $t9
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001F358: mflo        $t5
    ctx->r13 = lo;
    // 0x8001F35C: nop

    // 0x8001F360: nop

    // 0x8001F364: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x8001F368: mflo        $t8
    ctx->r24 = lo;
    // 0x8001F36C: addiu       $t2, $t8, -0x1
    ctx->r10 = ADD32(ctx->r24, -0X1);
    // 0x8001F370: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
L_8001F374:
    // 0x8001F374: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8001F378: lw          $t1, 0xAC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XAC);
    // 0x8001F37C: lbu         $t6, 0x41($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X41);
    // 0x8001F380: lbu         $t7, 0xD4($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0XD4);
    // 0x8001F384: addu        $t4, $t6, $t7
    ctx->r12 = ADD32(ctx->r14, ctx->r15);
    // 0x8001F388: addiu       $t3, $t4, -0x40
    ctx->r11 = ADD32(ctx->r12, -0X40);
    // 0x8001F38C: sw          $t3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r11;
    // 0x8001F390: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x8001F394: blez        $t9, L_8001F3A4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8001F398: nop
    
            goto L_8001F3A4;
    }
    // 0x8001F398: nop

    // 0x8001F39C: b           L_8001F3A8
    // 0x8001F3A0: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
        goto L_8001F3A8;
    // 0x8001F3A0: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_8001F3A4:
    // 0x8001F3A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001F3A8:
    // 0x8001F3A8: slti        $at, $s0, 0x7F
    ctx->r1 = SIGNED(ctx->r16) < 0X7F ? 1 : 0;
    // 0x8001F3AC: beq         $at, $zero, L_8001F3D4
    if (ctx->r1 == 0) {
        // 0x8001F3B0: nop
    
            goto L_8001F3D4;
    }
    // 0x8001F3B0: nop

    // 0x8001F3B4: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8001F3B8: blez        $t5, L_8001F3C8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8001F3BC: nop
    
            goto L_8001F3C8;
    }
    // 0x8001F3BC: nop

    // 0x8001F3C0: b           L_8001F3CC
    // 0x8001F3C4: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
        goto L_8001F3CC;
    // 0x8001F3C4: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
L_8001F3C8:
    // 0x8001F3C8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8001F3CC:
    // 0x8001F3CC: b           L_8001F3DC
    // 0x8001F3D0: sb          $s1, 0xA7($sp)
    MEM_B(0XA7, ctx->r29) = ctx->r17;
        goto L_8001F3DC;
    // 0x8001F3D0: sb          $s1, 0xA7($sp)
    MEM_B(0XA7, ctx->r29) = ctx->r17;
L_8001F3D4:
    // 0x8001F3D4: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
    // 0x8001F3D8: sb          $t8, 0xA7($sp)
    MEM_B(0XA7, ctx->r29) = ctx->r24;
L_8001F3DC:
    // 0x8001F3DC: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x8001F3E0: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8001F3E4: lbu         $t7, 0x3($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X3);
    // 0x8001F3E8: lbu         $t0, 0x42($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0X42);
    // 0x8001F3EC: andi        $t4, $t7, 0xF
    ctx->r12 = ctx->r15 & 0XF;
    // 0x8001F3F0: sll         $t3, $t4, 3
    ctx->r11 = S32(ctx->r12 << 3);
    // 0x8001F3F4: andi        $t1, $t0, 0x7F
    ctx->r9 = ctx->r8 & 0X7F;
    // 0x8001F3F8: addu        $t9, $t1, $t3
    ctx->r25 = ADD32(ctx->r9, ctx->r11);
    // 0x8001F3FC: sw          $t9, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r25;
    // 0x8001F400: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x8001F404: bgez        $t5, L_8001F414
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8001F408: nop
    
            goto L_8001F414;
    }
    // 0x8001F408: nop

    // 0x8001F40C: b           L_8001F418
    // 0x8001F410: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_8001F418;
    // 0x8001F410: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001F414:
    // 0x8001F414: lw          $s0, 0x7C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X7C);
L_8001F418:
    // 0x8001F418: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // 0x8001F41C: bne         $at, $zero, L_8001F430
    if (ctx->r1 != 0) {
        // 0x8001F420: nop
    
            goto L_8001F430;
    }
    // 0x8001F420: nop

    // 0x8001F424: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
    // 0x8001F428: b           L_8001F44C
    // 0x8001F42C: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
        goto L_8001F44C;
    // 0x8001F42C: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
L_8001F430:
    // 0x8001F430: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x8001F434: bgez        $t2, L_8001F444
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8001F438: nop
    
            goto L_8001F444;
    }
    // 0x8001F438: nop

    // 0x8001F43C: b           L_8001F448
    // 0x8001F440: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_8001F448;
    // 0x8001F440: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8001F444:
    // 0x8001F444: lw          $s1, 0x7C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X7C);
L_8001F448:
    // 0x8001F448: sw          $s1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r17;
L_8001F44C:
    // 0x8001F44C: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8001F450: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x8001F454: lbu         $t7, 0x42($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X42);
    // 0x8001F458: andi        $t4, $t7, 0x80
    ctx->r12 = ctx->r15 & 0X80;
    // 0x8001F45C: or          $t1, $t0, $t4
    ctx->r9 = ctx->r8 | ctx->r12;
    // 0x8001F460: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x8001F464: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8001F468: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8001F46C: lbu         $t9, 0xA7($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XA7);
    // 0x8001F470: lwc1        $f6, 0x2C($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X2C);
    // 0x8001F474: lwc1        $f8, 0x28($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X28);
    // 0x8001F478: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x8001F47C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001F480: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001F484: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x8001F488: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8001F48C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8001F490: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x8001F494: addiu       $a0, $t3, 0xC
    ctx->r4 = ADD32(ctx->r11, 0XC);
    // 0x8001F498: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x8001F49C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8001F4A0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8001F4A4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8001F4A8: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8001F4AC: jal         0x80026CB0
    // 0x8001F4B0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    func_80026CB0(rdram, ctx);
        goto after_8;
    // 0x8001F4B0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    after_8:
    // 0x8001F4B4: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8001F4B8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8001F4BC: sb          $t2, 0x45($t6)
    MEM_B(0X45, ctx->r14) = ctx->r10;
    // 0x8001F4C0: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8001F4C4: lh          $t7, 0x11E0($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X11E0);
    // 0x8001F4C8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001F4CC: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x8001F4D0: sh          $t0, 0x11E0($at)
    MEM_H(0X11E0, ctx->r1) = ctx->r8;
    // 0x8001F4D4: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8001F4D8: lbu         $t1, 0x44($t4)
    ctx->r9 = MEM_BU(ctx->r12, 0X44);
    // 0x8001F4DC: andi        $t3, $t1, 0x2
    ctx->r11 = ctx->r9 & 0X2;
    // 0x8001F4E0: bne         $t3, $zero, L_8001F738
    if (ctx->r11 != 0) {
        // 0x8001F4E4: nop
    
            goto L_8001F738;
    }
    // 0x8001F4E4: nop

    // 0x8001F4E8: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x8001F4EC: bne         $t9, $zero, L_8001F6D4
    if (ctx->r25 != 0) {
        // 0x8001F4F0: nop
    
            goto L_8001F6D4;
    }
    // 0x8001F4F0: nop

    // 0x8001F4F4: lw          $t5, 0xAC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XAC);
    // 0x8001F4F8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8001F4FC: lbu         $t8, 0xD($t5)
    ctx->r24 = MEM_BU(ctx->r13, 0XD);
    // 0x8001F500: sh          $t8, 0x3A($t2)
    MEM_H(0X3A, ctx->r10) = ctx->r24;
    // 0x8001F504: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8001F508: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x8001F50C: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001F510: lh          $t8, 0x3A($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X3A);
    // 0x8001F514: lh          $t2, 0x38($t5)
    ctx->r10 = MEM_H(ctx->r13, 0X38);
    // 0x8001F518: lbu         $t0, 0x2($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0X2);
    // 0x8001F51C: lw          $t6, -0x15DC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X15DC);
    // 0x8001F520: multu       $t8, $t2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001F524: andi        $t4, $t0, 0x1F
    ctx->r12 = ctx->r8 & 0X1F;
    // 0x8001F528: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
    // 0x8001F52C: sll         $t1, $t4, 1
    ctx->r9 = S32(ctx->r12 << 1);
    // 0x8001F530: addu        $t3, $t6, $t1
    ctx->r11 = ADD32(ctx->r14, ctx->r9);
    // 0x8001F534: lbu         $t4, 0xD5($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0XD5);
    // 0x8001F538: addiu       $at, $zero, 0x3F01
    ctx->r1 = ADD32(0, 0X3F01);
    // 0x8001F53C: lh          $t9, 0x0($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X0);
    // 0x8001F540: mflo        $t7
    ctx->r15 = lo;
    // 0x8001F544: nop

    // 0x8001F548: nop

    // 0x8001F54C: multu       $t7, $t4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001F550: mflo        $t6
    ctx->r14 = lo;
    // 0x8001F554: nop

    // 0x8001F558: nop

    // 0x8001F55C: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x8001F560: mflo        $t1
    ctx->r9 = lo;
    // 0x8001F564: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x8001F568: nop

    // 0x8001F56C: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001F570: mflo        $t3
    ctx->r11 = lo;
    // 0x8001F574: nop

    // 0x8001F578: nop

    // 0x8001F57C: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x8001F580: mflo        $t5
    ctx->r13 = lo;
    // 0x8001F584: bgtz        $t5, L_8001F594
    if (SIGNED(ctx->r13) > 0) {
        // 0x8001F588: nop
    
            goto L_8001F594;
    }
    // 0x8001F588: nop

    // 0x8001F58C: b           L_8001F61C
    // 0x8001F590: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
        goto L_8001F61C;
    // 0x8001F590: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
L_8001F594:
    // 0x8001F594: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8001F598: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x8001F59C: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8001F5A0: lh          $t3, 0x3A($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X3A);
    // 0x8001F5A4: lh          $t5, 0x38($t1)
    ctx->r13 = MEM_H(ctx->r9, 0X38);
    // 0x8001F5A8: lbu         $t0, 0x2($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0X2);
    // 0x8001F5AC: lw          $t8, -0x15DC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X15DC);
    // 0x8001F5B0: multu       $t3, $t5
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001F5B4: andi        $t7, $t0, 0x1F
    ctx->r15 = ctx->r8 & 0X1F;
    // 0x8001F5B8: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
    // 0x8001F5BC: sll         $t4, $t7, 1
    ctx->r12 = S32(ctx->r15 << 1);
    // 0x8001F5C0: addu        $t6, $t8, $t4
    ctx->r14 = ADD32(ctx->r24, ctx->r12);
    // 0x8001F5C4: lbu         $t7, 0xD5($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0XD5);
    // 0x8001F5C8: addiu       $at, $zero, 0x3F01
    ctx->r1 = ADD32(0, 0X3F01);
    // 0x8001F5CC: lh          $t9, 0x0($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X0);
    // 0x8001F5D0: mflo        $t2
    ctx->r10 = lo;
    // 0x8001F5D4: nop

    // 0x8001F5D8: nop

    // 0x8001F5DC: multu       $t2, $t7
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001F5E0: mflo        $t8
    ctx->r24 = lo;
    // 0x8001F5E4: nop

    // 0x8001F5E8: nop

    // 0x8001F5EC: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x8001F5F0: mflo        $t4
    ctx->r12 = lo;
    // 0x8001F5F4: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x8001F5F8: nop

    // 0x8001F5FC: multu       $t9, $t4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001F600: mflo        $t6
    ctx->r14 = lo;
    // 0x8001F604: nop

    // 0x8001F608: nop

    // 0x8001F60C: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x8001F610: mflo        $t1
    ctx->r9 = lo;
    // 0x8001F614: addiu       $t3, $t1, -0x1
    ctx->r11 = ADD32(ctx->r9, -0X1);
    // 0x8001F618: sw          $t3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r11;
L_8001F61C:
    // 0x8001F61C: lw          $t5, 0xAC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XAC);
    // 0x8001F620: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8001F624: lw          $t0, 0x4($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X4);
    // 0x8001F628: lwc1        $f6, 0x28($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X28);
    // 0x8001F62C: lwc1        $f10, 0x2C($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X2C);
    // 0x8001F630: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8001F634: nop

    // 0x8001F638: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001F63C: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001F640: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8001F644: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8001F648: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8001F64C: nop

    // 0x8001F650: sw          $t8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r24;
    // 0x8001F654: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8001F658: lw          $t9, 0x11DC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11DC);
    // 0x8001F65C: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x8001F660: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8001F664: lw          $t4, 0x50($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X50);
    // 0x8001F668: addu        $t1, $t4, $t6
    ctx->r9 = ADD32(ctx->r12, ctx->r14);
    // 0x8001F66C: sw          $t1, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->r9;
    // 0x8001F670: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8001F674: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x8001F678: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x8001F67C: jal         0x80026BE0
    // 0x8001F680: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_80026BE0(rdram, ctx);
        goto after_9;
    // 0x8001F680: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_9:
    // 0x8001F684: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8001F688: sh          $t5, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r13;
    // 0x8001F68C: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8001F690: sw          $t0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r8;
    // 0x8001F694: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001F698: lw          $a0, 0x11DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11DC);
    // 0x8001F69C: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x8001F6A0: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x8001F6A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001F6A8: jal         0x80026500
    // 0x8001F6AC: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    func_80026500(rdram, ctx);
        goto after_10;
    // 0x8001F6AC: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_10:
    // 0x8001F6B0: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8001F6B4: lbu         $t7, 0x44($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X44);
    // 0x8001F6B8: andi        $t8, $t7, 0x20
    ctx->r24 = ctx->r15 & 0X20;
    // 0x8001F6BC: beq         $t8, $zero, L_8001F6CC
    if (ctx->r24 == 0) {
        // 0x8001F6C0: nop
    
            goto L_8001F6CC;
    }
    // 0x8001F6C0: nop

    // 0x8001F6C4: jal         0x80020128
    // 0x8001F6C8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_80020128(rdram, ctx);
        goto after_11;
    // 0x8001F6C8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_11:
L_8001F6CC:
    // 0x8001F6CC: b           L_8001F738
    // 0x8001F6D0: nop

        goto L_8001F738;
    // 0x8001F6D0: nop

L_8001F6D4:
    // 0x8001F6D4: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x8001F6D8: sh          $t9, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r25;
    // 0x8001F6DC: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8001F6E0: sw          $t4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r12;
    // 0x8001F6E4: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x8001F6E8: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8001F6EC: lw          $t1, 0x0($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X0);
    // 0x8001F6F0: lwc1        $f8, 0x2C($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X2C);
    // 0x8001F6F4: lwc1        $f16, 0x28($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X28);
    // 0x8001F6F8: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8001F6FC: nop

    // 0x8001F700: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001F704: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001F708: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001F70C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8001F710: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x8001F714: nop

    // 0x8001F718: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x8001F71C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001F720: lw          $a0, 0x11DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11DC);
    // 0x8001F724: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x8001F728: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x8001F72C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001F730: jal         0x80026500
    // 0x8001F734: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    func_80026500(rdram, ctx);
        goto after_12;
    // 0x8001F734: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_12:
L_8001F738:
    // 0x8001F738: b           L_80020040
    // 0x8001F73C: nop

        goto L_80020040;
    // 0x8001F73C: nop

L_8001F740:
    // 0x8001F740: lw          $t2, 0xB8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB8);
    // 0x8001F744: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x8001F748: lhu         $t7, 0x0($t2)
    ctx->r15 = MEM_HU(ctx->r10, 0X0);
    // 0x8001F74C: bne         $t7, $at, L_8001F768
    if (ctx->r15 != ctx->r1) {
        // 0x8001F750: nop
    
            goto L_8001F768;
    }
    // 0x8001F750: nop

    // 0x8001F754: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8001F758: lbu         $t9, 0x44($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X44);
    // 0x8001F75C: andi        $t4, $t9, 0x2
    ctx->r12 = ctx->r25 & 0X2;
    // 0x8001F760: beq         $t4, $zero, L_8001F890
    if (ctx->r12 == 0) {
        // 0x8001F764: nop
    
            goto L_8001F890;
    }
    // 0x8001F764: nop

L_8001F768:
    // 0x8001F768: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8001F76C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001F770: lbu         $s0, 0x45($t6)
    ctx->r16 = MEM_BU(ctx->r14, 0X45);
    // 0x8001F774: beq         $s0, $at, L_8001F79C
    if (ctx->r16 == ctx->r1) {
        // 0x8001F778: nop
    
            goto L_8001F79C;
    }
    // 0x8001F778: nop

    // 0x8001F77C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001F780: beq         $s0, $at, L_8001F858
    if (ctx->r16 == ctx->r1) {
        // 0x8001F784: nop
    
            goto L_8001F858;
    }
    // 0x8001F784: nop

    // 0x8001F788: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8001F78C: beq         $s0, $at, L_8001F858
    if (ctx->r16 == ctx->r1) {
        // 0x8001F790: nop
    
            goto L_8001F858;
    }
    // 0x8001F790: nop

    // 0x8001F794: b           L_8001F868
    // 0x8001F798: nop

        goto L_8001F868;
    // 0x8001F798: nop

L_8001F79C:
    // 0x8001F79C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001F7A0: lw          $a0, 0x11DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11DC);
    // 0x8001F7A4: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8001F7A8: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x8001F7AC: jal         0x800201A4
    // 0x8001F7B0: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    func_800201A4(rdram, ctx);
        goto after_13;
    // 0x8001F7B0: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_13:
    // 0x8001F7B4: lw          $t1, 0xAC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XAC);
    // 0x8001F7B8: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8001F7BC: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8001F7C0: lwc1        $f10, 0x28($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X28);
    // 0x8001F7C4: lwc1        $f18, 0x2C($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X2C);
    // 0x8001F7C8: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8001F7CC: nop

    // 0x8001F7D0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001F7D4: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8001F7D8: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8001F7DC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8001F7E0: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8001F7E4: nop

    // 0x8001F7E8: sw          $t2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r10;
    // 0x8001F7EC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8001F7F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001F7F4: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x8001F7F8: jal         0x80026BE0
    // 0x8001F7FC: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_80026BE0(rdram, ctx);
        goto after_14;
    // 0x8001F7FC: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_14:
    // 0x8001F800: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x8001F804: beq         $t7, $zero, L_8001F848
    if (ctx->r15 == 0) {
        // 0x8001F808: nop
    
            goto L_8001F848;
    }
    // 0x8001F808: nop

    // 0x8001F80C: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x8001F810: sh          $t8, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r24;
    // 0x8001F814: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8001F818: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x8001F81C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001F820: lw          $a0, 0x11DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11DC);
    // 0x8001F824: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x8001F828: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x8001F82C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001F830: jal         0x80026500
    // 0x8001F834: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    func_80026500(rdram, ctx);
        goto after_15;
    // 0x8001F834: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_15:
    // 0x8001F838: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8001F83C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8001F840: b           L_8001F850
    // 0x8001F844: sb          $t4, 0x45($t6)
    MEM_B(0X45, ctx->r14) = ctx->r12;
        goto L_8001F850;
    // 0x8001F844: sb          $t4, 0x45($t6)
    MEM_B(0X45, ctx->r14) = ctx->r12;
L_8001F848:
    // 0x8001F848: jal         0x800200B8
    // 0x8001F84C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_800200B8(rdram, ctx);
        goto after_16;
    // 0x8001F84C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_16:
L_8001F850:
    // 0x8001F850: b           L_8001F870
    // 0x8001F854: nop

        goto L_8001F870;
    // 0x8001F854: nop

L_8001F858:
    // 0x8001F858: jal         0x800200B8
    // 0x8001F85C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_800200B8(rdram, ctx);
        goto after_17;
    // 0x8001F85C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_17:
    // 0x8001F860: b           L_8001F870
    // 0x8001F864: nop

        goto L_8001F870;
    // 0x8001F864: nop

L_8001F868:
    // 0x8001F868: b           L_8001F870
    // 0x8001F86C: nop

        goto L_8001F870;
    // 0x8001F86C: nop

L_8001F870:
    // 0x8001F870: lw          $t1, 0xB8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB8);
    // 0x8001F874: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001F878: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x8001F87C: bne         $t3, $at, L_8001F890
    if (ctx->r11 != ctx->r1) {
        // 0x8001F880: nop
    
            goto L_8001F890;
    }
    // 0x8001F880: nop

    // 0x8001F884: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x8001F888: addiu       $t5, $zero, 0x1000
    ctx->r13 = ADD32(0, 0X1000);
    // 0x8001F88C: sh          $t5, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r13;
L_8001F890:
    // 0x8001F890: b           L_80020040
    // 0x8001F894: nop

        goto L_80020040;
    // 0x8001F894: nop

L_8001F898:
    // 0x8001F898: lw          $t2, 0xB8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB8);
    // 0x8001F89C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8001F8A0: lw          $t7, 0x8($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X8);
    // 0x8001F8A4: sb          $t7, 0x41($t8)
    MEM_B(0X41, ctx->r24) = ctx->r15;
    // 0x8001F8A8: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8001F8AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001F8B0: lbu         $t4, 0x45($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X45);
    // 0x8001F8B4: bne         $t4, $at, L_8001F934
    if (ctx->r12 != ctx->r1) {
        // 0x8001F8B8: nop
    
            goto L_8001F934;
    }
    // 0x8001F8B8: nop

    // 0x8001F8BC: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8001F8C0: lw          $t3, 0xAC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XAC);
    // 0x8001F8C4: lbu         $t1, 0x41($t6)
    ctx->r9 = MEM_BU(ctx->r14, 0X41);
    // 0x8001F8C8: lbu         $t5, 0xD4($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0XD4);
    // 0x8001F8CC: addu        $t0, $t1, $t5
    ctx->r8 = ADD32(ctx->r9, ctx->r13);
    // 0x8001F8D0: addiu       $t2, $t0, -0x40
    ctx->r10 = ADD32(ctx->r8, -0X40);
    // 0x8001F8D4: sw          $t2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r10;
    // 0x8001F8D8: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8001F8DC: blez        $t7, L_8001F8EC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8001F8E0: nop
    
            goto L_8001F8EC;
    }
    // 0x8001F8E0: nop

    // 0x8001F8E4: b           L_8001F8F0
    // 0x8001F8E8: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
        goto L_8001F8F0;
    // 0x8001F8E8: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
L_8001F8EC:
    // 0x8001F8EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001F8F0:
    // 0x8001F8F0: slti        $at, $s0, 0x7F
    ctx->r1 = SIGNED(ctx->r16) < 0X7F ? 1 : 0;
    // 0x8001F8F4: beq         $at, $zero, L_8001F91C
    if (ctx->r1 == 0) {
        // 0x8001F8F8: nop
    
            goto L_8001F91C;
    }
    // 0x8001F8F8: nop

    // 0x8001F8FC: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8001F900: blez        $t8, L_8001F910
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8001F904: nop
    
            goto L_8001F910;
    }
    // 0x8001F904: nop

    // 0x8001F908: b           L_8001F914
    // 0x8001F90C: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
        goto L_8001F914;
    // 0x8001F90C: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
L_8001F910:
    // 0x8001F910: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8001F914:
    // 0x8001F914: b           L_8001F924
    // 0x8001F918: sb          $s1, 0xA7($sp)
    MEM_B(0XA7, ctx->r29) = ctx->r17;
        goto L_8001F924;
    // 0x8001F918: sb          $s1, 0xA7($sp)
    MEM_B(0XA7, ctx->r29) = ctx->r17;
L_8001F91C:
    // 0x8001F91C: addiu       $t9, $zero, 0x7F
    ctx->r25 = ADD32(0, 0X7F);
    // 0x8001F920: sb          $t9, 0xA7($sp)
    MEM_B(0XA7, ctx->r29) = ctx->r25;
L_8001F924:
    // 0x8001F924: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8001F928: lbu         $a1, 0xA7($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XA7);
    // 0x8001F92C: jal         0x80026DE0
    // 0x8001F930: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_80026DE0(rdram, ctx);
        goto after_18;
    // 0x8001F930: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_18:
L_8001F934:
    // 0x8001F934: b           L_80020040
    // 0x8001F938: nop

        goto L_80020040;
    // 0x8001F938: nop

L_8001F93C:
    // 0x8001F93C: lw          $t4, 0xB8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB8);
    // 0x8001F940: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8001F944: lwc1        $f8, 0x8($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8001F948: swc1        $f8, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->f8.u32l;
    // 0x8001F94C: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8001F950: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001F954: lbu         $t1, 0x45($t3)
    ctx->r9 = MEM_BU(ctx->r11, 0X45);
    // 0x8001F958: bne         $t1, $at, L_8001F99C
    if (ctx->r9 != ctx->r1) {
        // 0x8001F95C: nop
    
            goto L_8001F99C;
    }
    // 0x8001F95C: nop

    // 0x8001F960: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8001F964: lwc1        $f10, 0x2C($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X2C);
    // 0x8001F968: lwc1        $f16, 0x28($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X28);
    // 0x8001F96C: addiu       $a0, $t5, 0xC
    ctx->r4 = ADD32(ctx->r13, 0XC);
    // 0x8001F970: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001F974: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8001F978: jal         0x80026E90
    // 0x8001F97C: nop

    func_80026E90(rdram, ctx);
        goto after_19;
    // 0x8001F97C: nop

    after_19:
    // 0x8001F980: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8001F984: lbu         $t2, 0x44($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X44);
    // 0x8001F988: andi        $t7, $t2, 0x20
    ctx->r15 = ctx->r10 & 0X20;
    // 0x8001F98C: beq         $t7, $zero, L_8001F99C
    if (ctx->r15 == 0) {
        // 0x8001F990: nop
    
            goto L_8001F99C;
    }
    // 0x8001F990: nop

    // 0x8001F994: jal         0x80020128
    // 0x8001F998: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_80020128(rdram, ctx);
        goto after_20;
    // 0x8001F998: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_20:
L_8001F99C:
    // 0x8001F99C: b           L_80020040
    // 0x8001F9A0: nop

        goto L_80020040;
    // 0x8001F9A0: nop

L_8001F9A4:
    // 0x8001F9A4: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x8001F9A8: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8001F9AC: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8001F9B0: sb          $t9, 0x42($t4)
    MEM_B(0X42, ctx->r12) = ctx->r25;
    // 0x8001F9B4: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8001F9B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001F9BC: lbu         $t3, 0x45($t6)
    ctx->r11 = MEM_BU(ctx->r14, 0X45);
    // 0x8001F9C0: bne         $t3, $at, L_8001FA60
    if (ctx->r11 != ctx->r1) {
        // 0x8001F9C4: nop
    
            goto L_8001FA60;
    }
    // 0x8001F9C4: nop

    // 0x8001F9C8: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x8001F9CC: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8001F9D0: lbu         $t7, 0x3($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X3);
    // 0x8001F9D4: lbu         $t5, 0x42($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X42);
    // 0x8001F9D8: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x8001F9DC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8001F9E0: andi        $t0, $t5, 0x7F
    ctx->r8 = ctx->r13 & 0X7F;
    // 0x8001F9E4: addu        $t4, $t0, $t9
    ctx->r12 = ADD32(ctx->r8, ctx->r25);
    // 0x8001F9E8: sw          $t4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r12;
    // 0x8001F9EC: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x8001F9F0: bgez        $t6, L_8001FA00
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8001F9F4: nop
    
            goto L_8001FA00;
    }
    // 0x8001F9F4: nop

    // 0x8001F9F8: b           L_8001FA04
    // 0x8001F9FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_8001FA04;
    // 0x8001F9FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001FA00:
    // 0x8001FA00: lw          $s0, 0x7C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X7C);
L_8001FA04:
    // 0x8001FA04: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // 0x8001FA08: bne         $at, $zero, L_8001FA1C
    if (ctx->r1 != 0) {
        // 0x8001FA0C: nop
    
            goto L_8001FA1C;
    }
    // 0x8001FA0C: nop

    // 0x8001FA10: addiu       $t3, $zero, 0x7F
    ctx->r11 = ADD32(0, 0X7F);
    // 0x8001FA14: b           L_8001FA38
    // 0x8001FA18: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
        goto L_8001FA38;
    // 0x8001FA18: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
L_8001FA1C:
    // 0x8001FA1C: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x8001FA20: bgez        $t1, L_8001FA30
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8001FA24: nop
    
            goto L_8001FA30;
    }
    // 0x8001FA24: nop

    // 0x8001FA28: b           L_8001FA34
    // 0x8001FA2C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_8001FA34;
    // 0x8001FA2C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8001FA30:
    // 0x8001FA30: lw          $s1, 0x7C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X7C);
L_8001FA34:
    // 0x8001FA34: sw          $s1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r17;
L_8001FA38:
    // 0x8001FA38: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8001FA3C: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x8001FA40: lbu         $t7, 0x42($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X42);
    // 0x8001FA44: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x8001FA48: or          $t0, $t5, $t8
    ctx->r8 = ctx->r13 | ctx->r24;
    // 0x8001FA4C: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x8001FA50: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8001FA54: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x8001FA58: jal         0x80026F40
    // 0x8001FA5C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_80026F40(rdram, ctx);
        goto after_21;
    // 0x8001FA5C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_21:
L_8001FA60:
    // 0x8001FA60: b           L_80020040
    // 0x8001FA64: nop

        goto L_80020040;
    // 0x8001FA64: nop

L_8001FA68:
    // 0x8001FA68: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    // 0x8001FA6C: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8001FA70: lw          $t4, 0x8($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X8);
    // 0x8001FA74: sb          $t4, 0x43($t6)
    MEM_B(0X43, ctx->r14) = ctx->r12;
    // 0x8001FA78: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x8001FA7C: lw          $t2, 0x11F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X11F4);
    // 0x8001FA80: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8001FA84: lw          $t7, 0x3C($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X3C);
    // 0x8001FA88: lbu         $t1, 0x43($t3)
    ctx->r9 = MEM_BU(ctx->r11, 0X43);
    // 0x8001FA8C: slt         $at, $t1, $t7
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001FA90: bne         $at, $zero, L_8001FAA0
    if (ctx->r1 != 0) {
        // 0x8001FA94: nop
    
            goto L_8001FAA0;
    }
    // 0x8001FA94: nop

    // 0x8001FA98: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8001FA9C: sb          $zero, 0x43($t5)
    MEM_B(0X43, ctx->r13) = 0;
L_8001FAA0:
    // 0x8001FAA0: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8001FAA4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001FAA8: lbu         $t0, 0x45($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X45);
    // 0x8001FAAC: bne         $t0, $at, L_8001FAC0
    if (ctx->r8 != ctx->r1) {
        // 0x8001FAB0: nop
    
            goto L_8001FAC0;
    }
    // 0x8001FAB0: nop

    // 0x8001FAB4: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8001FAB8: lbu         $t4, 0x43($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X43);
    // 0x8001FABC: sh          $t4, 0x24($t9)
    MEM_H(0X24, ctx->r25) = ctx->r12;
L_8001FAC0:
    // 0x8001FAC0: b           L_80020040
    // 0x8001FAC4: nop

        goto L_80020040;
    // 0x8001FAC4: nop

L_8001FAC8:
    // 0x8001FAC8: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x8001FACC: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8001FAD0: lw          $t3, 0x8($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X8);
    // 0x8001FAD4: sh          $t3, 0x38($t2)
    MEM_H(0X38, ctx->r10) = ctx->r11;
    // 0x8001FAD8: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8001FADC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001FAE0: lbu         $t7, 0x45($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X45);
    // 0x8001FAE4: bne         $t7, $at, L_8001FC5C
    if (ctx->r15 != ctx->r1) {
        // 0x8001FAE8: nop
    
            goto L_8001FC5C;
    }
    // 0x8001FAE8: nop

    // 0x8001FAEC: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8001FAF0: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x8001FAF4: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x8001FAF8: lh          $t1, 0x3A($t2)
    ctx->r9 = MEM_H(ctx->r10, 0X3A);
    // 0x8001FAFC: lh          $t7, 0x38($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X38);
    // 0x8001FB00: lbu         $t0, 0x2($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X2);
    // 0x8001FB04: lw          $t5, -0x15DC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X15DC);
    // 0x8001FB08: multu       $t1, $t7
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001FB0C: andi        $t4, $t0, 0x1F
    ctx->r12 = ctx->r8 & 0X1F;
    // 0x8001FB10: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
    // 0x8001FB14: sll         $t9, $t4, 1
    ctx->r25 = S32(ctx->r12 << 1);
    // 0x8001FB18: addu        $t6, $t5, $t9
    ctx->r14 = ADD32(ctx->r13, ctx->r25);
    // 0x8001FB1C: lbu         $t4, 0xD5($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0XD5);
    // 0x8001FB20: addiu       $at, $zero, 0x3F01
    ctx->r1 = ADD32(0, 0X3F01);
    // 0x8001FB24: lh          $t3, 0x0($t6)
    ctx->r11 = MEM_H(ctx->r14, 0X0);
    // 0x8001FB28: mflo        $t8
    ctx->r24 = lo;
    // 0x8001FB2C: nop

    // 0x8001FB30: nop

    // 0x8001FB34: multu       $t8, $t4
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001FB38: mflo        $t5
    ctx->r13 = lo;
    // 0x8001FB3C: nop

    // 0x8001FB40: nop

    // 0x8001FB44: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x8001FB48: mflo        $t9
    ctx->r25 = lo;
    // 0x8001FB4C: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x8001FB50: nop

    // 0x8001FB54: multu       $t3, $t9
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001FB58: mflo        $t6
    ctx->r14 = lo;
    // 0x8001FB5C: nop

    // 0x8001FB60: nop

    // 0x8001FB64: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x8001FB68: mflo        $t2
    ctx->r10 = lo;
    // 0x8001FB6C: bgtz        $t2, L_8001FB7C
    if (SIGNED(ctx->r10) > 0) {
        // 0x8001FB70: nop
    
            goto L_8001FB7C;
    }
    // 0x8001FB70: nop

    // 0x8001FB74: b           L_8001FC04
    // 0x8001FB78: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
        goto L_8001FC04;
    // 0x8001FB78: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
L_8001FB7C:
    // 0x8001FB7C: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8001FB80: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x8001FB84: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8001FB88: lh          $t6, 0x3A($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X3A);
    // 0x8001FB8C: lh          $t2, 0x38($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X38);
    // 0x8001FB90: lbu         $t0, 0x2($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0X2);
    // 0x8001FB94: lw          $t1, -0x15DC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X15DC);
    // 0x8001FB98: multu       $t6, $t2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001FB9C: andi        $t8, $t0, 0x1F
    ctx->r24 = ctx->r8 & 0X1F;
    // 0x8001FBA0: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
    // 0x8001FBA4: sll         $t4, $t8, 1
    ctx->r12 = S32(ctx->r24 << 1);
    // 0x8001FBA8: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x8001FBAC: lbu         $t8, 0xD5($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XD5);
    // 0x8001FBB0: addiu       $at, $zero, 0x3F01
    ctx->r1 = ADD32(0, 0X3F01);
    // 0x8001FBB4: lh          $t3, 0x0($t5)
    ctx->r11 = MEM_H(ctx->r13, 0X0);
    // 0x8001FBB8: mflo        $t7
    ctx->r15 = lo;
    // 0x8001FBBC: nop

    // 0x8001FBC0: nop

    // 0x8001FBC4: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001FBC8: mflo        $t1
    ctx->r9 = lo;
    // 0x8001FBCC: nop

    // 0x8001FBD0: nop

    // 0x8001FBD4: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x8001FBD8: mflo        $t4
    ctx->r12 = lo;
    // 0x8001FBDC: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x8001FBE0: nop

    // 0x8001FBE4: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001FBE8: mflo        $t5
    ctx->r13 = lo;
    // 0x8001FBEC: nop

    // 0x8001FBF0: nop

    // 0x8001FBF4: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x8001FBF8: mflo        $t9
    ctx->r25 = lo;
    // 0x8001FBFC: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x8001FC00: sw          $t6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r14;
L_8001FC04:
    // 0x8001FC04: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8001FC08: lw          $t7, 0x11DC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X11DC);
    // 0x8001FC0C: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8001FC10: lw          $t8, 0x50($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X50);
    // 0x8001FC14: lw          $t0, 0x3C($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X3C);
    // 0x8001FC18: subu        $t1, $t0, $t8
    ctx->r9 = SUB32(ctx->r8, ctx->r24);
    // 0x8001FC1C: slti        $at, $t1, 0x3E8
    ctx->r1 = SIGNED(ctx->r9) < 0X3E8 ? 1 : 0;
    // 0x8001FC20: beq         $at, $zero, L_8001FC30
    if (ctx->r1 == 0) {
        // 0x8001FC24: nop
    
            goto L_8001FC30;
    }
    // 0x8001FC24: nop

    // 0x8001FC28: b           L_8001FC48
    // 0x8001FC2C: addiu       $s0, $zero, 0x3E8
    ctx->r16 = ADD32(0, 0X3E8);
        goto L_8001FC48;
    // 0x8001FC2C: addiu       $s0, $zero, 0x3E8
    ctx->r16 = ADD32(0, 0X3E8);
L_8001FC30:
    // 0x8001FC30: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x8001FC34: lw          $t5, 0x11DC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X11DC);
    // 0x8001FC38: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8001FC3C: lw          $t9, 0x50($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X50);
    // 0x8001FC40: lw          $t4, 0x3C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X3C);
    // 0x8001FC44: subu        $s0, $t4, $t9
    ctx->r16 = SUB32(ctx->r12, ctx->r25);
L_8001FC48:
    // 0x8001FC48: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8001FC4C: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x8001FC50: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8001FC54: jal         0x80026BE0
    // 0x8001FC58: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_80026BE0(rdram, ctx);
        goto after_22;
    // 0x8001FC58: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_22:
L_8001FC5C:
    // 0x8001FC5C: b           L_80020040
    // 0x8001FC60: nop

        goto L_80020040;
    // 0x8001FC60: nop

L_8001FC64:
    // 0x8001FC64: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8001FC68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001FC6C: lbu         $t2, 0x45($t6)
    ctx->r10 = MEM_BU(ctx->r14, 0X45);
    // 0x8001FC70: bne         $t2, $at, L_8001FDDC
    if (ctx->r10 != ctx->r1) {
        // 0x8001FC74: nop
    
            goto L_8001FDDC;
    }
    // 0x8001FC74: nop

    // 0x8001FC78: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x8001FC7C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8001FC80: lw          $t0, 0x8($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X8);
    // 0x8001FC84: lwc1        $f8, 0x28($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X28);
    // 0x8001FC88: lwc1        $f16, 0x2C($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X2C);
    // 0x8001FC8C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8001FC90: nop

    // 0x8001FC94: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001FC98: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001FC9C: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001FCA0: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8001FCA4: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x8001FCA8: nop

    // 0x8001FCAC: sw          $t3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r11;
    // 0x8001FCB0: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8001FCB4: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    // 0x8001FCB8: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x8001FCBC: lh          $t1, 0x3A($t8)
    ctx->r9 = MEM_H(ctx->r24, 0X3A);
    // 0x8001FCC0: lh          $t3, 0x38($t8)
    ctx->r11 = MEM_H(ctx->r24, 0X38);
    // 0x8001FCC4: lbu         $t9, 0x2($t4)
    ctx->r25 = MEM_BU(ctx->r12, 0X2);
    // 0x8001FCC8: lw          $t5, -0x15DC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X15DC);
    // 0x8001FCCC: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001FCD0: andi        $t6, $t9, 0x1F
    ctx->r14 = ctx->r25 & 0X1F;
    // 0x8001FCD4: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x8001FCD8: sll         $t2, $t6, 1
    ctx->r10 = S32(ctx->r14 << 1);
    // 0x8001FCDC: addu        $t7, $t5, $t2
    ctx->r15 = ADD32(ctx->r13, ctx->r10);
    // 0x8001FCE0: lbu         $t6, 0xD5($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XD5);
    // 0x8001FCE4: addiu       $at, $zero, 0x3F01
    ctx->r1 = ADD32(0, 0X3F01);
    // 0x8001FCE8: lh          $t0, 0x0($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X0);
    // 0x8001FCEC: mflo        $t4
    ctx->r12 = lo;
    // 0x8001FCF0: nop

    // 0x8001FCF4: nop

    // 0x8001FCF8: multu       $t4, $t6
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001FCFC: mflo        $t5
    ctx->r13 = lo;
    // 0x8001FD00: nop

    // 0x8001FD04: nop

    // 0x8001FD08: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x8001FD0C: mflo        $t2
    ctx->r10 = lo;
    // 0x8001FD10: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x8001FD14: nop

    // 0x8001FD18: multu       $t0, $t2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001FD1C: mflo        $t7
    ctx->r15 = lo;
    // 0x8001FD20: nop

    // 0x8001FD24: nop

    // 0x8001FD28: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x8001FD2C: mflo        $t8
    ctx->r24 = lo;
    // 0x8001FD30: bgtz        $t8, L_8001FD40
    if (SIGNED(ctx->r24) > 0) {
        // 0x8001FD34: nop
    
            goto L_8001FD40;
    }
    // 0x8001FD34: nop

    // 0x8001FD38: b           L_8001FDC8
    // 0x8001FD3C: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
        goto L_8001FDC8;
    // 0x8001FD3C: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
L_8001FD40:
    // 0x8001FD40: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8001FD44: lw          $t3, 0xA8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA8);
    // 0x8001FD48: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8001FD4C: lh          $t7, 0x3A($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X3A);
    // 0x8001FD50: lh          $t8, 0x38($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X38);
    // 0x8001FD54: lbu         $t9, 0x2($t3)
    ctx->r25 = MEM_BU(ctx->r11, 0X2);
    // 0x8001FD58: lw          $t1, -0x15DC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X15DC);
    // 0x8001FD5C: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001FD60: andi        $t4, $t9, 0x1F
    ctx->r12 = ctx->r25 & 0X1F;
    // 0x8001FD64: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x8001FD68: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x8001FD6C: addu        $t5, $t1, $t6
    ctx->r13 = ADD32(ctx->r9, ctx->r14);
    // 0x8001FD70: lbu         $t4, 0xD5($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0XD5);
    // 0x8001FD74: addiu       $at, $zero, 0x3F01
    ctx->r1 = ADD32(0, 0X3F01);
    // 0x8001FD78: lh          $t0, 0x0($t5)
    ctx->r8 = MEM_H(ctx->r13, 0X0);
    // 0x8001FD7C: mflo        $t3
    ctx->r11 = lo;
    // 0x8001FD80: nop

    // 0x8001FD84: nop

    // 0x8001FD88: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001FD8C: mflo        $t1
    ctx->r9 = lo;
    // 0x8001FD90: nop

    // 0x8001FD94: nop

    // 0x8001FD98: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x8001FD9C: mflo        $t6
    ctx->r14 = lo;
    // 0x8001FDA0: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x8001FDA4: nop

    // 0x8001FDA8: multu       $t0, $t6
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001FDAC: mflo        $t5
    ctx->r13 = lo;
    // 0x8001FDB0: nop

    // 0x8001FDB4: nop

    // 0x8001FDB8: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x8001FDBC: mflo        $t2
    ctx->r10 = lo;
    // 0x8001FDC0: addiu       $t7, $t2, -0x1
    ctx->r15 = ADD32(ctx->r10, -0X1);
    // 0x8001FDC4: sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
L_8001FDC8:
    // 0x8001FDC8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8001FDCC: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x8001FDD0: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x8001FDD4: jal         0x80026BE0
    // 0x8001FDD8: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_80026BE0(rdram, ctx);
        goto after_23;
    // 0x8001FDD8: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_23:
L_8001FDDC:
    // 0x8001FDDC: b           L_80020040
    // 0x8001FDE0: nop

        goto L_80020040;
    // 0x8001FDE0: nop

L_8001FDE4:
    // 0x8001FDE4: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8001FDE8: lbu         $t9, 0x44($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X44);
    // 0x8001FDEC: andi        $t3, $t9, 0x2
    ctx->r11 = ctx->r25 & 0X2;
    // 0x8001FDF0: bne         $t3, $zero, L_8001FFD0
    if (ctx->r11 != 0) {
        // 0x8001FDF4: nop
    
            goto L_8001FFD0;
    }
    // 0x8001FDF4: nop

    // 0x8001FDF8: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
    // 0x8001FDFC: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8001FE00: lbu         $t1, 0xD($t4)
    ctx->r9 = MEM_BU(ctx->r12, 0XD);
    // 0x8001FE04: sh          $t1, 0x3A($t0)
    MEM_H(0X3A, ctx->r8) = ctx->r9;
    // 0x8001FE08: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8001FE0C: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    // 0x8001FE10: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001FE14: lh          $t1, 0x3A($t4)
    ctx->r9 = MEM_H(ctx->r12, 0X3A);
    // 0x8001FE18: lh          $t0, 0x38($t4)
    ctx->r8 = MEM_H(ctx->r12, 0X38);
    // 0x8001FE1C: lbu         $t2, 0x2($t5)
    ctx->r10 = MEM_BU(ctx->r13, 0X2);
    // 0x8001FE20: lw          $t6, -0x15DC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X15DC);
    // 0x8001FE24: multu       $t1, $t0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001FE28: andi        $t7, $t2, 0x1F
    ctx->r15 = ctx->r10 & 0X1F;
    // 0x8001FE2C: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x8001FE30: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8001FE34: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8001FE38: lbu         $t7, 0xD5($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0XD5);
    // 0x8001FE3C: addiu       $at, $zero, 0x3F01
    ctx->r1 = ADD32(0, 0X3F01);
    // 0x8001FE40: lh          $t3, 0x0($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X0);
    // 0x8001FE44: mflo        $t5
    ctx->r13 = lo;
    // 0x8001FE48: nop

    // 0x8001FE4C: nop

    // 0x8001FE50: multu       $t5, $t7
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001FE54: mflo        $t6
    ctx->r14 = lo;
    // 0x8001FE58: nop

    // 0x8001FE5C: nop

    // 0x8001FE60: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x8001FE64: mflo        $t8
    ctx->r24 = lo;
    // 0x8001FE68: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x8001FE6C: nop

    // 0x8001FE70: multu       $t3, $t8
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001FE74: mflo        $t9
    ctx->r25 = lo;
    // 0x8001FE78: nop

    // 0x8001FE7C: nop

    // 0x8001FE80: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x8001FE84: mflo        $t4
    ctx->r12 = lo;
    // 0x8001FE88: bgtz        $t4, L_8001FE98
    if (SIGNED(ctx->r12) > 0) {
        // 0x8001FE8C: nop
    
            goto L_8001FE98;
    }
    // 0x8001FE8C: nop

    // 0x8001FE90: b           L_8001FF20
    // 0x8001FE94: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
        goto L_8001FF20;
    // 0x8001FE94: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
L_8001FE98:
    // 0x8001FE98: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8001FE9C: lw          $t0, 0xA8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA8);
    // 0x8001FEA0: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8001FEA4: lh          $t9, 0x3A($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X3A);
    // 0x8001FEA8: lh          $t4, 0x38($t8)
    ctx->r12 = MEM_H(ctx->r24, 0X38);
    // 0x8001FEAC: lbu         $t2, 0x2($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X2);
    // 0x8001FEB0: lw          $t1, -0x15DC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X15DC);
    // 0x8001FEB4: multu       $t9, $t4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001FEB8: andi        $t5, $t2, 0x1F
    ctx->r13 = ctx->r10 & 0X1F;
    // 0x8001FEBC: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x8001FEC0: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x8001FEC4: addu        $t6, $t1, $t7
    ctx->r14 = ADD32(ctx->r9, ctx->r15);
    // 0x8001FEC8: lbu         $t5, 0xD5($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0XD5);
    // 0x8001FECC: addiu       $at, $zero, 0x3F01
    ctx->r1 = ADD32(0, 0X3F01);
    // 0x8001FED0: lh          $t3, 0x0($t6)
    ctx->r11 = MEM_H(ctx->r14, 0X0);
    // 0x8001FED4: mflo        $t0
    ctx->r8 = lo;
    // 0x8001FED8: nop

    // 0x8001FEDC: nop

    // 0x8001FEE0: multu       $t0, $t5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001FEE4: mflo        $t1
    ctx->r9 = lo;
    // 0x8001FEE8: nop

    // 0x8001FEEC: nop

    // 0x8001FEF0: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x8001FEF4: mflo        $t7
    ctx->r15 = lo;
    // 0x8001FEF8: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x8001FEFC: nop

    // 0x8001FF00: multu       $t3, $t7
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001FF04: mflo        $t6
    ctx->r14 = lo;
    // 0x8001FF08: nop

    // 0x8001FF0C: nop

    // 0x8001FF10: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x8001FF14: mflo        $t8
    ctx->r24 = lo;
    // 0x8001FF18: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8001FF1C: sw          $t9, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r25;
L_8001FF20:
    // 0x8001FF20: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
    // 0x8001FF24: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8001FF28: lw          $t2, 0x4($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X4);
    // 0x8001FF2C: lwc1        $f10, 0x28($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X28);
    // 0x8001FF30: lwc1        $f18, 0x2C($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X2C);
    // 0x8001FF34: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8001FF38: nop

    // 0x8001FF3C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001FF40: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8001FF44: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8001FF48: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8001FF4C: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x8001FF50: nop

    // 0x8001FF54: sw          $t1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r9;
    // 0x8001FF58: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x8001FF5C: lw          $t3, 0x11DC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X11DC);
    // 0x8001FF60: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x8001FF64: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8001FF68: lw          $t7, 0x50($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X50);
    // 0x8001FF6C: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x8001FF70: sw          $t8, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->r24;
    // 0x8001FF74: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8001FF78: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x8001FF7C: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x8001FF80: jal         0x80026BE0
    // 0x8001FF84: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_80026BE0(rdram, ctx);
        goto after_24;
    // 0x8001FF84: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_24:
    // 0x8001FF88: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8001FF8C: sh          $t4, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r12;
    // 0x8001FF90: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8001FF94: sw          $t2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r10;
    // 0x8001FF98: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001FF9C: lw          $a0, 0x11DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11DC);
    // 0x8001FFA0: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x8001FFA4: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x8001FFA8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001FFAC: jal         0x80026500
    // 0x8001FFB0: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    func_80026500(rdram, ctx);
        goto after_25;
    // 0x8001FFB0: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_25:
    // 0x8001FFB4: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8001FFB8: lbu         $t5, 0x44($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X44);
    // 0x8001FFBC: andi        $t1, $t5, 0x20
    ctx->r9 = ctx->r13 & 0X20;
    // 0x8001FFC0: beq         $t1, $zero, L_8001FFD0
    if (ctx->r9 == 0) {
        // 0x8001FFC4: nop
    
            goto L_8001FFD0;
    }
    // 0x8001FFC4: nop

    // 0x8001FFC8: jal         0x80020128
    // 0x8001FFCC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_80020128(rdram, ctx);
        goto after_26;
    // 0x8001FFCC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_26:
L_8001FFD0:
    // 0x8001FFD0: b           L_80020040
    // 0x8001FFD4: nop

        goto L_80020040;
    // 0x8001FFD4: nop

L_8001FFD8:
    // 0x8001FFD8: jal         0x800200B8
    // 0x8001FFDC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_800200B8(rdram, ctx);
        goto after_27;
    // 0x8001FFDC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_27:
    // 0x8001FFE0: b           L_80020040
    // 0x8001FFE4: nop

        goto L_80020040;
    // 0x8001FFE4: nop

L_8001FFE8:
    // 0x8001FFE8: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8001FFEC: lbu         $t7, 0x44($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X44);
    // 0x8001FFF0: andi        $t6, $t7, 0x10
    ctx->r14 = ctx->r15 & 0X10;
    // 0x8001FFF4: beq         $t6, $zero, L_80020030
    if (ctx->r14 == 0) {
        // 0x8001FFF8: nop
    
            goto L_80020030;
    }
    // 0x8001FFF8: nop

    // 0x8001FFFC: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x80020000: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x80020004: lbu         $t4, 0x42($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X42);
    // 0x80020008: lh          $a1, 0x38($t9)
    ctx->r5 = MEM_H(ctx->r25, 0X38);
    // 0x8002000C: lbu         $a2, 0x41($t9)
    ctx->r6 = MEM_BU(ctx->r25, 0X41);
    // 0x80020010: lw          $a3, 0x2C($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X2C);
    // 0x80020014: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    // 0x80020018: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8002001C: lbu         $t2, 0x43($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X43);
    // 0x80020020: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80020024: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80020028: jal         0x80020790
    // 0x8002002C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    func_80020790(rdram, ctx);
        goto after_28;
    // 0x8002002C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_28:
L_80020030:
    // 0x80020030: b           L_80020040
    // 0x80020034: nop

        goto L_80020040;
    // 0x80020034: nop

L_80020038:
    // 0x80020038: b           L_80020040
    // 0x8002003C: nop

        goto L_80020040;
    // 0x8002003C: nop

L_80020040:
    // 0x80020040: lw          $t5, 0xB8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB8);
    // 0x80020044: lhu         $t1, 0x0($t5)
    ctx->r9 = MEM_HU(ctx->r13, 0X0);
    // 0x80020048: andi        $t3, $t1, 0x2D1
    ctx->r11 = ctx->r9 & 0X2D1;
    // 0x8002004C: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
    // 0x80020050: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80020054: beq         $t7, $zero, L_80020078
    if (ctx->r15 == 0) {
        // 0x80020058: sw          $t7, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r15;
            goto L_80020078;
    }
    // 0x80020058: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
    // 0x8002005C: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x80020060: bne         $t6, $zero, L_80020078
    if (ctx->r14 != 0) {
        // 0x80020064: nop
    
            goto L_80020078;
    }
    // 0x80020064: nop

    // 0x80020068: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8002006C: lbu         $t4, 0x44($t8)
    ctx->r12 = MEM_BU(ctx->r24, 0X44);
    // 0x80020070: andi        $t2, $t4, 0x1
    ctx->r10 = ctx->r12 & 0X1;
    // 0x80020074: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
L_80020078:
    // 0x80020078: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x8002007C: bne         $t9, $zero, L_8002009C
    if (ctx->r25 != 0) {
        // 0x80020080: nop
    
            goto L_8002009C;
    }
    // 0x80020080: nop

    // 0x80020084: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80020088: beq         $t0, $zero, L_8002009C
    if (ctx->r8 == 0) {
        // 0x8002008C: nop
    
            goto L_8002009C;
    }
    // 0x8002008C: nop

    // 0x80020090: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x80020094: beq         $t5, $zero, L_8001EE5C
    if (ctx->r13 == 0) {
        // 0x80020098: nop
    
            goto L_8001EE5C;
    }
    // 0x80020098: nop

L_8002009C:
    // 0x8002009C: b           L_800200A4
    // 0x800200A0: nop

        goto L_800200A4;
    // 0x800200A0: nop

L_800200A4:
    // 0x800200A4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800200A8: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800200AC: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800200B0: jr          $ra
    // 0x800200B4: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800200B4: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_800F8A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8A5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F8A60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8A64: jal         0x800F88A0
    // 0x800F8A68: nop

    func_800F88A0(rdram, ctx);
        goto after_0;
    // 0x800F8A68: nop

    after_0:
    // 0x800F8A6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8A70: lh          $v0, 0x22($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X22);
    // 0x800F8A74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F8A78: jr          $ra
    // 0x800F8A7C: nop

    return;
    // 0x800F8A7C: nop

;}
RECOMP_FUNC void vpflicker_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2986, 0X3F0) << 16);
    // 0x808000D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D8: lwc1        $f12, 0x3F0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2986, 0X3F0));
    // 0x808000DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2986, 0X3F4) << 16);
    // 0x808000E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808000E8: lwc1        $f14, 0x3F4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2986, 0X3F4));
    // 0x808000EC: jal         0x800DC264
    // 0x808000F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800DC264(rdram, ctx);
        goto after_0;
    // 0x808000F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000F4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x808000F8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808000FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800100: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80800104: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800108: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2986, 0X3F8) << 16);
    // 0x8080010C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800110: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800114: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80800118: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
    // 0x8080011C: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80800120: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80800124: nop

    // 0x80800128: bc1fl       L_8080013C
    if (!c1cs) {
        // 0x8080012C: swc1        $f2, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->f2.u32l;
            goto L_8080013C;
    }
    goto skip_0;
    // 0x8080012C: swc1        $f2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f2.u32l;
    skip_0:
    // 0x80800130: b           L_8080013C
    // 0x80800134: swc1        $f12, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f12.u32l;
        goto L_8080013C;
    // 0x80800134: swc1        $f12, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f12.u32l;
    // 0x80800138: swc1        $f2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f2.u32l;
L_8080013C:
    // 0x8080013C: lwc1        $f0, 0x3F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2986, 0X3F8));
    // 0x80800140: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80800144: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80800148: nop

    // 0x8080014C: bc1fl       L_80800160
    if (!c1cs) {
        // 0x80800150: swc1        $f2, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->f2.u32l;
            goto L_80800160;
    }
    goto skip_1;
    // 0x80800150: swc1        $f2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f2.u32l;
    skip_1:
    // 0x80800154: b           L_80800160
    // 0x80800158: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
        goto L_80800160;
    // 0x80800158: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
    // 0x8080015C: swc1        $f2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f2.u32l;
L_80800160:
    // 0x80800160: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x80800164: lw          $t6, 0x1C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X1C);
    // 0x80800168: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080016C: blez        $t7, L_808001A4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80800170: addu        $a2, $v1, $t6
        ctx->r6 = ADD32(ctx->r3, ctx->r14);
            goto L_808001A4;
    }
    // 0x80800170: addu        $a2, $v1, $t6
    ctx->r6 = ADD32(ctx->r3, ctx->r14);
    // 0x80800174: addiu       $v1, $a3, 0x8
    ctx->r3 = ADD32(ctx->r7, 0X8);
    // 0x80800178: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
L_8080017C:
    // 0x8080017C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800180: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80800184: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800188: mflo        $t9
    ctx->r25 = lo;
    // 0x8080018C: addu        $t0, $a2, $t9
    ctx->r8 = ADD32(ctx->r6, ctx->r25);
    // 0x80800190: sb          $a1, 0x3($t0)
    MEM_B(0X3, ctx->r8) = ctx->r5;
    // 0x80800194: lw          $t1, 0x4($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X4);
    // 0x80800198: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8080019C: bnel        $at, $zero, L_8080017C
    if (ctx->r1 != 0) {
        // 0x808001A0: lh          $t8, 0x0($v1)
        ctx->r24 = MEM_H(ctx->r3, 0X0);
            goto L_8080017C;
    }
    goto skip_2;
    // 0x808001A0: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    skip_2:
L_808001A4:
    // 0x808001A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001AC: jr          $ra
    // 0x808001B0: nop

    return;
    // 0x808001B0: nop

;}
RECOMP_FUNC void func_808000A4_chfantasycannon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808000A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000AC: jal         0x800B5BE4
    // 0x808000B0: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x808000B0: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_0:
    // 0x808000B4: jal         0x800F54E4
    // 0x808000B8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808000B8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_1:
    // 0x808000BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000C0: jal         0x800F5A00
    // 0x808000C4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x808000C4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x808000C8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x808000CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000D0: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808000D4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2392, 0XCF8) << 16);
    // 0x808000D8: addiu       $t6, $t6, 0xCF8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2392, 0XCF8));
    // 0x808000DC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808000E0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808000E8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808000EC: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x808000F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808000F4: jal         0x800BABB8
    // 0x808000F8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x808000F8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x808000FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800100: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800104: jr          $ra
    // 0x80800108: nop

    return;
    // 0x80800108: nop

;}
RECOMP_FUNC void bastatetimer_getPrevious(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091554: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x80091558: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8009155C: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x80091560: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80091564: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80091568: jr          $ra
    // 0x8009156C: lwc1        $f0, 0x4($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X4);
    return;
    // 0x8009156C: lwc1        $f0, 0x4($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X4);
;}
RECOMP_FUNC void func_80801340_sumultiscore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801340: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801348: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080134C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80801350: jal         0x80088378
    // 0x80801354: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    _gcstatusDll_entrypoint_13(rdram, ctx);
        goto after_0;
    // 0x80801354: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80801358: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080135C: beq         $v0, $at, L_808013AC
    if (ctx->r2 == ctx->r1) {
        // 0x80801360: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_808013AC;
    }
    // 0x80801360: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80801364: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801368: beq         $v0, $at, L_808013D0
    if (ctx->r2 == ctx->r1) {
        // 0x8080136C: addiu       $t2, $zero, 0xBD0
        ctx->r10 = ADD32(0, 0XBD0);
            goto L_808013D0;
    }
    // 0x8080136C: addiu       $t2, $zero, 0xBD0
    ctx->r10 = ADD32(0, 0XBD0);
    // 0x80801370: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801374: beq         $v0, $at, L_808013F0
    if (ctx->r2 == ctx->r1) {
        // 0x80801378: addiu       $t5, $zero, 0xBAB
        ctx->r13 = ADD32(0, 0XBAB);
            goto L_808013F0;
    }
    // 0x80801378: addiu       $t5, $zero, 0xBAB
    ctx->r13 = ADD32(0, 0XBAB);
    // 0x8080137C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80801380: beq         $v0, $at, L_80801410
    if (ctx->r2 == ctx->r1) {
        // 0x80801384: addiu       $t8, $zero, 0xBA2
        ctx->r24 = ADD32(0, 0XBA2);
            goto L_80801410;
    }
    // 0x80801384: addiu       $t8, $zero, 0xBA2
    ctx->r24 = ADD32(0, 0XBA2);
    // 0x80801388: lb          $t7, 0xA($a2)
    ctx->r15 = MEM_B(ctx->r6, 0XA);
    // 0x8080138C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801390: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801394: addiu       $t6, $zero, 0xB50
    ctx->r14 = ADD32(0, 0XB50);
    // 0x80801398: addiu       $t8, $t7, 0xA
    ctx->r24 = ADD32(ctx->r15, 0XA);
    // 0x8080139C: sb          $t8, 0xA($a2)
    MEM_B(0XA, ctx->r6) = ctx->r24;
    // 0x808013A0: sh          $t6, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r14;
    // 0x808013A4: b           L_8080142C
    // 0x808013A8: swc1        $f4, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f4.u32l;
        goto L_8080142C;
    // 0x808013A8: swc1        $f4, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f4.u32l;
L_808013AC:
    // 0x808013AC: lb          $t0, 0xC($a2)
    ctx->r8 = MEM_B(ctx->r6, 0XC);
    // 0x808013B0: addiu       $t9, $zero, 0xBD9
    ctx->r25 = ADD32(0, 0XBD9);
    // 0x808013B4: sh          $t9, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r25;
    // 0x808013B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3154, 0X149C) << 16);
    // 0x808013BC: lwc1        $f6, 0x149C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3154, 0X149C));
    // 0x808013C0: addiu       $t1, $t0, -0x5
    ctx->r9 = ADD32(ctx->r8, -0X5);
    // 0x808013C4: sb          $t1, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r9;
    // 0x808013C8: b           L_8080142C
    // 0x808013CC: swc1        $f6, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f6.u32l;
        goto L_8080142C;
    // 0x808013CC: swc1        $f6, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f6.u32l;
L_808013D0:
    // 0x808013D0: lb          $t3, 0xC($a2)
    ctx->r11 = MEM_B(ctx->r6, 0XC);
    // 0x808013D4: sh          $t2, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r10;
    // 0x808013D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3154, 0X14A0) << 16);
    // 0x808013DC: lwc1        $f8, 0x14A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3154, 0X14A0));
    // 0x808013E0: addiu       $t4, $t3, -0x5
    ctx->r12 = ADD32(ctx->r11, -0X5);
    // 0x808013E4: sb          $t4, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r12;
    // 0x808013E8: b           L_8080142C
    // 0x808013EC: swc1        $f8, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f8.u32l;
        goto L_8080142C;
    // 0x808013EC: swc1        $f8, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f8.u32l;
L_808013F0:
    // 0x808013F0: lb          $t6, 0xC($a2)
    ctx->r14 = MEM_B(ctx->r6, 0XC);
    // 0x808013F4: sh          $t5, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r13;
    // 0x808013F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3154, 0X14A4) << 16);
    // 0x808013FC: lwc1        $f10, 0x14A4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3154, 0X14A4));
    // 0x80801400: addiu       $t7, $t6, -0x7
    ctx->r15 = ADD32(ctx->r14, -0X7);
    // 0x80801404: sb          $t7, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r15;
    // 0x80801408: b           L_8080142C
    // 0x8080140C: swc1        $f10, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f10.u32l;
        goto L_8080142C;
    // 0x8080140C: swc1        $f10, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f10.u32l;
L_80801410:
    // 0x80801410: lb          $t9, 0xC($a2)
    ctx->r25 = MEM_B(ctx->r6, 0XC);
    // 0x80801414: sh          $t8, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r24;
    // 0x80801418: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3154, 0X14A8) << 16);
    // 0x8080141C: lwc1        $f16, 0x14A8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3154, 0X14A8));
    // 0x80801420: addiu       $t0, $t9, -0x6
    ctx->r8 = ADD32(ctx->r25, -0X6);
    // 0x80801424: sb          $t0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r8;
    // 0x80801428: swc1        $f16, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f16.u32l;
L_8080142C:
    // 0x8080142C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801430: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801434: jr          $ra
    // 0x80801438: nop

    return;
    // 0x80801438: nop

    // 0x8080143C: nop

;}
RECOMP_FUNC void _bsvan_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084180: syscall     105
    recomp_syscall_handler(rdram, ctx, 0x80084180);
    return;
    // 0x80084184: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void sujiggy_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800838: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080083C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80800840: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80800844: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3354, 0X8F4) << 16);
    // 0x80800848: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080084C: jr          $ra
    // 0x80800850: lhu         $v0, 0x8F4($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(3354, 0X8F4));
    return;
    // 0x80800850: lhu         $v0, 0x8F4($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(3354, 0X8F4));
;}
RECOMP_FUNC void _chweather_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800859E8: syscall     185
    recomp_syscall_handler(rdram, ctx, 0x800859E8);
    return;
    // 0x800859EC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808002E0_sumole(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808002F0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808002F4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808002F8: lw          $v0, 0x78($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X78);
    // 0x808002FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800300: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    // 0x80800304: sll         $t6, $v0, 20
    ctx->r14 = S32(ctx->r2 << 20);
    // 0x80800308: srl         $t7, $t6, 29
    ctx->r15 = S32(U32(ctx->r14) >> 29);
    // 0x8080030C: beq         $t7, $zero, L_80800330
    if (ctx->r15 == 0) {
        // 0x80800310: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_80800330;
    }
    // 0x80800310: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800314: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800318: beq         $t7, $at, L_80800338
    if (ctx->r15 == ctx->r1) {
        // 0x8080031C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800338;
    }
    // 0x8080031C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800320: beql        $t7, $at, L_80800354
    if (ctx->r15 == ctx->r1) {
        // 0x80800324: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800354;
    }
    goto skip_0;
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800328: b           L_8080036C
    // 0x8080032C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080036C;
    // 0x8080032C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800330:
    // 0x80800330: jal         0x800856B0
    // 0x80800334: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800334: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
L_80800338:
    // 0x80800338: jal         0x800856E0
    // 0x8080033C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x8080033C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800340: lbu         $t8, 0x7A($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X7A);
    // 0x80800344: andi        $t9, $t8, 0xFFF1
    ctx->r25 = ctx->r24 & 0XFFF1;
    // 0x80800348: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x8080034C: sb          $t0, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r8;
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800354:
    // 0x80800354: jal         0x808001E0
    // 0x80800358: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_808001E0_sumole(rdram, ctx);
        goto after_2;
    // 0x80800358: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8080035C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800360: jal         0x800856D8
    // 0x80800364: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x80800364: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80800368: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080036C:
    // 0x8080036C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800370: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800374: jr          $ra
    // 0x80800378: nop

    return;
    // 0x80800378: nop

;}
RECOMP_FUNC void chgate1doors_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080044C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1916, 0X4B8) << 16);
    // 0x80800450: jr          $ra
    // 0x80800454: addiu       $v0, $v0, 0x4B8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1916, 0X4B8));
    return;
    // 0x80800454: addiu       $v0, $v0, 0x4B8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1916, 0X4B8));
;}
RECOMP_FUNC void bstalk_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
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
    // 0x8080012C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800130: bne         $v0, $at, L_80800150
    if (ctx->r2 != ctx->r1) {
        // 0x80800134: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800150;
    }
    // 0x80800134: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800138: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080013C: sw          $t6, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r14;
    // 0x80800140: jal         0x8009E830
    // 0x80800144: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_1;
    // 0x80800144: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800148: b           L_8080015C
    // 0x8080014C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080015C;
    // 0x8080014C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800150:
    // 0x80800150: jal         0x80099B94
    // 0x80800154: nop

    func_80099B94(rdram, ctx);
        goto after_2;
    // 0x80800154: nop

    after_2:
    // 0x80800158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080015C:
    // 0x8080015C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800160: jr          $ra
    // 0x80800164: nop

    return;
    // 0x80800164: nop

    // 0x80800168: nop

    // 0x8080016C: nop

;}
RECOMP_FUNC void bskazeggass_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080029C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808002A0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(228, 0X2C0) << 16);
    // 0x808002A4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808002A8: jr          $ra
    // 0x808002AC: lw          $v0, 0x2C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(228, 0X2C0));
    return;
    // 0x808002AC: lw          $v0, 0x2C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(228, 0X2C0));
;}
RECOMP_FUNC void func_80800314_sccustom_big(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800314: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800318: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080031C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800320: jal         0x800E7188
    // 0x80800324: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800E7188(rdram, ctx);
        goto after_0;
    // 0x80800324: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800328: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080032C: jal         0x8008A610
    // 0x80800330: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _scinfobar_entrypoint_18(rdram, ctx);
        goto after_1;
    // 0x80800330: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800334: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800338: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8080033C: beql        $at, $zero, L_8080034C
    if (ctx->r1 == 0) {
        // 0x80800340: lui         $at, 0x41C0
        ctx->r1 = S32(0X41C0 << 16);
            goto L_8080034C;
    }
    goto skip_0;
    // 0x80800340: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    skip_0:
    // 0x80800344: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80800348: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
L_8080034C:
    // 0x8080034C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800350: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80800354: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x80800358: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8080035C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800360: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800364: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80800368: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080036C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800370: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800374: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800378: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8080037C: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80800380: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80800384: trunc.w.s   $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800388: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x8080038C: jr          $ra
    // 0x80800390: nop

    return;
    // 0x80800390: nop

;}
RECOMP_FUNC void func_80800A28_bskazglide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A30: jal         0x80800090
    // 0x80800A34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800090_bskazglide(rdram, ctx);
        goto after_0;
    // 0x80800A34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800A38: jal         0x80082FE0
    // 0x80800A3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800A3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800A40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A48: jr          $ra
    // 0x80800A4C: nop

    return;
    // 0x80800A4C: nop

;}
RECOMP_FUNC void func_800ADCD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADCD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800ADCD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800ADCD8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800ADCDC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800ADCE0: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x800ADCE4: lh          $s0, 0x4($a1)
    ctx->r16 = MEM_H(ctx->r5, 0X4);
    // 0x800ADCE8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800ADCEC: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
    // 0x800ADCF0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800ADCF4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800ADCF8: slt         $at, $t6, $s0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800ADCFC: beq         $at, $zero, L_800ADD28
    if (ctx->r1 == 0) {
        // 0x800ADD00: sll         $a1, $s0, 6
        ctx->r5 = S32(ctx->r16 << 6);
            goto L_800ADD28;
    }
    // 0x800ADD00: sll         $a1, $s0, 6
    ctx->r5 = S32(ctx->r16 << 6);
    // 0x800ADD04: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    // 0x800ADD08: jal         0x8001B208
    // 0x800ADD0C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    heap_realloc(rdram, ctx);
        goto after_0;
    // 0x800ADD0C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x800ADD10: lh          $t7, 0x4($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X4);
    // 0x800ADD14: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800ADD18: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800ADD1C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800ADD20: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x800ADD24: lh          $s0, 0x4($s1)
    ctx->r16 = MEM_H(ctx->r17, 0X4);
L_800ADD28:
    // 0x800ADD28: sll         $t9, $s0, 6
    ctx->r25 = S32(ctx->r16 << 6);
    // 0x800ADD2C: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
    // 0x800ADD30: addu        $s1, $t9, $a2
    ctx->r17 = ADD32(ctx->r25, ctx->r6);
    // 0x800ADD34: addiu       $s1, $s1, 0x50
    ctx->r17 = ADD32(ctx->r17, 0X50);
    // 0x800ADD38: jal         0x80019CD4
    // 0x800ADD3C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80019CD4(rdram, ctx);
        goto after_1;
    // 0x800ADD3C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_1:
    // 0x800ADD40: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800ADD44: addiu       $s0, $a2, 0x50
    ctx->r16 = ADD32(ctx->r6, 0X50);
    // 0x800ADD48: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800ADD4C: beql        $at, $zero, L_800ADD70
    if (ctx->r1 == 0) {
        // 0x800ADD50: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800ADD70;
    }
    goto skip_0;
    // 0x800ADD50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_800ADD54:
    // 0x800ADD54: jal         0x80018AD0
    // 0x800ADD58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mlMtxGet(rdram, ctx);
        goto after_2;
    // 0x800ADD58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800ADD5C: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x800ADD60: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800ADD64: bne         $at, $zero, L_800ADD54
    if (ctx->r1 != 0) {
        // 0x800ADD68: nop
    
            goto L_800ADD54;
    }
    // 0x800ADD68: nop

    // 0x800ADD6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800ADD70:
    // 0x800ADD70: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800ADD74: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800ADD78: jr          $ra
    // 0x800ADD7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800ADD7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void gcmapsects_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808008FC: jal         0x800BF704
    // 0x80800900: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800BF704(rdram, ctx);
        goto after_0;
    // 0x80800900: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800904: lh          $t7, 0x1A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1A);
    // 0x80800908: lw          $t6, 0x68($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X68);
    // 0x8080090C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80800910: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800914: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80800918: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080091C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80800920: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80800924: addu        $v1, $t6, $t8
    ctx->r3 = ADD32(ctx->r14, ctx->r24);
    // 0x80800928: lbu         $t2, 0x4C($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X4C);
    // 0x8080092C: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80800930: andi        $t3, $t2, 0xFFFE
    ctx->r11 = ctx->r10 & 0XFFFE;
    // 0x80800934: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80800938: sb          $t4, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = ctx->r12;
    // 0x8080093C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800940: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800944: jr          $ra
    // 0x80800948: nop

    return;
    // 0x80800948: nop

;}
RECOMP_FUNC void _bamovethrust_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084EE0: syscall     141
    recomp_syscall_handler(rdram, ctx, 0x80084EE0);
    return;
    // 0x80084EE4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _cadbfunc_entrypoint_30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085670: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x80085670);
    return;
    // 0x80085674: addi        $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
;}
RECOMP_FUNC void func_800F7058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7058: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F705C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F7060: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F7064: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F7068: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F706C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F7070: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800F7074: jal         0x8009E674
    // 0x800F7078: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8009E674(rdram, ctx);
        goto after_0;
    // 0x800F7078: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F707C: beq         $v0, $zero, L_800F70A8
    if (ctx->r2 == 0) {
        // 0x800F7080: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_800F70A8;
    }
    // 0x800F7080: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7084: jal         0x80084FE0
    // 0x800F7088: nop

    _bashoes_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x800F7088: nop

    after_1:
    // 0x800F708C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800F7090: bne         $v0, $at, L_800F70A0
    if (ctx->r2 != ctx->r1) {
        // 0x800F7094: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800F70A0;
    }
    // 0x800F7094: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800F7098: b           L_800F70AC
    // 0x800F709C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800F70AC;
    // 0x800F709C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800F70A0:
    // 0x800F70A0: b           L_800F70AC
    // 0x800F70A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800F70AC;
    // 0x800F70A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800F70A8:
    // 0x800F70A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F70AC:
    // 0x800F70AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F70B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F70B4: jr          $ra
    // 0x800F70B8: nop

    return;
    // 0x800F70B8: nop

;}
RECOMP_FUNC void func_80803D30_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803D30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80803D34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80803D38: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80803D3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803D40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803D44: bne         $a1, $at, L_80803DF8
    if (ctx->r5 != ctx->r1) {
        // 0x80803D48: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80803DF8;
    }
    // 0x80803D48: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80803D4C: jal         0x80089C90
    // 0x80803D50: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80803D50: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x80803D54: slti        $at, $v0, 0x61
    ctx->r1 = SIGNED(ctx->r2) < 0X61 ? 1 : 0;
    // 0x80803D58: bnel        $at, $zero, L_80803DD4
    if (ctx->r1 != 0) {
        // 0x80803D5C: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80803DD4;
    }
    goto skip_0;
    // 0x80803D5C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80803D60: lbu         $t7, 0x79($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X79);
    // 0x80803D64: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1692, 0X4704) << 16);
    // 0x80803D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803D6C: srl         $t8, $t7, 4
    ctx->r24 = S32(U32(ctx->r15) >> 4);
    // 0x80803D70: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80803D74: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x80803D78: jal         0x80803CC4
    // 0x80803D7C: lh          $a1, 0x4704($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1692, 0X4704));
    func_80803CC4_chflysaucer(rdram, ctx);
        goto after_1;
    // 0x80803D7C: lh          $a1, 0x4704($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1692, 0X4704));
    after_1:
    // 0x80803D80: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    // 0x80803D84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80803D88: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80803D8C: srl         $t0, $a0, 4
    ctx->r8 = S32(U32(ctx->r4) >> 4);
    // 0x80803D90: addiu       $a0, $t0, 0x1
    ctx->r4 = ADD32(ctx->r8, 0X1);
    // 0x80803D94: jal         0x80086468
    // 0x80803D98: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _chscorepoints_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80803D98: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80803D9C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80803DA0: lbu         $t2, 0x79($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X79);
    // 0x80803DA4: addiu       $v0, $v0, 0x75C8
    ctx->r2 = ADD32(ctx->r2, 0X75C8);
    // 0x80803DA8: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x80803DAC: srl         $t3, $t2, 4
    ctx->r11 = S32(U32(ctx->r10) >> 4);
    // 0x80803DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803DB4: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80803DB8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80803DBC: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x80803DC0: jal         0x80803BF0
    // 0x80803DC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80803BF0_chflysaucer(rdram, ctx);
        goto after_3;
    // 0x80803DC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80803DC8: jal         0x8010A570
    // 0x80803DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_4;
    // 0x80803DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80803DD0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_80803DD4:
    // 0x80803DD4: addiu       $a1, $zero, 0x98
    ctx->r5 = ADD32(0, 0X98);
    // 0x80803DD8: lhu         $t6, 0x18($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X18);
    // 0x80803DDC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80803DE0: beql        $t7, $zero, L_80803E04
    if (ctx->r15 == 0) {
        // 0x80803DE4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80803E04;
    }
    goto skip_1;
    // 0x80803DE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80803DE8: jal         0x8010114C
    // 0x80803DEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_5;
    // 0x80803DEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80803DF0: b           L_80803E04
    // 0x80803DF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803E04;
    // 0x80803DF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803DF8:
    // 0x80803DF8: b           L_80803E04
    // 0x80803DFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803E04;
    // 0x80803DFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80803E00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803E04:
    // 0x80803E04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803E08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80803E0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80803E10: jr          $ra
    // 0x80803E14: nop

    return;
    // 0x80803E14: nop

;}
RECOMP_FUNC void func_80801BC8_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801BC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801BCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801BD0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801BD4: jal         0x80100094
    // 0x80801BD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801BD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801BDC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801BE0: lwc1        $f6, 0xF0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XF0);
    // 0x80801BE4: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80801BE8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80801BEC: nop

    // 0x80801BF0: bc1fl       L_80801C44
    if (!c1cs) {
        // 0x80801BF4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801C44;
    }
    goto skip_0;
    // 0x80801BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801BF8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80801BFC: jal         0x800D8FF8
    // 0x80801C00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80801C00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80801C04: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80801C08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801C0C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801C10: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801C14: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80801C18: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80801C1C: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80801C20: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x80801C24: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80801C28: lwc1        $f2, 0xF0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x80801C2C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80801C30: nop

    // 0x80801C34: bc1fl       L_80801C44
    if (!c1cs) {
        // 0x80801C38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801C44;
    }
    goto skip_1;
    // 0x80801C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80801C3C: swc1        $f2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f2.u32l;
    // 0x80801C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801C44:
    // 0x80801C44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801C48: jr          $ra
    // 0x80801C4C: nop

    return;
    // 0x80801C4C: nop

;}
RECOMP_FUNC void _bsbansnooze_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082760: syscall     9
    recomp_syscall_handler(rdram, ctx, 0x80082760);
    return;
    // 0x80082764: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void chdiggerbossinterior_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1504, 0X230) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x230
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1504, 0X230));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x230
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1504, 0X230));
;}
RECOMP_FUNC void sumultiscore_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80800004: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80800008: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x8080000C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800010: bne         $at, $zero, L_80800094
    if (ctx->r1 != 0) {
        // 0x80800014: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800094;
    }
    // 0x80800014: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800018:
    // 0x80800018: blez        $v0, L_80800088
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080001C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800088;
    }
    // 0x8080001C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800020: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80800024: addu        $a1, $a0, $t6
    ctx->r5 = ADD32(ctx->r4, ctx->r14);
    // 0x80800028: lw          $t7, -0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, -0X4);
    // 0x8080002C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80800030: sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3 << 2);
    // 0x80800034: addu        $a3, $a0, $a1
    ctx->r7 = ADD32(ctx->r4, ctx->r5);
    // 0x80800038: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8080003C: beq         $at, $zero, L_80800088
    if (ctx->r1 == 0) {
        // 0x80800040: addu        $t2, $s0, $a1
        ctx->r10 = ADD32(ctx->r16, ctx->r5);
            goto L_80800088;
    }
    // 0x80800040: addu        $t2, $s0, $a1
    ctx->r10 = ADD32(ctx->r16, ctx->r5);
    // 0x80800044: lw          $t0, -0x4($a3)
    ctx->r8 = MEM_W(ctx->r7, -0X4);
    // 0x80800048: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x8080004C: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
L_80800050:
    // 0x80800050: sw          $t1, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->r9;
    // 0x80800054: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    // 0x80800058: lw          $t9, -0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, -0X4);
    // 0x8080005C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80800060: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
    // 0x80800064: addiu       $t2, $t2, -0x4
    ctx->r10 = ADD32(ctx->r10, -0X4);
    // 0x80800068: sw          $a1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r5;
    // 0x8080006C: blez        $v1, L_80800088
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80800070: sw          $t9, 0x4($t2)
        MEM_W(0X4, ctx->r10) = ctx->r25;
            goto L_80800088;
    }
    // 0x80800070: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x80800074: lw          $t0, -0x4($a3)
    ctx->r8 = MEM_W(ctx->r7, -0X4);
    // 0x80800078: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x8080007C: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80800080: bnel        $at, $zero, L_80800050
    if (ctx->r1 != 0) {
        // 0x80800084: sw          $t0, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r8;
            goto L_80800050;
    }
    goto skip_0;
    // 0x80800084: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
    skip_0:
L_80800088:
    // 0x80800088: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8080008C: bne         $v0, $a2, L_80800018
    if (ctx->r2 != ctx->r6) {
        // 0x80800090: nop
    
            goto L_80800018;
    }
    // 0x80800090: nop

L_80800094:
    // 0x80800094: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80800098: jr          $ra
    // 0x8080009C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8080009C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void gldialog_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: jr          $ra
    // 0x8080004C: nop

    return;
    // 0x8080004C: nop

;}
RECOMP_FUNC void chballoonburst_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1008, 0X1C40) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1C40
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1008, 0X1C40));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1C40
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1008, 0X1C40));
;}
RECOMP_FUNC void func_80800DC4_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800DC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800DCC: addiu       $t6, $zero, 0xA1
    ctx->r14 = ADD32(0, 0XA1);
    // 0x80800DD0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800DD4: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x80800DD8: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80800DDC: jal         0x80800000
    // 0x80800DE0: addiu       $a3, $zero, 0x29C
    ctx->r7 = ADD32(0, 0X29C);
    func_80800000_bsbtrot(rdram, ctx);
        goto after_0;
    // 0x80800DE0: addiu       $a3, $zero, 0x29C
    ctx->r7 = ADD32(0, 0X29C);
    after_0:
    // 0x80800DE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800DEC: jr          $ra
    // 0x80800DF0: nop

    return;
    // 0x80800DF0: nop

;}
RECOMP_FUNC void func_8080061C_chblackeye(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080061C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800620: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80800624: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800628: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080062C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80800630: jal         0x800B53A4
    // 0x80800634: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x80800634: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80800638: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8080063C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800640: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800644: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800648: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080064C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800650: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800654: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800658: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8080065C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800660: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800664: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800668: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8080066C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800670: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80800674: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x80800678: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8080067C: sll         $a3, $a1, 16
    ctx->r7 = S32(ctx->r5 << 16);
    // 0x80800680: sll         $t1, $v1, 16
    ctx->r9 = S32(ctx->r3 << 16);
    // 0x80800684: sra         $v1, $t1, 16
    ctx->r3 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80800688: sra         $t9, $a3, 16
    ctx->r25 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8080068C: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x80800690: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80800694: jal         0x800BA6B0
    // 0x80800698: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_800BA6B0(rdram, ctx);
        goto after_1;
    // 0x80800698: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x8080069C: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x808006A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808006A4: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808006A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006AC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808006B0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808006B4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808006B8: nop

    // 0x808006BC: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x808006C0: jal         0x800BA4D0
    // 0x808006C4: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    func_800BA4D0(rdram, ctx);
        goto after_2;
    // 0x808006C4: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    after_2:
    // 0x808006C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1796, 0XDCC) << 16);
    // 0x808006CC: lwc1        $f16, 0xDCC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1796, 0XDCC));
    // 0x808006D0: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808006D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1796, 0XDD0) << 16);
    // 0x808006D8: lwc1        $f4, 0xDD0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1796, 0XDD0));
    // 0x808006DC: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808006E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006E4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808006E8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808006EC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808006F0: jal         0x800BA7C4
    // 0x808006F4: nop

    func_800BA7C4(rdram, ctx);
        goto after_3;
    // 0x808006F4: nop

    after_3:
    // 0x808006F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1796, 0XDD4) << 16);
    // 0x808006FC: lwc1        $f10, 0xDD4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1796, 0XDD4));
    // 0x80800700: lwc1        $f8, 0x38($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800704: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800708: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8080070C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800710: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800714: jal         0x800BA7FC
    // 0x80800718: nop

    func_800BA7FC(rdram, ctx);
        goto after_4;
    // 0x80800718: nop

    after_4:
    // 0x8080071C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80800720: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800724: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80800728: jal         0x800DBEFC
    // 0x8080072C: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_5;
    // 0x8080072C: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    after_5:
    // 0x80800730: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1796, 0XEE0) << 16);
    // 0x80800734: addiu       $t7, $t7, 0xEE0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1796, 0XEE0));
    // 0x80800738: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080073C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800740: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800744: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800748: jal         0x800BABB8
    // 0x8080074C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_6;
    // 0x8080074C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_6:
    // 0x80800750: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1796, 0XE10) << 16);
    // 0x80800754: addiu       $a1, $a1, 0xE10
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1796, 0XE10));
    // 0x80800758: jal         0x80800000
    // 0x8080075C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chblackeye(rdram, ctx);
        goto after_7;
    // 0x8080075C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800760: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800764: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80800768: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8080076C: jr          $ra
    // 0x80800770: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800770: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
