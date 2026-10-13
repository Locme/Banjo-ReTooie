#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808008D4_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808008D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808008E0: jal         0x80100094
    // 0x808008E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808008E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808008E8: lw          $a0, 0x94($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X94);
    // 0x808008EC: beql        $a0, $zero, L_80800938
    if (ctx->r4 == 0) {
        // 0x808008F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800938;
    }
    goto skip_0;
    // 0x808008F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808008F4: jal         0x80087CD0
    // 0x808008F8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    _gcnewoption_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x808008F8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x808008FC: jal         0x8001B084
    // 0x80800900: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    heap_free(rdram, ctx);
        goto after_2;
    // 0x80800900: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800904: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800908: jal         0x80100094
    // 0x8080090C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x8080090C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800910: sw          $zero, 0x94($v0)
    MEM_W(0X94, ctx->r2) = 0;
    // 0x80800914: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800918: jal         0x80100094
    // 0x8080091C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x8080091C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800920: sb          $zero, 0x98($v0)
    MEM_B(0X98, ctx->r2) = 0;
    // 0x80800924: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800928: jal         0x80100094
    // 0x8080092C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x8080092C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800930: sb          $zero, 0x99($v0)
    MEM_B(0X99, ctx->r2) = 0;
    // 0x80800934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800938:
    // 0x80800938: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080093C: jr          $ra
    // 0x80800940: nop

    return;
    // 0x80800940: nop

;}
RECOMP_FUNC void _bsbeefly_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082858: syscall     16
    recomp_syscall_handler(rdram, ctx, 0x80082858);
    return;
    // 0x8008285C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8080023C_chlagoonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080023C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800240: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800244: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80800248: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x8080024C: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x80800250: addiu       $t9, $t8, -0x366
    ctx->r25 = ADD32(ctx->r24, -0X366);
    // 0x80800254: sltiu       $at, $t9, 0x8
    ctx->r1 = ctx->r25 < 0X8 ? 1 : 0;
    // 0x80800258: beq         $at, $zero, L_808002BC
    if (ctx->r1 == 0) {
        // 0x8080025C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_808002BC;
    }
    // 0x8080025C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800260: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1052, 0X7B0) << 16);
    // 0x80800264: addu        $at, $at, $t9
    gpr jr_addend_8080026C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800268: lw          $t9, 0x7B0($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1052, 0X7B0));
    // 0x8080026C: jr          $t9
    // 0x80800270: nop

    switch (jr_addend_8080026C >> 2) {
        case 0: goto L_80800274; break;
        case 1: goto L_80800284; break;
        case 2: goto L_80800284; break;
        case 3: goto L_80800294; break;
        case 4: goto L_808002BC; break;
        case 5: goto L_808002BC; break;
        case 6: goto L_808002A4; break;
        case 7: goto L_808002B4; break;
        default: switch_error(__func__, 0x8080026C, 0x808007B0);
    }
    // 0x80800270: nop

L_80800274:
    // 0x80800274: jal         0x808002CC
    // 0x80800278: nop

    func_808002CC_chlagoonbits(rdram, ctx);
        goto after_0;
    // 0x80800278: nop

    after_0:
    // 0x8080027C: b           L_808002C0
    // 0x80800280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002C0;
    // 0x80800280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800284:
    // 0x80800284: jal         0x80800360
    // 0x80800288: nop

    func_80800360_chlagoonbits(rdram, ctx);
        goto after_1;
    // 0x80800288: nop

    after_1:
    // 0x8080028C: b           L_808002C0
    // 0x80800290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002C0;
    // 0x80800290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800294:
    // 0x80800294: jal         0x8080041C
    // 0x80800298: nop

    func_8080041C_chlagoonbits(rdram, ctx);
        goto after_2;
    // 0x80800298: nop

    after_2:
    // 0x8080029C: b           L_808002C0
    // 0x808002A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002C0;
    // 0x808002A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002A4:
    // 0x808002A4: jal         0x808004B0
    // 0x808002A8: nop

    func_808004B0_chlagoonbits(rdram, ctx);
        goto after_3;
    // 0x808002A8: nop

    after_3:
    // 0x808002AC: b           L_808002C0
    // 0x808002B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002C0;
    // 0x808002B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002B4:
    // 0x808002B4: jal         0x80800548
    // 0x808002B8: nop

    func_80800548_chlagoonbits(rdram, ctx);
        goto after_4;
    // 0x808002B8: nop

    after_4:
L_808002BC:
    // 0x808002BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002C0:
    // 0x808002C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002C4: jr          $ra
    // 0x808002C8: nop

    return;
    // 0x808002C8: nop

;}
RECOMP_FUNC void func_800F9BC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9BC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F9BC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F9BCC: jal         0x800F8B88
    // 0x800F9BD0: nop

    func_800F8B88(rdram, ctx);
        goto after_0;
    // 0x800F9BD0: nop

    after_0:
    // 0x800F9BD4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800F9BD8: bnel        $v0, $at, L_800F9C2C
    if (ctx->r2 != ctx->r1) {
        // 0x800F9BDC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F9C2C;
    }
    goto skip_0;
    // 0x800F9BDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800F9BE0: jal         0x800DB9B0
    // 0x800F9BE4: nop

    func_800DB9B0(rdram, ctx);
        goto after_1;
    // 0x800F9BE4: nop

    after_1:
    // 0x800F9BE8: bne         $v0, $zero, L_800F9C28
    if (ctx->r2 != 0) {
        // 0x800F9BEC: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800F9C28;
    }
    // 0x800F9BEC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F9BF0: lbu         $t6, 0x5520($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X5520);
    // 0x800F9BF4: addiu       $t7, $t6, -0xD
    ctx->r15 = ADD32(ctx->r14, -0XD);
    // 0x800F9BF8: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x800F9BFC: beq         $at, $zero, L_800F9C18
    if (ctx->r1 == 0) {
        // 0x800F9C00: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800F9C18;
    }
    // 0x800F9C00: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800F9C04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800F9C08: addu        $at, $at, $t7
    gpr jr_addend_800F9C10 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800F9C0C: lw          $t7, 0x60D4($at)
    ctx->r15 = ADD32(ctx->r1, 0X60D4);
    // 0x800F9C10: jr          $t7
    // 0x800F9C14: nop

    switch (jr_addend_800F9C10 >> 2) {
        case 0: goto L_800F9C28; break;
        case 1: goto L_800F9C28; break;
        case 2: goto L_800F9C28; break;
        case 3: goto L_800F9C28; break;
        case 4: goto L_800F9C28; break;
        case 5: goto L_800F9C28; break;
        case 6: goto L_800F9C28; break;
        default: switch_error(__func__, 0x800F9C10, 0x801260D4);
    }
    // 0x800F9C14: nop

L_800F9C18:
    // 0x800F9C18: jal         0x800BEAF4
    // 0x800F9C1C: nop

    func_800BEAF4(rdram, ctx);
        goto after_2;
    // 0x800F9C1C: nop

    after_2:
    // 0x800F9C20: jal         0x800F9488
    // 0x800F9C24: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    func_800F9488(rdram, ctx);
        goto after_3;
    // 0x800F9C24: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_3:
L_800F9C28:
    // 0x800F9C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9C2C:
    // 0x800F9C2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F9C30: jr          $ra
    // 0x800F9C34: nop

    return;
    // 0x800F9C34: nop

;}
RECOMP_FUNC void func_8009C0BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C0BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C0C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C0C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009C0C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8009C0CC: jal         0x800EE7F8
    // 0x8009C0D0: lw          $a0, 0xE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8009C0D0: lw          $a0, 0xE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE4);
    after_0:
    // 0x8009C0D4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8009C0D8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8009C0DC: lw          $a0, 0xE4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XE4);
    // 0x8009C0E0: jal         0x800EE7F8
    // 0x8009C0E4: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8009C0E4: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_1:
    // 0x8009C0E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C0EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C0F0: jr          $ra
    // 0x8009C0F4: nop

    return;
    // 0x8009C0F4: nop

;}
RECOMP_FUNC void func_8009C0F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C0F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C0FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C100: jal         0x800EE7F8
    // 0x8009C104: lw          $a0, 0xE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8009C104: lw          $a0, 0xE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE4);
    after_0:
    // 0x8009C108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C10C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C110: jr          $ra
    // 0x8009C114: nop

    return;
    // 0x8009C114: nop

;}
RECOMP_FUNC void func_800A4338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4338: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800A433C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A4340: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A4344: jal         0x80090E24
    // 0x800A4348: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80090E24(rdram, ctx);
        goto after_0;
    // 0x800A4348: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800A434C: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x800A4350: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x800A4354: jal         0x80090E30
    // 0x800A4358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80090E30(rdram, ctx);
        goto after_1;
    // 0x800A4358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800A435C: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x800A4360: jal         0x800A5854
    // 0x800A4364: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    func_800A5854(rdram, ctx);
        goto after_2;
    // 0x800A4364: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    after_2:
    // 0x800A4368: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x800A436C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A4370: beq         $a0, $at, L_800A43A8
    if (ctx->r4 == ctx->r1) {
        // 0x800A4374: nop
    
            goto L_800A43A8;
    }
    // 0x800A4374: nop

    // 0x800A4378: jal         0x800A5904
    // 0x800A437C: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    func_800A5904(rdram, ctx);
        goto after_3;
    // 0x800A437C: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    after_3:
    // 0x800A4380: beq         $v0, $zero, L_800A43A8
    if (ctx->r2 == 0) {
        // 0x800A4384: lw          $v1, 0x60($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X60);
            goto L_800A43A8;
    }
    // 0x800A4384: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x800A4388: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x800A438C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A4390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A4394: lbu         $t7, 0x38($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X38);
    // 0x800A4398: beq         $t7, $zero, L_800A44E0
    if (ctx->r15 == 0) {
        // 0x800A439C: nop
    
            goto L_800A44E0;
    }
    // 0x800A439C: nop

    // 0x800A43A0: beq         $v1, $at, L_800A44E0
    if (ctx->r3 == ctx->r1) {
        // 0x800A43A4: nop
    
            goto L_800A44E0;
    }
    // 0x800A43A4: nop

L_800A43A8:
    // 0x800A43A8: jal         0x800A5B9C
    // 0x800A43AC: nop

    func_800A5B9C(rdram, ctx);
        goto after_4;
    // 0x800A43AC: nop

    after_4:
    // 0x800A43B0: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x800A43B4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800A43B8: sb          $v0, 0x4($t8)
    MEM_B(0X4, ctx->r24) = ctx->r2;
    // 0x800A43BC: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x800A43C0: lbu         $t9, 0x4($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X4);
    // 0x800A43C4: bne         $t9, $at, L_800A43D4
    if (ctx->r25 != ctx->r1) {
        // 0x800A43C8: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800A43D4;
    }
    // 0x800A43C8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800A43CC: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    // 0x800A43D0: sb          $zero, 0x4($v1)
    MEM_B(0X4, ctx->r3) = 0;
L_800A43D4:
    // 0x800A43D4: jal         0x800A5B7C
    // 0x800A43D8: nop

    func_800A5B7C(rdram, ctx);
        goto after_5;
    // 0x800A43D8: nop

    after_5:
    // 0x800A43DC: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x800A43E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A43E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A43E8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800A43EC: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x800A43F0: jal         0x800A3DB8
    // 0x800A43F4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800A3DB8(rdram, ctx);
        goto after_6;
    // 0x800A43F4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_6:
    // 0x800A43F8: jal         0x800A5BBC
    // 0x800A43FC: nop

    func_800A5BBC(rdram, ctx);
        goto after_7;
    // 0x800A43FC: nop

    after_7:
    // 0x800A4400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A4404: jal         0x800A3EC8
    // 0x800A4408: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800A3EC8(rdram, ctx);
        goto after_8;
    // 0x800A4408: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x800A440C: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x800A4410: lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X4);
    // 0x800A4414: beq         $v0, $zero, L_800A4430
    if (ctx->r2 == 0) {
        // 0x800A4418: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A4430;
    }
    // 0x800A4418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A441C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800A4420: jal         0x800A3D78
    // 0x800A4424: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    func_800A3D78(rdram, ctx);
        goto after_9;
    // 0x800A4424: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    after_9:
    // 0x800A4428: b           L_800A446C
    // 0x800A442C: nop

        goto L_800A446C;
    // 0x800A442C: nop

L_800A4430:
    // 0x800A4430: lbu         $t2, 0x38($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X38);
    // 0x800A4434: beq         $t2, $zero, L_800A446C
    if (ctx->r10 == 0) {
        // 0x800A4438: nop
    
            goto L_800A446C;
    }
    // 0x800A4438: nop

    // 0x800A443C: lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X3);
    // 0x800A4440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A4444: beq         $v0, $zero, L_800A445C
    if (ctx->r2 == 0) {
        // 0x800A4448: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800A445C;
    }
    // 0x800A4448: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800A444C: jal         0x800A3D78
    // 0x800A4450: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    func_800A3D78(rdram, ctx);
        goto after_10;
    // 0x800A4450: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    after_10:
    // 0x800A4454: b           L_800A446C
    // 0x800A4458: nop

        goto L_800A446C;
    // 0x800A4458: nop

L_800A445C:
    // 0x800A445C: jal         0x800A4CA8
    // 0x800A4460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_11;
    // 0x800A4460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x800A4464: jal         0x80110F44
    // 0x800A4468: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110F44(rdram, ctx);
        goto after_12;
    // 0x800A4468: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_12:
L_800A446C:
    // 0x800A446C: jal         0x800A5BAC
    // 0x800A4470: nop

    func_800A5BAC(rdram, ctx);
        goto after_13;
    // 0x800A4470: nop

    after_13:
    // 0x800A4474: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x800A4478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A447C: jal         0x800A4CA8
    // 0x800A4480: sb          $v0, 0x5($t3)
    MEM_B(0X5, ctx->r11) = ctx->r2;
    func_800A4CA8(rdram, ctx);
        goto after_14;
    // 0x800A4480: sb          $v0, 0x5($t3)
    MEM_B(0X5, ctx->r11) = ctx->r2;
    after_14:
    // 0x800A4484: jal         0x800A5BCC
    // 0x800A4488: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    func_800A5BCC(rdram, ctx);
        goto after_15;
    // 0x800A4488: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_15:
    // 0x800A448C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800A4490: jal         0x80110D80
    // 0x800A4494: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80110D80(rdram, ctx);
        goto after_16;
    // 0x800A4494: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_16:
    // 0x800A4498: jal         0x800A4CA8
    // 0x800A449C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_17;
    // 0x800A449C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x800A44A0: jal         0x800A5B6C
    // 0x800A44A4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    func_800A5B6C(rdram, ctx);
        goto after_18;
    // 0x800A44A4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_18:
    // 0x800A44A8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800A44AC: jal         0x80110D28
    // 0x800A44B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80110D28(rdram, ctx);
        goto after_19;
    // 0x800A44B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_19:
    // 0x800A44B4: jal         0x800A4CA8
    // 0x800A44B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_20;
    // 0x800A44B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x800A44BC: jal         0x800A5B8C
    // 0x800A44C0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_800A5B8C(rdram, ctx);
        goto after_21;
    // 0x800A44C0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_21:
    // 0x800A44C4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800A44C8: jal         0x80110D58
    // 0x800A44CC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_80110D58(rdram, ctx);
        goto after_22;
    // 0x800A44CC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_22:
    // 0x800A44D0: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x800A44D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A44D8: b           L_800A4864
    // 0x800A44DC: sb          $zero, 0x38($t4)
    MEM_B(0X38, ctx->r12) = 0;
        goto L_800A4864;
    // 0x800A44DC: sb          $zero, 0x38($t4)
    MEM_B(0X38, ctx->r12) = 0;
L_800A44E0:
    // 0x800A44E0: jal         0x8009E6F8
    // 0x800A44E4: sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    bs_getCurrentState(rdram, ctx);
        goto after_23;
    // 0x800A44E4: sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    after_23:
    // 0x800A44E8: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x800A44EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800A44F0: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x800A44F4: sltiu       $at, $t5, 0x7
    ctx->r1 = ctx->r13 < 0X7 ? 1 : 0;
    // 0x800A44F8: beq         $at, $zero, L_800A4860
    if (ctx->r1 == 0) {
        // 0x800A44FC: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_800A4860;
    }
    // 0x800A44FC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A4500: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A4504: addu        $at, $at, $t5
    gpr jr_addend_800A450C = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800A4508: lw          $t5, 0x5570($at)
    ctx->r13 = ADD32(ctx->r1, 0X5570);
    // 0x800A450C: jr          $t5
    // 0x800A4510: nop

    switch (jr_addend_800A450C >> 2) {
        case 0: goto L_800A4748; break;
        case 1: goto L_800A47BC; break;
        case 2: goto L_800A46D4; break;
        case 3: goto L_800A4514; break;
        case 4: goto L_800A4860; break;
        case 5: goto L_800A4860; break;
        case 6: goto L_800A4824; break;
        default: switch_error(__func__, 0x800A450C, 0x80125570);
    }
    // 0x800A4510: nop

L_800A4514:
    // 0x800A4514: jal         0x800A5800
    // 0x800A4518: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    func_800A5800(rdram, ctx);
        goto after_24;
    // 0x800A4518: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    after_24:
    // 0x800A451C: jal         0x80085650
    // 0x800A4520: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    _cadbfunc_entrypoint_26(rdram, ctx);
        goto after_25;
    // 0x800A4520: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    after_25:
    // 0x800A4524: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x800A4528: bnel        $t6, $zero, L_800A4564
    if (ctx->r14 != 0) {
        // 0x800A452C: lw          $t9, 0x84($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X84);
            goto L_800A4564;
    }
    goto skip_0;
    // 0x800A452C: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    skip_0:
    // 0x800A4530: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x800A4534: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x800A4538: lbu         $v0, 0x38($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X38);
    // 0x800A453C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800A4540: beql        $v0, $zero, L_800A4564
    if (ctx->r2 == 0) {
        // 0x800A4544: lw          $t9, 0x84($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X84);
            goto L_800A4564;
    }
    goto skip_1;
    // 0x800A4544: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    skip_1:
    // 0x800A4548: beql        $t8, $v0, L_800A4564
    if (ctx->r24 == ctx->r2) {
        // 0x800A454C: lw          $t9, 0x84($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X84);
            goto L_800A4564;
    }
    goto skip_2;
    // 0x800A454C: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    skip_2:
    // 0x800A4550: lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X3);
    // 0x800A4554: beql        $v0, $zero, L_800A4564
    if (ctx->r2 == 0) {
        // 0x800A4558: lw          $t9, 0x84($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X84);
            goto L_800A4564;
    }
    goto skip_3;
    // 0x800A4558: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    skip_3:
    // 0x800A455C: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x800A4560: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
L_800A4564:
    // 0x800A4564: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x800A4568: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800A456C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800A4570: bne         $t1, $at, L_800A4584
    if (ctx->r9 != ctx->r1) {
        // 0x800A4574: sw          $t0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r8;
            goto L_800A4584;
    }
    // 0x800A4574: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800A4578: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800A457C: sw          $t2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r10;
    // 0x800A4580: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
L_800A4584:
    // 0x800A4584: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x800A4588: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x800A458C: bnel        $t3, $zero, L_800A45B4
    if (ctx->r11 != 0) {
        // 0x800A4590: lbu         $t6, 0x38($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X38);
            goto L_800A45B4;
    }
    goto skip_4;
    // 0x800A4590: lbu         $t6, 0x38($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X38);
    skip_4:
    // 0x800A4594: lbu         $t4, 0x2($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X2);
    // 0x800A4598: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A459C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800A45A0: bnel        $t4, $at, L_800A45B4
    if (ctx->r12 != ctx->r1) {
        // 0x800A45A4: lbu         $t6, 0x38($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X38);
            goto L_800A45B4;
    }
    goto skip_5;
    // 0x800A45A4: lbu         $t6, 0x38($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X38);
    skip_5:
    // 0x800A45A8: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x800A45AC: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x800A45B0: lbu         $t6, 0x38($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X38);
L_800A45B4:
    // 0x800A45B4: bne         $t6, $zero, L_800A45EC
    if (ctx->r14 != 0) {
        // 0x800A45B8: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_800A45EC;
    }
    // 0x800A45B8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800A45BC: jal         0x80085668
    // 0x800A45C0: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    _cadbfunc_entrypoint_29(rdram, ctx);
        goto after_26;
    // 0x800A45C0: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    after_26:
    // 0x800A45C4: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x800A45C8: beql        $t7, $zero, L_800A45E8
    if (ctx->r15 == 0) {
        // 0x800A45CC: lw          $t9, 0x38($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X38);
            goto L_800A45E8;
    }
    goto skip_6;
    // 0x800A45CC: lw          $t9, 0x38($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X38);
    skip_6:
    // 0x800A45D0: jal         0x800A3DAC
    // 0x800A45D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3DAC(rdram, ctx);
        goto after_27;
    // 0x800A45D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x800A45D8: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x800A45DC: b           L_800A45EC
    // 0x800A45E0: sb          $v0, 0x3($t8)
    MEM_B(0X3, ctx->r24) = ctx->r2;
        goto L_800A45EC;
    // 0x800A45E0: sb          $v0, 0x3($t8)
    MEM_B(0X3, ctx->r24) = ctx->r2;
    // 0x800A45E4: lw          $t9, 0x38($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X38);
L_800A45E8:
    // 0x800A45E8: sb          $zero, 0x3($t9)
    MEM_B(0X3, ctx->r25) = 0;
L_800A45EC:
    // 0x800A45EC: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x800A45F0: beq         $t0, $zero, L_800A4604
    if (ctx->r8 == 0) {
        // 0x800A45F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A4604;
    }
    // 0x800A45F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A45F8: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x800A45FC: jal         0x800A3D78
    // 0x800A4600: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800A3D78(rdram, ctx);
        goto after_28;
    // 0x800A4600: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_28:
L_800A4604:
    // 0x800A4604: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x800A4608: lw          $t2, 0x38($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X38);
    // 0x800A460C: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x800A4610: jal         0x80085630
    // 0x800A4614: sb          $t1, 0x4($t2)
    MEM_B(0X4, ctx->r10) = ctx->r9;
    _cadbfunc_entrypoint_22(rdram, ctx);
        goto after_29;
    // 0x800A4614: sb          $t1, 0x4($t2)
    MEM_B(0X4, ctx->r10) = ctx->r9;
    after_29:
    // 0x800A4618: jal         0x80085640
    // 0x800A461C: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    _cadbfunc_entrypoint_24(rdram, ctx);
        goto after_30;
    // 0x800A461C: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    after_30:
    // 0x800A4620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A4624: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800A4628: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x800A462C: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x800A4630: jal         0x800A3DB8
    // 0x800A4634: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800A3DB8(rdram, ctx);
        goto after_31;
    // 0x800A4634: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_31:
    // 0x800A4638: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x800A463C: jal         0x80085668
    // 0x800A4640: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    _cadbfunc_entrypoint_29(rdram, ctx);
        goto after_32;
    // 0x800A4640: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    after_32:
    // 0x800A4644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A4648: jal         0x800A3EC8
    // 0x800A464C: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    func_800A3EC8(rdram, ctx);
        goto after_33;
    // 0x800A464C: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    after_33:
    // 0x800A4650: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x800A4654: jal         0x80085668
    // 0x800A4658: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    _cadbfunc_entrypoint_29(rdram, ctx);
        goto after_34;
    // 0x800A4658: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    after_34:
    // 0x800A465C: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x800A4660: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x800A4664: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x800A4668: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x800A466C: jal         0x80085668
    // 0x800A4670: sb          $t3, 0x5($t4)
    MEM_B(0X5, ctx->r12) = ctx->r11;
    _cadbfunc_entrypoint_29(rdram, ctx);
        goto after_35;
    // 0x800A4670: sb          $t3, 0x5($t4)
    MEM_B(0X5, ctx->r12) = ctx->r11;
    after_35:
    // 0x800A4674: jal         0x800A4CA8
    // 0x800A4678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_36;
    // 0x800A4678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x800A467C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A4680: jal         0x80110D80
    // 0x800A4684: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    func_80110D80(rdram, ctx);
        goto after_37;
    // 0x800A4684: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    after_37:
    // 0x800A4688: jal         0x80085690
    // 0x800A468C: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    _cadbfunc_entrypoint_34(rdram, ctx);
        goto after_38;
    // 0x800A468C: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    after_38:
    // 0x800A4690: jal         0x800A4CA8
    // 0x800A4694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_39;
    // 0x800A4694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x800A4698: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A469C: jal         0x80110D28
    // 0x800A46A0: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    func_80110D28(rdram, ctx);
        goto after_40;
    // 0x800A46A0: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    after_40:
    // 0x800A46A4: jal         0x80085680
    // 0x800A46A8: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    _cadbfunc_entrypoint_32(rdram, ctx);
        goto after_41;
    // 0x800A46A8: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    after_41:
    // 0x800A46AC: jal         0x800A4CA8
    // 0x800A46B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_42;
    // 0x800A46B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x800A46B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A46B8: jal         0x80110D58
    // 0x800A46BC: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    func_80110D58(rdram, ctx);
        goto after_43;
    // 0x800A46BC: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_43:
    // 0x800A46C0: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800A46C4: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x800A46C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A46CC: b           L_800A4864
    // 0x800A46D0: sb          $t5, 0x38($t6)
    MEM_B(0X38, ctx->r14) = ctx->r13;
        goto L_800A4864;
    // 0x800A46D0: sb          $t5, 0x38($t6)
    MEM_B(0X38, ctx->r14) = ctx->r13;
L_800A46D4:
    // 0x800A46D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A46D8: jal         0x8009CA70
    // 0x800A46DC: addiu       $a2, $zero, 0x4000
    ctx->r6 = ADD32(0, 0X4000);
    func_8009CA70(rdram, ctx);
        goto after_44;
    // 0x800A46DC: addiu       $a2, $zero, 0x4000
    ctx->r6 = ADD32(0, 0X4000);
    after_44:
    // 0x800A46E0: beql        $v0, $zero, L_800A4718
    if (ctx->r2 == 0) {
        // 0x800A46E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A4718;
    }
    goto skip_7;
    // 0x800A46E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_7:
    // 0x800A46E8: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x800A46EC: jal         0x800A5800
    // 0x800A46F0: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    func_800A5800(rdram, ctx);
        goto after_45;
    // 0x800A46F0: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    after_45:
    // 0x800A46F4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800A46F8: jal         0x80085668
    // 0x800A46FC: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    _cadbfunc_entrypoint_29(rdram, ctx);
        goto after_46;
    // 0x800A46FC: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_46:
    // 0x800A4700: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x800A4704: bnel        $t7, $zero, L_800A4718
    if (ctx->r15 != 0) {
        // 0x800A4708: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A4718;
    }
    goto skip_8;
    // 0x800A4708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_8:
    // 0x800A470C: b           L_800A4864
    // 0x800A4710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A4864;
    // 0x800A4710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A4714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800A4718:
    // 0x800A4718: jal         0x800A3B78
    // 0x800A471C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_800A3B78(rdram, ctx);
        goto after_47;
    // 0x800A471C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_47:
    // 0x800A4720: jal         0x800A4CA8
    // 0x800A4724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_48;
    // 0x800A4724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x800A4728: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A472C: jal         0x80089378
    // 0x800A4730: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    _ncbadolly_entrypoint_4(rdram, ctx);
        goto after_49;
    // 0x800A4730: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    after_49:
    // 0x800A4734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A4738: jal         0x800A3F14
    // 0x800A473C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800A3F14(rdram, ctx);
        goto after_50;
    // 0x800A473C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_50:
    // 0x800A4740: b           L_800A4864
    // 0x800A4744: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A4864;
    // 0x800A4744: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A4748:
    // 0x800A4748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A474C: jal         0x8009CA70
    // 0x800A4750: addiu       $a2, $zero, 0x4000
    ctx->r6 = ADD32(0, 0X4000);
    func_8009CA70(rdram, ctx);
        goto after_51;
    // 0x800A4750: addiu       $a2, $zero, 0x4000
    ctx->r6 = ADD32(0, 0X4000);
    after_51:
    // 0x800A4754: beql        $v0, $zero, L_800A478C
    if (ctx->r2 == 0) {
        // 0x800A4758: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A478C;
    }
    goto skip_9;
    // 0x800A4758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_9:
    // 0x800A475C: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x800A4760: jal         0x800A5800
    // 0x800A4764: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    func_800A5800(rdram, ctx);
        goto after_52;
    // 0x800A4764: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    after_52:
    // 0x800A4768: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800A476C: jal         0x80085668
    // 0x800A4770: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    _cadbfunc_entrypoint_29(rdram, ctx);
        goto after_53;
    // 0x800A4770: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_53:
    // 0x800A4774: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800A4778: bnel        $t8, $zero, L_800A478C
    if (ctx->r24 != 0) {
        // 0x800A477C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A478C;
    }
    goto skip_10;
    // 0x800A477C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_10:
    // 0x800A4780: b           L_800A4864
    // 0x800A4784: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A4864;
    // 0x800A4784: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A4788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800A478C:
    // 0x800A478C: jal         0x800A3B78
    // 0x800A4790: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800A3B78(rdram, ctx);
        goto after_54;
    // 0x800A4790: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_54:
    // 0x800A4794: jal         0x800A4CA8
    // 0x800A4798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_55;
    // 0x800A4798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_55:
    // 0x800A479C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A47A0: jal         0x80089350
    // 0x800A47A4: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    _ncbafixpos_entrypoint_4(rdram, ctx);
        goto after_56;
    // 0x800A47A4: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    after_56:
    // 0x800A47A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A47AC: jal         0x800A3F14
    // 0x800A47B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800A3F14(rdram, ctx);
        goto after_57;
    // 0x800A47B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_57:
    // 0x800A47B4: b           L_800A4864
    // 0x800A47B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A4864;
    // 0x800A47B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A47BC:
    // 0x800A47BC: lw          $t9, 0x38($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X38);
    // 0x800A47C0: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x800A47C4: lh          $t0, 0x36($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X36);
    // 0x800A47C8: beq         $a0, $t0, L_800A481C
    if (ctx->r4 == ctx->r8) {
        // 0x800A47CC: nop
    
            goto L_800A481C;
    }
    // 0x800A47CC: nop

    // 0x800A47D0: jal         0x800A5800
    // 0x800A47D4: nop

    func_800A5800(rdram, ctx);
        goto after_58;
    // 0x800A47D4: nop

    after_58:
    // 0x800A47D8: jal         0x80085580
    // 0x800A47DC: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    _cadbfunc_entrypoint_0(rdram, ctx);
        goto after_59;
    // 0x800A47DC: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_59:
    // 0x800A47E0: jal         0x80085590
    // 0x800A47E4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    _cadbfunc_entrypoint_2(rdram, ctx);
        goto after_60;
    // 0x800A47E4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_60:
    // 0x800A47E8: jal         0x800A4C48
    // 0x800A47EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4C48(rdram, ctx);
        goto after_61;
    // 0x800A47EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_61:
    // 0x800A47F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A47F4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x800A47F8: jal         0x800CA628
    // 0x800A47FC: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_800CA628(rdram, ctx);
        goto after_62;
    // 0x800A47FC: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_62:
    // 0x800A4800: jal         0x800A4CA8
    // 0x800A4804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_63;
    // 0x800A4804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_63:
    // 0x800A4808: jal         0x801108A0
    // 0x800A480C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_801108A0(rdram, ctx);
        goto after_64;
    // 0x800A480C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_64:
    // 0x800A4810: lw          $t1, 0x84($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X84);
    // 0x800A4814: lw          $t2, 0x38($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X38);
    // 0x800A4818: sh          $t1, 0x36($t2)
    MEM_H(0X36, ctx->r10) = ctx->r9;
L_800A481C:
    // 0x800A481C: b           L_800A4864
    // 0x800A4820: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A4864;
    // 0x800A4820: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A4824:
    // 0x800A4824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A4828: jal         0x800A3B78
    // 0x800A482C: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_800A3B78(rdram, ctx);
        goto after_65;
    // 0x800A482C: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_65:
    // 0x800A4830: jal         0x800A4CA8
    // 0x800A4834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_66;
    // 0x800A4834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_66:
    // 0x800A4838: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A483C: jal         0x80089198
    // 0x800A4840: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    _ncbaspiral_entrypoint_5(rdram, ctx);
        goto after_67;
    // 0x800A4840: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    after_67:
    // 0x800A4844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A4848: jal         0x800A3F14
    // 0x800A484C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800A3F14(rdram, ctx);
        goto after_68;
    // 0x800A484C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_68:
    // 0x800A4850: jal         0x800A4190
    // 0x800A4854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4190(rdram, ctx);
        goto after_69;
    // 0x800A4854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_69:
    // 0x800A4858: b           L_800A4864
    // 0x800A485C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A4864;
    // 0x800A485C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A4860:
    // 0x800A4860: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A4864:
    // 0x800A4864: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A4868: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A486C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x800A4870: jr          $ra
    // 0x800A4874: nop

    return;
    // 0x800A4874: nop

;}
RECOMP_FUNC void func_800CEA38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEA38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CEA3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CEA40: jal         0x800CE3E0
    // 0x800CEA44: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800CE3E0(rdram, ctx);
        goto after_0;
    // 0x800CEA44: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800CEA48: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800CEA4C: sb          $t6, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r14;
    // 0x800CEA50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CEA54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CEA58: jr          $ra
    // 0x800CEA5C: nop

    return;
    // 0x800CEA5C: nop

;}
RECOMP_FUNC void func_80026AA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026AA4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80026AA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026AAC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80026AB0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80026AB4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80026AB8: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80026ABC: lw          $t6, 0x11F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11F4);
    // 0x80026AC0: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80026AC4: beq         $t7, $zero, L_80026AFC
    if (ctx->r15 == 0) {
        // 0x80026AC8: sw          $t7, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r15;
            goto L_80026AFC;
    }
    // 0x80026AC8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80026ACC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80026AD0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80026AD4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80026AD8: jal         0x80020E74
    // 0x80026ADC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80020E74(rdram, ctx);
        goto after_0;
    // 0x80026ADC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x80026AE0: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80026AE4: lw          $a1, 0x11F4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X11F4);
    // 0x80026AE8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80026AEC: jal         0x80020E40
    // 0x80026AF0: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_80020E40(rdram, ctx);
        goto after_1;
    // 0x80026AF0: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_1:
    // 0x80026AF4: b           L_80026BB8
    // 0x80026AF8: nop

        goto L_80026BB8;
    // 0x80026AF8: nop

L_80026AFC:
    // 0x80026AFC: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80026B00: lw          $t0, 0x11F4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X11F4);
    // 0x80026B04: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80026B08: beq         $t1, $zero, L_80026B40
    if (ctx->r9 == 0) {
        // 0x80026B0C: sw          $t1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r9;
            goto L_80026B40;
    }
    // 0x80026B0C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80026B10: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80026B14: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80026B18: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80026B1C: jal         0x80020E74
    // 0x80026B20: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80020E74(rdram, ctx);
        goto after_2;
    // 0x80026B20: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80026B24: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80026B28: lw          $a1, 0x11F4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X11F4);
    // 0x80026B2C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80026B30: jal         0x80020E40
    // 0x80026B34: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_80020E40(rdram, ctx);
        goto after_3;
    // 0x80026B34: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_3:
    // 0x80026B38: b           L_80026BB8
    // 0x80026B3C: nop

        goto L_80026BB8;
    // 0x80026B3C: nop

L_80026B40:
    // 0x80026B40: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80026B44: lw          $t4, 0x11F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X11F4);
    // 0x80026B48: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x80026B4C: beq         $t5, $zero, L_80026BB8
    if (ctx->r13 == 0) {
        // 0x80026B50: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_80026BB8;
    }
    // 0x80026B50: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_80026B54:
    // 0x80026B54: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80026B58: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80026B5C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80026B60: lh          $t0, 0x2E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2E);
    // 0x80026B64: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x80026B68: lh          $t9, 0x16($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X16);
    // 0x80026B6C: slt         $at, $t0, $t9
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80026B70: bne         $at, $zero, L_80026BA8
    if (ctx->r1 != 0) {
        // 0x80026B74: nop
    
            goto L_80026BA8;
    }
    // 0x80026B74: nop

    // 0x80026B78: lw          $t1, 0x88($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X88);
    // 0x80026B7C: bne         $t1, $zero, L_80026BA8
    if (ctx->r9 != 0) {
        // 0x80026B80: nop
    
            goto L_80026BA8;
    }
    // 0x80026B80: nop

    // 0x80026B84: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80026B88: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80026B8C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80026B90: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80026B94: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x80026B98: lh          $t6, 0x16($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X16);
    // 0x80026B9C: sh          $t6, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r14;
    // 0x80026BA0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80026BA4: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_80026BA8:
    // 0x80026BA8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80026BAC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80026BB0: bne         $t0, $zero, L_80026B54
    if (ctx->r8 != 0) {
        // 0x80026BB4: sw          $t0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r8;
            goto L_80026B54;
    }
    // 0x80026BB4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_80026BB8:
    // 0x80026BB8: b           L_80026BC8
    // 0x80026BBC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_80026BC8;
    // 0x80026BBC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80026BC0: b           L_80026BC8
    // 0x80026BC4: nop

        goto L_80026BC8;
    // 0x80026BC4: nop

L_80026BC8:
    // 0x80026BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026BCC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80026BD0: jr          $ra
    // 0x80026BD4: nop

    return;
    // 0x80026BD4: nop

    // 0x80026BD8: nop

    // 0x80026BDC: nop

;}
RECOMP_FUNC void func_8001E010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E010: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001E014: lbu         $t6, -0x2488($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X2488);
    // 0x8001E018: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E01C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E020: beq         $t6, $zero, L_8001E038
    if (ctx->r14 == 0) {
        // 0x8001E024: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_8001E038;
    }
    // 0x8001E024: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001E028: addiu       $a0, $a0, -0x2768
    ctx->r4 = ADD32(ctx->r4, -0X2768);
    // 0x8001E02C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001E030: jal         0x8002EAD0
    // 0x8001E034: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8001E034: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
L_8001E038:
    // 0x8001E038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E03C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E040: jr          $ra
    // 0x8001E044: nop

    return;
    // 0x8001E044: nop

;}
RECOMP_FUNC void _chicekey_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087788: syscall     621
    recomp_syscall_handler(rdram, ctx, 0x80087788);
    return;
    // 0x8008778C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chalienbeam_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1368, 0X1A0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1368, 0X1A0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1368, 0X1A0));
;}
RECOMP_FUNC void bsmum_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DAC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800DB0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(308, 0X1190) << 16);
    // 0x80800DB4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800DB8: jr          $ra
    // 0x80800DBC: lw          $v0, 0x1190($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(308, 0X1190));
    return;
    // 0x80800DBC: lw          $v0, 0x1190($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(308, 0X1190));
;}
RECOMP_FUNC void func_808000E0_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808000E4: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x808000E8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x808000EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X7014) << 16);
    // 0x808000F0: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808000F4: jr          $ra
    // 0x808000F8: lwc1        $f0, 0x7014($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X7014));
    return;
    // 0x808000F8: lwc1        $f0, 0x7014($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X7014));
;}
RECOMP_FUNC void _bsbtrot_entrypoint_46(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082D30: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082D30);
    return;
    // 0x80082D34: addi        $t0, $zero, 0xB8
    ctx->r8 = ADD32(0, 0XB8);
;}
RECOMP_FUNC void func_80800A78_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A80: lbu         $t6, 0x15D($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X15D);
    // 0x80800A84: beql        $t6, $zero, L_80800A98
    if (ctx->r14 == 0) {
        // 0x80800A88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800A98;
    }
    goto skip_0;
    // 0x80800A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800A8C: jal         0x80800400
    // 0x80800A90: sb          $zero, 0x15D($a0)
    MEM_B(0X15D, ctx->r4) = 0;
    func_80800400_bsbansack(rdram, ctx);
        goto after_0;
    // 0x80800A90: sb          $zero, 0x15D($a0)
    MEM_B(0X15D, ctx->r4) = 0;
    after_0:
    // 0x80800A94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A98:
    // 0x80800A98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A9C: jr          $ra
    // 0x80800AA0: nop

    return;
    // 0x80800AA0: nop

;}
RECOMP_FUNC void ncba1p_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x54
    ctx->r2 = ADD32(0, 0X54);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x54
    ctx->r2 = ADD32(0, 0X54);
;}
RECOMP_FUNC void chrainbow_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AF8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800AFC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800B00: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80800B04: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80800B08: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80800B0C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80800B10: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80800B14: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80800B18: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800B1C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800B20: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800B24: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80800B28: jal         0x80106790
    // 0x80800B2C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800B2C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_0:
    // 0x80800B30: lui         $at, 0xC548
    ctx->r1 = S32(0XC548 << 16);
    // 0x80800B34: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800B38: lui         $at, 0x4548
    ctx->r1 = S32(0X4548 << 16);
    // 0x80800B3C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800B40: lui         $at, 0x4158
    ctx->r1 = S32(0X4158 << 16);
    // 0x80800B44: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800B48: lwc1        $f12, 0x58($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80800B4C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800B50: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800B54: lui         $a2, 0x4190
    ctx->r6 = S32(0X4190 << 16);
    // 0x80800B58: jal         0x800F10B4
    // 0x80800B5C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800B5C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_1:
    // 0x80800B60: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80800B64: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800B68: lwc1        $f12, 0x58($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X58);
    // 0x80800B6C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800B70: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80800B74: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x80800B78: jal         0x800F10B4
    // 0x80800B7C: lui         $a2, 0x4194
    ctx->r6 = S32(0X4194 << 16);
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80800B7C: lui         $a2, 0x4194
    ctx->r6 = S32(0X4194 << 16);
    after_2:
    // 0x80800B80: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80800B84: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800B88: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80800B8C: addu        $s2, $t7, $s0
    ctx->r18 = ADD32(ctx->r15, ctx->r16);
    // 0x80800B90: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x80800B94: beql        $at, $zero, L_80800CB4
    if (ctx->r1 == 0) {
        // 0x80800B98: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80800CB4;
    }
    goto skip_0;
    // 0x80800B98: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x80800B9C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80800BA0: nop

L_80800BA4:
    // 0x80800BA4: lh          $t8, 0x0($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X0);
    // 0x80800BA8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80800BAC: nop

    // 0x80800BB0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800BB4: c.lt.s      $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl < ctx->f20.fl;
    // 0x80800BB8: nop

    // 0x80800BBC: bc1fl       L_80800BD4
    if (!c1cs) {
        // 0x80800BC0: c.lt.s      $f12, $f22
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f12.fl < ctx->f22.fl;
            goto L_80800BD4;
    }
    goto skip_1;
    // 0x80800BC0: c.lt.s      $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f12.fl < ctx->f22.fl;
    skip_1:
    // 0x80800BC4: lbu         $t9, 0xF($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0XF);
    // 0x80800BC8: b           L_80800CA0
    // 0x80800BCC: sb          $t9, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r25;
        goto L_80800CA0;
    // 0x80800BCC: sb          $t9, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r25;
    // 0x80800BD0: c.lt.s      $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f12.fl < ctx->f22.fl;
L_80800BD4:
    // 0x80800BD4: nop

    // 0x80800BD8: bc1fl       L_80800CA0
    if (!c1cs) {
        // 0x80800BDC: sb          $zero, 0xF($s0)
        MEM_B(0XF, ctx->r16) = 0;
            goto L_80800CA0;
    }
    goto skip_2;
    // 0x80800BDC: sb          $zero, 0xF($s0)
    MEM_B(0XF, ctx->r16) = 0;
    skip_2:
    // 0x80800BE0: lbu         $t0, 0xF($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0XF);
    // 0x80800BE4: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80800BE8: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80800BEC: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80800BF0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800BF4: bgez        $t0, L_80800C08
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800BF8: cvt.s.w     $f6, $f6
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80800C08;
    }
    // 0x80800BF8: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800BFC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800C00: nop

    // 0x80800C04: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80800C08:
    // 0x80800C08: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80800C0C: jal         0x800F10B4
    // 0x80800C10: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80800C10: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_3:
    // 0x80800C14: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80800C18: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800C1C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80800C20: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800C24: cvt.w.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80800C28: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80800C2C: nop

    // 0x80800C30: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80800C34: beql        $t2, $zero, L_80800C84
    if (ctx->r10 == 0) {
        // 0x80800C38: mfc1        $t2, $f10
        ctx->r10 = (int32_t)ctx->f10.u32l;
            goto L_80800C84;
    }
    goto skip_3;
    // 0x80800C38: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    skip_3:
    // 0x80800C3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800C40: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800C44: sub.s       $f10, $f0, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80800C48: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80800C4C: nop

    // 0x80800C50: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80800C54: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80800C58: nop

    // 0x80800C5C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80800C60: bne         $t2, $zero, L_80800C78
    if (ctx->r10 != 0) {
        // 0x80800C64: nop
    
            goto L_80800C78;
    }
    // 0x80800C64: nop

    // 0x80800C68: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80800C6C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800C70: b           L_80800C90
    // 0x80800C74: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80800C90;
    // 0x80800C74: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80800C78:
    // 0x80800C78: b           L_80800C90
    // 0x80800C7C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80800C90;
    // 0x80800C7C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80800C80: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
L_80800C84:
    // 0x80800C84: nop

    // 0x80800C88: bltz        $t2, L_80800C78
    if (SIGNED(ctx->r10) < 0) {
        // 0x80800C8C: nop
    
            goto L_80800C78;
    }
    // 0x80800C8C: nop

L_80800C90:
    // 0x80800C90: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80800C94: b           L_80800CA0
    // 0x80800C98: sb          $t2, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r10;
        goto L_80800CA0;
    // 0x80800C98: sb          $t2, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r10;
    // 0x80800C9C: sb          $zero, 0xF($s0)
    MEM_B(0XF, ctx->r16) = 0;
L_80800CA0:
    // 0x80800CA0: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80800CA4: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x80800CA8: bne         $at, $zero, L_80800BA4
    if (ctx->r1 != 0) {
        // 0x80800CAC: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_80800BA4;
    }
    // 0x80800CAC: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80800CB0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80800CB4:
    // 0x80800CB4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800CB8: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800CBC: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80800CC0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80800CC4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80800CC8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80800CCC: jr          $ra
    // 0x80800CD0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800CD0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void __osIdCheckSum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034A84: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x80034A88: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x80034A8C: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80034A90: addiu       $a3, $a0, 0x4
    ctx->r7 = ADD32(ctx->r4, 0X4);
    // 0x80034A94: addiu       $t1, $a3, 0x2
    ctx->r9 = ADD32(ctx->r7, 0X2);
    // 0x80034A98: addu        $t8, $zero, $v0
    ctx->r24 = ADD32(0, ctx->r2);
    // 0x80034A9C: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80034AA0: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x80034AA4: nor         $t5, $v0, $zero
    ctx->r13 = ~(ctx->r2 | 0);
    // 0x80034AA8: addiu       $t2, $a3, 0x4
    ctx->r10 = ADD32(ctx->r7, 0X4);
    // 0x80034AAC: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x80034AB0: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x80034AB4: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x80034AB8: lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2);
    // 0x80034ABC: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80034AC0: addiu       $t3, $a3, 0x6
    ctx->r11 = ADD32(ctx->r7, 0X6);
    // 0x80034AC4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80034AC8: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80034ACC: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x80034AD0: nor         $t5, $v0, $zero
    ctx->r13 = ~(ctx->r2 | 0);
    // 0x80034AD4: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x80034AD8: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x80034ADC: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
L_80034AE0:
    // 0x80034AE0: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
    // 0x80034AE4: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x80034AE8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80034AEC: nor         $t5, $v0, $zero
    ctx->r13 = ~(ctx->r2 | 0);
    // 0x80034AF0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80034AF4: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80034AF8: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x80034AFC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80034B00: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80034B04: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x80034B08: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x80034B0C: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x80034B10: lhu         $v0, -0x8($t1)
    ctx->r2 = MEM_HU(ctx->r9, -0X8);
    // 0x80034B14: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x80034B18: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x80034B1C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80034B20: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80034B24: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x80034B28: nor         $t5, $v0, $zero
    ctx->r13 = ~(ctx->r2 | 0);
    // 0x80034B2C: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x80034B30: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x80034B34: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x80034B38: lhu         $v0, -0x8($t2)
    ctx->r2 = MEM_HU(ctx->r10, -0X8);
    // 0x80034B3C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80034B40: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80034B44: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x80034B48: nor         $t5, $v0, $zero
    ctx->r13 = ~(ctx->r2 | 0);
    // 0x80034B4C: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x80034B50: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x80034B54: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x80034B58: lhu         $v0, -0x8($t3)
    ctx->r2 = MEM_HU(ctx->r11, -0X8);
    // 0x80034B5C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80034B60: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80034B64: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x80034B68: nor         $t5, $v0, $zero
    ctx->r13 = ~(ctx->r2 | 0);
    // 0x80034B6C: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x80034B70: bne         $v1, $a0, L_80034AE0
    if (ctx->r3 != ctx->r4) {
        // 0x80034B74: sh          $t6, 0x0($a2)
        MEM_H(0X0, ctx->r6) = ctx->r14;
            goto L_80034AE0;
    }
    // 0x80034B74: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x80034B78: jr          $ra
    // 0x80034B7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80034B7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80800DE0_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800DE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DE8: jal         0x800C4B64
    // 0x80800DEC: nop

    func_800C4B64(rdram, ctx);
        goto after_0;
    // 0x80800DEC: nop

    after_0:
    // 0x80800DF0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2658, 0X21C0) << 16);
    // 0x80800DF4: addiu       $a1, $a1, 0x21C0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2658, 0X21C0));
    // 0x80800DF8: jal         0x800C4AF0
    // 0x80800DFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C4AF0(rdram, ctx);
        goto after_1;
    // 0x80800DFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80800E00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E08: jr          $ra
    // 0x80800E0C: nop

    return;
    // 0x80800E0C: nop

;}
RECOMP_FUNC void func_80800370_chcauldronentrydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800370: jr          $ra
    // 0x80800374: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800374: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800D7708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7708: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D770C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D7710: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800D7714: jal         0x800D7520
    // 0x800D7718: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800D7520(rdram, ctx);
        goto after_0;
    // 0x800D7718: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800D771C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D7720: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800D7724: jal         0x800C7AE4
    // 0x800D7728: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800C7AE4(rdram, ctx);
        goto after_1;
    // 0x800D7728: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x800D772C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800D7730: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800D7734: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D7738: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800D773C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D7740: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D7744: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D7748: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800D774C: jr          $ra
    // 0x800D7750: div.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    return;
    // 0x800D7750: div.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
;}
RECOMP_FUNC void _bsdronefired_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800830B8: syscall     42
    recomp_syscall_handler(rdram, ctx, 0x800830B8);
    return;
    // 0x800830BC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80098590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098590: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80098594: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80098598: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009859C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800985A0: jal         0x800EE7F8
    // 0x800985A4: lw          $a1, 0xE0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XE0);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800985A4: lw          $a1, 0xE0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XE0);
    after_0:
    // 0x800985A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800985AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800985B0: jr          $ra
    // 0x800985B4: nop

    return;
    // 0x800985B4: nop

;}
RECOMP_FUNC void func_800C7500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7500: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C7504: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C7508: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800C750C: addiu       $s1, $s1, -0x5760
    ctx->r17 = ADD32(ctx->r17, -0X5760);
    // 0x800C7510: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C7514: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C7518: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800C751C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
L_800C7520:
    // 0x800C7520: beql        $t6, $zero, L_800C7540
    if (ctx->r14 == 0) {
        // 0x800C7524: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_800C7540;
    }
    goto skip_0;
    // 0x800C7524: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    skip_0:
    // 0x800C7528: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x800C752C: beql        $v0, $zero, L_800C7540
    if (ctx->r2 == 0) {
        // 0x800C7530: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_800C7540;
    }
    goto skip_1;
    // 0x800C7530: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    skip_1:
    // 0x800C7534: jalr        $v0
    // 0x800C7538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800C7538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800C753C: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
L_800C7540:
    // 0x800C7540: addiu       $t7, $s1, 0x64
    ctx->r15 = ADD32(ctx->r17, 0X64);
    // 0x800C7544: bnel        $s0, $t7, L_800C7520
    if (ctx->r16 != ctx->r15) {
        // 0x800C7548: lw          $t6, 0x4($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X4);
            goto L_800C7520;
    }
    goto skip_2;
    // 0x800C7548: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    skip_2:
    // 0x800C754C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C7550: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C7554: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800C7558: jal         0x800C4308
    // 0x800C755C: nop

    func_800C4308(rdram, ctx);
        goto after_1;
    // 0x800C755C: nop

    after_1:
    // 0x800C7560: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7564: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C7568: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C756C: jr          $ra
    // 0x800C7570: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C7570: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800044_sccustom_big(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800048: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080004C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800050: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3382, 0X400) << 16);
    // 0x80800054: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800058: jal         0x800E73D4
    // 0x8080005C: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3382, 0X400));
    func_800E73D4(rdram, ctx);
        goto after_0;
    // 0x8080005C: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3382, 0X400));
    after_0:
    // 0x80800060: jal         0x8008A618
    // 0x80800064: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _scinfobar_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x80800064: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800068: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3382, 0X400) << 16);
    // 0x8080006C: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3382, 0X400));
    // 0x80800070: jal         0x800E6DB4
    // 0x80800074: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800E6DB4(rdram, ctx);
        goto after_2;
    // 0x80800074: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80800078: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3382, 0X400) << 16);
    // 0x8080007C: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3382, 0X400));
    // 0x80800080: jal         0x800E6A58
    // 0x80800084: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    func_800E6A58(rdram, ctx);
        goto after_3;
    // 0x80800084: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    after_3:
    // 0x80800088: jal         0x8008A620
    // 0x8080008C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _scinfobar_entrypoint_20(rdram, ctx);
        goto after_4;
    // 0x8080008C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80800090: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3382, 0X400) << 16);
    // 0x80800094: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3382, 0X400));
    // 0x80800098: jal         0x800E6DB4
    // 0x8080009C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800E6DB4(rdram, ctx);
        goto after_5;
    // 0x8080009C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x808000A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3382, 0X400) << 16);
    // 0x808000A8: addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3382, 0X400));
    // 0x808000AC: jr          $ra
    // 0x808000B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x808000B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8080014C_chdrawbridgeswitches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080014C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800150: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800154: addiu       $t6, $zero, 0x6A
    ctx->r14 = ADD32(0, 0X6A);
    // 0x80800158: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080015C: jal         0x80800030
    // 0x80800160: addiu       $a3, $zero, 0x6B
    ctx->r7 = ADD32(0, 0X6B);
    func_80800030_chdrawbridgeswitches(rdram, ctx);
        goto after_0;
    // 0x80800160: addiu       $a3, $zero, 0x6B
    ctx->r7 = ADD32(0, 0X6B);
    after_0:
    // 0x80800164: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800168: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080016C: jr          $ra
    // 0x80800170: nop

    return;
    // 0x80800170: nop

;}
RECOMP_FUNC void func_800BEAF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEAF4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BEAF8: addiu       $a0, $a0, -0x7A50
    ctx->r4 = ADD32(ctx->r4, -0X7A50);
    // 0x800BEAFC: lbu         $t6, 0x77($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X77);
    // 0x800BEB00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BEB04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BEB08: beql        $t6, $zero, L_800BEB1C
    if (ctx->r14 == 0) {
        // 0x800BEB0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800BEB1C;
    }
    goto skip_0;
    // 0x800BEB0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800BEB10: jal         0x80087F40
    // 0x800BEB14: nop

    _gcmapsects_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x800BEB14: nop

    after_0:
    // 0x800BEB18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800BEB1C:
    // 0x800BEB1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BEB20: jr          $ra
    // 0x800BEB24: nop

    return;
    // 0x800BEB24: nop

;}
RECOMP_FUNC void func_800BE5C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE5C4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BE5C8: addiu       $v1, $v1, -0x7BF0
    ctx->r3 = ADD32(ctx->r3, -0X7BF0);
    // 0x800BE5CC: addiu       $t6, $v1, 0x34
    ctx->r14 = ADD32(ctx->r3, 0X34);
    // 0x800BE5D0: bne         $a0, $t6, L_800BE5E0
    if (ctx->r4 != ctx->r14) {
        // 0x800BE5D4: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800BE5E0;
    }
    // 0x800BE5D4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BE5D8: jr          $ra
    // 0x800BE5DC: addiu       $v0, $v0, -0x7BB2
    ctx->r2 = ADD32(ctx->r2, -0X7BB2);
    return;
    // 0x800BE5DC: addiu       $v0, $v0, -0x7BB2
    ctx->r2 = ADD32(ctx->r2, -0X7BB2);
L_800BE5E0:
    // 0x800BE5E0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800BE5E4: lw          $t0, 0x44($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X44);
    // 0x800BE5E8: subu        $t8, $a0, $t7
    ctx->r24 = SUB32(ctx->r4, ctx->r15);
    // 0x800BE5EC: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x800BE5F0: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x800BE5F4: jr          $ra
    // 0x800BE5F8: nop

    return;
    // 0x800BE5F8: nop

    // 0x800BE5FC: nop

;}
RECOMP_FUNC void _babounce_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084600: syscall     116
    recomp_syscall_handler(rdram, ctx, 0x80084600);
    return;
    // 0x80084604: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void _bsjig_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800831F0: syscall     51
    recomp_syscall_handler(rdram, ctx, 0x800831F0);
    return;
    // 0x800831F4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800800_chcredits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800800: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800804: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800808: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080080C: jal         0x800D8FF8
    // 0x80800810: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800810: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800814: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800818: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8080081C: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800820: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x80800824: bne         $at, $zero, L_80800860
    if (ctx->r1 != 0) {
        // 0x80800828: slti        $at, $t6, 0x6
        ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
            goto L_80800860;
    }
    // 0x80800828: slti        $at, $t6, 0x6
    ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
    // 0x8080082C: beq         $at, $zero, L_80800860
    if (ctx->r1 == 0) {
        // 0x80800830: addiu       $a1, $sp, 0x34
        ctx->r5 = ADD32(ctx->r29, 0X34);
            goto L_80800860;
    }
    // 0x80800830: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800834: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800838: jal         0x80015ECC
    // 0x8080083C: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    func_80015ECC(rdram, ctx);
        goto after_1;
    // 0x8080083C: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80800840: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80800844: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800848: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8080084C: bnel        $t7, $at, L_80800864
    if (ctx->r15 != ctx->r1) {
        // 0x80800850: lhu         $t8, 0x72($s0)
        ctx->r24 = MEM_HU(ctx->r16, 0X72);
            goto L_80800864;
    }
    goto skip_0;
    // 0x80800850: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x80800854: jal         0x808000C8
    // 0x80800858: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    func_808000C8_chcredits(rdram, ctx);
        goto after_2;
    // 0x80800858: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x8080085C: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
L_80800860:
    // 0x80800860: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
L_80800864:
    // 0x80800864: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80800868: addiu       $t0, $t9, -0x2
    ctx->r8 = ADD32(ctx->r25, -0X2);
    // 0x8080086C: sltiu       $at, $t0, 0x7
    ctx->r1 = ctx->r8 < 0X7 ? 1 : 0;
    // 0x80800870: beq         $at, $zero, L_80800BB8
    if (ctx->r1 == 0) {
        // 0x80800874: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80800BB8;
    }
    // 0x80800874: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80800878: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1636, 0X11E0) << 16);
    // 0x8080087C: addu        $at, $at, $t0
    gpr jr_addend_80800884 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80800880: lw          $t0, 0x11E0($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1636, 0X11E0));
    // 0x80800884: jr          $t0
    // 0x80800888: nop

    switch (jr_addend_80800884 >> 2) {
        case 0: goto L_8080088C; break;
        case 1: goto L_808008C4; break;
        case 2: goto L_808009C4; break;
        case 3: goto L_808009FC; break;
        case 4: goto L_80800B84; break;
        case 5: goto L_80800AEC; break;
        case 6: goto L_80800BB8; break;
        default: switch_error(__func__, 0x80800884, 0x808011E0);
    }
    // 0x80800888: nop

L_8080088C:
    // 0x8080088C: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800890: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800898: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x8080089C: nop

    // 0x808008A0: bc1fl       L_808008BC
    if (!c1cs) {
        // 0x808008A4: sub.s       $f6, $f0, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_808008BC;
    }
    goto skip_1;
    // 0x808008A4: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    skip_1:
    // 0x808008A8: jal         0x80800710
    // 0x808008AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800710_chcredits(rdram, ctx);
        goto after_3;
    // 0x808008AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x808008B0: b           L_80800BBC
    // 0x808008B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800BBC;
    // 0x808008B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808008B8: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
L_808008BC:
    // 0x808008BC: b           L_80800BB8
    // 0x808008C0: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
        goto L_80800BB8;
    // 0x808008C0: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
L_808008C4:
    // 0x808008C4: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808008C8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808008CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D0: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808008D4: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x808008D8: nop

    // 0x808008DC: bc1fl       L_80800904
    if (!c1cs) {
        // 0x808008E0: sub.s       $f10, $f0, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_80800904;
    }
    goto skip_2;
    // 0x808008E0: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    skip_2:
    // 0x808008E4: jal         0x80800710
    // 0x808008E8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800710_chcredits(rdram, ctx);
        goto after_4;
    // 0x808008E8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x808008EC: lhu         $t1, 0x6E($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X6E);
    // 0x808008F0: andi        $t2, $t1, 0xFE00
    ctx->r10 = ctx->r9 & 0XFE00;
    // 0x808008F4: ori         $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 | 0XFF;
    // 0x808008F8: b           L_80800BB8
    // 0x808008FC: sh          $t3, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r11;
        goto L_80800BB8;
    // 0x808008FC: sh          $t3, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r11;
    // 0x80800900: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
L_80800904:
    // 0x80800904: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800908: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080090C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800910: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800914: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x80800918: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080091C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800920: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80800924: jal         0x800F10B4
    // 0x80800928: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x80800928: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x8080092C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80800930: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800934: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80800938: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8080093C: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80800940: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80800944: nop

    // 0x80800948: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x8080094C: beql        $t5, $zero, L_8080099C
    if (ctx->r13 == 0) {
        // 0x80800950: mfc1        $t5, $f4
        ctx->r13 = (int32_t)ctx->f4.u32l;
            goto L_8080099C;
    }
    goto skip_3;
    // 0x80800950: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    skip_3:
    // 0x80800954: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800958: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8080095C: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80800960: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80800964: nop

    // 0x80800968: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8080096C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80800970: nop

    // 0x80800974: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80800978: bne         $t5, $zero, L_80800990
    if (ctx->r13 != 0) {
        // 0x8080097C: nop
    
            goto L_80800990;
    }
    // 0x8080097C: nop

    // 0x80800980: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x80800984: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800988: b           L_808009A8
    // 0x8080098C: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_808009A8;
    // 0x8080098C: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80800990:
    // 0x80800990: b           L_808009A8
    // 0x80800994: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_808009A8;
    // 0x80800994: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80800998: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
L_8080099C:
    // 0x8080099C: nop

    // 0x808009A0: bltz        $t5, L_80800990
    if (SIGNED(ctx->r13) < 0) {
        // 0x808009A4: nop
    
            goto L_80800990;
    }
    // 0x808009A4: nop

L_808009A8:
    // 0x808009A8: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    // 0x808009AC: andi        $t7, $t5, 0x1FF
    ctx->r15 = ctx->r13 & 0X1FF;
    // 0x808009B0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x808009B4: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x808009B8: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x808009BC: b           L_80800BB8
    // 0x808009C0: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
        goto L_80800BB8;
    // 0x808009C0: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
L_808009C4:
    // 0x808009C4: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808009C8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808009CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009D0: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x808009D4: nop

    // 0x808009D8: bc1fl       L_808009F4
    if (!c1cs) {
        // 0x808009DC: sub.s       $f8, $f0, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_808009F4;
    }
    goto skip_4;
    // 0x808009DC: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    skip_4:
    // 0x808009E0: jal         0x80800710
    // 0x808009E4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800710_chcredits(rdram, ctx);
        goto after_6;
    // 0x808009E4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
    // 0x808009E8: b           L_80800BBC
    // 0x808009EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800BBC;
    // 0x808009EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808009F0: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
L_808009F4:
    // 0x808009F4: b           L_80800BB8
    // 0x808009F8: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
        goto L_80800BB8;
    // 0x808009F8: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_808009FC:
    // 0x808009FC: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800A00: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800A04: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800A08: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80800A0C: nop

    // 0x80800A10: bc1fl       L_80800A34
    if (!c1cs) {
        // 0x80800A14: sub.s       $f18, $f0, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_80800A34;
    }
    goto skip_5;
    // 0x80800A14: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    skip_5:
    // 0x80800A18: jal         0x80800300
    // 0x80800A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800300_chcredits(rdram, ctx);
        goto after_7;
    // 0x80800A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800A20: lhu         $t1, 0x6E($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800A24: andi        $t2, $t1, 0xFE00
    ctx->r10 = ctx->r9 & 0XFE00;
    // 0x80800A28: b           L_80800BB8
    // 0x80800A2C: sh          $t2, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r10;
        goto L_80800BB8;
    // 0x80800A2C: sh          $t2, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r10;
    // 0x80800A30: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
L_80800A34:
    // 0x80800A34: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800A38: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800A3C: lui         $a3, 0x437F
    ctx->r7 = S32(0X437F << 16);
    // 0x80800A40: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    // 0x80800A44: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800A48: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800A4C: jal         0x800F10B4
    // 0x80800A50: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x80800A50: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_8:
    // 0x80800A54: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80800A58: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80800A5C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80800A60: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800A64: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80800A68: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80800A6C: nop

    // 0x80800A70: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80800A74: beql        $t4, $zero, L_80800AC4
    if (ctx->r12 == 0) {
        // 0x80800A78: mfc1        $t4, $f4
        ctx->r12 = (int32_t)ctx->f4.u32l;
            goto L_80800AC4;
    }
    goto skip_6;
    // 0x80800A78: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    skip_6:
    // 0x80800A7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A80: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80800A84: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80800A88: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80800A8C: nop

    // 0x80800A90: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80800A94: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80800A98: nop

    // 0x80800A9C: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80800AA0: bne         $t4, $zero, L_80800AB8
    if (ctx->r12 != 0) {
        // 0x80800AA4: nop
    
            goto L_80800AB8;
    }
    // 0x80800AA4: nop

    // 0x80800AA8: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x80800AAC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800AB0: b           L_80800AD0
    // 0x80800AB4: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_80800AD0;
    // 0x80800AB4: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_80800AB8:
    // 0x80800AB8: b           L_80800AD0
    // 0x80800ABC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_80800AD0;
    // 0x80800ABC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80800AC0: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
L_80800AC4:
    // 0x80800AC4: nop

    // 0x80800AC8: bltz        $t4, L_80800AB8
    if (SIGNED(ctx->r12) < 0) {
        // 0x80800ACC: nop
    
            goto L_80800AB8;
    }
    // 0x80800ACC: nop

L_80800AD0:
    // 0x80800AD0: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800AD4: andi        $t6, $t4, 0x1FF
    ctx->r14 = ctx->r12 & 0X1FF;
    // 0x80800AD8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80800ADC: andi        $t7, $t8, 0xFE00
    ctx->r15 = ctx->r24 & 0XFE00;
    // 0x80800AE0: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80800AE4: b           L_80800BB8
    // 0x80800AE8: sh          $t9, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r25;
        goto L_80800BB8;
    // 0x80800AE8: sh          $t9, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r25;
L_80800AEC:
    // 0x80800AEC: jal         0x800C954C
    // 0x80800AF0: nop

    func_800C954C(rdram, ctx);
        goto after_9;
    // 0x80800AF0: nop

    after_9:
    // 0x80800AF4: bnel        $v0, $zero, L_80800BBC
    if (ctx->r2 != 0) {
        // 0x80800AF8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800BBC;
    }
    goto skip_7;
    // 0x80800AF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x80800AFC: jal         0x800EA05C
    // 0x80800B00: nop

    func_800EA05C(rdram, ctx);
        goto after_10;
    // 0x80800B00: nop

    after_10:
    // 0x80800B04: addiu       $at, $zero, 0x19C
    ctx->r1 = ADD32(0, 0X19C);
    // 0x80800B08: beq         $v0, $at, L_80800B24
    if (ctx->r2 == ctx->r1) {
        // 0x80800B0C: addiu       $a0, $zero, 0x650
        ctx->r4 = ADD32(0, 0X650);
            goto L_80800B24;
    }
    // 0x80800B0C: addiu       $a0, $zero, 0x650
    ctx->r4 = ADD32(0, 0X650);
    // 0x80800B10: addiu       $at, $zero, 0x19D
    ctx->r1 = ADD32(0, 0X19D);
    // 0x80800B14: beq         $v0, $at, L_80800B54
    if (ctx->r2 == ctx->r1) {
        // 0x80800B18: addiu       $a0, $zero, 0x650
        ctx->r4 = ADD32(0, 0X650);
            goto L_80800B54;
    }
    // 0x80800B18: addiu       $a0, $zero, 0x650
    ctx->r4 = ADD32(0, 0X650);
    // 0x80800B1C: b           L_80800BBC
    // 0x80800B20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800BBC;
    // 0x80800B20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800B24:
    // 0x80800B24: jal         0x800DA9E4
    // 0x80800B28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA9E4(rdram, ctx);
        goto after_11;
    // 0x80800B28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80800B2C: beq         $v0, $zero, L_80800B44
    if (ctx->r2 == 0) {
        // 0x80800B30: nop
    
            goto L_80800B44;
    }
    // 0x80800B30: nop

    // 0x80800B34: jal         0x8080038C
    // 0x80800B38: nop

    func_8080038C_chcredits(rdram, ctx);
        goto after_12;
    // 0x80800B38: nop

    after_12:
    // 0x80800B3C: b           L_80800BBC
    // 0x80800B40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800BBC;
    // 0x80800B40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800B44:
    // 0x80800B44: jal         0x80800208
    // 0x80800B48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    chcredits_entrypoint_0(rdram, ctx);
        goto after_13;
    // 0x80800B48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x80800B4C: b           L_80800BBC
    // 0x80800B50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800BBC;
    // 0x80800B50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800B54:
    // 0x80800B54: jal         0x800DA9E4
    // 0x80800B58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA9E4(rdram, ctx);
        goto after_14;
    // 0x80800B58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80800B5C: beq         $v0, $zero, L_80800B74
    if (ctx->r2 == 0) {
        // 0x80800B60: nop
    
            goto L_80800B74;
    }
    // 0x80800B60: nop

    // 0x80800B64: jal         0x8080038C
    // 0x80800B68: nop

    func_8080038C_chcredits(rdram, ctx);
        goto after_15;
    // 0x80800B68: nop

    after_15:
    // 0x80800B6C: b           L_80800BBC
    // 0x80800B70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800BBC;
    // 0x80800B70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800B74:
    // 0x80800B74: jal         0x80800208
    // 0x80800B78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    chcredits_entrypoint_0(rdram, ctx);
        goto after_16;
    // 0x80800B78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x80800B7C: b           L_80800BBC
    // 0x80800B80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800BBC;
    // 0x80800B80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800B84:
    // 0x80800B84: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800B88: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B90: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80800B94: nop

    // 0x80800B98: bc1fl       L_80800BB4
    if (!c1cs) {
        // 0x80800B9C: sub.s       $f8, $f0, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_80800BB4;
    }
    goto skip_8;
    // 0x80800B9C: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    skip_8:
    // 0x80800BA0: jal         0x80800710
    // 0x80800BA4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800710_chcredits(rdram, ctx);
        goto after_17;
    // 0x80800BA4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_17:
    // 0x80800BA8: b           L_80800BBC
    // 0x80800BAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800BBC;
    // 0x80800BAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800BB0: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
L_80800BB4:
    // 0x80800BB4: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
L_80800BB8:
    // 0x80800BB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800BBC:
    // 0x80800BBC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800BC0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800BC4: jr          $ra
    // 0x80800BC8: nop

    return;
    // 0x80800BC8: nop

;}
RECOMP_FUNC void _gcnewoption_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087D10: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087D10);
    return;
    // 0x80087D14: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void _chfireicestorm_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086850: syscall     389
    recomp_syscall_handler(rdram, ctx, 0x80086850);
    return;
    // 0x80086854: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800320_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800320: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800324: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800328: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080032C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800330: jal         0x8008CABC
    // 0x80800334: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800334: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800338: lw          $t6, 0x160($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X160);
    // 0x8080033C: lui         $a1, 0x3E77
    ctx->r5 = S32(0X3E77 << 16);
    // 0x80800340: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800344: bne         $t6, $zero, L_80800394
    if (ctx->r14 != 0) {
        // 0x80800348: ori         $a1, $a1, 0x65FE
        ctx->r5 = ctx->r5 | 0X65FE;
            goto L_80800394;
    }
    // 0x80800348: ori         $a1, $a1, 0x65FE
    ctx->r5 = ctx->r5 | 0X65FE;
    // 0x8080034C: jal         0x8008B348
    // 0x80800350: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    anctrl_isAt(rdram, ctx);
        goto after_1;
    // 0x80800350: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800354: beq         $v0, $zero, L_808003C0
    if (ctx->r2 == 0) {
        // 0x80800358: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808003C0;
    }
    // 0x80800358: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080035C: lui         $a1, 0x4019
    ctx->r5 = S32(0X4019 << 16);
    // 0x80800360: jal         0x8008B1BC
    // 0x80800364: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    anctrl_setDuration(rdram, ctx);
        goto after_2;
    // 0x80800364: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_2:
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080036C: jal         0x8009BA58
    // 0x80800370: lui         $a1, 0x44C8
    ctx->r5 = S32(0X44C8 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_3;
    // 0x80800370: lui         $a1, 0x44C8
    ctx->r5 = S32(0X44C8 << 16);
    after_3:
    // 0x80800374: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80800378: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800380: jal         0x8009DE38
    // 0x80800384: addiu       $a1, $zero, 0x406
    ctx->r5 = ADD32(0, 0X406);
    func_8009DE38(rdram, ctx);
        goto after_4;
    // 0x80800384: addiu       $a1, $zero, 0x406
    ctx->r5 = ADD32(0, 0X406);
    after_4:
    // 0x80800388: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080038C: b           L_808003C0
    // 0x80800390: sw          $t7, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r15;
        goto L_808003C0;
    // 0x80800390: sw          $t7, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r15;
L_80800394:
    // 0x80800394: jal         0x80800000
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsbfly(rdram, ctx);
        goto after_5;
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080039C: jal         0x8009BB50
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_6;
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808003A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808003A8: addiu       $t8, $zero, 0x24
    ctx->r24 = ADD32(0, 0X24);
    // 0x808003AC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808003B0: nop

    // 0x808003B4: bc1fl       L_808003C4
    if (!c1cs) {
        // 0x808003B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003C4;
    }
    goto skip_0;
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808003BC: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_808003C0:
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003C4:
    // 0x808003C4: jal         0x8009E5C8
    // 0x808003C8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_7;
    // 0x808003C8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x808003CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003D8: jr          $ra
    // 0x808003DC: nop

    return;
    // 0x808003DC: nop

;}
RECOMP_FUNC void _bscrashout_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082F48: syscall     35
    recomp_syscall_handler(rdram, ctx, 0x80082F48);
    return;
    // 0x80082F4C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800724_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800724: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800728: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080072C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800730: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80800734: jal         0x801039E4
    // 0x80800738: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_801039E4(rdram, ctx);
        goto after_0;
    // 0x80800738: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x8080073C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800740: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800744: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800748: jal         0x80100094
    // 0x8080074C: sh          $zero, 0x42($sp)
    MEM_H(0X42, ctx->r29) = 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080074C: sh          $zero, 0x42($sp)
    MEM_H(0X42, ctx->r29) = 0;
    after_1:
    // 0x80800750: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80800754: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800758: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080075C: lhu         $s0, 0x72($t7)
    ctx->r16 = MEM_HU(ctx->r15, 0X72);
    // 0x80800760: lh          $a2, 0x42($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X42);
    // 0x80800764: srl         $t8, $s0, 10
    ctx->r24 = S32(U32(ctx->r16) >> 10);
    // 0x80800768: beq         $t8, $at, L_80800788
    if (ctx->r24 == ctx->r1) {
        // 0x8080076C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800788;
    }
    // 0x8080076C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800770: beq         $t8, $at, L_80800790
    if (ctx->r24 == ctx->r1) {
        // 0x80800774: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800790;
    }
    // 0x80800774: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800778: beql        $t8, $at, L_8080079C
    if (ctx->r24 == ctx->r1) {
        // 0x8080077C: addiu       $a2, $zero, 0x1F4
        ctx->r6 = ADD32(0, 0X1F4);
            goto L_8080079C;
    }
    goto skip_0;
    // 0x8080077C: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    skip_0:
    // 0x80800780: b           L_8080079C
    // 0x80800784: nop

        goto L_8080079C;
    // 0x80800784: nop

L_80800788:
    // 0x80800788: b           L_8080079C
    // 0x8080078C: addiu       $a2, $zero, 0x1F2
    ctx->r6 = ADD32(0, 0X1F2);
        goto L_8080079C;
    // 0x8080078C: addiu       $a2, $zero, 0x1F2
    ctx->r6 = ADD32(0, 0X1F2);
L_80800790:
    // 0x80800790: b           L_8080079C
    // 0x80800794: addiu       $a2, $zero, 0x1F3
    ctx->r6 = ADD32(0, 0X1F3);
        goto L_8080079C;
    // 0x80800794: addiu       $a2, $zero, 0x1F3
    ctx->r6 = ADD32(0, 0X1F3);
    // 0x80800798: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
L_8080079C:
    // 0x8080079C: beql        $a2, $zero, L_808007E4
    if (ctx->r6 == 0) {
        // 0x808007A0: lw          $s0, 0x3C($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X3C);
            goto L_808007E4;
    }
    goto skip_1;
    // 0x808007A0: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x808007A4: jal         0x800D674C
    // 0x808007A8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800D674C(rdram, ctx);
        goto after_2;
    // 0x808007A8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x808007AC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808007B0: jal         0x80101F24
    // 0x808007B4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80101F24(rdram, ctx);
        goto after_3;
    // 0x808007B4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_3:
    // 0x808007B8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x808007BC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808007C0: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x808007C4: addiu       $t1, $t0, 0x2C
    ctx->r9 = ADD32(ctx->r8, 0X2C);
    // 0x808007C8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x808007CC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808007D8: jal         0x800E02F8
    // 0x808007DC: addiu       $a3, $zero, 0x2A
    ctx->r7 = ADD32(0, 0X2A);
    func_800E02F8(rdram, ctx);
        goto after_4;
    // 0x808007DC: addiu       $a3, $zero, 0x2A
    ctx->r7 = ADD32(0, 0X2A);
    after_4:
    // 0x808007E0: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
L_808007E4:
    // 0x808007E4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808007E8: jal         0x800B2768
    // 0x808007EC: addiu       $s0, $s0, 0x2C
    ctx->r16 = ADD32(ctx->r16, 0X2C);
    func_800B2768(rdram, ctx);
        goto after_5;
    // 0x808007EC: addiu       $s0, $s0, 0x2C
    ctx->r16 = ADD32(ctx->r16, 0X2C);
    after_5:
    // 0x808007F0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808007F4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808007F8: jal         0x80103CB8
    // 0x808007FC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80103CB8(rdram, ctx);
        goto after_6;
    // 0x808007FC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_6:
    // 0x80800800: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800804: jal         0x800B2840
    // 0x80800808: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_800B2840(rdram, ctx);
        goto after_7;
    // 0x80800808: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_7:
    // 0x8080080C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800810: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800814: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800818: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8080081C: jal         0x80087990
    // 0x80800820: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    _dbmorph_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x80800820: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_8:
    // 0x80800824: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800828: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080082C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800830: jr          $ra
    // 0x80800834: nop

    return;
    // 0x80800834: nop

;}
RECOMP_FUNC void _subaddielink_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A048: syscall     823
    recomp_syscall_handler(rdram, ctx, 0x8008A048);
    return;
    // 0x8008A04C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80092EC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092EC8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80092ECC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80092ED0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80092ED4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80092ED8: lw          $v1, 0x50($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X50);
    // 0x80092EDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80092EE0: lh          $a2, 0xC($v1)
    ctx->r6 = MEM_H(ctx->r3, 0XC);
    // 0x80092EE4: beql        $a1, $a2, L_80093060
    if (ctx->r5 == ctx->r6) {
        // 0x80092EE8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80093060;
    }
    goto skip_0;
    // 0x80092EE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80092EEC: beq         $a2, $zero, L_80092F14
    if (ctx->r6 == 0) {
        // 0x80092EF0: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80092F14;
    }
    // 0x80092EF0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80092EF4: jal         0x800D70F8
    // 0x80092EF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D70F8(rdram, ctx);
        goto after_0;
    // 0x80092EF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80092EFC: lw          $t7, 0x50($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X50);
    // 0x80092F00: jal         0x800D6CEC
    // 0x80092F04: lh          $a0, 0xC($t7)
    ctx->r4 = MEM_H(ctx->r15, 0XC);
    func_800D6CEC(rdram, ctx);
        goto after_1;
    // 0x80092F04: lh          $a0, 0xC($t7)
    ctx->r4 = MEM_H(ctx->r15, 0XC);
    after_1:
    // 0x80092F08: lw          $t8, 0x50($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X50);
    // 0x80092F0C: sh          $zero, 0xE($t8)
    MEM_H(0XE, ctx->r24) = 0;
    // 0x80092F10: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
L_80092F14:
    // 0x80092F14: lbu         $v0, 0x12($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X12);
    // 0x80092F18: beq         $v0, $zero, L_80092F38
    if (ctx->r2 == 0) {
        // 0x80092F1C: sll         $a0, $v0, 16
        ctx->r4 = S32(ctx->r2 << 16);
            goto L_80092F38;
    }
    // 0x80092F1C: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x80092F20: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80092F24: jal         0x80100E18
    // 0x80092F28: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_80100E18(rdram, ctx);
        goto after_2;
    // 0x80092F28: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_2:
    // 0x80092F2C: lw          $t0, 0x50($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X50);
    // 0x80092F30: sb          $zero, 0x12($t0)
    MEM_B(0X12, ctx->r8) = 0;
    // 0x80092F34: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
L_80092F38:
    // 0x80092F38: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80092F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80092F40: sh          $t1, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r9;
    // 0x80092F44: jal         0x80093FD4
    // 0x80092F48: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80093FD4(rdram, ctx);
        goto after_3;
    // 0x80092F48: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x80092F4C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80092F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80092F54: beql        $t2, $zero, L_80093060
    if (ctx->r10 == 0) {
        // 0x80092F58: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80093060;
    }
    goto skip_1;
    // 0x80092F58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80092F5C: jal         0x80092B04
    // 0x80092F60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80092B04(rdram, ctx);
        goto after_4;
    // 0x80092F60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80092F64: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80092F68: lw          $t3, 0x50($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X50);
    // 0x80092F6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80092F70: jal         0x800D70F8
    // 0x80092F74: lh          $a0, 0xC($t3)
    ctx->r4 = MEM_H(ctx->r11, 0XC);
    func_800D70F8(rdram, ctx);
        goto after_5;
    // 0x80092F74: lh          $a0, 0xC($t3)
    ctx->r4 = MEM_H(ctx->r11, 0XC);
    after_5:
    // 0x80092F78: jal         0x800B27E0
    // 0x80092F7C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800B27E0(rdram, ctx);
        goto after_6;
    // 0x80092F7C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x80092F80: lw          $t4, 0x50($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X50);
    // 0x80092F84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80092F88: jal         0x800ADD80
    // 0x80092F8C: lh          $a0, 0x0($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X0);
    func_800ADD80(rdram, ctx);
        goto after_7;
    // 0x80092F8C: lh          $a0, 0x0($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X0);
    after_7:
    // 0x80092F90: lw          $t5, 0x50($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X50);
    // 0x80092F94: lbu         $t6, 0x12($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X12);
    // 0x80092F98: bne         $t6, $zero, L_80092FEC
    if (ctx->r14 != 0) {
        // 0x80092F9C: nop
    
            goto L_80092FEC;
    }
    // 0x80092F9C: nop

    // 0x80092FA0: jal         0x800B26F0
    // 0x80092FA4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800B26F0(rdram, ctx);
        goto after_8;
    // 0x80092FA4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_8:
    // 0x80092FA8: beq         $v0, $zero, L_80092FB8
    if (ctx->r2 == 0) {
        // 0x80092FAC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80092FB8;
    }
    // 0x80092FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80092FB0: b           L_80092FBC
    // 0x80092FB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80092FBC;
    // 0x80092FB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80092FB8:
    // 0x80092FB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80092FBC:
    // 0x80092FBC: jal         0x800A25D0
    // 0x80092FC0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800A25D0(rdram, ctx);
        goto after_9;
    // 0x80092FC0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_9:
    // 0x80092FC4: lw          $t7, 0x50($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X50);
    // 0x80092FC8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80092FCC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80092FD0: lh          $a1, 0xC($t7)
    ctx->r5 = MEM_H(ctx->r15, 0XC);
    // 0x80092FD4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80092FD8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80092FDC: jal         0x80100D24
    // 0x80092FE0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80100D24(rdram, ctx);
        goto after_10;
    // 0x80092FE0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_10:
    // 0x80092FE4: lw          $t8, 0x50($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X50);
    // 0x80092FE8: sb          $v0, 0x12($t8)
    MEM_B(0X12, ctx->r24) = ctx->r2;
L_80092FEC:
    // 0x80092FEC: jal         0x800B2840
    // 0x80092FF0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800B2840(rdram, ctx);
        goto after_11;
    // 0x80092FF0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_11:
    // 0x80092FF4: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x80092FF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80092FFC: addiu       $a1, $v1, 0x50
    ctx->r5 = ADD32(ctx->r3, 0X50);
    // 0x80093000: jal         0x800B237C
    // 0x80093004: addiu       $a2, $v1, 0x5C
    ctx->r6 = ADD32(ctx->r3, 0X5C);
    func_800B237C(rdram, ctx);
        goto after_12;
    // 0x80093004: addiu       $a2, $v1, 0x5C
    ctx->r6 = ADD32(ctx->r3, 0X5C);
    after_12:
    // 0x80093008: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8009300C: lw          $t9, 0x50($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X50);
    // 0x80093010: swc1        $f4, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->f4.u32l;
    // 0x80093014: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x80093018: lwc1        $f6, 0x58($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X58);
    // 0x8009301C: swc1        $f6, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f6.u32l;
    // 0x80093020: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x80093024: addiu       $a0, $v1, 0x64
    ctx->r4 = ADD32(ctx->r3, 0X64);
    // 0x80093028: jal         0x800EE7F8
    // 0x8009302C: addiu       $a1, $v1, 0x50
    ctx->r5 = ADD32(ctx->r3, 0X50);
    func_800EE7F8(rdram, ctx);
        goto after_13;
    // 0x8009302C: addiu       $a1, $v1, 0x50
    ctx->r5 = ADD32(ctx->r3, 0X50);
    after_13:
    // 0x80093030: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x80093034: lwc1        $f8, 0x5C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x80093038: swc1        $f8, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f8.u32l;
    // 0x8009303C: jal         0x800B2840
    // 0x80093040: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800B2840(rdram, ctx);
        goto after_14;
    // 0x80093040: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_14:
    // 0x80093044: jal         0x800B2354
    // 0x80093048: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B2354(rdram, ctx);
        goto after_15;
    // 0x80093048: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_15:
    // 0x8009304C: lw          $t0, 0x50($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X50);
    // 0x80093050: swc1        $f0, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->f0.u32l;
    // 0x80093054: lw          $t1, 0x50($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X50);
    // 0x80093058: swc1        $f0, 0x60($t1)
    MEM_W(0X60, ctx->r9) = ctx->f0.u32l;
    // 0x8009305C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80093060:
    // 0x80093060: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80093064: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80093068: jr          $ra
    // 0x8009306C: nop

    return;
    // 0x8009306C: nop

;}
RECOMP_FUNC void func_8080356C_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080356C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803570: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803574: jal         0x80106790
    // 0x80803578: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80803578: nop

    after_0:
    // 0x8080357C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803580: jal         0x80102424
    // 0x80803584: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80803584: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x80803588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080358C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803590: jr          $ra
    // 0x80803594: nop

    return;
    // 0x80803594: nop

;}
RECOMP_FUNC void func_80801F74_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801F78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801F7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801F80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801F84: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801F88: jal         0x80088280
    // 0x80801F8C: addiu       $a0, $zero, 0x226
    ctx->r4 = ADD32(0, 0X226);
    _gccubesearch_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80801F8C: addiu       $a0, $zero, 0x226
    ctx->r4 = ADD32(0, 0X226);
    after_0:
    // 0x80801F90: jal         0x800EA05C
    // 0x80801F94: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x80801F94: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80801F98: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80801F9C: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x80801FA0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80801FA4: andi        $t7, $t6, 0x7F
    ctx->r15 = ctx->r14 & 0X7F;
    // 0x80801FA8: bne         $a0, $zero, L_80801FC0
    if (ctx->r4 != 0) {
        // 0x80801FAC: sh          $t7, 0x76($s0)
        MEM_H(0X76, ctx->r16) = ctx->r15;
            goto L_80801FC0;
    }
    // 0x80801FAC: sh          $t7, 0x76($s0)
    MEM_H(0X76, ctx->r16) = ctx->r15;
    // 0x80801FB0: jal         0x800FFAB0
    // 0x80801FB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80801FB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801FB8: b           L_808021E4
    // 0x80801FBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808021E4;
    // 0x80801FBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801FC0:
    // 0x80801FC0: jal         0x80088C00
    // 0x80801FC4: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x80801FC4: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_3:
    // 0x80801FC8: jal         0x8080071C
    // 0x80801FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080071C_chhumba(rdram, ctx);
        goto after_4;
    // 0x80801FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801FD0: lhu         $t0, 0x6E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6E);
    // 0x80801FD4: andi        $t9, $v0, 0x1FF
    ctx->r25 = ctx->r2 & 0X1FF;
    // 0x80801FD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801FDC: andi        $t1, $t0, 0xFE00
    ctx->r9 = ctx->r8 & 0XFE00;
    // 0x80801FE0: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80801FE4: sh          $t2, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r10;
    // 0x80801FE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801FEC: jal         0x800897C0
    // 0x80801FF0: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x80801FF0: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_5:
    // 0x80801FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801FF8: jal         0x80100094
    // 0x80801FFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_6;
    // 0x80801FFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80802000: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80802004: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802008: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080200C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80802010: jal         0x800897E8
    // 0x80802014: nop

    _suexpression_entrypoint_12(rdram, ctx);
        goto after_7;
    // 0x80802014: nop

    after_7:
    // 0x80802018: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8080201C: addiu       $at, $zero, 0x120
    ctx->r1 = ADD32(0, 0X120);
    // 0x80802020: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80802024: beq         $v0, $at, L_80802058
    if (ctx->r2 == ctx->r1) {
        // 0x80802028: addiu       $at, $zero, 0x135
        ctx->r1 = ADD32(0, 0X135);
            goto L_80802058;
    }
    // 0x80802028: addiu       $at, $zero, 0x135
    ctx->r1 = ADD32(0, 0X135);
    // 0x8080202C: beq         $v0, $at, L_80802048
    if (ctx->r2 == ctx->r1) {
        // 0x80802030: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80802048;
    }
    // 0x80802030: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80802034: addiu       $at, $zero, 0x157
    ctx->r1 = ADD32(0, 0X157);
    // 0x80802038: beql        $v0, $at, L_8080206C
    if (ctx->r2 == ctx->r1) {
        // 0x8080203C: lbu         $t4, 0x74($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0X74);
            goto L_8080206C;
    }
    goto skip_0;
    // 0x8080203C: lbu         $t4, 0x74($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X74);
    skip_0:
    // 0x80802040: b           L_80802078
    // 0x80802044: addiu       $at, $zero, 0x135
    ctx->r1 = ADD32(0, 0X135);
        goto L_80802078;
    // 0x80802044: addiu       $at, $zero, 0x135
    ctx->r1 = ADD32(0, 0X135);
L_80802048:
    // 0x80802048: jal         0x800BF744
    // 0x8080204C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_8;
    // 0x8080204C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80802050: b           L_80802074
    // 0x80802054: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_80802074;
    // 0x80802054: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_80802058:
    // 0x80802058: jal         0x800BF744
    // 0x8080205C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_9;
    // 0x8080205C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80802060: b           L_80802074
    // 0x80802064: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_80802074;
    // 0x80802064: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80802068: lbu         $t4, 0x74($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X74);
L_8080206C:
    // 0x8080206C: ori         $t5, $t4, 0x20
    ctx->r13 = ctx->r12 | 0X20;
    // 0x80802070: sb          $t5, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r13;
L_80802074:
    // 0x80802074: addiu       $at, $zero, 0x135
    ctx->r1 = ADD32(0, 0X135);
L_80802078:
    // 0x80802078: beq         $v0, $at, L_80802090
    if (ctx->r2 == ctx->r1) {
        // 0x8080207C: addiu       $a0, $zero, 0x381
        ctx->r4 = ADD32(0, 0X381);
            goto L_80802090;
    }
    // 0x8080207C: addiu       $a0, $zero, 0x381
    ctx->r4 = ADD32(0, 0X381);
    // 0x80802080: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1688, 0X272C) << 16);
    // 0x80802084: addiu       $a1, $a1, 0x272C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1688, 0X272C));
    // 0x80802088: jal         0x80108474
    // 0x8080208C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80108474(rdram, ctx);
        goto after_10;
    // 0x8080208C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
L_80802090:
    // 0x80802090: jal         0x80088848
    // 0x80802094: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_11;
    // 0x80802094: nop

    after_11:
    // 0x80802098: beq         $v0, $zero, L_808020B0
    if (ctx->r2 == 0) {
        // 0x8080209C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808020B0;
    }
    // 0x8080209C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808020A0: jal         0x80800E44
    // 0x808020A4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80800E44_chhumba(rdram, ctx);
        goto after_12;
    // 0x808020A4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_12:
    // 0x808020A8: b           L_808021E4
    // 0x808020AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808021E4;
    // 0x808020AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808020B0:
    // 0x808020B0: jal         0x8008FD70
    // 0x808020B4: nop

    func_8008FD70(rdram, ctx);
        goto after_13;
    // 0x808020B4: nop

    after_13:
    // 0x808020B8: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x808020BC: beq         $v0, $at, L_808020FC
    if (ctx->r2 == ctx->r1) {
        // 0x808020C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808020FC;
    }
    // 0x808020C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808020C4: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x808020C8: beq         $v0, $at, L_808020FC
    if (ctx->r2 == ctx->r1) {
        // 0x808020CC: addiu       $at, $zero, 0x1000
        ctx->r1 = ADD32(0, 0X1000);
            goto L_808020FC;
    }
    // 0x808020CC: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x808020D0: beq         $v0, $at, L_808020EC
    if (ctx->r2 == ctx->r1) {
        // 0x808020D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808020EC;
    }
    // 0x808020D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808020D8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x808020DC: beql        $v0, $at, L_808021E4
    if (ctx->r2 == ctx->r1) {
        // 0x808020E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808021E4;
    }
    goto skip_1;
    // 0x808020E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808020E4: b           L_8080210C
    // 0x808020E8: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
        goto L_8080210C;
    // 0x808020E8: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
L_808020EC:
    // 0x808020EC: jal         0x80800E44
    // 0x808020F0: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_80800E44_chhumba(rdram, ctx);
        goto after_14;
    // 0x808020F0: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_14:
    // 0x808020F4: b           L_808021E4
    // 0x808020F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808021E4;
    // 0x808020F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808020FC:
    // 0x808020FC: jal         0x80800E44
    // 0x80802100: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_80800E44_chhumba(rdram, ctx);
        goto after_15;
    // 0x80802100: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_15:
    // 0x80802104: b           L_808021E4
    // 0x80802108: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808021E4;
    // 0x80802108: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080210C:
    // 0x8080210C: lw          $t6, 0x74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X74);
    // 0x80802110: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80802114: bgezl       $t8, L_80802140
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80802118: lw          $t0, 0x74($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X74);
            goto L_80802140;
    }
    goto skip_2;
    // 0x80802118: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    skip_2:
    // 0x8080211C: jal         0x800DA9E4
    // 0x80802120: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_16;
    // 0x80802120: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x80802124: bne         $v0, $zero, L_8080213C
    if (ctx->r2 != 0) {
        // 0x80802128: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080213C;
    }
    // 0x80802128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080212C: jal         0x80800E44
    // 0x80802130: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800E44_chhumba(rdram, ctx);
        goto after_17;
    // 0x80802130: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_17:
    // 0x80802134: b           L_808021E4
    // 0x80802138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808021E4;
    // 0x80802138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080213C:
    // 0x8080213C: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
L_80802140:
    // 0x80802140: addiu       $a0, $zero, 0x8F
    ctx->r4 = ADD32(0, 0X8F);
    // 0x80802144: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80802148: bltz        $t1, L_80802170
    if (SIGNED(ctx->r9) < 0) {
        // 0x8080214C: nop
    
            goto L_80802170;
    }
    // 0x8080214C: nop

    // 0x80802150: jal         0x800DA9E4
    // 0x80802154: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_18;
    // 0x80802154: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x80802158: bne         $v0, $zero, L_80802170
    if (ctx->r2 != 0) {
        // 0x8080215C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802170;
    }
    // 0x8080215C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802160: jal         0x80800E44
    // 0x80802164: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800E44_chhumba(rdram, ctx);
        goto after_19;
    // 0x80802164: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_19:
    // 0x80802168: b           L_808021E4
    // 0x8080216C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808021E4;
    // 0x8080216C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802170:
    // 0x80802170: jal         0x80800878
    // 0x80802174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800878_chhumba(rdram, ctx);
        goto after_20;
    // 0x80802174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80802178: beq         $v0, $zero, L_808021D8
    if (ctx->r2 == 0) {
        // 0x8080217C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808021D8;
    }
    // 0x8080217C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802180: jal         0x8008FD48
    // 0x80802184: nop

    func_8008FD48(rdram, ctx);
        goto after_21;
    // 0x80802184: nop

    after_21:
    // 0x80802188: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080218C: bnel        $v0, $at, L_808021C8
    if (ctx->r2 != ctx->r1) {
        // 0x80802190: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808021C8;
    }
    goto skip_3;
    // 0x80802190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80802194: jal         0x8009EA2C
    // 0x80802198: nop

    func_8009EA2C(rdram, ctx);
        goto after_22;
    // 0x80802198: nop

    after_22:
    // 0x8080219C: beq         $v0, $zero, L_808021B4
    if (ctx->r2 == 0) {
        // 0x808021A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808021B4;
    }
    // 0x808021A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808021A4: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x808021A8: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x808021AC: bltzl       $t4, L_808021C8
    if (SIGNED(ctx->r12) < 0) {
        // 0x808021B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808021C8;
    }
    goto skip_4;
    // 0x808021B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
L_808021B4:
    // 0x808021B4: jal         0x80800E44
    // 0x808021B8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800E44_chhumba(rdram, ctx);
        goto after_23;
    // 0x808021B8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_23:
    // 0x808021BC: b           L_808021E4
    // 0x808021C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808021E4;
    // 0x808021C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808021C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808021C8:
    // 0x808021C8: jal         0x80800E44
    // 0x808021CC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800E44_chhumba(rdram, ctx);
        goto after_24;
    // 0x808021CC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_24:
    // 0x808021D0: b           L_808021E4
    // 0x808021D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808021E4;
    // 0x808021D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808021D8:
    // 0x808021D8: jal         0x80800E44
    // 0x808021DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800E44_chhumba(rdram, ctx);
        goto after_25;
    // 0x808021DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x808021E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808021E4:
    // 0x808021E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808021E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808021EC: jr          $ra
    // 0x808021F0: nop

    return;
    // 0x808021F0: nop

;}
RECOMP_FUNC void func_800A8230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8230: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A8234: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A8238: jr          $ra
    // 0x800A823C: sh          $t6, 0x7636($at)
    MEM_H(0X7636, ctx->r1) = ctx->r14;
    return;
    // 0x800A823C: sh          $t6, 0x7636($at)
    MEM_H(0X7636, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_8080432C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080432C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80804330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804334: jal         0x80807BB8
    // 0x80804338: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80807BB8_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80804338: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080433C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80804340: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80804344: jal         0x80802754
    // 0x80804348: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_80802754_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80804348: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x8080434C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80804350: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80804354: jal         0x80804104
    // 0x80804358: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    func_80804104_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80804358: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080435C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804360: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80804364: jr          $ra
    // 0x80804368: nop

    return;
    // 0x80804368: nop

;}
RECOMP_FUNC void _bsbeemain_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082890: syscall     17
    recomp_syscall_handler(rdram, ctx, 0x80082890);
    return;
    // 0x80082894: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _chstatuebossbits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086730: syscall     362
    recomp_syscall_handler(rdram, ctx, 0x80086730);
    return;
    // 0x80086734: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808008B0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808008B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808008BC: lw          $t7, 0x188($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X188);
    // 0x808008C0: jal         0x800D9004
    // 0x808008C4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_800D9004(rdram, ctx);
        goto after_0;
    // 0x808008C4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x808008C8: lui         $at, 0x40B0
    ctx->r1 = S32(0X40B0 << 16);
    // 0x808008CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808008D0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x808008D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808008D8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808008DC: lwc1        $f4, 0x90($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X90);
    // 0x808008E0: sub.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x808008E4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x808008E8: jal         0x80800900
    // 0x808008EC: nop

    func_80800900_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x808008EC: nop

    after_1:
    // 0x808008F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808008F8: jr          $ra
    // 0x808008FC: nop

    return;
    // 0x808008FC: nop

;}
RECOMP_FUNC void func_808014F8_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808014FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801500: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801504: jal         0x800A89F8
    // 0x80801508: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800A89F8(rdram, ctx);
        goto after_0;
    // 0x80801508: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080150C: jal         0x800A9478
    // 0x80801510: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800A9478(rdram, ctx);
        goto after_1;
    // 0x80801510: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80801514: jal         0x800F5EF8
    // 0x80801518: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5EF8(rdram, ctx);
        goto after_2;
    // 0x80801518: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8080151C: jal         0x80110024
    // 0x80801520: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110024(rdram, ctx);
        goto after_3;
    // 0x80801520: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80801524: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801528: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8080152C: jal         0x80089538
    // 0x80801530: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    _ncpod_entrypoint_15(rdram, ctx);
        goto after_4;
    // 0x80801530: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x80801534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801538: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080153C: jr          $ra
    // 0x80801540: nop

    return;
    // 0x80801540: nop

;}
RECOMP_FUNC void func_800A2058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2058: jr          $ra
    // 0x800A205C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x800A205C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_808009F0_chfriesstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808009F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808009F8: addiu       $at, $zero, 0x10E0
    ctx->r1 = ADD32(0, 0X10E0);
    // 0x808009FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A04: beq         $a1, $at, L_80800A28
    if (ctx->r5 == ctx->r1) {
        // 0x80800A08: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800A28;
    }
    // 0x80800A08: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800A0C: addiu       $at, $zero, 0x10FD
    ctx->r1 = ADD32(0, 0X10FD);
    // 0x80800A10: beq         $a1, $at, L_80800A50
    if (ctx->r5 == ctx->r1) {
        // 0x80800A14: addiu       $at, $zero, 0x110B
        ctx->r1 = ADD32(0, 0X110B);
            goto L_80800A50;
    }
    // 0x80800A14: addiu       $at, $zero, 0x110B
    ctx->r1 = ADD32(0, 0X110B);
    // 0x80800A18: beq         $a1, $at, L_80800A50
    if (ctx->r5 == ctx->r1) {
        // 0x80800A1C: nop
    
            goto L_80800A50;
    }
    // 0x80800A1C: nop

    // 0x80800A20: b           L_80800A6C
    // 0x80800A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800A6C;
    // 0x80800A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800A28:
    // 0x80800A28: jal         0x80085710
    // 0x80800A2C: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800A2C: nop

    after_0:
    // 0x80800A30: lhu         $t6, 0x6E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A3C: andi        $t7, $t6, 0xFE00
    ctx->r15 = ctx->r14 & 0XFE00;
    // 0x80800A40: jal         0x80102424
    // 0x80800A44: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800A44: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
    after_1:
    // 0x80800A48: b           L_80800ADC
    // 0x80800A4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800ADC;
    // 0x80800A4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A50:
    // 0x80800A50: jal         0x8008FC9C
    // 0x80800A54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8008FC9C(rdram, ctx);
        goto after_2;
    // 0x80800A54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80800A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A5C: jal         0x80102424
    // 0x80800A60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x80800A60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800A64: b           L_80800ADC
    // 0x80800A68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800ADC;
    // 0x80800A68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A6C:
    // 0x80800A6C: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x80800A70: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(940, 0XE50) << 16);
    // 0x80800A74: addiu       $a2, $a2, 0xE50
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(940, 0XE50));
    // 0x80800A78: beql        $t8, $zero, L_80800ABC
    if (ctx->r24 == 0) {
        // 0x80800A7C: lhu         $t9, 0x6E($s0)
        ctx->r25 = MEM_HU(ctx->r16, 0X6E);
            goto L_80800ABC;
    }
    goto skip_0;
    // 0x80800A7C: lhu         $t9, 0x6E($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6E);
    skip_0:
    // 0x80800A80: jal         0x8008A1F8
    // 0x80800A84: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x80800A84: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_4:
    // 0x80800A88: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A8C: bne         $v0, $at, L_80800AB8
    if (ctx->r2 != ctx->r1) {
        // 0x80800A90: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AB8;
    }
    // 0x80800A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A94: jal         0x80102424
    // 0x80800A98: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x80800A98: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x80800A9C: jal         0x80106790
    // 0x80800AA0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_6;
    // 0x80800AA0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_6:
    // 0x80800AA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800AA8: jal         0x80102424
    // 0x80800AAC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x80800AAC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x80800AB0: b           L_80800ADC
    // 0x80800AB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800ADC;
    // 0x80800AB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800AB8:
    // 0x80800AB8: lhu         $t9, 0x6E($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6E);
L_80800ABC:
    // 0x80800ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800AC4: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x80800AC8: jal         0x80102424
    // 0x80800ACC: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x80800ACC: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
    after_8:
    // 0x80800AD0: jal         0x80090708
    // 0x80800AD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_9;
    // 0x80800AD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x80800AD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800ADC:
    // 0x80800ADC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800AE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800AE4: jr          $ra
    // 0x80800AE8: nop

    return;
    // 0x80800AE8: nop

;}
RECOMP_FUNC void func_800BA5BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA5BC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800BA5C0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800BA5C4: swc1        $f12, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f12.u32l;
    // 0x800BA5C8: jr          $ra
    // 0x800BA5CC: swc1        $f14, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->f14.u32l;
    return;
    // 0x800BA5CC: swc1        $f14, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->f14.u32l;
;}
