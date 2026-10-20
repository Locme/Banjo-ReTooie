#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8010DC50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010DC50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010DC54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010DC58: jal         0x80104148
    // 0x8010DC5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80104148(rdram, ctx);
        goto after_0;
    // 0x8010DC5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8010DC60: lbu         $t6, 0x4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4);
    // 0x8010DC64: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8010DC68: addiu       $a0, $v0, 0x2
    ctx->r4 = ADD32(ctx->r2, 0X2);
    // 0x8010DC6C: bnel        $t6, $zero, L_8010DC9C
    if (ctx->r14 != 0) {
        // 0x8010DC70: lbu         $t7, 0x4($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X4);
            goto L_8010DC9C;
    }
    goto skip_0;
    // 0x8010DC70: lbu         $t7, 0x4($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X4);
    skip_0:
    // 0x8010DC74: jal         0x80104268
    // 0x8010DC78: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80104268(rdram, ctx);
        goto after_1;
    // 0x8010DC78: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8010DC7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010DC80: jal         0x8010DAE0
    // 0x8010DC84: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_8010DAE0(rdram, ctx);
        goto after_2;
    // 0x8010DC84: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8010DC88: jal         0x800AE020
    // 0x8010DC8C: nop

    func_800AE020(rdram, ctx);
        goto after_3;
    // 0x8010DC8C: nop

    after_3:
    // 0x8010DC90: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8010DC94: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8010DC98: lbu         $t7, 0x4($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X4);
L_8010DC9C:
    // 0x8010DC9C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8010DCA0: sb          $t8, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r24;
    // 0x8010DCA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010DCA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8010DCAC: jr          $ra
    // 0x8010DCB0: nop

    return;
    // 0x8010DCB0: nop

;}
RECOMP_FUNC void func_808001D0_chmasterjiggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001D4: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(768, 0X1620) << 16);
    // 0x808001D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808001E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808001E4: addiu       $t9, $t9, 0x1620
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(768, 0X1620));
    // 0x808001E8: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x808001EC: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x808001F0: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x808001F4: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x808001F8: addiu       $t0, $zero, 0x97
    ctx->r8 = ADD32(0, 0X97);
    // 0x808001FC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800200: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800204: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800208: jal         0x8008A208
    // 0x8080020C: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x8080020C: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    after_0:
    // 0x80800210: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800214: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800218: jr          $ra
    // 0x8080021C: nop

    return;
    // 0x8080021C: nop

;}
RECOMP_FUNC void _chlinkpipefan_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087428: syscall     570
    recomp_syscall_handler(rdram, ctx, 0x80087428);
    return;
    // 0x8008742C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800970_chprisonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800970: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800978: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080097C: jal         0x80100094
    // 0x80800980: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800980: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800984: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800988: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080098C: jal         0x80100094
    // 0x80800990: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800990: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800994: beq         $v0, $zero, L_808009A4
    if (ctx->r2 == 0) {
        // 0x80800998: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808009A4;
    }
    // 0x80800998: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080099C: jal         0x800897C8
    // 0x808009A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x808009A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_808009A4:
    // 0x808009A4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808009A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808009AC: jal         0x8008A2C0
    // 0x808009B0: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x808009B0: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_3:
    // 0x808009B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808009BC: jr          $ra
    // 0x808009C0: nop

    return;
    // 0x808009C0: nop

;}
RECOMP_FUNC void func_808004F8_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800500: jal         0x80085230
    // 0x80800504: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _basudie_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800504: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800508: jal         0x808000F0
    // 0x8080050C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bsvan_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080050C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800514: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800518: jr          $ra
    // 0x8080051C: nop

    return;
    // 0x8080051C: nop

;}
RECOMP_FUNC void func_80800C6C_chnicecavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C74: jal         0x80800BF8
    // 0x80800C78: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80800BF8_chnicecavemen(rdram, ctx);
        goto after_0;
    // 0x80800C78: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800C7C: beq         $v0, $zero, L_80800CB4
    if (ctx->r2 == 0) {
        // 0x80800C80: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800CB4;
    }
    // 0x80800C80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800C84: jal         0x80102424
    // 0x80800C88: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800C88: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x80800C8C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800C90: addiu       $t7, $zero, 0xA2
    ctx->r15 = ADD32(0, 0XA2);
    // 0x80800C94: addiu       $a1, $zero, 0x17D8
    ctx->r5 = ADD32(0, 0X17D8);
    // 0x80800C98: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80800C9C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800CA0: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800CA4: jal         0x8008A208
    // 0x80800CA8: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80800CA8: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    after_2:
    // 0x80800CAC: b           L_80800CB8
    // 0x80800CB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CB8;
    // 0x80800CB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CB4:
    // 0x80800CB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800CB8:
    // 0x80800CB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800CC0: jr          $ra
    // 0x80800CC4: nop

    return;
    // 0x80800CC4: nop

;}
RECOMP_FUNC void func_800F8E78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8E78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F8E7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8E80: jal         0x800F88A0
    // 0x800F8E84: nop

    func_800F88A0(rdram, ctx);
        goto after_0;
    // 0x800F8E84: nop

    after_0:
    // 0x800F8E88: beq         $v0, $zero, L_800F8EAC
    if (ctx->r2 == 0) {
        // 0x800F8E8C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800F8EAC;
    }
    // 0x800F8E8C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800F8E90: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F8E94: jal         0x800B28E8
    // 0x800F8E98: lw          $a0, 0x54F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X54F0);
    vector_index_of(rdram, ctx);
        goto after_1;
    // 0x800F8E98: lw          $a0, 0x54F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X54F0);
    after_1:
    // 0x800F8E9C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F8EA0: lw          $a0, 0x54F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X54F0);
    // 0x800F8EA4: jal         0x800B2E30
    // 0x800F8EA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    vector_erase(rdram, ctx);
        goto after_2;
    // 0x800F8EA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
L_800F8EAC:
    // 0x800F8EAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8EB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F8EB4: jr          $ra
    // 0x800F8EB8: nop

    return;
    // 0x800F8EB8: nop

;}
RECOMP_FUNC void _bsdronebitten_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083000: syscall     39
    recomp_syscall_handler(rdram, ctx, 0x80083000);
    return;
    // 0x80083004: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800A9AA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9AA4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A9AA8: lbu         $v0, 0x7760($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7760);
    // 0x800A9AAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A9AB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A9AB4: beq         $v0, $at, L_800A9AD0
    if (ctx->r2 == ctx->r1) {
        // 0x800A9AB8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800A9AD0;
    }
    // 0x800A9AB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9ABC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A9AC0: beq         $v0, $at, L_800A9AE0
    if (ctx->r2 == ctx->r1) {
        // 0x800A9AC4: nop
    
            goto L_800A9AE0;
    }
    // 0x800A9AC4: nop

    // 0x800A9AC8: b           L_800A9AEC
    // 0x800A9ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A9AEC;
    // 0x800A9ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A9AD0:
    // 0x800A9AD0: jal         0x800E817C
    // 0x800A9AD4: nop

    func_800E817C(rdram, ctx);
        goto after_0;
    // 0x800A9AD4: nop

    after_0:
    // 0x800A9AD8: b           L_800A9AEC
    // 0x800A9ADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A9AEC;
    // 0x800A9ADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A9AE0:
    // 0x800A9AE0: jal         0x80088C68
    // 0x800A9AE4: nop

    _gsattract_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x800A9AE4: nop

    after_1:
    // 0x800A9AE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A9AEC:
    // 0x800A9AEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A9AF0: jr          $ra
    // 0x800A9AF4: nop

    return;
    // 0x800A9AF4: nop

;}
RECOMP_FUNC void func_808006BC_bskazglide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006C4: jal         0x8009BC6C
    // 0x808006C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baphysics_reset_gravity(rdram, ctx);
        goto after_0;
    // 0x808006C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808006CC: jal         0x8009BC90
    // 0x808006D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_1;
    // 0x808006D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808006D4: jal         0x800832E8
    // 0x808006D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808006D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808006DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006E4: jr          $ra
    // 0x808006E8: nop

    return;
    // 0x808006E8: nop

;}
RECOMP_FUNC void _chtoxicroomprops_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087818: syscall     631
    recomp_syscall_handler(rdram, ctx, 0x80087818);
    return;
    // 0x8008781C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void ch1pfreeze_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "ch1pfreeze_entrypoint_1");
    // 0x808003B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808003B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003BC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808003C0: jal         0x800F5A00
    // 0x808003C4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800F5A00(rdram, ctx);
        goto after_0;
    // 0x808003C4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x808003C8: addiu       $a0, $zero, 0x2C5
    ctx->r4 = ADD32(0, 0X2C5);
    // 0x808003CC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x808003D0: jal         0x80108474
    // 0x808003D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80108474(rdram, ctx);
        goto after_1;
    // 0x808003D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x808003D8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808003DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003E0: jal         0x80100094
    // 0x808003E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808003E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808003E8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808003EC: jal         0x800F5F24
    // 0x808003F0: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    func_800F5F24(rdram, ctx);
        goto after_3;
    // 0x808003F0: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    after_3:
    // 0x808003F4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808003F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808003FC: jal         0x808002D0
    // 0x80800400: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    func_808002D0_ch1pfreeze(rdram, ctx);
        goto after_4;
    // 0x80800400: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    after_4:
    // 0x80800404: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080040C: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80800410: jr          $ra
    // 0x80800414: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800414: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800418: nop

    // 0x8080041C: nop

;}
RECOMP_FUNC void func_80015CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015CE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80015CEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80015CF0: jal         0x80015D14
    // 0x80015CF4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80015D14(rdram, ctx);
        goto after_0;
    // 0x80015CF4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80015CF8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80015CFC: jal         0x800CA510
    // 0x80015D00: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800CA510(rdram, ctx);
        goto after_1;
    // 0x80015D00: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80015D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015D08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80015D0C: jr          $ra
    // 0x80015D10: nop

    return;
    // 0x80015D10: nop

;}
RECOMP_FUNC void _vplight_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089000: syscall     755
    recomp_syscall_handler(rdram, ctx, 0x80089000);
    return;
    // 0x80089004: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _susplinet_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089EB8: syscall     812
    recomp_syscall_handler(rdram, ctx, 0x80089EB8);
    return;
    // 0x80089EBC: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void func_80800A50_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800A54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A60: jal         0x8080081C
    // 0x80800A64: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    bstrexlarge_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800A64: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800A68: jal         0x808004B4
    // 0x80800A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004B4_bstrexlarge(rdram, ctx);
        goto after_1;
    // 0x80800A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800A70: lbu         $v0, 0x15C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15C);
    // 0x80800A74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A7C: beq         $v0, $at, L_80800A94
    if (ctx->r2 == ctx->r1) {
        // 0x80800A80: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800A94;
    }
    // 0x80800A80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A84: beq         $v0, $at, L_80800AB4
    if (ctx->r2 == ctx->r1) {
        // 0x80800A88: nop
    
            goto L_80800AB4;
    }
    // 0x80800A88: nop

    // 0x80800A8C: b           L_80800AFC
    // 0x80800A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800AFC;
    // 0x80800A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800A94:
    // 0x80800A94: jal         0x8008DF8C
    // 0x80800A98: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_2;
    // 0x80800A98: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_2:
    // 0x80800A9C: beq         $v0, $zero, L_80800AF8
    if (ctx->r2 == 0) {
        // 0x80800AA0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AF8;
    }
    // 0x80800AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AA4: jal         0x80800934
    // 0x80800AA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800934_bstrexlarge(rdram, ctx);
        goto after_3;
    // 0x80800AA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800AAC: b           L_80800AFC
    // 0x80800AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800AFC;
    // 0x80800AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800AB4:
    // 0x80800AB4: jal         0x80800044
    // 0x80800AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800044_bstrexlarge(rdram, ctx);
        goto after_4;
    // 0x80800AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800ABC: jal         0x8008E078
    // 0x80800AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_5;
    // 0x80800AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800AC4: bne         $v0, $zero, L_80800ADC
    if (ctx->r2 != 0) {
        // 0x80800AC8: nop
    
            goto L_80800ADC;
    }
    // 0x80800AC8: nop

    // 0x80800ACC: jal         0x80800034
    // 0x80800AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800034_bstrexlarge(rdram, ctx);
        goto after_6;
    // 0x80800AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800AD4: beql        $v0, $zero, L_80800AFC
    if (ctx->r2 == 0) {
        // 0x80800AD8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AFC;
    }
    goto skip_0;
    // 0x80800AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_80800ADC:
    // 0x80800ADC: jal         0x800A2EAC
    // 0x80800AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A2EAC(rdram, ctx);
        goto after_7;
    // 0x80800AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AE8: jal         0x8009B9B0
    // 0x80800AEC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_8;
    // 0x80800AEC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_8:
    // 0x80800AF0: addiu       $t6, $zero, 0x147
    ctx->r14 = ADD32(0, 0X147);
    // 0x80800AF4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800AF8:
    // 0x80800AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800AFC:
    // 0x80800AFC: jal         0x8009E5C8
    // 0x80800B00: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_9;
    // 0x80800B00: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_9:
    // 0x80800B04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800B10: jr          $ra
    // 0x80800B14: nop

    return;
    // 0x80800B14: nop

;}
RECOMP_FUNC void chminelightswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1740, 0XC0) << 16);
    // 0x808000B8: jr          $ra
    // 0x808000BC: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1740, 0XC0));
    return;
    // 0x808000BC: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1740, 0XC0));
;}
RECOMP_FUNC void ncpoddialog_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801094: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801098: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080109C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808010A0: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x808010A4: jal         0x8001B798
    // 0x808010A8: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x808010A8: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    after_0:
    // 0x808010AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808010B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808010B4: jr          $ra
    // 0x808010B8: nop

    return;
    // 0x808010B8: nop

;}
RECOMP_FUNC void func_800EE7F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE7F8: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EE7FC: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800EE800: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EE804: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x800EE808: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EE80C: jr          $ra
    // 0x800EE810: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800EE810: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_800BEC10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEC10: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BEC14: jr          $ra
    // 0x800BEC18: lw          $v0, -0x78D8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X78D8);
    return;
    // 0x800BEC18: lw          $v0, -0x78D8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X78D8);
;}
RECOMP_FUNC void func_800C330C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C330C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C3310: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C3314: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C3318: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C331C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3320: beq         $t6, $zero, L_800C333C
    if (ctx->r14 == 0) {
        // 0x800C3324: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800C333C;
    }
    // 0x800C3324: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C3328: jal         0x800C1414
    // 0x800C332C: nop

    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C332C: nop

    after_0:
    // 0x800C3330: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C3334: jal         0x800C11F8
    // 0x800C3338: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800C11F8(rdram, ctx);
        goto after_1;
    // 0x800C3338: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
L_800C333C:
    // 0x800C333C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3340: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C3344: jr          $ra
    // 0x800C3348: nop

    return;
    // 0x800C3348: nop

;}
RECOMP_FUNC void func_80800208_bscarry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800208: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080020C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800210: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800214: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800218: jal         0x8009E6C4
    // 0x8080021C: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    func_8009E6C4(rdram, ctx);
        goto after_0;
    // 0x8080021C: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_0:
    // 0x80800220: bnel        $v0, $zero, L_8080026C
    if (ctx->r2 != 0) {
        // 0x80800224: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080026C;
    }
    goto skip_0;
    // 0x80800224: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800228: jal         0x8009EFA8
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_pushZone(rdram, ctx);
        goto after_1;
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800230: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x80800234: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: jal         0x8009F1C8
    // 0x80800240: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_2;
    // 0x80800240: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800244: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80800248: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800250: jal         0x8009F1C8
    // 0x80800254: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bastick_setZoneMax(rdram, ctx);
        goto after_3;
    // 0x80800254: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080025C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800260: jal         0x8009F1C8
    // 0x80800264: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_4;
    // 0x80800264: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_4:
    // 0x80800268: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080026C:
    // 0x8080026C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800270: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800274: jr          $ra
    // 0x80800278: nop

    return;
    // 0x80800278: nop

;}
RECOMP_FUNC void func_800B284C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B284C: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x800B2850: bne         $v0, $zero, L_800B2860
    if (ctx->r2 != 0) {
        // 0x800B2854: addu        $v1, $a0, $v0
        ctx->r3 = ADD32(ctx->r4, ctx->r2);
            goto L_800B2860;
    }
    // 0x800B2854: addu        $v1, $a0, $v0
    ctx->r3 = ADD32(ctx->r4, ctx->r2);
    // 0x800B2858: jr          $ra
    // 0x800B285C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B285C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B2860:
    // 0x800B2860: jr          $ra
    // 0x800B2864: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800B2864: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80115828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115828: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8011582C: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x80115830: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80115834: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80115838: swc1        $f12, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f12.u32l;
    // 0x8011583C: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x80115840: swc1        $f14, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f14.u32l;
    // 0x80115844: lw          $t8, 0x3C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X3C);
    // 0x80115848: sb          $v0, 0x11($t8)
    MEM_B(0X11, ctx->r24) = ctx->r2;
    // 0x8011584C: lw          $t9, 0x3C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X3C);
    // 0x80115850: jr          $ra
    // 0x80115854: sb          $v0, 0x12($t9)
    MEM_B(0X12, ctx->r25) = ctx->r2;
    return;
    // 0x80115854: sb          $v0, 0x12($t9)
    MEM_B(0X12, ctx->r25) = ctx->r2;
;}
RECOMP_FUNC void func_80800680_chfriendlystonehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800680: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800684: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800688: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080068C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800690: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800694: jal         0x800C01A8
    // 0x80800698: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    func_800C01A8(rdram, ctx);
        goto after_0;
    // 0x80800698: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    after_0:
    // 0x8080069C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808006A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808006A4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x808006A8: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    // 0x808006AC: jal         0x80085708
    // 0x808006B0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x808006B0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x808006B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006BC: jr          $ra
    // 0x808006C0: nop

    return;
    // 0x808006C0: nop

;}
RECOMP_FUNC void _fxripple_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800889B0: syscall     715
    recomp_syscall_handler(rdram, ctx, 0x800889B0);
    return;
    // 0x800889B4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bacough_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80115478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115478: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x8011547C: jr          $ra
    // 0x80115480: lwc1        $f0, 0x4($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X4);
    return;
    // 0x80115480: lwc1        $f0, 0x4($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X4);
;}
RECOMP_FUNC void _bababykaz_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800844D0: syscall     112
    recomp_syscall_handler(rdram, ctx, 0x800844D0);
    return;
    // 0x800844D4: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void _sueggmisc_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A350: syscall     837
    recomp_syscall_handler(rdram, ctx, 0x8008A350);
    return;
    // 0x8008A354: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800F4A8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4A8C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800F4A90: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F4A94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F4A98: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F4A9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4AA0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F4AA4: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800F4AA8: jal         0x80084860
    // 0x800F4AAC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    _badrone_entrypoint_15(rdram, ctx);
        goto after_0;
    // 0x800F4AAC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F4AB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4AB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F4AB8: jr          $ra
    // 0x800F4ABC: nop

    return;
    // 0x800F4ABC: nop

;}
RECOMP_FUNC void baflameline_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800400: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800404: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800408: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8080040C: jal         0x800EE7F8
    // 0x80800410: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800410: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x80800414: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800418: lw          $a0, 0x84($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X84);
    // 0x8080041C: jal         0x800EF2A0
    // 0x80800420: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EF2A0(rdram, ctx);
        goto after_1;
    // 0x80800420: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_1:
    // 0x80800424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800428: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080042C: jr          $ra
    // 0x80800430: nop

    return;
    // 0x80800430: nop

;}
RECOMP_FUNC void func_80800008_baeggsetup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: jal         0x8009E674
    // 0x80800014: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E674(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080001C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800020: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800024: jr          $ra
    // 0x80800028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void gsmaker_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002AC: jal         0x8080038C
    // 0x808002B0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    gsmaker_entrypoint_13(rdram, ctx);
        goto after_0;
    // 0x808002B0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x808002B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002BC: jr          $ra
    // 0x808002C0: nop

    return;
    // 0x808002C0: nop

;}
RECOMP_FUNC void func_800D0634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0634: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D0638: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D063C: bne         $a1, $at, L_800D0670
    if (ctx->r5 != ctx->r1) {
        // 0x800D0640: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800D0670;
    }
    // 0x800D0640: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D0644: jal         0x800CFC5C
    // 0x800D0648: nop

    func_800CFC5C(rdram, ctx);
        goto after_0;
    // 0x800D0648: nop

    after_0:
    // 0x800D064C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D0650: beq         $v0, $at, L_800D0670
    if (ctx->r2 == ctx->r1) {
        // 0x800D0654: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_800D0670;
    }
    // 0x800D0654: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800D0658: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x800D065C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800D0660: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D0664: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800D0668: b           L_800D0674
    // 0x800D066C: lw          $v0, -0x4E74($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4E74);
        goto L_800D0674;
    // 0x800D066C: lw          $v0, -0x4E74($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4E74);
L_800D0670:
    // 0x800D0670: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D0674:
    // 0x800D0674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D0678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D067C: jr          $ra
    // 0x800D0680: nop

    return;
    // 0x800D0680: nop

;}
RECOMP_FUNC void func_8080050C_chfootwear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080050C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800510: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800514: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800518: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080051C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800520: lhu         $t7, 0x64($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X64);
    // 0x80800524: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80800528: bne         $t8, $zero, L_80800538
    if (ctx->r24 != 0) {
        // 0x8080052C: nop
    
            goto L_80800538;
    }
    // 0x8080052C: nop

    // 0x80800530: b           L_80800634
    // 0x80800534: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800634;
    // 0x80800534: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800538:
    // 0x80800538: jal         0x800F6D24
    // 0x8080053C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800F6D24(rdram, ctx);
        goto after_0;
    // 0x8080053C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x80800540: beq         $v0, $zero, L_80800550
    if (ctx->r2 == 0) {
        // 0x80800544: nop
    
            goto L_80800550;
    }
    // 0x80800544: nop

    // 0x80800548: b           L_80800634
    // 0x8080054C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800634;
    // 0x8080054C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800550:
    // 0x80800550: jal         0x800F65D0
    // 0x80800554: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800F65D0(rdram, ctx);
        goto after_1;
    // 0x80800554: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800558: bne         $v0, $zero, L_80800568
    if (ctx->r2 != 0) {
        // 0x8080055C: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_80800568;
    }
    // 0x8080055C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80800560: b           L_80800634
    // 0x80800564: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800634;
    // 0x80800564: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800568:
    // 0x80800568: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x8080056C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2448, 0X6E0) << 16);
    // 0x80800570: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80800574: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80800578: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8080057C: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x80800580: jal         0x800C6E38
    // 0x80800584: lh          $a0, 0x6E0($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(2448, 0X6E0));
    func_800C6E38(rdram, ctx);
        goto after_2;
    // 0x80800584: lh          $a0, 0x6E0($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(2448, 0X6E0));
    after_2:
    // 0x80800588: bne         $v0, $zero, L_808005D4
    if (ctx->r2 != 0) {
        // 0x8080058C: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_808005D4;
    }
    // 0x8080058C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800590: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80800594: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80800598: beq         $t2, $zero, L_808005CC
    if (ctx->r10 == 0) {
        // 0x8080059C: nop
    
            goto L_808005CC;
    }
    // 0x8080059C: nop

    // 0x808005A0: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x808005A4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2448, 0X6E8) << 16);
    // 0x808005A8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x808005AC: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x808005B0: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x808005B4: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x808005B8: lh          $a0, 0x6E8($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(2448, 0X6E8));
    // 0x808005BC: beq         $a0, $zero, L_808005CC
    if (ctx->r4 == 0) {
        // 0x808005C0: nop
    
            goto L_808005CC;
    }
    // 0x808005C0: nop

    // 0x808005C4: jal         0x8008A298
    // 0x808005C8: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    _sudialog_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808005C8: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_3:
L_808005CC:
    // 0x808005CC: b           L_80800634
    // 0x808005D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800634;
    // 0x808005D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005D4:
    // 0x808005D4: jal         0x800F64A4
    // 0x808005D8: addiu       $a1, $zero, 0x501
    ctx->r5 = ADD32(0, 0X501);
    func_800F64A4(rdram, ctx);
        goto after_4;
    // 0x808005D8: addiu       $a1, $zero, 0x501
    ctx->r5 = ADD32(0, 0X501);
    after_4:
    // 0x808005DC: bne         $v0, $zero, L_808005EC
    if (ctx->r2 != 0) {
        // 0x808005E0: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_808005EC;
    }
    // 0x808005E0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808005E4: b           L_80800634
    // 0x808005E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800634;
    // 0x808005E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005EC:
    // 0x808005EC: beq         $t6, $zero, L_80800630
    if (ctx->r14 == 0) {
        // 0x808005F0: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_80800630;
    }
    // 0x808005F0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808005F4: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x808005F8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2448, 0X6E2) << 16);
    // 0x808005FC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800600: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80800604: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80800608: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8080060C: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x80800610: lh          $a1, 0x6E2($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(2448, 0X6E2));
    // 0x80800614: jal         0x800F7C0C
    // 0x80800618: lw          $a2, 0x50($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X50);
    func_800F7C0C(rdram, ctx);
        goto after_5;
    // 0x80800618: lw          $a2, 0x50($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X50);
    after_5:
    // 0x8080061C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800620: beql        $v0, $at, L_80800634
    if (ctx->r2 == ctx->r1) {
        // 0x80800624: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800634;
    }
    goto skip_0;
    // 0x80800624: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800628: b           L_80800634
    // 0x8080062C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800634;
    // 0x8080062C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800630:
    // 0x80800630: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800634:
    // 0x80800634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800638: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080063C: jr          $ra
    // 0x80800640: nop

    return;
    // 0x80800640: nop

;}
RECOMP_FUNC void func_80800704_ncpoducam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800704: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800708: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080070C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800710: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800714: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800718: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080071C: jal         0x8001B798
    // 0x80800720: lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X0);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x80800720: lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X0);
    after_0:
    // 0x80800724: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80800728: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080072C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800730: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800734: jal         0x80089D90
    // 0x80800738: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _suspline_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800738: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080073C: jal         0x8080021C
    // 0x80800740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080021C_ncpoducam(rdram, ctx);
        goto after_2;
    // 0x80800740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800744: bne         $v0, $zero, L_80800764
    if (ctx->r2 != 0) {
        // 0x80800748: addiu       $a0, $s0, 0x3C
        ctx->r4 = ADD32(ctx->r16, 0X3C);
            goto L_80800764;
    }
    // 0x80800748: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x8080074C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800750: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800754: jal         0x80089D90
    // 0x80800758: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    _suspline_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800758: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    after_3:
    // 0x8080075C: b           L_80800788
    // 0x80800760: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_80800788;
    // 0x80800760: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800764:
    // 0x80800764: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800768: jal         0x800F18FC
    // 0x8080076C: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    func_800F18FC(rdram, ctx);
        goto after_4;
    // 0x8080076C: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    after_4:
    // 0x80800770: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80800774: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800778: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8080077C: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x80800780: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x80800784: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800788:
    // 0x80800788: jal         0x80089D98
    // 0x8080078C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _suspline_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x8080078C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800790: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80800794: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800798: jal         0x80089D98
    // 0x8080079C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suspline_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x8080079C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808007A0: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808007A4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x808007A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808007AC: bnel        $t6, $zero, L_808007C0
    if (ctx->r14 != 0) {
        // 0x808007B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808007C0;
    }
    goto skip_0;
    // 0x808007B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808007B4: jal         0x80089DA0
    // 0x808007B8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _suspline_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x808007B8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x808007BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007C0:
    // 0x808007C0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808007C4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808007C8: jr          $ra
    // 0x808007CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808007CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void baanim_playForDuration_loopSmooth(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CB3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008CB40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008CB44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008CB48: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8008CB4C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8008CB50: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8008CB54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008CB58: jal         0x8008AF24
    // 0x8008CB5C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    anctrl_reset(rdram, ctx);
        goto after_0;
    // 0x8008CB5C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x8008CB60: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8008CB64: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8008CB68: jal         0x8008AED4
    // 0x8008CB6C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    anctrl_setIndex(rdram, ctx);
        goto after_1;
    // 0x8008CB6C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_1:
    // 0x8008CB70: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8008CB74: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8008CB78: jal         0x8008B1BC
    // 0x8008CB7C: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    anctrl_setDuration(rdram, ctx);
        goto after_2;
    // 0x8008CB7C: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_2:
    // 0x8008CB80: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8008CB84: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8008CB88: jal         0x8008B134
    // 0x8008CB8C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_3;
    // 0x8008CB8C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_3:
    // 0x8008CB90: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x8008CB94: jal         0x8008B064
    // 0x8008CB98: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    anctrl_start(rdram, ctx);
        goto after_4;
    // 0x8008CB98: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_4:
    // 0x8008CB9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008CBA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008CBA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008CBA8: jr          $ra
    // 0x8008CBAC: nop

    return;
    // 0x8008CBAC: nop

;}
RECOMP_FUNC void _subaddiepalette_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A070: syscall     825
    recomp_syscall_handler(rdram, ctx, 0x8008A070);
    return;
    // 0x8008A074: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800200_chprisonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800200: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800208: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080020C: jal         0x8080005C
    // 0x80800210: addiu       $a2, $zero, 0xAF
    ctx->r6 = ADD32(0, 0XAF);
    func_8080005C_chprisonbits(rdram, ctx);
        goto after_0;
    // 0x80800210: addiu       $a2, $zero, 0xAF
    ctx->r6 = ADD32(0, 0XAF);
    after_0:
    // 0x80800214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800218: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080021C: jr          $ra
    // 0x80800220: nop

    return;
    // 0x80800220: nop

;}
RECOMP_FUNC void chblink_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080004C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800050: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800054: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800058: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080005C: jal         0x8001B668
    // 0x80800060: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    func_8001B668(rdram, ctx);
        goto after_0;
    // 0x80800060: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_0:
    // 0x80800064: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x80800068: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8080006C: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x80800070: jal         0x8001B798
    // 0x80800074: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_8001B798(rdram, ctx);
        goto after_1;
    // 0x80800074: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x80800078: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8080007C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800080: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800084: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800088: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8080008C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800090: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
L_80800094:
    // 0x80800094: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800098: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8080009C: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x808000A0: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x808000A4: bne         $a0, $a1, L_80800094
    if (ctx->r4 != ctx->r5) {
        // 0x808000A8: swc1        $f0, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f0.u32l;
            goto L_80800094;
    }
    // 0x808000A8: swc1        $f0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f0.u32l;
    // 0x808000AC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808000B0: jal         0x80800000
    // 0x808000B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    chblink_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808000B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x808000B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000BC: lh          $v0, 0x1E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X1E);
    // 0x808000C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000C4: jr          $ra
    // 0x808000C8: nop

    return;
    // 0x808000C8: nop

;}
RECOMP_FUNC void func_80802444_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802444: lw          $v1, 0x188($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X188);
    // 0x80802448: lw          $v0, 0xA0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XA0);
    // 0x8080244C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80802450: jr          $ra
    // 0x80802454: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    return;
    // 0x80802454: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_800F9F74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9F74: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F9F78: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F9F7C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800F9F80: jr          $ra
    // 0x800F9F84: sh          $a1, 0x5532($at)
    MEM_H(0X5532, ctx->r1) = ctx->r5;
    return;
    // 0x800F9F84: sh          $a1, 0x5532($at)
    MEM_H(0X5532, ctx->r1) = ctx->r5;
    // 0x800F9F88: nop

    // 0x800F9F8C: nop

;}
RECOMP_FUNC void ncbaclimb_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800094: jr          $ra
    // 0x80800098: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800098: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _chbounce_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800858D8: syscall     180
    recomp_syscall_handler(rdram, ctx, 0x800858D8);
    return;
    // 0x800858DC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8080130C_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080130C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801310: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801314: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80801318: jal         0x80086C68
    // 0x8080131C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _chmumbopad_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080131C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80801320: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x80801324: sra         $t6, $a3, 16
    ctx->r14 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80801328: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x8080132C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80801330: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801334: jal         0x80089840
    // 0x80801338: addiu       $a2, $zero, 0x41
    ctx->r6 = ADD32(0, 0X41);
    _sumumbofx_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80801338: addiu       $a2, $zero, 0x41
    ctx->r6 = ADD32(0, 0X41);
    after_1:
    // 0x8080133C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80801340: jal         0x80100094
    // 0x80801344: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80801344: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80801348: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8080134C: jal         0x80089850
    // 0x80801350: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80801350: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80801354: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80801358: jal         0x80089900
    // 0x8080135C: lui         $a1, 0x4010
    ctx->r5 = S32(0X4010 << 16);
    _sumumbofx_entrypoint_24(rdram, ctx);
        goto after_4;
    // 0x8080135C: lui         $a1, 0x4010
    ctx->r5 = S32(0X4010 << 16);
    after_4:
    // 0x80801360: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80801364: jal         0x800898B8
    // 0x80801368: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_15(rdram, ctx);
        goto after_5;
    // 0x80801368: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_5:
    // 0x8080136C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1700, 0X2568) << 16);
    // 0x80801370: addiu       $t7, $t7, 0x2568
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1700, 0X2568));
    // 0x80801374: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80801378: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x8080137C: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1700, 0X2570) << 16);
    // 0x80801380: sw          $at, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r1;
    // 0x80801384: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80801388: addiu       $t1, $t1, 0x2570
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1700, 0X2570));
    // 0x8080138C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80801390: sw          $t0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r8;
    // 0x80801394: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x80801398: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(1700, 0X257C) << 16);
    // 0x8080139C: addiu       $t5, $t5, 0x257C
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(1700, 0X257C));
    // 0x808013A0: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x808013A4: lw          $t4, 0x4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X4);
    // 0x808013A8: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    // 0x808013AC: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x808013B0: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x808013B4: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x808013B8: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x808013BC: sw          $at, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r1;
    // 0x808013C0: lw          $t8, 0x4($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X4);
    // 0x808013C4: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x808013C8: lw          $at, 0x8($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X8);
    // 0x808013CC: sw          $at, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r1;
    // 0x808013D0: jal         0x800898A0
    // 0x808013D4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    _sumumbofx_entrypoint_12(rdram, ctx);
        goto after_6;
    // 0x808013D4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_6:
    // 0x808013D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808013DC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808013E0: jr          $ra
    // 0x808013E4: nop

    return;
    // 0x808013E4: nop

;}
RECOMP_FUNC void func_80800148_bsdronegoto(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800148: jr          $ra
    // 0x8080014C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080014C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _subaddiemarker_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A0C0: syscall     827
    recomp_syscall_handler(rdram, ctx, 0x8008A0C0);
    return;
    // 0x8008A0C4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80090080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090088: jal         0x800F54E4
    // 0x8009008C: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8009008C: nop

    after_0:
    // 0x80090090: jal         0x800F5FA8
    // 0x80090094: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5FA8(rdram, ctx);
        goto after_1;
    // 0x80090094: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80090098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009009C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800900A0: jr          $ra
    // 0x800900A4: nop

    return;
    // 0x800900A4: nop

;}
RECOMP_FUNC void _chfactorylinkgrill_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087558: syscall     587
    recomp_syscall_handler(rdram, ctx, 0x80087558);
    return;
    // 0x8008755C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
