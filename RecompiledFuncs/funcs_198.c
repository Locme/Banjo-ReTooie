#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8001A578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A578: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001A57C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A580: jal         0x800D3948
    // 0x8001A584: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_800D3948(rdram, ctx);
        goto after_0;
    // 0x8001A584: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001A588: beq         $v0, $zero, L_8001A62C
    if (ctx->r2 == 0) {
        // 0x8001A58C: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_8001A62C;
    }
    // 0x8001A58C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8001A590: beq         $a0, $zero, L_8001A5C0
    if (ctx->r4 == 0) {
        // 0x8001A594: addiu       $v0, $zero, 0x1388
        ctx->r2 = ADD32(0, 0X1388);
            goto L_8001A5C0;
    }
    // 0x8001A594: addiu       $v0, $zero, 0x1388
    ctx->r2 = ADD32(0, 0X1388);
    // 0x8001A598: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x8001A59C: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8001A5A0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8001A5A4: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x8001A5A8: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8001A5AC: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8001A5B0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8001A5B4: sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2 << 9);
    // 0x8001A5B8: b           L_8001A5C4
    // 0x8001A5BC: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
        goto L_8001A5C4;
    // 0x8001A5BC: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
L_8001A5C0:
    // 0x8001A5C0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001A5C4:
    // 0x8001A5C4: beq         $v0, $zero, L_8001A5FC
    if (ctx->r2 == 0) {
        // 0x8001A5C8: sll         $a0, $v0, 3
        ctx->r4 = S32(ctx->r2 << 3);
            goto L_8001A5FC;
    }
    // 0x8001A5C8: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    // 0x8001A5CC: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8001A5D0: jal         0x8001ACCC
    // 0x8001A5D4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    heap_alloc(rdram, ctx);
        goto after_1;
    // 0x8001A5D4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x8001A5D8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A5DC: jal         0x8001ACCC
    // 0x8001A5E0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    heap_alloc(rdram, ctx);
        goto after_2;
    // 0x8001A5E0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_2:
    // 0x8001A5E4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8001A5E8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001A5EC: addiu       $a0, $a0, -0x4318
    ctx->r4 = ADD32(ctx->r4, -0X4318);
    // 0x8001A5F0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8001A5F4: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8001A5F8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
L_8001A5FC:
    // 0x8001A5FC: beq         $v1, $zero, L_8001A62C
    if (ctx->r3 == 0) {
        // 0x8001A600: sll         $a0, $v1, 6
        ctx->r4 = S32(ctx->r3 << 6);
            goto L_8001A62C;
    }
    // 0x8001A600: sll         $a0, $v1, 6
    ctx->r4 = S32(ctx->r3 << 6);
    // 0x8001A604: jal         0x8001ACCC
    // 0x8001A608: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    heap_alloc(rdram, ctx);
        goto after_3;
    // 0x8001A608: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_3:
    // 0x8001A60C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A610: jal         0x8001ACCC
    // 0x8001A614: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    heap_alloc(rdram, ctx);
        goto after_4;
    // 0x8001A614: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_4:
    // 0x8001A618: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A61C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001A620: addiu       $v1, $v1, -0x4310
    ctx->r3 = ADD32(ctx->r3, -0X4310);
    // 0x8001A624: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8001A628: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_8001A62C:
    // 0x8001A62C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A630: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8001A634: jr          $ra
    // 0x8001A638: nop

    return;
    // 0x8001A638: nop

;}
RECOMP_FUNC void func_80800280_chconga(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800280: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800284: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800288: jal         0x800897C8
    // 0x8080028C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x8080028C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800294: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800298: jr          $ra
    // 0x8080029C: nop

    return;
    // 0x8080029C: nop

;}
RECOMP_FUNC void func_800C34CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C34CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C34D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C34D4: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C34D8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C34DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C34E0: beq         $t6, $zero, L_800C3518
    if (ctx->r14 == 0) {
        // 0x800C34E4: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800C3518;
    }
    // 0x800C34E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C34E8: jal         0x800C1414
    // 0x800C34EC: nop

    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C34EC: nop

    after_0:
    // 0x800C34F0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C34F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C34F8: beq         $t7, $zero, L_800C3510
    if (ctx->r15 == 0) {
        // 0x800C34FC: nop
    
            goto L_800C3510;
    }
    // 0x800C34FC: nop

    // 0x800C3500: jal         0x800C13B0
    // 0x800C3504: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    func_800C13B0(rdram, ctx);
        goto after_1;
    // 0x800C3504: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_1:
    // 0x800C3508: b           L_800C351C
    // 0x800C350C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800C351C;
    // 0x800C350C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C3510:
    // 0x800C3510: jal         0x800C13A0
    // 0x800C3514: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    func_800C13A0(rdram, ctx);
        goto after_2;
    // 0x800C3514: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_2:
L_800C3518:
    // 0x800C3518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C351C:
    // 0x800C351C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C3520: jr          $ra
    // 0x800C3524: nop

    return;
    // 0x800C3524: nop

;}
RECOMP_FUNC void bawobble_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800158: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8080015C: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x80800160: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80800164: swc1        $f12, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f12.u32l;
    // 0x80800168: lw          $t7, 0x154($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X154);
    // 0x8080016C: jr          $ra
    // 0x80800170: swc1        $f14, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f14.u32l;
    return;
    // 0x80800170: swc1        $f14, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_8010D690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D690: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8010D694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010D698: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8010D69C: jal         0x80103F38
    // 0x8010D6A0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80103F38(rdram, ctx);
        goto after_0;
    // 0x8010D6A0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x8010D6A4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8010D6A8: jal         0x8010A40C
    // 0x8010D6AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8010A40C(rdram, ctx);
        goto after_1;
    // 0x8010D6AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8010D6B0: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8010D6B4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8010D6B8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8010D6BC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8010D6C0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8010D6C4: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8010D6C8: jal         0x8010D6E0
    // 0x8010D6CC: nop

    func_8010D6E0(rdram, ctx);
        goto after_2;
    // 0x8010D6CC: nop

    after_2:
    // 0x8010D6D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010D6D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8010D6D8: jr          $ra
    // 0x8010D6DC: nop

    return;
    // 0x8010D6DC: nop

;}
RECOMP_FUNC void func_800CB4D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB4D0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800CB4D4: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800CB4D8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800CB4DC: addiu       $t7, $t7, -0x5490
    ctx->r15 = ADD32(ctx->r15, -0X5490);
    // 0x800CB4E0: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800CB4E4: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800CB4E8: lbu         $t8, 0x1($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X1);
    // 0x800CB4EC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800CB4F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CB4F4: bnel        $t8, $zero, L_800CB510
    if (ctx->r24 != 0) {
        // 0x800CB4F8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800CB510;
    }
    goto skip_0;
    // 0x800CB4F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800CB4FC: sb          $t9, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r25;
    // 0x800CB500: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x800CB504: jr          $ra
    // 0x800CB508: sh          $a2, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r6;
    return;
    // 0x800CB508: sh          $a2, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r6;
    // 0x800CB50C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CB510:
    // 0x800CB510: jr          $ra
    // 0x800CB514: nop

    return;
    // 0x800CB514: nop

;}
RECOMP_FUNC void _bamotor_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085498: syscall     163
    recomp_syscall_handler(rdram, ctx, 0x80085498);
    return;
    // 0x8008549C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _bsbeggass_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800828D0: syscall     18
    recomp_syscall_handler(rdram, ctx, 0x800828D0);
    return;
    // 0x800828D4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _gccubeDll_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087C80: syscall     655
    recomp_syscall_handler(rdram, ctx, 0x80087C80);
    return;
    // 0x80087C84: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800D86F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D86F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D86F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D86F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D86FC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D8700: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800D8704: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D8708: jal         0x8001B798
    // 0x800D870C: lh          $a0, -0x400C($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X400C);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x800D870C: lh          $a0, -0x400C($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X400C);
    after_0:
    // 0x800D8710: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800D8714: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800D8718: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800D871C: jal         0x8001B798
    // 0x800D8720: lh          $a0, 0x0($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X0);
    func_8001B798(rdram, ctx);
        goto after_1;
    // 0x800D8720: lh          $a0, 0x0($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X0);
    after_1:
    // 0x800D8724: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D8728: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800D872C: jal         0x800C7A68
    // 0x800D8730: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_800C7A68(rdram, ctx);
        goto after_2;
    // 0x800D8730: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800D8734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D8738: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D873C: jr          $ra
    // 0x800D8740: nop

    return;
    // 0x800D8740: nop

;}
RECOMP_FUNC void func_800C1D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1D80: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C1D84: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C1D88: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800C1D8C: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C1D90: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C1D94: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C1D98: jal         0x800C1414
    // 0x800C1D9C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C1D9C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x800C1DA0: lw          $t7, 0x78($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X78);
    // 0x800C1DA4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C1DA8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C1DAC: sll         $t8, $t7, 19
    ctx->r24 = S32(ctx->r15 << 19);
    // 0x800C1DB0: srl         $t9, $t8, 29
    ctx->r25 = S32(U32(ctx->r24) >> 29);
    // 0x800C1DB4: bne         $t9, $at, L_800C1FD0
    if (ctx->r25 != ctx->r1) {
        // 0x800C1DB8: nop
    
            goto L_800C1FD0;
    }
    // 0x800C1DB8: nop

    // 0x800C1DBC: lbu         $t0, 0x79($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X79);
    // 0x800C1DC0: beq         $t0, $zero, L_800C1FD0
    if (ctx->r8 == 0) {
        // 0x800C1DC4: nop
    
            goto L_800C1FD0;
    }
    // 0x800C1DC4: nop

    // 0x800C1DC8: jal         0x800EA05C
    // 0x800C1DCC: nop

    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x800C1DCC: nop

    after_1:
    // 0x800C1DD0: lh          $t1, 0x5E($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X5E);
    // 0x800C1DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C1DD8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800C1DDC: xor         $t2, $v0, $t1
    ctx->r10 = ctx->r2 ^ ctx->r9;
    // 0x800C1DE0: sltu        $t2, $zero, $t2
    ctx->r10 = 0 < ctx->r10 ? 1 : 0;
    // 0x800C1DE4: jal         0x800C13C4
    // 0x800C1DE8: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    func_800C13C4(rdram, ctx);
        goto after_2;
    // 0x800C1DE8: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    after_2:
    // 0x800C1DEC: beql        $v0, $zero, L_800C1E04
    if (ctx->r2 == 0) {
        // 0x800C1DF0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C1E04;
    }
    goto skip_0;
    // 0x800C1DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x800C1DF4: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    // 0x800C1DF8: jal         0x800C1950
    // 0x800C1DFC: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    func_800C1950(rdram, ctx);
        goto after_3;
    // 0x800C1DFC: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    after_3:
    // 0x800C1E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C1E04:
    // 0x800C1E04: jal         0x800C13C4
    // 0x800C1E08: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_800C13C4(rdram, ctx);
        goto after_4;
    // 0x800C1E08: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_4:
    // 0x800C1E0C: beql        $v0, $zero, L_800C1E48
    if (ctx->r2 == 0) {
        // 0x800C1E10: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C1E48;
    }
    goto skip_1;
    // 0x800C1E10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x800C1E14: lbu         $t3, 0x1B($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1B);
    // 0x800C1E18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C1E1C: bnel        $t3, $zero, L_800C1E48
    if (ctx->r11 != 0) {
        // 0x800C1E20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C1E48;
    }
    goto skip_2;
    // 0x800C1E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x800C1E24: jal         0x800C13C4
    // 0x800C1E28: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    func_800C13C4(rdram, ctx);
        goto after_5;
    // 0x800C1E28: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_5:
    // 0x800C1E2C: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    // 0x800C1E30: lbu         $a1, 0x60($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X60);
    // 0x800C1E34: lbu         $a2, 0x1B($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1B);
    // 0x800C1E38: lbu         $a3, 0x1C($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X1C);
    // 0x800C1E3C: jal         0x800C18C8
    // 0x800C1E40: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800C18C8(rdram, ctx);
        goto after_6;
    // 0x800C1E40: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_6:
    // 0x800C1E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C1E48:
    // 0x800C1E48: jal         0x800C13C4
    // 0x800C1E4C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C13C4(rdram, ctx);
        goto after_7;
    // 0x800C1E4C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x800C1E50: beq         $v0, $zero, L_800C1F0C
    if (ctx->r2 == 0) {
        // 0x800C1E54: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C1F0C;
    }
    // 0x800C1E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C1E58: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800C1E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C1E60: beql        $t4, $zero, L_800C1E8C
    if (ctx->r12 == 0) {
        // 0x800C1E64: lbu         $t5, 0x63($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X63);
            goto L_800C1E8C;
    }
    goto skip_3;
    // 0x800C1E64: lbu         $t5, 0x63($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X63);
    skip_3:
    // 0x800C1E68: jal         0x800C13C4
    // 0x800C1E6C: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    func_800C13C4(rdram, ctx);
        goto after_8;
    // 0x800C1E6C: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_8:
    // 0x800C1E70: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    // 0x800C1E74: lh          $a1, 0x5C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X5C);
    // 0x800C1E78: jal         0x800C1984
    // 0x800C1E7C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800C1984(rdram, ctx);
        goto after_9;
    // 0x800C1E7C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_9:
    // 0x800C1E80: b           L_800C1FB0
    // 0x800C1E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800C1FB0;
    // 0x800C1E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C1E88: lbu         $t5, 0x63($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X63);
L_800C1E8C:
    // 0x800C1E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C1E90: beql        $t5, $zero, L_800C1EAC
    if (ctx->r13 == 0) {
        // 0x800C1E94: lh          $a3, 0x5A($s0)
        ctx->r7 = MEM_H(ctx->r16, 0X5A);
            goto L_800C1EAC;
    }
    goto skip_4;
    // 0x800C1E94: lh          $a3, 0x5A($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X5A);
    skip_4:
    // 0x800C1E98: jal         0x800C19E4
    // 0x800C1E9C: lh          $a1, 0x5A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X5A);
    func_800C19E4(rdram, ctx);
        goto after_10;
    // 0x800C1E9C: lh          $a1, 0x5A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X5A);
    after_10:
    // 0x800C1EA0: b           L_800C1EAC
    // 0x800C1EA4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_800C1EAC;
    // 0x800C1EA4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800C1EA8: lh          $a3, 0x5A($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X5A);
L_800C1EAC:
    // 0x800C1EAC: slti        $at, $a3, 0x64
    ctx->r1 = SIGNED(ctx->r7) < 0X64 ? 1 : 0;
    // 0x800C1EB0: beq         $at, $zero, L_800C1EC0
    if (ctx->r1 == 0) {
        // 0x800C1EB4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C1EC0;
    }
    // 0x800C1EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C1EB8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C1EBC: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_800C1EC0:
    // 0x800C1EC0: jal         0x800C1CCC
    // 0x800C1EC4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_800C1CCC(rdram, ctx);
        goto after_11;
    // 0x800C1EC4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_11:
    // 0x800C1EC8: sh          $v0, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r2;
    // 0x800C1ECC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800C1ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C1ED4: jal         0x800C13C4
    // 0x800C1ED8: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    func_800C13C4(rdram, ctx);
        goto after_12;
    // 0x800C1ED8: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_12:
    // 0x800C1EDC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800C1EE0: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    // 0x800C1EE4: jal         0x800C1984
    // 0x800C1EE8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800C1984(rdram, ctx);
        goto after_13;
    // 0x800C1EE8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_13:
    // 0x800C1EEC: jal         0x800EA068
    // 0x800C1EF0: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_800EA068(rdram, ctx);
        goto after_14;
    // 0x800C1EF0: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_14:
    // 0x800C1EF4: bnel        $v0, $zero, L_800C1FB0
    if (ctx->r2 != 0) {
        // 0x800C1EF8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C1FB0;
    }
    goto skip_5;
    // 0x800C1EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
    // 0x800C1EFC: jal         0x800C1AA4
    // 0x800C1F00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C1AA4(rdram, ctx);
        goto after_15;
    // 0x800C1F00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x800C1F04: b           L_800C1FB0
    // 0x800C1F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800C1FB0;
    // 0x800C1F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C1F0C:
    // 0x800C1F0C: jal         0x800C13C4
    // 0x800C1F10: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    func_800C13C4(rdram, ctx);
        goto after_16;
    // 0x800C1F10: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    after_16:
    // 0x800C1F14: beql        $v0, $zero, L_800C1F2C
    if (ctx->r2 == 0) {
        // 0x800C1F18: lw          $t7, 0x28($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X28);
            goto L_800C1F2C;
    }
    goto skip_6;
    // 0x800C1F18: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    skip_6:
    // 0x800C1F1C: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    // 0x800C1F20: jal         0x800C191C
    // 0x800C1F24: lbu         $a1, 0x61($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X61);
    func_800C191C(rdram, ctx);
        goto after_17;
    // 0x800C1F24: lbu         $a1, 0x61($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X61);
    after_17:
    // 0x800C1F28: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
L_800C1F2C:
    // 0x800C1F2C: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // 0x800C1F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C1F34: beq         $t7, $zero, L_800C1F5C
    if (ctx->r15 == 0) {
        // 0x800C1F38: nop
    
            goto L_800C1F5C;
    }
    // 0x800C1F38: nop

    // 0x800C1F3C: jal         0x800C13C4
    // 0x800C1F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C13C4(rdram, ctx);
        goto after_18;
    // 0x800C1F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x800C1F44: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    // 0x800C1F48: lh          $a1, 0x5C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X5C);
    // 0x800C1F4C: jal         0x800C1984
    // 0x800C1F50: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800C1984(rdram, ctx);
        goto after_19;
    // 0x800C1F50: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_19:
    // 0x800C1F54: b           L_800C1FB0
    // 0x800C1F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800C1FB0;
    // 0x800C1F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C1F5C:
    // 0x800C1F5C: jal         0x800C13C4
    // 0x800C1F60: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800C13C4(rdram, ctx);
        goto after_20;
    // 0x800C1F60: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_20:
    // 0x800C1F64: beq         $v0, $zero, L_800C1FAC
    if (ctx->r2 == 0) {
        // 0x800C1F68: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C1FAC;
    }
    // 0x800C1F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C1F6C: jal         0x800C1CCC
    // 0x800C1F70: lh          $a1, 0x5A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X5A);
    func_800C1CCC(rdram, ctx);
        goto after_21;
    // 0x800C1F70: lh          $a1, 0x5A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X5A);
    after_21:
    // 0x800C1F74: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x800C1F78: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800C1F7C: beq         $at, $zero, L_800C1F8C
    if (ctx->r1 == 0) {
        // 0x800C1F80: sh          $v0, 0x5C($s0)
        MEM_H(0X5C, ctx->r16) = ctx->r2;
            goto L_800C1F8C;
    }
    // 0x800C1F80: sh          $v0, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r2;
    // 0x800C1F84: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C1F88: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_800C1F8C:
    // 0x800C1F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C1F90: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // 0x800C1F94: jal         0x800C13C4
    // 0x800C1F98: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_800C13C4(rdram, ctx);
        goto after_22;
    // 0x800C1F98: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_22:
    // 0x800C1F9C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800C1FA0: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    // 0x800C1FA4: jal         0x800C1984
    // 0x800C1FA8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800C1984(rdram, ctx);
        goto after_23;
    // 0x800C1FA8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_23:
L_800C1FAC:
    // 0x800C1FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C1FB0:
    // 0x800C1FB0: jal         0x800C13B0
    // 0x800C1FB4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800C13B0(rdram, ctx);
        goto after_24;
    // 0x800C1FB4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_24:
    // 0x800C1FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C1FBC: jal         0x800C13B0
    // 0x800C1FC0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800C13B0(rdram, ctx);
        goto after_25;
    // 0x800C1FC0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_25:
    // 0x800C1FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C1FC8: jal         0x800C13B0
    // 0x800C1FCC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_800C13B0(rdram, ctx);
        goto after_26;
    // 0x800C1FCC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_26:
L_800C1FD0:
    // 0x800C1FD0: jal         0x800A8184
    // 0x800C1FD4: nop

    func_800A8184(rdram, ctx);
        goto after_27;
    // 0x800C1FD4: nop

    after_27:
    // 0x800C1FD8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800C1FDC: bne         $v0, $at, L_800C1FEC
    if (ctx->r2 != ctx->r1) {
        // 0x800C1FE0: lw          $t9, 0x34($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X34);
            goto L_800C1FEC;
    }
    // 0x800C1FE0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800C1FE4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800C1FE8: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_800C1FEC:
    // 0x800C1FEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C1FF0: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x800C1FF4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C1FF8: jr          $ra
    // 0x800C1FFC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C1FFC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80800090_chmole_factory(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800098: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1832, 0XC0) << 16);
    // 0x8080009C: jal         0x800899F0
    // 0x808000A0: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1832, 0XC0));
    _sumole_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808000A0: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1832, 0XC0));
    after_0:
    // 0x808000A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void ncbabee_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: jr          $ra
    // 0x8080006C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080006C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _bsbtrot_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082C98: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082C98);
    return;
    // 0x80082C9C: addi        $t0, $zero, 0x6C
    ctx->r8 = ADD32(0, 0X6C);
;}
RECOMP_FUNC void func_80800C04_chbiggafoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800C08: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800C0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800C10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800C14: jal         0x800D9078
    // 0x80800C18: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x80800C18: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_0:
    // 0x80800C1C: beql        $v0, $zero, L_80800CCC
    if (ctx->r2 == 0) {
        // 0x80800C20: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800CCC;
    }
    goto skip_0;
    // 0x80800C20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800C24: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
    // 0x80800C28: lhu         $t0, 0x6E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800C2C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800C30: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80800C34: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80800C38: andi        $t1, $t0, 0xFE00
    ctx->r9 = ctx->r8 & 0XFE00;
    // 0x80800C3C: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80800C40: sh          $t2, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r10;
    // 0x80800C44: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x80800C48: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1216, 0X1030) << 16);
    // 0x80800C4C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80800C50: andi        $t3, $v0, 0x1FF
    ctx->r11 = ctx->r2 & 0X1FF;
    // 0x80800C54: bne         $t3, $at, L_80800C9C
    if (ctx->r11 != ctx->r1) {
        // 0x80800C58: or          $v0, $t3, $zero
        ctx->r2 = ctx->r11 | 0;
            goto L_80800C9C;
    }
    // 0x80800C58: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80800C5C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800C60: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x80800C64: jal         0x80085740
    // 0x80800C68: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    _capod_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80800C68: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_1:
    // 0x80800C6C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800C70: addiu       $t4, $zero, 0xA8
    ctx->r12 = ADD32(0, 0XA8);
    // 0x80800C74: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800C78: addiu       $a1, $zero, 0x12B2
    ctx->r5 = ADD32(0, 0X12B2);
    // 0x80800C7C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800C80: jal         0x8008A208
    // 0x80800C84: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80800C84: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x80800C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C8C: jal         0x80102424
    // 0x80800C90: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x80800C90: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x80800C94: b           L_80800CCC
    // 0x80800C98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800CCC;
    // 0x80800C98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800C9C:
    // 0x80800C9C: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x80800CA0: addu        $a1, $a1, $t5
    ctx->r5 = ADD32(ctx->r5, ctx->r13);
    // 0x80800CA4: lh          $a1, 0x1030($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1216, 0X1030));
    // 0x80800CA8: jal         0x80085740
    // 0x80800CAC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_20(rdram, ctx);
        goto after_4;
    // 0x80800CAC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x80800CB0: jal         0x80800CDC
    // 0x80800CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800CDC_chbiggafoot(rdram, ctx);
        goto after_5;
    // 0x80800CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800CB8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800CBC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800CC0: nop

    // 0x80800CC4: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x80800CC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800CCC:
    // 0x80800CCC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800CD0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800CD4: jr          $ra
    // 0x80800CD8: nop

    return;
    // 0x80800CD8: nop

;}
RECOMP_FUNC void func_80801BC4_chfantasyeyeball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801BC4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801BC8: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80801BCC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80801BD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801BD4: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80801BD8: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80801BDC: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80801BE0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80801BE4: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2400, 0X1FC0) << 16);
    // 0x80801BE8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80801BEC: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80801BF0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80801BF4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80801BF8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80801BFC: addiu       $s4, $s4, 0x1FC0
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2400, 0X1FC0));
    // 0x80801C00: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801C04: addiu       $s3, $a0, 0x4
    ctx->r19 = ADD32(ctx->r4, 0X4);
    // 0x80801C08: addiu       $s5, $zero, 0x8
    ctx->r21 = ADD32(0, 0X8);
L_80801C0C:
    // 0x80801C0C: beq         $s2, $zero, L_80801C1C
    if (ctx->r18 == 0) {
        // 0x80801C10: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80801C1C;
    }
    // 0x80801C10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801C14: b           L_80801C20
    // 0x80801C18: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
        goto L_80801C20;
    // 0x80801C18: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
L_80801C1C:
    // 0x80801C1C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
L_80801C20:
    // 0x80801C20: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80801C24: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80801C28: jal         0x800BABB8
    // 0x80801C2C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    func_800BABB8(rdram, ctx);
        goto after_0;
    // 0x80801C2C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_0:
    // 0x80801C30: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801C34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801C38: jal         0x800BA3FC
    // 0x80801C3C: addiu       $a1, $s0, 0x9DF
    ctx->r5 = ADD32(ctx->r16, 0X9DF);
    func_800BA3FC(rdram, ctx);
        goto after_1;
    // 0x80801C3C: addiu       $a1, $s0, 0x9DF
    ctx->r5 = ADD32(ctx->r16, 0X9DF);
    after_1:
    // 0x80801C40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801C44: jal         0x800BA22C
    // 0x80801C48: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800BA22C(rdram, ctx);
        goto after_2;
    // 0x80801C48: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80801C4C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801C50: bne         $s0, $s5, L_80801C0C
    if (ctx->r16 != ctx->r21) {
        // 0x80801C54: nop
    
            goto L_80801C0C;
    }
    // 0x80801C54: nop

    // 0x80801C58: beq         $s2, $zero, L_80801C68
    if (ctx->r18 == 0) {
        // 0x80801C5C: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80801C68;
    }
    // 0x80801C5C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80801C60: b           L_80801C6C
    // 0x80801C64: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
        goto L_80801C6C;
    // 0x80801C64: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
L_80801C68:
    // 0x80801C68: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
L_80801C6C:
    // 0x80801C6C: jal         0x80086E20
    // 0x80801C70: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    _chskeletonexplode_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x80801C70: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_3:
    // 0x80801C74: lui         $a0, 0x7FFF
    ctx->r4 = S32(0X7FFF << 16);
    // 0x80801C78: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80801C7C: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80801C80: ori         $a0, $a0, 0x441F
    ctx->r4 = ctx->r4 | 0X441F;
    // 0x80801C84: jal         0x800C4140
    // 0x80801C88: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800C4140(rdram, ctx);
        goto after_4;
    // 0x80801C88: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_4:
    // 0x80801C8C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80801C90: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80801C94: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80801C98: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80801C9C: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80801CA0: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80801CA4: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80801CA8: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80801CAC: jr          $ra
    // 0x80801CB0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80801CB0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80800018_chghostdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080001C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800024: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800028: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8080002C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800030: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800034: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80800038: bne         $t7, $at, L_80800050
    if (ctx->r15 != ctx->r1) {
        // 0x8080003C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800050;
    }
    // 0x8080003C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800040: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800044: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800048: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080004C: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
L_80800050:
    // 0x80800050: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800054: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800058: jal         0x800EFD24
    // 0x8080005C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x8080005C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80800060: jal         0x80103014
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_1;
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800068: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080006C: lui         $a3, 0x4422
    ctx->r7 = S32(0X4422 << 16);
    // 0x80800070: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x80800074: addiu       $t9, $zero, 0x96
    ctx->r25 = ADD32(0, 0X96);
    // 0x80800078: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080007C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80800080: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800084: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080008C: jal         0x80086898
    // 0x80800090: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800090: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_2:
    // 0x80800094: beq         $v0, $zero, L_808000C8
    if (ctx->r2 == 0) {
        // 0x80800098: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000C8;
    }
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080009C: jal         0x800868A8
    // 0x808000A0: lui         $a1, 0x4060
    ctx->r5 = S32(0X4060 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x808000A0: lui         $a1, 0x4060
    ctx->r5 = S32(0X4060 << 16);
    after_3:
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A8: jal         0x800868B0
    // 0x808000AC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x808000AC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_4:
    // 0x808000B0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B8: beq         $t0, $zero, L_808000C8
    if (ctx->r8 == 0) {
        // 0x808000BC: nop
    
            goto L_808000C8;
    }
    // 0x808000BC: nop

    // 0x808000C0: jal         0x800868C0
    // 0x808000C4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x808000C4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_5:
L_808000C8:
    // 0x808000C8: jal         0x800DA298
    // 0x808000CC: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x808000CC: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_6:
    // 0x808000D0: beql        $v0, $zero, L_808000E4
    if (ctx->r2 == 0) {
        // 0x808000D4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808000E4;
    }
    goto skip_0;
    // 0x808000D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808000D8: jal         0x800FFAB0
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_7;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808000E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000E4:
    // 0x808000E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000EC: jr          $ra
    // 0x808000F0: nop

    return;
    // 0x808000F0: nop

;}
RECOMP_FUNC void func_8080176C_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080176C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80801770: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801774: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801778: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080177C: jal         0x80100094
    // 0x80801780: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801780: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801784: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80801788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080178C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801790: jal         0x8080169C
    // 0x80801794: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_8080169C_chhandcart(rdram, ctx);
        goto after_1;
    // 0x80801794: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x80801798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080179C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808017A0: jal         0x8080169C
    // 0x808017A4: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_8080169C_chhandcart(rdram, ctx);
        goto after_2;
    // 0x808017A4: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_2:
    // 0x808017A8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808017AC: jal         0x800F1828
    // 0x808017B0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800F1828(rdram, ctx);
        goto after_3;
    // 0x808017B0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_3:
    // 0x808017B4: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808017B8: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808017BC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808017C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808017C4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808017C8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808017CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808017D0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808017D4: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x808017D8: lwc1        $f18, 0x93C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X93C);
    // 0x808017DC: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x808017E0: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    // 0x808017E4: lwc1        $f8, 0x4C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x808017E8: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x808017EC: nop

    // 0x808017F0: bc1f        L_8080181C
    if (!c1cs) {
        // 0x808017F4: nop
    
            goto L_8080181C;
    }
    // 0x808017F4: nop

    // 0x808017F8: jal         0x80013970
    // 0x808017FC: lwc1        $f12, 0x93C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X93C);
    func_80013970(rdram, ctx);
        goto after_4;
    // 0x808017FC: lwc1        $f12, 0x93C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X93C);
    after_4:
    // 0x80801800: lui         $at, 0x4268
    ctx->r1 = S32(0X4268 << 16);
    // 0x80801804: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801808: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080180C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80801810: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80801814: b           L_8080183C
    // 0x80801818: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
        goto L_8080183C;
    // 0x80801818: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
L_8080181C:
    // 0x8080181C: jal         0x80013970
    // 0x80801820: lwc1        $f12, 0x93C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X93C);
    func_80013970(rdram, ctx);
        goto after_5;
    // 0x80801820: lwc1        $f12, 0x93C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X93C);
    after_5:
    // 0x80801824: lui         $at, 0x4268
    ctx->r1 = S32(0X4268 << 16);
    // 0x80801828: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080182C: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801830: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80801834: sub.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80801838: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
L_8080183C:
    // 0x8080183C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801840: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801844: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80801848: jr          $ra
    // 0x8080184C: nop

    return;
    // 0x8080184C: nop

;}
RECOMP_FUNC void bainput_should_beak_bust(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097A90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80097A94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097A98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80097A9C: jal         0x80091A58
    // 0x80097AA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x80097AA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80097AA4: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097AA8: beq         $t6, $zero, L_80097AC0
    if (ctx->r14 == 0) {
        // 0x80097AAC: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80097AC0;
    }
    // 0x80097AAC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80097AB0: jal         0x8008D14C
    // 0x80097AB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008D14C(rdram, ctx);
        goto after_1;
    // 0x80097AB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80097AB8: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097ABC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80097AC0:
    // 0x80097AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097AC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80097AC8: jr          $ra
    // 0x80097ACC: nop

    return;
    // 0x80097ACC: nop

;}
RECOMP_FUNC void _chnewmumbo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086978: syscall     403
    recomp_syscall_handler(rdram, ctx, 0x80086978);
    return;
    // 0x8008697C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800E9898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9898: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E989C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800E98A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E98A4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E98A8: jal         0x800B3CDC
    // 0x800E98AC: addiu       $a0, $a0, 0x2DB0
    ctx->r4 = ADD32(ctx->r4, 0X2DB0);
    func_800B3CDC(rdram, ctx);
        goto after_0;
    // 0x800E98AC: addiu       $a0, $a0, 0x2DB0
    ctx->r4 = ADD32(ctx->r4, 0X2DB0);
    after_0:
    // 0x800E98B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E98B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E98B8: jr          $ra
    // 0x800E98BC: nop

    return;
    // 0x800E98BC: nop

;}
RECOMP_FUNC void _basudie_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085228: syscall     155
    recomp_syscall_handler(rdram, ctx, 0x80085228);
    return;
    // 0x8008522C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void gcstatusDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x808000A8: jr          $ra
    // 0x808000AC: sb          $a0, -0x4BFC($at)
    MEM_B(-0X4BFC, ctx->r1) = ctx->r4;
    return;
    // 0x808000AC: sb          $a0, -0x4BFC($at)
    MEM_B(-0X4BFC, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_80800630_chbottlesfamily(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800630: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800634: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800638: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080063C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800640: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800644: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800648: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080064C: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800650: addiu       $s1, $a0, 0x4
    ctx->r17 = ADD32(ctx->r4, 0X4);
    // 0x80800654: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800658: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080065C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80800660: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800664: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800668: jal         0x80089F18
    // 0x8080066C: nop

    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080066C: nop

    after_0:
    // 0x80800670: jal         0x80089828
    // 0x80800674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suexpression_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80800674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800678: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080067C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800680: jal         0x800897D8
    // 0x80800684: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800684: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800688: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x8080068C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800694: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800698: bne         $t7, $at, L_808006A8
    if (ctx->r15 != ctx->r1) {
        // 0x8080069C: lui         $a1, 0x8080
        ctx->r5 = S32(RELOC_HI16(1300, 0XF2C) << 16);
            goto L_808006A8;
    }
    // 0x8080069C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1300, 0XF2C) << 16);
    // 0x808006A0: jal         0x808009F0
    // 0x808006A4: addiu       $a1, $a1, 0xF2C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1300, 0XF2C));
    func_808009F0_chbottlesfamily(rdram, ctx);
        goto after_3;
    // 0x808006A4: addiu       $a1, $a1, 0xF2C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1300, 0XF2C));
    after_3:
L_808006A8:
    // 0x808006A8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1300, 0XF68) << 16);
    // 0x808006AC: addiu       $a1, $a1, 0xF68
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1300, 0XF68));
    // 0x808006B0: jal         0x80101E4C
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E4C(rdram, ctx);
        goto after_4;
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808006B8: beq         $v0, $zero, L_808006F0
    if (ctx->r2 == 0) {
        // 0x808006BC: nop
    
            goto L_808006F0;
    }
    // 0x808006BC: nop

    // 0x808006C0: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x808006C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808006C8: bne         $a0, $zero, L_808006E0
    if (ctx->r4 != 0) {
        // 0x808006CC: nop
    
            goto L_808006E0;
    }
    // 0x808006CC: nop

    // 0x808006D0: jal         0x80089D10
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808006D8: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
    // 0x808006DC: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
L_808006E0:
    // 0x808006E0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1300, 0XF48) << 16);
    // 0x808006E4: addiu       $a2, $a2, 0xF48
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1300, 0XF48));
    // 0x808006E8: jal         0x800C4350
    // 0x808006EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800C4350(rdram, ctx);
        goto after_6;
    // 0x808006EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
L_808006F0:
    // 0x808006F0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1300, 0XF58) << 16);
    // 0x808006F4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1300, 0XF78) << 16);
    // 0x808006F8: addiu       $a3, $a3, 0xF78
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1300, 0XF78));
    // 0x808006FC: addiu       $a2, $a2, 0xF58
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1300, 0XF58));
    // 0x80800700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800704: jal         0x80089D28
    // 0x80800708: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80800708: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x8080070C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800710: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800714: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800718: jr          $ra
    // 0x8080071C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8080071C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80805AC0_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805AC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80805AC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80805AC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80805ACC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80805AD0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80805AD4: lw          $a3, 0x18($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X18);
    // 0x80805AD8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80805ADC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80805AE0: beq         $a3, $zero, L_80805AF8
    if (ctx->r7 == 0) {
        // 0x80805AE4: nop
    
            goto L_80805AF8;
    }
    // 0x80805AE4: nop

    // 0x80805AE8: beql        $a3, $at, L_80805B0C
    if (ctx->r7 == ctx->r1) {
        // 0x80805AEC: lw          $v0, 0x1C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1C);
            goto L_80805B0C;
    }
    goto skip_0;
    // 0x80805AEC: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    skip_0:
    // 0x80805AF0: b           L_80805B90
    // 0x80805AF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80805B90;
    // 0x80805AF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80805AF8:
    // 0x80805AF8: jal         0x80802C7C
    // 0x80805AFC: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    func_80802C7C_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80805AFC: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    after_0:
    // 0x80805B00: b           L_80805B90
    // 0x80805B04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80805B90;
    // 0x80805B04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80805B08: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
L_80805B0C:
    // 0x80805B0C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80805B10: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80805B14: beq         $v0, $at, L_80805B84
    if (ctx->r2 == ctx->r1) {
        // 0x80805B18: nop
    
            goto L_80805B84;
    }
    // 0x80805B18: nop

    // 0x80805B1C: bne         $t6, $v0, L_80805B84
    if (ctx->r14 != ctx->r2) {
        // 0x80805B20: nop
    
            goto L_80805B84;
    }
    // 0x80805B20: nop

    // 0x80805B24: jal         0x80802C48
    // 0x80805B28: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    func_80802C48_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80805B28: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    after_1:
    // 0x80805B2C: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x80805B30: jal         0x808026C8
    // 0x80805B34: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808026C8_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80805B34: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_2:
    // 0x80805B38: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80805B3C: sw          $t7, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r15;
    // 0x80805B40: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80805B44: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80805B48: bne         $t8, $at, L_80805B60
    if (ctx->r24 != ctx->r1) {
        // 0x80805B4C: nop
    
            goto L_80805B60;
    }
    // 0x80805B4C: nop

    // 0x80805B50: jal         0x808068E8
    // 0x80805B54: nop

    func_808068E8_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80805B54: nop

    after_3:
    // 0x80805B58: b           L_80805B6C
    // 0x80805B5C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_80805B6C;
    // 0x80805B5C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_80805B60:
    // 0x80805B60: jal         0x80806A30
    // 0x80805B64: nop

    func_80806A30_chgameselect(rdram, ctx);
        goto after_4;
    // 0x80805B64: nop

    after_4:
    // 0x80805B68: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_80805B6C:
    // 0x80805B6C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80805B70: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80805B74: jal         0x80806AF4
    // 0x80805B78: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_80806AF4_chgameselect(rdram, ctx);
        goto after_5;
    // 0x80805B78: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_5:
    // 0x80805B7C: b           L_80805B90
    // 0x80805B80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80805B90;
    // 0x80805B80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80805B84:
    // 0x80805B84: jal         0x80802C7C
    // 0x80805B88: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    func_80802C7C_chgameselect(rdram, ctx);
        goto after_6;
    // 0x80805B88: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    after_6:
    // 0x80805B8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80805B90:
    // 0x80805B90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80805B94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80805B98: jr          $ra
    // 0x80805B9C: nop

    return;
    // 0x80805B9C: nop

;}
RECOMP_FUNC void func_8080000C_chlilterry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800018: jal         0x80089EC8
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sucoasterfly_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: jal         0x8010A3E8
    // 0x80800028: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_8010A3E8(rdram, ctx);
        goto after_1;
    // 0x80800028: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_1:
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

    // 0x8080003C: nop

;}
RECOMP_FUNC void suspline_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D0: jr          $ra
    // 0x808001D4: lbu         $v0, 0x8B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X8B);
    return;
    // 0x808001D4: lbu         $v0, 0x8B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X8B);
;}
RECOMP_FUNC void func_80801A44_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801A48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A4C: jal         0x80084C58
    // 0x80801A50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bafly_entrypoint_18(rdram, ctx);
        goto after_0;
    // 0x80801A50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801A54: jal         0x80800188
    // 0x80801A58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800188_bsbfly(rdram, ctx);
        goto after_1;
    // 0x80801A58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801A5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801A60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801A64: jr          $ra
    // 0x80801A68: nop

    return;
    // 0x80801A68: nop

;}
RECOMP_FUNC void _gcnewoption_entrypoint_33(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087DA0: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087DA0);
    return;
    // 0x80087DA4: addi        $t0, $zero, 0x84
    ctx->r8 = ADD32(0, 0X84);
;}
RECOMP_FUNC void func_80804A50_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804A50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804A54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804A58: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80804A5C: jal         0x80100094
    // 0x80804A60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80804A60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80804A64: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80804A68: sh          $t6, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r14;
    // 0x80804A6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804A70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804A74: jr          $ra
    // 0x80804A78: nop

    return;
    // 0x80804A78: nop

;}
RECOMP_FUNC void func_80800670_chfactorytoxicpools(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800670: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800674: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800678: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8080067C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800680: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800684: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800688: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080068C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80800690: jal         0x80100094
    // 0x80800694: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800694: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800698: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8080069C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808006A0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808006A4: lhu         $v1, 0x72($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X72);
    // 0x808006A8: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x808006AC: beq         $t6, $at, L_808006C4
    if (ctx->r14 == ctx->r1) {
        // 0x808006B0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808006C4;
    }
    // 0x808006B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808006B4: beq         $t6, $at, L_80800838
    if (ctx->r14 == ctx->r1) {
        // 0x808006B8: nop
    
            goto L_80800838;
    }
    // 0x808006B8: nop

    // 0x808006BC: b           L_8080087C
    // 0x808006C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8080087C;
    // 0x808006C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808006C4:
    // 0x808006C4: jal         0x800F54E4
    // 0x808006C8: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808006C8: nop

    after_1:
    // 0x808006CC: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808006D0: jal         0x800F6A38
    // 0x808006D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6A38(rdram, ctx);
        goto after_2;
    // 0x808006D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808006D8: beq         $v0, $zero, L_8080076C
    if (ctx->r2 == 0) {
        // 0x808006DC: addiu       $s2, $sp, 0x4C
        ctx->r18 = ADD32(ctx->r29, 0X4C);
            goto L_8080076C;
    }
    // 0x808006DC: addiu       $s2, $sp, 0x4C
    ctx->r18 = ADD32(ctx->r29, 0X4C);
    // 0x808006E0: jal         0x800F5C94
    // 0x808006E4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800F5C94(rdram, ctx);
        goto after_3;
    // 0x808006E4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x808006E8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808006EC: jal         0x800F5D18
    // 0x808006F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800F5D18(rdram, ctx);
        goto after_4;
    // 0x808006F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_4:
    // 0x808006F4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x808006F8: beq         $s0, $at, L_80800878
    if (ctx->r16 == ctx->r1) {
        // 0x808006FC: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_80800878;
    }
    // 0x808006FC: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80800700: beql        $s0, $at, L_8080087C
    if (ctx->r16 == ctx->r1) {
        // 0x80800704: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8080087C;
    }
    goto skip_0;
    // 0x80800704: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80800708: beq         $v0, $zero, L_80800878
    if (ctx->r2 == 0) {
        // 0x8080070C: lw          $a0, 0x68($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X68);
            goto L_80800878;
    }
    // 0x8080070C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80800710: jal         0x800D9078
    // 0x80800714: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D9078(rdram, ctx);
        goto after_5;
    // 0x80800714: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_5:
    // 0x80800718: beq         $v0, $zero, L_80800878
    if (ctx->r2 == 0) {
        // 0x8080071C: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80800878;
    }
    // 0x8080071C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800720: lh          $t7, 0x0($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X0);
    // 0x80800724: addiu       $a1, $zero, 0x52
    ctx->r5 = ADD32(0, 0X52);
    // 0x80800728: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8080072C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80800730: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80800734: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800738: addu        $a2, $s3, $t8
    ctx->r6 = ADD32(ctx->r19, ctx->r24);
    // 0x8080073C: jal         0x800F7D90
    // 0x80800740: addiu       $a2, $a2, 0x14
    ctx->r6 = ADD32(ctx->r6, 0X14);
    func_800F7D90(rdram, ctx);
        goto after_6;
    // 0x80800740: addiu       $a2, $a2, 0x14
    ctx->r6 = ADD32(ctx->r6, 0X14);
    after_6:
    // 0x80800744: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80800748: jal         0x80101FDC
    // 0x8080074C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x8080074C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x80800750: jal         0x80800898
    // 0x80800754: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    func_80800898_chfactorytoxicpools(rdram, ctx);
        goto after_8;
    // 0x80800754: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_8:
    // 0x80800758: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8080075C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800760: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80800764: b           L_80800878
    // 0x80800768: swc1        $f4, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->f4.u32l;
        goto L_80800878;
    // 0x80800768: swc1        $f4, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->f4.u32l;
L_8080076C:
    // 0x8080076C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800770: jal         0x800F5A00
    // 0x80800774: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800F5A00(rdram, ctx);
        goto after_9;
    // 0x80800774: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_9:
    // 0x80800778: lh          $t0, 0x2($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X2);
    // 0x8080077C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800780: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x80800784: blez        $t0, L_80800824
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80800788: nop
    
            goto L_80800824;
    }
    // 0x80800788: nop

L_8080078C:
    // 0x8080078C: jal         0x800F5628
    // 0x80800790: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800F5628(rdram, ctx);
        goto after_10;
    // 0x80800790: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_10:
    // 0x80800794: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1156, 0X934) << 16);
    // 0x80800798: lwc1        $f6, 0x934($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1156, 0X934));
    // 0x8080079C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808007A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808007A4: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x808007A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808007AC: bc1t        L_808007B8
    if (c1cs) {
        // 0x808007B0: nop
    
            goto L_808007B8;
    }
    // 0x808007B0: nop

    // 0x808007B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007B8:
    // 0x808007B8: beq         $v0, $zero, L_808007C8
    if (ctx->r2 == 0) {
        // 0x808007BC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808007C8;
    }
    // 0x808007BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808007C0: b           L_808007D0
    // 0x808007C4: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
        goto L_808007D0;
    // 0x808007C4: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
L_808007C8:
    // 0x808007C8: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x808007CC: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
L_808007D0:
    // 0x808007D0: lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4);
    // 0x808007D4: jal         0x800CC338
    // 0x808007D8: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    func_800CC338(rdram, ctx);
        goto after_11;
    // 0x808007D8: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_11:
    // 0x808007DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808007E0: beq         $v0, $at, L_8080080C
    if (ctx->r2 == ctx->r1) {
        // 0x808007E4: lw          $v1, 0x40($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X40);
            goto L_8080080C;
    }
    // 0x808007E4: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x808007E8: bne         $v1, $zero, L_80800800
    if (ctx->r3 != 0) {
        // 0x808007EC: addiu       $a0, $s0, 0x14
        ctx->r4 = ADD32(ctx->r16, 0X14);
            goto L_80800800;
    }
    // 0x808007EC: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x808007F0: jal         0x800EE7F8
    // 0x808007F4: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    func_800EE7F8(rdram, ctx);
        goto after_12;
    // 0x808007F4: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    after_12:
    // 0x808007F8: b           L_8080080C
    // 0x808007FC: sh          $s1, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r17;
        goto L_8080080C;
    // 0x808007FC: sh          $s1, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r17;
L_80800800:
    // 0x80800800: jal         0x800EE7F8
    // 0x80800804: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_13;
    // 0x80800804: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_13:
    // 0x80800808: sh          $s1, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r17;
L_8080080C:
    // 0x8080080C: lh          $t1, 0x2($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X2);
    // 0x80800810: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800814: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x80800818: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8080081C: bne         $at, $zero, L_8080078C
    if (ctx->r1 != 0) {
        // 0x80800820: nop
    
            goto L_8080078C;
    }
    // 0x80800820: nop

L_80800824:
    // 0x80800824: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1156, 0X938) << 16);
    // 0x80800828: lwc1        $f10, 0x938($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1156, 0X938));
    // 0x8080082C: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x80800830: b           L_80800878
    // 0x80800834: swc1        $f10, 0x58($t2)
    MEM_W(0X58, ctx->r10) = ctx->f10.u32l;
        goto L_80800878;
    // 0x80800834: swc1        $f10, 0x58($t2)
    MEM_W(0X58, ctx->r10) = ctx->f10.u32l;
L_80800838:
    // 0x80800838: jal         0x800D9078
    // 0x8080083C: addiu       $a0, $a1, 0x58
    ctx->r4 = ADD32(ctx->r5, 0X58);
    func_800D9078(rdram, ctx);
        goto after_14;
    // 0x8080083C: addiu       $a0, $a1, 0x58
    ctx->r4 = ADD32(ctx->r5, 0X58);
    after_14:
    // 0x80800840: beql        $v0, $zero, L_8080087C
    if (ctx->r2 == 0) {
        // 0x80800844: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8080087C;
    }
    goto skip_1;
    // 0x80800844: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80800848: jal         0x800F54E4
    // 0x8080084C: nop

    func_800F54E4(rdram, ctx);
        goto after_15;
    // 0x8080084C: nop

    after_15:
    // 0x80800850: jal         0x800F5578
    // 0x80800854: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5578(rdram, ctx);
        goto after_16;
    // 0x80800854: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_16:
    // 0x80800858: blez        $v0, L_80800878
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080085C: lw          $a0, 0x68($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X68);
            goto L_80800878;
    }
    // 0x8080085C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80800860: jal         0x80101FDC
    // 0x80800864: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_17;
    // 0x80800864: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80800868: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1156, 0X93C) << 16);
    // 0x8080086C: lwc1        $f16, 0x93C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1156, 0X93C));
    // 0x80800870: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x80800874: swc1        $f16, 0x58($t3)
    MEM_W(0X58, ctx->r11) = ctx->f16.u32l;
L_80800878:
    // 0x80800878: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080087C:
    // 0x8080087C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800880: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800884: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800888: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8080088C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800890: jr          $ra
    // 0x80800894: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80800894: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_800C9B30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9B30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C9B34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9B38: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C9B3C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C9B40: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800C9B44: jal         0x801069A4
    // 0x800C9B48: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_801069A4(rdram, ctx);
        goto after_0;
    // 0x800C9B48: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C9B4C: beq         $v0, $zero, L_800C9B74
    if (ctx->r2 == 0) {
        // 0x800C9B50: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_800C9B74;
    }
    // 0x800C9B50: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9B54: lhu         $t7, 0x12($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X12);
    // 0x800C9B58: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800C9B5C: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x800C9B60: srl         $t8, $t7, 1
    ctx->r24 = S32(U32(ctx->r15) >> 1);
    // 0x800C9B64: bnel        $t6, $t8, L_800C9B78
    if (ctx->r14 != ctx->r24) {
        // 0x800C9B68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C9B78;
    }
    goto skip_0;
    // 0x800C9B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C9B6C: jal         0x8010114C
    // 0x800C9B70: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_8010114C(rdram, ctx);
        goto after_1;
    // 0x800C9B70: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_1:
L_800C9B74:
    // 0x800C9B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9B78:
    // 0x800C9B78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C9B7C: jr          $ra
    // 0x800C9B80: nop

    return;
    // 0x800C9B80: nop

;}
RECOMP_FUNC void func_80800BE0_chnastycavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BE0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800BE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800BE8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800BEC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800BF0: jal         0x80100094
    // 0x80800BF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800BF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800BF8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800BFC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800C00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800C04: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800C08: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800C0C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800C10: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800C14: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800C18: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x80800C1C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800C20: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800C24: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80800C28: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800C2C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800C30: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80800C34: jal         0x80089F20
    // 0x80800C38: nop

    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800C38: nop

    after_1:
    // 0x80800C3C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800C40: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800C44: jal         0x800897D8
    // 0x80800C48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800C48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800C4C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800C50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800C54: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800C58: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x80800C5C: beq         $t7, $at, L_80800C88
    if (ctx->r15 == ctx->r1) {
        // 0x80800C60: addiu       $a1, $zero, 0x190
        ctx->r5 = ADD32(0, 0X190);
            goto L_80800C88;
    }
    // 0x80800C60: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    // 0x80800C64: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800C68: beq         $t7, $at, L_80800E54
    if (ctx->r15 == ctx->r1) {
        // 0x80800C6C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800E54;
    }
    // 0x80800C6C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800C70: beq         $t7, $at, L_80800D0C
    if (ctx->r15 == ctx->r1) {
        // 0x80800C74: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800D0C;
    }
    // 0x80800C74: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800C78: beq         $t7, $at, L_80800DAC
    if (ctx->r15 == ctx->r1) {
        // 0x80800C7C: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80800DAC;
    }
    // 0x80800C7C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800C80: b           L_80800E58
    // 0x80800C84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E58;
    // 0x80800C84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800C88:
    // 0x80800C88: addiu       $a2, $zero, 0x190
    ctx->r6 = ADD32(0, 0X190);
    // 0x80800C8C: jal         0x8010C9FC
    // 0x80800C90: addiu       $a3, $zero, -0xC8
    ctx->r7 = ADD32(0, -0XC8);
    func_8010C9FC(rdram, ctx);
        goto after_3;
    // 0x80800C90: addiu       $a3, $zero, -0xC8
    ctx->r7 = ADD32(0, -0XC8);
    after_3:
    // 0x80800C94: beql        $v0, $zero, L_80800E58
    if (ctx->r2 == 0) {
        // 0x80800C98: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800E58;
    }
    goto skip_0;
    // 0x80800C98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800C9C: jal         0x80090178
    // 0x80800CA0: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    func_80090178(rdram, ctx);
        goto after_4;
    // 0x80800CA0: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    after_4:
    // 0x80800CA4: bnel        $v0, $zero, L_80800E58
    if (ctx->r2 != 0) {
        // 0x80800CA8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800E58;
    }
    goto skip_1;
    // 0x80800CA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800CAC: jal         0x80800060
    // 0x80800CB0: nop

    func_80800060_chnastycavemen(rdram, ctx);
        goto after_5;
    // 0x80800CB0: nop

    after_5:
    // 0x80800CB4: beq         $v0, $zero, L_80800CC4
    if (ctx->r2 == 0) {
        // 0x80800CB8: nop
    
            goto L_80800CC4;
    }
    // 0x80800CB8: nop

    // 0x80800CBC: b           L_80800CE0
    // 0x80800CC0: addiu       $a1, $zero, 0x17EF
    ctx->r5 = ADD32(0, 0X17EF);
        goto L_80800CE0;
    // 0x80800CC0: addiu       $a1, $zero, 0x17EF
    ctx->r5 = ADD32(0, 0X17EF);
L_80800CC4:
    // 0x80800CC4: jal         0x8008FF6C
    // 0x80800CC8: nop

    func_8008FF6C(rdram, ctx);
        goto after_6;
    // 0x80800CC8: nop

    after_6:
    // 0x80800CCC: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80800CD0: bne         $v0, $at, L_80800CE0
    if (ctx->r2 != ctx->r1) {
        // 0x80800CD4: addiu       $a1, $zero, 0x17F1
        ctx->r5 = ADD32(0, 0X17F1);
            goto L_80800CE0;
    }
    // 0x80800CD4: addiu       $a1, $zero, 0x17F1
    ctx->r5 = ADD32(0, 0X17F1);
    // 0x80800CD8: b           L_80800CE0
    // 0x80800CDC: addiu       $a1, $zero, 0x17F0
    ctx->r5 = ADD32(0, 0X17F0);
        goto L_80800CE0;
    // 0x80800CDC: addiu       $a1, $zero, 0x17F0
    ctx->r5 = ADD32(0, 0X17F0);
L_80800CE0:
    // 0x80800CE0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800CE4: addiu       $t8, $zero, 0x96
    ctx->r24 = ADD32(0, 0X96);
    // 0x80800CE8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800CEC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80800CF0: jal         0x8008A208
    // 0x80800CF4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x80800CF4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x80800CF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CFC: jal         0x80102424
    // 0x80800D00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x80800D00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x80800D04: b           L_80800E58
    // 0x80800D08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E58;
    // 0x80800D08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D0C:
    // 0x80800D0C: jal         0x80101F24
    // 0x80800D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_9;
    // 0x80800D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800D14: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(760, 0X1204) << 16);
    // 0x80800D18: addiu       $a1, $a1, 0x1204
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(760, 0X1204));
    // 0x80800D1C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800D20: jal         0x800F3780
    // 0x80800D24: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_800F3780(rdram, ctx);
        goto after_10;
    // 0x80800D24: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_10:
    // 0x80800D28: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800D2C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800D30: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D38: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800D3C: nop

    // 0x80800D40: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800D44: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800D48: jal         0x80105A9C
    // 0x80800D4C: nop

    func_80105A9C(rdram, ctx);
        goto after_11;
    // 0x80800D4C: nop

    after_11:
    // 0x80800D50: jal         0x80105BAC
    // 0x80800D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105BAC(rdram, ctx);
        goto after_12;
    // 0x80800D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800D58: jal         0x80105834
    // 0x80800D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_13;
    // 0x80800D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800D60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D64: jal         0x80105230
    // 0x80800D68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80105230(rdram, ctx);
        goto after_14;
    // 0x80800D68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80800D6C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800D70: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800D74: jal         0x800F1DCC
    // 0x80800D78: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    func_800F1DCC(rdram, ctx);
        goto after_15;
    // 0x80800D78: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    after_15:
    // 0x80800D7C: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80800D80: jal         0x80105A5C
    // 0x80800D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_16;
    // 0x80800D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800D88: beql        $v0, $zero, L_80800E58
    if (ctx->r2 == 0) {
        // 0x80800D8C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800E58;
    }
    goto skip_2;
    // 0x80800D8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80800D90: jal         0x80090708
    // 0x80800D94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_17;
    // 0x80800D94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x80800D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D9C: jal         0x80102424
    // 0x80800DA0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_18;
    // 0x80800DA0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_18:
    // 0x80800DA4: b           L_80800E58
    // 0x80800DA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E58;
    // 0x80800DA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800DAC:
    // 0x80800DAC: addiu       $a1, $zero, 0x258
    ctx->r5 = ADD32(0, 0X258);
    // 0x80800DB0: addiu       $a2, $zero, 0x190
    ctx->r6 = ADD32(0, 0X190);
    // 0x80800DB4: jal         0x8010C9FC
    // 0x80800DB8: addiu       $a3, $zero, -0xC8
    ctx->r7 = ADD32(0, -0XC8);
    func_8010C9FC(rdram, ctx);
        goto after_19;
    // 0x80800DB8: addiu       $a3, $zero, -0xC8
    ctx->r7 = ADD32(0, -0XC8);
    after_19:
    // 0x80800DBC: beql        $v0, $zero, L_80800E58
    if (ctx->r2 == 0) {
        // 0x80800DC0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800E58;
    }
    goto skip_3;
    // 0x80800DC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80800DC4: jal         0x80090178
    // 0x80800DC8: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    func_80090178(rdram, ctx);
        goto after_20;
    // 0x80800DC8: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    after_20:
    // 0x80800DCC: bnel        $v0, $zero, L_80800E58
    if (ctx->r2 != 0) {
        // 0x80800DD0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800E58;
    }
    goto skip_4;
    // 0x80800DD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80800DD4: jal         0x80800060
    // 0x80800DD8: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    func_80800060_chnastycavemen(rdram, ctx);
        goto after_21;
    // 0x80800DD8: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    after_21:
    // 0x80800DDC: beq         $v0, $zero, L_80800DEC
    if (ctx->r2 == 0) {
        // 0x80800DE0: addiu       $a1, $zero, 0x17EF
        ctx->r5 = ADD32(0, 0X17EF);
            goto L_80800DEC;
    }
    // 0x80800DE0: addiu       $a1, $zero, 0x17EF
    ctx->r5 = ADD32(0, 0X17EF);
    // 0x80800DE4: b           L_80800E28
    // 0x80800DE8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
        goto L_80800E28;
    // 0x80800DE8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
L_80800DEC:
    // 0x80800DEC: jal         0x8008FF6C
    // 0x80800DF0: nop

    func_8008FF6C(rdram, ctx);
        goto after_22;
    // 0x80800DF0: nop

    after_22:
    // 0x80800DF4: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80800DF8: bne         $v0, $at, L_80800E0C
    if (ctx->r2 != ctx->r1) {
        // 0x80800DFC: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80800E0C;
    }
    // 0x80800DFC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E00: addiu       $t9, $zero, 0x17F0
    ctx->r25 = ADD32(0, 0X17F0);
    // 0x80800E04: b           L_80800E28
    // 0x80800E08: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
        goto L_80800E28;
    // 0x80800E08: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
L_80800E0C:
    // 0x80800E0C: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    // 0x80800E10: addiu       $a2, $zero, 0x2D
    ctx->r6 = ADD32(0, 0X2D);
    // 0x80800E14: jal         0x8008A1D8
    // 0x80800E18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_5(rdram, ctx);
        goto after_23;
    // 0x80800E18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_23:
    // 0x80800E1C: beq         $v0, $zero, L_80800E28
    if (ctx->r2 == 0) {
        // 0x80800E20: addiu       $t0, $zero, 0x1804
        ctx->r8 = ADD32(0, 0X1804);
            goto L_80800E28;
    }
    // 0x80800E20: addiu       $t0, $zero, 0x1804
    ctx->r8 = ADD32(0, 0X1804);
    // 0x80800E24: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
L_80800E28:
    // 0x80800E28: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800E2C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80800E30: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E34: beq         $a1, $zero, L_80800E54
    if (ctx->r5 == 0) {
        // 0x80800E38: addiu       $t1, $zero, 0x96
        ctx->r9 = ADD32(0, 0X96);
            goto L_80800E54;
    }
    // 0x80800E38: addiu       $t1, $zero, 0x96
    ctx->r9 = ADD32(0, 0X96);
    // 0x80800E3C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800E40: jal         0x8008A208
    // 0x80800E44: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_24;
    // 0x80800E44: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_24:
    // 0x80800E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E4C: jal         0x80102424
    // 0x80800E50: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_25;
    // 0x80800E50: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_25:
L_80800E54:
    // 0x80800E54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E58:
    // 0x80800E58: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800E5C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800E60: jr          $ra
    // 0x80800E64: nop

    return;
    // 0x80800E64: nop

;}
RECOMP_FUNC void func_808003A0_gccubeDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808003A4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808003A8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x808003AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003B8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808003BC: jal         0x800825C8
    // 0x808003C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_0;
    // 0x808003C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808003C4: bne         $v0, $zero, L_80800444
    if (ctx->r2 != 0) {
        // 0x808003C8: addiu       $s1, $sp, 0x2C
        ctx->r17 = ADD32(ctx->r29, 0X2C);
            goto L_80800444;
    }
    // 0x808003C8: addiu       $s1, $sp, 0x2C
    ctx->r17 = ADD32(ctx->r29, 0X2C);
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003D0:
    // 0x808003D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808003D4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808003D8: jal         0x800825F8
    // 0x808003DC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _gsmaker_entrypoint_22(rdram, ctx);
        goto after_1;
    // 0x808003DC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x808003E0: beq         $v0, $zero, L_80800400
    if (ctx->r2 == 0) {
        // 0x808003E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800400;
    }
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808003F0: jal         0x800825A8
    // 0x808003F4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _gsmaker_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x808003F4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x808003F8: b           L_80800434
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800434;
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800400:
    // 0x80800400: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800404: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800408: jal         0x800825F8
    // 0x8080040C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _gsmaker_entrypoint_22(rdram, ctx);
        goto after_3;
    // 0x8080040C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_3:
    // 0x80800410: bne         $v0, $zero, L_80800430
    if (ctx->r2 != 0) {
        // 0x80800414: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800430;
    }
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800418: jal         0x800825C8
    // 0x8080041C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_4;
    // 0x8080041C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80800420: beq         $v0, $zero, L_80800430
    if (ctx->r2 == 0) {
        // 0x80800424: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800430;
    }
    // 0x80800424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800428: jal         0x808000B8
    // 0x8080042C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_808000B8_gccubeDll(rdram, ctx);
        goto after_5;
    // 0x8080042C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
L_80800430:
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800434:
    // 0x80800434: jal         0x800825C8
    // 0x80800438: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_6;
    // 0x80800438: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8080043C: beql        $v0, $zero, L_808003D0
    if (ctx->r2 == 0) {
        // 0x80800440: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003D0;
    }
    goto skip_0;
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_80800444:
    // 0x80800444: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800448: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080044C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800450: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800454: jr          $ra
    // 0x80800458: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800458: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8009EBD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EBD0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009EBD4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009EBD8: addiu       $v0, $v0, 0x704C
    ctx->r2 = ADD32(ctx->r2, 0X704C);
    // 0x8009EBDC: addiu       $v1, $v1, 0x7040
    ctx->r3 = ADD32(ctx->r3, 0X7040);
L_8009EBE0:
    // 0x8009EBE0: lw          $t6, 0x14($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X14);
    // 0x8009EBE4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8009EBE8: bne         $v1, $v0, L_8009EBE0
    if (ctx->r3 != ctx->r2) {
        // 0x8009EBEC: sw          $t6, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->r14;
            goto L_8009EBE0;
    }
    // 0x8009EBEC: sw          $t6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r14;
    // 0x8009EBF0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009EBF4: addiu       $v0, $v0, 0x7040
    ctx->r2 = ADD32(ctx->r2, 0X7040);
    // 0x8009EBF8: lbu         $t7, 0x20($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X20);
    // 0x8009EBFC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8009EC00: jr          $ra
    // 0x8009EC04: sb          $t8, 0x20($v0)
    MEM_B(0X20, ctx->r2) = ctx->r24;
    return;
    // 0x8009EC04: sb          $t8, 0x20($v0)
    MEM_B(0X20, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void func_8080282C_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080282C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802830: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802834: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802838: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080283C: jal         0x80800090
    // 0x80802840: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80800090_chhandcart(rdram, ctx);
        goto after_0;
    // 0x80802840: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80802844: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80802848: bne         $v0, $v1, L_80802854
    if (ctx->r2 != ctx->r3) {
        // 0x8080284C: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_80802854;
    }
    // 0x8080284C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80802850: subu        $a1, $v1, $a1
    ctx->r5 = SUB32(ctx->r3, ctx->r5);
L_80802854:
    // 0x80802854: bne         $a1, $zero, L_80802864
    if (ctx->r5 != 0) {
        // 0x80802858: lw          $t6, 0x28($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X28);
            goto L_80802864;
    }
    // 0x80802858: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8080285C: beq         $t6, $zero, L_80802888
    if (ctx->r14 == 0) {
        // 0x80802860: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80802888;
    }
    // 0x80802860: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_80802864:
    // 0x80802864: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80802868: addiu       $a0, $zero, 0x385
    ctx->r4 = ADD32(0, 0X385);
    // 0x8080286C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80802870: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80802874: jal         0x80088280
    // 0x80802878: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    _gccubesearch_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80802878: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x8080287C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80802880: b           L_808028A4
    // 0x80802884: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_808028A4;
    // 0x80802884: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80802888:
    // 0x80802888: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8080288C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80802890: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80802894: jal         0x80088280
    // 0x80802898: addiu       $a0, $zero, 0x384
    ctx->r4 = ADD32(0, 0X384);
    _gccubesearch_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80802898: addiu       $a0, $zero, 0x384
    ctx->r4 = ADD32(0, 0X384);
    after_2:
    // 0x8080289C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808028A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_808028A4:
    // 0x808028A4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808028A8: jal         0x800EE88C
    // 0x808028AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800EE88C(rdram, ctx);
        goto after_3;
    // 0x808028AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_3:
    // 0x808028B0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808028B4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x808028B8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808028BC: lw          $t7, 0xC($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XC);
    // 0x808028C0: srl         $t8, $t7, 23
    ctx->r24 = S32(U32(ctx->r15) >> 23);
    // 0x808028C4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x808028C8: bgez        $t8, L_808028DC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808028CC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808028DC;
    }
    // 0x808028CC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808028D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808028D4: nop

    // 0x808028D8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_808028DC:
    // 0x808028DC: swc1        $f6, 0x48($t9)
    MEM_W(0X48, ctx->r25) = ctx->f6.u32l;
    // 0x808028E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808028E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808028E8: jr          $ra
    // 0x808028EC: nop

    return;
    // 0x808028EC: nop

;}
RECOMP_FUNC void gcnewoption_entrypoint_37(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802B50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802B54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802B58: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x80802B5C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80802B60: beq         $v0, $at, L_80802B70
    if (ctx->r2 == ctx->r1) {
        // 0x80802B64: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80802B70;
    }
    // 0x80802B64: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80802B68: bnel        $v0, $at, L_80802BB4
    if (ctx->r2 != ctx->r1) {
        // 0x80802B6C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80802BB4;
    }
    goto skip_0;
    // 0x80802B6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_80802B70:
    // 0x80802B70: beql        $a1, $zero, L_80802B8C
    if (ctx->r5 == 0) {
        // 0x80802B74: lbu         $t9, 0x1C($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X1C);
            goto L_80802B8C;
    }
    goto skip_1;
    // 0x80802B74: lbu         $t9, 0x1C($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1C);
    skip_1:
    // 0x80802B78: lbu         $t7, 0x1C($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1C);
    // 0x80802B7C: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x80802B80: b           L_80802B94
    // 0x80802B84: sb          $t8, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r24;
        goto L_80802B94;
    // 0x80802B84: sb          $t8, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r24;
    // 0x80802B88: lbu         $t9, 0x1C($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1C);
L_80802B8C:
    // 0x80802B8C: andi        $t0, $t9, 0xFFDF
    ctx->r8 = ctx->r25 & 0XFFDF;
    // 0x80802B90: sb          $t0, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r8;
L_80802B94:
    // 0x80802B94: jal         0x80802A9C
    // 0x80802B98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80802A9C_gcnewoption(rdram, ctx);
        goto after_0;
    // 0x80802B98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802B9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802BA0: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80802BA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80802BA8: b           L_80802BB4
    // 0x80802BAC: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
        goto L_80802BB4;
    // 0x80802BAC: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    // 0x80802BB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802BB4:
    // 0x80802BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802BB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802BBC: jr          $ra
    // 0x80802BC0: nop

    return;
    // 0x80802BC0: nop

;}
RECOMP_FUNC void func_80800000_gcdialogexec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800004: bnel        $a1, $at, L_80800018
    if (ctx->r5 != ctx->r1) {
        // 0x80800008: lhu         $t6, 0x12($a0)
        ctx->r14 = MEM_HU(ctx->r4, 0X12);
            goto L_80800018;
    }
    goto skip_0;
    // 0x80800008: lhu         $t6, 0x12($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X12);
    skip_0:
    // 0x8080000C: jr          $ra
    // 0x80800010: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800010: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800014: lhu         $t6, 0x12($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X12);
L_80800018:
    // 0x80800018: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x8080001C: xor         $v1, $a1, $t7
    ctx->r3 = ctx->r5 ^ ctx->r15;
    // 0x80800020: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80800024: jr          $ra
    // 0x80800028: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800028: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void subaddietaxi_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800604: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800608: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8080060C: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x80800610: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800614: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800618: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8080061C: jal         0x80106790
    // 0x80800620: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800620: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800624: jal         0x8010410C
    // 0x80800628: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_8010410C(rdram, ctx);
        goto after_1;
    // 0x80800628: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_1:
    // 0x8080062C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800630: jal         0x800CB518
    // 0x80800634: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_800CB518(rdram, ctx);
        goto after_2;
    // 0x80800634: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_2:
    // 0x80800638: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8080063C: beq         $t6, $zero, L_8080064C
    if (ctx->r14 == 0) {
        // 0x80800640: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_8080064C;
    }
    // 0x80800640: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800644: jal         0x800888C8
    // 0x80800648: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    _fxsparkle_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800648: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_3:
L_8080064C:
    // 0x8080064C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800650: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80800654: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80800658: jal         0x800EFE50
    // 0x8080065C: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    func_800EFE50(rdram, ctx);
        goto after_4;
    // 0x8080065C: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    after_4:
    // 0x80800660: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80800664: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800668: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x8080066C: lwc1        $f4, 0x18($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X18);
    // 0x80800670: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80800674: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800678: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080067C: jal         0x800F10B4
    // 0x80800680: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x80800680: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x80800684: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3334, 0XD34) << 16);
    // 0x80800688: lwc1        $f2, 0xD34($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3334, 0XD34));
    // 0x8080068C: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80800690: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800694: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x80800698: nop

    // 0x8080069C: bc1fl       L_808006C0
    if (!c1cs) {
        // 0x808006A0: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_808006C0;
    }
    goto skip_0;
    // 0x808006A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x808006A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808006A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808006AC: nop

    // 0x808006B0: div.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x808006B4: b           L_808006E4
    // 0x808006B8: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
        goto L_808006E4;
    // 0x808006B8: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x808006BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_808006C0:
    // 0x808006C0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808006C4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x808006C8: div.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x808006CC: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x808006D0: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x808006D4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x808006D8: jal         0x800F10B4
    // 0x808006DC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x808006DC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x808006E0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
L_808006E4:
    // 0x808006E4: jal         0x80104248
    // 0x808006E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_7;
    // 0x808006E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808006EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006F0: jal         0x8008AF04
    // 0x808006F4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_8008AF04(rdram, ctx);
        goto after_8;
    // 0x808006F4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_8:
    // 0x808006F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808006FC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800700: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800704: jr          $ra
    // 0x80800708: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800708: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800A0E50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0E50: jr          $ra
    // 0x800A0E54: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    return;
    // 0x800A0E54: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
;}
RECOMP_FUNC void suquiz_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C6C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800C70: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800C74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800C78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C7C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80800C80: jal         0x800EE7F8
    // 0x80800C84: lw          $a0, 0x7614($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7614);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800C84: lw          $a0, 0x7614($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7614);
    after_0:
    // 0x80800C88: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80800C8C: lw          $a0, 0x7614($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7614);
    // 0x80800C90: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C94: jal         0x800EE7F8
    // 0x80800C98: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800C98: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_1:
    // 0x80800C9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800CA4: jr          $ra
    // 0x80800CA8: nop

    return;
    // 0x80800CA8: nop

;}
RECOMP_FUNC void _batranslate_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085350: syscall     158
    recomp_syscall_handler(rdram, ctx, 0x80085350);
    return;
    // 0x80085354: xori        $t0, $zero, 0x8
    ctx->r8 = 0 ^ 0X8;
;}
RECOMP_FUNC void func_80800160_chmolehill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800160: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800164: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800168: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080016C: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80800170: lbu         $t8, 0x79($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X79);
    // 0x80800174: lbu         $t6, 0x65($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X65);
    // 0x80800178: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080017C: srl         $t9, $t8, 4
    ctx->r25 = S32(U32(ctx->r24) >> 4);
    // 0x80800180: sltiu       $at, $t9, 0x8
    ctx->r1 = ctx->r25 < 0X8 ? 1 : 0;
    // 0x80800184: andi        $t7, $t6, 0xFFF7
    ctx->r15 = ctx->r14 & 0XFFF7;
    // 0x80800188: beq         $at, $zero, L_80800278
    if (ctx->r1 == 0) {
        // 0x8080018C: sb          $t7, 0x65($a0)
        MEM_B(0X65, ctx->r4) = ctx->r15;
            goto L_80800278;
    }
    // 0x8080018C: sb          $t7, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r15;
    // 0x80800190: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800194: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1560, 0XA50) << 16);
    // 0x80800198: addu        $at, $at, $t9
    gpr jr_addend_808001A0 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8080019C: lw          $t9, 0xA50($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1560, 0XA50));
    // 0x808001A0: jr          $t9
    // 0x808001A4: nop

    switch (jr_addend_808001A0 >> 2) {
        case 0: goto L_80800278; break;
        case 1: goto L_808001C8; break;
        case 2: goto L_80800278; break;
        case 3: goto L_80800214; break;
        case 4: goto L_80800260; break;
        case 5: goto L_80800278; break;
        case 6: goto L_80800278; break;
        case 7: goto L_808001A8; break;
        default: switch_error(__func__, 0x808001A0, 0x80800A50);
    }
    // 0x808001A4: nop

L_808001A8:
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001AC: jal         0x80800698
    // 0x808001B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    chmolehill_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808001B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B8: jal         0x8080075C
    // 0x808001BC: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    chmolehill_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808001BC: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_1:
    // 0x808001C0: b           L_8080027C
    // 0x808001C4: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
        goto L_8080027C;
    // 0x808001C4: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_808001C8:
    // 0x808001C8: jal         0x80800088
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800088_chmolehill(rdram, ctx);
        goto after_2;
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808001D0: lw          $t0, 0x3C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X3C);
    // 0x808001D4: beql        $t0, $zero, L_8080027C
    if (ctx->r8 == 0) {
        // 0x808001D8: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_8080027C;
    }
    goto skip_0;
    // 0x808001D8: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x808001DC: jal         0x80800000
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chmolehill(rdram, ctx);
        goto after_3;
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808001E4: beql        $v0, $zero, L_8080027C
    if (ctx->r2 == 0) {
        // 0x808001E8: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_8080027C;
    }
    goto skip_1;
    // 0x808001E8: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_1:
    // 0x808001EC: jal         0x8008F8B0
    // 0x808001F0: nop

    func_8008F8B0(rdram, ctx);
        goto after_4;
    // 0x808001F0: nop

    after_4:
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F8: jal         0x80800698
    // 0x808001FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    chmolehill_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x808001FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800204: jal         0x8080075C
    // 0x80800208: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    chmolehill_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800208: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x8080020C: b           L_8080027C
    // 0x80800210: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
        goto L_8080027C;
    // 0x80800210: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_80800214:
    // 0x80800214: jal         0x80800088
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800088_chmolehill(rdram, ctx);
        goto after_7;
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080021C: lw          $t1, 0x3C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X3C);
    // 0x80800220: beql        $t1, $zero, L_8080027C
    if (ctx->r9 == 0) {
        // 0x80800224: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_8080027C;
    }
    goto skip_2;
    // 0x80800224: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_2:
    // 0x80800228: jal         0x80800000
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chmolehill(rdram, ctx);
        goto after_8;
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800230: beql        $v0, $zero, L_8080027C
    if (ctx->r2 == 0) {
        // 0x80800234: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_8080027C;
    }
    goto skip_3;
    // 0x80800234: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_3:
    // 0x80800238: jal         0x8008F8B0
    // 0x8080023C: nop

    func_8008F8B0(rdram, ctx);
        goto after_9;
    // 0x8080023C: nop

    after_9:
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800244: jal         0x80800698
    // 0x80800248: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    chmolehill_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x80800248: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800250: jal         0x8080075C
    // 0x80800254: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    chmolehill_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x80800254: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_11:
    // 0x80800258: b           L_8080027C
    // 0x8080025C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
        goto L_8080027C;
    // 0x8080025C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_80800260:
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800264: jal         0x80800698
    // 0x80800268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    chmolehill_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x80800268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800270: jal         0x8080075C
    // 0x80800274: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    chmolehill_entrypoint_2(rdram, ctx);
        goto after_13;
    // 0x80800274: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_13:
L_80800278:
    // 0x80800278: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_8080027C:
    // 0x8080027C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800280: srl         $t2, $v0, 10
    ctx->r10 = S32(U32(ctx->r2) >> 10);
    // 0x80800284: beq         $t2, $at, L_808002C0
    if (ctx->r10 == ctx->r1) {
        // 0x80800288: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_808002C0;
    }
    // 0x80800288: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8080028C: beq         $t2, $at, L_808002C0
    if (ctx->r10 == ctx->r1) {
        // 0x80800290: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_808002C0;
    }
    // 0x80800290: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80800294: beq         $t2, $at, L_808002B4
    if (ctx->r10 == ctx->r1) {
        // 0x80800298: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_808002B4;
    }
    // 0x80800298: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8080029C: bnel        $t2, $at, L_808002C4
    if (ctx->r10 != ctx->r1) {
        // 0x808002A0: lh          $t9, 0x8C($s0)
        ctx->r25 = MEM_H(ctx->r16, 0X8C);
            goto L_808002C4;
    }
    goto skip_4;
    // 0x808002A0: lh          $t9, 0x8C($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X8C);
    skip_4:
    // 0x808002A4: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x808002A8: ori         $t5, $t4, 0x8
    ctx->r13 = ctx->r12 | 0X8;
    // 0x808002AC: b           L_808002C0
    // 0x808002B0: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
        goto L_808002C0;
    // 0x808002B0: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
L_808002B4:
    // 0x808002B4: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x808002B8: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x808002BC: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
L_808002C0:
    // 0x808002C0: lh          $t9, 0x8C($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X8C);
L_808002C4:
    // 0x808002C4: beql        $t9, $zero, L_808004F0
    if (ctx->r25 == 0) {
        // 0x808002C8: lw          $t0, 0x3C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X3C);
            goto L_808004F0;
    }
    goto skip_5;
    // 0x808002C8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    skip_5:
    // 0x808002CC: jal         0x80104248
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_14;
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808002D4: jal         0x8008B284
    // 0x808002D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_getPlaybackType(rdram, ctx);
        goto after_15;
    // 0x808002D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_15:
    // 0x808002DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808002E0: beql        $v0, $at, L_808004F0
    if (ctx->r2 == ctx->r1) {
        // 0x808002E4: lw          $t0, 0x3C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X3C);
            goto L_808004F0;
    }
    goto skip_6;
    // 0x808002E4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    skip_6:
    // 0x808002E8: jal         0x801022E4
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_16;
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808002F0: addiu       $t0, $v0, -0x229
    ctx->r8 = ADD32(ctx->r2, -0X229);
    // 0x808002F4: sltiu       $at, $t0, 0x6
    ctx->r1 = ctx->r8 < 0X6 ? 1 : 0;
    // 0x808002F8: beq         $at, $zero, L_808004EC
    if (ctx->r1 == 0) {
        // 0x808002FC: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_808004EC;
    }
    // 0x808002FC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80800300: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1560, 0XA70) << 16);
    // 0x80800304: addu        $at, $at, $t0
    gpr jr_addend_8080030C = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80800308: lw          $t0, 0xA70($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1560, 0XA70));
    // 0x8080030C: jr          $t0
    // 0x80800310: nop

    switch (jr_addend_8080030C >> 2) {
        case 0: goto L_80800314; break;
        case 1: goto L_80800378; break;
        case 2: goto L_808003DC; break;
        case 3: goto L_8080040C; break;
        case 4: goto L_808004EC; break;
        case 5: goto L_80800470; break;
        default: switch_error(__func__, 0x8080030C, 0x80800A70);
    }
    // 0x80800310: nop

L_80800314:
    // 0x80800314: lui         $a1, 0x3E93
    ctx->r5 = S32(0X3E93 << 16);
    // 0x80800318: ori         $a1, $a1, 0x74BC
    ctx->r5 = ctx->r5 | 0X74BC;
    // 0x8080031C: jal         0x80101E14
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_17;
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800324: beq         $v0, $zero, L_80800348
    if (ctx->r2 == 0) {
        // 0x80800328: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800348;
    }
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080032C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1560, 0XAC0) << 16);
    // 0x80800330: addiu       $a2, $a2, 0xAC0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1560, 0XAC0));
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800338: jal         0x80089D18
    // 0x8080033C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_18;
    // 0x8080033C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_18:
    // 0x80800340: b           L_808004F0
    // 0x80800344: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
        goto L_808004F0;
    // 0x80800344: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_80800348:
    // 0x80800348: lui         $a1, 0x3F30
    ctx->r5 = S32(0X3F30 << 16);
    // 0x8080034C: jal         0x80101E14
    // 0x80800350: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    func_80101E14(rdram, ctx);
        goto after_19;
    // 0x80800350: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    after_19:
    // 0x80800354: bne         $v0, $zero, L_8080036C
    if (ctx->r2 != 0) {
        // 0x80800358: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080036C;
    }
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080035C: lui         $a1, 0x3F42
    ctx->r5 = S32(0X3F42 << 16);
    // 0x80800360: jal         0x80101E14
    // 0x80800364: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    func_80101E14(rdram, ctx);
        goto after_20;
    // 0x80800364: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    after_20:
    // 0x80800368: beq         $v0, $zero, L_808004EC
    if (ctx->r2 == 0) {
        // 0x8080036C: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_808004EC;
    }
L_8080036C:
    // 0x8080036C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800370: b           L_808004EC
    // 0x80800374: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
        goto L_808004EC;
    // 0x80800374: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
L_80800378:
    // 0x80800378: lui         $a1, 0x3E23
    ctx->r5 = S32(0X3E23 << 16);
    // 0x8080037C: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80800380: jal         0x80101E14
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_21;
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800388: beq         $v0, $zero, L_808003AC
    if (ctx->r2 == 0) {
        // 0x8080038C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003AC;
    }
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800390: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1560, 0XAC0) << 16);
    // 0x80800394: addiu       $a2, $a2, 0xAC0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1560, 0XAC0));
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080039C: jal         0x80089D18
    // 0x808003A0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_22;
    // 0x808003A0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_22:
    // 0x808003A4: b           L_808004F0
    // 0x808003A8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
        goto L_808004F0;
    // 0x808003A8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_808003AC:
    // 0x808003AC: lui         $a1, 0x3F5C
    ctx->r5 = S32(0X3F5C << 16);
    // 0x808003B0: jal         0x80101E14
    // 0x808003B4: ori         $a1, $a1, 0x28F6
    ctx->r5 = ctx->r5 | 0X28F6;
    func_80101E14(rdram, ctx);
        goto after_23;
    // 0x808003B4: ori         $a1, $a1, 0x28F6
    ctx->r5 = ctx->r5 | 0X28F6;
    after_23:
    // 0x808003B8: bne         $v0, $zero, L_808003D0
    if (ctx->r2 != 0) {
        // 0x808003BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003D0;
    }
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C0: lui         $a1, 0x3F7A
    ctx->r5 = S32(0X3F7A << 16);
    // 0x808003C4: jal         0x80101E14
    // 0x808003C8: ori         $a1, $a1, 0xE148
    ctx->r5 = ctx->r5 | 0XE148;
    func_80101E14(rdram, ctx);
        goto after_24;
    // 0x808003C8: ori         $a1, $a1, 0xE148
    ctx->r5 = ctx->r5 | 0XE148;
    after_24:
    // 0x808003CC: beq         $v0, $zero, L_808004EC
    if (ctx->r2 == 0) {
        // 0x808003D0: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_808004EC;
    }
L_808003D0:
    // 0x808003D0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x808003D4: b           L_808004EC
    // 0x808003D8: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
        goto L_808004EC;
    // 0x808003D8: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
L_808003DC:
    // 0x808003DC: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x808003E0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808003E4: jal         0x80101E14
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_25;
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x808003EC: beq         $v0, $zero, L_808004EC
    if (ctx->r2 == 0) {
        // 0x808003F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004EC;
    }
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1560, 0XACC) << 16);
    // 0x808003F8: addiu       $a2, $a2, 0xACC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1560, 0XACC));
    // 0x808003FC: jal         0x80089D18
    // 0x80800400: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_26;
    // 0x80800400: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_26:
    // 0x80800404: b           L_808004F0
    // 0x80800408: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
        goto L_808004F0;
    // 0x80800408: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_8080040C:
    // 0x8080040C: lui         $a1, 0x3EF5
    ctx->r5 = S32(0X3EF5 << 16);
    // 0x80800410: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    // 0x80800414: jal         0x80101E14
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_27;
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x8080041C: beq         $v0, $zero, L_80800440
    if (ctx->r2 == 0) {
        // 0x80800420: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800440;
    }
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800424: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1560, 0XAC0) << 16);
    // 0x80800428: addiu       $a2, $a2, 0xAC0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1560, 0XAC0));
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800430: jal         0x80089D18
    // 0x80800434: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_28;
    // 0x80800434: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_28:
    // 0x80800438: b           L_808004F0
    // 0x8080043C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
        goto L_808004F0;
    // 0x8080043C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_80800440:
    // 0x80800440: lui         $a1, 0x3F36
    ctx->r5 = S32(0X3F36 << 16);
    // 0x80800444: jal         0x80101E14
    // 0x80800448: ori         $a1, $a1, 0xAE7D
    ctx->r5 = ctx->r5 | 0XAE7D;
    func_80101E14(rdram, ctx);
        goto after_29;
    // 0x80800448: ori         $a1, $a1, 0xAE7D
    ctx->r5 = ctx->r5 | 0XAE7D;
    after_29:
    // 0x8080044C: bne         $v0, $zero, L_80800464
    if (ctx->r2 != 0) {
        // 0x80800450: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800464;
    }
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800454: lui         $a1, 0x3F6F
    ctx->r5 = S32(0X3F6F << 16);
    // 0x80800458: jal         0x80101E14
    // 0x8080045C: ori         $a1, $a1, 0x69
    ctx->r5 = ctx->r5 | 0X69;
    func_80101E14(rdram, ctx);
        goto after_30;
    // 0x8080045C: ori         $a1, $a1, 0x69
    ctx->r5 = ctx->r5 | 0X69;
    after_30:
    // 0x80800460: beq         $v0, $zero, L_808004EC
    if (ctx->r2 == 0) {
        // 0x80800464: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_808004EC;
    }
L_80800464:
    // 0x80800464: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800468: b           L_808004EC
    // 0x8080046C: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
        goto L_808004EC;
    // 0x8080046C: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
L_80800470:
    // 0x80800470: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(1560, 0XB5C) << 16);
    // 0x80800474: addiu       $t5, $t5, 0xB5C
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(1560, 0XB5C));
    // 0x80800478: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x8080047C: addiu       $t4, $sp, 0x24
    ctx->r12 = ADD32(ctx->r29, 0X24);
    // 0x80800480: lw          $t8, 0x4($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X4);
    // 0x80800484: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x80800488: lw          $at, 0x8($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X8);
    // 0x8080048C: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x80800490: lw          $t8, 0xC($t5)
    ctx->r24 = MEM_W(ctx->r13, 0XC);
    // 0x80800494: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    // 0x80800498: lw          $at, 0x10($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X10);
    // 0x8080049C: lui         $a1, 0x3D23
    ctx->r5 = S32(0X3D23 << 16);
    // 0x808004A0: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x808004A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A8: sw          $t8, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r24;
    // 0x808004AC: jal         0x80101E14
    // 0x808004B0: sw          $at, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r1;
    func_80101E14(rdram, ctx);
        goto after_31;
    // 0x808004B0: sw          $at, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r1;
    after_31:
    // 0x808004B4: beq         $v0, $zero, L_808004D8
    if (ctx->r2 == 0) {
        // 0x808004B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004D8;
    }
    // 0x808004B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004BC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1560, 0XAC0) << 16);
    // 0x808004C0: addiu       $a2, $a2, 0xAC0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1560, 0XAC0));
    // 0x808004C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C8: jal         0x80089D18
    // 0x808004CC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_32;
    // 0x808004CC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_32:
    // 0x808004D0: b           L_808004F0
    // 0x808004D4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
        goto L_808004F0;
    // 0x808004D4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_808004D8:
    // 0x808004D8: jal         0x80101E4C
    // 0x808004DC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80101E4C(rdram, ctx);
        goto after_33;
    // 0x808004DC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_33:
    // 0x808004E0: beq         $v0, $zero, L_808004EC
    if (ctx->r2 == 0) {
        // 0x808004E4: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_808004EC;
    }
    // 0x808004E4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808004E8: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
L_808004EC:
    // 0x808004EC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_808004F0:
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808004F8: beq         $t0, $zero, L_80800508
    if (ctx->r8 == 0) {
        // 0x808004FC: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1560, 0XADC) << 16);
            goto L_80800508;
    }
    // 0x808004FC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1560, 0XADC) << 16);
    // 0x80800500: jal         0x80089D18
    // 0x80800504: addiu       $a2, $a2, 0xADC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1560, 0XADC));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_34;
    // 0x80800504: addiu       $a2, $a2, 0xADC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1560, 0XADC));
    after_34:
L_80800508:
    // 0x80800508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080050C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800510: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800514: jr          $ra
    // 0x80800518: nop

    return;
    // 0x80800518: nop

;}
RECOMP_FUNC void func_808064DC_inantab(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808064DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808064E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808064E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808064E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808064EC: jal         0x80800020
    // 0x808064F0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80800020_inantab(rdram, ctx);
        goto after_0;
    // 0x808064F0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808064F4: bne         $v0, $zero, L_80806508
    if (ctx->r2 != 0) {
        // 0x808064F8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80806508;
    }
    // 0x808064F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808064FC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80806500: jal         0x808057BC
    // 0x80806504: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_808057BC_inantab(rdram, ctx);
        goto after_1;
    // 0x80806504: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
L_80806508:
    // 0x80806508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080650C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80806510: jr          $ra
    // 0x80806514: nop

    return;
    // 0x80806514: nop

;}
RECOMP_FUNC void func_80102D4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102D4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102D50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102D54: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80102D58: lwc1        $f14, 0x50($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80102D5C: lwc1        $f12, 0x44($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80102D60: jal         0x800F20BC
    // 0x80102D64: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_800F20BC(rdram, ctx);
        goto after_0;
    // 0x80102D64: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_0:
    // 0x80102D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102D6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102D70: jr          $ra
    // 0x80102D74: nop

    return;
    // 0x80102D74: nop

;}
RECOMP_FUNC void func_800D7138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7138: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D713C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D7140: jal         0x800D6254
    // 0x800D7144: nop

    func_800D6254(rdram, ctx);
        goto after_0;
    // 0x800D7144: nop

    after_0:
    // 0x800D7148: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D714C: beq         $v0, $at, L_800D7178
    if (ctx->r2 == ctx->r1) {
        // 0x800D7150: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D7178;
    }
    // 0x800D7150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D7154: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800D7158: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800D715C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800D7160: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D7164: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800D7168: lhu         $v0, -0x47F6($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X47F6);
    // 0x800D716C: srl         $t7, $v0, 12
    ctx->r15 = S32(U32(ctx->r2) >> 12);
    // 0x800D7170: b           L_800D717C
    // 0x800D7174: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_800D717C;
    // 0x800D7174: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800D7178:
    // 0x800D7178: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800D717C:
    // 0x800D717C: jr          $ra
    // 0x800D7180: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800D7180: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80804810_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804810: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80804814: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80804818: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080481C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80804820: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804824: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x80804828: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x8080482C: addiu       $a1, $zero, 0x155
    ctx->r5 = ADD32(0, 0X155);
    // 0x80804830: jal         0x80089C20
    // 0x80804834: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80804834: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_0:
    // 0x80804838: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080483C: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x80804840: bne         $v0, $zero, L_80804884
    if (ctx->r2 != 0) {
        // 0x80804844: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80804884;
    }
    // 0x80804844: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80804848: addiu       $a1, $zero, 0x29E
    ctx->r5 = ADD32(0, 0X29E);
    // 0x8080484C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80804850: jal         0x80089C20
    // 0x80804854: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80804854: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_1:
    // 0x80804858: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080485C: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x80804860: bne         $v0, $zero, L_80804978
    if (ctx->r2 != 0) {
        // 0x80804864: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80804978;
    }
    // 0x80804864: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80804868: addiu       $a1, $zero, 0x1B8
    ctx->r5 = ADD32(0, 0X1B8);
    // 0x8080486C: jal         0x80089C20
    // 0x80804870: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80804870: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_2:
    // 0x80804874: bne         $v0, $zero, L_80804978
    if (ctx->r2 != 0) {
        // 0x80804878: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80804978;
    }
    // 0x80804878: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080487C: b           L_80804B4C
    // 0x80804880: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80804B4C;
    // 0x80804880: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80804884:
    // 0x80804884: lhu         $t6, 0x72($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X72);
    // 0x80804888: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080488C: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80804890: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80804894: bne         $t7, $at, L_808048B0
    if (ctx->r15 != ctx->r1) {
        // 0x80804898: addiu       $a2, $s0, 0x4
        ctx->r6 = ADD32(ctx->r16, 0X4);
            goto L_808048B0;
    }
    // 0x80804898: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x8080489C: jal         0x800F0064
    // 0x808048A0: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_800F0064(rdram, ctx);
        goto after_3;
    // 0x808048A0: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_3:
    // 0x808048A4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808048A8: beq         $v0, $zero, L_808048D4
    if (ctx->r2 == 0) {
        // 0x808048AC: addiu       $a3, $sp, 0x40
        ctx->r7 = ADD32(ctx->r29, 0X40);
            goto L_808048D4;
    }
    // 0x808048AC: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
L_808048B0:
    // 0x808048B0: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808048B4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808048B8: srl         $t8, $v0, 10
    ctx->r24 = S32(U32(ctx->r2) >> 10);
    // 0x808048BC: beq         $t8, $at, L_808048D4
    if (ctx->r24 == ctx->r1) {
        // 0x808048C0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808048D4;
    }
    // 0x808048C0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808048C4: beq         $t8, $at, L_808048D4
    if (ctx->r24 == ctx->r1) {
        // 0x808048C8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808048D4;
    }
    // 0x808048C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808048CC: bnel        $t8, $at, L_8080497C
    if (ctx->r24 != ctx->r1) {
        // 0x808048D0: lhu         $t1, 0x72($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0X72);
            goto L_8080497C;
    }
    goto skip_0;
    // 0x808048D0: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
    skip_0:
L_808048D4:
    // 0x808048D4: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808048D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808048DC: addiu       $a1, $zero, 0x155
    ctx->r5 = ADD32(0, 0X155);
    // 0x808048E0: srl         $t9, $v0, 10
    ctx->r25 = S32(U32(ctx->r2) >> 10);
    // 0x808048E4: beq         $t9, $at, L_80804914
    if (ctx->r25 == ctx->r1) {
        // 0x808048E8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80804914;
    }
    // 0x808048E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808048EC: beq         $t9, $at, L_80804924
    if (ctx->r25 == ctx->r1) {
        // 0x808048F0: addiu       $a1, $zero, 0x155
        ctx->r5 = ADD32(0, 0X155);
            goto L_80804924;
    }
    // 0x808048F0: addiu       $a1, $zero, 0x155
    ctx->r5 = ADD32(0, 0X155);
    // 0x808048F4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808048F8: beq         $t9, $at, L_80804944
    if (ctx->r25 == ctx->r1) {
        // 0x808048FC: addiu       $a1, $zero, 0x155
        ctx->r5 = ADD32(0, 0X155);
            goto L_80804944;
    }
    // 0x808048FC: addiu       $a1, $zero, 0x155
    ctx->r5 = ADD32(0, 0X155);
    // 0x80804900: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80804904: beq         $t9, $at, L_80804934
    if (ctx->r25 == ctx->r1) {
        // 0x80804908: addiu       $a1, $zero, 0x155
        ctx->r5 = ADD32(0, 0X155);
            goto L_80804934;
    }
    // 0x80804908: addiu       $a1, $zero, 0x155
    ctx->r5 = ADD32(0, 0X155);
    // 0x8080490C: b           L_80804950
    // 0x80804910: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
        goto L_80804950;
    // 0x80804910: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
L_80804914:
    // 0x80804914: jal         0x80089C20
    // 0x80804918: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80804918: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x8080491C: b           L_80804950
    // 0x80804920: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80804950;
    // 0x80804920: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80804924:
    // 0x80804924: jal         0x80089C20
    // 0x80804928: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80804928: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_5:
    // 0x8080492C: b           L_80804950
    // 0x80804930: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80804950;
    // 0x80804930: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80804934:
    // 0x80804934: jal         0x80089C20
    // 0x80804938: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x80804938: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_6:
    // 0x8080493C: b           L_80804950
    // 0x80804940: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80804950;
    // 0x80804940: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80804944:
    // 0x80804944: jal         0x80089C20
    // 0x80804948: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x80804948: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_7:
    // 0x8080494C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80804950:
    // 0x80804950: beql        $v1, $zero, L_8080497C
    if (ctx->r3 == 0) {
        // 0x80804954: lhu         $t1, 0x72($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0X72);
            goto L_8080497C;
    }
    goto skip_1;
    // 0x80804954: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
    skip_1:
    // 0x80804958: lhu         $v0, 0x72($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X72);
    // 0x8080495C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80804960: srl         $t0, $v0, 10
    ctx->r8 = S32(U32(ctx->r2) >> 10);
    // 0x80804964: beq         $t0, $at, L_80804974
    if (ctx->r8 == ctx->r1) {
        // 0x80804968: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80804974;
    }
    // 0x80804968: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080496C: bnel        $t0, $at, L_8080497C
    if (ctx->r8 != ctx->r1) {
        // 0x80804970: lhu         $t1, 0x72($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0X72);
            goto L_8080497C;
    }
    goto skip_2;
    // 0x80804970: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
    skip_2:
L_80804974:
    // 0x80804974: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_80804978:
    // 0x80804978: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
L_8080497C:
    // 0x8080497C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80804980: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80804984: srl         $t2, $t1, 10
    ctx->r10 = S32(U32(ctx->r9) >> 10);
    // 0x80804988: bne         $t2, $at, L_80804B3C
    if (ctx->r10 != ctx->r1) {
        // 0x8080498C: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80804B3C;
    }
    // 0x8080498C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80804990: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80804994: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80804998: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8080499C: jal         0x80102D78
    // 0x808049A0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_80102D78(rdram, ctx);
        goto after_8;
    // 0x808049A0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_8:
    // 0x808049A4: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808049A8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808049AC: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x808049B0: jal         0x800136E4
    // 0x808049B4: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    func_800136E4(rdram, ctx);
        goto after_9;
    // 0x808049B4: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_9:
    // 0x808049B8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808049BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808049C0: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808049C4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808049C8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808049CC: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x808049D0: bc1fl       L_80804A00
    if (!c1cs) {
        // 0x808049D4: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_80804A00;
    }
    goto skip_3;
    // 0x808049D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_3:
    // 0x808049D8: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x808049DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808049E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4FAC) << 16);
    // 0x808049E4: lwc1        $f18, 0x4FAC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4FAC));
    // 0x808049E8: lwc1        $f16, 0x50($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X50);
    // 0x808049EC: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808049F0: mul.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808049F4: b           L_80804A60
    // 0x808049F8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
        goto L_80804A60;
    // 0x808049F8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x808049FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_80804A00:
    // 0x80804A00: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80804A04: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80804A08: nop

    // 0x80804A0C: bc1fl       L_80804A3C
    if (!c1cs) {
        // 0x80804A10: lwc1        $f0, 0x50($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
            goto L_80804A3C;
    }
    goto skip_4;
    // 0x80804A10: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    skip_4:
    // 0x80804A14: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x80804A18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80804A1C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4FB0) << 16);
    // 0x80804A20: lwc1        $f16, 0x4FB0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4FB0));
    // 0x80804A24: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80804A28: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80804A2C: mul.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80804A30: b           L_80804A60
    // 0x80804A34: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
        goto L_80804A60;
    // 0x80804A34: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80804A38: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
L_80804A3C:
    // 0x80804A3C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80804A40: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4FB4) << 16);
    // 0x80804A44: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80804A48: nop

    // 0x80804A4C: bc1fl       L_80804A64
    if (!c1cs) {
        // 0x80804A50: lui         $at, 0x41C8
        ctx->r1 = S32(0X41C8 << 16);
            goto L_80804A64;
    }
    goto skip_5;
    // 0x80804A50: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    skip_5:
    // 0x80804A54: lwc1        $f4, 0x4FB4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4FB4));
    // 0x80804A58: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80804A5C: nop

L_80804A60:
    // 0x80804A60: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
L_80804A64:
    // 0x80804A64: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80804A68: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80804A6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80804A70: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80804A74: nop

    // 0x80804A78: bc1fl       L_80804A88
    if (!c1cs) {
        // 0x80804A7C: c.lt.s      $f2, $f6
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
            goto L_80804A88;
    }
    goto skip_6;
    // 0x80804A7C: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    skip_6:
    // 0x80804A80: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80804A84: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
L_80804A88:
    // 0x80804A88: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x80804A8C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80804A90: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80804A94: bc1fl       L_80804B10
    if (!c1cs) {
        // 0x80804A98: lwc1        $f12, 0x38($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
            goto L_80804B10;
    }
    goto skip_7;
    // 0x80804A98: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    skip_7:
    // 0x80804A9C: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x80804AA0: jal         0x80102D78
    // 0x80804AA4: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    func_80102D78(rdram, ctx);
        goto after_10;
    // 0x80804AA4: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    after_10:
    // 0x80804AA8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80804AAC: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    // 0x80804AB0: jal         0x80102CF4
    // 0x80804AB4: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    func_80102CF4(rdram, ctx);
        goto after_11;
    // 0x80804AB4: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    after_11:
    // 0x80804AB8: bne         $v0, $zero, L_80804B0C
    if (ctx->r2 != 0) {
        // 0x80804ABC: lwc1        $f2, 0x34($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
            goto L_80804B0C;
    }
    // 0x80804ABC: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80804AC0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80804AC4: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x80804AC8: jal         0x80102CF4
    // 0x80804ACC: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    func_80102CF4(rdram, ctx);
        goto after_12;
    // 0x80804ACC: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_12:
    // 0x80804AD0: beq         $v0, $zero, L_80804B0C
    if (ctx->r2 == 0) {
        // 0x80804AD4: lwc1        $f2, 0x34($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
            goto L_80804B0C;
    }
    // 0x80804AD4: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80804AD8: jal         0x800DC0C0
    // 0x80804ADC: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_13;
    // 0x80804ADC: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_13:
    // 0x80804AE0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4FB8) << 16);
    // 0x80804AE4: lwc1        $f8, 0x4FB8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4FB8));
    // 0x80804AE8: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80804AEC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80804AF0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80804AF4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80804AF8: bc1fl       L_80804B10
    if (!c1cs) {
        // 0x80804AFC: lwc1        $f12, 0x38($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
            goto L_80804B10;
    }
    goto skip_8;
    // 0x80804AFC: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    skip_8:
    // 0x80804B00: jal         0x80800B4C
    // 0x80804B04: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_14;
    // 0x80804B04: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_14:
    // 0x80804B08: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
L_80804B0C:
    // 0x80804B0C: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
L_80804B10:
    // 0x80804B10: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80804B14: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80804B18: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80804B1C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // 0x80804B20: jal         0x800EFCD8
    // 0x80804B24: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800EFCD8(rdram, ctx);
        goto after_15;
    // 0x80804B24: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_15:
    // 0x80804B28: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80804B2C: jal         0x800EF04C
    // 0x80804B30: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EF04C(rdram, ctx);
        goto after_16;
    // 0x80804B30: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_16:
    // 0x80804B34: b           L_80804B4C
    // 0x80804B38: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80804B4C;
    // 0x80804B38: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80804B3C:
    // 0x80804B3C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // 0x80804B40: jal         0x800EE7F8
    // 0x80804B44: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_17;
    // 0x80804B44: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_17:
    // 0x80804B48: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80804B4C:
    // 0x80804B4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80804B50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804B54: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80804B58: jr          $ra
    // 0x80804B5C: nop

    return;
    // 0x80804B5C: nop

;}
RECOMP_FUNC void bskazhatch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800470: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800474: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(248, 0X4E0) << 16);
    // 0x80800478: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080047C: jr          $ra
    // 0x80800480: lw          $v0, 0x4E0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(248, 0X4E0));
    return;
    // 0x80800480: lw          $v0, 0x4E0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(248, 0X4E0));
;}
RECOMP_FUNC void chpickups_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800054: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(700, 0X988) << 16);
    // 0x80800058: jr          $ra
    // 0x8080005C: addiu       $v0, $v0, 0x988
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0X988));
    return;
    // 0x8080005C: addiu       $v0, $v0, 0x988
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0X988));
;}
RECOMP_FUNC void func_800F77E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F77E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F77EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F77F0: lui         $a3, 0xC4BB
    ctx->r7 = S32(0XC4BB << 16);
    // 0x800F77F4: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x800F77F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800F77FC: jal         0x800F7750
    // 0x800F7800: lui         $a2, 0x4452
    ctx->r6 = S32(0X4452 << 16);
    func_800F7750(rdram, ctx);
        goto after_0;
    // 0x800F7800: lui         $a2, 0x4452
    ctx->r6 = S32(0X4452 << 16);
    after_0:
    // 0x800F7804: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7808: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F780C: jr          $ra
    // 0x800F7810: nop

    return;
    // 0x800F7810: nop

;}
