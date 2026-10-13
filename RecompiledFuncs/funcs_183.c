#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _sumumbofx_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089858: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x80089858);
    return;
    // 0x8008985C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void chcrusher_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B00: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1624, 0XD68) << 16);
    // 0x80800B04: jr          $ra
    // 0x80800B08: addiu       $v0, $v0, 0xD68
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1624, 0XD68));
    return;
    // 0x80800B08: addiu       $v0, $v0, 0xD68
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1624, 0XD68));
    // 0x80800B0C: nop

;}
RECOMP_FUNC void func_801096C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801096C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801096CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801096D0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801096D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801096D8: jal         0x80103DFC
    // 0x801096DC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_80103DFC(rdram, ctx);
        goto after_0;
    // 0x801096DC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x801096E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801096E4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x801096E8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x801096EC: jal         0x80109538
    // 0x801096F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80109538(rdram, ctx);
        goto after_1;
    // 0x801096F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x801096F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801096F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801096FC: jr          $ra
    // 0x80109700: nop

    return;
    // 0x80109700: nop

;}
RECOMP_FUNC void func_8009C1F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C1F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C1FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C200: lw          $a0, 0xE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE4);
    // 0x8009C204: jal         0x800EE7F8
    // 0x8009C208: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8009C208: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_0:
    // 0x8009C20C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C210: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C214: jr          $ra
    // 0x8009C218: nop

    return;
    // 0x8009C218: nop

;}
RECOMP_FUNC void func_800191F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800191F8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800191FC: addiu       $v0, $v0, -0x4350
    ctx->r2 = ADD32(ctx->r2, -0X4350);
    // 0x80019200: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80019204: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80019208: swc1        $f12, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f12.u32l;
    // 0x8001920C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80019210: swc1        $f14, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->f14.u32l;
    // 0x80019214: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80019218: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8001921C: jr          $ra
    // 0x80019220: swc1        $f4, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f4.u32l;
    return;
    // 0x80019220: swc1        $f4, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_808005E0_chfactorysparkroom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005E0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808005E4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2372, 0X1094) << 16);
    // 0x808005E8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808005EC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808005F0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808005F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808005F8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808005FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800600: addiu       $t6, $t6, 0x1094
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2372, 0X1094));
    // 0x80800604: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80800608: addiu       $s4, $sp, 0x40
    ctx->r20 = ADD32(ctx->r29, 0X40);
    // 0x8080060C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800610: sw          $at, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r1;
    // 0x80800614: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80800618: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080061C: sw          $t9, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r25;
    // 0x80800620: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80800624: jal         0x80100094
    // 0x80800628: sw          $at, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r1;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800628: sw          $at, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r1;
    after_0:
    // 0x8080062C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2372, 0X10D8) << 16);
    // 0x80800630: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800634: addiu       $a0, $a0, 0x10D8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2372, 0X10D8));
    // 0x80800638: jal         0x800EE7F8
    // 0x8080063C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8080063C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80800640: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80800644: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(2372, 0X10A0) << 16);
    // 0x80800648: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2372, 0X10A8) << 16);
    // 0x8080064C: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2372, 0X10D8) << 16);
    // 0x80800650: addiu       $s3, $s3, 0x10D8
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2372, 0X10D8));
    // 0x80800654: addiu       $s1, $s1, 0x10A8
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2372, 0X10A8));
    // 0x80800658: addiu       $s2, $s2, 0x10A0
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(2372, 0X10A0));
L_8080065C:
    // 0x8080065C: jal         0x800C8A98
    // 0x80800660: nop

    func_800C8A98(rdram, ctx);
        goto after_2;
    // 0x80800660: nop

    after_2:
    // 0x80800664: sw          $v0, 0x200($s0)
    MEM_W(0X200, ctx->r16) = ctx->r2;
    // 0x80800668: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080066C: jal         0x800C8CB8
    // 0x80800670: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800C8CB8(rdram, ctx);
        goto after_3;
    // 0x80800670: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80800674: lw          $a0, 0x200($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X200);
    // 0x80800678: jal         0x800C8D4C
    // 0x8080067C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800C8D4C(rdram, ctx);
        goto after_4;
    // 0x8080067C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x80800680: lw          $a0, 0x200($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X200);
    // 0x80800684: jal         0x800C8F64
    // 0x80800688: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C8F64(rdram, ctx);
        goto after_5;
    // 0x80800688: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x8080068C: lw          $a0, 0x200($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X200);
    // 0x80800690: jal         0x800C8FE0
    // 0x80800694: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C8FE0(rdram, ctx);
        goto after_6;
    // 0x80800694: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x80800698: lw          $a0, 0x200($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X200);
    // 0x8080069C: jal         0x800C8E84
    // 0x808006A0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800C8E84(rdram, ctx);
        goto after_7;
    // 0x808006A0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_7:
    // 0x808006A4: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x808006A8: bne         $s1, $s3, L_8080065C
    if (ctx->r17 != ctx->r19) {
        // 0x808006AC: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8080065C;
    }
    // 0x808006AC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808006B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808006B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808006B8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808006BC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808006C0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808006C4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808006C8: jr          $ra
    // 0x808006CC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x808006CC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void ncba1p_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800894: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800898: jr          $ra
    // 0x8080089C: lwc1        $f0, 0x48($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X48);
    return;
    // 0x8080089C: lwc1        $f0, 0x48($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X48);
;}
RECOMP_FUNC void func_800D4EB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4EB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D4EBC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800D4EC0: bne         $a0, $at, L_800D4ECC
    if (ctx->r4 != ctx->r1) {
        // 0x800D4EC4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800D4ECC;
    }
    // 0x800D4EC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D4EC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800D4ECC:
    // 0x800D4ECC: jal         0x800D4DD0
    // 0x800D4ED0: nop

    func_800D4DD0(rdram, ctx);
        goto after_0;
    // 0x800D4ED0: nop

    after_0:
    // 0x800D4ED4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800D4ED8: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800D4EDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D4EE0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800D4EE4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800D4EE8: lbu         $v0, -0x49BE($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X49BE);
    // 0x800D4EEC: jr          $ra
    // 0x800D4EF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800D4EF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void badust_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080092C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800930: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800934: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800938: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x8080093C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800940: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800944: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80800948: beq         $a1, $zero, L_80800968
    if (ctx->r5 == 0) {
        // 0x8080094C: nop
    
            goto L_80800968;
    }
    // 0x8080094C: nop

    // 0x80800950: beq         $a1, $at, L_8080099C
    if (ctx->r5 == ctx->r1) {
        // 0x80800954: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080099C;
    }
    // 0x80800954: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800958: beq         $a1, $at, L_808009D0
    if (ctx->r5 == ctx->r1) {
        // 0x8080095C: nop
    
            goto L_808009D0;
    }
    // 0x8080095C: nop

    // 0x80800960: b           L_808009F4
    // 0x80800964: addiu       $t6, $a1, 0x1
    ctx->r14 = ADD32(ctx->r5, 0X1);
        goto L_808009F4;
    // 0x80800964: addiu       $t6, $a1, 0x1
    ctx->r14 = ADD32(ctx->r5, 0X1);
L_80800968:
    // 0x80800968: jal         0x8009BB18
    // 0x8080096C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB18(rdram, ctx);
        goto after_0;
    // 0x8080096C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800970: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800974: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080097C: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    // 0x80800980: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80800984: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800988: jal         0x80800424
    // 0x8080098C: nop

    badust_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x8080098C: nop

    after_1:
    // 0x80800990: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x80800994: b           L_808009F0
    // 0x80800998: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
        goto L_808009F0;
    // 0x80800998: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
L_8080099C:
    // 0x8080099C: jal         0x8009BB18
    // 0x808009A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB18(rdram, ctx);
        goto after_2;
    // 0x808009A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808009A4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x808009A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808009AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009B0: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    // 0x808009B4: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x808009B8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808009BC: jal         0x80800424
    // 0x808009C0: nop

    badust_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x808009C0: nop

    after_3:
    // 0x808009C4: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x808009C8: b           L_808009F0
    // 0x808009CC: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
        goto L_808009F0;
    // 0x808009CC: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
L_808009D0:
    // 0x808009D0: jal         0x8009BB18
    // 0x808009D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB18(rdram, ctx);
        goto after_4;
    // 0x808009D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808009D8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808009DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009E0: jal         0x80800424
    // 0x808009E4: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    badust_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x808009E4: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_5:
    // 0x808009E8: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x808009EC: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
L_808009F0:
    // 0x808009F0: addiu       $t6, $a1, 0x1
    ctx->r14 = ADD32(ctx->r5, 0X1);
L_808009F4:
    // 0x808009F4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x808009F8: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x808009FC: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80800A00: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x80800A04: bnel        $at, $zero, L_80800A14
    if (ctx->r1 != 0) {
        // 0x80800A08: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800A14;
    }
    goto skip_0;
    // 0x80800A08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800A0C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80800A10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A14:
    // 0x80800A14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A1C: jr          $ra
    // 0x80800A20: nop

    return;
    // 0x80800A20: nop

;}
RECOMP_FUNC void bstaxi_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EAC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800EB0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(392, 0X21A8) << 16);
    // 0x80800EB4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800EB8: jr          $ra
    // 0x80800EBC: lw          $v0, 0x21A8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(392, 0X21A8));
    return;
    // 0x80800EBC: lw          $v0, 0x21A8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(392, 0X21A8));
;}
RECOMP_FUNC void _idlight_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088D10: syscall     735
    recomp_syscall_handler(rdram, ctx, 0x80088D10);
    return;
    // 0x80088D14: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800CAEA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAEA4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800CAEA8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800CAEAC: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x800CAEB0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800CAEB4: lwc1        $f8, 0x48($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800CAEB8: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800CAEBC: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800CAEC0: lwc1        $f18, 0x4C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800CAEC4: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800CAEC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CAECC: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800CAED0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CAED4: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800CAED8: lwc1        $f10, 0x50($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800CAEDC: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800CAEE0: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800CAEE4: c.le.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl <= ctx->f4.fl;
    // 0x800CAEE8: nop

    // 0x800CAEEC: bc1f        L_800CAEF8
    if (!c1cs) {
        // 0x800CAEF0: nop
    
            goto L_800CAEF8;
    }
    // 0x800CAEF0: nop

    // 0x800CAEF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800CAEF8:
    // 0x800CAEF8: jr          $ra
    // 0x800CAEFC: nop

    return;
    // 0x800CAEFC: nop

;}
RECOMP_FUNC void func_8080143C_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080143C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801440: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801444: jal         0x80801158
    // 0x80801448: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80801158_bsbansack(rdram, ctx);
        goto after_0;
    // 0x80801448: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080144C: jal         0x800845D0
    // 0x80801450: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _babounce_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80801450: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801454: jal         0x80800238
    // 0x80801458: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800238_bsbansack(rdram, ctx);
        goto after_2;
    // 0x80801458: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080145C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801464: jr          $ra
    // 0x80801468: nop

    return;
    // 0x80801468: nop

;}
RECOMP_FUNC void _bcmp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800375D0: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x800375D4: bne         $at, $zero, L_800376B4
    if (ctx->r1 != 0) {
        // 0x800375D8: xor         $v0, $a0, $a1
        ctx->r2 = ctx->r4 ^ ctx->r5;
            goto L_800376B4;
    }
    // 0x800375D8: xor         $v0, $a0, $a1
    ctx->r2 = ctx->r4 ^ ctx->r5;
    // 0x800375DC: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x800375E0: bne         $v0, $zero, L_80037648
    if (ctx->r2 != 0) {
        // 0x800375E4: negu        $t8, $a0
        ctx->r24 = SUB32(0, ctx->r4);
            goto L_80037648;
    }
    // 0x800375E4: negu        $t8, $a0
    ctx->r24 = SUB32(0, ctx->r4);
    // 0x800375E8: andi        $t8, $t8, 0x3
    ctx->r24 = ctx->r24 & 0X3;
    // 0x800375EC: beq         $t8, $zero, L_8003760C
    if (ctx->r24 == 0) {
        // 0x800375F0: subu        $a2, $a2, $t8
        ctx->r6 = SUB32(ctx->r6, ctx->r24);
            goto L_8003760C;
    }
    // 0x800375F0: subu        $a2, $a2, $t8
    ctx->r6 = SUB32(ctx->r6, ctx->r24);
    // 0x800375F4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800375F8: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
    // 0x800375FC: lwl         $v1, 0x0($a1)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r5, 0X0);
    // 0x80037600: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80037604: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x80037608: bne         $v0, $v1, L_800376E4
    if (ctx->r2 != ctx->r3) {
        // 0x8003760C: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800376E4;
    }
L_8003760C:
    // 0x8003760C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80037610: and         $a3, $a2, $at
    ctx->r7 = ctx->r6 & ctx->r1;
    // 0x80037614: beq         $a3, $zero, L_800376B4
    if (ctx->r7 == 0) {
        // 0x80037618: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_800376B4;
    }
    // 0x80037618: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x8003761C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x80037620: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80037624:
    // 0x80037624: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80037628: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8003762C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80037630: bne         $v0, $v1, L_800376E4
    if (ctx->r2 != ctx->r3) {
        // 0x80037634: nop
    
            goto L_800376E4;
    }
    // 0x80037634: nop

    // 0x80037638: bnel        $a0, $a3, L_80037624
    if (ctx->r4 != ctx->r7) {
        // 0x8003763C: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_80037624;
    }
    goto skip_0;
    // 0x8003763C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x80037640: b           L_800376B4
    // 0x80037644: nop

        goto L_800376B4;
    // 0x80037644: nop

L_80037648:
    // 0x80037648: negu        $a3, $a1
    ctx->r7 = SUB32(0, ctx->r5);
    // 0x8003764C: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x80037650: beq         $a3, $zero, L_8003767C
    if (ctx->r7 == 0) {
        // 0x80037654: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_8003767C;
    }
    // 0x80037654: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x80037658: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x8003765C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_80037660:
    // 0x80037660: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x80037664: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80037668: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8003766C: bne         $v0, $v1, L_800376E4
    if (ctx->r2 != ctx->r3) {
        // 0x80037670: nop
    
            goto L_800376E4;
    }
    // 0x80037670: nop

    // 0x80037674: bnel        $a0, $a3, L_80037660
    if (ctx->r4 != ctx->r7) {
        // 0x80037678: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_80037660;
    }
    goto skip_1;
    // 0x80037678: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_1:
L_8003767C:
    // 0x8003767C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80037680: and         $a3, $a2, $at
    ctx->r7 = ctx->r6 & ctx->r1;
    // 0x80037684: beq         $a3, $zero, L_800376B4
    if (ctx->r7 == 0) {
        // 0x80037688: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_800376B4;
    }
    // 0x80037688: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x8003768C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x80037690: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
L_80037694:
    // 0x80037694: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80037698: lwr         $v0, 0x3($a0)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r4, 0X3);
    // 0x8003769C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800376A0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800376A4: bne         $v0, $v1, L_800376E4
    if (ctx->r2 != ctx->r3) {
        // 0x800376A8: nop
    
            goto L_800376E4;
    }
    // 0x800376A8: nop

    // 0x800376AC: bnel        $a0, $a3, L_80037694
    if (ctx->r4 != ctx->r7) {
        // 0x800376B0: lwl         $v0, 0x0($a0)
        ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
            goto L_80037694;
    }
    goto skip_2;
    // 0x800376B0: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
    skip_2:
L_800376B4:
    // 0x800376B4: blez        $a2, L_800376DC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800376B8: addu        $a3, $a2, $a0
        ctx->r7 = ADD32(ctx->r6, ctx->r4);
            goto L_800376DC;
    }
    // 0x800376B8: addu        $a3, $a2, $a0
    ctx->r7 = ADD32(ctx->r6, ctx->r4);
    // 0x800376BC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_800376C0:
    // 0x800376C0: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800376C4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800376C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800376CC: bne         $v0, $v1, L_800376E4
    if (ctx->r2 != ctx->r3) {
        // 0x800376D0: nop
    
            goto L_800376E4;
    }
    // 0x800376D0: nop

    // 0x800376D4: bnel        $a0, $a3, L_800376C0
    if (ctx->r4 != ctx->r7) {
        // 0x800376D8: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_800376C0;
    }
    goto skip_3;
    // 0x800376D8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_3:
L_800376DC:
    // 0x800376DC: jr          $ra
    // 0x800376E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800376E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800376E4:
    // 0x800376E4: jr          $ra
    // 0x800376E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800376E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void _bsclimb_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082ED0: syscall     34
    recomp_syscall_handler(rdram, ctx, 0x80082ED0);
    return;
    // 0x80082ED4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800630_gcboundDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800630: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800638: lw          $a0, 0xE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE0);
    // 0x8080063C: jal         0x800B42A0
    // 0x80800640: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    func_800B42A0(rdram, ctx);
        goto after_0;
    // 0x80800640: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_0:
    // 0x80800644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800648: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080064C: jr          $ra
    // 0x80800650: nop

    return;
    // 0x80800650: nop

;}
RECOMP_FUNC void func_800FC934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC934: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FC938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FC93C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800FC940: jal         0x800FB5F8
    // 0x800FC944: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800FB5F8(rdram, ctx);
        goto after_0;
    // 0x800FC944: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800FC948: beq         $v0, $zero, L_800FC96C
    if (ctx->r2 == 0) {
        // 0x800FC94C: lwc1        $f4, 0x1C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_800FC96C;
    }
    // 0x800FC94C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800FC950: lbu         $t6, 0x30($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X30);
    // 0x800FC954: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x800FC958: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800FC95C: andi        $t7, $t6, 0xFFF0
    ctx->r15 = ctx->r14 & 0XFFF0;
    // 0x800FC960: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x800FC964: sb          $t8, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r24;
    // 0x800FC968: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
L_800FC96C:
    // 0x800FC96C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FC970: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FC974: jr          $ra
    // 0x800FC978: nop

    return;
    // 0x800FC978: nop

;}
RECOMP_FUNC void _chvolcanobits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800863F8: syscall     322
    recomp_syscall_handler(rdram, ctx, 0x800863F8);
    return;
    // 0x800863FC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808004B8_chcoderoombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808004C4: jal         0x80100094
    // 0x808004C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808004C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808004CC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808004D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808004D4: jal         0x80100094
    // 0x808004D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808004D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808004DC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1172, 0X11F4) << 16);
    // 0x808004E0: addiu       $a0, $a1, 0x11F4
    ctx->r4 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1172, 0X11F4));
    // 0x808004E4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x808004E8: addiu       $v1, $v0, 0x154
    ctx->r3 = ADD32(ctx->r2, 0X154);
    // 0x808004EC: beql        $t6, $zero, L_80800510
    if (ctx->r14 == 0) {
        // 0x808004F0: lw          $t8, 0x1C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X1C);
            goto L_80800510;
    }
    goto skip_0;
    // 0x808004F0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808004F4: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_808004F8:
    // 0x808004F8: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x808004FC: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x80800500: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80800504: bnel        $t7, $zero, L_808004F8
    if (ctx->r15 != 0) {
        // 0x80800508: sh          $zero, 0x0($v1)
        MEM_H(0X0, ctx->r3) = 0;
            goto L_808004F8;
    }
    goto skip_1;
    // 0x80800508: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    skip_1:
    // 0x8080050C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
L_80800510:
    // 0x80800510: sb          $zero, 0x19($t8)
    MEM_B(0X19, ctx->r24) = 0;
    // 0x80800514: jal         0x80800E28
    // 0x80800518: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800E28_chcoderoombits(rdram, ctx);
        goto after_2;
    // 0x80800518: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8080051C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800520: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800524: jr          $ra
    // 0x80800528: nop

    return;
    // 0x80800528: nop

;}
RECOMP_FUNC void _chfactorysparkroom_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087658: syscall     601
    recomp_syscall_handler(rdram, ctx, 0x80087658);
    return;
    // 0x8008765C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bashake_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084FC8: syscall     147
    recomp_syscall_handler(rdram, ctx, 0x80084FC8);
    return;
    // 0x80084FCC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808001FC_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800200: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800204: jal         0x80089D00
    // 0x80800208: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddiefade_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800208: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080020C: jal         0x80800EE0
    // 0x80800210: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800EE0_chstonepillar(rdram, ctx);
        goto after_1;
    // 0x80800210: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800218: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080021C: jr          $ra
    // 0x80800220: nop

    return;
    // 0x80800220: nop

;}
RECOMP_FUNC void inflate_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C3FC: sw          $ra, 0xA6C($sp)
    MEM_W(0XA6C, ctx->r29) = ctx->r31;
    // 0x8001C400: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8001C404: addiu       $gp, $zero, 0x0
    ctx->r28 = ADD32(0, 0X0);
    // 0x8001C408: addiu       $fp, $zero, 0x0
    ctx->r30 = ADD32(0, 0X0);
L_8001C40C:
    // 0x8001C40C: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8001C410: jal         0x8001C45C
    // 0x8001C414: addiu       $a0, $sp, 0xA70
    ctx->r4 = ADD32(ctx->r29, 0XA70);
    inflate_block_recomp(rdram, ctx);
        goto after_0;
    // 0x8001C414: addiu       $a0, $sp, 0xA70
    ctx->r4 = ADD32(ctx->r29, 0XA70);
    after_0:
    // 0x8001C418: bne         $v0, $zero, L_8001C450
    if (ctx->r2 != 0) {
        // 0x8001C41C: lw          $t3, 0xA70($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XA70);
            goto L_8001C450;
    }
    // 0x8001C41C: lw          $t3, 0xA70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA70);
    // 0x8001C420: beq         $t3, $zero, L_8001C40C
    if (ctx->r11 == 0) {
        // 0x8001C424: slti        $at, $fp, 0x8
        ctx->r1 = SIGNED(ctx->r30) < 0X8 ? 1 : 0;
            goto L_8001C40C;
    }
    // 0x8001C424: slti        $at, $fp, 0x8
    ctx->r1 = SIGNED(ctx->r30) < 0X8 ? 1 : 0;
    // 0x8001C428: bne         $at, $zero, L_8001C440
    if (ctx->r1 != 0) {
        // 0x8001C42C: nop
    
            goto L_8001C440;
    }
    // 0x8001C42C: nop

L_8001C430:
    // 0x8001C430: addiu       $fp, $fp, -0x8
    ctx->r30 = ADD32(ctx->r30, -0X8);
    // 0x8001C434: slti        $at, $fp, 0x8
    ctx->r1 = SIGNED(ctx->r30) < 0X8 ? 1 : 0;
    // 0x8001C438: beq         $at, $zero, L_8001C430
    if (ctx->r1 == 0) {
        // 0x8001C43C: addiu       $s7, $s7, -0x1
        ctx->r23 = ADD32(ctx->r23, -0X1);
            goto L_8001C430;
    }
    // 0x8001C43C: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
L_8001C440:
    // 0x8001C440: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
    // 0x8001C444: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x8001C448: addiu       $t3, $t3, -0x2EA8
    ctx->r11 = ADD32(ctx->r11, -0X2EA8);
    // 0x8001C44C: sw          $s7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r23;
L_8001C450:
    // 0x8001C450: lw          $ra, 0xA6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA6C);
    // 0x8001C454: jr          $ra
    // 0x8001C458: nop

    return;
    // 0x8001C458: nop

;}
RECOMP_FUNC void _sukickball_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089AA8: syscall     802
    recomp_syscall_handler(rdram, ctx, 0x80089AA8);
    return;
    // 0x80089AAC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chhellterskeltermouth_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085E58: syscall     249
    recomp_syscall_handler(rdram, ctx, 0x80085E58);
    return;
    // 0x80085E5C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8008D3B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D3B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D3B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D3B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008D3BC: jal         0x80095738
    // 0x8008D3C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    baflag_isTrue(rdram, ctx);
        goto after_0;
    // 0x8008D3C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8008D3C4: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D3C8: beq         $t6, $zero, L_8008D3FC
    if (ctx->r14 == 0) {
        // 0x8008D3CC: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008D3FC;
    }
    // 0x8008D3CC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008D3D0: jal         0x800C6E38
    // 0x8008D3D4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_800C6E38(rdram, ctx);
        goto after_1;
    // 0x8008D3D4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_1:
    // 0x8008D3D8: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D3DC: beq         $t7, $zero, L_8008D3FC
    if (ctx->r15 == 0) {
        // 0x8008D3E0: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_8008D3FC;
    }
    // 0x8008D3E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8008D3E4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8008D3E8: addiu       $a1, $zero, 0x401
    ctx->r5 = ADD32(0, 0X401);
    // 0x8008D3EC: jal         0x800F64A4
    // 0x8008D3F0: lw          $a0, 0x184($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X184);
    func_800F64A4(rdram, ctx);
        goto after_2;
    // 0x8008D3F0: lw          $a0, 0x184($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X184);
    after_2:
    // 0x8008D3F4: sltu        $t9, $zero, $v0
    ctx->r25 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D3F8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8008D3FC:
    // 0x8008D3FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D400: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D404: jr          $ra
    // 0x8008D408: nop

    return;
    // 0x8008D408: nop

;}
RECOMP_FUNC void _babuzz_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084798: syscall     120
    recomp_syscall_handler(rdram, ctx, 0x80084798);
    return;
    // 0x8008479C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800D87D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D87D4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800D87D8: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800D87DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D87E0: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800D87E4: jr          $ra
    // 0x800D87E8: sw          $t6, -0x4090($at)
    MEM_W(-0X4090, ctx->r1) = ctx->r14;
    return;
    // 0x800D87E8: sw          $t6, -0x4090($at)
    MEM_W(-0X4090, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void _sucoaster_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A128: syscall     829
    recomp_syscall_handler(rdram, ctx, 0x8008A128);
    return;
    // 0x8008A12C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800110_bsdroneslide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800110: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800118: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080011C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800120: jal         0x800963C0
    // 0x80800124: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800963C0(rdram, ctx);
        goto after_0;
    // 0x80800124: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80800128: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8080012C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800130: jal         0x800F1988
    // 0x80800134: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_800F1988(rdram, ctx);
        goto after_1;
    // 0x80800134: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80800138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080013C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800140: jr          $ra
    // 0x80800144: nop

    return;
    // 0x80800144: nop

;}
RECOMP_FUNC void func_80801A7C_chpotogoldgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801A80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A84: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801A88: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801A8C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80801A90: jal         0x800DA298
    // 0x80801A94: addiu       $a0, $zero, 0x9F6
    ctx->r4 = ADD32(0, 0X9F6);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80801A94: addiu       $a0, $zero, 0x9F6
    ctx->r4 = ADD32(0, 0X9F6);
    after_0:
    // 0x80801A98: bnel        $v0, $zero, L_80801AB4
    if (ctx->r2 != 0) {
        // 0x80801A9C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80801AB4;
    }
    goto skip_0;
    // 0x80801A9C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x80801AA0: jal         0x800DA298
    // 0x80801AA4: addiu       $a0, $zero, 0x1DB
    ctx->r4 = ADD32(0, 0X1DB);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80801AA4: addiu       $a0, $zero, 0x1DB
    ctx->r4 = ADD32(0, 0X1DB);
    after_1:
    // 0x80801AA8: beq         $v0, $zero, L_80801AC8
    if (ctx->r2 == 0) {
        // 0x80801AAC: nop
    
            goto L_80801AC8;
    }
    // 0x80801AAC: nop

    // 0x80801AB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80801AB4:
    // 0x80801AB4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80801AB8: jal         0x800D91EC
    // 0x80801ABC: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800D91EC(rdram, ctx);
        goto after_2;
    // 0x80801ABC: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_2:
    // 0x80801AC0: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x80801AC4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80801AC8:
    // 0x80801AC8: jal         0x800DA298
    // 0x80801ACC: addiu       $a0, $zero, 0x9F7
    ctx->r4 = ADD32(0, 0X9F7);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80801ACC: addiu       $a0, $zero, 0x9F7
    ctx->r4 = ADD32(0, 0X9F7);
    after_3:
    // 0x80801AD0: bnel        $v0, $zero, L_80801AEC
    if (ctx->r2 != 0) {
        // 0x80801AD4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80801AEC;
    }
    goto skip_1;
    // 0x80801AD4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x80801AD8: jal         0x800DA298
    // 0x80801ADC: addiu       $a0, $zero, 0x1DB
    ctx->r4 = ADD32(0, 0X1DB);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80801ADC: addiu       $a0, $zero, 0x1DB
    ctx->r4 = ADD32(0, 0X1DB);
    after_4:
    // 0x80801AE0: beq         $v0, $zero, L_80801B04
    if (ctx->r2 == 0) {
        // 0x80801AE4: nop
    
            goto L_80801B04;
    }
    // 0x80801AE4: nop

    // 0x80801AE8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80801AEC:
    // 0x80801AEC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80801AF0: jal         0x800D91EC
    // 0x80801AF4: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    func_800D91EC(rdram, ctx);
        goto after_5;
    // 0x80801AF4: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    after_5:
    // 0x80801AF8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80801AFC: and         $t9, $t8, $v0
    ctx->r25 = ctx->r24 & ctx->r2;
    // 0x80801B00: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_80801B04:
    // 0x80801B04: jal         0x800DA298
    // 0x80801B08: addiu       $a0, $zero, 0x9F8
    ctx->r4 = ADD32(0, 0X9F8);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80801B08: addiu       $a0, $zero, 0x9F8
    ctx->r4 = ADD32(0, 0X9F8);
    after_6:
    // 0x80801B0C: bnel        $v0, $zero, L_80801B28
    if (ctx->r2 != 0) {
        // 0x80801B10: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80801B28;
    }
    goto skip_2;
    // 0x80801B10: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_2:
    // 0x80801B14: jal         0x800DA298
    // 0x80801B18: addiu       $a0, $zero, 0x1DB
    ctx->r4 = ADD32(0, 0X1DB);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80801B18: addiu       $a0, $zero, 0x1DB
    ctx->r4 = ADD32(0, 0X1DB);
    after_7:
    // 0x80801B1C: beq         $v0, $zero, L_80801B40
    if (ctx->r2 == 0) {
        // 0x80801B20: nop
    
            goto L_80801B40;
    }
    // 0x80801B20: nop

    // 0x80801B24: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80801B28:
    // 0x80801B28: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80801B2C: jal         0x800D91EC
    // 0x80801B30: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800D91EC(rdram, ctx);
        goto after_8;
    // 0x80801B30: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_8:
    // 0x80801B34: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80801B38: and         $t1, $t0, $v0
    ctx->r9 = ctx->r8 & ctx->r2;
    // 0x80801B3C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_80801B40:
    // 0x80801B40: jal         0x800DA298
    // 0x80801B44: addiu       $a0, $zero, 0x9F9
    ctx->r4 = ADD32(0, 0X9F9);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x80801B44: addiu       $a0, $zero, 0x9F9
    ctx->r4 = ADD32(0, 0X9F9);
    after_9:
    // 0x80801B48: bnel        $v0, $zero, L_80801B64
    if (ctx->r2 != 0) {
        // 0x80801B4C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80801B64;
    }
    goto skip_3;
    // 0x80801B4C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_3:
    // 0x80801B50: jal         0x800DA298
    // 0x80801B54: addiu       $a0, $zero, 0x1DB
    ctx->r4 = ADD32(0, 0X1DB);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x80801B54: addiu       $a0, $zero, 0x1DB
    ctx->r4 = ADD32(0, 0X1DB);
    after_10:
    // 0x80801B58: beq         $v0, $zero, L_80801B7C
    if (ctx->r2 == 0) {
        // 0x80801B5C: nop
    
            goto L_80801B7C;
    }
    // 0x80801B5C: nop

    // 0x80801B60: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80801B64:
    // 0x80801B64: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80801B68: jal         0x800D91EC
    // 0x80801B6C: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    func_800D91EC(rdram, ctx);
        goto after_11;
    // 0x80801B6C: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_11:
    // 0x80801B70: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80801B74: and         $t3, $t2, $v0
    ctx->r11 = ctx->r10 & ctx->r2;
    // 0x80801B78: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
L_80801B7C:
    // 0x80801B7C: jal         0x800DA298
    // 0x80801B80: addiu       $a0, $zero, 0x9F6
    ctx->r4 = ADD32(0, 0X9F6);
    func_800DA298(rdram, ctx);
        goto after_12;
    // 0x80801B80: addiu       $a0, $zero, 0x9F6
    ctx->r4 = ADD32(0, 0X9F6);
    after_12:
    // 0x80801B84: beq         $v0, $zero, L_80801BD4
    if (ctx->r2 == 0) {
        // 0x80801B88: nop
    
            goto L_80801BD4;
    }
    // 0x80801B88: nop

    // 0x80801B8C: jal         0x800DA298
    // 0x80801B90: addiu       $a0, $zero, 0x9F7
    ctx->r4 = ADD32(0, 0X9F7);
    func_800DA298(rdram, ctx);
        goto after_13;
    // 0x80801B90: addiu       $a0, $zero, 0x9F7
    ctx->r4 = ADD32(0, 0X9F7);
    after_13:
    // 0x80801B94: beq         $v0, $zero, L_80801BD4
    if (ctx->r2 == 0) {
        // 0x80801B98: nop
    
            goto L_80801BD4;
    }
    // 0x80801B98: nop

    // 0x80801B9C: jal         0x800DA298
    // 0x80801BA0: addiu       $a0, $zero, 0x9F8
    ctx->r4 = ADD32(0, 0X9F8);
    func_800DA298(rdram, ctx);
        goto after_14;
    // 0x80801BA0: addiu       $a0, $zero, 0x9F8
    ctx->r4 = ADD32(0, 0X9F8);
    after_14:
    // 0x80801BA4: beq         $v0, $zero, L_80801BD4
    if (ctx->r2 == 0) {
        // 0x80801BA8: nop
    
            goto L_80801BD4;
    }
    // 0x80801BA8: nop

    // 0x80801BAC: jal         0x800DA298
    // 0x80801BB0: addiu       $a0, $zero, 0x9F9
    ctx->r4 = ADD32(0, 0X9F9);
    func_800DA298(rdram, ctx);
        goto after_15;
    // 0x80801BB0: addiu       $a0, $zero, 0x9F9
    ctx->r4 = ADD32(0, 0X9F9);
    after_15:
    // 0x80801BB4: beq         $v0, $zero, L_80801BD4
    if (ctx->r2 == 0) {
        // 0x80801BB8: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80801BD4;
    }
    // 0x80801BB8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801BBC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    // 0x80801BC0: jal         0x800D91EC
    // 0x80801BC4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_800D91EC(rdram, ctx);
        goto after_16;
    // 0x80801BC4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_16:
    // 0x80801BC8: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80801BCC: and         $t5, $t4, $v0
    ctx->r13 = ctx->r12 & ctx->r2;
    // 0x80801BD0: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_80801BD4:
    // 0x80801BD4: jal         0x800BEA88
    // 0x80801BD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_17;
    // 0x80801BD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x80801BDC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80801BE0: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80801BE4: addiu       $a2, $a2, 0x75C0
    ctx->r6 = ADD32(ctx->r6, 0X75C0);
    // 0x80801BE8: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    // 0x80801BEC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80801BF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801BF4: jal         0x80088660
    // 0x80801BF8: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    _glid_entrypoint_0(rdram, ctx);
        goto after_18;
    // 0x80801BF8: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_18:
    // 0x80801BFC: jal         0x800BEA88
    // 0x80801C00: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_19;
    // 0x80801C00: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_19:
    // 0x80801C04: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80801C08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801C0C: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x80801C10: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80801C14: jal         0x80088660
    // 0x80801C18: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_20;
    // 0x80801C18: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    after_20:
    // 0x80801C1C: jal         0x800BEA88
    // 0x80801C20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_21;
    // 0x80801C20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_21:
    // 0x80801C24: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80801C28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801C2C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x80801C30: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80801C34: jal         0x80088660
    // 0x80801C38: lw          $a3, 0x0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_22;
    // 0x80801C38: lw          $a3, 0x0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X0);
    after_22:
    // 0x80801C3C: jal         0x800BEA88
    // 0x80801C40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_23;
    // 0x80801C40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_23:
    // 0x80801C44: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80801C48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801C4C: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x80801C50: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80801C54: jal         0x80088660
    // 0x80801C58: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_24;
    // 0x80801C58: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    after_24:
    // 0x80801C5C: jal         0x800BEA88
    // 0x80801C60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_25;
    // 0x80801C60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_25:
    // 0x80801C64: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80801C68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801C6C: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x80801C70: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80801C74: jal         0x80088660
    // 0x80801C78: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_26;
    // 0x80801C78: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    after_26:
    // 0x80801C7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801C80: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80801C84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801C88: jr          $ra
    // 0x80801C8C: nop

    return;
    // 0x80801C8C: nop

;}
RECOMP_FUNC void func_800E88AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E88AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E88B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E88B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E88B8: jal         0x800A89F8
    // 0x800E88BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800A89F8(rdram, ctx);
        goto after_0;
    // 0x800E88BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800E88C0: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    // 0x800E88C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800E88C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E88CC: jal         0x800E8918
    // 0x800E88D0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    func_800E8918(rdram, ctx);
        goto after_1;
    // 0x800E88D0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800E88D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E88D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E88DC: jr          $ra
    // 0x800E88E0: nop

    return;
    // 0x800E88E0: nop

;}
RECOMP_FUNC void func_80800540_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800540: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800544: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800548: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080054C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800550: sb          $zero, 0x15E($a0)
    MEM_B(0X15E, ctx->r4) = 0;
    // 0x80800554: addiu       $a1, $zero, 0x143
    ctx->r5 = ADD32(0, 0X143);
    // 0x80800558: jal         0x8008CCBC
    // 0x8080055C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_0;
    // 0x8080055C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_0:
    // 0x80800560: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800564: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080056C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800570: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800574: jal         0x8009FFD8
    // 0x80800578: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800578: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800580: jal         0x8009B9B0
    // 0x80800584: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800584: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080058C: addiu       $a1, $zero, 0x583
    ctx->r5 = ADD32(0, 0X583);
    // 0x80800590: jal         0x8009DE38
    // 0x80800594: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_3;
    // 0x80800594: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_3:
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080059C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808005A0: jal         0x80098140
    // 0x808005A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bainput_enable(rdram, ctx);
        goto after_4;
    // 0x808005A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x808005A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808005B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005B4: jr          $ra
    // 0x808005B8: nop

    return;
    // 0x808005B8: nop

;}
RECOMP_FUNC void func_800FF564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FF564: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800FF568: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FF56C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FF570: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FF574: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    // 0x800FF578: jal         0x80101238
    // 0x800FF57C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80101238(rdram, ctx);
        goto after_0;
    // 0x800FF57C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800FF580: addiu       $s1, $sp, 0x2C
    ctx->r17 = ADD32(ctx->r29, 0X2C);
    // 0x800FF584: jal         0x801067C4
    // 0x800FF588: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_801067C4(rdram, ctx);
        goto after_1;
    // 0x800FF588: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x800FF58C: beq         $v0, $zero, L_800FF5CC
    if (ctx->r2 == 0) {
        // 0x800FF590: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800FF5CC;
    }
    // 0x800FF590: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800FF594:
    // 0x800FF594: jal         0x800FF3EC
    // 0x800FF598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FF3EC(rdram, ctx);
        goto after_2;
    // 0x800FF598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800FF59C: jal         0x800FF4A4
    // 0x800FF5A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FF4A4(rdram, ctx);
        goto after_3;
    // 0x800FF5A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800FF5A4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800FF5A8: beql        $a0, $zero, L_800FF5BC
    if (ctx->r4 == 0) {
        // 0x800FF5AC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800FF5BC;
    }
    goto skip_0;
    // 0x800FF5AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x800FF5B0: jal         0x800EBFF4
    // 0x800FF5B4: nop

    func_800EBFF4(rdram, ctx);
        goto after_4;
    // 0x800FF5B4: nop

    after_4:
    // 0x800FF5B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800FF5BC:
    // 0x800FF5BC: jal         0x8010682C
    // 0x800FF5C0: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    func_8010682C(rdram, ctx);
        goto after_5;
    // 0x800FF5C0: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    after_5:
    // 0x800FF5C4: bne         $v0, $zero, L_800FF594
    if (ctx->r2 != 0) {
        // 0x800FF5C8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800FF594;
    }
    // 0x800FF5C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800FF5CC:
    // 0x800FF5CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FF5D0: sw          $zero, 0x5A50($at)
    MEM_W(0X5A50, ctx->r1) = 0;
    // 0x800FF5D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800FF5D8: jal         0x801041A0
    // 0x800FF5DC: sw          $zero, 0x7194($at)
    MEM_W(0X7194, ctx->r1) = 0;
    func_801041A0(rdram, ctx);
        goto after_6;
    // 0x800FF5DC: sw          $zero, 0x7194($at)
    MEM_W(0X7194, ctx->r1) = 0;
    after_6:
    // 0x800FF5E0: jal         0x80104378
    // 0x800FF5E4: nop

    func_80104378(rdram, ctx);
        goto after_7;
    // 0x800FF5E4: nop

    after_7:
    // 0x800FF5E8: jal         0x80105438
    // 0x800FF5EC: nop

    func_80105438(rdram, ctx);
        goto after_8;
    // 0x800FF5EC: nop

    after_8:
    // 0x800FF5F0: jal         0x80105C48
    // 0x800FF5F4: nop

    func_80105C48(rdram, ctx);
        goto after_9;
    // 0x800FF5F4: nop

    after_9:
    // 0x800FF5F8: jal         0x80106608
    // 0x800FF5FC: nop

    func_80106608(rdram, ctx);
        goto after_10;
    // 0x800FF5FC: nop

    after_10:
    // 0x800FF600: jal         0x80106A28
    // 0x800FF604: nop

    func_80106A28(rdram, ctx);
        goto after_11;
    // 0x800FF604: nop

    after_11:
    // 0x800FF608: jal         0x80106E18
    // 0x800FF60C: nop

    func_80106E18(rdram, ctx);
        goto after_12;
    // 0x800FF60C: nop

    after_12:
    // 0x800FF610: jal         0x8010DF98
    // 0x800FF614: nop

    func_8010DF98(rdram, ctx);
        goto after_13;
    // 0x800FF614: nop

    after_13:
    // 0x800FF618: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FF61C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FF620: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FF624: jr          $ra
    // 0x800FF628: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800FF628: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void baswim_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808002B4: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x808002B8: jr          $ra
    // 0x808002BC: swc1        $f12, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x808002BC: swc1        $f12, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_808000B8_chpodiumbankaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C0: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808000C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000C8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808000CC: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808000D0: beq         $t6, $at, L_808000F4
    if (ctx->r14 == ctx->r1) {
        // 0x808000D4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000F4;
    }
    // 0x808000D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000D8: beq         $t6, $at, L_80800104
    if (ctx->r14 == ctx->r1) {
        // 0x808000DC: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80800104;
    }
    // 0x808000DC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808000E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000E4: beql        $t6, $at, L_80800118
    if (ctx->r14 == ctx->r1) {
        // 0x808000E8: lbu         $a0, 0x79($a2)
        ctx->r4 = MEM_BU(ctx->r6, 0X79);
            goto L_80800118;
    }
    goto skip_0;
    // 0x808000E8: lbu         $a0, 0x79($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X79);
    skip_0:
    // 0x808000EC: b           L_80800164
    // 0x808000F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800164;
    // 0x808000F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000F4:
    // 0x808000F4: jal         0x80800044
    // 0x808000F8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80800044_chpodiumbankaz(rdram, ctx);
        goto after_0;
    // 0x808000F8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x808000FC: b           L_80800164
    // 0x80800100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800164;
    // 0x80800100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800104:
    // 0x80800104: jal         0x80101FDC
    // 0x80800108: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800108: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x8080010C: b           L_80800164
    // 0x80800110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800164;
    // 0x80800110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800114: lbu         $a0, 0x79($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X79);
L_80800118:
    // 0x80800118: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8080011C: srl         $t7, $a0, 4
    ctx->r15 = S32(U32(ctx->r4) >> 4);
    // 0x80800120: jal         0x800F6BE4
    // 0x80800124: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800F6BE4(rdram, ctx);
        goto after_2;
    // 0x80800124: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_2:
    // 0x80800128: beq         $v0, $zero, L_80800154
    if (ctx->r2 == 0) {
        // 0x8080012C: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80800154;
    }
    // 0x8080012C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800130: lbu         $a0, 0x79($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X79);
    // 0x80800134: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80800138: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080013C: srl         $t8, $a0, 4
    ctx->r24 = S32(U32(ctx->r4) >> 4);
    // 0x80800140: jal         0x800F7B9C
    // 0x80800144: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800F7B9C(rdram, ctx);
        goto after_3;
    // 0x80800144: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_3:
    // 0x80800148: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080014C: bne         $v0, $at, L_80800160
    if (ctx->r2 != ctx->r1) {
        // 0x80800150: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80800160;
    }
    // 0x80800150: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_80800154:
    // 0x80800154: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800158: jal         0x80101FDC
    // 0x8080015C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x8080015C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
L_80800160:
    // 0x80800160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800164:
    // 0x80800164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800168: jr          $ra
    // 0x8080016C: nop

    return;
    // 0x8080016C: nop

;}
RECOMP_FUNC void babounce_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_800FB434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB434: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800FB438: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800FB43C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800FB440: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800FB444: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FB448: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800FB44C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800FB450: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800FB454: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800FB458: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800FB45C: lw          $a3, 0x8($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X8);
    // 0x800FB460: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800FB464: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x800FB468: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800FB46C: jal         0x800EFA4C
    // 0x800FB470: nop

    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x800FB470: nop

    after_0:
    // 0x800FB474: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x800FB478: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800FB47C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800FB480: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800FB484: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800FB488: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x800FB48C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800FB490: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800FB494: jal         0x800EFA4C
    // 0x800FB498: nop

    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x800FB498: nop

    after_1:
    // 0x800FB49C: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800FB4A0: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800FB4A4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800FB4A8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800FB4AC: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x800FB4B0: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x800FB4B4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800FB4B8: jal         0x800C6B78
    // 0x800FB4BC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    func_800C6B78(rdram, ctx);
        goto after_2;
    // 0x800FB4BC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_2:
    // 0x800FB4C0: beq         $v0, $zero, L_800FB4F4
    if (ctx->r2 == 0) {
        // 0x800FB4C4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800FB4F4;
    }
    // 0x800FB4C4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800FB4C8: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800FB4CC: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800FB4D0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800FB4D4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800FB4D8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800FB4DC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800FB4E0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800FB4E4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800FB4E8: jal         0x800EFA4C
    // 0x800FB4EC: nop

    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x800FB4EC: nop

    after_3:
    // 0x800FB4F0: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
L_800FB4F4:
    // 0x800FB4F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FB4F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800FB4FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800FB500: jr          $ra
    // 0x800FB504: nop

    return;
    // 0x800FB504: nop

;}
RECOMP_FUNC void chskeletonexplode_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801048: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1808, 0X1138) << 16);
    // 0x8080104C: jr          $ra
    // 0x80801050: addiu       $v0, $v0, 0x1138
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1808, 0X1138));
    return;
    // 0x80801050: addiu       $v0, $v0, 0x1138
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1808, 0X1138));
    // 0x80801054: nop

    // 0x80801058: nop

    // 0x8080105C: nop

;}
RECOMP_FUNC void func_800D2E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2E90: bltz        $a0, L_800D2EAC
    if (SIGNED(ctx->r4) < 0) {
        // 0x800D2E94: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800D2EAC;
    }
    // 0x800D2E94: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D2E98: addiu       $v0, $v0, -0x4CA0
    ctx->r2 = ADD32(ctx->r2, -0X4CA0);
    // 0x800D2E9C: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800D2EA0: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800D2EA4: bnel        $at, $zero, L_800D2EB8
    if (ctx->r1 != 0) {
        // 0x800D2EA8: lw          $t7, 0x0($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X0);
            goto L_800D2EB8;
    }
    goto skip_0;
    // 0x800D2EA8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    skip_0:
L_800D2EAC:
    // 0x800D2EAC: jr          $ra
    // 0x800D2EB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800D2EB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D2EB4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
L_800D2EB8:
    // 0x800D2EB8: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x800D2EBC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D2EC0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800D2EC4: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x800D2EC8: beq         $t0, $zero, L_800D2ED8
    if (ctx->r8 == 0) {
        // 0x800D2ECC: nop
    
            goto L_800D2ED8;
    }
    // 0x800D2ECC: nop

    // 0x800D2ED0: b           L_800D2ED8
    // 0x800D2ED4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800D2ED8;
    // 0x800D2ED4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800D2ED8:
    // 0x800D2ED8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800D2EDC: jr          $ra
    // 0x800D2EE0: nop

    return;
    // 0x800D2EE0: nop

;}
RECOMP_FUNC void _badata_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084670: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x80084670);
    return;
    // 0x80084674: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800BAB1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BAB1C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800BAB20: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800BAB24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BAB28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BAB2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800BAB30: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800BAB34: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800BAB38: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800BAB3C: jal         0x800EFA4C
    // 0x800BAB40: addiu       $a0, $a0, 0x60
    ctx->r4 = ADD32(ctx->r4, 0X60);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x800BAB40: addiu       $a0, $a0, 0x60
    ctx->r4 = ADD32(ctx->r4, 0X60);
    after_0:
    // 0x800BAB44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BAB48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BAB4C: jr          $ra
    // 0x800BAB50: nop

    return;
    // 0x800BAB50: nop

;}
RECOMP_FUNC void func_8080015C_chalienbeam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080015C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800160: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800164: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800168: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080016C: jal         0x800E3A58
    // 0x80800170: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800E3A58(rdram, ctx);
        goto after_0;
    // 0x80800170: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80800174: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800178: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8080017C: swc1        $f4, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f4.u32l;
    // 0x80800180: jal         0x80101870
    // 0x80800184: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80101870(rdram, ctx);
        goto after_1;
    // 0x80800184: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080018C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800190: jr          $ra
    // 0x80800194: nop

    return;
    // 0x80800194: nop

    // 0x80800198: nop

    // 0x8080019C: nop

;}
RECOMP_FUNC void guMtxIdent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EF3C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8002EF40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002EF44: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8002EF48: jal         0x8002EEB4
    // 0x8002EF4C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x8002EF4C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x8002EF50: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8002EF54: jal         0x8002ED00
    // 0x8002EF58: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x8002EF58: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x8002EF5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002EF60: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8002EF64: jr          $ra
    // 0x8002EF68: nop

    return;
    // 0x8002EF68: nop

;}
RECOMP_FUNC void _gczoombox_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B40: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087B40);
    return;
    // 0x80087B44: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void _chburgerstand_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085D90: syscall     239
    recomp_syscall_handler(rdram, ctx, 0x80085D90);
    return;
    // 0x80085D94: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801E78_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801E78: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801E7C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801E80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801E84: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801E88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801E8C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80801E90: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80801E94: addiu       $s1, $s0, 0xC4
    ctx->r17 = ADD32(ctx->r16, 0XC4);
    // 0x80801E98: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80801E9C: subu        $a1, $t7, $a1
    ctx->r5 = SUB32(ctx->r15, ctx->r5);
    // 0x80801EA0: jal         0x80800000
    // 0x80801EA4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80800000_ncpoddialog(rdram, ctx);
        goto after_0;
    // 0x80801EA4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_0:
    // 0x80801EA8: addiu       $a2, $s0, 0x148
    ctx->r6 = ADD32(ctx->r16, 0X148);
    // 0x80801EAC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80801EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801EB4: jal         0x80800000
    // 0x80801EB8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80800000_ncpoddialog(rdram, ctx);
        goto after_1;
    // 0x80801EB8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_1:
    // 0x80801EBC: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80801EC0: lwc1        $f6, 0x14C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14C);
    // 0x80801EC4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801EC8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801ECC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80801ED0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801ED4: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
    // 0x80801ED8: lwc1        $f10, 0xC8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80801EDC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80801EE0: swc1        $f18, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f18.u32l;
    // 0x80801EE4: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80801EE8: swc1        $f4, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->f4.u32l;
    // 0x80801EEC: jal         0x800F1DF4
    // 0x80801EF0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800F1DF4(rdram, ctx);
        goto after_2;
    // 0x80801EF0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80801EF4: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80801EF8: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80801EFC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80801F00: beq         $t8, $zero, L_80801F18
    if (ctx->r24 == 0) {
        // 0x80801F04: sll         $t0, $t9, 2
        ctx->r8 = S32(ctx->r25 << 2);
            goto L_80801F18;
    }
    // 0x80801F04: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80801F08: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80801F0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801F10: b           L_80801F24
    // 0x80801F14: add.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f6.fl;
        goto L_80801F24;
    // 0x80801F14: add.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f6.fl;
L_80801F18:
    // 0x80801F18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801F1C: nop

    // 0x80801F20: sub.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f8.fl;
L_80801F24:
    // 0x80801F24: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x80801F28: addu        $t2, $s0, $t1
    ctx->r10 = ADD32(ctx->r16, ctx->r9);
    // 0x80801F2C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80801F30: lw          $a2, 0x24($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X24);
    // 0x80801F34: jal         0x800EEB9C
    // 0x80801F38: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EEB9C(rdram, ctx);
        goto after_3;
    // 0x80801F38: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x80801F3C: addiu       $s0, $sp, 0x34
    ctx->r16 = ADD32(ctx->r29, 0X34);
    // 0x80801F40: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801F44: jal         0x800EF04C
    // 0x80801F48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EF04C(rdram, ctx);
        goto after_4;
    // 0x80801F48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80801F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F50: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801F54: jal         0x800EFB24
    // 0x80801F58: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_800EFB24(rdram, ctx);
        goto after_5;
    // 0x80801F58: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x80801F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F60: jal         0x800EF334
    // 0x80801F64: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_800EF334(rdram, ctx);
        goto after_6;
    // 0x80801F64: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_6:
    // 0x80801F68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801F6C: jal         0x800EF04C
    // 0x80801F70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x80801F70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x80801F74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801F78: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801F7C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801F80: jr          $ra
    // 0x80801F84: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80801F84: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80800E30_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E38: jal         0x80800030
    // 0x80800E3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800030_bsbswim(rdram, ctx);
        goto after_0;
    // 0x80800E3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800E40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800E44: jal         0x800961AC
    // 0x80800E48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_1;
    // 0x80800E48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800E4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800E50: jal         0x800845D8
    // 0x80800E54: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _babounce_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800E54: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800E58: lui         $a2, 0x3F15
    ctx->r6 = S32(0X3F15 << 16);
    // 0x80800E5C: ori         $a2, $a2, 0x119D
    ctx->r6 = ctx->r6 | 0X119D;
    // 0x80800E60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800E64: jal         0x800845E0
    // 0x80800E68: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    _babounce_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x80800E68: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_3:
    // 0x80800E6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E74: jr          $ra
    // 0x80800E78: nop

    return;
    // 0x80800E78: nop

;}
RECOMP_FUNC void _badrone_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084828: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x80084828);
    return;
    // 0x8008482C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _chfactorylight_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086128: syscall     280
    recomp_syscall_handler(rdram, ctx, 0x80086128);
    return;
    // 0x8008612C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
