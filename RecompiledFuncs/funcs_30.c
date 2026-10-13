#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8001210C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001210C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80012110: lw          $t6, 0x59C8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X59C8);
    // 0x80012114: jr          $ra
    // 0x80012118: and         $v0, $t6, $a0
    ctx->r2 = ctx->r14 & ctx->r4;
    return;
    // 0x80012118: and         $v0, $t6, $a0
    ctx->r2 = ctx->r14 & ctx->r4;
;}
RECOMP_FUNC void boot___osPopThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8080045C_chdiggerbossshell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080045C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800460: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800464: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800468: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x8080046C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800470: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800474: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800478: bne         $t7, $at, L_808004B4
    if (ctx->r15 != ctx->r1) {
        // 0x8080047C: lui         $a1, 0x40
        ctx->r5 = S32(0X40 << 16);
            goto L_808004B4;
    }
    // 0x8080047C: lui         $a1, 0x40
    ctx->r5 = S32(0X40 << 16);
    // 0x80800480: jal         0x8010B990
    // 0x80800484: ori         $a1, $a1, 0x5
    ctx->r5 = ctx->r5 | 0X5;
    func_8010B990(rdram, ctx);
        goto after_0;
    // 0x80800484: ori         $a1, $a1, 0x5
    ctx->r5 = ctx->r5 | 0X5;
    after_0:
    // 0x80800488: andi        $t8, $v0, 0x20
    ctx->r24 = ctx->r2 & 0X20;
    // 0x8080048C: beq         $t8, $zero, L_8080049C
    if (ctx->r24 == 0) {
        // 0x80800490: nop
    
            goto L_8080049C;
    }
    // 0x80800490: nop

    // 0x80800494: jal         0x80800504
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800504_chdiggerbossshell(rdram, ctx);
        goto after_1;
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_8080049C:
    // 0x8080049C: jal         0x800D9078
    // 0x808004A0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_2;
    // 0x808004A0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_2:
    // 0x808004A4: beql        $v0, $zero, L_808004B8
    if (ctx->r2 == 0) {
        // 0x808004A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808004B8;
    }
    goto skip_0;
    // 0x808004A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808004AC: jal         0x80089CA8
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_808004B4:
    // 0x808004B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004B8:
    // 0x808004B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004C0: jr          $ra
    // 0x808004C4: nop

    return;
    // 0x808004C4: nop

;}
RECOMP_FUNC void func_80800824_chcheato(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800824: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080082C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800830: jal         0x800D1A04
    // 0x80800834: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    func_800D1A04(rdram, ctx);
        goto after_0;
    // 0x80800834: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_0:
    // 0x80800838: jal         0x80800BB8
    // 0x8080083C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80800BB8_chcheato(rdram, ctx);
        goto after_1;
    // 0x8080083C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800840: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800844: bne         $v0, $at, L_80800854
    if (ctx->r2 != ctx->r1) {
        // 0x80800848: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_80800854;
    }
    // 0x80800848: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8080084C: b           L_80800878
    // 0x80800850: addiu       $v0, $zero, 0x1147
    ctx->r2 = ADD32(0, 0X1147);
        goto L_80800878;
    // 0x80800850: addiu       $v0, $zero, 0x1147
    ctx->r2 = ADD32(0, 0X1147);
L_80800854:
    // 0x80800854: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x80800858: beq         $at, $zero, L_80800878
    if (ctx->r1 == 0) {
        // 0x8080085C: addiu       $v0, $zero, 0x1144
        ctx->r2 = ADD32(0, 0X1144);
            goto L_80800878;
    }
    // 0x8080085C: addiu       $v0, $zero, 0x1144
    ctx->r2 = ADD32(0, 0X1144);
    // 0x80800860: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80800864: addiu       $v0, $zero, 0x1145
    ctx->r2 = ADD32(0, 0X1145);
    // 0x80800868: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8080086C: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80800870: b           L_80800878
    // 0x80800874: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
        goto L_80800878;
    // 0x80800874: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_80800878:
    // 0x80800878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080087C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800880: jr          $ra
    // 0x80800884: nop

    return;
    // 0x80800884: nop

;}
RECOMP_FUNC void func_80806170_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806170: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80806174: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80806178: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080617C: jal         0x80802458
    // 0x80806180: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_80802458_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80806180: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80806184: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80806188: lwc1        $f4, 0x2C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8080618C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80806190: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80806194: jal         0x800F0DC0
    // 0x80806198: div.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    func_800F0DC0(rdram, ctx);
        goto after_1;
    // 0x80806198: div.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    after_1:
    // 0x8080619C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808061A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808061A4: jr          $ra
    // 0x808061A8: nop

    return;
    // 0x808061A8: nop

;}
RECOMP_FUNC void _chgameselect_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085BB0: syscall     205
    recomp_syscall_handler(rdram, ctx, 0x80085BB0);
    return;
    // 0x80085BB4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void suexpression_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B34: jr          $ra
    // 0x80800B38: sh          $a1, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r5;
    return;
    // 0x80800B38: sh          $a1, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void bamoveledge_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080001C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800024: jal         0x8009BC08
    // 0x80800028: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_8009BC08(rdram, ctx);
        goto after_0;
    // 0x80800028: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8080002C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800030: jal         0x8009BB24
    // 0x80800034: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009BB24(rdram, ctx);
        goto after_1;
    // 0x80800034: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x80800038: jal         0x800D8FF8
    // 0x8080003C: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x8080003C: nop

    after_2:
    // 0x80800040: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800044: jal         0x800EF334
    // 0x80800048: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800EF334(rdram, ctx);
        goto after_3;
    // 0x80800048: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x8080004C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80800050: jal         0x800EF04C
    // 0x80800054: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800EF04C(rdram, ctx);
        goto after_4;
    // 0x80800054: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x80800058: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080005C: jal         0x8009B98C
    // 0x80800060: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_8009B98C(rdram, ctx);
        goto after_5;
    // 0x80800060: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_5:
    // 0x80800064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800068: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080006C: jr          $ra
    // 0x80800070: nop

    return;
    // 0x80800070: nop

    // 0x80800074: nop

    // 0x80800078: nop

    // 0x8080007C: nop

;}
RECOMP_FUNC void func_80800038_bsstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800038: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080003C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800040: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800044: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800048: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080004C: jal         0x8009EF10
    // 0x80800050: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    bastick_getZone(rdram, ctx);
        goto after_0;
    // 0x80800050: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    after_0:
    // 0x80800054: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800058: beq         $v0, $at, L_80800084
    if (ctx->r2 == ctx->r1) {
        // 0x8080005C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800084;
    }
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800060: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800064: beq         $v0, $at, L_8080008C
    if (ctx->r2 == ctx->r1) {
        // 0x80800068: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080008C;
    }
    // 0x80800068: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080006C: beq         $v0, $at, L_80800094
    if (ctx->r2 == ctx->r1) {
        // 0x80800070: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800094;
    }
    // 0x80800070: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800074: beql        $v0, $at, L_808000A0
    if (ctx->r2 == ctx->r1) {
        // 0x80800078: addiu       $s1, $zero, 0x4
        ctx->r17 = ADD32(0, 0X4);
            goto L_808000A0;
    }
    goto skip_0;
    // 0x80800078: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    skip_0:
    // 0x8080007C: b           L_808000A0
    // 0x80800080: nop

        goto L_808000A0;
    // 0x80800080: nop

L_80800084:
    // 0x80800084: b           L_808000A0
    // 0x80800088: addiu       $s1, $zero, 0x1F
    ctx->r17 = ADD32(0, 0X1F);
        goto L_808000A0;
    // 0x80800088: addiu       $s1, $zero, 0x1F
    ctx->r17 = ADD32(0, 0X1F);
L_8080008C:
    // 0x8080008C: b           L_808000A0
    // 0x80800090: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_808000A0;
    // 0x80800090: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80800094:
    // 0x80800094: b           L_808000A0
    // 0x80800098: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
        goto L_808000A0;
    // 0x80800098: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x8080009C: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_808000A0:
    // 0x808000A0: jal         0x800919F4
    // 0x808000A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_1;
    // 0x808000A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808000A8: beq         $v0, $zero, L_808000B4
    if (ctx->r2 == 0) {
        // 0x808000AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000B4;
    }
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B0: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
L_808000B4:
    // 0x808000B4: jal         0x80091A58
    // 0x808000B8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_2;
    // 0x808000B8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_2:
    // 0x808000BC: beq         $v0, $zero, L_808000D0
    if (ctx->r2 == 0) {
        // 0x808000C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000D0;
    }
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: jal         0x800A055C
    // 0x808000C8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800A055C(rdram, ctx);
        goto after_3;
    // 0x808000C8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x808000CC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_808000D0:
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D4: jal         0x80091A58
    // 0x808000D8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_4;
    // 0x808000D8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_4:
    // 0x808000DC: beq         $v0, $zero, L_80800128
    if (ctx->r2 == 0) {
        // 0x808000E0: nop
    
            goto L_80800128;
    }
    // 0x808000E0: nop

    // 0x808000E4: jal         0x8009FE84
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getTypeOfJump(rdram, ctx);
        goto after_5;
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000EC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808000F0: jal         0x8008D714
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D714(rdram, ctx);
        goto after_6;
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808000F8: beq         $v0, $zero, L_80800108
    if (ctx->r2 == 0) {
        // 0x808000FC: nop
    
            goto L_80800108;
    }
    // 0x808000FC: nop

    // 0x80800100: b           L_80800128
    // 0x80800104: addiu       $s1, $zero, 0xB8
    ctx->r17 = ADD32(0, 0XB8);
        goto L_80800128;
    // 0x80800104: addiu       $s1, $zero, 0xB8
    ctx->r17 = ADD32(0, 0XB8);
L_80800108:
    // 0x80800108: jal         0x8008D790
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D790(rdram, ctx);
        goto after_7;
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800110: beq         $v0, $zero, L_80800128
    if (ctx->r2 == 0) {
        // 0x80800114: nop
    
            goto L_80800128;
    }
    // 0x80800114: nop

    // 0x80800118: jal         0x80084978
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baduo_entrypoint_12(rdram, ctx);
        goto after_8;
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800120: b           L_8080017C
    // 0x80800124: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080017C;
    // 0x80800124: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800128:
    // 0x80800128: jal         0x80097AD0
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_9;
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800130: beq         $v0, $zero, L_80800144
    if (ctx->r2 == 0) {
        // 0x80800134: nop
    
            goto L_80800144;
    }
    // 0x80800134: nop

    // 0x80800138: jal         0x800848A8
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_24(rdram, ctx);
        goto after_10;
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800140: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80800144:
    // 0x80800144: jal         0x8008E148
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_11;
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080014C: beq         $v0, $zero, L_80800160
    if (ctx->r2 == 0) {
        // 0x80800150: nop
    
            goto L_80800160;
    }
    // 0x80800150: nop

    // 0x80800154: jal         0x800848B0
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_12;
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080015C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80800160:
    // 0x80800160: jal         0x8008E35C
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_13;
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800168: beq         $v0, $zero, L_80800174
    if (ctx->r2 == 0) {
        // 0x8080016C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800174;
    }
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800170: addiu       $s1, $zero, 0x2D
    ctx->r17 = ADD32(0, 0X2D);
L_80800174:
    // 0x80800174: jal         0x800A02DC
    // 0x80800178: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800A02DC(rdram, ctx);
        goto after_14;
    // 0x80800178: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_14:
L_8080017C:
    // 0x8080017C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800180: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800184: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800188: jr          $ra
    // 0x8080018C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8080018C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _chbeanstalkseed_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087618: syscall     597
    recomp_syscall_handler(rdram, ctx, 0x80087618);
    return;
    // 0x8008761C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808004DC_chbubbleelevator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004DC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808004E0: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x808004E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004E8: sltiu       $at, $t7, 0x9
    ctx->r1 = ctx->r15 < 0X9 ? 1 : 0;
    // 0x808004EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004F4: beq         $at, $zero, L_80800888
    if (ctx->r1 == 0) {
        // 0x808004F8: sw          $a1, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r5;
            goto L_80800888;
    }
    // 0x808004F8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x808004FC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800500: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2368, 0XBF4) << 16);
    // 0x80800504: addu        $at, $at, $t7
    gpr jr_addend_8080050C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800508: lw          $t7, 0xBF4($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2368, 0XBF4));
    // 0x8080050C: jr          $t7
    // 0x80800510: nop

    switch (jr_addend_8080050C >> 2) {
        case 0: goto L_80800514; break;
        case 1: goto L_80800888; break;
        case 2: goto L_80800620; break;
        case 3: goto L_808006A8; break;
        case 4: goto L_808006E0; break;
        case 5: goto L_80800720; break;
        case 6: goto L_808007EC; break;
        case 7: goto L_80800830; break;
        case 8: goto L_80800844; break;
        default: switch_error(__func__, 0x8080050C, 0x80800BF4);
    }
    // 0x80800510: nop

L_80800514:
    // 0x80800514: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800518: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080051C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800520: jal         0x808008A8
    // 0x80800524: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_808008A8_chbubbleelevator(rdram, ctx);
        goto after_0;
    // 0x80800524: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_0:
    // 0x80800528: jal         0x800F54E4
    // 0x8080052C: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x8080052C: nop

    after_1:
    // 0x80800530: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800534: jal         0x800F7B9C
    // 0x80800538: addiu       $a1, $zero, 0x7C
    ctx->r5 = ADD32(0, 0X7C);
    func_800F7B9C(rdram, ctx);
        goto after_2;
    // 0x80800538: addiu       $a1, $zero, 0x7C
    ctx->r5 = ADD32(0, 0X7C);
    after_2:
    // 0x8080053C: jal         0x800F54E4
    // 0x80800540: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x80800540: nop

    after_3:
    // 0x80800544: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80800548: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8080054C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800550: jal         0x800F8294
    // 0x80800554: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F8294(rdram, ctx);
        goto after_4;
    // 0x80800554: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80800558: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080055C: jal         0x800F1DF4
    // 0x80800560: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_800F1DF4(rdram, ctx);
        goto after_5;
    // 0x80800560: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_5:
    // 0x80800564: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800568: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080056C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800570: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800574: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800578: jal         0x800EFA4C
    // 0x8080057C: nop

    func_800EFA4C(rdram, ctx);
        goto after_6;
    // 0x8080057C: nop

    after_6:
    // 0x80800580: jal         0x800F54E4
    // 0x80800584: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x80800584: nop

    after_7:
    // 0x80800588: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080058C: jal         0x800F832C
    // 0x80800590: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F832C(rdram, ctx);
        goto after_8;
    // 0x80800590: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_8:
    // 0x80800594: jal         0x800F54E4
    // 0x80800598: nop

    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x80800598: nop

    after_9:
    // 0x8080059C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005A0: jal         0x800F80E4
    // 0x808005A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F80E4(rdram, ctx);
        goto after_10;
    // 0x808005A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x808005A8: lbu         $t8, 0x79($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X79);
    // 0x808005AC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808005B0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2368, 0XC20) << 16);
    // 0x808005B4: srl         $t9, $t8, 4
    ctx->r25 = S32(U32(ctx->r24) >> 4);
    // 0x808005B8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x808005BC: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x808005C0: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x808005C4: addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    // 0x808005C8: lbu         $a2, 0xC20($a2)
    ctx->r6 = MEM_BU(ctx->r6, (int16_t)RELOC_LO16(2368, 0XC20));
    // 0x808005CC: addiu       $a3, $zero, 0x2001
    ctx->r7 = ADD32(0, 0X2001);
    // 0x808005D0: jal         0x80085708
    // 0x808005D4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    _capod_entrypoint_13(rdram, ctx);
        goto after_11;
    // 0x808005D4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_11:
    // 0x808005D8: jal         0x80015184
    // 0x808005DC: nop

    func_80015184(rdram, ctx);
        goto after_12;
    // 0x808005DC: nop

    after_12:
    // 0x808005E0: lhu         $t3, 0x6E($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X6E);
    // 0x808005E4: andi        $t2, $v0, 0x1FF
    ctx->r10 = ctx->r2 & 0X1FF;
    // 0x808005E8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808005EC: andi        $t4, $t3, 0xFE00
    ctx->r12 = ctx->r11 & 0XFE00;
    // 0x808005F0: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x808005F4: jal         0x80015178
    // 0x808005F8: sh          $t5, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r13;
    func_80015178(rdram, ctx);
        goto after_13;
    // 0x808005F8: sh          $t5, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r13;
    after_13:
    // 0x808005FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800604: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800608: jal         0x8008A4B0
    // 0x8080060C: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_14;
    // 0x8080060C: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    after_14:
    // 0x80800610: jal         0x800FC6B0
    // 0x80800614: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    func_800FC6B0(rdram, ctx);
        goto after_15;
    // 0x80800614: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_15:
    // 0x80800618: b           L_8080088C
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080088C;
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800620:
    // 0x80800620: lui         $a0, 0x665F
    ctx->r4 = S32(0X665F << 16);
    // 0x80800624: jal         0x800C3F48
    // 0x80800628: ori         $a0, $a0, 0x44B1
    ctx->r4 = ctx->r4 | 0X44B1;
    func_800C3F48(rdram, ctx);
        goto after_16;
    // 0x80800628: ori         $a0, $a0, 0x44B1
    ctx->r4 = ctx->r4 | 0X44B1;
    after_16:
    // 0x8080062C: jal         0x800DA524
    // 0x80800630: addiu       $a0, $zero, 0x6CA
    ctx->r4 = ADD32(0, 0X6CA);
    func_800DA524(rdram, ctx);
        goto after_17;
    // 0x80800630: addiu       $a0, $zero, 0x6CA
    ctx->r4 = ADD32(0, 0X6CA);
    after_17:
    // 0x80800634: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080063C: jal         0x808008A8
    // 0x80800640: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    func_808008A8_chbubbleelevator(rdram, ctx);
        goto after_18;
    // 0x80800640: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    after_18:
    // 0x80800644: jal         0x800F54E4
    // 0x80800648: nop

    func_800F54E4(rdram, ctx);
        goto after_19;
    // 0x80800648: nop

    after_19:
    // 0x8080064C: lui         $a3, 0xC4BB
    ctx->r7 = S32(0XC4BB << 16);
    // 0x80800650: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x80800654: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800658: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x8080065C: jal         0x800F78EC
    // 0x80800660: lui         $a2, 0x4452
    ctx->r6 = S32(0X4452 << 16);
    func_800F78EC(rdram, ctx);
        goto after_20;
    // 0x80800660: lui         $a2, 0x4452
    ctx->r6 = S32(0X4452 << 16);
    after_20:
    // 0x80800664: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800668: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080066C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800670: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800678: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    // 0x8080067C: jal         0x80089D40
    // 0x80800680: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_21;
    // 0x80800680: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
    after_21:
    // 0x80800684: jal         0x800FC74C
    // 0x80800688: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    func_800FC74C(rdram, ctx);
        goto after_22;
    // 0x80800688: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_22:
    // 0x8080068C: jal         0x800F54E4
    // 0x80800690: nop

    func_800F54E4(rdram, ctx);
        goto after_23;
    // 0x80800690: nop

    after_23:
    // 0x80800694: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800698: jal         0x800F80E4
    // 0x8080069C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F80E4(rdram, ctx);
        goto after_24;
    // 0x8080069C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x808006A0: b           L_8080088C
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080088C;
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006A8:
    // 0x808006A8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808006B4: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x808006B8: jal         0x8008A4B0
    // 0x808006BC: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_25;
    // 0x808006BC: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    after_25:
    // 0x808006C0: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x808006C4: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x808006C8: beql        $t6, $zero, L_8080088C
    if (ctx->r14 == 0) {
        // 0x808006CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080088C;
    }
    goto skip_0;
    // 0x808006CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808006D0: jal         0x80015178
    // 0x808006D4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_80015178(rdram, ctx);
        goto after_26;
    // 0x808006D4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_26:
    // 0x808006D8: b           L_8080088C
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080088C;
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006E0:
    // 0x808006E0: lui         $a0, 0x7FF1
    ctx->r4 = S32(0X7FF1 << 16);
    // 0x808006E4: jal         0x800C3F48
    // 0x808006E8: ori         $a0, $a0, 0x94D5
    ctx->r4 = ctx->r4 | 0X94D5;
    func_800C3F48(rdram, ctx);
        goto after_27;
    // 0x808006E8: ori         $a0, $a0, 0x94D5
    ctx->r4 = ctx->r4 | 0X94D5;
    after_27:
    // 0x808006EC: jal         0x800F54E4
    // 0x808006F0: nop

    func_800F54E4(rdram, ctx);
        goto after_28;
    // 0x808006F0: nop

    after_28:
    // 0x808006F4: lui         $a3, 0xC4BB
    ctx->r7 = S32(0XC4BB << 16);
    // 0x808006F8: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x808006FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800700: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800704: jal         0x800F78EC
    // 0x80800708: lui         $a2, 0x4452
    ctx->r6 = S32(0X4452 << 16);
    func_800F78EC(rdram, ctx);
        goto after_29;
    // 0x80800708: lui         $a2, 0x4452
    ctx->r6 = S32(0X4452 << 16);
    after_29:
    // 0x8080070C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800710: jal         0x8008A4B0
    // 0x80800714: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_30;
    // 0x80800714: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x80800718: b           L_8080088C
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080088C;
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800720:
    // 0x80800720: lui         $a0, 0x665F
    ctx->r4 = S32(0X665F << 16);
    // 0x80800724: jal         0x800C3F48
    // 0x80800728: ori         $a0, $a0, 0x44B1
    ctx->r4 = ctx->r4 | 0X44B1;
    func_800C3F48(rdram, ctx);
        goto after_31;
    // 0x80800728: ori         $a0, $a0, 0x44B1
    ctx->r4 = ctx->r4 | 0X44B1;
    after_31:
    // 0x8080072C: jal         0x800FC6B0
    // 0x80800730: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    func_800FC6B0(rdram, ctx);
        goto after_32;
    // 0x80800730: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_32:
    // 0x80800734: jal         0x800DA544
    // 0x80800738: addiu       $a0, $zero, 0x6CA
    ctx->r4 = ADD32(0, 0X6CA);
    func_800DA544(rdram, ctx);
        goto after_33;
    // 0x80800738: addiu       $a0, $zero, 0x6CA
    ctx->r4 = ADD32(0, 0X6CA);
    after_33:
    // 0x8080073C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800744: jal         0x808008A8
    // 0x80800748: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    func_808008A8_chbubbleelevator(rdram, ctx);
        goto after_34;
    // 0x80800748: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    after_34:
    // 0x8080074C: jal         0x800F54E4
    // 0x80800750: nop

    func_800F54E4(rdram, ctx);
        goto after_35;
    // 0x80800750: nop

    after_35:
    // 0x80800754: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800758: jal         0x800F7B9C
    // 0x8080075C: addiu       $a1, $zero, 0x7C
    ctx->r5 = ADD32(0, 0X7C);
    func_800F7B9C(rdram, ctx);
        goto after_36;
    // 0x8080075C: addiu       $a1, $zero, 0x7C
    ctx->r5 = ADD32(0, 0X7C);
    after_36:
    // 0x80800760: jal         0x800F54E4
    // 0x80800764: nop

    func_800F54E4(rdram, ctx);
        goto after_37;
    // 0x80800764: nop

    after_37:
    // 0x80800768: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080076C: jal         0x800F80E4
    // 0x80800770: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F80E4(rdram, ctx);
        goto after_38;
    // 0x80800770: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_38:
    // 0x80800774: jal         0x800F54E4
    // 0x80800778: nop

    func_800F54E4(rdram, ctx);
        goto after_39;
    // 0x80800778: nop

    after_39:
    // 0x8080077C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800780: jal         0x800F8294
    // 0x80800784: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800F8294(rdram, ctx);
        goto after_40;
    // 0x80800784: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_40:
    // 0x80800788: lbu         $t7, 0x79($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X79);
    // 0x8080078C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800790: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2368, 0XC21) << 16);
    // 0x80800794: srl         $t8, $t7, 4
    ctx->r24 = S32(U32(ctx->r15) >> 4);
    // 0x80800798: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8080079C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x808007A0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x808007A4: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x808007A8: lbu         $a2, 0xC21($a2)
    ctx->r6 = MEM_BU(ctx->r6, (int16_t)RELOC_LO16(2368, 0XC21));
    // 0x808007AC: addiu       $a3, $zero, 0x4001
    ctx->r7 = ADD32(0, 0X4001);
    // 0x808007B0: jal         0x80085708
    // 0x808007B4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    _capod_entrypoint_13(rdram, ctx);
        goto after_41;
    // 0x808007B4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_41:
    // 0x808007B8: jal         0x80015184
    // 0x808007BC: nop

    func_80015184(rdram, ctx);
        goto after_42;
    // 0x808007BC: nop

    after_42:
    // 0x808007C0: lhu         $t3, 0x6E($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X6E);
    // 0x808007C4: andi        $t1, $v0, 0x1FF
    ctx->r9 = ctx->r2 & 0X1FF;
    // 0x808007C8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808007CC: andi        $t2, $t3, 0xFE00
    ctx->r10 = ctx->r11 & 0XFE00;
    // 0x808007D0: or          $t4, $t1, $t2
    ctx->r12 = ctx->r9 | ctx->r10;
    // 0x808007D4: jal         0x80015178
    // 0x808007D8: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
    func_80015178(rdram, ctx);
        goto after_43;
    // 0x808007D8: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
    after_43:
    // 0x808007DC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808007E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808007E4: b           L_80800888
    // 0x808007E8: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
        goto L_80800888;
    // 0x808007E8: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
L_808007EC:
    // 0x808007EC: lbu         $t5, 0x79($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X79);
    // 0x808007F0: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2368, 0XC20) << 16);
    // 0x808007F4: addiu       $t8, $t8, 0xC20
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2368, 0XC20));
    // 0x808007F8: srl         $t6, $t5, 4
    ctx->r14 = S32(U32(ctx->r13) >> 4);
    // 0x808007FC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800800: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80800804: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80800808: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8080080C: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x80800810: jal         0x80087A58
    // 0x80800814: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_44;
    // 0x80800814: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    after_44:
    // 0x80800818: jal         0x80089D40
    // 0x8080081C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_45;
    // 0x8080081C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x80800820: jal         0x800FC74C
    // 0x80800824: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    func_800FC74C(rdram, ctx);
        goto after_46;
    // 0x80800824: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_46:
    // 0x80800828: b           L_8080088C
    // 0x8080082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080088C;
    // 0x8080082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800830:
    // 0x80800830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800834: jal         0x80103110
    // 0x80800838: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_47;
    // 0x80800838: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_47:
    // 0x8080083C: b           L_8080088C
    // 0x80800840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080088C;
    // 0x80800840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800844:
    // 0x80800844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800848: jal         0x80103110
    // 0x8080084C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_48;
    // 0x8080084C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_48:
    // 0x80800850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800854: jal         0x8008A4B0
    // 0x80800858: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_49;
    // 0x80800858: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_49:
    // 0x8080085C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2368, 0XC18) << 16);
    // 0x80800860: lwc1        $f6, 0xC18($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2368, 0XC18));
    // 0x80800864: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800868: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080086C: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800870: lui         $a0, 0x7FFF
    ctx->r4 = S32(0X7FFF << 16);
    // 0x80800874: ori         $a0, $a0, 0x468B
    ctx->r4 = ctx->r4 | 0X468B;
    // 0x80800878: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
    // 0x8080087C: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    // 0x80800880: jal         0x800C3F48
    // 0x80800884: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
    func_800C3F48(rdram, ctx);
        goto after_50;
    // 0x80800884: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
    after_50:
L_80800888:
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080088C:
    // 0x8080088C: jal         0x80101FDC
    // 0x80800890: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80101FDC(rdram, ctx);
        goto after_51;
    // 0x80800890: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_51:
    // 0x80800894: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800898: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080089C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808008A0: jr          $ra
    // 0x808008A4: nop

    return;
    // 0x808008A4: nop

;}
RECOMP_FUNC void _chbanjoctrl_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086390: syscall     315
    recomp_syscall_handler(rdram, ctx, 0x80086390);
    return;
    // 0x80086394: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800970_chcablespark(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800970: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800974: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800978: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080097C: jal         0x800F54E4
    // 0x80800980: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800980: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800984: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800988: jal         0x800F6478
    // 0x8080098C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6478(rdram, ctx);
        goto after_1;
    // 0x8080098C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800990: bne         $v0, $zero, L_808009A0
    if (ctx->r2 != 0) {
        // 0x80800994: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_808009A0;
    }
    // 0x80800994: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800998: b           L_80800A34
    // 0x8080099C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A34;
    // 0x8080099C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808009A0:
    // 0x808009A0: jal         0x800F57F0
    // 0x808009A4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F57F0(rdram, ctx);
        goto after_2;
    // 0x808009A4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x808009A8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x808009AC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808009B0: jal         0x800EE7F8
    // 0x808009B4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x808009B4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x808009B8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808009BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808009C0: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808009C4: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808009C8: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x808009CC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808009D0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808009D4: jal         0x800EF1B8
    // 0x808009D8: nop

    func_800EF1B8(rdram, ctx);
        goto after_4;
    // 0x808009D8: nop

    after_4:
    // 0x808009DC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808009E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808009E4: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808009E8: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808009EC: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x808009F0: mul.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808009F4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808009F8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808009FC: jal         0x800F0008
    // 0x80800A00: nop

    func_800F0008(rdram, ctx);
        goto after_5;
    // 0x80800A00: nop

    after_5:
    // 0x80800A04: beq         $v0, $zero, L_80800A30
    if (ctx->r2 == 0) {
        // 0x80800A08: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80800A30;
    }
    // 0x80800A08: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800A0C: jal         0x800F7B9C
    // 0x80800A10: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    func_800F7B9C(rdram, ctx);
        goto after_6;
    // 0x80800A10: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    after_6:
    // 0x80800A14: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A18: bne         $v0, $at, L_80800A30
    if (ctx->r2 != ctx->r1) {
        // 0x80800A1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A30;
    }
    // 0x80800A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A20: jal         0x800862B8
    // 0x80800A24: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _chelectricfence_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80800A24: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_7:
    // 0x80800A28: b           L_80800A34
    // 0x80800A2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A34;
    // 0x80800A2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A30:
    // 0x80800A30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A34:
    // 0x80800A34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A3C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800A40: jr          $ra
    // 0x80800A44: nop

    return;
    // 0x80800A44: nop

;}
RECOMP_FUNC void func_80800DC8_gcmapsects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800DCC: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x80800DD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800DD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800DD8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800DDC: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x80800DE0: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x80800DE4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80800DE8: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x80800DEC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80800DF0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800DF4: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x80800DF8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800DFC: lw          $a1, 0x30($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X30);
    // 0x80800E00: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80800E04: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80800E08: jal         0x800EFFB4
    // 0x80800E0C: addiu       $a0, $v0, 0x24
    ctx->r4 = ADD32(ctx->r2, 0X24);
    func_800EFFB4(rdram, ctx);
        goto after_0;
    // 0x80800E0C: addiu       $a0, $v0, 0x24
    ctx->r4 = ADD32(ctx->r2, 0X24);
    after_0:
    // 0x80800E10: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80800E14: beq         $v0, $zero, L_80800F64
    if (ctx->r2 == 0) {
        // 0x80800E18: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_80800F64;
    }
    // 0x80800E18: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80800E1C: lw          $t7, 0x68($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X68);
    // 0x80800E20: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80800E24: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80800E28: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x80800E2C: addiu       $a0, $v0, 0xC
    ctx->r4 = ADD32(ctx->r2, 0XC);
    // 0x80800E30: addiu       $a1, $v0, 0x18
    ctx->r5 = ADD32(ctx->r2, 0X18);
    // 0x80800E34: jal         0x800EFED0
    // 0x80800E38: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_800EFED0(rdram, ctx);
        goto after_1;
    // 0x80800E38: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80800E3C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80800E40: beq         $v0, $zero, L_80800F64
    if (ctx->r2 == 0) {
        // 0x80800E44: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_80800F64;
    }
    // 0x80800E44: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80800E48: lw          $t8, 0x68($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X68);
    // 0x80800E4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800E50: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80800E54: addu        $v0, $t8, $v1
    ctx->r2 = ADD32(ctx->r24, ctx->r3);
    // 0x80800E58: lbu         $t2, 0x4C($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X4C);
    // 0x80800E5C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80800E60: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    // 0x80800E64: ori         $t3, $t2, 0x80
    ctx->r11 = ctx->r10 | 0X80;
    // 0x80800E68: sb          $t3, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r11;
    // 0x80800E6C: lw          $t4, 0x68($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X68);
    // 0x80800E70: addu        $v0, $t4, $v1
    ctx->r2 = ADD32(ctx->r12, ctx->r3);
    // 0x80800E74: lbu         $t6, 0x4C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4C);
    // 0x80800E78: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x80800E7C: sb          $t7, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r15;
    // 0x80800E80: lw          $t8, 0x68($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X68);
    // 0x80800E84: addu        $v0, $t8, $v1
    ctx->r2 = ADD32(ctx->r24, ctx->r3);
    // 0x80800E88: lbu         $t2, 0x4C($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X4C);
    // 0x80800E8C: ori         $t3, $t2, 0x40
    ctx->r11 = ctx->r10 | 0X40;
    // 0x80800E90: sb          $t3, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r11;
    // 0x80800E94: lw          $t4, 0x68($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X68);
    // 0x80800E98: addu        $v0, $t4, $v1
    ctx->r2 = ADD32(ctx->r12, ctx->r3);
    // 0x80800E9C: lw          $t5, 0x4C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4C);
    // 0x80800EA0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80800EA4: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x80800EA8: bgezl       $t7, L_80800EC4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800EAC: lbu         $t2, 0x4C($v0)
        ctx->r10 = MEM_BU(ctx->r2, 0X4C);
            goto L_80800EC4;
    }
    goto skip_0;
    // 0x80800EAC: lbu         $t2, 0x4C($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X4C);
    skip_0:
    // 0x80800EB0: lw          $t9, 0x68($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X68);
    // 0x80800EB4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800EB8: sb          $t8, 0x7B($a3)
    MEM_B(0X7B, ctx->r7) = ctx->r24;
    // 0x80800EBC: addu        $v0, $t9, $v1
    ctx->r2 = ADD32(ctx->r25, ctx->r3);
    // 0x80800EC0: lbu         $t2, 0x4C($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X4C);
L_80800EC4:
    // 0x80800EC4: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80800EC8: beq         $t3, $zero, L_80800ED4
    if (ctx->r11 == 0) {
        // 0x80800ECC: nop
    
            goto L_80800ED4;
    }
    // 0x80800ECC: nop

    // 0x80800ED0: sb          $t4, 0x7E($a3)
    MEM_B(0X7E, ctx->r7) = ctx->r12;
L_80800ED4:
    // 0x80800ED4: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x80800ED8: subu        $t5, $t5, $s0
    ctx->r13 = SUB32(ctx->r13, ctx->r16);
    // 0x80800EDC: lw          $v1, 0x68($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X68);
    // 0x80800EE0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80800EE4: subu        $t5, $t5, $s0
    ctx->r13 = SUB32(ctx->r13, ctx->r16);
    // 0x80800EE8: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80800EEC: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x80800EF0: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80800EF4: lbu         $a1, 0x38($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X38);
    // 0x80800EF8: beq         $t0, $a1, L_80800F5C
    if (ctx->r8 == ctx->r5) {
        // 0x80800EFC: nop
    
            goto L_80800F5C;
    }
    // 0x80800EFC: nop

    // 0x80800F00: multu       $a1, $a2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800F04: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80800F08: subu        $t4, $t4, $s0
    ctx->r12 = SUB32(ctx->r12, ctx->r16);
    // 0x80800F0C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80800F10: subu        $t4, $t4, $s0
    ctx->r12 = SUB32(ctx->r12, ctx->r16);
    // 0x80800F14: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80800F18: mflo        $t8
    ctx->r24 = lo;
    // 0x80800F1C: addu        $v0, $v1, $t8
    ctx->r2 = ADD32(ctx->r3, ctx->r24);
    // 0x80800F20: lbu         $t2, 0x4C($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X4C);
    // 0x80800F24: ori         $t3, $t2, 0x80
    ctx->r11 = ctx->r10 | 0X80;
    // 0x80800F28: sb          $t3, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r11;
    // 0x80800F2C: lw          $v1, 0x68($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X68);
    // 0x80800F30: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x80800F34: addu        $t6, $t5, $a0
    ctx->r14 = ADD32(ctx->r13, ctx->r4);
    // 0x80800F38: lbu         $t7, 0x38($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X38);
    // 0x80800F3C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800F40: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800F44: mflo        $t8
    ctx->r24 = lo;
    // 0x80800F48: addu        $v0, $v1, $t8
    ctx->r2 = ADD32(ctx->r3, ctx->r24);
    // 0x80800F4C: lbu         $t2, 0x4C($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X4C);
    // 0x80800F50: ori         $t3, $t2, 0x20
    ctx->r11 = ctx->r10 | 0X20;
    // 0x80800F54: bne         $a0, $t1, L_80800ED4
    if (ctx->r4 != ctx->r9) {
        // 0x80800F58: sb          $t3, 0x4C($v0)
        MEM_B(0X4C, ctx->r2) = ctx->r11;
            goto L_80800ED4;
    }
    // 0x80800F58: sb          $t3, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r11;
L_80800F5C:
    // 0x80800F5C: b           L_80800F68
    // 0x80800F60: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80800F68;
    // 0x80800F60: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80800F64:
    // 0x80800F64: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800F68:
    // 0x80800F68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F6C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800F70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800F74: jr          $ra
    // 0x80800F78: nop

    return;
    // 0x80800F78: nop

;}
RECOMP_FUNC void func_8080010C_chlagoonlockerdoorhits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080010C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800110: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800114: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800118: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080011C: bne         $a1, $at, L_80800184
    if (ctx->r5 != ctx->r1) {
        // 0x80800120: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80800184;
    }
    // 0x80800120: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800124: addiu       $a0, $zero, 0x3A8
    ctx->r4 = ADD32(0, 0X3A8);
    // 0x80800128: jal         0x800DA3B8
    // 0x8080012C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA3B8(rdram, ctx);
        goto after_0;
    // 0x8080012C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800130: jal         0x800FFAB0
    // 0x80800134: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800134: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800138: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080013C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2032, 0X3CC) << 16);
    // 0x80800140: addiu       $a1, $a1, 0x3CC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2032, 0X3CC));
    // 0x80800144: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800148: jal         0x800C4AF0
    // 0x8080014C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_800C4AF0(rdram, ctx);
        goto after_2;
    // 0x8080014C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_2:
    // 0x80800150: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800154: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800158: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2032, 0X3A0) << 16);
    // 0x8080015C: addiu       $t7, $t7, 0x3A0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2032, 0X3A0));
    // 0x80800160: lw          $a3, 0x38($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X38);
    // 0x80800164: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800168: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080016C: jal         0x800BABB8
    // 0x80800170: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x80800170: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_3:
    // 0x80800174: jal         0x808001B0
    // 0x80800178: nop

    func_808001B0_chlagoonlockerdoorhits(rdram, ctx);
        goto after_4;
    // 0x80800178: nop

    after_4:
    // 0x8080017C: b           L_808001A0
    // 0x80800180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001A0;
    // 0x80800180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800184:
    // 0x80800184: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800188: bne         $a1, $at, L_808001A0
    if (ctx->r5 != ctx->r1) {
        // 0x8080018C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808001A0;
    }
    // 0x8080018C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800190: jal         0x8080022C
    // 0x80800194: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8080022C_chlagoonlockerdoorhits(rdram, ctx);
        goto after_5;
    // 0x80800194: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80800198: b           L_808001A0
    // 0x8080019C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001A0;
    // 0x8080019C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001A0:
    // 0x808001A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001A8: jr          $ra
    // 0x808001AC: nop

    return;
    // 0x808001AC: nop

;}
RECOMP_FUNC void func_808005F0_chbabydino(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808005F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808005F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808005FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800600: jal         0x800EA05C
    // 0x80800604: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800604: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800608: addiu       $at, $zero, 0xEA
    ctx->r1 = ADD32(0, 0XEA);
    // 0x8080060C: beq         $v0, $at, L_80800624
    if (ctx->r2 == ctx->r1) {
        // 0x80800610: addiu       $at, $zero, 0xEC
        ctx->r1 = ADD32(0, 0XEC);
            goto L_80800624;
    }
    // 0x80800610: addiu       $at, $zero, 0xEC
    ctx->r1 = ADD32(0, 0XEC);
    // 0x80800614: beq         $v0, $at, L_80800680
    if (ctx->r2 == ctx->r1) {
        // 0x80800618: nop
    
            goto L_80800680;
    }
    // 0x80800618: nop

    // 0x8080061C: b           L_808006C4
    // 0x80800620: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006C4;
    // 0x80800620: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800624:
    // 0x80800624: jal         0x80088840
    // 0x80800628: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x80800628: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_1:
    // 0x8080062C: beq         $v0, $zero, L_808006C0
    if (ctx->r2 == 0) {
        // 0x80800630: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006C0;
    }
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800634: jal         0x80102424
    // 0x80800638: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800638: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800640: jal         0x8008A4B0
    // 0x80800644: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800644: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800648: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080064C: addiu       $t6, $zero, 0x39
    ctx->r14 = ADD32(0, 0X39);
    // 0x80800650: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800654: addiu       $a1, $zero, 0x1080
    ctx->r5 = ADD32(0, 0X1080);
    // 0x80800658: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8080065C: jal         0x8008A208
    // 0x80800660: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80800660: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80800664: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800668: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080066C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800670: jal         0x80085708
    // 0x80800674: addiu       $a3, $zero, 0x2821
    ctx->r7 = ADD32(0, 0X2821);
    _capod_entrypoint_13(rdram, ctx);
        goto after_5;
    // 0x80800674: addiu       $a3, $zero, 0x2821
    ctx->r7 = ADD32(0, 0X2821);
    after_5:
    // 0x80800678: b           L_808006C4
    // 0x8080067C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006C4;
    // 0x8080067C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800680:
    // 0x80800680: jal         0x80088840
    // 0x80800684: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_6;
    // 0x80800684: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_6:
    // 0x80800688: beq         $v0, $zero, L_808006C0
    if (ctx->r2 == 0) {
        // 0x8080068C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006C0;
    }
    // 0x8080068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800690: jal         0x80102424
    // 0x80800694: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x80800694: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080069C: jal         0x8008A4B0
    // 0x808006A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x808006A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808006A4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808006A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808006AC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x808006B0: jal         0x80085708
    // 0x808006B4: addiu       $a3, $zero, 0x2821
    ctx->r7 = ADD32(0, 0X2821);
    _capod_entrypoint_13(rdram, ctx);
        goto after_9;
    // 0x808006B4: addiu       $a3, $zero, 0x2821
    ctx->r7 = ADD32(0, 0X2821);
    after_9:
    // 0x808006B8: b           L_808006C4
    // 0x808006BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006C4;
    // 0x808006BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006C0:
    // 0x808006C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006C4:
    // 0x808006C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808006C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808006CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808006D0: jr          $ra
    // 0x808006D4: nop

    return;
    // 0x808006D4: nop

    // 0x808006D8: nop

    // 0x808006DC: nop

;}
RECOMP_FUNC void ncfixposrot_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800064: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800068: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8080006C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800070: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800074: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80800078: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080007C: jal         0x800F18FC
    // 0x80800080: addiu       $a2, $a1, 0xC
    ctx->r6 = ADD32(ctx->r5, 0XC);
    func_800F18FC(rdram, ctx);
        goto after_0;
    // 0x80800080: addiu       $a2, $a1, 0xC
    ctx->r6 = ADD32(ctx->r5, 0XC);
    after_0:
    // 0x80800084: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800088: lwc1        $f12, 0xC($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8080008C: jal         0x800136E4
    // 0x80800090: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x80800090: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_1:
    // 0x80800094: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800098: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080009C: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x808000A0: swc1        $f4, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f4.u32l;
    // 0x808000A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void func_80800000_chquizremotectrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: beq         $a1, $zero, L_80800028
    if (ctx->r5 == 0) {
        // 0x80800004: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800028;
    }
    // 0x80800004: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800008: beq         $a1, $at, L_80800050
    if (ctx->r5 == ctx->r1) {
        // 0x8080000C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800050;
    }
    // 0x8080000C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800010: beq         $a1, $at, L_80800040
    if (ctx->r5 == ctx->r1) {
        // 0x80800014: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800040;
    }
    // 0x80800014: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800018: beql        $a1, $at, L_80800054
    if (ctx->r5 == ctx->r1) {
        // 0x8080001C: lbu         $t9, 0x79($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X79);
            goto L_80800054;
    }
    goto skip_0;
    // 0x8080001C: lbu         $t9, 0x79($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X79);
    skip_0:
    // 0x80800020: b           L_80800054
    // 0x80800024: lbu         $t9, 0x79($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X79);
        goto L_80800054;
    // 0x80800024: lbu         $t9, 0x79($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X79);
L_80800028:
    // 0x80800028: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8080002C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800030: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800034: swc1        $f18, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f18.u32l;
    // 0x80800038: b           L_80800050
    // 0x8080003C: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
        goto L_80800050;
    // 0x8080003C: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
L_80800040:
    // 0x80800040: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800044: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800048: nop

    // 0x8080004C: swc1        $f8, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f8.u32l;
L_80800050:
    // 0x80800050: lbu         $t9, 0x79($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X79);
L_80800054:
    // 0x80800054: sll         $t8, $a1, 4
    ctx->r24 = S32(ctx->r5 << 4);
    // 0x80800058: andi        $t0, $t9, 0xFF0F
    ctx->r8 = ctx->r25 & 0XFF0F;
    // 0x8080005C: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800060: jr          $ra
    // 0x80800064: sb          $t1, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r9;
    return;
    // 0x80800064: sb          $t1, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void bsjump_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808005F8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(216, 0X1110) << 16);
    // 0x808005FC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800600: jr          $ra
    // 0x80800604: lw          $v0, 0x1110($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(216, 0X1110));
    return;
    // 0x80800604: lw          $v0, 0x1110($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(216, 0X1110));
;}
RECOMP_FUNC void func_808001FC_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800200: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800204: jal         0x8008D04C
    // 0x80800208: nop

    func_8008D04C(rdram, ctx);
        goto after_0;
    // 0x80800208: nop

    after_0:
    // 0x8080020C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800210: jal         0x8008B134
    // 0x80800214: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_1;
    // 0x80800214: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80800218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080021C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800220: jr          $ra
    // 0x80800224: nop

    return;
    // 0x80800224: nop

;}
RECOMP_FUNC void func_80095A08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095A08: beql        $a2, $zero, L_80095A28
    if (ctx->r6 == 0) {
        // 0x80095A0C: lw          $v0, 0x94($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X94);
            goto L_80095A28;
    }
    goto skip_0;
    // 0x80095A0C: lw          $v0, 0x94($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X94);
    skip_0:
    // 0x80095A10: lw          $v0, 0x94($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X94);
    // 0x80095A14: lw          $t6, 0x14($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14);
    // 0x80095A18: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x80095A1C: jr          $ra
    // 0x80095A20: sw          $t7, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r15;
    return;
    // 0x80095A20: sw          $t7, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r15;
    // 0x80095A24: lw          $v0, 0x94($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X94);
L_80095A28:
    // 0x80095A28: nor         $t9, $a1, $zero
    ctx->r25 = ~(ctx->r5 | 0);
    // 0x80095A2C: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
    // 0x80095A30: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x80095A34: sw          $t0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r8;
    // 0x80095A38: jr          $ra
    // 0x80095A3C: nop

    return;
    // 0x80095A3C: nop

;}
RECOMP_FUNC void func_8080024C_chpowerhutwitchy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080024C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800250: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800254: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800258: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080025C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800260: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800264: jal         0x800BEA88
    // 0x80800268: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_0;
    // 0x80800268: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8080026C: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80800270: addiu       $s0, $s0, 0x6080
    ctx->r16 = ADD32(ctx->r16, 0X6080);
    // 0x80800274: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800278: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080027C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800284: jal         0x80088660
    // 0x80800288: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800288: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    after_1:
    // 0x8080028C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800290: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800294: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800298: jal         0x80088660
    // 0x8080029C: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x8080029C: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    after_2:
    // 0x808002A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808002A8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808002AC: jal         0x80088660
    // 0x808002B0: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808002B0: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    after_3:
    // 0x808002B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002B8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x808002BC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808002C0: jal         0x80088660
    // 0x808002C4: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x808002C4: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    after_4:
    // 0x808002C8: jal         0x800BEA88
    // 0x808002CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BEA88(rdram, ctx);
        goto after_5;
    // 0x808002CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x808002D0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808002D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002DC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808002E0: jal         0x80088660
    // 0x808002E4: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x808002E4: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    after_6:
    // 0x808002E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808002F0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808002F4: jal         0x80088660
    // 0x808002F8: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x808002F8: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    after_7:
    // 0x808002FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800300: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800304: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800308: jal         0x80088660
    // 0x8080030C: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x8080030C: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    after_8:
    // 0x80800310: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800314: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800318: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080031C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800320: jr          $ra
    // 0x80800324: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800324: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_808006C4_chbouncycastle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808006C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808006CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808006D0: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808006D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808006D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006DC: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808006E0: beq         $t6, $at, L_808006F8
    if (ctx->r14 == ctx->r1) {
        // 0x808006E4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808006F8;
    }
    // 0x808006E4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808006E8: beq         $t6, $at, L_80800730
    if (ctx->r14 == ctx->r1) {
        // 0x808006EC: nop
    
            goto L_80800730;
    }
    // 0x808006EC: nop

    // 0x808006F0: b           L_80800764
    // 0x808006F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800764;
    // 0x808006F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006F8:
    // 0x808006F8: jal         0x800D9078
    // 0x808006FC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x808006FC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_0:
    // 0x80800700: beq         $v0, $zero, L_80800760
    if (ctx->r2 == 0) {
        // 0x80800704: addiu       $a0, $zero, 0x19
        ctx->r4 = ADD32(0, 0X19);
            goto L_80800760;
    }
    // 0x80800704: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x80800708: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080070C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800710: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800714: jal         0x800D1000
    // 0x80800718: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_1;
    // 0x80800718: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800720: jal         0x80101FDC
    // 0x80800724: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800724: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800728: b           L_80800764
    // 0x8080072C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800764;
    // 0x8080072C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800730:
    // 0x80800730: jal         0x800D9078
    // 0x80800734: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_3;
    // 0x80800734: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_3:
    // 0x80800738: beq         $v0, $zero, L_80800760
    if (ctx->r2 == 0) {
        // 0x8080073C: addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
            goto L_80800760;
    }
    // 0x8080073C: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80800740: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800744: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800748: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8080074C: jal         0x800D1000
    // 0x80800750: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_4;
    // 0x80800750: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80800754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800758: jal         0x80101FDC
    // 0x8080075C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x8080075C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
L_80800760:
    // 0x80800760: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800764:
    // 0x80800764: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800768: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080076C: jr          $ra
    // 0x80800770: nop

    return;
    // 0x80800770: nop

;}
RECOMP_FUNC void func_801015D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801015D0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801015D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801015D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801015DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801015E0: jal         0x801039E4
    // 0x801015E4: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_801039E4(rdram, ctx);
        goto after_0;
    // 0x801015E4: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x801015E8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x801015EC: jal         0x80103D48
    // 0x801015F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103D48(rdram, ctx);
        goto after_1;
    // 0x801015F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801015F4: jal         0x80104248
    // 0x801015F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_2;
    // 0x801015F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801015FC: beq         $v0, $zero, L_80101638
    if (ctx->r2 == 0) {
        // 0x80101600: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80101638;
    }
    // 0x80101600: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80101604: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x80101608: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x8010160C: bltz        $t8, L_80101620
    if (SIGNED(ctx->r24) < 0) {
        // 0x80101610: nop
    
            goto L_80101620;
    }
    // 0x80101610: nop

    // 0x80101614: jal         0x8008B304
    // 0x80101618: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_8008B304(rdram, ctx);
        goto after_3;
    // 0x80101618: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_3:
    // 0x8010161C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_80101620:
    // 0x80101620: jal         0x8008AEDC
    // 0x80101624: nop

    func_8008AEDC(rdram, ctx);
        goto after_4;
    // 0x80101624: nop

    after_4:
    // 0x80101628: jal         0x8008C27C
    // 0x8010162C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008C27C(rdram, ctx);
        goto after_5;
    // 0x8010162C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80101630: jal         0x800DF41C
    // 0x80101634: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF41C(rdram, ctx);
        goto after_6;
    // 0x80101634: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
L_80101638:
    // 0x80101638: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8010163C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80101640: jal         0x80089828
    // 0x80101644: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    _suexpression_entrypoint_20(rdram, ctx);
        goto after_7;
    // 0x80101644: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    after_7:
    // 0x80101648: beq         $v0, $zero, L_8010165C
    if (ctx->r2 == 0) {
        // 0x8010164C: sw          $v0, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r2;
            goto L_8010165C;
    }
    // 0x8010164C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80101650: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80101654: jal         0x80089820
    // 0x80101658: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _suexpression_entrypoint_19(rdram, ctx);
        goto after_8;
    // 0x80101658: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
L_8010165C:
    // 0x8010165C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80101660: lh          $t1, 0x10($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X10);
    // 0x80101664: beql        $t1, $zero, L_8010170C
    if (ctx->r9 == 0) {
        // 0x80101668: lw          $t8, 0x34($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X34);
            goto L_8010170C;
    }
    goto skip_0;
    // 0x80101668: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x8010166C: jal         0x80104248
    // 0x80101670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_9;
    // 0x80101670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80101674: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80101678: jal         0x800B27E0
    // 0x8010167C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800B27E0(rdram, ctx);
        goto after_10;
    // 0x8010167C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_10:
    // 0x80101680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80101684: addiu       $a1, $zero, 0x9C
    ctx->r5 = ADD32(0, 0X9C);
    // 0x80101688: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8010168C: jal         0x8010108C
    // 0x80101690: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_8010108C(rdram, ctx);
        goto after_11;
    // 0x80101690: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_11:
    // 0x80101694: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80101698: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8010169C: beq         $a0, $zero, L_801016F4
    if (ctx->r4 == 0) {
        // 0x801016A0: nop
    
            goto L_801016F4;
    }
    // 0x801016A0: nop

    // 0x801016A4: beql        $a3, $zero, L_8010170C
    if (ctx->r7 == 0) {
        // 0x801016A8: lw          $t8, 0x34($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X34);
            goto L_8010170C;
    }
    goto skip_1;
    // 0x801016A8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x801016AC: lw          $t2, 0x7C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X7C);
    // 0x801016B0: sll         $t4, $t2, 19
    ctx->r12 = S32(ctx->r10 << 19);
    // 0x801016B4: bltzl       $t4, L_801016DC
    if (SIGNED(ctx->r12) < 0) {
        // 0x801016B8: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_801016DC;
    }
    goto skip_2;
    // 0x801016B8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    skip_2:
    // 0x801016BC: jal         0x8008AEDC
    // 0x801016C0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_8008AEDC(rdram, ctx);
        goto after_12;
    // 0x801016C0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_12:
    // 0x801016C4: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x801016C8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x801016CC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x801016D0: jal         0x8008C200
    // 0x801016D4: lh          $a0, 0x10($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X10);
    func_8008C200(rdram, ctx);
        goto after_13;
    // 0x801016D4: lh          $a0, 0x10($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X10);
    after_13:
    // 0x801016D8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_801016DC:
    // 0x801016DC: jal         0x800AE080
    // 0x801016E0: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    func_800AE080(rdram, ctx);
        goto after_14;
    // 0x801016E0: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    after_14:
    // 0x801016E4: jal         0x800DF72C
    // 0x801016E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF72C(rdram, ctx);
        goto after_15;
    // 0x801016E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_15:
    // 0x801016EC: b           L_8010170C
    // 0x801016F0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
        goto L_8010170C;
    // 0x801016F0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
L_801016F4:
    // 0x801016F4: beq         $a3, $zero, L_80101708
    if (ctx->r7 == 0) {
        // 0x801016F8: lw          $t7, 0x38($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X38);
            goto L_80101708;
    }
    // 0x801016F8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x801016FC: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    // 0x80101700: jal         0x800ADD80
    // 0x80101704: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_800ADD80(rdram, ctx);
        goto after_16;
    // 0x80101704: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_16:
L_80101708:
    // 0x80101708: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
L_8010170C:
    // 0x8010170C: beq         $t8, $zero, L_8010171C
    if (ctx->r24 == 0) {
        // 0x80101710: or          $a0, $t8, $zero
        ctx->r4 = ctx->r24 | 0;
            goto L_8010171C;
    }
    // 0x80101710: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80101714: jal         0x800897E0
    // 0x80101718: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _suexpression_entrypoint_11(rdram, ctx);
        goto after_17;
    // 0x80101718: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_17:
L_8010171C:
    // 0x8010171C: jal         0x800DF410
    // 0x80101720: lbu         $a0, 0x9B($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X9B);
    func_800DF410(rdram, ctx);
        goto after_18;
    // 0x80101720: lbu         $a0, 0x9B($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X9B);
    after_18:
    // 0x80101724: lhu         $a0, 0x7A($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X7A);
    // 0x80101728: srl         $t9, $a0, 14
    ctx->r25 = S32(U32(ctx->r4) >> 14);
    // 0x8010172C: jal         0x800DF830
    // 0x80101730: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800DF830(rdram, ctx);
        goto after_19;
    // 0x80101730: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_19:
    // 0x80101734: jal         0x8008A0F0
    // 0x80101738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieskeleton_entrypoint_4(rdram, ctx);
        goto after_20;
    // 0x80101738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8010173C: jal         0x800DF738
    // 0x80101740: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF738(rdram, ctx);
        goto after_21;
    // 0x80101740: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_21:
    // 0x80101744: lbu         $t0, 0x70($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X70);
    // 0x80101748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010174C: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80101750: bne         $t1, $zero, L_80101768
    if (ctx->r9 != 0) {
        // 0x80101754: nop
    
            goto L_80101768;
    }
    // 0x80101754: nop

    // 0x80101758: lw          $t2, 0x70($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X70);
    // 0x8010175C: sll         $t4, $t2, 10
    ctx->r12 = S32(ctx->r10 << 10);
    // 0x80101760: bgezl       $t4, L_8010177C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80101764: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010177C;
    }
    goto skip_3;
    // 0x80101764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
L_80101768:
    // 0x80101768: jal         0x80103CDC
    // 0x8010176C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80103CDC(rdram, ctx);
        goto after_22;
    // 0x8010176C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_22:
    // 0x80101770: jal         0x800DF818
    // 0x80101774: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF818(rdram, ctx);
        goto after_23;
    // 0x80101774: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_23:
    // 0x80101778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8010177C:
    // 0x8010177C: jal         0x80106A98
    // 0x80101780: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80106A98(rdram, ctx);
        goto after_24;
    // 0x80101780: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_24:
    // 0x80101784: jal         0x80101934
    // 0x80101788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101934(rdram, ctx);
        goto after_25;
    // 0x80101788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x8010178C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80101790: jal         0x800D731C
    // 0x80101794: lhu         $a0, 0x14($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X14);
    func_800D731C(rdram, ctx);
        goto after_26;
    // 0x80101794: lhu         $a0, 0x14($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X14);
    after_26:
    // 0x80101798: beq         $v0, $zero, L_801017A8
    if (ctx->r2 == 0) {
        // 0x8010179C: andi        $a0, $v0, 0xFF
        ctx->r4 = ctx->r2 & 0XFF;
            goto L_801017A8;
    }
    // 0x8010179C: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x801017A0: jal         0x800DF7E8
    // 0x801017A4: nop

    func_800DF7E8(rdram, ctx);
        goto after_27;
    // 0x801017A4: nop

    after_27:
L_801017A8:
    // 0x801017A8: jal         0x80103D70
    // 0x801017AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103D70(rdram, ctx);
        goto after_28;
    // 0x801017AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x801017B0: lbu         $t7, 0x7E($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X7E);
    // 0x801017B4: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x801017B8: sb          $t8, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r24;
    // 0x801017BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801017C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801017C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801017C8: jr          $ra
    // 0x801017CC: nop

    return;
    // 0x801017CC: nop

;}
RECOMP_FUNC void func_808001C8_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808001D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001D8: jal         0x80091A58
    // 0x808001DC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x808001DC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x808001E0: beq         $v0, $zero, L_808001EC
    if (ctx->r2 == 0) {
        // 0x808001E4: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_808001EC;
    }
    // 0x808001E4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808001E8: addiu       $v1, $zero, 0x107
    ctx->r3 = ADD32(0, 0X107);
L_808001EC:
    // 0x808001EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001F0: jal         0x808014B0
    // 0x808001F4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    bstnt_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x808001F4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x808001F8: beq         $v0, $zero, L_80800204
    if (ctx->r2 == 0) {
        // 0x808001FC: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800204;
    }
    // 0x808001FC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800200: addiu       $v1, $zero, 0x10E
    ctx->r3 = ADD32(0, 0X10E);
L_80800204:
    // 0x80800204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800208: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080020C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800210: jr          $ra
    // 0x80800214: nop

    return;
    // 0x80800214: nop

;}
RECOMP_FUNC void func_80801BDC_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801BDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801BE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801BE4: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x80801BE8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801BEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801BF0: jal         0x80084AE8
    // 0x80801BF4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    _baeggcursor_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80801BF4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80801BF8: jal         0x80801D70
    // 0x80801BFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80801D70_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80801BFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80801C00: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80801C04: sw          $zero, 0xA8($t7)
    MEM_W(0XA8, ctx->r15) = 0;
    // 0x80801C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801C0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801C10: jr          $ra
    // 0x80801C14: nop

    return;
    // 0x80801C14: nop

;}
RECOMP_FUNC void ncbatarget_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800268: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080026C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800270: jal         0x800EE7F8
    // 0x80800274: lw          $a0, 0x58($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X58);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800274: lw          $a0, 0x58($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X58);
    after_0:
    // 0x80800278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080027C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800280: jr          $ra
    // 0x80800284: nop

    return;
    // 0x80800284: nop

    // 0x80800288: nop

    // 0x8080028C: nop

;}
RECOMP_FUNC void _cadbfunc_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085580: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x80085580);
    return;
    // 0x80085584: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80809234_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809234: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80809238: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080923C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80809240: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80809244: jal         0x80100094
    // 0x80809248: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80809248: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080924C: lw          $t6, 0xDC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XDC);
    // 0x80809250: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80809254: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80809258: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8080925C: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80809260: bne         $at, $zero, L_80809288
    if (ctx->r1 != 0) {
        // 0x80809264: sw          $t7, 0xDC($v0)
        MEM_W(0XDC, ctx->r2) = ctx->r15;
            goto L_80809288;
    }
    // 0x80809264: sw          $t7, 0xDC($v0)
    MEM_W(0XDC, ctx->r2) = ctx->r15;
    // 0x80809268: sll         $t0, $t7, 3
    ctx->r8 = S32(ctx->r15 << 3);
    // 0x8080926C: lui         $a0, 0x8081
    ctx->r4 = S32(RELOC_HI16(1480, 0XA1FE) << 16);
    // 0x80809270: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x80809274: jal         0x800FC74C
    // 0x80809278: lh          $a0, -0x5E02($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1480, 0XA1FE));
    func_800FC74C(rdram, ctx);
        goto after_1;
    // 0x80809278: lh          $a0, -0x5E02($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1480, 0XA1FE));
    after_1:
    // 0x8080927C: sw          $zero, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = 0;
    // 0x80809280: b           L_808092FC
    // 0x80809284: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808092FC;
    // 0x80809284: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80809288:
    // 0x80809288: lw          $t1, 0xDC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XDC);
    // 0x8080928C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0XA208) << 16);
    // 0x80809290: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x80809294: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80809298: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8080929C: lwc1        $f4, -0x5DF8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0XA208));
    // 0x808092A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808092A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808092A8: swc1        $f4, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f4.u32l;
    // 0x808092AC: lw          $a3, 0x48($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X48);
    // 0x808092B0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x808092B4: addiu       $a1, $zero, 0x91C
    ctx->r5 = ADD32(0, 0X91C);
    // 0x808092B8: addiu       $a2, $a0, 0x4
    ctx->r6 = ADD32(ctx->r4, 0X4);
    // 0x808092BC: jal         0x80086680
    // 0x808092C0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    _chexploder_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x808092C0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x808092C4: lw          $v0, 0xDC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XDC);
    // 0x808092C8: lui         $a0, 0x8081
    ctx->r4 = S32(RELOC_HI16(1480, 0XA1FE) << 16);
    // 0x808092CC: beq         $v0, $zero, L_808092E4
    if (ctx->r2 == 0) {
        // 0x808092D0: sll         $t4, $v0, 3
        ctx->r12 = S32(ctx->r2 << 3);
            goto L_808092E4;
    }
    // 0x808092D0: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    // 0x808092D4: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x808092D8: jal         0x800FC74C
    // 0x808092DC: lh          $a0, -0x5E02($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1480, 0XA1FE));
    func_800FC74C(rdram, ctx);
        goto after_3;
    // 0x808092DC: lh          $a0, -0x5E02($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1480, 0XA1FE));
    after_3:
    // 0x808092E0: lw          $v0, 0xDC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XDC);
L_808092E4:
    // 0x808092E4: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x808092E8: lui         $a0, 0x8081
    ctx->r4 = S32(RELOC_HI16(1480, 0XA206) << 16);
    // 0x808092EC: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x808092F0: jal         0x800FC6B0
    // 0x808092F4: lh          $a0, -0x5DFA($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1480, 0XA206));
    func_800FC6B0(rdram, ctx);
        goto after_4;
    // 0x808092F4: lh          $a0, -0x5DFA($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1480, 0XA206));
    after_4:
    // 0x808092F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808092FC:
    // 0x808092FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80809300: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80809304: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80809308: jr          $ra
    // 0x8080930C: nop

    return;
    // 0x8080930C: nop

;}
RECOMP_FUNC void func_80800828_subaddierouteDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800828: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8080082C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80800830: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80800834: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80800838: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8080083C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80800840: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80800844: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80800848: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8080084C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80800850: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80800854: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800858: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8080085C: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80800860: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x80800864: lw          $v0, 0x70($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X70);
    // 0x80800868: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x8080086C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800870: sll         $s1, $v0, 22
    ctx->r17 = S32(ctx->r2 << 22);
    // 0x80800874: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x80800878: addiu       $s3, $sp, 0x88
    ctx->r19 = ADD32(ctx->r29, 0X88);
    // 0x8080087C: srl         $t6, $s1, 26
    ctx->r14 = S32(U32(ctx->r17) >> 26);
    // 0x80800880: addiu       $s0, $a2, 0x4
    ctx->r16 = ADD32(ctx->r6, 0X4);
    // 0x80800884: srl         $s2, $v0, 25
    ctx->r18 = S32(U32(ctx->r2) >> 25);
    // 0x80800888: addiu       $s1, $t6, -0x1
    ctx->r17 = ADD32(ctx->r14, -0X1);
    // 0x8080088C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80800890: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800894: jal         0x800EE7F8
    // 0x80800898: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800898: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x8080089C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808008A0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808008A4: jal         0x800EEB9C
    // 0x808008A8: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    func_800EEB9C(rdram, ctx);
        goto after_1;
    // 0x808008A8: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    after_1:
    // 0x808008AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808008B0: jal         0x800EE7F8
    // 0x808008B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808008B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x808008B8: lwc1        $f12, 0x7C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x808008BC: lwc1        $f14, 0x84($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X84);
    // 0x808008C0: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x808008C4: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x808008C8: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(3230, 0X18E0) << 16);
    // 0x808008CC: add.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x808008D0: addiu       $s4, $s4, 0x18E0
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(3230, 0X18E0));
    // 0x808008D4: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x808008D8: add.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x808008DC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808008E0: swc1        $f6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f6.u32l;
    // 0x808008E4: sh          $s1, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r17;
    // 0x808008E8: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    // 0x808008EC: sh          $s5, 0x2($s4)
    MEM_H(0X2, ctx->r20) = ctx->r21;
    // 0x808008F0: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x808008F4: addiu       $s7, $sp, 0x74
    ctx->r23 = ADD32(ctx->r29, 0X74);
    // 0x808008F8: addiu       $s6, $sp, 0x94
    ctx->r22 = ADD32(ctx->r29, 0X94);
L_808008FC:
    // 0x808008FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800900: jal         0x800CC63C
    // 0x80800904: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800CC63C(rdram, ctx);
        goto after_3;
    // 0x80800904: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80800908: lh          $t7, 0xC($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XC);
    // 0x8080090C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800910: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800914: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80800918: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8080091C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800920: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800924: jal         0x800F0064
    // 0x80800928: nop

    func_800F0064(rdram, ctx);
        goto after_4;
    // 0x80800928: nop

    after_4:
    // 0x8080092C: beql        $v0, $zero, L_80800940
    if (ctx->r2 == 0) {
        // 0x80800930: lh          $t8, 0xC($s0)
        ctx->r24 = MEM_H(ctx->r16, 0XC);
            goto L_80800940;
    }
    goto skip_0;
    // 0x80800930: lh          $t8, 0xC($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XC);
    skip_0:
    // 0x80800934: b           L_80800A3C
    // 0x80800938: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A3C;
    // 0x80800938: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080093C: lh          $t8, 0xC($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XC);
L_80800940:
    // 0x80800940: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // 0x80800944: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800948: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8080094C: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x80800950: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800954: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800958: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8080095C: jal         0x800F05F8
    // 0x80800960: nop

    func_800F05F8(rdram, ctx);
        goto after_5;
    // 0x80800960: nop

    after_5:
    // 0x80800964: beq         $v0, $zero, L_80800984
    if (ctx->r2 == 0) {
        // 0x80800968: lwc1        $f22, 0x74($sp)
        ctx->f22.u32l = MEM_W(ctx->r29, 0X74);
            goto L_80800984;
    }
    // 0x80800968: lwc1        $f22, 0x74($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8080096C: beq         $v0, $fp, L_8080098C
    if (ctx->r2 == ctx->r30) {
        // 0x80800970: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080098C;
    }
    // 0x80800970: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800974: beq         $v0, $at, L_808009AC
    if (ctx->r2 == ctx->r1) {
        // 0x80800978: lwc1        $f12, 0x74($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
            goto L_808009AC;
    }
    // 0x80800978: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8080097C: b           L_808009D4
    // 0x80800980: lwc1        $f12, 0x7C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X7C);
        goto L_808009D4;
    // 0x80800980: lwc1        $f12, 0x7C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X7C);
L_80800984:
    // 0x80800984: b           L_80800A3C
    // 0x80800988: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A3C;
    // 0x80800988: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080098C:
    // 0x8080098C: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x80800990: nop

    // 0x80800994: bc1f        L_808009A4
    if (!c1cs) {
        // 0x80800998: nop
    
            goto L_808009A4;
    }
    // 0x80800998: nop

    // 0x8080099C: b           L_80800A3C
    // 0x808009A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A3C;
    // 0x808009A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009A4:
    // 0x808009A4: b           L_808009D0
    // 0x808009A8: swc1        $f22, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f22.u32l;
        goto L_808009D0;
    // 0x808009A8: swc1        $f22, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f22.u32l;
L_808009AC:
    // 0x808009AC: jal         0x800F0E00
    // 0x808009B0: lwc1        $f14, 0x78($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X78);
    func_800F0E00(rdram, ctx);
        goto after_6;
    // 0x808009B0: lwc1        $f14, 0x78($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X78);
    after_6:
    // 0x808009B4: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x808009B8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x808009BC: bc1fl       L_808009D0
    if (!c1cs) {
        // 0x808009C0: swc1        $f22, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->f22.u32l;
            goto L_808009D0;
    }
    goto skip_1;
    // 0x808009C0: swc1        $f22, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f22.u32l;
    skip_1:
    // 0x808009C4: b           L_80800A3C
    // 0x808009C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A3C;
    // 0x808009C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808009CC: swc1        $f22, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f22.u32l;
L_808009D0:
    // 0x808009D0: lwc1        $f12, 0x7C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X7C);
L_808009D4:
    // 0x808009D4: lwc1        $f22, 0x74($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X74);
    // 0x808009D8: lwc1        $f14, 0x84($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X84);
    // 0x808009DC: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x808009E0: mul.s       $f0, $f12, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x808009E4: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x808009E8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808009EC: mul.s       $f2, $f14, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f22.fl);
    // 0x808009F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808009F4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808009F8: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x808009FC: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80800A00: sub.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x80800A04: swc1        $f12, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f12.u32l;
    // 0x80800A08: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800A0C: swc1        $f14, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f14.u32l;
    // 0x80800A10: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80800A14: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x80800A18: jal         0x80800F34
    // 0x80800A1C: swc1        $f10, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f10.u32l;
    func_80800F34_subaddierouteDll(rdram, ctx);
        goto after_7;
    // 0x80800A1C: swc1        $f10, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x80800A20: bne         $v0, $s5, L_808008FC
    if (ctx->r2 != ctx->r21) {
        // 0x80800A24: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_808008FC;
    }
    // 0x80800A24: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800A28: lw          $v1, 0xA4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA4);
    // 0x80800A2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800A30: lhu         $t9, 0x6($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X6);
    // 0x80800A34: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80800A38: sh          $t0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r8;
L_80800A3C:
    // 0x80800A3C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80800A40: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800A44: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800A48: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80800A4C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80800A50: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80800A54: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80800A58: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80800A5C: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80800A60: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80800A64: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80800A68: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80800A6C: jr          $ra
    // 0x80800A70: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80800A70: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void bskazstill_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800664: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800668: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(288, 0X8A4) << 16);
    // 0x8080066C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800670: jr          $ra
    // 0x80800674: lw          $v0, 0x8A4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(288, 0X8A4));
    return;
    // 0x80800674: lw          $v0, 0x8A4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(288, 0X8A4));
;}
RECOMP_FUNC void func_80800048_chlavaexplodbuild(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080004C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800050: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800054: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800058: addiu       $a1, $zero, 0x708
    ctx->r5 = ADD32(0, 0X708);
    // 0x8080005C: addiu       $a2, $zero, 0x7D0
    ctx->r6 = ADD32(0, 0X7D0);
    // 0x80800060: jal         0x8010CB0C
    // 0x80800064: addiu       $a3, $zero, -0x1F4
    ctx->r7 = ADD32(0, -0X1F4);
    func_8010CB0C(rdram, ctx);
        goto after_0;
    // 0x80800064: addiu       $a3, $zero, -0x1F4
    ctx->r7 = ADD32(0, -0X1F4);
    after_0:
    // 0x80800068: addiu       $a0, $zero, 0xA24
    ctx->r4 = ADD32(0, 0XA24);
    // 0x8080006C: jal         0x800DA3B8
    // 0x80800070: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800DA3B8(rdram, ctx);
        goto after_1;
    // 0x80800070: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80800074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800078: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080007C: jr          $ra
    // 0x80800080: nop

    return;
    // 0x80800080: nop

;}
RECOMP_FUNC void func_800123B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800123B0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800123B4: jr          $ra
    // 0x800123B8: lw          $v0, 0x59D0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X59D0);
    return;
    // 0x800123B8: lw          $v0, 0x59D0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X59D0);
;}
RECOMP_FUNC void func_8080000C_chamazonstadiumguard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80800010: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80800014: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80800018: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
    // 0x8080001C: swc1        $f6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f6.u32l;
    // 0x80800020: jr          $ra
    // 0x80800024: swc1        $f8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x80800024: swc1        $f8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void charmouredcaveman_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1116, 0XB20) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xB20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1116, 0XB20));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xB20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1116, 0XB20));
;}
RECOMP_FUNC void func_808007F0_chmasterjiggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007F4: slti        $at, $a1, 0x33
    ctx->r1 = SIGNED(ctx->r5) < 0X33 ? 1 : 0;
    // 0x808007F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007FC: bne         $at, $zero, L_80800818
    if (ctx->r1 != 0) {
        // 0x80800800: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800818;
    }
    // 0x80800800: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800804: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800808: beql        $a1, $at, L_80800940
    if (ctx->r5 == ctx->r1) {
        // 0x8080080C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800940;
    }
    goto skip_0;
    // 0x8080080C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800810: b           L_80800940
    // 0x80800814: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800940;
    // 0x80800814: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800818:
    // 0x80800818: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x8080081C: bne         $at, $zero, L_80800844
    if (ctx->r1 != 0) {
        // 0x80800820: addiu       $t6, $a1, -0x2E
        ctx->r14 = ADD32(ctx->r5, -0X2E);
            goto L_80800844;
    }
    // 0x80800820: addiu       $t6, $a1, -0x2E
    ctx->r14 = ADD32(ctx->r5, -0X2E);
    // 0x80800824: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80800828: beq         $at, $zero, L_80800850
    if (ctx->r1 == 0) {
        // 0x8080082C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800850;
    }
    // 0x8080082C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800830: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(768, 0X1578) << 16);
    // 0x80800834: addu        $at, $at, $t6
    gpr jr_addend_8080083C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800838: lw          $t6, 0x1578($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(768, 0X1578));
    // 0x8080083C: jr          $t6
    // 0x80800840: nop

    switch (jr_addend_8080083C >> 2) {
        case 0: goto L_80800858; break;
        case 1: goto L_8080086C; break;
        case 2: goto L_80800914; break;
        case 3: goto L_808008BC; break;
        case 4: goto L_80800888; break;
        default: switch_error(__func__, 0x8080083C, 0x80801578);
    }
    // 0x80800840: nop

L_80800844:
    // 0x80800844: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800848: beq         $a1, $at, L_80800880
    if (ctx->r5 == ctx->r1) {
        // 0x8080084C: nop
    
            goto L_80800880;
    }
    // 0x8080084C: nop

L_80800850:
    // 0x80800850: b           L_80800940
    // 0x80800854: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800940;
    // 0x80800854: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800858:
    // 0x80800858: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    // 0x8080085C: jal         0x80800744
    // 0x80800860: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    func_80800744_chmasterjiggy(rdram, ctx);
        goto after_0;
    // 0x80800860: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    after_0:
    // 0x80800864: b           L_80800940
    // 0x80800868: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800940;
    // 0x80800868: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080086C:
    // 0x8080086C: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    // 0x80800870: jal         0x80800704
    // 0x80800874: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    func_80800704_chmasterjiggy(rdram, ctx);
        goto after_1;
    // 0x80800874: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    after_1:
    // 0x80800878: b           L_80800940
    // 0x8080087C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800940;
    // 0x8080087C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800880:
    // 0x80800880: b           L_80800940
    // 0x80800884: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800940;
    // 0x80800884: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800888:
    // 0x80800888: lhu         $t7, 0x72($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X72);
    // 0x8080088C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800890: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800894: bne         $t8, $at, L_808008AC
    if (ctx->r24 != ctx->r1) {
        // 0x80800898: nop
    
            goto L_808008AC;
    }
    // 0x80800898: nop

    // 0x8080089C: jal         0x80800220
    // 0x808008A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800220_chmasterjiggy(rdram, ctx);
        goto after_2;
    // 0x808008A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x808008A4: b           L_80800940
    // 0x808008A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800940;
    // 0x808008A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008AC:
    // 0x808008AC: jal         0x808001D0
    // 0x808008B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808001D0_chmasterjiggy(rdram, ctx);
        goto after_3;
    // 0x808008B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808008B4: b           L_80800940
    // 0x808008B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800940;
    // 0x808008B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008BC:
    // 0x808008BC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808008C0: jal         0x80800220
    // 0x808008C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800220_chmasterjiggy(rdram, ctx);
        goto after_4;
    // 0x808008C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_4:
    // 0x808008C8: jal         0x8008A740
    // 0x808008CC: nop

    _sujiggy_entrypoint_21(rdram, ctx);
        goto after_5;
    // 0x808008CC: nop

    after_5:
    // 0x808008D0: beq         $v0, $zero, L_808008E8
    if (ctx->r2 == 0) {
        // 0x808008D4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808008E8;
    }
    // 0x808008D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808008D8: jal         0x808001D0
    // 0x808008DC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808001D0_chmasterjiggy(rdram, ctx);
        goto after_6;
    // 0x808008DC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_6:
    // 0x808008E0: b           L_80800940
    // 0x808008E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800940;
    // 0x808008E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008E8:
    // 0x808008E8: jal         0x8008A720
    // 0x808008EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _sujiggy_entrypoint_17(rdram, ctx);
        goto after_7;
    // 0x808008EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_7:
    // 0x808008F0: beq         $v0, $zero, L_80800900
    if (ctx->r2 == 0) {
        // 0x808008F4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800900;
    }
    // 0x808008F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808008F8: b           L_80800904
    // 0x808008FC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
        goto L_80800904;
    // 0x808008FC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_80800900:
    // 0x80800900: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_80800904:
    // 0x80800904: jal         0x808001D0
    // 0x80800908: nop

    func_808001D0_chmasterjiggy(rdram, ctx);
        goto after_8;
    // 0x80800908: nop

    after_8:
    // 0x8080090C: b           L_80800940
    // 0x80800910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800940;
    // 0x80800910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800914:
    // 0x80800914: lh          $a3, 0x20($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X20);
    // 0x80800918: addiu       $at, $zero, 0x14F7
    ctx->r1 = ADD32(0, 0X14F7);
    // 0x8080091C: beq         $a3, $at, L_8080092C
    if (ctx->r7 == ctx->r1) {
        // 0x80800920: addiu       $at, $zero, 0x14F8
        ctx->r1 = ADD32(0, 0X14F8);
            goto L_8080092C;
    }
    // 0x80800920: addiu       $at, $zero, 0x14F8
    ctx->r1 = ADD32(0, 0X14F8);
    // 0x80800924: beq         $a3, $at, L_8080092C
    if (ctx->r7 == ctx->r1) {
        // 0x80800928: nop
    
            goto L_8080092C;
    }
    // 0x80800928: nop

L_8080092C:
    // 0x8080092C: jal         0x8008A698
    // 0x80800930: nop

    _sujiggy_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x80800930: nop

    after_9:
    // 0x80800934: b           L_80800940
    // 0x80800938: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_80800940;
    // 0x80800938: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8080093C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800940:
    // 0x80800940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800944: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800948: jr          $ra
    // 0x8080094C: nop

    return;
    // 0x8080094C: nop

;}
RECOMP_FUNC void _chmasterjiggy_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085B18: syscall     196
    recomp_syscall_handler(rdram, ctx, 0x80085B18);
    return;
    // 0x80085B1C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void scinfobar_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005D0: jr          $ra
    // 0x808005D4: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    return;
    // 0x808005D4: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
;}
RECOMP_FUNC void func_8008FE68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FE68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FE6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FE70: jal         0x800F54E4
    // 0x8008FE74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FE74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008FE78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FE7C: jal         0x800F5A00
    // 0x8008FE80: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x8008FE80: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008FE84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FE88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FE8C: jr          $ra
    // 0x8008FE90: nop

    return;
    // 0x8008FE90: nop

;}
RECOMP_FUNC void func_8080160C_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080160C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801610: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801614: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801618: jal         0x80100094
    // 0x8080161C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080161C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801620: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    // 0x80801624: jal         0x800DA298
    // 0x80801628: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80801628: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080162C: bne         $v0, $zero, L_80801734
    if (ctx->r2 != 0) {
        // 0x80801630: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80801734;
    }
    // 0x80801630: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80801634: lbu         $a0, 0xC2($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0XC2);
    // 0x80801638: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080163C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80801640: blezl       $a0, L_80801668
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80801644: lbu         $t7, 0xC3($a1)
        ctx->r15 = MEM_BU(ctx->r5, 0XC3);
            goto L_80801668;
    }
    goto skip_0;
    // 0x80801644: lbu         $t7, 0xC3($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XC3);
    skip_0:
L_80801648:
    // 0x80801648: lbu         $t6, 0x30($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X30);
    // 0x8080164C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80801650: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80801654: beql        $t6, $zero, L_80801738
    if (ctx->r14 == 0) {
        // 0x80801658: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801738;
    }
    goto skip_1;
    // 0x80801658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8080165C: bne         $at, $zero, L_80801648
    if (ctx->r1 != 0) {
        // 0x80801660: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80801648;
    }
    // 0x80801660: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80801664: lbu         $t7, 0xC3($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XC3);
L_80801668:
    // 0x80801668: beql        $t7, $zero, L_80801738
    if (ctx->r15 == 0) {
        // 0x8080166C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801738;
    }
    goto skip_2;
    // 0x8080166C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80801670: lbu         $t8, 0xC4($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XC4);
    // 0x80801674: beql        $t8, $zero, L_80801738
    if (ctx->r24 == 0) {
        // 0x80801678: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801738;
    }
    goto skip_3;
    // 0x80801678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8080167C: lbu         $t9, 0xC6($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XC6);
    // 0x80801680: beql        $t9, $zero, L_80801694
    if (ctx->r25 == 0) {
        // 0x80801684: lw          $t0, 0x20($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X20);
            goto L_80801694;
    }
    goto skip_4;
    // 0x80801684: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    skip_4:
    // 0x80801688: jal         0x80085710
    // 0x8080168C: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_2;
    // 0x8080168C: nop

    after_2:
    // 0x80801690: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
L_80801694:
    // 0x80801694: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801698: lbu         $v0, 0x79($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X79);
    // 0x8080169C: srl         $t1, $v0, 4
    ctx->r9 = S32(U32(ctx->r2) >> 4);
    // 0x808016A0: beq         $t1, $zero, L_808016C8
    if (ctx->r9 == 0) {
        // 0x808016A4: nop
    
            goto L_808016C8;
    }
    // 0x808016A4: nop

    // 0x808016A8: beq         $t1, $at, L_808016C8
    if (ctx->r9 == ctx->r1) {
        // 0x808016AC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808016C8;
    }
    // 0x808016AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808016B0: beq         $t1, $at, L_808016C8
    if (ctx->r9 == ctx->r1) {
        // 0x808016B4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808016C8;
    }
    // 0x808016B4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808016B8: beql        $t1, $at, L_808016D4
    if (ctx->r9 == ctx->r1) {
        // 0x808016BC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_808016D4;
    }
    goto skip_5;
    // 0x808016BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_5:
    // 0x808016C0: b           L_808016D4
    // 0x808016C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_808016D4;
    // 0x808016C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_808016C8:
    // 0x808016C8: jal         0x800A54F8
    // 0x808016CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A54F8(rdram, ctx);
        goto after_3;
    // 0x808016CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x808016D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_808016D4:
    // 0x808016D4: jal         0x800BF744
    // 0x808016D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BF744(rdram, ctx);
        goto after_4;
    // 0x808016D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808016DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808016E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808016E4: lbu         $t2, 0x79($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X79);
    // 0x808016E8: srl         $t3, $t2, 4
    ctx->r11 = S32(U32(ctx->r10) >> 4);
    // 0x808016EC: bnel        $t3, $at, L_80801700
    if (ctx->r11 != ctx->r1) {
        // 0x808016F0: lw          $t4, 0x64($a0)
        ctx->r12 = MEM_W(ctx->r4, 0X64);
            goto L_80801700;
    }
    goto skip_6;
    // 0x808016F0: lw          $t4, 0x64($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X64);
    skip_6:
    // 0x808016F4: b           L_80801718
    // 0x808016F8: addiu       $a1, $zero, 0x10EB
    ctx->r5 = ADD32(0, 0X10EB);
        goto L_80801718;
    // 0x808016F8: addiu       $a1, $zero, 0x10EB
    ctx->r5 = ADD32(0, 0X10EB);
    // 0x808016FC: lw          $t4, 0x64($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X64);
L_80801700:
    // 0x80801700: addiu       $a1, $zero, 0x10D3
    ctx->r5 = ADD32(0, 0X10D3);
    // 0x80801704: sll         $t6, $t4, 12
    ctx->r14 = S32(ctx->r12 << 12);
    // 0x80801708: bltz        $t6, L_80801718
    if (SIGNED(ctx->r14) < 0) {
        // 0x8080170C: nop
    
            goto L_80801718;
    }
    // 0x8080170C: nop

    // 0x80801710: b           L_80801718
    // 0x80801714: addiu       $a1, $zero, 0x10FC
    ctx->r5 = ADD32(0, 0X10FC);
        goto L_80801718;
    // 0x80801714: addiu       $a1, $zero, 0x10FC
    ctx->r5 = ADD32(0, 0X10FC);
L_80801718:
    // 0x80801718: jal         0x8080061C
    // 0x8080171C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080061C_chdodgemcontrol(rdram, ctx);
        goto after_5;
    // 0x8080171C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80801720: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80801724: lbu         $t8, 0x72($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X72);
    // 0x80801728: andi        $t9, $t8, 0xFF03
    ctx->r25 = ctx->r24 & 0XFF03;
    // 0x8080172C: ori         $t0, $t9, 0x8
    ctx->r8 = ctx->r25 | 0X8;
    // 0x80801730: sb          $t0, 0x72($t7)
    MEM_B(0X72, ctx->r15) = ctx->r8;
L_80801734:
    // 0x80801734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801738:
    // 0x80801738: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080173C: jr          $ra
    // 0x80801740: nop

    return;
    // 0x80801740: nop

;}
RECOMP_FUNC void func_8009E154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E154: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8009E158: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8009E15C: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x8009E160: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8009E164: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009E168: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8009E16C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8009E170: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x8009E174: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8009E178: lw          $t7, 0x114($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X114);
    // 0x8009E17C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8009E180: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x8009E184: addu        $v0, $t7, $t6
    ctx->r2 = ADD32(ctx->r15, ctx->r14);
    // 0x8009E188: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8009E18C: beql        $v1, $zero, L_8009E1AC
    if (ctx->r3 == 0) {
        // 0x8009E190: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8009E1AC;
    }
    goto skip_0;
    // 0x8009E190: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x8009E194: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x8009E198: jalr        $v1
    // 0x8009E19C: lh          $a2, 0x4($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X4);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8009E19C: lh          $a2, 0x4($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X4);
    after_0:
    // 0x8009E1A0: b           L_8009E2B4
    // 0x8009E1A4: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
        goto L_8009E2B4;
    // 0x8009E1A4: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8009E1A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8009E1AC:
    // 0x8009E1AC: jal         0x80092CDC
    // 0x8009E1B0: lh          $a2, 0x4($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X4);
    func_80092CDC(rdram, ctx);
        goto after_1;
    // 0x8009E1B0: lh          $a2, 0x4($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X4);
    after_1:
    // 0x8009E1B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8009E1B8: jal         0x8009C128
    // 0x8009E1BC: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_8009C128(rdram, ctx);
        goto after_2;
    // 0x8009E1BC: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_2:
    // 0x8009E1C0: addiu       $s0, $sp, 0x4C
    ctx->r16 = ADD32(ctx->r29, 0X4C);
    // 0x8009E1C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8009E1C8: jal         0x80092D18
    // 0x8009E1CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80092D18(rdram, ctx);
        goto after_3;
    // 0x8009E1CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8009E1D0: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x8009E1D4: jal         0x800EF04C
    // 0x8009E1D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_4;
    // 0x8009E1D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8009E1DC: jal         0x800EEEA8
    // 0x8009E1E0: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    func_800EEEA8(rdram, ctx);
        goto after_5;
    // 0x8009E1E0: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    after_5:
    // 0x8009E1E4: beq         $v0, $zero, L_8009E250
    if (ctx->r2 == 0) {
        // 0x8009E1E8: addiu       $s0, $sp, 0x58
        ctx->r16 = ADD32(ctx->r29, 0X58);
            goto L_8009E250;
    }
    // 0x8009E1E8: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x8009E1EC: lw          $t9, 0x114($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X114);
    // 0x8009E1F0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8009E1F4: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x8009E1F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009E1FC: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x8009E200: jal         0x800EE7F8
    // 0x8009E204: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x8009E204: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_6:
    // 0x8009E208: jal         0x8009BFCC
    // 0x8009E20C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8009BFCC(rdram, ctx);
        goto after_7;
    // 0x8009E20C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x8009E210: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8009E214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009E218: jal         0x800EF8BC
    // 0x8009E21C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF8BC(rdram, ctx);
        goto after_8;
    // 0x8009E21C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x8009E220: jal         0x8009C984
    // 0x8009E224: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_get(rdram, ctx);
        goto after_9;
    // 0x8009E224: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x8009E228: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8009E22C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009E230: jal         0x800EF934
    // 0x8009E234: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF934(rdram, ctx);
        goto after_10;
    // 0x8009E234: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
    // 0x8009E238: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x8009E23C: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x8009E240: jal         0x800EE780
    // 0x8009E244: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800EE780(rdram, ctx);
        goto after_11;
    // 0x8009E244: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_11:
    // 0x8009E248: b           L_8009E2B4
    // 0x8009E24C: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
        goto L_8009E2B4;
    // 0x8009E24C: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
L_8009E250:
    // 0x8009E250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009E254: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x8009E258: jal         0x800EFB24
    // 0x8009E25C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    func_800EFB24(rdram, ctx);
        goto after_12;
    // 0x8009E25C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_12:
    // 0x8009E260: jal         0x8009C984
    // 0x8009E264: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_get(rdram, ctx);
        goto after_13;
    // 0x8009E264: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x8009E268: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x8009E26C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009E270: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8009E274: jal         0x800EF934
    // 0x8009E278: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF934(rdram, ctx);
        goto after_14;
    // 0x8009E278: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_14:
    // 0x8009E27C: jal         0x8009BFCC
    // 0x8009E280: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8009BFCC(rdram, ctx);
        goto after_15;
    // 0x8009E280: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x8009E284: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x8009E288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009E28C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8009E290: jal         0x800EF8BC
    // 0x8009E294: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF8BC(rdram, ctx);
        goto after_16;
    // 0x8009E294: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_16:
    // 0x8009E298: lw          $t1, 0x114($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X114);
    // 0x8009E29C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8009E2A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8009E2A4: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    // 0x8009E2A8: jal         0x800EE7F8
    // 0x8009E2AC: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_17;
    // 0x8009E2AC: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_17:
    // 0x8009E2B0: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
L_8009E2B4:
    // 0x8009E2B4: lw          $t3, 0x114($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X114);
    // 0x8009E2B8: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8009E2BC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8009E2C0: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8009E2C4: lwc1        $f10, 0x18($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X18);
    // 0x8009E2C8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8009E2CC: swc1        $f16, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f16.u32l;
    // 0x8009E2D0: lw          $t5, 0x114($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X114);
    // 0x8009E2D4: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8009E2D8: lwc1        $f4, 0x1C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x8009E2DC: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x8009E2E0: nop

    // 0x8009E2E4: bc1tl       L_8009E350
    if (c1cs) {
        // 0x8009E2E8: addiu       $s0, $sp, 0x40
        ctx->r16 = ADD32(ctx->r29, 0X40);
            goto L_8009E350;
    }
    goto skip_1;
    // 0x8009E2E8: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    skip_1:
    // 0x8009E2EC: jal         0x8009C984
    // 0x8009E2F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_get(rdram, ctx);
        goto after_18;
    // 0x8009E2F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
    // 0x8009E2F4: lw          $t7, 0x114($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X114);
    // 0x8009E2F8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8009E2FC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8009E300: lwc1        $f6, 0x24($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X24);
    // 0x8009E304: jal         0x800136E4
    // 0x8009E308: add.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_19;
    // 0x8009E308: add.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f0.fl;
    after_19:
    // 0x8009E30C: lw          $t0, 0x114($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X114);
    // 0x8009E310: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8009E314: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8009E318: addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // 0x8009E31C: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x8009E320: lw          $a1, 0x20($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X20);
    // 0x8009E324: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x8009E328: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8009E32C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8009E330: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8009E334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009E338: jal         0x800EF4E4
    // 0x8009E33C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800EF4E4(rdram, ctx);
        goto after_20;
    // 0x8009E33C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_20:
    // 0x8009E340: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x8009E344: jal         0x800EF04C
    // 0x8009E348: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_21;
    // 0x8009E348: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_21:
    // 0x8009E34C: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
L_8009E350:
    // 0x8009E350: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8009E354: jal         0x80096394
    // 0x8009E358: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80096394(rdram, ctx);
        goto after_22;
    // 0x8009E358: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_22:
    // 0x8009E35C: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x8009E360: jal         0x800EF04C
    // 0x8009E364: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_23;
    // 0x8009E364: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_23:
    // 0x8009E368: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x8009E36C: jal         0x800EE7F8
    // 0x8009E370: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    func_800EE7F8(rdram, ctx);
        goto after_24;
    // 0x8009E370: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    after_24:
    // 0x8009E374: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009E378: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8009E37C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8009E380: jr          $ra
    // 0x8009E384: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8009E384: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_808007EC_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808007F8: jal         0x8009BF5C
    // 0x808007FC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_0;
    // 0x808007FC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x80800800: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800804: jal         0x8009C4CC
    // 0x80800808: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_1;
    // 0x80800808: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x8080080C: jal         0x808000F0
    // 0x80800810: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bsvan_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800810: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080081C: jr          $ra
    // 0x80800820: nop

    return;
    // 0x80800820: nop

;}
RECOMP_FUNC void func_800F9110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9110: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F9114: jr          $ra
    // 0x800F9118: sb          $a0, 0x54FD($at)
    MEM_B(0X54FD, ctx->r1) = ctx->r4;
    return;
    // 0x800F9118: sb          $a0, 0x54FD($at)
    MEM_B(0X54FD, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_808001D8_chfantasytrashcanbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001DC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808001E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001E8: bne         $a1, $at, L_80800200
    if (ctx->r5 != ctx->r1) {
        // 0x808001EC: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800200;
    }
    // 0x808001EC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808001F0: addiu       $a0, $zero, 0x40C
    ctx->r4 = ADD32(0, 0X40C);
    // 0x808001F4: jal         0x80101180
    // 0x808001F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80101180(rdram, ctx);
        goto after_0;
    // 0x808001F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808001FC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_80800200:
    // 0x80800200: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800204: jal         0x80085820
    // 0x80800208: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80800208: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080020C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800210: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800214: jr          $ra
    // 0x80800218: nop

    return;
    // 0x80800218: nop

;}
RECOMP_FUNC void func_80805474_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805474: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80805478: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080547C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80805480: jal         0x8080537C
    // 0x80805484: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080537C_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80805484: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80805488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080548C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80805490: jr          $ra
    // 0x80805494: nop

    return;
    // 0x80805494: nop

;}
RECOMP_FUNC void func_80801B2C_chfactoryempspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B2C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80801B30: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80801B34: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80801B38: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80801B3C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80801B40: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80801B44: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80801B48: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80801B4C: jal         0x80100094
    // 0x80801B50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801B50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80801B54: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80801B58: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80801B5C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80801B60: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80801B64: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801B68: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801B6C: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // 0x80801B70: addiu       $s2, $sp, 0x44
    ctx->r18 = ADD32(ctx->r29, 0X44);
L_80801B74:
    // 0x80801B74: jal         0x800F54E4
    // 0x80801B78: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80801B78: nop

    after_1:
    // 0x80801B7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801B80: jal         0x800F5A00
    // 0x80801B84: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x80801B84: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x80801B88: jal         0x800C8A98
    // 0x80801B8C: nop

    func_800C8A98(rdram, ctx);
        goto after_3;
    // 0x80801B8C: nop

    after_3:
    // 0x80801B90: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801B94: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80801B98: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x80801B9C: jal         0x800C8E54
    // 0x80801BA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C8E54(rdram, ctx);
        goto after_4;
    // 0x80801BA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80801BA4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80801BA8: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x80801BAC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80801BB0: jal         0x800C8FB0
    // 0x80801BB4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C8FB0(rdram, ctx);
        goto after_5;
    // 0x80801BB4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_5:
    // 0x80801BB8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80801BBC: jal         0x800C8F64
    // 0x80801BC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C8F64(rdram, ctx);
        goto after_6;
    // 0x80801BC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80801BC4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80801BC8: jal         0x800C8CB8
    // 0x80801BCC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800C8CB8(rdram, ctx);
        goto after_7;
    // 0x80801BCC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x80801BD0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80801BD4: bne         $s1, $s3, L_80801B74
    if (ctx->r17 != ctx->r19) {
        // 0x80801BD8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80801B74;
    }
    // 0x80801BD8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80801BDC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80801BE0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80801BE4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80801BE8: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80801BEC: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80801BF0: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80801BF4: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80801BF8: jr          $ra
    // 0x80801BFC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80801BFC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8002A9B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A9B8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8002A9BC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002A9C0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8002A9C4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8002A9C8: lw          $t6, 0x11F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11F4);
    // 0x8002A9CC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8002A9D0: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8002A9D4: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8002A9D8: lui         $t0, 0x8002
    ctx->r8 = S32(0X8002 << 16);
    // 0x8002A9DC: addiu       $t0, $t0, 0x72B0
    ctx->r8 = ADD32(ctx->r8, 0X72B0);
    // 0x8002A9E0: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8002A9E4: bne         $t9, $t0, L_8002AA18
    if (ctx->r25 != ctx->r8) {
        // 0x8002A9E8: nop
    
            goto L_8002AA18;
    }
    // 0x8002A9E8: nop

    // 0x8002A9EC: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x8002A9F0: lw          $t1, 0x11F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X11F4);
    // 0x8002A9F4: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x8002A9F8: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x8002A9FC: lw          $t2, 0x34($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X34);
    // 0x8002AA00: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8002AA04: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8002AA08: b           L_8002AA28
    // 0x8002AA0C: lw          $v0, 0x44($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X44);
        goto L_8002AA28;
    // 0x8002AA0C: lw          $v0, 0x44($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X44);
    // 0x8002AA10: b           L_8002AA20
    // 0x8002AA14: nop

        goto L_8002AA20;
    // 0x8002AA14: nop

L_8002AA18:
    // 0x8002AA18: b           L_8002AA28
    // 0x8002AA1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002AA28;
    // 0x8002AA1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002AA20:
    // 0x8002AA20: b           L_8002AA28
    // 0x8002AA24: nop

        goto L_8002AA28;
    // 0x8002AA24: nop

L_8002AA28:
    // 0x8002AA28: jr          $ra
    // 0x8002AA2C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8002AA2C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8080297C_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080297C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80802980: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802984: jal         0x800D8FF8
    // 0x80802988: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80802988: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080298C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80802990: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80802994: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80802998: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8080299C: jal         0x800EE7F8
    // 0x808029A0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808029A0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x808029A4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808029A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808029AC: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808029B0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808029B4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808029B8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808029BC: jal         0x800EE7F8
    // 0x808029C0: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808029C0: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x808029C4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808029C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808029CC: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808029D0: lui         $a3, 0x2
    ctx->r7 = S32(0X2 << 16);
    // 0x808029D4: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x808029D8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x808029DC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808029E0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808029E4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x808029E8: jal         0x800BEF00
    // 0x808029EC: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    func_800BEF00(rdram, ctx);
        goto after_3;
    // 0x808029EC: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x808029F0: beq         $v0, $zero, L_80802A10
    if (ctx->r2 == 0) {
        // 0x808029F4: lw          $v1, 0x48($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X48);
            goto L_80802A10;
    }
    // 0x808029F4: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x808029F8: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808029FC: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80802A00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80802A04: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80802A08: nop

    // 0x80802A0C: bc1f        L_80802A38
    if (!c1cs) {
        // 0x80802A10: lui         $at, 0x437A
        ctx->r1 = S32(0X437A << 16);
            goto L_80802A38;
    }
L_80802A10:
    // 0x80802A10: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80802A14: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802A18: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80802A1C: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x80802A20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80802A24: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80802A28: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80802A2C: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80802A30: b           L_80802A38
    // 0x80802A34: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
        goto L_80802A38;
    // 0x80802A34: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
L_80802A38:
    // 0x80802A38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802A3C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80802A40: jr          $ra
    // 0x80802A44: nop

    return;
    // 0x80802A44: nop

;}
RECOMP_FUNC void func_808003D8_bscarry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003E0: jal         0x808001D4
    // 0x808003E4: nop

    func_808001D4_bscarry(rdram, ctx);
        goto after_0;
    // 0x808003E4: nop

    after_0:
    // 0x808003E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003F0: jr          $ra
    // 0x808003F4: nop

    return;
    // 0x808003F4: nop

;}
RECOMP_FUNC void subaddielink_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80800004: jr          $ra
    // 0x80800008: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    return;
    // 0x80800008: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
;}
