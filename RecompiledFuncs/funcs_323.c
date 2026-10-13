#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800F832C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F832C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F8330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F8334: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F8338: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F833C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F8340: jal         0x800F45E0
    // 0x800F8344: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800F45E0(rdram, ctx);
        goto after_0;
    // 0x800F8344: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F8348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F834C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F8350: jr          $ra
    // 0x800F8354: nop

    return;
    // 0x800F8354: nop

;}
RECOMP_FUNC void func_800EBB74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EBB74: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800EBB78: addiu       $t6, $t6, 0x2ED0
    ctx->r14 = ADD32(ctx->r14, 0X2ED0);
    // 0x800EBB7C: beq         $t6, $zero, L_800EBB8C
    if (ctx->r14 == 0) {
        // 0x800EBB80: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800EBB8C;
    }
    // 0x800EBB80: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800EBB84: jr          $ra
    // 0x800EBB88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800EBB88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EBB8C:
    // 0x800EBB8C: jr          $ra
    // 0x800EBB90: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800EBB90: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80104580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104580: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80104584: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80104588: jal         0x801043D8
    // 0x8010458C: nop

    func_801043D8(rdram, ctx);
        goto after_0;
    // 0x8010458C: nop

    after_0:
    // 0x80104590: beql        $v0, $zero, L_801045A0
    if (ctx->r2 == 0) {
        // 0x80104594: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801045A0;
    }
    goto skip_0;
    // 0x80104594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80104598: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x8010459C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801045A0:
    // 0x801045A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801045A4: jr          $ra
    // 0x801045A8: nop

    return;
    // 0x801045A8: nop

;}
RECOMP_FUNC void func_808010A8_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808010AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808010B4: jal         0x80082840
    // 0x808010B8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsbee_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808010B8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x808010BC: jal         0x800839E8
    // 0x808010C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x808010C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808010C4: beql        $v0, $zero, L_808010DC
    if (ctx->r2 == 0) {
        // 0x808010C8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808010DC;
    }
    goto skip_0;
    // 0x808010C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x808010CC: jal         0x800839B0
    // 0x808010D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bsrest_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x808010D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808010D4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808010D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_808010DC:
    // 0x808010DC: jal         0x8009E5C8
    // 0x808010E0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x808010E0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x808010E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808010E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808010EC: jr          $ra
    // 0x808010F0: nop

    return;
    // 0x808010F0: nop

;}
RECOMP_FUNC void _chpodiumbankaz_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800872B0: syscall     545
    recomp_syscall_handler(rdram, ctx, 0x800872B0);
    return;
    // 0x800872B4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080000C_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800010: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(1700, 0X24B4) << 16);
    // 0x80800014: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x80800018: lw          $v1, 0x24B4($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(1700, 0X24B4));
    // 0x8080001C: lui         $at, 0xB000
    ctx->r1 = S32(0XB000 << 16);
    // 0x80800020: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800024: andi        $a3, $v1, 0xFFFF
    ctx->r7 = ctx->r3 & 0XFFFF;
    // 0x80800028: addu        $a3, $a3, $at
    ctx->r7 = ADD32(ctx->r7, ctx->r1);
    // 0x8080002C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800030: and         $a2, $v1, $at
    ctx->r6 = ctx->r3 & ctx->r1;
    // 0x80800034: srl         $t7, $a2, 16
    ctx->r15 = S32(U32(ctx->r6) >> 16);
    // 0x80800038: andi        $t8, $a3, 0x2
    ctx->r24 = ctx->r7 & 0X2;
    // 0x8080003C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800040: beq         $t8, $zero, L_80800078
    if (ctx->r24 == 0) {
        // 0x80800044: or          $a2, $t7, $zero
        ctx->r6 = ctx->r15 | 0;
            goto L_80800078;
    }
    // 0x80800044: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80800048: srl         $a0, $a3, 2
    ctx->r4 = S32(U32(ctx->r7) >> 2);
    // 0x8080004C: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80800050: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80800054: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800058: jal         0x8001E210
    // 0x8080005C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    rom_read_word(rdram, ctx);
        goto after_0;
    // 0x8080005C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_0:
    // 0x80800060: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80800064: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800068: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8080006C: and         $t0, $v1, $at
    ctx->r8 = ctx->r3 & ctx->r1;
    // 0x80800070: b           L_80800098
    // 0x80800074: srl         $v1, $t0, 16
    ctx->r3 = S32(U32(ctx->r8) >> 16);
        goto L_80800098;
    // 0x80800074: srl         $v1, $t0, 16
    ctx->r3 = S32(U32(ctx->r8) >> 16);
L_80800078:
    // 0x80800078: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080007C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800080: jal         0x8001E210
    // 0x80800084: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    rom_read_word(rdram, ctx);
        goto after_1;
    // 0x80800084: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800088: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8080008C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800090: andi        $t2, $v1, 0xFFFF
    ctx->r10 = ctx->r3 & 0XFFFF;
    // 0x80800094: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
L_80800098:
    // 0x80800098: beq         $a2, $zero, L_808000FC
    if (ctx->r6 == 0) {
        // 0x8080009C: lui         $at, 0xB000
        ctx->r1 = S32(0XB000 << 16);
            goto L_808000FC;
    }
    // 0x8080009C: lui         $at, 0xB000
    ctx->r1 = S32(0XB000 << 16);
    // 0x808000A0: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x808000A4: andi        $t3, $a2, 0x2
    ctx->r11 = ctx->r6 & 0X2;
    // 0x808000A8: beq         $t3, $zero, L_808000E0
    if (ctx->r11 == 0) {
        // 0x808000AC: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_808000E0;
    }
    // 0x808000AC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808000B0: srl         $t4, $a2, 2
    ctx->r12 = S32(U32(ctx->r6) >> 2);
    // 0x808000B4: sll         $a0, $t4, 2
    ctx->r4 = S32(ctx->r12 << 2);
    // 0x808000B8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808000BC: jal         0x8001E210
    // 0x808000C0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    rom_read_word(rdram, ctx);
        goto after_2;
    // 0x808000C0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x808000C4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808000C8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x808000CC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x808000D0: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x808000D4: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x808000D8: b           L_808000FC
    // 0x808000DC: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
        goto L_808000FC;
    // 0x808000DC: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
L_808000E0:
    // 0x808000E0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808000E4: jal         0x8001E210
    // 0x808000E8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    rom_read_word(rdram, ctx);
        goto after_3;
    // 0x808000E8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_3:
    // 0x808000EC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x808000F0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x808000F4: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x808000F8: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
L_808000FC:
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800100: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800104: addiu       $v0, $v1, 0xA0
    ctx->r2 = ADD32(ctx->r3, 0XA0);
    // 0x80800108: jr          $ra
    // 0x8080010C: nop

    return;
    // 0x8080010C: nop

;}
RECOMP_FUNC void bsbeggass_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    // 0x80800014: jal         0x8008CDB8
    // 0x80800018: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_playForDuration_once(rdram, ctx);
        goto after_0;
    // 0x80800018: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_0:
    // 0x8080001C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800020: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800028: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080002C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800030: jal         0x8009FFD8
    // 0x80800034: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800034: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080003C: lui         $a1, 0x43AF
    ctx->r5 = S32(0X43AF << 16);
    // 0x80800040: jal         0x8009C99C
    // 0x80800044: lui         $a2, 0x4160
    ctx->r6 = S32(0X4160 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_2;
    // 0x80800044: lui         $a2, 0x4160
    ctx->r6 = S32(0X4160 << 16);
    after_2:
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080004C: jal         0x8009B9B0
    // 0x80800050: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800050: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800058: jal         0x800A0CDC
    // 0x8080005C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CDC(rdram, ctx);
        goto after_4;
    // 0x8080005C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800060: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800064: sw          $v0, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r2;
    // 0x80800068: sw          $v0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r2;
    // 0x8080006C: jal         0x80094510
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094510(rdram, ctx);
        goto after_5;
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800074: sw          $v0, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r2;
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080007C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800080: jal         0x80098140
    // 0x80800084: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bainput_enable(rdram, ctx);
        goto after_6;
    // 0x80800084: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80800088: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080008C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800090: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800094: jr          $ra
    // 0x80800098: nop

    return;
    // 0x80800098: nop

;}
RECOMP_FUNC void func_808003C4_ch2dbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808003C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003CC: jal         0x8008A110
    // 0x808003D0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    _sucoaster_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808003D0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x808003D4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x808003D8: jal         0x800EE88C
    // 0x808003DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800EE88C(rdram, ctx);
        goto after_1;
    // 0x808003DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x808003E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808003E4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x808003E8: jal         0x800EFC7C
    // 0x808003EC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EFC7C(rdram, ctx);
        goto after_2;
    // 0x808003EC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_2:
    // 0x808003F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1356, 0X8FC) << 16);
    // 0x808003F4: lwc1        $f4, 0x8FC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1356, 0X8FC));
    // 0x808003F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808003FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800400: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800404: nop

    // 0x80800408: bc1f        L_80800414
    if (!c1cs) {
        // 0x8080040C: nop
    
            goto L_80800414;
    }
    // 0x8080040C: nop

    // 0x80800410: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800414:
    // 0x80800414: jr          $ra
    // 0x80800418: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800418: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80015A70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015A70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80015A74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80015A78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80015A7C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80015A80: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80015A84: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80015A88: jal         0x80015860
    // 0x80015A8C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_80015860(rdram, ctx);
        goto after_0;
    // 0x80015A8C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80015A90: jal         0x80015828
    // 0x80015A94: nop

    func_80015828(rdram, ctx);
        goto after_1;
    // 0x80015A94: nop

    after_1:
    // 0x80015A98: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80015A9C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80015AA0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80015AA4: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x80015AA8: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80015AAC: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80015AB0: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80015AB4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80015AB8: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80015ABC: addiu       $t9, $t9, -0x6848
    ctx->r25 = ADD32(ctx->r25, -0X6848);
    // 0x80015AC0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80015AC4: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80015AC8: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x80015ACC: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x80015AD0: addiu       $v1, $zero, 0x1FF
    ctx->r3 = ADD32(0, 0X1FF);
    // 0x80015AD4: sh          $v1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r3;
    // 0x80015AD8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80015ADC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80015AE0: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
    // 0x80015AE4: sh          $v1, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r3;
    // 0x80015AE8: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x80015AEC: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
    // 0x80015AF0: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // 0x80015AF4: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80015AF8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80015AFC: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    // 0x80015B00: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80015B04: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80015B08: sh          $t3, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r11;
    // 0x80015B0C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80015B10: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x80015B14: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x80015B18: sh          $t5, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r13;
    // 0x80015B1C: jal         0x8002E660
    // 0x80015B20: sh          $t7, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r15;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_2;
    // 0x80015B20: sh          $t7, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r15;
    after_2:
    // 0x80015B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015B28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80015B2C: jr          $ra
    // 0x80015B30: nop

    return;
    // 0x80015B30: nop

;}
RECOMP_FUNC void func_80800A10_chbubbleelevator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A10: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800A14: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800A18: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800A1C: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80800A20: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800A24: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800A28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A2C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800A30: beql        $t7, $at, L_80800BAC
    if (ctx->r15 == ctx->r1) {
        // 0x80800A34: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800BAC;
    }
    goto skip_0;
    // 0x80800A34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800A38: jal         0x800D90A4
    // 0x80800A3C: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    func_800D90A4(rdram, ctx);
        goto after_0;
    // 0x80800A3C: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_0:
    // 0x80800A40: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800A44: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800A48: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800A4C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800A50: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800A54: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800A58: jal         0x800F10B4
    // 0x80800A5C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800A5C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80800A60: jal         0x800D8FF8
    // 0x80800A64: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80800A64: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80800A68: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800A6C: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800A70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800A74: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800A78: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800A7C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800A80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800A84: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800A88: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    // 0x80800A8C: lwc1        $f2, 0x54($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800A90: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80800A94: nop

    // 0x80800A98: bc1f        L_80800AAC
    if (!c1cs) {
        // 0x80800A9C: nop
    
            goto L_80800AAC;
    }
    // 0x80800A9C: nop

    // 0x80800AA0: sub.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x80800AA4: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    // 0x80800AA8: lwc1        $f2, 0x54($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X54);
L_80800AAC:
    // 0x80800AAC: mul.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80800AB0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2368, 0XC1C) << 16);
    // 0x80800AB4: lwc1        $f8, 0xC1C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2368, 0XC1C));
    // 0x80800AB8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800ABC: lui         $a3, 0x3D99
    ctx->r7 = S32(0X3D99 << 16);
    // 0x80800AC0: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800AC4: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    // 0x80800AC8: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x80800ACC: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800AD0: jal         0x800F10B4
    // 0x80800AD4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80800AD4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80800AD8: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80800ADC: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80800AE0: jal         0x800EE7F8
    // 0x80800AE4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80800AE4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x80800AE8: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x80800AEC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800AF0: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800AF4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80800AF8: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80800AFC: jal         0x800E3980
    // 0x80800B00: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    func_800E3980(rdram, ctx);
        goto after_5;
    // 0x80800B00: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x80800B04: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80800B08: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800B0C: jal         0x800F18FC
    // 0x80800B10: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_800F18FC(rdram, ctx);
        goto after_6;
    // 0x80800B10: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_6:
    // 0x80800B14: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80800B18: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80800B1C: jal         0x800EEBF0
    // 0x80800B20: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    func_800EEBF0(rdram, ctx);
        goto after_7;
    // 0x80800B20: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    after_7:
    // 0x80800B24: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80800B28: jal         0x800EF04C
    // 0x80800B2C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800EF04C(rdram, ctx);
        goto after_8;
    // 0x80800B2C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_8:
    // 0x80800B30: jal         0x80013970
    // 0x80800B34: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    func_80013970(rdram, ctx);
        goto after_9;
    // 0x80800B34: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    after_9:
    // 0x80800B38: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80800B3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800B40: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800B44: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800B48: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80800B4C: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800B50: jal         0x800138D0
    // 0x80800B54: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    func_800138D0(rdram, ctx);
        goto after_10;
    // 0x80800B54: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    after_10:
    // 0x80800B58: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80800B5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800B60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800B64: mul.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800B68: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x80800B6C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800B70: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80800B74: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80800B78: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x80800B7C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800B80: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x80800B84: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x80800B88: jal         0x80087748
    // 0x80800B8C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    _chbubble_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x80800B8C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_11:
    // 0x80800B90: lbu         $t1, 0x7E($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X7E);
    // 0x80800B94: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x80800B98: andi        $t0, $t9, 0x10
    ctx->r8 = ctx->r25 & 0X10;
    // 0x80800B9C: andi        $t2, $t1, 0xFFEF
    ctx->r10 = ctx->r9 & 0XFFEF;
    // 0x80800BA0: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80800BA4: sb          $t3, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r11;
    // 0x80800BA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800BAC:
    // 0x80800BAC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800BB0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800BB4: jr          $ra
    // 0x80800BB8: nop

    return;
    // 0x80800BB8: nop

;}
RECOMP_FUNC void func_80800444_bsmummove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800444: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800448: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080044C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800450: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800454: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800458: jal         0x8009EF04
    // 0x8080045C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    bastick_distance(rdram, ctx);
        goto after_0;
    // 0x8080045C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x80800460: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800464: nop

    // 0x80800468: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8080046C: nop

    // 0x80800470: bc1fl       L_80800490
    if (!c1cs) {
        // 0x80800474: lui         $a1, 0x3EF0
        ctx->r5 = S32(0X3EF0 << 16);
            goto L_80800490;
    }
    goto skip_0;
    // 0x80800474: lui         $a1, 0x3EF0
    ctx->r5 = S32(0X3EF0 << 16);
    skip_0:
    // 0x80800478: jal         0x8009C984
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_1;
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800480: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800484: jal         0x8009C914
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_2;
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080048C: lui         $a1, 0x3EF0
    ctx->r5 = S32(0X3EF0 << 16);
L_80800490:
    // 0x80800490: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800498: jal         0x800A2CE8
    // 0x8080049C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2CE8(rdram, ctx);
        goto after_3;
    // 0x8080049C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x808004A0: lui         $a1, 0x3F78
    ctx->r5 = S32(0X3F78 << 16);
    // 0x808004A4: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004AC: jal         0x800A2CE8
    // 0x808004B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_4;
    // 0x808004B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_4:
    // 0x808004B4: jal         0x80083860
    // 0x808004B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsmum_entrypoint_13(rdram, ctx);
        goto after_5;
    // 0x808004B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808004BC: jal         0x8009EF10
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_6;
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808004C4: beq         $v0, $zero, L_808004DC
    if (ctx->r2 == 0) {
        // 0x808004C8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808004DC;
    }
    // 0x808004C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808004CC: beql        $v0, $at, L_808004FC
    if (ctx->r2 == ctx->r1) {
        // 0x808004D0: addiu       $s1, $zero, 0xE7
        ctx->r17 = ADD32(0, 0XE7);
            goto L_808004FC;
    }
    goto skip_1;
    // 0x808004D0: addiu       $s1, $zero, 0xE7
    ctx->r17 = ADD32(0, 0XE7);
    skip_1:
    // 0x808004D4: b           L_808004FC
    // 0x808004D8: nop

        goto L_808004FC;
    // 0x808004D8: nop

L_808004DC:
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E0: jal         0x8009BCD4
    // 0x808004E4: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_7;
    // 0x808004E4: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_7:
    // 0x808004E8: beq         $v0, $zero, L_808004FC
    if (ctx->r2 == 0) {
        // 0x808004EC: nop
    
            goto L_808004FC;
    }
    // 0x808004EC: nop

    // 0x808004F0: b           L_808004FC
    // 0x808004F4: addiu       $s1, $zero, 0xE5
    ctx->r17 = ADD32(0, 0XE5);
        goto L_808004FC;
    // 0x808004F4: addiu       $s1, $zero, 0xE5
    ctx->r17 = ADD32(0, 0XE5);
    // 0x808004F8: addiu       $s1, $zero, 0xE7
    ctx->r17 = ADD32(0, 0XE7);
L_808004FC:
    // 0x808004FC: jal         0x8008DD04
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_8;
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800504: beq         $v0, $zero, L_80800510
    if (ctx->r2 == 0) {
        // 0x80800508: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800510;
    }
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080050C: addiu       $s1, $zero, 0xE9
    ctx->r17 = ADD32(0, 0XE9);
L_80800510:
    // 0x80800510: jal         0x80091A58
    // 0x80800514: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_9;
    // 0x80800514: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_9:
    // 0x80800518: beq         $v0, $zero, L_80800524
    if (ctx->r2 == 0) {
        // 0x8080051C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800524;
    }
    // 0x8080051C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800520: addiu       $s1, $zero, 0xF7
    ctx->r17 = ADD32(0, 0XF7);
L_80800524:
    // 0x80800524: jal         0x80091A58
    // 0x80800528: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_10;
    // 0x80800528: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_10:
    // 0x8080052C: beq         $v0, $zero, L_80800538
    if (ctx->r2 == 0) {
        // 0x80800530: nop
    
            goto L_80800538;
    }
    // 0x80800530: nop

    // 0x80800534: addiu       $s1, $zero, 0xE8
    ctx->r17 = ADD32(0, 0XE8);
L_80800538:
    // 0x80800538: jal         0x8008E148
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_11;
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800540: beq         $v0, $zero, L_80800554
    if (ctx->r2 == 0) {
        // 0x80800544: nop
    
            goto L_80800554;
    }
    // 0x80800544: nop

    // 0x80800548: jal         0x800848B0
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_12;
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800550: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80800554:
    // 0x80800554: jal         0x8008E35C
    // 0x80800558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_13;
    // 0x80800558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8080055C: beq         $v0, $zero, L_80800568
    if (ctx->r2 == 0) {
        // 0x80800560: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800568;
    }
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800564: addiu       $s1, $zero, 0xF0
    ctx->r17 = ADD32(0, 0XF0);
L_80800568:
    // 0x80800568: jal         0x8009E5C8
    // 0x8080056C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    bs_setState(rdram, ctx);
        goto after_14;
    // 0x8080056C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_14:
    // 0x80800570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800574: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800578: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080057C: jr          $ra
    // 0x80800580: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800580: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800F4648(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4648: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F464C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4650: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800F4654: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800F4658: jal         0x8009C128
    // 0x800F465C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x800F465C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800F4660: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800F4664: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800F4668: jal         0x800EFB24
    // 0x800F466C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x800F466C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x800F4670: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800F4674: jal         0x8009C1F8
    // 0x800F4678: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_8009C1F8(rdram, ctx);
        goto after_2;
    // 0x800F4678: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x800F467C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4680: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800F4684: jr          $ra
    // 0x800F4688: nop

    return;
    // 0x800F4688: nop

;}
RECOMP_FUNC void chbabydino_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(848, 0X770) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x770
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(848, 0X770));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x770
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(848, 0X770));
;}
RECOMP_FUNC void _chusefeather_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085958: syscall     182
    recomp_syscall_handler(rdram, ctx, 0x80085958);
    return;
    // 0x8008595C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void chbaddiesetup_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080064C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800650: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800654: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800658: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8080065C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800660: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800664: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800668: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080066C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800670: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800674: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80800678: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8080067C: jal         0x800858D8
    // 0x80800680: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    _chbounce_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800680: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80800684: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800688: jal         0x800858F8
    // 0x8080068C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    _chbounce_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x8080068C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80800690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800694: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800698: jr          $ra
    // 0x8080069C: nop

    return;
    // 0x8080069C: nop

;}
RECOMP_FUNC void func_80801990_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801990: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801994: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801998: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080199C: jal         0x808004CC
    // 0x808019A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bstrexsmall_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808019A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808019A4: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x808019A8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808019AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019B0: jal         0x8008CB3C
    // 0x808019B4: addiu       $a1, $zero, 0x1CE
    ctx->r5 = ADD32(0, 0X1CE);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x808019B4: addiu       $a1, $zero, 0x1CE
    ctx->r5 = ADD32(0, 0X1CE);
    after_1:
    // 0x808019B8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808019BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808019C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808019C8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808019CC: jal         0x8009FFD8
    // 0x808019D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x808019D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x808019D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019D8: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x808019DC: jal         0x8009C99C
    // 0x808019E0: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_3;
    // 0x808019E0: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    after_3:
    // 0x808019E4: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808019E8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808019EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019F0: jal         0x8008C9BC
    // 0x808019F4: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_4;
    // 0x808019F4: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_4:
    // 0x808019F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(416, 0X1AE4) << 16);
    // 0x808019FC: lwc1        $f4, 0x1AE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(416, 0X1AE4));
    // 0x80801A00: lui         $a3, 0x3F93
    ctx->r7 = S32(0X3F93 << 16);
    // 0x80801A04: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80801A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A0C: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80801A10: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x80801A14: jal         0x8008C9F0
    // 0x80801A18: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_5;
    // 0x80801A18: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x80801A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A20: jal         0x8008CA30
    // 0x80801A24: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8008CA30(rdram, ctx);
        goto after_6;
    // 0x80801A24: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_6:
    // 0x80801A28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801A2C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801A30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801A34: jr          $ra
    // 0x80801A38: nop

    return;
    // 0x80801A38: nop

;}
RECOMP_FUNC void func_8009EA88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EA88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EA8C: jr          $ra
    // 0x8009EA90: lwc1        $f0, 0x7070($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7070);
    return;
    // 0x8009EA90: lwc1        $f0, 0x7070($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7070);
;}
RECOMP_FUNC void _dbskeleton_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087A20: syscall     649
    recomp_syscall_handler(rdram, ctx, 0x80087A20);
    return;
    // 0x80087A24: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800F2EE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2EE0: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800F2EE4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800F2EE8: lbu         $t7, 0x1($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1);
    // 0x800F2EEC: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800F2EF0: lbu         $t8, 0x2($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2);
    // 0x800F2EF4: jr          $ra
    // 0x800F2EF8: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    return;
    // 0x800F2EF8: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_8008FE3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FE3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FE40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FE44: jal         0x800F54E4
    // 0x8008FE48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FE48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008FE4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FE50: jal         0x800F57F0
    // 0x8008FE54: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F57F0(rdram, ctx);
        goto after_1;
    // 0x8008FE54: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008FE58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FE5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FE60: jr          $ra
    // 0x8008FE64: nop

    return;
    // 0x8008FE64: nop

;}
RECOMP_FUNC void gcsectionDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001E0: jal         0x808000F0
    // 0x808001E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808000F0_gcsectionDll(rdram, ctx);
        goto after_0;
    // 0x808001E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808001E8: beq         $v0, $zero, L_808001F8
    if (ctx->r2 == 0) {
        // 0x808001EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001F8;
    }
    // 0x808001EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001F0: b           L_808001FC
    // 0x808001F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001FC;
    // 0x808001F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001F8:
    // 0x808001F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001FC:
    // 0x808001FC: jr          $ra
    // 0x80800200: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800200: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800204: nop

    // 0x80800208: nop

    // 0x8080020C: nop

;}
RECOMP_FUNC void ncbaswim_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080001C: jal         0x801124D0
    // 0x80800020: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_801124D0(rdram, ctx);
        goto after_0;
    // 0x80800020: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800024: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800028: jal         0x80115858
    // 0x8080002C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80115858(rdram, ctx);
        goto after_1;
    // 0x8080002C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800030: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800034: jal         0x80115870
    // 0x80800038: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80115870(rdram, ctx);
        goto after_2;
    // 0x80800038: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x8080003C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800044: jr          $ra
    // 0x80800048: nop

    return;
    // 0x80800048: nop

;}
RECOMP_FUNC void chswitch_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800688: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080068C: jr          $ra
    // 0x80800690: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    return;
    // 0x80800690: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void bsbwhirl_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F1C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80800F20: jal         0x80800EA0
    // 0x80800F24: addiu       $a1, $a1, -0x646C
    ctx->r5 = ADD32(ctx->r5, -0X646C);
    func_80800EA0_bsbwhirl(rdram, ctx);
        goto after_0;
    // 0x80800F24: addiu       $a1, $a1, -0x646C
    ctx->r5 = ADD32(ctx->r5, -0X646C);
    after_0:
    // 0x80800F28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F30: jr          $ra
    // 0x80800F34: nop

    return;
    // 0x80800F34: nop

    // 0x80800F38: nop

    // 0x80800F3C: nop

;}
RECOMP_FUNC void badust_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B88: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x80800B8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800B90: beq         $a1, $at, L_80800BF8
    if (ctx->r5 == ctx->r1) {
        // 0x80800B94: sw          $a1, 0x0($t6)
        MEM_W(0X0, ctx->r14) = ctx->r5;
            goto L_80800BF8;
    }
    // 0x80800B94: sw          $a1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r5;
    // 0x80800B98: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800B9C: beq         $a1, $at, L_80800BB8
    if (ctx->r5 == ctx->r1) {
        // 0x80800BA0: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80800BB8;
    }
    // 0x80800BA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800BA4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800BA8: beq         $a1, $at, L_80800BE8
    if (ctx->r5 == ctx->r1) {
        // 0x80800BAC: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80800BE8;
    }
    // 0x80800BAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800BB0: b           L_80800C08
    // 0x80800BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C08;
    // 0x80800BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BB8:
    // 0x80800BB8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800BBC: jal         0x8009ADF0
    // 0x80800BC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009ADF0(rdram, ctx);
        goto after_0;
    // 0x80800BC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800BC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800BC8: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x80800BCC: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80800BD0: lw          $t7, 0x5C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X5C);
    // 0x80800BD4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800BD8: jal         0x80085338
    // 0x80800BDC: sb          $zero, 0x9($t7)
    MEM_B(0X9, ctx->r15) = 0;
    _batimer_set(rdram, ctx);
        goto after_1;
    // 0x80800BDC: sb          $zero, 0x9($t7)
    MEM_B(0X9, ctx->r15) = 0;
    after_1:
    // 0x80800BE0: b           L_80800C08
    // 0x80800BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C08;
    // 0x80800BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BE8:
    // 0x80800BE8: jal         0x8009ADF0
    // 0x80800BEC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8009ADF0(rdram, ctx);
        goto after_2;
    // 0x80800BEC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800BF0: b           L_80800C08
    // 0x80800BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C08;
    // 0x80800BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BF8:
    // 0x80800BF8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800BFC: jal         0x8009ADF0
    // 0x80800C00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8009ADF0(rdram, ctx);
        goto after_3;
    // 0x80800C00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80800C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C08:
    // 0x80800C08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C0C: jr          $ra
    // 0x80800C10: nop

    return;
    // 0x80800C10: nop

;}
RECOMP_FUNC void func_800BEA88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEA88: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BEA8C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800BEA90: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BEA94: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800BEA98: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BEA9C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BEAA0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800BEAA4: jr          $ra
    // 0x800BEAA8: lw          $v0, -0x7A4C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7A4C);
    return;
    // 0x800BEAA8: lw          $v0, -0x7A4C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7A4C);
;}
RECOMP_FUNC void chfactoryliftdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1132, 0X140) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x140
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1132, 0X140));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x140
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1132, 0X140));
;}
RECOMP_FUNC void gspropmarker_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800008: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8080000C: beq         $a0, $zero, L_808000A8
    if (ctx->r4 == 0) {
        // 0x80800010: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_808000A8;
    }
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: jal         0x800E9DC4
    // 0x80800018: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800E9DC4(rdram, ctx);
        goto after_0;
    // 0x80800018: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080001C: beql        $v0, $zero, L_808000AC
    if (ctx->r2 == 0) {
        // 0x80800020: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808000AC;
    }
    goto skip_0;
    // 0x80800020: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800024: jal         0x800E9D68
    // 0x80800028: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800E9D68(rdram, ctx);
        goto after_1;
    // 0x80800028: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8080002C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800030: jal         0x800E9D90
    // 0x80800034: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800E9D90(rdram, ctx);
        goto after_2;
    // 0x80800034: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800038: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8080003C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800040: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80800044: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80800048: beq         $at, $zero, L_808000A8
    if (ctx->r1 == 0) {
        // 0x8080004C: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_808000A8;
    }
    // 0x8080004C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800050: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800054: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
L_80800058:
    // 0x80800058: andi        $a0, $v0, 0x1
    ctx->r4 = ctx->r2 & 0X1;
    // 0x8080005C: beq         $a2, $a0, L_80800078
    if (ctx->r6 == ctx->r4) {
        // 0x80800060: sll         $t8, $v0, 25
        ctx->r24 = S32(ctx->r2 << 25);
            goto L_80800078;
    }
    // 0x80800060: sll         $t8, $v0, 25
    ctx->r24 = S32(ctx->r2 << 25);
    // 0x80800064: bnel        $a0, $zero, L_8080009C
    if (ctx->r4 != 0) {
        // 0x80800068: addiu       $v1, $v1, 0x14
        ctx->r3 = ADD32(ctx->r3, 0X14);
            goto L_8080009C;
    }
    goto skip_1;
    // 0x80800068: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    skip_1:
    // 0x8080006C: lbu         $t6, 0x12($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X12);
    // 0x80800070: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80800074: bne         $a3, $t7, L_80800098
    if (ctx->r7 != ctx->r15) {
        // 0x80800078: srl         $t9, $t8, 26
        ctx->r25 = S32(U32(ctx->r24) >> 26);
            goto L_80800098;
    }
L_80800078:
    // 0x80800078: srl         $t9, $t8, 26
    ctx->r25 = S32(U32(ctx->r24) >> 26);
    // 0x8080007C: bnel        $t0, $t9, L_8080009C
    if (ctx->r8 != ctx->r25) {
        // 0x80800080: addiu       $v1, $v1, 0x14
        ctx->r3 = ADD32(ctx->r3, 0X14);
            goto L_8080009C;
    }
    goto skip_2;
    // 0x80800080: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    skip_2:
    // 0x80800084: lhu         $t1, 0x8($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X8);
    // 0x80800088: bnel        $s0, $t1, L_8080009C
    if (ctx->r16 != ctx->r9) {
        // 0x8080008C: addiu       $v1, $v1, 0x14
        ctx->r3 = ADD32(ctx->r3, 0X14);
            goto L_8080009C;
    }
    goto skip_3;
    // 0x8080008C: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    skip_3:
    // 0x80800090: b           L_808000AC
    // 0x80800094: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_808000AC;
    // 0x80800094: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800098:
    // 0x80800098: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
L_8080009C:
    // 0x8080009C: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x808000A0: bnel        $at, $zero, L_80800058
    if (ctx->r1 != 0) {
        // 0x808000A4: lw          $v0, 0x4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X4);
            goto L_80800058;
    }
    goto skip_4;
    // 0x808000A4: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    skip_4:
L_808000A8:
    // 0x808000A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000AC:
    // 0x808000AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000B8: jr          $ra
    // 0x808000BC: nop

    return;
    // 0x808000BC: nop

;}
RECOMP_FUNC void gczoombox_entrypoint_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808036A8: bnel        $a0, $zero, L_808036BC
    if (ctx->r4 != 0) {
        // 0x808036AC: lh          $v0, 0x1BC($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X1BC);
            goto L_808036BC;
    }
    goto skip_0;
    // 0x808036AC: lh          $v0, 0x1BC($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X1BC);
    skip_0:
    // 0x808036B0: jr          $ra
    // 0x808036B4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x808036B4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x808036B8: lh          $v0, 0x1BC($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X1BC);
L_808036BC:
    // 0x808036BC: jr          $ra
    // 0x808036C0: nop

    return;
    // 0x808036C0: nop

;}
RECOMP_FUNC void func_8009679C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009679C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800967A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800967A4: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x800967A8: jal         0x800C68DC
    // 0x800967AC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800C68DC(rdram, ctx);
        goto after_0;
    // 0x800967AC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x800967B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800967B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800967B8: jr          $ra
    // 0x800967BC: nop

    return;
    // 0x800967BC: nop

;}
RECOMP_FUNC void func_808001B4_chstonedartgunhead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001BC: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
    // 0x808001C0: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808001C4: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x808001C8: nop

    // 0x808001CC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x808001D0: lwc1        $f8, 0x2C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x808001D4: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
    // 0x808001D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808001DC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808001E0: jal         0x800136E4
    // 0x808001E4: add.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_0;
    // 0x808001E4: add.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f0.fl;
    after_0:
    // 0x808001E8: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808001EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808001F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1872, 0XDB0) << 16);
    // 0x808001F4: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    // 0x808001F8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x808001FC: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x80800200: nop

    // 0x80800204: beql        $t8, $t0, L_80800218
    if (ctx->r24 == ctx->r8) {
        // 0x80800208: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800218;
    }
    goto skip_0;
    // 0x80800208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080020C: lwc1        $f18, 0xDB0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1872, 0XDB0));
    // 0x80800210: swc1        $f18, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f18.u32l;
    // 0x80800214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800218:
    // 0x80800218: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080021C: jr          $ra
    // 0x80800220: nop

    return;
    // 0x80800220: nop

;}
RECOMP_FUNC void _ncbaspiral_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089198: syscall     764
    recomp_syscall_handler(rdram, ctx, 0x80089198);
    return;
    // 0x8008919C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80800038_ncpod(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800038: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080003C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800040: lbu         $t6, 0x42($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X42);
    // 0x80800044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800048: beql        $t6, $zero, L_80800060
    if (ctx->r14 == 0) {
        // 0x8080004C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800060;
    }
    goto skip_0;
    // 0x8080004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800050: sb          $zero, 0x42($a0)
    MEM_B(0X42, ctx->r4) = 0;
    // 0x80800054: jal         0x800F82D4
    // 0x80800058: lw          $a0, 0x38($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X38);
    func_800F82D4(rdram, ctx);
        goto after_0;
    // 0x80800058: lw          $a0, 0x38($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X38);
    after_0:
    // 0x8080005C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800060:
    // 0x80800060: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800064: jr          $ra
    // 0x80800068: nop

    return;
    // 0x80800068: nop

;}
RECOMP_FUNC void func_80800228_chpodiumbankaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800228: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080022C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800230: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800234: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800238: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8080023C: jal         0x800C6E38
    // 0x80800240: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x80800240: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_0:
    // 0x80800244: beql        $v0, $zero, L_80800308
    if (ctx->r2 == 0) {
        // 0x80800248: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800308;
    }
    goto skip_0;
    // 0x80800248: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080024C: jal         0x800F5410
    // 0x80800250: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_800F5410(rdram, ctx);
        goto after_1;
    // 0x80800250: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_1:
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800258: jal         0x80106790
    // 0x8080025C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x8080025C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800260: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80800264: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800268: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080026C: beq         $v1, $at, L_8080027C
    if (ctx->r3 == ctx->r1) {
        // 0x80800270: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8080027C;
    }
    // 0x80800270: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800274: bnel        $v1, $at, L_80800308
    if (ctx->r3 != ctx->r1) {
        // 0x80800278: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800308;
    }
    goto skip_1;
    // 0x80800278: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
L_8080027C:
    // 0x8080027C: lhu         $t6, 0x72($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X72);
    // 0x80800280: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800284: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800288: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080028C: beq         $t7, $at, L_808002B0
    if (ctx->r15 == ctx->r1) {
        // 0x80800290: addiu       $a1, $zero, 0x3A
        ctx->r5 = ADD32(0, 0X3A);
            goto L_808002B0;
    }
    // 0x80800290: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    // 0x80800294: lw          $a3, 0x48($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X48);
    // 0x80800298: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x8080029C: jal         0x800F7D38
    // 0x808002A0: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_800F7D38(rdram, ctx);
        goto after_3;
    // 0x808002A0: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x808002A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808002A8: bne         $v0, $at, L_80800304
    if (ctx->r2 != ctx->r1) {
        // 0x808002AC: lw          $v1, 0x38($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X38);
            goto L_80800304;
    }
    // 0x808002AC: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
L_808002B0:
    // 0x808002B0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808002B4: bne         $v1, $at, L_808002E0
    if (ctx->r3 != ctx->r1) {
        // 0x808002B8: lw          $a0, 0x44($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X44);
            goto L_808002E0;
    }
    // 0x808002B8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808002BC: jal         0x800F5A00
    // 0x808002C0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F5A00(rdram, ctx);
        goto after_4;
    // 0x808002C0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x808002C4: addiu       $t8, $zero, 0x1C
    ctx->r24 = ADD32(0, 0X1C);
    // 0x808002C8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808002CC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808002D0: lui         $a1, 0x42FA
    ctx->r5 = S32(0X42FA << 16);
    // 0x808002D4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808002D8: jal         0x80089F20
    // 0x808002DC: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x808002DC: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    after_5:
L_808002E0:
    // 0x808002E0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x808002E4: lbu         $t3, 0x79($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X79);
    // 0x808002E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002EC: sll         $t2, $t0, 4
    ctx->r10 = S32(ctx->r8 << 4);
    // 0x808002F0: andi        $t4, $t3, 0xFF0F
    ctx->r12 = ctx->r11 & 0XFF0F;
    // 0x808002F4: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x808002F8: sb          $t5, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r13;
    // 0x808002FC: jal         0x80101FDC
    // 0x80800300: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_6;
    // 0x80800300: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
L_80800304:
    // 0x80800304: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800308:
    // 0x80800308: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080030C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800310: jr          $ra
    // 0x80800314: nop

    return;
    // 0x80800314: nop

;}
RECOMP_FUNC void _fxrain_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088918: syscall     710
    recomp_syscall_handler(rdram, ctx, 0x80088918);
    return;
    // 0x8008891C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _chdragonbrothers_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086ED8: syscall     470
    recomp_syscall_handler(rdram, ctx, 0x80086ED8);
    return;
    // 0x80086EDC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void suflamefx_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080030C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800310: jr          $ra
    // 0x80800314: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x80800314: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void _chbaddieDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085920: syscall     181
    recomp_syscall_handler(rdram, ctx, 0x80085920);
    return;
    // 0x80085924: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800B8CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8CB0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8CB4: jr          $ra
    // 0x800B8CB8: sb          $a0, -0x7D39($at)
    MEM_B(-0X7D39, ctx->r1) = ctx->r4;
    return;
    // 0x800B8CB8: sb          $a0, -0x7D39($at)
    MEM_B(-0X7D39, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_80800488_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800488: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080048C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800490: jal         0x8009BA9C
    // 0x80800494: nop

    func_8009BA9C(rdram, ctx);
        goto after_0;
    // 0x80800494: nop

    after_0:
    // 0x80800498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080049C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004A0: jr          $ra
    // 0x808004A4: nop

    return;
    // 0x808004A4: nop

;}
RECOMP_FUNC void advance_crc_check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E8E4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001E8E8: lw          $v0, -0x1650($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1650);
    // 0x8001E8EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001E8F0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8001E8F4: bne         $v0, $at, L_8001E904
    if (ctx->r2 != ctx->r1) {
        // 0x8001E8F8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8001E904;
    }
    // 0x8001E8F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E8FC: b           L_8001EAA4
    // 0x8001E900: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8001EAA4;
    // 0x8001E900: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001E904:
    // 0x8001E904: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8001E908: lw          $t0, -0x1654($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X1654);
    // 0x8001E90C: lui         $v1, 0x0
    ctx->r3 = S32(0X0 << 16);
    // 0x8001E910: addiu       $v1, $v1, 0x50F0
    ctx->r3 = ADD32(ctx->r3, 0X50F0);
    // 0x8001E914: beq         $t0, $zero, L_8001EA08
    if (ctx->r8 == 0) {
        // 0x8001E918: sll         $t1, $v0, 3
        ctx->r9 = S32(ctx->r2 << 3);
            goto L_8001EA08;
    }
    // 0x8001E918: sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2 << 3);
    // 0x8001E91C: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x8001E920: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8001E924: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8001E928: lbu         $t7, 0x1195($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X1195);
    // 0x8001E92C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001E930: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001E934: lw          $a0, -0x165C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X165C);
    // 0x8001E938: lw          $a1, -0x1658($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X1658);
    // 0x8001E93C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8001E940: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x8001E944: beq         $t7, $zero, L_8001E974
    if (ctx->r15 == 0) {
        // 0x8001E948: sw          $a1, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r5;
            goto L_8001E974;
    }
    // 0x8001E948: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x8001E94C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001E950: lw          $a0, -0x1660($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1660);
    // 0x8001E954: jal         0x8001E210
    // 0x8001E958: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    rom_read_word(rdram, ctx);
        goto after_0;
    // 0x8001E958: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x8001E95C: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8001E960: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8001E964: lw          $a2, -0x1660($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X1660);
    // 0x8001E968: lw          $t0, -0x1654($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X1654);
    // 0x8001E96C: b           L_8001E984
    // 0x8001E970: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
        goto L_8001E984;
    // 0x8001E970: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
L_8001E974:
    // 0x8001E974: lw          $a2, -0x1660($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X1660);
    // 0x8001E978: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    // 0x8001E97C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8001E980: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_8001E984:
    // 0x8001E984: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8001E988: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x8001E98C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8001E990: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001E994: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8001E998: andi        $t9, $a0, 0x17
    ctx->r25 = ctx->r4 & 0X17;
    // 0x8001E99C: sllv        $t1, $v1, $t9
    ctx->r9 = S32(ctx->r3 << (ctx->r25 & 31));
    // 0x8001E9A0: lbu         $v1, 0x1($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X1);
    // 0x8001E9A4: xor         $a1, $a1, $t1
    ctx->r5 = ctx->r5 ^ ctx->r9;
    // 0x8001E9A8: addiu       $t8, $a2, 0x4
    ctx->r24 = ADD32(ctx->r6, 0X4);
    // 0x8001E9AC: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8001E9B0: andi        $t2, $a0, 0x17
    ctx->r10 = ctx->r4 & 0X17;
    // 0x8001E9B4: sllv        $t3, $v1, $t2
    ctx->r11 = S32(ctx->r3 << (ctx->r10 & 31));
    // 0x8001E9B8: lbu         $v1, 0x2($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X2);
    // 0x8001E9BC: xor         $a1, $a1, $t3
    ctx->r5 = ctx->r5 ^ ctx->r11;
    // 0x8001E9C0: addiu       $t9, $t0, -0x4
    ctx->r25 = ADD32(ctx->r8, -0X4);
    // 0x8001E9C4: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8001E9C8: andi        $t4, $a0, 0x17
    ctx->r12 = ctx->r4 & 0X17;
    // 0x8001E9CC: sllv        $t5, $v1, $t4
    ctx->r13 = S32(ctx->r3 << (ctx->r12 & 31));
    // 0x8001E9D0: lbu         $v1, 0x3($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X3);
    // 0x8001E9D4: xor         $a1, $a1, $t5
    ctx->r5 = ctx->r5 ^ ctx->r13;
    // 0x8001E9D8: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8001E9DC: andi        $t6, $a0, 0x17
    ctx->r14 = ctx->r4 & 0X17;
    // 0x8001E9E0: sw          $a0, -0x165C($at)
    MEM_W(-0X165C, ctx->r1) = ctx->r4;
    // 0x8001E9E4: sllv        $t7, $v1, $t6
    ctx->r15 = S32(ctx->r3 << (ctx->r14 & 31));
    // 0x8001E9E8: xor         $a1, $a1, $t7
    ctx->r5 = ctx->r5 ^ ctx->r15;
    // 0x8001E9EC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001E9F0: sw          $a1, -0x1658($at)
    MEM_W(-0X1658, ctx->r1) = ctx->r5;
    // 0x8001E9F4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001E9F8: sw          $t8, -0x1660($at)
    MEM_W(-0X1660, ctx->r1) = ctx->r24;
    // 0x8001E9FC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001EA00: b           L_8001EAA0
    // 0x8001EA04: sw          $t9, -0x1654($at)
    MEM_W(-0X1654, ctx->r1) = ctx->r25;
        goto L_8001EAA0;
    // 0x8001EA04: sw          $t9, -0x1654($at)
    MEM_W(-0X1654, ctx->r1) = ctx->r25;
L_8001EA08:
    // 0x8001EA08: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x8001EA0C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8001EA10: lbu         $t2, 0x1194($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X1194);
    // 0x8001EA14: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8001EA18: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8001EA1C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8001EA20: jal         0x8001E210
    // 0x8001EA24: addu        $a0, $t3, $v1
    ctx->r4 = ADD32(ctx->r11, ctx->r3);
    rom_read_word(rdram, ctx);
        goto after_1;
    // 0x8001EA24: addu        $a0, $t3, $v1
    ctx->r4 = ADD32(ctx->r11, ctx->r3);
    after_1:
    // 0x8001EA28: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x8001EA2C: lw          $t4, -0x1650($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X1650);
    // 0x8001EA30: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8001EA34: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8001EA38: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8001EA3C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8001EA40: lbu         $t6, 0x1194($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1194);
    // 0x8001EA44: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8001EA48: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001EA4C: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    // 0x8001EA50: jal         0x8001E210
    // 0x8001EA54: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    rom_read_word(rdram, ctx);
        goto after_2;
    // 0x8001EA54: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_2:
    // 0x8001EA58: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8001EA5C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8001EA60: lw          $t8, -0x165C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X165C);
    // 0x8001EA64: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8001EA68: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8001EA6C: beq         $a0, $t8, L_8001EA7C
    if (ctx->r4 == ctx->r24) {
        // 0x8001EA70: nop
    
            goto L_8001EA7C;
    }
    // 0x8001EA70: nop

    // 0x8001EA74: b           L_8001EAA4
    // 0x8001EA78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001EAA4;
    // 0x8001EA78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001EA7C:
    // 0x8001EA7C: lw          $t9, -0x1658($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1658);
    // 0x8001EA80: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001EA84: beq         $a1, $t9, L_8001EA94
    if (ctx->r5 == ctx->r25) {
        // 0x8001EA88: nop
    
            goto L_8001EA94;
    }
    // 0x8001EA88: nop

    // 0x8001EA8C: b           L_8001EAA4
    // 0x8001EA90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001EAA4;
    // 0x8001EA90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001EA94:
    // 0x8001EA94: lw          $a0, -0x1650($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1650);
    // 0x8001EA98: jal         0x8001E868
    // 0x8001EA9C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    set_crc_entry(rdram, ctx);
        goto after_3;
    // 0x8001EA9C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    after_3:
L_8001EAA0:
    // 0x8001EAA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001EAA4:
    // 0x8001EAA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001EAA8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8001EAAC: jr          $ra
    // 0x8001EAB0: nop

    return;
    // 0x8001EAB0: nop

;}
RECOMP_FUNC void chbounce_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80800004: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800008: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080000C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800010: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800014: addiu       $v0, $v0, 0x7188
    ctx->r2 = ADD32(ctx->r2, 0X7188);
    // 0x80800018: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8080001C: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80800020: jr          $ra
    // 0x80800024: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x80800024: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_80111340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111340: jr          $ra
    // 0x80111344: addiu       $v0, $zero, 0x8C
    ctx->r2 = ADD32(0, 0X8C);
    return;
    // 0x80111344: addiu       $v0, $zero, 0x8C
    ctx->r2 = ADD32(0, 0X8C);
;}
RECOMP_FUNC void func_808050D8_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808050D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808050DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808050E0: jal         0x80082FE8
    // 0x808050E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808050E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808050E8: jal         0x80807D48
    // 0x808050EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80807D48_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x808050EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808050F0: jal         0x80809D24
    // 0x808050F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80809D24_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x808050F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808050F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808050FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80805100: jr          $ra
    // 0x80805104: nop

    return;
    // 0x80805104: nop

;}
RECOMP_FUNC void gcintrotext_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800024: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800028: addiu       $a0, $zero, 0x6CB
    ctx->r4 = ADD32(0, 0X6CB);
    // 0x8080002C: jal         0x800DA9E4
    // 0x80800030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA9E4(rdram, ctx);
        goto after_0;
    // 0x80800030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800034: beq         $v0, $zero, L_80800044
    if (ctx->r2 == 0) {
        // 0x80800038: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800044;
    }
    // 0x80800038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080003C: b           L_80800048
    // 0x80800040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800048;
    // 0x80800040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800044:
    // 0x80800044: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800048:
    // 0x80800048: jr          $ra
    // 0x8080004C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8080004C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void suspline_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808004FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800500: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800504: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800508: lbu         $t6, 0x8A($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X8A);
    // 0x8080050C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800510: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80800514: bnel        $t7, $zero, L_8080061C
    if (ctx->r15 != 0) {
        // 0x80800518: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080061C;
    }
    goto skip_0;
    // 0x80800518: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080051C: lh          $t8, 0x7C($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X7C);
    // 0x80800520: lh          $a1, 0x78($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X78);
    // 0x80800524: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80800528: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8080052C: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80800530: lh          $t1, 0x70($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X70);
    // 0x80800534: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80800538: bne         $at, $zero, L_808005B4
    if (ctx->r1 != 0) {
        // 0x8080053C: addu        $s1, $t1, $a0
        ctx->r17 = ADD32(ctx->r9, ctx->r4);
            goto L_808005B4;
    }
    // 0x8080053C: addu        $s1, $t1, $a0
    ctx->r17 = ADD32(ctx->r9, ctx->r4);
    // 0x80800540: jal         0x80800224
    // 0x80800544: addiu       $a1, $s0, 0x58
    ctx->r5 = ADD32(ctx->r16, 0X58);
    func_80800224_suspline(rdram, ctx);
        goto after_0;
    // 0x80800544: addiu       $a1, $s0, 0x58
    ctx->r5 = ADD32(ctx->r16, 0X58);
    after_0:
    // 0x80800548: lh          $t2, 0x3C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X3C);
    // 0x8080054C: lh          $t5, 0x3E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X3E);
    // 0x80800550: lh          $t8, 0x40($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X40);
    // 0x80800554: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80800558: addu        $t4, $s1, $t3
    ctx->r12 = ADD32(ctx->r17, ctx->r11);
    // 0x8080055C: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80800560: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80800564: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x80800568: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8080056C: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80800570: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80800574: lh          $t1, 0x42($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X42);
    // 0x80800578: addu        $t0, $s1, $t9
    ctx->r8 = ADD32(ctx->r17, ctx->r25);
    // 0x8080057C: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x80800580: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80800584: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80800588: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x8080058C: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x80800590: lwc1        $f10, 0x0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80800594: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800598: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080059C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x808005A0: addiu       $a3, $s0, 0x60
    ctx->r7 = ADD32(ctx->r16, 0X60);
    // 0x808005A4: jal         0x80089120
    // 0x808005A8: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    _mlspline_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x808005A8: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x808005AC: b           L_808005E4
    // 0x808005B0: nop

        goto L_808005E4;
    // 0x808005B0: nop

L_808005B4:
    // 0x808005B4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808005B8: bne         $a1, $at, L_808005D8
    if (ctx->r5 != ctx->r1) {
        // 0x808005BC: or          $a2, $s1, $zero
        ctx->r6 = ctx->r17 | 0;
            goto L_808005D8;
    }
    // 0x808005BC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808005C0: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808005C4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808005C8: jal         0x800890F0
    // 0x808005CC: addiu       $a3, $s0, 0x60
    ctx->r7 = ADD32(ctx->r16, 0X60);
    _mlspline_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808005CC: addiu       $a3, $s0, 0x60
    ctx->r7 = ADD32(ctx->r16, 0X60);
    after_2:
    // 0x808005D0: b           L_808005E4
    // 0x808005D4: nop

        goto L_808005E4;
    // 0x808005D4: nop

L_808005D8:
    // 0x808005D8: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808005DC: jal         0x800890E0
    // 0x808005E0: addiu       $a3, $s0, 0x60
    ctx->r7 = ADD32(ctx->r16, 0X60);
    _mlspline_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808005E0: addiu       $a3, $s0, 0x60
    ctx->r7 = ADD32(ctx->r16, 0X60);
    after_3:
L_808005E4:
    // 0x808005E4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3202, 0XEAC) << 16);
    // 0x808005E8: lwc1        $f0, 0xEAC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3202, 0XEAC));
    // 0x808005EC: lwc1        $f16, 0x54($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808005F0: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x808005F4: nop

    // 0x808005F8: bc1f        L_80800604
    if (!c1cs) {
        // 0x808005FC: nop
    
            goto L_80800604;
    }
    // 0x808005FC: nop

    // 0x80800600: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_80800604:
    // 0x80800604: jal         0x800D8FF8
    // 0x80800608: nop

    func_800D8FF8(rdram, ctx);
        goto after_4;
    // 0x80800608: nop

    after_4:
    // 0x8080060C: lwc1        $f18, 0x60($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X60);
    // 0x80800610: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800614: swc1        $f4, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f4.u32l;
    // 0x80800618: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080061C:
    // 0x8080061C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800620: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800624: jr          $ra
    // 0x80800628: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800628: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800EFED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFED0: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800EFED4: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EFED8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EFEDC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800EFEE0: nop

    // 0x800EFEE4: bc1f        L_800EFEF0
    if (!c1cs) {
        // 0x800EFEE8: nop
    
            goto L_800EFEF0;
    }
    // 0x800EFEE8: nop

    // 0x800EFEEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EFEF0:
    // 0x800EFEF0: beq         $v0, $zero, L_800EFFAC
    if (ctx->r2 == 0) {
        // 0x800EFEF4: nop
    
            goto L_800EFFAC;
    }
    // 0x800EFEF4: nop

    // 0x800EFEF8: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EFEFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EFF00: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800EFF04: nop

    // 0x800EFF08: bc1f        L_800EFF14
    if (!c1cs) {
        // 0x800EFF0C: nop
    
            goto L_800EFF14;
    }
    // 0x800EFF0C: nop

    // 0x800EFF10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EFF14:
    // 0x800EFF14: beq         $v0, $zero, L_800EFFAC
    if (ctx->r2 == 0) {
        // 0x800EFF18: nop
    
            goto L_800EFFAC;
    }
    // 0x800EFF18: nop

    // 0x800EFF1C: lwc1        $f0, 0x4($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800EFF20: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EFF24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EFF28: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800EFF2C: nop

    // 0x800EFF30: bc1f        L_800EFF3C
    if (!c1cs) {
        // 0x800EFF34: nop
    
            goto L_800EFF3C;
    }
    // 0x800EFF34: nop

    // 0x800EFF38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EFF3C:
    // 0x800EFF3C: beq         $v0, $zero, L_800EFFAC
    if (ctx->r2 == 0) {
        // 0x800EFF40: nop
    
            goto L_800EFFAC;
    }
    // 0x800EFF40: nop

    // 0x800EFF44: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EFF48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EFF4C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800EFF50: nop

    // 0x800EFF54: bc1f        L_800EFF60
    if (!c1cs) {
        // 0x800EFF58: nop
    
            goto L_800EFF60;
    }
    // 0x800EFF58: nop

    // 0x800EFF5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EFF60:
    // 0x800EFF60: beq         $v0, $zero, L_800EFFAC
    if (ctx->r2 == 0) {
        // 0x800EFF64: nop
    
            goto L_800EFFAC;
    }
    // 0x800EFF64: nop

    // 0x800EFF68: lwc1        $f0, 0x8($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800EFF6C: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EFF70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EFF74: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x800EFF78: nop

    // 0x800EFF7C: bc1f        L_800EFF88
    if (!c1cs) {
        // 0x800EFF80: nop
    
            goto L_800EFF88;
    }
    // 0x800EFF80: nop

    // 0x800EFF84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EFF88:
    // 0x800EFF88: beq         $v0, $zero, L_800EFFAC
    if (ctx->r2 == 0) {
        // 0x800EFF8C: nop
    
            goto L_800EFFAC;
    }
    // 0x800EFF8C: nop

    // 0x800EFF90: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EFF94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EFF98: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800EFF9C: nop

    // 0x800EFFA0: bc1f        L_800EFFAC
    if (!c1cs) {
        // 0x800EFFA4: nop
    
            goto L_800EFFAC;
    }
    // 0x800EFFA4: nop

    // 0x800EFFA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EFFAC:
    // 0x800EFFAC: jr          $ra
    // 0x800EFFB0: nop

    return;
    // 0x800EFFB0: nop

;}
RECOMP_FUNC void chbaddiesetup_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800378: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080037C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800380: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800384: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800388: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080038C: jal         0x800A5D60
    // 0x80800390: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800A5D60(rdram, ctx);
        goto after_0;
    // 0x80800390: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800394: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800398: jal         0x80800000
    // 0x8080039C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80800000_chbaddiesetup(rdram, ctx);
        goto after_1;
    // 0x8080039C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808003A0: beq         $v0, $zero, L_8080045C
    if (ctx->r2 == 0) {
        // 0x808003A4: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8080045C;
    }
    // 0x808003A4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808003A8: lbu         $t8, 0x4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4);
    // 0x808003AC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x808003B0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808003B4: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x808003B8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x808003BC: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x808003C0: lbu         $t3, 0x4($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X4);
    // 0x808003C4: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x808003C8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x808003CC: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x808003D0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x808003D4: sw          $t1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r9;
    // 0x808003D8: lbu         $t9, 0x4($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X4);
    // 0x808003DC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x808003E0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x808003E4: sll         $t6, $t9, 5
    ctx->r14 = S32(ctx->r25 << 5);
    // 0x808003E8: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x808003EC: sw          $t8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r24;
    // 0x808003F0: lbu         $t4, 0x4($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X4);
    // 0x808003F4: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x808003F8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x808003FC: sll         $t1, $t4, 5
    ctx->r9 = S32(ctx->r12 << 5);
    // 0x80800400: addu        $t5, $t2, $t1
    ctx->r13 = ADD32(ctx->r10, ctx->r9);
    // 0x80800404: sw          $t3, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r11;
    // 0x80800408: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
    // 0x8080040C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80800410: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80800414: sll         $t8, $t6, 5
    ctx->r24 = S32(ctx->r14 << 5);
    // 0x80800418: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x8080041C: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
    // 0x80800420: lbu         $t1, 0x4($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X4);
    // 0x80800424: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80800428: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8080042C: sll         $t3, $t1, 5
    ctx->r11 = S32(ctx->r9 << 5);
    // 0x80800430: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x80800434: sw          $t4, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r12;
    // 0x80800438: lbu         $t8, 0x4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4);
    // 0x8080043C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80800440: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80800444: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x80800448: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8080044C: sw          $t6, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r14;
    // 0x80800450: lbu         $t1, 0x4($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X4);
    // 0x80800454: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80800458: sb          $t2, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r10;
L_8080045C:
    // 0x8080045C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800460: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800464: jr          $ra
    // 0x80800468: nop

    return;
    // 0x80800468: nop

;}
RECOMP_FUNC void _ncba1p_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800893C8: syscall     777
    recomp_syscall_handler(rdram, ctx, 0x800893C8);
    return;
    // 0x800893CC: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void _ncbaspline_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800893C0: syscall     776
    recomp_syscall_handler(rdram, ctx, 0x800893C0);
    return;
    // 0x800893C4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
