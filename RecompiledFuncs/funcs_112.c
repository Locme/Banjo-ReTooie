#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void chtntmineshoot_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F84: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2204, 0X2774) << 16);
    // 0x80801F88: jr          $ra
    // 0x80801F8C: addiu       $v0, $v0, 0x2774
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2204, 0X2774));
    return;
    // 0x80801F8C: addiu       $v0, $v0, 0x2774
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2204, 0X2774));
;}
RECOMP_FUNC void func_808059A4_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808059A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808059A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808059AC: jal         0x80100094
    // 0x808059B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808059B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808059B4: sb          $zero, 0x24($v0)
    MEM_B(0X24, ctx->r2) = 0;
    // 0x808059B8: sb          $zero, 0x25($v0)
    MEM_B(0X25, ctx->r2) = 0;
    // 0x808059BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808059C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808059C4: jr          $ra
    // 0x808059C8: nop

    return;
    // 0x808059C8: nop

;}
RECOMP_FUNC void func_80800964_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800964: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800968: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080096C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800970: jal         0x800D52B0
    // 0x80800974: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D52B0(rdram, ctx);
        goto after_0;
    // 0x80800974: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800978: jal         0x80800000
    // 0x8080097C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_gczoombox(rdram, ctx);
        goto after_1;
    // 0x8080097C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800980: jal         0x808000DC
    // 0x80800984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000DC_gczoombox(rdram, ctx);
        goto after_2;
    // 0x80800984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800988: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8080098C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800990: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_80800994:
    // 0x80800994: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800998: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x8080099C: sw          $zero, 0x184($v0)
    MEM_W(0X184, ctx->r2) = 0;
    // 0x808009A0: sw          $zero, 0x188($v0)
    MEM_W(0X188, ctx->r2) = 0;
    // 0x808009A4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x808009A8: bne         $v1, $a0, L_80800994
    if (ctx->r3 != ctx->r4) {
        // 0x808009AC: sw          $zero, 0x16C($v0)
        MEM_W(0X16C, ctx->r2) = 0;
            goto L_80800994;
    }
    // 0x808009AC: sw          $zero, 0x16C($v0)
    MEM_W(0X16C, ctx->r2) = 0;
    // 0x808009B0: lbu         $t6, 0x1E5($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1E5);
    // 0x808009B4: sb          $zero, 0x171($s0)
    MEM_B(0X171, ctx->r16) = 0;
    // 0x808009B8: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x808009BC: sb          $t7, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r15;
    // 0x808009C0: lw          $t8, 0x1E4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1E4);
    // 0x808009C4: sll         $t9, $t8, 11
    ctx->r25 = S32(ctx->r24 << 11);
    // 0x808009C8: srl         $t0, $t9, 31
    ctx->r8 = S32(U32(ctx->r25) >> 31);
    // 0x808009CC: sb          $t0, 0x174($s0)
    MEM_B(0X174, ctx->r16) = ctx->r8;
    // 0x808009D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808009D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808009D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808009DC: jr          $ra
    // 0x808009E0: nop

    return;
    // 0x808009E0: nop

;}
RECOMP_FUNC void func_80801428_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801428: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080142C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801430: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801434: jal         0x80100094
    // 0x80801438: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801438: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080143C: jal         0x80104200
    // 0x80801440: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    func_80104200(rdram, ctx);
        goto after_1;
    // 0x80801440: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    after_1:
    // 0x80801444: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801448: jal         0x8008AF24
    // 0x8080144C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x8080144C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80801450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801454: jal         0x8008B134
    // 0x80801458: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_3;
    // 0x80801458: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x8080145C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801460: jal         0x8008AED4
    // 0x80801464: addiu       $a1, $zero, 0x486
    ctx->r5 = ADD32(0, 0X486);
    anctrl_setIndex(rdram, ctx);
        goto after_4;
    // 0x80801464: addiu       $a1, $zero, 0x486
    ctx->r5 = ADD32(0, 0X486);
    after_4:
    // 0x80801468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080146C: jal         0x8008B1BC
    // 0x80801470: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x80801470: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_5:
    // 0x80801474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801478: jal         0x8008B188
    // 0x8080147C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008B188(rdram, ctx);
        goto after_6;
    // 0x8080147C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80801480: jal         0x8008B064
    // 0x80801484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x80801484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801488: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080148C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801490: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801494: jr          $ra
    // 0x80801498: nop

    return;
    // 0x80801498: nop

;}
RECOMP_FUNC void func_8080007C_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080007C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800084: jal         0x8009E6EC
    // 0x80800088: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80800088: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080008C: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80800090: beq         $v0, $at, L_808000B8
    if (ctx->r2 == ctx->r1) {
        // 0x80800094: addiu       $at, $zero, 0x1D
        ctx->r1 = ADD32(0, 0X1D);
            goto L_808000B8;
    }
    // 0x80800094: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x80800098: beq         $v0, $at, L_808000B8
    if (ctx->r2 == ctx->r1) {
        // 0x8080009C: addiu       $at, $zero, 0x1E
        ctx->r1 = ADD32(0, 0X1E);
            goto L_808000B8;
    }
    // 0x8080009C: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x808000A0: beq         $v0, $at, L_808000B8
    if (ctx->r2 == ctx->r1) {
        // 0x808000A4: addiu       $at, $zero, 0x25
        ctx->r1 = ADD32(0, 0X25);
            goto L_808000B8;
    }
    // 0x808000A4: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x808000A8: beql        $v0, $at, L_808000BC
    if (ctx->r2 == ctx->r1) {
        // 0x808000AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000BC;
    }
    goto skip_0;
    // 0x808000AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000B0: jal         0x80099B94
    // 0x808000B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80099B94(rdram, ctx);
        goto after_1;
    // 0x808000B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_808000B8:
    // 0x808000B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000BC:
    // 0x808000BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000C0: jr          $ra
    // 0x808000C4: nop

    return;
    // 0x808000C4: nop

;}
RECOMP_FUNC void func_80098520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098520: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80098524: lw          $t6, 0xAC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XAC);
    // 0x80098528: jr          $ra
    // 0x8009852C: swc1        $f12, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x8009852C: swc1        $f12, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void _bababykaz_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800844C8: syscall     112
    recomp_syscall_handler(rdram, ctx, 0x800844C8);
    return;
    // 0x800844CC: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_80800EC8_chfactorysparkroom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EC8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800ECC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800ED0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800ED4: beq         $a1, $at, L_80800EF0
    if (ctx->r5 == ctx->r1) {
        // 0x80800ED8: sw          $a0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r4;
            goto L_80800EF0;
    }
    // 0x80800ED8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800EDC: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80800EE0: beq         $a1, $at, L_80800FC8
    if (ctx->r5 == ctx->r1) {
        // 0x80800EE4: lui         $t7, 0x8080
        ctx->r15 = S32(RELOC_HI16(2372, 0X1150) << 16);
            goto L_80800FC8;
    }
    // 0x80800EE4: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2372, 0X1150) << 16);
    // 0x80800EE8: b           L_80801000
    // 0x80800EEC: nop

        goto L_80801000;
    // 0x80800EEC: nop

L_80800EF0:
    // 0x80800EF0: jal         0x800DA298
    // 0x80800EF4: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800EF4: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    after_0:
    // 0x80800EF8: beq         $v0, $zero, L_80800F70
    if (ctx->r2 == 0) {
        // 0x80800EFC: nop
    
            goto L_80800F70;
    }
    // 0x80800EFC: nop

    // 0x80800F00: jal         0x800DA298
    // 0x80800F04: addiu       $a0, $zero, 0x1BC
    ctx->r4 = ADD32(0, 0X1BC);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800F04: addiu       $a0, $zero, 0x1BC
    ctx->r4 = ADD32(0, 0X1BC);
    after_1:
    // 0x80800F08: bne         $v0, $zero, L_80800F2C
    if (ctx->r2 != 0) {
        // 0x80800F0C: nop
    
            goto L_80800F2C;
    }
    // 0x80800F0C: nop

    // 0x80800F10: jal         0x800DA544
    // 0x80800F14: addiu       $a0, $zero, 0xA04
    ctx->r4 = ADD32(0, 0XA04);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x80800F14: addiu       $a0, $zero, 0xA04
    ctx->r4 = ADD32(0, 0XA04);
    after_2:
    // 0x80800F18: addiu       $a0, $zero, 0x10D
    ctx->r4 = ADD32(0, 0X10D);
    // 0x80800F1C: jal         0x800887D8
    // 0x80800F20: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80800F20: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    after_3:
    // 0x80800F24: b           L_80801008
    // 0x80800F28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801008;
    // 0x80800F28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F2C:
    // 0x80800F2C: jal         0x80086B58
    // 0x80800F30: nop

    _chmrtannoy_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80800F30: nop

    after_4:
    // 0x80800F34: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800F38: addiu       $t7, $zero, 0xA3
    ctx->r15 = ADD32(0, 0XA3);
    // 0x80800F3C: addiu       $a1, $zero, 0x1365
    ctx->r5 = ADD32(0, 0X1365);
    // 0x80800F40: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80800F44: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800F48: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80800F4C: jal         0x8008A208
    // 0x80800F50: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80800F50: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    after_5:
    // 0x80800F54: jal         0x800DA524
    // 0x80800F58: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    func_800DA524(rdram, ctx);
        goto after_6;
    // 0x80800F58: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    after_6:
    // 0x80800F5C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800F60: jal         0x80108B04
    // 0x80800F64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_7;
    // 0x80800F64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800F68: b           L_80801008
    // 0x80800F6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801008;
    // 0x80800F6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F70:
    // 0x80800F70: jal         0x800DA298
    // 0x80800F74: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x80800F74: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    after_8:
    // 0x80800F78: bne         $v0, $zero, L_80800FC0
    if (ctx->r2 != 0) {
        // 0x80800F7C: lw          $t8, 0x30($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X30);
            goto L_80800FC0;
    }
    // 0x80800F7C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80800F80: lw          $t9, 0x74($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X74);
    // 0x80800F84: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x80800F88: bltz        $t1, L_80800FC0
    if (SIGNED(ctx->r9) < 0) {
        // 0x80800F8C: nop
    
            goto L_80800FC0;
    }
    // 0x80800F8C: nop

    // 0x80800F90: lbu         $t3, 0x74($t8)
    ctx->r11 = MEM_BU(ctx->r24, 0X74);
    // 0x80800F94: ori         $t4, $t3, 0x40
    ctx->r12 = ctx->r11 | 0X40;
    // 0x80800F98: jal         0x80086B58
    // 0x80800F9C: sb          $t4, 0x74($t8)
    MEM_B(0X74, ctx->r24) = ctx->r12;
    _chmrtannoy_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x80800F9C: sb          $t4, 0x74($t8)
    MEM_B(0X74, ctx->r24) = ctx->r12;
    after_9:
    // 0x80800FA0: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80800FA4: addiu       $t6, $zero, 0xA3
    ctx->r14 = ADD32(0, 0XA3);
    // 0x80800FA8: addiu       $a1, $zero, 0x133C
    ctx->r5 = ADD32(0, 0X133C);
    // 0x80800FAC: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80800FB0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800FB4: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80800FB8: jal         0x8008A208
    // 0x80800FBC: addiu       $a3, $t5, 0x4
    ctx->r7 = ADD32(ctx->r13, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_10;
    // 0x80800FBC: addiu       $a3, $t5, 0x4
    ctx->r7 = ADD32(ctx->r13, 0X4);
    after_10:
L_80800FC0:
    // 0x80800FC0: b           L_80801008
    // 0x80800FC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801008;
    // 0x80800FC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800FC8:
    // 0x80800FC8: addiu       $t7, $t7, 0x1150
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2372, 0X1150));
    // 0x80800FCC: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800FD0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800FD4: addiu       $a0, $zero, 0x47C
    ctx->r4 = ADD32(0, 0X47C);
    // 0x80800FD8: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x80800FDC: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80800FE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800FE4: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // 0x80800FE8: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x80800FEC: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80800FF0: jal         0x80108528
    // 0x80800FF4: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    func_80108528(rdram, ctx);
        goto after_11;
    // 0x80800FF4: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    after_11:
    // 0x80800FF8: b           L_80801008
    // 0x80800FFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801008;
    // 0x80800FFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801000:
    // 0x80801000: jal         0x80085820
    // 0x80801004: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_12;
    // 0x80801004: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_12:
L_80801008:
    // 0x80801008: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080100C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801010: jr          $ra
    // 0x80801014: nop

    return;
    // 0x80801014: nop

;}
RECOMP_FUNC void func_8080000C_chrainripples(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: jal         0x808001FC
    // 0x80800018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808001FC_chrainripples(rdram, ctx);
        goto after_0;
    // 0x80800018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080001C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800020: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800024: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800028: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8080002C: swc1        $f6, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->f6.u32l;
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800038: jr          $ra
    // 0x8080003C: nop

    return;
    // 0x8080003C: nop

;}
RECOMP_FUNC void func_8009AD38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009AD38: lw          $t6, 0xC0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC0);
    // 0x8009AD3C: jr          $ra
    // 0x8009AD40: sw          $a1, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->r5;
    return;
    // 0x8009AD40: sw          $a1, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void _baduo_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800849A0: syscall     124
    recomp_syscall_handler(rdram, ctx, 0x800849A0);
    return;
    // 0x800849A4: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void func_800989E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800989E4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800989E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800989EC: jal         0x8008DAA8
    // 0x800989F0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_8008DAA8(rdram, ctx);
        goto after_0;
    // 0x800989F0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x800989F4: beq         $v0, $zero, L_80098B3C
    if (ctx->r2 == 0) {
        // 0x800989F8: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_80098B3C;
    }
    // 0x800989F8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800989FC: lw          $t7, 0xBC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XBC);
    // 0x80098A00: lbu         $t8, 0x19($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X19);
    // 0x80098A04: bnel        $t8, $zero, L_80098B40
    if (ctx->r24 != 0) {
        // 0x80098A08: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80098B40;
    }
    goto skip_0;
    // 0x80098A08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80098A0C: jal         0x800BF6B8
    // 0x80098A10: nop

    func_800BF6B8(rdram, ctx);
        goto after_1;
    // 0x80098A10: nop

    after_1:
    // 0x80098A14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80098A18: beq         $v0, $at, L_80098B3C
    if (ctx->r2 == ctx->r1) {
        // 0x80098A1C: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80098B3C;
    }
    // 0x80098A1C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80098A20: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80098A24: jal         0x8009C128
    // 0x80098A28: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_8009C128(rdram, ctx);
        goto after_2;
    // 0x80098A28: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_2:
    // 0x80098A2C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80098A30: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80098A34: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80098A38: beql        $v1, $at, L_80098A5C
    if (ctx->r3 == ctx->r1) {
        // 0x80098A3C: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80098A5C;
    }
    goto skip_1;
    // 0x80098A3C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    skip_1:
    // 0x80098A40: lw          $a1, 0xBC($t9)
    ctx->r5 = MEM_W(ctx->r25, 0XBC);
    // 0x80098A44: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80098A48: jal         0x800EFED0
    // 0x80098A4C: addiu       $a0, $a1, 0xC
    ctx->r4 = ADD32(ctx->r5, 0XC);
    func_800EFED0(rdram, ctx);
        goto after_3;
    // 0x80098A4C: addiu       $a0, $a1, 0xC
    ctx->r4 = ADD32(ctx->r5, 0XC);
    after_3:
    // 0x80098A50: bnel        $v0, $zero, L_80098B40
    if (ctx->r2 != 0) {
        // 0x80098A54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80098B40;
    }
    goto skip_2;
    // 0x80098A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80098A58: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_80098A5C:
    // 0x80098A5C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80098A60: lw          $a1, 0xBC($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XBC);
    // 0x80098A64: lbu         $t0, 0x18($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X18);
    // 0x80098A68: bne         $t0, $zero, L_80098B34
    if (ctx->r8 != 0) {
        // 0x80098A6C: nop
    
            goto L_80098B34;
    }
    // 0x80098A6C: nop

    // 0x80098A70: jal         0x800D3948
    // 0x80098A74: sb          $t1, 0x18($a1)
    MEM_B(0X18, ctx->r5) = ctx->r9;
    func_800D3948(rdram, ctx);
        goto after_4;
    // 0x80098A74: sb          $t1, 0x18($a1)
    MEM_B(0X18, ctx->r5) = ctx->r9;
    after_4:
    // 0x80098A78: bne         $v0, $zero, L_80098A90
    if (ctx->r2 != 0) {
        // 0x80098A7C: nop
    
            goto L_80098A90;
    }
    // 0x80098A7C: nop

    // 0x80098A80: jal         0x800D395C
    // 0x80098A84: nop

    func_800D395C(rdram, ctx);
        goto after_5;
    // 0x80098A84: nop

    after_5:
    // 0x80098A88: beql        $v0, $zero, L_80098AA4
    if (ctx->r2 == 0) {
        // 0x80098A8C: sw          $zero, 0x24($sp)
        MEM_W(0X24, ctx->r29) = 0;
            goto L_80098AA4;
    }
    goto skip_3;
    // 0x80098A8C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    skip_3:
L_80098A90:
    // 0x80098A90: jal         0x80088190
    // 0x80098A94: nop

    _gcfrontend_entrypoint_12(rdram, ctx);
        goto after_6;
    // 0x80098A94: nop

    after_6:
    // 0x80098A98: b           L_80098B40
    // 0x80098A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80098B40;
    // 0x80098A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80098AA0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80098AA4:
    // 0x80098AA4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80098AA8: jal         0x800A3274
    // 0x80098AAC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800A3274(rdram, ctx);
        goto after_7;
    // 0x80098AAC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_7:
    // 0x80098AB0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80098AB4: beq         $v0, $at, L_80098ACC
    if (ctx->r2 == ctx->r1) {
        // 0x80098AB8: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_80098ACC;
    }
    // 0x80098AB8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80098ABC: bne         $v0, $at, L_80098AE4
    if (ctx->r2 != ctx->r1) {
        // 0x80098AC0: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80098AE4;
    }
    // 0x80098AC0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80098AC4: b           L_80098AE4
    // 0x80098AC8: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
        goto L_80098AE4;
    // 0x80098AC8: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
L_80098ACC:
    // 0x80098ACC: jal         0x800F8B88
    // 0x80098AD0: nop

    func_800F8B88(rdram, ctx);
        goto after_8;
    // 0x80098AD0: nop

    after_8:
    // 0x80098AD4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80098AD8: bne         $v0, $at, L_80098AE4
    if (ctx->r2 != ctx->r1) {
        // 0x80098ADC: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80098AE4;
    }
    // 0x80098ADC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80098AE0: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
L_80098AE4:
    // 0x80098AE4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80098AE8: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80098AEC: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x80098AF0: beq         $t4, $zero, L_80098B08
    if (ctx->r12 == 0) {
        // 0x80098AF4: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_80098B08;
    }
    // 0x80098AF4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80098AF8: jal         0x800F7B9C
    // 0x80098AFC: lw          $a0, 0x184($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X184);
    func_800F7B9C(rdram, ctx);
        goto after_9;
    // 0x80098AFC: lw          $a0, 0x184($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X184);
    after_9:
    // 0x80098B00: b           L_80098B40
    // 0x80098B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80098B40;
    // 0x80098B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80098B08:
    // 0x80098B08: beq         $t6, $zero, L_80098B24
    if (ctx->r14 == 0) {
        // 0x80098B0C: lw          $t7, 0x38($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X38);
            goto L_80098B24;
    }
    // 0x80098B0C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80098B10: lw          $a0, 0x184($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X184);
    // 0x80098B14: jal         0x800F7B9C
    // 0x80098B18: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    func_800F7B9C(rdram, ctx);
        goto after_10;
    // 0x80098B18: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    after_10:
    // 0x80098B1C: b           L_80098B40
    // 0x80098B20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80098B40;
    // 0x80098B20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80098B24:
    // 0x80098B24: jal         0x800A05DC
    // 0x80098B28: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800A05DC(rdram, ctx);
        goto after_11;
    // 0x80098B28: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_11:
    // 0x80098B2C: b           L_80098B40
    // 0x80098B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80098B40;
    // 0x80098B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80098B34:
    // 0x80098B34: jal         0x8009B800
    // 0x80098B38: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    baphysics_set_type(rdram, ctx);
        goto after_12;
    // 0x80098B38: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_12:
L_80098B3C:
    // 0x80098B3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80098B40:
    // 0x80098B40: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80098B44: jr          $ra
    // 0x80098B48: nop

    return;
    // 0x80098B48: nop

;}
RECOMP_FUNC void func_80800150_chcheatomenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800150: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800158: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080015C: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800160: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800164: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800168: bnel        $t7, $at, L_80800188
    if (ctx->r15 != ctx->r1) {
        // 0x8080016C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800188;
    }
    goto skip_0;
    // 0x8080016C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800170: jal         0x80100094
    // 0x80800174: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800174: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800178: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080017C: jal         0x80087CA0
    // 0x80800180: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _gcnewoption_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800180: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800188:
    // 0x80800188: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080018C: jr          $ra
    // 0x80800190: nop

    return;
    // 0x80800190: nop

;}
RECOMP_FUNC void _gcskyDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088070: syscall     667
    recomp_syscall_handler(rdram, ctx, 0x80088070);
    return;
    // 0x80088074: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8010CAC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CAC0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010CAC4: addiu       $a2, $a2, 0x6F50
    ctx->r6 = ADD32(ctx->r6, 0X6F50);
    // 0x8010CAC8: lh          $t6, 0xC($a2)
    ctx->r14 = MEM_H(ctx->r6, 0XC);
    // 0x8010CACC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010CAD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010CAD4: bne         $t6, $zero, L_8010CAE4
    if (ctx->r14 != 0) {
        // 0x8010CAD8: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8010CAE4;
    }
    // 0x8010CAD8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8010CADC: b           L_8010CAFC
    // 0x8010CAE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010CAFC;
    // 0x8010CAE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010CAE4:
    // 0x8010CAE4: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x8010CAE8: nop

    // 0x8010CAEC: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010CAF0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8010CAF4: jal         0x800EFFB4
    // 0x8010CAF8: nop

    func_800EFFB4(rdram, ctx);
        goto after_0;
    // 0x8010CAF8: nop

    after_0:
L_8010CAFC:
    // 0x8010CAFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010CB00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010CB04: jr          $ra
    // 0x8010CB08: nop

    return;
    // 0x8010CB08: nop

;}
RECOMP_FUNC void func_808008F8_chhoney(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008F8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808008FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800900: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800904: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800908: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080090C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800910: jal         0x800D8FF8
    // 0x80800914: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800914: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800918: lwc1        $f4, 0x58($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X58);
    // 0x8080091C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800920: lwc1        $f8, 0x30($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X30);
    // 0x80800924: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80800928: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8080092C: swc1        $f6, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->f6.u32l;
    // 0x80800930: lwc1        $f18, 0x58($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X58);
    // 0x80800934: swc1        $f10, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f10.u32l;
    // 0x80800938: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x8080093C: nop

    // 0x80800940: bc1fl       L_808009A8
    if (!c1cs) {
        // 0x80800944: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808009A8;
    }
    goto skip_0;
    // 0x80800944: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800948: jal         0x8008FC28
    // 0x8080094C: nop

    func_8008FC28(rdram, ctx);
        goto after_1;
    // 0x8080094C: nop

    after_1:
    // 0x80800950: jal         0x8008FC00
    // 0x80800954: addiu       $s1, $v0, 0x1
    ctx->r17 = ADD32(ctx->r2, 0X1);
    func_8008FC00(rdram, ctx);
        goto after_2;
    // 0x80800954: addiu       $s1, $v0, 0x1
    ctx->r17 = ADD32(ctx->r2, 0X1);
    after_2:
    // 0x80800958: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080095C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800960: jal         0x800DC128
    // 0x80800964: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800DC128(rdram, ctx);
        goto after_3;
    // 0x80800964: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80800968: bne         $v0, $s0, L_80800984
    if (ctx->r2 != ctx->r16) {
        // 0x8080096C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80800984;
    }
    // 0x8080096C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80800970:
    // 0x80800970: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800974: jal         0x800DC128
    // 0x80800978: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800DC128(rdram, ctx);
        goto after_4;
    // 0x80800978: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x8080097C: beq         $v0, $s0, L_80800970
    if (ctx->r2 == ctx->r16) {
        // 0x80800980: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80800970;
    }
    // 0x80800980: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80800984:
    // 0x80800984: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800988: jal         0x8008FC70
    // 0x8080098C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_8008FC70(rdram, ctx);
        goto after_5;
    // 0x8080098C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_5:
    // 0x80800990: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800994: jal         0x80800870
    // 0x80800998: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80800870_chhoney(rdram, ctx);
        goto after_6;
    // 0x80800998: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x8080099C: lwc1        $f4, 0x2C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x808009A0: swc1        $f4, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->f4.u32l;
    // 0x808009A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808009A8:
    // 0x808009A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808009AC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808009B0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808009B4: jr          $ra
    // 0x808009B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808009B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_808010E0_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808010E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808010EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808010F0: jal         0x80100094
    // 0x808010F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808010F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808010F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808010FC: jal         0x801015D0
    // 0x80801100: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_801015D0(rdram, ctx);
        goto after_1;
    // 0x80801100: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80801104: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80801108: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8080110C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80801110: lhu         $a1, 0x72($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X72);
    // 0x80801114: srl         $t7, $a1, 10
    ctx->r15 = S32(U32(ctx->r5) >> 10);
    // 0x80801118: beq         $t7, $at, L_80801130
    if (ctx->r15 == ctx->r1) {
        // 0x8080111C: addiu       $at, $zero, 0x1C
        ctx->r1 = ADD32(0, 0X1C);
            goto L_80801130;
    }
    // 0x8080111C: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80801120: beq         $t7, $at, L_80801144
    if (ctx->r15 == ctx->r1) {
        // 0x80801124: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_80801144;
    }
    // 0x80801124: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80801128: b           L_80801170
    // 0x8080112C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
        goto L_80801170;
    // 0x8080112C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_80801130:
    // 0x80801130: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80801134: jal         0x800DF744
    // 0x80801138: lh          $a1, 0x10($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X10);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x80801138: lh          $a1, 0x10($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X10);
    after_2:
    // 0x8080113C: b           L_8080117C
    // 0x80801140: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
        goto L_8080117C;
    // 0x80801140: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
L_80801144:
    // 0x80801144: lh          $t0, 0x6($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X6);
    // 0x80801148: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080114C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80801150: bne         $t0, $at, L_80801160
    if (ctx->r8 != ctx->r1) {
        // 0x80801154: nop
    
            goto L_80801160;
    }
    // 0x80801154: nop

    // 0x80801158: b           L_80801160
    // 0x8080115C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80801160;
    // 0x8080115C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80801160:
    // 0x80801160: jal         0x800DF744
    // 0x80801164: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x80801164: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x80801168: b           L_8080117C
    // 0x8080116C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
        goto L_8080117C;
    // 0x8080116C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
L_80801170:
    // 0x80801170: jal         0x800DF744
    // 0x80801174: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_4;
    // 0x80801174: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80801178: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
L_8080117C:
    // 0x8080117C: lh          $t2, 0x1A($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X1A);
    // 0x80801180: beql        $t2, $zero, L_808011A8
    if (ctx->r10 == 0) {
        // 0x80801184: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808011A8;
    }
    goto skip_0;
    // 0x80801184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801188: jal         0x80089C90
    // 0x8080118C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x8080118C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80801190: addiu       $a0, $zero, 0xE0
    ctx->r4 = ADD32(0, 0XE0);
    // 0x80801194: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x80801198: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8080119C: jal         0x800DF5D8
    // 0x808011A0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_800DF5D8(rdram, ctx);
        goto after_6;
    // 0x808011A0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_6:
    // 0x808011A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808011A8:
    // 0x808011A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808011AC: jr          $ra
    // 0x808011B0: nop

    return;
    // 0x808011B0: nop

;}
RECOMP_FUNC void func_800CA0A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA0A8: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800CA0AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CA0B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CA0B4: jal         0x800C9F94
    // 0x800CA0B8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_800C9F94(rdram, ctx);
        goto after_0;
    // 0x800CA0B8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800CA0BC: bnel        $v0, $zero, L_800CA164
    if (ctx->r2 != 0) {
        // 0x800CA0C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800CA164;
    }
    goto skip_0;
    // 0x800CA0C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800CA0C4: jal         0x800D8FF8
    // 0x800CA0C8: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x800CA0C8: nop

    after_1:
    // 0x800CA0CC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800CA0D0: addiu       $s0, $s0, -0x54A0
    ctx->r16 = ADD32(ctx->r16, -0X54A0);
    // 0x800CA0D4: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800CA0D8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800CA0DC: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800CA0E0: jal         0x800B2928
    // 0x800CA0E4: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    vector_size(rdram, ctx);
        goto after_2;
    // 0x800CA0E4: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    after_2:
    // 0x800CA0E8: blez        $v0, L_800CA144
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800CA0EC: addiu       $s1, $sp, 0x24
        ctx->r17 = ADD32(ctx->r29, 0X24);
            goto L_800CA144;
    }
    // 0x800CA0EC: addiu       $s1, $sp, 0x24
    ctx->r17 = ADD32(ctx->r29, 0X24);
L_800CA0F0:
    // 0x800CA0F0: jal         0x800B28C4
    // 0x800CA0F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    vector_begin(rdram, ctx);
        goto after_3;
    // 0x800CA0F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x800CA0F8: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800CA0FC: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800CA100: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800CA104: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CA108: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800CA10C: nop

    // 0x800CA110: bc1t        L_800CA144
    if (c1cs) {
        // 0x800CA114: nop
    
            goto L_800CA144;
    }
    // 0x800CA114: nop

    // 0x800CA118: jal         0x8001BBA0
    // 0x800CA11C: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    rare_memcpy(rdram, ctx);
        goto after_4;
    // 0x800CA11C: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    after_4:
    // 0x800CA120: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800CA124: jal         0x800B2E30
    // 0x800CA128: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    vector_erase(rdram, ctx);
        goto after_5;
    // 0x800CA128: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x800CA12C: jal         0x800C986C
    // 0x800CA130: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800C986C(rdram, ctx);
        goto after_6;
    // 0x800CA130: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x800CA134: jal         0x800B2928
    // 0x800CA138: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    vector_size(rdram, ctx);
        goto after_7;
    // 0x800CA138: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x800CA13C: bgtz        $v0, L_800CA0F0
    if (SIGNED(ctx->r2) > 0) {
        // 0x800CA140: nop
    
            goto L_800CA0F0;
    }
    // 0x800CA140: nop

L_800CA144:
    // 0x800CA144: jal         0x800B2928
    // 0x800CA148: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    vector_size(rdram, ctx);
        goto after_8;
    // 0x800CA148: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_8:
    // 0x800CA14C: bnel        $v0, $zero, L_800CA164
    if (ctx->r2 != 0) {
        // 0x800CA150: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800CA164;
    }
    goto skip_1;
    // 0x800CA150: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800CA154: jal         0x800B2D28
    // 0x800CA158: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    vector_free(rdram, ctx);
        goto after_9;
    // 0x800CA158: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_9:
    // 0x800CA15C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800CA160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800CA164:
    // 0x800CA164: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800CA168: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800CA16C: jr          $ra
    // 0x800CA170: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800CA170: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_800A9800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9800: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A9804: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9808: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A980C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A9810: jal         0x800A9828
    // 0x800A9814: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800A9828(rdram, ctx);
        goto after_0;
    // 0x800A9814: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800A9818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A981C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A9820: jr          $ra
    // 0x800A9824: nop

    return;
    // 0x800A9824: nop

;}
RECOMP_FUNC void func_80808E78_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808E78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80808E7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80808E80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80808E84: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80808E88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80808E8C: jal         0x80804848
    // 0x80808E90: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    func_80804848_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80808E90: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    after_0:
    // 0x80808E94: jal         0x80801928
    // 0x80808E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801928_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80808E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80808E9C: jal         0x80801DC0
    // 0x80808EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801DC0_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80808EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80808EA4: jal         0x80808DB0
    // 0x80808EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808DB0_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80808EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80808EAC: jal         0x80809D24
    // 0x80808EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80809D24_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x80808EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80808EB4: jal         0x8080682C
    // 0x80808EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080682C_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x80808EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80808EBC: jal         0x808099B4
    // 0x80808EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808099B4_bsfirstp(rdram, ctx);
        goto after_6;
    // 0x80808EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80808EC4: jal         0x80800830
    // 0x80808EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800830_bsfirstp(rdram, ctx);
        goto after_7;
    // 0x80808EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80808ECC: jal         0x80808EF0
    // 0x80808ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808EF0_bsfirstp(rdram, ctx);
        goto after_8;
    // 0x80808ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80808ED4: jal         0x80802F20
    // 0x80808ED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802F20_bsfirstp(rdram, ctx);
        goto after_9;
    // 0x80808ED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80808EDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80808EE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80808EE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80808EE8: jr          $ra
    // 0x80808EEC: nop

    return;
    // 0x80808EEC: nop

;}
RECOMP_FUNC void bsrest_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800688: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080068C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(344, 0X930) << 16);
    // 0x80800690: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800694: jr          $ra
    // 0x80800698: lw          $v0, 0x930($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(344, 0X930));
    return;
    // 0x80800698: lw          $v0, 0x930($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(344, 0X930));
;}
RECOMP_FUNC void func_8080049C_bsbanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080049C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004A4: jal         0x808003BC
    // 0x808004A8: nop

    func_808003BC_bsbanswim(rdram, ctx);
        goto after_0;
    // 0x808004A8: nop

    after_0:
    // 0x808004AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004B4: jr          $ra
    // 0x808004B8: nop

    return;
    // 0x808004B8: nop

;}
RECOMP_FUNC void func_80800B60_chtransparentfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B60: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80800B64: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800B68: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2232, 0X10E0) << 16);
    // 0x80800B6C: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2232, 0X11D0) << 16);
    // 0x80800B70: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800B74: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800B78: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800B7C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800B80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800B84: addiu       $v1, $v1, 0x11D0
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(2232, 0X11D0));
    // 0x80800B88: addiu       $v0, $v0, 0x10E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2232, 0X10E0));
    // 0x80800B8C: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
L_80800B90:
    // 0x80800B90: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80800B94: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80800B98: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x80800B9C: sw          $s4, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->r20;
    // 0x80800BA0: bne         $at, $zero, L_80800B90
    if (ctx->r1 != 0) {
        // 0x80800BA4: sw          $s4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r20;
            goto L_80800B90;
    }
    // 0x80800BA4: sw          $s4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r20;
    // 0x80800BA8: addiu       $a0, $zero, 0x295
    ctx->r4 = ADD32(0, 0X295);
    // 0x80800BAC: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80800BB0: jal         0x800882C0
    // 0x80800BB4: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800BB4: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_0:
    // 0x80800BB8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800BBC: blez        $v0, L_80800C08
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800BC0: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_80800C08;
    }
    // 0x80800BC0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80800BC4: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2232, 0X10E0) << 16);
    // 0x80800BC8: addiu       $s1, $sp, 0x54
    ctx->r17 = ADD32(ctx->r29, 0X54);
    // 0x80800BCC: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80800BD0: addu        $s3, $t7, $s1
    ctx->r19 = ADD32(ctx->r15, ctx->r17);
    // 0x80800BD4: addiu       $s0, $s0, 0x10E0
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2232, 0X10E0));
L_80800BD8:
    // 0x80800BD8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80800BDC: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x80800BE0: srl         $t9, $t8, 21
    ctx->r25 = S32(U32(ctx->r24) >> 21);
    // 0x80800BE4: jal         0x80088BE8
    // 0x80800BE8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    _gspropctrl_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800BE8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    after_1:
    // 0x80800BEC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800BF0: sltu        $at, $s1, $s3
    ctx->r1 = ctx->r17 < ctx->r19 ? 1 : 0;
    // 0x80800BF4: addiu       $t1, $v0, -0x32
    ctx->r9 = ADD32(ctx->r2, -0X32);
    // 0x80800BF8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80800BFC: bne         $at, $zero, L_80800BD8
    if (ctx->r1 != 0) {
        // 0x80800C00: sw          $t1, -0x8($s0)
        MEM_W(-0X8, ctx->r16) = ctx->r9;
            goto L_80800BD8;
    }
    // 0x80800C00: sw          $t1, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = ctx->r9;
    // 0x80800C04: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80800C08:
    // 0x80800C08: blez        $s2, L_80800D28
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80800C0C: nop
    
            goto L_80800D28;
    }
    // 0x80800C0C: nop

L_80800C10:
    // 0x80800C10: blez        $s2, L_80800D1C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80800C14: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80800D1C;
    }
    // 0x80800C14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800C18: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x80800C1C: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x80800C20: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(2232, 0X10E0) << 16);
    // 0x80800C24: addiu       $t3, $t3, 0x10E0
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(2232, 0X10E0));
    // 0x80800C28: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80800C2C: andi        $v0, $s2, 0x3
    ctx->r2 = ctx->r18 & 0X3;
    // 0x80800C30: beq         $v0, $zero, L_80800C78
    if (ctx->r2 == 0) {
        // 0x80800C34: addu        $s0, $t2, $t3
        ctx->r16 = ADD32(ctx->r10, ctx->r11);
            goto L_80800C78;
    }
    // 0x80800C34: addu        $s0, $t2, $t3
    ctx->r16 = ADD32(ctx->r10, ctx->r11);
    // 0x80800C38: sll         $t4, $zero, 2
    ctx->r12 = S32(0 << 2);
    // 0x80800C3C: subu        $t4, $t4, $zero
    ctx->r12 = SUB32(ctx->r12, 0);
    // 0x80800C40: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80800C44: addu        $a0, $t4, $t3
    ctx->r4 = ADD32(ctx->r12, ctx->r11);
    // 0x80800C48: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_80800C4C:
    // 0x80800C4C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80800C50: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80800C54: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80800C58: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80800C5C: beq         $at, $zero, L_80800C6C
    if (ctx->r1 == 0) {
        // 0x80800C60: nop
    
            goto L_80800C6C;
    }
    // 0x80800C60: nop

    // 0x80800C64: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80800C68: sw          $a1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r5;
L_80800C6C:
    // 0x80800C6C: bne         $a3, $a2, L_80800C4C
    if (ctx->r7 != ctx->r6) {
        // 0x80800C70: addiu       $a0, $a0, 0xC
        ctx->r4 = ADD32(ctx->r4, 0XC);
            goto L_80800C4C;
    }
    // 0x80800C70: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x80800C74: beq         $a2, $s2, L_80800D1C
    if (ctx->r6 == ctx->r18) {
        // 0x80800C78: sll         $t5, $a2, 2
        ctx->r13 = S32(ctx->r6 << 2);
            goto L_80800D1C;
    }
L_80800C78:
    // 0x80800C78: sll         $t5, $a2, 2
    ctx->r13 = S32(ctx->r6 << 2);
    // 0x80800C7C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2232, 0X10E0) << 16);
    // 0x80800C80: sll         $t6, $s2, 2
    ctx->r14 = S32(ctx->r18 << 2);
    // 0x80800C84: subu        $t6, $t6, $s2
    ctx->r14 = SUB32(ctx->r14, ctx->r18);
    // 0x80800C88: addiu       $t7, $t7, 0x10E0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2232, 0X10E0));
    // 0x80800C8C: subu        $t5, $t5, $a2
    ctx->r13 = SUB32(ctx->r13, ctx->r6);
    // 0x80800C90: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80800C94: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800C98: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x80800C9C: addu        $a0, $t5, $t7
    ctx->r4 = ADD32(ctx->r13, ctx->r15);
    // 0x80800CA0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80800CA4:
    // 0x80800CA4: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80800CA8: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80800CAC: beql        $at, $zero, L_80800CC4
    if (ctx->r1 == 0) {
        // 0x80800CB0: lw          $a1, 0xC($a0)
        ctx->r5 = MEM_W(ctx->r4, 0XC);
            goto L_80800CC4;
    }
    goto skip_0;
    // 0x80800CB0: lw          $a1, 0xC($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XC);
    skip_0:
    // 0x80800CB4: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80800CB8: sw          $a1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r5;
    // 0x80800CBC: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80800CC0: lw          $a1, 0xC($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XC);
L_80800CC4:
    // 0x80800CC4: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80800CC8: beql        $at, $zero, L_80800CE0
    if (ctx->r1 == 0) {
        // 0x80800CCC: lw          $a1, 0x18($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X18);
            goto L_80800CE0;
    }
    goto skip_1;
    // 0x80800CCC: lw          $a1, 0x18($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X18);
    skip_1:
    // 0x80800CD0: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    // 0x80800CD4: sw          $a1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r5;
    // 0x80800CD8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80800CDC: lw          $a1, 0x18($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X18);
L_80800CE0:
    // 0x80800CE0: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80800CE4: beql        $at, $zero, L_80800CFC
    if (ctx->r1 == 0) {
        // 0x80800CE8: lw          $a1, 0x24($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X24);
            goto L_80800CFC;
    }
    goto skip_2;
    // 0x80800CE8: lw          $a1, 0x24($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X24);
    skip_2:
    // 0x80800CEC: sw          $v1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r3;
    // 0x80800CF0: sw          $a1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r5;
    // 0x80800CF4: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80800CF8: lw          $a1, 0x24($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X24);
L_80800CFC:
    // 0x80800CFC: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80800D00: beql        $at, $zero, L_80800D14
    if (ctx->r1 == 0) {
        // 0x80800D04: addiu       $a0, $a0, 0x30
        ctx->r4 = ADD32(ctx->r4, 0X30);
            goto L_80800D14;
    }
    goto skip_3;
    // 0x80800D04: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    skip_3:
    // 0x80800D08: sw          $v1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r3;
    // 0x80800D0C: sw          $a1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r5;
    // 0x80800D10: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
L_80800D14:
    // 0x80800D14: bnel        $a0, $a3, L_80800CA4
    if (ctx->r4 != ctx->r7) {
        // 0x80800D18: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_80800CA4;
    }
    goto skip_4;
    // 0x80800D18: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_4:
L_80800D1C:
    // 0x80800D1C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80800D20: bne         $t0, $s2, L_80800C10
    if (ctx->r8 != ctx->r18) {
        // 0x80800D24: nop
    
            goto L_80800C10;
    }
    // 0x80800D24: nop

L_80800D28:
    // 0x80800D28: jal         0x800DA298
    // 0x80800D2C: addiu       $a0, $zero, 0x6C0
    ctx->r4 = ADD32(0, 0X6C0);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800D2C: addiu       $a0, $zero, 0x6C0
    ctx->r4 = ADD32(0, 0X6C0);
    after_2:
    // 0x80800D30: beq         $v0, $zero, L_80800D4C
    if (ctx->r2 == 0) {
        // 0x80800D34: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800D4C;
    }
    // 0x80800D34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800D38: addiu       $a0, $zero, 0x6C1
    ctx->r4 = ADD32(0, 0X6C1);
    // 0x80800D3C: jal         0x800DA564
    // 0x80800D40: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800DA564(rdram, ctx);
        goto after_3;
    // 0x80800D40: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x80800D44: b           L_80800D70
    // 0x80800D48: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_80800D70;
    // 0x80800D48: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80800D4C:
    // 0x80800D4C: jal         0x800DC128
    // 0x80800D50: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    func_800DC128(rdram, ctx);
        goto after_4;
    // 0x80800D50: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    after_4:
    // 0x80800D54: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800D58: addiu       $a0, $zero, 0x6C1
    ctx->r4 = ADD32(0, 0X6C1);
    // 0x80800D5C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800D60: jal         0x800DA7A8
    // 0x80800D64: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_800DA7A8(rdram, ctx);
        goto after_5;
    // 0x80800D64: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_5:
    // 0x80800D68: jal         0x800DA544
    // 0x80800D6C: addiu       $a0, $zero, 0x6C0
    ctx->r4 = ADD32(0, 0X6C0);
    func_800DA544(rdram, ctx);
        goto after_6;
    // 0x80800D6C: addiu       $a0, $zero, 0x6C0
    ctx->r4 = ADD32(0, 0X6C0);
    after_6:
L_80800D70:
    // 0x80800D70: jal         0x800DC090
    // 0x80800D74: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    func_800DC090(rdram, ctx);
        goto after_7;
    // 0x80800D74: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    after_7:
    // 0x80800D78: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x80800D7C: jal         0x800DC324
    // 0x80800D80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800DC324(rdram, ctx);
        goto after_8;
    // 0x80800D80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800D84: jal         0x80800E10
    // 0x80800D88: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80800E10_chtransparentfish(rdram, ctx);
        goto after_9;
    // 0x80800D88: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x80800D8C: bne         $v0, $zero, L_80800DE8
    if (ctx->r2 != 0) {
        // 0x80800D90: addiu       $s1, $zero, 0xC
        ctx->r17 = ADD32(0, 0XC);
            goto L_80800DE8;
    }
    // 0x80800D90: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
    // 0x80800D94: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2232, 0X10E0) << 16);
    // 0x80800D98: addiu       $s0, $s0, 0x10E0
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2232, 0X10E0));
    // 0x80800D9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80800DA0:
    // 0x80800DA0: jal         0x800DC128
    // 0x80800DA4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800DC128(rdram, ctx);
        goto after_10;
    // 0x80800DA4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_10:
    // 0x80800DA8: multu       $v0, $s1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800DAC: mflo        $t8
    ctx->r24 = lo;
    // 0x80800DB0: addu        $v1, $s0, $t8
    ctx->r3 = ADD32(ctx->r16, ctx->r24);
    // 0x80800DB4: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x80800DB8: bne         $s4, $t9, L_80800DD8
    if (ctx->r20 != ctx->r25) {
        // 0x80800DBC: nop
    
            goto L_80800DD8;
    }
    // 0x80800DBC: nop

    // 0x80800DC0: multu       $s3, $s1
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800DC4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80800DC8: mflo        $t1
    ctx->r9 = lo;
    // 0x80800DCC: addu        $t2, $s0, $t1
    ctx->r10 = ADD32(ctx->r16, ctx->r9);
    // 0x80800DD0: lw          $t4, 0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X4);
    // 0x80800DD4: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
L_80800DD8:
    // 0x80800DD8: jal         0x80800E10
    // 0x80800DDC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80800E10_chtransparentfish(rdram, ctx);
        goto after_11;
    // 0x80800DDC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_11:
    // 0x80800DE0: beql        $v0, $zero, L_80800DA0
    if (ctx->r2 == 0) {
        // 0x80800DE4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800DA0;
    }
    goto skip_5;
    // 0x80800DE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_5:
L_80800DE8:
    // 0x80800DE8: jal         0x800DC324
    // 0x80800DEC: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    func_800DC324(rdram, ctx);
        goto after_12;
    // 0x80800DEC: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    after_12:
    // 0x80800DF0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800DF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800DF8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DFC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800E00: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800E04: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800E08: jr          $ra
    // 0x80800E0C: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80800E0C: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_800DF464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF464: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF468: jr          $ra
    // 0x800DF46C: swc1        $f12, -0x37D0($at)
    MEM_W(-0X37D0, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x800DF46C: swc1        $f12, -0x37D0($at)
    MEM_W(-0X37D0, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void chclimbbase_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080038C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(680, 0X3D0) << 16);
    // 0x80800390: jr          $ra
    // 0x80800394: addiu       $v0, $v0, 0x3D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(680, 0X3D0));
    return;
    // 0x80800394: addiu       $v0, $v0, 0x3D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(680, 0X3D0));
;}
RECOMP_FUNC void func_8080000C_chgruntyfireballbig(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x80800018: jal         0x80109EEC
    // 0x8080001C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80109EEC(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_0:
    // 0x80800020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800028: jr          $ra
    // 0x8080002C: nop

    return;
    // 0x8080002C: nop

;}
RECOMP_FUNC void func_800A32F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A32F8: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A32FC: jr          $ra
    // 0x800A3300: lw          $v0, 0x44($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X44);
    return;
    // 0x800A3300: lw          $v0, 0x44($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X44);
;}
RECOMP_FUNC void _basub_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800851D0: syscall     154
    recomp_syscall_handler(rdram, ctx, 0x800851D0);
    return;
    // 0x800851D4: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void ncbaclimb_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080004C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800050: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800054: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x80800058: jal         0x80111B8C
    // 0x8080005C: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    func_80111B8C(rdram, ctx);
        goto after_0;
    // 0x8080005C: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    after_0:
    // 0x80800060: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800064: jal         0x801124D0
    // 0x80800068: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_801124D0(rdram, ctx);
        goto after_1;
    // 0x80800068: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x8080006C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800070: jal         0x80115858
    // 0x80800074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80115858(rdram, ctx);
        goto after_2;
    // 0x80800074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800078: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080007C: jal         0x80115870
    // 0x80800080: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80115870(rdram, ctx);
        goto after_3;
    // 0x80800080: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800088: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080008C: jr          $ra
    // 0x80800090: nop

    return;
    // 0x80800090: nop

;}
RECOMP_FUNC void _chbounce_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800858D0: syscall     180
    recomp_syscall_handler(rdram, ctx, 0x800858D0);
    return;
    // 0x800858D4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void idlight_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sll         $t7, $a3, 4
    ctx->r15 = S32(ctx->r7 << 4);
    // 0x80800004: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80800008: addu        $v0, $t7, $a1
    ctx->r2 = ADD32(ctx->r15, ctx->r5);
    // 0x8080000C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800010: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x80800014: beq         $at, $zero, L_80800230
    if (ctx->r1 == 0) {
        // 0x80800018: lwc1        $f0, 0x0($t6)
        ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
            goto L_80800230;
    }
    // 0x80800018: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
L_8080001C:
    // 0x8080001C: lbu         $t8, 0xC($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XC);
    // 0x80800020: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800024: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80800028: bgez        $t8, L_8080003C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8080002C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8080003C;
    }
    // 0x8080002C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800030: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800034: nop

    // 0x80800038: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8080003C:
    // 0x8080003C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800040: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800044: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800048: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8080004C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80800050: nop

    // 0x80800054: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80800058: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8080005C: nop

    // 0x80800060: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80800064: beql        $t0, $zero, L_808000B4
    if (ctx->r8 == 0) {
        // 0x80800068: mfc1        $t0, $f16
        ctx->r8 = (int32_t)ctx->f16.u32l;
            goto L_808000B4;
    }
    goto skip_0;
    // 0x80800068: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x8080006C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800070: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800074: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80800078: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8080007C: nop

    // 0x80800080: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80800084: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80800088: nop

    // 0x8080008C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80800090: bne         $t0, $zero, L_808000A8
    if (ctx->r8 != 0) {
        // 0x80800094: nop
    
            goto L_808000A8;
    }
    // 0x80800094: nop

    // 0x80800098: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x8080009C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808000A0: b           L_808000C0
    // 0x808000A4: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_808000C0;
    // 0x808000A4: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_808000A8:
    // 0x808000A8: b           L_808000C0
    // 0x808000AC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_808000C0;
    // 0x808000AC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x808000B0: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
L_808000B4:
    // 0x808000B4: nop

    // 0x808000B8: bltz        $t0, L_808000A8
    if (SIGNED(ctx->r8) < 0) {
        // 0x808000BC: nop
    
            goto L_808000A8;
    }
    // 0x808000BC: nop

L_808000C0:
    // 0x808000C0: sb          $t0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r8;
    // 0x808000C4: lbu         $t1, 0xD($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0XD);
    // 0x808000C8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x808000CC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808000D0: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x808000D4: bgez        $t1, L_808000E8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808000D8: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_808000E8;
    }
    // 0x808000D8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808000DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000E0: nop

    // 0x808000E4: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_808000E8:
    // 0x808000E8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x808000EC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x808000F0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808000F4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x808000F8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x808000FC: nop

    // 0x80800100: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800104: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80800108: nop

    // 0x8080010C: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80800110: beql        $t3, $zero, L_80800160
    if (ctx->r11 == 0) {
        // 0x80800114: mfc1        $t3, $f10
        ctx->r11 = (int32_t)ctx->f10.u32l;
            goto L_80800160;
    }
    goto skip_1;
    // 0x80800114: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x80800118: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080011C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800120: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80800124: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80800128: nop

    // 0x8080012C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80800130: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80800134: nop

    // 0x80800138: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x8080013C: bne         $t3, $zero, L_80800154
    if (ctx->r11 != 0) {
        // 0x80800140: nop
    
            goto L_80800154;
    }
    // 0x80800140: nop

    // 0x80800144: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x80800148: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080014C: b           L_8080016C
    // 0x80800150: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_8080016C;
    // 0x80800150: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80800154:
    // 0x80800154: b           L_8080016C
    // 0x80800158: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_8080016C;
    // 0x80800158: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8080015C: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
L_80800160:
    // 0x80800160: nop

    // 0x80800164: bltz        $t3, L_80800154
    if (SIGNED(ctx->r11) < 0) {
        // 0x80800168: nop
    
            goto L_80800154;
    }
    // 0x80800168: nop

L_8080016C:
    // 0x8080016C: sb          $t3, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r11;
    // 0x80800170: lbu         $t4, 0xE($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0XE);
    // 0x80800174: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80800178: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8080017C: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80800180: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800184: bgez        $t4, L_80800198
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800188: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80800198;
    }
    // 0x80800188: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8080018C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800190: nop

    // 0x80800194: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
L_80800198:
    // 0x80800198: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8080019C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808001A0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808001A4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x808001A8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x808001AC: nop

    // 0x808001B0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x808001B4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x808001B8: nop

    // 0x808001BC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x808001C0: beql        $t6, $zero, L_80800210
    if (ctx->r14 == 0) {
        // 0x808001C4: mfc1        $t6, $f6
        ctx->r14 = (int32_t)ctx->f6.u32l;
            goto L_80800210;
    }
    goto skip_2;
    // 0x808001C4: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    skip_2:
    // 0x808001C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001CC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808001D0: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808001D4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x808001D8: nop

    // 0x808001DC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x808001E0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x808001E4: nop

    // 0x808001E8: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x808001EC: bne         $t6, $zero, L_80800204
    if (ctx->r14 != 0) {
        // 0x808001F0: nop
    
            goto L_80800204;
    }
    // 0x808001F0: nop

    // 0x808001F4: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x808001F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808001FC: b           L_8080021C
    // 0x80800200: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_8080021C;
    // 0x80800200: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80800204:
    // 0x80800204: b           L_8080021C
    // 0x80800208: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_8080021C;
    // 0x80800208: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8080020C: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
L_80800210:
    // 0x80800210: nop

    // 0x80800214: bltz        $t6, L_80800204
    if (SIGNED(ctx->r14) < 0) {
        // 0x80800218: nop
    
            goto L_80800204;
    }
    // 0x80800218: nop

L_8080021C:
    // 0x8080021C: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x80800220: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80800224: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80800228: bne         $at, $zero, L_8080001C
    if (ctx->r1 != 0) {
        // 0x8080022C: sb          $t6, -0x2($a2)
        MEM_B(-0X2, ctx->r6) = ctx->r14;
            goto L_8080001C;
    }
    // 0x8080022C: sb          $t6, -0x2($a2)
    MEM_B(-0X2, ctx->r6) = ctx->r14;
L_80800230:
    // 0x80800230: jr          $ra
    // 0x80800234: nop

    return;
    // 0x80800234: nop

;}
RECOMP_FUNC void _subaddiemarker_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A0C8: syscall     827
    recomp_syscall_handler(rdram, ctx, 0x8008A0C8);
    return;
    // 0x8008A0CC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bscarry_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006CC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808006D0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(132, 0X7E0) << 16);
    // 0x808006D4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808006D8: jr          $ra
    // 0x808006DC: lw          $v0, 0x7E0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(132, 0X7E0));
    return;
    // 0x808006DC: lw          $v0, 0x7E0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(132, 0X7E0));
;}
RECOMP_FUNC void func_800F2D34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2D34: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800F2D38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F2D3C: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
    // 0x800F2D40: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800F2D44: lwc1        $f16, 0x4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F2D48: swc1        $f6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f6.u32l;
    // 0x800F2D4C: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800F2D50: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F2D54: swc1        $f8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f8.u32l;
    // 0x800F2D58: lwc1        $f10, 0xC($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800F2D5C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x800F2D60: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800F2D64: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800F2D68: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800F2D6C: lwc1        $f18, 0xC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800F2D70: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800F2D74: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800F2D78: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800F2D7C: lwc1        $f18, 0x10($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F2D80: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800F2D84: lwc1        $f10, 0x30($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800F2D88: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800F2D8C: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800F2D90: add.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800F2D94: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x800F2D98: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F2D9C: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800F2DA0: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F2DA4: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800F2DA8: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800F2DAC: lwc1        $f10, 0xC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800F2DB0: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800F2DB4: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800F2DB8: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800F2DBC: lwc1        $f10, 0x10($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F2DC0: add.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800F2DC4: lwc1        $f16, 0x34($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800F2DC8: mul.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800F2DCC: add.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800F2DD0: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800F2DD4: swc1        $f8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f8.u32l;
    // 0x800F2DD8: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F2DDC: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800F2DE0: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F2DE4: lwc1        $f18, 0x18($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800F2DE8: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800F2DEC: lwc1        $f16, 0xC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800F2DF0: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800F2DF4: lwc1        $f6, 0x28($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800F2DF8: mul.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800F2DFC: lwc1        $f16, 0x10($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F2E00: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800F2E04: lwc1        $f8, 0x38($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X38);
    // 0x800F2E08: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800F2E0C: add.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800F2E10: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800F2E14: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    // 0x800F2E18: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800F2E1C: lwc1        $f18, 0x4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F2E20: lwc1        $f10, 0x1C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800F2E24: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F2E28: mul.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800F2E2C: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800F2E30: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800F2E34: lwc1        $f6, 0x2C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800F2E38: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800F2E3C: lwc1        $f8, 0x10($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F2E40: add.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800F2E44: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x800F2E48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F2E4C: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800F2E50: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x800F2E54: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800F2E58: jr          $ra
    // 0x800F2E5C: swc1        $f18, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f18.u32l;
    return;
    // 0x800F2E5C: swc1        $f18, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_808000B0_chswappy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000BC: jal         0x80101FDC
    // 0x808000C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x808000C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808000C4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808000C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000D0: beq         $a1, $at, L_808000F0
    if (ctx->r5 == ctx->r1) {
        // 0x808000D4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000F0;
    }
    // 0x808000D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000D8: beq         $a1, $at, L_808000F8
    if (ctx->r5 == ctx->r1) {
        // 0x808000DC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808000F8;
    }
    // 0x808000DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000E0: beql        $a1, $at, L_808000FC
    if (ctx->r5 == ctx->r1) {
        // 0x808000E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000FC;
    }
    goto skip_0;
    // 0x808000E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000E8: b           L_808000FC
    // 0x808000EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000FC;
    // 0x808000EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000F0:
    // 0x808000F0: jal         0x8008A4B0
    // 0x808000F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x808000F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_808000F8:
    // 0x808000F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000FC:
    // 0x808000FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800100: jr          $ra
    // 0x80800104: nop

    return;
    // 0x80800104: nop

;}
RECOMP_FUNC void func_80800000_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: beq         $a2, $zero, L_8080002C
    if (ctx->r6 == 0) {
        // 0x80800010: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8080002C;
    }
    // 0x80800010: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800014: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800018: jal         0x80091A58
    // 0x8080001C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x8080001C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800020: beq         $v0, $zero, L_8080002C
    if (ctx->r2 == 0) {
        // 0x80800024: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_8080002C;
    }
    // 0x80800024: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80800028: addiu       $a3, $zero, 0x169
    ctx->r7 = ADD32(0, 0X169);
L_8080002C:
    // 0x8080002C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800030: jal         0x8008E148
    // 0x80800034: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_8008E148(rdram, ctx);
        goto after_1;
    // 0x80800034: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800038: beq         $v0, $zero, L_80800044
    if (ctx->r2 == 0) {
        // 0x8080003C: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_80800044;
    }
    // 0x8080003C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80800040: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80800044:
    // 0x80800044: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080004C: lbu         $t7, 0x15F($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X15F);
    // 0x80800050: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80800054: bnel        $t7, $zero, L_80800074
    if (ctx->r15 != 0) {
        // 0x80800058: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800074;
    }
    goto skip_0;
    // 0x80800058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080005C: jal         0x80091A30
    // 0x80800060: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    bakey_released(rdram, ctx);
        goto after_2;
    // 0x80800060: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x80800064: beq         $v0, $zero, L_80800070
    if (ctx->r2 == 0) {
        // 0x80800068: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_80800070;
    }
    // 0x80800068: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8080006C: addiu       $a3, $zero, 0x164
    ctx->r7 = ADD32(0, 0X164);
L_80800070:
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800074:
    // 0x80800074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800078: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8080007C: jr          $ra
    // 0x80800080: nop

    return;
    // 0x80800080: nop

;}
RECOMP_FUNC void _chjollyroger_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F60: syscall     264
    recomp_syscall_handler(rdram, ctx, 0x80085F60);
    return;
    // 0x80085F64: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _chevilmumbo_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086BD0: syscall     426
    recomp_syscall_handler(rdram, ctx, 0x80086BD0);
    return;
    // 0x80086BD4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800264_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800264: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080026C: jal         0x8008D04C
    // 0x80800270: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8008D04C(rdram, ctx);
        goto after_0;
    // 0x80800270: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800274: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800278: jal         0x8008B10C
    // 0x8080027C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8008B10C(rdram, ctx);
        goto after_1;
    // 0x8080027C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800284: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800288: jr          $ra
    // 0x8080028C: nop

    return;
    // 0x8080028C: nop

;}
RECOMP_FUNC void func_80800BFC_chnewfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BFC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800C00: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80800C04: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80800C08: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800C0C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80800C10: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800C14: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80800C18: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80800C1C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80800C20: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80800C24: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800C28: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800C2C: jal         0x80100094
    // 0x80800C30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800C34: jal         0x800DF324
    // 0x80800C38: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800DF324(rdram, ctx);
        goto after_1;
    // 0x80800C38: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_1:
    // 0x80800C3C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80800C40: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800C44: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800C48: jal         0x800AE1E8
    // 0x80800C4C: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    func_800AE1E8(rdram, ctx);
        goto after_2;
    // 0x80800C4C: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    after_2:
    // 0x80800C50: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80800C54: jal         0x800AE080
    // 0x80800C58: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    func_800AE080(rdram, ctx);
        goto after_3;
    // 0x80800C58: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    after_3:
    // 0x80800C5C: lw          $t8, 0x6C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X6C);
    // 0x80800C60: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80800C64: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800C68: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80800C6C: beq         $t9, $zero, L_80800CFC
    if (ctx->r25 == 0) {
        // 0x80800C70: addiu       $s5, $s2, 0x44
        ctx->r21 = ADD32(ctx->r18, 0X44);
            goto L_80800CFC;
    }
    // 0x80800C70: addiu       $s5, $s2, 0x44
    ctx->r21 = ADD32(ctx->r18, 0X44);
    // 0x80800C74: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800C78: addiu       $s6, $s2, 0x4
    ctx->r22 = ADD32(ctx->r18, 0X4);
    // 0x80800C7C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80800C80:
    // 0x80800C80: jal         0x80087A28
    // 0x80800C84: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _dbskeleton_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800C84: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80800C88: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800C8C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800C90: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800C94: jal         0x800AE630
    // 0x80800C98: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_800AE630(rdram, ctx);
        goto after_5;
    // 0x80800C98: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_5:
    // 0x80800C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CA0: jal         0x800EF334
    // 0x80800CA4: lw          $a1, 0x34($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X34);
    func_800EF334(rdram, ctx);
        goto after_6;
    // 0x80800CA4: lw          $a1, 0x34($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X34);
    after_6:
    // 0x80800CA8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800CAC: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80800CB0: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x80800CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CB8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80800CBC: jal         0x800EF5A0
    // 0x80800CC0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800EF5A0(rdram, ctx);
        goto after_7;
    // 0x80800CC0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x80800CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CC8: jal         0x800EF04C
    // 0x80800CCC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800EF04C(rdram, ctx);
        goto after_8;
    // 0x80800CCC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_8:
    // 0x80800CD0: swc1        $f20, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f20.u32l;
    // 0x80800CD4: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    // 0x80800CD8: jal         0x800EE7F8
    // 0x80800CDC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x80800CDC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x80800CE0: lw          $t0, 0x6C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X6C);
    // 0x80800CE4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800CE8: addiu       $s0, $s0, 0x60
    ctx->r16 = ADD32(ctx->r16, 0X60);
    // 0x80800CEC: andi        $t1, $t0, 0x1FF
    ctx->r9 = ctx->r8 & 0X1FF;
    // 0x80800CF0: sltu        $at, $s1, $t1
    ctx->r1 = ctx->r17 < ctx->r9 ? 1 : 0;
    // 0x80800CF4: bnel        $at, $zero, L_80800C80
    if (ctx->r1 != 0) {
        // 0x80800CF8: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800C80;
    }
    goto skip_0;
    // 0x80800CF8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
L_80800CFC:
    // 0x80800CFC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80800D00: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800D04: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800D08: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80800D0C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80800D10: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80800D14: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80800D18: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80800D1C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80800D20: jr          $ra
    // 0x80800D24: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800D24: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8080003C_chrainbow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800040: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800044: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800048: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x8080004C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800050: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800054: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800058: sltiu       $at, $t8, 0xD
    ctx->r1 = ctx->r24 < 0XD ? 1 : 0;
    // 0x8080005C: beq         $at, $zero, L_80800220
    if (ctx->r1 == 0) {
        // 0x80800060: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800220;
    }
    // 0x80800060: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800064: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2360, 0XF50) << 16);
    // 0x80800068: addu        $at, $at, $t8
    gpr jr_addend_80800070 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8080006C: lw          $t8, 0xF50($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2360, 0XF50));
    // 0x80800070: jr          $t8
    // 0x80800074: nop

    switch (jr_addend_80800070 >> 2) {
        case 0: goto L_80800078; break;
        case 1: goto L_80800098; break;
        case 2: goto L_808000B8; break;
        case 3: goto L_808000DC; break;
        case 4: goto L_80800124; break;
        case 5: goto L_80800148; break;
        case 6: goto L_80800220; break;
        case 7: goto L_8080016C; break;
        case 8: goto L_80800220; break;
        case 9: goto L_80800220; break;
        case 10: goto L_80800220; break;
        case 11: goto L_80800190; break;
        case 12: goto L_808001D4; break;
        default: switch_error(__func__, 0x80800070, 0x80800F50);
    }
    // 0x80800074: nop

L_80800078:
    // 0x80800078: jal         0x801065A4
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801065A4(rdram, ctx);
        goto after_0;
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800080: beq         $v0, $zero, L_80800220
    if (ctx->r2 == 0) {
        // 0x80800084: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800220;
    }
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800088: jal         0x80103110
    // 0x8080008C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x8080008C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800090: b           L_80800220
    // 0x80800094: nop

        goto L_80800220;
    // 0x80800094: nop

L_80800098:
    // 0x80800098: jal         0x800DA298
    // 0x8080009C: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x8080009C: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_2:
    // 0x808000A0: beq         $v0, $zero, L_80800220
    if (ctx->r2 == 0) {
        // 0x808000A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800220;
    }
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A8: jal         0x80800270
    // 0x808000AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800270_chrainbow(rdram, ctx);
        goto after_3;
    // 0x808000AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x808000B0: b           L_80800220
    // 0x808000B4: nop

        goto L_80800220;
    // 0x808000B4: nop

L_808000B8:
    // 0x808000B8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x808000BC: jal         0x800D91EC
    // 0x808000C0: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    func_800D91EC(rdram, ctx);
        goto after_4;
    // 0x808000C0: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_4:
    // 0x808000C4: beq         $v0, $zero, L_80800220
    if (ctx->r2 == 0) {
        // 0x808000C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800220;
    }
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000CC: jal         0x80800270
    // 0x808000D0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800270_chrainbow(rdram, ctx);
        goto after_5;
    // 0x808000D0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x808000D4: b           L_80800220
    // 0x808000D8: nop

        goto L_80800220;
    // 0x808000D8: nop

L_808000DC:
    // 0x808000DC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x808000E0: jal         0x800D91EC
    // 0x808000E4: lui         $a1, 0x40D0
    ctx->r5 = S32(0X40D0 << 16);
    func_800D91EC(rdram, ctx);
        goto after_6;
    // 0x808000E4: lui         $a1, 0x40D0
    ctx->r5 = S32(0X40D0 << 16);
    after_6:
    // 0x808000E8: beq         $v0, $zero, L_808000F8
    if (ctx->r2 == 0) {
        // 0x808000EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000F8;
    }
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F0: jal         0x80800270
    // 0x808000F4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800270_chrainbow(rdram, ctx);
        goto after_7;
    // 0x808000F4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_7:
L_808000F8:
    // 0x808000F8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808000FC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800100: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800104: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800108: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080010C: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    // 0x80800110: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800114: jal         0x800F10B4
    // 0x80800118: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x80800118: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x8080011C: b           L_80800220
    // 0x80800120: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
        goto L_80800220;
    // 0x80800120: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
L_80800124:
    // 0x80800124: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x80800128: jal         0x800D91EC
    // 0x8080012C: lui         $a1, 0x4128
    ctx->r5 = S32(0X4128 << 16);
    func_800D91EC(rdram, ctx);
        goto after_9;
    // 0x8080012C: lui         $a1, 0x4128
    ctx->r5 = S32(0X4128 << 16);
    after_9:
    // 0x80800130: beq         $v0, $zero, L_80800220
    if (ctx->r2 == 0) {
        // 0x80800134: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800220;
    }
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800138: jal         0x80800270
    // 0x8080013C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800270_chrainbow(rdram, ctx);
        goto after_10;
    // 0x8080013C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_10:
    // 0x80800140: b           L_80800220
    // 0x80800144: nop

        goto L_80800220;
    // 0x80800144: nop

L_80800148:
    // 0x80800148: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x8080014C: jal         0x800D91EC
    // 0x80800150: lui         $a1, 0x4158
    ctx->r5 = S32(0X4158 << 16);
    func_800D91EC(rdram, ctx);
        goto after_11;
    // 0x80800150: lui         $a1, 0x4158
    ctx->r5 = S32(0X4158 << 16);
    after_11:
    // 0x80800154: beq         $v0, $zero, L_80800220
    if (ctx->r2 == 0) {
        // 0x80800158: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800220;
    }
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: jal         0x80800270
    // 0x80800160: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800270_chrainbow(rdram, ctx);
        goto after_12;
    // 0x80800160: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_12:
    // 0x80800164: b           L_80800220
    // 0x80800168: nop

        goto L_80800220;
    // 0x80800168: nop

L_8080016C:
    // 0x8080016C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x80800170: jal         0x800D91EC
    // 0x80800174: lui         $a1, 0x4194
    ctx->r5 = S32(0X4194 << 16);
    func_800D91EC(rdram, ctx);
        goto after_13;
    // 0x80800174: lui         $a1, 0x4194
    ctx->r5 = S32(0X4194 << 16);
    after_13:
    // 0x80800178: beq         $v0, $zero, L_80800220
    if (ctx->r2 == 0) {
        // 0x8080017C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800220;
    }
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800180: jal         0x80800270
    // 0x80800184: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80800270_chrainbow(rdram, ctx);
        goto after_14;
    // 0x80800184: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_14:
    // 0x80800188: b           L_80800220
    // 0x8080018C: nop

        goto L_80800220;
    // 0x8080018C: nop

L_80800190:
    // 0x80800190: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x80800194: jal         0x800D91EC
    // 0x80800198: lui         $a1, 0x41A4
    ctx->r5 = S32(0X41A4 << 16);
    func_800D91EC(rdram, ctx);
        goto after_15;
    // 0x80800198: lui         $a1, 0x41A4
    ctx->r5 = S32(0X41A4 << 16);
    after_15:
    // 0x8080019C: beq         $v0, $zero, L_808001AC
    if (ctx->r2 == 0) {
        // 0x808001A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001AC;
    }
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: jal         0x80800270
    // 0x808001A8: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_80800270_chrainbow(rdram, ctx);
        goto after_16;
    // 0x808001A8: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_16:
L_808001AC:
    // 0x808001AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808001B0: lui         $at, 0x4194
    ctx->r1 = S32(0X4194 << 16);
    // 0x808001B4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001B8: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808001BC: lui         $a2, 0x41A4
    ctx->r6 = S32(0X41A4 << 16);
    // 0x808001C0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808001C4: jal         0x800F10B4
    // 0x808001C8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_17;
    // 0x808001C8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_17:
    // 0x808001CC: b           L_80800220
    // 0x808001D0: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
        goto L_80800220;
    // 0x808001D0: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
L_808001D4:
    // 0x808001D4: jal         0x801065A4
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801065A4(rdram, ctx);
        goto after_18;
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808001DC: beq         $v0, $zero, L_80800220
    if (ctx->r2 == 0) {
        // 0x808001E0: nop
    
            goto L_80800220;
    }
    // 0x808001E0: nop

    // 0x808001E4: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x808001E8: sll         $t1, $t9, 11
    ctx->r9 = S32(ctx->r25 << 11);
    // 0x808001EC: bltz        $t1, L_80800220
    if (SIGNED(ctx->r9) < 0) {
        // 0x808001F0: nop
    
            goto L_80800220;
    }
    // 0x808001F0: nop

    // 0x808001F4: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001FC: ori         $t4, $t3, 0x10
    ctx->r12 = ctx->r11 | 0X10;
    // 0x80800200: jal         0x801065A4
    // 0x80800204: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
    func_801065A4(rdram, ctx);
        goto after_19;
    // 0x80800204: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
    after_19:
    // 0x80800208: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8080020C: addiu       $a2, $a2, 0x7620
    ctx->r6 = ADD32(ctx->r6, 0X7620);
    // 0x80800210: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800214: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800218: jal         0x80088660
    // 0x8080021C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_20;
    // 0x8080021C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_20:
L_80800220:
    // 0x80800220: jal         0x80800838
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800838_chrainbow(rdram, ctx);
        goto after_21;
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800228: jal         0x801065A4
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801065A4(rdram, ctx);
        goto after_22;
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800230: beq         $v0, $zero, L_8080025C
    if (ctx->r2 == 0) {
        // 0x80800234: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080025C;
    }
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800238: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x8080023C: addiu       $t5, $t5, 0x7620
    ctx->r13 = ADD32(ctx->r13, 0X7620);
    // 0x80800240: jal         0x801065A4
    // 0x80800244: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    func_801065A4(rdram, ctx);
        goto after_23;
    // 0x80800244: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    after_23:
    // 0x80800248: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080024C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800250: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800254: jal         0x80088660
    // 0x80800258: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_24;
    // 0x80800258: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_24:
L_8080025C:
    // 0x8080025C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800260: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800264: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800268: jr          $ra
    // 0x8080026C: nop

    return;
    // 0x8080026C: nop

;}
RECOMP_FUNC void _gcstatusDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088310: syscall     679
    recomp_syscall_handler(rdram, ctx, 0x80088310);
    return;
    // 0x80088314: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800C2E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2E40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C2E44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C2E48: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C2E4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C2E50: jal         0x800C3CE8
    // 0x800C2E54: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    func_800C3CE8(rdram, ctx);
        goto after_0;
    // 0x800C2E54: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    after_0:
    // 0x800C2E58: jal         0x800C1414
    // 0x800C2E5C: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    func_800C1414(rdram, ctx);
        goto after_1;
    // 0x800C2E5C: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    after_1:
    // 0x800C2E60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C2E64: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C2E68: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800C2E6C: addiu       $t7, $zero, 0x55F0
    ctx->r15 = ADD32(0, 0X55F0);
    // 0x800C2E70: addiu       $t8, $zero, 0x3F
    ctx->r24 = ADD32(0, 0X3F);
    // 0x800C2E74: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800C2E78: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C2E7C: sw          $zero, 0x64($v0)
    MEM_W(0X64, ctx->r2) = 0;
    // 0x800C2E80: sh          $t6, 0x58($v0)
    MEM_H(0X58, ctx->r2) = ctx->r14;
    // 0x800C2E84: sh          $zero, 0x5C($v0)
    MEM_H(0X5C, ctx->r2) = 0;
    // 0x800C2E88: sh          $t7, 0x5A($v0)
    MEM_H(0X5A, ctx->r2) = ctx->r15;
    // 0x800C2E8C: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x800C2E90: sb          $t8, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r24;
    // 0x800C2E94: sb          $t9, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r25;
    // 0x800C2E98: jal         0x800EA05C
    // 0x800C2E9C: swc1        $f4, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f4.u32l;
    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x800C2E9C: swc1        $f4, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f4.u32l;
    after_2:
    // 0x800C2EA0: lhu         $t1, 0x7A($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X7A);
    // 0x800C2EA4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C2EA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C2EAC: andi        $t2, $t1, 0xFC3F
    ctx->r10 = ctx->r9 & 0XFC3F;
    // 0x800C2EB0: sh          $t2, 0x7A($s0)
    MEM_H(0X7A, ctx->r16) = ctx->r10;
    // 0x800C2EB4: lbu         $t3, 0x7B($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X7B);
    // 0x800C2EB8: sb          $t0, 0x63($s0)
    MEM_B(0X63, ctx->r16) = ctx->r8;
    // 0x800C2EBC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800C2EC0: andi        $t6, $t3, 0xFFEF
    ctx->r14 = ctx->r11 & 0XFFEF;
    // 0x800C2EC4: ori         $t8, $t6, 0x2
    ctx->r24 = ctx->r14 | 0X2;
    // 0x800C2EC8: sb          $t6, 0x7B($s0)
    MEM_B(0X7B, ctx->r16) = ctx->r14;
    // 0x800C2ECC: andi        $t0, $t8, 0xF7
    ctx->r8 = ctx->r24 & 0XF7;
    // 0x800C2ED0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800C2ED4: sb          $t8, 0x7B($s0)
    MEM_B(0X7B, ctx->r16) = ctx->r24;
    // 0x800C2ED8: andi        $t2, $t0, 0xDF
    ctx->r10 = ctx->r8 & 0XDF;
    // 0x800C2EDC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C2EE0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C2EE4: sb          $t0, 0x7B($s0)
    MEM_B(0X7B, ctx->r16) = ctx->r8;
    // 0x800C2EE8: sb          $t2, 0x7B($s0)
    MEM_B(0X7B, ctx->r16) = ctx->r10;
    // 0x800C2EEC: andi        $t3, $t2, 0xFB
    ctx->r11 = ctx->r10 & 0XFB;
    // 0x800C2EF0: sh          $v0, 0x5E($s0)
    MEM_H(0X5E, ctx->r16) = ctx->r2;
    // 0x800C2EF4: sb          $t3, 0x7B($s0)
    MEM_B(0X7B, ctx->r16) = ctx->r11;
    // 0x800C2EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2EFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C2F00: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x800C2F04: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x800C2F08: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    // 0x800C2F0C: jal         0x800C1210
    // 0x800C2F10: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    func_800C1210(rdram, ctx);
        goto after_3;
    // 0x800C2F10: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x800C2F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2F18: jal         0x800C11F8
    // 0x800C2F1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C11F8(rdram, ctx);
        goto after_4;
    // 0x800C2F1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800C2F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2F24: jal         0x800C13A0
    // 0x800C2F28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C13A0(rdram, ctx);
        goto after_5;
    // 0x800C2F28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x800C2F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2F30: jal         0x800C13A0
    // 0x800C2F34: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800C13A0(rdram, ctx);
        goto after_6;
    // 0x800C2F34: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x800C2F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2F3C: jal         0x800C13A0
    // 0x800C2F40: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800C13A0(rdram, ctx);
        goto after_7;
    // 0x800C2F40: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_7:
    // 0x800C2F44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2F48: jal         0x800C13A0
    // 0x800C2F4C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_800C13A0(rdram, ctx);
        goto after_8;
    // 0x800C2F4C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_8:
    // 0x800C2F50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C2F54: lwc1        $f10, 0x57F8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X57F8);
    // 0x800C2F58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C2F5C: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x800C2F60: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x800C2F64: lwc1        $f16, 0x57FC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X57FC);
    // 0x800C2F68: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x800C2F6C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C2F70: sh          $t4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r12;
    // 0x800C2F74: sb          $zero, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = 0;
    // 0x800C2F78: sb          $zero, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = 0;
    // 0x800C2F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2F80: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    // 0x800C2F84: jal         0x800EFD24
    // 0x800C2F88: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    func_800EFD24(rdram, ctx);
        goto after_9;
    // 0x800C2F88: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    after_9:
    // 0x800C2F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2F90: jal         0x800C13B0
    // 0x800C2F94: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C13B0(rdram, ctx);
        goto after_10;
    // 0x800C2F94: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x800C2F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2F9C: jal         0x800C13B0
    // 0x800C2FA0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_800C13B0(rdram, ctx);
        goto after_11;
    // 0x800C2FA0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_11:
    // 0x800C2FA4: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    // 0x800C2FA8: jal         0x800C3418
    // 0x800C2FAC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C3418(rdram, ctx);
        goto after_12;
    // 0x800C2FAC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
    // 0x800C2FB0: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x800C2FB4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800C2FB8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800C2FBC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x800C2FC0: jal         0x800C3798
    // 0x800C2FC4: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    func_800C3798(rdram, ctx);
        goto after_13;
    // 0x800C2FC4: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    after_13:
    // 0x800C2FC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2FCC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C2FD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C2FD4: jr          $ra
    // 0x800C2FD8: nop

    return;
    // 0x800C2FD8: nop

;}
RECOMP_FUNC void _bswalk_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084250: syscall     107
    recomp_syscall_handler(rdram, ctx, 0x80084250);
    return;
    // 0x80084254: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void func_80800228_chshockjump(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800228: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080022C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800230: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800234: jal         0x80089F48
    // 0x80800238: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _subaddiesect_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800238: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080023C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800240: bne         $v0, $at, L_8080026C
    if (ctx->r2 != ctx->r1) {
        // 0x80800244: sw          $v0, 0x28($s0)
        MEM_W(0X28, ctx->r16) = ctx->r2;
            goto L_8080026C;
    }
    // 0x80800244: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x80800248: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x8080024C: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80800250: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800254: beq         $t7, $at, L_80800288
    if (ctx->r15 == ctx->r1) {
        // 0x80800258: nop
    
            goto L_80800288;
    }
    // 0x80800258: nop

    // 0x8080025C: jal         0x80102E08
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102E08(rdram, ctx);
        goto after_1;
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800264: b           L_80800288
    // 0x80800268: nop

        goto L_80800288;
    // 0x80800268: nop

L_8080026C:
    // 0x8080026C: lhu         $a2, 0x76($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X76);
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800274: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x80800278: srl         $t8, $a2, 7
    ctx->r24 = S32(U32(ctx->r6) >> 7);
    // 0x8080027C: xori        $t9, $t8, 0x33
    ctx->r25 = ctx->r24 ^ 0X33;
    // 0x80800280: jal         0x80089F50
    // 0x80800284: sltu        $a2, $zero, $t9
    ctx->r6 = 0 < ctx->r25 ? 1 : 0;
    _subaddiesect_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800284: sltu        $a2, $zero, $t9
    ctx->r6 = 0 < ctx->r25 ? 1 : 0;
    after_2:
L_80800288:
    // 0x80800288: jal         0x800DA298
    // 0x8080028C: addiu       $a0, $zero, 0x661
    ctx->r4 = ADD32(0, 0X661);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x8080028C: addiu       $a0, $zero, 0x661
    ctx->r4 = ADD32(0, 0X661);
    after_3:
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800294: jal         0x8010A654
    // 0x80800298: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8010A654(rdram, ctx);
        goto after_4;
    // 0x80800298: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8080029C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002A8: jr          $ra
    // 0x808002AC: nop

    return;
    // 0x808002AC: nop

;}
RECOMP_FUNC void _chmole_maya_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A20: syscall     406
    recomp_syscall_handler(rdram, ctx, 0x80086A20);
    return;
    // 0x80086A24: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80016BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016BBC: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x80016BC0: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80016BC4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80016BC8: lhu         $t8, -0x6504($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X6504);
    // 0x80016BCC: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x80016BD0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80016BD4: jr          $ra
    // 0x80016BD8: and         $v0, $t8, $t6
    ctx->r2 = ctx->r24 & ctx->r14;
    return;
    // 0x80016BD8: and         $v0, $t8, $t6
    ctx->r2 = ctx->r24 & ctx->r14;
;}
RECOMP_FUNC void func_800C8E54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8E54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C8E58: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C8E5C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800C8E60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8E64: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C8E68: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x800C8E6C: jal         0x800C8D4C
    // 0x800C8E70: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    func_800C8D4C(rdram, ctx);
        goto after_0;
    // 0x800C8E70: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800C8E74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8E78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C8E7C: jr          $ra
    // 0x800C8E80: nop

    return;
    // 0x800C8E80: nop

;}
RECOMP_FUNC void func_801112B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801112B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801112B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801112B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801112BC: jal         0x800F53D0
    // 0x801112C0: lw          $a0, 0x68($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68);
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x801112C0: lw          $a0, 0x68($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68);
    after_0:
    // 0x801112C4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x801112C8: jal         0x80092BC4
    // 0x801112CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80092BC4(rdram, ctx);
        goto after_1;
    // 0x801112CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x801112D0: beq         $v0, $zero, L_801112F0
    if (ctx->r2 == 0) {
        // 0x801112D4: lw          $t7, 0x20($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X20);
            goto L_801112F0;
    }
    // 0x801112D4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x801112D8: jal         0x80092BD0
    // 0x801112DC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80092BD0(rdram, ctx);
        goto after_2;
    // 0x801112DC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x801112E0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801112E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801112E8: b           L_801112FC
    // 0x801112EC: sub.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f4.fl;
        goto L_801112FC;
    // 0x801112EC: sub.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f4.fl;
L_801112F0:
    // 0x801112F0: jal         0x800F5F24
    // 0x801112F4: lw          $a0, 0x68($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X68);
    func_800F5F24(rdram, ctx);
        goto after_3;
    // 0x801112F4: lw          $a0, 0x68($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X68);
    after_3:
    // 0x801112F8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_801112FC:
    // 0x801112FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80111300: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80111304: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80111308: jr          $ra
    // 0x8011130C: nop

    return;
    // 0x8011130C: nop

;}
RECOMP_FUNC void bsdronexform_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005CC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808005D0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808005D4: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x808005D8: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x808005DC: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x808005E0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x808005E4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x808005E8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x808005EC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x808005F0: jal         0x800F53D0
    // 0x808005F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x808005F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808005F8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808005FC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800600: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800604: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800608: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8080060C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800610: addiu       $s1, $sp, 0x4C
    ctx->r17 = ADD32(ctx->r29, 0X4C);
    // 0x80800614: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
L_80800618:
    // 0x80800618: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    // 0x8080061C: lw          $t6, 0x18C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X18C);
    // 0x80800620: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80800624: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800628: lwc1        $f4, 0x20($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X20);
    // 0x8080062C: div.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80800630: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80800634: jal         0x800F1074
    // 0x80800638: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    func_800F1074(rdram, ctx);
        goto after_1;
    // 0x80800638: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    after_1:
    // 0x8080063C: lw          $v0, 0x18C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X18C);
    // 0x80800640: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800644: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800648: lwc1        $f2, 0x24($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8080064C: lwc1        $f18, 0x28($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80800650: mul.s       $f6, $f2, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80800654: nop

    // 0x80800658: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8080065C: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80800660: bne         $s0, $s3, L_80800618
    if (ctx->r16 != ctx->r19) {
        // 0x80800664: swc1        $f10, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->f10.u32l;
            goto L_80800618;
    }
    // 0x80800664: swc1        $f10, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->f10.u32l;
    // 0x80800668: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8080066C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800670: jal         0x800DFF64
    // 0x80800674: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_800DFF64(rdram, ctx);
        goto after_2;
    // 0x80800674: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_2:
    // 0x80800678: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8080067C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800680: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80800684: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80800688: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8080068C: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80800690: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80800694: jr          $ra
    // 0x80800698: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80800698: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
