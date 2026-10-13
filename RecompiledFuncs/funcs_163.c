#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80801BA0_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801BA0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801BA4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2204, 0X2720) << 16);
    // 0x80801BA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801BAC: addiu       $t6, $t6, 0x2720
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2204, 0X2720));
    // 0x80801BB0: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80801BB4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80801BB8: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2204, 0X272C) << 16);
    // 0x80801BBC: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x80801BC0: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80801BC4: addiu       $t0, $t0, 0x272C
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2204, 0X272C));
    // 0x80801BC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801BCC: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80801BD0: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80801BD4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801BD8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80801BDC: sw          $at, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r1;
    // 0x80801BE0: jal         0x800BBCB8
    // 0x80801BE4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80801BE4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_0:
    // 0x80801BE8: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80801BEC: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80801BF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801BF4: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x80801BF8: jal         0x800E1610
    // 0x80801BFC: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    func_800E1610(rdram, ctx);
        goto after_1;
    // 0x80801BFC: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80801C00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801C04: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801C08: jr          $ra
    // 0x80801C0C: nop

    return;
    // 0x80801C0C: nop

;}
RECOMP_FUNC void _basquash_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800850B8: syscall     150
    recomp_syscall_handler(rdram, ctx, 0x800850B8);
    return;
    // 0x800850BC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800F24_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800F30: bne         $a1, $zero, L_80800F48
    if (ctx->r5 != 0) {
        // 0x80800F34: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800F48;
    }
    // 0x80800F34: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800F38: jal         0x800D395C
    // 0x80800F3C: nop

    func_800D395C(rdram, ctx);
        goto after_0;
    // 0x80800F3C: nop

    after_0:
    // 0x80800F40: beq         $v0, $zero, L_80800F78
    if (ctx->r2 == 0) {
        // 0x80800F44: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_80800F78;
    }
    // 0x80800F44: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
L_80800F48:
    // 0x80800F48: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800F4C: addiu       $a0, $zero, 0x18AF
    ctx->r4 = ADD32(0, 0X18AF);
    // 0x80800F50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800F54: lbu         $t8, 0x65($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X65);
    // 0x80800F58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800F5C: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x80800F60: sb          $t9, 0x65($t6)
    MEM_B(0X65, ctx->r14) = ctx->r25;
    // 0x80800F64: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800F68: jal         0x800861A0
    // 0x80800F6C: addiu       $a1, $a1, 0xF
    ctx->r5 = ADD32(ctx->r5, 0XF);
    _chintrotext_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800F6C: addiu       $a1, $a1, 0xF
    ctx->r5 = ADD32(ctx->r5, 0XF);
    after_1:
    // 0x80800F70: b           L_80800F90
    // 0x80800F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800F90;
    // 0x80800F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F78:
    // 0x80800F78: lbu         $t0, 0x65($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X65);
    // 0x80800F7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800F80: andi        $t1, $t0, 0xFFF7
    ctx->r9 = ctx->r8 & 0XFFF7;
    // 0x80800F84: jal         0x800861A8
    // 0x80800F88: sb          $t1, 0x65($v1)
    MEM_B(0X65, ctx->r3) = ctx->r9;
    _chintrotext_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800F88: sb          $t1, 0x65($v1)
    MEM_B(0X65, ctx->r3) = ctx->r9;
    after_2:
    // 0x80800F8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F90:
    // 0x80800F90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F94: jr          $ra
    // 0x80800F98: nop

    return;
    // 0x80800F98: nop

;}
RECOMP_FUNC void func_800128C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800128C0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800128C4: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x800128C8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800128CC: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800128D0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800128D4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800128D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800128DC: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x800128E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800128E4: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x800128E8: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x800128EC: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x800128F0: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x800128F4: lui         $s5, 0x8007
    ctx->r21 = S32(0X8007 << 16);
    // 0x800128F8: lui         $s7, 0x8004
    ctx->r23 = S32(0X8004 << 16);
    // 0x800128FC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80012900: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80012904: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80012908: addiu       $s7, $s7, 0x5BF0
    ctx->r23 = ADD32(ctx->r23, 0X5BF0);
    // 0x8001290C: addiu       $s5, $s5, -0x5EB8
    ctx->r21 = ADD32(ctx->r21, -0X5EB8);
    // 0x80012910: addiu       $s4, $s4, 0x59E0
    ctx->r20 = ADD32(ctx->r20, 0X59E0);
    // 0x80012914: addiu       $s3, $s3, 0x5BB8
    ctx->r19 = ADD32(ctx->r19, 0X5BB8);
    // 0x80012918: addiu       $s2, $s2, -0x33A0
    ctx->r18 = ADD32(ctx->r18, -0X33A0);
    // 0x8001291C: addiu       $s1, $s1, -0x33A4
    ctx->r17 = ADD32(ctx->r17, -0X33A4);
    // 0x80012920: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x80012924: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80012928:
    // 0x80012928: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001292C: jal         0x8002E1F0
    // 0x80012930: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80012930: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80012934: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x80012938: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8001293C: div         $zero, $t6, $s6
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r22)));
    // 0x80012940: mfhi        $t7
    ctx->r15 = hi;
    // 0x80012944: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80012948: addu        $t9, $s4, $t8
    ctx->r25 = ADD32(ctx->r20, ctx->r24);
    // 0x8001294C: bne         $s6, $zero, L_80012958
    if (ctx->r22 != 0) {
        // 0x80012950: nop
    
            goto L_80012958;
    }
    // 0x80012950: nop

    // 0x80012954: break       7
    do_break(2147559764);
L_80012958:
    // 0x80012958: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001295C: bne         $s6, $at, L_80012970
    if (ctx->r22 != ctx->r1) {
        // 0x80012960: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80012970;
    }
    // 0x80012960: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80012964: bne         $t6, $at, L_80012970
    if (ctx->r14 != ctx->r1) {
        // 0x80012968: nop
    
            goto L_80012970;
    }
    // 0x80012968: nop

    // 0x8001296C: break       6
    do_break(2147559788);
L_80012970:
    // 0x80012970: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x80012974: jal         0x800129FC
    // 0x80012978: nop

    func_800129FC(rdram, ctx);
        goto after_1;
    // 0x80012978: nop

    after_1:
    // 0x8001297C: beq         $v0, $zero, L_800129B8
    if (ctx->r2 == 0) {
        // 0x80012980: nop
    
            goto L_800129B8;
    }
    // 0x80012980: nop

    // 0x80012984: bne         $s0, $zero, L_800129B4
    if (ctx->r16 != 0) {
        // 0x80012988: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800129B4;
    }
    // 0x80012988: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8001298C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80012990: jal         0x8002E1F0
    // 0x80012994: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80012994: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80012998: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8001299C: jal         0x80012B74
    // 0x800129A0: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    func_80012B74(rdram, ctx);
        goto after_3;
    // 0x800129A0: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    after_3:
    // 0x800129A4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x800129A8: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800129AC: b           L_800129B8
    // 0x800129B0: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
        goto L_800129B8;
    // 0x800129B0: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
L_800129B4:
    // 0x800129B4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_800129B8:
    // 0x800129B8: jal         0x800E96B0
    // 0x800129BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E96B0(rdram, ctx);
        goto after_4;
    // 0x800129BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x800129C0: b           L_80012928
    // 0x800129C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80012928;
    // 0x800129C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800129C8: nop

    // 0x800129CC: nop

    // 0x800129D0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800129D4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800129D8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800129DC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800129E0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800129E4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800129E8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800129EC: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800129F0: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x800129F4: jr          $ra
    // 0x800129F8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800129F8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80800528_chhotwaterpoolbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800528: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080052C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800530: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800534: jal         0x800BEA88
    // 0x80800538: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BEA88(rdram, ctx);
        goto after_0;
    // 0x80800538: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8080053C: beq         $v0, $zero, L_8080055C
    if (ctx->r2 == 0) {
        // 0x80800540: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8080055C;
    }
    // 0x80800540: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800544: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800548: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8080054C: addiu       $a2, $a2, 0x6440
    ctx->r6 = ADD32(ctx->r6, 0X6440);
    // 0x80800550: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800554: jal         0x80088660
    // 0x80800558: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800558: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    after_1:
L_8080055C:
    // 0x8080055C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800560: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800564: jr          $ra
    // 0x80800568: nop

    return;
    // 0x80800568: nop

;}
RECOMP_FUNC void func_8080099C_basnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080099C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808009A0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808009A4: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x808009A8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808009AC: jal         0x800B5BE4
    // 0x808009B0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x808009B0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_0:
    // 0x808009B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808009B8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808009BC: jal         0x8009C128
    // 0x808009C0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x808009C0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x808009C4: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x808009C8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808009CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808009D0: lw          $t7, 0x110($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X110);
    // 0x808009D4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808009D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808009DC: lwc1        $f0, 0x1C($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x808009E0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808009E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808009E8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808009EC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808009F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808009F4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808009F8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808009FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A00: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(604, 0X100C) << 16);
    // 0x80800A04: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x80800A08: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800A0C: lwc1        $f8, 0x100C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X100C));
    // 0x80800A10: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800A14: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800A18: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800A1C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800A20: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800A24: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x80800A28: add.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x80800A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A30: addiu       $a3, $zero, 0x41
    ctx->r7 = ADD32(0, 0X41);
    // 0x80800A34: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800A38: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800A3C: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x80800A40: trunc.w.s   $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80800A44: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800A48: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800A4C: sll         $t2, $a2, 16
    ctx->r10 = S32(ctx->r6 << 16);
    // 0x80800A50: sra         $a2, $t2, 16
    ctx->r6 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80800A54: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x80800A58: jal         0x800BA730
    // 0x80800A5C: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    func_800BA730(rdram, ctx);
        goto after_2;
    // 0x80800A5C: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    after_2:
    // 0x80800A60: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800A64: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800A68: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800A6C: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80800A70: trunc.w.s   $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    ctx->f8.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80800A74: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80800A78: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80800A7C: add.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x80800A80: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800A84: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A8C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800A90: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x80800A94: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80800A98: addiu       $a1, $zero, -0xA
    ctx->r5 = ADD32(0, -0XA);
    // 0x80800A9C: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80800AA0: addiu       $a3, $zero, -0xA
    ctx->r7 = ADD32(0, -0XA);
    // 0x80800AA4: jal         0x800BA930
    // 0x80800AA8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    func_800BA930(rdram, ctx);
        goto after_3;
    // 0x80800AA8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_3:
    // 0x80800AAC: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AB4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800AB8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800ABC: jal         0x800BA7FC
    // 0x80800AC0: nop

    func_800BA7FC(rdram, ctx);
        goto after_4;
    // 0x80800AC0: nop

    after_4:
    // 0x80800AC4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800AC8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(604, 0X1010) << 16);
    // 0x80800ACC: jal         0x800DC178
    // 0x80800AD0: lwc1        $f14, 0x1010($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X1010));
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80800AD0: lwc1        $f14, 0x1010($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X1010));
    after_5:
    // 0x80800AD4: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ADC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800AE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800AE4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80800AE8: nop

    // 0x80800AEC: sll         $t3, $a3, 16
    ctx->r11 = S32(ctx->r7 << 16);
    // 0x80800AF0: jal         0x800BA77C
    // 0x80800AF4: sra         $a3, $t3, 16
    ctx->r7 = S32(SIGNED(ctx->r11) >> 16);
    func_800BA77C(rdram, ctx);
        goto after_6;
    // 0x80800AF4: sra         $a3, $t3, 16
    ctx->r7 = S32(SIGNED(ctx->r11) >> 16);
    after_6:
    // 0x80800AF8: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(604, 0X110C) << 16);
    // 0x80800AFC: addiu       $t5, $t5, 0x110C
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(604, 0X110C));
    // 0x80800B00: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B08: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800B0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800B10: jal         0x800BABB8
    // 0x80800B14: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_7;
    // 0x80800B14: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_7:
    // 0x80800B18: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800B1C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800B20: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800B24: jr          $ra
    // 0x80800B28: nop

    return;
    // 0x80800B28: nop

;}
RECOMP_FUNC void func_800C8C18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8C18: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C8C1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8C20: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C8C24: jal         0x800B296C
    // 0x800C8C28: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    vector_end(rdram, ctx);
        goto after_0;
    // 0x800C8C28: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    after_0:
    // 0x800C8C2C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C8C30: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    // 0x800C8C34: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800C8C38: jal         0x800B28C4
    // 0x800C8C3C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    vector_begin(rdram, ctx);
        goto after_1;
    // 0x800C8C3C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x800C8C40: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800C8C44: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800C8C48: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C8C4C: sltu        $at, $v0, $a2
    ctx->r1 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x800C8C50: beq         $at, $zero, L_800C8C84
    if (ctx->r1 == 0) {
        // 0x800C8C54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C8C84;
    }
    // 0x800C8C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8C58: lbu         $t6, 0x15($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X15);
L_800C8C5C:
    // 0x800C8C5C: beql        $t6, $zero, L_800C8C78
    if (ctx->r14 == 0) {
        // 0x800C8C60: addiu       $v1, $v1, 0x1C
        ctx->r3 = ADD32(ctx->r3, 0X1C);
            goto L_800C8C78;
    }
    goto skip_0;
    // 0x800C8C60: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    skip_0:
    // 0x800C8C64: lbu         $t7, 0x14($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X14);
    // 0x800C8C68: beql        $t7, $zero, L_800C8C78
    if (ctx->r15 == 0) {
        // 0x800C8C6C: addiu       $v1, $v1, 0x1C
        ctx->r3 = ADD32(ctx->r3, 0X1C);
            goto L_800C8C78;
    }
    goto skip_1;
    // 0x800C8C6C: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    skip_1:
    // 0x800C8C70: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C8C74: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
L_800C8C78:
    // 0x800C8C78: sltu        $at, $v1, $a2
    ctx->r1 = ctx->r3 < ctx->r6 ? 1 : 0;
    // 0x800C8C7C: bnel        $at, $zero, L_800C8C5C
    if (ctx->r1 != 0) {
        // 0x800C8C80: lbu         $t6, 0x15($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X15);
            goto L_800C8C5C;
    }
    goto skip_2;
    // 0x800C8C80: lbu         $t6, 0x15($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X15);
    skip_2:
L_800C8C84:
    // 0x800C8C84: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800C8C88: jr          $ra
    // 0x800C8C8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C8C8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800000_chlagoonfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800004: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x80800008: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x80800014: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80800018: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8080001C: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x80800020: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80800024: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80800028: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8080002C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80800030: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800034: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x80800038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080003C: andi        $t6, $a2, 0x1FF
    ctx->r14 = ctx->r6 & 0X1FF;
    // 0x80800040: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800044: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80800048: jal         0x80100074
    // 0x8080004C: sll         $a2, $t7, 4
    ctx->r6 = S32(ctx->r15 << 4);
    func_80100074(rdram, ctx);
        goto after_0;
    // 0x8080004C: sll         $a2, $t7, 4
    ctx->r6 = S32(ctx->r15 << 4);
    after_0:
    // 0x80800050: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800054: jal         0x80100094
    // 0x80800058: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800058: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080005C: lw          $t8, 0x6C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X6C);
    // 0x80800060: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800064: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800068: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x8080006C: beq         $t9, $zero, L_8080016C
    if (ctx->r25 == 0) {
        // 0x80800070: lui         $at, 0x4234
        ctx->r1 = S32(0X4234 << 16);
            goto L_8080016C;
    }
    // 0x80800070: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800074: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80800078: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x8080007C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80800080: lui         $at, 0xC3C8
    ctx->r1 = S32(0XC3C8 << 16);
    // 0x80800084: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800088: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8080008C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800090: addiu       $s3, $s2, 0x4
    ctx->r19 = ADD32(ctx->r18, 0X4);
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800098:
    // 0x80800098: jal         0x800EE7F8
    // 0x8080009C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x8080009C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x808000A0: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    // 0x808000A4: jal         0x800DC178
    // 0x808000A8: mov.s       $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    ctx->f14.fl = ctx->f30.fl;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x808000A8: mov.s       $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    ctx->f14.fl = ctx->f30.fl;
    after_3:
    // 0x808000AC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808000B0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808000B4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808000B8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000BC: jal         0x800DC178
    // 0x808000C0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x808000C0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_4:
    // 0x808000C4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808000C8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808000CC: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x808000D0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000D4: jal         0x800DC178
    // 0x808000D8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x808000D8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_5:
    // 0x808000DC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808000E0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808000E4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808000E8: jal         0x800EF214
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EF214(rdram, ctx);
        goto after_6;
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808000F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1800, 0XB50) << 16);
    // 0x808000F4: lwc1        $f4, 0xB50($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1800, 0XB50));
    // 0x808000F8: lwc1        $f14, 0x38($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X38);
    // 0x808000FC: mul.s       $f12, $f14, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x80800100: jal         0x800DC178
    // 0x80800104: nop

    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x80800104: nop

    after_7:
    // 0x80800108: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x8080010C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800110: jal         0x800DC128
    // 0x80800114: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DC128(rdram, ctx);
        goto after_8;
    // 0x80800114: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x80800118: sb          $v0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r2;
    // 0x8080011C: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x80800120: jal         0x800DC178
    // 0x80800124: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x80800124: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_9:
    // 0x80800128: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x8080012C: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x80800130: jal         0x800DC178
    // 0x80800134: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    func_800DC178(rdram, ctx);
        goto after_10;
    // 0x80800134: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_10:
    // 0x80800138: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x8080013C: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x80800140: jal         0x800DC178
    // 0x80800144: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    func_800DC178(rdram, ctx);
        goto after_11;
    // 0x80800144: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_11:
    // 0x80800148: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x8080014C: swc1        $f24, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f24.u32l;
    // 0x80800150: lw          $t0, 0x6C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X6C);
    // 0x80800154: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800158: addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
    // 0x8080015C: andi        $t1, $t0, 0x1FF
    ctx->r9 = ctx->r8 & 0X1FF;
    // 0x80800160: sltu        $at, $s1, $t1
    ctx->r1 = ctx->r17 < ctx->r9 ? 1 : 0;
    // 0x80800164: bnel        $at, $zero, L_80800098
    if (ctx->r1 != 0) {
        // 0x80800168: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800098;
    }
    goto skip_0;
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_8080016C:
    // 0x8080016C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80800170: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800174: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80800178: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8080017C: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80800180: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80800184: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x80800188: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8080018C: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80800190: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x80800194: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x80800198: jr          $ra
    // 0x8080019C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8080019C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80801980_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801984: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801988: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x8080198C: jal         0x80084C38
    // 0x80801990: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _bafly_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80801990: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x80801994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080199C: jr          $ra
    // 0x808019A0: nop

    return;
    // 0x808019A0: nop

;}
RECOMP_FUNC void func_80094BC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094BC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80094BC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80094BC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80094BCC: jal         0x80094348
    // 0x80094BD0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80094348(rdram, ctx);
        goto after_0;
    // 0x80094BD0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80094BD4: beq         $v0, $zero, L_80094BE4
    if (ctx->r2 == 0) {
        // 0x80094BD8: nop
    
            goto L_80094BE4;
    }
    // 0x80094BD8: nop

    // 0x80094BDC: b           L_80094BFC
    // 0x80094BE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80094BFC;
    // 0x80094BE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80094BE4:
    // 0x80094BE4: jal         0x80094510
    // 0x80094BE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80094510(rdram, ctx);
        goto after_1;
    // 0x80094BE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80094BEC: jal         0x800883E0
    // 0x80094BF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gcegg_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80094BF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80094BF4: jal         0x800D1A04
    // 0x80094BF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D1A04(rdram, ctx);
        goto after_3;
    // 0x80094BF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
L_80094BFC:
    // 0x80094BFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80094C00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80094C04: jr          $ra
    // 0x80094C08: nop

    return;
    // 0x80094C08: nop

;}
RECOMP_FUNC void func_80800E80_chlagoonufoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800E88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E8C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800E90: beq         $a1, $at, L_80800EBC
    if (ctx->r5 == ctx->r1) {
        // 0x80800E94: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80800EBC;
    }
    // 0x80800E94: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800E98: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800E9C: beq         $a1, $at, L_80800ED0
    if (ctx->r5 == ctx->r1) {
        // 0x80800EA0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800ED0;
    }
    // 0x80800EA0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800EA4: beq         $a1, $at, L_80800EFC
    if (ctx->r5 == ctx->r1) {
        // 0x80800EA8: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80800EFC;
    }
    // 0x80800EA8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800EAC: beql        $a1, $at, L_80800F10
    if (ctx->r5 == ctx->r1) {
        // 0x80800EB0: lbu         $t9, 0x79($a2)
        ctx->r25 = MEM_BU(ctx->r6, 0X79);
            goto L_80800F10;
    }
    goto skip_0;
    // 0x80800EB0: lbu         $t9, 0x79($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X79);
    skip_0:
    // 0x80800EB4: b           L_80800F28
    // 0x80800EB8: lbu         $t4, 0x72($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X72);
        goto L_80800F28;
    // 0x80800EB8: lbu         $t4, 0x72($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X72);
L_80800EBC:
    // 0x80800EBC: lhu         $t6, 0x6E($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X6E);
    // 0x80800EC0: andi        $t7, $t6, 0xFE00
    ctx->r15 = ctx->r14 & 0XFE00;
    // 0x80800EC4: ori         $t8, $t7, 0x3
    ctx->r24 = ctx->r15 | 0X3;
    // 0x80800EC8: b           L_80800F24
    // 0x80800ECC: sh          $t8, 0x6E($a2)
    MEM_H(0X6E, ctx->r6) = ctx->r24;
        goto L_80800F24;
    // 0x80800ECC: sh          $t8, 0x6E($a2)
    MEM_H(0X6E, ctx->r6) = ctx->r24;
L_80800ED0:
    // 0x80800ED0: lw          $a0, 0x3C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X3C);
    // 0x80800ED4: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x80800ED8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80800EDC: jal         0x808004D8
    // 0x80800EE0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_808004D8_chlagoonufoint(rdram, ctx);
        goto after_0;
    // 0x80800EE0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800EE4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(748, 0X191C) << 16);
    // 0x80800EE8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800EEC: lwc1        $f4, 0x191C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(748, 0X191C));
    // 0x80800EF0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80800EF4: b           L_80800F24
    // 0x80800EF8: swc1        $f4, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f4.u32l;
        goto L_80800F24;
    // 0x80800EF8: swc1        $f4, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f4.u32l;
L_80800EFC:
    // 0x80800EFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800F00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800F04: b           L_80800F24
    // 0x80800F08: swc1        $f6, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f6.u32l;
        goto L_80800F24;
    // 0x80800F08: swc1        $f6, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f6.u32l;
    // 0x80800F0C: lbu         $t9, 0x79($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X79);
L_80800F10:
    // 0x80800F10: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(748, 0X1920) << 16);
    // 0x80800F14: lwc1        $f8, 0x1920($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(748, 0X1920));
    // 0x80800F18: andi        $t0, $t9, 0xFF0F
    ctx->r8 = ctx->r25 & 0XFF0F;
    // 0x80800F1C: sb          $t0, 0x79($a2)
    MEM_B(0X79, ctx->r6) = ctx->r8;
    // 0x80800F20: swc1        $f8, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f8.u32l;
L_80800F24:
    // 0x80800F24: lbu         $t4, 0x72($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X72);
L_80800F28:
    // 0x80800F28: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
    // 0x80800F2C: andi        $t5, $t4, 0xFF03
    ctx->r13 = ctx->r12 & 0XFF03;
    // 0x80800F30: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80800F34: sb          $t6, 0x72($a2)
    MEM_B(0X72, ctx->r6) = ctx->r14;
    // 0x80800F38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F40: jr          $ra
    // 0x80800F44: nop

    return;
    // 0x80800F44: nop

;}
RECOMP_FUNC void func_808008A4_chspotlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008AC: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x808008B0: bne         $t6, $zero, L_808008C0
    if (ctx->r14 != 0) {
        // 0x808008B4: nop
    
            goto L_808008C0;
    }
    // 0x808008B4: nop

    // 0x808008B8: b           L_808008DC
    // 0x808008BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008DC;
    // 0x808008BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808008C0:
    // 0x808008C0: jal         0x800DA298
    // 0x808008C4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808008C4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x808008C8: beql        $v0, $zero, L_808008DC
    if (ctx->r2 == 0) {
        // 0x808008CC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808008DC;
    }
    goto skip_0;
    // 0x808008CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808008D0: b           L_808008DC
    // 0x808008D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008DC;
    // 0x808008D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808008D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008DC:
    // 0x808008DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008E4: jr          $ra
    // 0x808008E8: nop

    return;
    // 0x808008E8: nop

;}
RECOMP_FUNC void _chstinger_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800872C8: syscall     546
    recomp_syscall_handler(rdram, ctx, 0x800872C8);
    return;
    // 0x800872CC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080040C_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080040C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800410: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80800414: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80800418: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8080041C: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80800420: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x80800424: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800428: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8080042C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800430: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800434: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800438: jal         0x80100094
    // 0x8080043C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080043C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800440: lbu         $t6, 0xC5($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XC5);
    // 0x80800444: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800448: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080044C: blez        $t6, L_808004B8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800450: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1752, 0X49C8) << 16);
            goto L_808004B8;
    }
    // 0x80800450: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X49C8) << 16);
    // 0x80800454: lwc1        $f20, 0x49C8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X49C8));
    // 0x80800458: addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
    // 0x8080045C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80800460:
    // 0x80800460: beq         $s0, $s4, L_808004A4
    if (ctx->r16 == ctx->r20) {
        // 0x80800464: addu        $t7, $s1, $s0
        ctx->r15 = ADD32(ctx->r17, ctx->r16);
            goto L_808004A4;
    }
    // 0x80800464: addu        $t7, $s1, $s0
    ctx->r15 = ADD32(ctx->r17, ctx->r16);
    // 0x80800468: lbu         $t8, 0xAC($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XAC);
    // 0x8080046C: bnel        $s2, $t8, L_808004A8
    if (ctx->r18 != ctx->r24) {
        // 0x80800470: lbu         $t0, 0xC5($s1)
        ctx->r8 = MEM_BU(ctx->r17, 0XC5);
            goto L_808004A8;
    }
    goto skip_0;
    // 0x80800470: lbu         $t0, 0xC5($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0XC5);
    skip_0:
    // 0x80800474: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800478: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8080047C: mflo        $t9
    ctx->r25 = lo;
    // 0x80800480: addu        $a0, $s1, $t9
    ctx->r4 = ADD32(ctx->r17, ctx->r25);
    // 0x80800484: jal         0x800EEB40
    // 0x80800488: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    func_800EEB40(rdram, ctx);
        goto after_1;
    // 0x80800488: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    after_1:
    // 0x8080048C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80800490: nop

    // 0x80800494: bc1fl       L_808004A8
    if (!c1cs) {
        // 0x80800498: lbu         $t0, 0xC5($s1)
        ctx->r8 = MEM_BU(ctx->r17, 0XC5);
            goto L_808004A8;
    }
    goto skip_1;
    // 0x80800498: lbu         $t0, 0xC5($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0XC5);
    skip_1:
    // 0x8080049C: b           L_808004BC
    // 0x808004A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004BC;
    // 0x808004A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004A4:
    // 0x808004A4: lbu         $t0, 0xC5($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0XC5);
L_808004A8:
    // 0x808004A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808004AC: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x808004B0: bne         $at, $zero, L_80800460
    if (ctx->r1 != 0) {
        // 0x808004B4: nop
    
            goto L_80800460;
    }
    // 0x808004B4: nop

L_808004B8:
    // 0x808004B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004BC:
    // 0x808004BC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808004C0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808004C4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808004C8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808004CC: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x808004D0: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x808004D4: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x808004D8: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x808004DC: jr          $ra
    // 0x808004E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808004E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void baanim_setEndAndDuration(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CF1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008CF20: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8008CF24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CF28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008CF2C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008CF30: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8008CF34: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8008CF38: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8008CF3C: jal         0x8008B1D4
    // 0x8008CF40: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_0;
    // 0x8008CF40: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_0:
    // 0x8008CF44: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8008CF48: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8008CF4C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8008CF50: jal         0x8008B1BC
    // 0x8008CF54: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    anctrl_setDuration(rdram, ctx);
        goto after_1;
    // 0x8008CF54: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_1:
    // 0x8008CF58: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8008CF5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008CF60: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8008CF64: jal         0x8008B134
    // 0x8008CF68: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_2;
    // 0x8008CF68: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_2:
    // 0x8008CF6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008CF70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008CF74: jr          $ra
    // 0x8008CF78: nop

    return;
    // 0x8008CF78: nop

;}
RECOMP_FUNC void func_80014148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001414C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80014150: jal         0x80013DE4
    // 0x80014154: nop

    func_80013DE4(rdram, ctx);
        goto after_0;
    // 0x80014154: nop

    after_0:
    // 0x80014158: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001415C: lw          $t6, -0x7B74($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7B74);
    // 0x80014160: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80014164: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80014168: bnel        $t6, $at, L_800141C4
    if (ctx->r14 != ctx->r1) {
        // 0x8001416C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800141C4;
    }
    goto skip_0;
    // 0x8001416C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80014170: lw          $t7, -0x7B80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7B80);
    // 0x80014174: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80014178: addiu       $t8, $t8, -0x7154
    ctx->r24 = ADD32(ctx->r24, -0X7154);
    // 0x8001417C: bnel        $t7, $zero, L_800141C4
    if (ctx->r15 != 0) {
        // 0x80014180: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800141C4;
    }
    goto skip_1;
    // 0x80014180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80014184: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80014188: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001418C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80014190: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x80014194: jal         0x80013EF0
    // 0x80014198: lw          $a0, -0x71A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X71A8);
    func_80013EF0(rdram, ctx);
        goto after_1;
    // 0x80014198: lw          $a0, -0x71A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X71A8);
    after_1:
    // 0x8001419C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800141A0: addiu       $v0, $v0, -0x7154
    ctx->r2 = ADD32(ctx->r2, -0X7154);
    // 0x800141A4: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800141A8: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800141AC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800141B0: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x800141B4: mfhi        $t3
    ctx->r11 = hi;
    // 0x800141B8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800141BC: nop

    // 0x800141C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800141C4:
    // 0x800141C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800141C8: jr          $ra
    // 0x800141CC: nop

    return;
    // 0x800141CC: nop

;}
RECOMP_FUNC void func_80800870_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800870: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800874: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800878: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080087C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800880: jal         0x800D8FF8
    // 0x80800884: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800884: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    after_0:
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080088C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800890: jal         0x80100094
    // 0x80800894: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800894: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80800898: addiu       $s1, $sp, 0x2C
    ctx->r17 = ADD32(ctx->r29, 0X2C);
    // 0x8080089C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808008A0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808008A4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x808008A8: jal         0x800D1218
    // 0x808008AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D1218(rdram, ctx);
        goto after_2;
    // 0x808008AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808008B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808008B4: jal         0x800888C8
    // 0x808008B8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    _fxsparkle_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808008B8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_3:
    // 0x808008BC: lbu         $t6, 0x2F($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2F);
    // 0x808008C0: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808008C4: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808008C8: bne         $t6, $zero, L_808009D0
    if (ctx->r14 != 0) {
        // 0x808008CC: lui         $at, 0x4496
        ctx->r1 = S32(0X4496 << 16);
            goto L_808009D0;
    }
    // 0x808008CC: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x808008D0: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x808008D4: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x808008D8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808008DC: nop

    // 0x808008E0: bc1fl       L_80800950
    if (!c1cs) {
        // 0x808008E4: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80800950;
    }
    goto skip_0;
    // 0x808008E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x808008E8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x808008EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(880, 0X13D8) << 16);
    // 0x808008F0: lwc1        $f8, 0x13D8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X13D8));
    // 0x808008F4: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808008F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(880, 0X13DC) << 16);
    // 0x808008FC: lwc1        $f16, 0x34($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800900: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800904: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80800908: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080090C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800910: swc1        $f10, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f10.u32l;
    // 0x80800914: lwc1        $f18, 0x13DC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X13DC));
    // 0x80800918: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8080091C: jal         0x800D1254
    // 0x80800920: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    func_800D1254(rdram, ctx);
        goto after_4;
    // 0x80800920: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x80800924: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800928: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(880, 0X148C) << 16);
    // 0x8080092C: sb          $t7, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r15;
    // 0x80800930: addiu       $a3, $a3, 0x148C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(880, 0X148C));
    // 0x80800934: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800938: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080093C: jal         0x8010D930
    // 0x80800940: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_8010D930(rdram, ctx);
        goto after_5;
    // 0x80800940: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_5:
    // 0x80800944: b           L_80800AC8
    // 0x80800948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800AC8;
    // 0x80800948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080094C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80800950:
    // 0x80800950: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800954: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800958: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8080095C: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    // 0x80800960: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80800964: swc1        $f10, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f10.u32l;
    // 0x80800968: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080096C: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800970: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80800974: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80800978: bc1f        L_808009AC
    if (!c1cs) {
        // 0x8080097C: swc1        $f6, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
            goto L_808009AC;
    }
    // 0x8080097C: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x80800980: lwc1        $f8, 0x38($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800984: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800988: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x8080098C: c.lt.s      $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f8.fl < ctx->f14.fl;
    // 0x80800990: nop

    // 0x80800994: bc1fl       L_808009B0
    if (!c1cs) {
        // 0x80800998: lwc1        $f10, 0x34($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
            goto L_808009B0;
    }
    goto skip_1;
    // 0x80800998: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    skip_1:
    // 0x8080099C: jal         0x800F1DF4
    // 0x808009A0: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    func_800F1DF4(rdram, ctx);
        goto after_6;
    // 0x808009A0: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    after_6:
    // 0x808009A4: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808009A8: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
L_808009AC:
    // 0x808009AC: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
L_808009B0:
    // 0x808009B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808009B4: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x808009B8: mul.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x808009BC: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x808009C0: jal         0x800EF1B8
    // 0x808009C4: nop

    func_800EF1B8(rdram, ctx);
        goto after_7;
    // 0x808009C4: nop

    after_7:
    // 0x808009C8: b           L_80800AB8
    // 0x808009CC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
        goto L_80800AB8;
    // 0x808009CC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_808009D0:
    // 0x808009D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808009D4: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808009D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808009DC: mul.s       $f2, $f16, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x808009E0: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x808009E4: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
    // 0x808009E8: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808009EC: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808009F0: mul.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x808009F4: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x808009F8: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x808009FC: lwc1        $f4, 0x34($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800A00: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x80800A04: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x80800A08: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80800A0C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800A10: jal         0x800EF1B8
    // 0x80800A14: nop

    func_800EF1B8(rdram, ctx);
        goto after_8;
    // 0x80800A14: nop

    after_8:
    // 0x80800A18: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800A1C: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800A20: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800A24: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800A28: c.lt.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl < ctx->f14.fl;
    // 0x80800A2C: nop

    // 0x80800A30: bc1fl       L_80800AB8
    if (!c1cs) {
        // 0x80800A34: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_80800AB8;
    }
    goto skip_2;
    // 0x80800A34: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    skip_2:
    // 0x80800A38: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80800A3C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(880, 0X13E0) << 16);
    // 0x80800A40: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80800A44: nop

    // 0x80800A48: bc1fl       L_80800AB8
    if (!c1cs) {
        // 0x80800A4C: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_80800AB8;
    }
    goto skip_3;
    // 0x80800A4C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    skip_3:
    // 0x80800A50: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80800A54: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800A58: lwc1        $f16, 0x13E0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X13E0));
    // 0x80800A5C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(880, 0X148C) << 16);
    // 0x80800A60: addiu       $a3, $a3, 0x148C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(880, 0X148C));
    // 0x80800A64: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80800A68: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800A6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800A70: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800A74: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    // 0x80800A78: jal         0x8010D930
    // 0x80800A7C: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    func_8010D930(rdram, ctx);
        goto after_9;
    // 0x80800A7C: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    after_9:
    // 0x80800A80: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800A84: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800A88: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80800A8C: add.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80800A90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A94: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80800A98: nop

    // 0x80800A9C: bc1fl       L_80800AB8
    if (!c1cs) {
        // 0x80800AA0: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_80800AB8;
    }
    goto skip_4;
    // 0x80800AA0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    skip_4:
    // 0x80800AA4: jal         0x800D1254
    // 0x80800AA8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800D1254(rdram, ctx);
        goto after_10;
    // 0x80800AA8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_10:
    // 0x80800AAC: b           L_80800AC8
    // 0x80800AB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800AC8;
    // 0x80800AB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800AB4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_80800AB8:
    // 0x80800AB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800ABC: jal         0x800D1254
    // 0x80800AC0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800D1254(rdram, ctx);
        goto after_11;
    // 0x80800AC0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_11:
    // 0x80800AC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800AC8:
    // 0x80800AC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800ACC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800AD0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800AD4: jr          $ra
    // 0x80800AD8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800AD8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800E81E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E81E0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800E81E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E81E8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800E81EC: jal         0x8001A0C0
    // 0x800E81F0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    func_8001A0C0(rdram, ctx);
        goto after_0;
    // 0x800E81F0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x800E81F4: sra         $t6, $v0, 13
    ctx->r14 = S32(SIGNED(ctx->r2) >> 13);
    // 0x800E81F8: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x800E81FC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800E8200: addiu       $t9, $t9, 0x34C0
    ctx->r25 = ADD32(ctx->r25, 0X34C0);
    // 0x800E8204: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800E8208: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x800E820C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x800E8210: lw          $t4, 0x4($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4);
    // 0x800E8214: sra         $t0, $v0, 2
    ctx->r8 = S32(SIGNED(ctx->r2) >> 2);
    // 0x800E8218: andi        $t1, $t0, 0x7FF
    ctx->r9 = ctx->r8 & 0X7FF;
    // 0x800E821C: sllv        $t3, $t1, $t2
    ctx->r11 = S32(ctx->r9 << (ctx->r10 & 31));
    // 0x800E8220: addu        $a1, $t4, $t3
    ctx->r5 = ADD32(ctx->r12, ctx->r11);
    // 0x800E8224: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800E8228: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800E822C: bgez        $a1, L_800E823C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800E8230: sra         $t5, $a1, 8
        ctx->r13 = S32(SIGNED(ctx->r5) >> 8);
            goto L_800E823C;
    }
    // 0x800E8230: sra         $t5, $a1, 8
    ctx->r13 = S32(SIGNED(ctx->r5) >> 8);
    // 0x800E8234: addiu       $at, $a1, 0xFF
    ctx->r1 = ADD32(ctx->r5, 0XFF);
    // 0x800E8238: sra         $t5, $at, 8
    ctx->r13 = S32(SIGNED(ctx->r1) >> 8);
L_800E823C:
    // 0x800E823C: addiu       $t6, $t5, -0x1FF
    ctx->r14 = ADD32(ctx->r13, -0X1FF);
    // 0x800E8240: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800E8244: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800E8248: lwc1        $f8, 0x5E40($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5E40);
    // 0x800E824C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E8250: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800E8254: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800E8258: jal         0x800F2100
    // 0x800E825C: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x800E825C: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x800E8260: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800E8264: lwc1        $f18, 0x5E44($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5E44);
    // 0x800E8268: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800E826C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E8270: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800E8274: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800E8278: bc1fl       L_800E8290
    if (!c1cs) {
        // 0x800E827C: div.s       $f2, $f4, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
            goto L_800E8290;
    }
    goto skip_0;
    // 0x800E827C: div.s       $f2, $f4, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    skip_0:
    // 0x800E8280: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800E8284: b           L_800E8294
    // 0x800E8288: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_800E8294;
    // 0x800E8288: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800E828C: div.s       $f2, $f4, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
L_800E8290:
    // 0x800E8290: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800E8294:
    // 0x800E8294: jr          $ra
    // 0x800E8298: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800E8298: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void bskazstilt_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009A0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808009A4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(292, 0X1230) << 16);
    // 0x808009A8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808009AC: jr          $ra
    // 0x808009B0: lw          $v0, 0x1230($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(292, 0X1230));
    return;
    // 0x808009B0: lw          $v0, 0x1230($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(292, 0X1230));
;}
RECOMP_FUNC void _gspropmarker_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C50: syscall     730
    recomp_syscall_handler(rdram, ctx, 0x80088C50);
    return;
    // 0x80088C54: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void chbottlesdead_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080008C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1992, 0XC0) << 16);
    // 0x80800090: jr          $ra
    // 0x80800094: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1992, 0XC0));
    return;
    // 0x80800094: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1992, 0XC0));
    // 0x80800098: nop

    // 0x8080009C: nop

;}
RECOMP_FUNC void badrone_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800514: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800518: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080051C: jal         0x80800348
    // 0x80800520: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800348_badrone(rdram, ctx);
        goto after_0;
    // 0x80800520: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x80800524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800528: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080052C: jr          $ra
    // 0x80800530: nop

    return;
    // 0x80800530: nop

;}
RECOMP_FUNC void _sumole_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800899D0: syscall     800
    recomp_syscall_handler(rdram, ctx, 0x800899D0);
    return;
    // 0x800899D4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808003E4_sumumbofx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003E4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808003E8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808003EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003F8: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x808003FC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800400: jal         0x8010D254
    // 0x80800404: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x80800404: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80800408: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080040C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800410: jal         0x800EEB9C
    // 0x80800414: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    func_800EEB9C(rdram, ctx);
        goto after_1;
    // 0x80800414: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    after_1:
    // 0x80800418: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x8080041C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800420: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800424: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800428: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080042C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800430: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x80800434: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800438: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x8080043C: nop

    // 0x80800440: bc1f        L_80800464
    if (!c1cs) {
        // 0x80800444: nop
    
            goto L_80800464;
    }
    // 0x80800444: nop

    // 0x80800448: mov.s       $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = ctx->f10.fl;
    // 0x8080044C: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
L_80800450:
    // 0x80800450: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80800454: nop

    // 0x80800458: bc1tl       L_80800450
    if (c1cs) {
        // 0x8080045C: sub.s       $f0, $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_80800450;
    }
    goto skip_0;
    // 0x8080045C: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
    skip_0:
    // 0x80800460: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
L_80800464:
    // 0x80800464: jal         0x800EF04C
    // 0x80800468: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x80800468: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x8080046C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800470: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800474: lwc1        $f18, 0x28($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800478: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080047C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80800480: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800484: jal         0x800EF334
    // 0x80800488: nop

    func_800EF334(rdram, ctx);
        goto after_3;
    // 0x80800488: nop

    after_3:
    // 0x8080048C: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x80800490: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x80800494: jal         0x800EF334
    // 0x80800498: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_800EF334(rdram, ctx);
        goto after_4;
    // 0x80800498: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_4:
    // 0x8080049C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808004A0: jal         0x800EF04C
    // 0x808004A4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x808004A4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_5:
    // 0x808004A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004B0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808004B4: jr          $ra
    // 0x808004B8: nop

    return;
    // 0x808004B8: nop

;}
RECOMP_FUNC void badata_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D34: jal         0x80800000
    // 0x80800D38: nop

    func_80800000_badata(rdram, ctx);
        goto after_0;
    // 0x80800D38: nop

    after_0:
    // 0x80800D3C: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x80800D40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D44: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(473, 0X14D8) << 16);
    // 0x80800D48: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800D4C: lh          $v0, 0x14D8($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(473, 0X14D8));
    // 0x80800D50: jr          $ra
    // 0x80800D54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800D54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80808C64_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808C64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80808C68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80808C6C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80808C70: jal         0x80100094
    // 0x80808C74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80808C74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80808C78: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80808C7C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80808C80: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80808C84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80808C88: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80808C8C:
    // 0x80808C8C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80808C90: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80808C94: bne         $v1, $a1, L_80808C8C
    if (ctx->r3 != ctx->r5) {
        // 0x80808C98: swc1        $f0, 0xBC($a0)
        MEM_W(0XBC, ctx->r4) = ctx->f0.u32l;
            goto L_80808C8C;
    }
    // 0x80808C98: swc1        $f0, 0xBC($a0)
    MEM_W(0XBC, ctx->r4) = ctx->f0.u32l;
    // 0x80808C9C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80808CA0: addiu       $a0, $a2, 0xD4
    ctx->r4 = ADD32(ctx->r6, 0XD4);
    // 0x80808CA4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80808CA8: jal         0x800EE7F8
    // 0x80808CAC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80808CAC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x80808CB0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80808CB4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80808CB8: lwc1        $f4, 0x48($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X48);
    // 0x80808CBC: swc1        $f4, 0xE0($a2)
    MEM_W(0XE0, ctx->r6) = ctx->f4.u32l;
    // 0x80808CC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80808CC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80808CC8: jr          $ra
    // 0x80808CCC: nop

    return;
    // 0x80808CCC: nop

;}
RECOMP_FUNC void func_80801218_chsabreman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801218: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8080121C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801220: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801224: jal         0x801022E4
    // 0x80801228: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_801022E4(rdram, ctx);
        goto after_0;
    // 0x80801228: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080122C: addiu       $t6, $v0, -0x2F7
    ctx->r14 = ADD32(ctx->r2, -0X2F7);
    // 0x80801230: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x80801234: beq         $at, $zero, L_80801578
    if (ctx->r1 == 0) {
        // 0x80801238: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80801578;
    }
    // 0x80801238: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080123C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1232, 0X1BAC) << 16);
    // 0x80801240: addu        $at, $at, $t6
    gpr jr_addend_80801248 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801244: lw          $t6, 0x1BAC($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1232, 0X1BAC));
    // 0x80801248: jr          $t6
    // 0x8080124C: nop

    switch (jr_addend_80801248 >> 2) {
        case 0: goto L_80801250; break;
        case 1: goto L_80801578; break;
        case 2: goto L_808012B0; break;
        case 3: goto L_80801360; break;
        case 4: goto L_808013FC; break;
        case 5: goto L_80801440; break;
        case 6: goto L_808014A0; break;
        case 7: goto L_808014E0; break;
        case 8: goto L_80801504; break;
        default: switch_error(__func__, 0x80801248, 0x80801BAC);
    }
    // 0x8080124C: nop

L_80801250:
    // 0x80801250: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1232, 0X1E18) << 16);
    // 0x80801254: addiu       $t7, $t7, 0x1E18
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1232, 0X1E18));
    // 0x80801258: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8080125C: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    // 0x80801260: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801264: sw          $at, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r1;
    // 0x80801268: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8080126C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1232, 0X1E30) << 16);
    // 0x80801270: addiu       $a2, $a2, 0x1E30
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1232, 0X1E30));
    // 0x80801274: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x80801278: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8080127C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801280: sw          $at, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r1;
    // 0x80801284: jal         0x80089D28
    // 0x80801288: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80801288: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_1:
    // 0x8080128C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1232, 0X1E40) << 16);
    // 0x80801290: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80801294: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80801298: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8080129C: addiu       $a2, $a2, 0x1E40
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1232, 0X1E40));
    // 0x808012A0: jal         0x80089D20
    // 0x808012A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808012A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808012A8: b           L_8080157C
    // 0x808012AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080157C;
    // 0x808012AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808012B0:
    // 0x808012B0: lui         $a1, 0x3CA3
    ctx->r5 = S32(0X3CA3 << 16);
    // 0x808012B4: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x808012B8: jal         0x80101E14
    // 0x808012BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_3;
    // 0x808012BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808012C0: beq         $v0, $zero, L_8080133C
    if (ctx->r2 == 0) {
        // 0x808012C4: addiu       $a1, $zero, 0x5
        ctx->r5 = ADD32(0, 0X5);
            goto L_8080133C;
    }
    // 0x808012C4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808012C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808012CC: jal         0x8008A0E0
    // 0x808012D0: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x808012D0: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_4:
    // 0x808012D4: beq         $v0, $zero, L_80801328
    if (ctx->r2 == 0) {
        // 0x808012D8: addiu       $a0, $sp, 0x44
        ctx->r4 = ADD32(ctx->r29, 0X44);
            goto L_80801328;
    }
    // 0x808012D8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x808012DC: jal         0x800EE7F8
    // 0x808012E0: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x808012E0: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_5:
    // 0x808012E4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x808012E8: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x808012EC: jal         0x800EF1B8
    // 0x808012F0: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_6;
    // 0x808012F0: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    after_6:
    // 0x808012F4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808012F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808012FC: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80801300: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1232, 0X1E60) << 16);
    // 0x80801304: addiu       $t1, $t1, 0x1E60
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1232, 0X1E60));
    // 0x80801308: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080130C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80801310: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801314: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80801318: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x8080131C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x80801320: jal         0x800BABB8
    // 0x80801324: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_7;
    // 0x80801324: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_7:
L_80801328:
    // 0x80801328: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1232, 0X1E50) << 16);
    // 0x8080132C: addiu       $a2, $a2, 0x1E50
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1232, 0X1E50));
    // 0x80801330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801334: jal         0x80089D18
    // 0x80801338: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80801338: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_8:
L_8080133C:
    // 0x8080133C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1232, 0X1E8C) << 16);
    // 0x80801340: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1232, 0X1E9C) << 16);
    // 0x80801344: addiu       $a3, $a3, 0x1E9C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1232, 0X1E9C));
    // 0x80801348: addiu       $a2, $a2, 0x1E8C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1232, 0X1E8C));
    // 0x8080134C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801350: jal         0x80089D28
    // 0x80801354: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x80801354: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x80801358: b           L_8080157C
    // 0x8080135C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080157C;
    // 0x8080135C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801360:
    // 0x80801360: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801364: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1232, 0X1EC4) << 16);
    // 0x80801368: addiu       $a2, $a2, 0x1EC4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1232, 0X1EC4));
    // 0x8080136C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80801370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801374: jal         0x80089D20
    // 0x80801378: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x80801378: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_10:
    // 0x8080137C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1232, 0X1E30) << 16);
    // 0x80801380: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80801384: addiu       $a2, $a2, 0x1E30
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1232, 0X1E30));
    // 0x80801388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080138C: jal         0x80089D20
    // 0x80801390: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x80801390: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    after_11:
    // 0x80801394: jal         0x80101F24
    // 0x80801398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_12;
    // 0x80801398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080139C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1232, 0X1BD0) << 16);
    // 0x808013A0: lwc1        $f10, 0x1BD0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1232, 0X1BD0));
    // 0x808013A4: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x808013A8: nop

    // 0x808013AC: bc1fl       L_8080157C
    if (!c1cs) {
        // 0x808013B0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080157C;
    }
    goto skip_0;
    // 0x808013B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808013B4: jal         0x8001210C
    // 0x808013B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_13;
    // 0x808013B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_13:
    // 0x808013BC: beq         $v0, $zero, L_80801578
    if (ctx->r2 == 0) {
        // 0x808013C0: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_80801578;
    }
    // 0x808013C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808013C4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808013C8: jal         0x8008A0E0
    // 0x808013CC: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_14;
    // 0x808013CC: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_14:
    // 0x808013D0: beq         $v0, $zero, L_80801578
    if (ctx->r2 == 0) {
        // 0x808013D4: addiu       $a0, $sp, 0x38
        ctx->r4 = ADD32(ctx->r29, 0X38);
            goto L_80801578;
    }
    // 0x808013D4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808013D8: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1232, 0X1ED4) << 16);
    // 0x808013DC: addiu       $t2, $t2, 0x1ED4
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1232, 0X1ED4));
    // 0x808013E0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808013E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808013E8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808013EC: jal         0x800BBCB8
    // 0x808013F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_15;
    // 0x808013F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_15:
    // 0x808013F4: b           L_8080157C
    // 0x808013F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080157C;
    // 0x808013F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808013FC:
    // 0x808013FC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801400: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1232, 0X1EFC) << 16);
    // 0x80801404: lui         $a3, 0x3F19
    ctx->r7 = S32(0X3F19 << 16);
    // 0x80801408: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x8080140C: addiu       $a2, $a2, 0x1EFC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1232, 0X1EFC));
    // 0x80801410: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80801414: jal         0x80089D20
    // 0x80801418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_16;
    // 0x80801418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8080141C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1232, 0X1F08) << 16);
    // 0x80801420: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80801424: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80801428: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8080142C: addiu       $a2, $a2, 0x1F08
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1232, 0X1F08));
    // 0x80801430: jal         0x80089D20
    // 0x80801434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_17;
    // 0x80801434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80801438: b           L_8080157C
    // 0x8080143C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080157C;
    // 0x8080143C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801440:
    // 0x80801440: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801444: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1232, 0X1F14) << 16);
    // 0x80801448: lui         $a3, 0x3CCC
    ctx->r7 = S32(0X3CCC << 16);
    // 0x8080144C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80801450: addiu       $a2, $a2, 0x1F14
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1232, 0X1F14));
    // 0x80801454: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80801458: jal         0x80089D20
    // 0x8080145C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_18;
    // 0x8080145C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80801460: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1232, 0X1F2C) << 16);
    // 0x80801464: lui         $a3, 0x3DF5
    ctx->r7 = S32(0X3DF5 << 16);
    // 0x80801468: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8080146C: ori         $a3, $a3, 0xC28F
    ctx->r7 = ctx->r7 | 0XC28F;
    // 0x80801470: addiu       $a2, $a2, 0x1F2C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1232, 0X1F2C));
    // 0x80801474: jal         0x80089D20
    // 0x80801478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_19;
    // 0x80801478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8080147C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1232, 0X1F44) << 16);
    // 0x80801480: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1232, 0X1F5C) << 16);
    // 0x80801484: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80801488: addiu       $a3, $a3, 0x1F5C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1232, 0X1F5C));
    // 0x8080148C: addiu       $a2, $a2, 0x1F44
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1232, 0X1F44));
    // 0x80801490: jal         0x80089D28
    // 0x80801494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_20;
    // 0x80801494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80801498: b           L_8080157C
    // 0x8080149C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080157C;
    // 0x8080149C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808014A0:
    // 0x808014A0: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(1232, 0X1E24) << 16);
    // 0x808014A4: addiu       $t3, $t3, 0x1E24
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(1232, 0X1E24));
    // 0x808014A8: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x808014AC: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    // 0x808014B0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1232, 0X1E30) << 16);
    // 0x808014B4: sw          $at, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r1;
    // 0x808014B8: lw          $t6, 0x4($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X4);
    // 0x808014BC: addiu       $a2, $a2, 0x1E30
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1232, 0X1E30));
    // 0x808014C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014C4: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x808014C8: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x808014CC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808014D0: jal         0x80089D28
    // 0x808014D4: sw          $at, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r1;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_21;
    // 0x808014D4: sw          $at, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r1;
    after_21:
    // 0x808014D8: b           L_8080157C
    // 0x808014DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080157C;
    // 0x808014DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808014E0:
    // 0x808014E0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1232, 0X1F6C) << 16);
    // 0x808014E4: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x808014E8: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808014EC: addiu       $a2, $a2, 0x1F6C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1232, 0X1F6C));
    // 0x808014F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014F4: jal         0x80089D20
    // 0x808014F8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_22;
    // 0x808014F8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_22:
    // 0x808014FC: b           L_8080157C
    // 0x80801500: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080157C;
    // 0x80801500: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801504:
    // 0x80801504: lbu         $v1, 0x5F($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X5F);
    // 0x80801508: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080150C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801510: bne         $v1, $zero, L_80801528
    if (ctx->r3 != 0) {
        // 0x80801514: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1232, 0X1F78) << 16);
            goto L_80801528;
    }
    // 0x80801514: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1232, 0X1F78) << 16);
    // 0x80801518: jal         0x800C4350
    // 0x8080151C: addiu       $a2, $a2, 0x1F78
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1232, 0X1F78));
    func_800C4350(rdram, ctx);
        goto after_23;
    // 0x8080151C: addiu       $a2, $a2, 0x1F78
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1232, 0X1F78));
    after_23:
    // 0x80801520: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
    // 0x80801524: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80801528:
    // 0x80801528: beq         $v1, $zero, L_80801578
    if (ctx->r3 == 0) {
        // 0x8080152C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801578;
    }
    // 0x8080152C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801530: jal         0x80101E14
    // 0x80801534: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80101E14(rdram, ctx);
        goto after_24;
    // 0x80801534: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_24:
    // 0x80801538: beq         $v0, $zero, L_80801550
    if (ctx->r2 == 0) {
        // 0x8080153C: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_80801550;
    }
    // 0x8080153C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801540: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1232, 0X1F88) << 16);
    // 0x80801544: addiu       $a2, $a2, 0x1F88
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1232, 0X1F88));
    // 0x80801548: jal         0x800C4350
    // 0x8080154C: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    func_800C4350(rdram, ctx);
        goto after_25;
    // 0x8080154C: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    after_25:
L_80801550:
    // 0x80801550: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x80801554: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80801558: jal         0x80101E14
    // 0x8080155C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_26;
    // 0x8080155C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80801560: beq         $v0, $zero, L_80801578
    if (ctx->r2 == 0) {
        // 0x80801564: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_80801578;
    }
    // 0x80801564: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801568: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1232, 0X1F98) << 16);
    // 0x8080156C: addiu       $a2, $a2, 0x1F98
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1232, 0X1F98));
    // 0x80801570: jal         0x800C4350
    // 0x80801574: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    func_800C4350(rdram, ctx);
        goto after_27;
    // 0x80801574: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    after_27:
L_80801578:
    // 0x80801578: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080157C:
    // 0x8080157C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801580: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80801584: jr          $ra
    // 0x80801588: nop

    return;
    // 0x80801588: nop

;}
RECOMP_FUNC void sueggmove_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800360: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800364: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800368: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080036C: jal         0x80100094
    // 0x80800370: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800370: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800374: lbu         $v1, 0xD($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XD);
    // 0x80800378: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8080037C: beq         $v1, $zero, L_80800388
    if (ctx->r3 == 0) {
        // 0x80800380: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80800388;
    }
    // 0x80800380: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80800384: sb          $t6, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r14;
L_80800388:
    // 0x80800388: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8080038C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80800390: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80800394: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800398: jal         0x800EE7F8
    // 0x8080039C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8080039C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x808003A0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x808003A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808003A8: lbu         $t7, 0xF($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0XF);
    // 0x808003AC: bnel        $t7, $at, L_808003C0
    if (ctx->r15 != ctx->r1) {
        // 0x808003B0: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808003C0;
    }
    goto skip_0;
    // 0x808003B0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x808003B4: jal         0x8080012C
    // 0x808003B8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8080012C_sueggmove(rdram, ctx);
        goto after_2;
    // 0x808003B8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x808003BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_808003C0:
    // 0x808003C0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808003C4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x808003C8: jal         0x800EFB24
    // 0x808003CC: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EFB24(rdram, ctx);
        goto after_3;
    // 0x808003CC: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_3:
    // 0x808003D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808003D8: jr          $ra
    // 0x808003DC: nop

    return;
    // 0x808003DC: nop

;}
RECOMP_FUNC void func_800C16F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C16F8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C16FC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C1700: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C1704: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C1708: beq         $a1, $zero, L_800C184C
    if (ctx->r5 == 0) {
        // 0x800C170C: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_800C184C;
    }
    // 0x800C170C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C1710: lbu         $v0, 0x79($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X79);
    // 0x800C1714: beq         $v0, $zero, L_800C1728
    if (ctx->r2 == 0) {
        // 0x800C1718: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800C1728;
    }
    // 0x800C1718: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C171C: jal         0x800C1568
    // 0x800C1720: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_800C1568(rdram, ctx);
        goto after_0;
    // 0x800C1720: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C1724: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
L_800C1728:
    // 0x800C1728: sb          $a2, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r6;
    // 0x800C172C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C1730: jal         0x800C1210
    // 0x800C1734: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C1210(rdram, ctx);
        goto after_1;
    // 0x800C1734: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x800C1738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C173C: jal         0x800C13A0
    // 0x800C1740: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800C13A0(rdram, ctx);
        goto after_2;
    // 0x800C1740: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x800C1744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C1748: jal         0x800C13A0
    // 0x800C174C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800C13A0(rdram, ctx);
        goto after_3;
    // 0x800C174C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x800C1750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C1754: jal         0x800C13A0
    // 0x800C1758: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_800C13A0(rdram, ctx);
        goto after_4;
    // 0x800C1758: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_4:
    // 0x800C175C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800C1760: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x800C1764: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x800C1768: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C176C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C1770: addiu       $a1, $s0, 0x20
    ctx->r5 = ADD32(ctx->r16, 0X20);
    // 0x800C1774: addiu       $a2, $s0, 0x24
    ctx->r6 = ADD32(ctx->r16, 0X24);
    // 0x800C1778: jal         0x800CCEF4
    // 0x800C177C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800CCEF4(rdram, ctx);
        goto after_5;
    // 0x800C177C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x800C1780: beql        $v0, $zero, L_800C1800
    if (ctx->r2 == 0) {
        // 0x800C1784: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C1800;
    }
    goto skip_0;
    // 0x800C1784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x800C1788: jal         0x800CBC00
    // 0x800C178C: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    func_800CBC00(rdram, ctx);
        goto after_6;
    // 0x800C178C: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_6:
    // 0x800C1790: beql        $v0, $zero, L_800C1800
    if (ctx->r2 == 0) {
        // 0x800C1794: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C1800;
    }
    goto skip_1;
    // 0x800C1794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x800C1798: jal         0x800CBBE0
    // 0x800C179C: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    func_800CBBE0(rdram, ctx);
        goto after_7;
    // 0x800C179C: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_7:
    // 0x800C17A0: addiu       $t7, $v0, -0x2
    ctx->r15 = ADD32(ctx->r2, -0X2);
    // 0x800C17A4: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x800C17A8: beq         $at, $zero, L_800C17FC
    if (ctx->r1 == 0) {
        // 0x800C17AC: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800C17FC;
    }
    // 0x800C17AC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C17B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C17B4: addu        $at, $at, $t7
    gpr jr_addend_800C17BC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C17B8: lw          $t7, 0x57C0($at)
    ctx->r15 = ADD32(ctx->r1, 0X57C0);
    // 0x800C17BC: jr          $t7
    // 0x800C17C0: nop

    switch (jr_addend_800C17BC >> 2) {
        case 0: goto L_800C17C4; break;
        case 1: goto L_800C17D0; break;
        case 2: goto L_800C17DC; break;
        case 3: goto L_800C17E8; break;
        case 4: goto L_800C17F4; break;
        default: switch_error(__func__, 0x800C17BC, 0x801257C0);
    }
    // 0x800C17C0: nop

L_800C17C4:
    // 0x800C17C4: addiu       $t8, $zero, 0x19
    ctx->r24 = ADD32(0, 0X19);
    // 0x800C17C8: b           L_800C17FC
    // 0x800C17CC: sb          $t8, 0x60($s0)
    MEM_B(0X60, ctx->r16) = ctx->r24;
        goto L_800C17FC;
    // 0x800C17CC: sb          $t8, 0x60($s0)
    MEM_B(0X60, ctx->r16) = ctx->r24;
L_800C17D0:
    // 0x800C17D0: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x800C17D4: b           L_800C17FC
    // 0x800C17D8: sb          $t9, 0x60($s0)
    MEM_B(0X60, ctx->r16) = ctx->r25;
        goto L_800C17FC;
    // 0x800C17D8: sb          $t9, 0x60($s0)
    MEM_B(0X60, ctx->r16) = ctx->r25;
L_800C17DC:
    // 0x800C17DC: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x800C17E0: b           L_800C17FC
    // 0x800C17E4: sb          $t0, 0x60($s0)
    MEM_B(0X60, ctx->r16) = ctx->r8;
        goto L_800C17FC;
    // 0x800C17E4: sb          $t0, 0x60($s0)
    MEM_B(0X60, ctx->r16) = ctx->r8;
L_800C17E8:
    // 0x800C17E8: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x800C17EC: b           L_800C17FC
    // 0x800C17F0: sb          $t1, 0x60($s0)
    MEM_B(0X60, ctx->r16) = ctx->r9;
        goto L_800C17FC;
    // 0x800C17F0: sb          $t1, 0x60($s0)
    MEM_B(0X60, ctx->r16) = ctx->r9;
L_800C17F4:
    // 0x800C17F4: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x800C17F8: sb          $t2, 0x60($s0)
    MEM_B(0X60, ctx->r16) = ctx->r10;
L_800C17FC:
    // 0x800C17FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C1800:
    // 0x800C1800: jal         0x800C13C4
    // 0x800C1804: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    func_800C13C4(rdram, ctx);
        goto after_8;
    // 0x800C1804: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_8:
    // 0x800C1808: lbu         $a0, 0x60($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X60);
    // 0x800C180C: lbu         $a1, 0x1B($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1B);
    // 0x800C1810: lbu         $a2, 0x1C($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1C);
    // 0x800C1814: jal         0x800C122C
    // 0x800C1818: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_800C122C(rdram, ctx);
        goto after_9;
    // 0x800C1818: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_9:
    // 0x800C181C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800C1820: jal         0x800C1430
    // 0x800C1824: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    func_800C1430(rdram, ctx);
        goto after_10;
    // 0x800C1824: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    after_10:
    // 0x800C1828: lh          $a0, 0x58($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X58);
    // 0x800C182C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800C1830: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x800C1834: lhu         $a2, 0x5A($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X5A);
    // 0x800C1838: lbu         $a3, 0x61($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X61);
    // 0x800C183C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800C1840: addiu       $a0, $a0, -0x3E9
    ctx->r4 = ADD32(ctx->r4, -0X3E9);
    // 0x800C1844: jal         0x800DC3D4
    // 0x800C1848: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_800DC3D4(rdram, ctx);
        goto after_11;
    // 0x800C1848: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_11:
L_800C184C:
    // 0x800C184C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C1850: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C1854: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C1858: jr          $ra
    // 0x800C185C: nop

    return;
    // 0x800C185C: nop

;}
RECOMP_FUNC void chnests_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FA4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(752, 0X1470) << 16);
    // 0x80800FA8: jr          $ra
    // 0x80800FAC: addiu       $v0, $v0, 0x1470
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X1470));
    return;
    // 0x80800FAC: addiu       $v0, $v0, 0x1470
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X1470));
;}
RECOMP_FUNC void bstrexlarge_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808006F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808006FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800700: jal         0x8009E77C
    // 0x80800704: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_8009E77C(rdram, ctx);
        goto after_0;
    // 0x80800704: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_0:
    // 0x80800708: bnel        $v0, $zero, L_8080080C
    if (ctx->r2 != 0) {
        // 0x8080070C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080080C;
    }
    goto skip_0;
    // 0x8080070C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800710: jal         0x8009EFA8
    // 0x80800714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_pushZone(rdram, ctx);
        goto after_1;
    // 0x80800714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800718: lui         $a2, 0x3DF5
    ctx->r6 = S32(0X3DF5 << 16);
    // 0x8080071C: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80800720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800724: jal         0x8009F1C8
    // 0x80800728: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_2;
    // 0x80800728: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8080072C: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x80800730: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800738: jal         0x8009F1C8
    // 0x8080073C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bastick_setZoneMax(rdram, ctx);
        goto after_3;
    // 0x8080073C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800744: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800748: jal         0x8009F1C8
    // 0x8080074C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_4;
    // 0x8080074C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_4:
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800754: lui         $a1, 0x3FE0
    ctx->r5 = S32(0X3FE0 << 16);
    // 0x80800758: jal         0x800A4D6C
    // 0x8080075C: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    func_800A4D6C(rdram, ctx);
        goto after_5;
    // 0x8080075C: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    after_5:
    // 0x80800760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800764: jal         0x80092864
    // 0x80800768: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    func_80092864(rdram, ctx);
        goto after_6;
    // 0x80800768: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    after_6:
    // 0x8080076C: jal         0x8009E4AC
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E4AC(rdram, ctx);
        goto after_7;
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800778: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080077C: jal         0x8009E55C
    // 0x80800780: lui         $a2, 0x4334
    ctx->r6 = S32(0X4334 << 16);
    func_8009E55C(rdram, ctx);
        goto after_8;
    // 0x80800780: lui         $a2, 0x4334
    ctx->r6 = S32(0X4334 << 16);
    after_8:
    // 0x80800784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800788: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080078C: jal         0x8009E53C
    // 0x80800790: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009E53C(rdram, ctx);
        goto after_9;
    // 0x80800790: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_9:
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800798: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080079C: jal         0x8009E55C
    // 0x808007A0: lui         $a2, 0x4370
    ctx->r6 = S32(0X4370 << 16);
    func_8009E55C(rdram, ctx);
        goto after_10;
    // 0x808007A0: lui         $a2, 0x4370
    ctx->r6 = S32(0X4370 << 16);
    after_10:
    // 0x808007A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808007AC: jal         0x8009E53C
    // 0x808007B0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009E53C(rdram, ctx);
        goto after_11;
    // 0x808007B0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_11:
    // 0x808007B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007B8: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    // 0x808007BC: jal         0x800959C8
    // 0x808007C0: lui         $a2, 0x4387
    ctx->r6 = S32(0X4387 << 16);
    func_800959C8(rdram, ctx);
        goto after_12;
    // 0x808007C0: lui         $a2, 0x4387
    ctx->r6 = S32(0X4387 << 16);
    after_12:
    // 0x808007C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007C8: jal         0x8009590C
    // 0x808007CC: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    func_8009590C(rdram, ctx);
        goto after_13;
    // 0x808007CC: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    after_13:
    // 0x808007D0: lui         $a1, 0xC53B
    ctx->r5 = S32(0XC53B << 16);
    // 0x808007D4: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x808007D8: jal         0x8009BCB4
    // 0x808007DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_gravity(rdram, ctx);
        goto after_14;
    // 0x808007DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808007E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007E4: jal         0x80095964
    // 0x808007E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80095964(rdram, ctx);
        goto after_15;
    // 0x808007E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x808007EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808007F4: jal         0x800947EC
    // 0x808007F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_16;
    // 0x808007F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_16:
    // 0x808007FC: sb          $zero, 0x15D($s0)
    MEM_B(0X15D, ctx->r16) = 0;
    // 0x80800800: sb          $zero, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = 0;
    // 0x80800804: sw          $zero, 0x164($s0)
    MEM_W(0X164, ctx->r16) = 0;
    // 0x80800808: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080080C:
    // 0x8080080C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800810: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800814: jr          $ra
    // 0x80800818: nop

    return;
    // 0x80800818: nop

;}
RECOMP_FUNC void func_800A0C44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0C44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A0C48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A0C4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A0C50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A0C54: jal         0x800A0CF4
    // 0x800A0C58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_0;
    // 0x800A0C58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800A0C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A0C60: jal         0x800A0CE8
    // 0x800A0C64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CE8(rdram, ctx);
        goto after_1;
    // 0x800A0C64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800A0C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A0C6C: jal         0x800A0CDC
    // 0x800A0C70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CDC(rdram, ctx);
        goto after_2;
    // 0x800A0C70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800A0C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A0C78: jal         0x800A0D74
    // 0x800A0C7C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_800A0D74(rdram, ctx);
        goto after_3;
    // 0x800A0C7C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x800A0C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A0C84: jal         0x800A0D84
    // 0x800A0C88: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_800A0D84(rdram, ctx);
        goto after_4;
    // 0x800A0C88: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x800A0C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A0C90: jal         0x800A0DB8
    // 0x800A0C94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0DB8(rdram, ctx);
        goto after_5;
    // 0x800A0C94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x800A0C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A0C9C: jal         0x800A0DD0
    // 0x800A0CA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0DD0(rdram, ctx);
        goto after_6;
    // 0x800A0CA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x800A0CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A0CA8: jal         0x800A0CD0
    // 0x800A0CAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CD0(rdram, ctx);
        goto after_7;
    // 0x800A0CAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x800A0CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A0CB4: jal         0x800A0DC4
    // 0x800A0CB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0DC4(rdram, ctx);
        goto after_8;
    // 0x800A0CB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x800A0CBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A0CC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A0CC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A0CC8: jr          $ra
    // 0x800A0CCC: nop

    return;
    // 0x800A0CCC: nop

;}
RECOMP_FUNC void func_800DFFA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DFFA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DFFA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DFFA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DFFAC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800DFFB0: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800DFFB4: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x800DFFB8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800DFFBC: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800DFFC0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    // 0x800DFFC4: jal         0x800EE7F8
    // 0x800DFFC8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800DFFC8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x800DFFCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DFFD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DFFD4: jr          $ra
    // 0x800DFFD8: nop

    return;
    // 0x800DFFD8: nop

;}
RECOMP_FUNC void _idwater_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088E50: syscall     744
    recomp_syscall_handler(rdram, ctx, 0x80088E50);
    return;
    // 0x80088E54: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80802684_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802684: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802688: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080268C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80802690: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80802694: jal         0x800D9078
    // 0x80802698: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x80802698: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x8080269C: beq         $v0, $zero, L_808026C0
    if (ctx->r2 == 0) {
        // 0x808026A0: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_808026C0;
    }
    // 0x808026A0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808026A4: lw          $t6, 0x28($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X28);
    // 0x808026A8: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x808026AC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808026B0: bnel        $t6, $at, L_808026C4
    if (ctx->r14 != ctx->r1) {
        // 0x808026B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808026C4;
    }
    goto skip_0;
    // 0x808026B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808026B8: jal         0x80108B04
    // 0x808026BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_1;
    // 0x808026BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_808026C0:
    // 0x808026C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808026C4:
    // 0x808026C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808026C8: jr          $ra
    // 0x808026CC: nop

    return;
    // 0x808026CC: nop

;}
RECOMP_FUNC void func_8080000C_chtempleinternaldoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800010: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800018: lhu         $v1, 0x76($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X76);
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800020: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800024: srl         $t6, $v1, 7
    ctx->r14 = S32(U32(ctx->r3) >> 7);
    // 0x80800028: addiu       $v1, $t6, -0x32
    ctx->r3 = ADD32(ctx->r14, -0X32);
    // 0x8080002C: beq         $v1, $zero, L_80800058
    if (ctx->r3 == 0) {
        // 0x80800030: nop
    
            goto L_80800058;
    }
    // 0x80800030: nop

    // 0x80800034: beq         $v1, $at, L_80800060
    if (ctx->r3 == ctx->r1) {
        // 0x80800038: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_80800060;
    }
    // 0x80800038: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8080003C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800040: beq         $v1, $at, L_80800060
    if (ctx->r3 == ctx->r1) {
        // 0x80800044: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80800060;
    }
    // 0x80800044: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800048: beq         $v1, $at, L_80800060
    if (ctx->r3 == ctx->r1) {
        // 0x8080004C: lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
            goto L_80800060;
    }
    // 0x8080004C: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80800050: b           L_8080008C
    // 0x80800054: ori         $v0, $v0, 0x60A
    ctx->r2 = ctx->r2 | 0X60A;
        goto L_8080008C;
    // 0x80800054: ori         $v0, $v0, 0x60A
    ctx->r2 = ctx->r2 | 0X60A;
L_80800058:
    // 0x80800058: b           L_8080008C
    // 0x8080005C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080008C;
    // 0x8080005C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800060:
    // 0x80800060: lbu         $t7, 0x762C($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X762C);
    // 0x80800064: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080006C: bne         $t7, $at, L_8080007C
    if (ctx->r15 != ctx->r1) {
        // 0x80800070: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_8080007C;
    }
    // 0x80800070: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800074: b           L_8080008C
    // 0x80800078: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080008C;
    // 0x80800078: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080007C:
    // 0x8080007C: jal         0x80101FDC
    // 0x80800080: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x80800080: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80800084: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800088: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080008C:
    // 0x8080008C: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x80800090: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2188, 0X20C) << 16);
    // 0x80800094: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800098: lwc1        $f0, 0x20C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2188, 0X20C));
    // 0x8080009C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x808000A0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x808000A4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000AC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808000B0: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x808000B4: jal         0x80086898
    // 0x808000B8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808000B8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x808000BC: beq         $v0, $zero, L_808000E4
    if (ctx->r2 == 0) {
        // 0x808000C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000E4;
    }
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: jal         0x800868A8
    // 0x808000C8: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x808000C8: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_2:
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D0: jal         0x800868B8
    // 0x808000D4: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    _chdoormake_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x808000D4: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_3:
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000DC: jal         0x800868C0
    // 0x808000E0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x808000E0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_4:
L_808000E4:
    // 0x808000E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000E8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000F0: jr          $ra
    // 0x808000F4: nop

    return;
    // 0x808000F4: nop

;}
RECOMP_FUNC void func_80801454_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801454: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801458: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080145C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801460: jal         0x808001A8
    // 0x80801464: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808001A8_bswasher(rdram, ctx);
        goto after_0;
    // 0x80801464: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801468: lui         $a2, 0x4079
    ctx->r6 = S32(0X4079 << 16);
    // 0x8080146C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801474: jal         0x8008CB3C
    // 0x80801478: addiu       $a1, $zero, 0x356
    ctx->r5 = ADD32(0, 0X356);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80801478: addiu       $a1, $zero, 0x356
    ctx->r5 = ADD32(0, 0X356);
    after_1:
    // 0x8080147C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80801480: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801488: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080148C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80801490: jal         0x8009FFD8
    // 0x80801494: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80801494: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80801498: jal         0x808000BC
    // 0x8080149C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000BC_bswasher(rdram, ctx);
        goto after_3;
    // 0x8080149C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808014A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014A4: jal         0x8009B9B0
    // 0x808014A8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x808014A8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x808014AC: jal         0x800909CC
    // 0x808014B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800909CC(rdram, ctx);
        goto after_5;
    // 0x808014B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808014B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808014B8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808014BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808014C0: jr          $ra
    // 0x808014C4: nop

    return;
    // 0x808014C4: nop

;}
RECOMP_FUNC void func_808005B4_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005BC: lw          $a1, 0x24($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X24);
    // 0x808005C0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808005C4: beq         $a1, $zero, L_808005DC
    if (ctx->r5 == 0) {
        // 0x808005C8: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_808005DC;
    }
    // 0x808005C8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808005CC: jal         0x800C8B84
    // 0x808005D0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800C8B84(rdram, ctx);
        goto after_0;
    // 0x808005D0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x808005D4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808005D8: sw          $zero, 0x24($a2)
    MEM_W(0X24, ctx->r6) = 0;
L_808005DC:
    // 0x808005DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005E4: jr          $ra
    // 0x808005E8: nop

    return;
    // 0x808005E8: nop

;}
RECOMP_FUNC void func_808004D8_glhittableDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004E0: bne         $a0, $zero, L_808004F0
    if (ctx->r4 != 0) {
        // 0x808004E4: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_808004F0;
    }
    // 0x808004E4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808004E8: b           L_8080051C
    // 0x808004EC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_8080051C;
    // 0x808004EC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_808004F0:
    // 0x808004F0: lw          $t6, 0x24($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X24);
    // 0x808004F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808004F8: srl         $t7, $t6, 22
    ctx->r15 = S32(U32(ctx->r14) >> 22);
    // 0x808004FC: bne         $t7, $zero, L_8080051C
    if (ctx->r15 != 0) {
        // 0x80800500: nop
    
            goto L_8080051C;
    }
    // 0x80800500: nop

    // 0x80800504: lhu         $a0, 0x1A($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X1A);
    // 0x80800508: srl         $t8, $a0, 5
    ctx->r24 = S32(U32(ctx->r4) >> 5);
    // 0x8080050C: jal         0x800F52B8
    // 0x80800510: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800F52B8(rdram, ctx);
        goto after_0;
    // 0x80800510: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
    // 0x80800514: b           L_80800520
    // 0x80800518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800520;
    // 0x80800518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080051C:
    // 0x8080051C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800520:
    // 0x80800520: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800524: jr          $ra
    // 0x80800528: nop

    return;
    // 0x80800528: nop

    // 0x8080052C: nop

;}
RECOMP_FUNC void chjiggygamenew_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802B10: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80802B14: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(772, 0X3DCC) << 16);
    // 0x80802B18: addiu       $a1, $a1, 0x3DCC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(772, 0X3DCC));
    // 0x80802B1C: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    // 0x80802B20: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80802B24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802B28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802B2C: addiu       $a0, $zero, 0x1DF
    ctx->r4 = ADD32(0, 0X1DF);
    // 0x80802B30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802B34: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x80802B38: jal         0x80108474
    // 0x80802B3C: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    func_80108474(rdram, ctx);
        goto after_0;
    // 0x80802B3C: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    after_0:
    // 0x80802B40: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(772, 0X3DD8) << 16);
    // 0x80802B44: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80802B48: addiu       $a1, $a1, 0x3DD8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(772, 0X3DD8));
    // 0x80802B4C: addiu       $a0, $zero, 0x1E2
    ctx->r4 = ADD32(0, 0X1E2);
    // 0x80802B50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802B54: jal         0x80108528
    // 0x80802B58: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    func_80108528(rdram, ctx);
        goto after_1;
    // 0x80802B58: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80802B5C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80802B60: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80802B64: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80802B68: addiu       $a0, $zero, 0x1DE
    ctx->r4 = ADD32(0, 0X1DE);
    // 0x80802B6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802B70: sw          $t6, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->r14;
    // 0x80802B74: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80802B78: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    // 0x80802B7C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80802B80: sw          $t9, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r25;
    // 0x80802B84: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80802B88: jal         0x80108528
    // 0x80802B8C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80108528(rdram, ctx);
        goto after_2;
    // 0x80802B8C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_2:
    // 0x80802B90: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80802B94: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80802B98: sw          $t0, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r8;
    // 0x80802B9C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80802BA0: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80802BA4: sw          $t3, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r11;
    // 0x80802BA8: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80802BAC: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80802BB0: lhu         $t5, 0x12($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X12);
    // 0x80802BB4: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80802BB8: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x80802BBC: sh          $t7, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r15;
    // 0x80802BC0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80802BC4: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x80802BC8: lhu         $t9, 0x12($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X12);
    // 0x80802BCC: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80802BD0: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x80802BD4: sh          $t1, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r9;
    // 0x80802BD8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80802BDC: lhu         $t2, 0x12($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X12);
    // 0x80802BE0: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80802BE4: ori         $t4, $t3, 0x2
    ctx->r12 = ctx->r11 | 0X2;
    // 0x80802BE8: jal         0x800EC828
    // 0x80802BEC: sh          $t4, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r12;
    func_800EC828(rdram, ctx);
        goto after_3;
    // 0x80802BEC: sh          $t4, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r12;
    after_3:
    // 0x80802BF0: jal         0x800EC828
    // 0x80802BF4: nop

    func_800EC828(rdram, ctx);
        goto after_4;
    // 0x80802BF4: nop

    after_4:
    // 0x80802BF8: jal         0x800EC828
    // 0x80802BFC: nop

    func_800EC828(rdram, ctx);
        goto after_5;
    // 0x80802BFC: nop

    after_5:
    // 0x80802C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802C04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802C08: jr          $ra
    // 0x80802C0C: nop

    return;
    // 0x80802C0C: nop

;}
RECOMP_FUNC void subaddiedialog_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800990: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800994: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800998: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8080099C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x808009A0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808009A4: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x808009A8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x808009AC: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x808009B0: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x808009B4: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x808009B8: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x808009BC: lbu         $t6, 0xC($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0XC);
    // 0x808009C0: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x808009C4: jal         0x800F54E4
    // 0x808009C8: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808009C8: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    after_0:
    // 0x808009CC: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x808009D0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808009D4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808009D8: blezl       $t7, L_80800AB4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x808009DC: lw          $t4, 0x48($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X48);
            goto L_80800AB4;
    }
    goto skip_0;
    // 0x808009DC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    skip_0:
    // 0x808009E0: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
L_808009E4:
    // 0x808009E4: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x808009E8: sll         $t0, $s1, 3
    ctx->r8 = S32(ctx->r17 << 3);
    // 0x808009EC: bne         $t8, $zero, L_80800A20
    if (ctx->r24 != 0) {
        // 0x808009F0: addu        $s0, $t9, $t0
        ctx->r16 = ADD32(ctx->r25, ctx->r8);
            goto L_80800A20;
    }
    // 0x808009F0: addu        $s0, $t9, $t0
    ctx->r16 = ADD32(ctx->r25, ctx->r8);
    // 0x808009F4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808009F8: jal         0x800F64A4
    // 0x808009FC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800F64A4(rdram, ctx);
        goto after_1;
    // 0x808009FC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x80800A00: beql        $v0, $zero, L_80800A24
    if (ctx->r2 == 0) {
        // 0x80800A04: lw          $t3, 0x44($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X44);
            goto L_80800A24;
    }
    goto skip_1;
    // 0x80800A04: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    skip_1:
    // 0x80800A08: lbu         $t1, 0x6($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X6);
    // 0x80800A0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800A10: bnel        $t1, $at, L_80800A24
    if (ctx->r9 != ctx->r1) {
        // 0x80800A14: lw          $t3, 0x44($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X44);
            goto L_80800A24;
    }
    goto skip_2;
    // 0x80800A14: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x80800A18: lh          $t2, 0x4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X4);
    // 0x80800A1C: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
L_80800A20:
    // 0x80800A20: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
L_80800A24:
    // 0x80800A24: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x80800A28: sll         $t5, $s1, 3
    ctx->r13 = S32(ctx->r17 << 3);
    // 0x80800A2C: bne         $t3, $zero, L_80800A60
    if (ctx->r11 != 0) {
        // 0x80800A30: addu        $s0, $t4, $t5
        ctx->r16 = ADD32(ctx->r12, ctx->r13);
            goto L_80800A60;
    }
    // 0x80800A30: addu        $s0, $t4, $t5
    ctx->r16 = ADD32(ctx->r12, ctx->r13);
    // 0x80800A34: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800A38: jal         0x800F64A4
    // 0x80800A3C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800F64A4(rdram, ctx);
        goto after_2;
    // 0x80800A3C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x80800A40: beql        $v0, $zero, L_80800A64
    if (ctx->r2 == 0) {
        // 0x80800A44: lw          $t8, 0x40($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X40);
            goto L_80800A64;
    }
    goto skip_3;
    // 0x80800A44: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    skip_3:
    // 0x80800A48: lbu         $t6, 0x6($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X6);
    // 0x80800A4C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A50: bnel        $t6, $at, L_80800A64
    if (ctx->r14 != ctx->r1) {
        // 0x80800A54: lw          $t8, 0x40($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X40);
            goto L_80800A64;
    }
    goto skip_4;
    // 0x80800A54: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    skip_4:
    // 0x80800A58: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    // 0x80800A5C: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_80800A60:
    // 0x80800A60: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_80800A64:
    // 0x80800A64: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80800A68: sll         $t0, $s1, 3
    ctx->r8 = S32(ctx->r17 << 3);
    // 0x80800A6C: bne         $t8, $zero, L_80800AA0
    if (ctx->r24 != 0) {
        // 0x80800A70: addu        $s0, $t9, $t0
        ctx->r16 = ADD32(ctx->r25, ctx->r8);
            goto L_80800AA0;
    }
    // 0x80800A70: addu        $s0, $t9, $t0
    ctx->r16 = ADD32(ctx->r25, ctx->r8);
    // 0x80800A74: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800A78: jal         0x800F64A4
    // 0x80800A7C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800F64A4(rdram, ctx);
        goto after_3;
    // 0x80800A7C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x80800A80: beql        $v0, $zero, L_80800AA4
    if (ctx->r2 == 0) {
        // 0x80800A84: lw          $t3, 0x60($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X60);
            goto L_80800AA4;
    }
    goto skip_5;
    // 0x80800A84: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    skip_5:
    // 0x80800A88: lbu         $t1, 0x6($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X6);
    // 0x80800A8C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800A90: bnel        $t1, $at, L_80800AA4
    if (ctx->r9 != ctx->r1) {
        // 0x80800A94: lw          $t3, 0x60($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X60);
            goto L_80800AA4;
    }
    goto skip_6;
    // 0x80800A94: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    skip_6:
    // 0x80800A98: lh          $t2, 0x4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X4);
    // 0x80800A9C: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
L_80800AA0:
    // 0x80800AA0: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
L_80800AA4:
    // 0x80800AA4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800AA8: bnel        $s1, $t3, L_808009E4
    if (ctx->r17 != ctx->r11) {
        // 0x80800AAC: lw          $t8, 0x48($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X48);
            goto L_808009E4;
    }
    goto skip_7;
    // 0x80800AAC: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    skip_7:
    // 0x80800AB0: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
L_80800AB4:
    // 0x80800AB4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800AB8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800ABC: beql        $t4, $zero, L_80800C38
    if (ctx->r12 == 0) {
        // 0x80800AC0: lw          $t1, 0x44($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X44);
            goto L_80800C38;
    }
    goto skip_8;
    // 0x80800AC0: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    skip_8:
    // 0x80800AC4: lhu         $s0, 0x8($s2)
    ctx->r16 = MEM_HU(ctx->r18, 0X8);
    // 0x80800AC8: jal         0x80801394
    // 0x80800ACC: lhu         $a2, 0x0($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X0);
    func_80801394_subaddiedialog(rdram, ctx);
        goto after_4;
    // 0x80800ACC: lhu         $a2, 0x0($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X0);
    after_4:
    // 0x80800AD0: beq         $v0, $zero, L_80800C34
    if (ctx->r2 == 0) {
        // 0x80800AD4: lw          $t5, 0x3C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X3C);
            goto L_80800C34;
    }
    // 0x80800AD4: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80800AD8: andi        $t6, $t5, 0x20
    ctx->r14 = ctx->r13 & 0X20;
    // 0x80800ADC: beq         $t6, $zero, L_80800AEC
    if (ctx->r14 == 0) {
        // 0x80800AE0: lw          $a0, 0x54($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X54);
            goto L_80800AEC;
    }
    // 0x80800AE0: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800AE4: ori         $t7, $s0, 0x1
    ctx->r15 = ctx->r16 | 0X1;
    // 0x80800AE8: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
L_80800AEC:
    // 0x80800AEC: lhu         $a1, 0x4($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X4);
    // 0x80800AF0: jal         0x80800000
    // 0x80800AF4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80800000_subaddiedialog(rdram, ctx);
        goto after_5;
    // 0x80800AF4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x80800AF8: bne         $v0, $zero, L_80800B08
    if (ctx->r2 != 0) {
        // 0x80800AFC: lw          $t8, 0x3C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X3C);
            goto L_80800B08;
    }
    // 0x80800AFC: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80800B00: b           L_80800FEC
    // 0x80800B04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800FEC;
    // 0x80800B04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B08:
    // 0x80800B08: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x80800B0C: beq         $t9, $zero, L_80800B30
    if (ctx->r25 == 0) {
        // 0x80800B10: lw          $a0, 0x54($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X54);
            goto L_80800B30;
    }
    // 0x80800B10: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800B14: lhu         $a1, 0x4($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X4);
    // 0x80800B18: jal         0x8080110C
    // 0x80800B1C: lbu         $a2, 0xD($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0XD);
    func_8080110C_subaddiedialog(rdram, ctx);
        goto after_6;
    // 0x80800B1C: lbu         $a2, 0xD($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0XD);
    after_6:
    // 0x80800B20: bnel        $v0, $zero, L_80800B34
    if (ctx->r2 != 0) {
        // 0x80800B24: lw          $t0, 0x3C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X3C);
            goto L_80800B34;
    }
    goto skip_9;
    // 0x80800B24: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    skip_9:
    // 0x80800B28: b           L_80800FEC
    // 0x80800B2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800FEC;
    // 0x80800B2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B30:
    // 0x80800B30: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_80800B34:
    // 0x80800B34: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80800B38: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x80800B3C: beql        $t1, $zero, L_80800B78
    if (ctx->r9 == 0) {
        // 0x80800B40: lw          $t4, 0x3C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X3C);
            goto L_80800B78;
    }
    goto skip_10;
    // 0x80800B40: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    skip_10:
    // 0x80800B44: lwc1        $f4, 0x48($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X48);
    // 0x80800B48: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800B4C: lhu         $a2, 0x4($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X4);
    // 0x80800B50: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800B54: lbu         $a3, 0xD($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0XD);
    // 0x80800B58: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800B5C: jal         0x8080118C
    // 0x80800B60: nop

    func_8080118C_subaddiedialog(rdram, ctx);
        goto after_7;
    // 0x80800B60: nop

    after_7:
    // 0x80800B64: bnel        $v0, $zero, L_80800B78
    if (ctx->r2 != 0) {
        // 0x80800B68: lw          $t4, 0x3C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X3C);
            goto L_80800B78;
    }
    goto skip_11;
    // 0x80800B68: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    skip_11:
    // 0x80800B6C: b           L_80800FEC
    // 0x80800B70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800FEC;
    // 0x80800B70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800B74: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
L_80800B78:
    // 0x80800B78: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800B7C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800B80: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80800B84: bnel        $t5, $zero, L_80800BA8
    if (ctx->r13 != 0) {
        // 0x80800B88: lw          $t6, 0x3C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X3C);
            goto L_80800BA8;
    }
    goto skip_12;
    // 0x80800B88: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    skip_12:
    // 0x80800B8C: jal         0x800F4B8C
    // 0x80800B90: lhu         $a2, 0x8($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X8);
    func_800F4B8C(rdram, ctx);
        goto after_8;
    // 0x80800B90: lhu         $a2, 0x8($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X8);
    after_8:
    // 0x80800B94: bnel        $v0, $zero, L_80800BA8
    if (ctx->r2 != 0) {
        // 0x80800B98: lw          $t6, 0x3C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X3C);
            goto L_80800BA8;
    }
    goto skip_13;
    // 0x80800B98: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    skip_13:
    // 0x80800B9C: b           L_80800FEC
    // 0x80800BA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800FEC;
    // 0x80800BA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800BA4: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
L_80800BA8:
    // 0x80800BA8: lhu         $s0, 0xA($s2)
    ctx->r16 = MEM_HU(ctx->r18, 0XA);
    // 0x80800BAC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800BB0: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x80800BB4: bne         $t7, $zero, L_80800BC4
    if (ctx->r15 != 0) {
        // 0x80800BB8: lw          $a1, 0x48($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X48);
            goto L_80800BC4;
    }
    // 0x80800BB8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80800BBC: ori         $t8, $s0, 0x2
    ctx->r24 = ctx->r16 | 0X2;
    // 0x80800BC0: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
L_80800BC4:
    // 0x80800BC4: jal         0x808010C8
    // 0x80800BC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808010C8_subaddiedialog(rdram, ctx);
        goto after_9;
    // 0x80800BC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x80800BCC: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80800BD0: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80800BD4: lh          $t0, 0x6($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X6);
    // 0x80800BD8: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80800BDC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800BE0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800BE4: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x80800BE8: jal         0x80801284
    // 0x80800BEC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_10;
    // 0x80800BEC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_10:
    // 0x80800BF0: beq         $v0, $zero, L_80800C24
    if (ctx->r2 == 0) {
        // 0x80800BF4: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_80800C24;
    }
    // 0x80800BF4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800BF8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800BFC: jal         0x808013E4
    // 0x80800C00: lhu         $a2, 0x0($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X0);
    func_808013E4_subaddiedialog(rdram, ctx);
        goto after_11;
    // 0x80800C00: lhu         $a2, 0x0($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X0);
    after_11:
    // 0x80800C04: lbu         $v0, 0xE($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0XE);
    // 0x80800C08: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800C0C: beq         $v0, $zero, L_80800C1C
    if (ctx->r2 == 0) {
        // 0x80800C10: nop
    
            goto L_80800C1C;
    }
    // 0x80800C10: nop

    // 0x80800C14: jal         0x80102424
    // 0x80800C18: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80102424(rdram, ctx);
        goto after_12;
    // 0x80800C18: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_12:
L_80800C1C:
    // 0x80800C1C: b           L_80800FEC
    // 0x80800C20: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
        goto L_80800FEC;
    // 0x80800C20: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
L_80800C24:
    // 0x80800C24: jal         0x8080141C
    // 0x80800C28: nop

    func_8080141C_subaddiedialog(rdram, ctx);
        goto after_13;
    // 0x80800C28: nop

    after_13:
    // 0x80800C2C: b           L_80800FF0
    // 0x80800C30: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800FF0;
    // 0x80800C30: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800C34:
    // 0x80800C34: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
L_80800C38:
    // 0x80800C38: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800C3C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80800C40: beq         $t1, $zero, L_80800D64
    if (ctx->r9 == 0) {
        // 0x80800C44: lw          $t3, 0x40($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X40);
            goto L_80800D64;
    }
    // 0x80800C44: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80800C48: lhu         $a1, 0x4($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X4);
    // 0x80800C4C: jal         0x80801208
    // 0x80800C50: lhu         $a2, 0x8($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X8);
    func_80801208_subaddiedialog(rdram, ctx);
        goto after_14;
    // 0x80800C50: lhu         $a2, 0x8($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X8);
    after_14:
    // 0x80800C54: beq         $v0, $zero, L_80800D5C
    if (ctx->r2 == 0) {
        // 0x80800C58: lw          $t2, 0x3C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X3C);
            goto L_80800D5C;
    }
    // 0x80800C58: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80800C5C: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x80800C60: beq         $t3, $zero, L_80800C8C
    if (ctx->r11 == 0) {
        // 0x80800C64: lw          $a0, 0x54($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X54);
            goto L_80800C8C;
    }
    // 0x80800C64: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800C68: lhu         $a1, 0x4($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X4);
    // 0x80800C6C: jal         0x8080110C
    // 0x80800C70: lbu         $a2, 0xD($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0XD);
    func_8080110C_subaddiedialog(rdram, ctx);
        goto after_15;
    // 0x80800C70: lbu         $a2, 0xD($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0XD);
    after_15:
    // 0x80800C74: bnel        $v0, $zero, L_80800C90
    if (ctx->r2 != 0) {
        // 0x80800C78: lw          $t4, 0x3C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X3C);
            goto L_80800C90;
    }
    goto skip_14;
    // 0x80800C78: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    skip_14:
    // 0x80800C7C: jal         0x8080141C
    // 0x80800C80: nop

    func_8080141C_subaddiedialog(rdram, ctx);
        goto after_16;
    // 0x80800C80: nop

    after_16:
    // 0x80800C84: b           L_80800FF0
    // 0x80800C88: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800FF0;
    // 0x80800C88: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800C8C:
    // 0x80800C8C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
L_80800C90:
    // 0x80800C90: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80800C94: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x80800C98: beql        $t5, $zero, L_80800CDC
    if (ctx->r13 == 0) {
        // 0x80800C9C: lw          $t8, 0x3C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X3C);
            goto L_80800CDC;
    }
    goto skip_15;
    // 0x80800C9C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    skip_15:
    // 0x80800CA0: lwc1        $f8, 0x48($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X48);
    // 0x80800CA4: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800CA8: lhu         $a2, 0x4($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X4);
    // 0x80800CAC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800CB0: lbu         $a3, 0xD($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0XD);
    // 0x80800CB4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800CB8: jal         0x8080118C
    // 0x80800CBC: nop

    func_8080118C_subaddiedialog(rdram, ctx);
        goto after_17;
    // 0x80800CBC: nop

    after_17:
    // 0x80800CC0: bnel        $v0, $zero, L_80800CDC
    if (ctx->r2 != 0) {
        // 0x80800CC4: lw          $t8, 0x3C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X3C);
            goto L_80800CDC;
    }
    goto skip_16;
    // 0x80800CC4: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    skip_16:
    // 0x80800CC8: jal         0x8080141C
    // 0x80800CCC: nop

    func_8080141C_subaddiedialog(rdram, ctx);
        goto after_18;
    // 0x80800CCC: nop

    after_18:
    // 0x80800CD0: b           L_80800FF0
    // 0x80800CD4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800FF0;
    // 0x80800CD4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800CD8: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
L_80800CDC:
    // 0x80800CDC: lhu         $s0, 0xA($s2)
    ctx->r16 = MEM_HU(ctx->r18, 0XA);
    // 0x80800CE0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800CE4: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x80800CE8: bne         $t9, $zero, L_80800CF8
    if (ctx->r25 != 0) {
        // 0x80800CEC: lw          $a1, 0x44($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X44);
            goto L_80800CF8;
    }
    // 0x80800CEC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80800CF0: ori         $t0, $s0, 0x3
    ctx->r8 = ctx->r16 | 0X3;
    // 0x80800CF4: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
L_80800CF8:
    // 0x80800CF8: jal         0x808010C8
    // 0x80800CFC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_808010C8_subaddiedialog(rdram, ctx);
        goto after_19;
    // 0x80800CFC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_19:
    // 0x80800D00: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80800D04: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800D08: lh          $t2, 0x6($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X6);
    // 0x80800D0C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80800D10: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800D14: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800D18: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x80800D1C: jal         0x80801284
    // 0x80800D20: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_20;
    // 0x80800D20: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_20:
    // 0x80800D24: beq         $v0, $zero, L_80800D4C
    if (ctx->r2 == 0) {
        // 0x80800D28: nop
    
            goto L_80800D4C;
    }
    // 0x80800D28: nop

    // 0x80800D2C: lbu         $v0, 0xE($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0XE);
    // 0x80800D30: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800D34: beq         $v0, $zero, L_80800D44
    if (ctx->r2 == 0) {
        // 0x80800D38: nop
    
            goto L_80800D44;
    }
    // 0x80800D38: nop

    // 0x80800D3C: jal         0x80102424
    // 0x80800D40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80102424(rdram, ctx);
        goto after_21;
    // 0x80800D40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_21:
L_80800D44:
    // 0x80800D44: b           L_80800FEC
    // 0x80800D48: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
        goto L_80800FEC;
    // 0x80800D48: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
L_80800D4C:
    // 0x80800D4C: jal         0x8080141C
    // 0x80800D50: nop

    func_8080141C_subaddiedialog(rdram, ctx);
        goto after_22;
    // 0x80800D50: nop

    after_22:
    // 0x80800D54: b           L_80800FF0
    // 0x80800D58: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800FF0;
    // 0x80800D58: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800D5C:
    // 0x80800D5C: b           L_80800FEC
    // 0x80800D60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800FEC;
    // 0x80800D60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800D64:
    // 0x80800D64: beq         $t3, $zero, L_80800FEC
    if (ctx->r11 == 0) {
        // 0x80800D68: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800FEC;
    }
    // 0x80800D68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800D6C: lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X2);
    // 0x80800D70: beql        $v0, $zero, L_80800ED4
    if (ctx->r2 == 0) {
        // 0x80800D74: lw          $a0, 0x54($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X54);
            goto L_80800ED4;
    }
    goto skip_17;
    // 0x80800D74: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    skip_17:
    // 0x80800D78: jal         0x800DA298
    // 0x80800D7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA298(rdram, ctx);
        goto after_23;
    // 0x80800D7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_23:
    // 0x80800D80: bne         $v0, $zero, L_80800ED0
    if (ctx->r2 != 0) {
        // 0x80800D84: lw          $t4, 0x3C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X3C);
            goto L_80800ED0;
    }
    // 0x80800D84: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80800D88: andi        $t5, $t4, 0x20
    ctx->r13 = ctx->r12 & 0X20;
    // 0x80800D8C: beq         $t5, $zero, L_80800D9C
    if (ctx->r13 == 0) {
        // 0x80800D90: lhu         $a2, 0x8($s2)
        ctx->r6 = MEM_HU(ctx->r18, 0X8);
            goto L_80800D9C;
    }
    // 0x80800D90: lhu         $a2, 0x8($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X8);
    // 0x80800D94: ori         $t6, $a2, 0x1
    ctx->r14 = ctx->r6 | 0X1;
    // 0x80800D98: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
L_80800D9C:
    // 0x80800D9C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800DA0: jal         0x80800000
    // 0x80800DA4: lhu         $a1, 0x4($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X4);
    func_80800000_subaddiedialog(rdram, ctx);
        goto after_24;
    // 0x80800DA4: lhu         $a1, 0x4($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X4);
    after_24:
    // 0x80800DA8: bne         $v0, $zero, L_80800DB8
    if (ctx->r2 != 0) {
        // 0x80800DAC: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_80800DB8;
    }
    // 0x80800DAC: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80800DB0: b           L_80800FEC
    // 0x80800DB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800FEC;
    // 0x80800DB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800DB8:
    // 0x80800DB8: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x80800DBC: beq         $t8, $zero, L_80800DE0
    if (ctx->r24 == 0) {
        // 0x80800DC0: lw          $a0, 0x54($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X54);
            goto L_80800DE0;
    }
    // 0x80800DC0: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800DC4: lhu         $a1, 0x4($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X4);
    // 0x80800DC8: jal         0x8080110C
    // 0x80800DCC: lbu         $a2, 0xD($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0XD);
    func_8080110C_subaddiedialog(rdram, ctx);
        goto after_25;
    // 0x80800DCC: lbu         $a2, 0xD($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0XD);
    after_25:
    // 0x80800DD0: bnel        $v0, $zero, L_80800DE4
    if (ctx->r2 != 0) {
        // 0x80800DD4: lw          $t9, 0x3C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X3C);
            goto L_80800DE4;
    }
    goto skip_18;
    // 0x80800DD4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    skip_18:
    // 0x80800DD8: b           L_80800FEC
    // 0x80800DDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800FEC;
    // 0x80800DDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800DE0:
    // 0x80800DE0: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
L_80800DE4:
    // 0x80800DE4: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80800DE8: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x80800DEC: beql        $t0, $zero, L_80800E28
    if (ctx->r8 == 0) {
        // 0x80800DF0: lw          $t3, 0x3C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X3C);
            goto L_80800E28;
    }
    goto skip_19;
    // 0x80800DF0: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    skip_19:
    // 0x80800DF4: lwc1        $f16, 0x48($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X48);
    // 0x80800DF8: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800DFC: lhu         $a2, 0x4($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X4);
    // 0x80800E00: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800E04: lbu         $a3, 0xD($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0XD);
    // 0x80800E08: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800E0C: jal         0x8080118C
    // 0x80800E10: nop

    func_8080118C_subaddiedialog(rdram, ctx);
        goto after_26;
    // 0x80800E10: nop

    after_26:
    // 0x80800E14: bnel        $v0, $zero, L_80800E28
    if (ctx->r2 != 0) {
        // 0x80800E18: lw          $t3, 0x3C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X3C);
            goto L_80800E28;
    }
    goto skip_20;
    // 0x80800E18: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    skip_20:
    // 0x80800E1C: b           L_80800FEC
    // 0x80800E20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800FEC;
    // 0x80800E20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800E24: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
L_80800E28:
    // 0x80800E28: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800E2C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800E30: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80800E34: bnel        $t4, $zero, L_80800E58
    if (ctx->r12 != 0) {
        // 0x80800E38: lw          $t5, 0x3C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X3C);
            goto L_80800E58;
    }
    goto skip_21;
    // 0x80800E38: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    skip_21:
    // 0x80800E3C: jal         0x800F4B8C
    // 0x80800E40: lhu         $a2, 0x8($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X8);
    func_800F4B8C(rdram, ctx);
        goto after_27;
    // 0x80800E40: lhu         $a2, 0x8($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X8);
    after_27:
    // 0x80800E44: bnel        $v0, $zero, L_80800E58
    if (ctx->r2 != 0) {
        // 0x80800E48: lw          $t5, 0x3C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X3C);
            goto L_80800E58;
    }
    goto skip_22;
    // 0x80800E48: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    skip_22:
    // 0x80800E4C: b           L_80800FEC
    // 0x80800E50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800FEC;
    // 0x80800E50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800E54: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
L_80800E58:
    // 0x80800E58: lhu         $s0, 0xA($s2)
    ctx->r16 = MEM_HU(ctx->r18, 0XA);
    // 0x80800E5C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800E60: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x80800E64: bne         $t6, $zero, L_80800E74
    if (ctx->r14 != 0) {
        // 0x80800E68: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_80800E74;
    }
    // 0x80800E68: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800E6C: ori         $t7, $s0, 0x2
    ctx->r15 = ctx->r16 | 0X2;
    // 0x80800E70: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
L_80800E74:
    // 0x80800E74: jal         0x808010C8
    // 0x80800E78: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_808010C8_subaddiedialog(rdram, ctx);
        goto after_28;
    // 0x80800E78: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_28:
    // 0x80800E7C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80800E80: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80800E84: lh          $t9, 0x6($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X6);
    // 0x80800E88: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80800E8C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800E90: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800E94: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x80800E98: jal         0x80801284
    // 0x80800E9C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_29;
    // 0x80800E9C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_29:
    // 0x80800EA0: beq         $v0, $zero, L_80800FDC
    if (ctx->r2 == 0) {
        // 0x80800EA4: nop
    
            goto L_80800FDC;
    }
    // 0x80800EA4: nop

    // 0x80800EA8: jal         0x800DA544
    // 0x80800EAC: lhu         $a0, 0x2($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X2);
    func_800DA544(rdram, ctx);
        goto after_30;
    // 0x80800EAC: lhu         $a0, 0x2($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X2);
    after_30:
    // 0x80800EB0: lbu         $v0, 0xE($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0XE);
    // 0x80800EB4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800EB8: beq         $v0, $zero, L_80800EC8
    if (ctx->r2 == 0) {
        // 0x80800EBC: nop
    
            goto L_80800EC8;
    }
    // 0x80800EBC: nop

    // 0x80800EC0: jal         0x80102424
    // 0x80800EC4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80102424(rdram, ctx);
        goto after_31;
    // 0x80800EC4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_31:
L_80800EC8:
    // 0x80800EC8: b           L_80800FEC
    // 0x80800ECC: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
        goto L_80800FEC;
    // 0x80800ECC: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
L_80800ED0:
    // 0x80800ED0: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
L_80800ED4:
    // 0x80800ED4: lhu         $a1, 0x4($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X4);
    // 0x80800ED8: lhu         $a2, 0x8($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X8);
    // 0x80800EDC: jal         0x80801208
    // 0x80800EE0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    func_80801208_subaddiedialog(rdram, ctx);
        goto after_32;
    // 0x80800EE0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    after_32:
    // 0x80800EE4: beq         $v0, $zero, L_80800FDC
    if (ctx->r2 == 0) {
        // 0x80800EE8: lw          $t0, 0x3C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X3C);
            goto L_80800FDC;
    }
    // 0x80800EE8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80800EEC: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x80800EF0: beq         $t1, $zero, L_80800F1C
    if (ctx->r9 == 0) {
        // 0x80800EF4: lw          $a0, 0x54($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X54);
            goto L_80800F1C;
    }
    // 0x80800EF4: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800EF8: lhu         $a1, 0x4($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X4);
    // 0x80800EFC: jal         0x8080110C
    // 0x80800F00: lbu         $a2, 0xD($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0XD);
    func_8080110C_subaddiedialog(rdram, ctx);
        goto after_33;
    // 0x80800F00: lbu         $a2, 0xD($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0XD);
    after_33:
    // 0x80800F04: bnel        $v0, $zero, L_80800F20
    if (ctx->r2 != 0) {
        // 0x80800F08: lw          $t2, 0x3C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X3C);
            goto L_80800F20;
    }
    goto skip_23;
    // 0x80800F08: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    skip_23:
    // 0x80800F0C: jal         0x8080141C
    // 0x80800F10: nop

    func_8080141C_subaddiedialog(rdram, ctx);
        goto after_34;
    // 0x80800F10: nop

    after_34:
    // 0x80800F14: b           L_80800FF0
    // 0x80800F18: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800FF0;
    // 0x80800F18: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800F1C:
    // 0x80800F1C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
L_80800F20:
    // 0x80800F20: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80800F24: andi        $t3, $t2, 0x4
    ctx->r11 = ctx->r10 & 0X4;
    // 0x80800F28: beql        $t3, $zero, L_80800F6C
    if (ctx->r11 == 0) {
        // 0x80800F2C: lw          $t6, 0x3C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X3C);
            goto L_80800F6C;
    }
    goto skip_24;
    // 0x80800F2C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    skip_24:
    // 0x80800F30: lwc1        $f4, 0x48($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X48);
    // 0x80800F34: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800F38: lhu         $a2, 0x4($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X4);
    // 0x80800F3C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800F40: lbu         $a3, 0xD($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0XD);
    // 0x80800F44: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800F48: jal         0x8080118C
    // 0x80800F4C: nop

    func_8080118C_subaddiedialog(rdram, ctx);
        goto after_35;
    // 0x80800F4C: nop

    after_35:
    // 0x80800F50: bnel        $v0, $zero, L_80800F6C
    if (ctx->r2 != 0) {
        // 0x80800F54: lw          $t6, 0x3C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X3C);
            goto L_80800F6C;
    }
    goto skip_25;
    // 0x80800F54: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    skip_25:
    // 0x80800F58: jal         0x8080141C
    // 0x80800F5C: nop

    func_8080141C_subaddiedialog(rdram, ctx);
        goto after_36;
    // 0x80800F5C: nop

    after_36:
    // 0x80800F60: b           L_80800FF0
    // 0x80800F64: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800FF0;
    // 0x80800F64: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800F68: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
L_80800F6C:
    // 0x80800F6C: lhu         $s0, 0xA($s2)
    ctx->r16 = MEM_HU(ctx->r18, 0XA);
    // 0x80800F70: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800F74: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x80800F78: bne         $t7, $zero, L_80800F88
    if (ctx->r15 != 0) {
        // 0x80800F7C: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_80800F88;
    }
    // 0x80800F7C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800F80: ori         $t8, $s0, 0x3
    ctx->r24 = ctx->r16 | 0X3;
    // 0x80800F84: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
L_80800F88:
    // 0x80800F88: jal         0x808010C8
    // 0x80800F8C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_808010C8_subaddiedialog(rdram, ctx);
        goto after_37;
    // 0x80800F8C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_37:
    // 0x80800F90: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80800F94: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80800F98: lh          $t0, 0x6($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X6);
    // 0x80800F9C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80800FA0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800FA4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800FA8: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x80800FAC: jal         0x80801284
    // 0x80800FB0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_38;
    // 0x80800FB0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_38:
    // 0x80800FB4: beq         $v0, $zero, L_80800FDC
    if (ctx->r2 == 0) {
        // 0x80800FB8: nop
    
            goto L_80800FDC;
    }
    // 0x80800FB8: nop

    // 0x80800FBC: lbu         $v0, 0xE($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0XE);
    // 0x80800FC0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800FC4: beq         $v0, $zero, L_80800FD4
    if (ctx->r2 == 0) {
        // 0x80800FC8: nop
    
            goto L_80800FD4;
    }
    // 0x80800FC8: nop

    // 0x80800FCC: jal         0x80102424
    // 0x80800FD0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80102424(rdram, ctx);
        goto after_39;
    // 0x80800FD0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_39:
L_80800FD4:
    // 0x80800FD4: b           L_80800FEC
    // 0x80800FD8: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
        goto L_80800FEC;
    // 0x80800FD8: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
L_80800FDC:
    // 0x80800FDC: jal         0x8080141C
    // 0x80800FE0: nop

    func_8080141C_subaddiedialog(rdram, ctx);
        goto after_40;
    // 0x80800FE0: nop

    after_40:
    // 0x80800FE4: b           L_80800FF0
    // 0x80800FE8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800FF0;
    // 0x80800FE8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800FEC:
    // 0x80800FEC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800FF0:
    // 0x80800FF0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800FF4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800FF8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800FFC: jr          $ra
    // 0x80801000: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80801000: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8008B610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B610: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008B614: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B618: jal         0x8001ACCC
    // 0x8008B61C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x8008B61C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_0:
    // 0x8008B620: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008B624: addiu       $v1, $v1, 0x6CC0
    ctx->r3 = ADD32(ctx->r3, 0X6CC0);
    // 0x8008B628: addiu       $a1, $v0, 0x3C
    ctx->r5 = ADD32(ctx->r2, 0X3C);
    // 0x8008B62C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8008B630: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x8008B634: jal         0x8008BBC0
    // 0x8008B638: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008BBC0(rdram, ctx);
        goto after_1;
    // 0x8008B638: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8008B63C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B640: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008B644: jr          $ra
    // 0x8008B648: nop

    return;
    // 0x8008B648: nop

;}
RECOMP_FUNC void func_808002E0_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808002E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002EC: jal         0x8008E35C
    // 0x808002F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    player_inWater(rdram, ctx);
        goto after_0;
    // 0x808002F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808002F4: beq         $v0, $zero, L_80800338
    if (ctx->r2 == 0) {
        // 0x808002F8: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_80800338;
    }
    // 0x808002F8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800300: jal         0x8009BCB4
    // 0x80800304: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_gravity(rdram, ctx);
        goto after_1;
    // 0x80800304: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080030C: jal         0x8009BCC4
    // 0x80800310: lui         $a1, 0xC57A
    ctx->r5 = S32(0XC57A << 16);
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800310: lui         $a1, 0xC57A
    ctx->r5 = S32(0XC57A << 16);
    after_2:
    // 0x80800314: lui         $a1, 0x3F59
    ctx->r5 = S32(0X3F59 << 16);
    // 0x80800318: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8080031C: jal         0x80084EF0
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovethrust_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800328: jal         0x80084EE8
    // 0x8080032C: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    _bamovethrust_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x8080032C: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_4:
    // 0x80800330: b           L_80800384
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800384;
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800338:
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080033C: jal         0x8009BCB4
    // 0x80800340: lui         $a1, 0xC4E1
    ctx->r5 = S32(0XC4E1 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_5;
    // 0x80800340: lui         $a1, 0xC4E1
    ctx->r5 = S32(0XC4E1 << 16);
    after_5:
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800348: jal         0x8009BCC4
    // 0x8080034C: lui         $a1, 0xC57A
    ctx->r5 = S32(0XC57A << 16);
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_6;
    // 0x8080034C: lui         $a1, 0xC57A
    ctx->r5 = S32(0XC57A << 16);
    after_6:
    // 0x80800350: lui         $a1, 0x3F6E
    ctx->r5 = S32(0X3F6E << 16);
    // 0x80800354: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    // 0x80800358: jal         0x80084EF0
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovethrust_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800360: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(296, 0X16A4) << 16);
    // 0x80800364: lwc1        $f6, 0x16A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(296, 0X16A4));
    // 0x80800368: lwc1        $f4, 0x16C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800370: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800374: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800378: jal         0x80084EE8
    // 0x8080037C: nop

    _bamovethrust_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x8080037C: nop

    after_8:
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800384:
    // 0x80800384: jal         0x800919F4
    // 0x80800388: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_held(rdram, ctx);
        goto after_9;
    // 0x80800388: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_9:
    // 0x8080038C: beq         $v0, $zero, L_808003D0
    if (ctx->r2 == 0) {
        // 0x80800390: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003D0;
    }
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800394: jal         0x80084DA0
    // 0x80800398: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _bakaztorpedo_entrypoint_6(rdram, ctx);
        goto after_10;
    // 0x80800398: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x8080039C: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x808003A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808003A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A8: jal         0x8009650C
    // 0x808003AC: swc1        $f10, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f10.u32l;
    func_8009650C(rdram, ctx);
        goto after_11;
    // 0x808003AC: swc1        $f10, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f10.u32l;
    after_11:
    // 0x808003B0: beq         $v0, $zero, L_808003EC
    if (ctx->r2 == 0) {
        // 0x808003B4: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_808003EC;
    }
    // 0x808003B4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808003B8: lwc1        $f16, 0x16C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x808003BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808003C0: nop

    // 0x808003C4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808003C8: b           L_808003EC
    // 0x808003CC: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
        goto L_808003EC;
    // 0x808003CC: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
L_808003D0:
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D4: jal         0x80084DA0
    // 0x808003D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _bakaztorpedo_entrypoint_6(rdram, ctx);
        goto after_12;
    // 0x808003D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
    // 0x808003DC: lui         $at, 0x41B4
    ctx->r1 = S32(0X41B4 << 16);
    // 0x808003E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003E4: nop

    // 0x808003E8: swc1        $f6, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f6.u32l;
L_808003EC:
    // 0x808003EC: jal         0x808000CC
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000CC_bskaztorpedo(rdram, ctx);
        goto after_13;
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808003F4: jal         0x8009BB94
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB94(rdram, ctx);
        goto after_14;
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808003FC: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80800400: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800404: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800408: lui         $a2, 0x44BB
    ctx->r6 = S32(0X44BB << 16);
    // 0x8080040C: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80800410: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800414: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    // 0x80800418: jal         0x800F10B4
    // 0x8080041C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_15;
    // 0x8080041C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_15:
    // 0x80800420: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800424: jal         0x80084DA8
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bakaztorpedo_entrypoint_7(rdram, ctx);
        goto after_16;
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8080042C: jal         0x8009BFD8
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BFD8(rdram, ctx);
        goto after_17;
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800434: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800438: jal         0x8009BFCC
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BFCC(rdram, ctx);
        goto after_18;
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800440: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800444: jal         0x80013728
    // 0x80800448: sub.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f0.fl;
    func_80013728(rdram, ctx);
        goto after_19;
    // 0x80800448: sub.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f0.fl;
    after_19:
    // 0x8080044C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80800450: jal         0x8009C990
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_20;
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800458: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8080045C: jal         0x8009C984
    // 0x80800460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_21;
    // 0x80800460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800464: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800468: jal         0x80013728
    // 0x8080046C: sub.s       $f12, $f16, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f0.fl;
    func_80013728(rdram, ctx);
        goto after_22;
    // 0x8080046C: sub.s       $f12, $f16, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f0.fl;
    after_22:
    // 0x80800470: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800474: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800478: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800480: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80800484: nop

    // 0x80800488: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8080048C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800490: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800494: jal         0x80084D98
    // 0x80800498: nop

    _bakaztorpedo_entrypoint_5(rdram, ctx);
        goto after_23;
    // 0x80800498: nop

    after_23:
    // 0x8080049C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x808004A0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808004A4: beql        $t6, $zero, L_808004F8
    if (ctx->r14 == 0) {
        // 0x808004A8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808004F8;
    }
    goto skip_0;
    // 0x808004A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808004AC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808004B0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808004B4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808004B8: jal         0x800DC178
    // 0x808004BC: nop

    func_800DC178(rdram, ctx);
        goto after_24;
    // 0x808004BC: nop

    after_24:
    // 0x808004C0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x808004C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808004C8: lwc1        $f12, 0x16C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x808004CC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808004D0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808004D4: lui         $a2, 0x4361
    ctx->r6 = S32(0X4361 << 16);
    // 0x808004D8: jal         0x800F10B4
    // 0x808004DC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_25;
    // 0x808004DC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_25:
    // 0x808004E0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808004EC: jal         0x80091290
    // 0x808004F0: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    func_80091290(rdram, ctx);
        goto after_26;
    // 0x808004F0: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    after_26:
    // 0x808004F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004F8:
    // 0x808004F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808004FC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800500: jr          $ra
    // 0x80800504: nop

    return;
    // 0x80800504: nop

;}
RECOMP_FUNC void func_808019A4_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019A4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808019A8: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2658, 0X2130) << 16);
    // 0x808019AC: lh          $t6, 0x2130($t6)
    ctx->r14 = MEM_H(ctx->r14, (int16_t)RELOC_LO16(2658, 0X2130));
    // 0x808019B0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x808019B4: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x808019B8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x808019BC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x808019C0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x808019C4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808019C8: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x808019CC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808019D0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x808019D4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x808019D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808019DC: beq         $s4, $t6, L_80801A50
    if (ctx->r20 == ctx->r14) {
        // 0x808019E0: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_80801A50;
    }
    // 0x808019E0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x808019E4: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2658, 0X2130) << 16);
    // 0x808019E8: addiu       $s0, $t7, 0x2130
    ctx->r16 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2658, 0X2130));
    // 0x808019EC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x808019F0: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_808019F4:
    // 0x808019F4: jal         0x800D0018
    // 0x808019F8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800D0018(rdram, ctx);
        goto after_0;
    // 0x808019F8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x808019FC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801A00: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80801A04: jal         0x800CFC8C
    // 0x80801A08: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800CFC8C(rdram, ctx);
        goto after_1;
    // 0x80801A08: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x80801A0C: bne         $s3, $s6, L_80801A18
    if (ctx->r19 != ctx->r22) {
        // 0x80801A10: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80801A18;
    }
    // 0x80801A10: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801A14: beq         $s1, $zero, L_80801A40
    if (ctx->r17 == 0) {
        // 0x80801A18: addiu       $t8, $zero, 0x6
        ctx->r24 = ADD32(0, 0X6);
            goto L_80801A40;
    }
L_80801A18:
    // 0x80801A18: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80801A1C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801A20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801A24: lh          $a2, 0x4($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X4);
    // 0x80801A28: lh          $a3, 0x2($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X2);
    // 0x80801A2C: jal         0x80801844
    // 0x80801A30: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80801844_gcnewpause(rdram, ctx);
        goto after_2;
    // 0x80801A30: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_2:
    // 0x80801A34: beql        $v0, $zero, L_80801A44
    if (ctx->r2 == 0) {
        // 0x80801A38: lh          $a0, 0x6($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X6);
            goto L_80801A44;
    }
    goto skip_0;
    // 0x80801A38: lh          $a0, 0x6($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X6);
    skip_0:
    // 0x80801A3C: or          $s5, $s6, $zero
    ctx->r21 = ctx->r22 | 0;
L_80801A40:
    // 0x80801A40: lh          $a0, 0x6($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X6);
L_80801A44:
    // 0x80801A44: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x80801A48: bne         $s4, $a0, L_808019F4
    if (ctx->r20 != ctx->r4) {
        // 0x80801A4C: nop
    
            goto L_808019F4;
    }
    // 0x80801A4C: nop

L_80801A50:
    // 0x80801A50: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80801A54: jal         0x800DADEC
    // 0x80801A58: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800DADEC(rdram, ctx);
        goto after_3;
    // 0x80801A58: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x80801A5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801A60: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x80801A64: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80801A68: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80801A6C: jal         0x8080190C
    // 0x80801A70: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_8080190C_gcnewpause(rdram, ctx);
        goto after_4;
    // 0x80801A70: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_4:
    // 0x80801A74: beq         $v0, $zero, L_80801A80
    if (ctx->r2 == 0) {
        // 0x80801A78: nop
    
            goto L_80801A80;
    }
    // 0x80801A78: nop

    // 0x80801A7C: or          $s5, $s6, $zero
    ctx->r21 = ctx->r22 | 0;
L_80801A80:
    // 0x80801A80: jal         0x80801C3C
    // 0x80801A84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80801C3C_gcnewpause(rdram, ctx);
        goto after_5;
    // 0x80801A84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x80801A88: bne         $s3, $s6, L_80801A98
    if (ctx->r19 != ctx->r22) {
        // 0x80801A8C: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80801A98;
    }
    // 0x80801A8C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801A90: beql        $v0, $zero, L_80801AD0
    if (ctx->r2 == 0) {
        // 0x80801A94: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80801AD0;
    }
    goto skip_1;
    // 0x80801A94: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_1:
L_80801A98:
    // 0x80801A98: jal         0x80801BF0
    // 0x80801A9C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80801BF0_gcnewpause(rdram, ctx);
        goto after_6;
    // 0x80801A9C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x80801AA0: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80801AA4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80801AA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801AAC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801AB0: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    // 0x80801AB4: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    // 0x80801AB8: jal         0x80801844
    // 0x80801ABC: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80801844_gcnewpause(rdram, ctx);
        goto after_7;
    // 0x80801ABC: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_7:
    // 0x80801AC0: beql        $v0, $zero, L_80801AD0
    if (ctx->r2 == 0) {
        // 0x80801AC4: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80801AD0;
    }
    goto skip_2;
    // 0x80801AC4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_2:
    // 0x80801AC8: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80801ACC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80801AD0:
    // 0x80801AD0: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x80801AD4: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80801AD8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801ADC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80801AE0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80801AE4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80801AE8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80801AEC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80801AF0: jr          $ra
    // 0x80801AF4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80801AF4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_808006E0_bscarry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006E8: jal         0x800839B8
    // 0x808006EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x808006EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808006F0: jal         0x808001D4
    // 0x808006F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808001D4_bscarry(rdram, ctx);
        goto after_1;
    // 0x808006F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808006F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800700: jr          $ra
    // 0x80800704: nop

    return;
    // 0x80800704: nop

;}
RECOMP_FUNC void _badust_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800849C8: syscall     125
    recomp_syscall_handler(rdram, ctx, 0x800849C8);
    return;
    // 0x800849CC: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void subaddiefade_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000BC: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x808000C0: sll         $t8, $t6, 27
    ctx->r24 = S32(ctx->r14 << 27);
    // 0x808000C4: bgezl       $t8, L_808001F0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808000C8: lhu         $v0, 0x78($a0)
        ctx->r2 = MEM_HU(ctx->r4, 0X78);
            goto L_808001F0;
    }
    goto skip_0;
    // 0x808000C8: lhu         $v0, 0x78($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X78);
    skip_0:
    // 0x808000CC: jal         0x800D8FF8
    // 0x808000D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808000D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000D8: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x808000DC: lwc1        $f2, 0x18($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X18);
    // 0x808000E0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x808000E4: swc1        $f6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f6.u32l;
    // 0x808000E8: lwc1        $f8, 0x1C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x808000EC: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x808000F0: nop

    // 0x808000F4: bc1fl       L_80800104
    if (!c1cs) {
        // 0x808000F8: lhu         $v0, 0x78($a0)
        ctx->r2 = MEM_HU(ctx->r4, 0X78);
            goto L_80800104;
    }
    goto skip_1;
    // 0x808000F8: lhu         $v0, 0x78($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X78);
    skip_1:
    // 0x808000FC: swc1        $f2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f2.u32l;
    // 0x80800100: lhu         $v0, 0x78($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X78);
L_80800104:
    // 0x80800104: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800108: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8080010C: beq         $t9, $at, L_80800124
    if (ctx->r25 == ctx->r1) {
        // 0x80800110: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800124;
    }
    // 0x80800110: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800114: beql        $t9, $at, L_80800188
    if (ctx->r25 == ctx->r1) {
        // 0x80800118: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80800188;
    }
    goto skip_2;
    // 0x80800118: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_2:
    // 0x8080011C: b           L_808002E0
    // 0x80800120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002E0;
    // 0x80800120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800124:
    // 0x80800124: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800128: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8080012C: c.eq.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl == ctx->f2.fl;
    // 0x80800130: nop

    // 0x80800134: bc1tl       L_80800164
    if (c1cs) {
        // 0x80800138: sb          $t2, 0x9B($a0)
        MEM_B(0X9B, ctx->r4) = ctx->r10;
            goto L_80800164;
    }
    goto skip_3;
    // 0x80800138: sb          $t2, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = ctx->r10;
    skip_3:
    // 0x8080013C: lwc1        $f16, 0x1C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80800140: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800144: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800148: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8080014C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800150: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800154: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x80800158: b           L_80800164
    // 0x8080015C: sb          $t1, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = ctx->r9;
        goto L_80800164;
    // 0x8080015C: sb          $t1, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = ctx->r9;
    // 0x80800160: sb          $t2, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = ctx->r10;
L_80800164:
    // 0x80800164: lbu         $t3, 0x9B($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X9B);
    // 0x80800168: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8080016C: bnel        $t3, $at, L_808002E0
    if (ctx->r11 != ctx->r1) {
        // 0x80800170: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002E0;
    }
    goto skip_4;
    // 0x80800170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80800174: lbu         $t4, 0x79($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X79);
    // 0x80800178: andi        $t5, $t4, 0xFFFC
    ctx->r13 = ctx->r12 & 0XFFFC;
    // 0x8080017C: b           L_808002DC
    // 0x80800180: sb          $t5, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r13;
        goto L_808002DC;
    // 0x80800180: sb          $t5, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r13;
    // 0x80800184: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_80800188:
    // 0x80800188: nop

    // 0x8080018C: c.eq.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl == ctx->f2.fl;
    // 0x80800190: nop

    // 0x80800194: bc1tl       L_808001D0
    if (c1cs) {
        // 0x80800198: sb          $zero, 0x9B($a0)
        MEM_B(0X9B, ctx->r4) = 0;
            goto L_808001D0;
    }
    goto skip_5;
    // 0x80800198: sb          $zero, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = 0;
    skip_5:
    // 0x8080019C: lwc1        $f16, 0x1C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x808001A0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x808001A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001A8: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x808001AC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x808001B0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808001B4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x808001B8: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x808001BC: nop

    // 0x808001C0: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x808001C4: b           L_808001D0
    // 0x808001C8: sb          $t9, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = ctx->r25;
        goto L_808001D0;
    // 0x808001C8: sb          $t9, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = ctx->r25;
    // 0x808001CC: sb          $zero, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = 0;
L_808001D0:
    // 0x808001D0: lbu         $t0, 0x9B($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X9B);
    // 0x808001D4: bnel        $t0, $zero, L_808002E0
    if (ctx->r8 != 0) {
        // 0x808001D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002E0;
    }
    goto skip_6;
    // 0x808001D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x808001DC: lbu         $t1, 0x79($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X79);
    // 0x808001E0: andi        $t2, $t1, 0xFFFC
    ctx->r10 = ctx->r9 & 0XFFFC;
    // 0x808001E4: b           L_808002DC
    // 0x808001E8: sb          $t2, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r10;
        goto L_808002DC;
    // 0x808001E8: sb          $t2, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r10;
    // 0x808001EC: lhu         $v0, 0x78($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X78);
L_808001F0:
    // 0x808001F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001F4: andi        $t3, $v0, 0x3
    ctx->r11 = ctx->r2 & 0X3;
    // 0x808001F8: beq         $t3, $at, L_80800218
    if (ctx->r11 == ctx->r1) {
        // 0x808001FC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800218;
    }
    // 0x808001FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800200: beq         $t3, $at, L_8080025C
    if (ctx->r11 == ctx->r1) {
        // 0x80800204: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080025C;
    }
    // 0x80800204: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800208: beql        $t3, $at, L_808002AC
    if (ctx->r11 == ctx->r1) {
        // 0x8080020C: lbu         $v0, 0x9B($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X9B);
            goto L_808002AC;
    }
    goto skip_7;
    // 0x8080020C: lbu         $v0, 0x9B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9B);
    skip_7:
    // 0x80800210: b           L_808002E0
    // 0x80800214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002E0;
    // 0x80800214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800218:
    // 0x80800218: lbu         $v0, 0x9B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9B);
    // 0x8080021C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80800220: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x80800224: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x80800228: bnel        $at, $zero, L_8080023C
    if (ctx->r1 != 0) {
        // 0x8080022C: sb          $v0, 0x9B($a0)
        MEM_B(0X9B, ctx->r4) = ctx->r2;
            goto L_8080023C;
    }
    goto skip_8;
    // 0x8080022C: sb          $v0, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = ctx->r2;
    skip_8:
    // 0x80800230: b           L_8080023C
    // 0x80800234: sb          $t4, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = ctx->r12;
        goto L_8080023C;
    // 0x80800234: sb          $t4, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = ctx->r12;
    // 0x80800238: sb          $v0, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = ctx->r2;
L_8080023C:
    // 0x8080023C: lbu         $t5, 0x9B($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X9B);
    // 0x80800240: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80800244: bnel        $t5, $at, L_808002E0
    if (ctx->r13 != ctx->r1) {
        // 0x80800248: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002E0;
    }
    goto skip_9;
    // 0x80800248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x8080024C: lbu         $t6, 0x79($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X79);
    // 0x80800250: andi        $t8, $t6, 0xFFFC
    ctx->r24 = ctx->r14 & 0XFFFC;
    // 0x80800254: b           L_808002DC
    // 0x80800258: sb          $t8, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r24;
        goto L_808002DC;
    // 0x80800258: sb          $t8, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r24;
L_8080025C:
    // 0x8080025C: lbu         $v0, 0x9B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9B);
    // 0x80800260: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800264: addiu       $v0, $v0, -0x7
    ctx->r2 = ADD32(ctx->r2, -0X7);
    // 0x80800268: bgezl       $v0, L_8080027C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8080026C: sb          $v0, 0x9B($a0)
        MEM_B(0X9B, ctx->r4) = ctx->r2;
            goto L_8080027C;
    }
    goto skip_10;
    // 0x8080026C: sb          $v0, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = ctx->r2;
    skip_10:
    // 0x80800270: b           L_8080027C
    // 0x80800274: sb          $zero, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = 0;
        goto L_8080027C;
    // 0x80800274: sb          $zero, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = 0;
    // 0x80800278: sb          $v0, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = ctx->r2;
L_8080027C:
    // 0x8080027C: lbu         $t7, 0x9B($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X9B);
    // 0x80800280: bnel        $t7, $zero, L_808002E0
    if (ctx->r15 != 0) {
        // 0x80800284: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002E0;
    }
    goto skip_11;
    // 0x80800284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_11:
    // 0x80800288: jal         0x80107070
    // 0x8080028C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80107070(rdram, ctx);
        goto after_1;
    // 0x8080028C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800290: bne         $v0, $zero, L_808002DC
    if (ctx->r2 != 0) {
        // 0x80800294: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808002DC;
    }
    // 0x80800294: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800298: jal         0x800FFAB0
    // 0x8080029C: nop

    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x8080029C: nop

    after_2:
    // 0x808002A0: b           L_808002E0
    // 0x808002A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002E0;
    // 0x808002A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002A8: lbu         $v0, 0x9B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9B);
L_808002AC:
    // 0x808002AC: addiu       $v0, $v0, -0x7
    ctx->r2 = ADD32(ctx->r2, -0X7);
    // 0x808002B0: bgezl       $v0, L_808002C4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x808002B4: sb          $v0, 0x9B($a0)
        MEM_B(0X9B, ctx->r4) = ctx->r2;
            goto L_808002C4;
    }
    goto skip_12;
    // 0x808002B4: sb          $v0, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = ctx->r2;
    skip_12:
    // 0x808002B8: b           L_808002C4
    // 0x808002BC: sb          $zero, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = 0;
        goto L_808002C4;
    // 0x808002BC: sb          $zero, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = 0;
    // 0x808002C0: sb          $v0, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = ctx->r2;
L_808002C4:
    // 0x808002C4: lbu         $t9, 0x9B($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X9B);
    // 0x808002C8: bnel        $t9, $zero, L_808002E0
    if (ctx->r25 != 0) {
        // 0x808002CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002E0;
    }
    goto skip_13;
    // 0x808002CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_13:
    // 0x808002D0: lbu         $t0, 0x79($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X79);
    // 0x808002D4: andi        $t1, $t0, 0xFFFC
    ctx->r9 = ctx->r8 & 0XFFFC;
    // 0x808002D8: sb          $t1, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r9;
L_808002DC:
    // 0x808002DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002E0:
    // 0x808002E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002E4: jr          $ra
    // 0x808002E8: nop

    return;
    // 0x808002E8: nop

;}
RECOMP_FUNC void _chswitch_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085800: syscall     176
    recomp_syscall_handler(rdram, ctx, 0x80085800);
    return;
    // 0x80085804: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80802798_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802798: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080279C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808027A0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x808027A4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1240, 0X3C74) << 16);
    // 0x808027A8: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x808027AC: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x808027B0: addiu       $a2, $a2, 0x3C74
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1240, 0X3C74));
    // 0x808027B4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x808027B8: jal         0x80089D20
    // 0x808027BC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808027BC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x808027C0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1240, 0X3C6C) << 16);
    // 0x808027C4: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x808027C8: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808027CC: addiu       $a2, $a2, 0x3C6C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1240, 0X3C6C));
    // 0x808027D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808027D4: jal         0x80089D20
    // 0x808027D8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808027D8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808027DC: beq         $v0, $zero, L_80802854
    if (ctx->r2 == 0) {
        // 0x808027E0: addiu       $a0, $sp, 0x24
        ctx->r4 = ADD32(ctx->r29, 0X24);
            goto L_80802854;
    }
    // 0x808027E0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808027E4: jal         0x800EE7F8
    // 0x808027E8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808027E8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808027EC: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808027F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808027F4: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808027F8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x808027FC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80802800: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80802804: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80802808: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8080280C: addiu       $a0, $a0, 0x6D78
    ctx->r4 = ADD32(ctx->r4, 0X6D78);
    // 0x80802810: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80802814: lw          $t8, 0x48($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X48);
    // 0x80802818: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8080281C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80802820: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80802824: jal         0x80086D50
    // 0x80802828: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    _chbaddiesetup_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x80802828: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_3:
    // 0x8080282C: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80802830: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80802834: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802838: jal         0x80018820
    // 0x8080283C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80018820(rdram, ctx);
        goto after_4;
    // 0x8080283C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_4:
    // 0x80802840: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80802844: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80802848: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080284C: jal         0x800E15CC
    // 0x80802850: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    func_800E15CC(rdram, ctx);
        goto after_5;
    // 0x80802850: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_5:
L_80802854:
    // 0x80802854: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802858: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080285C: jr          $ra
    // 0x80802860: nop

    return;
    // 0x80802860: nop

;}
RECOMP_FUNC void func_800CC5F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC5F4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800CC5F8: lw          $t7, -0x517C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X517C);
    // 0x800CC5FC: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800CC600: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800CC604: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800CC608: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800CC60C: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800CC610: srl         $t9, $v0, 9
    ctx->r25 = S32(U32(ctx->r2) >> 9);
    // 0x800CC614: jr          $ra
    // 0x800CC618: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    return;
    // 0x800CC618: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
;}
